#include "recovered/recovery_b210_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b210 {
namespace {
void f_002a0410(Memory&,State&,Frame&,const Operations&);
void f_00165310(Memory&,State&,Frame&,const Operations&);
void f_00229f70(Memory&,State&,Frame&,const Operations&);
void f_00071260(Memory&,State&,Frame&,const Operations&);
void f_0007b650(Memory&,State&,Frame&,const Operations&);
void f_00157280(Memory&,State&,Frame&,const Operations&);
void f_000702c0(Memory&,State&,Frame&,const Operations&);
void f_0029e380(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_002a0410(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006a0410: { // 0x6a0410: a12ca88100 MOV EAX,[0x0081a82c]
    s.ax = m.r32((0x0081a82cu));
  }
  L006a0415: { // 0x6a0415: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L006a0418: { // 0x6a0418: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006a041a: { // 0x6a041a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006a041b: { // 0x6a041b: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006a041c: { // 0x6a041c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006a041d: { // 0x6a041d: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L006a041f: { // 0x6a041f: 0f858a010000 JNZ 0x006a05af
    if(integer::condition("JNZ",flags)) goto L006a05af;
  }
  L006a0425: { // 0x6a0425: 8b7c241c MOV EDI,dword ptr [ESP + 0x1c]
    s.di = m.r32((f.sp+0x0000001cu));
  }
  L006a0429: { // 0x6a0429: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  L006a042e: { // 0x6a042e: 39475c CMP dword ptr [EDI + 0x5c],EAX
    (void)integer::sub(m.r32((s.di+0x0000005cu)),s.ax,32,flags);
  }
  L006a0431: { // 0x6a0431: 0f8478010000 JZ 0x006a05af
    if(integer::condition("JZ",flags)) goto L006a05af;
  }
  L006a0437: { // 0x6a0437: f6872c01000008 TEST byte ptr [EDI + 0x12c],0x8
    (void)integer::logical((m.r8((s.di+0x0000012cu)))&(0x00000008u),8,flags);
  }
  L006a043e: { // 0x6a043e: 750e JNZ 0x006a044e
    if(integer::condition("JNZ",flags)) goto L006a044e;
  }
  L006a0440: { // 0x6a0440: 8a8f38010000 MOV CL,byte ptr [EDI + 0x138]
    s.cx = with_al(s.cx, m.r8((s.di+0x00000138u)));
  }
  L006a0446: { // 0x6a0446: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006a0448: { // 0x6a0448: 0f8461010000 JZ 0x006a05af
    if(integer::condition("JZ",flags)) goto L006a05af;
  }
  L006a044e: { // 0x6a044e: 89475c MOV dword ptr [EDI + 0x5c],EAX
    m.w32((s.di+0x0000005cu), s.ax);
  }
  L006a0451: { // 0x6a0451: 8d44240c LEA EAX,[ESP + 0xc]
    s.ax = (f.sp+0x0000000cu);
  }
  L006a0455: { // 0x6a0455: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006a0456: { // 0x6a0456: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006a0457: { // 0x6a0457: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006a0459: { // 0x6a0459: e80255ddff CALL 0x00475960
    s.arithmetic_flags=flags; invoke(m,s,f,0x00475960u,6947934u); flags=s.arithmetic_flags;
  }
  L006a045e: { // 0x6a045e: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L006a0460: { // 0x6a0460: 8b7004 MOV ESI,dword ptr [EAX + 0x4]
    s.si = m.r32((s.ax+0x00000004u));
  }
  L006a0463: { // 0x6a0463: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L006a0466: { // 0x6a0466: 8b872c010000 MOV EAX,dword ptr [EDI + 0x12c]
    s.ax = m.r32((s.di+0x0000012cu));
  }
  L006a046c: { // 0x6a046c: a808 TEST AL,0x8
    (void)integer::logical(((s.ax & 0xffu))&(0x00000008u),8,flags);
  }
  L006a046e: { // 0x6a046e: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L006a0472: { // 0x6a0472: 744b JZ 0x006a04bf
    if(integer::condition("JZ",flags)) goto L006a04bf;
  }
  L006a0474: { // 0x6a0474: a810 TEST AL,0x10
    (void)integer::logical(((s.ax & 0xffu))&(0x00000010u),8,flags);
  }
  L006a0476: { // 0x6a0476: 7447 JZ 0x006a04bf
    if(integer::condition("JZ",flags)) goto L006a04bf;
  }
  L006a0478: { // 0x6a0478: 8d0449 LEA EAX,[ECX + ECX*0x2]
    s.ax = (s.cx+(s.cx * 0x00000002u));
  }
  L006a047b: { // 0x6a047b: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L006a047e: { // 0x6a047e: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L006a0481: { // 0x6a0481: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006a0482: { // 0x6a0482: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006a0484: { // 0x6a0484: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L006a0486: { // 0x6a0486: 8d0449 LEA EAX,[ECX + ECX*0x2]
    s.ax = (s.cx+(s.cx * 0x00000002u));
  }
  L006a0489: { // 0x6a0489: d1ff SAR EDI,0x1
    s.di = integer::shift(s.di,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L006a048b: { // 0x6a048b: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L006a048e: { // 0x6a048e: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
  L006a0490: { // 0x6a0490: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006a0491: { // 0x6a0491: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006a0493: { // 0x6a0493: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006a0495: { // 0x6a0495: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L006a0497: { // 0x6a0497: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L006a049a: { // 0x6a049a: 2bc6 SUB EAX,ESI
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L006a049c: { // 0x6a049c: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L006a049e: { // 0x6a049e: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L006a04a1: { // 0x6a04a1: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006a04a2: { // 0x6a04a2: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006a04a4: { // 0x6a04a4: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L006a04a6: { // 0x6a04a6: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L006a04a8: { // 0x6a04a8: 8d0476 LEA EAX,[ESI + ESI*0x2]
    s.ax = (s.si+(s.si * 0x00000002u));
  }
  L006a04ab: { // 0x6a04ab: d1f9 SAR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L006a04ad: { // 0x6a04ad: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L006a04b0: { // 0x6a04b0: 897c2410 MOV dword ptr [ESP + 0x10],EDI
    m.w32((f.sp+0x00000010u), s.di);
  }
  L006a04b4: { // 0x6a04b4: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
  L006a04b6: { // 0x6a04b6: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006a04b7: { // 0x6a04b7: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006a04b9: { // 0x6a04b9: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L006a04bb: { // 0x6a04bb: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L006a04bd: { // 0x6a04bd: eb45 JMP 0x006a0504
    goto L006a0504;
  }
  L006a04bf: { // 0x6a04bf: 8d0449 LEA EAX,[ECX + ECX*0x2]
    s.ax = (s.cx+(s.cx * 0x00000002u));
  }
  L006a04c2: { // 0x6a04c2: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L006a04c5: { // 0x6a04c5: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L006a04c8: { // 0x6a04c8: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006a04c9: { // 0x6a04c9: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006a04cb: { // 0x6a04cb: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L006a04cd: { // 0x6a04cd: 8d0449 LEA EAX,[ECX + ECX*0x2]
    s.ax = (s.cx+(s.cx * 0x00000002u));
  }
  L006a04d0: { // 0x6a04d0: d1ff SAR EDI,0x1
    s.di = integer::shift(s.di,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L006a04d2: { // 0x6a04d2: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L006a04d5: { // 0x6a04d5: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
  L006a04d7: { // 0x6a04d7: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006a04d8: { // 0x6a04d8: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006a04da: { // 0x6a04da: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006a04dc: { // 0x6a04dc: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L006a04de: { // 0x6a04de: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L006a04e1: { // 0x6a04e1: 2bc6 SUB EAX,ESI
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L006a04e3: { // 0x6a04e3: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L006a04e5: { // 0x6a04e5: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L006a04e8: { // 0x6a04e8: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006a04e9: { // 0x6a04e9: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006a04eb: { // 0x6a04eb: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L006a04ed: { // 0x6a04ed: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L006a04ef: { // 0x6a04ef: 8d0476 LEA EAX,[ESI + ESI*0x2]
    s.ax = (s.si+(s.si * 0x00000002u));
  }
  L006a04f2: { // 0x6a04f2: d1f9 SAR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L006a04f4: { // 0x6a04f4: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L006a04f7: { // 0x6a04f7: 897c2410 MOV dword ptr [ESP + 0x10],EDI
    m.w32((f.sp+0x00000010u), s.di);
  }
  L006a04fb: { // 0x6a04fb: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
  L006a04fd: { // 0x6a04fd: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006a04fe: { // 0x6a04fe: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006a0500: { // 0x6a0500: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L006a0502: { // 0x6a0502: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L006a0504: { // 0x6a0504: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L006a0506: { // 0x6a0506: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L006a0508: { // 0x6a0508: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006a0509: { // 0x6a0509: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L006a050f: { // 0x6a050f: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L006a0511: { // 0x6a0511: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L006a0513: { // 0x6a0513: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L006a0515: { // 0x6a0515: c1fe08 SAR ESI,0x8
    s.si = integer::shift(s.si,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L006a0518: { // 0x6a0518: e8937affff CALL 0x00697fb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00697fb0u,6948125u); flags=s.arithmetic_flags;
  }
  L006a051d: { // 0x6a051d: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006a051f: { // 0x6a051f: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L006a0521: { // 0x6a0521: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006a0522: { // 0x6a0522: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L006a0528: { // 0x6a0528: 89742410 MOV dword ptr [ESP + 0x10],ESI
    m.w32((f.sp+0x00000010u), s.si);
  }
  L006a052c: { // 0x6a052c: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L006a052e: { // 0x6a052e: 8b93b4000000 MOV EDX,dword ptr [EBX + 0xb4]
    s.dx = m.r32((s.bx+0x000000b4u));
  }
  L006a0534: { // 0x6a0534: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L006a0537: { // 0x6a0537: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L006a0539: { // 0x6a0539: 8b8bb0000000 MOV ECX,dword ptr [EBX + 0xb0]
    s.cx = m.r32((s.bx+0x000000b0u));
  }
  L006a053f: { // 0x6a053f: 2bf1 SUB ESI,ECX
    s.si = integer::sub(s.si,s.cx,32,flags);
  }
  L006a0541: { // 0x6a0541: 8b0d70198200 MOV ECX,dword ptr [0x00821970]
    s.cx = m.r32((0x00821970u));
  }
  L006a0547: { // 0x6a0547: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006a0549: { // 0x6a0549: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006a054a: { // 0x6a054a: 8d51e2 LEA EDX,[ECX + -0x1e]
    s.dx = (s.cx-0x0000001eu);
  }
  L006a054d: { // 0x6a054d: 3bf2 CMP ESI,EDX
    (void)integer::sub(s.si,s.dx,32,flags);
  }
  L006a054f: { // 0x6a054f: 7c5e JL 0x006a05af
    if(integer::condition("JL",flags)) goto L006a05af;
  }
  L006a0551: { // 0x6a0551: 83f8e2 CMP EAX,-0x1e
    (void)integer::sub(s.ax,0xffffffe2u,32,flags);
  }
  L006a0554: { // 0x6a0554: 7c59 JL 0x006a05af
    if(integer::condition("JL",flags)) goto L006a05af;
  }
  L006a0556: { // 0x6a0556: 8b1578198200 MOV EDX,dword ptr [0x00821978]
    s.dx = m.r32((0x00821978u));
  }
  L006a055c: { // 0x6a055c: 8d4c0a1e LEA ECX,[EDX + ECX*0x1 + 0x1e]
    s.cx = (s.dx+(s.cx * 0x00000001u)+0x0000001eu);
  }
  L006a0560: { // 0x6a0560: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L006a0562: { // 0x6a0562: 7f4b JG 0x006a05af
    if(integer::condition("JG",flags)) goto L006a05af;
  }
  L006a0564: { // 0x6a0564: 8b1574198200 MOV EDX,dword ptr [0x00821974]
    s.dx = m.r32((0x00821974u));
  }
  L006a056a: { // 0x6a056a: 8b0d7c198200 MOV ECX,dword ptr [0x0082197c]
    s.cx = m.r32((0x0082197cu));
  }
  L006a0570: { // 0x6a0570: 8d54110f LEA EDX,[ECX + EDX*0x1 + 0xf]
    s.dx = (s.cx+(s.dx * 0x00000001u)+0x0000000fu);
  }
  L006a0574: { // 0x6a0574: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L006a0576: { // 0x6a0576: 7f37 JG 0x006a05af
    if(integer::condition("JG",flags)) goto L006a05af;
  }
  L006a0578: { // 0x6a0578: 8b83e0000000 MOV EAX,dword ptr [EBX + 0xe0]
    s.ax = m.r32((s.bx+0x000000e0u));
  }
  L006a057e: { // 0x6a057e: 3d1f030000 CMP EAX,0x31f
    (void)integer::sub(s.ax,0x0000031fu,32,flags);
  }
  L006a0583: { // 0x6a0583: 7d18 JGE 0x006a059d
    if(integer::condition("JGE",flags)) goto L006a059d;
  }
  L006a0585: { // 0x6a0585: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L006a0589: { // 0x6a0589: 898c83e4000000 MOV dword ptr [EBX + EAX*0x4 + 0xe4],ECX
    m.w32((s.bx+(s.ax * 0x00000004u)+0x000000e4u), s.cx);
  }
  L006a0590: { // 0x6a0590: 8b83e0000000 MOV EAX,dword ptr [EBX + 0xe0]
    s.ax = m.r32((s.bx+0x000000e0u));
  }
  L006a0596: { // 0x6a0596: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L006a0597: { // 0x6a0597: 8983e0000000 MOV dword ptr [EBX + 0xe0],EAX
    m.w32((s.bx+0x000000e0u), s.ax);
  }
  L006a059d: { // 0x6a059d: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L006a05a1: { // 0x6a05a1: c6823801000000 MOV byte ptr [EDX + 0x138],0x0
    m.w8((s.dx+0x00000138u), 0x00000000u);
  }
  L006a05a8: { // 0x6a05a8: c6837d0d000001 MOV byte ptr [EBX + 0xd7d],0x1
    m.w8((s.bx+0x00000d7du), 0x00000001u);
  }
  L006a05af: { // 0x6a05af: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006a05b0: { // 0x6a05b0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006a05b1: { // 0x6a05b1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006a05b2: { // 0x6a05b2: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L006a05b5: { // 0x6a05b5: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00165310(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00565310: { // 0x565310: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00565313: { // 0x565313: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L00565317: { // 0x565317: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00565318: { // 0x565318: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00565319: { // 0x565319: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0056531a: { // 0x56531a: 8b4824 MOV ECX,dword ptr [EAX + 0x24]
    s.cx = m.r32((s.ax+0x00000024u));
  }
  L0056531d: { // 0x56531d: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0056531e: { // 0x56531e: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L00565322: { // 0x565322: 668b5c241e MOV BX,word ptr [ESP + 0x1e]
    s.bx = with_ax(s.bx, m.r16((f.sp+0x0000001eu)));
  }
  L00565327: { // 0x565327: bf01000000 MOV EDI,0x1
    s.di = 0x00000001u;
  }
  L0056532c: { // 0x56532c: 668be9 MOV BP,CX
    s.bp = (s.bp & 0xffff0000u) | (((s.cx & 0xffffu)) & 0xffffu);
  }
  L0056532f: { // 0x56532f: 0fbfc3 MOVSX EAX,BX
    s.ax = std::uint32_t(integer::sign_extend((s.bx & 0xffffu),16));
  }
  L00565332: { // 0x565332: 0fbfd5 MOVSX EDX,BP
    s.dx = std::uint32_t(integer::sign_extend((s.bp & 0xffffu),16));
  }
  L00565335: { // 0x565335: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L00565338: { // 0x565338: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0056533a: { // 0x56533a: 7818 JS 0x00565354
    if(integer::condition("JS",flags)) goto L00565354;
  }
  L0056533c: { // 0x56533c: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00565341: { // 0x565341: 7d11 JGE 0x00565354
    if(integer::condition("JGE",flags)) goto L00565354;
  }
  L00565343: { // 0x565343: 8b0d58a98100 MOV ECX,dword ptr [0x0081a958]
    s.cx = m.r32((0x0081a958u));
  }
  L00565349: { // 0x565349: 8b0481 MOV EAX,dword ptr [ECX + EAX*0x4]
    s.ax = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L0056534c: { // 0x56534c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0056534e: { // 0x56534e: 7404 JZ 0x00565354
    if(integer::condition("JZ",flags)) goto L00565354;
  }
  L00565350: { // 0x565350: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00565352: { // 0x565352: eb0f JMP 0x00565363
    goto L00565363;
  }
  L00565354: { // 0x565354: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L00565358: { // 0x565358: be1076a500 MOV ESI,0xa57610
    s.si = 0x00a57610u;
  }
  L0056535d: { // 0x56535d: 89153476a500 MOV dword ptr [0x00a57634],EDX
    m.w32((0x00a57634u), s.dx);
  }
  L00565363: { // 0x565363: 0fbe861b010000 MOVSX EAX,byte ptr [ESI + 0x11b]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.si+0x0000011bu)),8));
  }
  L0056536a: { // 0x56536a: 8d4ffe LEA ECX,[EDI + -0x2]
    s.cx = (s.di-0x00000002u);
  }
  L0056536d: { // 0x56536d: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0056536f: { // 0x56536f: 7c45 JL 0x005653b6
    if(integer::condition("JL",flags)) goto L005653b6;
  }
  L00565371: { // 0x565371: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L00565373: { // 0x565373: 7f41 JG 0x005653b6
    if(integer::condition("JG",flags)) goto L005653b6;
  }
  L00565375: { // 0x565375: 8a442424 MOV AL,byte ptr [ESP + 0x24]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000024u)));
  }
  L00565379: { // 0x565379: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0056537b: { // 0x56537b: 740e JZ 0x0056538b
    if(integer::condition("JZ",flags)) goto L0056538b;
  }
  L0056537d: { // 0x56537d: 8d5624 LEA EDX,[ESI + 0x24]
    s.dx = (s.si+0x00000024u);
  }
  L00565380: { // 0x565380: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00565385: { // 0x565385: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00565386: { // 0x565386: e8e54b0c00 CALL 0x00629f70
    s.arithmetic_flags=flags; invoke(m,s,f,0x00629f70u,5657483u); flags=s.arithmetic_flags;
  }
  L0056538b: { // 0x56538b: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0056538d: { // 0x56538d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0056538f: { // 0x56538f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00565390: { // 0x565390: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00565394: { // 0x565394: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00565398: { // 0x565398: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00565399: { // 0x565399: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L0056539d: { // 0x56539d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0056539e: { // 0x56539e: e8bdbef0ff CALL 0x00471260
    s.arithmetic_flags=flags; invoke(m,s,f,0x00471260u,5657507u); flags=s.arithmetic_flags;
  }
  L005653a3: { // 0x5653a3: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005653a5: { // 0x5653a5: 740f JZ 0x005653b6
    if(integer::condition("JZ",flags)) goto L005653b6;
  }
  L005653a7: { // 0x5653a7: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L005653ab: { // 0x5653ab: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L005653ad: { // 0x5653ad: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005653ae: { // 0x5653ae: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L005653b0: { // 0x5653b0: ff9280010000 CALL dword ptr [EDX + 0x180]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000180u)),5657526u); flags=s.arithmetic_flags;
  }
  L005653b6: { // 0x5653b6: 6645 INC BP
    s.bp = (s.bp & 0xffff0000u) | ((integer::increment((s.bp & 0xffffu),16,flags)) & 0xffffu);
  }
  L005653b8: { // 0x5653b8: 83c702 ADD EDI,0x2
    s.di = integer::add(s.di,0x00000002u,32,flags);
  }
  L005653bb: { // 0x5653bb: 6643 INC BX
    s.bx = with_ax(s.bx, integer::increment((s.bx & 0xffffu),16,flags));
  }
  L005653bd: { // 0x5653bd: 83ff0f CMP EDI,0xf
    (void)integer::sub(s.di,0x0000000fu,32,flags);
  }
  L005653c0: { // 0x5653c0: 66896c241c MOV word ptr [ESP + 0x1c],BP
    m.w16((f.sp+0x0000001cu), (s.bp & 0xffffu));
  }
  L005653c5: { // 0x5653c5: 66895c241e MOV word ptr [ESP + 0x1e],BX
    m.w16((f.sp+0x0000001eu), (s.bx & 0xffffu));
  }
  L005653ca: { // 0x5653ca: 0f8c5fffffff JL 0x0056532f
    if(integer::condition("JL",flags)) goto L0056532f;
  }
  L005653d0: { // 0x5653d0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005653d1: { // 0x5653d1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005653d2: { // 0x5653d2: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005653d3: { // 0x5653d3: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005653d4: { // 0x5653d4: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L005653d7: { // 0x5653d7: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
void f_00229f70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00629f70: { // 0x629f70: 83ec34 SUB ESP,0x34
    f.sp = integer::sub(f.sp,0x00000034u,32,flags);
  }
  L00629f73: { // 0x629f73: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00629f74: { // 0x629f74: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00629f75: { // 0x629f75: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00629f76: { // 0x629f76: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00629f78: { // 0x629f78: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L00629f7a: { // 0x629f7a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00629f7b: { // 0x629f7b: 39ae18120000 CMP dword ptr [ESI + 0x1218],EBP
    (void)integer::sub(m.r32((s.si+0x00001218u)),s.bp,32,flags);
  }
  L00629f81: { // 0x629f81: 0f848d010000 JZ 0x0062a114
    if(integer::condition("JZ",flags)) goto L0062a114;
  }
  L00629f87: { // 0x629f87: 8b442448 MOV EAX,dword ptr [ESP + 0x48]
    s.ax = m.r32((f.sp+0x00000048u));
  }
  L00629f8b: { // 0x629f8b: 8bbe94140000 MOV EDI,dword ptr [ESI + 0x1494]
    s.di = m.r32((s.si+0x00001494u));
  }
  L00629f91: { // 0x629f91: 0fbf4802 MOVSX ECX,word ptr [EAX + 0x2]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000002u)),16));
  }
  L00629f95: { // 0x629f95: 0fbf10 MOVSX EDX,word ptr [EAX]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.ax)),16));
  }
  L00629f98: { // 0x629f98: 8b868c140000 MOV EAX,dword ptr [ESI + 0x148c]
    s.ax = m.r32((s.si+0x0000148cu));
  }
  L00629f9e: { // 0x629f9e: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00629fa0: { // 0x629fa0: 2bcf SUB ECX,EDI
    s.cx = integer::sub(s.cx,s.di,32,flags);
  }
  L00629fa2: { // 0x629fa2: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00629fa4: { // 0x629fa4: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L00629fa6: { // 0x629fa6: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00629fa9: { // 0x629fa9: ba02000000 MOV EDX,0x2
    s.dx = 0x00000002u;
  }
  L00629fae: { // 0x629fae: 7504 JNZ 0x00629fb4
    if(integer::condition("JNZ",flags)) goto L00629fb4;
  }
  L00629fb0: { // 0x629fb0: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00629fb2: { // 0x629fb2: eb0e JMP 0x00629fc2
    goto L00629fc2;
  }
  L00629fb4: { // 0x629fb4: 8bbe00010000 MOV EDI,dword ptr [ESI + 0x100]
    s.di = m.r32((s.si+0x00000100u));
  }
  L00629fba: { // 0x629fba: 8d7c3fff LEA EDI,[EDI + EDI*0x1 + -0x1]
    s.di = (s.di+(s.di * 0x00000001u)-0x00000001u);
  }
  L00629fbe: { // 0x629fbe: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L00629fc0: { // 0x629fc0: 7505 JNZ 0x00629fc7
    if(integer::condition("JNZ",flags)) goto L00629fc7;
  }
  L00629fc2: { // 0x629fc2: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L00629fc7: { // 0x629fc7: 894c2428 MOV dword ptr [ESP + 0x28],ECX
    m.w32((f.sp+0x00000028u), s.cx);
  }
  L00629fcb: { // 0x629fcb: 8b8e40120000 MOV ECX,dword ptr [ESI + 0x1240]
    s.cx = m.r32((s.si+0x00001240u));
  }
  L00629fd1: { // 0x629fd1: 8954242c MOV dword ptr [ESP + 0x2c],EDX
    m.w32((f.sp+0x0000002cu), s.dx);
  }
  L00629fd5: { // 0x629fd5: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00629fd6: { // 0x629fd6: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  L00629fda: { // 0x629fda: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L00629fde: { // 0x629fde: 8b863c120000 MOV EAX,dword ptr [ESI + 0x123c]
    s.ax = m.r32((s.si+0x0000123cu));
  }
  L00629fe4: { // 0x629fe4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00629fe5: { // 0x629fe5: bf01000000 MOV EDI,0x1
    s.di = 0x00000001u;
  }
  L00629fea: { // 0x629fea: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L00629fee: { // 0x629fee: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00629fef: { // 0x629fef: 8d542430 LEA EDX,[ESP + 0x30]
    s.dx = (f.sp+0x00000030u);
  }
  L00629ff3: { // 0x629ff3: 8d4c2440 LEA ECX,[ESP + 0x40]
    s.cx = (f.sp+0x00000040u);
  }
  L00629ff7: { // 0x629ff7: 897c243c MOV dword ptr [ESP + 0x3c],EDI
    m.w32((f.sp+0x0000003cu), s.di);
  }
  L00629ffb: { // 0x629ffb: 896c241c MOV dword ptr [ESP + 0x1c],EBP
    m.w32((f.sp+0x0000001cu), s.bp);
  }
  L00629fff: { // 0x629fff: 896c2420 MOV dword ptr [ESP + 0x20],EBP
    m.w32((f.sp+0x00000020u), s.bp);
  }
  L0062a003: { // 0x62a003: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L0062a007: { // 0x62a007: e8e45ddfff CALL 0x0041fdf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041fdf0u,6463500u); flags=s.arithmetic_flags;
  }
  L0062a00c: { // 0x62a00c: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0062a00e: { // 0x62a00e: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L0062a012: { // 0x62a012: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0062a015: { // 0x62a015: 89542428 MOV dword ptr [ESP + 0x28],EDX
    m.w32((f.sp+0x00000028u), s.dx);
  }
  L0062a019: { // 0x62a019: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L0062a01c: { // 0x62a01c: 894c242c MOV dword ptr [ESP + 0x2c],ECX
    m.w32((f.sp+0x0000002cu), s.cx);
  }
  L0062a020: { // 0x62a020: 8b8e18120000 MOV ECX,dword ptr [ESI + 0x1218]
    s.cx = m.r32((s.si+0x00001218u));
  }
  L0062a026: { // 0x62a026: 8b500c MOV EDX,dword ptr [EAX + 0xc]
    s.dx = m.r32((s.ax+0x0000000cu));
  }
  L0062a029: { // 0x62a029: 89542430 MOV dword ptr [ESP + 0x30],EDX
    m.w32((f.sp+0x00000030u), s.dx);
  }
  L0062a02d: { // 0x62a02d: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0062a02f: { // 0x62a02f: ff507c CALL dword ptr [EAX + 0x7c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000007cu)),6463538u); flags=s.arithmetic_flags;
  }
  L0062a032: { // 0x62a032: 8b8e18120000 MOV ECX,dword ptr [ESI + 0x1218]
    s.cx = m.r32((s.si+0x00001218u));
  }
  L0062a038: { // 0x62a038: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0062a03a: { // 0x62a03a: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L0062a03c: { // 0x62a03c: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),6463554u); flags=s.arithmetic_flags;
  }
  L0062a042: { // 0x62a042: 8b5c242c MOV EBX,dword ptr [ESP + 0x2c]
    s.bx = m.r32((f.sp+0x0000002cu));
  }
  L0062a046: { // 0x62a046: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0062a04a: { // 0x62a04a: 3bdd CMP EBX,EBP
    (void)integer::sub(s.bx,s.bp,32,flags);
  }
  L0062a04c: { // 0x62a04c: 0f8ec2000000 JLE 0x0062a114
    if(integer::condition("JLE",flags)) goto L0062a114;
  }
  L0062a052: { // 0x62a052: 396c2430 CMP dword ptr [ESP + 0x30],EBP
    (void)integer::sub(m.r32((f.sp+0x00000030u)),s.bp,32,flags);
  }
  L0062a056: { // 0x62a056: 0f8eb8000000 JLE 0x0062a114
    if(integer::condition("JLE",flags)) goto L0062a114;
  }
  L0062a05c: { // 0x62a05c: db442424 FILD dword ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.load_integer32(m.r32(address));
  }
  L0062a060: { // 0x62a060: d88e84140000 FMUL float ptr [ESI + 0x1484]
    const auto address=(s.si+0x00001484u);
    s.fp.multiply32(m.r32(address));
  }
  L0062a066: { // 0x62a066: e8e5091400 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6463595u); flags=s.arithmetic_flags;
  }
  L0062a06b: { // 0x62a06b: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L0062a06f: { // 0x62a06f: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0062a070: { // 0x62a070: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0062a072: { // 0x62a072: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L0062a074: { // 0x62a074: 0f9cc1 SETL CL
    s.cx = with_al(s.cx, (integer::condition("JL",flags)?1u:0u));
  }
  L0062a077: { // 0x62a077: 03da ADD EBX,EDX
    s.bx = integer::add(s.bx,s.dx,32,flags);
  }
  L0062a079: { // 0x62a079: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0062a07a: { // 0x62a07a: 895c2448 MOV dword ptr [ESP + 0x48],EBX
    m.w32((f.sp+0x00000048u), s.bx);
  }
  L0062a07e: { // 0x62a07e: 23c8 AND ECX,EAX
    s.cx = integer::logical((s.cx)&(s.ax),32,flags);
  }
  L0062a080: { // 0x62a080: db442448 FILD dword ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    s.fp.load_integer32(m.r32(address));
  }
  L0062a084: { // 0x62a084: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L0062a088: { // 0x62a088: d88e84140000 FMUL float ptr [ESI + 0x1484]
    const auto address=(s.si+0x00001484u);
    s.fp.multiply32(m.r32(address));
  }
  L0062a08e: { // 0x62a08e: e8bd091400 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6463635u); flags=s.arithmetic_flags;
  }
  L0062a093: { // 0x62a093: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0062a094: { // 0x62a094: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0062a096: { // 0x62a096: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L0062a098: { // 0x62a098: 7c02 JL 0x0062a09c
    if(integer::condition("JL",flags)) goto L0062a09c;
  }
  L0062a09a: { // 0x62a09a: 8bef MOV EBP,EDI
    s.bp = s.di;
  }
  L0062a09c: { // 0x62a09c: db442428 FILD dword ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.load_integer32(m.r32(address));
  }
  L0062a0a0: { // 0x62a0a0: d88e84140000 FMUL float ptr [ESI + 0x1484]
    const auto address=(s.si+0x00001484u);
    s.fp.multiply32(m.r32(address));
  }
  L0062a0a6: { // 0x62a0a6: e8a5091400 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6463659u); flags=s.arithmetic_flags;
  }
  L0062a0ab: { // 0x62a0ab: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0062a0ac: { // 0x62a0ac: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0062a0ae: { // 0x62a0ae: 8b4c2430 MOV ECX,dword ptr [ESP + 0x30]
    s.cx = m.r32((f.sp+0x00000030u));
  }
  L0062a0b2: { // 0x62a0b2: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0062a0b4: { // 0x62a0b4: 0f9cc3 SETL BL
    s.bx = with_al(s.bx, (integer::condition("JL",flags)?1u:0u));
  }
  L0062a0b7: { // 0x62a0b7: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L0062a0b8: { // 0x62a0b8: 23d8 AND EBX,EAX
    s.bx = integer::logical((s.bx)&(s.ax),32,flags);
  }
  L0062a0ba: { // 0x62a0ba: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L0062a0be: { // 0x62a0be: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0062a0c0: { // 0x62a0c0: 894c2448 MOV dword ptr [ESP + 0x48],ECX
    m.w32((f.sp+0x00000048u), s.cx);
  }
  L0062a0c4: { // 0x62a0c4: db442448 FILD dword ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    s.fp.load_integer32(m.r32(address));
  }
  L0062a0c8: { // 0x62a0c8: d88e84140000 FMUL float ptr [ESI + 0x1484]
    const auto address=(s.si+0x00001484u);
    s.fp.multiply32(m.r32(address));
  }
  L0062a0ce: { // 0x62a0ce: e87d091400 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6463699u); flags=s.arithmetic_flags;
  }
  L0062a0d3: { // 0x62a0d3: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L0062a0d7: { // 0x62a0d7: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0062a0d8: { // 0x62a0d8: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0062a0da: { // 0x62a0da: 89442448 MOV dword ptr [ESP + 0x48],EAX
    m.w32((f.sp+0x00000048u), s.ax);
  }
  L0062a0de: { // 0x62a0de: 7c04 JL 0x0062a0e4
    if(integer::condition("JL",flags)) goto L0062a0e4;
  }
  L0062a0e0: { // 0x62a0e0: 894c2448 MOV dword ptr [ESP + 0x48],ECX
    m.w32((f.sp+0x00000048u), s.cx);
  }
  L0062a0e4: { // 0x62a0e4: 3b5c2448 CMP EBX,dword ptr [ESP + 0x48]
    (void)integer::sub(s.bx,m.r32((f.sp+0x00000048u)),32,flags);
  }
  L0062a0e8: { // 0x62a0e8: 7d2a JGE 0x0062a114
    if(integer::condition("JGE",flags)) goto L0062a114;
  }
  L0062a0ea: { // 0x62a0ea: 8b7c2420 MOV EDI,dword ptr [ESP + 0x20]
    s.di = m.r32((f.sp+0x00000020u));
  }
  L0062a0ee: { // 0x62a0ee: 3bfd CMP EDI,EBP
    (void)integer::sub(s.di,s.bp,32,flags);
  }
  L0062a0f0: { // 0x62a0f0: 7d19 JGE 0x0062a10b
    if(integer::condition("JGE",flags)) goto L0062a10b;
  }
  L0062a0f2: { // 0x62a0f2: 8d542410 LEA EDX,[ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  L0062a0f6: { // 0x62a0f6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0062a0f8: { // 0x62a0f8: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0062a0f9: { // 0x62a0f9: 897c2414 MOV dword ptr [ESP + 0x14],EDI
    m.w32((f.sp+0x00000014u), s.di);
  }
  L0062a0fd: { // 0x62a0fd: 895c2418 MOV dword ptr [ESP + 0x18],EBX
    m.w32((f.sp+0x00000018u), s.bx);
  }
  L0062a101: { // 0x62a101: e89afbffff CALL 0x00629ca0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00629ca0u,6463750u); flags=s.arithmetic_flags;
  }
  L0062a106: { // 0x62a106: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0062a107: { // 0x62a107: 3bfd CMP EDI,EBP
    (void)integer::sub(s.di,s.bp,32,flags);
  }
  L0062a109: { // 0x62a109: 7ce7 JL 0x0062a0f2
    if(integer::condition("JL",flags)) goto L0062a0f2;
  }
  L0062a10b: { // 0x62a10b: 8b442448 MOV EAX,dword ptr [ESP + 0x48]
    s.ax = m.r32((f.sp+0x00000048u));
  }
  L0062a10f: { // 0x62a10f: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L0062a110: { // 0x62a110: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L0062a112: { // 0x62a112: 7cd6 JL 0x0062a0ea
    if(integer::condition("JL",flags)) goto L0062a0ea;
  }
  L0062a114: { // 0x62a114: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0062a115: { // 0x62a115: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0062a116: { // 0x62a116: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0062a117: { // 0x62a117: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0062a118: { // 0x62a118: 83c434 ADD ESP,0x34
    f.sp = integer::add(f.sp,0x00000034u,32,flags);
  }
  L0062a11b: { // 0x62a11b: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00071260(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00471260: { // 0x471260: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00471261: { // 0x471261: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L00471263: { // 0x471263: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L00471266: { // 0x471266: 83ec34 SUB ESP,0x34
    f.sp = integer::sub(f.sp,0x00000034u,32,flags);
  }
  L00471269: { // 0x471269: 8b5508 MOV EDX,dword ptr [EBP + 0x8]
    s.dx = m.r32((s.bp+0x00000008u));
  }
  L0047126c: { // 0x47126c: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0047126d: { // 0x47126d: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0047126e: { // 0x47126e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0047126f: { // 0x47126f: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L00471271: { // 0x471271: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L00471273: { // 0x471273: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L00471277: { // 0x471277: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L0047127b: { // 0x47127b: 8d3cc500000000 LEA EDI,[EAX*0x8 + 0x0]
    s.di = ((s.ax * 0x00000008u)+0x00000000u);
  }
  L00471282: { // 0x471282: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L00471284: { // 0x471284: 8b4204 MOV EAX,dword ptr [EDX + 0x4]
    s.ax = m.r32((s.dx+0x00000004u));
  }
  L00471287: { // 0x471287: 8d1cc500000000 LEA EBX,[EAX*0x8 + 0x0]
    s.bx = ((s.ax * 0x00000008u)+0x00000000u);
  }
  L0047128e: { // 0x47128e: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00471290: { // 0x471290: 8a450c MOV AL,byte ptr [EBP + 0xc]
    s.ax = with_al(s.ax, m.r8((s.bp+0x0000000cu)));
  }
  L00471293: { // 0x471293: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00471295: { // 0x471295: 7408 JZ 0x0047129f
    if(integer::condition("JZ",flags)) goto L0047129f;
  }
  L00471297: { // 0x471297: 8b89e8000000 MOV ECX,dword ptr [ECX + 0xe8]
    s.cx = m.r32((s.cx+0x000000e8u));
  }
  L0047129d: { // 0x47129d: eb06 JMP 0x004712a5
    goto L004712a5;
  }
  L0047129f: { // 0x47129f: 8b89e4000000 MOV ECX,dword ptr [ECX + 0xe4]
    s.cx = m.r32((s.cx+0x000000e4u));
  }
  L004712a5: { // 0x4712a5: 3bce CMP ECX,ESI
    (void)integer::sub(s.cx,s.si,32,flags);
  }
  L004712a7: { // 0x4712a7: 0f84a2000000 JZ 0x0047134f
    if(integer::condition("JZ",flags)) goto L0047134f;
  }
  L004712ad: { // 0x4712ad: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004712af: { // 0x4712af: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L004712b1: { // 0x4712b1: 0f8480000000 JZ 0x00471337
    if(integer::condition("JZ",flags)) goto L00471337;
  }
  L004712b7: { // 0x4712b7: 8a4614 MOV AL,byte ptr [ESI + 0x14]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000014u)));
  }
  L004712ba: { // 0x4712ba: 2401 AND AL,0x1
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags));
  }
  L004712bc: { // 0x4712bc: 88442413 MOV byte ptr [ESP + 0x13],AL
    m.w8((f.sp+0x00000013u), (s.ax & 0xffu));
  }
  L004712c0: { // 0x4712c0: 7475 JZ 0x00471337
    if(integer::condition("JZ",flags)) goto L00471337;
  }
  L004712c2: { // 0x4712c2: 3b7510 CMP ESI,dword ptr [EBP + 0x10]
    (void)integer::sub(s.si,m.r32((s.bp+0x00000010u)),32,flags);
  }
  L004712c5: { // 0x4712c5: 7470 JZ 0x00471337
    if(integer::condition("JZ",flags)) goto L00471337;
  }
  L004712c7: { // 0x4712c7: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004712c9: { // 0x4712c9: 8d442428 LEA EAX,[ESP + 0x28]
    s.ax = (f.sp+0x00000028u);
  }
  L004712cd: { // 0x4712cd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004712ce: { // 0x4712ce: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004712d0: { // 0x4712d0: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),4657875u); flags=s.arithmetic_flags;
  }
  L004712d3: { // 0x4712d3: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L004712d5: { // 0x4712d5: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L004712d8: { // 0x4712d8: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L004712da: { // 0x4712da: 25ff000000 AND EAX,0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  L004712df: { // 0x4712df: 8b4a04 MOV ECX,dword ptr [EDX + 0x4]
    s.cx = m.r32((s.dx+0x00000004u));
  }
  L004712e2: { // 0x4712e2: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  L004712e4: { // 0x4712e4: 81e1ff000000 AND ECX,0xff
    s.cx = integer::logical((s.cx)&(0x000000ffu),32,flags);
  }
  L004712ea: { // 0x4712ea: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L004712ee: { // 0x4712ee: 2bcb SUB ECX,EBX
    s.cx = integer::sub(s.cx,s.bx,32,flags);
  }
  L004712f0: { // 0x4712f0: 8b5208 MOV EDX,dword ptr [EDX + 0x8]
    s.dx = m.r32((s.dx+0x00000008u));
  }
  L004712f3: { // 0x4712f3: 894c2428 MOV dword ptr [ESP + 0x28],ECX
    m.w32((f.sp+0x00000028u), s.cx);
  }
  L004712f7: { // 0x4712f7: 89542444 MOV dword ptr [ESP + 0x44],EDX
    m.w32((f.sp+0x00000044u), s.dx);
  }
  L004712fb: { // 0x4712fb: db442428 FILD dword ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.load_integer32(m.r32(address));
  }
  L004712ff: { // 0x4712ff: db442424 FILD dword ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.load_integer32(m.r32(address));
  }
  L00471303: { // 0x471303: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L00471305: { // 0x471305: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L00471307: { // 0x471307: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L00471309: { // 0x471309: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L0047130b: { // 0x47130b: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0047130d: { // 0x47130d: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00471310: { // 0x471310: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00471312: { // 0x471312: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00471314: { // 0x471314: e8678d0400 CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,4657945u); flags=s.arithmetic_flags;
  }
  L00471319: { // 0x471319: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0047131c: { // 0x47131c: e82f972f00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4657953u); flags=s.arithmetic_flags;
  }
  L00471321: { // 0x471321: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L00471325: { // 0x471325: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00471327: { // 0x471327: 7406 JZ 0x0047132f
    if(integer::condition("JZ",flags)) goto L0047132f;
  }
  L00471329: { // 0x471329: 3b442418 CMP EAX,dword ptr [ESP + 0x18]
    (void)integer::sub(s.ax,m.r32((f.sp+0x00000018u)),32,flags);
  }
  L0047132d: { // 0x47132d: 7d08 JGE 0x00471337
    if(integer::condition("JGE",flags)) goto L00471337;
  }
  L0047132f: { // 0x47132f: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L00471333: { // 0x471333: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00471337: { // 0x471337: 8b7630 MOV ESI,dword ptr [ESI + 0x30]
    s.si = m.r32((s.si+0x00000030u));
  }
  L0047133a: { // 0x47133a: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0047133c: { // 0x47133c: 0f8575ffffff JNZ 0x004712b7
    if(integer::condition("JNZ",flags)) goto L004712b7;
  }
  L00471342: { // 0x471342: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00471346: { // 0x471346: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00471347: { // 0x471347: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00471348: { // 0x471348: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00471349: { // 0x471349: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L0047134b: { // 0x47134b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0047134c: { // 0x47134c: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L0047134f: { // 0x47134f: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00471351: { // 0x471351: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00471352: { // 0x471352: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00471353: { // 0x471353: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00471354: { // 0x471354: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L00471356: { // 0x471356: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00471357: { // 0x471357: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
void f_0007b650(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0047b650: { // 0x47b650: 83ec08 SUB ESP, 0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0047b653: { // 0x47b653: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0047b654: { // 0x47b654: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0047b655: { // 0x47b655: 0fbf7124 MOVSX ESI, word ptr [ECX + 0x24]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000024u)),16));
  }
  L0047b659: { // 0x47b659: 0fbf7926 MOVSX EDI, word ptr [ECX + 0x26]
    s.di = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000026u)),16));
  }
  L0047b65d: { // 0x47b65d: c1e608 SHL ESI, 0x8
    s.si = integer::shift(s.si,0x00000008u,32,flags,integer::Shift::left);
  }
  L0047b660: { // 0x47b660: c1e708 SHL EDI, 0x8
    s.di = integer::shift(s.di,0x00000008u,32,flags,integer::Shift::left);
  }
  L0047b663: { // 0x47b663: 8d442408 LEA EAX, [ESP + 0x8]
    s.ax = (f.sp+0x00000008u);
  }
  L0047b667: { // 0x47b667: 81c680000000 ADD ESI, 0x80
    s.si = integer::add(s.si,0x00000080u,32,flags);
  }
  L0047b66d: { // 0x47b66d: 81c780000000 ADD EDI, 0x80
    s.di = integer::add(s.di,0x00000080u,32,flags);
  }
  L0047b673: { // 0x47b673: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0047b674: { // 0x47b674: 8974240c MOV dword ptr [ESP + 0xc], ESI
    m.w32((f.sp+0x0000000cu), s.si);
  }
  L0047b678: { // 0x47b678: 897c2410 MOV dword ptr [ESP + 0x10], EDI
    m.w32((f.sp+0x00000010u), s.di);
  }
  L0047b67c: { // 0x47b67c: e83f4cffff CALL 0x4702c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004702c0u,4699777u); flags=s.arithmetic_flags;
  }
  L0047b681: { // 0x47b681: 8b4c2414 MOV ECX, dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0047b685: { // 0x47b685: 8bd1 MOV EDX, ECX
    s.dx = s.cx;
  }
  L0047b687: { // 0x47b687: 8932 MOV dword ptr [EDX], ESI
    m.w32((s.dx), s.si);
  }
  L0047b689: { // 0x47b689: 897a04 MOV dword ptr [EDX + 0x4], EDI
    m.w32((s.dx+0x00000004u), s.di);
  }
  L0047b68c: { // 0x47b68c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0047b68d: { // 0x47b68d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047b68e: { // 0x47b68e: 894208 MOV dword ptr [EDX + 0x8], EAX
    m.w32((s.dx+0x00000008u), s.ax);
  }
  L0047b691: { // 0x47b691: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L0047b693: { // 0x47b693: 83c408 ADD ESP, 0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0047b696: { // 0x47b696: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00157280(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00557280: { // 0x557280: 8b8110010000 MOV EAX,dword ptr [ECX + 0x110]
    s.ax = m.r32((s.cx+0x00000110u));
  }
  L00557286: { // 0x557286: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00557287: { // 0x557287: 8ba914010000 MOV EBP,dword ptr [ECX + 0x114]
    s.bp = m.r32((s.cx+0x00000114u));
  }
  L0055728d: { // 0x55728d: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0055728e: { // 0x55728e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00557290: { // 0x557290: 7433 JZ 0x005572c5
    if(integer::condition("JZ",flags)) goto L005572c5;
  }
  L00557292: { // 0x557292: 8bb108010000 MOV ESI,dword ptr [ECX + 0x108]
    s.si = m.r32((s.cx+0x00000108u));
  }
  L00557298: { // 0x557298: 8b910c010000 MOV EDX,dword ptr [ECX + 0x10c]
    s.dx = m.r32((s.cx+0x0000010cu));
  }
  L0055729e: { // 0x55729e: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0055729f: { // 0x55729f: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L005572a0: { // 0x5572a0: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L005572a1: { // 0x5572a1: 89b108010000 MOV dword ptr [ECX + 0x108],ESI
    m.w32((s.cx+0x00000108u), s.si);
  }
  L005572a7: { // 0x5572a7: 898110010000 MOV dword ptr [ECX + 0x110],EAX
    m.w32((s.cx+0x00000110u), s.ax);
  }
  L005572ad: { // 0x5572ad: 8d8504f8ffff LEA EAX,[EBP + 0xfffff804]
    s.ax = (s.bp+0xfffff804u);
  }
  L005572b3: { // 0x5572b3: 89910c010000 MOV dword ptr [ECX + 0x10c],EDX
    m.w32((s.cx+0x0000010cu), s.dx);
  }
  L005572b9: { // 0x5572b9: 898114010000 MOV dword ptr [ECX + 0x114],EAX
    m.w32((s.cx+0x00000114u), s.ax);
  }
  L005572bf: { // 0x5572bf: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L005572c2: { // 0x5572c2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005572c3: { // 0x5572c3: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005572c4: { // 0x5572c4: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L005572c5: { // 0x5572c5: 8b910c010000 MOV EDX,dword ptr [ECX + 0x10c]
    s.dx = m.r32((s.cx+0x0000010cu));
  }
  L005572cb: { // 0x5572cb: 8b8108010000 MOV EAX,dword ptr [ECX + 0x108]
    s.ax = m.r32((s.cx+0x00000108u));
  }
  L005572d1: { // 0x5572d1: 8bb1f0000000 MOV ESI,dword ptr [ECX + 0xf0]
    s.si = m.r32((s.cx+0x000000f0u));
  }
  L005572d7: { // 0x5572d7: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005572d8: { // 0x5572d8: 899108010000 MOV dword ptr [ECX + 0x108],EDX
    m.w32((s.cx+0x00000108u), s.dx);
  }
  L005572de: { // 0x5572de: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L005572e0: { // 0x5572e0: 2bd6 SUB EDX,ESI
    s.dx = integer::sub(s.dx,s.si,32,flags);
  }
  L005572e2: { // 0x5572e2: 89810c010000 MOV dword ptr [ECX + 0x10c],EAX
    m.w32((s.cx+0x0000010cu), s.ax);
  }
  L005572e8: { // 0x5572e8: 8d5402ff LEA EDX,[EDX + EAX*0x1 + -0x1]
    s.dx = (s.dx+(s.ax * 0x00000001u)-0x00000001u);
  }
  L005572ec: { // 0x5572ec: f6c201 TEST DL,0x1
    (void)integer::logical(((s.dx & 0xffu))&(0x00000001u),8,flags);
  }
  L005572ef: { // 0x5572ef: 740a JZ 0x005572fb
    if(integer::condition("JZ",flags)) goto L005572fb;
  }
  L005572f1: { // 0x5572f1: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L005572f2: { // 0x5572f2: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L005572f3: { // 0x5572f3: 89810c010000 MOV dword ptr [ECX + 0x10c],EAX
    m.w32((s.cx+0x0000010cu), s.ax);
  }
  L005572f9: { // 0x5572f9: eb0a JMP 0x00557305
    goto L00557305;
  }
  L005572fb: { // 0x5572fb: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L005572fc: { // 0x5572fc: 83c6fe ADD ESI,-0x2
    s.si = integer::add(s.si,0xfffffffeu,32,flags);
  }
  L005572ff: { // 0x5572ff: 89b908010000 MOV dword ptr [ECX + 0x108],EDI
    m.w32((s.cx+0x00000108u), s.di);
  }
  L00557305: { // 0x557305: 8b810c010000 MOV EAX,dword ptr [ECX + 0x10c]
    s.ax = m.r32((s.cx+0x0000010cu));
  }
  L0055730b: { // 0x55730b: 8b9108010000 MOV EDX,dword ptr [ECX + 0x108]
    s.dx = m.r32((s.cx+0x00000108u));
  }
  L00557311: { // 0x557311: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L00557314: { // 0x557314: 89b110010000 MOV dword ptr [ECX + 0x110],ESI
    m.w32((s.cx+0x00000110u), s.si);
  }
  L0055731a: { // 0x55731a: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0055731c: { // 0x55731c: 8b9138010000 MOV EDX,dword ptr [ECX + 0x138]
    s.dx = m.r32((s.cx+0x00000138u));
  }
  L00557322: { // 0x557322: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00557323: { // 0x557323: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00557324: { // 0x557324: 8d0482 LEA EAX,[EDX + EAX*0x4]
    s.ax = (s.dx+(s.ax * 0x00000004u));
  }
  L00557327: { // 0x557327: 898114010000 MOV dword ptr [ECX + 0x114],EAX
    m.w32((s.cx+0x00000114u), s.ax);
  }
  L0055732d: { // 0x55732d: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L00557330: { // 0x557330: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00557331: { // 0x557331: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000702c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004702c0: { // 0x4702c0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004702c1: { // 0x4702c1: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L004702c3: { // 0x4702c3: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L004702c6: { // 0x4702c6: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L004702c9: { // 0x4702c9: a0708f8300 MOV AL,[0x00838f70]
    s.ax = with_al(s.ax, m.r8((0x00838f70u)));
  }
  L004702ce: { // 0x4702ce: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004702cf: { // 0x4702cf: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L004702d1: { // 0x4702d1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004702d3: { // 0x4702d3: 7513 JNZ 0x004702e8
    if(integer::condition("JNZ",flags)) goto L004702e8;
  }
  L004702d5: { // 0x4702d5: db05808f8300 FILD dword ptr [0x00838f80]
    const auto address=(0x00838f80u);
    s.fp.load_integer32(m.r32(address));
  }
  L004702db: { // 0x4702db: 0c01 OR AL,0x1
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000001u),8,flags));
  }
  L004702dd: { // 0x4702dd: a2708f8300 MOV [0x00838f70],AL
    m.w8((0x00838f70u), (s.ax & 0xffu));
  }
  L004702e2: { // 0x4702e2: dd1df08e8300 FSTP double ptr [0x00838ef0]
    const auto address=(0x00838ef0u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L004702e8: { // 0x4702e8: a802 TEST AL,0x2
    (void)integer::logical(((s.ax & 0xffu))&(0x00000002u),8,flags);
  }
  L004702ea: { // 0x4702ea: 7519 JNZ 0x00470305
    if(integer::condition("JNZ",flags)) goto L00470305;
  }
  L004702ec: { // 0x4702ec: dd05f08e8300 FLD double ptr [0x00838ef0]
    const auto address=(0x00838ef0u);
    s.fp.load64(read64(m,address));
  }
  L004702f2: { // 0x4702f2: dc0d30577800 FMUL double ptr [0x00785730]
    const auto address=(0x00785730u);
    s.fp.multiply64(read64(m,address));
  }
  L004702f8: { // 0x4702f8: 0c02 OR AL,0x2
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000002u),8,flags));
  }
  L004702fa: { // 0x4702fa: a2708f8300 MOV [0x00838f70],AL
    m.w8((0x00838f70u), (s.ax & 0xffu));
  }
  L004702ff: { // 0x4702ff: dd1d108f8300 FSTP double ptr [0x00838f10]
    const auto address=(0x00838f10u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00470305: { // 0x470305: a804 TEST AL,0x4
    (void)integer::logical(((s.ax & 0xffu))&(0x00000004u),8,flags);
  }
  L00470307: { // 0x470307: 0f85a7060000 JNZ 0x004709b4
    if(integer::condition("JNZ",flags)) goto L004709b4;
  }
  L0047030d: { // 0x47030d: 8b0df48e8300 MOV ECX,dword ptr [0x00838ef4]
    s.cx = m.r32((0x00838ef4u));
  }
  L00470313: { // 0x470313: 0c04 OR AL,0x4
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000004u),8,flags));
  }
  L00470315: { // 0x470315: a2708f8300 MOV [0x00838f70],AL
    m.w8((0x00838f70u), (s.ax & 0xffu));
  }
  L0047031a: { // 0x47031a: a1f08e8300 MOV EAX,[0x00838ef0]
    s.ax = m.r32((0x00838ef0u));
  }
  L0047031f: { // 0x47031f: a398d77b00 MOV [0x007bd798],EAX
    m.w32((0x007bd798u), s.ax);
  }
  L00470324: { // 0x470324: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00470326: { // 0x470326: 890d9cd77b00 MOV dword ptr [0x007bd79c],ECX
    m.w32((0x007bd79cu), s.cx);
  }
  L0047032c: { // 0x47032c: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0047032e: { // 0x47032e: 8915c0d77b00 MOV dword ptr [0x007bd7c0],EDX
    m.w32((0x007bd7c0u), s.dx);
  }
  L00470334: { // 0x470334: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L00470336: { // 0x470336: a3c4d77b00 MOV [0x007bd7c4],EAX
    m.w32((0x007bd7c4u), s.ax);
  }
  L0047033b: { // 0x47033b: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0047033d: { // 0x47033d: 890de0d77b00 MOV dword ptr [0x007bd7e0],ECX
    m.w32((0x007bd7e0u), s.cx);
  }
  L00470343: { // 0x470343: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00470345: { // 0x470345: 8915e4d77b00 MOV dword ptr [0x007bd7e4],EDX
    m.w32((0x007bd7e4u), s.dx);
  }
  L0047034b: { // 0x47034b: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L0047034d: { // 0x47034d: dd05f08e8300 FLD double ptr [0x00838ef0]
    const auto address=(0x00838ef0u);
    s.fp.load64(read64(m,address));
  }
  L00470353: { // 0x470353: a3e8d77b00 MOV [0x007bd7e8],EAX
    m.w32((0x007bd7e8u), s.ax);
  }
  L00470358: { // 0x470358: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0047035a: { // 0x47035a: 890decd77b00 MOV dword ptr [0x007bd7ec],ECX
    m.w32((0x007bd7ecu), s.cx);
  }
  L00470360: { // 0x470360: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00470362: { // 0x470362: 891508d87b00 MOV dword ptr [0x007bd808],EDX
    m.w32((0x007bd808u), s.dx);
  }
  L00470368: { // 0x470368: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L0047036a: { // 0x47036a: a30cd87b00 MOV [0x007bd80c],EAX
    m.w32((0x007bd80cu), s.ax);
  }
  L0047036f: { // 0x47036f: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00470371: { // 0x470371: 890d10d87b00 MOV dword ptr [0x007bd810],ECX
    m.w32((0x007bd810u), s.cx);
  }
  L00470377: { // 0x470377: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00470379: { // 0x470379: 891514d87b00 MOV dword ptr [0x007bd814],EDX
    m.w32((0x007bd814u), s.dx);
  }
  L0047037f: { // 0x47037f: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L00470381: { // 0x470381: a338d87b00 MOV [0x007bd838],EAX
    m.w32((0x007bd838u), s.ax);
  }
  L00470386: { // 0x470386: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00470388: { // 0x470388: 890d3cd87b00 MOV dword ptr [0x007bd83c],ECX
    m.w32((0x007bd83cu), s.cx);
  }
  L0047038e: { // 0x47038e: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00470390: { // 0x470390: 891560d87b00 MOV dword ptr [0x007bd860],EDX
    m.w32((0x007bd860u), s.dx);
  }
  L00470396: { // 0x470396: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L00470398: { // 0x470398: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L0047039a: { // 0x47039a: dd1d30d87b00 FSTP double ptr [0x007bd830]
    const auto address=(0x007bd830u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L004703a0: { // 0x4703a0: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L004703a2: { // 0x4703a2: c705a0d77b0000000000 MOV dword ptr [0x007bd7a0],0x0
    m.w32((0x007bd7a0u), 0x00000000u);
  }
  L004703ac: { // 0x4703ac: c705a4d77b0000000000 MOV dword ptr [0x007bd7a4],0x0
    m.w32((0x007bd7a4u), 0x00000000u);
  }
  L004703b6: { // 0x4703b6: c705a8d77b0000000000 MOV dword ptr [0x007bd7a8],0x0
    m.w32((0x007bd7a8u), 0x00000000u);
  }
  L004703c0: { // 0x4703c0: c705acd77b0000000000 MOV dword ptr [0x007bd7ac],0x0
    m.w32((0x007bd7acu), 0x00000000u);
  }
  L004703ca: { // 0x4703ca: c705b0d77b0000000000 MOV dword ptr [0x007bd7b0],0x0
    m.w32((0x007bd7b0u), 0x00000000u);
  }
  L004703d4: { // 0x4703d4: c705b4d77b000000f03f MOV dword ptr [0x007bd7b4],0x3ff00000
    m.w32((0x007bd7b4u), 0x3ff00000u);
  }
  L004703de: { // 0x4703de: c705b8d77b0000000000 MOV dword ptr [0x007bd7b8],0x0
    m.w32((0x007bd7b8u), 0x00000000u);
  }
  L004703e8: { // 0x4703e8: c705bcd77b0000000000 MOV dword ptr [0x007bd7bc],0x0
    m.w32((0x007bd7bcu), 0x00000000u);
  }
  L004703f2: { // 0x4703f2: c705c8d77b0000000000 MOV dword ptr [0x007bd7c8],0x0
    m.w32((0x007bd7c8u), 0x00000000u);
  }
  L004703fc: { // 0x4703fc: c705ccd77b0000000000 MOV dword ptr [0x007bd7cc],0x0
    m.w32((0x007bd7ccu), 0x00000000u);
  }
  L00470406: { // 0x470406: c705d0d77b0000000000 MOV dword ptr [0x007bd7d0],0x0
    m.w32((0x007bd7d0u), 0x00000000u);
  }
  L00470410: { // 0x470410: c705d4d77b000000f0bf MOV dword ptr [0x007bd7d4],0xbff00000
    m.w32((0x007bd7d4u), 0xbff00000u);
  }
  L0047041a: { // 0x47041a: c705d8d77b0000000000 MOV dword ptr [0x007bd7d8],0x0
    m.w32((0x007bd7d8u), 0x00000000u);
  }
  L00470424: { // 0x470424: c705dcd77b0000000000 MOV dword ptr [0x007bd7dc],0x0
    m.w32((0x007bd7dcu), 0x00000000u);
  }
  L0047042e: { // 0x47042e: c705f0d77b0000000000 MOV dword ptr [0x007bd7f0],0x0
    m.w32((0x007bd7f0u), 0x00000000u);
  }
  L00470438: { // 0x470438: c705f4d77b0000000000 MOV dword ptr [0x007bd7f4],0x0
    m.w32((0x007bd7f4u), 0x00000000u);
  }
  L00470442: { // 0x470442: c705f8d77b0000000000 MOV dword ptr [0x007bd7f8],0x0
    m.w32((0x007bd7f8u), 0x00000000u);
  }
  L0047044c: { // 0x47044c: c705fcd77b0000000000 MOV dword ptr [0x007bd7fc],0x0
    m.w32((0x007bd7fcu), 0x00000000u);
  }
  L00470456: { // 0x470456: c70500d87b0000000000 MOV dword ptr [0x007bd800],0x0
    m.w32((0x007bd800u), 0x00000000u);
  }
  L00470460: { // 0x470460: c70504d87b000000f0bf MOV dword ptr [0x007bd804],0xbff00000
    m.w32((0x007bd804u), 0xbff00000u);
  }
  L0047046a: { // 0x47046a: c70518d87b0000000000 MOV dword ptr [0x007bd818],0x0
    m.w32((0x007bd818u), 0x00000000u);
  }
  L00470474: { // 0x470474: c7051cd87b0000000000 MOV dword ptr [0x007bd81c],0x0
    m.w32((0x007bd81cu), 0x00000000u);
  }
  L0047047e: { // 0x47047e: c70520d87b0000000000 MOV dword ptr [0x007bd820],0x0
    m.w32((0x007bd820u), 0x00000000u);
  }
  L00470488: { // 0x470488: c70524d87b000000f03f MOV dword ptr [0x007bd824],0x3ff00000
    m.w32((0x007bd824u), 0x3ff00000u);
  }
  L00470492: { // 0x470492: c70528d87b0000000000 MOV dword ptr [0x007bd828],0x0
    m.w32((0x007bd828u), 0x00000000u);
  }
  L0047049c: { // 0x47049c: c7052cd87b000000f03f MOV dword ptr [0x007bd82c],0x3ff00000
    m.w32((0x007bd82cu), 0x3ff00000u);
  }
  L004704a6: { // 0x4704a6: c70540d87b0000000000 MOV dword ptr [0x007bd840],0x0
    m.w32((0x007bd840u), 0x00000000u);
  }
  L004704b0: { // 0x4704b0: c70544d87b0000000000 MOV dword ptr [0x007bd844],0x0
    m.w32((0x007bd844u), 0x00000000u);
  }
  L004704ba: { // 0x4704ba: c70548d87b0000000000 MOV dword ptr [0x007bd848],0x0
    m.w32((0x007bd848u), 0x00000000u);
  }
  L004704c4: { // 0x4704c4: c7054cd87b000000f0bf MOV dword ptr [0x007bd84c],0xbff00000
    m.w32((0x007bd84cu), 0xbff00000u);
  }
  L004704ce: { // 0x4704ce: c70550d87b0000000000 MOV dword ptr [0x007bd850],0x0
    m.w32((0x007bd850u), 0x00000000u);
  }
  L004704d8: { // 0x4704d8: c70554d87b000000f03f MOV dword ptr [0x007bd854],0x3ff00000
    m.w32((0x007bd854u), 0x3ff00000u);
  }
  L004704e2: { // 0x4704e2: c70558d87b0000000000 MOV dword ptr [0x007bd858],0x0
    m.w32((0x007bd858u), 0x00000000u);
  }
  L004704ec: { // 0x4704ec: c7055cd87b0000000000 MOV dword ptr [0x007bd85c],0x0
    m.w32((0x007bd85cu), 0x00000000u);
  }
  L004704f6: { // 0x4704f6: a364d87b00 MOV [0x007bd864],EAX
    m.w32((0x007bd864u), s.ax);
  }
  L004704fb: { // 0x4704fb: c70568d87b0000000000 MOV dword ptr [0x007bd868],0x0
    m.w32((0x007bd868u), 0x00000000u);
  }
  L00470505: { // 0x470505: c7056cd87b0000000000 MOV dword ptr [0x007bd86c],0x0
    m.w32((0x007bd86cu), 0x00000000u);
  }
  L0047050f: { // 0x47050f: c70570d87b0000000000 MOV dword ptr [0x007bd870],0x0
    m.w32((0x007bd870u), 0x00000000u);
  }
  L00470519: { // 0x470519: c70574d87b000000f0bf MOV dword ptr [0x007bd874],0xbff00000
    m.w32((0x007bd874u), 0xbff00000u);
  }
  L00470523: { // 0x470523: c70578d87b0000000000 MOV dword ptr [0x007bd878],0x0
    m.w32((0x007bd878u), 0x00000000u);
  }
  L0047052d: { // 0x47052d: c7057cd87b000000f0bf MOV dword ptr [0x007bd87c],0xbff00000
    m.w32((0x007bd87cu), 0xbff00000u);
  }
  L00470537: { // 0x470537: 890d80d87b00 MOV dword ptr [0x007bd880],ECX
    m.w32((0x007bd880u), s.cx);
  }
  L0047053d: { // 0x47053d: 891584d87b00 MOV dword ptr [0x007bd884],EDX
    m.w32((0x007bd884u), s.dx);
  }
  L00470543: { // 0x470543: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00470545: { // 0x470545: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L00470547: { // 0x470547: a388d87b00 MOV [0x007bd888],EAX
    m.w32((0x007bd888u), s.ax);
  }
  L0047054c: { // 0x47054c: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0047054e: { // 0x47054e: dd05f08e8300 FLD double ptr [0x00838ef0]
    const auto address=(0x00838ef0u);
    s.fp.load64(read64(m,address));
  }
  L00470554: { // 0x470554: 890d8cd87b00 MOV dword ptr [0x007bd88c],ECX
    m.w32((0x007bd88cu), s.cx);
  }
  L0047055a: { // 0x47055a: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0047055c: { // 0x47055c: 8915b0d87b00 MOV dword ptr [0x007bd8b0],EDX
    m.w32((0x007bd8b0u), s.dx);
  }
  L00470562: { // 0x470562: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L00470564: { // 0x470564: a3b4d87b00 MOV [0x007bd8b4],EAX
    m.w32((0x007bd8b4u), s.ax);
  }
  L00470569: { // 0x470569: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0047056b: { // 0x47056b: 890dd8d87b00 MOV dword ptr [0x007bd8d8],ECX
    m.w32((0x007bd8d8u), s.cx);
  }
  L00470571: { // 0x470571: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00470573: { // 0x470573: 8915dcd87b00 MOV dword ptr [0x007bd8dc],EDX
    m.w32((0x007bd8dcu), s.dx);
  }
  L00470579: { // 0x470579: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L0047057b: { // 0x47057b: a3f8d87b00 MOV [0x007bd8f8],EAX
    m.w32((0x007bd8f8u), s.ax);
  }
  L00470580: { // 0x470580: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00470582: { // 0x470582: 890dfcd87b00 MOV dword ptr [0x007bd8fc],ECX
    m.w32((0x007bd8fcu), s.cx);
  }
  L00470588: { // 0x470588: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0047058a: { // 0x47058a: 891500d97b00 MOV dword ptr [0x007bd900],EDX
    m.w32((0x007bd900u), s.dx);
  }
  L00470590: { // 0x470590: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L00470592: { // 0x470592: a304d97b00 MOV [0x007bd904],EAX
    m.w32((0x007bd904u), s.ax);
  }
  L00470597: { // 0x470597: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00470599: { // 0x470599: dcc0 FADD ST0,ST0
    numeric_b88::detail::reg<0xdcc0>(s.fp);
  }
  L0047059b: { // 0x47059b: 890d28d97b00 MOV dword ptr [0x007bd928],ECX
    m.w32((0x007bd928u), s.cx);
  }
  L004705a1: { // 0x4705a1: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004705a3: { // 0x4705a3: 89152cd97b00 MOV dword ptr [0x007bd92c],EDX
    m.w32((0x007bd92cu), s.dx);
  }
  L004705a9: { // 0x4705a9: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L004705ab: { // 0x4705ab: a348d97b00 MOV [0x007bd948],EAX
    m.w32((0x007bd948u), s.ax);
  }
  L004705b0: { // 0x4705b0: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L004705b2: { // 0x4705b2: dd1520d97b00 FST double ptr [0x007bd920]
    const auto address=(0x007bd920u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L004705b8: { // 0x4705b8: dd1578d97b00 FST double ptr [0x007bd978]
    const auto address=(0x007bd978u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L004705be: { // 0x4705be: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004705c0: { // 0x4705c0: c70590d87b0000000000 MOV dword ptr [0x007bd890],0x0
    m.w32((0x007bd890u), 0x00000000u);
  }
  L004705ca: { // 0x4705ca: c70594d87b0000000000 MOV dword ptr [0x007bd894],0x0
    m.w32((0x007bd894u), 0x00000000u);
  }
  L004705d4: { // 0x4705d4: c70598d87b0000000000 MOV dword ptr [0x007bd898],0x0
    m.w32((0x007bd898u), 0x00000000u);
  }
  L004705de: { // 0x4705de: c7059cd87b000000f03f MOV dword ptr [0x007bd89c],0x3ff00000
    m.w32((0x007bd89cu), 0x3ff00000u);
  }
  L004705e8: { // 0x4705e8: c705a0d87b0000000000 MOV dword ptr [0x007bd8a0],0x0
    m.w32((0x007bd8a0u), 0x00000000u);
  }
  L004705f2: { // 0x4705f2: c705a4d87b000000f0bf MOV dword ptr [0x007bd8a4],0xbff00000
    m.w32((0x007bd8a4u), 0xbff00000u);
  }
  L004705fc: { // 0x4705fc: c705a8d87b0000000000 MOV dword ptr [0x007bd8a8],0x0
    m.w32((0x007bd8a8u), 0x00000000u);
  }
  L00470606: { // 0x470606: c705acd87b0000000000 MOV dword ptr [0x007bd8ac],0x0
    m.w32((0x007bd8acu), 0x00000000u);
  }
  L00470610: { // 0x470610: c705b8d87b0000000000 MOV dword ptr [0x007bd8b8],0x0
    m.w32((0x007bd8b8u), 0x00000000u);
  }
  L0047061a: { // 0x47061a: c705bcd87b0000000000 MOV dword ptr [0x007bd8bc],0x0
    m.w32((0x007bd8bcu), 0x00000000u);
  }
  L00470624: { // 0x470624: c705c0d87b0000000000 MOV dword ptr [0x007bd8c0],0x0
    m.w32((0x007bd8c0u), 0x00000000u);
  }
  L0047062e: { // 0x47062e: c705c4d87b000000f03f MOV dword ptr [0x007bd8c4],0x3ff00000
    m.w32((0x007bd8c4u), 0x3ff00000u);
  }
  L00470638: { // 0x470638: c705c8d87b0000000000 MOV dword ptr [0x007bd8c8],0x0
    m.w32((0x007bd8c8u), 0x00000000u);
  }
  L00470642: { // 0x470642: c705ccd87b000000f03f MOV dword ptr [0x007bd8cc],0x3ff00000
    m.w32((0x007bd8ccu), 0x3ff00000u);
  }
  L0047064c: { // 0x47064c: c705d0d87b0000000000 MOV dword ptr [0x007bd8d0],0x0
    m.w32((0x007bd8d0u), 0x00000000u);
  }
  L00470656: { // 0x470656: c705d4d87b0000000000 MOV dword ptr [0x007bd8d4],0x0
    m.w32((0x007bd8d4u), 0x00000000u);
  }
  L00470660: { // 0x470660: c705e0d87b0000000000 MOV dword ptr [0x007bd8e0],0x0
    m.w32((0x007bd8e0u), 0x00000000u);
  }
  L0047066a: { // 0x47066a: c705e4d87b0000000000 MOV dword ptr [0x007bd8e4],0x0
    m.w32((0x007bd8e4u), 0x00000000u);
  }
  L00470674: { // 0x470674: c705e8d87b0000000000 MOV dword ptr [0x007bd8e8],0x0
    m.w32((0x007bd8e8u), 0x00000000u);
  }
  L0047067e: { // 0x47067e: c705ecd87b000000f0bf MOV dword ptr [0x007bd8ec],0xbff00000
    m.w32((0x007bd8ecu), 0xbff00000u);
  }
  L00470688: { // 0x470688: c705f0d87b0000000000 MOV dword ptr [0x007bd8f0],0x0
    m.w32((0x007bd8f0u), 0x00000000u);
  }
  L00470692: { // 0x470692: c705f4d87b000000f03f MOV dword ptr [0x007bd8f4],0x3ff00000
    m.w32((0x007bd8f4u), 0x3ff00000u);
  }
  L0047069c: { // 0x47069c: c70508d97b0000000000 MOV dword ptr [0x007bd908],0x0
    m.w32((0x007bd908u), 0x00000000u);
  }
  L004706a6: { // 0x4706a6: c7050cd97b0000000000 MOV dword ptr [0x007bd90c],0x0
    m.w32((0x007bd90cu), 0x00000000u);
  }
  L004706b0: { // 0x4706b0: c70510d97b0000000000 MOV dword ptr [0x007bd910],0x0
    m.w32((0x007bd910u), 0x00000000u);
  }
  L004706ba: { // 0x4706ba: c70514d97b000000f0bf MOV dword ptr [0x007bd914],0xbff00000
    m.w32((0x007bd914u), 0xbff00000u);
  }
  L004706c4: { // 0x4706c4: c70518d97b0000000000 MOV dword ptr [0x007bd918],0x0
    m.w32((0x007bd918u), 0x00000000u);
  }
  L004706ce: { // 0x4706ce: c7051cd97b000000f0bf MOV dword ptr [0x007bd91c],0xbff00000
    m.w32((0x007bd91cu), 0xbff00000u);
  }
  L004706d8: { // 0x4706d8: c70530d97b0000000000 MOV dword ptr [0x007bd930],0x0
    m.w32((0x007bd930u), 0x00000000u);
  }
  L004706e2: { // 0x4706e2: c70534d97b0000000000 MOV dword ptr [0x007bd934],0x0
    m.w32((0x007bd934u), 0x00000000u);
  }
  L004706ec: { // 0x4706ec: c70538d97b0000000000 MOV dword ptr [0x007bd938],0x0
    m.w32((0x007bd938u), 0x00000000u);
  }
  L004706f6: { // 0x4706f6: c7053cd97b000000f03f MOV dword ptr [0x007bd93c],0x3ff00000
    m.w32((0x007bd93cu), 0x3ff00000u);
  }
  L00470700: { // 0x470700: c70540d97b0000000000 MOV dword ptr [0x007bd940],0x0
    m.w32((0x007bd940u), 0x00000000u);
  }
  L0047070a: { // 0x47070a: c70544d97b000000f0bf MOV dword ptr [0x007bd944],0xbff00000
    m.w32((0x007bd944u), 0xbff00000u);
  }
  L00470714: { // 0x470714: 890d4cd97b00 MOV dword ptr [0x007bd94c],ECX
    m.w32((0x007bd94cu), s.cx);
  }
  L0047071a: { // 0x47071a: 891550d97b00 MOV dword ptr [0x007bd950],EDX
    m.w32((0x007bd950u), s.dx);
  }
  L00470720: { // 0x470720: a354d97b00 MOV [0x007bd954],EAX
    m.w32((0x007bd954u), s.ax);
  }
  L00470725: { // 0x470725: c70558d97b0000000000 MOV dword ptr [0x007bd958],0x0
    m.w32((0x007bd958u), 0x00000000u);
  }
  L0047072f: { // 0x47072f: c7055cd97b0000000000 MOV dword ptr [0x007bd95c],0x0
    m.w32((0x007bd95cu), 0x00000000u);
  }
  L00470739: { // 0x470739: c70560d97b0000000000 MOV dword ptr [0x007bd960],0x0
    m.w32((0x007bd960u), 0x00000000u);
  }
  L00470743: { // 0x470743: c70564d97b000000f03f MOV dword ptr [0x007bd964],0x3ff00000
    m.w32((0x007bd964u), 0x3ff00000u);
  }
  L0047074d: { // 0x47074d: c70568d97b0000000000 MOV dword ptr [0x007bd968],0x0
    m.w32((0x007bd968u), 0x00000000u);
  }
  L00470757: { // 0x470757: c7056cd97b000000f03f MOV dword ptr [0x007bd96c],0x3ff00000
    m.w32((0x007bd96cu), 0x3ff00000u);
  }
  L00470761: { // 0x470761: c70570d97b0000000000 MOV dword ptr [0x007bd970],0x0
    m.w32((0x007bd970u), 0x00000000u);
  }
  L0047076b: { // 0x47076b: c70574d97b0000000000 MOV dword ptr [0x007bd974],0x0
    m.w32((0x007bd974u), 0x00000000u);
  }
  L00470775: { // 0x470775: c70580d97b0000000000 MOV dword ptr [0x007bd980],0x0
    m.w32((0x007bd980u), 0x00000000u);
  }
  L0047077f: { // 0x47077f: c70584d97b0000000000 MOV dword ptr [0x007bd984],0x0
    m.w32((0x007bd984u), 0x00000000u);
  }
  L00470789: { // 0x470789: c70588d97b0000000000 MOV dword ptr [0x007bd988],0x0
    m.w32((0x007bd988u), 0x00000000u);
  }
  L00470793: { // 0x470793: dd15a0d97b00 FST double ptr [0x007bd9a0]
    const auto address=(0x007bd9a0u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L00470799: { // 0x470799: dd15c0d97b00 FST double ptr [0x007bd9c0]
    const auto address=(0x007bd9c0u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L0047079f: { // 0x47079f: dd15c8d97b00 FST double ptr [0x007bd9c8]
    const auto address=(0x007bd9c8u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L004707a5: { // 0x4707a5: dd1df0d97b00 FSTP double ptr [0x007bd9f0]
    const auto address=(0x007bd9f0u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L004707ab: { // 0x4707ab: dd05f08e8300 FLD double ptr [0x00838ef0]
    const auto address=(0x00838ef0u);
    s.fp.load64(read64(m,address));
  }
  L004707b1: { // 0x4707b1: dc0d28577800 FMUL double ptr [0x00785728]
    const auto address=(0x00785728u);
    s.fp.multiply64(read64(m,address));
  }
  L004707b7: { // 0x4707b7: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L004707b9: { // 0x4707b9: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L004707bb: { // 0x4707bb: 890d98d97b00 MOV dword ptr [0x007bd998],ECX
    m.w32((0x007bd998u), s.cx);
  }
  L004707c1: { // 0x4707c1: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004707c3: { // 0x4707c3: 89159cd97b00 MOV dword ptr [0x007bd99c],EDX
    m.w32((0x007bd99cu), s.dx);
  }
  L004707c9: { // 0x4707c9: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L004707cb: { // 0x4707cb: dd1518da7b00 FST double ptr [0x007bda18]
    const auto address=(0x007bda18u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L004707d1: { // 0x4707d1: dd1520da7b00 FST double ptr [0x007bda20]
    const auto address=(0x007bda20u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L004707d7: { // 0x4707d7: dd1540da7b00 FST double ptr [0x007bda40]
    const auto address=(0x007bda40u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L004707dd: { // 0x4707dd: dd05f08e8300 FLD double ptr [0x00838ef0]
    const auto address=(0x00838ef0u);
    s.fp.load64(read64(m,address));
  }
  L004707e3: { // 0x4707e3: dc0db0797800 FMUL double ptr [0x007879b0]
    const auto address=(0x007879b0u);
    s.fp.multiply64(read64(m,address));
  }
  L004707e9: { // 0x4707e9: a3e8d97b00 MOV [0x007bd9e8],EAX
    m.w32((0x007bd9e8u), s.ax);
  }
  L004707ee: { // 0x4707ee: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L004707f0: { // 0x4707f0: 890decd97b00 MOV dword ptr [0x007bd9ec],ECX
    m.w32((0x007bd9ecu), s.cx);
  }
  L004707f6: { // 0x4707f6: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004707f8: { // 0x4707f8: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L004707fa: { // 0x4707fa: 891538da7b00 MOV dword ptr [0x007bda38],EDX
    m.w32((0x007bda38u), s.dx);
  }
  L00470800: { // 0x470800: dd542408 FST double ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L00470804: { // 0x470804: dd1d48da7b00 FSTP double ptr [0x007bda48]
    const auto address=(0x007bda48u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0047080a: { // 0x47080a: a33cda7b00 MOV [0x007bda3c],EAX
    m.w32((0x007bda3cu), s.ax);
  }
  L0047080f: { // 0x47080f: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00470811: { // 0x470811: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L00470815: { // 0x470815: 890d88da7b00 MOV dword ptr [0x007bda88],ECX
    m.w32((0x007bda88u), s.cx);
  }
  L0047081b: { // 0x47081b: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L0047081f: { // 0x47081f: c7058cd97b000000f0bf MOV dword ptr [0x007bd98c],0xbff00000
    m.w32((0x007bd98cu), 0xbff00000u);
  }
  L00470829: { // 0x470829: dd1568da7b00 FST double ptr [0x007bda68]
    const auto address=(0x007bda68u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L0047082f: { // 0x47082f: dd1570da7b00 FST double ptr [0x007bda70]
    const auto address=(0x007bda70u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L00470835: { // 0x470835: dd1d90da7b00 FSTP double ptr [0x007bda90]
    const auto address=(0x007bda90u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0047083b: { // 0x47083b: c70590d97b0000000000 MOV dword ptr [0x007bd990],0x0
    m.w32((0x007bd990u), 0x00000000u);
  }
  L00470845: { // 0x470845: c70594d97b000000f03f MOV dword ptr [0x007bd994],0x3ff00000
    m.w32((0x007bd994u), 0x3ff00000u);
  }
  L0047084f: { // 0x47084f: c705a8d97b0000000000 MOV dword ptr [0x007bd9a8],0x0
    m.w32((0x007bd9a8u), 0x00000000u);
  }
  L00470859: { // 0x470859: c705acd97b0000000000 MOV dword ptr [0x007bd9ac],0x0
    m.w32((0x007bd9acu), 0x00000000u);
  }
  L00470863: { // 0x470863: c705b0d97b0000000000 MOV dword ptr [0x007bd9b0],0x0
    m.w32((0x007bd9b0u), 0x00000000u);
  }
  L0047086d: { // 0x47086d: c705b4d97b000000f0bf MOV dword ptr [0x007bd9b4],0xbff00000
    m.w32((0x007bd9b4u), 0xbff00000u);
  }
  L00470877: { // 0x470877: c705b8d97b0000000000 MOV dword ptr [0x007bd9b8],0x0
    m.w32((0x007bd9b8u), 0x00000000u);
  }
  L00470881: { // 0x470881: c705bcd97b000000f0bf MOV dword ptr [0x007bd9bc],0xbff00000
    m.w32((0x007bd9bcu), 0xbff00000u);
  }
  L0047088b: { // 0x47088b: c705d0d97b0000000000 MOV dword ptr [0x007bd9d0],0x0
    m.w32((0x007bd9d0u), 0x00000000u);
  }
  L00470895: { // 0x470895: c705d4d97b0000000000 MOV dword ptr [0x007bd9d4],0x0
    m.w32((0x007bd9d4u), 0x00000000u);
  }
  L0047089f: { // 0x47089f: c705d8d97b0000000000 MOV dword ptr [0x007bd9d8],0x0
    m.w32((0x007bd9d8u), 0x00000000u);
  }
  L004708a9: { // 0x4708a9: c705dcd97b000000f03f MOV dword ptr [0x007bd9dc],0x3ff00000
    m.w32((0x007bd9dcu), 0x3ff00000u);
  }
  L004708b3: { // 0x4708b3: c705e0d97b0000000000 MOV dword ptr [0x007bd9e0],0x0
    m.w32((0x007bd9e0u), 0x00000000u);
  }
  L004708bd: { // 0x4708bd: c705e4d97b000000f0bf MOV dword ptr [0x007bd9e4],0xbff00000
    m.w32((0x007bd9e4u), 0xbff00000u);
  }
  L004708c7: { // 0x4708c7: c705f8d97b0000000000 MOV dword ptr [0x007bd9f8],0x0
    m.w32((0x007bd9f8u), 0x00000000u);
  }
  L004708d1: { // 0x4708d1: c705fcd97b0000000000 MOV dword ptr [0x007bd9fc],0x0
    m.w32((0x007bd9fcu), 0x00000000u);
  }
  L004708db: { // 0x4708db: c70500da7b0000000000 MOV dword ptr [0x007bda00],0x0
    m.w32((0x007bda00u), 0x00000000u);
  }
  L004708e5: { // 0x4708e5: c70504da7b0000000000 MOV dword ptr [0x007bda04],0x0
    m.w32((0x007bda04u), 0x00000000u);
  }
  L004708ef: { // 0x4708ef: c70508da7b0000000000 MOV dword ptr [0x007bda08],0x0
    m.w32((0x007bda08u), 0x00000000u);
  }
  L004708f9: { // 0x4708f9: c7050cda7b0000000000 MOV dword ptr [0x007bda0c],0x0
    m.w32((0x007bda0cu), 0x00000000u);
  }
  L00470903: { // 0x470903: c70510da7b0000000000 MOV dword ptr [0x007bda10],0x0
    m.w32((0x007bda10u), 0x00000000u);
  }
  L0047090d: { // 0x47090d: c70514da7b0000000000 MOV dword ptr [0x007bda14],0x0
    m.w32((0x007bda14u), 0x00000000u);
  }
  L00470917: { // 0x470917: c70528da7b0000000000 MOV dword ptr [0x007bda28],0x0
    m.w32((0x007bda28u), 0x00000000u);
  }
  L00470921: { // 0x470921: c7052cda7b0000000000 MOV dword ptr [0x007bda2c],0x0
    m.w32((0x007bda2cu), 0x00000000u);
  }
  L0047092b: { // 0x47092b: c70530da7b0000000000 MOV dword ptr [0x007bda30],0x0
    m.w32((0x007bda30u), 0x00000000u);
  }
  L00470935: { // 0x470935: c70534da7b0000000000 MOV dword ptr [0x007bda34],0x0
    m.w32((0x007bda34u), 0x00000000u);
  }
  L0047093f: { // 0x47093f: c70550da7b0000000000 MOV dword ptr [0x007bda50],0x0
    m.w32((0x007bda50u), 0x00000000u);
  }
  L00470949: { // 0x470949: c70554da7b0000000000 MOV dword ptr [0x007bda54],0x0
    m.w32((0x007bda54u), 0x00000000u);
  }
  L00470953: { // 0x470953: c70558da7b0000000000 MOV dword ptr [0x007bda58],0x0
    m.w32((0x007bda58u), 0x00000000u);
  }
  L0047095d: { // 0x47095d: c7055cda7b0000000000 MOV dword ptr [0x007bda5c],0x0
    m.w32((0x007bda5cu), 0x00000000u);
  }
  L00470967: { // 0x470967: c70560da7b0000000000 MOV dword ptr [0x007bda60],0x0
    m.w32((0x007bda60u), 0x00000000u);
  }
  L00470971: { // 0x470971: c70564da7b0000000000 MOV dword ptr [0x007bda64],0x0
    m.w32((0x007bda64u), 0x00000000u);
  }
  L0047097b: { // 0x47097b: c70578da7b0000000000 MOV dword ptr [0x007bda78],0x0
    m.w32((0x007bda78u), 0x00000000u);
  }
  L00470985: { // 0x470985: c7057cda7b0000000000 MOV dword ptr [0x007bda7c],0x0
    m.w32((0x007bda7cu), 0x00000000u);
  }
  L0047098f: { // 0x47098f: c70580da7b0000000000 MOV dword ptr [0x007bda80],0x0
    m.w32((0x007bda80u), 0x00000000u);
  }
  L00470999: { // 0x470999: c70584da7b0000000000 MOV dword ptr [0x007bda84],0x0
    m.w32((0x007bda84u), 0x00000000u);
  }
  L004709a3: { // 0x4709a3: 89158cda7b00 MOV dword ptr [0x007bda8c],EDX
    m.w32((0x007bda8cu), s.dx);
  }
  L004709a9: { // 0x4709a9: a398da7b00 MOV [0x007bda98],EAX
    m.w32((0x007bda98u), s.ax);
  }
  L004709ae: { // 0x4709ae: 890d9cda7b00 MOV dword ptr [0x007bda9c],ECX
    m.w32((0x007bda9cu), s.cx);
  }
  L004709b4: { // 0x4709b4: 0fbe961b010000 MOVSX EDX,byte ptr [ESI + 0x11b]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.si+0x0000011bu)),8));
  }
  L004709bb: { // 0x4709bb: 0faf15808f8300 IMUL EDX,dword ptr [0x00838f80]
    s.dx = integer::imul(s.dx,m.r32((0x00838f80u)),32,flags);
  }
  L004709c2: { // 0x4709c2: 89542404 MOV dword ptr [ESP + 0x4],EDX
    m.w32((f.sp+0x00000004u), s.dx);
  }
  L004709c6: { // 0x4709c6: db442404 FILD dword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load_integer32(m.r32(address));
  }
  L004709ca: { // 0x4709ca: dc0528577800 FADD double ptr [0x00785728]
    const auto address=(0x00785728u);
    s.fp.add64(read64(m,address));
  }
  L004709d0: { // 0x4709d0: e87ba02f00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4655573u); flags=s.arithmetic_flags;
  }
  L004709d5: { // 0x4709d5: 8a8e1c010000 MOV CL,byte ptr [ESI + 0x11c]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000011cu)));
  }
  L004709db: { // 0x4709db: 89442408 MOV dword ptr [ESP + 0x8],EAX
    m.w32((f.sp+0x00000008u), s.ax);
  }
  L004709df: { // 0x4709df: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004709e1: { // 0x4709e1: 0f868d000000 JBE 0x00470a74
    if(integer::condition("JBE",flags)) goto L00470a74;
  }
  L004709e7: { // 0x4709e7: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L004709ea: { // 0x4709ea: 81e1ff000000 AND ECX,0xff
    s.cx = integer::logical((s.cx)&(0x000000ffu),32,flags);
  }
  L004709f0: { // 0x4709f0: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L004709f1: { // 0x4709f1: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L004709f4: { // 0x4709f4: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L004709f6: { // 0x4709f6: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L004709fc: { // 0x4709fc: 8d0c89 LEA ECX,[ECX + ECX*0x4]
    s.cx = (s.cx+(s.cx * 0x00000004u));
  }
  L004709ff: { // 0x4709ff: 89542404 MOV dword ptr [ESP + 0x4],EDX
    m.w32((f.sp+0x00000004u), s.dx);
  }
  L00470a03: { // 0x470a03: 25ff000000 AND EAX,0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  L00470a08: { // 0x470a08: db442404 FILD dword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load_integer32(m.r32(address));
  }
  L00470a0c: { // 0x470a0c: c1e103 SHL ECX,0x3
    s.cx = integer::shift(s.cx,0x00000003u,32,flags,integer::Shift::left);
  }
  L00470a0f: { // 0x470a0f: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  L00470a13: { // 0x470a13: dc8988d77b00 FMUL double ptr [ECX + 0x7bd788]
    const auto address=(s.cx+0x007bd788u);
    s.fp.multiply64(read64(m,address));
  }
  L00470a19: { // 0x470a19: dc0d108f8300 FMUL double ptr [0x00838f10]
    const auto address=(0x00838f10u);
    s.fp.multiply64(read64(m,address));
  }
  L00470a1f: { // 0x470a1f: db442404 FILD dword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load_integer32(m.r32(address));
  }
  L00470a23: { // 0x470a23: dc8980d77b00 FMUL double ptr [ECX + 0x7bd780]
    const auto address=(s.cx+0x007bd780u);
    s.fp.multiply64(read64(m,address));
  }
  L00470a29: { // 0x470a29: dc0d108f8300 FMUL double ptr [0x00838f10]
    const auto address=(0x00838f10u);
    s.fp.multiply64(read64(m,address));
  }
  L00470a2f: { // 0x470a2f: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L00470a31: { // 0x470a31: dc8190d77b00 FADD double ptr [ECX + 0x7bd790]
    const auto address=(s.cx+0x007bd790u);
    s.fp.add64(read64(m,address));
  }
  L00470a37: { // 0x470a37: dc81a0d77b00 FADD double ptr [ECX + 0x7bd7a0]
    const auto address=(s.cx+0x007bd7a0u);
    s.fp.add64(read64(m,address));
  }
  L00470a3d: { // 0x470a3d: dc1510667800 FCOM double ptr [0x00786610]
    const auto address=(0x00786610u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L00470a43: { // 0x470a43: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00470a45: { // 0x470a45: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00470a48: { // 0x470a48: 7408 JZ 0x00470a52
    if(integer::condition("JZ",flags)) goto L00470a52;
  }
  L00470a4a: { // 0x470a4a: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00470a4c: { // 0x470a4c: dd0510667800 FLD double ptr [0x00786610]
    const auto address=(0x00786610u);
    s.fp.load64(read64(m,address));
  }
  L00470a52: { // 0x470a52: dc9198d77b00 FCOM double ptr [ECX + 0x7bd798]
    const auto address=(s.cx+0x007bd798u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L00470a58: { // 0x470a58: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00470a5a: { // 0x470a5a: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L00470a5d: { // 0x470a5d: 7508 JNZ 0x00470a67
    if(integer::condition("JNZ",flags)) goto L00470a67;
  }
  L00470a5f: { // 0x470a5f: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00470a61: { // 0x470a61: dd8198d77b00 FLD double ptr [ECX + 0x7bd798]
    const auto address=(s.cx+0x007bd798u);
    s.fp.load64(read64(m,address));
  }
  L00470a67: { // 0x470a67: db442408 FILD dword ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.load_integer32(m.r32(address));
  }
  L00470a6b: { // 0x470a6b: d8c1 FADD ST0,ST1
    numeric_b88::detail::reg<0xd8c1>(s.fp);
  }
  L00470a6d: { // 0x470a6d: e8de9f2f00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4655730u); flags=s.arithmetic_flags;
  }
  L00470a72: { // 0x470a72: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00470a74: { // 0x470a74: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00470a75: { // 0x470a75: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L00470a77: { // 0x470a77: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00470a78: { // 0x470a78: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0029e380(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0069e380: { // 0x69e380: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0069e381: { // 0x69e381: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0069e382: { // 0x69e382: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0069e383: { // 0x69e383: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L0069e387: { // 0x69e387: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0069e388: { // 0x69e388: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0069e389: { // 0x69e389: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e38e: { // 0x69e38e: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L0069e390: { // 0x69e390: 83cfff OR EDI,0xffffffff
    s.di = integer::logical((s.di)|(0xffffffffu),32,flags);
  }
  L0069e393: { // 0x69e393: e86871eaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6939544u); flags=s.arithmetic_flags;
  }
  L0069e398: { // 0x69e398: 8a4c2418 MOV CL,byte ptr [ESP + 0x18]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000018u)));
  }
  L0069e39c: { // 0x69e39c: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0069e39e: { // 0x69e39e: 0f84d0010000 JZ 0x0069e574
    if(integer::condition("JZ",flags)) goto L0069e574;
  }
  L0069e3a4: { // 0x69e3a4: 8b8040010000 MOV EAX,dword ptr [EAX + 0x140]
    s.ax = m.r32((s.ax+0x00000140u));
  }
  L0069e3aa: { // 0x69e3aa: a803 TEST AL,0x3
    (void)integer::logical(((s.ax & 0xffu))&(0x00000003u),8,flags);
  }
  L0069e3ac: { // 0x69e3ac: 7505 JNZ 0x0069e3b3
    if(integer::condition("JNZ",flags)) goto L0069e3b3;
  }
  L0069e3ae: { // 0x69e3ae: bffeffffff MOV EDI,0xfffffffe
    s.di = 0xfffffffeu;
  }
  L0069e3b3: { // 0x69e3b3: bb02000000 MOV EBX,0x2
    s.bx = 0x00000002u;
  }
  L0069e3b8: { // 0x69e3b8: 84c3 TEST BL,AL
    (void)integer::logical(((s.bx & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0069e3ba: { // 0x69e3ba: 0f8494030000 JZ 0x0069e754
    if(integer::condition("JZ",flags)) goto L0069e754;
  }
  L0069e3c0: { // 0x69e3c0: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0069e3c3: { // 0x69e3c3: 668b4e02 MOV CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000002u)));
  }
  L0069e3c7: { // 0x69e3c7: 6648 DEC AX
    s.ax = with_ax(s.ax, integer::decrement((s.ax & 0xffffu),16,flags));
  }
  L0069e3c9: { // 0x69e3c9: 6649 DEC CX
    s.cx = with_ax(s.cx, integer::decrement((s.cx & 0xffffu),16,flags));
  }
  L0069e3cb: { // 0x69e3cb: 6689442418 MOV word ptr [ESP + 0x18],AX
    m.w16((f.sp+0x00000018u), (s.ax & 0xffffu));
  }
  L0069e3d0: { // 0x69e3d0: 66894c241a MOV word ptr [ESP + 0x1a],CX
    m.w16((f.sp+0x0000001au), (s.cx & 0xffffu));
  }
  L0069e3d5: { // 0x69e3d5: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0069e3d9: { // 0x69e3d9: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L0069e3dd: { // 0x69e3dd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0069e3de: { // 0x69e3de: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e3e3: { // 0x69e3e3: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L0069e3e7: { // 0x69e3e7: e81471eaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6939628u); flags=s.arithmetic_flags;
  }
  L0069e3ec: { // 0x69e3ec: 849840010000 TEST byte ptr [EAX + 0x140],BL
    (void)integer::logical((m.r8((s.ax+0x00000140u)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e3f2: { // 0x69e3f2: 7505 JNZ 0x0069e3f9
    if(integer::condition("JNZ",flags)) goto L0069e3f9;
  }
  L0069e3f4: { // 0x69e3f4: bd40000000 MOV EBP,0x40
    s.bp = 0x00000040u;
  }
  L0069e3f9: { // 0x69e3f9: 668b0e MOV CX,word ptr [ESI]
    s.cx = with_ax(s.cx, m.r16((s.si)));
  }
  L0069e3fc: { // 0x69e3fc: 668b5602 MOV DX,word ptr [ESI + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.si+0x00000002u)));
  }
  L0069e400: { // 0x69e400: 66894c2418 MOV word ptr [ESP + 0x18],CX
    m.w16((f.sp+0x00000018u), (s.cx & 0xffffu));
  }
  L0069e405: { // 0x69e405: 664a DEC DX
    s.dx = with_ax(s.dx, integer::decrement((s.dx & 0xffffu),16,flags));
  }
  L0069e407: { // 0x69e407: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0069e40b: { // 0x69e40b: 668954241a MOV word ptr [ESP + 0x1a],DX
    m.w16((f.sp+0x0000001au), (s.dx & 0xffffu));
  }
  L0069e410: { // 0x69e410: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0069e414: { // 0x69e414: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0069e415: { // 0x69e415: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e41a: { // 0x69e41a: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0069e41e: { // 0x69e41e: e8dd70eaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6939683u); flags=s.arithmetic_flags;
  }
  L0069e423: { // 0x69e423: 849840010000 TEST byte ptr [EAX + 0x140],BL
    (void)integer::logical((m.r8((s.ax+0x00000140u)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e429: { // 0x69e429: 7506 JNZ 0x0069e431
    if(integer::condition("JNZ",flags)) goto L0069e431;
  }
  L0069e42b: { // 0x69e42b: 81cd80000000 OR EBP,0x80
    s.bp = integer::logical((s.bp)|(0x00000080u),32,flags);
  }
  L0069e431: { // 0x69e431: 668b16 MOV DX,word ptr [ESI]
    s.dx = with_ax(s.dx, m.r16((s.si)));
  }
  L0069e434: { // 0x69e434: 668b4602 MOV AX,word ptr [ESI + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000002u)));
  }
  L0069e438: { // 0x69e438: 6642 INC DX
    s.dx = with_ax(s.dx, integer::increment((s.dx & 0xffffu),16,flags));
  }
  L0069e43a: { // 0x69e43a: 6648 DEC AX
    s.ax = with_ax(s.ax, integer::decrement((s.ax & 0xffffu),16,flags));
  }
  L0069e43c: { // 0x69e43c: 6689542418 MOV word ptr [ESP + 0x18],DX
    m.w16((f.sp+0x00000018u), (s.dx & 0xffffu));
  }
  L0069e441: { // 0x69e441: 668944241a MOV word ptr [ESP + 0x1a],AX
    m.w16((f.sp+0x0000001au), (s.ax & 0xffffu));
  }
  L0069e446: { // 0x69e446: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0069e44a: { // 0x69e44a: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L0069e44e: { // 0x69e44e: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0069e452: { // 0x69e452: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0069e453: { // 0x69e453: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e458: { // 0x69e458: e8a370eaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6939741u); flags=s.arithmetic_flags;
  }
  L0069e45d: { // 0x69e45d: 849840010000 TEST byte ptr [EAX + 0x140],BL
    (void)integer::logical((m.r8((s.ax+0x00000140u)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e463: { // 0x69e463: 7503 JNZ 0x0069e468
    if(integer::condition("JNZ",flags)) goto L0069e468;
  }
  L0069e465: { // 0x69e465: 83cd01 OR EBP,0x1
    s.bp = integer::logical((s.bp)|(0x00000001u),32,flags);
  }
  L0069e468: { // 0x69e468: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0069e46b: { // 0x69e46b: 668b4e02 MOV CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000002u)));
  }
  L0069e46f: { // 0x69e46f: 6648 DEC AX
    s.ax = with_ax(s.ax, integer::decrement((s.ax & 0xffffu),16,flags));
  }
  L0069e471: { // 0x69e471: 66894c241a MOV word ptr [ESP + 0x1a],CX
    m.w16((f.sp+0x0000001au), (s.cx & 0xffffu));
  }
  L0069e476: { // 0x69e476: 6689442418 MOV word ptr [ESP + 0x18],AX
    m.w16((f.sp+0x00000018u), (s.ax & 0xffffu));
  }
  L0069e47b: { // 0x69e47b: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0069e47f: { // 0x69e47f: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L0069e483: { // 0x69e483: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e488: { // 0x69e488: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0069e489: { // 0x69e489: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L0069e48d: { // 0x69e48d: e86e70eaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6939794u); flags=s.arithmetic_flags;
  }
  L0069e492: { // 0x69e492: 849840010000 TEST byte ptr [EAX + 0x140],BL
    (void)integer::logical((m.r8((s.ax+0x00000140u)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e498: { // 0x69e498: 7503 JNZ 0x0069e49d
    if(integer::condition("JNZ",flags)) goto L0069e49d;
  }
  L0069e49a: { // 0x69e49a: 83cd20 OR EBP,0x20
    s.bp = integer::logical((s.bp)|(0x00000020u),32,flags);
  }
  L0069e49d: { // 0x69e49d: 668b0e MOV CX,word ptr [ESI]
    s.cx = with_ax(s.cx, m.r16((s.si)));
  }
  L0069e4a0: { // 0x69e4a0: 668b5602 MOV DX,word ptr [ESI + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.si+0x00000002u)));
  }
  L0069e4a4: { // 0x69e4a4: 6641 INC CX
    s.cx = with_ax(s.cx, integer::increment((s.cx & 0xffffu),16,flags));
  }
  L0069e4a6: { // 0x69e4a6: 668954241a MOV word ptr [ESP + 0x1a],DX
    m.w16((f.sp+0x0000001au), (s.dx & 0xffffu));
  }
  L0069e4ab: { // 0x69e4ab: 66894c2418 MOV word ptr [ESP + 0x18],CX
    m.w16((f.sp+0x00000018u), (s.cx & 0xffffu));
  }
  L0069e4b0: { // 0x69e4b0: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0069e4b4: { // 0x69e4b4: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0069e4b8: { // 0x69e4b8: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0069e4bc: { // 0x69e4bc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0069e4bd: { // 0x69e4bd: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e4c2: { // 0x69e4c2: e83970eaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6939847u); flags=s.arithmetic_flags;
  }
  L0069e4c7: { // 0x69e4c7: 849840010000 TEST byte ptr [EAX + 0x140],BL
    (void)integer::logical((m.r8((s.ax+0x00000140u)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e4cd: { // 0x69e4cd: 7502 JNZ 0x0069e4d1
    if(integer::condition("JNZ",flags)) goto L0069e4d1;
  }
  L0069e4cf: { // 0x69e4cf: 0beb OR EBP,EBX
    s.bp = integer::logical((s.bp)|(s.bx),32,flags);
  }
  L0069e4d1: { // 0x69e4d1: 668b16 MOV DX,word ptr [ESI]
    s.dx = with_ax(s.dx, m.r16((s.si)));
  }
  L0069e4d4: { // 0x69e4d4: 668b4602 MOV AX,word ptr [ESI + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000002u)));
  }
  L0069e4d8: { // 0x69e4d8: 664a DEC DX
    s.dx = with_ax(s.dx, integer::decrement((s.dx & 0xffffu),16,flags));
  }
  L0069e4da: { // 0x69e4da: 6640 INC AX
    s.ax = with_ax(s.ax, integer::increment((s.ax & 0xffffu),16,flags));
  }
  L0069e4dc: { // 0x69e4dc: 6689542418 MOV word ptr [ESP + 0x18],DX
    m.w16((f.sp+0x00000018u), (s.dx & 0xffffu));
  }
  L0069e4e1: { // 0x69e4e1: 668944241a MOV word ptr [ESP + 0x1a],AX
    m.w16((f.sp+0x0000001au), (s.ax & 0xffffu));
  }
  L0069e4e6: { // 0x69e4e6: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0069e4ea: { // 0x69e4ea: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L0069e4ee: { // 0x69e4ee: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0069e4f2: { // 0x69e4f2: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0069e4f3: { // 0x69e4f3: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e4f8: { // 0x69e4f8: e80370eaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6939901u); flags=s.arithmetic_flags;
  }
  L0069e4fd: { // 0x69e4fd: 849840010000 TEST byte ptr [EAX + 0x140],BL
    (void)integer::logical((m.r8((s.ax+0x00000140u)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e503: { // 0x69e503: 7503 JNZ 0x0069e508
    if(integer::condition("JNZ",flags)) goto L0069e508;
  }
  L0069e505: { // 0x69e505: 83cd10 OR EBP,0x10
    s.bp = integer::logical((s.bp)|(0x00000010u),32,flags);
  }
  L0069e508: { // 0x69e508: 668b4e02 MOV CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000002u)));
  }
  L0069e50c: { // 0x69e50c: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0069e50f: { // 0x69e50f: 6641 INC CX
    s.cx = with_ax(s.cx, integer::increment((s.cx & 0xffffu),16,flags));
  }
  L0069e511: { // 0x69e511: 6689442418 MOV word ptr [ESP + 0x18],AX
    m.w16((f.sp+0x00000018u), (s.ax & 0xffffu));
  }
  L0069e516: { // 0x69e516: 66894c241a MOV word ptr [ESP + 0x1a],CX
    m.w16((f.sp+0x0000001au), (s.cx & 0xffffu));
  }
  L0069e51b: { // 0x69e51b: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0069e51f: { // 0x69e51f: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L0069e523: { // 0x69e523: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e528: { // 0x69e528: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0069e529: { // 0x69e529: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L0069e52d: { // 0x69e52d: e8ce6feaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6939954u); flags=s.arithmetic_flags;
  }
  L0069e532: { // 0x69e532: 849840010000 TEST byte ptr [EAX + 0x140],BL
    (void)integer::logical((m.r8((s.ax+0x00000140u)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e538: { // 0x69e538: 7503 JNZ 0x0069e53d
    if(integer::condition("JNZ",flags)) goto L0069e53d;
  }
  L0069e53a: { // 0x69e53a: 83cd08 OR EBP,0x8
    s.bp = integer::logical((s.bp)|(0x00000008u),32,flags);
  }
  L0069e53d: { // 0x69e53d: 668b0e MOV CX,word ptr [ESI]
    s.cx = with_ax(s.cx, m.r16((s.si)));
  }
  L0069e540: { // 0x69e540: 668b5602 MOV DX,word ptr [ESI + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.si+0x00000002u)));
  }
  L0069e544: { // 0x69e544: 6641 INC CX
    s.cx = with_ax(s.cx, integer::increment((s.cx & 0xffffu),16,flags));
  }
  L0069e546: { // 0x69e546: 6642 INC DX
    s.dx = with_ax(s.dx, integer::increment((s.dx & 0xffffu),16,flags));
  }
  L0069e548: { // 0x69e548: 66894c2418 MOV word ptr [ESP + 0x18],CX
    m.w16((f.sp+0x00000018u), (s.cx & 0xffffu));
  }
  L0069e54d: { // 0x69e54d: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0069e551: { // 0x69e551: 668954241a MOV word ptr [ESP + 0x1a],DX
    m.w16((f.sp+0x0000001au), (s.dx & 0xffffu));
  }
  L0069e556: { // 0x69e556: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0069e55a: { // 0x69e55a: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0069e55b: { // 0x69e55b: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e560: { // 0x69e560: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0069e564: { // 0x69e564: e8976feaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6940009u); flags=s.arithmetic_flags;
  }
  L0069e569: { // 0x69e569: 8a8840010000 MOV CL,byte ptr [EAX + 0x140]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000140u)));
  }
  L0069e56f: { // 0x69e56f: e9cb010000 JMP 0x0069e73f
    goto L0069e73f;
  }
  L0069e574: { // 0x69e574: 8b802c010000 MOV EAX,dword ptr [EAX + 0x12c]
    s.ax = m.r32((s.ax+0x0000012cu));
  }
  L0069e57a: { // 0x69e57a: a818 TEST AL,0x18
    (void)integer::logical(((s.ax & 0xffu))&(0x00000018u),8,flags);
  }
  L0069e57c: { // 0x69e57c: 7505 JNZ 0x0069e583
    if(integer::condition("JNZ",flags)) goto L0069e583;
  }
  L0069e57e: { // 0x69e57e: bffeffffff MOV EDI,0xfffffffe
    s.di = 0xfffffffeu;
  }
  L0069e583: { // 0x69e583: bb08000000 MOV EBX,0x8
    s.bx = 0x00000008u;
  }
  L0069e588: { // 0x69e588: 84c3 TEST BL,AL
    (void)integer::logical(((s.bx & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0069e58a: { // 0x69e58a: 0f84c4010000 JZ 0x0069e754
    if(integer::condition("JZ",flags)) goto L0069e754;
  }
  L0069e590: { // 0x69e590: 668b16 MOV DX,word ptr [ESI]
    s.dx = with_ax(s.dx, m.r16((s.si)));
  }
  L0069e593: { // 0x69e593: 668b4602 MOV AX,word ptr [ESI + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000002u)));
  }
  L0069e597: { // 0x69e597: 664a DEC DX
    s.dx = with_ax(s.dx, integer::decrement((s.dx & 0xffffu),16,flags));
  }
  L0069e599: { // 0x69e599: 6648 DEC AX
    s.ax = with_ax(s.ax, integer::decrement((s.ax & 0xffffu),16,flags));
  }
  L0069e59b: { // 0x69e59b: 6689542418 MOV word ptr [ESP + 0x18],DX
    m.w16((f.sp+0x00000018u), (s.dx & 0xffffu));
  }
  L0069e5a0: { // 0x69e5a0: 668944241a MOV word ptr [ESP + 0x1a],AX
    m.w16((f.sp+0x0000001au), (s.ax & 0xffffu));
  }
  L0069e5a5: { // 0x69e5a5: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0069e5a9: { // 0x69e5a9: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L0069e5ad: { // 0x69e5ad: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0069e5b1: { // 0x69e5b1: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0069e5b2: { // 0x69e5b2: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e5b7: { // 0x69e5b7: e8446feaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6940092u); flags=s.arithmetic_flags;
  }
  L0069e5bc: { // 0x69e5bc: 84982c010000 TEST byte ptr [EAX + 0x12c],BL
    (void)integer::logical((m.r8((s.ax+0x0000012cu)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e5c2: { // 0x69e5c2: 7505 JNZ 0x0069e5c9
    if(integer::condition("JNZ",flags)) goto L0069e5c9;
  }
  L0069e5c4: { // 0x69e5c4: bd40000000 MOV EBP,0x40
    s.bp = 0x00000040u;
  }
  L0069e5c9: { // 0x69e5c9: 668b4e02 MOV CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000002u)));
  }
  L0069e5cd: { // 0x69e5cd: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0069e5d0: { // 0x69e5d0: 6649 DEC CX
    s.cx = with_ax(s.cx, integer::decrement((s.cx & 0xffffu),16,flags));
  }
  L0069e5d2: { // 0x69e5d2: 6689442418 MOV word ptr [ESP + 0x18],AX
    m.w16((f.sp+0x00000018u), (s.ax & 0xffffu));
  }
  L0069e5d7: { // 0x69e5d7: 66894c241a MOV word ptr [ESP + 0x1a],CX
    m.w16((f.sp+0x0000001au), (s.cx & 0xffffu));
  }
  L0069e5dc: { // 0x69e5dc: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0069e5e0: { // 0x69e5e0: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L0069e5e4: { // 0x69e5e4: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e5e9: { // 0x69e5e9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0069e5ea: { // 0x69e5ea: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L0069e5ee: { // 0x69e5ee: e80d6feaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6940147u); flags=s.arithmetic_flags;
  }
  L0069e5f3: { // 0x69e5f3: 84982c010000 TEST byte ptr [EAX + 0x12c],BL
    (void)integer::logical((m.r8((s.ax+0x0000012cu)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e5f9: { // 0x69e5f9: 7506 JNZ 0x0069e601
    if(integer::condition("JNZ",flags)) goto L0069e601;
  }
  L0069e5fb: { // 0x69e5fb: 81cd80000000 OR EBP,0x80
    s.bp = integer::logical((s.bp)|(0x00000080u),32,flags);
  }
  L0069e601: { // 0x69e601: 668b0e MOV CX,word ptr [ESI]
    s.cx = with_ax(s.cx, m.r16((s.si)));
  }
  L0069e604: { // 0x69e604: 668b5602 MOV DX,word ptr [ESI + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.si+0x00000002u)));
  }
  L0069e608: { // 0x69e608: 6641 INC CX
    s.cx = with_ax(s.cx, integer::increment((s.cx & 0xffffu),16,flags));
  }
  L0069e60a: { // 0x69e60a: 664a DEC DX
    s.dx = with_ax(s.dx, integer::decrement((s.dx & 0xffffu),16,flags));
  }
  L0069e60c: { // 0x69e60c: 66894c2418 MOV word ptr [ESP + 0x18],CX
    m.w16((f.sp+0x00000018u), (s.cx & 0xffffu));
  }
  L0069e611: { // 0x69e611: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0069e615: { // 0x69e615: 668954241a MOV word ptr [ESP + 0x1a],DX
    m.w16((f.sp+0x0000001au), (s.dx & 0xffffu));
  }
  L0069e61a: { // 0x69e61a: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0069e61e: { // 0x69e61e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0069e61f: { // 0x69e61f: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e624: { // 0x69e624: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0069e628: { // 0x69e628: e8d36eeaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6940205u); flags=s.arithmetic_flags;
  }
  L0069e62d: { // 0x69e62d: 84982c010000 TEST byte ptr [EAX + 0x12c],BL
    (void)integer::logical((m.r8((s.ax+0x0000012cu)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e633: { // 0x69e633: 7503 JNZ 0x0069e638
    if(integer::condition("JNZ",flags)) goto L0069e638;
  }
  L0069e635: { // 0x69e635: 83cd01 OR EBP,0x1
    s.bp = integer::logical((s.bp)|(0x00000001u),32,flags);
  }
  L0069e638: { // 0x69e638: 668b16 MOV DX,word ptr [ESI]
    s.dx = with_ax(s.dx, m.r16((s.si)));
  }
  L0069e63b: { // 0x69e63b: 668b4602 MOV AX,word ptr [ESI + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000002u)));
  }
  L0069e63f: { // 0x69e63f: 664a DEC DX
    s.dx = with_ax(s.dx, integer::decrement((s.dx & 0xffffu),16,flags));
  }
  L0069e641: { // 0x69e641: 668944241a MOV word ptr [ESP + 0x1a],AX
    m.w16((f.sp+0x0000001au), (s.ax & 0xffffu));
  }
  L0069e646: { // 0x69e646: 6689542418 MOV word ptr [ESP + 0x18],DX
    m.w16((f.sp+0x00000018u), (s.dx & 0xffffu));
  }
  L0069e64b: { // 0x69e64b: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0069e64f: { // 0x69e64f: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L0069e653: { // 0x69e653: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0069e657: { // 0x69e657: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0069e658: { // 0x69e658: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e65d: { // 0x69e65d: e89e6eeaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6940258u); flags=s.arithmetic_flags;
  }
  L0069e662: { // 0x69e662: 84982c010000 TEST byte ptr [EAX + 0x12c],BL
    (void)integer::logical((m.r8((s.ax+0x0000012cu)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e668: { // 0x69e668: 7503 JNZ 0x0069e66d
    if(integer::condition("JNZ",flags)) goto L0069e66d;
  }
  L0069e66a: { // 0x69e66a: 83cd20 OR EBP,0x20
    s.bp = integer::logical((s.bp)|(0x00000020u),32,flags);
  }
  L0069e66d: { // 0x69e66d: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0069e670: { // 0x69e670: 668b4e02 MOV CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000002u)));
  }
  L0069e674: { // 0x69e674: 6640 INC AX
    s.ax = with_ax(s.ax, integer::increment((s.ax & 0xffffu),16,flags));
  }
  L0069e676: { // 0x69e676: 66894c241a MOV word ptr [ESP + 0x1a],CX
    m.w16((f.sp+0x0000001au), (s.cx & 0xffffu));
  }
  L0069e67b: { // 0x69e67b: 6689442418 MOV word ptr [ESP + 0x18],AX
    m.w16((f.sp+0x00000018u), (s.ax & 0xffffu));
  }
  L0069e680: { // 0x69e680: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0069e684: { // 0x69e684: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L0069e688: { // 0x69e688: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e68d: { // 0x69e68d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0069e68e: { // 0x69e68e: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L0069e692: { // 0x69e692: e8696eeaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6940311u); flags=s.arithmetic_flags;
  }
  L0069e697: { // 0x69e697: 84982c010000 TEST byte ptr [EAX + 0x12c],BL
    (void)integer::logical((m.r8((s.ax+0x0000012cu)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e69d: { // 0x69e69d: 7503 JNZ 0x0069e6a2
    if(integer::condition("JNZ",flags)) goto L0069e6a2;
  }
  L0069e69f: { // 0x69e69f: 83cd02 OR EBP,0x2
    s.bp = integer::logical((s.bp)|(0x00000002u),32,flags);
  }
  L0069e6a2: { // 0x69e6a2: 668b0e MOV CX,word ptr [ESI]
    s.cx = with_ax(s.cx, m.r16((s.si)));
  }
  L0069e6a5: { // 0x69e6a5: 668b5602 MOV DX,word ptr [ESI + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.si+0x00000002u)));
  }
  L0069e6a9: { // 0x69e6a9: 6649 DEC CX
    s.cx = with_ax(s.cx, integer::decrement((s.cx & 0xffffu),16,flags));
  }
  L0069e6ab: { // 0x69e6ab: 6642 INC DX
    s.dx = with_ax(s.dx, integer::increment((s.dx & 0xffffu),16,flags));
  }
  L0069e6ad: { // 0x69e6ad: 66894c2418 MOV word ptr [ESP + 0x18],CX
    m.w16((f.sp+0x00000018u), (s.cx & 0xffffu));
  }
  L0069e6b2: { // 0x69e6b2: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0069e6b6: { // 0x69e6b6: 668954241a MOV word ptr [ESP + 0x1a],DX
    m.w16((f.sp+0x0000001au), (s.dx & 0xffffu));
  }
  L0069e6bb: { // 0x69e6bb: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0069e6bf: { // 0x69e6bf: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0069e6c0: { // 0x69e6c0: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e6c5: { // 0x69e6c5: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0069e6c9: { // 0x69e6c9: e8326eeaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6940366u); flags=s.arithmetic_flags;
  }
  L0069e6ce: { // 0x69e6ce: 84982c010000 TEST byte ptr [EAX + 0x12c],BL
    (void)integer::logical((m.r8((s.ax+0x0000012cu)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e6d4: { // 0x69e6d4: 7503 JNZ 0x0069e6d9
    if(integer::condition("JNZ",flags)) goto L0069e6d9;
  }
  L0069e6d6: { // 0x69e6d6: 83cd10 OR EBP,0x10
    s.bp = integer::logical((s.bp)|(0x00000010u),32,flags);
  }
  L0069e6d9: { // 0x69e6d9: 668b4602 MOV AX,word ptr [ESI + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000002u)));
  }
  L0069e6dd: { // 0x69e6dd: 668b16 MOV DX,word ptr [ESI]
    s.dx = with_ax(s.dx, m.r16((s.si)));
  }
  L0069e6e0: { // 0x69e6e0: 6640 INC AX
    s.ax = with_ax(s.ax, integer::increment((s.ax & 0xffffu),16,flags));
  }
  L0069e6e2: { // 0x69e6e2: 6689542418 MOV word ptr [ESP + 0x18],DX
    m.w16((f.sp+0x00000018u), (s.dx & 0xffffu));
  }
  L0069e6e7: { // 0x69e6e7: 668944241a MOV word ptr [ESP + 0x1a],AX
    m.w16((f.sp+0x0000001au), (s.ax & 0xffffu));
  }
  L0069e6ec: { // 0x69e6ec: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0069e6f0: { // 0x69e6f0: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L0069e6f4: { // 0x69e6f4: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0069e6f8: { // 0x69e6f8: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0069e6f9: { // 0x69e6f9: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e6fe: { // 0x69e6fe: e8fd6deaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6940419u); flags=s.arithmetic_flags;
  }
  L0069e703: { // 0x69e703: 84982c010000 TEST byte ptr [EAX + 0x12c],BL
    (void)integer::logical((m.r8((s.ax+0x0000012cu)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e709: { // 0x69e709: 7502 JNZ 0x0069e70d
    if(integer::condition("JNZ",flags)) goto L0069e70d;
  }
  L0069e70b: { // 0x69e70b: 0beb OR EBP,EBX
    s.bp = integer::logical((s.bp)|(s.bx),32,flags);
  }
  L0069e70d: { // 0x69e70d: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0069e710: { // 0x69e710: 668b4e02 MOV CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000002u)));
  }
  L0069e714: { // 0x69e714: 6640 INC AX
    s.ax = with_ax(s.ax, integer::increment((s.ax & 0xffffu),16,flags));
  }
  L0069e716: { // 0x69e716: 6641 INC CX
    s.cx = with_ax(s.cx, integer::increment((s.cx & 0xffffu),16,flags));
  }
  L0069e718: { // 0x69e718: 6689442418 MOV word ptr [ESP + 0x18],AX
    m.w16((f.sp+0x00000018u), (s.ax & 0xffffu));
  }
  L0069e71d: { // 0x69e71d: 66894c241a MOV word ptr [ESP + 0x1a],CX
    m.w16((f.sp+0x0000001au), (s.cx & 0xffffu));
  }
  L0069e722: { // 0x69e722: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0069e726: { // 0x69e726: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L0069e72a: { // 0x69e72a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0069e72b: { // 0x69e72b: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e730: { // 0x69e730: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L0069e734: { // 0x69e734: e8c76deaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6940473u); flags=s.arithmetic_flags;
  }
  L0069e739: { // 0x69e739: 8a882c010000 MOV CL,byte ptr [EAX + 0x12c]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0000012cu)));
  }
  L0069e73f: { // 0x69e73f: 84cb TEST BL,CL
    (void)integer::logical(((s.bx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0069e741: { // 0x69e741: 7503 JNZ 0x0069e746
    if(integer::condition("JNZ",flags)) goto L0069e746;
  }
  L0069e743: { // 0x69e743: 83cd04 OR EBP,0x4
    s.bp = integer::logical((s.bp)|(0x00000004u),32,flags);
  }
  L0069e746: { // 0x69e746: 0fbe8564727900 MOVSX EAX,byte ptr [EBP + 0x797264]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.bp+0x00797264u)),8));
  }
  L0069e74d: { // 0x69e74d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0069e74e: { // 0x69e74e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0069e74f: { // 0x69e74f: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0069e750: { // 0x69e750: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0069e751: { // 0x69e751: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0069e754: { // 0x69e754: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0069e756: { // 0x69e756: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0069e757: { // 0x69e757: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0069e758: { // 0x69e758: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0069e759: { // 0x69e759: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0069e75a: { // 0x69e75a: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
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
void f_0036aa50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0076aa50: { // 0x76aa50: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L0076aa53: { // 0x76aa53: d93c24 FNSTCW word ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.control();
    m.w16(address,value);
  }
  L0076aa56: { // 0x76aa56: 8d442404 LEA EAX,[ESP + 0x4]
    s.ax = (f.sp+0x00000004u);
  }
  L0076aa5a: { // 0x76aa5a: 8b1424 MOV EDX,dword ptr [ESP]
    s.dx = m.r32((f.sp));
  }
  L0076aa5d: { // 0x76aa5d: 81e2ffff0000 AND EDX,0xffff
    s.dx = integer::logical((s.dx)&(0x0000ffffu),32,flags);
  }
  L0076aa63: { // 0x76aa63: 3b15043a7c00 CMP EDX,dword ptr [0x007c3a04]
    (void)integer::sub(s.dx,m.r32((0x007c3a04u)),32,flags);
  }
  L0076aa69: { // 0x76aa69: 750b JNZ 0x0076aa76
    if(integer::condition("JNZ",flags)) goto L0076aa76;
  }
  L0076aa6b: { // 0x76aa6b: df38 FISTP qword ptr [EAX]
    const auto address=(s.ax);
    const auto value=s.fp.pop_integer64();
    write64(m,address,value);
  }
  L0076aa6d: { // 0x76aa6d: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0076aa70: { // 0x76aa70: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0076aa72: { // 0x76aa72: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0076aa75: { // 0x76aa75: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076aa76: { // 0x76aa76: 8b15043a7c00 MOV EDX,dword ptr [0x007c3a04]
    s.dx = m.r32((0x007c3a04u));
  }
  L0076aa7c: { // 0x76aa7c: 891424 MOV dword ptr [ESP],EDX
    m.w32((f.sp), s.dx);
  }
  L0076aa7f: { // 0x76aa7f: d92c24 FLDCW word ptr [ESP]
    const auto address=(f.sp);
    s.fp.load_control(m.r16(address));
  }
  L0076aa82: { // 0x76aa82: df38 FISTP qword ptr [EAX]
    const auto address=(s.ax);
    const auto value=s.fp.pop_integer64();
    write64(m,address,value);
  }
  L0076aa84: { // 0x76aa84: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0076aa87: { // 0x76aa87: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0076aa89: { // 0x76aa89: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0076aa8c: { // 0x76aa8c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 6947856u:f_002a0410(m,s,child,{});break;
case 5657360u:f_00165310(m,s,child,{});break;
case 6463344u:f_00229f70(m,s,child,{});break;
case 4657760u:f_00071260(m,s,child,{});break;
case 4699728u:f_0007b650(m,s,child,{});break;
case 5599872u:f_00157280(m,s,child,{});break;
case 4653760u:f_000702c0(m,s,child,{});break;
case 6939520u:f_0029e380(m,s,child,{});break;
case 5526784u:f_00145500(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
default:throw std::domain_error("recovery210 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_005570f0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005570f0: { // 0x5570f0: 83ec14 SUB ESP,0x14
    f.sp = integer::sub(f.sp,0x00000014u,32,flags);
  }
  L005570f3: { // 0x5570f3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005570f4: { // 0x5570f4: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005570f5: { // 0x5570f5: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005570f6: { // 0x5570f6: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L005570f8: { // 0x5570f8: bb01000000 MOV EBX,0x1
    s.bx = 0x00000001u;
  }
  L005570fd: { // 0x5570fd: 8b87f0000000 MOV EAX,dword ptr [EDI + 0xf0]
    s.ax = m.r32((s.di+0x000000f0u));
  }
  L00557103: { // 0x557103: 899f08010000 MOV dword ptr [EDI + 0x108],EBX
    m.w32((s.di+0x00000108u), s.bx);
  }
  L00557109: { // 0x557109: 89870c010000 MOV dword ptr [EDI + 0x10c],EAX
    m.w32((s.di+0x0000010cu), s.ax);
  }
  L0055710f: { // 0x55710f: 8d48ff LEA ECX,[EAX + -0x1]
    s.cx = (s.ax-0x00000001u);
  }
  L00557112: { // 0x557112: 898f10010000 MOV dword ptr [EDI + 0x110],ECX
    m.w32((s.di+0x00000110u), s.cx);
  }
  L00557118: { // 0x557118: 8b9738010000 MOV EDX,dword ptr [EDI + 0x138]
    s.dx = m.r32((s.di+0x00000138u));
  }
  L0055711e: { // 0x55711e: c1e00b SHL EAX,0xb
    s.ax = integer::shift(s.ax,0x0000000bu,32,flags,integer::Shift::left);
  }
  L00557121: { // 0x557121: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00557123: { // 0x557123: 8d441004 LEA EAX,[EAX + EDX*0x1 + 0x4]
    s.ax = (s.ax+(s.dx * 0x00000001u)+0x00000004u);
  }
  L00557127: { // 0x557127: 898714010000 MOV dword ptr [EDI + 0x114],EAX
    m.w32((s.di+0x00000114u), s.ax);
  }
  L0055712d: { // 0x55712d: e84e010000 CALL 0x00557280
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557280u,5599538u); flags=s.arithmetic_flags;
  }
  L00557132: { // 0x557132: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00557134: { // 0x557134: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00557136: { // 0x557136: 7461 JZ 0x00557199
    if(integer::condition("JZ",flags)) goto L00557199;
  }
  L00557138: { // 0x557138: f6864001000020 TEST byte ptr [ESI + 0x140],0x20
    (void)integer::logical((m.r8((s.si+0x00000140u)))&(0x00000020u),8,flags);
  }
  L0055713f: { // 0x55713f: 744b JZ 0x0055718c
    if(integer::condition("JZ",flags)) goto L0055718c;
  }
  L00557141: { // 0x557141: 8b862c010000 MOV EAX,dword ptr [ESI + 0x12c]
    s.ax = m.r32((s.si+0x0000012cu));
  }
  L00557147: { // 0x557147: 8b9640010000 MOV EDX,dword ptr [ESI + 0x140]
    s.dx = m.r32((s.si+0x00000140u));
  }
  L0055714d: { // 0x55714d: 24e7 AND AL,0xe7
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000e7u),8,flags));
  }
  L0055714f: { // 0x55714f: 83e2dc AND EDX,0xffffffdc
    s.dx = integer::logical((s.dx)&(0xffffffdcu),32,flags);
  }
  L00557152: { // 0x557152: 89862c010000 MOV dword ptr [ESI + 0x12c],EAX
    m.w32((s.si+0x0000012cu), s.ax);
  }
  L00557158: { // 0x557158: 899640010000 MOV dword ptr [ESI + 0x140],EDX
    m.w32((s.si+0x00000140u), s.dx);
  }
  L0055715e: { // 0x55715e: 889e38010000 MOV byte ptr [ESI + 0x138],BL
    m.w8((s.si+0x00000138u), (s.bx & 0xffu));
  }
  L00557164: { // 0x557164: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L0055716a: { // 0x55716a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0055716b: { // 0x55716b: e8a0921400 CALL 0x006a0410
    s.arithmetic_flags=flags; invoke(m,s,f,0x006a0410u,5599600u); flags=s.arithmetic_flags;
  }
  L00557170: { // 0x557170: 80be20010000fe CMP byte ptr [ESI + 0x120],0xfe
    (void)integer::sub(m.r8((s.si+0x00000120u)),0x000000feu,8,flags);
  }
  L00557177: { // 0x557177: 7513 JNZ 0x0055718c
    if(integer::condition("JNZ",flags)) goto L0055718c;
  }
  L00557179: { // 0x557179: 8b0de4e0a100 MOV ECX,dword ptr [0x00a1e0e4]
    s.cx = m.r32((0x00a1e0e4u));
  }
  L0055717f: { // 0x55717f: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00557180: { // 0x557180: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00557181: { // 0x557181: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00557182: { // 0x557182: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00557187: { // 0x557187: e884e10000 CALL 0x00565310
    s.arithmetic_flags=flags; invoke(m,s,f,0x00565310u,5599628u); flags=s.arithmetic_flags;
  }
  L0055718c: { // 0x55718c: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0055718e: { // 0x55718e: e8ed000000 CALL 0x00557280
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557280u,5599635u); flags=s.arithmetic_flags;
  }
  L00557193: { // 0x557193: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00557195: { // 0x557195: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00557197: { // 0x557197: 759f JNZ 0x00557138
    if(integer::condition("JNZ",flags)) goto L00557138;
  }
  L00557199: { // 0x557199: 8b87f0000000 MOV EAX,dword ptr [EDI + 0xf0]
    s.ax = m.r32((s.di+0x000000f0u));
  }
  L0055719f: { // 0x55719f: 899f08010000 MOV dword ptr [EDI + 0x108],EBX
    m.w32((s.di+0x00000108u), s.bx);
  }
  L005571a5: { // 0x5571a5: 89870c010000 MOV dword ptr [EDI + 0x10c],EAX
    m.w32((s.di+0x0000010cu), s.ax);
  }
  L005571ab: { // 0x5571ab: 8d50ff LEA EDX,[EAX + -0x1]
    s.dx = (s.ax-0x00000001u);
  }
  L005571ae: { // 0x5571ae: 899710010000 MOV dword ptr [EDI + 0x110],EDX
    m.w32((s.di+0x00000110u), s.dx);
  }
  L005571b4: { // 0x5571b4: 8b8f38010000 MOV ECX,dword ptr [EDI + 0x138]
    s.cx = m.r32((s.di+0x00000138u));
  }
  L005571ba: { // 0x5571ba: c1e00b SHL EAX,0xb
    s.ax = integer::shift(s.ax,0x0000000bu,32,flags,integer::Shift::left);
  }
  L005571bd: { // 0x5571bd: 8d540804 LEA EDX,[EAX + ECX*0x1 + 0x4]
    s.dx = (s.ax+(s.cx * 0x00000001u)+0x00000004u);
  }
  L005571c1: { // 0x5571c1: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005571c3: { // 0x5571c3: 899714010000 MOV dword ptr [EDI + 0x114],EDX
    m.w32((s.di+0x00000114u), s.dx);
  }
  L005571c9: { // 0x5571c9: e8b2000000 CALL 0x00557280
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557280u,5599694u); flags=s.arithmetic_flags;
  }
  L005571ce: { // 0x5571ce: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L005571d0: { // 0x5571d0: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L005571d2: { // 0x5571d2: 0f849c000000 JZ 0x00557274
    if(integer::condition("JZ",flags)) goto L00557274;
  }
  L005571d8: { // 0x5571d8: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005571da: { // 0x5571da: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L005571de: { // 0x5571de: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005571df: { // 0x5571df: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005571e1: { // 0x5571e1: ff5048 CALL dword ptr [EAX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000048u)),5599716u); flags=s.arithmetic_flags;
  }
  L005571e4: { // 0x5571e4: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L005571e6: { // 0x5571e6: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L005571e8: { // 0x5571e8: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L005571ea: { // 0x5571ea: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L005571eb: { // 0x5571eb: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L005571f1: { // 0x5571f1: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L005571f3: { // 0x5571f3: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L005571f6: { // 0x5571f6: 6689442410 MOV word ptr [ESP + 0x10],AX
    m.w16((f.sp+0x00000010u), (s.ax & 0xffffu));
  }
  L005571fb: { // 0x5571fb: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L005571fe: { // 0x5571fe: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L005571ff: { // 0x5571ff: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00557205: { // 0x557205: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L0055720b: { // 0x55720b: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0055720d: { // 0x55720d: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00557210: { // 0x557210: 6689442412 MOV word ptr [ESP + 0x12],AX
    m.w16((f.sp+0x00000012u), (s.ax & 0xffffu));
  }
  L00557215: { // 0x557215: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00557219: { // 0x557219: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L0055721d: { // 0x55721d: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L00557221: { // 0x557221: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00557222: { // 0x557222: e859711400 CALL 0x0069e380
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069e380u,5599783u); flags=s.arithmetic_flags;
  }
  L00557227: { // 0x557227: 3a8620010000 CMP AL,byte ptr [ESI + 0x120]
    (void)integer::sub((s.ax & 0xffu),m.r8((s.si+0x00000120u)),8,flags);
  }
  L0055722d: { // 0x55722d: 7434 JZ 0x00557263
    if(integer::condition("JZ",flags)) goto L00557263;
  }
  L0055722f: { // 0x55722f: 888620010000 MOV byte ptr [ESI + 0x120],AL
    m.w8((s.si+0x00000120u), (s.ax & 0xffu));
  }
  L00557235: { // 0x557235: 889e38010000 MOV byte ptr [ESI + 0x138],BL
    m.w8((s.si+0x00000138u), (s.bx & 0xffu));
  }
  L0055723b: { // 0x55723b: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L00557241: { // 0x557241: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00557242: { // 0x557242: e8c9911400 CALL 0x006a0410
    s.arithmetic_flags=flags; invoke(m,s,f,0x006a0410u,5599815u); flags=s.arithmetic_flags;
  }
  L00557247: { // 0x557247: 80be20010000fe CMP byte ptr [ESI + 0x120],0xfe
    (void)integer::sub(m.r8((s.si+0x00000120u)),0x000000feu,8,flags);
  }
  L0055724e: { // 0x55724e: 7513 JNZ 0x00557263
    if(integer::condition("JNZ",flags)) goto L00557263;
  }
  L00557250: { // 0x557250: 8b0de4e0a100 MOV ECX,dword ptr [0x00a1e0e4]
    s.cx = m.r32((0x00a1e0e4u));
  }
  L00557256: { // 0x557256: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00557257: { // 0x557257: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00557258: { // 0x557258: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00557259: { // 0x557259: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0055725e: { // 0x55725e: e8ade00000 CALL 0x00565310
    s.arithmetic_flags=flags; invoke(m,s,f,0x00565310u,5599843u); flags=s.arithmetic_flags;
  }
  L00557263: { // 0x557263: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00557265: { // 0x557265: e816000000 CALL 0x00557280
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557280u,5599850u); flags=s.arithmetic_flags;
  }
  L0055726a: { // 0x55726a: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0055726c: { // 0x55726c: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0055726e: { // 0x55726e: 0f8564ffffff JNZ 0x005571d8
    if(integer::condition("JNZ",flags)) goto L005571d8;
  }
  L00557274: { // 0x557274: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00557275: { // 0x557275: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00557276: { // 0x557276: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00557277: { // 0x557277: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L0055727a: { // 0x55727a: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
