#include "recovered/recovery_b643_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b643 {
namespace {
void f_001ca970(Memory&,State&,Frame&,const Operations&);
void f_0000ff10(Memory&,State&,Frame&,const Operations&);
void f_00005bf0(Memory&,State&,Frame&,const Operations&);
void f_00219cf0(Memory&,State&,Frame&,const Operations&);
void f_001cde80(Memory&,State&,Frame&,const Operations&);
void f_00010580(Memory&,State&,Frame&,const Operations&);
void f_0036dd10(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_001ca970(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005ca970: { // 0x5ca970: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005ca971: { // 0x5ca971: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005ca972: { // 0x5ca972: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L005ca974: { // 0x5ca974: e89755e4ff CALL 0x0040ff10
    s.arithmetic_flags=flags; invoke(m,s,f,0x0040ff10u,6072697u); flags=s.arithmetic_flags;
  }
  L005ca979: { // 0x5ca979: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L005ca97b: { // 0x5ca97b: b8ff000000 MOV EAX,0xff
    s.ax = 0x000000ffu;
  }
  L005ca980: { // 0x5ca980: 895e24 MOV dword ptr [ESI + 0x24],EBX
    m.w32((s.si+0x00000024u), s.bx);
  }
  L005ca983: { // 0x5ca983: 895e28 MOV dword ptr [ESI + 0x28],EBX
    m.w32((s.si+0x00000028u), s.bx);
  }
  L005ca986: { // 0x5ca986: 895e2c MOV dword ptr [ESI + 0x2c],EBX
    m.w32((s.si+0x0000002cu), s.bx);
  }
  L005ca989: { // 0x5ca989: 89466c MOV dword ptr [ESI + 0x6c],EAX
    m.w32((s.si+0x0000006cu), s.ax);
  }
  L005ca98c: { // 0x5ca98c: 894670 MOV dword ptr [ESI + 0x70],EAX
    m.w32((s.si+0x00000070u), s.ax);
  }
  L005ca98f: { // 0x5ca98f: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L005ca991: { // 0x5ca991: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  L005ca994: { // 0x5ca994: 884676 MOV byte ptr [ESI + 0x76],AL
    m.w8((s.si+0x00000076u), (s.ax & 0xffu));
  }
  L005ca997: { // 0x5ca997: 88467d MOV byte ptr [ESI + 0x7d],AL
    m.w8((s.si+0x0000007du), (s.ax & 0xffu));
  }
  L005ca99a: { // 0x5ca99a: 888685000000 MOV byte ptr [ESI + 0x85],AL
    m.w8((s.si+0x00000085u), (s.ax & 0xffu));
  }
  L005ca9a0: { // 0x5ca9a0: 895e30 MOV dword ptr [ESI + 0x30],EBX
    m.w32((s.si+0x00000030u), s.bx);
  }
  L005ca9a3: { // 0x5ca9a3: 895e34 MOV dword ptr [ESI + 0x34],EBX
    m.w32((s.si+0x00000034u), s.bx);
  }
  L005ca9a6: { // 0x5ca9a6: 895e38 MOV dword ptr [ESI + 0x38],EBX
    m.w32((s.si+0x00000038u), s.bx);
  }
  L005ca9a9: { // 0x5ca9a9: 894e64 MOV dword ptr [ESI + 0x64],ECX
    m.w32((s.si+0x00000064u), s.cx);
  }
  L005ca9ac: { // 0x5ca9ac: 885e68 MOV byte ptr [ESI + 0x68],BL
    m.w8((s.si+0x00000068u), (s.bx & 0xffu));
  }
  L005ca9af: { // 0x5ca9af: 885e74 MOV byte ptr [ESI + 0x74],BL
    m.w8((s.si+0x00000074u), (s.bx & 0xffu));
  }
  L005ca9b2: { // 0x5ca9b2: 885e75 MOV byte ptr [ESI + 0x75],BL
    m.w8((s.si+0x00000075u), (s.bx & 0xffu));
  }
  L005ca9b5: { // 0x5ca9b5: 885e77 MOV byte ptr [ESI + 0x77],BL
    m.w8((s.si+0x00000077u), (s.bx & 0xffu));
  }
  L005ca9b8: { // 0x5ca9b8: 885e78 MOV byte ptr [ESI + 0x78],BL
    m.w8((s.si+0x00000078u), (s.bx & 0xffu));
  }
  L005ca9bb: { // 0x5ca9bb: 885e79 MOV byte ptr [ESI + 0x79],BL
    m.w8((s.si+0x00000079u), (s.bx & 0xffu));
  }
  L005ca9be: { // 0x5ca9be: 885e7a MOV byte ptr [ESI + 0x7a],BL
    m.w8((s.si+0x0000007au), (s.bx & 0xffu));
  }
  L005ca9c1: { // 0x5ca9c1: 885e7b MOV byte ptr [ESI + 0x7b],BL
    m.w8((s.si+0x0000007bu), (s.bx & 0xffu));
  }
  L005ca9c4: { // 0x5ca9c4: 885e7c MOV byte ptr [ESI + 0x7c],BL
    m.w8((s.si+0x0000007cu), (s.bx & 0xffu));
  }
  L005ca9c7: { // 0x5ca9c7: 898e80000000 MOV dword ptr [ESI + 0x80],ECX
    m.w32((s.si+0x00000080u), s.cx);
  }
  L005ca9cd: { // 0x5ca9cd: 889e84000000 MOV byte ptr [ESI + 0x84],BL
    m.w8((s.si+0x00000084u), (s.bx & 0xffu));
  }
  L005ca9d3: { // 0x5ca9d3: 8b0d68aaa500 MOV ECX,dword ptr [0x00a5aa68]
    s.cx = m.r32((0x00a5aa68u));
  }
  L005ca9d9: { // 0x5ca9d9: 8d8688000000 LEA EAX,[ESI + 0x88]
    s.ax = (s.si+0x00000088u);
  }
  L005ca9df: { // 0x5ca9df: 898e88000000 MOV dword ptr [ESI + 0x88],ECX
    m.w32((s.si+0x00000088u), s.cx);
  }
  L005ca9e5: { // 0x5ca9e5: 8b156caaa500 MOV EDX,dword ptr [0x00a5aa6c]
    s.dx = m.r32((0x00a5aa6cu));
  }
  L005ca9eb: { // 0x5ca9eb: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
  L005ca9ee: { // 0x5ca9ee: 8b0d70aaa500 MOV ECX,dword ptr [0x00a5aa70]
    s.cx = m.r32((0x00a5aa70u));
  }
  L005ca9f4: { // 0x5ca9f4: 899e94000000 MOV dword ptr [ESI + 0x94],EBX
    m.w32((s.si+0x00000094u), s.bx);
  }
  L005ca9fa: { // 0x5ca9fa: c70658247900 MOV dword ptr [ESI],0x792458
    m.w32((s.si), 0x00792458u);
  }
  L005caa00: { // 0x5caa00: 894808 MOV dword ptr [EAX + 0x8],ECX
    m.w32((s.ax+0x00000008u), s.cx);
  }
  L005caa03: { // 0x5caa03: 8d4e3c LEA ECX,[ESI + 0x3c]
    s.cx = (s.si+0x0000003cu);
  }
  L005caa06: { // 0x5caa06: c746043c247900 MOV dword ptr [ESI + 0x4],0x79243c
    m.w32((s.si+0x00000004u), 0x0079243cu);
  }
  L005caa0d: { // 0x5caa0d: c7460834247900 MOV dword ptr [ESI + 0x8],0x792434
    m.w32((s.si+0x00000008u), 0x00792434u);
  }
  L005caa14: { // 0x5caa14: c7460c2c247900 MOV dword ptr [ESI + 0xc],0x79242c
    m.w32((s.si+0x0000000cu), 0x0079242cu);
  }
  L005caa1b: { // 0x5caa1b: e8d0b1e3ff CALL 0x00405bf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00405bf0u,6072864u); flags=s.arithmetic_flags;
  }
  L005caa20: { // 0x5caa20: 8d4e50 LEA ECX,[ESI + 0x50]
    s.cx = (s.si+0x00000050u);
  }
  L005caa23: { // 0x5caa23: e8c8b1e3ff CALL 0x00405bf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00405bf0u,6072872u); flags=s.arithmetic_flags;
  }
  L005caa28: { // 0x5caa28: a1c07fa200 MOV EAX,[0x00a27fc0]
    s.ax = m.r32((0x00a27fc0u));
  }
  L005caa2d: { // 0x5caa2d: 8b0dc87fa200 MOV ECX,dword ptr [0x00a27fc8]
    s.cx = m.r32((0x00a27fc8u));
  }
  L005caa33: { // 0x5caa33: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L005caa35: { // 0x5caa35: 7c2c JL 0x005caa63
    if(integer::condition("JL",flags)) goto L005caa63;
  }
  L005caa37: { // 0x5caa37: 381dc57fa200 CMP byte ptr [0x00a27fc5],BL
    (void)integer::sub(m.r8((0x00a27fc5u)),(s.bx & 0xffu),8,flags);
  }
  L005caa3d: { // 0x5caa3d: 7504 JNZ 0x005caa43
    if(integer::condition("JNZ",flags)) goto L005caa43;
  }
  L005caa3f: { // 0x5caa3f: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L005caa41: { // 0x5caa41: 7538 JNZ 0x005caa7b
    if(integer::condition("JNZ",flags)) goto L005caa7b;
  }
  L005caa43: { // 0x5caa43: 8b0dcc7fa200 MOV ECX,dword ptr [0x00a27fcc]
    s.cx = m.r32((0x00a27fccu));
  }
  L005caa49: { // 0x5caa49: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L005caa4b: { // 0x5caa4b: 7e2e JLE 0x005caa7b
    if(integer::condition("JLE",flags)) goto L005caa7b;
  }
  L005caa4d: { // 0x5caa4d: 8b15b87fa200 MOV EDX,dword ptr [0x00a27fb8]
    s.dx = m.r32((0x00a27fb8u));
  }
  L005caa53: { // 0x5caa53: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L005caa55: { // 0x5caa55: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005caa56: { // 0x5caa56: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005caa57: { // 0x5caa57: b9b87fa200 MOV ECX,0xa27fb8
    s.cx = 0x00a27fb8u;
  }
  L005caa5c: { // 0x5caa5c: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),6072927u); flags=s.arithmetic_flags;
  }
  L005caa5f: { // 0x5caa5f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005caa61: { // 0x5caa61: 7418 JZ 0x005caa7b
    if(integer::condition("JZ",flags)) goto L005caa7b;
  }
  L005caa63: { // 0x5caa63: 8b0dc87fa200 MOV ECX,dword ptr [0x00a27fc8]
    s.cx = m.r32((0x00a27fc8u));
  }
  L005caa69: { // 0x5caa69: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L005caa6b: { // 0x5caa6b: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L005caa6c: { // 0x5caa6c: 890dc87fa200 MOV dword ptr [0x00a27fc8],ECX
    m.w32((0x00a27fc8u), s.cx);
  }
  L005caa72: { // 0x5caa72: 8b0dbc7fa200 MOV ECX,dword ptr [0x00a27fbc]
    s.cx = m.r32((0x00a27fbcu));
  }
  L005caa78: { // 0x5caa78: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L005caa7b: { // 0x5caa7b: a17088aa00 MOV EAX,[0x00aa8870]
    s.ax = m.r32((0x00aa8870u));
  }
  L005caa80: { // 0x5caa80: 8b0d7888aa00 MOV ECX,dword ptr [0x00aa8878]
    s.cx = m.r32((0x00aa8878u));
  }
  L005caa86: { // 0x5caa86: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L005caa88: { // 0x5caa88: 7c2c JL 0x005caab6
    if(integer::condition("JL",flags)) goto L005caab6;
  }
  L005caa8a: { // 0x5caa8a: 381d7588aa00 CMP byte ptr [0x00aa8875],BL
    (void)integer::sub(m.r8((0x00aa8875u)),(s.bx & 0xffu),8,flags);
  }
  L005caa90: { // 0x5caa90: 7504 JNZ 0x005caa96
    if(integer::condition("JNZ",flags)) goto L005caa96;
  }
  L005caa92: { // 0x5caa92: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L005caa94: { // 0x5caa94: 7538 JNZ 0x005caace
    if(integer::condition("JNZ",flags)) goto L005caace;
  }
  L005caa96: { // 0x5caa96: 8b0d7c88aa00 MOV ECX,dword ptr [0x00aa887c]
    s.cx = m.r32((0x00aa887cu));
  }
  L005caa9c: { // 0x5caa9c: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L005caa9e: { // 0x5caa9e: 7e2e JLE 0x005caace
    if(integer::condition("JLE",flags)) goto L005caace;
  }
  L005caaa0: { // 0x5caaa0: 8b156888aa00 MOV EDX,dword ptr [0x00aa8868]
    s.dx = m.r32((0x00aa8868u));
  }
  L005caaa6: { // 0x5caaa6: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L005caaa8: { // 0x5caaa8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005caaa9: { // 0x5caaa9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005caaaa: { // 0x5caaaa: b96888aa00 MOV ECX,0xaa8868
    s.cx = 0x00aa8868u;
  }
  L005caaaf: { // 0x5caaaf: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),6073010u); flags=s.arithmetic_flags;
  }
  L005caab2: { // 0x5caab2: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005caab4: { // 0x5caab4: 7418 JZ 0x005caace
    if(integer::condition("JZ",flags)) goto L005caace;
  }
  L005caab6: { // 0x5caab6: 8b0d7888aa00 MOV ECX,dword ptr [0x00aa8878]
    s.cx = m.r32((0x00aa8878u));
  }
  L005caabc: { // 0x5caabc: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L005caabe: { // 0x5caabe: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L005caabf: { // 0x5caabf: 890d7888aa00 MOV dword ptr [0x00aa8878],ECX
    m.w32((0x00aa8878u), s.cx);
  }
  L005caac5: { // 0x5caac5: 8b0d6c88aa00 MOV ECX,dword ptr [0x00aa886c]
    s.cx = m.r32((0x00aa886cu));
  }
  L005caacb: { // 0x5caacb: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L005caace: { // 0x5caace: a1c087aa00 MOV EAX,[0x00aa87c0]
    s.ax = m.r32((0x00aa87c0u));
  }
  L005caad3: { // 0x5caad3: 8b0dc887aa00 MOV ECX,dword ptr [0x00aa87c8]
    s.cx = m.r32((0x00aa87c8u));
  }
  L005caad9: { // 0x5caad9: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L005caadb: { // 0x5caadb: 7c2c JL 0x005cab09
    if(integer::condition("JL",flags)) goto L005cab09;
  }
  L005caadd: { // 0x5caadd: 381dc587aa00 CMP byte ptr [0x00aa87c5],BL
    (void)integer::sub(m.r8((0x00aa87c5u)),(s.bx & 0xffu),8,flags);
  }
  L005caae3: { // 0x5caae3: 7504 JNZ 0x005caae9
    if(integer::condition("JNZ",flags)) goto L005caae9;
  }
  L005caae5: { // 0x5caae5: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L005caae7: { // 0x5caae7: 7538 JNZ 0x005cab21
    if(integer::condition("JNZ",flags)) goto L005cab21;
  }
  L005caae9: { // 0x5caae9: 8b0dcc87aa00 MOV ECX,dword ptr [0x00aa87cc]
    s.cx = m.r32((0x00aa87ccu));
  }
  L005caaef: { // 0x5caaef: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L005caaf1: { // 0x5caaf1: 7e2e JLE 0x005cab21
    if(integer::condition("JLE",flags)) goto L005cab21;
  }
  L005caaf3: { // 0x5caaf3: 8b15b887aa00 MOV EDX,dword ptr [0x00aa87b8]
    s.dx = m.r32((0x00aa87b8u));
  }
  L005caaf9: { // 0x5caaf9: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L005caafb: { // 0x5caafb: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005caafc: { // 0x5caafc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005caafd: { // 0x5caafd: b9b887aa00 MOV ECX,0xaa87b8
    s.cx = 0x00aa87b8u;
  }
  L005cab02: { // 0x5cab02: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),6073093u); flags=s.arithmetic_flags;
  }
  L005cab05: { // 0x5cab05: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cab07: { // 0x5cab07: 7418 JZ 0x005cab21
    if(integer::condition("JZ",flags)) goto L005cab21;
  }
  L005cab09: { // 0x5cab09: 8b0dc887aa00 MOV ECX,dword ptr [0x00aa87c8]
    s.cx = m.r32((0x00aa87c8u));
  }
  L005cab0f: { // 0x5cab0f: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L005cab11: { // 0x5cab11: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L005cab12: { // 0x5cab12: 890dc887aa00 MOV dword ptr [0x00aa87c8],ECX
    m.w32((0x00aa87c8u), s.cx);
  }
  L005cab18: { // 0x5cab18: 8b0dbc87aa00 MOV ECX,dword ptr [0x00aa87bc]
    s.cx = m.r32((0x00aa87bcu));
  }
  L005cab1e: { // 0x5cab1e: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L005cab21: { // 0x5cab21: a16887aa00 MOV EAX,[0x00aa8768]
    s.ax = m.r32((0x00aa8768u));
  }
  L005cab26: { // 0x5cab26: 8b0d7087aa00 MOV ECX,dword ptr [0x00aa8770]
    s.cx = m.r32((0x00aa8770u));
  }
  L005cab2c: { // 0x5cab2c: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L005cab2e: { // 0x5cab2e: 7c2c JL 0x005cab5c
    if(integer::condition("JL",flags)) goto L005cab5c;
  }
  L005cab30: { // 0x5cab30: 381d6d87aa00 CMP byte ptr [0x00aa876d],BL
    (void)integer::sub(m.r8((0x00aa876du)),(s.bx & 0xffu),8,flags);
  }
  L005cab36: { // 0x5cab36: 7504 JNZ 0x005cab3c
    if(integer::condition("JNZ",flags)) goto L005cab3c;
  }
  L005cab38: { // 0x5cab38: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L005cab3a: { // 0x5cab3a: 7538 JNZ 0x005cab74
    if(integer::condition("JNZ",flags)) goto L005cab74;
  }
  L005cab3c: { // 0x5cab3c: 8b0d7487aa00 MOV ECX,dword ptr [0x00aa8774]
    s.cx = m.r32((0x00aa8774u));
  }
  L005cab42: { // 0x5cab42: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L005cab44: { // 0x5cab44: 7e2e JLE 0x005cab74
    if(integer::condition("JLE",flags)) goto L005cab74;
  }
  L005cab46: { // 0x5cab46: 8b156087aa00 MOV EDX,dword ptr [0x00aa8760]
    s.dx = m.r32((0x00aa8760u));
  }
  L005cab4c: { // 0x5cab4c: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L005cab4e: { // 0x5cab4e: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005cab4f: { // 0x5cab4f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005cab50: { // 0x5cab50: b96087aa00 MOV ECX,0xaa8760
    s.cx = 0x00aa8760u;
  }
  L005cab55: { // 0x5cab55: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),6073176u); flags=s.arithmetic_flags;
  }
  L005cab58: { // 0x5cab58: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cab5a: { // 0x5cab5a: 7418 JZ 0x005cab74
    if(integer::condition("JZ",flags)) goto L005cab74;
  }
  L005cab5c: { // 0x5cab5c: 8b0d7087aa00 MOV ECX,dword ptr [0x00aa8770]
    s.cx = m.r32((0x00aa8770u));
  }
  L005cab62: { // 0x5cab62: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L005cab64: { // 0x5cab64: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L005cab65: { // 0x5cab65: 890d7087aa00 MOV dword ptr [0x00aa8770],ECX
    m.w32((0x00aa8770u), s.cx);
  }
  L005cab6b: { // 0x5cab6b: 8b0d6487aa00 MOV ECX,dword ptr [0x00aa8764]
    s.cx = m.r32((0x00aa8764u));
  }
  L005cab71: { // 0x5cab71: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L005cab74: { // 0x5cab74: 8a4614 MOV AL,byte ptr [ESI + 0x14]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000014u)));
  }
  L005cab77: { // 0x5cab77: 0c02 OR AL,0x2
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000002u),8,flags));
  }
  L005cab79: { // 0x5cab79: 884614 MOV byte ptr [ESI + 0x14],AL
    m.w8((s.si+0x00000014u), (s.ax & 0xffu));
  }
  L005cab7c: { // 0x5cab7c: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L005cab7e: { // 0x5cab7e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005cab7f: { // 0x5cab7f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005cab80: { // 0x5cab80: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0000ff10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0040ff10: { // 0x40ff10: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0040ff12: { // 0x40ff12: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0040ff14: { // 0x40ff14: c74008445e7800 MOV dword ptr [EAX + 0x8],0x785e44
    m.w32((s.ax+0x00000008u), 0x00785e44u);
  }
  L0040ff1b: { // 0x40ff1b: c7400c3c5e7800 MOV dword ptr [EAX + 0xc],0x785e3c
    m.w32((s.ax+0x0000000cu), 0x00785e3cu);
  }
  L0040ff22: { // 0x40ff22: 894818 MOV dword ptr [EAX + 0x18],ECX
    m.w32((s.ax+0x00000018u), s.cx);
  }
  L0040ff25: { // 0x40ff25: 89481c MOV dword ptr [EAX + 0x1c],ECX
    m.w32((s.ax+0x0000001cu), s.cx);
  }
  L0040ff28: { // 0x40ff28: 884820 MOV byte ptr [EAX + 0x20],CL
    m.w8((s.ax+0x00000020u), (s.cx & 0xffu));
  }
  L0040ff2b: { // 0x40ff2b: 8a4814 MOV CL,byte ptr [EAX + 0x14]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000014u)));
  }
  L0040ff2e: { // 0x40ff2e: 80e1f8 AND CL,0xf8
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))&(0x000000f8u),8,flags));
  }
  L0040ff31: { // 0x40ff31: c74010ffffffff MOV dword ptr [EAX + 0x10],0xffffffff
    m.w32((s.ax+0x00000010u), 0xffffffffu);
  }
  L0040ff38: { // 0x40ff38: c700d85d7800 MOV dword ptr [EAX],0x785dd8
    m.w32((s.ax), 0x00785dd8u);
  }
  L0040ff3e: { // 0x40ff3e: c74004bc5d7800 MOV dword ptr [EAX + 0x4],0x785dbc
    m.w32((s.ax+0x00000004u), 0x00785dbcu);
  }
  L0040ff45: { // 0x40ff45: c74008b45d7800 MOV dword ptr [EAX + 0x8],0x785db4
    m.w32((s.ax+0x00000008u), 0x00785db4u);
  }
  L0040ff4c: { // 0x40ff4c: c7400cac5d7800 MOV dword ptr [EAX + 0xc],0x785dac
    m.w32((s.ax+0x0000000cu), 0x00785dacu);
  }
  L0040ff53: { // 0x40ff53: 884814 MOV byte ptr [EAX + 0x14],CL
    m.w8((s.ax+0x00000014u), (s.cx & 0xffu));
  }
  L0040ff56: { // 0x40ff56: c3 RET
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
void f_00219cf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00619cf0: { // 0x619cf0: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L00619cf4: { // 0x619cf4: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00619cf6: { // 0x619cf6: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L00619cfa: { // 0x619cfa: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L00619cfc: { // 0x619cfc: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L00619d00: { // 0x619d00: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
  L00619d03: { // 0x619d03: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00619d07: { // 0x619d07: 894808 MOV dword ptr [EAX + 0x8],ECX
    m.w32((s.ax+0x00000008u), s.cx);
  }
  L00619d0a: { // 0x619d0a: 89500c MOV dword ptr [EAX + 0xc],EDX
    m.w32((s.ax+0x0000000cu), s.dx);
  }
  L00619d0d: { // 0x619d0d: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
}

void f_001cde80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005cde80: { // 0x5cde80: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L005cde84: { // 0x5cde84: 83ec1c SUB ESP,0x1c
    f.sp = integer::sub(f.sp,0x0000001cu,32,flags);
  }
  L005cde87: { // 0x5cde87: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005cde88: { // 0x5cde88: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005cde89: { // 0x5cde89: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L005cde8b: { // 0x5cde8b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005cde8c: { // 0x5cde8c: e8ef26e4ff CALL 0x00410580
    s.arithmetic_flags=flags; invoke(m,s,f,0x00410580u,6086289u); flags=s.arithmetic_flags;
  }
  L005cde91: { // 0x5cde91: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L005cde93: { // 0x5cde93: 8d85c8000000 LEA EAX,[EBP + 0xc8]
    s.ax = (s.bp+0x000000c8u);
  }
  L005cde99: { // 0x5cde99: 889d98000000 MOV byte ptr [EBP + 0x98],BL
    m.w8((s.bp+0x00000098u), (s.bx & 0xffu));
  }
  L005cde9f: { // 0x5cde9f: 889d99000000 MOV byte ptr [EBP + 0x99],BL
    m.w8((s.bp+0x00000099u), (s.bx & 0xffu));
  }
  L005cdea5: { // 0x5cdea5: 889d9a000000 MOV byte ptr [EBP + 0x9a],BL
    m.w8((s.bp+0x0000009au), (s.bx & 0xffu));
  }
  L005cdeab: { // 0x5cdeab: 899d9c000000 MOV dword ptr [EBP + 0x9c],EBX
    m.w32((s.bp+0x0000009cu), s.bx);
  }
  L005cdeb1: { // 0x5cdeb1: 899da0000000 MOV dword ptr [EBP + 0xa0],EBX
    m.w32((s.bp+0x000000a0u), s.bx);
  }
  L005cdeb7: { // 0x5cdeb7: 899da4000000 MOV dword ptr [EBP + 0xa4],EBX
    m.w32((s.bp+0x000000a4u), s.bx);
  }
  L005cdebd: { // 0x5cdebd: 889da8000000 MOV byte ptr [EBP + 0xa8],BL
    m.w8((s.bp+0x000000a8u), (s.bx & 0xffu));
  }
  L005cdec3: { // 0x5cdec3: 899dac000000 MOV dword ptr [EBP + 0xac],EBX
    m.w32((s.bp+0x000000acu), s.bx);
  }
  L005cdec9: { // 0x5cdec9: 899db0000000 MOV dword ptr [EBP + 0xb0],EBX
    m.w32((s.bp+0x000000b0u), s.bx);
  }
  L005cdecf: { // 0x5cdecf: 899db4000000 MOV dword ptr [EBP + 0xb4],EBX
    m.w32((s.bp+0x000000b4u), s.bx);
  }
  L005cded5: { // 0x5cded5: 899db8000000 MOV dword ptr [EBP + 0xb8],EBX
    m.w32((s.bp+0x000000b8u), s.bx);
  }
  L005cdedb: { // 0x5cdedb: 899dbc000000 MOV dword ptr [EBP + 0xbc],EBX
    m.w32((s.bp+0x000000bcu), s.bx);
  }
  L005cdee1: { // 0x5cdee1: 899dc0000000 MOV dword ptr [EBP + 0xc0],EBX
    m.w32((s.bp+0x000000c0u), s.bx);
  }
  L005cdee7: { // 0x5cdee7: 899dc4000000 MOV dword ptr [EBP + 0xc4],EBX
    m.w32((s.bp+0x000000c4u), s.bx);
  }
  L005cdeed: { // 0x5cdeed: b90f000000 MOV ECX,0xf
    s.cx = 0x0000000fu;
  }
  L005cdef2: { // 0x5cdef2: 8918 MOV dword ptr [EAX],EBX
    m.w32((s.ax), s.bx);
  }
  L005cdef4: { // 0x5cdef4: 895804 MOV dword ptr [EAX + 0x4],EBX
    m.w32((s.ax+0x00000004u), s.bx);
  }
  L005cdef7: { // 0x5cdef7: 83c008 ADD EAX,0x8
    s.ax = integer::add(s.ax,0x00000008u,32,flags);
  }
  L005cdefa: { // 0x5cdefa: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L005cdefb: { // 0x5cdefb: 75f5 JNZ 0x005cdef2
    if(integer::condition("JNZ",flags)) goto L005cdef2;
  }
  L005cdefd: { // 0x5cdefd: 8d8540010000 LEA EAX,[EBP + 0x140]
    s.ax = (s.bp+0x00000140u);
  }
  L005cdf03: { // 0x5cdf03: b90f000000 MOV ECX,0xf
    s.cx = 0x0000000fu;
  }
  L005cdf08: { // 0x5cdf08: 8918 MOV dword ptr [EAX],EBX
    m.w32((s.ax), s.bx);
  }
  L005cdf0a: { // 0x5cdf0a: 895804 MOV dword ptr [EAX + 0x4],EBX
    m.w32((s.ax+0x00000004u), s.bx);
  }
  L005cdf0d: { // 0x5cdf0d: 83c008 ADD EAX,0x8
    s.ax = integer::add(s.ax,0x00000008u,32,flags);
  }
  L005cdf10: { // 0x5cdf10: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L005cdf11: { // 0x5cdf11: 75f5 JNZ 0x005cdf08
    if(integer::condition("JNZ",flags)) goto L005cdf08;
  }
  L005cdf13: { // 0x5cdf13: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005cdf14: { // 0x5cdf14: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005cdf15: { // 0x5cdf15: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L005cdf18: { // 0x5cdf18: 8dbdc8010000 LEA EDI,[EBP + 0x1c8]
    s.di = (s.bp+0x000001c8u);
  }
  L005cdf1e: { // 0x5cdf1e: 889db8010000 MOV byte ptr [EBP + 0x1b8],BL
    m.w8((s.bp+0x000001b8u), (s.bx & 0xffu));
  }
  L005cdf24: { // 0x5cdf24: 899dbc010000 MOV dword ptr [EBP + 0x1bc],EBX
    m.w32((s.bp+0x000001bcu), s.bx);
  }
  L005cdf2a: { // 0x5cdf2a: 8985c0010000 MOV dword ptr [EBP + 0x1c0],EAX
    m.w32((s.bp+0x000001c0u), s.ax);
  }
  L005cdf30: { // 0x5cdf30: 8985c4010000 MOV dword ptr [EBP + 0x1c4],EAX
    m.w32((s.bp+0x000001c4u), s.ax);
  }
  L005cdf36: { // 0x5cdf36: 881f MOV byte ptr [EDI],BL
    m.w8((s.di), (s.bx & 0xffu));
  }
  L005cdf38: { // 0x5cdf38: 889de1010000 MOV byte ptr [EBP + 0x1e1],BL
    m.w8((s.bp+0x000001e1u), (s.bx & 0xffu));
  }
  L005cdf3e: { // 0x5cdf3e: 889de2010000 MOV byte ptr [EBP + 0x1e2],BL
    m.w8((s.bp+0x000001e2u), (s.bx & 0xffu));
  }
  L005cdf44: { // 0x5cdf44: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L005cdf46: { // 0x5cdf46: 889de3010000 MOV byte ptr [EBP + 0x1e3],BL
    m.w8((s.bp+0x000001e3u), (s.bx & 0xffu));
  }
  L005cdf4c: { // 0x5cdf4c: 8885fe010000 MOV byte ptr [EBP + 0x1fe],AL
    m.w8((s.bp+0x000001feu), (s.ax & 0xffu));
  }
  L005cdf52: { // 0x5cdf52: 888500020000 MOV byte ptr [EBP + 0x200],AL
    m.w8((s.bp+0x00000200u), (s.ax & 0xffu));
  }
  L005cdf58: { // 0x5cdf58: 888501020000 MOV byte ptr [EBP + 0x201],AL
    m.w8((s.bp+0x00000201u), (s.ax & 0xffu));
  }
  L005cdf5e: { // 0x5cdf5e: 888505020000 MOV byte ptr [EBP + 0x205],AL
    m.w8((s.bp+0x00000205u), (s.ax & 0xffu));
  }
  L005cdf64: { // 0x5cdf64: b080 MOV AL,0x80
    s.ax = with_al(s.ax, 0x00000080u);
  }
  L005cdf66: { // 0x5cdf66: 889dfc010000 MOV byte ptr [EBP + 0x1fc],BL
    m.w8((s.bp+0x000001fcu), (s.bx & 0xffu));
  }
  L005cdf6c: { // 0x5cdf6c: 889dfd010000 MOV byte ptr [EBP + 0x1fd],BL
    m.w8((s.bp+0x000001fdu), (s.bx & 0xffu));
  }
  L005cdf72: { // 0x5cdf72: 889dff010000 MOV byte ptr [EBP + 0x1ff],BL
    m.w8((s.bp+0x000001ffu), (s.bx & 0xffu));
  }
  L005cdf78: { // 0x5cdf78: 889d02020000 MOV byte ptr [EBP + 0x202],BL
    m.w8((s.bp+0x00000202u), (s.bx & 0xffu));
  }
  L005cdf7e: { // 0x5cdf7e: 889d03020000 MOV byte ptr [EBP + 0x203],BL
    m.w8((s.bp+0x00000203u), (s.bx & 0xffu));
  }
  L005cdf84: { // 0x5cdf84: 889d04020000 MOV byte ptr [EBP + 0x204],BL
    m.w8((s.bp+0x00000204u), (s.bx & 0xffu));
  }
  L005cdf8a: { // 0x5cdf8a: 889d06020000 MOV byte ptr [EBP + 0x206],BL
    m.w8((s.bp+0x00000206u), (s.bx & 0xffu));
  }
  L005cdf90: { // 0x5cdf90: 889d07020000 MOV byte ptr [EBP + 0x207],BL
    m.w8((s.bp+0x00000207u), (s.bx & 0xffu));
  }
  L005cdf96: { // 0x5cdf96: 889d08020000 MOV byte ptr [EBP + 0x208],BL
    m.w8((s.bp+0x00000208u), (s.bx & 0xffu));
  }
  L005cdf9c: { // 0x5cdf9c: 889d09020000 MOV byte ptr [EBP + 0x209],BL
    m.w8((s.bp+0x00000209u), (s.bx & 0xffu));
  }
  L005cdfa2: { // 0x5cdfa2: 889d0a020000 MOV byte ptr [EBP + 0x20a],BL
    m.w8((s.bp+0x0000020au), (s.bx & 0xffu));
  }
  L005cdfa8: { // 0x5cdfa8: 88850b020000 MOV byte ptr [EBP + 0x20b],AL
    m.w8((s.bp+0x0000020bu), (s.ax & 0xffu));
  }
  L005cdfae: { // 0x5cdfae: 88850c020000 MOV byte ptr [EBP + 0x20c],AL
    m.w8((s.bp+0x0000020cu), (s.ax & 0xffu));
  }
  L005cdfb4: { // 0x5cdfb4: 88850d020000 MOV byte ptr [EBP + 0x20d],AL
    m.w8((s.bp+0x0000020du), (s.ax & 0xffu));
  }
  L005cdfba: { // 0x5cdfba: c7851002000010000000 MOV dword ptr [EBP + 0x210],0x10
    m.w32((s.bp+0x00000210u), 0x00000010u);
  }
  L005cdfc4: { // 0x5cdfc4: 899d14020000 MOV dword ptr [EBP + 0x214],EBX
    m.w32((s.bp+0x00000214u), s.bx);
  }
  L005cdfca: { // 0x5cdfca: 899d18020000 MOV dword ptr [EBP + 0x218],EBX
    m.w32((s.bp+0x00000218u), s.bx);
  }
  L005cdfd0: { // 0x5cdfd0: 899d1c020000 MOV dword ptr [EBP + 0x21c],EBX
    m.w32((s.bp+0x0000021cu), s.bx);
  }
  L005cdfd6: { // 0x5cdfd6: 889d20020000 MOV byte ptr [EBP + 0x220],BL
    m.w8((s.bp+0x00000220u), (s.bx & 0xffu));
  }
  L005cdfdc: { // 0x5cdfdc: 899d24020000 MOV dword ptr [EBP + 0x224],EBX
    m.w32((s.bp+0x00000224u), s.bx);
  }
  L005cdfe2: { // 0x5cdfe2: 899d28020000 MOV dword ptr [EBP + 0x228],EBX
    m.w32((s.bp+0x00000228u), s.bx);
  }
  L005cdfe8: { // 0x5cdfe8: 899d2c020000 MOV dword ptr [EBP + 0x22c],EBX
    m.w32((s.bp+0x0000022cu), s.bx);
  }
  L005cdfee: { // 0x5cdfee: 899d30020000 MOV dword ptr [EBP + 0x230],EBX
    m.w32((s.bp+0x00000230u), s.bx);
  }
  L005cdff4: { // 0x5cdff4: 889d34020000 MOV byte ptr [EBP + 0x234],BL
    m.w8((s.bp+0x00000234u), (s.bx & 0xffu));
  }
  L005cdffa: { // 0x5cdffa: 899d38020000 MOV dword ptr [EBP + 0x238],EBX
    m.w32((s.bp+0x00000238u), s.bx);
  }
  L005ce000: { // 0x5ce000: 8d7524 LEA ESI,[EBP + 0x24]
    s.si = (s.bp+0x00000024u);
  }
  L005ce003: { // 0x5ce003: 899d3c020000 MOV dword ptr [EBP + 0x23c],EBX
    m.w32((s.bp+0x0000023cu), s.bx);
  }
  L005ce009: { // 0x5ce009: 899d40020000 MOV dword ptr [EBP + 0x240],EBX
    m.w32((s.bp+0x00000240u), s.bx);
  }
  L005ce00f: { // 0x5ce00f: 899d44020000 MOV dword ptr [EBP + 0x244],EBX
    m.w32((s.bp+0x00000244u), s.bx);
  }
  L005ce015: { // 0x5ce015: 889d48020000 MOV byte ptr [EBP + 0x248],BL
    m.w8((s.bp+0x00000248u), (s.bx & 0xffu));
  }
  L005ce01b: { // 0x5ce01b: 899d4c020000 MOV dword ptr [EBP + 0x24c],EBX
    m.w32((s.bp+0x0000024cu), s.bx);
  }
  L005ce021: { // 0x5ce021: 899d50020000 MOV dword ptr [EBP + 0x250],EBX
    m.w32((s.bp+0x00000250u), s.bx);
  }
  L005ce027: { // 0x5ce027: 899d54020000 MOV dword ptr [EBP + 0x254],EBX
    m.w32((s.bp+0x00000254u), s.bx);
  }
  L005ce02d: { // 0x5ce02d: 899d58020000 MOV dword ptr [EBP + 0x258],EBX
    m.w32((s.bp+0x00000258u), s.bx);
  }
  L005ce033: { // 0x5ce033: 889d5c020000 MOV byte ptr [EBP + 0x25c],BL
    m.w8((s.bp+0x0000025cu), (s.bx & 0xffu));
  }
  L005ce039: { // 0x5ce039: 899d60020000 MOV dword ptr [EBP + 0x260],EBX
    m.w32((s.bp+0x00000260u), s.bx);
  }
  L005ce03f: { // 0x5ce03f: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  L005ce041: { // 0x5ce041: c74500b8267900 MOV dword ptr [EBP],0x7926b8
    m.w32((s.bp), 0x007926b8u);
  }
  L005ce048: { // 0x5ce048: c745049c267900 MOV dword ptr [EBP + 0x4],0x79269c
    m.w32((s.bp+0x00000004u), 0x0079269cu);
  }
  L005ce04f: { // 0x5ce04f: c7450894267900 MOV dword ptr [EBP + 0x8],0x792694
    m.w32((s.bp+0x00000008u), 0x00792694u);
  }
  L005ce056: { // 0x5ce056: c7450c8c267900 MOV dword ptr [EBP + 0xc],0x79268c
    m.w32((s.bp+0x0000000cu), 0x0079268cu);
  }
  L005ce05d: { // 0x5ce05d: 7408 JZ 0x005ce067
    if(integer::condition("JZ",flags)) goto L005ce067;
  }
  L005ce05f: { // 0x5ce05f: b906000000 MOV ECX,0x6
    s.cx = 0x00000006u;
  }
  L005ce064: { // 0x5ce064: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L005ce066: { // 0x5ce066: a4 MOVSB ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::single);
  }
  L005ce067: { // 0x5ce067: b9a4488200 MOV ECX,0x8248a4
    s.cx = 0x008248a4u;
  }
  L005ce06c: { // 0x5ce06c: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005ce06e: { // 0x5ce06e: 7506 JNZ 0x005ce076
    if(integer::condition("JNZ",flags)) goto L005ce076;
  }
  L005ce070: { // 0x5ce070: 885c2410 MOV byte ptr [ESP + 0x10],BL
    m.w8((f.sp+0x00000010u), (s.bx & 0xffu));
  }
  L005ce074: { // 0x5ce074: eb18 JMP 0x005ce08e
    goto L005ce08e;
  }
  L005ce076: { // 0x5ce076: 6a18 PUSH 0x18
    f.push(m,0x00000018u);
  }
  L005ce078: { // 0x5ce078: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  L005ce07c: { // 0x5ce07c: 68a4488200 PUSH 0x8248a4
    f.push(m,0x008248a4u);
  }
  L005ce081: { // 0x5ce081: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005ce082: { // 0x5ce082: e889fc1900 CALL 0x0076dd10
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076dd10u,6086791u); flags=s.arithmetic_flags;
  }
  L005ce087: { // 0x5ce087: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L005ce08a: { // 0x5ce08a: 885c2428 MOV byte ptr [ESP + 0x28],BL
    m.w8((f.sp+0x00000028u), (s.bx & 0xffu));
  }
  L005ce08e: { // 0x5ce08e: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L005ce092: { // 0x5ce092: 8dbde3010000 LEA EDI,[EBP + 0x1e3]
    s.di = (s.bp+0x000001e3u);
  }
  L005ce098: { // 0x5ce098: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L005ce09a: { // 0x5ce09a: 740c JZ 0x005ce0a8
    if(integer::condition("JZ",flags)) goto L005ce0a8;
  }
  L005ce09c: { // 0x5ce09c: b906000000 MOV ECX,0x6
    s.cx = 0x00000006u;
  }
  L005ce0a1: { // 0x5ce0a1: 8d742410 LEA ESI,[ESP + 0x10]
    s.si = (f.sp+0x00000010u);
  }
  L005ce0a5: { // 0x5ce0a5: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L005ce0a7: { // 0x5ce0a7: a4 MOVSB ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::single);
  }
  L005ce0a8: { // 0x5ce0a8: a100aba500 MOV EAX,[0x00a5ab00]
    s.ax = m.r32((0x00a5ab00u));
  }
  L005ce0ad: { // 0x5ce0ad: 8b0d08aba500 MOV ECX,dword ptr [0x00a5ab08]
    s.cx = m.r32((0x00a5ab08u));
  }
  L005ce0b3: { // 0x5ce0b3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005ce0b4: { // 0x5ce0b4: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L005ce0b6: { // 0x5ce0b6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005ce0b7: { // 0x5ce0b7: 7c2c JL 0x005ce0e5
    if(integer::condition("JL",flags)) goto L005ce0e5;
  }
  L005ce0b9: { // 0x5ce0b9: 381d05aba500 CMP byte ptr [0x00a5ab05],BL
    (void)integer::sub(m.r8((0x00a5ab05u)),(s.bx & 0xffu),8,flags);
  }
  L005ce0bf: { // 0x5ce0bf: 7504 JNZ 0x005ce0c5
    if(integer::condition("JNZ",flags)) goto L005ce0c5;
  }
  L005ce0c1: { // 0x5ce0c1: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L005ce0c3: { // 0x5ce0c3: 7538 JNZ 0x005ce0fd
    if(integer::condition("JNZ",flags)) goto L005ce0fd;
  }
  L005ce0c5: { // 0x5ce0c5: 8b0d0caba500 MOV ECX,dword ptr [0x00a5ab0c]
    s.cx = m.r32((0x00a5ab0cu));
  }
  L005ce0cb: { // 0x5ce0cb: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L005ce0cd: { // 0x5ce0cd: 7e2e JLE 0x005ce0fd
    if(integer::condition("JLE",flags)) goto L005ce0fd;
  }
  L005ce0cf: { // 0x5ce0cf: 8b15f8aaa500 MOV EDX,dword ptr [0x00a5aaf8]
    s.dx = m.r32((0x00a5aaf8u));
  }
  L005ce0d5: { // 0x5ce0d5: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L005ce0d7: { // 0x5ce0d7: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005ce0d8: { // 0x5ce0d8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005ce0d9: { // 0x5ce0d9: b9f8aaa500 MOV ECX,0xa5aaf8
    s.cx = 0x00a5aaf8u;
  }
  L005ce0de: { // 0x5ce0de: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),6086881u); flags=s.arithmetic_flags;
  }
  L005ce0e1: { // 0x5ce0e1: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005ce0e3: { // 0x5ce0e3: 7418 JZ 0x005ce0fd
    if(integer::condition("JZ",flags)) goto L005ce0fd;
  }
  L005ce0e5: { // 0x5ce0e5: 8b0d08aba500 MOV ECX,dword ptr [0x00a5ab08]
    s.cx = m.r32((0x00a5ab08u));
  }
  L005ce0eb: { // 0x5ce0eb: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L005ce0ed: { // 0x5ce0ed: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L005ce0ee: { // 0x5ce0ee: 890d08aba500 MOV dword ptr [0x00a5ab08],ECX
    m.w32((0x00a5ab08u), s.cx);
  }
  L005ce0f4: { // 0x5ce0f4: 8b0dfcaaa500 MOV ECX,dword ptr [0x00a5aafc]
    s.cx = m.r32((0x00a5aafcu));
  }
  L005ce0fa: { // 0x5ce0fa: 892c81 MOV dword ptr [ECX + EAX*0x4],EBP
    m.w32((s.cx+(s.ax * 0x00000004u)), s.bp);
  }
  L005ce0fd: { // 0x5ce0fd: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L005ce0ff: { // 0x5ce0ff: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005ce100: { // 0x5ce100: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005ce101: { // 0x5ce101: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L005ce104: { // 0x5ce104: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00010580(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00410580: { // 0x410580: 83ec44 SUB ESP,0x44
    f.sp = integer::sub(f.sp,0x00000044u,32,flags);
  }
  L00410583: { // 0x410583: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00410584: { // 0x410584: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00410585: { // 0x410585: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00410586: { // 0x410586: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00410587: { // 0x410587: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L00410589: { // 0x410589: e882f9ffff CALL 0x0040ff10
    s.arithmetic_flags=flags; invoke(m,s,f,0x0040ff10u,4261262u); flags=s.arithmetic_flags;
  }
  L0041058e: { // 0x41058e: 8b442458 MOV EAX,dword ptr [ESP + 0x58]
    s.ax = m.r32((f.sp+0x00000058u));
  }
  L00410592: { // 0x410592: 8d5d24 LEA EBX,[EBP + 0x24]
    s.bx = (s.bp+0x00000024u);
  }
  L00410595: { // 0x410595: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00410597: { // 0x410597: c60300 MOV byte ptr [EBX],0x0
    m.w8((s.bx), 0x00000000u);
  }
  L0041059a: { // 0x41059a: c6453d00 MOV byte ptr [EBP + 0x3d],0x0
    m.w8((s.bp+0x0000003du), 0x00000000u);
  }
  L0041059e: { // 0x41059e: c6456400 MOV byte ptr [EBP + 0x64],0x0
    m.w8((s.bp+0x00000064u), 0x00000000u);
  }
  L004105a2: { // 0x4105a2: c74500885e7800 MOV dword ptr [EBP],0x785e88
    m.w32((s.bp), 0x00785e88u);
  }
  L004105a9: { // 0x4105a9: c745046c5e7800 MOV dword ptr [EBP + 0x4],0x785e6c
    m.w32((s.bp+0x00000004u), 0x00785e6cu);
  }
  L004105b0: { // 0x4105b0: c74508645e7800 MOV dword ptr [EBP + 0x8],0x785e64
    m.w32((s.bp+0x00000008u), 0x00785e64u);
  }
  L004105b7: { // 0x4105b7: c7450c5c5e7800 MOV dword ptr [EBP + 0xc],0x785e5c
    m.w32((s.bp+0x0000000cu), 0x00785e5cu);
  }
  L004105be: { // 0x4105be: 754d JNZ 0x0041060d
    if(integer::condition("JNZ",flags)) goto L0041060d;
  }
  L004105c0: { // 0x4105c0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004105c1: { // 0x4105c1: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L004105c5: { // 0x4105c5: 6810927b00 PUSH 0x7b9210
    f.push(m,0x007b9210u);
  }
  L004105ca: { // 0x4105ca: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004105cb: { // 0x4105cb: e864d43500 CALL 0x0076da34
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076da34u,4261328u); flags=s.arithmetic_flags;
  }
  L004105d0: { // 0x4105d0: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L004105d4: { // 0x4105d4: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L004105d7: { // 0x4105d7: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004105d9: { // 0x4105d9: 7506 JNZ 0x004105e1
    if(integer::condition("JNZ",flags)) goto L004105e1;
  }
  L004105db: { // 0x4105db: 884c2420 MOV byte ptr [ESP + 0x20],CL
    m.w8((f.sp+0x00000020u), (s.cx & 0xffu));
  }
  L004105df: { // 0x4105df: eb19 JMP 0x004105fa
    goto L004105fa;
  }
  L004105e1: { // 0x4105e1: 8d542410 LEA EDX,[ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  L004105e5: { // 0x4105e5: 6a18 PUSH 0x18
    f.push(m,0x00000018u);
  }
  L004105e7: { // 0x4105e7: 8d442424 LEA EAX,[ESP + 0x24]
    s.ax = (f.sp+0x00000024u);
  }
  L004105eb: { // 0x4105eb: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004105ec: { // 0x4105ec: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004105ed: { // 0x4105ed: e81ed73500 CALL 0x0076dd10
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076dd10u,4261362u); flags=s.arithmetic_flags;
  }
  L004105f2: { // 0x4105f2: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L004105f5: { // 0x4105f5: c644243800 MOV byte ptr [ESP + 0x38],0x0
    m.w8((f.sp+0x00000038u), 0x00000000u);
  }
  L004105fa: { // 0x4105fa: 8d4c2420 LEA ECX,[ESP + 0x20]
    s.cx = (f.sp+0x00000020u);
  }
  L004105fe: { // 0x4105fe: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L00410600: { // 0x410600: 7436 JZ 0x00410638
    if(integer::condition("JZ",flags)) goto L00410638;
  }
  L00410602: { // 0x410602: b906000000 MOV ECX,0x6
    s.cx = 0x00000006u;
  }
  L00410607: { // 0x410607: 8d742420 LEA ESI,[ESP + 0x20]
    s.si = (f.sp+0x00000020u);
  }
  L0041060b: { // 0x41060b: eb26 JMP 0x00410633
    goto L00410633;
  }
  L0041060d: { // 0x41060d: 6a18 PUSH 0x18
    f.push(m,0x00000018u);
  }
  L0041060f: { // 0x41060f: 8d542424 LEA EDX,[ESP + 0x24]
    s.dx = (f.sp+0x00000024u);
  }
  L00410613: { // 0x410613: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00410614: { // 0x410614: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00410615: { // 0x410615: e8f6d63500 CALL 0x0076dd10
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076dd10u,4261402u); flags=s.arithmetic_flags;
  }
  L0041061a: { // 0x41061a: 8d44242c LEA EAX,[ESP + 0x2c]
    s.ax = (f.sp+0x0000002cu);
  }
  L0041061e: { // 0x41061e: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00410621: { // 0x410621: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00410623: { // 0x410623: c644243800 MOV byte ptr [ESP + 0x38],0x0
    m.w8((f.sp+0x00000038u), 0x00000000u);
  }
  L00410628: { // 0x410628: 740e JZ 0x00410638
    if(integer::condition("JZ",flags)) goto L00410638;
  }
  L0041062a: { // 0x41062a: b906000000 MOV ECX,0x6
    s.cx = 0x00000006u;
  }
  L0041062f: { // 0x41062f: 8d742420 LEA ESI,[ESP + 0x20]
    s.si = (f.sp+0x00000020u);
  }
  L00410633: { // 0x410633: 8bfb MOV EDI,EBX
    s.di = s.bx;
  }
  L00410635: { // 0x410635: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L00410637: { // 0x410637: a4 MOVSB ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::single);
  }
  L00410638: { // 0x410638: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L0041063a: { // 0x41063a: 7506 JNZ 0x00410642
    if(integer::condition("JNZ",flags)) goto L00410642;
  }
  L0041063c: { // 0x41063c: 885c2420 MOV byte ptr [ESP + 0x20],BL
    m.w8((f.sp+0x00000020u), (s.bx & 0xffu));
  }
  L00410640: { // 0x410640: eb15 JMP 0x00410657
    goto L00410657;
  }
  L00410642: { // 0x410642: 6a30 PUSH 0x30
    f.push(m,0x00000030u);
  }
  L00410644: { // 0x410644: 8d4c2424 LEA ECX,[ESP + 0x24]
    s.cx = (f.sp+0x00000024u);
  }
  L00410648: { // 0x410648: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00410649: { // 0x410649: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0041064a: { // 0x41064a: e8c1d63500 CALL 0x0076dd10
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076dd10u,4261455u); flags=s.arithmetic_flags;
  }
  L0041064f: { // 0x41064f: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00410652: { // 0x410652: c644245000 MOV byte ptr [ESP + 0x50],0x0
    m.w8((f.sp+0x00000050u), 0x00000000u);
  }
  L00410657: { // 0x410657: 8d542420 LEA EDX,[ESP + 0x20]
    s.dx = (f.sp+0x00000020u);
  }
  L0041065b: { // 0x41065b: 8d7d64 LEA EDI,[EBP + 0x64]
    s.di = (s.bp+0x00000064u);
  }
  L0041065e: { // 0x41065e: 3bd7 CMP EDX,EDI
    (void)integer::sub(s.dx,s.di,32,flags);
  }
  L00410660: { // 0x410660: 740c JZ 0x0041066e
    if(integer::condition("JZ",flags)) goto L0041066e;
  }
  L00410662: { // 0x410662: b90c000000 MOV ECX,0xc
    s.cx = 0x0000000cu;
  }
  L00410667: { // 0x410667: 8d742420 LEA ESI,[ESP + 0x20]
    s.si = (f.sp+0x00000020u);
  }
  L0041066b: { // 0x41066b: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L0041066d: { // 0x41066d: a4 MOVSB ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::single);
  }
  L0041066e: { // 0x41066e: c745608c208200 MOV dword ptr [EBP + 0x60],0x82208c
    m.w32((s.bp+0x00000060u), 0x0082208cu);
  }
  L00410675: { // 0x410675: a18085a200 MOV EAX,[0x00a28580]
    s.ax = m.r32((0x00a28580u));
  }
  L0041067a: { // 0x41067a: 39058885a200 CMP dword ptr [0x00a28588],EAX
    (void)integer::sub(m.r32((0x00a28588u)),s.ax,32,flags);
  }
  L00410680: { // 0x410680: 7c2e JL 0x004106b0
    if(integer::condition("JL",flags)) goto L004106b0;
  }
  L00410682: { // 0x410682: 8a0d8585a200 MOV CL,byte ptr [0x00a28585]
    s.cx = with_al(s.cx, m.r8((0x00a28585u)));
  }
  L00410688: { // 0x410688: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0041068a: { // 0x41068a: 7504 JNZ 0x00410690
    if(integer::condition("JNZ",flags)) goto L00410690;
  }
  L0041068c: { // 0x41068c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0041068e: { // 0x41068e: 7538 JNZ 0x004106c8
    if(integer::condition("JNZ",flags)) goto L004106c8;
  }
  L00410690: { // 0x410690: 8b0d8c85a200 MOV ECX,dword ptr [0x00a2858c]
    s.cx = m.r32((0x00a2858cu));
  }
  L00410696: { // 0x410696: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00410698: { // 0x410698: 7e2e JLE 0x004106c8
    if(integer::condition("JLE",flags)) goto L004106c8;
  }
  L0041069a: { // 0x41069a: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0041069c: { // 0x41069c: a17885a200 MOV EAX,[0x00a28578]
    s.ax = m.r32((0x00a28578u));
  }
  L004106a1: { // 0x4106a1: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L004106a3: { // 0x4106a3: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004106a4: { // 0x4106a4: b97885a200 MOV ECX,0xa28578
    s.cx = 0x00a28578u;
  }
  L004106a9: { // 0x4106a9: ff5008 CALL dword ptr [EAX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000008u)),4261548u); flags=s.arithmetic_flags;
  }
  L004106ac: { // 0x4106ac: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004106ae: { // 0x4106ae: 7418 JZ 0x004106c8
    if(integer::condition("JZ",flags)) goto L004106c8;
  }
  L004106b0: { // 0x4106b0: 8b0d8885a200 MOV ECX,dword ptr [0x00a28588]
    s.cx = m.r32((0x00a28588u));
  }
  L004106b6: { // 0x4106b6: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004106b8: { // 0x4106b8: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L004106b9: { // 0x4106b9: 890d8885a200 MOV dword ptr [0x00a28588],ECX
    m.w32((0x00a28588u), s.cx);
  }
  L004106bf: { // 0x4106bf: 8b0d7c85a200 MOV ECX,dword ptr [0x00a2857c]
    s.cx = m.r32((0x00a2857cu));
  }
  L004106c5: { // 0x4106c5: 892c81 MOV dword ptr [ECX + EAX*0x4],EBP
    m.w32((s.cx+(s.ax * 0x00000004u)), s.bp);
  }
  L004106c8: { // 0x4106c8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004106c9: { // 0x4106c9: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L004106cb: { // 0x4106cb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004106cc: { // 0x4106cc: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004106cd: { // 0x4106cd: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004106ce: { // 0x4106ce: 83c444 ADD ESP,0x44
    f.sp = integer::add(f.sp,0x00000044u,32,flags);
  }
  L004106d1: { // 0x4106d1: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0036dd10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0076dd10: { // 0x76dd10: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L0076dd14: { // 0x76dd14: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0076dd15: { // 0x76dd15: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0076dd17: { // 0x76dd17: 747a JZ 0x0076dd93
    if(integer::condition("JZ",flags)) goto L0076dd93;
  }
  L0076dd19: { // 0x76dd19: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0076dd1a: { // 0x76dd1a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0076dd1b: { // 0x76dd1b: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0076dd1d: { // 0x76dd1d: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L0076dd21: { // 0x76dd21: f7c603000000 TEST ESI,0x3
    (void)integer::logical((s.si)&(0x00000003u),32,flags);
  }
  L0076dd27: { // 0x76dd27: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L0076dd2b: { // 0x76dd2b: 7507 JNZ 0x0076dd34
    if(integer::condition("JNZ",flags)) goto L0076dd34;
  }
  L0076dd2d: { // 0x76dd2d: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L0076dd30: { // 0x76dd30: 756f JNZ 0x0076dda1
    if(integer::condition("JNZ",flags)) goto L0076dda1;
  }
  L0076dd32: { // 0x76dd32: eb21 JMP 0x0076dd55
    goto L0076dd55;
  }
  L0076dd34: { // 0x76dd34: 8a06 MOV AL,byte ptr [ESI]
    s.ax = with_al(s.ax, m.r8((s.si)));
  }
  L0076dd36: { // 0x76dd36: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0076dd37: { // 0x76dd37: 8807 MOV byte ptr [EDI],AL
    m.w8((s.di), (s.ax & 0xffu));
  }
  L0076dd39: { // 0x76dd39: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0076dd3a: { // 0x76dd3a: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0076dd3b: { // 0x76dd3b: 7425 JZ 0x0076dd62
    if(integer::condition("JZ",flags)) goto L0076dd62;
  }
  L0076dd3d: { // 0x76dd3d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0076dd3f: { // 0x76dd3f: 7429 JZ 0x0076dd6a
    if(integer::condition("JZ",flags)) goto L0076dd6a;
  }
  L0076dd41: { // 0x76dd41: f7c603000000 TEST ESI,0x3
    (void)integer::logical((s.si)&(0x00000003u),32,flags);
  }
  L0076dd47: { // 0x76dd47: 75eb JNZ 0x0076dd34
    if(integer::condition("JNZ",flags)) goto L0076dd34;
  }
  L0076dd49: { // 0x76dd49: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0076dd4b: { // 0x76dd4b: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L0076dd4e: { // 0x76dd4e: 7551 JNZ 0x0076dda1
    if(integer::condition("JNZ",flags)) goto L0076dda1;
  }
  L0076dd50: { // 0x76dd50: 83e303 AND EBX,0x3
    s.bx = integer::logical((s.bx)&(0x00000003u),32,flags);
  }
  L0076dd53: { // 0x76dd53: 740d JZ 0x0076dd62
    if(integer::condition("JZ",flags)) goto L0076dd62;
  }
  L0076dd55: { // 0x76dd55: 8a06 MOV AL,byte ptr [ESI]
    s.ax = with_al(s.ax, m.r8((s.si)));
  }
  L0076dd57: { // 0x76dd57: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0076dd58: { // 0x76dd58: 8807 MOV byte ptr [EDI],AL
    m.w8((s.di), (s.ax & 0xffu));
  }
  L0076dd5a: { // 0x76dd5a: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0076dd5b: { // 0x76dd5b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0076dd5d: { // 0x76dd5d: 742f JZ 0x0076dd8e
    if(integer::condition("JZ",flags)) goto L0076dd8e;
  }
  L0076dd5f: { // 0x76dd5f: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L0076dd60: { // 0x76dd60: 75f3 JNZ 0x0076dd55
    if(integer::condition("JNZ",flags)) goto L0076dd55;
  }
  L0076dd62: { // 0x76dd62: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0076dd66: { // 0x76dd66: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0076dd67: { // 0x76dd67: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076dd68: { // 0x76dd68: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076dd69: { // 0x76dd69: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076dd6a: { // 0x76dd6a: f7c703000000 TEST EDI,0x3
    (void)integer::logical((s.di)&(0x00000003u),32,flags);
  }
  L0076dd70: { // 0x76dd70: 7412 JZ 0x0076dd84
    if(integer::condition("JZ",flags)) goto L0076dd84;
  }
  L0076dd72: { // 0x76dd72: 8807 MOV byte ptr [EDI],AL
    m.w8((s.di), (s.ax & 0xffu));
  }
  L0076dd74: { // 0x76dd74: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0076dd75: { // 0x76dd75: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0076dd76: { // 0x76dd76: 0f848a000000 JZ 0x0076de06
    if(integer::condition("JZ",flags)) goto L0076de06;
  }
  L0076dd7c: { // 0x76dd7c: f7c703000000 TEST EDI,0x3
    (void)integer::logical((s.di)&(0x00000003u),32,flags);
  }
  L0076dd82: { // 0x76dd82: 75ee JNZ 0x0076dd72
    if(integer::condition("JNZ",flags)) goto L0076dd72;
  }
  L0076dd84: { // 0x76dd84: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0076dd86: { // 0x76dd86: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L0076dd89: { // 0x76dd89: 756c JNZ 0x0076ddf7
    if(integer::condition("JNZ",flags)) goto L0076ddf7;
  }
  L0076dd8b: { // 0x76dd8b: 8807 MOV byte ptr [EDI],AL
    m.w8((s.di), (s.ax & 0xffu));
  }
  L0076dd8d: { // 0x76dd8d: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0076dd8e: { // 0x76dd8e: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L0076dd8f: { // 0x76dd8f: 75fa JNZ 0x0076dd8b
    if(integer::condition("JNZ",flags)) goto L0076dd8b;
  }
  L0076dd91: { // 0x76dd91: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0076dd92: { // 0x76dd92: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076dd93: { // 0x76dd93: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L0076dd97: { // 0x76dd97: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076dd98: { // 0x76dd98: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076dd99: { // 0x76dd99: 8917 MOV dword ptr [EDI],EDX
    m.w32((s.di), s.dx);
  }
  L0076dd9b: { // 0x76dd9b: 83c704 ADD EDI,0x4
    s.di = integer::add(s.di,0x00000004u,32,flags);
  }
  L0076dd9e: { // 0x76dd9e: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0076dd9f: { // 0x76dd9f: 74af JZ 0x0076dd50
    if(integer::condition("JZ",flags)) goto L0076dd50;
  }
  L0076dda1: { // 0x76dda1: bafffefe7e MOV EDX,0x7efefeff
    s.dx = 0x7efefeffu;
  }
  L0076dda6: { // 0x76dda6: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0076dda8: { // 0x76dda8: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L0076ddaa: { // 0x76ddaa: 83f0ff XOR EAX,0xffffffff
    s.ax = integer::logical((s.ax)^(0xffffffffu),32,flags);
  }
  L0076ddad: { // 0x76ddad: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L0076ddaf: { // 0x76ddaf: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0076ddb1: { // 0x76ddb1: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  L0076ddb4: { // 0x76ddb4: a900010181 TEST EAX,0x81010100
    (void)integer::logical((s.ax)&(0x81010100u),32,flags);
  }
  L0076ddb9: { // 0x76ddb9: 74de JZ 0x0076dd99
    if(integer::condition("JZ",flags)) goto L0076dd99;
  }
  L0076ddbb: { // 0x76ddbb: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L0076ddbd: { // 0x76ddbd: 742c JZ 0x0076ddeb
    if(integer::condition("JZ",flags)) goto L0076ddeb;
  }
  L0076ddbf: { // 0x76ddbf: 84f6 TEST DH,DH
    (void)integer::logical((((s.dx >> 8) & 0xffu))&(((s.dx >> 8) & 0xffu)),8,flags);
  }
  L0076ddc1: { // 0x76ddc1: 741e JZ 0x0076dde1
    if(integer::condition("JZ",flags)) goto L0076dde1;
  }
  L0076ddc3: { // 0x76ddc3: f7c20000ff00 TEST EDX,0xff0000
    (void)integer::logical((s.dx)&(0x00ff0000u),32,flags);
  }
  L0076ddc9: { // 0x76ddc9: 740c JZ 0x0076ddd7
    if(integer::condition("JZ",flags)) goto L0076ddd7;
  }
  L0076ddcb: { // 0x76ddcb: f7c2000000ff TEST EDX,0xff000000
    (void)integer::logical((s.dx)&(0xff000000u),32,flags);
  }
  L0076ddd1: { // 0x76ddd1: 75c6 JNZ 0x0076dd99
    if(integer::condition("JNZ",flags)) goto L0076dd99;
  }
  L0076ddd3: { // 0x76ddd3: 8917 MOV dword ptr [EDI],EDX
    m.w32((s.di), s.dx);
  }
  L0076ddd5: { // 0x76ddd5: eb18 JMP 0x0076ddef
    goto L0076ddef;
  }
  L0076ddd7: { // 0x76ddd7: 81e2ffff0000 AND EDX,0xffff
    s.dx = integer::logical((s.dx)&(0x0000ffffu),32,flags);
  }
  L0076dddd: { // 0x76dddd: 8917 MOV dword ptr [EDI],EDX
    m.w32((s.di), s.dx);
  }
  L0076dddf: { // 0x76dddf: eb0e JMP 0x0076ddef
    goto L0076ddef;
  }
  L0076dde1: { // 0x76dde1: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0076dde7: { // 0x76dde7: 8917 MOV dword ptr [EDI],EDX
    m.w32((s.di), s.dx);
  }
  L0076dde9: { // 0x76dde9: eb04 JMP 0x0076ddef
    goto L0076ddef;
  }
  L0076ddeb: { // 0x76ddeb: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0076dded: { // 0x76dded: 8917 MOV dword ptr [EDI],EDX
    m.w32((s.di), s.dx);
  }
  L0076ddef: { // 0x76ddef: 83c704 ADD EDI,0x4
    s.di = integer::add(s.di,0x00000004u,32,flags);
  }
  L0076ddf2: { // 0x76ddf2: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0076ddf4: { // 0x76ddf4: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0076ddf5: { // 0x76ddf5: 740a JZ 0x0076de01
    if(integer::condition("JZ",flags)) goto L0076de01;
  }
  L0076ddf7: { // 0x76ddf7: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0076ddf9: { // 0x76ddf9: 8907 MOV dword ptr [EDI],EAX
    m.w32((s.di), s.ax);
  }
  L0076ddfb: { // 0x76ddfb: 83c704 ADD EDI,0x4
    s.di = integer::add(s.di,0x00000004u,32,flags);
  }
  L0076ddfe: { // 0x76ddfe: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0076ddff: { // 0x76ddff: 75f8 JNZ 0x0076ddf9
    if(integer::condition("JNZ",flags)) goto L0076ddf9;
  }
  L0076de01: { // 0x76de01: 83e303 AND EBX,0x3
    s.bx = integer::logical((s.bx)&(0x00000003u),32,flags);
  }
  L0076de04: { // 0x76de04: 7585 JNZ 0x0076dd8b
    if(integer::condition("JNZ",flags)) goto L0076dd8b;
  }
  L0076de06: { // 0x76de06: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0076de0a: { // 0x76de0a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0076de0b: { // 0x76de0b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076de0c: { // 0x76de0c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076de0d: { // 0x76de0d: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 6072688u:f_001ca970(m,s,child,{});break;
case 4259600u:f_0000ff10(m,s,child,{});break;
case 4217840u:f_00005bf0(m,s,child,{});break;
case 6397168u:f_00219cf0(m,s,child,{});break;
case 6086272u:f_001cde80(m,s,child,{});break;
case 4261248u:f_00010580(m,s,child,{});break;
case 7789840u:f_0036dd10(m,s,child,{});break;
default:throw std::domain_error("recovery643 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00526130(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00526130: { // 0x526130: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L00526133: { // 0x526133: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00526134: { // 0x526134: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00526136: { // 0x526136: e835480a00 CALL 0x005ca970
    s.arithmetic_flags=flags; invoke(m,s,f,0x005ca970u,5398843u); flags=s.arithmetic_flags;
  }
  L0052613b: { // 0x52613b: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0052613f: { // 0x52613f: 8b0d1489a200 MOV ECX,dword ptr [0x00a28914]
    s.cx = m.r32((0x00a28914u));
  }
  L00526145: { // 0x526145: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L00526148: { // 0x526148: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0052614c: { // 0x52614c: 899698000000 MOV dword ptr [ESI + 0x98],EDX
    m.w32((s.si+0x00000098u), s.dx);
  }
  L00526152: { // 0x526152: c706b0f77800 MOV dword ptr [ESI],0x78f7b0
    m.w32((s.si), 0x0078f7b0u);
  }
  L00526158: { // 0x526158: c7460494f77800 MOV dword ptr [ESI + 0x4],0x78f794
    m.w32((s.si+0x00000004u), 0x0078f794u);
  }
  L0052615f: { // 0x52615f: c746088cf77800 MOV dword ptr [ESI + 0x8],0x78f78c
    m.w32((s.si+0x00000008u), 0x0078f78cu);
  }
  L00526166: { // 0x526166: c7460c84f77800 MOV dword ptr [ESI + 0xc],0x78f784
    m.w32((s.si+0x0000000cu), 0x0078f784u);
  }
  L0052616d: { // 0x52616d: 668b01 MOV AX,word ptr [ECX]
    s.ax = with_ax(s.ax, m.r16((s.cx)));
  }
  L00526170: { // 0x526170: 663b0558a1a300 CMP AX,word ptr [0x00a3a158]
    (void)integer::sub((s.ax & 0xffffu),m.r16((0x00a3a158u)),16,flags);
  }
  L00526177: { // 0x526177: 750d JNZ 0x00526186
    if(integer::condition("JNZ",flags)) goto L00526186;
  }
  L00526179: { // 0x526179: 668b5102 MOV DX,word ptr [ECX + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.cx+0x00000002u)));
  }
  L0052617d: { // 0x52617d: 663b155aa1a300 CMP DX,word ptr [0x00a3a15a]
    (void)integer::sub((s.dx & 0xffffu),m.r16((0x00a3a15au)),16,flags);
  }
  L00526184: { // 0x526184: 7445 JZ 0x005261cb
    if(integer::condition("JZ",flags)) goto L005261cb;
  }
  L00526186: { // 0x526186: 0fbf4902 MOVSX ECX,word ptr [ECX + 0x2]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000002u)),16));
  }
  L0052618a: { // 0x52618a: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0052618d: { // 0x52618d: c1e108 SHL ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::left);
  }
  L00526190: { // 0x526190: c1e008 SHL EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::left);
  }
  L00526193: { // 0x526193: 81c180000000 ADD ECX,0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L00526199: { // 0x526199: 8d542404 LEA EDX,[ESP + 0x4]
    s.dx = (f.sp+0x00000004u);
  }
  L0052619d: { // 0x52619d: 0580000000 ADD EAX,0x80
    s.ax = integer::add(s.ax,0x00000080u,32,flags);
  }
  L005261a2: { // 0x5261a2: 894c2408 MOV dword ptr [ESP + 0x8],ECX
    m.w32((f.sp+0x00000008u), s.cx);
  }
  L005261a6: { // 0x5261a6: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005261a7: { // 0x5261a7: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005261a9: { // 0x5261a9: 89442408 MOV dword ptr [ESP + 0x8],EAX
    m.w32((f.sp+0x00000008u), s.ax);
  }
  L005261ad: { // 0x5261ad: c744241000000000 MOV dword ptr [ESP + 0x10],0x0
    m.w32((f.sp+0x00000010u), 0x00000000u);
  }
  L005261b5: { // 0x5261b5: c6467600 MOV byte ptr [ESI + 0x76],0x0
    m.w8((s.si+0x00000076u), 0x00000000u);
  }
  L005261b9: { // 0x5261b9: ff154cf97800 CALL dword ptr [0x0078f94c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((0x0078f94cu)),5398975u); flags=s.arithmetic_flags;
  }
  L005261bf: { // 0x5261bf: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005261c1: { // 0x5261c1: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L005261c3: { // 0x5261c3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005261c5: { // 0x5261c5: ff901c010000 CALL dword ptr [EAX + 0x11c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000011cu)),5398987u); flags=s.arithmetic_flags;
  }
  L005261cb: { // 0x5261cb: a190a78100 MOV EAX,[0x0081a790]
    s.ax = m.r32((0x0081a790u));
  }
  L005261d0: { // 0x5261d0: 8b0d98a78100 MOV ECX,dword ptr [0x0081a798]
    s.cx = m.r32((0x0081a798u));
  }
  L005261d6: { // 0x5261d6: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L005261d8: { // 0x5261d8: 7c2f JL 0x00526209
    if(integer::condition("JL",flags)) goto L00526209;
  }
  L005261da: { // 0x5261da: 8a0d95a78100 MOV CL,byte ptr [0x0081a795]
    s.cx = with_al(s.cx, m.r8((0x0081a795u)));
  }
  L005261e0: { // 0x5261e0: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L005261e2: { // 0x5261e2: 7504 JNZ 0x005261e8
    if(integer::condition("JNZ",flags)) goto L005261e8;
  }
  L005261e4: { // 0x5261e4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005261e6: { // 0x5261e6: 7539 JNZ 0x00526221
    if(integer::condition("JNZ",flags)) goto L00526221;
  }
  L005261e8: { // 0x5261e8: 8b0d9ca78100 MOV ECX,dword ptr [0x0081a79c]
    s.cx = m.r32((0x0081a79cu));
  }
  L005261ee: { // 0x5261ee: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005261f0: { // 0x5261f0: 7e2f JLE 0x00526221
    if(integer::condition("JLE",flags)) goto L00526221;
  }
  L005261f2: { // 0x5261f2: 8b1588a78100 MOV EDX,dword ptr [0x0081a788]
    s.dx = m.r32((0x0081a788u));
  }
  L005261f8: { // 0x5261f8: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L005261fa: { // 0x5261fa: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L005261fc: { // 0x5261fc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005261fd: { // 0x5261fd: b988a78100 MOV ECX,0x81a788
    s.cx = 0x0081a788u;
  }
  L00526202: { // 0x526202: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),5399045u); flags=s.arithmetic_flags;
  }
  L00526205: { // 0x526205: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00526207: { // 0x526207: 7418 JZ 0x00526221
    if(integer::condition("JZ",flags)) goto L00526221;
  }
  L00526209: { // 0x526209: 8b0d98a78100 MOV ECX,dword ptr [0x0081a798]
    s.cx = m.r32((0x0081a798u));
  }
  L0052620f: { // 0x52620f: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00526211: { // 0x526211: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00526212: { // 0x526212: 890d98a78100 MOV dword ptr [0x0081a798],ECX
    m.w32((0x0081a798u), s.cx);
  }
  L00526218: { // 0x526218: 8b0d8ca78100 MOV ECX,dword ptr [0x0081a78c]
    s.cx = m.r32((0x0081a78cu));
  }
  L0052621e: { // 0x52621e: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L00526221: { // 0x526221: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00526223: { // 0x526223: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00526224: { // 0x526224: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00526227: { // 0x526227: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00527140(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00527140: { // 0x527140: 83ec34 SUB ESP,0x34
    f.sp = integer::sub(f.sp,0x00000034u,32,flags);
  }
  L00527143: { // 0x527143: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00527144: { // 0x527144: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00527145: { // 0x527145: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00527146: { // 0x527146: 8b742450 MOV ESI,dword ptr [ESP + 0x50]
    s.si = m.r32((f.sp+0x00000050u));
  }
  L0052714a: { // 0x52714a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0052714b: { // 0x52714b: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L0052714d: { // 0x52714d: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0052714e: { // 0x52714e: e82d6d0a00 CALL 0x005cde80
    s.arithmetic_flags=flags; invoke(m,s,f,0x005cde80u,5402963u); flags=s.arithmetic_flags;
  }
  L00527153: { // 0x527153: 8b442448 MOV EAX,dword ptr [ESP + 0x48]
    s.ax = m.r32((f.sp+0x00000048u));
  }
  L00527157: { // 0x527157: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00527159: { // 0x527159: 898564020000 MOV dword ptr [EBP + 0x264],EAX
    m.w32((s.bp+0x00000264u), s.ax);
  }
  L0052715f: { // 0x52715f: b8ffff0000 MOV EAX,0xffff
    s.ax = 0x0000ffffu;
  }
  L00527164: { // 0x527164: 898568020000 MOV dword ptr [EBP + 0x268],EAX
    m.w32((s.bp+0x00000268u), s.ax);
  }
  L0052716a: { // 0x52716a: 89856c020000 MOV dword ptr [EBP + 0x26c],EAX
    m.w32((s.bp+0x0000026cu), s.ax);
  }
  L00527170: { // 0x527170: 899d70020000 MOV dword ptr [EBP + 0x270],EBX
    m.w32((s.bp+0x00000270u), s.bx);
  }
  L00527176: { // 0x527176: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00527178: { // 0x527178: 899d78020000 MOV dword ptr [EBP + 0x278],EBX
    m.w32((s.bp+0x00000278u), s.bx);
  }
  L0052717e: { // 0x52717e: 899d7c020000 MOV dword ptr [EBP + 0x27c],EBX
    m.w32((s.bp+0x0000027cu), s.bx);
  }
  L00527184: { // 0x527184: c6858002000001 MOV byte ptr [EBP + 0x280],0x1
    m.w8((s.bp+0x00000280u), 0x00000001u);
  }
  L0052718b: { // 0x52718b: 889d81020000 MOV byte ptr [EBP + 0x281],BL
    m.w8((s.bp+0x00000281u), (s.bx & 0xffu));
  }
  L00527191: { // 0x527191: c785740200002c027900 MOV dword ptr [EBP + 0x274],0x79022c
    m.w32((s.bp+0x00000274u), 0x0079022cu);
  }
  L0052719b: { // 0x52719b: c785880200000a000000 MOV dword ptr [EBP + 0x288],0xa
    m.w32((s.bp+0x00000288u), 0x0000000au);
  }
  L005271a5: { // 0x5271a5: 899d84020000 MOV dword ptr [EBP + 0x284],EBX
    m.w32((s.bp+0x00000284u), s.bx);
  }
  L005271ab: { // 0x5271ab: 83caff OR EDX,0xffffffff
    s.dx = integer::logical((s.dx)|(0xffffffffu),32,flags);
  }
  L005271ae: { // 0x5271ae: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L005271b0: { // 0x5271b0: 89859c020000 MOV dword ptr [EBP + 0x29c],EAX
    m.w32((s.bp+0x0000029cu), s.ax);
  }
  L005271b6: { // 0x5271b6: 899590020000 MOV dword ptr [EBP + 0x290],EDX
    m.w32((s.bp+0x00000290u), s.dx);
  }
  L005271bc: { // 0x5271bc: 899594020000 MOV dword ptr [EBP + 0x294],EDX
    m.w32((s.bp+0x00000294u), s.dx);
  }
  L005271c2: { // 0x5271c2: 899598020000 MOV dword ptr [EBP + 0x298],EDX
    m.w32((s.bp+0x00000298u), s.dx);
  }
  L005271c8: { // 0x5271c8: 898da0020000 MOV dword ptr [EBP + 0x2a0],ECX
    m.w32((s.bp+0x000002a0u), s.cx);
  }
  L005271ce: { // 0x5271ce: 8b4c244c MOV ECX,dword ptr [ESP + 0x4c]
    s.cx = m.r32((f.sp+0x0000004cu));
  }
  L005271d2: { // 0x5271d2: 8995a4020000 MOV dword ptr [EBP + 0x2a4],EDX
    m.w32((s.bp+0x000002a4u), s.dx);
  }
  L005271d8: { // 0x5271d8: 8b542450 MOV EDX,dword ptr [ESP + 0x50]
    s.dx = m.r32((f.sp+0x00000050u));
  }
  L005271dc: { // 0x5271dc: 81e1ff000000 AND ECX,0xff
    s.cx = integer::logical((s.cx)&(0x000000ffu),32,flags);
  }
  L005271e2: { // 0x5271e2: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L005271e8: { // 0x5271e8: 899d8c020000 MOV dword ptr [EBP + 0x28c],EBX
    m.w32((s.bp+0x0000028cu), s.bx);
  }
  L005271ee: { // 0x5271ee: 899da8020000 MOV dword ptr [EBP + 0x2a8],EBX
    m.w32((s.bp+0x000002a8u), s.bx);
  }
  L005271f4: { // 0x5271f4: 898dac020000 MOV dword ptr [EBP + 0x2ac],ECX
    m.w32((s.bp+0x000002acu), s.cx);
  }
  L005271fa: { // 0x5271fa: 889db0020000 MOV byte ptr [EBP + 0x2b0],BL
    m.w8((s.bp+0x000002b0u), (s.bx & 0xffu));
  }
  L00527200: { // 0x527200: 889db1020000 MOV byte ptr [EBP + 0x2b1],BL
    m.w8((s.bp+0x000002b1u), (s.bx & 0xffu));
  }
  L00527206: { // 0x527206: c685b202000001 MOV byte ptr [EBP + 0x2b2],0x1
    m.w8((s.bp+0x000002b2u), 0x00000001u);
  }
  L0052720d: { // 0x52720d: 889db3020000 MOV byte ptr [EBP + 0x2b3],BL
    m.w8((s.bp+0x000002b3u), (s.bx & 0xffu));
  }
  L00527213: { // 0x527213: 899db4020000 MOV dword ptr [EBP + 0x2b4],EBX
    m.w32((s.bp+0x000002b4u), s.bx);
  }
  L00527219: { // 0x527219: 899db8020000 MOV dword ptr [EBP + 0x2b8],EBX
    m.w32((s.bp+0x000002b8u), s.bx);
  }
  L0052721f: { // 0x52721f: 8995bc020000 MOV dword ptr [EBP + 0x2bc],EDX
    m.w32((s.bp+0x000002bcu), s.dx);
  }
  L00527225: { // 0x527225: c785c002000001000000 MOV dword ptr [EBP + 0x2c0],0x1
    m.w32((s.bp+0x000002c0u), 0x00000001u);
  }
  L0052722f: { // 0x52722f: 889dc4020000 MOV byte ptr [EBP + 0x2c4],BL
    m.w8((s.bp+0x000002c4u), (s.bx & 0xffu));
  }
  L00527235: { // 0x527235: c685d502000001 MOV byte ptr [EBP + 0x2d5],0x1
    m.w8((s.bp+0x000002d5u), 0x00000001u);
  }
  L0052723c: { // 0x52723c: 889dd6020000 MOV byte ptr [EBP + 0x2d6],BL
    m.w8((s.bp+0x000002d6u), (s.bx & 0xffu));
  }
  L00527242: { // 0x527242: 899dd8020000 MOV dword ptr [EBP + 0x2d8],EBX
    m.w32((s.bp+0x000002d8u), s.bx);
  }
  L00527248: { // 0x527248: c7450088017900 MOV dword ptr [EBP],0x790188
    m.w32((s.bp), 0x00790188u);
  }
  L0052724f: { // 0x52724f: c745046c017900 MOV dword ptr [EBP + 0x4],0x79016c
    m.w32((s.bp+0x00000004u), 0x0079016cu);
  }
  L00527256: { // 0x527256: c7450864017900 MOV dword ptr [EBP + 0x8],0x790164
    m.w32((s.bp+0x00000008u), 0x00790164u);
  }
  L0052725d: { // 0x52725d: c7450c5c017900 MOV dword ptr [EBP + 0xc],0x79015c
    m.w32((s.bp+0x0000000cu), 0x0079015cu);
  }
  L00527264: { // 0x527264: a1c087aa00 MOV EAX,[0x00aa87c0]
    s.ax = m.r32((0x00aa87c0u));
  }
  L00527269: { // 0x527269: 8b0dc887aa00 MOV ECX,dword ptr [0x00aa87c8]
    s.cx = m.r32((0x00aa87c8u));
  }
  L0052726f: { // 0x52726f: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00527271: { // 0x527271: 7c2b JL 0x0052729e
    if(integer::condition("JL",flags)) goto L0052729e;
  }
  L00527273: { // 0x527273: 381dc587aa00 CMP byte ptr [0x00aa87c5],BL
    (void)integer::sub(m.r8((0x00aa87c5u)),(s.bx & 0xffu),8,flags);
  }
  L00527279: { // 0x527279: 7504 JNZ 0x0052727f
    if(integer::condition("JNZ",flags)) goto L0052727f;
  }
  L0052727b: { // 0x52727b: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0052727d: { // 0x52727d: 7537 JNZ 0x005272b6
    if(integer::condition("JNZ",flags)) goto L005272b6;
  }
  L0052727f: { // 0x52727f: 8b0dcc87aa00 MOV ECX,dword ptr [0x00aa87cc]
    s.cx = m.r32((0x00aa87ccu));
  }
  L00527285: { // 0x527285: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L00527287: { // 0x527287: 7e2d JLE 0x005272b6
    if(integer::condition("JLE",flags)) goto L005272b6;
  }
  L00527289: { // 0x527289: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0052728b: { // 0x52728b: a1b887aa00 MOV EAX,[0x00aa87b8]
    s.ax = m.r32((0x00aa87b8u));
  }
  L00527290: { // 0x527290: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00527291: { // 0x527291: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00527292: { // 0x527292: b9b887aa00 MOV ECX,0xaa87b8
    s.cx = 0x00aa87b8u;
  }
  L00527297: { // 0x527297: ff5008 CALL dword ptr [EAX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000008u)),5403290u); flags=s.arithmetic_flags;
  }
  L0052729a: { // 0x52729a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0052729c: { // 0x52729c: 7418 JZ 0x005272b6
    if(integer::condition("JZ",flags)) goto L005272b6;
  }
  L0052729e: { // 0x52729e: 8b0dc887aa00 MOV ECX,dword ptr [0x00aa87c8]
    s.cx = m.r32((0x00aa87c8u));
  }
  L005272a4: { // 0x5272a4: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L005272a6: { // 0x5272a6: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L005272a7: { // 0x5272a7: 890dc887aa00 MOV dword ptr [0x00aa87c8],ECX
    m.w32((0x00aa87c8u), s.cx);
  }
  L005272ad: { // 0x5272ad: 8b0dbc87aa00 MOV ECX,dword ptr [0x00aa87bc]
    s.cx = m.r32((0x00aa87bcu));
  }
  L005272b3: { // 0x5272b3: 892c81 MOV dword ptr [ECX + EAX*0x4],EBP
    m.w32((s.cx+(s.ax * 0x00000004u)), s.bp);
  }
  L005272b6: { // 0x5272b6: 385c2458 CMP byte ptr [ESP + 0x58],BL
    (void)integer::sub(m.r8((f.sp+0x00000058u)),(s.bx & 0xffu),8,flags);
  }
  L005272ba: { // 0x5272ba: 7553 JNZ 0x0052730f
    if(integer::condition("JNZ",flags)) goto L0052730f;
  }
  L005272bc: { // 0x5272bc: a11889a200 MOV EAX,[0x00a28918]
    s.ax = m.r32((0x00a28918u));
  }
  L005272c1: { // 0x5272c1: 8b0d2089a200 MOV ECX,dword ptr [0x00a28920]
    s.cx = m.r32((0x00a28920u));
  }
  L005272c7: { // 0x5272c7: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L005272c9: { // 0x5272c9: 7c2c JL 0x005272f7
    if(integer::condition("JL",flags)) goto L005272f7;
  }
  L005272cb: { // 0x5272cb: 381d1d89a200 CMP byte ptr [0x00a2891d],BL
    (void)integer::sub(m.r8((0x00a2891du)),(s.bx & 0xffu),8,flags);
  }
  L005272d1: { // 0x5272d1: 7504 JNZ 0x005272d7
    if(integer::condition("JNZ",flags)) goto L005272d7;
  }
  L005272d3: { // 0x5272d3: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L005272d5: { // 0x5272d5: 7538 JNZ 0x0052730f
    if(integer::condition("JNZ",flags)) goto L0052730f;
  }
  L005272d7: { // 0x5272d7: 8b0d2489a200 MOV ECX,dword ptr [0x00a28924]
    s.cx = m.r32((0x00a28924u));
  }
  L005272dd: { // 0x5272dd: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L005272df: { // 0x5272df: 7e2e JLE 0x0052730f
    if(integer::condition("JLE",flags)) goto L0052730f;
  }
  L005272e1: { // 0x5272e1: 8b151089a200 MOV EDX,dword ptr [0x00a28910]
    s.dx = m.r32((0x00a28910u));
  }
  L005272e7: { // 0x5272e7: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L005272e9: { // 0x5272e9: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005272ea: { // 0x5272ea: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005272eb: { // 0x5272eb: b91089a200 MOV ECX,0xa28910
    s.cx = 0x00a28910u;
  }
  L005272f0: { // 0x5272f0: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),5403379u); flags=s.arithmetic_flags;
  }
  L005272f3: { // 0x5272f3: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005272f5: { // 0x5272f5: 7418 JZ 0x0052730f
    if(integer::condition("JZ",flags)) goto L0052730f;
  }
  L005272f7: { // 0x5272f7: 8b0d2089a200 MOV ECX,dword ptr [0x00a28920]
    s.cx = m.r32((0x00a28920u));
  }
  L005272fd: { // 0x5272fd: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L005272ff: { // 0x5272ff: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00527300: { // 0x527300: 890d2089a200 MOV dword ptr [0x00a28920],ECX
    m.w32((0x00a28920u), s.cx);
  }
  L00527306: { // 0x527306: 8b0d1489a200 MOV ECX,dword ptr [0x00a28914]
    s.cx = m.r32((0x00a28914u));
  }
  L0052730c: { // 0x52730c: 892c81 MOV dword ptr [ECX + EAX*0x4],EBP
    m.w32((s.cx+(s.ax * 0x00000004u)), s.bp);
  }
  L0052730f: { // 0x52730f: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L00527311: { // 0x527311: 7506 JNZ 0x00527319
    if(integer::condition("JNZ",flags)) goto L00527319;
  }
  L00527313: { // 0x527313: 885c2410 MOV byte ptr [ESP + 0x10],BL
    m.w8((f.sp+0x00000010u), (s.bx & 0xffu));
  }
  L00527317: { // 0x527317: eb14 JMP 0x0052732d
    goto L0052732d;
  }
  L00527319: { // 0x527319: 6a30 PUSH 0x30
    f.push(m,0x00000030u);
  }
  L0052731b: { // 0x52731b: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  L0052731f: { // 0x52731f: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00527320: { // 0x527320: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00527321: { // 0x527321: e8ea692400 CALL 0x0076dd10
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076dd10u,5403430u); flags=s.arithmetic_flags;
  }
  L00527326: { // 0x527326: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00527329: { // 0x527329: 885c2440 MOV byte ptr [ESP + 0x40],BL
    m.w8((f.sp+0x00000040u), (s.bx & 0xffu));
  }
  L0052732d: { // 0x52732d: 8d7d64 LEA EDI,[EBP + 0x64]
    s.di = (s.bp+0x00000064u);
  }
  L00527330: { // 0x527330: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L00527334: { // 0x527334: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L00527336: { // 0x527336: 740c JZ 0x00527344
    if(integer::condition("JZ",flags)) goto L00527344;
  }
  L00527338: { // 0x527338: b90c000000 MOV ECX,0xc
    s.cx = 0x0000000cu;
  }
  L0052733d: { // 0x52733d: 8d742410 LEA ESI,[ESP + 0x10]
    s.si = (f.sp+0x00000010u);
  }
  L00527341: { // 0x527341: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L00527343: { // 0x527343: a4 MOVSB ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::single);
  }
  L00527344: { // 0x527344: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00527345: { // 0x527345: 889dc5020000 MOV byte ptr [EBP + 0x2c5],BL
    m.w8((s.bp+0x000002c5u), (s.bx & 0xffu));
  }
  L0052734b: { // 0x52734b: c685ff01000001 MOV byte ptr [EBP + 0x1ff],0x1
    m.w8((s.bp+0x000001ffu), 0x00000001u);
  }
  L00527352: { // 0x527352: 889d00020000 MOV byte ptr [EBP + 0x200],BL
    m.w8((s.bp+0x00000200u), (s.bx & 0xffu));
  }
  L00527358: { // 0x527358: 889d01020000 MOV byte ptr [EBP + 0x201],BL
    m.w8((s.bp+0x00000201u), (s.bx & 0xffu));
  }
  L0052735e: { // 0x52735e: c6850202000001 MOV byte ptr [EBP + 0x202],0x1
    m.w8((s.bp+0x00000202u), 0x00000001u);
  }
  L00527365: { // 0x527365: c6850302000001 MOV byte ptr [EBP + 0x203],0x1
    m.w8((s.bp+0x00000203u), 0x00000001u);
  }
  L0052736c: { // 0x52736c: 889d05020000 MOV byte ptr [EBP + 0x205],BL
    m.w8((s.bp+0x00000205u), (s.bx & 0xffu));
  }
  L00527372: { // 0x527372: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L00527374: { // 0x527374: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00527375: { // 0x527375: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00527376: { // 0x527376: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00527377: { // 0x527377: 83c434 ADD ESP,0x34
    f.sp = integer::add(f.sp,0x00000034u,32,flags);
  }
  L0052737a: { // 0x52737a: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
