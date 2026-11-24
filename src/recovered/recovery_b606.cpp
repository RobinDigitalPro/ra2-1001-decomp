#include "recovered/recovery_b606_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b606 {
namespace {
void f_000e0030(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_000e0030(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004e0030: { // 0x004e0030: a1ac1c8200 MOV EAX,[0x00821cac]
    s.ax = m.r32((0x00821cacu));
  }
  L004e0035: { // 0x004e0035: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e0037: { // 0x004e0037: 7407 JZ 0x004e0040
    if(integer::condition("JZ",flags)) goto L004e0040;
  }
  L004e0039: { // 0x004e0039: c6807d0d000001 MOV byte ptr [EAX + 0xd7d],0x1
    m.w8((s.ax+0x00000d7du), 0x00000001u);
  }
  L004e0040: { // 0x004e0040: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L004e0044: { // 0x004e0044: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e0046: { // 0x004e0046: 7413 JZ 0x004e005b
    if(integer::condition("JZ",flags)) goto L004e005b;
  }
  L004e0048: { // 0x004e0048: 83790c02 CMP dword ptr [ECX + 0xc],0x2
    (void)integer::sub(m.r32((s.cx+0x0000000cu)),0x00000002u,32,flags);
  }
  L004e004c: { // 0x004e004c: 7403 JZ 0x004e0051
    if(integer::condition("JZ",flags)) goto L004e0051;
  }
  L004e004e: { // 0x004e004e: 89410c MOV dword ptr [ECX + 0xc],EAX
    m.w32((s.cx+0x0000000cu), s.ax);
  }
  L004e0051: { // 0x004e0051: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L004e0056: { // 0x004e0056: e8557a0700 CALL 0x00557ab0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557ab0u,5111899u); flags=s.arithmetic_flags;
  }
  L004e005b: { // 0x004e005b: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 5111856u:f_000e0030(m,s,child,{});break;
default:throw std::domain_error("recovery606 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00672650(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00672650: { // 0x672650: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L00672654: { // 0x672654: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  L00672657: { // 0x672657: 7506 JNZ 0x0067265f
    if(integer::condition("JNZ",flags)) goto L0067265f;
  }
  L00672659: { // 0x672659: 8b91d84e0000 MOV EDX,dword ptr [ECX + 0x4ed8]
    s.dx = m.r32((s.cx+0x00004ed8u));
  }
  L0067265f: { // 0x67265f: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L00672661: { // 0x672661: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00672662: { // 0x672662: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L00672665: { // 0x672665: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00672667: { // 0x672667: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00672668: { // 0x672668: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00672669: { // 0x672669: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0067266a: { // 0x67266a: 8d04c0 LEA EAX,[EAX + EAX*0x8]
    s.ax = (s.ax+(s.ax * 0x00000008u));
  }
  L0067266d: { // 0x67266d: 8b356c198200 MOV ESI,dword ptr [0x0082196c]
    s.si = m.r32((0x0082196cu));
  }
  L00672673: { // 0x672673: 8b2d64198200 MOV EBP,dword ptr [0x00821964]
    s.bp = m.r32((0x00821964u));
  }
  L00672679: { // 0x672679: 8d0442 LEA EAX,[EDX + EAX*0x2]
    s.ax = (s.dx+(s.ax * 0x00000002u));
  }
  L0067267c: { // 0x67267c: 8d1440 LEA EDX,[EAX + EAX*0x2]
    s.dx = (s.ax+(s.ax * 0x00000002u));
  }
  L0067267f: { // 0x67267f: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  L00672684: { // 0x672684: 8a9839220000 MOV BL,byte ptr [EAX + 0x2239]
    s.bx = with_al(s.bx, m.r8((s.ax+0x00002239u)));
  }
  L0067268a: { // 0x67268a: 8dbc9140150000 LEA EDI,[ECX + EDX*0x4 + 0x1540]
    s.di = (s.cx+(s.dx * 0x00000004u)+0x00001540u);
  }
  L00672691: { // 0x672691: 8ad3 MOV DL,BL
    s.dx = with_al(s.dx, (s.bx & 0xffu));
  }
  L00672693: { // 0x672693: f6da NEG DL
    s.dx = with_al(s.dx, integer::sub(0u,(s.dx & 0xffu),8,flags));
  }
  L00672695: { // 0x672695: 1bd2 SBB EDX,EDX
    s.dx = integer::sub(s.dx,s.dx,32,flags,flags&integer::CF);
  }
  L00672697: { // 0x672697: 83e208 AND EDX,0x8
    s.dx = integer::logical((s.dx)&(0x00000008u),32,flags);
  }
  L0067269a: { // 0x67269a: 83c212 ADD EDX,0x12
    s.dx = integer::add(s.dx,0x00000012u,32,flags);
  }
  L0067269d: { // 0x67269d: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L0067269f: { // 0x67269f: 8b156c48aa00 MOV EDX,dword ptr [0x00aa486c]
    s.dx = m.r32((0x00aa486cu));
  }
  L006726a5: { // 0x6726a5: 2bf2 SUB ESI,EDX
    s.si = integer::sub(s.si,s.dx,32,flags);
  }
  L006726a7: { // 0x6726a7: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L006726a9: { // 0x6726a9: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L006726ab: { // 0x6726ab: b81f85eb51 MOV EAX,0x51eb851f
    s.ax = 0x51eb851fu;
  }
  L006726b0: { // 0x6726b0: 8d542af9 LEA EDX,[EDX + EBP*0x1 + -0x7]
    s.dx = (s.dx+(s.bp * 0x00000001u)-0x00000007u);
  }
  L006726b4: { // 0x6726b4: f7ea IMUL EDX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.dx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  L006726b6: { // 0x6726b6: c1fa04 SAR EDX,0x4
    s.dx = integer::shift(s.dx,0x00000004u,32,flags,integer::Shift::arithmetic_right);
  }
  L006726b9: { // 0x6726b9: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L006726bb: { // 0x6726bb: c1e81f SHR EAX,0x1f
    s.ax = integer::shift(s.ax,0x0000001fu,32,flags,integer::Shift::right);
  }
  L006726be: { // 0x6726be: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L006726c0: { // 0x6726c0: 8a442414 MOV AL,byte ptr [ESP + 0x14]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000014u)));
  }
  L006726c4: { // 0x6726c4: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006726c6: { // 0x6726c6: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L006726ca: { // 0x6726ca: 741f JZ 0x006726eb
    if(integer::condition("JZ",flags)) goto L006726eb;
  }
  L006726cc: { // 0x6726cc: 8b4740 MOV EAX,dword ptr [EDI + 0x40]
    s.ax = m.r32((s.di+0x00000040u));
  }
  L006726cf: { // 0x6726cf: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006726d1: { // 0x6726d1: 7463 JZ 0x00672736
    if(integer::condition("JZ",flags)) goto L00672736;
  }
  L006726d3: { // 0x6726d3: 8b4744 MOV EAX,dword ptr [EDI + 0x44]
    s.ax = m.r32((s.di+0x00000044u));
  }
  L006726d6: { // 0x6726d6: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006726d8: { // 0x6726d8: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006726da: { // 0x6726da: 894744 MOV dword ptr [EDI + 0x44],EAX
    m.w32((s.di+0x00000044u), s.ax);
  }
  L006726dd: { // 0x6726dd: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006726df: { // 0x6726df: ff5038 CALL dword ptr [EAX + 0x38]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000038u)),6760162u); flags=s.arithmetic_flags;
  }
  L006726e2: { // 0x6726e2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006726e3: { // 0x6726e3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006726e4: { // 0x6726e4: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006726e5: { // 0x6726e5: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006726e7: { // 0x6726e7: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006726e8: { // 0x6726e8: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006726eb: { // 0x6726eb: f6db NEG BL
    s.bx = with_al(s.bx, integer::sub(0u,(s.bx & 0xffu),8,flags));
  }
  L006726ed: { // 0x6726ed: 1bdb SBB EBX,EBX
    s.bx = integer::sub(s.bx,s.bx,32,flags,flags&integer::CF);
  }
  L006726ef: { // 0x6726ef: b81f85eb51 MOV EAX,0x51eb851f
    s.ax = 0x51eb851fu;
  }
  L006726f4: { // 0x6726f4: 83e308 AND EBX,0x8
    s.bx = integer::logical((s.bx)&(0x00000008u),32,flags);
  }
  L006726f7: { // 0x6726f7: 83c312 ADD EBX,0x12
    s.bx = integer::add(s.bx,0x00000012u,32,flags);
  }
  L006726fa: { // 0x6726fa: 2bf3 SUB ESI,EBX
    s.si = integer::sub(s.si,s.bx,32,flags);
  }
  L006726fc: { // 0x6726fc: 8b5f40 MOV EBX,dword ptr [EDI + 0x40]
    s.bx = m.r32((s.di+0x00000040u));
  }
  L006726ff: { // 0x6726ff: 8d542ef9 LEA EDX,[ESI + EBP*0x1 + -0x7]
    s.dx = (s.si+(s.bp * 0x00000001u)-0x00000007u);
  }
  L00672703: { // 0x672703: f7ea IMUL EDX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.dx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  L00672705: { // 0x672705: c1fa04 SAR EDX,0x4
    s.dx = integer::shift(s.dx,0x00000004u,32,flags,integer::Shift::arithmetic_right);
  }
  L00672708: { // 0x672708: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L0067270a: { // 0x67270a: c1e81f SHR EAX,0x1f
    s.ax = integer::shift(s.ax,0x0000001fu,32,flags,integer::Shift::right);
  }
  L0067270d: { // 0x67270d: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L0067270f: { // 0x67270f: 8b4750 MOV EAX,dword ptr [EDI + 0x50]
    s.ax = m.r32((s.di+0x00000050u));
  }
  L00672712: { // 0x672712: 03d3 ADD EDX,EBX
    s.dx = integer::add(s.dx,s.bx,32,flags);
  }
  L00672714: { // 0x672714: d1e2 SHL EDX,0x1
    s.dx = integer::shift(s.dx,0x00000001u,32,flags,integer::Shift::left);
  }
  L00672716: { // 0x672716: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L00672718: { // 0x672718: 7d1c JGE 0x00672736
    if(integer::condition("JGE",flags)) goto L00672736;
  }
  L0067271a: { // 0x67271a: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0067271e: { // 0x67271e: 8b4744 MOV EAX,dword ptr [EDI + 0x44]
    s.ax = m.r32((s.di+0x00000044u));
  }
  L00672721: { // 0x672721: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00672723: { // 0x672723: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00672725: { // 0x672725: 894744 MOV dword ptr [EDI + 0x44],EAX
    m.w32((s.di+0x00000044u), s.ax);
  }
  L00672728: { // 0x672728: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0067272a: { // 0x67272a: ff5038 CALL dword ptr [EAX + 0x38]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000038u)),6760237u); flags=s.arithmetic_flags;
  }
  L0067272d: { // 0x67272d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0067272e: { // 0x67272e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0067272f: { // 0x67272f: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00672730: { // 0x672730: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00672732: { // 0x672732: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00672733: { // 0x672733: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00672736: { // 0x672736: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00672737: { // 0x672737: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00672738: { // 0x672738: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00672739: { // 0x672739: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0067273b: { // 0x67273b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0067273c: { // 0x67273c: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
