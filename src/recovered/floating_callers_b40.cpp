#include "floating_callers_b40_memory.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Original instruction annotations are retained; acceptance requires current native proof.
namespace ra2::recovered::floating_callers_b40 {
namespace {
void f_0001b750(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x41b750: dd4108 FLD double ptr [ECX + 0x8]
    const auto address=(s.cx+0x00000008u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x41b753: dd01 FLD double ptr [ECX]
    const auto address=(s.cx);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x41b755: d9c0 FLD ST0
    s.fp.load_st0();
  }
  { // 0x41b757: d8c9 FMUL ST1
    extended::multiply_st1(s.fp);
  }
  { // 0x41b759: d9c2 FLD ST2
    s.fp.load_st2();
  }
  { // 0x41b75b: d8cb FMUL ST3
    extended::multiply_st3(s.fp);
  }
  { // 0x41b75d: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x41b760: dec1 FADDP
    s.fp.add_pop();
  }
  { // 0x41b762: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x41b765: ddd8 FSTP ST0
    s.fp.pop_st0();
  }
  { // 0x41b767: ddd8 FSTP ST0
    s.fp.pop_st0();
  }
  { // 0x41b769: e812e90900 CALL 0x004ba080
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x000ba080u,0x0041b76eu);
    flags=s.arithmetic_flags;
  }
  { // 0x41b76e: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x41b771: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0001b780(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x41b780: db4108 FILD dword ptr [ECX + 0x8]
    const auto address=(s.cx+0x00000008u);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x41b783: db4104 FILD dword ptr [ECX + 0x4]
    const auto address=(s.cx+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x41b786: db01 FILD dword ptr [ECX]
    const auto address=(s.cx);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x41b788: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x41b78b: d9c0 FLD ST0
    s.fp.load_st0();
  }
  { // 0x41b78d: d8c9 FMUL ST1
    extended::multiply_st1(s.fp);
  }
  { // 0x41b78f: d9c2 FLD ST2
    s.fp.load_st2();
  }
  { // 0x41b791: d8cb FMUL ST3
    extended::multiply_st3(s.fp);
  }
  { // 0x41b793: dec1 FADDP
    s.fp.add_pop();
  }
  { // 0x41b795: d9c3 FLD ST3
    extended::load_st3(s.fp);
  }
  { // 0x41b797: d8cc FMUL ST4
    extended::multiply_st4(s.fp);
  }
  { // 0x41b799: dec1 FADDP
    s.fp.add_pop();
  }
  { // 0x41b79b: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x41b79e: ddd8 FSTP ST0
    s.fp.pop_st0();
  }
  { // 0x41b7a0: ddd8 FSTP ST0
    s.fp.pop_st0();
  }
  { // 0x41b7a2: ddd8 FSTP ST0
    s.fp.pop_st0();
  }
  { // 0x41b7a4: e8d7e80900 CALL 0x004ba080
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x000ba080u,0x0041b7a9u);
    flags=s.arithmetic_flags;
  }
  { // 0x41b7a9: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x41b7ac: e99ff23400 JMP 0x0076aa50
    s.arithmetic_flags=flags;
    invoke_closed_tail(m,s,f,0x36aa50u); return;
  }
}
void f_0001b7c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x41b7c0: dd4110 FLD double ptr [ECX + 0x10]
    const auto address=(s.cx+0x00000010u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x41b7c3: dd4108 FLD double ptr [ECX + 0x8]
    const auto address=(s.cx+0x00000008u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x41b7c6: dd01 FLD double ptr [ECX]
    const auto address=(s.cx);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x41b7c8: d9c0 FLD ST0
    s.fp.load_st0();
  }
  { // 0x41b7ca: d8c9 FMUL ST1
    extended::multiply_st1(s.fp);
  }
  { // 0x41b7cc: d9c2 FLD ST2
    s.fp.load_st2();
  }
  { // 0x41b7ce: d8cb FMUL ST3
    extended::multiply_st3(s.fp);
  }
  { // 0x41b7d0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x41b7d3: dec1 FADDP
    s.fp.add_pop();
  }
  { // 0x41b7d5: d9c3 FLD ST3
    extended::load_st3(s.fp);
  }
  { // 0x41b7d7: d8cc FMUL ST4
    extended::multiply_st4(s.fp);
  }
  { // 0x41b7d9: dec1 FADDP
    s.fp.add_pop();
  }
  { // 0x41b7db: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x41b7de: ddd8 FSTP ST0
    s.fp.pop_st0();
  }
  { // 0x41b7e0: ddd8 FSTP ST0
    s.fp.pop_st0();
  }
  { // 0x41b7e2: ddd8 FSTP ST0
    s.fp.pop_st0();
  }
  { // 0x41b7e4: e897e80900 CALL 0x004ba080
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x000ba080u,0x0041b7e9u);
    flags=s.arithmetic_flags;
  }
  { // 0x41b7e9: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x41b7ec: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0001b830(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x41b830: dd4108 FLD double ptr [ECX + 0x8]
    const auto address=(s.cx+0x00000008u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x41b833: dd01 FLD double ptr [ECX]
    const auto address=(s.cx);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x41b835: d9c0 FLD ST0
    s.fp.load_st0();
  }
  { // 0x41b837: d8c9 FMUL ST1
    extended::multiply_st1(s.fp);
  }
  { // 0x41b839: d9c2 FLD ST2
    s.fp.load_st2();
  }
  { // 0x41b83b: d8cb FMUL ST3
    extended::multiply_st3(s.fp);
  }
  { // 0x41b83d: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x41b840: dec1 FADDP
    s.fp.add_pop();
  }
  { // 0x41b842: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x41b845: ddd8 FSTP ST0
    s.fp.pop_st0();
  }
  { // 0x41b847: ddd8 FSTP ST0
    s.fp.pop_st0();
  }
  { // 0x41b849: e832e80900 CALL 0x004ba080
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x000ba080u,0x0041b84eu);
    flags=s.arithmetic_flags;
  }
  { // 0x41b84e: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x41b851: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00036e00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x436e00: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x436e01: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x436e02: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x436e04: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x436e05: d94618 FLD float ptr [ESI + 0x18]
    const auto address=(s.si+0x00000018u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x436e08: e8433c3300 CALL 0x0076aa50
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x0036aa50u,0x00436e0du);
    flags=s.arithmetic_flags;
  }
  { // 0x436e0d: d9461c FLD float ptr [ESI + 0x1c]
    const auto address=(s.si+0x0000001cu);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x436e10: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x436e12: e8393c3300 CALL 0x0076aa50
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x0036aa50u,0x00436e17u);
    flags=s.arithmetic_flags;
  }
  { // 0x436e17: d94620 FLD float ptr [ESI + 0x20]
    const auto address=(s.si+0x00000020u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x436e1a: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  { // 0x436e1c: e82f3c3300 CALL 0x0076aa50
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x0036aa50u,0x00436e21u);
    flags=s.arithmetic_flags;
  }
  { // 0x436e21: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x436e25: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  { // 0x436e27: 893a MOV dword ptr [EDX],EDI
    m.w32((s.dx), s.di);
  }
  { // 0x436e29: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x436e2a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x436e2b: 895a04 MOV dword ptr [EDX + 0x4],EBX
    m.w32((s.dx+0x00000004u), s.bx);
  }
  { // 0x436e2e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x436e2f: 894208 MOV dword ptr [EDX + 0x8],EAX
    m.w32((s.dx+0x00000008u), s.ax);
  }
  { // 0x436e32: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x436e34: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00037590(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x437590: d94108 FLD float ptr [ECX + 0x8]
    const auto address=(s.cx+0x00000008u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x437593: d94104 FLD float ptr [ECX + 0x4]
    const auto address=(s.cx+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x437596: d901 FLD float ptr [ECX]
    const auto address=(s.cx);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x437598: d9c0 FLD ST0
    s.fp.load_st0();
  }
  { // 0x43759a: d8c9 FMUL ST1
    extended::multiply_st1(s.fp);
  }
  { // 0x43759c: d9c2 FLD ST2
    s.fp.load_st2();
  }
  { // 0x43759e: d8cb FMUL ST3
    extended::multiply_st3(s.fp);
  }
  { // 0x4375a0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x4375a3: dec1 FADDP
    s.fp.add_pop();
  }
  { // 0x4375a5: d9c3 FLD ST3
    extended::load_st3(s.fp);
  }
  { // 0x4375a7: d8cc FMUL ST4
    extended::multiply_st4(s.fp);
  }
  { // 0x4375a9: dec1 FADDP
    s.fp.add_pop();
  }
  { // 0x4375ab: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x4375ae: ddd8 FSTP ST0
    s.fp.pop_st0();
  }
  { // 0x4375b0: ddd8 FSTP ST0
    s.fp.pop_st0();
  }
  { // 0x4375b2: ddd8 FSTP ST0
    s.fp.pop_st0();
  }
  { // 0x4375b4: e8c72a0800 CALL 0x004ba080
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x000ba080u,0x004375b9u);
    flags=s.arithmetic_flags;
  }
  { // 0x4375b9: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x4375bc: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0007cc60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x47cc60: db4104 FILD dword ptr [ECX + 0x4]
    const auto address=(s.cx+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x47cc63: db01 FILD dword ptr [ECX]
    const auto address=(s.cx);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x47cc65: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x47cc68: d9c0 FLD ST0
    s.fp.load_st0();
  }
  { // 0x47cc6a: d8c9 FMUL ST1
    extended::multiply_st1(s.fp);
  }
  { // 0x47cc6c: d9c2 FLD ST2
    s.fp.load_st2();
  }
  { // 0x47cc6e: d8cb FMUL ST3
    extended::multiply_st3(s.fp);
  }
  { // 0x47cc70: dec1 FADDP
    s.fp.add_pop();
  }
  { // 0x47cc72: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x47cc75: ddd8 FSTP ST0
    s.fp.pop_st0();
  }
  { // 0x47cc77: ddd8 FSTP ST0
    s.fp.pop_st0();
  }
  { // 0x47cc79: e802d40300 CALL 0x004ba080
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x000ba080u,0x0047cc7eu);
    flags=s.arithmetic_flags;
  }
  { // 0x47cc7e: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x47cc81: e9cadd2e00 JMP 0x0076aa50
    s.arithmetic_flags=flags;
    invoke_closed_tail(m,s,f,0x36aa50u); return;
  }
}
void f_0007f790(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x47f790: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x47f791: 894c2400 MOV dword ptr [ESP],ECX
    m.w32((f.sp), s.cx);
  }
  { // 0x47f795: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x47f798: db442408 FILD dword ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x47f79c: dc4c2410 FMUL double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto operand=read64(m,address);
    s.fp.multiply64(operand);
  }
  { // 0x47f7a0: dc0da88d7800 FMUL double ptr [0x00788da8]
    const auto address=(0x00788da8u);
    const auto operand=read64(m,address);
    s.fp.multiply64(operand);
  }
  { // 0x47f7a6: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x47f7a9: e8d2a80300 CALL 0x004ba080
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x000ba080u,0x0047f7aeu);
    flags=s.arithmetic_flags;
  }
  { // 0x47f7ae: e89db22e00 CALL 0x0076aa50
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x0036aa50u,0x0047f7b3u);
    flags=s.arithmetic_flags;
  }
  { // 0x47f7b3: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x47f7b6: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00096950(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x496950: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  { // 0x496953: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x496954: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x496956: 8a4618 MOV AL,byte ptr [ESI + 0x18]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000018u)));
  }
  { // 0x496959: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x49695b: 7506 JNZ 0x00496963
    if(integer::condition("JNZ",flags)) goto L00496963;
  }
  { // 0x49695d: 807e1901 CMP byte ptr [ESI + 0x19],0x1
    (void)integer::sub(m.r8((s.si+0x00000019u)),0x00000001u,8,flags);
  }
  { // 0x496961: 7431 JZ 0x00496994
    if(integer::condition("JZ",flags)) goto L00496994;
  }
  L00496963: { // 0x496963: dd442418 FLD double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x496967: dc0d08667800 FMUL double ptr [0x00786608]
    const auto address=(0x00786608u);
    const auto operand=read64(m,address);
    s.fp.multiply64(operand);
  }
  { // 0x49696d: c6461801 MOV byte ptr [ESI + 0x18],0x1
    m.w8((s.si+0x00000018u), 0x00000001u);
  }
  { // 0x496971: dd16 FST double ptr [ESI]
    const auto address=(s.si);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  { // 0x496973: e8d8402d00 CALL 0x0076aa50
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x0036aa50u,0x00496978u);
    flags=s.arithmetic_flags;
  }
  { // 0x496978: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  { // 0x49697e: 8d5608 LEA EDX,[ESI + 0x8]
    s.dx = (s.si+0x00000008u);
  }
  { // 0x496981: c6461901 MOV byte ptr [ESI + 0x19],0x1
    m.w8((s.si+0x00000019u), 0x00000001u);
  }
  { // 0x496985: 890a MOV dword ptr [EDX],ECX
    m.w32((s.dx), s.cx);
  }
  { // 0x496987: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x49698b: 894a04 MOV dword ptr [EDX + 0x4],ECX
    m.w32((s.dx+0x00000004u), s.cx);
  }
  { // 0x49698e: 894208 MOV dword ptr [EDX + 0x8],EAX
    m.w32((s.dx+0x00000008u), s.ax);
  }
  { // 0x496991: 89420c MOV dword ptr [EDX + 0xc],EAX
    m.w32((s.dx+0x0000000cu), s.ax);
  }
  L00496994: { // 0x496994: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x496995: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x496998: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_000969a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4969a0: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  { // 0x4969a3: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4969a4: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4969a6: 8a4618 MOV AL,byte ptr [ESI + 0x18]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000018u)));
  }
  { // 0x4969a9: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4969ab: 7507 JNZ 0x004969b4
    if(integer::condition("JNZ",flags)) goto L004969b4;
  }
  { // 0x4969ad: 8a4619 MOV AL,byte ptr [ESI + 0x19]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000019u)));
  }
  { // 0x4969b0: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4969b2: 7431 JZ 0x004969e5
    if(integer::condition("JZ",flags)) goto L004969e5;
  }
  L004969b4: { // 0x4969b4: dd442418 FLD double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x4969b8: dc0d08667800 FMUL double ptr [0x00786608]
    const auto address=(0x00786608u);
    const auto operand=read64(m,address);
    s.fp.multiply64(operand);
  }
  { // 0x4969be: c6461801 MOV byte ptr [ESI + 0x18],0x1
    m.w8((s.si+0x00000018u), 0x00000001u);
  }
  { // 0x4969c2: dd16 FST double ptr [ESI]
    const auto address=(s.si);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  { // 0x4969c4: e887402d00 CALL 0x0076aa50
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x0036aa50u,0x004969c9u);
    flags=s.arithmetic_flags;
  }
  { // 0x4969c9: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  { // 0x4969cf: 8d5608 LEA EDX,[ESI + 0x8]
    s.dx = (s.si+0x00000008u);
  }
  { // 0x4969d2: c6461900 MOV byte ptr [ESI + 0x19],0x0
    m.w8((s.si+0x00000019u), 0x00000000u);
  }
  { // 0x4969d6: 890a MOV dword ptr [EDX],ECX
    m.w32((s.dx), s.cx);
  }
  { // 0x4969d8: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x4969dc: 894a04 MOV dword ptr [EDX + 0x4],ECX
    m.w32((s.dx+0x00000004u), s.cx);
  }
  { // 0x4969df: 894208 MOV dword ptr [EDX + 0x8],EAX
    m.w32((s.dx+0x00000008u), s.ax);
  }
  { // 0x4969e2: 89420c MOV dword ptr [EDX + 0xc],EAX
    m.w32((s.dx+0x0000000cu), s.ax);
  }
  L004969e5: { // 0x4969e5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4969e6: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x4969e9: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_000ba0f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4ba0f0: dd442404 FLD double ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x4ba0f4: d80d38317c00 FMUL float ptr [0x007c3138]
    const auto address=(0x007c3138u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x4ba0fa: e851092b00 CALL 0x0076aa50
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x0036aa50u,0x004ba0ffu);
    flags=s.arithmetic_flags;
  }
  { // 0x4ba0ff: 8ac8 MOV CL,AL
    s.cx = with_al(s.cx, (s.ax & 0xffu));
  }
  { // 0x4ba101: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x4ba102: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x4ba104: 80e101 AND CL,0x1
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))&(0x00000001u),8,flags));
  }
  { // 0x4ba107: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x4ba109: 25ff1f0080 AND EAX,0x80001fff
    s.ax = integer::logical((s.ax)&(0x80001fffu),32,flags);
  }
  { // 0x4ba10e: 790e JNS 0x004ba11e
    if(integer::condition("JNS",flags)) goto L004ba11e;
  }
  { // 0x4ba110: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x4ba111: 0d00e0ffff OR EAX,0xffffe000
    s.ax = integer::logical((s.ax)|(0xffffe000u),32,flags);
  }
  { // 0x4ba116: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x4ba117: 7905 JNS 0x004ba11e
    if(integer::condition("JNS",flags)) goto L004ba11e;
  }
  { // 0x4ba119: 0500200000 ADD EAX,0x2000
    s.ax = integer::add(s.ax,0x00002000u,32,flags);
  }
  L004ba11e: { // 0x4ba11e: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x4ba120: 7408 JZ 0x004ba12a
    if(integer::condition("JZ",flags)) goto L004ba12a;
  }
  { // 0x4ba122: 3dff1f0000 CMP EAX,0x1fff
    (void)integer::sub(s.ax,0x00001fffu,32,flags);
  }
  { // 0x4ba127: 7d01 JGE 0x004ba12a
    if(integer::condition("JGE",flags)) goto L004ba12a;
  }
  { // 0x4ba129: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004ba12a: { // 0x4ba12a: d9048504a17e00 FLD float ptr [EAX*0x4 + 0x7ea104]
    const auto address=((s.ax * 0x00000004u)+0x007ea104u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x4ba131: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000ba140(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4ba140: dd442404 FLD double ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x4ba144: d80d3c317c00 FMUL float ptr [0x007c313c]
    const auto address=(0x007c313cu);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x4ba14a: e801092b00 CALL 0x0076aa50
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x0036aa50u,0x004ba14fu);
    flags=s.arithmetic_flags;
  }
  { // 0x4ba14f: 8ac8 MOV CL,AL
    s.cx = with_al(s.cx, (s.ax & 0xffu));
  }
  { // 0x4ba151: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x4ba152: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x4ba154: 80e101 AND CL,0x1
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))&(0x00000001u),8,flags));
  }
  { // 0x4ba157: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x4ba159: 25ff1f0080 AND EAX,0x80001fff
    s.ax = integer::logical((s.ax)&(0x80001fffu),32,flags);
  }
  { // 0x4ba15e: 7910 JNS 0x004ba170
    if(integer::condition("JNS",flags)) goto L004ba170;
  }
  { // 0x4ba160: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x4ba161: 0d00e0ffff OR EAX,0xffffe000
    s.ax = integer::logical((s.ax)|(0xffffe000u),32,flags);
  }
  { // 0x4ba166: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x4ba167: 7907 JNS 0x004ba170
    if(integer::condition("JNS",flags)) goto L004ba170;
  }
  { // 0x4ba169: 0500280000 ADD EAX,0x2800
    s.ax = integer::add(s.ax,0x00002800u,32,flags);
  }
  { // 0x4ba16e: eb05 JMP 0x004ba175
    goto L004ba175;
  }
  L004ba170: { // 0x4ba170: 0500080000 ADD EAX,0x800
    s.ax = integer::add(s.ax,0x00000800u,32,flags);
  }
  L004ba175: { // 0x4ba175: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x4ba177: 7408 JZ 0x004ba181
    if(integer::condition("JZ",flags)) goto L004ba181;
  }
  { // 0x4ba179: 3dff270000 CMP EAX,0x27ff
    (void)integer::sub(s.ax,0x000027ffu,32,flags);
  }
  { // 0x4ba17e: 7d01 JGE 0x004ba181
    if(integer::condition("JGE",flags)) goto L004ba181;
  }
  { // 0x4ba180: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004ba181: { // 0x4ba181: d9048504a17e00 FLD float ptr [EAX*0x4 + 0x7ea104]
    const auto address=((s.ax * 0x00000004u)+0x007ea104u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x4ba188: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000ba190(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4ba190: dd442404 FLD double ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x4ba194: dc0d80bf7800 FMUL double ptr [0x0078bf80]
    const auto address=(0x0078bf80u);
    const auto operand=read64(m,address);
    s.fp.multiply64(operand);
  }
  { // 0x4ba19a: e8b1082b00 CALL 0x0076aa50
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x0036aa50u,0x004ba19fu);
    flags=s.arithmetic_flags;
  }
  { // 0x4ba19f: 25ff0f0080 AND EAX,0x80000fff
    s.ax = integer::logical((s.ax)&(0x80000fffu),32,flags);
  }
  { // 0x4ba1a4: 790e JNS 0x004ba1b4
    if(integer::condition("JNS",flags)) goto L004ba1b4;
  }
  { // 0x4ba1a6: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x4ba1a7: 0d00f0ffff OR EAX,0xfffff000
    s.ax = integer::logical((s.ax)|(0xfffff000u),32,flags);
  }
  { // 0x4ba1ac: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x4ba1ad: 7905 JNS 0x004ba1b4
    if(integer::condition("JNS",flags)) goto L004ba1b4;
  }
  { // 0x4ba1af: 0500100000 ADD EAX,0x1000
    s.ax = integer::add(s.ax,0x00001000u,32,flags);
  }
  L004ba1b4: { // 0x4ba1b4: d9048524817f00 FLD float ptr [EAX*0x4 + 0x7f8124]
    const auto address=((s.ax * 0x00000004u)+0x007f8124u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x4ba1bb: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000ba1c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4ba1c0: dd442404 FLD double ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x4ba1c4: d805f8677800 FADD float ptr [0x007867f8]
    const auto address=(0x007867f8u);
    const auto operand=m.r32(address);
    s.fp.add32(operand);
  }
  { // 0x4ba1ca: d80d88bf7800 FMUL float ptr [0x0078bf88]
    const auto address=(0x0078bf88u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x4ba1d0: e87b082b00 CALL 0x0076aa50
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x0036aa50u,0x004ba1d5u);
    flags=s.arithmetic_flags;
  }
  { // 0x4ba1d5: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  { // 0x4ba1d8: b914417f00 MOV ECX,0x7f4114
    s.cx = 0x007f4114u;
  }
  { // 0x4ba1dd: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x4ba1df: d901 FLD float ptr [ECX]
    const auto address=(s.cx);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x4ba1e1: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000ba1f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4ba1f0: dd442404 FLD double ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x4ba1f4: d805f8677800 FADD float ptr [0x007867f8]
    const auto address=(0x007867f8u);
    const auto operand=m.r32(address);
    s.fp.add32(operand);
  }
  { // 0x4ba1fa: d80d88bf7800 FMUL float ptr [0x0078bf88]
    const auto address=(0x0078bf88u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x4ba200: e84b082b00 CALL 0x0076aa50
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x0036aa50u,0x004ba205u);
    flags=s.arithmetic_flags;
  }
  { // 0x4ba205: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  { // 0x4ba208: b914417f00 MOV ECX,0x7f4114
    s.cx = 0x007f4114u;
  }
  { // 0x4ba20d: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x4ba20f: d901 FLD float ptr [ECX]
    const auto address=(s.cx);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x4ba211: dc2d30667800 FSUBR double ptr [0x00786630]
    const auto address=(0x00786630u);
    const auto operand=read64(m,address);
    s.fp.reverse_subtract64(operand);
  }
  { // 0x4ba217: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000ba220(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4ba220: dd442404 FLD double ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x4ba224: d9542404 FST float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto value=s.fp.store32();
    m.w32(address,value);
  }
  { // 0x4ba228: d83538018000 FDIV float ptr [0x00800138]
    const auto address=(0x00800138u);
    const auto operand=m.r32(address);
    extended::divide32(s.fp,operand);
  }
  { // 0x4ba22e: e81d082b00 CALL 0x0076aa50
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x0036aa50u,0x004ba233u);
    flags=s.arithmetic_flags;
  }
  { // 0x4ba233: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x4ba234: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  { // 0x4ba236: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x4ba238: 3d01100000 CMP EAX,0x1001
    (void)integer::sub(s.ax,0x00001001u,32,flags);
  }
  { // 0x4ba23d: 7d09 JGE 0x004ba248
    if(integer::condition("JGE",flags)) goto L004ba248;
  }
  { // 0x4ba23f: d9048534c17f00 FLD float ptr [EAX*0x4 + 0x7fc134]
    const auto address=((s.ax * 0x00000004u)+0x007fc134u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x4ba246: eb06 JMP 0x004ba24e
    goto L004ba24e;
  }
  L004ba248: { // 0x4ba248: d9058cbf7800 FLD float ptr [0x0078bf8c]
    const auto address=(0x0078bf8cu);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  L004ba24e: { // 0x4ba24e: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x4ba252: d81d38577800 FCOMP float ptr [0x00785738]
    const auto address=(0x00785738u);
    const auto operand=m.r32(address);
    s.fp.compare_pop32(operand);
  }
  { // 0x4ba258: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x4ba25a: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x4ba25d: 7402 JZ 0x004ba261
    if(integer::condition("JZ",flags)) goto L004ba261;
  }
  { // 0x4ba25f: d9e0 FCHS
    s.fp.change_sign();
  }
  L004ba261: { // 0x4ba261: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000e47a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4e47a0: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x4e47a4: d80d00df7800 FMUL float ptr [0x0078df00]
    const auto address=(0x0078df00u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x4e47aa: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4e47ab: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4e47ad: da8618540000 FIADD dword ptr [ESI + 0x5418]
    const auto address=(s.si+0x00005418u);
    const auto operand=m.r32(address);
    extended::add_integer32(s.fp,operand);
  }
  { // 0x4e47b3: e898622800 CALL 0x0076aa50
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x0036aa50u,0x004e47b8u);
    flags=s.arithmetic_flags;
  }
  { // 0x4e47b8: 898618540000 MOV dword ptr [ESI + 0x5418],EAX
    m.w32((s.si+0x00005418u), s.ax);
  }
  { // 0x4e47be: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x4e47c2: 8b0d3c86aa00 MOV ECX,dword ptr [0x00aa863c]
    s.cx = m.r32((0x00aa863cu));
  }
  { // 0x4e47c8: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  { // 0x4e47cb: 8b4634 MOV EAX,dword ptr [ESI + 0x34]
    s.ax = m.r32((s.si+0x00000034u));
  }
  { // 0x4e47ce: db82b8000000 FILD dword ptr [EDX + 0xb8]
    const auto address=(s.dx+0x000000b8u);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x4e47d4: d88848010000 FMUL float ptr [EAX + 0x148]
    const auto address=(s.ax+0x00000148u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x4e47da: d84c2408 FMUL float ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x4e47de: da864c020000 FIADD dword ptr [ESI + 0x24c]
    const auto address=(s.si+0x0000024cu);
    const auto operand=m.r32(address);
    extended::add_integer32(s.fp,operand);
  }
  { // 0x4e47e4: e867622800 CALL 0x0076aa50
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x0036aa50u,0x004e47e9u);
    flags=s.arithmetic_flags;
  }
  { // 0x4e47e9: d9442408 FLD float ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x4e47ed: 89864c020000 MOV dword ptr [ESI + 0x24c],EAX
    m.w32((s.si+0x0000024cu), s.ax);
  }
  { // 0x4e47f3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4e47f4: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00290460(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x690460: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x690461: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x690462: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x690463: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x690464: 8b3d3c86aa00 MOV EDI,dword ptr [0x00aa863c]
    s.di = m.r32((0x00aa863cu));
  }
  { // 0x69046a: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x69046c: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x69046e: 8954240c MOV dword ptr [ESP + 0xc],EDX
    m.w32((f.sp+0x0000000cu), s.dx);
  }
  { // 0x690472: 2bf9 SUB EDI,ECX
    s.di = integer::sub(s.di,s.cx,32,flags);
  }
  { // 0x690474: bb04000000 MOV EBX,0x4
    s.bx = 0x00000004u;
  }
  L00690479: { // 0x690479: d906 FLD float ptr [ESI]
    const auto address=(s.si);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x69047b: d81d38577800 FCOMP float ptr [0x00785738]
    const auto address=(0x00785738u);
    const auto operand=m.r32(address);
    s.fp.compare_pop32(operand);
  }
  { // 0x690481: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x690483: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  { // 0x690486: 751a JNZ 0x006904a2
    if(integer::condition("JNZ",flags)) goto L006904a2;
  }
  { // 0x690488: 8b0437 MOV EAX,dword ptr [EDI + ESI*0x1]
    s.ax = m.r32((s.di+(s.si * 0x00000001u)));
  }
  { // 0x69048b: db80b8000000 FILD dword ptr [EAX + 0xb8]
    const auto address=(s.ax+0x000000b8u);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x690491: d80e FMUL float ptr [ESI]
    const auto address=(s.si);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x690493: da44240c FIADD dword ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    const auto operand=m.r32(address);
    extended::add_integer32(s.fp,operand);
  }
  { // 0x690497: e8b4a50d00 CALL 0x0076aa50
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x0036aa50u,0x0069049cu);
    flags=s.arithmetic_flags;
  }
  { // 0x69049c: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  { // 0x69049e: 8954240c MOV dword ptr [ESP + 0xc],EDX
    m.w32((f.sp+0x0000000cu), s.dx);
  }
  L006904a2: { // 0x6904a2: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x6904a5: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  { // 0x6904a6: 75d1 JNZ 0x00690479
    if(integer::condition("JNZ",flags)) goto L00690479;
  }
  { // 0x6904a8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6904a9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6904aa: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  { // 0x6904ac: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6904ad: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x6904ae: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002904b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6904b0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6904b1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6904b2: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6904b3: c744240800000000 MOV dword ptr [ESP + 0x8],0x0
    m.w32((f.sp+0x00000008u), 0x00000000u);
  }
  { // 0x6904bb: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6904bd: bf04000000 MOV EDI,0x4
    s.di = 0x00000004u;
  }
  L006904c2: { // 0x6904c2: db442408 FILD dword ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x6904c6: d806 FADD float ptr [ESI]
    const auto address=(s.si);
    const auto operand=m.r32(address);
    s.fp.add32(operand);
  }
  { // 0x6904c8: e883a50d00 CALL 0x0076aa50
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x0036aa50u,0x006904cdu);
    flags=s.arithmetic_flags;
  }
  { // 0x6904cd: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x6904d0: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  { // 0x6904d1: 89442408 MOV dword ptr [ESP + 0x8],EAX
    m.w32((f.sp+0x00000008u), s.ax);
  }
  { // 0x6904d5: 75eb JNZ 0x006904c2
    if(integer::condition("JNZ",flags)) goto L006904c2;
  }
  { // 0x6904d7: db442408 FILD dword ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x6904db: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6904dc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6904dd: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x6904de: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00297f40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x697f40: 83ec18 SUB ESP,0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
  { // 0x697f43: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  { // 0x697f47: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x697f48: 8d91e40d0000 LEA EDX,[ECX + 0xde4]
    s.dx = (s.cx+0x00000de4u);
  }
  { // 0x697f4e: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  { // 0x697f52: db00 FILD dword ptr [EAX]
    const auto address=(s.ax);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x697f54: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  { // 0x697f5c: d95c2404 FSTP float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x697f60: db4004 FILD dword ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x697f63: 8d442404 LEA EAX,[ESP + 0x4]
    s.ax = (f.sp+0x00000004u);
  }
  { // 0x697f67: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x697f68: d95c240c FSTP float ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x697f6c: e80f62efff CALL 0x0058e180
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x0018e180u,0x00697f71u);
    flags=s.arithmetic_flags;
  }
  { // 0x697f71: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x697f73: 894c2404 MOV dword ptr [ESP + 0x4],ECX
    m.w32((f.sp+0x00000004u), s.cx);
  }
  { // 0x697f77: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  { // 0x697f7a: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x697f7e: 89542408 MOV dword ptr [ESP + 0x8],EDX
    m.w32((f.sp+0x00000008u), s.dx);
  }
  { // 0x697f82: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  { // 0x697f85: 8944240c MOV dword ptr [ESP + 0xc],EAX
    m.w32((f.sp+0x0000000cu), s.ax);
  }
  { // 0x697f89: e8c22a0d00 CALL 0x0076aa50
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x0036aa50u,0x00697f8eu);
    flags=s.arithmetic_flags;
  }
  { // 0x697f8e: d9442408 FLD float ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x697f92: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x697f94: e8b72a0d00 CALL 0x0076aa50
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x0036aa50u,0x00697f99u);
    flags=s.arithmetic_flags;
  }
  { // 0x697f99: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x697f9b: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  { // 0x697f9f: 8930 MOV dword ptr [EAX],ESI
    m.w32((s.ax), s.si);
  }
  { // 0x697fa1: 894804 MOV dword ptr [EAX + 0x4],ECX
    m.w32((s.ax+0x00000004u), s.cx);
  }
  { // 0x697fa4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x697fa5: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  { // 0x697fa8: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00297fb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x697fb0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x697fb3: 81f9d8020000 CMP ECX,0x2d8
    (void)integer::sub(s.cx,0x000002d8u,32,flags);
  }
  { // 0x697fb9: 894c2404 MOV dword ptr [ESP + 0x4],ECX
    m.w32((f.sp+0x00000004u), s.cx);
  }
  { // 0x697fbd: c744240000000000 MOV dword ptr [ESP],0x0
    m.w32((f.sp), 0x00000000u);
  }
  { // 0x697fc5: 7c08 JL 0x00697fcf
    if(integer::condition("JL",flags)) goto L00697fcf;
  }
  { // 0x697fc7: c744240001000000 MOV dword ptr [ESP],0x1
    m.w32((f.sp), 0x00000001u);
  }
  L00697fcf: { // 0x697fcf: db442404 FILD dword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x697fd3: dc0d905faa00 FMUL double ptr [0x00aa5f90]
    const auto address=(0x00aa5f90u);
    const auto operand=read64(m,address);
    s.fp.multiply64(operand);
  }
  { // 0x697fd9: da442400 FIADD dword ptr [ESP]
    const auto address=(f.sp);
    const auto operand=m.r32(address);
    extended::add_integer32(s.fp,operand);
  }
  { // 0x697fdd: dc0528577800 FADD double ptr [0x00785728]
    const auto address=(0x00785728u);
    const auto operand=read64(m,address);
    s.fp.add64(operand);
  }
  { // 0x697fe3: e8682a0d00 CALL 0x0076aa50
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x0036aa50u,0x00697fe8u);
    flags=s.arithmetic_flags;
  }
  { // 0x697fe8: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x697feb: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00297ff0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x697ff0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x697ff1: 894c2400 MOV dword ptr [ESP],ECX
    m.w32((f.sp), s.cx);
  }
  { // 0x697ff5: db442400 FILD dword ptr [ESP]
    const auto address=(f.sp);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x697ff9: dc2528577800 FSUB double ptr [0x00785728]
    const auto address=(0x00785728u);
    const auto operand=read64(m,address);
    s.fp.subtract64(operand);
  }
  { // 0x697fff: dc0d2860aa00 FMUL double ptr [0x00aa6028]
    const auto address=(0x00aa6028u);
    const auto operand=read64(m,address);
    s.fp.multiply64(operand);
  }
  { // 0x698005: e8462a0d00 CALL 0x0076aa50
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x0036aa50u,0x0069800au);
    flags=s.arithmetic_flags;
  }
  { // 0x69800a: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x69800b: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002dd410(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6dd410: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x6dd414: 8b5124 MOV EDX,dword ptr [ECX + 0x24]
    s.dx = m.r32((s.cx+0x00000024u));
  }
  { // 0x6dd417: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x6dd419: 7314 JNC 0x006dd42f
    if(integer::condition("JNC",flags)) goto L006dd42f;
  }
  { // 0x6dd41b: 8b4918 MOV ECX,dword ptr [ECX + 0x18]
    s.cx = m.r32((s.cx+0x00000018u));
  }
  { // 0x6dd41e: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  { // 0x6dd421: d98284020000 FLD float ptr [EDX + 0x284]
    const auto address=(s.dx+0x00000284u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x6dd427: e824d60800 CALL 0x0076aa50
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x0036aa50u,0x006dd42cu);
    flags=s.arithmetic_flags;
  }
  { // 0x6dd42c: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L006dd42f: { // 0x6dd42f: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6dd431: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_003105e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7105e0: 8b0495e8377e00 MOV EAX,dword ptr [EDX*0x4 + 0x7e37e8]
    s.ax = m.r32(((s.dx * 0x00000004u)+0x007e37e8u));
  }
  { // 0x7105e7: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x7105e8: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x7105e9: 8b2c95fc377e00 MOV EBP,dword ptr [EDX*0x4 + 0x7e37fc]
    s.bp = m.r32(((s.dx * 0x00000004u)+0x007e37fcu));
  }
  { // 0x7105f0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7105f1: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x7105f3: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  { // 0x7105f5: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x7105f7: 7e4a JLE 0x00710643
    if(integer::condition("JLE",flags)) goto L00710643;
  }
  { // 0x7105f9: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x7105fa: 8d7804 LEA EDI,[EAX + 0x4]
    s.di = (s.ax+0x00000004u);
  }
  L007105fd: { // 0x7105fd: d947fc FLD float ptr [EDI + -0x4]
    const auto address=(s.di-0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x710600: d80b FMUL float ptr [EBX]
    const auto address=(s.bx);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x710602: d94704 FLD float ptr [EDI + 0x4]
    const auto address=(s.di+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x710605: d84b08 FMUL float ptr [EBX + 0x8]
    const auto address=(s.bx+0x00000008u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x710608: dec1 FADDP
    s.fp.add_pop();
  }
  { // 0x71060a: d94304 FLD float ptr [EBX + 0x4]
    const auto address=(s.bx+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x71060d: d80f FMUL float ptr [EDI]
    const auto address=(s.di);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x71060f: dec1 FADDP
    s.fp.add_pop();
  }
  { // 0x710611: dc1510667800 FCOM double ptr [0x00786610]
    const auto address=(0x00786610u);
    const auto operand=read64(m,address);
    extended::compare64(s.fp,operand);
  }
  { // 0x710617: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x710619: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x71061c: 740b JZ 0x00710629
    if(integer::condition("JZ",flags)) goto L00710629;
  }
  { // 0x71061e: ddd8 FSTP ST0
    s.fp.pop_st0();
  }
  { // 0x710620: c6869008ae0000 MOV byte ptr [ESI + 0xae0890],0x0
    m.w8((s.si+0x00ae0890u), 0x00000000u);
  }
  { // 0x710627: eb11 JMP 0x0071063a
    goto L0071063a;
  }
  L00710629: { // 0x710629: d80dd0987900 FMUL float ptr [0x007998d0]
    const auto address=(0x007998d0u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x71062f: e81ca40500 CALL 0x0076aa50
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x0036aa50u,0x00710634u);
    flags=s.arithmetic_flags;
  }
  { // 0x710634: 88869008ae00 MOV byte ptr [ESI + 0xae0890],AL
    m.w8((s.si+0x00ae0890u), (s.ax & 0xffu));
  }
  L0071063a: { // 0x71063a: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x71063b: 83c70c ADD EDI,0xc
    s.di = integer::add(s.di,0x0000000cu,32,flags);
  }
  { // 0x71063e: 3bf5 CMP ESI,EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  { // 0x710640: 7cbb JL 0x007105fd
    if(integer::condition("JL",flags)) goto L007105fd;
  }
  { // 0x710642: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00710643: { // 0x710643: b010 MOV AL,0x10
    s.ax = with_al(s.ax, 0x00000010u);
  }
  { // 0x710645: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x710646: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x710647: a28f09ae00 MOV [0x00ae098f],AL
    m.w8((0x00ae098fu), (s.ax & 0xffu));
  }
  { // 0x71064c: a28e09ae00 MOV [0x00ae098e],AL
    m.w8((0x00ae098eu), (s.ax & 0xffu));
  }
  { // 0x710651: a28d09ae00 MOV [0x00ae098d],AL
    m.w8((0x00ae098du), (s.ax & 0xffu));
  }
  { // 0x710656: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x710657: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00316c80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x716c80: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  { // 0x716c83: d9442414 FLD float ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x716c87: dc2d08577800 FSUBR double ptr [0x00785708]
    const auto address=(0x00785708u);
    const auto operand=read64(m,address);
    s.fp.reverse_subtract64(operand);
  }
  { // 0x716c8d: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x716c8e: 8b5c2414 MOV EBX,dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  { // 0x716c92: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x716c93: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x716c94: db03 FILD dword ptr [EBX]
    const auto address=(s.bx);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x716c96: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  { // 0x716c98: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x716c99: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x716c9b: d84c2424 FMUL float ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x716c9f: db06 FILD dword ptr [ESI]
    const auto address=(s.si);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x716ca1: d8ca FMUL ST2
    extended::multiply_st2(s.fp);
  }
  { // 0x716ca3: dec1 FADDP
    s.fp.add_pop();
  }
  { // 0x716ca5: e8a63d0500 CALL 0x0076aa50
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x0036aa50u,0x00716caau);
    flags=s.arithmetic_flags;
  }
  { // 0x716caa: db4304 FILD dword ptr [EBX + 0x4]
    const auto address=(s.bx+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x716cad: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  { // 0x716caf: d84c2424 FMUL float ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x716cb3: db4604 FILD dword ptr [ESI + 0x4]
    const auto address=(s.si+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x716cb6: d8ca FMUL ST2
    extended::multiply_st2(s.fp);
  }
  { // 0x716cb8: dec1 FADDP
    s.fp.add_pop();
  }
  { // 0x716cba: e8913d0500 CALL 0x0076aa50
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x0036aa50u,0x00716cbfu);
    flags=s.arithmetic_flags;
  }
  { // 0x716cbf: db4308 FILD dword ptr [EBX + 0x8]
    const auto address=(s.bx+0x00000008u);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x716cc2: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  { // 0x716cc6: d84c2424 FMUL float ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x716cca: db4608 FILD dword ptr [ESI + 0x8]
    const auto address=(s.si+0x00000008u);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x716ccd: d8ca FMUL ST2
    extended::multiply_st2(s.fp);
  }
  { // 0x716ccf: dec1 FADDP
    s.fp.add_pop();
  }
  { // 0x716cd1: e87a3d0500 CALL 0x0076aa50
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x0036aa50u,0x00716cd6u);
    flags=s.arithmetic_flags;
  }
  { // 0x716cd6: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  { // 0x716cda: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x716cdc: ddd8 FSTP ST0
    s.fp.pop_st0();
  }
  { // 0x716cde: 8929 MOV dword ptr [ECX],EBP
    m.w32((s.cx), s.bp);
  }
  { // 0x716ce0: 895104 MOV dword ptr [ECX + 0x4],EDX
    m.w32((s.cx+0x00000004u), s.dx);
  }
  { // 0x716ce3: 894108 MOV dword ptr [ECX + 0x8],EAX
    m.w32((s.cx+0x00000008u), s.ax);
  }
  { // 0x716ce6: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x716ce8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x716ce9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x716cea: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x716ceb: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x716cec: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x716cef: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00316d00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x716d00: d9442408 FLD float ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x716d04: dc2d08577800 FSUBR double ptr [0x00785708]
    const auto address=(0x00785708u);
    const auto operand=read64(m,address);
    s.fp.reverse_subtract64(operand);
  }
  { // 0x716d0a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x716d0b: 8b5c2408 MOV EBX,dword ptr [ESP + 0x8]
    s.bx = m.r32((f.sp+0x00000008u));
  }
  { // 0x716d0f: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x716d10: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x716d11: db03 FILD dword ptr [EBX]
    const auto address=(s.bx);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x716d13: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x716d14: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x716d16: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x716d18: d84c2418 FMUL float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x716d1c: db07 FILD dword ptr [EDI]
    const auto address=(s.di);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x716d1e: d8ca FMUL ST2
    extended::multiply_st2(s.fp);
  }
  { // 0x716d20: dec1 FADDP
    s.fp.add_pop();
  }
  { // 0x716d22: e8293d0500 CALL 0x0076aa50
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x0036aa50u,0x00716d27u);
    flags=s.arithmetic_flags;
  }
  { // 0x716d27: db4304 FILD dword ptr [EBX + 0x4]
    const auto address=(s.bx+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x716d2a: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  { // 0x716d2c: d84c2418 FMUL float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x716d30: db4704 FILD dword ptr [EDI + 0x4]
    const auto address=(s.di+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x716d33: d8ca FMUL ST2
    extended::multiply_st2(s.fp);
  }
  { // 0x716d35: dec1 FADDP
    s.fp.add_pop();
  }
  { // 0x716d37: e8143d0500 CALL 0x0076aa50
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x0036aa50u,0x00716d3cu);
    flags=s.arithmetic_flags;
  }
  { // 0x716d3c: 892e MOV dword ptr [ESI],EBP
    m.w32((s.si), s.bp);
  }
  { // 0x716d3e: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  { // 0x716d41: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x716d43: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x716d44: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x716d45: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x716d46: ddd8 FSTP ST0
    s.fp.pop_st0();
  }
  { // 0x716d48: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x716d49: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
} // namespace
const std::array<Entry,26>& entries_a() {
  static const std::array<Entry,26> entries{{
    {0x1b750u,f_0001b750},
    {0x1b780u,f_0001b780},
    {0x1b7c0u,f_0001b7c0},
    {0x1b830u,f_0001b830},
    {0x36e00u,f_00036e00},
    {0x37590u,f_00037590},
    {0x7cc60u,f_0007cc60},
    {0x7f790u,f_0007f790},
    {0x96950u,f_00096950},
    {0x969a0u,f_000969a0},
    {0xba0f0u,f_000ba0f0},
    {0xba140u,f_000ba140},
    {0xba190u,f_000ba190},
    {0xba1c0u,f_000ba1c0},
    {0xba1f0u,f_000ba1f0},
    {0xba220u,f_000ba220},
    {0xe47a0u,f_000e47a0},
    {0x290460u,f_00290460},
    {0x2904b0u,f_002904b0},
    {0x297f40u,f_00297f40},
    {0x297fb0u,f_00297fb0},
    {0x297ff0u,f_00297ff0},
    {0x2dd410u,f_002dd410},
    {0x3105e0u,f_003105e0},
    {0x316c80u,f_00316c80},
    {0x316d00u,f_00316d00},
  }}; return entries;
}
} // namespace ra2::recovered::floating_callers_b40
