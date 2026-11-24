#include "seh_terminal_b53_memory.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::seh_terminal_b53 {
namespace {
void f_003707ed(Memory&,State&,Frame&,const Operations&);
void f_0037e3be(Memory&,State&,Frame&,const Operations&);
void f_00380d14(Memory&,State&,Frame&,const Operations&);
void f_00380d8d(Memory&,State&,Frame&,const Operations&);
void f_0038124c(Memory&,State&,Frame&,const Operations&);
void f_003707ed(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x007707ed: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x007707ef: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x007707f1: ff74240c PUSH dword ptr [ESP + 0xc]
    f.push(m,m.r32((f.sp+0x0000000cu)));
  }
  { // 0x007707f5: e822000000 CALL 0x0077081c
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x0077081cu;
    invoke_terminal(m,s,f,op,target,0x007707fau);
    flags=s.arithmetic_flags;
  }
  { // 0x007707fa: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x007707fd: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0037e3be(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77e3be: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77e3bf: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x77e3c3: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x77e3c5: 813863736de0 CMP dword ptr [EAX],0xe06d7363
    (void)integer::sub(m.r32((s.ax)),0xe06d7363u,32,flags);
  }
  { // 0x77e3cb: 7514 JNZ 0x0077e3e1
    if(integer::condition("JNZ",flags)) goto L0077e3e1;
  }
  { // 0x77e3cd: 83781003 CMP dword ptr [EAX + 0x10],0x3
    (void)integer::sub(m.r32((s.ax+0x00000010u)),0x00000003u,32,flags);
  }
  { // 0x77e3d1: 750e JNZ 0x0077e3e1
    if(integer::condition("JNZ",flags)) goto L0077e3e1;
  }
  { // 0x77e3d3: 81781420059319 CMP dword ptr [EAX + 0x14],0x19930520
    (void)integer::sub(m.r32((s.ax+0x00000014u)),0x19930520u,32,flags);
  }
  { // 0x77e3da: 7505 JNZ 0x0077e3e1
    if(integer::condition("JNZ",flags)) goto L0077e3e1;
  }
  { // 0x77e3dc: e933290000 JMP 0x00780d14
    s.arithmetic_flags=flags; f_00380d14(m,s,f,op); return;
  }
  L0077e3e1: { // 0x77e3e1: a1d407b100 MOV EAX,[0x00b107d4]
    s.ax = m.r32((0x00b107d4u));
  }
  { // 0x77e3e6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x77e3e8: 7414 JZ 0x0077e3fe
    if(integer::condition("JZ",flags)) goto L0077e3fe;
  }
  { // 0x77e3ea: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77e3eb: e80c290000 CALL 0x00780cfc
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x00780cfcu;
    invoke_external(m,s,f,op,0u,target,0x0077e3f0u);
    flags=s.arithmetic_flags;
  }
  { // 0x77e3f0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x77e3f2: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77e3f3: 7409 JZ 0x0077e3fe
    if(integer::condition("JZ",flags)) goto L0077e3fe;
  }
  { // 0x77e3f5: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77e3f6: ff15d407b100 CALL dword ptr [0x00b107d4]
    s.arithmetic_flags=flags;
    const std::uint32_t target=m.r32((0x00b107d4u));
    invoke_external(m,s,f,op,1u,target,0x0077e3fcu);
    flags=s.arithmetic_flags;
  }
  { // 0x77e3fc: eb02 JMP 0x0077e400
    goto L0077e400;
  }
  L0077e3fe: { // 0x77e3fe: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0077e400: { // 0x77e400: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x77e401: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00380d14(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x780d14: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x780d15: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x780d17: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  { // 0x780d19: 6888d47900 PUSH 0x79d488
    f.push(m,0x0079d488u);
  }
  { // 0x780d1e: 68d40b7700 PUSH 0x770bd4
    f.push(m,0x00770bd4u);
  }
  { // 0x780d23: 64a100000000 MOV EAX,FS:[0x0]
    s.ax = s.fs0;
  }
  { // 0x780d29: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x780d2a: 64892500000000 MOV dword ptr FS:[0x0],ESP
    s.fs0 = f.sp;
  }
  { // 0x780d31: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x780d32: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x780d33: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x780d34: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x780d35: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x780d36: 8965e8 MOV dword ptr [EBP + -0x18],ESP
    m.w32((s.bp-0x00000018u), f.sp);
  }
  { // 0x780d39: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x780d3b: 8975fc MOV dword ptr [EBP + -0x4],ESI
    m.w32((s.bp-0x00000004u), s.si);
  }
  { // 0x780d3e: e88842ffff CALL 0x00774fcb
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x00774fcbu;
    invoke_external(m,s,f,op,0u,target,0x00780d43u);
    flags=s.arithmetic_flags;
  }
  { // 0x780d43: 397060 CMP dword ptr [EAX + 0x60],ESI
    (void)integer::sub(m.r32((s.ax+0x00000060u)),s.si,32,flags);
  }
  { // 0x780d46: 741f JZ 0x00780d67
    if(integer::condition("JZ",flags)) goto L00780d67;
  }
  { // 0x780d48: c745fc01000000 MOV dword ptr [EBP + -0x4],0x1
    m.w32((s.bp-0x00000004u), 0x00000001u);
  }
  { // 0x780d4f: e87742ffff CALL 0x00774fcb
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x00774fcbu;
    invoke_external(m,s,f,op,1u,target,0x00780d54u);
    flags=s.arithmetic_flags;
  }
  { // 0x780d54: ff5060 CALL dword ptr [EAX + 0x60]
    s.arithmetic_flags=flags;
    const std::uint32_t target=m.r32((s.ax+0x00000060u));
    invoke_external(m,s,f,op,2u,target,0x00780d57u);
    flags=s.arithmetic_flags;
  }
  { // 0x780d57: 8975fc MOV dword ptr [EBP + -0x4],ESI
    m.w32((s.bp-0x00000004u), s.si);
  }
  { // 0x780d5a: eb0b JMP 0x00780d67
    goto L00780d67;
  }
  L00780d67: { // 0x780d67: 834dfcff OR dword ptr [EBP + -0x4],0xffffffff
    m.w32((s.bp-0x00000004u), integer::logical((m.r32((s.bp-0x00000004u)))|(0xffffffffu),32,flags));
  }
  { // 0x780d6b: e800000000 CALL 0x00780d70
    s.arithmetic_flags=flags;
    f.push(m,0x00780d70u); goto L00780d70;
    flags=s.arithmetic_flags;
  }
  L00780d70: { // 0x780d70: e9d7040000 JMP 0x0078124c
    s.arithmetic_flags=flags; f_0038124c(m,s,f,op); return;
  }
}
void f_00380d8d(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x780d8d: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x780d8e: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x780d90: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  { // 0x780d92: 68a0d47900 PUSH 0x79d4a0
    f.push(m,0x0079d4a0u);
  }
  { // 0x780d97: 68d40b7700 PUSH 0x770bd4
    f.push(m,0x00770bd4u);
  }
  { // 0x780d9c: 64a100000000 MOV EAX,FS:[0x0]
    s.ax = s.fs0;
  }
  { // 0x780da2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x780da3: 64892500000000 MOV dword ptr FS:[0x0],ESP
    s.fs0 = f.sp;
  }
  { // 0x780daa: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x780dab: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x780dac: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x780dad: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x780dae: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x780daf: 8965e8 MOV dword ptr [EBP + -0x18],ESP
    m.w32((s.bp-0x00000018u), f.sp);
  }
  { // 0x780db2: 8365fc00 AND dword ptr [EBP + -0x4],0x0
    m.w32((s.bp-0x00000004u), integer::logical((m.r32((s.bp-0x00000004u)))&(0x00000000u),32,flags));
  }
  { // 0x780db6: a184878100 MOV EAX,[0x00818784]
    s.ax = m.r32((0x00818784u));
  }
  { // 0x780dbb: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x780dbd: 7416 JZ 0x00780dd5
    if(integer::condition("JZ",flags)) goto L00780dd5;
  }
  { // 0x780dbf: c745fc01000000 MOV dword ptr [EBP + -0x4],0x1
    m.w32((s.bp-0x00000004u), 0x00000001u);
  }
  { // 0x780dc6: ffd0 CALL EAX
    s.arithmetic_flags=flags;
    const std::uint32_t target=s.ax;
    invoke_external(m,s,f,op,0u,target,0x00780dc8u);
    flags=s.arithmetic_flags;
  }
  { // 0x780dc8: eb07 JMP 0x00780dd1
    goto L00780dd1;
  }
  L00780dd1: { // 0x780dd1: 8365fc00 AND dword ptr [EBP + -0x4],0x0
    m.w32((s.bp-0x00000004u), integer::logical((m.r32((s.bp-0x00000004u)))&(0x00000000u),32,flags));
  }
  L00780dd5: { // 0x780dd5: 834dfcff OR dword ptr [EBP + -0x4],0xffffffff
    m.w32((s.bp-0x00000004u), integer::logical((m.r32((s.bp-0x00000004u)))|(0xffffffffu),32,flags));
  }
  { // 0x780dd9: e800000000 CALL 0x00780dde
    s.arithmetic_flags=flags;
    f.push(m,0x00780ddeu); goto L00780dde;
    flags=s.arithmetic_flags;
  }
  L00780dde: { // 0x780dde: e931ffffff JMP 0x00780d14
    s.arithmetic_flags=flags; f_00380d14(m,s,f,op); return;
  }
}
void f_0038124c(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x78124c: 6a0a PUSH 0xa
    f.push(m,0x0000000au);
  }
  { // 0x78124e: e81c8dffff CALL 0x00779f6f
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x00779f6fu;
    invoke_external(m,s,f,op,0u,target,0x00781253u);
    flags=s.arithmetic_flags;
  }
  { // 0x781253: 6a16 PUSH 0x16
    f.push(m,0x00000016u);
  }
  { // 0x781255: e8d671ffff CALL 0x00778430
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x00778430u;
    invoke_external(m,s,f,op,1u,target,0x0078125au);
    flags=s.arithmetic_flags;
  }
  { // 0x78125a: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x78125b: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x78125c: 6a03 PUSH 0x3
    f.push(m,0x00000003u);
  }
  { // 0x78125e: e88af5feff CALL 0x007707ed
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,op,f_003707ed,0x00781263u,0u);
    flags=s.arithmetic_flags;
  }
}
} // namespace
const std::array<Entry,3>& entries_a() {
  static const std::array<Entry,3> entries{{
    {0x37e3beu,f_0037e3be},
    {0x380d14u,f_00380d14},
    {0x380d8du,f_00380d8d},
  }}; return entries;
}
} // namespace ra2::recovered::seh_terminal_b53
