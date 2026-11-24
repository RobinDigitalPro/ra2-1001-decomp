#include "recovered/recovery_b824_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b824 {
namespace {
void f_002030c0(Memory&,State&,Frame&,const Operations&);
void f_0022fe40(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void f_001cd850(Memory&,State&,Frame&,const Operations&);
void f_00200de0(Memory&,State&,Frame&,const Operations&);
void f_00201870(Memory&,State&,Frame&,const Operations&);
void f_00202000(Memory&,State&,Frame&,const Operations&);
void f_00203750(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);
void f_002030c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006030c0: { // 0x6030c0: 83ec14 SUB ESP, 0x14
    f.sp = integer::sub(f.sp,0x00000014u,32,flags);
  }
  L006030c3: { // 0x6030c3: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006030c4: { // 0x6030c4: 8be9 MOV EBP, ECX
    s.bp = s.cx;
  }
  L006030c6: { // 0x6030c6: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006030c7: { // 0x6030c7: 896c2408 MOV dword ptr [ESP + 8], EBP
    m.w32((f.sp+8u), s.bp);
  }
  L006030cb: { // 0x6030cb: 8bb5b8000000 MOV ESI, dword ptr [EBP + 0xb8]
    s.si = m.r32((s.bp+0x000000b8u));
  }
  L006030d1: { // 0x6030d1: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L006030d2: { // 0x6030d2: 7811 JS 0x6030e5
    if(integer::condition("JS",flags)) goto L006030e5;
  }
  L006030d4: { // 0x6030d4: 8b85ac000000 MOV EAX, dword ptr [EBP + 0xac]
    s.ax = m.r32((s.bp+0x000000acu));
  }
  L006030da: { // 0x6030da: 8b0cb0 MOV ECX, dword ptr [EAX + ESI*4]
    s.cx = m.r32((s.ax+(s.si * 4u)));
  }
  L006030dd: { // 0x6030dd: e88ee7ffff CALL 0x601870
    s.arithmetic_flags=flags; invoke(m,s,f,0x00601870u,6303970u); flags=s.arithmetic_flags;
  }
  L006030e2: { // 0x6030e2: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L006030e3: { // 0x6030e3: 79ef JNS 0x6030d4
    if(integer::condition("JNS",flags)) goto L006030d4;
  }
  L006030e5: { // 0x6030e5: 8bb5b8000000 MOV ESI, dword ptr [EBP + 0xb8]
    s.si = m.r32((s.bp+0x000000b8u));
  }
  L006030eb: { // 0x6030eb: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L006030ec: { // 0x6030ec: 8974240c MOV dword ptr [ESP + 0xc], ESI
    m.w32((f.sp+0x0000000cu), s.si);
  }
  L006030f0: { // 0x6030f0: 0f884a010000 JS 0x603240
    if(integer::condition("JS",flags)) goto L00603240;
  }
  L006030f6: { // 0x6030f6: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006030f7: { // 0x6030f7: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006030f8: { // 0x6030f8: 8b8dac000000 MOV ECX, dword ptr [EBP + 0xac]
    s.cx = m.r32((s.bp+0x000000acu));
  }
  L006030fe: { // 0x6030fe: 8b1cb1 MOV EBX, dword ptr [ECX + ESI*4]
    s.bx = m.r32((s.cx+(s.si * 4u)));
  }
  L00603101: { // 0x603101: 8a8321010000 MOV AL, byte ptr [EBX + 0x121]
    s.ax = with_al(s.ax, m.r8((s.bx+0x00000121u)));
  }
  L00603107: { // 0x603107: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00603109: { // 0x603109: 0f841d010000 JZ 0x60322c
    if(integer::condition("JZ",flags)) goto L0060322c;
  }
  L0060310f: { // 0x60310f: 8b9398000000 MOV EDX, dword ptr [EBX + 0x98]
    s.dx = m.r32((s.bx+0x00000098u));
  }
  L00603115: { // 0x603115: 8b82e0020000 MOV EAX, dword ptr [EDX + 0x2e0]
    s.ax = m.r32((s.dx+0x000002e0u));
  }
  L0060311b: { // 0x60311b: 83f8ff CMP EAX, -1
    (void)integer::sub(s.ax,4294967295u,32,flags);
  }
  L0060311e: { // 0x60311e: 0f84f8000000 JZ 0x60321c
    if(integer::condition("JZ",flags)) goto L0060321c;
  }
  L00603124: { // 0x603124: 8b2d34e1a100 MOV EBP, dword ptr [0xa1e134]
    s.bp = m.r32((0x00a1e134u));
  }
  L0060312a: { // 0x60312a: 8d8b88000000 LEA ECX, [EBX + 0x88]
    s.cx = (s.bx+0x00000088u);
  }
  L00603130: { // 0x603130: 8bf9 MOV EDI, ECX
    s.di = s.cx;
  }
  L00603132: { // 0x603132: 6828010000 PUSH 0x128
    f.push(m,0x00000128u);
  }
  L00603137: { // 0x603137: 8b6c8500 MOV EBP, dword ptr [EBP + EAX*4]
    s.bp = m.r32((s.bp+(s.ax * 4u)));
  }
  L0060313b: { // 0x60313b: 8b8264020000 MOV EAX, dword ptr [EDX + 0x264]
    s.ax = m.r32((s.dx+0x00000264u));
  }
  L00603141: { // 0x603141: 8b0f MOV ECX, dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  L00603143: { // 0x603143: 03c1 ADD EAX, ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00603145: { // 0x603145: 8b8a68020000 MOV ECX, dword ptr [EDX + 0x268]
    s.cx = m.r32((s.dx+0x00000268u));
  }
  L0060314b: { // 0x60314b: 8b7704 MOV ESI, dword ptr [EDI + 4]
    s.si = m.r32((s.di+4u));
  }
  L0060314e: { // 0x60314e: 8b926c020000 MOV EDX, dword ptr [EDX + 0x26c]
    s.dx = m.r32((s.dx+0x0000026cu));
  }
  L00603154: { // 0x603154: 03ce ADD ECX, ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L00603156: { // 0x603156: 8944241c MOV dword ptr [ESP + 0x1c], EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0060315a: { // 0x60315a: 8b7f08 MOV EDI, dword ptr [EDI + 8]
    s.di = m.r32((s.di+8u));
  }
  L0060315d: { // 0x60315d: 894c2420 MOV dword ptr [ESP + 0x20], ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L00603161: { // 0x603161: 03d7 ADD EDX, EDI
    s.dx = integer::add(s.dx,s.di,32,flags);
  }
  L00603163: { // 0x603163: 89542424 MOV dword ptr [ESP + 0x24], EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L00603167: { // 0x603167: e8eba71600 CALL 0x76d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,6304108u); flags=s.arithmetic_flags;
  }
  L0060316c: { // 0x60316c: 83c404 ADD ESP, 4
    f.sp = integer::add(f.sp,4u,32,flags);
  }
  L0060316f: { // 0x60316f: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00603171: { // 0x603171: 0f84a1000000 JZ 0x603218
    if(integer::condition("JZ",flags)) goto L00603218;
  }
  L00603177: { // 0x603177: 6a00 PUSH 0
    f.push(m,0u);
  }
  L00603179: { // 0x603179: 8d54241c LEA EDX, [ESP + 0x1c]
    s.dx = (f.sp+0x0000001cu);
  }
  L0060317d: { // 0x60317d: 68c0e0a500 PUSH 0xa5e0c0
    f.push(m,0x00a5e0c0u);
  }
  L00603182: { // 0x603182: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00603183: { // 0x603183: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00603184: { // 0x603184: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L00603186: { // 0x603186: e895ceffff CALL 0x600020
    s.arithmetic_flags=flags; invoke(m,s,f,0x00600020u,6304139u); flags=s.arithmetic_flags;
  }
  L0060318b: { // 0x60318b: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L0060318d: { // 0x60318d: 85ff TEST EDI, EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0060318f: { // 0x60318f: 0f8483000000 JZ 0x603218
    if(integer::condition("JZ",flags)) goto L00603218;
  }
  L00603195: { // 0x603195: 8b6c2410 MOV EBP, dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L00603199: { // 0x603199: 8b8db0000000 MOV ECX, dword ptr [EBP + 0xb0]
    s.cx = m.r32((s.bp+0x000000b0u));
  }
  L0060319f: { // 0x60319f: 8b85b8000000 MOV EAX, dword ptr [EBP + 0xb8]
    s.ax = m.r32((s.bp+0x000000b8u));
  }
  L006031a5: { // 0x6031a5: 8db5a8000000 LEA ESI, [EBP + 0xa8]
    s.si = (s.bp+0x000000a8u);
  }
  L006031ab: { // 0x6031ab: 3bc1 CMP EAX, ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L006031ad: { // 0x6031ad: 7c22 JL 0x6031d1
    if(integer::condition("JL",flags)) goto L006031d1;
  }
  L006031af: { // 0x6031af: 8a460d MOV AL, byte ptr [ESI + 0xd]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000000du)));
  }
  L006031b2: { // 0x6031b2: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006031b4: { // 0x6031b4: 7504 JNZ 0x6031ba
    if(integer::condition("JNZ",flags)) goto L006031ba;
  }
  L006031b6: { // 0x6031b6: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006031b8: { // 0x6031b8: 7526 JNZ 0x6031e0
    if(integer::condition("JNZ",flags)) goto L006031e0;
  }
  L006031ba: { // 0x6031ba: 8b4614 MOV EAX, dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  L006031bd: { // 0x6031bd: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006031bf: { // 0x6031bf: 7e1f JLE 0x6031e0
    if(integer::condition("JLE",flags)) goto L006031e0;
  }
  L006031c1: { // 0x6031c1: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006031c3: { // 0x6031c3: 03c1 ADD EAX, ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L006031c5: { // 0x6031c5: 6a00 PUSH 0
    f.push(m,0u);
  }
  L006031c7: { // 0x6031c7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006031c8: { // 0x6031c8: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006031ca: { // 0x6031ca: ff5208 CALL dword ptr [EDX + 8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+8u)),6304205u); flags=s.arithmetic_flags;
  }
  L006031cd: { // 0x6031cd: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006031cf: { // 0x6031cf: 740f JZ 0x6031e0
    if(integer::condition("JZ",flags)) goto L006031e0;
  }
  L006031d1: { // 0x6031d1: 8b4610 MOV EAX, dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L006031d4: { // 0x6031d4: 8b5604 MOV EDX, dword ptr [ESI + 4]
    s.dx = m.r32((s.si+4u));
  }
  L006031d7: { // 0x6031d7: 8d4801 LEA ECX, [EAX + 1]
    s.cx = (s.ax+1u);
  }
  L006031da: { // 0x6031da: 894e10 MOV dword ptr [ESI + 0x10], ECX
    m.w32((s.si+0x00000010u), s.cx);
  }
  L006031dd: { // 0x6031dd: 893c82 MOV dword ptr [EDX + EAX*4], EDI
    m.w32((s.dx+(s.ax * 4u)), s.di);
  }
  L006031e0: { // 0x6031e0: 8b83d4000000 MOV EAX, dword ptr [EBX + 0xd4]
    s.ax = m.r32((s.bx+0x000000d4u));
  }
  L006031e6: { // 0x6031e6: 8d8bb0000000 LEA ECX, [EBX + 0xb0]
    s.cx = (s.bx+0x000000b0u);
  }
  L006031ec: { // 0x6031ec: 8987d4000000 MOV dword ptr [EDI + 0xd4], EAX
    m.w32((s.di+0x000000d4u), s.ax);
  }
  L006031f2: { // 0x6031f2: 81c7b0000000 ADD EDI, 0xb0
    s.di = integer::add(s.di,0x000000b0u,32,flags);
  }
  L006031f8: { // 0x6031f8: 8b11 MOV EDX, dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L006031fa: { // 0x6031fa: 8917 MOV dword ptr [EDI], EDX
    m.w32((s.di), s.dx);
  }
  L006031fc: { // 0x6031fc: 8b4104 MOV EAX, dword ptr [ECX + 4]
    s.ax = m.r32((s.cx+4u));
  }
  L006031ff: { // 0x6031ff: 894704 MOV dword ptr [EDI + 4], EAX
    m.w32((s.di+4u), s.ax);
  }
  L00603202: { // 0x603202: 8b4908 MOV ECX, dword ptr [ECX + 8]
    s.cx = m.r32((s.cx+8u));
  }
  L00603205: { // 0x603205: 894f08 MOV dword ptr [EDI + 8], ECX
    m.w32((s.di+8u), s.cx);
  }
  L00603208: { // 0x603208: 8b13 MOV EDX, dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L0060320a: { // 0x60320a: 8bcb MOV ECX, EBX
    s.cx = s.bx;
  }
  L0060320c: { // 0x60320c: ff92f0000000 CALL dword ptr [EDX + 0xf0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000000f0u)),6304274u); flags=s.arithmetic_flags;
  }
  L00603212: { // 0x603212: 8b742414 MOV ESI, dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L00603216: { // 0x603216: eb1b JMP 0x603233
    goto L00603233;
  }
  L00603218: { // 0x603218: 8b6c2410 MOV EBP, dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L0060321c: { // 0x60321c: 8b13 MOV EDX, dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L0060321e: { // 0x60321e: 8bcb MOV ECX, EBX
    s.cx = s.bx;
  }
  L00603220: { // 0x603220: ff92f0000000 CALL dword ptr [EDX + 0xf0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000000f0u)),6304294u); flags=s.arithmetic_flags;
  }
  L00603226: { // 0x603226: 8b742414 MOV ESI, dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L0060322a: { // 0x60322a: eb07 JMP 0x603233
    goto L00603233;
  }
  L0060322c: { // 0x60322c: 8bcb MOV ECX, EBX
    s.cx = s.bx;
  }
  L0060322e: { // 0x60322e: e8cdedffff CALL 0x602000
    s.arithmetic_flags=flags; invoke(m,s,f,0x00602000u,6304307u); flags=s.arithmetic_flags;
  }
  L00603233: { // 0x603233: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L00603234: { // 0x603234: 89742414 MOV dword ptr [ESP + 0x14], ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L00603238: { // 0x603238: 0f89bafeffff JNS 0x6030f8
    if(integer::condition("JNS",flags)) goto L006030f8;
  }
  L0060323e: { // 0x60323e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0060323f: { // 0x60323f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00603240: { // 0x603240: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00603241: { // 0x603241: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00603242: { // 0x603242: 83c414 ADD ESP, 0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L00603245: { // 0x603245: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0022fe40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0062fe40: { // 0x62fe40: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L0062fe44: { // 0x62fe44: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L0062fe46: { // 0x62fe46: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  L0062fe4a: { // 0x62fe4a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0062fe4b: { // 0x62fe4b: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0062fe4d: { // 0x62fe4d: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0062fe4f: { // 0x62fe4f: 0f8494000000 JZ 0x0062fee9
    if(integer::condition("JZ",flags)) goto L0062fee9;
  }
  L0062fe55: { // 0x62fe55: 7e04 JLE 0x0062fe5b
    if(integer::condition("JLE",flags)) goto L0062fe5b;
  }
  L0062fe57: { // 0x62fe57: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0062fe59: { // 0x62fe59: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0062fe5b: { // 0x62fe5b: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0062fe5c: { // 0x62fe5c: 2bcb SUB ECX,EBX
    s.cx = integer::sub(s.cx,s.bx,32,flags);
  }
  L0062fe5e: { // 0x62fe5e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0062fe5f: { // 0x62fe5f: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0062fe61: { // 0x62fe61: f7c700000080 TEST EDI,0x80000000
    (void)integer::logical((s.di)&(0x80000000u),32,flags);
  }
  L0062fe67: { // 0x62fe67: b91f000000 MOV ECX,0x1f
    s.cx = 0x0000001fu;
  }
  L0062fe6c: { // 0x62fe6c: 7510 JNZ 0x0062fe7e
    if(integer::condition("JNZ",flags)) goto L0062fe7e;
  }
  L0062fe6e: { // 0x62fe6e: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0062fe70: { // 0x62fe70: 7e0c JLE 0x0062fe7e
    if(integer::condition("JLE",flags)) goto L0062fe7e;
  }
  L0062fe72: { // 0x62fe72: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0062fe73: { // 0x62fe73: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L0062fe78: { // 0x62fe78: d3e0 SHL EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L0062fe7a: { // 0x62fe7a: 85c7 TEST EDI,EAX
    (void)integer::logical((s.di)&(s.ax),32,flags);
  }
  L0062fe7c: { // 0x62fe7c: 74f0 JZ 0x0062fe6e
    if(integer::condition("JZ",flags)) goto L0062fe6e;
  }
  L0062fe7e: { // 0x62fe7e: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0062fe7f: { // 0x62fe7f: 83cdff OR EBP,0xffffffff
    s.bp = integer::logical((s.bp)|(0xffffffffu),32,flags);
  }
  L0062fe82: { // 0x62fe82: d3e5 SHL EBP,CL
    s.bp = integer::shift(s.bp,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L0062fe84: { // 0x62fe84: 8d4701 LEA EAX,[EDI + 0x1]
    s.ax = (s.di+0x00000001u);
  }
  L0062fe87: { // 0x62fe87: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0062fe89: { // 0x62fe89: f7d5 NOT EBP
    s.bp = (~(s.bp)&integer::mask(32));
  }
  L0062fe8b: { // 0x62fe8b: 7e58 JLE 0x0062fee5
    if(integer::condition("JLE",flags)) goto L0062fee5;
  }
  L0062fe8d: { // 0x62fe8d: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0062fe8e: { // 0x62fe8e: 803a00 CMP byte ptr [EDX],0x0
    (void)integer::sub(m.r8((s.dx)),0x00000000u,8,flags);
  }
  L0062fe91: { // 0x62fe91: 7404 JZ 0x0062fe97
    if(integer::condition("JZ",flags)) goto L0062fe97;
  }
  L0062fe93: { // 0x62fe93: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0062fe95: { // 0x62fe95: eb47 JMP 0x0062fede
    goto L0062fede;
  }
  L0062fe97: { // 0x62fe97: 8b4a04 MOV ECX,dword ptr [EDX + 0x4]
    s.cx = m.r32((s.dx+0x00000004u));
  }
  L0062fe9a: { // 0x62fe9a: 8b748a0c MOV ESI,dword ptr [EDX + ECX*0x4 + 0xc]
    s.si = m.r32((s.dx+(s.cx * 0x00000004u)+0x0000000cu));
  }
  L0062fe9e: { // 0x62fe9e: 8d448a0c LEA EAX,[EDX + ECX*0x4 + 0xc]
    s.ax = (s.dx+(s.cx * 0x00000004u)+0x0000000cu);
  }
  L0062fea2: { // 0x62fea2: 8b4a08 MOV ECX,dword ptr [EDX + 0x8]
    s.cx = m.r32((s.dx+0x00000008u));
  }
  L0062fea5: { // 0x62fea5: 8b4c8a0c MOV ECX,dword ptr [EDX + ECX*0x4 + 0xc]
    s.cx = m.r32((s.dx+(s.cx * 0x00000004u)+0x0000000cu));
  }
  L0062fea9: { // 0x62fea9: 33f1 XOR ESI,ECX
    s.si = integer::logical((s.si)^(s.cx),32,flags);
  }
  L0062feab: { // 0x62feab: 8930 MOV dword ptr [EAX],ESI
    m.w32((s.ax), s.si);
  }
  L0062fead: { // 0x62fead: 8b4204 MOV EAX,dword ptr [EDX + 0x4]
    s.ax = m.r32((s.dx+0x00000004u));
  }
  L0062feb0: { // 0x62feb0: 8b4a08 MOV ECX,dword ptr [EDX + 0x8]
    s.cx = m.r32((s.dx+0x00000008u));
  }
  L0062feb3: { // 0x62feb3: 8b74820c MOV ESI,dword ptr [EDX + EAX*0x4 + 0xc]
    s.si = m.r32((s.dx+(s.ax * 0x00000004u)+0x0000000cu));
  }
  L0062feb7: { // 0x62feb7: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0062feb8: { // 0x62feb8: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0062feb9: { // 0x62feb9: 3dfa000000 CMP EAX,0xfa
    (void)integer::sub(s.ax,0x000000fau,32,flags);
  }
  L0062febe: { // 0x62febe: 894204 MOV dword ptr [EDX + 0x4],EAX
    m.w32((s.dx+0x00000004u), s.ax);
  }
  L0062fec1: { // 0x62fec1: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  L0062fec4: { // 0x62fec4: 7c07 JL 0x0062fecd
    if(integer::condition("JL",flags)) goto L0062fecd;
  }
  L0062fec6: { // 0x62fec6: c7420400000000 MOV dword ptr [EDX + 0x4],0x0
    m.w32((s.dx+0x00000004u), 0x00000000u);
  }
  L0062fecd: { // 0x62fecd: 81f9fa000000 CMP ECX,0xfa
    (void)integer::sub(s.cx,0x000000fau,32,flags);
  }
  L0062fed3: { // 0x62fed3: 7c07 JL 0x0062fedc
    if(integer::condition("JL",flags)) goto L0062fedc;
  }
  L0062fed5: { // 0x62fed5: c7420800000000 MOV dword ptr [EDX + 0x8],0x0
    m.w32((s.dx+0x00000008u), 0x00000000u);
  }
  L0062fedc: { // 0x62fedc: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0062fede: { // 0x62fede: 23c5 AND EAX,EBP
    s.ax = integer::logical((s.ax)&(s.bp),32,flags);
  }
  L0062fee0: { // 0x62fee0: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0062fee2: { // 0x62fee2: 7faa JG 0x0062fe8e
    if(integer::condition("JG",flags)) goto L0062fe8e;
  }
  L0062fee4: { // 0x62fee4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0062fee5: { // 0x62fee5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0062fee6: { // 0x62fee6: 03c3 ADD EAX,EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L0062fee8: { // 0x62fee8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0062fee9: { // 0x62fee9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0062feea: { // 0x62feea: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
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
void f_00200de0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00600de0: { // 0x600de0: 83ec1c SUB ESP,0x1c
    f.sp = integer::sub(f.sp,0x0000001cu,32,flags);
  }
  L00600de3: { // 0x600de3: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00600de4: { // 0x600de4: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00600de6: { // 0x600de6: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L00600dec: { // 0x600dec: 68feffff7f PUSH 0x7ffffffe
    f.push(m,0x7ffffffeu);
  }
  L00600df1: { // 0x600df1: d986fc000000 FLD float ptr [ESI + 0xfc]
    const auto address=(s.si+0x000000fcu);
    s.fp.load32(m.r32(address));
  }
  L00600df7: { // 0x600df7: d98600010000 FLD float ptr [ESI + 0x100]
    const auto address=(s.si+0x00000100u);
    s.fp.load32(m.r32(address));
  }
  L00600dfd: { // 0x600dfd: 8b86d4000000 MOV EAX,dword ptr [ESI + 0xd4]
    s.ax = m.r32((s.si+0x000000d4u));
  }
  L00600e03: { // 0x600e03: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00600e05: { // 0x600e05: d95c2420 FSTP float ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00600e09: { // 0x600e09: d98604010000 FLD float ptr [ESI + 0x104]
    const auto address=(s.si+0x00000104u);
    s.fp.load32(m.r32(address));
  }
  L00600e0f: { // 0x600e0f: d95c2424 FSTP float ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00600e13: { // 0x600e13: 8944240c MOV dword ptr [ESP + 0xc],EAX
    m.w32((f.sp+0x0000000cu), s.ax);
  }
  L00600e17: { // 0x600e17: 81c118020000 ADD ECX,0x218
    s.cx = integer::add(s.cx,0x00000218u,32,flags);
  }
  L00600e1d: { // 0x600e1d: d84c240c FMUL float ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    s.fp.multiply32(m.r32(address));
  }
  L00600e21: { // 0x600e21: d95c2410 FSTP float ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00600e25: { // 0x600e25: d9442420 FLD float ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.load32(m.r32(address));
  }
  L00600e29: { // 0x600e29: d84c240c FMUL float ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    s.fp.multiply32(m.r32(address));
  }
  L00600e2d: { // 0x600e2d: d95c2414 FSTP float ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00600e31: { // 0x600e31: d9442424 FLD float ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.load32(m.r32(address));
  }
  L00600e35: { // 0x600e35: d84c240c FMUL float ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    s.fp.multiply32(m.r32(address));
  }
  L00600e39: { // 0x600e39: d95c2418 FSTP float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00600e3d: { // 0x600e3d: e8feef0200 CALL 0x0062fe40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fe40u,6295106u); flags=s.arithmetic_flags;
  }
  L00600e42: { // 0x600e42: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  L00600e46: { // 0x600e46: db442404 FILD dword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load_integer32(m.r32(address));
  }
  L00600e4a: { // 0x600e4a: dc0d80727800 FMUL double ptr [0x00787280]
    const auto address=(0x00787280u);
    s.fp.multiply64(read64(m,address));
  }
  L00600e50: { // 0x600e50: dc2528577800 FSUB double ptr [0x00785728]
    const auto address=(0x00785728u);
    s.fp.subtract64(read64(m,address));
  }
  L00600e56: { // 0x600e56: dc0d70757800 FMUL double ptr [0x00787570]
    const auto address=(0x00787570u);
    s.fp.multiply64(read64(m,address));
  }
  L00600e5c: { // 0x600e5c: d886d4000000 FADD float ptr [ESI + 0xd4]
    const auto address=(s.si+0x000000d4u);
    s.fp.add32(m.r32(address));
  }
  L00600e62: { // 0x600e62: d99ed4000000 FSTP float ptr [ESI + 0xd4]
    const auto address=(s.si+0x000000d4u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00600e68: { // 0x600e68: d9442408 FLD float ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L00600e6c: { // 0x600e6c: d88608010000 FADD float ptr [ESI + 0x108]
    const auto address=(s.si+0x00000108u);
    s.fp.add32(m.r32(address));
  }
  L00600e72: { // 0x600e72: d99e08010000 FSTP float ptr [ESI + 0x108]
    const auto address=(s.si+0x00000108u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00600e78: { // 0x600e78: d944240c FLD float ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    s.fp.load32(m.r32(address));
  }
  L00600e7c: { // 0x600e7c: d8860c010000 FADD float ptr [ESI + 0x10c]
    const auto address=(s.si+0x0000010cu);
    s.fp.add32(m.r32(address));
  }
  L00600e82: { // 0x600e82: d99e0c010000 FSTP float ptr [ESI + 0x10c]
    const auto address=(s.si+0x0000010cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00600e88: { // 0x600e88: d9442410 FLD float ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load32(m.r32(address));
  }
  L00600e8c: { // 0x600e8c: d88610010000 FADD float ptr [ESI + 0x110]
    const auto address=(s.si+0x00000110u);
    s.fp.add32(m.r32(address));
  }
  L00600e92: { // 0x600e92: d99e10010000 FSTP float ptr [ESI + 0x110]
    const auto address=(s.si+0x00000110u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00600e98: { // 0x600e98: d98608010000 FLD float ptr [ESI + 0x108]
    const auto address=(s.si+0x00000108u);
    s.fp.load32(m.r32(address));
  }
  L00600e9e: { // 0x600e9e: e8ad9b1600 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6295203u); flags=s.arithmetic_flags;
  }
  L00600ea3: { // 0x600ea3: d9860c010000 FLD float ptr [ESI + 0x10c]
    const auto address=(s.si+0x0000010cu);
    s.fp.load32(m.r32(address));
  }
  L00600ea9: { // 0x600ea9: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00600ead: { // 0x600ead: e89e9b1600 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6295218u); flags=s.arithmetic_flags;
  }
  L00600eb2: { // 0x600eb2: d98610010000 FLD float ptr [ESI + 0x110]
    const auto address=(s.si+0x00000110u);
    s.fp.load32(m.r32(address));
  }
  L00600eb8: { // 0x600eb8: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00600ebc: { // 0x600ebc: e88f9b1600 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6295233u); flags=s.arithmetic_flags;
  }
  L00600ec1: { // 0x600ec1: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00600ec3: { // 0x600ec3: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L00600ec7: { // 0x600ec7: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L00600ecb: { // 0x600ecb: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00600ecd: { // 0x600ecd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00600ece: { // 0x600ece: ff929c010000 CALL dword ptr [EDX + 0x19c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000019cu)),6295252u); flags=s.arithmetic_flags;
  }
  L00600ed4: { // 0x600ed4: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L00600eda: { // 0x600eda: 68feffff7f PUSH 0x7ffffffe
    f.push(m,0x7ffffffeu);
  }
  L00600edf: { // 0x600edf: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00600ee1: { // 0x600ee1: 81c118020000 ADD ECX,0x218
    s.cx = integer::add(s.cx,0x00000218u,32,flags);
  }
  L00600ee7: { // 0x600ee7: e854ef0200 CALL 0x0062fe40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fe40u,6295276u); flags=s.arithmetic_flags;
  }
  L00600eec: { // 0x600eec: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  L00600ef0: { // 0x600ef0: 8b8e98000000 MOV ECX,dword ptr [ESI + 0x98]
    s.cx = m.r32((s.si+0x00000098u));
  }
  L00600ef6: { // 0x600ef6: db442404 FILD dword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load_integer32(m.r32(address));
  }
  L00600efa: { // 0x600efa: dc0d80727800 FMUL double ptr [0x00787280]
    const auto address=(0x00787280u);
    s.fp.multiply64(read64(m,address));
  }
  L00600f00: { // 0x600f00: dc0df8c07800 FMUL double ptr [0x0078c0f8]
    const auto address=(0x0078c0f8u);
    s.fp.multiply64(read64(m,address));
  }
  L00600f06: { // 0x600f06: dc8180020000 FADD double ptr [ECX + 0x280]
    const auto address=(s.cx+0x00000280u);
    s.fp.add64(read64(m,address));
  }
  L00600f0c: { // 0x600f0c: dc86a8000000 FADD double ptr [ESI + 0xa8]
    const auto address=(s.si+0x000000a8u);
    s.fp.add64(read64(m,address));
  }
  L00600f12: { // 0x600f12: dd96a8000000 FST double ptr [ESI + 0xa8]
    const auto address=(s.si+0x000000a8u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L00600f18: { // 0x600f18: dc1d08577800 FCOMP double ptr [0x00785708]
    const auto address=(0x00785708u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00600f1e: { // 0x600f1e: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00600f20: { // 0x600f20: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L00600f23: { // 0x600f23: 7547 JNZ 0x00600f6c
    if(integer::condition("JNZ",flags)) goto L00600f6c;
  }
  L00600f25: { // 0x600f25: 8b9198020000 MOV EDX,dword ptr [ECX + 0x298]
    s.dx = m.r32((s.cx+0x00000298u));
  }
  L00600f2b: { // 0x600f2b: 8b86a0000000 MOV EAX,dword ptr [ESI + 0xa0]
    s.ax = m.r32((s.si+0x000000a0u));
  }
  L00600f31: { // 0x600f31: 83ea02 SUB EDX,0x2
    s.dx = integer::sub(s.dx,0x00000002u,32,flags);
  }
  L00600f34: { // 0x600f34: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00600f36: { // 0x600f36: 7d20 JGE 0x00600f58
    if(integer::condition("JGE",flags)) goto L00600f58;
  }
  L00600f38: { // 0x600f38: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00600f39: { // 0x600f39: c786a800000000000000 MOV dword ptr [ESI + 0xa8],0x0
    m.w32((s.si+0x000000a8u), 0x00000000u);
  }
  L00600f43: { // 0x600f43: 8986a0000000 MOV dword ptr [ESI + 0xa0],EAX
    m.w32((s.si+0x000000a0u), s.ax);
  }
  L00600f49: { // 0x600f49: c786ac00000000000000 MOV dword ptr [ESI + 0xac],0x0
    m.w32((s.si+0x000000acu), 0x00000000u);
  }
  L00600f53: { // 0x600f53: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00600f54: { // 0x600f54: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L00600f57: { // 0x600f57: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00600f58: { // 0x600f58: c786a800000000000000 MOV dword ptr [ESI + 0xa8],0x0
    m.w32((s.si+0x000000a8u), 0x00000000u);
  }
  L00600f62: { // 0x600f62: c786ac0000000000f03f MOV dword ptr [ESI + 0xac],0x3ff00000
    m.w32((s.si+0x000000acu), 0x3ff00000u);
  }
  L00600f6c: { // 0x600f6c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00600f6d: { // 0x600f6d: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L00600f70: { // 0x600f70: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00201870(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00601870: { // 0x601870: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00601871: { // 0x601871: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00601873: { // 0x601873: 8b8698000000 MOV EAX,dword ptr [ESI + 0x98]
    s.ax = m.r32((s.si+0x00000098u));
  }
  L00601879: { // 0x601879: 8b80e4020000 MOV EAX,dword ptr [EAX + 0x2e4]
    s.ax = m.r32((s.ax+0x000002e4u));
  }
  L0060187f: { // 0x60187f: 83f804 CMP EAX,0x4
    (void)integer::sub(s.ax,0x00000004u,32,flags);
  }
  L00601882: { // 0x601882: 7732 JA 0x006018b6
    if(integer::condition("JA",flags)) goto L006018b6;
  }
  L00601884: { // 0x601884: ff2485d0186000 JMP dword ptr [EAX*0x4 + 0x6018d0]
    switch((std::array<std::uint32_t,5>{0x60188bu,0x601894u,0x60189du,0x6018a6u,0x6018afu}[s.ax])){
    case 0x00601870u: goto L00601870;
    case 0x00601871u: goto L00601871;
    case 0x00601873u: goto L00601873;
    case 0x00601879u: goto L00601879;
    case 0x0060187fu: goto L0060187f;
    case 0x00601882u: goto L00601882;
    case 0x00601884u: goto L00601884;
    case 0x0060188bu: goto L0060188b;
    case 0x0060188du: goto L0060188d;
    case 0x00601892u: goto L00601892;
    case 0x00601894u: goto L00601894;
    case 0x00601896u: goto L00601896;
    case 0x0060189bu: goto L0060189b;
    case 0x0060189du: goto L0060189d;
    case 0x0060189fu: goto L0060189f;
    case 0x006018a4u: goto L006018a4;
    case 0x006018a6u: goto L006018a6;
    case 0x006018a8u: goto L006018a8;
    case 0x006018adu: goto L006018ad;
    case 0x006018afu: goto L006018af;
    case 0x006018b1u: goto L006018b1;
    case 0x006018b6u: goto L006018b6;
    case 0x006018bdu: goto L006018bd;
    case 0x006018c5u: goto L006018c5;
    case 0x006018c7u: goto L006018c7;
    case 0x006018ceu: goto L006018ce;
    case 0x006018cfu: goto L006018cf;
    default:throw std::domain_error("recovery824 unsupported switch destination");}
  }
  L0060188b: { // 0x60188b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0060188d: { // 0x60188d: e8feeeffff CALL 0x00600790
    s.arithmetic_flags=flags; invoke(m,s,f,0x00600790u,6297746u); flags=s.arithmetic_flags;
  }
  L00601892: { // 0x601892: eb22 JMP 0x006018b6
    goto L006018b6;
  }
  L00601894: { // 0x601894: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00601896: { // 0x601896: e8e5f6ffff CALL 0x00600f80
    s.arithmetic_flags=flags; invoke(m,s,f,0x00600f80u,6297755u); flags=s.arithmetic_flags;
  }
  L0060189b: { // 0x60189b: eb19 JMP 0x006018b6
    goto L006018b6;
  }
  L0060189d: { // 0x60189d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0060189f: { // 0x60189f: e8acfcffff CALL 0x00601550
    s.arithmetic_flags=flags; invoke(m,s,f,0x00601550u,6297764u); flags=s.arithmetic_flags;
  }
  L006018a4: { // 0x6018a4: eb10 JMP 0x006018b6
    goto L006018b6;
  }
  L006018a6: { // 0x6018a6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006018a8: { // 0x6018a8: e873f8ffff CALL 0x00601120
    s.arithmetic_flags=flags; invoke(m,s,f,0x00601120u,6297773u); flags=s.arithmetic_flags;
  }
  L006018ad: { // 0x6018ad: eb07 JMP 0x006018b6
    goto L006018b6;
  }
  L006018af: { // 0x6018af: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006018b1: { // 0x6018b1: e82af5ffff CALL 0x00600de0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00600de0u,6297782u); flags=s.arithmetic_flags;
  }
  L006018b6: { // 0x6018b6: 66ff8e18010000 DEC word ptr [ESI + 0x118]
    m.w16((s.si+0x00000118u), integer::decrement(m.r16((s.si+0x00000118u)),16,flags));
  }
  L006018bd: { // 0x6018bd: 6683be1801000000 CMP word ptr [ESI + 0x118],0x0
    (void)integer::sub(m.r16((s.si+0x00000118u)),0x00000000u,16,flags);
  }
  L006018c5: { // 0x6018c5: 7507 JNZ 0x006018ce
    if(integer::condition("JNZ",flags)) goto L006018ce;
  }
  L006018c7: { // 0x6018c7: c6862101000001 MOV byte ptr [ESI + 0x121],0x1
    m.w8((s.si+0x00000121u), 0x00000001u);
  }
  L006018ce: { // 0x6018ce: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006018cf: { // 0x6018cf: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00202000(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00602000: { // 0x602000: 83ec18 SUB ESP,0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
  L00602003: { // 0x602003: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00602004: { // 0x602004: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00602006: { // 0x602006: 8b8698000000 MOV EAX,dword ptr [ESI + 0x98]
    s.ax = m.r32((s.si+0x00000098u));
  }
  L0060200c: { // 0x60200c: 8b80e4020000 MOV EAX,dword ptr [EAX + 0x2e4]
    s.ax = m.r32((s.ax+0x000002e4u));
  }
  L00602012: { // 0x602012: 83e800 SUB EAX,0x0
    s.ax = integer::sub(s.ax,0x00000000u,32,flags);
  }
  L00602015: { // 0x602015: 0f84de000000 JZ 0x006020f9
    if(integer::condition("JZ",flags)) goto L006020f9;
  }
  L0060201b: { // 0x60201b: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0060201c: { // 0x60201c: 0f84cb000000 JZ 0x006020ed
    if(integer::condition("JZ",flags)) goto L006020ed;
  }
  L00602022: { // 0x602022: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00602023: { // 0x602023: 0f85d7000000 JNZ 0x00602100
    if(integer::condition("JNZ",flags)) goto L00602100;
  }
  L00602029: { // 0x602029: d986d4000000 FLD float ptr [ESI + 0xd4]
    const auto address=(s.si+0x000000d4u);
    s.fp.load32(m.r32(address));
  }
  L0060202f: { // 0x60202f: dc1d10667800 FCOMP double ptr [0x00786610]
    const auto address=(0x00786610u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00602035: { // 0x602035: 8d8688000000 LEA EAX,[ESI + 0x88]
    s.ax = (s.si+0x00000088u);
  }
  L0060203b: { // 0x60203b: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0060203c: { // 0x60203c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0060203d: { // 0x60203d: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0060203f: { // 0x60203f: 8b18 MOV EBX,dword ptr [EAX]
    s.bx = m.r32((s.ax));
  }
  L00602041: { // 0x602041: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  L00602043: { // 0x602043: 895c2418 MOV dword ptr [ESP + 0x18],EBX
    m.w32((f.sp+0x00000018u), s.bx);
  }
  L00602047: { // 0x602047: 8b5804 MOV EBX,dword ptr [EAX + 0x4]
    s.bx = m.r32((s.ax+0x00000004u));
  }
  L0060204a: { // 0x60204a: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L0060204d: { // 0x60204d: 8b5704 MOV EDX,dword ptr [EDI + 0x4]
    s.dx = m.r32((s.di+0x00000004u));
  }
  L00602050: { // 0x602050: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L00602054: { // 0x602054: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00602056: { // 0x602056: 8b7f08 MOV EDI,dword ptr [EDI + 0x8]
    s.di = m.r32((s.di+0x00000008u));
  }
  L00602059: { // 0x602059: 894c240c MOV dword ptr [ESP + 0xc],ECX
    m.w32((f.sp+0x0000000cu), s.cx);
  }
  L0060205d: { // 0x60205d: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L00602060: { // 0x602060: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L00602064: { // 0x602064: 897c2414 MOV dword ptr [ESP + 0x14],EDI
    m.w32((f.sp+0x00000014u), s.di);
  }
  L00602068: { // 0x602068: 895c241c MOV dword ptr [ESP + 0x1c],EBX
    m.w32((f.sp+0x0000001cu), s.bx);
  }
  L0060206c: { // 0x60206c: 7524 JNZ 0x00602092
    if(integer::condition("JNZ",flags)) goto L00602092;
  }
  L0060206e: { // 0x60206e: 8b9ef0000000 MOV EBX,dword ptr [ESI + 0xf0]
    s.bx = m.r32((s.si+0x000000f0u));
  }
  L00602074: { // 0x602074: 8b86f8000000 MOV EAX,dword ptr [ESI + 0xf8]
    s.ax = m.r32((s.si+0x000000f8u));
  }
  L0060207a: { // 0x60207a: 03cb ADD ECX,EBX
    s.cx = integer::add(s.cx,s.bx,32,flags);
  }
  L0060207c: { // 0x60207c: 894c240c MOV dword ptr [ESP + 0xc],ECX
    m.w32((f.sp+0x0000000cu), s.cx);
  }
  L00602080: { // 0x602080: 8b8ef4000000 MOV ECX,dword ptr [ESI + 0xf4]
    s.cx = m.r32((s.si+0x000000f4u));
  }
  L00602086: { // 0x602086: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L00602088: { // 0x602088: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L0060208a: { // 0x60208a: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L0060208e: { // 0x60208e: 897c2414 MOV dword ptr [ESP + 0x14],EDI
    m.w32((f.sp+0x00000014u), s.di);
  }
  L00602092: { // 0x602092: d986d4000000 FLD float ptr [ESI + 0xd4]
    const auto address=(s.si+0x000000d4u);
    s.fp.load32(m.r32(address));
  }
  L00602098: { // 0x602098: dc1d10667800 FCOMP double ptr [0x00786610]
    const auto address=(0x00786610u);
    s.fp.compare_pop64(read64(m,address));
  }
  L0060209e: { // 0x60209e: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L006020a0: { // 0x6020a0: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L006020a3: { // 0x6020a3: 7532 JNZ 0x006020d7
    if(integer::condition("JNZ",flags)) goto L006020d7;
  }
  L006020a5: { // 0x6020a5: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L006020a9: { // 0x6020a9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006020aa: { // 0x6020aa: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006020af: { // 0x6020af: e8bc4ff5ff CALL 0x00557070
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557070u,6299828u); flags=s.arithmetic_flags;
  }
  L006020b4: { // 0x6020b4: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  L006020b8: { // 0x6020b8: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006020bd: { // 0x6020bd: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006020be: { // 0x6020be: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L006020c0: { // 0x6020c0: e8ab4ff5ff CALL 0x00557070
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557070u,6299845u); flags=s.arithmetic_flags;
  }
  L006020c5: { // 0x6020c5: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L006020c7: { // 0x6020c7: 7e0e JLE 0x006020d7
    if(integer::condition("JLE",flags)) goto L006020d7;
  }
  L006020c9: { // 0x6020c9: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006020cb: { // 0x6020cb: 88861d010000 MOV byte ptr [ESI + 0x11d],AL
    m.w8((s.si+0x0000011du), (s.ax & 0xffu));
  }
  L006020d1: { // 0x6020d1: 888621010000 MOV byte ptr [ESI + 0x121],AL
    m.w8((s.si+0x00000121u), (s.ax & 0xffu));
  }
  L006020d7: { // 0x6020d7: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006020d9: { // 0x6020d9: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  L006020dd: { // 0x6020dd: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006020de: { // 0x6020de: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006020e0: { // 0x6020e0: ff909c010000 CALL dword ptr [EAX + 0x19c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000019cu)),6299878u); flags=s.arithmetic_flags;
  }
  L006020e6: { // 0x6020e6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006020e7: { // 0x6020e7: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006020e8: { // 0x6020e8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006020e9: { // 0x6020e9: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L006020ec: { // 0x6020ec: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L006020ed: { // 0x6020ed: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006020ef: { // 0x6020ef: e81cfdffff CALL 0x00601e10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00601e10u,6299892u); flags=s.arithmetic_flags;
  }
  L006020f4: { // 0x6020f4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006020f5: { // 0x6020f5: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L006020f8: { // 0x6020f8: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L006020f9: { // 0x6020f9: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006020fb: { // 0x6020fb: e8c0fbffff CALL 0x00601cc0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00601cc0u,6299904u); flags=s.arithmetic_flags;
  }
  L00602100: { // 0x602100: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00602101: { // 0x602101: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L00602104: { // 0x602104: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00203750(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00603750: { // 0x603750: 83ec44 SUB ESP, 0x44
    f.sp = integer::sub(f.sp,0x00000044u,32,flags);
  }
  L00603753: { // 0x603753: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00603754: { // 0x603754: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00603755: { // 0x603755: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00603756: { // 0x603756: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00603757: { // 0x603757: 8bf9 MOV EDI, ECX
    s.di = s.cx;
  }
  L00603759: { // 0x603759: 897c2414 MOV dword ptr [ESP + 0x14], EDI
    m.w32((f.sp+0x00000014u), s.di);
  }
  L0060375d: { // 0x60375d: 8b87cc000000 MOV EAX, dword ptr [EDI + 0xcc]
    s.ax = m.r32((s.di+0x000000ccu));
  }
  L00603763: { // 0x603763: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00603765: { // 0x603765: 7468 JZ 0x6037cf
    if(integer::condition("JZ",flags)) goto L006037cf;
  }
  L00603767: { // 0x603767: 8a4814 MOV CL, byte ptr [EAX + 0x14]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000014u)));
  }
  L0060376a: { // 0x60376a: d0e9 SHR CL, 1
    s.cx = with_al(s.cx, integer::shift((s.cx & 0xffu),1u,8,flags,integer::Shift::right));
  }
  L0060376c: { // 0x60376c: 80e101 AND CL, 1
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))&(1u),8,flags));
  }
  L0060376f: { // 0x60376f: 884c2413 MOV byte ptr [ESP + 0x13], CL
    m.w8((f.sp+0x00000013u), (s.cx & 0xffu));
  }
  L00603773: { // 0x603773: 745a JZ 0x6037cf
    if(integer::condition("JZ",flags)) goto L006037cf;
  }
  L00603775: { // 0x603775: 8b5004 MOV EDX, dword ptr [EAX + 4]
    s.dx = m.r32((s.ax+4u));
  }
  L00603778: { // 0x603778: 83c004 ADD EAX, 4
    s.ax = integer::add(s.ax,4u,32,flags);
  }
  L0060377b: { // 0x60377b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0060377c: { // 0x60377c: ff520c CALL dword ptr [EDX + 0xc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000000cu)),6305663u); flags=s.arithmetic_flags;
  }
  L0060377f: { // 0x60377f: 83f806 CMP EAX, 6
    (void)integer::sub(s.ax,6u,32,flags);
  }
  L00603782: { // 0x603782: 744b JZ 0x6037cf
    if(integer::condition("JZ",flags)) goto L006037cf;
  }
  L00603784: { // 0x603784: 8b8fcc000000 MOV ECX, dword ptr [EDI + 0xcc]
    s.cx = m.r32((s.di+0x000000ccu));
  }
  L0060378a: { // 0x60378a: 8d542448 LEA EDX, [ESP + 0x48]
    s.dx = (f.sp+0x00000048u);
  }
  L0060378e: { // 0x60378e: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0060378f: { // 0x60378f: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00603791: { // 0x603791: ff5048 CALL dword ptr [EAX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000048u)),6305684u); flags=s.arithmetic_flags;
  }
  L00603794: { // 0x603794: 8b8f9c000000 MOV ECX, dword ptr [EDI + 0x9c]
    s.cx = m.r32((s.di+0x0000009cu));
  }
  L0060379a: { // 0x60379a: 8b10 MOV EDX, dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0060379c: { // 0x60379c: 8b6804 MOV EBP, dword ptr [EAX + 4]
    s.bp = m.r32((s.ax+4u));
  }
  L0060379f: { // 0x60379f: 8b5808 MOV EBX, dword ptr [EAX + 8]
    s.bx = m.r32((s.ax+8u));
  }
  L006037a2: { // 0x6037a2: 8bb7a4000000 MOV ESI, dword ptr [EDI + 0xa4]
    s.si = m.r32((s.di+0x000000a4u));
  }
  L006037a8: { // 0x6037a8: 8b07 MOV EAX, dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L006037aa: { // 0x6037aa: 03ca ADD ECX, EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L006037ac: { // 0x6037ac: 8b97a0000000 MOV EDX, dword ptr [EDI + 0xa0]
    s.dx = m.r32((s.di+0x000000a0u));
  }
  L006037b2: { // 0x6037b2: 894c2430 MOV dword ptr [ESP + 0x30], ECX
    m.w32((f.sp+0x00000030u), s.cx);
  }
  L006037b6: { // 0x6037b6: 8d4c2430 LEA ECX, [ESP + 0x30]
    s.cx = (f.sp+0x00000030u);
  }
  L006037ba: { // 0x6037ba: 03d5 ADD EDX, EBP
    s.dx = integer::add(s.dx,s.bp,32,flags);
  }
  L006037bc: { // 0x6037bc: 03f3 ADD ESI, EBX
    s.si = integer::add(s.si,s.bx,32,flags);
  }
  L006037be: { // 0x6037be: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006037bf: { // 0x6037bf: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L006037c1: { // 0x6037c1: 89542438 MOV dword ptr [ESP + 0x38], EDX
    m.w32((f.sp+0x00000038u), s.dx);
  }
  L006037c5: { // 0x6037c5: 8974243c MOV dword ptr [ESP + 0x3c], ESI
    m.w32((f.sp+0x0000003cu), s.si);
  }
  L006037c9: { // 0x6037c9: ff909c010000 CALL dword ptr [EAX + 0x19c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000019cu)),6305743u); flags=s.arithmetic_flags;
  }
  L006037cf: { // 0x6037cf: 8b87b8000000 MOV EAX, dword ptr [EDI + 0xb8]
    s.ax = m.r32((s.di+0x000000b8u));
  }
  L006037d5: { // 0x6037d5: 33f6 XOR ESI, ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L006037d7: { // 0x6037d7: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006037d9: { // 0x6037d9: 7e19 JLE 0x6037f4
    if(integer::condition("JLE",flags)) goto L006037f4;
  }
  L006037db: { // 0x6037db: 8b97ac000000 MOV EDX, dword ptr [EDI + 0xac]
    s.dx = m.r32((s.di+0x000000acu));
  }
  L006037e1: { // 0x6037e1: 8b0cb2 MOV ECX, dword ptr [EDX + ESI*4]
    s.cx = m.r32((s.dx+(s.si * 4u)));
  }
  L006037e4: { // 0x6037e4: e887e0ffff CALL 0x601870
    s.arithmetic_flags=flags; invoke(m,s,f,0x00601870u,6305769u); flags=s.arithmetic_flags;
  }
  L006037e9: { // 0x6037e9: 8b87b8000000 MOV EAX, dword ptr [EDI + 0xb8]
    s.ax = m.r32((s.di+0x000000b8u));
  }
  L006037ef: { // 0x6037ef: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L006037f0: { // 0x6037f0: 3bf0 CMP ESI, EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L006037f2: { // 0x6037f2: 7ce7 JL 0x6037db
    if(integer::condition("JL",flags)) goto L006037db;
  }
  L006037f4: { // 0x6037f4: 8b9fb8000000 MOV EBX, dword ptr [EDI + 0xb8]
    s.bx = m.r32((s.di+0x000000b8u));
  }
  L006037fa: { // 0x6037fa: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L006037fb: { // 0x6037fb: 895c2428 MOV dword ptr [ESP + 0x28], EBX
    m.w32((f.sp+0x00000028u), s.bx);
  }
  L006037ff: { // 0x6037ff: 0f8846020000 JS 0x603a4b
    if(integer::condition("JS",flags)) goto L00603a4b;
  }
  L00603805: { // 0x603805: 8b87ac000000 MOV EAX, dword ptr [EDI + 0xac]
    s.ax = m.r32((s.di+0x000000acu));
  }
  L0060380b: { // 0x60380b: 8b3498 MOV ESI, dword ptr [EAX + EBX*4]
    s.si = m.r32((s.ax+(s.bx * 4u)));
  }
  L0060380e: { // 0x60380e: 8a8621010000 MOV AL, byte ptr [ESI + 0x121]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000121u)));
  }
  L00603814: { // 0x603814: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00603816: { // 0x603816: 0f841d020000 JZ 0x603a39
    if(integer::condition("JZ",flags)) goto L00603a39;
  }
  L0060381c: { // 0x60381c: 8b8e98000000 MOV ECX, dword ptr [ESI + 0x98]
    s.cx = m.r32((s.si+0x00000098u));
  }
  L00603822: { // 0x603822: 83b9e0020000ff CMP dword ptr [ECX + 0x2e0], -1
    (void)integer::sub(m.r32((s.cx+0x000002e0u)),4294967295u,32,flags);
  }
  L00603829: { // 0x603829: 0f84fa010000 JZ 0x603a29
    if(integer::condition("JZ",flags)) goto L00603a29;
  }
  L0060382f: { // 0x60382f: 8d9688000000 LEA EDX, [ESI + 0x88]
    s.dx = (s.si+0x00000088u);
  }
  L00603835: { // 0x603835: 8b0dc055a200 MOV ECX, dword ptr [0xa255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L0060383b: { // 0x60383b: 81c118020000 ADD ECX, 0x218
    s.cx = integer::add(s.cx,0x00000218u,32,flags);
  }
  L00603841: { // 0x603841: 8b3a MOV EDI, dword ptr [EDX]
    s.di = m.r32((s.dx));
  }
  L00603843: { // 0x603843: 8b6a04 MOV EBP, dword ptr [EDX + 4]
    s.bp = m.r32((s.dx+4u));
  }
  L00603846: { // 0x603846: 8b4208 MOV EAX, dword ptr [EDX + 8]
    s.ax = m.r32((s.dx+8u));
  }
  L00603849: { // 0x603849: 8b9698000000 MOV EDX, dword ptr [ESI + 0x98]
    s.dx = m.r32((s.si+0x00000098u));
  }
  L0060384f: { // 0x60384f: 89442450 MOV dword ptr [ESP + 0x50], EAX
    m.w32((f.sp+0x00000050u), s.ax);
  }
  L00603853: { // 0x603853: 8b9ad4020000 MOV EBX, dword ptr [EDX + 0x2d4]
    s.bx = m.r32((s.dx+0x000002d4u));
  }
  L00603859: { // 0x603859: c1fb03 SAR EBX, 3
    s.bx = integer::shift(s.bx,3u,32,flags,integer::Shift::arithmetic_right);
  }
  L0060385c: { // 0x60385c: e87fc50200 CALL 0x62fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,6305889u); flags=s.arithmetic_flags;
  }
  L00603861: { // 0x603861: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00603862: { // 0x603862: f7fb IDIV EBX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.bx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00603864: { // 0x603864: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00603866: { // 0x603866: 7f04 JG 0x60386c
    if(integer::condition("JG",flags)) goto L0060386c;
  }
  L00603868: { // 0x603868: 2bd3 SUB EDX, EBX
    s.dx = integer::sub(s.dx,s.bx,32,flags);
  }
  L0060386a: { // 0x60386a: eb02 JMP 0x60386e
    goto L0060386e;
  }
  L0060386c: { // 0x60386c: 03d3 ADD EDX, EBX
    s.dx = integer::add(s.dx,s.bx,32,flags);
  }
  L0060386e: { // 0x60386e: a1c055a200 MOV EAX, dword ptr [0xa255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  L00603873: { // 0x603873: 8954241c MOV dword ptr [ESP + 0x1c], EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L00603877: { // 0x603877: 8d8818020000 LEA ECX, [EAX + 0x218]
    s.cx = (s.ax+0x00000218u);
  }
  L0060387d: { // 0x60387d: 8b8698000000 MOV EAX, dword ptr [ESI + 0x98]
    s.ax = m.r32((s.si+0x00000098u));
  }
  L00603883: { // 0x603883: 8944242c MOV dword ptr [ESP + 0x2c], EAX
    m.w32((f.sp+0x0000002cu), s.ax);
  }
  L00603887: { // 0x603887: 8b98d4020000 MOV EBX, dword ptr [EAX + 0x2d4]
    s.bx = m.r32((s.ax+0x000002d4u));
  }
  L0060388d: { // 0x60388d: c1fb03 SAR EBX, 3
    s.bx = integer::shift(s.bx,3u,32,flags,integer::Shift::arithmetic_right);
  }
  L00603890: { // 0x603890: 895c2424 MOV dword ptr [ESP + 0x24], EBX
    m.w32((f.sp+0x00000024u), s.bx);
  }
  L00603894: { // 0x603894: e847c50200 CALL 0x62fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,6305945u); flags=s.arithmetic_flags;
  }
  L00603899: { // 0x603899: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0060389a: { // 0x60389a: f7fb IDIV EBX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.bx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L0060389c: { // 0x60389c: 8b442424 MOV EAX, dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L006038a0: { // 0x6038a0: 8bda MOV EBX, EDX
    s.bx = s.dx;
  }
  L006038a2: { // 0x6038a2: 85db TEST EBX, EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L006038a4: { // 0x6038a4: 7f04 JG 0x6038aa
    if(integer::condition("JG",flags)) goto L006038aa;
  }
  L006038a6: { // 0x6038a6: 2bd8 SUB EBX, EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L006038a8: { // 0x6038a8: eb02 JMP 0x6038ac
    goto L006038ac;
  }
  L006038aa: { // 0x6038aa: 03d8 ADD EBX, EAX
    s.bx = integer::add(s.bx,s.ax,32,flags);
  }
  L006038ac: { // 0x6038ac: 8b4c242c MOV ECX, dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L006038b0: { // 0x6038b0: a134e1a100 MOV EAX, dword ptr [0xa1e134]
    s.ax = m.r32((0x00a1e134u));
  }
  L006038b5: { // 0x6038b5: 6828010000 PUSH 0x128
    f.push(m,0x00000128u);
  }
  L006038ba: { // 0x6038ba: 8b91e0020000 MOV EDX, dword ptr [ECX + 0x2e0]
    s.dx = m.r32((s.cx+0x000002e0u));
  }
  L006038c0: { // 0x6038c0: 8b0c90 MOV ECX, dword ptr [EAX + EDX*4]
    s.cx = m.r32((s.ax+(s.dx * 4u)));
  }
  L006038c3: { // 0x6038c3: 8b542420 MOV EDX, dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L006038c7: { // 0x6038c7: 894c2428 MOV dword ptr [ESP + 0x28], ECX
    m.w32((f.sp+0x00000028u), s.cx);
  }
  L006038cb: { // 0x6038cb: 8d0c2b LEA ECX, [EBX + EBP]
    s.cx = (s.bx+s.bp);
  }
  L006038ce: { // 0x6038ce: 8d0417 LEA EAX, [EDI + EDX]
    s.ax = (s.di+s.dx);
  }
  L006038d1: { // 0x6038d1: 894c2438 MOV dword ptr [ESP + 0x38], ECX
    m.w32((f.sp+0x00000038u), s.cx);
  }
  L006038d5: { // 0x6038d5: 89442434 MOV dword ptr [ESP + 0x34], EAX
    m.w32((f.sp+0x00000034u), s.ax);
  }
  L006038d9: { // 0x6038d9: 8b442454 MOV EAX, dword ptr [ESP + 0x54]
    s.ax = m.r32((f.sp+0x00000054u));
  }
  L006038dd: { // 0x6038dd: 8944243c MOV dword ptr [ESP + 0x3c], EAX
    m.w32((f.sp+0x0000003cu), s.ax);
  }
  L006038e1: { // 0x6038e1: e871a01600 CALL 0x76d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,6306022u); flags=s.arithmetic_flags;
  }
  L006038e6: { // 0x6038e6: 83c404 ADD ESP, 4
    f.sp = integer::add(f.sp,4u,32,flags);
  }
  L006038e9: { // 0x6038e9: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006038eb: { // 0x6038eb: 0f84c4000000 JZ 0x6039b5
    if(integer::condition("JZ",flags)) goto L006039b5;
  }
  L006038f1: { // 0x6038f1: 8b542424 MOV EDX, dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L006038f5: { // 0x6038f5: 6a00 PUSH 0
    f.push(m,0u);
  }
  L006038f7: { // 0x6038f7: 8d4c2434 LEA ECX, [ESP + 0x34]
    s.cx = (f.sp+0x00000034u);
  }
  L006038fb: { // 0x6038fb: 68c0e0a500 PUSH 0xa5e0c0
    f.push(m,0x00a5e0c0u);
  }
  L00603900: { // 0x603900: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00603901: { // 0x603901: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00603902: { // 0x603902: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L00603904: { // 0x603904: e817c7ffff CALL 0x600020
    s.arithmetic_flags=flags; invoke(m,s,f,0x00600020u,6306057u); flags=s.arithmetic_flags;
  }
  L00603909: { // 0x603909: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0060390b: { // 0x60390b: 89442418 MOV dword ptr [ESP + 0x18], EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0060390f: { // 0x60390f: 745d JZ 0x60396e
    if(integer::condition("JZ",flags)) goto L0060396e;
  }
  L00603911: { // 0x603911: 8b4c2414 MOV ECX, dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L00603915: { // 0x603915: 8d442418 LEA EAX, [ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L00603919: { // 0x603919: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0060391a: { // 0x60391a: 81c1a8000000 ADD ECX, 0xa8
    s.cx = integer::add(s.cx,0x000000a8u,32,flags);
  }
  L00603920: { // 0x603920: e80b130000 CALL 0x604c30
    s.arithmetic_flags=flags; invoke(m,s,f,0x00604c30u,6306085u); flags=s.arithmetic_flags;
  }
  L00603925: { // 0x603925: 8b442418 MOV EAX, dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00603929: { // 0x603929: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0060392b: { // 0x60392b: 8944242c MOV dword ptr [ESP + 0x2c], EAX
    m.w32((f.sp+0x0000002cu), s.ax);
  }
  L0060392f: { // 0x60392f: 743d JZ 0x60396e
    if(integer::condition("JZ",flags)) goto L0060396e;
  }
  L00603931: { // 0x603931: 8b96d4000000 MOV EDX, dword ptr [ESI + 0xd4]
    s.dx = m.r32((s.si+0x000000d4u));
  }
  L00603937: { // 0x603937: 8990d4000000 MOV dword ptr [EAX + 0xd4], EDX
    m.w32((s.ax+0x000000d4u), s.dx);
  }
  L0060393d: { // 0x60393d: a1c055a200 MOV EAX, dword ptr [0xa255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  L00603942: { // 0x603942: 8d8818020000 LEA ECX, [EAX + 0x218]
    s.cx = (s.ax+0x00000218u);
  }
  L00603948: { // 0x603948: e893c40200 CALL 0x62fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,6306125u); flags=s.arithmetic_flags;
  }
  L0060394d: { // 0x60394d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0060394e: { // 0x60394e: b906000000 MOV ECX, 6
    s.cx = 6u;
  }
  L00603953: { // 0x603953: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00603955: { // 0x603955: 8a861f010000 MOV AL, byte ptr [ESI + 0x11f]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000011fu)));
  }
  L0060395b: { // 0x60395b: f7da NEG EDX
    s.dx = integer::sub(0u,s.dx,32,flags);
  }
  L0060395d: { // 0x60395d: 1ad2 SBB DL, DL
    s.dx = with_al(s.dx, integer::sub((s.dx & 0xffu),(s.dx & 0xffu),8,flags,flags&integer::CF));
  }
  L0060395f: { // 0x60395f: 83e219 AND EDX, 0x19
    s.dx = integer::logical((s.dx)&(0x00000019u),32,flags);
  }
  L00603962: { // 0x603962: 02d0 ADD DL, AL
    s.dx = with_al(s.dx, integer::add((s.dx & 0xffu),(s.ax & 0xffu),8,flags));
  }
  L00603964: { // 0x603964: 8b44242c MOV EAX, dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L00603968: { // 0x603968: 88901f010000 MOV byte ptr [EAX + 0x11f], DL
    m.w8((s.ax+0x0000011fu), (s.dx & 0xffu));
  }
  L0060396e: { // 0x60396e: 8b4c241c MOV ECX, dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L00603972: { // 0x603972: 2beb SUB EBP, EBX
    s.bp = integer::sub(s.bp,s.bx,32,flags);
  }
  L00603974: { // 0x603974: 2bf9 SUB EDI, ECX
    s.di = integer::sub(s.di,s.cx,32,flags);
  }
  L00603976: { // 0x603976: 8b4c2450 MOV ECX, dword ptr [ESP + 0x50]
    s.cx = m.r32((f.sp+0x00000050u));
  }
  L0060397a: { // 0x60397a: 6828010000 PUSH 0x128
    f.push(m,0x00000128u);
  }
  L0060397f: { // 0x60397f: 897c2440 MOV dword ptr [ESP + 0x40], EDI
    m.w32((f.sp+0x00000040u), s.di);
  }
  L00603983: { // 0x603983: 896c2444 MOV dword ptr [ESP + 0x44], EBP
    m.w32((f.sp+0x00000044u), s.bp);
  }
  L00603987: { // 0x603987: 894c2448 MOV dword ptr [ESP + 0x48], ECX
    m.w32((f.sp+0x00000048u), s.cx);
  }
  L0060398b: { // 0x60398b: e8c79f1600 CALL 0x76d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,6306192u); flags=s.arithmetic_flags;
  }
  L00603990: { // 0x603990: 83c404 ADD ESP, 4
    f.sp = integer::add(f.sp,4u,32,flags);
  }
  L00603993: { // 0x603993: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00603995: { // 0x603995: 7428 JZ 0x6039bf
    if(integer::condition("JZ",flags)) goto L006039bf;
  }
  L00603997: { // 0x603997: 8b4c2424 MOV ECX, dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L0060399b: { // 0x60399b: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0060399d: { // 0x60399d: 8d542440 LEA EDX, [ESP + 0x40]
    s.dx = (f.sp+0x00000040u);
  }
  L006039a1: { // 0x6039a1: 68c0e0a500 PUSH 0xa5e0c0
    f.push(m,0x00a5e0c0u);
  }
  L006039a6: { // 0x6039a6: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006039a7: { // 0x6039a7: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006039a8: { // 0x6039a8: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L006039aa: { // 0x6039aa: e871c6ffff CALL 0x600020
    s.arithmetic_flags=flags; invoke(m,s,f,0x00600020u,6306223u); flags=s.arithmetic_flags;
  }
  L006039af: { // 0x6039af: 89442420 MOV dword ptr [ESP + 0x20], EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L006039b3: { // 0x6039b3: eb14 JMP 0x6039c9
    goto L006039c9;
  }
  L006039b5: { // 0x6039b5: c744241800000000 MOV dword ptr [ESP + 0x18], 0
    m.w32((f.sp+0x00000018u), 0u);
  }
  L006039bd: { // 0x6039bd: ebaf JMP 0x60396e
    goto L0060396e;
  }
  L006039bf: { // 0x6039bf: c744242000000000 MOV dword ptr [ESP + 0x20], 0
    m.w32((f.sp+0x00000020u), 0u);
  }
  L006039c7: { // 0x6039c7: eb5c JMP 0x603a25
    goto L00603a25;
  }
  L006039c9: { // 0x6039c9: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006039cb: { // 0x6039cb: 7458 JZ 0x603a25
    if(integer::condition("JZ",flags)) goto L00603a25;
  }
  L006039cd: { // 0x6039cd: 8b442414 MOV EAX, dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L006039d1: { // 0x6039d1: 8d542420 LEA EDX, [ESP + 0x20]
    s.dx = (f.sp+0x00000020u);
  }
  L006039d5: { // 0x6039d5: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006039d6: { // 0x6039d6: 8d88a8000000 LEA ECX, [EAX + 0xa8]
    s.cx = (s.ax+0x000000a8u);
  }
  L006039dc: { // 0x6039dc: e84f120000 CALL 0x604c30
    s.arithmetic_flags=flags; invoke(m,s,f,0x00604c30u,6306273u); flags=s.arithmetic_flags;
  }
  L006039e1: { // 0x6039e1: 8b442420 MOV EAX, dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L006039e5: { // 0x6039e5: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006039e7: { // 0x6039e7: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L006039e9: { // 0x6039e9: 743a JZ 0x603a25
    if(integer::condition("JZ",flags)) goto L00603a25;
  }
  L006039eb: { // 0x6039eb: 8b8ed4000000 MOV ECX, dword ptr [ESI + 0xd4]
    s.cx = m.r32((s.si+0x000000d4u));
  }
  L006039f1: { // 0x6039f1: 8988d4000000 MOV dword ptr [EAX + 0xd4], ECX
    m.w32((s.ax+0x000000d4u), s.cx);
  }
  L006039f7: { // 0x6039f7: 8b15c055a200 MOV EDX, dword ptr [0xa255c0]
    s.dx = m.r32((0x00a255c0u));
  }
  L006039fd: { // 0x6039fd: 8d8a18020000 LEA ECX, [EDX + 0x218]
    s.cx = (s.dx+0x00000218u);
  }
  L00603a03: { // 0x603a03: e8d8c30200 CALL 0x62fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,6306312u); flags=s.arithmetic_flags;
  }
  L00603a08: { // 0x603a08: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00603a09: { // 0x603a09: b906000000 MOV ECX, 6
    s.cx = 6u;
  }
  L00603a0e: { // 0x603a0e: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00603a10: { // 0x603a10: 8a861f010000 MOV AL, byte ptr [ESI + 0x11f]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000011fu)));
  }
  L00603a16: { // 0x603a16: f7da NEG EDX
    s.dx = integer::sub(0u,s.dx,32,flags);
  }
  L00603a18: { // 0x603a18: 1ad2 SBB DL, DL
    s.dx = with_al(s.dx, integer::sub((s.dx & 0xffu),(s.dx & 0xffu),8,flags,flags&integer::CF));
  }
  L00603a1a: { // 0x603a1a: 83e219 AND EDX, 0x19
    s.dx = integer::logical((s.dx)&(0x00000019u),32,flags);
  }
  L00603a1d: { // 0x603a1d: 02d0 ADD DL, AL
    s.dx = with_al(s.dx, integer::add((s.dx & 0xffu),(s.ax & 0xffu),8,flags));
  }
  L00603a1f: { // 0x603a1f: 88971f010000 MOV byte ptr [EDI + 0x11f], DL
    m.w8((s.di+0x0000011fu), (s.dx & 0xffu));
  }
  L00603a25: { // 0x603a25: 8b7c2414 MOV EDI, dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L00603a29: { // 0x603a29: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00603a2b: { // 0x603a2b: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00603a2d: { // 0x603a2d: ff92f0000000 CALL dword ptr [EDX + 0xf0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000000f0u)),6306355u); flags=s.arithmetic_flags;
  }
  L00603a33: { // 0x603a33: 8b5c2428 MOV EBX, dword ptr [ESP + 0x28]
    s.bx = m.r32((f.sp+0x00000028u));
  }
  L00603a37: { // 0x603a37: eb07 JMP 0x603a40
    goto L00603a40;
  }
  L00603a39: { // 0x603a39: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00603a3b: { // 0x603a3b: e8c0e5ffff CALL 0x602000
    s.arithmetic_flags=flags; invoke(m,s,f,0x00602000u,6306368u); flags=s.arithmetic_flags;
  }
  L00603a40: { // 0x603a40: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L00603a41: { // 0x603a41: 895c2428 MOV dword ptr [ESP + 0x28], EBX
    m.w32((f.sp+0x00000028u), s.bx);
  }
  L00603a45: { // 0x603a45: 0f89bafdffff JNS 0x603805
    if(integer::condition("JNS",flags)) goto L00603805;
  }
  L00603a4b: { // 0x603a4b: 8a87e4000000 MOV AL, byte ptr [EDI + 0xe4]
    s.ax = with_al(s.ax, m.r8((s.di+0x000000e4u)));
  }
  L00603a51: { // 0x603a51: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00603a53: { // 0x603a53: 0f859b010000 JNZ 0x603bf4
    if(integer::condition("JNZ",flags)) goto L00603bf4;
  }
  L00603a59: { // 0x603a59: 8a477d MOV AL, byte ptr [EDI + 0x7d]
    s.ax = with_al(s.ax, m.r8((s.di+0x0000007du)));
  }
  L00603a5c: { // 0x603a5c: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00603a5e: { // 0x603a5e: 0f8490010000 JZ 0x603bf4
    if(integer::condition("JZ",flags)) goto L00603bf4;
  }
  L00603a64: { // 0x603a64: d987d4000000 FLD dword ptr [EDI + 0xd4]
    const auto address=(s.di+0x000000d4u);
    s.fp.load32(m.r32(address));
  }
  L00603a6a: { // 0x603a6a: e8e16f1600 CALL 0x76aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6306415u); flags=s.arithmetic_flags;
  }
  L00603a6f: { // 0x603a6f: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L00603a71: { // 0x603a71: a16c89a200 MOV EAX, dword ptr [0xa2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  L00603a76: { // 0x603a76: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00603a77: { // 0x603a77: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00603a79: { // 0x603a79: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00603a7b: { // 0x603a7b: 0f8573010000 JNZ 0x603bf4
    if(integer::condition("JNZ",flags)) goto L00603bf4;
  }
  L00603a81: { // 0x603a81: 8b87cc000000 MOV EAX, dword ptr [EDI + 0xcc]
    s.ax = m.r32((s.di+0x000000ccu));
  }
  L00603a87: { // 0x603a87: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00603a89: { // 0x603a89: 7414 JZ 0x603a9f
    if(integer::condition("JZ",flags)) goto L00603a9f;
  }
  L00603a8b: { // 0x603a8b: f6401404 TEST byte ptr [EAX + 0x14], 4
    (void)integer::logical((m.r8((s.ax+0x00000014u)))&(4u),8,flags);
  }
  L00603a8f: { // 0x603a8f: 740e JZ 0x603a9f
    if(integer::condition("JZ",flags)) goto L00603a9f;
  }
  L00603a91: { // 0x603a91: 8a8874050000 MOV CL, byte ptr [EAX + 0x574]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000574u)));
  }
  L00603a97: { // 0x603a97: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00603a99: { // 0x603a99: 0f8d55010000 JGE 0x603bf4
    if(integer::condition("JGE",flags)) goto L00603bf4;
  }
  L00603a9f: { // 0x603a9f: 8b15c055a200 MOV EDX, dword ptr [0xa255c0]
    s.dx = m.r32((0x00a255c0u));
  }
  L00603aa5: { // 0x603aa5: 8db218020000 LEA ESI, [EDX + 0x218]
    s.si = (s.dx+0x00000218u);
  }
  L00603aab: { // 0x603aab: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00603aad: { // 0x603aad: e82ec30200 CALL 0x62fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,6306482u); flags=s.arithmetic_flags;
  }
  L00603ab2: { // 0x603ab2: 8b9f98000000 MOV EBX, dword ptr [EDI + 0x98]
    s.bx = m.r32((s.di+0x00000098u));
  }
  L00603ab8: { // 0x603ab8: 8944242c MOV dword ptr [ESP + 0x2c], EAX
    m.w32((f.sp+0x0000002cu), s.ax);
  }
  L00603abc: { // 0x603abc: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00603abe: { // 0x603abe: 8b8378020000 MOV EAX, dword ptr [EBX + 0x278]
    s.ax = m.r32((s.bx+0x00000278u));
  }
  L00603ac4: { // 0x603ac4: 8d6801 LEA EBP, [EAX + 1]
    s.bp = (s.ax+1u);
  }
  L00603ac7: { // 0x603ac7: e814c30200 CALL 0x62fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,6306508u); flags=s.arithmetic_flags;
  }
  L00603acc: { // 0x603acc: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00603acd: { // 0x603acd: f7fd IDIV EBP
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.bp,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00603acf: { // 0x603acf: 8b44242c MOV EAX, dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L00603ad3: { // 0x603ad3: 8bca MOV ECX, EDX
    s.cx = s.dx;
  }
  L00603ad5: { // 0x603ad5: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00603ad6: { // 0x603ad6: f7fd IDIV EBP
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.bp,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00603ad8: { // 0x603ad8: 8d8788000000 LEA EAX, [EDI + 0x88]
    s.ax = (s.di+0x00000088u);
  }
  L00603ade: { // 0x603ade: 8be8 MOV EBP, EAX
    s.bp = s.ax;
  }
  L00603ae0: { // 0x603ae0: 8b4500 MOV EAX, dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L00603ae3: { // 0x603ae3: 8b7504 MOV ESI, dword ptr [EBP + 4]
    s.si = m.r32((s.bp+4u));
  }
  L00603ae6: { // 0x603ae6: 03ce ADD ECX, ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L00603ae8: { // 0x603ae8: 8b6d08 MOV EBP, dword ptr [EBP + 8]
    s.bp = m.r32((s.bp+8u));
  }
  L00603aeb: { // 0x603aeb: 894c2440 MOV dword ptr [ESP + 0x40], ECX
    m.w32((f.sp+0x00000040u), s.cx);
  }
  L00603aef: { // 0x603aef: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00603af1: { // 0x603af1: 8d550a LEA EDX, [EBP + 0xa]
    s.dx = (s.bp+0x0000000au);
  }
  L00603af4: { // 0x603af4: 8944243c MOV dword ptr [ESP + 0x3c], EAX
    m.w32((f.sp+0x0000003cu), s.ax);
  }
  L00603af8: { // 0x603af8: 89542444 MOV dword ptr [ESP + 0x44], EDX
    m.w32((f.sp+0x00000044u), s.dx);
  }
  L00603afc: { // 0x603afc: 83bb64020000ff CMP dword ptr [EBX + 0x264], -1
    (void)integer::sub(m.r32((s.bx+0x00000264u)),4294967295u,32,flags);
  }
  L00603b03: { // 0x603b03: 0f84eb000000 JZ 0x603bf4
    if(integer::condition("JZ",flags)) goto L00603bf4;
  }
  L00603b09: { // 0x603b09: 6828010000 PUSH 0x128
    f.push(m,0x00000128u);
  }
  L00603b0e: { // 0x603b0e: e8449e1600 CALL 0x76d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,6306579u); flags=s.arithmetic_flags;
  }
  L00603b13: { // 0x603b13: 83c404 ADD ESP, 4
    f.sp = integer::add(f.sp,4u,32,flags);
  }
  L00603b16: { // 0x603b16: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00603b18: { // 0x603b18: 0f84d6000000 JZ 0x603bf4
    if(integer::condition("JZ",flags)) goto L00603bf4;
  }
  L00603b1e: { // 0x603b1e: 8d8fc0000000 LEA ECX, [EDI + 0xc0]
    s.cx = (s.di+0x000000c0u);
  }
  L00603b24: { // 0x603b24: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00603b25: { // 0x603b25: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00603b26: { // 0x603b26: 8b8f98000000 MOV ECX, dword ptr [EDI + 0x98]
    s.cx = m.r32((s.di+0x00000098u));
  }
  L00603b2c: { // 0x603b2c: 8d542444 LEA EDX, [ESP + 0x44]
    s.dx = (f.sp+0x00000044u);
  }
  L00603b30: { // 0x603b30: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00603b31: { // 0x603b31: 8b9164020000 MOV EDX, dword ptr [ECX + 0x264]
    s.dx = m.r32((s.cx+0x00000264u));
  }
  L00603b37: { // 0x603b37: 8b0d34e1a100 MOV ECX, dword ptr [0xa1e134]
    s.cx = m.r32((0x00a1e134u));
  }
  L00603b3d: { // 0x603b3d: 8b1491 MOV EDX, dword ptr [ECX + EDX*4]
    s.dx = m.r32((s.cx+(s.dx * 4u)));
  }
  L00603b40: { // 0x603b40: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L00603b42: { // 0x603b42: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00603b43: { // 0x603b43: e8d8c4ffff CALL 0x600020
    s.arithmetic_flags=flags; invoke(m,s,f,0x00600020u,6306632u); flags=s.arithmetic_flags;
  }
  L00603b48: { // 0x603b48: 8bd8 MOV EBX, EAX
    s.bx = s.ax;
  }
  L00603b4a: { // 0x603b4a: 85db TEST EBX, EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L00603b4c: { // 0x603b4c: 0f84a2000000 JZ 0x603bf4
    if(integer::condition("JZ",flags)) goto L00603bf4;
  }
  L00603b52: { // 0x603b52: 8b8fb0000000 MOV ECX, dword ptr [EDI + 0xb0]
    s.cx = m.r32((s.di+0x000000b0u));
  }
  L00603b58: { // 0x603b58: 8b87b8000000 MOV EAX, dword ptr [EDI + 0xb8]
    s.ax = m.r32((s.di+0x000000b8u));
  }
  L00603b5e: { // 0x603b5e: 8db7a8000000 LEA ESI, [EDI + 0xa8]
    s.si = (s.di+0x000000a8u);
  }
  L00603b64: { // 0x603b64: 3bc1 CMP EAX, ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00603b66: { // 0x603b66: 7c22 JL 0x603b8a
    if(integer::condition("JL",flags)) goto L00603b8a;
  }
  L00603b68: { // 0x603b68: 8a460d MOV AL, byte ptr [ESI + 0xd]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000000du)));
  }
  L00603b6b: { // 0x603b6b: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00603b6d: { // 0x603b6d: 7504 JNZ 0x603b73
    if(integer::condition("JNZ",flags)) goto L00603b73;
  }
  L00603b6f: { // 0x603b6f: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00603b71: { // 0x603b71: 7526 JNZ 0x603b99
    if(integer::condition("JNZ",flags)) goto L00603b99;
  }
  L00603b73: { // 0x603b73: 8b4614 MOV EAX, dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  L00603b76: { // 0x603b76: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00603b78: { // 0x603b78: 7e1f JLE 0x603b99
    if(integer::condition("JLE",flags)) goto L00603b99;
  }
  L00603b7a: { // 0x603b7a: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00603b7c: { // 0x603b7c: 03c1 ADD EAX, ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00603b7e: { // 0x603b7e: 6a00 PUSH 0
    f.push(m,0u);
  }
  L00603b80: { // 0x603b80: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00603b81: { // 0x603b81: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00603b83: { // 0x603b83: ff5208 CALL dword ptr [EDX + 8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+8u)),6306694u); flags=s.arithmetic_flags;
  }
  L00603b86: { // 0x603b86: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00603b88: { // 0x603b88: 740f JZ 0x603b99
    if(integer::condition("JZ",flags)) goto L00603b99;
  }
  L00603b8a: { // 0x603b8a: 8b4610 MOV EAX, dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L00603b8d: { // 0x603b8d: 8b5604 MOV EDX, dword ptr [ESI + 4]
    s.dx = m.r32((s.si+4u));
  }
  L00603b90: { // 0x603b90: 8d4801 LEA ECX, [EAX + 1]
    s.cx = (s.ax+1u);
  }
  L00603b93: { // 0x603b93: 894e10 MOV dword ptr [ESI + 0x10], ECX
    m.w32((s.si+0x00000010u), s.cx);
  }
  L00603b96: { // 0x603b96: 891c82 MOV dword ptr [EDX + EAX*4], EBX
    m.w32((s.dx+(s.ax * 4u)), s.bx);
  }
  L00603b99: { // 0x603b99: 8b8798000000 MOV EAX, dword ptr [EDI + 0x98]
    s.ax = m.r32((s.di+0x00000098u));
  }
  L00603b9f: { // 0x603b9f: d987d4000000 FLD dword ptr [EDI + 0xd4]
    const auto address=(s.di+0x000000d4u);
    s.fp.load32(m.r32(address));
  }
  L00603ba5: { // 0x603ba5: d89880020000 FCOMP dword ptr [EAX + 0x280]
    const auto address=(s.ax+0x00000280u);
    s.fp.compare_pop32(m.r32(address));
  }
  L00603bab: { // 0x603bab: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00603bad: { // 0x603bad: f6c441 TEST AH, 0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L00603bb0: { // 0x603bb0: 7507 JNZ 0x603bb9
    if(integer::condition("JNZ",flags)) goto L00603bb9;
  }
  L00603bb2: { // 0x603bb2: 80831f01000019 ADD byte ptr [EBX + 0x11f], 0x19
    m.w8((s.bx+0x0000011fu), integer::add(m.r8((s.bx+0x0000011fu)),0x00000019u,8,flags));
  }
  L00603bb9: { // 0x603bb9: 8b8f98000000 MOV ECX, dword ptr [EDI + 0x98]
    s.cx = m.r32((s.di+0x00000098u));
  }
  L00603bbf: { // 0x603bbf: db816c020000 FILD dword ptr [ECX + 0x26c]
    const auto address=(s.cx+0x0000026cu);
    s.fp.load_integer32(m.r32(address));
  }
  L00603bc5: { // 0x603bc5: d8afd4000000 FSUBR dword ptr [EDI + 0xd4]
    const auto address=(s.di+0x000000d4u);
    ra2::platform::x87_b61::reverse_subtract32(s.fp,m.r32(address));
  }
  L00603bcb: { // 0x603bcb: d80d002f7900 FMUL dword ptr [0x792f00]
    const auto address=(0x00792f00u);
    s.fp.multiply32(m.r32(address));
  }
  L00603bd1: { // 0x603bd1: d8abd4000000 FSUBR dword ptr [EBX + 0xd4]
    const auto address=(s.bx+0x000000d4u);
    ra2::platform::x87_b61::reverse_subtract32(s.fp,m.r32(address));
  }
  L00603bd7: { // 0x603bd7: d993d4000000 FST dword ptr [EBX + 0xd4]
    const auto address=(s.bx+0x000000d4u);
    const auto value=s.fp.store32();
    m.w32(address,value);
  }
  L00603bdd: { // 0x603bdd: dc1df8567800 FCOMP qword ptr [0x7856f8]
    const auto address=(0x007856f8u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00603be3: { // 0x603be3: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00603be5: { // 0x603be5: f6c401 TEST AH, 1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(1u),8,flags);
  }
  L00603be8: { // 0x603be8: 740a JZ 0x603bf4
    if(integer::condition("JZ",flags)) goto L00603bf4;
  }
  L00603bea: { // 0x603bea: c783d400000000000040 MOV dword ptr [EBX + 0xd4], 0x40000000
    m.w32((s.bx+0x000000d4u), 0x40000000u);
  }
  L00603bf4: { // 0x603bf4: 8b8798000000 MOV EAX, dword ptr [EDI + 0x98]
    s.ax = m.r32((s.di+0x00000098u));
  }
  L00603bfa: { // 0x603bfa: d98070020000 FLD dword ptr [EAX + 0x270]
    const auto address=(s.ax+0x00000270u);
    s.fp.load32(m.r32(address));
  }
  L00603c00: { // 0x603c00: d887d4000000 FADD dword ptr [EDI + 0xd4]
    const auto address=(s.di+0x000000d4u);
    s.fp.add32(m.r32(address));
  }
  L00603c06: { // 0x603c06: d997d4000000 FST dword ptr [EDI + 0xd4]
    const auto address=(s.di+0x000000d4u);
    const auto value=s.fp.store32();
    m.w32(address,value);
  }
  L00603c0c: { // 0x603c0c: d8987c020000 FCOMP dword ptr [EAX + 0x27c]
    const auto address=(s.ax+0x0000027cu);
    s.fp.compare_pop32(m.r32(address));
  }
  L00603c12: { // 0x603c12: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00603c14: { // 0x603c14: f6c441 TEST AH, 0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L00603c17: { // 0x603c17: 7507 JNZ 0x603c20
    if(integer::condition("JNZ",flags)) goto L00603c20;
  }
  L00603c19: { // 0x603c19: c687e400000001 MOV byte ptr [EDI + 0xe4], 1
    m.w8((s.di+0x000000e4u), 1u);
  }
  L00603c20: { // 0x603c20: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00603c21: { // 0x603c21: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00603c22: { // 0x603c22: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00603c23: { // 0x603c23: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00603c24: { // 0x603c24: 83c444 ADD ESP, 0x44
    f.sp = integer::add(f.sp,0x00000044u,32,flags);
  }
  L00603c27: { // 0x603c27: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 6303936u:f_002030c0(m,s,child,{});break;
case 6487616u:f_0022fe40(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
case 6084688u:f_001cd850(m,s,child,{});break;
case 6295008u:f_00200de0(m,s,child,{});break;
case 6297712u:f_00201870(m,s,child,{});break;
case 6299648u:f_00202000(m,s,child,{});break;
case 6305616u:f_00203750(m,s,child,{});break;
default:throw std::domain_error("recovery824 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_006030c0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006030c0: { // 0x6030c0: 83ec14 SUB ESP, 0x14
    f.sp = integer::sub(f.sp,0x00000014u,32,flags);
  }
  L006030c3: { // 0x6030c3: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006030c4: { // 0x6030c4: 8be9 MOV EBP, ECX
    s.bp = s.cx;
  }
  L006030c6: { // 0x6030c6: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006030c7: { // 0x6030c7: 896c2408 MOV dword ptr [ESP + 8], EBP
    m.w32((f.sp+8u), s.bp);
  }
  L006030cb: { // 0x6030cb: 8bb5b8000000 MOV ESI, dword ptr [EBP + 0xb8]
    s.si = m.r32((s.bp+0x000000b8u));
  }
  L006030d1: { // 0x6030d1: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L006030d2: { // 0x6030d2: 7811 JS 0x6030e5
    if(integer::condition("JS",flags)) goto L006030e5;
  }
  L006030d4: { // 0x6030d4: 8b85ac000000 MOV EAX, dword ptr [EBP + 0xac]
    s.ax = m.r32((s.bp+0x000000acu));
  }
  L006030da: { // 0x6030da: 8b0cb0 MOV ECX, dword ptr [EAX + ESI*4]
    s.cx = m.r32((s.ax+(s.si * 4u)));
  }
  L006030dd: { // 0x6030dd: e88ee7ffff CALL 0x601870
    s.arithmetic_flags=flags; invoke(m,s,f,0x00601870u,6303970u); flags=s.arithmetic_flags;
  }
  L006030e2: { // 0x6030e2: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L006030e3: { // 0x6030e3: 79ef JNS 0x6030d4
    if(integer::condition("JNS",flags)) goto L006030d4;
  }
  L006030e5: { // 0x6030e5: 8bb5b8000000 MOV ESI, dword ptr [EBP + 0xb8]
    s.si = m.r32((s.bp+0x000000b8u));
  }
  L006030eb: { // 0x6030eb: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L006030ec: { // 0x6030ec: 8974240c MOV dword ptr [ESP + 0xc], ESI
    m.w32((f.sp+0x0000000cu), s.si);
  }
  L006030f0: { // 0x6030f0: 0f884a010000 JS 0x603240
    if(integer::condition("JS",flags)) goto L00603240;
  }
  L006030f6: { // 0x6030f6: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006030f7: { // 0x6030f7: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006030f8: { // 0x6030f8: 8b8dac000000 MOV ECX, dword ptr [EBP + 0xac]
    s.cx = m.r32((s.bp+0x000000acu));
  }
  L006030fe: { // 0x6030fe: 8b1cb1 MOV EBX, dword ptr [ECX + ESI*4]
    s.bx = m.r32((s.cx+(s.si * 4u)));
  }
  L00603101: { // 0x603101: 8a8321010000 MOV AL, byte ptr [EBX + 0x121]
    s.ax = with_al(s.ax, m.r8((s.bx+0x00000121u)));
  }
  L00603107: { // 0x603107: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00603109: { // 0x603109: 0f841d010000 JZ 0x60322c
    if(integer::condition("JZ",flags)) goto L0060322c;
  }
  L0060310f: { // 0x60310f: 8b9398000000 MOV EDX, dword ptr [EBX + 0x98]
    s.dx = m.r32((s.bx+0x00000098u));
  }
  L00603115: { // 0x603115: 8b82e0020000 MOV EAX, dword ptr [EDX + 0x2e0]
    s.ax = m.r32((s.dx+0x000002e0u));
  }
  L0060311b: { // 0x60311b: 83f8ff CMP EAX, -1
    (void)integer::sub(s.ax,4294967295u,32,flags);
  }
  L0060311e: { // 0x60311e: 0f84f8000000 JZ 0x60321c
    if(integer::condition("JZ",flags)) goto L0060321c;
  }
  L00603124: { // 0x603124: 8b2d34e1a100 MOV EBP, dword ptr [0xa1e134]
    s.bp = m.r32((0x00a1e134u));
  }
  L0060312a: { // 0x60312a: 8d8b88000000 LEA ECX, [EBX + 0x88]
    s.cx = (s.bx+0x00000088u);
  }
  L00603130: { // 0x603130: 8bf9 MOV EDI, ECX
    s.di = s.cx;
  }
  L00603132: { // 0x603132: 6828010000 PUSH 0x128
    f.push(m,0x00000128u);
  }
  L00603137: { // 0x603137: 8b6c8500 MOV EBP, dword ptr [EBP + EAX*4]
    s.bp = m.r32((s.bp+(s.ax * 4u)));
  }
  L0060313b: { // 0x60313b: 8b8264020000 MOV EAX, dword ptr [EDX + 0x264]
    s.ax = m.r32((s.dx+0x00000264u));
  }
  L00603141: { // 0x603141: 8b0f MOV ECX, dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  L00603143: { // 0x603143: 03c1 ADD EAX, ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00603145: { // 0x603145: 8b8a68020000 MOV ECX, dword ptr [EDX + 0x268]
    s.cx = m.r32((s.dx+0x00000268u));
  }
  L0060314b: { // 0x60314b: 8b7704 MOV ESI, dword ptr [EDI + 4]
    s.si = m.r32((s.di+4u));
  }
  L0060314e: { // 0x60314e: 8b926c020000 MOV EDX, dword ptr [EDX + 0x26c]
    s.dx = m.r32((s.dx+0x0000026cu));
  }
  L00603154: { // 0x603154: 03ce ADD ECX, ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L00603156: { // 0x603156: 8944241c MOV dword ptr [ESP + 0x1c], EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0060315a: { // 0x60315a: 8b7f08 MOV EDI, dword ptr [EDI + 8]
    s.di = m.r32((s.di+8u));
  }
  L0060315d: { // 0x60315d: 894c2420 MOV dword ptr [ESP + 0x20], ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L00603161: { // 0x603161: 03d7 ADD EDX, EDI
    s.dx = integer::add(s.dx,s.di,32,flags);
  }
  L00603163: { // 0x603163: 89542424 MOV dword ptr [ESP + 0x24], EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L00603167: { // 0x603167: e8eba71600 CALL 0x76d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,6304108u); flags=s.arithmetic_flags;
  }
  L0060316c: { // 0x60316c: 83c404 ADD ESP, 4
    f.sp = integer::add(f.sp,4u,32,flags);
  }
  L0060316f: { // 0x60316f: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00603171: { // 0x603171: 0f84a1000000 JZ 0x603218
    if(integer::condition("JZ",flags)) goto L00603218;
  }
  L00603177: { // 0x603177: 6a00 PUSH 0
    f.push(m,0u);
  }
  L00603179: { // 0x603179: 8d54241c LEA EDX, [ESP + 0x1c]
    s.dx = (f.sp+0x0000001cu);
  }
  L0060317d: { // 0x60317d: 68c0e0a500 PUSH 0xa5e0c0
    f.push(m,0x00a5e0c0u);
  }
  L00603182: { // 0x603182: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00603183: { // 0x603183: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00603184: { // 0x603184: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L00603186: { // 0x603186: e895ceffff CALL 0x600020
    s.arithmetic_flags=flags; invoke(m,s,f,0x00600020u,6304139u); flags=s.arithmetic_flags;
  }
  L0060318b: { // 0x60318b: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L0060318d: { // 0x60318d: 85ff TEST EDI, EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0060318f: { // 0x60318f: 0f8483000000 JZ 0x603218
    if(integer::condition("JZ",flags)) goto L00603218;
  }
  L00603195: { // 0x603195: 8b6c2410 MOV EBP, dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L00603199: { // 0x603199: 8b8db0000000 MOV ECX, dword ptr [EBP + 0xb0]
    s.cx = m.r32((s.bp+0x000000b0u));
  }
  L0060319f: { // 0x60319f: 8b85b8000000 MOV EAX, dword ptr [EBP + 0xb8]
    s.ax = m.r32((s.bp+0x000000b8u));
  }
  L006031a5: { // 0x6031a5: 8db5a8000000 LEA ESI, [EBP + 0xa8]
    s.si = (s.bp+0x000000a8u);
  }
  L006031ab: { // 0x6031ab: 3bc1 CMP EAX, ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L006031ad: { // 0x6031ad: 7c22 JL 0x6031d1
    if(integer::condition("JL",flags)) goto L006031d1;
  }
  L006031af: { // 0x6031af: 8a460d MOV AL, byte ptr [ESI + 0xd]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000000du)));
  }
  L006031b2: { // 0x6031b2: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006031b4: { // 0x6031b4: 7504 JNZ 0x6031ba
    if(integer::condition("JNZ",flags)) goto L006031ba;
  }
  L006031b6: { // 0x6031b6: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006031b8: { // 0x6031b8: 7526 JNZ 0x6031e0
    if(integer::condition("JNZ",flags)) goto L006031e0;
  }
  L006031ba: { // 0x6031ba: 8b4614 MOV EAX, dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  L006031bd: { // 0x6031bd: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006031bf: { // 0x6031bf: 7e1f JLE 0x6031e0
    if(integer::condition("JLE",flags)) goto L006031e0;
  }
  L006031c1: { // 0x6031c1: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006031c3: { // 0x6031c3: 03c1 ADD EAX, ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L006031c5: { // 0x6031c5: 6a00 PUSH 0
    f.push(m,0u);
  }
  L006031c7: { // 0x6031c7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006031c8: { // 0x6031c8: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006031ca: { // 0x6031ca: ff5208 CALL dword ptr [EDX + 8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+8u)),6304205u); flags=s.arithmetic_flags;
  }
  L006031cd: { // 0x6031cd: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006031cf: { // 0x6031cf: 740f JZ 0x6031e0
    if(integer::condition("JZ",flags)) goto L006031e0;
  }
  L006031d1: { // 0x6031d1: 8b4610 MOV EAX, dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L006031d4: { // 0x6031d4: 8b5604 MOV EDX, dword ptr [ESI + 4]
    s.dx = m.r32((s.si+4u));
  }
  L006031d7: { // 0x6031d7: 8d4801 LEA ECX, [EAX + 1]
    s.cx = (s.ax+1u);
  }
  L006031da: { // 0x6031da: 894e10 MOV dword ptr [ESI + 0x10], ECX
    m.w32((s.si+0x00000010u), s.cx);
  }
  L006031dd: { // 0x6031dd: 893c82 MOV dword ptr [EDX + EAX*4], EDI
    m.w32((s.dx+(s.ax * 4u)), s.di);
  }
  L006031e0: { // 0x6031e0: 8b83d4000000 MOV EAX, dword ptr [EBX + 0xd4]
    s.ax = m.r32((s.bx+0x000000d4u));
  }
  L006031e6: { // 0x6031e6: 8d8bb0000000 LEA ECX, [EBX + 0xb0]
    s.cx = (s.bx+0x000000b0u);
  }
  L006031ec: { // 0x6031ec: 8987d4000000 MOV dword ptr [EDI + 0xd4], EAX
    m.w32((s.di+0x000000d4u), s.ax);
  }
  L006031f2: { // 0x6031f2: 81c7b0000000 ADD EDI, 0xb0
    s.di = integer::add(s.di,0x000000b0u,32,flags);
  }
  L006031f8: { // 0x6031f8: 8b11 MOV EDX, dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L006031fa: { // 0x6031fa: 8917 MOV dword ptr [EDI], EDX
    m.w32((s.di), s.dx);
  }
  L006031fc: { // 0x6031fc: 8b4104 MOV EAX, dword ptr [ECX + 4]
    s.ax = m.r32((s.cx+4u));
  }
  L006031ff: { // 0x6031ff: 894704 MOV dword ptr [EDI + 4], EAX
    m.w32((s.di+4u), s.ax);
  }
  L00603202: { // 0x603202: 8b4908 MOV ECX, dword ptr [ECX + 8]
    s.cx = m.r32((s.cx+8u));
  }
  L00603205: { // 0x603205: 894f08 MOV dword ptr [EDI + 8], ECX
    m.w32((s.di+8u), s.cx);
  }
  L00603208: { // 0x603208: 8b13 MOV EDX, dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L0060320a: { // 0x60320a: 8bcb MOV ECX, EBX
    s.cx = s.bx;
  }
  L0060320c: { // 0x60320c: ff92f0000000 CALL dword ptr [EDX + 0xf0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000000f0u)),6304274u); flags=s.arithmetic_flags;
  }
  L00603212: { // 0x603212: 8b742414 MOV ESI, dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L00603216: { // 0x603216: eb1b JMP 0x603233
    goto L00603233;
  }
  L00603218: { // 0x603218: 8b6c2410 MOV EBP, dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L0060321c: { // 0x60321c: 8b13 MOV EDX, dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L0060321e: { // 0x60321e: 8bcb MOV ECX, EBX
    s.cx = s.bx;
  }
  L00603220: { // 0x603220: ff92f0000000 CALL dword ptr [EDX + 0xf0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000000f0u)),6304294u); flags=s.arithmetic_flags;
  }
  L00603226: { // 0x603226: 8b742414 MOV ESI, dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L0060322a: { // 0x60322a: eb07 JMP 0x603233
    goto L00603233;
  }
  L0060322c: { // 0x60322c: 8bcb MOV ECX, EBX
    s.cx = s.bx;
  }
  L0060322e: { // 0x60322e: e8cdedffff CALL 0x602000
    s.arithmetic_flags=flags; invoke(m,s,f,0x00602000u,6304307u); flags=s.arithmetic_flags;
  }
  L00603233: { // 0x603233: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L00603234: { // 0x603234: 89742414 MOV dword ptr [ESP + 0x14], ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L00603238: { // 0x603238: 0f89bafeffff JNS 0x6030f8
    if(integer::condition("JNS",flags)) goto L006030f8;
  }
  L0060323e: { // 0x60323e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0060323f: { // 0x60323f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00603240: { // 0x603240: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00603241: { // 0x603241: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00603242: { // 0x603242: 83c414 ADD ESP, 0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L00603245: { // 0x603245: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00603750(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00603750: { // 0x603750: 83ec44 SUB ESP, 0x44
    f.sp = integer::sub(f.sp,0x00000044u,32,flags);
  }
  L00603753: { // 0x603753: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00603754: { // 0x603754: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00603755: { // 0x603755: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00603756: { // 0x603756: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00603757: { // 0x603757: 8bf9 MOV EDI, ECX
    s.di = s.cx;
  }
  L00603759: { // 0x603759: 897c2414 MOV dword ptr [ESP + 0x14], EDI
    m.w32((f.sp+0x00000014u), s.di);
  }
  L0060375d: { // 0x60375d: 8b87cc000000 MOV EAX, dword ptr [EDI + 0xcc]
    s.ax = m.r32((s.di+0x000000ccu));
  }
  L00603763: { // 0x603763: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00603765: { // 0x603765: 7468 JZ 0x6037cf
    if(integer::condition("JZ",flags)) goto L006037cf;
  }
  L00603767: { // 0x603767: 8a4814 MOV CL, byte ptr [EAX + 0x14]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000014u)));
  }
  L0060376a: { // 0x60376a: d0e9 SHR CL, 1
    s.cx = with_al(s.cx, integer::shift((s.cx & 0xffu),1u,8,flags,integer::Shift::right));
  }
  L0060376c: { // 0x60376c: 80e101 AND CL, 1
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))&(1u),8,flags));
  }
  L0060376f: { // 0x60376f: 884c2413 MOV byte ptr [ESP + 0x13], CL
    m.w8((f.sp+0x00000013u), (s.cx & 0xffu));
  }
  L00603773: { // 0x603773: 745a JZ 0x6037cf
    if(integer::condition("JZ",flags)) goto L006037cf;
  }
  L00603775: { // 0x603775: 8b5004 MOV EDX, dword ptr [EAX + 4]
    s.dx = m.r32((s.ax+4u));
  }
  L00603778: { // 0x603778: 83c004 ADD EAX, 4
    s.ax = integer::add(s.ax,4u,32,flags);
  }
  L0060377b: { // 0x60377b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0060377c: { // 0x60377c: ff520c CALL dword ptr [EDX + 0xc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000000cu)),6305663u); flags=s.arithmetic_flags;
  }
  L0060377f: { // 0x60377f: 83f806 CMP EAX, 6
    (void)integer::sub(s.ax,6u,32,flags);
  }
  L00603782: { // 0x603782: 744b JZ 0x6037cf
    if(integer::condition("JZ",flags)) goto L006037cf;
  }
  L00603784: { // 0x603784: 8b8fcc000000 MOV ECX, dword ptr [EDI + 0xcc]
    s.cx = m.r32((s.di+0x000000ccu));
  }
  L0060378a: { // 0x60378a: 8d542448 LEA EDX, [ESP + 0x48]
    s.dx = (f.sp+0x00000048u);
  }
  L0060378e: { // 0x60378e: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0060378f: { // 0x60378f: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00603791: { // 0x603791: ff5048 CALL dword ptr [EAX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000048u)),6305684u); flags=s.arithmetic_flags;
  }
  L00603794: { // 0x603794: 8b8f9c000000 MOV ECX, dword ptr [EDI + 0x9c]
    s.cx = m.r32((s.di+0x0000009cu));
  }
  L0060379a: { // 0x60379a: 8b10 MOV EDX, dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0060379c: { // 0x60379c: 8b6804 MOV EBP, dword ptr [EAX + 4]
    s.bp = m.r32((s.ax+4u));
  }
  L0060379f: { // 0x60379f: 8b5808 MOV EBX, dword ptr [EAX + 8]
    s.bx = m.r32((s.ax+8u));
  }
  L006037a2: { // 0x6037a2: 8bb7a4000000 MOV ESI, dword ptr [EDI + 0xa4]
    s.si = m.r32((s.di+0x000000a4u));
  }
  L006037a8: { // 0x6037a8: 8b07 MOV EAX, dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L006037aa: { // 0x6037aa: 03ca ADD ECX, EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L006037ac: { // 0x6037ac: 8b97a0000000 MOV EDX, dword ptr [EDI + 0xa0]
    s.dx = m.r32((s.di+0x000000a0u));
  }
  L006037b2: { // 0x6037b2: 894c2430 MOV dword ptr [ESP + 0x30], ECX
    m.w32((f.sp+0x00000030u), s.cx);
  }
  L006037b6: { // 0x6037b6: 8d4c2430 LEA ECX, [ESP + 0x30]
    s.cx = (f.sp+0x00000030u);
  }
  L006037ba: { // 0x6037ba: 03d5 ADD EDX, EBP
    s.dx = integer::add(s.dx,s.bp,32,flags);
  }
  L006037bc: { // 0x6037bc: 03f3 ADD ESI, EBX
    s.si = integer::add(s.si,s.bx,32,flags);
  }
  L006037be: { // 0x6037be: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006037bf: { // 0x6037bf: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L006037c1: { // 0x6037c1: 89542438 MOV dword ptr [ESP + 0x38], EDX
    m.w32((f.sp+0x00000038u), s.dx);
  }
  L006037c5: { // 0x6037c5: 8974243c MOV dword ptr [ESP + 0x3c], ESI
    m.w32((f.sp+0x0000003cu), s.si);
  }
  L006037c9: { // 0x6037c9: ff909c010000 CALL dword ptr [EAX + 0x19c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000019cu)),6305743u); flags=s.arithmetic_flags;
  }
  L006037cf: { // 0x6037cf: 8b87b8000000 MOV EAX, dword ptr [EDI + 0xb8]
    s.ax = m.r32((s.di+0x000000b8u));
  }
  L006037d5: { // 0x6037d5: 33f6 XOR ESI, ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L006037d7: { // 0x6037d7: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006037d9: { // 0x6037d9: 7e19 JLE 0x6037f4
    if(integer::condition("JLE",flags)) goto L006037f4;
  }
  L006037db: { // 0x6037db: 8b97ac000000 MOV EDX, dword ptr [EDI + 0xac]
    s.dx = m.r32((s.di+0x000000acu));
  }
  L006037e1: { // 0x6037e1: 8b0cb2 MOV ECX, dword ptr [EDX + ESI*4]
    s.cx = m.r32((s.dx+(s.si * 4u)));
  }
  L006037e4: { // 0x6037e4: e887e0ffff CALL 0x601870
    s.arithmetic_flags=flags; invoke(m,s,f,0x00601870u,6305769u); flags=s.arithmetic_flags;
  }
  L006037e9: { // 0x6037e9: 8b87b8000000 MOV EAX, dword ptr [EDI + 0xb8]
    s.ax = m.r32((s.di+0x000000b8u));
  }
  L006037ef: { // 0x6037ef: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L006037f0: { // 0x6037f0: 3bf0 CMP ESI, EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L006037f2: { // 0x6037f2: 7ce7 JL 0x6037db
    if(integer::condition("JL",flags)) goto L006037db;
  }
  L006037f4: { // 0x6037f4: 8b9fb8000000 MOV EBX, dword ptr [EDI + 0xb8]
    s.bx = m.r32((s.di+0x000000b8u));
  }
  L006037fa: { // 0x6037fa: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L006037fb: { // 0x6037fb: 895c2428 MOV dword ptr [ESP + 0x28], EBX
    m.w32((f.sp+0x00000028u), s.bx);
  }
  L006037ff: { // 0x6037ff: 0f8846020000 JS 0x603a4b
    if(integer::condition("JS",flags)) goto L00603a4b;
  }
  L00603805: { // 0x603805: 8b87ac000000 MOV EAX, dword ptr [EDI + 0xac]
    s.ax = m.r32((s.di+0x000000acu));
  }
  L0060380b: { // 0x60380b: 8b3498 MOV ESI, dword ptr [EAX + EBX*4]
    s.si = m.r32((s.ax+(s.bx * 4u)));
  }
  L0060380e: { // 0x60380e: 8a8621010000 MOV AL, byte ptr [ESI + 0x121]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000121u)));
  }
  L00603814: { // 0x603814: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00603816: { // 0x603816: 0f841d020000 JZ 0x603a39
    if(integer::condition("JZ",flags)) goto L00603a39;
  }
  L0060381c: { // 0x60381c: 8b8e98000000 MOV ECX, dword ptr [ESI + 0x98]
    s.cx = m.r32((s.si+0x00000098u));
  }
  L00603822: { // 0x603822: 83b9e0020000ff CMP dword ptr [ECX + 0x2e0], -1
    (void)integer::sub(m.r32((s.cx+0x000002e0u)),4294967295u,32,flags);
  }
  L00603829: { // 0x603829: 0f84fa010000 JZ 0x603a29
    if(integer::condition("JZ",flags)) goto L00603a29;
  }
  L0060382f: { // 0x60382f: 8d9688000000 LEA EDX, [ESI + 0x88]
    s.dx = (s.si+0x00000088u);
  }
  L00603835: { // 0x603835: 8b0dc055a200 MOV ECX, dword ptr [0xa255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L0060383b: { // 0x60383b: 81c118020000 ADD ECX, 0x218
    s.cx = integer::add(s.cx,0x00000218u,32,flags);
  }
  L00603841: { // 0x603841: 8b3a MOV EDI, dword ptr [EDX]
    s.di = m.r32((s.dx));
  }
  L00603843: { // 0x603843: 8b6a04 MOV EBP, dword ptr [EDX + 4]
    s.bp = m.r32((s.dx+4u));
  }
  L00603846: { // 0x603846: 8b4208 MOV EAX, dword ptr [EDX + 8]
    s.ax = m.r32((s.dx+8u));
  }
  L00603849: { // 0x603849: 8b9698000000 MOV EDX, dword ptr [ESI + 0x98]
    s.dx = m.r32((s.si+0x00000098u));
  }
  L0060384f: { // 0x60384f: 89442450 MOV dword ptr [ESP + 0x50], EAX
    m.w32((f.sp+0x00000050u), s.ax);
  }
  L00603853: { // 0x603853: 8b9ad4020000 MOV EBX, dword ptr [EDX + 0x2d4]
    s.bx = m.r32((s.dx+0x000002d4u));
  }
  L00603859: { // 0x603859: c1fb03 SAR EBX, 3
    s.bx = integer::shift(s.bx,3u,32,flags,integer::Shift::arithmetic_right);
  }
  L0060385c: { // 0x60385c: e87fc50200 CALL 0x62fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,6305889u); flags=s.arithmetic_flags;
  }
  L00603861: { // 0x603861: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00603862: { // 0x603862: f7fb IDIV EBX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.bx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00603864: { // 0x603864: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00603866: { // 0x603866: 7f04 JG 0x60386c
    if(integer::condition("JG",flags)) goto L0060386c;
  }
  L00603868: { // 0x603868: 2bd3 SUB EDX, EBX
    s.dx = integer::sub(s.dx,s.bx,32,flags);
  }
  L0060386a: { // 0x60386a: eb02 JMP 0x60386e
    goto L0060386e;
  }
  L0060386c: { // 0x60386c: 03d3 ADD EDX, EBX
    s.dx = integer::add(s.dx,s.bx,32,flags);
  }
  L0060386e: { // 0x60386e: a1c055a200 MOV EAX, dword ptr [0xa255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  L00603873: { // 0x603873: 8954241c MOV dword ptr [ESP + 0x1c], EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L00603877: { // 0x603877: 8d8818020000 LEA ECX, [EAX + 0x218]
    s.cx = (s.ax+0x00000218u);
  }
  L0060387d: { // 0x60387d: 8b8698000000 MOV EAX, dword ptr [ESI + 0x98]
    s.ax = m.r32((s.si+0x00000098u));
  }
  L00603883: { // 0x603883: 8944242c MOV dword ptr [ESP + 0x2c], EAX
    m.w32((f.sp+0x0000002cu), s.ax);
  }
  L00603887: { // 0x603887: 8b98d4020000 MOV EBX, dword ptr [EAX + 0x2d4]
    s.bx = m.r32((s.ax+0x000002d4u));
  }
  L0060388d: { // 0x60388d: c1fb03 SAR EBX, 3
    s.bx = integer::shift(s.bx,3u,32,flags,integer::Shift::arithmetic_right);
  }
  L00603890: { // 0x603890: 895c2424 MOV dword ptr [ESP + 0x24], EBX
    m.w32((f.sp+0x00000024u), s.bx);
  }
  L00603894: { // 0x603894: e847c50200 CALL 0x62fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,6305945u); flags=s.arithmetic_flags;
  }
  L00603899: { // 0x603899: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0060389a: { // 0x60389a: f7fb IDIV EBX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.bx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L0060389c: { // 0x60389c: 8b442424 MOV EAX, dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L006038a0: { // 0x6038a0: 8bda MOV EBX, EDX
    s.bx = s.dx;
  }
  L006038a2: { // 0x6038a2: 85db TEST EBX, EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L006038a4: { // 0x6038a4: 7f04 JG 0x6038aa
    if(integer::condition("JG",flags)) goto L006038aa;
  }
  L006038a6: { // 0x6038a6: 2bd8 SUB EBX, EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L006038a8: { // 0x6038a8: eb02 JMP 0x6038ac
    goto L006038ac;
  }
  L006038aa: { // 0x6038aa: 03d8 ADD EBX, EAX
    s.bx = integer::add(s.bx,s.ax,32,flags);
  }
  L006038ac: { // 0x6038ac: 8b4c242c MOV ECX, dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L006038b0: { // 0x6038b0: a134e1a100 MOV EAX, dword ptr [0xa1e134]
    s.ax = m.r32((0x00a1e134u));
  }
  L006038b5: { // 0x6038b5: 6828010000 PUSH 0x128
    f.push(m,0x00000128u);
  }
  L006038ba: { // 0x6038ba: 8b91e0020000 MOV EDX, dword ptr [ECX + 0x2e0]
    s.dx = m.r32((s.cx+0x000002e0u));
  }
  L006038c0: { // 0x6038c0: 8b0c90 MOV ECX, dword ptr [EAX + EDX*4]
    s.cx = m.r32((s.ax+(s.dx * 4u)));
  }
  L006038c3: { // 0x6038c3: 8b542420 MOV EDX, dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L006038c7: { // 0x6038c7: 894c2428 MOV dword ptr [ESP + 0x28], ECX
    m.w32((f.sp+0x00000028u), s.cx);
  }
  L006038cb: { // 0x6038cb: 8d0c2b LEA ECX, [EBX + EBP]
    s.cx = (s.bx+s.bp);
  }
  L006038ce: { // 0x6038ce: 8d0417 LEA EAX, [EDI + EDX]
    s.ax = (s.di+s.dx);
  }
  L006038d1: { // 0x6038d1: 894c2438 MOV dword ptr [ESP + 0x38], ECX
    m.w32((f.sp+0x00000038u), s.cx);
  }
  L006038d5: { // 0x6038d5: 89442434 MOV dword ptr [ESP + 0x34], EAX
    m.w32((f.sp+0x00000034u), s.ax);
  }
  L006038d9: { // 0x6038d9: 8b442454 MOV EAX, dword ptr [ESP + 0x54]
    s.ax = m.r32((f.sp+0x00000054u));
  }
  L006038dd: { // 0x6038dd: 8944243c MOV dword ptr [ESP + 0x3c], EAX
    m.w32((f.sp+0x0000003cu), s.ax);
  }
  L006038e1: { // 0x6038e1: e871a01600 CALL 0x76d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,6306022u); flags=s.arithmetic_flags;
  }
  L006038e6: { // 0x6038e6: 83c404 ADD ESP, 4
    f.sp = integer::add(f.sp,4u,32,flags);
  }
  L006038e9: { // 0x6038e9: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006038eb: { // 0x6038eb: 0f84c4000000 JZ 0x6039b5
    if(integer::condition("JZ",flags)) goto L006039b5;
  }
  L006038f1: { // 0x6038f1: 8b542424 MOV EDX, dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L006038f5: { // 0x6038f5: 6a00 PUSH 0
    f.push(m,0u);
  }
  L006038f7: { // 0x6038f7: 8d4c2434 LEA ECX, [ESP + 0x34]
    s.cx = (f.sp+0x00000034u);
  }
  L006038fb: { // 0x6038fb: 68c0e0a500 PUSH 0xa5e0c0
    f.push(m,0x00a5e0c0u);
  }
  L00603900: { // 0x603900: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00603901: { // 0x603901: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00603902: { // 0x603902: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L00603904: { // 0x603904: e817c7ffff CALL 0x600020
    s.arithmetic_flags=flags; invoke(m,s,f,0x00600020u,6306057u); flags=s.arithmetic_flags;
  }
  L00603909: { // 0x603909: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0060390b: { // 0x60390b: 89442418 MOV dword ptr [ESP + 0x18], EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0060390f: { // 0x60390f: 745d JZ 0x60396e
    if(integer::condition("JZ",flags)) goto L0060396e;
  }
  L00603911: { // 0x603911: 8b4c2414 MOV ECX, dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L00603915: { // 0x603915: 8d442418 LEA EAX, [ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L00603919: { // 0x603919: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0060391a: { // 0x60391a: 81c1a8000000 ADD ECX, 0xa8
    s.cx = integer::add(s.cx,0x000000a8u,32,flags);
  }
  L00603920: { // 0x603920: e80b130000 CALL 0x604c30
    s.arithmetic_flags=flags; invoke(m,s,f,0x00604c30u,6306085u); flags=s.arithmetic_flags;
  }
  L00603925: { // 0x603925: 8b442418 MOV EAX, dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00603929: { // 0x603929: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0060392b: { // 0x60392b: 8944242c MOV dword ptr [ESP + 0x2c], EAX
    m.w32((f.sp+0x0000002cu), s.ax);
  }
  L0060392f: { // 0x60392f: 743d JZ 0x60396e
    if(integer::condition("JZ",flags)) goto L0060396e;
  }
  L00603931: { // 0x603931: 8b96d4000000 MOV EDX, dword ptr [ESI + 0xd4]
    s.dx = m.r32((s.si+0x000000d4u));
  }
  L00603937: { // 0x603937: 8990d4000000 MOV dword ptr [EAX + 0xd4], EDX
    m.w32((s.ax+0x000000d4u), s.dx);
  }
  L0060393d: { // 0x60393d: a1c055a200 MOV EAX, dword ptr [0xa255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  L00603942: { // 0x603942: 8d8818020000 LEA ECX, [EAX + 0x218]
    s.cx = (s.ax+0x00000218u);
  }
  L00603948: { // 0x603948: e893c40200 CALL 0x62fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,6306125u); flags=s.arithmetic_flags;
  }
  L0060394d: { // 0x60394d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0060394e: { // 0x60394e: b906000000 MOV ECX, 6
    s.cx = 6u;
  }
  L00603953: { // 0x603953: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00603955: { // 0x603955: 8a861f010000 MOV AL, byte ptr [ESI + 0x11f]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000011fu)));
  }
  L0060395b: { // 0x60395b: f7da NEG EDX
    s.dx = integer::sub(0u,s.dx,32,flags);
  }
  L0060395d: { // 0x60395d: 1ad2 SBB DL, DL
    s.dx = with_al(s.dx, integer::sub((s.dx & 0xffu),(s.dx & 0xffu),8,flags,flags&integer::CF));
  }
  L0060395f: { // 0x60395f: 83e219 AND EDX, 0x19
    s.dx = integer::logical((s.dx)&(0x00000019u),32,flags);
  }
  L00603962: { // 0x603962: 02d0 ADD DL, AL
    s.dx = with_al(s.dx, integer::add((s.dx & 0xffu),(s.ax & 0xffu),8,flags));
  }
  L00603964: { // 0x603964: 8b44242c MOV EAX, dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L00603968: { // 0x603968: 88901f010000 MOV byte ptr [EAX + 0x11f], DL
    m.w8((s.ax+0x0000011fu), (s.dx & 0xffu));
  }
  L0060396e: { // 0x60396e: 8b4c241c MOV ECX, dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L00603972: { // 0x603972: 2beb SUB EBP, EBX
    s.bp = integer::sub(s.bp,s.bx,32,flags);
  }
  L00603974: { // 0x603974: 2bf9 SUB EDI, ECX
    s.di = integer::sub(s.di,s.cx,32,flags);
  }
  L00603976: { // 0x603976: 8b4c2450 MOV ECX, dword ptr [ESP + 0x50]
    s.cx = m.r32((f.sp+0x00000050u));
  }
  L0060397a: { // 0x60397a: 6828010000 PUSH 0x128
    f.push(m,0x00000128u);
  }
  L0060397f: { // 0x60397f: 897c2440 MOV dword ptr [ESP + 0x40], EDI
    m.w32((f.sp+0x00000040u), s.di);
  }
  L00603983: { // 0x603983: 896c2444 MOV dword ptr [ESP + 0x44], EBP
    m.w32((f.sp+0x00000044u), s.bp);
  }
  L00603987: { // 0x603987: 894c2448 MOV dword ptr [ESP + 0x48], ECX
    m.w32((f.sp+0x00000048u), s.cx);
  }
  L0060398b: { // 0x60398b: e8c79f1600 CALL 0x76d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,6306192u); flags=s.arithmetic_flags;
  }
  L00603990: { // 0x603990: 83c404 ADD ESP, 4
    f.sp = integer::add(f.sp,4u,32,flags);
  }
  L00603993: { // 0x603993: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00603995: { // 0x603995: 7428 JZ 0x6039bf
    if(integer::condition("JZ",flags)) goto L006039bf;
  }
  L00603997: { // 0x603997: 8b4c2424 MOV ECX, dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L0060399b: { // 0x60399b: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0060399d: { // 0x60399d: 8d542440 LEA EDX, [ESP + 0x40]
    s.dx = (f.sp+0x00000040u);
  }
  L006039a1: { // 0x6039a1: 68c0e0a500 PUSH 0xa5e0c0
    f.push(m,0x00a5e0c0u);
  }
  L006039a6: { // 0x6039a6: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006039a7: { // 0x6039a7: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006039a8: { // 0x6039a8: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L006039aa: { // 0x6039aa: e871c6ffff CALL 0x600020
    s.arithmetic_flags=flags; invoke(m,s,f,0x00600020u,6306223u); flags=s.arithmetic_flags;
  }
  L006039af: { // 0x6039af: 89442420 MOV dword ptr [ESP + 0x20], EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L006039b3: { // 0x6039b3: eb14 JMP 0x6039c9
    goto L006039c9;
  }
  L006039b5: { // 0x6039b5: c744241800000000 MOV dword ptr [ESP + 0x18], 0
    m.w32((f.sp+0x00000018u), 0u);
  }
  L006039bd: { // 0x6039bd: ebaf JMP 0x60396e
    goto L0060396e;
  }
  L006039bf: { // 0x6039bf: c744242000000000 MOV dword ptr [ESP + 0x20], 0
    m.w32((f.sp+0x00000020u), 0u);
  }
  L006039c7: { // 0x6039c7: eb5c JMP 0x603a25
    goto L00603a25;
  }
  L006039c9: { // 0x6039c9: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006039cb: { // 0x6039cb: 7458 JZ 0x603a25
    if(integer::condition("JZ",flags)) goto L00603a25;
  }
  L006039cd: { // 0x6039cd: 8b442414 MOV EAX, dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L006039d1: { // 0x6039d1: 8d542420 LEA EDX, [ESP + 0x20]
    s.dx = (f.sp+0x00000020u);
  }
  L006039d5: { // 0x6039d5: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006039d6: { // 0x6039d6: 8d88a8000000 LEA ECX, [EAX + 0xa8]
    s.cx = (s.ax+0x000000a8u);
  }
  L006039dc: { // 0x6039dc: e84f120000 CALL 0x604c30
    s.arithmetic_flags=flags; invoke(m,s,f,0x00604c30u,6306273u); flags=s.arithmetic_flags;
  }
  L006039e1: { // 0x6039e1: 8b442420 MOV EAX, dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L006039e5: { // 0x6039e5: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006039e7: { // 0x6039e7: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L006039e9: { // 0x6039e9: 743a JZ 0x603a25
    if(integer::condition("JZ",flags)) goto L00603a25;
  }
  L006039eb: { // 0x6039eb: 8b8ed4000000 MOV ECX, dword ptr [ESI + 0xd4]
    s.cx = m.r32((s.si+0x000000d4u));
  }
  L006039f1: { // 0x6039f1: 8988d4000000 MOV dword ptr [EAX + 0xd4], ECX
    m.w32((s.ax+0x000000d4u), s.cx);
  }
  L006039f7: { // 0x6039f7: 8b15c055a200 MOV EDX, dword ptr [0xa255c0]
    s.dx = m.r32((0x00a255c0u));
  }
  L006039fd: { // 0x6039fd: 8d8a18020000 LEA ECX, [EDX + 0x218]
    s.cx = (s.dx+0x00000218u);
  }
  L00603a03: { // 0x603a03: e8d8c30200 CALL 0x62fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,6306312u); flags=s.arithmetic_flags;
  }
  L00603a08: { // 0x603a08: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00603a09: { // 0x603a09: b906000000 MOV ECX, 6
    s.cx = 6u;
  }
  L00603a0e: { // 0x603a0e: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00603a10: { // 0x603a10: 8a861f010000 MOV AL, byte ptr [ESI + 0x11f]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000011fu)));
  }
  L00603a16: { // 0x603a16: f7da NEG EDX
    s.dx = integer::sub(0u,s.dx,32,flags);
  }
  L00603a18: { // 0x603a18: 1ad2 SBB DL, DL
    s.dx = with_al(s.dx, integer::sub((s.dx & 0xffu),(s.dx & 0xffu),8,flags,flags&integer::CF));
  }
  L00603a1a: { // 0x603a1a: 83e219 AND EDX, 0x19
    s.dx = integer::logical((s.dx)&(0x00000019u),32,flags);
  }
  L00603a1d: { // 0x603a1d: 02d0 ADD DL, AL
    s.dx = with_al(s.dx, integer::add((s.dx & 0xffu),(s.ax & 0xffu),8,flags));
  }
  L00603a1f: { // 0x603a1f: 88971f010000 MOV byte ptr [EDI + 0x11f], DL
    m.w8((s.di+0x0000011fu), (s.dx & 0xffu));
  }
  L00603a25: { // 0x603a25: 8b7c2414 MOV EDI, dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L00603a29: { // 0x603a29: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00603a2b: { // 0x603a2b: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00603a2d: { // 0x603a2d: ff92f0000000 CALL dword ptr [EDX + 0xf0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000000f0u)),6306355u); flags=s.arithmetic_flags;
  }
  L00603a33: { // 0x603a33: 8b5c2428 MOV EBX, dword ptr [ESP + 0x28]
    s.bx = m.r32((f.sp+0x00000028u));
  }
  L00603a37: { // 0x603a37: eb07 JMP 0x603a40
    goto L00603a40;
  }
  L00603a39: { // 0x603a39: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00603a3b: { // 0x603a3b: e8c0e5ffff CALL 0x602000
    s.arithmetic_flags=flags; invoke(m,s,f,0x00602000u,6306368u); flags=s.arithmetic_flags;
  }
  L00603a40: { // 0x603a40: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L00603a41: { // 0x603a41: 895c2428 MOV dword ptr [ESP + 0x28], EBX
    m.w32((f.sp+0x00000028u), s.bx);
  }
  L00603a45: { // 0x603a45: 0f89bafdffff JNS 0x603805
    if(integer::condition("JNS",flags)) goto L00603805;
  }
  L00603a4b: { // 0x603a4b: 8a87e4000000 MOV AL, byte ptr [EDI + 0xe4]
    s.ax = with_al(s.ax, m.r8((s.di+0x000000e4u)));
  }
  L00603a51: { // 0x603a51: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00603a53: { // 0x603a53: 0f859b010000 JNZ 0x603bf4
    if(integer::condition("JNZ",flags)) goto L00603bf4;
  }
  L00603a59: { // 0x603a59: 8a477d MOV AL, byte ptr [EDI + 0x7d]
    s.ax = with_al(s.ax, m.r8((s.di+0x0000007du)));
  }
  L00603a5c: { // 0x603a5c: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00603a5e: { // 0x603a5e: 0f8490010000 JZ 0x603bf4
    if(integer::condition("JZ",flags)) goto L00603bf4;
  }
  L00603a64: { // 0x603a64: d987d4000000 FLD dword ptr [EDI + 0xd4]
    const auto address=(s.di+0x000000d4u);
    s.fp.load32(m.r32(address));
  }
  L00603a6a: { // 0x603a6a: e8e16f1600 CALL 0x76aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6306415u); flags=s.arithmetic_flags;
  }
  L00603a6f: { // 0x603a6f: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L00603a71: { // 0x603a71: a16c89a200 MOV EAX, dword ptr [0xa2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  L00603a76: { // 0x603a76: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00603a77: { // 0x603a77: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00603a79: { // 0x603a79: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00603a7b: { // 0x603a7b: 0f8573010000 JNZ 0x603bf4
    if(integer::condition("JNZ",flags)) goto L00603bf4;
  }
  L00603a81: { // 0x603a81: 8b87cc000000 MOV EAX, dword ptr [EDI + 0xcc]
    s.ax = m.r32((s.di+0x000000ccu));
  }
  L00603a87: { // 0x603a87: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00603a89: { // 0x603a89: 7414 JZ 0x603a9f
    if(integer::condition("JZ",flags)) goto L00603a9f;
  }
  L00603a8b: { // 0x603a8b: f6401404 TEST byte ptr [EAX + 0x14], 4
    (void)integer::logical((m.r8((s.ax+0x00000014u)))&(4u),8,flags);
  }
  L00603a8f: { // 0x603a8f: 740e JZ 0x603a9f
    if(integer::condition("JZ",flags)) goto L00603a9f;
  }
  L00603a91: { // 0x603a91: 8a8874050000 MOV CL, byte ptr [EAX + 0x574]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000574u)));
  }
  L00603a97: { // 0x603a97: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00603a99: { // 0x603a99: 0f8d55010000 JGE 0x603bf4
    if(integer::condition("JGE",flags)) goto L00603bf4;
  }
  L00603a9f: { // 0x603a9f: 8b15c055a200 MOV EDX, dword ptr [0xa255c0]
    s.dx = m.r32((0x00a255c0u));
  }
  L00603aa5: { // 0x603aa5: 8db218020000 LEA ESI, [EDX + 0x218]
    s.si = (s.dx+0x00000218u);
  }
  L00603aab: { // 0x603aab: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00603aad: { // 0x603aad: e82ec30200 CALL 0x62fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,6306482u); flags=s.arithmetic_flags;
  }
  L00603ab2: { // 0x603ab2: 8b9f98000000 MOV EBX, dword ptr [EDI + 0x98]
    s.bx = m.r32((s.di+0x00000098u));
  }
  L00603ab8: { // 0x603ab8: 8944242c MOV dword ptr [ESP + 0x2c], EAX
    m.w32((f.sp+0x0000002cu), s.ax);
  }
  L00603abc: { // 0x603abc: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00603abe: { // 0x603abe: 8b8378020000 MOV EAX, dword ptr [EBX + 0x278]
    s.ax = m.r32((s.bx+0x00000278u));
  }
  L00603ac4: { // 0x603ac4: 8d6801 LEA EBP, [EAX + 1]
    s.bp = (s.ax+1u);
  }
  L00603ac7: { // 0x603ac7: e814c30200 CALL 0x62fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,6306508u); flags=s.arithmetic_flags;
  }
  L00603acc: { // 0x603acc: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00603acd: { // 0x603acd: f7fd IDIV EBP
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.bp,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00603acf: { // 0x603acf: 8b44242c MOV EAX, dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L00603ad3: { // 0x603ad3: 8bca MOV ECX, EDX
    s.cx = s.dx;
  }
  L00603ad5: { // 0x603ad5: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00603ad6: { // 0x603ad6: f7fd IDIV EBP
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.bp,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00603ad8: { // 0x603ad8: 8d8788000000 LEA EAX, [EDI + 0x88]
    s.ax = (s.di+0x00000088u);
  }
  L00603ade: { // 0x603ade: 8be8 MOV EBP, EAX
    s.bp = s.ax;
  }
  L00603ae0: { // 0x603ae0: 8b4500 MOV EAX, dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L00603ae3: { // 0x603ae3: 8b7504 MOV ESI, dword ptr [EBP + 4]
    s.si = m.r32((s.bp+4u));
  }
  L00603ae6: { // 0x603ae6: 03ce ADD ECX, ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L00603ae8: { // 0x603ae8: 8b6d08 MOV EBP, dword ptr [EBP + 8]
    s.bp = m.r32((s.bp+8u));
  }
  L00603aeb: { // 0x603aeb: 894c2440 MOV dword ptr [ESP + 0x40], ECX
    m.w32((f.sp+0x00000040u), s.cx);
  }
  L00603aef: { // 0x603aef: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00603af1: { // 0x603af1: 8d550a LEA EDX, [EBP + 0xa]
    s.dx = (s.bp+0x0000000au);
  }
  L00603af4: { // 0x603af4: 8944243c MOV dword ptr [ESP + 0x3c], EAX
    m.w32((f.sp+0x0000003cu), s.ax);
  }
  L00603af8: { // 0x603af8: 89542444 MOV dword ptr [ESP + 0x44], EDX
    m.w32((f.sp+0x00000044u), s.dx);
  }
  L00603afc: { // 0x603afc: 83bb64020000ff CMP dword ptr [EBX + 0x264], -1
    (void)integer::sub(m.r32((s.bx+0x00000264u)),4294967295u,32,flags);
  }
  L00603b03: { // 0x603b03: 0f84eb000000 JZ 0x603bf4
    if(integer::condition("JZ",flags)) goto L00603bf4;
  }
  L00603b09: { // 0x603b09: 6828010000 PUSH 0x128
    f.push(m,0x00000128u);
  }
  L00603b0e: { // 0x603b0e: e8449e1600 CALL 0x76d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,6306579u); flags=s.arithmetic_flags;
  }
  L00603b13: { // 0x603b13: 83c404 ADD ESP, 4
    f.sp = integer::add(f.sp,4u,32,flags);
  }
  L00603b16: { // 0x603b16: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00603b18: { // 0x603b18: 0f84d6000000 JZ 0x603bf4
    if(integer::condition("JZ",flags)) goto L00603bf4;
  }
  L00603b1e: { // 0x603b1e: 8d8fc0000000 LEA ECX, [EDI + 0xc0]
    s.cx = (s.di+0x000000c0u);
  }
  L00603b24: { // 0x603b24: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00603b25: { // 0x603b25: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00603b26: { // 0x603b26: 8b8f98000000 MOV ECX, dword ptr [EDI + 0x98]
    s.cx = m.r32((s.di+0x00000098u));
  }
  L00603b2c: { // 0x603b2c: 8d542444 LEA EDX, [ESP + 0x44]
    s.dx = (f.sp+0x00000044u);
  }
  L00603b30: { // 0x603b30: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00603b31: { // 0x603b31: 8b9164020000 MOV EDX, dword ptr [ECX + 0x264]
    s.dx = m.r32((s.cx+0x00000264u));
  }
  L00603b37: { // 0x603b37: 8b0d34e1a100 MOV ECX, dword ptr [0xa1e134]
    s.cx = m.r32((0x00a1e134u));
  }
  L00603b3d: { // 0x603b3d: 8b1491 MOV EDX, dword ptr [ECX + EDX*4]
    s.dx = m.r32((s.cx+(s.dx * 4u)));
  }
  L00603b40: { // 0x603b40: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L00603b42: { // 0x603b42: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00603b43: { // 0x603b43: e8d8c4ffff CALL 0x600020
    s.arithmetic_flags=flags; invoke(m,s,f,0x00600020u,6306632u); flags=s.arithmetic_flags;
  }
  L00603b48: { // 0x603b48: 8bd8 MOV EBX, EAX
    s.bx = s.ax;
  }
  L00603b4a: { // 0x603b4a: 85db TEST EBX, EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L00603b4c: { // 0x603b4c: 0f84a2000000 JZ 0x603bf4
    if(integer::condition("JZ",flags)) goto L00603bf4;
  }
  L00603b52: { // 0x603b52: 8b8fb0000000 MOV ECX, dword ptr [EDI + 0xb0]
    s.cx = m.r32((s.di+0x000000b0u));
  }
  L00603b58: { // 0x603b58: 8b87b8000000 MOV EAX, dword ptr [EDI + 0xb8]
    s.ax = m.r32((s.di+0x000000b8u));
  }
  L00603b5e: { // 0x603b5e: 8db7a8000000 LEA ESI, [EDI + 0xa8]
    s.si = (s.di+0x000000a8u);
  }
  L00603b64: { // 0x603b64: 3bc1 CMP EAX, ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00603b66: { // 0x603b66: 7c22 JL 0x603b8a
    if(integer::condition("JL",flags)) goto L00603b8a;
  }
  L00603b68: { // 0x603b68: 8a460d MOV AL, byte ptr [ESI + 0xd]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000000du)));
  }
  L00603b6b: { // 0x603b6b: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00603b6d: { // 0x603b6d: 7504 JNZ 0x603b73
    if(integer::condition("JNZ",flags)) goto L00603b73;
  }
  L00603b6f: { // 0x603b6f: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00603b71: { // 0x603b71: 7526 JNZ 0x603b99
    if(integer::condition("JNZ",flags)) goto L00603b99;
  }
  L00603b73: { // 0x603b73: 8b4614 MOV EAX, dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  L00603b76: { // 0x603b76: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00603b78: { // 0x603b78: 7e1f JLE 0x603b99
    if(integer::condition("JLE",flags)) goto L00603b99;
  }
  L00603b7a: { // 0x603b7a: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00603b7c: { // 0x603b7c: 03c1 ADD EAX, ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00603b7e: { // 0x603b7e: 6a00 PUSH 0
    f.push(m,0u);
  }
  L00603b80: { // 0x603b80: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00603b81: { // 0x603b81: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00603b83: { // 0x603b83: ff5208 CALL dword ptr [EDX + 8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+8u)),6306694u); flags=s.arithmetic_flags;
  }
  L00603b86: { // 0x603b86: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00603b88: { // 0x603b88: 740f JZ 0x603b99
    if(integer::condition("JZ",flags)) goto L00603b99;
  }
  L00603b8a: { // 0x603b8a: 8b4610 MOV EAX, dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L00603b8d: { // 0x603b8d: 8b5604 MOV EDX, dword ptr [ESI + 4]
    s.dx = m.r32((s.si+4u));
  }
  L00603b90: { // 0x603b90: 8d4801 LEA ECX, [EAX + 1]
    s.cx = (s.ax+1u);
  }
  L00603b93: { // 0x603b93: 894e10 MOV dword ptr [ESI + 0x10], ECX
    m.w32((s.si+0x00000010u), s.cx);
  }
  L00603b96: { // 0x603b96: 891c82 MOV dword ptr [EDX + EAX*4], EBX
    m.w32((s.dx+(s.ax * 4u)), s.bx);
  }
  L00603b99: { // 0x603b99: 8b8798000000 MOV EAX, dword ptr [EDI + 0x98]
    s.ax = m.r32((s.di+0x00000098u));
  }
  L00603b9f: { // 0x603b9f: d987d4000000 FLD dword ptr [EDI + 0xd4]
    const auto address=(s.di+0x000000d4u);
    s.fp.load32(m.r32(address));
  }
  L00603ba5: { // 0x603ba5: d89880020000 FCOMP dword ptr [EAX + 0x280]
    const auto address=(s.ax+0x00000280u);
    s.fp.compare_pop32(m.r32(address));
  }
  L00603bab: { // 0x603bab: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00603bad: { // 0x603bad: f6c441 TEST AH, 0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L00603bb0: { // 0x603bb0: 7507 JNZ 0x603bb9
    if(integer::condition("JNZ",flags)) goto L00603bb9;
  }
  L00603bb2: { // 0x603bb2: 80831f01000019 ADD byte ptr [EBX + 0x11f], 0x19
    m.w8((s.bx+0x0000011fu), integer::add(m.r8((s.bx+0x0000011fu)),0x00000019u,8,flags));
  }
  L00603bb9: { // 0x603bb9: 8b8f98000000 MOV ECX, dword ptr [EDI + 0x98]
    s.cx = m.r32((s.di+0x00000098u));
  }
  L00603bbf: { // 0x603bbf: db816c020000 FILD dword ptr [ECX + 0x26c]
    const auto address=(s.cx+0x0000026cu);
    s.fp.load_integer32(m.r32(address));
  }
  L00603bc5: { // 0x603bc5: d8afd4000000 FSUBR dword ptr [EDI + 0xd4]
    const auto address=(s.di+0x000000d4u);
    ra2::platform::x87_b61::reverse_subtract32(s.fp,m.r32(address));
  }
  L00603bcb: { // 0x603bcb: d80d002f7900 FMUL dword ptr [0x792f00]
    const auto address=(0x00792f00u);
    s.fp.multiply32(m.r32(address));
  }
  L00603bd1: { // 0x603bd1: d8abd4000000 FSUBR dword ptr [EBX + 0xd4]
    const auto address=(s.bx+0x000000d4u);
    ra2::platform::x87_b61::reverse_subtract32(s.fp,m.r32(address));
  }
  L00603bd7: { // 0x603bd7: d993d4000000 FST dword ptr [EBX + 0xd4]
    const auto address=(s.bx+0x000000d4u);
    const auto value=s.fp.store32();
    m.w32(address,value);
  }
  L00603bdd: { // 0x603bdd: dc1df8567800 FCOMP qword ptr [0x7856f8]
    const auto address=(0x007856f8u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00603be3: { // 0x603be3: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00603be5: { // 0x603be5: f6c401 TEST AH, 1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(1u),8,flags);
  }
  L00603be8: { // 0x603be8: 740a JZ 0x603bf4
    if(integer::condition("JZ",flags)) goto L00603bf4;
  }
  L00603bea: { // 0x603bea: c783d400000000000040 MOV dword ptr [EBX + 0xd4], 0x40000000
    m.w32((s.bx+0x000000d4u), 0x40000000u);
  }
  L00603bf4: { // 0x603bf4: 8b8798000000 MOV EAX, dword ptr [EDI + 0x98]
    s.ax = m.r32((s.di+0x00000098u));
  }
  L00603bfa: { // 0x603bfa: d98070020000 FLD dword ptr [EAX + 0x270]
    const auto address=(s.ax+0x00000270u);
    s.fp.load32(m.r32(address));
  }
  L00603c00: { // 0x603c00: d887d4000000 FADD dword ptr [EDI + 0xd4]
    const auto address=(s.di+0x000000d4u);
    s.fp.add32(m.r32(address));
  }
  L00603c06: { // 0x603c06: d997d4000000 FST dword ptr [EDI + 0xd4]
    const auto address=(s.di+0x000000d4u);
    const auto value=s.fp.store32();
    m.w32(address,value);
  }
  L00603c0c: { // 0x603c0c: d8987c020000 FCOMP dword ptr [EAX + 0x27c]
    const auto address=(s.ax+0x0000027cu);
    s.fp.compare_pop32(m.r32(address));
  }
  L00603c12: { // 0x603c12: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00603c14: { // 0x603c14: f6c441 TEST AH, 0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L00603c17: { // 0x603c17: 7507 JNZ 0x603c20
    if(integer::condition("JNZ",flags)) goto L00603c20;
  }
  L00603c19: { // 0x603c19: c687e400000001 MOV byte ptr [EDI + 0xe4], 1
    m.w8((s.di+0x000000e4u), 1u);
  }
  L00603c20: { // 0x603c20: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00603c21: { // 0x603c21: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00603c22: { // 0x603c22: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00603c23: { // 0x603c23: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00603c24: { // 0x603c24: 83c444 ADD ESP, 0x44
    f.sp = integer::add(f.sp,0x00000044u,32,flags);
  }
  L00603c27: { // 0x603c27: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00604750(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00604750: { // 0x604750: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00604751: { // 0x604751: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00604753: { // 0x604753: 8b8698000000 MOV EAX,dword ptr [ESI + 0x98]
    s.ax = m.r32((s.si+0x00000098u));
  }
  L00604759: { // 0x604759: 8b8084020000 MOV EAX,dword ptr [EAX + 0x284]
    s.ax = m.r32((s.ax+0x00000284u));
  }
  L0060475f: { // 0x60475f: 83f804 CMP EAX,0x4
    (void)integer::sub(s.ax,0x00000004u,32,flags);
  }
  L00604762: { // 0x604762: 7732 JA 0x00604796
    if(integer::condition("JA",flags)) goto L00604796;
  }
  L00604764: { // 0x604764: ff248530486000 JMP dword ptr [EAX*0x4 + 0x604830]
    switch((std::array<std::uint32_t,5>{0x60476bu,0x604774u,0x60477du,0x604786u,0x60478fu}[s.ax])){
    case 0x00604750u: goto L00604750;
    case 0x00604751u: goto L00604751;
    case 0x00604753u: goto L00604753;
    case 0x00604759u: goto L00604759;
    case 0x0060475fu: goto L0060475f;
    case 0x00604762u: goto L00604762;
    case 0x00604764u: goto L00604764;
    case 0x0060476bu: goto L0060476b;
    case 0x0060476du: goto L0060476d;
    case 0x00604772u: goto L00604772;
    case 0x00604774u: goto L00604774;
    case 0x00604776u: goto L00604776;
    case 0x0060477bu: goto L0060477b;
    case 0x0060477du: goto L0060477d;
    case 0x0060477fu: goto L0060477f;
    case 0x00604784u: goto L00604784;
    case 0x00604786u: goto L00604786;
    case 0x00604788u: goto L00604788;
    case 0x0060478du: goto L0060478d;
    case 0x0060478fu: goto L0060478f;
    case 0x00604791u: goto L00604791;
    case 0x00604796u: goto L00604796;
    case 0x0060479cu: goto L0060479c;
    case 0x0060479du: goto L0060479d;
    case 0x006047a3u: goto L006047a3;
    case 0x006047a5u: goto L006047a5;
    case 0x006047a7u: goto L006047a7;
    case 0x006047a9u: goto L006047a9;
    case 0x006047afu: goto L006047af;
    case 0x006047b2u: goto L006047b2;
    case 0x006047b4u: goto L006047b4;
    case 0x006047b6u: goto L006047b6;
    case 0x006047bcu: goto L006047bc;
    case 0x006047beu: goto L006047be;
    case 0x006047c0u: goto L006047c0;
    case 0x006047c6u: goto L006047c6;
    case 0x006047c8u: goto L006047c8;
    case 0x006047cau: goto L006047ca;
    case 0x006047ccu: goto L006047cc;
    case 0x006047ceu: goto L006047ce;
    case 0x006047d4u: goto L006047d4;
    case 0x006047d8u: goto L006047d8;
    case 0x006047ddu: goto L006047dd;
    case 0x006047e3u: goto L006047e3;
    case 0x006047e5u: goto L006047e5;
    case 0x006047ebu: goto L006047eb;
    case 0x006047edu: goto L006047ed;
    case 0x006047efu: goto L006047ef;
    case 0x006047f1u: goto L006047f1;
    case 0x006047f3u: goto L006047f3;
    case 0x006047f9u: goto L006047f9;
    case 0x006047fbu: goto L006047fb;
    case 0x006047fdu: goto L006047fd;
    case 0x00604803u: goto L00604803;
    case 0x00604805u: goto L00604805;
    case 0x00604807u: goto L00604807;
    case 0x00604808u: goto L00604808;
    case 0x0060480du: goto L0060480d;
    case 0x00604810u: goto L00604810;
    case 0x00604812u: goto L00604812;
    case 0x00604814u: goto L00604814;
    case 0x0060481au: goto L0060481a;
    case 0x0060481cu: goto L0060481c;
    case 0x0060481du: goto L0060481d;
    case 0x00604823u: goto L00604823;
    case 0x00604829u: goto L00604829;
    case 0x0060482cu: goto L0060482c;
    case 0x0060482du: goto L0060482d;
    default:throw std::domain_error("recovery824 unsupported switch destination");}
  }
  L0060476b: { // 0x60476b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0060476d: { // 0x60476d: e8deefffff CALL 0x00603750
    s.arithmetic_flags=flags; invoke(m,s,f,0x00603750u,6309746u); flags=s.arithmetic_flags;
  }
  L00604772: { // 0x604772: eb22 JMP 0x00604796
    goto L00604796;
  }
  L00604774: { // 0x604774: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00604776: { // 0x604776: e845e9ffff CALL 0x006030c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006030c0u,6309755u); flags=s.arithmetic_flags;
  }
  L0060477b: { // 0x60477b: eb19 JMP 0x00604796
    goto L00604796;
  }
  L0060477d: { // 0x60477d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0060477f: { // 0x60477f: e81cfcffff CALL 0x006043a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006043a0u,6309764u); flags=s.arithmetic_flags;
  }
  L00604784: { // 0x604784: eb10 JMP 0x00604796
    goto L00604796;
  }
  L00604786: { // 0x604786: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00604788: { // 0x604788: e8c3eaffff CALL 0x00603250
    s.arithmetic_flags=flags; invoke(m,s,f,0x00603250u,6309773u); flags=s.arithmetic_flags;
  }
  L0060478d: { // 0x60478d: eb07 JMP 0x00604796
    goto L00604796;
  }
  L0060478f: { // 0x60478f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00604791: { // 0x604791: e89af4ffff CALL 0x00603c30
    s.arithmetic_flags=flags; invoke(m,s,f,0x00603c30u,6309782u); flags=s.arithmetic_flags;
  }
  L00604796: { // 0x604796: 8b86d8000000 MOV EAX,dword ptr [ESI + 0xd8]
    s.ax = m.r32((s.si+0x000000d8u));
  }
  L0060479c: { // 0x60479c: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0060479d: { // 0x60479d: 8986d8000000 MOV dword ptr [ESI + 0xd8],EAX
    m.w32((s.si+0x000000d8u), s.ax);
  }
  L006047a3: { // 0x6047a3: 750a JNZ 0x006047af
    if(integer::condition("JNZ",flags)) goto L006047af;
  }
  L006047a5: { // 0x6047a5: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006047a7: { // 0x6047a7: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006047a9: { // 0x6047a9: ff92f0000000 CALL dword ptr [EDX + 0xf0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000000f0u)),6309807u); flags=s.arithmetic_flags;
  }
  L006047af: { // 0x6047af: 8a467d MOV AL,byte ptr [ESI + 0x7d]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000007du)));
  }
  L006047b2: { // 0x6047b2: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006047b4: { // 0x6047b4: 7476 JZ 0x0060482c
    if(integer::condition("JZ",flags)) goto L0060482c;
  }
  L006047b6: { // 0x6047b6: 8a86e4000000 MOV AL,byte ptr [ESI + 0xe4]
    s.ax = with_al(s.ax, m.r8((s.si+0x000000e4u)));
  }
  L006047bc: { // 0x6047bc: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006047be: { // 0x6047be: 746c JZ 0x0060482c
    if(integer::condition("JZ",flags)) goto L0060482c;
  }
  L006047c0: { // 0x6047c0: 8b86b8000000 MOV EAX,dword ptr [ESI + 0xb8]
    s.ax = m.r32((s.si+0x000000b8u));
  }
  L006047c6: { // 0x6047c6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006047c8: { // 0x6047c8: 7562 JNZ 0x0060482c
    if(integer::condition("JNZ",flags)) goto L0060482c;
  }
  L006047ca: { // 0x6047ca: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006047cc: { // 0x6047cc: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006047ce: { // 0x6047ce: ff90d0000000 CALL dword ptr [EAX + 0xd0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000000d0u)),6309844u); flags=s.arithmetic_flags;
  }
  L006047d4: { // 0x6047d4: c6467d00 MOV byte ptr [ESI + 0x7d],0x0
    m.w8((s.si+0x0000007du), 0x00000000u);
  }
  L006047d8: { // 0x6047d8: a1e887aa00 MOV EAX,[0x00aa87e8]
    s.ax = m.r32((0x00aa87e8u));
  }
  L006047dd: { // 0x6047dd: 3905f087aa00 CMP dword ptr [0x00aa87f0],EAX
    (void)integer::sub(m.r32((0x00aa87f0u)),s.ax,32,flags);
  }
  L006047e3: { // 0x6047e3: 7c2f JL 0x00604814
    if(integer::condition("JL",flags)) goto L00604814;
  }
  L006047e5: { // 0x6047e5: 8a0ded87aa00 MOV CL,byte ptr [0x00aa87ed]
    s.cx = with_al(s.cx, m.r8((0x00aa87edu)));
  }
  L006047eb: { // 0x6047eb: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006047ed: { // 0x6047ed: 7504 JNZ 0x006047f3
    if(integer::condition("JNZ",flags)) goto L006047f3;
  }
  L006047ef: { // 0x6047ef: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006047f1: { // 0x6047f1: 7539 JNZ 0x0060482c
    if(integer::condition("JNZ",flags)) goto L0060482c;
  }
  L006047f3: { // 0x6047f3: 8b0df487aa00 MOV ECX,dword ptr [0x00aa87f4]
    s.cx = m.r32((0x00aa87f4u));
  }
  L006047f9: { // 0x6047f9: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006047fb: { // 0x6047fb: 7e2f JLE 0x0060482c
    if(integer::condition("JLE",flags)) goto L0060482c;
  }
  L006047fd: { // 0x6047fd: 8b15e087aa00 MOV EDX,dword ptr [0x00aa87e0]
    s.dx = m.r32((0x00aa87e0u));
  }
  L00604803: { // 0x604803: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00604805: { // 0x604805: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00604807: { // 0x604807: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00604808: { // 0x604808: b9e087aa00 MOV ECX,0xaa87e0
    s.cx = 0x00aa87e0u;
  }
  L0060480d: { // 0x60480d: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),6309904u); flags=s.arithmetic_flags;
  }
  L00604810: { // 0x604810: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00604812: { // 0x604812: 7418 JZ 0x0060482c
    if(integer::condition("JZ",flags)) goto L0060482c;
  }
  L00604814: { // 0x604814: 8b0df087aa00 MOV ECX,dword ptr [0x00aa87f0]
    s.cx = m.r32((0x00aa87f0u));
  }
  L0060481a: { // 0x60481a: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0060481c: { // 0x60481c: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0060481d: { // 0x60481d: 890df087aa00 MOV dword ptr [0x00aa87f0],ECX
    m.w32((0x00aa87f0u), s.cx);
  }
  L00604823: { // 0x604823: 8b0de487aa00 MOV ECX,dword ptr [0x00aa87e4]
    s.cx = m.r32((0x00aa87e4u));
  }
  L00604829: { // 0x604829: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L0060482c: { // 0x60482c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0060482d: { // 0x60482d: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
