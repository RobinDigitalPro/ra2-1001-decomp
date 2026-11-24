#include "recovered/recovery_b723_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b723 {
namespace {
void f_0005e970(Memory&,State&,Frame&,const Operations&);
void f_000eaa70(Memory&,State&,Frame&,const Operations&);
void f_000829a0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_0005e970(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0045e970: { // 0x45e970: b807000000 MOV EAX, 7
    s.ax = 7u;
  }
  L0045e975: { // 0x45e975: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000eaa70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004eaa70: { // 0x4eaa70: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004eaa71: { // 0x4eaa71: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L004eaa73: { // 0x4eaa73: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L004eaa75: { // 0x4eaa75: 7d04 JGE 0x4eaa7b
    if(integer::condition("JGE",flags)) goto L004eaa7b;
  }
  L004eaa77: { // 0x4eaa77: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004eaa79: { // 0x4eaa79: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004eaa7a: { // 0x4eaa7a: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004eaa7b: { // 0x4eaa7b: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004eaa7d: { // 0x4eaa7d: e81e7ff9ff CALL 0x4829a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004829a0u,5155458u); flags=s.arithmetic_flags;
  }
  L004eaa82: { // 0x4eaa82: 83fe06 CMP ESI, 6
    (void)integer::sub(s.si,6u,32,flags);
  }
  L004eaa85: { // 0x4eaa85: 7409 JZ 0x4eaa90
    if(integer::condition("JZ",flags)) goto L004eaa90;
  }
  L004eaa87: { // 0x4eaa87: 83fe07 CMP ESI, 7
    (void)integer::sub(s.si,7u,32,flags);
  }
  L004eaa8a: { // 0x4eaa8a: 7404 JZ 0x4eaa90
    if(integer::condition("JZ",flags)) goto L004eaa90;
  }
  L004eaa8c: { // 0x4eaa8c: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004eaa8e: { // 0x4eaa8e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004eaa8f: { // 0x4eaa8f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004eaa90: { // 0x4eaa90: 8b80a00b0000 MOV EAX, dword ptr [EAX + 0xba0]
    s.ax = m.r32((s.ax+0x00000ba0u));
  }
  L004eaa96: { // 0x4eaa96: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004eaa97: { // 0x4eaa97: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000829a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004829a0: { // 0x4829a0: 8d41ff LEA EAX, [ECX - 1]
    s.ax = (s.cx-1u);
  }
  L004829a3: { // 0x4829a3: 83f827 CMP EAX, 0x27
    (void)integer::sub(s.ax,0x00000027u,32,flags);
  }
  L004829a6: { // 0x4829a6: 7735 JA 0x4829dd
    if(integer::condition("JA",flags)) goto L004829dd;
  }
  L004829a8: { // 0x4829a8: 33c9 XOR ECX, ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L004829aa: { // 0x4829aa: 8a88f4294800 MOV CL, byte ptr [EAX + 0x4829f4]
    constexpr unsigned char targets[]{0,1,1,4,4,2,2,4,4,4,4,4,4,4,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,0};if(s.ax>=40)throw std::domain_error("723 class table bounds");s.cx=with_al(s.cx,targets[s.ax]);
  }
  L004829b0: { // 0x4829b0: ff248de0294800 JMP dword ptr [ECX*4 + 0x4829e0]
    const unsigned targets[]{0x4829b7,0x4829d3,0x4829c0,0x4829ca,0x4829dd};if(s.cx>=5)throw std::domain_error("723 target table bounds");switch(targets[s.cx]){
    case 0x004829a0u: goto L004829a0;
    case 0x004829a3u: goto L004829a3;
    case 0x004829a6u: goto L004829a6;
    case 0x004829a8u: goto L004829a8;
    case 0x004829aau: goto L004829aa;
    case 0x004829b0u: goto L004829b0;
    case 0x004829b7u: goto L004829b7;
    case 0x004829bcu: goto L004829bc;
    case 0x004829bfu: goto L004829bf;
    case 0x004829c0u: goto L004829c0;
    case 0x004829c6u: goto L004829c6;
    case 0x004829c9u: goto L004829c9;
    case 0x004829cau: goto L004829ca;
    case 0x004829cfu: goto L004829cf;
    case 0x004829d2u: goto L004829d2;
    case 0x004829d3u: goto L004829d3;
    case 0x004829d9u: goto L004829d9;
    case 0x004829dcu: goto L004829dc;
    case 0x004829ddu: goto L004829dd;
    case 0x004829dfu: goto L004829df;
    default:throw std::domain_error("recovery723 unsupported switch destination");}
  }
  L004829b7: { // 0x4829b7: a17ce0a100 MOV EAX, dword ptr [0xa1e07c]
    s.ax = m.r32((0x00a1e07cu));
  }
  L004829bc: { // 0x4829bc: 8b0490 MOV EAX, dword ptr [EAX + EDX*4]
    s.ax = m.r32((s.ax+(s.dx * 4u)));
  }
  L004829bf: { // 0x4829bf: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004829c0: { // 0x4829c0: 8b0d0ce0a100 MOV ECX, dword ptr [0xa1e00c]
    s.cx = m.r32((0x00a1e00cu));
  }
  L004829c6: { // 0x4829c6: 8b0491 MOV EAX, dword ptr [ECX + EDX*4]
    s.ax = m.r32((s.cx+(s.dx * 4u)));
  }
  L004829c9: { // 0x4829c9: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004829ca: { // 0x4829ca: a1a47fa200 MOV EAX, dword ptr [0xa27fa4]
    s.ax = m.r32((0x00a27fa4u));
  }
  L004829cf: { // 0x4829cf: 8b0490 MOV EAX, dword ptr [EAX + EDX*4]
    s.ax = m.r32((s.ax+(s.dx * 4u)));
  }
  L004829d2: { // 0x4829d2: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004829d3: { // 0x4829d3: 8b0dac55a200 MOV ECX, dword ptr [0xa255ac]
    s.cx = m.r32((0x00a255acu));
  }
  L004829d9: { // 0x4829d9: 8b0491 MOV EAX, dword ptr [ECX + EDX*4]
    s.ax = m.r32((s.cx+(s.dx * 4u)));
  }
  L004829dc: { // 0x4829dc: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004829dd: { // 0x4829dd: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004829df: { // 0x4829df: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4581744u:f_0005e970(m,s,child,{});break;
case 5155440u:f_000eaa70(m,s,child,{});break;
case 4729248u:f_000829a0(m,s,child,{});break;
default:throw std::domain_error("recovery723 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_006779e0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006779e0: { // 0x6779e0: a1b07fa200 MOV EAX,[0x00a27fb0]
    s.ax = m.r32((0x00a27fb0u));
  }
  L006779e5: { // 0x6779e5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006779e6: { // 0x6779e6: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006779e7: { // 0x6779e7: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L006779e9: { // 0x6779e9: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L006779eb: { // 0x6779eb: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L006779ef: { // 0x6779ef: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006779f1: { // 0x6779f1: 7e12 JLE 0x00677a05
    if(integer::condition("JLE",flags)) goto L00677a05;
  }
  L006779f3: { // 0x6779f3: 8b15a47fa200 MOV EDX,dword ptr [0x00a27fa4]
    s.dx = m.r32((0x00a27fa4u));
  }
  L006779f9: { // 0x6779f9: 390a CMP dword ptr [EDX],ECX
    (void)integer::sub(m.r32((s.dx)),s.cx,32,flags);
  }
  L006779fb: { // 0x6779fb: 7468 JZ 0x00677a65
    if(integer::condition("JZ",flags)) goto L00677a65;
  }
  L006779fd: { // 0x6779fd: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L006779fe: { // 0x6779fe: 83c204 ADD EDX,0x4
    s.dx = integer::add(s.dx,0x00000004u,32,flags);
  }
  L00677a01: { // 0x677a01: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L00677a03: { // 0x677a03: 7cf4 JL 0x006779f9
    if(integer::condition("JL",flags)) goto L006779f9;
  }
  L00677a05: { // 0x677a05: 8b1588e0a100 MOV EDX,dword ptr [0x00a1e088]
    s.dx = m.r32((0x00a1e088u));
  }
  L00677a0b: { // 0x677a0b: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L00677a0d: { // 0x677a0d: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00677a0f: { // 0x677a0f: 7e11 JLE 0x00677a22
    if(integer::condition("JLE",flags)) goto L00677a22;
  }
  L00677a11: { // 0x677a11: a17ce0a100 MOV EAX,[0x00a1e07c]
    s.ax = m.r32((0x00a1e07cu));
  }
  L00677a16: { // 0x677a16: 3b08 CMP ECX,dword ptr [EAX]
    (void)integer::sub(s.cx,m.r32((s.ax)),32,flags);
  }
  L00677a18: { // 0x677a18: 744b JZ 0x00677a65
    if(integer::condition("JZ",flags)) goto L00677a65;
  }
  L00677a1a: { // 0x677a1a: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L00677a1b: { // 0x677a1b: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  L00677a1e: { // 0x677a1e: 3bf2 CMP ESI,EDX
    (void)integer::sub(s.si,s.dx,32,flags);
  }
  L00677a20: { // 0x677a20: 7cf4 JL 0x00677a16
    if(integer::condition("JL",flags)) goto L00677a16;
  }
  L00677a22: { // 0x677a22: 8b15b855a200 MOV EDX,dword ptr [0x00a255b8]
    s.dx = m.r32((0x00a255b8u));
  }
  L00677a28: { // 0x677a28: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L00677a2a: { // 0x677a2a: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00677a2c: { // 0x677a2c: 7e11 JLE 0x00677a3f
    if(integer::condition("JLE",flags)) goto L00677a3f;
  }
  L00677a2e: { // 0x677a2e: a1ac55a200 MOV EAX,[0x00a255ac]
    s.ax = m.r32((0x00a255acu));
  }
  L00677a33: { // 0x677a33: 3b08 CMP ECX,dword ptr [EAX]
    (void)integer::sub(s.cx,m.r32((s.ax)),32,flags);
  }
  L00677a35: { // 0x677a35: 742e JZ 0x00677a65
    if(integer::condition("JZ",flags)) goto L00677a65;
  }
  L00677a37: { // 0x677a37: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L00677a38: { // 0x677a38: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  L00677a3b: { // 0x677a3b: 3bf2 CMP ESI,EDX
    (void)integer::sub(s.si,s.dx,32,flags);
  }
  L00677a3d: { // 0x677a3d: 7cf4 JL 0x00677a33
    if(integer::condition("JL",flags)) goto L00677a33;
  }
  L00677a3f: { // 0x677a3f: 8b1518e0a100 MOV EDX,dword ptr [0x00a1e018]
    s.dx = m.r32((0x00a1e018u));
  }
  L00677a45: { // 0x677a45: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L00677a47: { // 0x677a47: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00677a49: { // 0x677a49: 0f8ed0000000 JLE 0x00677b1f
    if(integer::condition("JLE",flags)) goto L00677b1f;
  }
  L00677a4f: { // 0x677a4f: a10ce0a100 MOV EAX,[0x00a1e00c]
    s.ax = m.r32((0x00a1e00cu));
  }
  L00677a54: { // 0x677a54: 3b08 CMP ECX,dword ptr [EAX]
    (void)integer::sub(s.cx,m.r32((s.ax)),32,flags);
  }
  L00677a56: { // 0x677a56: 740d JZ 0x00677a65
    if(integer::condition("JZ",flags)) goto L00677a65;
  }
  L00677a58: { // 0x677a58: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L00677a59: { // 0x677a59: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  L00677a5c: { // 0x677a5c: 3bf2 CMP ESI,EDX
    (void)integer::sub(s.si,s.dx,32,flags);
  }
  L00677a5e: { // 0x677a5e: 7cf4 JL 0x00677a54
    if(integer::condition("JL",flags)) goto L00677a54;
  }
  L00677a60: { // 0x677a60: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00677a61: { // 0x677a61: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00677a62: { // 0x677a62: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00677a65: { // 0x677a65: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00677a67: { // 0x677a67: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),6781546u); flags=s.arithmetic_flags;
  }
  L00677a6a: { // 0x677a6a: 83f80f CMP EAX,0xf
    (void)integer::sub(s.ax,0x0000000fu,32,flags);
  }
  L00677a6d: { // 0x677a6d: 7453 JZ 0x00677ac2
    if(integer::condition("JZ",flags)) goto L00677ac2;
  }
  L00677a6f: { // 0x677a6f: 83f810 CMP EAX,0x10
    (void)integer::sub(s.ax,0x00000010u,32,flags);
  }
  L00677a72: { // 0x677a72: 744e JZ 0x00677ac2
    if(integer::condition("JZ",flags)) goto L00677ac2;
  }
  L00677a74: { // 0x677a74: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L00677a77: { // 0x677a77: 7442 JZ 0x00677abb
    if(integer::condition("JZ",flags)) goto L00677abb;
  }
  L00677a79: { // 0x677a79: 83f828 CMP EAX,0x28
    (void)integer::sub(s.ax,0x00000028u,32,flags);
  }
  L00677a7c: { // 0x677a7c: 743d JZ 0x00677abb
    if(integer::condition("JZ",flags)) goto L00677abb;
  }
  L00677a7e: { // 0x677a7e: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  L00677a81: { // 0x677a81: 7438 JZ 0x00677abb
    if(integer::condition("JZ",flags)) goto L00677abb;
  }
  L00677a83: { // 0x677a83: 83f803 CMP EAX,0x3
    (void)integer::sub(s.ax,0x00000003u,32,flags);
  }
  L00677a86: { // 0x677a86: 7433 JZ 0x00677abb
    if(integer::condition("JZ",flags)) goto L00677abb;
  }
  L00677a88: { // 0x677a88: 83f806 CMP EAX,0x6
    (void)integer::sub(s.ax,0x00000006u,32,flags);
  }
  L00677a8b: { // 0x677a8b: 741b JZ 0x00677aa8
    if(integer::condition("JZ",flags)) goto L00677aa8;
  }
  L00677a8d: { // 0x677a8d: 83f807 CMP EAX,0x7
    (void)integer::sub(s.ax,0x00000007u,32,flags);
  }
  L00677a90: { // 0x677a90: 7416 JZ 0x00677aa8
    if(integer::condition("JZ",flags)) goto L00677aa8;
  }
  L00677a92: { // 0x677a92: 83f839 CMP EAX,0x39
    (void)integer::sub(s.ax,0x00000039u,32,flags);
  }
  L00677a95: { // 0x677a95: 740a JZ 0x00677aa1
    if(integer::condition("JZ",flags)) goto L00677aa1;
  }
  L00677a97: { // 0x677a97: 83f820 CMP EAX,0x20
    (void)integer::sub(s.ax,0x00000020u,32,flags);
  }
  L00677a9a: { // 0x677a9a: 7405 JZ 0x00677aa1
    if(integer::condition("JZ",flags)) goto L00677aa1;
  }
  L00677a9c: { // 0x677a9c: 83f81f CMP EAX,0x1f
    (void)integer::sub(s.ax,0x0000001fu,32,flags);
  }
  L00677a9f: { // 0x677a9f: 757e JNZ 0x00677b1f
    if(integer::condition("JNZ",flags)) goto L00677b1f;
  }
  L00677aa1: { // 0x677aa1: b901000000 MOV ECX,0x1
    s.cx = 0x00000001u;
  }
  L00677aa6: { // 0x677aa6: eb1f JMP 0x00677ac7
    goto L00677ac7;
  }
  L00677aa8: { // 0x677aa8: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L00677aaa: { // 0x677aaa: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00677aac: { // 0x677aac: e8bf2fe7ff CALL 0x004eaa70
    s.arithmetic_flags=flags; invoke(m,s,f,0x004eaa70u,6781617u); flags=s.arithmetic_flags;
  }
  L00677ab1: { // 0x677ab1: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00677ab3: { // 0x677ab3: 83f805 CMP EAX,0x5
    (void)integer::sub(s.ax,0x00000005u,32,flags);
  }
  L00677ab6: { // 0x677ab6: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L00677ab9: { // 0x677ab9: eb0c JMP 0x00677ac7
    goto L00677ac7;
  }
  L00677abb: { // 0x677abb: b903000000 MOV ECX,0x3
    s.cx = 0x00000003u;
  }
  L00677ac0: { // 0x677ac0: eb05 JMP 0x00677ac7
    goto L00677ac7;
  }
  L00677ac2: { // 0x677ac2: b902000000 MOV ECX,0x2
    s.cx = 0x00000002u;
  }
  L00677ac7: { // 0x677ac7: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00677ac9: { // 0x677ac9: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L00677acc: { // 0x677acc: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00677ace: { // 0x677ace: 8d14c0 LEA EDX,[EAX + EAX*0x8]
    s.dx = (s.ax+(s.ax * 0x00000008u));
  }
  L00677ad1: { // 0x677ad1: 8d0451 LEA EAX,[ECX + EDX*0x2]
    s.ax = (s.cx+(s.dx * 0x00000002u));
  }
  L00677ad4: { // 0x677ad4: 8d0440 LEA EAX,[EAX + EAX*0x2]
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  L00677ad7: { // 0x677ad7: 8d948740150000 LEA EDX,[EDI + EAX*0x4 + 0x1540]
    s.dx = (s.di+(s.ax * 0x00000004u)+0x00001540u);
  }
  L00677ade: { // 0x677ade: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00677ae0: { // 0x677ae0: 8d4a54 LEA ECX,[EDX + 0x54]
    s.cx = (s.dx+0x00000054u);
  }
  L00677ae3: { // 0x677ae3: 3931 CMP dword ptr [ECX],ESI
    (void)integer::sub(m.r32((s.cx)),s.si,32,flags);
  }
  L00677ae5: { // 0x677ae5: 740b JZ 0x00677af2
    if(integer::condition("JZ",flags)) goto L00677af2;
  }
  L00677ae7: { // 0x677ae7: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00677ae8: { // 0x677ae8: 83c130 ADD ECX,0x30
    s.cx = integer::add(s.cx,0x00000030u,32,flags);
  }
  L00677aeb: { // 0x677aeb: 83f84b CMP EAX,0x4b
    (void)integer::sub(s.ax,0x0000004bu,32,flags);
  }
  L00677aee: { // 0x677aee: 7cf3 JL 0x00677ae3
    if(integer::condition("JL",flags)) goto L00677ae3;
  }
  L00677af0: { // 0x677af0: eb19 JMP 0x00677b0b
    goto L00677b0b;
  }
  L00677af2: { // 0x677af2: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  L00677af8: { // 0x677af8: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L00677afc: { // 0x677afc: 8d0440 LEA EAX,[EAX + EAX*0x2]
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  L00677aff: { // 0x677aff: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L00677b01: { // 0x677b01: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L00677b04: { // 0x677b04: 898c1080000000 MOV dword ptr [EAX + EDX*0x1 + 0x80],ECX
    m.w32((s.ax+(s.dx * 0x00000001u)+0x00000080u), s.cx);
  }
  L00677b0b: { // 0x677b0b: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  L00677b11: { // 0x677b11: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00677b15: { // 0x677b15: 8d441101 LEA EAX,[ECX + EDX*0x1 + 0x1]
    s.ax = (s.cx+(s.dx * 0x00000001u)+0x00000001u);
  }
  L00677b19: { // 0x677b19: 8987dc4e0000 MOV dword ptr [EDI + 0x4edc],EAX
    m.w32((s.di+0x00004edcu), s.ax);
  }
  L00677b1f: { // 0x677b1f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00677b20: { // 0x677b20: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00677b21: { // 0x677b21: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
