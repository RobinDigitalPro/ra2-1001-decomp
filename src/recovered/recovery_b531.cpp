#include "recovered/recovery_b531_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b531 {
namespace {
void f_00172700(Memory&,State&,Frame&,const Operations&);
void f_00157450(Memory&,State&,Frame&,const Operations&);
void f_0007b190(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_0018a810(Memory&,State&,Frame&,const Operations&);
void f_0016b760(Memory&,State&,Frame&,const Operations&);
void f_00172ad0(Memory&,State&,Frame&,const Operations&);
void f_001851f0(Memory&,State&,Frame&,const Operations&);
void f_0001c300(Memory&,State&,Frame&,const Operations&);
void f_0022fde0(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_00172700(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00572700: { // 0x572700: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00572701: { // 0x572701: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00572702: { // 0x572702: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00572703: { // 0x572703: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00572704: { // 0x572704: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00572705: { // 0x572705: 8b7c2418 MOV EDI,dword ptr [ESP + 0x18]
    s.di = m.r32((f.sp+0x00000018u));
  }
  L00572709: { // 0x572709: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L0057270d: { // 0x57270d: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L00572711: { // 0x572711: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00572713: { // 0x572713: 668b4f04 MOV CX,word ptr [EDI + 0x4]
    s.cx = with_ax(s.cx, m.r16((s.di+0x00000004u)));
  }
  L00572717: { // 0x572717: 668b07 MOV AX,word ptr [EDI]
    s.ax = with_ax(s.ax, m.r16((s.di)));
  }
  L0057271a: { // 0x57271a: 66894c241e MOV word ptr [ESP + 0x1e],CX
    m.w16((f.sp+0x0000001eu), (s.cx & 0xffffu));
  }
  L0057271f: { // 0x57271f: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00572720: { // 0x572720: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00572725: { // 0x572725: 6689442420 MOV word ptr [ESP + 0x20],AX
    m.w16((f.sp+0x00000020u), (s.ax & 0xffffu));
  }
  L0057272a: { // 0x57272a: e8214dfeff CALL 0x00557450
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557450u,5711663u); flags=s.arithmetic_flags;
  }
  L0057272f: { // 0x57272f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00572731: { // 0x572731: 0f8433010000 JZ 0x0057286a
    if(integer::condition("JZ",flags)) goto L0057286a;
  }
  L00572737: { // 0x572737: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  L0057273a: { // 0x57273a: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  L0057273c: { // 0x57273c: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0057273e: { // 0x57273e: 8d5408ff LEA EDX,[EAX + ECX*0x1 + -0x1]
    s.dx = (s.ax+(s.cx * 0x00000001u)-0x00000001u);
  }
  L00572742: { // 0x572742: 668b4704 MOV AX,word ptr [EDI + 0x4]
    s.ax = with_ax(s.ax, m.r16((s.di+0x00000004u)));
  }
  L00572746: { // 0x572746: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L0057274a: { // 0x57274a: 668954241c MOV word ptr [ESP + 0x1c],DX
    m.w16((f.sp+0x0000001cu), (s.dx & 0xffffu));
  }
  L0057274f: { // 0x57274f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00572750: { // 0x572750: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00572755: { // 0x572755: 6689442422 MOV word ptr [ESP + 0x22],AX
    m.w16((f.sp+0x00000022u), (s.ax & 0xffffu));
  }
  L0057275a: { // 0x57275a: e8f14cfeff CALL 0x00557450
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557450u,5711711u); flags=s.arithmetic_flags;
  }
  L0057275f: { // 0x57275f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00572761: { // 0x572761: 0f8403010000 JZ 0x0057286a
    if(integer::condition("JZ",flags)) goto L0057286a;
  }
  L00572767: { // 0x572767: 668b17 MOV DX,word ptr [EDI]
    s.dx = with_ax(s.dx, m.r16((s.di)));
  }
  L0057276a: { // 0x57276a: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  L0057276d: { // 0x57276d: 8b4f0c MOV ECX,dword ptr [EDI + 0xc]
    s.cx = m.r32((s.di+0x0000000cu));
  }
  L00572770: { // 0x572770: 6689542418 MOV word ptr [ESP + 0x18],DX
    m.w16((f.sp+0x00000018u), (s.dx & 0xffffu));
  }
  L00572775: { // 0x572775: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00572777: { // 0x572777: 8d5408ff LEA EDX,[EAX + ECX*0x1 + -0x1]
    s.dx = (s.ax+(s.cx * 0x00000001u)-0x00000001u);
  }
  L0057277b: { // 0x57277b: 8d44241c LEA EAX,[ESP + 0x1c]
    s.ax = (f.sp+0x0000001cu);
  }
  L0057277f: { // 0x57277f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00572780: { // 0x572780: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00572785: { // 0x572785: 6689542422 MOV word ptr [ESP + 0x22],DX
    m.w16((f.sp+0x00000022u), (s.dx & 0xffffu));
  }
  L0057278a: { // 0x57278a: e8c14cfeff CALL 0x00557450
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557450u,5711759u); flags=s.arithmetic_flags;
  }
  L0057278f: { // 0x57278f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00572791: { // 0x572791: 0f84d3000000 JZ 0x0057286a
    if(integer::condition("JZ",flags)) goto L0057286a;
  }
  L00572797: { // 0x572797: 8b4f08 MOV ECX,dword ptr [EDI + 0x8]
    s.cx = m.r32((s.di+0x00000008u));
  }
  L0057279a: { // 0x57279a: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L0057279c: { // 0x57279c: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0057279e: { // 0x57279e: 8d4411ff LEA EAX,[ECX + EDX*0x1 + -0x1]
    s.ax = (s.cx+(s.dx * 0x00000001u)-0x00000001u);
  }
  L005727a2: { // 0x5727a2: 8b4f04 MOV ECX,dword ptr [EDI + 0x4]
    s.cx = m.r32((s.di+0x00000004u));
  }
  L005727a5: { // 0x5727a5: 8b570c MOV EDX,dword ptr [EDI + 0xc]
    s.dx = m.r32((s.di+0x0000000cu));
  }
  L005727a8: { // 0x5727a8: 668944241c MOV word ptr [ESP + 0x1c],AX
    m.w16((f.sp+0x0000001cu), (s.ax & 0xffffu));
  }
  L005727ad: { // 0x5727ad: 8d4411ff LEA EAX,[ECX + EDX*0x1 + -0x1]
    s.ax = (s.cx+(s.dx * 0x00000001u)-0x00000001u);
  }
  L005727b1: { // 0x5727b1: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L005727b5: { // 0x5727b5: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005727b6: { // 0x5727b6: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L005727bb: { // 0x5727bb: 6689442422 MOV word ptr [ESP + 0x22],AX
    m.w16((f.sp+0x00000022u), (s.ax & 0xffffu));
  }
  L005727c0: { // 0x5727c0: e88b4cfeff CALL 0x00557450
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557450u,5711813u); flags=s.arithmetic_flags;
  }
  L005727c5: { // 0x5727c5: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005727c7: { // 0x5727c7: 0f849d000000 JZ 0x0057286a
    if(integer::condition("JZ",flags)) goto L0057286a;
  }
  L005727cd: { // 0x5727cd: 8b5f04 MOV EBX,dword ptr [EDI + 0x4]
    s.bx = m.r32((s.di+0x00000004u));
  }
  L005727d0: { // 0x5727d0: 8b4f0c MOV ECX,dword ptr [EDI + 0xc]
    s.cx = m.r32((s.di+0x0000000cu));
  }
  L005727d3: { // 0x5727d3: 8bd3 MOV EDX,EBX
    s.dx = s.bx;
  }
  L005727d5: { // 0x5727d5: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L005727d7: { // 0x5727d7: 3bda CMP EBX,EDX
    (void)integer::sub(s.bx,s.dx,32,flags);
  }
  L005727d9: { // 0x5727d9: 0f8d81000000 JGE 0x00572860
    if(integer::condition("JGE",flags)) goto L00572860;
  }
  L005727df: { // 0x5727df: 8b6c241c MOV EBP,dword ptr [ESP + 0x1c]
    s.bp = m.r32((f.sp+0x0000001cu));
  }
  L005727e3: { // 0x5727e3: 8b37 MOV ESI,dword ptr [EDI]
    s.si = m.r32((s.di));
  }
  L005727e5: { // 0x5727e5: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  L005727e8: { // 0x5727e8: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L005727ea: { // 0x5727ea: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L005727ec: { // 0x5727ec: 7d65 JGE 0x00572853
    if(integer::condition("JGE",flags)) goto L00572853;
  }
  L005727ee: { // 0x5727ee: 8b0d3c86a500 MOV ECX,dword ptr [0x00a5863c]
    s.cx = m.r32((0x00a5863cu));
  }
  L005727f4: { // 0x5727f4: 6689742418 MOV word ptr [ESP + 0x18],SI
    m.w16((f.sp+0x00000018u), (s.si & 0xffffu));
  }
  L005727f9: { // 0x5727f9: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005727fb: { // 0x5727fb: 66895c241a MOV word ptr [ESP + 0x1a],BX
    m.w16((f.sp+0x0000001au), (s.bx & 0xffffu));
  }
  L00572800: { // 0x572800: 7505 JNZ 0x00572807
    if(integer::condition("JNZ",flags)) goto L00572807;
  }
  L00572802: { // 0x572802: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L00572805: { // 0x572805: eb19 JMP 0x00572820
    goto L00572820;
  }
  L00572807: { // 0x572807: 0fbfc3 MOVSX EAX,BX
    s.ax = std::uint32_t(integer::sign_extend((s.bx & 0xffffu),16));
  }
  L0057280a: { // 0x57280a: 0faf054c6b8300 IMUL EAX,dword ptr [0x00836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  L00572811: { // 0x572811: 0fbfd6 MOVSX EDX,SI
    s.dx = std::uint32_t(integer::sign_extend((s.si & 0xffffu),16));
  }
  L00572814: { // 0x572814: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00572816: { // 0x572816: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L00572819: { // 0x572819: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L0057281c: { // 0x57281c: 8b440838 MOV EAX,dword ptr [EAX + ECX*0x1 + 0x38]
    s.ax = m.r32((s.ax+(s.cx * 0x00000001u)+0x00000038u));
  }
  L00572820: { // 0x572820: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00572824: { // 0x572824: 3b4108 CMP EAX,dword ptr [ECX + 0x8]
    (void)integer::sub(s.ax,m.r32((s.cx+0x00000008u)),32,flags);
  }
  L00572827: { // 0x572827: 7404 JZ 0x0057282d
    if(integer::condition("JZ",flags)) goto L0057282d;
  }
  L00572829: { // 0x572829: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L0057282b: { // 0x57282b: 753d JNZ 0x0057286a
    if(integer::condition("JNZ",flags)) goto L0057286a;
  }
  L0057282d: { // 0x57282d: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L00572831: { // 0x572831: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00572836: { // 0x572836: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00572837: { // 0x572837: e8c42cfdff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5711932u); flags=s.arithmetic_flags;
  }
  L0057283c: { // 0x57283c: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0057283e: { // 0x57283e: e84d89f0ff CALL 0x0047b190
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b190u,5711939u); flags=s.arithmetic_flags;
  }
  L00572843: { // 0x572843: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00572845: { // 0x572845: 7423 JZ 0x0057286a
    if(integer::condition("JZ",flags)) goto L0057286a;
  }
  L00572847: { // 0x572847: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  L0057284a: { // 0x57284a: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L0057284c: { // 0x57284c: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0057284d: { // 0x57284d: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0057284f: { // 0x57284f: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L00572851: { // 0x572851: 7c9b JL 0x005727ee
    if(integer::condition("JL",flags)) goto L005727ee;
  }
  L00572853: { // 0x572853: 8b4f04 MOV ECX,dword ptr [EDI + 0x4]
    s.cx = m.r32((s.di+0x00000004u));
  }
  L00572856: { // 0x572856: 8b570c MOV EDX,dword ptr [EDI + 0xc]
    s.dx = m.r32((s.di+0x0000000cu));
  }
  L00572859: { // 0x572859: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L0057285a: { // 0x57285a: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L0057285c: { // 0x57285c: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L0057285e: { // 0x57285e: 7c83 JL 0x005727e3
    if(integer::condition("JL",flags)) goto L005727e3;
  }
  L00572860: { // 0x572860: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00572861: { // 0x572861: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00572862: { // 0x572862: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00572863: { // 0x572863: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00572865: { // 0x572865: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00572866: { // 0x572866: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00572867: { // 0x572867: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0057286a: { // 0x57286a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0057286b: { // 0x57286b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057286c: { // 0x57286c: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0057286d: { // 0x57286d: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0057286f: { // 0x57286f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00572870: { // 0x572870: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00572871: { // 0x572871: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00157450(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00557450: { // 0x557450: 8a442408 MOV AL,byte ptr [ESP + 0x8]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000008u)));
  }
  L00557454: { // 0x557454: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00557455: { // 0x557455: 8b5c2408 MOV EBX,dword ptr [ESP + 0x8]
    s.bx = m.r32((f.sp+0x00000008u));
  }
  L00557459: { // 0x557459: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0055745a: { // 0x55745a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0055745b: { // 0x55745b: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0055745d: { // 0x55745d: 0fbf5302 MOVSX EDX,word ptr [EBX + 0x2]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.bx+0x00000002u)),16));
  }
  L00557461: { // 0x557461: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00557462: { // 0x557462: 0fbf3b MOVSX EDI,word ptr [EBX]
    s.di = std::uint32_t(integer::sign_extend(m.r16((s.bx)),16));
  }
  L00557465: { // 0x557465: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00557467: { // 0x557467: 7454 JZ 0x005574bd
    if(integer::condition("JZ",flags)) goto L005574bd;
  }
  L00557469: { // 0x557469: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L0055746b: { // 0x55746b: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L0055746e: { // 0x55746e: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L00557470: { // 0x557470: 7814 JS 0x00557486
    if(integer::condition("JS",flags)) goto L00557486;
  }
  L00557472: { // 0x557472: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00557477: { // 0x557477: 7d0d JGE 0x00557486
    if(integer::condition("JGE",flags)) goto L00557486;
  }
  L00557479: { // 0x557479: 8b3558a98100 MOV ESI,dword ptr [0x0081a958]
    s.si = m.r32((0x0081a958u));
  }
  L0055747f: { // 0x55747f: 8b0486 MOV EAX,dword ptr [ESI + EAX*0x4]
    s.ax = m.r32((s.si+(s.ax * 0x00000004u)));
  }
  L00557482: { // 0x557482: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00557484: { // 0x557484: 750c JNZ 0x00557492
    if(integer::condition("JNZ",flags)) goto L00557492;
  }
  L00557486: { // 0x557486: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L00557488: { // 0x557488: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L0055748d: { // 0x55748d: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L00557492: { // 0x557492: 8a981c010000 MOV BL,byte ptr [EAX + 0x11c]
    s.bx = with_al(s.bx, m.r8((s.ax+0x0000011cu)));
  }
  L00557498: { // 0x557498: 0fbeb01b010000 MOVSX ESI,byte ptr [EAX + 0x11b]
    s.si = std::uint32_t(integer::sign_extend(m.r8((s.ax+0x0000011bu)),8));
  }
  L0055749f: { // 0x55749f: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L005574a1: { // 0x5574a1: 741a JZ 0x005574bd
    if(integer::condition("JZ",flags)) goto L005574bd;
  }
  L005574a3: { // 0x5574a3: 8b81fc000000 MOV EAX,dword ptr [ECX + 0xfc]
    s.ax = m.r32((s.cx+0x000000fcu));
  }
  L005574a9: { // 0x5574a9: 8b99f0000000 MOV EBX,dword ptr [ECX + 0xf0]
    s.bx = m.r32((s.cx+0x000000f0u));
  }
  L005574af: { // 0x5574af: 8d444304 LEA EAX,[EBX + EAX*0x2 + 0x4]
    s.ax = (s.bx+(s.ax * 0x00000002u)+0x00000004u);
  }
  L005574b3: { // 0x5574b3: 8d1c3a LEA EBX,[EDX + EDI*0x1]
    s.bx = (s.dx+(s.di * 0x00000001u));
  }
  L005574b6: { // 0x5574b6: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L005574b8: { // 0x5574b8: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L005574ba: { // 0x5574ba: 7d01 JGE 0x005574bd
    if(integer::condition("JGE",flags)) goto L005574bd;
  }
  L005574bc: { // 0x5574bc: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L005574bd: { // 0x5574bd: 8b99fc000000 MOV EBX,dword ptr [ECX + 0xfc]
    s.bx = m.r32((s.cx+0x000000fcu));
  }
  L005574c3: { // 0x5574c3: 8b81f0000000 MOV EAX,dword ptr [ECX + 0xf0]
    s.ax = m.r32((s.cx+0x000000f0u));
  }
  L005574c9: { // 0x5574c9: 8d2c3a LEA EBP,[EDX + EDI*0x1]
    s.bp = (s.dx+(s.di * 0x00000001u));
  }
  L005574cc: { // 0x5574cc: 8d1c58 LEA EBX,[EAX + EBX*0x2]
    s.bx = (s.ax+(s.bx * 0x00000002u));
  }
  L005574cf: { // 0x5574cf: 03de ADD EBX,ESI
    s.bx = integer::add(s.bx,s.si,32,flags);
  }
  L005574d1: { // 0x5574d1: 3beb CMP EBP,EBX
    (void)integer::sub(s.bp,s.bx,32,flags);
  }
  L005574d3: { // 0x5574d3: 7e49 JLE 0x0055751e
    if(integer::condition("JLE",flags)) goto L0055751e;
  }
  L005574d5: { // 0x5574d5: 8b9904010000 MOV EBX,dword ptr [ECX + 0x104]
    s.bx = m.r32((s.cx+0x00000104u));
  }
  L005574db: { // 0x5574db: 8ba9fc000000 MOV EBP,dword ptr [ECX + 0xfc]
    s.bp = m.r32((s.cx+0x000000fcu));
  }
  L005574e1: { // 0x5574e1: 03dd ADD EBX,EBP
    s.bx = integer::add(s.bx,s.bp,32,flags);
  }
  L005574e3: { // 0x5574e3: 8d5c5802 LEA EBX,[EAX + EBX*0x2 + 0x2]
    s.bx = (s.ax+(s.bx * 0x00000002u)+0x00000002u);
  }
  L005574e7: { // 0x5574e7: 03de ADD EBX,ESI
    s.bx = integer::add(s.bx,s.si,32,flags);
  }
  L005574e9: { // 0x5574e9: 8d343a LEA ESI,[EDX + EDI*0x1]
    s.si = (s.dx+(s.di * 0x00000001u));
  }
  L005574ec: { // 0x5574ec: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L005574ee: { // 0x5574ee: 7f2e JG 0x0055751e
    if(integer::condition("JG",flags)) goto L0055751e;
  }
  L005574f0: { // 0x5574f0: 8bb1f8000000 MOV ESI,dword ptr [ECX + 0xf8]
    s.si = m.r32((s.cx+0x000000f8u));
  }
  L005574f6: { // 0x5574f6: 8b8900010000 MOV ECX,dword ptr [ECX + 0x100]
    s.cx = m.r32((s.cx+0x00000100u));
  }
  L005574fc: { // 0x5574fc: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L005574fe: { // 0x5574fe: 8bdf MOV EBX,EDI
    s.bx = s.di;
  }
  L00557500: { // 0x557500: d1e1 SHL ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::left);
  }
  L00557502: { // 0x557502: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00557504: { // 0x557504: 2bda SUB EBX,EDX
    s.bx = integer::sub(s.bx,s.dx,32,flags);
  }
  L00557506: { // 0x557506: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L00557508: { // 0x557508: 7d14 JGE 0x0055751e
    if(integer::condition("JGE",flags)) goto L0055751e;
  }
  L0055750a: { // 0x55750a: 8d0c36 LEA ECX,[ESI + ESI*0x1]
    s.cx = (s.si+(s.si * 0x00000001u));
  }
  L0055750d: { // 0x55750d: 2bd7 SUB EDX,EDI
    s.dx = integer::sub(s.dx,s.di,32,flags);
  }
  L0055750f: { // 0x55750f: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00557511: { // 0x557511: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L00557513: { // 0x557513: 7d09 JGE 0x0055751e
    if(integer::condition("JGE",flags)) goto L0055751e;
  }
  L00557515: { // 0x557515: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00557516: { // 0x557516: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00557517: { // 0x557517: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00557518: { // 0x557518: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0055751a: { // 0x55751a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0055751b: { // 0x55751b: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0055751e: { // 0x55751e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0055751f: { // 0x55751f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00557520: { // 0x557520: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00557521: { // 0x557521: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00557523: { // 0x557523: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00557524: { // 0x557524: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_0007b190(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0047b190: { // 0x47b190: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  L0047b193: { // 0x47b193: 3dffff0000 CMP EAX,0xffff
    (void)integer::sub(s.ax,0x0000ffffu,32,flags);
  }
  L0047b198: { // 0x47b198: 7407 JZ 0x0047b1a1
    if(integer::condition("JZ",flags)) goto L0047b1a1;
  }
  L0047b19a: { // 0x47b19a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0047b19c: { // 0x47b19c: 7403 JZ 0x0047b1a1
    if(integer::condition("JZ",flags)) goto L0047b1a1;
  }
  L0047b19e: { // 0x47b19e: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0047b1a0: { // 0x47b1a0: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b1a1: { // 0x47b1a1: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047b1a3: { // 0x47b1a3: c3 RET
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
void f_0018a810(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0058a810: { // 0x58a810: 0fbf11 MOVSX EDX,word ptr [ECX]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.cx)),16));
  }
  L0058a813: { // 0x58a813: 0fbf4102 MOVSX EAX,word ptr [ECX + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000002u)),16));
  }
  L0058a817: { // 0x58a817: 8b0d3486a500 MOV ECX,dword ptr [0x00a58634]
    s.cx = m.r32((0x00a58634u));
  }
  L0058a81d: { // 0x58a81d: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0058a81e: { // 0x58a81e: 8d3410 LEA ESI,[EAX + EDX*0x1]
    s.si = (s.ax+(s.dx * 0x00000001u));
  }
  L0058a821: { // 0x58a821: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L0058a823: { // 0x58a823: 7e1c JLE 0x0058a841
    if(integer::condition("JLE",flags)) goto L0058a841;
  }
  L0058a825: { // 0x58a825: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0058a826: { // 0x58a826: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L0058a828: { // 0x58a828: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L0058a82a: { // 0x58a82a: 3bf9 CMP EDI,ECX
    (void)integer::sub(s.di,s.cx,32,flags);
  }
  L0058a82c: { // 0x58a82c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0058a82d: { // 0x58a82d: 7d12 JGE 0x0058a841
    if(integer::condition("JGE",flags)) goto L0058a841;
  }
  L0058a82f: { // 0x58a82f: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0058a831: { // 0x58a831: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0058a833: { // 0x58a833: 7d0c JGE 0x0058a841
    if(integer::condition("JGE",flags)) goto L0058a841;
  }
  L0058a835: { // 0x58a835: 3b353886a500 CMP ESI,dword ptr [0x00a58638]
    (void)integer::sub(s.si,m.r32((0x00a58638u)),32,flags);
  }
  L0058a83b: { // 0x58a83b: 7f04 JG 0x0058a841
    if(integer::condition("JG",flags)) goto L0058a841;
  }
  L0058a83d: { // 0x58a83d: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0058a83f: { // 0x58a83f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0058a840: { // 0x58a840: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0058a841: { // 0x58a841: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0058a843: { // 0x58a843: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0058a844: { // 0x58a844: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0016b760(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0056b760: { // 0x56b760: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0056b761: { // 0x56b761: 8b353c86a500 MOV ESI,dword ptr [0x00a5863c]
    s.si = m.r32((0x00a5863cu));
  }
  L0056b767: { // 0x56b767: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0056b769: { // 0x56b769: 741a JZ 0x0056b785
    if(integer::condition("JZ",flags)) goto L0056b785;
  }
  L0056b76b: { // 0x56b76b: 0fbf4102 MOVSX EAX,word ptr [ECX + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000002u)),16));
  }
  L0056b76f: { // 0x56b76f: 0faf054c6b8300 IMUL EAX,dword ptr [0x00836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  L0056b776: { // 0x56b776: 0fbf09 MOVSX ECX,word ptr [ECX]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.cx)),16));
  }
  L0056b779: { // 0x56b779: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0056b77b: { // 0x56b77b: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0056b77e: { // 0x56b77e: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L0056b781: { // 0x56b781: 89543038 MOV dword ptr [EAX + ESI*0x1 + 0x38],EDX
    m.w32((s.ax+(s.si * 0x00000001u)+0x00000038u), s.dx);
  }
  L0056b785: { // 0x56b785: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0056b786: { // 0x56b786: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00172ad0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00572ad0: { // 0x572ad0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00572ad1: { // 0x572ad1: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00572ad2: { // 0x572ad2: 8b355079a500 MOV ESI,dword ptr [0x00a57950]
    s.si = m.r32((0x00a57950u));
  }
  L00572ad8: { // 0x572ad8: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00572ada: { // 0x572ada: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00572adb: { // 0x572adb: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00572add: { // 0x572add: 7e17 JLE 0x00572af6
    if(integer::condition("JLE",flags)) goto L00572af6;
  }
  L00572adf: { // 0x572adf: 8b3d4479a500 MOV EDI,dword ptr [0x00a57944]
    s.di = m.r32((0x00a57944u));
  }
  L00572ae5: { // 0x572ae5: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  L00572ae7: { // 0x572ae7: 8b1a MOV EBX,dword ptr [EDX]
    s.bx = m.r32((s.dx));
  }
  L00572ae9: { // 0x572ae9: 394b08 CMP dword ptr [EBX + 0x8],ECX
    (void)integer::sub(m.r32((s.bx+0x00000008u)),s.cx,32,flags);
  }
  L00572aec: { // 0x572aec: 740e JZ 0x00572afc
    if(integer::condition("JZ",flags)) goto L00572afc;
  }
  L00572aee: { // 0x572aee: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00572aef: { // 0x572aef: 83c204 ADD EDX,0x4
    s.dx = integer::add(s.dx,0x00000004u,32,flags);
  }
  L00572af2: { // 0x572af2: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L00572af4: { // 0x572af4: 7cf1 JL 0x00572ae7
    if(integer::condition("JL",flags)) goto L00572ae7;
  }
  L00572af6: { // 0x572af6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00572af7: { // 0x572af7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00572af8: { // 0x572af8: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00572afa: { // 0x572afa: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00572afb: { // 0x572afb: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00572afc: { // 0x572afc: 8b0487 MOV EAX,dword ptr [EDI + EAX*0x4]
    s.ax = m.r32((s.di+(s.ax * 0x00000004u)));
  }
  L00572aff: { // 0x572aff: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00572b00: { // 0x572b00: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00572b01: { // 0x572b01: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00572b02: { // 0x572b02: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_001851f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005851f0: { // 0x5851f0: 83ec14 SUB ESP,0x14
    f.sp = integer::sub(f.sp,0x00000014u,32,flags);
  }
  L005851f3: { // 0x5851f3: a11489a200 MOV EAX,[0x00a28914]
    s.ax = m.r32((0x00a28914u));
  }
  L005851f8: { // 0x5851f8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005851f9: { // 0x5851f9: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005851fa: { // 0x5851fa: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L005851fe: { // 0x5851fe: 8b2c88 MOV EBP,dword ptr [EAX + ECX*0x4]
    s.bp = m.r32((s.ax+(s.cx * 0x00000004u)));
  }
  L00585201: { // 0x585201: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00585203: { // 0x585203: 8b5500 MOV EDX,dword ptr [EBP]
    s.dx = m.r32((s.bp));
  }
  L00585206: { // 0x585206: ff929c000000 CALL dword ptr [EDX + 0x9c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000009cu)),5788172u); flags=s.arithmetic_flags;
  }
  L0058520c: { // 0x58520c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0058520e: { // 0x58520e: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00585212: { // 0x585212: 0f8436010000 JZ 0x0058534e
    if(integer::condition("JZ",flags)) goto L0058534e;
  }
  L00585218: { // 0x585218: 8b85b8020000 MOV EAX,dword ptr [EBP + 0x2b8]
    s.ax = m.r32((s.bp+0x000002b8u));
  }
  L0058521e: { // 0x58521e: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00585220: { // 0x585220: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00585222: { // 0x585222: 895c240c MOV dword ptr [ESP + 0xc],EBX
    m.w32((f.sp+0x0000000cu), s.bx);
  }
  L00585226: { // 0x585226: 0f8e22010000 JLE 0x0058534e
    if(integer::condition("JLE",flags)) goto L0058534e;
  }
  L0058522c: { // 0x58522c: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0058522d: { // 0x58522d: 8b353486a500 MOV ESI,dword ptr [0x00a58634]
    s.si = m.r32((0x00a58634u));
  }
  L00585233: { // 0x585233: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00585234: { // 0x585234: 8b85b4020000 MOV EAX,dword ptr [EBP + 0x2b4]
    s.ax = m.r32((s.bp+0x000002b4u));
  }
  L0058523a: { // 0x58523a: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0058523c: { // 0x58523c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0058523e: { // 0x58523e: 0f8ef5000000 JLE 0x00585339
    if(integer::condition("JLE",flags)) goto L00585339;
  }
  L00585244: { // 0x585244: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L00585248: { // 0x585248: 668bcb MOV CX,BX
    s.cx = with_ax(s.cx, (s.bx & 0xffffu));
  }
  L0058524b: { // 0x58524b: 668b02 MOV AX,word ptr [EDX]
    s.ax = with_ax(s.ax, m.r16((s.dx)));
  }
  L0058524e: { // 0x58524e: 66034a02 ADD CX,word ptr [EDX + 0x2]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((s.dx+0x00000002u)),16,flags));
  }
  L00585252: { // 0x585252: 6603c7 ADD AX,DI
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),(s.di & 0xffffu),16,flags));
  }
  L00585255: { // 0x585255: 6689442418 MOV word ptr [ESP + 0x18],AX
    m.w16((f.sp+0x00000018u), (s.ax & 0xffffu));
  }
  L0058525a: { // 0x58525a: 66894c241a MOV word ptr [ESP + 0x1a],CX
    m.w16((f.sp+0x0000001au), (s.cx & 0xffffu));
  }
  L0058525f: { // 0x58525f: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L00585263: { // 0x585263: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L00585267: { // 0x585267: 0fbfd0 MOVSX EDX,AX
    s.dx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0058526a: { // 0x58526a: 0fbfc1 MOVSX EAX,CX
    s.ax = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L0058526d: { // 0x58526d: 8d0c10 LEA ECX,[EAX + EDX*0x1]
    s.cx = (s.ax+(s.dx * 0x00000001u));
  }
  L00585270: { // 0x585270: 3bce CMP ECX,ESI
    (void)integer::sub(s.cx,s.si,32,flags);
  }
  L00585272: { // 0x585272: 0f8eb2000000 JLE 0x0058532a
    if(integer::condition("JLE",flags)) goto L0058532a;
  }
  L00585278: { // 0x585278: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  L0058527a: { // 0x58527a: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L0058527c: { // 0x58527c: 3bde CMP EBX,ESI
    (void)integer::sub(s.bx,s.si,32,flags);
  }
  L0058527e: { // 0x58527e: 0f8da2000000 JGE 0x00585326
    if(integer::condition("JGE",flags)) goto L00585326;
  }
  L00585284: { // 0x585284: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00585286: { // 0x585286: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L00585288: { // 0x585288: 0f8d98000000 JGE 0x00585326
    if(integer::condition("JGE",flags)) goto L00585326;
  }
  L0058528e: { // 0x58528e: 3b0d3886a500 CMP ECX,dword ptr [0x00a58638]
    (void)integer::sub(s.cx,m.r32((0x00a58638u)),32,flags);
  }
  L00585294: { // 0x585294: 0f8f8c000000 JG 0x00585326
    if(integer::condition("JG",flags)) goto L00585326;
  }
  L0058529a: { // 0x58529a: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L0058529e: { // 0x58529e: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L005852a3: { // 0x5852a3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005852a4: { // 0x5852a4: e85702fcff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5788329u); flags=s.arithmetic_flags;
  }
  L005852a9: { // 0x5852a9: 8b8db4020000 MOV ECX,dword ptr [EBP + 0x2b4]
    s.cx = m.r32((s.bp+0x000002b4u));
  }
  L005852af: { // 0x5852af: 8b5c2414 MOV EBX,dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  L005852b3: { // 0x5852b3: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L005852b7: { // 0x5852b7: 0fafcb IMUL ECX,EBX
    s.cx = integer::imul(s.cx,s.bx,32,flags);
  }
  L005852ba: { // 0x5852ba: 03cf ADD ECX,EDI
    s.cx = integer::add(s.cx,s.di,32,flags);
  }
  L005852bc: { // 0x5852bc: 8b748a10 MOV ESI,dword ptr [EDX + ECX*0x4 + 0x10]
    s.si = m.r32((s.dx+(s.cx * 0x00000004u)+0x00000010u));
  }
  L005852c0: { // 0x5852c0: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L005852c2: { // 0x5852c2: 745a JZ 0x0058531e
    if(integer::condition("JZ",flags)) goto L0058531e;
  }
  L005852c4: { // 0x5852c4: 8b9564020000 MOV EDX,dword ptr [EBP + 0x264]
    s.dx = m.r32((s.bp+0x00000264u));
  }
  L005852ca: { // 0x5852ca: 88881a010000 MOV byte ptr [EAX + 0x11a],CL
    m.w8((s.ax+0x0000011au), (s.cx & 0xffu));
  }
  L005852d0: { // 0x5852d0: 8b4c242c MOV ECX,dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L005852d4: { // 0x5852d4: 895038 MOV dword ptr [EAX + 0x38],EDX
    m.w32((s.ax+0x00000038u), s.dx);
  }
  L005852d7: { // 0x5852d7: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  L005852da: { // 0x5852da: 740e JZ 0x005852ea
    if(integer::condition("JZ",flags)) goto L005852ea;
  }
  L005852dc: { // 0x5852dc: 8a5628 MOV DL,byte ptr [ESI + 0x28]
    s.dx = with_al(s.dx, m.r8((s.si+0x00000028u)));
  }
  L005852df: { // 0x5852df: 02d1 ADD DL,CL
    s.dx = with_al(s.dx, integer::add((s.dx & 0xffu),(s.cx & 0xffu),8,flags));
  }
  L005852e1: { // 0x5852e1: 80ea04 SUB DL,0x4
    s.dx = with_al(s.dx, integer::sub((s.dx & 0xffu),0x00000004u,8,flags));
  }
  L005852e4: { // 0x5852e4: 88901b010000 MOV byte ptr [EAX + 0x11b],DL
    m.w8((s.ax+0x0000011bu), (s.dx & 0xffu));
  }
  L005852ea: { // 0x5852ea: 8a4e2a MOV CL,byte ptr [ESI + 0x2a]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000002au)));
  }
  L005852ed: { // 0x5852ed: 88881c010000 MOV byte ptr [EAX + 0x11c],CL
    m.w8((s.ax+0x0000011cu), (s.cx & 0xffu));
  }
  L005852f3: { // 0x5852f3: 8b0d3c86a500 MOV ECX,dword ptr [0x00a5863c]
    s.cx = m.r32((0x00a5863cu));
  }
  L005852f9: { // 0x5852f9: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005852fb: { // 0x5852fb: 7421 JZ 0x0058531e
    if(integer::condition("JZ",flags)) goto L0058531e;
  }
  L005852fd: { // 0x5852fd: 0fbf442412 MOVSX EAX,word ptr [ESP + 0x12]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000012u)),16));
  }
  L00585302: { // 0x585302: 0faf054c6b8300 IMUL EAX,dword ptr [0x00836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  L00585309: { // 0x585309: 0fbf542410 MOVSX EDX,word ptr [ESP + 0x10]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000010u)),16));
  }
  L0058530e: { // 0x58530e: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00585310: { // 0x585310: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L00585314: { // 0x585314: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L00585317: { // 0x585317: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L0058531a: { // 0x58531a: 89540838 MOV dword ptr [EAX + ECX*0x1 + 0x38],EDX
    m.w32((s.ax+(s.cx * 0x00000001u)+0x00000038u), s.dx);
  }
  L0058531e: { // 0x58531e: 8b353486a500 MOV ESI,dword ptr [0x00a58634]
    s.si = m.r32((0x00a58634u));
  }
  L00585324: { // 0x585324: eb04 JMP 0x0058532a
    goto L0058532a;
  }
  L00585326: { // 0x585326: 8b5c2414 MOV EBX,dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  L0058532a: { // 0x58532a: 8b85b4020000 MOV EAX,dword ptr [EBP + 0x2b4]
    s.ax = m.r32((s.bp+0x000002b4u));
  }
  L00585330: { // 0x585330: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L00585331: { // 0x585331: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L00585333: { // 0x585333: 0f8c0bffffff JL 0x00585244
    if(integer::condition("JL",flags)) goto L00585244;
  }
  L00585339: { // 0x585339: 8b85b8020000 MOV EAX,dword ptr [EBP + 0x2b8]
    s.ax = m.r32((s.bp+0x000002b8u));
  }
  L0058533f: { // 0x58533f: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L00585340: { // 0x585340: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L00585342: { // 0x585342: 895c2414 MOV dword ptr [ESP + 0x14],EBX
    m.w32((f.sp+0x00000014u), s.bx);
  }
  L00585346: { // 0x585346: 0f8ce8feffff JL 0x00585234
    if(integer::condition("JL",flags)) goto L00585234;
  }
  L0058534c: { // 0x58534c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0058534d: { // 0x58534d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0058534e: { // 0x58534e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0058534f: { // 0x58534f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00585350: { // 0x585350: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L00585353: { // 0x585353: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_0001c300(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0041c300: { // 0x41c300: 8b81a4000000 MOV EAX,dword ptr [ECX + 0xa4]
    s.ax = m.r32((s.cx+0x000000a4u));
  }
  L0041c306: { // 0x41c306: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0022fde0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0062fde0: { // 0x62fde0: 803900 CMP byte ptr [ECX],0x0
    (void)integer::sub(m.r8((s.cx)),0x00000000u,8,flags);
  }
  L0062fde3: { // 0x62fde3: 7403 JZ 0x0062fde8
    if(integer::condition("JZ",flags)) goto L0062fde8;
  }
  L0062fde5: { // 0x62fde5: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0062fde7: { // 0x62fde7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0062fde8: { // 0x62fde8: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L0062fdeb: { // 0x62fdeb: 8b5108 MOV EDX,dword ptr [ECX + 0x8]
    s.dx = m.r32((s.cx+0x00000008u));
  }
  L0062fdee: { // 0x62fdee: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0062fdef: { // 0x62fdef: 8b54910c MOV EDX,dword ptr [ECX + EDX*0x4 + 0xc]
    s.dx = m.r32((s.cx+(s.dx * 0x00000004u)+0x0000000cu));
  }
  L0062fdf3: { // 0x62fdf3: 8b74810c MOV ESI,dword ptr [ECX + EAX*0x4 + 0xc]
    s.si = m.r32((s.cx+(s.ax * 0x00000004u)+0x0000000cu));
  }
  L0062fdf7: { // 0x62fdf7: 8d44810c LEA EAX,[ECX + EAX*0x4 + 0xc]
    s.ax = (s.cx+(s.ax * 0x00000004u)+0x0000000cu);
  }
  L0062fdfb: { // 0x62fdfb: 33f2 XOR ESI,EDX
    s.si = integer::logical((s.si)^(s.dx),32,flags);
  }
  L0062fdfd: { // 0x62fdfd: 8930 MOV dword ptr [EAX],ESI
    m.w32((s.ax), s.si);
  }
  L0062fdff: { // 0x62fdff: 8b5104 MOV EDX,dword ptr [ECX + 0x4]
    s.dx = m.r32((s.cx+0x00000004u));
  }
  L0062fe02: { // 0x62fe02: 8b7108 MOV ESI,dword ptr [ECX + 0x8]
    s.si = m.r32((s.cx+0x00000008u));
  }
  L0062fe05: { // 0x62fe05: 8b44910c MOV EAX,dword ptr [ECX + EDX*0x4 + 0xc]
    s.ax = m.r32((s.cx+(s.dx * 0x00000004u)+0x0000000cu));
  }
  L0062fe09: { // 0x62fe09: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L0062fe0a: { // 0x62fe0a: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0062fe0b: { // 0x62fe0b: 81fafa000000 CMP EDX,0xfa
    (void)integer::sub(s.dx,0x000000fau,32,flags);
  }
  L0062fe11: { // 0x62fe11: 895104 MOV dword ptr [ECX + 0x4],EDX
    m.w32((s.cx+0x00000004u), s.dx);
  }
  L0062fe14: { // 0x62fe14: 897108 MOV dword ptr [ECX + 0x8],ESI
    m.w32((s.cx+0x00000008u), s.si);
  }
  L0062fe17: { // 0x62fe17: 7c07 JL 0x0062fe20
    if(integer::condition("JL",flags)) goto L0062fe20;
  }
  L0062fe19: { // 0x62fe19: c7410400000000 MOV dword ptr [ECX + 0x4],0x0
    m.w32((s.cx+0x00000004u), 0x00000000u);
  }
  L0062fe20: { // 0x62fe20: 81fefa000000 CMP ESI,0xfa
    (void)integer::sub(s.si,0x000000fau,32,flags);
  }
  L0062fe26: { // 0x62fe26: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0062fe27: { // 0x62fe27: 7c07 JL 0x0062fe30
    if(integer::condition("JL",flags)) goto L0062fe30;
  }
  L0062fe29: { // 0x62fe29: c7410800000000 MOV dword ptr [ECX + 0x8],0x0
    m.w32((s.cx+0x00000008u), 0x00000000u);
  }
  L0062fe30: { // 0x62fe30: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
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
case 5711616u:f_00172700(m,s,child,{});break;
case 5600336u:f_00157450(m,s,child,{});break;
case 4698512u:f_0007b190(m,s,child,{});break;
case 5526784u:f_00145500(m,s,child,{});break;
case 5810192u:f_0018a810(m,s,child,{});break;
case 5683040u:f_0016b760(m,s,child,{});break;
case 5712592u:f_00172ad0(m,s,child,{});break;
case 5788144u:f_001851f0(m,s,child,{});break;
case 4309760u:f_0001c300(m,s,child,{});break;
case 6487520u:f_0022fde0(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
default:throw std::domain_error("recovery531 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0056f7e0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0056f7e0: { // 0x56f7e0: 83ec5c SUB ESP,0x5c
    f.sp = integer::sub(f.sp,0x0000005cu,32,flags);
  }
  L0056f7e3: { // 0x56f7e3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0056f7e4: { // 0x56f7e4: 8b5c2468 MOV EBX,dword ptr [ESP + 0x68]
    s.bx = m.r32((f.sp+0x00000068u));
  }
  L0056f7e8: { // 0x56f7e8: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0056f7e9: { // 0x56f7e9: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0056f7ea: { // 0x56f7ea: 668b5302 MOV DX,word ptr [EBX + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.bx+0x00000002u)));
  }
  L0056f7ee: { // 0x56f7ee: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0056f7ef: { // 0x56f7ef: 8b7c2470 MOV EDI,dword ptr [ESP + 0x70]
    s.di = m.r32((f.sp+0x00000070u));
  }
  L0056f7f3: { // 0x56f7f3: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L0056f7f7: { // 0x56f7f7: 668b4702 MOV AX,word ptr [EDI + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.di+0x00000002u)));
  }
  L0056f7fb: { // 0x56f7fb: 663bc2 CMP AX,DX
    (void)integer::sub((s.ax & 0xffffu),(s.dx & 0xffffu),16,flags);
  }
  L0056f7fe: { // 0x56f7fe: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L0056f800: { // 0x56f800: 7f02 JG 0x0056f804
    if(integer::condition("JG",flags)) goto L0056f804;
  }
  L0056f802: { // 0x56f802: 8bea MOV EBP,EDX
    s.bp = s.dx;
  }
  L0056f804: { // 0x56f804: 663bc2 CMP AX,DX
    (void)integer::sub((s.ax & 0xffffu),(s.dx & 0xffffu),16,flags);
  }
  L0056f807: { // 0x56f807: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0056f809: { // 0x56f809: 7c02 JL 0x0056f80d
    if(integer::condition("JL",flags)) goto L0056f80d;
  }
  L0056f80b: { // 0x56f80b: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L0056f80d: { // 0x56f80d: 663bc2 CMP AX,DX
    (void)integer::sub((s.ax & 0xffffu),(s.dx & 0xffffu),16,flags);
  }
  L0056f810: { // 0x56f810: 7d02 JGE 0x0056f814
    if(integer::condition("JGE",flags)) goto L0056f814;
  }
  L0056f812: { // 0x56f812: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0056f814: { // 0x56f814: 0fbf07 MOVSX EAX,word ptr [EDI]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di)),16));
  }
  L0056f817: { // 0x56f817: 0fbfd2 MOVSX EDX,DX
    s.dx = std::uint32_t(integer::sign_extend((s.dx & 0xffffu),16));
  }
  L0056f81a: { // 0x56f81a: 8d48fb LEA ECX,[EAX + -0x5]
    s.cx = (s.ax-0x00000005u);
  }
  L0056f81d: { // 0x56f81d: 83ea03 SUB EDX,0x3
    s.dx = integer::sub(s.dx,0x00000003u,32,flags);
  }
  L0056f820: { // 0x56f820: 894c245c MOV dword ptr [ESP + 0x5c],ECX
    m.w32((f.sp+0x0000005cu), s.cx);
  }
  L0056f824: { // 0x56f824: 89542460 MOV dword ptr [ESP + 0x60],EDX
    m.w32((f.sp+0x00000060u), s.dx);
  }
  L0056f828: { // 0x56f828: 0fbf0b MOVSX ECX,word ptr [EBX]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.bx)),16));
  }
  L0056f82b: { // 0x56f82b: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L0056f82d: { // 0x56f82d: 0fbfd6 MOVSX EDX,SI
    s.dx = std::uint32_t(integer::sign_extend((s.si & 0xffffu),16));
  }
  L0056f830: { // 0x56f830: 0fbfc5 MOVSX EAX,BP
    s.ax = std::uint32_t(integer::sign_extend((s.bp & 0xffffu),16));
  }
  L0056f833: { // 0x56f833: 83c109 ADD ECX,0x9
    s.cx = integer::add(s.cx,0x00000009u,32,flags);
  }
  L0056f836: { // 0x56f836: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0056f838: { // 0x56f838: 894c2464 MOV dword ptr [ESP + 0x64],ECX
    m.w32((f.sp+0x00000064u), s.cx);
  }
  L0056f83c: { // 0x56f83c: 8b4c2478 MOV ECX,dword ptr [ESP + 0x78]
    s.cx = m.r32((f.sp+0x00000078u));
  }
  L0056f840: { // 0x56f840: 8d54245c LEA EDX,[ESP + 0x5c]
    s.dx = (f.sp+0x0000005cu);
  }
  L0056f844: { // 0x56f844: 83c00b ADD EAX,0xb
    s.ax = integer::add(s.ax,0x0000000bu,32,flags);
  }
  L0056f847: { // 0x56f847: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0056f848: { // 0x56f848: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0056f84c: { // 0x56f84c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0056f84d: { // 0x56f84d: 89442470 MOV dword ptr [ESP + 0x70],EAX
    m.w32((f.sp+0x00000070u), s.ax);
  }
  L0056f851: { // 0x56f851: e8aa2e0000 CALL 0x00572700
    s.arithmetic_flags=flags; invoke(m,s,f,0x00572700u,5699670u); flags=s.arithmetic_flags;
  }
  L0056f856: { // 0x56f856: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0056f858: { // 0x56f858: 750a JNZ 0x0056f864
    if(integer::condition("JNZ",flags)) goto L0056f864;
  }
  L0056f85a: { // 0x56f85a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0056f85b: { // 0x56f85b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0056f85c: { // 0x56f85c: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0056f85d: { // 0x56f85d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0056f85e: { // 0x56f85e: 83c45c ADD ESP,0x5c
    f.sp = integer::add(f.sp,0x0000005cu,32,flags);
  }
  L0056f861: { // 0x56f861: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0056f864: { // 0x56f864: 0fbf7702 MOVSX ESI,word ptr [EDI + 0x2]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L0056f868: { // 0x56f868: 0fbf4302 MOVSX EAX,word ptr [EBX + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.bx+0x00000002u)),16));
  }
  L0056f86c: { // 0x56f86c: 2bc6 SUB EAX,ESI
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L0056f86e: { // 0x56f86e: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L0056f872: { // 0x56f872: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0056f873: { // 0x56f873: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0056f875: { // 0x56f875: 0fbf03 MOVSX EAX,word ptr [EBX]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.bx)),16));
  }
  L0056f878: { // 0x56f878: 33ca XOR ECX,EDX
    s.cx = integer::logical((s.cx)^(s.dx),32,flags);
  }
  L0056f87a: { // 0x56f87a: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L0056f87c: { // 0x56f87c: 0fbf17 MOVSX EDX,word ptr [EDI]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.di)),16));
  }
  L0056f87f: { // 0x56f87f: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0056f881: { // 0x56f881: 894c2470 MOV dword ptr [ESP + 0x70],ECX
    m.w32((f.sp+0x00000070u), s.cx);
  }
  L0056f885: { // 0x56f885: 8d50fb LEA EDX,[EAX + -0x5]
    s.dx = (s.ax-0x00000005u);
  }
  L0056f888: { // 0x56f888: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L0056f88a: { // 0x56f88a: 7e0c JLE 0x0056f898
    if(integer::condition("JLE",flags)) goto L0056f898;
  }
  L0056f88c: { // 0x56f88c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0056f88d: { // 0x56f88d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0056f88e: { // 0x56f88e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0056f88f: { // 0x56f88f: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0056f891: { // 0x56f891: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0056f892: { // 0x56f892: 83c45c ADD ESP,0x5c
    f.sp = integer::add(f.sp,0x0000005cu,32,flags);
  }
  L0056f895: { // 0x56f895: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0056f898: { // 0x56f898: 8b4c2468 MOV ECX,dword ptr [ESP + 0x68]
    s.cx = m.r32((f.sp+0x00000068u));
  }
  L0056f89c: { // 0x56f89c: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0056f89d: { // 0x56f89d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0056f89e: { // 0x56f89e: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0056f8a0: { // 0x56f8a0: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L0056f8a2: { // 0x56f8a2: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L0056f8a4: { // 0x56f8a4: 8b44245c MOV EAX,dword ptr [ESP + 0x5c]
    s.ax = m.r32((f.sp+0x0000005cu));
  }
  L0056f8a8: { // 0x56f8a8: 8944244c MOV dword ptr [ESP + 0x4c],EAX
    m.w32((f.sp+0x0000004cu), s.ax);
  }
  L0056f8ac: { // 0x56f8ac: 8d4601 LEA EAX,[ESI + 0x1]
    s.ax = (s.si+0x00000001u);
  }
  L0056f8af: { // 0x56f8af: 2bd6 SUB EDX,ESI
    s.dx = integer::sub(s.dx,s.si,32,flags);
  }
  L0056f8b1: { // 0x56f8b1: 8b742460 MOV ESI,dword ptr [ESP + 0x60]
    s.si = m.r32((f.sp+0x00000060u));
  }
  L0056f8b5: { // 0x56f8b5: d1fd SAR EBP,0x1
    s.bp = integer::shift(s.bp,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0056f8b7: { // 0x56f8b7: 8d543201 LEA EDX,[EDX + ESI*0x1 + 0x1]
    s.dx = (s.dx+(s.si * 0x00000001u)+0x00000001u);
  }
  L0056f8bb: { // 0x56f8bb: 83c503 ADD EBP,0x3
    s.bp = integer::add(s.bp,0x00000003u,32,flags);
  }
  L0056f8be: { // 0x56f8be: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L0056f8c0: { // 0x56f8c0: 896c2428 MOV dword ptr [ESP + 0x28],EBP
    m.w32((f.sp+0x00000028u), s.bp);
  }
  L0056f8c4: { // 0x56f8c4: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0056f8c6: { // 0x56f8c6: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0056f8ca: { // 0x56f8ca: 89542420 MOV dword ptr [ESP + 0x20],EDX
    m.w32((f.sp+0x00000020u), s.dx);
  }
  L0056f8ce: { // 0x56f8ce: 0f8d88000000 JGE 0x0056f95c
    if(integer::condition("JGE",flags)) goto L0056f95c;
  }
  L0056f8d4: { // 0x56f8d4: 8b44245c MOV EAX,dword ptr [ESP + 0x5c]
    s.ax = m.r32((f.sp+0x0000005cu));
  }
  L0056f8d8: { // 0x56f8d8: 8d542802 LEA EDX,[EAX + EBP*0x1 + 0x2]
    s.dx = (s.ax+(s.bp * 0x00000001u)+0x00000002u);
  }
  L0056f8dc: { // 0x56f8dc: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L0056f8e0: { // 0x56f8e0: 8b74244c MOV ESI,dword ptr [ESP + 0x4c]
    s.si = m.r32((f.sp+0x0000004cu));
  }
  L0056f8e4: { // 0x56f8e4: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L0056f8e8: { // 0x56f8e8: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L0056f8ea: { // 0x56f8ea: 7d5f JGE 0x0056f94b
    if(integer::condition("JGE",flags)) goto L0056f94b;
  }
  L0056f8ec: { // 0x56f8ec: 668b442418 MOV AX,word ptr [ESP + 0x18]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x00000018u)));
  }
  L0056f8f1: { // 0x56f8f1: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L0056f8f5: { // 0x56f8f5: 6689742414 MOV word ptr [ESP + 0x14],SI
    m.w16((f.sp+0x00000014u), (s.si & 0xffffu));
  }
  L0056f8fa: { // 0x56f8fa: 6689442416 MOV word ptr [ESP + 0x16],AX
    m.w16((f.sp+0x00000016u), (s.ax & 0xffffu));
  }
  L0056f8ff: { // 0x56f8ff: e80caf0100 CALL 0x0058a810
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058a810u,5699844u); flags=s.arithmetic_flags;
  }
  L0056f904: { // 0x56f904: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0056f906: { // 0x56f906: 7436 JZ 0x0056f93e
    if(integer::condition("JZ",flags)) goto L0056f93e;
  }
  L0056f908: { // 0x56f908: 8b542478 MOV EDX,dword ptr [ESP + 0x78]
    s.dx = m.r32((f.sp+0x00000078u));
  }
  L0056f90c: { // 0x56f90c: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L0056f910: { // 0x56f910: e84bbeffff CALL 0x0056b760
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056b760u,5699861u); flags=s.arithmetic_flags;
  }
  L0056f915: { // 0x56f915: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L0056f919: { // 0x56f919: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0056f91a: { // 0x56f91a: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0056f91f: { // 0x56f91f: e8dc5bfdff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5699876u); flags=s.arithmetic_flags;
  }
  L0056f924: { // 0x56f924: 8b4c2478 MOV ECX,dword ptr [ESP + 0x78]
    s.cx = m.r32((f.sp+0x00000078u));
  }
  L0056f928: { // 0x56f928: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L0056f92c: { // 0x56f92c: e89f310000 CALL 0x00572ad0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00572ad0u,5699889u); flags=s.arithmetic_flags;
  }
  L0056f931: { // 0x56f931: 8a5010 MOV DL,byte ptr [EAX + 0x10]
    s.dx = with_al(s.dx, m.r8((s.ax+0x00000010u)));
  }
  L0056f934: { // 0x56f934: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L0056f938: { // 0x56f938: 88901b010000 MOV byte ptr [EAX + 0x11b],DL
    m.w8((s.ax+0x0000011bu), (s.dx & 0xffu));
  }
  L0056f93e: { // 0x56f93e: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L0056f942: { // 0x56f942: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0056f943: { // 0x56f943: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L0056f945: { // 0x56f945: 7ca5 JL 0x0056f8ec
    if(integer::condition("JL",flags)) goto L0056f8ec;
  }
  L0056f947: { // 0x56f947: 8b4c2468 MOV ECX,dword ptr [ESP + 0x68]
    s.cx = m.r32((f.sp+0x00000068u));
  }
  L0056f94b: { // 0x56f94b: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0056f94f: { // 0x56f94f: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L0056f953: { // 0x56f953: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0056f954: { // 0x56f954: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0056f956: { // 0x56f956: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0056f95a: { // 0x56f95a: 7c84 JL 0x0056f8e0
    if(integer::condition("JL",flags)) goto L0056f8e0;
  }
  L0056f95c: { // 0x56f95c: 0fbf5302 MOVSX EDX,word ptr [EBX + 0x2]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.bx+0x00000002u)),16));
  }
  L0056f960: { // 0x56f960: 0fbf33 MOVSX ESI,word ptr [EBX]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.bx)),16));
  }
  L0056f963: { // 0x56f963: 8d4201 LEA EAX,[EDX + 0x1]
    s.ax = (s.dx+0x00000001u);
  }
  L0056f966: { // 0x56f966: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L0056f968: { // 0x56f968: 8b542460 MOV EDX,dword ptr [ESP + 0x60]
    s.dx = m.r32((f.sp+0x00000060u));
  }
  L0056f96c: { // 0x56f96c: 2bf5 SUB ESI,EBP
    s.si = integer::sub(s.si,s.bp,32,flags);
  }
  L0056f96e: { // 0x56f96e: 83c603 ADD ESI,0x3
    s.si = integer::add(s.si,0x00000003u,32,flags);
  }
  L0056f971: { // 0x56f971: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0056f975: { // 0x56f975: 8d4c1101 LEA ECX,[ECX + EDX*0x1 + 0x1]
    s.cx = (s.cx+(s.dx * 0x00000001u)+0x00000001u);
  }
  L0056f979: { // 0x56f979: 894c2458 MOV dword ptr [ESP + 0x58],ECX
    m.w32((f.sp+0x00000058u), s.cx);
  }
  L0056f97d: { // 0x56f97d: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0056f97f: { // 0x56f97f: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0056f981: { // 0x56f981: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L0056f985: { // 0x56f985: 7d7c JGE 0x0056fa03
    if(integer::condition("JGE",flags)) goto L0056fa03;
  }
  L0056f987: { // 0x56f987: 8d442e02 LEA EAX,[ESI + EBP*0x1 + 0x2]
    s.ax = (s.si+(s.bp * 0x00000001u)+0x00000002u);
  }
  L0056f98b: { // 0x56f98b: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L0056f98d: { // 0x56f98d: 8bde MOV EBX,ESI
    s.bx = s.si;
  }
  L0056f98f: { // 0x56f98f: 7d5d JGE 0x0056f9ee
    if(integer::condition("JGE",flags)) goto L0056f9ee;
  }
  L0056f991: { // 0x56f991: 668b542418 MOV DX,word ptr [ESP + 0x18]
    s.dx = with_ax(s.dx, m.r16((f.sp+0x00000018u)));
  }
  L0056f996: { // 0x56f996: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L0056f99a: { // 0x56f99a: 66895c2414 MOV word ptr [ESP + 0x14],BX
    m.w16((f.sp+0x00000014u), (s.bx & 0xffffu));
  }
  L0056f99f: { // 0x56f99f: 6689542416 MOV word ptr [ESP + 0x16],DX
    m.w16((f.sp+0x00000016u), (s.dx & 0xffffu));
  }
  L0056f9a4: { // 0x56f9a4: e867ae0100 CALL 0x0058a810
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058a810u,5700009u); flags=s.arithmetic_flags;
  }
  L0056f9a9: { // 0x56f9a9: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0056f9ab: { // 0x56f9ab: 7434 JZ 0x0056f9e1
    if(integer::condition("JZ",flags)) goto L0056f9e1;
  }
  L0056f9ad: { // 0x56f9ad: 8b542478 MOV EDX,dword ptr [ESP + 0x78]
    s.dx = m.r32((f.sp+0x00000078u));
  }
  L0056f9b1: { // 0x56f9b1: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L0056f9b5: { // 0x56f9b5: e8a6bdffff CALL 0x0056b760
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056b760u,5700026u); flags=s.arithmetic_flags;
  }
  L0056f9ba: { // 0x56f9ba: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L0056f9be: { // 0x56f9be: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0056f9c3: { // 0x56f9c3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0056f9c4: { // 0x56f9c4: e8375bfdff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5700041u); flags=s.arithmetic_flags;
  }
  L0056f9c9: { // 0x56f9c9: 8b4c2478 MOV ECX,dword ptr [ESP + 0x78]
    s.cx = m.r32((f.sp+0x00000078u));
  }
  L0056f9cd: { // 0x56f9cd: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L0056f9cf: { // 0x56f9cf: e8fc300000 CALL 0x00572ad0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00572ad0u,5700052u); flags=s.arithmetic_flags;
  }
  L0056f9d4: { // 0x56f9d4: 8a4810 MOV CL,byte ptr [EAX + 0x10]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000010u)));
  }
  L0056f9d7: { // 0x56f9d7: 888d1b010000 MOV byte ptr [EBP + 0x11b],CL
    m.w8((s.bp+0x0000011bu), (s.cx & 0xffu));
  }
  L0056f9dd: { // 0x56f9dd: 8b6c2428 MOV EBP,dword ptr [ESP + 0x28]
    s.bp = m.r32((f.sp+0x00000028u));
  }
  L0056f9e1: { // 0x56f9e1: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L0056f9e2: { // 0x56f9e2: 8d442e02 LEA EAX,[ESI + EBP*0x1 + 0x2]
    s.ax = (s.si+(s.bp * 0x00000001u)+0x00000002u);
  }
  L0056f9e6: { // 0x56f9e6: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L0056f9e8: { // 0x56f9e8: 7ca7 JL 0x0056f991
    if(integer::condition("JL",flags)) goto L0056f991;
  }
  L0056f9ea: { // 0x56f9ea: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L0056f9ee: { // 0x56f9ee: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0056f9f2: { // 0x56f9f2: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L0056f9f3: { // 0x56f9f3: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L0056f9f5: { // 0x56f9f5: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L0056f9f9: { // 0x56f9f9: 7c90 JL 0x0056f98b
    if(integer::condition("JL",flags)) goto L0056f98b;
  }
  L0056f9fb: { // 0x56f9fb: 8b5c2474 MOV EBX,dword ptr [ESP + 0x74]
    s.bx = m.r32((f.sp+0x00000074u));
  }
  L0056f9ff: { // 0x56f9ff: 8b542460 MOV EDX,dword ptr [ESP + 0x60]
    s.dx = m.r32((f.sp+0x00000060u));
  }
  L0056fa03: { // 0x56fa03: 8b44245c MOV EAX,dword ptr [ESP + 0x5c]
    s.ax = m.r32((f.sp+0x0000005cu));
  }
  L0056fa07: { // 0x56fa07: 8d4a02 LEA ECX,[EDX + 0x2]
    s.cx = (s.dx+0x00000002u);
  }
  L0056fa0a: { // 0x56fa0a: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0056fa0e: { // 0x56fa0e: 8d7004 LEA ESI,[EAX + 0x4]
    s.si = (s.ax+0x00000004u);
  }
  L0056fa11: { // 0x56fa11: 0fbf4702 MOVSX EAX,word ptr [EDI + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L0056fa15: { // 0x56fa15: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0056fa17: { // 0x56fa17: 8974244c MOV dword ptr [ESP + 0x4c],ESI
    m.w32((f.sp+0x0000004cu), s.si);
  }
  L0056fa1b: { // 0x56fa1b: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0056fa1c: { // 0x56fa1c: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0056fa1e: { // 0x56fa1e: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L0056fa20: { // 0x56fa20: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L0056fa24: { // 0x56fa24: 7d72 JGE 0x0056fa98
    if(integer::condition("JGE",flags)) goto L0056fa98;
  }
  L0056fa26: { // 0x56fa26: 8d4c2efe LEA ECX,[ESI + EBP*0x1 + -0x2]
    s.cx = (s.si+(s.bp * 0x00000001u)-0x00000002u);
  }
  L0056fa2a: { // 0x56fa2a: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L0056fa2c: { // 0x56fa2c: 7d5d JGE 0x0056fa8b
    if(integer::condition("JGE",flags)) goto L0056fa8b;
  }
  L0056fa2e: { // 0x56fa2e: 668b4c2418 MOV CX,word ptr [ESP + 0x18]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000018u)));
  }
  L0056fa33: { // 0x56fa33: 6689742414 MOV word ptr [ESP + 0x14],SI
    m.w16((f.sp+0x00000014u), (s.si & 0xffffu));
  }
  L0056fa38: { // 0x56fa38: 66894c2416 MOV word ptr [ESP + 0x16],CX
    m.w16((f.sp+0x00000016u), (s.cx & 0xffffu));
  }
  L0056fa3d: { // 0x56fa3d: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L0056fa41: { // 0x56fa41: e8caad0100 CALL 0x0058a810
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058a810u,5700166u); flags=s.arithmetic_flags;
  }
  L0056fa46: { // 0x56fa46: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0056fa48: { // 0x56fa48: 742c JZ 0x0056fa76
    if(integer::condition("JZ",flags)) goto L0056fa76;
  }
  L0056fa4a: { // 0x56fa4a: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0056fa4e: { // 0x56fa4e: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L0056fa52: { // 0x56fa52: 8b5208 MOV EDX,dword ptr [EDX + 0x8]
    s.dx = m.r32((s.dx+0x00000008u));
  }
  L0056fa55: { // 0x56fa55: e806bdffff CALL 0x0056b760
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056b760u,5700186u); flags=s.arithmetic_flags;
  }
  L0056fa5a: { // 0x56fa5a: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L0056fa5e: { // 0x56fa5e: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0056fa63: { // 0x56fa63: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0056fa64: { // 0x56fa64: e8975afdff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5700201u); flags=s.arithmetic_flags;
  }
  L0056fa69: { // 0x56fa69: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L0056fa6d: { // 0x56fa6d: 8a5110 MOV DL,byte ptr [ECX + 0x10]
    s.dx = with_al(s.dx, m.r8((s.cx+0x00000010u)));
  }
  L0056fa70: { // 0x56fa70: 88901b010000 MOV byte ptr [EAX + 0x11b],DL
    m.w8((s.ax+0x0000011bu), (s.dx & 0xffu));
  }
  L0056fa76: { // 0x56fa76: 8b44244c MOV EAX,dword ptr [ESP + 0x4c]
    s.ax = m.r32((f.sp+0x0000004cu));
  }
  L0056fa7a: { // 0x56fa7a: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0056fa7b: { // 0x56fa7b: 8d4428fe LEA EAX,[EAX + EBP*0x1 + -0x2]
    s.ax = (s.ax+(s.bp * 0x00000001u)-0x00000002u);
  }
  L0056fa7f: { // 0x56fa7f: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L0056fa81: { // 0x56fa81: 7cab JL 0x0056fa2e
    if(integer::condition("JL",flags)) goto L0056fa2e;
  }
  L0056fa83: { // 0x56fa83: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L0056fa87: { // 0x56fa87: 8b74244c MOV ESI,dword ptr [ESP + 0x4c]
    s.si = m.r32((f.sp+0x0000004cu));
  }
  L0056fa8b: { // 0x56fa8b: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0056fa8f: { // 0x56fa8f: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0056fa90: { // 0x56fa90: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L0056fa92: { // 0x56fa92: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0056fa96: { // 0x56fa96: 7c8e JL 0x0056fa26
    if(integer::condition("JL",flags)) goto L0056fa26;
  }
  L0056fa98: { // 0x56fa98: 0fbf33 MOVSX ESI,word ptr [EBX]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.bx)),16));
  }
  L0056fa9b: { // 0x56fa9b: 0fbf4302 MOVSX EAX,word ptr [EBX + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.bx+0x00000002u)),16));
  }
  L0056fa9f: { // 0x56fa9f: 8b542460 MOV EDX,dword ptr [ESP + 0x60]
    s.dx = m.r32((f.sp+0x00000060u));
  }
  L0056faa3: { // 0x56faa3: 8b4c2460 MOV ECX,dword ptr [ESP + 0x60]
    s.cx = m.r32((f.sp+0x00000060u));
  }
  L0056faa7: { // 0x56faa7: 2bf5 SUB ESI,EBP
    s.si = integer::sub(s.si,s.bp,32,flags);
  }
  L0056faa9: { // 0x56faa9: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0056faab: { // 0x56faab: 83c602 ADD ESI,0x2
    s.si = integer::add(s.si,0x00000002u,32,flags);
  }
  L0056faae: { // 0x56faae: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L0056fab1: { // 0x56fab1: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0056fab2: { // 0x56fab2: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0056fab6: { // 0x56fab6: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0056fab8: { // 0x56fab8: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L0056faba: { // 0x56faba: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L0056fabe: { // 0x56fabe: 7d70 JGE 0x0056fb30
    if(integer::condition("JGE",flags)) goto L0056fb30;
  }
  L0056fac0: { // 0x56fac0: 8d6c2eff LEA EBP,[ESI + EBP*0x1 + -0x1]
    s.bp = (s.si+(s.bp * 0x00000001u)-0x00000001u);
  }
  L0056fac4: { // 0x56fac4: 896c2428 MOV dword ptr [ESP + 0x28],EBP
    m.w32((f.sp+0x00000028u), s.bp);
  }
  L0056fac8: { // 0x56fac8: 3bf5 CMP ESI,EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  L0056faca: { // 0x56faca: 8bde MOV EBX,ESI
    s.bx = s.si;
  }
  L0056facc: { // 0x56facc: 7d51 JGE 0x0056fb1f
    if(integer::condition("JGE",flags)) goto L0056fb1f;
  }
  L0056face: { // 0x56face: 668b542418 MOV DX,word ptr [ESP + 0x18]
    s.dx = with_ax(s.dx, m.r16((f.sp+0x00000018u)));
  }
  L0056fad3: { // 0x56fad3: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L0056fad7: { // 0x56fad7: 66895c2414 MOV word ptr [ESP + 0x14],BX
    m.w16((f.sp+0x00000014u), (s.bx & 0xffffu));
  }
  L0056fadc: { // 0x56fadc: 6689542416 MOV word ptr [ESP + 0x16],DX
    m.w16((f.sp+0x00000016u), (s.dx & 0xffffu));
  }
  L0056fae1: { // 0x56fae1: e82aad0100 CALL 0x0058a810
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058a810u,5700326u); flags=s.arithmetic_flags;
  }
  L0056fae6: { // 0x56fae6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0056fae8: { // 0x56fae8: 742c JZ 0x0056fb16
    if(integer::condition("JZ",flags)) goto L0056fb16;
  }
  L0056faea: { // 0x56faea: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L0056faee: { // 0x56faee: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L0056faf2: { // 0x56faf2: 8b5508 MOV EDX,dword ptr [EBP + 0x8]
    s.dx = m.r32((s.bp+0x00000008u));
  }
  L0056faf5: { // 0x56faf5: e866bcffff CALL 0x0056b760
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056b760u,5700346u); flags=s.arithmetic_flags;
  }
  L0056fafa: { // 0x56fafa: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L0056fafe: { // 0x56fafe: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0056fb03: { // 0x56fb03: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0056fb04: { // 0x56fb04: e8f759fdff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5700361u); flags=s.arithmetic_flags;
  }
  L0056fb09: { // 0x56fb09: 8a4d10 MOV CL,byte ptr [EBP + 0x10]
    s.cx = with_al(s.cx, m.r8((s.bp+0x00000010u)));
  }
  L0056fb0c: { // 0x56fb0c: 8b6c2428 MOV EBP,dword ptr [ESP + 0x28]
    s.bp = m.r32((f.sp+0x00000028u));
  }
  L0056fb10: { // 0x56fb10: 88881b010000 MOV byte ptr [EAX + 0x11b],CL
    m.w8((s.ax+0x0000011bu), (s.cx & 0xffu));
  }
  L0056fb16: { // 0x56fb16: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L0056fb17: { // 0x56fb17: 3bdd CMP EBX,EBP
    (void)integer::sub(s.bx,s.bp,32,flags);
  }
  L0056fb19: { // 0x56fb19: 7cb3 JL 0x0056face
    if(integer::condition("JL",flags)) goto L0056face;
  }
  L0056fb1b: { // 0x56fb1b: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L0056fb1f: { // 0x56fb1f: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0056fb23: { // 0x56fb23: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0056fb24: { // 0x56fb24: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L0056fb26: { // 0x56fb26: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0056fb2a: { // 0x56fb2a: 7c9c JL 0x0056fac8
    if(integer::condition("JL",flags)) goto L0056fac8;
  }
  L0056fb2c: { // 0x56fb2c: 8b5c2474 MOV EBX,dword ptr [ESP + 0x74]
    s.bx = m.r32((f.sp+0x00000074u));
  }
  L0056fb30: { // 0x56fb30: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L0056fb34: { // 0x56fb34: 8b742478 MOV ESI,dword ptr [ESP + 0x78]
    s.si = m.r32((f.sp+0x00000078u));
  }
  L0056fb38: { // 0x56fb38: 8b0d705ca500 MOV ECX,dword ptr [0x00a55c70]
    s.cx = m.r32((0x00a55c70u));
  }
  L0056fb3e: { // 0x56fb3e: 8b5510 MOV EDX,dword ptr [EBP + 0x10]
    s.dx = m.r32((s.bp+0x00000010u));
  }
  L0056fb41: { // 0x56fb41: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0056fb42: { // 0x56fb42: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0056fb43: { // 0x56fb43: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  L0056fb45: { // 0x56fb45: e8a6560100 CALL 0x005851f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005851f0u,5700426u); flags=s.arithmetic_flags;
  }
  L0056fb4a: { // 0x56fb4a: 668b03 MOV AX,word ptr [EBX]
    s.ax = with_ax(s.ax, m.r16((s.bx)));
  }
  L0056fb4d: { // 0x56fb4d: 668b4b02 MOV CX,word ptr [EBX + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.bx+0x00000002u)));
  }
  L0056fb51: { // 0x56fb51: 662d0200 SUB AX,0x2
    s.ax = with_ax(s.ax, integer::sub((s.ax & 0xffffu),0x00000002u,16,flags));
  }
  L0056fb55: { // 0x56fb55: 66894c241e MOV word ptr [ESP + 0x1e],CX
    m.w16((f.sp+0x0000001eu), (s.cx & 0xffffu));
  }
  L0056fb5a: { // 0x56fb5a: 8b0d705ca500 MOV ECX,dword ptr [0x00a55c70]
    s.cx = m.r32((0x00a55c70u));
  }
  L0056fb60: { // 0x56fb60: 668944241c MOV word ptr [ESP + 0x1c],AX
    m.w16((f.sp+0x0000001cu), (s.ax & 0xffffu));
  }
  L0056fb65: { // 0x56fb65: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L0056fb69: { // 0x56fb69: 8b4510 MOV EAX,dword ptr [EBP + 0x10]
    s.ax = m.r32((s.bp+0x00000010u));
  }
  L0056fb6c: { // 0x56fb6c: 89542428 MOV dword ptr [ESP + 0x28],EDX
    m.w32((f.sp+0x00000028u), s.dx);
  }
  L0056fb70: { // 0x56fb70: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0056fb71: { // 0x56fb71: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0056fb72: { // 0x56fb72: 8d542430 LEA EDX,[ESP + 0x30]
    s.dx = (f.sp+0x00000030u);
  }
  L0056fb76: { // 0x56fb76: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0056fb77: { // 0x56fb77: e874560100 CALL 0x005851f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005851f0u,5700476u); flags=s.arithmetic_flags;
  }
  L0056fb7c: { // 0x56fb7c: 8b6c2430 MOV EBP,dword ptr [ESP + 0x30]
    s.bp = m.r32((f.sp+0x00000030u));
  }
  L0056fb80: { // 0x56fb80: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0056fb82: { // 0x56fb82: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L0056fb84: { // 0x56fb84: 6689442428 MOV word ptr [ESP + 0x28],AX
    m.w16((f.sp+0x00000028u), (s.ax & 0xffffu));
  }
  L0056fb89: { // 0x56fb89: 668944242a MOV word ptr [ESP + 0x2a],AX
    m.w16((f.sp+0x0000002au), (s.ax & 0xffffu));
  }
  L0056fb8e: { // 0x56fb8e: 0f8497010000 JZ 0x0056fd2b
    if(integer::condition("JZ",flags)) goto L0056fd2b;
  }
  L0056fb94: { // 0x56fb94: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0056fb99: { // 0x56fb99: e842020c00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5700510u); flags=s.arithmetic_flags;
  }
  L0056fb9e: { // 0x56fb9e: 8944244c MOV dword ptr [ESP + 0x4c],EAX
    m.w32((f.sp+0x0000004cu), s.ax);
  }
  L0056fba2: { // 0x56fba2: c744245000000000 MOV dword ptr [ESP + 0x50],0x0
    m.w32((f.sp+0x00000050u), 0x00000000u);
  }
  L0056fbaa: { // 0x56fbaa: df6c244c FILD qword ptr [ESP + 0x4c]
    const auto address=(f.sp+0x0000004cu);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0056fbae: { // 0x56fbae: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0056fbb4: { // 0x56fbb4: e897ae1f00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5700537u); flags=s.arithmetic_flags;
  }
  L0056fbb9: { // 0x56fbb9: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0056fbbb: { // 0x56fbbb: 83fe01 CMP ESI,0x1
    (void)integer::sub(s.si,0x00000001u,32,flags);
  }
  L0056fbbe: { // 0x56fbbe: 77d4 JA 0x0056fb94
    if(integer::condition("JA",flags)) goto L0056fb94;
  }
  L0056fbc0: { // 0x56fbc0: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0056fbc2: { // 0x56fbc2: 66c74424340000 MOV word ptr [ESP + 0x34],0x0
    m.w16((f.sp+0x00000034u), 0x00000000u);
  }
  L0056fbc9: { // 0x56fbc9: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0056fbcb: { // 0x56fbcb: 0f9fc1 SETG CL
    s.cx = with_al(s.cx, (integer::condition("JG",flags)?1u:0u));
  }
  L0056fbce: { // 0x56fbce: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0056fbd0: { // 0x56fbd0: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L0056fbd4: { // 0x56fbd4: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0056fbd6: { // 0x56fbd6: 0f9dc2 SETGE DL
    s.dx = with_al(s.dx, (integer::condition("JGE",flags)?1u:0u));
  }
  L0056fbd9: { // 0x56fbd9: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L0056fbda: { // 0x56fbda: 83fe01 CMP ESI,0x1
    (void)integer::sub(s.si,0x00000001u,32,flags);
  }
  L0056fbdd: { // 0x56fbdd: 6689542436 MOV word ptr [ESP + 0x36],DX
    m.w16((f.sp+0x00000036u), (s.dx & 0xffffu));
  }
  L0056fbe2: { // 0x56fbe2: 7511 JNZ 0x0056fbf5
    if(integer::condition("JNZ",flags)) goto L0056fbf5;
  }
  L0056fbe4: { // 0x56fbe4: 668b442470 MOV AX,word ptr [ESP + 0x70]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x00000070u)));
  }
  L0056fbe9: { // 0x56fbe9: 66896c242a MOV word ptr [ESP + 0x2a],BP
    m.w16((f.sp+0x0000002au), (s.bp & 0xffffu));
  }
  L0056fbee: { // 0x56fbee: 6689442428 MOV word ptr [ESP + 0x28],AX
    m.w16((f.sp+0x00000028u), (s.ax & 0xffffu));
  }
  L0056fbf3: { // 0x56fbf3: eb13 JMP 0x0056fc08
    goto L0056fc08;
  }
  L0056fbf5: { // 0x56fbf5: 668b03 MOV AX,word ptr [EBX]
    s.ax = with_ax(s.ax, m.r16((s.bx)));
  }
  L0056fbf8: { // 0x56fbf8: 662b442470 SUB AX,word ptr [ESP + 0x70]
    s.ax = with_ax(s.ax, integer::sub((s.ax & 0xffffu),m.r16((f.sp+0x00000070u)),16,flags));
  }
  L0056fbfd: { // 0x56fbfd: 662b07 SUB AX,word ptr [EDI]
    s.ax = with_ax(s.ax, integer::sub((s.ax & 0xffffu),m.r16((s.di)),16,flags));
  }
  L0056fc00: { // 0x56fc00: 83e805 SUB EAX,0x5
    s.ax = integer::sub(s.ax,0x00000005u,32,flags);
  }
  L0056fc03: { // 0x56fc03: 6689442434 MOV word ptr [ESP + 0x34],AX
    m.w16((f.sp+0x00000034u), (s.ax & 0xffffu));
  }
  L0056fc08: { // 0x56fc08: 8b542470 MOV EDX,dword ptr [ESP + 0x70]
    s.dx = m.r32((f.sp+0x00000070u));
  }
  L0056fc0c: { // 0x56fc0c: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0056fc0e: { // 0x56fc0e: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0056fc10: { // 0x56fc10: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L0056fc14: { // 0x56fc14: 0f8e11010000 JLE 0x0056fd2b
    if(integer::condition("JLE",flags)) goto L0056fd2b;
  }
  L0056fc1a: { // 0x56fc1a: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0056fc1e: { // 0x56fc1e: eb08 JMP 0x0056fc28
    goto L0056fc28;
  }
  L0056fc20: { // 0x56fc20: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0056fc24: { // 0x56fc24: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0056fc28: { // 0x56fc28: 8d1489 LEA EDX,[ECX + ECX*0x4]
    s.dx = (s.cx+(s.cx * 0x00000004u));
  }
  L0056fc2b: { // 0x56fc2b: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L0056fc2d: { // 0x56fc2d: bec4b47c00 MOV ESI,0x7cb4c4
    s.si = 0x007cb4c4u;
  }
  L0056fc32: { // 0x56fc32: 8d1c95d8b47c00 LEA EBX,[EDX*0x4 + 0x7cb4d8]
    s.bx = ((s.dx * 0x00000004u)+0x007cb4d8u);
  }
  L0056fc39: { // 0x56fc39: eb04 JMP 0x0056fc3f
    goto L0056fc3f;
  }
  L0056fc3b: { // 0x56fc3b: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0056fc3f: { // 0x56fc3f: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0056fc41: { // 0x56fc41: 7406 JZ 0x0056fc49
    if(integer::condition("JZ",flags)) goto L0056fc49;
  }
  L0056fc43: { // 0x56fc43: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L0056fc47: { // 0x56fc47: eb08 JMP 0x0056fc51
    goto L0056fc51;
  }
  L0056fc49: { // 0x56fc49: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0056fc4d: { // 0x56fc4d: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L0056fc51: { // 0x56fc51: 668b17 MOV DX,word ptr [EDI]
    s.dx = with_ax(s.dx, m.r16((s.di)));
  }
  L0056fc54: { // 0x56fc54: 668b4f02 MOV CX,word ptr [EDI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.di+0x00000002u)));
  }
  L0056fc58: { // 0x56fc58: 6683c203 ADD DX,0x3
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),0x00000003u,16,flags));
  }
  L0056fc5c: { // 0x56fc5c: 66894c243e MOV word ptr [ESP + 0x3e],CX
    m.w16((f.sp+0x0000003eu), (s.cx & 0xffffu));
  }
  L0056fc61: { // 0x56fc61: 668954243c MOV word ptr [ESP + 0x3c],DX
    m.w16((f.sp+0x0000003cu), (s.dx & 0xffffu));
  }
  L0056fc66: { // 0x56fc66: 8b54243c MOV EDX,dword ptr [ESP + 0x3c]
    s.dx = m.r32((f.sp+0x0000003cu));
  }
  L0056fc6a: { // 0x56fc6a: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L0056fc6c: { // 0x56fc6c: 8b44243e MOV EAX,dword ptr [ESP + 0x3e]
    s.ax = m.r32((f.sp+0x0000003eu));
  }
  L0056fc70: { // 0x56fc70: 03c5 ADD EAX,EBP
    s.ax = integer::add(s.ax,s.bp,32,flags);
  }
  L0056fc72: { // 0x56fc72: 6689542444 MOV word ptr [ESP + 0x44],DX
    m.w16((f.sp+0x00000044u), (s.dx & 0xffffu));
  }
  L0056fc77: { // 0x56fc77: 8b542434 MOV EDX,dword ptr [ESP + 0x34]
    s.dx = m.r32((f.sp+0x00000034u));
  }
  L0056fc7b: { // 0x56fc7b: 6689442446 MOV word ptr [ESP + 0x46],AX
    m.w16((f.sp+0x00000046u), (s.ax & 0xffffu));
  }
  L0056fc80: { // 0x56fc80: 8b4c2444 MOV ECX,dword ptr [ESP + 0x44]
    s.cx = m.r32((f.sp+0x00000044u));
  }
  L0056fc84: { // 0x56fc84: 8d0411 LEA EAX,[ECX + EDX*0x1]
    s.ax = (s.cx+(s.dx * 0x00000001u));
  }
  L0056fc87: { // 0x56fc87: 8b4c2446 MOV ECX,dword ptr [ESP + 0x46]
    s.cx = m.r32((f.sp+0x00000046u));
  }
  L0056fc8b: { // 0x56fc8b: 8b542436 MOV EDX,dword ptr [ESP + 0x36]
    s.dx = m.r32((f.sp+0x00000036u));
  }
  L0056fc8f: { // 0x56fc8f: 6689442424 MOV word ptr [ESP + 0x24],AX
    m.w16((f.sp+0x00000024u), (s.ax & 0xffffu));
  }
  L0056fc94: { // 0x56fc94: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L0056fc96: { // 0x56fc96: 66894c244e MOV word ptr [ESP + 0x4e],CX
    m.w16((f.sp+0x0000004eu), (s.cx & 0xffffu));
  }
  L0056fc9b: { // 0x56fc9b: 8b44244e MOV EAX,dword ptr [ESP + 0x4e]
    s.ax = m.r32((f.sp+0x0000004eu));
  }
  L0056fc9f: { // 0x56fc9f: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L0056fca3: { // 0x56fca3: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0056fca5: { // 0x56fca5: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0056fcaa: { // 0x56fcaa: 6689442426 MOV word ptr [ESP + 0x26],AX
    m.w16((f.sp+0x00000026u), (s.ax & 0xffffu));
  }
  L0056fcaf: { // 0x56fcaf: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L0056fcb3: { // 0x56fcb3: 8d442430 LEA EAX,[ESP + 0x30]
    s.ax = (f.sp+0x00000030u);
  }
  L0056fcb7: { // 0x56fcb7: 89542430 MOV dword ptr [ESP + 0x30],EDX
    m.w32((f.sp+0x00000030u), s.dx);
  }
  L0056fcbb: { // 0x56fcbb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0056fcbc: { // 0x56fcbc: e83f58fdff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5700801u); flags=s.arithmetic_flags;
  }
  L0056fcc1: { // 0x56fcc1: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0056fcc5: { // 0x56fcc5: 8a0e MOV CL,byte ptr [ESI]
    s.cx = with_al(s.cx, m.r8((s.si)));
  }
  L0056fcc7: { // 0x56fcc7: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  L0056fcca: { // 0x56fcca: 83c304 ADD EBX,0x4
    s.bx = integer::add(s.bx,0x00000004u,32,flags);
  }
  L0056fccd: { // 0x56fccd: 024a10 ADD CL,byte ptr [EDX + 0x10]
    s.cx = with_al(s.cx, integer::add((s.cx & 0xffu),m.r8((s.dx+0x00000010u)),8,flags));
  }
  L0056fcd0: { // 0x56fcd0: 80e904 SUB CL,0x4
    s.cx = with_al(s.cx, integer::sub((s.cx & 0xffu),0x00000004u,8,flags));
  }
  L0056fcd3: { // 0x56fcd3: 88881b010000 MOV byte ptr [EAX + 0x11b],CL
    m.w8((s.ax+0x0000011bu), (s.cx & 0xffu));
  }
  L0056fcd9: { // 0x56fcd9: 8a4bfc MOV CL,byte ptr [EBX + -0x4]
    s.cx = with_al(s.cx, m.r8((s.bx-0x00000004u)));
  }
  L0056fcdc: { // 0x56fcdc: 88881c010000 MOV byte ptr [EAX + 0x11c],CL
    m.w8((s.ax+0x0000011cu), (s.cx & 0xffu));
  }
  L0056fce2: { // 0x56fce2: 8b15505ca500 MOV EDX,dword ptr [0x00a55c50]
    s.dx = m.r32((0x00a55c50u));
  }
  L0056fce8: { // 0x56fce8: 81e1ff000000 AND ECX,0xff
    s.cx = integer::logical((s.cx)&(0x000000ffu),32,flags);
  }
  L0056fcee: { // 0x56fcee: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L0056fcef: { // 0x56fcef: c6801a01000000 MOV byte ptr [EAX + 0x11a],0x0
    m.w8((s.ax+0x0000011au), 0x00000000u);
  }
  L0056fcf6: { // 0x56fcf6: 81fed8b47c00 CMP ESI,0x7cb4d8
    (void)integer::sub(s.si,0x007cb4d8u,32,flags);
  }
  L0056fcfc: { // 0x56fcfc: 8d4c11ff LEA ECX,[ECX + EDX*0x1 + -0x1]
    s.cx = (s.cx+(s.dx * 0x00000001u)-0x00000001u);
  }
  L0056fd00: { // 0x56fd00: 894838 MOV dword ptr [EAX + 0x38],ECX
    m.w32((s.ax+0x00000038u), s.cx);
  }
  L0056fd03: { // 0x56fd03: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0056fd07: { // 0x56fd07: 0f8c2effffff JL 0x0056fc3b
    if(integer::condition("JL",flags)) goto L0056fc3b;
  }
  L0056fd0d: { // 0x56fd0d: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0056fd11: { // 0x56fd11: 8b4c2470 MOV ECX,dword ptr [ESP + 0x70]
    s.cx = m.r32((f.sp+0x00000070u));
  }
  L0056fd15: { // 0x56fd15: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0056fd16: { // 0x56fd16: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L0056fd17: { // 0x56fd17: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0056fd19: { // 0x56fd19: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L0056fd1d: { // 0x56fd1d: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L0056fd21: { // 0x56fd21: 0f8cf9feffff JL 0x0056fc20
    if(integer::condition("JL",flags)) goto L0056fc20;
  }
  L0056fd27: { // 0x56fd27: 8b5c2474 MOV EBX,dword ptr [ESP + 0x74]
    s.bx = m.r32((f.sp+0x00000074u));
  }
  L0056fd2b: { // 0x56fd2b: 0fbf17 MOVSX EDX,word ptr [EDI]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.di)),16));
  }
  L0056fd2e: { // 0x56fd2e: 0fbf03 MOVSX EAX,word ptr [EBX]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.bx)),16));
  }
  L0056fd31: { // 0x56fd31: 8b5c2470 MOV EBX,dword ptr [ESP + 0x70]
    s.bx = m.r32((f.sp+0x00000070u));
  }
  L0056fd35: { // 0x56fd35: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0056fd37: { // 0x56fd37: 2bc3 SUB EAX,EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L0056fd39: { // 0x56fd39: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0056fd3b: { // 0x56fd3b: 83e805 SUB EAX,0x5
    s.ax = integer::sub(s.ax,0x00000005u,32,flags);
  }
  L0056fd3e: { // 0x56fd3e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0056fd40: { // 0x56fd40: 0f8ede000000 JLE 0x0056fe24
    if(integer::condition("JLE",flags)) goto L0056fe24;
  }
  L0056fd46: { // 0x56fd46: 8b6c242a MOV EBP,dword ptr [ESP + 0x2a]
    s.bp = m.r32((f.sp+0x0000002au));
  }
  L0056fd4a: { // 0x56fd4a: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0056fd4c: { // 0x56fd4c: 668b0f MOV CX,word ptr [EDI]
    s.cx = with_ax(s.cx, m.r16((s.di)));
  }
  L0056fd4f: { // 0x56fd4f: 668b5702 MOV DX,word ptr [EDI + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.di+0x00000002u)));
  }
  L0056fd53: { // 0x56fd53: 6683c103 ADD CX,0x3
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),0x00000003u,16,flags));
  }
  L0056fd57: { // 0x56fd57: 6689542446 MOV word ptr [ESP + 0x46],DX
    m.w16((f.sp+0x00000046u), (s.dx & 0xffffu));
  }
  L0056fd5c: { // 0x56fd5c: 66894c2444 MOV word ptr [ESP + 0x44],CX
    m.w16((f.sp+0x00000044u), (s.cx & 0xffffu));
  }
  L0056fd61: { // 0x56fd61: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    s.ax = m.r32((f.sp+0x00000044u));
  }
  L0056fd65: { // 0x56fd65: 8b4c2446 MOV ECX,dword ptr [ESP + 0x46]
    s.cx = m.r32((f.sp+0x00000046u));
  }
  L0056fd69: { // 0x56fd69: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L0056fd6b: { // 0x56fd6b: 03cb ADD ECX,EBX
    s.cx = integer::add(s.cx,s.bx,32,flags);
  }
  L0056fd6d: { // 0x56fd6d: 668944243c MOV word ptr [ESP + 0x3c],AX
    m.w16((f.sp+0x0000003cu), (s.ax & 0xffffu));
  }
  L0056fd72: { // 0x56fd72: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L0056fd76: { // 0x56fd76: 66894c243e MOV word ptr [ESP + 0x3e],CX
    m.w16((f.sp+0x0000003eu), (s.cx & 0xffffu));
  }
  L0056fd7b: { // 0x56fd7b: 8b54243c MOV EDX,dword ptr [ESP + 0x3c]
    s.dx = m.r32((f.sp+0x0000003cu));
  }
  L0056fd7f: { // 0x56fd7f: 8d0c02 LEA ECX,[EDX + EAX*0x1]
    s.cx = (s.dx+(s.ax * 0x00000001u));
  }
  L0056fd82: { // 0x56fd82: 8b54243e MOV EDX,dword ptr [ESP + 0x3e]
    s.dx = m.r32((f.sp+0x0000003eu));
  }
  L0056fd86: { // 0x56fd86: 66894c2424 MOV word ptr [ESP + 0x24],CX
    m.w16((f.sp+0x00000024u), (s.cx & 0xffffu));
  }
  L0056fd8b: { // 0x56fd8b: 8d042a LEA EAX,[EDX + EBP*0x1]
    s.ax = (s.dx+(s.bp * 0x00000001u));
  }
  L0056fd8e: { // 0x56fd8e: 6689442426 MOV word ptr [ESP + 0x26],AX
    m.w16((f.sp+0x00000026u), (s.ax & 0xffffu));
  }
  L0056fd93: { // 0x56fd93: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L0056fd97: { // 0x56fd97: 89542430 MOV dword ptr [ESP + 0x30],EDX
    m.w32((f.sp+0x00000030u), s.dx);
  }
  L0056fd9b: { // 0x56fd9b: 8b153c86a500 MOV EDX,dword ptr [0x00a5863c]
    s.dx = m.r32((0x00a5863cu));
  }
  L0056fda1: { // 0x56fda1: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0056fda3: { // 0x56fda3: 741d JZ 0x0056fdc2
    if(integer::condition("JZ",flags)) goto L0056fdc2;
  }
  L0056fda5: { // 0x56fda5: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0056fda8: { // 0x56fda8: 0faf054c6b8300 IMUL EAX,dword ptr [0x00836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  L0056fdaf: { // 0x56fdaf: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L0056fdb2: { // 0x56fdb2: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0056fdb4: { // 0x56fdb4: 8b4c2478 MOV ECX,dword ptr [ESP + 0x78]
    s.cx = m.r32((f.sp+0x00000078u));
  }
  L0056fdb8: { // 0x56fdb8: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0056fdbb: { // 0x56fdbb: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L0056fdbe: { // 0x56fdbe: 894c1038 MOV dword ptr [EAX + EDX*0x1 + 0x38],ECX
    m.w32((s.ax+(s.dx * 0x00000001u)+0x00000038u), s.cx);
  }
  L0056fdc2: { // 0x56fdc2: 8d542430 LEA EDX,[ESP + 0x30]
    s.dx = (f.sp+0x00000030u);
  }
  L0056fdc6: { // 0x56fdc6: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0056fdcb: { // 0x56fdcb: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0056fdcc: { // 0x56fdcc: e82f57fdff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5701073u); flags=s.arithmetic_flags;
  }
  L0056fdd1: { // 0x56fdd1: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L0056fdd5: { // 0x56fdd5: 8a5110 MOV DL,byte ptr [ECX + 0x10]
    s.dx = with_al(s.dx, m.r8((s.cx+0x00000010u)));
  }
  L0056fdd8: { // 0x56fdd8: c6801c01000004 MOV byte ptr [EAX + 0x11c],0x4
    m.w8((s.ax+0x0000011cu), 0x00000004u);
  }
  L0056fddf: { // 0x56fddf: 2ad3 SUB DL,BL
    s.dx = with_al(s.dx, integer::sub((s.dx & 0xffu),(s.bx & 0xffu),8,flags));
  }
  L0056fde1: { // 0x56fde1: feca DEC DL
    s.dx = with_al(s.dx, integer::decrement((s.dx & 0xffu),8,flags));
  }
  L0056fde3: { // 0x56fde3: 88901b010000 MOV byte ptr [EAX + 0x11b],DL
    m.w8((s.ax+0x0000011bu), (s.dx & 0xffu));
  }
  L0056fde9: { // 0x56fde9: 8b0d505ca500 MOV ECX,dword ptr [0x00a55c50]
    s.cx = m.r32((0x00a55c50u));
  }
  L0056fdef: { // 0x56fdef: 83c103 ADD ECX,0x3
    s.cx = integer::add(s.cx,0x00000003u,32,flags);
  }
  L0056fdf2: { // 0x56fdf2: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L0056fdf3: { // 0x56fdf3: 83fb04 CMP EBX,0x4
    (void)integer::sub(s.bx,0x00000004u,32,flags);
  }
  L0056fdf6: { // 0x56fdf6: 894838 MOV dword ptr [EAX + 0x38],ECX
    m.w32((s.ax+0x00000038u), s.cx);
  }
  L0056fdf9: { // 0x56fdf9: c6801a01000000 MOV byte ptr [EAX + 0x11a],0x0
    m.w8((s.ax+0x0000011au), 0x00000000u);
  }
  L0056fe00: { // 0x56fe00: 0f8c46ffffff JL 0x0056fd4c
    if(integer::condition("JL",flags)) goto L0056fd4c;
  }
  L0056fe06: { // 0x56fe06: 8b442474 MOV EAX,dword ptr [ESP + 0x74]
    s.ax = m.r32((f.sp+0x00000074u));
  }
  L0056fe0a: { // 0x56fe0a: 8b5c2470 MOV EBX,dword ptr [ESP + 0x70]
    s.bx = m.r32((f.sp+0x00000070u));
  }
  L0056fe0e: { // 0x56fe0e: 0fbf17 MOVSX EDX,word ptr [EDI]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.di)),16));
  }
  L0056fe11: { // 0x56fe11: 0fbf08 MOVSX ECX,word ptr [EAX]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.ax)),16));
  }
  L0056fe14: { // 0x56fe14: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L0056fe16: { // 0x56fe16: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0056fe17: { // 0x56fe17: 2bcb SUB ECX,EBX
    s.cx = integer::sub(s.cx,s.bx,32,flags);
  }
  L0056fe19: { // 0x56fe19: 83e905 SUB ECX,0x5
    s.cx = integer::sub(s.cx,0x00000005u,32,flags);
  }
  L0056fe1c: { // 0x56fe1c: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L0056fe1e: { // 0x56fe1e: 0f8c26ffffff JL 0x0056fd4a
    if(integer::condition("JL",flags)) goto L0056fd4a;
  }
  L0056fe24: { // 0x56fe24: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0056fe25: { // 0x56fe25: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0056fe26: { // 0x56fe26: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0056fe27: { // 0x56fe27: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0056fe29: { // 0x56fe29: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0056fe2a: { // 0x56fe2a: 83c45c ADD ESP,0x5c
    f.sp = integer::add(f.sp,0x0000005cu,32,flags);
  }
  L0056fe2d: { // 0x56fe2d: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_0056fe30(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0056fe30: { // 0x56fe30: 83ec5c SUB ESP,0x5c
    f.sp = integer::sub(f.sp,0x0000005cu,32,flags);
  }
  L0056fe33: { // 0x56fe33: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0056fe34: { // 0x56fe34: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0056fe35: { // 0x56fe35: 8b6c246c MOV EBP,dword ptr [ESP + 0x6c]
    s.bp = m.r32((f.sp+0x0000006cu));
  }
  L0056fe39: { // 0x56fe39: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0056fe3a: { // 0x56fe3a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0056fe3b: { // 0x56fe3b: 8b7c2470 MOV EDI,dword ptr [ESP + 0x70]
    s.di = m.r32((f.sp+0x00000070u));
  }
  L0056fe3f: { // 0x56fe3f: 668b5500 MOV DX,word ptr [EBP]
    s.dx = with_ax(s.dx, m.r16((s.bp)));
  }
  L0056fe43: { // 0x56fe43: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L0056fe47: { // 0x56fe47: 668b07 MOV AX,word ptr [EDI]
    s.ax = with_ax(s.ax, m.r16((s.di)));
  }
  L0056fe4a: { // 0x56fe4a: 663bc2 CMP AX,DX
    (void)integer::sub((s.ax & 0xffffu),(s.dx & 0xffffu),16,flags);
  }
  L0056fe4d: { // 0x56fe4d: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0056fe4f: { // 0x56fe4f: 7f02 JG 0x0056fe53
    if(integer::condition("JG",flags)) goto L0056fe53;
  }
  L0056fe51: { // 0x56fe51: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  L0056fe53: { // 0x56fe53: 663bc2 CMP AX,DX
    (void)integer::sub((s.ax & 0xffffu),(s.dx & 0xffffu),16,flags);
  }
  L0056fe56: { // 0x56fe56: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0056fe58: { // 0x56fe58: 7c02 JL 0x0056fe5c
    if(integer::condition("JL",flags)) goto L0056fe5c;
  }
  L0056fe5a: { // 0x56fe5a: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L0056fe5c: { // 0x56fe5c: 663bc2 CMP AX,DX
    (void)integer::sub((s.ax & 0xffffu),(s.dx & 0xffffu),16,flags);
  }
  L0056fe5f: { // 0x56fe5f: 7c02 JL 0x0056fe63
    if(integer::condition("JL",flags)) goto L0056fe63;
  }
  L0056fe61: { // 0x56fe61: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L0056fe63: { // 0x56fe63: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0056fe66: { // 0x56fe66: 83e803 SUB EAX,0x3
    s.ax = integer::sub(s.ax,0x00000003u,32,flags);
  }
  L0056fe69: { // 0x56fe69: 8944245c MOV dword ptr [ESP + 0x5c],EAX
    m.w32((f.sp+0x0000005cu), s.ax);
  }
  L0056fe6d: { // 0x56fe6d: 0fbf4502 MOVSX EAX,word ptr [EBP + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.bp+0x00000002u)),16));
  }
  L0056fe71: { // 0x56fe71: 8d50fc LEA EDX,[EAX + -0x4]
    s.dx = (s.ax-0x00000004u);
  }
  L0056fe74: { // 0x56fe74: 89542460 MOV dword ptr [ESP + 0x60],EDX
    m.w32((f.sp+0x00000060u), s.dx);
  }
  L0056fe78: { // 0x56fe78: 0fbfd6 MOVSX EDX,SI
    s.dx = std::uint32_t(integer::sign_extend((s.si & 0xffffu),16));
  }
  L0056fe7b: { // 0x56fe7b: 0fbff3 MOVSX ESI,BX
    s.si = std::uint32_t(integer::sign_extend((s.bx & 0xffffu),16));
  }
  L0056fe7e: { // 0x56fe7e: 2bf2 SUB ESI,EDX
    s.si = integer::sub(s.si,s.dx,32,flags);
  }
  L0056fe80: { // 0x56fe80: 0fbf5702 MOVSX EDX,word ptr [EDI + 0x2]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L0056fe84: { // 0x56fe84: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L0056fe86: { // 0x56fe86: 8b442478 MOV EAX,dword ptr [ESP + 0x78]
    s.ax = m.r32((f.sp+0x00000078u));
  }
  L0056fe8a: { // 0x56fe8a: 83c209 ADD EDX,0x9
    s.dx = integer::add(s.dx,0x00000009u,32,flags);
  }
  L0056fe8d: { // 0x56fe8d: 83c60b ADD ESI,0xb
    s.si = integer::add(s.si,0x0000000bu,32,flags);
  }
  L0056fe90: { // 0x56fe90: 89542468 MOV dword ptr [ESP + 0x68],EDX
    m.w32((f.sp+0x00000068u), s.dx);
  }
  L0056fe94: { // 0x56fe94: 8d54245c LEA EDX,[ESP + 0x5c]
    s.dx = (f.sp+0x0000005cu);
  }
  L0056fe98: { // 0x56fe98: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0056fe99: { // 0x56fe99: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0056fe9a: { // 0x56fe9a: 8974246c MOV dword ptr [ESP + 0x6c],ESI
    m.w32((f.sp+0x0000006cu), s.si);
  }
  L0056fe9e: { // 0x56fe9e: e85d280000 CALL 0x00572700
    s.arithmetic_flags=flags; invoke(m,s,f,0x00572700u,5701283u); flags=s.arithmetic_flags;
  }
  L0056fea3: { // 0x56fea3: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0056fea5: { // 0x56fea5: 750a JNZ 0x0056feb1
    if(integer::condition("JNZ",flags)) goto L0056feb1;
  }
  L0056fea7: { // 0x56fea7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0056fea8: { // 0x56fea8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0056fea9: { // 0x56fea9: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0056feaa: { // 0x56feaa: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0056feab: { // 0x56feab: 83c45c ADD ESP,0x5c
    f.sp = integer::add(f.sp,0x0000005cu,32,flags);
  }
  L0056feae: { // 0x56feae: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0056feb1: { // 0x56feb1: 0fbf1f MOVSX EBX,word ptr [EDI]
    s.bx = std::uint32_t(integer::sign_extend(m.r16((s.di)),16));
  }
  L0056feb4: { // 0x56feb4: 0fbf4500 MOVSX EAX,word ptr [EBP]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.bp)),16));
  }
  L0056feb8: { // 0x56feb8: 2bc3 SUB EAX,EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L0056feba: { // 0x56feba: 0fbf4f02 MOVSX ECX,word ptr [EDI + 0x2]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L0056febe: { // 0x56febe: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L0056fec2: { // 0x56fec2: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0056fec3: { // 0x56fec3: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0056fec5: { // 0x56fec5: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0056fec7: { // 0x56fec7: 33f2 XOR ESI,EDX
    s.si = integer::logical((s.si)^(s.dx),32,flags);
  }
  L0056fec9: { // 0x56fec9: 2bf2 SUB ESI,EDX
    s.si = integer::sub(s.si,s.dx,32,flags);
  }
  L0056fecb: { // 0x56fecb: 0fbf5502 MOVSX EDX,word ptr [EBP + 0x2]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.bp+0x00000002u)),16));
  }
  L0056fecf: { // 0x56fecf: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0056fed1: { // 0x56fed1: 89742470 MOV dword ptr [ESP + 0x70],ESI
    m.w32((f.sp+0x00000070u), s.si);
  }
  L0056fed5: { // 0x56fed5: 8d50fb LEA EDX,[EAX + -0x5]
    s.dx = (s.ax-0x00000005u);
  }
  L0056fed8: { // 0x56fed8: 3bf2 CMP ESI,EDX
    (void)integer::sub(s.si,s.dx,32,flags);
  }
  L0056feda: { // 0x56feda: 7e0c JLE 0x0056fee8
    if(integer::condition("JLE",flags)) goto L0056fee8;
  }
  L0056fedc: { // 0x56fedc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0056fedd: { // 0x56fedd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0056fede: { // 0x56fede: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0056fedf: { // 0x56fedf: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0056fee1: { // 0x56fee1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0056fee2: { // 0x56fee2: 83c45c ADD ESP,0x5c
    f.sp = integer::add(f.sp,0x0000005cu,32,flags);
  }
  L0056fee5: { // 0x56fee5: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0056fee8: { // 0x56fee8: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0056fee9: { // 0x56fee9: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0056feea: { // 0x56feea: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0056feec: { // 0x56feec: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0056feee: { // 0x56feee: d1fe SAR ESI,0x1
    s.si = integer::shift(s.si,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0056fef0: { // 0x56fef0: 83c602 ADD ESI,0x2
    s.si = integer::add(s.si,0x00000002u,32,flags);
  }
  L0056fef3: { // 0x56fef3: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L0056fef4: { // 0x56fef4: 2bce SUB ECX,ESI
    s.cx = integer::sub(s.cx,s.si,32,flags);
  }
  L0056fef6: { // 0x56fef6: 895c244c MOV dword ptr [ESP + 0x4c],EBX
    m.w32((f.sp+0x0000004cu), s.bx);
  }
  L0056fefa: { // 0x56fefa: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L0056fefd: { // 0x56fefd: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0056ff01: { // 0x56ff01: 8d540e03 LEA EDX,[ESI + ECX*0x1 + 0x3]
    s.dx = (s.si+(s.cx * 0x00000001u)+0x00000003u);
  }
  L0056ff05: { // 0x56ff05: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L0056ff07: { // 0x56ff07: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L0056ff0b: { // 0x56ff0b: 7d76 JGE 0x0056ff83
    if(integer::condition("JGE",flags)) goto L0056ff83;
  }
  L0056ff0d: { // 0x56ff0d: 8d4307 LEA EAX,[EBX + 0x7]
    s.ax = (s.bx+0x00000007u);
  }
  L0056ff10: { // 0x56ff10: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L0056ff12: { // 0x56ff12: 8beb MOV EBP,EBX
    s.bp = s.bx;
  }
  L0056ff14: { // 0x56ff14: 7d5c JGE 0x0056ff72
    if(integer::condition("JGE",flags)) goto L0056ff72;
  }
  L0056ff16: { // 0x56ff16: 668b442418 MOV AX,word ptr [ESP + 0x18]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x00000018u)));
  }
  L0056ff1b: { // 0x56ff1b: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L0056ff1f: { // 0x56ff1f: 66896c2414 MOV word ptr [ESP + 0x14],BP
    m.w16((f.sp+0x00000014u), (s.bp & 0xffffu));
  }
  L0056ff24: { // 0x56ff24: 6689442416 MOV word ptr [ESP + 0x16],AX
    m.w16((f.sp+0x00000016u), (s.ax & 0xffffu));
  }
  L0056ff29: { // 0x56ff29: e8e2a80100 CALL 0x0058a810
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058a810u,5701422u); flags=s.arithmetic_flags;
  }
  L0056ff2e: { // 0x56ff2e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0056ff30: { // 0x56ff30: 7434 JZ 0x0056ff66
    if(integer::condition("JZ",flags)) goto L0056ff66;
  }
  L0056ff32: { // 0x56ff32: 8b542478 MOV EDX,dword ptr [ESP + 0x78]
    s.dx = m.r32((f.sp+0x00000078u));
  }
  L0056ff36: { // 0x56ff36: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L0056ff3a: { // 0x56ff3a: e821b8ffff CALL 0x0056b760
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056b760u,5701439u); flags=s.arithmetic_flags;
  }
  L0056ff3f: { // 0x56ff3f: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L0056ff43: { // 0x56ff43: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0056ff44: { // 0x56ff44: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0056ff49: { // 0x56ff49: e8b255fdff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5701454u); flags=s.arithmetic_flags;
  }
  L0056ff4e: { // 0x56ff4e: 8b4c2478 MOV ECX,dword ptr [ESP + 0x78]
    s.cx = m.r32((f.sp+0x00000078u));
  }
  L0056ff52: { // 0x56ff52: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0056ff54: { // 0x56ff54: e8772b0000 CALL 0x00572ad0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00572ad0u,5701465u); flags=s.arithmetic_flags;
  }
  L0056ff59: { // 0x56ff59: 8a5010 MOV DL,byte ptr [EAX + 0x10]
    s.dx = with_al(s.dx, m.r8((s.ax+0x00000010u)));
  }
  L0056ff5c: { // 0x56ff5c: 88931b010000 MOV byte ptr [EBX + 0x11b],DL
    m.w8((s.bx+0x0000011bu), (s.dx & 0xffu));
  }
  L0056ff62: { // 0x56ff62: 8b5c244c MOV EBX,dword ptr [ESP + 0x4c]
    s.bx = m.r32((f.sp+0x0000004cu));
  }
  L0056ff66: { // 0x56ff66: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L0056ff67: { // 0x56ff67: 8d4307 LEA EAX,[EBX + 0x7]
    s.ax = (s.bx+0x00000007u);
  }
  L0056ff6a: { // 0x56ff6a: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L0056ff6c: { // 0x56ff6c: 7ca8 JL 0x0056ff16
    if(integer::condition("JL",flags)) goto L0056ff16;
  }
  L0056ff6e: { // 0x56ff6e: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L0056ff72: { // 0x56ff72: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0056ff76: { // 0x56ff76: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0056ff77: { // 0x56ff77: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L0056ff79: { // 0x56ff79: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0056ff7d: { // 0x56ff7d: 7c91 JL 0x0056ff10
    if(integer::condition("JL",flags)) goto L0056ff10;
  }
  L0056ff7f: { // 0x56ff7f: 8b6c2474 MOV EBP,dword ptr [ESP + 0x74]
    s.bp = m.r32((f.sp+0x00000074u));
  }
  L0056ff83: { // 0x56ff83: 0fbf6d00 MOVSX EBP,word ptr [EBP]
    s.bp = std::uint32_t(integer::sign_extend(m.r16((s.bp)),16));
  }
  L0056ff87: { // 0x56ff87: 8b442460 MOV EAX,dword ptr [ESP + 0x60]
    s.ax = m.r32((f.sp+0x00000060u));
  }
  L0056ff8b: { // 0x56ff8b: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L0056ff8c: { // 0x56ff8c: 896c244c MOV dword ptr [ESP + 0x4c],EBP
    m.w32((f.sp+0x0000004cu), s.bp);
  }
  L0056ff90: { // 0x56ff90: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0056ff94: { // 0x56ff94: 8d4c0602 LEA ECX,[ESI + EAX*0x1 + 0x2]
    s.cx = (s.si+(s.ax * 0x00000001u)+0x00000002u);
  }
  L0056ff98: { // 0x56ff98: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0056ff9a: { // 0x56ff9a: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L0056ff9e: { // 0x56ff9e: 7d72 JGE 0x00570012
    if(integer::condition("JGE",flags)) goto L00570012;
  }
  L0056ffa0: { // 0x56ffa0: 8d4507 LEA EAX,[EBP + 0x7]
    s.ax = (s.bp+0x00000007u);
  }
  L0056ffa3: { // 0x56ffa3: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L0056ffa5: { // 0x56ffa5: 8bdd MOV EBX,EBP
    s.bx = s.bp;
  }
  L0056ffa7: { // 0x56ffa7: 7d5c JGE 0x00570005
    if(integer::condition("JGE",flags)) goto L00570005;
  }
  L0056ffa9: { // 0x56ffa9: 668b442418 MOV AX,word ptr [ESP + 0x18]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x00000018u)));
  }
  L0056ffae: { // 0x56ffae: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L0056ffb2: { // 0x56ffb2: 66895c2414 MOV word ptr [ESP + 0x14],BX
    m.w16((f.sp+0x00000014u), (s.bx & 0xffffu));
  }
  L0056ffb7: { // 0x56ffb7: 6689442416 MOV word ptr [ESP + 0x16],AX
    m.w16((f.sp+0x00000016u), (s.ax & 0xffffu));
  }
  L0056ffbc: { // 0x56ffbc: e84fa80100 CALL 0x0058a810
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058a810u,5701569u); flags=s.arithmetic_flags;
  }
  L0056ffc1: { // 0x56ffc1: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0056ffc3: { // 0x56ffc3: 7434 JZ 0x0056fff9
    if(integer::condition("JZ",flags)) goto L0056fff9;
  }
  L0056ffc5: { // 0x56ffc5: 8b542478 MOV EDX,dword ptr [ESP + 0x78]
    s.dx = m.r32((f.sp+0x00000078u));
  }
  L0056ffc9: { // 0x56ffc9: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L0056ffcd: { // 0x56ffcd: e88eb7ffff CALL 0x0056b760
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056b760u,5701586u); flags=s.arithmetic_flags;
  }
  L0056ffd2: { // 0x56ffd2: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L0056ffd6: { // 0x56ffd6: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0056ffd7: { // 0x56ffd7: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0056ffdc: { // 0x56ffdc: e81f55fdff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5701601u); flags=s.arithmetic_flags;
  }
  L0056ffe1: { // 0x56ffe1: 8b4c2478 MOV ECX,dword ptr [ESP + 0x78]
    s.cx = m.r32((f.sp+0x00000078u));
  }
  L0056ffe5: { // 0x56ffe5: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L0056ffe7: { // 0x56ffe7: e8e42a0000 CALL 0x00572ad0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00572ad0u,5701612u); flags=s.arithmetic_flags;
  }
  L0056ffec: { // 0x56ffec: 8a5010 MOV DL,byte ptr [EAX + 0x10]
    s.dx = with_al(s.dx, m.r8((s.ax+0x00000010u)));
  }
  L0056ffef: { // 0x56ffef: 88951b010000 MOV byte ptr [EBP + 0x11b],DL
    m.w8((s.bp+0x0000011bu), (s.dx & 0xffu));
  }
  L0056fff5: { // 0x56fff5: 8b6c244c MOV EBP,dword ptr [ESP + 0x4c]
    s.bp = m.r32((f.sp+0x0000004cu));
  }
  L0056fff9: { // 0x56fff9: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L0056fffa: { // 0x56fffa: 8d4507 LEA EAX,[EBP + 0x7]
    s.ax = (s.bp+0x00000007u);
  }
  L0056fffd: { // 0x56fffd: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L0056ffff: { // 0x56ffff: 7ca8 JL 0x0056ffa9
    if(integer::condition("JL",flags)) goto L0056ffa9;
  }
  L00570001: { // 0x570001: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L00570005: { // 0x570005: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L00570009: { // 0x570009: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L0057000a: { // 0x57000a: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L0057000c: { // 0x57000c: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L00570010: { // 0x570010: 7c91 JL 0x0056ffa3
    if(integer::condition("JL",flags)) goto L0056ffa3;
  }
  L00570012: { // 0x570012: 8b54245c MOV EDX,dword ptr [ESP + 0x5c]
    s.dx = m.r32((f.sp+0x0000005cu));
  }
  L00570016: { // 0x570016: 0fbf0f MOVSX ECX,word ptr [EDI]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.di)),16));
  }
  L00570019: { // 0x570019: 8d4202 LEA EAX,[EDX + 0x2]
    s.ax = (s.dx+0x00000002u);
  }
  L0057001c: { // 0x57001c: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L0057001e: { // 0x57001e: 8944244c MOV dword ptr [ESP + 0x4c],EAX
    m.w32((f.sp+0x0000004cu), s.ax);
  }
  L00570022: { // 0x570022: 0fbf4702 MOVSX EAX,word ptr [EDI + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L00570026: { // 0x570026: 2bc6 SUB EAX,ESI
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L00570028: { // 0x570028: 83c002 ADD EAX,0x2
    s.ax = integer::add(s.ax,0x00000002u,32,flags);
  }
  L0057002b: { // 0x57002b: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0057002c: { // 0x57002c: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L0057002e: { // 0x57002e: 8d5c06ff LEA EBX,[ESI + EAX*0x1 + -0x1]
    s.bx = (s.si+(s.ax * 0x00000001u)-0x00000001u);
  }
  L00570032: { // 0x570032: 896c241c MOV dword ptr [ESP + 0x1c],EBP
    m.w32((f.sp+0x0000001cu), s.bp);
  }
  L00570036: { // 0x570036: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00570038: { // 0x570038: 895c2424 MOV dword ptr [ESP + 0x24],EBX
    m.w32((f.sp+0x00000024u), s.bx);
  }
  L0057003c: { // 0x57003c: 7d71 JGE 0x005700af
    if(integer::condition("JGE",flags)) goto L005700af;
  }
  L0057003e: { // 0x57003e: 8b5c244c MOV EBX,dword ptr [ESP + 0x4c]
    s.bx = m.r32((f.sp+0x0000004cu));
  }
  L00570042: { // 0x570042: 03cb ADD ECX,EBX
    s.cx = integer::add(s.cx,s.bx,32,flags);
  }
  L00570044: { // 0x570044: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L00570048: { // 0x570048: 3b5c2418 CMP EBX,dword ptr [ESP + 0x18]
    (void)integer::sub(s.bx,m.r32((f.sp+0x00000018u)),32,flags);
  }
  L0057004c: { // 0x57004c: 7d54 JGE 0x005700a2
    if(integer::condition("JGE",flags)) goto L005700a2;
  }
  L0057004e: { // 0x57004e: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L00570052: { // 0x570052: 66895c2414 MOV word ptr [ESP + 0x14],BX
    m.w16((f.sp+0x00000014u), (s.bx & 0xffffu));
  }
  L00570057: { // 0x570057: 66896c2416 MOV word ptr [ESP + 0x16],BP
    m.w16((f.sp+0x00000016u), (s.bp & 0xffffu));
  }
  L0057005c: { // 0x57005c: e8afa70100 CALL 0x0058a810
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058a810u,5701729u); flags=s.arithmetic_flags;
  }
  L00570061: { // 0x570061: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00570063: { // 0x570063: 742c JZ 0x00570091
    if(integer::condition("JZ",flags)) goto L00570091;
  }
  L00570065: { // 0x570065: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L00570069: { // 0x570069: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L0057006d: { // 0x57006d: 8b5508 MOV EDX,dword ptr [EBP + 0x8]
    s.dx = m.r32((s.bp+0x00000008u));
  }
  L00570070: { // 0x570070: e8ebb6ffff CALL 0x0056b760
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056b760u,5701749u); flags=s.arithmetic_flags;
  }
  L00570075: { // 0x570075: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L00570079: { // 0x570079: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0057007a: { // 0x57007a: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0057007f: { // 0x57007f: e87c54fdff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5701764u); flags=s.arithmetic_flags;
  }
  L00570084: { // 0x570084: 8a5510 MOV DL,byte ptr [EBP + 0x10]
    s.dx = with_al(s.dx, m.r8((s.bp+0x00000010u)));
  }
  L00570087: { // 0x570087: 8b6c241c MOV EBP,dword ptr [ESP + 0x1c]
    s.bp = m.r32((f.sp+0x0000001cu));
  }
  L0057008b: { // 0x57008b: 88901b010000 MOV byte ptr [EAX + 0x11b],DL
    m.w8((s.ax+0x0000011bu), (s.dx & 0xffu));
  }
  L00570091: { // 0x570091: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00570095: { // 0x570095: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L00570096: { // 0x570096: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L00570098: { // 0x570098: 7cb4 JL 0x0057004e
    if(integer::condition("JL",flags)) goto L0057004e;
  }
  L0057009a: { // 0x57009a: 8b54245c MOV EDX,dword ptr [ESP + 0x5c]
    s.dx = m.r32((f.sp+0x0000005cu));
  }
  L0057009e: { // 0x57009e: 8b5c244c MOV EBX,dword ptr [ESP + 0x4c]
    s.bx = m.r32((f.sp+0x0000004cu));
  }
  L005700a2: { // 0x5700a2: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L005700a6: { // 0x5700a6: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L005700a7: { // 0x5700a7: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L005700a9: { // 0x5700a9: 896c241c MOV dword ptr [ESP + 0x1c],EBP
    m.w32((f.sp+0x0000001cu), s.bp);
  }
  L005700ad: { // 0x5700ad: 7c99 JL 0x00570048
    if(integer::condition("JL",flags)) goto L00570048;
  }
  L005700af: { // 0x5700af: 8b442474 MOV EAX,dword ptr [ESP + 0x74]
    s.ax = m.r32((f.sp+0x00000074u));
  }
  L005700b3: { // 0x5700b3: 8d5a02 LEA EBX,[EDX + 0x2]
    s.bx = (s.dx+0x00000002u);
  }
  L005700b6: { // 0x5700b6: 895c244c MOV dword ptr [ESP + 0x4c],EBX
    m.w32((f.sp+0x0000004cu), s.bx);
  }
  L005700ba: { // 0x5700ba: 0fbf4802 MOVSX ECX,word ptr [EAX + 0x2]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000002u)),16));
  }
  L005700be: { // 0x5700be: 0fbf00 MOVSX EAX,word ptr [EAX]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.ax)),16));
  }
  L005700c1: { // 0x5700c1: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L005700c3: { // 0x5700c3: 8d540efe LEA EDX,[ESI + ECX*0x1 + -0x2]
    s.dx = (s.si+(s.cx * 0x00000001u)-0x00000002u);
  }
  L005700c7: { // 0x5700c7: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L005700c8: { // 0x5700c8: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L005700ca: { // 0x5700ca: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L005700cc: { // 0x5700cc: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L005700d0: { // 0x5700d0: 7d65 JGE 0x00570137
    if(integer::condition("JGE",flags)) goto L00570137;
  }
  L005700d2: { // 0x5700d2: 03c3 ADD EAX,EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L005700d4: { // 0x5700d4: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L005700d8: { // 0x5700d8: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L005700dc: { // 0x5700dc: 8bf3 MOV ESI,EBX
    s.si = s.bx;
  }
  L005700de: { // 0x5700de: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L005700e0: { // 0x5700e0: 7d50 JGE 0x00570132
    if(integer::condition("JGE",flags)) goto L00570132;
  }
  L005700e2: { // 0x5700e2: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L005700e6: { // 0x5700e6: 6689742414 MOV word ptr [ESP + 0x14],SI
    m.w16((f.sp+0x00000014u), (s.si & 0xffffu));
  }
  L005700eb: { // 0x5700eb: 66896c2416 MOV word ptr [ESP + 0x16],BP
    m.w16((f.sp+0x00000016u), (s.bp & 0xffffu));
  }
  L005700f0: { // 0x5700f0: e81ba70100 CALL 0x0058a810
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058a810u,5701877u); flags=s.arithmetic_flags;
  }
  L005700f5: { // 0x5700f5: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005700f7: { // 0x5700f7: 742c JZ 0x00570125
    if(integer::condition("JZ",flags)) goto L00570125;
  }
  L005700f9: { // 0x5700f9: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L005700fd: { // 0x5700fd: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L00570101: { // 0x570101: 8b5308 MOV EDX,dword ptr [EBX + 0x8]
    s.dx = m.r32((s.bx+0x00000008u));
  }
  L00570104: { // 0x570104: e857b6ffff CALL 0x0056b760
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056b760u,5701897u); flags=s.arithmetic_flags;
  }
  L00570109: { // 0x570109: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L0057010d: { // 0x57010d: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00570112: { // 0x570112: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00570113: { // 0x570113: e8e853fdff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5701912u); flags=s.arithmetic_flags;
  }
  L00570118: { // 0x570118: 8a4b10 MOV CL,byte ptr [EBX + 0x10]
    s.cx = with_al(s.cx, m.r8((s.bx+0x00000010u)));
  }
  L0057011b: { // 0x57011b: 8b5c244c MOV EBX,dword ptr [ESP + 0x4c]
    s.bx = m.r32((f.sp+0x0000004cu));
  }
  L0057011f: { // 0x57011f: 88881b010000 MOV byte ptr [EAX + 0x11b],CL
    m.w8((s.ax+0x0000011bu), (s.cx & 0xffu));
  }
  L00570125: { // 0x570125: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L00570129: { // 0x570129: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0057012a: { // 0x57012a: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L0057012c: { // 0x57012c: 7cb4 JL 0x005700e2
    if(integer::condition("JL",flags)) goto L005700e2;
  }
  L0057012e: { // 0x57012e: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L00570132: { // 0x570132: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L00570133: { // 0x570133: 3bea CMP EBP,EDX
    (void)integer::sub(s.bp,s.dx,32,flags);
  }
  L00570135: { // 0x570135: 7ca1 JL 0x005700d8
    if(integer::condition("JL",flags)) goto L005700d8;
  }
  L00570137: { // 0x570137: 668b4702 MOV AX,word ptr [EDI + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.di+0x00000002u)));
  }
  L0057013b: { // 0x57013b: 668b17 MOV DX,word ptr [EDI]
    s.dx = with_ax(s.dx, m.r16((s.di)));
  }
  L0057013e: { // 0x57013e: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L00570142: { // 0x570142: 8b742478 MOV ESI,dword ptr [ESP + 0x78]
    s.si = m.r32((f.sp+0x00000078u));
  }
  L00570146: { // 0x570146: 662d0200 SUB AX,0x2
    s.ax = with_ax(s.ax, integer::sub((s.ax & 0xffffu),0x00000002u,16,flags));
  }
  L0057014a: { // 0x57014a: 668954241c MOV word ptr [ESP + 0x1c],DX
    m.w16((f.sp+0x0000001cu), (s.dx & 0xffffu));
  }
  L0057014f: { // 0x57014f: 8b5310 MOV EDX,dword ptr [EBX + 0x10]
    s.dx = m.r32((s.bx+0x00000010u));
  }
  L00570152: { // 0x570152: 668944241e MOV word ptr [ESP + 0x1e],AX
    m.w16((f.sp+0x0000001eu), (s.ax & 0xffffu));
  }
  L00570157: { // 0x570157: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0057015b: { // 0x57015b: a1705ca500 MOV EAX,[0x00a55c70]
    s.ax = m.r32((0x00a55c70u));
  }
  L00570160: { // 0x570160: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L00570164: { // 0x570164: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00570165: { // 0x570165: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00570166: { // 0x570166: 8d54242c LEA EDX,[ESP + 0x2c]
    s.dx = (f.sp+0x0000002cu);
  }
  L0057016a: { // 0x57016a: 8d4802 LEA ECX,[EAX + 0x2]
    s.cx = (s.ax+0x00000002u);
  }
  L0057016d: { // 0x57016d: e87e500100 CALL 0x005851f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005851f0u,5702002u); flags=s.arithmetic_flags;
  }
  L00570172: { // 0x570172: 8b4b10 MOV ECX,dword ptr [EBX + 0x10]
    s.cx = m.r32((s.bx+0x00000010u));
  }
  L00570175: { // 0x570175: a1705ca500 MOV EAX,[0x00a55c70]
    s.ax = m.r32((0x00a55c70u));
  }
  L0057017a: { // 0x57017a: 8b6c2474 MOV EBP,dword ptr [ESP + 0x74]
    s.bp = m.r32((f.sp+0x00000074u));
  }
  L0057017e: { // 0x57017e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0057017f: { // 0x57017f: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00570180: { // 0x570180: 8bd5 MOV EDX,EBP
    s.dx = s.bp;
  }
  L00570182: { // 0x570182: 8d4803 LEA ECX,[EAX + 0x3]
    s.cx = (s.ax+0x00000003u);
  }
  L00570185: { // 0x570185: e866500100 CALL 0x005851f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005851f0u,5702026u); flags=s.arithmetic_flags;
  }
  L0057018a: { // 0x57018a: 8b742420 MOV ESI,dword ptr [ESP + 0x20]
    s.si = m.r32((f.sp+0x00000020u));
  }
  L0057018e: { // 0x57018e: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00570190: { // 0x570190: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L00570192: { // 0x570192: 66895c2434 MOV word ptr [ESP + 0x34],BX
    m.w16((f.sp+0x00000034u), (s.bx & 0xffffu));
  }
  L00570197: { // 0x570197: 66895c2436 MOV word ptr [ESP + 0x36],BX
    m.w16((f.sp+0x00000036u), (s.bx & 0xffffu));
  }
  L0057019c: { // 0x57019c: 0f84a9010000 JZ 0x0057034b
    if(integer::condition("JZ",flags)) goto L0057034b;
  }
  L005701a2: { // 0x5701a2: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L005701a7: { // 0x5701a7: e834fc0b00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5702060u); flags=s.arithmetic_flags;
  }
  L005701ac: { // 0x5701ac: 8944244c MOV dword ptr [ESP + 0x4c],EAX
    m.w32((f.sp+0x0000004cu), s.ax);
  }
  L005701b0: { // 0x5701b0: 895c2450 MOV dword ptr [ESP + 0x50],EBX
    m.w32((f.sp+0x00000050u), s.bx);
  }
  L005701b4: { // 0x5701b4: df6c244c FILD qword ptr [ESP + 0x4c]
    const auto address=(f.sp+0x0000004cu);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L005701b8: { // 0x5701b8: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L005701be: { // 0x5701be: e88da81f00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5702083u); flags=s.arithmetic_flags;
  }
  L005701c3: { // 0x5701c3: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L005701c6: { // 0x5701c6: 77da JA 0x005701a2
    if(integer::condition("JA",flags)) goto L005701a2;
  }
  L005701c8: { // 0x5701c8: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L005701ca: { // 0x5701ca: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L005701cc: { // 0x5701cc: 0f9fc1 SETG CL
    s.cx = with_al(s.cx, (integer::condition("JG",flags)?1u:0u));
  }
  L005701cf: { // 0x5701cf: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L005701d1: { // 0x5701d1: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L005701d3: { // 0x5701d3: 0f9dc2 SETGE DL
    s.dx = with_al(s.dx, (integer::condition("JGE",flags)?1u:0u));
  }
  L005701d6: { // 0x5701d6: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L005701d7: { // 0x5701d7: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L005701da: { // 0x5701da: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L005701de: { // 0x5701de: 668954242c MOV word ptr [ESP + 0x2c],DX
    m.w16((f.sp+0x0000002cu), (s.dx & 0xffffu));
  }
  L005701e3: { // 0x5701e3: 66895c242e MOV word ptr [ESP + 0x2e],BX
    m.w16((f.sp+0x0000002eu), (s.bx & 0xffffu));
  }
  L005701e8: { // 0x5701e8: 7512 JNZ 0x005701fc
    if(integer::condition("JNZ",flags)) goto L005701fc;
  }
  L005701ea: { // 0x5701ea: 8b442470 MOV EAX,dword ptr [ESP + 0x70]
    s.ax = m.r32((f.sp+0x00000070u));
  }
  L005701ee: { // 0x5701ee: 6689742434 MOV word ptr [ESP + 0x34],SI
    m.w16((f.sp+0x00000034u), (s.si & 0xffffu));
  }
  L005701f3: { // 0x5701f3: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L005701f5: { // 0x5701f5: 6689442436 MOV word ptr [ESP + 0x36],AX
    m.w16((f.sp+0x00000036u), (s.ax & 0xffffu));
  }
  L005701fa: { // 0x5701fa: eb25 JMP 0x00570221
    goto L00570221;
  }
  L005701fc: { // 0x5701fc: 668b4702 MOV AX,word ptr [EDI + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.di+0x00000002u)));
  }
  L00570200: { // 0x570200: 668954242c MOV word ptr [ESP + 0x2c],DX
    m.w16((f.sp+0x0000002cu), (s.dx & 0xffffu));
  }
  L00570205: { // 0x570205: 662b442470 SUB AX,word ptr [ESP + 0x70]
    s.ax = with_ax(s.ax, integer::sub((s.ax & 0xffffu),m.r16((f.sp+0x00000070u)),16,flags));
  }
  L0057020a: { // 0x57020a: 662b4502 SUB AX,word ptr [EBP + 0x2]
    s.ax = with_ax(s.ax, integer::sub((s.ax & 0xffffu),m.r16((s.bp+0x00000002u)),16,flags));
  }
  L0057020e: { // 0x57020e: 83e805 SUB EAX,0x5
    s.ax = integer::sub(s.ax,0x00000005u,32,flags);
  }
  L00570211: { // 0x570211: 6689442446 MOV word ptr [ESP + 0x46],AX
    m.w16((f.sp+0x00000046u), (s.ax & 0xffffu));
  }
  L00570216: { // 0x570216: 8b542446 MOV EDX,dword ptr [ESP + 0x46]
    s.dx = m.r32((f.sp+0x00000046u));
  }
  L0057021a: { // 0x57021a: f7da NEG EDX
    s.dx = integer::sub(0u,s.dx,32,flags);
  }
  L0057021c: { // 0x57021c: 668954242e MOV word ptr [ESP + 0x2e],DX
    m.w16((f.sp+0x0000002eu), (s.dx & 0xffffu));
  }
  L00570221: { // 0x570221: 8b442470 MOV EAX,dword ptr [ESP + 0x70]
    s.ax = m.r32((f.sp+0x00000070u));
  }
  L00570225: { // 0x570225: 895c2414 MOV dword ptr [ESP + 0x14],EBX
    m.w32((f.sp+0x00000014u), s.bx);
  }
  L00570229: { // 0x570229: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0057022b: { // 0x57022b: 0f8e1a010000 JLE 0x0057034b
    if(integer::condition("JLE",flags)) goto L0057034b;
  }
  L00570231: { // 0x570231: 895c2418 MOV dword ptr [ESP + 0x18],EBX
    m.w32((f.sp+0x00000018u), s.bx);
  }
  L00570235: { // 0x570235: eb06 JMP 0x0057023d
    goto L0057023d;
  }
  L00570237: { // 0x570237: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0057023b: { // 0x57023b: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0057023d: { // 0x57023d: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00570241: { // 0x570241: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L00570243: { // 0x570243: 8d1489 LEA EDX,[ECX + ECX*0x4]
    s.dx = (s.cx+(s.cx * 0x00000004u));
  }
  L00570246: { // 0x570246: be00b57c00 MOV ESI,0x7cb500
    s.si = 0x007cb500u;
  }
  L0057024b: { // 0x57024b: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L0057024d: { // 0x57024d: 668944244e MOV word ptr [ESP + 0x4e],AX
    m.w16((f.sp+0x0000004eu), (s.ax & 0xffffu));
  }
  L00570252: { // 0x570252: 8d1c9514b57c00 LEA EBX,[EDX*0x4 + 0x7cb514]
    s.bx = ((s.dx * 0x00000004u)+0x007cb514u);
  }
  L00570259: { // 0x570259: eb04 JMP 0x0057025f
    goto L0057025f;
  }
  L0057025b: { // 0x57025b: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0057025f: { // 0x57025f: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00570261: { // 0x570261: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L00570265: { // 0x570265: 7504 JNZ 0x0057026b
    if(integer::condition("JNZ",flags)) goto L0057026b;
  }
  L00570267: { // 0x570267: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0057026b: { // 0x57026b: 668b5702 MOV DX,word ptr [EDI + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.di+0x00000002u)));
  }
  L0057026f: { // 0x57026f: 668b07 MOV AX,word ptr [EDI]
    s.ax = with_ax(s.ax, m.r16((s.di)));
  }
  L00570272: { // 0x570272: 6683ea03 SUB DX,0x3
    s.dx = with_ax(s.dx, integer::sub((s.dx & 0xffffu),0x00000003u,16,flags));
  }
  L00570276: { // 0x570276: 668944243c MOV word ptr [ESP + 0x3c],AX
    m.w16((f.sp+0x0000003cu), (s.ax & 0xffffu));
  }
  L0057027b: { // 0x57027b: 668954243e MOV word ptr [ESP + 0x3e],DX
    m.w16((f.sp+0x0000003eu), (s.dx & 0xffffu));
  }
  L00570280: { // 0x570280: 8b44243c MOV EAX,dword ptr [ESP + 0x3c]
    s.ax = m.r32((f.sp+0x0000003cu));
  }
  L00570284: { // 0x570284: 8b54243e MOV EDX,dword ptr [ESP + 0x3e]
    s.dx = m.r32((f.sp+0x0000003eu));
  }
  L00570288: { // 0x570288: 03c5 ADD EAX,EBP
    s.ax = integer::add(s.ax,s.bp,32,flags);
  }
  L0057028a: { // 0x57028a: 6689442444 MOV word ptr [ESP + 0x44],AX
    m.w16((f.sp+0x00000044u), (s.ax & 0xffffu));
  }
  L0057028f: { // 0x57028f: 8b44244e MOV EAX,dword ptr [ESP + 0x4e]
    s.ax = m.r32((f.sp+0x0000004eu));
  }
  L00570293: { // 0x570293: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00570295: { // 0x570295: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L00570299: { // 0x570299: 6689542446 MOV word ptr [ESP + 0x46],DX
    m.w16((f.sp+0x00000046u), (s.dx & 0xffffu));
  }
  L0057029e: { // 0x57029e: 8b542444 MOV EDX,dword ptr [ESP + 0x44]
    s.dx = m.r32((f.sp+0x00000044u));
  }
  L005702a2: { // 0x5702a2: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L005702a4: { // 0x5702a4: 8b44242e MOV EAX,dword ptr [ESP + 0x2e]
    s.ax = m.r32((f.sp+0x0000002eu));
  }
  L005702a8: { // 0x5702a8: 6689542420 MOV word ptr [ESP + 0x20],DX
    m.w16((f.sp+0x00000020u), (s.dx & 0xffffu));
  }
  L005702ad: { // 0x5702ad: 8b542446 MOV EDX,dword ptr [ESP + 0x46]
    s.dx = m.r32((f.sp+0x00000046u));
  }
  L005702b1: { // 0x5702b1: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L005702b3: { // 0x5702b3: 6689442422 MOV word ptr [ESP + 0x22],AX
    m.w16((f.sp+0x00000022u), (s.ax & 0xffffu));
  }
  L005702b8: { // 0x5702b8: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L005702bc: { // 0x5702bc: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L005702be: { // 0x5702be: 8d4c2428 LEA ECX,[ESP + 0x28]
    s.cx = (f.sp+0x00000028u);
  }
  L005702c2: { // 0x5702c2: 6689542424 MOV word ptr [ESP + 0x24],DX
    m.w16((f.sp+0x00000024u), (s.dx & 0xffffu));
  }
  L005702c7: { // 0x5702c7: 6689442426 MOV word ptr [ESP + 0x26],AX
    m.w16((f.sp+0x00000026u), (s.ax & 0xffffu));
  }
  L005702cc: { // 0x5702cc: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L005702d0: { // 0x5702d0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005702d1: { // 0x5702d1: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L005702d6: { // 0x5702d6: 8944242c MOV dword ptr [ESP + 0x2c],EAX
    m.w32((f.sp+0x0000002cu), s.ax);
  }
  L005702da: { // 0x5702da: e82152fdff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5702367u); flags=s.arithmetic_flags;
  }
  L005702df: { // 0x5702df: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L005702e3: { // 0x5702e3: 8a16 MOV DL,byte ptr [ESI]
    s.dx = with_al(s.dx, m.r8((s.si)));
  }
  L005702e5: { // 0x5702e5: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  L005702e8: { // 0x5702e8: 83c304 ADD EBX,0x4
    s.bx = integer::add(s.bx,0x00000004u,32,flags);
  }
  L005702eb: { // 0x5702eb: 025110 ADD DL,byte ptr [ECX + 0x10]
    s.dx = with_al(s.dx, integer::add((s.dx & 0xffu),m.r8((s.cx+0x00000010u)),8,flags));
  }
  L005702ee: { // 0x5702ee: 80ea04 SUB DL,0x4
    s.dx = with_al(s.dx, integer::sub((s.dx & 0xffu),0x00000004u,8,flags));
  }
  L005702f1: { // 0x5702f1: 88901b010000 MOV byte ptr [EAX + 0x11b],DL
    m.w8((s.ax+0x0000011bu), (s.dx & 0xffu));
  }
  L005702f7: { // 0x5702f7: 8a4bfc MOV CL,byte ptr [EBX + -0x4]
    s.cx = with_al(s.cx, m.r8((s.bx-0x00000004u)));
  }
  L005702fa: { // 0x5702fa: 88881c010000 MOV byte ptr [EAX + 0x11c],CL
    m.w8((s.ax+0x0000011cu), (s.cx & 0xffu));
  }
  L00570300: { // 0x570300: 8b15505ca500 MOV EDX,dword ptr [0x00a55c50]
    s.dx = m.r32((0x00a55c50u));
  }
  L00570306: { // 0x570306: 81e1ff000000 AND ECX,0xff
    s.cx = integer::logical((s.cx)&(0x000000ffu),32,flags);
  }
  L0057030c: { // 0x57030c: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L0057030d: { // 0x57030d: 81fe14b57c00 CMP ESI,0x7cb514
    (void)integer::sub(s.si,0x007cb514u,32,flags);
  }
  L00570313: { // 0x570313: c6801a01000000 MOV byte ptr [EAX + 0x11a],0x0
    m.w8((s.ax+0x0000011au), 0x00000000u);
  }
  L0057031a: { // 0x57031a: 8d4c11ff LEA ECX,[ECX + EDX*0x1 + -0x1]
    s.cx = (s.cx+(s.dx * 0x00000001u)-0x00000001u);
  }
  L0057031e: { // 0x57031e: 894838 MOV dword ptr [EAX + 0x38],ECX
    m.w32((s.ax+0x00000038u), s.cx);
  }
  L00570321: { // 0x570321: 0f8c34ffffff JL 0x0057025b
    if(integer::condition("JL",flags)) goto L0057025b;
  }
  L00570327: { // 0x570327: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0057032b: { // 0x57032b: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0057032f: { // 0x57032f: 8b4c2470 MOV ECX,dword ptr [ESP + 0x70]
    s.cx = m.r32((f.sp+0x00000070u));
  }
  L00570333: { // 0x570333: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00570334: { // 0x570334: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L00570335: { // 0x570335: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00570337: { // 0x570337: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L0057033b: { // 0x57033b: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L0057033f: { // 0x57033f: 0f8cf2feffff JL 0x00570237
    if(integer::condition("JL",flags)) goto L00570237;
  }
  L00570345: { // 0x570345: 8b6c2474 MOV EBP,dword ptr [ESP + 0x74]
    s.bp = m.r32((f.sp+0x00000074u));
  }
  L00570349: { // 0x570349: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0057034b: { // 0x57034b: 0fbf5702 MOVSX EDX,word ptr [EDI + 0x2]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L0057034f: { // 0x57034f: 0fbf4502 MOVSX EAX,word ptr [EBP + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.bp+0x00000002u)),16));
  }
  L00570353: { // 0x570353: 8b742470 MOV ESI,dword ptr [ESP + 0x70]
    s.si = m.r32((f.sp+0x00000070u));
  }
  L00570357: { // 0x570357: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L00570359: { // 0x570359: 2bd6 SUB EDX,ESI
    s.dx = integer::sub(s.dx,s.si,32,flags);
  }
  L0057035b: { // 0x57035b: 895c2418 MOV dword ptr [ESP + 0x18],EBX
    m.w32((f.sp+0x00000018u), s.bx);
  }
  L0057035f: { // 0x57035f: 83ea05 SUB EDX,0x5
    s.dx = integer::sub(s.dx,0x00000005u,32,flags);
  }
  L00570362: { // 0x570362: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00570364: { // 0x570364: 0f8ef8000000 JLE 0x00570462
    if(integer::condition("JLE",flags)) goto L00570462;
  }
  L0057036a: { // 0x57036a: 8b6c2436 MOV EBP,dword ptr [ESP + 0x36]
    s.bp = m.r32((f.sp+0x00000036u));
  }
  L0057036e: { // 0x57036e: eb02 JMP 0x00570372
    goto L00570372;
  }
  L00570370: { // 0x570370: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00570372: { // 0x570372: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L00570376: { // 0x570376: f7d9 NEG ECX
    s.cx = integer::sub(0u,s.cx,32,flags);
  }
  L00570378: { // 0x570378: 66894c244e MOV word ptr [ESP + 0x4e],CX
    m.w16((f.sp+0x0000004eu), (s.cx & 0xffffu));
  }
  L0057037d: { // 0x57037d: 8b74244e MOV ESI,dword ptr [ESP + 0x4e]
    s.si = m.r32((f.sp+0x0000004eu));
  }
  L00570381: { // 0x570381: 668b4702 MOV AX,word ptr [EDI + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.di+0x00000002u)));
  }
  L00570385: { // 0x570385: 668b17 MOV DX,word ptr [EDI]
    s.dx = with_ax(s.dx, m.r16((s.di)));
  }
  L00570388: { // 0x570388: 662d0300 SUB AX,0x3
    s.ax = with_ax(s.ax, integer::sub((s.ax & 0xffffu),0x00000003u,16,flags));
  }
  L0057038c: { // 0x57038c: 6689542444 MOV word ptr [ESP + 0x44],DX
    m.w16((f.sp+0x00000044u), (s.dx & 0xffffu));
  }
  L00570391: { // 0x570391: 6689442446 MOV word ptr [ESP + 0x46],AX
    m.w16((f.sp+0x00000046u), (s.ax & 0xffffu));
  }
  L00570396: { // 0x570396: 8b4c2444 MOV ECX,dword ptr [ESP + 0x44]
    s.cx = m.r32((f.sp+0x00000044u));
  }
  L0057039a: { // 0x57039a: 8b542446 MOV EDX,dword ptr [ESP + 0x46]
    s.dx = m.r32((f.sp+0x00000046u));
  }
  L0057039e: { // 0x57039e: 03cb ADD ECX,EBX
    s.cx = integer::add(s.cx,s.bx,32,flags);
  }
  L005703a0: { // 0x5703a0: 03d6 ADD EDX,ESI
    s.dx = integer::add(s.dx,s.si,32,flags);
  }
  L005703a2: { // 0x5703a2: 66894c243c MOV word ptr [ESP + 0x3c],CX
    m.w16((f.sp+0x0000003cu), (s.cx & 0xffffu));
  }
  L005703a7: { // 0x5703a7: 8b4c2434 MOV ECX,dword ptr [ESP + 0x34]
    s.cx = m.r32((f.sp+0x00000034u));
  }
  L005703ab: { // 0x5703ab: 668954243e MOV word ptr [ESP + 0x3e],DX
    m.w16((f.sp+0x0000003eu), (s.dx & 0xffffu));
  }
  L005703b0: { // 0x5703b0: 8b44243c MOV EAX,dword ptr [ESP + 0x3c]
    s.ax = m.r32((f.sp+0x0000003cu));
  }
  L005703b4: { // 0x5703b4: 8b54243e MOV EDX,dword ptr [ESP + 0x3e]
    s.dx = m.r32((f.sp+0x0000003eu));
  }
  L005703b8: { // 0x5703b8: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L005703ba: { // 0x5703ba: 8d042a LEA EAX,[EDX + EBP*0x1]
    s.ax = (s.dx+(s.bp * 0x00000001u));
  }
  L005703bd: { // 0x5703bd: 66894c2424 MOV word ptr [ESP + 0x24],CX
    m.w16((f.sp+0x00000024u), (s.cx & 0xffffu));
  }
  L005703c2: { // 0x5703c2: 6689442426 MOV word ptr [ESP + 0x26],AX
    m.w16((f.sp+0x00000026u), (s.ax & 0xffffu));
  }
  L005703c7: { // 0x5703c7: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L005703cb: { // 0x5703cb: 89542428 MOV dword ptr [ESP + 0x28],EDX
    m.w32((f.sp+0x00000028u), s.dx);
  }
  L005703cf: { // 0x5703cf: 8b153c86a500 MOV EDX,dword ptr [0x00a5863c]
    s.dx = m.r32((0x00a5863cu));
  }
  L005703d5: { // 0x5703d5: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L005703d7: { // 0x5703d7: 741d JZ 0x005703f6
    if(integer::condition("JZ",flags)) goto L005703f6;
  }
  L005703d9: { // 0x5703d9: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L005703dc: { // 0x5703dc: 0faf054c6b8300 IMUL EAX,dword ptr [0x00836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  L005703e3: { // 0x5703e3: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L005703e6: { // 0x5703e6: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L005703e8: { // 0x5703e8: 8b4c2478 MOV ECX,dword ptr [ESP + 0x78]
    s.cx = m.r32((f.sp+0x00000078u));
  }
  L005703ec: { // 0x5703ec: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L005703ef: { // 0x5703ef: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L005703f2: { // 0x5703f2: 894c1038 MOV dword ptr [EAX + EDX*0x1 + 0x38],ECX
    m.w32((s.ax+(s.dx * 0x00000001u)+0x00000038u), s.cx);
  }
  L005703f6: { // 0x5703f6: 8d542428 LEA EDX,[ESP + 0x28]
    s.dx = (f.sp+0x00000028u);
  }
  L005703fa: { // 0x5703fa: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L005703ff: { // 0x5703ff: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00570400: { // 0x570400: e8fb50fdff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5702661u); flags=s.arithmetic_flags;
  }
  L00570405: { // 0x570405: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00570409: { // 0x570409: 8a5110 MOV DL,byte ptr [ECX + 0x10]
    s.dx = with_al(s.dx, m.r8((s.cx+0x00000010u)));
  }
  L0057040c: { // 0x57040c: c6801c01000003 MOV byte ptr [EAX + 0x11c],0x3
    m.w8((s.ax+0x0000011cu), 0x00000003u);
  }
  L00570413: { // 0x570413: 2ad3 SUB DL,BL
    s.dx = with_al(s.dx, integer::sub((s.dx & 0xffu),(s.bx & 0xffu),8,flags));
  }
  L00570415: { // 0x570415: feca DEC DL
    s.dx = with_al(s.dx, integer::decrement((s.dx & 0xffu),8,flags));
  }
  L00570417: { // 0x570417: 88901b010000 MOV byte ptr [EAX + 0x11b],DL
    m.w8((s.ax+0x0000011bu), (s.dx & 0xffu));
  }
  L0057041d: { // 0x57041d: 8b0d505ca500 MOV ECX,dword ptr [0x00a55c50]
    s.cx = m.r32((0x00a55c50u));
  }
  L00570423: { // 0x570423: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L00570426: { // 0x570426: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L00570427: { // 0x570427: 83fb04 CMP EBX,0x4
    (void)integer::sub(s.bx,0x00000004u,32,flags);
  }
  L0057042a: { // 0x57042a: 894838 MOV dword ptr [EAX + 0x38],ECX
    m.w32((s.ax+0x00000038u), s.cx);
  }
  L0057042d: { // 0x57042d: c6801a01000000 MOV byte ptr [EAX + 0x11a],0x0
    m.w8((s.ax+0x0000011au), 0x00000000u);
  }
  L00570434: { // 0x570434: 0f8c47ffffff JL 0x00570381
    if(integer::condition("JL",flags)) goto L00570381;
  }
  L0057043a: { // 0x57043a: 8b4c2474 MOV ECX,dword ptr [ESP + 0x74]
    s.cx = m.r32((f.sp+0x00000074u));
  }
  L0057043e: { // 0x57043e: 8b5c2470 MOV EBX,dword ptr [ESP + 0x70]
    s.bx = m.r32((f.sp+0x00000070u));
  }
  L00570442: { // 0x570442: 0fbf5702 MOVSX EDX,word ptr [EDI + 0x2]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L00570446: { // 0x570446: 0fbf4902 MOVSX ECX,word ptr [ECX + 0x2]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000002u)),16));
  }
  L0057044a: { // 0x57044a: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0057044e: { // 0x57044e: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L00570450: { // 0x570450: 2bd3 SUB EDX,EBX
    s.dx = integer::sub(s.dx,s.bx,32,flags);
  }
  L00570452: { // 0x570452: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00570453: { // 0x570453: 83ea05 SUB EDX,0x5
    s.dx = integer::sub(s.dx,0x00000005u,32,flags);
  }
  L00570456: { // 0x570456: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0057045a: { // 0x57045a: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0057045c: { // 0x57045c: 0f8c0effffff JL 0x00570370
    if(integer::condition("JL",flags)) goto L00570370;
  }
  L00570462: { // 0x570462: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00570463: { // 0x570463: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00570464: { // 0x570464: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00570465: { // 0x570465: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00570467: { // 0x570467: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00570468: { // 0x570468: 83c45c ADD ESP,0x5c
    f.sp = integer::add(f.sp,0x0000005cu,32,flags);
  }
  L0057046b: { // 0x57046b: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00570470(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00570470: { // 0x570470: 83ec64 SUB ESP,0x64
    f.sp = integer::sub(f.sp,0x00000064u,32,flags);
  }
  L00570473: { // 0x570473: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00570474: { // 0x570474: 8b5c246c MOV EBX,dword ptr [ESP + 0x6c]
    s.bx = m.r32((f.sp+0x0000006cu));
  }
  L00570478: { // 0x570478: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00570479: { // 0x570479: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0057047a: { // 0x57047a: 668b4302 MOV AX,word ptr [EBX + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.bx+0x00000002u)));
  }
  L0057047e: { // 0x57047e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0057047f: { // 0x57047f: 8b7c247c MOV EDI,dword ptr [ESP + 0x7c]
    s.di = m.r32((f.sp+0x0000007cu));
  }
  L00570483: { // 0x570483: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L00570487: { // 0x570487: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L00570489: { // 0x570489: 668b5702 MOV DX,word ptr [EDI + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.di+0x00000002u)));
  }
  L0057048d: { // 0x57048d: 663bc2 CMP AX,DX
    (void)integer::sub((s.ax & 0xffffu),(s.dx & 0xffffu),16,flags);
  }
  L00570490: { // 0x570490: 7f02 JG 0x00570494
    if(integer::condition("JG",flags)) goto L00570494;
  }
  L00570492: { // 0x570492: 8bea MOV EBP,EDX
    s.bp = s.dx;
  }
  L00570494: { // 0x570494: 663bc2 CMP AX,DX
    (void)integer::sub((s.ax & 0xffffu),(s.dx & 0xffffu),16,flags);
  }
  L00570497: { // 0x570497: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00570499: { // 0x570499: 7c02 JL 0x0057049d
    if(integer::condition("JL",flags)) goto L0057049d;
  }
  L0057049b: { // 0x57049b: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L0057049d: { // 0x57049d: 663bc2 CMP AX,DX
    (void)integer::sub((s.ax & 0xffffu),(s.dx & 0xffffu),16,flags);
  }
  L005704a0: { // 0x5704a0: 7d02 JGE 0x005704a4
    if(integer::condition("JGE",flags)) goto L005704a4;
  }
  L005704a2: { // 0x5704a2: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L005704a4: { // 0x5704a4: 0fbf07 MOVSX EAX,word ptr [EDI]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di)),16));
  }
  L005704a7: { // 0x5704a7: 0fbfd2 MOVSX EDX,DX
    s.dx = std::uint32_t(integer::sign_extend((s.dx & 0xffffu),16));
  }
  L005704aa: { // 0x5704aa: 8d48fc LEA ECX,[EAX + -0x4]
    s.cx = (s.ax-0x00000004u);
  }
  L005704ad: { // 0x5704ad: 83ea07 SUB EDX,0x7
    s.dx = integer::sub(s.dx,0x00000007u,32,flags);
  }
  L005704b0: { // 0x5704b0: 894c2464 MOV dword ptr [ESP + 0x64],ECX
    m.w32((f.sp+0x00000064u), s.cx);
  }
  L005704b4: { // 0x5704b4: 89542468 MOV dword ptr [ESP + 0x68],EDX
    m.w32((f.sp+0x00000068u), s.dx);
  }
  L005704b8: { // 0x5704b8: 0fbf0b MOVSX ECX,word ptr [EBX]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.bx)),16));
  }
  L005704bb: { // 0x5704bb: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L005704bd: { // 0x5704bd: 0fbfd6 MOVSX EDX,SI
    s.dx = std::uint32_t(integer::sign_extend((s.si & 0xffffu),16));
  }
  L005704c0: { // 0x5704c0: 0fbfc5 MOVSX EAX,BP
    s.ax = std::uint32_t(integer::sign_extend((s.bp & 0xffffu),16));
  }
  L005704c3: { // 0x5704c3: 83c108 ADD ECX,0x8
    s.cx = integer::add(s.cx,0x00000008u,32,flags);
  }
  L005704c6: { // 0x5704c6: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L005704c8: { // 0x5704c8: 894c246c MOV dword ptr [ESP + 0x6c],ECX
    m.w32((f.sp+0x0000006cu), s.cx);
  }
  L005704cc: { // 0x5704cc: 8b8c2480000000 MOV ECX,dword ptr [ESP + 0x80]
    s.cx = m.r32((f.sp+0x00000080u));
  }
  L005704d3: { // 0x5704d3: 8d542464 LEA EDX,[ESP + 0x64]
    s.dx = (f.sp+0x00000064u);
  }
  L005704d7: { // 0x5704d7: 83c00b ADD EAX,0xb
    s.ax = integer::add(s.ax,0x0000000bu,32,flags);
  }
  L005704da: { // 0x5704da: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005704db: { // 0x5704db: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L005704df: { // 0x5704df: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005704e0: { // 0x5704e0: 89442478 MOV dword ptr [ESP + 0x78],EAX
    m.w32((f.sp+0x00000078u), s.ax);
  }
  L005704e4: { // 0x5704e4: e817220000 CALL 0x00572700
    s.arithmetic_flags=flags; invoke(m,s,f,0x00572700u,5702889u); flags=s.arithmetic_flags;
  }
  L005704e9: { // 0x5704e9: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005704eb: { // 0x5704eb: 750a JNZ 0x005704f7
    if(integer::condition("JNZ",flags)) goto L005704f7;
  }
  L005704ed: { // 0x5704ed: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005704ee: { // 0x5704ee: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005704ef: { // 0x5704ef: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005704f0: { // 0x5704f0: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005704f1: { // 0x5704f1: 83c464 ADD ESP,0x64
    f.sp = integer::add(f.sp,0x00000064u,32,flags);
  }
  L005704f4: { // 0x5704f4: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005704f7: { // 0x5704f7: 0fbf4f02 MOVSX ECX,word ptr [EDI + 0x2]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L005704fb: { // 0x5704fb: 0fbf5302 MOVSX EDX,word ptr [EBX + 0x2]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.bx+0x00000002u)),16));
  }
  L005704ff: { // 0x5704ff: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00570501: { // 0x570501: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00570503: { // 0x570503: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L00570507: { // 0x570507: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00570508: { // 0x570508: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L0057050a: { // 0x57050a: 0fbf03 MOVSX EAX,word ptr [EBX]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.bx)),16));
  }
  L0057050d: { // 0x57050d: 33ea XOR EBP,EDX
    s.bp = integer::logical((s.bp)^(s.dx),32,flags);
  }
  L0057050f: { // 0x57050f: 2bea SUB EBP,EDX
    s.bp = integer::sub(s.bp,s.dx,32,flags);
  }
  L00570511: { // 0x570511: 0fbf17 MOVSX EDX,word ptr [EDI]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.di)),16));
  }
  L00570514: { // 0x570514: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00570516: { // 0x570516: 896c247c MOV dword ptr [ESP + 0x7c],EBP
    m.w32((f.sp+0x0000007cu), s.bp);
  }
  L0057051a: { // 0x57051a: 8d50fb LEA EDX,[EAX + -0x5]
    s.dx = (s.ax-0x00000005u);
  }
  L0057051d: { // 0x57051d: 3bea CMP EBP,EDX
    (void)integer::sub(s.bp,s.dx,32,flags);
  }
  L0057051f: { // 0x57051f: 7e0c JLE 0x0057052d
    if(integer::condition("JLE",flags)) goto L0057052d;
  }
  L00570521: { // 0x570521: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00570522: { // 0x570522: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00570523: { // 0x570523: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00570524: { // 0x570524: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00570526: { // 0x570526: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00570527: { // 0x570527: 83c464 ADD ESP,0x64
    f.sp = integer::add(f.sp,0x00000064u,32,flags);
  }
  L0057052a: { // 0x57052a: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0057052d: { // 0x57052d: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0057052e: { // 0x57052e: 8b742464 MOV ESI,dword ptr [ESP + 0x64]
    s.si = m.r32((f.sp+0x00000064u));
  }
  L00570532: { // 0x570532: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00570533: { // 0x570533: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00570535: { // 0x570535: 89742454 MOV dword ptr [ESP + 0x54],ESI
    m.w32((f.sp+0x00000054u), s.si);
  }
  L00570539: { // 0x570539: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L0057053b: { // 0x57053b: 8b442468 MOV EAX,dword ptr [ESP + 0x68]
    s.ax = m.r32((f.sp+0x00000068u));
  }
  L0057053f: { // 0x57053f: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00570541: { // 0x570541: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00570545: { // 0x570545: d1fd SAR EBP,0x1
    s.bp = integer::shift(s.bp,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00570547: { // 0x570547: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00570549: { // 0x570549: 83c503 ADD EBP,0x3
    s.bp = integer::add(s.bp,0x00000003u,32,flags);
  }
  L0057054c: { // 0x57054c: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0057054e: { // 0x57054e: 896c2428 MOV dword ptr [ESP + 0x28],EBP
    m.w32((f.sp+0x00000028u), s.bp);
  }
  L00570552: { // 0x570552: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L00570556: { // 0x570556: 0f8d88000000 JGE 0x005705e4
    if(integer::condition("JGE",flags)) goto L005705e4;
  }
  L0057055c: { // 0x57055c: 8d4c2e02 LEA ECX,[ESI + EBP*0x1 + 0x2]
    s.cx = (s.si+(s.bp * 0x00000001u)+0x00000002u);
  }
  L00570560: { // 0x570560: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L00570564: { // 0x570564: 3b74241c CMP ESI,dword ptr [ESP + 0x1c]
    (void)integer::sub(s.si,m.r32((f.sp+0x0000001cu)),32,flags);
  }
  L00570568: { // 0x570568: 7d69 JGE 0x005705d3
    if(integer::condition("JGE",flags)) goto L005705d3;
  }
  L0057056a: { // 0x57056a: 668b542418 MOV DX,word ptr [ESP + 0x18]
    s.dx = with_ax(s.dx, m.r16((f.sp+0x00000018u)));
  }
  L0057056f: { // 0x57056f: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L00570573: { // 0x570573: 6689742414 MOV word ptr [ESP + 0x14],SI
    m.w16((f.sp+0x00000014u), (s.si & 0xffffu));
  }
  L00570578: { // 0x570578: 6689542416 MOV word ptr [ESP + 0x16],DX
    m.w16((f.sp+0x00000016u), (s.dx & 0xffffu));
  }
  L0057057d: { // 0x57057d: e88ea20100 CALL 0x0058a810
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058a810u,5703042u); flags=s.arithmetic_flags;
  }
  L00570582: { // 0x570582: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00570584: { // 0x570584: 743c JZ 0x005705c2
    if(integer::condition("JZ",flags)) goto L005705c2;
  }
  L00570586: { // 0x570586: 8b942480000000 MOV EDX,dword ptr [ESP + 0x80]
    s.dx = m.r32((f.sp+0x00000080u));
  }
  L0057058d: { // 0x57058d: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L00570591: { // 0x570591: e8cab1ffff CALL 0x0056b760
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056b760u,5703062u); flags=s.arithmetic_flags;
  }
  L00570596: { // 0x570596: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L0057059a: { // 0x57059a: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0057059f: { // 0x57059f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005705a0: { // 0x5705a0: e85b4ffdff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5703077u); flags=s.arithmetic_flags;
  }
  L005705a5: { // 0x5705a5: 8b8c2480000000 MOV ECX,dword ptr [ESP + 0x80]
    s.cx = m.r32((f.sp+0x00000080u));
  }
  L005705ac: { // 0x5705ac: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L005705b0: { // 0x5705b0: e81b250000 CALL 0x00572ad0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00572ad0u,5703093u); flags=s.arithmetic_flags;
  }
  L005705b5: { // 0x5705b5: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L005705b9: { // 0x5705b9: 8a4810 MOV CL,byte ptr [EAX + 0x10]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000010u)));
  }
  L005705bc: { // 0x5705bc: 888a1b010000 MOV byte ptr [EDX + 0x11b],CL
    m.w8((s.dx+0x0000011bu), (s.cx & 0xffu));
  }
  L005705c2: { // 0x5705c2: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L005705c6: { // 0x5705c6: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L005705c7: { // 0x5705c7: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L005705c9: { // 0x5705c9: 7c9f JL 0x0057056a
    if(integer::condition("JL",flags)) goto L0057056a;
  }
  L005705cb: { // 0x5705cb: 8b442468 MOV EAX,dword ptr [ESP + 0x68]
    s.ax = m.r32((f.sp+0x00000068u));
  }
  L005705cf: { // 0x5705cf: 8b742454 MOV ESI,dword ptr [ESP + 0x54]
    s.si = m.r32((f.sp+0x00000054u));
  }
  L005705d3: { // 0x5705d3: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L005705d7: { // 0x5705d7: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L005705db: { // 0x5705db: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L005705dc: { // 0x5705dc: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L005705de: { // 0x5705de: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L005705e2: { // 0x5705e2: 7c80 JL 0x00570564
    if(integer::condition("JL",flags)) goto L00570564;
  }
  L005705e4: { // 0x5705e4: 0fbf4b02 MOVSX ECX,word ptr [EBX + 0x2]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.bx+0x00000002u)),16));
  }
  L005705e8: { // 0x5705e8: 0fbf33 MOVSX ESI,word ptr [EBX]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.bx)),16));
  }
  L005705eb: { // 0x5705eb: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L005705ed: { // 0x5705ed: 2bf5 SUB ESI,EBP
    s.si = integer::sub(s.si,s.bp,32,flags);
  }
  L005705ef: { // 0x5705ef: 83c602 ADD ESI,0x2
    s.si = integer::add(s.si,0x00000002u,32,flags);
  }
  L005705f2: { // 0x5705f2: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L005705f6: { // 0x5705f6: 8d1401 LEA EDX,[ECX + EAX*0x1]
    s.dx = (s.cx+(s.ax * 0x00000001u));
  }
  L005705f9: { // 0x5705f9: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L005705fb: { // 0x5705fb: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L005705ff: { // 0x5705ff: 0f8d82000000 JGE 0x00570687
    if(integer::condition("JGE",flags)) goto L00570687;
  }
  L00570605: { // 0x570605: 8d4c2e03 LEA ECX,[ESI + EBP*0x1 + 0x3]
    s.cx = (s.si+(s.bp * 0x00000001u)+0x00000003u);
  }
  L00570609: { // 0x570609: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L0057060b: { // 0x57060b: 8bde MOV EBX,ESI
    s.bx = s.si;
  }
  L0057060d: { // 0x57060d: 7d67 JGE 0x00570676
    if(integer::condition("JGE",flags)) goto L00570676;
  }
  L0057060f: { // 0x57060f: 668b442418 MOV AX,word ptr [ESP + 0x18]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x00000018u)));
  }
  L00570614: { // 0x570614: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L00570618: { // 0x570618: 66895c2414 MOV word ptr [ESP + 0x14],BX
    m.w16((f.sp+0x00000014u), (s.bx & 0xffffu));
  }
  L0057061d: { // 0x57061d: 6689442416 MOV word ptr [ESP + 0x16],AX
    m.w16((f.sp+0x00000016u), (s.ax & 0xffffu));
  }
  L00570622: { // 0x570622: e8e9a10100 CALL 0x0058a810
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058a810u,5703207u); flags=s.arithmetic_flags;
  }
  L00570627: { // 0x570627: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00570629: { // 0x570629: 743a JZ 0x00570665
    if(integer::condition("JZ",flags)) goto L00570665;
  }
  L0057062b: { // 0x57062b: 8b942480000000 MOV EDX,dword ptr [ESP + 0x80]
    s.dx = m.r32((f.sp+0x00000080u));
  }
  L00570632: { // 0x570632: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L00570636: { // 0x570636: e825b1ffff CALL 0x0056b760
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056b760u,5703227u); flags=s.arithmetic_flags;
  }
  L0057063b: { // 0x57063b: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L0057063f: { // 0x57063f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00570640: { // 0x570640: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00570645: { // 0x570645: e8b64efdff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5703242u); flags=s.arithmetic_flags;
  }
  L0057064a: { // 0x57064a: 8b8c2480000000 MOV ECX,dword ptr [ESP + 0x80]
    s.cx = m.r32((f.sp+0x00000080u));
  }
  L00570651: { // 0x570651: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L00570653: { // 0x570653: e878240000 CALL 0x00572ad0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00572ad0u,5703256u); flags=s.arithmetic_flags;
  }
  L00570658: { // 0x570658: 8a5010 MOV DL,byte ptr [EAX + 0x10]
    s.dx = with_al(s.dx, m.r8((s.ax+0x00000010u)));
  }
  L0057065b: { // 0x57065b: 88951b010000 MOV byte ptr [EBP + 0x11b],DL
    m.w8((s.bp+0x0000011bu), (s.dx & 0xffu));
  }
  L00570661: { // 0x570661: 8b6c2428 MOV EBP,dword ptr [ESP + 0x28]
    s.bp = m.r32((f.sp+0x00000028u));
  }
  L00570665: { // 0x570665: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L00570666: { // 0x570666: 8d4c2e03 LEA ECX,[ESI + EBP*0x1 + 0x3]
    s.cx = (s.si+(s.bp * 0x00000001u)+0x00000003u);
  }
  L0057066a: { // 0x57066a: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L0057066c: { // 0x57066c: 7ca1 JL 0x0057060f
    if(integer::condition("JL",flags)) goto L0057060f;
  }
  L0057066e: { // 0x57066e: 8b442468 MOV EAX,dword ptr [ESP + 0x68]
    s.ax = m.r32((f.sp+0x00000068u));
  }
  L00570672: { // 0x570672: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L00570676: { // 0x570676: 8b5c2418 MOV EBX,dword ptr [ESP + 0x18]
    s.bx = m.r32((f.sp+0x00000018u));
  }
  L0057067a: { // 0x57067a: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L0057067b: { // 0x57067b: 3bda CMP EBX,EDX
    (void)integer::sub(s.bx,s.dx,32,flags);
  }
  L0057067d: { // 0x57067d: 895c2418 MOV dword ptr [ESP + 0x18],EBX
    m.w32((f.sp+0x00000018u), s.bx);
  }
  L00570681: { // 0x570681: 7c86 JL 0x00570609
    if(integer::condition("JL",flags)) goto L00570609;
  }
  L00570683: { // 0x570683: 8b5c2478 MOV EBX,dword ptr [ESP + 0x78]
    s.bx = m.r32((f.sp+0x00000078u));
  }
  L00570687: { // 0x570687: 0fbf0f MOVSX ECX,word ptr [EDI]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.di)),16));
  }
  L0057068a: { // 0x57068a: 8b542470 MOV EDX,dword ptr [ESP + 0x70]
    s.dx = m.r32((f.sp+0x00000070u));
  }
  L0057068e: { // 0x57068e: 894c2454 MOV dword ptr [ESP + 0x54],ECX
    m.w32((f.sp+0x00000054u), s.cx);
  }
  L00570692: { // 0x570692: 0fbf4f02 MOVSX ECX,word ptr [EDI + 0x2]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L00570696: { // 0x570696: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L00570698: { // 0x570698: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0057069c: { // 0x57069c: 2bf1 SUB ESI,ECX
    s.si = integer::sub(s.si,s.cx,32,flags);
  }
  L0057069e: { // 0x57069e: 8d7406fe LEA ESI,[ESI + EAX*0x1 + -0x2]
    s.si = (s.si+(s.ax * 0x00000001u)-0x00000002u);
  }
  L005706a2: { // 0x5706a2: 03f1 ADD ESI,ECX
    s.si = integer::add(s.si,s.cx,32,flags);
  }
  L005706a4: { // 0x5706a4: 3bce CMP ECX,ESI
    (void)integer::sub(s.cx,s.si,32,flags);
  }
  L005706a6: { // 0x5706a6: 89742428 MOV dword ptr [ESP + 0x28],ESI
    m.w32((f.sp+0x00000028u), s.si);
  }
  L005706aa: { // 0x5706aa: 7d7a JGE 0x00570726
    if(integer::condition("JGE",flags)) goto L00570726;
  }
  L005706ac: { // 0x5706ac: 8b5c2454 MOV EBX,dword ptr [ESP + 0x54]
    s.bx = m.r32((f.sp+0x00000054u));
  }
  L005706b0: { // 0x5706b0: 8d4c2bfe LEA ECX,[EBX + EBP*0x1 + -0x2]
    s.cx = (s.bx+(s.bp * 0x00000001u)-0x00000002u);
  }
  L005706b4: { // 0x5706b4: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L005706b6: { // 0x5706b6: 8bf3 MOV ESI,EBX
    s.si = s.bx;
  }
  L005706b8: { // 0x5706b8: 7d59 JGE 0x00570713
    if(integer::condition("JGE",flags)) goto L00570713;
  }
  L005706ba: { // 0x5706ba: 668b542418 MOV DX,word ptr [ESP + 0x18]
    s.dx = with_ax(s.dx, m.r16((f.sp+0x00000018u)));
  }
  L005706bf: { // 0x5706bf: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L005706c3: { // 0x5706c3: 6689742414 MOV word ptr [ESP + 0x14],SI
    m.w16((f.sp+0x00000014u), (s.si & 0xffffu));
  }
  L005706c8: { // 0x5706c8: 6689542416 MOV word ptr [ESP + 0x16],DX
    m.w16((f.sp+0x00000016u), (s.dx & 0xffffu));
  }
  L005706cd: { // 0x5706cd: e83ea10100 CALL 0x0058a810
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058a810u,5703378u); flags=s.arithmetic_flags;
  }
  L005706d2: { // 0x5706d2: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005706d4: { // 0x5706d4: 742c JZ 0x00570702
    if(integer::condition("JZ",flags)) goto L00570702;
  }
  L005706d6: { // 0x5706d6: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L005706da: { // 0x5706da: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L005706de: { // 0x5706de: 8b5308 MOV EDX,dword ptr [EBX + 0x8]
    s.dx = m.r32((s.bx+0x00000008u));
  }
  L005706e1: { // 0x5706e1: e87ab0ffff CALL 0x0056b760
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056b760u,5703398u); flags=s.arithmetic_flags;
  }
  L005706e6: { // 0x5706e6: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L005706ea: { // 0x5706ea: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L005706ef: { // 0x5706ef: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005706f0: { // 0x5706f0: e80b4efdff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5703413u); flags=s.arithmetic_flags;
  }
  L005706f5: { // 0x5706f5: 8a4b10 MOV CL,byte ptr [EBX + 0x10]
    s.cx = with_al(s.cx, m.r8((s.bx+0x00000010u)));
  }
  L005706f8: { // 0x5706f8: 8b5c2454 MOV EBX,dword ptr [ESP + 0x54]
    s.bx = m.r32((f.sp+0x00000054u));
  }
  L005706fc: { // 0x5706fc: 88881b010000 MOV byte ptr [EAX + 0x11b],CL
    m.w8((s.ax+0x0000011bu), (s.cx & 0xffu));
  }
  L00570702: { // 0x570702: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L00570703: { // 0x570703: 8d4c2bfe LEA ECX,[EBX + EBP*0x1 + -0x2]
    s.cx = (s.bx+(s.bp * 0x00000001u)-0x00000002u);
  }
  L00570707: { // 0x570707: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L00570709: { // 0x570709: 7caf JL 0x005706ba
    if(integer::condition("JL",flags)) goto L005706ba;
  }
  L0057070b: { // 0x57070b: 8b542470 MOV EDX,dword ptr [ESP + 0x70]
    s.dx = m.r32((f.sp+0x00000070u));
  }
  L0057070f: { // 0x57070f: 8b442468 MOV EAX,dword ptr [ESP + 0x68]
    s.ax = m.r32((f.sp+0x00000068u));
  }
  L00570713: { // 0x570713: 8b742418 MOV ESI,dword ptr [ESP + 0x18]
    s.si = m.r32((f.sp+0x00000018u));
  }
  L00570717: { // 0x570717: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L00570718: { // 0x570718: 3b742428 CMP ESI,dword ptr [ESP + 0x28]
    (void)integer::sub(s.si,m.r32((f.sp+0x00000028u)),32,flags);
  }
  L0057071c: { // 0x57071c: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L00570720: { // 0x570720: 7c92 JL 0x005706b4
    if(integer::condition("JL",flags)) goto L005706b4;
  }
  L00570722: { // 0x570722: 8b5c2478 MOV EBX,dword ptr [ESP + 0x78]
    s.bx = m.r32((f.sp+0x00000078u));
  }
  L00570726: { // 0x570726: 0fbf4b02 MOVSX ECX,word ptr [EBX + 0x2]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.bx+0x00000002u)),16));
  }
  L0057072a: { // 0x57072a: 0fbf33 MOVSX ESI,word ptr [EBX]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.bx)),16));
  }
  L0057072d: { // 0x57072d: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L0057072f: { // 0x57072f: 2bf5 SUB ESI,EBP
    s.si = integer::sub(s.si,s.bp,32,flags);
  }
  L00570731: { // 0x570731: 83c602 ADD ESI,0x2
    s.si = integer::add(s.si,0x00000002u,32,flags);
  }
  L00570734: { // 0x570734: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L00570738: { // 0x570738: 8d4402fe LEA EAX,[EDX + EAX*0x1 + -0x2]
    s.ax = (s.dx+(s.ax * 0x00000001u)-0x00000002u);
  }
  L0057073c: { // 0x57073c: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057073e: { // 0x57073e: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00570740: { // 0x570740: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L00570744: { // 0x570744: 7d70 JGE 0x005707b6
    if(integer::condition("JGE",flags)) goto L005707b6;
  }
  L00570746: { // 0x570746: 8d6c2eff LEA EBP,[ESI + EBP*0x1 + -0x1]
    s.bp = (s.si+(s.bp * 0x00000001u)-0x00000001u);
  }
  L0057074a: { // 0x57074a: 896c2428 MOV dword ptr [ESP + 0x28],EBP
    m.w32((f.sp+0x00000028u), s.bp);
  }
  L0057074e: { // 0x57074e: 3bf5 CMP ESI,EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  L00570750: { // 0x570750: 8bde MOV EBX,ESI
    s.bx = s.si;
  }
  L00570752: { // 0x570752: 7d51 JGE 0x005707a5
    if(integer::condition("JGE",flags)) goto L005707a5;
  }
  L00570754: { // 0x570754: 668b542418 MOV DX,word ptr [ESP + 0x18]
    s.dx = with_ax(s.dx, m.r16((f.sp+0x00000018u)));
  }
  L00570759: { // 0x570759: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L0057075d: { // 0x57075d: 66895c2414 MOV word ptr [ESP + 0x14],BX
    m.w16((f.sp+0x00000014u), (s.bx & 0xffffu));
  }
  L00570762: { // 0x570762: 6689542416 MOV word ptr [ESP + 0x16],DX
    m.w16((f.sp+0x00000016u), (s.dx & 0xffffu));
  }
  L00570767: { // 0x570767: e8a4a00100 CALL 0x0058a810
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058a810u,5703532u); flags=s.arithmetic_flags;
  }
  L0057076c: { // 0x57076c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0057076e: { // 0x57076e: 742c JZ 0x0057079c
    if(integer::condition("JZ",flags)) goto L0057079c;
  }
  L00570770: { // 0x570770: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L00570774: { // 0x570774: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L00570778: { // 0x570778: 8b5508 MOV EDX,dword ptr [EBP + 0x8]
    s.dx = m.r32((s.bp+0x00000008u));
  }
  L0057077b: { // 0x57077b: e8e0afffff CALL 0x0056b760
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056b760u,5703552u); flags=s.arithmetic_flags;
  }
  L00570780: { // 0x570780: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L00570784: { // 0x570784: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00570789: { // 0x570789: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0057078a: { // 0x57078a: e8714dfdff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5703567u); flags=s.arithmetic_flags;
  }
  L0057078f: { // 0x57078f: 8a4d10 MOV CL,byte ptr [EBP + 0x10]
    s.cx = with_al(s.cx, m.r8((s.bp+0x00000010u)));
  }
  L00570792: { // 0x570792: 8b6c2428 MOV EBP,dword ptr [ESP + 0x28]
    s.bp = m.r32((f.sp+0x00000028u));
  }
  L00570796: { // 0x570796: 88881b010000 MOV byte ptr [EAX + 0x11b],CL
    m.w8((s.ax+0x0000011bu), (s.cx & 0xffu));
  }
  L0057079c: { // 0x57079c: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L0057079d: { // 0x57079d: 3bdd CMP EBX,EBP
    (void)integer::sub(s.bx,s.bp,32,flags);
  }
  L0057079f: { // 0x57079f: 7cb3 JL 0x00570754
    if(integer::condition("JL",flags)) goto L00570754;
  }
  L005707a1: { // 0x5707a1: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L005707a5: { // 0x5707a5: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L005707a9: { // 0x5707a9: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L005707aa: { // 0x5707aa: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L005707ac: { // 0x5707ac: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L005707b0: { // 0x5707b0: 7c9c JL 0x0057074e
    if(integer::condition("JL",flags)) goto L0057074e;
  }
  L005707b2: { // 0x5707b2: 8b5c2478 MOV EBX,dword ptr [ESP + 0x78]
    s.bx = m.r32((f.sp+0x00000078u));
  }
  L005707b6: { // 0x5707b6: 668b4702 MOV AX,word ptr [EDI + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.di+0x00000002u)));
  }
  L005707ba: { // 0x5707ba: 668b17 MOV DX,word ptr [EDI]
    s.dx = with_ax(s.dx, m.r16((s.di)));
  }
  L005707bd: { // 0x5707bd: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L005707c1: { // 0x5707c1: 8bb42480000000 MOV ESI,dword ptr [ESP + 0x80]
    s.si = m.r32((f.sp+0x00000080u));
  }
  L005707c8: { // 0x5707c8: 662d0300 SUB AX,0x3
    s.ax = with_ax(s.ax, integer::sub((s.ax & 0xffffu),0x00000003u,16,flags));
  }
  L005707cc: { // 0x5707cc: 668954241c MOV word ptr [ESP + 0x1c],DX
    m.w16((f.sp+0x0000001cu), (s.dx & 0xffffu));
  }
  L005707d1: { // 0x5707d1: 8b5510 MOV EDX,dword ptr [EBP + 0x10]
    s.dx = m.r32((s.bp+0x00000010u));
  }
  L005707d4: { // 0x5707d4: 668944241e MOV word ptr [ESP + 0x1e],AX
    m.w16((f.sp+0x0000001eu), (s.ax & 0xffffu));
  }
  L005707d9: { // 0x5707d9: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L005707dd: { // 0x5707dd: a1705ca500 MOV EAX,[0x00a55c70]
    s.ax = m.r32((0x00a55c70u));
  }
  L005707e2: { // 0x5707e2: 894c2428 MOV dword ptr [ESP + 0x28],ECX
    m.w32((f.sp+0x00000028u), s.cx);
  }
  L005707e6: { // 0x5707e6: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005707e7: { // 0x5707e7: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005707e8: { // 0x5707e8: 8d542430 LEA EDX,[ESP + 0x30]
    s.dx = (f.sp+0x00000030u);
  }
  L005707ec: { // 0x5707ec: 8d4804 LEA ECX,[EAX + 0x4]
    s.cx = (s.ax+0x00000004u);
  }
  L005707ef: { // 0x5707ef: e8fc490100 CALL 0x005851f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005851f0u,5703668u); flags=s.arithmetic_flags;
  }
  L005707f4: { // 0x5707f4: 668b0b MOV CX,word ptr [EBX]
    s.cx = with_ax(s.cx, m.r16((s.bx)));
  }
  L005707f7: { // 0x5707f7: 668b5302 MOV DX,word ptr [EBX + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.bx+0x00000002u)));
  }
  L005707fb: { // 0x5707fb: 6683e902 SUB CX,0x2
    s.cx = with_ax(s.cx, integer::sub((s.cx & 0xffffu),0x00000002u,16,flags));
  }
  L005707ff: { // 0x5707ff: 6683ea03 SUB DX,0x3
    s.dx = with_ax(s.dx, integer::sub((s.dx & 0xffffu),0x00000003u,16,flags));
  }
  L00570803: { // 0x570803: 66894c241c MOV word ptr [ESP + 0x1c],CX
    m.w16((f.sp+0x0000001cu), (s.cx & 0xffffu));
  }
  L00570808: { // 0x570808: 8b4d10 MOV ECX,dword ptr [EBP + 0x10]
    s.cx = m.r32((s.bp+0x00000010u));
  }
  L0057080b: { // 0x57080b: 668954241e MOV word ptr [ESP + 0x1e],DX
    m.w16((f.sp+0x0000001eu), (s.dx & 0xffffu));
  }
  L00570810: { // 0x570810: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L00570814: { // 0x570814: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L00570818: { // 0x570818: a1705ca500 MOV EAX,[0x00a55c70]
    s.ax = m.r32((0x00a55c70u));
  }
  L0057081d: { // 0x57081d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0057081e: { // 0x57081e: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0057081f: { // 0x57081f: 8d542430 LEA EDX,[ESP + 0x30]
    s.dx = (f.sp+0x00000030u);
  }
  L00570823: { // 0x570823: 8d4805 LEA ECX,[EAX + 0x5]
    s.cx = (s.ax+0x00000005u);
  }
  L00570826: { // 0x570826: e8c5490100 CALL 0x005851f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005851f0u,5703723u); flags=s.arithmetic_flags;
  }
  L0057082b: { // 0x57082b: 668b0b MOV CX,word ptr [EBX]
    s.cx = with_ax(s.cx, m.r16((s.bx)));
  }
  L0057082e: { // 0x57082e: 668b5302 MOV DX,word ptr [EBX + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.bx+0x00000002u)));
  }
  L00570832: { // 0x570832: 6649 DEC CX
    s.cx = with_ax(s.cx, integer::decrement((s.cx & 0xffffu),16,flags));
  }
  L00570834: { // 0x570834: 664a DEC DX
    s.dx = with_ax(s.dx, integer::decrement((s.dx & 0xffffu),16,flags));
  }
  L00570836: { // 0x570836: 66894c241c MOV word ptr [ESP + 0x1c],CX
    m.w16((f.sp+0x0000001cu), (s.cx & 0xffffu));
  }
  L0057083b: { // 0x57083b: 8b4d10 MOV ECX,dword ptr [EBP + 0x10]
    s.cx = m.r32((s.bp+0x00000010u));
  }
  L0057083e: { // 0x57083e: 668954241e MOV word ptr [ESP + 0x1e],DX
    m.w16((f.sp+0x0000001eu), (s.dx & 0xffffu));
  }
  L00570843: { // 0x570843: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L00570847: { // 0x570847: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L0057084b: { // 0x57084b: a1705ca500 MOV EAX,[0x00a55c70]
    s.ax = m.r32((0x00a55c70u));
  }
  L00570850: { // 0x570850: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00570851: { // 0x570851: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00570852: { // 0x570852: 8d542430 LEA EDX,[ESP + 0x30]
    s.dx = (f.sp+0x00000030u);
  }
  L00570856: { // 0x570856: 8d4806 LEA ECX,[EAX + 0x6]
    s.cx = (s.ax+0x00000006u);
  }
  L00570859: { // 0x570859: e892490100 CALL 0x005851f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005851f0u,5703774u); flags=s.arithmetic_flags;
  }
  L0057085e: { // 0x57085e: 8b742430 MOV ESI,dword ptr [ESP + 0x30]
    s.si = m.r32((f.sp+0x00000030u));
  }
  L00570862: { // 0x570862: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00570864: { // 0x570864: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L00570866: { // 0x570866: 6689442428 MOV word ptr [ESP + 0x28],AX
    m.w16((f.sp+0x00000028u), (s.ax & 0xffffu));
  }
  L0057086b: { // 0x57086b: 668944242a MOV word ptr [ESP + 0x2a],AX
    m.w16((f.sp+0x0000002au), (s.ax & 0xffffu));
  }
  L00570870: { // 0x570870: 0f84a5010000 JZ 0x00570a1b
    if(integer::condition("JZ",flags)) goto L00570a1b;
  }
  L00570876: { // 0x570876: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0057087b: { // 0x57087b: e860f50b00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5703808u); flags=s.arithmetic_flags;
  }
  L00570880: { // 0x570880: 89442454 MOV dword ptr [ESP + 0x54],EAX
    m.w32((f.sp+0x00000054u), s.ax);
  }
  L00570884: { // 0x570884: c744245800000000 MOV dword ptr [ESP + 0x58],0x0
    m.w32((f.sp+0x00000058u), 0x00000000u);
  }
  L0057088c: { // 0x57088c: df6c2454 FILD qword ptr [ESP + 0x54]
    const auto address=(f.sp+0x00000054u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L00570890: { // 0x570890: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L00570896: { // 0x570896: e8b5a11f00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5703835u); flags=s.arithmetic_flags;
  }
  L0057089b: { // 0x57089b: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L0057089d: { // 0x57089d: 83fd01 CMP EBP,0x1
    (void)integer::sub(s.bp,0x00000001u,32,flags);
  }
  L005708a0: { // 0x5708a0: 77d4 JA 0x00570876
    if(integer::condition("JA",flags)) goto L00570876;
  }
  L005708a2: { // 0x5708a2: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L005708a4: { // 0x5708a4: 66c74424340000 MOV word ptr [ESP + 0x34],0x0
    m.w16((f.sp+0x00000034u), 0x00000000u);
  }
  L005708ab: { // 0x5708ab: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L005708ad: { // 0x5708ad: 0f9fc1 SETG CL
    s.cx = with_al(s.cx, (integer::condition("JG",flags)?1u:0u));
  }
  L005708b0: { // 0x5708b0: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L005708b2: { // 0x5708b2: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L005708b6: { // 0x5708b6: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L005708b8: { // 0x5708b8: 0f9cc2 SETL DL
    s.dx = with_al(s.dx, (integer::condition("JL",flags)?1u:0u));
  }
  L005708bb: { // 0x5708bb: 83fd01 CMP EBP,0x1
    (void)integer::sub(s.bp,0x00000001u,32,flags);
  }
  L005708be: { // 0x5708be: 6689542436 MOV word ptr [ESP + 0x36],DX
    m.w16((f.sp+0x00000036u), (s.dx & 0xffffu));
  }
  L005708c3: { // 0x5708c3: 7513 JNZ 0x005708d8
    if(integer::condition("JNZ",flags)) goto L005708d8;
  }
  L005708c5: { // 0x5708c5: 668b44247c MOV AX,word ptr [ESP + 0x7c]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x0000007cu)));
  }
  L005708ca: { // 0x5708ca: f7de NEG ESI
    s.si = integer::sub(0u,s.si,32,flags);
  }
  L005708cc: { // 0x5708cc: 6689442428 MOV word ptr [ESP + 0x28],AX
    m.w16((f.sp+0x00000028u), (s.ax & 0xffffu));
  }
  L005708d1: { // 0x5708d1: 668974242a MOV word ptr [ESP + 0x2a],SI
    m.w16((f.sp+0x0000002au), (s.si & 0xffffu));
  }
  L005708d6: { // 0x5708d6: eb13 JMP 0x005708eb
    goto L005708eb;
  }
  L005708d8: { // 0x5708d8: 668b03 MOV AX,word ptr [EBX]
    s.ax = with_ax(s.ax, m.r16((s.bx)));
  }
  L005708db: { // 0x5708db: 662b44247c SUB AX,word ptr [ESP + 0x7c]
    s.ax = with_ax(s.ax, integer::sub((s.ax & 0xffffu),m.r16((f.sp+0x0000007cu)),16,flags));
  }
  L005708e0: { // 0x5708e0: 662b07 SUB AX,word ptr [EDI]
    s.ax = with_ax(s.ax, integer::sub((s.ax & 0xffffu),m.r16((s.di)),16,flags));
  }
  L005708e3: { // 0x5708e3: 83e805 SUB EAX,0x5
    s.ax = integer::sub(s.ax,0x00000005u,32,flags);
  }
  L005708e6: { // 0x5708e6: 6689442434 MOV word ptr [ESP + 0x34],AX
    m.w16((f.sp+0x00000034u), (s.ax & 0xffffu));
  }
  L005708eb: { // 0x5708eb: 8b54247c MOV EDX,dword ptr [ESP + 0x7c]
    s.dx = m.r32((f.sp+0x0000007cu));
  }
  L005708ef: { // 0x5708ef: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005708f1: { // 0x5708f1: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L005708f3: { // 0x5708f3: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L005708f7: { // 0x5708f7: 0f8e1e010000 JLE 0x00570a1b
    if(integer::condition("JLE",flags)) goto L00570a1b;
  }
  L005708fd: { // 0x5708fd: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00570901: { // 0x570901: eb08 JMP 0x0057090b
    goto L0057090b;
  }
  L00570903: { // 0x570903: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00570907: { // 0x570907: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0057090b: { // 0x57090b: 8d1489 LEA EDX,[ECX + ECX*0x4]
    s.dx = (s.cx+(s.cx * 0x00000004u));
  }
  L0057090e: { // 0x57090e: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L00570910: { // 0x570910: be3cb57c00 MOV ESI,0x7cb53c
    s.si = 0x007cb53cu;
  }
  L00570915: { // 0x570915: 8d1c9550b57c00 LEA EBX,[EDX*0x4 + 0x7cb550]
    s.bx = ((s.dx * 0x00000004u)+0x007cb550u);
  }
  L0057091c: { // 0x57091c: eb04 JMP 0x00570922
    goto L00570922;
  }
  L0057091e: { // 0x57091e: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L00570922: { // 0x570922: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00570924: { // 0x570924: 740a JZ 0x00570930
    if(integer::condition("JZ",flags)) goto L00570930;
  }
  L00570926: { // 0x570926: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0057092a: { // 0x57092a: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L0057092e: { // 0x57092e: eb04 JMP 0x00570934
    goto L00570934;
  }
  L00570930: { // 0x570930: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L00570934: { // 0x570934: 668b0f MOV CX,word ptr [EDI]
    s.cx = with_ax(s.cx, m.r16((s.di)));
  }
  L00570937: { // 0x570937: 8bd5 MOV EDX,EBP
    s.dx = s.bp;
  }
  L00570939: { // 0x570939: f7da NEG EDX
    s.dx = integer::sub(0u,s.dx,32,flags);
  }
  L0057093b: { // 0x57093b: 668954244e MOV word ptr [ESP + 0x4e],DX
    m.w16((f.sp+0x0000004eu), (s.dx & 0xffffu));
  }
  L00570940: { // 0x570940: 668b5702 MOV DX,word ptr [EDI + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.di+0x00000002u)));
  }
  L00570944: { // 0x570944: 6683c103 ADD CX,0x3
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),0x00000003u,16,flags));
  }
  L00570948: { // 0x570948: 668954243e MOV word ptr [ESP + 0x3e],DX
    m.w16((f.sp+0x0000003eu), (s.dx & 0xffffu));
  }
  L0057094d: { // 0x57094d: 8b54243e MOV EDX,dword ptr [ESP + 0x3e]
    s.dx = m.r32((f.sp+0x0000003eu));
  }
  L00570951: { // 0x570951: 66894c243c MOV word ptr [ESP + 0x3c],CX
    m.w16((f.sp+0x0000003cu), (s.cx & 0xffffu));
  }
  L00570956: { // 0x570956: 8b4c243c MOV ECX,dword ptr [ESP + 0x3c]
    s.cx = m.r32((f.sp+0x0000003cu));
  }
  L0057095a: { // 0x57095a: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0057095c: { // 0x57095c: 8b44244e MOV EAX,dword ptr [ESP + 0x4e]
    s.ax = m.r32((f.sp+0x0000004eu));
  }
  L00570960: { // 0x570960: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00570962: { // 0x570962: 66894c2444 MOV word ptr [ESP + 0x44],CX
    m.w16((f.sp+0x00000044u), (s.cx & 0xffffu));
  }
  L00570967: { // 0x570967: 6689542446 MOV word ptr [ESP + 0x46],DX
    m.w16((f.sp+0x00000046u), (s.dx & 0xffffu));
  }
  L0057096c: { // 0x57096c: 8b4c2444 MOV ECX,dword ptr [ESP + 0x44]
    s.cx = m.r32((f.sp+0x00000044u));
  }
  L00570970: { // 0x570970: 8b542434 MOV EDX,dword ptr [ESP + 0x34]
    s.dx = m.r32((f.sp+0x00000034u));
  }
  L00570974: { // 0x570974: 8d0411 LEA EAX,[ECX + EDX*0x1]
    s.ax = (s.cx+(s.dx * 0x00000001u));
  }
  L00570977: { // 0x570977: 8b4c2446 MOV ECX,dword ptr [ESP + 0x46]
    s.cx = m.r32((f.sp+0x00000046u));
  }
  L0057097b: { // 0x57097b: 8b542436 MOV EDX,dword ptr [ESP + 0x36]
    s.dx = m.r32((f.sp+0x00000036u));
  }
  L0057097f: { // 0x57097f: 6689442424 MOV word ptr [ESP + 0x24],AX
    m.w16((f.sp+0x00000024u), (s.ax & 0xffffu));
  }
  L00570984: { // 0x570984: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L00570986: { // 0x570986: 66894c2456 MOV word ptr [ESP + 0x56],CX
    m.w16((f.sp+0x00000056u), (s.cx & 0xffffu));
  }
  L0057098b: { // 0x57098b: 8b442456 MOV EAX,dword ptr [ESP + 0x56]
    s.ax = m.r32((f.sp+0x00000056u));
  }
  L0057098f: { // 0x57098f: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L00570993: { // 0x570993: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00570995: { // 0x570995: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0057099a: { // 0x57099a: 6689442426 MOV word ptr [ESP + 0x26],AX
    m.w16((f.sp+0x00000026u), (s.ax & 0xffffu));
  }
  L0057099f: { // 0x57099f: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L005709a3: { // 0x5709a3: 8d442430 LEA EAX,[ESP + 0x30]
    s.ax = (f.sp+0x00000030u);
  }
  L005709a7: { // 0x5709a7: 89542430 MOV dword ptr [ESP + 0x30],EDX
    m.w32((f.sp+0x00000030u), s.dx);
  }
  L005709ab: { // 0x5709ab: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005709ac: { // 0x5709ac: e84f4bfdff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5704113u); flags=s.arithmetic_flags;
  }
  L005709b1: { // 0x5709b1: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L005709b5: { // 0x5709b5: 8a0e MOV CL,byte ptr [ESI]
    s.cx = with_al(s.cx, m.r8((s.si)));
  }
  L005709b7: { // 0x5709b7: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  L005709ba: { // 0x5709ba: 83c304 ADD EBX,0x4
    s.bx = integer::add(s.bx,0x00000004u,32,flags);
  }
  L005709bd: { // 0x5709bd: 024a10 ADD CL,byte ptr [EDX + 0x10]
    s.cx = with_al(s.cx, integer::add((s.cx & 0xffu),m.r8((s.dx+0x00000010u)),8,flags));
  }
  L005709c0: { // 0x5709c0: 80e904 SUB CL,0x4
    s.cx = with_al(s.cx, integer::sub((s.cx & 0xffu),0x00000004u,8,flags));
  }
  L005709c3: { // 0x5709c3: 88881b010000 MOV byte ptr [EAX + 0x11b],CL
    m.w8((s.ax+0x0000011bu), (s.cx & 0xffu));
  }
  L005709c9: { // 0x5709c9: 8a4bfc MOV CL,byte ptr [EBX + -0x4]
    s.cx = with_al(s.cx, m.r8((s.bx-0x00000004u)));
  }
  L005709cc: { // 0x5709cc: 88881c010000 MOV byte ptr [EAX + 0x11c],CL
    m.w8((s.ax+0x0000011cu), (s.cx & 0xffu));
  }
  L005709d2: { // 0x5709d2: 8b15505ca500 MOV EDX,dword ptr [0x00a55c50]
    s.dx = m.r32((0x00a55c50u));
  }
  L005709d8: { // 0x5709d8: 81e1ff000000 AND ECX,0xff
    s.cx = integer::logical((s.cx)&(0x000000ffu),32,flags);
  }
  L005709de: { // 0x5709de: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L005709df: { // 0x5709df: c6801a01000000 MOV byte ptr [EAX + 0x11a],0x0
    m.w8((s.ax+0x0000011au), 0x00000000u);
  }
  L005709e6: { // 0x5709e6: 81fe50b57c00 CMP ESI,0x7cb550
    (void)integer::sub(s.si,0x007cb550u,32,flags);
  }
  L005709ec: { // 0x5709ec: 8d4c11ff LEA ECX,[ECX + EDX*0x1 + -0x1]
    s.cx = (s.cx+(s.dx * 0x00000001u)-0x00000001u);
  }
  L005709f0: { // 0x5709f0: 894838 MOV dword ptr [EAX + 0x38],ECX
    m.w32((s.ax+0x00000038u), s.cx);
  }
  L005709f3: { // 0x5709f3: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L005709f7: { // 0x5709f7: 0f8c21ffffff JL 0x0057091e
    if(integer::condition("JL",flags)) goto L0057091e;
  }
  L005709fd: { // 0x5709fd: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L00570a01: { // 0x570a01: 8b4c247c MOV ECX,dword ptr [ESP + 0x7c]
    s.cx = m.r32((f.sp+0x0000007cu));
  }
  L00570a05: { // 0x570a05: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00570a06: { // 0x570a06: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L00570a07: { // 0x570a07: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00570a09: { // 0x570a09: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00570a0d: { // 0x570a0d: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L00570a11: { // 0x570a11: 0f8cecfeffff JL 0x00570903
    if(integer::condition("JL",flags)) goto L00570903;
  }
  L00570a17: { // 0x570a17: 8b5c2478 MOV EBX,dword ptr [ESP + 0x78]
    s.bx = m.r32((f.sp+0x00000078u));
  }
  L00570a1b: { // 0x570a1b: 0fbf13 MOVSX EDX,word ptr [EBX]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.bx)),16));
  }
  L00570a1e: { // 0x570a1e: 0fbf07 MOVSX EAX,word ptr [EDI]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di)),16));
  }
  L00570a21: { // 0x570a21: 8b5c247c MOV EBX,dword ptr [ESP + 0x7c]
    s.bx = m.r32((f.sp+0x0000007cu));
  }
  L00570a25: { // 0x570a25: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L00570a27: { // 0x570a27: 2bd3 SUB EDX,EBX
    s.dx = integer::sub(s.dx,s.bx,32,flags);
  }
  L00570a29: { // 0x570a29: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L00570a2b: { // 0x570a2b: 83ea05 SUB EDX,0x5
    s.dx = integer::sub(s.dx,0x00000005u,32,flags);
  }
  L00570a2e: { // 0x570a2e: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00570a30: { // 0x570a30: 0f8eea000000 JLE 0x00570b20
    if(integer::condition("JLE",flags)) goto L00570b20;
  }
  L00570a36: { // 0x570a36: 8b6c242a MOV EBP,dword ptr [ESP + 0x2a]
    s.bp = m.r32((f.sp+0x0000002au));
  }
  L00570a3a: { // 0x570a3a: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00570a3c: { // 0x570a3c: 668b17 MOV DX,word ptr [EDI]
    s.dx = with_ax(s.dx, m.r16((s.di)));
  }
  L00570a3f: { // 0x570a3f: 668b4702 MOV AX,word ptr [EDI + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.di+0x00000002u)));
  }
  L00570a43: { // 0x570a43: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00570a45: { // 0x570a45: 6683c203 ADD DX,0x3
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),0x00000003u,16,flags));
  }
  L00570a49: { // 0x570a49: f7d9 NEG ECX
    s.cx = integer::sub(0u,s.cx,32,flags);
  }
  L00570a4b: { // 0x570a4b: 66894c2456 MOV word ptr [ESP + 0x56],CX
    m.w16((f.sp+0x00000056u), (s.cx & 0xffffu));
  }
  L00570a50: { // 0x570a50: 6689542444 MOV word ptr [ESP + 0x44],DX
    m.w16((f.sp+0x00000044u), (s.dx & 0xffffu));
  }
  L00570a55: { // 0x570a55: 6689442446 MOV word ptr [ESP + 0x46],AX
    m.w16((f.sp+0x00000046u), (s.ax & 0xffffu));
  }
  L00570a5a: { // 0x570a5a: 8b4c2444 MOV ECX,dword ptr [ESP + 0x44]
    s.cx = m.r32((f.sp+0x00000044u));
  }
  L00570a5e: { // 0x570a5e: 8b542446 MOV EDX,dword ptr [ESP + 0x46]
    s.dx = m.r32((f.sp+0x00000046u));
  }
  L00570a62: { // 0x570a62: 8b442456 MOV EAX,dword ptr [ESP + 0x56]
    s.ax = m.r32((f.sp+0x00000056u));
  }
  L00570a66: { // 0x570a66: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L00570a68: { // 0x570a68: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00570a6a: { // 0x570a6a: 66894c243c MOV word ptr [ESP + 0x3c],CX
    m.w16((f.sp+0x0000003cu), (s.cx & 0xffffu));
  }
  L00570a6f: { // 0x570a6f: 668954243e MOV word ptr [ESP + 0x3e],DX
    m.w16((f.sp+0x0000003eu), (s.dx & 0xffffu));
  }
  L00570a74: { // 0x570a74: 8b4c243c MOV ECX,dword ptr [ESP + 0x3c]
    s.cx = m.r32((f.sp+0x0000003cu));
  }
  L00570a78: { // 0x570a78: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L00570a7c: { // 0x570a7c: 8b44243e MOV EAX,dword ptr [ESP + 0x3e]
    s.ax = m.r32((f.sp+0x0000003eu));
  }
  L00570a80: { // 0x570a80: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L00570a82: { // 0x570a82: 03c5 ADD EAX,EBP
    s.ax = integer::add(s.ax,s.bp,32,flags);
  }
  L00570a84: { // 0x570a84: 66894c2424 MOV word ptr [ESP + 0x24],CX
    m.w16((f.sp+0x00000024u), (s.cx & 0xffffu));
  }
  L00570a89: { // 0x570a89: 6689442426 MOV word ptr [ESP + 0x26],AX
    m.w16((f.sp+0x00000026u), (s.ax & 0xffffu));
  }
  L00570a8e: { // 0x570a8e: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L00570a92: { // 0x570a92: 89542430 MOV dword ptr [ESP + 0x30],EDX
    m.w32((f.sp+0x00000030u), s.dx);
  }
  L00570a96: { // 0x570a96: 8b153c86a500 MOV EDX,dword ptr [0x00a5863c]
    s.dx = m.r32((0x00a5863cu));
  }
  L00570a9c: { // 0x570a9c: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00570a9e: { // 0x570a9e: 7420 JZ 0x00570ac0
    if(integer::condition("JZ",flags)) goto L00570ac0;
  }
  L00570aa0: { // 0x570aa0: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00570aa3: { // 0x570aa3: 0faf054c6b8300 IMUL EAX,dword ptr [0x00836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  L00570aaa: { // 0x570aaa: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L00570aad: { // 0x570aad: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00570aaf: { // 0x570aaf: 8b8c2480000000 MOV ECX,dword ptr [ESP + 0x80]
    s.cx = m.r32((f.sp+0x00000080u));
  }
  L00570ab6: { // 0x570ab6: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L00570ab9: { // 0x570ab9: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L00570abc: { // 0x570abc: 894c1038 MOV dword ptr [EAX + EDX*0x1 + 0x38],ECX
    m.w32((s.ax+(s.dx * 0x00000001u)+0x00000038u), s.cx);
  }
  L00570ac0: { // 0x570ac0: 8d542430 LEA EDX,[ESP + 0x30]
    s.dx = (f.sp+0x00000030u);
  }
  L00570ac4: { // 0x570ac4: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00570ac9: { // 0x570ac9: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00570aca: { // 0x570aca: e8314afdff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5704399u); flags=s.arithmetic_flags;
  }
  L00570acf: { // 0x570acf: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00570ad3: { // 0x570ad3: 8a5110 MOV DL,byte ptr [ECX + 0x10]
    s.dx = with_al(s.dx, m.r8((s.cx+0x00000010u)));
  }
  L00570ad6: { // 0x570ad6: c6801c01000002 MOV byte ptr [EAX + 0x11c],0x2
    m.w8((s.ax+0x0000011cu), 0x00000002u);
  }
  L00570add: { // 0x570add: 2ad3 SUB DL,BL
    s.dx = with_al(s.dx, integer::sub((s.dx & 0xffu),(s.bx & 0xffu),8,flags));
  }
  L00570adf: { // 0x570adf: feca DEC DL
    s.dx = with_al(s.dx, integer::decrement((s.dx & 0xffu),8,flags));
  }
  L00570ae1: { // 0x570ae1: 88901b010000 MOV byte ptr [EAX + 0x11b],DL
    m.w8((s.ax+0x0000011bu), (s.dx & 0xffu));
  }
  L00570ae7: { // 0x570ae7: 8b0d505ca500 MOV ECX,dword ptr [0x00a55c50]
    s.cx = m.r32((0x00a55c50u));
  }
  L00570aed: { // 0x570aed: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00570aee: { // 0x570aee: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L00570aef: { // 0x570aef: 83fb04 CMP EBX,0x4
    (void)integer::sub(s.bx,0x00000004u,32,flags);
  }
  L00570af2: { // 0x570af2: 894838 MOV dword ptr [EAX + 0x38],ECX
    m.w32((s.ax+0x00000038u), s.cx);
  }
  L00570af5: { // 0x570af5: c6801a01000000 MOV byte ptr [EAX + 0x11a],0x0
    m.w8((s.ax+0x0000011au), 0x00000000u);
  }
  L00570afc: { // 0x570afc: 0f8c3affffff JL 0x00570a3c
    if(integer::condition("JL",flags)) goto L00570a3c;
  }
  L00570b02: { // 0x570b02: 8b542478 MOV EDX,dword ptr [ESP + 0x78]
    s.dx = m.r32((f.sp+0x00000078u));
  }
  L00570b06: { // 0x570b06: 8b5c247c MOV EBX,dword ptr [ESP + 0x7c]
    s.bx = m.r32((f.sp+0x0000007cu));
  }
  L00570b0a: { // 0x570b0a: 0fbf0f MOVSX ECX,word ptr [EDI]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.di)),16));
  }
  L00570b0d: { // 0x570b0d: 0fbf02 MOVSX EAX,word ptr [EDX]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.dx)),16));
  }
  L00570b10: { // 0x570b10: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00570b12: { // 0x570b12: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L00570b13: { // 0x570b13: 2bc3 SUB EAX,EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L00570b15: { // 0x570b15: 83e805 SUB EAX,0x5
    s.ax = integer::sub(s.ax,0x00000005u,32,flags);
  }
  L00570b18: { // 0x570b18: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L00570b1a: { // 0x570b1a: 0f8c1affffff JL 0x00570a3a
    if(integer::condition("JL",flags)) goto L00570a3a;
  }
  L00570b20: { // 0x570b20: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00570b21: { // 0x570b21: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00570b22: { // 0x570b22: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00570b23: { // 0x570b23: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00570b25: { // 0x570b25: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00570b26: { // 0x570b26: 83c464 ADD ESP,0x64
    f.sp = integer::add(f.sp,0x00000064u,32,flags);
  }
  L00570b29: { // 0x570b29: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00570b30(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00570b30: { // 0x570b30: 83ec58 SUB ESP,0x58
    f.sp = integer::sub(f.sp,0x00000058u,32,flags);
  }
  L00570b33: { // 0x570b33: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00570b34: { // 0x570b34: 8b5c2464 MOV EBX,dword ptr [ESP + 0x64]
    s.bx = m.r32((f.sp+0x00000064u));
  }
  L00570b38: { // 0x570b38: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00570b39: { // 0x570b39: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00570b3a: { // 0x570b3a: 668b13 MOV DX,word ptr [EBX]
    s.dx = with_ax(s.dx, m.r16((s.bx)));
  }
  L00570b3d: { // 0x570b3d: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00570b3e: { // 0x570b3e: 8b7c246c MOV EDI,dword ptr [ESP + 0x6c]
    s.di = m.r32((f.sp+0x0000006cu));
  }
  L00570b42: { // 0x570b42: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L00570b46: { // 0x570b46: 668b07 MOV AX,word ptr [EDI]
    s.ax = with_ax(s.ax, m.r16((s.di)));
  }
  L00570b49: { // 0x570b49: 663bc2 CMP AX,DX
    (void)integer::sub((s.ax & 0xffffu),(s.dx & 0xffffu),16,flags);
  }
  L00570b4c: { // 0x570b4c: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L00570b4e: { // 0x570b4e: 7f02 JG 0x00570b52
    if(integer::condition("JG",flags)) goto L00570b52;
  }
  L00570b50: { // 0x570b50: 8bea MOV EBP,EDX
    s.bp = s.dx;
  }
  L00570b52: { // 0x570b52: 663bc2 CMP AX,DX
    (void)integer::sub((s.ax & 0xffffu),(s.dx & 0xffffu),16,flags);
  }
  L00570b55: { // 0x570b55: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00570b57: { // 0x570b57: 7c02 JL 0x00570b5b
    if(integer::condition("JL",flags)) goto L00570b5b;
  }
  L00570b59: { // 0x570b59: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L00570b5b: { // 0x570b5b: 663bc2 CMP AX,DX
    (void)integer::sub((s.ax & 0xffffu),(s.dx & 0xffffu),16,flags);
  }
  L00570b5e: { // 0x570b5e: 7c02 JL 0x00570b62
    if(integer::condition("JL",flags)) goto L00570b62;
  }
  L00570b60: { // 0x570b60: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L00570b62: { // 0x570b62: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00570b65: { // 0x570b65: 83e807 SUB EAX,0x7
    s.ax = integer::sub(s.ax,0x00000007u,32,flags);
  }
  L00570b68: { // 0x570b68: 89442458 MOV dword ptr [ESP + 0x58],EAX
    m.w32((f.sp+0x00000058u), s.ax);
  }
  L00570b6c: { // 0x570b6c: 0fbf4702 MOVSX EAX,word ptr [EDI + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L00570b70: { // 0x570b70: 8d50fc LEA EDX,[EAX + -0x4]
    s.dx = (s.ax-0x00000004u);
  }
  L00570b73: { // 0x570b73: 8954245c MOV dword ptr [ESP + 0x5c],EDX
    m.w32((f.sp+0x0000005cu), s.dx);
  }
  L00570b77: { // 0x570b77: 0fbfd6 MOVSX EDX,SI
    s.dx = std::uint32_t(integer::sign_extend((s.si & 0xffffu),16));
  }
  L00570b7a: { // 0x570b7a: 0fbff5 MOVSX ESI,BP
    s.si = std::uint32_t(integer::sign_extend((s.bp & 0xffffu),16));
  }
  L00570b7d: { // 0x570b7d: 2bf2 SUB ESI,EDX
    s.si = integer::sub(s.si,s.dx,32,flags);
  }
  L00570b7f: { // 0x570b7f: 0fbf5302 MOVSX EDX,word ptr [EBX + 0x2]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.bx+0x00000002u)),16));
  }
  L00570b83: { // 0x570b83: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L00570b85: { // 0x570b85: 8b442474 MOV EAX,dword ptr [ESP + 0x74]
    s.ax = m.r32((f.sp+0x00000074u));
  }
  L00570b89: { // 0x570b89: 83c209 ADD EDX,0x9
    s.dx = integer::add(s.dx,0x00000009u,32,flags);
  }
  L00570b8c: { // 0x570b8c: 83c60b ADD ESI,0xb
    s.si = integer::add(s.si,0x0000000bu,32,flags);
  }
  L00570b8f: { // 0x570b8f: 89542464 MOV dword ptr [ESP + 0x64],EDX
    m.w32((f.sp+0x00000064u), s.dx);
  }
  L00570b93: { // 0x570b93: 8d542458 LEA EDX,[ESP + 0x58]
    s.dx = (f.sp+0x00000058u);
  }
  L00570b97: { // 0x570b97: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00570b98: { // 0x570b98: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00570b99: { // 0x570b99: 89742468 MOV dword ptr [ESP + 0x68],ESI
    m.w32((f.sp+0x00000068u), s.si);
  }
  L00570b9d: { // 0x570b9d: e85e1b0000 CALL 0x00572700
    s.arithmetic_flags=flags; invoke(m,s,f,0x00572700u,5704610u); flags=s.arithmetic_flags;
  }
  L00570ba2: { // 0x570ba2: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00570ba4: { // 0x570ba4: 750a JNZ 0x00570bb0
    if(integer::condition("JNZ",flags)) goto L00570bb0;
  }
  L00570ba6: { // 0x570ba6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00570ba7: { // 0x570ba7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00570ba8: { // 0x570ba8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00570ba9: { // 0x570ba9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00570baa: { // 0x570baa: 83c458 ADD ESP,0x58
    f.sp = integer::add(f.sp,0x00000058u,32,flags);
  }
  L00570bad: { // 0x570bad: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00570bb0: { // 0x570bb0: 0fbf37 MOVSX ESI,word ptr [EDI]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.di)),16));
  }
  L00570bb3: { // 0x570bb3: 0fbf03 MOVSX EAX,word ptr [EBX]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.bx)),16));
  }
  L00570bb6: { // 0x570bb6: 2bc6 SUB EAX,ESI
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L00570bb8: { // 0x570bb8: 0fbf4b02 MOVSX ECX,word ptr [EBX + 0x2]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.bx+0x00000002u)),16));
  }
  L00570bbc: { // 0x570bbc: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L00570bc0: { // 0x570bc0: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00570bc1: { // 0x570bc1: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L00570bc3: { // 0x570bc3: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00570bc5: { // 0x570bc5: 0fbf5702 MOVSX EDX,word ptr [EDI + 0x2]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L00570bc9: { // 0x570bc9: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L00570bcb: { // 0x570bcb: 8944246c MOV dword ptr [ESP + 0x6c],EAX
    m.w32((f.sp+0x0000006cu), s.ax);
  }
  L00570bcf: { // 0x570bcf: 8d51fb LEA EDX,[ECX + -0x5]
    s.dx = (s.cx-0x00000005u);
  }
  L00570bd2: { // 0x570bd2: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00570bd4: { // 0x570bd4: 7e0c JLE 0x00570be2
    if(integer::condition("JLE",flags)) goto L00570be2;
  }
  L00570bd6: { // 0x570bd6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00570bd7: { // 0x570bd7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00570bd8: { // 0x570bd8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00570bd9: { // 0x570bd9: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00570bdb: { // 0x570bdb: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00570bdc: { // 0x570bdc: 83c458 ADD ESP,0x58
    f.sp = integer::add(f.sp,0x00000058u,32,flags);
  }
  L00570bdf: { // 0x570bdf: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00570be2: { // 0x570be2: 8d4101 LEA EAX,[ECX + 0x1]
    s.ax = (s.cx+0x00000001u);
  }
  L00570be5: { // 0x570be5: 8b4c2458 MOV ECX,dword ptr [ESP + 0x58]
    s.cx = m.r32((f.sp+0x00000058u));
  }
  L00570be9: { // 0x570be9: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00570bea: { // 0x570bea: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00570bec: { // 0x570bec: 2bf1 SUB ESI,ECX
    s.si = integer::sub(s.si,s.cx,32,flags);
  }
  L00570bee: { // 0x570bee: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00570bf0: { // 0x570bf0: 8b44245c MOV EAX,dword ptr [ESP + 0x5c]
    s.ax = m.r32((f.sp+0x0000005cu));
  }
  L00570bf4: { // 0x570bf4: d1fb SAR EBX,0x1
    s.bx = integer::shift(s.bx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00570bf6: { // 0x570bf6: 83c302 ADD EBX,0x2
    s.bx = integer::add(s.bx,0x00000002u,32,flags);
  }
  L00570bf9: { // 0x570bf9: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L00570bfb: { // 0x570bfb: 894c2448 MOV dword ptr [ESP + 0x48],ECX
    m.w32((f.sp+0x00000048u), s.cx);
  }
  L00570bff: { // 0x570bff: 896c241c MOV dword ptr [ESP + 0x1c],EBP
    m.w32((f.sp+0x0000001cu), s.bp);
  }
  L00570c03: { // 0x570c03: 8d540302 LEA EDX,[EBX + EAX*0x1 + 0x2]
    s.dx = (s.bx+(s.ax * 0x00000001u)+0x00000002u);
  }
  L00570c07: { // 0x570c07: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00570c09: { // 0x570c09: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L00570c0d: { // 0x570c0d: 7d79 JGE 0x00570c88
    if(integer::condition("JGE",flags)) goto L00570c88;
  }
  L00570c0f: { // 0x570c0f: 03f1 ADD ESI,ECX
    s.si = integer::add(s.si,s.cx,32,flags);
  }
  L00570c11: { // 0x570c11: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L00570c15: { // 0x570c15: 8b742448 MOV ESI,dword ptr [ESP + 0x48]
    s.si = m.r32((f.sp+0x00000048u));
  }
  L00570c19: { // 0x570c19: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00570c1d: { // 0x570c1d: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L00570c1f: { // 0x570c1f: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L00570c21: { // 0x570c21: 7d58 JGE 0x00570c7b
    if(integer::condition("JGE",flags)) goto L00570c7b;
  }
  L00570c23: { // 0x570c23: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L00570c27: { // 0x570c27: 6689742414 MOV word ptr [ESP + 0x14],SI
    m.w16((f.sp+0x00000014u), (s.si & 0xffffu));
  }
  L00570c2c: { // 0x570c2c: 66896c2416 MOV word ptr [ESP + 0x16],BP
    m.w16((f.sp+0x00000016u), (s.bp & 0xffffu));
  }
  L00570c31: { // 0x570c31: e8da9b0100 CALL 0x0058a810
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058a810u,5704758u); flags=s.arithmetic_flags;
  }
  L00570c36: { // 0x570c36: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00570c38: { // 0x570c38: 7434 JZ 0x00570c6e
    if(integer::condition("JZ",flags)) goto L00570c6e;
  }
  L00570c3a: { // 0x570c3a: 8b542474 MOV EDX,dword ptr [ESP + 0x74]
    s.dx = m.r32((f.sp+0x00000074u));
  }
  L00570c3e: { // 0x570c3e: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L00570c42: { // 0x570c42: e819abffff CALL 0x0056b760
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056b760u,5704775u); flags=s.arithmetic_flags;
  }
  L00570c47: { // 0x570c47: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L00570c4b: { // 0x570c4b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00570c4c: { // 0x570c4c: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00570c51: { // 0x570c51: e8aa48fdff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5704790u); flags=s.arithmetic_flags;
  }
  L00570c56: { // 0x570c56: 8b4c2474 MOV ECX,dword ptr [ESP + 0x74]
    s.cx = m.r32((f.sp+0x00000074u));
  }
  L00570c5a: { // 0x570c5a: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L00570c5c: { // 0x570c5c: e86f1e0000 CALL 0x00572ad0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00572ad0u,5704801u); flags=s.arithmetic_flags;
  }
  L00570c61: { // 0x570c61: 8a5010 MOV DL,byte ptr [EAX + 0x10]
    s.dx = with_al(s.dx, m.r8((s.ax+0x00000010u)));
  }
  L00570c64: { // 0x570c64: 88951b010000 MOV byte ptr [EBP + 0x11b],DL
    m.w8((s.bp+0x0000011bu), (s.dx & 0xffu));
  }
  L00570c6a: { // 0x570c6a: 8b6c241c MOV EBP,dword ptr [ESP + 0x1c]
    s.bp = m.r32((f.sp+0x0000001cu));
  }
  L00570c6e: { // 0x570c6e: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00570c72: { // 0x570c72: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L00570c73: { // 0x570c73: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L00570c75: { // 0x570c75: 7cac JL 0x00570c23
    if(integer::condition("JL",flags)) goto L00570c23;
  }
  L00570c77: { // 0x570c77: 8b4c2458 MOV ECX,dword ptr [ESP + 0x58]
    s.cx = m.r32((f.sp+0x00000058u));
  }
  L00570c7b: { // 0x570c7b: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L00570c7f: { // 0x570c7f: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L00570c80: { // 0x570c80: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L00570c82: { // 0x570c82: 896c241c MOV dword ptr [ESP + 0x1c],EBP
    m.w32((f.sp+0x0000001cu), s.bp);
  }
  L00570c86: { // 0x570c86: 7c8d JL 0x00570c15
    if(integer::condition("JL",flags)) goto L00570c15;
  }
  L00570c88: { // 0x570c88: 8b542470 MOV EDX,dword ptr [ESP + 0x70]
    s.dx = m.r32((f.sp+0x00000070u));
  }
  L00570c8c: { // 0x570c8c: 894c2448 MOV dword ptr [ESP + 0x48],ECX
    m.w32((f.sp+0x00000048u), s.cx);
  }
  L00570c90: { // 0x570c90: 0fbf4202 MOVSX EAX,word ptr [EDX + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.dx+0x00000002u)),16));
  }
  L00570c94: { // 0x570c94: 0fbf12 MOVSX EDX,word ptr [EDX]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.dx)),16));
  }
  L00570c97: { // 0x570c97: 2bc3 SUB EAX,EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L00570c99: { // 0x570c99: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L00570c9b: { // 0x570c9b: 83c003 ADD EAX,0x3
    s.ax = integer::add(s.ax,0x00000003u,32,flags);
  }
  L00570c9e: { // 0x570c9e: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L00570ca0: { // 0x570ca0: 8d740302 LEA ESI,[EBX + EAX*0x1 + 0x2]
    s.si = (s.bx+(s.ax * 0x00000001u)+0x00000002u);
  }
  L00570ca4: { // 0x570ca4: 896c2418 MOV dword ptr [ESP + 0x18],EBP
    m.w32((f.sp+0x00000018u), s.bp);
  }
  L00570ca8: { // 0x570ca8: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L00570caa: { // 0x570caa: 89742424 MOV dword ptr [ESP + 0x24],ESI
    m.w32((f.sp+0x00000024u), s.si);
  }
  L00570cae: { // 0x570cae: 7d77 JGE 0x00570d27
    if(integer::condition("JGE",flags)) goto L00570d27;
  }
  L00570cb0: { // 0x570cb0: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L00570cb2: { // 0x570cb2: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L00570cb6: { // 0x570cb6: 8b742448 MOV ESI,dword ptr [ESP + 0x48]
    s.si = m.r32((f.sp+0x00000048u));
  }
  L00570cba: { // 0x570cba: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L00570cbe: { // 0x570cbe: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L00570cc0: { // 0x570cc0: 7d58 JGE 0x00570d1a
    if(integer::condition("JGE",flags)) goto L00570d1a;
  }
  L00570cc2: { // 0x570cc2: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L00570cc6: { // 0x570cc6: 6689742414 MOV word ptr [ESP + 0x14],SI
    m.w16((f.sp+0x00000014u), (s.si & 0xffffu));
  }
  L00570ccb: { // 0x570ccb: 66896c2416 MOV word ptr [ESP + 0x16],BP
    m.w16((f.sp+0x00000016u), (s.bp & 0xffffu));
  }
  L00570cd0: { // 0x570cd0: e83b9b0100 CALL 0x0058a810
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058a810u,5704917u); flags=s.arithmetic_flags;
  }
  L00570cd5: { // 0x570cd5: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00570cd7: { // 0x570cd7: 7434 JZ 0x00570d0d
    if(integer::condition("JZ",flags)) goto L00570d0d;
  }
  L00570cd9: { // 0x570cd9: 8b542474 MOV EDX,dword ptr [ESP + 0x74]
    s.dx = m.r32((f.sp+0x00000074u));
  }
  L00570cdd: { // 0x570cdd: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L00570ce1: { // 0x570ce1: e87aaaffff CALL 0x0056b760
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056b760u,5704934u); flags=s.arithmetic_flags;
  }
  L00570ce6: { // 0x570ce6: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L00570cea: { // 0x570cea: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00570cef: { // 0x570cef: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00570cf0: { // 0x570cf0: e80b48fdff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5704949u); flags=s.arithmetic_flags;
  }
  L00570cf5: { // 0x570cf5: 8b4c2474 MOV ECX,dword ptr [ESP + 0x74]
    s.cx = m.r32((f.sp+0x00000074u));
  }
  L00570cf9: { // 0x570cf9: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L00570cfb: { // 0x570cfb: e8d01d0000 CALL 0x00572ad0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00572ad0u,5704960u); flags=s.arithmetic_flags;
  }
  L00570d00: { // 0x570d00: 8a4810 MOV CL,byte ptr [EAX + 0x10]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000010u)));
  }
  L00570d03: { // 0x570d03: 888d1b010000 MOV byte ptr [EBP + 0x11b],CL
    m.w8((s.bp+0x0000011bu), (s.cx & 0xffu));
  }
  L00570d09: { // 0x570d09: 8b6c2418 MOV EBP,dword ptr [ESP + 0x18]
    s.bp = m.r32((f.sp+0x00000018u));
  }
  L00570d0d: { // 0x570d0d: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L00570d11: { // 0x570d11: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L00570d12: { // 0x570d12: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L00570d14: { // 0x570d14: 7cac JL 0x00570cc2
    if(integer::condition("JL",flags)) goto L00570cc2;
  }
  L00570d16: { // 0x570d16: 8b4c2458 MOV ECX,dword ptr [ESP + 0x58]
    s.cx = m.r32((f.sp+0x00000058u));
  }
  L00570d1a: { // 0x570d1a: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L00570d1e: { // 0x570d1e: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L00570d1f: { // 0x570d1f: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L00570d21: { // 0x570d21: 896c2418 MOV dword ptr [ESP + 0x18],EBP
    m.w32((f.sp+0x00000018u), s.bp);
  }
  L00570d25: { // 0x570d25: 7c8f JL 0x00570cb6
    if(integer::condition("JL",flags)) goto L00570cb6;
  }
  L00570d27: { // 0x570d27: 0fbf2f MOVSX EBP,word ptr [EDI]
    s.bp = std::uint32_t(integer::sign_extend(m.r16((s.di)),16));
  }
  L00570d2a: { // 0x570d2a: 8b542460 MOV EDX,dword ptr [ESP + 0x60]
    s.dx = m.r32((f.sp+0x00000060u));
  }
  L00570d2e: { // 0x570d2e: 896c2424 MOV dword ptr [ESP + 0x24],EBP
    m.w32((f.sp+0x00000024u), s.bp);
  }
  L00570d32: { // 0x570d32: 0fbf4702 MOVSX EAX,word ptr [EDI + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L00570d36: { // 0x570d36: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L00570d38: { // 0x570d38: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00570d3c: { // 0x570d3c: 2bf5 SUB ESI,EBP
    s.si = integer::sub(s.si,s.bp,32,flags);
  }
  L00570d3e: { // 0x570d3e: 8d740eff LEA ESI,[ESI + ECX*0x1 + -0x1]
    s.si = (s.si+(s.cx * 0x00000001u)-0x00000001u);
  }
  L00570d42: { // 0x570d42: 89742450 MOV dword ptr [ESP + 0x50],ESI
    m.w32((f.sp+0x00000050u), s.si);
  }
  L00570d46: { // 0x570d46: 8d7403ff LEA ESI,[EBX + EAX*0x1 + -0x1]
    s.si = (s.bx+(s.ax * 0x00000001u)-0x00000001u);
  }
  L00570d4a: { // 0x570d4a: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L00570d4c: { // 0x570d4c: 89742420 MOV dword ptr [ESP + 0x20],ESI
    m.w32((f.sp+0x00000020u), s.si);
  }
  L00570d50: { // 0x570d50: 7d7e JGE 0x00570dd0
    if(integer::condition("JGE",flags)) goto L00570dd0;
  }
  L00570d52: { // 0x570d52: 8b442450 MOV EAX,dword ptr [ESP + 0x50]
    s.ax = m.r32((f.sp+0x00000050u));
  }
  L00570d56: { // 0x570d56: 03c5 ADD EAX,EBP
    s.ax = integer::add(s.ax,s.bp,32,flags);
  }
  L00570d58: { // 0x570d58: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L00570d5c: { // 0x570d5c: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L00570d60: { // 0x570d60: 8bf5 MOV ESI,EBP
    s.si = s.bp;
  }
  L00570d62: { // 0x570d62: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L00570d64: { // 0x570d64: 7d59 JGE 0x00570dbf
    if(integer::condition("JGE",flags)) goto L00570dbf;
  }
  L00570d66: { // 0x570d66: 668b4c2418 MOV CX,word ptr [ESP + 0x18]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000018u)));
  }
  L00570d6b: { // 0x570d6b: 6689742414 MOV word ptr [ESP + 0x14],SI
    m.w16((f.sp+0x00000014u), (s.si & 0xffffu));
  }
  L00570d70: { // 0x570d70: 66894c2416 MOV word ptr [ESP + 0x16],CX
    m.w16((f.sp+0x00000016u), (s.cx & 0xffffu));
  }
  L00570d75: { // 0x570d75: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L00570d79: { // 0x570d79: e8929a0100 CALL 0x0058a810
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058a810u,5705086u); flags=s.arithmetic_flags;
  }
  L00570d7e: { // 0x570d7e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00570d80: { // 0x570d80: 742c JZ 0x00570dae
    if(integer::condition("JZ",flags)) goto L00570dae;
  }
  L00570d82: { // 0x570d82: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L00570d86: { // 0x570d86: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L00570d8a: { // 0x570d8a: 8b5508 MOV EDX,dword ptr [EBP + 0x8]
    s.dx = m.r32((s.bp+0x00000008u));
  }
  L00570d8d: { // 0x570d8d: e8cea9ffff CALL 0x0056b760
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056b760u,5705106u); flags=s.arithmetic_flags;
  }
  L00570d92: { // 0x570d92: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  L00570d96: { // 0x570d96: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00570d9b: { // 0x570d9b: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00570d9c: { // 0x570d9c: e85f47fdff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5705121u); flags=s.arithmetic_flags;
  }
  L00570da1: { // 0x570da1: 8a4d10 MOV CL,byte ptr [EBP + 0x10]
    s.cx = with_al(s.cx, m.r8((s.bp+0x00000010u)));
  }
  L00570da4: { // 0x570da4: 8b6c2424 MOV EBP,dword ptr [ESP + 0x24]
    s.bp = m.r32((f.sp+0x00000024u));
  }
  L00570da8: { // 0x570da8: 88881b010000 MOV byte ptr [EAX + 0x11b],CL
    m.w8((s.ax+0x0000011bu), (s.cx & 0xffu));
  }
  L00570dae: { // 0x570dae: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L00570db2: { // 0x570db2: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L00570db3: { // 0x570db3: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L00570db5: { // 0x570db5: 7caf JL 0x00570d66
    if(integer::condition("JL",flags)) goto L00570d66;
  }
  L00570db7: { // 0x570db7: 8b542460 MOV EDX,dword ptr [ESP + 0x60]
    s.dx = m.r32((f.sp+0x00000060u));
  }
  L00570dbb: { // 0x570dbb: 8b4c2458 MOV ECX,dword ptr [ESP + 0x58]
    s.cx = m.r32((f.sp+0x00000058u));
  }
  L00570dbf: { // 0x570dbf: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00570dc3: { // 0x570dc3: 8b742420 MOV ESI,dword ptr [ESP + 0x20]
    s.si = m.r32((f.sp+0x00000020u));
  }
  L00570dc7: { // 0x570dc7: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00570dc8: { // 0x570dc8: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L00570dca: { // 0x570dca: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00570dce: { // 0x570dce: 7c8c JL 0x00570d5c
    if(integer::condition("JL",flags)) goto L00570d5c;
  }
  L00570dd0: { // 0x570dd0: 8b6c2470 MOV EBP,dword ptr [ESP + 0x70]
    s.bp = m.r32((f.sp+0x00000070u));
  }
  L00570dd4: { // 0x570dd4: 0fbf4502 MOVSX EAX,word ptr [EBP + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.bp+0x00000002u)),16));
  }
  L00570dd8: { // 0x570dd8: 0fbf7500 MOVSX ESI,word ptr [EBP]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.bp)),16));
  }
  L00570ddc: { // 0x570ddc: 2bc3 SUB EAX,EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L00570dde: { // 0x570dde: 2bd6 SUB EDX,ESI
    s.dx = integer::sub(s.dx,s.si,32,flags);
  }
  L00570de0: { // 0x570de0: 83c003 ADD EAX,0x3
    s.ax = integer::add(s.ax,0x00000003u,32,flags);
  }
  L00570de3: { // 0x570de3: 8d540aff LEA EDX,[EDX + ECX*0x1 + -0x1]
    s.dx = (s.dx+(s.cx * 0x00000001u)-0x00000001u);
  }
  L00570de7: { // 0x570de7: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00570deb: { // 0x570deb: 8d4c03fe LEA ECX,[EBX + EAX*0x1 + -0x2]
    s.cx = (s.bx+(s.ax * 0x00000001u)-0x00000002u);
  }
  L00570def: { // 0x570def: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00570df1: { // 0x570df1: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L00570df5: { // 0x570df5: 7d72 JGE 0x00570e69
    if(integer::condition("JGE",flags)) goto L00570e69;
  }
  L00570df7: { // 0x570df7: 03d6 ADD EDX,ESI
    s.dx = integer::add(s.dx,s.si,32,flags);
  }
  L00570df9: { // 0x570df9: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L00570dfd: { // 0x570dfd: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L00570e01: { // 0x570e01: 8bde MOV EBX,ESI
    s.bx = s.si;
  }
  L00570e03: { // 0x570e03: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L00570e05: { // 0x570e05: 7d55 JGE 0x00570e5c
    if(integer::condition("JGE",flags)) goto L00570e5c;
  }
  L00570e07: { // 0x570e07: 668b542418 MOV DX,word ptr [ESP + 0x18]
    s.dx = with_ax(s.dx, m.r16((f.sp+0x00000018u)));
  }
  L00570e0c: { // 0x570e0c: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L00570e10: { // 0x570e10: 66895c2414 MOV word ptr [ESP + 0x14],BX
    m.w16((f.sp+0x00000014u), (s.bx & 0xffffu));
  }
  L00570e15: { // 0x570e15: 6689542416 MOV word ptr [ESP + 0x16],DX
    m.w16((f.sp+0x00000016u), (s.dx & 0xffffu));
  }
  L00570e1a: { // 0x570e1a: e8f1990100 CALL 0x0058a810
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058a810u,5705247u); flags=s.arithmetic_flags;
  }
  L00570e1f: { // 0x570e1f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00570e21: { // 0x570e21: 742c JZ 0x00570e4f
    if(integer::condition("JZ",flags)) goto L00570e4f;
  }
  L00570e23: { // 0x570e23: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00570e27: { // 0x570e27: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L00570e2b: { // 0x570e2b: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L00570e2e: { // 0x570e2e: e82da9ffff CALL 0x0056b760
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056b760u,5705267u); flags=s.arithmetic_flags;
  }
  L00570e33: { // 0x570e33: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L00570e37: { // 0x570e37: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00570e38: { // 0x570e38: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00570e3d: { // 0x570e3d: e8be46fdff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5705282u); flags=s.arithmetic_flags;
  }
  L00570e42: { // 0x570e42: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00570e46: { // 0x570e46: 8a4a10 MOV CL,byte ptr [EDX + 0x10]
    s.cx = with_al(s.cx, m.r8((s.dx+0x00000010u)));
  }
  L00570e49: { // 0x570e49: 88881b010000 MOV byte ptr [EAX + 0x11b],CL
    m.w8((s.ax+0x0000011bu), (s.cx & 0xffu));
  }
  L00570e4f: { // 0x570e4f: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L00570e53: { // 0x570e53: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L00570e54: { // 0x570e54: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L00570e56: { // 0x570e56: 7caf JL 0x00570e07
    if(integer::condition("JL",flags)) goto L00570e07;
  }
  L00570e58: { // 0x570e58: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L00570e5c: { // 0x570e5c: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00570e60: { // 0x570e60: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00570e61: { // 0x570e61: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00570e63: { // 0x570e63: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00570e67: { // 0x570e67: 7c94 JL 0x00570dfd
    if(integer::condition("JL",flags)) goto L00570dfd;
  }
  L00570e69: { // 0x570e69: 668b17 MOV DX,word ptr [EDI]
    s.dx = with_ax(s.dx, m.r16((s.di)));
  }
  L00570e6c: { // 0x570e6c: 668b4702 MOV AX,word ptr [EDI + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.di+0x00000002u)));
  }
  L00570e70: { // 0x570e70: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L00570e74: { // 0x570e74: 8b742474 MOV ESI,dword ptr [ESP + 0x74]
    s.si = m.r32((f.sp+0x00000074u));
  }
  L00570e78: { // 0x570e78: 6683ea03 SUB DX,0x3
    s.dx = with_ax(s.dx, integer::sub((s.dx & 0xffffu),0x00000003u,16,flags));
  }
  L00570e7c: { // 0x570e7c: 668944241e MOV word ptr [ESP + 0x1e],AX
    m.w16((f.sp+0x0000001eu), (s.ax & 0xffffu));
  }
  L00570e81: { // 0x570e81: a1705ca500 MOV EAX,[0x00a55c70]
    s.ax = m.r32((0x00a55c70u));
  }
  L00570e86: { // 0x570e86: 668954241c MOV word ptr [ESP + 0x1c],DX
    m.w16((f.sp+0x0000001cu), (s.dx & 0xffffu));
  }
  L00570e8b: { // 0x570e8b: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L00570e8f: { // 0x570e8f: 8b5310 MOV EDX,dword ptr [EBX + 0x10]
    s.dx = m.r32((s.bx+0x00000010u));
  }
  L00570e92: { // 0x570e92: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L00570e96: { // 0x570e96: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00570e97: { // 0x570e97: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00570e98: { // 0x570e98: 8d54242c LEA EDX,[ESP + 0x2c]
    s.dx = (f.sp+0x0000002cu);
  }
  L00570e9c: { // 0x570e9c: 8d4807 LEA ECX,[EAX + 0x7]
    s.cx = (s.ax+0x00000007u);
  }
  L00570e9f: { // 0x570e9f: e84c430100 CALL 0x005851f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005851f0u,5705380u); flags=s.arithmetic_flags;
  }
  L00570ea4: { // 0x570ea4: 668b4d00 MOV CX,word ptr [EBP]
    s.cx = with_ax(s.cx, m.r16((s.bp)));
  }
  L00570ea8: { // 0x570ea8: 668b5502 MOV DX,word ptr [EBP + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.bp+0x00000002u)));
  }
  L00570eac: { // 0x570eac: 6683e903 SUB CX,0x3
    s.cx = with_ax(s.cx, integer::sub((s.cx & 0xffffu),0x00000003u,16,flags));
  }
  L00570eb0: { // 0x570eb0: 6683ea02 SUB DX,0x2
    s.dx = with_ax(s.dx, integer::sub((s.dx & 0xffffu),0x00000002u,16,flags));
  }
  L00570eb4: { // 0x570eb4: 66894c241c MOV word ptr [ESP + 0x1c],CX
    m.w16((f.sp+0x0000001cu), (s.cx & 0xffffu));
  }
  L00570eb9: { // 0x570eb9: 8b4b10 MOV ECX,dword ptr [EBX + 0x10]
    s.cx = m.r32((s.bx+0x00000010u));
  }
  L00570ebc: { // 0x570ebc: 668954241e MOV word ptr [ESP + 0x1e],DX
    m.w16((f.sp+0x0000001eu), (s.dx & 0xffffu));
  }
  L00570ec1: { // 0x570ec1: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L00570ec5: { // 0x570ec5: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L00570ec9: { // 0x570ec9: a1705ca500 MOV EAX,[0x00a55c70]
    s.ax = m.r32((0x00a55c70u));
  }
  L00570ece: { // 0x570ece: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00570ecf: { // 0x570ecf: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00570ed0: { // 0x570ed0: 8d54242c LEA EDX,[ESP + 0x2c]
    s.dx = (f.sp+0x0000002cu);
  }
  L00570ed4: { // 0x570ed4: 8d4808 LEA ECX,[EAX + 0x8]
    s.cx = (s.ax+0x00000008u);
  }
  L00570ed7: { // 0x570ed7: e814430100 CALL 0x005851f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005851f0u,5705436u); flags=s.arithmetic_flags;
  }
  L00570edc: { // 0x570edc: 668b4d00 MOV CX,word ptr [EBP]
    s.cx = with_ax(s.cx, m.r16((s.bp)));
  }
  L00570ee0: { // 0x570ee0: 668b5502 MOV DX,word ptr [EBP + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.bp+0x00000002u)));
  }
  L00570ee4: { // 0x570ee4: 6649 DEC CX
    s.cx = with_ax(s.cx, integer::decrement((s.cx & 0xffffu),16,flags));
  }
  L00570ee6: { // 0x570ee6: 664a DEC DX
    s.dx = with_ax(s.dx, integer::decrement((s.dx & 0xffffu),16,flags));
  }
  L00570ee8: { // 0x570ee8: 66894c241c MOV word ptr [ESP + 0x1c],CX
    m.w16((f.sp+0x0000001cu), (s.cx & 0xffffu));
  }
  L00570eed: { // 0x570eed: 8b4b10 MOV ECX,dword ptr [EBX + 0x10]
    s.cx = m.r32((s.bx+0x00000010u));
  }
  L00570ef0: { // 0x570ef0: 668954241e MOV word ptr [ESP + 0x1e],DX
    m.w16((f.sp+0x0000001eu), (s.dx & 0xffffu));
  }
  L00570ef5: { // 0x570ef5: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L00570ef9: { // 0x570ef9: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L00570efd: { // 0x570efd: a1705ca500 MOV EAX,[0x00a55c70]
    s.ax = m.r32((0x00a55c70u));
  }
  L00570f02: { // 0x570f02: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00570f03: { // 0x570f03: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00570f04: { // 0x570f04: 8d54242c LEA EDX,[ESP + 0x2c]
    s.dx = (f.sp+0x0000002cu);
  }
  L00570f08: { // 0x570f08: 8d4809 LEA ECX,[EAX + 0x9]
    s.cx = (s.ax+0x00000009u);
  }
  L00570f0b: { // 0x570f0b: e8e0420100 CALL 0x005851f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005851f0u,5705488u); flags=s.arithmetic_flags;
  }
  L00570f10: { // 0x570f10: 8b742428 MOV ESI,dword ptr [ESP + 0x28]
    s.si = m.r32((f.sp+0x00000028u));
  }
  L00570f14: { // 0x570f14: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00570f16: { // 0x570f16: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L00570f18: { // 0x570f18: 66895c2430 MOV word ptr [ESP + 0x30],BX
    m.w16((f.sp+0x00000030u), (s.bx & 0xffffu));
  }
  L00570f1d: { // 0x570f1d: 66895c2432 MOV word ptr [ESP + 0x32],BX
    m.w16((f.sp+0x00000032u), (s.bx & 0xffffu));
  }
  L00570f22: { // 0x570f22: 0f8499010000 JZ 0x005710c1
    if(integer::condition("JZ",flags)) goto L005710c1;
  }
  L00570f28: { // 0x570f28: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L00570f2d: { // 0x570f2d: e8aeee0b00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5705522u); flags=s.arithmetic_flags;
  }
  L00570f32: { // 0x570f32: 89442448 MOV dword ptr [ESP + 0x48],EAX
    m.w32((f.sp+0x00000048u), s.ax);
  }
  L00570f36: { // 0x570f36: 895c244c MOV dword ptr [ESP + 0x4c],EBX
    m.w32((f.sp+0x0000004cu), s.bx);
  }
  L00570f3a: { // 0x570f3a: df6c2448 FILD qword ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L00570f3e: { // 0x570f3e: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L00570f44: { // 0x570f44: e8079b1f00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5705545u); flags=s.arithmetic_flags;
  }
  L00570f49: { // 0x570f49: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L00570f4c: { // 0x570f4c: 77da JA 0x00570f28
    if(integer::condition("JA",flags)) goto L00570f28;
  }
  L00570f4e: { // 0x570f4e: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00570f50: { // 0x570f50: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L00570f52: { // 0x570f52: 0f9fc1 SETG CL
    s.cx = with_al(s.cx, (integer::condition("JG",flags)?1u:0u));
  }
  L00570f55: { // 0x570f55: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00570f57: { // 0x570f57: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L00570f59: { // 0x570f59: 0f9fc2 SETG DL
    s.dx = with_al(s.dx, (integer::condition("JG",flags)?1u:0u));
  }
  L00570f5c: { // 0x570f5c: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L00570f5f: { // 0x570f5f: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L00570f63: { // 0x570f63: 6689542438 MOV word ptr [ESP + 0x38],DX
    m.w16((f.sp+0x00000038u), (s.dx & 0xffffu));
  }
  L00570f68: { // 0x570f68: 66895c243a MOV word ptr [ESP + 0x3a],BX
    m.w16((f.sp+0x0000003au), (s.bx & 0xffffu));
  }
  L00570f6d: { // 0x570f6d: 7511 JNZ 0x00570f80
    if(integer::condition("JNZ",flags)) goto L00570f80;
  }
  L00570f6f: { // 0x570f6f: 668b44246c MOV AX,word ptr [ESP + 0x6c]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x0000006cu)));
  }
  L00570f74: { // 0x570f74: 6689742430 MOV word ptr [ESP + 0x30],SI
    m.w16((f.sp+0x00000030u), (s.si & 0xffffu));
  }
  L00570f79: { // 0x570f79: 6689442432 MOV word ptr [ESP + 0x32],AX
    m.w16((f.sp+0x00000032u), (s.ax & 0xffffu));
  }
  L00570f7e: { // 0x570f7e: eb15 JMP 0x00570f95
    goto L00570f95;
  }
  L00570f80: { // 0x570f80: 668b4502 MOV AX,word ptr [EBP + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.bp+0x00000002u)));
  }
  L00570f84: { // 0x570f84: 662b44246c SUB AX,word ptr [ESP + 0x6c]
    s.ax = with_ax(s.ax, integer::sub((s.ax & 0xffffu),m.r16((f.sp+0x0000006cu)),16,flags));
  }
  L00570f89: { // 0x570f89: 662b4702 SUB AX,word ptr [EDI + 0x2]
    s.ax = with_ax(s.ax, integer::sub((s.ax & 0xffffu),m.r16((s.di+0x00000002u)),16,flags));
  }
  L00570f8d: { // 0x570f8d: 83e805 SUB EAX,0x5
    s.ax = integer::sub(s.ax,0x00000005u,32,flags);
  }
  L00570f90: { // 0x570f90: 668944243a MOV word ptr [ESP + 0x3a],AX
    m.w16((f.sp+0x0000003au), (s.ax & 0xffffu));
  }
  L00570f95: { // 0x570f95: 8b44246c MOV EAX,dword ptr [ESP + 0x6c]
    s.ax = m.r32((f.sp+0x0000006cu));
  }
  L00570f99: { // 0x570f99: 895c2414 MOV dword ptr [ESP + 0x14],EBX
    m.w32((f.sp+0x00000014u), s.bx);
  }
  L00570f9d: { // 0x570f9d: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00570f9f: { // 0x570f9f: 0f8e1c010000 JLE 0x005710c1
    if(integer::condition("JLE",flags)) goto L005710c1;
  }
  L00570fa5: { // 0x570fa5: 895c2418 MOV dword ptr [ESP + 0x18],EBX
    m.w32((f.sp+0x00000018u), s.bx);
  }
  L00570fa9: { // 0x570fa9: eb06 JMP 0x00570fb1
    goto L00570fb1;
  }
  L00570fab: { // 0x570fab: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L00570faf: { // 0x570faf: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00570fb1: { // 0x570fb1: 8d1489 LEA EDX,[ECX + ECX*0x4]
    s.dx = (s.cx+(s.cx * 0x00000004u));
  }
  L00570fb4: { // 0x570fb4: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L00570fb6: { // 0x570fb6: be78b57c00 MOV ESI,0x7cb578
    s.si = 0x007cb578u;
  }
  L00570fbb: { // 0x570fbb: 8d1c958cb57c00 LEA EBX,[EDX*0x4 + 0x7cb58c]
    s.bx = ((s.dx * 0x00000004u)+0x007cb58cu);
  }
  L00570fc2: { // 0x570fc2: eb04 JMP 0x00570fc8
    goto L00570fc8;
  }
  L00570fc4: { // 0x570fc4: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L00570fc8: { // 0x570fc8: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00570fca: { // 0x570fca: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L00570fce: { // 0x570fce: 7504 JNZ 0x00570fd4
    if(integer::condition("JNZ",flags)) goto L00570fd4;
  }
  L00570fd0: { // 0x570fd0: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L00570fd4: { // 0x570fd4: 668b17 MOV DX,word ptr [EDI]
    s.dx = with_ax(s.dx, m.r16((s.di)));
  }
  L00570fd7: { // 0x570fd7: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L00570fd9: { // 0x570fd9: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L00570fdb: { // 0x570fdb: 6689442428 MOV word ptr [ESP + 0x28],AX
    m.w16((f.sp+0x00000028u), (s.ax & 0xffffu));
  }
  L00570fe0: { // 0x570fe0: 668b4702 MOV AX,word ptr [EDI + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.di+0x00000002u)));
  }
  L00570fe4: { // 0x570fe4: 66050300 ADD AX,0x3
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),0x00000003u,16,flags));
  }
  L00570fe8: { // 0x570fe8: 6689542440 MOV word ptr [ESP + 0x40],DX
    m.w16((f.sp+0x00000040u), (s.dx & 0xffffu));
  }
  L00570fed: { // 0x570fed: 6689442442 MOV word ptr [ESP + 0x42],AX
    m.w16((f.sp+0x00000042u), (s.ax & 0xffffu));
  }
  L00570ff2: { // 0x570ff2: 8b542440 MOV EDX,dword ptr [ESP + 0x40]
    s.dx = m.r32((f.sp+0x00000040u));
  }
  L00570ff6: { // 0x570ff6: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L00570ffa: { // 0x570ffa: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00570ffc: { // 0x570ffc: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00571000: { // 0x571000: 6689542448 MOV word ptr [ESP + 0x48],DX
    m.w16((f.sp+0x00000048u), (s.dx & 0xffffu));
  }
  L00571005: { // 0x571005: 8b542442 MOV EDX,dword ptr [ESP + 0x42]
    s.dx = m.r32((f.sp+0x00000042u));
  }
  L00571009: { // 0x571009: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L0057100b: { // 0x57100b: 8b442438 MOV EAX,dword ptr [ESP + 0x38]
    s.ax = m.r32((f.sp+0x00000038u));
  }
  L0057100f: { // 0x57100f: 668954244a MOV word ptr [ESP + 0x4a],DX
    m.w16((f.sp+0x0000004au), (s.dx & 0xffffu));
  }
  L00571014: { // 0x571014: 8b542448 MOV EDX,dword ptr [ESP + 0x48]
    s.dx = m.r32((f.sp+0x00000048u));
  }
  L00571018: { // 0x571018: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L0057101a: { // 0x57101a: 8b44243a MOV EAX,dword ptr [ESP + 0x3a]
    s.ax = m.r32((f.sp+0x0000003au));
  }
  L0057101e: { // 0x57101e: 6689542420 MOV word ptr [ESP + 0x20],DX
    m.w16((f.sp+0x00000020u), (s.dx & 0xffffu));
  }
  L00571023: { // 0x571023: 8b54244a MOV EDX,dword ptr [ESP + 0x4a]
    s.dx = m.r32((f.sp+0x0000004au));
  }
  L00571027: { // 0x571027: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00571029: { // 0x571029: 6689442422 MOV word ptr [ESP + 0x22],AX
    m.w16((f.sp+0x00000022u), (s.ax & 0xffffu));
  }
  L0057102e: { // 0x57102e: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L00571032: { // 0x571032: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L00571034: { // 0x571034: 8d4c242c LEA ECX,[ESP + 0x2c]
    s.cx = (f.sp+0x0000002cu);
  }
  L00571038: { // 0x571038: 6689542424 MOV word ptr [ESP + 0x24],DX
    m.w16((f.sp+0x00000024u), (s.dx & 0xffffu));
  }
  L0057103d: { // 0x57103d: 6689442426 MOV word ptr [ESP + 0x26],AX
    m.w16((f.sp+0x00000026u), (s.ax & 0xffffu));
  }
  L00571042: { // 0x571042: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L00571046: { // 0x571046: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00571047: { // 0x571047: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0057104c: { // 0x57104c: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L00571050: { // 0x571050: e8ab44fdff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5705813u); flags=s.arithmetic_flags;
  }
  L00571055: { // 0x571055: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00571059: { // 0x571059: 8a16 MOV DL,byte ptr [ESI]
    s.dx = with_al(s.dx, m.r8((s.si)));
  }
  L0057105b: { // 0x57105b: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  L0057105e: { // 0x57105e: 83c304 ADD EBX,0x4
    s.bx = integer::add(s.bx,0x00000004u,32,flags);
  }
  L00571061: { // 0x571061: 025110 ADD DL,byte ptr [ECX + 0x10]
    s.dx = with_al(s.dx, integer::add((s.dx & 0xffu),m.r8((s.cx+0x00000010u)),8,flags));
  }
  L00571064: { // 0x571064: 80ea04 SUB DL,0x4
    s.dx = with_al(s.dx, integer::sub((s.dx & 0xffu),0x00000004u,8,flags));
  }
  L00571067: { // 0x571067: 88901b010000 MOV byte ptr [EAX + 0x11b],DL
    m.w8((s.ax+0x0000011bu), (s.dx & 0xffu));
  }
  L0057106d: { // 0x57106d: 8a4bfc MOV CL,byte ptr [EBX + -0x4]
    s.cx = with_al(s.cx, m.r8((s.bx-0x00000004u)));
  }
  L00571070: { // 0x571070: 88881c010000 MOV byte ptr [EAX + 0x11c],CL
    m.w8((s.ax+0x0000011cu), (s.cx & 0xffu));
  }
  L00571076: { // 0x571076: 8b15505ca500 MOV EDX,dword ptr [0x00a55c50]
    s.dx = m.r32((0x00a55c50u));
  }
  L0057107c: { // 0x57107c: 81e1ff000000 AND ECX,0xff
    s.cx = integer::logical((s.cx)&(0x000000ffu),32,flags);
  }
  L00571082: { // 0x571082: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L00571083: { // 0x571083: 81fe8cb57c00 CMP ESI,0x7cb58c
    (void)integer::sub(s.si,0x007cb58cu,32,flags);
  }
  L00571089: { // 0x571089: c6801a01000000 MOV byte ptr [EAX + 0x11a],0x0
    m.w8((s.ax+0x0000011au), 0x00000000u);
  }
  L00571090: { // 0x571090: 8d4c11ff LEA ECX,[ECX + EDX*0x1 + -0x1]
    s.cx = (s.cx+(s.dx * 0x00000001u)-0x00000001u);
  }
  L00571094: { // 0x571094: 894838 MOV dword ptr [EAX + 0x38],ECX
    m.w32((s.ax+0x00000038u), s.cx);
  }
  L00571097: { // 0x571097: 0f8c27ffffff JL 0x00570fc4
    if(integer::condition("JL",flags)) goto L00570fc4;
  }
  L0057109d: { // 0x57109d: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L005710a1: { // 0x5710a1: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L005710a5: { // 0x5710a5: 8b4c246c MOV ECX,dword ptr [ESP + 0x6c]
    s.cx = m.r32((f.sp+0x0000006cu));
  }
  L005710a9: { // 0x5710a9: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L005710aa: { // 0x5710aa: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L005710ab: { // 0x5710ab: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L005710ad: { // 0x5710ad: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L005710b1: { // 0x5710b1: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L005710b5: { // 0x5710b5: 0f8cf0feffff JL 0x00570fab
    if(integer::condition("JL",flags)) goto L00570fab;
  }
  L005710bb: { // 0x5710bb: 8b6c2470 MOV EBP,dword ptr [ESP + 0x70]
    s.bp = m.r32((f.sp+0x00000070u));
  }
  L005710bf: { // 0x5710bf: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L005710c1: { // 0x5710c1: 0fbf5502 MOVSX EDX,word ptr [EBP + 0x2]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.bp+0x00000002u)),16));
  }
  L005710c5: { // 0x5710c5: 0fbf4702 MOVSX EAX,word ptr [EDI + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L005710c9: { // 0x5710c9: 8b6c246c MOV EBP,dword ptr [ESP + 0x6c]
    s.bp = m.r32((f.sp+0x0000006cu));
  }
  L005710cd: { // 0x5710cd: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L005710cf: { // 0x5710cf: 2bd5 SUB EDX,EBP
    s.dx = integer::sub(s.dx,s.bp,32,flags);
  }
  L005710d1: { // 0x5710d1: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L005710d3: { // 0x5710d3: 83ea05 SUB EDX,0x5
    s.dx = integer::sub(s.dx,0x00000005u,32,flags);
  }
  L005710d6: { // 0x5710d6: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L005710d8: { // 0x5710d8: 0f8eea000000 JLE 0x005711c8
    if(integer::condition("JLE",flags)) goto L005711c8;
  }
  L005710de: { // 0x5710de: 8b6c2432 MOV EBP,dword ptr [ESP + 0x32]
    s.bp = m.r32((f.sp+0x00000032u));
  }
  L005710e2: { // 0x5710e2: eb02 JMP 0x005710e6
    goto L005710e6;
  }
  L005710e4: { // 0x5710e4: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L005710e6: { // 0x5710e6: 668b4702 MOV AX,word ptr [EDI + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.di+0x00000002u)));
  }
  L005710ea: { // 0x5710ea: 668b17 MOV DX,word ptr [EDI]
    s.dx = with_ax(s.dx, m.r16((s.di)));
  }
  L005710ed: { // 0x5710ed: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L005710ef: { // 0x5710ef: 66050300 ADD AX,0x3
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),0x00000003u,16,flags));
  }
  L005710f3: { // 0x5710f3: f7d9 NEG ECX
    s.cx = integer::sub(0u,s.cx,32,flags);
  }
  L005710f5: { // 0x5710f5: 66894c242c MOV word ptr [ESP + 0x2c],CX
    m.w16((f.sp+0x0000002cu), (s.cx & 0xffffu));
  }
  L005710fa: { // 0x5710fa: 6689542448 MOV word ptr [ESP + 0x48],DX
    m.w16((f.sp+0x00000048u), (s.dx & 0xffffu));
  }
  L005710ff: { // 0x5710ff: 8b54242c MOV EDX,dword ptr [ESP + 0x2c]
    s.dx = m.r32((f.sp+0x0000002cu));
  }
  L00571103: { // 0x571103: 668944244a MOV word ptr [ESP + 0x4a],AX
    m.w16((f.sp+0x0000004au), (s.ax & 0xffffu));
  }
  L00571108: { // 0x571108: 8b4c2448 MOV ECX,dword ptr [ESP + 0x48]
    s.cx = m.r32((f.sp+0x00000048u));
  }
  L0057110c: { // 0x57110c: 8b44244a MOV EAX,dword ptr [ESP + 0x4a]
    s.ax = m.r32((f.sp+0x0000004au));
  }
  L00571110: { // 0x571110: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L00571112: { // 0x571112: 8b542430 MOV EDX,dword ptr [ESP + 0x30]
    s.dx = m.r32((f.sp+0x00000030u));
  }
  L00571116: { // 0x571116: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L00571118: { // 0x571118: 66894c2440 MOV word ptr [ESP + 0x40],CX
    m.w16((f.sp+0x00000040u), (s.cx & 0xffffu));
  }
  L0057111d: { // 0x57111d: 6689442442 MOV word ptr [ESP + 0x42],AX
    m.w16((f.sp+0x00000042u), (s.ax & 0xffffu));
  }
  L00571122: { // 0x571122: 8b4c2440 MOV ECX,dword ptr [ESP + 0x40]
    s.cx = m.r32((f.sp+0x00000040u));
  }
  L00571126: { // 0x571126: 8b442442 MOV EAX,dword ptr [ESP + 0x42]
    s.ax = m.r32((f.sp+0x00000042u));
  }
  L0057112a: { // 0x57112a: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L0057112c: { // 0x57112c: 03c5 ADD EAX,EBP
    s.ax = integer::add(s.ax,s.bp,32,flags);
  }
  L0057112e: { // 0x57112e: 66894c2424 MOV word ptr [ESP + 0x24],CX
    m.w16((f.sp+0x00000024u), (s.cx & 0xffffu));
  }
  L00571133: { // 0x571133: 6689442426 MOV word ptr [ESP + 0x26],AX
    m.w16((f.sp+0x00000026u), (s.ax & 0xffffu));
  }
  L00571138: { // 0x571138: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L0057113c: { // 0x57113c: 89542428 MOV dword ptr [ESP + 0x28],EDX
    m.w32((f.sp+0x00000028u), s.dx);
  }
  L00571140: { // 0x571140: 8b153c86a500 MOV EDX,dword ptr [0x00a5863c]
    s.dx = m.r32((0x00a5863cu));
  }
  L00571146: { // 0x571146: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00571148: { // 0x571148: 741d JZ 0x00571167
    if(integer::condition("JZ",flags)) goto L00571167;
  }
  L0057114a: { // 0x57114a: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0057114d: { // 0x57114d: 0faf054c6b8300 IMUL EAX,dword ptr [0x00836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  L00571154: { // 0x571154: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L00571157: { // 0x571157: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00571159: { // 0x571159: 8b4c2474 MOV ECX,dword ptr [ESP + 0x74]
    s.cx = m.r32((f.sp+0x00000074u));
  }
  L0057115d: { // 0x57115d: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L00571160: { // 0x571160: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L00571163: { // 0x571163: 894c1038 MOV dword ptr [EAX + EDX*0x1 + 0x38],ECX
    m.w32((s.ax+(s.dx * 0x00000001u)+0x00000038u), s.cx);
  }
  L00571167: { // 0x571167: 8d542428 LEA EDX,[ESP + 0x28]
    s.dx = (f.sp+0x00000028u);
  }
  L0057116b: { // 0x57116b: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00571170: { // 0x571170: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00571171: { // 0x571171: e88a43fdff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5706102u); flags=s.arithmetic_flags;
  }
  L00571176: { // 0x571176: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L0057117a: { // 0x57117a: 8a5110 MOV DL,byte ptr [ECX + 0x10]
    s.dx = with_al(s.dx, m.r8((s.cx+0x00000010u)));
  }
  L0057117d: { // 0x57117d: c6801c01000001 MOV byte ptr [EAX + 0x11c],0x1
    m.w8((s.ax+0x0000011cu), 0x00000001u);
  }
  L00571184: { // 0x571184: 2ad3 SUB DL,BL
    s.dx = with_al(s.dx, integer::sub((s.dx & 0xffu),(s.bx & 0xffu),8,flags));
  }
  L00571186: { // 0x571186: feca DEC DL
    s.dx = with_al(s.dx, integer::decrement((s.dx & 0xffu),8,flags));
  }
  L00571188: { // 0x571188: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L00571189: { // 0x571189: 88901b010000 MOV byte ptr [EAX + 0x11b],DL
    m.w8((s.ax+0x0000011bu), (s.dx & 0xffu));
  }
  L0057118f: { // 0x57118f: 8b0d505ca500 MOV ECX,dword ptr [0x00a55c50]
    s.cx = m.r32((0x00a55c50u));
  }
  L00571195: { // 0x571195: 83fb04 CMP EBX,0x4
    (void)integer::sub(s.bx,0x00000004u,32,flags);
  }
  L00571198: { // 0x571198: 894838 MOV dword ptr [EAX + 0x38],ECX
    m.w32((s.ax+0x00000038u), s.cx);
  }
  L0057119b: { // 0x57119b: c6801a01000000 MOV byte ptr [EAX + 0x11a],0x0
    m.w8((s.ax+0x0000011au), 0x00000000u);
  }
  L005711a2: { // 0x5711a2: 0f8c3effffff JL 0x005710e6
    if(integer::condition("JL",flags)) goto L005710e6;
  }
  L005711a8: { // 0x5711a8: 8b542470 MOV EDX,dword ptr [ESP + 0x70]
    s.dx = m.r32((f.sp+0x00000070u));
  }
  L005711ac: { // 0x5711ac: 8b5c246c MOV EBX,dword ptr [ESP + 0x6c]
    s.bx = m.r32((f.sp+0x0000006cu));
  }
  L005711b0: { // 0x5711b0: 0fbf4f02 MOVSX ECX,word ptr [EDI + 0x2]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L005711b4: { // 0x5711b4: 0fbf4202 MOVSX EAX,word ptr [EDX + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.dx+0x00000002u)),16));
  }
  L005711b8: { // 0x5711b8: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L005711ba: { // 0x5711ba: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L005711bb: { // 0x5711bb: 2bc3 SUB EAX,EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L005711bd: { // 0x5711bd: 83e805 SUB EAX,0x5
    s.ax = integer::sub(s.ax,0x00000005u,32,flags);
  }
  L005711c0: { // 0x5711c0: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L005711c2: { // 0x5711c2: 0f8c1cffffff JL 0x005710e4
    if(integer::condition("JL",flags)) goto L005710e4;
  }
  L005711c8: { // 0x5711c8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005711c9: { // 0x5711c9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005711ca: { // 0x5711ca: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005711cb: { // 0x5711cb: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L005711cd: { // 0x5711cd: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005711ce: { // 0x5711ce: 83c458 ADD ESP,0x58
    f.sp = integer::add(f.sp,0x00000058u,32,flags);
  }
  L005711d1: { // 0x5711d1: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
