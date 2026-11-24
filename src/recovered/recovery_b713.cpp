#include "recovered/recovery_b713.hpp"
#include "recovered/recovery_b707.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::recovery_b713 {
Result run(Memory& original,const floating_b61::Inputs&i){
 Memory m=original;
 constexpr std::uint32_t stack_base=0x7e000000u,entry_sp=stack_base+0x6004u,outer=0x76543210u;
 std::array<std::uint8_t,0x8000> bytes{};leaf::Memory stack(bytes.data(),stack_base,std::uint32_t(bytes.size()));m.add(stack);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{entry_sp,entry_sp,outer};m.w32(entry_sp,outer);for(unsigned k=0;k<i.arg.size();++k)m.w32(entry_sp+4u+4u*k,i.arg[k]);
 fun_005f5c20(m,s,f,Operations{});
 i.fp=s.fp;
 if(f.sp!=entry_sp+4u+16u)throw std::runtime_error("text713 root RET 0x10 stack cleanup mismatch");
 i.fp=s.fp;Result r{};r.eax=s.ax;for(unsigned k=0;k<r.args.size();++k)r.args[k]=m.r32(entry_sp+4u+4u*k);return r;
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
#include "recovered/recovery_b713.hpp"
#include "recovered/recovery_b707.hpp"
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b713 {
using namespace ra2::recovered::recovery_b108;
namespace integer=direct_b33::integer;
namespace {
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);
void f_001f5c20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5f5c20: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  { // 0x5f5c23: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  { // 0x5f5c27: 89542404 MOV dword ptr [ESP + 0x4],EDX
    m.w32((f.sp+0x00000004u), s.dx);
  }
  { // 0x5f5c2b: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x5f5c2d: 894c2408 MOV dword ptr [ESP + 0x8],ECX
    m.w32((f.sp+0x00000008u), s.cx);
  }
  { // 0x5f5c31: 8a0dfcb28300 MOV CL,byte ptr [0x0083b2fc]
    s.cx = with_al(s.cx, m.r8((0x0083b2fcu)));
  }
  { // 0x5f5c37: 8ad4 MOV DL,AH
    s.dx = with_al(s.dx, ((s.ax >> 8) & 0xffu));
  }
  { // 0x5f5c39: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  { // 0x5f5c3f: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5f5c40: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x5f5c41: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f5c42: d3ea SHR EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  { // 0x5f5c44: 8b0df8b28300 MOV ECX,dword ptr [0x0083b2f8]
    s.cx = m.r32((0x0083b2f8u));
  }
  { // 0x5f5c4a: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x5f5c4c: c1ee10 SHR ESI,0x10
    s.si = integer::shift(s.si,0x00000010u,32,flags,integer::Shift::right);
  }
  { // 0x5f5c4f: 81e6ff000000 AND ESI,0xff
    s.si = integer::logical((s.si)&(0x000000ffu),32,flags);
  }
  { // 0x5f5c55: 25ff000000 AND EAX,0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  { // 0x5f5c5a: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  { // 0x5f5c5c: 8a0df4b28300 MOV CL,byte ptr [0x0083b2f4]
    s.cx = with_al(s.cx, m.r8((0x0083b2f4u)));
  }
  { // 0x5f5c62: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5f5c63: d3ee SHR ESI,CL
    s.si = integer::shift(s.si,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  { // 0x5f5c65: 8b0df0b28300 MOV ECX,dword ptr [0x0083b2f0]
    s.cx = m.r32((0x0083b2f0u));
  }
  { // 0x5f5c6b: 8b7c2424 MOV EDI,dword ptr [ESP + 0x24]
    s.di = m.r32((f.sp+0x00000024u));
  }
  { // 0x5f5c6f: d3e6 SHL ESI,CL
    s.si = integer::shift(s.si,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  { // 0x5f5c71: 8a0decb28300 MOV CL,byte ptr [0x0083b2ec]
    s.cx = with_al(s.cx, m.r8((0x0083b2ecu)));
  }
  { // 0x5f5c77: d3e8 SHR EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  { // 0x5f5c79: 8b0de8b28300 MOV ECX,dword ptr [0x0083b2e8]
    s.cx = m.r32((0x0083b2e8u));
  }
  { // 0x5f5c7f: 0bd6 OR EDX,ESI
    s.dx = integer::logical((s.dx)|(s.si),32,flags);
  }
  { // 0x5f5c81: 8b742420 MOV ESI,dword ptr [ESP + 0x20]
    s.si = m.r32((f.sp+0x00000020u));
  }
  { // 0x5f5c85: 8b5e08 MOV EBX,dword ptr [ESI + 0x8]
    s.bx = m.r32((s.si+0x00000008u));
  }
  { // 0x5f5c88: 8b6e0c MOV EBP,dword ptr [ESI + 0xc]
    s.bp = m.r32((s.si+0x0000000cu));
  }
  { // 0x5f5c8b: d3e0 SHL EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  { // 0x5f5c8d: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x5f5c90: 2be9 SUB EBP,ECX
    s.bp = integer::sub(s.bp,s.cx,32,flags);
  }
  { // 0x5f5c92: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  { // 0x5f5c96: 0bd0 OR EDX,EAX
    s.dx = integer::logical((s.dx)|(s.ax),32,flags);
  }
  { // 0x5f5c98: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x5f5c9a: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  { // 0x5f5c9c: 89542428 MOV dword ptr [ESP + 0x28],EDX
    m.w32((f.sp+0x00000028u), s.dx);
  }
  { // 0x5f5ca0: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x5f5ca2: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  { // 0x5f5ca6: 7506 JNZ 0x005f5cae
    if(integer::condition("JNZ",flags)) goto L005f5cae;
  }
  { // 0x5f5ca8: 8b3d306d8300 MOV EDI,dword ptr [0x00836d30]
    s.di = m.r32((0x00836d30u));
  }
  L005f5cae: { // 0x5f5cae: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x5f5cb0: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x5f5cb2: e859b6e3ff CALL 0x00431310
    s.arithmetic_flags=flags; invoke(m,s,f,0x00431310u,0x005f5cb7u); flags=0x202u; s.arithmetic_flags=flags;
  }
  { // 0x5f5cb7: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x5f5cb9: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f5cba: e861b6e3ff CALL 0x00431320
    s.arithmetic_flags=flags; invoke(m,s,f,0x00431320u,0x005f5cbfu); flags=0x202u; s.arithmetic_flags=flags;
  }
  { // 0x5f5cbf: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x5f5cc1: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  { // 0x5f5cc5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5f5cc6: e825b6e3ff CALL 0x004312f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004312f0u,0x005f5ccbu); flags=0x202u; s.arithmetic_flags=flags;
  }
  { // 0x5f5ccb: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  { // 0x5f5ccf: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  { // 0x5f5cd3: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  { // 0x5f5cd7: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5f5cd9: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5f5cdb: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5f5cdd: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x5f5cde: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5f5cdf: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5f5ce0: 8b4c2430 MOV ECX,dword ptr [ESP + 0x30]
    s.cx = m.r32((f.sp+0x00000030u));
  }
  { // 0x5f5ce4: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x5f5ce5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5f5ce6: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5f5ce7: 8b0d186d8300 MOV ECX,dword ptr [0x00836d18]
    s.cx = m.r32((0x00836d18u));
  }
  { // 0x5f5ced: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5f5cee: e85dc6e3ff CALL 0x00432350
    s.arithmetic_flags=flags; invoke(m,s,f,0x00432350u,0x005f5cf3u); flags=0x202u; s.arithmetic_flags=flags;
  }
  { // 0x5f5cf3: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x5f5cf5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5f5cf6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5f5cf7: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x5f5cf8: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5f5cf9: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x5f5cfc: c21000 RET 0x10
    finish(m,s,f,16u); return;
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
 case 0x00431370u:throw std::domain_error("B713 fixture excludes centered-rectangle helper path");
 case 0x00432350u:{State child=s;Frame cf{f.sp,f.sp,continuation};ra2::recovered::recovery_b707::fun_00432350(m,child,cf,Operations{});s=child;f.sp=cf.sp;return;}
 default:throw std::domain_error("B713 unreviewed direct call target");
 }
 for(unsigned k=0;k<q.arg.size();++k)m.w32(f.sp+4u+4u*k,q.arg[k]);
 if(m.r32(f.sp)!=continuation)throw std::runtime_error("B713 helper return address changed");
 f.sp+=4u+cleanup;
}
}
void fun_005f5c20(Memory&m,State&s,Frame&f,const Operations&op){f_001f5c20(m,s,f,op);}
} // namespace ra2::recovered::recovery_b713
