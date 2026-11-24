#include "recovered/recovery_b623_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b623 {
namespace {
void f_001d6fc0(Memory&,State&,Frame&,const Operations&);
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

} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 6123456u:f_001d6fc0(m,s,child,{});break;
default:throw std::domain_error("recovery623 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_005e2660(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005e2660: { // 0x5e2660: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005e2661: { // 0x5e2661: a1a4b1a500 MOV EAX,[0x00a5b1a4]
    s.ax = m.r32((0x00a5b1a4u));
  }
  L005e2666: { // 0x5e2666: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005e2667: { // 0x5e2667: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L005e2669: { // 0x5e2669: 894c2404 MOV dword ptr [ESP + 0x4],ECX
    m.w32((f.sp+0x00000004u), s.cx);
  }
  L005e266d: { // 0x5e266d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005e266f: { // 0x5e266f: 7441 JZ 0x005e26b2
    if(integer::condition("JZ",flags)) goto L005e26b2;
  }
  L005e2671: { // 0x5e2671: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  L005e2675: { // 0x5e2675: ff15b8b1a500 CALL dword ptr [0x00a5b1b8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((0x00a5b1b8u)),6170235u); flags=s.arithmetic_flags;
  }
  L005e267b: { // 0x5e267b: 8b0dacb1a500 MOV ECX,dword ptr [0x00a5b1ac]
    s.cx = m.r32((0x00a5b1acu));
  }
  L005e2681: { // 0x5e2681: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L005e2686: { // 0x5e2686: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L005e2688: { // 0x5e2688: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L005e2689: { // 0x5e2689: 23d0 AND EDX,EAX
    s.dx = integer::logical((s.dx)&(s.ax),32,flags);
  }
  L005e268b: { // 0x5e268b: a1a0b1a500 MOV EAX,[0x00a5b1a0]
    s.ax = m.r32((0x00a5b1a0u));
  }
  L005e2690: { // 0x5e2690: 8b0490 MOV EAX,dword ptr [EAX + EDX*0x4]
    s.ax = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L005e2693: { // 0x5e2693: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005e2695: { // 0x5e2695: 741b JZ 0x005e26b2
    if(integer::condition("JZ",flags)) goto L005e26b2;
  }
  L005e2697: { // 0x5e2697: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L005e269b: { // 0x5e269b: 3908 CMP dword ptr [EAX],ECX
    (void)integer::sub(m.r32((s.ax)),s.cx,32,flags);
  }
  L005e269d: { // 0x5e269d: 740c JZ 0x005e26ab
    if(integer::condition("JZ",flags)) goto L005e26ab;
  }
  L005e269f: { // 0x5e269f: 8b8004020000 MOV EAX,dword ptr [EAX + 0x204]
    s.ax = m.r32((s.ax+0x00000204u));
  }
  L005e26a5: { // 0x5e26a5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005e26a7: { // 0x5e26a7: 75f2 JNZ 0x005e269b
    if(integer::condition("JNZ",flags)) goto L005e269b;
  }
  L005e26a9: { // 0x5e26a9: eb07 JMP 0x005e26b2
    goto L005e26b2;
  }
  L005e26ab: { // 0x5e26ab: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005e26ad: { // 0x5e26ad: 7403 JZ 0x005e26b2
    if(integer::condition("JZ",flags)) goto L005e26b2;
  }
  L005e26af: { // 0x5e26af: 8d7004 LEA ESI,[EAX + 0x4]
    s.si = (s.ax+0x00000004u);
  }
  L005e26b2: { // 0x5e26b2: 8b466c MOV EAX,dword ptr [ESI + 0x6c]
    s.ax = m.r32((s.si+0x0000006cu));
  }
  L005e26b5: { // 0x5e26b5: 3dbc000000 CMP EAX,0xbc
    (void)integer::sub(s.ax,0x000000bcu,32,flags);
  }
  L005e26ba: { // 0x5e26ba: 7427 JZ 0x005e26e3
    if(integer::condition("JZ",flags)) goto L005e26e3;
  }
  L005e26bc: { // 0x5e26bc: 3dbd000000 CMP EAX,0xbd
    (void)integer::sub(s.ax,0x000000bdu,32,flags);
  }
  L005e26c1: { // 0x5e26c1: 7420 JZ 0x005e26e3
    if(integer::condition("JZ",flags)) goto L005e26e3;
  }
  L005e26c3: { // 0x5e26c3: 3d02010000 CMP EAX,0x102
    (void)integer::sub(s.ax,0x00000102u,32,flags);
  }
  L005e26c8: { // 0x5e26c8: 7419 JZ 0x005e26e3
    if(integer::condition("JZ",flags)) goto L005e26e3;
  }
  L005e26ca: { // 0x5e26ca: 3dc2000000 CMP EAX,0xc2
    (void)integer::sub(s.ax,0x000000c2u,32,flags);
  }
  L005e26cf: { // 0x5e26cf: 7412 JZ 0x005e26e3
    if(integer::condition("JZ",flags)) goto L005e26e3;
  }
  L005e26d1: { // 0x5e26d1: 3dc9000000 CMP EAX,0xc9
    (void)integer::sub(s.ax,0x000000c9u,32,flags);
  }
  L005e26d6: { // 0x5e26d6: 740b JZ 0x005e26e3
    if(integer::condition("JZ",flags)) goto L005e26e3;
  }
  L005e26d8: { // 0x5e26d8: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005e26da: { // 0x5e26da: 8886d6000000 MOV byte ptr [ESI + 0xd6],AL
    m.w8((s.si+0x000000d6u), (s.ax & 0xffu));
  }
  L005e26e0: { // 0x5e26e0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005e26e1: { // 0x5e26e1: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005e26e2: { // 0x5e26e2: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005e26e3: { // 0x5e26e3: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L005e26e8: { // 0x5e26e8: 8886d6000000 MOV byte ptr [ESI + 0xd6],AL
    m.w8((s.si+0x000000d6u), (s.ax & 0xffu));
  }
  L005e26ee: { // 0x5e26ee: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005e26ef: { // 0x5e26ef: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005e26f0: { // 0x5e26f0: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_005e2840(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005e2840: { // 0x5e2840: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005e2841: { // 0x5e2841: a1a4b1a500 MOV EAX,[0x00a5b1a4]
    s.ax = m.r32((0x00a5b1a4u));
  }
  L005e2846: { // 0x5e2846: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005e2847: { // 0x5e2847: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L005e2849: { // 0x5e2849: 894c2404 MOV dword ptr [ESP + 0x4],ECX
    m.w32((f.sp+0x00000004u), s.cx);
  }
  L005e284d: { // 0x5e284d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005e284f: { // 0x5e284f: 7441 JZ 0x005e2892
    if(integer::condition("JZ",flags)) goto L005e2892;
  }
  L005e2851: { // 0x5e2851: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  L005e2855: { // 0x5e2855: ff15b8b1a500 CALL dword ptr [0x00a5b1b8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((0x00a5b1b8u)),6170715u); flags=s.arithmetic_flags;
  }
  L005e285b: { // 0x5e285b: 8b0dacb1a500 MOV ECX,dword ptr [0x00a5b1ac]
    s.cx = m.r32((0x00a5b1acu));
  }
  L005e2861: { // 0x5e2861: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L005e2866: { // 0x5e2866: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L005e2868: { // 0x5e2868: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L005e2869: { // 0x5e2869: 23d0 AND EDX,EAX
    s.dx = integer::logical((s.dx)&(s.ax),32,flags);
  }
  L005e286b: { // 0x5e286b: a1a0b1a500 MOV EAX,[0x00a5b1a0]
    s.ax = m.r32((0x00a5b1a0u));
  }
  L005e2870: { // 0x5e2870: 8b0490 MOV EAX,dword ptr [EAX + EDX*0x4]
    s.ax = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L005e2873: { // 0x5e2873: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005e2875: { // 0x5e2875: 741b JZ 0x005e2892
    if(integer::condition("JZ",flags)) goto L005e2892;
  }
  L005e2877: { // 0x5e2877: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L005e287b: { // 0x5e287b: 3908 CMP dword ptr [EAX],ECX
    (void)integer::sub(m.r32((s.ax)),s.cx,32,flags);
  }
  L005e287d: { // 0x5e287d: 740c JZ 0x005e288b
    if(integer::condition("JZ",flags)) goto L005e288b;
  }
  L005e287f: { // 0x5e287f: 8b8004020000 MOV EAX,dword ptr [EAX + 0x204]
    s.ax = m.r32((s.ax+0x00000204u));
  }
  L005e2885: { // 0x5e2885: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005e2887: { // 0x5e2887: 75f2 JNZ 0x005e287b
    if(integer::condition("JNZ",flags)) goto L005e287b;
  }
  L005e2889: { // 0x5e2889: eb07 JMP 0x005e2892
    goto L005e2892;
  }
  L005e288b: { // 0x5e288b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005e288d: { // 0x5e288d: 7403 JZ 0x005e2892
    if(integer::condition("JZ",flags)) goto L005e2892;
  }
  L005e288f: { // 0x5e288f: 8d7004 LEA ESI,[EAX + 0x4]
    s.si = (s.ax+0x00000004u);
  }
  L005e2892: { // 0x5e2892: 8b466c MOV EAX,dword ptr [ESI + 0x6c]
    s.ax = m.r32((s.si+0x0000006cu));
  }
  L005e2895: { // 0x5e2895: 3dbc000000 CMP EAX,0xbc
    (void)integer::sub(s.ax,0x000000bcu,32,flags);
  }
  L005e289a: { // 0x5e289a: 743a JZ 0x005e28d6
    if(integer::condition("JZ",flags)) goto L005e28d6;
  }
  L005e289c: { // 0x5e289c: 3dbd000000 CMP EAX,0xbd
    (void)integer::sub(s.ax,0x000000bdu,32,flags);
  }
  L005e28a1: { // 0x5e28a1: 7433 JZ 0x005e28d6
    if(integer::condition("JZ",flags)) goto L005e28d6;
  }
  L005e28a3: { // 0x5e28a3: 3d02010000 CMP EAX,0x102
    (void)integer::sub(s.ax,0x00000102u,32,flags);
  }
  L005e28a8: { // 0x5e28a8: 742c JZ 0x005e28d6
    if(integer::condition("JZ",flags)) goto L005e28d6;
  }
  L005e28aa: { // 0x5e28aa: 3dc2000000 CMP EAX,0xc2
    (void)integer::sub(s.ax,0x000000c2u,32,flags);
  }
  L005e28af: { // 0x5e28af: 7425 JZ 0x005e28d6
    if(integer::condition("JZ",flags)) goto L005e28d6;
  }
  L005e28b1: { // 0x5e28b1: 3dc9000000 CMP EAX,0xc9
    (void)integer::sub(s.ax,0x000000c9u,32,flags);
  }
  L005e28b6: { // 0x5e28b6: 741e JZ 0x005e28d6
    if(integer::condition("JZ",flags)) goto L005e28d6;
  }
  L005e28b8: { // 0x5e28b8: 3d05010000 CMP EAX,0x105
    (void)integer::sub(s.ax,0x00000105u,32,flags);
  }
  L005e28bd: { // 0x5e28bd: 7417 JZ 0x005e28d6
    if(integer::condition("JZ",flags)) goto L005e28d6;
  }
  L005e28bf: { // 0x5e28bf: 83f86b CMP EAX,0x6b
    (void)integer::sub(s.ax,0x0000006bu,32,flags);
  }
  L005e28c2: { // 0x5e28c2: 7412 JZ 0x005e28d6
    if(integer::condition("JZ",flags)) goto L005e28d6;
  }
  L005e28c4: { // 0x5e28c4: 3d13010000 CMP EAX,0x113
    (void)integer::sub(s.ax,0x00000113u,32,flags);
  }
  L005e28c9: { // 0x5e28c9: 740b JZ 0x005e28d6
    if(integer::condition("JZ",flags)) goto L005e28d6;
  }
  L005e28cb: { // 0x5e28cb: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005e28cd: { // 0x5e28cd: 8886d5000000 MOV byte ptr [ESI + 0xd5],AL
    m.w8((s.si+0x000000d5u), (s.ax & 0xffu));
  }
  L005e28d3: { // 0x5e28d3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005e28d4: { // 0x5e28d4: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005e28d5: { // 0x5e28d5: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005e28d6: { // 0x5e28d6: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L005e28db: { // 0x5e28db: 8886d5000000 MOV byte ptr [ESI + 0xd5],AL
    m.w8((s.si+0x000000d5u), (s.ax & 0xffu));
  }
  L005e28e1: { // 0x5e28e1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005e28e2: { // 0x5e28e2: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005e28e3: { // 0x5e28e3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
