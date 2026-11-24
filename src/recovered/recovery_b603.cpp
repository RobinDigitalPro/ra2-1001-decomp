#include "recovered/recovery_b603_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b603 {
namespace {
void f_0000cdf0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_0000cdf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0040cdf0: { // 0x40cdf0: 8b5110 MOV EDX, dword ptr [ECX + 0x10]
    s.dx = m.r32((s.cx+0x00000010u));
  }
  L0040cdf3: { // 0x40cdf3: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0040cdf5: { // 0x40cdf5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0040cdf6: { // 0x40cdf6: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0040cdf8: { // 0x40cdf8: 7e15 JLE 0x40ce0f
    if(integer::condition("JLE",flags)) goto L0040ce0f;
  }
  L0040cdfa: { // 0x40cdfa: 8b742408 MOV ESI, dword ptr [ESP + 8]
    s.si = m.r32((f.sp+8u));
  }
  L0040cdfe: { // 0x40cdfe: 8b4904 MOV ECX, dword ptr [ECX + 4]
    s.cx = m.r32((s.cx+4u));
  }
  L0040ce01: { // 0x40ce01: 8b36 MOV ESI, dword ptr [ESI]
    s.si = m.r32((s.si));
  }
  L0040ce03: { // 0x40ce03: 3931 CMP dword ptr [ECX], ESI
    (void)integer::sub(m.r32((s.cx)),s.si,32,flags);
  }
  L0040ce05: { // 0x40ce05: 740b JZ 0x40ce12
    if(integer::condition("JZ",flags)) goto L0040ce12;
  }
  L0040ce07: { // 0x40ce07: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0040ce08: { // 0x40ce08: 83c104 ADD ECX, 4
    s.cx = integer::add(s.cx,4u,32,flags);
  }
  L0040ce0b: { // 0x40ce0b: 3bc2 CMP EAX, EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0040ce0d: { // 0x40ce0d: 7cf4 JL 0x40ce03
    if(integer::condition("JL",flags)) goto L0040ce03;
  }
  L0040ce0f: { // 0x40ce0f: 83c8ff OR EAX, 0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L0040ce12: { // 0x40ce12: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0040ce13: { // 0x40ce13: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4247024u:f_0000cdf0(m,s,child,{});break;
default:throw std::domain_error("recovery603 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00436590(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00436590: { // 0x436590: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00436591: { // 0x436591: 8b5c2408 MOV EBX,dword ptr [ESP + 0x8]
    s.bx = m.r32((f.sp+0x00000008u));
  }
  L00436595: { // 0x436595: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00436596: { // 0x436596: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00436598: { // 0x436598: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  L0043659c: { // 0x43659c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0043659d: { // 0x43659d: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0043659f: { // 0x43659f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004365a0: { // 0x4365a0: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004365a2: { // 0x4365a2: 895c2414 MOV dword ptr [ESP + 0x14],EBX
    m.w32((f.sp+0x00000014u), s.bx);
  }
  L004365a6: { // 0x4365a6: ff5010 CALL dword ptr [EAX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000010u)),4416937u); flags=s.arithmetic_flags;
  }
  L004365a9: { // 0x4365a9: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L004365ac: { // 0x4365ac: 7421 JZ 0x004365cf
    if(integer::condition("JZ",flags)) goto L004365cf;
  }
  L004365ae: { // 0x4365ae: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    s.cx = m.r32((s.si+0x00000010u));
  }
  L004365b1: { // 0x4365b1: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L004365b3: { // 0x4365b3: 7d1a JGE 0x004365cf
    if(integer::condition("JGE",flags)) goto L004365cf;
  }
  L004365b5: { // 0x4365b5: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L004365b6: { // 0x4365b6: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L004365b8: { // 0x4365b8: 894e10 MOV dword ptr [ESI + 0x10],ECX
    m.w32((s.si+0x00000010u), s.cx);
  }
  L004365bb: { // 0x4365bb: 7d12 JGE 0x004365cf
    if(integer::condition("JGE",flags)) goto L004365cf;
  }
  L004365bd: { // 0x4365bd: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  L004365c0: { // 0x4365c0: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004365c1: { // 0x4365c1: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L004365c4: { // 0x4365c4: 895481fc MOV dword ptr [ECX + EAX*0x4 + -0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)-0x00000004u), s.dx);
  }
  L004365c8: { // 0x4365c8: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    s.cx = m.r32((s.si+0x00000010u));
  }
  L004365cb: { // 0x4365cb: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L004365cd: { // 0x4365cd: 7cee JL 0x004365bd
    if(integer::condition("JL",flags)) goto L004365bd;
  }
  L004365cf: { // 0x4365cf: 8b4618 MOV EAX,dword ptr [ESI + 0x18]
    s.ax = m.r32((s.si+0x00000018u));
  }
  L004365d2: { // 0x4365d2: 8d7e18 LEA EDI,[ESI + 0x18]
    s.di = (s.si+0x00000018u);
  }
  L004365d5: { // 0x4365d5: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L004365d9: { // 0x4365d9: 895c2410 MOV dword ptr [ESP + 0x10],EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
  L004365dd: { // 0x4365dd: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004365de: { // 0x4365de: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L004365e0: { // 0x4365e0: ff5010 CALL dword ptr [EAX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000010u)),4416995u); flags=s.arithmetic_flags;
  }
  L004365e3: { // 0x4365e3: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L004365e6: { // 0x4365e6: 7421 JZ 0x00436609
    if(integer::condition("JZ",flags)) goto L00436609;
  }
  L004365e8: { // 0x4365e8: 8b4f10 MOV ECX,dword ptr [EDI + 0x10]
    s.cx = m.r32((s.di+0x00000010u));
  }
  L004365eb: { // 0x4365eb: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L004365ed: { // 0x4365ed: 7d1a JGE 0x00436609
    if(integer::condition("JGE",flags)) goto L00436609;
  }
  L004365ef: { // 0x4365ef: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L004365f0: { // 0x4365f0: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L004365f2: { // 0x4365f2: 894f10 MOV dword ptr [EDI + 0x10],ECX
    m.w32((s.di+0x00000010u), s.cx);
  }
  L004365f5: { // 0x4365f5: 7d12 JGE 0x00436609
    if(integer::condition("JGE",flags)) goto L00436609;
  }
  L004365f7: { // 0x4365f7: 8b4f04 MOV ECX,dword ptr [EDI + 0x4]
    s.cx = m.r32((s.di+0x00000004u));
  }
  L004365fa: { // 0x4365fa: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004365fb: { // 0x4365fb: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L004365fe: { // 0x4365fe: 895481fc MOV dword ptr [ECX + EAX*0x4 + -0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)-0x00000004u), s.dx);
  }
  L00436602: { // 0x436602: 8b4f10 MOV ECX,dword ptr [EDI + 0x10]
    s.cx = m.r32((s.di+0x00000010u));
  }
  L00436605: { // 0x436605: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00436607: { // 0x436607: 7cee JL 0x004365f7
    if(integer::condition("JL",flags)) goto L004365f7;
  }
  L00436609: { // 0x436609: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L0043660c: { // 0x43660c: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0043660e: { // 0x43660e: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00436610: { // 0x436610: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00436612: { // 0x436612: 7e1a JLE 0x0043662e
    if(integer::condition("JLE",flags)) goto L0043662e;
  }
  L00436614: { // 0x436614: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L00436617: { // 0x436617: 8b0488 MOV EAX,dword ptr [EAX + ECX*0x4]
    s.ax = m.r32((s.ax+(s.cx * 0x00000004u)));
  }
  L0043661a: { // 0x43661a: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0043661c: { // 0x43661c: 7408 JZ 0x00436626
    if(integer::condition("JZ",flags)) goto L00436626;
  }
  L0043661e: { // 0x43661e: 395824 CMP dword ptr [EAX + 0x24],EBX
    (void)integer::sub(m.r32((s.ax+0x00000024u)),s.bx,32,flags);
  }
  L00436621: { // 0x436621: 7503 JNZ 0x00436626
    if(integer::condition("JNZ",flags)) goto L00436626;
  }
  L00436623: { // 0x436623: 895024 MOV dword ptr [EAX + 0x24],EDX
    m.w32((s.ax+0x00000024u), s.dx);
  }
  L00436626: { // 0x436626: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L00436629: { // 0x436629: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0043662a: { // 0x43662a: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L0043662c: { // 0x43662c: 7ce6 JL 0x00436614
    if(integer::condition("JL",flags)) goto L00436614;
  }
  L0043662e: { // 0x43662e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0043662f: { // 0x43662f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00436630: { // 0x436630: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00436631: { // 0x436631: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00499870(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00499870: { // 0x499870: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00499871: { // 0x499871: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00499872: { // 0x499872: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  L00499876: { // 0x499876: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L00499878: { // 0x499878: 0f84b8000000 JZ 0x00499936
    if(integer::condition("JZ",flags)) goto L00499936;
  }
  L0049987e: { // 0x49987e: 8b8780000000 MOV EAX,dword ptr [EDI + 0x80]
    s.ax = m.r32((s.di+0x00000080u));
  }
  L00499884: { // 0x499884: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00499887: { // 0x499887: 0f84a9000000 JZ 0x00499936
    if(integer::condition("JZ",flags)) goto L00499936;
  }
  L0049988d: { // 0x49988d: 8d0440 LEA EAX,[EAX + EAX*0x2]
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  L00499890: { // 0x499890: 897c240c MOV dword ptr [ESP + 0xc],EDI
    m.w32((f.sp+0x0000000cu), s.di);
  }
  L00499894: { // 0x499894: 8b14c5a8a88300 MOV EDX,dword ptr [EAX*0x8 + 0x83a8a8]
    s.dx = m.r32(((s.ax * 0x00000008u)+0x0083a8a8u));
  }
  L0049989b: { // 0x49989b: 8d34c5a8a88300 LEA ESI,[EAX*0x8 + 0x83a8a8]
    s.si = ((s.ax * 0x00000008u)+0x0083a8a8u);
  }
  L004998a2: { // 0x4998a2: 8d44240c LEA EAX,[ESP + 0xc]
    s.ax = (f.sp+0x0000000cu);
  }
  L004998a6: { // 0x4998a6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004998a8: { // 0x4998a8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004998a9: { // 0x4998a9: ff5210 CALL dword ptr [EDX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000010u)),4823212u); flags=s.arithmetic_flags;
  }
  L004998ac: { // 0x4998ac: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L004998af: { // 0x4998af: 742b JZ 0x004998dc
    if(integer::condition("JZ",flags)) goto L004998dc;
  }
  L004998b1: { // 0x4998b1: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    s.cx = m.r32((s.si+0x00000010u));
  }
  L004998b4: { // 0x4998b4: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L004998b6: { // 0x4998b6: 7d24 JGE 0x004998dc
    if(integer::condition("JGE",flags)) goto L004998dc;
  }
  L004998b8: { // 0x4998b8: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L004998b9: { // 0x4998b9: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L004998bb: { // 0x4998bb: 894e10 MOV dword ptr [ESI + 0x10],ECX
    m.w32((s.si+0x00000010u), s.cx);
  }
  L004998be: { // 0x4998be: 7d12 JGE 0x004998d2
    if(integer::condition("JGE",flags)) goto L004998d2;
  }
  L004998c0: { // 0x4998c0: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  L004998c3: { // 0x4998c3: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004998c4: { // 0x4998c4: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L004998c7: { // 0x4998c7: 895481fc MOV dword ptr [ECX + EAX*0x4 + -0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)-0x00000004u), s.dx);
  }
  L004998cb: { // 0x4998cb: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    s.cx = m.r32((s.si+0x00000010u));
  }
  L004998ce: { // 0x4998ce: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L004998d0: { // 0x4998d0: 7cee JL 0x004998c0
    if(integer::condition("JL",flags)) goto L004998c0;
  }
  L004998d2: { // 0x4998d2: c78780000000ffffffff MOV dword ptr [EDI + 0x80],0xffffffff
    m.w32((s.di+0x00000080u), 0xffffffffu);
  }
  L004998dc: { // 0x4998dc: 83bf80000000ff CMP dword ptr [EDI + 0x80],-0x1
    (void)integer::sub(m.r32((s.di+0x00000080u)),0xffffffffu,32,flags);
  }
  L004998e3: { // 0x4998e3: 7451 JZ 0x00499936
    if(integer::condition("JZ",flags)) goto L00499936;
  }
  L004998e5: { // 0x4998e5: beb8a88300 MOV ESI,0x83a8b8
    s.si = 0x0083a8b8u;
  }
  L004998ea: { // 0x4998ea: 8b46f0 MOV EAX,dword ptr [ESI + -0x10]
    s.ax = m.r32((s.si-0x00000010u));
  }
  L004998ed: { // 0x4998ed: 8d4ef0 LEA ECX,[ESI + -0x10]
    s.cx = (s.si-0x00000010u);
  }
  L004998f0: { // 0x4998f0: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  L004998f4: { // 0x4998f4: 897c240c MOV dword ptr [ESP + 0xc],EDI
    m.w32((f.sp+0x0000000cu), s.di);
  }
  L004998f8: { // 0x4998f8: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004998f9: { // 0x4998f9: ff5010 CALL dword ptr [EAX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000010u)),4823292u); flags=s.arithmetic_flags;
  }
  L004998fc: { // 0x4998fc: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L004998ff: { // 0x4998ff: 7420 JZ 0x00499921
    if(integer::condition("JZ",flags)) goto L00499921;
  }
  L00499901: { // 0x499901: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L00499903: { // 0x499903: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00499905: { // 0x499905: 7d1a JGE 0x00499921
    if(integer::condition("JGE",flags)) goto L00499921;
  }
  L00499907: { // 0x499907: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00499908: { // 0x499908: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0049990a: { // 0x49990a: 890e MOV dword ptr [ESI],ECX
    m.w32((s.si), s.cx);
  }
  L0049990c: { // 0x49990c: 7ddc JGE 0x004998ea
    if(integer::condition("JGE",flags)) goto L004998ea;
  }
  L0049990e: { // 0x49990e: 8b4ef4 MOV ECX,dword ptr [ESI + -0xc]
    s.cx = m.r32((s.si-0x0000000cu));
  }
  L00499911: { // 0x499911: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00499912: { // 0x499912: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L00499915: { // 0x499915: 895481fc MOV dword ptr [ECX + EAX*0x4 + -0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)-0x00000004u), s.dx);
  }
  L00499919: { // 0x499919: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0049991b: { // 0x49991b: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0049991d: { // 0x49991d: 7cef JL 0x0049990e
    if(integer::condition("JL",flags)) goto L0049990e;
  }
  L0049991f: { // 0x49991f: ebc9 JMP 0x004998ea
    goto L004998ea;
  }
  L00499921: { // 0x499921: 83c618 ADD ESI,0x18
    s.si = integer::add(s.si,0x00000018u,32,flags);
  }
  L00499924: { // 0x499924: 81fe30a98300 CMP ESI,0x83a930
    (void)integer::sub(s.si,0x0083a930u,32,flags);
  }
  L0049992a: { // 0x49992a: 7cbe JL 0x004998ea
    if(integer::condition("JL",flags)) goto L004998ea;
  }
  L0049992c: { // 0x49992c: c78780000000ffffffff MOV dword ptr [EDI + 0x80],0xffffffff
    m.w32((s.di+0x00000080u), 0xffffffffu);
  }
  L00499936: { // 0x499936: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00499937: { // 0x499937: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00499938: { // 0x499938: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
