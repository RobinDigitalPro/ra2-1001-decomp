#include "terminal_b52_memory.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::terminal_b52 {
namespace {
void f_003707dc(Memory&,State&,Frame&,const Operations&);
void f_003707ed(Memory&,State&,Frame&,const Operations&);
void f_00381910(Memory&,State&,Frame&,const Operations&);
void f_00286a00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x686a00: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x686a01: e8d69d0e00 CALL 0x007707dc
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,op,f_003707dc,0x00686a06u,0u);
    flags=s.arithmetic_flags;
  }
  { // 0x686a06: 90 NOP
    (void)0;
  }
  { // 0x686a07: 90 NOP
    (void)0;
  }
  { // 0x686a08: 90 NOP
    (void)0;
  }
  { // 0x686a09: 90 NOP
    (void)0;
  }
  { // 0x686a0a: 90 NOP
    (void)0;
  }
  { // 0x686a0b: 90 NOP
    (void)0;
  }
  { // 0x686a0c: 90 NOP
    (void)0;
  }
  { // 0x686a0d: 90 NOP
    (void)0;
  }
  { // 0x686a0e: 90 NOP
    (void)0;
  }
  { // 0x686a0f: 90 NOP
    (void)0;
  }
}
void f_003707dc(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x007707dc: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x007707de: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x007707e0: ff74240c PUSH dword ptr [ESP + 0xc]
    f.push(m,m.r32((f.sp+0x0000000cu)));
  }
  { // 0x007707e4: e833000000 CALL 0x0077081c
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x0077081cu;
    invoke_terminal(m,s,f,op,target,0x007707e9u);
    flags=s.arithmetic_flags;
  }
  { // 0x007707e9: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x007707ec: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
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
void f_003714d8(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7714d8: 833dc004b10001 CMP dword ptr [0x00b104c0],0x1
    (void)integer::sub(m.r32((0x00b104c0u)),0x00000001u,32,flags);
  }
  { // 0x7714df: 7505 JNZ 0x007714e6
    if(integer::condition("JNZ",flags)) goto L007714e6;
  }
  { // 0x7714e1: e8508a0000 CALL 0x00779f36
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x00779f36u;
    invoke_external(m,s,f,op,0u,target,0x007714e6u);
    flags=s.arithmetic_flags;
  }
  L007714e6: { // 0x7714e6: ff742404 PUSH dword ptr [ESP + 0x4]
    f.push(m,m.r32((f.sp+0x00000004u)));
  }
  { // 0x7714ea: e8808a0000 CALL 0x00779f6f
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x00779f6fu;
    invoke_external(m,s,f,op,1u,target,0x007714efu);
    flags=s.arithmetic_flags;
  }
  { // 0x7714ef: 68ff000000 PUSH 0xff
    f.push(m,0x000000ffu);
  }
  { // 0x7714f4: ff1570728100 CALL dword ptr [0x00817270]
    s.arithmetic_flags=flags;
    const std::uint32_t target=m.r32((0x00817270u));
    invoke_terminal(m,s,f,op,target,0x007714fau);
    flags=s.arithmetic_flags;
  }
}
void f_003714fd(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7714fd: 833dc004b10001 CMP dword ptr [0x00b104c0],0x1
    (void)integer::sub(m.r32((0x00b104c0u)),0x00000001u,32,flags);
  }
  { // 0x771504: 7505 JNZ 0x0077150b
    if(integer::condition("JNZ",flags)) goto L0077150b;
  }
  { // 0x771506: e82b8a0000 CALL 0x00779f36
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x00779f36u;
    invoke_external(m,s,f,op,0u,target,0x0077150bu);
    flags=s.arithmetic_flags;
  }
  L0077150b: { // 0x77150b: ff742404 PUSH dword ptr [ESP + 0x4]
    f.push(m,m.r32((f.sp+0x00000004u)));
  }
  { // 0x77150f: e85b8a0000 CALL 0x00779f6f
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x00779f6fu;
    invoke_external(m,s,f,op,1u,target,0x00771514u);
    flags=s.arithmetic_flags;
  }
  { // 0x771514: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x771515: 68ff000000 PUSH 0xff
    f.push(m,0x000000ffu);
  }
  { // 0x77151a: ff1504527800 CALL dword ptr [0x00785204]
    s.arithmetic_flags=flags;
    const std::uint32_t target=m.r32((0x00785204u));
    invoke_terminal(m,s,f,op,target,0x00771520u);
    flags=s.arithmetic_flags;
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
void f_003818ec(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7818ec: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x7818ed: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x7818ef: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  { // 0x7818f2: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x7818f4: 8d4df0 LEA ECX,[EBP + -0x10]
    s.cx = (s.bp-0x00000010u);
  }
  { // 0x7818f7: ff750c PUSH dword ptr [EBP + 0xc]
    f.push(m,m.r32((s.bp+0x0000000cu)));
  }
  { // 0x7818fa: ff7508 PUSH dword ptr [EBP + 0x8]
    f.push(m,m.r32((s.bp+0x00000008u)));
  }
  { // 0x7818fd: e80e000000 CALL 0x00781910
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,op,f_00381910,0x00781902u,12u);
    flags=s.arithmetic_flags;
  }
  { // 0x781902: 8d45f0 LEA EAX,[EBP + -0x10]
    s.ax = (s.bp-0x00000010u);
  }
  { // 0x781905: 68381c7b00 PUSH 0x7b1c38
    f.push(m,0x007b1c38u);
  }
  { // 0x78190a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x78190b: e81452ffff CALL 0x00776b24
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x00776b24u;
    invoke_terminal(m,s,f,op,target,0x00781910u);
    flags=s.arithmetic_flags;
  }
}
void f_00381910(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x00781910: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x00781914: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x00781915: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x00781917: 83660c00 AND dword ptr [ESI + 0xc],0x0
    m.w32((s.si+0x0000000cu), integer::logical((m.r32((s.si+0x0000000cu)))&(0x00000000u),32,flags));
  }
  { // 0x0078191b: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  { // 0x0078191e: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x00781922: c706d8d47900 MOV dword ptr [ESI],0x79d4d8
    m.w32((s.si), 0x0079d4d8u);
  }
  { // 0x00781928: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x0078192a: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  { // 0x0078192d: 740d JZ 0x0078193c
    if(integer::condition("JZ",flags)) goto L0078193c;
  }
  { // 0x0078192f: 807c241000 CMP byte ptr [ESP + 0x10],0x0
    (void)integer::sub(m.r8((f.sp+0x00000010u)),0x00000000u,8,flags);
  }
  { // 0x00781934: 7406 JZ 0x0078193c
    if(integer::condition("JZ",flags)) goto L0078193c;
  }
  { // 0x00781936: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x00781938: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x00781939: ff5104 CALL dword ptr [ECX + 0x4]
    s.arithmetic_flags=flags;
    const std::uint32_t target=m.r32((s.cx+0x00000004u));
    invoke_external(m,s,f,op,0u,target,0x0078193cu);
    flags=s.arithmetic_flags;
  }
  L0078193c: { // 0x0078193c: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x0078193e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x0078193f: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
} // namespace
const std::array<Entry,5>& entries_a() {
  static const std::array<Entry,5> entries{{
    {0x286a00u,f_00286a00},
    {0x3714d8u,f_003714d8},
    {0x3714fdu,f_003714fd},
    {0x38124cu,f_0038124c},
    {0x3818ecu,f_003818ec},
  }}; return entries;
}
} // namespace ra2::recovered::terminal_b52
