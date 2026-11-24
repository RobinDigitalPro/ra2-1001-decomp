#include "floating_parser_b50_memory.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::floating_parser_b50 {
namespace {
void f_0036e8a6(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76e8a6: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x76e8a7: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x76e8a9: 83ec18 SUB ESP,0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
  { // 0x76e8ac: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76e8ad: 8b7508 MOV ESI,dword ptr [EBP + 0x8]
    s.si = m.r32((s.bp+0x00000008u));
  }
  L0076e8b0: { // 0x76e8b0: 833d6c77810001 CMP dword ptr [0x0081776c],0x1
    (void)integer::sub(m.r32((0x0081776cu)),0x00000001u,32,flags);
  }
  { // 0x76e8b7: 7e0f JLE 0x0076e8c8
    if(integer::condition("JLE",flags)) goto L0076e8c8;
  }
  { // 0x76e8b9: 0fb606 MOVZX EAX,byte ptr [ESI]
    s.ax = (m.r8((s.si))&integer::mask(8));
  }
  { // 0x76e8bc: 6a08 PUSH 0x8
    f.push(m,0x00000008u);
  }
  { // 0x76e8be: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x76e8bf: e80d660000 CALL 0x00774ed1
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x00774ed1u;
    invoke_external(m,s,f,op,0u,target,0x0076e8c4u);
    flags=s.arithmetic_flags;
  }
  { // 0x76e8c4: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x76e8c5: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x76e8c6: eb0f JMP 0x0076e8d7
    goto L0076e8d7;
  }
  L0076e8c8: { // 0x76e8c8: 0fb606 MOVZX EAX,byte ptr [ESI]
    s.ax = (m.r8((s.si))&integer::mask(8));
  }
  { // 0x76e8cb: 8b0d60758100 MOV ECX,dword ptr [0x00817560]
    s.cx = m.r32((0x00817560u));
  }
  { // 0x76e8d1: 8a0441 MOV AL,byte ptr [ECX + EAX*0x2]
    s.ax = with_al(s.ax, m.r8((s.cx+(s.ax * 0x00000002u))));
  }
  { // 0x76e8d4: 83e008 AND EAX,0x8
    s.ax = integer::logical((s.ax)&(0x00000008u),32,flags);
  }
  L0076e8d7: { // 0x76e8d7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x76e8d9: 7403 JZ 0x0076e8de
    if(integer::condition("JZ",flags)) goto L0076e8de;
  }
  { // 0x76e8db: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x76e8dc: ebd2 JMP 0x0076e8b0
    goto L0076e8b0;
  }
  L0076e8de: { // 0x76e8de: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x76e8e0: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x76e8e2: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76e8e3: e878680000 CALL 0x00775160
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x00775160u;
    invoke_external(m,s,f,op,1u,target,0x0076e8e8u);
    flags=s.arithmetic_flags;
  }
  { // 0x76e8e8: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x76e8e9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x76e8ea: 8d45e8 LEA EAX,[EBP + -0x18]
    s.ax = (s.bp-0x00000018u);
  }
  { // 0x76e8ed: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76e8ee: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x76e8ef: e8ea670000 CALL 0x007750de
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x007750deu;
    invoke_external(m,s,f,op,2u,target,0x0076e8f4u);
    flags=s.arithmetic_flags;
  }
  { // 0x76e8f4: dd4010 FLD double ptr [EAX + 0x10]
    const auto address=(s.ax+0x00000010u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x76e8f7: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  { // 0x76e8fa: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x76e8fb: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x76e8fc: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
const std::array<Entry,1>& entries_a() {
  static const std::array<Entry,1> entries{{
    {0x36e8a6u,f_0036e8a6},
  }}; return entries;
}
} // namespace ra2::recovered::floating_parser_b50
