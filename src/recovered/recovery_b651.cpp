#include "recovered/recovery_b651_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b651 {
namespace {
void f_000cde40(Memory&,State&,Frame&,const Operations&);
void f_000547a0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_000cde40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004cde40: { // 0x4cde40: 8b5110 MOV EDX, dword ptr [ECX + 0x10]
    s.dx = m.r32((s.cx+0x00000010u));
  }
  L004cde43: { // 0x4cde43: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004cde45: { // 0x4cde45: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004cde46: { // 0x4cde46: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L004cde48: { // 0x4cde48: 7e15 JLE 0x4cde5f
    if(integer::condition("JLE",flags)) goto L004cde5f;
  }
  L004cde4a: { // 0x4cde4a: 8b742408 MOV ESI, dword ptr [ESP + 8]
    s.si = m.r32((f.sp+8u));
  }
  L004cde4e: { // 0x4cde4e: 8b4904 MOV ECX, dword ptr [ECX + 4]
    s.cx = m.r32((s.cx+4u));
  }
  L004cde51: { // 0x4cde51: 8b36 MOV ESI, dword ptr [ESI]
    s.si = m.r32((s.si));
  }
  L004cde53: { // 0x4cde53: 3931 CMP dword ptr [ECX], ESI
    (void)integer::sub(m.r32((s.cx)),s.si,32,flags);
  }
  L004cde55: { // 0x4cde55: 740b JZ 0x4cde62
    if(integer::condition("JZ",flags)) goto L004cde62;
  }
  L004cde57: { // 0x4cde57: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004cde58: { // 0x4cde58: 83c104 ADD ECX, 4
    s.cx = integer::add(s.cx,4u,32,flags);
  }
  L004cde5b: { // 0x4cde5b: 3bc2 CMP EAX, EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L004cde5d: { // 0x4cde5d: 7cf4 JL 0x4cde53
    if(integer::condition("JL",flags)) goto L004cde53;
  }
  L004cde5f: { // 0x4cde5f: 83c8ff OR EAX, 0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L004cde62: { // 0x4cde62: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004cde63: { // 0x4cde63: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000547a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004547a0: { // 0x4547a0: 8b5110 MOV EDX,dword ptr [ECX + 0x10]
    s.dx = m.r32((s.cx+0x00000010u));
  }
  L004547a3: { // 0x4547a3: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L004547a7: { // 0x4547a7: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L004547a9: { // 0x4547a9: 7d21 JGE 0x004547cc
    if(integer::condition("JGE",flags)) goto L004547cc;
  }
  L004547ab: { // 0x4547ab: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L004547ac: { // 0x4547ac: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L004547ae: { // 0x4547ae: 895110 MOV dword ptr [ECX + 0x10],EDX
    m.w32((s.cx+0x00000010u), s.dx);
  }
  L004547b1: { // 0x4547b1: 7d14 JGE 0x004547c7
    if(integer::condition("JGE",flags)) goto L004547c7;
  }
  L004547b3: { // 0x4547b3: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004547b4: { // 0x4547b4: 8b5104 MOV EDX,dword ptr [ECX + 0x4]
    s.dx = m.r32((s.cx+0x00000004u));
  }
  L004547b7: { // 0x4547b7: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004547b8: { // 0x4547b8: 8b3482 MOV ESI,dword ptr [EDX + EAX*0x4]
    s.si = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L004547bb: { // 0x4547bb: 897482fc MOV dword ptr [EDX + EAX*0x4 + -0x4],ESI
    m.w32((s.dx+(s.ax * 0x00000004u)-0x00000004u), s.si);
  }
  L004547bf: { // 0x4547bf: 8b5110 MOV EDX,dword ptr [ECX + 0x10]
    s.dx = m.r32((s.cx+0x00000010u));
  }
  L004547c2: { // 0x4547c2: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L004547c4: { // 0x4547c4: 7cee JL 0x004547b4
    if(integer::condition("JL",flags)) goto L004547b4;
  }
  L004547c6: { // 0x4547c6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004547c7: { // 0x4547c7: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L004547c9: { // 0x4547c9: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004547cc: { // 0x4547cc: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004547ce: { // 0x4547ce: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 5037632u:f_000cde40(m,s,child,{});break;
case 4540320u:f_000547a0(m,s,child,{});break;
default:throw std::domain_error("recovery651 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00692660(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00692660: { // 0x692660: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L00692663: { // 0x692663: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00692664: { // 0x692664: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00692665: { // 0x692665: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00692667: { // 0x692667: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00692669: { // 0x692669: 8b4650 MOV EAX,dword ptr [ESI + 0x50]
    s.ax = m.r32((s.si+0x00000050u));
  }
  L0069266c: { // 0x69266c: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0069266e: { // 0x69266e: 7430 JZ 0x006926a0
    if(integer::condition("JZ",flags)) goto L006926a0;
  }
  L00692670: { // 0x692670: 889875010000 MOV byte ptr [EAX + 0x175],BL
    m.w8((s.ax+0x00000175u), (s.bx & 0xffu));
  }
  L00692676: { // 0x692676: 895e50 MOV dword ptr [ESI + 0x50],EBX
    m.w32((s.si+0x00000050u), s.bx);
  }
  L00692679: { // 0x692679: 8b150087aa00 MOV EDX,dword ptr [0x00aa8700]
    s.dx = m.r32((0x00aa8700u));
  }
  L0069267f: { // 0x69267f: 8d442408 LEA EAX,[ESP + 0x8]
    s.ax = (f.sp+0x00000008u);
  }
  L00692683: { // 0x692683: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00692684: { // 0x692684: b90087aa00 MOV ECX,0xaa8700
    s.cx = 0x00aa8700u;
  }
  L00692689: { // 0x692689: 8974240c MOV dword ptr [ESP + 0xc],ESI
    m.w32((f.sp+0x0000000cu), s.si);
  }
  L0069268d: { // 0x69268d: ff5210 CALL dword ptr [EDX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000010u)),6891152u); flags=s.arithmetic_flags;
  }
  L00692690: { // 0x692690: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00692693: { // 0x692693: 740b JZ 0x006926a0
    if(integer::condition("JZ",flags)) goto L006926a0;
  }
  L00692695: { // 0x692695: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00692696: { // 0x692696: b90087aa00 MOV ECX,0xaa8700
    s.cx = 0x00aa8700u;
  }
  L0069269b: { // 0x69269b: e80021dcff CALL 0x004547a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004547a0u,6891168u); flags=s.arithmetic_flags;
  }
  L006926a0: { // 0x6926a0: 385e54 CMP byte ptr [ESI + 0x54],BL
    (void)integer::sub(m.r8((s.si+0x00000054u)),(s.bx & 0xffu),8,flags);
  }
  L006926a3: { // 0x6926a3: 742a JZ 0x006926cf
    if(integer::condition("JZ",flags)) goto L006926cf;
  }
  L006926a5: { // 0x6926a5: 8b150087aa00 MOV EDX,dword ptr [0x00aa8700]
    s.dx = m.r32((0x00aa8700u));
  }
  L006926ab: { // 0x6926ab: 8d442408 LEA EAX,[ESP + 0x8]
    s.ax = (f.sp+0x00000008u);
  }
  L006926af: { // 0x6926af: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006926b0: { // 0x6926b0: b90087aa00 MOV ECX,0xaa8700
    s.cx = 0x00aa8700u;
  }
  L006926b5: { // 0x6926b5: 8974240c MOV dword ptr [ESP + 0xc],ESI
    m.w32((f.sp+0x0000000cu), s.si);
  }
  L006926b9: { // 0x6926b9: ff5210 CALL dword ptr [EDX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000010u)),6891196u); flags=s.arithmetic_flags;
  }
  L006926bc: { // 0x6926bc: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L006926bf: { // 0x6926bf: 740b JZ 0x006926cc
    if(integer::condition("JZ",flags)) goto L006926cc;
  }
  L006926c1: { // 0x6926c1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006926c2: { // 0x6926c2: b90087aa00 MOV ECX,0xaa8700
    s.cx = 0x00aa8700u;
  }
  L006926c7: { // 0x6926c7: e8d420dcff CALL 0x004547a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004547a0u,6891212u); flags=s.arithmetic_flags;
  }
  L006926cc: { // 0x6926cc: 885e54 MOV byte ptr [ESI + 0x54],BL
    m.w8((s.si+0x00000054u), (s.bx & 0xffu));
  }
  L006926cf: { // 0x6926cf: 385e55 CMP byte ptr [ESI + 0x55],BL
    (void)integer::sub(m.r8((s.si+0x00000055u)),(s.bx & 0xffu),8,flags);
  }
  L006926d2: { // 0x6926d2: 7452 JZ 0x00692726
    if(integer::condition("JZ",flags)) goto L00692726;
  }
  L006926d4: { // 0x6926d4: 385e57 CMP byte ptr [ESI + 0x57],BL
    (void)integer::sub(m.r8((s.si+0x00000057u)),(s.bx & 0xffu),8,flags);
  }
  L006926d7: { // 0x6926d7: 754d JNZ 0x00692726
    if(integer::condition("JNZ",flags)) goto L00692726;
  }
  L006926d9: { // 0x6926d9: 385e58 CMP byte ptr [ESI + 0x58],BL
    (void)integer::sub(m.r8((s.si+0x00000058u)),(s.bx & 0xffu),8,flags);
  }
  L006926dc: { // 0x6926dc: 7548 JNZ 0x00692726
    if(integer::condition("JNZ",flags)) goto L00692726;
  }
  L006926de: { // 0x6926de: c7465cffffffff MOV dword ptr [ESI + 0x5c],0xffffffff
    m.w32((s.si+0x0000005cu), 0xffffffffu);
  }
  L006926e5: { // 0x6926e5: 8b462c MOV EAX,dword ptr [ESI + 0x2c]
    s.ax = m.r32((s.si+0x0000002cu));
  }
  L006926e8: { // 0x6926e8: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L006926eb: { // 0x6926eb: 7508 JNZ 0x006926f5
    if(integer::condition("JNZ",flags)) goto L006926f5;
  }
  L006926ed: { // 0x6926ed: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  L006926f2: { // 0x6926f2: 89462c MOV dword ptr [ESI + 0x2c],EAX
    m.w32((s.si+0x0000002cu), s.ax);
  }
  L006926f5: { // 0x6926f5: 8b4624 MOV EAX,dword ptr [ESI + 0x24]
    s.ax = m.r32((s.si+0x00000024u));
  }
  L006926f8: { // 0x6926f8: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  L006926fe: { // 0x6926fe: 8b90b0000000 MOV EDX,dword ptr [EAX + 0xb0]
    s.dx = m.r32((s.ax+0x000000b0u));
  }
  L00692704: { // 0x692704: 894e2c MOV dword ptr [ESI + 0x2c],ECX
    m.w32((s.si+0x0000002cu), s.cx);
  }
  L00692707: { // 0x692707: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L0069270b: { // 0x69270b: 894e30 MOV dword ptr [ESI + 0x30],ECX
    m.w32((s.si+0x00000030u), s.cx);
  }
  L0069270e: { // 0x69270e: 895634 MOV dword ptr [ESI + 0x34],EDX
    m.w32((s.si+0x00000034u), s.dx);
  }
  L00692711: { // 0x692711: 3898dd000000 CMP byte ptr [EAX + 0xdd],BL
    (void)integer::sub(m.r8((s.ax+0x000000ddu)),(s.bx & 0xffu),8,flags);
  }
  L00692717: { // 0x692717: 7403 JZ 0x0069271c
    if(integer::condition("JZ",flags)) goto L0069271c;
  }
  L00692719: { // 0x692719: 895e60 MOV dword ptr [ESI + 0x60],EBX
    m.w32((s.si+0x00000060u), s.bx);
  }
  L0069271c: { // 0x69271c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0069271d: { // 0x69271d: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0069271f: { // 0x69271f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00692720: { // 0x692720: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00692723: { // 0x692723: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00692726: { // 0x692726: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00692727: { // 0x692727: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00692729: { // 0x692729: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0069272a: { // 0x69272a: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0069272d: { // 0x69272d: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
