#include "recovered/recovery_b545_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b545 {
namespace {
void f_0007cc40(Memory&,State&,Frame&,const Operations&);
void f_00053ab0(Memory&,State&,Frame&,const Operations&);
void f_0001fdf0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_0007cc40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0047cc40: { // 0x47cc40: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L0047cc44: { // 0x47cc44: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L0047cc46: { // 0x47cc46: 8b4904 MOV ECX,dword ptr [ECX + 0x4]
    s.cx = m.r32((s.cx+0x00000004u));
  }
  L0047cc49: { // 0x47cc49: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0047cc4a: { // 0x47cc4a: 8b30 MOV ESI,dword ptr [EAX]
    s.si = m.r32((s.ax));
  }
  L0047cc4c: { // 0x47cc4c: 2bd6 SUB EDX,ESI
    s.dx = integer::sub(s.dx,s.si,32,flags);
  }
  L0047cc4e: { // 0x47cc4e: 8b7004 MOV ESI,dword ptr [EAX + 0x4]
    s.si = m.r32((s.ax+0x00000004u));
  }
  L0047cc51: { // 0x47cc51: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L0047cc55: { // 0x47cc55: 2bce SUB ECX,ESI
    s.cx = integer::sub(s.cx,s.si,32,flags);
  }
  L0047cc57: { // 0x47cc57: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047cc58: { // 0x47cc58: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L0047cc5a: { // 0x47cc5a: 894804 MOV dword ptr [EAX + 0x4],ECX
    m.w32((s.ax+0x00000004u), s.cx);
  }
  L0047cc5d: { // 0x47cc5d: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00053ab0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00453ab0: { // 0x453ab0: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00453ab2: { // 0x453ab2: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L00453ab6: { // 0x453ab6: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00453ab8: { // 0x453ab8: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L00453aba: { // 0x453aba: 8b4904 MOV ECX,dword ptr [ECX + 0x4]
    s.cx = m.r32((s.cx+0x00000004u));
  }
  L00453abd: { // 0x453abd: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L00453ac1: { // 0x453ac1: 894804 MOV dword ptr [EAX + 0x4],ECX
    m.w32((s.ax+0x00000004u), s.cx);
  }
  L00453ac4: { // 0x453ac4: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L00453ac8: { // 0x453ac8: 895008 MOV dword ptr [EAX + 0x8],EDX
    m.w32((s.ax+0x00000008u), s.dx);
  }
  L00453acb: { // 0x453acb: 89480c MOV dword ptr [EAX + 0xc],ECX
    m.w32((s.ax+0x0000000cu), s.cx);
  }
  L00453ace: { // 0x453ace: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
void f_0001fdf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0041fdf0: { // 0x41fdf0: 83ec18 SUB ESP,0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
  L0041fdf3: { // 0x41fdf3: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0041fdf5: { // 0x41fdf5: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0041fdf6: { // 0x41fdf6: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L0041fdfa: { // 0x41fdfa: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0041fdfb: { // 0x41fdfb: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0041fdfc: { // 0x41fdfc: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0041fdfe: { // 0x41fdfe: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0041fdff: { // 0x41fdff: 8b1e MOV EBX,dword ptr [ESI]
    s.bx = m.r32((s.si));
  }
  L0041fe01: { // 0x41fe01: 8b7e04 MOV EDI,dword ptr [ESI + 0x4]
    s.di = m.r32((s.si+0x00000004u));
  }
  L0041fe04: { // 0x41fe04: 8b6e08 MOV EBP,dword ptr [ESI + 0x8]
    s.bp = m.r32((s.si+0x00000008u));
  }
  L0041fe07: { // 0x41fe07: 896c2420 MOV dword ptr [ESP + 0x20],EBP
    m.w32((f.sp+0x00000020u), s.bp);
  }
  L0041fe0b: { // 0x41fe0b: 8b760c MOV ESI,dword ptr [ESI + 0xc]
    s.si = m.r32((s.si+0x0000000cu));
  }
  L0041fe0e: { // 0x41fe0e: 89742424 MOV dword ptr [ESP + 0x24],ESI
    m.w32((f.sp+0x00000024u), s.si);
  }
  L0041fe12: { // 0x41fe12: 8b7208 MOV ESI,dword ptr [EDX + 0x8]
    s.si = m.r32((s.dx+0x00000008u));
  }
  L0041fe15: { // 0x41fe15: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0041fe17: { // 0x41fe17: 0f8edb000000 JLE 0x0041fef8
    if(integer::condition("JLE",flags)) goto L0041fef8;
  }
  L0041fe1d: { // 0x41fe1d: 8b6a0c MOV EBP,dword ptr [EDX + 0xc]
    s.bp = m.r32((s.dx+0x0000000cu));
  }
  L0041fe20: { // 0x41fe20: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0041fe22: { // 0x41fe22: 896c2414 MOV dword ptr [ESP + 0x14],EBP
    m.w32((f.sp+0x00000014u), s.bp);
  }
  L0041fe26: { // 0x41fe26: 0f8ecc000000 JLE 0x0041fef8
    if(integer::condition("JLE",flags)) goto L0041fef8;
  }
  L0041fe2c: { // 0x41fe2c: 8b6908 MOV EBP,dword ptr [ECX + 0x8]
    s.bp = m.r32((s.cx+0x00000008u));
  }
  L0041fe2f: { // 0x41fe2f: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0041fe31: { // 0x41fe31: 0f8ec1000000 JLE 0x0041fef8
    if(integer::condition("JLE",flags)) goto L0041fef8;
  }
  L0041fe37: { // 0x41fe37: 8b690c MOV EBP,dword ptr [ECX + 0xc]
    s.bp = m.r32((s.cx+0x0000000cu));
  }
  L0041fe3a: { // 0x41fe3a: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0041fe3c: { // 0x41fe3c: 0f8eb6000000 JLE 0x0041fef8
    if(integer::condition("JLE",flags)) goto L0041fef8;
  }
  L0041fe42: { // 0x41fe42: 8b0a MOV ECX,dword ptr [EDX]
    s.cx = m.r32((s.dx));
  }
  L0041fe44: { // 0x41fe44: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L0041fe46: { // 0x41fe46: 7d0e JGE 0x0041fe56
    if(integer::condition("JGE",flags)) goto L0041fe56;
  }
  L0041fe48: { // 0x41fe48: 8b6c2420 MOV EBP,dword ptr [ESP + 0x20]
    s.bp = m.r32((f.sp+0x00000020u));
  }
  L0041fe4c: { // 0x41fe4c: 2bd9 SUB EBX,ECX
    s.bx = integer::sub(s.bx,s.cx,32,flags);
  }
  L0041fe4e: { // 0x41fe4e: 03eb ADD EBP,EBX
    s.bp = integer::add(s.bp,s.bx,32,flags);
  }
  L0041fe50: { // 0x41fe50: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0041fe52: { // 0x41fe52: 896c2420 MOV dword ptr [ESP + 0x20],EBP
    m.w32((f.sp+0x00000020u), s.bp);
  }
  L0041fe56: { // 0x41fe56: 837c242001 CMP dword ptr [ESP + 0x20],0x1
    (void)integer::sub(m.r32((f.sp+0x00000020u)),0x00000001u,32,flags);
  }
  L0041fe5b: { // 0x41fe5b: 0f8c97000000 JL 0x0041fef8
    if(integer::condition("JL",flags)) goto L0041fef8;
  }
  L0041fe61: { // 0x41fe61: 8b5204 MOV EDX,dword ptr [EDX + 0x4]
    s.dx = m.r32((s.dx+0x00000004u));
  }
  L0041fe64: { // 0x41fe64: 3bfa CMP EDI,EDX
    (void)integer::sub(s.di,s.dx,32,flags);
  }
  L0041fe66: { // 0x41fe66: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L0041fe6a: { // 0x41fe6a: 7d0e JGE 0x0041fe7a
    if(integer::condition("JGE",flags)) goto L0041fe7a;
  }
  L0041fe6c: { // 0x41fe6c: 8b6c2424 MOV EBP,dword ptr [ESP + 0x24]
    s.bp = m.r32((f.sp+0x00000024u));
  }
  L0041fe70: { // 0x41fe70: 2bfa SUB EDI,EDX
    s.di = integer::sub(s.di,s.dx,32,flags);
  }
  L0041fe72: { // 0x41fe72: 03ef ADD EBP,EDI
    s.bp = integer::add(s.bp,s.di,32,flags);
  }
  L0041fe74: { // 0x41fe74: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L0041fe76: { // 0x41fe76: 896c2424 MOV dword ptr [ESP + 0x24],EBP
    m.w32((f.sp+0x00000024u), s.bp);
  }
  L0041fe7a: { // 0x41fe7a: 837c242401 CMP dword ptr [ESP + 0x24],0x1
    (void)integer::sub(m.r32((f.sp+0x00000024u)),0x00000001u,32,flags);
  }
  L0041fe7f: { // 0x41fe7f: 7c77 JL 0x0041fef8
    if(integer::condition("JL",flags)) goto L0041fef8;
  }
  L0041fe81: { // 0x41fe81: 8b6c2420 MOV EBP,dword ptr [ESP + 0x20]
    s.bp = m.r32((f.sp+0x00000020u));
  }
  L0041fe85: { // 0x41fe85: 8d1431 LEA EDX,[ECX + ESI*0x1]
    s.dx = (s.cx+(s.si * 0x00000001u));
  }
  L0041fe88: { // 0x41fe88: 03eb ADD EBP,EBX
    s.bp = integer::add(s.bp,s.bx,32,flags);
  }
  L0041fe8a: { // 0x41fe8a: 3bea CMP EBP,EDX
    (void)integer::sub(s.bp,s.dx,32,flags);
  }
  L0041fe8c: { // 0x41fe8c: 7e06 JLE 0x0041fe94
    if(integer::condition("JLE",flags)) goto L0041fe94;
  }
  L0041fe8e: { // 0x41fe8e: 2bcb SUB ECX,EBX
    s.cx = integer::sub(s.cx,s.bx,32,flags);
  }
  L0041fe90: { // 0x41fe90: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L0041fe92: { // 0x41fe92: eb04 JMP 0x0041fe98
    goto L0041fe98;
  }
  L0041fe94: { // 0x41fe94: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L0041fe98: { // 0x41fe98: 83f901 CMP ECX,0x1
    (void)integer::sub(s.cx,0x00000001u,32,flags);
  }
  L0041fe9b: { // 0x41fe9b: 7c5b JL 0x0041fef8
    if(integer::condition("JL",flags)) goto L0041fef8;
  }
  L0041fe9d: { // 0x41fe9d: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0041fea1: { // 0x41fea1: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L0041fea5: { // 0x41fea5: 03d6 ADD EDX,ESI
    s.dx = integer::add(s.dx,s.si,32,flags);
  }
  L0041fea7: { // 0x41fea7: 8b742424 MOV ESI,dword ptr [ESP + 0x24]
    s.si = m.r32((f.sp+0x00000024u));
  }
  L0041feab: { // 0x41feab: 8d2c3e LEA EBP,[ESI + EDI*0x1]
    s.bp = (s.si+(s.di * 0x00000001u));
  }
  L0041feae: { // 0x41feae: 3bea CMP EBP,EDX
    (void)integer::sub(s.bp,s.dx,32,flags);
  }
  L0041feb0: { // 0x41feb0: 7e04 JLE 0x0041feb6
    if(integer::condition("JLE",flags)) goto L0041feb6;
  }
  L0041feb2: { // 0x41feb2: 2bd7 SUB EDX,EDI
    s.dx = integer::sub(s.dx,s.di,32,flags);
  }
  L0041feb4: { // 0x41feb4: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L0041feb6: { // 0x41feb6: 83fe01 CMP ESI,0x1
    (void)integer::sub(s.si,0x00000001u,32,flags);
  }
  L0041feb9: { // 0x41feb9: 7c3d JL 0x0041fef8
    if(integer::condition("JL",flags)) goto L0041fef8;
  }
  L0041febb: { // 0x41febb: 8b542430 MOV EDX,dword ptr [ESP + 0x30]
    s.dx = m.r32((f.sp+0x00000030u));
  }
  L0041febf: { // 0x41febf: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0041fec1: { // 0x41fec1: 740b JZ 0x0041fece
    if(integer::condition("JZ",flags)) goto L0041fece;
  }
  L0041fec3: { // 0x41fec3: 8b6c242c MOV EBP,dword ptr [ESP + 0x2c]
    s.bp = m.r32((f.sp+0x0000002cu));
  }
  L0041fec7: { // 0x41fec7: 8b6d00 MOV EBP,dword ptr [EBP]
    s.bp = m.r32((s.bp));
  }
  L0041feca: { // 0x41feca: 2beb SUB EBP,EBX
    s.bp = integer::sub(s.bp,s.bx,32,flags);
  }
  L0041fecc: { // 0x41fecc: 012a ADD dword ptr [EDX],EBP
    m.w32((s.dx), integer::add(m.r32((s.dx)),s.bp,32,flags));
  }
  L0041fece: { // 0x41fece: 8b542434 MOV EDX,dword ptr [ESP + 0x34]
    s.dx = m.r32((f.sp+0x00000034u));
  }
  L0041fed2: { // 0x41fed2: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0041fed4: { // 0x41fed4: 740b JZ 0x0041fee1
    if(integer::condition("JZ",flags)) goto L0041fee1;
  }
  L0041fed6: { // 0x41fed6: 8b6c242c MOV EBP,dword ptr [ESP + 0x2c]
    s.bp = m.r32((f.sp+0x0000002cu));
  }
  L0041feda: { // 0x41feda: 8b6d04 MOV EBP,dword ptr [EBP + 0x4]
    s.bp = m.r32((s.bp+0x00000004u));
  }
  L0041fedd: { // 0x41fedd: 2bef SUB EBP,EDI
    s.bp = integer::sub(s.bp,s.di,32,flags);
  }
  L0041fedf: { // 0x41fedf: 012a ADD dword ptr [EDX],EBP
    m.w32((s.dx), integer::add(m.r32((s.dx)),s.bp,32,flags));
  }
  L0041fee1: { // 0x41fee1: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0041fee3: { // 0x41fee3: 891a MOV dword ptr [EDX],EBX
    m.w32((s.dx), s.bx);
  }
  L0041fee5: { // 0x41fee5: 897a04 MOV dword ptr [EDX + 0x4],EDI
    m.w32((s.dx+0x00000004u), s.di);
  }
  L0041fee8: { // 0x41fee8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0041fee9: { // 0x41fee9: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  L0041feec: { // 0x41feec: 89720c MOV dword ptr [EDX + 0xc],ESI
    m.w32((s.dx+0x0000000cu), s.si);
  }
  L0041feef: { // 0x41feef: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0041fef0: { // 0x41fef0: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0041fef1: { // 0x41fef1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0041fef2: { // 0x41fef2: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L0041fef5: { // 0x41fef5: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L0041fef8: { // 0x41fef8: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0041fefa: { // 0x41fefa: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0041fefc: { // 0x41fefc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0041fefd: { // 0x41fefd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0041fefe: { // 0x41fefe: 890a MOV dword ptr [EDX],ECX
    m.w32((s.dx), s.cx);
  }
  L0041ff00: { // 0x41ff00: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0041ff01: { // 0x41ff01: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0041ff02: { // 0x41ff02: 894a04 MOV dword ptr [EDX + 0x4],ECX
    m.w32((s.dx+0x00000004u), s.cx);
  }
  L0041ff05: { // 0x41ff05: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  L0041ff08: { // 0x41ff08: 894a0c MOV dword ptr [EDX + 0xc],ECX
    m.w32((s.dx+0x0000000cu), s.cx);
  }
  L0041ff0b: { // 0x41ff0b: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L0041ff0e: { // 0x41ff0e: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4705344u:f_0007cc40(m,s,child,{});break;
case 4537008u:f_00053ab0(m,s,child,{});break;
case 4324848u:f_0001fdf0(m,s,child,{});break;
default:throw std::domain_error("recovery545 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00698a30(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00698a30: { // 0x698a30: 8a442404 MOV AL,byte ptr [ESP + 0x4]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000004u)));
  }
  L00698a34: { // 0x698a34: 83ec60 SUB ESP,0x60
    f.sp = integer::sub(f.sp,0x00000060u,32,flags);
  }
  L00698a37: { // 0x698a37: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00698a39: { // 0x698a39: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00698a3a: { // 0x698a3a: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00698a3b: { // 0x698a3b: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00698a3c: { // 0x698a3c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00698a3d: { // 0x698a3d: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L00698a3f: { // 0x698a3f: 0f858e010000 JNZ 0x00698bd3
    if(integer::condition("JNZ",flags)) goto L00698bd3;
  }
  L00698a45: { // 0x698a45: 8b35c860aa00 MOV ESI,dword ptr [0x00aa60c8]
    s.si = m.r32((0x00aa60c8u));
  }
  L00698a4b: { // 0x698a4b: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00698a4d: { // 0x698a4d: 0f8480010000 JZ 0x00698bd3
    if(integer::condition("JZ",flags)) goto L00698bd3;
  }
  L00698a53: { // 0x698a53: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L00698a54: { // 0x698a54: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00698a56: { // 0x698a56: 89742410 MOV dword ptr [ESP + 0x10],ESI
    m.w32((f.sp+0x00000010u), s.si);
  }
  L00698a5a: { // 0x698a5a: 0f8c73010000 JL 0x00698bd3
    if(integer::condition("JL",flags)) goto L00698bd3;
  }
  L00698a60: { // 0x698a60: 8d2cb6 LEA EBP,[ESI + ESI*0x4]
    s.bp = (s.si+(s.si * 0x00000004u));
  }
  L00698a63: { // 0x698a63: c1e502 SHL EBP,0x2
    s.bp = integer::shift(s.bp,0x00000002u,32,flags,integer::Shift::left);
  }
  L00698a66: { // 0x698a66: a1bc60aa00 MOV EAX,[0x00aa60bc]
    s.ax = m.r32((0x00aa60bcu));
  }
  L00698a6b: { // 0x698a6b: 8d0c28 LEA ECX,[EAX + EBP*0x1]
    s.cx = (s.ax+(s.bp * 0x00000001u));
  }
  L00698a6e: { // 0x698a6e: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L00698a70: { // 0x698a70: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L00698a72: { // 0x698a72: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L00698a76: { // 0x698a76: 8b4a04 MOV ECX,dword ptr [EDX + 0x4]
    s.cx = m.r32((s.dx+0x00000004u));
  }
  L00698a79: { // 0x698a79: 894c2434 MOV dword ptr [ESP + 0x34],ECX
    m.w32((f.sp+0x00000034u), s.cx);
  }
  L00698a7d: { // 0x698a7d: 8b7a08 MOV EDI,dword ptr [EDX + 0x8]
    s.di = m.r32((s.dx+0x00000008u));
  }
  L00698a80: { // 0x698a80: 897c2438 MOV dword ptr [ESP + 0x38],EDI
    m.w32((f.sp+0x00000038u), s.di);
  }
  L00698a84: { // 0x698a84: 8b7c2478 MOV EDI,dword ptr [ESP + 0x78]
    s.di = m.r32((f.sp+0x00000078u));
  }
  L00698a88: { // 0x698a88: 8b520c MOV EDX,dword ptr [EDX + 0xc]
    s.dx = m.r32((s.dx+0x0000000cu));
  }
  L00698a8b: { // 0x698a8b: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L00698a8d: { // 0x698a8d: 8954243c MOV dword ptr [ESP + 0x3c],EDX
    m.w32((f.sp+0x0000003cu), s.dx);
  }
  L00698a91: { // 0x698a91: 8b54247c MOV EDX,dword ptr [ESP + 0x7c]
    s.dx = m.r32((f.sp+0x0000007cu));
  }
  L00698a95: { // 0x698a95: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L00698a97: { // 0x698a97: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L00698a9b: { // 0x698a9b: a174198200 MOV EAX,[0x00821974]
    s.ax = m.r32((0x00821974u));
  }
  L00698aa0: { // 0x698aa0: 894c2434 MOV dword ptr [ESP + 0x34],ECX
    m.w32((f.sp+0x00000034u), s.cx);
  }
  L00698aa4: { // 0x698aa4: 8b0d70198200 MOV ECX,dword ptr [0x00821970]
    s.cx = m.r32((0x00821970u));
  }
  L00698aaa: { // 0x698aaa: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00698aae: { // 0x698aae: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L00698ab2: { // 0x698ab2: a17c198200 MOV EAX,[0x0082197c]
    s.ax = m.r32((0x0082197cu));
  }
  L00698ab7: { // 0x698ab7: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L00698abb: { // 0x698abb: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L00698abf: { // 0x698abf: 8b0d78198200 MOV ECX,dword ptr [0x00821978]
    s.cx = m.r32((0x00821978u));
  }
  L00698ac5: { // 0x698ac5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00698ac6: { // 0x698ac6: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L00698aca: { // 0x698aca: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00698acb: { // 0x698acb: 8d442430 LEA EAX,[ESP + 0x30]
    s.ax = (f.sp+0x00000030u);
  }
  L00698acf: { // 0x698acf: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00698ad0: { // 0x698ad0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00698ad1: { // 0x698ad1: 8d4c2430 LEA ECX,[ESP + 0x30]
    s.cx = (f.sp+0x00000030u);
  }
  L00698ad5: { // 0x698ad5: e86641deff CALL 0x0047cc40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047cc40u,6916826u); flags=s.arithmetic_flags;
  }
  L00698ada: { // 0x698ada: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00698adb: { // 0x698adb: 8d4c245c LEA ECX,[ESP + 0x5c]
    s.cx = (f.sp+0x0000005cu);
  }
  L00698adf: { // 0x698adf: e8ccafdbff CALL 0x00453ab0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00453ab0u,6916836u); flags=s.arithmetic_flags;
  }
  L00698ae4: { // 0x698ae4: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00698ae6: { // 0x698ae6: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00698ae8: { // 0x698ae8: 894c2444 MOV dword ptr [ESP + 0x44],ECX
    m.w32((f.sp+0x00000044u), s.cx);
  }
  L00698aec: { // 0x698aec: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00698aee: { // 0x698aee: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L00698af1: { // 0x698af1: 8954244c MOV dword ptr [ESP + 0x4c],EDX
    m.w32((f.sp+0x0000004cu), s.dx);
  }
  L00698af5: { // 0x698af5: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L00698af8: { // 0x698af8: 894c2450 MOV dword ptr [ESP + 0x50],ECX
    m.w32((f.sp+0x00000050u), s.cx);
  }
  L00698afc: { // 0x698afc: 8d4c2468 LEA ECX,[ESP + 0x68]
    s.cx = (f.sp+0x00000068u);
  }
  L00698b00: { // 0x698b00: 8b500c MOV EDX,dword ptr [EAX + 0xc]
    s.dx = m.r32((s.ax+0x0000000cu));
  }
  L00698b03: { // 0x698b03: 8d442438 LEA EAX,[ESP + 0x38]
    s.ax = (f.sp+0x00000038u);
  }
  L00698b07: { // 0x698b07: 89542454 MOV dword ptr [ESP + 0x54],EDX
    m.w32((f.sp+0x00000054u), s.dx);
  }
  L00698b0b: { // 0x698b0b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00698b0c: { // 0x698b0c: 8d54244c LEA EDX,[ESP + 0x4c]
    s.dx = (f.sp+0x0000004cu);
  }
  L00698b10: { // 0x698b10: e8db72d8ff CALL 0x0041fdf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041fdf0u,6916885u); flags=s.arithmetic_flags;
  }
  L00698b15: { // 0x698b15: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00698b17: { // 0x698b17: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00698b19: { // 0x698b19: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L00698b1d: { // 0x698b1d: 8b5104 MOV EDX,dword ptr [ECX + 0x4]
    s.dx = m.r32((s.cx+0x00000004u));
  }
  L00698b20: { // 0x698b20: 89542434 MOV dword ptr [ESP + 0x34],EDX
    m.w32((f.sp+0x00000034u), s.dx);
  }
  L00698b24: { // 0x698b24: 8b5108 MOV EDX,dword ptr [ECX + 0x8]
    s.dx = m.r32((s.cx+0x00000008u));
  }
  L00698b27: { // 0x698b27: 89542438 MOV dword ptr [ESP + 0x38],EDX
    m.w32((f.sp+0x00000038u), s.dx);
  }
  L00698b2b: { // 0x698b2b: 8b15bc60aa00 MOV EDX,dword ptr [0x00aa60bc]
    s.dx = m.r32((0x00aa60bcu));
  }
  L00698b31: { // 0x698b31: 8b490c MOV ECX,dword ptr [ECX + 0xc]
    s.cx = m.r32((s.cx+0x0000000cu));
  }
  L00698b34: { // 0x698b34: 894c243c MOV dword ptr [ESP + 0x3c],ECX
    m.w32((f.sp+0x0000003cu), s.cx);
  }
  L00698b38: { // 0x698b38: 8d0c2a LEA ECX,[EDX + EBP*0x1]
    s.cx = (s.dx+(s.bp * 0x00000001u));
  }
  L00698b3b: { // 0x698b3b: 89042a MOV dword ptr [EDX + EBP*0x1],EAX
    m.w32((s.dx+(s.bp * 0x00000001u)), s.ax);
  }
  L00698b3e: { // 0x698b3e: 8b542434 MOV EDX,dword ptr [ESP + 0x34]
    s.dx = m.r32((f.sp+0x00000034u));
  }
  L00698b42: { // 0x698b42: 895104 MOV dword ptr [ECX + 0x4],EDX
    m.w32((s.cx+0x00000004u), s.dx);
  }
  L00698b45: { // 0x698b45: 8b442438 MOV EAX,dword ptr [ESP + 0x38]
    s.ax = m.r32((f.sp+0x00000038u));
  }
  L00698b49: { // 0x698b49: 894108 MOV dword ptr [ECX + 0x8],EAX
    m.w32((s.cx+0x00000008u), s.ax);
  }
  L00698b4c: { // 0x698b4c: 8b54243c MOV EDX,dword ptr [ESP + 0x3c]
    s.dx = m.r32((f.sp+0x0000003cu));
  }
  L00698b50: { // 0x698b50: 89510c MOV dword ptr [ECX + 0xc],EDX
    m.w32((s.cx+0x0000000cu), s.dx);
  }
  L00698b53: { // 0x698b53: 8b442438 MOV EAX,dword ptr [ESP + 0x38]
    s.ax = m.r32((f.sp+0x00000038u));
  }
  L00698b57: { // 0x698b57: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00698b59: { // 0x698b59: 7e08 JLE 0x00698b63
    if(integer::condition("JLE",flags)) goto L00698b63;
  }
  L00698b5b: { // 0x698b5b: 8b4c243c MOV ECX,dword ptr [ESP + 0x3c]
    s.cx = m.r32((f.sp+0x0000003cu));
  }
  L00698b5f: { // 0x698b5f: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00698b61: { // 0x698b61: 7f3d JG 0x00698ba0
    if(integer::condition("JG",flags)) goto L00698ba0;
  }
  L00698b63: { // 0x698b63: a1c860aa00 MOV EAX,[0x00aa60c8]
    s.ax = m.r32((0x00aa60c8u));
  }
  L00698b68: { // 0x698b68: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L00698b6a: { // 0x698b6a: 7d57 JGE 0x00698bc3
    if(integer::condition("JGE",flags)) goto L00698bc3;
  }
  L00698b6c: { // 0x698b6c: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00698b6d: { // 0x698b6d: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L00698b6f: { // 0x698b6f: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L00698b71: { // 0x698b71: a3c860aa00 MOV [0x00aa60c8],EAX
    m.w32((0x00aa60c8u), s.ax);
  }
  L00698b76: { // 0x698b76: 7d4b JGE 0x00698bc3
    if(integer::condition("JGE",flags)) goto L00698bc3;
  }
  L00698b78: { // 0x698b78: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L00698b7a: { // 0x698b7a: 8b0dbc60aa00 MOV ECX,dword ptr [0x00aa60bc]
    s.cx = m.r32((0x00aa60bcu));
  }
  L00698b80: { // 0x698b80: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L00698b81: { // 0x698b81: 8d740814 LEA ESI,[EAX + ECX*0x1 + 0x14]
    s.si = (s.ax+(s.cx * 0x00000001u)+0x00000014u);
  }
  L00698b85: { // 0x698b85: 8d3c08 LEA EDI,[EAX + ECX*0x1]
    s.di = (s.ax+(s.cx * 0x00000001u));
  }
  L00698b88: { // 0x698b88: b905000000 MOV ECX,0x5
    s.cx = 0x00000005u;
  }
  L00698b8d: { // 0x698b8d: 83c014 ADD EAX,0x14
    s.ax = integer::add(s.ax,0x00000014u,32,flags);
  }
  L00698b90: { // 0x698b90: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L00698b92: { // 0x698b92: 3b15c860aa00 CMP EDX,dword ptr [0x00aa60c8]
    (void)integer::sub(s.dx,m.r32((0x00aa60c8u)),32,flags);
  }
  L00698b98: { // 0x698b98: 7ce0 JL 0x00698b7a
    if(integer::condition("JL",flags)) goto L00698b7a;
  }
  L00698b9a: { // 0x698b9a: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L00698b9e: { // 0x698b9e: eb23 JMP 0x00698bc3
    goto L00698bc3;
  }
  L00698ba0: { // 0x698ba0: 8b7c2430 MOV EDI,dword ptr [ESP + 0x30]
    s.di = m.r32((f.sp+0x00000030u));
  }
  L00698ba4: { // 0x698ba4: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L00698ba7: { // 0x698ba7: 8bd4 MOV EDX,ESP
    s.dx = f.sp;
  }
  L00698ba9: { // 0x698ba9: 893a MOV dword ptr [EDX],EDI
    m.w32((s.dx), s.di);
  }
  L00698bab: { // 0x698bab: 8b7c2444 MOV EDI,dword ptr [ESP + 0x44]
    s.di = m.r32((f.sp+0x00000044u));
  }
  L00698baf: { // 0x698baf: 897a04 MOV dword ptr [EDX + 0x4],EDI
    m.w32((s.dx+0x00000004u), s.di);
  }
  L00698bb2: { // 0x698bb2: 894208 MOV dword ptr [EDX + 0x8],EAX
    m.w32((s.dx+0x00000008u), s.ax);
  }
  L00698bb5: { // 0x698bb5: 894a0c MOV dword ptr [EDX + 0xc],ECX
    m.w32((s.dx+0x0000000cu), s.cx);
  }
  L00698bb8: { // 0x698bb8: 8b0dac1f8200 MOV ECX,dword ptr [0x00821fac]
    s.cx = m.r32((0x00821facu));
  }
  L00698bbe: { // 0x698bbe: e83d8f0c00 CALL 0x00761b00
    s.arithmetic_flags=flags; invoke(m,s,f,0x00761b00u,6917059u); flags=s.arithmetic_flags;
  }
  L00698bc3: { // 0x698bc3: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L00698bc4: { // 0x698bc4: 83ed14 SUB EBP,0x14
    s.bp = integer::sub(s.bp,0x00000014u,32,flags);
  }
  L00698bc7: { // 0x698bc7: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00698bc9: { // 0x698bc9: 89742410 MOV dword ptr [ESP + 0x10],ESI
    m.w32((f.sp+0x00000010u), s.si);
  }
  L00698bcd: { // 0x698bcd: 0f8d93feffff JGE 0x00698a66
    if(integer::condition("JGE",flags)) goto L00698a66;
  }
  L00698bd3: { // 0x698bd3: 8b83e0000000 MOV EAX,dword ptr [EBX + 0xe0]
    s.ax = m.r32((s.bx+0x000000e0u));
  }
  L00698bd9: { // 0x698bd9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00698bdb: { // 0x698bdb: 0f8eb7000000 JLE 0x00698c98
    if(integer::condition("JLE",flags)) goto L00698c98;
  }
  L00698be1: { // 0x698be1: 8a4c2474 MOV CL,byte ptr [ESP + 0x74]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000074u)));
  }
  L00698be5: { // 0x698be5: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00698be7: { // 0x698be7: 0f85ab000000 JNZ 0x00698c98
    if(integer::condition("JNZ",flags)) goto L00698c98;
  }
  L00698bed: { // 0x698bed: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L00698bef: { // 0x698bef: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00698bf1: { // 0x698bf1: 0f8ea1000000 JLE 0x00698c98
    if(integer::condition("JLE",flags)) goto L00698c98;
  }
  L00698bf7: { // 0x698bf7: 8dbbe4000000 LEA EDI,[EBX + 0xe4]
    s.di = (s.bx+0x000000e4u);
  }
  L00698bfd: { // 0x698bfd: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  L00698bff: { // 0x698bff: 8d442430 LEA EAX,[ESP + 0x30]
    s.ax = (f.sp+0x00000030u);
  }
  L00698c03: { // 0x698c03: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00698c04: { // 0x698c04: e857cdddff CALL 0x00475960
    s.arithmetic_flags=flags; invoke(m,s,f,0x00475960u,6917129u); flags=s.arithmetic_flags;
  }
  L00698c09: { // 0x698c09: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00698c0b: { // 0x698c0b: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L00698c0f: { // 0x698c0f: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L00698c13: { // 0x698c13: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L00698c16: { // 0x698c16: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00698c17: { // 0x698c17: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L00698c1b: { // 0x698c1b: 8d54242c LEA EDX,[ESP + 0x2c]
    s.dx = (f.sp+0x0000002cu);
  }
  L00698c1f: { // 0x698c1f: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L00698c22: { // 0x698c22: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00698c23: { // 0x698c23: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L00698c27: { // 0x698c27: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00698c29: { // 0x698c29: c744242400000000 MOV dword ptr [ESP + 0x24],0x0
    m.w32((f.sp+0x00000024u), 0x00000000u);
  }
  L00698c31: { // 0x698c31: e8aaf1ffff CALL 0x00697de0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00697de0u,6917174u); flags=s.arithmetic_flags;
  }
  L00698c36: { // 0x698c36: 8b93b0000000 MOV EDX,dword ptr [EBX + 0xb0]
    s.dx = m.r32((s.bx+0x000000b0u));
  }
  L00698c3c: { // 0x698c3c: 8bb3b4000000 MOV ESI,dword ptr [EBX + 0xb4]
    s.si = m.r32((s.bx+0x000000b4u));
  }
  L00698c42: { // 0x698c42: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00698c44: { // 0x698c44: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00698c46: { // 0x698c46: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00698c48: { // 0x698c48: 8b1570198200 MOV EDX,dword ptr [0x00821970]
    s.dx = m.r32((0x00821970u));
  }
  L00698c4e: { // 0x698c4e: 8b4904 MOV ECX,dword ptr [ECX + 0x4]
    s.cx = m.r32((s.cx+0x00000004u));
  }
  L00698c51: { // 0x698c51: 2bce SUB ECX,ESI
    s.cx = integer::sub(s.cx,s.si,32,flags);
  }
  L00698c53: { // 0x698c53: 8b3574198200 MOV ESI,dword ptr [0x00821974]
    s.si = m.r32((0x00821974u));
  }
  L00698c59: { // 0x698c59: 8d4410e2 LEA EAX,[EAX + EDX*0x1 + -0x1e]
    s.ax = (s.ax+(s.dx * 0x00000001u)-0x0000001eu);
  }
  L00698c5d: { // 0x698c5d: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L00698c61: { // 0x698c61: a150deb000 MOV EAX,[0x00b0de50]
    s.ax = m.r32((0x00b0de50u));
  }
  L00698c66: { // 0x698c66: 8d4c0ef1 LEA ECX,[ESI + ECX*0x1 + -0xf]
    s.cx = (s.si+(s.cx * 0x00000001u)-0x0000000fu);
  }
  L00698c6a: { // 0x698c6a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00698c6c: { // 0x698c6c: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L00698c70: { // 0x698c70: 7414 JZ 0x00698c86
    if(integer::condition("JZ",flags)) goto L00698c86;
  }
  L00698c72: { // 0x698c72: 8b942480000000 MOV EDX,dword ptr [ESP + 0x80]
    s.dx = m.r32((f.sp+0x00000080u));
  }
  L00698c79: { // 0x698c79: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  L00698c7b: { // 0x698c7b: 8d442420 LEA EAX,[ESP + 0x20]
    s.ax = (f.sp+0x00000020u);
  }
  L00698c7f: { // 0x698c7f: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00698c80: { // 0x698c80: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00698c81: { // 0x698c81: e82ac4ddff CALL 0x004750b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004750b0u,6917254u); flags=s.arithmetic_flags;
  }
  L00698c86: { // 0x698c86: 8b83e0000000 MOV EAX,dword ptr [EBX + 0xe0]
    s.ax = m.r32((s.bx+0x000000e0u));
  }
  L00698c8c: { // 0x698c8c: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L00698c8d: { // 0x698c8d: 83c704 ADD EDI,0x4
    s.di = integer::add(s.di,0x00000004u,32,flags);
  }
  L00698c90: { // 0x698c90: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L00698c92: { // 0x698c92: 0f8c65ffffff JL 0x00698bfd
    if(integer::condition("JL",flags)) goto L00698bfd;
  }
  L00698c98: { // 0x698c98: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00698c99: { // 0x698c99: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00698c9a: { // 0x698c9a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00698c9b: { // 0x698c9b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00698c9c: { // 0x698c9c: 83c460 ADD ESP,0x60
    f.sp = integer::add(f.sp,0x00000060u,32,flags);
  }
  L00698c9f: { // 0x698c9f: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
