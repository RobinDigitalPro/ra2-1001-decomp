#include "recovered/recovery_b692_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b692 {
namespace {
void f_00145490(Memory&,State&,Frame&,const Operations&);
void f_002ce3f0(Memory&,State&,Frame&,const Operations&);
void f_00053810(Memory&,State&,Frame&,const Operations&);
void f_002cc360(Memory&,State&,Frame&,const Operations&);
void f_002cc370(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_00145490(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00545490: { // 0x545490: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00545491: { // 0x545491: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00545492: { // 0x545492: 8b7c240c MOV EDI, dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  L00545496: { // 0x545496: 8b07 MOV EAX, dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L00545498: { // 0x545498: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00545499: { // 0x545499: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0054549f: { // 0x54549f: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L005454a1: { // 0x5454a1: 8bf0 MOV ESI, EAX
    s.si = s.ax;
  }
  L005454a3: { // 0x5454a3: 8b4704 MOV EAX, dword ptr [EDI + 4]
    s.ax = m.r32((s.di+4u));
  }
  L005454a6: { // 0x5454a6: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L005454a7: { // 0x5454a7: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L005454ad: { // 0x5454ad: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L005454af: { // 0x5454af: c1f808 SAR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L005454b2: { // 0x5454b2: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L005454b4: { // 0x5454b4: c1fe08 SAR ESI, 8
    s.si = integer::shift(s.si,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L005454b7: { // 0x5454b7: c1e209 SHL EDX, 9
    s.dx = integer::shift(s.dx,9u,32,flags,integer::Shift::left);
  }
  L005454ba: { // 0x5454ba: 03d6 ADD EDX, ESI
    s.dx = integer::add(s.dx,s.si,32,flags);
  }
  L005454bc: { // 0x5454bc: 781c JS 0x5454da
    if(integer::condition("JS",flags)) goto L005454da;
  }
  L005454be: { // 0x5454be: 3b913c010000 CMP EDX, dword ptr [ECX + 0x13c]
    (void)integer::sub(s.dx,m.r32((s.cx+0x0000013cu)),32,flags);
  }
  L005454c4: { // 0x5454c4: 7d14 JGE 0x5454da
    if(integer::condition("JGE",flags)) goto L005454da;
  }
  L005454c6: { // 0x5454c6: 8b8938010000 MOV ECX, dword ptr [ECX + 0x138]
    s.cx = m.r32((s.cx+0x00000138u));
  }
  L005454cc: { // 0x5454cc: 8b1491 MOV EDX, dword ptr [ECX + EDX*4]
    s.dx = m.r32((s.cx+(s.dx * 4u)));
  }
  L005454cf: { // 0x5454cf: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L005454d1: { // 0x5454d1: 7407 JZ 0x5454da
    if(integer::condition("JZ",flags)) goto L005454da;
  }
  L005454d3: { // 0x5454d3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005454d4: { // 0x5454d4: 8bc2 MOV EAX, EDX
    s.ax = s.dx;
  }
  L005454d6: { // 0x5454d6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005454d7: { // 0x5454d7: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L005454da: { // 0x5454da: 668974240c MOV word ptr [ESP + 0xc], SI
    m.w16((f.sp+0x0000000cu), (s.si & 0xffffu));
  }
  L005454df: { // 0x5454df: 668944240e MOV word ptr [ESP + 0xe], AX
    m.w16((f.sp+0x0000000eu), (s.ax & 0xffffu));
  }
  L005454e4: { // 0x5454e4: 8b54240c MOV EDX, dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  L005454e8: { // 0x5454e8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005454e9: { // 0x5454e9: 89153476a500 MOV dword ptr [0xa57634], EDX
    m.w32((0x00a57634u), s.dx);
  }
  L005454ef: { // 0x5454ef: b81076a500 MOV EAX, 0xa57610
    s.ax = 0x00a57610u;
  }
  L005454f4: { // 0x5454f4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005454f5: { // 0x5454f5: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_002ce3f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006ce3f0: { // 0x6ce3f0: 8b91fc030000 MOV EDX, dword ptr [ECX + 0x3fc]
    s.dx = m.r32((s.cx+0x000003fcu));
  }
  L006ce3f6: { // 0x6ce3f6: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006ce3f8: { // 0x6ce3f8: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L006ce3fa: { // 0x6ce3fa: 0f9fc0 SETG AL
    s.ax = with_al(s.ax, (integer::condition("JG",flags)?1u:0u));
  }
  L006ce3fd: { // 0x6ce3fd: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00053810(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00453810: { // 0x453810: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00453812: { // 0x453812: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002cc360(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006cc360: { // 0x6cc360: 8a8104020000 MOV AL, byte ptr [ECX + 0x204]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000204u)));
  }
  L006cc366: { // 0x6cc366: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002cc370(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006cc370: { // 0x6cc370: 8a8105020000 MOV AL, byte ptr [ECX + 0x205]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000205u)));
  }
  L006cc376: { // 0x6cc376: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 5526672u:f_00145490(m,s,child,{});break;
case 7136240u:f_002ce3f0(m,s,child,{});break;
case 4536336u:f_00053810(m,s,child,{});break;
case 7127904u:f_002cc360(m,s,child,{});break;
case 7127920u:f_002cc370(m,s,child,{});break;
default:throw std::domain_error("recovery692 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0049fb50(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0049fb50: { // 0x49fb50: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0049fb51: { // 0x49fb51: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  L0049fb55: { // 0x49fb55: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0049fb56: { // 0x49fb56: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L0049fb59: { // 0x49fb59: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0049fb5b: { // 0x49fb5b: ff9024030000 CALL dword ptr [EAX + 0x324]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000324u)),4848481u); flags=s.arithmetic_flags;
  }
  L0049fb61: { // 0x49fb61: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049fb63: { // 0x49fb63: 0f8597000000 JNZ 0x0049fc00
    if(integer::condition("JNZ",flags)) goto L0049fc00;
  }
  L0049fb69: { // 0x49fb69: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L0049fb6c: { // 0x49fb6c: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L0049fb6e: { // 0x49fb6e: ff9228030000 CALL dword ptr [EDX + 0x328]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000328u)),4848500u); flags=s.arithmetic_flags;
  }
  L0049fb74: { // 0x49fb74: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049fb76: { // 0x49fb76: 0f8584000000 JNZ 0x0049fc00
    if(integer::condition("JNZ",flags)) goto L0049fc00;
  }
  L0049fb7c: { // 0x49fb7c: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L0049fb7f: { // 0x49fb7f: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0049fb81: { // 0x49fb81: ff90bc010000 CALL dword ptr [EAX + 0x1bc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000001bcu)),4848519u); flags=s.arithmetic_flags;
  }
  L0049fb87: { // 0x49fb87: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049fb89: { // 0x49fb89: 7575 JNZ 0x0049fc00
    if(integer::condition("JNZ",flags)) goto L0049fc00;
  }
  L0049fb8b: { // 0x49fb8b: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L0049fb8e: { // 0x49fb8e: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L0049fb90: { // 0x49fb90: ff92c0010000 CALL dword ptr [EDX + 0x1c0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001c0u)),4848534u); flags=s.arithmetic_flags;
  }
  L0049fb96: { // 0x49fb96: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049fb98: { // 0x49fb98: 7566 JNZ 0x0049fc00
    if(integer::condition("JNZ",flags)) goto L0049fc00;
  }
  L0049fb9a: { // 0x49fb9a: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0049fb9e: { // 0x49fb9e: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0049fba2: { // 0x49fba2: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0049fba6: { // 0x49fba6: 8d7e30 LEA EDI,[ESI + 0x30]
    s.di = (s.si+0x00000030u);
  }
  L0049fba9: { // 0x49fba9: 894630 MOV dword ptr [ESI + 0x30],EAX
    m.w32((s.si+0x00000030u), s.ax);
  }
  L0049fbac: { // 0x49fbac: 894f04 MOV dword ptr [EDI + 0x4],ECX
    m.w32((s.di+0x00000004u), s.cx);
  }
  L0049fbaf: { // 0x49fbaf: 895708 MOV dword ptr [EDI + 0x8],EDX
    m.w32((s.di+0x00000008u), s.dx);
  }
  L0049fbb2: { // 0x49fbb2: 8b3dc8ac8300 MOV EDI,dword ptr [0x0083acc8]
    s.di = m.r32((0x0083acc8u));
  }
  L0049fbb8: { // 0x49fbb8: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0049fbba: { // 0x49fbba: 7510 JNZ 0x0049fbcc
    if(integer::condition("JNZ",flags)) goto L0049fbcc;
  }
  L0049fbbc: { // 0x49fbbc: 3b0dccac8300 CMP ECX,dword ptr [0x0083accc]
    (void)integer::sub(s.cx,m.r32((0x0083acccu)),32,flags);
  }
  L0049fbc2: { // 0x49fbc2: 7508 JNZ 0x0049fbcc
    if(integer::condition("JNZ",flags)) goto L0049fbcc;
  }
  L0049fbc4: { // 0x49fbc4: 3b15d0ac8300 CMP EDX,dword ptr [0x0083acd0]
    (void)integer::sub(s.dx,m.r32((0x0083acd0u)),32,flags);
  }
  L0049fbca: { // 0x49fbca: 7434 JZ 0x0049fc00
    if(integer::condition("JZ",flags)) goto L0049fc00;
  }
  L0049fbcc: { // 0x49fbcc: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0049fbd0: { // 0x49fbd0: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L0049fbd4: { // 0x49fbd4: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L0049fbd8: { // 0x49fbd8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049fbd9: { // 0x49fbd9: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0049fbde: { // 0x49fbde: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L0049fbe2: { // 0x49fbe2: e8a9580a00 CALL 0x00545490
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545490u,4848615u); flags=s.arithmetic_flags;
  }
  L0049fbe7: { // 0x49fbe7: 8b8840010000 MOV ECX,dword ptr [EAX + 0x140]
    s.cx = m.r32((s.ax+0x00000140u));
  }
  L0049fbed: { // 0x49fbed: f6c501 TEST CH,0x1
    (void)integer::logical((((s.cx >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0049fbf0: { // 0x49fbf0: 740e JZ 0x0049fc00
    if(integer::condition("JZ",flags)) goto L0049fc00;
  }
  L0049fbf2: { // 0x49fbf2: 8b0df0ac8300 MOV ECX,dword ptr [0x0083acf0]
    s.cx = m.r32((0x0083acf0u));
  }
  L0049fbf8: { // 0x49fbf8: 8b4638 MOV EAX,dword ptr [ESI + 0x38]
    s.ax = m.r32((s.si+0x00000038u));
  }
  L0049fbfb: { // 0x49fbfb: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0049fbfd: { // 0x49fbfd: 894638 MOV dword ptr [ESI + 0x38],EAX
    m.w32((s.si+0x00000038u), s.ax);
  }
  L0049fc00: { // 0x49fc00: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0049fc01: { // 0x49fc01: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049fc02: { // 0x49fc02: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_0066b770(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0066b770: { // 0x66b770: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0066b771: { // 0x66b771: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  L0066b775: { // 0x66b775: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0066b776: { // 0x66b776: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L0066b779: { // 0x66b779: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0066b77b: { // 0x66b77b: ff9024030000 CALL dword ptr [EAX + 0x324]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000324u)),6731649u); flags=s.arithmetic_flags;
  }
  L0066b781: { // 0x66b781: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0066b783: { // 0x66b783: 0f8597000000 JNZ 0x0066b820
    if(integer::condition("JNZ",flags)) goto L0066b820;
  }
  L0066b789: { // 0x66b789: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L0066b78c: { // 0x66b78c: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L0066b78e: { // 0x66b78e: ff9228030000 CALL dword ptr [EDX + 0x328]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000328u)),6731668u); flags=s.arithmetic_flags;
  }
  L0066b794: { // 0x66b794: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0066b796: { // 0x66b796: 0f8584000000 JNZ 0x0066b820
    if(integer::condition("JNZ",flags)) goto L0066b820;
  }
  L0066b79c: { // 0x66b79c: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L0066b79f: { // 0x66b79f: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0066b7a1: { // 0x66b7a1: ff90bc010000 CALL dword ptr [EAX + 0x1bc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000001bcu)),6731687u); flags=s.arithmetic_flags;
  }
  L0066b7a7: { // 0x66b7a7: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0066b7a9: { // 0x66b7a9: 7575 JNZ 0x0066b820
    if(integer::condition("JNZ",flags)) goto L0066b820;
  }
  L0066b7ab: { // 0x66b7ab: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L0066b7ae: { // 0x66b7ae: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L0066b7b0: { // 0x66b7b0: ff92c0010000 CALL dword ptr [EDX + 0x1c0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001c0u)),6731702u); flags=s.arithmetic_flags;
  }
  L0066b7b6: { // 0x66b7b6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0066b7b8: { // 0x66b7b8: 7566 JNZ 0x0066b820
    if(integer::condition("JNZ",flags)) goto L0066b820;
  }
  L0066b7ba: { // 0x66b7ba: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0066b7be: { // 0x66b7be: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0066b7c2: { // 0x66b7c2: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0066b7c6: { // 0x66b7c6: 8d7e30 LEA EDI,[ESI + 0x30]
    s.di = (s.si+0x00000030u);
  }
  L0066b7c9: { // 0x66b7c9: 894630 MOV dword ptr [ESI + 0x30],EAX
    m.w32((s.si+0x00000030u), s.ax);
  }
  L0066b7cc: { // 0x66b7cc: 894f04 MOV dword ptr [EDI + 0x4],ECX
    m.w32((s.di+0x00000004u), s.cx);
  }
  L0066b7cf: { // 0x66b7cf: 895708 MOV dword ptr [EDI + 0x8],EDX
    m.w32((s.di+0x00000008u), s.dx);
  }
  L0066b7d2: { // 0x66b7d2: 8b3dc80caa00 MOV EDI,dword ptr [0x00aa0cc8]
    s.di = m.r32((0x00aa0cc8u));
  }
  L0066b7d8: { // 0x66b7d8: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0066b7da: { // 0x66b7da: 7510 JNZ 0x0066b7ec
    if(integer::condition("JNZ",flags)) goto L0066b7ec;
  }
  L0066b7dc: { // 0x66b7dc: 3b0dcc0caa00 CMP ECX,dword ptr [0x00aa0ccc]
    (void)integer::sub(s.cx,m.r32((0x00aa0cccu)),32,flags);
  }
  L0066b7e2: { // 0x66b7e2: 7508 JNZ 0x0066b7ec
    if(integer::condition("JNZ",flags)) goto L0066b7ec;
  }
  L0066b7e4: { // 0x66b7e4: 3b15d00caa00 CMP EDX,dword ptr [0x00aa0cd0]
    (void)integer::sub(s.dx,m.r32((0x00aa0cd0u)),32,flags);
  }
  L0066b7ea: { // 0x66b7ea: 7434 JZ 0x0066b820
    if(integer::condition("JZ",flags)) goto L0066b820;
  }
  L0066b7ec: { // 0x66b7ec: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0066b7f0: { // 0x66b7f0: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L0066b7f4: { // 0x66b7f4: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L0066b7f8: { // 0x66b7f8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0066b7f9: { // 0x66b7f9: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0066b7fe: { // 0x66b7fe: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L0066b802: { // 0x66b802: e8899cedff CALL 0x00545490
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545490u,6731783u); flags=s.arithmetic_flags;
  }
  L0066b807: { // 0x66b807: 8b8840010000 MOV ECX,dword ptr [EAX + 0x140]
    s.cx = m.r32((s.ax+0x00000140u));
  }
  L0066b80d: { // 0x66b80d: f6c501 TEST CH,0x1
    (void)integer::logical((((s.cx >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0066b810: { // 0x66b810: 740e JZ 0x0066b820
    if(integer::condition("JZ",flags)) goto L0066b820;
  }
  L0066b812: { // 0x66b812: 8b0df00caa00 MOV ECX,dword ptr [0x00aa0cf0]
    s.cx = m.r32((0x00aa0cf0u));
  }
  L0066b818: { // 0x66b818: 8b4638 MOV EAX,dword ptr [ESI + 0x38]
    s.ax = m.r32((s.si+0x00000038u));
  }
  L0066b81b: { // 0x66b81b: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0066b81d: { // 0x66b81d: 894638 MOV dword ptr [ESI + 0x38],EAX
    m.w32((s.si+0x00000038u), s.ax);
  }
  L0066b820: { // 0x66b820: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0066b821: { // 0x66b821: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0066b822: { // 0x66b822: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
