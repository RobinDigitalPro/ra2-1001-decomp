#include "recovered/recovery_b657_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b657 {
namespace {
void f_00127630(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_0007b190(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_00127630(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00527630: { // 0x00527630: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00527631: { // 0x00527631: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00527633: { // 0x00527633: 8b86a4000000 MOV EAX,dword ptr [ESI + 0xa4]
    s.ax = m.r32((s.si+0x000000a4u));
  }
  L00527639: { // 0x00527639: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0052763b: { // 0x0052763b: 7517 JNZ 0x00527654
    if(integer::condition("JNZ",flags)) goto L00527654;
  }
  L0052763d: { // 0x0052763d: 8a8ec4020000 MOV CL,byte ptr [ESI + 0x2c4]
    s.cx = with_al(s.cx, m.r8((s.si+0x000002c4u)));
  }
  L00527643: { // 0x00527643: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00527645: { // 0x00527645: 740d JZ 0x00527654
    if(integer::condition("JZ",flags)) goto L00527654;
  }
  L00527647: { // 0x00527647: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00527649: { // 0x00527649: e872210000 CALL 0x005297c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005297c0u,5404238u); flags=s.arithmetic_flags;
  }
  L0052764e: { // 0x0052764e: 8b86a4000000 MOV EAX,dword ptr [ESI + 0xa4]
    s.ax = m.r32((s.si+0x000000a4u));
  }
  L00527654: { // 0x00527654: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00527655: { // 0x00527655: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
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
void f_0007b190(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0047b190: { // 0x47b190: 8b4138 MOV EAX, dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  L0047b193: { // 0x47b193: 3dffff0000 CMP EAX, 0xffff
    (void)integer::sub(s.ax,0x0000ffffu,32,flags);
  }
  L0047b198: { // 0x47b198: 7407 JZ 0x47b1a1
    if(integer::condition("JZ",flags)) goto L0047b1a1;
  }
  L0047b19a: { // 0x47b19a: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0047b19c: { // 0x47b19c: 7403 JZ 0x47b1a1
    if(integer::condition("JZ",flags)) goto L0047b1a1;
  }
  L0047b19e: { // 0x47b19e: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0047b1a0: { // 0x47b1a0: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b1a1: { // 0x47b1a1: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L0047b1a3: { // 0x47b1a3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}


} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 5404208u:f_00127630(m,s,child,{});break;
case 5526784u:f_00145500(m,s,child,{});break;
case 4698512u:f_0007b190(m,s,child,{});break;
default:throw std::domain_error("recovery657 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_005862e0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005862e0: { // 0x5862e0: 83ec14 SUB ESP,0x14
    f.sp = integer::sub(f.sp,0x00000014u,32,flags);
  }
  L005862e3: { // 0x5862e3: a11489a200 MOV EAX,[0x00a28914]
    s.ax = m.r32((0x00a28914u));
  }
  L005862e8: { // 0x5862e8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005862e9: { // 0x5862e9: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005862ea: { // 0x5862ea: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005862eb: { // 0x5862eb: 8b3488 MOV ESI,dword ptr [EAX + ECX*0x4]
    s.si = m.r32((s.ax+(s.cx * 0x00000004u)));
  }
  L005862ee: { // 0x5862ee: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005862ef: { // 0x5862ef: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L005862f1: { // 0x5862f1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005862f3: { // 0x5862f3: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005862f5: { // 0x5862f5: 897c241c MOV dword ptr [ESP + 0x1c],EDI
    m.w32((f.sp+0x0000001cu), s.di);
  }
  L005862f9: { // 0x5862f9: 89742410 MOV dword ptr [ESP + 0x10],ESI
    m.w32((f.sp+0x00000010u), s.si);
  }
  L005862fd: { // 0x5862fd: ff929c000000 CALL dword ptr [EDX + 0x9c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000009cu)),5792515u); flags=s.arithmetic_flags;
  }
  L00586303: { // 0x586303: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00586305: { // 0x586305: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L00586309: { // 0x586309: 0f844e010000 JZ 0x0058645d
    if(integer::condition("JZ",flags)) goto L0058645d;
  }
  L0058630f: { // 0x58630f: 8b86b8020000 MOV EAX,dword ptr [ESI + 0x2b8]
    s.ax = m.r32((s.si+0x000002b8u));
  }
  L00586315: { // 0x586315: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00586317: { // 0x586317: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00586319: { // 0x586319: 0f8e3e010000 JLE 0x0058645d
    if(integer::condition("JLE",flags)) goto L0058645d;
  }
  L0058631f: { // 0x58631f: 8b353486a500 MOV ESI,dword ptr [0x00a58634]
    s.si = m.r32((0x00a58634u));
  }
  L00586325: { // 0x586325: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00586329: { // 0x586329: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L0058632b: { // 0x58632b: 8b88b4020000 MOV ECX,dword ptr [EAX + 0x2b4]
    s.cx = m.r32((s.ax+0x000002b4u));
  }
  L00586331: { // 0x586331: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00586333: { // 0x586333: 0f8ef1000000 JLE 0x0058642a
    if(integer::condition("JLE",flags)) goto L0058642a;
  }
  L00586339: { // 0x586339: 668b07 MOV AX,word ptr [EDI]
    s.ax = with_ax(s.ax, m.r16((s.di)));
  }
  L0058633c: { // 0x58633c: 668bcb MOV CX,BX
    s.cx = with_ax(s.cx, (s.bx & 0xffffu));
  }
  L0058633f: { // 0x58633f: 66034f02 ADD CX,word ptr [EDI + 0x2]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((s.di+0x00000002u)),16,flags));
  }
  L00586343: { // 0x586343: 6603c5 ADD AX,BP
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),(s.bp & 0xffffu),16,flags));
  }
  L00586346: { // 0x586346: 6689442418 MOV word ptr [ESP + 0x18],AX
    m.w16((f.sp+0x00000018u), (s.ax & 0xffffu));
  }
  L0058634b: { // 0x58634b: 66894c241a MOV word ptr [ESP + 0x1a],CX
    m.w16((f.sp+0x0000001au), (s.cx & 0xffffu));
  }
  L00586350: { // 0x586350: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L00586354: { // 0x586354: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L00586358: { // 0x586358: 0fbfd0 MOVSX EDX,AX
    s.dx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0058635b: { // 0x58635b: 0fbfc1 MOVSX EAX,CX
    s.ax = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L0058635e: { // 0x58635e: 8d0c10 LEA ECX,[EAX + EDX*0x1]
    s.cx = (s.ax+(s.dx * 0x00000001u));
  }
  L00586361: { // 0x586361: 3bce CMP ECX,ESI
    (void)integer::sub(s.cx,s.si,32,flags);
  }
  L00586363: { // 0x586363: 0f8ede000000 JLE 0x00586447
    if(integer::condition("JLE",flags)) goto L00586447;
  }
  L00586369: { // 0x586369: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L0058636b: { // 0x58636b: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L0058636d: { // 0x58636d: 3bfe CMP EDI,ESI
    (void)integer::sub(s.di,s.si,32,flags);
  }
  L0058636f: { // 0x58636f: 0f8dd2000000 JGE 0x00586447
    if(integer::condition("JGE",flags)) goto L00586447;
  }
  L00586375: { // 0x586375: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00586377: { // 0x586377: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L00586379: { // 0x586379: 0f8dc8000000 JGE 0x00586447
    if(integer::condition("JGE",flags)) goto L00586447;
  }
  L0058637f: { // 0x58637f: 3b0d3886a500 CMP ECX,dword ptr [0x00a58638]
    (void)integer::sub(s.cx,m.r32((0x00a58638u)),32,flags);
  }
  L00586385: { // 0x586385: 0f8fbc000000 JG 0x00586447
    if(integer::condition("JG",flags)) goto L00586447;
  }
  L0058638b: { // 0x58638b: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L0058638f: { // 0x58638f: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00586394: { // 0x586394: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00586395: { // 0x586395: e866f1fbff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5792666u); flags=s.arithmetic_flags;
  }
  L0058639a: { // 0x58639a: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0058639c: { // 0x58639c: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L005863a0: { // 0x5863a0: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L005863a4: { // 0x5863a4: 8b91b4020000 MOV EDX,dword ptr [ECX + 0x2b4]
    s.dx = m.r32((s.cx+0x000002b4u));
  }
  L005863aa: { // 0x5863aa: 0fafd3 IMUL EDX,EBX
    s.dx = integer::imul(s.dx,s.bx,32,flags);
  }
  L005863ad: { // 0x5863ad: 03d5 ADD EDX,EBP
    s.dx = integer::add(s.dx,s.bp,32,flags);
  }
  L005863af: { // 0x5863af: 8b749010 MOV ESI,dword ptr [EAX + EDX*0x4 + 0x10]
    s.si = m.r32((s.ax+(s.dx * 0x00000004u)+0x00000010u));
  }
  L005863b3: { // 0x5863b3: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L005863b5: { // 0x5863b5: 7458 JZ 0x0058640f
    if(integer::condition("JZ",flags)) goto L0058640f;
  }
  L005863b7: { // 0x5863b7: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005863b9: { // 0x5863b9: e8d24defff CALL 0x0047b190
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b190u,5792702u); flags=s.arithmetic_flags;
  }
  L005863be: { // 0x5863be: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005863c0: { // 0x5863c0: 750f JNZ 0x005863d1
    if(integer::condition("JNZ",flags)) goto L005863d1;
  }
  L005863c2: { // 0x5863c2: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005863c4: { // 0x5863c4: e8e74defff CALL 0x0047b1b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b1b0u,5792713u); flags=s.arithmetic_flags;
  }
  L005863c9: { // 0x5863c9: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005863cb: { // 0x5863cb: 0f8480000000 JZ 0x00586451
    if(integer::condition("JZ",flags)) goto L00586451;
  }
  L005863d1: { // 0x5863d1: 0fbe562a MOVSX EDX,byte ptr [ESI + 0x2a]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.si+0x0000002au)),8));
  }
  L005863d5: { // 0x5863d5: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L005863d7: { // 0x5863d7: 8a8f1c010000 MOV CL,byte ptr [EDI + 0x11c]
    s.cx = with_al(s.cx, m.r8((s.di+0x0000011cu)));
  }
  L005863dd: { // 0x5863dd: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L005863df: { // 0x5863df: 7570 JNZ 0x00586451
    if(integer::condition("JNZ",flags)) goto L00586451;
  }
  L005863e1: { // 0x5863e1: 8a442428 MOV AL,byte ptr [ESP + 0x28]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000028u)));
  }
  L005863e5: { // 0x5863e5: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005863e7: { // 0x5863e7: 7426 JZ 0x0058640f
    if(integer::condition("JZ",flags)) goto L0058640f;
  }
  L005863e9: { // 0x5863e9: 0fbf442416 MOVSX EAX,word ptr [ESP + 0x16]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000016u)),16));
  }
  L005863ee: { // 0x5863ee: 0faf054c6b8300 IMUL EAX,dword ptr [0x00836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  L005863f5: { // 0x5863f5: 0fbf4c2414 MOVSX ECX,word ptr [ESP + 0x14]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000014u)),16));
  }
  L005863fa: { // 0x5863fa: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L005863fc: { // 0x5863fc: 8d1480 LEA EDX,[EAX + EAX*0x4]
    s.dx = (s.ax+(s.ax * 0x00000004u));
  }
  L005863ff: { // 0x5863ff: a13c86a500 MOV EAX,[0x00a5863c]
    s.ax = m.r32((0x00a5863cu));
  }
  L00586404: { // 0x586404: c1e204 SHL EDX,0x4
    s.dx = integer::shift(s.dx,0x00000004u,32,flags,integer::Shift::left);
  }
  L00586407: { // 0x586407: 8a4c0246 MOV CL,byte ptr [EDX + EAX*0x1 + 0x46]
    s.cx = with_al(s.cx, m.r8((s.dx+(s.ax * 0x00000001u)+0x00000046u)));
  }
  L0058640b: { // 0x58640b: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0058640d: { // 0x58640d: 7542 JNZ 0x00586451
    if(integer::condition("JNZ",flags)) goto L00586451;
  }
  L0058640f: { // 0x58640f: 8b353486a500 MOV ESI,dword ptr [0x00a58634]
    s.si = m.r32((0x00a58634u));
  }
  L00586415: { // 0x586415: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00586419: { // 0x586419: 8b7c241c MOV EDI,dword ptr [ESP + 0x1c]
    s.di = m.r32((f.sp+0x0000001cu));
  }
  L0058641d: { // 0x58641d: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L0058641e: { // 0x58641e: 3ba9b4020000 CMP EBP,dword ptr [ECX + 0x2b4]
    (void)integer::sub(s.bp,m.r32((s.cx+0x000002b4u)),32,flags);
  }
  L00586424: { // 0x586424: 0f8c0fffffff JL 0x00586339
    if(integer::condition("JL",flags)) goto L00586339;
  }
  L0058642a: { // 0x58642a: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0058642e: { // 0x58642e: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L0058642f: { // 0x58642f: 3b9ab8020000 CMP EBX,dword ptr [EDX + 0x2b8]
    (void)integer::sub(s.bx,m.r32((s.dx+0x000002b8u)),32,flags);
  }
  L00586435: { // 0x586435: 0f8ceafeffff JL 0x00586325
    if(integer::condition("JL",flags)) goto L00586325;
  }
  L0058643b: { // 0x58643b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0058643c: { // 0x58643c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0058643d: { // 0x58643d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0058643e: { // 0x58643e: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00586440: { // 0x586440: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00586441: { // 0x586441: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L00586444: { // 0x586444: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00586447: { // 0x586447: 8a44242c MOV AL,byte ptr [ESP + 0x2c]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000002cu)));
  }
  L0058644b: { // 0x58644b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0058644d: { // 0x58644d: 7502 JNZ 0x00586451
    if(integer::condition("JNZ",flags)) goto L00586451;
  }
  L0058644f: { // 0x58644f: ebc4 JMP 0x00586415
    goto L00586415;
  }
  L00586451: { // 0x586451: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00586452: { // 0x586452: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00586453: { // 0x586453: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00586454: { // 0x586454: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00586456: { // 0x586456: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00586457: { // 0x586457: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L0058645a: { // 0x58645a: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0058645d: { // 0x58645d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0058645e: { // 0x58645e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0058645f: { // 0x58645f: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00586460: { // 0x586460: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00586462: { // 0x586462: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00586463: { // 0x586463: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L00586466: { // 0x586466: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00586470(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00586470: { // 0x586470: 83ec14 SUB ESP,0x14
    f.sp = integer::sub(f.sp,0x00000014u,32,flags);
  }
  L00586473: { // 0x586473: a11489a200 MOV EAX,[0x00a28914]
    s.ax = m.r32((0x00a28914u));
  }
  L00586478: { // 0x586478: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00586479: { // 0x586479: 8954240c MOV dword ptr [ESP + 0xc],EDX
    m.w32((f.sp+0x0000000cu), s.dx);
  }
  L0058647d: { // 0x58647d: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0058647e: { // 0x58647e: 8b1c88 MOV EBX,dword ptr [EAX + ECX*0x4]
    s.bx = m.r32((s.ax+(s.cx * 0x00000004u)));
  }
  L00586481: { // 0x586481: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00586483: { // 0x586483: 895c240c MOV dword ptr [ESP + 0xc],EBX
    m.w32((f.sp+0x0000000cu), s.bx);
  }
  L00586487: { // 0x586487: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L00586489: { // 0x586489: ff929c000000 CALL dword ptr [EDX + 0x9c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000009cu)),5792911u); flags=s.arithmetic_flags;
  }
  L0058648f: { // 0x58648f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00586491: { // 0x586491: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00586495: { // 0x586495: 0f84d2000000 JZ 0x0058656d
    if(integer::condition("JZ",flags)) goto L0058656d;
  }
  L0058649b: { // 0x58649b: 8b83b8020000 MOV EAX,dword ptr [EBX + 0x2b8]
    s.ax = m.r32((s.bx+0x000002b8u));
  }
  L005864a1: { // 0x5864a1: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L005864a3: { // 0x5864a3: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005864a5: { // 0x5864a5: 0f8ec2000000 JLE 0x0058656d
    if(integer::condition("JLE",flags)) goto L0058656d;
  }
  L005864ab: { // 0x5864ab: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005864ac: { // 0x5864ac: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005864ad: { // 0x5864ad: 8b3d3486a500 MOV EDI,dword ptr [0x00a58634]
    s.di = m.r32((0x00a58634u));
  }
  L005864b3: { // 0x5864b3: 8b83b4020000 MOV EAX,dword ptr [EBX + 0x2b4]
    s.ax = m.r32((s.bx+0x000002b4u));
  }
  L005864b9: { // 0x5864b9: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L005864bb: { // 0x5864bb: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005864bd: { // 0x5864bd: 0f8e99000000 JLE 0x0058655c
    if(integer::condition("JLE",flags)) goto L0058655c;
  }
  L005864c3: { // 0x5864c3: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L005864c7: { // 0x5864c7: 668bcd MOV CX,BP
    s.cx = with_ax(s.cx, (s.bp & 0xffffu));
  }
  L005864ca: { // 0x5864ca: 668b02 MOV AX,word ptr [EDX]
    s.ax = with_ax(s.ax, m.r16((s.dx)));
  }
  L005864cd: { // 0x5864cd: 66034a02 ADD CX,word ptr [EDX + 0x2]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((s.dx+0x00000002u)),16,flags));
  }
  L005864d1: { // 0x5864d1: 6603c6 ADD AX,SI
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),(s.si & 0xffffu),16,flags));
  }
  L005864d4: { // 0x5864d4: 6689442410 MOV word ptr [ESP + 0x10],AX
    m.w16((f.sp+0x00000010u), (s.ax & 0xffffu));
  }
  L005864d9: { // 0x5864d9: 66894c2412 MOV word ptr [ESP + 0x12],CX
    m.w16((f.sp+0x00000012u), (s.cx & 0xffffu));
  }
  L005864de: { // 0x5864de: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L005864e2: { // 0x5864e2: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L005864e6: { // 0x5864e6: 0fbfd0 MOVSX EDX,AX
    s.dx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L005864e9: { // 0x5864e9: 0fbfc1 MOVSX EAX,CX
    s.ax = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L005864ec: { // 0x5864ec: 8d0c10 LEA ECX,[EAX + EDX*0x1]
    s.cx = (s.ax+(s.dx * 0x00000001u));
  }
  L005864ef: { // 0x5864ef: 3bcf CMP ECX,EDI
    (void)integer::sub(s.cx,s.di,32,flags);
  }
  L005864f1: { // 0x5864f1: 7e5a JLE 0x0058654d
    if(integer::condition("JLE",flags)) goto L0058654d;
  }
  L005864f3: { // 0x5864f3: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  L005864f5: { // 0x5864f5: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L005864f7: { // 0x5864f7: 3bdf CMP EBX,EDI
    (void)integer::sub(s.bx,s.di,32,flags);
  }
  L005864f9: { // 0x5864f9: 7d4e JGE 0x00586549
    if(integer::condition("JGE",flags)) goto L00586549;
  }
  L005864fb: { // 0x5864fb: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L005864fd: { // 0x5864fd: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L005864ff: { // 0x5864ff: 7d48 JGE 0x00586549
    if(integer::condition("JGE",flags)) goto L00586549;
  }
  L00586501: { // 0x586501: 3b0d3886a500 CMP ECX,dword ptr [0x00a58638]
    (void)integer::sub(s.cx,m.r32((0x00a58638u)),32,flags);
  }
  L00586507: { // 0x586507: 7f40 JG 0x00586549
    if(integer::condition("JG",flags)) goto L00586549;
  }
  L00586509: { // 0x586509: 8d44241c LEA EAX,[ESP + 0x1c]
    s.ax = (f.sp+0x0000001cu);
  }
  L0058650d: { // 0x58650d: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00586512: { // 0x586512: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00586513: { // 0x586513: e8e8effbff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5793048u); flags=s.arithmetic_flags;
  }
  L00586518: { // 0x586518: 8b5c2414 MOV EBX,dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  L0058651c: { // 0x58651c: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L00586520: { // 0x586520: 8b8bb4020000 MOV ECX,dword ptr [EBX + 0x2b4]
    s.cx = m.r32((s.bx+0x000002b4u));
  }
  L00586526: { // 0x586526: 0fafcd IMUL ECX,EBP
    s.cx = integer::imul(s.cx,s.bp,32,flags);
  }
  L00586529: { // 0x586529: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L0058652b: { // 0x58652b: 8b7c8a10 MOV EDI,dword ptr [EDX + ECX*0x4 + 0x10]
    s.di = m.r32((s.dx+(s.cx * 0x00000004u)+0x00000010u));
  }
  L0058652f: { // 0x58652f: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L00586531: { // 0x586531: 740e JZ 0x00586541
    if(integer::condition("JZ",flags)) goto L00586541;
  }
  L00586533: { // 0x586533: c74038ffff0000 MOV dword ptr [EAX + 0x38],0xffff
    m.w32((s.ax+0x00000038u), 0x0000ffffu);
  }
  L0058653a: { // 0x58653a: c6801a01000000 MOV byte ptr [EAX + 0x11a],0x0
    m.w8((s.ax+0x0000011au), 0x00000000u);
  }
  L00586541: { // 0x586541: 8b3d3486a500 MOV EDI,dword ptr [0x00a58634]
    s.di = m.r32((0x00a58634u));
  }
  L00586547: { // 0x586547: eb04 JMP 0x0058654d
    goto L0058654d;
  }
  L00586549: { // 0x586549: 8b5c2414 MOV EBX,dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  L0058654d: { // 0x58654d: 8b83b4020000 MOV EAX,dword ptr [EBX + 0x2b4]
    s.ax = m.r32((s.bx+0x000002b4u));
  }
  L00586553: { // 0x586553: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L00586554: { // 0x586554: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L00586556: { // 0x586556: 0f8c67ffffff JL 0x005864c3
    if(integer::condition("JL",flags)) goto L005864c3;
  }
  L0058655c: { // 0x58655c: 8b83b8020000 MOV EAX,dword ptr [EBX + 0x2b8]
    s.ax = m.r32((s.bx+0x000002b8u));
  }
  L00586562: { // 0x586562: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L00586563: { // 0x586563: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L00586565: { // 0x586565: 0f8c48ffffff JL 0x005864b3
    if(integer::condition("JL",flags)) goto L005864b3;
  }
  L0058656b: { // 0x58656b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0058656c: { // 0x58656c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0058656d: { // 0x58656d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0058656e: { // 0x58656e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0058656f: { // 0x58656f: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L00586572: { // 0x586572: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00586580(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00586580: { // 0x586580: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L00586583: { // 0x586583: a11489a200 MOV EAX,[0x00a28914]
    s.ax = m.r32((0x00a28914u));
  }
  L00586588: { // 0x586588: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00586589: { // 0x586589: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0058658a: { // 0x58658a: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L0058658c: { // 0x58658c: 8b3c88 MOV EDI,dword ptr [EAX + ECX*0x4]
    s.di = m.r32((s.ax+(s.cx * 0x00000004u)));
  }
  L0058658f: { // 0x58658f: 89742410 MOV dword ptr [ESP + 0x10],ESI
    m.w32((f.sp+0x00000010u), s.si);
  }
  L00586593: { // 0x586593: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00586595: { // 0x586595: 897c240c MOV dword ptr [ESP + 0xc],EDI
    m.w32((f.sp+0x0000000cu), s.di);
  }
  L00586599: { // 0x586599: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L0058659b: { // 0x58659b: ff929c000000 CALL dword ptr [EDX + 0x9c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000009cu)),5793185u); flags=s.arithmetic_flags;
  }
  L005865a1: { // 0x5865a1: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005865a3: { // 0x5865a3: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L005865a7: { // 0x5865a7: 0f84cf000000 JZ 0x0058667c
    if(integer::condition("JZ",flags)) goto L0058667c;
  }
  L005865ad: { // 0x5865ad: 8b8fb8020000 MOV ECX,dword ptr [EDI + 0x2b8]
    s.cx = m.r32((s.di+0x000002b8u));
  }
  L005865b3: { // 0x5865b3: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005865b5: { // 0x5865b5: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005865b7: { // 0x5865b7: 89442408 MOV dword ptr [ESP + 0x8],EAX
    m.w32((f.sp+0x00000008u), s.ax);
  }
  L005865bb: { // 0x5865bb: 0f8ebb000000 JLE 0x0058667c
    if(integer::condition("JLE",flags)) goto L0058667c;
  }
  L005865c1: { // 0x5865c1: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005865c2: { // 0x5865c2: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005865c3: { // 0x5865c3: 8b2d3486a500 MOV EBP,dword ptr [0x00a58634]
    s.bp = m.r32((0x00a58634u));
  }
  L005865c9: { // 0x5865c9: eb04 JMP 0x005865cf
    goto L005865cf;
  }
  L005865cb: { // 0x5865cb: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L005865cf: { // 0x5865cf: 8bbfb4020000 MOV EDI,dword ptr [EDI + 0x2b4]
    s.di = m.r32((s.di+0x000002b4u));
  }
  L005865d5: { // 0x5865d5: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L005865d7: { // 0x5865d7: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L005865d9: { // 0x5865d9: 0f8e86000000 JLE 0x00586665
    if(integer::condition("JLE",flags)) goto L00586665;
  }
  L005865df: { // 0x5865df: 668b0e MOV CX,word ptr [ESI]
    s.cx = with_ax(s.cx, m.r16((s.si)));
  }
  L005865e2: { // 0x5865e2: 668bd0 MOV DX,AX
    s.dx = with_ax(s.dx, (s.ax & 0xffffu));
  }
  L005865e5: { // 0x5865e5: 66035602 ADD DX,word ptr [ESI + 0x2]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((s.si+0x00000002u)),16,flags));
  }
  L005865e9: { // 0x5865e9: 6603cb ADD CX,BX
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),(s.bx & 0xffffu),16,flags));
  }
  L005865ec: { // 0x5865ec: 0fbff1 MOVSX ESI,CX
    s.si = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L005865ef: { // 0x5865ef: 0fbfca MOVSX ECX,DX
    s.cx = std::uint32_t(integer::sign_extend((s.dx & 0xffffu),16));
  }
  L005865f2: { // 0x5865f2: 8d1431 LEA EDX,[ECX + ESI*0x1]
    s.dx = (s.cx+(s.si * 0x00000001u));
  }
  L005865f5: { // 0x5865f5: 3bd5 CMP EDX,EBP
    (void)integer::sub(s.dx,s.bp,32,flags);
  }
  L005865f7: { // 0x5865f7: 7e55 JLE 0x0058664e
    if(integer::condition("JLE",flags)) goto L0058664e;
  }
  L005865f9: { // 0x5865f9: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L005865fb: { // 0x5865fb: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L005865fd: { // 0x5865fd: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L005865ff: { // 0x5865ff: 7d49 JGE 0x0058664a
    if(integer::condition("JGE",flags)) goto L0058664a;
  }
  L00586601: { // 0x586601: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00586603: { // 0x586603: 2bc6 SUB EAX,ESI
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L00586605: { // 0x586605: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L00586607: { // 0x586607: 7d41 JGE 0x0058664a
    if(integer::condition("JGE",flags)) goto L0058664a;
  }
  L00586609: { // 0x586609: 3b153886a500 CMP EDX,dword ptr [0x00a58638]
    (void)integer::sub(s.dx,m.r32((0x00a58638u)),32,flags);
  }
  L0058660f: { // 0x58660f: 7f39 JG 0x0058664a
    if(integer::condition("JG",flags)) goto L0058664a;
  }
  L00586611: { // 0x586611: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00586615: { // 0x586615: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L00586619: { // 0x586619: 0faff8 IMUL EDI,EAX
    s.di = integer::imul(s.di,s.ax,32,flags);
  }
  L0058661c: { // 0x58661c: 03fb ADD EDI,EBX
    s.di = integer::add(s.di,s.bx,32,flags);
  }
  L0058661e: { // 0x58661e: 837cba1000 CMP dword ptr [EDX + EDI*0x4 + 0x10],0x0
    (void)integer::sub(m.r32((s.dx+(s.di * 0x00000004u)+0x00000010u)),0x00000000u,32,flags);
  }
  L00586623: { // 0x586623: 7429 JZ 0x0058664e
    if(integer::condition("JZ",flags)) goto L0058664e;
  }
  L00586625: { // 0x586625: 0faf0d4c6b8300 IMUL ECX,dword ptr [0x00836b4c]
    s.cx = integer::imul(s.cx,m.r32((0x00836b4cu)),32,flags);
  }
  L0058662c: { // 0x58662c: 8b153c86a500 MOV EDX,dword ptr [0x00a5863c]
    s.dx = m.r32((0x00a5863cu));
  }
  L00586632: { // 0x586632: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L00586634: { // 0x586634: 8d3489 LEA ESI,[ECX + ECX*0x4]
    s.si = (s.cx+(s.cx * 0x00000004u));
  }
  L00586637: { // 0x586637: 8a4c2424 MOV CL,byte ptr [ESP + 0x24]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000024u)));
  }
  L0058663b: { // 0x58663b: c1e604 SHL ESI,0x4
    s.si = integer::shift(s.si,0x00000004u,32,flags,integer::Shift::left);
  }
  L0058663e: { // 0x58663e: 884c1646 MOV byte ptr [ESI + EDX*0x1 + 0x46],CL
    m.w8((s.si+(s.dx * 0x00000001u)+0x00000046u), (s.cx & 0xffu));
  }
  L00586642: { // 0x586642: 8b2d3486a500 MOV EBP,dword ptr [0x00a58634]
    s.bp = m.r32((0x00a58634u));
  }
  L00586648: { // 0x586648: eb04 JMP 0x0058664e
    goto L0058664e;
  }
  L0058664a: { // 0x58664a: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0058664e: { // 0x58664e: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L00586652: { // 0x586652: 8b742418 MOV ESI,dword ptr [ESP + 0x18]
    s.si = m.r32((f.sp+0x00000018u));
  }
  L00586656: { // 0x586656: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L00586657: { // 0x586657: 8bb9b4020000 MOV EDI,dword ptr [ECX + 0x2b4]
    s.di = m.r32((s.cx+0x000002b4u));
  }
  L0058665d: { // 0x58665d: 3bdf CMP EBX,EDI
    (void)integer::sub(s.bx,s.di,32,flags);
  }
  L0058665f: { // 0x58665f: 0f8c7affffff JL 0x005865df
    if(integer::condition("JL",flags)) goto L005865df;
  }
  L00586665: { // 0x586665: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L00586669: { // 0x586669: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0058666a: { // 0x58666a: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0058666e: { // 0x58666e: 3b82b8020000 CMP EAX,dword ptr [EDX + 0x2b8]
    (void)integer::sub(s.ax,m.r32((s.dx+0x000002b8u)),32,flags);
  }
  L00586674: { // 0x586674: 0f8c51ffffff JL 0x005865cb
    if(integer::condition("JL",flags)) goto L005865cb;
  }
  L0058667a: { // 0x58667a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0058667b: { // 0x58667b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0058667c: { // 0x58667c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0058667d: { // 0x58667d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0058667e: { // 0x58667e: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00586681: { // 0x586681: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
