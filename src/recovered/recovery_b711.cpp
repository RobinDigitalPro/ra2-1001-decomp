#include "recovered/recovery_b711.hpp"
#include "recovered/recovery_b707.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::recovery_b711 {
Result run(Memory& original,const floating_b61::Inputs&i){
 Memory m=original;
 constexpr std::uint32_t stack_base=0x7e000000u,entry_sp=stack_base+0x6004u,outer=0x76543210u;
 std::array<std::uint8_t,0x8000> bytes{};leaf::Memory stack(bytes.data(),stack_base,std::uint32_t(bytes.size()));m.add(stack);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{entry_sp,entry_sp,outer};m.w32(entry_sp,outer);for(unsigned k=0;k<i.arg.size();++k)m.w32(entry_sp+4u+4u*k,i.arg[k]);
 fun_005f5d00(m,s,f,Operations{});
 i.fp=s.fp;
 if(f.sp!=entry_sp+4u+32u)throw std::runtime_error("text711 root RET 0x20 stack cleanup mismatch");
 Result r{};r.eax=s.ax;for(unsigned k=0;k<r.args.size();++k)r.args[k]=m.r32(entry_sp+4u+4u*k);return r;
}
std::uint32_t call_root(Memory&m,const floating_b61::Inputs&i){const auto r=run(m,i);for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=r.args[k];return r.eax;}
}

#include "recovered/recovery_b108_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include "recovered/strings_b37_primitives.hpp"
#include <limits>
#include <algorithm>
#include <stdexcept>
#include "recovered/recovery_b108_machine.hpp"
#include "recovered/recovery_b711.hpp"
#include "recovered/recovery_b707.hpp"
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b711 {
using namespace ra2::recovered::recovery_b108;
namespace integer=direct_b33::integer;
namespace {
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);
void f_001f5d00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5f5d00: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  { // 0x5f5d03: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  { // 0x5f5d07: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5f5d08: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x5f5d0a: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  { // 0x5f5d0e: 8a0dfcb28300 MOV CL,byte ptr [0x0083b2fc]
    s.cx = with_al(s.cx, m.r8((0x0083b2fcu)));
  }
  { // 0x5f5d14: 8adc MOV BL,AH
    s.bx = with_al(s.bx, ((s.ax >> 8) & 0xffu));
  }
  { // 0x5f5d16: 81e3ff000000 AND EBX,0xff
    s.bx = integer::logical((s.bx)&(0x000000ffu),32,flags);
  }
  { // 0x5f5d1c: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x5f5d1d: d3eb SHR EBX,CL
    s.bx = integer::shift(s.bx,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  { // 0x5f5d1f: 8b0df8b28300 MOV ECX,dword ptr [0x0083b2f8]
    s.cx = m.r32((0x0083b2f8u));
  }
  { // 0x5f5d25: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f5d26: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x5f5d28: 25ff000000 AND EAX,0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  { // 0x5f5d2d: c1ee10 SHR ESI,0x10
    s.si = integer::shift(s.si,0x00000010u,32,flags,integer::Shift::right);
  }
  { // 0x5f5d30: d3e3 SHL EBX,CL
    s.bx = integer::shift(s.bx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  { // 0x5f5d32: 8a0df4b28300 MOV CL,byte ptr [0x0083b2f4]
    s.cx = with_al(s.cx, m.r8((0x0083b2f4u)));
  }
  { // 0x5f5d38: 81e6ff000000 AND ESI,0xff
    s.si = integer::logical((s.si)&(0x000000ffu),32,flags);
  }
  { // 0x5f5d3e: d3ee SHR ESI,CL
    s.si = integer::shift(s.si,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  { // 0x5f5d40: 8b0df0b28300 MOV ECX,dword ptr [0x0083b2f0]
    s.cx = m.r32((0x0083b2f0u));
  }
  { // 0x5f5d46: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5f5d47: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  { // 0x5f5d4b: d3e6 SHL ESI,CL
    s.si = integer::shift(s.si,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  { // 0x5f5d4d: 8a0decb28300 MOV CL,byte ptr [0x0083b2ec]
    s.cx = with_al(s.cx, m.r8((0x0083b2ecu)));
  }
  { // 0x5f5d53: d3e8 SHR EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  { // 0x5f5d55: 8b0de8b28300 MOV ECX,dword ptr [0x0083b2e8]
    s.cx = m.r32((0x0083b2e8u));
  }
  { // 0x5f5d5b: 0bde OR EBX,ESI
    s.bx = integer::logical((s.bx)|(s.si),32,flags);
  }
  { // 0x5f5d5d: 8b742424 MOV ESI,dword ptr [ESP + 0x24]
    s.si = m.r32((f.sp+0x00000024u));
  }
  { // 0x5f5d61: 8b6e0c MOV EBP,dword ptr [ESI + 0xc]
    s.bp = m.r32((s.si+0x0000000cu));
  }
  { // 0x5f5d64: 8b7e08 MOV EDI,dword ptr [ESI + 0x8]
    s.di = m.r32((s.si+0x00000008u));
  }
  { // 0x5f5d67: d3e0 SHL EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  { // 0x5f5d69: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x5f5d6b: 2bf9 SUB EDI,ECX
    s.di = integer::sub(s.di,s.cx,32,flags);
  }
  { // 0x5f5d6d: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  { // 0x5f5d71: 0bd8 OR EBX,EAX
    s.bx = integer::logical((s.bx)|(s.ax),32,flags);
  }
  { // 0x5f5d73: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x5f5d76: 8944242c MOV dword ptr [ESP + 0x2c],EAX
    m.w32((f.sp+0x0000002cu), s.ax);
  }
  { // 0x5f5d7a: 2be8 SUB EBP,EAX
    s.bp = integer::sub(s.bp,s.ax,32,flags);
  }
  { // 0x5f5d7c: 8a442430 MOV AL,byte ptr [ESP + 0x30]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000030u)));
  }
  { // 0x5f5d80: 895c2410 MOV dword ptr [ESP + 0x10],EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
  { // 0x5f5d84: 8b5c2428 MOV EBX,dword ptr [ESP + 0x28]
    s.bx = m.r32((f.sp+0x00000028u));
  }
  { // 0x5f5d88: a804 TEST AL,0x4
    (void)integer::logical(((s.ax & 0xffu))&(0x00000004u),8,flags);
  }
  { // 0x5f5d8a: 742a JZ 0x005f5db6
    if(integer::condition("JZ",flags)) goto L005f5db6;
  }
  { // 0x5f5d8c: 8d442424 LEA EAX,[ESP + 0x24]
    s.ax = (f.sp+0x00000024u);
  }
  { // 0x5f5d90: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5f5d91: 8d4c242c LEA ECX,[ESP + 0x2c]
    s.cx = (f.sp+0x0000002cu);
  }
  { // 0x5f5d95: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5f5d96: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5f5d97: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x5f5d98: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x5f5d9a: e8d1b5e3ff CALL 0x00431370
    s.arithmetic_flags=flags; invoke(m,s,f,0x00431370u,0x005f5d9fu); flags=0x202u; s.arithmetic_flags=flags;
  }
  { // 0x5f5d9f: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  { // 0x5f5da1: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  { // 0x5f5da5: 8b4c242c MOV ECX,dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  { // 0x5f5da9: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x5f5dab: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x5f5dac: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x5f5dae: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x5f5db0: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  { // 0x5f5db2: 894c242c MOV dword ptr [ESP + 0x2c],ECX
    m.w32((f.sp+0x0000002cu), s.cx);
  }
  L005f5db6: { // 0x5f5db6: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x5f5db8: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x5f5dba: e851b5e3ff CALL 0x00431310
    s.arithmetic_flags=flags; invoke(m,s,f,0x00431310u,0x005f5dbfu); flags=0x202u; s.arithmetic_flags=flags;
  }
  { // 0x5f5dbf: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x5f5dc1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f5dc2: e859b5e3ff CALL 0x00431320
    s.arithmetic_flags=flags; invoke(m,s,f,0x00431320u,0x005f5dc7u); flags=0x202u; s.arithmetic_flags=flags;
  }
  { // 0x5f5dc7: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x5f5dc9: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  { // 0x5f5dcd: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x5f5dce: e81db5e3ff CALL 0x004312f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004312f0u,0x005f5dd3u); flags=0x202u; s.arithmetic_flags=flags;
  }
  { // 0x5f5dd3: 8b442440 MOV EAX,dword ptr [ESP + 0x40]
    s.ax = m.r32((f.sp+0x00000040u));
  }
  { // 0x5f5dd7: 8b4c243c MOV ECX,dword ptr [ESP + 0x3c]
    s.cx = m.r32((f.sp+0x0000003cu));
  }
  { // 0x5f5ddb: 8b542430 MOV EDX,dword ptr [ESP + 0x30]
    s.dx = m.r32((f.sp+0x00000030u));
  }
  { // 0x5f5ddf: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5f5de0: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  { // 0x5f5de4: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5f5de5: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  { // 0x5f5de9: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x5f5dea: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  { // 0x5f5dee: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x5f5def: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5f5df0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5f5df1: 8b442434 MOV EAX,dword ptr [ESP + 0x34]
    s.ax = m.r32((f.sp+0x00000034u));
  }
  { // 0x5f5df5: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5f5df6: 8b0d186d8300 MOV ECX,dword ptr [0x00836d18]
    s.cx = m.r32((0x00836d18u));
  }
  { // 0x5f5dfc: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x5f5dfd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5f5dfe: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5f5dff: e84cc5e3ff CALL 0x00432350
    s.arithmetic_flags=flags; invoke(m,s,f,0x00432350u,0x005f5e04u); flags=0x202u; s.arithmetic_flags=flags;
  }
  { // 0x5f5e04: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x5f5e06: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5f5e07: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5f5e08: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x5f5e09: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5f5e0a: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x5f5e0d: c22000 RET 0x20
    finish(m,s,f,32u); return;
  }
}
} // namespace

namespace {
using U=std::uint32_t;
using B26=ra2::recovered::global_b26::Inputs;
void invoke(Memory&m,State&s,Frame&f,U target,U continuation){
 f.push(m,continuation);B26 q{};q.ax=s.ax;q.cx=s.cx;q.dx=s.dx;q.arithmetic_flags=s.arithmetic_flags;
 for(unsigned k=0;k<q.arg.size();++k)q.arg[k]=m.r32(f.sp+4u+4u*k);
 U cleanup=4;
 switch(target){
 case 0x00431310u:{const U old=m.r8(q.cx+0x41u);m.w8(q.cx+0x41u,q.arg[0]);s.ax=old;break;}
 case 0x00431320u:{const U src=q.arg[0];if(!src){for(U k=0;k<4;++k)m.w32(q.cx+0x30u+4u*k,0u);s.ax=0;}else{for(U k=0;k<4;++k)m.w32(q.cx+0x30u+4u*k,m.r32(src+4u*k));s.ax=m.r32(src+12u);}break;}
 case 0x004312f0u:{const U old=m.r16(q.cx+0x24u);m.w16(q.cx+0x24u,q.arg[0]);s.ax=old;break;}
 case 0x00431370u:throw std::domain_error("B711 fixture excludes centered-rectangle helper path");
 case 0x00432350u:{State child=s;Frame cf{f.sp,f.sp,continuation};ra2::recovered::recovery_b707::fun_00432350(m,child,cf,Operations{});s=child;f.sp=cf.sp;return;}
 default:throw std::domain_error("B711 unreviewed direct call target");
 }
 for(unsigned k=0;k<q.arg.size();++k)m.w32(f.sp+4u+4u*k,q.arg[k]);
 if(m.r32(f.sp)!=continuation)throw std::runtime_error("B711 helper return address changed");
 f.sp+=4u+cleanup;
}
}
void fun_005f5d00(Memory&m,State&s,Frame&f,const Operations&op){f_001f5d00(m,s,f,op);}
} // namespace ra2::recovered::recovery_b711
