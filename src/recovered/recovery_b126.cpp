#include "recovered/recovery_b126_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b126 {
namespace {
void f_0000dc20(Memory&,State&,Frame&,const Operations&);
void f_0001b580(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_0000dc20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0040dc20: { // 0x40dc20: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0040dc21: { // 0x40dc21: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0040dc23: { // 0x40dc23: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0040dc25: { // 0x40dc25: 741e JZ 0x0040dc45
    if(integer::condition("JZ",flags)) goto L0040dc45;
  }
  L0040dc27: { // 0x40dc27: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0040dc29: { // 0x40dc29: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),4250668u); flags=s.arithmetic_flags;
  }
  L0040dc2c: { // 0x40dc2c: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0040dc2d: { // 0x40dc2d: 83f80e CMP EAX,0xe
    (void)integer::sub(s.ax,0x0000000eu,32,flags);
  }
  L0040dc30: { // 0x40dc30: 7713 JA 0x0040dc45
    if(integer::condition("JA",flags)) goto L0040dc45;
  }
  L0040dc32: { // 0x40dc32: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0040dc34: { // 0x40dc34: 8a8854dc4000 MOV CL,byte ptr [EAX + 0x40dc54]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0040dc54u)));
  }
  L0040dc3a: { // 0x40dc3a: ff248d4cdc4000 JMP dword ptr [ECX*0x4 + 0x40dc4c]
    switch(m.r32(((s.cx * 0x00000004u)+0x0040dc4cu))){
    case 0x0040dc20u: goto L0040dc20;
    case 0x0040dc21u: goto L0040dc21;
    case 0x0040dc23u: goto L0040dc23;
    case 0x0040dc25u: goto L0040dc25;
    case 0x0040dc27u: goto L0040dc27;
    case 0x0040dc29u: goto L0040dc29;
    case 0x0040dc2cu: goto L0040dc2c;
    case 0x0040dc2du: goto L0040dc2d;
    case 0x0040dc30u: goto L0040dc30;
    case 0x0040dc32u: goto L0040dc32;
    case 0x0040dc34u: goto L0040dc34;
    case 0x0040dc3au: goto L0040dc3a;
    case 0x0040dc41u: goto L0040dc41;
    case 0x0040dc43u: goto L0040dc43;
    case 0x0040dc44u: goto L0040dc44;
    case 0x0040dc45u: goto L0040dc45;
    case 0x0040dc47u: goto L0040dc47;
    case 0x0040dc48u: goto L0040dc48;
    default:throw std::domain_error("recovery126 unsupported switch destination");}
  }
  L0040dc41: { // 0x40dc41: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0040dc43: { // 0x40dc43: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0040dc44: { // 0x40dc44: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0040dc45: { // 0x40dc45: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0040dc47: { // 0x40dc47: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0040dc48: { // 0x40dc48: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0001b580(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0041b580: { // 0x41b580: b802000000 MOV EAX,0x2
    s.ax = 0x00000002u;
  }
  L0041b585: { // 0x41b585: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4250656u:f_0000dc20(m,s,child,{});break;
case 4306304u:f_0001b580(m,s,child,{});break;
default:throw std::domain_error("recovery126 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_006aaf60(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);
 std::array<std::uint8_t,23> table0{{65,220,64,0,69,220,64,0,0,0,1,1,1,0,1,1,1,1,1,1,1,1,0}};leaf::Memory tablemem0(table0.data(),4250700u,23u);m.add(tablemem0);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006aaf60: { // 0x6aaf60: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006aaf61: { // 0x6aaf61: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006aaf63: { // 0x6aaf63: 807e0434 CMP byte ptr [ESI + 0x4],0x34
    (void)integer::sub(m.r8((s.si+0x00000004u)),0x00000034u,8,flags);
  }
  L006aaf67: { // 0x6aaf67: 0f85b3000000 JNZ 0x006ab020
    if(integer::condition("JNZ",flags)) goto L006ab020;
  }
  L006aaf6d: { // 0x6aaf6d: 8b0d647aaa00 MOV ECX,dword ptr [0x00aa7a64]
    s.cx = m.r32((0x00aa7a64u));
  }
  L006aaf73: { // 0x6aaf73: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006aaf74: { // 0x6aaf74: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006aaf76: { // 0x6aaf76: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006aaf77: { // 0x6aaf77: 747e JZ 0x006aaff7
    if(integer::condition("JZ",flags)) goto L006aaff7;
  }
  L006aaf79: { // 0x6aaf79: 8b15707aaa00 MOV EDX,dword ptr [0x00aa7a70]
    s.dx = m.r32((0x00aa7a70u));
  }
  L006aaf7f: { // 0x6aaf7f: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L006aaf81: { // 0x6aaf81: 740c JZ 0x006aaf8f
    if(integer::condition("JZ",flags)) goto L006aaf8f;
  }
  L006aaf83: { // 0x6aaf83: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L006aaf85: { // 0x6aaf85: 8b3e MOV EDI,dword ptr [ESI]
    s.di = m.r32((s.si));
  }
  L006aaf87: { // 0x6aaf87: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L006aaf89: { // 0x6aaf89: 0f8482000000 JZ 0x006ab011
    if(integer::condition("JZ",flags)) goto L006ab011;
  }
  L006aaf8f: { // 0x6aaf8f: a06c7aaa00 MOV AL,[0x00aa7a6c]
    s.ax = with_al(s.ax, m.r8((0x00aa7a6cu)));
  }
  L006aaf94: { // 0x6aaf94: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006aaf96: { // 0x6aaf96: 752e JNZ 0x006aafc6
    if(integer::condition("JNZ",flags)) goto L006aafc6;
  }
  L006aaf98: { // 0x6aaf98: 6810ba4100 PUSH 0x41ba10
    f.push(m,0x0041ba10u);
  }
  L006aaf9d: { // 0x6aaf9d: 6a08 PUSH 0x8
    f.push(m,0x00000008u);
  }
  L006aaf9f: { // 0x6aaf9f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006aafa0: { // 0x6aafa0: 8b0d607aaa00 MOV ECX,dword ptr [0x00aa7a60]
    s.cx = m.r32((0x00aa7a60u));
  }
  L006aafa6: { // 0x6aafa6: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006aafa7: { // 0x6aafa7: e8da260c00 CALL 0x0076d686
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d686u,6991788u); flags=s.arithmetic_flags;
  }
  L006aafac: { // 0x6aafac: 8b0d647aaa00 MOV ECX,dword ptr [0x00aa7a64]
    s.cx = m.r32((0x00aa7a64u));
  }
  L006aafb2: { // 0x6aafb2: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L006aafb5: { // 0x6aafb5: c705707aaa0000000000 MOV dword ptr [0x00aa7a70],0x0
    m.w32((0x00aa7a70u), 0x00000000u);
  }
  L006aafbf: { // 0x6aafbf: c6056c7aaa0001 MOV byte ptr [0x00aa7a6c],0x1
    m.w8((0x00aa7a6cu), 0x00000001u);
  }
  L006aafc6: { // 0x6aafc6: 8b1e MOV EBX,dword ptr [ESI]
    s.bx = m.r32((s.si));
  }
  L006aafc8: { // 0x6aafc8: 8b3d607aaa00 MOV EDI,dword ptr [0x00aa7a60]
    s.di = m.r32((0x00aa7a60u));
  }
  L006aafce: { // 0x6aafce: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006aafd0: { // 0x6aafd0: 7e25 JLE 0x006aaff7
    if(integer::condition("JLE",flags)) goto L006aaff7;
  }
  L006aafd2: { // 0x6aafd2: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L006aafd4: { // 0x6aafd4: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006aafd5: { // 0x6aafd5: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006aafd7: { // 0x6aafd7: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L006aafd9: { // 0x6aafd9: 8b34c7 MOV ESI,dword ptr [EDI + EAX*0x8]
    s.si = m.r32((s.di+(s.ax * 0x00000008u)));
  }
  L006aafdc: { // 0x6aafdc: 8d14c7 LEA EDX,[EDI + EAX*0x8]
    s.dx = (s.di+(s.ax * 0x00000008u));
  }
  L006aafdf: { // 0x6aafdf: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L006aafe1: { // 0x6aafe1: 7e04 JLE 0x006aafe7
    if(integer::condition("JLE",flags)) goto L006aafe7;
  }
  L006aafe3: { // 0x6aafe3: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006aafe5: { // 0x6aafe5: eb0c JMP 0x006aaff3
    goto L006aaff3;
  }
  L006aafe7: { // 0x6aafe7: 741e JZ 0x006ab007
    if(integer::condition("JZ",flags)) goto L006ab007;
  }
  L006aafe9: { // 0x6aafe9: 8d7a08 LEA EDI,[EDX + 0x8]
    s.di = (s.dx+0x00000008u);
  }
  L006aafec: { // 0x6aafec: 83caff OR EDX,0xffffffff
    s.dx = integer::logical((s.dx)|(0xffffffffu),32,flags);
  }
  L006aafef: { // 0x6aafef: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L006aaff1: { // 0x6aaff1: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L006aaff3: { // 0x6aaff3: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006aaff5: { // 0x6aaff5: 7fdb JG 0x006aafd2
    if(integer::condition("JG",flags)) goto L006aafd2;
  }
  L006aaff7: { // 0x6aaff7: b8a80ab100 MOV EAX,0xb10aa8
    s.ax = 0x00b10aa8u;
  }
  L006aaffc: { // 0x6aaffc: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L006aaffe: { // 0x6aaffe: e81d2cd6ff CALL 0x0040dc20
    s.arithmetic_flags=flags; invoke(m,s,f,0x0040dc20u,6991875u); flags=s.arithmetic_flags;
  }
  L006ab003: { // 0x6ab003: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006ab004: { // 0x6ab004: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006ab005: { // 0x6ab005: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006ab006: { // 0x6ab006: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006ab007: { // 0x6ab007: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L006ab009: { // 0x6ab009: 74ec JZ 0x006aaff7
    if(integer::condition("JZ",flags)) goto L006aaff7;
  }
  L006ab00b: { // 0x6ab00b: 8915707aaa00 MOV dword ptr [0x00aa7a70],EDX
    m.w32((0x00aa7a70u), s.dx);
  }
  L006ab011: { // 0x6ab011: 8b4a04 MOV ECX,dword ptr [EDX + 0x4]
    s.cx = m.r32((s.dx+0x00000004u));
  }
  L006ab014: { // 0x6ab014: 8d4204 LEA EAX,[EDX + 0x4]
    s.ax = (s.dx+0x00000004u);
  }
  L006ab017: { // 0x6ab017: e8042cd6ff CALL 0x0040dc20
    s.arithmetic_flags=flags; invoke(m,s,f,0x0040dc20u,6991900u); flags=s.arithmetic_flags;
  }
  L006ab01c: { // 0x6ab01c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006ab01d: { // 0x6ab01d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006ab01e: { // 0x6ab01e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006ab01f: { // 0x6ab01f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006ab020: { // 0x6ab020: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006ab022: { // 0x6ab022: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006ab023: { // 0x6ab023: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
