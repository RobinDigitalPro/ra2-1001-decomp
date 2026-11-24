#include "recovered/recovery_b246_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b246 {
namespace {
void f_00155130(Memory&,State&,Frame&,const Operations&);
void f_0002add0(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_002a9440(Memory&,State&,Frame&,const Operations&);
void f_002e2a00(Memory&,State&,Frame&,const Operations&);
void f_0007a060(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_00155130(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00555130: { // 0x555130: 668b442406 MOV AX,word ptr [ESP + 0x6]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x00000006u)));
  }
  L00555135: { // 0x555135: 83ec1c SUB ESP,0x1c
    f.sp = integer::sub(f.sp,0x0000001cu,32,flags);
  }
  L00555138: { // 0x555138: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00555139: { // 0x555139: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0055513a: { // 0x55513a: 668b6c242e MOV BP,word ptr [ESP + 0x2e]
    s.bp = (s.bp & 0xffff0000u) | ((m.r16((f.sp+0x0000002eu))) & 0xffffu);
  }
  L0055513f: { // 0x55513f: 32db XOR BL,BL
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))^((s.bx & 0xffu)),8,flags));
  }
  L00555141: { // 0x555141: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00555142: { // 0x555142: 663bc5 CMP AX,BP
    (void)integer::sub((s.ax & 0xffffu),(s.bp & 0xffffu),16,flags);
  }
  L00555145: { // 0x555145: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00555146: { // 0x555146: 7520 JNZ 0x00555168
    if(integer::condition("JNZ",flags)) goto L00555168;
  }
  L00555148: { // 0x555148: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L0055514c: { // 0x55514c: 8b7c2434 MOV EDI,dword ptr [ESP + 0x34]
    s.di = m.r32((f.sp+0x00000034u));
  }
  L00555150: { // 0x555150: 663bc7 CMP AX,DI
    (void)integer::sub((s.ax & 0xffffu),(s.di & 0xffffu),16,flags);
  }
  L00555153: { // 0x555153: b301 MOV BL,0x1
    s.bx = with_al(s.bx, 0x00000001u);
  }
  L00555155: { // 0x555155: 7e30 JLE 0x00555187
    if(integer::condition("JLE",flags)) goto L00555187;
  }
  L00555157: { // 0x555157: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00555159: { // 0x555159: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0055515b: { // 0x55515b: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0055515d: { // 0x55515d: 897c2434 MOV dword ptr [ESP + 0x34],EDI
    m.w32((f.sp+0x00000034u), s.di);
  }
  L00555161: { // 0x555161: 668b6c2436 MOV BP,word ptr [ESP + 0x36]
    s.bp = (s.bp & 0xffff0000u) | ((m.r16((f.sp+0x00000036u))) & 0xffffu);
  }
  L00555166: { // 0x555166: eb1f JMP 0x00555187
    goto L00555187;
  }
  L00555168: { // 0x555168: 7e15 JLE 0x0055517f
    if(integer::condition("JLE",flags)) goto L0055517f;
  }
  L0055516a: { // 0x55516a: 8b4c2430 MOV ECX,dword ptr [ESP + 0x30]
    s.cx = m.r32((f.sp+0x00000030u));
  }
  L0055516e: { // 0x55516e: 8b442434 MOV EAX,dword ptr [ESP + 0x34]
    s.ax = m.r32((f.sp+0x00000034u));
  }
  L00555172: { // 0x555172: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L00555174: { // 0x555174: 897c2434 MOV dword ptr [ESP + 0x34],EDI
    m.w32((f.sp+0x00000034u), s.di);
  }
  L00555178: { // 0x555178: 668b6c2436 MOV BP,word ptr [ESP + 0x36]
    s.bp = (s.bp & 0xffff0000u) | ((m.r16((f.sp+0x00000036u))) & 0xffffu);
  }
  L0055517d: { // 0x55517d: eb08 JMP 0x00555187
    goto L00555187;
  }
  L0055517f: { // 0x55517f: 8b7c2434 MOV EDI,dword ptr [ESP + 0x34]
    s.di = m.r32((f.sp+0x00000034u));
  }
  L00555183: { // 0x555183: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L00555187: { // 0x555187: 89442434 MOV dword ptr [ESP + 0x34],EAX
    m.w32((f.sp+0x00000034u), s.ax);
  }
  L0055518b: { // 0x55518b: 668b4c2434 MOV CX,word ptr [ESP + 0x34]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000034u)));
  }
  L00555190: { // 0x555190: 663bcf CMP CX,DI
    (void)integer::sub((s.cx & 0xffffu),(s.di & 0xffffu),16,flags);
  }
  L00555193: { // 0x555193: 750b JNZ 0x005551a0
    if(integer::condition("JNZ",flags)) goto L005551a0;
  }
  L00555195: { // 0x555195: 66396c2436 CMP word ptr [ESP + 0x36],BP
    (void)integer::sub(m.r16((f.sp+0x00000036u)),(s.bp & 0xffffu),16,flags);
  }
  L0055519a: { // 0x55519a: 0f849f020000 JZ 0x0055543f
    if(integer::condition("JZ",flags)) goto L0055543f;
  }
  L005551a0: { // 0x5551a0: 0fbf442436 MOVSX EAX,word ptr [ESP + 0x36]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000036u)),16));
  }
  L005551a5: { // 0x5551a5: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L005551a8: { // 0x5551a8: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L005551ab: { // 0x5551ab: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L005551ad: { // 0x5551ad: 7814 JS 0x005551c3
    if(integer::condition("JS",flags)) goto L005551c3;
  }
  L005551af: { // 0x5551af: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L005551b4: { // 0x5551b4: 7d0d JGE 0x005551c3
    if(integer::condition("JGE",flags)) goto L005551c3;
  }
  L005551b6: { // 0x5551b6: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L005551bc: { // 0x5551bc: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L005551bf: { // 0x5551bf: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005551c1: { // 0x5551c1: 750e JNZ 0x005551d1
    if(integer::condition("JNZ",flags)) goto L005551d1;
  }
  L005551c3: { // 0x5551c3: 8b442434 MOV EAX,dword ptr [ESP + 0x34]
    s.ax = m.r32((f.sp+0x00000034u));
  }
  L005551c7: { // 0x5551c7: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L005551cc: { // 0x5551cc: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L005551d1: { // 0x5551d1: 8b483c MOV ECX,dword ptr [EAX + 0x3c]
    s.cx = m.r32((s.ax+0x0000003cu));
  }
  L005551d4: { // 0x5551d4: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005551d6: { // 0x5551d6: 7414 JZ 0x005551ec
    if(integer::condition("JZ",flags)) goto L005551ec;
  }
  L005551d8: { // 0x5551d8: 8b155c6ea500 MOV EDX,dword ptr [0x00a56e5c]
    s.dx = m.r32((0x00a56e5cu));
  }
  L005551de: { // 0x5551de: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L005551e0: { // 0x5551e0: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L005551e2: { // 0x5551e2: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005551e3: { // 0x5551e3: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L005551e5: { // 0x5551e5: 6a1f PUSH 0x1f
    f.push(m,0x0000001fu);
  }
  L005551e7: { // 0x5551e7: e854421500 CALL 0x006a9440
    s.arithmetic_flags=flags; invoke(m,s,f,0x006a9440u,5591532u); flags=s.arithmetic_flags;
  }
  L005551ec: { // 0x5551ec: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L005551ee: { // 0x5551ee: 0f8439010000 JZ 0x0055532d
    if(integer::condition("JZ",flags)) goto L0055532d;
  }
  L005551f4: { // 0x5551f4: a1b09d8300 MOV EAX,[0x00839db0]
    s.ax = m.r32((0x00839db0u));
  }
  L005551f9: { // 0x5551f9: 8b4c2434 MOV ECX,dword ptr [ESP + 0x34]
    s.cx = m.r32((f.sp+0x00000034u));
  }
  L005551fd: { // 0x5551fd: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L005551ff: { // 0x5551ff: 66a1b29d8300 MOV AX,[0x00839db2]
    s.ax = with_ax(s.ax, m.r16((0x00839db2u)));
  }
  L00555205: { // 0x555205: 6603442436 ADD AX,word ptr [ESP + 0x36]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((f.sp+0x00000036u)),16,flags));
  }
  L0055520a: { // 0x55520a: 66894c2430 MOV word ptr [ESP + 0x30],CX
    m.w16((f.sp+0x00000030u), (s.cx & 0xffffu));
  }
  L0055520f: { // 0x55520f: 0fbfd1 MOVSX EDX,CX
    s.dx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L00555212: { // 0x555212: 6689442432 MOV word ptr [ESP + 0x32],AX
    m.w16((f.sp+0x00000032u), (s.ax & 0xffffu));
  }
  L00555217: { // 0x555217: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0055521a: { // 0x55521a: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L0055521d: { // 0x55521d: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0055521f: { // 0x55521f: 7814 JS 0x00555235
    if(integer::condition("JS",flags)) goto L00555235;
  }
  L00555221: { // 0x555221: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00555226: { // 0x555226: 7d0d JGE 0x00555235
    if(integer::condition("JGE",flags)) goto L00555235;
  }
  L00555228: { // 0x555228: 8b0d58a98100 MOV ECX,dword ptr [0x0081a958]
    s.cx = m.r32((0x0081a958u));
  }
  L0055522e: { // 0x55522e: 8b0481 MOV EAX,dword ptr [ECX + EAX*0x4]
    s.ax = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L00555231: { // 0x555231: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00555233: { // 0x555233: 750f JNZ 0x00555244
    if(integer::condition("JNZ",flags)) goto L00555244;
  }
  L00555235: { // 0x555235: 8b542430 MOV EDX,dword ptr [ESP + 0x30]
    s.dx = m.r32((f.sp+0x00000030u));
  }
  L00555239: { // 0x555239: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L0055523e: { // 0x55523e: 89153476a500 MOV dword ptr [0x00a57634],EDX
    m.w32((0x00a57634u), s.dx);
  }
  L00555244: { // 0x555244: 8b483c MOV ECX,dword ptr [EAX + 0x3c]
    s.cx = m.r32((s.ax+0x0000003cu));
  }
  L00555247: { // 0x555247: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00555249: { // 0x555249: 7413 JZ 0x0055525e
    if(integer::condition("JZ",flags)) goto L0055525e;
  }
  L0055524b: { // 0x55524b: a15c6ea500 MOV EAX,[0x00a56e5c]
    s.ax = m.r32((0x00a56e5cu));
  }
  L00555250: { // 0x555250: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00555252: { // 0x555252: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00555254: { // 0x555254: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00555255: { // 0x555255: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00555257: { // 0x555257: 6a1f PUSH 0x1f
    f.push(m,0x0000001fu);
  }
  L00555259: { // 0x555259: e8e2411500 CALL 0x006a9440
    s.arithmetic_flags=flags; invoke(m,s,f,0x006a9440u,5591646u); flags=s.arithmetic_flags;
  }
  L0055525e: { // 0x55525e: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L00555262: { // 0x555262: 68a09d8300 PUSH 0x839da0
    f.push(m,0x00839da0u);
  }
  L00555267: { // 0x555267: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00555268: { // 0x555268: 8d4c243c LEA ECX,[ESP + 0x3c]
    s.cx = (f.sp+0x0000003cu);
  }
  L0055526c: { // 0x55526c: e85f5bedff CALL 0x0042add0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042add0u,5591665u); flags=s.arithmetic_flags;
  }
  L00555271: { // 0x555271: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00555273: { // 0x555273: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L00555277: { // 0x555277: 0fbf442412 MOVSX EAX,word ptr [ESP + 0x12]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000012u)),16));
  }
  L0055527c: { // 0x55527c: 0fbfd1 MOVSX EDX,CX
    s.dx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L0055527f: { // 0x55527f: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L00555282: { // 0x555282: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00555284: { // 0x555284: 7818 JS 0x0055529e
    if(integer::condition("JS",flags)) goto L0055529e;
  }
  L00555286: { // 0x555286: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L0055528b: { // 0x55528b: 7d11 JGE 0x0055529e
    if(integer::condition("JGE",flags)) goto L0055529e;
  }
  L0055528d: { // 0x55528d: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L00555293: { // 0x555293: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L00555296: { // 0x555296: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00555298: { // 0x555298: 7404 JZ 0x0055529e
    if(integer::condition("JZ",flags)) goto L0055529e;
  }
  L0055529a: { // 0x55529a: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0055529c: { // 0x55529c: eb0b JMP 0x005552a9
    goto L005552a9;
  }
  L0055529e: { // 0x55529e: 890d3476a500 MOV dword ptr [0x00a57634],ECX
    m.w32((0x00a57634u), s.cx);
  }
  L005552a4: { // 0x5552a4: be1076a500 MOV ESI,0xa57610
    s.si = 0x00a57610u;
  }
  L005552a9: { // 0x5552a9: 8b4e3c MOV ECX,dword ptr [ESI + 0x3c]
    s.cx = m.r32((s.si+0x0000003cu));
  }
  L005552ac: { // 0x5552ac: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005552ae: { // 0x5552ae: 7413 JZ 0x005552c3
    if(integer::condition("JZ",flags)) goto L005552c3;
  }
  L005552b0: { // 0x5552b0: a15c6ea500 MOV EAX,[0x00a56e5c]
    s.ax = m.r32((0x00a56e5cu));
  }
  L005552b5: { // 0x5552b5: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L005552b7: { // 0x5552b7: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L005552b9: { // 0x5552b9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005552ba: { // 0x5552ba: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L005552bc: { // 0x5552bc: 6a1f PUSH 0x1f
    f.push(m,0x0000001fu);
  }
  L005552be: { // 0x5552be: e87d411500 CALL 0x006a9440
    s.arithmetic_flags=flags; invoke(m,s,f,0x006a9440u,5591747u); flags=s.arithmetic_flags;
  }
  L005552c3: { // 0x5552c3: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L005552c7: { // 0x5552c7: 68a09d8300 PUSH 0x839da0
    f.push(m,0x00839da0u);
  }
  L005552cc: { // 0x5552cc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005552cd: { // 0x5552cd: 8d4e24 LEA ECX,[ESI + 0x24]
    s.cx = (s.si+0x00000024u);
  }
  L005552d0: { // 0x5552d0: e8fb5aedff CALL 0x0042add0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042add0u,5591765u); flags=s.arithmetic_flags;
  }
  L005552d5: { // 0x5552d5: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L005552d7: { // 0x5552d7: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L005552db: { // 0x5552db: 0fbf442412 MOVSX EAX,word ptr [ESP + 0x12]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000012u)),16));
  }
  L005552e0: { // 0x5552e0: 0fbfd1 MOVSX EDX,CX
    s.dx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L005552e3: { // 0x5552e3: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L005552e6: { // 0x5552e6: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L005552e8: { // 0x5552e8: 7814 JS 0x005552fe
    if(integer::condition("JS",flags)) goto L005552fe;
  }
  L005552ea: { // 0x5552ea: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L005552ef: { // 0x5552ef: 7d0d JGE 0x005552fe
    if(integer::condition("JGE",flags)) goto L005552fe;
  }
  L005552f1: { // 0x5552f1: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L005552f7: { // 0x5552f7: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L005552fa: { // 0x5552fa: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005552fc: { // 0x5552fc: 750b JNZ 0x00555309
    if(integer::condition("JNZ",flags)) goto L00555309;
  }
  L005552fe: { // 0x5552fe: 890d3476a500 MOV dword ptr [0x00a57634],ECX
    m.w32((0x00a57634u), s.cx);
  }
  L00555304: { // 0x555304: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L00555309: { // 0x555309: 8b483c MOV ECX,dword ptr [EAX + 0x3c]
    s.cx = m.r32((s.ax+0x0000003cu));
  }
  L0055530c: { // 0x55530c: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0055530e: { // 0x55530e: 7413 JZ 0x00555323
    if(integer::condition("JZ",flags)) goto L00555323;
  }
  L00555310: { // 0x555310: a15c6ea500 MOV EAX,[0x00a56e5c]
    s.ax = m.r32((0x00a56e5cu));
  }
  L00555315: { // 0x555315: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00555317: { // 0x555317: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00555319: { // 0x555319: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0055531a: { // 0x55531a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0055531c: { // 0x55531c: 6a1f PUSH 0x1f
    f.push(m,0x0000001fu);
  }
  L0055531e: { // 0x55531e: e81d411500 CALL 0x006a9440
    s.arithmetic_flags=flags; invoke(m,s,f,0x006a9440u,5591843u); flags=s.arithmetic_flags;
  }
  L00555323: { // 0x555323: 66ff442434 INC word ptr [ESP + 0x34]
    m.w16((f.sp+0x00000034u), integer::increment(m.r16((f.sp+0x00000034u)),16,flags));
  }
  L00555328: { // 0x555328: e95efeffff JMP 0x0055518b
    goto L0055518b;
  }
  L0055532d: { // 0x55532d: 8d4c2420 LEA ECX,[ESP + 0x20]
    s.cx = (f.sp+0x00000020u);
  }
  L00555331: { // 0x555331: 68a89d8300 PUSH 0x839da8
    f.push(m,0x00839da8u);
  }
  L00555336: { // 0x555336: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00555337: { // 0x555337: 8d4c243c LEA ECX,[ESP + 0x3c]
    s.cx = (f.sp+0x0000003cu);
  }
  L0055533b: { // 0x55533b: e8905aedff CALL 0x0042add0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042add0u,5591872u); flags=s.arithmetic_flags;
  }
  L00555340: { // 0x555340: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00555342: { // 0x555342: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L00555346: { // 0x555346: 0fbf442412 MOVSX EAX,word ptr [ESP + 0x12]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000012u)),16));
  }
  L0055534b: { // 0x55534b: 0fbfd1 MOVSX EDX,CX
    s.dx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L0055534e: { // 0x55534e: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L00555351: { // 0x555351: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00555353: { // 0x555353: 7814 JS 0x00555369
    if(integer::condition("JS",flags)) goto L00555369;
  }
  L00555355: { // 0x555355: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L0055535a: { // 0x55535a: 7d0d JGE 0x00555369
    if(integer::condition("JGE",flags)) goto L00555369;
  }
  L0055535c: { // 0x55535c: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L00555362: { // 0x555362: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L00555365: { // 0x555365: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00555367: { // 0x555367: 750b JNZ 0x00555374
    if(integer::condition("JNZ",flags)) goto L00555374;
  }
  L00555369: { // 0x555369: 890d3476a500 MOV dword ptr [0x00a57634],ECX
    m.w32((0x00a57634u), s.cx);
  }
  L0055536f: { // 0x55536f: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L00555374: { // 0x555374: 8b483c MOV ECX,dword ptr [EAX + 0x3c]
    s.cx = m.r32((s.ax+0x0000003cu));
  }
  L00555377: { // 0x555377: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00555379: { // 0x555379: 7413 JZ 0x0055538e
    if(integer::condition("JZ",flags)) goto L0055538e;
  }
  L0055537b: { // 0x55537b: a15c6ea500 MOV EAX,[0x00a56e5c]
    s.ax = m.r32((0x00a56e5cu));
  }
  L00555380: { // 0x555380: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00555382: { // 0x555382: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00555384: { // 0x555384: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00555385: { // 0x555385: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00555387: { // 0x555387: 6a1f PUSH 0x1f
    f.push(m,0x0000001fu);
  }
  L00555389: { // 0x555389: e8b2401500 CALL 0x006a9440
    s.arithmetic_flags=flags; invoke(m,s,f,0x006a9440u,5591950u); flags=s.arithmetic_flags;
  }
  L0055538e: { // 0x55538e: 8d4c2424 LEA ECX,[ESP + 0x24]
    s.cx = (f.sp+0x00000024u);
  }
  L00555392: { // 0x555392: 68b89d8300 PUSH 0x839db8
    f.push(m,0x00839db8u);
  }
  L00555397: { // 0x555397: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00555398: { // 0x555398: 8d4c243c LEA ECX,[ESP + 0x3c]
    s.cx = (f.sp+0x0000003cu);
  }
  L0055539c: { // 0x55539c: e82f5aedff CALL 0x0042add0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042add0u,5591969u); flags=s.arithmetic_flags;
  }
  L005553a1: { // 0x5553a1: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L005553a3: { // 0x5553a3: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L005553a7: { // 0x5553a7: 0fbf442412 MOVSX EAX,word ptr [ESP + 0x12]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000012u)),16));
  }
  L005553ac: { // 0x5553ac: 0fbfd1 MOVSX EDX,CX
    s.dx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L005553af: { // 0x5553af: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L005553b2: { // 0x5553b2: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L005553b4: { // 0x5553b4: 7818 JS 0x005553ce
    if(integer::condition("JS",flags)) goto L005553ce;
  }
  L005553b6: { // 0x5553b6: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L005553bb: { // 0x5553bb: 7d11 JGE 0x005553ce
    if(integer::condition("JGE",flags)) goto L005553ce;
  }
  L005553bd: { // 0x5553bd: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L005553c3: { // 0x5553c3: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L005553c6: { // 0x5553c6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005553c8: { // 0x5553c8: 7404 JZ 0x005553ce
    if(integer::condition("JZ",flags)) goto L005553ce;
  }
  L005553ca: { // 0x5553ca: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L005553cc: { // 0x5553cc: eb0b JMP 0x005553d9
    goto L005553d9;
  }
  L005553ce: { // 0x5553ce: 890d3476a500 MOV dword ptr [0x00a57634],ECX
    m.w32((0x00a57634u), s.cx);
  }
  L005553d4: { // 0x5553d4: be1076a500 MOV ESI,0xa57610
    s.si = 0x00a57610u;
  }
  L005553d9: { // 0x5553d9: 8b4e3c MOV ECX,dword ptr [ESI + 0x3c]
    s.cx = m.r32((s.si+0x0000003cu));
  }
  L005553dc: { // 0x5553dc: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005553de: { // 0x5553de: 7413 JZ 0x005553f3
    if(integer::condition("JZ",flags)) goto L005553f3;
  }
  L005553e0: { // 0x5553e0: a15c6ea500 MOV EAX,[0x00a56e5c]
    s.ax = m.r32((0x00a56e5cu));
  }
  L005553e5: { // 0x5553e5: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L005553e7: { // 0x5553e7: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L005553e9: { // 0x5553e9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005553ea: { // 0x5553ea: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L005553ec: { // 0x5553ec: 6a1f PUSH 0x1f
    f.push(m,0x0000001fu);
  }
  L005553ee: { // 0x5553ee: e84d401500 CALL 0x006a9440
    s.arithmetic_flags=flags; invoke(m,s,f,0x006a9440u,5592051u); flags=s.arithmetic_flags;
  }
  L005553f3: { // 0x5553f3: 8d4c2428 LEA ECX,[ESP + 0x28]
    s.cx = (f.sp+0x00000028u);
  }
  L005553f7: { // 0x5553f7: 68b89d8300 PUSH 0x839db8
    f.push(m,0x00839db8u);
  }
  L005553fc: { // 0x5553fc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005553fd: { // 0x5553fd: 8d4e24 LEA ECX,[ESI + 0x24]
    s.cx = (s.si+0x00000024u);
  }
  L00555400: { // 0x555400: e8cb59edff CALL 0x0042add0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042add0u,5592069u); flags=s.arithmetic_flags;
  }
  L00555405: { // 0x555405: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00555407: { // 0x555407: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L0055540b: { // 0x55540b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0055540c: { // 0x55540c: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00555411: { // 0x555411: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L00555415: { // 0x555415: e8e600ffff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5592090u); flags=s.arithmetic_flags;
  }
  L0055541a: { // 0x55541a: 8b483c MOV ECX,dword ptr [EAX + 0x3c]
    s.cx = m.r32((s.ax+0x0000003cu));
  }
  L0055541d: { // 0x55541d: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0055541f: { // 0x55541f: 7414 JZ 0x00555435
    if(integer::condition("JZ",flags)) goto L00555435;
  }
  L00555421: { // 0x555421: 8b155c6ea500 MOV EDX,dword ptr [0x00a56e5c]
    s.dx = m.r32((0x00a56e5cu));
  }
  L00555427: { // 0x555427: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00555429: { // 0x555429: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0055542b: { // 0x55542b: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0055542c: { // 0x55542c: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0055542e: { // 0x55542e: 6a1f PUSH 0x1f
    f.push(m,0x0000001fu);
  }
  L00555430: { // 0x555430: e80b401500 CALL 0x006a9440
    s.arithmetic_flags=flags; invoke(m,s,f,0x006a9440u,5592117u); flags=s.arithmetic_flags;
  }
  L00555435: { // 0x555435: 66ff442436 INC word ptr [ESP + 0x36]
    m.w16((f.sp+0x00000036u), integer::increment(m.r16((f.sp+0x00000036u)),16,flags));
  }
  L0055543a: { // 0x55543a: e94cfdffff JMP 0x0055518b
    goto L0055518b;
  }
  L0055543f: { // 0x55543f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00555440: { // 0x555440: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00555441: { // 0x555441: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00555442: { // 0x555442: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00555443: { // 0x555443: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L00555446: { // 0x555446: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
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
void f_002a9440(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006a9440: { // 0x6a9440: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006a9441: { // 0x6a9441: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006a9442: { // 0x6a9442: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006a9443: { // 0x6a9443: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L006a9445: { // 0x6a9445: 32db XOR BL,BL
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))^((s.bx & 0xffu)),8,flags));
  }
  L006a9447: { // 0x6a9447: 885c240b MOV byte ptr [ESP + 0xb],BL
    m.w8((f.sp+0x0000000bu), (s.bx & 0xffu));
  }
  L006a944b: { // 0x6a944b: 885c240a MOV byte ptr [ESP + 0xa],BL
    m.w8((f.sp+0x0000000au), (s.bx & 0xffu));
  }
  L006a944f: { // 0x6a944f: 8a4535 MOV AL,byte ptr [EBP + 0x35]
    s.ax = with_al(s.ax, m.r8((s.bp+0x00000035u)));
  }
  L006a9452: { // 0x6a9452: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006a9454: { // 0x6a9454: 7408 JZ 0x006a945e
    if(integer::condition("JZ",flags)) goto L006a945e;
  }
  L006a9456: { // 0x6a9456: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006a9457: { // 0x6a9457: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006a9459: { // 0x6a9459: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006a945a: { // 0x6a945a: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L006a945b: { // 0x6a945b: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
  L006a945e: { // 0x6a945e: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006a945f: { // 0x6a945f: 8b7528 MOV ESI,dword ptr [EBP + 0x28]
    s.si = m.r32((s.bp+0x00000028u));
  }
  L006a9462: { // 0x6a9462: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006a9463: { // 0x6a9463: 8b7c241c MOV EDI,dword ptr [ESP + 0x1c]
    s.di = m.r32((f.sp+0x0000001cu));
  }
  L006a9467: { // 0x6a9467: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L006a9469: { // 0x6a9469: c6453501 MOV byte ptr [EBP + 0x35],0x1
    m.w8((s.bp+0x00000035u), 0x00000001u);
  }
  L006a946d: { // 0x6a946d: 0f849d000000 JZ 0x006a9510
    if(integer::condition("JZ",flags)) goto L006a9510;
  }
  L006a9473: { // 0x6a9473: 8b4d24 MOV ECX,dword ptr [EBP + 0x24]
    s.cx = m.r32((s.bp+0x00000024u));
  }
  L006a9476: { // 0x6a9476: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L006a947a: { // 0x6a947a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006a947b: { // 0x6a947b: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L006a947f: { // 0x6a947f: 8b919c000000 MOV EDX,dword ptr [ECX + 0x9c]
    s.dx = m.r32((s.cx+0x0000009cu));
  }
  L006a9485: { // 0x6a9485: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L006a9489: { // 0x6a9489: 83fa02 CMP EDX,0x2
    (void)integer::sub(s.dx,0x00000002u,32,flags);
  }
  L006a948c: { // 0x6a948c: 0f94c2 SETZ DL
    s.dx = with_al(s.dx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L006a948f: { // 0x6a948f: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006a9490: { // 0x6a9490: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006a9491: { // 0x6a9491: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006a9492: { // 0x6a9492: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006a9493: { // 0x6a9493: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006a9495: { // 0x6a9495: e866950300 CALL 0x006e2a00
    s.arithmetic_flags=flags; invoke(m,s,f,0x006e2a00u,6984858u); flags=s.arithmetic_flags;
  }
  L006a949a: { // 0x6a949a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006a949c: { // 0x6a949c: 7467 JZ 0x006a9505
    if(integer::condition("JZ",flags)) goto L006a9505;
  }
  L006a949e: { // 0x6a949e: 8b5524 MOV EDX,dword ptr [EBP + 0x24]
    s.dx = m.r32((s.bp+0x00000024u));
  }
  L006a94a1: { // 0x6a94a1: 8b829c000000 MOV EAX,dword ptr [EDX + 0x9c]
    s.ax = m.r32((s.dx+0x0000009cu));
  }
  L006a94a7: { // 0x6a94a7: 83e800 SUB EAX,0x0
    s.ax = integer::sub(s.ax,0x00000000u,32,flags);
  }
  L006a94aa: { // 0x6a94aa: 743a JZ 0x006a94e6
    if(integer::condition("JZ",flags)) goto L006a94e6;
  }
  L006a94ac: { // 0x6a94ac: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L006a94ad: { // 0x6a94ad: 7414 JZ 0x006a94c3
    if(integer::condition("JZ",flags)) goto L006a94c3;
  }
  L006a94af: { // 0x6a94af: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L006a94b0: { // 0x6a94b0: 7553 JNZ 0x006a9505
    if(integer::condition("JNZ",flags)) goto L006a9505;
  }
  L006a94b2: { // 0x6a94b2: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L006a94b6: { // 0x6a94b6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006a94b8: { // 0x6a94b8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006a94b9: { // 0x6a94b9: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006a94ba: { // 0x6a94ba: e831960300 CALL 0x006e2af0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006e2af0u,6984895u); flags=s.arithmetic_flags;
  }
  L006a94bf: { // 0x6a94bf: b301 MOV BL,0x1
    s.bx = with_al(s.bx, 0x00000001u);
  }
  L006a94c1: { // 0x6a94c1: eb42 JMP 0x006a9505
    goto L006a9505;
  }
  L006a94c3: { // 0x6a94c3: 837d2c01 CMP dword ptr [EBP + 0x2c],0x1
    (void)integer::sub(m.r32((s.bp+0x0000002cu)),0x00000001u,32,flags);
  }
  L006a94c7: { // 0x6a94c7: 7537 JNZ 0x006a9500
    if(integer::condition("JNZ",flags)) goto L006a9500;
  }
  L006a94c9: { // 0x6a94c9: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L006a94cd: { // 0x6a94cd: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006a94ce: { // 0x6a94ce: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006a94cf: { // 0x6a94cf: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006a94d1: { // 0x6a94d1: e81a960300 CALL 0x006e2af0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006e2af0u,6984918u); flags=s.arithmetic_flags;
  }
  L006a94d6: { // 0x6a94d6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006a94d8: { // 0x6a94d8: e873970300 CALL 0x006e2c50
    s.arithmetic_flags=flags; invoke(m,s,f,0x006e2c50u,6984925u); flags=s.arithmetic_flags;
  }
  L006a94dd: { // 0x6a94dd: c644241301 MOV byte ptr [ESP + 0x13],0x1
    m.w8((f.sp+0x00000013u), 0x00000001u);
  }
  L006a94e2: { // 0x6a94e2: b301 MOV BL,0x1
    s.bx = with_al(s.bx, 0x00000001u);
  }
  L006a94e4: { // 0x6a94e4: eb1f JMP 0x006a9505
    goto L006a9505;
  }
  L006a94e6: { // 0x6a94e6: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L006a94ea: { // 0x6a94ea: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006a94ec: { // 0x6a94ec: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006a94ed: { // 0x6a94ed: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006a94ee: { // 0x6a94ee: e8fd950300 CALL 0x006e2af0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006e2af0u,6984947u); flags=s.arithmetic_flags;
  }
  L006a94f3: { // 0x6a94f3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006a94f5: { // 0x6a94f5: e856970300 CALL 0x006e2c50
    s.arithmetic_flags=flags; invoke(m,s,f,0x006e2c50u,6984954u); flags=s.arithmetic_flags;
  }
  L006a94fa: { // 0x6a94fa: b301 MOV BL,0x1
    s.bx = with_al(s.bx, 0x00000001u);
  }
  L006a94fc: { // 0x6a94fc: 885c2413 MOV byte ptr [ESP + 0x13],BL
    m.w8((f.sp+0x00000013u), (s.bx & 0xffu));
  }
  L006a9500: { // 0x6a9500: c644241201 MOV byte ptr [ESP + 0x12],0x1
    m.w8((f.sp+0x00000012u), 0x00000001u);
  }
  L006a9505: { // 0x6a9505: 8b7628 MOV ESI,dword ptr [ESI + 0x28]
    s.si = m.r32((s.si+0x00000028u));
  }
  L006a9508: { // 0x6a9508: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L006a950a: { // 0x6a950a: 0f8563ffffff JNZ 0x006a9473
    if(integer::condition("JNZ",flags)) goto L006a9473;
  }
  L006a9510: { // 0x6a9510: 8a442412 MOV AL,byte ptr [ESP + 0x12]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000012u)));
  }
  L006a9514: { // 0x6a9514: c6453500 MOV byte ptr [EBP + 0x35],0x0
    m.w8((s.bp+0x00000035u), 0x00000000u);
  }
  L006a9518: { // 0x6a9518: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006a951a: { // 0x6a951a: 7446 JZ 0x006a9562
    if(integer::condition("JZ",flags)) goto L006a9562;
  }
  L006a951c: { // 0x6a951c: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L006a951e: { // 0x6a951e: 740e JZ 0x006a952e
    if(integer::condition("JZ",flags)) goto L006a952e;
  }
  L006a9520: { // 0x6a9520: 396f34 CMP dword ptr [EDI + 0x34],EBP
    (void)integer::sub(m.r32((s.di+0x00000034u)),s.bp,32,flags);
  }
  L006a9523: { // 0x6a9523: 7509 JNZ 0x006a952e
    if(integer::condition("JNZ",flags)) goto L006a952e;
  }
  L006a9525: { // 0x6a9525: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006a9527: { // 0x6a9527: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006a9529: { // 0x6a9529: e89235f2ff CALL 0x005ccac0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005ccac0u,6985006u); flags=s.arithmetic_flags;
  }
  L006a952e: { // 0x6a952e: 668b442420 MOV AX,word ptr [ESP + 0x20]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x00000020u)));
  }
  L006a9533: { // 0x6a9533: 663b053079aa00 CMP AX,word ptr [0x00aa7930]
    (void)integer::sub((s.ax & 0xffffu),m.r16((0x00aa7930u)),16,flags);
  }
  L006a953a: { // 0x6a953a: 750e JNZ 0x006a954a
    if(integer::condition("JNZ",flags)) goto L006a954a;
  }
  L006a953c: { // 0x6a953c: 668b4c2422 MOV CX,word ptr [ESP + 0x22]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000022u)));
  }
  L006a9541: { // 0x6a9541: 663b0d3279aa00 CMP CX,word ptr [0x00aa7932]
    (void)integer::sub((s.cx & 0xffffu),m.r16((0x00aa7932u)),16,flags);
  }
  L006a9548: { // 0x6a9548: 7418 JZ 0x006a9562
    if(integer::condition("JZ",flags)) goto L006a9562;
  }
  L006a954a: { // 0x6a954a: 8d542420 LEA EDX,[ESP + 0x20]
    s.dx = (f.sp+0x00000020u);
  }
  L006a954e: { // 0x6a954e: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006a9550: { // 0x6a9550: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006a9551: { // 0x6a9551: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006a9556: { // 0x6a9556: e8a5bfe9ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6985051u); flags=s.arithmetic_flags;
  }
  L006a955b: { // 0x6a955b: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006a955d: { // 0x6a955d: e8fe0addff CALL 0x0047a060
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047a060u,6985058u); flags=s.arithmetic_flags;
  }
  L006a9562: { // 0x6a9562: 8a442413 MOV AL,byte ptr [ESP + 0x13]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000013u)));
  }
  L006a9566: { // 0x6a9566: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006a9567: { // 0x6a9567: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006a9569: { // 0x6a9569: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006a956a: { // 0x6a956a: 745e JZ 0x006a95ca
    if(integer::condition("JZ",flags)) goto L006a95ca;
  }
  L006a956c: { // 0x6a956c: b201 MOV DL,0x1
    s.dx = with_al(s.dx, 0x00000001u);
  }
  L006a956e: { // 0x6a956e: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L006a9570: { // 0x6a9570: e8db880300 CALL 0x006e1e50
    s.arithmetic_flags=flags; invoke(m,s,f,0x006e1e50u,6985077u); flags=s.arithmetic_flags;
  }
  L006a9575: { // 0x6a9575: a1e887aa00 MOV EAX,[0x00aa87e8]
    s.ax = m.r32((0x00aa87e8u));
  }
  L006a957a: { // 0x6a957a: 8b0df087aa00 MOV ECX,dword ptr [0x00aa87f0]
    s.cx = m.r32((0x00aa87f0u));
  }
  L006a9580: { // 0x6a9580: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L006a9582: { // 0x6a9582: 7c2e JL 0x006a95b2
    if(integer::condition("JL",flags)) goto L006a95b2;
  }
  L006a9584: { // 0x6a9584: 8a0ded87aa00 MOV CL,byte ptr [0x00aa87ed]
    s.cx = with_al(s.cx, m.r8((0x00aa87edu)));
  }
  L006a958a: { // 0x6a958a: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006a958c: { // 0x6a958c: 7504 JNZ 0x006a9592
    if(integer::condition("JNZ",flags)) goto L006a9592;
  }
  L006a958e: { // 0x6a958e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006a9590: { // 0x6a9590: 7538 JNZ 0x006a95ca
    if(integer::condition("JNZ",flags)) goto L006a95ca;
  }
  L006a9592: { // 0x6a9592: 8b0df487aa00 MOV ECX,dword ptr [0x00aa87f4]
    s.cx = m.r32((0x00aa87f4u));
  }
  L006a9598: { // 0x6a9598: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006a959a: { // 0x6a959a: 7e2e JLE 0x006a95ca
    if(integer::condition("JLE",flags)) goto L006a95ca;
  }
  L006a959c: { // 0x6a959c: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L006a959e: { // 0x6a959e: a1e087aa00 MOV EAX,[0x00aa87e0]
    s.ax = m.r32((0x00aa87e0u));
  }
  L006a95a3: { // 0x6a95a3: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006a95a5: { // 0x6a95a5: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006a95a6: { // 0x6a95a6: b9e087aa00 MOV ECX,0xaa87e0
    s.cx = 0x00aa87e0u;
  }
  L006a95ab: { // 0x6a95ab: ff5008 CALL dword ptr [EAX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000008u)),6985134u); flags=s.arithmetic_flags;
  }
  L006a95ae: { // 0x6a95ae: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006a95b0: { // 0x6a95b0: 7418 JZ 0x006a95ca
    if(integer::condition("JZ",flags)) goto L006a95ca;
  }
  L006a95b2: { // 0x6a95b2: 8b0df087aa00 MOV ECX,dword ptr [0x00aa87f0]
    s.cx = m.r32((0x00aa87f0u));
  }
  L006a95b8: { // 0x6a95b8: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L006a95ba: { // 0x6a95ba: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L006a95bb: { // 0x6a95bb: 890df087aa00 MOV dword ptr [0x00aa87f0],ECX
    m.w32((0x00aa87f0u), s.cx);
  }
  L006a95c1: { // 0x6a95c1: 8b0de487aa00 MOV ECX,dword ptr [0x00aa87e4]
    s.cx = m.r32((0x00aa87e4u));
  }
  L006a95c7: { // 0x6a95c7: 892c81 MOV dword ptr [ECX + EAX*0x4],EBP
    m.w32((s.cx+(s.ax * 0x00000004u)), s.bp);
  }
  L006a95ca: { // 0x6a95ca: 8ac3 MOV AL,BL
    s.ax = with_al(s.ax, (s.bx & 0xffu));
  }
  L006a95cc: { // 0x6a95cc: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006a95cd: { // 0x6a95cd: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006a95ce: { // 0x6a95ce: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L006a95cf: { // 0x6a95cf: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
}
void f_002e2a00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006e2a00: { // 0x6e2a00: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006e2a01: { // 0x6e2a01: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006e2a02: { // 0x6e2a02: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006e2a04: { // 0x6e2a04: 8a4640 MOV AL,byte ptr [ESI + 0x40]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000040u)));
  }
  L006e2a07: { // 0x6e2a07: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006e2a09: { // 0x6e2a09: 0f84cc000000 JZ 0x006e2adb
    if(integer::condition("JZ",flags)) goto L006e2adb;
  }
  L006e2a0f: { // 0x6e2a0f: 8a462c MOV AL,byte ptr [ESI + 0x2c]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000002cu)));
  }
  L006e2a12: { // 0x6e2a12: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006e2a14: { // 0x6e2a14: 0f85c1000000 JNZ 0x006e2adb
    if(integer::condition("JNZ",flags)) goto L006e2adb;
  }
  L006e2a1a: { // 0x6e2a1a: 8a442414 MOV AL,byte ptr [ESP + 0x14]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000014u)));
  }
  L006e2a1e: { // 0x6e2a1e: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006e2a1f: { // 0x6e2a1f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006e2a21: { // 0x6e2a21: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006e2a22: { // 0x6e2a22: c644240f01 MOV byte ptr [ESP + 0xf],0x1
    m.w8((f.sp+0x0000000fu), 0x00000001u);
  }
  L006e2a27: { // 0x6e2a27: 0f8594000000 JNZ 0x006e2ac1
    if(integer::condition("JNZ",flags)) goto L006e2ac1;
  }
  L006e2a2d: { // 0x6e2a2d: 8b4624 MOV EAX,dword ptr [ESI + 0x24]
    s.ax = m.r32((s.si+0x00000024u));
  }
  L006e2a30: { // 0x6e2a30: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L006e2a32: { // 0x6e2a32: 8bb8ac000000 MOV EDI,dword ptr [EAX + 0xac]
    s.di = m.r32((s.ax+0x000000acu));
  }
  L006e2a38: { // 0x6e2a38: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L006e2a3a: { // 0x6e2a3a: 0f8481000000 JZ 0x006e2ac1
    if(integer::condition("JZ",flags)) goto L006e2ac1;
  }
  L006e2a40: { // 0x6e2a40: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006e2a41: { // 0x6e2a41: 8b463c MOV EAX,dword ptr [ESI + 0x3c]
    s.ax = m.r32((s.si+0x0000003cu));
  }
  L006e2a44: { // 0x6e2a44: bd01000000 MOV EBP,0x1
    s.bp = 0x00000001u;
  }
  L006e2a49: { // 0x6e2a49: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L006e2a4b: { // 0x6e2a4b: d3e5 SHL EBP,CL
    s.bp = integer::shift(s.bp,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L006e2a4d: { // 0x6e2a4d: 85c5 TEST EBP,EAX
    (void)integer::logical((s.bp)&(s.ax),32,flags);
  }
  L006e2a4f: { // 0x6e2a4f: 753e JNZ 0x006e2a8f
    if(integer::condition("JNZ",flags)) goto L006e2a8f;
  }
  L006e2a51: { // 0x6e2a51: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L006e2a55: { // 0x6e2a55: 8d542424 LEA EDX,[ESP + 0x24]
    s.dx = (f.sp+0x00000024u);
  }
  L006e2a59: { // 0x6e2a59: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006e2a5a: { // 0x6e2a5a: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L006e2a5e: { // 0x6e2a5e: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006e2a5f: { // 0x6e2a5f: 8b5624 MOV EDX,dword ptr [ESI + 0x24]
    s.dx = m.r32((s.si+0x00000024u));
  }
  L006e2a62: { // 0x6e2a62: 8d4630 LEA EAX,[ESI + 0x30]
    s.ax = (s.si+0x00000030u);
  }
  L006e2a65: { // 0x6e2a65: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006e2a66: { // 0x6e2a66: 8b82a4000000 MOV EAX,dword ptr [EDX + 0xa4]
    s.ax = m.r32((s.dx+0x000000a4u));
  }
  L006e2a6c: { // 0x6e2a6c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006e2a6d: { // 0x6e2a6d: 8b88b4000000 MOV ECX,dword ptr [EAX + 0xb4]
    s.cx = m.r32((s.ax+0x000000b4u));
  }
  L006e2a73: { // 0x6e2a73: e8e8a1e0ff CALL 0x004ecc60
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ecc60u,7219832u); flags=s.arithmetic_flags;
  }
  L006e2a78: { // 0x6e2a78: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L006e2a7c: { // 0x6e2a7c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006e2a7d: { // 0x6e2a7d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006e2a7e: { // 0x6e2a7e: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006e2a80: { // 0x6e2a80: e88b88ffff CALL 0x006db310
    s.arithmetic_flags=flags; invoke(m,s,f,0x006db310u,7219845u); flags=s.arithmetic_flags;
  }
  L006e2a85: { // 0x6e2a85: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006e2a87: { // 0x6e2a87: 7506 JNZ 0x006e2a8f
    if(integer::condition("JNZ",flags)) goto L006e2a8f;
  }
  L006e2a89: { // 0x6e2a89: 88442413 MOV byte ptr [ESP + 0x13],AL
    m.w8((f.sp+0x00000013u), (s.ax & 0xffu));
  }
  L006e2a8d: { // 0x6e2a8d: eb21 JMP 0x006e2ab0
    goto L006e2ab0;
  }
  L006e2a8f: { // 0x6e2a8f: 8a442424 MOV AL,byte ptr [ESP + 0x24]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000024u)));
  }
  L006e2a93: { // 0x6e2a93: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006e2a95: { // 0x6e2a95: 7419 JZ 0x006e2ab0
    if(integer::condition("JZ",flags)) goto L006e2ab0;
  }
  L006e2a97: { // 0x6e2a97: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006e2a99: { // 0x6e2a99: e81295ffff CALL 0x006dbfb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006dbfb0u,7219870u); flags=s.arithmetic_flags;
  }
  L006e2a9e: { // 0x6e2a9e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006e2aa0: { // 0x6e2aa0: 740e JZ 0x006e2ab0
    if(integer::condition("JZ",flags)) goto L006e2ab0;
  }
  L006e2aa2: { // 0x6e2aa2: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006e2aa4: { // 0x6e2aa4: e86795ffff CALL 0x006dc010
    s.arithmetic_flags=flags; invoke(m,s,f,0x006dc010u,7219881u); flags=s.arithmetic_flags;
  }
  L006e2aa9: { // 0x6e2aa9: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006e2aab: { // 0x6e2aab: 7403 JZ 0x006e2ab0
    if(integer::condition("JZ",flags)) goto L006e2ab0;
  }
  L006e2aad: { // 0x6e2aad: 096e3c OR dword ptr [ESI + 0x3c],EBP
    m.w32((s.si+0x0000003cu), integer::logical((m.r32((s.si+0x0000003cu)))|(s.bp),32,flags));
  }
  L006e2ab0: { // 0x6e2ab0: 8b7f28 MOV EDI,dword ptr [EDI + 0x28]
    s.di = m.r32((s.di+0x00000028u));
  }
  L006e2ab3: { // 0x6e2ab3: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L006e2ab4: { // 0x6e2ab4: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L006e2ab6: { // 0x6e2ab6: 7589 JNZ 0x006e2a41
    if(integer::condition("JNZ",flags)) goto L006e2a41;
  }
  L006e2ab8: { // 0x6e2ab8: 8a442413 MOV AL,byte ptr [ESP + 0x13]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000013u)));
  }
  L006e2abc: { // 0x6e2abc: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006e2abd: { // 0x6e2abd: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006e2abf: { // 0x6e2abf: 740f JZ 0x006e2ad0
    if(integer::condition("JZ",flags)) goto L006e2ad0;
  }
  L006e2ac1: { // 0x6e2ac1: 8a442420 MOV AL,byte ptr [ESP + 0x20]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000020u)));
  }
  L006e2ac5: { // 0x6e2ac5: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006e2ac7: { // 0x6e2ac7: 7407 JZ 0x006e2ad0
    if(integer::condition("JZ",flags)) goto L006e2ad0;
  }
  L006e2ac9: { // 0x6e2ac9: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006e2acb: { // 0x6e2acb: e870feffff CALL 0x006e2940
    s.arithmetic_flags=flags; invoke(m,s,f,0x006e2940u,7219920u); flags=s.arithmetic_flags;
  }
  L006e2ad0: { // 0x6e2ad0: 8a44240f MOV AL,byte ptr [ESP + 0xf]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000000fu)));
  }
  L006e2ad4: { // 0x6e2ad4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006e2ad5: { // 0x6e2ad5: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006e2ad6: { // 0x6e2ad6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006e2ad7: { // 0x6e2ad7: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L006e2ad8: { // 0x6e2ad8: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
  L006e2adb: { // 0x6e2adb: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006e2add: { // 0x6e2add: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006e2ade: { // 0x6e2ade: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L006e2adf: { // 0x6e2adf: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
}
void f_0007a060(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0047a060: { // 0x0047a060: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0047a061: { // 0x0047a061: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0047a063: { // 0x0047a063: 8b463c MOV EAX,dword ptr [ESI + 0x3c]
    s.ax = m.r32((s.si+0x0000003cu));
  }
  L0047a066: { // 0x0047a066: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0047a068: { // 0x0047a068: 7403 JZ 0x0047a06d
    if(integer::condition("JZ",flags)) goto L0047a06d;
  }
  L0047a06a: { // 0x0047a06a: ff482c DEC dword ptr [EAX + 0x2c]
    m.w32((s.ax+0x0000002cu), integer::decrement(m.r32((s.ax+0x0000002cu)),32,flags));
  }
  L0047a06d: { // 0x0047a06d: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L0047a071: { // 0x0047a071: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0047a073: { // 0x0047a073: 89463c MOV dword ptr [ESI + 0x3c],EAX
    m.w32((s.si+0x0000003cu), s.ax);
  }
  L0047a076: { // 0x0047a076: 745e JZ 0x0047a0d6
    if(integer::condition("JZ",flags)) goto L0047a0d6;
  }
  L0047a078: { // 0x0047a078: a180b98100 MOV EAX,[0x0081b980]
    s.ax = m.r32((0x0081b980u));
  }
  L0047a07d: { // 0x0047a07d: 8b0d88b98100 MOV ECX,dword ptr [0x0081b988]
    s.cx = m.r32((0x0081b988u));
  }
  L0047a083: { // 0x0047a083: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L0047a085: { // 0x0047a085: 7c2e JL 0x0047a0b5
    if(integer::condition("JL",flags)) goto L0047a0b5;
  }
  L0047a087: { // 0x0047a087: 8a0d85b98100 MOV CL,byte ptr [0x0081b985]
    s.cx = with_al(s.cx, m.r8((0x0081b985u)));
  }
  L0047a08d: { // 0x0047a08d: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0047a08f: { // 0x0047a08f: 7504 JNZ 0x0047a095
    if(integer::condition("JNZ",flags)) goto L0047a095;
  }
  L0047a091: { // 0x0047a091: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0047a093: { // 0x0047a093: 753b JNZ 0x0047a0d0
    if(integer::condition("JNZ",flags)) goto L0047a0d0;
  }
  L0047a095: { // 0x0047a095: 8b0d8cb98100 MOV ECX,dword ptr [0x0081b98c]
    s.cx = m.r32((0x0081b98cu));
  }
  L0047a09b: { // 0x0047a09b: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0047a09d: { // 0x0047a09d: 7e31 JLE 0x0047a0d0
    if(integer::condition("JLE",flags)) goto L0047a0d0;
  }
  L0047a09f: { // 0x0047a09f: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0047a0a1: { // 0x0047a0a1: a178b98100 MOV EAX,[0x0081b978]
    s.ax = m.r32((0x0081b978u));
  }
  L0047a0a6: { // 0x0047a0a6: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0047a0a8: { // 0x0047a0a8: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0047a0a9: { // 0x0047a0a9: b978b98100 MOV ECX,0x81b978
    s.cx = 0x0081b978u;
  }
  L0047a0ae: { // 0x0047a0ae: ff5008 CALL dword ptr [EAX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000008u)),4694193u); flags=s.arithmetic_flags;
  }
  L0047a0b1: { // 0x0047a0b1: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0047a0b3: { // 0x0047a0b3: 741b JZ 0x0047a0d0
    if(integer::condition("JZ",flags)) goto L0047a0d0;
  }
  L0047a0b5: { // 0x0047a0b5: 8b0d88b98100 MOV ECX,dword ptr [0x0081b988]
    s.cx = m.r32((0x0081b988u));
  }
  L0047a0bb: { // 0x0047a0bb: 8b157cb98100 MOV EDX,dword ptr [0x0081b97c]
    s.dx = m.r32((0x0081b97cu));
  }
  L0047a0c1: { // 0x0047a0c1: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0047a0c3: { // 0x0047a0c3: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0047a0c4: { // 0x0047a0c4: 890d88b98100 MOV dword ptr [0x0081b988],ECX
    m.w32((0x0081b988u), s.cx);
  }
  L0047a0ca: { // 0x0047a0ca: 8b4e24 MOV ECX,dword ptr [ESI + 0x24]
    s.cx = m.r32((s.si+0x00000024u));
  }
  L0047a0cd: { // 0x0047a0cd: 890c82 MOV dword ptr [EDX + EAX*0x4],ECX
    m.w32((s.dx+(s.ax * 0x00000004u)), s.cx);
  }
  L0047a0d0: { // 0x0047a0d0: 8b763c MOV ESI,dword ptr [ESI + 0x3c]
    s.si = m.r32((s.si+0x0000003cu));
  }
  L0047a0d3: { // 0x0047a0d3: ff462c INC dword ptr [ESI + 0x2c]
    m.w32((s.si+0x0000002cu), integer::increment(m.r32((s.si+0x0000002cu)),32,flags));
  }
  L0047a0d6: { // 0x0047a0d6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047a0d7: { // 0x0047a0d7: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 5591344u:f_00155130(m,s,child,{});break;
case 4369872u:f_0002add0(m,s,child,{});break;
case 5526784u:f_00145500(m,s,child,{});break;
case 6984768u:f_002a9440(m,s,child,{});break;
case 7219712u:f_002e2a00(m,s,child,{});break;
case 4694112u:f_0007a060(m,s,child,{});break;
default:throw std::domain_error("recovery246 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0055c850(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0055c850: { // 0x55c850: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L0055c853: { // 0x55c853: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0055c854: { // 0x55c854: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0055c855: { // 0x55c855: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0055c856: { // 0x55c856: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0055c857: { // 0x55c857: 8b7c2420 MOV EDI,dword ptr [ESP + 0x20]
    s.di = m.r32((f.sp+0x00000020u));
  }
  L0055c85b: { // 0x55c85b: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0055c85f: { // 0x55c85f: 8b0da09d8300 MOV ECX,dword ptr [0x00839da0]
    s.cx = m.r32((0x00839da0u));
  }
  L0055c865: { // 0x55c865: 8bdf MOV EBX,EDI
    s.bx = s.di;
  }
  L0055c867: { // 0x55c867: 895c2420 MOV dword ptr [ESP + 0x20],EBX
    m.w32((f.sp+0x00000020u), s.bx);
  }
  L0055c86b: { // 0x55c86b: 668b15a29d8300 MOV DX,word ptr [0x00839da2]
    s.dx = with_ax(s.dx, m.r16((0x00839da2u)));
  }
  L0055c872: { // 0x55c872: 8d3419 LEA ESI,[ECX + EBX*0x1]
    s.si = (s.cx+(s.bx * 0x00000001u));
  }
  L0055c875: { // 0x55c875: 6603542422 ADD DX,word ptr [ESP + 0x22]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((f.sp+0x00000022u)),16,flags));
  }
  L0055c87a: { // 0x55c87a: 6689742410 MOV word ptr [ESP + 0x10],SI
    m.w16((f.sp+0x00000010u), (s.si & 0xffffu));
  }
  L0055c87f: { // 0x55c87f: 0fbff6 MOVSX ESI,SI
    s.si = std::uint32_t(integer::sign_extend((s.si & 0xffffu),16));
  }
  L0055c882: { // 0x55c882: 0fbfc2 MOVSX EAX,DX
    s.ax = std::uint32_t(integer::sign_extend((s.dx & 0xffffu),16));
  }
  L0055c885: { // 0x55c885: 6689542412 MOV word ptr [ESP + 0x12],DX
    m.w16((f.sp+0x00000012u), (s.dx & 0xffffu));
  }
  L0055c88a: { // 0x55c88a: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L0055c88e: { // 0x55c88e: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L0055c891: { // 0x55c891: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L0055c893: { // 0x55c893: 895c2420 MOV dword ptr [ESP + 0x20],EBX
    m.w32((f.sp+0x00000020u), s.bx);
  }
  L0055c897: { // 0x55c897: 7814 JS 0x0055c8ad
    if(integer::condition("JS",flags)) goto L0055c8ad;
  }
  L0055c899: { // 0x55c899: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L0055c89e: { // 0x55c89e: 7d0d JGE 0x0055c8ad
    if(integer::condition("JGE",flags)) goto L0055c8ad;
  }
  L0055c8a0: { // 0x55c8a0: 8b3558a98100 MOV ESI,dword ptr [0x0081a958]
    s.si = m.r32((0x0081a958u));
  }
  L0055c8a6: { // 0x55c8a6: 8b0486 MOV EAX,dword ptr [ESI + EAX*0x4]
    s.ax = m.r32((s.si+(s.ax * 0x00000004u)));
  }
  L0055c8a9: { // 0x55c8a9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0055c8ab: { // 0x55c8ab: 750b JNZ 0x0055c8b8
    if(integer::condition("JNZ",flags)) goto L0055c8b8;
  }
  L0055c8ad: { // 0x55c8ad: 891d3476a500 MOV dword ptr [0x00a57634],EBX
    m.w32((0x00a57634u), s.bx);
  }
  L0055c8b3: { // 0x55c8b3: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L0055c8b8: { // 0x55c8b8: 8b4044 MOV EAX,dword ptr [EAX + 0x44]
    s.ax = m.r32((s.ax+0x00000044u));
  }
  L0055c8bb: { // 0x55c8bb: 3dcd000000 CMP EAX,0xcd
    (void)integer::sub(s.ax,0x000000cdu,32,flags);
  }
  L0055c8c0: { // 0x55c8c0: 7c07 JL 0x0055c8c9
    if(integer::condition("JL",flags)) goto L0055c8c9;
  }
  L0055c8c2: { // 0x55c8c2: 3de8000000 CMP EAX,0xe8
    (void)integer::sub(s.ax,0x000000e8u,32,flags);
  }
  L0055c8c7: { // 0x55c8c7: 7ea2 JLE 0x0055c86b
    if(integer::condition("JLE",flags)) goto L0055c86b;
  }
  L0055c8c9: { // 0x55c8c9: 8b2db09d8300 MOV EBP,dword ptr [0x00839db0]
    s.bp = m.r32((0x00839db0u));
  }
  L0055c8cf: { // 0x55c8cf: 897c2420 MOV dword ptr [ESP + 0x20],EDI
    m.w32((f.sp+0x00000020u), s.di);
  }
  L0055c8d3: { // 0x55c8d3: 8d042b LEA EAX,[EBX + EBP*0x1]
    s.ax = (s.bx+(s.bp * 0x00000001u));
  }
  L0055c8d6: { // 0x55c8d6: 668b1db29d8300 MOV BX,word ptr [0x00839db2]
    s.bx = with_ax(s.bx, m.r16((0x00839db2u)));
  }
  L0055c8dd: { // 0x55c8dd: 6689442414 MOV word ptr [ESP + 0x14],AX
    m.w16((f.sp+0x00000014u), (s.ax & 0xffffu));
  }
  L0055c8e2: { // 0x55c8e2: 668bc3 MOV AX,BX
    s.ax = with_ax(s.ax, (s.bx & 0xffffu));
  }
  L0055c8e5: { // 0x55c8e5: 6603c2 ADD AX,DX
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),(s.dx & 0xffffu),16,flags));
  }
  L0055c8e8: { // 0x55c8e8: 6689442416 MOV word ptr [ESP + 0x16],AX
    m.w16((f.sp+0x00000016u), (s.ax & 0xffffu));
  }
  L0055c8ed: { // 0x55c8ed: 668bd3 MOV DX,BX
    s.dx = with_ax(s.dx, (s.bx & 0xffffu));
  }
  L0055c8f0: { // 0x55c8f0: 8d342f LEA ESI,[EDI + EBP*0x1]
    s.si = (s.di+(s.bp * 0x00000001u));
  }
  L0055c8f3: { // 0x55c8f3: 6603542422 ADD DX,word ptr [ESP + 0x22]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((f.sp+0x00000022u)),16,flags));
  }
  L0055c8f8: { // 0x55c8f8: 6689742410 MOV word ptr [ESP + 0x10],SI
    m.w16((f.sp+0x00000010u), (s.si & 0xffffu));
  }
  L0055c8fd: { // 0x55c8fd: 0fbff6 MOVSX ESI,SI
    s.si = std::uint32_t(integer::sign_extend((s.si & 0xffffu),16));
  }
  L0055c900: { // 0x55c900: 0fbfc2 MOVSX EAX,DX
    s.ax = std::uint32_t(integer::sign_extend((s.dx & 0xffffu),16));
  }
  L0055c903: { // 0x55c903: 6689542412 MOV word ptr [ESP + 0x12],DX
    m.w16((f.sp+0x00000012u), (s.dx & 0xffffu));
  }
  L0055c908: { // 0x55c908: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L0055c90c: { // 0x55c90c: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L0055c90f: { // 0x55c90f: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L0055c911: { // 0x55c911: 897c2420 MOV dword ptr [ESP + 0x20],EDI
    m.w32((f.sp+0x00000020u), s.di);
  }
  L0055c915: { // 0x55c915: 7814 JS 0x0055c92b
    if(integer::condition("JS",flags)) goto L0055c92b;
  }
  L0055c917: { // 0x55c917: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L0055c91c: { // 0x55c91c: 7d0d JGE 0x0055c92b
    if(integer::condition("JGE",flags)) goto L0055c92b;
  }
  L0055c91e: { // 0x55c91e: 8b3558a98100 MOV ESI,dword ptr [0x0081a958]
    s.si = m.r32((0x0081a958u));
  }
  L0055c924: { // 0x55c924: 8b0486 MOV EAX,dword ptr [ESI + EAX*0x4]
    s.ax = m.r32((s.si+(s.ax * 0x00000004u)));
  }
  L0055c927: { // 0x55c927: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0055c929: { // 0x55c929: 750b JNZ 0x0055c936
    if(integer::condition("JNZ",flags)) goto L0055c936;
  }
  L0055c92b: { // 0x55c92b: 893d3476a500 MOV dword ptr [0x00a57634],EDI
    m.w32((0x00a57634u), s.di);
  }
  L0055c931: { // 0x55c931: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L0055c936: { // 0x55c936: 8b4044 MOV EAX,dword ptr [EAX + 0x44]
    s.ax = m.r32((s.ax+0x00000044u));
  }
  L0055c939: { // 0x55c939: 3dcd000000 CMP EAX,0xcd
    (void)integer::sub(s.ax,0x000000cdu,32,flags);
  }
  L0055c93e: { // 0x55c93e: 7c07 JL 0x0055c947
    if(integer::condition("JL",flags)) goto L0055c947;
  }
  L0055c940: { // 0x55c940: 3de8000000 CMP EAX,0xe8
    (void)integer::sub(s.ax,0x000000e8u,32,flags);
  }
  L0055c945: { // 0x55c945: 7ea6 JLE 0x0055c8ed
    if(integer::condition("JLE",flags)) goto L0055c8ed;
  }
  L0055c947: { // 0x55c947: 660315a29d8300 ADD DX,word ptr [0x00839da2]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((0x00839da2u)),16,flags));
  }
  L0055c94e: { // 0x55c94e: 03f9 ADD EDI,ECX
    s.di = integer::add(s.di,s.cx,32,flags);
  }
  L0055c950: { // 0x55c950: 66897c2420 MOV word ptr [ESP + 0x20],DI
    m.w16((f.sp+0x00000020u), (s.di & 0xffffu));
  }
  L0055c955: { // 0x55c955: 6689542422 MOV word ptr [ESP + 0x22],DX
    m.w16((f.sp+0x00000022u), (s.dx & 0xffffu));
  }
  L0055c95a: { // 0x55c95a: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L0055c95e: { // 0x55c95e: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L0055c962: { // 0x55c962: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0055c963: { // 0x55c963: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0055c967: { // 0x55c967: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0055c968: { // 0x55c968: e8c387ffff CALL 0x00555130
    s.arithmetic_flags=flags; invoke(m,s,f,0x00555130u,5622125u); flags=s.arithmetic_flags;
  }
  L0055c96d: { // 0x55c96d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0055c96e: { // 0x55c96e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0055c96f: { // 0x55c96f: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0055c970: { // 0x55c970: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0055c971: { // 0x55c971: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0055c974: { // 0x55c974: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
