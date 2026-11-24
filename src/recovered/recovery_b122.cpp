#include "recovered/recovery_b122_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b122 {
namespace {
void f_000072f0(Memory&,State&,Frame&,const Operations&);
void f_00007310(Memory&,State&,Frame&,const Operations&);
void f_00093da0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_000072f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004072f0: { // 0x4072f0: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004072f2: { // 0x4072f2: 740b JZ 0x004072ff
    if(integer::condition("JZ",flags)) goto L004072ff;
  }
  L004072f4: { // 0x4072f4: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L004072f6: { // 0x4072f6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004072f8: { // 0x4072f8: 7407 JZ 0x00407301
    if(integer::condition("JZ",flags)) goto L00407301;
  }
  L004072fa: { // 0x4072fa: 3b4008 CMP EAX,dword ptr [EAX + 0x8]
    (void)integer::sub(s.ax,m.r32((s.ax+0x00000008u)),32,flags);
  }
  L004072fd: { // 0x4072fd: 7502 JNZ 0x00407301
    if(integer::condition("JNZ",flags)) goto L00407301;
  }
  L004072ff: { // 0x4072ff: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00407301: { // 0x407301: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00007310(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00407310: { // 0x407310: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00407312: { // 0x407312: 740b JZ 0x0040731f
    if(integer::condition("JZ",flags)) goto L0040731f;
  }
  L00407314: { // 0x407314: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00407316: { // 0x407316: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00407318: { // 0x407318: 7407 JZ 0x00407321
    if(integer::condition("JZ",flags)) goto L00407321;
  }
  L0040731a: { // 0x40731a: 3b4008 CMP EAX,dword ptr [EAX + 0x8]
    (void)integer::sub(s.ax,m.r32((s.ax+0x00000008u)),32,flags);
  }
  L0040731d: { // 0x40731d: 7502 JNZ 0x00407321
    if(integer::condition("JNZ",flags)) goto L00407321;
  }
  L0040731f: { // 0x40731f: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00407321: { // 0x407321: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_00093da0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00493da0: { // 0x493da0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00493da1: { // 0x493da1: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00493da2: { // 0x493da2: 8b6c240c MOV EBP,dword ptr [ESP + 0xc]
    s.bp = m.r32((f.sp+0x0000000cu));
  }
  L00493da6: { // 0x493da6: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00493da8: { // 0x493da8: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00493da9: { // 0x493da9: 3beb CMP EBP,EBX
    (void)integer::sub(s.bp,s.bx,32,flags);
  }
  L00493dab: { // 0x493dab: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00493dac: { // 0x493dac: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00493dae: { // 0x493dae: 0f844c010000 JZ 0x00493f00
    if(integer::condition("JZ",flags)) goto L00493f00;
  }
  L00493db4: { // 0x493db4: 8b7c2418 MOV EDI,dword ptr [ESP + 0x18]
    s.di = m.r32((f.sp+0x00000018u));
  }
  L00493db8: { // 0x493db8: 3bfb CMP EDI,EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  L00493dba: { // 0x493dba: 0f8e40010000 JLE 0x00493f00
    if(integer::condition("JLE",flags)) goto L00493f00;
  }
  L00493dc0: { // 0x493dc0: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L00493dc3: { // 0x493dc3: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00493dc5: { // 0x493dc5: 7454 JZ 0x00493e1b
    if(integer::condition("JZ",flags)) goto L00493e1b;
  }
  L00493dc7: { // 0x493dc7: ba04000000 MOV EDX,0x4
    s.dx = 0x00000004u;
  }
  L00493dcc: { // 0x493dcc: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00493dce: { // 0x493dce: 734b JNC 0x00493e1b
    if(integer::condition("JNC",flags)) goto L00493e1b;
  }
  L00493dd0: { // 0x493dd0: 8a4d00 MOV CL,byte ptr [EBP]
    s.cx = with_al(s.cx, m.r8((s.bp)));
  }
  L00493dd3: { // 0x493dd3: 884c3008 MOV byte ptr [EAX + ESI*0x1 + 0x8],CL
    m.w8((s.ax+(s.si * 0x00000001u)+0x00000008u), (s.cx & 0xffu));
  }
  L00493dd7: { // 0x493dd7: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  L00493dda: { // 0x493dda: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00493ddb: { // 0x493ddb: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00493ddd: { // 0x493ddd: 894e04 MOV dword ptr [ESI + 0x4],ECX
    m.w32((s.si+0x00000004u), s.cx);
  }
  L00493de0: { // 0x493de0: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00493de2: { // 0x493de2: 7531 JNZ 0x00493e15
    if(integer::condition("JNZ",flags)) goto L00493e15;
  }
  L00493de4: { // 0x493de4: 8ac1 MOV AL,CL
    s.ax = with_al(s.ax, (s.cx & 0xffu));
  }
  L00493de6: { // 0x493de6: 88460c MOV byte ptr [ESI + 0xc],AL
    m.w8((s.si+0x0000000cu), (s.ax & 0xffu));
  }
  L00493de9: { // 0x493de9: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L00493dec: { // 0x493dec: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00493ded: { // 0x493ded: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00493def: { // 0x493def: 730c JNC 0x00493dfd
    if(integer::condition("JNC",flags)) goto L00493dfd;
  }
  L00493df1: { // 0x493df1: 8a4e08 MOV CL,byte ptr [ESI + 0x8]
    s.cx = with_al(s.cx, m.r8((s.si+0x00000008u)));
  }
  L00493df4: { // 0x493df4: 884c0608 MOV byte ptr [ESI + EAX*0x1 + 0x8],CL
    m.w8((s.si+(s.ax * 0x00000001u)+0x00000008u), (s.cx & 0xffu));
  }
  L00493df8: { // 0x493df8: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00493df9: { // 0x493df9: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00493dfb: { // 0x493dfb: 72f4 JC 0x00493df1
    if(integer::condition("JC",flags)) goto L00493df1;
  }
  L00493dfd: { // 0x493dfd: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L00493dff: { // 0x493dff: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L00493e02: { // 0x493e02: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00493e03: { // 0x493e03: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L00493e07: { // 0x493e07: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00493e0b: { // 0x493e0b: e860010000 CALL 0x00493f70
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493f70u,4800016u); flags=s.arithmetic_flags;
  }
  L00493e10: { // 0x493e10: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  L00493e12: { // 0x493e12: 895e04 MOV dword ptr [ESI + 0x4],EBX
    m.w32((s.si+0x00000004u), s.bx);
  }
  L00493e15: { // 0x493e15: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L00493e16: { // 0x493e16: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L00493e17: { // 0x493e17: 3bfb CMP EDI,EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  L00493e19: { // 0x493e19: 7fa5 JG 0x00493dc0
    if(integer::condition("JG",flags)) goto L00493dc0;
  }
  L00493e1b: { // 0x493e1b: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L00493e1d: { // 0x493e1d: c1e802 SHR EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::right);
  }
  L00493e20: { // 0x493e20: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00493e22: { // 0x493e22: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00493e23: { // 0x493e23: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00493e25: { // 0x493e25: 744f JZ 0x00493e76
    if(integer::condition("JZ",flags)) goto L00493e76;
  }
  L00493e27: { // 0x493e27: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00493e28: { // 0x493e28: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00493e2c: { // 0x493e2c: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L00493e2e: { // 0x493e2e: 8d0487 LEA EAX,[EDI + EAX*0x4]
    s.ax = (s.di+(s.ax * 0x00000004u));
  }
  L00493e31: { // 0x493e31: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00493e35: { // 0x493e35: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00493e37: { // 0x493e37: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00493e39: { // 0x493e39: f7d0 NOT EAX
    s.ax = (~(s.ax)&integer::mask(32));
  }
  L00493e3b: { // 0x493e3b: bf04000000 MOV EDI,0x4
    s.di = 0x00000004u;
  }
  L00493e40: { // 0x493e40: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00493e42: { // 0x493e42: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00493e44: { // 0x493e44: 8a19 MOV BL,byte ptr [ECX]
    s.bx = with_al(s.bx, m.r8((s.cx)));
  }
  L00493e46: { // 0x493e46: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00493e4c: { // 0x493e4c: 33d3 XOR EDX,EBX
    s.dx = integer::logical((s.dx)^(s.bx),32,flags);
  }
  L00493e4e: { // 0x493e4e: c1e808 SHR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::right);
  }
  L00493e51: { // 0x493e51: 8b149534067c00 MOV EDX,dword ptr [EDX*0x4 + 0x7c0634]
    s.dx = m.r32(((s.dx * 0x00000004u)+0x007c0634u));
  }
  L00493e58: { // 0x493e58: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L00493e5a: { // 0x493e5a: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00493e5b: { // 0x493e5b: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L00493e5c: { // 0x493e5c: 75e2 JNZ 0x00493e40
    if(integer::condition("JNZ",flags)) goto L00493e40;
  }
  L00493e5e: { // 0x493e5e: f7d0 NOT EAX
    s.ax = (~(s.ax)&integer::mask(32));
  }
  L00493e60: { // 0x493e60: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  L00493e62: { // 0x493e62: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00493e66: { // 0x493e66: 83c504 ADD EBP,0x4
    s.bp = integer::add(s.bp,0x00000004u,32,flags);
  }
  L00493e69: { // 0x493e69: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00493e6a: { // 0x493e6a: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00493e6e: { // 0x493e6e: 75c5 JNZ 0x00493e35
    if(integer::condition("JNZ",flags)) goto L00493e35;
  }
  L00493e70: { // 0x493e70: 8b7c2418 MOV EDI,dword ptr [ESP + 0x18]
    s.di = m.r32((f.sp+0x00000018u));
  }
  L00493e74: { // 0x493e74: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00493e76: { // 0x493e76: 3bfb CMP EDI,EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  L00493e78: { // 0x493e78: 0f8e82000000 JLE 0x00493f00
    if(integer::condition("JLE",flags)) goto L00493f00;
  }
  L00493e7e: { // 0x493e7e: 897c2414 MOV dword ptr [ESP + 0x14],EDI
    m.w32((f.sp+0x00000014u), s.di);
  }
  L00493e82: { // 0x493e82: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L00493e85: { // 0x493e85: 8a4d00 MOV CL,byte ptr [EBP]
    s.cx = with_al(s.cx, m.r8((s.bp)));
  }
  L00493e88: { // 0x493e88: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00493e8a: { // 0x493e8a: 7503 JNZ 0x00493e8f
    if(integer::condition("JNZ",flags)) goto L00493e8f;
  }
  L00493e8c: { // 0x493e8c: 895e08 MOV dword ptr [ESI + 0x8],EBX
    m.w32((s.si+0x00000008u), s.bx);
  }
  L00493e8f: { // 0x493e8f: 884c3008 MOV byte ptr [EAX + ESI*0x1 + 0x8],CL
    m.w8((s.ax+(s.si * 0x00000001u)+0x00000008u), (s.cx & 0xffu));
  }
  L00493e93: { // 0x493e93: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  L00493e96: { // 0x493e96: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00493e97: { // 0x493e97: bf04000000 MOV EDI,0x4
    s.di = 0x00000004u;
  }
  L00493e9c: { // 0x493e9c: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00493e9e: { // 0x493e9e: 894e04 MOV dword ptr [ESI + 0x4],ECX
    m.w32((s.si+0x00000004u), s.cx);
  }
  L00493ea1: { // 0x493ea1: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L00493ea3: { // 0x493ea3: 754f JNZ 0x00493ef4
    if(integer::condition("JNZ",flags)) goto L00493ef4;
  }
  L00493ea5: { // 0x493ea5: 8ac1 MOV AL,CL
    s.ax = with_al(s.ax, (s.cx & 0xffu));
  }
  L00493ea7: { // 0x493ea7: 88460c MOV byte ptr [ESI + 0xc],AL
    m.w8((s.si+0x0000000cu), (s.ax & 0xffu));
  }
  L00493eaa: { // 0x493eaa: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L00493ead: { // 0x493ead: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00493eae: { // 0x493eae: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L00493eb0: { // 0x493eb0: 730c JNC 0x00493ebe
    if(integer::condition("JNC",flags)) goto L00493ebe;
  }
  L00493eb2: { // 0x493eb2: 8a4e08 MOV CL,byte ptr [ESI + 0x8]
    s.cx = with_al(s.cx, m.r8((s.si+0x00000008u)));
  }
  L00493eb5: { // 0x493eb5: 884c0608 MOV byte ptr [ESI + EAX*0x1 + 0x8],CL
    m.w8((s.si+(s.ax * 0x00000001u)+0x00000008u), (s.cx & 0xffu));
  }
  L00493eb9: { // 0x493eb9: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00493eba: { // 0x493eba: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L00493ebc: { // 0x493ebc: 72f4 JC 0x00493eb2
    if(integer::condition("JC",flags)) goto L00493eb2;
  }
  L00493ebe: { // 0x493ebe: 8b5608 MOV EDX,dword ptr [ESI + 0x8]
    s.dx = m.r32((s.si+0x00000008u));
  }
  L00493ec1: { // 0x493ec1: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00493ec3: { // 0x493ec3: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L00493ec7: { // 0x493ec7: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L00493ecb: { // 0x493ecb: f7d0 NOT EAX
    s.ax = (~(s.ax)&integer::mask(32));
  }
  L00493ecd: { // 0x493ecd: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00493ecf: { // 0x493ecf: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00493ed1: { // 0x493ed1: 8a19 MOV BL,byte ptr [ECX]
    s.bx = with_al(s.bx, m.r8((s.cx)));
  }
  L00493ed3: { // 0x493ed3: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00493ed9: { // 0x493ed9: 33d3 XOR EDX,EBX
    s.dx = integer::logical((s.dx)^(s.bx),32,flags);
  }
  L00493edb: { // 0x493edb: c1e808 SHR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::right);
  }
  L00493ede: { // 0x493ede: 8b149534067c00 MOV EDX,dword ptr [EDX*0x4 + 0x7c0634]
    s.dx = m.r32(((s.dx * 0x00000004u)+0x007c0634u));
  }
  L00493ee5: { // 0x493ee5: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L00493ee7: { // 0x493ee7: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00493ee8: { // 0x493ee8: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L00493ee9: { // 0x493ee9: 75e2 JNZ 0x00493ecd
    if(integer::condition("JNZ",flags)) goto L00493ecd;
  }
  L00493eeb: { // 0x493eeb: f7d0 NOT EAX
    s.ax = (~(s.ax)&integer::mask(32));
  }
  L00493eed: { // 0x493eed: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00493eef: { // 0x493eef: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  L00493ef1: { // 0x493ef1: 895e04 MOV dword ptr [ESI + 0x4],EBX
    m.w32((s.si+0x00000004u), s.bx);
  }
  L00493ef4: { // 0x493ef4: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00493ef8: { // 0x493ef8: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L00493ef9: { // 0x493ef9: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00493efa: { // 0x493efa: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00493efe: { // 0x493efe: 7582 JNZ 0x00493e82
    if(integer::condition("JNZ",flags)) goto L00493e82;
  }
  L00493f00: { // 0x493f00: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L00493f03: { // 0x493f03: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00493f05: { // 0x493f05: 7459 JZ 0x00493f60
    if(integer::condition("JZ",flags)) goto L00493f60;
  }
  L00493f07: { // 0x493f07: 8ac8 MOV CL,AL
    s.cx = with_al(s.cx, (s.ax & 0xffu));
  }
  L00493f09: { // 0x493f09: 884c3008 MOV byte ptr [EAX + ESI*0x1 + 0x8],CL
    m.w8((s.ax+(s.si * 0x00000001u)+0x00000008u), (s.cx & 0xffu));
  }
  L00493f0d: { // 0x493f0d: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L00493f10: { // 0x493f10: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00493f11: { // 0x493f11: 83f804 CMP EAX,0x4
    (void)integer::sub(s.ax,0x00000004u,32,flags);
  }
  L00493f14: { // 0x493f14: 730d JNC 0x00493f23
    if(integer::condition("JNC",flags)) goto L00493f23;
  }
  L00493f16: { // 0x493f16: 8a5608 MOV DL,byte ptr [ESI + 0x8]
    s.dx = with_al(s.dx, m.r8((s.si+0x00000008u)));
  }
  L00493f19: { // 0x493f19: 88540608 MOV byte ptr [ESI + EAX*0x1 + 0x8],DL
    m.w8((s.si+(s.ax * 0x00000001u)+0x00000008u), (s.dx & 0xffu));
  }
  L00493f1d: { // 0x493f1d: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00493f1e: { // 0x493f1e: 83f804 CMP EAX,0x4
    (void)integer::sub(s.ax,0x00000004u,32,flags);
  }
  L00493f21: { // 0x493f21: 72f3 JC 0x00493f16
    if(integer::condition("JC",flags)) goto L00493f16;
  }
  L00493f23: { // 0x493f23: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L00493f26: { // 0x493f26: 8b36 MOV ESI,dword ptr [ESI]
    s.si = m.r32((s.si));
  }
  L00493f28: { // 0x493f28: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00493f2c: { // 0x493f2c: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L00493f30: { // 0x493f30: f7d6 NOT ESI
    s.si = (~(s.si)&integer::mask(32));
  }
  L00493f32: { // 0x493f32: b904000000 MOV ECX,0x4
    s.cx = 0x00000004u;
  }
  L00493f37: { // 0x493f37: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L00493f39: { // 0x493f39: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00493f3b: { // 0x493f3b: 8a18 MOV BL,byte ptr [EAX]
    s.bx = with_al(s.bx, m.r8((s.ax)));
  }
  L00493f3d: { // 0x493f3d: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00493f43: { // 0x493f43: 33d3 XOR EDX,EBX
    s.dx = integer::logical((s.dx)^(s.bx),32,flags);
  }
  L00493f45: { // 0x493f45: c1ee08 SHR ESI,0x8
    s.si = integer::shift(s.si,0x00000008u,32,flags,integer::Shift::right);
  }
  L00493f48: { // 0x493f48: 8b149534067c00 MOV EDX,dword ptr [EDX*0x4 + 0x7c0634]
    s.dx = m.r32(((s.dx * 0x00000004u)+0x007c0634u));
  }
  L00493f4f: { // 0x493f4f: 33f2 XOR ESI,EDX
    s.si = integer::logical((s.si)^(s.dx),32,flags);
  }
  L00493f51: { // 0x493f51: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00493f52: { // 0x493f52: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00493f53: { // 0x493f53: 75e2 JNZ 0x00493f37
    if(integer::condition("JNZ",flags)) goto L00493f37;
  }
  L00493f55: { // 0x493f55: f7d6 NOT ESI
    s.si = (~(s.si)&integer::mask(32));
  }
  L00493f57: { // 0x493f57: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00493f59: { // 0x493f59: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00493f5a: { // 0x493f5a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00493f5b: { // 0x493f5b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00493f5c: { // 0x493f5c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00493f5d: { // 0x493f5d: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L00493f60: { // 0x493f60: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00493f62: { // 0x493f62: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00493f63: { // 0x493f63: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00493f64: { // 0x493f64: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00493f65: { // 0x493f65: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00493f66: { // 0x493f66: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4223728u:f_000072f0(m,s,child,{});break;
case 4223760u:f_00007310(m,s,child,{});break;
case 4799904u:f_00093da0(m,s,child,{});break;
default:throw std::domain_error("recovery122 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00408210(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00408210: { // 0x408210: a16c988100 MOV EAX,[0x0081986c]
    s.ax = m.r32((0x0081986cu));
  }
  L00408215: { // 0x408215: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00408216: { // 0x408216: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00408218: { // 0x408218: 0f8487000000 JZ 0x004082a5
    if(integer::condition("JZ",flags)) goto L004082a5;
  }
  L0040821e: { // 0x40821e: b960988100 MOV ECX,0x819860
    s.cx = 0x00819860u;
  }
  L00408223: { // 0x408223: e8c8f0ffff CALL 0x004072f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004072f0u,4227624u); flags=s.arithmetic_flags;
  }
  L00408228: { // 0x408228: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0040822a: { // 0x40822a: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0040822c: { // 0x40822c: 7477 JZ 0x004082a5
    if(integer::condition("JZ",flags)) goto L004082a5;
  }
  L0040822e: { // 0x40822e: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0040822f: { // 0x40822f: 8b2de0517800 MOV EBP,dword ptr [0x007851e0]
    s.bp = m.r32((0x007851e0u));
  }
  L00408235: { // 0x408235: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00408236: { // 0x408236: 8b3ddc517800 MOV EDI,dword ptr [0x007851dc]
    s.di = m.r32((0x007851dcu));
  }
  L0040823c: { // 0x40823c: 8b8680000000 MOV EAX,dword ptr [ESI + 0x80]
    s.ax = m.r32((s.si+0x00000080u));
  }
  L00408242: { // 0x408242: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00408244: { // 0x408244: 7450 JZ 0x00408296
    if(integer::condition("JZ",flags)) goto L00408296;
  }
  L00408246: { // 0x408246: 8b8680000000 MOV EAX,dword ptr [ESI + 0x80]
    s.ax = m.r32((s.si+0x00000080u));
  }
  L0040824c: { // 0x40824c: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0040824d: { // 0x40824d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0040824f: { // 0x40824f: 898680000000 MOV dword ptr [ESI + 0x80],EAX
    m.w32((s.si+0x00000080u), s.ax);
  }
  L00408255: { // 0x408255: 7d0a JGE 0x00408261
    if(integer::condition("JGE",flags)) goto L00408261;
  }
  L00408257: { // 0x408257: c7868000000000000000 MOV dword ptr [ESI + 0x80],0x0
    m.w32((s.si+0x00000080u), 0x00000000u);
  }
  L00408261: { // 0x408261: 8b8680000000 MOV EAX,dword ptr [ESI + 0x80]
    s.ax = m.r32((s.si+0x00000080u));
  }
  L00408267: { // 0x408267: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00408269: { // 0x408269: 752b JNZ 0x00408296
    if(integer::condition("JNZ",flags)) goto L00408296;
  }
  L0040826b: { // 0x40826b: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  L0040826e: { // 0x40826e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00408270: { // 0x408270: 7424 JZ 0x00408296
    if(integer::condition("JZ",flags)) goto L00408296;
  }
  L00408272: { // 0x408272: 6848988100 PUSH 0x819848
    f.push(m,0x00819848u);
  }
  L00408277: { // 0x408277: ffd7 CALL EDI
    s.arithmetic_flags=flags; invoke(m,s,f,s.di,4227705u); flags=s.arithmetic_flags;
  }
  L00408279: { // 0x408279: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  L0040827c: { // 0x40827c: a802 TEST AL,0x2
    (void)integer::logical(((s.ax & 0xffu))&(0x00000002u),8,flags);
  }
  L0040827e: { // 0x40827e: 7407 JZ 0x00408287
    if(integer::condition("JZ",flags)) goto L00408287;
  }
  L00408280: { // 0x408280: 24fd AND AL,0xfd
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000fdu),8,flags));
  }
  L00408282: { // 0x408282: 0c01 OR AL,0x1
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000001u),8,flags));
  }
  L00408284: { // 0x408284: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  L00408287: { // 0x408287: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx = m.r32((s.si+0x00000014u));
  }
  L0040828a: { // 0x40828a: e8c1a3ffff CALL 0x00402650
    s.arithmetic_flags=flags; invoke(m,s,f,0x00402650u,4227727u); flags=s.arithmetic_flags;
  }
  L0040828f: { // 0x40828f: 6848988100 PUSH 0x819848
    f.push(m,0x00819848u);
  }
  L00408294: { // 0x408294: ffd5 CALL EBP
    s.arithmetic_flags=flags; invoke(m,s,f,s.bp,4227734u); flags=s.arithmetic_flags;
  }
  L00408296: { // 0x408296: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00408298: { // 0x408298: e873f0ffff CALL 0x00407310
    s.arithmetic_flags=flags; invoke(m,s,f,0x00407310u,4227741u); flags=s.arithmetic_flags;
  }
  L0040829d: { // 0x40829d: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0040829f: { // 0x40829f: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L004082a1: { // 0x4082a1: 7599 JNZ 0x0040823c
    if(integer::condition("JNZ",flags)) goto L0040823c;
  }
  L004082a3: { // 0x4082a3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004082a4: { // 0x4082a4: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004082a5: { // 0x4082a5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004082a6: { // 0x4082a6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_0046bdc0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0046bdc0: { // 0x46bdc0: 81ec8c000000 SUB ESP,0x8c
    f.sp = integer::sub(f.sp,0x0000008cu,32,flags);
  }
  L0046bdc6: { // 0x46bdc6: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0046bdc7: { // 0x46bdc7: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0046bdc8: { // 0x46bdc8: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0046bdca: { // 0x46bdca: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0046bdcc: { // 0x46bdcc: 385e38 CMP byte ptr [ESI + 0x38],BL
    (void)integer::sub(m.r8((s.si+0x00000038u)),(s.bx & 0xffu),8,flags);
  }
  L0046bdcf: { // 0x46bdcf: 7568 JNZ 0x0046be39
    if(integer::condition("JNZ",flags)) goto L0046be39;
  }
  L0046bdd1: { // 0x46bdd1: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L0046bdd5: { // 0x46bdd5: 895c2418 MOV dword ptr [ESP + 0x18],EBX
    m.w32((f.sp+0x00000018u), s.bx);
  }
  L0046bdd9: { // 0x46bdd9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0046bdda: { // 0x46bdda: 895c2420 MOV dword ptr [ESP + 0x20],EBX
    m.w32((f.sp+0x00000020u), s.bx);
  }
  L0046bdde: { // 0x46bdde: 885c2424 MOV byte ptr [ESP + 0x24],BL
    m.w8((f.sp+0x00000024u), (s.bx & 0xffu));
  }
  L0046bde2: { // 0x46bde2: 895c2450 MOV dword ptr [ESP + 0x50],EBX
    m.w32((f.sp+0x00000050u), s.bx);
  }
  L0046bde6: { // 0x46bde6: 895c2454 MOV dword ptr [ESP + 0x54],EBX
    m.w32((f.sp+0x00000054u), s.bx);
  }
  L0046bdea: { // 0x46bdea: c744243c01234567 MOV dword ptr [ESP + 0x3c],0x67452301
    m.w32((f.sp+0x0000003cu), 0x67452301u);
  }
  L0046bdf2: { // 0x46bdf2: c744244089abcdef MOV dword ptr [ESP + 0x40],0xefcdab89
    m.w32((f.sp+0x00000040u), 0xefcdab89u);
  }
  L0046bdfa: { // 0x46bdfa: c7442444fedcba98 MOV dword ptr [ESP + 0x44],0x98badcfe
    m.w32((f.sp+0x00000044u), 0x98badcfeu);
  }
  L0046be02: { // 0x46be02: c744244876543210 MOV dword ptr [ESP + 0x48],0x10325476
    m.w32((f.sp+0x00000048u), 0x10325476u);
  }
  L0046be0a: { // 0x46be0a: c744244cf0e1d2c3 MOV dword ptr [ESP + 0x4c],0xc3d2e1f0
    m.w32((f.sp+0x0000004cu), 0xc3d2e1f0u);
  }
  L0046be12: { // 0x46be12: c744241894897800 MOV dword ptr [ESP + 0x18],0x788994
    m.w32((f.sp+0x00000018u), 0x00788994u);
  }
  L0046be1a: { // 0x46be1a: e851fc0900 CALL 0x0050ba70
    s.arithmetic_flags=flags; invoke(m,s,f,0x0050ba70u,4636191u); flags=s.arithmetic_flags;
  }
  L0046be1f: { // 0x46be1f: 8d4e39 LEA ECX,[ESI + 0x39]
    s.cx = (s.si+0x00000039u);
  }
  L0046be22: { // 0x46be22: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0046be23: { // 0x46be23: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0046be27: { // 0x46be27: e804ef1f00 CALL 0x0066ad30
    s.arithmetic_flags=flags; invoke(m,s,f,0x0066ad30u,4636204u); flags=s.arithmetic_flags;
  }
  L0046be2c: { // 0x46be2c: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L0046be30: { // 0x46be30: c6463801 MOV byte ptr [ESI + 0x38],0x1
    m.w8((s.si+0x00000038u), 0x00000001u);
  }
  L0046be34: { // 0x46be34: e807a81900 CALL 0x00606640
    s.arithmetic_flags=flags; invoke(m,s,f,0x00606640u,4636217u); flags=s.arithmetic_flags;
  }
  L0046be39: { // 0x46be39: 83c639 ADD ESI,0x39
    s.si = integer::add(s.si,0x00000039u,32,flags);
  }
  L0046be3c: { // 0x46be3c: 6a14 PUSH 0x14
    f.push(m,0x00000014u);
  }
  L0046be3e: { // 0x46be3e: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0046be3f: { // 0x46be3f: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L0046be43: { // 0x46be43: 895c2410 MOV dword ptr [ESP + 0x10],EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
  L0046be47: { // 0x46be47: 895c2414 MOV dword ptr [ESP + 0x14],EBX
    m.w32((f.sp+0x00000014u), s.bx);
  }
  L0046be4b: { // 0x46be4b: 895c2418 MOV dword ptr [ESP + 0x18],EBX
    m.w32((f.sp+0x00000018u), s.bx);
  }
  L0046be4f: { // 0x46be4f: e84c7f0200 CALL 0x00493da0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493da0u,4636244u); flags=s.arithmetic_flags;
  }
  L0046be54: { // 0x46be54: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0046be55: { // 0x46be55: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0046be56: { // 0x46be56: 81c48c000000 ADD ESP,0x8c
    f.sp = integer::add(f.sp,0x0000008cu,32,flags);
  }
  L0046be5c: { // 0x46be5c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
