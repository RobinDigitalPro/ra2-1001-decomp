#include "recovered/recovery_b756_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b756 {
namespace {
void f_000585b0(Memory&,State&,Frame&,const Operations&);
void f_000585c0(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_000713b0(Memory&,State&,Frame&,const Operations&);
void f_00053890(Memory&,State&,Frame&,const Operations&);
void f_0005e970(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_000585b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004585b0: { // 0x4585b0: 8b81780c0000 MOV EAX, dword ptr [ECX + 0xc78]
    s.ax = m.r32((s.cx+0x00000c78u));
  }
  L004585b6: { // 0x4585b6: 8b048508ac7b00 MOV EAX, dword ptr [EAX*4 + 0x7bac08]
    s.ax = m.r32(((s.ax * 4u)+0x007bac08u));
  }
  L004585bd: { // 0x4585bd: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000585c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004585c0: { // 0x4585c0: 8a442404 MOV AL, byte ptr [ESP + 4]
    s.ax = with_al(s.ax, m.r8((f.sp+4u)));
  }
  L004585c4: { // 0x4585c4: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004585c6: { // 0x4585c6: 7421 JZ 0x4585e9
    if(integer::condition("JZ",flags)) goto L004585e9;
  }
  L004585c8: { // 0x4585c8: 8a8114120000 MOV AL, byte ptr [ECX + 0x1214]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00001214u)));
  }
  L004585ce: { // 0x4585ce: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004585d0: { // 0x4585d0: 7417 JZ 0x4585e9
    if(integer::condition("JZ",flags)) goto L004585e9;
  }
  L004585d2: { // 0x4585d2: 8b81780c0000 MOV EAX, dword ptr [ECX + 0xc78]
    s.ax = m.r32((s.cx+0x00000c78u));
  }
  L004585d8: { // 0x4585d8: ba01000000 MOV EDX, 1
    s.dx = 1u;
  }
  L004585dd: { // 0x4585dd: 8b048560ac7b00 MOV EAX, dword ptr [EAX*4 + 0x7bac60]
    s.ax = m.r32(((s.ax * 4u)+0x007bac60u));
  }
  L004585e4: { // 0x4585e4: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004585e6: { // 0x4585e6: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004585e9: { // 0x4585e9: 8b81780c0000 MOV EAX, dword ptr [ECX + 0xc78]
    s.ax = m.r32((s.cx+0x00000c78u));
  }
  L004585ef: { // 0x4585ef: 33d2 XOR EDX, EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L004585f1: { // 0x4585f1: 8b048560ac7b00 MOV EAX, dword ptr [EAX*4 + 0x7bac60]
    s.ax = m.r32(((s.ax * 4u)+0x007bac60u));
  }
  L004585f8: { // 0x4585f8: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004585fa: { // 0x4585fa: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00145500(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00545500: { // 0x545500: 8b542404 MOV EDX, dword ptr [ESP + 4]
    s.dx = m.r32((f.sp+4u));
  }
  L00545504: { // 0x545504: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00545505: { // 0x545505: 0fbf4202 MOVSX EAX, word ptr [EDX + 2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.dx+2u)),16));
  }
  L00545509: { // 0x545509: 0fbf32 MOVSX ESI, word ptr [EDX]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.dx)),16));
  }
  L0054550c: { // 0x54550c: c1e009 SHL EAX, 9
    s.ax = integer::shift(s.ax,9u,32,flags,integer::Shift::left);
  }
  L0054550f: { // 0x54550f: 03c6 ADD EAX, ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L00545511: { // 0x545511: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00545512: { // 0x545512: 7814 JS 0x545528
    if(integer::condition("JS",flags)) goto L00545528;
  }
  L00545514: { // 0x545514: 3d00000400 CMP EAX, 0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00545519: { // 0x545519: 7d0d JGE 0x545528
    if(integer::condition("JGE",flags)) goto L00545528;
  }
  L0054551b: { // 0x54551b: 8b8938010000 MOV ECX, dword ptr [ECX + 0x138]
    s.cx = m.r32((s.cx+0x00000138u));
  }
  L00545521: { // 0x545521: 8b0481 MOV EAX, dword ptr [ECX + EAX*4]
    s.ax = m.r32((s.cx+(s.ax * 4u)));
  }
  L00545524: { // 0x545524: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00545526: { // 0x545526: 750d JNZ 0x545535
    if(integer::condition("JNZ",flags)) goto L00545535;
  }
  L00545528: { // 0x545528: 8b12 MOV EDX, dword ptr [EDX]
    s.dx = m.r32((s.dx));
  }
  L0054552a: { // 0x54552a: b81076a500 MOV EAX, 0xa57610
    s.ax = 0x00a57610u;
  }
  L0054552f: { // 0x54552f: 89153476a500 MOV dword ptr [0xa57634], EDX
    m.w32((0x00a57634u), s.dx);
  }
  L00545535: { // 0x545535: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000713b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004713b0: { // 0x4713b0: a0a885a200 MOV AL, byte ptr [0xa285a8]
    s.ax = with_al(s.ax, m.r8((0x00a285a8u)));
  }
  L004713b5: { // 0x4713b5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004713b6: { // 0x4713b6: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004713b8: { // 0x4713b8: 741d JZ 0x4713d7
    if(integer::condition("JZ",flags)) goto L004713d7;
  }
  L004713ba: { // 0x4713ba: 8bb1e4000000 MOV ESI, dword ptr [ECX + 0xe4]
    s.si = m.r32((s.cx+0x000000e4u));
  }
  L004713c0: { // 0x4713c0: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L004713c2: { // 0x4713c2: 7413 JZ 0x4713d7
    if(integer::condition("JZ",flags)) goto L004713d7;
  }
  L004713c4: { // 0x4713c4: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004713c6: { // 0x4713c6: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004713c8: { // 0x4713c8: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),4658123u); flags=s.arithmetic_flags;
  }
  L004713cb: { // 0x4713cb: 83f806 CMP EAX, 6
    (void)integer::sub(s.ax,6u,32,flags);
  }
  L004713ce: { // 0x4713ce: 740b JZ 0x4713db
    if(integer::condition("JZ",flags)) goto L004713db;
  }
  L004713d0: { // 0x4713d0: 8b7630 MOV ESI, dword ptr [ESI + 0x30]
    s.si = m.r32((s.si+0x00000030u));
  }
  L004713d3: { // 0x4713d3: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L004713d5: { // 0x4713d5: 75ed JNZ 0x4713c4
    if(integer::condition("JNZ",flags)) goto L004713c4;
  }
  L004713d7: { // 0x4713d7: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004713d9: { // 0x4713d9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004713da: { // 0x4713da: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004713db: { // 0x4713db: 8bc6 MOV EAX, ESI
    s.ax = s.si;
  }
  L004713dd: { // 0x4713dd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004713de: { // 0x4713de: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00053890(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00453890: { // 0x453890: b806000000 MOV EAX, 6
    s.ax = 6u;
  }
  L00453895: { // 0x453895: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0005e970(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0045e970: { // 0x45e970: b807000000 MOV EAX, 7
    s.ax = 7u;
  }
  L0045e975: { // 0x45e975: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4556208u:f_000585b0(m,s,child,{});break;
case 4556224u:f_000585c0(m,s,child,{});break;
case 5526784u:f_00145500(m,s,child,{});break;
case 4658096u:f_000713b0(m,s,child,{});break;
case 4536464u:f_00053890(m,s,child,{});break;
case 4581744u:f_0005e970(m,s,child,{});break;
default:throw std::domain_error("recovery756 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00498fb0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00498fb0: { // 0x498fb0: a1e4e0a100 MOV EAX,[0x00a1e0e4]
    s.ax = m.r32((0x00a1e0e4u));
  }
  L00498fb5: { // 0x498fb5: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  L00498fb9: { // 0x498fb9: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  L00498fbc: { // 0x498fbc: 8b5030 MOV EDX,dword ptr [EAX + 0x30]
    s.dx = m.r32((s.ax+0x00000030u));
  }
  L00498fbf: { // 0x498fbf: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00498fc0: { // 0x498fc0: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L00498fc2: { // 0x498fc2: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00498fc3: { // 0x498fc3: 0f8593010000 JNZ 0x0049915c
    if(integer::condition("JNZ",flags)) goto L0049915c;
  }
  L00498fc9: { // 0x498fc9: a05389a200 MOV AL,[0x00a28953]
    s.ax = with_al(s.ax, m.r8((0x00a28953u)));
  }
  L00498fce: { // 0x498fce: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00498fd0: { // 0x498fd0: 0f8586010000 JNZ 0x0049915c
    if(integer::condition("JNZ",flags)) goto L0049915c;
  }
  L00498fd6: { // 0x498fd6: 8b442434 MOV EAX,dword ptr [ESP + 0x34]
    s.ax = m.r32((f.sp+0x00000034u));
  }
  L00498fda: { // 0x498fda: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00498fdc: { // 0x498fdc: 0f847a010000 JZ 0x0049915c
    if(integer::condition("JZ",flags)) goto L0049915c;
  }
  L00498fe2: { // 0x498fe2: 8b7c2438 MOV EDI,dword ptr [ESP + 0x38]
    s.di = m.r32((f.sp+0x00000038u));
  }
  L00498fe6: { // 0x498fe6: 668b17 MOV DX,word ptr [EDI]
    s.dx = with_ax(s.dx, m.r16((s.di)));
  }
  L00498fe9: { // 0x498fe9: 663b1540a98300 CMP DX,word ptr [0x0083a940]
    (void)integer::sub((s.dx & 0xffffu),m.r16((0x0083a940u)),16,flags);
  }
  L00498ff0: { // 0x498ff0: 7511 JNZ 0x00499003
    if(integer::condition("JNZ",flags)) goto L00499003;
  }
  L00498ff2: { // 0x498ff2: 668b4702 MOV AX,word ptr [EDI + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.di+0x00000002u)));
  }
  L00498ff6: { // 0x498ff6: 663b0542a98300 CMP AX,word ptr [0x0083a942]
    (void)integer::sub((s.ax & 0xffffu),m.r16((0x0083a942u)),16,flags);
  }
  L00498ffd: { // 0x498ffd: 0f8459010000 JZ 0x0049915c
    if(integer::condition("JZ",flags)) goto L0049915c;
  }
  L00499003: { // 0x499003: 8b74242c MOV ESI,dword ptr [ESP + 0x2c]
    s.si = m.r32((f.sp+0x0000002cu));
  }
  L00499007: { // 0x499007: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00499009: { // 0x499009: 0f844d010000 JZ 0x0049915c
    if(integer::condition("JZ",flags)) goto L0049915c;
  }
  L0049900f: { // 0x49900f: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00499011: { // 0x499011: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00499013: { // 0x499013: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),4821014u); flags=s.arithmetic_flags;
  }
  L00499016: { // 0x499016: 83f807 CMP EAX,0x7
    (void)integer::sub(s.ax,0x00000007u,32,flags);
  }
  L00499019: { // 0x499019: 0f853d010000 JNZ 0x0049915c
    if(integer::condition("JNZ",flags)) goto L0049915c;
  }
  L0049901f: { // 0x49901f: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00499020: { // 0x499020: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00499021: { // 0x499021: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00499023: { // 0x499023: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00499025: { // 0x499025: e896f5fbff CALL 0x004585c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004585c0u,4821034u); flags=s.arithmetic_flags;
  }
  L0049902a: { // 0x49902a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0049902c: { // 0x49902c: 89442434 MOV dword ptr [ESP + 0x34],EAX
    m.w32((f.sp+0x00000034u), s.ax);
  }
  L00499030: { // 0x499030: e87bf5fbff CALL 0x004585b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004585b0u,4821045u); flags=s.arithmetic_flags;
  }
  L00499035: { // 0x499035: 0fbf2f MOVSX EBP,word ptr [EDI]
    s.bp = std::uint32_t(integer::sign_extend(m.r16((s.di)),16));
  }
  L00499038: { // 0x499038: 0fbf5f02 MOVSX EBX,word ptr [EDI + 0x2]
    s.bx = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L0049903c: { // 0x49903c: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0049903e: { // 0x49903e: 8b86400c0000 MOV EAX,dword ptr [ESI + 0xc40]
    s.ax = m.r32((s.si+0x00000c40u));
  }
  L00499044: { // 0x499044: 8b742434 MOV ESI,dword ptr [ESP + 0x34]
    s.si = m.r32((f.sp+0x00000034u));
  }
  L00499048: { // 0x499048: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00499049: { // 0x499049: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0049904b: { // 0x49904b: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L0049904f: { // 0x49904f: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00499051: { // 0x499051: 8d1442 LEA EDX,[EDX + EAX*0x2]
    s.dx = (s.dx+(s.ax * 0x00000002u));
  }
  L00499054: { // 0x499054: 895c2424 MOV dword ptr [ESP + 0x24],EBX
    m.w32((f.sp+0x00000024u), s.bx);
  }
  L00499058: { // 0x499058: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L0049905a: { // 0x49905a: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L0049905c: { // 0x49905c: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L0049905e: { // 0x49905e: 8d3446 LEA ESI,[ESI + EAX*0x2]
    s.si = (s.si+(s.ax * 0x00000002u));
  }
  L00499061: { // 0x499061: c644243c00 MOV byte ptr [ESP + 0x3c],0x0
    m.w8((f.sp+0x0000003cu), 0x00000000u);
  }
  L00499066: { // 0x499066: 894c2440 MOV dword ptr [ESP + 0x40],ECX
    m.w32((f.sp+0x00000040u), s.cx);
  }
  L0049906a: { // 0x49906a: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L0049906e: { // 0x49906e: 0f8dda000000 JGE 0x0049914e
    if(integer::condition("JGE",flags)) goto L0049914e;
  }
  L00499074: { // 0x499074: 03f3 ADD ESI,EBX
    s.si = integer::add(s.si,s.bx,32,flags);
  }
  L00499076: { // 0x499076: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L0049907a: { // 0x49907a: 3bde CMP EBX,ESI
    (void)integer::sub(s.bx,s.si,32,flags);
  }
  L0049907c: { // 0x49907c: 8bfb MOV EDI,EBX
    s.di = s.bx;
  }
  L0049907e: { // 0x49907e: 0f8db9000000 JGE 0x0049913d
    if(integer::condition("JGE",flags)) goto L0049913d;
  }
  L00499084: { // 0x499084: 0fbf4c2440 MOVSX ECX,word ptr [ESP + 0x40]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000040u)),16));
  }
  L00499089: { // 0x499089: 668b442440 MOV AX,word ptr [ESP + 0x40]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x00000040u)));
  }
  L0049908e: { // 0x49908e: 3bcd CMP ECX,EBP
    (void)integer::sub(s.cx,s.bp,32,flags);
  }
  L00499090: { // 0x499090: 6689442410 MOV word ptr [ESP + 0x10],AX
    m.w16((f.sp+0x00000010u), (s.ax & 0xffffu));
  }
  L00499095: { // 0x499095: 66897c2412 MOV word ptr [ESP + 0x12],DI
    m.w16((f.sp+0x00000012u), (s.di & 0xffffu));
  }
  L0049909a: { // 0x49909a: 0fbfc7 MOVSX EAX,DI
    s.ax = std::uint32_t(integer::sign_extend((s.di & 0xffffu),16));
  }
  L0049909d: { // 0x49909d: 7c1c JL 0x004990bb
    if(integer::condition("JL",flags)) goto L004990bb;
  }
  L0049909f: { // 0x49909f: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L004990a3: { // 0x4990a3: 03d5 ADD EDX,EBP
    s.dx = integer::add(s.dx,s.bp,32,flags);
  }
  L004990a5: { // 0x4990a5: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L004990a7: { // 0x4990a7: 7d12 JGE 0x004990bb
    if(integer::condition("JGE",flags)) goto L004990bb;
  }
  L004990a9: { // 0x4990a9: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L004990ad: { // 0x4990ad: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L004990af: { // 0x4990af: 7c0a JL 0x004990bb
    if(integer::condition("JL",flags)) goto L004990bb;
  }
  L004990b1: { // 0x4990b1: 8b542434 MOV EDX,dword ptr [ESP + 0x34]
    s.dx = m.r32((f.sp+0x00000034u));
  }
  L004990b5: { // 0x4990b5: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L004990b7: { // 0x4990b7: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L004990b9: { // 0x4990b9: 7c71 JL 0x0049912c
    if(integer::condition("JL",flags)) goto L0049912c;
  }
  L004990bb: { // 0x4990bb: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L004990bf: { // 0x4990bf: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L004990c4: { // 0x4990c4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004990c5: { // 0x4990c5: e836c40a00 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4821194u); flags=s.arithmetic_flags;
  }
  L004990ca: { // 0x4990ca: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L004990cc: { // 0x4990cc: e8df82fdff CALL 0x004713b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004713b0u,4821201u); flags=s.arithmetic_flags;
  }
  L004990d1: { // 0x4990d1: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L004990d3: { // 0x4990d3: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L004990d5: { // 0x4990d5: 7455 JZ 0x0049912c
    if(integer::condition("JZ",flags)) goto L0049912c;
  }
  L004990d7: { // 0x4990d7: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L004990dd: { // 0x4990dd: 8b442438 MOV EAX,dword ptr [ESP + 0x38]
    s.ax = m.r32((f.sp+0x00000038u));
  }
  L004990e1: { // 0x4990e1: 394130 CMP dword ptr [ECX + 0x30],EAX
    (void)integer::sub(m.r32((s.cx+0x00000030u)),s.ax,32,flags);
  }
  L004990e4: { // 0x4990e4: 7514 JNZ 0x004990fa
    if(integer::condition("JNZ",flags)) goto L004990fa;
  }
  L004990e6: { // 0x4990e6: 8b9618040000 MOV EDX,dword ptr [ESI + 0x418]
    s.dx = m.r32((s.si+0x00000418u));
  }
  L004990ec: { // 0x4990ec: 80ba0312000000 CMP byte ptr [EDX + 0x1203],0x0
    (void)integer::sub(m.r8((s.dx+0x00001203u)),0x00000000u,8,flags);
  }
  L004990f3: { // 0x4990f3: 7405 JZ 0x004990fa
    if(integer::condition("JZ",flags)) goto L004990fa;
  }
  L004990f5: { // 0x4990f5: c644243c01 MOV byte ptr [ESP + 0x3c],0x1
    m.w8((f.sp+0x0000003cu), 0x00000001u);
  }
  L004990fa: { // 0x4990fa: 8a15f455a200 MOV DL,byte ptr [0x00a255f4]
    s.dx = with_al(s.dx, m.r8((0x00a255f4u)));
  }
  L00499100: { // 0x499100: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L00499102: { // 0x499102: 7428 JZ 0x0049912c
    if(integer::condition("JZ",flags)) goto L0049912c;
  }
  L00499104: { // 0x499104: 8b15cca5a100 MOV EDX,dword ptr [0x00a1a5cc]
    s.dx = m.r32((0x00a1a5ccu));
  }
  L0049910a: { // 0x49910a: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L0049910d: { // 0x49910d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049910e: { // 0x49910e: e8cdba0400 CALL 0x004e4be0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e4be0u,4821267u); flags=s.arithmetic_flags;
  }
  L00499113: { // 0x499113: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00499115: { // 0x499115: 7415 JZ 0x0049912c
    if(integer::condition("JZ",flags)) goto L0049912c;
  }
  L00499117: { // 0x499117: 8b8e18040000 MOV ECX,dword ptr [ESI + 0x418]
    s.cx = m.r32((s.si+0x00000418u));
  }
  L0049911d: { // 0x49911d: 8a8104120000 MOV AL,byte ptr [ECX + 0x1204]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00001204u)));
  }
  L00499123: { // 0x499123: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00499125: { // 0x499125: 7405 JZ 0x0049912c
    if(integer::condition("JZ",flags)) goto L0049912c;
  }
  L00499127: { // 0x499127: c644243c01 MOV byte ptr [ESP + 0x3c],0x1
    m.w8((f.sp+0x0000003cu), 0x00000001u);
  }
  L0049912c: { // 0x49912c: 8b742418 MOV ESI,dword ptr [ESP + 0x18]
    s.si = m.r32((f.sp+0x00000018u));
  }
  L00499130: { // 0x499130: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L00499131: { // 0x499131: 3bfe CMP EDI,ESI
    (void)integer::sub(s.di,s.si,32,flags);
  }
  L00499133: { // 0x499133: 0f8c4bffffff JL 0x00499084
    if(integer::condition("JL",flags)) goto L00499084;
  }
  L00499139: { // 0x499139: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L0049913d: { // 0x49913d: 8b442440 MOV EAX,dword ptr [ESP + 0x40]
    s.ax = m.r32((f.sp+0x00000040u));
  }
  L00499141: { // 0x499141: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00499142: { // 0x499142: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00499144: { // 0x499144: 89442440 MOV dword ptr [ESP + 0x40],EAX
    m.w32((f.sp+0x00000040u), s.ax);
  }
  L00499148: { // 0x499148: 0f8c2cffffff JL 0x0049907a
    if(integer::condition("JL",flags)) goto L0049907a;
  }
  L0049914e: { // 0x49914e: 8a44243c MOV AL,byte ptr [ESP + 0x3c]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000003cu)));
  }
  L00499152: { // 0x499152: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00499153: { // 0x499153: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00499154: { // 0x499154: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00499155: { // 0x499155: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00499156: { // 0x499156: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L00499159: { // 0x499159: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0049915c: { // 0x49915c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0049915d: { // 0x49915d: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0049915f: { // 0x49915f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00499160: { // 0x499160: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L00499163: { // 0x499163: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
