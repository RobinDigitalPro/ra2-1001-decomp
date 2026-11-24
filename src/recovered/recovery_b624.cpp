#include "platform/observed_enum624.hpp"
#include "recovered/recovery_b624_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b624 {
namespace {
void f_00092500(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_00092500(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00492500: { // 0x492500: 8b442404 MOV EAX, dword ptr [ESP + 4]
    s.ax = m.r32((f.sp+4u));
  }
  L00492504: { // 0x492504: 8b154467a500 MOV EDX, dword ptr [0xa56744]
    s.dx = m.r32((0x00a56744u));
  }
  L0049250a: { // 0x49250a: 83c014 ADD EAX, 0x14
    s.ax = integer::add(s.ax,0x00000014u,32,flags);
  }
  L0049250d: { // 0x49250d: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L0049250e: { // 0x49250e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049250f: { // 0x49250f: 89154467a500 MOV dword ptr [0xa56744], EDX
    m.w32((0x00a56744u), s.dx);
  }
  L00492515: { // 0x492515: ff15bc517800 CALL dword ptr [0x7851bc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((0x007851bcu)),4793627u); flags=s.arithmetic_flags;
  }
  L0049251b: { // 0x49251b: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4793600u:f_00092500(m,s,child,{});break;
default:{if(target!=ra2::platform::enum624::References::address())throw std::domain_error("624 unreviewed API");s.ax=ra2::platform::enum624::References::guest_call(m.r32(child.sp+4));child.sp+=8;break;}}
f.sp=child.sp;
}
}

std::uint32_t fun_00492a30(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00492a30: { // 0x492a30: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00492a31: { // 0x492a31: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L00492a35: { // 0x492a35: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L00492a37: { // 0x492a37: 7509 JNZ 0x00492a42
    if(integer::condition("JNZ",flags)) goto L00492a42;
  }
  L00492a39: { // 0x492a39: b803400080 MOV EAX,0x80004003
    s.ax = 0x80004003u;
  }
  L00492a3e: { // 0x492a3e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00492a3f: { // 0x492a3f: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00492a42: { // 0x492a42: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L00492a46: { // 0x492a46: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L00492a4a: { // 0x492a4a: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L00492a4d: { // 0x492a4d: 760d JBE 0x00492a5c
    if(integer::condition("JBE",flags)) goto L00492a5c;
  }
  L00492a4f: { // 0x492a4f: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00492a51: { // 0x492a51: 750d JNZ 0x00492a60
    if(integer::condition("JNZ",flags)) goto L00492a60;
  }
  L00492a53: { // 0x492a53: b803400080 MOV EAX,0x80004003
    s.ax = 0x80004003u;
  }
  L00492a58: { // 0x492a58: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00492a59: { // 0x492a59: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00492a5c: { // 0x492a5c: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00492a5e: { // 0x492a5e: 740a JZ 0x00492a6a
    if(integer::condition("JZ",flags)) goto L00492a6a;
  }
  L00492a60: { // 0x492a60: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L00492a64: { // 0x492a64: c70100000000 MOV dword ptr [ECX],0x0
    m.w32((s.cx), 0x00000000u);
  }
  L00492a6a: { // 0x492a6a: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00492a6b: { // 0x492a6b: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00492a6c: { // 0x492a6c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00492a6d: { // 0x492a6d: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L00492a6f: { // 0x492a6f: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00492a71: { // 0x492a71: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00492a73: { // 0x492a73: 7639 JBE 0x00492aae
    if(integer::condition("JBE",flags)) goto L00492aae;
  }
  L00492a75: { // 0x492a75: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L00492a79: { // 0x492a79: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L00492a7c: { // 0x492a7c: 8b4e1c MOV ECX,dword ptr [ESI + 0x1c]
    s.cx = m.r32((s.si+0x0000001cu));
  }
  L00492a7f: { // 0x492a7f: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00492a81: { // 0x492a81: 7d2b JGE 0x00492aae
    if(integer::condition("JGE",flags)) goto L00492aae;
  }
  L00492a83: { // 0x492a83: 8b5610 MOV EDX,dword ptr [ESI + 0x10]
    s.dx = m.r32((s.si+0x00000010u));
  }
  L00492a86: { // 0x492a86: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L00492a89: { // 0x492a89: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00492a8a: { // 0x492a8a: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00492a8c: { // 0x492a8c: ff5104 CALL dword ptr [ECX + 0x4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+0x00000004u)),4795023u); flags=s.arithmetic_flags;
  }
  L00492a8f: { // 0x492a8f: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L00492a92: { // 0x492a92: 83c304 ADD EBX,0x4
    s.bx = integer::add(s.bx,0x00000004u,32,flags);
  }
  L00492a95: { // 0x492a95: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L00492a96: { // 0x492a96: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L00492a97: { // 0x492a97: 8d5001 LEA EDX,[EAX + 0x1]
    s.dx = (s.ax+0x00000001u);
  }
  L00492a9a: { // 0x492a9a: 895604 MOV dword ptr [ESI + 0x4],EDX
    m.w32((s.si+0x00000004u), s.dx);
  }
  L00492a9d: { // 0x492a9d: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    s.cx = m.r32((s.si+0x00000010u));
  }
  L00492aa0: { // 0x492aa0: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L00492aa3: { // 0x492aa3: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00492aa7: { // 0x492aa7: 8953fc MOV dword ptr [EBX + -0x4],EDX
    m.w32((s.bx-0x00000004u), s.dx);
  }
  L00492aaa: { // 0x492aaa: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L00492aac: { // 0x492aac: 72cb JC 0x00492a79
    if(integer::condition("JC",flags)) goto L00492a79;
  }
  L00492aae: { // 0x492aae: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L00492ab2: { // 0x492ab2: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00492ab4: { // 0x492ab4: 7402 JZ 0x00492ab8
    if(integer::condition("JZ",flags)) goto L00492ab8;
  }
  L00492ab6: { // 0x492ab6: 8928 MOV dword ptr [EAX],EBP
    m.w32((s.ax), s.bp);
  }
  L00492ab8: { // 0x492ab8: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L00492aba: { // 0x492aba: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00492abb: { // 0x492abb: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L00492abd: { // 0x492abd: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  L00492abf: { // 0x492abf: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00492ac0: { // 0x492ac0: 25fbbfff7f AND EAX,0x7fffbffb
    s.ax = integer::logical((s.ax)&(0x7fffbffbu),32,flags);
  }
  L00492ac5: { // 0x492ac5: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00492ac6: { // 0x492ac6: 0505400080 ADD EAX,0x80004005
    s.ax = integer::add(s.ax,0x80004005u,32,flags);
  }
  L00492acb: { // 0x492acb: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00492acc: { // 0x492acc: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
