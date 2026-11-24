#include "recursive_lock_b54_memory.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recursive_lock_b54 {
namespace {
void f_003714d8(Memory&,State&,Frame&,const Operations&);
void f_003715b6(Memory&,State&,Frame&,const Operations&);
void f_00371617(Memory&,State&,Frame&,const Operations&);
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
void f_003715b6(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7715b6: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x7715b7: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x7715b9: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  { // 0x7715bc: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7715bd: 833c857872810000 CMP dword ptr [EAX*0x4 + 0x817278],0x0
    (void)integer::sub(m.r32(((s.ax * 0x00000004u)+0x00817278u)),0x00000000u,32,flags);
  }
  { // 0x7715c5: 8d348578728100 LEA ESI,[EAX*0x4 + 0x817278]
    s.si = ((s.ax * 0x00000004u)+0x00817278u);
  }
  { // 0x7715cc: 753e JNZ 0x0077160c
    if(integer::condition("JNZ",flags)) goto L0077160c;
  }
  { // 0x7715ce: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x7715cf: 6a18 PUSH 0x18
    f.push(m,0x00000018u);
  }
  { // 0x7715d1: e89ac9ffff CALL 0x0076df70
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x0076df70u;
    invoke_external(m,s,f,op,0u,target,0x007715d6u);
    flags=s.arithmetic_flags;
  }
  { // 0x7715d6: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x7715d8: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x7715d9: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x7715db: 7508 JNZ 0x007715e5
    if(integer::condition("JNZ",flags)) goto L007715e5;
  }
  { // 0x7715dd: 6a11 PUSH 0x11
    f.push(m,0x00000011u);
  }
  { // 0x7715df: e8f4feffff CALL 0x007714d8
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,op,f_003714d8,0x007715e4u,0u);
    flags=s.arithmetic_flags;
  }
  { // 0x7715e4: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L007715e5: { // 0x7715e5: 6a11 PUSH 0x11
    f.push(m,0x00000011u);
  }
  { // 0x7715e7: e8caffffff CALL 0x007715b6
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,op,f_003715b6,0x007715ecu,0u);
    flags=s.arithmetic_flags;
  }
  { // 0x7715ec: 833e00 CMP dword ptr [ESI],0x0
    (void)integer::sub(m.r32((s.si)),0x00000000u,32,flags);
  }
  { // 0x7715ef: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x7715f0: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x7715f1: 750a JNZ 0x007715fd
    if(integer::condition("JNZ",flags)) goto L007715fd;
  }
  { // 0x7715f3: ff15e8517800 CALL dword ptr [0x007851e8]
    s.arithmetic_flags=flags;
    const std::uint32_t target=m.r32((0x007851e8u));
    invoke_external(m,s,f,op,3u,target,0x007715f9u);
    flags=s.arithmetic_flags;
  }
  { // 0x7715f9: 893e MOV dword ptr [ESI],EDI
    m.w32((s.si), s.di);
  }
  { // 0x7715fb: eb06 JMP 0x00771603
    goto L00771603;
  }
  L007715fd: { // 0x7715fd: e826c9ffff CALL 0x0076df28
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x0076df28u;
    invoke_external(m,s,f,op,4u,target,0x00771602u);
    flags=s.arithmetic_flags;
  }
  { // 0x771602: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00771603: { // 0x771603: 6a11 PUSH 0x11
    f.push(m,0x00000011u);
  }
  { // 0x771605: e80d000000 CALL 0x00771617
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,op,f_00371617,0x0077160au,0u);
    flags=s.arithmetic_flags;
  }
  { // 0x77160a: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77160b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0077160c: { // 0x77160c: ff36 PUSH dword ptr [ESI]
    f.push(m,m.r32((s.si)));
  }
  { // 0x77160e: ff15dc517800 CALL dword ptr [0x007851dc]
    s.arithmetic_flags=flags;
    const std::uint32_t target=m.r32((0x007851dcu));
    invoke_external(m,s,f,op,6u,target,0x00771614u);
    flags=s.arithmetic_flags;
  }
  { // 0x771614: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x771615: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x771616: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00371617(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x771617: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x771618: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x77161a: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  { // 0x77161d: ff348578728100 PUSH dword ptr [EAX*0x4 + 0x817278]
    f.push(m,m.r32(((s.ax * 0x00000004u)+0x00817278u)));
  }
  { // 0x771624: ff15e0517800 CALL dword ptr [0x007851e0]
    s.arithmetic_flags=flags;
    const std::uint32_t target=m.r32((0x007851e0u));
    invoke_external(m,s,f,op,0u,target,0x0077162au);
    flags=s.arithmetic_flags;
  }
  { // 0x77162a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x77162b: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
const std::array<Entry,1>& entries_a() {
  static const std::array<Entry,1> entries{{
    {0x3715b6u,f_003715b6},
  }}; return entries;
}
} // namespace ra2::recovered::recursive_lock_b54
