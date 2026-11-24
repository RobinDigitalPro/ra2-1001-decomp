#include "recovered/recovery_b617_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b617 {
namespace {
void f_001ca970(Memory&,State&,Frame&,const Operations&);
void f_0000ff10(Memory&,State&,Frame&,const Operations&);
void f_00005bf0(Memory&,State&,Frame&,const Operations&);
void f_00219cf0(Memory&,State&,Frame&,const Operations&);
void f_000ce9d0(Memory&,State&,Frame&,const Operations&);
void f_0000ffd0(Memory&,State&,Frame&,const Operations&);
void f_0025a120(Memory&,State&,Frame&,const Operations&);
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

void f_000ce9d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004ce9d0: { // 0x4ce9d0: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004ce9d2: { // 0x4ce9d2: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  L004ce9d8: { // 0x4ce9d8: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L004ce9da: { // 0x4ce9da: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L004ce9dc: { // 0x4ce9dc: 894808 MOV dword ptr [EAX + 0x8],ECX
    m.w32((s.ax+0x00000008u), s.cx);
  }
  L004ce9df: { // 0x4ce9df: 8b156c89a200 MOV EDX,dword ptr [0x00a2896c]
    s.dx = m.r32((0x00a2896cu));
  }
  L004ce9e5: { // 0x4ce9e5: 89500c MOV dword ptr [EAX + 0xc],EDX
    m.w32((s.ax+0x0000000cu), s.dx);
  }
  L004ce9e8: { // 0x4ce9e8: 894814 MOV dword ptr [EAX + 0x14],ECX
    m.w32((s.ax+0x00000014u), s.cx);
  }
  L004ce9eb: { // 0x4ce9eb: 894818 MOV dword ptr [EAX + 0x18],ECX
    m.w32((s.ax+0x00000018u), s.cx);
  }
  L004ce9ee: { // 0x4ce9ee: 89481c MOV dword ptr [EAX + 0x1c],ECX
    m.w32((s.ax+0x0000001cu), s.cx);
  }
  L004ce9f1: { // 0x4ce9f1: 894820 MOV dword ptr [EAX + 0x20],ECX
    m.w32((s.ax+0x00000020u), s.cx);
  }
  L004ce9f4: { // 0x4ce9f4: 894824 MOV dword ptr [EAX + 0x24],ECX
    m.w32((s.ax+0x00000024u), s.cx);
  }
  L004ce9f7: { // 0x4ce9f7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0000ffd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0040ffd0: { // 0x0040ffd0: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L0040ffd6: { // 0x0040ffd6: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0040ffd8: { // 0x0040ffd8: 750c JNZ 0x0040ffe6
    if(integer::condition("JNZ",flags)) goto L0040ffe6;
  }
  L0040ffda: { // 0x0040ffda: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L0040ffde: { // 0x0040ffde: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0040ffe0: { // 0x0040ffe0: 89410c MOV dword ptr [ECX + 0xc],EAX
    m.w32((s.cx+0x0000000cu), s.ax);
  }
  L0040ffe3: { // 0x0040ffe3: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0040ffe6: { // 0x0040ffe6: e835a12400 CALL 0x0065a120
    s.arithmetic_flags=flags; invoke(m,s,f,0x0065a120u,4259819u); flags=s.arithmetic_flags;
  }
  L0040ffeb: { // 0x0040ffeb: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L0040ffef: { // 0x0040ffef: 89420c MOV dword ptr [EDX + 0xc],EAX
    m.w32((s.dx+0x0000000cu), s.ax);
  }
  L0040fff2: { // 0x0040fff2: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0025a120(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0065a120: { // 0x65a120: 8b8114020000 MOV EAX,dword ptr [ECX + 0x214]
    s.ax = m.r32((s.cx+0x00000214u));
  }
  L0065a126: { // 0x65a126: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0065a127: { // 0x65a127: 898114020000 MOV dword ptr [ECX + 0x214],EAX
    m.w32((s.cx+0x00000214u), s.ax);
  }
  L0065a12d: { // 0x65a12d: c3 RET
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
case 5040592u:f_000ce9d0(m,s,child,{});break;
case 4259792u:f_0000ffd0(m,s,child,{});break;
case 6660384u:f_0025a120(m,s,child,{});break;
default:throw std::domain_error("recovery617 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_004208e0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004208e0: { // 0x4208e0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004208e1: { // 0x4208e1: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004208e2: { // 0x4208e2: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004208e4: { // 0x4208e4: e887a01a00 CALL 0x005ca970
    s.arithmetic_flags=flags; invoke(m,s,f,0x005ca970u,4327657u); flags=s.arithmetic_flags;
  }
  L004208e9: { // 0x4208e9: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L004208eb: { // 0x4208eb: 680000803f PUSH 0x3f800000
    f.push(m,0x3f800000u);
  }
  L004208f0: { // 0x4208f0: 899e98000000 MOV dword ptr [ESI + 0x98],EBX
    m.w32((s.si+0x00000098u), s.bx);
  }
  L004208f6: { // 0x4208f6: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  L004208fb: { // 0x4208fb: 89869c000000 MOV dword ptr [ESI + 0x9c],EAX
    m.w32((s.si+0x0000009cu), s.ax);
  }
  L00420901: { // 0x420901: 899ea4000000 MOV dword ptr [ESI + 0xa4],EBX
    m.w32((s.si+0x000000a4u), s.bx);
  }
  L00420907: { // 0x420907: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L0042090a: { // 0x42090a: 899ea8000000 MOV dword ptr [ESI + 0xa8],EBX
    m.w32((s.si+0x000000a8u), s.bx);
  }
  L00420910: { // 0x420910: c786ac00000001000000 MOV dword ptr [ESI + 0xac],0x1
    m.w32((s.si+0x000000acu), 0x00000001u);
  }
  L0042091a: { // 0x42091a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0042091b: { // 0x42091b: 899eb0000000 MOV dword ptr [ESI + 0xb0],EBX
    m.w32((s.si+0x000000b0u), s.bx);
  }
  L00420921: { // 0x420921: 899eb4000000 MOV dword ptr [ESI + 0xb4],EBX
    m.w32((s.si+0x000000b4u), s.bx);
  }
  L00420927: { // 0x420927: 8986b8000000 MOV dword ptr [ESI + 0xb8],EAX
    m.w32((s.si+0x000000b8u), s.ax);
  }
  L0042092d: { // 0x42092d: 899ebc000000 MOV dword ptr [ESI + 0xbc],EBX
    m.w32((s.si+0x000000bcu), s.bx);
  }
  L00420933: { // 0x420933: 8986c0000000 MOV dword ptr [ESI + 0xc0],EAX
    m.w32((s.si+0x000000c0u), s.ax);
  }
  L00420939: { // 0x420939: c786e4000000e8030000 MOV dword ptr [ESI + 0xe4],0x3e8
    m.w32((s.si+0x000000e4u), 0x000003e8u);
  }
  L00420943: { // 0x420943: 899ee8000000 MOV dword ptr [ESI + 0xe8],EBX
    m.w32((s.si+0x000000e8u), s.bx);
  }
  L00420949: { // 0x420949: 899eec000000 MOV dword ptr [ESI + 0xec],EBX
    m.w32((s.si+0x000000ecu), s.bx);
  }
  L0042094f: { // 0x42094f: 889e00010000 MOV byte ptr [ESI + 0x100],BL
    m.w8((s.si+0x00000100u), (s.bx & 0xffu));
  }
  L00420955: { // 0x420955: 889e01010000 MOV byte ptr [ESI + 0x101],BL
    m.w8((s.si+0x00000101u), (s.bx & 0xffu));
  }
  L0042095b: { // 0x42095b: 889e02010000 MOV byte ptr [ESI + 0x102],BL
    m.w8((s.si+0x00000102u), (s.bx & 0xffu));
  }
  L00420961: { // 0x420961: 889e03010000 MOV byte ptr [ESI + 0x103],BL
    m.w8((s.si+0x00000103u), (s.bx & 0xffu));
  }
  L00420967: { // 0x420967: 899e04010000 MOV dword ptr [ESI + 0x104],EBX
    m.w32((s.si+0x00000104u), s.bx);
  }
  L0042096d: { // 0x42096d: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0042096e: { // 0x42096e: 899e08010000 MOV dword ptr [ESI + 0x108],EBX
    m.w32((s.si+0x00000108u), s.bx);
  }
  L00420974: { // 0x420974: 899e10010000 MOV dword ptr [ESI + 0x110],EBX
    m.w32((s.si+0x00000110u), s.bx);
  }
  L0042097a: { // 0x42097a: 899e18010000 MOV dword ptr [ESI + 0x118],EBX
    m.w32((s.si+0x00000118u), s.bx);
  }
  L00420980: { // 0x420980: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00420981: { // 0x420981: 8d8e38010000 LEA ECX,[ESI + 0x138]
    s.cx = (s.si+0x00000138u);
  }
  L00420987: { // 0x420987: 899e0c010000 MOV dword ptr [ESI + 0x10c],EBX
    m.w32((s.si+0x0000010cu), s.bx);
  }
  L0042098d: { // 0x42098d: 899e14010000 MOV dword ptr [ESI + 0x114],EBX
    m.w32((s.si+0x00000114u), s.bx);
  }
  L00420993: { // 0x420993: 899e1c010000 MOV dword ptr [ESI + 0x11c],EBX
    m.w32((s.si+0x0000011cu), s.bx);
  }
  L00420999: { // 0x420999: e852931f00 CALL 0x00619cf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00619cf0u,4327838u); flags=s.arithmetic_flags;
  }
  L0042099e: { // 0x42099e: 680000803f PUSH 0x3f800000
    f.push(m,0x3f800000u);
  }
  L004209a3: { // 0x4209a3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004209a4: { // 0x4209a4: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004209a5: { // 0x4209a5: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004209a6: { // 0x4209a6: 8d8e48010000 LEA ECX,[ESI + 0x148]
    s.cx = (s.si+0x00000148u);
  }
  L004209ac: { // 0x4209ac: e83f931f00 CALL 0x00619cf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00619cf0u,4327857u); flags=s.arithmetic_flags;
  }
  L004209b1: { // 0x4209b1: 899e68010000 MOV dword ptr [ESI + 0x168],EBX
    m.w32((s.si+0x00000168u), s.bx);
  }
  L004209b7: { // 0x4209b7: 889e59010000 MOV byte ptr [ESI + 0x159],BL
    m.w8((s.si+0x00000159u), (s.bx & 0xffu));
  }
  L004209bd: { // 0x4209bd: 899e64010000 MOV dword ptr [ESI + 0x164],EBX
    m.w32((s.si+0x00000164u), s.bx);
  }
  L004209c3: { // 0x4209c3: 899e6c010000 MOV dword ptr [ESI + 0x16c],EBX
    m.w32((s.si+0x0000016cu), s.bx);
  }
  L004209c9: { // 0x4209c9: 889e74010000 MOV byte ptr [ESI + 0x174],BL
    m.w8((s.si+0x00000174u), (s.bx & 0xffu));
  }
  L004209cf: { // 0x4209cf: c6867501000001 MOV byte ptr [ESI + 0x175],0x1
    m.w8((s.si+0x00000175u), 0x00000001u);
  }
  L004209d6: { // 0x4209d6: 889e76010000 MOV byte ptr [ESI + 0x176],BL
    m.w8((s.si+0x00000176u), (s.bx & 0xffu));
  }
  L004209dc: { // 0x4209dc: 889e77010000 MOV byte ptr [ESI + 0x177],BL
    m.w8((s.si+0x00000177u), (s.bx & 0xffu));
  }
  L004209e2: { // 0x4209e2: 889e7b010000 MOV byte ptr [ESI + 0x17b],BL
    m.w8((s.si+0x0000017bu), (s.bx & 0xffu));
  }
  L004209e8: { // 0x4209e8: c6867c01000001 MOV byte ptr [ESI + 0x17c],0x1
    m.w8((s.si+0x0000017cu), 0x00000001u);
  }
  L004209ef: { // 0x4209ef: 889e7d010000 MOV byte ptr [ESI + 0x17d],BL
    m.w8((s.si+0x0000017du), (s.bx & 0xffu));
  }
  L004209f5: { // 0x4209f5: 889e7e010000 MOV byte ptr [ESI + 0x17e],BL
    m.w8((s.si+0x0000017eu), (s.bx & 0xffu));
  }
  L004209fb: { // 0x4209fb: c70684707800 MOV dword ptr [ESI],0x787084
    m.w32((s.si), 0x00787084u);
  }
  L00420a01: { // 0x420a01: c7460468707800 MOV dword ptr [ESI + 0x4],0x787068
    m.w32((s.si+0x00000004u), 0x00787068u);
  }
  L00420a08: { // 0x420a08: c7460860707800 MOV dword ptr [ESI + 0x8],0x787060
    m.w32((s.si+0x00000008u), 0x00787060u);
  }
  L00420a0f: { // 0x420a0f: c7460c58707800 MOV dword ptr [ESI + 0xc],0x787058
    m.w32((s.si+0x0000000cu), 0x00787058u);
  }
  L00420a16: { // 0x420a16: a1b885a200 MOV EAX,[0x00a285b8]
    s.ax = m.r32((0x00a285b8u));
  }
  L00420a1b: { // 0x420a1b: 8b0dc085a200 MOV ECX,dword ptr [0x00a285c0]
    s.cx = m.r32((0x00a285c0u));
  }
  L00420a21: { // 0x420a21: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00420a23: { // 0x420a23: 7c2c JL 0x00420a51
    if(integer::condition("JL",flags)) goto L00420a51;
  }
  L00420a25: { // 0x420a25: 381dbd85a200 CMP byte ptr [0x00a285bd],BL
    (void)integer::sub(m.r8((0x00a285bdu)),(s.bx & 0xffu),8,flags);
  }
  L00420a2b: { // 0x420a2b: 7504 JNZ 0x00420a31
    if(integer::condition("JNZ",flags)) goto L00420a31;
  }
  L00420a2d: { // 0x420a2d: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00420a2f: { // 0x420a2f: 7538 JNZ 0x00420a69
    if(integer::condition("JNZ",flags)) goto L00420a69;
  }
  L00420a31: { // 0x420a31: 8b0dc485a200 MOV ECX,dword ptr [0x00a285c4]
    s.cx = m.r32((0x00a285c4u));
  }
  L00420a37: { // 0x420a37: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L00420a39: { // 0x420a39: 7e2e JLE 0x00420a69
    if(integer::condition("JLE",flags)) goto L00420a69;
  }
  L00420a3b: { // 0x420a3b: 8b15b085a200 MOV EDX,dword ptr [0x00a285b0]
    s.dx = m.r32((0x00a285b0u));
  }
  L00420a41: { // 0x420a41: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00420a43: { // 0x420a43: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00420a44: { // 0x420a44: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00420a45: { // 0x420a45: b9b085a200 MOV ECX,0xa285b0
    s.cx = 0x00a285b0u;
  }
  L00420a4a: { // 0x420a4a: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),4328013u); flags=s.arithmetic_flags;
  }
  L00420a4d: { // 0x420a4d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00420a4f: { // 0x420a4f: 7418 JZ 0x00420a69
    if(integer::condition("JZ",flags)) goto L00420a69;
  }
  L00420a51: { // 0x420a51: 8b0dc085a200 MOV ECX,dword ptr [0x00a285c0]
    s.cx = m.r32((0x00a285c0u));
  }
  L00420a57: { // 0x420a57: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00420a59: { // 0x420a59: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00420a5a: { // 0x420a5a: 890dc085a200 MOV dword ptr [0x00a285c0],ECX
    m.w32((0x00a285c0u), s.cx);
  }
  L00420a60: { // 0x420a60: 8b0db485a200 MOV ECX,dword ptr [0x00a285b4]
    s.cx = m.r32((0x00a285b4u));
  }
  L00420a66: { // 0x420a66: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L00420a69: { // 0x420a69: 8d8e80010000 LEA ECX,[ESI + 0x180]
    s.cx = (s.si+0x00000180u);
  }
  L00420a6f: { // 0x420a6f: e87c51feff CALL 0x00405bf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00405bf0u,4328052u); flags=s.arithmetic_flags;
  }
  L00420a74: { // 0x420a74: 8d8e94010000 LEA ECX,[ESI + 0x194]
    s.cx = (s.si+0x00000194u);
  }
  L00420a7a: { // 0x420a7a: e87151feff CALL 0x00405bf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00405bf0u,4328063u); flags=s.arithmetic_flags;
  }
  L00420a7f: { // 0x420a7f: c6467d01 MOV byte ptr [ESI + 0x7d],0x1
    m.w8((s.si+0x0000007du), 0x00000001u);
  }
  L00420a83: { // 0x420a83: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00420a85: { // 0x420a85: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00420a86: { // 0x420a86: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00420a87: { // 0x420a87: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_0045f020(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0045f020: { // 0x45f020: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0045f021: { // 0x45f021: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0045f022: { // 0x45f022: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0045f024: { // 0x45f024: e847b91600 CALL 0x005ca970
    s.arithmetic_flags=flags; invoke(m,s,f,0x005ca970u,4583465u); flags=s.arithmetic_flags;
  }
  L0045f029: { // 0x45f029: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0045f02b: { // 0x45f02b: 8d8ea4000000 LEA ECX,[ESI + 0xa4]
    s.cx = (s.si+0x000000a4u);
  }
  L0045f031: { // 0x45f031: 899e98000000 MOV dword ptr [ESI + 0x98],EBX
    m.w32((s.si+0x00000098u), s.bx);
  }
  L0045f037: { // 0x45f037: 899e9c000000 MOV dword ptr [ESI + 0x9c],EBX
    m.w32((s.si+0x0000009cu), s.bx);
  }
  L0045f03d: { // 0x45f03d: 889ea0000000 MOV byte ptr [ESI + 0xa0],BL
    m.w8((s.si+0x000000a0u), (s.bx & 0xffu));
  }
  L0045f043: { // 0x45f043: e888f90600 CALL 0x004ce9d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ce9d0u,4583496u); flags=s.arithmetic_flags;
  }
  L0045f048: { // 0x45f048: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0045f04a: { // 0x45f04a: 899e08010000 MOV dword ptr [ESI + 0x108],EBX
    m.w32((s.si+0x00000108u), s.bx);
  }
  L0045f050: { // 0x45f050: 8886ec000000 MOV byte ptr [ESI + 0xec],AL
    m.w8((s.si+0x000000ecu), (s.ax & 0xffu));
  }
  L0045f056: { // 0x45f056: 8886ed000000 MOV byte ptr [ESI + 0xed],AL
    m.w8((s.si+0x000000edu), (s.ax & 0xffu));
  }
  L0045f05c: { // 0x45f05c: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L0045f05f: { // 0x45f05f: 889ecc000000 MOV byte ptr [ESI + 0xcc],BL
    m.w8((s.si+0x000000ccu), (s.bx & 0xffu));
  }
  L0045f065: { // 0x45f065: 899ee8000000 MOV dword ptr [ESI + 0xe8],EBX
    m.w32((s.si+0x000000e8u), s.bx);
  }
  L0045f06b: { // 0x45f06b: 899ef0000000 MOV dword ptr [ESI + 0xf0],EBX
    m.w32((s.si+0x000000f0u), s.bx);
  }
  L0045f071: { // 0x45f071: 899ef4000000 MOV dword ptr [ESI + 0xf4],EBX
    m.w32((s.si+0x000000f4u), s.bx);
  }
  L0045f077: { // 0x45f077: 899ef8000000 MOV dword ptr [ESI + 0xf8],EBX
    m.w32((s.si+0x000000f8u), s.bx);
  }
  L0045f07d: { // 0x45f07d: 8986fc000000 MOV dword ptr [ESI + 0xfc],EAX
    m.w32((s.si+0x000000fcu), s.ax);
  }
  L0045f083: { // 0x45f083: 899e00010000 MOV dword ptr [ESI + 0x100],EBX
    m.w32((s.si+0x00000100u), s.bx);
  }
  L0045f089: { // 0x45f089: 899e0c010000 MOV dword ptr [ESI + 0x10c],EBX
    m.w32((s.si+0x0000010cu), s.bx);
  }
  L0045f08f: { // 0x45f08f: 899e10010000 MOV dword ptr [ESI + 0x110],EBX
    m.w32((s.si+0x00000110u), s.bx);
  }
  L0045f095: { // 0x45f095: 889e14010000 MOV byte ptr [ESI + 0x114],BL
    m.w8((s.si+0x00000114u), (s.bx & 0xffu));
  }
  L0045f09b: { // 0x45f09b: 889e15010000 MOV byte ptr [ESI + 0x115],BL
    m.w8((s.si+0x00000115u), (s.bx & 0xffu));
  }
  L0045f0a1: { // 0x45f0a1: 899e18010000 MOV dword ptr [ESI + 0x118],EBX
    m.w32((s.si+0x00000118u), s.bx);
  }
  L0045f0a7: { // 0x45f0a7: 66898634010000 MOV word ptr [ESI + 0x134],AX
    m.w16((s.si+0x00000134u), (s.ax & 0xffffu));
  }
  L0045f0ae: { // 0x45f0ae: 66898636010000 MOV word ptr [ESI + 0x136],AX
    m.w16((s.si+0x00000136u), (s.ax & 0xffffu));
  }
  L0045f0b5: { // 0x45f0b5: 8d4604 LEA EAX,[ESI + 0x4]
    s.ax = (s.si+0x00000004u);
  }
  L0045f0b8: { // 0x45f0b8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0045f0b9: { // 0x45f0b9: 899e3c010000 MOV dword ptr [ESI + 0x13c],EBX
    m.w32((s.si+0x0000013cu), s.bx);
  }
  L0045f0bf: { // 0x45f0bf: 889e40010000 MOV byte ptr [ESI + 0x140],BL
    m.w8((s.si+0x00000140u), (s.bx & 0xffu));
  }
  L0045f0c5: { // 0x45f0c5: c70674837800 MOV dword ptr [ESI],0x788374
    m.w32((s.si), 0x00788374u);
  }
  L0045f0cb: { // 0x45f0cb: c70058837800 MOV dword ptr [EAX],0x788358
    m.w32((s.ax), 0x00788358u);
  }
  L0045f0d1: { // 0x45f0d1: c7460850837800 MOV dword ptr [ESI + 0x8],0x788350
    m.w32((s.si+0x00000008u), 0x00788350u);
  }
  L0045f0d8: { // 0x45f0d8: c7460c48837800 MOV dword ptr [ESI + 0xc],0x788348
    m.w32((s.si+0x0000000cu), 0x00788348u);
  }
  L0045f0df: { // 0x45f0df: e8ec0efbff CALL 0x0040ffd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0040ffd0u,4583652u); flags=s.arithmetic_flags;
  }
  L0045f0e4: { // 0x45f0e4: 899e1c010000 MOV dword ptr [ESI + 0x11c],EBX
    m.w32((s.si+0x0000011cu), s.bx);
  }
  L0045f0ea: { // 0x45f0ea: 899e20010000 MOV dword ptr [ESI + 0x120],EBX
    m.w32((s.si+0x00000120u), s.bx);
  }
  L0045f0f0: { // 0x45f0f0: 899e24010000 MOV dword ptr [ESI + 0x124],EBX
    m.w32((s.si+0x00000124u), s.bx);
  }
  L0045f0f6: { // 0x45f0f6: 899e28010000 MOV dword ptr [ESI + 0x128],EBX
    m.w32((s.si+0x00000128u), s.bx);
  }
  L0045f0fc: { // 0x45f0fc: 899e2c010000 MOV dword ptr [ESI + 0x12c],EBX
    m.w32((s.si+0x0000012cu), s.bx);
  }
  L0045f102: { // 0x45f102: 899e30010000 MOV dword ptr [ESI + 0x130],EBX
    m.w32((s.si+0x00000130u), s.bx);
  }
  L0045f108: { // 0x45f108: a13089a200 MOV EAX,[0x00a28930]
    s.ax = m.r32((0x00a28930u));
  }
  L0045f10d: { // 0x45f10d: 8b0d3889a200 MOV ECX,dword ptr [0x00a28938]
    s.cx = m.r32((0x00a28938u));
  }
  L0045f113: { // 0x45f113: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L0045f115: { // 0x45f115: 7c2b JL 0x0045f142
    if(integer::condition("JL",flags)) goto L0045f142;
  }
  L0045f117: { // 0x45f117: 381d3589a200 CMP byte ptr [0x00a28935],BL
    (void)integer::sub(m.r8((0x00a28935u)),(s.bx & 0xffu),8,flags);
  }
  L0045f11d: { // 0x45f11d: 7504 JNZ 0x0045f123
    if(integer::condition("JNZ",flags)) goto L0045f123;
  }
  L0045f11f: { // 0x45f11f: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0045f121: { // 0x45f121: 7537 JNZ 0x0045f15a
    if(integer::condition("JNZ",flags)) goto L0045f15a;
  }
  L0045f123: { // 0x45f123: 8b0d3c89a200 MOV ECX,dword ptr [0x00a2893c]
    s.cx = m.r32((0x00a2893cu));
  }
  L0045f129: { // 0x45f129: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L0045f12b: { // 0x45f12b: 7e2d JLE 0x0045f15a
    if(integer::condition("JLE",flags)) goto L0045f15a;
  }
  L0045f12d: { // 0x45f12d: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0045f12f: { // 0x45f12f: a12889a200 MOV EAX,[0x00a28928]
    s.ax = m.r32((0x00a28928u));
  }
  L0045f134: { // 0x45f134: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0045f135: { // 0x45f135: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0045f136: { // 0x45f136: b92889a200 MOV ECX,0xa28928
    s.cx = 0x00a28928u;
  }
  L0045f13b: { // 0x45f13b: ff5008 CALL dword ptr [EAX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000008u)),4583742u); flags=s.arithmetic_flags;
  }
  L0045f13e: { // 0x45f13e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0045f140: { // 0x45f140: 7418 JZ 0x0045f15a
    if(integer::condition("JZ",flags)) goto L0045f15a;
  }
  L0045f142: { // 0x45f142: 8b0d3889a200 MOV ECX,dword ptr [0x00a28938]
    s.cx = m.r32((0x00a28938u));
  }
  L0045f148: { // 0x45f148: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0045f14a: { // 0x45f14a: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0045f14b: { // 0x45f14b: 890d3889a200 MOV dword ptr [0x00a28938],ECX
    m.w32((0x00a28938u), s.cx);
  }
  L0045f151: { // 0x45f151: 8b0d2c89a200 MOV ECX,dword ptr [0x00a2892c]
    s.cx = m.r32((0x00a2892cu));
  }
  L0045f157: { // 0x45f157: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L0045f15a: { // 0x45f15a: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0045f15c: { // 0x45f15c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0045f15d: { // 0x45f15d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0045f15e: { // 0x45f15e: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00600560(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00600560: { // 0x600560: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00600561: { // 0x600561: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00600563: { // 0x600563: e808a4fcff CALL 0x005ca970
    s.arithmetic_flags=flags; invoke(m,s,f,0x005ca970u,6292840u); flags=s.arithmetic_flags;
  }
  L00600568: { // 0x600568: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0060056a: { // 0x60056a: 8d8ed8000000 LEA ECX,[ESI + 0xd8]
    s.cx = (s.si+0x000000d8u);
  }
  L00600570: { // 0x600570: 898698000000 MOV dword ptr [ESI + 0x98],EAX
    m.w32((s.si+0x00000098u), s.ax);
  }
  L00600576: { // 0x600576: 88869c000000 MOV byte ptr [ESI + 0x9c],AL
    m.w8((s.si+0x0000009cu), (s.ax & 0xffu));
  }
  L0060057c: { // 0x60057c: 88869d000000 MOV byte ptr [ESI + 0x9d],AL
    m.w8((s.si+0x0000009du), (s.ax & 0xffu));
  }
  L00600582: { // 0x600582: 88869e000000 MOV byte ptr [ESI + 0x9e],AL
    m.w8((s.si+0x0000009eu), (s.ax & 0xffu));
  }
  L00600588: { // 0x600588: 8986a8000000 MOV dword ptr [ESI + 0xa8],EAX
    m.w32((s.si+0x000000a8u), s.ax);
  }
  L0060058e: { // 0x60058e: 8986a0000000 MOV dword ptr [ESI + 0xa0],EAX
    m.w32((s.si+0x000000a0u), s.ax);
  }
  L00600594: { // 0x600594: 8986ac000000 MOV dword ptr [ESI + 0xac],EAX
    m.w32((s.si+0x000000acu), s.ax);
  }
  L0060059a: { // 0x60059a: 8986b0000000 MOV dword ptr [ESI + 0xb0],EAX
    m.w32((s.si+0x000000b0u), s.ax);
  }
  L006005a0: { // 0x6005a0: 8986b4000000 MOV dword ptr [ESI + 0xb4],EAX
    m.w32((s.si+0x000000b4u), s.ax);
  }
  L006005a6: { // 0x6005a6: 8986b8000000 MOV dword ptr [ESI + 0xb8],EAX
    m.w32((s.si+0x000000b8u), s.ax);
  }
  L006005ac: { // 0x6005ac: 8986bc000000 MOV dword ptr [ESI + 0xbc],EAX
    m.w32((s.si+0x000000bcu), s.ax);
  }
  L006005b2: { // 0x6005b2: 8986c0000000 MOV dword ptr [ESI + 0xc0],EAX
    m.w32((s.si+0x000000c0u), s.ax);
  }
  L006005b8: { // 0x6005b8: c786c4000000000080bf MOV dword ptr [ESI + 0xc4],0xbf800000
    m.w32((s.si+0x000000c4u), 0xbf800000u);
  }
  L006005c2: { // 0x6005c2: 8986c8000000 MOV dword ptr [ESI + 0xc8],EAX
    m.w32((s.si+0x000000c8u), s.ax);
  }
  L006005c8: { // 0x6005c8: 8986cc000000 MOV dword ptr [ESI + 0xcc],EAX
    m.w32((s.si+0x000000ccu), s.ax);
  }
  L006005ce: { // 0x6005ce: 8986d0000000 MOV dword ptr [ESI + 0xd0],EAX
    m.w32((s.si+0x000000d0u), s.ax);
  }
  L006005d4: { // 0x6005d4: 8986d4000000 MOV dword ptr [ESI + 0xd4],EAX
    m.w32((s.si+0x000000d4u), s.ax);
  }
  L006005da: { // 0x6005da: 8b1548e0a500 MOV EDX,dword ptr [0x00a5e048]
    s.dx = m.r32((0x00a5e048u));
  }
  L006005e0: { // 0x6005e0: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  L006005e2: { // 0x6005e2: 8b154ce0a500 MOV EDX,dword ptr [0x00a5e04c]
    s.dx = m.r32((0x00a5e04cu));
  }
  L006005e8: { // 0x6005e8: 895104 MOV dword ptr [ECX + 0x4],EDX
    m.w32((s.cx+0x00000004u), s.dx);
  }
  L006005eb: { // 0x6005eb: 8b1550e0a500 MOV EDX,dword ptr [0x00a5e050]
    s.dx = m.r32((0x00a5e050u));
  }
  L006005f1: { // 0x6005f1: 895108 MOV dword ptr [ECX + 0x8],EDX
    m.w32((s.cx+0x00000008u), s.dx);
  }
  L006005f4: { // 0x6005f4: 8b1548e0a500 MOV EDX,dword ptr [0x00a5e048]
    s.dx = m.r32((0x00a5e048u));
  }
  L006005fa: { // 0x6005fa: 8d8ee4000000 LEA ECX,[ESI + 0xe4]
    s.cx = (s.si+0x000000e4u);
  }
  L00600600: { // 0x600600: 8996e4000000 MOV dword ptr [ESI + 0xe4],EDX
    m.w32((s.si+0x000000e4u), s.dx);
  }
  L00600606: { // 0x600606: 8b154ce0a500 MOV EDX,dword ptr [0x00a5e04c]
    s.dx = m.r32((0x00a5e04cu));
  }
  L0060060c: { // 0x60060c: 895104 MOV dword ptr [ECX + 0x4],EDX
    m.w32((s.cx+0x00000004u), s.dx);
  }
  L0060060f: { // 0x60060f: 8b1550e0a500 MOV EDX,dword ptr [0x00a5e050]
    s.dx = m.r32((0x00a5e050u));
  }
  L00600615: { // 0x600615: 895108 MOV dword ptr [ECX + 0x8],EDX
    m.w32((s.cx+0x00000008u), s.dx);
  }
  L00600618: { // 0x600618: 8b1548e0a500 MOV EDX,dword ptr [0x00a5e048]
    s.dx = m.r32((0x00a5e048u));
  }
  L0060061e: { // 0x60061e: 8d8ef0000000 LEA ECX,[ESI + 0xf0]
    s.cx = (s.si+0x000000f0u);
  }
  L00600624: { // 0x600624: 8996f0000000 MOV dword ptr [ESI + 0xf0],EDX
    m.w32((s.si+0x000000f0u), s.dx);
  }
  L0060062a: { // 0x60062a: 8b154ce0a500 MOV EDX,dword ptr [0x00a5e04c]
    s.dx = m.r32((0x00a5e04cu));
  }
  L00600630: { // 0x600630: 895104 MOV dword ptr [ECX + 0x4],EDX
    m.w32((s.cx+0x00000004u), s.dx);
  }
  L00600633: { // 0x600633: 8b1550e0a500 MOV EDX,dword ptr [0x00a5e050]
    s.dx = m.r32((0x00a5e050u));
  }
  L00600639: { // 0x600639: 895108 MOV dword ptr [ECX + 0x8],EDX
    m.w32((s.cx+0x00000008u), s.dx);
  }
  L0060063c: { // 0x60063c: 8986fc000000 MOV dword ptr [ESI + 0xfc],EAX
    m.w32((s.si+0x000000fcu), s.ax);
  }
  L00600642: { // 0x600642: 898600010000 MOV dword ptr [ESI + 0x100],EAX
    m.w32((s.si+0x00000100u), s.ax);
  }
  L00600648: { // 0x600648: 898604010000 MOV dword ptr [ESI + 0x104],EAX
    m.w32((s.si+0x00000104u), s.ax);
  }
  L0060064e: { // 0x60064e: 898608010000 MOV dword ptr [ESI + 0x108],EAX
    m.w32((s.si+0x00000108u), s.ax);
  }
  L00600654: { // 0x600654: 89860c010000 MOV dword ptr [ESI + 0x10c],EAX
    m.w32((s.si+0x0000010cu), s.ax);
  }
  L0060065a: { // 0x60065a: 898610010000 MOV dword ptr [ESI + 0x110],EAX
    m.w32((s.si+0x00000110u), s.ax);
  }
  L00600660: { // 0x600660: 898614010000 MOV dword ptr [ESI + 0x114],EAX
    m.w32((s.si+0x00000114u), s.ax);
  }
  L00600666: { // 0x600666: 88861c010000 MOV byte ptr [ESI + 0x11c],AL
    m.w8((s.si+0x0000011cu), (s.ax & 0xffu));
  }
  L0060066c: { // 0x60066c: 88861d010000 MOV byte ptr [ESI + 0x11d],AL
    m.w8((s.si+0x0000011du), (s.ax & 0xffu));
  }
  L00600672: { // 0x600672: 88861e010000 MOV byte ptr [ESI + 0x11e],AL
    m.w8((s.si+0x0000011eu), (s.ax & 0xffu));
  }
  L00600678: { // 0x600678: 88861f010000 MOV byte ptr [ESI + 0x11f],AL
    m.w8((s.si+0x0000011fu), (s.ax & 0xffu));
  }
  L0060067e: { // 0x60067e: 888620010000 MOV byte ptr [ESI + 0x120],AL
    m.w8((s.si+0x00000120u), (s.ax & 0xffu));
  }
  L00600684: { // 0x600684: 888621010000 MOV byte ptr [ESI + 0x121],AL
    m.w8((s.si+0x00000121u), (s.ax & 0xffu));
  }
  L0060068a: { // 0x60068a: c7061c2d7900 MOV dword ptr [ESI],0x792d1c
    m.w32((s.si), 0x00792d1cu);
  }
  L00600690: { // 0x600690: c74604002d7900 MOV dword ptr [ESI + 0x4],0x792d00
    m.w32((s.si+0x00000004u), 0x00792d00u);
  }
  L00600697: { // 0x600697: c74608f82c7900 MOV dword ptr [ESI + 0x8],0x792cf8
    m.w32((s.si+0x00000008u), 0x00792cf8u);
  }
  L0060069e: { // 0x60069e: c7460cf02c7900 MOV dword ptr [ESI + 0xc],0x792cf0
    m.w32((s.si+0x0000000cu), 0x00792cf0u);
  }
  L006006a5: { // 0x6006a5: 8b0d60e1a100 MOV ECX,dword ptr [0x00a1e160]
    s.cx = m.r32((0x00a1e160u));
  }
  L006006ab: { // 0x6006ab: 8b1568e1a100 MOV EDX,dword ptr [0x00a1e168]
    s.dx = m.r32((0x00a1e168u));
  }
  L006006b1: { // 0x6006b1: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L006006b3: { // 0x6006b3: 7c2b JL 0x006006e0
    if(integer::condition("JL",flags)) goto L006006e0;
  }
  L006006b5: { // 0x6006b5: 380565e1a100 CMP byte ptr [0x00a1e165],AL
    (void)integer::sub(m.r8((0x00a1e165u)),(s.ax & 0xffu),8,flags);
  }
  L006006bb: { // 0x6006bb: 7504 JNZ 0x006006c1
    if(integer::condition("JNZ",flags)) goto L006006c1;
  }
  L006006bd: { // 0x6006bd: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L006006bf: { // 0x6006bf: 7537 JNZ 0x006006f8
    if(integer::condition("JNZ",flags)) goto L006006f8;
  }
  L006006c1: { // 0x6006c1: 8b156ce1a100 MOV EDX,dword ptr [0x00a1e16c]
    s.dx = m.r32((0x00a1e16cu));
  }
  L006006c7: { // 0x6006c7: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L006006c9: { // 0x6006c9: 7e2d JLE 0x006006f8
    if(integer::condition("JLE",flags)) goto L006006f8;
  }
  L006006cb: { // 0x6006cb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006006cc: { // 0x6006cc: a158e1a100 MOV EAX,[0x00a1e158]
    s.ax = m.r32((0x00a1e158u));
  }
  L006006d1: { // 0x6006d1: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L006006d3: { // 0x6006d3: b958e1a100 MOV ECX,0xa1e158
    s.cx = 0x00a1e158u;
  }
  L006006d8: { // 0x6006d8: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006006d9: { // 0x6006d9: ff5008 CALL dword ptr [EAX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000008u)),6293212u); flags=s.arithmetic_flags;
  }
  L006006dc: { // 0x6006dc: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006006de: { // 0x6006de: 7418 JZ 0x006006f8
    if(integer::condition("JZ",flags)) goto L006006f8;
  }
  L006006e0: { // 0x6006e0: 8b0d68e1a100 MOV ECX,dword ptr [0x00a1e168]
    s.cx = m.r32((0x00a1e168u));
  }
  L006006e6: { // 0x6006e6: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L006006e8: { // 0x6006e8: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L006006e9: { // 0x6006e9: 890d68e1a100 MOV dword ptr [0x00a1e168],ECX
    m.w32((0x00a1e168u), s.cx);
  }
  L006006ef: { // 0x6006ef: 8b0d5ce1a100 MOV ECX,dword ptr [0x00a1e15c]
    s.cx = m.r32((0x00a1e15cu));
  }
  L006006f5: { // 0x6006f5: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L006006f8: { // 0x6006f8: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L006006fa: { // 0x6006fa: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006006fb: { // 0x6006fb: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_007018e0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L007018e0: { // 0x7018e0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L007018e1: { // 0x7018e1: 56 PUSH ESI
    f.push(m,s.si);
  }
  L007018e2: { // 0x7018e2: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L007018e4: { // 0x7018e4: e88790ecff CALL 0x005ca970
    s.arithmetic_flags=flags; invoke(m,s,f,0x005ca970u,7346409u); flags=s.arithmetic_flags;
  }
  L007018e9: { // 0x7018e9: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L007018eb: { // 0x7018eb: 680000803f PUSH 0x3f800000
    f.push(m,0x3f800000u);
  }
  L007018f0: { // 0x7018f0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L007018f1: { // 0x7018f1: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L007018f2: { // 0x7018f2: 899e98000000 MOV dword ptr [ESI + 0x98],EBX
    m.w32((s.si+0x00000098u), s.bx);
  }
  L007018f8: { // 0x7018f8: 899ea0000000 MOV dword ptr [ESI + 0xa0],EBX
    m.w32((s.si+0x000000a0u), s.bx);
  }
  L007018fe: { // 0x7018fe: 899ea8000000 MOV dword ptr [ESI + 0xa8],EBX
    m.w32((s.si+0x000000a8u), s.bx);
  }
  L00701904: { // 0x701904: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00701905: { // 0x701905: 8d8ec8000000 LEA ECX,[ESI + 0xc8]
    s.cx = (s.si+0x000000c8u);
  }
  L0070190b: { // 0x70190b: 899e9c000000 MOV dword ptr [ESI + 0x9c],EBX
    m.w32((s.si+0x0000009cu), s.bx);
  }
  L00701911: { // 0x701911: 899ea4000000 MOV dword ptr [ESI + 0xa4],EBX
    m.w32((s.si+0x000000a4u), s.bx);
  }
  L00701917: { // 0x701917: 899eac000000 MOV dword ptr [ESI + 0xac],EBX
    m.w32((s.si+0x000000acu), s.bx);
  }
  L0070191d: { // 0x70191d: e8ce83f1ff CALL 0x00619cf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00619cf0u,7346466u); flags=s.arithmetic_flags;
  }
  L00701922: { // 0x701922: 680000803f PUSH 0x3f800000
    f.push(m,0x3f800000u);
  }
  L00701927: { // 0x701927: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00701928: { // 0x701928: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00701929: { // 0x701929: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0070192a: { // 0x70192a: 8d8ed8000000 LEA ECX,[ESI + 0xd8]
    s.cx = (s.si+0x000000d8u);
  }
  L00701930: { // 0x701930: e8bb83f1ff CALL 0x00619cf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00619cf0u,7346485u); flags=s.arithmetic_flags;
  }
  L00701935: { // 0x701935: 8d4604 LEA EAX,[ESI + 0x4]
    s.ax = (s.si+0x00000004u);
  }
  L00701938: { // 0x701938: c786e8000000ffffffff MOV dword ptr [ESI + 0xe8],0xffffffff
    m.w32((s.si+0x000000e8u), 0xffffffffu);
  }
  L00701942: { // 0x701942: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00701943: { // 0x701943: 899eec000000 MOV dword ptr [ESI + 0xec],EBX
    m.w32((s.si+0x000000ecu), s.bx);
  }
  L00701949: { // 0x701949: 899ef0000000 MOV dword ptr [ESI + 0xf0],EBX
    m.w32((s.si+0x000000f0u), s.bx);
  }
  L0070194f: { // 0x70194f: 899ef4000000 MOV dword ptr [ESI + 0xf4],EBX
    m.w32((s.si+0x000000f4u), s.bx);
  }
  L00701955: { // 0x701955: 889ef8000000 MOV byte ptr [ESI + 0xf8],BL
    m.w8((s.si+0x000000f8u), (s.bx & 0xffu));
  }
  L0070195b: { // 0x70195b: 889e24010000 MOV byte ptr [ESI + 0x124],BL
    m.w8((s.si+0x00000124u), (s.bx & 0xffu));
  }
  L00701961: { // 0x701961: 899e28010000 MOV dword ptr [ESI + 0x128],EBX
    m.w32((s.si+0x00000128u), s.bx);
  }
  L00701967: { // 0x701967: c706b8927900 MOV dword ptr [ESI],0x7992b8
    m.w32((s.si), 0x007992b8u);
  }
  L0070196d: { // 0x70196d: c7009c927900 MOV dword ptr [EAX],0x79929c
    m.w32((s.ax), 0x0079929cu);
  }
  L00701973: { // 0x701973: c7460894927900 MOV dword ptr [ESI + 0x8],0x799294
    m.w32((s.si+0x00000008u), 0x00799294u);
  }
  L0070197a: { // 0x70197a: c7460c8c927900 MOV dword ptr [ESI + 0xc],0x79928c
    m.w32((s.si+0x0000000cu), 0x0079928cu);
  }
  L00701981: { // 0x701981: e84ae6d0ff CALL 0x0040ffd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0040ffd0u,7346566u); flags=s.arithmetic_flags;
  }
  L00701986: { // 0x701986: 8d8efc000000 LEA ECX,[ESI + 0xfc]
    s.cx = (s.si+0x000000fcu);
  }
  L0070198c: { // 0x70198c: e85f42d0ff CALL 0x00405bf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00405bf0u,7346577u); flags=s.arithmetic_flags;
  }
  L00701991: { // 0x701991: 8d8e10010000 LEA ECX,[ESI + 0x110]
    s.cx = (s.si+0x00000110u);
  }
  L00701997: { // 0x701997: e85442d0ff CALL 0x00405bf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00405bf0u,7346588u); flags=s.arithmetic_flags;
  }
  L0070199c: { // 0x70199c: a1181d8200 MOV EAX,[0x00821d18]
    s.ax = m.r32((0x00821d18u));
  }
  L007019a1: { // 0x7019a1: 8b0d201d8200 MOV ECX,dword ptr [0x00821d20]
    s.cx = m.r32((0x00821d20u));
  }
  L007019a7: { // 0x7019a7: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L007019a9: { // 0x7019a9: 7c2b JL 0x007019d6
    if(integer::condition("JL",flags)) goto L007019d6;
  }
  L007019ab: { // 0x7019ab: 381d1d1d8200 CMP byte ptr [0x00821d1d],BL
    (void)integer::sub(m.r8((0x00821d1du)),(s.bx & 0xffu),8,flags);
  }
  L007019b1: { // 0x7019b1: 7504 JNZ 0x007019b7
    if(integer::condition("JNZ",flags)) goto L007019b7;
  }
  L007019b3: { // 0x7019b3: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L007019b5: { // 0x7019b5: 7537 JNZ 0x007019ee
    if(integer::condition("JNZ",flags)) goto L007019ee;
  }
  L007019b7: { // 0x7019b7: 8b0d241d8200 MOV ECX,dword ptr [0x00821d24]
    s.cx = m.r32((0x00821d24u));
  }
  L007019bd: { // 0x7019bd: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L007019bf: { // 0x7019bf: 7e2d JLE 0x007019ee
    if(integer::condition("JLE",flags)) goto L007019ee;
  }
  L007019c1: { // 0x7019c1: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L007019c3: { // 0x7019c3: a1101d8200 MOV EAX,[0x00821d10]
    s.ax = m.r32((0x00821d10u));
  }
  L007019c8: { // 0x7019c8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L007019c9: { // 0x7019c9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L007019ca: { // 0x7019ca: b9101d8200 MOV ECX,0x821d10
    s.cx = 0x00821d10u;
  }
  L007019cf: { // 0x7019cf: ff5008 CALL dword ptr [EAX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000008u)),7346642u); flags=s.arithmetic_flags;
  }
  L007019d2: { // 0x7019d2: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L007019d4: { // 0x7019d4: 7418 JZ 0x007019ee
    if(integer::condition("JZ",flags)) goto L007019ee;
  }
  L007019d6: { // 0x7019d6: 8b0d201d8200 MOV ECX,dword ptr [0x00821d20]
    s.cx = m.r32((0x00821d20u));
  }
  L007019dc: { // 0x7019dc: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L007019de: { // 0x7019de: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L007019df: { // 0x7019df: 890d201d8200 MOV dword ptr [0x00821d20],ECX
    m.w32((0x00821d20u), s.cx);
  }
  L007019e5: { // 0x7019e5: 8b0d141d8200 MOV ECX,dword ptr [0x00821d14]
    s.cx = m.r32((0x00821d14u));
  }
  L007019eb: { // 0x7019eb: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L007019ee: { // 0x7019ee: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L007019f0: { // 0x7019f0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L007019f1: { // 0x7019f1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L007019f2: { // 0x7019f2: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
