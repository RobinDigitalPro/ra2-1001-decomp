#include "recovered/recovery_b585_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b585 {
namespace {
void f_0001b320(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_0001b320(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0041b320: { // 0x41b320: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0041b321: { // 0x41b321: 8b8188000000 MOV EAX,dword ptr [ECX + 0x88]
    s.ax = m.r32((s.cx+0x00000088u));
  }
  L0041b327: { // 0x41b327: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0041b328: { // 0x41b328: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0041b32e: { // 0x41b32e: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0041b330: { // 0x41b330: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0041b333: { // 0x41b333: 6689442400 MOV word ptr [ESP],AX
    m.w16((f.sp), (s.ax & 0xffffu));
  }
  L0041b338: { // 0x41b338: 8b818c000000 MOV EAX,dword ptr [ECX + 0x8c]
    s.ax = m.r32((s.cx+0x0000008cu));
  }
  L0041b33e: { // 0x41b33e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0041b33f: { // 0x41b33f: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0041b345: { // 0x41b345: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0041b347: { // 0x41b347: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0041b34a: { // 0x41b34a: 6689442402 MOV word ptr [ESP + 0x2],AX
    m.w16((f.sp+0x00000002u), (s.ax & 0xffffu));
  }
  L0041b34f: { // 0x41b34f: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L0041b353: { // 0x41b353: 8b4c2400 MOV ECX,dword ptr [ESP]
    s.cx = m.r32((f.sp));
  }
  L0041b357: { // 0x41b357: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L0041b359: { // 0x41b359: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0041b35a: { // 0x41b35a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4305696u:f_0001b320(m,s,child,{});break;
default:throw std::domain_error("recovery585 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0042cad0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0042cad0: { // 0x42cad0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0042cad1: { // 0x42cad1: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0042cad2: { // 0x42cad2: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0042cad3: { // 0x42cad3: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L0042cad7: { // 0x42cad7: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0042cad9: { // 0x42cad9: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0042cada: { // 0x42cada: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0042cadb: { // 0x42cadb: 8b85b4010000 MOV EAX,dword ptr [EBP + 0x1b4]
    s.ax = m.r32((s.bp+0x000001b4u));
  }
  L0042cae1: { // 0x42cae1: 8b4b74 MOV ECX,dword ptr [EBX + 0x74]
    s.cx = m.r32((s.bx+0x00000074u));
  }
  L0042cae4: { // 0x42cae4: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0042cae6: { // 0x42cae6: 7573 JNZ 0x0042cb5b
    if(integer::condition("JNZ",flags)) goto L0042cb5b;
  }
  L0042cae8: { // 0x42cae8: 8b4314 MOV EAX,dword ptr [EBX + 0x14]
    s.ax = m.r32((s.bx+0x00000014u));
  }
  L0042caeb: { // 0x42caeb: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0042caed: { // 0x42caed: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0042caef: { // 0x42caef: 7e6a JLE 0x0042cb5b
    if(integer::condition("JLE",flags)) goto L0042cb5b;
  }
  L0042caf1: { // 0x42caf1: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0042caf3: { // 0x42caf3: 897c2418 MOV dword ptr [ESP + 0x18],EDI
    m.w32((f.sp+0x00000018u), s.di);
  }
  L0042caf7: { // 0x42caf7: 8b4b08 MOV ECX,dword ptr [EBX + 0x8]
    s.cx = m.r32((s.bx+0x00000008u));
  }
  L0042cafa: { // 0x42cafa: 8b9518040000 MOV EDX,dword ptr [EBP + 0x418]
    s.dx = m.r32((s.bp+0x00000418u));
  }
  L0042cb00: { // 0x42cb00: 03f9 ADD EDI,ECX
    s.di = integer::add(s.di,s.cx,32,flags);
  }
  L0042cb02: { // 0x42cb02: 8b82900b0000 MOV EAX,dword ptr [EDX + 0xb90]
    s.ax = m.r32((s.dx+0x00000b90u));
  }
  L0042cb08: { // 0x42cb08: 3b07 CMP EAX,dword ptr [EDI]
    (void)integer::sub(s.ax,m.r32((s.di)),32,flags);
  }
  L0042cb0a: { // 0x42cb0a: 7523 JNZ 0x0042cb2f
    if(integer::condition("JNZ",flags)) goto L0042cb2f;
  }
  L0042cb0c: { // 0x42cb0c: 8b5500 MOV EDX,dword ptr [EBP]
    s.dx = m.r32((s.bp));
  }
  L0042cb0f: { // 0x42cb0f: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L0042cb13: { // 0x42cb13: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0042cb14: { // 0x42cb14: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0042cb16: { // 0x42cb16: ff92a0010000 CALL dword ptr [EDX + 0x1a0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001a0u)),4377372u); flags=s.arithmetic_flags;
  }
  L0042cb1c: { // 0x42cb1c: 668b08 MOV CX,word ptr [EAX]
    s.cx = with_ax(s.cx, m.r16((s.ax)));
  }
  L0042cb1f: { // 0x42cb1f: 663b4f04 CMP CX,word ptr [EDI + 0x4]
    (void)integer::sub((s.cx & 0xffffu),m.r16((s.di+0x00000004u)),16,flags);
  }
  L0042cb23: { // 0x42cb23: 750a JNZ 0x0042cb2f
    if(integer::condition("JNZ",flags)) goto L0042cb2f;
  }
  L0042cb25: { // 0x42cb25: 668b5002 MOV DX,word ptr [EAX + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.ax+0x00000002u)));
  }
  L0042cb29: { // 0x42cb29: 663b5706 CMP DX,word ptr [EDI + 0x6]
    (void)integer::sub((s.dx & 0xffffu),m.r16((s.di+0x00000006u)),16,flags);
  }
  L0042cb2d: { // 0x42cb2d: 7415 JZ 0x0042cb44
    if(integer::condition("JZ",flags)) goto L0042cb44;
  }
  L0042cb2f: { // 0x42cb2f: 8b7c2418 MOV EDI,dword ptr [ESP + 0x18]
    s.di = m.r32((f.sp+0x00000018u));
  }
  L0042cb33: { // 0x42cb33: 8b4314 MOV EAX,dword ptr [EBX + 0x14]
    s.ax = m.r32((s.bx+0x00000014u));
  }
  L0042cb36: { // 0x42cb36: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0042cb37: { // 0x42cb37: 83c710 ADD EDI,0x10
    s.di = integer::add(s.di,0x00000010u,32,flags);
  }
  L0042cb3a: { // 0x42cb3a: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L0042cb3c: { // 0x42cb3c: 897c2418 MOV dword ptr [ESP + 0x18],EDI
    m.w32((f.sp+0x00000018u), s.di);
  }
  L0042cb40: { // 0x42cb40: 7d19 JGE 0x0042cb5b
    if(integer::condition("JGE",flags)) goto L0042cb5b;
  }
  L0042cb42: { // 0x42cb42: ebb3 JMP 0x0042caf7
    goto L0042caf7;
  }
  L0042cb44: { // 0x42cb44: 8b4b08 MOV ECX,dword ptr [EBX + 0x8]
    s.cx = m.r32((s.bx+0x00000008u));
  }
  L0042cb47: { // 0x42cb47: c1e604 SHL ESI,0x4
    s.si = integer::shift(s.si,0x00000004u,32,flags,integer::Shift::left);
  }
  L0042cb4a: { // 0x42cb4a: 03f1 ADD ESI,ECX
    s.si = integer::add(s.si,s.cx,32,flags);
  }
  L0042cb4c: { // 0x42cb4c: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0042cb4e: { // 0x42cb4e: 740b JZ 0x0042cb5b
    if(integer::condition("JZ",flags)) goto L0042cb5b;
  }
  L0042cb50: { // 0x42cb50: c6460801 MOV byte ptr [ESI + 0x8],0x1
    m.w8((s.si+0x00000008u), 0x00000001u);
  }
  L0042cb54: { // 0x42cb54: c7460c00000000 MOV dword ptr [ESI + 0xc],0x0
    m.w32((s.si+0x0000000cu), 0x00000000u);
  }
  L0042cb5b: { // 0x42cb5b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0042cb5c: { // 0x42cb5c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0042cb5d: { // 0x42cb5d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0042cb5e: { // 0x42cb5e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0042cb5f: { // 0x42cb5f: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0042cb60: { // 0x42cb60: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
