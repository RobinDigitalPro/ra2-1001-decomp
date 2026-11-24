#include "recovery_b1303_ctor_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b1303_ctor {
namespace {
void f_001ca970(Memory&,State&,Frame&,const Operations&);
void f_0000ffd0(Memory&,State&,Frame&,const Operations&);
void f_0000ff10(Memory&,State&,Frame&,const Operations&);
void f_00005bf0(Memory&,State&,Frame&,const Operations&);
void f_0000ffc0(Memory&,State&,Frame&,const Operations&);
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


void f_0000ffc0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0040ffc0: { // 0x40ffc0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L0040ffc4: { // 0x40ffc4: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L0040ffc7: { // 0x40ffc7: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 6072688u:f_001ca970(m,s,child,{});break;
case 4259792u:f_0000ffd0(m,s,child,{});break;
case 4259600u:f_0000ff10(m,s,child,{});break;
case 4217840u:f_00005bf0(m,s,child,{});break;
case 4259776u:f_0000ffc0(m,s,child,{});break;
case 0x0065a120u: { // exact accepted 0x65a120: owner+0x214 increment
  const auto owner=s.cx; const auto v=m.r32(owner+0x214u)+1u;
  m.w32(owner+0x214u,v);s.ax=v;child.sp+=4u;break;
}
default:throw std::domain_error("recovery626 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_005d2e50(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005d2e50: { // 0x5d2e50: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L005d2e53: { // 0x5d2e53: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005d2e54: { // 0x5d2e54: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L005d2e56: { // 0x5d2e56: e8157bffff CALL 0x005ca970
    s.arithmetic_flags=flags; invoke(m,s,f,0x005ca970u,6106715u); flags=s.arithmetic_flags;
  }
  L005d2e5b: { // 0x5d2e5b: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L005d2e5f: { // 0x5d2e5f: c706b4277900 MOV dword ptr [ESI],0x7927b4
    m.w32((s.si), 0x007927b4u);
  }
  L005d2e65: { // 0x5d2e65: 898698000000 MOV dword ptr [ESI + 0x98],EAX
    m.w32((s.si+0x00000098u), s.ax);
  }
  L005d2e6b: { // 0x5d2e6b: 8d4604 LEA EAX,[ESI + 0x4]
    s.ax = (s.si+0x00000004u);
  }
  L005d2e6e: { // 0x5d2e6e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005d2e6f: { // 0x5d2e6f: c74608ac277900 MOV dword ptr [ESI + 0x8],0x7927ac
    m.w32((s.si+0x00000008u), 0x007927acu);
  }
  L005d2e76: { // 0x5d2e76: c70090277900 MOV dword ptr [EAX],0x792790
    m.w32((s.ax), 0x00792790u);
  }
  L005d2e7c: { // 0x5d2e7c: c7460c88277900 MOV dword ptr [ESI + 0xc],0x792788
    m.w32((s.si+0x0000000cu), 0x00792788u);
  }
  L005d2e83: { // 0x5d2e83: e848d1e3ff CALL 0x0040ffd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0040ffd0u,6106760u); flags=s.arithmetic_flags;
  }
  L005d2e88: { // 0x5d2e88: a14888a200 MOV EAX,[0x00a28848]
    s.ax = m.r32((0x00a28848u));
  }
  L005d2e8d: { // 0x5d2e8d: 8b0d5088a200 MOV ECX,dword ptr [0x00a28850]
    s.cx = m.r32((0x00a28850u));
  }
  L005d2e93: { // 0x5d2e93: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L005d2e95: { // 0x5d2e95: 7c2f JL 0x005d2ec6
    if(integer::condition("JL",flags)) goto L005d2ec6;
  }
  L005d2e97: { // 0x5d2e97: 8a0d4d88a200 MOV CL,byte ptr [0x00a2884d]
    s.cx = with_al(s.cx, m.r8((0x00a2884du)));
  }
  L005d2e9d: { // 0x5d2e9d: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L005d2e9f: { // 0x5d2e9f: 7504 JNZ 0x005d2ea5
    if(integer::condition("JNZ",flags)) goto L005d2ea5;
  }
  L005d2ea1: { // 0x5d2ea1: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005d2ea3: { // 0x5d2ea3: 7539 JNZ 0x005d2ede
    if(integer::condition("JNZ",flags)) goto L005d2ede;
  }
  L005d2ea5: { // 0x5d2ea5: 8b0d5488a200 MOV ECX,dword ptr [0x00a28854]
    s.cx = m.r32((0x00a28854u));
  }
  L005d2eab: { // 0x5d2eab: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005d2ead: { // 0x5d2ead: 7e2f JLE 0x005d2ede
    if(integer::condition("JLE",flags)) goto L005d2ede;
  }
  L005d2eaf: { // 0x5d2eaf: 8b154088a200 MOV EDX,dword ptr [0x00a28840]
    s.dx = m.r32((0x00a28840u));
  }
  L005d2eb5: { // 0x5d2eb5: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L005d2eb7: { // 0x5d2eb7: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L005d2eb9: { // 0x5d2eb9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005d2eba: { // 0x5d2eba: b94088a200 MOV ECX,0xa28840
    s.cx = 0x00a28840u;
  }
  L005d2ebf: { // 0x5d2ebf: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),6106818u); flags=s.arithmetic_flags;
  }
  L005d2ec2: { // 0x5d2ec2: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005d2ec4: { // 0x5d2ec4: 7418 JZ 0x005d2ede
    if(integer::condition("JZ",flags)) goto L005d2ede;
  }
  L005d2ec6: { // 0x5d2ec6: 8b0d5088a200 MOV ECX,dword ptr [0x00a28850]
    s.cx = m.r32((0x00a28850u));
  }
  L005d2ecc: { // 0x5d2ecc: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L005d2ece: { // 0x5d2ece: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L005d2ecf: { // 0x5d2ecf: 890d5088a200 MOV dword ptr [0x00a28850],ECX
    m.w32((0x00a28850u), s.cx);
  }
  L005d2ed5: { // 0x5d2ed5: 8b0d4488a200 MOV ECX,dword ptr [0x00a28844]
    s.cx = m.r32((0x00a28844u));
  }
  L005d2edb: { // 0x5d2edb: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L005d2ede: { // 0x5d2ede: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L005d2ee2: { // 0x5d2ee2: 668b10 MOV DX,word ptr [EAX]
    s.dx = with_ax(s.dx, m.r16((s.ax)));
  }
  L005d2ee5: { // 0x5d2ee5: 663b15f0aba500 CMP DX,word ptr [0x00a5abf0]
    (void)integer::sub((s.dx & 0xffffu),m.r16((0x00a5abf0u)),16,flags);
  }
  L005d2eec: { // 0x5d2eec: 750d JNZ 0x005d2efb
    if(integer::condition("JNZ",flags)) goto L005d2efb;
  }
  L005d2eee: { // 0x5d2eee: 668b4802 MOV CX,word ptr [EAX + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.ax+0x00000002u)));
  }
  L005d2ef2: { // 0x5d2ef2: 663b0df2aba500 CMP CX,word ptr [0x00a5abf2]
    (void)integer::sub((s.cx & 0xffffu),m.r16((0x00a5abf2u)),16,flags);
  }
  L005d2ef9: { // 0x5d2ef9: 744b JZ 0x005d2f46
    if(integer::condition("JZ",flags)) goto L005d2f46;
  }
  L005d2efb: { // 0x5d2efb: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L005d2eff: { // 0x5d2eff: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L005d2f01: { // 0x5d2f01: 8915f42b7d00 MOV dword ptr [0x007d2bf4],EDX
    m.w32((0x007d2bf4u), s.dx);
  }
  L005d2f07: { // 0x5d2f07: c744241000000000 MOV dword ptr [ESP + 0x10],0x0
    m.w32((f.sp+0x00000010u), 0x00000000u);
  }
  L005d2f0f: { // 0x5d2f0f: 0fbf08 MOVSX ECX,word ptr [EAX]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.ax)),16));
  }
  L005d2f12: { // 0x5d2f12: 0fbf5002 MOVSX EDX,word ptr [EAX + 0x2]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000002u)),16));
  }
  L005d2f16: { // 0x5d2f16: c1e108 SHL ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::left);
  }
  L005d2f19: { // 0x5d2f19: 81c180000000 ADD ECX,0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L005d2f1f: { // 0x5d2f1f: 8d442408 LEA EAX,[ESP + 0x8]
    s.ax = (f.sp+0x00000008u);
  }
  L005d2f23: { // 0x5d2f23: c1e208 SHL EDX,0x8
    s.dx = integer::shift(s.dx,0x00000008u,32,flags,integer::Shift::left);
  }
  L005d2f26: { // 0x5d2f26: 894c2408 MOV dword ptr [ESP + 0x8],ECX
    m.w32((f.sp+0x00000008u), s.cx);
  }
  L005d2f2a: { // 0x5d2f2a: 81c280000000 ADD EDX,0x80
    s.dx = integer::add(s.dx,0x00000080u,32,flags);
  }
  L005d2f30: { // 0x5d2f30: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005d2f31: { // 0x5d2f31: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005d2f33: { // 0x5d2f33: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L005d2f37: { // 0x5d2f37: e8e48fffff CALL 0x005cbf20
    s.arithmetic_flags=flags; invoke(m,s,f,0x005cbf20u,6106940u); flags=s.arithmetic_flags;
  }
  L005d2f3c: { // 0x5d2f3c: c705f42b7d00ffffffff MOV dword ptr [0x007d2bf4],0xffffffff
    m.w32((0x007d2bf4u), 0xffffffffu);
  }
  L005d2f46: { // 0x5d2f46: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L005d2f48: { // 0x5d2f48: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005d2f49: { // 0x5d2f49: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L005d2f4c: { // 0x5d2f4c: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_0067ccf0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0067ccf0: { // 0x67ccf0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0067ccf1: { // 0x67ccf1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0067ccf3: { // 0x67ccf3: e878dcf4ff CALL 0x005ca970
    s.arithmetic_flags=flags; invoke(m,s,f,0x005ca970u,6802680u); flags=s.arithmetic_flags;
  }
  L0067ccf8: { // 0x67ccf8: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L0067ccfc: { // 0x67ccfc: c70634647900 MOV dword ptr [ESI],0x796434
    m.w32((s.si), 0x00796434u);
  }
  L0067cd02: { // 0x67cd02: 898698000000 MOV dword ptr [ESI + 0x98],EAX
    m.w32((s.si+0x00000098u), s.ax);
  }
  L0067cd08: { // 0x67cd08: 8d4604 LEA EAX,[ESI + 0x4]
    s.ax = (s.si+0x00000004u);
  }
  L0067cd0b: { // 0x67cd0b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0067cd0c: { // 0x67cd0c: c746082c647900 MOV dword ptr [ESI + 0x8],0x79642c
    m.w32((s.si+0x00000008u), 0x0079642cu);
  }
  L0067cd13: { // 0x67cd13: c70010647900 MOV dword ptr [EAX],0x796410
    m.w32((s.ax), 0x00796410u);
  }
  L0067cd19: { // 0x67cd19: c7460c08647900 MOV dword ptr [ESI + 0xc],0x796408
    m.w32((s.si+0x0000000cu), 0x00796408u);
  }
  L0067cd20: { // 0x67cd20: e8ab32d9ff CALL 0x0040ffd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0040ffd0u,6802725u); flags=s.arithmetic_flags;
  }
  L0067cd25: { // 0x67cd25: a17855a200 MOV EAX,[0x00a25578]
    s.ax = m.r32((0x00a25578u));
  }
  L0067cd2a: { // 0x67cd2a: 8b0d8055a200 MOV ECX,dword ptr [0x00a25580]
    s.cx = m.r32((0x00a25580u));
  }
  L0067cd30: { // 0x67cd30: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L0067cd32: { // 0x67cd32: 7c2f JL 0x0067cd63
    if(integer::condition("JL",flags)) goto L0067cd63;
  }
  L0067cd34: { // 0x67cd34: 8a0d7d55a200 MOV CL,byte ptr [0x00a2557d]
    s.cx = with_al(s.cx, m.r8((0x00a2557du)));
  }
  L0067cd3a: { // 0x67cd3a: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0067cd3c: { // 0x67cd3c: 7504 JNZ 0x0067cd42
    if(integer::condition("JNZ",flags)) goto L0067cd42;
  }
  L0067cd3e: { // 0x67cd3e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0067cd40: { // 0x67cd40: 7539 JNZ 0x0067cd7b
    if(integer::condition("JNZ",flags)) goto L0067cd7b;
  }
  L0067cd42: { // 0x67cd42: 8b0d8455a200 MOV ECX,dword ptr [0x00a25584]
    s.cx = m.r32((0x00a25584u));
  }
  L0067cd48: { // 0x67cd48: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0067cd4a: { // 0x67cd4a: 7e2f JLE 0x0067cd7b
    if(integer::condition("JLE",flags)) goto L0067cd7b;
  }
  L0067cd4c: { // 0x67cd4c: 8b157055a200 MOV EDX,dword ptr [0x00a25570]
    s.dx = m.r32((0x00a25570u));
  }
  L0067cd52: { // 0x67cd52: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0067cd54: { // 0x67cd54: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0067cd56: { // 0x67cd56: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0067cd57: { // 0x67cd57: b97055a200 MOV ECX,0xa25570
    s.cx = 0x00a25570u;
  }
  L0067cd5c: { // 0x67cd5c: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),6802783u); flags=s.arithmetic_flags;
  }
  L0067cd5f: { // 0x67cd5f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0067cd61: { // 0x67cd61: 7418 JZ 0x0067cd7b
    if(integer::condition("JZ",flags)) goto L0067cd7b;
  }
  L0067cd63: { // 0x67cd63: 8b0d8055a200 MOV ECX,dword ptr [0x00a25580]
    s.cx = m.r32((0x00a25580u));
  }
  L0067cd69: { // 0x67cd69: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0067cd6b: { // 0x67cd6b: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0067cd6c: { // 0x67cd6c: 890d8055a200 MOV dword ptr [0x00a25580],ECX
    m.w32((0x00a25580u), s.cx);
  }
  L0067cd72: { // 0x67cd72: 8b0d7455a200 MOV ECX,dword ptr [0x00a25574]
    s.cx = m.r32((0x00a25574u));
  }
  L0067cd78: { // 0x67cd78: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L0067cd7b: { // 0x67cd7b: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L0067cd7f: { // 0x67cd7f: 8b0df049aa00 MOV ECX,dword ptr [0x00aa49f0]
    s.cx = m.r32((0x00aa49f0u));
  }
  L0067cd85: { // 0x67cd85: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0067cd87: { // 0x67cd87: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L0067cd89: { // 0x67cd89: 751a JNZ 0x0067cda5
    if(integer::condition("JNZ",flags)) goto L0067cda5;
  }
  L0067cd8b: { // 0x67cd8b: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L0067cd8e: { // 0x67cd8e: 8b15f449aa00 MOV EDX,dword ptr [0x00aa49f4]
    s.dx = m.r32((0x00aa49f4u));
  }
  L0067cd94: { // 0x67cd94: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L0067cd96: { // 0x67cd96: 750d JNZ 0x0067cda5
    if(integer::condition("JNZ",flags)) goto L0067cda5;
  }
  L0067cd98: { // 0x67cd98: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L0067cd9b: { // 0x67cd9b: 8b0df849aa00 MOV ECX,dword ptr [0x00aa49f8]
    s.cx = m.r32((0x00aa49f8u));
  }
  L0067cda1: { // 0x67cda1: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L0067cda3: { // 0x67cda3: 742f JZ 0x0067cdd4
    if(integer::condition("JZ",flags)) goto L0067cdd4;
  }
  L0067cda5: { // 0x67cda5: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L0067cda9: { // 0x67cda9: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0067cdab: { // 0x67cdab: 890dc8da7d00 MOV dword ptr [0x007ddac8],ECX
    m.w32((0x007ddac8u), s.cx);
  }
  L0067cdb1: { // 0x67cdb1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0067cdb2: { // 0x67cdb2: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0067cdb4: { // 0x67cdb4: e867f1f4ff CALL 0x005cbf20
    s.arithmetic_flags=flags; invoke(m,s,f,0x005cbf20u,6802873u); flags=s.arithmetic_flags;
  }
  L0067cdb9: { // 0x67cdb9: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0067cdbb: { // 0x67cdbb: 750d JNZ 0x0067cdca
    if(integer::condition("JNZ",flags)) goto L0067cdca;
  }
  L0067cdbd: { // 0x67cdbd: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0067cdbf: { // 0x67cdbf: e85c07f5ff CALL 0x005cd520
    s.arithmetic_flags=flags; invoke(m,s,f,0x005cd520u,6802884u); flags=s.arithmetic_flags;
  }
  L0067cdc4: { // 0x67cdc4: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0067cdc6: { // 0x67cdc6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0067cdc7: { // 0x67cdc7: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0067cdca: { // 0x67cdca: c705c8da7d00ffffffff MOV dword ptr [0x007ddac8],0xffffffff
    m.w32((0x007ddac8u), 0xffffffffu);
  }
  L0067cdd4: { // 0x67cdd4: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0067cdd6: { // 0x67cdd6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0067cdd7: { // 0x67cdd7: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_006d8690(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006d8690: { // 0x6d8690: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L006d8693: { // 0x6d8693: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006d8694: { // 0x6d8694: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006d8695: { // 0x6d8695: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006d8696: { // 0x6d8696: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006d8697: { // 0x6d8697: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006d8699: { // 0x6d8699: e8d222efff CALL 0x005ca970
    s.arithmetic_flags=flags; invoke(m,s,f,0x005ca970u,7177886u); flags=s.arithmetic_flags;
  }
  L006d869e: { // 0x6d869e: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L006d86a2: { // 0x6d86a2: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L006d86a4: { // 0x6d86a4: 899e98000000 MOV dword ptr [ESI + 0x98],EBX
    m.w32((s.si+0x00000098u), s.bx);
  }
  L006d86aa: { // 0x6d86aa: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  L006d86af: { // 0x6d86af: 89869c000000 MOV dword ptr [ESI + 0x9c],EAX
    m.w32((s.si+0x0000009cu), s.ax);
  }
  L006d86b5: { // 0x6d86b5: 899ea4000000 MOV dword ptr [ESI + 0xa4],EBX
    m.w32((s.si+0x000000a4u), s.bx);
  }
  L006d86bb: { // 0x6d86bb: 899ea8000000 MOV dword ptr [ESI + 0xa8],EBX
    m.w32((s.si+0x000000a8u), s.bx);
  }
  L006d86c1: { // 0x6d86c1: c786ac00000001000000 MOV dword ptr [ESI + 0xac],0x1
    m.w32((s.si+0x000000acu), 0x00000001u);
  }
  L006d86cb: { // 0x6d86cb: 8d7e04 LEA EDI,[ESI + 0x4]
    s.di = (s.si+0x00000004u);
  }
  L006d86ce: { // 0x6d86ce: 898eb0000000 MOV dword ptr [ESI + 0xb0],ECX
    m.w32((s.si+0x000000b0u), s.cx);
  }
  L006d86d4: { // 0x6d86d4: 889eb4000000 MOV byte ptr [ESI + 0xb4],BL
    m.w8((s.si+0x000000b4u), (s.bx & 0xffu));
  }
  L006d86da: { // 0x6d86da: 889eb5000000 MOV byte ptr [ESI + 0xb5],BL
    m.w8((s.si+0x000000b5u), (s.bx & 0xffu));
  }
  L006d86e0: { // 0x6d86e0: 899eb8000000 MOV dword ptr [ESI + 0xb8],EBX
    m.w32((s.si+0x000000b8u), s.bx);
  }
  L006d86e6: { // 0x6d86e6: 899ebc000000 MOV dword ptr [ESI + 0xbc],EBX
    m.w32((s.si+0x000000bcu), s.bx);
  }
  L006d86ec: { // 0x6d86ec: 899ec0000000 MOV dword ptr [ESI + 0xc0],EBX
    m.w32((s.si+0x000000c0u), s.bx);
  }
  L006d86f2: { // 0x6d86f2: 899ec4000000 MOV dword ptr [ESI + 0xc4],EBX
    m.w32((s.si+0x000000c4u), s.bx);
  }
  L006d86f8: { // 0x6d86f8: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006d86f9: { // 0x6d86f9: c70674827900 MOV dword ptr [ESI],0x798274
    m.w32((s.si), 0x00798274u);
  }
  L006d86ff: { // 0x6d86ff: c70748827900 MOV dword ptr [EDI],0x798248
    m.w32((s.di), 0x00798248u);
  }
  L006d8705: { // 0x6d8705: c746086c827900 MOV dword ptr [ESI + 0x8],0x79826c
    m.w32((s.si+0x00000008u), 0x0079826cu);
  }
  L006d870c: { // 0x6d870c: c7460c64827900 MOV dword ptr [ESI + 0xc],0x798264
    m.w32((s.si+0x0000000cu), 0x00798264u);
  }
  L006d8713: { // 0x6d8713: e8b878d3ff CALL 0x0040ffd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0040ffd0u,7178008u); flags=s.arithmetic_flags;
  }
  L006d8718: { // 0x6d8718: 8b96b0000000 MOV EDX,dword ptr [ESI + 0xb0]
    s.dx = m.r32((s.si+0x000000b0u));
  }
  L006d871e: { // 0x6d871e: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L006d8722: { // 0x6d8722: 8b82a0000000 MOV EAX,dword ptr [EDX + 0xa0]
    s.ax = m.r32((s.dx+0x000000a0u));
  }
  L006d8728: { // 0x6d8728: 89466c MOV dword ptr [ESI + 0x6c],EAX
    m.w32((s.si+0x0000006cu), s.ax);
  }
  L006d872b: { // 0x6d872b: 668b01 MOV AX,word ptr [ECX]
    s.ax = with_ax(s.ax, m.r16((s.cx)));
  }
  L006d872e: { // 0x6d872e: 663b05707eaa00 CMP AX,word ptr [0x00aa7e70]
    (void)integer::sub((s.ax & 0xffffu),m.r16((0x00aa7e70u)),16,flags);
  }
  L006d8735: { // 0x6d8735: 750d JNZ 0x006d8744
    if(integer::condition("JNZ",flags)) goto L006d8744;
  }
  L006d8737: { // 0x6d8737: 668b5102 MOV DX,word ptr [ECX + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.cx+0x00000002u)));
  }
  L006d873b: { // 0x6d873b: 663b15727eaa00 CMP DX,word ptr [0x00aa7e72]
    (void)integer::sub((s.dx & 0xffffu),m.r16((0x00aa7e72u)),16,flags);
  }
  L006d8742: { // 0x6d8742: 743c JZ 0x006d8780
    if(integer::condition("JZ",flags)) goto L006d8780;
  }
  L006d8744: { // 0x6d8744: 0fbf4902 MOVSX ECX,word ptr [ECX + 0x2]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000002u)),16));
  }
  L006d8748: { // 0x6d8748: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L006d874b: { // 0x6d874b: c1e108 SHL ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::left);
  }
  L006d874e: { // 0x6d874e: c1e008 SHL EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::left);
  }
  L006d8751: { // 0x6d8751: 81c180000000 ADD ECX,0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L006d8757: { // 0x6d8757: 8d542410 LEA EDX,[ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  L006d875b: { // 0x6d875b: 0580000000 ADD EAX,0x80
    s.ax = integer::add(s.ax,0x00000080u,32,flags);
  }
  L006d8760: { // 0x6d8760: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L006d8764: { // 0x6d8764: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006d8765: { // 0x6d8765: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006d8766: { // 0x6d8766: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006d8768: { // 0x6d8768: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L006d876c: { // 0x6d876c: 895c2420 MOV dword ptr [ESP + 0x20],EBX
    m.w32((f.sp+0x00000020u), s.bx);
  }
  L006d8770: { // 0x6d8770: e81b130000 CALL 0x006d9a90
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d9a90u,7178101u); flags=s.arithmetic_flags;
  }
  L006d8775: { // 0x6d8775: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006d8777: { // 0x6d8777: 7507 JNZ 0x006d8780
    if(integer::condition("JNZ",flags)) goto L006d8780;
  }
  L006d8779: { // 0x6d8779: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006d877b: { // 0x6d877b: e8a04defff CALL 0x005cd520
    s.arithmetic_flags=flags; invoke(m,s,f,0x005cd520u,7178112u); flags=s.arithmetic_flags;
  }
  L006d8780: { // 0x6d8780: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  L006d8785: { // 0x6d8785: 8d969c000000 LEA EDX,[ESI + 0x9c]
    s.dx = (s.si+0x0000009cu);
  }
  L006d878b: { // 0x6d878b: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L006d878d: { // 0x6d878d: 899ea8000000 MOV dword ptr [ESI + 0xa8],EBX
    m.w32((s.si+0x000000a8u), s.bx);
  }
  L006d8793: { // 0x6d8793: 8902 MOV dword ptr [EDX],EAX
    m.w32((s.dx), s.ax);
  }
  L006d8795: { // 0x6d8795: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L006d8799: { // 0x6d8799: 894204 MOV dword ptr [EDX + 0x4],EAX
    m.w32((s.dx+0x00000004u), s.ax);
  }
  L006d879c: { // 0x6d879c: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  L006d879f: { // 0x6d879f: a19885a200 MOV EAX,[0x00a28598]
    s.ax = m.r32((0x00a28598u));
  }
  L006d87a4: { // 0x6d87a4: 3905a085a200 CMP dword ptr [0x00a285a0],EAX
    (void)integer::sub(m.r32((0x00a285a0u)),s.ax,32,flags);
  }
  L006d87aa: { // 0x6d87aa: 7c2c JL 0x006d87d8
    if(integer::condition("JL",flags)) goto L006d87d8;
  }
  L006d87ac: { // 0x6d87ac: 381d9d85a200 CMP byte ptr [0x00a2859d],BL
    (void)integer::sub(m.r8((0x00a2859du)),(s.bx & 0xffu),8,flags);
  }
  L006d87b2: { // 0x6d87b2: 7504 JNZ 0x006d87b8
    if(integer::condition("JNZ",flags)) goto L006d87b8;
  }
  L006d87b4: { // 0x6d87b4: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L006d87b6: { // 0x6d87b6: 7538 JNZ 0x006d87f0
    if(integer::condition("JNZ",flags)) goto L006d87f0;
  }
  L006d87b8: { // 0x6d87b8: 8b0da485a200 MOV ECX,dword ptr [0x00a285a4]
    s.cx = m.r32((0x00a285a4u));
  }
  L006d87be: { // 0x6d87be: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L006d87c0: { // 0x6d87c0: 7e2e JLE 0x006d87f0
    if(integer::condition("JLE",flags)) goto L006d87f0;
  }
  L006d87c2: { // 0x6d87c2: 8b159085a200 MOV EDX,dword ptr [0x00a28590]
    s.dx = m.r32((0x00a28590u));
  }
  L006d87c8: { // 0x6d87c8: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L006d87ca: { // 0x6d87ca: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006d87cb: { // 0x6d87cb: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006d87cc: { // 0x6d87cc: b99085a200 MOV ECX,0xa28590
    s.cx = 0x00a28590u;
  }
  L006d87d1: { // 0x6d87d1: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),7178196u); flags=s.arithmetic_flags;
  }
  L006d87d4: { // 0x6d87d4: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006d87d6: { // 0x6d87d6: 7418 JZ 0x006d87f0
    if(integer::condition("JZ",flags)) goto L006d87f0;
  }
  L006d87d8: { // 0x6d87d8: 8b0da085a200 MOV ECX,dword ptr [0x00a285a0]
    s.cx = m.r32((0x00a285a0u));
  }
  L006d87de: { // 0x6d87de: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L006d87e0: { // 0x6d87e0: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L006d87e1: { // 0x6d87e1: 890da085a200 MOV dword ptr [0x00a285a0],ECX
    m.w32((0x00a285a0u), s.cx);
  }
  L006d87e7: { // 0x6d87e7: 8b0d9485a200 MOV ECX,dword ptr [0x00a28594]
    s.cx = m.r32((0x00a28594u));
  }
  L006d87ed: { // 0x6d87ed: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L006d87f0: { // 0x6d87f0: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006d87f1: { // 0x6d87f1: e8ca77d3ff CALL 0x0040ffc0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0040ffc0u,7178230u); flags=s.arithmetic_flags;
  }
  L006d87f6: { // 0x6d87f6: 8b15647aaa00 MOV EDX,dword ptr [0x00aa7a64]
    s.dx = m.r32((0x00aa7a64u));
  }
  L006d87fc: { // 0x6d87fc: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L006d8800: { // 0x6d8800: a1687aaa00 MOV EAX,[0x00aa7a68]
    s.ax = m.r32((0x00aa7a68u));
  }
  L006d8805: { // 0x6d8805: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L006d8806: { // 0x6d8806: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L006d8808: { // 0x6d8808: 0f8e8e000000 JLE 0x006d889c
    if(integer::condition("JLE",flags)) goto L006d889c;
  }
  L006d880e: { // 0x6d880e: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L006d8810: { // 0x6d8810: 7507 JNZ 0x006d8819
    if(integer::condition("JNZ",flags)) goto L006d8819;
  }
  L006d8812: { // 0x6d8812: bd0a000000 MOV EBP,0xa
    s.bp = 0x0000000au;
  }
  L006d8817: { // 0x6d8817: eb0a JMP 0x006d8823
    goto L006d8823;
  }
  L006d8819: { // 0x6d8819: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L006d881b: { // 0x6d881b: 3beb CMP EBP,EBX
    (void)integer::sub(s.bp,s.bx,32,flags);
  }
  L006d881d: { // 0x6d881d: 0f8cac000000 JL 0x006d88cf
    if(integer::condition("JL",flags)) goto L006d88cf;
  }
  L006d8823: { // 0x6d8823: 03c5 ADD EAX,EBP
    s.ax = integer::add(s.ax,s.bp,32,flags);
  }
  L006d8825: { // 0x6d8825: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L006d8829: { // 0x6d8829: c1e003 SHL EAX,0x3
    s.ax = integer::shift(s.ax,0x00000003u,32,flags,integer::Shift::left);
  }
  L006d882c: { // 0x6d882c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006d882d: { // 0x6d882d: e825510900 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,7178290u); flags=s.arithmetic_flags;
  }
  L006d8832: { // 0x6d8832: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L006d8834: { // 0x6d8834: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L006d8837: { // 0x6d8837: 3bfb CMP EDI,EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  L006d8839: { // 0x6d8839: 0f8490000000 JZ 0x006d88cf
    if(integer::condition("JZ",flags)) goto L006d88cf;
  }
  L006d883f: { // 0x6d883f: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L006d8843: { // 0x6d8843: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006d8845: { // 0x6d8845: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L006d8846: { // 0x6d8846: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L006d884a: { // 0x6d884a: 8b0d647aaa00 MOV ECX,dword ptr [0x00aa7a64]
    s.cx = m.r32((0x00aa7a64u));
  }
  L006d8850: { // 0x6d8850: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L006d8852: { // 0x6d8852: 7e21 JLE 0x006d8875
    if(integer::condition("JLE",flags)) goto L006d8875;
  }
  L006d8854: { // 0x6d8854: 8b15607aaa00 MOV EDX,dword ptr [0x00aa7a60]
    s.dx = m.r32((0x00aa7a60u));
  }
  L006d885a: { // 0x6d885a: 8d0cc2 LEA ECX,[EDX + EAX*0x8]
    s.cx = (s.dx+(s.ax * 0x00000008u));
  }
  L006d885d: { // 0x6d885d: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L006d885e: { // 0x6d885e: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L006d8860: { // 0x6d8860: 8954c7f8 MOV dword ptr [EDI + EAX*0x8 + -0x8],EDX
    m.w32((s.di+(s.ax * 0x00000008u)-0x00000008u), s.dx);
  }
  L006d8864: { // 0x6d8864: 8b4904 MOV ECX,dword ptr [ECX + 0x4]
    s.cx = m.r32((s.cx+0x00000004u));
  }
  L006d8867: { // 0x6d8867: 894cc7fc MOV dword ptr [EDI + EAX*0x8 + -0x4],ECX
    m.w32((s.di+(s.ax * 0x00000008u)-0x00000004u), s.cx);
  }
  L006d886b: { // 0x6d886b: 8b0d647aaa00 MOV ECX,dword ptr [0x00aa7a64]
    s.cx = m.r32((0x00aa7a64u));
  }
  L006d8871: { // 0x6d8871: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L006d8873: { // 0x6d8873: 7cdf JL 0x006d8854
    if(integer::condition("JL",flags)) goto L006d8854;
  }
  L006d8875: { // 0x6d8875: 8b15607aaa00 MOV EDX,dword ptr [0x00aa7a60]
    s.dx = m.r32((0x00aa7a60u));
  }
  L006d887b: { // 0x6d887b: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006d887c: { // 0x6d887c: e8fa4d0900 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,7178369u); flags=s.arithmetic_flags;
  }
  L006d8881: { // 0x6d8881: a1687aaa00 MOV EAX,[0x00aa7a68]
    s.ax = m.r32((0x00aa7a68u));
  }
  L006d8886: { // 0x6d8886: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L006d8889: { // 0x6d8889: 03c5 ADD EAX,EBP
    s.ax = integer::add(s.ax,s.bp,32,flags);
  }
  L006d888b: { // 0x6d888b: 893d607aaa00 MOV dword ptr [0x00aa7a60],EDI
    m.w32((0x00aa7a60u), s.di);
  }
  L006d8891: { // 0x6d8891: a3687aaa00 MOV [0x00aa7a68],EAX
    m.w32((0x00aa7a68u), s.ax);
  }
  L006d8896: { // 0x6d8896: 891d707aaa00 MOV dword ptr [0x00aa7a70],EBX
    m.w32((0x00aa7a70u), s.bx);
  }
  L006d889c: { // 0x6d889c: 8b0d607aaa00 MOV ECX,dword ptr [0x00aa7a60]
    s.cx = m.r32((0x00aa7a60u));
  }
  L006d88a2: { // 0x6d88a2: 8b15647aaa00 MOV EDX,dword ptr [0x00aa7a64]
    s.dx = m.r32((0x00aa7a64u));
  }
  L006d88a8: { // 0x6d88a8: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L006d88ac: { // 0x6d88ac: 8904d1 MOV dword ptr [ECX + EDX*0x8],EAX
    m.w32((s.cx+(s.dx * 0x00000008u)), s.ax);
  }
  L006d88af: { // 0x6d88af: a1647aaa00 MOV EAX,[0x00aa7a64]
    s.ax = m.r32((0x00aa7a64u));
  }
  L006d88b4: { // 0x6d88b4: 8b0d607aaa00 MOV ECX,dword ptr [0x00aa7a60]
    s.cx = m.r32((0x00aa7a60u));
  }
  L006d88ba: { // 0x6d88ba: 8974c104 MOV dword ptr [ECX + EAX*0x8 + 0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000008u)+0x00000004u), s.si);
  }
  L006d88be: { // 0x6d88be: a1647aaa00 MOV EAX,[0x00aa7a64]
    s.ax = m.r32((0x00aa7a64u));
  }
  L006d88c3: { // 0x6d88c3: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L006d88c4: { // 0x6d88c4: 881d6c7aaa00 MOV byte ptr [0x00aa7a6c],BL
    m.w8((0x00aa7a6cu), (s.bx & 0xffu));
  }
  L006d88ca: { // 0x6d88ca: a3647aaa00 MOV [0x00aa7a64],EAX
    m.w32((0x00aa7a64u), s.ax);
  }
  L006d88cf: { // 0x6d88cf: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L006d88d1: { // 0x6d88d1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006d88d2: { // 0x6d88d2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006d88d3: { // 0x6d88d3: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006d88d4: { // 0x6d88d4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006d88d5: { // 0x6d88d5: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L006d88d8: { // 0x6d88d8: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_006d88e0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006d88e0: { // 0x6d88e0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L006d88e3: { // 0x6d88e3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006d88e4: { // 0x6d88e4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006d88e5: { // 0x6d88e5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006d88e6: { // 0x6d88e6: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006d88e7: { // 0x6d88e7: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006d88e9: { // 0x6d88e9: e88220efff CALL 0x005ca970
    s.arithmetic_flags=flags; invoke(m,s,f,0x005ca970u,7178478u); flags=s.arithmetic_flags;
  }
  L006d88ee: { // 0x6d88ee: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L006d88f0: { // 0x6d88f0: 8d7e04 LEA EDI,[ESI + 0x4]
    s.di = (s.si+0x00000004u);
  }
  L006d88f3: { // 0x6d88f3: 899e98000000 MOV dword ptr [ESI + 0x98],EBX
    m.w32((s.si+0x00000098u), s.bx);
  }
  L006d88f9: { // 0x6d88f9: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  L006d88fe: { // 0x6d88fe: 89869c000000 MOV dword ptr [ESI + 0x9c],EAX
    m.w32((s.si+0x0000009cu), s.ax);
  }
  L006d8904: { // 0x6d8904: 899ea4000000 MOV dword ptr [ESI + 0xa4],EBX
    m.w32((s.si+0x000000a4u), s.bx);
  }
  L006d890a: { // 0x6d890a: 899ea8000000 MOV dword ptr [ESI + 0xa8],EBX
    m.w32((s.si+0x000000a8u), s.bx);
  }
  L006d8910: { // 0x6d8910: c786ac00000001000000 MOV dword ptr [ESI + 0xac],0x1
    m.w32((s.si+0x000000acu), 0x00000001u);
  }
  L006d891a: { // 0x6d891a: 899eb0000000 MOV dword ptr [ESI + 0xb0],EBX
    m.w32((s.si+0x000000b0u), s.bx);
  }
  L006d8920: { // 0x6d8920: 889eb4000000 MOV byte ptr [ESI + 0xb4],BL
    m.w8((s.si+0x000000b4u), (s.bx & 0xffu));
  }
  L006d8926: { // 0x6d8926: 889eb5000000 MOV byte ptr [ESI + 0xb5],BL
    m.w8((s.si+0x000000b5u), (s.bx & 0xffu));
  }
  L006d892c: { // 0x6d892c: 899eb8000000 MOV dword ptr [ESI + 0xb8],EBX
    m.w32((s.si+0x000000b8u), s.bx);
  }
  L006d8932: { // 0x6d8932: 899ebc000000 MOV dword ptr [ESI + 0xbc],EBX
    m.w32((s.si+0x000000bcu), s.bx);
  }
  L006d8938: { // 0x6d8938: 899ec0000000 MOV dword ptr [ESI + 0xc0],EBX
    m.w32((s.si+0x000000c0u), s.bx);
  }
  L006d893e: { // 0x6d893e: 899ec4000000 MOV dword ptr [ESI + 0xc4],EBX
    m.w32((s.si+0x000000c4u), s.bx);
  }
  L006d8944: { // 0x6d8944: c70674827900 MOV dword ptr [ESI],0x798274
    m.w32((s.si), 0x00798274u);
  }
  L006d894a: { // 0x6d894a: c70748827900 MOV dword ptr [EDI],0x798248
    m.w32((s.di), 0x00798248u);
  }
  L006d8950: { // 0x6d8950: c746086c827900 MOV dword ptr [ESI + 0x8],0x79826c
    m.w32((s.si+0x00000008u), 0x0079826cu);
  }
  L006d8957: { // 0x6d8957: c7460c64827900 MOV dword ptr [ESI + 0xc],0x798264
    m.w32((s.si+0x0000000cu), 0x00798264u);
  }
  L006d895e: { // 0x6d895e: a19885a200 MOV EAX,[0x00a28598]
    s.ax = m.r32((0x00a28598u));
  }
  L006d8963: { // 0x6d8963: 3905a085a200 CMP dword ptr [0x00a285a0],EAX
    (void)integer::sub(m.r32((0x00a285a0u)),s.ax,32,flags);
  }
  L006d8969: { // 0x6d8969: 7c2c JL 0x006d8997
    if(integer::condition("JL",flags)) goto L006d8997;
  }
  L006d896b: { // 0x6d896b: 381d9d85a200 CMP byte ptr [0x00a2859d],BL
    (void)integer::sub(m.r8((0x00a2859du)),(s.bx & 0xffu),8,flags);
  }
  L006d8971: { // 0x6d8971: 7504 JNZ 0x006d8977
    if(integer::condition("JNZ",flags)) goto L006d8977;
  }
  L006d8973: { // 0x6d8973: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L006d8975: { // 0x6d8975: 7538 JNZ 0x006d89af
    if(integer::condition("JNZ",flags)) goto L006d89af;
  }
  L006d8977: { // 0x6d8977: 8b0da485a200 MOV ECX,dword ptr [0x00a285a4]
    s.cx = m.r32((0x00a285a4u));
  }
  L006d897d: { // 0x6d897d: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L006d897f: { // 0x6d897f: 7e2e JLE 0x006d89af
    if(integer::condition("JLE",flags)) goto L006d89af;
  }
  L006d8981: { // 0x6d8981: 8b159085a200 MOV EDX,dword ptr [0x00a28590]
    s.dx = m.r32((0x00a28590u));
  }
  L006d8987: { // 0x6d8987: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L006d8989: { // 0x6d8989: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006d898a: { // 0x6d898a: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006d898b: { // 0x6d898b: b99085a200 MOV ECX,0xa28590
    s.cx = 0x00a28590u;
  }
  L006d8990: { // 0x6d8990: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),7178643u); flags=s.arithmetic_flags;
  }
  L006d8993: { // 0x6d8993: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006d8995: { // 0x6d8995: 7418 JZ 0x006d89af
    if(integer::condition("JZ",flags)) goto L006d89af;
  }
  L006d8997: { // 0x6d8997: 8b0da085a200 MOV ECX,dword ptr [0x00a285a0]
    s.cx = m.r32((0x00a285a0u));
  }
  L006d899d: { // 0x6d899d: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L006d899f: { // 0x6d899f: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L006d89a0: { // 0x6d89a0: 890da085a200 MOV dword ptr [0x00a285a0],ECX
    m.w32((0x00a285a0u), s.cx);
  }
  L006d89a6: { // 0x6d89a6: 8b0d9485a200 MOV ECX,dword ptr [0x00a28594]
    s.cx = m.r32((0x00a28594u));
  }
  L006d89ac: { // 0x6d89ac: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L006d89af: { // 0x6d89af: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006d89b0: { // 0x6d89b0: e80b76d3ff CALL 0x0040ffc0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0040ffc0u,7178677u); flags=s.arithmetic_flags;
  }
  L006d89b5: { // 0x6d89b5: 8b15647aaa00 MOV EDX,dword ptr [0x00aa7a64]
    s.dx = m.r32((0x00aa7a64u));
  }
  L006d89bb: { // 0x6d89bb: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L006d89bf: { // 0x6d89bf: a1687aaa00 MOV EAX,[0x00aa7a68]
    s.ax = m.r32((0x00aa7a68u));
  }
  L006d89c4: { // 0x6d89c4: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L006d89c5: { // 0x6d89c5: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L006d89c7: { // 0x6d89c7: 0f8e8e000000 JLE 0x006d8a5b
    if(integer::condition("JLE",flags)) goto L006d8a5b;
  }
  L006d89cd: { // 0x6d89cd: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L006d89cf: { // 0x6d89cf: 7507 JNZ 0x006d89d8
    if(integer::condition("JNZ",flags)) goto L006d89d8;
  }
  L006d89d1: { // 0x6d89d1: bd0a000000 MOV EBP,0xa
    s.bp = 0x0000000au;
  }
  L006d89d6: { // 0x6d89d6: eb0a JMP 0x006d89e2
    goto L006d89e2;
  }
  L006d89d8: { // 0x6d89d8: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L006d89da: { // 0x6d89da: 3beb CMP EBP,EBX
    (void)integer::sub(s.bp,s.bx,32,flags);
  }
  L006d89dc: { // 0x6d89dc: 0f8cac000000 JL 0x006d8a8e
    if(integer::condition("JL",flags)) goto L006d8a8e;
  }
  L006d89e2: { // 0x6d89e2: 03c5 ADD EAX,EBP
    s.ax = integer::add(s.ax,s.bp,32,flags);
  }
  L006d89e4: { // 0x6d89e4: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L006d89e8: { // 0x6d89e8: c1e003 SHL EAX,0x3
    s.ax = integer::shift(s.ax,0x00000003u,32,flags,integer::Shift::left);
  }
  L006d89eb: { // 0x6d89eb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006d89ec: { // 0x6d89ec: e8664f0900 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,7178737u); flags=s.arithmetic_flags;
  }
  L006d89f1: { // 0x6d89f1: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L006d89f3: { // 0x6d89f3: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L006d89f6: { // 0x6d89f6: 3bfb CMP EDI,EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  L006d89f8: { // 0x6d89f8: 0f8490000000 JZ 0x006d8a8e
    if(integer::condition("JZ",flags)) goto L006d8a8e;
  }
  L006d89fe: { // 0x6d89fe: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L006d8a02: { // 0x6d8a02: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006d8a04: { // 0x6d8a04: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L006d8a05: { // 0x6d8a05: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L006d8a09: { // 0x6d8a09: 8b0d647aaa00 MOV ECX,dword ptr [0x00aa7a64]
    s.cx = m.r32((0x00aa7a64u));
  }
  L006d8a0f: { // 0x6d8a0f: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L006d8a11: { // 0x6d8a11: 7e21 JLE 0x006d8a34
    if(integer::condition("JLE",flags)) goto L006d8a34;
  }
  L006d8a13: { // 0x6d8a13: 8b15607aaa00 MOV EDX,dword ptr [0x00aa7a60]
    s.dx = m.r32((0x00aa7a60u));
  }
  L006d8a19: { // 0x6d8a19: 8d0cc2 LEA ECX,[EDX + EAX*0x8]
    s.cx = (s.dx+(s.ax * 0x00000008u));
  }
  L006d8a1c: { // 0x6d8a1c: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L006d8a1d: { // 0x6d8a1d: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L006d8a1f: { // 0x6d8a1f: 8954c7f8 MOV dword ptr [EDI + EAX*0x8 + -0x8],EDX
    m.w32((s.di+(s.ax * 0x00000008u)-0x00000008u), s.dx);
  }
  L006d8a23: { // 0x6d8a23: 8b4904 MOV ECX,dword ptr [ECX + 0x4]
    s.cx = m.r32((s.cx+0x00000004u));
  }
  L006d8a26: { // 0x6d8a26: 894cc7fc MOV dword ptr [EDI + EAX*0x8 + -0x4],ECX
    m.w32((s.di+(s.ax * 0x00000008u)-0x00000004u), s.cx);
  }
  L006d8a2a: { // 0x6d8a2a: 8b0d647aaa00 MOV ECX,dword ptr [0x00aa7a64]
    s.cx = m.r32((0x00aa7a64u));
  }
  L006d8a30: { // 0x6d8a30: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L006d8a32: { // 0x6d8a32: 7cdf JL 0x006d8a13
    if(integer::condition("JL",flags)) goto L006d8a13;
  }
  L006d8a34: { // 0x6d8a34: 8b15607aaa00 MOV EDX,dword ptr [0x00aa7a60]
    s.dx = m.r32((0x00aa7a60u));
  }
  L006d8a3a: { // 0x6d8a3a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006d8a3b: { // 0x6d8a3b: e83b4c0900 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,7178816u); flags=s.arithmetic_flags;
  }
  L006d8a40: { // 0x6d8a40: a1687aaa00 MOV EAX,[0x00aa7a68]
    s.ax = m.r32((0x00aa7a68u));
  }
  L006d8a45: { // 0x6d8a45: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L006d8a48: { // 0x6d8a48: 03c5 ADD EAX,EBP
    s.ax = integer::add(s.ax,s.bp,32,flags);
  }
  L006d8a4a: { // 0x6d8a4a: 893d607aaa00 MOV dword ptr [0x00aa7a60],EDI
    m.w32((0x00aa7a60u), s.di);
  }
  L006d8a50: { // 0x6d8a50: a3687aaa00 MOV [0x00aa7a68],EAX
    m.w32((0x00aa7a68u), s.ax);
  }
  L006d8a55: { // 0x6d8a55: 891d707aaa00 MOV dword ptr [0x00aa7a70],EBX
    m.w32((0x00aa7a70u), s.bx);
  }
  L006d8a5b: { // 0x6d8a5b: 8b0d607aaa00 MOV ECX,dword ptr [0x00aa7a60]
    s.cx = m.r32((0x00aa7a60u));
  }
  L006d8a61: { // 0x6d8a61: 8b15647aaa00 MOV EDX,dword ptr [0x00aa7a64]
    s.dx = m.r32((0x00aa7a64u));
  }
  L006d8a67: { // 0x6d8a67: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L006d8a6b: { // 0x6d8a6b: 8904d1 MOV dword ptr [ECX + EDX*0x8],EAX
    m.w32((s.cx+(s.dx * 0x00000008u)), s.ax);
  }
  L006d8a6e: { // 0x6d8a6e: a1647aaa00 MOV EAX,[0x00aa7a64]
    s.ax = m.r32((0x00aa7a64u));
  }
  L006d8a73: { // 0x6d8a73: 8b0d607aaa00 MOV ECX,dword ptr [0x00aa7a60]
    s.cx = m.r32((0x00aa7a60u));
  }
  L006d8a79: { // 0x6d8a79: 8974c104 MOV dword ptr [ECX + EAX*0x8 + 0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000008u)+0x00000004u), s.si);
  }
  L006d8a7d: { // 0x6d8a7d: a1647aaa00 MOV EAX,[0x00aa7a64]
    s.ax = m.r32((0x00aa7a64u));
  }
  L006d8a82: { // 0x6d8a82: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L006d8a83: { // 0x6d8a83: 881d6c7aaa00 MOV byte ptr [0x00aa7a6c],BL
    m.w8((0x00aa7a6cu), (s.bx & 0xffu));
  }
  L006d8a89: { // 0x6d8a89: a3647aaa00 MOV [0x00aa7a64],EAX
    m.w32((0x00aa7a64u), s.ax);
  }
  L006d8a8e: { // 0x6d8a8e: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L006d8a90: { // 0x6d8a90: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006d8a91: { // 0x6d8a91: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006d8a92: { // 0x6d8a92: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006d8a93: { // 0x6d8a93: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006d8a94: { // 0x6d8a94: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L006d8a97: { // 0x6d8a97: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
