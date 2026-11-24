#include "recovered/recovery_b641_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b641 {
namespace {
void f_00011370(Memory&,State&,Frame&,const Operations&);
void f_000113b0(Memory&,State&,Frame&,const Operations&);
void f_000113c0(Memory&,State&,Frame&,const Operations&);
void f_000112f0(Memory&,State&,Frame&,const Operations&);
void f_000112c0(Memory&,State&,Frame&,const Operations&);
void f_000112d0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_00011370(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00411370: { // 0x411370: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00411371: { // 0x411371: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00411372: { // 0x411372: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00411374: { // 0x411374: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00411375: { // 0x411375: 8b7e0c MOV EDI,dword ptr [ESI + 0xc]
    s.di = m.r32((s.si+0x0000000cu));
  }
  L00411378: { // 0x411378: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0041137a: { // 0x41137a: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0041137b: { // 0x41137b: 897e0c MOV dword ptr [ESI + 0xc],EDI
    m.w32((s.si+0x0000000cu), s.di);
  }
  L0041137e: { // 0x41137e: 8b7e14 MOV EDI,dword ptr [ESI + 0x14]
    s.di = m.r32((s.si+0x00000014u));
  }
  L00411381: { // 0x411381: ff5070 CALL dword ptr [EAX + 0x70]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000070u)),4264836u); flags=s.arithmetic_flags;
  }
  L00411384: { // 0x411384: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00411386: { // 0x411386: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00411388: { // 0x411388: 0faf5c2410 IMUL EBX,dword ptr [ESP + 0x10]
    s.bx = integer::imul(s.bx,m.r32((f.sp+0x00000010u)),32,flags);
  }
  L0041138d: { // 0x41138d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0041138f: { // 0x41138f: ff5274 CALL dword ptr [EDX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000074u)),4264850u); flags=s.arithmetic_flags;
  }
  L00411392: { // 0x411392: 0faf442414 IMUL EAX,dword ptr [ESP + 0x14]
    s.ax = integer::imul(s.ax,m.r32((f.sp+0x00000014u)),32,flags);
  }
  L00411397: { // 0x411397: 03fb ADD EDI,EBX
    s.di = integer::add(s.di,s.bx,32,flags);
  }
  L00411399: { // 0x411399: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L0041139b: { // 0x41139b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0041139c: { // 0x41139c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0041139d: { // 0x41139d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0041139e: { // 0x41139e: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_000113b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004113b0: { // 0x4113b0: 8b4110 MOV EAX,dword ptr [ECX + 0x10]
    s.ax = m.r32((s.cx+0x00000010u));
  }
  L004113b3: { // 0x4113b3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000113c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004113c0: { // 0x004113c0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004113c1: { // 0x004113c1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004113c3: { // 0x004113c3: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004113c5: { // 0x004113c5: ff507c CALL dword ptr [EAX + 0x7c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000007cu)),4264904u); flags=s.arithmetic_flags;
  }
  L004113c8: { // 0x004113c8: 0faf4610 IMUL EAX,dword ptr [ESI + 0x10]
    s.ax = integer::imul(s.ax,m.r32((s.si+0x00000010u)),32,flags);
  }
  L004113cc: { // 0x004113cc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004113cd: { // 0x004113cd: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000112f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004112f0: { // 0x4112f0: 8b410c MOV EAX,dword ptr [ECX + 0xc]
    s.ax = m.r32((s.cx+0x0000000cu));
  }
  L004112f3: { // 0x4112f3: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L004112f4: { // 0x4112f4: 89410c MOV dword ptr [ECX + 0xc],EAX
    m.w32((s.cx+0x0000000cu), s.ax);
  }
  L004112f7: { // 0x4112f7: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L004112f9: { // 0x4112f9: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000112c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004112c0: { // 0x4112c0: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L004112c3: { // 0x4112c3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}


void f_000112d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004112d0: { // 0x4112d0: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L004112d3: { // 0x4112d3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4264816u:f_00011370(m,s,child,{});break;
case 4264880u:f_000113b0(m,s,child,{});break;
case 4264896u:f_000113c0(m,s,child,{});break;
case 4264688u:f_000112f0(m,s,child,{});break;
case 4264640u:f_000112c0(m,s,child,{});break;
case 4264656u:f_000112d0(m,s,child,{});break;
default:throw std::domain_error("recovery641 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_005f64a0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005f64a0: { // 0x5f64a0: 83ec24 SUB ESP,0x24
    f.sp = integer::sub(f.sp,0x00000024u,32,flags);
  }
  L005f64a3: { // 0x5f64a3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005f64a4: { // 0x5f64a4: 8b5c2430 MOV EBX,dword ptr [ESP + 0x30]
    s.bx = m.r32((f.sp+0x00000030u));
  }
  L005f64a8: { // 0x5f64a8: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005f64a9: { // 0x5f64a9: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005f64aa: { // 0x5f64aa: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L005f64ac: { // 0x5f64ac: 8bea MOV EBP,EDX
    s.bp = s.dx;
  }
  L005f64ae: { // 0x5f64ae: 896c2428 MOV dword ptr [ESP + 0x28],EBP
    m.w32((f.sp+0x00000028u), s.bp);
  }
  L005f64b2: { // 0x5f64b2: 8974242c MOV dword ptr [ESP + 0x2c],ESI
    m.w32((f.sp+0x0000002cu), s.si);
  }
  L005f64b6: { // 0x5f64b6: 0faf5e08 IMUL EBX,dword ptr [ESI + 0x8]
    s.bx = integer::imul(s.bx,m.r32((s.si+0x00000008u)),32,flags);
  }
  L005f64ba: { // 0x5f64ba: c1fb10 SAR EBX,0x10
    s.bx = integer::shift(s.bx,0x00000010u,32,flags,integer::Shift::arithmetic_right);
  }
  L005f64bd: { // 0x5f64bd: c744240c01000000 MOV dword ptr [ESP + 0xc],0x1
    m.w32((f.sp+0x0000000cu), 0x00000001u);
  }
  L005f64c5: { // 0x5f64c5: 895c2410 MOV dword ptr [ESP + 0x10],EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
  L005f64c9: { // 0x5f64c9: 0f88b1010000 JS 0x005f6680
    if(integer::condition("JS",flags)) goto L005f6680;
  }
  L005f64cf: { // 0x5f64cf: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L005f64d1: { // 0x5f64d1: 7509 JNZ 0x005f64dc
    if(integer::condition("JNZ",flags)) goto L005f64dc;
  }
  L005f64d3: { // 0x5f64d3: bb01000000 MOV EBX,0x1
    s.bx = 0x00000001u;
  }
  L005f64d8: { // 0x5f64d8: 895c2410 MOV dword ptr [ESP + 0x10],EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
  L005f64dc: { // 0x5f64dc: 8b5500 MOV EDX,dword ptr [EBP]
    s.dx = m.r32((s.bp));
  }
  L005f64df: { // 0x5f64df: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L005f64e1: { // 0x5f64e1: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005f64e3: { // 0x5f64e3: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005f64e4: { // 0x5f64e4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005f64e5: { // 0x5f64e5: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L005f64e7: { // 0x5f64e7: ff525c CALL dword ptr [EDX + 0x5c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000005cu)),6251754u); flags=s.arithmetic_flags;
  }
  L005f64ea: { // 0x5f64ea: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005f64ec: { // 0x5f64ec: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L005f64f0: { // 0x5f64f0: 0f848a010000 JZ 0x005f6680
    if(integer::condition("JZ",flags)) goto L005f6680;
  }
  L005f64f6: { // 0x5f64f6: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  L005f64f9: { // 0x5f64f9: c744243800000000 MOV dword ptr [ESP + 0x38],0x0
    m.w32((f.sp+0x00000038u), 0x00000000u);
  }
  L005f6501: { // 0x5f6501: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005f6503: { // 0x5f6503: 0f8e6f010000 JLE 0x005f6678
    if(integer::condition("JLE",flags)) goto L005f6678;
  }
  L005f6509: { // 0x5f6509: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005f650a: { // 0x5f650a: 8b7c2438 MOV EDI,dword ptr [ESP + 0x38]
    s.di = m.r32((f.sp+0x00000038u));
  }
  L005f650e: { // 0x5f650e: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L005f6511: { // 0x5f6511: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L005f6513: { // 0x5f6513: ff5074 CALL dword ptr [EAX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000074u)),6251798u); flags=s.arithmetic_flags;
  }
  L005f6516: { // 0x5f6516: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L005f6517: { // 0x5f6517: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L005f6519: { // 0x5f6519: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  L005f651c: { // 0x5f651c: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L005f651e: { // 0x5f651e: 8b44243c MOV EAX,dword ptr [ESP + 0x3c]
    s.ax = m.r32((f.sp+0x0000003cu));
  }
  L005f6522: { // 0x5f6522: d1f9 SAR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L005f6524: { // 0x5f6524: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L005f6526: { // 0x5f6526: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005f6528: { // 0x5f6528: 0fafca IMUL ECX,EDX
    s.cx = integer::imul(s.cx,s.dx,32,flags);
  }
  L005f652b: { // 0x5f652b: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L005f652d: { // 0x5f652d: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  L005f6530: { // 0x5f6530: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L005f6531: { // 0x5f6531: 83e203 AND EDX,0x3
    s.dx = integer::logical((s.dx)&(0x00000003u),32,flags);
  }
  L005f6534: { // 0x5f6534: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L005f6536: { // 0x5f6536: c1f802 SAR EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::arithmetic_right);
  }
  L005f6539: { // 0x5f6539: 8d1440 LEA EDX,[EAX + EAX*0x2]
    s.dx = (s.ax+(s.ax * 0x00000002u));
  }
  L005f653c: { // 0x5f653c: 3954243c CMP dword ptr [ESP + 0x3c],EDX
    (void)integer::sub(m.r32((f.sp+0x0000003cu)),s.dx,32,flags);
  }
  L005f6540: { // 0x5f6540: 7508 JNZ 0x005f654a
    if(integer::condition("JNZ",flags)) goto L005f654a;
  }
  L005f6542: { // 0x5f6542: c744241001000000 MOV dword ptr [ESP + 0x10],0x1
    m.w32((f.sp+0x00000010u), 0x00000001u);
  }
  L005f654a: { // 0x5f654a: 3944243c CMP dword ptr [ESP + 0x3c],EAX
    (void)integer::sub(m.r32((f.sp+0x0000003cu)),s.ax,32,flags);
  }
  L005f654e: { // 0x5f654e: 7508 JNZ 0x005f6558
    if(integer::condition("JNZ",flags)) goto L005f6558;
  }
  L005f6550: { // 0x5f6550: c744241000000000 MOV dword ptr [ESP + 0x10],0x0
    m.w32((f.sp+0x00000010u), 0x00000000u);
  }
  L005f6558: { // 0x5f6558: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L005f655a: { // 0x5f655a: 0f8e03010000 JLE 0x005f6663
    if(integer::condition("JLE",flags)) goto L005f6663;
  }
  L005f6560: { // 0x5f6560: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L005f6564: { // 0x5f6564: 895c2420 MOV dword ptr [ESP + 0x20],EBX
    m.w32((f.sp+0x00000020u), s.bx);
  }
  L005f6568: { // 0x5f6568: 8d0c48 LEA ECX,[EAX + ECX*0x2]
    s.cx = (s.ax+(s.cx * 0x00000002u));
  }
  L005f656b: { // 0x5f656b: b8ff000000 MOV EAX,0xff
    s.ax = 0x000000ffu;
  }
  L005f6570: { // 0x5f6570: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L005f6574: { // 0x5f6574: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L005f6578: { // 0x5f6578: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L005f657c: { // 0x5f657c: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L005f657e: { // 0x5f657e: 0f84b9000000 JZ 0x005f663d
    if(integer::condition("JZ",flags)) goto L005f663d;
  }
  L005f6584: { // 0x5f6584: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L005f6585: { // 0x5f6585: f77e08 IDIV dword ptr [ESI + 0x8]
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(m.r32((s.si+0x00000008u)),32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L005f6588: { // 0x5f6588: 668b09 MOV CX,word ptr [ECX]
    s.cx = with_ax(s.cx, m.r16((s.cx)));
  }
  L005f658b: { // 0x5f658b: baff000000 MOV EDX,0xff
    s.dx = 0x000000ffu;
  }
  L005f6590: { // 0x5f6590: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L005f6592: { // 0x5f6592: 81e7ffff0000 AND EDI,0xffff
    s.di = integer::logical((s.di)&(0x0000ffffu),32,flags);
  }
  L005f6598: { // 0x5f6598: 81e6ffff0000 AND ESI,0xffff
    s.si = integer::logical((s.si)&(0x0000ffffu),32,flags);
  }
  L005f659e: { // 0x5f659e: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L005f65a0: { // 0x5f65a0: 668b1d32dfa500 MOV BX,word ptr [0x00a5df32]
    s.bx = with_ax(s.bx, m.r16((0x00a5df32u)));
  }
  L005f65a7: { // 0x5f65a7: 897c2428 MOV dword ptr [ESP + 0x28],EDI
    m.w32((f.sp+0x00000028u), s.di);
  }
  L005f65ab: { // 0x5f65ab: 8b0d34dfa500 MOV ECX,dword ptr [0x00a5df34]
    s.cx = m.r32((0x00a5df34u));
  }
  L005f65b1: { // 0x5f65b1: 81e1ffff0000 AND ECX,0xffff
    s.cx = integer::logical((s.cx)&(0x0000ffffu),32,flags);
  }
  L005f65b7: { // 0x5f65b7: 25ff000000 AND EAX,0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  L005f65bc: { // 0x5f65bc: a3b40ab100 MOV [0x00b10ab4],EAX
    m.w32((0x00b10ab4u), s.ax);
  }
  L005f65c1: { // 0x5f65c1: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L005f65c3: { // 0x5f65c3: a130dfa500 MOV EAX,[0x00a5df30]
    s.ax = m.r32((0x00a5df30u));
  }
  L005f65c8: { // 0x5f65c8: 8915b80ab100 MOV dword ptr [0x00b10ab8],EDX
    m.w32((0x00b10ab8u), s.dx);
  }
  L005f65ce: { // 0x5f65ce: 25ffff0000 AND EAX,0xffff
    s.ax = integer::logical((s.ax)&(0x0000ffffu),32,flags);
  }
  L005f65d3: { // 0x5f65d3: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L005f65d5: { // 0x5f65d5: 23c6 AND EAX,ESI
    s.ax = integer::logical((s.ax)&(s.si),32,flags);
  }
  L005f65d7: { // 0x5f65d7: 23ef AND EBP,EDI
    s.bp = integer::logical((s.bp)&(s.di),32,flags);
  }
  L005f65d9: { // 0x5f65d9: 0fafc2 IMUL EAX,EDX
    s.ax = integer::imul(s.ax,s.dx,32,flags);
  }
  L005f65dc: { // 0x5f65dc: 0faf2db40ab100 IMUL EBP,dword ptr [0x00b10ab4]
    s.bp = integer::imul(s.bp,m.r32((0x00b10ab4u)),32,flags);
  }
  L005f65e3: { // 0x5f65e3: 03e8 ADD EBP,EAX
    s.bp = integer::add(s.bp,s.ax,32,flags);
  }
  L005f65e5: { // 0x5f65e5: a130dfa500 MOV EAX,[0x00a5df30]
    s.ax = m.r32((0x00a5df30u));
  }
  L005f65ea: { // 0x5f65ea: c1ed08 SHR EBP,0x8
    s.bp = integer::shift(s.bp,0x00000008u,32,flags,integer::Shift::right);
  }
  L005f65ed: { // 0x5f65ed: 23e8 AND EBP,EAX
    s.bp = integer::logical((s.bp)&(s.ax),32,flags);
  }
  L005f65ef: { // 0x5f65ef: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L005f65f1: { // 0x5f65f1: 23fb AND EDI,EBX
    s.di = integer::logical((s.di)&(s.bx),32,flags);
  }
  L005f65f3: { // 0x5f65f3: 23c3 AND EAX,EBX
    s.ax = integer::logical((s.ax)&(s.bx),32,flags);
  }
  L005f65f5: { // 0x5f65f5: 0faf3db40ab100 IMUL EDI,dword ptr [0x00b10ab4]
    s.di = integer::imul(s.di,m.r32((0x00b10ab4u)),32,flags);
  }
  L005f65fc: { // 0x5f65fc: 0fafc2 IMUL EAX,EDX
    s.ax = integer::imul(s.ax,s.dx,32,flags);
  }
  L005f65ff: { // 0x5f65ff: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L005f6601: { // 0x5f6601: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L005f6603: { // 0x5f6603: c1ef08 SHR EDI,0x8
    s.di = integer::shift(s.di,0x00000008u,32,flags,integer::Shift::right);
  }
  L005f6606: { // 0x5f6606: 6623fb AND DI,BX
    s.di = (s.di & 0xffff0000u) | ((integer::logical(((s.di & 0xffffu))&((s.bx & 0xffffu)),16,flags)) & 0xffffu);
  }
  L005f6609: { // 0x5f6609: 8b5c2428 MOV EBX,dword ptr [ESP + 0x28]
    s.bx = m.r32((f.sp+0x00000028u));
  }
  L005f660d: { // 0x5f660d: 23c3 AND EAX,EBX
    s.ax = integer::logical((s.ax)&(s.bx),32,flags);
  }
  L005f660f: { // 0x5f660f: 23ce AND ECX,ESI
    s.cx = integer::logical((s.cx)&(s.si),32,flags);
  }
  L005f6611: { // 0x5f6611: 0faf05b40ab100 IMUL EAX,dword ptr [0x00b10ab4]
    s.ax = integer::imul(s.ax,m.r32((0x00b10ab4u)),32,flags);
  }
  L005f6618: { // 0x5f6618: 0fafca IMUL ECX,EDX
    s.cx = integer::imul(s.cx,s.dx,32,flags);
  }
  L005f661b: { // 0x5f661b: 8b742430 MOV ESI,dword ptr [ESP + 0x30]
    s.si = m.r32((f.sp+0x00000030u));
  }
  L005f661f: { // 0x5f661f: 8b5c2414 MOV EBX,dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  L005f6623: { // 0x5f6623: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L005f6625: { // 0x5f6625: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L005f6629: { // 0x5f6629: 0bef OR EBP,EDI
    s.bp = integer::logical((s.bp)|(s.di),32,flags);
  }
  L005f662b: { // 0x5f662b: 8b7c2438 MOV EDI,dword ptr [ESP + 0x38]
    s.di = m.r32((f.sp+0x00000038u));
  }
  L005f662f: { // 0x5f662f: c1e808 SHR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::right);
  }
  L005f6632: { // 0x5f6632: 0be8 OR EBP,EAX
    s.bp = integer::logical((s.bp)|(s.ax),32,flags);
  }
  L005f6634: { // 0x5f6634: 668929 MOV word ptr [ECX],BP
    m.w16((s.cx), (s.bp & 0xffffu));
  }
  L005f6637: { // 0x5f6637: 8b6c242c MOV EBP,dword ptr [ESP + 0x2c]
    s.bp = m.r32((f.sp+0x0000002cu));
  }
  L005f663b: { // 0x5f663b: eb03 JMP 0x005f6640
    goto L005f6640;
  }
  L005f663d: { // 0x5f663d: 668939 MOV word ptr [ECX],DI
    m.w16((s.cx), (s.di & 0xffffu));
  }
  L005f6640: { // 0x5f6640: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L005f6644: { // 0x5f6644: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L005f6648: { // 0x5f6648: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L005f664b: { // 0x5f664b: 05ff000000 ADD EAX,0xff
    s.ax = integer::add(s.ax,0x000000ffu,32,flags);
  }
  L005f6650: { // 0x5f6650: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L005f6651: { // 0x5f6651: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L005f6655: { // 0x5f6655: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L005f6659: { // 0x5f6659: 89542420 MOV dword ptr [ESP + 0x20],EDX
    m.w32((f.sp+0x00000020u), s.dx);
  }
  L005f665d: { // 0x5f665d: 0f8515ffffff JNZ 0x005f6578
    if(integer::condition("JNZ",flags)) goto L005f6578;
  }
  L005f6663: { // 0x5f6663: 8b44243c MOV EAX,dword ptr [ESP + 0x3c]
    s.ax = m.r32((f.sp+0x0000003cu));
  }
  L005f6667: { // 0x5f6667: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  L005f666a: { // 0x5f666a: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L005f666b: { // 0x5f666b: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L005f666d: { // 0x5f666d: 8944243c MOV dword ptr [ESP + 0x3c],EAX
    m.w32((f.sp+0x0000003cu), s.ax);
  }
  L005f6671: { // 0x5f6671: 0f8c97feffff JL 0x005f650e
    if(integer::condition("JL",flags)) goto L005f650e;
  }
  L005f6677: { // 0x5f6677: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005f6678: { // 0x5f6678: 8b5500 MOV EDX,dword ptr [EBP]
    s.dx = m.r32((s.bp));
  }
  L005f667b: { // 0x5f667b: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L005f667d: { // 0x5f667d: ff5260 CALL dword ptr [EDX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),6252160u); flags=s.arithmetic_flags;
  }
  L005f6680: { // 0x5f6680: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005f6681: { // 0x5f6681: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005f6682: { // 0x5f6682: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005f6683: { // 0x5f6683: 83c424 ADD ESP,0x24
    f.sp = integer::add(f.sp,0x00000024u,32,flags);
  }
  L005f6686: { // 0x5f6686: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_005f6690(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005f6690: { // 0x5f6690: 83ec14 SUB ESP,0x14
    f.sp = integer::sub(f.sp,0x00000014u,32,flags);
  }
  L005f6693: { // 0x5f6693: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005f6694: { // 0x5f6694: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005f6695: { // 0x5f6695: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L005f6697: { // 0x5f6697: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L005f6699: { // 0x5f6699: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L005f669b: { // 0x5f669b: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005f669d: { // 0x5f669d: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L005f669f: { // 0x5f669f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005f66a0: { // 0x5f66a0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005f66a1: { // 0x5f66a1: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005f66a3: { // 0x5f66a3: 897c241c MOV dword ptr [ESP + 0x1c],EDI
    m.w32((f.sp+0x0000001cu), s.di);
  }
  L005f66a7: { // 0x5f66a7: ff525c CALL dword ptr [EDX + 0x5c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000005cu)),6252202u); flags=s.arithmetic_flags;
  }
  L005f66aa: { // 0x5f66aa: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005f66ac: { // 0x5f66ac: 8944240c MOV dword ptr [ESP + 0xc],EAX
    m.w32((f.sp+0x0000000cu), s.ax);
  }
  L005f66b0: { // 0x5f66b0: 0f8476010000 JZ 0x005f682c
    if(integer::condition("JZ",flags)) goto L005f682c;
  }
  L005f66b6: { // 0x5f66b6: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L005f66b8: { // 0x5f66b8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005f66b9: { // 0x5f66b9: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005f66ba: { // 0x5f66ba: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005f66bc: { // 0x5f66bc: ff5074 CALL dword ptr [EAX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000074u)),6252223u); flags=s.arithmetic_flags;
  }
  L005f66bf: { // 0x5f66bf: 8b5e0c MOV EBX,dword ptr [ESI + 0xc]
    s.bx = m.r32((s.si+0x0000000cu));
  }
  L005f66c2: { // 0x5f66c2: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L005f66c3: { // 0x5f66c3: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L005f66c5: { // 0x5f66c5: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  L005f66c8: { // 0x5f66c8: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L005f66ca: { // 0x5f66ca: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L005f66cc: { // 0x5f66cc: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L005f66d0: { // 0x5f66d0: 03cb ADD ECX,EBX
    s.cx = integer::add(s.cx,s.bx,32,flags);
  }
  L005f66d2: { // 0x5f66d2: d1fd SAR EBP,0x1
    s.bp = integer::shift(s.bp,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L005f66d4: { // 0x5f66d4: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L005f66d6: { // 0x5f66d6: 896c2418 MOV dword ptr [ESP + 0x18],EBP
    m.w32((f.sp+0x00000018u), s.bp);
  }
  L005f66da: { // 0x5f66da: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L005f66de: { // 0x5f66de: 0f8d95000000 JGE 0x005f6779
    if(integer::condition("JGE",flags)) goto L005f6779;
  }
  L005f66e4: { // 0x5f66e4: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L005f66e6: { // 0x5f66e6: 0fafcd IMUL ECX,EBP
    s.cx = integer::imul(s.cx,s.bp,32,flags);
  }
  L005f66e9: { // 0x5f66e9: 894c2428 MOV dword ptr [ESP + 0x28],ECX
    m.w32((f.sp+0x00000028u), s.cx);
  }
  L005f66ed: { // 0x5f66ed: 8b3e MOV EDI,dword ptr [ESI]
    s.di = m.r32((s.si));
  }
  L005f66ef: { // 0x5f66ef: 8d1c39 LEA EBX,[ECX + EDI*0x1]
    s.bx = (s.cx+(s.di * 0x00000001u));
  }
  L005f66f2: { // 0x5f66f2: 895c2420 MOV dword ptr [ESP + 0x20],EBX
    m.w32((f.sp+0x00000020u), s.bx);
  }
  L005f66f6: { // 0x5f66f6: 8d1c07 LEA EBX,[EDI + EAX*0x1]
    s.bx = (s.di+(s.ax * 0x00000001u));
  }
  L005f66f9: { // 0x5f66f9: 3bfb CMP EDI,EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  L005f66fb: { // 0x5f66fb: 7d5d JGE 0x005f675a
    if(integer::condition("JGE",flags)) goto L005f675a;
  }
  L005f66fd: { // 0x5f66fd: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L005f6701: { // 0x5f6701: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L005f6705: { // 0x5f6705: 8d0c4a LEA ECX,[EDX + ECX*0x2]
    s.cx = (s.dx+(s.cx * 0x00000002u));
  }
  L005f6708: { // 0x5f6708: 668b1d32dfa500 MOV BX,word ptr [0x00a5df32]
    s.bx = with_ax(s.bx, m.r16((0x00a5df32u)));
  }
  L005f670f: { // 0x5f670f: 668b11 MOV DX,word ptr [ECX]
    s.dx = with_ax(s.dx, m.r16((s.cx)));
  }
  L005f6712: { // 0x5f6712: 668beb MOV BP,BX
    s.bp = (s.bp & 0xffff0000u) | (((s.bx & 0xffffu)) & 0xffffu);
  }
  L005f6715: { // 0x5f6715: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L005f6718: { // 0x5f6718: 66d1ed SHR BP,0x1
    s.bp = (s.bp & 0xffff0000u) | ((integer::shift((s.bp & 0xffffu),0x00000001u,16,flags,integer::Shift::right)) & 0xffffu);
  }
  L005f671b: { // 0x5f671b: 6623eb AND BP,BX
    s.bp = (s.bp & 0xffff0000u) | ((integer::logical(((s.bp & 0xffffu))&((s.bx & 0xffffu)),16,flags)) & 0xffffu);
  }
  L005f671e: { // 0x5f671e: 668b1d30dfa500 MOV BX,word ptr [0x00a5df30]
    s.bx = with_ax(s.bx, m.r16((0x00a5df30u)));
  }
  L005f6725: { // 0x5f6725: 66d1eb SHR BX,0x1
    s.bx = with_ax(s.bx, integer::shift((s.bx & 0xffffu),0x00000001u,16,flags,integer::Shift::right));
  }
  L005f6728: { // 0x5f6728: 231d30dfa500 AND EBX,dword ptr [0x00a5df30]
    s.bx = integer::logical((s.bx)&(m.r32((0x00a5df30u))),32,flags);
  }
  L005f672e: { // 0x5f672e: 66d1ea SHR DX,0x1
    s.dx = with_ax(s.dx, integer::shift((s.dx & 0xffffu),0x00000001u,16,flags,integer::Shift::right));
  }
  L005f6731: { // 0x5f6731: 0beb OR EBP,EBX
    s.bp = integer::logical((s.bp)|(s.bx),32,flags);
  }
  L005f6733: { // 0x5f6733: 668b1d34dfa500 MOV BX,word ptr [0x00a5df34]
    s.bx = with_ax(s.bx, m.r16((0x00a5df34u)));
  }
  L005f673a: { // 0x5f673a: 66d1eb SHR BX,0x1
    s.bx = with_ax(s.bx, integer::shift((s.bx & 0xffffu),0x00000001u,16,flags,integer::Shift::right));
  }
  L005f673d: { // 0x5f673d: 0beb OR EBP,EBX
    s.bp = integer::logical((s.bp)|(s.bx),32,flags);
  }
  L005f673f: { // 0x5f673f: 23ea AND EBP,EDX
    s.bp = integer::logical((s.bp)&(s.dx),32,flags);
  }
  L005f6741: { // 0x5f6741: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L005f6742: { // 0x5f6742: 668969fe MOV word ptr [ECX + -0x2],BP
    m.w16((s.cx-0x00000002u), (s.bp & 0xffffu));
  }
  L005f6746: { // 0x5f6746: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005f6748: { // 0x5f6748: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L005f674a: { // 0x5f674a: 3bfa CMP EDI,EDX
    (void)integer::sub(s.di,s.dx,32,flags);
  }
  L005f674c: { // 0x5f674c: 7cba JL 0x005f6708
    if(integer::condition("JL",flags)) goto L005f6708;
  }
  L005f674e: { // 0x5f674e: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L005f6752: { // 0x5f6752: 8b6c2418 MOV EBP,dword ptr [ESP + 0x18]
    s.bp = m.r32((f.sp+0x00000018u));
  }
  L005f6756: { // 0x5f6756: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L005f675a: { // 0x5f675a: 8b7e04 MOV EDI,dword ptr [ESI + 0x4]
    s.di = m.r32((s.si+0x00000004u));
  }
  L005f675d: { // 0x5f675d: 8b5e0c MOV EBX,dword ptr [ESI + 0xc]
    s.bx = m.r32((s.si+0x0000000cu));
  }
  L005f6760: { // 0x5f6760: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L005f6761: { // 0x5f6761: 03fb ADD EDI,EBX
    s.di = integer::add(s.di,s.bx,32,flags);
  }
  L005f6763: { // 0x5f6763: 03cd ADD ECX,EBP
    s.cx = integer::add(s.cx,s.bp,32,flags);
  }
  L005f6765: { // 0x5f6765: 3bd7 CMP EDX,EDI
    (void)integer::sub(s.dx,s.di,32,flags);
  }
  L005f6767: { // 0x5f6767: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L005f676b: { // 0x5f676b: 894c2428 MOV dword ptr [ESP + 0x28],ECX
    m.w32((f.sp+0x00000028u), s.cx);
  }
  L005f676f: { // 0x5f676f: 0f8c78ffffff JL 0x005f66ed
    if(integer::condition("JL",flags)) goto L005f66ed;
  }
  L005f6775: { // 0x5f6775: 8b7c241c MOV EDI,dword ptr [ESP + 0x1c]
    s.di = m.r32((f.sp+0x0000001cu));
  }
  L005f6779: { // 0x5f6779: 8b5e04 MOV EBX,dword ptr [ESI + 0x4]
    s.bx = m.r32((s.si+0x00000004u));
  }
  L005f677c: { // 0x5f677c: 8b4c242c MOV ECX,dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L005f6780: { // 0x5f6780: 895c2410 MOV dword ptr [ESP + 0x10],EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
  L005f6784: { // 0x5f6784: 8d140b LEA EDX,[EBX + ECX*0x1]
    s.dx = (s.bx+(s.cx * 0x00000001u));
  }
  L005f6787: { // 0x5f6787: 3bda CMP EBX,EDX
    (void)integer::sub(s.bx,s.dx,32,flags);
  }
  L005f6789: { // 0x5f6789: 0f8d94000000 JGE 0x005f6823
    if(integer::condition("JGE",flags)) goto L005f6823;
  }
  L005f678f: { // 0x5f678f: 0fafdd IMUL EBX,EBP
    s.bx = integer::imul(s.bx,s.bp,32,flags);
  }
  L005f6792: { // 0x5f6792: 895c2428 MOV dword ptr [ESP + 0x28],EBX
    m.w32((f.sp+0x00000028u), s.bx);
  }
  L005f6796: { // 0x5f6796: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L005f6798: { // 0x5f6798: 8b6e08 MOV EBP,dword ptr [ESI + 0x8]
    s.bp = m.r32((s.si+0x00000008u));
  }
  L005f679b: { // 0x5f679b: 03e9 ADD EBP,ECX
    s.bp = integer::add(s.bp,s.cx,32,flags);
  }
  L005f679d: { // 0x5f679d: 8d140b LEA EDX,[EBX + ECX*0x1]
    s.dx = (s.bx+(s.cx * 0x00000001u));
  }
  L005f67a0: { // 0x5f67a0: 8d3c01 LEA EDI,[ECX + EAX*0x1]
    s.di = (s.cx+(s.ax * 0x00000001u));
  }
  L005f67a3: { // 0x5f67a3: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L005f67a5: { // 0x5f67a5: 3bfd CMP EDI,EBP
    (void)integer::sub(s.di,s.bp,32,flags);
  }
  L005f67a7: { // 0x5f67a7: 7d52 JGE 0x005f67fb
    if(integer::condition("JGE",flags)) goto L005f67fb;
  }
  L005f67a9: { // 0x5f67a9: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L005f67ad: { // 0x5f67ad: 8d0c51 LEA ECX,[ECX + EDX*0x2]
    s.cx = (s.cx+(s.dx * 0x00000002u));
  }
  L005f67b0: { // 0x5f67b0: 668b1d32dfa500 MOV BX,word ptr [0x00a5df32]
    s.bx = with_ax(s.bx, m.r16((0x00a5df32u)));
  }
  L005f67b7: { // 0x5f67b7: 668b11 MOV DX,word ptr [ECX]
    s.dx = with_ax(s.dx, m.r16((s.cx)));
  }
  L005f67ba: { // 0x5f67ba: 668beb MOV BP,BX
    s.bp = (s.bp & 0xffff0000u) | (((s.bx & 0xffffu)) & 0xffffu);
  }
  L005f67bd: { // 0x5f67bd: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L005f67c0: { // 0x5f67c0: 66d1ed SHR BP,0x1
    s.bp = (s.bp & 0xffff0000u) | ((integer::shift((s.bp & 0xffffu),0x00000001u,16,flags,integer::Shift::right)) & 0xffffu);
  }
  L005f67c3: { // 0x5f67c3: 6623eb AND BP,BX
    s.bp = (s.bp & 0xffff0000u) | ((integer::logical(((s.bp & 0xffffu))&((s.bx & 0xffffu)),16,flags)) & 0xffffu);
  }
  L005f67c6: { // 0x5f67c6: 668b1d30dfa500 MOV BX,word ptr [0x00a5df30]
    s.bx = with_ax(s.bx, m.r16((0x00a5df30u)));
  }
  L005f67cd: { // 0x5f67cd: 66d1eb SHR BX,0x1
    s.bx = with_ax(s.bx, integer::shift((s.bx & 0xffffu),0x00000001u,16,flags,integer::Shift::right));
  }
  L005f67d0: { // 0x5f67d0: 231d30dfa500 AND EBX,dword ptr [0x00a5df30]
    s.bx = integer::logical((s.bx)&(m.r32((0x00a5df30u))),32,flags);
  }
  L005f67d6: { // 0x5f67d6: 66d1ea SHR DX,0x1
    s.dx = with_ax(s.dx, integer::shift((s.dx & 0xffffu),0x00000001u,16,flags,integer::Shift::right));
  }
  L005f67d9: { // 0x5f67d9: 0beb OR EBP,EBX
    s.bp = integer::logical((s.bp)|(s.bx),32,flags);
  }
  L005f67db: { // 0x5f67db: 668b1d34dfa500 MOV BX,word ptr [0x00a5df34]
    s.bx = with_ax(s.bx, m.r16((0x00a5df34u)));
  }
  L005f67e2: { // 0x5f67e2: 66d1eb SHR BX,0x1
    s.bx = with_ax(s.bx, integer::shift((s.bx & 0xffffu),0x00000001u,16,flags,integer::Shift::right));
  }
  L005f67e5: { // 0x5f67e5: 0beb OR EBP,EBX
    s.bp = integer::logical((s.bp)|(s.bx),32,flags);
  }
  L005f67e7: { // 0x5f67e7: 23ea AND EBP,EDX
    s.bp = integer::logical((s.bp)&(s.dx),32,flags);
  }
  L005f67e9: { // 0x5f67e9: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L005f67ea: { // 0x5f67ea: 668969fe MOV word ptr [ECX + -0x2],BP
    m.w16((s.cx-0x00000002u), (s.bp & 0xffffu));
  }
  L005f67ee: { // 0x5f67ee: 8b5608 MOV EDX,dword ptr [ESI + 0x8]
    s.dx = m.r32((s.si+0x00000008u));
  }
  L005f67f1: { // 0x5f67f1: 0316 ADD EDX,dword ptr [ESI]
    s.dx = integer::add(s.dx,m.r32((s.si)),32,flags);
  }
  L005f67f3: { // 0x5f67f3: 3bfa CMP EDI,EDX
    (void)integer::sub(s.di,s.dx,32,flags);
  }
  L005f67f5: { // 0x5f67f5: 7cb9 JL 0x005f67b0
    if(integer::condition("JL",flags)) goto L005f67b0;
  }
  L005f67f7: { // 0x5f67f7: 8b5c2428 MOV EBX,dword ptr [ESP + 0x28]
    s.bx = m.r32((f.sp+0x00000028u));
  }
  L005f67fb: { // 0x5f67fb: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L005f67ff: { // 0x5f67ff: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L005f6803: { // 0x5f6803: 8b6c242c MOV EBP,dword ptr [ESP + 0x2c]
    s.bp = m.r32((f.sp+0x0000002cu));
  }
  L005f6807: { // 0x5f6807: 03da ADD EBX,EDX
    s.bx = integer::add(s.bx,s.dx,32,flags);
  }
  L005f6809: { // 0x5f6809: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  L005f680c: { // 0x5f680c: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L005f680d: { // 0x5f680d: 03d5 ADD EDX,EBP
    s.dx = integer::add(s.dx,s.bp,32,flags);
  }
  L005f680f: { // 0x5f680f: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L005f6813: { // 0x5f6813: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L005f6815: { // 0x5f6815: 895c2428 MOV dword ptr [ESP + 0x28],EBX
    m.w32((f.sp+0x00000028u), s.bx);
  }
  L005f6819: { // 0x5f6819: 0f8c77ffffff JL 0x005f6796
    if(integer::condition("JL",flags)) goto L005f6796;
  }
  L005f681f: { // 0x5f681f: 8b7c241c MOV EDI,dword ptr [ESP + 0x1c]
    s.di = m.r32((f.sp+0x0000001cu));
  }
  L005f6823: { // 0x5f6823: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L005f6825: { // 0x5f6825: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005f6827: { // 0x5f6827: ff5060 CALL dword ptr [EAX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000060u)),6252586u); flags=s.arithmetic_flags;
  }
  L005f682a: { // 0x5f682a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005f682b: { // 0x5f682b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005f682c: { // 0x5f682c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005f682d: { // 0x5f682d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005f682e: { // 0x5f682e: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L005f6831: { // 0x5f6831: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00682580(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00682580: { // 0x682580: 83ec14 SUB ESP,0x14
    f.sp = integer::sub(f.sp,0x00000014u,32,flags);
  }
  L00682583: { // 0x682583: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L00682587: { // 0x682587: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00682588: { // 0x682588: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00682589: { // 0x682589: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0068258a: { // 0x68258a: 8b32 MOV ESI,dword ptr [EDX]
    s.si = m.r32((s.dx));
  }
  L0068258c: { // 0x68258c: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0068258e: { // 0x68258e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0068258f: { // 0x68258f: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00682591: { // 0x682591: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00682592: { // 0x682592: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00682593: { // 0x682593: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L00682595: { // 0x682595: ff565c CALL dword ptr [ESI + 0x5c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x0000005cu)),6825368u); flags=s.arithmetic_flags;
  }
  L00682598: { // 0x682598: 8b7c2430 MOV EDI,dword ptr [ESP + 0x30]
    s.di = m.r32((f.sp+0x00000030u));
  }
  L0068259c: { // 0x68259c: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L0068259e: { // 0x68259e: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L006825a0: { // 0x6825a0: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006825a2: { // 0x6825a2: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L006825a4: { // 0x6825a4: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006825a5: { // 0x6825a5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006825a6: { // 0x6825a6: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006825a8: { // 0x6825a8: ff525c CALL dword ptr [EDX + 0x5c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000005cu)),6825387u); flags=s.arithmetic_flags;
  }
  L006825ab: { // 0x6825ab: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L006825af: { // 0x6825af: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L006825b3: { // 0x6825b3: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L006825b5: { // 0x6825b5: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L006825b9: { // 0x6825b9: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006825bb: { // 0x6825bb: 8b7004 MOV ESI,dword ptr [EAX + 0x4]
    s.si = m.r32((s.ax+0x00000004u));
  }
  L006825be: { // 0x6825be: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L006825c1: { // 0x6825c1: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L006825c5: { // 0x6825c5: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L006825c7: { // 0x6825c7: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L006825ca: { // 0x6825ca: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L006825ce: { // 0x6825ce: ff527c CALL dword ptr [EDX + 0x7c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000007cu)),6825425u); flags=s.arithmetic_flags;
  }
  L006825d1: { // 0x6825d1: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L006825d5: { // 0x6825d5: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L006825d7: { // 0x6825d7: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006825d9: { // 0x6825d9: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),6825439u); flags=s.arithmetic_flags;
  }
  L006825df: { // 0x6825df: 8b4c242c MOV ECX,dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L006825e3: { // 0x6825e3: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L006825e5: { // 0x6825e5: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L006825e7: { // 0x6825e7: ff5274 CALL dword ptr [EDX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000074u)),6825450u); flags=s.arithmetic_flags;
  }
  L006825ea: { // 0x6825ea: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006825eb: { // 0x6825eb: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006825ed: { // 0x6825ed: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L006825ef: { // 0x6825ef: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L006825f1: { // 0x6825f1: 7e5d JLE 0x00682650
    if(integer::condition("JLE",flags)) goto L00682650;
  }
  L006825f3: { // 0x6825f3: 0faff0 IMUL ESI,EAX
    s.si = integer::imul(s.si,s.ax,32,flags);
  }
  L006825f6: { // 0x6825f6: 8b542430 MOV EDX,dword ptr [ESP + 0x30]
    s.dx = m.r32((f.sp+0x00000030u));
  }
  L006825fa: { // 0x6825fa: 8d0c00 LEA ECX,[EAX + EAX*0x1]
    s.cx = (s.ax+(s.ax * 0x00000001u));
  }
  L006825fd: { // 0x6825fd: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00682601: { // 0x682601: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L00682605: { // 0x682605: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L00682607: { // 0x682607: 895c2430 MOV dword ptr [ESP + 0x30],EBX
    m.w32((f.sp+0x00000030u), s.bx);
  }
  L0068260b: { // 0x68260b: 8d6c7500 LEA EBP,[EBP + ESI*0x2]
    s.bp = (s.bp+(s.si * 0x00000002u));
  }
  L0068260f: { // 0x68260f: 8b74241c MOV ESI,dword ptr [ESP + 0x1c]
    s.si = m.r32((f.sp+0x0000001cu));
  }
  L00682613: { // 0x682613: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00682615: { // 0x682615: 7e28 JLE 0x0068263f
    if(integer::condition("JLE",flags)) goto L0068263f;
  }
  L00682617: { // 0x682617: 8bde MOV EBX,ESI
    s.bx = s.si;
  }
  L00682619: { // 0x682619: 03f6 ADD ESI,ESI
    s.si = integer::add(s.si,s.si,32,flags);
  }
  L0068261b: { // 0x68261b: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L0068261d: { // 0x68261d: 03d6 ADD EDX,ESI
    s.dx = integer::add(s.dx,s.si,32,flags);
  }
  L0068261f: { // 0x68261f: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00682621: { // 0x682621: 89542428 MOV dword ptr [ESP + 0x28],EDX
    m.w32((f.sp+0x00000028u), s.dx);
  }
  L00682625: { // 0x682625: 668b10 MOV DX,word ptr [EAX]
    s.dx = with_ax(s.dx, m.r16((s.ax)));
  }
  L00682628: { // 0x682628: 663b542434 CMP DX,word ptr [ESP + 0x34]
    (void)integer::sub((s.dx & 0xffffu),m.r16((f.sp+0x00000034u)),16,flags);
  }
  L0068262d: { // 0x68262d: 7403 JZ 0x00682632
    if(integer::condition("JZ",flags)) goto L00682632;
  }
  L0068262f: { // 0x68262f: 668911 MOV word ptr [ECX],DX
    m.w16((s.cx), (s.dx & 0xffffu));
  }
  L00682632: { // 0x682632: 83c002 ADD EAX,0x2
    s.ax = integer::add(s.ax,0x00000002u,32,flags);
  }
  L00682635: { // 0x682635: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L00682638: { // 0x682638: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L00682639: { // 0x682639: 75ea JNZ 0x00682625
    if(integer::condition("JNZ",flags)) goto L00682625;
  }
  L0068263b: { // 0x68263b: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L0068263f: { // 0x68263f: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00682643: { // 0x682643: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L00682647: { // 0x682647: 03e9 ADD EBP,ECX
    s.bp = integer::add(s.bp,s.cx,32,flags);
  }
  L00682649: { // 0x682649: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0068264a: { // 0x68264a: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L0068264e: { // 0x68264e: 75bf JNZ 0x0068260f
    if(integer::condition("JNZ",flags)) goto L0068260f;
  }
  L00682650: { // 0x682650: 8b4c242c MOV ECX,dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L00682654: { // 0x682654: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00682656: { // 0x682656: ff5260 CALL dword ptr [EDX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),6825561u); flags=s.arithmetic_flags;
  }
  L00682659: { // 0x682659: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L0068265b: { // 0x68265b: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0068265d: { // 0x68265d: ff5060 CALL dword ptr [EAX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000060u)),6825568u); flags=s.arithmetic_flags;
  }
  L00682660: { // 0x682660: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00682661: { // 0x682661: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00682662: { // 0x682662: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00682663: { // 0x682663: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00682665: { // 0x682665: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00682666: { // 0x682666: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L00682669: { // 0x682669: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
