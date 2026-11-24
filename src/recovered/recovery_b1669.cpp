#include "recovered/recovery_b1669.hpp"
#include <cstring>
#include <limits>
namespace ra2::recovered::b1669 {namespace {using namespace floating_b61;namespace integer=direct_b33::integer;using recovery_b566::finish;using recovery_b566::string_instruction;using recovery_b566::Kind;using recovery_b566::Repeat;
void invoke(Memory&,State&,Frame&,unsigned,unsigned,const Operations&);
void f_0007b880(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_00054050(Memory&,State&,Frame&,const Operations&);
void f_000544d0(Memory&,State&,Frame&,const Operations&);
void f_0007b880(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x47b880: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  { // 0x47b885: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  { // 0x47b888: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  { // 0x47b88a: f6c610 TEST DH,0x10
    (void)integer::logical((((s.dx >> 8) & 0xffu))&(0x00000010u),8,flags);
  }
  { // 0x47b88d: 0f845d010000 JZ 0x0047b9f0
    if(integer::condition("JZ",flags)) goto L0047b9f0;
  }
  { // 0x47b893: 8b4924 MOV ECX,dword ptr [ECX + 0x24]
    s.cx = m.r32((s.cx+0x00000024u));
  }
  { // 0x47b896: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x47b897: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x47b898: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x47b899: be01000000 MOV ESI,0x1
    s.si = 0x00000001u;
  }
  { // 0x47b89e: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x47b89f: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  { // 0x47b8a3: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  { // 0x47b8a7: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0047b8a9: { // 0x47b8a9: 8d542410 LEA EDX,[ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  { // 0x47b8ad: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x47b8b2: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x47b8b3: e8489c0c00 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4700344u,op); flags=s.arithmetic_flags;
  }
  { // 0x47b8b8: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  { // 0x47b8ba: 8d4efe LEA ECX,[ESI + -0x2]
    s.cx = (s.si-0x00000002u);
  }
  { // 0x47b8bd: 0fbe851b010000 MOVSX EAX,byte ptr [EBP + 0x11b]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.bp+0x0000011bu)),8));
  }
  { // 0x47b8c4: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x47b8c6: 0f8c02010000 JL 0x0047b9ce
    if(integer::condition("JL",flags)) goto L0047b9ce;
  }
  { // 0x47b8cc: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  { // 0x47b8ce: 0f8ffa000000 JG 0x0047b9ce
    if(integer::condition("JG",flags)) goto L0047b9ce;
  }
  { // 0x47b8d4: 8b8540010000 MOV EAX,dword ptr [EBP + 0x140]
    s.ax = m.r32((s.bp+0x00000140u));
  }
  { // 0x47b8da: be00004000 MOV ESI,0x400000
    s.si = 0x00400000u;
  }
  { // 0x47b8df: 85c6 TEST ESI,EAX
    (void)integer::logical((s.si)&(s.ax),32,flags);
  }
  { // 0x47b8e1: 0f85e7000000 JNZ 0x0047b9ce
    if(integer::condition("JNZ",flags)) goto L0047b9ce;
  }
  { // 0x47b8e7: 6a18 PUSH 0x18
    f.push(m,0x00000018u);
  }
  { // 0x47b8e9: e869202f00 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,4700398u,op); flags=s.arithmetic_flags;
  }
  { // 0x47b8ee: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x47b8f1: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x47b8f3: 7421 JZ 0x0047b916
    if(integer::condition("JZ",flags)) goto L0047b916;
  }
  { // 0x47b8f5: 895804 MOV dword ptr [EAX + 0x4],EBX
    m.w32((s.ax+0x00000004u), s.bx);
  }
  { // 0x47b8f8: 895808 MOV dword ptr [EAX + 0x8],EBX
    m.w32((s.ax+0x00000008u), s.bx);
  }
  { // 0x47b8fb: c6400c01 MOV byte ptr [EAX + 0xc],0x1
    m.w8((s.ax+0x0000000cu), 0x00000001u);
  }
  { // 0x47b8ff: 88580d MOV byte ptr [EAX + 0xd],BL
    m.w8((s.ax+0x0000000du), (s.bx & 0xffu));
  }
  { // 0x47b902: c7007c817800 MOV dword ptr [EAX],0x78817c
    m.w32((s.ax), 0x0078817cu);
  }
  { // 0x47b908: c740140a000000 MOV dword ptr [EAX + 0x14],0xa
    m.w32((s.ax+0x00000014u), 0x0000000au);
  }
  { // 0x47b90f: 895810 MOV dword ptr [EAX + 0x10],EBX
    m.w32((s.ax+0x00000010u), s.bx);
  }
  { // 0x47b912: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x47b914: eb02 JMP 0x0047b918
    goto L0047b918;
  }
  L0047b916: { // 0x47b916: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0047b918: { // 0x47b918: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  { // 0x47b91a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x47b91b: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x47b91d: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x47b91f: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),4700450u,op); flags=s.arithmetic_flags;
  }
  { // 0x47b922: c7471401000000 MOV dword ptr [EDI + 0x14],0x1
    m.w32((s.di+0x00000014u), 0x00000001u);
  }
  { // 0x47b929: 8b8d40010000 MOV ECX,dword ptr [EBP + 0x140]
    s.cx = m.r32((s.bp+0x00000140u));
  }
  { // 0x47b92f: 0bce OR ECX,ESI
    s.cx = integer::logical((s.cx)|(s.si),32,flags);
  }
  { // 0x47b931: 8bb5e4000000 MOV ESI,dword ptr [EBP + 0xe4]
    s.si = m.r32((s.bp+0x000000e4u));
  }
  { // 0x47b937: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  { // 0x47b939: 898d40010000 MOV dword ptr [EBP + 0x140],ECX
    m.w32((s.bp+0x00000140u), s.cx);
  }
  { // 0x47b93f: 7477 JZ 0x0047b9b8
    if(integer::condition("JZ",flags)) goto L0047b9b8;
  }
  L0047b941: { // 0x47b941: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x47b944: 8d4604 LEA EAX,[ESI + 0x4]
    s.ax = (s.si+0x00000004u);
  }
  { // 0x47b947: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x47b948: ff510c CALL dword ptr [ECX + 0xc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+0x0000000cu)),4700491u,op); flags=s.arithmetic_flags;
  }
  { // 0x47b94b: 83f806 CMP EAX,0x6
    (void)integer::sub(s.ax,0x00000006u,32,flags);
  }
  { // 0x47b94e: 7548 JNZ 0x0047b998
    if(integer::condition("JNZ",flags)) goto L0047b998;
  }
  { // 0x47b950: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x47b952: 8d44241c LEA EAX,[ESP + 0x1c]
    s.ax = (f.sp+0x0000001cu);
  }
  { // 0x47b956: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x47b957: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x47b959: ff92a0010000 CALL dword ptr [EDX + 0x1a0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001a0u)),4700511u,op); flags=s.arithmetic_flags;
  }
  { // 0x47b95f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x47b961: e8ea6efdff CALL 0x00452850
    s.arithmetic_flags=flags; invoke(m,s,f,0x00452850u,4700518u,op); flags=s.arithmetic_flags;
  }
  { // 0x47b966: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x47b968: 7447 JZ 0x0047b9b1
    if(integer::condition("JZ",flags)) goto L0047b9b1;
  }
  { // 0x47b96a: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x47b96c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x47b96e: ff527c CALL dword ptr [EDX + 0x7c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000007cu)),4700529u,op); flags=s.arithmetic_flags;
  }
  { // 0x47b971: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x47b973: 750f JNZ 0x0047b984
    if(integer::condition("JNZ",flags)) goto L0047b984;
  }
  { // 0x47b975: 8a86bd050000 MOV AL,byte ptr [ESI + 0x5bd]
    s.ax = with_al(s.ax, m.r8((s.si+0x000005bdu)));
  }
  { // 0x47b97b: c644241401 MOV byte ptr [ESP + 0x14],0x1
    m.w8((f.sp+0x00000014u), 0x00000001u);
  }
  { // 0x47b980: 3c0f CMP AL,0xf
    (void)integer::sub((s.ax & 0xffu),0x0000000fu,8,flags);
  }
  { // 0x47b982: 7504 JNZ 0x0047b988
    if(integer::condition("JNZ",flags)) goto L0047b988;
  }
  L0047b984: { // 0x47b984: 885c2414 MOV byte ptr [ESP + 0x14],BL
    m.w8((f.sp+0x00000014u), (s.bx & 0xffu));
  }
  L0047b988: { // 0x47b988: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  { // 0x47b98c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x47b98e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x47b98f: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x47b990: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x47b991: e84a6ffdff CALL 0x004528e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004528e0u,4700566u,op); flags=s.arithmetic_flags;
  }
  { // 0x47b996: eb19 JMP 0x0047b9b1
    goto L0047b9b1;
  }
  L0047b998: { // 0x47b998: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  { // 0x47b99b: 740a JZ 0x0047b9a7
    if(integer::condition("JZ",flags)) goto L0047b9a7;
  }
  { // 0x47b99d: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  { // 0x47b9a0: 7405 JZ 0x0047b9a7
    if(integer::condition("JZ",flags)) goto L0047b9a7;
  }
  { // 0x47b9a2: 83f80f CMP EAX,0xf
    (void)integer::sub(s.ax,0x0000000fu,32,flags);
  }
  { // 0x47b9a5: 750a JNZ 0x0047b9b1
    if(integer::condition("JNZ",flags)) goto L0047b9b1;
  }
  L0047b9a7: { // 0x47b9a7: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x47b9a9: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x47b9ab: ff9244010000 CALL dword ptr [EDX + 0x144]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000144u)),4700593u,op); flags=s.arithmetic_flags;
  }
  L0047b9b1: { // 0x47b9b1: 8b7630 MOV ESI,dword ptr [ESI + 0x30]
    s.si = m.r32((s.si+0x00000030u));
  }
  { // 0x47b9b4: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  { // 0x47b9b6: 7589 JNZ 0x0047b941
    if(integer::condition("JNZ",flags)) goto L0047b941;
  }
  L0047b9b8: { // 0x47b9b8: 395f10 CMP dword ptr [EDI + 0x10],EBX
    (void)integer::sub(m.r32((s.di+0x00000010u)),s.bx,32,flags);
  }
  { // 0x47b9bb: 7e05 JLE 0x0047b9c2
    if(integer::condition("JLE",flags)) goto L0047b9c2;
  }
  { // 0x47b9bd: 897d28 MOV dword ptr [EBP + 0x28],EDI
    m.w32((s.bp+0x00000028u), s.di);
  }
  { // 0x47b9c0: eb0c JMP 0x0047b9ce
    goto L0047b9ce;
  }
  L0047b9c2: { // 0x47b9c2: 3bfb CMP EDI,EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  { // 0x47b9c4: 7408 JZ 0x0047b9ce
    if(integer::condition("JZ",flags)) goto L0047b9ce;
  }
  { // 0x47b9c6: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x47b9c8: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x47b9ca: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x47b9cc: ff10 CALL dword ptr [EAX]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax)),4700622u,op); flags=s.arithmetic_flags;
  }
  L0047b9ce: { // 0x47b9ce: 8b742418 MOV ESI,dword ptr [ESP + 0x18]
    s.si = m.r32((f.sp+0x00000018u));
  }
  { // 0x47b9d2: 66ff442410 INC word ptr [ESP + 0x10]
    m.w16((f.sp+0x00000010u), integer::increment(m.r16((f.sp+0x00000010u)),16,flags));
  }
  { // 0x47b9d7: 66ff442412 INC word ptr [ESP + 0x12]
    m.w16((f.sp+0x00000012u), integer::increment(m.r16((f.sp+0x00000012u)),16,flags));
  }
  { // 0x47b9dc: 83c602 ADD ESI,0x2
    s.si = integer::add(s.si,0x00000002u,32,flags);
  }
  { // 0x47b9df: 83fe0f CMP ESI,0xf
    (void)integer::sub(s.si,0x0000000fu,32,flags);
  }
  { // 0x47b9e2: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  { // 0x47b9e6: 0f8ebdfeffff JLE 0x0047b8a9
    if(integer::condition("JLE",flags)) goto L0047b8a9;
  }
  { // 0x47b9ec: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x47b9ed: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x47b9ee: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x47b9ef: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0047b9f0: { // 0x47b9f0: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x47b9f3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00145500(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x545500: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  { // 0x545504: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x545505: 0fbf4202 MOVSX EAX,word ptr [EDX + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.dx+0x00000002u)),16));
  }
  { // 0x545509: 0fbf32 MOVSX ESI,word ptr [EDX]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.dx)),16));
  }
  { // 0x54550c: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  { // 0x54550f: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  { // 0x545511: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x545512: 7814 JS 0x00545528
    if(integer::condition("JS",flags)) goto L00545528;
  }
  { // 0x545514: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  { // 0x545519: 7d0d JGE 0x00545528
    if(integer::condition("JGE",flags)) goto L00545528;
  }
  { // 0x54551b: 8b8938010000 MOV ECX,dword ptr [ECX + 0x138]
    s.cx = m.r32((s.cx+0x00000138u));
  }
  { // 0x545521: 8b0481 MOV EAX,dword ptr [ECX + EAX*0x4]
    s.ax = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  { // 0x545524: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x545526: 750d JNZ 0x00545535
    if(integer::condition("JNZ",flags)) goto L00545535;
  }
  L00545528: { // 0x545528: 8b12 MOV EDX,dword ptr [EDX]
    s.dx = m.r32((s.dx));
  }
  { // 0x54552a: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  { // 0x54552f: 89153476a500 MOV dword ptr [0x00a57634],EDX
    m.w32((0x00a57634u), s.dx);
  }
  L00545535: { // 0x545535: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00054050(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x454050: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x454051: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x454052: 8b6c240c MOV EBP,dword ptr [ESP + 0xc]
    s.bp = m.r32((f.sp+0x0000000cu));
  }
  { // 0x454056: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x454057: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  { // 0x454059: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x45405a: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x45405c: 747c JZ 0x004540da
    if(integer::condition("JZ",flags)) goto L004540da;
  }
  { // 0x45405e: 8b5c2418 MOV EBX,dword ptr [ESP + 0x18]
    s.bx = m.r32((f.sp+0x00000018u));
  }
  { // 0x454062: c6460c00 MOV byte ptr [ESI + 0xc],0x0
    m.w8((s.si+0x0000000cu), 0x00000000u);
  }
  { // 0x454066: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x454068: 7514 JNZ 0x0045407e
    if(integer::condition("JNZ",flags)) goto L0045407e;
  }
  { // 0x45406a: 8d04ad00000000 LEA EAX,[EBP*0x4 + 0x0]
    s.ax = ((s.bp * 0x00000004u)+0x00000000u);
  }
  { // 0x454071: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x454072: e8e0983100 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,4538487u,op); flags=s.arithmetic_flags;
  }
  { // 0x454077: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x45407a: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x45407c: eb02 JMP 0x00454080
    goto L00454080;
  }
  L0045407e: { // 0x45407e: 8bfb MOV EDI,EBX
    s.di = s.bx;
  }
  L00454080: { // 0x454080: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x454082: c6460c01 MOV byte ptr [ESI + 0xc],0x1
    m.w8((s.si+0x0000000cu), 0x00000001u);
  }
  { // 0x454086: 746f JZ 0x004540f7
    if(integer::condition("JZ",flags)) goto L004540f7;
  }
  { // 0x454088: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x45408b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x45408d: 7439 JZ 0x004540c8
    if(integer::condition("JZ",flags)) goto L004540c8;
  }
  { // 0x45408f: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x454092: 3be9 CMP EBP,ECX
    (void)integer::sub(s.bp,s.cx,32,flags);
  }
  { // 0x454094: 7d02 JGE 0x00454098
    if(integer::condition("JGE",flags)) goto L00454098;
  }
  { // 0x454096: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00454098: { // 0x454098: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x45409a: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x45409c: 7e10 JLE 0x004540ae
    if(integer::condition("JLE",flags)) goto L004540ae;
  }
  L0045409e: { // 0x45409e: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  { // 0x4540a1: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x4540a2: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x4540a4: 8b5482fc MOV EDX,dword ptr [EDX + EAX*0x4 + -0x4]
    s.dx = m.r32((s.dx+(s.ax * 0x00000004u)-0x00000004u));
  }
  { // 0x4540a8: 895487fc MOV dword ptr [EDI + EAX*0x4 + -0x4],EDX
    m.w32((s.di+(s.ax * 0x00000004u)-0x00000004u), s.dx);
  }
  { // 0x4540ac: 7cf0 JL 0x0045409e
    if(integer::condition("JL",flags)) goto L0045409e;
  }
  L004540ae: { // 0x4540ae: 8a460d MOV AL,byte ptr [ESI + 0xd]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000000du)));
  }
  { // 0x4540b1: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4540b3: 7413 JZ 0x004540c8
    if(integer::condition("JZ",flags)) goto L004540c8;
  }
  { // 0x4540b5: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x4540b8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4540b9: e8bd953100 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,4538558u,op); flags=s.arithmetic_flags;
  }
  { // 0x4540be: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x4540c1: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  L004540c8: { // 0x4540c8: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4540ca: 897e04 MOV dword ptr [ESI + 0x4],EDI
    m.w32((s.si+0x00000004u), s.di);
  }
  { // 0x4540cd: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x4540cf: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  { // 0x4540d2: 896e08 MOV dword ptr [ESI + 0x8],EBP
    m.w32((s.si+0x00000008u), s.bp);
  }
  { // 0x4540d5: 88460d MOV byte ptr [ESI + 0xd],AL
    m.w8((s.si+0x0000000du), (s.ax & 0xffu));
  }
  { // 0x4540d8: eb07 JMP 0x004540e1
    goto L004540e1;
  }
  L004540da: { // 0x4540da: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x4540dc: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4540de: ff520c CALL dword ptr [EDX + 0xc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000000cu)),4538593u,op); flags=s.arithmetic_flags;
  }
  L004540e1: { // 0x4540e1: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  { // 0x4540e4: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    s.cx = m.r32((s.si+0x00000010u));
  }
  { // 0x4540e7: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x4540e9: 7d03 JGE 0x004540ee
    if(integer::condition("JGE",flags)) goto L004540ee;
  }
  { // 0x4540eb: 894610 MOV dword ptr [ESI + 0x10],EAX
    m.w32((s.si+0x00000010u), s.ax);
  }
  L004540ee: { // 0x4540ee: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4540ef: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4540f0: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x4540f1: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x4540f3: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4540f4: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L004540f7: { // 0x4540f7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4540f8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4540f9: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x4540fa: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x4540fc: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4540fd: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_000544d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4544d0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4544d1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4544d3: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x4544d6: c7069c817800 MOV dword ptr [ESI],0x78819c
    m.w32((s.si), 0x0078819cu);
  }
  { // 0x4544dc: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4544de: 7417 JZ 0x004544f7
    if(integer::condition("JZ",flags)) goto L004544f7;
  }
  { // 0x4544e0: 8a4e0d MOV CL,byte ptr [ESI + 0xd]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000000du)));
  }
  { // 0x4544e3: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x4544e5: 7410 JZ 0x004544f7
    if(integer::condition("JZ",flags)) goto L004544f7;
  }
  { // 0x4544e7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4544e8: e88e913100 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,4539629u,op); flags=s.arithmetic_flags;
  }
  { // 0x4544ed: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x4544f0: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  L004544f7: { // 0x4544f7: 8a442408 MOV AL,byte ptr [ESP + 0x8]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000008u)));
  }
  { // 0x4544fb: c6460d00 MOV byte ptr [ESI + 0xd],0x0
    m.w8((s.si+0x0000000du), 0x00000000u);
  }
  { // 0x4544ff: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x454501: c7460800000000 MOV dword ptr [ESI + 0x8],0x0
    m.w32((s.si+0x00000008u), 0x00000000u);
  }
  { // 0x454508: 7409 JZ 0x00454513
    if(integer::condition("JZ",flags)) goto L00454513;
  }
  { // 0x45450a: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x45450b: e86b913100 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,4539664u,op); flags=s.arithmetic_flags;
  }
  { // 0x454510: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00454513: { // 0x454513: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x454515: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x454516: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void invoke(Memory&m,State&s,Frame&f,unsigned target,unsigned continuation,const Operations&op){f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
if(target==0x76d957){if(!op.heap_context||!op.allocate)throw std::domain_error("genuine ordinary allocator required");s.ax=op.allocate(op.heap_context,m,m.r32(child.entry_sp+4),s.fp);finish(m,s,child,0);f.sp=child.sp;return;}
if(target==0x76d67b){if(!op.heap_context||!op.release)throw std::domain_error("genuine ordinary release required");s.ax=op.release(op.heap_context,m,m.r32(child.entry_sp+4),s.fp);finish(m,s,child,0);f.sp=child.sp;return;}
switch(target){case 0x47b880:f_0007b880(m,s,child,op);break;
case 0x545500:f_00145500(m,s,child,op);break;
case 0x454050:f_00054050(m,s,child,op);break;
case 0x4544d0:f_000544d0(m,s,child,op);break;
default:throw std::domain_error("B1669 unselected authentic target");}f.sp=child.sp;}
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
}
Result run(Memory&world,unsigned entry,unsigned char*storage,unsigned size,const NativeState&in,const fp::Image&incoming,const Operations&op){
need(storage&&size==0x8044&&!(entry&7u)&&std::uint64_t(reinterpret_cast<std::uintptr_t>(storage))+0x8000==entry,"actual owned32KB+68 frame");need(op.heap_context&&op.allocate&&op.release,"actual ordinaryheap provider");
std::array<unsigned,16>before;unsigned ret;std::memcpy(before.data(),storage+0x8004,64);std::memcpy(&ret,storage+0x8000,4);constexpr unsigned B=0x18000000,owner=B+0x1000,cells=B+0x10000,table=B+0x40000;
need(in.cx==owner&&!(in.flags&0x400)&&incoming.word(8)==0xffff&&!(incoming.word(4)&~0x3800),"finite owner DF TOP emptytags");need(std::uint64_t(entry)+68<=B||std::uint64_t(entry)-0x8000>=B+0x140000,"private public disjoint");Memory m=world;leaf::Memory local(storage,entry-0x8000,size);m.add(local);
need(m.r32(0xa255c0)==B+0x2000&&(m.r32(B+0x2000)&0x1000)&&m.r32(0x81a958)==table,"positive flags and owned map");unsigned coord=m.r32(owner+0x24),x=coord&65535,y=coord>>16;need(x>=10&&x<=25&&y==x+10,"finite diagonal coordinate");
for(unsigned k=0;k<8;++k){unsigned cell=cells+0x200*k;need(m.r32(table+4*((y+k)*512+x+k))==cell&&m.r8(cell+0x11b)==2*k&&!(m.r32(cell+0x140)&0x400000)&&m.r32(cell+0xe4)==0,"eight distinct positive cells");}
need(m.r32(0x78817c)==0x4544d0&&m.r32(0x788184)==0x454050,"normal authentic vptr bindings");
State s{};s.ax=in.ax;s.cx=in.cx;s.dx=in.dx;s.bx=in.bx;s.bp=in.bp;s.si=in.si;s.di=in.di;s.arithmetic_flags=in.flags;s.fp.image=incoming;Frame f{entry,entry,ret};f_0007b880(m,s,f,op);need(f.sp==entry+4&&s.bx==in.bx&&s.bp==in.bp&&s.si==in.si&&s.di==in.di&&!(s.arithmetic_flags&0x400),"RET0 nonvol DF");Result out{s.ax,s,{}};std::memcpy(out.words.data(),storage+0x8004,64);need(out.words==before,"all16 unchanged");return out;
}
}
