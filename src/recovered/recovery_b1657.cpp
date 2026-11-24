#include "recovered/recovery_b1657.hpp"
namespace ra2::recovered::b1657 {
using namespace floating_b61;
using Frame=recovery_b566::Frame;
using recovery_b566::finish;using recovery_b566::string_instruction;using recovery_b566::Kind;using recovery_b566::Repeat;using recovery_b566::reverse_divide32;using recovery_b566::reverse_divide64;
namespace integer=direct_b33::integer;namespace floating_b61=ra2::recovered::floating_b61;namespace numeric_b88=ra2::recovered::numeric_b88;
namespace {
inline void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
void invoke(Memory&,State&,Frame&,unsigned,unsigned,const Operations&);
void f_00178ed0(Memory&,State&,Frame&,const Operations&);
void f_0006cc20(Memory&,State&,Frame&,const Operations&);
void f_000ba080(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void f_0022fde0(Memory&,State&,Frame&,const Operations&);
void f_0006ce50(Memory&,State&,Frame&,const Operations&);

void f_00178ed0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00578ed0: { // 0x578ed0: 83ec74 SUB ESP,0x74
    f.sp = integer::sub(f.sp,0x00000074u,32,flags);
  }
  L00578ed3: { // 0x578ed3: db44247c FILD dword ptr [ESP + 0x7c]
    const auto address=(f.sp+0x0000007cu);
    s.fp.load_integer32(m.r32(address));
  }
  L00578ed7: { // 0x578ed7: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00578ed8: { // 0x578ed8: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00578ed9: { // 0x578ed9: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00578eda: { // 0x578eda: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00578edb: { // 0x578edb: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00578ede: { // 0x578ede: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00578ee1: { // 0x578ee1: e89a11f4ff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,5738214u,op); flags=s.arithmetic_flags;
  }
  L00578ee6: { // 0x578ee6: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00578ee9: { // 0x578ee9: e8621b1f00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5738222u,op); flags=s.arithmetic_flags;
  }
  L00578eee: { // 0x578eee: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00578ef0: { // 0x578ef0: 8bbc248c000000 MOV EDI,dword ptr [ESP + 0x8c]
    s.di = m.r32((f.sp+0x0000008cu));
  }
  L00578ef7: { // 0x578ef7: 0fafc8 IMUL ECX,EAX
    s.cx = integer::imul(s.cx,s.ax,32,flags);
  }
  L00578efa: { // 0x578efa: 3bcf CMP ECX,EDI
    (void)integer::sub(s.cx,s.di,32,flags);
  }
  L00578efc: { // 0x578efc: 89442438 MOV dword ptr [ESP + 0x38],EAX
    m.w32((f.sp+0x00000038u), s.ax);
  }
  L00578f00: { // 0x578f00: 7508 JNZ 0x00578f0a
    if(integer::condition("JNZ",flags)) goto L00578f0a;
  }
  L00578f02: { // 0x578f02: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00578f04: { // 0x578f04: 895c2420 MOV dword ptr [ESP + 0x20],EBX
    m.w32((f.sp+0x00000020u), s.bx);
  }
  L00578f08: { // 0x578f08: eb09 JMP 0x00578f13
    goto L00578f13;
  }
  L00578f0a: { // 0x578f0a: 8d5001 LEA EDX,[EAX + 0x1]
    s.dx = (s.ax+0x00000001u);
  }
  L00578f0d: { // 0x578f0d: 89542420 MOV dword ptr [ESP + 0x20],EDX
    m.w32((f.sp+0x00000020u), s.dx);
  }
  L00578f11: { // 0x578f11: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  L00578f13: { // 0x578f13: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00578f15: { // 0x578f15: 0fafc8 IMUL ECX,EAX
    s.cx = integer::imul(s.cx,s.ax,32,flags);
  }
  L00578f18: { // 0x578f18: 3bcf CMP ECX,EDI
    (void)integer::sub(s.cx,s.di,32,flags);
  }
  L00578f1a: { // 0x578f1a: 7c08 JL 0x00578f24
    if(integer::condition("JL",flags)) goto L00578f24;
  }
  L00578f1c: { // 0x578f1c: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00578f1e: { // 0x578f1e: 89742410 MOV dword ptr [ESP + 0x10],ESI
    m.w32((f.sp+0x00000010u), s.si);
  }
  L00578f22: { // 0x578f22: eb06 JMP 0x00578f2a
    goto L00578f2a;
  }
  L00578f24: { // 0x578f24: 895c2410 MOV dword ptr [ESP + 0x10],EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
  L00578f28: { // 0x578f28: 8bf3 MOV ESI,EBX
    s.si = s.bx;
  }
  L00578f2a: { // 0x578f2a: 8bac2490000000 MOV EBP,dword ptr [ESP + 0x90]
    s.bp = m.r32((f.sp+0x00000090u));
  }
  L00578f31: { // 0x578f31: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L00578f36: { // 0x578f36: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L00578f39: { // 0x578f39: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00578f3a: { // 0x578f3a: f7fb IDIV EBX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.bx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00578f3c: { // 0x578f3c: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00578f40: { // 0x578f40: 8b450c MOV EAX,dword ptr [EBP + 0xc]
    s.ax = m.r32((s.bp+0x0000000cu));
  }
  L00578f43: { // 0x578f43: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00578f44: { // 0x578f44: f7fb IDIV EBX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.bx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00578f46: { // 0x578f46: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00578f4a: { // 0x578f4a: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00578f4c: { // 0x578f4c: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L00578f50: { // 0x578f50: 89442434 MOV dword ptr [ESP + 0x34],EAX
    m.w32((f.sp+0x00000034u), s.ax);
  }
  L00578f54: { // 0x578f54: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L00578f58: { // 0x578f58: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L00578f5c: { // 0x578f5c: e87f6e0b00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5738337u,op); flags=s.arithmetic_flags;
  }
  L00578f61: { // 0x578f61: 8944243c MOV dword ptr [ESP + 0x3c],EAX
    m.w32((f.sp+0x0000003cu), s.ax);
  }
  L00578f65: { // 0x578f65: c744244000000000 MOV dword ptr [ESP + 0x40],0x0
    m.w32((f.sp+0x00000040u), 0x00000000u);
  }
  L00578f6d: { // 0x578f6d: df6c243c FILD qword ptr [ESP + 0x3c]
    const auto address=(f.sp+0x0000003cu);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L00578f71: { // 0x578f71: dc0db00d7900 FMUL double ptr [0x00790db0]
    const auto address=(0x00790db0u);
    s.fp.multiply64(read64(m,address));
  }
  L00578f77: { // 0x578f77: dc1d28577800 FCOMP double ptr [0x00785728]
    const auto address=(0x00785728u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00578f7d: { // 0x578f7d: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00578f7f: { // 0x578f7f: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00578f82: { // 0x578f82: 7418 JZ 0x00578f9c
    if(integer::condition("JZ",flags)) goto L00578f9c;
  }
  L00578f84: { // 0x578f84: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L00578f87: { // 0x578f87: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00578f88: { // 0x578f88: f7fe IDIV ESI
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.si,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00578f8a: { // 0x578f8a: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L00578f8e: { // 0x578f8e: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L00578f92: { // 0x578f92: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00578f96: { // 0x578f96: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L00578f9a: { // 0x578f9a: eb16 JMP 0x00578fb2
    goto L00578fb2;
  }
  L00578f9c: { // 0x578f9c: 8b450c MOV EAX,dword ptr [EBP + 0xc]
    s.ax = m.r32((s.bp+0x0000000cu));
  }
  L00578f9f: { // 0x578f9f: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L00578fa3: { // 0x578fa3: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00578fa4: { // 0x578fa4: f7fe IDIV ESI
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.si,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00578fa6: { // 0x578fa6: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L00578faa: { // 0x578faa: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00578fae: { // 0x578fae: 89442434 MOV dword ptr [ESP + 0x34],EAX
    m.w32((f.sp+0x00000034u), s.ax);
  }
  L00578fb2: { // 0x578fb2: 0faff3 IMUL ESI,EBX
    s.si = integer::imul(s.si,s.bx,32,flags);
  }
  L00578fb5: { // 0x578fb5: 8b4d04 MOV ECX,dword ptr [EBP + 0x4]
    s.cx = m.r32((s.bp+0x00000004u));
  }
  L00578fb8: { // 0x578fb8: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L00578fbb: { // 0x578fbb: 2bf7 SUB ESI,EDI
    s.si = integer::sub(s.si,s.di,32,flags);
  }
  L00578fbd: { // 0x578fbd: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00578fbf: { // 0x578fbf: 894c2440 MOV dword ptr [ESP + 0x40],ECX
    m.w32((f.sp+0x00000040u), s.cx);
  }
  L00578fc3: { // 0x578fc3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00578fc4: { // 0x578fc4: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00578fc5: { // 0x578fc5: 8d4c2474 LEA ECX,[ESP + 0x74]
    s.cx = (f.sp+0x00000074u);
  }
  L00578fc9: { // 0x578fc9: 89442444 MOV dword ptr [ESP + 0x44],EAX
    m.w32((f.sp+0x00000044u), s.ax);
  }
  L00578fcd: { // 0x578fcd: e84e3cefff CALL 0x0046cc20
    s.arithmetic_flags=flags; invoke(m,s,f,0x0046cc20u,5738450u,op); flags=s.arithmetic_flags;
  }
  L00578fd2: { // 0x578fd2: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00578fd3: { // 0x578fd3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00578fd4: { // 0x578fd4: 8d4c245c LEA ECX,[ESP + 0x5c]
    s.cx = (f.sp+0x0000005cu);
  }
  L00578fd8: { // 0x578fd8: c7442474948a7800 MOV dword ptr [ESP + 0x74],0x788a94
    m.w32((f.sp+0x00000074u), 0x00788a94u);
  }
  L00578fe0: { // 0x578fe0: c78424880000000a000000 MOV dword ptr [ESP + 0x88],0xa
    m.w32((f.sp+0x00000088u), 0x0000000au);
  }
  L00578feb: { // 0x578feb: 89bc2484000000 MOV dword ptr [ESP + 0x84],EDI
    m.w32((f.sp+0x00000084u), s.di);
  }
  L00578ff2: { // 0x578ff2: e8293cefff CALL 0x0046cc20
    s.arithmetic_flags=flags; invoke(m,s,f,0x0046cc20u,5738487u,op); flags=s.arithmetic_flags;
  }
  L00578ff7: { // 0x578ff7: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00578ffb: { // 0x578ffb: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00578ffd: { // 0x578ffd: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00578fff: { // 0x578fff: c7442454948a7800 MOV dword ptr [ESP + 0x54],0x788a94
    m.w32((f.sp+0x00000054u), 0x00788a94u);
  }
  L00579007: { // 0x579007: c74424680a000000 MOV dword ptr [ESP + 0x68],0xa
    m.w32((f.sp+0x00000068u), 0x0000000au);
  }
  L0057900f: { // 0x57900f: 894c2464 MOV dword ptr [ESP + 0x64],ECX
    m.w32((f.sp+0x00000064u), s.cx);
  }
  L00579013: { // 0x579013: 0f8ea0000000 JLE 0x005790b9
    if(integer::condition("JLE",flags)) goto L005790b9;
  }
  L00579019: { // 0x579019: 8b442474 MOV EAX,dword ptr [ESP + 0x74]
    s.ax = m.r32((f.sp+0x00000074u));
  }
  L0057901d: { // 0x57901d: 8b4c247c MOV ECX,dword ptr [ESP + 0x7c]
    s.cx = m.r32((f.sp+0x0000007cu));
  }
  L00579021: { // 0x579021: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00579023: { // 0x579023: 7c2b JL 0x00579050
    if(integer::condition("JL",flags)) goto L00579050;
  }
  L00579025: { // 0x579025: 8a4c2479 MOV CL,byte ptr [ESP + 0x79]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000079u)));
  }
  L00579029: { // 0x579029: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0057902b: { // 0x57902b: 7504 JNZ 0x00579031
    if(integer::condition("JNZ",flags)) goto L00579031;
  }
  L0057902d: { // 0x57902d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0057902f: { // 0x57902f: 7531 JNZ 0x00579062
    if(integer::condition("JNZ",flags)) goto L00579062;
  }
  L00579031: { // 0x579031: 8b8c2480000000 MOV ECX,dword ptr [ESP + 0x80]
    s.cx = m.r32((f.sp+0x00000080u));
  }
  L00579038: { // 0x579038: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0057903a: { // 0x57903a: 7e26 JLE 0x00579062
    if(integer::condition("JLE",flags)) goto L00579062;
  }
  L0057903c: { // 0x57903c: 8b54246c MOV EDX,dword ptr [ESP + 0x6c]
    s.dx = m.r32((f.sp+0x0000006cu));
  }
  L00579040: { // 0x579040: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00579042: { // 0x579042: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00579044: { // 0x579044: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00579045: { // 0x579045: 8d4c2474 LEA ECX,[ESP + 0x74]
    s.cx = (f.sp+0x00000074u);
  }
  L00579049: { // 0x579049: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),5738572u,op); flags=s.arithmetic_flags;
  }
  L0057904c: { // 0x57904c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0057904e: { // 0x57904e: 7412 JZ 0x00579062
    if(integer::condition("JZ",flags)) goto L00579062;
  }
  L00579050: { // 0x579050: 8b4c247c MOV ECX,dword ptr [ESP + 0x7c]
    s.cx = m.r32((f.sp+0x0000007cu));
  }
  L00579054: { // 0x579054: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00579056: { // 0x579056: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00579057: { // 0x579057: 894c247c MOV dword ptr [ESP + 0x7c],ECX
    m.w32((f.sp+0x0000007cu), s.cx);
  }
  L0057905b: { // 0x57905b: 8b4c2470 MOV ECX,dword ptr [ESP + 0x70]
    s.cx = m.r32((f.sp+0x00000070u));
  }
  L0057905f: { // 0x57905f: 891c81 MOV dword ptr [ECX + EAX*0x4],EBX
    m.w32((s.cx+(s.ax * 0x00000004u)), s.bx);
  }
  L00579062: { // 0x579062: 8b44245c MOV EAX,dword ptr [ESP + 0x5c]
    s.ax = m.r32((f.sp+0x0000005cu));
  }
  L00579066: { // 0x579066: 8b4c2464 MOV ECX,dword ptr [ESP + 0x64]
    s.cx = m.r32((f.sp+0x00000064u));
  }
  L0057906a: { // 0x57906a: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L0057906c: { // 0x57906c: 7c28 JL 0x00579096
    if(integer::condition("JL",flags)) goto L00579096;
  }
  L0057906e: { // 0x57906e: 8a4c2461 MOV CL,byte ptr [ESP + 0x61]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000061u)));
  }
  L00579072: { // 0x579072: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00579074: { // 0x579074: 7504 JNZ 0x0057907a
    if(integer::condition("JNZ",flags)) goto L0057907a;
  }
  L00579076: { // 0x579076: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00579078: { // 0x579078: 752e JNZ 0x005790a8
    if(integer::condition("JNZ",flags)) goto L005790a8;
  }
  L0057907a: { // 0x57907a: 8b4c2468 MOV ECX,dword ptr [ESP + 0x68]
    s.cx = m.r32((f.sp+0x00000068u));
  }
  L0057907e: { // 0x57907e: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00579080: { // 0x579080: 7e26 JLE 0x005790a8
    if(integer::condition("JLE",flags)) goto L005790a8;
  }
  L00579082: { // 0x579082: 8b542454 MOV EDX,dword ptr [ESP + 0x54]
    s.dx = m.r32((f.sp+0x00000054u));
  }
  L00579086: { // 0x579086: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00579088: { // 0x579088: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0057908a: { // 0x57908a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0057908b: { // 0x57908b: 8d4c245c LEA ECX,[ESP + 0x5c]
    s.cx = (f.sp+0x0000005cu);
  }
  L0057908f: { // 0x57908f: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),5738642u,op); flags=s.arithmetic_flags;
  }
  L00579092: { // 0x579092: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00579094: { // 0x579094: 7412 JZ 0x005790a8
    if(integer::condition("JZ",flags)) goto L005790a8;
  }
  L00579096: { // 0x579096: 8b4c2464 MOV ECX,dword ptr [ESP + 0x64]
    s.cx = m.r32((f.sp+0x00000064u));
  }
  L0057909a: { // 0x57909a: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0057909c: { // 0x57909c: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0057909d: { // 0x57909d: 894c2464 MOV dword ptr [ESP + 0x64],ECX
    m.w32((f.sp+0x00000064u), s.cx);
  }
  L005790a1: { // 0x5790a1: 8b4c2458 MOV ECX,dword ptr [ESP + 0x58]
    s.cx = m.r32((f.sp+0x00000058u));
  }
  L005790a5: { // 0x5790a5: 893c81 MOV dword ptr [ECX + EAX*0x4],EDI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.di);
  }
  L005790a8: { // 0x5790a8: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L005790ac: { // 0x5790ac: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L005790ad: { // 0x5790ad: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L005790af: { // 0x5790af: 0f8c64ffffff JL 0x00579019
    if(integer::condition("JL",flags)) goto L00579019;
  }
  L005790b5: { // 0x5790b5: 8b4c2464 MOV ECX,dword ptr [ESP + 0x64]
    s.cx = m.r32((f.sp+0x00000064u));
  }
  L005790b9: { // 0x5790b9: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L005790bb: { // 0x5790bb: 0f8e87000000 JLE 0x00579148
    if(integer::condition("JLE",flags)) goto L00579148;
  }
  L005790c1: { // 0x5790c1: 8bfe MOV EDI,ESI
    s.di = s.si;
  }
  L005790c3: { // 0x5790c3: 8d71ff LEA ESI,[ECX + -0x1]
    s.si = (s.cx-0x00000001u);
  }
  L005790c6: { // 0x5790c6: c744242c00000000 MOV dword ptr [ESP + 0x2c],0x0
    m.w32((f.sp+0x0000002cu), 0x00000000u);
  }
  L005790ce: { // 0x5790ce: 8d5601 LEA EDX,[ESI + 0x1]
    s.dx = (s.si+0x00000001u);
  }
  L005790d1: { // 0x5790d1: 89542428 MOV dword ptr [ESP + 0x28],EDX
    m.w32((f.sp+0x00000028u), s.dx);
  }
  L005790d5: { // 0x5790d5: df6c2428 FILD qword ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L005790d9: { // 0x5790d9: dd5c244c FSTP double ptr [ESP + 0x4c]
    const auto address=(f.sp+0x0000004cu);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L005790dd: { // 0x5790dd: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L005790e2: { // 0x5790e2: e8f96c0b00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5738727u,op); flags=s.arithmetic_flags;
  }
  L005790e7: { // 0x5790e7: 89442444 MOV dword ptr [ESP + 0x44],EAX
    m.w32((f.sp+0x00000044u), s.ax);
  }
  L005790eb: { // 0x5790eb: c744244800000000 MOV dword ptr [ESP + 0x48],0x0
    m.w32((f.sp+0x00000048u), 0x00000000u);
  }
  L005790f3: { // 0x5790f3: df6c2444 FILD qword ptr [ESP + 0x44]
    const auto address=(f.sp+0x00000044u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L005790f7: { // 0x5790f7: dc4c244c FMUL double ptr [ESP + 0x4c]
    const auto address=(f.sp+0x0000004cu);
    s.fp.multiply64(read64(m,address));
  }
  L005790fb: { // 0x5790fb: dc0db00d7900 FMUL double ptr [0x00790db0]
    const auto address=(0x00790db0u);
    s.fp.multiply64(read64(m,address));
  }
  L00579101: { // 0x579101: e84a191f00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5738758u,op); flags=s.arithmetic_flags;
  }
  L00579106: { // 0x579106: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L00579108: { // 0x579108: 77d3 JA 0x005790dd
    if(integer::condition("JA",flags)) goto L005790dd;
  }
  L0057910a: { // 0x57910a: 8b4c2458 MOV ECX,dword ptr [ESP + 0x58]
    s.cx = m.r32((f.sp+0x00000058u));
  }
  L0057910e: { // 0x57910e: 8b742438 MOV ESI,dword ptr [ESP + 0x38]
    s.si = m.r32((f.sp+0x00000038u));
  }
  L00579112: { // 0x579112: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L00579115: { // 0x579115: 8b4c2470 MOV ECX,dword ptr [ESP + 0x70]
    s.cx = m.r32((f.sp+0x00000070u));
  }
  L00579119: { // 0x579119: 893491 MOV dword ptr [ECX + EDX*0x4],ESI
    m.w32((s.cx+(s.dx * 0x00000004u)), s.si);
  }
  L0057911c: { // 0x57911c: 8b4c2464 MOV ECX,dword ptr [ESP + 0x64]
    s.cx = m.r32((f.sp+0x00000064u));
  }
  L00579120: { // 0x579120: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00579122: { // 0x579122: 7d1d JGE 0x00579141
    if(integer::condition("JGE",flags)) goto L00579141;
  }
  L00579124: { // 0x579124: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00579125: { // 0x579125: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00579127: { // 0x579127: 894c2464 MOV dword ptr [ESP + 0x64],ECX
    m.w32((f.sp+0x00000064u), s.cx);
  }
  L0057912b: { // 0x57912b: 7d14 JGE 0x00579141
    if(integer::condition("JGE",flags)) goto L00579141;
  }
  L0057912d: { // 0x57912d: 8b4c2458 MOV ECX,dword ptr [ESP + 0x58]
    s.cx = m.r32((f.sp+0x00000058u));
  }
  L00579131: { // 0x579131: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00579132: { // 0x579132: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L00579135: { // 0x579135: 895481fc MOV dword ptr [ECX + EAX*0x4 + -0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)-0x00000004u), s.dx);
  }
  L00579139: { // 0x579139: 8b4c2464 MOV ECX,dword ptr [ESP + 0x64]
    s.cx = m.r32((f.sp+0x00000064u));
  }
  L0057913d: { // 0x57913d: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0057913f: { // 0x57913f: 7cec JL 0x0057912d
    if(integer::condition("JL",flags)) goto L0057912d;
  }
  L00579141: { // 0x579141: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L00579142: { // 0x579142: 0f857bffffff JNZ 0x005790c3
    if(integer::condition("JNZ",flags)) goto L005790c3;
  }
  L00579148: { // 0x579148: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0057914c: { // 0x57914c: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0057914e: { // 0x57914e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00579150: { // 0x579150: 897c2438 MOV dword ptr [ESP + 0x38],EDI
    m.w32((f.sp+0x00000038u), s.di);
  }
  L00579154: { // 0x579154: 0f8e33010000 JLE 0x0057928d
    if(integer::condition("JLE",flags)) goto L0057928d;
  }
  L0057915a: { // 0x57915a: 8bb42488000000 MOV ESI,dword ptr [ESP + 0x88]
    s.si = m.r32((f.sp+0x00000088u));
  }
  L00579161: { // 0x579161: 8b442470 MOV EAX,dword ptr [ESP + 0x70]
    s.ax = m.r32((f.sp+0x00000070u));
  }
  L00579165: { // 0x579165: 8b0cb8 MOV ECX,dword ptr [EAX + EDI*0x4]
    s.cx = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  L00579168: { // 0x579168: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L0057916a: { // 0x57916a: 7d30 JGE 0x0057919c
    if(integer::condition("JGE",flags)) goto L0057919c;
  }
  L0057916c: { // 0x57916c: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L00579170: { // 0x579170: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00579172: { // 0x579172: 7e15 JLE 0x00579189
    if(integer::condition("JLE",flags)) goto L00579189;
  }
  L00579174: { // 0x579174: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00579178: { // 0x579178: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00579179: { // 0x579179: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0057917b: { // 0x57917b: 8b54243c MOV EDX,dword ptr [ESP + 0x3c]
    s.dx = m.r32((f.sp+0x0000003cu));
  }
  L0057917f: { // 0x57917f: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00579181: { // 0x579181: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00579183: { // 0x579183: 8954243c MOV dword ptr [ESP + 0x3c],EDX
    m.w32((f.sp+0x0000003cu), s.dx);
  }
  L00579187: { // 0x579187: eb13 JMP 0x0057919c
    goto L0057919c;
  }
  L00579189: { // 0x579189: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0057918d: { // 0x57918d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0057918e: { // 0x57918e: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00579190: { // 0x579190: 8b542440 MOV EDX,dword ptr [ESP + 0x40]
    s.dx = m.r32((f.sp+0x00000040u));
  }
  L00579194: { // 0x579194: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00579196: { // 0x579196: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00579198: { // 0x579198: 89542440 MOV dword ptr [ESP + 0x40],EDX
    m.w32((f.sp+0x00000040u), s.dx);
  }
  L0057919c: { // 0x57919c: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0057919e: { // 0x57919e: 0f8ea4000000 JLE 0x00579248
    if(integer::condition("JLE",flags)) goto L00579248;
  }
  L005791a4: { // 0x5791a4: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L005791a8: { // 0x5791a8: 894c2428 MOV dword ptr [ESP + 0x28],ECX
    m.w32((f.sp+0x00000028u), s.cx);
  }
  L005791ac: { // 0x5791ac: 8d5afc LEA EBX,[EDX + -0x4]
    s.bx = (s.dx-0x00000004u);
  }
  L005791af: { // 0x5791af: 8b44243c MOV EAX,dword ptr [ESP + 0x3c]
    s.ax = m.r32((f.sp+0x0000003cu));
  }
  L005791b3: { // 0x5791b3: 8b4c2440 MOV ECX,dword ptr [ESP + 0x40]
    s.cx = m.r32((f.sp+0x00000040u));
  }
  L005791b7: { // 0x5791b7: 8d7802 LEA EDI,[EAX + 0x2]
    s.di = (s.ax+0x00000002u);
  }
  L005791ba: { // 0x5791ba: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L005791bd: { // 0x5791bd: 8d6902 LEA EBP,[ECX + 0x2]
    s.bp = (s.cx+0x00000002u);
  }
  L005791c0: { // 0x5791c0: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    s.cx = m.r32((s.si+0x00000010u));
  }
  L005791c3: { // 0x5791c3: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L005791c5: { // 0x5791c5: 7c22 JL 0x005791e9
    if(integer::condition("JL",flags)) goto L005791e9;
  }
  L005791c7: { // 0x5791c7: 8a4e0d MOV CL,byte ptr [ESI + 0xd]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000000du)));
  }
  L005791ca: { // 0x5791ca: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L005791cc: { // 0x5791cc: 7504 JNZ 0x005791d2
    if(integer::condition("JNZ",flags)) goto L005791d2;
  }
  L005791ce: { // 0x5791ce: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005791d0: { // 0x5791d0: 753c JNZ 0x0057920e
    if(integer::condition("JNZ",flags)) goto L0057920e;
  }
  L005791d2: { // 0x5791d2: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx = m.r32((s.si+0x00000014u));
  }
  L005791d5: { // 0x5791d5: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005791d7: { // 0x5791d7: 7e35 JLE 0x0057920e
    if(integer::condition("JLE",flags)) goto L0057920e;
  }
  L005791d9: { // 0x5791d9: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005791db: { // 0x5791db: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L005791dd: { // 0x5791dd: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L005791df: { // 0x5791df: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005791e0: { // 0x5791e0: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005791e2: { // 0x5791e2: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),5738981u,op); flags=s.arithmetic_flags;
  }
  L005791e5: { // 0x5791e5: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005791e7: { // 0x5791e7: 7425 JZ 0x0057920e
    if(integer::condition("JZ",flags)) goto L0057920e;
  }
  L005791e9: { // 0x5791e9: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L005791ec: { // 0x5791ec: 8d4801 LEA ECX,[EAX + 0x1]
    s.cx = (s.ax+0x00000001u);
  }
  L005791ef: { // 0x5791ef: 894e10 MOV dword ptr [ESI + 0x10],ECX
    m.w32((s.si+0x00000010u), s.cx);
  }
  L005791f2: { // 0x5791f2: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  L005791f5: { // 0x5791f5: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L005791f8: { // 0x5791f8: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L005791fa: { // 0x5791fa: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L005791fc: { // 0x5791fc: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00579200: { // 0x579200: 83c0fc ADD EAX,-0x4
    s.ax = integer::add(s.ax,0xfffffffcu,32,flags);
  }
  L00579203: { // 0x579203: 893a MOV dword ptr [EDX],EDI
    m.w32((s.dx), s.di);
  }
  L00579205: { // 0x579205: 896a04 MOV dword ptr [EDX + 0x4],EBP
    m.w32((s.dx+0x00000004u), s.bp);
  }
  L00579208: { // 0x579208: 895a08 MOV dword ptr [EDX + 0x8],EBX
    m.w32((s.dx+0x00000008u), s.bx);
  }
  L0057920b: { // 0x57920b: 89420c MOV dword ptr [EDX + 0xc],EAX
    m.w32((s.dx+0x0000000cu), s.ax);
  }
  L0057920e: { // 0x57920e: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L00579212: { // 0x579212: 8b54243c MOV EDX,dword ptr [ESP + 0x3c]
    s.dx = m.r32((f.sp+0x0000003cu));
  }
  L00579216: { // 0x579216: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L0057921a: { // 0x57921a: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L0057921c: { // 0x57921c: 8b4c2440 MOV ECX,dword ptr [ESP + 0x40]
    s.cx = m.r32((f.sp+0x00000040u));
  }
  L00579220: { // 0x579220: 8954243c MOV dword ptr [ESP + 0x3c],EDX
    m.w32((f.sp+0x0000003cu), s.dx);
  }
  L00579224: { // 0x579224: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L00579228: { // 0x579228: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L0057922a: { // 0x57922a: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0057922b: { // 0x57922b: 894c2440 MOV dword ptr [ESP + 0x40],ECX
    m.w32((f.sp+0x00000040u), s.cx);
  }
  L0057922f: { // 0x57922f: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L00579233: { // 0x579233: 0f8576ffffff JNZ 0x005791af
    if(integer::condition("JNZ",flags)) goto L005791af;
  }
  L00579239: { // 0x579239: 8b5c2420 MOV EBX,dword ptr [ESP + 0x20]
    s.bx = m.r32((f.sp+0x00000020u));
  }
  L0057923d: { // 0x57923d: 8bac2490000000 MOV EBP,dword ptr [ESP + 0x90]
    s.bp = m.r32((f.sp+0x00000090u));
  }
  L00579244: { // 0x579244: 8b7c2438 MOV EDI,dword ptr [ESP + 0x38]
    s.di = m.r32((f.sp+0x00000038u));
  }
  L00579248: { // 0x579248: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L0057924c: { // 0x57924c: 8b4c243c MOV ECX,dword ptr [ESP + 0x3c]
    s.cx = m.r32((f.sp+0x0000003cu));
  }
  L00579250: { // 0x579250: 8b542440 MOV EDX,dword ptr [ESP + 0x40]
    s.dx = m.r32((f.sp+0x00000040u));
  }
  L00579254: { // 0x579254: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00579256: { // 0x579256: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L0057925a: { // 0x57925a: 894c243c MOV dword ptr [ESP + 0x3c],ECX
    m.w32((f.sp+0x0000003cu), s.cx);
  }
  L0057925e: { // 0x57925e: 8b4c2434 MOV ECX,dword ptr [ESP + 0x34]
    s.cx = m.r32((f.sp+0x00000034u));
  }
  L00579262: { // 0x579262: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L00579264: { // 0x579264: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00579266: { // 0x579266: 89542440 MOV dword ptr [ESP + 0x40],EDX
    m.w32((f.sp+0x00000040u), s.dx);
  }
  L0057926a: { // 0x57926a: 7e09 JLE 0x00579275
    if(integer::condition("JLE",flags)) goto L00579275;
  }
  L0057926c: { // 0x57926c: 8b5500 MOV EDX,dword ptr [EBP]
    s.dx = m.r32((s.bp));
  }
  L0057926f: { // 0x57926f: 8954243c MOV dword ptr [ESP + 0x3c],EDX
    m.w32((f.sp+0x0000003cu), s.dx);
  }
  L00579273: { // 0x579273: eb07 JMP 0x0057927c
    goto L0057927c;
  }
  L00579275: { // 0x579275: 8b4504 MOV EAX,dword ptr [EBP + 0x4]
    s.ax = m.r32((s.bp+0x00000004u));
  }
  L00579278: { // 0x579278: 89442440 MOV dword ptr [ESP + 0x40],EAX
    m.w32((f.sp+0x00000040u), s.ax);
  }
  L0057927c: { // 0x57927c: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00579280: { // 0x579280: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L00579281: { // 0x579281: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L00579283: { // 0x579283: 897c2438 MOV dword ptr [ESP + 0x38],EDI
    m.w32((f.sp+0x00000038u), s.di);
  }
  L00579287: { // 0x579287: 0f8cd4feffff JL 0x00579161
    if(integer::condition("JL",flags)) goto L00579161;
  }
  L0057928d: { // 0x57928d: 8b442458 MOV EAX,dword ptr [ESP + 0x58]
    s.ax = m.r32((f.sp+0x00000058u));
  }
  L00579291: { // 0x579291: bed4897800 MOV ESI,0x7889d4
    s.si = 0x007889d4u;
  }
  L00579296: { // 0x579296: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00579298: { // 0x579298: 89742454 MOV dword ptr [ESP + 0x54],ESI
    m.w32((f.sp+0x00000054u), s.si);
  }
  L0057929c: { // 0x57929c: 7419 JZ 0x005792b7
    if(integer::condition("JZ",flags)) goto L005792b7;
  }
  L0057929e: { // 0x57929e: 8a4c2461 MOV CL,byte ptr [ESP + 0x61]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000061u)));
  }
  L005792a2: { // 0x5792a2: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L005792a4: { // 0x5792a4: 7411 JZ 0x005792b7
    if(integer::condition("JZ",flags)) goto L005792b7;
  }
  L005792a6: { // 0x5792a6: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005792a7: { // 0x5792a7: e8cf431f00 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,5739180u,op); flags=s.arithmetic_flags;
  }
  L005792ac: { // 0x5792ac: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L005792af: { // 0x5792af: c744245800000000 MOV dword ptr [ESP + 0x58],0x0
    m.w32((f.sp+0x00000058u), 0x00000000u);
  }
  L005792b7: { // 0x5792b7: 8b442470 MOV EAX,dword ptr [ESP + 0x70]
    s.ax = m.r32((f.sp+0x00000070u));
  }
  L005792bb: { // 0x5792bb: 8974246c MOV dword ptr [ESP + 0x6c],ESI
    m.w32((f.sp+0x0000006cu), s.si);
  }
  L005792bf: { // 0x5792bf: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005792c0: { // 0x5792c0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005792c1: { // 0x5792c1: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005792c2: { // 0x5792c2: c644245500 MOV byte ptr [ESP + 0x55],0x0
    m.w8((f.sp+0x00000055u), 0x00000000u);
  }
  L005792c7: { // 0x5792c7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005792c9: { // 0x5792c9: c744245000000000 MOV dword ptr [ESP + 0x50],0x0
    m.w32((f.sp+0x00000050u), 0x00000000u);
  }
  L005792d1: { // 0x5792d1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005792d2: { // 0x5792d2: 7411 JZ 0x005792e5
    if(integer::condition("JZ",flags)) goto L005792e5;
  }
  L005792d4: { // 0x5792d4: 8a4c2469 MOV CL,byte ptr [ESP + 0x69]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000069u)));
  }
  L005792d8: { // 0x5792d8: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L005792da: { // 0x5792da: 7409 JZ 0x005792e5
    if(integer::condition("JZ",flags)) goto L005792e5;
  }
  L005792dc: { // 0x5792dc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005792dd: { // 0x5792dd: e899431f00 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,5739234u,op); flags=s.arithmetic_flags;
  }
  L005792e2: { // 0x5792e2: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L005792e5: { // 0x5792e5: 83c474 ADD ESP,0x74
    f.sp = integer::add(f.sp,0x00000074u,32,flags);
  }
  L005792e8: { // 0x5792e8: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}

void f_0006cc20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0046cc20: { // 0x46cc20: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L0046cc24: { // 0x46cc24: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0046cc25: { // 0x46cc25: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0046cc27: { // 0x46cc27: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0046cc29: { // 0x46cc29: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0046cc2b: { // 0x46cc2b: 895604 MOV dword ptr [ESI + 0x4],EDX
    m.w32((s.si+0x00000004u), s.dx);
  }
  L0046cc2e: { // 0x46cc2e: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  L0046cc31: { // 0x46cc31: c6460c01 MOV byte ptr [ESI + 0xc],0x1
    m.w8((s.si+0x0000000cu), 0x00000001u);
  }
  L0046cc35: { // 0x46cc35: 88560d MOV byte ptr [ESI + 0xd],DL
    m.w8((s.si+0x0000000du), (s.dx & 0xffu));
  }
  L0046cc38: { // 0x46cc38: c706d4897800 MOV dword ptr [ESI],0x7889d4
    m.w32((s.si), 0x007889d4u);
  }
  L0046cc3e: { // 0x46cc3e: 7424 JZ 0x0046cc64
    if(integer::condition("JZ",flags)) goto L0046cc64;
  }
  L0046cc40: { // 0x46cc40: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L0046cc44: { // 0x46cc44: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L0046cc46: { // 0x46cc46: 7409 JZ 0x0046cc51
    if(integer::condition("JZ",flags)) goto L0046cc51;
  }
  L0046cc48: { // 0x46cc48: 894e04 MOV dword ptr [ESI + 0x4],ECX
    m.w32((s.si+0x00000004u), s.cx);
  }
  L0046cc4b: { // 0x46cc4b: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0046cc4d: { // 0x46cc4d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0046cc4e: { // 0x46cc4e: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0046cc51: { // 0x46cc51: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L0046cc54: { // 0x46cc54: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0046cc55: { // 0x46cc55: e8fd0c3000 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,4639834u,op); flags=s.arithmetic_flags;
  }
  L0046cc5a: { // 0x46cc5a: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0046cc5d: { // 0x46cc5d: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  L0046cc60: { // 0x46cc60: c6460d01 MOV byte ptr [ESI + 0xd],0x1
    m.w8((s.si+0x0000000du), 0x00000001u);
  }
  L0046cc64: { // 0x46cc64: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0046cc66: { // 0x46cc66: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0046cc67: { // 0x46cc67: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}

void f_000ba080(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004ba080: { // 0x4ba080: dd442404 FLD double ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load64(read64(m,address));
  }
  L004ba084: { // 0x4ba084: d81538577800 FCOM float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.compare32(m.r32(address));
  }
  L004ba08a: { // 0x4ba08a: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004ba08c: { // 0x4ba08c: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L004ba08f: { // 0x4ba08f: 7409 JZ 0x004ba09a
    if(integer::condition("JZ",flags)) goto L004ba09a;
  }
  L004ba091: { // 0x4ba091: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L004ba093: { // 0x4ba093: d90538577800 FLD float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.load32(m.r32(address));
  }
  L004ba099: { // 0x4ba099: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004ba09a: { // 0x4ba09a: d81538577800 FCOM float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.compare32(m.r32(address));
  }
  L004ba0a0: { // 0x4ba0a0: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004ba0a2: { // 0x4ba0a2: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L004ba0a5: { // 0x4ba0a5: 7406 JZ 0x004ba0ad
    if(integer::condition("JZ",flags)) goto L004ba0ad;
  }
  L004ba0a7: { // 0x4ba0a7: dc0d78857800 FMUL double ptr [0x00788578]
    const auto address=(0x00788578u);
    s.fp.multiply64(read64(m,address));
  }
  L004ba0ad: { // 0x4ba0ad: d95c2404 FSTP float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L004ba0b1: { // 0x4ba0b1: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L004ba0b5: { // 0x4ba0b5: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004ba0b7: { // 0x4ba0b7: 81e1ffff7f00 AND ECX,0x7fffff
    s.cx = integer::logical((s.cx)&(0x007fffffu),32,flags);
  }
  L004ba0bd: { // 0x4ba0bd: c1e817 SHR EAX,0x17
    s.ax = integer::shift(s.ax,0x00000017u,32,flags,integer::Shift::right);
  }
  L004ba0c0: { // 0x4ba0c0: 83e87f SUB EAX,0x7f
    s.ax = integer::sub(s.ax,0x0000007fu,32,flags);
  }
  L004ba0c3: { // 0x4ba0c3: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L004ba0c5: { // 0x4ba0c5: 7406 JZ 0x004ba0cd
    if(integer::condition("JZ",flags)) goto L004ba0cd;
  }
  L004ba0c7: { // 0x4ba0c7: 81c900008000 OR ECX,0x800000
    s.cx = integer::logical((s.cx)|(0x00800000u),32,flags);
  }
  L004ba0cd: { // 0x4ba0cd: 66d1f8 SAR AX,0x1
    s.ax = with_ax(s.ax, integer::shift((s.ax & 0xffffu),0x00000001u,16,flags,integer::Shift::arithmetic_right));
  }
  L004ba0d0: { // 0x4ba0d0: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L004ba0d3: { // 0x4ba0d3: c1e90a SHR ECX,0xa
    s.cx = integer::shift(s.cx,0x0000000au,32,flags,integer::Shift::right);
  }
  L004ba0d6: { // 0x4ba0d6: 83c07f ADD EAX,0x7f
    s.ax = integer::add(s.ax,0x0000007fu,32,flags);
  }
  L004ba0d9: { // 0x4ba0d9: 8b0c8d3c018000 MOV ECX,dword ptr [ECX*0x4 + 0x80013c]
    s.cx = m.r32(((s.cx * 0x00000004u)+0x0080013cu));
  }
  L004ba0e0: { // 0x4ba0e0: c1e017 SHL EAX,0x17
    s.ax = integer::shift(s.ax,0x00000017u,32,flags,integer::Shift::left);
  }
  L004ba0e3: { // 0x4ba0e3: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L004ba0e5: { // 0x4ba0e5: 894c2404 MOV dword ptr [ESP + 0x4],ECX
    m.w32((f.sp+0x00000004u), s.cx);
  }
  L004ba0e9: { // 0x4ba0e9: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L004ba0ed: { // 0x4ba0ed: c3 RET
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

void f_0006ce50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0046ce50: { // 0x46ce50: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0046ce51: { // 0x46ce51: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0046ce52: { // 0x46ce52: 8b6c240c MOV EBP,dword ptr [ESP + 0xc]
    s.bp = m.r32((f.sp+0x0000000cu));
  }
  L0046ce56: { // 0x46ce56: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0046ce57: { // 0x46ce57: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0046ce59: { // 0x46ce59: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0046ce5a: { // 0x46ce5a: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0046ce5c: { // 0x46ce5c: 747c JZ 0x0046ceda
    if(integer::condition("JZ",flags)) goto L0046ceda;
  }
  L0046ce5e: { // 0x46ce5e: 8b5c2418 MOV EBX,dword ptr [ESP + 0x18]
    s.bx = m.r32((f.sp+0x00000018u));
  }
  L0046ce62: { // 0x46ce62: c6460c00 MOV byte ptr [ESI + 0xc],0x0
    m.w8((s.si+0x0000000cu), 0x00000000u);
  }
  L0046ce66: { // 0x46ce66: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L0046ce68: { // 0x46ce68: 7514 JNZ 0x0046ce7e
    if(integer::condition("JNZ",flags)) goto L0046ce7e;
  }
  L0046ce6a: { // 0x46ce6a: 8d04ad00000000 LEA EAX,[EBP*0x4 + 0x0]
    s.ax = ((s.bp * 0x00000004u)+0x00000000u);
  }
  L0046ce71: { // 0x46ce71: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0046ce72: { // 0x46ce72: e8e00a3000 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,4640375u,op); flags=s.arithmetic_flags;
  }
  L0046ce77: { // 0x46ce77: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0046ce7a: { // 0x46ce7a: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0046ce7c: { // 0x46ce7c: eb02 JMP 0x0046ce80
    goto L0046ce80;
  }
  L0046ce7e: { // 0x46ce7e: 8bfb MOV EDI,EBX
    s.di = s.bx;
  }
  L0046ce80: { // 0x46ce80: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0046ce82: { // 0x46ce82: c6460c01 MOV byte ptr [ESI + 0xc],0x1
    m.w8((s.si+0x0000000cu), 0x00000001u);
  }
  L0046ce86: { // 0x46ce86: 746f JZ 0x0046cef7
    if(integer::condition("JZ",flags)) goto L0046cef7;
  }
  L0046ce88: { // 0x46ce88: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L0046ce8b: { // 0x46ce8b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0046ce8d: { // 0x46ce8d: 7439 JZ 0x0046cec8
    if(integer::condition("JZ",flags)) goto L0046cec8;
  }
  L0046ce8f: { // 0x46ce8f: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L0046ce92: { // 0x46ce92: 3be9 CMP EBP,ECX
    (void)integer::sub(s.bp,s.cx,32,flags);
  }
  L0046ce94: { // 0x46ce94: 7d02 JGE 0x0046ce98
    if(integer::condition("JGE",flags)) goto L0046ce98;
  }
  L0046ce96: { // 0x46ce96: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0046ce98: { // 0x46ce98: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0046ce9a: { // 0x46ce9a: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0046ce9c: { // 0x46ce9c: 7e10 JLE 0x0046ceae
    if(integer::condition("JLE",flags)) goto L0046ceae;
  }
  L0046ce9e: { // 0x46ce9e: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  L0046cea1: { // 0x46cea1: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0046cea2: { // 0x46cea2: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0046cea4: { // 0x46cea4: 8b5482fc MOV EDX,dword ptr [EDX + EAX*0x4 + -0x4]
    s.dx = m.r32((s.dx+(s.ax * 0x00000004u)-0x00000004u));
  }
  L0046cea8: { // 0x46cea8: 895487fc MOV dword ptr [EDI + EAX*0x4 + -0x4],EDX
    m.w32((s.di+(s.ax * 0x00000004u)-0x00000004u), s.dx);
  }
  L0046ceac: { // 0x46ceac: 7cf0 JL 0x0046ce9e
    if(integer::condition("JL",flags)) goto L0046ce9e;
  }
  L0046ceae: { // 0x46ceae: 8a460d MOV AL,byte ptr [ESI + 0xd]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000000du)));
  }
  L0046ceb1: { // 0x46ceb1: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0046ceb3: { // 0x46ceb3: 7413 JZ 0x0046cec8
    if(integer::condition("JZ",flags)) goto L0046cec8;
  }
  L0046ceb5: { // 0x46ceb5: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L0046ceb8: { // 0x46ceb8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0046ceb9: { // 0x46ceb9: e8bd073000 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,4640446u,op); flags=s.arithmetic_flags;
  }
  L0046cebe: { // 0x46cebe: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0046cec1: { // 0x46cec1: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  L0046cec8: { // 0x46cec8: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0046ceca: { // 0x46ceca: 897e04 MOV dword ptr [ESI + 0x4],EDI
    m.w32((s.si+0x00000004u), s.di);
  }
  L0046cecd: { // 0x46cecd: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L0046cecf: { // 0x46cecf: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  L0046ced2: { // 0x46ced2: 896e08 MOV dword ptr [ESI + 0x8],EBP
    m.w32((s.si+0x00000008u), s.bp);
  }
  L0046ced5: { // 0x46ced5: 88460d MOV byte ptr [ESI + 0xd],AL
    m.w8((s.si+0x0000000du), (s.ax & 0xffu));
  }
  L0046ced8: { // 0x46ced8: eb07 JMP 0x0046cee1
    goto L0046cee1;
  }
  L0046ceda: { // 0x46ceda: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0046cedc: { // 0x46cedc: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0046cede: { // 0x46cede: ff520c CALL dword ptr [EDX + 0xc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000000cu)),4640481u,op); flags=s.arithmetic_flags;
  }
  L0046cee1: { // 0x46cee1: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L0046cee4: { // 0x46cee4: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    s.cx = m.r32((s.si+0x00000010u));
  }
  L0046cee7: { // 0x46cee7: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0046cee9: { // 0x46cee9: 7d03 JGE 0x0046ceee
    if(integer::condition("JGE",flags)) goto L0046ceee;
  }
  L0046ceeb: { // 0x46ceeb: 894610 MOV dword ptr [ESI + 0x10],EAX
    m.w32((s.si+0x00000010u), s.ax);
  }
  L0046ceee: { // 0x46ceee: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0046ceef: { // 0x46ceef: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0046cef0: { // 0x46cef0: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0046cef1: { // 0x46cef1: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0046cef3: { // 0x46cef3: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0046cef4: { // 0x46cef4: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0046cef7: { // 0x46cef7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0046cef8: { // 0x46cef8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0046cef9: { // 0x46cef9: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0046cefa: { // 0x46cefa: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0046cefc: { // 0x46cefc: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0046cefd: { // 0x46cefd: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}

inline void invoke(Memory&m,State&s,Frame&f,unsigned target,unsigned continuation,const Operations&op){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 if(target==0x76d957u){if(!op.allocate)throw std::domain_error("genuine ordinary allocator callback required");const unsigned actual=op.allocate(op.heap_context,m,m.r32(child.entry_sp+4),s.fp);s.ax=actual;finish(m,s,child,0);f.sp=child.sp;return;}
 if(target==0x76d67bu){if(!op.release)throw std::domain_error("genuine ordinary release callback required");const unsigned actual=op.release(op.heap_context,m,m.r32(child.entry_sp+4),s.fp);s.ax=actual;finish(m,s,child,0);f.sp=child.sp;return;}
 switch(target){
case 0x578ed0u:f_00178ed0(m,s,child,op);break;
case 0x46cc20u:f_0006cc20(m,s,child,op);break;
case 0x4ba080u:f_000ba080(m,s,child,op);break;
case 0x76aa50u:f_0036aa50(m,s,child,op);break;
case 0x62fde0u:f_0022fde0(m,s,child,op);break;
case 0x46ce50u:f_0006ce50(m,s,child,op);break;
default:throw std::domain_error("private_partition unresolved authentic target");}f.sp=child.sp;
}

} // anonymous namespace
Result run(Memory&world,unsigned entry,unsigned char*storage,unsigned size,const NativeState&in,const fp::Image&incoming,const Operations&op){
 need(entry>=0x8000&&size>=0x8000+68&&std::uint64_t(entry)+68<=0x100000000ull&&std::uint64_t(reinterpret_cast<std::uintptr_t>(storage))+0x8000==entry,"actual owned32KB Source frame and caller extent");
 need(op.heap_context&&op.allocate&&op.release,"nonnull actual Source ordinary-provider callbacks/context");
 leaf::Memory local(storage,entry-0x8000,size);Memory m=world;m.add(local);
 std::array<unsigned,16>before{};for(unsigned k=0;k<16;++k)before[k]=m.r32(entry+4+4*k);
 // Finite positive one-cell partition; no general constructor/seed-generator claim.
 constexpr unsigned short controls[]{0x037f,0x077f,0x0b7f,0x0f7f,0x027f,0x067f,0x0a7f,0x0e7f,0x007f,0x047f,0x087f,0x0c7f};bool cw=false;for(auto value:controls)if(incoming.word(0)==value)cw=true;
 need(cw&&incoming.word(8)==0xffff&&(incoming.word(4)&~0x3800u)==0&&!(in.flags&0x400),"finite12CW/all8TOP emptytags and DFclear");need(before[1]==1,"selected requestedcount1");
 const unsigned out=before[0],rect=before[2];auto public_range=[&](unsigned a,unsigned n){need(a&&std::uint64_t(a)+n<=0x100000000ull&&(std::uint64_t(a)+n<=entry-0x8000||std::uint64_t(a)>=std::uint64_t(entry)+68),"declared public range outside actual private frame");for(unsigned k=0;k<n;++k)(void)m.r8(a+k);};auto disjoint=[](unsigned a,unsigned n,unsigned b,unsigned z){return std::uint64_t(a)+n<=b||std::uint64_t(b)+z<=a;};
 public_range(out,24);public_range(rect,16);need(disjoint(out,24,rect,16),"separate supplied output/rectangle");const unsigned backing=m.r32(out+4),capacity=m.r32(out+8);need(capacity>=1&&capacity<=4&&m.r32(out+0x10)==0,"caller-owned sparecapacity rectangle record; no output grow");public_range(backing,capacity*16);need(disjoint(out,24,backing,capacity*16)&&disjoint(rect,16,backing,capacity*16),"disjoint callerowned rectangle backing");
 const unsigned x=m.r32(rect),y=m.r32(rect+4),w=m.r32(rect+8),h=m.r32(rect+12);need(x>=4&&x<=11&&y>=6&&y<=12&&w>=8&&w<=24&&h>=8&&h<=28&&w%4==0&&h%4==0,"finitepositive signed-safe rectangle");
 need(m.r32(0x80013c)==0&&m.r32(0x785738)==0&&m.r32(0x785728)==0&&m.r32(0x78572c)==0x3fe00000&&m.r32(0x790db0)==0x100000&&m.r32(0x790db4)==0x3df00000&&m.r32(0x7c3a04)==0x0e7f&&m.r32(0x788a9c)==0x46ce50,"authentic selected sqrtcell/zero/half/scale/cachedCW/internalgrow addresspoint");
 const unsigned rng=0xa581d8,a=m.r32(rng+4),b=m.r32(rng+8);need(m.r8(rng)==0&&a<249&&b==a+1,"borrowed coherent adjacent lagged-XOR cursors");public_range(rng,1012);need(disjoint(rng,1012,out,24)&&disjoint(rng,1012,rect,16)&&disjoint(rng,1012,backing,capacity*16),"RNG and supplied public records disjoint");const unsigned draw=m.r32(rng+12+4*a)^m.r32(rng+12+4*b);need(draw==0x40000000||draw==0x80000000,"finite actualXOR coin results, not synthetic RNG provider");
 // The output vptr is not consumed on sparecapacity; no class/addresspoint inferred.
 // Provider callbacks must implement actual successful ordinary40B allocations and full frees; tests bind the existing real provider. No result is manufactured here. 
 State state{};state.ax=in.ax;state.cx=in.cx;state.dx=in.dx;state.bx=in.bx;state.bp=in.bp;state.si=in.si;state.di=in.di;state.arithmetic_flags=in.flags;state.fp.image=incoming;
 Frame frame{entry,entry,m.r32(entry)};f_00178ed0(m,state,frame,op);
 need(frame.sp==entry+16&&state.bx==in.bx&&state.bp==in.bp&&state.si==in.si&&state.di==in.di&&!(state.arithmetic_flags&0x400),"actual RET12/nonvolDF");
 Result result{state.ax,state,{}};for(unsigned k=0;k<16;++k){result.words[k]=m.r32(entry+4+4*k);need(result.words[k]==before[k],"actual all16 unchanged caller poststate");}return result;
}
}
