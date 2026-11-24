#include "recovered/recovery_b629_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b629 {
namespace {
void f_001d6fc0(Memory&,State&,Frame&,const Operations&);
void f_002e7dd0(Memory&,State&,Frame&,const Operations&);
void f_002e7820(Memory&,State&,Frame&,const Operations&);
void f_002e7b30(Memory&,State&,Frame&,const Operations&);
void f_002e8470(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_001d6fc0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005d6fc0: { // 0x5d6fc0: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L005d6fc2: { // 0x5d6fc2: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002e7dd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006e7dd0: { // 0x6e7dd0: a10c8caa00 MOV EAX,[0x00aa8c0c]
    s.ax = m.r32((0x00aa8c0cu));
  }
  L006e7dd5: { // 0x6e7dd5: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002e7820(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006e7820: { // 0x6e7820: a1f48baa00 MOV EAX,[0x00aa8bf4]
    s.ax = m.r32((0x00aa8bf4u));
  }
  L006e7825: { // 0x6e7825: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002e7b30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006e7b30: { // 0x6e7b30: a1008caa00 MOV EAX,[0x00aa8c00]
    s.ax = m.r32((0x00aa8c00u));
  }
  L006e7b35: { // 0x6e7b35: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002e8470(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006e8470: { // 0x6e8470: a1188caa00 MOV EAX,[0x00aa8c18]
    s.ax = m.r32((0x00aa8c18u));
  }
  L006e8475: { // 0x6e8475: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 6123456u:f_001d6fc0(m,s,child,{});break;
case 7241168u:f_002e7dd0(m,s,child,{});break;
case 7239712u:f_002e7820(m,s,child,{});break;
case 7240496u:f_002e7b30(m,s,child,{});break;
case 7242864u:f_002e8470(m,s,child,{});break;
default:throw std::domain_error("recovery629 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_005e2c50(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005e2c50: { // 0x5e2c50: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005e2c51: { // 0x5e2c51: a1a4b1a500 MOV EAX,[0x00a5b1a4]
    s.ax = m.r32((0x00a5b1a4u));
  }
  L005e2c56: { // 0x5e2c56: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005e2c57: { // 0x5e2c57: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L005e2c59: { // 0x5e2c59: 894c2404 MOV dword ptr [ESP + 0x4],ECX
    m.w32((f.sp+0x00000004u), s.cx);
  }
  L005e2c5d: { // 0x5e2c5d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005e2c5f: { // 0x5e2c5f: 7441 JZ 0x005e2ca2
    if(integer::condition("JZ",flags)) goto L005e2ca2;
  }
  L005e2c61: { // 0x5e2c61: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  L005e2c65: { // 0x5e2c65: ff15b8b1a500 CALL dword ptr [0x00a5b1b8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((0x00a5b1b8u)),6171755u); flags=s.arithmetic_flags;
  }
  L005e2c6b: { // 0x5e2c6b: 8b0dacb1a500 MOV ECX,dword ptr [0x00a5b1ac]
    s.cx = m.r32((0x00a5b1acu));
  }
  L005e2c71: { // 0x5e2c71: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L005e2c76: { // 0x5e2c76: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L005e2c78: { // 0x5e2c78: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L005e2c79: { // 0x5e2c79: 23d0 AND EDX,EAX
    s.dx = integer::logical((s.dx)&(s.ax),32,flags);
  }
  L005e2c7b: { // 0x5e2c7b: a1a0b1a500 MOV EAX,[0x00a5b1a0]
    s.ax = m.r32((0x00a5b1a0u));
  }
  L005e2c80: { // 0x5e2c80: 8b0490 MOV EAX,dword ptr [EAX + EDX*0x4]
    s.ax = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L005e2c83: { // 0x5e2c83: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005e2c85: { // 0x5e2c85: 741b JZ 0x005e2ca2
    if(integer::condition("JZ",flags)) goto L005e2ca2;
  }
  L005e2c87: { // 0x5e2c87: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L005e2c8b: { // 0x5e2c8b: 3908 CMP dword ptr [EAX],ECX
    (void)integer::sub(m.r32((s.ax)),s.cx,32,flags);
  }
  L005e2c8d: { // 0x5e2c8d: 740c JZ 0x005e2c9b
    if(integer::condition("JZ",flags)) goto L005e2c9b;
  }
  L005e2c8f: { // 0x5e2c8f: 8b8004020000 MOV EAX,dword ptr [EAX + 0x204]
    s.ax = m.r32((s.ax+0x00000204u));
  }
  L005e2c95: { // 0x5e2c95: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005e2c97: { // 0x5e2c97: 75f2 JNZ 0x005e2c8b
    if(integer::condition("JNZ",flags)) goto L005e2c8b;
  }
  L005e2c99: { // 0x5e2c99: eb07 JMP 0x005e2ca2
    goto L005e2ca2;
  }
  L005e2c9b: { // 0x5e2c9b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005e2c9d: { // 0x5e2c9d: 7403 JZ 0x005e2ca2
    if(integer::condition("JZ",flags)) goto L005e2ca2;
  }
  L005e2c9f: { // 0x5e2c9f: 8d7004 LEA ESI,[EAX + 0x4]
    s.si = (s.ax+0x00000004u);
  }
  L005e2ca2: { // 0x5e2ca2: 8b466c MOV EAX,dword ptr [ESI + 0x6c]
    s.ax = m.r32((s.si+0x0000006cu));
  }
  L005e2ca5: { // 0x5e2ca5: 3d94000000 CMP EAX,0x94
    (void)integer::sub(s.ax,0x00000094u,32,flags);
  }
  L005e2caa: { // 0x5e2caa: 7523 JNZ 0x005e2ccf
    if(integer::condition("JNZ",flags)) goto L005e2ccf;
  }
  L005e2cac: { // 0x5e2cac: e81f511000 CALL 0x006e7dd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006e7dd0u,6171825u); flags=s.arithmetic_flags;
  }
  L005e2cb1: { // 0x5e2cb1: 894674 MOV dword ptr [ESI + 0x74],EAX
    m.w32((s.si+0x00000074u), s.ax);
  }
  L005e2cb4: { // 0x5e2cb4: 8b0d448baa00 MOV ECX,dword ptr [0x00aa8b44]
    s.cx = m.r32((0x00aa8b44u));
  }
  L005e2cba: { // 0x5e2cba: 898ee0000000 MOV dword ptr [ESI + 0xe0],ECX
    m.w32((s.si+0x000000e0u), s.cx);
  }
  L005e2cc0: { // 0x5e2cc0: 8b15448baa00 MOV EDX,dword ptr [0x00aa8b44]
    s.dx = m.r32((0x00aa8b44u));
  }
  L005e2cc6: { // 0x5e2cc6: 8996e4000000 MOV dword ptr [ESI + 0xe4],EDX
    m.w32((s.si+0x000000e4u), s.dx);
  }
  L005e2ccc: { // 0x5e2ccc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005e2ccd: { // 0x5e2ccd: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005e2cce: { // 0x5e2cce: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005e2ccf: { // 0x5e2ccf: 3d03010000 CMP EAX,0x103
    (void)integer::sub(s.ax,0x00000103u,32,flags);
  }
  L005e2cd4: { // 0x5e2cd4: 7522 JNZ 0x005e2cf8
    if(integer::condition("JNZ",flags)) goto L005e2cf8;
  }
  L005e2cd6: { // 0x5e2cd6: e8454b1000 CALL 0x006e7820
    s.arithmetic_flags=flags; invoke(m,s,f,0x006e7820u,6171867u); flags=s.arithmetic_flags;
  }
  L005e2cdb: { // 0x5e2cdb: 894674 MOV dword ptr [ESI + 0x74],EAX
    m.w32((s.si+0x00000074u), s.ax);
  }
  L005e2cde: { // 0x5e2cde: a1b08baa00 MOV EAX,[0x00aa8bb0]
    s.ax = m.r32((0x00aa8bb0u));
  }
  L005e2ce3: { // 0x5e2ce3: 8986e0000000 MOV dword ptr [ESI + 0xe0],EAX
    m.w32((s.si+0x000000e0u), s.ax);
  }
  L005e2ce9: { // 0x5e2ce9: 8b0db08baa00 MOV ECX,dword ptr [0x00aa8bb0]
    s.cx = m.r32((0x00aa8bb0u));
  }
  L005e2cef: { // 0x5e2cef: 898ee4000000 MOV dword ptr [ESI + 0xe4],ECX
    m.w32((s.si+0x000000e4u), s.cx);
  }
  L005e2cf5: { // 0x5e2cf5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005e2cf6: { // 0x5e2cf6: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005e2cf7: { // 0x5e2cf7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005e2cf8: { // 0x5e2cf8: 3d08010000 CMP EAX,0x108
    (void)integer::sub(s.ax,0x00000108u,32,flags);
  }
  L005e2cfd: { // 0x5e2cfd: 7522 JNZ 0x005e2d21
    if(integer::condition("JNZ",flags)) goto L005e2d21;
  }
  L005e2cff: { // 0x5e2cff: e82c4e1000 CALL 0x006e7b30
    s.arithmetic_flags=flags; invoke(m,s,f,0x006e7b30u,6171908u); flags=s.arithmetic_flags;
  }
  L005e2d04: { // 0x5e2d04: 894674 MOV dword ptr [ESI + 0x74],EAX
    m.w32((s.si+0x00000074u), s.ax);
  }
  L005e2d07: { // 0x5e2d07: 8b15a88baa00 MOV EDX,dword ptr [0x00aa8ba8]
    s.dx = m.r32((0x00aa8ba8u));
  }
  L005e2d0d: { // 0x5e2d0d: 8996e0000000 MOV dword ptr [ESI + 0xe0],EDX
    m.w32((s.si+0x000000e0u), s.dx);
  }
  L005e2d13: { // 0x5e2d13: a1a88baa00 MOV EAX,[0x00aa8ba8]
    s.ax = m.r32((0x00aa8ba8u));
  }
  L005e2d18: { // 0x5e2d18: 8986e4000000 MOV dword ptr [ESI + 0xe4],EAX
    m.w32((s.si+0x000000e4u), s.ax);
  }
  L005e2d1e: { // 0x5e2d1e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005e2d1f: { // 0x5e2d1f: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005e2d20: { // 0x5e2d20: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005e2d21: { // 0x5e2d21: 3dc60b0000 CMP EAX,0xbc6
    (void)integer::sub(s.ax,0x00000bc6u,32,flags);
  }
  L005e2d26: { // 0x5e2d26: 7523 JNZ 0x005e2d4b
    if(integer::condition("JNZ",flags)) goto L005e2d4b;
  }
  L005e2d28: { // 0x5e2d28: e8f34a1000 CALL 0x006e7820
    s.arithmetic_flags=flags; invoke(m,s,f,0x006e7820u,6171949u); flags=s.arithmetic_flags;
  }
  L005e2d2d: { // 0x5e2d2d: 894674 MOV dword ptr [ESI + 0x74],EAX
    m.w32((s.si+0x00000074u), s.ax);
  }
  L005e2d30: { // 0x5e2d30: 8b0db08baa00 MOV ECX,dword ptr [0x00aa8bb0]
    s.cx = m.r32((0x00aa8bb0u));
  }
  L005e2d36: { // 0x5e2d36: 898ee0000000 MOV dword ptr [ESI + 0xe0],ECX
    m.w32((s.si+0x000000e0u), s.cx);
  }
  L005e2d3c: { // 0x5e2d3c: 8b15b08baa00 MOV EDX,dword ptr [0x00aa8bb0]
    s.dx = m.r32((0x00aa8bb0u));
  }
  L005e2d42: { // 0x5e2d42: 8996e4000000 MOV dword ptr [ESI + 0xe4],EDX
    m.w32((s.si+0x000000e4u), s.dx);
  }
  L005e2d48: { // 0x5e2d48: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005e2d49: { // 0x5e2d49: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005e2d4a: { // 0x5e2d4a: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005e2d4b: { // 0x5e2d4b: 3dc70b0000 CMP EAX,0xbc7
    (void)integer::sub(s.ax,0x00000bc7u,32,flags);
  }
  L005e2d50: { // 0x5e2d50: 7484 JZ 0x005e2cd6
    if(integer::condition("JZ",flags)) goto L005e2cd6;
  }
  L005e2d52: { // 0x5e2d52: e819571000 CALL 0x006e8470
    s.arithmetic_flags=flags; invoke(m,s,f,0x006e8470u,6171991u); flags=s.arithmetic_flags;
  }
  L005e2d57: { // 0x5e2d57: 894674 MOV dword ptr [ESI + 0x74],EAX
    m.w32((s.si+0x00000074u), s.ax);
  }
  L005e2d5a: { // 0x5e2d5a: 8b15bc8baa00 MOV EDX,dword ptr [0x00aa8bbc]
    s.dx = m.r32((0x00aa8bbcu));
  }
  L005e2d60: { // 0x5e2d60: 8996e0000000 MOV dword ptr [ESI + 0xe0],EDX
    m.w32((s.si+0x000000e0u), s.dx);
  }
  L005e2d66: { // 0x5e2d66: a10c8baa00 MOV EAX,[0x00aa8b0c]
    s.ax = m.r32((0x00aa8b0cu));
  }
  L005e2d6b: { // 0x5e2d6b: 8986e4000000 MOV dword ptr [ESI + 0xe4],EAX
    m.w32((s.si+0x000000e4u), s.ax);
  }
  L005e2d71: { // 0x5e2d71: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005e2d72: { // 0x5e2d72: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005e2d73: { // 0x5e2d73: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
