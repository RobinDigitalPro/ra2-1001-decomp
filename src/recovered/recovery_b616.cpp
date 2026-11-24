#include "recovered/recovery_b616_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b616 {
namespace {
void f_00212fc0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_00212fc0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00612fc0: { // 0x612fc0: 8b5110 MOV EDX, dword ptr [ECX + 0x10]
    s.dx = m.r32((s.cx+0x00000010u));
  }
  L00612fc3: { // 0x612fc3: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00612fc5: { // 0x612fc5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00612fc6: { // 0x612fc6: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00612fc8: { // 0x612fc8: 7e15 JLE 0x612fdf
    if(integer::condition("JLE",flags)) goto L00612fdf;
  }
  L00612fca: { // 0x612fca: 8b742408 MOV ESI, dword ptr [ESP + 8]
    s.si = m.r32((f.sp+8u));
  }
  L00612fce: { // 0x612fce: 8b4904 MOV ECX, dword ptr [ECX + 4]
    s.cx = m.r32((s.cx+4u));
  }
  L00612fd1: { // 0x612fd1: 8b36 MOV ESI, dword ptr [ESI]
    s.si = m.r32((s.si));
  }
  L00612fd3: { // 0x612fd3: 3931 CMP dword ptr [ECX], ESI
    (void)integer::sub(m.r32((s.cx)),s.si,32,flags);
  }
  L00612fd5: { // 0x612fd5: 740b JZ 0x612fe2
    if(integer::condition("JZ",flags)) goto L00612fe2;
  }
  L00612fd7: { // 0x612fd7: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00612fd8: { // 0x612fd8: 83c104 ADD ECX, 4
    s.cx = integer::add(s.cx,4u,32,flags);
  }
  L00612fdb: { // 0x612fdb: 3bc2 CMP EAX, EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00612fdd: { // 0x612fdd: 7cf4 JL 0x612fd3
    if(integer::condition("JL",flags)) goto L00612fd3;
  }
  L00612fdf: { // 0x612fdf: 83c8ff OR EAX, 0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L00612fe2: { // 0x612fe2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00612fe3: { // 0x612fe3: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 6369216u:f_00212fc0(m,s,child,{});break;
default:throw std::domain_error("recovery616 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0060bfc0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0060bfc0: { // 0x60bfc0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0060bfc1: { // 0x60bfc1: 8b15b0e2a500 MOV EDX,dword ptr [0x00a5e2b0]
    s.dx = m.r32((0x00a5e2b0u));
  }
  L0060bfc7: { // 0x60bfc7: 894c2400 MOV dword ptr [ESP],ECX
    m.w32((f.sp), s.cx);
  }
  L0060bfcb: { // 0x60bfcb: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  L0060bfcf: { // 0x60bfcf: b9b0e2a500 MOV ECX,0xa5e2b0
    s.cx = 0x00a5e2b0u;
  }
  L0060bfd4: { // 0x60bfd4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0060bfd5: { // 0x60bfd5: ff5210 CALL dword ptr [EDX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000010u)),6340568u); flags=s.arithmetic_flags;
  }
  L0060bfd8: { // 0x60bfd8: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L0060bfdb: { // 0x60bfdb: 742d JZ 0x0060c00a
    if(integer::condition("JZ",flags)) goto L0060c00a;
  }
  L0060bfdd: { // 0x60bfdd: 8b0dc0e2a500 MOV ECX,dword ptr [0x00a5e2c0]
    s.cx = m.r32((0x00a5e2c0u));
  }
  L0060bfe3: { // 0x60bfe3: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0060bfe5: { // 0x60bfe5: 7d23 JGE 0x0060c00a
    if(integer::condition("JGE",flags)) goto L0060c00a;
  }
  L0060bfe7: { // 0x60bfe7: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0060bfe8: { // 0x60bfe8: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0060bfea: { // 0x60bfea: 890dc0e2a500 MOV dword ptr [0x00a5e2c0],ECX
    m.w32((0x00a5e2c0u), s.cx);
  }
  L0060bff0: { // 0x60bff0: 7d18 JGE 0x0060c00a
    if(integer::condition("JGE",flags)) goto L0060c00a;
  }
  L0060bff2: { // 0x60bff2: 8b0db4e2a500 MOV ECX,dword ptr [0x00a5e2b4]
    s.cx = m.r32((0x00a5e2b4u));
  }
  L0060bff8: { // 0x60bff8: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0060bff9: { // 0x60bff9: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L0060bffc: { // 0x60bffc: 895481fc MOV dword ptr [ECX + EAX*0x4 + -0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)-0x00000004u), s.dx);
  }
  L0060c000: { // 0x60c000: 8b0dc0e2a500 MOV ECX,dword ptr [0x00a5e2c0]
    s.cx = m.r32((0x00a5e2c0u));
  }
  L0060c006: { // 0x60c006: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0060c008: { // 0x60c008: 7ce8 JL 0x0060bff2
    if(integer::condition("JL",flags)) goto L0060bff2;
  }
  L0060c00a: { // 0x60c00a: 8b1588e1a500 MOV EDX,dword ptr [0x00a5e188]
    s.dx = m.r32((0x00a5e188u));
  }
  L0060c010: { // 0x60c010: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  L0060c014: { // 0x60c014: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0060c015: { // 0x60c015: b988e1a500 MOV ECX,0xa5e188
    s.cx = 0x00a5e188u;
  }
  L0060c01a: { // 0x60c01a: ff5210 CALL dword ptr [EDX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000010u)),6340637u); flags=s.arithmetic_flags;
  }
  L0060c01d: { // 0x60c01d: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L0060c020: { // 0x60c020: 742d JZ 0x0060c04f
    if(integer::condition("JZ",flags)) goto L0060c04f;
  }
  L0060c022: { // 0x60c022: 8b0d98e1a500 MOV ECX,dword ptr [0x00a5e198]
    s.cx = m.r32((0x00a5e198u));
  }
  L0060c028: { // 0x60c028: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0060c02a: { // 0x60c02a: 7d23 JGE 0x0060c04f
    if(integer::condition("JGE",flags)) goto L0060c04f;
  }
  L0060c02c: { // 0x60c02c: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0060c02d: { // 0x60c02d: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0060c02f: { // 0x60c02f: 890d98e1a500 MOV dword ptr [0x00a5e198],ECX
    m.w32((0x00a5e198u), s.cx);
  }
  L0060c035: { // 0x60c035: 7d18 JGE 0x0060c04f
    if(integer::condition("JGE",flags)) goto L0060c04f;
  }
  L0060c037: { // 0x60c037: 8b0d8ce1a500 MOV ECX,dword ptr [0x00a5e18c]
    s.cx = m.r32((0x00a5e18cu));
  }
  L0060c03d: { // 0x60c03d: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0060c03e: { // 0x60c03e: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L0060c041: { // 0x60c041: 895481fc MOV dword ptr [ECX + EAX*0x4 + -0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)-0x00000004u), s.dx);
  }
  L0060c045: { // 0x60c045: 8b0d98e1a500 MOV ECX,dword ptr [0x00a5e198]
    s.cx = m.r32((0x00a5e198u));
  }
  L0060c04b: { // 0x60c04b: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0060c04d: { // 0x60c04d: 7ce8 JL 0x0060c037
    if(integer::condition("JL",flags)) goto L0060c037;
  }
  L0060c04f: { // 0x60c04f: 8b1530e2a500 MOV EDX,dword ptr [0x00a5e230]
    s.dx = m.r32((0x00a5e230u));
  }
  L0060c055: { // 0x60c055: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  L0060c059: { // 0x60c059: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0060c05a: { // 0x60c05a: b930e2a500 MOV ECX,0xa5e230
    s.cx = 0x00a5e230u;
  }
  L0060c05f: { // 0x60c05f: ff5210 CALL dword ptr [EDX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000010u)),6340706u); flags=s.arithmetic_flags;
  }
  L0060c062: { // 0x60c062: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L0060c065: { // 0x60c065: 742d JZ 0x0060c094
    if(integer::condition("JZ",flags)) goto L0060c094;
  }
  L0060c067: { // 0x60c067: 8b0d40e2a500 MOV ECX,dword ptr [0x00a5e240]
    s.cx = m.r32((0x00a5e240u));
  }
  L0060c06d: { // 0x60c06d: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0060c06f: { // 0x60c06f: 7d23 JGE 0x0060c094
    if(integer::condition("JGE",flags)) goto L0060c094;
  }
  L0060c071: { // 0x60c071: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0060c072: { // 0x60c072: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0060c074: { // 0x60c074: 890d40e2a500 MOV dword ptr [0x00a5e240],ECX
    m.w32((0x00a5e240u), s.cx);
  }
  L0060c07a: { // 0x60c07a: 7d18 JGE 0x0060c094
    if(integer::condition("JGE",flags)) goto L0060c094;
  }
  L0060c07c: { // 0x60c07c: 8b0d34e2a500 MOV ECX,dword ptr [0x00a5e234]
    s.cx = m.r32((0x00a5e234u));
  }
  L0060c082: { // 0x60c082: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0060c083: { // 0x60c083: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L0060c086: { // 0x60c086: 895481fc MOV dword ptr [ECX + EAX*0x4 + -0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)-0x00000004u), s.dx);
  }
  L0060c08a: { // 0x60c08a: 8b0d40e2a500 MOV ECX,dword ptr [0x00a5e240]
    s.cx = m.r32((0x00a5e240u));
  }
  L0060c090: { // 0x60c090: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0060c092: { // 0x60c092: 7ce8 JL 0x0060c07c
    if(integer::condition("JL",flags)) goto L0060c07c;
  }
  L0060c094: { // 0x60c094: 8b442400 MOV EAX,dword ptr [ESP]
    s.ax = m.r32((f.sp));
  }
  L0060c098: { // 0x60c098: 8b15e4e2a500 MOV EDX,dword ptr [0x00a5e2e4]
    s.dx = m.r32((0x00a5e2e4u));
  }
  L0060c09e: { // 0x60c09e: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0060c0a0: { // 0x60c0a0: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L0060c0a2: { // 0x60c0a2: 7506 JNZ 0x0060c0aa
    if(integer::condition("JNZ",flags)) goto L0060c0aa;
  }
  L0060c0a4: { // 0x60c0a4: 890de4e2a500 MOV dword ptr [0x00a5e2e4],ECX
    m.w32((0x00a5e2e4u), s.cx);
  }
  L0060c0aa: { // 0x60c0aa: 390550e2a500 CMP dword ptr [0x00a5e250],EAX
    (void)integer::sub(m.r32((0x00a5e250u)),s.ax,32,flags);
  }
  L0060c0b0: { // 0x60c0b0: 7506 JNZ 0x0060c0b8
    if(integer::condition("JNZ",flags)) goto L0060c0b8;
  }
  L0060c0b2: { // 0x60c0b2: 890d50e2a500 MOV dword ptr [0x00a5e250],ECX
    m.w32((0x00a5e250u), s.cx);
  }
  L0060c0b8: { // 0x60c0b8: 390508e2a500 CMP dword ptr [0x00a5e208],EAX
    (void)integer::sub(m.r32((0x00a5e208u)),s.ax,32,flags);
  }
  L0060c0be: { // 0x60c0be: 7506 JNZ 0x0060c0c6
    if(integer::condition("JNZ",flags)) goto L0060c0c6;
  }
  L0060c0c0: { // 0x60c0c0: 890d08e2a500 MOV dword ptr [0x00a5e208],ECX
    m.w32((0x00a5e208u), s.cx);
  }
  L0060c0c6: { // 0x60c0c6: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0060c0c7: { // 0x60c0c7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
