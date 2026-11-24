#include "recovered/recovery_b825_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b825 {
namespace {
void f_00020d90(Memory&,State&,Frame&,const Operations&);
void f_000226a0(Memory&,State&,Frame&,const Operations&);
void f_001cb3a0(Memory&,State&,Frame&,const Operations&);
void f_00099870(Memory&,State&,Frame&,const Operations&);
void f_00099820(Memory&,State&,Frame&,const Operations&);
void f_00132b00(Memory&,State&,Frame&,const Operations&);
void f_00132be0(Memory&,State&,Frame&,const Operations&);
void f_001cd4d0(Memory&,State&,Frame&,const Operations&);
void f_001cd850(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_00020d90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00420d90: { // 0x420d90: 83ec18 SUB ESP, 0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
  L00420d93: { // 0x420d93: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00420d94: { // 0x420d94: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00420d95: { // 0x420d95: 8bf9 MOV EDI, ECX
    s.di = s.cx;
  }
  L00420d97: { // 0x420d97: 8b87b4000000 MOV EAX, dword ptr [EDI + 0xb4]
    s.ax = m.r32((s.di+0x000000b4u));
  }
  L00420d9d: { // 0x420d9d: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00420d9f: { // 0x420d9f: 7448 JZ 0x420de9
    if(integer::condition("JZ",flags)) goto L00420de9;
  }
  L00420da1: { // 0x420da1: 8d442408 LEA EAX, [ESP + 8]
    s.ax = (f.sp+8u);
  }
  L00420da5: { // 0x420da5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00420da6: { // 0x420da6: e825c71a00 CALL 0x5cd4d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005cd4d0u,4328875u); flags=s.arithmetic_flags;
  }
  L00420dab: { // 0x420dab: 8b8fb4000000 MOV ECX, dword ptr [EDI + 0xb4]
    s.cx = m.r32((s.di+0x000000b4u));
  }
  L00420db1: { // 0x420db1: 8bf0 MOV ESI, EAX
    s.si = s.ax;
  }
  L00420db3: { // 0x420db3: 8d442414 LEA EAX, [ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L00420db7: { // 0x420db7: 8b11 MOV EDX, dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00420db9: { // 0x420db9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00420dba: { // 0x420dba: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),4328893u); flags=s.arithmetic_flags;
  }
  L00420dbd: { // 0x420dbd: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00420dbf: { // 0x420dbf: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00420dc1: { // 0x420dc1: 8b7804 MOV EDI, dword ptr [EAX + 4]
    s.di = m.r32((s.ax+4u));
  }
  L00420dc4: { // 0x420dc4: 03ca ADD ECX, EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L00420dc6: { // 0x420dc6: 8b5604 MOV EDX, dword ptr [ESI + 4]
    s.dx = m.r32((s.si+4u));
  }
  L00420dc9: { // 0x420dc9: 8b7608 MOV ESI, dword ptr [ESI + 8]
    s.si = m.r32((s.si+8u));
  }
  L00420dcc: { // 0x420dcc: 03d7 ADD EDX, EDI
    s.dx = integer::add(s.dx,s.di,32,flags);
  }
  L00420dce: { // 0x420dce: 8b7808 MOV EDI, dword ptr [EAX + 8]
    s.di = m.r32((s.ax+8u));
  }
  L00420dd1: { // 0x420dd1: 8b442424 MOV EAX, dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L00420dd5: { // 0x420dd5: 03f7 ADD ESI, EDI
    s.si = integer::add(s.si,s.di,32,flags);
  }
  L00420dd7: { // 0x420dd7: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L00420dd9: { // 0x420dd9: 890f MOV dword ptr [EDI], ECX
    m.w32((s.di), s.cx);
  }
  L00420ddb: { // 0x420ddb: 895704 MOV dword ptr [EDI + 4], EDX
    m.w32((s.di+4u), s.dx);
  }
  L00420dde: { // 0x420dde: 897708 MOV dword ptr [EDI + 8], ESI
    m.w32((s.di+8u), s.si);
  }
  L00420de1: { // 0x420de1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00420de2: { // 0x420de2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00420de3: { // 0x420de3: 83c418 ADD ESP, 0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L00420de6: { // 0x420de6: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00420de9: { // 0x420de9: 8d4c2414 LEA ECX, [ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L00420ded: { // 0x420ded: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00420dee: { // 0x420dee: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L00420df0: { // 0x420df0: e8dbc61a00 CALL 0x5cd4d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005cd4d0u,4328949u); flags=s.arithmetic_flags;
  }
  L00420df5: { // 0x420df5: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L00420df7: { // 0x420df7: 8b442424 MOV EAX, dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L00420dfb: { // 0x420dfb: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L00420dfd: { // 0x420dfd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00420dfe: { // 0x420dfe: 8b32 MOV ESI, dword ptr [EDX]
    s.si = m.r32((s.dx));
  }
  L00420e00: { // 0x420e00: 8931 MOV dword ptr [ECX], ESI
    m.w32((s.cx), s.si);
  }
  L00420e02: { // 0x420e02: 8b7204 MOV ESI, dword ptr [EDX + 4]
    s.si = m.r32((s.dx+4u));
  }
  L00420e05: { // 0x420e05: 897104 MOV dword ptr [ECX + 4], ESI
    m.w32((s.cx+4u), s.si);
  }
  L00420e08: { // 0x420e08: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00420e09: { // 0x420e09: 8b5208 MOV EDX, dword ptr [EDX + 8]
    s.dx = m.r32((s.dx+8u));
  }
  L00420e0c: { // 0x420e0c: 895108 MOV dword ptr [ECX + 8], EDX
    m.w32((s.cx+8u), s.dx);
  }
  L00420e0f: { // 0x420e0f: 83c418 ADD ESP, 0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L00420e12: { // 0x420e12: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000226a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004226a0: { // 0x4226a0: 8b81b4000000 MOV EAX, dword ptr [ECX + 0xb4]
    s.ax = m.r32((s.cx+0x000000b4u));
  }
  L004226a6: { // 0x4226a6: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004226a8: { // 0x4226a8: 7406 JZ 0x4226b0
    if(integer::condition("JZ",flags)) goto L004226b0;
  }
  L004226aa: { // 0x4226aa: b802000000 MOV EAX, 2
    s.ax = 2u;
  }
  L004226af: { // 0x4226af: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004226b0: { // 0x4226b0: 8b81b0000000 MOV EAX, dword ptr [ECX + 0xb0]
    s.ax = m.r32((s.cx+0x000000b0u));
  }
  L004226b6: { // 0x4226b6: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004226b8: { // 0x4226b8: 7407 JZ 0x4226c1
    if(integer::condition("JZ",flags)) goto L004226c1;
  }
  L004226ba: { // 0x4226ba: 8b8020030000 MOV EAX, dword ptr [EAX + 0x320]
    s.ax = m.r32((s.ax+0x00000320u));
  }
  L004226c0: { // 0x4226c0: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004226c1: { // 0x4226c1: b803000000 MOV EAX, 3
    s.ax = 3u;
  }
  L004226c6: { // 0x4226c6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_001cb3a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005cb3a0: { // 0x5cb3a0: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00099870(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00499870: { // 0x499870: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00499871: { // 0x499871: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00499872: { // 0x499872: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  L00499876: { // 0x499876: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L00499878: { // 0x499878: 0f84b8000000 JZ 0x00499936
    if(integer::condition("JZ",flags)) goto L00499936;
  }
  L0049987e: { // 0x49987e: 8b8780000000 MOV EAX,dword ptr [EDI + 0x80]
    s.ax = m.r32((s.di+0x00000080u));
  }
  L00499884: { // 0x499884: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00499887: { // 0x499887: 0f84a9000000 JZ 0x00499936
    if(integer::condition("JZ",flags)) goto L00499936;
  }
  L0049988d: { // 0x49988d: 8d0440 LEA EAX,[EAX + EAX*0x2]
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  L00499890: { // 0x499890: 897c240c MOV dword ptr [ESP + 0xc],EDI
    m.w32((f.sp+0x0000000cu), s.di);
  }
  L00499894: { // 0x499894: 8b14c5a8a88300 MOV EDX,dword ptr [EAX*0x8 + 0x83a8a8]
    s.dx = m.r32(((s.ax * 0x00000008u)+0x0083a8a8u));
  }
  L0049989b: { // 0x49989b: 8d34c5a8a88300 LEA ESI,[EAX*0x8 + 0x83a8a8]
    s.si = ((s.ax * 0x00000008u)+0x0083a8a8u);
  }
  L004998a2: { // 0x4998a2: 8d44240c LEA EAX,[ESP + 0xc]
    s.ax = (f.sp+0x0000000cu);
  }
  L004998a6: { // 0x4998a6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004998a8: { // 0x4998a8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004998a9: { // 0x4998a9: ff5210 CALL dword ptr [EDX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000010u)),4823212u); flags=s.arithmetic_flags;
  }
  L004998ac: { // 0x4998ac: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L004998af: { // 0x4998af: 742b JZ 0x004998dc
    if(integer::condition("JZ",flags)) goto L004998dc;
  }
  L004998b1: { // 0x4998b1: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    s.cx = m.r32((s.si+0x00000010u));
  }
  L004998b4: { // 0x4998b4: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L004998b6: { // 0x4998b6: 7d24 JGE 0x004998dc
    if(integer::condition("JGE",flags)) goto L004998dc;
  }
  L004998b8: { // 0x4998b8: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L004998b9: { // 0x4998b9: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L004998bb: { // 0x4998bb: 894e10 MOV dword ptr [ESI + 0x10],ECX
    m.w32((s.si+0x00000010u), s.cx);
  }
  L004998be: { // 0x4998be: 7d12 JGE 0x004998d2
    if(integer::condition("JGE",flags)) goto L004998d2;
  }
  L004998c0: { // 0x4998c0: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  L004998c3: { // 0x4998c3: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004998c4: { // 0x4998c4: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L004998c7: { // 0x4998c7: 895481fc MOV dword ptr [ECX + EAX*0x4 + -0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)-0x00000004u), s.dx);
  }
  L004998cb: { // 0x4998cb: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    s.cx = m.r32((s.si+0x00000010u));
  }
  L004998ce: { // 0x4998ce: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L004998d0: { // 0x4998d0: 7cee JL 0x004998c0
    if(integer::condition("JL",flags)) goto L004998c0;
  }
  L004998d2: { // 0x4998d2: c78780000000ffffffff MOV dword ptr [EDI + 0x80],0xffffffff
    m.w32((s.di+0x00000080u), 0xffffffffu);
  }
  L004998dc: { // 0x4998dc: 83bf80000000ff CMP dword ptr [EDI + 0x80],-0x1
    (void)integer::sub(m.r32((s.di+0x00000080u)),0xffffffffu,32,flags);
  }
  L004998e3: { // 0x4998e3: 7451 JZ 0x00499936
    if(integer::condition("JZ",flags)) goto L00499936;
  }
  L004998e5: { // 0x4998e5: beb8a88300 MOV ESI,0x83a8b8
    s.si = 0x0083a8b8u;
  }
  L004998ea: { // 0x4998ea: 8b46f0 MOV EAX,dword ptr [ESI + -0x10]
    s.ax = m.r32((s.si-0x00000010u));
  }
  L004998ed: { // 0x4998ed: 8d4ef0 LEA ECX,[ESI + -0x10]
    s.cx = (s.si-0x00000010u);
  }
  L004998f0: { // 0x4998f0: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  L004998f4: { // 0x4998f4: 897c240c MOV dword ptr [ESP + 0xc],EDI
    m.w32((f.sp+0x0000000cu), s.di);
  }
  L004998f8: { // 0x4998f8: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004998f9: { // 0x4998f9: ff5010 CALL dword ptr [EAX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000010u)),4823292u); flags=s.arithmetic_flags;
  }
  L004998fc: { // 0x4998fc: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L004998ff: { // 0x4998ff: 7420 JZ 0x00499921
    if(integer::condition("JZ",flags)) goto L00499921;
  }
  L00499901: { // 0x499901: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L00499903: { // 0x499903: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00499905: { // 0x499905: 7d1a JGE 0x00499921
    if(integer::condition("JGE",flags)) goto L00499921;
  }
  L00499907: { // 0x499907: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00499908: { // 0x499908: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0049990a: { // 0x49990a: 890e MOV dword ptr [ESI],ECX
    m.w32((s.si), s.cx);
  }
  L0049990c: { // 0x49990c: 7ddc JGE 0x004998ea
    if(integer::condition("JGE",flags)) goto L004998ea;
  }
  L0049990e: { // 0x49990e: 8b4ef4 MOV ECX,dword ptr [ESI + -0xc]
    s.cx = m.r32((s.si-0x0000000cu));
  }
  L00499911: { // 0x499911: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00499912: { // 0x499912: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L00499915: { // 0x499915: 895481fc MOV dword ptr [ECX + EAX*0x4 + -0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)-0x00000004u), s.dx);
  }
  L00499919: { // 0x499919: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0049991b: { // 0x49991b: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0049991d: { // 0x49991d: 7cef JL 0x0049990e
    if(integer::condition("JL",flags)) goto L0049990e;
  }
  L0049991f: { // 0x49991f: ebc9 JMP 0x004998ea
    goto L004998ea;
  }
  L00499921: { // 0x499921: 83c618 ADD ESI,0x18
    s.si = integer::add(s.si,0x00000018u,32,flags);
  }
  L00499924: { // 0x499924: 81fe30a98300 CMP ESI,0x83a930
    (void)integer::sub(s.si,0x0083a930u,32,flags);
  }
  L0049992a: { // 0x49992a: 7cbe JL 0x004998ea
    if(integer::condition("JL",flags)) goto L004998ea;
  }
  L0049992c: { // 0x49992c: c78780000000ffffffff MOV dword ptr [EDI + 0x80],0xffffffff
    m.w32((s.di+0x00000080u), 0xffffffffu);
  }
  L00499936: { // 0x499936: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00499937: { // 0x499937: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00499938: { // 0x499938: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00099820(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00499820: { // 0x499820: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00499821: { // 0x499821: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  L00499825: { // 0x499825: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00499827: { // 0x499827: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00499828: { // 0x499828: 743e JZ 0x00499868
    if(integer::condition("JZ",flags)) goto L00499868;
  }
  L0049982a: { // 0x49982a: 83be80000000ff CMP dword ptr [ESI + 0x80],-0x1
    (void)integer::sub(m.r32((s.si+0x00000080u)),0xffffffffu,32,flags);
  }
  L00499831: { // 0x499831: 7406 JZ 0x00499839
    if(integer::condition("JZ",flags)) goto L00499839;
  }
  L00499833: { // 0x499833: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00499834: { // 0x499834: e837000000 CALL 0x00499870
    s.arithmetic_flags=flags; invoke(m,s,f,0x00499870u,4823097u); flags=s.arithmetic_flags;
  }
  L00499839: { // 0x499839: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0049983b: { // 0x49983b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0049983d: { // 0x49983d: ff5074 CALL dword ptr [EAX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000074u)),4823104u); flags=s.arithmetic_flags;
  }
  L00499840: { // 0x499840: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00499842: { // 0x499842: 83ffff CMP EDI,-0x1
    (void)integer::sub(s.di,0xffffffffu,32,flags);
  }
  L00499845: { // 0x499845: 7421 JZ 0x00499868
    if(integer::condition("JZ",flags)) goto L00499868;
  }
  L00499847: { // 0x499847: 83ff02 CMP EDI,0x2
    (void)integer::sub(s.di,0x00000002u,32,flags);
  }
  L0049984a: { // 0x49984a: 8d147f LEA EDX,[EDI + EDI*0x2]
    s.dx = (s.di+(s.di * 0x00000002u));
  }
  L0049984d: { // 0x49984d: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L00499850: { // 0x499850: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00499851: { // 0x499851: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00499852: { // 0x499852: 8d0cd5a8a88300 LEA ECX,[EDX*0x8 + 0x83a8a8]
    s.cx = ((s.dx * 0x00000008u)+0x0083a8a8u);
  }
  L00499859: { // 0x499859: e8a2920900 CALL 0x00532b00
    s.arithmetic_flags=flags; invoke(m,s,f,0x00532b00u,4823134u); flags=s.arithmetic_flags;
  }
  L0049985e: { // 0x49985e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00499860: { // 0x499860: 7406 JZ 0x00499868
    if(integer::condition("JZ",flags)) goto L00499868;
  }
  L00499862: { // 0x499862: 89be80000000 MOV dword ptr [ESI + 0x80],EDI
    m.w32((s.si+0x00000080u), s.di);
  }
  L00499868: { // 0x499868: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00499869: { // 0x499869: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049986a: { // 0x49986a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00132b00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00532b00: { // 0x532b00: 8a442408 MOV AL,byte ptr [ESP + 0x8]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000008u)));
  }
  L00532b04: { // 0x532b04: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00532b05: { // 0x532b05: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00532b07: { // 0x532b07: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00532b09: { // 0x532b09: 7414 JZ 0x00532b1f
    if(integer::condition("JZ",flags)) goto L00532b1f;
  }
  L00532b0b: { // 0x532b0b: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L00532b0f: { // 0x532b0f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00532b10: { // 0x532b10: e8cb000000 CALL 0x00532be0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00532be0u,5450517u); flags=s.arithmetic_flags;
  }
  L00532b15: { // 0x532b15: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L00532b17: { // 0x532b17: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  L00532b19: { // 0x532b19: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00532b1a: { // 0x532b1a: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L00532b1c: { // 0x532b1c: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L00532b1f: { // 0x532b1f: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L00532b22: { // 0x532b22: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L00532b25: { // 0x532b25: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00532b27: { // 0x532b27: 7c31 JL 0x00532b5a
    if(integer::condition("JL",flags)) goto L00532b5a;
  }
  L00532b29: { // 0x532b29: 8a460d MOV AL,byte ptr [ESI + 0xd]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000000du)));
  }
  L00532b2c: { // 0x532b2c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00532b2e: { // 0x532b2e: 7504 JNZ 0x00532b34
    if(integer::condition("JNZ",flags)) goto L00532b34;
  }
  L00532b30: { // 0x532b30: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00532b32: { // 0x532b32: 7517 JNZ 0x00532b4b
    if(integer::condition("JNZ",flags)) goto L00532b4b;
  }
  L00532b34: { // 0x532b34: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  L00532b37: { // 0x532b37: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00532b39: { // 0x532b39: 7e10 JLE 0x00532b4b
    if(integer::condition("JLE",flags)) goto L00532b4b;
  }
  L00532b3b: { // 0x532b3b: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00532b3d: { // 0x532b3d: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00532b3f: { // 0x532b3f: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00532b41: { // 0x532b41: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00532b42: { // 0x532b42: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00532b44: { // 0x532b44: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),5450567u); flags=s.arithmetic_flags;
  }
  L00532b47: { // 0x532b47: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00532b49: { // 0x532b49: 750f JNZ 0x00532b5a
    if(integer::condition("JNZ",flags)) goto L00532b5a;
  }
  L00532b4b: { // 0x532b4b: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00532b4d: { // 0x532b4d: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00532b4f: { // 0x532b4f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00532b51: { // 0x532b51: 0f95c2 SETNZ DL
    s.dx = with_al(s.dx, (integer::condition("SETNZ",flags)?1u:0u));
  }
  L00532b54: { // 0x532b54: 8ac2 MOV AL,DL
    s.ax = with_al(s.ax, (s.dx & 0xffu));
  }
  L00532b56: { // 0x532b56: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00532b57: { // 0x532b57: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L00532b5a: { // 0x532b5a: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L00532b5d: { // 0x532b5d: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  L00532b60: { // 0x532b60: 8d4801 LEA ECX,[EAX + 0x1]
    s.cx = (s.ax+0x00000001u);
  }
  L00532b63: { // 0x532b63: 894e10 MOV dword ptr [ESI + 0x10],ECX
    m.w32((s.si+0x00000010u), s.cx);
  }
  L00532b66: { // 0x532b66: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  L00532b6a: { // 0x532b6a: 890c82 MOV dword ptr [EDX + EAX*0x4],ECX
    m.w32((s.dx+(s.ax * 0x00000004u)), s.cx);
  }
  L00532b6d: { // 0x532b6d: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00532b6f: { // 0x532b6f: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00532b71: { // 0x532b71: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00532b72: { // 0x532b72: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00532b74: { // 0x532b74: 0f95c2 SETNZ DL
    s.dx = with_al(s.dx, (integer::condition("SETNZ",flags)?1u:0u));
  }
  L00532b77: { // 0x532b77: 8ac2 MOV AL,DL
    s.ax = with_al(s.ax, (s.dx & 0xffu));
  }
  L00532b79: { // 0x532b79: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00132be0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00532be0: { // 0x532be0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00532be1: { // 0x532be1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00532be3: { // 0x532be3: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L00532be6: { // 0x532be6: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L00532be9: { // 0x532be9: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00532beb: { // 0x532beb: 7c28 JL 0x00532c15
    if(integer::condition("JL",flags)) goto L00532c15;
  }
  L00532bed: { // 0x532bed: 8a460d MOV AL,byte ptr [ESI + 0xd]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000000du)));
  }
  L00532bf0: { // 0x532bf0: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00532bf2: { // 0x532bf2: 7504 JNZ 0x00532bf8
    if(integer::condition("JNZ",flags)) goto L00532bf8;
  }
  L00532bf4: { // 0x532bf4: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00532bf6: { // 0x532bf6: 7517 JNZ 0x00532c0f
    if(integer::condition("JNZ",flags)) goto L00532c0f;
  }
  L00532bf8: { // 0x532bf8: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  L00532bfb: { // 0x532bfb: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00532bfd: { // 0x532bfd: 7e10 JLE 0x00532c0f
    if(integer::condition("JLE",flags)) goto L00532c0f;
  }
  L00532bff: { // 0x532bff: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00532c01: { // 0x532c01: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00532c03: { // 0x532c03: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00532c05: { // 0x532c05: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00532c06: { // 0x532c06: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00532c08: { // 0x532c08: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),5450763u); flags=s.arithmetic_flags;
  }
  L00532c0b: { // 0x532c0b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00532c0d: { // 0x532c0d: 7506 JNZ 0x00532c15
    if(integer::condition("JNZ",flags)) goto L00532c15;
  }
  L00532c0f: { // 0x532c0f: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00532c11: { // 0x532c11: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00532c12: { // 0x532c12: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00532c15: { // 0x532c15: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L00532c18: { // 0x532c18: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00532c19: { // 0x532c19: 8b5c240c MOV EBX,dword ptr [ESP + 0xc]
    s.bx = m.r32((f.sp+0x0000000cu));
  }
  L00532c1d: { // 0x532c1d: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00532c1e: { // 0x532c1e: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00532c20: { // 0x532c20: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00532c22: { // 0x532c22: 7e18 JLE 0x00532c3c
    if(integer::condition("JLE",flags)) goto L00532c3c;
  }
  L00532c24: { // 0x532c24: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L00532c27: { // 0x532c27: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00532c28: { // 0x532c28: 8b0cb8 MOV ECX,dword ptr [EAX + EDI*0x4]
    s.cx = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  L00532c2b: { // 0x532c2b: e840a50900 CALL 0x005cd170
    s.arithmetic_flags=flags; invoke(m,s,f,0x005cd170u,5450800u); flags=s.arithmetic_flags;
  }
  L00532c30: { // 0x532c30: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00532c32: { // 0x532c32: 7508 JNZ 0x00532c3c
    if(integer::condition("JNZ",flags)) goto L00532c3c;
  }
  L00532c34: { // 0x532c34: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L00532c37: { // 0x532c37: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L00532c38: { // 0x532c38: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L00532c3a: { // 0x532c3a: 7ce8 JL 0x00532c24
    if(integer::condition("JL",flags)) goto L00532c24;
  }
  L00532c3c: { // 0x532c3c: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L00532c3f: { // 0x532c3f: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00532c40: { // 0x532c40: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L00532c42: { // 0x532c42: 7c10 JL 0x00532c54
    if(integer::condition("JL",flags)) goto L00532c54;
  }
  L00532c44: { // 0x532c44: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  L00532c47: { // 0x532c47: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00532c48: { // 0x532c48: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L00532c4a: { // 0x532c4a: 8b548104 MOV EDX,dword ptr [ECX + EAX*0x4 + 0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)+0x00000004u));
  }
  L00532c4e: { // 0x532c4e: 89548108 MOV dword ptr [ECX + EAX*0x4 + 0x8],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)+0x00000008u), s.dx);
  }
  L00532c52: { // 0x532c52: 7df0 JGE 0x00532c44
    if(integer::condition("JGE",flags)) goto L00532c44;
  }
  L00532c54: { // 0x532c54: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L00532c57: { // 0x532c57: 891cb8 MOV dword ptr [EAX + EDI*0x4],EBX
    m.w32((s.ax+(s.di * 0x00000004u)), s.bx);
  }
  L00532c5a: { // 0x532c5a: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L00532c5d: { // 0x532c5d: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00532c5e: { // 0x532c5e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00532c5f: { // 0x532c5f: 894610 MOV dword ptr [ESI + 0x10],EAX
    m.w32((s.si+0x00000010u), s.ax);
  }
  L00532c62: { // 0x532c62: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00532c63: { // 0x532c63: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L00532c68: { // 0x532c68: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00532c69: { // 0x532c69: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_001cd4d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005cd4d0: { // 0x5cd4d0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L005cd4d4: { // 0x5cd4d4: 81c188000000 ADD ECX,0x88
    s.cx = integer::add(s.cx,0x00000088u,32,flags);
  }
  L005cd4da: { // 0x5cd4da: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005cd4db: { // 0x5cd4db: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L005cd4dd: { // 0x5cd4dd: 8b31 MOV ESI,dword ptr [ECX]
    s.si = m.r32((s.cx));
  }
  L005cd4df: { // 0x5cd4df: 8932 MOV dword ptr [EDX],ESI
    m.w32((s.dx), s.si);
  }
  L005cd4e1: { // 0x5cd4e1: 8b7104 MOV ESI,dword ptr [ECX + 0x4]
    s.si = m.r32((s.cx+0x00000004u));
  }
  L005cd4e4: { // 0x5cd4e4: 897204 MOV dword ptr [EDX + 0x4],ESI
    m.w32((s.dx+0x00000004u), s.si);
  }
  L005cd4e7: { // 0x5cd4e7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005cd4e8: { // 0x5cd4e8: 8b4908 MOV ECX,dword ptr [ECX + 0x8]
    s.cx = m.r32((s.cx+0x00000008u));
  }
  L005cd4eb: { // 0x5cd4eb: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  L005cd4ee: { // 0x5cd4ee: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_001cd850(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005cd850: { // 0x5cd850: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L005cd854: { // 0x5cd854: 81c188000000 ADD ECX,0x88
    s.cx = integer::add(s.cx,0x00000088u,32,flags);
  }
  L005cd85a: { // 0x5cd85a: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L005cd85c: { // 0x5cd85c: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  L005cd85e: { // 0x5cd85e: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L005cd861: { // 0x5cd861: 895104 MOV dword ptr [ECX + 0x4],EDX
    m.w32((s.cx+0x00000004u), s.dx);
  }
  L005cd864: { // 0x5cd864: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L005cd867: { // 0x5cd867: 894108 MOV dword ptr [ECX + 0x8],EAX
    m.w32((s.cx+0x00000008u), s.ax);
  }
  L005cd86a: { // 0x5cd86a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4328848u:f_00020d90(m,s,child,{});break;
case 4335264u:f_000226a0(m,s,child,{});break;
case 6075296u:f_001cb3a0(m,s,child,{});break;
case 4823152u:f_00099870(m,s,child,{});break;
case 4823072u:f_00099820(m,s,child,{});break;
case 5450496u:f_00132b00(m,s,child,{});break;
case 5450720u:f_00132be0(m,s,child,{});break;
case 6083792u:f_001cd4d0(m,s,child,{});break;
case 6084688u:f_001cd850(m,s,child,{});break;
default:throw std::domain_error("recovery825 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00422540(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00422540: { // 0x422540: 83ec24 SUB ESP,0x24
    f.sp = integer::sub(f.sp,0x00000024u,32,flags);
  }
  L00422543: { // 0x422543: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00422544: { // 0x422544: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00422545: { // 0x422545: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00422546: { // 0x422546: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00422548: { // 0x422548: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00422549: { // 0x422549: 8baeb4000000 MOV EBP,dword ptr [ESI + 0xb4]
    s.bp = m.r32((s.si+0x000000b4u));
  }
  L0042254f: { // 0x42254f: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L00422551: { // 0x422551: 0f849b000000 JZ 0x004225f2
    if(integer::condition("JZ",flags)) goto L004225f2;
  }
  L00422557: { // 0x422557: 8a5e74 MOV BL,byte ptr [ESI + 0x74]
    s.bx = with_al(s.bx, m.r8((s.si+0x00000074u)));
  }
  L0042255a: { // 0x42255a: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L0042255c: { // 0x42255c: 740b JZ 0x00422569
    if(integer::condition("JZ",flags)) goto L00422569;
  }
  L0042255e: { // 0x42255e: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0042255f: { // 0x42255f: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00422564: { // 0x422564: e807730700 CALL 0x00499870
    s.arithmetic_flags=flags; invoke(m,s,f,0x00499870u,4334953u); flags=s.arithmetic_flags;
  }
  L00422569: { // 0x422569: 8b3dc085a200 MOV EDI,dword ptr [0x00a285c0]
    s.di = m.r32((0x00a285c0u));
  }
  L0042256f: { // 0x42256f: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00422571: { // 0x422571: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L00422573: { // 0x422573: 7e22 JLE 0x00422597
    if(integer::condition("JLE",flags)) goto L00422597;
  }
  L00422575: { // 0x422575: 8b15b485a200 MOV EDX,dword ptr [0x00a285b4]
    s.dx = m.r32((0x00a285b4u));
  }
  L0042257b: { // 0x42257b: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L0042257d: { // 0x42257d: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L0042257f: { // 0x42257f: 740e JZ 0x0042258f
    if(integer::condition("JZ",flags)) goto L0042258f;
  }
  L00422581: { // 0x422581: 8b80b4000000 MOV EAX,dword ptr [EAX + 0xb4]
    s.ax = m.r32((s.ax+0x000000b4u));
  }
  L00422587: { // 0x422587: 3b86b4000000 CMP EAX,dword ptr [ESI + 0xb4]
    (void)integer::sub(s.ax,m.r32((s.si+0x000000b4u)),32,flags);
  }
  L0042258d: { // 0x42258d: 7408 JZ 0x00422597
    if(integer::condition("JZ",flags)) goto L00422597;
  }
  L0042258f: { // 0x42258f: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00422590: { // 0x422590: 83c204 ADD EDX,0x4
    s.dx = integer::add(s.dx,0x00000004u,32,flags);
  }
  L00422593: { // 0x422593: 3bcf CMP ECX,EDI
    (void)integer::sub(s.cx,s.di,32,flags);
  }
  L00422595: { // 0x422595: 7ce4 JL 0x0042257b
    if(integer::condition("JL",flags)) goto L0042257b;
  }
  L00422597: { // 0x422597: 3bcf CMP ECX,EDI
    (void)integer::sub(s.cx,s.di,32,flags);
  }
  L00422599: { // 0x422599: 750f JNZ 0x004225aa
    if(integer::condition("JNZ",flags)) goto L004225aa;
  }
  L0042259b: { // 0x42259b: 8b5500 MOV EDX,dword ptr [EBP]
    s.dx = m.r32((s.bp));
  }
  L0042259e: { // 0x42259e: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L004225a0: { // 0x4225a0: ff9264010000 CALL dword ptr [EDX + 0x164]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000164u)),4335014u); flags=s.arithmetic_flags;
  }
  L004225a6: { // 0x4225a6: c6457800 MOV byte ptr [EBP + 0x78],0x0
    m.w8((s.bp+0x00000078u), 0x00000000u);
  }
  L004225aa: { // 0x4225aa: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004225ac: { // 0x4225ac: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L004225b0: { // 0x4225b0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004225b1: { // 0x4225b1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004225b3: { // 0x4225b3: ff5048 CALL dword ptr [EAX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000048u)),4335030u); flags=s.arithmetic_flags;
  }
  L004225b6: { // 0x4225b6: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L004225b8: { // 0x4225b8: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L004225bc: { // 0x4225bc: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L004225bf: { // 0x4225bf: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L004225c3: { // 0x4225c3: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L004225c7: { // 0x4225c7: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L004225ca: { // 0x4225ca: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004225cc: { // 0x4225cc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004225cd: { // 0x4225cd: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004225cf: { // 0x4225cf: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L004225d3: { // 0x4225d3: c786b400000000000000 MOV dword ptr [ESI + 0xb4],0x0
    m.w32((s.si+0x000000b4u), 0x00000000u);
  }
  L004225dd: { // 0x4225dd: ff909c010000 CALL dword ptr [EAX + 0x19c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000019cu)),4335075u); flags=s.arithmetic_flags;
  }
  L004225e3: { // 0x4225e3: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L004225e5: { // 0x4225e5: 740b JZ 0x004225f2
    if(integer::condition("JZ",flags)) goto L004225f2;
  }
  L004225e7: { // 0x4225e7: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004225e8: { // 0x4225e8: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L004225ed: { // 0x4225ed: e82e720700 CALL 0x00499820
    s.arithmetic_flags=flags; invoke(m,s,f,0x00499820u,4335090u); flags=s.arithmetic_flags;
  }
  L004225f2: { // 0x4225f2: 8b7c2438 MOV EDI,dword ptr [ESP + 0x38]
    s.di = m.r32((f.sp+0x00000038u));
  }
  L004225f6: { // 0x4225f6: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L004225f8: { // 0x4225f8: 7471 JZ 0x0042266b
    if(integer::condition("JZ",flags)) goto L0042266b;
  }
  L004225fa: { // 0x4225fa: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004225fc: { // 0x4225fc: 8d44241c LEA EAX,[ESP + 0x1c]
    s.ax = (f.sp+0x0000001cu);
  }
  L00422600: { // 0x422600: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00422601: { // 0x422601: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00422603: { // 0x422603: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),4335110u); flags=s.arithmetic_flags;
  }
  L00422606: { // 0x422606: 8b18 MOV EBX,dword ptr [EAX]
    s.bx = m.r32((s.ax));
  }
  L00422608: { // 0x422608: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00422609: { // 0x422609: 8b6804 MOV EBP,dword ptr [EAX + 0x4]
    s.bp = m.r32((s.ax+0x00000004u));
  }
  L0042260c: { // 0x42260c: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L0042260f: { // 0x42260f: 894c2428 MOV dword ptr [ESP + 0x28],ECX
    m.w32((f.sp+0x00000028u), s.cx);
  }
  L00422613: { // 0x422613: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00422618: { // 0x422618: e853720700 CALL 0x00499870
    s.arithmetic_flags=flags; invoke(m,s,f,0x00499870u,4335133u); flags=s.arithmetic_flags;
  }
  L0042261d: { // 0x42261d: c6477801 MOV byte ptr [EDI + 0x78],0x1
    m.w8((s.di+0x00000078u), 0x00000001u);
  }
  L00422621: { // 0x422621: 89beb4000000 MOV dword ptr [ESI + 0xb4],EDI
    m.w32((s.si+0x000000b4u), s.di);
  }
  L00422627: { // 0x422627: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L00422629: { // 0x422629: 8d442428 LEA EAX,[ESP + 0x28]
    s.ax = (f.sp+0x00000028u);
  }
  L0042262d: { // 0x42262d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0042262e: { // 0x42262e: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00422630: { // 0x422630: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),4335155u); flags=s.arithmetic_flags;
  }
  L00422633: { // 0x422633: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00422635: { // 0x422635: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L00422638: { // 0x422638: 8b7804 MOV EDI,dword ptr [EAX + 0x4]
    s.di = m.r32((s.ax+0x00000004u));
  }
  L0042263b: { // 0x42263b: 2bd9 SUB EBX,ECX
    s.bx = integer::sub(s.bx,s.cx,32,flags);
  }
  L0042263d: { // 0x42263d: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L00422641: { // 0x422641: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L00422645: { // 0x422645: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L00422647: { // 0x422647: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00422649: { // 0x422649: 2bef SUB EBP,EDI
    s.bp = integer::sub(s.bp,s.di,32,flags);
  }
  L0042264b: { // 0x42264b: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0042264f: { // 0x42264f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00422650: { // 0x422650: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00422652: { // 0x422652: 895c2414 MOV dword ptr [ESP + 0x14],EBX
    m.w32((f.sp+0x00000014u), s.bx);
  }
  L00422656: { // 0x422656: 896c2418 MOV dword ptr [ESP + 0x18],EBP
    m.w32((f.sp+0x00000018u), s.bp);
  }
  L0042265a: { // 0x42265a: ff929c010000 CALL dword ptr [EDX + 0x19c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000019cu)),4335200u); flags=s.arithmetic_flags;
  }
  L00422660: { // 0x422660: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00422661: { // 0x422661: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00422666: { // 0x422666: e8b5710700 CALL 0x00499820
    s.arithmetic_flags=flags; invoke(m,s,f,0x00499820u,4335211u); flags=s.arithmetic_flags;
  }
  L0042266b: { // 0x42266b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0042266c: { // 0x42266c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0042266d: { // 0x42266d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0042266e: { // 0x42266e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0042266f: { // 0x42266f: 83c424 ADD ESP,0x24
    f.sp = integer::add(f.sp,0x00000024u,32,flags);
  }
  L00422672: { // 0x422672: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
