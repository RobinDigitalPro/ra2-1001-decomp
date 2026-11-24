#include "recovered/recovery_b702_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b702 {
namespace {
void f_00011370(Memory&,State&,Frame&,const Operations&);
void f_000113b0(Memory&,State&,Frame&,const Operations&);
void f_000113c0(Memory&,State&,Frame&,const Operations&);
void f_000112c0(Memory&,State&,Frame&,const Operations&);
void f_000112d0(Memory&,State&,Frame&,const Operations&);
void f_00031ec0(Memory&,State&,Frame&,const Operations&);
void f_00053890(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_00011370(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00411370: { // 0x411370: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00411371: { // 0x411371: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00411372: { // 0x411372: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00411374: { // 0x411374: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00411375: { // 0x411375: 8b7e0c MOV EDI,dword ptr [ESI + 0xc]
    s.di = m.r32((s.si+0x0000000cu));
  }
  L00411378: { // 0x411378: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0041137a: { // 0x41137a: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0041137b: { // 0x41137b: 897e0c MOV dword ptr [ESI + 0xc],EDI
    m.w32((s.si+0x0000000cu), s.di);
  }
  L0041137e: { // 0x41137e: 8b7e14 MOV EDI,dword ptr [ESI + 0x14]
    s.di = m.r32((s.si+0x00000014u));
  }
  L00411381: { // 0x411381: ff5070 CALL dword ptr [EAX + 0x70]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000070u)),4264836u); flags=s.arithmetic_flags;
  }
  L00411384: { // 0x411384: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00411386: { // 0x411386: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00411388: { // 0x411388: 0faf5c2410 IMUL EBX,dword ptr [ESP + 0x10]
    s.bx = integer::imul(s.bx,m.r32((f.sp+0x00000010u)),32,flags);
  }
  L0041138d: { // 0x41138d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0041138f: { // 0x41138f: ff5274 CALL dword ptr [EDX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000074u)),4264850u); flags=s.arithmetic_flags;
  }
  L00411392: { // 0x411392: 0faf442414 IMUL EAX,dword ptr [ESP + 0x14]
    s.ax = integer::imul(s.ax,m.r32((f.sp+0x00000014u)),32,flags);
  }
  L00411397: { // 0x411397: 03fb ADD EDI,EBX
    s.di = integer::add(s.di,s.bx,32,flags);
  }
  L00411399: { // 0x411399: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L0041139b: { // 0x41139b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0041139c: { // 0x41139c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0041139d: { // 0x41139d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0041139e: { // 0x41139e: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_000113b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004113b0: { // 0x4113b0: 8b4110 MOV EAX,dword ptr [ECX + 0x10]
    s.ax = m.r32((s.cx+0x00000010u));
  }
  L004113b3: { // 0x4113b3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000113c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004113c0: { // 0x004113c0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004113c1: { // 0x004113c1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004113c3: { // 0x004113c3: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004113c5: { // 0x004113c5: ff507c CALL dword ptr [EAX + 0x7c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000007cu)),4264904u); flags=s.arithmetic_flags;
  }
  L004113c8: { // 0x004113c8: 0faf4610 IMUL EAX,dword ptr [ESI + 0x10]
    s.ax = integer::imul(s.ax,m.r32((s.si+0x00000010u)),32,flags);
  }
  L004113cc: { // 0x004113cc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004113cd: { // 0x004113cd: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000112c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004112c0: { // 0x4112c0: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L004112c3: { // 0x4112c3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000112d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004112d0: { // 0x4112d0: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L004112d3: { // 0x4112d3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00031ec0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00431ec0: { // 0x431ec0: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  L00431ec4: { // 0x431ec4: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  L00431ec8: { // 0x431ec8: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00431ec9: { // 0x431ec9: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L00431ecc: { // 0x431ecc: 8b720c MOV ESI,dword ptr [EDX + 0xc]
    s.si = m.r32((s.dx+0x0000000cu));
  }
  L00431ecf: { // 0x431ecf: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L00431ed1: { // 0x431ed1: 7f6f JG 0x00431f42
    if(integer::condition("JG",flags)) goto L00431f42;
  }
  L00431ed3: { // 0x431ed3: 8b4204 MOV EAX,dword ptr [EDX + 0x4]
    s.ax = m.r32((s.dx+0x00000004u));
  }
  L00431ed6: { // 0x431ed6: 8b710c MOV ESI,dword ptr [ECX + 0xc]
    s.si = m.r32((s.cx+0x0000000cu));
  }
  L00431ed9: { // 0x431ed9: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L00431edb: { // 0x431edb: 7f65 JG 0x00431f42
    if(integer::condition("JG",flags)) goto L00431f42;
  }
  L00431edd: { // 0x431edd: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00431edf: { // 0x431edf: 8b7208 MOV ESI,dword ptr [EDX + 0x8]
    s.si = m.r32((s.dx+0x00000008u));
  }
  L00431ee2: { // 0x431ee2: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L00431ee4: { // 0x431ee4: 7f5c JG 0x00431f42
    if(integer::condition("JG",flags)) goto L00431f42;
  }
  L00431ee6: { // 0x431ee6: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L00431ee8: { // 0x431ee8: 8b7108 MOV ESI,dword ptr [ECX + 0x8]
    s.si = m.r32((s.cx+0x00000008u));
  }
  L00431eeb: { // 0x431eeb: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L00431eed: { // 0x431eed: 7f53 JG 0x00431f42
    if(integer::condition("JG",flags)) goto L00431f42;
  }
  L00431eef: { // 0x431eef: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L00431ef3: { // 0x431ef3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00431ef4: { // 0x431ef4: 8b39 MOV EDI,dword ptr [ECX]
    s.di = m.r32((s.cx));
  }
  L00431ef6: { // 0x431ef6: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00431ef8: { // 0x431ef8: 893e MOV dword ptr [ESI],EDI
    m.w32((s.si), s.di);
  }
  L00431efa: { // 0x431efa: 8b7904 MOV EDI,dword ptr [ECX + 0x4]
    s.di = m.r32((s.cx+0x00000004u));
  }
  L00431efd: { // 0x431efd: 897e04 MOV dword ptr [ESI + 0x4],EDI
    m.w32((s.si+0x00000004u), s.di);
  }
  L00431f00: { // 0x431f00: 8b7908 MOV EDI,dword ptr [ECX + 0x8]
    s.di = m.r32((s.cx+0x00000008u));
  }
  L00431f03: { // 0x431f03: 897e08 MOV dword ptr [ESI + 0x8],EDI
    m.w32((s.si+0x00000008u), s.di);
  }
  L00431f06: { // 0x431f06: 8b490c MOV ECX,dword ptr [ECX + 0xc]
    s.cx = m.r32((s.cx+0x0000000cu));
  }
  L00431f09: { // 0x431f09: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00431f0a: { // 0x431f0a: 894e0c MOV dword ptr [ESI + 0xc],ECX
    m.w32((s.si+0x0000000cu), s.cx);
  }
  L00431f0d: { // 0x431f0d: 8b4a04 MOV ECX,dword ptr [EDX + 0x4]
    s.cx = m.r32((s.dx+0x00000004u));
  }
  L00431f10: { // 0x431f10: 394804 CMP dword ptr [EAX + 0x4],ECX
    (void)integer::sub(m.r32((s.ax+0x00000004u)),s.cx,32,flags);
  }
  L00431f13: { // 0x431f13: 7d03 JGE 0x00431f18
    if(integer::condition("JGE",flags)) goto L00431f18;
  }
  L00431f15: { // 0x431f15: 894804 MOV dword ptr [EAX + 0x4],ECX
    m.w32((s.ax+0x00000004u), s.cx);
  }
  L00431f18: { // 0x431f18: 8b0a MOV ECX,dword ptr [EDX]
    s.cx = m.r32((s.dx));
  }
  L00431f1a: { // 0x431f1a: 8b30 MOV ESI,dword ptr [EAX]
    s.si = m.r32((s.ax));
  }
  L00431f1c: { // 0x431f1c: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L00431f1e: { // 0x431f1e: 7d02 JGE 0x00431f22
    if(integer::condition("JGE",flags)) goto L00431f22;
  }
  L00431f20: { // 0x431f20: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L00431f22: { // 0x431f22: 8b4a0c MOV ECX,dword ptr [EDX + 0xc]
    s.cx = m.r32((s.dx+0x0000000cu));
  }
  L00431f25: { // 0x431f25: 8b700c MOV ESI,dword ptr [EAX + 0xc]
    s.si = m.r32((s.ax+0x0000000cu));
  }
  L00431f28: { // 0x431f28: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L00431f2a: { // 0x431f2a: 7e03 JLE 0x00431f2f
    if(integer::condition("JLE",flags)) goto L00431f2f;
  }
  L00431f2c: { // 0x431f2c: 89480c MOV dword ptr [EAX + 0xc],ECX
    m.w32((s.ax+0x0000000cu), s.cx);
  }
  L00431f2f: { // 0x431f2f: 8b5208 MOV EDX,dword ptr [EDX + 0x8]
    s.dx = m.r32((s.dx+0x00000008u));
  }
  L00431f32: { // 0x431f32: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L00431f35: { // 0x431f35: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L00431f37: { // 0x431f37: 7e03 JLE 0x00431f3c
    if(integer::condition("JLE",flags)) goto L00431f3c;
  }
  L00431f39: { // 0x431f39: 895008 MOV dword ptr [EAX + 0x8],EDX
    m.w32((s.ax+0x00000008u), s.dx);
  }
  L00431f3c: { // 0x431f3c: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00431f3e: { // 0x431f3e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00431f3f: { // 0x431f3f: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L00431f42: { // 0x431f42: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L00431f46: { // 0x431f46: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  L00431f49: { // 0x431f49: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00431f4a: { // 0x431f4a: c70000000000 MOV dword ptr [EAX],0x0
    m.w32((s.ax), 0x00000000u);
  }
  L00431f50: { // 0x431f50: c7400400000000 MOV dword ptr [EAX + 0x4],0x0
    m.w32((s.ax+0x00000004u), 0x00000000u);
  }
  L00431f57: { // 0x431f57: 894808 MOV dword ptr [EAX + 0x8],ECX
    m.w32((s.ax+0x00000008u), s.cx);
  }
  L00431f5a: { // 0x431f5a: 89480c MOV dword ptr [EAX + 0xc],ECX
    m.w32((s.ax+0x0000000cu), s.cx);
  }
  L00431f5d: { // 0x431f5d: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00431f5f: { // 0x431f5f: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
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
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4264816u:f_00011370(m,s,child,{});break;
case 4264880u:f_000113b0(m,s,child,{});break;
case 4264896u:f_000113c0(m,s,child,{});break;
case 4264640u:f_000112c0(m,s,child,{});break;
case 4264656u:f_000112d0(m,s,child,{});break;
case 4398784u:f_00031ec0(m,s,child,{});break;
case 4536464u:f_00053890(m,s,child,{});break;
default:throw std::domain_error("recovery702 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00431f70(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00431f70: { // 0x431f70: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L00431f73: { // 0x431f73: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00431f74: { // 0x431f74: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00431f75: { // 0x431f75: 8b7c241c MOV EDI,dword ptr [ESP + 0x1c]
    s.di = m.r32((f.sp+0x0000001cu));
  }
  L00431f79: { // 0x431f79: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00431f7b: { // 0x431f7b: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00431f7d: { // 0x431f7d: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00431f7f: { // 0x431f7f: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L00431f81: { // 0x431f81: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00431f82: { // 0x431f82: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00431f83: { // 0x431f83: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00431f85: { // 0x431f85: ff525c CALL dword ptr [EDX + 0x5c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000005cu)),4398984u); flags=s.arithmetic_flags;
  }
  L00431f88: { // 0x431f88: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  L00431f8b: { // 0x431f8b: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L00431f8d: { // 0x431f8d: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00431f8f: { // 0x431f8f: ff5074 CALL dword ptr [EAX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000074u)),4398994u); flags=s.arithmetic_flags;
  }
  L00431f92: { // 0x431f92: d1e8 SHR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::right);
  }
  L00431f94: { // 0x431f94: 894610 MOV dword ptr [ESI + 0x10],EAX
    m.w32((s.si+0x00000010u), s.ax);
  }
  L00431f97: { // 0x431f97: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L00431f99: { // 0x431f99: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00431f9b: { // 0x431f9b: c744240800000000 MOV dword ptr [ESP + 0x8],0x0
    m.w32((f.sp+0x00000008u), 0x00000000u);
  }
  L00431fa3: { // 0x431fa3: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  L00431fab: { // 0x431fab: ff527c CALL dword ptr [EDX + 0x7c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000007cu)),4399022u); flags=s.arithmetic_flags;
  }
  L00431fae: { // 0x431fae: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00431faf: { // 0x431faf: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00431fb1: { // 0x431fb1: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00431fb5: { // 0x431fb5: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L00431fb7: { // 0x431fb7: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),4399037u); flags=s.arithmetic_flags;
  }
  L00431fbd: { // 0x431fbd: 8b5638 MOV EDX,dword ptr [ESI + 0x38]
    s.dx = m.r32((s.si+0x00000038u));
  }
  L00431fc0: { // 0x431fc0: 8b7e3c MOV EDI,dword ptr [ESI + 0x3c]
    s.di = m.r32((s.si+0x0000003cu));
  }
  L00431fc3: { // 0x431fc3: 0bd7 OR EDX,EDI
    s.dx = integer::logical((s.dx)|(s.di),32,flags);
  }
  L00431fc5: { // 0x431fc5: 8b7e34 MOV EDI,dword ptr [ESI + 0x34]
    s.di = m.r32((s.si+0x00000034u));
  }
  L00431fc8: { // 0x431fc8: 8d4e30 LEA ECX,[ESI + 0x30]
    s.cx = (s.si+0x00000030u);
  }
  L00431fcb: { // 0x431fcb: 0bd7 OR EDX,EDI
    s.dx = integer::logical((s.dx)|(s.di),32,flags);
  }
  L00431fcd: { // 0x431fcd: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00431fce: { // 0x431fce: 8b39 MOV EDI,dword ptr [ECX]
    s.di = m.r32((s.cx));
  }
  L00431fd0: { // 0x431fd0: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00431fd4: { // 0x431fd4: 0bd7 OR EDX,EDI
    s.dx = integer::logical((s.dx)|(s.di),32,flags);
  }
  L00431fd6: { // 0x431fd6: 751f JNZ 0x00431ff7
    if(integer::condition("JNZ",flags)) goto L00431ff7;
  }
  L00431fd8: { // 0x431fd8: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L00431fdc: { // 0x431fdc: 89463c MOV dword ptr [ESI + 0x3c],EAX
    m.w32((s.si+0x0000003cu), s.ax);
  }
  L00431fdf: { // 0x431fdf: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  L00431fe1: { // 0x431fe1: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L00431fe5: { // 0x431fe5: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00431fe9: { // 0x431fe9: 894e34 MOV dword ptr [ESI + 0x34],ECX
    m.w32((s.si+0x00000034u), s.cx);
  }
  L00431fec: { // 0x431fec: 895638 MOV dword ptr [ESI + 0x38],EDX
    m.w32((s.si+0x00000038u), s.dx);
  }
  L00431fef: { // 0x431fef: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00431ff0: { // 0x431ff0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00431ff1: { // 0x431ff1: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00431ff4: { // 0x431ff4: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00431ff7: { // 0x431ff7: 8d442408 LEA EAX,[ESP + 0x8]
    s.ax = (f.sp+0x00000008u);
  }
  L00431ffb: { // 0x431ffb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00431ffc: { // 0x431ffc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00431ffd: { // 0x431ffd: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00431ffe: { // 0x431ffe: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00432000: { // 0x432000: e8bbfeffff CALL 0x00431ec0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00431ec0u,4399109u); flags=s.arithmetic_flags;
  }
  L00432005: { // 0x432005: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00432006: { // 0x432006: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00432007: { // 0x432007: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0043200a: { // 0x43200a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_005cc7f0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005cc7f0: { // 0x5cc7f0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005cc7f1: { // 0x5cc7f1: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005cc7f2: { // 0x5cc7f2: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L005cc7f4: { // 0x5cc7f4: 8a4676 MOV AL,byte ptr [ESI + 0x76]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000076u)));
  }
  L005cc7f7: { // 0x5cc7f7: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cc7f9: { // 0x5cc7f9: 0f85b8000000 JNZ 0x005cc8b7
    if(integer::condition("JNZ",flags)) goto L005cc8b7;
  }
  L005cc7ff: { // 0x5cc7ff: 8b5c240c MOV EBX,dword ptr [ESP + 0xc]
    s.bx = m.r32((f.sp+0x0000000cu));
  }
  L005cc803: { // 0x5cc803: 83fb02 CMP EBX,0x2
    (void)integer::sub(s.bx,0x00000002u,32,flags);
  }
  L005cc806: { // 0x5cc806: 7525 JNZ 0x005cc82d
    if(integer::condition("JNZ",flags)) goto L005cc82d;
  }
  L005cc808: { // 0x5cc808: 8a4675 MOV AL,byte ptr [ESI + 0x75]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000075u)));
  }
  L005cc80b: { // 0x5cc80b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cc80d: { // 0x5cc80d: 0f85a4000000 JNZ 0x005cc8b7
    if(integer::condition("JNZ",flags)) goto L005cc8b7;
  }
  L005cc813: { // 0x5cc813: 8a4674 MOV AL,byte ptr [ESI + 0x74]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000074u)));
  }
  L005cc816: { // 0x5cc816: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cc818: { // 0x5cc818: 0f8499000000 JZ 0x005cc8b7
    if(integer::condition("JZ",flags)) goto L005cc8b7;
  }
  L005cc81e: { // 0x5cc81e: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005cc820: { // 0x5cc820: ff902c010000 CALL dword ptr [EAX + 0x12c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000012cu)),6080550u); flags=s.arithmetic_flags;
  }
  L005cc826: { // 0x5cc826: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005cc827: { // 0x5cc827: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L005cc829: { // 0x5cc829: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005cc82a: { // 0x5cc82a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005cc82d: { // 0x5cc82d: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005cc82f: { // 0x5cc82f: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005cc830: { // 0x5cc830: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cc832: { // 0x5cc832: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),6080565u); flags=s.arithmetic_flags;
  }
  L005cc835: { // 0x5cc835: 83f806 CMP EAX,0x6
    (void)integer::sub(s.ax,0x00000006u,32,flags);
  }
  L005cc838: { // 0x5cc838: 7514 JNZ 0x005cc84e
    if(integer::condition("JNZ",flags)) goto L005cc84e;
  }
  L005cc83a: { // 0x5cc83a: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L005cc840: { // 0x5cc840: 8b88f00b0000 MOV ECX,dword ptr [EAX + 0xbf0]
    s.cx = m.r32((s.ax+0x00000bf0u));
  }
  L005cc846: { // 0x5cc846: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005cc848: { // 0x5cc848: 7404 JZ 0x005cc84e
    if(integer::condition("JZ",flags)) goto L005cc84e;
  }
  L005cc84a: { // 0x5cc84a: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L005cc84c: { // 0x5cc84c: 742d JZ 0x005cc87b
    if(integer::condition("JZ",flags)) goto L005cc87b;
  }
  L005cc84e: { // 0x5cc84e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cc850: { // 0x5cc850: e8cb13e4ff CALL 0x0040dc20
    s.arithmetic_flags=flags; invoke(m,s,f,0x0040dc20u,6080597u); flags=s.arithmetic_flags;
  }
  L005cc855: { // 0x5cc855: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L005cc857: { // 0x5cc857: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L005cc859: { // 0x5cc859: 7420 JZ 0x005cc87b
    if(integer::condition("JZ",flags)) goto L005cc87b;
  }
  L005cc85b: { // 0x5cc85b: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L005cc85d: { // 0x5cc85d: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005cc85f: { // 0x5cc85f: ff92a0020000 CALL dword ptr [EDX + 0x2a0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000002a0u)),6080613u); flags=s.arithmetic_flags;
  }
  L005cc865: { // 0x5cc865: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L005cc867: { // 0x5cc867: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005cc869: { // 0x5cc869: ff5038 CALL dword ptr [EAX + 0x38]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000038u)),6080620u); flags=s.arithmetic_flags;
  }
  L005cc86c: { // 0x5cc86c: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005cc86e: { // 0x5cc86e: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L005cc872: { // 0x5cc872: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005cc873: { // 0x5cc873: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cc875: { // 0x5cc875: ff92a0010000 CALL dword ptr [EDX + 0x1a0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001a0u)),6080635u); flags=s.arithmetic_flags;
  }
  L005cc87b: { // 0x5cc87b: 83fb01 CMP EBX,0x1
    (void)integer::sub(s.bx,0x00000001u,32,flags);
  }
  L005cc87e: { // 0x5cc87e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005cc87f: { // 0x5cc87f: 7405 JZ 0x005cc886
    if(integer::condition("JZ",flags)) goto L005cc886;
  }
  L005cc881: { // 0x5cc881: 83fb03 CMP EBX,0x3
    (void)integer::sub(s.bx,0x00000003u,32,flags);
  }
  L005cc884: { // 0x5cc884: 751c JNZ 0x005cc8a2
    if(integer::condition("JNZ",flags)) goto L005cc8a2;
  }
  L005cc886: { // 0x5cc886: 8a4674 MOV AL,byte ptr [ESI + 0x74]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000074u)));
  }
  L005cc889: { // 0x5cc889: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cc88b: { // 0x5cc88b: 7515 JNZ 0x005cc8a2
    if(integer::condition("JNZ",flags)) goto L005cc8a2;
  }
  L005cc88d: { // 0x5cc88d: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005cc88f: { // 0x5cc88f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cc891: { // 0x5cc891: c6467401 MOV byte ptr [ESI + 0x74],0x1
    m.w8((s.si+0x00000074u), 0x00000001u);
  }
  L005cc895: { // 0x5cc895: ff922c010000 CALL dword ptr [EDX + 0x12c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000012cu)),6080667u); flags=s.arithmetic_flags;
  }
  L005cc89b: { // 0x5cc89b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005cc89c: { // 0x5cc89c: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L005cc89e: { // 0x5cc89e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005cc89f: { // 0x5cc89f: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005cc8a2: { // 0x5cc8a2: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L005cc8a4: { // 0x5cc8a4: 7511 JNZ 0x005cc8b7
    if(integer::condition("JNZ",flags)) goto L005cc8b7;
  }
  L005cc8a6: { // 0x5cc8a6: 8a4674 MOV AL,byte ptr [ESI + 0x74]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000074u)));
  }
  L005cc8a9: { // 0x5cc8a9: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cc8ab: { // 0x5cc8ab: 740a JZ 0x005cc8b7
    if(integer::condition("JZ",flags)) goto L005cc8b7;
  }
  L005cc8ad: { // 0x5cc8ad: 885e74 MOV byte ptr [ESI + 0x74],BL
    m.w8((s.si+0x00000074u), (s.bx & 0xffu));
  }
  L005cc8b0: { // 0x5cc8b0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005cc8b1: { // 0x5cc8b1: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L005cc8b3: { // 0x5cc8b3: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005cc8b4: { // 0x5cc8b4: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005cc8b7: { // 0x5cc8b7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005cc8b8: { // 0x5cc8b8: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L005cc8ba: { // 0x5cc8ba: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005cc8bb: { // 0x5cc8bb: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
