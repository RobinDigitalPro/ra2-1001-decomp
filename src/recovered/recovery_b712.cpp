#include "recovered/recovery_b712.hpp"
#include "recovered/recovery_b711.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::recovery_b712 {
Result run(Memory& original,const floating_b61::Inputs&i){
 Memory m=original;
 constexpr std::uint32_t stack_base=0x7e100000u,entry_sp=stack_base+0x6004u,outer=0x76543211u;
 std::array<std::uint8_t,0x8000> bytes{};leaf::Memory stack(bytes.data(),stack_base,std::uint32_t(bytes.size()));m.add(stack);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{entry_sp,entry_sp,outer};m.w32(entry_sp,outer);for(unsigned k=0;k<i.arg.size();++k)m.w32(entry_sp+4u+4u*k,i.arg[k]);
 fun_00534f10(m,s,f,Operations{});
 if(f.sp!=entry_sp+4u+12u)throw std::runtime_error("text712 root RET 0xc stack cleanup mismatch");
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
#include "recovered/recovery_b712.hpp"
#include "recovered/recovery_b711.hpp"
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b712 {
using namespace ra2::recovered::recovery_b108;
namespace integer=direct_b33::integer;
namespace {
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);
void f_00134f10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x534f10: 83ec18 SUB ESP,0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
  { // 0x534f13: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  { // 0x534f17: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x534f18: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x534f19: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x534f1a: 8b7004 MOV ESI,dword ptr [EAX + 0x4]
    s.si = m.r32((s.ax+0x00000004u));
  }
  { // 0x534f1d: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x534f1f: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  { // 0x534f22: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  { // 0x534f24: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x534f26: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  { // 0x534f29: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  { // 0x534f2b: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  { // 0x534f2d: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  { // 0x534f31: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  { // 0x534f35: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  { // 0x534f39: 668b0de8b28300 MOV CX,word ptr [0x0083b2e8]
    s.cx = with_ax(s.cx, m.r16((0x0083b2e8u)));
  }
  { // 0x534f40: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  { // 0x534f44: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  { // 0x534f46: 66d3ea SHR DX,CL
    s.dx = with_ax(s.dx, integer::shift((s.dx & 0xffffu),(s.cx & 0xffu),16,flags,integer::Shift::right));
  }
  { // 0x534f49: 8b0decb28300 MOV ECX,dword ptr [0x0083b2ec]
    s.cx = m.r32((0x0083b2ecu));
  }
  { // 0x534f4f: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x534f51: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x534f53: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x534f55: 6a0c PUSH 0xc
    f.push(m,0x0000000cu);
  }
  { // 0x534f57: 89742428 MOV dword ptr [ESP + 0x28],ESI
    m.w32((f.sp+0x00000028u), s.si);
  }
  { // 0x534f5b: d2e2 SHL DL,CL
    s.dx = with_al(s.dx, integer::shift((s.dx & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::left));
  }
  { // 0x534f5d: 668b0df8b28300 MOV CX,word ptr [0x0083b2f8]
    s.cx = with_ax(s.cx, m.r16((0x0083b2f8u)));
  }
  { // 0x534f64: 8854241c MOV byte ptr [ESP + 0x1c],DL
    m.w8((f.sp+0x0000001cu), (s.dx & 0xffu));
  }
  { // 0x534f68: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  { // 0x534f6a: 66d3ea SHR DX,CL
    s.dx = with_ax(s.dx, integer::shift((s.dx & 0xffffu),(s.cx & 0xffu),16,flags,integer::Shift::right));
  }
  { // 0x534f6d: 8b0dfcb28300 MOV ECX,dword ptr [0x0083b2fc]
    s.cx = m.r32((0x0083b2fcu));
  }
  { // 0x534f73: d2e2 SHL DL,CL
    s.dx = with_al(s.dx, integer::shift((s.dx & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::left));
  }
  { // 0x534f75: 668b0df0b28300 MOV CX,word ptr [0x0083b2f0]
    s.cx = with_ax(s.cx, m.r16((0x0083b2f0u)));
  }
  { // 0x534f7c: 66d3e8 SHR AX,CL
    s.ax = with_ax(s.ax, integer::shift((s.ax & 0xffffu),(s.cx & 0xffu),16,flags,integer::Shift::right));
  }
  { // 0x534f7f: 8b0df4b28300 MOV ECX,dword ptr [0x0083b2f4]
    s.cx = m.r32((0x0083b2f4u));
  }
  { // 0x534f85: 8854241d MOV byte ptr [ESP + 0x1d],DL
    m.w8((f.sp+0x0000001du), (s.dx & 0xffu));
  }
  { // 0x534f89: d2e0 SHL AL,CL
    s.ax = with_al(s.ax, integer::shift((s.ax & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::left));
  }
  { // 0x534f8b: 8844241e MOV byte ptr [ESP + 0x1e],AL
    m.w8((f.sp+0x0000001eu), (s.ax & 0xffu));
  }
  { // 0x534f8f: 8b4c241e MOV ECX,dword ptr [ESP + 0x1e]
    s.cx = m.r32((f.sp+0x0000001eu));
  }
  { // 0x534f93: 8b54241d MOV EDX,dword ptr [ESP + 0x1d]
    s.dx = m.r32((f.sp+0x0000001du));
  }
  { // 0x534f97: 8b442440 MOV EAX,dword ptr [ESP + 0x40]
    s.ax = m.r32((f.sp+0x00000040u));
  }
  { // 0x534f9b: 81e1ff000000 AND ECX,0xff
    s.cx = integer::logical((s.cx)&(0x000000ffu),32,flags);
  }
  { // 0x534fa1: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  { // 0x534fa7: c1e108 SHL ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::left);
  }
  { // 0x534faa: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x534fab: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  { // 0x534faf: 0bca OR ECX,EDX
    s.cx = integer::logical((s.cx)|(s.dx),32,flags);
  }
  { // 0x534fb1: 25ff000000 AND EAX,0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  { // 0x534fb6: c1e108 SHL ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::left);
  }
  { // 0x534fb9: 0bc8 OR ECX,EAX
    s.cx = integer::logical((s.cx)|(s.ax),32,flags);
  }
  { // 0x534fbb: 8d542428 LEA EDX,[ESP + 0x28]
    s.dx = (f.sp+0x00000028u);
  }
  { // 0x534fbf: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x534fc0: 8b0d306d8300 MOV ECX,dword ptr [0x00836d30]
    s.cx = m.r32((0x00836d30u));
  }
  { // 0x534fc6: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x534fc7: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x534fc8: 8bd5 MOV EDX,EBP
    s.dx = s.bp;
  }
  { // 0x534fca: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x534fcc: e82f0d0c00 CALL 0x005f5d00
    s.arithmetic_flags=flags; invoke(m,s,f,0x005f5d00u,0x00534fd1u); flags=0x202u; s.arithmetic_flags=flags;
  }
  { // 0x534fd1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x534fd2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x534fd3: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x534fd4: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  { // 0x534fd7: c20c00 RET 0xc
    finish(m,s,f,12u); return;
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
 case 0x00431370u:throw std::domain_error("B712 fixture excludes centered-rectangle helper path");
 case 0x005f5d00u:{State child=s;Frame cf{f.sp,f.sp,continuation};ra2::recovered::recovery_b711::fun_005f5d00(m,child,cf,Operations{});s=child;f.sp=cf.sp;return;}
 default:throw std::domain_error("B712 unreviewed direct call target");
 }
 for(unsigned k=0;k<q.arg.size();++k)m.w32(f.sp+4u+4u*k,q.arg[k]);
 if(m.r32(f.sp)!=continuation)throw std::runtime_error("B712 helper return address changed");
 f.sp+=4u+cleanup;
}
}
void fun_00534f10(Memory&m,State&s,Frame&f,const Operations&op){f_00134f10(m,s,f,op);}
} // namespace ra2::recovered::recovery_b712
