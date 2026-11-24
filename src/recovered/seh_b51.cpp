#include "seh_b51_memory.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::seh_b51 {
namespace {
void f_0036f78c(Memory&,State&,Frame&,const Operations&);
void f_00370bb2(Memory&,State&,Frame&,const Operations&);
void f_0036f42f(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76f42f: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x76f430: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x76f432: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  { // 0x76f434: 68f8c57900 PUSH 0x79c5f8
    f.push(m,0x0079c5f8u);
  }
  { // 0x76f439: 68d40b7700 PUSH 0x770bd4
    f.push(m,0x00770bd4u);
  }
  { // 0x76f43e: 64a100000000 MOV EAX,FS:[0x0]
    s.ax = s.fs0;
  }
  { // 0x76f444: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x76f445: 64892500000000 MOV dword ptr FS:[0x0],ESP
    s.fs0 = f.sp;
  }
  { // 0x76f44c: 83ec18 SUB ESP,0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
  { // 0x76f44f: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x76f450: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76f451: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x76f452: 8965e8 MOV dword ptr [EBP + -0x18],ESP
    m.w32((s.bp-0x00000018u), f.sp);
  }
  { // 0x76f455: 837d0800 CMP dword ptr [EBP + 0x8],0x0
    (void)integer::sub(m.r32((s.bp+0x00000008u)),0x00000000u,32,flags);
  }
  { // 0x76f459: 7511 JNZ 0x0076f46c
    if(integer::condition("JNZ",flags)) goto L0076f46c;
  }
  { // 0x76f45b: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0076f45d: { // 0x76f45d: 8b4df0 MOV ECX,dword ptr [EBP + -0x10]
    s.cx = m.r32((s.bp-0x00000010u));
  }
  { // 0x76f460: 64890d00000000 MOV dword ptr FS:[0x0],ECX
    s.fs0 = s.cx;
  }
  { // 0x76f467: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x76f468: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x76f469: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x76f46a: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x76f46b: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076f46c: { // 0x76f46c: 8365fc00 AND dword ptr [EBP + -0x4],0x0
    m.w32((s.bp-0x00000004u), integer::logical((m.r32((s.bp-0x00000004u)))&(0x00000000u),32,flags));
  }
  { // 0x76f470: ff7508 PUSH dword ptr [EBP + 0x8]
    f.push(m,m.r32((s.bp+0x00000008u)));
  }
  { // 0x76f473: e814030000 CALL 0x0076f78c
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,op,f_0036f78c,0x0076f478u,0u);
    flags=s.arithmetic_flags;
  }
  { // 0x76f478: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x76f479: 834dfcff OR dword ptr [EBP + -0x4],0xffffffff
    m.w32((s.bp-0x00000004u), integer::logical((m.r32((s.bp-0x00000004u)))|(0xffffffffu),32,flags));
  }
  { // 0x76f47d: ebde JMP 0x0076f45d
    goto L0076f45d;
  }
}
void f_0036f78c(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76f78c: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  { // 0x76f790: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x76f792: 8b50fc MOV EDX,dword ptr [EAX + -0x4]
    s.dx = m.r32((s.ax-0x00000004u));
  }
  { // 0x76f795: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x76f797: 2b4204 SUB EAX,dword ptr [EDX + 0x4]
    s.ax = integer::sub(s.ax,m.r32((s.dx+0x00000004u)),32,flags);
  }
  { // 0x76f79a: 8b5208 MOV EDX,dword ptr [EDX + 0x8]
    s.dx = m.r32((s.dx+0x00000008u));
  }
  { // 0x76f79d: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  { // 0x76f79f: 7404 JZ 0x0076f7a5
    if(integer::condition("JZ",flags)) goto L0076f7a5;
  }
  { // 0x76f7a1: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  { // 0x76f7a3: 0301 ADD EAX,dword ptr [ECX]
    s.ax = integer::add(s.ax,m.r32((s.cx)),32,flags);
  }
  L0076f7a5: { // 0x76f7a5: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00370b1e(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x770b1e: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x770b1f: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x770b20: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x770b21: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x770b25: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x770b26: 6afe PUSH -0x2
    f.push(m,0xfffffffeu);
  }
  { // 0x770b28: 68fc0a7700 PUSH 0x770afc
    f.push(m,0x00770afcu);
  }
  { // 0x770b2d: 64ff3500000000 PUSH dword ptr FS:[0x0]
    f.push(m,s.fs0);
  }
  { // 0x770b34: 64892500000000 MOV dword ptr FS:[0x0],ESP
    s.fs0 = f.sp;
  }
  L00770b3b: { // 0x770b3b: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  { // 0x770b3f: 8b5808 MOV EBX,dword ptr [EAX + 0x8]
    s.bx = m.r32((s.ax+0x00000008u));
  }
  { // 0x770b42: 8b700c MOV ESI,dword ptr [EAX + 0xc]
    s.si = m.r32((s.ax+0x0000000cu));
  }
  { // 0x770b45: 83feff CMP ESI,-0x1
    (void)integer::sub(s.si,0xffffffffu,32,flags);
  }
  { // 0x770b48: 742e JZ 0x00770b78
    if(integer::condition("JZ",flags)) goto L00770b78;
  }
  { // 0x770b4a: 3b742424 CMP ESI,dword ptr [ESP + 0x24]
    (void)integer::sub(s.si,m.r32((f.sp+0x00000024u)),32,flags);
  }
  { // 0x770b4e: 7428 JZ 0x00770b78
    if(integer::condition("JZ",flags)) goto L00770b78;
  }
  { // 0x770b50: 8d3476 LEA ESI,[ESI + ESI*0x2]
    s.si = (s.si+(s.si * 0x00000002u));
  }
  { // 0x770b53: 8b0cb3 MOV ECX,dword ptr [EBX + ESI*0x4]
    s.cx = m.r32((s.bx+(s.si * 0x00000004u)));
  }
  { // 0x770b56: 894c2408 MOV dword ptr [ESP + 0x8],ECX
    m.w32((f.sp+0x00000008u), s.cx);
  }
  { // 0x770b5a: 89480c MOV dword ptr [EAX + 0xc],ECX
    m.w32((s.ax+0x0000000cu), s.cx);
  }
  { // 0x770b5d: 837cb30400 CMP dword ptr [EBX + ESI*0x4 + 0x4],0x0
    (void)integer::sub(m.r32((s.bx+(s.si * 0x00000004u)+0x00000004u)),0x00000000u,32,flags);
  }
  { // 0x770b62: 7512 JNZ 0x00770b76
    if(integer::condition("JNZ",flags)) goto L00770b76;
  }
  { // 0x770b64: 6801010000 PUSH 0x101
    f.push(m,0x00000101u);
  }
  { // 0x770b69: 8b44b308 MOV EAX,dword ptr [EBX + ESI*0x4 + 0x8]
    s.ax = m.r32((s.bx+(s.si * 0x00000004u)+0x00000008u));
  }
  { // 0x770b6d: e840000000 CALL 0x00770bb2
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,op,f_00370bb2,0x00770b72u,4u);
    flags=s.arithmetic_flags;
  }
  { // 0x770b72: ff54b308 CALL dword ptr [EBX + ESI*0x4 + 0x8]
    s.arithmetic_flags=flags;
    const std::uint32_t target=m.r32((s.bx+(s.si * 0x00000004u)+0x00000008u));
    invoke_external(m,s,f,op,1u,target,0x00770b76u);
    flags=s.arithmetic_flags;
  }
  L00770b76: { // 0x770b76: ebc3 JMP 0x00770b3b
    goto L00770b3b;
  }
  L00770b78: { // 0x770b78: 648f0500000000 POP dword ptr FS:[0x0]
    const auto value=f.pop(m); s.fs0 = value;
  }
  { // 0x770b7f: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x770b82: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x770b83: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x770b84: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x770b85: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00370bb2(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x770bb2: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x770bb3: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x770bb4: bb50728100 MOV EBX,0x817250
    s.bx = 0x00817250u;
  }
  { // 0x770bb9: 8b4d08 MOV ECX,dword ptr [EBP + 0x8]
    s.cx = m.r32((s.bp+0x00000008u));
  }
  { // 0x770bbc: 894b08 MOV dword ptr [EBX + 0x8],ECX
    m.w32((s.bx+0x00000008u), s.cx);
  }
  { // 0x770bbf: 894304 MOV dword ptr [EBX + 0x4],EAX
    m.w32((s.bx+0x00000004u), s.ax);
  }
  { // 0x770bc2: 896b0c MOV dword ptr [EBX + 0xc],EBP
    m.w32((s.bx+0x0000000cu), s.bp);
  }
  { // 0x770bc5: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x770bc6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x770bc7: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
} // namespace
const std::array<Entry,2>& entries_a() {
  static const std::array<Entry,2> entries{{
    {0x36f42fu,f_0036f42f},
    {0x370b1eu,f_00370b1e},
  }}; return entries;
}
} // namespace ra2::recovered::seh_b51
