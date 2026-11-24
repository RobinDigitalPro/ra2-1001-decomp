const unsigned char table_4829e0[]{183,41,72,0,211,41,72,0,192,41,72,0,202,41,72,0,221,41,72,0,0,1,1,4,4,2,2,4,4,4,4,4,4,4,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,0};
const unsigned char table_4f472c[]{254,68,79,0,39,69,79,0,28,69,79,0,121,68,79,0,50,69,79,0,0,1,1,4,4,2,2,4,4,4,4,4,4,4,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,0,48,70,79,0,229,69,79,0,57,69,79,0,179,68,79,0,32,71,79,0,0,4,4,4,1,4,4,4,4,4,4,4,4,2,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,3};
#include "recovered/recovery_b739_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b739 {
namespace {
void f_0005e970(Memory&,State&,Frame&,const Operations&);
void f_0005e990(Memory&,State&,Frame&,const Operations&);
void f_00091af0(Memory&,State&,Frame&,const Operations&);
void f_000b9ab0(Memory&,State&,Frame&,const Operations&);
void f_002b6910(Memory&,State&,Frame&,const Operations&);
void f_000538b0(Memory&,State&,Frame&,const Operations&);
void f_00053890(Memory&,State&,Frame&,const Operations&);
void f_00010250(Memory&,State&,Frame&,const Operations&);
void f_000eaa70(Memory&,State&,Frame&,const Operations&);
void f_000829a0(Memory&,State&,Frame&,const Operations&);
void f_000e0030(Memory&,State&,Frame&,const Operations&);
void f_00157ab0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);
void f_000f4430(Memory&,State&,Frame&,const Operations&);

void f_0005e970(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0045e970: { // 0x45e970: b807000000 MOV EAX, 7
    s.ax = 7u;
  }
  L0045e975: { // 0x45e975: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0005e990(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0045e990: { // 0x45e990: 8b81900b0000 MOV EAX, dword ptr [ECX + 0xb90]
    s.ax = m.r32((s.cx+0x00000b90u));
  }
  L0045e996: { // 0x45e996: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00091af0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00491af0: { // 0x491af0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00491af1: { // 0x491af1: 8b5c2408 MOV EBX, dword ptr [ESP + 8]
    s.bx = m.r32((f.sp+8u));
  }
  L00491af5: { // 0x491af5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00491af6: { // 0x491af6: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L00491af8: { // 0x491af8: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00491af9: { // 0x491af9: 8b7e08 MOV EDI, dword ptr [ESI + 8]
    s.di = m.r32((s.si+8u));
  }
  L00491afc: { // 0x491afc: 3bdf CMP EBX, EDI
    (void)integer::sub(s.bx,s.di,32,flags);
  }
  L00491afe: { // 0x491afe: 7c2d JL 0x491b2d
    if(integer::condition("JL",flags)) goto L00491b2d;
  }
  L00491b00: { // 0x491b00: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00491b02: { // 0x491b02: 8d4b0a LEA ECX, [EBX + 0xa]
    s.cx = (s.bx+0x0000000au);
  }
  L00491b05: { // 0x491b05: 6a00 PUSH 0
    f.push(m,0u);
  }
  L00491b07: { // 0x491b07: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00491b08: { // 0x491b08: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00491b0a: { // 0x491b0a: ff5008 CALL dword ptr [EAX + 8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+8u)),4791053u); flags=s.arithmetic_flags;
  }
  L00491b0d: { // 0x491b0d: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00491b0f: { // 0x491b0f: 7428 JZ 0x491b39
    if(integer::condition("JZ",flags)) goto L00491b39;
  }
  L00491b11: { // 0x491b11: 8b4e08 MOV ECX, dword ptr [ESI + 8]
    s.cx = m.r32((s.si+8u));
  }
  L00491b14: { // 0x491b14: 8bc7 MOV EAX, EDI
    s.ax = s.di;
  }
  L00491b16: { // 0x491b16: 3bf9 CMP EDI, ECX
    (void)integer::sub(s.di,s.cx,32,flags);
  }
  L00491b18: { // 0x491b18: 7d13 JGE 0x491b2d
    if(integer::condition("JGE",flags)) goto L00491b2d;
  }
  L00491b1a: { // 0x491b1a: 8b5604 MOV EDX, dword ptr [ESI + 4]
    s.dx = m.r32((s.si+4u));
  }
  L00491b1d: { // 0x491b1d: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00491b1e: { // 0x491b1e: c74482fc00000000 MOV dword ptr [EDX + EAX*4 - 4], 0
    m.w32((s.dx+(s.ax * 4u)-4u), 0u);
  }
  L00491b26: { // 0x491b26: 8b4e08 MOV ECX, dword ptr [ESI + 8]
    s.cx = m.r32((s.si+8u));
  }
  L00491b29: { // 0x491b29: 3bc1 CMP EAX, ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00491b2b: { // 0x491b2b: 7ced JL 0x491b1a
    if(integer::condition("JL",flags)) goto L00491b1a;
  }
  L00491b2d: { // 0x491b2d: 8b4604 MOV EAX, dword ptr [ESI + 4]
    s.ax = m.r32((s.si+4u));
  }
  L00491b30: { // 0x491b30: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00491b31: { // 0x491b31: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00491b32: { // 0x491b32: 8b0498 MOV EAX, dword ptr [EAX + EBX*4]
    s.ax = m.r32((s.ax+(s.bx * 4u)));
  }
  L00491b35: { // 0x491b35: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00491b36: { // 0x491b36: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00491b39: { // 0x491b39: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00491b3a: { // 0x491b3a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00491b3b: { // 0x491b3b: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00491b3d: { // 0x491b3d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00491b3e: { // 0x491b3e: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000b9ab0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004b9ab0: { // 0x4b9ab0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004b9ab1: { // 0x4b9ab1: 8b5c2408 MOV EBX, dword ptr [ESP + 8]
    s.bx = m.r32((f.sp+8u));
  }
  L004b9ab5: { // 0x4b9ab5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004b9ab6: { // 0x4b9ab6: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L004b9ab8: { // 0x4b9ab8: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004b9ab9: { // 0x4b9ab9: 33ff XOR EDI, EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L004b9abb: { // 0x4b9abb: 8b4e54 MOV ECX, dword ptr [ESI + 0x54]
    s.cx = m.r32((s.si+0x00000054u));
  }
  L004b9abe: { // 0x4b9abe: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004b9ac0: { // 0x4b9ac0: 7411 JZ 0x4b9ad3
    if(integer::condition("JZ",flags)) goto L004b9ad3;
  }
  L004b9ac2: { // 0x4b9ac2: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L004b9ac4: { // 0x4b9ac4: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),4954826u); flags=s.arithmetic_flags;
  }
  L004b9aca: { // 0x4b9aca: 3bc3 CMP EAX, EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L004b9acc: { // 0x4b9acc: 7505 JNZ 0x4b9ad3
    if(integer::condition("JNZ",flags)) goto L004b9ad3;
  }
  L004b9ace: { // 0x4b9ace: bf01000000 MOV EDI, 1
    s.di = 1u;
  }
  L004b9ad3: { // 0x4b9ad3: 8b464c MOV EAX, dword ptr [ESI + 0x4c]
    s.ax = m.r32((s.si+0x0000004cu));
  }
  L004b9ad6: { // 0x4b9ad6: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004b9ad8: { // 0x4b9ad8: 7e0e JLE 0x4b9ae8
    if(integer::condition("JLE",flags)) goto L004b9ae8;
  }
  L004b9ada: { // 0x4b9ada: 8b7640 MOV ESI, dword ptr [ESI + 0x40]
    s.si = m.r32((s.si+0x00000040u));
  }
  L004b9add: { // 0x4b9add: 391e CMP dword ptr [ESI], EBX
    (void)integer::sub(m.r32((s.si)),s.bx,32,flags);
  }
  L004b9adf: { // 0x4b9adf: 7501 JNZ 0x4b9ae2
    if(integer::condition("JNZ",flags)) goto L004b9ae2;
  }
  L004b9ae1: { // 0x4b9ae1: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L004b9ae2: { // 0x4b9ae2: 83c604 ADD ESI, 4
    s.si = integer::add(s.si,4u,32,flags);
  }
  L004b9ae5: { // 0x4b9ae5: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L004b9ae6: { // 0x4b9ae6: 75f5 JNZ 0x4b9add
    if(integer::condition("JNZ",flags)) goto L004b9add;
  }
  L004b9ae8: { // 0x4b9ae8: 8bc7 MOV EAX, EDI
    s.ax = s.di;
  }
  L004b9aea: { // 0x4b9aea: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004b9aeb: { // 0x4b9aeb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004b9aec: { // 0x4b9aec: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004b9aed: { // 0x4b9aed: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_002b6910(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006b6910: { // 0x6b6910: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006b6912: {if(m.r32(s.ax+0x84)!=0x4538b0)throw std::domain_error("739 unprovedtail");s.arithmetic_flags=flags;f_000538b0(m,s,f,op);return;
  }
}
void f_000538b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004538b0: { // 0x4538b0: 8b8118040000 MOV EAX, dword ptr [ECX + 0x418]
    s.ax = m.r32((s.cx+0x00000418u));
  }
  L004538b6: { // 0x4538b6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_00053890(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00453890: { // 0x453890: b806000000 MOV EAX, 6
    s.ax = 6u;
  }
  L00453895: { // 0x453895: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00010250(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00410250: { // 0x410250: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00410252: { // 0x410252: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000eaa70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004eaa70: { // 0x4eaa70: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004eaa71: { // 0x4eaa71: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L004eaa73: { // 0x4eaa73: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L004eaa75: { // 0x4eaa75: 7d04 JGE 0x4eaa7b
    if(integer::condition("JGE",flags)) goto L004eaa7b;
  }
  L004eaa77: { // 0x4eaa77: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004eaa79: { // 0x4eaa79: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004eaa7a: { // 0x4eaa7a: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004eaa7b: { // 0x4eaa7b: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004eaa7d: { // 0x4eaa7d: e81e7ff9ff CALL 0x4829a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004829a0u,5155458u); flags=s.arithmetic_flags;
  }
  L004eaa82: { // 0x4eaa82: 83fe06 CMP ESI, 6
    (void)integer::sub(s.si,6u,32,flags);
  }
  L004eaa85: { // 0x4eaa85: 7409 JZ 0x4eaa90
    if(integer::condition("JZ",flags)) goto L004eaa90;
  }
  L004eaa87: { // 0x4eaa87: 83fe07 CMP ESI, 7
    (void)integer::sub(s.si,7u,32,flags);
  }
  L004eaa8a: { // 0x4eaa8a: 7404 JZ 0x4eaa90
    if(integer::condition("JZ",flags)) goto L004eaa90;
  }
  L004eaa8c: { // 0x4eaa8c: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004eaa8e: { // 0x4eaa8e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004eaa8f: { // 0x4eaa8f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004eaa90: { // 0x4eaa90: 8b80a00b0000 MOV EAX, dword ptr [EAX + 0xba0]
    s.ax = m.r32((s.ax+0x00000ba0u));
  }
  L004eaa96: { // 0x4eaa96: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004eaa97: { // 0x4eaa97: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000829a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004829a0: { // 0x4829a0: 8d41ff LEA EAX, [ECX - 1]
    s.ax = (s.cx-1u);
  }
  L004829a3: { // 0x4829a3: 83f827 CMP EAX, 0x27
    (void)integer::sub(s.ax,0x00000027u,32,flags);
  }
  L004829a6: { // 0x4829a6: 7735 JA 0x4829dd
    if(integer::condition("JA",flags)) goto L004829dd;
  }
  L004829a8: { // 0x4829a8: 33c9 XOR ECX, ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L004829aa: { // 0x4829aa: 8a88f4294800 MOV CL, byte ptr [EAX + 0x4829f4]
    s.cx = with_al(s.cx, table_4829e0[20+s.ax]);
  }
  L004829b0: { // 0x4829b0: ff248de0294800 JMP dword ptr [ECX*4 + 0x4829e0]
    switch((std::uint32_t(table_4829e0[0+4*s.cx])|(std::uint32_t(table_4829e0[0+4*s.cx+1])<<8)|(std::uint32_t(table_4829e0[0+4*s.cx+2])<<16)|(std::uint32_t(table_4829e0[0+4*s.cx+3])<<24))){
    case 0x004829a0u: goto L004829a0;
    case 0x004829a3u: goto L004829a3;
    case 0x004829a6u: goto L004829a6;
    case 0x004829a8u: goto L004829a8;
    case 0x004829aau: goto L004829aa;
    case 0x004829b0u: goto L004829b0;
    case 0x004829b7u: goto L004829b7;
    case 0x004829bcu: goto L004829bc;
    case 0x004829bfu: goto L004829bf;
    case 0x004829c0u: goto L004829c0;
    case 0x004829c6u: goto L004829c6;
    case 0x004829c9u: goto L004829c9;
    case 0x004829cau: goto L004829ca;
    case 0x004829cfu: goto L004829cf;
    case 0x004829d2u: goto L004829d2;
    case 0x004829d3u: goto L004829d3;
    case 0x004829d9u: goto L004829d9;
    case 0x004829dcu: goto L004829dc;
    case 0x004829ddu: goto L004829dd;
    case 0x004829dfu: goto L004829df;
    default:throw std::domain_error("recovery739 unsupported switch destination");}
  }
  L004829b7: { // 0x4829b7: a17ce0a100 MOV EAX, dword ptr [0xa1e07c]
    s.ax = m.r32((0x00a1e07cu));
  }
  L004829bc: { // 0x4829bc: 8b0490 MOV EAX, dword ptr [EAX + EDX*4]
    s.ax = m.r32((s.ax+(s.dx * 4u)));
  }
  L004829bf: { // 0x4829bf: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004829c0: { // 0x4829c0: 8b0d0ce0a100 MOV ECX, dword ptr [0xa1e00c]
    s.cx = m.r32((0x00a1e00cu));
  }
  L004829c6: { // 0x4829c6: 8b0491 MOV EAX, dword ptr [ECX + EDX*4]
    s.ax = m.r32((s.cx+(s.dx * 4u)));
  }
  L004829c9: { // 0x4829c9: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004829ca: { // 0x4829ca: a1a47fa200 MOV EAX, dword ptr [0xa27fa4]
    s.ax = m.r32((0x00a27fa4u));
  }
  L004829cf: { // 0x4829cf: 8b0490 MOV EAX, dword ptr [EAX + EDX*4]
    s.ax = m.r32((s.ax+(s.dx * 4u)));
  }
  L004829d2: { // 0x4829d2: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004829d3: { // 0x4829d3: 8b0dac55a200 MOV ECX, dword ptr [0xa255ac]
    s.cx = m.r32((0x00a255acu));
  }
  L004829d9: { // 0x4829d9: 8b0491 MOV EAX, dword ptr [ECX + EDX*4]
    s.ax = m.r32((s.cx+(s.dx * 4u)));
  }
  L004829dc: { // 0x4829dc: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004829dd: { // 0x4829dd: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004829df: { // 0x4829df: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000e0030(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004e0030: { // 0x4e0030: a1ac1c8200 MOV EAX, dword ptr [0x821cac]
    s.ax = m.r32((0x00821cacu));
  }
  L004e0035: { // 0x4e0035: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e0037: { // 0x4e0037: 7407 JZ 0x4e0040
    if(integer::condition("JZ",flags)) goto L004e0040;
  }
  L004e0039: { // 0x4e0039: c6807d0d000001 MOV byte ptr [EAX + 0xd7d], 1
    m.w8((s.ax+0x00000d7du), 1u);
  }
  L004e0040: { // 0x4e0040: 8b442404 MOV EAX, dword ptr [ESP + 4]
    s.ax = m.r32((f.sp+4u));
  }
  L004e0044: { // 0x4e0044: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e0046: { // 0x4e0046: 7413 JZ 0x4e005b
    if(integer::condition("JZ",flags)) goto L004e005b;
  }
  L004e0048: { // 0x4e0048: 83790c02 CMP dword ptr [ECX + 0xc], 2
    (void)integer::sub(m.r32((s.cx+0x0000000cu)),2u,32,flags);
  }
  L004e004c: { // 0x4e004c: 7403 JZ 0x4e0051
    if(integer::condition("JZ",flags)) goto L004e0051;
  }
  L004e004e: { // 0x4e004e: 89410c MOV dword ptr [ECX + 0xc], EAX
    m.w32((s.cx+0x0000000cu), s.ax);
  }
  L004e0051: { // 0x4e0051: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L004e0056: { // 0x4e0056: e8557a0700 CALL 0x557ab0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557ab0u,5111899u); flags=s.arithmetic_flags;
  }
  L004e005b: { // 0x4e005b: c20400 RET 4
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
void f_000f4430(Memory&m,State&s,Frame&f,const Operations&op){
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004f4430: { // 0x4f4430: 83ec08 SUB ESP, 8
    f.sp = integer::sub(f.sp,8u,32,flags);
  }
  L004f4433: { // 0x4f4433: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004f4434: { // 0x4f4434: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004f4435: { // 0x4f4435: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004f4436: { // 0x4f4436: 8b742418 MOV ESI, dword ptr [ESP + 0x18]
    s.si = m.r32((f.sp+0x00000018u));
  }
  L004f443a: { // 0x4f443a: 8be9 MOV EBP, ECX
    s.bp = s.cx;
  }
  L004f443c: { // 0x4f443c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004f443d: { // 0x4f443d: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L004f443f: { // 0x4f443f: 896c2414 MOV dword ptr [ESP + 0x14], EBP
    m.w32((f.sp+0x00000014u), s.bp);
  }
  L004f4443: { // 0x4f4443: 0f84cb020000 JZ 0x4f4714
    if(integer::condition("JZ",flags)) goto L004f4714;
  }
  L004f4449: { // 0x4f4449: 8a86da0a0000 MOV AL, byte ptr [ESI + 0xada]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000adau)));
  }
  L004f444f: { // 0x4f444f: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004f4451: { // 0x4f4451: 33db XOR EBX, EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L004f4453: { // 0x4f4453: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004f4455: { // 0x4f4455: 895c2410 MOV dword ptr [ESP + 0x10], EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
  L004f4459: { // 0x4f4459: 8844241c MOV byte ptr [ESP + 0x1c], AL
    m.w8((f.sp+0x0000001cu), (s.ax & 0xffu));
  }
  L004f445d: { // 0x4f445d: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),5194848u); flags=s.arithmetic_flags;
  }
  L004f4460: { // 0x4f4460: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L004f4461: { // 0x4f4461: 83f827 CMP EAX, 0x27
    (void)integer::sub(s.ax,0x00000027u,32,flags);
  }
  L004f4464: { // 0x4f4464: 0f87c8000000 JA 0x4f4532
    if(integer::condition("JA",flags)) goto L004f4532;
  }
  L004f446a: { // 0x4f446a: 33c9 XOR ECX, ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L004f446c: { // 0x4f446c: 8a8840474f00 MOV CL, byte ptr [EAX + 0x4f4740]
    s.cx = with_al(s.cx, table_4f472c[20+s.ax]);
  }
  L004f4472: { // 0x4f4472: ff248d2c474f00 JMP dword ptr [ECX*4 + 0x4f472c]
    switch((std::uint32_t(table_4f472c[0+4*s.cx])|(std::uint32_t(table_4f472c[0+4*s.cx+1])<<8)|(std::uint32_t(table_4f472c[0+4*s.cx+2])<<16)|(std::uint32_t(table_4f472c[0+4*s.cx+3])<<24))){
    case 0x004f4430u: goto L004f4430;
    case 0x004f4433u: goto L004f4433;
    case 0x004f4434u: goto L004f4434;
    case 0x004f4435u: goto L004f4435;
    case 0x004f4436u: goto L004f4436;
    case 0x004f443au: goto L004f443a;
    case 0x004f443cu: goto L004f443c;
    case 0x004f443du: goto L004f443d;
    case 0x004f443fu: goto L004f443f;
    case 0x004f4443u: goto L004f4443;
    case 0x004f4449u: goto L004f4449;
    case 0x004f444fu: goto L004f444f;
    case 0x004f4451u: goto L004f4451;
    case 0x004f4453u: goto L004f4453;
    case 0x004f4455u: goto L004f4455;
    case 0x004f4459u: goto L004f4459;
    case 0x004f445du: goto L004f445d;
    case 0x004f4460u: goto L004f4460;
    case 0x004f4461u: goto L004f4461;
    case 0x004f4464u: goto L004f4464;
    case 0x004f446au: goto L004f446a;
    case 0x004f446cu: goto L004f446c;
    case 0x004f4472u: goto L004f4472;
    case 0x004f4479u: goto L004f4479;
    case 0x004f447fu: goto L004f447f;
    case 0x004f4481u: goto L004f4481;
    case 0x004f4483u: goto L004f4483;
    case 0x004f4484u: goto L004f4484;
    case 0x004f4486u: goto L004f4486;
    case 0x004f448bu: goto L004f448b;
    case 0x004f448fu: goto L004f448f;
    case 0x004f4491u: goto L004f4491;
    case 0x004f4493u: goto L004f4493;
    case 0x004f4495u: goto L004f4495;
    case 0x004f4498u: goto L004f4498;
    case 0x004f449bu: goto L004f449b;
    case 0x004f449eu: goto L004f449e;
    case 0x004f44a4u: goto L004f44a4;
    case 0x004f44a6u: goto L004f44a6;
    case 0x004f44acu: goto L004f44ac;
    case 0x004f44b3u: goto L004f44b3;
    case 0x004f44b9u: goto L004f44b9;
    case 0x004f44bbu: goto L004f44bb;
    case 0x004f44bdu: goto L004f44bd;
    case 0x004f44bfu: goto L004f44bf;
    case 0x004f44c1u: goto L004f44c1;
    case 0x004f44c4u: goto L004f44c4;
    case 0x004f44c5u: goto L004f44c5;
    case 0x004f44cbu: goto L004f44cb;
    case 0x004f44d0u: goto L004f44d0;
    case 0x004f44d2u: goto L004f44d2;
    case 0x004f44d4u: goto L004f44d4;
    case 0x004f44d5u: goto L004f44d5;
    case 0x004f44d7u: goto L004f44d7;
    case 0x004f44d9u: goto L004f44d9;
    case 0x004f44dbu: goto L004f44db;
    case 0x004f44ddu: goto L004f44dd;
    case 0x004f44e3u: goto L004f44e3;
    case 0x004f44e5u: goto L004f44e5;
    case 0x004f44ebu: goto L004f44eb;
    case 0x004f44edu: goto L004f44ed;
    case 0x004f44efu: goto L004f44ef;
    case 0x004f44f2u: goto L004f44f2;
    case 0x004f44f3u: goto L004f44f3;
    case 0x004f44f9u: goto L004f44f9;
    case 0x004f44feu: goto L004f44fe;
    case 0x004f4502u: goto L004f4502;
    case 0x004f4504u: goto L004f4504;
    case 0x004f4506u: goto L004f4506;
    case 0x004f450cu: goto L004f450c;
    case 0x004f4511u: goto L004f4511;
    case 0x004f4517u: goto L004f4517;
    case 0x004f451cu: goto L004f451c;
    case 0x004f4522u: goto L004f4522;
    case 0x004f4527u: goto L004f4527;
    case 0x004f452du: goto L004f452d;
    case 0x004f4532u: goto L004f4532;
    case 0x004f4534u: goto L004f4534;
    case 0x004f4539u: goto L004f4539;
    case 0x004f453fu: goto L004f453f;
    case 0x004f4541u: goto L004f4541;
    case 0x004f4543u: goto L004f4543;
    case 0x004f4545u: goto L004f4545;
    case 0x004f4547u: goto L004f4547;
    case 0x004f454au: goto L004f454a;
    case 0x004f454bu: goto L004f454b;
    case 0x004f4551u: goto L004f4551;
    case 0x004f4556u: goto L004f4556;
    case 0x004f4558u: goto L004f4558;
    case 0x004f455eu: goto L004f455e;
    case 0x004f455fu: goto L004f455f;
    case 0x004f4561u: goto L004f4561;
    case 0x004f4563u: goto L004f4563;
    case 0x004f4565u: goto L004f4565;
    case 0x004f4567u: goto L004f4567;
    case 0x004f456du: goto L004f456d;
    case 0x004f456fu: goto L004f456f;
    case 0x004f4571u: goto L004f4571;
    case 0x004f4574u: goto L004f4574;
    case 0x004f4575u: goto L004f4575;
    case 0x004f457bu: goto L004f457b;
    case 0x004f4580u: goto L004f4580;
    case 0x004f4584u: goto L004f4584;
    case 0x004f458au: goto L004f458a;
    case 0x004f458cu: goto L004f458c;
    case 0x004f458eu: goto L004f458e;
    case 0x004f4593u: goto L004f4593;
    case 0x004f4595u: goto L004f4595;
    case 0x004f4597u: goto L004f4597;
    case 0x004f4599u: goto L004f4599;
    case 0x004f459eu: goto L004f459e;
    case 0x004f45a1u: goto L004f45a1;
    case 0x004f45a7u: goto L004f45a7;
    case 0x004f45a9u: goto L004f45a9;
    case 0x004f45abu: goto L004f45ab;
    case 0x004f45adu: goto L004f45ad;
    case 0x004f45b0u: goto L004f45b0;
    case 0x004f45b6u: goto L004f45b6;
    case 0x004f45b8u: goto L004f45b8;
    case 0x004f45bcu: goto L004f45bc;
    case 0x004f45c1u: goto L004f45c1;
    case 0x004f45c2u: goto L004f45c2;
    case 0x004f45c4u: goto L004f45c4;
    case 0x004f45c6u: goto L004f45c6;
    case 0x004f45cau: goto L004f45ca;
    case 0x004f45d0u: goto L004f45d0;
    case 0x004f45d2u: goto L004f45d2;
    case 0x004f45d8u: goto L004f45d8;
    case 0x004f45dcu: goto L004f45dc;
    case 0x004f45deu: goto L004f45de;
    case 0x004f45e0u: goto L004f45e0;
    case 0x004f45e5u: goto L004f45e5;
    case 0x004f45ebu: goto L004f45eb;
    case 0x004f45edu: goto L004f45ed;
    case 0x004f45efu: goto L004f45ef;
    case 0x004f45f1u: goto L004f45f1;
    case 0x004f45f3u: goto L004f45f3;
    case 0x004f45f6u: goto L004f45f6;
    case 0x004f45f7u: goto L004f45f7;
    case 0x004f45fdu: goto L004f45fd;
    case 0x004f4602u: goto L004f4602;
    case 0x004f4604u: goto L004f4604;
    case 0x004f4606u: goto L004f4606;
    case 0x004f4607u: goto L004f4607;
    case 0x004f4609u: goto L004f4609;
    case 0x004f460bu: goto L004f460b;
    case 0x004f460du: goto L004f460d;
    case 0x004f460fu: goto L004f460f;
    case 0x004f4615u: goto L004f4615;
    case 0x004f4617u: goto L004f4617;
    case 0x004f461du: goto L004f461d;
    case 0x004f461fu: goto L004f461f;
    case 0x004f4621u: goto L004f4621;
    case 0x004f4624u: goto L004f4624;
    case 0x004f4625u: goto L004f4625;
    case 0x004f462bu: goto L004f462b;
    case 0x004f4630u: goto L004f4630;
    case 0x004f4636u: goto L004f4636;
    case 0x004f4638u: goto L004f4638;
    case 0x004f463au: goto L004f463a;
    case 0x004f463fu: goto L004f463f;
    case 0x004f4641u: goto L004f4641;
    case 0x004f4643u: goto L004f4643;
    case 0x004f4647u: goto L004f4647;
    case 0x004f464du: goto L004f464d;
    case 0x004f464fu: goto L004f464f;
    case 0x004f4655u: goto L004f4655;
    case 0x004f465bu: goto L004f465b;
    case 0x004f465eu: goto L004f465e;
    case 0x004f4660u: goto L004f4660;
    case 0x004f4663u: goto L004f4663;
    case 0x004f4664u: goto L004f4664;
    case 0x004f4666u: goto L004f4666;
    case 0x004f466bu: goto L004f466b;
    case 0x004f466du: goto L004f466d;
    case 0x004f466fu: goto L004f466f;
    case 0x004f4671u: goto L004f4671;
    case 0x004f4676u: goto L004f4676;
    case 0x004f467cu: goto L004f467c;
    case 0x004f467fu: goto L004f467f;
    case 0x004f4681u: goto L004f4681;
    case 0x004f4682u: goto L004f4682;
    case 0x004f4687u: goto L004f4687;
    case 0x004f468bu: goto L004f468b;
    case 0x004f4690u: goto L004f4690;
    case 0x004f4691u: goto L004f4691;
    case 0x004f4697u: goto L004f4697;
    case 0x004f4699u: goto L004f4699;
    case 0x004f469du: goto L004f469d;
    case 0x004f46a1u: goto L004f46a1;
    case 0x004f46a7u: goto L004f46a7;
    case 0x004f46a9u: goto L004f46a9;
    case 0x004f46abu: goto L004f46ab;
    case 0x004f46adu: goto L004f46ad;
    case 0x004f46aeu: goto L004f46ae;
    case 0x004f46afu: goto L004f46af;
    case 0x004f46b0u: goto L004f46b0;
    case 0x004f46b2u: goto L004f46b2;
    case 0x004f46b3u: goto L004f46b3;
    case 0x004f46b6u: goto L004f46b6;
    case 0x004f46b9u: goto L004f46b9;
    case 0x004f46bfu: goto L004f46bf;
    case 0x004f46c1u: goto L004f46c1;
    case 0x004f46c3u: goto L004f46c3;
    case 0x004f46c5u: goto L004f46c5;
    case 0x004f46c7u: goto L004f46c7;
    case 0x004f46cau: goto L004f46ca;
    case 0x004f46cbu: goto L004f46cb;
    case 0x004f46d1u: goto L004f46d1;
    case 0x004f46d6u: goto L004f46d6;
    case 0x004f46d8u: goto L004f46d8;
    case 0x004f46dau: goto L004f46da;
    case 0x004f46dbu: goto L004f46db;
    case 0x004f46ddu: goto L004f46dd;
    case 0x004f46dfu: goto L004f46df;
    case 0x004f46e1u: goto L004f46e1;
    case 0x004f46e3u: goto L004f46e3;
    case 0x004f46e5u: goto L004f46e5;
    case 0x004f46e6u: goto L004f46e6;
    case 0x004f46e7u: goto L004f46e7;
    case 0x004f46e8u: goto L004f46e8;
    case 0x004f46eau: goto L004f46ea;
    case 0x004f46ebu: goto L004f46eb;
    case 0x004f46eeu: goto L004f46ee;
    case 0x004f46f1u: goto L004f46f1;
    case 0x004f46f3u: goto L004f46f3;
    case 0x004f46f5u: goto L004f46f5;
    case 0x004f46f7u: goto L004f46f7;
    case 0x004f46f9u: goto L004f46f9;
    case 0x004f46fcu: goto L004f46fc;
    case 0x004f46fdu: goto L004f46fd;
    case 0x004f4703u: goto L004f4703;
    case 0x004f4708u: goto L004f4708;
    case 0x004f470eu: goto L004f470e;
    case 0x004f4710u: goto L004f4710;
    case 0x004f4712u: goto L004f4712;
    case 0x004f4714u: goto L004f4714;
    case 0x004f4715u: goto L004f4715;
    case 0x004f4716u: goto L004f4716;
    case 0x004f4717u: goto L004f4717;
    case 0x004f4719u: goto L004f4719;
    case 0x004f471au: goto L004f471a;
    case 0x004f471du: goto L004f471d;
    case 0x004f4720u: goto L004f4720;
    case 0x004f4721u: goto L004f4721;
    case 0x004f4722u: goto L004f4722;
    case 0x004f4723u: goto L004f4723;
    case 0x004f4725u: goto L004f4725;
    case 0x004f4726u: goto L004f4726;
    case 0x004f4729u: goto L004f4729;
    default:throw std::domain_error("recovery739 unsupported switch destination");}
  }
  L004f4479: { // 0x4f4479: 8bbddc520000 MOV EDI, dword ptr [EBP + 0x52dc]
    s.di = m.r32((s.bp+0x000052dcu));
  }
  L004f447f: { // 0x4f447f: 85ff TEST EDI, EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L004f4481: { // 0x4f4481: 740e JZ 0x4f4491
    if(integer::condition("JZ",flags)) goto L004f4491;
  }
  L004f4483: { // 0x4f4483: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004f4484: { // 0x4f4484: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L004f4486: { // 0x4f4486: e82556fcff CALL 0x4b9ab0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004b9ab0u,5194891u); flags=s.arithmetic_flags;
  }
  L004f448b: { // 0x4f448b: 89442410 MOV dword ptr [ESP + 0x10], EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L004f448f: { // 0x4f448f: 8bd8 MOV EBX, EAX
    s.bx = s.ax;
  }
  L004f4491: { // 0x4f4491: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004f4493: { // 0x4f4493: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004f4495: { // 0x4f4495: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),5194904u); flags=s.arithmetic_flags;
  }
  L004f4498: { // 0x4f4498: 83c0fd ADD EAX, -3
    s.ax = integer::add(s.ax,4294967293u,32,flags);
  }
  L004f449b: { // 0x4f449b: 83f825 CMP EAX, 0x25
    (void)integer::sub(s.ax,0x00000025u,32,flags);
  }
  L004f449e: { // 0x4f449e: 0f877c020000 JA 0x4f4720
    if(integer::condition("JA",flags)) goto L004f4720;
  }
  L004f44a4: { // 0x4f44a4: 33c9 XOR ECX, ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L004f44a6: { // 0x4f44a6: 8a887c474f00 MOV CL, byte ptr [EAX + 0x4f477c]
    s.cx = with_al(s.cx, table_4f472c[80+s.ax]);
  }
  L004f44ac: { // 0x4f44ac: ff248d68474f00 JMP dword ptr [ECX*4 + 0x4f4768]
    switch((std::uint32_t(table_4f472c[60+4*s.cx])|(std::uint32_t(table_4f472c[60+4*s.cx+1])<<8)|(std::uint32_t(table_4f472c[60+4*s.cx+2])<<16)|(std::uint32_t(table_4f472c[60+4*s.cx+3])<<24))){
    case 0x004f4430u: goto L004f4430;
    case 0x004f4433u: goto L004f4433;
    case 0x004f4434u: goto L004f4434;
    case 0x004f4435u: goto L004f4435;
    case 0x004f4436u: goto L004f4436;
    case 0x004f443au: goto L004f443a;
    case 0x004f443cu: goto L004f443c;
    case 0x004f443du: goto L004f443d;
    case 0x004f443fu: goto L004f443f;
    case 0x004f4443u: goto L004f4443;
    case 0x004f4449u: goto L004f4449;
    case 0x004f444fu: goto L004f444f;
    case 0x004f4451u: goto L004f4451;
    case 0x004f4453u: goto L004f4453;
    case 0x004f4455u: goto L004f4455;
    case 0x004f4459u: goto L004f4459;
    case 0x004f445du: goto L004f445d;
    case 0x004f4460u: goto L004f4460;
    case 0x004f4461u: goto L004f4461;
    case 0x004f4464u: goto L004f4464;
    case 0x004f446au: goto L004f446a;
    case 0x004f446cu: goto L004f446c;
    case 0x004f4472u: goto L004f4472;
    case 0x004f4479u: goto L004f4479;
    case 0x004f447fu: goto L004f447f;
    case 0x004f4481u: goto L004f4481;
    case 0x004f4483u: goto L004f4483;
    case 0x004f4484u: goto L004f4484;
    case 0x004f4486u: goto L004f4486;
    case 0x004f448bu: goto L004f448b;
    case 0x004f448fu: goto L004f448f;
    case 0x004f4491u: goto L004f4491;
    case 0x004f4493u: goto L004f4493;
    case 0x004f4495u: goto L004f4495;
    case 0x004f4498u: goto L004f4498;
    case 0x004f449bu: goto L004f449b;
    case 0x004f449eu: goto L004f449e;
    case 0x004f44a4u: goto L004f44a4;
    case 0x004f44a6u: goto L004f44a6;
    case 0x004f44acu: goto L004f44ac;
    case 0x004f44b3u: goto L004f44b3;
    case 0x004f44b9u: goto L004f44b9;
    case 0x004f44bbu: goto L004f44bb;
    case 0x004f44bdu: goto L004f44bd;
    case 0x004f44bfu: goto L004f44bf;
    case 0x004f44c1u: goto L004f44c1;
    case 0x004f44c4u: goto L004f44c4;
    case 0x004f44c5u: goto L004f44c5;
    case 0x004f44cbu: goto L004f44cb;
    case 0x004f44d0u: goto L004f44d0;
    case 0x004f44d2u: goto L004f44d2;
    case 0x004f44d4u: goto L004f44d4;
    case 0x004f44d5u: goto L004f44d5;
    case 0x004f44d7u: goto L004f44d7;
    case 0x004f44d9u: goto L004f44d9;
    case 0x004f44dbu: goto L004f44db;
    case 0x004f44ddu: goto L004f44dd;
    case 0x004f44e3u: goto L004f44e3;
    case 0x004f44e5u: goto L004f44e5;
    case 0x004f44ebu: goto L004f44eb;
    case 0x004f44edu: goto L004f44ed;
    case 0x004f44efu: goto L004f44ef;
    case 0x004f44f2u: goto L004f44f2;
    case 0x004f44f3u: goto L004f44f3;
    case 0x004f44f9u: goto L004f44f9;
    case 0x004f44feu: goto L004f44fe;
    case 0x004f4502u: goto L004f4502;
    case 0x004f4504u: goto L004f4504;
    case 0x004f4506u: goto L004f4506;
    case 0x004f450cu: goto L004f450c;
    case 0x004f4511u: goto L004f4511;
    case 0x004f4517u: goto L004f4517;
    case 0x004f451cu: goto L004f451c;
    case 0x004f4522u: goto L004f4522;
    case 0x004f4527u: goto L004f4527;
    case 0x004f452du: goto L004f452d;
    case 0x004f4532u: goto L004f4532;
    case 0x004f4534u: goto L004f4534;
    case 0x004f4539u: goto L004f4539;
    case 0x004f453fu: goto L004f453f;
    case 0x004f4541u: goto L004f4541;
    case 0x004f4543u: goto L004f4543;
    case 0x004f4545u: goto L004f4545;
    case 0x004f4547u: goto L004f4547;
    case 0x004f454au: goto L004f454a;
    case 0x004f454bu: goto L004f454b;
    case 0x004f4551u: goto L004f4551;
    case 0x004f4556u: goto L004f4556;
    case 0x004f4558u: goto L004f4558;
    case 0x004f455eu: goto L004f455e;
    case 0x004f455fu: goto L004f455f;
    case 0x004f4561u: goto L004f4561;
    case 0x004f4563u: goto L004f4563;
    case 0x004f4565u: goto L004f4565;
    case 0x004f4567u: goto L004f4567;
    case 0x004f456du: goto L004f456d;
    case 0x004f456fu: goto L004f456f;
    case 0x004f4571u: goto L004f4571;
    case 0x004f4574u: goto L004f4574;
    case 0x004f4575u: goto L004f4575;
    case 0x004f457bu: goto L004f457b;
    case 0x004f4580u: goto L004f4580;
    case 0x004f4584u: goto L004f4584;
    case 0x004f458au: goto L004f458a;
    case 0x004f458cu: goto L004f458c;
    case 0x004f458eu: goto L004f458e;
    case 0x004f4593u: goto L004f4593;
    case 0x004f4595u: goto L004f4595;
    case 0x004f4597u: goto L004f4597;
    case 0x004f4599u: goto L004f4599;
    case 0x004f459eu: goto L004f459e;
    case 0x004f45a1u: goto L004f45a1;
    case 0x004f45a7u: goto L004f45a7;
    case 0x004f45a9u: goto L004f45a9;
    case 0x004f45abu: goto L004f45ab;
    case 0x004f45adu: goto L004f45ad;
    case 0x004f45b0u: goto L004f45b0;
    case 0x004f45b6u: goto L004f45b6;
    case 0x004f45b8u: goto L004f45b8;
    case 0x004f45bcu: goto L004f45bc;
    case 0x004f45c1u: goto L004f45c1;
    case 0x004f45c2u: goto L004f45c2;
    case 0x004f45c4u: goto L004f45c4;
    case 0x004f45c6u: goto L004f45c6;
    case 0x004f45cau: goto L004f45ca;
    case 0x004f45d0u: goto L004f45d0;
    case 0x004f45d2u: goto L004f45d2;
    case 0x004f45d8u: goto L004f45d8;
    case 0x004f45dcu: goto L004f45dc;
    case 0x004f45deu: goto L004f45de;
    case 0x004f45e0u: goto L004f45e0;
    case 0x004f45e5u: goto L004f45e5;
    case 0x004f45ebu: goto L004f45eb;
    case 0x004f45edu: goto L004f45ed;
    case 0x004f45efu: goto L004f45ef;
    case 0x004f45f1u: goto L004f45f1;
    case 0x004f45f3u: goto L004f45f3;
    case 0x004f45f6u: goto L004f45f6;
    case 0x004f45f7u: goto L004f45f7;
    case 0x004f45fdu: goto L004f45fd;
    case 0x004f4602u: goto L004f4602;
    case 0x004f4604u: goto L004f4604;
    case 0x004f4606u: goto L004f4606;
    case 0x004f4607u: goto L004f4607;
    case 0x004f4609u: goto L004f4609;
    case 0x004f460bu: goto L004f460b;
    case 0x004f460du: goto L004f460d;
    case 0x004f460fu: goto L004f460f;
    case 0x004f4615u: goto L004f4615;
    case 0x004f4617u: goto L004f4617;
    case 0x004f461du: goto L004f461d;
    case 0x004f461fu: goto L004f461f;
    case 0x004f4621u: goto L004f4621;
    case 0x004f4624u: goto L004f4624;
    case 0x004f4625u: goto L004f4625;
    case 0x004f462bu: goto L004f462b;
    case 0x004f4630u: goto L004f4630;
    case 0x004f4636u: goto L004f4636;
    case 0x004f4638u: goto L004f4638;
    case 0x004f463au: goto L004f463a;
    case 0x004f463fu: goto L004f463f;
    case 0x004f4641u: goto L004f4641;
    case 0x004f4643u: goto L004f4643;
    case 0x004f4647u: goto L004f4647;
    case 0x004f464du: goto L004f464d;
    case 0x004f464fu: goto L004f464f;
    case 0x004f4655u: goto L004f4655;
    case 0x004f465bu: goto L004f465b;
    case 0x004f465eu: goto L004f465e;
    case 0x004f4660u: goto L004f4660;
    case 0x004f4663u: goto L004f4663;
    case 0x004f4664u: goto L004f4664;
    case 0x004f4666u: goto L004f4666;
    case 0x004f466bu: goto L004f466b;
    case 0x004f466du: goto L004f466d;
    case 0x004f466fu: goto L004f466f;
    case 0x004f4671u: goto L004f4671;
    case 0x004f4676u: goto L004f4676;
    case 0x004f467cu: goto L004f467c;
    case 0x004f467fu: goto L004f467f;
    case 0x004f4681u: goto L004f4681;
    case 0x004f4682u: goto L004f4682;
    case 0x004f4687u: goto L004f4687;
    case 0x004f468bu: goto L004f468b;
    case 0x004f4690u: goto L004f4690;
    case 0x004f4691u: goto L004f4691;
    case 0x004f4697u: goto L004f4697;
    case 0x004f4699u: goto L004f4699;
    case 0x004f469du: goto L004f469d;
    case 0x004f46a1u: goto L004f46a1;
    case 0x004f46a7u: goto L004f46a7;
    case 0x004f46a9u: goto L004f46a9;
    case 0x004f46abu: goto L004f46ab;
    case 0x004f46adu: goto L004f46ad;
    case 0x004f46aeu: goto L004f46ae;
    case 0x004f46afu: goto L004f46af;
    case 0x004f46b0u: goto L004f46b0;
    case 0x004f46b2u: goto L004f46b2;
    case 0x004f46b3u: goto L004f46b3;
    case 0x004f46b6u: goto L004f46b6;
    case 0x004f46b9u: goto L004f46b9;
    case 0x004f46bfu: goto L004f46bf;
    case 0x004f46c1u: goto L004f46c1;
    case 0x004f46c3u: goto L004f46c3;
    case 0x004f46c5u: goto L004f46c5;
    case 0x004f46c7u: goto L004f46c7;
    case 0x004f46cau: goto L004f46ca;
    case 0x004f46cbu: goto L004f46cb;
    case 0x004f46d1u: goto L004f46d1;
    case 0x004f46d6u: goto L004f46d6;
    case 0x004f46d8u: goto L004f46d8;
    case 0x004f46dau: goto L004f46da;
    case 0x004f46dbu: goto L004f46db;
    case 0x004f46ddu: goto L004f46dd;
    case 0x004f46dfu: goto L004f46df;
    case 0x004f46e1u: goto L004f46e1;
    case 0x004f46e3u: goto L004f46e3;
    case 0x004f46e5u: goto L004f46e5;
    case 0x004f46e6u: goto L004f46e6;
    case 0x004f46e7u: goto L004f46e7;
    case 0x004f46e8u: goto L004f46e8;
    case 0x004f46eau: goto L004f46ea;
    case 0x004f46ebu: goto L004f46eb;
    case 0x004f46eeu: goto L004f46ee;
    case 0x004f46f1u: goto L004f46f1;
    case 0x004f46f3u: goto L004f46f3;
    case 0x004f46f5u: goto L004f46f5;
    case 0x004f46f7u: goto L004f46f7;
    case 0x004f46f9u: goto L004f46f9;
    case 0x004f46fcu: goto L004f46fc;
    case 0x004f46fdu: goto L004f46fd;
    case 0x004f4703u: goto L004f4703;
    case 0x004f4708u: goto L004f4708;
    case 0x004f470eu: goto L004f470e;
    case 0x004f4710u: goto L004f4710;
    case 0x004f4712u: goto L004f4712;
    case 0x004f4714u: goto L004f4714;
    case 0x004f4715u: goto L004f4715;
    case 0x004f4716u: goto L004f4716;
    case 0x004f4717u: goto L004f4717;
    case 0x004f4719u: goto L004f4719;
    case 0x004f471au: goto L004f471a;
    case 0x004f471du: goto L004f471d;
    case 0x004f4720u: goto L004f4720;
    case 0x004f4721u: goto L004f4721;
    case 0x004f4722u: goto L004f4722;
    case 0x004f4723u: goto L004f4723;
    case 0x004f4725u: goto L004f4725;
    case 0x004f4726u: goto L004f4726;
    case 0x004f4729u: goto L004f4729;
    default:throw std::domain_error("recovery739 unsupported switch destination");}
  }
  L004f44b3: { // 0x4f44b3: 8bbe88030000 MOV EDI, dword ptr [ESI + 0x388]
    s.di = m.r32((s.si+0x00000388u));
  }
  L004f44b9: { // 0x4f44b9: 85ff TEST EDI, EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L004f44bb: { // 0x4f44bb: 7f2e JG 0x4f44eb
    if(integer::condition("JG",flags)) goto L004f44eb;
  }
  L004f44bd: { // 0x4f44bd: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004f44bf: { // 0x4f44bf: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004f44c1: { // 0x4f44c1: ff5240 CALL dword ptr [EDX + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000040u)),5194948u); flags=s.arithmetic_flags;
  }
  L004f44c4: { // 0x4f44c4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004f44c5: { // 0x4f44c5: 8d8db0540000 LEA ECX, [EBP + 0x54b0]
    s.cx = (s.bp+0x000054b0u);
  }
  L004f44cb: { // 0x4f44cb: e820d6f9ff CALL 0x491af0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00491af0u,5194960u); flags=s.arithmetic_flags;
  }
  L004f44d0: { // 0x4f44d0: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L004f44d2: { // 0x4f44d2: 8bc7 MOV EAX, EDI
    s.ax = s.di;
  }
  L004f44d4: { // 0x4f44d4: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004f44d5: { // 0x4f44d5: 33c2 XOR EAX, EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L004f44d7: { // 0x4f44d7: 03cb ADD ECX, EBX
    s.cx = integer::add(s.cx,s.bx,32,flags);
  }
  L004f44d9: { // 0x4f44d9: 2bc2 SUB EAX, EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004f44db: { // 0x4f44db: 3bc8 CMP ECX, EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L004f44dd: { // 0x4f44dd: 0f8d31020000 JGE 0x4f4714
    if(integer::condition("JGE",flags)) goto L004f4714;
  }
  L004f44e3: { // 0x4f44e3: 85ff TEST EDI, EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L004f44e5: { // 0x4f44e5: 0f8e35020000 JLE 0x4f4720
    if(integer::condition("JLE",flags)) goto L004f4720;
  }
  L004f44eb: { // 0x4f44eb: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004f44ed: { // 0x4f44ed: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004f44ef: { // 0x4f44ef: ff5240 CALL dword ptr [EDX + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000040u)),5194994u); flags=s.arithmetic_flags;
  }
  L004f44f2: { // 0x4f44f2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004f44f3: { // 0x4f44f3: 8d8d30540000 LEA ECX, [EBP + 0x5430]
    s.cx = (s.bp+0x00005430u);
  }
  L004f44f9: { // 0x4f44f9: e905020000 JMP 0x4f4703
    goto L004f4703;
  }
  L004f44fe: { // 0x4f44fe: 8a44241c MOV AL, byte ptr [ESP + 0x1c]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000001cu)));
  }
  L004f4502: { // 0x4f4502: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004f4504: { // 0x4f4504: 740b JZ 0x4f4511
    if(integer::condition("JZ",flags)) goto L004f4511;
  }
  L004f4506: { // 0x4f4506: 8bbde4520000 MOV EDI, dword ptr [EBP + 0x52e4]
    s.di = m.r32((s.bp+0x000052e4u));
  }
  L004f450c: { // 0x4f450c: e96effffff JMP 0x4f447f
    goto L004f447f;
  }
  L004f4511: { // 0x4f4511: 8bbde0520000 MOV EDI, dword ptr [EBP + 0x52e0]
    s.di = m.r32((s.bp+0x000052e0u));
  }
  L004f4517: { // 0x4f4517: e963ffffff JMP 0x4f447f
    goto L004f447f;
  }
  L004f451c: { // 0x4f451c: 8bbde8520000 MOV EDI, dword ptr [EBP + 0x52e8]
    s.di = m.r32((s.bp+0x000052e8u));
  }
  L004f4522: { // 0x4f4522: e958ffffff JMP 0x4f447f
    goto L004f447f;
  }
  L004f4527: { // 0x4f4527: 8bbdd8520000 MOV EDI, dword ptr [EBP + 0x52d8]
    s.di = m.r32((s.bp+0x000052d8u));
  }
  L004f452d: { // 0x4f452d: e94dffffff JMP 0x4f447f
    goto L004f447f;
  }
  L004f4532: { // 0x4f4532: 33ff XOR EDI, EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L004f4534: { // 0x4f4534: e958ffffff JMP 0x4f4491
    goto L004f4491;
  }
  L004f4539: { // 0x4f4539: 8b8688030000 MOV EAX, dword ptr [ESI + 0x388]
    s.ax = m.r32((s.si+0x00000388u));
  }
  L004f453f: { // 0x4f453f: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004f4541: { // 0x4f4541: 7f2a JG 0x4f456d
    if(integer::condition("JG",flags)) goto L004f456d;
  }
  L004f4543: { // 0x4f4543: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004f4545: { // 0x4f4545: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004f4547: { // 0x4f4547: ff5040 CALL dword ptr [EAX + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000040u)),5195082u); flags=s.arithmetic_flags;
  }
  L004f454a: { // 0x4f454a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004f454b: { // 0x4f454b: 8d8dc0540000 LEA ECX, [EBP + 0x54c0]
    s.cx = (s.bp+0x000054c0u);
  }
  L004f4551: { // 0x4f4551: e89ad5f9ff CALL 0x491af0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00491af0u,5195094u); flags=s.arithmetic_flags;
  }
  L004f4556: { // 0x4f4556: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L004f4558: { // 0x4f4558: 8b8688030000 MOV EAX, dword ptr [ESI + 0x388]
    s.ax = m.r32((s.si+0x00000388u));
  }
  L004f455e: { // 0x4f455e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004f455f: { // 0x4f455f: 33c2 XOR EAX, EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L004f4561: { // 0x4f4561: 03cb ADD ECX, EBX
    s.cx = integer::add(s.cx,s.bx,32,flags);
  }
  L004f4563: { // 0x4f4563: 2bc2 SUB EAX, EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004f4565: { // 0x4f4565: 3bc8 CMP ECX, EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L004f4567: { // 0x4f4567: 0f8da7010000 JGE 0x4f4714
    if(integer::condition("JGE",flags)) goto L004f4714;
  }
  L004f456d: { // 0x4f456d: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004f456f: { // 0x4f456f: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004f4571: { // 0x4f4571: ff5240 CALL dword ptr [EDX + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000040u)),5195124u); flags=s.arithmetic_flags;
  }
  L004f4574: { // 0x4f4574: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004f4575: { // 0x4f4575: 8d8d40540000 LEA ECX, [EBP + 0x5440]
    s.cx = (s.bp+0x00005440u);
  }
  L004f457b: { // 0x4f457b: e870d5f9ff CALL 0x491af0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00491af0u,5195136u); flags=s.arithmetic_flags;
  }
  L004f4580: { // 0x4f4580: 8944241c MOV dword ptr [ESP + 0x1c], EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L004f4584: { // 0x4f4584: 8a86140c0000 MOV AL, byte ptr [ESI + 0xc14]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000c14u)));
  }
  L004f458a: { // 0x4f458a: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004f458c: { // 0x4f458c: 743c JZ 0x4f45ca
    if(integer::condition("JZ",flags)) goto L004f45ca;
  }
  L004f458e: { // 0x4f458e: a1d8e48400 MOV EAX, dword ptr [0x84e4d8]
    s.ax = m.r32((0x0084e4d8u));
  }
  L004f4593: { // 0x4f4593: 33db XOR EBX, EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L004f4595: { // 0x4f4595: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004f4597: { // 0x4f4597: 7e2d JLE 0x4f45c6
    if(integer::condition("JLE",flags)) goto L004f45c6;
  }
  L004f4599: { // 0x4f4599: a1cce48400 MOV EAX, dword ptr [0x84e4cc]
    s.ax = m.r32((0x0084e4ccu));
  }
  L004f459e: { // 0x4f459e: 8b3c98 MOV EDI, dword ptr [EAX + EBX*4]
    s.di = m.r32((s.ax+(s.bx * 4u)));
  }
  L004f45a1: { // 0x4f45a1: 39afb4010000 CMP dword ptr [EDI + 0x1b4], EBP
    (void)integer::sub(m.r32((s.di+0x000001b4u)),s.bp,32,flags);
  }
  L004f45a7: { // 0x4f45a7: 7513 JNZ 0x4f45bc
    if(integer::condition("JNZ",flags)) goto L004f45bc;
  }
  L004f45a9: { // 0x4f45a9: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004f45ab: { // 0x4f45ab: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004f45ad: { // 0x4f45ad: ff5240 CALL dword ptr [EDX + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000040u)),5195184u); flags=s.arithmetic_flags;
  }
  L004f45b0: { // 0x4f45b0: 398790020000 CMP dword ptr [EDI + 0x290], EAX
    (void)integer::sub(m.r32((s.di+0x00000290u)),s.ax,32,flags);
  }
  L004f45b6: { // 0x4f45b6: 7504 JNZ 0x4f45bc
    if(integer::condition("JNZ",flags)) goto L004f45bc;
  }
  L004f45b8: { // 0x4f45b8: ff44241c INC dword ptr [ESP + 0x1c]
    m.w32((f.sp+0x0000001cu), integer::increment(m.r32((f.sp+0x0000001cu)),32,flags));
  }
  L004f45bc: { // 0x4f45bc: a1d8e48400 MOV EAX, dword ptr [0x84e4d8]
    s.ax = m.r32((0x0084e4d8u));
  }
  L004f45c1: { // 0x4f45c1: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L004f45c2: { // 0x4f45c2: 3bd8 CMP EBX, EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L004f45c4: { // 0x4f45c4: 7cd3 JL 0x4f4599
    if(integer::condition("JL",flags)) goto L004f4599;
  }
  L004f45c6: { // 0x4f45c6: 8b5c2410 MOV EBX, dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L004f45ca: { // 0x4f45ca: 8bb688030000 MOV ESI, dword ptr [ESI + 0x388]
    s.si = m.r32((s.si+0x00000388u));
  }
  L004f45d0: { // 0x4f45d0: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L004f45d2: { // 0x4f45d2: 0f8e48010000 JLE 0x4f4720
    if(integer::condition("JLE",flags)) goto L004f4720;
  }
  L004f45d8: { // 0x4f45d8: 8b44241c MOV EAX, dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L004f45dc: { // 0x4f45dc: 03c3 ADD EAX, EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L004f45de: { // 0x4f45de: 3bc6 CMP EAX, ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L004f45e0: { // 0x4f45e0: e92d010000 JMP 0x4f4712
    goto L004f4712;
  }
  L004f45e5: { // 0x4f45e5: 8bbe88030000 MOV EDI, dword ptr [ESI + 0x388]
    s.di = m.r32((s.si+0x00000388u));
  }
  L004f45eb: { // 0x4f45eb: 85ff TEST EDI, EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L004f45ed: { // 0x4f45ed: 7f2e JG 0x4f461d
    if(integer::condition("JG",flags)) goto L004f461d;
  }
  L004f45ef: { // 0x4f45ef: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004f45f1: { // 0x4f45f1: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004f45f3: { // 0x4f45f3: ff5240 CALL dword ptr [EDX + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000040u)),5195254u); flags=s.arithmetic_flags;
  }
  L004f45f6: { // 0x4f45f6: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004f45f7: { // 0x4f45f7: 8d8da0540000 LEA ECX, [EBP + 0x54a0]
    s.cx = (s.bp+0x000054a0u);
  }
  L004f45fd: { // 0x4f45fd: e8eed4f9ff CALL 0x491af0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00491af0u,5195266u); flags=s.arithmetic_flags;
  }
  L004f4602: { // 0x4f4602: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L004f4604: { // 0x4f4604: 8bc7 MOV EAX, EDI
    s.ax = s.di;
  }
  L004f4606: { // 0x4f4606: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004f4607: { // 0x4f4607: 33c2 XOR EAX, EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L004f4609: { // 0x4f4609: 03cb ADD ECX, EBX
    s.cx = integer::add(s.cx,s.bx,32,flags);
  }
  L004f460b: { // 0x4f460b: 2bc2 SUB EAX, EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004f460d: { // 0x4f460d: 3bc8 CMP ECX, EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L004f460f: { // 0x4f460f: 0f8dff000000 JGE 0x4f4714
    if(integer::condition("JGE",flags)) goto L004f4714;
  }
  L004f4615: { // 0x4f4615: 85ff TEST EDI, EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L004f4617: { // 0x4f4617: 0f8e03010000 JLE 0x4f4720
    if(integer::condition("JLE",flags)) goto L004f4720;
  }
  L004f461d: { // 0x4f461d: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004f461f: { // 0x4f461f: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004f4621: { // 0x4f4621: ff5240 CALL dword ptr [EDX + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000040u)),5195300u); flags=s.arithmetic_flags;
  }
  L004f4624: { // 0x4f4624: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004f4625: { // 0x4f4625: 8d8d20540000 LEA ECX, [EBP + 0x5420]
    s.cx = (s.bp+0x00005420u);
  }
  L004f462b: { // 0x4f462b: e9d3000000 JMP 0x4f4703
    goto L004f4703;
  }
  L004f4630: { // 0x4f4630: 8a86a30b0000 MOV AL, byte ptr [ESI + 0xba3]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000ba3u)));
  }
  L004f4636: { // 0x4f4636: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004f4638: { // 0x4f4638: 747f JZ 0x4f46b9
    if(integer::condition("JZ",flags)) goto L004f46b9;
  }
  L004f463a: { // 0x4f463a: a1881b8200 MOV EAX, dword ptr [0x821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L004f463f: { // 0x4f463f: 33f6 XOR ESI, ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L004f4641: { // 0x4f4641: 33db XOR EBX, EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L004f4643: { // 0x4f4643: 8974241c MOV dword ptr [ESP + 0x1c], ESI
    m.w32((f.sp+0x0000001cu), s.si);
  }
  L004f4647: { // 0x4f4647: 39b0180a0000 CMP dword ptr [EAX + 0xa18], ESI
    (void)integer::sub(m.r32((s.ax+0x00000a18u)),s.si,32,flags);
  }
  L004f464d: { // 0x4f464d: 7e4e JLE 0x4f469d
    if(integer::condition("JLE",flags)) goto L004f469d;
  }
  L004f464f: { // 0x4f464f: 81c590540000 ADD EBP, 0x5490
    s.bp = integer::add(s.bp,0x00005490u,32,flags);
  }
  L004f4655: { // 0x4f4655: 8b800c0a0000 MOV EAX, dword ptr [EAX + 0xa0c]
    s.ax = m.r32((s.ax+0x00000a0cu));
  }
  L004f465b: { // 0x4f465b: 8b0cb0 MOV ECX, dword ptr [EAX + ESI*4]
    s.cx = m.r32((s.ax+(s.si * 4u)));
  }
  L004f465e: { // 0x4f465e: 8b11 MOV EDX, dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L004f4660: { // 0x4f4660: ff5240 CALL dword ptr [EDX + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000040u)),5195363u); flags=s.arithmetic_flags;
  }
  L004f4663: { // 0x4f4663: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004f4664: { // 0x4f4664: 8bcd MOV ECX, EBP
    s.cx = s.bp;
  }
  L004f4666: { // 0x4f4666: e885d4f9ff CALL 0x491af0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00491af0u,5195371u); flags=s.arithmetic_flags;
  }
  L004f466b: { // 0x4f466b: 03d8 ADD EBX, EAX
    s.bx = integer::add(s.bx,s.ax,32,flags);
  }
  L004f466d: { // 0x4f466d: 85ff TEST EDI, EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L004f466f: { // 0x4f466f: 741a JZ 0x4f468b
    if(integer::condition("JZ",flags)) goto L004f468b;
  }
  L004f4671: { // 0x4f4671: a1881b8200 MOV EAX, dword ptr [0x821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L004f4676: { // 0x4f4676: 8b880c0a0000 MOV ECX, dword ptr [EAX + 0xa0c]
    s.cx = m.r32((s.ax+0x00000a0cu));
  }
  L004f467c: { // 0x4f467c: 8b14b1 MOV EDX, dword ptr [ECX + ESI*4]
    s.dx = m.r32((s.cx+(s.si * 4u)));
  }
  L004f467f: { // 0x4f467f: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L004f4681: { // 0x4f4681: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004f4682: { // 0x4f4682: e82954fcff CALL 0x4b9ab0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004b9ab0u,5195399u); flags=s.arithmetic_flags;
  }
  L004f4687: { // 0x4f4687: 0144241c ADD dword ptr [ESP + 0x1c], EAX
    m.w32((f.sp+0x0000001cu), integer::add(m.r32((f.sp+0x0000001cu)),s.ax,32,flags));
  }
  L004f468b: { // 0x4f468b: a1881b8200 MOV EAX, dword ptr [0x821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L004f4690: { // 0x4f4690: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L004f4691: { // 0x4f4691: 3bb0180a0000 CMP ESI, dword ptr [EAX + 0xa18]
    (void)integer::sub(s.si,m.r32((s.ax+0x00000a18u)),32,flags);
  }
  L004f4697: { // 0x4f4697: 7cbc JL 0x4f4655
    if(integer::condition("JL",flags)) goto L004f4655;
  }
  L004f4699: { // 0x4f4699: 8b6c2414 MOV EBP, dword ptr [ESP + 0x14]
    s.bp = m.r32((f.sp+0x00000014u));
  }
  L004f469d: { // 0x4f469d: 8b44241c MOV EAX, dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L004f46a1: { // 0x4f46a1: 8b8d18020000 MOV ECX, dword ptr [EBP + 0x218]
    s.cx = m.r32((s.bp+0x00000218u));
  }
  L004f46a7: { // 0x4f46a7: 03c3 ADD EAX, EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L004f46a9: { // 0x4f46a9: 3bc1 CMP EAX, ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L004f46ab: { // 0x4f46ab: 7c73 JL 0x4f4720
    if(integer::condition("JL",flags)) goto L004f4720;
  }
  L004f46ad: { // 0x4f46ad: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004f46ae: { // 0x4f46ae: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004f46af: { // 0x4f46af: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004f46b0: { // 0x4f46b0: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L004f46b2: { // 0x4f46b2: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004f46b3: { // 0x4f46b3: 83c408 ADD ESP, 8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  L004f46b6: { // 0x4f46b6: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004f46b9: { // 0x4f46b9: 8bbe88030000 MOV EDI, dword ptr [ESI + 0x388]
    s.di = m.r32((s.si+0x00000388u));
  }
  L004f46bf: { // 0x4f46bf: 85ff TEST EDI, EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L004f46c1: { // 0x4f46c1: 7f32 JG 0x4f46f5
    if(integer::condition("JG",flags)) goto L004f46f5;
  }
  L004f46c3: { // 0x4f46c3: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004f46c5: { // 0x4f46c5: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004f46c7: { // 0x4f46c7: ff5240 CALL dword ptr [EDX + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000040u)),5195466u); flags=s.arithmetic_flags;
  }
  L004f46ca: { // 0x4f46ca: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004f46cb: { // 0x4f46cb: 8d8dd0540000 LEA ECX, [EBP + 0x54d0]
    s.cx = (s.bp+0x000054d0u);
  }
  L004f46d1: { // 0x4f46d1: e81ad4f9ff CALL 0x491af0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00491af0u,5195478u); flags=s.arithmetic_flags;
  }
  L004f46d6: { // 0x4f46d6: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L004f46d8: { // 0x4f46d8: 8bc7 MOV EAX, EDI
    s.ax = s.di;
  }
  L004f46da: { // 0x4f46da: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004f46db: { // 0x4f46db: 33c2 XOR EAX, EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L004f46dd: { // 0x4f46dd: 03cb ADD ECX, EBX
    s.cx = integer::add(s.cx,s.bx,32,flags);
  }
  L004f46df: { // 0x4f46df: 2bc2 SUB EAX, EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004f46e1: { // 0x4f46e1: 3bc8 CMP ECX, EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L004f46e3: { // 0x4f46e3: 7c0c JL 0x4f46f1
    if(integer::condition("JL",flags)) goto L004f46f1;
  }
  L004f46e5: { // 0x4f46e5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004f46e6: { // 0x4f46e6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004f46e7: { // 0x4f46e7: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004f46e8: { // 0x4f46e8: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L004f46ea: { // 0x4f46ea: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004f46eb: { // 0x4f46eb: 83c408 ADD ESP, 8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  L004f46ee: { // 0x4f46ee: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004f46f1: { // 0x4f46f1: 85ff TEST EDI, EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L004f46f3: { // 0x4f46f3: 7e2b JLE 0x4f4720
    if(integer::condition("JLE",flags)) goto L004f4720;
  }
  L004f46f5: { // 0x4f46f5: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004f46f7: { // 0x4f46f7: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004f46f9: { // 0x4f46f9: ff5240 CALL dword ptr [EDX + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000040u)),5195516u); flags=s.arithmetic_flags;
  }
  L004f46fc: { // 0x4f46fc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004f46fd: { // 0x4f46fd: 8d8d50540000 LEA ECX, [EBP + 0x5450]
    s.cx = (s.bp+0x00005450u);
  }
  L004f4703: { // 0x4f4703: e8e8d3f9ff CALL 0x491af0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00491af0u,5195528u); flags=s.arithmetic_flags;
  }
  L004f4708: { // 0x4f4708: 8b8e88030000 MOV ECX, dword ptr [ESI + 0x388]
    s.cx = m.r32((s.si+0x00000388u));
  }
  L004f470e: { // 0x4f470e: 03c3 ADD EAX, EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L004f4710: { // 0x4f4710: 3bc1 CMP EAX, ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L004f4712: { // 0x4f4712: 7c0c JL 0x4f4720
    if(integer::condition("JL",flags)) goto L004f4720;
  }
  L004f4714: { // 0x4f4714: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004f4715: { // 0x4f4715: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004f4716: { // 0x4f4716: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004f4717: { // 0x4f4717: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L004f4719: { // 0x4f4719: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004f471a: { // 0x4f471a: 83c408 ADD ESP, 8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  L004f471d: { // 0x4f471d: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004f4720: { // 0x4f4720: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004f4721: { // 0x4f4721: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004f4722: { // 0x4f4722: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004f4723: { // 0x4f4723: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004f4725: { // 0x4f4725: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004f4726: { // 0x4f4726: 83c408 ADD ESP, 8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  L004f4729: { // 0x4f4729: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 0x4f4430u:f_000f4430(m,s,child,{});break;
case 4581744u:f_0005e970(m,s,child,{});break;
case 4581776u:f_0005e990(m,s,child,{});break;
case 4791024u:f_00091af0(m,s,child,{});break;
case 4954800u:f_000b9ab0(m,s,child,{});break;
case 7039248u:f_002b6910(m,s,child,{});break;
case 4536496u:f_000538b0(m,s,child,{});break;
case 4536464u:f_00053890(m,s,child,{});break;
case 4260432u:f_00010250(m,s,child,{});break;
case 5155440u:f_000eaa70(m,s,child,{});break;
case 4729248u:f_000829a0(m,s,child,{});break;
case 5111856u:f_000e0030(m,s,child,{});break;
case 5601968u:f_00157ab0(m,s,child,{});break;
default:throw std::domain_error("recovery739 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_004f4430(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004f4430: { // 0x4f4430: 83ec08 SUB ESP, 8
    f.sp = integer::sub(f.sp,8u,32,flags);
  }
  L004f4433: { // 0x4f4433: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004f4434: { // 0x4f4434: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004f4435: { // 0x4f4435: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004f4436: { // 0x4f4436: 8b742418 MOV ESI, dword ptr [ESP + 0x18]
    s.si = m.r32((f.sp+0x00000018u));
  }
  L004f443a: { // 0x4f443a: 8be9 MOV EBP, ECX
    s.bp = s.cx;
  }
  L004f443c: { // 0x4f443c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004f443d: { // 0x4f443d: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L004f443f: { // 0x4f443f: 896c2414 MOV dword ptr [ESP + 0x14], EBP
    m.w32((f.sp+0x00000014u), s.bp);
  }
  L004f4443: { // 0x4f4443: 0f84cb020000 JZ 0x4f4714
    if(integer::condition("JZ",flags)) goto L004f4714;
  }
  L004f4449: { // 0x4f4449: 8a86da0a0000 MOV AL, byte ptr [ESI + 0xada]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000adau)));
  }
  L004f444f: { // 0x4f444f: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004f4451: { // 0x4f4451: 33db XOR EBX, EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L004f4453: { // 0x4f4453: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004f4455: { // 0x4f4455: 895c2410 MOV dword ptr [ESP + 0x10], EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
  L004f4459: { // 0x4f4459: 8844241c MOV byte ptr [ESP + 0x1c], AL
    m.w8((f.sp+0x0000001cu), (s.ax & 0xffu));
  }
  L004f445d: { // 0x4f445d: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),5194848u); flags=s.arithmetic_flags;
  }
  L004f4460: { // 0x4f4460: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L004f4461: { // 0x4f4461: 83f827 CMP EAX, 0x27
    (void)integer::sub(s.ax,0x00000027u,32,flags);
  }
  L004f4464: { // 0x4f4464: 0f87c8000000 JA 0x4f4532
    if(integer::condition("JA",flags)) goto L004f4532;
  }
  L004f446a: { // 0x4f446a: 33c9 XOR ECX, ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L004f446c: { // 0x4f446c: 8a8840474f00 MOV CL, byte ptr [EAX + 0x4f4740]
    s.cx = with_al(s.cx, table_4f472c[20+s.ax]);
  }
  L004f4472: { // 0x4f4472: ff248d2c474f00 JMP dword ptr [ECX*4 + 0x4f472c]
    switch((std::uint32_t(table_4f472c[0+4*s.cx])|(std::uint32_t(table_4f472c[0+4*s.cx+1])<<8)|(std::uint32_t(table_4f472c[0+4*s.cx+2])<<16)|(std::uint32_t(table_4f472c[0+4*s.cx+3])<<24))){
    case 0x004f4430u: goto L004f4430;
    case 0x004f4433u: goto L004f4433;
    case 0x004f4434u: goto L004f4434;
    case 0x004f4435u: goto L004f4435;
    case 0x004f4436u: goto L004f4436;
    case 0x004f443au: goto L004f443a;
    case 0x004f443cu: goto L004f443c;
    case 0x004f443du: goto L004f443d;
    case 0x004f443fu: goto L004f443f;
    case 0x004f4443u: goto L004f4443;
    case 0x004f4449u: goto L004f4449;
    case 0x004f444fu: goto L004f444f;
    case 0x004f4451u: goto L004f4451;
    case 0x004f4453u: goto L004f4453;
    case 0x004f4455u: goto L004f4455;
    case 0x004f4459u: goto L004f4459;
    case 0x004f445du: goto L004f445d;
    case 0x004f4460u: goto L004f4460;
    case 0x004f4461u: goto L004f4461;
    case 0x004f4464u: goto L004f4464;
    case 0x004f446au: goto L004f446a;
    case 0x004f446cu: goto L004f446c;
    case 0x004f4472u: goto L004f4472;
    case 0x004f4479u: goto L004f4479;
    case 0x004f447fu: goto L004f447f;
    case 0x004f4481u: goto L004f4481;
    case 0x004f4483u: goto L004f4483;
    case 0x004f4484u: goto L004f4484;
    case 0x004f4486u: goto L004f4486;
    case 0x004f448bu: goto L004f448b;
    case 0x004f448fu: goto L004f448f;
    case 0x004f4491u: goto L004f4491;
    case 0x004f4493u: goto L004f4493;
    case 0x004f4495u: goto L004f4495;
    case 0x004f4498u: goto L004f4498;
    case 0x004f449bu: goto L004f449b;
    case 0x004f449eu: goto L004f449e;
    case 0x004f44a4u: goto L004f44a4;
    case 0x004f44a6u: goto L004f44a6;
    case 0x004f44acu: goto L004f44ac;
    case 0x004f44b3u: goto L004f44b3;
    case 0x004f44b9u: goto L004f44b9;
    case 0x004f44bbu: goto L004f44bb;
    case 0x004f44bdu: goto L004f44bd;
    case 0x004f44bfu: goto L004f44bf;
    case 0x004f44c1u: goto L004f44c1;
    case 0x004f44c4u: goto L004f44c4;
    case 0x004f44c5u: goto L004f44c5;
    case 0x004f44cbu: goto L004f44cb;
    case 0x004f44d0u: goto L004f44d0;
    case 0x004f44d2u: goto L004f44d2;
    case 0x004f44d4u: goto L004f44d4;
    case 0x004f44d5u: goto L004f44d5;
    case 0x004f44d7u: goto L004f44d7;
    case 0x004f44d9u: goto L004f44d9;
    case 0x004f44dbu: goto L004f44db;
    case 0x004f44ddu: goto L004f44dd;
    case 0x004f44e3u: goto L004f44e3;
    case 0x004f44e5u: goto L004f44e5;
    case 0x004f44ebu: goto L004f44eb;
    case 0x004f44edu: goto L004f44ed;
    case 0x004f44efu: goto L004f44ef;
    case 0x004f44f2u: goto L004f44f2;
    case 0x004f44f3u: goto L004f44f3;
    case 0x004f44f9u: goto L004f44f9;
    case 0x004f44feu: goto L004f44fe;
    case 0x004f4502u: goto L004f4502;
    case 0x004f4504u: goto L004f4504;
    case 0x004f4506u: goto L004f4506;
    case 0x004f450cu: goto L004f450c;
    case 0x004f4511u: goto L004f4511;
    case 0x004f4517u: goto L004f4517;
    case 0x004f451cu: goto L004f451c;
    case 0x004f4522u: goto L004f4522;
    case 0x004f4527u: goto L004f4527;
    case 0x004f452du: goto L004f452d;
    case 0x004f4532u: goto L004f4532;
    case 0x004f4534u: goto L004f4534;
    case 0x004f4539u: goto L004f4539;
    case 0x004f453fu: goto L004f453f;
    case 0x004f4541u: goto L004f4541;
    case 0x004f4543u: goto L004f4543;
    case 0x004f4545u: goto L004f4545;
    case 0x004f4547u: goto L004f4547;
    case 0x004f454au: goto L004f454a;
    case 0x004f454bu: goto L004f454b;
    case 0x004f4551u: goto L004f4551;
    case 0x004f4556u: goto L004f4556;
    case 0x004f4558u: goto L004f4558;
    case 0x004f455eu: goto L004f455e;
    case 0x004f455fu: goto L004f455f;
    case 0x004f4561u: goto L004f4561;
    case 0x004f4563u: goto L004f4563;
    case 0x004f4565u: goto L004f4565;
    case 0x004f4567u: goto L004f4567;
    case 0x004f456du: goto L004f456d;
    case 0x004f456fu: goto L004f456f;
    case 0x004f4571u: goto L004f4571;
    case 0x004f4574u: goto L004f4574;
    case 0x004f4575u: goto L004f4575;
    case 0x004f457bu: goto L004f457b;
    case 0x004f4580u: goto L004f4580;
    case 0x004f4584u: goto L004f4584;
    case 0x004f458au: goto L004f458a;
    case 0x004f458cu: goto L004f458c;
    case 0x004f458eu: goto L004f458e;
    case 0x004f4593u: goto L004f4593;
    case 0x004f4595u: goto L004f4595;
    case 0x004f4597u: goto L004f4597;
    case 0x004f4599u: goto L004f4599;
    case 0x004f459eu: goto L004f459e;
    case 0x004f45a1u: goto L004f45a1;
    case 0x004f45a7u: goto L004f45a7;
    case 0x004f45a9u: goto L004f45a9;
    case 0x004f45abu: goto L004f45ab;
    case 0x004f45adu: goto L004f45ad;
    case 0x004f45b0u: goto L004f45b0;
    case 0x004f45b6u: goto L004f45b6;
    case 0x004f45b8u: goto L004f45b8;
    case 0x004f45bcu: goto L004f45bc;
    case 0x004f45c1u: goto L004f45c1;
    case 0x004f45c2u: goto L004f45c2;
    case 0x004f45c4u: goto L004f45c4;
    case 0x004f45c6u: goto L004f45c6;
    case 0x004f45cau: goto L004f45ca;
    case 0x004f45d0u: goto L004f45d0;
    case 0x004f45d2u: goto L004f45d2;
    case 0x004f45d8u: goto L004f45d8;
    case 0x004f45dcu: goto L004f45dc;
    case 0x004f45deu: goto L004f45de;
    case 0x004f45e0u: goto L004f45e0;
    case 0x004f45e5u: goto L004f45e5;
    case 0x004f45ebu: goto L004f45eb;
    case 0x004f45edu: goto L004f45ed;
    case 0x004f45efu: goto L004f45ef;
    case 0x004f45f1u: goto L004f45f1;
    case 0x004f45f3u: goto L004f45f3;
    case 0x004f45f6u: goto L004f45f6;
    case 0x004f45f7u: goto L004f45f7;
    case 0x004f45fdu: goto L004f45fd;
    case 0x004f4602u: goto L004f4602;
    case 0x004f4604u: goto L004f4604;
    case 0x004f4606u: goto L004f4606;
    case 0x004f4607u: goto L004f4607;
    case 0x004f4609u: goto L004f4609;
    case 0x004f460bu: goto L004f460b;
    case 0x004f460du: goto L004f460d;
    case 0x004f460fu: goto L004f460f;
    case 0x004f4615u: goto L004f4615;
    case 0x004f4617u: goto L004f4617;
    case 0x004f461du: goto L004f461d;
    case 0x004f461fu: goto L004f461f;
    case 0x004f4621u: goto L004f4621;
    case 0x004f4624u: goto L004f4624;
    case 0x004f4625u: goto L004f4625;
    case 0x004f462bu: goto L004f462b;
    case 0x004f4630u: goto L004f4630;
    case 0x004f4636u: goto L004f4636;
    case 0x004f4638u: goto L004f4638;
    case 0x004f463au: goto L004f463a;
    case 0x004f463fu: goto L004f463f;
    case 0x004f4641u: goto L004f4641;
    case 0x004f4643u: goto L004f4643;
    case 0x004f4647u: goto L004f4647;
    case 0x004f464du: goto L004f464d;
    case 0x004f464fu: goto L004f464f;
    case 0x004f4655u: goto L004f4655;
    case 0x004f465bu: goto L004f465b;
    case 0x004f465eu: goto L004f465e;
    case 0x004f4660u: goto L004f4660;
    case 0x004f4663u: goto L004f4663;
    case 0x004f4664u: goto L004f4664;
    case 0x004f4666u: goto L004f4666;
    case 0x004f466bu: goto L004f466b;
    case 0x004f466du: goto L004f466d;
    case 0x004f466fu: goto L004f466f;
    case 0x004f4671u: goto L004f4671;
    case 0x004f4676u: goto L004f4676;
    case 0x004f467cu: goto L004f467c;
    case 0x004f467fu: goto L004f467f;
    case 0x004f4681u: goto L004f4681;
    case 0x004f4682u: goto L004f4682;
    case 0x004f4687u: goto L004f4687;
    case 0x004f468bu: goto L004f468b;
    case 0x004f4690u: goto L004f4690;
    case 0x004f4691u: goto L004f4691;
    case 0x004f4697u: goto L004f4697;
    case 0x004f4699u: goto L004f4699;
    case 0x004f469du: goto L004f469d;
    case 0x004f46a1u: goto L004f46a1;
    case 0x004f46a7u: goto L004f46a7;
    case 0x004f46a9u: goto L004f46a9;
    case 0x004f46abu: goto L004f46ab;
    case 0x004f46adu: goto L004f46ad;
    case 0x004f46aeu: goto L004f46ae;
    case 0x004f46afu: goto L004f46af;
    case 0x004f46b0u: goto L004f46b0;
    case 0x004f46b2u: goto L004f46b2;
    case 0x004f46b3u: goto L004f46b3;
    case 0x004f46b6u: goto L004f46b6;
    case 0x004f46b9u: goto L004f46b9;
    case 0x004f46bfu: goto L004f46bf;
    case 0x004f46c1u: goto L004f46c1;
    case 0x004f46c3u: goto L004f46c3;
    case 0x004f46c5u: goto L004f46c5;
    case 0x004f46c7u: goto L004f46c7;
    case 0x004f46cau: goto L004f46ca;
    case 0x004f46cbu: goto L004f46cb;
    case 0x004f46d1u: goto L004f46d1;
    case 0x004f46d6u: goto L004f46d6;
    case 0x004f46d8u: goto L004f46d8;
    case 0x004f46dau: goto L004f46da;
    case 0x004f46dbu: goto L004f46db;
    case 0x004f46ddu: goto L004f46dd;
    case 0x004f46dfu: goto L004f46df;
    case 0x004f46e1u: goto L004f46e1;
    case 0x004f46e3u: goto L004f46e3;
    case 0x004f46e5u: goto L004f46e5;
    case 0x004f46e6u: goto L004f46e6;
    case 0x004f46e7u: goto L004f46e7;
    case 0x004f46e8u: goto L004f46e8;
    case 0x004f46eau: goto L004f46ea;
    case 0x004f46ebu: goto L004f46eb;
    case 0x004f46eeu: goto L004f46ee;
    case 0x004f46f1u: goto L004f46f1;
    case 0x004f46f3u: goto L004f46f3;
    case 0x004f46f5u: goto L004f46f5;
    case 0x004f46f7u: goto L004f46f7;
    case 0x004f46f9u: goto L004f46f9;
    case 0x004f46fcu: goto L004f46fc;
    case 0x004f46fdu: goto L004f46fd;
    case 0x004f4703u: goto L004f4703;
    case 0x004f4708u: goto L004f4708;
    case 0x004f470eu: goto L004f470e;
    case 0x004f4710u: goto L004f4710;
    case 0x004f4712u: goto L004f4712;
    case 0x004f4714u: goto L004f4714;
    case 0x004f4715u: goto L004f4715;
    case 0x004f4716u: goto L004f4716;
    case 0x004f4717u: goto L004f4717;
    case 0x004f4719u: goto L004f4719;
    case 0x004f471au: goto L004f471a;
    case 0x004f471du: goto L004f471d;
    case 0x004f4720u: goto L004f4720;
    case 0x004f4721u: goto L004f4721;
    case 0x004f4722u: goto L004f4722;
    case 0x004f4723u: goto L004f4723;
    case 0x004f4725u: goto L004f4725;
    case 0x004f4726u: goto L004f4726;
    case 0x004f4729u: goto L004f4729;
    default:throw std::domain_error("recovery739 unsupported switch destination");}
  }
  L004f4479: { // 0x4f4479: 8bbddc520000 MOV EDI, dword ptr [EBP + 0x52dc]
    s.di = m.r32((s.bp+0x000052dcu));
  }
  L004f447f: { // 0x4f447f: 85ff TEST EDI, EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L004f4481: { // 0x4f4481: 740e JZ 0x4f4491
    if(integer::condition("JZ",flags)) goto L004f4491;
  }
  L004f4483: { // 0x4f4483: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004f4484: { // 0x4f4484: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L004f4486: { // 0x4f4486: e82556fcff CALL 0x4b9ab0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004b9ab0u,5194891u); flags=s.arithmetic_flags;
  }
  L004f448b: { // 0x4f448b: 89442410 MOV dword ptr [ESP + 0x10], EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L004f448f: { // 0x4f448f: 8bd8 MOV EBX, EAX
    s.bx = s.ax;
  }
  L004f4491: { // 0x4f4491: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004f4493: { // 0x4f4493: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004f4495: { // 0x4f4495: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),5194904u); flags=s.arithmetic_flags;
  }
  L004f4498: { // 0x4f4498: 83c0fd ADD EAX, -3
    s.ax = integer::add(s.ax,4294967293u,32,flags);
  }
  L004f449b: { // 0x4f449b: 83f825 CMP EAX, 0x25
    (void)integer::sub(s.ax,0x00000025u,32,flags);
  }
  L004f449e: { // 0x4f449e: 0f877c020000 JA 0x4f4720
    if(integer::condition("JA",flags)) goto L004f4720;
  }
  L004f44a4: { // 0x4f44a4: 33c9 XOR ECX, ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L004f44a6: { // 0x4f44a6: 8a887c474f00 MOV CL, byte ptr [EAX + 0x4f477c]
    s.cx = with_al(s.cx, table_4f472c[80+s.ax]);
  }
  L004f44ac: { // 0x4f44ac: ff248d68474f00 JMP dword ptr [ECX*4 + 0x4f4768]
    switch((std::uint32_t(table_4f472c[60+4*s.cx])|(std::uint32_t(table_4f472c[60+4*s.cx+1])<<8)|(std::uint32_t(table_4f472c[60+4*s.cx+2])<<16)|(std::uint32_t(table_4f472c[60+4*s.cx+3])<<24))){
    case 0x004f4430u: goto L004f4430;
    case 0x004f4433u: goto L004f4433;
    case 0x004f4434u: goto L004f4434;
    case 0x004f4435u: goto L004f4435;
    case 0x004f4436u: goto L004f4436;
    case 0x004f443au: goto L004f443a;
    case 0x004f443cu: goto L004f443c;
    case 0x004f443du: goto L004f443d;
    case 0x004f443fu: goto L004f443f;
    case 0x004f4443u: goto L004f4443;
    case 0x004f4449u: goto L004f4449;
    case 0x004f444fu: goto L004f444f;
    case 0x004f4451u: goto L004f4451;
    case 0x004f4453u: goto L004f4453;
    case 0x004f4455u: goto L004f4455;
    case 0x004f4459u: goto L004f4459;
    case 0x004f445du: goto L004f445d;
    case 0x004f4460u: goto L004f4460;
    case 0x004f4461u: goto L004f4461;
    case 0x004f4464u: goto L004f4464;
    case 0x004f446au: goto L004f446a;
    case 0x004f446cu: goto L004f446c;
    case 0x004f4472u: goto L004f4472;
    case 0x004f4479u: goto L004f4479;
    case 0x004f447fu: goto L004f447f;
    case 0x004f4481u: goto L004f4481;
    case 0x004f4483u: goto L004f4483;
    case 0x004f4484u: goto L004f4484;
    case 0x004f4486u: goto L004f4486;
    case 0x004f448bu: goto L004f448b;
    case 0x004f448fu: goto L004f448f;
    case 0x004f4491u: goto L004f4491;
    case 0x004f4493u: goto L004f4493;
    case 0x004f4495u: goto L004f4495;
    case 0x004f4498u: goto L004f4498;
    case 0x004f449bu: goto L004f449b;
    case 0x004f449eu: goto L004f449e;
    case 0x004f44a4u: goto L004f44a4;
    case 0x004f44a6u: goto L004f44a6;
    case 0x004f44acu: goto L004f44ac;
    case 0x004f44b3u: goto L004f44b3;
    case 0x004f44b9u: goto L004f44b9;
    case 0x004f44bbu: goto L004f44bb;
    case 0x004f44bdu: goto L004f44bd;
    case 0x004f44bfu: goto L004f44bf;
    case 0x004f44c1u: goto L004f44c1;
    case 0x004f44c4u: goto L004f44c4;
    case 0x004f44c5u: goto L004f44c5;
    case 0x004f44cbu: goto L004f44cb;
    case 0x004f44d0u: goto L004f44d0;
    case 0x004f44d2u: goto L004f44d2;
    case 0x004f44d4u: goto L004f44d4;
    case 0x004f44d5u: goto L004f44d5;
    case 0x004f44d7u: goto L004f44d7;
    case 0x004f44d9u: goto L004f44d9;
    case 0x004f44dbu: goto L004f44db;
    case 0x004f44ddu: goto L004f44dd;
    case 0x004f44e3u: goto L004f44e3;
    case 0x004f44e5u: goto L004f44e5;
    case 0x004f44ebu: goto L004f44eb;
    case 0x004f44edu: goto L004f44ed;
    case 0x004f44efu: goto L004f44ef;
    case 0x004f44f2u: goto L004f44f2;
    case 0x004f44f3u: goto L004f44f3;
    case 0x004f44f9u: goto L004f44f9;
    case 0x004f44feu: goto L004f44fe;
    case 0x004f4502u: goto L004f4502;
    case 0x004f4504u: goto L004f4504;
    case 0x004f4506u: goto L004f4506;
    case 0x004f450cu: goto L004f450c;
    case 0x004f4511u: goto L004f4511;
    case 0x004f4517u: goto L004f4517;
    case 0x004f451cu: goto L004f451c;
    case 0x004f4522u: goto L004f4522;
    case 0x004f4527u: goto L004f4527;
    case 0x004f452du: goto L004f452d;
    case 0x004f4532u: goto L004f4532;
    case 0x004f4534u: goto L004f4534;
    case 0x004f4539u: goto L004f4539;
    case 0x004f453fu: goto L004f453f;
    case 0x004f4541u: goto L004f4541;
    case 0x004f4543u: goto L004f4543;
    case 0x004f4545u: goto L004f4545;
    case 0x004f4547u: goto L004f4547;
    case 0x004f454au: goto L004f454a;
    case 0x004f454bu: goto L004f454b;
    case 0x004f4551u: goto L004f4551;
    case 0x004f4556u: goto L004f4556;
    case 0x004f4558u: goto L004f4558;
    case 0x004f455eu: goto L004f455e;
    case 0x004f455fu: goto L004f455f;
    case 0x004f4561u: goto L004f4561;
    case 0x004f4563u: goto L004f4563;
    case 0x004f4565u: goto L004f4565;
    case 0x004f4567u: goto L004f4567;
    case 0x004f456du: goto L004f456d;
    case 0x004f456fu: goto L004f456f;
    case 0x004f4571u: goto L004f4571;
    case 0x004f4574u: goto L004f4574;
    case 0x004f4575u: goto L004f4575;
    case 0x004f457bu: goto L004f457b;
    case 0x004f4580u: goto L004f4580;
    case 0x004f4584u: goto L004f4584;
    case 0x004f458au: goto L004f458a;
    case 0x004f458cu: goto L004f458c;
    case 0x004f458eu: goto L004f458e;
    case 0x004f4593u: goto L004f4593;
    case 0x004f4595u: goto L004f4595;
    case 0x004f4597u: goto L004f4597;
    case 0x004f4599u: goto L004f4599;
    case 0x004f459eu: goto L004f459e;
    case 0x004f45a1u: goto L004f45a1;
    case 0x004f45a7u: goto L004f45a7;
    case 0x004f45a9u: goto L004f45a9;
    case 0x004f45abu: goto L004f45ab;
    case 0x004f45adu: goto L004f45ad;
    case 0x004f45b0u: goto L004f45b0;
    case 0x004f45b6u: goto L004f45b6;
    case 0x004f45b8u: goto L004f45b8;
    case 0x004f45bcu: goto L004f45bc;
    case 0x004f45c1u: goto L004f45c1;
    case 0x004f45c2u: goto L004f45c2;
    case 0x004f45c4u: goto L004f45c4;
    case 0x004f45c6u: goto L004f45c6;
    case 0x004f45cau: goto L004f45ca;
    case 0x004f45d0u: goto L004f45d0;
    case 0x004f45d2u: goto L004f45d2;
    case 0x004f45d8u: goto L004f45d8;
    case 0x004f45dcu: goto L004f45dc;
    case 0x004f45deu: goto L004f45de;
    case 0x004f45e0u: goto L004f45e0;
    case 0x004f45e5u: goto L004f45e5;
    case 0x004f45ebu: goto L004f45eb;
    case 0x004f45edu: goto L004f45ed;
    case 0x004f45efu: goto L004f45ef;
    case 0x004f45f1u: goto L004f45f1;
    case 0x004f45f3u: goto L004f45f3;
    case 0x004f45f6u: goto L004f45f6;
    case 0x004f45f7u: goto L004f45f7;
    case 0x004f45fdu: goto L004f45fd;
    case 0x004f4602u: goto L004f4602;
    case 0x004f4604u: goto L004f4604;
    case 0x004f4606u: goto L004f4606;
    case 0x004f4607u: goto L004f4607;
    case 0x004f4609u: goto L004f4609;
    case 0x004f460bu: goto L004f460b;
    case 0x004f460du: goto L004f460d;
    case 0x004f460fu: goto L004f460f;
    case 0x004f4615u: goto L004f4615;
    case 0x004f4617u: goto L004f4617;
    case 0x004f461du: goto L004f461d;
    case 0x004f461fu: goto L004f461f;
    case 0x004f4621u: goto L004f4621;
    case 0x004f4624u: goto L004f4624;
    case 0x004f4625u: goto L004f4625;
    case 0x004f462bu: goto L004f462b;
    case 0x004f4630u: goto L004f4630;
    case 0x004f4636u: goto L004f4636;
    case 0x004f4638u: goto L004f4638;
    case 0x004f463au: goto L004f463a;
    case 0x004f463fu: goto L004f463f;
    case 0x004f4641u: goto L004f4641;
    case 0x004f4643u: goto L004f4643;
    case 0x004f4647u: goto L004f4647;
    case 0x004f464du: goto L004f464d;
    case 0x004f464fu: goto L004f464f;
    case 0x004f4655u: goto L004f4655;
    case 0x004f465bu: goto L004f465b;
    case 0x004f465eu: goto L004f465e;
    case 0x004f4660u: goto L004f4660;
    case 0x004f4663u: goto L004f4663;
    case 0x004f4664u: goto L004f4664;
    case 0x004f4666u: goto L004f4666;
    case 0x004f466bu: goto L004f466b;
    case 0x004f466du: goto L004f466d;
    case 0x004f466fu: goto L004f466f;
    case 0x004f4671u: goto L004f4671;
    case 0x004f4676u: goto L004f4676;
    case 0x004f467cu: goto L004f467c;
    case 0x004f467fu: goto L004f467f;
    case 0x004f4681u: goto L004f4681;
    case 0x004f4682u: goto L004f4682;
    case 0x004f4687u: goto L004f4687;
    case 0x004f468bu: goto L004f468b;
    case 0x004f4690u: goto L004f4690;
    case 0x004f4691u: goto L004f4691;
    case 0x004f4697u: goto L004f4697;
    case 0x004f4699u: goto L004f4699;
    case 0x004f469du: goto L004f469d;
    case 0x004f46a1u: goto L004f46a1;
    case 0x004f46a7u: goto L004f46a7;
    case 0x004f46a9u: goto L004f46a9;
    case 0x004f46abu: goto L004f46ab;
    case 0x004f46adu: goto L004f46ad;
    case 0x004f46aeu: goto L004f46ae;
    case 0x004f46afu: goto L004f46af;
    case 0x004f46b0u: goto L004f46b0;
    case 0x004f46b2u: goto L004f46b2;
    case 0x004f46b3u: goto L004f46b3;
    case 0x004f46b6u: goto L004f46b6;
    case 0x004f46b9u: goto L004f46b9;
    case 0x004f46bfu: goto L004f46bf;
    case 0x004f46c1u: goto L004f46c1;
    case 0x004f46c3u: goto L004f46c3;
    case 0x004f46c5u: goto L004f46c5;
    case 0x004f46c7u: goto L004f46c7;
    case 0x004f46cau: goto L004f46ca;
    case 0x004f46cbu: goto L004f46cb;
    case 0x004f46d1u: goto L004f46d1;
    case 0x004f46d6u: goto L004f46d6;
    case 0x004f46d8u: goto L004f46d8;
    case 0x004f46dau: goto L004f46da;
    case 0x004f46dbu: goto L004f46db;
    case 0x004f46ddu: goto L004f46dd;
    case 0x004f46dfu: goto L004f46df;
    case 0x004f46e1u: goto L004f46e1;
    case 0x004f46e3u: goto L004f46e3;
    case 0x004f46e5u: goto L004f46e5;
    case 0x004f46e6u: goto L004f46e6;
    case 0x004f46e7u: goto L004f46e7;
    case 0x004f46e8u: goto L004f46e8;
    case 0x004f46eau: goto L004f46ea;
    case 0x004f46ebu: goto L004f46eb;
    case 0x004f46eeu: goto L004f46ee;
    case 0x004f46f1u: goto L004f46f1;
    case 0x004f46f3u: goto L004f46f3;
    case 0x004f46f5u: goto L004f46f5;
    case 0x004f46f7u: goto L004f46f7;
    case 0x004f46f9u: goto L004f46f9;
    case 0x004f46fcu: goto L004f46fc;
    case 0x004f46fdu: goto L004f46fd;
    case 0x004f4703u: goto L004f4703;
    case 0x004f4708u: goto L004f4708;
    case 0x004f470eu: goto L004f470e;
    case 0x004f4710u: goto L004f4710;
    case 0x004f4712u: goto L004f4712;
    case 0x004f4714u: goto L004f4714;
    case 0x004f4715u: goto L004f4715;
    case 0x004f4716u: goto L004f4716;
    case 0x004f4717u: goto L004f4717;
    case 0x004f4719u: goto L004f4719;
    case 0x004f471au: goto L004f471a;
    case 0x004f471du: goto L004f471d;
    case 0x004f4720u: goto L004f4720;
    case 0x004f4721u: goto L004f4721;
    case 0x004f4722u: goto L004f4722;
    case 0x004f4723u: goto L004f4723;
    case 0x004f4725u: goto L004f4725;
    case 0x004f4726u: goto L004f4726;
    case 0x004f4729u: goto L004f4729;
    default:throw std::domain_error("recovery739 unsupported switch destination");}
  }
  L004f44b3: { // 0x4f44b3: 8bbe88030000 MOV EDI, dword ptr [ESI + 0x388]
    s.di = m.r32((s.si+0x00000388u));
  }
  L004f44b9: { // 0x4f44b9: 85ff TEST EDI, EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L004f44bb: { // 0x4f44bb: 7f2e JG 0x4f44eb
    if(integer::condition("JG",flags)) goto L004f44eb;
  }
  L004f44bd: { // 0x4f44bd: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004f44bf: { // 0x4f44bf: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004f44c1: { // 0x4f44c1: ff5240 CALL dword ptr [EDX + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000040u)),5194948u); flags=s.arithmetic_flags;
  }
  L004f44c4: { // 0x4f44c4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004f44c5: { // 0x4f44c5: 8d8db0540000 LEA ECX, [EBP + 0x54b0]
    s.cx = (s.bp+0x000054b0u);
  }
  L004f44cb: { // 0x4f44cb: e820d6f9ff CALL 0x491af0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00491af0u,5194960u); flags=s.arithmetic_flags;
  }
  L004f44d0: { // 0x4f44d0: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L004f44d2: { // 0x4f44d2: 8bc7 MOV EAX, EDI
    s.ax = s.di;
  }
  L004f44d4: { // 0x4f44d4: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004f44d5: { // 0x4f44d5: 33c2 XOR EAX, EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L004f44d7: { // 0x4f44d7: 03cb ADD ECX, EBX
    s.cx = integer::add(s.cx,s.bx,32,flags);
  }
  L004f44d9: { // 0x4f44d9: 2bc2 SUB EAX, EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004f44db: { // 0x4f44db: 3bc8 CMP ECX, EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L004f44dd: { // 0x4f44dd: 0f8d31020000 JGE 0x4f4714
    if(integer::condition("JGE",flags)) goto L004f4714;
  }
  L004f44e3: { // 0x4f44e3: 85ff TEST EDI, EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L004f44e5: { // 0x4f44e5: 0f8e35020000 JLE 0x4f4720
    if(integer::condition("JLE",flags)) goto L004f4720;
  }
  L004f44eb: { // 0x4f44eb: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004f44ed: { // 0x4f44ed: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004f44ef: { // 0x4f44ef: ff5240 CALL dword ptr [EDX + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000040u)),5194994u); flags=s.arithmetic_flags;
  }
  L004f44f2: { // 0x4f44f2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004f44f3: { // 0x4f44f3: 8d8d30540000 LEA ECX, [EBP + 0x5430]
    s.cx = (s.bp+0x00005430u);
  }
  L004f44f9: { // 0x4f44f9: e905020000 JMP 0x4f4703
    goto L004f4703;
  }
  L004f44fe: { // 0x4f44fe: 8a44241c MOV AL, byte ptr [ESP + 0x1c]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000001cu)));
  }
  L004f4502: { // 0x4f4502: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004f4504: { // 0x4f4504: 740b JZ 0x4f4511
    if(integer::condition("JZ",flags)) goto L004f4511;
  }
  L004f4506: { // 0x4f4506: 8bbde4520000 MOV EDI, dword ptr [EBP + 0x52e4]
    s.di = m.r32((s.bp+0x000052e4u));
  }
  L004f450c: { // 0x4f450c: e96effffff JMP 0x4f447f
    goto L004f447f;
  }
  L004f4511: { // 0x4f4511: 8bbde0520000 MOV EDI, dword ptr [EBP + 0x52e0]
    s.di = m.r32((s.bp+0x000052e0u));
  }
  L004f4517: { // 0x4f4517: e963ffffff JMP 0x4f447f
    goto L004f447f;
  }
  L004f451c: { // 0x4f451c: 8bbde8520000 MOV EDI, dword ptr [EBP + 0x52e8]
    s.di = m.r32((s.bp+0x000052e8u));
  }
  L004f4522: { // 0x4f4522: e958ffffff JMP 0x4f447f
    goto L004f447f;
  }
  L004f4527: { // 0x4f4527: 8bbdd8520000 MOV EDI, dword ptr [EBP + 0x52d8]
    s.di = m.r32((s.bp+0x000052d8u));
  }
  L004f452d: { // 0x4f452d: e94dffffff JMP 0x4f447f
    goto L004f447f;
  }
  L004f4532: { // 0x4f4532: 33ff XOR EDI, EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L004f4534: { // 0x4f4534: e958ffffff JMP 0x4f4491
    goto L004f4491;
  }
  L004f4539: { // 0x4f4539: 8b8688030000 MOV EAX, dword ptr [ESI + 0x388]
    s.ax = m.r32((s.si+0x00000388u));
  }
  L004f453f: { // 0x4f453f: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004f4541: { // 0x4f4541: 7f2a JG 0x4f456d
    if(integer::condition("JG",flags)) goto L004f456d;
  }
  L004f4543: { // 0x4f4543: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004f4545: { // 0x4f4545: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004f4547: { // 0x4f4547: ff5040 CALL dword ptr [EAX + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000040u)),5195082u); flags=s.arithmetic_flags;
  }
  L004f454a: { // 0x4f454a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004f454b: { // 0x4f454b: 8d8dc0540000 LEA ECX, [EBP + 0x54c0]
    s.cx = (s.bp+0x000054c0u);
  }
  L004f4551: { // 0x4f4551: e89ad5f9ff CALL 0x491af0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00491af0u,5195094u); flags=s.arithmetic_flags;
  }
  L004f4556: { // 0x4f4556: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L004f4558: { // 0x4f4558: 8b8688030000 MOV EAX, dword ptr [ESI + 0x388]
    s.ax = m.r32((s.si+0x00000388u));
  }
  L004f455e: { // 0x4f455e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004f455f: { // 0x4f455f: 33c2 XOR EAX, EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L004f4561: { // 0x4f4561: 03cb ADD ECX, EBX
    s.cx = integer::add(s.cx,s.bx,32,flags);
  }
  L004f4563: { // 0x4f4563: 2bc2 SUB EAX, EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004f4565: { // 0x4f4565: 3bc8 CMP ECX, EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L004f4567: { // 0x4f4567: 0f8da7010000 JGE 0x4f4714
    if(integer::condition("JGE",flags)) goto L004f4714;
  }
  L004f456d: { // 0x4f456d: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004f456f: { // 0x4f456f: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004f4571: { // 0x4f4571: ff5240 CALL dword ptr [EDX + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000040u)),5195124u); flags=s.arithmetic_flags;
  }
  L004f4574: { // 0x4f4574: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004f4575: { // 0x4f4575: 8d8d40540000 LEA ECX, [EBP + 0x5440]
    s.cx = (s.bp+0x00005440u);
  }
  L004f457b: { // 0x4f457b: e870d5f9ff CALL 0x491af0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00491af0u,5195136u); flags=s.arithmetic_flags;
  }
  L004f4580: { // 0x4f4580: 8944241c MOV dword ptr [ESP + 0x1c], EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L004f4584: { // 0x4f4584: 8a86140c0000 MOV AL, byte ptr [ESI + 0xc14]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000c14u)));
  }
  L004f458a: { // 0x4f458a: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004f458c: { // 0x4f458c: 743c JZ 0x4f45ca
    if(integer::condition("JZ",flags)) goto L004f45ca;
  }
  L004f458e: { // 0x4f458e: a1d8e48400 MOV EAX, dword ptr [0x84e4d8]
    s.ax = m.r32((0x0084e4d8u));
  }
  L004f4593: { // 0x4f4593: 33db XOR EBX, EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L004f4595: { // 0x4f4595: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004f4597: { // 0x4f4597: 7e2d JLE 0x4f45c6
    if(integer::condition("JLE",flags)) goto L004f45c6;
  }
  L004f4599: { // 0x4f4599: a1cce48400 MOV EAX, dword ptr [0x84e4cc]
    s.ax = m.r32((0x0084e4ccu));
  }
  L004f459e: { // 0x4f459e: 8b3c98 MOV EDI, dword ptr [EAX + EBX*4]
    s.di = m.r32((s.ax+(s.bx * 4u)));
  }
  L004f45a1: { // 0x4f45a1: 39afb4010000 CMP dword ptr [EDI + 0x1b4], EBP
    (void)integer::sub(m.r32((s.di+0x000001b4u)),s.bp,32,flags);
  }
  L004f45a7: { // 0x4f45a7: 7513 JNZ 0x4f45bc
    if(integer::condition("JNZ",flags)) goto L004f45bc;
  }
  L004f45a9: { // 0x4f45a9: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004f45ab: { // 0x4f45ab: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004f45ad: { // 0x4f45ad: ff5240 CALL dword ptr [EDX + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000040u)),5195184u); flags=s.arithmetic_flags;
  }
  L004f45b0: { // 0x4f45b0: 398790020000 CMP dword ptr [EDI + 0x290], EAX
    (void)integer::sub(m.r32((s.di+0x00000290u)),s.ax,32,flags);
  }
  L004f45b6: { // 0x4f45b6: 7504 JNZ 0x4f45bc
    if(integer::condition("JNZ",flags)) goto L004f45bc;
  }
  L004f45b8: { // 0x4f45b8: ff44241c INC dword ptr [ESP + 0x1c]
    m.w32((f.sp+0x0000001cu), integer::increment(m.r32((f.sp+0x0000001cu)),32,flags));
  }
  L004f45bc: { // 0x4f45bc: a1d8e48400 MOV EAX, dword ptr [0x84e4d8]
    s.ax = m.r32((0x0084e4d8u));
  }
  L004f45c1: { // 0x4f45c1: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L004f45c2: { // 0x4f45c2: 3bd8 CMP EBX, EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L004f45c4: { // 0x4f45c4: 7cd3 JL 0x4f4599
    if(integer::condition("JL",flags)) goto L004f4599;
  }
  L004f45c6: { // 0x4f45c6: 8b5c2410 MOV EBX, dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L004f45ca: { // 0x4f45ca: 8bb688030000 MOV ESI, dword ptr [ESI + 0x388]
    s.si = m.r32((s.si+0x00000388u));
  }
  L004f45d0: { // 0x4f45d0: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L004f45d2: { // 0x4f45d2: 0f8e48010000 JLE 0x4f4720
    if(integer::condition("JLE",flags)) goto L004f4720;
  }
  L004f45d8: { // 0x4f45d8: 8b44241c MOV EAX, dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L004f45dc: { // 0x4f45dc: 03c3 ADD EAX, EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L004f45de: { // 0x4f45de: 3bc6 CMP EAX, ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L004f45e0: { // 0x4f45e0: e92d010000 JMP 0x4f4712
    goto L004f4712;
  }
  L004f45e5: { // 0x4f45e5: 8bbe88030000 MOV EDI, dword ptr [ESI + 0x388]
    s.di = m.r32((s.si+0x00000388u));
  }
  L004f45eb: { // 0x4f45eb: 85ff TEST EDI, EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L004f45ed: { // 0x4f45ed: 7f2e JG 0x4f461d
    if(integer::condition("JG",flags)) goto L004f461d;
  }
  L004f45ef: { // 0x4f45ef: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004f45f1: { // 0x4f45f1: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004f45f3: { // 0x4f45f3: ff5240 CALL dword ptr [EDX + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000040u)),5195254u); flags=s.arithmetic_flags;
  }
  L004f45f6: { // 0x4f45f6: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004f45f7: { // 0x4f45f7: 8d8da0540000 LEA ECX, [EBP + 0x54a0]
    s.cx = (s.bp+0x000054a0u);
  }
  L004f45fd: { // 0x4f45fd: e8eed4f9ff CALL 0x491af0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00491af0u,5195266u); flags=s.arithmetic_flags;
  }
  L004f4602: { // 0x4f4602: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L004f4604: { // 0x4f4604: 8bc7 MOV EAX, EDI
    s.ax = s.di;
  }
  L004f4606: { // 0x4f4606: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004f4607: { // 0x4f4607: 33c2 XOR EAX, EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L004f4609: { // 0x4f4609: 03cb ADD ECX, EBX
    s.cx = integer::add(s.cx,s.bx,32,flags);
  }
  L004f460b: { // 0x4f460b: 2bc2 SUB EAX, EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004f460d: { // 0x4f460d: 3bc8 CMP ECX, EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L004f460f: { // 0x4f460f: 0f8dff000000 JGE 0x4f4714
    if(integer::condition("JGE",flags)) goto L004f4714;
  }
  L004f4615: { // 0x4f4615: 85ff TEST EDI, EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L004f4617: { // 0x4f4617: 0f8e03010000 JLE 0x4f4720
    if(integer::condition("JLE",flags)) goto L004f4720;
  }
  L004f461d: { // 0x4f461d: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004f461f: { // 0x4f461f: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004f4621: { // 0x4f4621: ff5240 CALL dword ptr [EDX + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000040u)),5195300u); flags=s.arithmetic_flags;
  }
  L004f4624: { // 0x4f4624: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004f4625: { // 0x4f4625: 8d8d20540000 LEA ECX, [EBP + 0x5420]
    s.cx = (s.bp+0x00005420u);
  }
  L004f462b: { // 0x4f462b: e9d3000000 JMP 0x4f4703
    goto L004f4703;
  }
  L004f4630: { // 0x4f4630: 8a86a30b0000 MOV AL, byte ptr [ESI + 0xba3]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000ba3u)));
  }
  L004f4636: { // 0x4f4636: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004f4638: { // 0x4f4638: 747f JZ 0x4f46b9
    if(integer::condition("JZ",flags)) goto L004f46b9;
  }
  L004f463a: { // 0x4f463a: a1881b8200 MOV EAX, dword ptr [0x821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L004f463f: { // 0x4f463f: 33f6 XOR ESI, ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L004f4641: { // 0x4f4641: 33db XOR EBX, EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L004f4643: { // 0x4f4643: 8974241c MOV dword ptr [ESP + 0x1c], ESI
    m.w32((f.sp+0x0000001cu), s.si);
  }
  L004f4647: { // 0x4f4647: 39b0180a0000 CMP dword ptr [EAX + 0xa18], ESI
    (void)integer::sub(m.r32((s.ax+0x00000a18u)),s.si,32,flags);
  }
  L004f464d: { // 0x4f464d: 7e4e JLE 0x4f469d
    if(integer::condition("JLE",flags)) goto L004f469d;
  }
  L004f464f: { // 0x4f464f: 81c590540000 ADD EBP, 0x5490
    s.bp = integer::add(s.bp,0x00005490u,32,flags);
  }
  L004f4655: { // 0x4f4655: 8b800c0a0000 MOV EAX, dword ptr [EAX + 0xa0c]
    s.ax = m.r32((s.ax+0x00000a0cu));
  }
  L004f465b: { // 0x4f465b: 8b0cb0 MOV ECX, dword ptr [EAX + ESI*4]
    s.cx = m.r32((s.ax+(s.si * 4u)));
  }
  L004f465e: { // 0x4f465e: 8b11 MOV EDX, dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L004f4660: { // 0x4f4660: ff5240 CALL dword ptr [EDX + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000040u)),5195363u); flags=s.arithmetic_flags;
  }
  L004f4663: { // 0x4f4663: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004f4664: { // 0x4f4664: 8bcd MOV ECX, EBP
    s.cx = s.bp;
  }
  L004f4666: { // 0x4f4666: e885d4f9ff CALL 0x491af0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00491af0u,5195371u); flags=s.arithmetic_flags;
  }
  L004f466b: { // 0x4f466b: 03d8 ADD EBX, EAX
    s.bx = integer::add(s.bx,s.ax,32,flags);
  }
  L004f466d: { // 0x4f466d: 85ff TEST EDI, EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L004f466f: { // 0x4f466f: 741a JZ 0x4f468b
    if(integer::condition("JZ",flags)) goto L004f468b;
  }
  L004f4671: { // 0x4f4671: a1881b8200 MOV EAX, dword ptr [0x821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L004f4676: { // 0x4f4676: 8b880c0a0000 MOV ECX, dword ptr [EAX + 0xa0c]
    s.cx = m.r32((s.ax+0x00000a0cu));
  }
  L004f467c: { // 0x4f467c: 8b14b1 MOV EDX, dword ptr [ECX + ESI*4]
    s.dx = m.r32((s.cx+(s.si * 4u)));
  }
  L004f467f: { // 0x4f467f: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L004f4681: { // 0x4f4681: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004f4682: { // 0x4f4682: e82954fcff CALL 0x4b9ab0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004b9ab0u,5195399u); flags=s.arithmetic_flags;
  }
  L004f4687: { // 0x4f4687: 0144241c ADD dword ptr [ESP + 0x1c], EAX
    m.w32((f.sp+0x0000001cu), integer::add(m.r32((f.sp+0x0000001cu)),s.ax,32,flags));
  }
  L004f468b: { // 0x4f468b: a1881b8200 MOV EAX, dword ptr [0x821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L004f4690: { // 0x4f4690: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L004f4691: { // 0x4f4691: 3bb0180a0000 CMP ESI, dword ptr [EAX + 0xa18]
    (void)integer::sub(s.si,m.r32((s.ax+0x00000a18u)),32,flags);
  }
  L004f4697: { // 0x4f4697: 7cbc JL 0x4f4655
    if(integer::condition("JL",flags)) goto L004f4655;
  }
  L004f4699: { // 0x4f4699: 8b6c2414 MOV EBP, dword ptr [ESP + 0x14]
    s.bp = m.r32((f.sp+0x00000014u));
  }
  L004f469d: { // 0x4f469d: 8b44241c MOV EAX, dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L004f46a1: { // 0x4f46a1: 8b8d18020000 MOV ECX, dword ptr [EBP + 0x218]
    s.cx = m.r32((s.bp+0x00000218u));
  }
  L004f46a7: { // 0x4f46a7: 03c3 ADD EAX, EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L004f46a9: { // 0x4f46a9: 3bc1 CMP EAX, ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L004f46ab: { // 0x4f46ab: 7c73 JL 0x4f4720
    if(integer::condition("JL",flags)) goto L004f4720;
  }
  L004f46ad: { // 0x4f46ad: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004f46ae: { // 0x4f46ae: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004f46af: { // 0x4f46af: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004f46b0: { // 0x4f46b0: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L004f46b2: { // 0x4f46b2: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004f46b3: { // 0x4f46b3: 83c408 ADD ESP, 8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  L004f46b6: { // 0x4f46b6: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004f46b9: { // 0x4f46b9: 8bbe88030000 MOV EDI, dword ptr [ESI + 0x388]
    s.di = m.r32((s.si+0x00000388u));
  }
  L004f46bf: { // 0x4f46bf: 85ff TEST EDI, EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L004f46c1: { // 0x4f46c1: 7f32 JG 0x4f46f5
    if(integer::condition("JG",flags)) goto L004f46f5;
  }
  L004f46c3: { // 0x4f46c3: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004f46c5: { // 0x4f46c5: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004f46c7: { // 0x4f46c7: ff5240 CALL dword ptr [EDX + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000040u)),5195466u); flags=s.arithmetic_flags;
  }
  L004f46ca: { // 0x4f46ca: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004f46cb: { // 0x4f46cb: 8d8dd0540000 LEA ECX, [EBP + 0x54d0]
    s.cx = (s.bp+0x000054d0u);
  }
  L004f46d1: { // 0x4f46d1: e81ad4f9ff CALL 0x491af0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00491af0u,5195478u); flags=s.arithmetic_flags;
  }
  L004f46d6: { // 0x4f46d6: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L004f46d8: { // 0x4f46d8: 8bc7 MOV EAX, EDI
    s.ax = s.di;
  }
  L004f46da: { // 0x4f46da: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004f46db: { // 0x4f46db: 33c2 XOR EAX, EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L004f46dd: { // 0x4f46dd: 03cb ADD ECX, EBX
    s.cx = integer::add(s.cx,s.bx,32,flags);
  }
  L004f46df: { // 0x4f46df: 2bc2 SUB EAX, EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004f46e1: { // 0x4f46e1: 3bc8 CMP ECX, EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L004f46e3: { // 0x4f46e3: 7c0c JL 0x4f46f1
    if(integer::condition("JL",flags)) goto L004f46f1;
  }
  L004f46e5: { // 0x4f46e5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004f46e6: { // 0x4f46e6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004f46e7: { // 0x4f46e7: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004f46e8: { // 0x4f46e8: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L004f46ea: { // 0x4f46ea: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004f46eb: { // 0x4f46eb: 83c408 ADD ESP, 8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  L004f46ee: { // 0x4f46ee: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004f46f1: { // 0x4f46f1: 85ff TEST EDI, EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L004f46f3: { // 0x4f46f3: 7e2b JLE 0x4f4720
    if(integer::condition("JLE",flags)) goto L004f4720;
  }
  L004f46f5: { // 0x4f46f5: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004f46f7: { // 0x4f46f7: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004f46f9: { // 0x4f46f9: ff5240 CALL dword ptr [EDX + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000040u)),5195516u); flags=s.arithmetic_flags;
  }
  L004f46fc: { // 0x4f46fc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004f46fd: { // 0x4f46fd: 8d8d50540000 LEA ECX, [EBP + 0x5450]
    s.cx = (s.bp+0x00005450u);
  }
  L004f4703: { // 0x4f4703: e8e8d3f9ff CALL 0x491af0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00491af0u,5195528u); flags=s.arithmetic_flags;
  }
  L004f4708: { // 0x4f4708: 8b8e88030000 MOV ECX, dword ptr [ESI + 0x388]
    s.cx = m.r32((s.si+0x00000388u));
  }
  L004f470e: { // 0x4f470e: 03c3 ADD EAX, EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L004f4710: { // 0x4f4710: 3bc1 CMP EAX, ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L004f4712: { // 0x4f4712: 7c0c JL 0x4f4720
    if(integer::condition("JL",flags)) goto L004f4720;
  }
  L004f4714: { // 0x4f4714: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004f4715: { // 0x4f4715: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004f4716: { // 0x4f4716: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004f4717: { // 0x4f4717: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L004f4719: { // 0x4f4719: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004f471a: { // 0x4f471a: 83c408 ADD ESP, 8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  L004f471d: { // 0x4f471d: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004f4720: { // 0x4f4720: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004f4721: { // 0x4f4721: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004f4722: { // 0x4f4722: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004f4723: { // 0x4f4723: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004f4725: { // 0x4f4725: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004f4726: { // 0x4f4726: 83c408 ADD ESP, 8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  L004f4729: { // 0x4f4729: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00671a80(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00671a80: { // 0x671a80: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00671a81: { // 0x671a81: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L00671a83: { // 0x671a83: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00671a84: { // 0x671a84: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00671a85: { // 0x671a85: 8a85e14e0000 MOV AL,byte ptr [EBP + 0x4ee1]
    s.ax = with_al(s.ax, m.r8((s.bp+0x00004ee1u)));
  }
  L00671a8b: { // 0x671a8b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00671a8d: { // 0x671a8d: 0f84fa000000 JZ 0x00671b8d
    if(integer::condition("JZ",flags)) goto L00671b8d;
  }
  L00671a93: { // 0x671a93: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L00671a97: { // 0x671a97: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L00671a99: { // 0x671a99: 0f84ee000000 JZ 0x00671b8d
    if(integer::condition("JZ",flags)) goto L00671b8d;
  }
  L00671a9f: { // 0x671a9f: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L00671aa1: { // 0x671aa1: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00671aa3: { // 0x671aa3: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),6757033u); flags=s.arithmetic_flags;
  }
  L00671aa9: { // 0x671aa9: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00671aad: { // 0x671aad: a1e4e0a100 MOV EAX,[0x00a1e0e4]
    s.ax = m.r32((0x00a1e0e4u));
  }
  L00671ab2: { // 0x671ab2: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00671ab4: { // 0x671ab4: 0f84d3000000 JZ 0x00671b8d
    if(integer::condition("JZ",flags)) goto L00671b8d;
  }
  L00671aba: { // 0x671aba: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L00671abc: { // 0x671abc: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00671abe: { // 0x671abe: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),6757057u); flags=s.arithmetic_flags;
  }
  L00671ac1: { // 0x671ac1: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00671ac3: { // 0x671ac3: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L00671ac5: { // 0x671ac5: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00671ac7: { // 0x671ac7: ff5040 CALL dword ptr [EAX + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000040u)),6757066u); flags=s.arithmetic_flags;
  }
  L00671aca: { // 0x671aca: 83fe0f CMP ESI,0xf
    (void)integer::sub(s.si,0x0000000fu,32,flags);
  }
  L00671acd: { // 0x671acd: 745a JZ 0x00671b29
    if(integer::condition("JZ",flags)) goto L00671b29;
  }
  L00671acf: { // 0x671acf: 83fe10 CMP ESI,0x10
    (void)integer::sub(s.si,0x00000010u,32,flags);
  }
  L00671ad2: { // 0x671ad2: 7455 JZ 0x00671b29
    if(integer::condition("JZ",flags)) goto L00671b29;
  }
  L00671ad4: { // 0x671ad4: 83fe01 CMP ESI,0x1
    (void)integer::sub(s.si,0x00000001u,32,flags);
  }
  L00671ad7: { // 0x671ad7: 7449 JZ 0x00671b22
    if(integer::condition("JZ",flags)) goto L00671b22;
  }
  L00671ad9: { // 0x671ad9: 83fe28 CMP ESI,0x28
    (void)integer::sub(s.si,0x00000028u,32,flags);
  }
  L00671adc: { // 0x671adc: 7444 JZ 0x00671b22
    if(integer::condition("JZ",flags)) goto L00671b22;
  }
  L00671ade: { // 0x671ade: 83fe02 CMP ESI,0x2
    (void)integer::sub(s.si,0x00000002u,32,flags);
  }
  L00671ae1: { // 0x671ae1: 743f JZ 0x00671b22
    if(integer::condition("JZ",flags)) goto L00671b22;
  }
  L00671ae3: { // 0x671ae3: 83fe03 CMP ESI,0x3
    (void)integer::sub(s.si,0x00000003u,32,flags);
  }
  L00671ae6: { // 0x671ae6: 743a JZ 0x00671b22
    if(integer::condition("JZ",flags)) goto L00671b22;
  }
  L00671ae8: { // 0x671ae8: 83fe06 CMP ESI,0x6
    (void)integer::sub(s.si,0x00000006u,32,flags);
  }
  L00671aeb: { // 0x671aeb: 7420 JZ 0x00671b0d
    if(integer::condition("JZ",flags)) goto L00671b0d;
  }
  L00671aed: { // 0x671aed: 83fe07 CMP ESI,0x7
    (void)integer::sub(s.si,0x00000007u,32,flags);
  }
  L00671af0: { // 0x671af0: 741b JZ 0x00671b0d
    if(integer::condition("JZ",flags)) goto L00671b0d;
  }
  L00671af2: { // 0x671af2: 83fe39 CMP ESI,0x39
    (void)integer::sub(s.si,0x00000039u,32,flags);
  }
  L00671af5: { // 0x671af5: 740f JZ 0x00671b06
    if(integer::condition("JZ",flags)) goto L00671b06;
  }
  L00671af7: { // 0x671af7: 83fe20 CMP ESI,0x20
    (void)integer::sub(s.si,0x00000020u,32,flags);
  }
  L00671afa: { // 0x671afa: 740a JZ 0x00671b06
    if(integer::condition("JZ",flags)) goto L00671b06;
  }
  L00671afc: { // 0x671afc: 83fe1f CMP ESI,0x1f
    (void)integer::sub(s.si,0x0000001fu,32,flags);
  }
  L00671aff: { // 0x671aff: 7405 JZ 0x00671b06
    if(integer::condition("JZ",flags)) goto L00671b06;
  }
  L00671b01: { // 0x671b01: 83ceff OR ESI,0xffffffff
    s.si = integer::logical((s.si)|(0xffffffffu),32,flags);
  }
  L00671b04: { // 0x671b04: eb28 JMP 0x00671b2e
    goto L00671b2e;
  }
  L00671b06: { // 0x671b06: be01000000 MOV ESI,0x1
    s.si = 0x00000001u;
  }
  L00671b0b: { // 0x671b0b: eb21 JMP 0x00671b2e
    goto L00671b2e;
  }
  L00671b0d: { // 0x671b0d: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00671b0f: { // 0x671b0f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00671b11: { // 0x671b11: e85a8fe7ff CALL 0x004eaa70
    s.arithmetic_flags=flags; invoke(m,s,f,0x004eaa70u,6757142u); flags=s.arithmetic_flags;
  }
  L00671b16: { // 0x671b16: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00671b18: { // 0x671b18: 83f805 CMP EAX,0x5
    (void)integer::sub(s.ax,0x00000005u,32,flags);
  }
  L00671b1b: { // 0x671b1b: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L00671b1e: { // 0x671b1e: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00671b20: { // 0x671b20: eb0c JMP 0x00671b2e
    goto L00671b2e;
  }
  L00671b22: { // 0x671b22: be03000000 MOV ESI,0x3
    s.si = 0x00000003u;
  }
  L00671b27: { // 0x671b27: eb05 JMP 0x00671b2e
    goto L00671b2e;
  }
  L00671b29: { // 0x671b29: be02000000 MOV ESI,0x2
    s.si = 0x00000002u;
  }
  L00671b2e: { // 0x671b2e: 3bb5d84e0000 CMP ESI,dword ptr [EBP + 0x4ed8]
    (void)integer::sub(s.si,m.r32((s.bp+0x00004ed8u)),32,flags);
  }
  L00671b34: { // 0x671b34: 7557 JNZ 0x00671b8d
    if(integer::condition("JNZ",flags)) goto L00671b8d;
  }
  L00671b36: { // 0x671b36: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00671b3a: { // 0x671b3a: 8b0de4e0a100 MOV ECX,dword ptr [0x00a1e0e4]
    s.cx = m.r32((0x00a1e0e4u));
  }
  L00671b40: { // 0x671b40: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00671b41: { // 0x671b41: e8ea28e8ff CALL 0x004f4430
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f4430u,6757190u); flags=s.arithmetic_flags;
  }
  L00671b46: { // 0x671b46: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00671b48: { // 0x671b48: 7443 JZ 0x00671b8d
    if(integer::condition("JZ",flags)) goto L00671b8d;
  }
  L00671b4a: { // 0x671b4a: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00671b4c: { // 0x671b4c: c685e24e000001 MOV byte ptr [EBP + 0x4ee2],0x1
    m.w8((s.bp+0x00004ee2u), 0x00000001u);
  }
  L00671b53: { // 0x671b53: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L00671b56: { // 0x671b56: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L00671b58: { // 0x671b58: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00671b5a: { // 0x671b5a: 8d04c0 LEA EAX,[EAX + EAX*0x8]
    s.ax = (s.ax+(s.ax * 0x00000008u));
  }
  L00671b5d: { // 0x671b5d: 8d0446 LEA EAX,[ESI + EAX*0x2]
    s.ax = (s.si+(s.ax * 0x00000002u));
  }
  L00671b60: { // 0x671b60: 8d0c40 LEA ECX,[EAX + EAX*0x2]
    s.cx = (s.ax+(s.ax * 0x00000002u));
  }
  L00671b63: { // 0x671b63: c6848d7815000001 MOV byte ptr [EBP + ECX*0x4 + 0x1578],0x1
    m.w8((s.bp+(s.cx * 0x00000004u)+0x00001578u), 0x00000001u);
  }
  L00671b6b: { // 0x671b6b: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00671b70: { // 0x671b70: e8bbe4e6ff CALL 0x004e0030
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e0030u,6757237u); flags=s.arithmetic_flags;
  }
  L00671b75: { // 0x671b75: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  L00671b7a: { // 0x671b7a: 8b8ddc4e0000 MOV ECX,dword ptr [EBP + 0x4edc]
    s.cx = m.r32((s.bp+0x00004edcu));
  }
  L00671b80: { // 0x671b80: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00671b82: { // 0x671b82: 7f09 JG 0x00671b8d
    if(integer::condition("JG",flags)) goto L00671b8d;
  }
  L00671b84: { // 0x671b84: 83c002 ADD EAX,0x2
    s.ax = integer::add(s.ax,0x00000002u,32,flags);
  }
  L00671b87: { // 0x671b87: 8985dc4e0000 MOV dword ptr [EBP + 0x4edc],EAX
    m.w32((s.bp+0x00004edcu), s.ax);
  }
  L00671b8d: { // 0x671b8d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00671b8e: { // 0x671b8e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00671b8f: { // 0x671b8f: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00671b90: { // 0x671b90: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
