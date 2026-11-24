#include "recovered/recovery_b212_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b212 {
namespace {
void f_0002de20(Memory&,State&,Frame&,const Operations&);
void f_00229ca0(Memory&,State&,Frame&,const Operations&);
void f_00229220(Memory&,State&,Frame&,const Operations&);
void f_0001fdf0(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void f_000112c0(Memory&,State&,Frame&,const Operations&);
void f_000112d0(Memory&,State&,Frame&,const Operations&);
void f_000e4ba0(Memory&,State&,Frame&,const Operations&);
void f_000e4be0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_0002de20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0042de20: { // 0x42de20: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  L0042de25: { // 0x42de25: 83ec38 SUB ESP,0x38
    f.sp = integer::sub(f.sp,0x00000038u,32,flags);
  }
  L0042de28: { // 0x42de28: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0042de29: { // 0x42de29: f73d946c8300 IDIV dword ptr [0x00836c94]
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(m.r32((0x00836c94u)),32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L0042de2f: { // 0x42de2f: a1906c8300 MOV EAX,[0x00836c90]
    s.ax = m.r32((0x00836c90u));
  }
  L0042de34: { // 0x42de34: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0042de35: { // 0x42de35: 8a5c2454 MOV BL,byte ptr [ESP + 0x54]
    s.bx = with_al(s.bx, m.r8((f.sp+0x00000054u)));
  }
  L0042de39: { // 0x42de39: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0042de3a: { // 0x42de3a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0042de3b: { // 0x42de3b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0042de3c: { // 0x42de3c: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0042de3d: { // 0x42de3d: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L0042de3f: { // 0x42de3f: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L0042de41: { // 0x42de41: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L0042de43: { // 0x42de43: 7c08 JL 0x0042de4d
    if(integer::condition("JL",flags)) goto L0042de4d;
  }
  L0042de45: { // 0x42de45: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L0042de47: { // 0x42de47: 0f8428020000 JZ 0x0042e075
    if(integer::condition("JZ",flags)) goto L0042e075;
  }
  L0042de4d: { // 0x42de4d: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0042de4f: { // 0x42de4f: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L0042de53: { // 0x42de53: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0042de54: { // 0x42de54: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0042de55: { // 0x42de55: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0042de5a: { // 0x42de5a: e8c1b31f00 CALL 0x00629220
    s.arithmetic_flags=flags; invoke(m,s,f,0x00629220u,4382303u); flags=s.arithmetic_flags;
  }
  L0042de5f: { // 0x42de5f: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0042de61: { // 0x42de61: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L0042de65: { // 0x42de65: 8b7004 MOV ESI,dword ptr [EAX + 0x4]
    s.si = m.r32((s.ax+0x00000004u));
  }
  L0042de68: { // 0x42de68: a1906c8300 MOV EAX,[0x00836c90]
    s.ax = m.r32((0x00836c90u));
  }
  L0042de6d: { // 0x42de6d: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L0042de6f: { // 0x42de6f: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L0042de73: { // 0x42de73: 7d61 JGE 0x0042ded6
    if(integer::condition("JGE",flags)) goto L0042ded6;
  }
  L0042de75: { // 0x42de75: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L0042de77: { // 0x42de77: 755d JNZ 0x0042ded6
    if(integer::condition("JNZ",flags)) goto L0042ded6;
  }
  L0042de79: { // 0x42de79: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0042de7b: { // 0x42de7b: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0042de7d: { // 0x42de7d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0042de7e: { // 0x42de7e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0042de7f: { // 0x42de7f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0042de80: { // 0x42de80: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0042de81: { // 0x42de81: 68e8030000 PUSH 0x3e8
    f.push(m,0x000003e8u);
  }
  L0042de86: { // 0x42de86: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0042de87: { // 0x42de87: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0042de88: { // 0x42de88: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0042de89: { // 0x42de89: 8b0dd86c8300 MOV ECX,dword ptr [0x00836cd8]
    s.cx = m.r32((0x00836cd8u));
  }
  L0042de8f: { // 0x42de8f: 8d542470 LEA EDX,[ESP + 0x70]
    s.dx = (f.sp+0x00000070u);
  }
  L0042de93: { // 0x42de93: 6800060000 PUSH 0x600
    f.push(m,0x00000600u);
  }
  L0042de98: { // 0x42de98: 8d442434 LEA EAX,[ESP + 0x34]
    s.ax = (f.sp+0x00000034u);
  }
  L0042de9c: { // 0x42de9c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0042de9d: { // 0x42de9d: 8b9510010000 MOV EDX,dword ptr [EBP + 0x110]
    s.dx = m.r32((s.bp+0x00000110u));
  }
  L0042dea3: { // 0x42dea3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0042dea4: { // 0x42dea4: a1cca5a100 MOV EAX,[0x00a1a5cc]
    s.ax = m.r32((0x00a1a5ccu));
  }
  L0042dea9: { // 0x42dea9: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0042deaa: { // 0x42deaa: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0042deab: { // 0x42deab: 8b0c90 MOV ECX,dword ptr [EAX + EDX*0x4]
    s.cx = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L0042deae: { // 0x42deae: a104eaa900 MOV EAX,[0x00a9ea04]
    s.ax = m.r32((0x00a9ea04u));
  }
  L0042deb3: { // 0x42deb3: 8b91405f0100 MOV EDX,dword ptr [ECX + 0x15f40]
    s.dx = m.r32((s.cx+0x00015f40u));
  }
  L0042deb9: { // 0x42deb9: 8b0c90 MOV ECX,dword ptr [EAX + EDX*0x4]
    s.cx = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L0042debc: { // 0x42debc: 8b910c030000 MOV EDX,dword ptr [ECX + 0x30c]
    s.dx = m.r32((s.cx+0x0000030cu));
  }
  L0042dec2: { // 0x42dec2: 8b8c2480000000 MOV ECX,dword ptr [ESP + 0x80]
    s.cx = m.r32((f.sp+0x00000080u));
  }
  L0042dec9: { // 0x42dec9: e8020d0700 CALL 0x0049ebd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0049ebd0u,4382414u); flags=s.arithmetic_flags;
  }
  L0042dece: { // 0x42dece: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L0042ded2: { // 0x42ded2: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L0042ded6: { // 0x42ded6: 8b2d886c8300 MOV EBP,dword ptr [0x00836c88]
    s.bp = m.r32((0x00836c88u));
  }
  L0042dedc: { // 0x42dedc: 8b3d8c6c8300 MOV EDI,dword ptr [0x00836c8c]
    s.di = m.r32((0x00836c8cu));
  }
  L0042dee2: { // 0x42dee2: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L0042dee4: { // 0x42dee4: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0042dee5: { // 0x42dee5: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0042dee7: { // 0x42dee7: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0042dee9: { // 0x42dee9: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L0042deeb: { // 0x42deeb: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0042deed: { // 0x42deed: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0042deee: { // 0x42deee: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0042def0: { // 0x42def0: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0042def2: { // 0x42def2: 8b0dbcbc8100 MOV ECX,dword ptr [0x0081bcbc]
    s.cx = m.r32((0x0081bcbcu));
  }
  L0042def8: { // 0x42def8: 895c2438 MOV dword ptr [ESP + 0x38],EBX
    m.w32((f.sp+0x00000038u), s.bx);
  }
  L0042defc: { // 0x42defc: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0042defe: { // 0x42defe: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  L0042df00: { // 0x42df00: a1b8bc8100 MOV EAX,[0x0081bcb8]
    s.ax = m.r32((0x0081bcb8u));
  }
  L0042df05: { // 0x42df05: 03c3 ADD EAX,EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L0042df07: { // 0x42df07: 8b1d30ba8100 MOV EBX,dword ptr [0x0081ba30]
    s.bx = m.r32((0x0081ba30u));
  }
  L0042df0d: { // 0x42df0d: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L0042df0f: { // 0x42df0f: 8974243c MOV dword ptr [ESP + 0x3c],ESI
    m.w32((f.sp+0x0000003cu), s.si);
  }
  L0042df13: { // 0x42df13: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L0042df15: { // 0x42df15: 0f8ecd000000 JLE 0x0042dfe8
    if(integer::condition("JLE",flags)) goto L0042dfe8;
  }
  L0042df1b: { // 0x42df1b: 8b1534ba8100 MOV EDX,dword ptr [0x0081ba34]
    s.dx = m.r32((0x0081ba34u));
  }
  L0042df21: { // 0x42df21: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0042df23: { // 0x42df23: 0f8ebf000000 JLE 0x0042dfe8
    if(integer::condition("JLE",flags)) goto L0042dfe8;
  }
  L0042df29: { // 0x42df29: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0042df2b: { // 0x42df2b: 0f8e9a000000 JLE 0x0042dfcb
    if(integer::condition("JLE",flags)) goto L0042dfcb;
  }
  L0042df31: { // 0x42df31: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0042df33: { // 0x42df33: 0f8e92000000 JLE 0x0042dfcb
    if(integer::condition("JLE",flags)) goto L0042dfcb;
  }
  L0042df39: { // 0x42df39: 8b1528ba8100 MOV EDX,dword ptr [0x0081ba28]
    s.dx = m.r32((0x0081ba28u));
  }
  L0042df3f: { // 0x42df3f: 8b352cba8100 MOV ESI,dword ptr [0x0081ba2c]
    s.si = m.r32((0x0081ba2cu));
  }
  L0042df45: { // 0x42df45: 895c2420 MOV dword ptr [ESP + 0x20],EBX
    m.w32((f.sp+0x00000020u), s.bx);
  }
  L0042df49: { // 0x42df49: 8b1d34ba8100 MOV EBX,dword ptr [0x0081ba34]
    s.bx = m.r32((0x0081ba34u));
  }
  L0042df4f: { // 0x42df4f: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L0042df51: { // 0x42df51: 8974241c MOV dword ptr [ESP + 0x1c],ESI
    m.w32((f.sp+0x0000001cu), s.si);
  }
  L0042df55: { // 0x42df55: 895c2424 MOV dword ptr [ESP + 0x24],EBX
    m.w32((f.sp+0x00000024u), s.bx);
  }
  L0042df59: { // 0x42df59: 7e0e JLE 0x0042df69
    if(integer::condition("JLE",flags)) goto L0042df69;
  }
  L0042df5b: { // 0x42df5b: 8b5c2420 MOV EBX,dword ptr [ESP + 0x20]
    s.bx = m.r32((f.sp+0x00000020u));
  }
  L0042df5f: { // 0x42df5f: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L0042df61: { // 0x42df61: 03da ADD EBX,EDX
    s.bx = integer::add(s.bx,s.dx,32,flags);
  }
  L0042df63: { // 0x42df63: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0042df65: { // 0x42df65: 895c2420 MOV dword ptr [ESP + 0x20],EBX
    m.w32((f.sp+0x00000020u), s.bx);
  }
  L0042df69: { // 0x42df69: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L0042df6b: { // 0x42df6b: 7e10 JLE 0x0042df7d
    if(integer::condition("JLE",flags)) goto L0042df7d;
  }
  L0042df6d: { // 0x42df6d: 8b5c2424 MOV EBX,dword ptr [ESP + 0x24]
    s.bx = m.r32((f.sp+0x00000024u));
  }
  L0042df71: { // 0x42df71: 2bf1 SUB ESI,ECX
    s.si = integer::sub(s.si,s.cx,32,flags);
  }
  L0042df73: { // 0x42df73: 03de ADD EBX,ESI
    s.bx = integer::add(s.bx,s.si,32,flags);
  }
  L0042df75: { // 0x42df75: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L0042df79: { // 0x42df79: 895c2424 MOV dword ptr [ESP + 0x24],EBX
    m.w32((f.sp+0x00000024u), s.bx);
  }
  L0042df7d: { // 0x42df7d: 8b742420 MOV ESI,dword ptr [ESP + 0x20]
    s.si = m.r32((f.sp+0x00000020u));
  }
  L0042df81: { // 0x42df81: 8d1c28 LEA EBX,[EAX + EBP*0x1]
    s.bx = (s.ax+(s.bp * 0x00000001u));
  }
  L0042df84: { // 0x42df84: 03f2 ADD ESI,EDX
    s.si = integer::add(s.si,s.dx,32,flags);
  }
  L0042df86: { // 0x42df86: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L0042df88: { // 0x42df88: 7d0a JGE 0x0042df94
    if(integer::condition("JGE",flags)) goto L0042df94;
  }
  L0042df8a: { // 0x42df8a: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0042df8c: { // 0x42df8c: 8d442801 LEA EAX,[EAX + EBP*0x1 + 0x1]
    s.ax = (s.ax+(s.bp * 0x00000001u)+0x00000001u);
  }
  L0042df90: { // 0x42df90: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L0042df94: { // 0x42df94: 8b742424 MOV ESI,dword ptr [ESP + 0x24]
    s.si = m.r32((f.sp+0x00000024u));
  }
  L0042df98: { // 0x42df98: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L0042df9c: { // 0x42df9c: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L0042df9e: { // 0x42df9e: 8d1c39 LEA EBX,[ECX + EDI*0x1]
    s.bx = (s.cx+(s.di * 0x00000001u));
  }
  L0042dfa1: { // 0x42dfa1: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0042dfa3: { // 0x42dfa3: 7d08 JGE 0x0042dfad
    if(integer::condition("JGE",flags)) goto L0042dfad;
  }
  L0042dfa5: { // 0x42dfa5: 2b4c241c SUB ECX,dword ptr [ESP + 0x1c]
    s.cx = integer::sub(s.cx,m.r32((f.sp+0x0000001cu)),32,flags);
  }
  L0042dfa9: { // 0x42dfa9: 8d743901 LEA ESI,[ECX + EDI*0x1 + 0x1]
    s.si = (s.cx+(s.di * 0x00000001u)+0x00000001u);
  }
  L0042dfad: { // 0x42dfad: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0042dfb1: { // 0x42dfb1: 89542428 MOV dword ptr [ESP + 0x28],EDX
    m.w32((f.sp+0x00000028u), s.dx);
  }
  L0042dfb5: { // 0x42dfb5: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L0042dfb9: { // 0x42dfb9: 89742434 MOV dword ptr [ESP + 0x34],ESI
    m.w32((f.sp+0x00000034u), s.si);
  }
  L0042dfbd: { // 0x42dfbd: 8b74243c MOV ESI,dword ptr [ESP + 0x3c]
    s.si = m.r32((f.sp+0x0000003cu));
  }
  L0042dfc1: { // 0x42dfc1: 894c242c MOV dword ptr [ESP + 0x2c],ECX
    m.w32((f.sp+0x0000002cu), s.cx);
  }
  L0042dfc5: { // 0x42dfc5: 89542430 MOV dword ptr [ESP + 0x30],EDX
    m.w32((f.sp+0x00000030u), s.dx);
  }
  L0042dfc9: { // 0x42dfc9: eb2d JMP 0x0042dff8
    goto L0042dff8;
  }
  L0042dfcb: { // 0x42dfcb: a128ba8100 MOV EAX,[0x0081ba28]
    s.ax = m.r32((0x0081ba28u));
  }
  L0042dfd0: { // 0x42dfd0: 8b0d2cba8100 MOV ECX,dword ptr [0x0081ba2c]
    s.cx = m.r32((0x0081ba2cu));
  }
  L0042dfd6: { // 0x42dfd6: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L0042dfda: { // 0x42dfda: 894c242c MOV dword ptr [ESP + 0x2c],ECX
    m.w32((f.sp+0x0000002cu), s.cx);
  }
  L0042dfde: { // 0x42dfde: 895c2430 MOV dword ptr [ESP + 0x30],EBX
    m.w32((f.sp+0x00000030u), s.bx);
  }
  L0042dfe2: { // 0x42dfe2: 89542434 MOV dword ptr [ESP + 0x34],EDX
    m.w32((f.sp+0x00000034u), s.dx);
  }
  L0042dfe6: { // 0x42dfe6: eb10 JMP 0x0042dff8
    goto L0042dff8;
  }
  L0042dfe8: { // 0x42dfe8: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L0042dfec: { // 0x42dfec: 894c242c MOV dword ptr [ESP + 0x2c],ECX
    m.w32((f.sp+0x0000002cu), s.cx);
  }
  L0042dff0: { // 0x42dff0: 896c2430 MOV dword ptr [ESP + 0x30],EBP
    m.w32((f.sp+0x00000030u), s.bp);
  }
  L0042dff4: { // 0x42dff4: 897c2434 MOV dword ptr [ESP + 0x34],EDI
    m.w32((f.sp+0x00000034u), s.di);
  }
  L0042dff8: { // 0x42dff8: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0042dffa: { // 0x42dffa: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0042dffc: { // 0x42dffc: 68b8bc8100 PUSH 0x81bcb8
    f.push(m,0x0081bcb8u);
  }
  L0042e001: { // 0x42e001: 8d542434 LEA EDX,[ESP + 0x34]
    s.dx = (f.sp+0x00000034u);
  }
  L0042e005: { // 0x42e005: 8d4c2424 LEA ECX,[ESP + 0x24]
    s.cx = (f.sp+0x00000024u);
  }
  L0042e009: { // 0x42e009: e8e21dffff CALL 0x0041fdf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041fdf0u,4382734u); flags=s.arithmetic_flags;
  }
  L0042e00e: { // 0x42e00e: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0042e010: { // 0x42e010: 8bde MOV EBX,ESI
    s.bx = s.si;
  }
  L0042e012: { // 0x42e012: 891528ba8100 MOV dword ptr [0x0081ba28],EDX
    m.w32((0x0081ba28u), s.dx);
  }
  L0042e018: { // 0x42e018: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L0042e01b: { // 0x42e01b: 890d2cba8100 MOV dword ptr [0x0081ba2c],ECX
    m.w32((0x0081ba2cu), s.cx);
  }
  L0042e021: { // 0x42e021: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L0042e024: { // 0x42e024: 891530ba8100 MOV dword ptr [0x0081ba30],EDX
    m.w32((0x0081ba30u), s.dx);
  }
  L0042e02a: { // 0x42e02a: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L0042e02d: { // 0x42e02d: a334ba8100 MOV [0x0081ba34],EAX
    m.w32((0x0081ba34u), s.ax);
  }
  L0042e032: { // 0x42e032: 8d043e LEA EAX,[ESI + EDI*0x1]
    s.ax = (s.si+(s.di * 0x00000001u));
  }
  L0042e035: { // 0x42e035: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L0042e037: { // 0x42e037: 89442460 MOV dword ptr [ESP + 0x60],EAX
    m.w32((f.sp+0x00000060u), s.ax);
  }
  L0042e03b: { // 0x42e03b: 7d38 JGE 0x0042e075
    if(integer::condition("JGE",flags)) goto L0042e075;
  }
  L0042e03d: { // 0x42e03d: 8b742438 MOV ESI,dword ptr [ESP + 0x38]
    s.si = m.r32((f.sp+0x00000038u));
  }
  L0042e041: { // 0x42e041: 8d3c2e LEA EDI,[ESI + EBP*0x1]
    s.di = (s.si+(s.bp * 0x00000001u));
  }
  L0042e044: { // 0x42e044: 897c244c MOV dword ptr [ESP + 0x4c],EDI
    m.w32((f.sp+0x0000004cu), s.di);
  }
  L0042e048: { // 0x42e048: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  L0042e04a: { // 0x42e04a: 7d24 JGE 0x0042e070
    if(integer::condition("JGE",flags)) goto L0042e070;
  }
  L0042e04c: { // 0x42e04c: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0042e050: { // 0x42e050: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L0042e054: { // 0x42e054: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0042e055: { // 0x42e055: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0042e05a: { // 0x42e05a: 895c2420 MOV dword ptr [ESP + 0x20],EBX
    m.w32((f.sp+0x00000020u), s.bx);
  }
  L0042e05e: { // 0x42e05e: e83dbc1f00 CALL 0x00629ca0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00629ca0u,4382819u); flags=s.arithmetic_flags;
  }
  L0042e063: { // 0x42e063: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0042e064: { // 0x42e064: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  L0042e066: { // 0x42e066: 7ce4 JL 0x0042e04c
    if(integer::condition("JL",flags)) goto L0042e04c;
  }
  L0042e068: { // 0x42e068: 8b742438 MOV ESI,dword ptr [ESP + 0x38]
    s.si = m.r32((f.sp+0x00000038u));
  }
  L0042e06c: { // 0x42e06c: 8b442460 MOV EAX,dword ptr [ESP + 0x60]
    s.ax = m.r32((f.sp+0x00000060u));
  }
  L0042e070: { // 0x42e070: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L0042e071: { // 0x42e071: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L0042e073: { // 0x42e073: 7cd3 JL 0x0042e048
    if(integer::condition("JL",flags)) goto L0042e048;
  }
  L0042e075: { // 0x42e075: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0042e076: { // 0x42e076: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0042e077: { // 0x42e077: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0042e078: { // 0x42e078: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0042e079: { // 0x42e079: 83c438 ADD ESP,0x38
    f.sp = integer::add(f.sp,0x00000038u,32,flags);
  }
  L0042e07c: { // 0x42e07c: c21800 RET 0x18
    s.arithmetic_flags=flags; finish(m,s,f,24u); return;
  }
}
void f_00229ca0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00629ca0: { // 0x629ca0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00629ca1: { // 0x629ca1: 8b5c2408 MOV EBX,dword ptr [ESP + 0x8]
    s.bx = m.r32((f.sp+0x00000008u));
  }
  L00629ca5: { // 0x629ca5: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00629ca6: { // 0x629ca6: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L00629ca8: { // 0x629ca8: 833b00 CMP dword ptr [EBX],0x0
    (void)integer::sub(m.r32((s.bx)),0x00000000u,32,flags);
  }
  L00629cab: { // 0x629cab: 0f8cbc000000 JL 0x00629d6d
    if(integer::condition("JL",flags)) goto L00629d6d;
  }
  L00629cb1: { // 0x629cb1: 8b8f18120000 MOV ECX,dword ptr [EDI + 0x1218]
    s.cx = m.r32((s.di+0x00001218u));
  }
  L00629cb7: { // 0x629cb7: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00629cb9: { // 0x629cb9: ff507c CALL dword ptr [EAX + 0x7c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000007cu)),6462652u); flags=s.arithmetic_flags;
  }
  L00629cbc: { // 0x629cbc: 3903 CMP dword ptr [EBX],EAX
    (void)integer::sub(m.r32((s.bx)),s.ax,32,flags);
  }
  L00629cbe: { // 0x629cbe: 0f8da9000000 JGE 0x00629d6d
    if(integer::condition("JGE",flags)) goto L00629d6d;
  }
  L00629cc4: { // 0x629cc4: 8b4304 MOV EAX,dword ptr [EBX + 0x4]
    s.ax = m.r32((s.bx+0x00000004u));
  }
  L00629cc7: { // 0x629cc7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00629cc9: { // 0x629cc9: 0f8c9e000000 JL 0x00629d6d
    if(integer::condition("JL",flags)) goto L00629d6d;
  }
  L00629ccf: { // 0x629ccf: 8b8f18120000 MOV ECX,dword ptr [EDI + 0x1218]
    s.cx = m.r32((s.di+0x00001218u));
  }
  L00629cd5: { // 0x629cd5: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00629cd7: { // 0x629cd7: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),6462685u); flags=s.arithmetic_flags;
  }
  L00629cdd: { // 0x629cdd: 394304 CMP dword ptr [EBX + 0x4],EAX
    (void)integer::sub(m.r32((s.bx+0x00000004u)),s.ax,32,flags);
  }
  L00629ce0: { // 0x629ce0: 0f8d87000000 JGE 0x00629d6d
    if(integer::condition("JGE",flags)) goto L00629d6d;
  }
  L00629ce6: { // 0x629ce6: 8b8f18120000 MOV ECX,dword ptr [EDI + 0x1218]
    s.cx = m.r32((s.di+0x00001218u));
  }
  L00629cec: { // 0x629cec: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00629cee: { // 0x629cee: ff507c CALL dword ptr [EAX + 0x7c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000007cu)),6462705u); flags=s.arithmetic_flags;
  }
  L00629cf1: { // 0x629cf1: 0faf4304 IMUL EAX,dword ptr [EBX + 0x4]
    s.ax = integer::imul(s.ax,m.r32((s.bx+0x00000004u)),32,flags);
  }
  L00629cf5: { // 0x629cf5: 0303 ADD EAX,dword ptr [EBX]
    s.ax = integer::add(s.ax,m.r32((s.bx)),32,flags);
  }
  L00629cf7: { // 0x629cf7: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00629cf9: { // 0x629cf9: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00629cfb: { // 0x629cfb: 83e107 AND ECX,0x7
    s.cx = integer::logical((s.cx)&(0x00000007u),32,flags);
  }
  L00629cfe: { // 0x629cfe: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L00629d03: { // 0x629d03: d3e0 SHL EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L00629d05: { // 0x629d05: 8b8f70120000 MOV ECX,dword ptr [EDI + 0x1270]
    s.cx = m.r32((s.di+0x00001270u));
  }
  L00629d0b: { // 0x629d0b: c1fa03 SAR EDX,0x3
    s.dx = integer::shift(s.dx,0x00000003u,32,flags,integer::Shift::arithmetic_right);
  }
  L00629d0e: { // 0x629d0e: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L00629d10: { // 0x629d10: 8a0a MOV CL,byte ptr [EDX]
    s.cx = with_al(s.cx, m.r8((s.dx)));
  }
  L00629d12: { // 0x629d12: 84c8 TEST AL,CL
    (void)integer::logical(((s.ax & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00629d14: { // 0x629d14: 7557 JNZ 0x00629d6d
    if(integer::condition("JNZ",flags)) goto L00629d6d;
  }
  L00629d16: { // 0x629d16: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00629d17: { // 0x629d17: 0ac8 OR CL,AL
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))|((s.ax & 0xffu)),8,flags));
  }
  L00629d19: { // 0x629d19: 8db758120000 LEA ESI,[EDI + 0x1258]
    s.si = (s.di+0x00001258u);
  }
  L00629d1f: { // 0x629d1f: 880a MOV byte ptr [EDX],CL
    m.w8((s.dx), (s.cx & 0xffu));
  }
  L00629d21: { // 0x629d21: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L00629d24: { // 0x629d24: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    s.cx = m.r32((s.si+0x00000010u));
  }
  L00629d27: { // 0x629d27: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00629d29: { // 0x629d29: 7c22 JL 0x00629d4d
    if(integer::condition("JL",flags)) goto L00629d4d;
  }
  L00629d2b: { // 0x629d2b: 8a4e0d MOV CL,byte ptr [ESI + 0xd]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000000du)));
  }
  L00629d2e: { // 0x629d2e: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00629d30: { // 0x629d30: 7504 JNZ 0x00629d36
    if(integer::condition("JNZ",flags)) goto L00629d36;
  }
  L00629d32: { // 0x629d32: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00629d34: { // 0x629d34: 752f JNZ 0x00629d65
    if(integer::condition("JNZ",flags)) goto L00629d65;
  }
  L00629d36: { // 0x629d36: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx = m.r32((s.si+0x00000014u));
  }
  L00629d39: { // 0x629d39: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00629d3b: { // 0x629d3b: 7e28 JLE 0x00629d65
    if(integer::condition("JLE",flags)) goto L00629d65;
  }
  L00629d3d: { // 0x629d3d: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00629d3f: { // 0x629d3f: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00629d41: { // 0x629d41: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00629d43: { // 0x629d43: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00629d44: { // 0x629d44: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00629d46: { // 0x629d46: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),6462793u); flags=s.arithmetic_flags;
  }
  L00629d49: { // 0x629d49: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00629d4b: { // 0x629d4b: 7418 JZ 0x00629d65
    if(integer::condition("JZ",flags)) goto L00629d65;
  }
  L00629d4d: { // 0x629d4d: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L00629d50: { // 0x629d50: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  L00629d53: { // 0x629d53: 8d4801 LEA ECX,[EAX + 0x1]
    s.cx = (s.ax+0x00000001u);
  }
  L00629d56: { // 0x629d56: 894e10 MOV dword ptr [ESI + 0x10],ECX
    m.w32((s.si+0x00000010u), s.cx);
  }
  L00629d59: { // 0x629d59: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  L00629d5b: { // 0x629d5b: 890cc2 MOV dword ptr [EDX + EAX*0x8],ECX
    m.w32((s.dx+(s.ax * 0x00000008u)), s.cx);
  }
  L00629d5e: { // 0x629d5e: 8b4b04 MOV ECX,dword ptr [EBX + 0x4]
    s.cx = m.r32((s.bx+0x00000004u));
  }
  L00629d61: { // 0x629d61: 894cc204 MOV dword ptr [EDX + EAX*0x8 + 0x4],ECX
    m.w32((s.dx+(s.ax * 0x00000008u)+0x00000004u), s.cx);
  }
  L00629d65: { // 0x629d65: c687d514000001 MOV byte ptr [EDI + 0x14d5],0x1
    m.w8((s.di+0x000014d5u), 0x00000001u);
  }
  L00629d6c: { // 0x629d6c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00629d6d: { // 0x629d6d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00629d6e: { // 0x629d6e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00629d6f: { // 0x629d6f: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00229220(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00629220: { // 0x629220: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L00629224: { // 0x629224: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00629225: { // 0x629225: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00629226: { // 0x629226: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00629227: { // 0x629227: 8b18 MOV EBX,dword ptr [EAX]
    s.bx = m.r32((s.ax));
  }
  L00629229: { // 0x629229: 8b7004 MOV ESI,dword ptr [EAX + 0x4]
    s.si = m.r32((s.ax+0x00000004u));
  }
  L0062922c: { // 0x62922c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0062922d: { // 0x62922d: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0062922f: { // 0x62922f: 8b878c140000 MOV EAX,dword ptr [EDI + 0x148c]
    s.ax = m.r32((s.di+0x0000148cu));
  }
  L00629235: { // 0x629235: c1e008 SHL EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::left);
  }
  L00629238: { // 0x629238: 2bc6 SUB EAX,ESI
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L0062923a: { // 0x62923a: 03c3 ADD EAX,EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L0062923c: { // 0x62923c: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00629240: { // 0x629240: db442418 FILD dword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load_integer32(m.r32(address));
  }
  L00629244: { // 0x629244: d88f84140000 FMUL float ptr [EDI + 0x1484]
    const auto address=(s.di+0x00001484u);
    s.fp.multiply32(m.r32(address));
  }
  L0062924a: { // 0x62924a: d80dbc377900 FMUL float ptr [0x007937bc]
    const auto address=(0x007937bcu);
    s.fp.multiply32(m.r32(address));
  }
  L00629250: { // 0x629250: e8fb171400 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6459989u); flags=s.arithmetic_flags;
  }
  L00629255: { // 0x629255: 8b8f94140000 MOV ECX,dword ptr [EDI + 0x1494]
    s.cx = m.r32((s.di+0x00001494u));
  }
  L0062925b: { // 0x62925b: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L0062925d: { // 0x62925d: c1e108 SHL ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::left);
  }
  L00629260: { // 0x629260: 2bf1 SUB ESI,ECX
    s.si = integer::sub(s.si,s.cx,32,flags);
  }
  L00629262: { // 0x629262: 03f3 ADD ESI,EBX
    s.si = integer::add(s.si,s.bx,32,flags);
  }
  L00629264: { // 0x629264: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L00629268: { // 0x629268: db442418 FILD dword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load_integer32(m.r32(address));
  }
  L0062926c: { // 0x62926c: d88f84140000 FMUL float ptr [EDI + 0x1484]
    const auto address=(s.di+0x00001484u);
    s.fp.multiply32(m.r32(address));
  }
  L00629272: { // 0x629272: d80dbc377900 FMUL float ptr [0x007937bc]
    const auto address=(0x007937bcu);
    s.fp.multiply32(m.r32(address));
  }
  L00629278: { // 0x629278: e8d3171400 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6460029u); flags=s.arithmetic_flags;
  }
  L0062927d: { // 0x62927d: 8a4c241c MOV CL,byte ptr [ESP + 0x1c]
    s.cx = with_al(s.cx, m.r8((f.sp+0x0000001cu)));
  }
  L00629281: { // 0x629281: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00629283: { // 0x629283: 7426 JZ 0x006292ab
    if(integer::condition("JZ",flags)) goto L006292ab;
  }
  L00629285: { // 0x629285: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L00629287: { // 0x629287: 7d02 JGE 0x0062928b
    if(integer::condition("JGE",flags)) goto L0062928b;
  }
  L00629289: { // 0x629289: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L0062928b: { // 0x62928b: 8b8fa0140000 MOV ECX,dword ptr [EDI + 0x14a0]
    s.cx = m.r32((s.di+0x000014a0u));
  }
  L00629291: { // 0x629291: 3be9 CMP EBP,ECX
    (void)integer::sub(s.bp,s.cx,32,flags);
  }
  L00629293: { // 0x629293: 7c03 JL 0x00629298
    if(integer::condition("JL",flags)) goto L00629298;
  }
  L00629295: { // 0x629295: 8d69ff LEA EBP,[ECX + -0x1]
    s.bp = (s.cx-0x00000001u);
  }
  L00629298: { // 0x629298: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0062929a: { // 0x62929a: 7d02 JGE 0x0062929e
    if(integer::condition("JGE",flags)) goto L0062929e;
  }
  L0062929c: { // 0x62929c: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0062929e: { // 0x62929e: 8bbfa4140000 MOV EDI,dword ptr [EDI + 0x14a4]
    s.di = m.r32((s.di+0x000014a4u));
  }
  L006292a4: { // 0x6292a4: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L006292a6: { // 0x6292a6: 7c03 JL 0x006292ab
    if(integer::condition("JL",flags)) goto L006292ab;
  }
  L006292a8: { // 0x6292a8: 8d47ff LEA EAX,[EDI + -0x1]
    s.ax = (s.di-0x00000001u);
  }
  L006292ab: { // 0x6292ab: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L006292af: { // 0x6292af: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006292b0: { // 0x6292b0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006292b1: { // 0x6292b1: 8929 MOV dword ptr [ECX],EBP
    m.w32((s.cx), s.bp);
  }
  L006292b3: { // 0x6292b3: 894104 MOV dword ptr [ECX + 0x4],EAX
    m.w32((s.cx+0x00000004u), s.ax);
  }
  L006292b6: { // 0x6292b6: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006292b7: { // 0x6292b7: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L006292b9: { // 0x6292b9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006292ba: { // 0x6292ba: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
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
void f_000112c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004112c0: { // 0x4112c0: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L004112c3: { // 0x4112c3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000112d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004112d0: { // 0x4112d0: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L004112d3: { // 0x4112d3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000e4ba0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004e4ba0: { // 0x4e4ba0: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004e4ba2: { // 0x4e4ba2: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L004e4ba6: { // 0x4e4ba6: 3b4830 CMP ECX,dword ptr [EAX + 0x30]
    (void)integer::sub(s.cx,m.r32((s.ax+0x00000030u)),32,flags);
  }
  L004e4ba9: { // 0x4e4ba9: 7505 JNZ 0x004e4bb0
    if(integer::condition("JNZ",flags)) goto L004e4bb0;
  }
  L004e4bab: { // 0x4e4bab: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L004e4bad: { // 0x4e4bad: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004e4bb0: { // 0x4e4bb0: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  L004e4bb3: { // 0x4e4bb3: 7418 JZ 0x004e4bcd
    if(integer::condition("JZ",flags)) goto L004e4bcd;
  }
  L004e4bb5: { // 0x4e4bb5: 8b8074560000 MOV EAX,dword ptr [EAX + 0x5674]
    s.ax = m.r32((s.ax+0x00005674u));
  }
  L004e4bbb: { // 0x4e4bbb: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L004e4bc0: { // 0x4e4bc0: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L004e4bc2: { // 0x4e4bc2: 23c2 AND EAX,EDX
    s.ax = integer::logical((s.ax)&(s.dx),32,flags);
  }
  L004e4bc4: { // 0x4e4bc4: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L004e4bc6: { // 0x4e4bc6: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  L004e4bc8: { // 0x4e4bc8: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L004e4bca: { // 0x4e4bca: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004e4bcd: { // 0x4e4bcd: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004e4bcf: { // 0x4e4bcf: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000e4be0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004e4be0: { // 0x4e4be0: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004e4be2: { // 0x4e4be2: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L004e4be6: { // 0x4e4be6: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004e4be8: { // 0x4e4be8: 7430 JZ 0x004e4c1a
    if(integer::condition("JZ",flags)) goto L004e4c1a;
  }
  L004e4bea: { // 0x4e4bea: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L004e4bec: { // 0x4e4bec: 7505 JNZ 0x004e4bf3
    if(integer::condition("JNZ",flags)) goto L004e4bf3;
  }
  L004e4bee: { // 0x4e4bee: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L004e4bf0: { // 0x4e4bf0: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004e4bf3: { // 0x4e4bf3: 8b4930 MOV ECX,dword ptr [ECX + 0x30]
    s.cx = m.r32((s.cx+0x00000030u));
  }
  L004e4bf6: { // 0x4e4bf6: 8b5030 MOV EDX,dword ptr [EAX + 0x30]
    s.dx = m.r32((s.ax+0x00000030u));
  }
  L004e4bf9: { // 0x4e4bf9: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L004e4bfb: { // 0x4e4bfb: 7505 JNZ 0x004e4c02
    if(integer::condition("JNZ",flags)) goto L004e4c02;
  }
  L004e4bfd: { // 0x4e4bfd: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L004e4bff: { // 0x4e4bff: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004e4c02: { // 0x4e4c02: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  L004e4c05: { // 0x4e4c05: 7413 JZ 0x004e4c1a
    if(integer::condition("JZ",flags)) goto L004e4c1a;
  }
  L004e4c07: { // 0x4e4c07: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L004e4c0c: { // 0x4e4c0c: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L004e4c0e: { // 0x4e4c0e: 859074560000 TEST dword ptr [EAX + 0x5674],EDX
    (void)integer::logical((m.r32((s.ax+0x00005674u)))&(s.dx),32,flags);
  }
  L004e4c14: { // 0x4e4c14: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  L004e4c17: { // 0x4e4c17: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004e4c1a: { // 0x4e4c1a: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004e4c1c: { // 0x4e4c1c: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4382240u:f_0002de20(m,s,child,{});break;
case 6462624u:f_00229ca0(m,s,child,{});break;
case 6459936u:f_00229220(m,s,child,{});break;
case 4324848u:f_0001fdf0(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
case 4264640u:f_000112c0(m,s,child,{});break;
case 4264656u:f_000112d0(m,s,child,{});break;
case 5131168u:f_000e4ba0(m,s,child,{});break;
case 5131232u:f_000e4be0(m,s,child,{});break;
default:throw std::domain_error("recovery212 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0042ee00(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0042ee00: { // 0x42ee00: 8b4160 MOV EAX,dword ptr [ECX + 0x60]
    s.ax = m.r32((s.cx+0x00000060u));
  }
  L0042ee03: { // 0x42ee03: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0042ee06: { // 0x42ee06: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0042ee08: { // 0x42ee08: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0042ee09: { // 0x42ee09: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0042ee0a: { // 0x42ee0a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0042ee0b: { // 0x42ee0b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0042ee0c: { // 0x42ee0c: 0f84b5000000 JZ 0x0042eec7
    if(integer::condition("JZ",flags)) goto L0042eec7;
  }
  L0042ee12: { // 0x42ee12: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  L0042ee17: { // 0x42ee17: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0042ee18: { // 0x42ee18: f7797c IDIV dword ptr [ECX + 0x7c]
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(m.r32((s.cx+0x0000007cu)),32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L0042ee1b: { // 0x42ee1b: a1906c8300 MOV EAX,[0x00836c90]
    s.ax = m.r32((0x00836c90u));
  }
  L0042ee20: { // 0x42ee20: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0042ee21: { // 0x42ee21: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L0042ee23: { // 0x42ee23: 0f8d9e000000 JGE 0x0042eec7
    if(integer::condition("JGE",flags)) goto L0042eec7;
  }
  L0042ee29: { // 0x42ee29: 8b6c242c MOV EBP,dword ptr [ESP + 0x2c]
    s.bp = m.r32((f.sp+0x0000002cu));
  }
  L0042ee2d: { // 0x42ee2d: 8b5c2428 MOV EBX,dword ptr [ESP + 0x28]
    s.bx = m.r32((f.sp+0x00000028u));
  }
  L0042ee31: { // 0x42ee31: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0042ee33: { // 0x42ee33: c744241408000000 MOV dword ptr [ESP + 0x14],0x8
    m.w32((f.sp+0x00000014u), 0x00000008u);
  }
  L0042ee3b: { // 0x42ee3b: c744241003000000 MOV dword ptr [ESP + 0x10],0x3
    m.w32((f.sp+0x00000010u), 0x00000003u);
  }
  L0042ee43: { // 0x42ee43: 8b37 MOV ESI,dword ptr [EDI]
    s.si = m.r32((s.di));
  }
  L0042ee45: { // 0x42ee45: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0042ee47: { // 0x42ee47: 7461 JZ 0x0042eeaa
    if(integer::condition("JZ",flags)) goto L0042eeaa;
  }
  L0042ee49: { // 0x42ee49: f6460c01 TEST byte ptr [ESI + 0xc],0x1
    (void)integer::logical((m.r8((s.si+0x0000000cu)))&(0x00000001u),8,flags);
  }
  L0042ee4d: { // 0x42ee4d: 745b JZ 0x0042eeaa
    if(integer::condition("JZ",flags)) goto L0042eeaa;
  }
  L0042ee4f: { // 0x42ee4f: 8b8e10010000 MOV ECX,dword ptr [ESI + 0x110]
    s.cx = m.r32((s.si+0x00000110u));
  }
  L0042ee55: { // 0x42ee55: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0042ee56: { // 0x42ee56: 8b0de4e0a100 MOV ECX,dword ptr [0x00a1e0e4]
    s.cx = m.r32((0x00a1e0e4u));
  }
  L0042ee5c: { // 0x42ee5c: e83f5d0b00 CALL 0x004e4ba0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e4ba0u,4386401u); flags=s.arithmetic_flags;
  }
  L0042ee61: { // 0x42ee61: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0042ee63: { // 0x42ee63: 7445 JZ 0x0042eeaa
    if(integer::condition("JZ",flags)) goto L0042eeaa;
  }
  L0042ee65: { // 0x42ee65: 8b8610010000 MOV EAX,dword ptr [ESI + 0x110]
    s.ax = m.r32((s.si+0x00000110u));
  }
  L0042ee6b: { // 0x42ee6b: 8b0dcca5a100 MOV ECX,dword ptr [0x00a1a5cc]
    s.cx = m.r32((0x00a1a5ccu));
  }
  L0042ee71: { // 0x42ee71: 8b15e4e0a100 MOV EDX,dword ptr [0x00a1e0e4]
    s.dx = m.r32((0x00a1e0e4u));
  }
  L0042ee77: { // 0x42ee77: 8b0c81 MOV ECX,dword ptr [ECX + EAX*0x4]
    s.cx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L0042ee7a: { // 0x42ee7a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0042ee7b: { // 0x42ee7b: e8605d0b00 CALL 0x004e4be0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e4be0u,4386432u); flags=s.arithmetic_flags;
  }
  L0042ee80: { // 0x42ee80: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0042ee82: { // 0x42ee82: 7426 JZ 0x0042eeaa
    if(integer::condition("JZ",flags)) goto L0042eeaa;
  }
  L0042ee84: { // 0x42ee84: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L0042ee88: { // 0x42ee88: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0042ee8a: { // 0x42ee8a: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L0042ee8e: { // 0x42ee8e: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L0042ee91: { // 0x42ee91: 8bd4 MOV EDX,ESP
    s.dx = f.sp;
  }
  L0042ee93: { // 0x42ee93: 8902 MOV dword ptr [EDX],EAX
    m.w32((s.dx), s.ax);
  }
  L0042ee95: { // 0x42ee95: 894a04 MOV dword ptr [EDX + 0x4],ECX
    m.w32((s.dx+0x00000004u), s.cx);
  }
  L0042ee98: { // 0x42ee98: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0042ee9a: { // 0x42ee9a: 895a08 MOV dword ptr [EDX + 0x8],EBX
    m.w32((s.dx+0x00000008u), s.bx);
  }
  L0042ee9d: { // 0x42ee9d: 896a0c MOV dword ptr [EDX + 0xc],EBP
    m.w32((s.dx+0x0000000cu), s.bp);
  }
  L0042eea0: { // 0x42eea0: 8b542430 MOV EDX,dword ptr [ESP + 0x30]
    s.dx = m.r32((f.sp+0x00000030u));
  }
  L0042eea4: { // 0x42eea4: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0042eea5: { // 0x42eea5: e876efffff CALL 0x0042de20
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042de20u,4386474u); flags=s.arithmetic_flags;
  }
  L0042eeaa: { // 0x42eeaa: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0042eeae: { // 0x42eeae: 83c704 ADD EDI,0x4
    s.di = integer::add(s.di,0x00000004u,32,flags);
  }
  L0042eeb1: { // 0x42eeb1: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0042eeb2: { // 0x42eeb2: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0042eeb6: { // 0x42eeb6: 758b JNZ 0x0042ee43
    if(integer::condition("JNZ",flags)) goto L0042ee43;
  }
  L0042eeb8: { // 0x42eeb8: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0042eebc: { // 0x42eebc: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0042eebd: { // 0x42eebd: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L0042eec1: { // 0x42eec1: 0f8574ffffff JNZ 0x0042ee3b
    if(integer::condition("JNZ",flags)) goto L0042ee3b;
  }
  L0042eec7: { // 0x42eec7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0042eec8: { // 0x42eec8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0042eec9: { // 0x42eec9: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0042eeca: { // 0x42eeca: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0042eecb: { // 0x42eecb: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0042eece: { // 0x42eece: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
