#include "recovered/recovery_b767_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b767 {
namespace {
void f_0036e313(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_0036e313(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0076e313: { // 0x76e313: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0076e314: { // 0x76e314: 33db XOR EBX, EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0076e316: { // 0x76e316: 391d3005b100 CMP dword ptr [0xb10530], EBX
    (void)integer::sub(m.r32((0x00b10530u)),s.bx,32,flags);
  }
  L0076e31c: { // 0x76e31c: 7513 JNZ 0x76e331
    if(integer::condition("JNZ",flags)) goto L0076e331;
  }
  L0076e31e: { // 0x76e31e: 8b442408 MOV EAX, dword ptr [ESP + 8]
    s.ax = m.r32((f.sp+8u));
  }
  L0076e322: { // 0x76e322: 83f861 CMP EAX, 0x61
    (void)integer::sub(s.ax,0x00000061u,32,flags);
  }
  L0076e325: { // 0x76e325: 7c59 JL 0x76e380
    if(integer::condition("JL",flags)) goto L0076e380;
  }
  L0076e327: { // 0x76e327: 83f87a CMP EAX, 0x7a
    (void)integer::sub(s.ax,0x0000007au,32,flags);
  }
  L0076e32a: { // 0x76e32a: 7f54 JG 0x76e380
    if(integer::condition("JG",flags)) goto L0076e380;
  }
  L0076e32c: { // 0x76e32c: 83e820 SUB EAX, 0x20
    s.ax = integer::sub(s.ax,0x00000020u,32,flags);
  }
  L0076e32f: { // 0x76e32f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0076e330: { // 0x76e330: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076e331: { // 0x76e331: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0076e332: { // 0x76e332: be240eb100 MOV ESI, 0xb10e24
    s.si = 0x00b10e24u;
  }
  L0076e337: { // 0x76e337: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0076e338: { // 0x76e338: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0076e339: { // 0x76e339: ff15bc517800 CALL dword ptr [0x7851bc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((0x007851bcu)),7791423u); flags=s.arithmetic_flags;
  }
  L0076e33f: { // 0x76e33f: 391d200eb100 CMP dword ptr [0xb10e20], EBX
    (void)integer::sub(m.r32((0x00b10e20u)),s.bx,32,flags);
  }
  L0076e345: { // 0x76e345: 8b3dc0517800 MOV EDI, dword ptr [0x7851c0]
    s.di = m.r32((0x007851c0u));
  }
  L0076e34b: { // 0x76e34b: 740e JZ 0x76e35b
    if(integer::condition("JZ",flags)) goto L0076e35b;
  }
  L0076e34d: { // 0x76e34d: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0076e34e: { // 0x76e34e: ffd7 CALL EDI
    s.arithmetic_flags=flags; invoke(m,s,f,s.di,7791440u); flags=s.arithmetic_flags;
  }
  L0076e350: { // 0x76e350: 6a13 PUSH 0x13
    f.push(m,0x00000013u);
  }
  L0076e352: { // 0x76e352: e85f320000 CALL 0x7715b6
    s.arithmetic_flags=flags; invoke(m,s,f,0x007715b6u,7791447u); flags=s.arithmetic_flags;
  }
  L0076e357: { // 0x76e357: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0076e358: { // 0x76e358: 6a01 PUSH 1
    f.push(m,1u);
  }
  L0076e35a: { // 0x76e35a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0076e35b: { // 0x76e35b: ff742410 PUSH dword ptr [ESP + 0x10]
    f.push(m,m.r32((f.sp+0x00000010u)));
  }
  L0076e35f: { // 0x76e35f: e81e000000 CALL 0x76e382
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076e382u,7791460u); flags=s.arithmetic_flags;
  }
  L0076e364: { // 0x76e364: 85db TEST EBX, EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L0076e366: { // 0x76e366: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0076e367: { // 0x76e367: 89442410 MOV dword ptr [ESP + 0x10], EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0076e36b: { // 0x76e36b: 740a JZ 0x76e377
    if(integer::condition("JZ",flags)) goto L0076e377;
  }
  L0076e36d: { // 0x76e36d: 6a13 PUSH 0x13
    f.push(m,0x00000013u);
  }
  L0076e36f: { // 0x76e36f: e8a3320000 CALL 0x771617
    s.arithmetic_flags=flags; invoke(m,s,f,0x00771617u,7791476u); flags=s.arithmetic_flags;
  }
  L0076e374: { // 0x76e374: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0076e375: { // 0x76e375: eb03 JMP 0x76e37a
    goto L0076e37a;
  }
  L0076e377: { // 0x76e377: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0076e378: { // 0x76e378: ffd7 CALL EDI
    s.arithmetic_flags=flags; invoke(m,s,f,s.di,7791482u); flags=s.arithmetic_flags;
  }
  L0076e37a: { // 0x76e37a: 8b442410 MOV EAX, dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0076e37e: { // 0x76e37e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076e37f: { // 0x76e37f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076e380: { // 0x76e380: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0076e381: { // 0x76e381: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 7791379u:f_0036e313(m,s,child,{});break;
default:throw std::domain_error("recovery767 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0076e914(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0076e914: { // 0x76e914: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0076e915: { // 0x76e915: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L0076e917: { // 0x76e917: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L0076e91a: { // 0x76e91a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0076e91b: { // 0x76e91b: 8365f800 AND dword ptr [EBP + -0x8],0x0
    m.w32((s.bp-0x00000008u), integer::logical((m.r32((s.bp-0x00000008u)))&(0x00000000u),32,flags));
  }
  L0076e91f: { // 0x76e91f: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0076e920: { // 0x76e920: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0076e921: { // 0x76e921: 8b7d08 MOV EDI,dword ptr [EBP + 0x8]
    s.di = m.r32((s.bp+0x00000008u));
  }
  L0076e924: { // 0x76e924: 8a1f MOV BL,byte ptr [EDI]
    s.bx = with_al(s.bx, m.r8((s.di)));
  }
  L0076e926: { // 0x76e926: 8d7701 LEA ESI,[EDI + 0x1]
    s.si = (s.di+0x00000001u);
  }
  L0076e929: { // 0x76e929: 8975fc MOV dword ptr [EBP + -0x4],ESI
    m.w32((s.bp-0x00000004u), s.si);
  }
  L0076e92c: { // 0x76e92c: 833d6c77810001 CMP dword ptr [0x0081776c],0x1
    (void)integer::sub(m.r32((0x0081776cu)),0x00000001u,32,flags);
  }
  L0076e933: { // 0x76e933: 7e0f JLE 0x0076e944
    if(integer::condition("JLE",flags)) goto L0076e944;
  }
  L0076e935: { // 0x76e935: 0fb6c3 MOVZX EAX,BL
    s.ax = ((s.bx & 0xffu)&integer::mask(8));
  }
  L0076e938: { // 0x76e938: 6a08 PUSH 0x8
    f.push(m,0x00000008u);
  }
  L0076e93a: { // 0x76e93a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0076e93b: { // 0x76e93b: e891650000 CALL 0x00774ed1
    s.arithmetic_flags=flags; invoke(m,s,f,0x00774ed1u,7792960u); flags=s.arithmetic_flags;
  }
  L0076e940: { // 0x76e940: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0076e941: { // 0x76e941: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0076e942: { // 0x76e942: eb0f JMP 0x0076e953
    goto L0076e953;
  }
  L0076e944: { // 0x76e944: 8b0d60758100 MOV ECX,dword ptr [0x00817560]
    s.cx = m.r32((0x00817560u));
  }
  L0076e94a: { // 0x76e94a: 0fb6c3 MOVZX EAX,BL
    s.ax = ((s.bx & 0xffu)&integer::mask(8));
  }
  L0076e94d: { // 0x76e94d: 8a0441 MOV AL,byte ptr [ECX + EAX*0x2]
    s.ax = with_al(s.ax, m.r8((s.cx+(s.ax * 0x00000002u))));
  }
  L0076e950: { // 0x76e950: 83e008 AND EAX,0x8
    s.ax = integer::logical((s.ax)&(0x00000008u),32,flags);
  }
  L0076e953: { // 0x76e953: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0076e955: { // 0x76e955: 7405 JZ 0x0076e95c
    if(integer::condition("JZ",flags)) goto L0076e95c;
  }
  L0076e957: { // 0x76e957: 8a1e MOV BL,byte ptr [ESI]
    s.bx = with_al(s.bx, m.r8((s.si)));
  }
  L0076e959: { // 0x76e959: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0076e95a: { // 0x76e95a: ebd0 JMP 0x0076e92c
    goto L0076e92c;
  }
  L0076e95c: { // 0x76e95c: 80fb2d CMP BL,0x2d
    (void)integer::sub((s.bx & 0xffu),0x0000002du,8,flags);
  }
  L0076e95f: { // 0x76e95f: 8975fc MOV dword ptr [EBP + -0x4],ESI
    m.w32((s.bp-0x00000004u), s.si);
  }
  L0076e962: { // 0x76e962: 7506 JNZ 0x0076e96a
    if(integer::condition("JNZ",flags)) goto L0076e96a;
  }
  L0076e964: { // 0x76e964: 834d1402 OR dword ptr [EBP + 0x14],0x2
    m.w32((s.bp+0x00000014u), integer::logical((m.r32((s.bp+0x00000014u)))|(0x00000002u),32,flags));
  }
  L0076e968: { // 0x76e968: eb05 JMP 0x0076e96f
    goto L0076e96f;
  }
  L0076e96a: { // 0x76e96a: 80fb2b CMP BL,0x2b
    (void)integer::sub((s.bx & 0xffu),0x0000002bu,8,flags);
  }
  L0076e96d: { // 0x76e96d: 7506 JNZ 0x0076e975
    if(integer::condition("JNZ",flags)) goto L0076e975;
  }
  L0076e96f: { // 0x76e96f: 8a1e MOV BL,byte ptr [ESI]
    s.bx = with_al(s.bx, m.r8((s.si)));
  }
  L0076e971: { // 0x76e971: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0076e972: { // 0x76e972: 8975fc MOV dword ptr [EBP + -0x4],ESI
    m.w32((s.bp-0x00000004u), s.si);
  }
  L0076e975: { // 0x76e975: 8b4510 MOV EAX,dword ptr [EBP + 0x10]
    s.ax = m.r32((s.bp+0x00000010u));
  }
  L0076e978: { // 0x76e978: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0076e97a: { // 0x76e97a: 0f8c89010000 JL 0x0076eb09
    if(integer::condition("JL",flags)) goto L0076eb09;
  }
  L0076e980: { // 0x76e980: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0076e983: { // 0x76e983: 0f8480010000 JZ 0x0076eb09
    if(integer::condition("JZ",flags)) goto L0076eb09;
  }
  L0076e989: { // 0x76e989: 83f824 CMP EAX,0x24
    (void)integer::sub(s.ax,0x00000024u,32,flags);
  }
  L0076e98c: { // 0x76e98c: 0f8f77010000 JG 0x0076eb09
    if(integer::condition("JG",flags)) goto L0076eb09;
  }
  L0076e992: { // 0x76e992: 6a10 PUSH 0x10
    f.push(m,0x00000010u);
  }
  L0076e994: { // 0x76e994: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0076e996: { // 0x76e996: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0076e997: { // 0x76e997: 7524 JNZ 0x0076e9bd
    if(integer::condition("JNZ",flags)) goto L0076e9bd;
  }
  L0076e999: { // 0x76e999: 80fb30 CMP BL,0x30
    (void)integer::sub((s.bx & 0xffu),0x00000030u,8,flags);
  }
  L0076e99c: { // 0x76e99c: 7409 JZ 0x0076e9a7
    if(integer::condition("JZ",flags)) goto L0076e9a7;
  }
  L0076e99e: { // 0x76e99e: c745100a000000 MOV dword ptr [EBP + 0x10],0xa
    m.w32((s.bp+0x00000010u), 0x0000000au);
  }
  L0076e9a5: { // 0x76e9a5: eb32 JMP 0x0076e9d9
    goto L0076e9d9;
  }
  L0076e9a7: { // 0x76e9a7: 8a06 MOV AL,byte ptr [ESI]
    s.ax = with_al(s.ax, m.r8((s.si)));
  }
  L0076e9a9: { // 0x76e9a9: 3c78 CMP AL,0x78
    (void)integer::sub((s.ax & 0xffu),0x00000078u,8,flags);
  }
  L0076e9ab: { // 0x76e9ab: 740d JZ 0x0076e9ba
    if(integer::condition("JZ",flags)) goto L0076e9ba;
  }
  L0076e9ad: { // 0x76e9ad: 3c58 CMP AL,0x58
    (void)integer::sub((s.ax & 0xffu),0x00000058u,8,flags);
  }
  L0076e9af: { // 0x76e9af: 7409 JZ 0x0076e9ba
    if(integer::condition("JZ",flags)) goto L0076e9ba;
  }
  L0076e9b1: { // 0x76e9b1: c7451008000000 MOV dword ptr [EBP + 0x10],0x8
    m.w32((s.bp+0x00000010u), 0x00000008u);
  }
  L0076e9b8: { // 0x76e9b8: eb1f JMP 0x0076e9d9
    goto L0076e9d9;
  }
  L0076e9ba: { // 0x76e9ba: 894d10 MOV dword ptr [EBP + 0x10],ECX
    m.w32((s.bp+0x00000010u), s.cx);
  }
  L0076e9bd: { // 0x76e9bd: 394d10 CMP dword ptr [EBP + 0x10],ECX
    (void)integer::sub(m.r32((s.bp+0x00000010u)),s.cx,32,flags);
  }
  L0076e9c0: { // 0x76e9c0: 7517 JNZ 0x0076e9d9
    if(integer::condition("JNZ",flags)) goto L0076e9d9;
  }
  L0076e9c2: { // 0x76e9c2: 80fb30 CMP BL,0x30
    (void)integer::sub((s.bx & 0xffu),0x00000030u,8,flags);
  }
  L0076e9c5: { // 0x76e9c5: 7512 JNZ 0x0076e9d9
    if(integer::condition("JNZ",flags)) goto L0076e9d9;
  }
  L0076e9c7: { // 0x76e9c7: 8a06 MOV AL,byte ptr [ESI]
    s.ax = with_al(s.ax, m.r8((s.si)));
  }
  L0076e9c9: { // 0x76e9c9: 3c78 CMP AL,0x78
    (void)integer::sub((s.ax & 0xffu),0x00000078u,8,flags);
  }
  L0076e9cb: { // 0x76e9cb: 7404 JZ 0x0076e9d1
    if(integer::condition("JZ",flags)) goto L0076e9d1;
  }
  L0076e9cd: { // 0x76e9cd: 3c58 CMP AL,0x58
    (void)integer::sub((s.ax & 0xffu),0x00000058u,8,flags);
  }
  L0076e9cf: { // 0x76e9cf: 7508 JNZ 0x0076e9d9
    if(integer::condition("JNZ",flags)) goto L0076e9d9;
  }
  L0076e9d1: { // 0x76e9d1: 8a5e01 MOV BL,byte ptr [ESI + 0x1]
    s.bx = with_al(s.bx, m.r8((s.si+0x00000001u)));
  }
  L0076e9d4: { // 0x76e9d4: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0076e9d5: { // 0x76e9d5: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0076e9d6: { // 0x76e9d6: 8975fc MOV dword ptr [EBP + -0x4],ESI
    m.w32((s.bp-0x00000004u), s.si);
  }
  L0076e9d9: { // 0x76e9d9: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L0076e9dc: { // 0x76e9dc: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0076e9de: { // 0x76e9de: f77510 DIV dword ptr [EBP + 0x10]
    const auto divisor=m.r32((s.bp+0x00000010u));const std::uint64_t dividend=(std::uint64_t(s.dx)<<32)|s.ax;if(!divisor||dividend/divisor>0xffffffffull)throw std::domain_error("767 DIV overflow");s.ax=std::uint32_t(dividend/divisor);s.dx=std::uint32_t(dividend%divisor);
  }
  L0076e9e1: { // 0x76e9e1: bf03010000 MOV EDI,0x103
    s.di = 0x00000103u;
  }
  L0076e9e6: { // 0x76e9e6: 8945f4 MOV dword ptr [EBP + -0xc],EAX
    m.w32((s.bp-0x0000000cu), s.ax);
  }
  L0076e9e9: { // 0x76e9e9: 833d6c77810001 CMP dword ptr [0x0081776c],0x1
    (void)integer::sub(m.r32((0x0081776cu)),0x00000001u,32,flags);
  }
  L0076e9f0: { // 0x76e9f0: 0fb6f3 MOVZX ESI,BL
    s.si = ((s.bx & 0xffu)&integer::mask(8));
  }
  L0076e9f3: { // 0x76e9f3: 7e0c JLE 0x0076ea01
    if(integer::condition("JLE",flags)) goto L0076ea01;
  }
  L0076e9f5: { // 0x76e9f5: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  L0076e9f7: { // 0x76e9f7: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0076e9f8: { // 0x76e9f8: e8d4640000 CALL 0x00774ed1
    s.arithmetic_flags=flags; invoke(m,s,f,0x00774ed1u,7793149u); flags=s.arithmetic_flags;
  }
  L0076e9fd: { // 0x76e9fd: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0076e9fe: { // 0x76e9fe: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0076e9ff: { // 0x76e9ff: eb0b JMP 0x0076ea0c
    goto L0076ea0c;
  }
  L0076ea01: { // 0x76ea01: a160758100 MOV EAX,[0x00817560]
    s.ax = m.r32((0x00817560u));
  }
  L0076ea06: { // 0x76ea06: 8a0470 MOV AL,byte ptr [EAX + ESI*0x2]
    s.ax = with_al(s.ax, m.r8((s.ax+(s.si * 0x00000002u))));
  }
  L0076ea09: { // 0x76ea09: 83e004 AND EAX,0x4
    s.ax = integer::logical((s.ax)&(0x00000004u),32,flags);
  }
  L0076ea0c: { // 0x76ea0c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0076ea0e: { // 0x76ea0e: 7408 JZ 0x0076ea18
    if(integer::condition("JZ",flags)) goto L0076ea18;
  }
  L0076ea10: { // 0x76ea10: 0fbecb MOVSX ECX,BL
    s.cx = std::uint32_t(integer::sign_extend((s.bx & 0xffu),8));
  }
  L0076ea13: { // 0x76ea13: 83e930 SUB ECX,0x30
    s.cx = integer::sub(s.cx,0x00000030u,32,flags);
  }
  L0076ea16: { // 0x76ea16: eb32 JMP 0x0076ea4a
    goto L0076ea4a;
  }
  L0076ea18: { // 0x76ea18: 833d6c77810001 CMP dword ptr [0x0081776c],0x1
    (void)integer::sub(m.r32((0x0081776cu)),0x00000001u,32,flags);
  }
  L0076ea1f: { // 0x76ea1f: 7e0b JLE 0x0076ea2c
    if(integer::condition("JLE",flags)) goto L0076ea2c;
  }
  L0076ea21: { // 0x76ea21: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0076ea22: { // 0x76ea22: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0076ea23: { // 0x76ea23: e8a9640000 CALL 0x00774ed1
    s.arithmetic_flags=flags; invoke(m,s,f,0x00774ed1u,7793192u); flags=s.arithmetic_flags;
  }
  L0076ea28: { // 0x76ea28: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0076ea29: { // 0x76ea29: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0076ea2a: { // 0x76ea2a: eb0b JMP 0x0076ea37
    goto L0076ea37;
  }
  L0076ea2c: { // 0x76ea2c: a160758100 MOV EAX,[0x00817560]
    s.ax = m.r32((0x00817560u));
  }
  L0076ea31: { // 0x76ea31: 668b0470 MOV AX,word ptr [EAX + ESI*0x2]
    s.ax = with_ax(s.ax, m.r16((s.ax+(s.si * 0x00000002u))));
  }
  L0076ea35: { // 0x76ea35: 23c7 AND EAX,EDI
    s.ax = integer::logical((s.ax)&(s.di),32,flags);
  }
  L0076ea37: { // 0x76ea37: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0076ea39: { // 0x76ea39: 744a JZ 0x0076ea85
    if(integer::condition("JZ",flags)) goto L0076ea85;
  }
  L0076ea3b: { // 0x76ea3b: 0fbec3 MOVSX EAX,BL
    s.ax = std::uint32_t(integer::sign_extend((s.bx & 0xffu),8));
  }
  L0076ea3e: { // 0x76ea3e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0076ea3f: { // 0x76ea3f: e8cff8ffff CALL 0x0076e313
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076e313u,7793220u); flags=s.arithmetic_flags;
  }
  L0076ea44: { // 0x76ea44: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0076ea45: { // 0x76ea45: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0076ea47: { // 0x76ea47: 83e937 SUB ECX,0x37
    s.cx = integer::sub(s.cx,0x00000037u,32,flags);
  }
  L0076ea4a: { // 0x76ea4a: 3b4d10 CMP ECX,dword ptr [EBP + 0x10]
    (void)integer::sub(s.cx,m.r32((s.bp+0x00000010u)),32,flags);
  }
  L0076ea4d: { // 0x76ea4d: 7336 JNC 0x0076ea85
    if(integer::condition("JNC",flags)) goto L0076ea85;
  }
  L0076ea4f: { // 0x76ea4f: 8b75f8 MOV ESI,dword ptr [EBP + -0x8]
    s.si = m.r32((s.bp-0x00000008u));
  }
  L0076ea52: { // 0x76ea52: 834d1408 OR dword ptr [EBP + 0x14],0x8
    m.w32((s.bp+0x00000014u), integer::logical((m.r32((s.bp+0x00000014u)))|(0x00000008u),32,flags));
  }
  L0076ea56: { // 0x76ea56: 3b75f4 CMP ESI,dword ptr [EBP + -0xc]
    (void)integer::sub(s.si,m.r32((s.bp-0x0000000cu)),32,flags);
  }
  L0076ea59: { // 0x76ea59: 7214 JC 0x0076ea6f
    if(integer::condition("JC",flags)) goto L0076ea6f;
  }
  L0076ea5b: { // 0x76ea5b: 750c JNZ 0x0076ea69
    if(integer::condition("JNZ",flags)) goto L0076ea69;
  }
  L0076ea5d: { // 0x76ea5d: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L0076ea60: { // 0x76ea60: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0076ea62: { // 0x76ea62: f77510 DIV dword ptr [EBP + 0x10]
    const auto divisor=m.r32((s.bp+0x00000010u));const std::uint64_t dividend=(std::uint64_t(s.dx)<<32)|s.ax;if(!divisor||dividend/divisor>0xffffffffull)throw std::domain_error("767 DIV overflow");s.ax=std::uint32_t(dividend/divisor);s.dx=std::uint32_t(dividend%divisor);
  }
  L0076ea65: { // 0x76ea65: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L0076ea67: { // 0x76ea67: 7606 JBE 0x0076ea6f
    if(integer::condition("JBE",flags)) goto L0076ea6f;
  }
  L0076ea69: { // 0x76ea69: 834d1404 OR dword ptr [EBP + 0x14],0x4
    m.w32((s.bp+0x00000014u), integer::logical((m.r32((s.bp+0x00000014u)))|(0x00000004u),32,flags));
  }
  L0076ea6d: { // 0x76ea6d: eb09 JMP 0x0076ea78
    goto L0076ea78;
  }
  L0076ea6f: { // 0x76ea6f: 0faf7510 IMUL ESI,dword ptr [EBP + 0x10]
    s.si = integer::imul(s.si,m.r32((s.bp+0x00000010u)),32,flags);
  }
  L0076ea73: { // 0x76ea73: 03f1 ADD ESI,ECX
    s.si = integer::add(s.si,s.cx,32,flags);
  }
  L0076ea75: { // 0x76ea75: 8975f8 MOV dword ptr [EBP + -0x8],ESI
    m.w32((s.bp-0x00000008u), s.si);
  }
  L0076ea78: { // 0x76ea78: 8b45fc MOV EAX,dword ptr [EBP + -0x4]
    s.ax = m.r32((s.bp-0x00000004u));
  }
  L0076ea7b: { // 0x76ea7b: ff45fc INC dword ptr [EBP + -0x4]
    m.w32((s.bp-0x00000004u), integer::increment(m.r32((s.bp-0x00000004u)),32,flags));
  }
  L0076ea7e: { // 0x76ea7e: 8a18 MOV BL,byte ptr [EAX]
    s.bx = with_al(s.bx, m.r8((s.ax)));
  }
  L0076ea80: { // 0x76ea80: e964ffffff JMP 0x0076e9e9
    goto L0076e9e9;
  }
  L0076ea85: { // 0x76ea85: 8b4514 MOV EAX,dword ptr [EBP + 0x14]
    s.ax = m.r32((s.bp+0x00000014u));
  }
  L0076ea88: { // 0x76ea88: ff4dfc DEC dword ptr [EBP + -0x4]
    m.w32((s.bp-0x00000004u), integer::decrement(m.r32((s.bp-0x00000004u)),32,flags));
  }
  L0076ea8b: { // 0x76ea8b: 8b5d0c MOV EBX,dword ptr [EBP + 0xc]
    s.bx = m.r32((s.bp+0x0000000cu));
  }
  L0076ea8e: { // 0x76ea8e: a808 TEST AL,0x8
    (void)integer::logical(((s.ax & 0xffu))&(0x00000008u),8,flags);
  }
  L0076ea90: { // 0x76ea90: 7510 JNZ 0x0076eaa2
    if(integer::condition("JNZ",flags)) goto L0076eaa2;
  }
  L0076ea92: { // 0x76ea92: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L0076ea94: { // 0x76ea94: 7406 JZ 0x0076ea9c
    if(integer::condition("JZ",flags)) goto L0076ea9c;
  }
  L0076ea96: { // 0x76ea96: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L0076ea99: { // 0x76ea99: 8945fc MOV dword ptr [EBP + -0x4],EAX
    m.w32((s.bp-0x00000004u), s.ax);
  }
  L0076ea9c: { // 0x76ea9c: 8365f800 AND dword ptr [EBP + -0x8],0x0
    m.w32((s.bp-0x00000008u), integer::logical((m.r32((s.bp-0x00000008u)))&(0x00000000u),32,flags));
  }
  L0076eaa0: { // 0x76eaa0: eb4b JMP 0x0076eaed
    goto L0076eaed;
  }
  L0076eaa2: { // 0x76eaa2: a804 TEST AL,0x4
    (void)integer::logical(((s.ax & 0xffu))&(0x00000004u),8,flags);
  }
  L0076eaa4: { // 0x76eaa4: beffffff7f MOV ESI,0x7fffffff
    s.si = 0x7fffffffu;
  }
  L0076eaa9: { // 0x76eaa9: 751b JNZ 0x0076eac6
    if(integer::condition("JNZ",flags)) goto L0076eac6;
  }
  L0076eaab: { // 0x76eaab: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L0076eaad: { // 0x76eaad: 753e JNZ 0x0076eaed
    if(integer::condition("JNZ",flags)) goto L0076eaed;
  }
  L0076eaaf: { // 0x76eaaf: 83e002 AND EAX,0x2
    s.ax = integer::logical((s.ax)&(0x00000002u),32,flags);
  }
  L0076eab2: { // 0x76eab2: 7409 JZ 0x0076eabd
    if(integer::condition("JZ",flags)) goto L0076eabd;
  }
  L0076eab4: { // 0x76eab4: 817df800000080 CMP dword ptr [EBP + -0x8],0x80000000
    (void)integer::sub(m.r32((s.bp-0x00000008u)),0x80000000u,32,flags);
  }
  L0076eabb: { // 0x76eabb: 7709 JA 0x0076eac6
    if(integer::condition("JA",flags)) goto L0076eac6;
  }
  L0076eabd: { // 0x76eabd: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0076eabf: { // 0x76eabf: 752c JNZ 0x0076eaed
    if(integer::condition("JNZ",flags)) goto L0076eaed;
  }
  L0076eac1: { // 0x76eac1: 3975f8 CMP dword ptr [EBP + -0x8],ESI
    (void)integer::sub(m.r32((s.bp-0x00000008u)),s.si,32,flags);
  }
  L0076eac4: { // 0x76eac4: 7627 JBE 0x0076eaed
    if(integer::condition("JBE",flags)) goto L0076eaed;
  }
  L0076eac6: { // 0x76eac6: e883670000 CALL 0x0077524e
    s.arithmetic_flags=flags; invoke(m,s,f,0x0077524eu,7793355u); flags=s.arithmetic_flags;
  }
  L0076eacb: { // 0x76eacb: f6451401 TEST byte ptr [EBP + 0x14],0x1
    (void)integer::logical((m.r8((s.bp+0x00000014u)))&(0x00000001u),8,flags);
  }
  L0076eacf: { // 0x76eacf: c70022000000 MOV dword ptr [EAX],0x22
    m.w32((s.ax), 0x00000022u);
  }
  L0076ead5: { // 0x76ead5: 7406 JZ 0x0076eadd
    if(integer::condition("JZ",flags)) goto L0076eadd;
  }
  L0076ead7: { // 0x76ead7: 834df8ff OR dword ptr [EBP + -0x8],0xffffffff
    m.w32((s.bp-0x00000008u), integer::logical((m.r32((s.bp-0x00000008u)))|(0xffffffffu),32,flags));
  }
  L0076eadb: { // 0x76eadb: eb10 JMP 0x0076eaed
    goto L0076eaed;
  }
  L0076eadd: { // 0x76eadd: 8b4514 MOV EAX,dword ptr [EBP + 0x14]
    s.ax = m.r32((s.bp+0x00000014u));
  }
  L0076eae0: { // 0x76eae0: 2402 AND AL,0x2
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x00000002u),8,flags));
  }
  L0076eae2: { // 0x76eae2: f6d8 NEG AL
    s.ax = with_al(s.ax, integer::sub(0u,(s.ax & 0xffu),8,flags));
  }
  L0076eae4: { // 0x76eae4: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  L0076eae6: { // 0x76eae6: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L0076eae8: { // 0x76eae8: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L0076eaea: { // 0x76eaea: 8945f8 MOV dword ptr [EBP + -0x8],EAX
    m.w32((s.bp-0x00000008u), s.ax);
  }
  L0076eaed: { // 0x76eaed: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L0076eaef: { // 0x76eaef: 7405 JZ 0x0076eaf6
    if(integer::condition("JZ",flags)) goto L0076eaf6;
  }
  L0076eaf1: { // 0x76eaf1: 8b45fc MOV EAX,dword ptr [EBP + -0x4]
    s.ax = m.r32((s.bp-0x00000004u));
  }
  L0076eaf4: { // 0x76eaf4: 8903 MOV dword ptr [EBX],EAX
    m.w32((s.bx), s.ax);
  }
  L0076eaf6: { // 0x76eaf6: f6451402 TEST byte ptr [EBP + 0x14],0x2
    (void)integer::logical((m.r8((s.bp+0x00000014u)))&(0x00000002u),8,flags);
  }
  L0076eafa: { // 0x76eafa: 7408 JZ 0x0076eb04
    if(integer::condition("JZ",flags)) goto L0076eb04;
  }
  L0076eafc: { // 0x76eafc: 8b45f8 MOV EAX,dword ptr [EBP + -0x8]
    s.ax = m.r32((s.bp-0x00000008u));
  }
  L0076eaff: { // 0x76eaff: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L0076eb01: { // 0x76eb01: 8945f8 MOV dword ptr [EBP + -0x8],EAX
    m.w32((s.bp-0x00000008u), s.ax);
  }
  L0076eb04: { // 0x76eb04: 8b45f8 MOV EAX,dword ptr [EBP + -0x8]
    s.ax = m.r32((s.bp-0x00000008u));
  }
  L0076eb07: { // 0x76eb07: eb0b JMP 0x0076eb14
    goto L0076eb14;
  }
  L0076eb09: { // 0x76eb09: 8b450c MOV EAX,dword ptr [EBP + 0xc]
    s.ax = m.r32((s.bp+0x0000000cu));
  }
  L0076eb0c: { // 0x76eb0c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0076eb0e: { // 0x76eb0e: 7402 JZ 0x0076eb12
    if(integer::condition("JZ",flags)) goto L0076eb12;
  }
  L0076eb10: { // 0x76eb10: 8938 MOV dword ptr [EAX],EDI
    m.w32((s.ax), s.di);
  }
  L0076eb12: { // 0x76eb12: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0076eb14: { // 0x76eb14: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076eb15: { // 0x76eb15: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076eb16: { // 0x76eb16: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0076eb17: { // 0x76eb17: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L0076eb18: { // 0x76eb18: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
