#include "platform/observed_control635.hpp"
#include "recovered/recovery_b635_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b635 {
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
default:{if(target!=ra2::platform::control635::Control::address())throw std::domain_error("635 unreviewed API");s.ax=ra2::platform::control635::Control::guest_call(m.r32(child.sp+4));child.sp+=8;break;}}
f.sp=child.sp;
}
}

std::uint32_t fun_005d9450(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005d9450: { // 0x5d9450: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005d9451: { // 0x5d9451: a1a4b1a500 MOV EAX,[0x00a5b1a4]
    s.ax = m.r32((0x00a5b1a4u));
  }
  L005d9456: { // 0x5d9456: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005d9457: { // 0x5d9457: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L005d9459: { // 0x5d9459: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005d945a: { // 0x5d945a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005d945c: { // 0x5d945c: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L005d945e: { // 0x5d945e: 894c2408 MOV dword ptr [ESP + 0x8],ECX
    m.w32((f.sp+0x00000008u), s.cx);
  }
  L005d9462: { // 0x5d9462: 7441 JZ 0x005d94a5
    if(integer::condition("JZ",flags)) goto L005d94a5;
  }
  L005d9464: { // 0x5d9464: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  L005d9468: { // 0x5d9468: ff15b8b1a500 CALL dword ptr [0x00a5b1b8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((0x00a5b1b8u)),6132846u); flags=s.arithmetic_flags;
  }
  L005d946e: { // 0x5d946e: 8b0dacb1a500 MOV ECX,dword ptr [0x00a5b1ac]
    s.cx = m.r32((0x00a5b1acu));
  }
  L005d9474: { // 0x5d9474: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L005d9479: { // 0x5d9479: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L005d947b: { // 0x5d947b: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L005d947c: { // 0x5d947c: 23d0 AND EDX,EAX
    s.dx = integer::logical((s.dx)&(s.ax),32,flags);
  }
  L005d947e: { // 0x5d947e: a1a0b1a500 MOV EAX,[0x00a5b1a0]
    s.ax = m.r32((0x00a5b1a0u));
  }
  L005d9483: { // 0x5d9483: 8b0490 MOV EAX,dword ptr [EAX + EDX*0x4]
    s.ax = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L005d9486: { // 0x5d9486: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005d9488: { // 0x5d9488: 741b JZ 0x005d94a5
    if(integer::condition("JZ",flags)) goto L005d94a5;
  }
  L005d948a: { // 0x5d948a: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  L005d948e: { // 0x5d948e: 3908 CMP dword ptr [EAX],ECX
    (void)integer::sub(m.r32((s.ax)),s.cx,32,flags);
  }
  L005d9490: { // 0x5d9490: 740c JZ 0x005d949e
    if(integer::condition("JZ",flags)) goto L005d949e;
  }
  L005d9492: { // 0x5d9492: 8b8004020000 MOV EAX,dword ptr [EAX + 0x204]
    s.ax = m.r32((s.ax+0x00000204u));
  }
  L005d9498: { // 0x5d9498: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005d949a: { // 0x5d949a: 75f2 JNZ 0x005d948e
    if(integer::condition("JNZ",flags)) goto L005d948e;
  }
  L005d949c: { // 0x5d949c: eb07 JMP 0x005d94a5
    goto L005d94a5;
  }
  L005d949e: { // 0x5d949e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005d94a0: { // 0x5d94a0: 7403 JZ 0x005d94a5
    if(integer::condition("JZ",flags)) goto L005d94a5;
  }
  L005d94a2: { // 0x5d94a2: 8d7004 LEA ESI,[EAX + 0x4]
    s.si = (s.ax+0x00000004u);
  }
  L005d94a5: { // 0x5d94a5: 8b766c MOV ESI,dword ptr [ESI + 0x6c]
    s.si = m.r32((s.si+0x0000006cu));
  }
  L005d94a8: { // 0x5d94a8: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005d94a9: { // 0x5d94a9: ff15f4537800 CALL dword ptr [0x007853f4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((0x007853f4u)),6132911u); flags=s.arithmetic_flags;
  }
  L005d94af: { // 0x5d94af: 81febc000000 CMP ESI,0xbc
    (void)integer::sub(s.si,0x000000bcu,32,flags);
  }
  L005d94b5: { // 0x5d94b5: 7418 JZ 0x005d94cf
    if(integer::condition("JZ",flags)) goto L005d94cf;
  }
  L005d94b7: { // 0x5d94b7: 81febd000000 CMP ESI,0xbd
    (void)integer::sub(s.si,0x000000bdu,32,flags);
  }
  L005d94bd: { // 0x5d94bd: 7410 JZ 0x005d94cf
    if(integer::condition("JZ",flags)) goto L005d94cf;
  }
  L005d94bf: { // 0x5d94bf: 81fec2000000 CMP ESI,0xc2
    (void)integer::sub(s.si,0x000000c2u,32,flags);
  }
  L005d94c5: { // 0x5d94c5: 7408 JZ 0x005d94cf
    if(integer::condition("JZ",flags)) goto L005d94cf;
  }
  L005d94c7: { // 0x5d94c7: 81fec9000000 CMP ESI,0xc9
    (void)integer::sub(s.si,0x000000c9u,32,flags);
  }
  L005d94cd: { // 0x5d94cd: 7548 JNZ 0x005d9517
    if(integer::condition("JNZ",flags)) goto L005d9517;
  }
  L005d94cf: { // 0x5d94cf: 3dd2060000 CMP EAX,0x6d2
    (void)integer::sub(s.ax,0x000006d2u,32,flags);
  }
  L005d94d4: { // 0x5d94d4: 0f84a3000000 JZ 0x005d957d
    if(integer::condition("JZ",flags)) goto L005d957d;
  }
  L005d94da: { // 0x5d94da: 3dd3060000 CMP EAX,0x6d3
    (void)integer::sub(s.ax,0x000006d3u,32,flags);
  }
  L005d94df: { // 0x5d94df: 0f8498000000 JZ 0x005d957d
    if(integer::condition("JZ",flags)) goto L005d957d;
  }
  L005d94e5: { // 0x5d94e5: 3dd4060000 CMP EAX,0x6d4
    (void)integer::sub(s.ax,0x000006d4u,32,flags);
  }
  L005d94ea: { // 0x5d94ea: 0f848d000000 JZ 0x005d957d
    if(integer::condition("JZ",flags)) goto L005d957d;
  }
  L005d94f0: { // 0x5d94f0: 3dd5060000 CMP EAX,0x6d5
    (void)integer::sub(s.ax,0x000006d5u,32,flags);
  }
  L005d94f5: { // 0x5d94f5: 0f8482000000 JZ 0x005d957d
    if(integer::condition("JZ",flags)) goto L005d957d;
  }
  L005d94fb: { // 0x5d94fb: 3dd6060000 CMP EAX,0x6d6
    (void)integer::sub(s.ax,0x000006d6u,32,flags);
  }
  L005d9500: { // 0x5d9500: 747b JZ 0x005d957d
    if(integer::condition("JZ",flags)) goto L005d957d;
  }
  L005d9502: { // 0x5d9502: 3dd7060000 CMP EAX,0x6d7
    (void)integer::sub(s.ax,0x000006d7u,32,flags);
  }
  L005d9507: { // 0x5d9507: 7474 JZ 0x005d957d
    if(integer::condition("JZ",flags)) goto L005d957d;
  }
  L005d9509: { // 0x5d9509: 3dd8060000 CMP EAX,0x6d8
    (void)integer::sub(s.ax,0x000006d8u,32,flags);
  }
  L005d950e: { // 0x5d950e: 746d JZ 0x005d957d
    if(integer::condition("JZ",flags)) goto L005d957d;
  }
  L005d9510: { // 0x5d9510: 3dd9060000 CMP EAX,0x6d9
    (void)integer::sub(s.ax,0x000006d9u,32,flags);
  }
  L005d9515: { // 0x5d9515: 7466 JZ 0x005d957d
    if(integer::condition("JZ",flags)) goto L005d957d;
  }
  L005d9517: { // 0x5d9517: 81fe02010000 CMP ESI,0x102
    (void)integer::sub(s.si,0x00000102u,32,flags);
  }
  L005d951d: { // 0x5d951d: 7420 JZ 0x005d953f
    if(integer::condition("JZ",flags)) goto L005d953f;
  }
  L005d951f: { // 0x5d951f: 81febc000000 CMP ESI,0xbc
    (void)integer::sub(s.si,0x000000bcu,32,flags);
  }
  L005d9525: { // 0x5d9525: 7418 JZ 0x005d953f
    if(integer::condition("JZ",flags)) goto L005d953f;
  }
  L005d9527: { // 0x5d9527: 81febd000000 CMP ESI,0xbd
    (void)integer::sub(s.si,0x000000bdu,32,flags);
  }
  L005d952d: { // 0x5d952d: 7410 JZ 0x005d953f
    if(integer::condition("JZ",flags)) goto L005d953f;
  }
  L005d952f: { // 0x5d952f: 81fec2000000 CMP ESI,0xc2
    (void)integer::sub(s.si,0x000000c2u,32,flags);
  }
  L005d9535: { // 0x5d9535: 7408 JZ 0x005d953f
    if(integer::condition("JZ",flags)) goto L005d953f;
  }
  L005d9537: { // 0x5d9537: 81fec9000000 CMP ESI,0xc9
    (void)integer::sub(s.si,0x000000c9u,32,flags);
  }
  L005d953d: { // 0x5d953d: 7538 JNZ 0x005d9577
    if(integer::condition("JNZ",flags)) goto L005d9577;
  }
  L005d953f: { // 0x5d953f: 3dda060000 CMP EAX,0x6da
    (void)integer::sub(s.ax,0x000006dau,32,flags);
  }
  L005d9544: { // 0x5d9544: 7437 JZ 0x005d957d
    if(integer::condition("JZ",flags)) goto L005d957d;
  }
  L005d9546: { // 0x5d9546: 3ddb060000 CMP EAX,0x6db
    (void)integer::sub(s.ax,0x000006dbu,32,flags);
  }
  L005d954b: { // 0x5d954b: 7430 JZ 0x005d957d
    if(integer::condition("JZ",flags)) goto L005d957d;
  }
  L005d954d: { // 0x5d954d: 3ddc060000 CMP EAX,0x6dc
    (void)integer::sub(s.ax,0x000006dcu,32,flags);
  }
  L005d9552: { // 0x5d9552: 7429 JZ 0x005d957d
    if(integer::condition("JZ",flags)) goto L005d957d;
  }
  L005d9554: { // 0x5d9554: 3ddd060000 CMP EAX,0x6dd
    (void)integer::sub(s.ax,0x000006ddu,32,flags);
  }
  L005d9559: { // 0x5d9559: 7422 JZ 0x005d957d
    if(integer::condition("JZ",flags)) goto L005d957d;
  }
  L005d955b: { // 0x5d955b: 3dde060000 CMP EAX,0x6de
    (void)integer::sub(s.ax,0x000006deu,32,flags);
  }
  L005d9560: { // 0x5d9560: 741b JZ 0x005d957d
    if(integer::condition("JZ",flags)) goto L005d957d;
  }
  L005d9562: { // 0x5d9562: 3ddf060000 CMP EAX,0x6df
    (void)integer::sub(s.ax,0x000006dfu,32,flags);
  }
  L005d9567: { // 0x5d9567: 7414 JZ 0x005d957d
    if(integer::condition("JZ",flags)) goto L005d957d;
  }
  L005d9569: { // 0x5d9569: 3de0060000 CMP EAX,0x6e0
    (void)integer::sub(s.ax,0x000006e0u,32,flags);
  }
  L005d956e: { // 0x5d956e: 740d JZ 0x005d957d
    if(integer::condition("JZ",flags)) goto L005d957d;
  }
  L005d9570: { // 0x5d9570: 3de1060000 CMP EAX,0x6e1
    (void)integer::sub(s.ax,0x000006e1u,32,flags);
  }
  L005d9575: { // 0x5d9575: 7406 JZ 0x005d957d
    if(integer::condition("JZ",flags)) goto L005d957d;
  }
  L005d9577: { // 0x5d9577: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005d9578: { // 0x5d9578: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L005d957a: { // 0x5d957a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005d957b: { // 0x5d957b: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005d957c: { // 0x5d957c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005d957d: { // 0x5d957d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005d957e: { // 0x5d957e: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L005d9580: { // 0x5d9580: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005d9581: { // 0x5d9581: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005d9582: { // 0x5d9582: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
