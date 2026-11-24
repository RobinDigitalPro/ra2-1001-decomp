#include "recovered/recovery_b1645.hpp"
#include "recovered/recovery_b566_machine.hpp"
#include <array>
#include <cstdint>
#include <stdexcept>
namespace ra2::recovered::b1645 {
namespace {
using namespace floating_b61;
using State=recovery_b566::State;
using Frame=recovery_b566::Frame;
using recovery_b566::finish;
using recovery_b566::string_instruction;
using recovery_b566::Kind;
using recovery_b566::Repeat;
using recovery_b566::reverse_divide32;
using recovery_b566::reverse_divide64;
namespace integer=direct_b33::integer;
inline void need(bool ok,const char*s){if(!ok)throw std::domain_error(s);}
struct Operations{Api*api;};
// Private methods only; parent supplies reviewed Operations/invoke and B566 aliases.
// No entry wrapper, no assumption of unchanged caller words, no sqrt substitute.
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t,const Operations&);
void f_000adb10(Memory&,State&,Frame&,const Operations&);
void f_00011230(Memory&,State&,Frame&,const Operations&);
void f_00361c80(Memory&,State&,Frame&,const Operations&);
void f_000ae5e0(Memory&,State&,Frame&,const Operations&);
void f_00011290(Memory&,State&,Frame&,const Operations&);
void f_000112c0(Memory&,State&,Frame&,const Operations&);
void f_000112f0(Memory&,State&,Frame&,const Operations&);
void f_00011370(Memory&,State&,Frame&,const Operations&);
void f_000113b0(Memory&,State&,Frame&,const Operations&);
void f_000113c0(Memory&,State&,Frame&,const Operations&);
void f_0001fdf0(Memory&,State&,Frame&,const Operations&);
void f_00360f60(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);

void f_000adb10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004adb10: { // 0x4adb10: 83ec6c SUB ESP,0x6c
    f.sp = integer::sub(f.sp,0x0000006cu,32,flags);
  }
  L004adb13: { // 0x4adb13: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004adb14: { // 0x4adb14: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004adb15: { // 0x4adb15: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004adb16: { // 0x4adb16: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004adb17: { // 0x4adb17: 8bbc248c000000 MOV EDI,dword ptr [ESP + 0x8c]
    s.di = m.r32((f.sp+0x0000008cu));
  }
  L004adb1e: { // 0x4adb1e: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004adb20: { // 0x4adb20: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004adb22: { // 0x4adb22: 8a07 MOV AL,byte ptr [EDI]
    s.ax = with_al(s.ax, m.r8((s.di)));
  }
  L004adb24: { // 0x4adb24: 89742434 MOV dword ptr [ESP + 0x34],ESI
    m.w32((f.sp+0x00000034u), s.si);
  }
  L004adb28: { // 0x4adb28: 8984248c000000 MOV dword ptr [ESP + 0x8c],EAX
    m.w32((f.sp+0x0000008cu), s.ax);
  }
  L004adb2f: { // 0x4adb2f: db84248c000000 FILD dword ptr [ESP + 0x8c]
    const auto address=(f.sp+0x0000008cu);
    s.fp.load_integer32(m.r32(address));
  }
  L004adb36: { // 0x4adb36: d88c2490000000 FMUL float ptr [ESP + 0x90]
    const auto address=(f.sp+0x00000090u);
    s.fp.multiply32(m.r32(address));
  }
  L004adb3d: { // 0x4adb3d: e80ecf2b00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4905794u,op); flags=s.arithmetic_flags;
  }
  L004adb42: { // 0x4adb42: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L004adb44: { // 0x4adb44: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L004adb46: { // 0x4adb46: 8a4f01 MOV CL,byte ptr [EDI + 0x1]
    s.cx = with_al(s.cx, m.r8((s.di+0x00000001u)));
  }
  L004adb49: { // 0x4adb49: 895c2430 MOV dword ptr [ESP + 0x30],EBX
    m.w32((f.sp+0x00000030u), s.bx);
  }
  L004adb4d: { // 0x4adb4d: 898c248c000000 MOV dword ptr [ESP + 0x8c],ECX
    m.w32((f.sp+0x0000008cu), s.cx);
  }
  L004adb54: { // 0x4adb54: db84248c000000 FILD dword ptr [ESP + 0x8c]
    const auto address=(f.sp+0x0000008cu);
    s.fp.load_integer32(m.r32(address));
  }
  L004adb5b: { // 0x4adb5b: d88c2490000000 FMUL float ptr [ESP + 0x90]
    const auto address=(f.sp+0x00000090u);
    s.fp.multiply32(m.r32(address));
  }
  L004adb62: { // 0x4adb62: e8e9ce2b00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4905831u,op); flags=s.arithmetic_flags;
  }
  L004adb67: { // 0x4adb67: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L004adb69: { // 0x4adb69: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L004adb6b: { // 0x4adb6b: 8a5702 MOV DL,byte ptr [EDI + 0x2]
    s.dx = with_al(s.dx, m.r8((s.di+0x00000002u)));
  }
  L004adb6e: { // 0x4adb6e: 896c242c MOV dword ptr [ESP + 0x2c],EBP
    m.w32((f.sp+0x0000002cu), s.bp);
  }
  L004adb72: { // 0x4adb72: 8994248c000000 MOV dword ptr [ESP + 0x8c],EDX
    m.w32((f.sp+0x0000008cu), s.dx);
  }
  L004adb79: { // 0x4adb79: db84248c000000 FILD dword ptr [ESP + 0x8c]
    const auto address=(f.sp+0x0000008cu);
    s.fp.load_integer32(m.r32(address));
  }
  L004adb80: { // 0x4adb80: d88c2490000000 FMUL float ptr [ESP + 0x90]
    const auto address=(f.sp+0x00000090u);
    s.fp.multiply32(m.r32(address));
  }
  L004adb87: { // 0x4adb87: e8c4ce2b00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4905868u,op); flags=s.arithmetic_flags;
  }
  L004adb8c: { // 0x4adb8c: 83fb08 CMP EBX,0x8
    (void)integer::sub(s.bx,0x00000008u,32,flags);
  }
  L004adb8f: { // 0x4adb8f: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L004adb93: { // 0x4adb93: 7d0e JGE 0x004adba3
    if(integer::condition("JGE",flags)) goto L004adba3;
  }
  L004adb95: { // 0x4adb95: 83fd08 CMP EBP,0x8
    (void)integer::sub(s.bp,0x00000008u,32,flags);
  }
  L004adb98: { // 0x4adb98: 7d09 JGE 0x004adba3
    if(integer::condition("JGE",flags)) goto L004adba3;
  }
  L004adb9a: { // 0x4adb9a: 83f808 CMP EAX,0x8
    (void)integer::sub(s.ax,0x00000008u,32,flags);
  }
  L004adb9d: { // 0x4adb9d: 0f8c230a0000 JL 0x004ae5c6
    if(integer::condition("JL",flags)) goto L004ae5c6;
  }
  L004adba3: { // 0x4adba3: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004adba5: { // 0x4adba5: 8d4c244c LEA ECX,[ESP + 0x4c]
    s.cx = (f.sp+0x0000004cu);
  }
  L004adba9: { // 0x4adba9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004adbaa: { // 0x4adbaa: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004adbac: { // 0x4adbac: ff5078 CALL dword ptr [EAX + 0x78]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000078u)),4905903u,op); flags=s.arithmetic_flags;
  }
  L004adbaf: { // 0x4adbaf: 8b942480000000 MOV EDX,dword ptr [ESP + 0x80]
    s.dx = m.r32((f.sp+0x00000080u));
  }
  L004adbb6: { // 0x4adbb6: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L004adbb8: { // 0x4adbb8: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L004adbba: { // 0x4adbba: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004adbbb: { // 0x4adbbb: 8d4c2448 LEA ECX,[ESP + 0x48]
    s.cx = (f.sp+0x00000048u);
  }
  L004adbbf: { // 0x4adbbf: e82c22f7ff CALL 0x0041fdf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041fdf0u,4905924u,op); flags=s.arithmetic_flags;
  }
  L004adbc4: { // 0x4adbc4: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L004adbc6: { // 0x4adbc6: 8b32 MOV ESI,dword ptr [EDX]
    s.si = m.r32((s.dx));
  }
  L004adbc8: { // 0x4adbc8: 8974246c MOV dword ptr [ESP + 0x6c],ESI
    m.w32((f.sp+0x0000006cu), s.si);
  }
  L004adbcc: { // 0x4adbcc: 8b7a04 MOV EDI,dword ptr [EDX + 0x4]
    s.di = m.r32((s.dx+0x00000004u));
  }
  L004adbcf: { // 0x4adbcf: 897c2470 MOV dword ptr [ESP + 0x70],EDI
    m.w32((f.sp+0x00000070u), s.di);
  }
  L004adbd3: { // 0x4adbd3: 8b4208 MOV EAX,dword ptr [EDX + 0x8]
    s.ax = m.r32((s.dx+0x00000008u));
  }
  L004adbd6: { // 0x4adbd6: 89442474 MOV dword ptr [ESP + 0x74],EAX
    m.w32((f.sp+0x00000074u), s.ax);
  }
  L004adbda: { // 0x4adbda: 8b4a0c MOV ECX,dword ptr [EDX + 0xc]
    s.cx = m.r32((s.dx+0x0000000cu));
  }
  L004adbdd: { // 0x4adbdd: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004adbdf: { // 0x4adbdf: 894c2478 MOV dword ptr [ESP + 0x78],ECX
    m.w32((f.sp+0x00000078u), s.cx);
  }
  L004adbe3: { // 0x4adbe3: 7508 JNZ 0x004adbed
    if(integer::condition("JNZ",flags)) goto L004adbed;
  }
  L004adbe5: { // 0x4adbe5: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004adbe7: { // 0x4adbe7: 0f84d9090000 JZ 0x004ae5c6
    if(integer::condition("JZ",flags)) goto L004ae5c6;
  }
  L004adbed: { // 0x4adbed: 8b8c2484000000 MOV ECX,dword ptr [ESP + 0x84]
    s.cx = m.r32((f.sp+0x00000084u));
  }
  L004adbf4: { // 0x4adbf4: 8bac2488000000 MOV EBP,dword ptr [ESP + 0x88]
    s.bp = m.r32((f.sp+0x00000088u));
  }
  L004adbfb: { // 0x4adbfb: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L004adbfd: { // 0x4adbfd: 8b5104 MOV EDX,dword ptr [ECX + 0x4]
    s.dx = m.r32((s.cx+0x00000004u));
  }
  L004adc00: { // 0x4adc00: 8b4d00 MOV ECX,dword ptr [EBP]
    s.cx = m.r32((s.bp));
  }
  L004adc03: { // 0x4adc03: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L004adc05: { // 0x4adc05: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L004adc07: { // 0x4adc07: 8b7504 MOV ESI,dword ptr [EBP + 0x4]
    s.si = m.r32((s.bp+0x00000004u));
  }
  L004adc0a: { // 0x4adc0a: 8bac2494000000 MOV EBP,dword ptr [ESP + 0x94]
    s.bp = m.r32((f.sp+0x00000094u));
  }
  L004adc11: { // 0x4adc11: 03d7 ADD EDX,EDI
    s.dx = integer::add(s.dx,s.di,32,flags);
  }
  L004adc13: { // 0x4adc13: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L004adc15: { // 0x4adc15: 03f7 ADD ESI,EDI
    s.si = integer::add(s.si,s.di,32,flags);
  }
  L004adc17: { // 0x4adc17: 8bbc2498000000 MOV EDI,dword ptr [ESP + 0x98]
    s.di = m.r32((f.sp+0x00000098u));
  }
  L004adc1e: { // 0x4adc1e: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L004adc20: { // 0x4adc20: 895c245c MOV dword ptr [ESP + 0x5c],EBX
    m.w32((f.sp+0x0000005cu), s.bx);
  }
  L004adc24: { // 0x4adc24: 89542460 MOV dword ptr [ESP + 0x60],EDX
    m.w32((f.sp+0x00000060u), s.dx);
  }
  L004adc28: { // 0x4adc28: 894c2464 MOV dword ptr [ESP + 0x64],ECX
    m.w32((f.sp+0x00000064u), s.cx);
  }
  L004adc2c: { // 0x4adc2c: 89742468 MOV dword ptr [ESP + 0x68],ESI
    m.w32((f.sp+0x00000068u), s.si);
  }
  L004adc30: { // 0x4adc30: 7e1b JLE 0x004adc4d
    if(integer::condition("JLE",flags)) goto L004adc4d;
  }
  L004adc32: { // 0x4adc32: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L004adc34: { // 0x4adc34: 8bef MOV EBP,EDI
    s.bp = s.di;
  }
  L004adc36: { // 0x4adc36: 8bbc2494000000 MOV EDI,dword ptr [ESP + 0x94]
    s.di = m.r32((f.sp+0x00000094u));
  }
  L004adc3d: { // 0x4adc3d: 895c245c MOV dword ptr [ESP + 0x5c],EBX
    m.w32((f.sp+0x0000005cu), s.bx);
  }
  L004adc41: { // 0x4adc41: 89742460 MOV dword ptr [ESP + 0x60],ESI
    m.w32((f.sp+0x00000060u), s.si);
  }
  L004adc45: { // 0x4adc45: 89442464 MOV dword ptr [ESP + 0x64],EAX
    m.w32((f.sp+0x00000064u), s.ax);
  }
  L004adc49: { // 0x4adc49: 89542468 MOV dword ptr [ESP + 0x68],EDX
    m.w32((f.sp+0x00000068u), s.dx);
  }
  L004adc4d: { // 0x4adc4d: 8b4c2468 MOV ECX,dword ptr [ESP + 0x68]
    s.cx = m.r32((f.sp+0x00000068u));
  }
  L004adc51: { // 0x4adc51: 8b442464 MOV EAX,dword ptr [ESP + 0x64]
    s.ax = m.r32((f.sp+0x00000064u));
  }
  L004adc55: { // 0x4adc55: 8d54246c LEA EDX,[ESP + 0x6c]
    s.dx = (f.sp+0x0000006cu);
  }
  L004adc59: { // 0x4adc59: 894c2450 MOV dword ptr [ESP + 0x50],ECX
    m.w32((f.sp+0x00000050u), s.cx);
  }
  L004adc5d: { // 0x4adc5d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004adc5e: { // 0x4adc5e: 8bf3 MOV ESI,EBX
    s.si = s.bx;
  }
  L004adc60: { // 0x4adc60: 8b5c2464 MOV EBX,dword ptr [ESP + 0x64]
    s.bx = m.r32((f.sp+0x00000064u));
  }
  L004adc64: { // 0x4adc64: 8d542468 LEA EDX,[ESP + 0x68]
    s.dx = (f.sp+0x00000068u);
  }
  L004adc68: { // 0x4adc68: 8d4c2460 LEA ECX,[ESP + 0x60]
    s.cx = (f.sp+0x00000060u);
  }
  L004adc6c: { // 0x4adc6c: 89442450 MOV dword ptr [ESP + 0x50],EAX
    m.w32((f.sp+0x00000050u), s.ax);
  }
  L004adc70: { // 0x4adc70: e8eb322b00 CALL 0x00760f60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00760f60u,4906101u,op); flags=s.arithmetic_flags;
  }
  L004adc75: { // 0x4adc75: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004adc77: { // 0x4adc77: 0f8449090000 JZ 0x004ae5c6
    if(integer::condition("JZ",flags)) goto L004ae5c6;
  }
  L004adc7d: { // 0x4adc7d: 8b442464 MOV EAX,dword ptr [ESP + 0x64]
    s.ax = m.r32((f.sp+0x00000064u));
  }
  L004adc81: { // 0x4adc81: 8b4c244c MOV ECX,dword ptr [ESP + 0x4c]
    s.cx = m.r32((f.sp+0x0000004cu));
  }
  L004adc85: { // 0x4adc85: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L004adc87: { // 0x4adc87: 8b4c2468 MOV ECX,dword ptr [ESP + 0x68]
    s.cx = m.r32((f.sp+0x00000068u));
  }
  L004adc8b: { // 0x4adc8b: 89bc2494000000 MOV dword ptr [ESP + 0x94],EDI
    m.w32((f.sp+0x00000094u), s.di);
  }
  L004adc92: { // 0x4adc92: 89ac2490000000 MOV dword ptr [ESP + 0x90],EBP
    m.w32((f.sp+0x00000090u), s.bp);
  }
  L004adc99: { // 0x4adc99: 750a JNZ 0x004adca5
    if(integer::condition("JNZ",flags)) goto L004adca5;
  }
  L004adc9b: { // 0x4adc9b: 3b4c2450 CMP ECX,dword ptr [ESP + 0x50]
    (void)integer::sub(s.cx,m.r32((f.sp+0x00000050u)),32,flags);
  }
  L004adc9f: { // 0x4adc9f: 0f84d0000000 JZ 0x004add75
    if(integer::condition("JZ",flags)) goto L004add75;
  }
  L004adca5: { // 0x4adca5: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L004adca7: { // 0x4adca7: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L004adcaa: { // 0x4adcaa: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L004adcac: { // 0x4adcac: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L004adcae: { // 0x4adcae: 89542444 MOV dword ptr [ESP + 0x44],EDX
    m.w32((f.sp+0x00000044u), s.dx);
  }
  L004adcb2: { // 0x4adcb2: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L004adcb4: { // 0x4adcb4: db442444 FILD dword ptr [ESP + 0x44]
    const auto address=(f.sp+0x00000044u);
    s.fp.load_integer32(m.r32(address));
  }
  L004adcb8: { // 0x4adcb8: 89442448 MOV dword ptr [ESP + 0x48],EAX
    m.w32((f.sp+0x00000048u), s.ax);
  }
  L004adcbc: { // 0x4adcbc: db442448 FILD dword ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    s.fp.load_integer32(m.r32(address));
  }
  L004adcc0: { // 0x4adcc0: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L004adcc2: { // 0x4adcc2: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L004adcc4: { // 0x4adcc4: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L004adcc6: { // 0x4adcc6: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L004adcc8: { // 0x4adcc8: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L004adcca: { // 0x4adcca: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L004adccd: { // 0x4adccd: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L004adccf: { // 0x4adccf: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L004adcd1: { // 0x4adcd1: e8aac30000 CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,4906198u,op); flags=s.arithmetic_flags;
  }
  L004adcd6: { // 0x4adcd6: e875cd2b00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4906203u,op); flags=s.arithmetic_flags;
  }
  L004adcdb: { // 0x4adcdb: 8b542454 MOV EDX,dword ptr [ESP + 0x54]
    s.dx = m.r32((f.sp+0x00000054u));
  }
  L004adcdf: { // 0x4adcdf: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004adce1: { // 0x4adce1: 898424a0000000 MOV dword ptr [ESP + 0xa0],EAX
    m.w32((f.sp+0x000000a0u), s.ax);
  }
  L004adce8: { // 0x4adce8: 8b442458 MOV EAX,dword ptr [ESP + 0x58]
    s.ax = m.r32((f.sp+0x00000058u));
  }
  L004adcec: { // 0x4adcec: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L004adcee: { // 0x4adcee: 8bd3 MOV EDX,EBX
    s.dx = s.bx;
  }
  L004adcf0: { // 0x4adcf0: 894c2444 MOV dword ptr [ESP + 0x44],ECX
    m.w32((f.sp+0x00000044u), s.cx);
  }
  L004adcf4: { // 0x4adcf4: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L004adcf6: { // 0x4adcf6: db442444 FILD dword ptr [ESP + 0x44]
    const auto address=(f.sp+0x00000044u);
    s.fp.load_integer32(m.r32(address));
  }
  L004adcfa: { // 0x4adcfa: 89542448 MOV dword ptr [ESP + 0x48],EDX
    m.w32((f.sp+0x00000048u), s.dx);
  }
  L004adcfe: { // 0x4adcfe: db442448 FILD dword ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    s.fp.load_integer32(m.r32(address));
  }
  L004add02: { // 0x4add02: db8424a0000000 FILD dword ptr [ESP + 0xa0]
    const auto address=(f.sp+0x000000a0u);
    s.fp.load_integer32(m.r32(address));
  }
  L004add09: { // 0x4add09: dd5c2444 FSTP double ptr [ESP + 0x44]
    const auto address=(f.sp+0x00000044u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L004add0d: { // 0x4add0d: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L004add0f: { // 0x4add0f: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L004add11: { // 0x4add11: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L004add13: { // 0x4add13: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L004add15: { // 0x4add15: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L004add17: { // 0x4add17: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L004add1a: { // 0x4add1a: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L004add1c: { // 0x4add1c: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L004add1e: { // 0x4add1e: e85dc30000 CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,4906275u,op); flags=s.arithmetic_flags;
  }
  L004add23: { // 0x4add23: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L004add26: { // 0x4add26: e825cd2b00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4906283u,op); flags=s.arithmetic_flags;
  }
  L004add2b: { // 0x4add2b: 89842498000000 MOV dword ptr [ESP + 0x98],EAX
    m.w32((f.sp+0x00000098u), s.ax);
  }
  L004add32: { // 0x4add32: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L004add34: { // 0x4add34: db842498000000 FILD dword ptr [ESP + 0x98]
    const auto address=(f.sp+0x00000098u);
    s.fp.load_integer32(m.r32(address));
  }
  L004add3b: { // 0x4add3b: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  L004add3d: { // 0x4add3d: 89842498000000 MOV dword ptr [ESP + 0x98],EAX
    m.w32((f.sp+0x00000098u), s.ax);
  }
  L004add44: { // 0x4add44: dc7c243c FDIVR double ptr [ESP + 0x3c]
    const auto address=(f.sp+0x0000003cu);
    reverse_divide64(s.fp,read64(m,address));
  }
  L004add48: { // 0x4add48: db842498000000 FILD dword ptr [ESP + 0x98]
    const auto address=(f.sp+0x00000098u);
    s.fp.load_integer32(m.r32(address));
  }
  L004add4f: { // 0x4add4f: dec9 FMULP
    numeric_b88::detail::reg<0xdec9>(s.fp);
  }
  L004add51: { // 0x4add51: e8facc2b00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4906326u,op); flags=s.arithmetic_flags;
  }
  L004add56: { // 0x4add56: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004add57: { // 0x4add57: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L004add59: { // 0x4add59: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004add5b: { // 0x4add5b: 3bef CMP EBP,EDI
    (void)integer::sub(s.bp,s.di,32,flags);
  }
  L004add5d: { // 0x4add5d: 7d0b JGE 0x004add6a
    if(integer::condition("JGE",flags)) goto L004add6a;
  }
  L004add5f: { // 0x4add5f: 03c5 ADD EAX,EBP
    s.ax = integer::add(s.ax,s.bp,32,flags);
  }
  L004add61: { // 0x4add61: 89842494000000 MOV dword ptr [ESP + 0x94],EAX
    m.w32((f.sp+0x00000094u), s.ax);
  }
  L004add68: { // 0x4add68: eb0b JMP 0x004add75
    goto L004add75;
  }
  L004add6a: { // 0x4add6a: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L004add6c: { // 0x4add6c: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L004add6e: { // 0x4add6e: 898c2494000000 MOV dword ptr [ESP + 0x94],ECX
    m.w32((f.sp+0x00000094u), s.cx);
  }
  L004add75: { // 0x4add75: 8b44245c MOV EAX,dword ptr [ESP + 0x5c]
    s.ax = m.r32((f.sp+0x0000005cu));
  }
  L004add79: { // 0x4add79: 8b4c2460 MOV ECX,dword ptr [ESP + 0x60]
    s.cx = m.r32((f.sp+0x00000060u));
  }
  L004add7d: { // 0x4add7d: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L004add7f: { // 0x4add7f: 7508 JNZ 0x004add89
    if(integer::condition("JNZ",flags)) goto L004add89;
  }
  L004add81: { // 0x4add81: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L004add83: { // 0x4add83: 0f84ce000000 JZ 0x004ade57
    if(integer::condition("JZ",flags)) goto L004ade57;
  }
  L004add89: { // 0x4add89: 8b54244c MOV EDX,dword ptr [ESP + 0x4c]
    s.dx = m.r32((f.sp+0x0000004cu));
  }
  L004add8d: { // 0x4add8d: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L004add90: { // 0x4add90: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004add92: { // 0x4add92: 89442444 MOV dword ptr [ESP + 0x44],EAX
    m.w32((f.sp+0x00000044u), s.ax);
  }
  L004add96: { // 0x4add96: 8b442458 MOV EAX,dword ptr [ESP + 0x58]
    s.ax = m.r32((f.sp+0x00000058u));
  }
  L004add9a: { // 0x4add9a: db442444 FILD dword ptr [ESP + 0x44]
    const auto address=(f.sp+0x00000044u);
    s.fp.load_integer32(m.r32(address));
  }
  L004add9e: { // 0x4add9e: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L004adda0: { // 0x4adda0: 894c2448 MOV dword ptr [ESP + 0x48],ECX
    m.w32((f.sp+0x00000048u), s.cx);
  }
  L004adda4: { // 0x4adda4: db442448 FILD dword ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    s.fp.load_integer32(m.r32(address));
  }
  L004adda8: { // 0x4adda8: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L004addaa: { // 0x4addaa: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L004addac: { // 0x4addac: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L004addae: { // 0x4addae: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L004addb0: { // 0x4addb0: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L004addb2: { // 0x4addb2: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L004addb5: { // 0x4addb5: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L004addb7: { // 0x4addb7: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L004addb9: { // 0x4addb9: e8c2c20000 CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,4906430u,op); flags=s.arithmetic_flags;
  }
  L004addbe: { // 0x4addbe: e88dcc2b00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4906435u,op); flags=s.arithmetic_flags;
  }
  L004addc3: { // 0x4addc3: 89842498000000 MOV dword ptr [ESP + 0x98],EAX
    m.w32((f.sp+0x00000098u), s.ax);
  }
  L004addca: { // 0x4addca: 8b442454 MOV EAX,dword ptr [ESP + 0x54]
    s.ax = m.r32((f.sp+0x00000054u));
  }
  L004addce: { // 0x4addce: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  L004addd0: { // 0x4addd0: 89742444 MOV dword ptr [ESP + 0x44],ESI
    m.w32((f.sp+0x00000044u), s.si);
  }
  L004addd4: { // 0x4addd4: 8b742458 MOV ESI,dword ptr [ESP + 0x58]
    s.si = m.r32((f.sp+0x00000058u));
  }
  L004addd8: { // 0x4addd8: db442444 FILD dword ptr [ESP + 0x44]
    const auto address=(f.sp+0x00000044u);
    s.fp.load_integer32(m.r32(address));
  }
  L004adddc: { // 0x4adddc: 2bde SUB EBX,ESI
    s.bx = integer::sub(s.bx,s.si,32,flags);
  }
  L004addde: { // 0x4addde: 895c2448 MOV dword ptr [ESP + 0x48],EBX
    m.w32((f.sp+0x00000048u), s.bx);
  }
  L004adde2: { // 0x4adde2: db442448 FILD dword ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    s.fp.load_integer32(m.r32(address));
  }
  L004adde6: { // 0x4adde6: db842498000000 FILD dword ptr [ESP + 0x98]
    const auto address=(f.sp+0x00000098u);
    s.fp.load_integer32(m.r32(address));
  }
  L004added: { // 0x4added: dd5c2454 FSTP double ptr [ESP + 0x54]
    const auto address=(f.sp+0x00000054u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L004addf1: { // 0x4addf1: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L004addf3: { // 0x4addf3: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L004addf5: { // 0x4addf5: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L004addf7: { // 0x4addf7: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L004addf9: { // 0x4addf9: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L004addfb: { // 0x4addfb: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L004addfe: { // 0x4addfe: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L004ade00: { // 0x4ade00: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L004ade02: { // 0x4ade02: e879c20000 CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,4906503u,op); flags=s.arithmetic_flags;
  }
  L004ade07: { // 0x4ade07: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L004ade0a: { // 0x4ade0a: e841cc2b00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4906511u,op); flags=s.arithmetic_flags;
  }
  L004ade0f: { // 0x4ade0f: 89842490000000 MOV dword ptr [ESP + 0x90],EAX
    m.w32((f.sp+0x00000090u), s.ax);
  }
  L004ade16: { // 0x4ade16: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L004ade18: { // 0x4ade18: db842490000000 FILD dword ptr [ESP + 0x90]
    const auto address=(f.sp+0x00000090u);
    s.fp.load_integer32(m.r32(address));
  }
  L004ade1f: { // 0x4ade1f: 2bcf SUB ECX,EDI
    s.cx = integer::sub(s.cx,s.di,32,flags);
  }
  L004ade21: { // 0x4ade21: 898c2490000000 MOV dword ptr [ESP + 0x90],ECX
    m.w32((f.sp+0x00000090u), s.cx);
  }
  L004ade28: { // 0x4ade28: dc7c244c FDIVR double ptr [ESP + 0x4c]
    const auto address=(f.sp+0x0000004cu);
    reverse_divide64(s.fp,read64(m,address));
  }
  L004ade2c: { // 0x4ade2c: db842490000000 FILD dword ptr [ESP + 0x90]
    const auto address=(f.sp+0x00000090u);
    s.fp.load_integer32(m.r32(address));
  }
  L004ade33: { // 0x4ade33: dec9 FMULP
    numeric_b88::detail::reg<0xdec9>(s.fp);
  }
  L004ade35: { // 0x4ade35: e816cc2b00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4906554u,op); flags=s.arithmetic_flags;
  }
  L004ade3a: { // 0x4ade3a: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004ade3b: { // 0x4ade3b: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L004ade3d: { // 0x4ade3d: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004ade3f: { // 0x4ade3f: 3bfd CMP EDI,EBP
    (void)integer::sub(s.di,s.bp,32,flags);
  }
  L004ade41: { // 0x4ade41: 7e0b JLE 0x004ade4e
    if(integer::condition("JLE",flags)) goto L004ade4e;
  }
  L004ade43: { // 0x4ade43: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L004ade45: { // 0x4ade45: 89bc2490000000 MOV dword ptr [ESP + 0x90],EDI
    m.w32((f.sp+0x00000090u), s.di);
  }
  L004ade4c: { // 0x4ade4c: eb09 JMP 0x004ade57
    goto L004ade57;
  }
  L004ade4e: { // 0x4ade4e: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L004ade50: { // 0x4ade50: 89842490000000 MOV dword ptr [ESP + 0x90],EAX
    m.w32((f.sp+0x00000090u), s.ax);
  }
  L004ade57: { // 0x4ade57: 8b742434 MOV ESI,dword ptr [ESP + 0x34]
    s.si = m.r32((f.sp+0x00000034u));
  }
  L004ade5b: { // 0x4ade5b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004ade5d: { // 0x4ade5d: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004ade5f: { // 0x4ade5f: ff5270 CALL dword ptr [EDX + 0x70]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000070u)),4906594u,op); flags=s.arithmetic_flags;
  }
  L004ade62: { // 0x4ade62: 8b4c2460 MOV ECX,dword ptr [ESP + 0x60]
    s.cx = m.r32((f.sp+0x00000060u));
  }
  L004ade66: { // 0x4ade66: 8b54245c MOV EDX,dword ptr [ESP + 0x5c]
    s.dx = m.r32((f.sp+0x0000005cu));
  }
  L004ade6a: { // 0x4ade6a: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004ade6c: { // 0x4ade6c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004ade6d: { // 0x4ade6d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004ade6e: { // 0x4ade6e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004ade70: { // 0x4ade70: ff505c CALL dword ptr [EAX + 0x5c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000005cu)),4906611u,op); flags=s.arithmetic_flags;
  }
  L004ade73: { // 0x4ade73: 8b0dac1f8200 MOV ECX,dword ptr [0x00821fac]
    s.cx = m.r32((0x00821facu));
  }
  L004ade79: { // 0x4ade79: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L004ade7b: { // 0x4ade7b: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004ade7d: { // 0x4ade7d: 899c248c000000 MOV dword ptr [ESP + 0x8c],EBX
    m.w32((f.sp+0x0000008cu), s.bx);
  }
  L004ade84: { // 0x4ade84: 0f843c070000 JZ 0x004ae5c6
    if(integer::condition("JZ",flags)) goto L004ae5c6;
  }
  L004ade8a: { // 0x4ade8a: 8b442460 MOV EAX,dword ptr [ESP + 0x60]
    s.ax = m.r32((f.sp+0x00000060u));
  }
  L004ade8e: { // 0x4ade8e: 8b7904 MOV EDI,dword ptr [ECX + 0x4]
    s.di = m.r32((s.cx+0x00000004u));
  }
  L004ade91: { // 0x4ade91: 8b54245c MOV EDX,dword ptr [ESP + 0x5c]
    s.dx = m.r32((f.sp+0x0000005cu));
  }
  L004ade95: { // 0x4ade95: 89442450 MOV dword ptr [ESP + 0x50],EAX
    m.w32((f.sp+0x00000050u), s.ax);
  }
  L004ade99: { // 0x4ade99: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  L004ade9b: { // 0x4ade9b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004ade9c: { // 0x4ade9c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004ade9d: { // 0x4ade9d: e8de3d2b00 CALL 0x00761c80
    s.arithmetic_flags=flags; invoke(m,s,f,0x00761c80u,4906658u,op); flags=s.arithmetic_flags;
  }
  L004adea2: { // 0x4adea2: 8b0df4988100 MOV ECX,dword ptr [0x008198f4]
    s.cx = m.r32((0x008198f4u));
  }
  L004adea8: { // 0x4adea8: 8b54245c MOV EDX,dword ptr [ESP + 0x5c]
    s.dx = m.r32((f.sp+0x0000005cu));
  }
  L004adeac: { // 0x4adeac: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L004adeae: { // 0x4adeae: 8b442460 MOV EAX,dword ptr [ESP + 0x60]
    s.ax = m.r32((f.sp+0x00000060u));
  }
  L004adeb2: { // 0x4adeb2: 8b7904 MOV EDI,dword ptr [ECX + 0x4]
    s.di = m.r32((s.cx+0x00000004u));
  }
  L004adeb5: { // 0x4adeb5: 89442450 MOV dword ptr [ESP + 0x50],EAX
    m.w32((f.sp+0x00000050u), s.ax);
  }
  L004adeb9: { // 0x4adeb9: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  L004adebb: { // 0x4adebb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004adebc: { // 0x4adebc: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004adebd: { // 0x4adebd: e86e33f6ff CALL 0x00411230
    s.arithmetic_flags=flags; invoke(m,s,f,0x00411230u,4906690u,op); flags=s.arithmetic_flags;
  }
  L004adec2: { // 0x4adec2: 8b4c2460 MOV ECX,dword ptr [ESP + 0x60]
    s.cx = m.r32((f.sp+0x00000060u));
  }
  L004adec6: { // 0x4adec6: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L004adec8: { // 0x4adec8: a1ac1f8200 MOV EAX,[0x00821fac]
    s.ax = m.r32((0x00821facu));
  }
  L004adecd: { // 0x4adecd: 8b542470 MOV EDX,dword ptr [ESP + 0x70]
    s.dx = m.r32((f.sp+0x00000070u));
  }
  L004aded1: { // 0x4aded1: c7442420ffffffff MOV dword ptr [ESP + 0x20],0xffffffff
    m.w32((f.sp+0x00000020u), 0xffffffffu);
  }
  L004aded9: { // 0x4aded9: 668b7824 MOV DI,word ptr [EAX + 0x24]
    s.di = (s.di & 0xffff0000u) | ((m.r16((s.ax+0x00000024u))) & 0xffffu);
  }
  L004adedd: { // 0x4adedd: 66037804 ADD DI,word ptr [EAX + 0x4]
    s.di = (s.di & 0xffff0000u) | ((integer::add((s.di & 0xffffu),m.r16((s.ax+0x00000004u)),16,flags)) & 0xffffu);
  }
  L004adee1: { // 0x4adee1: 8b4028 MOV EAX,dword ptr [EAX + 0x28]
    s.ax = m.r32((s.ax+0x00000028u));
  }
  L004adee4: { // 0x4adee4: 89842480000000 MOV dword ptr [ESP + 0x80],EAX
    m.w32((f.sp+0x00000080u), s.ax);
  }
  L004adeeb: { // 0x4adeeb: 2bf9 SUB EDI,ECX
    s.di = integer::sub(s.di,s.cx,32,flags);
  }
  L004adeed: { // 0x4adeed: 2bfa SUB EDI,EDX
    s.di = integer::sub(s.di,s.dx,32,flags);
  }
  L004adeef: { // 0x4adeef: 8b942490000000 MOV EDX,dword ptr [ESP + 0x90]
    s.dx = m.r32((f.sp+0x00000090u));
  }
  L004adef6: { // 0x4adef6: 03fa ADD EDI,EDX
    s.di = integer::add(s.di,s.dx,32,flags);
  }
  L004adef8: { // 0x4adef8: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L004adefa: { // 0x4adefa: 89bc2498000000 MOV dword ptr [ESP + 0x98],EDI
    m.w32((f.sp+0x00000098u), s.di);
  }
  L004adf01: { // 0x4adf01: 0f84bf060000 JZ 0x004ae5c6
    if(integer::condition("JZ",flags)) goto L004ae5c6;
  }
  L004adf07: { // 0x4adf07: 8b442464 MOV EAX,dword ptr [ESP + 0x64]
    s.ax = m.r32((f.sp+0x00000064u));
  }
  L004adf0b: { // 0x4adf0b: 8b7c245c MOV EDI,dword ptr [ESP + 0x5c]
    s.di = m.r32((f.sp+0x0000005cu));
  }
  L004adf0f: { // 0x4adf0f: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  L004adf11: { // 0x4adf11: 8b7c2468 MOV EDI,dword ptr [ESP + 0x68]
    s.di = m.r32((f.sp+0x00000068u));
  }
  L004adf15: { // 0x4adf15: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L004adf19: { // 0x4adf19: 8b842494000000 MOV EAX,dword ptr [ESP + 0x94]
    s.ax = m.r32((f.sp+0x00000094u));
  }
  L004adf20: { // 0x4adf20: 2bf9 SUB EDI,ECX
    s.di = integer::sub(s.di,s.cx,32,flags);
  }
  L004adf22: { // 0x4adf22: 8b4c2434 MOV ECX,dword ptr [ESP + 0x34]
    s.cx = m.r32((f.sp+0x00000034u));
  }
  L004adf26: { // 0x4adf26: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004adf28: { // 0x4adf28: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L004adf2a: { // 0x4adf2a: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L004adf2c: { // 0x4adf2c: ff5274 CALL dword ptr [EDX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000074u)),4906799u,op); flags=s.arithmetic_flags;
  }
  L004adf2f: { // 0x4adf2f: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L004adf31: { // 0x4adf31: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L004adf35: { // 0x4adf35: 7d1e JGE 0x004adf55
    if(integer::condition("JGE",flags)) goto L004adf55;
  }
  L004adf37: { // 0x4adf37: 8b8c2480000000 MOV ECX,dword ptr [ESP + 0x80]
    s.cx = m.r32((f.sp+0x00000080u));
  }
  L004adf3e: { // 0x4adf3e: c744242001000000 MOV dword ptr [ESP + 0x20],0x1
    m.w32((f.sp+0x00000020u), 0x00000001u);
  }
  L004adf46: { // 0x4adf46: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L004adf48: { // 0x4adf48: f7d9 NEG ECX
    s.cx = integer::sub(0u,s.cx,32,flags);
  }
  L004adf4a: { // 0x4adf4a: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L004adf4e: { // 0x4adf4e: 898c2480000000 MOV dword ptr [ESP + 0x80],ECX
    m.w32((f.sp+0x00000080u), s.cx);
  }
  L004adf55: { // 0x4adf55: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L004adf57: { // 0x4adf57: c744241c01000000 MOV dword ptr [ESP + 0x1c],0x1
    m.w32((f.sp+0x0000001cu), 0x00000001u);
  }
  L004adf5f: { // 0x4adf5f: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004adf60: { // 0x4adf60: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L004adf62: { // 0x4adf62: 33ca XOR ECX,EDX
    s.cx = integer::logical((s.cx)^(s.dx),32,flags);
  }
  L004adf64: { // 0x4adf64: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L004adf66: { // 0x4adf66: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L004adf68: { // 0x4adf68: 7d08 JGE 0x004adf72
    if(integer::condition("JGE",flags)) goto L004adf72;
  }
  L004adf6a: { // 0x4adf6a: c744241cffffffff MOV dword ptr [ESP + 0x1c],0xffffffff
    m.w32((f.sp+0x0000001cu), 0xffffffffu);
  }
  L004adf72: { // 0x4adf72: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L004adf74: { // 0x4adf74: c684249400000000 MOV byte ptr [ESP + 0x94],0x0
    m.w8((f.sp+0x00000094u), 0x00000000u);
  }
  L004adf7c: { // 0x4adf7c: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004adf7d: { // 0x4adf7d: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L004adf7f: { // 0x4adf7f: c684249500000000 MOV byte ptr [ESP + 0x95],0x0
    m.w8((f.sp+0x00000095u), 0x00000000u);
  }
  L004adf87: { // 0x4adf87: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004adf89: { // 0x4adf89: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L004adf8d: { // 0x4adf8d: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L004adf8f: { // 0x4adf8f: c684249600000000 MOV byte ptr [ESP + 0x96],0x0
    m.w8((f.sp+0x00000096u), 0x00000000u);
  }
  L004adf97: { // 0x4adf97: 8d3c12 LEA EDI,[EDX + EDX*0x1]
    s.di = (s.dx+(s.dx * 0x00000001u));
  }
  L004adf9a: { // 0x4adf9a: 89bc2488000000 MOV dword ptr [ESP + 0x88],EDI
    m.w32((f.sp+0x00000088u), s.di);
  }
  L004adfa1: { // 0x4adfa1: 8d3c09 LEA EDI,[ECX + ECX*0x1]
    s.di = (s.cx+(s.cx * 0x00000001u));
  }
  L004adfa4: { // 0x4adfa4: 89bc2484000000 MOV dword ptr [ESP + 0x84],EDI
    m.w32((f.sp+0x00000084u), s.di);
  }
  L004adfab: { // 0x4adfab: 8d3c00 LEA EDI,[EAX + EAX*0x1]
    s.di = (s.ax+(s.ax * 0x00000001u));
  }
  L004adfae: { // 0x4adfae: 897c2410 MOV dword ptr [ESP + 0x10],EDI
    m.w32((f.sp+0x00000010u), s.di);
  }
  L004adfb2: { // 0x4adfb2: 0f8e00020000 JLE 0x004ae1b8
    if(integer::condition("JLE",flags)) goto L004ae1b8;
  }
  L004adfb8: { // 0x4adfb8: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L004adfba: { // 0x4adfba: 0f8ef8010000 JLE 0x004ae1b8
    if(integer::condition("JLE",flags)) goto L004ae1b8;
  }
  L004adfc0: { // 0x4adfc0: 8bbc2484000000 MOV EDI,dword ptr [ESP + 0x84]
    s.di = m.r32((f.sp+0x00000084u));
  }
  L004adfc7: { // 0x4adfc7: 8b8c2488000000 MOV ECX,dword ptr [ESP + 0x88]
    s.cx = m.r32((f.sp+0x00000088u));
  }
  L004adfce: { // 0x4adfce: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L004adfd0: { // 0x4adfd0: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L004adfd2: { // 0x4adfd2: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004adfd4: { // 0x4adfd4: 897c2438 MOV dword ptr [ESP + 0x38],EDI
    m.w32((f.sp+0x00000038u), s.di);
  }
  L004adfd8: { // 0x4adfd8: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L004adfdc: { // 0x4adfdc: 0f8ecf050000 JLE 0x004ae5b1
    if(integer::condition("JLE",flags)) goto L004ae5b1;
  }
  L004adfe2: { // 0x4adfe2: 8b1dac1f8200 MOV EBX,dword ptr [0x00821fac]
    s.bx = m.r32((0x00821facu));
  }
  L004adfe8: { // 0x4adfe8: c744241800000000 MOV dword ptr [ESP + 0x18],0x0
    m.w32((f.sp+0x00000018u), 0x00000000u);
  }
  L004adff0: { // 0x4adff0: 8944243c MOV dword ptr [ESP + 0x3c],EAX
    m.w32((f.sp+0x0000003cu), s.ax);
  }
  L004adff4: { // 0x4adff4: 668b842498000000 MOV AX,word ptr [ESP + 0x98]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x00000098u)));
  }
  L004adffc: { // 0x4adffc: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L004adffe: { // 0x4adffe: 663b06 CMP AX,word ptr [ESI]
    (void)integer::sub((s.ax & 0xffffu),m.r16((s.si)),16,flags);
  }
  L004ae001: { // 0x4ae001: 668b5500 MOV DX,word ptr [EBP]
    s.dx = with_ax(s.dx, m.r16((s.bp)));
  }
  L004ae005: { // 0x4ae005: 0f83b0000000 JNC 0x004ae0bb
    if(integer::condition("JNC",flags)) goto L004ae0bb;
  }
  L004ae00b: { // 0x4ae00b: 8b9c248c000000 MOV EBX,dword ptr [ESP + 0x8c]
    s.bx = m.r32((f.sp+0x0000008cu));
  }
  L004ae012: { // 0x4ae012: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L004ae016: { // 0x4ae016: 668b3c19 MOV DI,word ptr [ECX + EBX*0x1]
    s.di = (s.di & 0xffff0000u) | ((m.r16((s.cx+(s.bx * 0x00000001u)))) & 0xffffu);
  }
  L004ae01a: { // 0x4ae01a: 668b0de8b28300 MOV CX,word ptr [0x0083b2e8]
    s.cx = with_ax(s.cx, m.r16((0x0083b2e8u)));
  }
  L004ae021: { // 0x4ae021: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L004ae023: { // 0x4ae023: 66d3e8 SHR AX,CL
    s.ax = with_ax(s.ax, integer::shift((s.ax & 0xffffu),(s.cx & 0xffu),16,flags,integer::Shift::right));
  }
  L004ae026: { // 0x4ae026: 8b0decb28300 MOV ECX,dword ptr [0x0083b2ec]
    s.cx = m.r32((0x0083b2ecu));
  }
  L004ae02c: { // 0x4ae02c: d2e0 SHL AL,CL
    s.ax = with_al(s.ax, integer::shift((s.ax & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::left));
  }
  L004ae02e: { // 0x4ae02e: 668b0df8b28300 MOV CX,word ptr [0x0083b2f8]
    s.cx = with_ax(s.cx, m.r16((0x0083b2f8u)));
  }
  L004ae035: { // 0x4ae035: 88842490000000 MOV byte ptr [ESP + 0x90],AL
    m.w8((f.sp+0x00000090u), (s.ax & 0xffu));
  }
  L004ae03c: { // 0x4ae03c: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L004ae03e: { // 0x4ae03e: 66d3e8 SHR AX,CL
    s.ax = with_ax(s.ax, integer::shift((s.ax & 0xffffu),(s.cx & 0xffu),16,flags,integer::Shift::right));
  }
  L004ae041: { // 0x4ae041: 8b0dfcb28300 MOV ECX,dword ptr [0x0083b2fc]
    s.cx = m.r32((0x0083b2fcu));
  }
  L004ae047: { // 0x4ae047: d2e0 SHL AL,CL
    s.ax = with_al(s.ax, integer::shift((s.ax & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::left));
  }
  L004ae049: { // 0x4ae049: 668b0df0b28300 MOV CX,word ptr [0x0083b2f0]
    s.cx = with_ax(s.cx, m.r16((0x0083b2f0u)));
  }
  L004ae050: { // 0x4ae050: 88842491000000 MOV byte ptr [ESP + 0x91],AL
    m.w8((f.sp+0x00000091u), (s.ax & 0xffu));
  }
  L004ae057: { // 0x4ae057: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L004ae059: { // 0x4ae059: 66d3e8 SHR AX,CL
    s.ax = with_ax(s.ax, integer::shift((s.ax & 0xffffu),(s.cx & 0xffu),16,flags,integer::Shift::right));
  }
  L004ae05c: { // 0x4ae05c: 8b0df4b28300 MOV ECX,dword ptr [0x0083b2f4]
    s.cx = m.r32((0x0083b2f4u));
  }
  L004ae062: { // 0x4ae062: d2e0 SHL AL,CL
    s.ax = with_al(s.ax, integer::shift((s.ax & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::left));
  }
  L004ae064: { // 0x4ae064: 668b8c2490000000 MOV CX,word ptr [ESP + 0x90]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000090u)));
  }
  L004ae06c: { // 0x4ae06c: 66898c2494000000 MOV word ptr [ESP + 0x94],CX
    m.w16((f.sp+0x00000094u), (s.cx & 0xffffu));
  }
  L004ae074: { // 0x4ae074: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L004ae076: { // 0x4ae076: 0faf4c242c IMUL ECX,dword ptr [ESP + 0x2c]
    s.cx = integer::imul(s.cx,m.r32((f.sp+0x0000002cu)),32,flags);
  }
  L004ae07b: { // 0x4ae07b: 88842496000000 MOV byte ptr [ESP + 0x96],AL
    m.w8((f.sp+0x00000096u), (s.ax & 0xffu));
  }
  L004ae082: { // 0x4ae082: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L004ae084: { // 0x4ae084: 0faf442428 IMUL EAX,dword ptr [ESP + 0x28]
    s.ax = integer::imul(s.ax,m.r32((f.sp+0x00000028u)),32,flags);
  }
  L004ae089: { // 0x4ae089: 0faf542430 IMUL EDX,dword ptr [ESP + 0x30]
    s.dx = integer::imul(s.dx,m.r32((f.sp+0x00000030u)),32,flags);
  }
  L004ae08e: { // 0x4ae08e: c1f807 SAR EAX,0x7
    s.ax = integer::shift(s.ax,0x00000007u,32,flags,integer::Shift::arithmetic_right);
  }
  L004ae091: { // 0x4ae091: c1f907 SAR ECX,0x7
    s.cx = integer::shift(s.cx,0x00000007u,32,flags,integer::Shift::arithmetic_right);
  }
  L004ae094: { // 0x4ae094: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004ae095: { // 0x4ae095: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004ae096: { // 0x4ae096: c1fa07 SAR EDX,0x7
    s.dx = integer::shift(s.dx,0x00000007u,32,flags,integer::Shift::arithmetic_right);
  }
  L004ae099: { // 0x4ae099: 8d8c249c000000 LEA ECX,[ESP + 0x9c]
    s.cx = (f.sp+0x0000009cu);
  }
  L004ae0a0: { // 0x4ae0a0: e83b050000 CALL 0x004ae5e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ae5e0u,4907173u,op); flags=s.arithmetic_flags;
  }
  L004ae0a5: { // 0x4ae0a5: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L004ae0a9: { // 0x4ae0a9: 8b7c2438 MOV EDI,dword ptr [ESP + 0x38]
    s.di = m.r32((f.sp+0x00000038u));
  }
  L004ae0ad: { // 0x4ae0ad: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L004ae0b1: { // 0x4ae0b1: 6689041a MOV word ptr [EDX + EBX*0x1],AX
    m.w16((s.dx+(s.bx * 0x00000001u)), (s.ax & 0xffffu));
  }
  L004ae0b5: { // 0x4ae0b5: 8b1dac1f8200 MOV EBX,dword ptr [0x00821fac]
    s.bx = m.r32((0x00821facu));
  }
  L004ae0bb: { // 0x4ae0bb: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L004ae0bd: { // 0x4ae0bd: 0f8e83000000 JLE 0x004ae146
    if(integer::condition("JLE",flags)) goto L004ae146;
  }
  L004ae0c3: { // 0x4ae0c3: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L004ae0c7: { // 0x4ae0c7: 8b94248c000000 MOV EDX,dword ptr [ESP + 0x8c]
    s.dx = m.r32((f.sp+0x0000008cu));
  }
  L004ae0ce: { // 0x4ae0ce: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L004ae0d2: { // 0x4ae0d2: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L004ae0d4: { // 0x4ae0d4: 8994248c000000 MOV dword ptr [ESP + 0x8c],EDX
    m.w32((f.sp+0x0000008cu), s.dx);
  }
  L004ae0db: { // 0x4ae0db: 8b942480000000 MOV EDX,dword ptr [ESP + 0x80]
    s.dx = m.r32((f.sp+0x00000080u));
  }
  L004ae0e2: { // 0x4ae0e2: 2bf9 SUB EDI,ECX
    s.di = integer::sub(s.di,s.cx,32,flags);
  }
  L004ae0e4: { // 0x4ae0e4: 8d0c12 LEA ECX,[EDX + EDX*0x1]
    s.cx = (s.dx+(s.dx * 0x00000001u));
  }
  L004ae0e7: { // 0x4ae0e7: 03f1 ADD ESI,ECX
    s.si = integer::add(s.si,s.cx,32,flags);
  }
  L004ae0e9: { // 0x4ae0e9: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L004ae0eb: { // 0x4ae0eb: 7e0a JLE 0x004ae0f7
    if(integer::condition("JLE",flags)) goto L004ae0f7;
  }
  L004ae0ed: { // 0x4ae0ed: 3b731c CMP ESI,dword ptr [EBX + 0x1c]
    (void)integer::sub(s.si,m.r32((s.bx+0x0000001cu)),32,flags);
  }
  L004ae0f0: { // 0x4ae0f0: 7213 JC 0x004ae105
    if(integer::condition("JC",flags)) goto L004ae105;
  }
  L004ae0f2: { // 0x4ae0f2: 2b7320 SUB ESI,dword ptr [EBX + 0x20]
    s.si = integer::sub(s.si,m.r32((s.bx+0x00000020u)),32,flags);
  }
  L004ae0f5: { // 0x4ae0f5: eb0e JMP 0x004ae105
    goto L004ae105;
  }
  L004ae0f7: { // 0x4ae0f7: 3b7318 CMP ESI,dword ptr [EBX + 0x18]
    (void)integer::sub(s.si,m.r32((s.bx+0x00000018u)),32,flags);
  }
  L004ae0fa: { // 0x4ae0fa: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004ae0fc: { // 0x4ae0fc: 7305 JNC 0x004ae103
    if(integer::condition("JNC",flags)) goto L004ae103;
  }
  L004ae0fe: { // 0x4ae0fe: 8b4320 MOV EAX,dword ptr [EBX + 0x20]
    s.ax = m.r32((s.bx+0x00000020u));
  }
  L004ae101: { // 0x4ae101: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L004ae103: { // 0x4ae103: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L004ae105: { // 0x4ae105: 03e9 ADD EBP,ECX
    s.bp = integer::add(s.bp,s.cx,32,flags);
  }
  L004ae107: { // 0x4ae107: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L004ae109: { // 0x4ae109: 7e0f JLE 0x004ae11a
    if(integer::condition("JLE",flags)) goto L004ae11a;
  }
  L004ae10b: { // 0x4ae10b: a1f4988100 MOV EAX,[0x008198f4]
    s.ax = m.r32((0x008198f4u));
  }
  L004ae110: { // 0x4ae110: 3b681c CMP EBP,dword ptr [EAX + 0x1c]
    (void)integer::sub(s.bp,m.r32((s.ax+0x0000001cu)),32,flags);
  }
  L004ae113: { // 0x4ae113: 7219 JC 0x004ae12e
    if(integer::condition("JC",flags)) goto L004ae12e;
  }
  L004ae115: { // 0x4ae115: 2b6820 SUB EBP,dword ptr [EAX + 0x20]
    s.bp = integer::sub(s.bp,m.r32((s.ax+0x00000020u)),32,flags);
  }
  L004ae118: { // 0x4ae118: eb14 JMP 0x004ae12e
    goto L004ae12e;
  }
  L004ae11a: { // 0x4ae11a: 8b0df4988100 MOV ECX,dword ptr [0x008198f4]
    s.cx = m.r32((0x008198f4u));
  }
  L004ae120: { // 0x4ae120: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L004ae122: { // 0x4ae122: 3b6918 CMP EBP,dword ptr [ECX + 0x18]
    (void)integer::sub(s.bp,m.r32((s.cx+0x00000018u)),32,flags);
  }
  L004ae125: { // 0x4ae125: 7305 JNC 0x004ae12c
    if(integer::condition("JNC",flags)) goto L004ae12c;
  }
  L004ae127: { // 0x4ae127: 8b4120 MOV EAX,dword ptr [ECX + 0x20]
    s.ax = m.r32((s.cx+0x00000020u));
  }
  L004ae12a: { // 0x4ae12a: 03c5 ADD EAX,EBP
    s.ax = integer::add(s.ax,s.bp,32,flags);
  }
  L004ae12c: { // 0x4ae12c: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L004ae12e: { // 0x4ae12e: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L004ae132: { // 0x4ae132: 8b842498000000 MOV EAX,dword ptr [ESP + 0x98]
    s.ax = m.r32((f.sp+0x00000098u));
  }
  L004ae139: { // 0x4ae139: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L004ae13b: { // 0x4ae13b: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L004ae13f: { // 0x4ae13f: 89842498000000 MOV dword ptr [ESP + 0x98],EAX
    m.w32((f.sp+0x00000098u), s.ax);
  }
  L004ae146: { // 0x4ae146: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004ae148: { // 0x4ae148: 7e1c JLE 0x004ae166
    if(integer::condition("JLE",flags)) goto L004ae166;
  }
  L004ae14a: { // 0x4ae14a: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L004ae14e: { // 0x4ae14e: 8b431c MOV EAX,dword ptr [EBX + 0x1c]
    s.ax = m.r32((s.bx+0x0000001cu));
  }
  L004ae151: { // 0x4ae151: 83c602 ADD ESI,0x2
    s.si = integer::add(s.si,0x00000002u,32,flags);
  }
  L004ae154: { // 0x4ae154: 83c202 ADD EDX,0x2
    s.dx = integer::add(s.dx,0x00000002u,32,flags);
  }
  L004ae157: { // 0x4ae157: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L004ae159: { // 0x4ae159: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L004ae15d: { // 0x4ae15d: 7203 JC 0x004ae162
    if(integer::condition("JC",flags)) goto L004ae162;
  }
  L004ae15f: { // 0x4ae15f: 2b7320 SUB ESI,dword ptr [EBX + 0x20]
    s.si = integer::sub(s.si,m.r32((s.bx+0x00000020u)),32,flags);
  }
  L004ae162: { // 0x4ae162: 2b4c2410 SUB ECX,dword ptr [ESP + 0x10]
    s.cx = integer::sub(s.cx,m.r32((f.sp+0x00000010u)),32,flags);
  }
  L004ae166: { // 0x4ae166: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L004ae16a: { // 0x4ae16a: 8b842498000000 MOV EAX,dword ptr [ESP + 0x98]
    s.ax = m.r32((f.sp+0x00000098u));
  }
  L004ae171: { // 0x4ae171: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004ae173: { // 0x4ae173: 8b942484000000 MOV EDX,dword ptr [ESP + 0x84]
    s.dx = m.r32((f.sp+0x00000084u));
  }
  L004ae17a: { // 0x4ae17a: 89842498000000 MOV dword ptr [ESP + 0x98],EAX
    m.w32((f.sp+0x00000098u), s.ax);
  }
  L004ae181: { // 0x4ae181: 8b842488000000 MOV EAX,dword ptr [ESP + 0x88]
    s.ax = m.r32((f.sp+0x00000088u));
  }
  L004ae188: { // 0x4ae188: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L004ae18a: { // 0x4ae18a: 8b44243c MOV EAX,dword ptr [ESP + 0x3c]
    s.ax = m.r32((f.sp+0x0000003cu));
  }
  L004ae18e: { // 0x4ae18e: 03fa ADD EDI,EDX
    s.di = integer::add(s.di,s.dx,32,flags);
  }
  L004ae190: { // 0x4ae190: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L004ae191: { // 0x4ae191: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L004ae195: { // 0x4ae195: 897c2438 MOV dword ptr [ESP + 0x38],EDI
    m.w32((f.sp+0x00000038u), s.di);
  }
  L004ae199: { // 0x4ae199: 8944243c MOV dword ptr [ESP + 0x3c],EAX
    m.w32((f.sp+0x0000003cu), s.ax);
  }
  L004ae19d: { // 0x4ae19d: 0f8551feffff JNZ 0x004adff4
    if(integer::condition("JNZ",flags)) goto L004adff4;
  }
  L004ae1a3: { // 0x4ae1a3: 8b4c2434 MOV ECX,dword ptr [ESP + 0x34]
    s.cx = m.r32((f.sp+0x00000034u));
  }
  L004ae1a7: { // 0x4ae1a7: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L004ae1a9: { // 0x4ae1a9: ff5260 CALL dword ptr [EDX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),4907436u,op); flags=s.arithmetic_flags;
  }
  L004ae1ac: { // 0x4ae1ac: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004ae1ad: { // 0x4ae1ad: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004ae1ae: { // 0x4ae1ae: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004ae1af: { // 0x4ae1af: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L004ae1b1: { // 0x4ae1b1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004ae1b2: { // 0x4ae1b2: 83c46c ADD ESP,0x6c
    f.sp = integer::add(f.sp,0x0000006cu,32,flags);
  }
  L004ae1b5: { // 0x4ae1b5: c21c00 RET 0x1c
    s.arithmetic_flags=flags; finish(m,s,f,28u); return;
  }
  L004ae1b8: { // 0x4ae1b8: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L004ae1ba: { // 0x4ae1ba: 0f8efa010000 JLE 0x004ae3ba
    if(integer::condition("JLE",flags)) goto L004ae3ba;
  }
  L004ae1c0: { // 0x4ae1c0: 8bbc2484000000 MOV EDI,dword ptr [ESP + 0x84]
    s.di = m.r32((f.sp+0x00000084u));
  }
  L004ae1c7: { // 0x4ae1c7: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L004ae1cb: { // 0x4ae1cb: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L004ae1cf: { // 0x4ae1cf: 2bf9 SUB EDI,ECX
    s.di = integer::sub(s.di,s.cx,32,flags);
  }
  L004ae1d1: { // 0x4ae1d1: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L004ae1d3: { // 0x4ae1d3: 897c243c MOV dword ptr [ESP + 0x3c],EDI
    m.w32((f.sp+0x0000003cu), s.di);
  }
  L004ae1d7: { // 0x4ae1d7: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004ae1d9: { // 0x4ae1d9: 89442438 MOV dword ptr [ESP + 0x38],EAX
    m.w32((f.sp+0x00000038u), s.ax);
  }
  L004ae1dd: { // 0x4ae1dd: c744241800000000 MOV dword ptr [ESP + 0x18],0x0
    m.w32((f.sp+0x00000018u), 0x00000000u);
  }
  L004ae1e5: { // 0x4ae1e5: 0f8ec6030000 JLE 0x004ae5b1
    if(integer::condition("JLE",flags)) goto L004ae5b1;
  }
  L004ae1eb: { // 0x4ae1eb: 8b1dac1f8200 MOV EBX,dword ptr [0x00821fac]
    s.bx = m.r32((0x00821facu));
  }
  L004ae1f1: { // 0x4ae1f1: 668b842498000000 MOV AX,word ptr [ESP + 0x98]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x00000098u)));
  }
  L004ae1f9: { // 0x4ae1f9: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L004ae1fb: { // 0x4ae1fb: 663b06 CMP AX,word ptr [ESI]
    (void)integer::sub((s.ax & 0xffffu),m.r16((s.si)),16,flags);
  }
  L004ae1fe: { // 0x4ae1fe: 668b5500 MOV DX,word ptr [EBP]
    s.dx = with_ax(s.dx, m.r16((s.bp)));
  }
  L004ae202: { // 0x4ae202: 0f83ac000000 JNC 0x004ae2b4
    if(integer::condition("JNC",flags)) goto L004ae2b4;
  }
  L004ae208: { // 0x4ae208: 8b9c248c000000 MOV EBX,dword ptr [ESP + 0x8c]
    s.bx = m.r32((f.sp+0x0000008cu));
  }
  L004ae20f: { // 0x4ae20f: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L004ae213: { // 0x4ae213: 668b3c4b MOV DI,word ptr [EBX + ECX*0x2]
    s.di = (s.di & 0xffff0000u) | ((m.r16((s.bx+(s.cx * 0x00000002u)))) & 0xffffu);
  }
  L004ae217: { // 0x4ae217: 668b0de8b28300 MOV CX,word ptr [0x0083b2e8]
    s.cx = with_ax(s.cx, m.r16((0x0083b2e8u)));
  }
  L004ae21e: { // 0x4ae21e: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L004ae220: { // 0x4ae220: 66d3e8 SHR AX,CL
    s.ax = with_ax(s.ax, integer::shift((s.ax & 0xffffu),(s.cx & 0xffu),16,flags,integer::Shift::right));
  }
  L004ae223: { // 0x4ae223: 8b0decb28300 MOV ECX,dword ptr [0x0083b2ec]
    s.cx = m.r32((0x0083b2ecu));
  }
  L004ae229: { // 0x4ae229: d2e0 SHL AL,CL
    s.ax = with_al(s.ax, integer::shift((s.ax & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::left));
  }
  L004ae22b: { // 0x4ae22b: 668b0df8b28300 MOV CX,word ptr [0x0083b2f8]
    s.cx = with_ax(s.cx, m.r16((0x0083b2f8u)));
  }
  L004ae232: { // 0x4ae232: 88842490000000 MOV byte ptr [ESP + 0x90],AL
    m.w8((f.sp+0x00000090u), (s.ax & 0xffu));
  }
  L004ae239: { // 0x4ae239: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L004ae23b: { // 0x4ae23b: 66d3e8 SHR AX,CL
    s.ax = with_ax(s.ax, integer::shift((s.ax & 0xffffu),(s.cx & 0xffu),16,flags,integer::Shift::right));
  }
  L004ae23e: { // 0x4ae23e: 8b0dfcb28300 MOV ECX,dword ptr [0x0083b2fc]
    s.cx = m.r32((0x0083b2fcu));
  }
  L004ae244: { // 0x4ae244: d2e0 SHL AL,CL
    s.ax = with_al(s.ax, integer::shift((s.ax & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::left));
  }
  L004ae246: { // 0x4ae246: 668b0df0b28300 MOV CX,word ptr [0x0083b2f0]
    s.cx = with_ax(s.cx, m.r16((0x0083b2f0u)));
  }
  L004ae24d: { // 0x4ae24d: 88842491000000 MOV byte ptr [ESP + 0x91],AL
    m.w8((f.sp+0x00000091u), (s.ax & 0xffu));
  }
  L004ae254: { // 0x4ae254: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L004ae256: { // 0x4ae256: 66d3e8 SHR AX,CL
    s.ax = with_ax(s.ax, integer::shift((s.ax & 0xffffu),(s.cx & 0xffu),16,flags,integer::Shift::right));
  }
  L004ae259: { // 0x4ae259: 8b0df4b28300 MOV ECX,dword ptr [0x0083b2f4]
    s.cx = m.r32((0x0083b2f4u));
  }
  L004ae25f: { // 0x4ae25f: d2e0 SHL AL,CL
    s.ax = with_al(s.ax, integer::shift((s.ax & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::left));
  }
  L004ae261: { // 0x4ae261: 668b8c2490000000 MOV CX,word ptr [ESP + 0x90]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000090u)));
  }
  L004ae269: { // 0x4ae269: 66898c2494000000 MOV word ptr [ESP + 0x94],CX
    m.w16((f.sp+0x00000094u), (s.cx & 0xffffu));
  }
  L004ae271: { // 0x4ae271: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L004ae273: { // 0x4ae273: 0faf4c242c IMUL ECX,dword ptr [ESP + 0x2c]
    s.cx = integer::imul(s.cx,m.r32((f.sp+0x0000002cu)),32,flags);
  }
  L004ae278: { // 0x4ae278: 88842496000000 MOV byte ptr [ESP + 0x96],AL
    m.w8((f.sp+0x00000096u), (s.ax & 0xffu));
  }
  L004ae27f: { // 0x4ae27f: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L004ae281: { // 0x4ae281: 0faf442428 IMUL EAX,dword ptr [ESP + 0x28]
    s.ax = integer::imul(s.ax,m.r32((f.sp+0x00000028u)),32,flags);
  }
  L004ae286: { // 0x4ae286: 0faf542430 IMUL EDX,dword ptr [ESP + 0x30]
    s.dx = integer::imul(s.dx,m.r32((f.sp+0x00000030u)),32,flags);
  }
  L004ae28b: { // 0x4ae28b: c1f807 SAR EAX,0x7
    s.ax = integer::shift(s.ax,0x00000007u,32,flags,integer::Shift::arithmetic_right);
  }
  L004ae28e: { // 0x4ae28e: c1f907 SAR ECX,0x7
    s.cx = integer::shift(s.cx,0x00000007u,32,flags,integer::Shift::arithmetic_right);
  }
  L004ae291: { // 0x4ae291: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004ae292: { // 0x4ae292: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004ae293: { // 0x4ae293: c1fa07 SAR EDX,0x7
    s.dx = integer::shift(s.dx,0x00000007u,32,flags,integer::Shift::arithmetic_right);
  }
  L004ae296: { // 0x4ae296: 8d8c249c000000 LEA ECX,[ESP + 0x9c]
    s.cx = (f.sp+0x0000009cu);
  }
  L004ae29d: { // 0x4ae29d: e83e030000 CALL 0x004ae5e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ae5e0u,4907682u,op); flags=s.arithmetic_flags;
  }
  L004ae2a2: { // 0x4ae2a2: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L004ae2a6: { // 0x4ae2a6: 8b7c243c MOV EDI,dword ptr [ESP + 0x3c]
    s.di = m.r32((f.sp+0x0000003cu));
  }
  L004ae2aa: { // 0x4ae2aa: 66890453 MOV word ptr [EBX + EDX*0x2],AX
    m.w16((s.bx+(s.dx * 0x00000002u)), (s.ax & 0xffffu));
  }
  L004ae2ae: { // 0x4ae2ae: 8b1dac1f8200 MOV EBX,dword ptr [0x00821fac]
    s.bx = m.r32((0x00821facu));
  }
  L004ae2b4: { // 0x4ae2b4: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L004ae2b6: { // 0x4ae2b6: 0f8e8b000000 JLE 0x004ae347
    if(integer::condition("JLE",flags)) goto L004ae347;
  }
  L004ae2bc: { // 0x4ae2bc: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L004ae2c0: { // 0x4ae2c0: 8b8c248c000000 MOV ECX,dword ptr [ESP + 0x8c]
    s.cx = m.r32((f.sp+0x0000008cu));
  }
  L004ae2c7: { // 0x4ae2c7: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L004ae2c9: { // 0x4ae2c9: 8b842488000000 MOV EAX,dword ptr [ESP + 0x88]
    s.ax = m.r32((f.sp+0x00000088u));
  }
  L004ae2d0: { // 0x4ae2d0: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L004ae2d2: { // 0x4ae2d2: 8b842480000000 MOV EAX,dword ptr [ESP + 0x80]
    s.ax = m.r32((f.sp+0x00000080u));
  }
  L004ae2d9: { // 0x4ae2d9: 898c248c000000 MOV dword ptr [ESP + 0x8c],ECX
    m.w32((f.sp+0x0000008cu), s.cx);
  }
  L004ae2e0: { // 0x4ae2e0: 8d0c00 LEA ECX,[EAX + EAX*0x1]
    s.cx = (s.ax+(s.ax * 0x00000001u));
  }
  L004ae2e3: { // 0x4ae2e3: 03f1 ADD ESI,ECX
    s.si = integer::add(s.si,s.cx,32,flags);
  }
  L004ae2e5: { // 0x4ae2e5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004ae2e7: { // 0x4ae2e7: 7e0a JLE 0x004ae2f3
    if(integer::condition("JLE",flags)) goto L004ae2f3;
  }
  L004ae2e9: { // 0x4ae2e9: 3b731c CMP ESI,dword ptr [EBX + 0x1c]
    (void)integer::sub(s.si,m.r32((s.bx+0x0000001cu)),32,flags);
  }
  L004ae2ec: { // 0x4ae2ec: 7215 JC 0x004ae303
    if(integer::condition("JC",flags)) goto L004ae303;
  }
  L004ae2ee: { // 0x4ae2ee: 2b7320 SUB ESI,dword ptr [EBX + 0x20]
    s.si = integer::sub(s.si,m.r32((s.bx+0x00000020u)),32,flags);
  }
  L004ae2f1: { // 0x4ae2f1: eb10 JMP 0x004ae303
    goto L004ae303;
  }
  L004ae2f3: { // 0x4ae2f3: 8b5318 MOV EDX,dword ptr [EBX + 0x18]
    s.dx = m.r32((s.bx+0x00000018u));
  }
  L004ae2f6: { // 0x4ae2f6: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004ae2f8: { // 0x4ae2f8: 3bf2 CMP ESI,EDX
    (void)integer::sub(s.si,s.dx,32,flags);
  }
  L004ae2fa: { // 0x4ae2fa: 7305 JNC 0x004ae301
    if(integer::condition("JNC",flags)) goto L004ae301;
  }
  L004ae2fc: { // 0x4ae2fc: 8b4320 MOV EAX,dword ptr [EBX + 0x20]
    s.ax = m.r32((s.bx+0x00000020u));
  }
  L004ae2ff: { // 0x4ae2ff: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L004ae301: { // 0x4ae301: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L004ae303: { // 0x4ae303: 8b842480000000 MOV EAX,dword ptr [ESP + 0x80]
    s.ax = m.r32((f.sp+0x00000080u));
  }
  L004ae30a: { // 0x4ae30a: 03e9 ADD EBP,ECX
    s.bp = integer::add(s.bp,s.cx,32,flags);
  }
  L004ae30c: { // 0x4ae30c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004ae30e: { // 0x4ae30e: 7e0f JLE 0x004ae31f
    if(integer::condition("JLE",flags)) goto L004ae31f;
  }
  L004ae310: { // 0x4ae310: a1f4988100 MOV EAX,[0x008198f4]
    s.ax = m.r32((0x008198f4u));
  }
  L004ae315: { // 0x4ae315: 3b681c CMP EBP,dword ptr [EAX + 0x1c]
    (void)integer::sub(s.bp,m.r32((s.ax+0x0000001cu)),32,flags);
  }
  L004ae318: { // 0x4ae318: 7219 JC 0x004ae333
    if(integer::condition("JC",flags)) goto L004ae333;
  }
  L004ae31a: { // 0x4ae31a: 2b6820 SUB EBP,dword ptr [EAX + 0x20]
    s.bp = integer::sub(s.bp,m.r32((s.ax+0x00000020u)),32,flags);
  }
  L004ae31d: { // 0x4ae31d: eb14 JMP 0x004ae333
    goto L004ae333;
  }
  L004ae31f: { // 0x4ae31f: 8b0df4988100 MOV ECX,dword ptr [0x008198f4]
    s.cx = m.r32((0x008198f4u));
  }
  L004ae325: { // 0x4ae325: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L004ae327: { // 0x4ae327: 3b6918 CMP EBP,dword ptr [ECX + 0x18]
    (void)integer::sub(s.bp,m.r32((s.cx+0x00000018u)),32,flags);
  }
  L004ae32a: { // 0x4ae32a: 7305 JNC 0x004ae331
    if(integer::condition("JNC",flags)) goto L004ae331;
  }
  L004ae32c: { // 0x4ae32c: 8b4120 MOV EAX,dword ptr [ECX + 0x20]
    s.ax = m.r32((s.cx+0x00000020u));
  }
  L004ae32f: { // 0x4ae32f: 03c5 ADD EAX,EBP
    s.ax = integer::add(s.ax,s.bp,32,flags);
  }
  L004ae331: { // 0x4ae331: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L004ae333: { // 0x4ae333: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L004ae337: { // 0x4ae337: 8b842498000000 MOV EAX,dword ptr [ESP + 0x98]
    s.ax = m.r32((f.sp+0x00000098u));
  }
  L004ae33e: { // 0x4ae33e: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L004ae340: { // 0x4ae340: 89842498000000 MOV dword ptr [ESP + 0x98],EAX
    m.w32((f.sp+0x00000098u), s.ax);
  }
  L004ae347: { // 0x4ae347: 8b442438 MOV EAX,dword ptr [ESP + 0x38]
    s.ax = m.r32((f.sp+0x00000038u));
  }
  L004ae34b: { // 0x4ae34b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004ae34d: { // 0x4ae34d: 7e1d JLE 0x004ae36c
    if(integer::condition("JLE",flags)) goto L004ae36c;
  }
  L004ae34f: { // 0x4ae34f: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L004ae353: { // 0x4ae353: 8b8c2498000000 MOV ECX,dword ptr [ESP + 0x98]
    s.cx = m.r32((f.sp+0x00000098u));
  }
  L004ae35a: { // 0x4ae35a: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L004ae35c: { // 0x4ae35c: 898c2498000000 MOV dword ptr [ESP + 0x98],ECX
    m.w32((f.sp+0x00000098u), s.cx);
  }
  L004ae363: { // 0x4ae363: 8b8c2488000000 MOV ECX,dword ptr [ESP + 0x88]
    s.cx = m.r32((f.sp+0x00000088u));
  }
  L004ae36a: { // 0x4ae36a: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L004ae36c: { // 0x4ae36c: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L004ae370: { // 0x4ae370: 8b942484000000 MOV EDX,dword ptr [ESP + 0x84]
    s.dx = m.r32((f.sp+0x00000084u));
  }
  L004ae377: { // 0x4ae377: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L004ae379: { // 0x4ae379: 83c602 ADD ESI,0x2
    s.si = integer::add(s.si,0x00000002u,32,flags);
  }
  L004ae37c: { // 0x4ae37c: 89442438 MOV dword ptr [ESP + 0x38],EAX
    m.w32((f.sp+0x00000038u), s.ax);
  }
  L004ae380: { // 0x4ae380: 8b431c MOV EAX,dword ptr [EBX + 0x1c]
    s.ax = m.r32((s.bx+0x0000001cu));
  }
  L004ae383: { // 0x4ae383: 03fa ADD EDI,EDX
    s.di = integer::add(s.di,s.dx,32,flags);
  }
  L004ae385: { // 0x4ae385: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L004ae387: { // 0x4ae387: 897c243c MOV dword ptr [ESP + 0x3c],EDI
    m.w32((f.sp+0x0000003cu), s.di);
  }
  L004ae38b: { // 0x4ae38b: 7203 JC 0x004ae390
    if(integer::condition("JC",flags)) goto L004ae390;
  }
  L004ae38d: { // 0x4ae38d: 2b7320 SUB ESI,dword ptr [EBX + 0x20]
    s.si = integer::sub(s.si,m.r32((s.bx+0x00000020u)),32,flags);
  }
  L004ae390: { // 0x4ae390: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L004ae394: { // 0x4ae394: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L004ae398: { // 0x4ae398: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004ae399: { // 0x4ae399: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L004ae39b: { // 0x4ae39b: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L004ae39f: { // 0x4ae39f: 0f8c4cfeffff JL 0x004ae1f1
    if(integer::condition("JL",flags)) goto L004ae1f1;
  }
  L004ae3a5: { // 0x4ae3a5: 8b4c2434 MOV ECX,dword ptr [ESP + 0x34]
    s.cx = m.r32((f.sp+0x00000034u));
  }
  L004ae3a9: { // 0x4ae3a9: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L004ae3ab: { // 0x4ae3ab: ff5260 CALL dword ptr [EDX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),4907950u,op); flags=s.arithmetic_flags;
  }
  L004ae3ae: { // 0x4ae3ae: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004ae3af: { // 0x4ae3af: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004ae3b0: { // 0x4ae3b0: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004ae3b1: { // 0x4ae3b1: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L004ae3b3: { // 0x4ae3b3: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004ae3b4: { // 0x4ae3b4: 83c46c ADD ESP,0x6c
    f.sp = integer::add(f.sp,0x0000006cu,32,flags);
  }
  L004ae3b7: { // 0x4ae3b7: c21c00 RET 0x1c
    s.arithmetic_flags=flags; finish(m,s,f,28u); return;
  }
  L004ae3ba: { // 0x4ae3ba: 8bbc2488000000 MOV EDI,dword ptr [ESP + 0x88]
    s.di = m.r32((f.sp+0x00000088u));
  }
  L004ae3c1: { // 0x4ae3c1: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L004ae3c5: { // 0x4ae3c5: 2bf9 SUB EDI,ECX
    s.di = integer::sub(s.di,s.cx,32,flags);
  }
  L004ae3c7: { // 0x4ae3c7: 2bd9 SUB EBX,ECX
    s.bx = integer::sub(s.bx,s.cx,32,flags);
  }
  L004ae3c9: { // 0x4ae3c9: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004ae3cb: { // 0x4ae3cb: 897c243c MOV dword ptr [ESP + 0x3c],EDI
    m.w32((f.sp+0x0000003cu), s.di);
  }
  L004ae3cf: { // 0x4ae3cf: 895c2438 MOV dword ptr [ESP + 0x38],EBX
    m.w32((f.sp+0x00000038u), s.bx);
  }
  L004ae3d3: { // 0x4ae3d3: 0f8ed8010000 JLE 0x004ae5b1
    if(integer::condition("JLE",flags)) goto L004ae5b1;
  }
  L004ae3d9: { // 0x4ae3d9: 8b842480000000 MOV EAX,dword ptr [ESP + 0x80]
    s.ax = m.r32((f.sp+0x00000080u));
  }
  L004ae3e0: { // 0x4ae3e0: 894c244c MOV dword ptr [ESP + 0x4c],ECX
    m.w32((f.sp+0x0000004cu), s.cx);
  }
  L004ae3e4: { // 0x4ae3e4: 8b0dac1f8200 MOV ECX,dword ptr [0x00821fac]
    s.cx = m.r32((0x00821facu));
  }
  L004ae3ea: { // 0x4ae3ea: c744241800000000 MOV dword ptr [ESP + 0x18],0x0
    m.w32((f.sp+0x00000018u), 0x00000000u);
  }
  L004ae3f2: { // 0x4ae3f2: 8d1400 LEA EDX,[EAX + EAX*0x1]
    s.dx = (s.ax+(s.ax * 0x00000001u));
  }
  L004ae3f5: { // 0x4ae3f5: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L004ae3f9: { // 0x4ae3f9: 668b842498000000 MOV AX,word ptr [ESP + 0x98]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x00000098u)));
  }
  L004ae401: { // 0x4ae401: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L004ae403: { // 0x4ae403: 663b06 CMP AX,word ptr [ESI]
    (void)integer::sub((s.ax & 0xffffu),m.r16((s.si)),16,flags);
  }
  L004ae406: { // 0x4ae406: 668b5500 MOV DX,word ptr [EBP]
    s.dx = with_ax(s.dx, m.r16((s.bp)));
  }
  L004ae40a: { // 0x4ae40a: 0f83b0000000 JNC 0x004ae4c0
    if(integer::condition("JNC",flags)) goto L004ae4c0;
  }
  L004ae410: { // 0x4ae410: 8b9c248c000000 MOV EBX,dword ptr [ESP + 0x8c]
    s.bx = m.r32((f.sp+0x0000008cu));
  }
  L004ae417: { // 0x4ae417: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L004ae41b: { // 0x4ae41b: 668b3c19 MOV DI,word ptr [ECX + EBX*0x1]
    s.di = (s.di & 0xffff0000u) | ((m.r16((s.cx+(s.bx * 0x00000001u)))) & 0xffffu);
  }
  L004ae41f: { // 0x4ae41f: 668b0de8b28300 MOV CX,word ptr [0x0083b2e8]
    s.cx = with_ax(s.cx, m.r16((0x0083b2e8u)));
  }
  L004ae426: { // 0x4ae426: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L004ae428: { // 0x4ae428: 66d3e8 SHR AX,CL
    s.ax = with_ax(s.ax, integer::shift((s.ax & 0xffffu),(s.cx & 0xffu),16,flags,integer::Shift::right));
  }
  L004ae42b: { // 0x4ae42b: 8b0decb28300 MOV ECX,dword ptr [0x0083b2ec]
    s.cx = m.r32((0x0083b2ecu));
  }
  L004ae431: { // 0x4ae431: d2e0 SHL AL,CL
    s.ax = with_al(s.ax, integer::shift((s.ax & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::left));
  }
  L004ae433: { // 0x4ae433: 668b0df8b28300 MOV CX,word ptr [0x0083b2f8]
    s.cx = with_ax(s.cx, m.r16((0x0083b2f8u)));
  }
  L004ae43a: { // 0x4ae43a: 88842490000000 MOV byte ptr [ESP + 0x90],AL
    m.w8((f.sp+0x00000090u), (s.ax & 0xffu));
  }
  L004ae441: { // 0x4ae441: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L004ae443: { // 0x4ae443: 66d3e8 SHR AX,CL
    s.ax = with_ax(s.ax, integer::shift((s.ax & 0xffffu),(s.cx & 0xffu),16,flags,integer::Shift::right));
  }
  L004ae446: { // 0x4ae446: 8b0dfcb28300 MOV ECX,dword ptr [0x0083b2fc]
    s.cx = m.r32((0x0083b2fcu));
  }
  L004ae44c: { // 0x4ae44c: d2e0 SHL AL,CL
    s.ax = with_al(s.ax, integer::shift((s.ax & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::left));
  }
  L004ae44e: { // 0x4ae44e: 668b0df0b28300 MOV CX,word ptr [0x0083b2f0]
    s.cx = with_ax(s.cx, m.r16((0x0083b2f0u)));
  }
  L004ae455: { // 0x4ae455: 88842491000000 MOV byte ptr [ESP + 0x91],AL
    m.w8((f.sp+0x00000091u), (s.ax & 0xffu));
  }
  L004ae45c: { // 0x4ae45c: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L004ae45e: { // 0x4ae45e: 66d3e8 SHR AX,CL
    s.ax = with_ax(s.ax, integer::shift((s.ax & 0xffffu),(s.cx & 0xffu),16,flags,integer::Shift::right));
  }
  L004ae461: { // 0x4ae461: 8b0df4b28300 MOV ECX,dword ptr [0x0083b2f4]
    s.cx = m.r32((0x0083b2f4u));
  }
  L004ae467: { // 0x4ae467: d2e0 SHL AL,CL
    s.ax = with_al(s.ax, integer::shift((s.ax & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::left));
  }
  L004ae469: { // 0x4ae469: 668b8c2490000000 MOV CX,word ptr [ESP + 0x90]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000090u)));
  }
  L004ae471: { // 0x4ae471: 66898c2494000000 MOV word ptr [ESP + 0x94],CX
    m.w16((f.sp+0x00000094u), (s.cx & 0xffffu));
  }
  L004ae479: { // 0x4ae479: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L004ae47b: { // 0x4ae47b: 0faf4c242c IMUL ECX,dword ptr [ESP + 0x2c]
    s.cx = integer::imul(s.cx,m.r32((f.sp+0x0000002cu)),32,flags);
  }
  L004ae480: { // 0x4ae480: 88842496000000 MOV byte ptr [ESP + 0x96],AL
    m.w8((f.sp+0x00000096u), (s.ax & 0xffu));
  }
  L004ae487: { // 0x4ae487: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L004ae489: { // 0x4ae489: 0faf442428 IMUL EAX,dword ptr [ESP + 0x28]
    s.ax = integer::imul(s.ax,m.r32((f.sp+0x00000028u)),32,flags);
  }
  L004ae48e: { // 0x4ae48e: 0faf542430 IMUL EDX,dword ptr [ESP + 0x30]
    s.dx = integer::imul(s.dx,m.r32((f.sp+0x00000030u)),32,flags);
  }
  L004ae493: { // 0x4ae493: c1f807 SAR EAX,0x7
    s.ax = integer::shift(s.ax,0x00000007u,32,flags,integer::Shift::arithmetic_right);
  }
  L004ae496: { // 0x4ae496: c1f907 SAR ECX,0x7
    s.cx = integer::shift(s.cx,0x00000007u,32,flags,integer::Shift::arithmetic_right);
  }
  L004ae499: { // 0x4ae499: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004ae49a: { // 0x4ae49a: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004ae49b: { // 0x4ae49b: c1fa07 SAR EDX,0x7
    s.dx = integer::shift(s.dx,0x00000007u,32,flags,integer::Shift::arithmetic_right);
  }
  L004ae49e: { // 0x4ae49e: 8d8c249c000000 LEA ECX,[ESP + 0x9c]
    s.cx = (f.sp+0x0000009cu);
  }
  L004ae4a5: { // 0x4ae4a5: e836010000 CALL 0x004ae5e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ae5e0u,4908202u,op); flags=s.arithmetic_flags;
  }
  L004ae4aa: { // 0x4ae4aa: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L004ae4ae: { // 0x4ae4ae: 8b7c243c MOV EDI,dword ptr [ESP + 0x3c]
    s.di = m.r32((f.sp+0x0000003cu));
  }
  L004ae4b2: { // 0x4ae4b2: 6689041a MOV word ptr [EDX + EBX*0x1],AX
    m.w16((s.dx+(s.bx * 0x00000001u)), (s.ax & 0xffffu));
  }
  L004ae4b6: { // 0x4ae4b6: 8b0dac1f8200 MOV ECX,dword ptr [0x00821fac]
    s.cx = m.r32((0x00821facu));
  }
  L004ae4bc: { // 0x4ae4bc: 8b5c2438 MOV EBX,dword ptr [ESP + 0x38]
    s.bx = m.r32((f.sp+0x00000038u));
  }
  L004ae4c0: { // 0x4ae4c0: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L004ae4c2: { // 0x4ae4c2: 7e1f JLE 0x004ae4e3
    if(integer::condition("JLE",flags)) goto L004ae4e3;
  }
  L004ae4c4: { // 0x4ae4c4: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L004ae4c8: { // 0x4ae4c8: 8b411c MOV EAX,dword ptr [ECX + 0x1c]
    s.ax = m.r32((s.cx+0x0000001cu));
  }
  L004ae4cb: { // 0x4ae4cb: 83c602 ADD ESI,0x2
    s.si = integer::add(s.si,0x00000002u,32,flags);
  }
  L004ae4ce: { // 0x4ae4ce: 83c202 ADD EDX,0x2
    s.dx = integer::add(s.dx,0x00000002u,32,flags);
  }
  L004ae4d1: { // 0x4ae4d1: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L004ae4d3: { // 0x4ae4d3: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L004ae4d7: { // 0x4ae4d7: 7203 JC 0x004ae4dc
    if(integer::condition("JC",flags)) goto L004ae4dc;
  }
  L004ae4d9: { // 0x4ae4d9: 2b7120 SUB ESI,dword ptr [ECX + 0x20]
    s.si = integer::sub(s.si,m.r32((s.cx+0x00000020u)),32,flags);
  }
  L004ae4dc: { // 0x4ae4dc: 2bbc2484000000 SUB EDI,dword ptr [ESP + 0x84]
    s.di = integer::sub(s.di,m.r32((f.sp+0x00000084u)),32,flags);
  }
  L004ae4e3: { // 0x4ae4e3: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L004ae4e5: { // 0x4ae4e5: 7e1d JLE 0x004ae504
    if(integer::condition("JLE",flags)) goto L004ae504;
  }
  L004ae4e7: { // 0x4ae4e7: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L004ae4eb: { // 0x4ae4eb: 8b942498000000 MOV EDX,dword ptr [ESP + 0x98]
    s.dx = m.r32((f.sp+0x00000098u));
  }
  L004ae4f2: { // 0x4ae4f2: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L004ae4f4: { // 0x4ae4f4: 8b842484000000 MOV EAX,dword ptr [ESP + 0x84]
    s.ax = m.r32((f.sp+0x00000084u));
  }
  L004ae4fb: { // 0x4ae4fb: 89942498000000 MOV dword ptr [ESP + 0x98],EDX
    m.w32((f.sp+0x00000098u), s.dx);
  }
  L004ae502: { // 0x4ae502: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L004ae504: { // 0x4ae504: 8b842488000000 MOV EAX,dword ptr [ESP + 0x88]
    s.ax = m.r32((f.sp+0x00000088u));
  }
  L004ae50b: { // 0x4ae50b: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L004ae50f: { // 0x4ae50f: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L004ae511: { // 0x4ae511: 8b84248c000000 MOV EAX,dword ptr [ESP + 0x8c]
    s.ax = m.r32((f.sp+0x0000008cu));
  }
  L004ae518: { // 0x4ae518: 03da ADD EBX,EDX
    s.bx = integer::add(s.bx,s.dx,32,flags);
  }
  L004ae51a: { // 0x4ae51a: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L004ae51e: { // 0x4ae51e: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004ae520: { // 0x4ae520: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L004ae524: { // 0x4ae524: 8984248c000000 MOV dword ptr [ESP + 0x8c],EAX
    m.w32((f.sp+0x0000008cu), s.ax);
  }
  L004ae52b: { // 0x4ae52b: 8b842480000000 MOV EAX,dword ptr [ESP + 0x80]
    s.ax = m.r32((f.sp+0x00000080u));
  }
  L004ae532: { // 0x4ae532: 03f2 ADD ESI,EDX
    s.si = integer::add(s.si,s.dx,32,flags);
  }
  L004ae534: { // 0x4ae534: 897c243c MOV dword ptr [ESP + 0x3c],EDI
    m.w32((f.sp+0x0000003cu), s.di);
  }
  L004ae538: { // 0x4ae538: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004ae53a: { // 0x4ae53a: 895c2438 MOV dword ptr [ESP + 0x38],EBX
    m.w32((f.sp+0x00000038u), s.bx);
  }
  L004ae53e: { // 0x4ae53e: 7e0a JLE 0x004ae54a
    if(integer::condition("JLE",flags)) goto L004ae54a;
  }
  L004ae540: { // 0x4ae540: 3b711c CMP ESI,dword ptr [ECX + 0x1c]
    (void)integer::sub(s.si,m.r32((s.cx+0x0000001cu)),32,flags);
  }
  L004ae543: { // 0x4ae543: 7215 JC 0x004ae55a
    if(integer::condition("JC",flags)) goto L004ae55a;
  }
  L004ae545: { // 0x4ae545: 2b7120 SUB ESI,dword ptr [ECX + 0x20]
    s.si = integer::sub(s.si,m.r32((s.cx+0x00000020u)),32,flags);
  }
  L004ae548: { // 0x4ae548: eb10 JMP 0x004ae55a
    goto L004ae55a;
  }
  L004ae54a: { // 0x4ae54a: 8b5118 MOV EDX,dword ptr [ECX + 0x18]
    s.dx = m.r32((s.cx+0x00000018u));
  }
  L004ae54d: { // 0x4ae54d: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004ae54f: { // 0x4ae54f: 3bf2 CMP ESI,EDX
    (void)integer::sub(s.si,s.dx,32,flags);
  }
  L004ae551: { // 0x4ae551: 7305 JNC 0x004ae558
    if(integer::condition("JNC",flags)) goto L004ae558;
  }
  L004ae553: { // 0x4ae553: 8b4120 MOV EAX,dword ptr [ECX + 0x20]
    s.ax = m.r32((s.cx+0x00000020u));
  }
  L004ae556: { // 0x4ae556: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L004ae558: { // 0x4ae558: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L004ae55a: { // 0x4ae55a: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L004ae55e: { // 0x4ae55e: 8b842480000000 MOV EAX,dword ptr [ESP + 0x80]
    s.ax = m.r32((f.sp+0x00000080u));
  }
  L004ae565: { // 0x4ae565: 03ea ADD EBP,EDX
    s.bp = integer::add(s.bp,s.dx,32,flags);
  }
  L004ae567: { // 0x4ae567: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004ae569: { // 0x4ae569: 7e0f JLE 0x004ae57a
    if(integer::condition("JLE",flags)) goto L004ae57a;
  }
  L004ae56b: { // 0x4ae56b: a1f4988100 MOV EAX,[0x008198f4]
    s.ax = m.r32((0x008198f4u));
  }
  L004ae570: { // 0x4ae570: 3b681c CMP EBP,dword ptr [EAX + 0x1c]
    (void)integer::sub(s.bp,m.r32((s.ax+0x0000001cu)),32,flags);
  }
  L004ae573: { // 0x4ae573: 7219 JC 0x004ae58e
    if(integer::condition("JC",flags)) goto L004ae58e;
  }
  L004ae575: { // 0x4ae575: 2b6820 SUB EBP,dword ptr [EAX + 0x20]
    s.bp = integer::sub(s.bp,m.r32((s.ax+0x00000020u)),32,flags);
  }
  L004ae578: { // 0x4ae578: eb14 JMP 0x004ae58e
    goto L004ae58e;
  }
  L004ae57a: { // 0x4ae57a: 8b15f4988100 MOV EDX,dword ptr [0x008198f4]
    s.dx = m.r32((0x008198f4u));
  }
  L004ae580: { // 0x4ae580: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L004ae582: { // 0x4ae582: 3b6a18 CMP EBP,dword ptr [EDX + 0x18]
    (void)integer::sub(s.bp,m.r32((s.dx+0x00000018u)),32,flags);
  }
  L004ae585: { // 0x4ae585: 7305 JNC 0x004ae58c
    if(integer::condition("JNC",flags)) goto L004ae58c;
  }
  L004ae587: { // 0x4ae587: 8b4220 MOV EAX,dword ptr [EDX + 0x20]
    s.ax = m.r32((s.dx+0x00000020u));
  }
  L004ae58a: { // 0x4ae58a: 03c5 ADD EAX,EBP
    s.ax = integer::add(s.ax,s.bp,32,flags);
  }
  L004ae58c: { // 0x4ae58c: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L004ae58e: { // 0x4ae58e: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L004ae592: { // 0x4ae592: 8b942498000000 MOV EDX,dword ptr [ESP + 0x98]
    s.dx = m.r32((f.sp+0x00000098u));
  }
  L004ae599: { // 0x4ae599: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L004ae59b: { // 0x4ae59b: 8b44244c MOV EAX,dword ptr [ESP + 0x4c]
    s.ax = m.r32((f.sp+0x0000004cu));
  }
  L004ae59f: { // 0x4ae59f: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L004ae5a0: { // 0x4ae5a0: 89942498000000 MOV dword ptr [ESP + 0x98],EDX
    m.w32((f.sp+0x00000098u), s.dx);
  }
  L004ae5a7: { // 0x4ae5a7: 8944244c MOV dword ptr [ESP + 0x4c],EAX
    m.w32((f.sp+0x0000004cu), s.ax);
  }
  L004ae5ab: { // 0x4ae5ab: 0f8548feffff JNZ 0x004ae3f9
    if(integer::condition("JNZ",flags)) goto L004ae3f9;
  }
  L004ae5b1: { // 0x4ae5b1: 8b4c2434 MOV ECX,dword ptr [ESP + 0x34]
    s.cx = m.r32((f.sp+0x00000034u));
  }
  L004ae5b5: { // 0x4ae5b5: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L004ae5b7: { // 0x4ae5b7: ff5260 CALL dword ptr [EDX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),4908474u,op); flags=s.arithmetic_flags;
  }
  L004ae5ba: { // 0x4ae5ba: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004ae5bb: { // 0x4ae5bb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004ae5bc: { // 0x4ae5bc: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004ae5bd: { // 0x4ae5bd: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L004ae5bf: { // 0x4ae5bf: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004ae5c0: { // 0x4ae5c0: 83c46c ADD ESP,0x6c
    f.sp = integer::add(f.sp,0x0000006cu,32,flags);
  }
  L004ae5c3: { // 0x4ae5c3: c21c00 RET 0x1c
    s.arithmetic_flags=flags; finish(m,s,f,28u); return;
  }
  L004ae5c6: { // 0x4ae5c6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004ae5c7: { // 0x4ae5c7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004ae5c8: { // 0x4ae5c8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004ae5c9: { // 0x4ae5c9: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004ae5cb: { // 0x4ae5cb: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004ae5cc: { // 0x4ae5cc: 83c46c ADD ESP,0x6c
    f.sp = integer::add(f.sp,0x0000006cu,32,flags);
  }
  L004ae5cf: { // 0x4ae5cf: c21c00 RET 0x1c
    s.arithmetic_flags=flags; finish(m,s,f,28u); return;
  }
}

void f_00011230(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00411230: { // 0x411230: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L00411234: { // 0x411234: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00411235: { // 0x411235: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00411237: { // 0x411237: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00411238: { // 0x411238: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00411239: { // 0x411239: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0041123d: { // 0x41123d: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx = m.r32((s.si+0x00000014u));
  }
  L00411240: { // 0x411240: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00411241: { // 0x411241: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00411243: { // 0x411243: ff505c CALL dword ptr [EAX + 0x5c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000005cu)),4264518u,op); flags=s.arithmetic_flags;
  }
  L00411246: { // 0x411246: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx = m.r32((s.si+0x00000014u));
  }
  L00411249: { // 0x411249: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0041124b: { // 0x41124b: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0041124d: { // 0x41124d: ff5060 CALL dword ptr [EAX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000060u)),4264528u,op); flags=s.arithmetic_flags;
  }
  L00411250: { // 0x411250: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L00411253: { // 0x411253: 8b4e1c MOV ECX,dword ptr [ESI + 0x1c]
    s.cx = m.r32((s.si+0x0000001cu));
  }
  L00411256: { // 0x411256: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L00411258: { // 0x411258: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0041125a: { // 0x41125a: 7203 JC 0x0041125f
    if(integer::condition("JC",flags)) goto L0041125f;
  }
  L0041125c: { // 0x41125c: 2b4620 SUB EAX,dword ptr [ESI + 0x20]
    s.ax = integer::sub(s.ax,m.r32((s.si+0x00000020u)),32,flags);
  }
  L0041125f: { // 0x41125f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00411260: { // 0x411260: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00411261: { // 0x411261: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}

void f_00361c80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00761c80: { // 0x761c80: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L00761c84: { // 0x761c84: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00761c85: { // 0x761c85: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00761c87: { // 0x761c87: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00761c88: { // 0x761c88: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00761c89: { // 0x761c89: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00761c8d: { // 0x761c8d: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx = m.r32((s.si+0x00000014u));
  }
  L00761c90: { // 0x761c90: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00761c91: { // 0x761c91: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00761c93: { // 0x761c93: ff505c CALL dword ptr [EAX + 0x5c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000005cu)),7740566u,op); flags=s.arithmetic_flags;
  }
  L00761c96: { // 0x761c96: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx = m.r32((s.si+0x00000014u));
  }
  L00761c99: { // 0x761c99: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00761c9b: { // 0x761c9b: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00761c9d: { // 0x761c9d: ff5060 CALL dword ptr [EAX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000060u)),7740576u,op); flags=s.arithmetic_flags;
  }
  L00761ca0: { // 0x761ca0: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L00761ca3: { // 0x761ca3: 8b4e1c MOV ECX,dword ptr [ESI + 0x1c]
    s.cx = m.r32((s.si+0x0000001cu));
  }
  L00761ca6: { // 0x761ca6: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L00761ca8: { // 0x761ca8: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00761caa: { // 0x761caa: 7203 JC 0x00761caf
    if(integer::condition("JC",flags)) goto L00761caf;
  }
  L00761cac: { // 0x761cac: 2b4620 SUB EAX,dword ptr [ESI + 0x20]
    s.ax = integer::sub(s.ax,m.r32((s.si+0x00000020u)),32,flags);
  }
  L00761caf: { // 0x761caf: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00761cb0: { // 0x761cb0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00761cb1: { // 0x761cb1: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}

void f_000ae5e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004ae5e0: { // 0x4ae5e0: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004ae5e2: { // 0x4ae5e2: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004ae5e3: { // 0x4ae5e3: 8a01 MOV AL,byte ptr [ECX]
    s.ax = with_al(s.ax, m.r8((s.cx)));
  }
  L004ae5e5: { // 0x4ae5e5: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004ae5e6: { // 0x4ae5e6: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  L004ae5ea: { // 0x4ae5ea: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L004ae5ec: { // 0x4ae5ec: 03f2 ADD ESI,EDX
    s.si = integer::add(s.si,s.dx,32,flags);
  }
  L004ae5ee: { // 0x4ae5ee: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L004ae5f0: { // 0x4ae5f0: 8a5101 MOV DL,byte ptr [ECX + 0x1]
    s.dx = with_al(s.dx, m.r8((s.cx+0x00000001u)));
  }
  L004ae5f3: { // 0x4ae5f3: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004ae5f5: { // 0x4ae5f5: 8a4102 MOV AL,byte ptr [ECX + 0x2]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000002u)));
  }
  L004ae5f8: { // 0x4ae5f8: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L004ae5fc: { // 0x4ae5fc: 03d7 ADD EDX,EDI
    s.dx = integer::add(s.dx,s.di,32,flags);
  }
  L004ae5fe: { // 0x4ae5fe: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L004ae600: { // 0x4ae600: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L004ae602: { // 0x4ae602: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L004ae604: { // 0x4ae604: 81feff000000 CMP ESI,0xff
    (void)integer::sub(s.si,0x000000ffu,32,flags);
  }
  L004ae60a: { // 0x4ae60a: 7c0b JL 0x004ae617
    if(integer::condition("JL",flags)) goto L004ae617;
  }
  L004ae60c: { // 0x4ae60c: bf01000000 MOV EDI,0x1
    s.di = 0x00000001u;
  }
  L004ae611: { // 0x4ae611: 8d8e01ffffff LEA ECX,[ESI + 0xffffff01]
    s.cx = (s.si+0xffffff01u);
  }
  L004ae617: { // 0x4ae617: 81faff000000 CMP EDX,0xff
    (void)integer::sub(s.dx,0x000000ffu,32,flags);
  }
  L004ae61d: { // 0x4ae61d: 7c08 JL 0x004ae627
    if(integer::condition("JL",flags)) goto L004ae627;
  }
  L004ae61f: { // 0x4ae61f: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L004ae620: { // 0x4ae620: 8d8c1101ffffff LEA ECX,[ECX + EDX*0x1 + 0xffffff01]
    s.cx = (s.cx+(s.dx * 0x00000001u)+0xffffff01u);
  }
  L004ae627: { // 0x4ae627: 3dff000000 CMP EAX,0xff
    (void)integer::sub(s.ax,0x000000ffu,32,flags);
  }
  L004ae62c: { // 0x4ae62c: 7c08 JL 0x004ae636
    if(integer::condition("JL",flags)) goto L004ae636;
  }
  L004ae62e: { // 0x4ae62e: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L004ae62f: { // 0x4ae62f: 8d8c0101ffffff LEA ECX,[ECX + EAX*0x1 + 0xffffff01]
    s.cx = (s.cx+(s.ax * 0x00000001u)+0xffffff01u);
  }
  L004ae636: { // 0x4ae636: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L004ae638: { // 0x4ae638: 7429 JZ 0x004ae663
    if(integer::condition("JZ",flags)) goto L004ae663;
  }
  L004ae63a: { // 0x4ae63a: 83ff03 CMP EDI,0x3
    (void)integer::sub(s.di,0x00000003u,32,flags);
  }
  L004ae63d: { // 0x4ae63d: 7d24 JGE 0x004ae663
    if(integer::condition("JGE",flags)) goto L004ae663;
  }
  L004ae63f: { // 0x4ae63f: 83ff01 CMP EDI,0x1
    (void)integer::sub(s.di,0x00000001u,32,flags);
  }
  L004ae642: { // 0x4ae642: 7502 JNZ 0x004ae646
    if(integer::condition("JNZ",flags)) goto L004ae646;
  }
  L004ae644: { // 0x4ae644: d1f9 SAR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L004ae646: { // 0x4ae646: 81feff000000 CMP ESI,0xff
    (void)integer::sub(s.si,0x000000ffu,32,flags);
  }
  L004ae64c: { // 0x4ae64c: 7d02 JGE 0x004ae650
    if(integer::condition("JGE",flags)) goto L004ae650;
  }
  L004ae64e: { // 0x4ae64e: 03f1 ADD ESI,ECX
    s.si = integer::add(s.si,s.cx,32,flags);
  }
  L004ae650: { // 0x4ae650: 81faff000000 CMP EDX,0xff
    (void)integer::sub(s.dx,0x000000ffu,32,flags);
  }
  L004ae656: { // 0x4ae656: 7d02 JGE 0x004ae65a
    if(integer::condition("JGE",flags)) goto L004ae65a;
  }
  L004ae658: { // 0x4ae658: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L004ae65a: { // 0x4ae65a: 3dff000000 CMP EAX,0xff
    (void)integer::sub(s.ax,0x000000ffu,32,flags);
  }
  L004ae65f: { // 0x4ae65f: 7d07 JGE 0x004ae668
    if(integer::condition("JGE",flags)) goto L004ae668;
  }
  L004ae661: { // 0x4ae661: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L004ae663: { // 0x4ae663: 3dff000000 CMP EAX,0xff
    (void)integer::sub(s.ax,0x000000ffu,32,flags);
  }
  L004ae668: { // 0x4ae668: 7e05 JLE 0x004ae66f
    if(integer::condition("JLE",flags)) goto L004ae66f;
  }
  L004ae66a: { // 0x4ae66a: b8ff000000 MOV EAX,0xff
    s.ax = 0x000000ffu;
  }
  L004ae66f: { // 0x4ae66f: 81faff000000 CMP EDX,0xff
    (void)integer::sub(s.dx,0x000000ffu,32,flags);
  }
  L004ae675: { // 0x4ae675: 7e05 JLE 0x004ae67c
    if(integer::condition("JLE",flags)) goto L004ae67c;
  }
  L004ae677: { // 0x4ae677: baff000000 MOV EDX,0xff
    s.dx = 0x000000ffu;
  }
  L004ae67c: { // 0x4ae67c: 81feff000000 CMP ESI,0xff
    (void)integer::sub(s.si,0x000000ffu,32,flags);
  }
  L004ae682: { // 0x4ae682: 7e05 JLE 0x004ae689
    if(integer::condition("JLE",flags)) goto L004ae689;
  }
  L004ae684: { // 0x4ae684: beff000000 MOV ESI,0xff
    s.si = 0x000000ffu;
  }
  L004ae689: { // 0x4ae689: 8b0df4b28300 MOV ECX,dword ptr [0x0083b2f4]
    s.cx = m.r32((0x0083b2f4u));
  }
  L004ae68f: { // 0x4ae68f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004ae690: { // 0x4ae690: d3f8 SAR EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::arithmetic_right);
  }
  L004ae692: { // 0x4ae692: 8b0df0b28300 MOV ECX,dword ptr [0x0083b2f0]
    s.cx = m.r32((0x0083b2f0u));
  }
  L004ae698: { // 0x4ae698: d3e0 SHL EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L004ae69a: { // 0x4ae69a: 8b0dfcb28300 MOV ECX,dword ptr [0x0083b2fc]
    s.cx = m.r32((0x0083b2fcu));
  }
  L004ae6a0: { // 0x4ae6a0: d3fa SAR EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::arithmetic_right);
  }
  L004ae6a2: { // 0x4ae6a2: 8b0df8b28300 MOV ECX,dword ptr [0x0083b2f8]
    s.cx = m.r32((0x0083b2f8u));
  }
  L004ae6a8: { // 0x4ae6a8: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L004ae6aa: { // 0x4ae6aa: 8b0decb28300 MOV ECX,dword ptr [0x0083b2ec]
    s.cx = m.r32((0x0083b2ecu));
  }
  L004ae6b0: { // 0x4ae6b0: d3fe SAR ESI,CL
    s.si = integer::shift(s.si,(s.cx & 0xffu),32,flags,integer::Shift::arithmetic_right);
  }
  L004ae6b2: { // 0x4ae6b2: 8b0de8b28300 MOV ECX,dword ptr [0x0083b2e8]
    s.cx = m.r32((0x0083b2e8u));
  }
  L004ae6b8: { // 0x4ae6b8: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  L004ae6ba: { // 0x4ae6ba: d3e6 SHL ESI,CL
    s.si = integer::shift(s.si,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L004ae6bc: { // 0x4ae6bc: 0bc6 OR EAX,ESI
    s.ax = integer::logical((s.ax)|(s.si),32,flags);
  }
  L004ae6be: { // 0x4ae6be: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004ae6bf: { // 0x4ae6bf: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}

void f_00011290(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00411290: { // 0x411290: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L00411294: { // 0x411294: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00411295: { // 0x411295: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00411296: { // 0x411296: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00411297: { // 0x411297: 8b7904 MOV EDI,dword ptr [ECX + 0x4]
    s.di = m.r32((s.cx+0x00000004u));
  }
  L0041129a: { // 0x41129a: 8b4908 MOV ECX,dword ptr [ECX + 0x8]
    s.cx = m.r32((s.cx+0x00000008u));
  }
  L0041129d: { // 0x41129d: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0041129f: { // 0x41129f: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L004112a1: { // 0x4112a1: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L004112a3: { // 0x4112a3: 8913 MOV dword ptr [EBX],EDX
    m.w32((s.bx), s.dx);
  }
  L004112a5: { // 0x4112a5: 897304 MOV dword ptr [EBX + 0x4],ESI
    m.w32((s.bx+0x00000004u), s.si);
  }
  L004112a8: { // 0x4112a8: 897b08 MOV dword ptr [EBX + 0x8],EDI
    m.w32((s.bx+0x00000008u), s.di);
  }
  L004112ab: { // 0x4112ab: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004112ac: { // 0x4112ac: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004112ad: { // 0x4112ad: 894b0c MOV dword ptr [EBX + 0xc],ECX
    m.w32((s.bx+0x0000000cu), s.cx);
  }
  L004112b0: { // 0x4112b0: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004112b1: { // 0x4112b1: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_000112c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004112c0: { // 0x4112c0: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L004112c3: { // 0x4112c3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_000112f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004112f0: { // 0x4112f0: 8b410c MOV EAX,dword ptr [ECX + 0xc]
    s.ax = m.r32((s.cx+0x0000000cu));
  }
  L004112f3: { // 0x4112f3: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L004112f4: { // 0x4112f4: 89410c MOV dword ptr [ECX + 0xc],EAX
    m.w32((s.cx+0x0000000cu), s.ax);
  }
  L004112f7: { // 0x4112f7: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L004112f9: { // 0x4112f9: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_00011370(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00411370: { // 0x411370: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00411371: { // 0x411371: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00411372: { // 0x411372: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00411374: { // 0x411374: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00411375: { // 0x411375: 8b7e0c MOV EDI,dword ptr [ESI + 0xc]
    s.di = m.r32((s.si+0x0000000cu));
  }
  L00411378: { // 0x411378: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0041137a: { // 0x41137a: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0041137b: { // 0x41137b: 897e0c MOV dword ptr [ESI + 0xc],EDI
    m.w32((s.si+0x0000000cu), s.di);
  }
  L0041137e: { // 0x41137e: 8b7e14 MOV EDI,dword ptr [ESI + 0x14]
    s.di = m.r32((s.si+0x00000014u));
  }
  L00411381: { // 0x411381: ff5070 CALL dword ptr [EAX + 0x70]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000070u)),4264836u,op); flags=s.arithmetic_flags;
  }
  L00411384: { // 0x411384: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00411386: { // 0x411386: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00411388: { // 0x411388: 0faf5c2410 IMUL EBX,dword ptr [ESP + 0x10]
    s.bx = integer::imul(s.bx,m.r32((f.sp+0x00000010u)),32,flags);
  }
  L0041138d: { // 0x41138d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0041138f: { // 0x41138f: ff5274 CALL dword ptr [EDX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000074u)),4264850u,op); flags=s.arithmetic_flags;
  }
  L00411392: { // 0x411392: 0faf442414 IMUL EAX,dword ptr [ESP + 0x14]
    s.ax = integer::imul(s.ax,m.r32((f.sp+0x00000014u)),32,flags);
  }
  L00411397: { // 0x411397: 03fb ADD EDI,EBX
    s.di = integer::add(s.di,s.bx,32,flags);
  }
  L00411399: { // 0x411399: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L0041139b: { // 0x41139b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0041139c: { // 0x41139c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0041139d: { // 0x41139d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0041139e: { // 0x41139e: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}

void f_000113b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004113b0: { // 0x4113b0: 8b4110 MOV EAX,dword ptr [ECX + 0x10]
    s.ax = m.r32((s.cx+0x00000010u));
  }
  L004113b3: { // 0x4113b3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_000113c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004113c0: { // 0x004113c0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004113c1: { // 0x004113c1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004113c3: { // 0x004113c3: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004113c5: { // 0x004113c5: ff507c CALL dword ptr [EAX + 0x7c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000007cu)),4264904u,op); flags=s.arithmetic_flags;
  }
  L004113c8: { // 0x004113c8: 0faf4610 IMUL EAX,dword ptr [ESI + 0x10]
    s.ax = integer::imul(s.ax,m.r32((s.si+0x00000010u)),32,flags);
  }
  L004113cc: { // 0x004113cc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004113cd: { // 0x004113cd: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_0001fdf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0041fdf0: { // 0x41fdf0: 83ec18 SUB ESP,0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
  L0041fdf3: { // 0x41fdf3: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0041fdf5: { // 0x41fdf5: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0041fdf6: { // 0x41fdf6: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L0041fdfa: { // 0x41fdfa: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0041fdfb: { // 0x41fdfb: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0041fdfc: { // 0x41fdfc: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0041fdfe: { // 0x41fdfe: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0041fdff: { // 0x41fdff: 8b1e MOV EBX,dword ptr [ESI]
    s.bx = m.r32((s.si));
  }
  L0041fe01: { // 0x41fe01: 8b7e04 MOV EDI,dword ptr [ESI + 0x4]
    s.di = m.r32((s.si+0x00000004u));
  }
  L0041fe04: { // 0x41fe04: 8b6e08 MOV EBP,dword ptr [ESI + 0x8]
    s.bp = m.r32((s.si+0x00000008u));
  }
  L0041fe07: { // 0x41fe07: 896c2420 MOV dword ptr [ESP + 0x20],EBP
    m.w32((f.sp+0x00000020u), s.bp);
  }
  L0041fe0b: { // 0x41fe0b: 8b760c MOV ESI,dword ptr [ESI + 0xc]
    s.si = m.r32((s.si+0x0000000cu));
  }
  L0041fe0e: { // 0x41fe0e: 89742424 MOV dword ptr [ESP + 0x24],ESI
    m.w32((f.sp+0x00000024u), s.si);
  }
  L0041fe12: { // 0x41fe12: 8b7208 MOV ESI,dword ptr [EDX + 0x8]
    s.si = m.r32((s.dx+0x00000008u));
  }
  L0041fe15: { // 0x41fe15: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0041fe17: { // 0x41fe17: 0f8edb000000 JLE 0x0041fef8
    if(integer::condition("JLE",flags)) goto L0041fef8;
  }
  L0041fe1d: { // 0x41fe1d: 8b6a0c MOV EBP,dword ptr [EDX + 0xc]
    s.bp = m.r32((s.dx+0x0000000cu));
  }
  L0041fe20: { // 0x41fe20: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0041fe22: { // 0x41fe22: 896c2414 MOV dword ptr [ESP + 0x14],EBP
    m.w32((f.sp+0x00000014u), s.bp);
  }
  L0041fe26: { // 0x41fe26: 0f8ecc000000 JLE 0x0041fef8
    if(integer::condition("JLE",flags)) goto L0041fef8;
  }
  L0041fe2c: { // 0x41fe2c: 8b6908 MOV EBP,dword ptr [ECX + 0x8]
    s.bp = m.r32((s.cx+0x00000008u));
  }
  L0041fe2f: { // 0x41fe2f: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0041fe31: { // 0x41fe31: 0f8ec1000000 JLE 0x0041fef8
    if(integer::condition("JLE",flags)) goto L0041fef8;
  }
  L0041fe37: { // 0x41fe37: 8b690c MOV EBP,dword ptr [ECX + 0xc]
    s.bp = m.r32((s.cx+0x0000000cu));
  }
  L0041fe3a: { // 0x41fe3a: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0041fe3c: { // 0x41fe3c: 0f8eb6000000 JLE 0x0041fef8
    if(integer::condition("JLE",flags)) goto L0041fef8;
  }
  L0041fe42: { // 0x41fe42: 8b0a MOV ECX,dword ptr [EDX]
    s.cx = m.r32((s.dx));
  }
  L0041fe44: { // 0x41fe44: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L0041fe46: { // 0x41fe46: 7d0e JGE 0x0041fe56
    if(integer::condition("JGE",flags)) goto L0041fe56;
  }
  L0041fe48: { // 0x41fe48: 8b6c2420 MOV EBP,dword ptr [ESP + 0x20]
    s.bp = m.r32((f.sp+0x00000020u));
  }
  L0041fe4c: { // 0x41fe4c: 2bd9 SUB EBX,ECX
    s.bx = integer::sub(s.bx,s.cx,32,flags);
  }
  L0041fe4e: { // 0x41fe4e: 03eb ADD EBP,EBX
    s.bp = integer::add(s.bp,s.bx,32,flags);
  }
  L0041fe50: { // 0x41fe50: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0041fe52: { // 0x41fe52: 896c2420 MOV dword ptr [ESP + 0x20],EBP
    m.w32((f.sp+0x00000020u), s.bp);
  }
  L0041fe56: { // 0x41fe56: 837c242001 CMP dword ptr [ESP + 0x20],0x1
    (void)integer::sub(m.r32((f.sp+0x00000020u)),0x00000001u,32,flags);
  }
  L0041fe5b: { // 0x41fe5b: 0f8c97000000 JL 0x0041fef8
    if(integer::condition("JL",flags)) goto L0041fef8;
  }
  L0041fe61: { // 0x41fe61: 8b5204 MOV EDX,dword ptr [EDX + 0x4]
    s.dx = m.r32((s.dx+0x00000004u));
  }
  L0041fe64: { // 0x41fe64: 3bfa CMP EDI,EDX
    (void)integer::sub(s.di,s.dx,32,flags);
  }
  L0041fe66: { // 0x41fe66: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L0041fe6a: { // 0x41fe6a: 7d0e JGE 0x0041fe7a
    if(integer::condition("JGE",flags)) goto L0041fe7a;
  }
  L0041fe6c: { // 0x41fe6c: 8b6c2424 MOV EBP,dword ptr [ESP + 0x24]
    s.bp = m.r32((f.sp+0x00000024u));
  }
  L0041fe70: { // 0x41fe70: 2bfa SUB EDI,EDX
    s.di = integer::sub(s.di,s.dx,32,flags);
  }
  L0041fe72: { // 0x41fe72: 03ef ADD EBP,EDI
    s.bp = integer::add(s.bp,s.di,32,flags);
  }
  L0041fe74: { // 0x41fe74: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L0041fe76: { // 0x41fe76: 896c2424 MOV dword ptr [ESP + 0x24],EBP
    m.w32((f.sp+0x00000024u), s.bp);
  }
  L0041fe7a: { // 0x41fe7a: 837c242401 CMP dword ptr [ESP + 0x24],0x1
    (void)integer::sub(m.r32((f.sp+0x00000024u)),0x00000001u,32,flags);
  }
  L0041fe7f: { // 0x41fe7f: 7c77 JL 0x0041fef8
    if(integer::condition("JL",flags)) goto L0041fef8;
  }
  L0041fe81: { // 0x41fe81: 8b6c2420 MOV EBP,dword ptr [ESP + 0x20]
    s.bp = m.r32((f.sp+0x00000020u));
  }
  L0041fe85: { // 0x41fe85: 8d1431 LEA EDX,[ECX + ESI*0x1]
    s.dx = (s.cx+(s.si * 0x00000001u));
  }
  L0041fe88: { // 0x41fe88: 03eb ADD EBP,EBX
    s.bp = integer::add(s.bp,s.bx,32,flags);
  }
  L0041fe8a: { // 0x41fe8a: 3bea CMP EBP,EDX
    (void)integer::sub(s.bp,s.dx,32,flags);
  }
  L0041fe8c: { // 0x41fe8c: 7e06 JLE 0x0041fe94
    if(integer::condition("JLE",flags)) goto L0041fe94;
  }
  L0041fe8e: { // 0x41fe8e: 2bcb SUB ECX,EBX
    s.cx = integer::sub(s.cx,s.bx,32,flags);
  }
  L0041fe90: { // 0x41fe90: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L0041fe92: { // 0x41fe92: eb04 JMP 0x0041fe98
    goto L0041fe98;
  }
  L0041fe94: { // 0x41fe94: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L0041fe98: { // 0x41fe98: 83f901 CMP ECX,0x1
    (void)integer::sub(s.cx,0x00000001u,32,flags);
  }
  L0041fe9b: { // 0x41fe9b: 7c5b JL 0x0041fef8
    if(integer::condition("JL",flags)) goto L0041fef8;
  }
  L0041fe9d: { // 0x41fe9d: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0041fea1: { // 0x41fea1: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L0041fea5: { // 0x41fea5: 03d6 ADD EDX,ESI
    s.dx = integer::add(s.dx,s.si,32,flags);
  }
  L0041fea7: { // 0x41fea7: 8b742424 MOV ESI,dword ptr [ESP + 0x24]
    s.si = m.r32((f.sp+0x00000024u));
  }
  L0041feab: { // 0x41feab: 8d2c3e LEA EBP,[ESI + EDI*0x1]
    s.bp = (s.si+(s.di * 0x00000001u));
  }
  L0041feae: { // 0x41feae: 3bea CMP EBP,EDX
    (void)integer::sub(s.bp,s.dx,32,flags);
  }
  L0041feb0: { // 0x41feb0: 7e04 JLE 0x0041feb6
    if(integer::condition("JLE",flags)) goto L0041feb6;
  }
  L0041feb2: { // 0x41feb2: 2bd7 SUB EDX,EDI
    s.dx = integer::sub(s.dx,s.di,32,flags);
  }
  L0041feb4: { // 0x41feb4: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L0041feb6: { // 0x41feb6: 83fe01 CMP ESI,0x1
    (void)integer::sub(s.si,0x00000001u,32,flags);
  }
  L0041feb9: { // 0x41feb9: 7c3d JL 0x0041fef8
    if(integer::condition("JL",flags)) goto L0041fef8;
  }
  L0041febb: { // 0x41febb: 8b542430 MOV EDX,dword ptr [ESP + 0x30]
    s.dx = m.r32((f.sp+0x00000030u));
  }
  L0041febf: { // 0x41febf: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0041fec1: { // 0x41fec1: 740b JZ 0x0041fece
    if(integer::condition("JZ",flags)) goto L0041fece;
  }
  L0041fec3: { // 0x41fec3: 8b6c242c MOV EBP,dword ptr [ESP + 0x2c]
    s.bp = m.r32((f.sp+0x0000002cu));
  }
  L0041fec7: { // 0x41fec7: 8b6d00 MOV EBP,dword ptr [EBP]
    s.bp = m.r32((s.bp));
  }
  L0041feca: { // 0x41feca: 2beb SUB EBP,EBX
    s.bp = integer::sub(s.bp,s.bx,32,flags);
  }
  L0041fecc: { // 0x41fecc: 012a ADD dword ptr [EDX],EBP
    m.w32((s.dx), integer::add(m.r32((s.dx)),s.bp,32,flags));
  }
  L0041fece: { // 0x41fece: 8b542434 MOV EDX,dword ptr [ESP + 0x34]
    s.dx = m.r32((f.sp+0x00000034u));
  }
  L0041fed2: { // 0x41fed2: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0041fed4: { // 0x41fed4: 740b JZ 0x0041fee1
    if(integer::condition("JZ",flags)) goto L0041fee1;
  }
  L0041fed6: { // 0x41fed6: 8b6c242c MOV EBP,dword ptr [ESP + 0x2c]
    s.bp = m.r32((f.sp+0x0000002cu));
  }
  L0041feda: { // 0x41feda: 8b6d04 MOV EBP,dword ptr [EBP + 0x4]
    s.bp = m.r32((s.bp+0x00000004u));
  }
  L0041fedd: { // 0x41fedd: 2bef SUB EBP,EDI
    s.bp = integer::sub(s.bp,s.di,32,flags);
  }
  L0041fedf: { // 0x41fedf: 012a ADD dword ptr [EDX],EBP
    m.w32((s.dx), integer::add(m.r32((s.dx)),s.bp,32,flags));
  }
  L0041fee1: { // 0x41fee1: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0041fee3: { // 0x41fee3: 891a MOV dword ptr [EDX],EBX
    m.w32((s.dx), s.bx);
  }
  L0041fee5: { // 0x41fee5: 897a04 MOV dword ptr [EDX + 0x4],EDI
    m.w32((s.dx+0x00000004u), s.di);
  }
  L0041fee8: { // 0x41fee8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0041fee9: { // 0x41fee9: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  L0041feec: { // 0x41feec: 89720c MOV dword ptr [EDX + 0xc],ESI
    m.w32((s.dx+0x0000000cu), s.si);
  }
  L0041feef: { // 0x41feef: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0041fef0: { // 0x41fef0: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0041fef1: { // 0x41fef1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0041fef2: { // 0x41fef2: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L0041fef5: { // 0x41fef5: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L0041fef8: { // 0x41fef8: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0041fefa: { // 0x41fefa: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0041fefc: { // 0x41fefc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0041fefd: { // 0x41fefd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0041fefe: { // 0x41fefe: 890a MOV dword ptr [EDX],ECX
    m.w32((s.dx), s.cx);
  }
  L0041ff00: { // 0x41ff00: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0041ff01: { // 0x41ff01: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0041ff02: { // 0x41ff02: 894a04 MOV dword ptr [EDX + 0x4],ECX
    m.w32((s.dx+0x00000004u), s.cx);
  }
  L0041ff05: { // 0x41ff05: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  L0041ff08: { // 0x41ff08: 894a0c MOV dword ptr [EDX + 0xc],ECX
    m.w32((s.dx+0x0000000cu), s.cx);
  }
  L0041ff0b: { // 0x41ff0b: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L0041ff0e: { // 0x41ff0e: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}

void f_00360f60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00760f60: { // 0x760f60: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00760f61: { // 0x760f61: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L00760f63: { // 0x760f63: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L00760f66: { // 0x760f66: 83ec64 SUB ESP,0x64
    f.sp = integer::sub(f.sp,0x00000064u,32,flags);
  }
  L00760f69: { // 0x760f69: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00760f6a: { // 0x760f6a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00760f6b: { // 0x760f6b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00760f6c: { // 0x760f6c: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L00760f6e: { // 0x760f6e: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L00760f70: { // 0x760f70: 8b4d08 MOV ECX,dword ptr [EBP + 0x8]
    s.cx = m.r32((s.bp+0x00000008u));
  }
  L00760f73: { // 0x760f73: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L00760f77: { // 0x760f77: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00760f79: { // 0x760f79: 8b7104 MOV ESI,dword ptr [ECX + 0x4]
    s.si = m.r32((s.cx+0x00000004u));
  }
  L00760f7c: { // 0x760f7c: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00760f80: { // 0x760f80: 8b5908 MOV EBX,dword ptr [ECX + 0x8]
    s.bx = m.r32((s.cx+0x00000008u));
  }
  L00760f83: { // 0x760f83: db442414 FILD dword ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load_integer32(m.r32(address));
  }
  L00760f87: { // 0x760f87: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L00760f8b: { // 0x760f8b: 03d8 ADD EBX,EAX
    s.bx = integer::add(s.bx,s.ax,32,flags);
  }
  L00760f8d: { // 0x760f8d: dd542430 FST double ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L00760f91: { // 0x760f91: db442414 FILD dword ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load_integer32(m.r32(address));
  }
  L00760f95: { // 0x760f95: 895c2414 MOV dword ptr [ESP + 0x14],EBX
    m.w32((f.sp+0x00000014u), s.bx);
  }
  L00760f99: { // 0x760f99: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L00760f9b: { // 0x760f9b: db02 FILD dword ptr [EDX]
    const auto address=(s.dx);
    s.fp.load_integer32(m.r32(address));
  }
  L00760f9d: { // 0x760f9d: dd5c2438 FSTP double ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00760fa1: { // 0x760fa1: db4204 FILD dword ptr [EDX + 0x4]
    const auto address=(s.dx+0x00000004u);
    s.fp.load_integer32(m.r32(address));
  }
  L00760fa4: { // 0x760fa4: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00760fa6: { // 0x760fa6: dd5c2428 FSTP double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00760faa: { // 0x760faa: db07 FILD dword ptr [EDI]
    const auto address=(s.di);
    s.fp.load_integer32(m.r32(address));
  }
  L00760fac: { // 0x760fac: dd542468 FST double ptr [ESP + 0x68]
    const auto address=(f.sp+0x00000068u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L00760fb0: { // 0x760fb0: db4704 FILD dword ptr [EDI + 0x4]
    const auto address=(s.di+0x00000004u);
    s.fp.load_integer32(m.r32(address));
  }
  L00760fb3: { // 0x760fb3: dd5c2440 FSTP double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00760fb7: { // 0x760fb7: dd442438 FLD double ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.load64(read64(m,address));
  }
  L00760fbb: { // 0x760fbb: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L00760fbd: { // 0x760fbd: d8e1 FSUB ST0,ST1
    numeric_b88::detail::reg<0xd8e1>(s.fp);
  }
  L00760fbf: { // 0x760fbf: dd442440 FLD double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.load64(read64(m,address));
  }
  L00760fc3: { // 0x760fc3: dc642428 FSUB double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.subtract64(read64(m,address));
  }
  L00760fc7: { // 0x760fc7: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L00760fc9: { // 0x760fc9: d8f1 FDIV ST0,ST1
    numeric_b88::detail::reg<0xd8f1>(s.fp);
  }
  L00760fcb: { // 0x760fcb: dd5c2458 FSTP double ptr [ESP + 0x58]
    const auto address=(f.sp+0x00000058u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00760fcf: { // 0x760fcf: d8f1 FDIV ST0,ST1
    numeric_b88::detail::reg<0xd8f1>(s.fp);
  }
  L00760fd1: { // 0x760fd1: dd5c2460 FSTP double ptr [ESP + 0x60]
    const auto address=(f.sp+0x00000060u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00760fd5: { // 0x760fd5: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00760fd7: { // 0x760fd7: db442414 FILD dword ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load_integer32(m.r32(address));
  }
  L00760fdb: { // 0x760fdb: dd5c2448 FSTP double ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00760fdf: { // 0x760fdf: dc542448 FCOM double ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L00760fe3: { // 0x760fe3: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00760fe5: { // 0x760fe5: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00760fe8: { // 0x760fe8: 7509 JNZ 0x00760ff3
    if(integer::condition("JNZ",flags)) goto L00760ff3;
  }
  L00760fea: { // 0x760fea: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00760fec: { // 0x760fec: ba02000000 MOV EDX,0x2
    s.dx = 0x00000002u;
  }
  L00760ff1: { // 0x760ff1: eb0e JMP 0x00761001
    goto L00761001;
  }
  L00760ff3: { // 0x760ff3: d8dc FCOMP ST4
    numeric_b88::detail::reg<0xd8dc>(s.fp);
  }
  L00760ff5: { // 0x760ff5: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00760ff7: { // 0x760ff7: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00760ffa: { // 0x760ffa: 7405 JZ 0x00761001
    if(integer::condition("JZ",flags)) goto L00761001;
  }
  L00760ffc: { // 0x760ffc: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L00761001: { // 0x761001: 8b410c MOV EAX,dword ptr [ECX + 0xc]
    s.ax = m.r32((s.cx+0x0000000cu));
  }
  L00761004: { // 0x761004: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L00761006: { // 0x761006: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0076100a: { // 0x76100a: db442410 FILD dword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load_integer32(m.r32(address));
  }
  L0076100e: { // 0x76100e: dd5c2450 FSTP double ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00761012: { // 0x761012: dd442428 FLD double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.load64(read64(m,address));
  }
  L00761016: { // 0x761016: dc5c2450 FCOMP double ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    s.fp.compare_pop64(read64(m,address));
  }
  L0076101a: { // 0x76101a: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0076101c: { // 0x76101c: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0076101f: { // 0x76101f: 7505 JNZ 0x00761026
    if(integer::condition("JNZ",flags)) goto L00761026;
  }
  L00761021: { // 0x761021: 83ca04 OR EDX,0x4
    s.dx = integer::logical((s.dx)|(0x00000004u),32,flags);
  }
  L00761024: { // 0x761024: eb10 JMP 0x00761036
    goto L00761036;
  }
  L00761026: { // 0x761026: dd442428 FLD double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.load64(read64(m,address));
  }
  L0076102a: { // 0x76102a: d8db FCOMP ST3
    numeric_b88::detail::reg<0xd8db>(s.fp);
  }
  L0076102c: { // 0x76102c: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0076102e: { // 0x76102e: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761031: { // 0x761031: 7403 JZ 0x00761036
    if(integer::condition("JZ",flags)) goto L00761036;
  }
  L00761033: { // 0x761033: 83ca08 OR EDX,0x8
    s.dx = integer::logical((s.dx)|(0x00000008u),32,flags);
  }
  L00761036: { // 0x761036: dc542448 FCOM double ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L0076103a: { // 0x76103a: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0076103c: { // 0x76103c: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0076103e: { // 0x76103e: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761041: { // 0x761041: 7509 JNZ 0x0076104c
    if(integer::condition("JNZ",flags)) goto L0076104c;
  }
  L00761043: { // 0x761043: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00761045: { // 0x761045: b902000000 MOV ECX,0x2
    s.cx = 0x00000002u;
  }
  L0076104a: { // 0x76104a: eb0e JMP 0x0076105a
    goto L0076105a;
  }
  L0076104c: { // 0x76104c: d8db FCOMP ST3
    numeric_b88::detail::reg<0xd8db>(s.fp);
  }
  L0076104e: { // 0x76104e: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00761050: { // 0x761050: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761053: { // 0x761053: 7405 JZ 0x0076105a
    if(integer::condition("JZ",flags)) goto L0076105a;
  }
  L00761055: { // 0x761055: b901000000 MOV ECX,0x1
    s.cx = 0x00000001u;
  }
  L0076105a: { // 0x76105a: dd442440 FLD double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.load64(read64(m,address));
  }
  L0076105e: { // 0x76105e: dc5c2450 FCOMP double ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00761062: { // 0x761062: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00761064: { // 0x761064: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761067: { // 0x761067: 7505 JNZ 0x0076106e
    if(integer::condition("JNZ",flags)) goto L0076106e;
  }
  L00761069: { // 0x761069: 83c904 OR ECX,0x4
    s.cx = integer::logical((s.cx)|(0x00000004u),32,flags);
  }
  L0076106c: { // 0x76106c: eb10 JMP 0x0076107e
    goto L0076107e;
  }
  L0076106e: { // 0x76106e: dd442440 FLD double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.load64(read64(m,address));
  }
  L00761072: { // 0x761072: d8da FCOMP ST2
    numeric_b88::detail::reg<0xd8da>(s.fp);
  }
  L00761074: { // 0x761074: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00761076: { // 0x761076: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761079: { // 0x761079: 7403 JZ 0x0076107e
    if(integer::condition("JZ",flags)) goto L0076107e;
  }
  L0076107b: { // 0x76107b: 83c908 OR ECX,0x8
    s.cx = integer::logical((s.cx)|(0x00000008u),32,flags);
  }
  L0076107e: { // 0x76107e: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00761080: { // 0x761080: 7508 JNZ 0x0076108a
    if(integer::condition("JNZ",flags)) goto L0076108a;
  }
  L00761082: { // 0x761082: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00761084: { // 0x761084: 0f844f010000 JZ 0x007611d9
    if(integer::condition("JZ",flags)) goto L007611d9;
  }
  L0076108a: { // 0x76108a: 85ca TEST EDX,ECX
    (void)integer::logical((s.dx)&(s.cx),32,flags);
  }
  L0076108c: { // 0x76108c: 0f858a010000 JNZ 0x0076121c
    if(integer::condition("JNZ",flags)) goto L0076121c;
  }
  L00761092: { // 0x761092: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00761094: { // 0x761094: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L00761096: { // 0x761096: 7502 JNZ 0x0076109a
    if(integer::condition("JNZ",flags)) goto L0076109a;
  }
  L00761098: { // 0x761098: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0076109a: { // 0x76109a: a808 TEST AL,0x8
    (void)integer::logical(((s.ax & 0xffu))&(0x00000008u),8,flags);
  }
  L0076109c: { // 0x76109c: 7418 JZ 0x007610b6
    if(integer::condition("JZ",flags)) goto L007610b6;
  }
  L0076109e: { // 0x76109e: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L007610a0: { // 0x7610a0: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L007610a2: { // 0x7610a2: dc642428 FSUB double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.subtract64(read64(m,address));
  }
  L007610a6: { // 0x7610a6: dc4c2458 FMUL double ptr [ESP + 0x58]
    const auto address=(f.sp+0x00000058u);
    s.fp.multiply64(read64(m,address));
  }
  L007610aa: { // 0x7610aa: dc442438 FADD double ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.add64(read64(m,address));
  }
  L007610ae: { // 0x7610ae: dd5c2430 FSTP double ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L007610b2: { // 0x7610b2: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L007610b4: { // 0x7610b4: eb72 JMP 0x00761128
    goto L00761128;
  }
  L007610b6: { // 0x7610b6: a804 TEST AL,0x4
    (void)integer::logical(((s.ax & 0xffu))&(0x00000004u),8,flags);
  }
  L007610b8: { // 0x7610b8: 741f JZ 0x007610d9
    if(integer::condition("JZ",flags)) goto L007610d9;
  }
  L007610ba: { // 0x7610ba: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L007610be: { // 0x7610be: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L007610bf: { // 0x7610bf: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L007610c1: { // 0x7610c1: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L007610c5: { // 0x7610c5: db442418 FILD dword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load_integer32(m.r32(address));
  }
  L007610c9: { // 0x7610c9: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L007610cb: { // 0x7610cb: dc642428 FSUB double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.subtract64(read64(m,address));
  }
  L007610cf: { // 0x7610cf: dc4c2458 FMUL double ptr [ESP + 0x58]
    const auto address=(f.sp+0x00000058u);
    s.fp.multiply64(read64(m,address));
  }
  L007610d3: { // 0x7610d3: dc442438 FADD double ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.add64(read64(m,address));
  }
  L007610d7: { // 0x7610d7: eb4b JMP 0x00761124
    goto L00761124;
  }
  L007610d9: { // 0x7610d9: a802 TEST AL,0x2
    (void)integer::logical(((s.ax & 0xffu))&(0x00000002u),8,flags);
  }
  L007610db: { // 0x7610db: 7431 JZ 0x0076110e
    if(integer::condition("JZ",flags)) goto L0076110e;
  }
  L007610dd: { // 0x7610dd: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L007610e1: { // 0x7610e1: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L007610e2: { // 0x7610e2: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L007610e4: { // 0x7610e4: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L007610e8: { // 0x7610e8: db442418 FILD dword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load_integer32(m.r32(address));
  }
  L007610ec: { // 0x7610ec: dd542418 FST double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L007610f0: { // 0x7610f0: dc642438 FSUB double ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.subtract64(read64(m,address));
  }
  L007610f4: { // 0x7610f4: 8b742418 MOV ESI,dword ptr [ESP + 0x18]
    s.si = m.r32((f.sp+0x00000018u));
  }
  L007610f8: { // 0x7610f8: 8b5c241c MOV EBX,dword ptr [ESP + 0x1c]
    s.bx = m.r32((f.sp+0x0000001cu));
  }
  L007610fc: { // 0x7610fc: 89742430 MOV dword ptr [ESP + 0x30],ESI
    m.w32((f.sp+0x00000030u), s.si);
  }
  L00761100: { // 0x761100: 895c2434 MOV dword ptr [ESP + 0x34],EBX
    m.w32((f.sp+0x00000034u), s.bx);
  }
  L00761104: { // 0x761104: dc4c2460 FMUL double ptr [ESP + 0x60]
    const auto address=(f.sp+0x00000060u);
    s.fp.multiply64(read64(m,address));
  }
  L00761108: { // 0x761108: dc442428 FADD double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.add64(read64(m,address));
  }
  L0076110c: { // 0x76110c: eb1a JMP 0x00761128
    goto L00761128;
  }
  L0076110e: { // 0x76110e: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L00761110: { // 0x761110: 7416 JZ 0x00761128
    if(integer::condition("JZ",flags)) goto L00761128;
  }
  L00761112: { // 0x761112: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00761114: { // 0x761114: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L00761116: { // 0x761116: dc642438 FSUB double ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.subtract64(read64(m,address));
  }
  L0076111a: { // 0x76111a: dc4c2460 FMUL double ptr [ESP + 0x60]
    const auto address=(f.sp+0x00000060u);
    s.fp.multiply64(read64(m,address));
  }
  L0076111e: { // 0x76111e: dc442428 FADD double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.add64(read64(m,address));
  }
  L00761122: { // 0x761122: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L00761124: { // 0x761124: dd5c2430 FSTP double ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00761128: { // 0x761128: dd442430 FLD double ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.load64(read64(m,address));
  }
  L0076112c: { // 0x76112c: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0076112e: { // 0x76112e: 7556 JNZ 0x00761186
    if(integer::condition("JNZ",flags)) goto L00761186;
  }
  L00761130: { // 0x761130: dd542438 FST double ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L00761134: { // 0x761134: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L00761136: { // 0x761136: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00761138: { // 0x761138: dd5c2428 FSTP double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0076113c: { // 0x76113c: dc542448 FCOM double ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L00761140: { // 0x761140: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00761142: { // 0x761142: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761145: { // 0x761145: 7509 JNZ 0x00761150
    if(integer::condition("JNZ",flags)) goto L00761150;
  }
  L00761147: { // 0x761147: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00761149: { // 0x761149: ba02000000 MOV EDX,0x2
    s.dx = 0x00000002u;
  }
  L0076114e: { // 0x76114e: eb0e JMP 0x0076115e
    goto L0076115e;
  }
  L00761150: { // 0x761150: d8db FCOMP ST3
    numeric_b88::detail::reg<0xd8db>(s.fp);
  }
  L00761152: { // 0x761152: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00761154: { // 0x761154: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761157: { // 0x761157: 7405 JZ 0x0076115e
    if(integer::condition("JZ",flags)) goto L0076115e;
  }
  L00761159: { // 0x761159: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L0076115e: { // 0x76115e: dc542450 FCOM double ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L00761162: { // 0x761162: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00761164: { // 0x761164: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761167: { // 0x761167: 7508 JNZ 0x00761171
    if(integer::condition("JNZ",flags)) goto L00761171;
  }
  L00761169: { // 0x761169: 83ca04 OR EDX,0x4
    s.dx = integer::logical((s.dx)|(0x00000004u),32,flags);
  }
  L0076116c: { // 0x76116c: e90dffffff JMP 0x0076107e
    goto L0076107e;
  }
  L00761171: { // 0x761171: d8d1 FCOM
    numeric_b88::detail::reg<0xd8d1>(s.fp);
  }
  L00761173: { // 0x761173: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00761175: { // 0x761175: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761178: { // 0x761178: 0f8400ffffff JZ 0x0076107e
    if(integer::condition("JZ",flags)) goto L0076107e;
  }
  L0076117e: { // 0x76117e: 83ca08 OR EDX,0x8
    s.dx = integer::logical((s.dx)|(0x00000008u),32,flags);
  }
  L00761181: { // 0x761181: e9f8feffff JMP 0x0076107e
    goto L0076107e;
  }
  L00761186: { // 0x761186: dd542468 FST double ptr [ESP + 0x68]
    const auto address=(f.sp+0x00000068u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L0076118a: { // 0x76118a: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L0076118c: { // 0x76118c: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0076118e: { // 0x76118e: dd5c2440 FSTP double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00761192: { // 0x761192: dc542448 FCOM double ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L00761196: { // 0x761196: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00761198: { // 0x761198: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0076119b: { // 0x76119b: 7509 JNZ 0x007611a6
    if(integer::condition("JNZ",flags)) goto L007611a6;
  }
  L0076119d: { // 0x76119d: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0076119f: { // 0x76119f: b902000000 MOV ECX,0x2
    s.cx = 0x00000002u;
  }
  L007611a4: { // 0x7611a4: eb0e JMP 0x007611b4
    goto L007611b4;
  }
  L007611a6: { // 0x7611a6: d8db FCOMP ST3
    numeric_b88::detail::reg<0xd8db>(s.fp);
  }
  L007611a8: { // 0x7611a8: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L007611aa: { // 0x7611aa: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L007611ad: { // 0x7611ad: 7405 JZ 0x007611b4
    if(integer::condition("JZ",flags)) goto L007611b4;
  }
  L007611af: { // 0x7611af: b901000000 MOV ECX,0x1
    s.cx = 0x00000001u;
  }
  L007611b4: { // 0x7611b4: dc542450 FCOM double ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L007611b8: { // 0x7611b8: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L007611ba: { // 0x7611ba: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L007611bd: { // 0x7611bd: 7508 JNZ 0x007611c7
    if(integer::condition("JNZ",flags)) goto L007611c7;
  }
  L007611bf: { // 0x7611bf: 83c904 OR ECX,0x4
    s.cx = integer::logical((s.cx)|(0x00000004u),32,flags);
  }
  L007611c2: { // 0x7611c2: e9b7feffff JMP 0x0076107e
    goto L0076107e;
  }
  L007611c7: { // 0x7611c7: d8d1 FCOM
    numeric_b88::detail::reg<0xd8d1>(s.fp);
  }
  L007611c9: { // 0x7611c9: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L007611cb: { // 0x7611cb: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L007611ce: { // 0x7611ce: 0f84aafeffff JZ 0x0076107e
    if(integer::condition("JZ",flags)) goto L0076107e;
  }
  L007611d4: { // 0x7611d4: e9a2feffff JMP 0x0076107b
    goto L0076107b;
  }
  L007611d9: { // 0x7611d9: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L007611db: { // 0x7611db: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L007611dd: { // 0x7611dd: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L007611df: { // 0x7611df: dd442438 FLD double ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.load64(read64(m,address));
  }
  L007611e3: { // 0x7611e3: e868980000 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7737832u,op); flags=s.arithmetic_flags;
  }
  L007611e8: { // 0x7611e8: 8b742424 MOV ESI,dword ptr [ESP + 0x24]
    s.si = m.r32((f.sp+0x00000024u));
  }
  L007611ec: { // 0x7611ec: dd442428 FLD double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.load64(read64(m,address));
  }
  L007611f0: { // 0x7611f0: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  L007611f2: { // 0x7611f2: e859980000 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7737847u,op); flags=s.arithmetic_flags;
  }
  L007611f7: { // 0x7611f7: dd442468 FLD double ptr [ESP + 0x68]
    const auto address=(f.sp+0x00000068u);
    s.fp.load64(read64(m,address));
  }
  L007611fb: { // 0x7611fb: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  L007611fe: { // 0x7611fe: e84d980000 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7737859u,op); flags=s.arithmetic_flags;
  }
  L00761203: { // 0x761203: dd442440 FLD double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.load64(read64(m,address));
  }
  L00761207: { // 0x761207: 8907 MOV dword ptr [EDI],EAX
    m.w32((s.di), s.ax);
  }
  L00761209: { // 0x761209: e842980000 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7737870u,op); flags=s.arithmetic_flags;
  }
  L0076120e: { // 0x76120e: 894704 MOV dword ptr [EDI + 0x4],EAX
    m.w32((s.di+0x00000004u), s.ax);
  }
  L00761211: { // 0x761211: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00761213: { // 0x761213: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00761214: { // 0x761214: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00761215: { // 0x761215: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00761216: { // 0x761216: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L00761218: { // 0x761218: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00761219: { // 0x761219: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0076121c: { // 0x76121c: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0076121e: { // 0x76121e: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00761220: { // 0x761220: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00761221: { // 0x761221: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00761222: { // 0x761222: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00761224: { // 0x761224: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00761226: { // 0x761226: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00761227: { // 0x761227: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L00761229: { // 0x761229: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0076122a: { // 0x76122a: c20400 RET 0x4
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

inline void invoke(Memory&m,State&s,Frame&f,unsigned target,unsigned continuation,const Operations&op){
 need(op.api!=nullptr,"explicit provider context");auto&api=*op.api;
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};const auto arg=[&](unsigned k){return m.r32(child.sp+4+4*k);};
 switch(target){
 case 0x4adb10:f_000adb10(m,s,child,op);break;
 case 0x411230:f_00011230(m,s,child,op);break;
 case 0x761c80:f_00361c80(m,s,child,op);break;
 case 0x4ae5e0:f_000ae5e0(m,s,child,op);break;
 case 0x411290:f_00011290(m,s,child,op);break;
 case 0x4112c0:f_000112c0(m,s,child,op);break;
 case 0x4112f0:f_000112f0(m,s,child,op);break;
 case 0x411370:case 0x4113b0:{
  const auto z=m.r32(0x821fac),a=m.r32(0x8198f4);need(z&&a&&(s.cx==m.r32(z+20)||s.cx==m.r32(a+20))&&m.r32(s.cx)==0x785ef8,"constructor-bound software wrapper/header");
  if(target==0x411370)f_00011370(m,s,child,op);else f_000113b0(m,s,child,op);break;
 }
 case 0x4113c0:f_000113c0(m,s,child,op);break;
 case 0x41fdf0:f_0001fdf0(m,s,child,op);break;
 case 0x760f60:f_00360f60(m,s,child,op);break;
 case 0x76aa50:f_0036aa50(m,s,child,op);break;
 case 0x4aa970:s.ax=m.r32(s.cx+0x10);finish(m,s,child,0);break;
 case 0x4aa980:s.ax=m.r32(m.r32(s.cx+0x20)+0x10);finish(m,s,child,0);break;
 case 0x4aa990:case 0x4aab50:{
  const unsigned self=s.cx,surface=m.r32(self+28),count=m.r32(self+12);need(m.r8(0x839fe0)==1&&m.r32(self)==0x78bbe4&&m.r32(self+20)!=0&&surface==api.surface(),"genuine borrowed prelocked surface");
  const unsigned lost=api.is_lost(surface,s.fp);need(lost==0,"actual nonlost provider");
  if(target==0x4aa990){need(count==1&&arg(0)<16&&arg(1)<12,"positive nested1-to2 Lock");const unsigned offset=m.r32(m.r32(self+32)+16)*arg(1)+m.r32(self+16)*arg(0);m.w32(self+12,2);s.cx=self;s.dx=m.r32(self);s.ax=integer::add(m.r32(self+20),offset,32,s.arithmetic_flags);finish(m,s,child,8);}
  else{need(count==2,"nested2-to1 Unlock");m.w32(self+12,1);s.ax=1;s.arithmetic_flags=integer::logical(s.ax,32,s.arithmetic_flags);finish(m,s,child,0);}break;
 }
 default:throw std::domain_error("ADB10 out-of-recipe call (no sqrt/clip/foreign provider allowed)");
 }
 f.sp=child.sp;
}
}
unsigned run(Memory&world,const Inputs&in,Api&api){
 need(world.r32(in.cx)==0x78bbe4&&world.r32(in.cx+4)==16&&world.r32(in.cx+8)==12&&world.r32(in.cx+12)==1&&world.r32(in.cx+20)!=0&&world.r8(0x7c13c4)==1,"authentic main16x12/prelockedC1 recipe");
 need(world.r32(0x821fac)!=0&&world.r32(0x8198f4)!=0&&in.arg[4]==0x3f800000&&in.arg[5]==0&&in.arg[6]==0,"normal software buffers/finite color factor/depth recipe");
 need(world.r32(in.arg[0])==0&&world.r32(in.arg[0]+4)==0&&world.r32(in.arg[0]+8)==16&&world.r32(in.arg[0]+12)==12&&world.r32(in.arg[1])==2&&world.r32(in.arg[1]+4)==2&&world.r32(in.arg[2])==10&&world.r32(in.arg[2]+4)==2,"exact whole-visible horizontal geometry; no sqrt/clip continuation");
 std::array<std::uint8_t,0x8000>storage{};constexpr unsigned base=0x7d000000,entry=base+0x6004;ra2::recovered::leaf::Memory local(storage.data(),base,unsigned(storage.size()));Memory m=world;m.add(local);
 State s{};s.ax=in.ax;s.cx=in.cx;s.dx=in.dx;s.bx=0x13572468;s.bp=0x24681357;s.si=0x31415926;s.di=0x27182818;s.fp=in.fp;s.arithmetic_flags=in.arithmetic_flags;const auto before=s;
 Frame frame{entry,entry,0x76543210};m.w32(entry,frame.outer_return);for(unsigned k=0;k<16;++k)m.w32(entry+4+4*k,in.arg[k]);const Operations op{&api};f_000adb10(m,s,frame,op);
 need(frame.sp==entry+32&&s.bx==before.bx&&s.bp==before.bp&&s.si==before.si&&s.di==before.di,"full RET1C/nonvolatile recipe");in.fp=s.fp;for(unsigned k=0;k<16;++k)in.arg[k]=m.r32(entry+4+4*k);return s.ax;
}
}
