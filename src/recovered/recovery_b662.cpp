#include "recovered/recovery_b662_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b662 {
namespace {
void f_00058670(Memory&,State&,Frame&,const Operations&);
void f_002d0250(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_00058670(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00458670: { // 0x458670: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00458671: { // 0x458671: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00458672: { // 0x458672: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00458673: { // 0x458673: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00458674: { // 0x458674: 8bd9 MOV EBX, ECX
    s.bx = s.cx;
  }
  L00458676: { // 0x458676: e8d57b2700 CALL 0x6d0250
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d0250u,4556411u); flags=s.arithmetic_flags;
  }
  L0045867b: { // 0x45867b: 8b0d881b8200 MOV ECX, dword ptr [0x821b88]
    s.cx = m.r32((0x00821b88u));
  }
  L00458681: { // 0x458681: 8bf0 MOV ESI, EAX
    s.si = s.ax;
  }
  L00458683: { // 0x458683: 8b810c0a0000 MOV EAX, dword ptr [ECX + 0xa0c]
    s.ax = m.r32((s.cx+0x00000a0cu));
  }
  L00458689: { // 0x458689: 8b38 MOV EDI, dword ptr [EAX]
    s.di = m.r32((s.ax));
  }
  L0045868b: { // 0x45868b: 8b97b0030000 MOV EDX, dword ptr [EDI + 0x3b0]
    s.dx = m.r32((s.di+0x000003b0u));
  }
  L00458691: { // 0x458691: 3b1a CMP EBX, dword ptr [EDX]
    (void)integer::sub(s.bx,m.r32((s.dx)),32,flags);
  }
  L00458693: { // 0x458693: 752e JNZ 0x4586c3
    if(integer::condition("JNZ",flags)) goto L004586c3;
  }
  L00458695: { // 0x458695: 8a912c140000 MOV DL, byte ptr [ECX + 0x142c]
    s.dx = with_al(s.dx, m.r8((s.cx+0x0000142cu)));
  }
  L0045869b: { // 0x45869b: 84d2 TEST DL, DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L0045869d: { // 0x45869d: 7524 JNZ 0x4586c3
    if(integer::condition("JNZ",flags)) goto L004586c3;
  }
  L0045869f: { // 0x45869f: 8b4004 MOV EAX, dword ptr [EAX + 4]
    s.ax = m.r32((s.ax+4u));
  }
  L004586a2: { // 0x4586a2: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L004586a4: { // 0x4586a4: 8b10 MOV EDX, dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L004586a6: { // 0x4586a6: ff92ac000000 CALL dword ptr [EDX + 0xac]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000000acu)),4556460u); flags=s.arithmetic_flags;
  }
  L004586ac: { // 0x4586ac: 8be8 MOV EBP, EAX
    s.bp = s.ax;
  }
  L004586ae: { // 0x4586ae: 8b07 MOV EAX, dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L004586b0: { // 0x4586b0: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L004586b2: { // 0x4586b2: ff90ac000000 CALL dword ptr [EAX + 0xac]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000000acu)),4556472u); flags=s.arithmetic_flags;
  }
  L004586b8: { // 0x4586b8: 03c5 ADD EAX, EBP
    s.ax = integer::add(s.ax,s.bp,32,flags);
  }
  L004586ba: { // 0x4586ba: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004586bb: { // 0x4586bb: 2bc2 SUB EAX, EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004586bd: { // 0x4586bd: d1f8 SAR EAX, 1
    s.ax = integer::shift(s.ax,1u,32,flags,integer::Shift::arithmetic_right);
  }
  L004586bf: { // 0x4586bf: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L004586c1: { // 0x4586c1: 03f0 ADD ESI, EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L004586c3: { // 0x4586c3: 8b9b380c0000 MOV EBX, dword ptr [EBX + 0xc38]
    s.bx = m.r32((s.bx+0x00000c38u));
  }
  L004586c9: { // 0x4586c9: 85db TEST EBX, EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L004586cb: { // 0x4586cb: 741b JZ 0x4586e8
    if(integer::condition("JZ",flags)) goto L004586e8;
  }
  L004586cd: { // 0x4586cd: 8b13 MOV EDX, dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L004586cf: { // 0x4586cf: 8bcb MOV ECX, EBX
    s.cx = s.bx;
  }
  L004586d1: { // 0x4586d1: ff92ac000000 CALL dword ptr [EDX + 0xac]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000000acu)),4556503u); flags=s.arithmetic_flags;
  }
  L004586d7: { // 0x4586d7: 2bf0 SUB ESI, EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  L004586d9: { // 0x4586d9: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004586db: { // 0x4586db: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L004586dd: { // 0x4586dd: 0f9ec0 SETLE AL
    s.ax = with_al(s.ax, (integer::condition("SETLE",flags)?1u:0u));
  }
  L004586e0: { // 0x4586e0: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L004586e1: { // 0x4586e1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004586e2: { // 0x4586e2: 23c6 AND EAX, ESI
    s.ax = integer::logical((s.ax)&(s.si),32,flags);
  }
  L004586e4: { // 0x4586e4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004586e5: { // 0x4586e5: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004586e6: { // 0x4586e6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004586e7: { // 0x4586e7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004586e8: { // 0x4586e8: 8bc6 MOV EAX, ESI
    s.ax = s.si;
  }
  L004586ea: { // 0x4586ea: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004586eb: { // 0x4586eb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004586ec: { // 0x4586ec: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004586ed: { // 0x4586ed: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004586ee: { // 0x4586ee: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002d0250(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006d0250: { // 0x6d0250: 8b8150050000 MOV EAX, dword ptr [ECX + 0x550]
    s.ax = m.r32((s.cx+0x00000550u));
  }
  L006d0256: { // 0x6d0256: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4556400u:f_00058670(m,s,child,{});break;
case 7144016u:f_002d0250(m,s,child,{});break;
default:throw std::domain_error("recovery662 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_004a6720(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004a6720: { // 0x4a6720: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004a6721: { // 0x4a6721: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004a6722: { // 0x4a6722: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004a6724: { // 0x4a6724: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L004a6727: { // 0x4a6727: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004a6729: { // 0x4a6729: 0f8eb2000000 JLE 0x004a67e1
    if(integer::condition("JLE",flags)) goto L004a67e1;
  }
  L004a672f: { // 0x4a672f: 8b5c240c MOV EBX,dword ptr [ESP + 0xc]
    s.bx = m.r32((f.sp+0x0000000cu));
  }
  L004a6733: { // 0x4a6733: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L004a6735: { // 0x4a6735: 0f8ca6000000 JL 0x004a67e1
    if(integer::condition("JL",flags)) goto L004a67e1;
  }
  L004a673b: { // 0x4a673b: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L004a673d: { // 0x4a673d: 0f8d9e000000 JGE 0x004a67e1
    if(integer::condition("JGE",flags)) goto L004a67e1;
  }
  L004a6743: { // 0x4a6743: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L004a6749: { // 0x4a6749: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004a674a: { // 0x4a674a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004a674b: { // 0x4a674b: 8b9164220000 MOV EDX,dword ptr [ECX + 0x2264]
    s.dx = m.r32((s.cx+0x00002264u));
  }
  L004a6751: { // 0x4a6751: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L004a6753: { // 0x4a6753: 743f JZ 0x004a6794
    if(integer::condition("JZ",flags)) goto L004a6794;
  }
  L004a6755: { // 0x4a6755: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004a6757: { // 0x4a6757: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L004a6759: { // 0x4a6759: 7e39 JLE 0x004a6794
    if(integer::condition("JLE",flags)) goto L004a6794;
  }
  L004a675b: { // 0x4a675b: 8b9158220000 MOV EDX,dword ptr [ECX + 0x2258]
    s.dx = m.r32((s.cx+0x00002258u));
  }
  L004a6761: { // 0x4a6761: 8b7c9e14 MOV EDI,dword ptr [ESI + EBX*0x4 + 0x14]
    s.di = m.r32((s.si+(s.bx * 0x00000004u)+0x00000014u));
  }
  L004a6765: { // 0x4a6765: 393c82 CMP dword ptr [EDX + EAX*0x4],EDI
    (void)integer::sub(m.r32((s.dx+(s.ax * 0x00000004u))),s.di,32,flags);
  }
  L004a6768: { // 0x4a6768: 750d JNZ 0x004a6777
    if(integer::condition("JNZ",flags)) goto L004a6777;
  }
  L004a676a: { // 0x4a676a: 8ba974220000 MOV EBP,dword ptr [ECX + 0x2274]
    s.bp = m.r32((s.cx+0x00002274u));
  }
  L004a6770: { // 0x4a6770: 837c8500ff CMP dword ptr [EBP + EAX*0x4],-0x1
    (void)integer::sub(m.r32((s.bp+(s.ax * 0x00000004u))),0xffffffffu,32,flags);
  }
  L004a6775: { // 0x4a6775: 750d JNZ 0x004a6784
    if(integer::condition("JNZ",flags)) goto L004a6784;
  }
  L004a6777: { // 0x4a6777: 8ba964220000 MOV EBP,dword ptr [ECX + 0x2264]
    s.bp = m.r32((s.cx+0x00002264u));
  }
  L004a677d: { // 0x4a677d: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004a677e: { // 0x4a677e: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L004a6780: { // 0x4a6780: 7ce3 JL 0x004a6765
    if(integer::condition("JL",flags)) goto L004a6765;
  }
  L004a6782: { // 0x4a6782: eb10 JMP 0x004a6794
    goto L004a6794;
  }
  L004a6784: { // 0x4a6784: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L004a6787: { // 0x4a6787: 740b JZ 0x004a6794
    if(integer::condition("JZ",flags)) goto L004a6794;
  }
  L004a6789: { // 0x4a6789: 8b8990220000 MOV ECX,dword ptr [ECX + 0x2290]
    s.cx = m.r32((s.cx+0x00002290u));
  }
  L004a678f: { // 0x4a678f: 8d0481 LEA EAX,[ECX + EAX*0x4]
    s.ax = (s.cx+(s.ax * 0x00000004u));
  }
  L004a6792: { // 0x4a6792: ff08 DEC dword ptr [EAX]
    m.w32((s.ax), integer::decrement(m.r32((s.ax)),32,flags));
  }
  L004a6794: { // 0x4a6794: 8b4c9e14 MOV ECX,dword ptr [ESI + EBX*0x4 + 0x14]
    s.cx = m.r32((s.si+(s.bx * 0x00000004u)+0x00000014u));
  }
  L004a6798: { // 0x4a6798: 8d7c9e14 LEA EDI,[ESI + EBX*0x4 + 0x14]
    s.di = (s.si+(s.bx * 0x00000004u)+0x00000014u);
  }
  L004a679c: { // 0x4a679c: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L004a679e: { // 0x4a679e: ff92ac000000 CALL dword ptr [EDX + 0xac]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000000acu)),4876196u); flags=s.arithmetic_flags;
  }
  L004a67a4: { // 0x4a67a4: 8b4e28 MOV ECX,dword ptr [ESI + 0x28]
    s.cx = m.r32((s.si+0x00000028u));
  }
  L004a67a7: { // 0x4a67a7: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L004a67a9: { // 0x4a67a9: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L004a67ac: { // 0x4a67ac: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L004a67ad: { // 0x4a67ad: 894e28 MOV dword ptr [ESI + 0x28],ECX
    m.w32((s.si+0x00000028u), s.cx);
  }
  L004a67b0: { // 0x4a67b0: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L004a67b2: { // 0x4a67b2: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L004a67b4: { // 0x4a67b4: 7d13 JGE 0x004a67c9
    if(integer::condition("JGE",flags)) goto L004a67c9;
  }
  L004a67b6: { // 0x4a67b6: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L004a67b8: { // 0x4a67b8: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L004a67bb: { // 0x4a67bb: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L004a67bc: { // 0x4a67bc: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L004a67be: { // 0x4a67be: 8b5610 MOV EDX,dword ptr [ESI + 0x10]
    s.dx = m.r32((s.si+0x00000010u));
  }
  L004a67c1: { // 0x4a67c1: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  L004a67c4: { // 0x4a67c4: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L004a67c5: { // 0x4a67c5: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L004a67c7: { // 0x4a67c7: 7cef JL 0x004a67b8
    if(integer::condition("JL",flags)) goto L004a67b8;
  }
  L004a67c9: { // 0x4a67c9: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L004a67cc: { // 0x4a67cc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004a67cd: { // 0x4a67cd: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L004a67ce: { // 0x4a67ce: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004a67cf: { // 0x4a67cf: 894610 MOV dword ptr [ESI + 0x10],EAX
    m.w32((s.si+0x00000010u), s.ax);
  }
  L004a67d2: { // 0x4a67d2: c744861400000000 MOV dword ptr [ESI + EAX*0x4 + 0x14],0x0
    m.w32((s.si+(s.ax * 0x00000004u)+0x00000014u), 0x00000000u);
  }
  L004a67da: { // 0x4a67da: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004a67db: { // 0x4a67db: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L004a67dd: { // 0x4a67dd: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004a67de: { // 0x4a67de: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004a67e1: { // 0x4a67e1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004a67e2: { // 0x4a67e2: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004a67e4: { // 0x4a67e4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004a67e5: { // 0x4a67e5: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
