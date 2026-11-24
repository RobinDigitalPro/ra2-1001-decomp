#include "recovered/recovery_b1662.hpp"
#include <algorithm>
#include <array>
#include <cstdint>
#include <stdexcept>
#include <utility>
namespace ra2::recovered::b1662 {
namespace {
namespace leaf=ra2::recovered::leaf;
using namespace ra2::recovered::floating_b61;
using recovery_b566::finish; using recovery_b566::string_instruction; using recovery_b566::Kind; using recovery_b566::Repeat; using recovery_b566::reverse_divide32; using recovery_b566::reverse_divide64;
namespace integer=ra2::recovered::direct_b33::integer;
namespace numeric_b88=ra2::recovered::numeric_b88;
namespace fp=ra2::platform::x87;
using State=recovery_b566::State; using Frame=recovery_b566::Frame;
void invoke(Memory&,State&,Frame&,unsigned,unsigned,const Operations&);
void f_00317f20(Memory&,State&,Frame&,const Operations&);
void f_0018ac10(Memory&,State&,Frame&,const Operations&);

void f_00317f20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00717f20: { // 0x717f20: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00717f21: { // 0x717f21: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L00717f23: { // 0x717f23: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L00717f26: { // 0x717f26: 83ec68 SUB ESP,0x68
    f.sp = integer::sub(f.sp,0x00000068u,32,flags);
  }
  L00717f29: { // 0x717f29: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00717f2a: { // 0x717f2a: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00717f2b: { // 0x717f2b: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00717f2c: { // 0x717f2c: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00717f2e: { // 0x717f2e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00717f2f: { // 0x717f2f: 8b86b8010000 MOV EAX,dword ptr [ESI + 0x1b8]
    s.ax = m.r32((s.si+0x000001b8u));
  }
  L00717f35: { // 0x717f35: 8daeb8010000 LEA EBP,[ESI + 0x1b8]
    s.bp = (s.si+0x000001b8u);
  }
  L00717f3b: { // 0x717f3b: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00717f3d: { // 0x717f3d: ff500c CALL dword ptr [EAX + 0xc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000000cu)),7438144u,op); flags=s.arithmetic_flags;
  }
  L00717f40: { // 0x717f40: 8a8618010000 MOV AL,byte ptr [ESI + 0x118]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000118u)));
  }
  L00717f46: { // 0x717f46: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00717f48: { // 0x717f48: 0f848b010000 JZ 0x007180d9
    if(integer::condition("JZ",flags)) goto L007180d9;
  }
  L00717f4e: { // 0x717f4e: 8b86a0000000 MOV EAX,dword ptr [ESI + 0xa0]
    s.ax = m.r32((s.si+0x000000a0u));
  }
  L00717f54: { // 0x717f54: d905189b7900 FLD float ptr [0x00799b18]
    const auto address=(0x00799b18u);
    s.fp.load32(m.r32(address));
  }
  L00717f5a: { // 0x717f5a: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00717f5b: { // 0x717f5b: dd5c2440 FSTP double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00717f5f: { // 0x717f5f: d905189b7900 FLD float ptr [0x00799b18]
    const auto address=(0x00799b18u);
    s.fp.load32(m.r32(address));
  }
  L00717f65: { // 0x717f65: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00717f6b: { // 0x717f6b: dc0d28577800 FMUL double ptr [0x00785728]
    const auto address=(0x00785728u);
    s.fp.multiply64(read64(m,address));
  }
  L00717f71: { // 0x717f71: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00717f73: { // 0x717f73: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00717f76: { // 0x717f76: 6689442418 MOV word ptr [ESP + 0x18],AX
    m.w16((f.sp+0x00000018u), (s.ax & 0xffffu));
  }
  L00717f7b: { // 0x717f7b: 8b86a4000000 MOV EAX,dword ptr [ESI + 0xa4]
    s.ax = m.r32((s.si+0x000000a4u));
  }
  L00717f81: { // 0x717f81: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00717f82: { // 0x717f82: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00717f88: { // 0x717f88: dc8620010000 FADD double ptr [ESI + 0x120]
    const auto address=(s.si+0x00000120u);
    s.fp.add64(read64(m,address));
  }
  L00717f8e: { // 0x717f8e: dc5c2440 FCOMP double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00717f92: { // 0x717f92: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00717f94: { // 0x717f94: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00717f97: { // 0x717f97: 668944241a MOV word ptr [ESP + 0x1a],AX
    m.w16((f.sp+0x0000001au), (s.ax & 0xffffu));
  }
  L00717f9c: { // 0x717f9c: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L00717fa0: { // 0x717fa0: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00717fa2: { // 0x717fa2: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L00717fa6: { // 0x717fa6: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00717fa9: { // 0x717fa9: 0f85b8040000 JNZ 0x00718467
    if(integer::condition("JNZ",flags)) goto L00718467;
  }
  L00717faf: { // 0x717faf: dd442440 FLD double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.load64(read64(m,address));
  }
  L00717fb3: { // 0x717fb3: d9c0 FLD st0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L00717fb5: { // 0x717fb5: dc2d08577800 FSUBR double ptr [0x00785708]
    const auto address=(0x00785708u);
    s.fp.reverse_subtract64(read64(m,address));
  }
  L00717fbb: { // 0x717fbb: db86b4000000 FILD dword ptr [ESI + 0xb4]
    const auto address=(s.si+0x000000b4u);
    s.fp.load_integer32(m.r32(address));
  }
  L00717fc1: { // 0x717fc1: d8ca FMUL st2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L00717fc3: { // 0x717fc3: db86a8000000 FILD dword ptr [ESI + 0xa8]
    const auto address=(s.si+0x000000a8u);
    s.fp.load_integer32(m.r32(address));
  }
  L00717fc9: { // 0x717fc9: d8ca FMUL st2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L00717fcb: { // 0x717fcb: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L00717fcd: { // 0x717fcd: e87e2a0500 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7438290u,op); flags=s.arithmetic_flags;
  }
  L00717fd2: { // 0x717fd2: db86b0000000 FILD dword ptr [ESI + 0xb0]
    const auto address=(s.si+0x000000b0u);
    s.fp.load_integer32(m.r32(address));
  }
  L00717fd8: { // 0x717fd8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00717fd9: { // 0x717fd9: d8ca FMUL st2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L00717fdb: { // 0x717fdb: db86a4000000 FILD dword ptr [ESI + 0xa4]
    const auto address=(s.si+0x000000a4u);
    s.fp.load_integer32(m.r32(address));
  }
  L00717fe1: { // 0x717fe1: d8ca FMUL st2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L00717fe3: { // 0x717fe3: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L00717fe5: { // 0x717fe5: e8662a0500 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7438314u,op); flags=s.arithmetic_flags;
  }
  L00717fea: { // 0x717fea: db86ac000000 FILD dword ptr [ESI + 0xac]
    const auto address=(s.si+0x000000acu);
    s.fp.load_integer32(m.r32(address));
  }
  L00717ff0: { // 0x717ff0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00717ff1: { // 0x717ff1: d8ca FMUL st2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L00717ff3: { // 0x717ff3: db86a0000000 FILD dword ptr [ESI + 0xa0]
    const auto address=(s.si+0x000000a0u);
    s.fp.load_integer32(m.r32(address));
  }
  L00717ff9: { // 0x717ff9: d8ca FMUL st2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L00717ffb: { // 0x717ffb: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L00717ffd: { // 0x717ffd: e84e2a0500 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7438338u,op); flags=s.arithmetic_flags;
  }
  L00718002: { // 0x718002: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00718004: { // 0x718004: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00718005: { // 0x718005: 8d4c2454 LEA ECX,[ESP + 0x54]
    s.cx = (f.sp+0x00000054u);
  }
  L00718009: { // 0x718009: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0071800b: { // 0x71800b: e8d0c6d1ff CALL 0x004346e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004346e0u,7438352u,op); flags=s.arithmetic_flags;
  }
  L00718010: { // 0x718010: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00718012: { // 0x718012: 8b0a MOV ECX,dword ptr [EDX]
    s.cx = m.r32((s.dx));
  }
  L00718014: { // 0x718014: 8b4204 MOV EAX,dword ptr [EDX + 0x4]
    s.ax = m.r32((s.dx+0x00000004u));
  }
  L00718017: { // 0x718017: 8b5208 MOV EDX,dword ptr [EDX + 0x8]
    s.dx = m.r32((s.dx+0x00000008u));
  }
  L0071801a: { // 0x71801a: 8954245c MOV dword ptr [ESP + 0x5c],EDX
    m.w32((f.sp+0x0000005cu), s.dx);
  }
  L0071801e: { // 0x71801e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0071801f: { // 0x71801f: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00718025: { // 0x718025: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00718027: { // 0x718027: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00718029: { // 0x718029: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0071802b: { // 0x71802b: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0071802c: { // 0x71802c: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00718032: { // 0x718032: 8d4c2424 LEA ECX,[ESP + 0x24]
    s.cx = (f.sp+0x00000024u);
  }
  L00718036: { // 0x718036: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00718038: { // 0x718038: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0071803a: { // 0x71803a: c1ff08 SAR EDI,0x8
    s.di = integer::shift(s.di,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0071803d: { // 0x71803d: c1fb08 SAR EBX,0x8
    s.bx = integer::shift(s.bx,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00718040: { // 0x718040: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00718041: { // 0x718041: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00718042: { // 0x718042: e8e92cd1ff CALL 0x0042ad30
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042ad30u,7438407u,op); flags=s.arithmetic_flags;
  }
  L00718047: { // 0x718047: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L00718049: { // 0x718049: 6639442410 CMP word ptr [ESP + 0x10],AX
    (void)integer::sub(m.r16((f.sp+0x00000010u)),(s.ax & 0xffffu),16,flags);
  }
  L0071804e: { // 0x71804e: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L00718052: { // 0x718052: 750c JNZ 0x00718060
    if(integer::condition("JNZ",flags)) goto L00718060;
  }
  L00718054: { // 0x718054: 668b442412 MOV AX,word ptr [ESP + 0x12]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x00000012u)));
  }
  L00718059: { // 0x718059: 663b44241e CMP AX,word ptr [ESP + 0x1e]
    (void)integer::sub((s.ax & 0xffffu),m.r16((f.sp+0x0000001eu)),16,flags);
  }
  L0071805e: { // 0x71805e: 7442 JZ 0x007180a2
    if(integer::condition("JZ",flags)) goto L007180a2;
  }
  L00718060: { // 0x718060: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00718061: { // 0x718061: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00718062: { // 0x718062: 8d4c2428 LEA ECX,[ESP + 0x28]
    s.cx = (f.sp+0x00000028u);
  }
  L00718066: { // 0x718066: e8c52cd1ff CALL 0x0042ad30
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042ad30u,7438443u,op); flags=s.arithmetic_flags;
  }
  L0071806b: { // 0x71806b: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0071806d: { // 0x71806d: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L00718071: { // 0x718071: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00718072: { // 0x718072: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00718077: { // 0x718077: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L0071807b: { // 0x71807b: e880d4e2ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,7438464u,op); flags=s.arithmetic_flags;
  }
  L00718080: { // 0x718080: 8b5500 MOV EDX,dword ptr [EBP]
    s.dx = m.r32((s.bp));
  }
  L00718083: { // 0x718083: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00718087: { // 0x718087: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L0071808b: { // 0x71808b: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0071808d: { // 0x71808d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0071808e: { // 0x71808e: ff5210 CALL dword ptr [EDX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000010u)),7438481u,op); flags=s.arithmetic_flags;
  }
  L00718091: { // 0x718091: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00718094: { // 0x718094: 750c JNZ 0x007180a2
    if(integer::condition("JNZ",flags)) goto L007180a2;
  }
  L00718096: { // 0x718096: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0071809a: { // 0x71809a: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0071809b: { // 0x71809b: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0071809d: { // 0x71809d: e84e120000 CALL 0x007192f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x007192f0u,7438498u,op); flags=s.arithmetic_flags;
  }
  L007180a2: { // 0x7180a2: d905189b7900 FLD float ptr [0x00799b18]
    const auto address=(0x00799b18u);
    s.fp.load32(m.r32(address));
  }
  L007180a8: { // 0x7180a8: dc442440 FADD double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.add64(read64(m,address));
  }
  L007180ac: { // 0x7180ac: dd5c2440 FSTP double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L007180b0: { // 0x7180b0: d905189b7900 FLD float ptr [0x00799b18]
    const auto address=(0x00799b18u);
    s.fp.load32(m.r32(address));
  }
  L007180b6: { // 0x7180b6: dc0d28577800 FMUL double ptr [0x00785728]
    const auto address=(0x00785728u);
    s.fp.multiply64(read64(m,address));
  }
  L007180bc: { // 0x7180bc: dc8620010000 FADD double ptr [ESI + 0x120]
    const auto address=(s.si+0x00000120u);
    s.fp.add64(read64(m,address));
  }
  L007180c2: { // 0x7180c2: dc5c2440 FCOMP double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.compare_pop64(read64(m,address));
  }
  L007180c6: { // 0x7180c6: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L007180c8: { // 0x7180c8: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L007180cb: { // 0x7180cb: 0f84defeffff JZ 0x00717faf
    if(integer::condition("JZ",flags)) goto L00717faf;
  }
  L007180d1: { // 0x7180d1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L007180d2: { // 0x7180d2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L007180d3: { // 0x7180d3: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L007180d4: { // 0x7180d4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L007180d5: { // 0x7180d5: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L007180d7: { // 0x7180d7: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L007180d8: { // 0x7180d8: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L007180d9: { // 0x7180d9: 8b86ec000000 MOV EAX,dword ptr [ESI + 0xec]
    s.ax = m.r32((s.si+0x000000ecu));
  }
  L007180df: { // 0x7180df: 8d4c2424 LEA ECX,[ESP + 0x24]
    s.cx = (f.sp+0x00000024u);
  }
  L007180e3: { // 0x7180e3: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L007180e4: { // 0x7180e4: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L007180ea: { // 0x7180ea: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L007180ec: { // 0x7180ec: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L007180ef: { // 0x7180ef: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007180f0: { // 0x7180f0: 8b86e8000000 MOV EAX,dword ptr [ESI + 0xe8]
    s.ax = m.r32((s.si+0x000000e8u));
  }
  L007180f6: { // 0x7180f6: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L007180f7: { // 0x7180f7: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L007180fd: { // 0x7180fd: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L007180ff: { // 0x7180ff: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00718102: { // 0x718102: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00718103: { // 0x718103: e8282cd1ff CALL 0x0042ad30
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042ad30u,7438600u,op); flags=s.arithmetic_flags;
  }
  L00718108: { // 0x718108: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0071810a: { // 0x71810a: 8dbef4000000 LEA EDI,[ESI + 0xf4]
    s.di = (s.si+0x000000f4u);
  }
  L00718110: { // 0x718110: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00718114: { // 0x718114: 8d4c2424 LEA ECX,[ESP + 0x24]
    s.cx = (f.sp+0x00000024u);
  }
  L00718118: { // 0x718118: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  L0071811b: { // 0x71811b: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0071811c: { // 0x71811c: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00718122: { // 0x718122: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00718124: { // 0x718124: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00718127: { // 0x718127: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00718128: { // 0x718128: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L0071812a: { // 0x71812a: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0071812b: { // 0x71812b: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00718131: { // 0x718131: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00718133: { // 0x718133: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00718136: { // 0x718136: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00718137: { // 0x718137: e8f42bd1ff CALL 0x0042ad30
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042ad30u,7438652u,op); flags=s.arithmetic_flags;
  }
  L0071813c: { // 0x71813c: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0071813e: { // 0x71813e: 8d4c2424 LEA ECX,[ESP + 0x24]
    s.cx = (f.sp+0x00000024u);
  }
  L00718142: { // 0x718142: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00718146: { // 0x718146: 8b86b0000000 MOV EAX,dword ptr [ESI + 0xb0]
    s.ax = m.r32((s.si+0x000000b0u));
  }
  L0071814c: { // 0x71814c: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0071814d: { // 0x71814d: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00718153: { // 0x718153: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00718155: { // 0x718155: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00718158: { // 0x718158: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00718159: { // 0x718159: 8b86ac000000 MOV EAX,dword ptr [ESI + 0xac]
    s.ax = m.r32((s.si+0x000000acu));
  }
  L0071815f: { // 0x71815f: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00718160: { // 0x718160: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00718166: { // 0x718166: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00718168: { // 0x718168: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0071816b: { // 0x71816b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0071816c: { // 0x71816c: e8bf2bd1ff CALL 0x0042ad30
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042ad30u,7438705u,op); flags=s.arithmetic_flags;
  }
  L00718171: { // 0x718171: d905189b7900 FLD float ptr [0x00799b18]
    const auto address=(0x00799b18u);
    s.fp.load32(m.r32(address));
  }
  L00718177: { // 0x718177: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L00718179: { // 0x718179: 8b9628010000 MOV EDX,dword ptr [ESI + 0x128]
    s.dx = m.r32((s.si+0x00000128u));
  }
  L0071817f: { // 0x71817f: dc0d28577800 FMUL double ptr [0x00785728]
    const auto address=(0x00785728u);
    s.fp.multiply64(read64(m,address));
  }
  L00718185: { // 0x718185: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00718189: { // 0x718189: 8b862c010000 MOV EAX,dword ptr [ESI + 0x12c]
    s.ax = m.r32((s.si+0x0000012cu));
  }
  L0071818f: { // 0x71818f: 89542440 MOV dword ptr [ESP + 0x40],EDX
    m.w32((f.sp+0x00000040u), s.dx);
  }
  L00718193: { // 0x718193: 89442444 MOV dword ptr [ESP + 0x44],EAX
    m.w32((f.sp+0x00000044u), s.ax);
  }
  L00718197: { // 0x718197: dc8620010000 FADD double ptr [ESI + 0x120]
    const auto address=(s.si+0x00000120u);
    s.fp.add64(read64(m,address));
  }
  L0071819d: { // 0x71819d: dc5c2440 FCOMP double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.compare_pop64(read64(m,address));
  }
  L007181a1: { // 0x7181a1: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L007181a3: { // 0x7181a3: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L007181a6: { // 0x7181a6: 0f85bb020000 JNZ 0x00718467
    if(integer::condition("JNZ",flags)) goto L00718467;
  }
  L007181ac: { // 0x7181ac: bb04000000 MOV EBX,0x4
    s.bx = 0x00000004u;
  }
  L007181b1: { // 0x7181b1: a1580cae00 MOV EAX,[0x00ae0c58]
    s.ax = m.r32((0x00ae0c58u));
  }
  L007181b6: { // 0x7181b6: 8b0d500cae00 MOV ECX,dword ptr [0x00ae0c50]
    s.cx = m.r32((0x00ae0c50u));
  }
  L007181bc: { // 0x7181bc: 8b15540cae00 MOV EDX,dword ptr [0x00ae0c54]
    s.dx = m.r32((0x00ae0c54u));
  }
  L007181c2: { // 0x7181c2: 89442450 MOV dword ptr [ESP + 0x50],EAX
    m.w32((f.sp+0x00000050u), s.ax);
  }
  L007181c6: { // 0x7181c6: 8b8694010000 MOV EAX,dword ptr [ESI + 0x194]
    s.ax = m.r32((s.si+0x00000194u));
  }
  L007181cc: { // 0x7181cc: 894c2448 MOV dword ptr [ESP + 0x48],ECX
    m.w32((f.sp+0x00000048u), s.cx);
  }
  L007181d0: { // 0x7181d0: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L007181d2: { // 0x7181d2: 8954244c MOV dword ptr [ESP + 0x4c],EDX
    m.w32((f.sp+0x0000004cu), s.dx);
  }
  L007181d6: { // 0x7181d6: 0f8d17010000 JGE 0x007182f3
    if(integer::condition("JGE",flags)) goto L007182f3;
  }
  L007181dc: { // 0x7181dc: dd442440 FLD double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.load64(read64(m,address));
  }
  L007181e0: { // 0x7181e0: d9c0 FLD st0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L007181e2: { // 0x7181e2: dc2d08577800 FSUBR double ptr [0x00785708]
    const auto address=(0x00785708u);
    s.fp.reverse_subtract64(read64(m,address));
  }
  L007181e8: { // 0x7181e8: db86f0000000 FILD dword ptr [ESI + 0xf0]
    const auto address=(s.si+0x000000f0u);
    s.fp.load_integer32(m.r32(address));
  }
  L007181ee: { // 0x7181ee: d8ca FMUL st2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L007181f0: { // 0x7181f0: db8608010000 FILD dword ptr [ESI + 0x108]
    const auto address=(s.si+0x00000108u);
    s.fp.load_integer32(m.r32(address));
  }
  L007181f6: { // 0x7181f6: d8ca FMUL st2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L007181f8: { // 0x7181f8: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L007181fa: { // 0x7181fa: e851280500 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7438847u,op); flags=s.arithmetic_flags;
  }
  L007181ff: { // 0x7181ff: db86ec000000 FILD dword ptr [ESI + 0xec]
    const auto address=(s.si+0x000000ecu);
    s.fp.load_integer32(m.r32(address));
  }
  L00718205: { // 0x718205: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00718206: { // 0x718206: d8ca FMUL st2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L00718208: { // 0x718208: db8604010000 FILD dword ptr [ESI + 0x104]
    const auto address=(s.si+0x00000104u);
    s.fp.load_integer32(m.r32(address));
  }
  L0071820e: { // 0x71820e: d8ca FMUL st2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L00718210: { // 0x718210: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L00718212: { // 0x718212: e839280500 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7438871u,op); flags=s.arithmetic_flags;
  }
  L00718217: { // 0x718217: db86e8000000 FILD dword ptr [ESI + 0xe8]
    const auto address=(s.si+0x000000e8u);
    s.fp.load_integer32(m.r32(address));
  }
  L0071821d: { // 0x71821d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0071821e: { // 0x71821e: d8ca FMUL st2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L00718220: { // 0x718220: db8600010000 FILD dword ptr [ESI + 0x100]
    const auto address=(s.si+0x00000100u);
    s.fp.load_integer32(m.r32(address));
  }
  L00718226: { // 0x718226: d8ca FMUL st2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L00718228: { // 0x718228: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0071822a: { // 0x71822a: e821280500 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7438895u,op); flags=s.arithmetic_flags;
  }
  L0071822f: { // 0x71822f: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00718231: { // 0x718231: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00718232: { // 0x718232: 8d4c2460 LEA ECX,[ESP + 0x60]
    s.cx = (f.sp+0x00000060u);
  }
  L00718236: { // 0x718236: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00718238: { // 0x718238: e8a3c4d1ff CALL 0x004346e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004346e0u,7438909u,op); flags=s.arithmetic_flags;
  }
  L0071823d: { // 0x71823d: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0071823f: { // 0x71823f: 8b0a MOV ECX,dword ptr [EDX]
    s.cx = m.r32((s.dx));
  }
  L00718241: { // 0x718241: 894c2448 MOV dword ptr [ESP + 0x48],ECX
    m.w32((f.sp+0x00000048u), s.cx);
  }
  L00718245: { // 0x718245: 8b4204 MOV EAX,dword ptr [EDX + 0x4]
    s.ax = m.r32((s.dx+0x00000004u));
  }
  L00718248: { // 0x718248: 8944244c MOV dword ptr [ESP + 0x4c],EAX
    m.w32((f.sp+0x0000004cu), s.ax);
  }
  L0071824c: { // 0x71824c: 8b5208 MOV EDX,dword ptr [EDX + 0x8]
    s.dx = m.r32((s.dx+0x00000008u));
  }
  L0071824f: { // 0x71824f: 89542450 MOV dword ptr [ESP + 0x50],EDX
    m.w32((f.sp+0x00000050u), s.dx);
  }
  L00718253: { // 0x718253: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00718254: { // 0x718254: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0071825a: { // 0x71825a: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0071825c: { // 0x71825c: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0071825f: { // 0x71825f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00718260: { // 0x718260: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00718262: { // 0x718262: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00718263: { // 0x718263: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00718269: { // 0x718269: 8d4c242c LEA ECX,[ESP + 0x2c]
    s.cx = (f.sp+0x0000002cu);
  }
  L0071826d: { // 0x71826d: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0071826f: { // 0x71826f: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00718272: { // 0x718272: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00718273: { // 0x718273: e8b82ad1ff CALL 0x0042ad30
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042ad30u,7438968u,op); flags=s.arithmetic_flags;
  }
  L00718278: { // 0x718278: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0071827a: { // 0x71827a: 6639442410 CMP word ptr [ESP + 0x10],AX
    (void)integer::sub(m.r16((f.sp+0x00000010u)),(s.ax & 0xffffu),16,flags);
  }
  L0071827f: { // 0x71827f: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L00718283: { // 0x718283: 750c JNZ 0x00718291
    if(integer::condition("JNZ",flags)) goto L00718291;
  }
  L00718285: { // 0x718285: 668b442412 MOV AX,word ptr [ESP + 0x12]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x00000012u)));
  }
  L0071828a: { // 0x71828a: 663b442422 CMP AX,word ptr [ESP + 0x22]
    (void)integer::sub((s.ax & 0xffffu),m.r16((f.sp+0x00000022u)),16,flags);
  }
  L0071828f: { // 0x71828f: 7462 JZ 0x007182f3
    if(integer::condition("JZ",flags)) goto L007182f3;
  }
  L00718291: { // 0x718291: 8b44244c MOV EAX,dword ptr [ESP + 0x4c]
    s.ax = m.r32((f.sp+0x0000004cu));
  }
  L00718295: { // 0x718295: 8d4c242c LEA ECX,[ESP + 0x2c]
    s.cx = (f.sp+0x0000002cu);
  }
  L00718299: { // 0x718299: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0071829a: { // 0x71829a: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L007182a0: { // 0x7182a0: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L007182a2: { // 0x7182a2: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L007182a5: { // 0x7182a5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007182a6: { // 0x7182a6: 8b44244c MOV EAX,dword ptr [ESP + 0x4c]
    s.ax = m.r32((f.sp+0x0000004cu));
  }
  L007182aa: { // 0x7182aa: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L007182ab: { // 0x7182ab: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L007182b1: { // 0x7182b1: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L007182b3: { // 0x7182b3: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L007182b6: { // 0x7182b6: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007182b7: { // 0x7182b7: e8742ad1ff CALL 0x0042ad30
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042ad30u,7439036u,op); flags=s.arithmetic_flags;
  }
  L007182bc: { // 0x7182bc: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L007182be: { // 0x7182be: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L007182c2: { // 0x7182c2: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L007182c3: { // 0x7182c3: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L007182c8: { // 0x7182c8: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L007182cc: { // 0x7182cc: e82fd2e2ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,7439057u,op); flags=s.arithmetic_flags;
  }
  L007182d1: { // 0x7182d1: 8b5500 MOV EDX,dword ptr [EBP]
    s.dx = m.r32((s.bp));
  }
  L007182d4: { // 0x7182d4: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L007182d8: { // 0x7182d8: 8d44241c LEA EAX,[ESP + 0x1c]
    s.ax = (f.sp+0x0000001cu);
  }
  L007182dc: { // 0x7182dc: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L007182de: { // 0x7182de: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007182df: { // 0x7182df: ff5210 CALL dword ptr [EDX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000010u)),7439074u,op); flags=s.arithmetic_flags;
  }
  L007182e2: { // 0x7182e2: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L007182e5: { // 0x7182e5: 750c JNZ 0x007182f3
    if(integer::condition("JNZ",flags)) goto L007182f3;
  }
  L007182e7: { // 0x7182e7: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L007182eb: { // 0x7182eb: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L007182ec: { // 0x7182ec: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L007182ee: { // 0x7182ee: e8fd0f0000 CALL 0x007192f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x007192f0u,7439091u,op); flags=s.arithmetic_flags;
  }
  L007182f3: { // 0x7182f3: dd442440 FLD double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.load64(read64(m,address));
  }
  L007182f7: { // 0x7182f7: d9542420 FST float ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    const auto value=s.fp.store32();
    m.w32(address,value);
  }
  L007182fb: { // 0x7182fb: d9c0 FLD st0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L007182fd: { // 0x7182fd: dc2d08577800 FSUBR double ptr [0x00785708]
    const auto address=(0x00785708u);
    s.fp.reverse_subtract64(read64(m,address));
  }
  L00718303: { // 0x718303: db86b4000000 FILD dword ptr [ESI + 0xb4]
    const auto address=(s.si+0x000000b4u);
    s.fp.load_integer32(m.r32(address));
  }
  L00718309: { // 0x718309: d8ca FMUL st2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L0071830b: { // 0x71830b: db86a8000000 FILD dword ptr [ESI + 0xa8]
    const auto address=(s.si+0x000000a8u);
    s.fp.load_integer32(m.r32(address));
  }
  L00718311: { // 0x718311: d8ca FMUL st2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L00718313: { // 0x718313: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L00718315: { // 0x718315: e836270500 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7439130u,op); flags=s.arithmetic_flags;
  }
  L0071831a: { // 0x71831a: db86b0000000 FILD dword ptr [ESI + 0xb0]
    const auto address=(s.si+0x000000b0u);
    s.fp.load_integer32(m.r32(address));
  }
  L00718320: { // 0x718320: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00718321: { // 0x718321: d8ca FMUL st2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L00718323: { // 0x718323: db86a4000000 FILD dword ptr [ESI + 0xa4]
    const auto address=(s.si+0x000000a4u);
    s.fp.load_integer32(m.r32(address));
  }
  L00718329: { // 0x718329: d8ca FMUL st2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L0071832b: { // 0x71832b: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0071832d: { // 0x71832d: e81e270500 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7439154u,op); flags=s.arithmetic_flags;
  }
  L00718332: { // 0x718332: db86ac000000 FILD dword ptr [ESI + 0xac]
    const auto address=(s.si+0x000000acu);
    s.fp.load_integer32(m.r32(address));
  }
  L00718338: { // 0x718338: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00718339: { // 0x718339: d8ca FMUL st2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L0071833b: { // 0x71833b: db86a0000000 FILD dword ptr [ESI + 0xa0]
    const auto address=(s.si+0x000000a0u);
    s.fp.load_integer32(m.r32(address));
  }
  L00718341: { // 0x718341: d8ca FMUL st2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L00718343: { // 0x718343: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L00718345: { // 0x718345: e806270500 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7439178u,op); flags=s.arithmetic_flags;
  }
  L0071834a: { // 0x71834a: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0071834c: { // 0x71834c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0071834d: { // 0x71834d: 8d4c246c LEA ECX,[ESP + 0x6c]
    s.cx = (f.sp+0x0000006cu);
  }
  L00718351: { // 0x718351: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00718353: { // 0x718353: e888c3d1ff CALL 0x004346e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004346e0u,7439192u,op); flags=s.arithmetic_flags;
  }
  L00718358: { // 0x718358: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0071835a: { // 0x71835a: 8b0a MOV ECX,dword ptr [EDX]
    s.cx = m.r32((s.dx));
  }
  L0071835c: { // 0x71835c: 894c2448 MOV dword ptr [ESP + 0x48],ECX
    m.w32((f.sp+0x00000048u), s.cx);
  }
  L00718360: { // 0x718360: 8b4204 MOV EAX,dword ptr [EDX + 0x4]
    s.ax = m.r32((s.dx+0x00000004u));
  }
  L00718363: { // 0x718363: 8944244c MOV dword ptr [ESP + 0x4c],EAX
    m.w32((f.sp+0x0000004cu), s.ax);
  }
  L00718367: { // 0x718367: 8b5208 MOV EDX,dword ptr [EDX + 0x8]
    s.dx = m.r32((s.dx+0x00000008u));
  }
  L0071836a: { // 0x71836a: 89542450 MOV dword ptr [ESP + 0x50],EDX
    m.w32((f.sp+0x00000050u), s.dx);
  }
  L0071836e: { // 0x71836e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0071836f: { // 0x71836f: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00718375: { // 0x718375: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00718377: { // 0x718377: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0071837a: { // 0x71837a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0071837b: { // 0x71837b: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0071837d: { // 0x71837d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0071837e: { // 0x71837e: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00718384: { // 0x718384: 8d4c2434 LEA ECX,[ESP + 0x34]
    s.cx = (f.sp+0x00000034u);
  }
  L00718388: { // 0x718388: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0071838a: { // 0x71838a: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0071838d: { // 0x71838d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0071838e: { // 0x71838e: e89d29d1ff CALL 0x0042ad30
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042ad30u,7439251u,op); flags=s.arithmetic_flags;
  }
  L00718393: { // 0x718393: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L00718395: { // 0x718395: 8d4c2424 LEA ECX,[ESP + 0x24]
    s.cx = (f.sp+0x00000024u);
  }
  L00718399: { // 0x718399: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0071839a: { // 0x71839a: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0071839e: { // 0x71839e: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L007183a2: { // 0x7183a2: e8a925e7ff CALL 0x0058a950
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058a950u,7439271u,op); flags=s.arithmetic_flags;
  }
  L007183a7: { // 0x7183a7: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L007183a9: { // 0x7183a9: 7420 JZ 0x007183cb
    if(integer::condition("JZ",flags)) goto L007183cb;
  }
  L007183ab: { // 0x7183ab: 8d542434 LEA EDX,[ESP + 0x34]
    s.dx = (f.sp+0x00000034u);
  }
  L007183af: { // 0x7183af: 8d4c2448 LEA ECX,[ESP + 0x48]
    s.cx = (f.sp+0x00000048u);
  }
  L007183b3: { // 0x7183b3: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L007183b4: { // 0x7183b4: e8b7b3cfff CALL 0x00413770
    s.arithmetic_flags=flags; invoke(m,s,f,0x00413770u,7439289u,op); flags=s.arithmetic_flags;
  }
  L007183b9: { // 0x7183b9: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L007183bb: { // 0x7183bb: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L007183bf: { // 0x7183bf: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L007183c0: { // 0x7183c0: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L007183c2: { // 0x7183c2: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L007183c6: { // 0x7183c6: e835e8ffff CALL 0x00716c00
    s.arithmetic_flags=flags; invoke(m,s,f,0x00716c00u,7439307u,op); flags=s.arithmetic_flags;
  }
  L007183cb: { // 0x7183cb: 399e94010000 CMP dword ptr [ESI + 0x194],EBX
    (void)integer::sub(m.r32((s.si+0x00000194u)),s.bx,32,flags);
  }
  L007183d1: { // 0x7183d1: 7c65 JL 0x00718438
    if(integer::condition("JL",flags)) goto L00718438;
  }
  L007183d3: { // 0x7183d3: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L007183d7: { // 0x7183d7: 8d4c246c LEA ECX,[ESP + 0x6c]
    s.cx = (f.sp+0x0000006cu);
  }
  L007183db: { // 0x7183db: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L007183dc: { // 0x7183dc: 57 PUSH EDI
    f.push(m,s.di);
  }
  L007183dd: { // 0x7183dd: 8d960c010000 LEA EDX,[ESI + 0x10c]
    s.dx = (s.si+0x0000010cu);
  }
  L007183e3: { // 0x7183e3: e898e8ffff CALL 0x00716c80
    s.arithmetic_flags=flags; invoke(m,s,f,0x00716c80u,7439336u,op); flags=s.arithmetic_flags;
  }
  L007183e8: { // 0x7183e8: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L007183ea: { // 0x7183ea: 894c2448 MOV dword ptr [ESP + 0x48],ECX
    m.w32((f.sp+0x00000048u), s.cx);
  }
  L007183ee: { // 0x7183ee: 8d4c2438 LEA ECX,[ESP + 0x38]
    s.cx = (f.sp+0x00000038u);
  }
  L007183f2: { // 0x7183f2: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L007183f5: { // 0x7183f5: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L007183f6: { // 0x7183f6: 89542450 MOV dword ptr [ESP + 0x50],EDX
    m.w32((f.sp+0x00000050u), s.dx);
  }
  L007183fa: { // 0x7183fa: 8d4c244c LEA ECX,[ESP + 0x4c]
    s.cx = (f.sp+0x0000004cu);
  }
  L007183fe: { // 0x7183fe: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L00718401: { // 0x718401: 89442454 MOV dword ptr [ESP + 0x54],EAX
    m.w32((f.sp+0x00000054u), s.ax);
  }
  L00718405: { // 0x718405: e866b3cfff CALL 0x00413770
    s.arithmetic_flags=flags; invoke(m,s,f,0x00413770u,7439370u,op); flags=s.arithmetic_flags;
  }
  L0071840a: { // 0x71840a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0071840b: { // 0x71840b: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L0071840f: { // 0x71840f: e83c25e7ff CALL 0x0058a950
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058a950u,7439380u,op); flags=s.arithmetic_flags;
  }
  L00718414: { // 0x718414: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00718416: { // 0x718416: 7420 JZ 0x00718438
    if(integer::condition("JZ",flags)) goto L00718438;
  }
  L00718418: { // 0x718418: 8d54243c LEA EDX,[ESP + 0x3c]
    s.dx = (f.sp+0x0000003cu);
  }
  L0071841c: { // 0x71841c: 8d4c2448 LEA ECX,[ESP + 0x48]
    s.cx = (f.sp+0x00000048u);
  }
  L00718420: { // 0x718420: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00718421: { // 0x718421: e84ab3cfff CALL 0x00413770
    s.arithmetic_flags=flags; invoke(m,s,f,0x00413770u,7439398u,op); flags=s.arithmetic_flags;
  }
  L00718426: { // 0x718426: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L00718428: { // 0x718428: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0071842c: { // 0x71842c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0071842d: { // 0x71842d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0071842f: { // 0x71842f: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L00718433: { // 0x718433: e8c8e7ffff CALL 0x00716c00
    s.arithmetic_flags=flags; invoke(m,s,f,0x00716c00u,7439416u,op); flags=s.arithmetic_flags;
  }
  L00718438: { // 0x718438: d905189b7900 FLD float ptr [0x00799b18]
    const auto address=(0x00799b18u);
    s.fp.load32(m.r32(address));
  }
  L0071843e: { // 0x71843e: dc442440 FADD double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.add64(read64(m,address));
  }
  L00718442: { // 0x718442: dd5c2440 FSTP double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00718446: { // 0x718446: d905189b7900 FLD float ptr [0x00799b18]
    const auto address=(0x00799b18u);
    s.fp.load32(m.r32(address));
  }
  L0071844c: { // 0x71844c: dc0d28577800 FMUL double ptr [0x00785728]
    const auto address=(0x00785728u);
    s.fp.multiply64(read64(m,address));
  }
  L00718452: { // 0x718452: dc8620010000 FADD double ptr [ESI + 0x120]
    const auto address=(s.si+0x00000120u);
    s.fp.add64(read64(m,address));
  }
  L00718458: { // 0x718458: dc5c2440 FCOMP double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.compare_pop64(read64(m,address));
  }
  L0071845c: { // 0x71845c: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0071845e: { // 0x71845e: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00718461: { // 0x718461: 0f844afdffff JZ 0x007181b1
    if(integer::condition("JZ",flags)) goto L007181b1;
  }
  L00718467: { // 0x718467: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00718468: { // 0x718468: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00718469: { // 0x718469: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0071846a: { // 0x71846a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0071846b: { // 0x71846b: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L0071846d: { // 0x71846d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0071846e: { // 0x71846e: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_0018ac10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0058ac10: { // 0x58ac10: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0058ac11: { // 0x58ac11: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0058ac12: { // 0x58ac12: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0058ac14: { // 0x58ac14: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0058ac16: { // 0x58ac16: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L0058ac19: { // 0x58ac19: 895e10 MOV dword ptr [ESI + 0x10],EBX
    m.w32((s.si+0x00000010u), s.bx);
  }
  L0058ac1c: { // 0x58ac1c: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0058ac1e: { // 0x58ac1e: 7411 JZ 0x0058ac31
    if(integer::condition("JZ",flags)) goto L0058ac31;
  }
  L0058ac20: { // 0x58ac20: 385e0d CMP byte ptr [ESI + 0xd],BL
    (void)integer::sub(m.r8((s.si+0x0000000du)),(s.bx & 0xffu),8,flags);
  }
  L0058ac23: { // 0x58ac23: 740c JZ 0x0058ac31
    if(integer::condition("JZ",flags)) goto L0058ac31;
  }
  L0058ac25: { // 0x58ac25: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0058ac26: { // 0x58ac26: e8502a1e00 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,5811243u,op); flags=s.arithmetic_flags;
  }
  L0058ac2b: { // 0x58ac2b: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0058ac2e: { // 0x58ac2e: 895e04 MOV dword ptr [ESI + 0x4],EBX
    m.w32((s.si+0x00000004u), s.bx);
  }
  L0058ac31: { // 0x58ac31: 885e0d MOV byte ptr [ESI + 0xd],BL
    m.w8((s.si+0x0000000du), (s.bx & 0xffu));
  }
  L0058ac34: { // 0x58ac34: 895e08 MOV dword ptr [ESI + 0x8],EBX
    m.w32((s.si+0x00000008u), s.bx);
  }
  L0058ac37: { // 0x58ac37: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0058ac38: { // 0x58ac38: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0058ac39: { // 0x58ac39: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

inline void invoke(Memory&m,State&s,Frame&f,unsigned target,unsigned continuation,const Operations&op){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 if(target==0x76d67bu){if(!op.release)throw std::domain_error("genuine ordinary release callback required");const unsigned actual=op.release(op.heap_context,m,m.r32(child.entry_sp+4),s.fp);s.ax=actual;finish(m,s,child,0);f.sp=child.sp;return;}
 switch(target){
case 0x717f20u:f_00317f20(m,s,child,op);break;
case 0x58ac10u:f_0018ac10(m,s,child,op);break;
default:throw std::domain_error("B1662 unresolved authentic target; fail closed");}f.sp=child.sp;
}
struct ExpectedByte { std::uint32_t address; unsigned char value; };
constexpr ExpectedByte ro_bytes[]={
{0x790ef0u,0x10u},
{0x790ef1u,0xacu},
{0x790ef2u,0x58u},
{0x790ef3u,0x00u},
{0x799b18u,0xcdu},
{0x799b19u,0xccu},
{0x799b1au,0x4cu},
{0x799b1bu,0x3du},
{0x785728u,0x00u},
{0x785729u,0x00u},
{0x78572au,0x00u},
{0x78572bu,0x00u},
{0x78572cu,0x00u},
{0x78572du,0x00u},
{0x78572eu,0xe0u},
{0x78572fu,0x3fu},
};

bool disjoint(std::uint64_t a,std::uint64_t an,std::uint64_t b,std::uint64_t bn){return a+an<=b||b+bn<=a;}
bool arena_span(std::uint32_t a,std::uint32_t n){constexpr std::uint32_t bases[]{0x18000000u,0x24000000u,0x31000000u};for(auto b:bases)if(a>=b&&std::uint64_t(a)+n<=std::uint64_t(b)+0x140000u)return true;return false;}
void read_span(Memory&m,std::uint32_t a,std::uint32_t n){if(!a||std::uint64_t(a)+n>0x100000000ull)throw std::domain_error("public span bounds");for(std::uint32_t i=0;i<n;++i)(void)m.r8(a+i);}
} // namespace
Result run(Memory&world,std::uint32_t entry,unsigned char*storage,unsigned size,const NativeState&in,const fp::Image&incoming,const Operations&op){
 if(!storage||size!=0x8000u+68u||entry<0x8000u||(entry&7u)||std::uint64_t(entry)+68u>0x100000000ull||std::uint64_t(reinterpret_cast<std::uintptr_t>(storage))+0x8000u!=entry)throw std::domain_error("owned 32KB private caller extent/alignment");
 if(!op.heap_context||!op.release)throw std::domain_error("actual ordinary release provider/context required");
 const std::uint64_t lo=std::uint64_t(entry)-0x8000u,hi=std::uint64_t(entry)+68u;
 leaf::Memory local(storage,static_cast<unsigned>(lo),size);Memory m=world;m.add(local);
 std::array<std::uint32_t,16> before{};for(unsigned i=0;i<16;++i)before[i]=m.r32(entry+4u+4u*i);
 const std::uint32_t self=in.cx;
 if(!self||!arena_span(self,0x1d0u)||!disjoint(lo,hi-lo,self,0x1d0u))throw std::domain_error("finite owned self arena extent outside private caller");
 read_span(m,self,0x1d0u);
 if(m.r32(self)!=0x799b60u||m.r32(self+4)!=0x799b44u||m.r32(self+8)!=0x799b3cu||m.r32(self+12)!=0x799b34u)throw std::domain_error("normal primary/secondary addresspoints");
 if(m.r32(self+0xa0)!=0||m.r32(self+0xa4)!=0||m.r8(self+0x118)!=1||m.r32(self+0x120)!=0||m.r32(self+0x124)!=0)throw std::domain_error("finite zero coordinates and scalar FP route");
 const auto vector=self+0x1b8u,data=m.r32(vector+4);
 if(m.r32(vector)!=0x790ee4u||!data||m.r32(vector+8)!=5||m.r8(vector+12)!=1||m.r8(vector+13)!=1||m.r32(vector+16)!=0||m.r32(vector+20)!=10)throw std::domain_error("normal owned vector capacity5 count0 growth10");
 // Provider qualification binds the pointer to the actual twenty-byte allocation and ownership.
 if(std::uint64_t(data)+20u>0x100000000ull||!disjoint(lo,hi-lo,data,20)||!disjoint(self,0x1d0u,data,20))throw std::domain_error("release backing outside self/private extents");
 for(const auto&b:ro_bytes)if(m.r8(b.address)!=b.value)throw std::domain_error("exact authenticated readonly table/scalar input required");
 constexpr unsigned short controls[]{0x037f,0x077f,0x0b7f,0x0f7f,0x027f,0x067f,0x0a7f,0x0e7f,0x007f,0x047f,0x087f,0x0c7f};bool cw_ok=false;for(auto cw:controls)if(incoming.word(0)==cw)cw_ok=true;
 if(!cw_ok||incoming.word(8)!=0xffffu||(incoming.word(4)&~0x3800u)!=0||(in.flags&0x400u))throw std::domain_error("finite x87 CW/TOP/empty tags/DF precondition");
 State s{};s.ax=in.ax;s.cx=in.cx;s.dx=in.dx;s.bx=in.bx;s.bp=in.bp;s.si=in.si;s.di=in.di;s.arithmetic_flags=in.flags;s.fp.image=incoming;
 Frame f{entry,entry,m.r32(entry)};f_00317f20(m,s,f,op);
 const auto expected_status=static_cast<std::uint16_t>((incoming.word(4)&0x3800u)|0x0100u);
 if(f.sp!=entry+4u||s.ax!=expected_status)throw std::domain_error("Root RET0/full EAX includes literal x87 TOP/status");
 if(s.bx!=in.bx||s.bp!=in.bp||s.si!=in.si||s.di!=in.di||(s.arithmetic_flags&0x400u))throw std::domain_error("preserved nonvolatiles/DF");
 fp::Image expected=incoming;expected.word(4,expected_status);
 constexpr unsigned char final_st7[]{0x00,0x00,0x00,0x00,0x00,0xcd,0xcc,0xcc,0xf9,0x3f};
 for(unsigned i=0;i<10;++i)expected.bytes[98+i]=final_st7[i];
 if(!fp::same_numeric(s.fp.image,expected))throw std::domain_error("exact numeric86/CW/SW/tags/all80 poststate without normalization");
 if(m.r32(vector+4)!=0||m.r32(vector+8)!=0||m.r8(vector+12)!=1||m.r8(vector+13)!=0||m.r32(vector+16)!=0||m.r32(vector+20)!=10||m.r32(vector)!=0x790ee4u)throw std::domain_error("owned vector release exact public poststate");
 Result result{s.ax,s,{}};for(unsigned i=0;i<16;++i){result.words[i]=m.r32(entry+4u+4u*i);if(result.words[i]!=before[i])throw std::domain_error("all sixteen caller words preserved");}return result;
}
} // namespace ra2::recovered::b1662
