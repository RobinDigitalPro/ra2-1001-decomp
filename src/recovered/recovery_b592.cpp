// Exact previously reviewed helper bodies; same guest stack and ABI state.
#include "recovery_b233.cpp"
#include "recovery_b592_machine.hpp"
namespace ra2::recovered::recovery_b233 {
static void call592(Memory&m,recovery_b592::State&s,recovery_b592::Frame&f,std::uint32_t target){
 State t{};t.ax=s.ax;t.cx=s.cx;t.dx=s.dx;t.bx=s.bx;t.bp=s.bp;t.si=s.si;t.di=s.di;t.fp=s.fp;t.arithmetic_flags=s.arithmetic_flags;
 Frame g{f.entry_sp,f.sp,f.outer_return};
 if(target==0x5a4890)f_001a4890(m,t,g,{});else if(target==0x76ebd0)f_0036ebd0(m,t,g,{});else f_001a6450(m,t,g,{});
 s.ax=t.ax;s.cx=t.cx;s.dx=t.dx;s.bx=t.bx;s.bp=t.bp;s.si=t.si;s.di=t.di;s.fp=t.fp;s.arithmetic_flags=t.arithmetic_flags;f.sp=g.sp;
}
}
#include "recovered/recovery_b592_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b592 {
namespace {
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 0x5a4890u:case 0x76ebd0u:case 0x5a6450u:ra2::recovered::recovery_b233::call592(m,s,child,target);break;
default:throw std::domain_error("recovery592 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00607230(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 std::array<std::uint8_t,16> readonly0{236,118,0,144,64,236,118,0,108,236,118,0,144,236,118,0};leaf::Memory table0(readonly0.data(),0x76ec30u,16);m.add(table0);
 std::array<std::uint8_t,32> readonly1{15,237,118,0,252,236,118,0,244,236,118,0,236,236,118,0,228,236,118,0,220,236,118,0,212,236,118,0,204,236,118,0};leaf::Memory table1(readonly1.data(),0x76ecacu,32);m.add(table1);
 std::array<std::uint8_t,16> readonly2{40,237,118,0,48,237,118,0,60,237,118,0,80,237,118,0};leaf::Memory table2(readonly2.data(),0x76ed18u,16);m.add(table2);
 std::array<std::uint8_t,16> readonly3{238,118,0,144,200,237,118,0,232,237,118,0,16,238,118,0};leaf::Memory table3(readonly3.data(),0x76edb8u,16);m.add(table3);
 std::array<std::uint8_t,32> readonly4{100,238,118,0,108,238,118,0,116,238,118,0,124,238,118,0,132,238,118,0,140,238,118,0,148,238,118,0,167,238,118,0};leaf::Memory table4(readonly4.data(),0x76ee44u,32);m.add(table4);
 std::array<std::uint8_t,16> readonly5{192,238,118,0,200,238,118,0,216,238,118,0,236,238,118,0};leaf::Memory table5(readonly5.data(),0x76eeb0u,16);m.add(table5);

 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00607230: { // 0x607230: 81ec04030000 SUB ESP,0x304
    f.sp = integer::sub(f.sp,0x00000304u,32,flags);
  }
  L00607236: { // 0x607236: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00607237: { // 0x607237: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00607238: { // 0x607238: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0060723a: { // 0x60723a: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0060723c: { // 0x60723c: 6a40 PUSH 0x40
    f.push(m,0x00000040u);
  }
  L0060723e: { // 0x60723e: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00607240: { // 0x607240: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L00607244: { // 0x607244: 8974240c MOV dword ptr [ESP + 0xc],ESI
    m.w32((f.sp+0x0000000cu), s.si);
  }
  L00607248: { // 0x607248: e843d6f9ff CALL 0x005a4890
    s.arithmetic_flags=flags; invoke(m,s,f,0x005a4890u,6320717u); flags=s.arithmetic_flags;
  }
  L0060724d: { // 0x60724d: 8b8300020000 MOV EAX,dword ptr [EBX + 0x200]
    s.ax = m.r32((s.bx+0x00000200u));
  }
  L00607253: { // 0x607253: 8b8c2414030000 MOV ECX,dword ptr [ESP + 0x314]
    s.cx = m.r32((f.sp+0x00000314u));
  }
  L0060725a: { // 0x60725a: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0060725b: { // 0x60725b: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0060725c: { // 0x60725c: 83e207 AND EDX,0x7
    s.dx = integer::logical((s.dx)&(0x00000007u),32,flags);
  }
  L0060725f: { // 0x60725f: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00607261: { // 0x607261: c1f803 SAR EAX,0x3
    s.ax = integer::shift(s.ax,0x00000003u,32,flags,integer::Shift::arithmetic_right);
  }
  L00607264: { // 0x607264: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00607265: { // 0x607265: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00607267: { // 0x607267: 0f8c06010000 JL 0x00607373
    if(integer::condition("JL",flags)) goto L00607373;
  }
  L0060726d: { // 0x60726d: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0060726e: { // 0x60726e: 8bac2414030000 MOV EBP,dword ptr [ESP + 0x314]
    s.bp = m.r32((f.sp+0x00000314u));
  }
  L00607275: { // 0x607275: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00607276: { // 0x607276: 6a40 PUSH 0x40
    f.push(m,0x00000040u);
  }
  L00607278: { // 0x607278: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0060727a: { // 0x60727a: 8d8c2418020000 LEA ECX,[ESP + 0x218]
    s.cx = (f.sp+0x00000218u);
  }
  L00607281: { // 0x607281: e80ad6f9ff CALL 0x005a4890
    s.arithmetic_flags=flags; invoke(m,s,f,0x005a4890u,6320774u); flags=s.arithmetic_flags;
  }
  L00607286: { // 0x607286: 8b8300020000 MOV EAX,dword ptr [EBX + 0x200]
    s.ax = m.r32((s.bx+0x00000200u));
  }
  L0060728c: { // 0x60728c: b940000000 MOV ECX,0x40
    s.cx = 0x00000040u;
  }
  L00607291: { // 0x607291: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00607292: { // 0x607292: 8db42414020000 LEA ESI,[ESP + 0x214]
    s.si = (f.sp+0x00000214u);
  }
  L00607299: { // 0x607299: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0060729a: { // 0x60729a: 83e207 AND EDX,0x7
    s.dx = integer::logical((s.dx)&(0x00000007u),32,flags);
  }
  L0060729d: { // 0x60729d: 8d7c2414 LEA EDI,[ESP + 0x14]
    s.di = (f.sp+0x00000014u);
  }
  L006072a1: { // 0x6072a1: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L006072a3: { // 0x6072a3: c1f803 SAR EAX,0x3
    s.ax = integer::shift(s.ax,0x00000003u,32,flags,integer::Shift::arithmetic_right);
  }
  L006072a6: { // 0x6072a6: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L006072a7: { // 0x6072a7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006072a8: { // 0x6072a8: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L006072ac: { // 0x6072ac: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006072ad: { // 0x6072ad: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006072ae: { // 0x6072ae: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L006072b0: { // 0x6072b0: e81b791600 CALL 0x0076ebd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076ebd0u,6320821u); flags=s.arithmetic_flags;
  }
  L006072b5: { // 0x6072b5: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L006072b8: { // 0x6072b8: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L006072ba: { // 0x6072ba: 8d8c2414010000 LEA ECX,[ESP + 0x114]
    s.cx = (f.sp+0x00000114u);
  }
  L006072c1: { // 0x6072c1: 6a40 PUSH 0x40
    f.push(m,0x00000040u);
  }
  L006072c3: { // 0x6072c3: e8c8d5f9ff CALL 0x005a4890
    s.arithmetic_flags=flags; invoke(m,s,f,0x005a4890u,6320840u); flags=s.arithmetic_flags;
  }
  L006072c8: { // 0x6072c8: 6a40 PUSH 0x40
    f.push(m,0x00000040u);
  }
  L006072ca: { // 0x6072ca: 8d8300010000 LEA EAX,[EBX + 0x100]
    s.ax = (s.bx+0x00000100u);
  }
  L006072d0: { // 0x6072d0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006072d1: { // 0x6072d1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006072d2: { // 0x6072d2: 8d542420 LEA EDX,[ESP + 0x20]
    s.dx = (f.sp+0x00000020u);
  }
  L006072d6: { // 0x6072d6: 8d8c2420010000 LEA ECX,[ESP + 0x120]
    s.cx = (f.sp+0x00000120u);
  }
  L006072dd: { // 0x6072dd: e86ef1f9ff CALL 0x005a6450
    s.arithmetic_flags=flags; invoke(m,s,f,0x005a6450u,6320866u); flags=s.arithmetic_flags;
  }
  L006072e2: { // 0x6072e2: a30094a200 MOV [0x00a29400],EAX
    m.w32((0x00a29400u), s.ax);
  }
  L006072e7: { // 0x6072e7: 8b8300020000 MOV EAX,dword ptr [EBX + 0x200]
    s.ax = m.r32((s.bx+0x00000200u));
  }
  L006072ed: { // 0x6072ed: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L006072ee: { // 0x6072ee: b940000000 MOV ECX,0x40
    s.cx = 0x00000040u;
  }
  L006072f3: { // 0x6072f3: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006072f4: { // 0x6072f4: 83e207 AND EDX,0x7
    s.dx = integer::logical((s.dx)&(0x00000007u),32,flags);
  }
  L006072f7: { // 0x6072f7: 8db42414010000 LEA ESI,[ESP + 0x114]
    s.si = (f.sp+0x00000114u);
  }
  L006072fe: { // 0x6072fe: 8d7c2414 LEA EDI,[ESP + 0x14]
    s.di = (f.sp+0x00000014u);
  }
  L00607302: { // 0x607302: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00607304: { // 0x607304: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L00607306: { // 0x607306: 8bb42420030000 MOV ESI,dword ptr [ESP + 0x320]
    s.si = m.r32((f.sp+0x00000320u));
  }
  L0060730d: { // 0x60730d: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L00607311: { // 0x607311: c1f803 SAR EAX,0x3
    s.ax = integer::shift(s.ax,0x00000003u,32,flags,integer::Shift::arithmetic_right);
  }
  L00607314: { // 0x607314: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00607315: { // 0x607315: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00607316: { // 0x607316: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00607317: { // 0x607317: e8b4781600 CALL 0x0076ebd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076ebd0u,6320924u); flags=s.arithmetic_flags;
  }
  L0060731c: { // 0x60731c: 8b8300020000 MOV EAX,dword ptr [EBX + 0x200]
    s.ax = m.r32((s.bx+0x00000200u));
  }
  L00607322: { // 0x607322: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00607325: { // 0x607325: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00607326: { // 0x607326: 8b8c241c030000 MOV ECX,dword ptr [ESP + 0x31c]
    s.cx = m.r32((f.sp+0x0000031cu));
  }
  L0060732d: { // 0x60732d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0060732e: { // 0x60732e: 83e207 AND EDX,0x7
    s.dx = integer::logical((s.dx)&(0x00000007u),32,flags);
  }
  L00607331: { // 0x607331: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00607333: { // 0x607333: 83caff OR EDX,0xffffffff
    s.dx = integer::logical((s.dx)|(0xffffffffu),32,flags);
  }
  L00607336: { // 0x607336: c1f803 SAR EAX,0x3
    s.ax = integer::shift(s.ax,0x00000003u,32,flags,integer::Shift::arithmetic_right);
  }
  L00607339: { // 0x607339: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L0060733b: { // 0x60733b: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L0060733d: { // 0x60733d: 89b42420030000 MOV dword ptr [ESP + 0x320],ESI
    m.w32((f.sp+0x00000320u), s.si);
  }
  L00607344: { // 0x607344: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L00607348: { // 0x607348: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L0060734a: { // 0x60734a: 8d6c2801 LEA EBP,[EAX + EBP*0x1 + 0x1]
    s.bp = (s.ax+(s.bp * 0x00000001u)+0x00000001u);
  }
  L0060734e: { // 0x60734e: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L00607350: { // 0x607350: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00607351: { // 0x607351: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00607353: { // 0x607353: 898c241c030000 MOV dword ptr [ESP + 0x31c],ECX
    m.w32((f.sp+0x0000031cu), s.cx);
  }
  L0060735a: { // 0x60735a: 89742410 MOV dword ptr [ESP + 0x10],ESI
    m.w32((f.sp+0x00000010u), s.si);
  }
  L0060735e: { // 0x60735e: 0f8d12ffffff JGE 0x00607276
    if(integer::condition("JGE",flags)) goto L00607276;
  }
  L00607364: { // 0x607364: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00607365: { // 0x607365: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00607367: { // 0x607367: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00607368: { // 0x607368: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00607369: { // 0x607369: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0060736a: { // 0x60736a: 81c404030000 ADD ESP,0x304
    f.sp = integer::add(f.sp,0x00000304u,32,flags);
  }
  L00607370: { // 0x607370: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00607373: { // 0x607373: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00607375: { // 0x607375: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00607376: { // 0x607376: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00607377: { // 0x607377: 81c404030000 ADD ESP,0x304
    f.sp = integer::add(f.sp,0x00000304u,32,flags);
  }
  L0060737d: { // 0x60737d: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
