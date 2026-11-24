#include "recovered/recovery_b114_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b114 {
namespace {
void f_0007f5d0(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_0007f5d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0047f5d0: { // 0x47f5d0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0047f5d1: { // 0x47f5d1: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L0047f5d3: { // 0x47f5d3: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L0047f5d6: { // 0x47f5d6: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  L0047f5d9: { // 0x47f5d9: 8b450c MOV EAX,dword ptr [EBP + 0xc]
    s.ax = m.r32((s.bp+0x0000000cu));
  }
  L0047f5dc: { // 0x47f5dc: 89542400 MOV dword ptr [ESP],EDX
    m.w32((f.sp), s.dx);
  }
  L0047f5e0: { // 0x47f5e0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0047f5e2: { // 0x47f5e2: 7e18 JLE 0x0047f5fc
    if(integer::condition("JLE",flags)) goto L0047f5fc;
  }
  L0047f5e4: { // 0x47f5e4: 8b4518 MOV EAX,dword ptr [EBP + 0x18]
    s.ax = m.r32((s.bp+0x00000018u));
  }
  L0047f5e7: { // 0x47f5e7: c700127cd3f4 MOV dword ptr [EAX],0xf4d37c12
    m.w32((s.ax), 0xf4d37c12u);
  }
  L0047f5ed: { // 0x47f5ed: c74004d921e93f MOV dword ptr [EAX + 0x4],0x3fe921d9
    m.w32((s.ax+0x00000004u), 0x3fe921d9u);
  }
  L0047f5f4: { // 0x47f5f4: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047f5f6: { // 0x47f5f6: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L0047f5f8: { // 0x47f5f8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0047f5f9: { // 0x47f5f9: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
  L0047f5fc: { // 0x47f5fc: db4508 FILD dword ptr [EBP + 0x8]
    const auto address=(s.bp+0x00000008u);
    s.fp.load_integer32(m.r32(address));
  }
  L0047f5ff: { // 0x47f5ff: dc1d10667800 FCOMP double ptr [0x00786610]
    const auto address=(0x00786610u);
    s.fp.compare_pop64(read64(m,address));
  }
  L0047f605: { // 0x47f605: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0047f607: { // 0x47f607: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L0047f60a: { // 0x47f60a: 7407 JZ 0x0047f613
    if(integer::condition("JZ",flags)) goto L0047f613;
  }
  L0047f60c: { // 0x47f60c: c7450800000000 MOV dword ptr [EBP + 0x8],0x0
    m.w32((s.bp+0x00000008u), 0x00000000u);
  }
  L0047f613: { // 0x47f613: db4508 FILD dword ptr [EBP + 0x8]
    const auto address=(s.bp+0x00000008u);
    s.fp.load_integer32(m.r32(address));
  }
  L0047f616: { // 0x47f616: dd5c2408 FSTP double ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0047f61a: { // 0x47f61a: db450c FILD dword ptr [EBP + 0xc]
    const auto address=(s.bp+0x0000000cu);
    s.fp.load_integer32(m.r32(address));
  }
  L0047f61d: { // 0x47f61d: dd542410 FST double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L0047f621: { // 0x47f621: db442400 FILD dword ptr [ESP]
    const auto address=(f.sp);
    s.fp.load_integer32(m.r32(address));
  }
  L0047f625: { // 0x47f625: dd542418 FST double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L0047f629: { // 0x47f629: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L0047f62b: { // 0x47f62b: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L0047f62d: { // 0x47f62d: dd4510 FLD double ptr [EBP + 0x10]
    const auto address=(s.bp+0x00000010u);
    s.fp.load64(read64(m,address));
  }
  L0047f630: { // 0x47f630: dd442410 FLD double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load64(read64(m,address));
  }
  L0047f634: { // 0x47f634: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L0047f636: { // 0x47f636: d8ea FSUBR ST0,ST2
    numeric_b88::detail::reg<0xd8ea>(s.fp);
  }
  L0047f638: { // 0x47f638: dd5c2410 FSTP double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0047f63c: { // 0x47f63c: dd442408 FLD double ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.load64(read64(m,address));
  }
  L0047f640: { // 0x47f640: dc4c2408 FMUL double ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.multiply64(read64(m,address));
  }
  L0047f644: { // 0x47f644: dd5c2408 FSTP double ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0047f648: { // 0x47f648: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L0047f64a: { // 0x47f64a: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L0047f64c: { // 0x47f64c: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L0047f64e: { // 0x47f64e: d9ca FXCH ST2
    numeric_b88::detail::reg<0xd9ca>(s.fp);
  }
  L0047f650: { // 0x47f650: d8cc FMUL ST4
    numeric_b88::detail::reg<0xd8cc>(s.fp);
  }
  L0047f652: { // 0x47f652: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L0047f654: { // 0x47f654: dcc0 FADD ST0,ST0
    numeric_b88::detail::reg<0xdcc0>(s.fp);
  }
  L0047f656: { // 0x47f656: deea FSUBP ST2,ST0
    numeric_b88::detail::reg<0xdeea>(s.fp);
  }
  L0047f658: { // 0x47f658: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L0047f65a: { // 0x47f65a: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L0047f65c: { // 0x47f65c: dc4c2408 FMUL double ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.multiply64(read64(m,address));
  }
  L0047f660: { // 0x47f660: deea FSUBP ST2,ST0
    numeric_b88::detail::reg<0xdeea>(s.fp);
  }
  L0047f662: { // 0x47f662: d9c9 FXCH
    numeric_b88::detail::reg<0xd9c9>(s.fp);
  }
  L0047f664: { // 0x47f664: dd5c2400 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0047f668: { // 0x47f668: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0047f66a: { // 0x47f66a: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0047f66c: { // 0x47f66c: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L0047f66e: { // 0x47f66e: dec9 FMULP
    numeric_b88::detail::reg<0xdec9>(s.fp);
  }
  L0047f670: { // 0x47f670: dc742408 FDIV double ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.divide64(read64(m,address));
  }
  L0047f674: { // 0x47f674: dc0508577800 FADD double ptr [0x00785708]
    const auto address=(0x00785708u);
    s.fp.add64(read64(m,address));
  }
  L0047f67a: { // 0x47f67a: dcc0 FADD ST0,ST0
    numeric_b88::detail::reg<0xdcc0>(s.fp);
  }
  L0047f67c: { // 0x47f67c: dd542408 FST double ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L0047f680: { // 0x47f680: dd442400 FLD double ptr [ESP]
    const auto address=(f.sp);
    s.fp.load64(read64(m,address));
  }
  L0047f684: { // 0x47f684: dc1d10667800 FCOMP double ptr [0x00786610]
    const auto address=(0x00786610u);
    s.fp.compare_pop64(read64(m,address));
  }
  L0047f68a: { // 0x47f68a: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0047f68c: { // 0x47f68c: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0047f68f: { // 0x47f68f: 757f JNZ 0x0047f710
    if(integer::condition("JNZ",flags)) goto L0047f710;
  }
  L0047f691: { // 0x47f691: dc1d10667800 FCOMP double ptr [0x00786610]
    const auto address=(0x00786610u);
    s.fp.compare_pop64(read64(m,address));
  }
  L0047f697: { // 0x47f697: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0047f699: { // 0x47f699: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L0047f69c: { // 0x47f69c: 7574 JNZ 0x0047f712
    if(integer::condition("JNZ",flags)) goto L0047f712;
  }
  L0047f69e: { // 0x47f69e: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0047f6a0: { // 0x47f6a0: 7518 JNZ 0x0047f6ba
    if(integer::condition("JNZ",flags)) goto L0047f6ba;
  }
  L0047f6a2: { // 0x47f6a2: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L0047f6a6: { // 0x47f6a6: 8b4c2400 MOV ECX,dword ptr [ESP]
    s.cx = m.r32((f.sp));
  }
  L0047f6aa: { // 0x47f6aa: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0047f6ab: { // 0x47f6ab: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0047f6ac: { // 0x47f6ac: e8cfa90300 CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,4716209u); flags=s.arithmetic_flags;
  }
  L0047f6b1: { // 0x47f6b1: dc442418 FADD double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.add64(read64(m,address));
  }
  L0047f6b5: { // 0x47f6b5: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0047f6b8: { // 0x47f6b8: eb16 JMP 0x0047f6d0
    goto L0047f6d0;
  }
  L0047f6ba: { // 0x47f6ba: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L0047f6be: { // 0x47f6be: 8b442400 MOV EAX,dword ptr [ESP]
    s.ax = m.r32((f.sp));
  }
  L0047f6c2: { // 0x47f6c2: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0047f6c3: { // 0x47f6c3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0047f6c4: { // 0x47f6c4: e8b7a90300 CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,4716233u); flags=s.arithmetic_flags;
  }
  L0047f6c9: { // 0x47f6c9: dc6c2418 FSUBR double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.reverse_subtract64(read64(m,address));
  }
  L0047f6cd: { // 0x47f6cd: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0047f6d0: { // 0x47f6d0: dc742408 FDIV double ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.divide64(read64(m,address));
  }
  L0047f6d4: { // 0x47f6d4: dd542400 FST double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L0047f6d8: { // 0x47f6d8: dc1d10667800 FCOMP double ptr [0x00786610]
    const auto address=(0x00786610u);
    s.fp.compare_pop64(read64(m,address));
  }
  L0047f6de: { // 0x47f6de: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0047f6e0: { // 0x47f6e0: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0047f6e3: { // 0x47f6e3: 752d JNZ 0x0047f712
    if(integer::condition("JNZ",flags)) goto L0047f712;
  }
  L0047f6e5: { // 0x47f6e5: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L0047f6e9: { // 0x47f6e9: 8b542400 MOV EDX,dword ptr [ESP]
    s.dx = m.r32((f.sp));
  }
  L0047f6ed: { // 0x47f6ed: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0047f6ee: { // 0x47f6ee: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0047f6ef: { // 0x47f6ef: e88ca90300 CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,4716276u); flags=s.arithmetic_flags;
  }
  L0047f6f4: { // 0x47f6f4: dc742420 FDIV double ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.divide64(read64(m,address));
  }
  L0047f6f8: { // 0x47f6f8: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0047f6fb: { // 0x47f6fb: e8f0aa0300 CALL 0x004ba1f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba1f0u,4716288u); flags=s.arithmetic_flags;
  }
  L0047f700: { // 0x47f700: 8b4518 MOV EAX,dword ptr [EBP + 0x18]
    s.ax = m.r32((s.bp+0x00000018u));
  }
  L0047f703: { // 0x47f703: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0047f706: { // 0x47f706: dd18 FSTP double ptr [EAX]
    const auto address=(s.ax);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0047f708: { // 0x47f708: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047f70a: { // 0x47f70a: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L0047f70c: { // 0x47f70c: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0047f70d: { // 0x47f70d: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
  L0047f710: { // 0x47f710: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0047f712: { // 0x47f712: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0047f714: { // 0x47f714: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L0047f716: { // 0x47f716: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0047f717: { // 0x47f717: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
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
case 4715984u:f_0007f5d0(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
default:throw std::domain_error("recovery114 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0047f4d0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0047f4d0: { // 0x47f4d0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0047f4d3: { // 0x47f4d3: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L0047f4d7: { // 0x47f4d7: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0047f4d8: { // 0x47f4d8: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0047f4d9: { // 0x47f4d9: 8b6c241c MOV EBP,dword ptr [ESP + 0x1c]
    s.bp = m.r32((f.sp+0x0000001cu));
  }
  L0047f4dd: { // 0x47f4dd: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0047f4de: { // 0x47f4de: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0047f4df: { // 0x47f4df: 8b7c2428 MOV EDI,dword ptr [ESP + 0x28]
    s.di = m.r32((f.sp+0x00000028u));
  }
  L0047f4e3: { // 0x47f4e3: 8ad9 MOV BL,CL
    s.bx = with_al(s.bx, (s.cx & 0xffu));
  }
  L0047f4e5: { // 0x47f4e5: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L0047f4e7: { // 0x47f4e7: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L0047f4eb: { // 0x47f4eb: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L0047f4ef: { // 0x47f4ef: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0047f4f0: { // 0x47f4f0: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0047f4f1: { // 0x47f4f1: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0047f4f2: { // 0x47f4f2: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0047f4f3: { // 0x47f4f3: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0047f4f4: { // 0x47f4f4: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L0047f4f6: { // 0x47f4f6: 8acb MOV CL,BL
    s.cx = with_al(s.cx, (s.bx & 0xffu));
  }
  L0047f4f8: { // 0x47f4f8: e8d3000000 CALL 0x0047f5d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047f5d0u,4715773u); flags=s.arithmetic_flags;
  }
  L0047f4fd: { // 0x47f4fd: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0047f4ff: { // 0x47f4ff: 0f84bc000000 JZ 0x0047f5c1
    if(integer::condition("JZ",flags)) goto L0047f5c1;
  }
  L0047f505: { // 0x47f505: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L0047f507: { // 0x47f507: 7430 JZ 0x0047f539
    if(integer::condition("JZ",flags)) goto L0047f539;
  }
  L0047f509: { // 0x47f509: dd442424 FLD double ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.load64(read64(m,address));
  }
  L0047f50d: { // 0x47f50d: dc2530667800 FSUB double ptr [0x00786630]
    const auto address=(0x00786630u);
    s.fp.subtract64(read64(m,address));
  }
  L0047f513: { // 0x47f513: dc0d28667800 FMUL double ptr [0x00786628]
    const auto address=(0x00786628u);
    s.fp.multiply64(read64(m,address));
  }
  L0047f519: { // 0x47f519: e832b52e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4715806u); flags=s.arithmetic_flags;
  }
  L0047f51e: { // 0x47f51e: 6689442420 MOV word ptr [ESP + 0x20],AX
    m.w16((f.sp+0x00000020u), (s.ax & 0xffffu));
  }
  L0047f523: { // 0x47f523: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L0047f527: { // 0x47f527: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L0047f52b: { // 0x47f52b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0047f52c: { // 0x47f52c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047f52d: { // 0x47f52d: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L0047f52f: { // 0x47f52f: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0047f530: { // 0x47f530: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047f532: { // 0x47f532: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0047f533: { // 0x47f533: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0047f536: { // 0x47f536: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0047f539: { // 0x47f539: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0047f53d: { // 0x47f53d: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L0047f541: { // 0x47f541: 8d542410 LEA EDX,[ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  L0047f545: { // 0x47f545: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0047f546: { // 0x47f546: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0047f547: { // 0x47f547: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0047f548: { // 0x47f548: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0047f549: { // 0x47f549: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0047f54a: { // 0x47f54a: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0047f54b: { // 0x47f54b: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L0047f54d: { // 0x47f54d: 32c9 XOR CL,CL
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))^((s.cx & 0xffu)),8,flags));
  }
  L0047f54f: { // 0x47f54f: e87c000000 CALL 0x0047f5d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047f5d0u,4715860u); flags=s.arithmetic_flags;
  }
  L0047f554: { // 0x47f554: dd442410 FLD double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load64(read64(m,address));
  }
  L0047f558: { // 0x47f558: dc5c2424 FCOMP double ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.compare_pop64(read64(m,address));
  }
  L0047f55c: { // 0x47f55c: dd442424 FLD double ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.load64(read64(m,address));
  }
  L0047f560: { // 0x47f560: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0047f562: { // 0x47f562: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0047f565: { // 0x47f565: 742e JZ 0x0047f595
    if(integer::condition("JZ",flags)) goto L0047f595;
  }
  L0047f567: { // 0x47f567: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L0047f569: { // 0x47f569: dc2530667800 FSUB double ptr [0x00786630]
    const auto address=(0x00786630u);
    s.fp.subtract64(read64(m,address));
  }
  L0047f56f: { // 0x47f56f: dc0d28667800 FMUL double ptr [0x00786628]
    const auto address=(0x00786628u);
    s.fp.multiply64(read64(m,address));
  }
  L0047f575: { // 0x47f575: e8d6b42e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4715898u); flags=s.arithmetic_flags;
  }
  L0047f57a: { // 0x47f57a: 8b54242c MOV EDX,dword ptr [ESP + 0x2c]
    s.dx = m.r32((f.sp+0x0000002cu));
  }
  L0047f57e: { // 0x47f57e: 6689442420 MOV word ptr [ESP + 0x20],AX
    m.w16((f.sp+0x00000020u), (s.ax & 0xffffu));
  }
  L0047f583: { // 0x47f583: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L0047f587: { // 0x47f587: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0047f588: { // 0x47f588: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047f589: { // 0x47f589: 8902 MOV dword ptr [EDX],EAX
    m.w32((s.dx), s.ax);
  }
  L0047f58b: { // 0x47f58b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0047f58c: { // 0x47f58c: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047f58e: { // 0x47f58e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0047f58f: { // 0x47f58f: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0047f592: { // 0x47f592: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0047f595: { // 0x47f595: dc2530667800 FSUB double ptr [0x00786630]
    const auto address=(0x00786630u);
    s.fp.subtract64(read64(m,address));
  }
  L0047f59b: { // 0x47f59b: dc0d28667800 FMUL double ptr [0x00786628]
    const auto address=(0x00786628u);
    s.fp.multiply64(read64(m,address));
  }
  L0047f5a1: { // 0x47f5a1: e8aab42e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4715942u); flags=s.arithmetic_flags;
  }
  L0047f5a6: { // 0x47f5a6: 8b4c242c MOV ECX,dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L0047f5aa: { // 0x47f5aa: 6689442420 MOV word ptr [ESP + 0x20],AX
    m.w16((f.sp+0x00000020u), (s.ax & 0xffffu));
  }
  L0047f5af: { // 0x47f5af: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L0047f5b3: { // 0x47f5b3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0047f5b4: { // 0x47f5b4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047f5b5: { // 0x47f5b5: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0047f5b6: { // 0x47f5b6: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  L0047f5b8: { // 0x47f5b8: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047f5ba: { // 0x47f5ba: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0047f5bb: { // 0x47f5bb: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0047f5be: { // 0x47f5be: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0047f5c1: { // 0x47f5c1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0047f5c2: { // 0x47f5c2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047f5c3: { // 0x47f5c3: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0047f5c4: { // 0x47f5c4: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0047f5c6: { // 0x47f5c6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0047f5c7: { // 0x47f5c7: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0047f5ca: { // 0x47f5ca: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
