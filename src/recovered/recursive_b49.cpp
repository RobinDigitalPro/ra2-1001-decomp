#include "recursive_b49_memory.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recursive_b49 {
namespace {
void f_002d7850(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6d7850: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6d7851: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6d7853: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6d7854: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x6d7856: 8b4e44 MOV ECX,dword ptr [ESI + 0x44]
    s.cx = m.r32((s.si+0x00000044u));
  }
  { // 0x6d7859: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x6d785b: 7412 JZ 0x006d786f
    if(integer::condition("JZ",flags)) goto L006d786f;
  }
  { // 0x6d785d: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x6d7861: 83f832 CMP EAX,0x32
    (void)integer::sub(s.ax,0x00000032u,32,flags);
  }
  { // 0x6d7864: 7f09 JG 0x006d786f
    if(integer::condition("JG",flags)) goto L006d786f;
  }
  { // 0x6d7866: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x6d7867: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6d7868: e8e3ffffff CALL 0x006d7850
    s.arithmetic_flags=flags;
    invoke_recursive(m,s,f,op,f_002d7850,0x006d786du);
    flags=s.arithmetic_flags;
  }
  { // 0x6d786d: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L006d786f: { // 0x6d786f: 8b4e24 MOV ECX,dword ptr [ESI + 0x24]
    s.cx = m.r32((s.si+0x00000024u));
  }
  { // 0x6d7872: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6d7874: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x6d7876: ff909c030000 CALL dword ptr [EAX + 0x39c]
    s.arithmetic_flags=flags;
    const std::uint32_t target=m.r32((s.ax+0x0000039cu));
    invoke_external(m,s,f,op,1u,target,0x006d787cu);
    flags=s.arithmetic_flags;
  }
  { // 0x6d787c: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x6d787e: 8b81a4000000 MOV EAX,dword ptr [ECX + 0xa4]
    s.ax = m.r32((s.cx+0x000000a4u));
  }
  { // 0x6d7884: 89464c MOV dword ptr [ESI + 0x4c],EAX
    m.w32((s.si+0x0000004cu), s.ax);
  }
  { // 0x6d7887: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  { // 0x6d7889: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6d788a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6d788b: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_002d7ae0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6d7ae0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6d7ae1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6d7ae2: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6d7ae4: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x6d7ae6: 8b4628 MOV EAX,dword ptr [ESI + 0x28]
    s.ax = m.r32((s.si+0x00000028u));
  }
  { // 0x6d7ae9: 889804020000 MOV byte ptr [EAX + 0x204],BL
    m.w8((s.ax+0x00000204u), (s.bx & 0xffu));
  }
  { // 0x6d7aef: 8b4e28 MOV ECX,dword ptr [ESI + 0x28]
    s.cx = m.r32((s.si+0x00000028u));
  }
  { // 0x6d7af2: 89990c020000 MOV dword ptr [ECX + 0x20c],EBX
    m.w32((s.cx+0x0000020cu), s.bx);
  }
  { // 0x6d7af8: 8b4644 MOV EAX,dword ptr [ESI + 0x44]
    s.ax = m.r32((s.si+0x00000044u));
  }
  { // 0x6d7afb: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x6d7afd: 895e28 MOV dword ptr [ESI + 0x28],EBX
    m.w32((s.si+0x00000028u), s.bx);
  }
  { // 0x6d7b00: 7410 JZ 0x006d7b12
    if(integer::condition("JZ",flags)) goto L006d7b12;
  }
  { // 0x6d7b02: 397040 CMP dword ptr [EAX + 0x40],ESI
    (void)integer::sub(m.r32((s.ax+0x00000040u)),s.si,32,flags);
  }
  { // 0x6d7b05: 7503 JNZ 0x006d7b0a
    if(integer::condition("JNZ",flags)) goto L006d7b0a;
  }
  { // 0x6d7b07: 895840 MOV dword ptr [EAX + 0x40],EBX
    m.w32((s.ax+0x00000040u), s.bx);
  }
  L006d7b0a: { // 0x6d7b0a: 8b4e44 MOV ECX,dword ptr [ESI + 0x44]
    s.cx = m.r32((s.si+0x00000044u));
  }
  { // 0x6d7b0d: e8ceffffff CALL 0x006d7ae0
    s.arithmetic_flags=flags;
    invoke_recursive(m,s,f,op,f_002d7ae0,0x006d7b12u);
    flags=s.arithmetic_flags;
  }
  L006d7b12: { // 0x6d7b12: 8b4640 MOV EAX,dword ptr [ESI + 0x40]
    s.ax = m.r32((s.si+0x00000040u));
  }
  { // 0x6d7b15: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x6d7b17: 7410 JZ 0x006d7b29
    if(integer::condition("JZ",flags)) goto L006d7b29;
  }
  { // 0x6d7b19: 397044 CMP dword ptr [EAX + 0x44],ESI
    (void)integer::sub(m.r32((s.ax+0x00000044u)),s.si,32,flags);
  }
  { // 0x6d7b1c: 7503 JNZ 0x006d7b21
    if(integer::condition("JNZ",flags)) goto L006d7b21;
  }
  { // 0x6d7b1e: 895844 MOV dword ptr [EAX + 0x44],EBX
    m.w32((s.ax+0x00000044u), s.bx);
  }
  L006d7b21: { // 0x6d7b21: 8b4e40 MOV ECX,dword ptr [ESI + 0x40]
    s.cx = m.r32((s.si+0x00000040u));
  }
  { // 0x6d7b24: e8b7ffffff CALL 0x006d7ae0
    s.arithmetic_flags=flags;
    invoke_recursive(m,s,f,op,f_002d7ae0,0x006d7b29u);
    flags=s.arithmetic_flags;
  }
  L006d7b29: { // 0x6d7b29: 895e44 MOV dword ptr [ESI + 0x44],EBX
    m.w32((s.si+0x00000044u), s.bx);
  }
  { // 0x6d7b2c: 895e40 MOV dword ptr [ESI + 0x40],EBX
    m.w32((s.si+0x00000040u), s.bx);
  }
  { // 0x6d7b2f: 895e3c MOV dword ptr [ESI + 0x3c],EBX
    m.w32((s.si+0x0000003cu), s.bx);
  }
  { // 0x6d7b32: 895e38 MOV dword ptr [ESI + 0x38],EBX
    m.w32((s.si+0x00000038u), s.bx);
  }
  { // 0x6d7b35: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6d7b36: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6d7b37: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002e2790(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6e2790: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e2791: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6e2793: 8b4628 MOV EAX,dword ptr [ESI + 0x28]
    s.ax = m.r32((s.si+0x00000028u));
  }
  { // 0x6e2796: 8b4e24 MOV ECX,dword ptr [ESI + 0x24]
    s.cx = m.r32((s.si+0x00000024u));
  }
  { // 0x6e2799: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6e279b: 7420 JZ 0x006e27bd
    if(integer::condition("JZ",flags)) goto L006e27bd;
  }
  { // 0x6e279d: e8ce0c0000 CALL 0x006e3470
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x006e3470u;
    invoke_external(m,s,f,op,0u,target,0x006e27a2u);
    flags=s.arithmetic_flags;
  }
  { // 0x6e27a2: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6e27a4: 7510 JNZ 0x006e27b6
    if(integer::condition("JNZ",flags)) goto L006e27b6;
  }
  { // 0x6e27a6: 8b4e28 MOV ECX,dword ptr [ESI + 0x28]
    s.cx = m.r32((s.si+0x00000028u));
  }
  { // 0x6e27a9: e8e2ffffff CALL 0x006e2790
    s.arithmetic_flags=flags;
    invoke_recursive(m,s,f,op,f_002e2790,0x006e27aeu);
    flags=s.arithmetic_flags;
  }
  { // 0x6e27ae: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6e27b0: 7504 JNZ 0x006e27b6
    if(integer::condition("JNZ",flags)) goto L006e27b6;
  }
  { // 0x6e27b2: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6e27b4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6e27b5: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L006e27b6: { // 0x6e27b6: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x6e27bb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6e27bc: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L006e27bd: { // 0x6e27bd: e8ae0c0000 CALL 0x006e3470
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x006e3470u;
    invoke_external(m,s,f,op,2u,target,0x006e27c2u);
    flags=s.arithmetic_flags;
  }
  { // 0x6e27c2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6e27c3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002e27d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6e27d0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e27d1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6e27d3: 8b4628 MOV EAX,dword ptr [ESI + 0x28]
    s.ax = m.r32((s.si+0x00000028u));
  }
  { // 0x6e27d6: 8b4e24 MOV ECX,dword ptr [ESI + 0x24]
    s.cx = m.r32((s.si+0x00000024u));
  }
  { // 0x6e27d9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6e27db: 7420 JZ 0x006e27fd
    if(integer::condition("JZ",flags)) goto L006e27fd;
  }
  { // 0x6e27dd: e85e0c0000 CALL 0x006e3440
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x006e3440u;
    invoke_external(m,s,f,op,0u,target,0x006e27e2u);
    flags=s.arithmetic_flags;
  }
  { // 0x6e27e2: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6e27e4: 7510 JNZ 0x006e27f6
    if(integer::condition("JNZ",flags)) goto L006e27f6;
  }
  { // 0x6e27e6: 8b4e28 MOV ECX,dword ptr [ESI + 0x28]
    s.cx = m.r32((s.si+0x00000028u));
  }
  { // 0x6e27e9: e8e2ffffff CALL 0x006e27d0
    s.arithmetic_flags=flags;
    invoke_recursive(m,s,f,op,f_002e27d0,0x006e27eeu);
    flags=s.arithmetic_flags;
  }
  { // 0x6e27ee: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6e27f0: 7504 JNZ 0x006e27f6
    if(integer::condition("JNZ",flags)) goto L006e27f6;
  }
  { // 0x6e27f2: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6e27f4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6e27f5: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L006e27f6: { // 0x6e27f6: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x6e27fb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6e27fc: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L006e27fd: { // 0x6e27fd: e83e0c0000 CALL 0x006e3440
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x006e3440u;
    invoke_external(m,s,f,op,2u,target,0x006e2802u);
    flags=s.arithmetic_flags;
  }
  { // 0x6e2802: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6e2803: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002e36d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6e36d0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6e36d1: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x6e36d3: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e36d4: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6e36d5: 8bb3ac000000 MOV ESI,dword ptr [EBX + 0xac]
    s.si = m.r32((s.bx+0x000000acu));
  }
  { // 0x6e36db: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x6e36dd: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6e36df: 7411 JZ 0x006e36f2
    if(integer::condition("JZ",flags)) goto L006e36f2;
  }
  L006e36e1: { // 0x6e36e1: 8b4e2c MOV ECX,dword ptr [ESI + 0x2c]
    s.cx = m.r32((s.si+0x0000002cu));
  }
  { // 0x6e36e4: e80786ffff CALL 0x006dbcf0
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x006dbcf0u;
    invoke_external(m,s,f,op,0u,target,0x006e36e9u);
    flags=s.arithmetic_flags;
  }
  { // 0x6e36e9: 8b7628 MOV ESI,dword ptr [ESI + 0x28]
    s.si = m.r32((s.si+0x00000028u));
  }
  { // 0x6e36ec: 0bf8 OR EDI,EAX
    s.di = integer::logical((s.di)|(s.ax),32,flags);
  }
  { // 0x6e36ee: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6e36f0: 75ef JNZ 0x006e36e1
    if(integer::condition("JNZ",flags)) goto L006e36e1;
  }
  L006e36f2: { // 0x6e36f2: 8bb3b0000000 MOV ESI,dword ptr [EBX + 0xb0]
    s.si = m.r32((s.bx+0x000000b0u));
  }
  { // 0x6e36f8: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6e36fa: 7411 JZ 0x006e370d
    if(integer::condition("JZ",flags)) goto L006e370d;
  }
  L006e36fc: { // 0x6e36fc: 8b4e2c MOV ECX,dword ptr [ESI + 0x2c]
    s.cx = m.r32((s.si+0x0000002cu));
  }
  { // 0x6e36ff: e83c4dfcff CALL 0x006a8440
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x006a8440u;
    invoke_external(m,s,f,op,1u,target,0x006e3704u);
    flags=s.arithmetic_flags;
  }
  { // 0x6e3704: 8b7628 MOV ESI,dword ptr [ESI + 0x28]
    s.si = m.r32((s.si+0x00000028u));
  }
  { // 0x6e3707: 0bf8 OR EDI,EAX
    s.di = integer::logical((s.di)|(s.ax),32,flags);
  }
  { // 0x6e3709: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6e370b: 75ef JNZ 0x006e36fc
    if(integer::condition("JNZ",flags)) goto L006e36fc;
  }
  L006e370d: { // 0x6e370d: 8b8ba8000000 MOV ECX,dword ptr [EBX + 0xa8]
    s.cx = m.r32((s.bx+0x000000a8u));
  }
  { // 0x6e3713: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x6e3715: 740b JZ 0x006e3722
    if(integer::condition("JZ",flags)) goto L006e3722;
  }
  { // 0x6e3717: e8b4ffffff CALL 0x006e36d0
    s.arithmetic_flags=flags;
    invoke_recursive(m,s,f,op,f_002e36d0,0x006e371cu);
    flags=s.arithmetic_flags;
  }
  { // 0x6e371c: 0bc7 OR EAX,EDI
    s.ax = integer::logical((s.ax)|(s.di),32,flags);
  }
  { // 0x6e371e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6e371f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6e3720: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6e3721: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L006e3722: { // 0x6e3722: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x6e3724: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6e3725: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6e3726: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6e3727: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
const std::array<Entry,5>& entries_a() {
  static const std::array<Entry,5> entries{{
    {0x2d7850u,f_002d7850},
    {0x2d7ae0u,f_002d7ae0},
    {0x2e2790u,f_002e2790},
    {0x2e27d0u,f_002e27d0},
    {0x2e36d0u,f_002e36d0},
  }}; return entries;
}
} // namespace ra2::recovered::recursive_b49
