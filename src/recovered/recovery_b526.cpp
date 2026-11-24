#include "recovered/recovery_b526_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b526 {
namespace {
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_0014d560(Memory&,State&,Frame&,const Operations&);
void f_0002add0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_00145500(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00545500: { // 0x545500: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L00545504: { // 0x545504: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00545505: { // 0x545505: 0fbf4202 MOVSX EAX,word ptr [EDX + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.dx+0x00000002u)),16));
  }
  L00545509: { // 0x545509: 0fbf32 MOVSX ESI,word ptr [EDX]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.dx)),16));
  }
  L0054550c: { // 0x54550c: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L0054550f: { // 0x54550f: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L00545511: { // 0x545511: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00545512: { // 0x545512: 7814 JS 0x00545528
    if(integer::condition("JS",flags)) goto L00545528;
  }
  L00545514: { // 0x545514: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00545519: { // 0x545519: 7d0d JGE 0x00545528
    if(integer::condition("JGE",flags)) goto L00545528;
  }
  L0054551b: { // 0x54551b: 8b8938010000 MOV ECX,dword ptr [ECX + 0x138]
    s.cx = m.r32((s.cx+0x00000138u));
  }
  L00545521: { // 0x545521: 8b0481 MOV EAX,dword ptr [ECX + EAX*0x4]
    s.ax = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L00545524: { // 0x545524: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00545526: { // 0x545526: 750d JNZ 0x00545535
    if(integer::condition("JNZ",flags)) goto L00545535;
  }
  L00545528: { // 0x545528: 8b12 MOV EDX,dword ptr [EDX]
    s.dx = m.r32((s.dx));
  }
  L0054552a: { // 0x54552a: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L0054552f: { // 0x54552f: 89153476a500 MOV dword ptr [0x00a57634],EDX
    m.w32((0x00a57634u), s.dx);
  }
  L00545535: { // 0x545535: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0014d560(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0054d560: { // 0x54d560: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0054d563: { // 0x54d563: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0054d567: { // 0x54d567: 8b515c MOV EDX,dword ptr [ECX + 0x5c]
    s.dx = m.r32((s.cx+0x0000005cu));
  }
  L0054d56a: { // 0x54d56a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0054d56b: { // 0x54d56b: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0054d56c: { // 0x54d56c: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0054d56d: { // 0x54d56d: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0054d56f: { // 0x54d56f: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0054d570: { // 0x54d570: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L0054d574: { // 0x54d574: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L0054d578: { // 0x54d578: 0f8d8b000000 JGE 0x0054d609
    if(integer::condition("JGE",flags)) goto L0054d609;
  }
  L0054d57e: { // 0x54d57e: 8b4950 MOV ECX,dword ptr [ECX + 0x50]
    s.cx = m.r32((s.cx+0x00000050u));
  }
  L0054d581: { // 0x54d581: 8b7c241c MOV EDI,dword ptr [ESP + 0x1c]
    s.di = m.r32((f.sp+0x0000001cu));
  }
  L0054d585: { // 0x54d585: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L0054d588: { // 0x54d588: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0054d58a: { // 0x54d58a: 8b410c MOV EAX,dword ptr [ECX + 0xc]
    s.ax = m.r32((s.cx+0x0000000cu));
  }
  L0054d58d: { // 0x54d58d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0054d58f: { // 0x54d58f: 7564 JNZ 0x0054d5f5
    if(integer::condition("JNZ",flags)) goto L0054d5f5;
  }
  L0054d591: { // 0x54d591: 8b31 MOV ESI,dword ptr [ECX]
    s.si = m.r32((s.cx));
  }
  L0054d593: { // 0x54d593: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L0054d596: { // 0x54d596: 0fbfd6 MOVSX EDX,SI
    s.dx = std::uint32_t(integer::sign_extend((s.si & 0xffffu),16));
  }
  L0054d599: { // 0x54d599: 0fbfd8 MOVSX EBX,AX
    s.bx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0054d59c: { // 0x54d59c: 8bea MOV EBP,EDX
    s.bp = s.dx;
  }
  L0054d59e: { // 0x54d59e: 8974241c MOV dword ptr [ESP + 0x1c],ESI
    m.w32((f.sp+0x0000001cu), s.si);
  }
  L0054d5a2: { // 0x54d5a2: 2beb SUB EBP,EBX
    s.bp = integer::sub(s.bp,s.bx,32,flags);
  }
  L0054d5a4: { // 0x54d5a4: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0054d5a8: { // 0x54d5a8: 7526 JNZ 0x0054d5d0
    if(integer::condition("JNZ",flags)) goto L0054d5d0;
  }
  L0054d5aa: { // 0x54d5aa: 668b4702 MOV AX,word ptr [EDI + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.di+0x00000002u)));
  }
  L0054d5ae: { // 0x54d5ae: 663b44241e CMP AX,word ptr [ESP + 0x1e]
    (void)integer::sub((s.ax & 0xffffu),m.r16((f.sp+0x0000001eu)),16,flags);
  }
  L0054d5b3: { // 0x54d5b3: 7c40 JL 0x0054d5f5
    if(integer::condition("JL",flags)) goto L0054d5f5;
  }
  L0054d5b5: { // 0x54d5b5: 663b442412 CMP AX,word ptr [ESP + 0x12]
    (void)integer::sub((s.ax & 0xffffu),m.r16((f.sp+0x00000012u)),16,flags);
  }
  L0054d5ba: { // 0x54d5ba: 7f39 JG 0x0054d5f5
    if(integer::condition("JG",flags)) goto L0054d5f5;
  }
  L0054d5bc: { // 0x54d5bc: 0fbf07 MOVSX EAX,word ptr [EDI]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di)),16));
  }
  L0054d5bf: { // 0x54d5bf: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0054d5c1: { // 0x54d5c1: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0054d5c2: { // 0x54d5c2: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L0054d5c4: { // 0x54d5c4: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0054d5c6: { // 0x54d5c6: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L0054d5ca: { // 0x54d5ca: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0054d5cc: { // 0x54d5cc: 7e48 JLE 0x0054d616
    if(integer::condition("JLE",flags)) goto L0054d616;
  }
  L0054d5ce: { // 0x54d5ce: eb25 JMP 0x0054d5f5
    goto L0054d5f5;
  }
  L0054d5d0: { // 0x54d5d0: 668b17 MOV DX,word ptr [EDI]
    s.dx = with_ax(s.dx, m.r16((s.di)));
  }
  L0054d5d3: { // 0x54d5d3: 663bd0 CMP DX,AX
    (void)integer::sub((s.dx & 0xffffu),(s.ax & 0xffffu),16,flags);
  }
  L0054d5d6: { // 0x54d5d6: 7f1d JG 0x0054d5f5
    if(integer::condition("JG",flags)) goto L0054d5f5;
  }
  L0054d5d8: { // 0x54d5d8: 663bd6 CMP DX,SI
    (void)integer::sub((s.dx & 0xffffu),(s.si & 0xffffu),16,flags);
  }
  L0054d5db: { // 0x54d5db: 7c18 JL 0x0054d5f5
    if(integer::condition("JL",flags)) goto L0054d5f5;
  }
  L0054d5dd: { // 0x54d5dd: 0fbf4702 MOVSX EAX,word ptr [EDI + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L0054d5e1: { // 0x54d5e1: 0fbf54241e MOVSX EDX,word ptr [ESP + 0x1e]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x0000001eu)),16));
  }
  L0054d5e6: { // 0x54d5e6: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0054d5e8: { // 0x54d5e8: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0054d5e9: { // 0x54d5e9: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L0054d5eb: { // 0x54d5eb: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0054d5ed: { // 0x54d5ed: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L0054d5f1: { // 0x54d5f1: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0054d5f3: { // 0x54d5f3: 7e21 JLE 0x0054d616
    if(integer::condition("JLE",flags)) goto L0054d616;
  }
  L0054d5f5: { // 0x54d5f5: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L0054d5f9: { // 0x54d5f9: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L0054d5fd: { // 0x54d5fd: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0054d5fe: { // 0x54d5fe: 83c110 ADD ECX,0x10
    s.cx = integer::add(s.cx,0x00000010u,32,flags);
  }
  L0054d601: { // 0x54d601: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0054d603: { // 0x54d603: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L0054d607: { // 0x54d607: 7c81 JL 0x0054d58a
    if(integer::condition("JL",flags)) goto L0054d58a;
  }
  L0054d609: { // 0x54d609: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0054d60a: { // 0x54d60a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0054d60b: { // 0x54d60b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0054d60c: { // 0x54d60c: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L0054d60f: { // 0x54d60f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0054d610: { // 0x54d610: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0054d613: { // 0x54d613: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L0054d616: { // 0x54d616: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L0054d61a: { // 0x54d61a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0054d61b: { // 0x54d61b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0054d61c: { // 0x54d61c: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0054d61d: { // 0x54d61d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0054d61e: { // 0x54d61e: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0054d621: { // 0x54d621: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
void f_0002add0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0042add0: { // 0x42add0: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L0042add4: { // 0x42add4: 668b10 MOV DX,word ptr [EAX]
    s.dx = with_ax(s.dx, m.r16((s.ax)));
  }
  L0042add7: { // 0x42add7: 668b4002 MOV AX,word ptr [EAX + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.ax+0x00000002u)));
  }
  L0042addb: { // 0x42addb: 66034102 ADD AX,word ptr [ECX + 0x2]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((s.cx+0x00000002u)),16,flags));
  }
  L0042addf: { // 0x42addf: 660311 ADD DX,word ptr [ECX]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((s.cx)),16,flags));
  }
  L0042ade2: { // 0x42ade2: 668944240a MOV word ptr [ESP + 0xa],AX
    m.w16((f.sp+0x0000000au), (s.ax & 0xffffu));
  }
  L0042ade7: { // 0x42ade7: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L0042adeb: { // 0x42adeb: 6689542408 MOV word ptr [ESP + 0x8],DX
    m.w16((f.sp+0x00000008u), (s.dx & 0xffffu));
  }
  L0042adf0: { // 0x42adf0: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  L0042adf4: { // 0x42adf4: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L0042adf6: { // 0x42adf6: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 5526784u:f_00145500(m,s,child,{});break;
case 5559648u:f_0014d560(m,s,child,{});break;
case 4369872u:f_0002add0(m,s,child,{});break;
default:throw std::domain_error("recovery526 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00566110(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00566110: { // 0x566110: 83ec30 SUB ESP,0x30
    f.sp = integer::sub(f.sp,0x00000030u,32,flags);
  }
  L00566113: { // 0x566113: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00566114: { // 0x566114: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00566115: { // 0x566115: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00566116: { // 0x566116: 8b742440 MOV ESI,dword ptr [ESP + 0x40]
    s.si = m.r32((f.sp+0x00000040u));
  }
  L0056611a: { // 0x56611a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0056611b: { // 0x56611b: 894c243c MOV dword ptr [ESP + 0x3c],ECX
    m.w32((f.sp+0x0000003cu), s.cx);
  }
  L0056611f: { // 0x56611f: c644241200 MOV byte ptr [ESP + 0x12],0x0
    m.w8((f.sp+0x00000012u), 0x00000000u);
  }
  L00566124: { // 0x566124: c644241300 MOV byte ptr [ESP + 0x13],0x0
    m.w8((f.sp+0x00000013u), 0x00000000u);
  }
  L00566129: { // 0x566129: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0056612b: { // 0x56612b: c7442414ffffffff MOV dword ptr [ESP + 0x14],0xffffffff
    m.w32((f.sp+0x00000014u), 0xffffffffu);
  }
  L00566133: { // 0x566133: bdfeffffff MOV EBP,0xfffffffe
    s.bp = 0xfffffffeu;
  }
  L00566138: { // 0x566138: bffeffffff MOV EDI,0xfffffffe
    s.di = 0xfffffffeu;
  }
  L0056613d: { // 0x56613d: 668bc5 MOV AX,BP
    s.ax = with_ax(s.ax, (s.bp & 0xffffu));
  }
  L00566140: { // 0x566140: 668bcf MOV CX,DI
    s.cx = with_ax(s.cx, (s.di & 0xffffu));
  }
  L00566143: { // 0x566143: 66034602 ADD AX,word ptr [ESI + 0x2]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((s.si+0x00000002u)),16,flags));
  }
  L00566147: { // 0x566147: 66030e ADD CX,word ptr [ESI]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((s.si)),16,flags));
  }
  L0056614a: { // 0x56614a: 6689442446 MOV word ptr [ESP + 0x46],AX
    m.w16((f.sp+0x00000046u), (s.ax & 0xffffu));
  }
  L0056614f: { // 0x56614f: 66894c2444 MOV word ptr [ESP + 0x44],CX
    m.w16((f.sp+0x00000044u), (s.cx & 0xffffu));
  }
  L00566154: { // 0x566154: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00566157: { // 0x566157: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L0056615a: { // 0x56615a: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L0056615d: { // 0x56615d: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0056615f: { // 0x56615f: 7814 JS 0x00566175
    if(integer::condition("JS",flags)) goto L00566175;
  }
  L00566161: { // 0x566161: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00566166: { // 0x566166: 7d0d JGE 0x00566175
    if(integer::condition("JGE",flags)) goto L00566175;
  }
  L00566168: { // 0x566168: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L0056616e: { // 0x56616e: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L00566171: { // 0x566171: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00566173: { // 0x566173: 750e JNZ 0x00566183
    if(integer::condition("JNZ",flags)) goto L00566183;
  }
  L00566175: { // 0x566175: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    s.ax = m.r32((f.sp+0x00000044u));
  }
  L00566179: { // 0x566179: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L0056617e: { // 0x56617e: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L00566183: { // 0x566183: 8b5038 MOV EDX,dword ptr [EAX + 0x38]
    s.dx = m.r32((s.ax+0x00000038u));
  }
  L00566186: { // 0x566186: a1a047a500 MOV EAX,[0x00a547a0]
    s.ax = m.r32((0x00a547a0u));
  }
  L0056618b: { // 0x56618b: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L0056618d: { // 0x56618d: 7c74 JL 0x00566203
    if(integer::condition("JL",flags)) goto L00566203;
  }
  L0056618f: { // 0x56618f: 83c010 ADD EAX,0x10
    s.ax = integer::add(s.ax,0x00000010u,32,flags);
  }
  L00566192: { // 0x566192: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L00566194: { // 0x566194: 7d6d JGE 0x00566203
    if(integer::condition("JGE",flags)) goto L00566203;
  }
  L00566196: { // 0x566196: 668bc5 MOV AX,BP
    s.ax = with_ax(s.ax, (s.bp & 0xffffu));
  }
  L00566199: { // 0x566199: 668bcf MOV CX,DI
    s.cx = with_ax(s.cx, (s.di & 0xffffu));
  }
  L0056619c: { // 0x56619c: 66034602 ADD AX,word ptr [ESI + 0x2]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((s.si+0x00000002u)),16,flags));
  }
  L005661a0: { // 0x5661a0: 66030e ADD CX,word ptr [ESI]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((s.si)),16,flags));
  }
  L005661a3: { // 0x5661a3: c644241201 MOV byte ptr [ESP + 0x12],0x1
    m.w8((f.sp+0x00000012u), 0x00000001u);
  }
  L005661a8: { // 0x5661a8: 668944241a MOV word ptr [ESP + 0x1a],AX
    m.w16((f.sp+0x0000001au), (s.ax & 0xffffu));
  }
  L005661ad: { // 0x5661ad: 66894c2418 MOV word ptr [ESP + 0x18],CX
    m.w16((f.sp+0x00000018u), (s.cx & 0xffffu));
  }
  L005661b2: { // 0x5661b2: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L005661b5: { // 0x5661b5: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L005661b8: { // 0x5661b8: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L005661bb: { // 0x5661bb: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L005661bd: { // 0x5661bd: 7826 JS 0x005661e5
    if(integer::condition("JS",flags)) goto L005661e5;
  }
  L005661bf: { // 0x5661bf: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L005661c4: { // 0x5661c4: 7d1f JGE 0x005661e5
    if(integer::condition("JGE",flags)) goto L005661e5;
  }
  L005661c6: { // 0x5661c6: 8b0d58a98100 MOV ECX,dword ptr [0x0081a958]
    s.cx = m.r32((0x0081a958u));
  }
  L005661cc: { // 0x5661cc: 8b0481 MOV EAX,dword ptr [ECX + EAX*0x4]
    s.ax = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L005661cf: { // 0x5661cf: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005661d1: { // 0x5661d1: 7412 JZ 0x005661e5
    if(integer::condition("JZ",flags)) goto L005661e5;
  }
  L005661d3: { // 0x5661d3: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L005661d5: { // 0x5661d5: a1a047a500 MOV EAX,[0x00a547a0]
    s.ax = m.r32((0x00a547a0u));
  }
  L005661da: { // 0x5661da: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L005661dc: { // 0x5661dc: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L005661e0: { // 0x5661e0: e9c1010000 JMP 0x005663a6
    goto L005663a6;
  }
  L005661e5: { // 0x5661e5: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L005661e9: { // 0x5661e9: bb1076a500 MOV EBX,0xa57610
    s.bx = 0x00a57610u;
  }
  L005661ee: { // 0x5661ee: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L005661f3: { // 0x5661f3: a1a047a500 MOV EAX,[0x00a547a0]
    s.ax = m.r32((0x00a547a0u));
  }
  L005661f8: { // 0x5661f8: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L005661fa: { // 0x5661fa: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L005661fe: { // 0x5661fe: e9a3010000 JMP 0x005663a6
    goto L005663a6;
  }
  L00566203: { // 0x566203: a1b0a8a300 MOV EAX,[0x00a3a8b0]
    s.ax = m.r32((0x00a3a8b0u));
  }
  L00566208: { // 0x566208: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L0056620a: { // 0x56620a: 7c74 JL 0x00566280
    if(integer::condition("JL",flags)) goto L00566280;
  }
  L0056620c: { // 0x56620c: 83c010 ADD EAX,0x10
    s.ax = integer::add(s.ax,0x00000010u,32,flags);
  }
  L0056620f: { // 0x56620f: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L00566211: { // 0x566211: 7d6d JGE 0x00566280
    if(integer::condition("JGE",flags)) goto L00566280;
  }
  L00566213: { // 0x566213: 668bc5 MOV AX,BP
    s.ax = with_ax(s.ax, (s.bp & 0xffffu));
  }
  L00566216: { // 0x566216: 668bcf MOV CX,DI
    s.cx = with_ax(s.cx, (s.di & 0xffffu));
  }
  L00566219: { // 0x566219: 66034602 ADD AX,word ptr [ESI + 0x2]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((s.si+0x00000002u)),16,flags));
  }
  L0056621d: { // 0x56621d: 66030e ADD CX,word ptr [ESI]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((s.si)),16,flags));
  }
  L00566220: { // 0x566220: c644241201 MOV byte ptr [ESP + 0x12],0x1
    m.w8((f.sp+0x00000012u), 0x00000001u);
  }
  L00566225: { // 0x566225: 668944241e MOV word ptr [ESP + 0x1e],AX
    m.w16((f.sp+0x0000001eu), (s.ax & 0xffffu));
  }
  L0056622a: { // 0x56622a: 66894c241c MOV word ptr [ESP + 0x1c],CX
    m.w16((f.sp+0x0000001cu), (s.cx & 0xffffu));
  }
  L0056622f: { // 0x56622f: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00566232: { // 0x566232: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L00566235: { // 0x566235: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L00566238: { // 0x566238: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0056623a: { // 0x56623a: 7826 JS 0x00566262
    if(integer::condition("JS",flags)) goto L00566262;
  }
  L0056623c: { // 0x56623c: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00566241: { // 0x566241: 7d1f JGE 0x00566262
    if(integer::condition("JGE",flags)) goto L00566262;
  }
  L00566243: { // 0x566243: 8b0d58a98100 MOV ECX,dword ptr [0x0081a958]
    s.cx = m.r32((0x0081a958u));
  }
  L00566249: { // 0x566249: 8b0481 MOV EAX,dword ptr [ECX + EAX*0x4]
    s.ax = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L0056624c: { // 0x56624c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0056624e: { // 0x56624e: 7412 JZ 0x00566262
    if(integer::condition("JZ",flags)) goto L00566262;
  }
  L00566250: { // 0x566250: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00566252: { // 0x566252: a1b0a8a300 MOV EAX,[0x00a3a8b0]
    s.ax = m.r32((0x00a3a8b0u));
  }
  L00566257: { // 0x566257: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L00566259: { // 0x566259: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L0056625d: { // 0x56625d: e944010000 JMP 0x005663a6
    goto L005663a6;
  }
  L00566262: { // 0x566262: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L00566266: { // 0x566266: bb1076a500 MOV EBX,0xa57610
    s.bx = 0x00a57610u;
  }
  L0056626b: { // 0x56626b: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L00566270: { // 0x566270: a1b0a8a300 MOV EAX,[0x00a3a8b0]
    s.ax = m.r32((0x00a3a8b0u));
  }
  L00566275: { // 0x566275: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L00566277: { // 0x566277: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L0056627b: { // 0x56627b: e926010000 JMP 0x005663a6
    goto L005663a6;
  }
  L00566280: { // 0x566280: 668bcf MOV CX,DI
    s.cx = with_ax(s.cx, (s.di & 0xffffu));
  }
  L00566283: { // 0x566283: 668bd5 MOV DX,BP
    s.dx = with_ax(s.dx, (s.bp & 0xffffu));
  }
  L00566286: { // 0x566286: 66030e ADD CX,word ptr [ESI]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((s.si)),16,flags));
  }
  L00566289: { // 0x566289: 66035602 ADD DX,word ptr [ESI + 0x2]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((s.si+0x00000002u)),16,flags));
  }
  L0056628d: { // 0x56628d: 66894c2420 MOV word ptr [ESP + 0x20],CX
    m.w16((f.sp+0x00000020u), (s.cx & 0xffffu));
  }
  L00566292: { // 0x566292: 8d4c2434 LEA ECX,[ESP + 0x34]
    s.cx = (f.sp+0x00000034u);
  }
  L00566296: { // 0x566296: 6689542422 MOV word ptr [ESP + 0x22],DX
    m.w16((f.sp+0x00000022u), (s.dx & 0xffffu));
  }
  L0056629b: { // 0x56629b: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L0056629f: { // 0x56629f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005662a0: { // 0x5662a0: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L005662a5: { // 0x5662a5: 89442438 MOV dword ptr [ESP + 0x38],EAX
    m.w32((f.sp+0x00000038u), s.ax);
  }
  L005662a9: { // 0x5662a9: e852f2fdff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5661358u); flags=s.arithmetic_flags;
  }
  L005662ae: { // 0x5662ae: 8b4044 MOV EAX,dword ptr [EAX + 0x44]
    s.ax = m.r32((s.ax+0x00000044u));
  }
  L005662b1: { // 0x5662b1: 83f84a CMP EAX,0x4a
    (void)integer::sub(s.ax,0x0000004au,32,flags);
  }
  L005662b4: { // 0x5662b4: 7c5d JL 0x00566313
    if(integer::condition("JL",flags)) goto L00566313;
  }
  L005662b6: { // 0x5662b6: 83f865 CMP EAX,0x65
    (void)integer::sub(s.ax,0x00000065u,32,flags);
  }
  L005662b9: { // 0x5662b9: 7f58 JG 0x00566313
    if(integer::condition("JG",flags)) goto L00566313;
  }
  L005662bb: { // 0x5662bb: 668bc5 MOV AX,BP
    s.ax = with_ax(s.ax, (s.bp & 0xffffu));
  }
  L005662be: { // 0x5662be: 668bcf MOV CX,DI
    s.cx = with_ax(s.cx, (s.di & 0xffffu));
  }
  L005662c1: { // 0x5662c1: 66034602 ADD AX,word ptr [ESI + 0x2]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((s.si+0x00000002u)),16,flags));
  }
  L005662c5: { // 0x5662c5: 66030e ADD CX,word ptr [ESI]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((s.si)),16,flags));
  }
  L005662c8: { // 0x5662c8: c644241200 MOV byte ptr [ESP + 0x12],0x0
    m.w8((f.sp+0x00000012u), 0x00000000u);
  }
  L005662cd: { // 0x5662cd: c644241300 MOV byte ptr [ESP + 0x13],0x0
    m.w8((f.sp+0x00000013u), 0x00000000u);
  }
  L005662d2: { // 0x5662d2: 6689442426 MOV word ptr [ESP + 0x26],AX
    m.w16((f.sp+0x00000026u), (s.ax & 0xffffu));
  }
  L005662d7: { // 0x5662d7: 66894c2424 MOV word ptr [ESP + 0x24],CX
    m.w16((f.sp+0x00000024u), (s.cx & 0xffffu));
  }
  L005662dc: { // 0x5662dc: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L005662df: { // 0x5662df: 0fbfd1 MOVSX EDX,CX
    s.dx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L005662e2: { // 0x5662e2: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L005662e5: { // 0x5662e5: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L005662e7: { // 0x5662e7: 781b JS 0x00566304
    if(integer::condition("JS",flags)) goto L00566304;
  }
  L005662e9: { // 0x5662e9: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L005662ee: { // 0x5662ee: 7d14 JGE 0x00566304
    if(integer::condition("JGE",flags)) goto L00566304;
  }
  L005662f0: { // 0x5662f0: 8b0d58a98100 MOV ECX,dword ptr [0x0081a958]
    s.cx = m.r32((0x0081a958u));
  }
  L005662f6: { // 0x5662f6: 8b0481 MOV EAX,dword ptr [ECX + EAX*0x4]
    s.ax = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L005662f9: { // 0x5662f9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005662fb: { // 0x5662fb: 7407 JZ 0x00566304
    if(integer::condition("JZ",flags)) goto L00566304;
  }
  L005662fd: { // 0x5662fd: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L005662ff: { // 0x5662ff: e9a2000000 JMP 0x005663a6
    goto L005663a6;
  }
  L00566304: { // 0x566304: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L00566308: { // 0x566308: 89153476a500 MOV dword ptr [0x00a57634],EDX
    m.w32((0x00a57634u), s.dx);
  }
  L0056630e: { // 0x56630e: e98e000000 JMP 0x005663a1
    goto L005663a1;
  }
  L00566313: { // 0x566313: 668bc7 MOV AX,DI
    s.ax = with_ax(s.ax, (s.di & 0xffffu));
  }
  L00566316: { // 0x566316: 668bcd MOV CX,BP
    s.cx = with_ax(s.cx, (s.bp & 0xffffu));
  }
  L00566319: { // 0x566319: 660306 ADD AX,word ptr [ESI]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((s.si)),16,flags));
  }
  L0056631c: { // 0x56631c: 66034e02 ADD CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((s.si+0x00000002u)),16,flags));
  }
  L00566320: { // 0x566320: 6689442428 MOV word ptr [ESP + 0x28],AX
    m.w16((f.sp+0x00000028u), (s.ax & 0xffffu));
  }
  L00566325: { // 0x566325: 66894c242a MOV word ptr [ESP + 0x2a],CX
    m.w16((f.sp+0x0000002au), (s.cx & 0xffffu));
  }
  L0056632a: { // 0x56632a: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L0056632e: { // 0x56632e: 8d442434 LEA EAX,[ESP + 0x34]
    s.ax = (f.sp+0x00000034u);
  }
  L00566332: { // 0x566332: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00566333: { // 0x566333: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00566338: { // 0x566338: 89542438 MOV dword ptr [ESP + 0x38],EDX
    m.w32((f.sp+0x00000038u), s.dx);
  }
  L0056633c: { // 0x56633c: e8bff1fdff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5661505u); flags=s.arithmetic_flags;
  }
  L00566341: { // 0x566341: 8b4044 MOV EAX,dword ptr [EAX + 0x44]
    s.ax = m.r32((s.ax+0x00000044u));
  }
  L00566344: { // 0x566344: 3dcd000000 CMP EAX,0xcd
    (void)integer::sub(s.ax,0x000000cdu,32,flags);
  }
  L00566349: { // 0x566349: 7c5b JL 0x005663a6
    if(integer::condition("JL",flags)) goto L005663a6;
  }
  L0056634b: { // 0x56634b: 3de8000000 CMP EAX,0xe8
    (void)integer::sub(s.ax,0x000000e8u,32,flags);
  }
  L00566350: { // 0x566350: 7f54 JG 0x005663a6
    if(integer::condition("JG",flags)) goto L005663a6;
  }
  L00566352: { // 0x566352: 668bc5 MOV AX,BP
    s.ax = with_ax(s.ax, (s.bp & 0xffffu));
  }
  L00566355: { // 0x566355: 668bcf MOV CX,DI
    s.cx = with_ax(s.cx, (s.di & 0xffffu));
  }
  L00566358: { // 0x566358: 66034602 ADD AX,word ptr [ESI + 0x2]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((s.si+0x00000002u)),16,flags));
  }
  L0056635c: { // 0x56635c: 66030e ADD CX,word ptr [ESI]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((s.si)),16,flags));
  }
  L0056635f: { // 0x56635f: c644241200 MOV byte ptr [ESP + 0x12],0x0
    m.w8((f.sp+0x00000012u), 0x00000000u);
  }
  L00566364: { // 0x566364: c644241301 MOV byte ptr [ESP + 0x13],0x1
    m.w8((f.sp+0x00000013u), 0x00000001u);
  }
  L00566369: { // 0x566369: 668944242e MOV word ptr [ESP + 0x2e],AX
    m.w16((f.sp+0x0000002eu), (s.ax & 0xffffu));
  }
  L0056636e: { // 0x56636e: 66894c242c MOV word ptr [ESP + 0x2c],CX
    m.w16((f.sp+0x0000002cu), (s.cx & 0xffffu));
  }
  L00566373: { // 0x566373: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00566376: { // 0x566376: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L00566379: { // 0x566379: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L0056637c: { // 0x56637c: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0056637e: { // 0x56637e: 7818 JS 0x00566398
    if(integer::condition("JS",flags)) goto L00566398;
  }
  L00566380: { // 0x566380: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00566385: { // 0x566385: 7d11 JGE 0x00566398
    if(integer::condition("JGE",flags)) goto L00566398;
  }
  L00566387: { // 0x566387: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L0056638d: { // 0x56638d: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L00566390: { // 0x566390: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00566392: { // 0x566392: 7404 JZ 0x00566398
    if(integer::condition("JZ",flags)) goto L00566398;
  }
  L00566394: { // 0x566394: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00566396: { // 0x566396: eb0e JMP 0x005663a6
    goto L005663a6;
  }
  L00566398: { // 0x566398: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L0056639c: { // 0x56639c: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L005663a1: { // 0x5663a1: bb1076a500 MOV EBX,0xa57610
    s.bx = 0x00a57610u;
  }
  L005663a6: { // 0x5663a6: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L005663a7: { // 0x5663a7: 83ff03 CMP EDI,0x3
    (void)integer::sub(s.di,0x00000003u,32,flags);
  }
  L005663aa: { // 0x5663aa: 0f8c8dfdffff JL 0x0056613d
    if(integer::condition("JL",flags)) goto L0056613d;
  }
  L005663b0: { // 0x5663b0: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L005663b1: { // 0x5663b1: 83fd03 CMP EBP,0x3
    (void)integer::sub(s.bp,0x00000003u,32,flags);
  }
  L005663b4: { // 0x5663b4: 0f8c7efdffff JL 0x00566138
    if(integer::condition("JL",flags)) goto L00566138;
  }
  L005663ba: { // 0x5663ba: 8a442412 MOV AL,byte ptr [ESP + 0x12]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000012u)));
  }
  L005663be: { // 0x5663be: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005663c0: { // 0x5663c0: 0f8435010000 JZ 0x005664fb
    if(integer::condition("JZ",flags)) goto L005664fb;
  }
  L005663c6: { // 0x5663c6: 8b4b38 MOV ECX,dword ptr [EBX + 0x38]
    s.cx = m.r32((s.bx+0x00000038u));
  }
  L005663c9: { // 0x5663c9: 8b151489a200 MOV EDX,dword ptr [0x00a28914]
    s.dx = m.r32((0x00a28914u));
  }
  L005663cf: { // 0x5663cf: 8b048a MOV EAX,dword ptr [EDX + ECX*0x4]
    s.ax = m.r32((s.dx+(s.cx * 0x00000004u)));
  }
  L005663d2: { // 0x5663d2: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L005663d4: { // 0x5663d4: 8a8b1a010000 MOV CL,byte ptr [EBX + 0x11a]
    s.cx = with_al(s.cx, m.r8((s.bx+0x0000011au)));
  }
  L005663da: { // 0x5663da: 8bb0b4020000 MOV ESI,dword ptr [EAX + 0x2b4]
    s.si = m.r32((s.ax+0x000002b4u));
  }
  L005663e0: { // 0x5663e0: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L005663e2: { // 0x5663e2: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L005663e3: { // 0x5663e3: f7fe IDIV ESI
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.si,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L005663e5: { // 0x5663e5: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L005663e7: { // 0x5663e7: 668b4b24 MOV CX,word ptr [EBX + 0x24]
    s.cx = with_ax(s.cx, m.r16((s.bx+0x00000024u)));
  }
  L005663eb: { // 0x5663eb: 668bfa MOV DI,DX
    s.di = (s.di & 0xffff0000u) | (((s.dx & 0xffffu)) & 0xffffu);
  }
  L005663ee: { // 0x5663ee: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L005663ef: { // 0x5663ef: f7fe IDIV ESI
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.si,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L005663f1: { // 0x5663f1: 668b5326 MOV DX,word ptr [EBX + 0x26]
    s.dx = with_ax(s.dx, m.r16((s.bx+0x00000026u)));
  }
  L005663f5: { // 0x5663f5: 662bcf SUB CX,DI
    s.cx = with_ax(s.cx, integer::sub((s.cx & 0xffffu),(s.di & 0xffffu),16,flags));
  }
  L005663f8: { // 0x5663f8: 66894c242c MOV word ptr [ESP + 0x2c],CX
    m.w16((f.sp+0x0000002cu), (s.cx & 0xffffu));
  }
  L005663fd: { // 0x5663fd: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L00566401: { // 0x566401: 8b348d2cb07c00 MOV ESI,dword ptr [ECX*0x4 + 0x7cb02c]
    s.si = m.r32(((s.cx * 0x00000004u)+0x007cb02cu));
  }
  L00566408: { // 0x566408: 662bd0 SUB DX,AX
    s.dx = with_ax(s.dx, integer::sub((s.dx & 0xffffu),(s.ax & 0xffffu),16,flags));
  }
  L0056640b: { // 0x56640b: 668b044decaf7c00 MOV AX,word ptr [ECX*0x2 + 0x7cafec]
    s.ax = with_ax(s.ax, m.r16(((s.cx * 0x00000002u)+0x007cafecu)));
  }
  L00566413: { // 0x566413: 668954242e MOV word ptr [ESP + 0x2e],DX
    m.w16((f.sp+0x0000002eu), (s.dx & 0xffffu));
  }
  L00566418: { // 0x566418: 668b144d0cb07c00 MOV DX,word ptr [ECX*0x2 + 0x7cb00c]
    s.dx = with_ax(s.dx, m.r16(((s.cx * 0x00000002u)+0x007cb00cu)));
  }
  L00566420: { // 0x566420: 6689442434 MOV word ptr [ESP + 0x34],AX
    m.w16((f.sp+0x00000034u), (s.ax & 0xffffu));
  }
  L00566425: { // 0x566425: 6689542436 MOV word ptr [ESP + 0x36],DX
    m.w16((f.sp+0x00000036u), (s.dx & 0xffffu));
  }
  L0056642a: { // 0x56642a: 8b442434 MOV EAX,dword ptr [ESP + 0x34]
    s.ax = m.r32((f.sp+0x00000034u));
  }
  L0056642e: { // 0x56642e: 8b54242c MOV EDX,dword ptr [ESP + 0x2c]
    s.dx = m.r32((f.sp+0x0000002cu));
  }
  L00566432: { // 0x566432: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00566434: { // 0x566434: 8b54242e MOV EDX,dword ptr [ESP + 0x2e]
    s.dx = m.r32((f.sp+0x0000002eu));
  }
  L00566438: { // 0x566438: 6689442444 MOV word ptr [ESP + 0x44],AX
    m.w16((f.sp+0x00000044u), (s.ax & 0xffffu));
  }
  L0056643d: { // 0x56643d: 8b442436 MOV EAX,dword ptr [ESP + 0x36]
    s.ax = m.r32((f.sp+0x00000036u));
  }
  L00566441: { // 0x566441: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00566443: { // 0x566443: 83feff CMP ESI,-0x1
    (void)integer::sub(s.si,0xffffffffu,32,flags);
  }
  L00566446: { // 0x566446: 6689442446 MOV word ptr [ESP + 0x46],AX
    m.w16((f.sp+0x00000046u), (s.ax & 0xffffu));
  }
  L0056644b: { // 0x56644b: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    s.ax = m.r32((f.sp+0x00000044u));
  }
  L0056644f: { // 0x56644f: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00566453: { // 0x566453: 0f84e8040000 JZ 0x00566941
    if(integer::condition("JZ",flags)) goto L00566941;
  }
  L00566459: { // 0x566459: 8b7c243c MOV EDI,dword ptr [ESP + 0x3c]
    s.di = m.r32((f.sp+0x0000003cu));
  }
  L0056645d: { // 0x56645d: 89442444 MOV dword ptr [ESP + 0x44],EAX
    m.w32((f.sp+0x00000044u), s.ax);
  }
  L00566461: { // 0x566461: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00566463: { // 0x566463: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L00566467: { // 0x566467: 6a03 PUSH 0x3
    f.push(m,0x00000003u);
  }
  L00566469: { // 0x566469: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0056646a: { // 0x56646a: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0056646c: { // 0x56646c: e8ef70feff CALL 0x0054d560
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054d560u,5661809u); flags=s.arithmetic_flags;
  }
  L00566471: { // 0x566471: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00566473: { // 0x566473: 0f8cc8040000 JL 0x00566941
    if(integer::condition("JL",flags)) goto L00566941;
  }
  L00566479: { // 0x566479: 8b4f50 MOV ECX,dword ptr [EDI + 0x50]
    s.cx = m.r32((s.di+0x00000050u));
  }
  L0056647c: { // 0x56647c: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L0056647f: { // 0x56647f: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00566481: { // 0x566481: 8a4808 MOV CL,byte ptr [EAX + 0x8]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000008u)));
  }
  L00566484: { // 0x566484: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00566486: { // 0x566486: 7467 JZ 0x005664ef
    if(integer::condition("JZ",flags)) goto L005664ef;
  }
  L00566488: { // 0x566488: 8b4c2444 MOV ECX,dword ptr [ESP + 0x44]
    s.cx = m.r32((f.sp+0x00000044u));
  }
  L0056648c: { // 0x56648c: 668b542446 MOV DX,word ptr [ESP + 0x46]
    s.dx = with_ax(s.dx, m.r16((f.sp+0x00000046u)));
  }
  L00566491: { // 0x566491: 663908 CMP word ptr [EAX],CX
    (void)integer::sub(m.r16((s.ax)),(s.cx & 0xffffu),16,flags);
  }
  L00566494: { // 0x566494: 7521 JNZ 0x005664b7
    if(integer::condition("JNZ",flags)) goto L005664b7;
  }
  L00566496: { // 0x566496: 66395002 CMP word ptr [EAX + 0x2],DX
    (void)integer::sub(m.r16((s.ax+0x00000002u)),(s.dx & 0xffffu),16,flags);
  }
  L0056649a: { // 0x56649a: 751b JNZ 0x005664b7
    if(integer::condition("JNZ",flags)) goto L005664b7;
  }
  L0056649c: { // 0x56649c: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0056649f: { // 0x56649f: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L005664a1: { // 0x5664a1: 83e007 AND EAX,0x7
    s.ax = integer::logical((s.ax)&(0x00000007u),32,flags);
  }
  L005664a4: { // 0x5664a4: 89542444 MOV dword ptr [ESP + 0x44],EDX
    m.w32((f.sp+0x00000044u), s.dx);
  }
  L005664a8: { // 0x5664a8: 8d54243c LEA EDX,[ESP + 0x3c]
    s.dx = (f.sp+0x0000003cu);
  }
  L005664ac: { // 0x5664ac: 8d0c85a09d8300 LEA ECX,[EAX*0x4 + 0x839da0]
    s.cx = ((s.ax * 0x00000004u)+0x00839da0u);
  }
  L005664b3: { // 0x5664b3: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005664b4: { // 0x5664b4: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005664b5: { // 0x5664b5: eb24 JMP 0x005664db
    goto L005664db;
  }
  L005664b7: { // 0x5664b7: 66394804 CMP word ptr [EAX + 0x4],CX
    (void)integer::sub(m.r16((s.ax+0x00000004u)),(s.cx & 0xffffu),16,flags);
  }
  L005664bb: { // 0x5664bb: 7532 JNZ 0x005664ef
    if(integer::condition("JNZ",flags)) goto L005664ef;
  }
  L005664bd: { // 0x5664bd: 66395006 CMP word ptr [EAX + 0x6],DX
    (void)integer::sub(m.r16((s.ax+0x00000006u)),(s.dx & 0xffffu),16,flags);
  }
  L005664c1: { // 0x5664c1: 752c JNZ 0x005664ef
    if(integer::condition("JNZ",flags)) goto L005664ef;
  }
  L005664c3: { // 0x5664c3: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L005664c5: { // 0x5664c5: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005664c7: { // 0x5664c7: 83e107 AND ECX,0x7
    s.cx = integer::logical((s.cx)&(0x00000007u),32,flags);
  }
  L005664ca: { // 0x5664ca: 89442444 MOV dword ptr [ESP + 0x44],EAX
    m.w32((f.sp+0x00000044u), s.ax);
  }
  L005664ce: { // 0x5664ce: 8d442434 LEA EAX,[ESP + 0x34]
    s.ax = (f.sp+0x00000034u);
  }
  L005664d2: { // 0x5664d2: 8d148da09d8300 LEA EDX,[ECX*0x4 + 0x839da0]
    s.dx = ((s.cx * 0x00000004u)+0x00839da0u);
  }
  L005664d9: { // 0x5664d9: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005664da: { // 0x5664da: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005664db: { // 0x5664db: 8d4c244c LEA ECX,[ESP + 0x4c]
    s.cx = (f.sp+0x0000004cu);
  }
  L005664df: { // 0x5664df: e8ec48ecff CALL 0x0042add0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042add0u,5661924u); flags=s.arithmetic_flags;
  }
  L005664e4: { // 0x5664e4: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L005664e6: { // 0x5664e6: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L005664ea: { // 0x5664ea: e972ffffff JMP 0x00566461
    goto L00566461;
  }
  L005664ef: { // 0x5664ef: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005664f0: { // 0x5664f0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005664f1: { // 0x5664f1: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005664f2: { // 0x5664f2: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L005664f4: { // 0x5664f4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005664f5: { // 0x5664f5: 83c430 ADD ESP,0x30
    f.sp = integer::add(f.sp,0x00000030u,32,flags);
  }
  L005664f8: { // 0x5664f8: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005664fb: { // 0x5664fb: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L005664fd: { // 0x5664fd: 0f843e040000 JZ 0x00566941
    if(integer::condition("JZ",flags)) goto L00566941;
  }
  L00566503: { // 0x566503: 8a442413 MOV AL,byte ptr [ESP + 0x13]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000013u)));
  }
  L00566507: { // 0x566507: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00566509: { // 0x566509: 8b4344 MOV EAX,dword ptr [EBX + 0x44]
    s.ax = m.r32((s.bx+0x00000044u));
  }
  L0056650c: { // 0x56650c: 0f8432020000 JZ 0x00566744
    if(integer::condition("JZ",flags)) goto L00566744;
  }
  L00566512: { // 0x566512: 3dcd000000 CMP EAX,0xcd
    (void)integer::sub(s.ax,0x000000cdu,32,flags);
  }
  L00566517: { // 0x566517: 7c07 JL 0x00566520
    if(integer::condition("JL",flags)) goto L00566520;
  }
  L00566519: { // 0x566519: 3dd5000000 CMP EAX,0xd5
    (void)integer::sub(s.ax,0x000000d5u,32,flags);
  }
  L0056651e: { // 0x56651e: 7e19 JLE 0x00566539
    if(integer::condition("JLE",flags)) goto L00566539;
  }
  L00566520: { // 0x566520: 3ddf000000 CMP EAX,0xdf
    (void)integer::sub(s.ax,0x000000dfu,32,flags);
  }
  L00566525: { // 0x566525: 7c07 JL 0x0056652e
    if(integer::condition("JL",flags)) goto L0056652e;
  }
  L00566527: { // 0x566527: 3de2000000 CMP EAX,0xe2
    (void)integer::sub(s.ax,0x000000e2u,32,flags);
  }
  L0056652c: { // 0x56652c: 7e0b JLE 0x00566539
    if(integer::condition("JLE",flags)) goto L00566539;
  }
  L0056652e: { // 0x56652e: 3de7000000 CMP EAX,0xe7
    (void)integer::sub(s.ax,0x000000e7u,32,flags);
  }
  L00566533: { // 0x566533: 0f8504010000 JNZ 0x0056663d
    if(integer::condition("JNZ",flags)) goto L0056663d;
  }
  L00566539: { // 0x566539: 8b4b24 MOV ECX,dword ptr [EBX + 0x24]
    s.cx = m.r32((s.bx+0x00000024u));
  }
  L0056653c: { // 0x56653c: 894c2444 MOV dword ptr [ESP + 0x44],ECX
    m.w32((f.sp+0x00000044u), s.cx);
  }
  L00566540: { // 0x566540: 8d542444 LEA EDX,[ESP + 0x44]
    s.dx = (f.sp+0x00000044u);
  }
  L00566544: { // 0x566544: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00566549: { // 0x566549: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0056654a: { // 0x56654a: e8b1effdff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5662031u); flags=s.arithmetic_flags;
  }
  L0056654f: { // 0x56654f: 8b4044 MOV EAX,dword ptr [EAX + 0x44]
    s.ax = m.r32((s.ax+0x00000044u));
  }
  L00566552: { // 0x566552: 3dcd000000 CMP EAX,0xcd
    (void)integer::sub(s.ax,0x000000cdu,32,flags);
  }
  L00566557: { // 0x566557: 7c62 JL 0x005665bb
    if(integer::condition("JL",flags)) goto L005665bb;
  }
  L00566559: { // 0x566559: 3de8000000 CMP EAX,0xe8
    (void)integer::sub(s.ax,0x000000e8u,32,flags);
  }
  L0056655e: { // 0x56655e: 7f5b JG 0x005665bb
    if(integer::condition("JG",flags)) goto L005665bb;
  }
  L00566560: { // 0x566560: 668b4c2446 MOV CX,word ptr [ESP + 0x46]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000046u)));
  }
  L00566565: { // 0x566565: 0fbf542444 MOVSX EDX,word ptr [ESP + 0x44]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000044u)),16));
  }
  L0056656a: { // 0x56656a: 0fbfc1 MOVSX EAX,CX
    s.ax = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L0056656d: { // 0x56656d: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L00566570: { // 0x566570: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00566572: { // 0x566572: 7814 JS 0x00566588
    if(integer::condition("JS",flags)) goto L00566588;
  }
  L00566574: { // 0x566574: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00566579: { // 0x566579: 7d0d JGE 0x00566588
    if(integer::condition("JGE",flags)) goto L00566588;
  }
  L0056657b: { // 0x56657b: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L00566581: { // 0x566581: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L00566584: { // 0x566584: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00566586: { // 0x566586: 750e JNZ 0x00566596
    if(integer::condition("JNZ",flags)) goto L00566596;
  }
  L00566588: { // 0x566588: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    s.ax = m.r32((f.sp+0x00000044u));
  }
  L0056658c: { // 0x56658c: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L00566591: { // 0x566591: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L00566596: { // 0x566596: 8b4044 MOV EAX,dword ptr [EAX + 0x44]
    s.ax = m.r32((s.ax+0x00000044u));
  }
  L00566599: { // 0x566599: 3de7000000 CMP EAX,0xe7
    (void)integer::sub(s.ax,0x000000e7u,32,flags);
  }
  L0056659e: { // 0x56659e: 0f844bffffff JZ 0x005664ef
    if(integer::condition("JZ",flags)) goto L005664ef;
  }
  L005665a4: { // 0x5665a4: 3de8000000 CMP EAX,0xe8
    (void)integer::sub(s.ax,0x000000e8u,32,flags);
  }
  L005665a9: { // 0x5665a9: 0f8440ffffff JZ 0x005664ef
    if(integer::condition("JZ",flags)) goto L005664ef;
  }
  L005665af: { // 0x5665af: 66ff4c2444 DEC word ptr [ESP + 0x44]
    m.w16((f.sp+0x00000044u), integer::decrement(m.r16((f.sp+0x00000044u)),16,flags));
  }
  L005665b4: { // 0x5665b4: 66894c2446 MOV word ptr [ESP + 0x46],CX
    m.w16((f.sp+0x00000046u), (s.cx & 0xffffu));
  }
  L005665b9: { // 0x5665b9: eb85 JMP 0x00566540
    goto L00566540;
  }
  L005665bb: { // 0x5665bb: 8b4b24 MOV ECX,dword ptr [EBX + 0x24]
    s.cx = m.r32((s.bx+0x00000024u));
  }
  L005665be: { // 0x5665be: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L005665c2: { // 0x5665c2: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  L005665c6: { // 0x5665c6: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L005665cb: { // 0x5665cb: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005665cc: { // 0x5665cc: e82feffdff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5662161u); flags=s.arithmetic_flags;
  }
  L005665d1: { // 0x5665d1: 8b4044 MOV EAX,dword ptr [EAX + 0x44]
    s.ax = m.r32((s.ax+0x00000044u));
  }
  L005665d4: { // 0x5665d4: 3dcd000000 CMP EAX,0xcd
    (void)integer::sub(s.ax,0x000000cdu,32,flags);
  }
  L005665d9: { // 0x5665d9: 0f8c62030000 JL 0x00566941
    if(integer::condition("JL",flags)) goto L00566941;
  }
  L005665df: { // 0x5665df: 3de8000000 CMP EAX,0xe8
    (void)integer::sub(s.ax,0x000000e8u,32,flags);
  }
  L005665e4: { // 0x5665e4: 0f8f57030000 JG 0x00566941
    if(integer::condition("JG",flags)) goto L00566941;
  }
  L005665ea: { // 0x5665ea: 0fbf442416 MOVSX EAX,word ptr [ESP + 0x16]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000016u)),16));
  }
  L005665ef: { // 0x5665ef: 0fbf4c2414 MOVSX ECX,word ptr [ESP + 0x14]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000014u)),16));
  }
  L005665f4: { // 0x5665f4: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L005665f7: { // 0x5665f7: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L005665f9: { // 0x5665f9: 7814 JS 0x0056660f
    if(integer::condition("JS",flags)) goto L0056660f;
  }
  L005665fb: { // 0x5665fb: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00566600: { // 0x566600: 7d0d JGE 0x0056660f
    if(integer::condition("JGE",flags)) goto L0056660f;
  }
  L00566602: { // 0x566602: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L00566608: { // 0x566608: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L0056660b: { // 0x56660b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0056660d: { // 0x56660d: 750e JNZ 0x0056661d
    if(integer::condition("JNZ",flags)) goto L0056661d;
  }
  L0056660f: { // 0x56660f: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00566613: { // 0x566613: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L00566618: { // 0x566618: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L0056661d: { // 0x56661d: 8b4044 MOV EAX,dword ptr [EAX + 0x44]
    s.ax = m.r32((s.ax+0x00000044u));
  }
  L00566620: { // 0x566620: 3de7000000 CMP EAX,0xe7
    (void)integer::sub(s.ax,0x000000e7u,32,flags);
  }
  L00566625: { // 0x566625: 0f84c4feffff JZ 0x005664ef
    if(integer::condition("JZ",flags)) goto L005664ef;
  }
  L0056662b: { // 0x56662b: 3de8000000 CMP EAX,0xe8
    (void)integer::sub(s.ax,0x000000e8u,32,flags);
  }
  L00566630: { // 0x566630: 0f84b9feffff JZ 0x005664ef
    if(integer::condition("JZ",flags)) goto L005664ef;
  }
  L00566636: { // 0x566636: 66ff442414 INC word ptr [ESP + 0x14]
    m.w16((f.sp+0x00000014u), integer::increment(m.r16((f.sp+0x00000014u)),16,flags));
  }
  L0056663b: { // 0x56663b: eb85 JMP 0x005665c2
    goto L005665c2;
  }
  L0056663d: { // 0x56663d: 8b4b24 MOV ECX,dword ptr [EBX + 0x24]
    s.cx = m.r32((s.bx+0x00000024u));
  }
  L00566640: { // 0x566640: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L00566644: { // 0x566644: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  L00566648: { // 0x566648: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0056664d: { // 0x56664d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0056664e: { // 0x56664e: e8adeefdff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5662291u); flags=s.arithmetic_flags;
  }
  L00566653: { // 0x566653: 8b4044 MOV EAX,dword ptr [EAX + 0x44]
    s.ax = m.r32((s.ax+0x00000044u));
  }
  L00566656: { // 0x566656: 3dcd000000 CMP EAX,0xcd
    (void)integer::sub(s.ax,0x000000cdu,32,flags);
  }
  L0056665b: { // 0x56665b: 7c5a JL 0x005666b7
    if(integer::condition("JL",flags)) goto L005666b7;
  }
  L0056665d: { // 0x56665d: 3de8000000 CMP EAX,0xe8
    (void)integer::sub(s.ax,0x000000e8u,32,flags);
  }
  L00566662: { // 0x566662: 7f53 JG 0x005666b7
    if(integer::condition("JG",flags)) goto L005666b7;
  }
  L00566664: { // 0x566664: 0fbf442416 MOVSX EAX,word ptr [ESP + 0x16]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000016u)),16));
  }
  L00566669: { // 0x566669: 0fbf4c2414 MOVSX ECX,word ptr [ESP + 0x14]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000014u)),16));
  }
  L0056666e: { // 0x56666e: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L00566671: { // 0x566671: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00566673: { // 0x566673: 7814 JS 0x00566689
    if(integer::condition("JS",flags)) goto L00566689;
  }
  L00566675: { // 0x566675: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L0056667a: { // 0x56667a: 7d0d JGE 0x00566689
    if(integer::condition("JGE",flags)) goto L00566689;
  }
  L0056667c: { // 0x56667c: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L00566682: { // 0x566682: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L00566685: { // 0x566685: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00566687: { // 0x566687: 750e JNZ 0x00566697
    if(integer::condition("JNZ",flags)) goto L00566697;
  }
  L00566689: { // 0x566689: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0056668d: { // 0x56668d: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L00566692: { // 0x566692: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L00566697: { // 0x566697: 8b4044 MOV EAX,dword ptr [EAX + 0x44]
    s.ax = m.r32((s.ax+0x00000044u));
  }
  L0056669a: { // 0x56669a: 3de7000000 CMP EAX,0xe7
    (void)integer::sub(s.ax,0x000000e7u,32,flags);
  }
  L0056669f: { // 0x56669f: 0f844afeffff JZ 0x005664ef
    if(integer::condition("JZ",flags)) goto L005664ef;
  }
  L005666a5: { // 0x5666a5: 3de8000000 CMP EAX,0xe8
    (void)integer::sub(s.ax,0x000000e8u,32,flags);
  }
  L005666aa: { // 0x5666aa: 0f843ffeffff JZ 0x005664ef
    if(integer::condition("JZ",flags)) goto L005664ef;
  }
  L005666b0: { // 0x5666b0: 66ff442416 INC word ptr [ESP + 0x16]
    m.w16((f.sp+0x00000016u), integer::increment(m.r16((f.sp+0x00000016u)),16,flags));
  }
  L005666b5: { // 0x5666b5: eb8d JMP 0x00566644
    goto L00566644;
  }
  L005666b7: { // 0x5666b7: 8b4b24 MOV ECX,dword ptr [EBX + 0x24]
    s.cx = m.r32((s.bx+0x00000024u));
  }
  L005666ba: { // 0x5666ba: 894c2444 MOV dword ptr [ESP + 0x44],ECX
    m.w32((f.sp+0x00000044u), s.cx);
  }
  L005666be: { // 0x5666be: 8d542444 LEA EDX,[ESP + 0x44]
    s.dx = (f.sp+0x00000044u);
  }
  L005666c2: { // 0x5666c2: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L005666c7: { // 0x5666c7: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005666c8: { // 0x5666c8: e833eefdff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5662413u); flags=s.arithmetic_flags;
  }
  L005666cd: { // 0x5666cd: 8b4044 MOV EAX,dword ptr [EAX + 0x44]
    s.ax = m.r32((s.ax+0x00000044u));
  }
  L005666d0: { // 0x5666d0: 3dcd000000 CMP EAX,0xcd
    (void)integer::sub(s.ax,0x000000cdu,32,flags);
  }
  L005666d5: { // 0x5666d5: 0f8c66020000 JL 0x00566941
    if(integer::condition("JL",flags)) goto L00566941;
  }
  L005666db: { // 0x5666db: 3de8000000 CMP EAX,0xe8
    (void)integer::sub(s.ax,0x000000e8u,32,flags);
  }
  L005666e0: { // 0x5666e0: 0f8f5b020000 JG 0x00566941
    if(integer::condition("JG",flags)) goto L00566941;
  }
  L005666e6: { // 0x5666e6: 0fbf442446 MOVSX EAX,word ptr [ESP + 0x46]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000046u)),16));
  }
  L005666eb: { // 0x5666eb: 668b4c2444 MOV CX,word ptr [ESP + 0x44]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000044u)));
  }
  L005666f0: { // 0x5666f0: 0fbfd1 MOVSX EDX,CX
    s.dx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L005666f3: { // 0x5666f3: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L005666f6: { // 0x5666f6: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L005666f8: { // 0x5666f8: 7814 JS 0x0056670e
    if(integer::condition("JS",flags)) goto L0056670e;
  }
  L005666fa: { // 0x5666fa: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L005666ff: { // 0x5666ff: 7d0d JGE 0x0056670e
    if(integer::condition("JGE",flags)) goto L0056670e;
  }
  L00566701: { // 0x566701: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L00566707: { // 0x566707: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L0056670a: { // 0x56670a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0056670c: { // 0x56670c: 750e JNZ 0x0056671c
    if(integer::condition("JNZ",flags)) goto L0056671c;
  }
  L0056670e: { // 0x56670e: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    s.ax = m.r32((f.sp+0x00000044u));
  }
  L00566712: { // 0x566712: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L00566717: { // 0x566717: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L0056671c: { // 0x56671c: 8b4044 MOV EAX,dword ptr [EAX + 0x44]
    s.ax = m.r32((s.ax+0x00000044u));
  }
  L0056671f: { // 0x56671f: 3de7000000 CMP EAX,0xe7
    (void)integer::sub(s.ax,0x000000e7u,32,flags);
  }
  L00566724: { // 0x566724: 0f84c5fdffff JZ 0x005664ef
    if(integer::condition("JZ",flags)) goto L005664ef;
  }
  L0056672a: { // 0x56672a: 3de8000000 CMP EAX,0xe8
    (void)integer::sub(s.ax,0x000000e8u,32,flags);
  }
  L0056672f: { // 0x56672f: 0f84bafdffff JZ 0x005664ef
    if(integer::condition("JZ",flags)) goto L005664ef;
  }
  L00566735: { // 0x566735: 66ff4c2446 DEC word ptr [ESP + 0x46]
    m.w16((f.sp+0x00000046u), integer::decrement(m.r16((f.sp+0x00000046u)),16,flags));
  }
  L0056673a: { // 0x56673a: 66894c2444 MOV word ptr [ESP + 0x44],CX
    m.w16((f.sp+0x00000044u), (s.cx & 0xffffu));
  }
  L0056673f: { // 0x56673f: e97affffff JMP 0x005666be
    goto L005666be;
  }
  L00566744: { // 0x566744: 83f84a CMP EAX,0x4a
    (void)integer::sub(s.ax,0x0000004au,32,flags);
  }
  L00566747: { // 0x566747: 7c05 JL 0x0056674e
    if(integer::condition("JL",flags)) goto L0056674e;
  }
  L00566749: { // 0x566749: 83f852 CMP EAX,0x52
    (void)integer::sub(s.ax,0x00000052u,32,flags);
  }
  L0056674c: { // 0x56674c: 7e13 JLE 0x00566761
    if(integer::condition("JLE",flags)) goto L00566761;
  }
  L0056674e: { // 0x56674e: 83f85c CMP EAX,0x5c
    (void)integer::sub(s.ax,0x0000005cu,32,flags);
  }
  L00566751: { // 0x566751: 7c05 JL 0x00566758
    if(integer::condition("JL",flags)) goto L00566758;
  }
  L00566753: { // 0x566753: 83f85f CMP EAX,0x5f
    (void)integer::sub(s.ax,0x0000005fu,32,flags);
  }
  L00566756: { // 0x566756: 7e09 JLE 0x00566761
    if(integer::condition("JLE",flags)) goto L00566761;
  }
  L00566758: { // 0x566758: 83f864 CMP EAX,0x64
    (void)integer::sub(s.ax,0x00000064u,32,flags);
  }
  L0056675b: { // 0x56675b: 0f85f4000000 JNZ 0x00566855
    if(integer::condition("JNZ",flags)) goto L00566855;
  }
  L00566761: { // 0x566761: 8b4b24 MOV ECX,dword ptr [EBX + 0x24]
    s.cx = m.r32((s.bx+0x00000024u));
  }
  L00566764: { // 0x566764: 894c2444 MOV dword ptr [ESP + 0x44],ECX
    m.w32((f.sp+0x00000044u), s.cx);
  }
  L00566768: { // 0x566768: 8d542444 LEA EDX,[ESP + 0x44]
    s.dx = (f.sp+0x00000044u);
  }
  L0056676c: { // 0x56676c: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00566771: { // 0x566771: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00566772: { // 0x566772: e889edfdff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5662583u); flags=s.arithmetic_flags;
  }
  L00566777: { // 0x566777: 8b4044 MOV EAX,dword ptr [EAX + 0x44]
    s.ax = m.r32((s.ax+0x00000044u));
  }
  L0056677a: { // 0x56677a: 83f84a CMP EAX,0x4a
    (void)integer::sub(s.ax,0x0000004au,32,flags);
  }
  L0056677d: { // 0x56677d: 7c5c JL 0x005667db
    if(integer::condition("JL",flags)) goto L005667db;
  }
  L0056677f: { // 0x56677f: 83f865 CMP EAX,0x65
    (void)integer::sub(s.ax,0x00000065u,32,flags);
  }
  L00566782: { // 0x566782: 7f57 JG 0x005667db
    if(integer::condition("JG",flags)) goto L005667db;
  }
  L00566784: { // 0x566784: 668b4c2446 MOV CX,word ptr [ESP + 0x46]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000046u)));
  }
  L00566789: { // 0x566789: 0fbf542444 MOVSX EDX,word ptr [ESP + 0x44]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000044u)),16));
  }
  L0056678e: { // 0x56678e: 0fbfc1 MOVSX EAX,CX
    s.ax = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L00566791: { // 0x566791: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L00566794: { // 0x566794: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00566796: { // 0x566796: 7814 JS 0x005667ac
    if(integer::condition("JS",flags)) goto L005667ac;
  }
  L00566798: { // 0x566798: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L0056679d: { // 0x56679d: 7d0d JGE 0x005667ac
    if(integer::condition("JGE",flags)) goto L005667ac;
  }
  L0056679f: { // 0x56679f: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L005667a5: { // 0x5667a5: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L005667a8: { // 0x5667a8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005667aa: { // 0x5667aa: 750e JNZ 0x005667ba
    if(integer::condition("JNZ",flags)) goto L005667ba;
  }
  L005667ac: { // 0x5667ac: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    s.ax = m.r32((f.sp+0x00000044u));
  }
  L005667b0: { // 0x5667b0: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L005667b5: { // 0x5667b5: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L005667ba: { // 0x5667ba: 8b4044 MOV EAX,dword ptr [EAX + 0x44]
    s.ax = m.r32((s.ax+0x00000044u));
  }
  L005667bd: { // 0x5667bd: 83f864 CMP EAX,0x64
    (void)integer::sub(s.ax,0x00000064u,32,flags);
  }
  L005667c0: { // 0x5667c0: 0f8429fdffff JZ 0x005664ef
    if(integer::condition("JZ",flags)) goto L005664ef;
  }
  L005667c6: { // 0x5667c6: 83f865 CMP EAX,0x65
    (void)integer::sub(s.ax,0x00000065u,32,flags);
  }
  L005667c9: { // 0x5667c9: 0f8420fdffff JZ 0x005664ef
    if(integer::condition("JZ",flags)) goto L005664ef;
  }
  L005667cf: { // 0x5667cf: 66ff4c2444 DEC word ptr [ESP + 0x44]
    m.w16((f.sp+0x00000044u), integer::decrement(m.r16((f.sp+0x00000044u)),16,flags));
  }
  L005667d4: { // 0x5667d4: 66894c2446 MOV word ptr [ESP + 0x46],CX
    m.w16((f.sp+0x00000046u), (s.cx & 0xffffu));
  }
  L005667d9: { // 0x5667d9: eb8d JMP 0x00566768
    goto L00566768;
  }
  L005667db: { // 0x5667db: 8b4b24 MOV ECX,dword ptr [EBX + 0x24]
    s.cx = m.r32((s.bx+0x00000024u));
  }
  L005667de: { // 0x5667de: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L005667e2: { // 0x5667e2: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  L005667e6: { // 0x5667e6: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L005667eb: { // 0x5667eb: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005667ec: { // 0x5667ec: e80fedfdff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5662705u); flags=s.arithmetic_flags;
  }
  L005667f1: { // 0x5667f1: 8b4044 MOV EAX,dword ptr [EAX + 0x44]
    s.ax = m.r32((s.ax+0x00000044u));
  }
  L005667f4: { // 0x5667f4: 83f84a CMP EAX,0x4a
    (void)integer::sub(s.ax,0x0000004au,32,flags);
  }
  L005667f7: { // 0x5667f7: 0f8c44010000 JL 0x00566941
    if(integer::condition("JL",flags)) goto L00566941;
  }
  L005667fd: { // 0x5667fd: 83f865 CMP EAX,0x65
    (void)integer::sub(s.ax,0x00000065u,32,flags);
  }
  L00566800: { // 0x566800: 0f8f3b010000 JG 0x00566941
    if(integer::condition("JG",flags)) goto L00566941;
  }
  L00566806: { // 0x566806: 0fbf442416 MOVSX EAX,word ptr [ESP + 0x16]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000016u)),16));
  }
  L0056680b: { // 0x56680b: 0fbf4c2414 MOVSX ECX,word ptr [ESP + 0x14]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000014u)),16));
  }
  L00566810: { // 0x566810: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L00566813: { // 0x566813: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00566815: { // 0x566815: 7814 JS 0x0056682b
    if(integer::condition("JS",flags)) goto L0056682b;
  }
  L00566817: { // 0x566817: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L0056681c: { // 0x56681c: 7d0d JGE 0x0056682b
    if(integer::condition("JGE",flags)) goto L0056682b;
  }
  L0056681e: { // 0x56681e: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L00566824: { // 0x566824: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L00566827: { // 0x566827: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00566829: { // 0x566829: 750e JNZ 0x00566839
    if(integer::condition("JNZ",flags)) goto L00566839;
  }
  L0056682b: { // 0x56682b: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0056682f: { // 0x56682f: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L00566834: { // 0x566834: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L00566839: { // 0x566839: 8b4044 MOV EAX,dword ptr [EAX + 0x44]
    s.ax = m.r32((s.ax+0x00000044u));
  }
  L0056683c: { // 0x56683c: 83f864 CMP EAX,0x64
    (void)integer::sub(s.ax,0x00000064u,32,flags);
  }
  L0056683f: { // 0x56683f: 0f84aafcffff JZ 0x005664ef
    if(integer::condition("JZ",flags)) goto L005664ef;
  }
  L00566845: { // 0x566845: 83f865 CMP EAX,0x65
    (void)integer::sub(s.ax,0x00000065u,32,flags);
  }
  L00566848: { // 0x566848: 0f84a1fcffff JZ 0x005664ef
    if(integer::condition("JZ",flags)) goto L005664ef;
  }
  L0056684e: { // 0x56684e: 66ff442414 INC word ptr [ESP + 0x14]
    m.w16((f.sp+0x00000014u), integer::increment(m.r16((f.sp+0x00000014u)),16,flags));
  }
  L00566853: { // 0x566853: eb8d JMP 0x005667e2
    goto L005667e2;
  }
  L00566855: { // 0x566855: 8b4b24 MOV ECX,dword ptr [EBX + 0x24]
    s.cx = m.r32((s.bx+0x00000024u));
  }
  L00566858: { // 0x566858: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L0056685c: { // 0x56685c: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  L00566860: { // 0x566860: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00566865: { // 0x566865: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00566866: { // 0x566866: e895ecfdff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5662827u); flags=s.arithmetic_flags;
  }
  L0056686b: { // 0x56686b: 8b4044 MOV EAX,dword ptr [EAX + 0x44]
    s.ax = m.r32((s.ax+0x00000044u));
  }
  L0056686e: { // 0x56686e: 83f84a CMP EAX,0x4a
    (void)integer::sub(s.ax,0x0000004au,32,flags);
  }
  L00566871: { // 0x566871: 7c54 JL 0x005668c7
    if(integer::condition("JL",flags)) goto L005668c7;
  }
  L00566873: { // 0x566873: 83f865 CMP EAX,0x65
    (void)integer::sub(s.ax,0x00000065u,32,flags);
  }
  L00566876: { // 0x566876: 7f4f JG 0x005668c7
    if(integer::condition("JG",flags)) goto L005668c7;
  }
  L00566878: { // 0x566878: 0fbf442416 MOVSX EAX,word ptr [ESP + 0x16]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000016u)),16));
  }
  L0056687d: { // 0x56687d: 0fbf4c2414 MOVSX ECX,word ptr [ESP + 0x14]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000014u)),16));
  }
  L00566882: { // 0x566882: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L00566885: { // 0x566885: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00566887: { // 0x566887: 7814 JS 0x0056689d
    if(integer::condition("JS",flags)) goto L0056689d;
  }
  L00566889: { // 0x566889: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L0056688e: { // 0x56688e: 7d0d JGE 0x0056689d
    if(integer::condition("JGE",flags)) goto L0056689d;
  }
  L00566890: { // 0x566890: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L00566896: { // 0x566896: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L00566899: { // 0x566899: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0056689b: { // 0x56689b: 750e JNZ 0x005668ab
    if(integer::condition("JNZ",flags)) goto L005668ab;
  }
  L0056689d: { // 0x56689d: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L005668a1: { // 0x5668a1: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L005668a6: { // 0x5668a6: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L005668ab: { // 0x5668ab: 8b4044 MOV EAX,dword ptr [EAX + 0x44]
    s.ax = m.r32((s.ax+0x00000044u));
  }
  L005668ae: { // 0x5668ae: 83f864 CMP EAX,0x64
    (void)integer::sub(s.ax,0x00000064u,32,flags);
  }
  L005668b1: { // 0x5668b1: 0f8438fcffff JZ 0x005664ef
    if(integer::condition("JZ",flags)) goto L005664ef;
  }
  L005668b7: { // 0x5668b7: 83f865 CMP EAX,0x65
    (void)integer::sub(s.ax,0x00000065u,32,flags);
  }
  L005668ba: { // 0x5668ba: 0f842ffcffff JZ 0x005664ef
    if(integer::condition("JZ",flags)) goto L005664ef;
  }
  L005668c0: { // 0x5668c0: 66ff442416 INC word ptr [ESP + 0x16]
    m.w16((f.sp+0x00000016u), integer::increment(m.r16((f.sp+0x00000016u)),16,flags));
  }
  L005668c5: { // 0x5668c5: eb95 JMP 0x0056685c
    goto L0056685c;
  }
  L005668c7: { // 0x5668c7: 8b4b24 MOV ECX,dword ptr [EBX + 0x24]
    s.cx = m.r32((s.bx+0x00000024u));
  }
  L005668ca: { // 0x5668ca: 894c2444 MOV dword ptr [ESP + 0x44],ECX
    m.w32((f.sp+0x00000044u), s.cx);
  }
  L005668ce: { // 0x5668ce: 8d542444 LEA EDX,[ESP + 0x44]
    s.dx = (f.sp+0x00000044u);
  }
  L005668d2: { // 0x5668d2: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L005668d7: { // 0x5668d7: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005668d8: { // 0x5668d8: e823ecfdff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5662941u); flags=s.arithmetic_flags;
  }
  L005668dd: { // 0x5668dd: 8b4044 MOV EAX,dword ptr [EAX + 0x44]
    s.ax = m.r32((s.ax+0x00000044u));
  }
  L005668e0: { // 0x5668e0: 83f84a CMP EAX,0x4a
    (void)integer::sub(s.ax,0x0000004au,32,flags);
  }
  L005668e3: { // 0x5668e3: 7c5c JL 0x00566941
    if(integer::condition("JL",flags)) goto L00566941;
  }
  L005668e5: { // 0x5668e5: 83f865 CMP EAX,0x65
    (void)integer::sub(s.ax,0x00000065u,32,flags);
  }
  L005668e8: { // 0x5668e8: 7f57 JG 0x00566941
    if(integer::condition("JG",flags)) goto L00566941;
  }
  L005668ea: { // 0x5668ea: 0fbf442446 MOVSX EAX,word ptr [ESP + 0x46]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000046u)),16));
  }
  L005668ef: { // 0x5668ef: 668b4c2444 MOV CX,word ptr [ESP + 0x44]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000044u)));
  }
  L005668f4: { // 0x5668f4: 0fbfd1 MOVSX EDX,CX
    s.dx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L005668f7: { // 0x5668f7: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L005668fa: { // 0x5668fa: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L005668fc: { // 0x5668fc: 7814 JS 0x00566912
    if(integer::condition("JS",flags)) goto L00566912;
  }
  L005668fe: { // 0x5668fe: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00566903: { // 0x566903: 7d0d JGE 0x00566912
    if(integer::condition("JGE",flags)) goto L00566912;
  }
  L00566905: { // 0x566905: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L0056690b: { // 0x56690b: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L0056690e: { // 0x56690e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00566910: { // 0x566910: 750e JNZ 0x00566920
    if(integer::condition("JNZ",flags)) goto L00566920;
  }
  L00566912: { // 0x566912: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    s.ax = m.r32((f.sp+0x00000044u));
  }
  L00566916: { // 0x566916: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L0056691b: { // 0x56691b: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L00566920: { // 0x566920: 8b4044 MOV EAX,dword ptr [EAX + 0x44]
    s.ax = m.r32((s.ax+0x00000044u));
  }
  L00566923: { // 0x566923: 83f864 CMP EAX,0x64
    (void)integer::sub(s.ax,0x00000064u,32,flags);
  }
  L00566926: { // 0x566926: 0f84c3fbffff JZ 0x005664ef
    if(integer::condition("JZ",flags)) goto L005664ef;
  }
  L0056692c: { // 0x56692c: 83f865 CMP EAX,0x65
    (void)integer::sub(s.ax,0x00000065u,32,flags);
  }
  L0056692f: { // 0x56692f: 0f84bafbffff JZ 0x005664ef
    if(integer::condition("JZ",flags)) goto L005664ef;
  }
  L00566935: { // 0x566935: 66ff4c2446 DEC word ptr [ESP + 0x46]
    m.w16((f.sp+0x00000046u), integer::decrement(m.r16((f.sp+0x00000046u)),16,flags));
  }
  L0056693a: { // 0x56693a: 66894c2444 MOV word ptr [ESP + 0x44],CX
    m.w16((f.sp+0x00000044u), (s.cx & 0xffffu));
  }
  L0056693f: { // 0x56693f: eb8d JMP 0x005668ce
    goto L005668ce;
  }
  L00566941: { // 0x566941: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00566942: { // 0x566942: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00566943: { // 0x566943: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00566944: { // 0x566944: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00566946: { // 0x566946: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00566947: { // 0x566947: 83c430 ADD ESP,0x30
    f.sp = integer::add(f.sp,0x00000030u,32,flags);
  }
  L0056694a: { // 0x56694a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
