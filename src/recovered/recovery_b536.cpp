#include "recovered/recovery_b536_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b536 {
namespace {
void f_000cf180(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_000cf180(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004cf180: { // 0x4cf180: c6411c01 MOV byte ptr [ECX + 0x1c],0x1
    m.w8((s.cx+0x0000001cu), 0x00000001u);
  }
  L004cf184: { // 0x4cf184: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0036aa50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0076aa50: { // 0x76aa50: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L0076aa53: { // 0x76aa53: d93c24 FNSTCW word ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.control();
    m.w16(address,value);
  }
  L0076aa56: { // 0x76aa56: 8d442404 LEA EAX,[ESP + 0x4]
    s.ax = (f.sp+0x00000004u);
  }
  L0076aa5a: { // 0x76aa5a: 8b1424 MOV EDX,dword ptr [ESP]
    s.dx = m.r32((f.sp));
  }
  L0076aa5d: { // 0x76aa5d: 81e2ffff0000 AND EDX,0xffff
    s.dx = integer::logical((s.dx)&(0x0000ffffu),32,flags);
  }
  L0076aa63: { // 0x76aa63: 3b15043a7c00 CMP EDX,dword ptr [0x007c3a04]
    (void)integer::sub(s.dx,m.r32((0x007c3a04u)),32,flags);
  }
  L0076aa69: { // 0x76aa69: 750b JNZ 0x0076aa76
    if(integer::condition("JNZ",flags)) goto L0076aa76;
  }
  L0076aa6b: { // 0x76aa6b: df38 FISTP qword ptr [EAX]
    const auto address=(s.ax);
    const auto value=s.fp.pop_integer64();
    write64(m,address,value);
  }
  L0076aa6d: { // 0x76aa6d: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0076aa70: { // 0x76aa70: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0076aa72: { // 0x76aa72: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0076aa75: { // 0x76aa75: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076aa76: { // 0x76aa76: 8b15043a7c00 MOV EDX,dword ptr [0x007c3a04]
    s.dx = m.r32((0x007c3a04u));
  }
  L0076aa7c: { // 0x76aa7c: 891424 MOV dword ptr [ESP],EDX
    m.w32((f.sp), s.dx);
  }
  L0076aa7f: { // 0x76aa7f: d92c24 FLDCW word ptr [ESP]
    const auto address=(f.sp);
    s.fp.load_control(m.r16(address));
  }
  L0076aa82: { // 0x76aa82: df38 FISTP qword ptr [EAX]
    const auto address=(s.ax);
    const auto value=s.fp.pop_integer64();
    write64(m,address,value);
  }
  L0076aa84: { // 0x76aa84: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0076aa87: { // 0x76aa87: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0076aa89: { // 0x76aa89: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0076aa8c: { // 0x76aa8c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 5042560u:f_000cf180(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
default:throw std::domain_error("recovery536 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0067a0b0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0067a0b0: { // 0x67a0b0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0067a0b1: { // 0x67a0b1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0067a0b3: { // 0x67a0b3: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  L0067a0b7: { // 0x67a0b7: 8b4630 MOV EAX,dword ptr [ESI + 0x30]
    s.ax = m.r32((s.si+0x00000030u));
  }
  L0067a0ba: { // 0x67a0ba: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L0067a0bc: { // 0x67a0bc: 7d02 JGE 0x0067a0c0
    if(integer::condition("JGE",flags)) goto L0067a0c0;
  }
  L0067a0be: { // 0x67a0be: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0067a0c0: { // 0x67a0c0: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0067a0c3: { // 0x67a0c3: 894648 MOV dword ptr [ESI + 0x48],EAX
    m.w32((s.si+0x00000048u), s.ax);
  }
  L0067a0c6: { // 0x67a0c6: 7f05 JG 0x0067a0cd
    if(integer::condition("JG",flags)) goto L0067a0cd;
  }
  L0067a0c8: { // 0x67a0c8: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L0067a0cd: { // 0x67a0cd: 894648 MOV dword ptr [ESI + 0x48],EAX
    m.w32((s.si+0x00000048u), s.ax);
  }
  L0067a0d0: { // 0x67a0d0: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0067a0d2: { // 0x67a0d2: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0067a0d3: { // 0x67a0d3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0067a0d4: { // 0x67a0d4: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0067a0d6: { // 0x67a0d6: ff5048 CALL dword ptr [EAX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000048u)),6791385u); flags=s.arithmetic_flags;
  }
  L0067a0d9: { // 0x67a0d9: 8a462e MOV AL,byte ptr [ESI + 0x2e]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000002eu)));
  }
  L0067a0dc: { // 0x67a0dc: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0067a0de: { // 0x67a0de: 7405 JZ 0x0067a0e5
    if(integer::condition("JZ",flags)) goto L0067a0e5;
  }
  L0067a0e0: { // 0x67a0e0: 8b5e14 MOV EBX,dword ptr [ESI + 0x14]
    s.bx = m.r32((s.si+0x00000014u));
  }
  L0067a0e3: { // 0x67a0e3: eb03 JMP 0x0067a0e8
    goto L0067a0e8;
  }
  L0067a0e5: { // 0x67a0e5: 8b5e18 MOV EBX,dword ptr [ESI + 0x18]
    s.bx = m.r32((s.si+0x00000018u));
  }
  L0067a0e8: { // 0x67a0e8: db4630 FILD dword ptr [ESI + 0x30]
    const auto address=(s.si+0x00000030u);
    s.fp.load_integer32(m.r32(address));
  }
  L0067a0eb: { // 0x67a0eb: 895c2410 MOV dword ptr [ESP + 0x10],EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
  L0067a0ef: { // 0x67a0ef: db442410 FILD dword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load_integer32(m.r32(address));
  }
  L0067a0f3: { // 0x67a0f3: db4648 FILD dword ptr [ESI + 0x48]
    const auto address=(s.si+0x00000048u);
    s.fp.load_integer32(m.r32(address));
  }
  L0067a0f6: { // 0x67a0f6: d8f2 FDIV ST0,ST2
    numeric_b88::detail::reg<0xd8f2>(s.fp);
  }
  L0067a0f8: { // 0x67a0f8: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L0067a0fa: { // 0x67a0fa: e851090f00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6791423u); flags=s.arithmetic_flags;
  }
  L0067a0ff: { // 0x67a0ff: 83f804 CMP EAX,0x4
    (void)integer::sub(s.ax,0x00000004u,32,flags);
  }
  L0067a102: { // 0x67a102: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0067a104: { // 0x67a104: 7f05 JG 0x0067a10b
    if(integer::condition("JG",flags)) goto L0067a10b;
  }
  L0067a106: { // 0x67a106: bf04000000 MOV EDI,0x4
    s.di = 0x00000004u;
  }
  L0067a10b: { // 0x67a10b: db4634 FILD dword ptr [ESI + 0x34]
    const auto address=(s.si+0x00000034u);
    s.fp.load_integer32(m.r32(address));
  }
  L0067a10e: { // 0x67a10e: 897e4c MOV dword ptr [ESI + 0x4c],EDI
    m.w32((s.si+0x0000004cu), s.di);
  }
  L0067a111: { // 0x67a111: d8f2 FDIV ST0,ST2
    numeric_b88::detail::reg<0xd8f2>(s.fp);
  }
  L0067a113: { // 0x67a113: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L0067a115: { // 0x67a115: e836090f00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6791450u); flags=s.arithmetic_flags;
  }
  L0067a11a: { // 0x67a11a: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0067a11c: { // 0x67a11c: 2bcf SUB ECX,EDI
    s.cx = integer::sub(s.cx,s.di,32,flags);
  }
  L0067a11e: { // 0x67a11e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0067a11f: { // 0x67a11f: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0067a121: { // 0x67a121: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0067a123: { // 0x67a123: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0067a124: { // 0x67a124: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0067a126: { // 0x67a126: 7d07 JGE 0x0067a12f
    if(integer::condition("JGE",flags)) goto L0067a12f;
  }
  L0067a128: { // 0x67a128: 894650 MOV dword ptr [ESI + 0x50],EAX
    m.w32((s.si+0x00000050u), s.ax);
  }
  L0067a12b: { // 0x67a12b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0067a12c: { // 0x67a12c: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0067a12f: { // 0x67a12f: 894e50 MOV dword ptr [ESI + 0x50],ECX
    m.w32((s.si+0x00000050u), s.cx);
  }
  L0067a132: { // 0x67a132: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0067a133: { // 0x67a133: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
