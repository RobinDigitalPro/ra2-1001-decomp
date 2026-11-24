#include "recovered/recovery_b540_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b540 {
namespace {
void f_002ce490(Memory&,State&,Frame&,const Operations&);
void f_002b6910(Memory&,State&,Frame&,const Operations&);
void f_000538b0(Memory&,State&,Frame&,const Operations&);
void f_00053890(Memory&,State&,Frame&,const Operations&);
void f_0005e3b0(Memory&,State&,Frame&,const Operations&);
void tail(Memory&,State&,Frame&,std::uint32_t);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_002ce490(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006ce490: { // 0x6ce490: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006ce492: { // 0x6ce492: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7136408u); flags=s.arithmetic_flags;
  }
  L006ce498: { // 0x6ce498: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L006ce49a: { // 0x6ce49a: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006ce49c: { // 0x6ce49c: ffa2a0000000 JMP dword ptr [EDX + 0xa0]
    s.arithmetic_flags=flags; tail(m,s,f,m.r32((s.dx+0x000000a0u))); return;
  }
}
void f_002b6910(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006b6910: { // 0x6b6910: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006b6912: { // 0x6b6912: ffa084000000 JMP dword ptr [EAX + 0x84]
    s.arithmetic_flags=flags; tail(m,s,f,m.r32((s.ax+0x00000084u))); return;
  }
}
void f_000538b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004538b0: { // 0x4538b0: 8b8118040000 MOV EAX,dword ptr [ECX + 0x418]
    s.ax = m.r32((s.cx+0x00000418u));
  }
  L004538b6: { // 0x4538b6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00053890(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00453890: { // 0x453890: b806000000 MOV EAX,0x6
    s.ax = 0x00000006u;
  }
  L00453895: { // 0x453895: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0005e3b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0045e3b0: { // 0x45e3b0: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0045e3b2: { // 0x45e3b2: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 7136400u:f_002ce490(m,s,child,{});break;
case 7039248u:f_002b6910(m,s,child,{});break;
case 4536496u:f_000538b0(m,s,child,{});break;
case 4536464u:f_00053890(m,s,child,{});break;
case 4580272u:f_0005e3b0(m,s,child,{});break;
default:throw std::domain_error("recovery540 unreviewed original call");}
f.sp=child.sp;
}
}
namespace { void tail(Memory&m,State&s,Frame&f,std::uint32_t target){switch(target){case 7136400u:f_002ce490(m,s,f,{});return;case 7039248u:f_002b6910(m,s,f,{});return;case 4536496u:f_000538b0(m,s,f,{});return;case 4536464u:f_00053890(m,s,f,{});return;case 4580272u:f_0005e3b0(m,s,f,{});return;default:throw std::domain_error("B540 unexpected tail target");}}}

std::uint32_t fun_0060e720(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0060e720: { // 0x60e720: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0060e721: { // 0x60e721: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0060e722: { // 0x60e722: 8b1db088a200 MOV EBX,dword ptr [0x00a288b0]
    s.bx = m.r32((0x00a288b0u));
  }
  L0060e728: { // 0x60e728: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0060e729: { // 0x60e729: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0060e72a: { // 0x60e72a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0060e72b: { // 0x60e72b: 83cdff OR EBP,0xffffffff
    s.bp = integer::logical((s.bp)|(0xffffffffu),32,flags);
  }
  L0060e72e: { // 0x60e72e: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0060e730: { // 0x60e730: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L0060e732: { // 0x60e732: 7e67 JLE 0x0060e79b
    if(integer::condition("JLE",flags)) goto L0060e79b;
  }
  L0060e734: { // 0x60e734: a1a488a200 MOV EAX,[0x00a288a4]
    s.ax = m.r32((0x00a288a4u));
  }
  L0060e739: { // 0x60e739: 8b34b8 MOV ESI,dword ptr [EAX + EDI*0x4]
    s.si = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  L0060e73c: { // 0x60e73c: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0060e73e: { // 0x60e73e: 7450 JZ 0x0060e790
    if(integer::condition("JZ",flags)) goto L0060e790;
  }
  L0060e740: { // 0x60e740: 8a4e14 MOV CL,byte ptr [ESI + 0x14]
    s.cx = with_al(s.cx, m.r8((s.si+0x00000014u)));
  }
  L0060e743: { // 0x60e743: 80e101 AND CL,0x1
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))&(0x00000001u),8,flags));
  }
  L0060e746: { // 0x60e746: 884c2413 MOV byte ptr [ESP + 0x13],CL
    m.w8((f.sp+0x00000013u), (s.cx & 0xffu));
  }
  L0060e74a: { // 0x60e74a: 7444 JZ 0x0060e790
    if(integer::condition("JZ",flags)) goto L0060e790;
  }
  L0060e74c: { // 0x60e74c: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0060e74e: { // 0x60e74e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0060e750: { // 0x60e750: ff9248040000 CALL dword ptr [EDX + 0x448]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000448u)),6350678u); flags=s.arithmetic_flags;
  }
  L0060e756: { // 0x60e756: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0060e758: { // 0x60e758: 7407 JZ 0x0060e761
    if(integer::condition("JZ",flags)) goto L0060e761;
  }
  L0060e75a: { // 0x60e75a: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0060e75b: { // 0x60e75b: 3bfb CMP EDI,EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  L0060e75d: { // 0x60e75d: 7d3c JGE 0x0060e79b
    if(integer::condition("JGE",flags)) goto L0060e79b;
  }
  L0060e75f: { // 0x60e75f: ebd3 JMP 0x0060e734
    goto L0060e734;
  }
  L0060e761: { // 0x60e761: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0060e763: { // 0x60e763: 742b JZ 0x0060e790
    if(integer::condition("JZ",flags)) goto L0060e790;
  }
  L0060e765: { // 0x60e765: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0060e767: { // 0x60e767: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0060e769: { // 0x60e769: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),6350700u); flags=s.arithmetic_flags;
  }
  L0060e76c: { // 0x60e76c: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  L0060e76f: { // 0x60e76f: 7508 JNZ 0x0060e779
    if(integer::condition("JNZ",flags)) goto L0060e779;
  }
  L0060e771: { // 0x60e771: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0060e772: { // 0x60e772: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0060e773: { // 0x60e773: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0060e774: { // 0x60e774: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0060e776: { // 0x60e776: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0060e777: { // 0x60e777: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0060e778: { // 0x60e778: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0060e779: { // 0x60e779: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0060e77b: { // 0x60e77b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0060e77d: { // 0x60e77d: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),6350720u); flags=s.arithmetic_flags;
  }
  L0060e780: { // 0x60e780: 83f806 CMP EAX,0x6
    (void)integer::sub(s.ax,0x00000006u,32,flags);
  }
  L0060e783: { // 0x60e783: 750b JNZ 0x0060e790
    if(integer::condition("JNZ",flags)) goto L0060e790;
  }
  L0060e785: { // 0x60e785: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0060e786: { // 0x60e786: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0060e787: { // 0x60e787: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0060e788: { // 0x60e788: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L0060e78d: { // 0x60e78d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0060e78e: { // 0x60e78e: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0060e78f: { // 0x60e78f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0060e790: { // 0x60e790: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0060e791: { // 0x60e791: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0060e792: { // 0x60e792: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0060e793: { // 0x60e793: b802000000 MOV EAX,0x2
    s.ax = 0x00000002u;
  }
  L0060e798: { // 0x60e798: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0060e799: { // 0x60e799: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0060e79a: { // 0x60e79a: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0060e79b: { // 0x60e79b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0060e79c: { // 0x60e79c: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L0060e79e: { // 0x60e79e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0060e79f: { // 0x60e79f: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0060e7a0: { // 0x60e7a0: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0060e7a1: { // 0x60e7a1: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0060e7a2: { // 0x60e7a2: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
