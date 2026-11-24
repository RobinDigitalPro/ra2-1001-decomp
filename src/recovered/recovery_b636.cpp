#include "platform/observed_ticks636.hpp"
#include "recovered/recovery_b636_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b636 {
namespace {
void f_00144ef0(Memory&,State&,Frame&,const Operations&);
void f_00169980(Memory&,State&,Frame&,const Operations&);
void f_00169a30(Memory&,State&,Frame&,const Operations&);
void f_0002d4a0(Memory&,State&,Frame&,const Operations&);
void f_00167930(Memory&,State&,Frame&,const Operations&);
void f_00277c20(Memory&,State&,Frame&,const Operations&);
void f_0002ce60(Memory&,State&,Frame&,const Operations&);
void f_00277cb0(Memory&,State&,Frame&,const Operations&);
void f_000dd870(Memory&,State&,Frame&,const Operations&);
void f_0028fad0(Memory&,State&,Frame&,const Operations&);
void f_00005bf0(Memory&,State&,Frame&,const Operations&);
void f_0000aed0(Memory&,State&,Frame&,const Operations&);
void f_00277bb0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_00144ef0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00544ef0: { // 0x544ef0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00544ef1: { // 0x544ef1: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00544ef2: { // 0x544ef2: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00544ef3: { // 0x544ef3: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00544ef4: { // 0x544ef4: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00544ef6: { // 0x544ef6: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00544ef7: { // 0x544ef7: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00544ef9: { // 0x544ef9: 8d7e4c LEA EDI,[ESI + 0x4c]
    s.di = (s.si+0x0000004cu);
  }
  L00544efc: { // 0x544efc: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00544efd: { // 0x544efd: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00544efe: { // 0x544efe: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00544f00: { // 0x544f00: c7063cdc7800 MOV dword ptr [ESI],0x78dc3c
    m.w32((s.si), 0x0078dc3cu);
  }
  L00544f06: { // 0x544f06: 885e10 MOV byte ptr [ESI + 0x10],BL
    m.w8((s.si+0x00000010u), (s.bx & 0xffu));
  }
  L00544f09: { // 0x544f09: 895e14 MOV dword ptr [ESI + 0x14],EBX
    m.w32((s.si+0x00000014u), s.bx);
  }
  L00544f0c: { // 0x544f0c: e86f4a0200 CALL 0x00569980
    s.arithmetic_flags=flags; invoke(m,s,f,0x00569980u,5525265u); flags=s.arithmetic_flags;
  }
  L00544f11: { // 0x544f11: c707d8097900 MOV dword ptr [EDI],0x7909d8
    m.w32((s.di), 0x007909d8u);
  }
  L00544f17: { // 0x544f17: c747140a000000 MOV dword ptr [EDI + 0x14],0xa
    m.w32((s.di+0x00000014u), 0x0000000au);
  }
  L00544f1e: { // 0x544f1e: 895f10 MOV dword ptr [EDI + 0x10],EBX
    m.w32((s.di+0x00000010u), s.bx);
  }
  L00544f21: { // 0x544f21: 8dbe88000000 LEA EDI,[ESI + 0x88]
    s.di = (s.si+0x00000088u);
  }
  L00544f27: { // 0x544f27: bd03000000 MOV EBP,0x3
    s.bp = 0x00000003u;
  }
  L00544f2c: { // 0x544f2c: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00544f2d: { // 0x544f2d: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00544f2e: { // 0x544f2e: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00544f30: { // 0x544f30: e8fb4a0200 CALL 0x00569a30
    s.arithmetic_flags=flags; invoke(m,s,f,0x00569a30u,5525301u); flags=s.arithmetic_flags;
  }
  L00544f35: { // 0x544f35: c707b8097900 MOV dword ptr [EDI],0x7909b8
    m.w32((s.di), 0x007909b8u);
  }
  L00544f3b: { // 0x544f3b: c747140a000000 MOV dword ptr [EDI + 0x14],0xa
    m.w32((s.di+0x00000014u), 0x0000000au);
  }
  L00544f42: { // 0x544f42: 895f10 MOV dword ptr [EDI + 0x10],EBX
    m.w32((s.di+0x00000010u), s.bx);
  }
  L00544f45: { // 0x544f45: 83c718 ADD EDI,0x18
    s.di = integer::add(s.di,0x00000018u,32,flags);
  }
  L00544f48: { // 0x544f48: 4d DEC EBP
    s.bp = integer::decrement(s.bp,32,flags);
  }
  L00544f49: { // 0x544f49: 75e1 JNZ 0x00544f2c
    if(integer::condition("JNZ",flags)) goto L00544f2c;
  }
  L00544f4b: { // 0x544f4b: 8dbed0000000 LEA EDI,[ESI + 0xd0]
    s.di = (s.si+0x000000d0u);
  }
  L00544f51: { // 0x544f51: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00544f52: { // 0x544f52: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00544f53: { // 0x544f53: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00544f55: { // 0x544f55: e84685eeff CALL 0x0042d4a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042d4a0u,5525338u); flags=s.arithmetic_flags;
  }
  L00544f5a: { // 0x544f5a: ba0a000000 MOV EDX,0xa
    s.dx = 0x0000000au;
  }
  L00544f5f: { // 0x544f5f: c707a0757800 MOV dword ptr [EDI],0x7875a0
    m.w32((s.di), 0x007875a0u);
  }
  L00544f65: { // 0x544f65: 895714 MOV dword ptr [EDI + 0x14],EDX
    m.w32((s.di+0x00000014u), s.dx);
  }
  L00544f68: { // 0x544f68: 895f10 MOV dword ptr [EDI + 0x10],EBX
    m.w32((s.di+0x00000010u), s.bx);
  }
  L00544f6b: { // 0x544f6b: c7863401000098097900 MOV dword ptr [ESI + 0x134],0x790998
    m.w32((s.si+0x00000134u), 0x00790998u);
  }
  L00544f75: { // 0x544f75: 8d8660010000 LEA EAX,[ESI + 0x160]
    s.ax = (s.si+0x00000160u);
  }
  L00544f7b: { // 0x544f7b: b900010000 MOV ECX,0x100
    s.cx = 0x00000100u;
  }
  L00544f80: { // 0x544f80: 668918 MOV word ptr [EAX],BX
    m.w16((s.ax), (s.bx & 0xffffu));
  }
  L00544f83: { // 0x544f83: 66895802 MOV word ptr [EAX + 0x2],BX
    m.w16((s.ax+0x00000002u), (s.bx & 0xffffu));
  }
  L00544f87: { // 0x544f87: 83c010 ADD EAX,0x10
    s.ax = integer::add(s.ax,0x00000010u,32,flags);
  }
  L00544f8a: { // 0x544f8a: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00544f8b: { // 0x544f8b: 75f3 JNZ 0x00544f80
    if(integer::condition("JNZ",flags)) goto L00544f80;
  }
  L00544f8d: { // 0x544f8d: 899e5c110000 MOV dword ptr [ESI + 0x115c],EBX
    m.w32((s.si+0x0000115cu), s.bx);
  }
  L00544f93: { // 0x544f93: 899e60110000 MOV dword ptr [ESI + 0x1160],EBX
    m.w32((s.si+0x00001160u), s.bx);
  }
  L00544f99: { // 0x544f99: c6866411000001 MOV byte ptr [ESI + 0x1164],0x1
    m.w8((s.si+0x00001164u), 0x00000001u);
  }
  L00544fa0: { // 0x544fa0: 889e65110000 MOV byte ptr [ESI + 0x1165],BL
    m.w8((s.si+0x00001165u), (s.bx & 0xffu));
  }
  L00544fa6: { // 0x544fa6: c78658110000a0757800 MOV dword ptr [ESI + 0x1158],0x7875a0
    m.w32((s.si+0x00001158u), 0x007875a0u);
  }
  L00544fb0: { // 0x544fb0: 89966c110000 MOV dword ptr [ESI + 0x116c],EDX
    m.w32((s.si+0x0000116cu), s.dx);
  }
  L00544fb6: { // 0x544fb6: 899e68110000 MOV dword ptr [ESI + 0x1168],EBX
    m.w32((s.si+0x00001168u), s.bx);
  }
  L00544fbc: { // 0x544fbc: 8d7e18 LEA EDI,[ESI + 0x18]
    s.di = (s.si+0x00000018u);
  }
  L00544fbf: { // 0x544fbf: b90c000000 MOV ECX,0xc
    s.cx = 0x0000000cu;
  }
  L00544fc4: { // 0x544fc4: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00544fc6: { // 0x544fc6: c7061c097900 MOV dword ptr [ESI],0x79091c
    m.w32((s.si), 0x0079091cu);
  }
  L00544fcc: { // 0x544fcc: 8d6e7c LEA EBP,[ESI + 0x7c]
    s.bp = (s.si+0x0000007cu);
  }
  L00544fcf: { // 0x544fcf: f3ab STOSD.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::count);
  }
  L00544fd1: { // 0x544fd1: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00544fd3: { // 0x544fd3: 8dbe88000000 LEA EDI,[ESI + 0x88]
    s.di = (s.si+0x00000088u);
  }
  L00544fd9: { // 0x544fd9: c744241003000000 MOV dword ptr [ESP + 0x10],0x3
    m.w32((f.sp+0x00000010u), 0x00000003u);
  }
  L00544fe1: { // 0x544fe1: 8901 MOV dword ptr [ECX],EAX
    m.w32((s.cx), s.ax);
  }
  L00544fe3: { // 0x544fe3: 894104 MOV dword ptr [ECX + 0x4],EAX
    m.w32((s.cx+0x00000004u), s.ax);
  }
  L00544fe6: { // 0x544fe6: 894108 MOV dword ptr [ECX + 0x8],EAX
    m.w32((s.cx+0x00000008u), s.ax);
  }
  L00544fe9: { // 0x544fe9: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L00544feb: { // 0x544feb: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00544fed: { // 0x544fed: ff520c CALL dword ptr [EDX + 0xc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000000cu)),5525488u); flags=s.arithmetic_flags;
  }
  L00544ff0: { // 0x544ff0: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00544ff4: { // 0x544ff4: 895d00 MOV dword ptr [EBP],EBX
    m.w32((s.bp), s.bx);
  }
  L00544ff7: { // 0x544ff7: 83c504 ADD EBP,0x4
    s.bp = integer::add(s.bp,0x00000004u,32,flags);
  }
  L00544ffa: { // 0x544ffa: 83c718 ADD EDI,0x18
    s.di = integer::add(s.di,0x00000018u,32,flags);
  }
  L00544ffd: { // 0x544ffd: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00544ffe: { // 0x544ffe: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00545002: { // 0x545002: 75e5 JNZ 0x00544fe9
    if(integer::condition("JNZ",flags)) goto L00544fe9;
  }
  L00545004: { // 0x545004: 895e14 MOV dword ptr [ESI + 0x14],EBX
    m.w32((s.si+0x00000014u), s.bx);
  }
  L00545007: { // 0x545007: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00545009: { // 0x545009: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0054500a: { // 0x54500a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0054500b: { // 0x54500b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0054500c: { // 0x54500c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0054500d: { // 0x54500d: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0054500e: { // 0x54500e: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00169980(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00569980: { // 0x569980: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00569981: { // 0x569981: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00569982: { // 0x569982: 8b74240c MOV ESI,dword ptr [ESP + 0xc]
    s.si = m.r32((f.sp+0x0000000cu));
  }
  L00569986: { // 0x569986: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00569987: { // 0x569987: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L00569989: { // 0x569989: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0056998b: { // 0x56998b: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L0056998d: { // 0x56998d: 895f04 MOV dword ptr [EDI + 0x4],EBX
    m.w32((s.di+0x00000004u), s.bx);
  }
  L00569990: { // 0x569990: 897708 MOV dword ptr [EDI + 0x8],ESI
    m.w32((s.di+0x00000008u), s.si);
  }
  L00569993: { // 0x569993: c6470c01 MOV byte ptr [EDI + 0xc],0x1
    m.w8((s.di+0x0000000cu), 0x00000001u);
  }
  L00569997: { // 0x569997: 885f0d MOV byte ptr [EDI + 0xd],BL
    m.w8((s.di+0x0000000du), (s.bx & 0xffu));
  }
  L0056999a: { // 0x56999a: c707f8097900 MOV dword ptr [EDI],0x7909f8
    m.w32((s.di), 0x007909f8u);
  }
  L005699a0: { // 0x5699a0: 0f8480000000 JZ 0x00569a26
    if(integer::condition("JZ",flags)) goto L00569a26;
  }
  L005699a6: { // 0x5699a6: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L005699aa: { // 0x5699aa: 3bd3 CMP EDX,EBX
    (void)integer::sub(s.dx,s.bx,32,flags);
  }
  L005699ac: { // 0x5699ac: 7434 JZ 0x005699e2
    if(integer::condition("JZ",flags)) goto L005699e2;
  }
  L005699ae: { // 0x5699ae: 8d4eff LEA ECX,[ESI + -0x1]
    s.cx = (s.si-0x00000001u);
  }
  L005699b1: { // 0x5699b1: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L005699b3: { // 0x5699b3: 7c22 JL 0x005699d7
    if(integer::condition("JL",flags)) goto L005699d7;
  }
  L005699b5: { // 0x5699b5: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L005699b6: { // 0x5699b6: 8d4202 LEA EAX,[EDX + 0x2]
    s.ax = (s.dx+0x00000002u);
  }
  L005699b9: { // 0x5699b9: 83ceff OR ESI,0xffffffff
    s.si = integer::logical((s.si)|(0xffffffffu),32,flags);
  }
  L005699bc: { // 0x5699bc: 668958fe MOV word ptr [EAX + -0x2],BX
    m.w16((s.ax-0x00000002u), (s.bx & 0xffffu));
  }
  L005699c0: { // 0x5699c0: 668918 MOV word ptr [EAX],BX
    m.w16((s.ax), (s.bx & 0xffffu));
  }
  L005699c3: { // 0x5699c3: 66895802 MOV word ptr [EAX + 0x2],BX
    m.w16((s.ax+0x00000002u), (s.bx & 0xffffu));
  }
  L005699c7: { // 0x5699c7: 66895804 MOV word ptr [EAX + 0x4],BX
    m.w16((s.ax+0x00000004u), (s.bx & 0xffffu));
  }
  L005699cb: { // 0x5699cb: 885806 MOV byte ptr [EAX + 0x6],BL
    m.w8((s.ax+0x00000006u), (s.bx & 0xffu));
  }
  L005699ce: { // 0x5699ce: 89700a MOV dword ptr [EAX + 0xa],ESI
    m.w32((s.ax+0x0000000au), s.si);
  }
  L005699d1: { // 0x5699d1: 83c010 ADD EAX,0x10
    s.ax = integer::add(s.ax,0x00000010u,32,flags);
  }
  L005699d4: { // 0x5699d4: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L005699d5: { // 0x5699d5: 75e5 JNZ 0x005699bc
    if(integer::condition("JNZ",flags)) goto L005699bc;
  }
  L005699d7: { // 0x5699d7: 895704 MOV dword ptr [EDI + 0x4],EDX
    m.w32((s.di+0x00000004u), s.dx);
  }
  L005699da: { // 0x5699da: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L005699dc: { // 0x5699dc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005699dd: { // 0x5699dd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005699de: { // 0x5699de: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005699df: { // 0x5699df: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L005699e2: { // 0x5699e2: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L005699e4: { // 0x5699e4: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L005699e7: { // 0x5699e7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005699e8: { // 0x5699e8: e86a3f2000 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,5675501u); flags=s.arithmetic_flags;
  }
  L005699ed: { // 0x5699ed: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L005699f0: { // 0x5699f0: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L005699f2: { // 0x5699f2: 742b JZ 0x00569a1f
    if(integer::condition("JZ",flags)) goto L00569a1f;
  }
  L005699f4: { // 0x5699f4: 8d56ff LEA EDX,[ESI + -0x1]
    s.dx = (s.si-0x00000001u);
  }
  L005699f7: { // 0x5699f7: 3bd3 CMP EDX,EBX
    (void)integer::sub(s.dx,s.bx,32,flags);
  }
  L005699f9: { // 0x5699f9: 7c22 JL 0x00569a1d
    if(integer::condition("JL",flags)) goto L00569a1d;
  }
  L005699fb: { // 0x5699fb: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L005699fc: { // 0x5699fc: 8d4802 LEA ECX,[EAX + 0x2]
    s.cx = (s.ax+0x00000002u);
  }
  L005699ff: { // 0x5699ff: 83ceff OR ESI,0xffffffff
    s.si = integer::logical((s.si)|(0xffffffffu),32,flags);
  }
  L00569a02: { // 0x569a02: 668959fe MOV word ptr [ECX + -0x2],BX
    m.w16((s.cx-0x00000002u), (s.bx & 0xffffu));
  }
  L00569a06: { // 0x569a06: 668919 MOV word ptr [ECX],BX
    m.w16((s.cx), (s.bx & 0xffffu));
  }
  L00569a09: { // 0x569a09: 66895902 MOV word ptr [ECX + 0x2],BX
    m.w16((s.cx+0x00000002u), (s.bx & 0xffffu));
  }
  L00569a0d: { // 0x569a0d: 66895904 MOV word ptr [ECX + 0x4],BX
    m.w16((s.cx+0x00000004u), (s.bx & 0xffffu));
  }
  L00569a11: { // 0x569a11: 885906 MOV byte ptr [ECX + 0x6],BL
    m.w8((s.cx+0x00000006u), (s.bx & 0xffu));
  }
  L00569a14: { // 0x569a14: 89710a MOV dword ptr [ECX + 0xa],ESI
    m.w32((s.cx+0x0000000au), s.si);
  }
  L00569a17: { // 0x569a17: 83c110 ADD ECX,0x10
    s.cx = integer::add(s.cx,0x00000010u,32,flags);
  }
  L00569a1a: { // 0x569a1a: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L00569a1b: { // 0x569a1b: 75e5 JNZ 0x00569a02
    if(integer::condition("JNZ",flags)) goto L00569a02;
  }
  L00569a1d: { // 0x569a1d: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00569a1f: { // 0x569a1f: 895f04 MOV dword ptr [EDI + 0x4],EBX
    m.w32((s.di+0x00000004u), s.bx);
  }
  L00569a22: { // 0x569a22: c6470d01 MOV byte ptr [EDI + 0xd],0x1
    m.w8((s.di+0x0000000du), 0x00000001u);
  }
  L00569a26: { // 0x569a26: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L00569a28: { // 0x569a28: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00569a29: { // 0x569a29: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00569a2a: { // 0x569a2a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00569a2b: { // 0x569a2b: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00169a30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00569a30: { // 0x569a30: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00569a31: { // 0x569a31: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00569a32: { // 0x569a32: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00569a33: { // 0x569a33: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00569a34: { // 0x569a34: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00569a35: { // 0x569a35: 8b7c2418 MOV EDI,dword ptr [ESP + 0x18]
    s.di = m.r32((f.sp+0x00000018u));
  }
  L00569a39: { // 0x569a39: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L00569a3b: { // 0x569a3b: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00569a3d: { // 0x569a3d: 896c2410 MOV dword ptr [ESP + 0x10],EBP
    m.w32((f.sp+0x00000010u), s.bp);
  }
  L00569a41: { // 0x569a41: 3bfb CMP EDI,EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  L00569a43: { // 0x569a43: 895d04 MOV dword ptr [EBP + 0x4],EBX
    m.w32((s.bp+0x00000004u), s.bx);
  }
  L00569a46: { // 0x569a46: 897d08 MOV dword ptr [EBP + 0x8],EDI
    m.w32((s.bp+0x00000008u), s.di);
  }
  L00569a49: { // 0x569a49: c6450c01 MOV byte ptr [EBP + 0xc],0x1
    m.w8((s.bp+0x0000000cu), 0x00000001u);
  }
  L00569a4d: { // 0x569a4d: 885d0d MOV byte ptr [EBP + 0xd],BL
    m.w8((s.bp+0x0000000du), (s.bx & 0xffu));
  }
  L00569a50: { // 0x569a50: c74500180a7900 MOV dword ptr [EBP],0x790a18
    m.w32((s.bp), 0x00790a18u);
  }
  L00569a57: { // 0x569a57: 0f84db000000 JZ 0x00569b38
    if(integer::condition("JZ",flags)) goto L00569b38;
  }
  L00569a5d: { // 0x569a5d: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L00569a61: { // 0x569a61: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00569a63: { // 0x569a63: 745f JZ 0x00569ac4
    if(integer::condition("JZ",flags)) goto L00569ac4;
  }
  L00569a65: { // 0x569a65: 8938 MOV dword ptr [EAX],EDI
    m.w32((s.ax), s.di);
  }
  L00569a67: { // 0x569a67: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L00569a68: { // 0x569a68: 8d7004 LEA ESI,[EAX + 0x4]
    s.si = (s.ax+0x00000004u);
  }
  L00569a6b: { // 0x569a6b: 3bfb CMP EDI,EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  L00569a6d: { // 0x569a6d: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L00569a71: { // 0x569a71: 7c44 JL 0x00569ab7
    if(integer::condition("JL",flags)) goto L00569ab7;
  }
  L00569a73: { // 0x569a73: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L00569a74: { // 0x569a74: bd0a000000 MOV EBP,0xa
    s.bp = 0x0000000au;
  }
  L00569a79: { // 0x569a79: 895e04 MOV dword ptr [ESI + 0x4],EBX
    m.w32((s.si+0x00000004u), s.bx);
  }
  L00569a7c: { // 0x569a7c: 895e08 MOV dword ptr [ESI + 0x8],EBX
    m.w32((s.si+0x00000008u), s.bx);
  }
  L00569a7f: { // 0x569a7f: c6460c01 MOV byte ptr [ESI + 0xc],0x1
    m.w8((s.si+0x0000000cu), 0x00000001u);
  }
  L00569a83: { // 0x569a83: 885e0d MOV byte ptr [ESI + 0xd],BL
    m.w8((s.si+0x0000000du), (s.bx & 0xffu));
  }
  L00569a86: { // 0x569a86: c7066c577800 MOV dword ptr [ESI],0x78576c
    m.w32((s.si), 0x0078576cu);
  }
  L00569a8c: { // 0x569a8c: c706b80a7900 MOV dword ptr [ESI],0x790ab8
    m.w32((s.si), 0x00790ab8u);
  }
  L00569a92: { // 0x569a92: 896e14 MOV dword ptr [ESI + 0x14],EBP
    m.w32((s.si+0x00000014u), s.bp);
  }
  L00569a95: { // 0x569a95: 895e10 MOV dword ptr [ESI + 0x10],EBX
    m.w32((s.si+0x00000010u), s.bx);
  }
  L00569a98: { // 0x569a98: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00569a9a: { // 0x569a9a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00569a9c: { // 0x569a9c: ff500c CALL dword ptr [EAX + 0xc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000000cu)),5675679u); flags=s.arithmetic_flags;
  }
  L00569a9f: { // 0x569a9f: 66895e18 MOV word ptr [ESI + 0x18],BX
    m.w16((s.si+0x00000018u), (s.bx & 0xffffu));
  }
  L00569aa3: { // 0x569aa3: 895e1c MOV dword ptr [ESI + 0x1c],EBX
    m.w32((s.si+0x0000001cu), s.bx);
  }
  L00569aa6: { // 0x569aa6: 895e20 MOV dword ptr [ESI + 0x20],EBX
    m.w32((s.si+0x00000020u), s.bx);
  }
  L00569aa9: { // 0x569aa9: 83c624 ADD ESI,0x24
    s.si = integer::add(s.si,0x00000024u,32,flags);
  }
  L00569aac: { // 0x569aac: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L00569aad: { // 0x569aad: 75ca JNZ 0x00569a79
    if(integer::condition("JNZ",flags)) goto L00569a79;
  }
  L00569aaf: { // 0x569aaf: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L00569ab3: { // 0x569ab3: 8b742418 MOV ESI,dword ptr [ESP + 0x18]
    s.si = m.r32((f.sp+0x00000018u));
  }
  L00569ab7: { // 0x569ab7: 897504 MOV dword ptr [EBP + 0x4],ESI
    m.w32((s.bp+0x00000004u), s.si);
  }
  L00569aba: { // 0x569aba: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00569abb: { // 0x569abb: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L00569abd: { // 0x569abd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00569abe: { // 0x569abe: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00569abf: { // 0x569abf: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00569ac0: { // 0x569ac0: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00569ac1: { // 0x569ac1: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L00569ac4: { // 0x569ac4: 8d0cff LEA ECX,[EDI + EDI*0x8]
    s.cx = (s.di+(s.di * 0x00000008u));
  }
  L00569ac7: { // 0x569ac7: 8d148d04000000 LEA EDX,[ECX*0x4 + 0x4]
    s.dx = ((s.cx * 0x00000004u)+0x00000004u);
  }
  L00569ace: { // 0x569ace: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00569acf: { // 0x569acf: e8833e2000 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,5675732u); flags=s.arithmetic_flags;
  }
  L00569ad4: { // 0x569ad4: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00569ad7: { // 0x569ad7: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00569ad9: { // 0x569ad9: 7456 JZ 0x00569b31
    if(integer::condition("JZ",flags)) goto L00569b31;
  }
  L00569adb: { // 0x569adb: 8938 MOV dword ptr [EAX],EDI
    m.w32((s.ax), s.di);
  }
  L00569add: { // 0x569add: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  L00569ae0: { // 0x569ae0: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L00569ae1: { // 0x569ae1: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00569ae5: { // 0x569ae5: 3bfb CMP EDI,EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  L00569ae7: { // 0x569ae7: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00569ae9: { // 0x569ae9: 7c44 JL 0x00569b2f
    if(integer::condition("JL",flags)) goto L00569b2f;
  }
  L00569aeb: { // 0x569aeb: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L00569aec: { // 0x569aec: bd0a000000 MOV EBP,0xa
    s.bp = 0x0000000au;
  }
  L00569af1: { // 0x569af1: 895e04 MOV dword ptr [ESI + 0x4],EBX
    m.w32((s.si+0x00000004u), s.bx);
  }
  L00569af4: { // 0x569af4: 895e08 MOV dword ptr [ESI + 0x8],EBX
    m.w32((s.si+0x00000008u), s.bx);
  }
  L00569af7: { // 0x569af7: c6460c01 MOV byte ptr [ESI + 0xc],0x1
    m.w8((s.si+0x0000000cu), 0x00000001u);
  }
  L00569afb: { // 0x569afb: 885e0d MOV byte ptr [ESI + 0xd],BL
    m.w8((s.si+0x0000000du), (s.bx & 0xffu));
  }
  L00569afe: { // 0x569afe: c7066c577800 MOV dword ptr [ESI],0x78576c
    m.w32((s.si), 0x0078576cu);
  }
  L00569b04: { // 0x569b04: c706b80a7900 MOV dword ptr [ESI],0x790ab8
    m.w32((s.si), 0x00790ab8u);
  }
  L00569b0a: { // 0x569b0a: 896e14 MOV dword ptr [ESI + 0x14],EBP
    m.w32((s.si+0x00000014u), s.bp);
  }
  L00569b0d: { // 0x569b0d: 895e10 MOV dword ptr [ESI + 0x10],EBX
    m.w32((s.si+0x00000010u), s.bx);
  }
  L00569b10: { // 0x569b10: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00569b12: { // 0x569b12: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00569b14: { // 0x569b14: ff500c CALL dword ptr [EAX + 0xc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000000cu)),5675799u); flags=s.arithmetic_flags;
  }
  L00569b17: { // 0x569b17: 66895e18 MOV word ptr [ESI + 0x18],BX
    m.w16((s.si+0x00000018u), (s.bx & 0xffffu));
  }
  L00569b1b: { // 0x569b1b: 895e1c MOV dword ptr [ESI + 0x1c],EBX
    m.w32((s.si+0x0000001cu), s.bx);
  }
  L00569b1e: { // 0x569b1e: 895e20 MOV dword ptr [ESI + 0x20],EBX
    m.w32((s.si+0x00000020u), s.bx);
  }
  L00569b21: { // 0x569b21: 83c624 ADD ESI,0x24
    s.si = integer::add(s.si,0x00000024u,32,flags);
  }
  L00569b24: { // 0x569b24: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L00569b25: { // 0x569b25: 75ca JNZ 0x00569af1
    if(integer::condition("JNZ",flags)) goto L00569af1;
  }
  L00569b27: { // 0x569b27: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L00569b2b: { // 0x569b2b: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00569b2f: { // 0x569b2f: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00569b31: { // 0x569b31: 895d04 MOV dword ptr [EBP + 0x4],EBX
    m.w32((s.bp+0x00000004u), s.bx);
  }
  L00569b34: { // 0x569b34: c6450d01 MOV byte ptr [EBP + 0xd],0x1
    m.w8((s.bp+0x0000000du), 0x00000001u);
  }
  L00569b38: { // 0x569b38: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00569b39: { // 0x569b39: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L00569b3b: { // 0x569b3b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00569b3c: { // 0x569b3c: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00569b3d: { // 0x569b3d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00569b3e: { // 0x569b3e: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00569b3f: { // 0x569b3f: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_0002d4a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0042d4a0: { // 0x42d4a0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0042d4a1: { // 0x42d4a1: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0042d4a2: { // 0x42d4a2: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  L0042d4a6: { // 0x42d4a6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0042d4a8: { // 0x42d4a8: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0042d4aa: { // 0x42d4aa: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  L0042d4b1: { // 0x42d4b1: 897e08 MOV dword ptr [ESI + 0x8],EDI
    m.w32((s.si+0x00000008u), s.di);
  }
  L0042d4b4: { // 0x42d4b4: c6460c01 MOV byte ptr [ESI + 0xc],0x1
    m.w8((s.si+0x0000000cu), 0x00000001u);
  }
  L0042d4b8: { // 0x42d4b8: c6460d00 MOV byte ptr [ESI + 0xd],0x0
    m.w8((s.si+0x0000000du), 0x00000000u);
  }
  L0042d4bc: { // 0x42d4bc: c706e0757800 MOV dword ptr [ESI],0x7875e0
    m.w32((s.si), 0x007875e0u);
  }
  L0042d4c2: { // 0x42d4c2: 7447 JZ 0x0042d50b
    if(integer::condition("JZ",flags)) goto L0042d50b;
  }
  L0042d4c4: { // 0x42d4c4: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0042d4c8: { // 0x42d4c8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0042d4ca: { // 0x42d4ca: 740f JZ 0x0042d4db
    if(integer::condition("JZ",flags)) goto L0042d4db;
  }
  L0042d4cc: { // 0x42d4cc: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L0042d4cd: { // 0x42d4cd: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  L0042d4d0: { // 0x42d4d0: 897c240c MOV dword ptr [ESP + 0xc],EDI
    m.w32((f.sp+0x0000000cu), s.di);
  }
  L0042d4d4: { // 0x42d4d4: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0042d4d6: { // 0x42d4d6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0042d4d7: { // 0x42d4d7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0042d4d8: { // 0x42d4d8: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0042d4db: { // 0x42d4db: 8d04bd00000000 LEA EAX,[EDI*0x4 + 0x0]
    s.ax = ((s.di * 0x00000004u)+0x00000000u);
  }
  L0042d4e2: { // 0x42d4e2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0042d4e3: { // 0x42d4e3: e86f043400 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,4379880u); flags=s.arithmetic_flags;
  }
  L0042d4e8: { // 0x42d4e8: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0042d4eb: { // 0x42d4eb: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0042d4ed: { // 0x42d4ed: 7413 JZ 0x0042d502
    if(integer::condition("JZ",flags)) goto L0042d502;
  }
  L0042d4ef: { // 0x42d4ef: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L0042d4f0: { // 0x42d4f0: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  L0042d4f3: { // 0x42d4f3: 897c240c MOV dword ptr [ESP + 0xc],EDI
    m.w32((f.sp+0x0000000cu), s.di);
  }
  L0042d4f7: { // 0x42d4f7: c6460d01 MOV byte ptr [ESI + 0xd],0x1
    m.w8((s.si+0x0000000du), 0x00000001u);
  }
  L0042d4fb: { // 0x42d4fb: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0042d4fd: { // 0x42d4fd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0042d4fe: { // 0x42d4fe: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0042d4ff: { // 0x42d4ff: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0042d502: { // 0x42d502: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0042d504: { // 0x42d504: c6460d01 MOV byte ptr [ESI + 0xd],0x1
    m.w8((s.si+0x0000000du), 0x00000001u);
  }
  L0042d508: { // 0x42d508: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  L0042d50b: { // 0x42d50b: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0042d50d: { // 0x42d50d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0042d50e: { // 0x42d50e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0042d50f: { // 0x42d50f: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00167930(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00567930: { // 0x567930: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00567931: { // 0x567931: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00567932: { // 0x567932: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00567933: { // 0x567933: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L00567935: { // 0x567935: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00567937: { // 0x567937: 8b4f04 MOV ECX,dword ptr [EDI + 0x4]
    s.cx = m.r32((s.di+0x00000004u));
  }
  L0056793a: { // 0x56793a: 895f10 MOV dword ptr [EDI + 0x10],EBX
    m.w32((s.di+0x00000010u), s.bx);
  }
  L0056793d: { // 0x56793d: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L0056793f: { // 0x56793f: 745d JZ 0x0056799e
    if(integer::condition("JZ",flags)) goto L0056799e;
  }
  L00567941: { // 0x567941: 385f0d CMP byte ptr [EDI + 0xd],BL
    (void)integer::sub(m.r8((s.di+0x0000000du)),(s.bx & 0xffu),8,flags);
  }
  L00567944: { // 0x567944: 7458 JZ 0x0056799e
    if(integer::condition("JZ",flags)) goto L0056799e;
  }
  L00567946: { // 0x567946: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L00567948: { // 0x567948: 7451 JZ 0x0056799b
    if(integer::condition("JZ",flags)) goto L0056799b;
  }
  L0056794a: { // 0x56794a: 8b41fc MOV EAX,dword ptr [ECX + -0x4]
    s.ax = m.r32((s.cx-0x00000004u));
  }
  L0056794d: { // 0x56794d: 8d51fc LEA EDX,[ECX + -0x4]
    s.dx = (s.cx-0x00000004u);
  }
  L00567950: { // 0x567950: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00567951: { // 0x567951: 8954240c MOV dword ptr [ESP + 0xc],EDX
    m.w32((f.sp+0x0000000cu), s.dx);
  }
  L00567955: { // 0x567955: 8d34c0 LEA ESI,[EAX + EAX*0x8]
    s.si = (s.ax+(s.ax * 0x00000008u));
  }
  L00567958: { // 0x567958: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00567959: { // 0x567959: 8d34b1 LEA ESI,[ECX + ESI*0x4]
    s.si = (s.cx+(s.si * 0x00000004u));
  }
  L0056795c: { // 0x56795c: 7833 JS 0x00567991
    if(integer::condition("JS",flags)) goto L00567991;
  }
  L0056795e: { // 0x56795e: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0056795f: { // 0x56795f: 8d6801 LEA EBP,[EAX + 0x1]
    s.bp = (s.ax+0x00000001u);
  }
  L00567962: { // 0x567962: 8b46e0 MOV EAX,dword ptr [ESI + -0x20]
    s.ax = m.r32((s.si-0x00000020u));
  }
  L00567965: { // 0x567965: 83ee24 SUB ESI,0x24
    s.si = integer::sub(s.si,0x00000024u,32,flags);
  }
  L00567968: { // 0x567968: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0056796a: { // 0x56796a: c7066c577800 MOV dword ptr [ESI],0x78576c
    m.w32((s.si), 0x0078576cu);
  }
  L00567970: { // 0x567970: 7411 JZ 0x00567983
    if(integer::condition("JZ",flags)) goto L00567983;
  }
  L00567972: { // 0x567972: 385e0d CMP byte ptr [ESI + 0xd],BL
    (void)integer::sub(m.r8((s.si+0x0000000du)),(s.bx & 0xffu),8,flags);
  }
  L00567975: { // 0x567975: 740c JZ 0x00567983
    if(integer::condition("JZ",flags)) goto L00567983;
  }
  L00567977: { // 0x567977: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00567978: { // 0x567978: e8fe5c2000 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,5667197u); flags=s.arithmetic_flags;
  }
  L0056797d: { // 0x56797d: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00567980: { // 0x567980: 895e04 MOV dword ptr [ESI + 0x4],EBX
    m.w32((s.si+0x00000004u), s.bx);
  }
  L00567983: { // 0x567983: 4d DEC EBP
    s.bp = integer::decrement(s.bp,32,flags);
  }
  L00567984: { // 0x567984: 885e0d MOV byte ptr [ESI + 0xd],BL
    m.w8((s.si+0x0000000du), (s.bx & 0xffu));
  }
  L00567987: { // 0x567987: 895e08 MOV dword ptr [ESI + 0x8],EBX
    m.w32((s.si+0x00000008u), s.bx);
  }
  L0056798a: { // 0x56798a: 75d6 JNZ 0x00567962
    if(integer::condition("JNZ",flags)) goto L00567962;
  }
  L0056798c: { // 0x56798c: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00567990: { // 0x567990: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00567991: { // 0x567991: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00567992: { // 0x567992: e8e45c2000 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,5667223u); flags=s.arithmetic_flags;
  }
  L00567997: { // 0x567997: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0056799a: { // 0x56799a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0056799b: { // 0x56799b: 895f04 MOV dword ptr [EDI + 0x4],EBX
    m.w32((s.di+0x00000004u), s.bx);
  }
  L0056799e: { // 0x56799e: 885f0d MOV byte ptr [EDI + 0xd],BL
    m.w8((s.di+0x0000000du), (s.bx & 0xffu));
  }
  L005679a1: { // 0x5679a1: 895f08 MOV dword ptr [EDI + 0x8],EBX
    m.w32((s.di+0x00000008u), s.bx);
  }
  L005679a4: { // 0x5679a4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005679a5: { // 0x5679a5: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005679a6: { // 0x5679a6: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005679a7: { // 0x5679a7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00277c20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00677c20: { // 0x00677c20: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L00677c24: { // 0x00677c24: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00677c25: { // 0x00677c25: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00677c27: { // 0x00677c27: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00677c28: { // 0x00677c28: e8c3d2ecff CALL 0x00544ef0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00544ef0u,6781997u); flags=s.arithmetic_flags;
  }
  L00677c2d: { // 0x00677c2d: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00677c2f: { // 0x00677c2f: 8886c8110000 MOV byte ptr [ESI + 0x11c8],AL
    m.w8((s.si+0x000011c8u), (s.ax & 0xffu));
  }
  L00677c35: { // 0x00677c35: 8886c9110000 MOV byte ptr [ESI + 0x11c9],AL
    m.w8((s.si+0x000011c9u), (s.ax & 0xffu));
  }
  L00677c3b: { // 0x00677c3b: 8886ca110000 MOV byte ptr [ESI + 0x11ca],AL
    m.w8((s.si+0x000011cau), (s.ax & 0xffu));
  }
  L00677c41: { // 0x00677c41: c7061c997800 MOV dword ptr [ESI],0x78991c
    m.w32((s.si), 0x0078991cu);
  }
  L00677c47: { // 0x00677c47: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00677c49: { // 0x00677c49: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00677c4a: { // 0x00677c4a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0002ce60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0042ce60: { // 0x42ce60: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0042ce61: { // 0x42ce61: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0042ce62: { // 0x42ce62: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  L0042ce66: { // 0x42ce66: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0042ce68: { // 0x42ce68: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0042ce6a: { // 0x42ce6a: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  L0042ce71: { // 0x42ce71: 897e08 MOV dword ptr [ESI + 0x8],EDI
    m.w32((s.si+0x00000008u), s.di);
  }
  L0042ce74: { // 0x42ce74: c6460c01 MOV byte ptr [ESI + 0xc],0x1
    m.w8((s.si+0x0000000cu), 0x00000001u);
  }
  L0042ce78: { // 0x42ce78: c6460d00 MOV byte ptr [ESI + 0xd],0x0
    m.w8((s.si+0x0000000du), 0x00000000u);
  }
  L0042ce7c: { // 0x42ce7c: c706e0757800 MOV dword ptr [ESI],0x7875e0
    m.w32((s.si), 0x007875e0u);
  }
  L0042ce82: { // 0x42ce82: 7436 JZ 0x0042ceba
    if(integer::condition("JZ",flags)) goto L0042ceba;
  }
  L0042ce84: { // 0x42ce84: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0042ce88: { // 0x42ce88: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0042ce8a: { // 0x42ce8a: 740a JZ 0x0042ce96
    if(integer::condition("JZ",flags)) goto L0042ce96;
  }
  L0042ce8c: { // 0x42ce8c: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L0042ce8d: { // 0x42ce8d: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  L0042ce90: { // 0x42ce90: 897c240c MOV dword ptr [ESP + 0xc],EDI
    m.w32((f.sp+0x0000000cu), s.di);
  }
  L0042ce94: { // 0x42ce94: eb24 JMP 0x0042ceba
    goto L0042ceba;
  }
  L0042ce96: { // 0x42ce96: 8d04bd00000000 LEA EAX,[EDI*0x4 + 0x0]
    s.ax = ((s.di * 0x00000004u)+0x00000000u);
  }
  L0042ce9d: { // 0x42ce9d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0042ce9e: { // 0x42ce9e: e8b40a3400 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,4378275u); flags=s.arithmetic_flags;
  }
  L0042cea3: { // 0x42cea3: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0042cea6: { // 0x42cea6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0042cea8: { // 0x42cea8: 7407 JZ 0x0042ceb1
    if(integer::condition("JZ",flags)) goto L0042ceb1;
  }
  L0042ceaa: { // 0x42ceaa: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L0042ceab: { // 0x42ceab: 897c240c MOV dword ptr [ESP + 0xc],EDI
    m.w32((f.sp+0x0000000cu), s.di);
  }
  L0042ceaf: { // 0x42ceaf: eb02 JMP 0x0042ceb3
    goto L0042ceb3;
  }
  L0042ceb1: { // 0x42ceb1: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0042ceb3: { // 0x42ceb3: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  L0042ceb6: { // 0x42ceb6: c6460d01 MOV byte ptr [ESI + 0xd],0x1
    m.w8((s.si+0x0000000du), 0x00000001u);
  }
  L0042ceba: { // 0x42ceba: c706a0757800 MOV dword ptr [ESI],0x7875a0
    m.w32((s.si), 0x007875a0u);
  }
  L0042cec0: { // 0x42cec0: c746140a000000 MOV dword ptr [ESI + 0x14],0xa
    m.w32((s.si+0x00000014u), 0x0000000au);
  }
  L0042cec7: { // 0x42cec7: c7461000000000 MOV dword ptr [ESI + 0x10],0x0
    m.w32((s.si+0x00000010u), 0x00000000u);
  }
  L0042cece: { // 0x42cece: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0042ced0: { // 0x42ced0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0042ced1: { // 0x42ced1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0042ced2: { // 0x42ced2: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00277cb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00677cb0: { // 0x677cb0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00677cb1: { // 0x677cb1: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00677cb2: { // 0x677cb2: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  L00677cb6: { // 0x677cb6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00677cb8: { // 0x677cb8: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L00677cba: { // 0x677cba: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  L00677cc1: { // 0x677cc1: 897e08 MOV dword ptr [ESI + 0x8],EDI
    m.w32((s.si+0x00000008u), s.di);
  }
  L00677cc4: { // 0x677cc4: c6460c01 MOV byte ptr [ESI + 0xc],0x1
    m.w8((s.si+0x0000000cu), 0x00000001u);
  }
  L00677cc8: { // 0x677cc8: c6460d00 MOV byte ptr [ESI + 0xd],0x0
    m.w8((s.si+0x0000000du), 0x00000000u);
  }
  L00677ccc: { // 0x677ccc: c7069c1f7900 MOV dword ptr [ESI],0x791f9c
    m.w32((s.si), 0x00791f9cu);
  }
  L00677cd2: { // 0x677cd2: 7436 JZ 0x00677d0a
    if(integer::condition("JZ",flags)) goto L00677d0a;
  }
  L00677cd4: { // 0x677cd4: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00677cd8: { // 0x677cd8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00677cda: { // 0x677cda: 740a JZ 0x00677ce6
    if(integer::condition("JZ",flags)) goto L00677ce6;
  }
  L00677cdc: { // 0x677cdc: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L00677cdd: { // 0x677cdd: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  L00677ce0: { // 0x677ce0: 897c240c MOV dword ptr [ESP + 0xc],EDI
    m.w32((f.sp+0x0000000cu), s.di);
  }
  L00677ce4: { // 0x677ce4: eb24 JMP 0x00677d0a
    goto L00677d0a;
  }
  L00677ce6: { // 0x677ce6: 8d04fd00000000 LEA EAX,[EDI*0x8 + 0x0]
    s.ax = ((s.di * 0x00000008u)+0x00000000u);
  }
  L00677ced: { // 0x677ced: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00677cee: { // 0x677cee: e8645c0f00 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,6782195u); flags=s.arithmetic_flags;
  }
  L00677cf3: { // 0x677cf3: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00677cf6: { // 0x677cf6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00677cf8: { // 0x677cf8: 7407 JZ 0x00677d01
    if(integer::condition("JZ",flags)) goto L00677d01;
  }
  L00677cfa: { // 0x677cfa: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L00677cfb: { // 0x677cfb: 897c240c MOV dword ptr [ESP + 0xc],EDI
    m.w32((f.sp+0x0000000cu), s.di);
  }
  L00677cff: { // 0x677cff: eb02 JMP 0x00677d03
    goto L00677d03;
  }
  L00677d01: { // 0x677d01: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00677d03: { // 0x677d03: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  L00677d06: { // 0x677d06: c6460d01 MOV byte ptr [ESI + 0xd],0x1
    m.w8((s.si+0x0000000du), 0x00000001u);
  }
  L00677d0a: { // 0x677d0a: c7067c1f7900 MOV dword ptr [ESI],0x791f7c
    m.w32((s.si), 0x00791f7cu);
  }
  L00677d10: { // 0x677d10: c746140a000000 MOV dword ptr [ESI + 0x14],0xa
    m.w32((s.si+0x00000014u), 0x0000000au);
  }
  L00677d17: { // 0x677d17: c7461000000000 MOV dword ptr [ESI + 0x10],0x0
    m.w32((s.si+0x00000010u), 0x00000000u);
  }
  L00677d1e: { // 0x677d1e: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00677d20: { // 0x677d20: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00677d21: { // 0x677d21: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00677d22: { // 0x677d22: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_000dd870(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004dd870: { // 0x004dd870: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004dd871: { // 0x004dd871: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004dd873: { // 0x004dd873: 8d4e04 LEA ECX,[ESI + 0x4]
    s.cx = (s.si+0x00000004u);
  }
  L004dd876: { // 0x004dd876: e855221b00 CALL 0x0068fad0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0068fad0u,5101691u); flags=s.arithmetic_flags;
  }
  L004dd87b: { // 0x004dd87b: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  L004dd87d: { // 0x004dd87d: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L004dd881: { // 0x004dd881: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  L004dd884: { // 0x004dd884: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004dd886: { // 0x004dd886: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004dd887: { // 0x004dd887: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0028fad0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0068fad0: { // 0x0068fad0: ff1524557800 CALL dword ptr [0x00785524]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((0x00785524u)),6879958u); flags=s.arithmetic_flags;
  }
  L0068fad6: { // 0x0068fad6: c1e804 SHR EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::right);
  }
  L0068fad9: { // 0x0068fad9: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00005bf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00405bf0: { // 0x405bf0: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00405bf2: { // 0x405bf2: c7410cec928100 MOV dword ptr [ECX + 0xc],0x8192ec
    m.w32((s.cx+0x0000000cu), 0x008192ecu);
  }
  L00405bf9: { // 0x405bf9: 8901 MOV dword ptr [ECX],EAX
    m.w32((s.cx), s.ax);
  }
  L00405bfb: { // 0x405bfb: 894104 MOV dword ptr [ECX + 0x4],EAX
    m.w32((s.cx+0x00000004u), s.ax);
  }
  L00405bfe: { // 0x405bfe: 894108 MOV dword ptr [ECX + 0x8],EAX
    m.w32((s.cx+0x00000008u), s.ax);
  }
  L00405c01: { // 0x405c01: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0000aed0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0040aed0: { // 0x0040aed0: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L0040aed4: { // 0x0040aed4: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0040aed5: { // 0x0040aed5: 7820 JS 0x0040aef7
    if(integer::condition("JS",flags)) goto L0040aef7;
  }
  L0040aed7: { // 0x0040aed7: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0040aed8: { // 0x0040aed8: 8b5c2414 MOV EBX,dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  L0040aedc: { // 0x0040aedc: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0040aedd: { // 0x0040aedd: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L0040aee1: { // 0x0040aee1: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0040aee2: { // 0x0040aee2: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L0040aee6: { // 0x0040aee6: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0040aee7: { // 0x0040aee7: 8d7801 LEA EDI,[EAX + 0x1]
    s.di = (s.ax+0x00000001u);
  }
  L0040aeea: { // 0x0040aeea: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0040aeec: { // 0x0040aeec: ffd3 CALL EBX
    s.arithmetic_flags=flags; invoke(m,s,f,s.bx,4239086u); flags=s.arithmetic_flags;
  }
  L0040aeee: { // 0x0040aeee: 03f5 ADD ESI,EBP
    s.si = integer::add(s.si,s.bp,32,flags);
  }
  L0040aef0: { // 0x0040aef0: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L0040aef1: { // 0x0040aef1: 75f7 JNZ 0x0040aeea
    if(integer::condition("JNZ",flags)) goto L0040aeea;
  }
  L0040aef3: { // 0x0040aef3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0040aef4: { // 0x0040aef4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0040aef5: { // 0x0040aef5: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0040aef6: { // 0x0040aef6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0040aef7: { // 0x0040aef7: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
}
void f_00277bb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00677bb0: { // 0x677bb0: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L00677bb2: { // 0x677bb2: 33c9 XOR ECX, ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00677bb4: { // 0x677bb4: 894814 MOV dword ptr [EAX + 0x14], ECX
    m.w32((s.ax+0x00000014u), s.cx);
  }
  L00677bb7: { // 0x677bb7: 8b156c89a200 MOV EDX, dword ptr [0xa2896c]
    s.dx = m.r32((0x00a2896cu));
  }
  L00677bbd: { // 0x677bbd: 895018 MOV dword ptr [EAX + 0x18], EDX
    m.w32((s.ax+0x00000018u), s.dx);
  }
  L00677bc0: { // 0x677bc0: 894820 MOV dword ptr [EAX + 0x20], ECX
    m.w32((s.ax+0x00000020u), s.cx);
  }
  L00677bc3: { // 0x677bc3: 894824 MOV dword ptr [EAX + 0x24], ECX
    m.w32((s.ax+0x00000024u), s.cx);
  }
  L00677bc6: { // 0x677bc6: c7402801000000 MOV dword ptr [EAX + 0x28], 1
    m.w32((s.ax+0x00000028u), 1u);
  }
  L00677bcd: { // 0x677bcd: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 5525232u:f_00144ef0(m,s,child,{});break;
case 5675392u:f_00169980(m,s,child,{});break;
case 5675568u:f_00169a30(m,s,child,{});break;
case 4379808u:f_0002d4a0(m,s,child,{});break;
case 5667120u:f_00167930(m,s,child,{});break;
case 6781984u:f_00277c20(m,s,child,{});break;
case 4378208u:f_0002ce60(m,s,child,{});break;
case 6782128u:f_00277cb0(m,s,child,{});break;
case 5101680u:f_000dd870(m,s,child,{});break;
case 6879952u:f_0028fad0(m,s,child,{});break;
case 4217840u:f_00005bf0(m,s,child,{});break;
case 4239056u:f_0000aed0(m,s,child,{});break;
case 6781872u:f_00277bb0(m,s,child,{});break;
default:{if(target!=ra2::platform::ticks636::Tick::address())throw std::domain_error("636 unreviewed API");s.ax=ra2::platform::ticks636::Tick::get();child.sp+=4;break;}}
f.sp=child.sp;
}
}

std::uint32_t fun_00671130(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00671130: { // 0x671130: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L00671134: { // 0x671134: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00671135: { // 0x671135: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00671136: { // 0x671136: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00671137: { // 0x671137: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00671138: { // 0x671138: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0067113a: { // 0x67113a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0067113b: { // 0x67113b: e8e06a0000 CALL 0x00677c20
    s.arithmetic_flags=flags; invoke(m,s,f,0x00677c20u,6754624u); flags=s.arithmetic_flags;
  }
  L00671140: { // 0x671140: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L00671142: { // 0x671142: 8d8f20120000 LEA ECX,[EDI + 0x1220]
    s.cx = (s.di+0x00001220u);
  }
  L00671148: { // 0x671148: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00671149: { // 0x671149: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0067114a: { // 0x67114a: e811bddbff CALL 0x0042ce60
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042ce60u,6754639u); flags=s.arithmetic_flags;
  }
  L0067114f: { // 0x67114f: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00671150: { // 0x671150: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00671151: { // 0x671151: 8d8f58120000 LEA ECX,[EDI + 0x1258]
    s.cx = (s.di+0x00001258u);
  }
  L00671157: { // 0x671157: e8546b0000 CALL 0x00677cb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00677cb0u,6754652u); flags=s.arithmetic_flags;
  }
  L0067115c: { // 0x67115c: 8db774120000 LEA ESI,[EDI + 0x1274]
    s.si = (s.di+0x00001274u);
  }
  L00671162: { // 0x671162: bb16000000 MOV EBX,0x16
    s.bx = 0x00000016u;
  }
  L00671167: { // 0x671167: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00671168: { // 0x671168: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00671169: { // 0x671169: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0067116b: { // 0x67116b: e8406b0000 CALL 0x00677cb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00677cb0u,6754672u); flags=s.arithmetic_flags;
  }
  L00671170: { // 0x671170: 83c618 ADD ESI,0x18
    s.si = integer::add(s.si,0x00000018u,32,flags);
  }
  L00671173: { // 0x671173: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L00671174: { // 0x671174: 75f1 JNZ 0x00671167
    if(integer::condition("JNZ",flags)) goto L00671167;
  }
  L00671176: { // 0x671176: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00671177: { // 0x671177: 8d8ffc140000 LEA ECX,[EDI + 0x14fc]
    s.cx = (s.di+0x000014fcu);
  }
  L0067117d: { // 0x67117d: e8eec6e6ff CALL 0x004dd870
    s.arithmetic_flags=flags; invoke(m,s,f,0x004dd870u,6754690u); flags=s.arithmetic_flags;
  }
  L00671182: { // 0x671182: 8d8fbc140000 LEA ECX,[EDI + 0x14bc]
    s.cx = (s.di+0x000014bcu);
  }
  L00671188: { // 0x671188: c707dc367900 MOV dword ptr [EDI],0x7936dc
    m.w32((s.di), 0x007936dcu);
  }
  L0067118e: { // 0x67118e: e85d4ad9ff CALL 0x00405bf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00405bf0u,6754707u); flags=s.arithmetic_flags;
  }
  L00671193: { // 0x671193: 8d8f20150000 LEA ECX,[EDI + 0x1520]
    s.cx = (s.di+0x00001520u);
  }
  L00671199: { // 0x671199: e832e90100 CALL 0x0068fad0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0068fad0u,6754718u); flags=s.arithmetic_flags;
  }
  L0067119e: { // 0x67119e: 89871c150000 MOV dword ptr [EDI + 0x151c],EAX
    m.w32((s.di+0x0000151cu), s.ax);
  }
  L006711a4: { // 0x6711a4: 89af24150000 MOV dword ptr [EDI + 0x1524],EBP
    m.w32((s.di+0x00001524u), s.bp);
  }
  L006711aa: { // 0x6711aa: c707ec327900 MOV dword ptr [EDI],0x7932ec
    m.w32((s.di), 0x007932ecu);
  }
  L006711b0: { // 0x6711b0: 8db740150000 LEA ESI,[EDI + 0x1540]
    s.si = (s.di+0x00001540u);
  }
  L006711b6: { // 0x6711b6: bb04000000 MOV EBX,0x4
    s.bx = 0x00000004u;
  }
  L006711bb: { // 0x6711bb: 892e MOV dword ptr [ESI],EBP
    m.w32((s.si), s.bp);
  }
  L006711bd: { // 0x6711bd: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  L006711c3: { // 0x6711c3: 68b07b6700 PUSH 0x677bb0
    f.push(m,0x00677bb0u);
  }
  L006711c8: { // 0x6711c8: 6a4b PUSH 0x4b
    f.push(m,0x0000004bu);
  }
  L006711ca: { // 0x6711ca: 8d5654 LEA EDX,[ESI + 0x54]
    s.dx = (s.si+0x00000054u);
  }
  L006711cd: { // 0x6711cd: 6a30 PUSH 0x30
    f.push(m,0x00000030u);
  }
  L006711cf: { // 0x6711cf: 894e04 MOV dword ptr [ESI + 0x4],ECX
    m.w32((s.si+0x00000004u), s.cx);
  }
  L006711d2: { // 0x6711d2: 896e0c MOV dword ptr [ESI + 0xc],EBP
    m.w32((s.si+0x0000000cu), s.bp);
  }
  L006711d5: { // 0x6711d5: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006711d6: { // 0x6711d6: 896e10 MOV dword ptr [ESI + 0x10],EBP
    m.w32((s.si+0x00000010u), s.bp);
  }
  L006711d9: { // 0x6711d9: c7461401000000 MOV dword ptr [ESI + 0x14],0x1
    m.w32((s.si+0x00000014u), 0x00000001u);
  }
  L006711e0: { // 0x6711e0: e8eb9cd9ff CALL 0x0040aed0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0040aed0u,6754789u); flags=s.arithmetic_flags;
  }
  L006711e5: { // 0x6711e5: 81c6640e0000 ADD ESI,0xe64
    s.si = integer::add(s.si,0x00000e64u,32,flags);
  }
  L006711eb: { // 0x6711eb: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L006711ec: { // 0x6711ec: 75cd JNZ 0x006711bb
    if(integer::condition("JNZ",flags)) goto L006711bb;
  }
  L006711ee: { // 0x6711ee: c707b0627900 MOV dword ptr [EDI],0x7962b0
    m.w32((s.di), 0x007962b0u);
  }
  L006711f4: { // 0x6711f4: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L006711f6: { // 0x6711f6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006711f7: { // 0x6711f7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006711f8: { // 0x6711f8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006711f9: { // 0x6711f9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006711fa: { // 0x6711fa: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
