#include "recovered/recovery_b527_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b527 {
namespace {
void f_00258270(Memory&,State&,Frame&,const Operations&);
void f_002a9870(Memory&,State&,Frame&,const Operations&);
void f_000e4ae0(Memory&,State&,Frame&,const Operations&);
void f_000e24d0(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_00258270(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00658270: { // 0x00658270: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L00658274: { // 0x00658274: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00658275: { // 0x00658275: 83f832 CMP EAX,0x32
    (void)integer::sub(s.ax,0x00000032u,32,flags);
  }
  L00658278: { // 0x00658278: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0065827a: { // 0x0065827a: 7336 JNC 0x006582b2
    if(integer::condition("JNC",flags)) goto L006582b2;
  }
  L0065827c: { // 0x0065827c: 8d0c80 LEA ECX,[EAX + EAX*0x4]
    s.cx = (s.ax+(s.ax * 0x00000004u));
  }
  L0065827f: { // 0x0065827f: 8d1407 LEA EDX,[EDI + EAX*0x1]
    s.dx = (s.di+(s.ax * 0x00000001u));
  }
  L00658282: { // 0x00658282: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00658283: { // 0x00658283: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00658284: { // 0x00658284: 8a9cca38120000 MOV BL,byte ptr [EDX + ECX*0x8 + 0x1238]
    s.bx = with_al(s.bx, m.r8((s.dx+(s.cx * 0x00000008u)+0x00001238u)));
  }
  L0065828b: { // 0x0065828b: 8db4ca38120000 LEA ESI,[EDX + ECX*0x8 + 0x1238]
    s.si = (s.dx+(s.cx * 0x00000008u)+0x00001238u);
  }
  L00658292: { // 0x00658292: 8a4c2414 MOV CL,byte ptr [ESP + 0x14]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000014u)));
  }
  L00658296: { // 0x00658296: 3ad9 CMP BL,CL
    (void)integer::sub((s.bx & 0xffu),(s.cx & 0xffu),8,flags);
  }
  L00658298: { // 0x00658298: 7410 JZ 0x006582aa
    if(integer::condition("JZ",flags)) goto L006582aa;
  }
  L0065829a: { // 0x0065829a: 880e MOV byte ptr [ESI],CL
    m.w8((s.si), (s.cx & 0xffu));
  }
  L0065829c: { // 0x0065829c: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0065829e: { // 0x0065829e: c6872e22000001 MOV byte ptr [EDI + 0x222e],0x1
    m.w8((s.di+0x0000222eu), 0x00000001u);
  }
  L006582a5: { // 0x006582a5: e8c6150500 CALL 0x006a9870
    s.arithmetic_flags=flags; invoke(m,s,f,0x006a9870u,6652586u); flags=s.arithmetic_flags;
  }
  L006582aa: { // 0x006582aa: 8ac3 MOV AL,BL
    s.ax = with_al(s.ax, (s.bx & 0xffu));
  }
  L006582ac: { // 0x006582ac: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006582ad: { // 0x006582ad: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006582ae: { // 0x006582ae: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006582af: { // 0x006582af: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L006582b2: { // 0x006582b2: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006582b4: { // 0x006582b4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006582b5: { // 0x006582b5: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_002a9870(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006a9870: { // 0x6a9870: a16079aa00 MOV EAX,[0x00aa7960]
    s.ax = m.r32((0x00aa7960u));
  }
  L006a9875: { // 0x6a9875: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006a9876: { // 0x6a9876: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L006a9878: { // 0x6a9878: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006a9879: { // 0x6a9879: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006a987b: { // 0x6a987b: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L006a987d: { // 0x6a987d: 7e1b JLE 0x006a989a
    if(integer::condition("JLE",flags)) goto L006a989a;
  }
  L006a987f: { // 0x6a987f: a15479aa00 MOV EAX,[0x00aa7954]
    s.ax = m.r32((0x00aa7954u));
  }
  L006a9884: { // 0x6a9884: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006a9885: { // 0x6a9885: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  L006a9888: { // 0x6a9888: 8b4928 MOV ECX,dword ptr [ECX + 0x28]
    s.cx = m.r32((s.cx+0x00000028u));
  }
  L006a988b: { // 0x6a988b: e850900300 CALL 0x006e28e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006e28e0u,6985872u); flags=s.arithmetic_flags;
  }
  L006a9890: { // 0x6a9890: a16079aa00 MOV EAX,[0x00aa7960]
    s.ax = m.r32((0x00aa7960u));
  }
  L006a9895: { // 0x6a9895: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L006a9896: { // 0x6a9896: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L006a9898: { // 0x6a9898: 7ce5 JL 0x006a987f
    if(integer::condition("JL",flags)) goto L006a987f;
  }
  L006a989a: { // 0x6a989a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006a989b: { // 0x6a989b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006a989c: { // 0x6a989c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000e4ae0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004e4ae0: { // 0x4e4ae0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L004e4ae4: { // 0x4e4ae4: 8b914c020000 MOV EDX,dword ptr [ECX + 0x24c]
    s.dx = m.r32((s.cx+0x0000024cu));
  }
  L004e4aea: { // 0x4e4aea: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L004e4aec: { // 0x4e4aec: 89914c020000 MOV dword ptr [ECX + 0x24c],EDX
    m.w32((s.cx+0x0000024cu), s.dx);
  }
  L004e4af2: { // 0x4e4af2: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000e24d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004e24d0: { // 0x4e24d0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004e24d1: { // 0x4e24d1: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L004e24d3: { // 0x4e24d3: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L004e24d6: { // 0x4e24d6: 83ec14 SUB ESP,0x14
    f.sp = integer::sub(f.sp,0x00000014u,32,flags);
  }
  L004e24d9: { // 0x4e24d9: 8b81c8000000 MOV EAX,dword ptr [ECX + 0xc8]
    s.ax = m.r32((s.cx+0x000000c8u));
  }
  L004e24df: { // 0x4e24df: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004e24e0: { // 0x4e24e0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004e24e1: { // 0x4e24e1: 8b7508 MOV ESI,dword ptr [EBP + 0x8]
    s.si = m.r32((s.bp+0x00000008u));
  }
  L004e24e4: { // 0x4e24e4: 8944240c MOV dword ptr [ESP + 0xc],EAX
    m.w32((f.sp+0x0000000cu), s.ax);
  }
  L004e24e8: { // 0x4e24e8: 89b1c8000000 MOV dword ptr [ECX + 0xc8],ESI
    m.w32((s.cx+0x000000c8u), s.si);
  }
  L004e24ee: { // 0x4e24ee: a1c855a200 MOV EAX,[0x00a255c8]
    s.ax = m.r32((0x00a255c8u));
  }
  L004e24f3: { // 0x4e24f3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004e24f4: { // 0x4e24f4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e24f6: { // 0x4e24f6: 0f8400010000 JZ 0x004e25fc
    if(integer::condition("JZ",flags)) goto L004e25fc;
  }
  L004e24fc: { // 0x4e24fc: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L004e2501: { // 0x4e2501: 8b7934 MOV EDI,dword ptr [ECX + 0x34]
    s.di = m.r32((s.cx+0x00000034u));
  }
  L004e2504: { // 0x4e2504: 8d14b6 LEA EDX,[ESI + ESI*0x4]
    s.dx = (s.si+(s.si * 0x00000004u));
  }
  L004e2507: { // 0x4e2507: c1e204 SHL EDX,0x4
    s.dx = integer::shift(s.dx,0x00000004u,32,flags,integer::Shift::left);
  }
  L004e250a: { // 0x4e250a: dd840298110000 FLD double ptr [EDX + EAX*0x1 + 0x1198]
    const auto address=(s.dx+(s.ax * 0x00000001u)+0x00001198u);
    s.fp.load64(read64(m,address));
  }
  L004e2511: { // 0x4e2511: dc8fc8000000 FMUL double ptr [EDI + 0xc8]
    const auto address=(s.di+0x000000c8u);
    s.fp.multiply64(read64(m,address));
  }
  L004e2517: { // 0x4e2517: dd99d0000000 FSTP double ptr [ECX + 0xd0]
    const auto address=(s.cx+0x000000d0u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L004e251d: { // 0x4e251d: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L004e2522: { // 0x4e2522: dd8402a0110000 FLD double ptr [EDX + EAX*0x1 + 0x11a0]
    const auto address=(s.dx+(s.ax * 0x00000001u)+0x000011a0u);
    s.fp.load64(read64(m,address));
  }
  L004e2529: { // 0x4e2529: dc8880100000 FMUL double ptr [EAX + 0x1080]
    const auto address=(s.ax+0x00001080u);
    s.fp.multiply64(read64(m,address));
  }
  L004e252f: { // 0x4e252f: dc8fd0000000 FMUL double ptr [EDI + 0xd0]
    const auto address=(s.di+0x000000d0u);
    s.fp.multiply64(read64(m,address));
  }
  L004e2535: { // 0x4e2535: dd99d8000000 FSTP double ptr [ECX + 0xd8]
    const auto address=(s.cx+0x000000d8u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L004e253b: { // 0x4e253b: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L004e2540: { // 0x4e2540: dd8402a8110000 FLD double ptr [EDX + EAX*0x1 + 0x11a8]
    const auto address=(s.dx+(s.ax * 0x00000001u)+0x000011a8u);
    s.fp.load64(read64(m,address));
  }
  L004e2547: { // 0x4e2547: dc8880100000 FMUL double ptr [EAX + 0x1080]
    const auto address=(s.ax+0x00001080u);
    s.fp.multiply64(read64(m,address));
  }
  L004e254d: { // 0x4e254d: dc8fd8000000 FMUL double ptr [EDI + 0xd8]
    const auto address=(s.di+0x000000d8u);
    s.fp.multiply64(read64(m,address));
  }
  L004e2553: { // 0x4e2553: dd99e0000000 FSTP double ptr [ECX + 0xe0]
    const auto address=(s.cx+0x000000e0u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L004e2559: { // 0x4e2559: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L004e255e: { // 0x4e255e: dd8402b0110000 FLD double ptr [EDX + EAX*0x1 + 0x11b0]
    const auto address=(s.dx+(s.ax * 0x00000001u)+0x000011b0u);
    s.fp.load64(read64(m,address));
  }
  L004e2565: { // 0x4e2565: dc8fe0000000 FMUL double ptr [EDI + 0xe0]
    const auto address=(s.di+0x000000e0u);
    s.fp.multiply64(read64(m,address));
  }
  L004e256b: { // 0x4e256b: dd99e8000000 FSTP double ptr [ECX + 0xe8]
    const auto address=(s.cx+0x000000e8u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L004e2571: { // 0x4e2571: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L004e2576: { // 0x4e2576: dd8402b8110000 FLD double ptr [EDX + EAX*0x1 + 0x11b8]
    const auto address=(s.dx+(s.ax * 0x00000001u)+0x000011b8u);
    s.fp.load64(read64(m,address));
  }
  L004e257d: { // 0x4e257d: dc8fe8000000 FMUL double ptr [EDI + 0xe8]
    const auto address=(s.di+0x000000e8u);
    s.fp.multiply64(read64(m,address));
  }
  L004e2583: { // 0x4e2583: dd99f0000000 FSTP double ptr [ECX + 0xf0]
    const auto address=(s.cx+0x000000f0u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L004e2589: { // 0x4e2589: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L004e258e: { // 0x4e258e: dd8402c0110000 FLD double ptr [EDX + EAX*0x1 + 0x11c0]
    const auto address=(s.dx+(s.ax * 0x00000001u)+0x000011c0u);
    s.fp.load64(read64(m,address));
  }
  L004e2595: { // 0x4e2595: dc8ff0000000 FMUL double ptr [EDI + 0xf0]
    const auto address=(s.di+0x000000f0u);
    s.fp.multiply64(read64(m,address));
  }
  L004e259b: { // 0x4e259b: 8d84b61d010000 LEA EAX,[ESI + ESI*0x4 + 0x11d]
    s.ax = (s.si+(s.si * 0x00000004u)+0x0000011du);
  }
  L004e25a2: { // 0x4e25a2: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L004e25a5: { // 0x4e25a5: dd99f8000000 FSTP double ptr [ECX + 0xf8]
    const auto address=(s.cx+0x000000f8u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L004e25ab: { // 0x4e25ab: 0305881b8200 ADD EAX,dword ptr [0x00821b88]
    s.ax = integer::add(s.ax,m.r32((0x00821b88u)),32,flags);
  }
  L004e25b1: { // 0x4e25b1: 8b18 MOV EBX,dword ptr [EAX]
    s.bx = m.r32((s.ax));
  }
  L004e25b3: { // 0x4e25b3: 899908010000 MOV dword ptr [ECX + 0x108],EBX
    m.w32((s.cx+0x00000108u), s.bx);
  }
  L004e25b9: { // 0x4e25b9: 8b4004 MOV EAX,dword ptr [EAX + 0x4]
    s.ax = m.r32((s.ax+0x00000004u));
  }
  L004e25bc: { // 0x4e25bc: 89810c010000 MOV dword ptr [ECX + 0x10c],EAX
    m.w32((s.cx+0x0000010cu), s.ax);
  }
  L004e25c2: { // 0x4e25c2: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L004e25c7: { // 0x4e25c7: 8d8402d8110000 LEA EAX,[EDX + EAX*0x1 + 0x11d8]
    s.ax = (s.dx+(s.ax * 0x00000001u)+0x000011d8u);
  }
  L004e25ce: { // 0x4e25ce: 8b18 MOV EBX,dword ptr [EAX]
    s.bx = m.r32((s.ax));
  }
  L004e25d0: { // 0x4e25d0: 899910010000 MOV dword ptr [ECX + 0x110],EBX
    m.w32((s.cx+0x00000110u), s.bx);
  }
  L004e25d6: { // 0x4e25d6: 8b4004 MOV EAX,dword ptr [EAX + 0x4]
    s.ax = m.r32((s.ax+0x00000004u));
  }
  L004e25d9: { // 0x4e25d9: 898114010000 MOV dword ptr [ECX + 0x114],EAX
    m.w32((s.cx+0x00000114u), s.ax);
  }
  L004e25df: { // 0x4e25df: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L004e25e4: { // 0x4e25e4: dd8402c8110000 FLD double ptr [EDX + EAX*0x1 + 0x11c8]
    const auto address=(s.dx+(s.ax * 0x00000001u)+0x000011c8u);
    s.fp.load64(read64(m,address));
  }
  L004e25eb: { // 0x4e25eb: dc8880100000 FMUL double ptr [EAX + 0x1080]
    const auto address=(s.ax+0x00001080u);
    s.fp.multiply64(read64(m,address));
  }
  L004e25f1: { // 0x4e25f1: dc8ff8000000 FMUL double ptr [EDI + 0xf8]
    const auto address=(s.di+0x000000f8u);
    s.fp.multiply64(read64(m,address));
  }
  L004e25f7: { // 0x4e25f7: e9fc000000 JMP 0x004e26f8
    goto L004e26f8;
  }
  L004e25fc: { // 0x4e25fc: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L004e2601: { // 0x4e2601: 8d14b6 LEA EDX,[ESI + ESI*0x4]
    s.dx = (s.si+(s.si * 0x00000004u));
  }
  L004e2604: { // 0x4e2604: c1e204 SHL EDX,0x4
    s.dx = integer::shift(s.dx,0x00000004u,32,flags,integer::Shift::left);
  }
  L004e2607: { // 0x4e2607: 8d840298110000 LEA EAX,[EDX + EAX*0x1 + 0x1198]
    s.ax = (s.dx+(s.ax * 0x00000001u)+0x00001198u);
  }
  L004e260e: { // 0x4e260e: 8b38 MOV EDI,dword ptr [EAX]
    s.di = m.r32((s.ax));
  }
  L004e2610: { // 0x4e2610: 89b9d0000000 MOV dword ptr [ECX + 0xd0],EDI
    m.w32((s.cx+0x000000d0u), s.di);
  }
  L004e2616: { // 0x4e2616: 8b4004 MOV EAX,dword ptr [EAX + 0x4]
    s.ax = m.r32((s.ax+0x00000004u));
  }
  L004e2619: { // 0x4e2619: 8981d4000000 MOV dword ptr [ECX + 0xd4],EAX
    m.w32((s.cx+0x000000d4u), s.ax);
  }
  L004e261f: { // 0x4e261f: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L004e2624: { // 0x4e2624: dd8402a0110000 FLD double ptr [EDX + EAX*0x1 + 0x11a0]
    const auto address=(s.dx+(s.ax * 0x00000001u)+0x000011a0u);
    s.fp.load64(read64(m,address));
  }
  L004e262b: { // 0x4e262b: dc8880100000 FMUL double ptr [EAX + 0x1080]
    const auto address=(s.ax+0x00001080u);
    s.fp.multiply64(read64(m,address));
  }
  L004e2631: { // 0x4e2631: dd99d8000000 FSTP double ptr [ECX + 0xd8]
    const auto address=(s.cx+0x000000d8u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L004e2637: { // 0x4e2637: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L004e263c: { // 0x4e263c: dd8402a8110000 FLD double ptr [EDX + EAX*0x1 + 0x11a8]
    const auto address=(s.dx+(s.ax * 0x00000001u)+0x000011a8u);
    s.fp.load64(read64(m,address));
  }
  L004e2643: { // 0x4e2643: dc8880100000 FMUL double ptr [EAX + 0x1080]
    const auto address=(s.ax+0x00001080u);
    s.fp.multiply64(read64(m,address));
  }
  L004e2649: { // 0x4e2649: dd99e0000000 FSTP double ptr [ECX + 0xe0]
    const auto address=(s.cx+0x000000e0u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L004e264f: { // 0x4e264f: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L004e2654: { // 0x4e2654: 8d8402b0110000 LEA EAX,[EDX + EAX*0x1 + 0x11b0]
    s.ax = (s.dx+(s.ax * 0x00000001u)+0x000011b0u);
  }
  L004e265b: { // 0x4e265b: 8b38 MOV EDI,dword ptr [EAX]
    s.di = m.r32((s.ax));
  }
  L004e265d: { // 0x4e265d: 89b9e8000000 MOV dword ptr [ECX + 0xe8],EDI
    m.w32((s.cx+0x000000e8u), s.di);
  }
  L004e2663: { // 0x4e2663: 8b4004 MOV EAX,dword ptr [EAX + 0x4]
    s.ax = m.r32((s.ax+0x00000004u));
  }
  L004e2666: { // 0x4e2666: 8981ec000000 MOV dword ptr [ECX + 0xec],EAX
    m.w32((s.cx+0x000000ecu), s.ax);
  }
  L004e266c: { // 0x4e266c: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L004e2671: { // 0x4e2671: 8d8402b8110000 LEA EAX,[EDX + EAX*0x1 + 0x11b8]
    s.ax = (s.dx+(s.ax * 0x00000001u)+0x000011b8u);
  }
  L004e2678: { // 0x4e2678: 8b38 MOV EDI,dword ptr [EAX]
    s.di = m.r32((s.ax));
  }
  L004e267a: { // 0x4e267a: 89b9f0000000 MOV dword ptr [ECX + 0xf0],EDI
    m.w32((s.cx+0x000000f0u), s.di);
  }
  L004e2680: { // 0x4e2680: 8b4004 MOV EAX,dword ptr [EAX + 0x4]
    s.ax = m.r32((s.ax+0x00000004u));
  }
  L004e2683: { // 0x4e2683: 8981f4000000 MOV dword ptr [ECX + 0xf4],EAX
    m.w32((s.cx+0x000000f4u), s.ax);
  }
  L004e2689: { // 0x4e2689: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L004e268e: { // 0x4e268e: 8d8402c0110000 LEA EAX,[EDX + EAX*0x1 + 0x11c0]
    s.ax = (s.dx+(s.ax * 0x00000001u)+0x000011c0u);
  }
  L004e2695: { // 0x4e2695: 8b38 MOV EDI,dword ptr [EAX]
    s.di = m.r32((s.ax));
  }
  L004e2697: { // 0x4e2697: 89b9f8000000 MOV dword ptr [ECX + 0xf8],EDI
    m.w32((s.cx+0x000000f8u), s.di);
  }
  L004e269d: { // 0x4e269d: 8b4004 MOV EAX,dword ptr [EAX + 0x4]
    s.ax = m.r32((s.ax+0x00000004u));
  }
  L004e26a0: { // 0x4e26a0: 8981fc000000 MOV dword ptr [ECX + 0xfc],EAX
    m.w32((s.cx+0x000000fcu), s.ax);
  }
  L004e26a6: { // 0x4e26a6: 8b3d881b8200 MOV EDI,dword ptr [0x00821b88]
    s.di = m.r32((0x00821b88u));
  }
  L004e26ac: { // 0x4e26ac: 8d84b61d010000 LEA EAX,[ESI + ESI*0x4 + 0x11d]
    s.ax = (s.si+(s.si * 0x00000004u)+0x0000011du);
  }
  L004e26b3: { // 0x4e26b3: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L004e26b6: { // 0x4e26b6: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L004e26b8: { // 0x4e26b8: 8b38 MOV EDI,dword ptr [EAX]
    s.di = m.r32((s.ax));
  }
  L004e26ba: { // 0x4e26ba: 89b908010000 MOV dword ptr [ECX + 0x108],EDI
    m.w32((s.cx+0x00000108u), s.di);
  }
  L004e26c0: { // 0x4e26c0: 8b4004 MOV EAX,dword ptr [EAX + 0x4]
    s.ax = m.r32((s.ax+0x00000004u));
  }
  L004e26c3: { // 0x4e26c3: 89810c010000 MOV dword ptr [ECX + 0x10c],EAX
    m.w32((s.cx+0x0000010cu), s.ax);
  }
  L004e26c9: { // 0x4e26c9: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L004e26ce: { // 0x4e26ce: 8d8402d8110000 LEA EAX,[EDX + EAX*0x1 + 0x11d8]
    s.ax = (s.dx+(s.ax * 0x00000001u)+0x000011d8u);
  }
  L004e26d5: { // 0x4e26d5: 8b38 MOV EDI,dword ptr [EAX]
    s.di = m.r32((s.ax));
  }
  L004e26d7: { // 0x4e26d7: 89b910010000 MOV dword ptr [ECX + 0x110],EDI
    m.w32((s.cx+0x00000110u), s.di);
  }
  L004e26dd: { // 0x4e26dd: 8b4004 MOV EAX,dword ptr [EAX + 0x4]
    s.ax = m.r32((s.ax+0x00000004u));
  }
  L004e26e0: { // 0x4e26e0: 898114010000 MOV dword ptr [ECX + 0x114],EAX
    m.w32((s.cx+0x00000114u), s.ax);
  }
  L004e26e6: { // 0x4e26e6: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L004e26eb: { // 0x4e26eb: dd8402c8110000 FLD double ptr [EDX + EAX*0x1 + 0x11c8]
    const auto address=(s.dx+(s.ax * 0x00000001u)+0x000011c8u);
    s.fp.load64(read64(m,address));
  }
  L004e26f2: { // 0x4e26f2: dc8880100000 FMUL double ptr [EAX + 0x1080]
    const auto address=(s.ax+0x00001080u);
    s.fp.multiply64(read64(m,address));
  }
  L004e26f8: { // 0x4e26f8: dd9900010000 FSTP double ptr [ECX + 0x100]
    const auto address=(s.cx+0x00000100u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L004e26fe: { // 0x4e26fe: 8b15881b8200 MOV EDX,dword ptr [0x00821b88]
    s.dx = m.r32((0x00821b88u));
  }
  L004e2704: { // 0x4e2704: 8b3d6c89a200 MOV EDI,dword ptr [0x00a2896c]
    s.di = m.r32((0x00a2896cu));
  }
  L004e270a: { // 0x4e270a: 8b9a340e0000 MOV EBX,dword ptr [EDX + 0xe34]
    s.bx = m.r32((s.dx+0x00000e34u));
  }
  L004e2710: { // 0x4e2710: 8b5130 MOV EDX,dword ptr [ECX + 0x30]
    s.dx = m.r32((s.cx+0x00000030u));
  }
  L004e2713: { // 0x4e2713: 8d04d500000000 LEA EAX,[EDX*0x8 + 0x0]
    s.ax = ((s.dx * 0x00000008u)+0x00000000u);
  }
  L004e271a: { // 0x4e271a: 8b34b3 MOV ESI,dword ptr [EBX + ESI*0x4]
    s.si = m.r32((s.bx+(s.si * 0x00000004u)));
  }
  L004e271d: { // 0x4e271d: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004e271f: { // 0x4e271f: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L004e2723: { // 0x4e2723: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L004e2726: { // 0x4e2726: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L004e2729: { // 0x4e2729: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L004e272b: { // 0x4e272b: 81c184560000 ADD ECX,0x5684
    s.cx = integer::add(s.cx,0x00005684u,32,flags);
  }
  L004e2731: { // 0x4e2731: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L004e2735: { // 0x4e2735: 8939 MOV dword ptr [ECX],EDI
    m.w32((s.cx), s.di);
  }
  L004e2737: { // 0x4e2737: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004e2738: { // 0x4e2738: 895104 MOV dword ptr [ECX + 0x4],EDX
    m.w32((s.cx+0x00000004u), s.dx);
  }
  L004e273b: { // 0x4e273b: 897108 MOV dword ptr [ECX + 0x8],ESI
    m.w32((s.cx+0x00000008u), s.si);
  }
  L004e273e: { // 0x4e273e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004e273f: { // 0x4e273f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004e2740: { // 0x4e2740: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L004e2742: { // 0x4e2742: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004e2743: { // 0x4e2743: c20400 RET 0x4
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
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 6652528u:f_00258270(m,s,child,{});break;
case 6985840u:f_002a9870(m,s,child,{});break;
case 5130976u:f_000e4ae0(m,s,child,{});break;
case 5121232u:f_000e24d0(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
default:throw std::domain_error("recovery527 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_004b5850(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004b5850: { // 0x4b5850: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L004b5853: { // 0x4b5853: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004b5854: { // 0x4b5854: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004b5855: { // 0x4b5855: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L004b5857: { // 0x4b5857: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L004b5859: { // 0x4b5859: 8a043e MOV AL,byte ptr [ESI + EDI*0x1]
    s.ax = with_al(s.ax, m.r8((s.si+(s.di * 0x00000001u))));
  }
  L004b585c: { // 0x4b585c: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L004b5862: { // 0x4b5862: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004b5863: { // 0x4b5863: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004b5864: { // 0x4b5864: e8072a1a00 CALL 0x00658270
    s.arithmetic_flags=flags; invoke(m,s,f,0x00658270u,4937833u); flags=s.arithmetic_flags;
  }
  L004b5869: { // 0x4b5869: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L004b586a: { // 0x4b586a: 83fe32 CMP ESI,0x32
    (void)integer::sub(s.si,0x00000032u,32,flags);
  }
  L004b586d: { // 0x4b586d: 7cea JL 0x004b5859
    if(integer::condition("JL",flags)) goto L004b5859;
  }
  L004b586f: { // 0x4b586f: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  L004b5874: { // 0x4b5874: db4734 FILD dword ptr [EDI + 0x34]
    const auto address=(s.di+0x00000034u);
    s.fp.load_integer32(m.r32(address));
  }
  L004b5877: { // 0x4b5877: 8b8808120000 MOV ECX,dword ptr [EAX + 0x1208]
    s.cx = m.r32((s.ax+0x00001208u));
  }
  L004b587d: { // 0x4b587d: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  L004b5880: { // 0x4b5880: 894c2408 MOV dword ptr [ESP + 0x8],ECX
    m.w32((f.sp+0x00000008u), s.cx);
  }
  L004b5884: { // 0x4b5884: dc8800120000 FMUL double ptr [EAX + 0x1200]
    const auto address=(s.ax+0x00001200u);
    s.fp.multiply64(read64(m,address));
  }
  L004b588a: { // 0x4b588a: 7419 JZ 0x004b58a5
    if(integer::condition("JZ",flags)) goto L004b58a5;
  }
  L004b588c: { // 0x4b588c: db442408 FILD dword ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.load_integer32(m.r32(address));
  }
  L004b5890: { // 0x4b5890: dd5c2408 FSTP double ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L004b5894: { // 0x4b5894: dc542408 FCOM double ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L004b5898: { // 0x4b5898: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004b589a: { // 0x4b589a: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L004b589d: { // 0x4b589d: 7506 JNZ 0x004b58a5
    if(integer::condition("JNZ",flags)) goto L004b58a5;
  }
  L004b589f: { // 0x4b589f: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L004b58a1: { // 0x4b58a1: dd442408 FLD double ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.load64(read64(m,address));
  }
  L004b58a5: { // 0x4b58a5: e8a6512b00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4937898u); flags=s.arithmetic_flags;
  }
  L004b58aa: { // 0x4b58aa: 8b0de4e0a100 MOV ECX,dword ptr [0x00a1e0e4]
    s.cx = m.r32((0x00a1e0e4u));
  }
  L004b58b0: { // 0x4b58b0: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L004b58b2: { // 0x4b58b2: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004b58b3: { // 0x4b58b3: e828f20200 CALL 0x004e4ae0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e4ae0u,4937912u); flags=s.arithmetic_flags;
  }
  L004b58b8: { // 0x4b58b8: a1e4e0a100 MOV EAX,[0x00a1e0e4]
    s.ax = m.r32((0x00a1e0e4u));
  }
  L004b58bd: { // 0x4b58bd: 8b8824010000 MOV ECX,dword ptr [EAX + 0x124]
    s.cx = m.r32((s.ax+0x00000124u));
  }
  L004b58c3: { // 0x4b58c3: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L004b58c5: { // 0x4b58c5: 898824010000 MOV dword ptr [EAX + 0x124],ECX
    m.w32((s.ax+0x00000124u), s.cx);
  }
  L004b58cb: { // 0x4b58cb: 8b4f3c MOV ECX,dword ptr [EDI + 0x3c]
    s.cx = m.r32((s.di+0x0000003cu));
  }
  L004b58ce: { // 0x4b58ce: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004b58cf: { // 0x4b58cf: 8b0de4e0a100 MOV ECX,dword ptr [0x00a1e0e4]
    s.cx = m.r32((0x00a1e0e4u));
  }
  L004b58d5: { // 0x4b58d5: e8f6cb0200 CALL 0x004e24d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e24d0u,4937946u); flags=s.arithmetic_flags;
  }
  L004b58da: { // 0x4b58da: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  L004b58df: { // 0x4b58df: 8a8831220000 MOV CL,byte ptr [EAX + 0x2231]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00002231u)));
  }
  L004b58e5: { // 0x4b58e5: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004b58e7: { // 0x4b58e7: 745f JZ 0x004b5948
    if(integer::condition("JZ",flags)) goto L004b5948;
  }
  L004b58e9: { // 0x4b58e9: 8b4f38 MOV ECX,dword ptr [EDI + 0x38]
    s.cx = m.r32((s.di+0x00000038u));
  }
  L004b58ec: { // 0x4b58ec: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004b58ee: { // 0x4b58ee: 7e47 JLE 0x004b5937
    if(integer::condition("JLE",flags)) goto L004b5937;
  }
  L004b58f0: { // 0x4b58f0: 8b156c89a200 MOV EDX,dword ptr [0x00a2896c]
    s.dx = m.r32((0x00a2896cu));
  }
  L004b58f6: { // 0x4b58f6: 05c8070000 ADD EAX,0x7c8
    s.ax = integer::add(s.ax,0x000007c8u,32,flags);
  }
  L004b58fb: { // 0x4b58fb: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L004b58fd: { // 0x4b58fd: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  L004b5901: { // 0x4b5901: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
  L004b5904: { // 0x4b5904: 894808 MOV dword ptr [EAX + 0x8],ECX
    m.w32((s.ax+0x00000008u), s.cx);
  }
  L004b5907: { // 0x4b5907: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  L004b590c: { // 0x4b590c: 83b8c8070000ff CMP dword ptr [EAX + 0x7c8],-0x1
    (void)integer::sub(m.r32((s.ax+0x000007c8u)),0xffffffffu,32,flags);
  }
  L004b5913: { // 0x4b5913: 7533 JNZ 0x004b5948
    if(integer::condition("JNZ",flags)) goto L004b5948;
  }
  L004b5915: { // 0x4b5915: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  L004b591b: { // 0x4b591b: 8988c8070000 MOV dword ptr [EAX + 0x7c8],ECX
    m.w32((s.ax+0x000007c8u), s.cx);
  }
  L004b5921: { // 0x4b5921: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  L004b5926: { // 0x4b5926: 668b5740 MOV DX,word ptr [EDI + 0x40]
    s.dx = with_ax(s.dx, m.r16((s.di+0x00000040u)));
  }
  L004b592a: { // 0x4b592a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004b592b: { // 0x4b592b: 66899004230000 MOV word ptr [EAX + 0x2304],DX
    m.w16((s.ax+0x00002304u), (s.dx & 0xffffu));
  }
  L004b5932: { // 0x4b5932: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004b5933: { // 0x4b5933: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L004b5936: { // 0x4b5936: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004b5937: { // 0x4b5937: 668b5740 MOV DX,word ptr [EDI + 0x40]
    s.dx = with_ax(s.dx, m.r16((s.di+0x00000040u)));
  }
  L004b593b: { // 0x4b593b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004b593c: { // 0x4b593c: 66899004230000 MOV word ptr [EAX + 0x2304],DX
    m.w16((s.ax+0x00002304u), (s.dx & 0xffffu));
  }
  L004b5943: { // 0x4b5943: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004b5944: { // 0x4b5944: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L004b5947: { // 0x4b5947: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004b5948: { // 0x4b5948: 668b4f40 MOV CX,word ptr [EDI + 0x40]
    s.cx = with_ax(s.cx, m.r16((s.di+0x00000040u)));
  }
  L004b594c: { // 0x4b594c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004b594d: { // 0x4b594d: 66898804230000 MOV word ptr [EAX + 0x2304],CX
    m.w16((s.ax+0x00002304u), (s.cx & 0xffffu));
  }
  L004b5954: { // 0x4b5954: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004b5955: { // 0x4b5955: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L004b5958: { // 0x4b5958: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
