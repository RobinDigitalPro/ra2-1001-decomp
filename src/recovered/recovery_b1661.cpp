#include "recovered/recovery_b1661.hpp"
#include <algorithm>
#include <array>
#include <cstdint>
#include <stdexcept>
#include <utility>
namespace ra2::recovered::b1661 {
namespace {
namespace leaf=ra2::recovered::leaf;
using namespace ra2::recovered::floating_b61;
using recovery_b566::finish; using recovery_b566::string_instruction; using recovery_b566::Kind; using recovery_b566::Repeat; using recovery_b566::reverse_divide32; using recovery_b566::reverse_divide64;
namespace integer=ra2::recovered::direct_b33::integer;
namespace numeric_b88=ra2::recovered::numeric_b88;
namespace fp=ra2::platform::x87;
using State=recovery_b566::State; using Frame=recovery_b566::Frame;
void invoke(Memory&,State&,Frame&,unsigned,unsigned,const Operations&);
void f_00318470(Memory&,State&,Frame&,const Operations&);
void f_001cd850(Memory&,State&,Frame&,const Operations&);
void f_000ba080(Memory&,State&,Frame&,const Operations&);
void f_000ba1f0(Memory&,State&,Frame&,const Operations&);
void f_0018ce60(Memory&,State&,Frame&,const Operations&);
void f_0018d7a0(Memory&,State&,Frame&,const Operations&);
void f_0018e180(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void f_00298010(Memory&,State&,Frame&,const Operations&);
void f_000ba0f0(Memory&,State&,Frame&,const Operations&);
void f_000ba140(Memory&,State&,Frame&,const Operations&);

void f_00318470(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00718470: { // 0x718470: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00718471: { // 0x718471: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L00718473: { // 0x718473: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L00718476: { // 0x718476: 81ecbc000000 SUB ESP,0xbc
    f.sp = integer::sub(f.sp,0x000000bcu,32,flags);
  }
  L0071847c: { // 0x71847c: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0071847d: { // 0x71847d: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0071847e: { // 0x71847e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0071847f: { // 0x71847f: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L00718481: { // 0x718481: 8a0d5c0cae00 MOV CL,byte ptr [0x00ae0c5c]
    s.cx = with_al(s.cx, m.r8((0x00ae0c5cu)));
  }
  L00718487: { // 0x718487: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00718489: { // 0x718489: 84c8 TEST AL,CL
    (void)integer::logical(((s.ax & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0071848b: { // 0x71848b: 0f8593020000 JNZ 0x00718724
    if(integer::condition("JNZ",flags)) goto L00718724;
  }
  L00718491: { // 0x718491: 8ad1 MOV DL,CL
    s.dx = with_al(s.dx, (s.cx & 0xffu));
  }
  L00718493: { // 0x718493: c744240c0000f0c1 MOV dword ptr [ESP + 0xc],0xc1f00000
    m.w32((f.sp+0x0000000cu), 0xc1f00000u);
  }
  L0071849b: { // 0x71849b: 0ad0 OR DL,AL
    s.dx = with_al(s.dx, integer::logical(((s.dx & 0xffu))|((s.ax & 0xffu)),8,flags));
  }
  L0071849d: { // 0x71849d: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L007184a1: { // 0x7184a1: c74424100000c8c2 MOV dword ptr [ESP + 0x10],0xc2c80000
    m.w32((f.sp+0x00000010u), 0xc2c80000u);
  }
  L007184a9: { // 0x7184a9: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L007184ad: { // 0x7184ad: 88155c0cae00 MOV byte ptr [0x00ae0c5c],DL
    m.w8((0x00ae0c5cu), (s.dx & 0xffu));
  }
  L007184b3: { // 0x7184b3: c744241400000000 MOV dword ptr [ESP + 0x14],0x0
    m.w32((f.sp+0x00000014u), 0x00000000u);
  }
  L007184bb: { // 0x7184bb: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L007184bf: { // 0x7184bf: a3c00bae00 MOV [0x00ae0bc0],EAX
    m.w32((0x00ae0bc0u), s.ax);
  }
  L007184c4: { // 0x7184c4: c744240c0000f0c1 MOV dword ptr [ESP + 0xc],0xc1f00000
    m.w32((f.sp+0x0000000cu), 0xc1f00000u);
  }
  L007184cc: { // 0x7184cc: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L007184d0: { // 0x7184d0: 890dc40bae00 MOV dword ptr [0x00ae0bc4],ECX
    m.w32((0x00ae0bc4u), s.cx);
  }
  L007184d6: { // 0x7184d6: c74424100000c842 MOV dword ptr [ESP + 0x10],0x42c80000
    m.w32((f.sp+0x00000010u), 0x42c80000u);
  }
  L007184de: { // 0x7184de: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L007184e2: { // 0x7184e2: 8915c80bae00 MOV dword ptr [0x00ae0bc8],EDX
    m.w32((0x00ae0bc8u), s.dx);
  }
  L007184e8: { // 0x7184e8: c744241400000000 MOV dword ptr [ESP + 0x14],0x0
    m.w32((f.sp+0x00000014u), 0x00000000u);
  }
  L007184f0: { // 0x7184f0: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L007184f4: { // 0x7184f4: a3cc0bae00 MOV [0x00ae0bcc],EAX
    m.w32((0x00ae0bccu), s.ax);
  }
  L007184f9: { // 0x7184f9: c744240c0000f041 MOV dword ptr [ESP + 0xc],0x41f00000
    m.w32((f.sp+0x0000000cu), 0x41f00000u);
  }
  L00718501: { // 0x718501: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L00718505: { // 0x718505: 890dd00bae00 MOV dword ptr [0x00ae0bd0],ECX
    m.w32((0x00ae0bd0u), s.cx);
  }
  L0071850b: { // 0x71850b: c74424100000c8c2 MOV dword ptr [ESP + 0x10],0xc2c80000
    m.w32((f.sp+0x00000010u), 0xc2c80000u);
  }
  L00718513: { // 0x718513: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00718517: { // 0x718517: 8915d40bae00 MOV dword ptr [0x00ae0bd4],EDX
    m.w32((0x00ae0bd4u), s.dx);
  }
  L0071851d: { // 0x71851d: c744241400000000 MOV dword ptr [ESP + 0x14],0x0
    m.w32((f.sp+0x00000014u), 0x00000000u);
  }
  L00718525: { // 0x718525: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L00718529: { // 0x718529: a3d80bae00 MOV [0x00ae0bd8],EAX
    m.w32((0x00ae0bd8u), s.ax);
  }
  L0071852e: { // 0x71852e: c744240c0000f041 MOV dword ptr [ESP + 0xc],0x41f00000
    m.w32((f.sp+0x0000000cu), 0x41f00000u);
  }
  L00718536: { // 0x718536: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L0071853a: { // 0x71853a: 890ddc0bae00 MOV dword ptr [0x00ae0bdc],ECX
    m.w32((0x00ae0bdcu), s.cx);
  }
  L00718540: { // 0x718540: c74424100000c842 MOV dword ptr [ESP + 0x10],0x42c80000
    m.w32((f.sp+0x00000010u), 0x42c80000u);
  }
  L00718548: { // 0x718548: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L0071854c: { // 0x71854c: 8915e00bae00 MOV dword ptr [0x00ae0be0],EDX
    m.w32((0x00ae0be0u), s.dx);
  }
  L00718552: { // 0x718552: c744241400000000 MOV dword ptr [ESP + 0x14],0x0
    m.w32((f.sp+0x00000014u), 0x00000000u);
  }
  L0071855a: { // 0x71855a: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L0071855e: { // 0x71855e: a3e40bae00 MOV [0x00ae0be4],EAX
    m.w32((0x00ae0be4u), s.ax);
  }
  L00718563: { // 0x718563: c744240c000008c2 MOV dword ptr [ESP + 0xc],0xc2080000
    m.w32((f.sp+0x0000000cu), 0xc2080000u);
  }
  L0071856b: { // 0x71856b: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L0071856f: { // 0x71856f: 890de80bae00 MOV dword ptr [0x00ae0be8],ECX
    m.w32((0x00ae0be8u), s.cx);
  }
  L00718575: { // 0x718575: c7442410000030c2 MOV dword ptr [ESP + 0x10],0xc2300000
    m.w32((f.sp+0x00000010u), 0xc2300000u);
  }
  L0071857d: { // 0x71857d: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00718581: { // 0x718581: 8915ec0bae00 MOV dword ptr [0x00ae0bec],EDX
    m.w32((0x00ae0becu), s.dx);
  }
  L00718587: { // 0x718587: c744241400000000 MOV dword ptr [ESP + 0x14],0x0
    m.w32((f.sp+0x00000014u), 0x00000000u);
  }
  L0071858f: { // 0x71858f: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L00718593: { // 0x718593: a3f00bae00 MOV [0x00ae0bf0],EAX
    m.w32((0x00ae0bf0u), s.ax);
  }
  L00718598: { // 0x718598: c744240c000008c2 MOV dword ptr [ESP + 0xc],0xc2080000
    m.w32((f.sp+0x0000000cu), 0xc2080000u);
  }
  L007185a0: { // 0x7185a0: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L007185a4: { // 0x7185a4: 890df40bae00 MOV dword ptr [0x00ae0bf4],ECX
    m.w32((0x00ae0bf4u), s.cx);
  }
  L007185aa: { // 0x7185aa: c744241000003042 MOV dword ptr [ESP + 0x10],0x42300000
    m.w32((f.sp+0x00000010u), 0x42300000u);
  }
  L007185b2: { // 0x7185b2: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L007185b6: { // 0x7185b6: 8915f80bae00 MOV dword ptr [0x00ae0bf8],EDX
    m.w32((0x00ae0bf8u), s.dx);
  }
  L007185bc: { // 0x7185bc: c744241400000000 MOV dword ptr [ESP + 0x14],0x0
    m.w32((f.sp+0x00000014u), 0x00000000u);
  }
  L007185c4: { // 0x7185c4: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L007185c8: { // 0x7185c8: a3fc0bae00 MOV [0x00ae0bfc],EAX
    m.w32((0x00ae0bfcu), s.ax);
  }
  L007185cd: { // 0x7185cd: c744240c00000842 MOV dword ptr [ESP + 0xc],0x42080000
    m.w32((f.sp+0x0000000cu), 0x42080000u);
  }
  L007185d5: { // 0x7185d5: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L007185d9: { // 0x7185d9: 890d000cae00 MOV dword ptr [0x00ae0c00],ECX
    m.w32((0x00ae0c00u), s.cx);
  }
  L007185df: { // 0x7185df: c7442410000030c2 MOV dword ptr [ESP + 0x10],0xc2300000
    m.w32((f.sp+0x00000010u), 0xc2300000u);
  }
  L007185e7: { // 0x7185e7: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L007185eb: { // 0x7185eb: 8915040cae00 MOV dword ptr [0x00ae0c04],EDX
    m.w32((0x00ae0c04u), s.dx);
  }
  L007185f1: { // 0x7185f1: c744241400000000 MOV dword ptr [ESP + 0x14],0x0
    m.w32((f.sp+0x00000014u), 0x00000000u);
  }
  L007185f9: { // 0x7185f9: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L007185fd: { // 0x7185fd: a3080cae00 MOV [0x00ae0c08],EAX
    m.w32((0x00ae0c08u), s.ax);
  }
  L00718602: { // 0x718602: c744240c00000842 MOV dword ptr [ESP + 0xc],0x42080000
    m.w32((f.sp+0x0000000cu), 0x42080000u);
  }
  L0071860a: { // 0x71860a: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L0071860e: { // 0x71860e: 890d0c0cae00 MOV dword ptr [0x00ae0c0c],ECX
    m.w32((0x00ae0c0cu), s.cx);
  }
  L00718614: { // 0x718614: c744241000003042 MOV dword ptr [ESP + 0x10],0x42300000
    m.w32((f.sp+0x00000010u), 0x42300000u);
  }
  L0071861c: { // 0x71861c: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00718620: { // 0x718620: 8915100cae00 MOV dword ptr [0x00ae0c10],EDX
    m.w32((0x00ae0c10u), s.dx);
  }
  L00718626: { // 0x718626: c744241400000000 MOV dword ptr [ESP + 0x14],0x0
    m.w32((f.sp+0x00000014u), 0x00000000u);
  }
  L0071862e: { // 0x71862e: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L00718632: { // 0x718632: a3140cae00 MOV [0x00ae0c14],EAX
    m.w32((0x00ae0c14u), s.ax);
  }
  L00718637: { // 0x718637: c744240c0000d8c1 MOV dword ptr [ESP + 0xc],0xc1d80000
    m.w32((f.sp+0x0000000cu), 0xc1d80000u);
  }
  L0071863f: { // 0x71863f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L00718643: { // 0x718643: 890d180cae00 MOV dword ptr [0x00ae0c18],ECX
    m.w32((0x00ae0c18u), s.cx);
  }
  L00718649: { // 0x718649: c7442410000008c2 MOV dword ptr [ESP + 0x10],0xc2080000
    m.w32((f.sp+0x00000010u), 0xc2080000u);
  }
  L00718651: { // 0x718651: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00718655: { // 0x718655: 89151c0cae00 MOV dword ptr [0x00ae0c1c],EDX
    m.w32((0x00ae0c1cu), s.dx);
  }
  L0071865b: { // 0x71865b: c744241400000000 MOV dword ptr [ESP + 0x14],0x0
    m.w32((f.sp+0x00000014u), 0x00000000u);
  }
  L00718663: { // 0x718663: a3200cae00 MOV [0x00ae0c20],EAX
    m.w32((0x00ae0c20u), s.ax);
  }
  L00718668: { // 0x718668: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L0071866c: { // 0x71866c: 890d240cae00 MOV dword ptr [0x00ae0c24],ECX
    m.w32((0x00ae0c24u), s.cx);
  }
  L00718672: { // 0x718672: 8915280cae00 MOV dword ptr [0x00ae0c28],EDX
    m.w32((0x00ae0c28u), s.dx);
  }
  L00718678: { // 0x718678: c744240c0000d8c1 MOV dword ptr [ESP + 0xc],0xc1d80000
    m.w32((f.sp+0x0000000cu), 0xc1d80000u);
  }
  L00718680: { // 0x718680: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L00718684: { // 0x718684: c744241000000842 MOV dword ptr [ESP + 0x10],0x42080000
    m.w32((f.sp+0x00000010u), 0x42080000u);
  }
  L0071868c: { // 0x71868c: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00718690: { // 0x718690: c744241400000000 MOV dword ptr [ESP + 0x14],0x0
    m.w32((f.sp+0x00000014u), 0x00000000u);
  }
  L00718698: { // 0x718698: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L0071869c: { // 0x71869c: a32c0cae00 MOV [0x00ae0c2c],EAX
    m.w32((0x00ae0c2cu), s.ax);
  }
  L007186a1: { // 0x7186a1: 890d300cae00 MOV dword ptr [0x00ae0c30],ECX
    m.w32((0x00ae0c30u), s.cx);
  }
  L007186a7: { // 0x7186a7: 8915340cae00 MOV dword ptr [0x00ae0c34],EDX
    m.w32((0x00ae0c34u), s.dx);
  }
  L007186ad: { // 0x7186ad: c744240c0000d841 MOV dword ptr [ESP + 0xc],0x41d80000
    m.w32((f.sp+0x0000000cu), 0x41d80000u);
  }
  L007186b5: { // 0x7186b5: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L007186b9: { // 0x7186b9: c7442410000008c2 MOV dword ptr [ESP + 0x10],0xc2080000
    m.w32((f.sp+0x00000010u), 0xc2080000u);
  }
  L007186c1: { // 0x7186c1: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L007186c5: { // 0x7186c5: c744241400000000 MOV dword ptr [ESP + 0x14],0x0
    m.w32((f.sp+0x00000014u), 0x00000000u);
  }
  L007186cd: { // 0x7186cd: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L007186d1: { // 0x7186d1: a3380cae00 MOV [0x00ae0c38],EAX
    m.w32((0x00ae0c38u), s.ax);
  }
  L007186d6: { // 0x7186d6: 890d3c0cae00 MOV dword ptr [0x00ae0c3c],ECX
    m.w32((0x00ae0c3cu), s.cx);
  }
  L007186dc: { // 0x7186dc: 8915400cae00 MOV dword ptr [0x00ae0c40],EDX
    m.w32((0x00ae0c40u), s.dx);
  }
  L007186e2: { // 0x7186e2: c744240c0000d841 MOV dword ptr [ESP + 0xc],0x41d80000
    m.w32((f.sp+0x0000000cu), 0x41d80000u);
  }
  L007186ea: { // 0x7186ea: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L007186ee: { // 0x7186ee: c744241000000842 MOV dword ptr [ESP + 0x10],0x42080000
    m.w32((f.sp+0x00000010u), 0x42080000u);
  }
  L007186f6: { // 0x7186f6: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L007186fa: { // 0x7186fa: c744241400000000 MOV dword ptr [ESP + 0x14],0x0
    m.w32((f.sp+0x00000014u), 0x00000000u);
  }
  L00718702: { // 0x718702: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L00718706: { // 0x718706: 68b08d7100 PUSH 0x718db0
    f.push(m,0x00718db0u);
  }
  L0071870b: { // 0x71870b: a3440cae00 MOV [0x00ae0c44],EAX
    m.w32((0x00ae0c44u), s.ax);
  }
  L00718710: { // 0x718710: 890d480cae00 MOV dword ptr [0x00ae0c48],ECX
    m.w32((0x00ae0c48u), s.cx);
  }
  L00718716: { // 0x718716: 89154c0cae00 MOV dword ptr [0x00ae0c4c],EDX
    m.w32((0x00ae0c4cu), s.dx);
  }
  L0071871c: { // 0x71871c: e8a95b0500 CALL 0x0076e2ca
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076e2cau,7440161u,op); flags=s.arithmetic_flags;
  }
  L00718721: { // 0x718721: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00718724: { // 0x718724: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L00718727: { // 0x718727: 8bb79c000000 MOV ESI,dword ptr [EDI + 0x9c]
    s.si = m.r32((s.di+0x0000009cu));
  }
  L0071872d: { // 0x71872d: 8b5d0c MOV EBX,dword ptr [EBP + 0xc]
    s.bx = m.r32((s.bp+0x0000000cu));
  }
  L00718730: { // 0x718730: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00718732: { // 0x718732: d904b51c9b7900 FLD float ptr [ESI*0x4 + 0x799b1c]
    const auto address=((s.si * 0x00000004u)+0x00799b1cu);
    s.fp.load32(m.r32(address));
  }
  L00718739: { // 0x718739: 894c2428 MOV dword ptr [ESP + 0x28],ECX
    m.w32((f.sp+0x00000028u), s.cx);
  }
  L0071873d: { // 0x71873d: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  L0071873f: { // 0x71873f: d9c0 FLD st0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L00718741: { // 0x718741: dc2d08577800 FSUBR double ptr [0x00785708]
    const auto address=(0x00785708u);
    s.fp.reverse_subtract64(read64(m,address));
  }
  L00718747: { // 0x718747: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L0071874b: { // 0x71874b: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0071874e: { // 0x71874e: db442424 FILD dword ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.load_integer32(m.r32(address));
  }
  L00718752: { // 0x718752: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L00718755: { // 0x718755: 8954242c MOV dword ptr [ESP + 0x2c],EDX
    m.w32((f.sp+0x0000002cu), s.dx);
  }
  L00718759: { // 0x718759: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L0071875d: { // 0x71875d: d8ca FMUL st2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L0071875f: { // 0x71875f: db442428 FILD dword ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.load_integer32(m.r32(address));
  }
  L00718763: { // 0x718763: d8ca FMUL st2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L00718765: { // 0x718765: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L00718767: { // 0x718767: e8e4220500 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7440236u,op); flags=s.arithmetic_flags;
  }
  L0071876c: { // 0x71876c: 8b5304 MOV EDX,dword ptr [EBX + 0x4]
    s.dx = m.r32((s.bx+0x00000004u));
  }
  L0071876f: { // 0x71876f: 8944240c MOV dword ptr [ESP + 0xc],EAX
    m.w32((f.sp+0x0000000cu), s.ax);
  }
  L00718773: { // 0x718773: 89542470 MOV dword ptr [ESP + 0x70],EDX
    m.w32((f.sp+0x00000070u), s.dx);
  }
  L00718777: { // 0x718777: db442470 FILD dword ptr [ESP + 0x70]
    const auto address=(f.sp+0x00000070u);
    s.fp.load_integer32(m.r32(address));
  }
  L0071877b: { // 0x71877b: d8ca FMUL st2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L0071877d: { // 0x71877d: db44242c FILD dword ptr [ESP + 0x2c]
    const auto address=(f.sp+0x0000002cu);
    s.fp.load_integer32(m.r32(address));
  }
  L00718781: { // 0x718781: d8ca FMUL st2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L00718783: { // 0x718783: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L00718785: { // 0x718785: e8c6220500 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7440266u,op); flags=s.arithmetic_flags;
  }
  L0071878a: { // 0x71878a: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0071878e: { // 0x71878e: 8b4308 MOV EAX,dword ptr [EBX + 0x8]
    s.ax = m.r32((s.bx+0x00000008u));
  }
  L00718791: { // 0x718791: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00718795: { // 0x718795: db442418 FILD dword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load_integer32(m.r32(address));
  }
  L00718799: { // 0x718799: d8ca FMUL st2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L0071879b: { // 0x71879b: db442430 FILD dword ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.load_integer32(m.r32(address));
  }
  L0071879f: { // 0x71879f: d8ca FMUL st2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L007187a1: { // 0x7187a1: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L007187a3: { // 0x7187a3: e8a8220500 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7440296u,op); flags=s.arithmetic_flags;
  }
  L007187a8: { // 0x7187a8: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L007187ac: { // 0x7187ac: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L007187b0: { // 0x7187b0: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L007187b2: { // 0x7187b2: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L007187b4: { // 0x7187b4: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L007187b6: { // 0x7187b6: 894c2434 MOV dword ptr [ESP + 0x34],ECX
    m.w32((f.sp+0x00000034u), s.cx);
  }
  L007187ba: { // 0x7187ba: 89542438 MOV dword ptr [ESP + 0x38],EDX
    m.w32((f.sp+0x00000038u), s.dx);
  }
  L007187be: { // 0x7187be: 8944243c MOV dword ptr [ESP + 0x3c],EAX
    m.w32((f.sp+0x0000003cu), s.ax);
  }
  L007187c2: { // 0x7187c2: 7507 JNZ 0x007187cb
    if(integer::condition("JNZ",flags)) goto L007187cb;
  }
  L007187c4: { // 0x7187c4: 83c032 ADD EAX,0x32
    s.ax = integer::add(s.ax,0x00000032u,32,flags);
  }
  L007187c7: { // 0x7187c7: 8944243c MOV dword ptr [ESP + 0x3c],EAX
    m.w32((f.sp+0x0000003cu), s.ax);
  }
  L007187cb: { // 0x7187cb: d904b51c9b7900 FLD float ptr [ESI*0x4 + 0x799b1c]
    const auto address=((s.si * 0x00000004u)+0x00799b1cu);
    s.fp.load32(m.r32(address));
  }
  L007187d2: { // 0x7187d2: d9c0 FLD st0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L007187d4: { // 0x7187d4: dc2d08577800 FSUBR double ptr [0x00785708]
    const auto address=(0x00785708u);
    s.fp.reverse_subtract64(read64(m,address));
  }
  L007187da: { // 0x7187da: db442428 FILD dword ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.load_integer32(m.r32(address));
  }
  L007187de: { // 0x7187de: d8ca FMUL st2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L007187e0: { // 0x7187e0: db442424 FILD dword ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.load_integer32(m.r32(address));
  }
  L007187e4: { // 0x7187e4: d8ca FMUL st2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L007187e6: { // 0x7187e6: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L007187e8: { // 0x7187e8: e863220500 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7440365u,op); flags=s.arithmetic_flags;
  }
  L007187ed: { // 0x7187ed: db44242c FILD dword ptr [ESP + 0x2c]
    const auto address=(f.sp+0x0000002cu);
    s.fp.load_integer32(m.r32(address));
  }
  L007187f1: { // 0x7187f1: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L007187f3: { // 0x7187f3: d8ca FMUL st2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L007187f5: { // 0x7187f5: db442470 FILD dword ptr [ESP + 0x70]
    const auto address=(f.sp+0x00000070u);
    s.fp.load_integer32(m.r32(address));
  }
  L007187f9: { // 0x7187f9: d8ca FMUL st2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L007187fb: { // 0x7187fb: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L007187fd: { // 0x7187fd: e84e220500 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7440386u,op); flags=s.arithmetic_flags;
  }
  L00718802: { // 0x718802: db442430 FILD dword ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.load_integer32(m.r32(address));
  }
  L00718806: { // 0x718806: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00718808: { // 0x718808: d8ca FMUL st2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L0071880a: { // 0x71880a: db442418 FILD dword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load_integer32(m.r32(address));
  }
  L0071880e: { // 0x71880e: d8ca FMUL st2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L00718810: { // 0x718810: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L00718812: { // 0x718812: e839220500 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7440407u,op); flags=s.arithmetic_flags;
  }
  L00718817: { // 0x718817: 8b4c2434 MOV ECX,dword ptr [ESP + 0x34]
    s.cx = m.r32((f.sp+0x00000034u));
  }
  L0071881b: { // 0x71881b: 89742428 MOV dword ptr [ESP + 0x28],ESI
    m.w32((f.sp+0x00000028u), s.si);
  }
  L0071881f: { // 0x71881f: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00718821: { // 0x718821: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L00718825: { // 0x718825: 8b442438 MOV EAX,dword ptr [ESP + 0x38]
    s.ax = m.r32((f.sp+0x00000038u));
  }
  L00718829: { // 0x718829: 2bf1 SUB ESI,ECX
    s.si = integer::sub(s.si,s.cx,32,flags);
  }
  L0071882b: { // 0x71882b: 895c242c MOV dword ptr [ESP + 0x2c],EBX
    m.w32((f.sp+0x0000002cu), s.bx);
  }
  L0071882f: { // 0x71882f: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00718831: { // 0x718831: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L00718835: { // 0x718835: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00718837: { // 0x718837: db442418 FILD dword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load_integer32(m.r32(address));
  }
  L0071883b: { // 0x71883b: 895c2418 MOV dword ptr [ESP + 0x18],EBX
    m.w32((f.sp+0x00000018u), s.bx);
  }
  L0071883f: { // 0x71883f: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00718842: { // 0x718842: db442420 FILD dword ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.load_integer32(m.r32(address));
  }
  L00718846: { // 0x718846: d9542418 FST float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto value=s.fp.store32();
    m.w32(address,value);
  }
  L0071884a: { // 0x71884a: d9c0 FLD st0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L0071884c: { // 0x71884c: d8c9 FMUL st1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L0071884e: { // 0x71884e: d9c2 FLD st2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L00718850: { // 0x718850: d8cb FMUL st3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L00718852: { // 0x718852: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L00718854: { // 0x718854: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00718857: { // 0x718857: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00718859: { // 0x718859: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0071885b: { // 0x71885b: e82018daff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,7440480u,op); flags=s.arithmetic_flags;
  }
  L00718860: { // 0x718860: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00718863: { // 0x718863: e8e8210500 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7440488u,op); flags=s.arithmetic_flags;
  }
  L00718868: { // 0x718868: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L0071886c: { // 0x71886c: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00718870: { // 0x718870: 8d87a0000000 LEA EAX,[EDI + 0xa0]
    s.ax = (s.di+0x000000a0u);
  }
  L00718876: { // 0x718876: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00718878: { // 0x718878: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00718879: { // 0x718879: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  L0071887b: { // 0x71887b: 8b542430 MOV EDX,dword ptr [ESP + 0x30]
    s.dx = m.r32((f.sp+0x00000030u));
  }
  L0071887f: { // 0x71887f: 895104 MOV dword ptr [ECX + 0x4],EDX
    m.w32((s.cx+0x00000004u), s.dx);
  }
  L00718882: { // 0x718882: 8b542434 MOV EDX,dword ptr [ESP + 0x34]
    s.dx = m.r32((f.sp+0x00000034u));
  }
  L00718886: { // 0x718886: 895108 MOV dword ptr [ECX + 0x8],EDX
    m.w32((s.cx+0x00000008u), s.dx);
  }
  L00718889: { // 0x718889: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L0071888b: { // 0x71888b: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0071888d: { // 0x71888d: ff929c010000 CALL dword ptr [EDX + 0x19c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000019cu)),7440531u,op); flags=s.arithmetic_flags;
  }
  L00718893: { // 0x718893: 8b4c2434 MOV ECX,dword ptr [ESP + 0x34]
    s.cx = m.r32((f.sp+0x00000034u));
  }
  L00718897: { // 0x718897: 8b542438 MOV EDX,dword ptr [ESP + 0x38]
    s.dx = m.r32((f.sp+0x00000038u));
  }
  L0071889b: { // 0x71889b: 8d87ac000000 LEA EAX,[EDI + 0xac]
    s.ax = (s.di+0x000000acu);
  }
  L007188a1: { // 0x7188a1: 8db7b8000000 LEA ESI,[EDI + 0xb8]
    s.si = (s.di+0x000000b8u);
  }
  L007188a7: { // 0x7188a7: c7873001000006000000 MOV dword ptr [EDI + 0x130],0x6
    m.w32((s.di+0x00000130u), 0x00000006u);
  }
  L007188b1: { // 0x7188b1: 56 PUSH ESI
    f.push(m,s.si);
  }
  L007188b2: { // 0x7188b2: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L007188b4: { // 0x7188b4: 8b4c2440 MOV ECX,dword ptr [ESP + 0x40]
    s.cx = m.r32((f.sp+0x00000040u));
  }
  L007188b8: { // 0x7188b8: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
  L007188bb: { // 0x7188bb: 8d9738010000 LEA EDX,[EDI + 0x138]
    s.dx = (s.di+0x00000138u);
  }
  L007188c1: { // 0x7188c1: 899734010000 MOV dword ptr [EDI + 0x134],EDX
    m.w32((s.di+0x00000134u), s.dx);
  }
  L007188c7: { // 0x7188c7: 894808 MOV dword ptr [EAX + 0x8],ECX
    m.w32((s.ax+0x00000008u), s.cx);
  }
  L007188ca: { // 0x7188ca: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L007188d0: { // 0x7188d0: 8d44242c LEA EAX,[ESP + 0x2c]
    s.ax = (f.sp+0x0000002cu);
  }
  L007188d4: { // 0x7188d4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007188d5: { // 0x7188d5: e836f7f7ff CALL 0x00698010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00698010u,7440602u,op); flags=s.arithmetic_flags;
  }
  L007188da: { // 0x7188da: 8d9fc0000000 LEA EBX,[EDI + 0xc0]
    s.bx = (s.di+0x000000c0u);
  }
  L007188e0: { // 0x7188e0: 8d4c2434 LEA ECX,[ESP + 0x34]
    s.cx = (f.sp+0x00000034u);
  }
  L007188e4: { // 0x7188e4: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L007188e5: { // 0x7188e5: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L007188e6: { // 0x7188e6: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L007188ec: { // 0x7188ec: e81ff7f7ff CALL 0x00698010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00698010u,7440625u,op); flags=s.arithmetic_flags;
  }
  L007188f1: { // 0x7188f1: 8b9734010000 MOV EDX,dword ptr [EDI + 0x134]
    s.dx = m.r32((s.di+0x00000134u));
  }
  L007188f7: { // 0x7188f7: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L007188f9: { // 0x7188f9: db442418 FILD dword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load_integer32(m.r32(address));
  }
  L007188fd: { // 0x7188fd: 894208 MOV dword ptr [EDX + 0x8],EAX
    m.w32((s.dx+0x00000008u), s.ax);
  }
  L00718900: { // 0x718900: 8b4b04 MOV ECX,dword ptr [EBX + 0x4]
    s.cx = m.r32((s.bx+0x00000004u));
  }
  L00718903: { // 0x718903: 894a0c MOV dword ptr [EDX + 0xc],ECX
    m.w32((s.dx+0x0000000cu), s.cx);
  }
  L00718906: { // 0x718906: 8b9734010000 MOV EDX,dword ptr [EDI + 0x134]
    s.dx = m.r32((s.di+0x00000134u));
  }
  L0071890c: { // 0x71890c: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0071890e: { // 0x71890e: 894220 MOV dword ptr [EDX + 0x20],EAX
    m.w32((s.dx+0x00000020u), s.ax);
  }
  L00718911: { // 0x718911: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  L00718914: { // 0x718914: d9c0 FLD st0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L00718916: { // 0x718916: 894a24 MOV dword ptr [EDX + 0x24],ECX
    m.w32((s.dx+0x00000024u), s.cx);
  }
  L00718919: { // 0x718919: 8b879c000000 MOV EAX,dword ptr [EDI + 0x9c]
    s.ax = m.r32((s.di+0x0000009cu));
  }
  L0071891f: { // 0x71891f: d9c0 FLD st0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L00718921: { // 0x718921: 8d0440 LEA EAX,[EAX + EAX*0x2]
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  L00718924: { // 0x718924: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L00718927: { // 0x718927: d880c00bae00 FADD float ptr [EAX + 0xae0bc0]
    const auto address=(s.ax+0x00ae0bc0u);
    s.fp.add32(m.r32(address));
  }
  L0071892d: { // 0x71892d: d95c2474 FSTP float ptr [ESP + 0x74]
    const auto address=(f.sp+0x00000074u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00718931: { // 0x718931: d980c40bae00 FLD float ptr [EAX + 0xae0bc4]
    const auto address=(s.ax+0x00ae0bc4u);
    s.fp.load32(m.r32(address));
  }
  L00718937: { // 0x718937: 8b542474 MOV EDX,dword ptr [ESP + 0x74]
    s.dx = m.r32((f.sp+0x00000074u));
  }
  L0071893b: { // 0x71893b: d95c2478 FSTP float ptr [ESP + 0x78]
    const auto address=(f.sp+0x00000078u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0071893f: { // 0x71893f: d980c80bae00 FLD float ptr [EAX + 0xae0bc8]
    const auto address=(s.ax+0x00ae0bc8u);
    s.fp.load32(m.r32(address));
  }
  L00718945: { // 0x718945: 8b4c2478 MOV ECX,dword ptr [ESP + 0x78]
    s.cx = m.r32((f.sp+0x00000078u));
  }
  L00718949: { // 0x718949: 89542464 MOV dword ptr [ESP + 0x64],EDX
    m.w32((f.sp+0x00000064u), s.dx);
  }
  L0071894d: { // 0x71894d: d95c247c FSTP float ptr [ESP + 0x7c]
    const auto address=(f.sp+0x0000007cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00718951: { // 0x718951: 8b54247c MOV EDX,dword ptr [ESP + 0x7c]
    s.dx = m.r32((f.sp+0x0000007cu));
  }
  L00718955: { // 0x718955: 894c2468 MOV dword ptr [ESP + 0x68],ECX
    m.w32((f.sp+0x00000068u), s.cx);
  }
  L00718959: { // 0x718959: 8954246c MOV dword ptr [ESP + 0x6c],EDX
    m.w32((f.sp+0x0000006cu), s.dx);
  }
  L0071895d: { // 0x71895d: d880cc0bae00 FADD float ptr [EAX + 0xae0bcc]
    const auto address=(s.ax+0x00ae0bccu);
    s.fp.add32(m.r32(address));
  }
  L00718963: { // 0x718963: d99c2480000000 FSTP float ptr [ESP + 0x80]
    const auto address=(f.sp+0x00000080u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0071896a: { // 0x71896a: d980d00bae00 FLD float ptr [EAX + 0xae0bd0]
    const auto address=(s.ax+0x00ae0bd0u);
    s.fp.load32(m.r32(address));
  }
  L00718970: { // 0x718970: 8b8c2480000000 MOV ECX,dword ptr [ESP + 0x80]
    s.cx = m.r32((f.sp+0x00000080u));
  }
  L00718977: { // 0x718977: d99c2484000000 FSTP float ptr [ESP + 0x84]
    const auto address=(f.sp+0x00000084u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0071897e: { // 0x71897e: d980d40bae00 FLD float ptr [EAX + 0xae0bd4]
    const auto address=(s.ax+0x00ae0bd4u);
    s.fp.load32(m.r32(address));
  }
  L00718984: { // 0x718984: 8b942484000000 MOV EDX,dword ptr [ESP + 0x84]
    s.dx = m.r32((f.sp+0x00000084u));
  }
  L0071898b: { // 0x71898b: 894c2440 MOV dword ptr [ESP + 0x40],ECX
    m.w32((f.sp+0x00000040u), s.cx);
  }
  L0071898f: { // 0x71898f: d99c2488000000 FSTP float ptr [ESP + 0x88]
    const auto address=(f.sp+0x00000088u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00718996: { // 0x718996: 8b8c2488000000 MOV ECX,dword ptr [ESP + 0x88]
    s.cx = m.r32((f.sp+0x00000088u));
  }
  L0071899d: { // 0x71899d: 89542444 MOV dword ptr [ESP + 0x44],EDX
    m.w32((f.sp+0x00000044u), s.dx);
  }
  L007189a1: { // 0x7189a1: 894c2448 MOV dword ptr [ESP + 0x48],ECX
    m.w32((f.sp+0x00000048u), s.cx);
  }
  L007189a5: { // 0x7189a5: d980d80bae00 FLD float ptr [EAX + 0xae0bd8]
    const auto address=(s.ax+0x00ae0bd8u);
    s.fp.load32(m.r32(address));
  }
  L007189ab: { // 0x7189ab: d99c248c000000 FSTP float ptr [ESP + 0x8c]
    const auto address=(f.sp+0x0000008cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L007189b2: { // 0x7189b2: d980dc0bae00 FLD float ptr [EAX + 0xae0bdc]
    const auto address=(s.ax+0x00ae0bdcu);
    s.fp.load32(m.r32(address));
  }
  L007189b8: { // 0x7189b8: 8b94248c000000 MOV EDX,dword ptr [ESP + 0x8c]
    s.dx = m.r32((f.sp+0x0000008cu));
  }
  L007189bf: { // 0x7189bf: d99c2490000000 FSTP float ptr [ESP + 0x90]
    const auto address=(f.sp+0x00000090u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L007189c6: { // 0x7189c6: d980e00bae00 FLD float ptr [EAX + 0xae0be0]
    const auto address=(s.ax+0x00ae0be0u);
    s.fp.load32(m.r32(address));
  }
  L007189cc: { // 0x7189cc: 8b8c2490000000 MOV ECX,dword ptr [ESP + 0x90]
    s.cx = m.r32((f.sp+0x00000090u));
  }
  L007189d3: { // 0x7189d3: 8954244c MOV dword ptr [ESP + 0x4c],EDX
    m.w32((f.sp+0x0000004cu), s.dx);
  }
  L007189d7: { // 0x7189d7: d99c2494000000 FSTP float ptr [ESP + 0x94]
    const auto address=(f.sp+0x00000094u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L007189de: { // 0x7189de: 8b942494000000 MOV EDX,dword ptr [ESP + 0x94]
    s.dx = m.r32((f.sp+0x00000094u));
  }
  L007189e5: { // 0x7189e5: 894c2450 MOV dword ptr [ESP + 0x50],ECX
    m.w32((f.sp+0x00000050u), s.cx);
  }
  L007189e9: { // 0x7189e9: 89542454 MOV dword ptr [ESP + 0x54],EDX
    m.w32((f.sp+0x00000054u), s.dx);
  }
  L007189ed: { // 0x7189ed: d980e40bae00 FLD float ptr [EAX + 0xae0be4]
    const auto address=(s.ax+0x00ae0be4u);
    s.fp.load32(m.r32(address));
  }
  L007189f3: { // 0x7189f3: d95c240c FSTP float ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L007189f7: { // 0x7189f7: d980e80bae00 FLD float ptr [EAX + 0xae0be8]
    const auto address=(s.ax+0x00ae0be8u);
    s.fp.load32(m.r32(address));
  }
  L007189fd: { // 0x7189fd: d95c2410 FSTP float ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00718a01: { // 0x718a01: d980ec0bae00 FLD float ptr [EAX + 0xae0bec]
    const auto address=(s.ax+0x00ae0becu);
    s.fp.load32(m.r32(address));
  }
  L00718a07: { // 0x718a07: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L00718a0b: { // 0x718a0b: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00718a0f: { // 0x718a0f: d95c2414 FSTP float ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00718a13: { // 0x718a13: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L00718a17: { // 0x718a17: 89442458 MOV dword ptr [ESP + 0x58],EAX
    m.w32((f.sp+0x00000058u), s.ax);
  }
  L00718a1b: { // 0x718a1b: 894c245c MOV dword ptr [ESP + 0x5c],ECX
    m.w32((f.sp+0x0000005cu), s.cx);
  }
  L00718a1f: { // 0x718a1f: 89542460 MOV dword ptr [ESP + 0x60],EDX
    m.w32((f.sp+0x00000060u), s.dx);
  }
  L00718a23: { // 0x718a23: 8b44243c MOV EAX,dword ptr [ESP + 0x3c]
    s.ax = m.r32((f.sp+0x0000003cu));
  }
  L00718a27: { // 0x718a27: 8b4c2430 MOV ECX,dword ptr [ESP + 0x30]
    s.cx = m.r32((f.sp+0x00000030u));
  }
  L00718a2b: { // 0x718a2b: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00718a2d: { // 0x718a2d: 8b4c2434 MOV ECX,dword ptr [ESP + 0x34]
    s.cx = m.r32((f.sp+0x00000034u));
  }
  L00718a31: { // 0x718a31: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00718a35: { // 0x718a35: 8b5c2428 MOV EBX,dword ptr [ESP + 0x28]
    s.bx = m.r32((f.sp+0x00000028u));
  }
  L00718a39: { // 0x718a39: db442418 FILD dword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load_integer32(m.r32(address));
  }
  L00718a3d: { // 0x718a3d: db442430 FILD dword ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.load_integer32(m.r32(address));
  }
  L00718a41: { // 0x718a41: d9442474 FLD float ptr [ESP + 0x74]
    const auto address=(f.sp+0x00000074u);
    s.fp.load32(m.r32(address));
  }
  L00718a45: { // 0x718a45: d8ca FMUL st2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L00718a47: { // 0x718a47: 8b542438 MOV EDX,dword ptr [ESP + 0x38]
    s.dx = m.r32((f.sp+0x00000038u));
  }
  L00718a4b: { // 0x718a4b: 8b74242c MOV ESI,dword ptr [ESP + 0x2c]
    s.si = m.r32((f.sp+0x0000002cu));
  }
  L00718a4f: { // 0x718a4f: 2bcb SUB ECX,EBX
    s.cx = integer::sub(s.cx,s.bx,32,flags);
  }
  L00718a51: { // 0x718a51: 2bd6 SUB EDX,ESI
    s.dx = integer::sub(s.dx,s.si,32,flags);
  }
  L00718a53: { // 0x718a53: d8f3 FDIV st0,st3
    numeric_b88::detail::reg<0xd8f3>(s.fp);
  }
  L00718a55: { // 0x718a55: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L00718a59: { // 0x718a59: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00718a5c: { // 0x718a5c: d8c1 FADD st0,st1
    numeric_b88::detail::reg<0xd8c1>(s.fp);
  }
  L00718a5e: { // 0x718a5e: d95c2474 FSTP float ptr [ESP + 0x74]
    const auto address=(f.sp+0x00000074u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00718a62: { // 0x718a62: d9842488000000 FLD float ptr [ESP + 0x88]
    const auto address=(f.sp+0x00000088u);
    s.fp.load32(m.r32(address));
  }
  L00718a69: { // 0x718a69: d8ca FMUL st2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L00718a6b: { // 0x718a6b: d8f3 FDIV st0,st3
    numeric_b88::detail::reg<0xd8f3>(s.fp);
  }
  L00718a6d: { // 0x718a6d: d8c1 FADD st0,st1
    numeric_b88::detail::reg<0xd8c1>(s.fp);
  }
  L00718a6f: { // 0x718a6f: d95c2450 FSTP float ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00718a73: { // 0x718a73: d9842494000000 FLD float ptr [ESP + 0x94]
    const auto address=(f.sp+0x00000094u);
    s.fp.load32(m.r32(address));
  }
  L00718a7a: { // 0x718a7a: d8ca FMUL st2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L00718a7c: { // 0x718a7c: d8f3 FDIV st0,st3
    numeric_b88::detail::reg<0xd8f3>(s.fp);
  }
  L00718a7e: { // 0x718a7e: d8c1 FADD st0,st1
    numeric_b88::detail::reg<0xd8c1>(s.fp);
  }
  L00718a80: { // 0x718a80: d95c245c FSTP float ptr [ESP + 0x5c]
    const auto address=(f.sp+0x0000005cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00718a84: { // 0x718a84: d9442414 FLD float ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load32(m.r32(address));
  }
  L00718a88: { // 0x718a88: d8ca FMUL st2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L00718a8a: { // 0x718a8a: d8f3 FDIV st0,st3
    numeric_b88::detail::reg<0xd8f3>(s.fp);
  }
  L00718a8c: { // 0x718a8c: d8c1 FADD st0,st1
    numeric_b88::detail::reg<0xd8c1>(s.fp);
  }
  L00718a8e: { // 0x718a8e: d95c2468 FSTP float ptr [ESP + 0x68]
    const auto address=(f.sp+0x00000068u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00718a92: { // 0x718a92: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00718a94: { // 0x718a94: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00718a96: { // 0x718a96: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00718a98: { // 0x718a98: db442420 FILD dword ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.load_integer32(m.r32(address));
  }
  L00718a9c: { // 0x718a9c: d9542414 FST float ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    const auto value=s.fp.store32();
    m.w32(address,value);
  }
  L00718aa0: { // 0x718aa0: 89542420 MOV dword ptr [ESP + 0x20],EDX
    m.w32((f.sp+0x00000020u), s.dx);
  }
  L00718aa4: { // 0x718aa4: db442420 FILD dword ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.load_integer32(m.r32(address));
  }
  L00718aa8: { // 0x718aa8: d9c9 FXCH
    numeric_b88::detail::reg<0xd9c9>(s.fp);
  }
  L00718aaa: { // 0x718aaa: dd5c2420 FSTP double ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00718aae: { // 0x718aae: d9442414 FLD float ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load32(m.r32(address));
  }
  L00718ab2: { // 0x718ab2: d9c1 FLD st1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L00718ab4: { // 0x718ab4: d8ca FMUL st2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L00718ab6: { // 0x718ab6: d9c1 FLD st1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L00718ab8: { // 0x718ab8: d8ca FMUL st2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L00718aba: { // 0x718aba: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L00718abc: { // 0x718abc: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00718abf: { // 0x718abf: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00718ac1: { // 0x718ac1: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00718ac3: { // 0x718ac3: e8b815daff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,7441096u,op); flags=s.arithmetic_flags;
  }
  L00718ac8: { // 0x718ac8: dd442420 FLD double ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.load64(read64(m,address));
  }
  L00718acc: { // 0x718acc: d9c1 FLD st1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L00718ace: { // 0x718ace: d8d9 FCOMP
    numeric_b88::detail::reg<0xd8d9>(s.fp);
  }
  L00718ad0: { // 0x718ad0: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00718ad3: { // 0x718ad3: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00718ad5: { // 0x718ad5: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00718ad8: { // 0x718ad8: 7404 JZ 0x00718ade
    if(integer::condition("JZ",flags)) goto L00718ade;
  }
  L00718ada: { // 0x718ada: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00718adc: { // 0x718adc: d9c0 FLD st0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L00718ade: { // 0x718ade: d9c0 FLD st0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L00718ae0: { // 0x718ae0: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L00718ae2: { // 0x718ae2: d8da FCOMP st2
    numeric_b88::detail::reg<0xd8da>(s.fp);
  }
  L00718ae4: { // 0x718ae4: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00718ae6: { // 0x718ae6: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L00718ae9: { // 0x718ae9: 7506 JNZ 0x00718af1
    if(integer::condition("JNZ",flags)) goto L00718af1;
  }
  L00718aeb: { // 0x718aeb: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00718aed: { // 0x718aed: d9c0 FLD st0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L00718aef: { // 0x718aef: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L00718af1: { // 0x718af1: d8f1 FDIV st0,st1
    numeric_b88::detail::reg<0xd8f1>(s.fp);
  }
  L00718af3: { // 0x718af3: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00718af6: { // 0x718af6: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00718af9: { // 0x718af9: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00718afb: { // 0x718afb: e8f016daff CALL 0x004ba1f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba1f0u,7441152u,op); flags=s.arithmetic_flags;
  }
  L00718b00: { // 0x718b00: 8b442434 MOV EAX,dword ptr [ESP + 0x34]
    s.ax = m.r32((f.sp+0x00000034u));
  }
  L00718b04: { // 0x718b04: 8b4c2440 MOV ECX,dword ptr [ESP + 0x40]
    s.cx = m.r32((f.sp+0x00000040u));
  }
  L00718b08: { // 0x718b08: dd5c2420 FSTP double ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00718b0c: { // 0x718b0c: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00718b0f: { // 0x718b0f: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00718b11: { // 0x718b11: 7e0a JLE 0x00718b1d
    if(integer::condition("JLE",flags)) goto L00718b1d;
  }
  L00718b13: { // 0x718b13: dd442418 FLD double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load64(read64(m,address));
  }
  L00718b17: { // 0x718b17: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L00718b19: { // 0x718b19: dd5c2418 FSTP double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00718b1d: { // 0x718b1d: 8d8c2498000000 LEA ECX,[ESP + 0x98]
    s.cx = (f.sp+0x00000098u);
  }
  L00718b24: { // 0x718b24: e83743e7ff CALL 0x0058ce60
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058ce60u,7441193u,op); flags=s.arithmetic_flags;
  }
  L00718b29: { // 0x718b29: dd442418 FLD double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load64(read64(m,address));
  }
  L00718b2d: { // 0x718b2d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00718b2e: { // 0x718b2e: 8d8c249c000000 LEA ECX,[ESP + 0x9c]
    s.cx = (f.sp+0x0000009cu);
  }
  L00718b35: { // 0x718b35: d91c24 FSTP float ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00718b38: { // 0x718b38: e8634ce7ff CALL 0x0058d7a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058d7a0u,7441213u,op); flags=s.arithmetic_flags;
  }
  L00718b3d: { // 0x718b3d: 8d4c2464 LEA ECX,[ESP + 0x64]
    s.cx = (f.sp+0x00000064u);
  }
  L00718b41: { // 0x718b41: 8d942498000000 LEA EDX,[ESP + 0x98]
    s.dx = (f.sp+0x00000098u);
  }
  L00718b48: { // 0x718b48: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00718b49: { // 0x718b49: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L00718b4d: { // 0x718b4d: e82e56e7ff CALL 0x0058e180
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058e180u,7441234u,op); flags=s.arithmetic_flags;
  }
  L00718b52: { // 0x718b52: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00718b54: { // 0x718b54: 89542464 MOV dword ptr [ESP + 0x64],EDX
    m.w32((f.sp+0x00000064u), s.dx);
  }
  L00718b58: { // 0x718b58: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L00718b5b: { // 0x718b5b: 894c2468 MOV dword ptr [ESP + 0x68],ECX
    m.w32((f.sp+0x00000068u), s.cx);
  }
  L00718b5f: { // 0x718b5f: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  L00718b63: { // 0x718b63: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L00718b66: { // 0x718b66: 8d442440 LEA EAX,[ESP + 0x40]
    s.ax = (f.sp+0x00000040u);
  }
  L00718b6a: { // 0x718b6a: 8954246c MOV dword ptr [ESP + 0x6c],EDX
    m.w32((f.sp+0x0000006cu), s.dx);
  }
  L00718b6e: { // 0x718b6e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00718b6f: { // 0x718b6f: 8d94249c000000 LEA EDX,[ESP + 0x9c]
    s.dx = (f.sp+0x0000009cu);
  }
  L00718b76: { // 0x718b76: e80556e7ff CALL 0x0058e180
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058e180u,7441275u,op); flags=s.arithmetic_flags;
  }
  L00718b7b: { // 0x718b7b: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00718b7d: { // 0x718b7d: 894c2440 MOV dword ptr [ESP + 0x40],ECX
    m.w32((f.sp+0x00000040u), s.cx);
  }
  L00718b81: { // 0x718b81: 8d4c244c LEA ECX,[ESP + 0x4c]
    s.cx = (f.sp+0x0000004cu);
  }
  L00718b85: { // 0x718b85: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L00718b88: { // 0x718b88: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00718b89: { // 0x718b89: 89542448 MOV dword ptr [ESP + 0x48],EDX
    m.w32((f.sp+0x00000048u), s.dx);
  }
  L00718b8d: { // 0x718b8d: 8d94249c000000 LEA EDX,[ESP + 0x9c]
    s.dx = (f.sp+0x0000009cu);
  }
  L00718b94: { // 0x718b94: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L00718b97: { // 0x718b97: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L00718b9b: { // 0x718b9b: 8944244c MOV dword ptr [ESP + 0x4c],EAX
    m.w32((f.sp+0x0000004cu), s.ax);
  }
  L00718b9f: { // 0x718b9f: e8dc55e7ff CALL 0x0058e180
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058e180u,7441316u,op); flags=s.arithmetic_flags;
  }
  L00718ba4: { // 0x718ba4: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00718ba6: { // 0x718ba6: 8954244c MOV dword ptr [ESP + 0x4c],EDX
    m.w32((f.sp+0x0000004cu), s.dx);
  }
  L00718baa: { // 0x718baa: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L00718bad: { // 0x718bad: 894c2450 MOV dword ptr [ESP + 0x50],ECX
    m.w32((f.sp+0x00000050u), s.cx);
  }
  L00718bb1: { // 0x718bb1: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  L00718bb5: { // 0x718bb5: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L00718bb8: { // 0x718bb8: 8d442458 LEA EAX,[ESP + 0x58]
    s.ax = (f.sp+0x00000058u);
  }
  L00718bbc: { // 0x718bbc: 89542454 MOV dword ptr [ESP + 0x54],EDX
    m.w32((f.sp+0x00000054u), s.dx);
  }
  L00718bc0: { // 0x718bc0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00718bc1: { // 0x718bc1: 8d94249c000000 LEA EDX,[ESP + 0x9c]
    s.dx = (f.sp+0x0000009cu);
  }
  L00718bc8: { // 0x718bc8: e8b355e7ff CALL 0x0058e180
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058e180u,7441357u,op); flags=s.arithmetic_flags;
  }
  L00718bcd: { // 0x718bcd: db442428 FILD dword ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.load_integer32(m.r32(address));
  }
  L00718bd1: { // 0x718bd1: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00718bd3: { // 0x718bd3: 894c2458 MOV dword ptr [ESP + 0x58],ECX
    m.w32((f.sp+0x00000058u), s.cx);
  }
  L00718bd7: { // 0x718bd7: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L00718bda: { // 0x718bda: d9c0 FLD st0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L00718bdc: { // 0x718bdc: d8442464 FADD float ptr [ESP + 0x64]
    const auto address=(f.sp+0x00000064u);
    s.fp.add32(m.r32(address));
  }
  L00718be0: { // 0x718be0: 8954245c MOV dword ptr [ESP + 0x5c],EDX
    m.w32((f.sp+0x0000005cu), s.dx);
  }
  L00718be4: { // 0x718be4: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L00718be7: { // 0x718be7: 89442460 MOV dword ptr [ESP + 0x60],EAX
    m.w32((f.sp+0x00000060u), s.ax);
  }
  L00718beb: { // 0x718beb: e8601e0500 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7441392u,op); flags=s.arithmetic_flags;
  }
  L00718bf0: { // 0x718bf0: db44242c FILD dword ptr [ESP + 0x2c]
    const auto address=(f.sp+0x0000002cu);
    s.fp.load_integer32(m.r32(address));
  }
  L00718bf4: { // 0x718bf4: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00718bf6: { // 0x718bf6: d9542424 FST float ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    const auto value=s.fp.store32();
    m.w32(address,value);
  }
  L00718bfa: { // 0x718bfa: d8442468 FADD float ptr [ESP + 0x68]
    const auto address=(f.sp+0x00000068u);
    s.fp.add32(m.r32(address));
  }
  L00718bfe: { // 0x718bfe: e84d1e0500 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7441411u,op); flags=s.arithmetic_flags;
  }
  L00718c03: { // 0x718c03: d944246c FLD float ptr [ESP + 0x6c]
    const auto address=(f.sp+0x0000006cu);
    s.fp.load32(m.r32(address));
  }
  L00718c07: { // 0x718c07: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00718c0b: { // 0x718c0b: e8401e0500 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7441424u,op); flags=s.arithmetic_flags;
  }
  L00718c10: { // 0x718c10: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00718c14: { // 0x718c14: 8d9fe8000000 LEA EBX,[EDI + 0xe8]
    s.bx = (s.di+0x000000e8u);
  }
  L00718c1a: { // 0x718c1a: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00718c1c: { // 0x718c1c: d9c0 FLD st0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L00718c1e: { // 0x718c1e: d8442440 FADD float ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.add32(m.r32(address));
  }
  L00718c22: { // 0x718c22: 8931 MOV dword ptr [ECX],ESI
    m.w32((s.cx), s.si);
  }
  L00718c24: { // 0x718c24: 895104 MOV dword ptr [ECX + 0x4],EDX
    m.w32((s.cx+0x00000004u), s.dx);
  }
  L00718c27: { // 0x718c27: 894108 MOV dword ptr [ECX + 0x8],EAX
    m.w32((s.cx+0x00000008u), s.ax);
  }
  L00718c2a: { // 0x718c2a: e8211e0500 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7441455u,op); flags=s.arithmetic_flags;
  }
  L00718c2f: { // 0x718c2f: d9442424 FLD float ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.load32(m.r32(address));
  }
  L00718c33: { // 0x718c33: d8442444 FADD float ptr [ESP + 0x44]
    const auto address=(f.sp+0x00000044u);
    s.fp.add32(m.r32(address));
  }
  L00718c37: { // 0x718c37: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00718c39: { // 0x718c39: e8121e0500 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7441470u,op); flags=s.arithmetic_flags;
  }
  L00718c3e: { // 0x718c3e: d9442448 FLD float ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    s.fp.load32(m.r32(address));
  }
  L00718c42: { // 0x718c42: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00718c46: { // 0x718c46: e8051e0500 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7441483u,op); flags=s.arithmetic_flags;
  }
  L00718c4b: { // 0x718c4b: 8d8ff4000000 LEA ECX,[EDI + 0xf4]
    s.cx = (s.di+0x000000f4u);
  }
  L00718c51: { // 0x718c51: 89b7f4000000 MOV dword ptr [EDI + 0xf4],ESI
    m.w32((s.di+0x000000f4u), s.si);
  }
  L00718c57: { // 0x718c57: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00718c5b: { // 0x718c5b: d9c0 FLD st0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L00718c5d: { // 0x718c5d: d844244c FADD float ptr [ESP + 0x4c]
    const auto address=(f.sp+0x0000004cu);
    s.fp.add32(m.r32(address));
  }
  L00718c61: { // 0x718c61: 895104 MOV dword ptr [ECX + 0x4],EDX
    m.w32((s.cx+0x00000004u), s.dx);
  }
  L00718c64: { // 0x718c64: 894108 MOV dword ptr [ECX + 0x8],EAX
    m.w32((s.cx+0x00000008u), s.ax);
  }
  L00718c67: { // 0x718c67: e8e41d0500 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7441516u,op); flags=s.arithmetic_flags;
  }
  L00718c6c: { // 0x718c6c: d9442424 FLD float ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.load32(m.r32(address));
  }
  L00718c70: { // 0x718c70: d8442450 FADD float ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    s.fp.add32(m.r32(address));
  }
  L00718c74: { // 0x718c74: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00718c76: { // 0x718c76: e8d51d0500 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7441531u,op); flags=s.arithmetic_flags;
  }
  L00718c7b: { // 0x718c7b: d9442454 FLD float ptr [ESP + 0x54]
    const auto address=(f.sp+0x00000054u);
    s.fp.load32(m.r32(address));
  }
  L00718c7f: { // 0x718c7f: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00718c83: { // 0x718c83: e8c81d0500 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7441544u,op); flags=s.arithmetic_flags;
  }
  L00718c88: { // 0x718c88: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00718c8c: { // 0x718c8c: 8d8f00010000 LEA ECX,[EDI + 0x100]
    s.cx = (s.di+0x00000100u);
  }
  L00718c92: { // 0x718c92: d8442458 FADD float ptr [ESP + 0x58]
    const auto address=(f.sp+0x00000058u);
    s.fp.add32(m.r32(address));
  }
  L00718c96: { // 0x718c96: 8931 MOV dword ptr [ECX],ESI
    m.w32((s.cx), s.si);
  }
  L00718c98: { // 0x718c98: 895104 MOV dword ptr [ECX + 0x4],EDX
    m.w32((s.cx+0x00000004u), s.dx);
  }
  L00718c9b: { // 0x718c9b: 894108 MOV dword ptr [ECX + 0x8],EAX
    m.w32((s.cx+0x00000008u), s.ax);
  }
  L00718c9e: { // 0x718c9e: e8ad1d0500 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7441571u,op); flags=s.arithmetic_flags;
  }
  L00718ca3: { // 0x718ca3: d9442424 FLD float ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.load32(m.r32(address));
  }
  L00718ca7: { // 0x718ca7: d844245c FADD float ptr [ESP + 0x5c]
    const auto address=(f.sp+0x0000005cu);
    s.fp.add32(m.r32(address));
  }
  L00718cab: { // 0x718cab: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00718cad: { // 0x718cad: e89e1d0500 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7441586u,op); flags=s.arithmetic_flags;
  }
  L00718cb2: { // 0x718cb2: d9442460 FLD float ptr [ESP + 0x60]
    const auto address=(f.sp+0x00000060u);
    s.fp.load32(m.r32(address));
  }
  L00718cb6: { // 0x718cb6: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00718cba: { // 0x718cba: e8911d0500 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7441599u,op); flags=s.arithmetic_flags;
  }
  L00718cbf: { // 0x718cbf: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00718cc3: { // 0x718cc3: 8d8f0c010000 LEA ECX,[EDI + 0x10c]
    s.cx = (s.di+0x0000010cu);
  }
  L00718cc9: { // 0x718cc9: 89b70c010000 MOV dword ptr [EDI + 0x10c],ESI
    m.w32((s.di+0x0000010cu), s.si);
  }
  L00718ccf: { // 0x718ccf: 8db7c8000000 LEA ESI,[EDI + 0xc8]
    s.si = (s.di+0x000000c8u);
  }
  L00718cd5: { // 0x718cd5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00718cd6: { // 0x718cd6: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00718cd7: { // 0x718cd7: 895104 MOV dword ptr [ECX + 0x4],EDX
    m.w32((s.cx+0x00000004u), s.dx);
  }
  L00718cda: { // 0x718cda: 894108 MOV dword ptr [ECX + 0x8],EAX
    m.w32((s.cx+0x00000008u), s.ax);
  }
  L00718cdd: { // 0x718cdd: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L00718ce3: { // 0x718ce3: e828f3f7ff CALL 0x00698010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00698010u,7441640u,op); flags=s.arithmetic_flags;
  }
  L00718ce8: { // 0x718ce8: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L00718cee: { // 0x718cee: 8d9fd0000000 LEA EBX,[EDI + 0xd0]
    s.bx = (s.di+0x000000d0u);
  }
  L00718cf4: { // 0x718cf4: 8d87f4000000 LEA EAX,[EDI + 0xf4]
    s.ax = (s.di+0x000000f4u);
  }
  L00718cfa: { // 0x718cfa: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00718cfb: { // 0x718cfb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00718cfc: { // 0x718cfc: e80ff3f7ff CALL 0x00698010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00698010u,7441665u,op); flags=s.arithmetic_flags;
  }
  L00718d01: { // 0x718d01: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L00718d07: { // 0x718d07: 8d87d8000000 LEA EAX,[EDI + 0xd8]
    s.ax = (s.di+0x000000d8u);
  }
  L00718d0d: { // 0x718d0d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00718d0e: { // 0x718d0e: 8d8700010000 LEA EAX,[EDI + 0x100]
    s.ax = (s.di+0x00000100u);
  }
  L00718d14: { // 0x718d14: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00718d15: { // 0x718d15: e8f6f2f7ff CALL 0x00698010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00698010u,7441690u,op); flags=s.arithmetic_flags;
  }
  L00718d1a: { // 0x718d1a: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L00718d20: { // 0x718d20: 8d87e0000000 LEA EAX,[EDI + 0xe0]
    s.ax = (s.di+0x000000e0u);
  }
  L00718d26: { // 0x718d26: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00718d27: { // 0x718d27: 8d870c010000 LEA EAX,[EDI + 0x10c]
    s.ax = (s.di+0x0000010cu);
  }
  L00718d2d: { // 0x718d2d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00718d2e: { // 0x718d2e: e8ddf2f7ff CALL 0x00698010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00698010u,7441715u,op); flags=s.arithmetic_flags;
  }
  L00718d33: { // 0x718d33: 8b8734010000 MOV EAX,dword ptr [EDI + 0x134]
    s.ax = m.r32((s.di+0x00000134u));
  }
  L00718d39: { // 0x718d39: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L00718d3b: { // 0x718d3b: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L00718d3d: { // 0x718d3d: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  L00718d40: { // 0x718d40: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
  L00718d43: { // 0x718d43: 8b8734010000 MOV EAX,dword ptr [EDI + 0x134]
    s.ax = m.r32((s.di+0x00000134u));
  }
  L00718d49: { // 0x718d49: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  L00718d4b: { // 0x718d4b: 894810 MOV dword ptr [EAX + 0x10],ECX
    m.w32((s.ax+0x00000010u), s.cx);
  }
  L00718d4e: { // 0x718d4e: 8b5304 MOV EDX,dword ptr [EBX + 0x4]
    s.dx = m.r32((s.bx+0x00000004u));
  }
  L00718d51: { // 0x718d51: 895014 MOV dword ptr [EAX + 0x14],EDX
    m.w32((s.ax+0x00000014u), s.dx);
  }
  L00718d54: { // 0x718d54: 8b8734010000 MOV EAX,dword ptr [EDI + 0x134]
    s.ax = m.r32((s.di+0x00000134u));
  }
  L00718d5a: { // 0x718d5a: 8b8fe0000000 MOV ECX,dword ptr [EDI + 0xe0]
    s.cx = m.r32((s.di+0x000000e0u));
  }
  L00718d60: { // 0x718d60: 894818 MOV dword ptr [EAX + 0x18],ECX
    m.w32((s.ax+0x00000018u), s.cx);
  }
  L00718d63: { // 0x718d63: 8b97e4000000 MOV EDX,dword ptr [EDI + 0xe4]
    s.dx = m.r32((s.di+0x000000e4u));
  }
  L00718d69: { // 0x718d69: 89501c MOV dword ptr [EAX + 0x1c],EDX
    m.w32((s.ax+0x0000001cu), s.dx);
  }
  L00718d6c: { // 0x718d6c: 8b8734010000 MOV EAX,dword ptr [EDI + 0x134]
    s.ax = m.r32((s.di+0x00000134u));
  }
  L00718d72: { // 0x718d72: 8b8fd8000000 MOV ECX,dword ptr [EDI + 0xd8]
    s.cx = m.r32((s.di+0x000000d8u));
  }
  L00718d78: { // 0x718d78: 894828 MOV dword ptr [EAX + 0x28],ECX
    m.w32((s.ax+0x00000028u), s.cx);
  }
  L00718d7b: { // 0x718d7b: 8b97dc000000 MOV EDX,dword ptr [EDI + 0xdc]
    s.dx = m.r32((s.di+0x000000dcu));
  }
  L00718d81: { // 0x718d81: b906000000 MOV ECX,0x6
    s.cx = 0x00000006u;
  }
  L00718d86: { // 0x718d86: 89502c MOV dword ptr [EAX + 0x2c],EDX
    m.w32((s.ax+0x0000002cu), s.dx);
  }
  L00718d89: { // 0x718d89: 8bb79c010000 MOV ESI,dword ptr [EDI + 0x19c]
    s.si = m.r32((s.di+0x0000019cu));
  }
  L00718d8f: { // 0x718d8f: 81c6f8020000 ADD ESI,0x2f8
    s.si = integer::add(s.si,0x000002f8u,32,flags);
  }
  L00718d95: { // 0x718d95: 81c7a0010000 ADD EDI,0x1a0
    s.di = integer::add(s.di,0x000001a0u,32,flags);
  }
  L00718d9b: { // 0x718d9b: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L00718d9d: { // 0x718d9d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00718d9e: { // 0x718d9e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00718d9f: { // 0x718d9f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00718da0: { // 0x718da0: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L00718da2: { // 0x718da2: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00718da3: { // 0x718da3: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
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

void f_000ba1f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004ba1f0: { // 0x4ba1f0: dd442404 FLD double ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load64(read64(m,address));
  }
  L004ba1f4: { // 0x4ba1f4: d805f8677800 FADD float ptr [0x007867f8]
    const auto address=(0x007867f8u);
    s.fp.add32(m.r32(address));
  }
  L004ba1fa: { // 0x4ba1fa: d80d88bf7800 FMUL float ptr [0x0078bf88]
    const auto address=(0x0078bf88u);
    s.fp.multiply32(m.r32(address));
  }
  L004ba200: { // 0x4ba200: e84b082b00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4956677u,op); flags=s.arithmetic_flags;
  }
  L004ba205: { // 0x4ba205: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L004ba208: { // 0x4ba208: b914417f00 MOV ECX,0x7f4114
    s.cx = 0x007f4114u;
  }
  L004ba20d: { // 0x4ba20d: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L004ba20f: { // 0x4ba20f: d901 FLD float ptr [ECX]
    const auto address=(s.cx);
    s.fp.load32(m.r32(address));
  }
  L004ba211: { // 0x4ba211: dc2d30667800 FSUBR double ptr [0x00786630]
    const auto address=(0x00786630u);
    s.fp.reverse_subtract64(read64(m,address));
  }
  L004ba217: { // 0x4ba217: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_0018ce60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0058ce60: { // 0x58ce60: ba0000803f MOV EDX,0x3f800000
    s.dx = 0x3f800000u;
  }
  L0058ce65: { // 0x58ce65: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0058ce67: { // 0x58ce67: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  L0058ce69: { // 0x58ce69: 894104 MOV dword ptr [ECX + 0x4],EAX
    m.w32((s.cx+0x00000004u), s.ax);
  }
  L0058ce6c: { // 0x58ce6c: 894108 MOV dword ptr [ECX + 0x8],EAX
    m.w32((s.cx+0x00000008u), s.ax);
  }
  L0058ce6f: { // 0x58ce6f: 89410c MOV dword ptr [ECX + 0xc],EAX
    m.w32((s.cx+0x0000000cu), s.ax);
  }
  L0058ce72: { // 0x58ce72: 894110 MOV dword ptr [ECX + 0x10],EAX
    m.w32((s.cx+0x00000010u), s.ax);
  }
  L0058ce75: { // 0x58ce75: 895114 MOV dword ptr [ECX + 0x14],EDX
    m.w32((s.cx+0x00000014u), s.dx);
  }
  L0058ce78: { // 0x58ce78: 894118 MOV dword ptr [ECX + 0x18],EAX
    m.w32((s.cx+0x00000018u), s.ax);
  }
  L0058ce7b: { // 0x58ce7b: 89411c MOV dword ptr [ECX + 0x1c],EAX
    m.w32((s.cx+0x0000001cu), s.ax);
  }
  L0058ce7e: { // 0x58ce7e: 894120 MOV dword ptr [ECX + 0x20],EAX
    m.w32((s.cx+0x00000020u), s.ax);
  }
  L0058ce81: { // 0x58ce81: 894124 MOV dword ptr [ECX + 0x24],EAX
    m.w32((s.cx+0x00000024u), s.ax);
  }
  L0058ce84: { // 0x58ce84: 895128 MOV dword ptr [ECX + 0x28],EDX
    m.w32((s.cx+0x00000028u), s.dx);
  }
  L0058ce87: { // 0x58ce87: 89412c MOV dword ptr [ECX + 0x2c],EAX
    m.w32((s.cx+0x0000002cu), s.ax);
  }
  L0058ce8a: { // 0x58ce8a: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_0018d7a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0058d7a0: { // 0x58d7a0: 83ec08 SUB ESP,8
    f.sp = integer::sub(f.sp,8u,32,flags);
  }
  L0058d7a3: { // 0x58d7a3: d944240c FLD float ptr [ESP+0xc]
    const auto address=(f.sp+0x0000000cu);
    s.fp.load32(m.r32(address));
  }
  L0058d7a7: { // 0x58d7a7: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0058d7a8: { // 0x58d7a8: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0058d7a9: { // 0x58d7a9: dd5c2408 FSTP double ptr [ESP+8]
    const auto address=(f.sp+8u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0058d7ad: { // 0x58d7ad: 8b5c2408 MOV EBX,dword ptr [ESP+8]
    s.bx = m.r32((f.sp+8u));
  }
  L0058d7b1: { // 0x58d7b1: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0058d7b2: { // 0x58d7b2: 8b7c2410 MOV EDI,dword ptr [ESP+0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L0058d7b6: { // 0x58d7b6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0058d7b8: { // 0x58d7b8: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0058d7b9: { // 0x58d7b9: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0058d7ba: { // 0x58d7ba: e881c9f2ff CALL 0x4ba140
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba140u,5822399u,op); flags=s.arithmetic_flags;
  }
  L0058d7bf: { // 0x58d7bf: d95c2420 FSTP float ptr [ESP+0x20]
    const auto address=(f.sp+0x00000020u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058d7c3: { // 0x58d7c3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0058d7c4: { // 0x58d7c4: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0058d7c5: { // 0x58d7c5: e826c9f2ff CALL 0x4ba0f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba0f0u,5822410u,op); flags=s.arithmetic_flags;
  }
  L0058d7ca: { // 0x58d7ca: d906 FLD float ptr [ESI]
    const auto address=(s.si);
    s.fp.load32(m.r32(address));
  }
  L0058d7cc: { // 0x58d7cc: d94604 FLD float ptr [ESI+4]
    const auto address=(s.si+4u);
    s.fp.load32(m.r32(address));
  }
  L0058d7cf: { // 0x58d7cf: d9c0 FLD st0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L0058d7d1: { // 0x58d7d1: d8cb FMUL st3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L0058d7d3: { // 0x58d7d3: d9c2 FLD st2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L0058d7d5: { // 0x58d7d5: d84c2428 FMUL float ptr [ESP+0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.multiply32(m.r32(address));
  }
  L0058d7d9: { // 0x58d7d9: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0058d7dc: { // 0x58d7dc: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058d7de: { // 0x58d7de: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0058d7df: { // 0x58d7df: d91e FSTP float ptr [ESI]
    const auto address=(s.si);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058d7e1: { // 0x58d7e1: d84c2414 FMUL float ptr [ESP+0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.multiply32(m.r32(address));
  }
  L0058d7e5: { // 0x58d7e5: d9c9 FXCH
    numeric_b88::detail::reg<0xd9c9>(s.fp);
  }
  L0058d7e7: { // 0x58d7e7: d8ca FMUL st2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L0058d7e9: { // 0x58d7e9: dee9 FSUBP
    numeric_b88::detail::reg<0xdee9>(s.fp);
  }
  L0058d7eb: { // 0x58d7eb: d95e04 FSTP float ptr [ESI+4]
    const auto address=(s.si+4u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058d7ee: { // 0x58d7ee: d94610 FLD float ptr [ESI+0x10]
    const auto address=(s.si+0x00000010u);
    s.fp.load32(m.r32(address));
  }
  L0058d7f1: { // 0x58d7f1: d94614 FLD float ptr [ESI+0x14]
    const auto address=(s.si+0x00000014u);
    s.fp.load32(m.r32(address));
  }
  L0058d7f4: { // 0x58d7f4: d9c0 FLD st0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L0058d7f6: { // 0x58d7f6: d8cb FMUL st3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L0058d7f8: { // 0x58d7f8: d9c2 FLD st2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L0058d7fa: { // 0x58d7fa: d84c2414 FMUL float ptr [ESP+0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.multiply32(m.r32(address));
  }
  L0058d7fe: { // 0x58d7fe: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058d800: { // 0x58d800: d95e10 FSTP float ptr [ESI+0x10]
    const auto address=(s.si+0x00000010u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058d803: { // 0x58d803: d84c2414 FMUL float ptr [ESP+0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.multiply32(m.r32(address));
  }
  L0058d807: { // 0x58d807: d9c9 FXCH
    numeric_b88::detail::reg<0xd9c9>(s.fp);
  }
  L0058d809: { // 0x58d809: d8ca FMUL st2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L0058d80b: { // 0x58d80b: dee9 FSUBP
    numeric_b88::detail::reg<0xdee9>(s.fp);
  }
  L0058d80d: { // 0x58d80d: d95e14 FSTP float ptr [ESI+0x14]
    const auto address=(s.si+0x00000014u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058d810: { // 0x58d810: d94620 FLD float ptr [ESI+0x20]
    const auto address=(s.si+0x00000020u);
    s.fp.load32(m.r32(address));
  }
  L0058d813: { // 0x58d813: d94624 FLD float ptr [ESI+0x24]
    const auto address=(s.si+0x00000024u);
    s.fp.load32(m.r32(address));
  }
  L0058d816: { // 0x58d816: d9c0 FLD st0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L0058d818: { // 0x58d818: d8cb FMUL st3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L0058d81a: { // 0x58d81a: d9c2 FLD st2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L0058d81c: { // 0x58d81c: d84c2414 FMUL float ptr [ESP+0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.multiply32(m.r32(address));
  }
  L0058d820: { // 0x58d820: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058d822: { // 0x58d822: d95e20 FSTP float ptr [ESI+0x20]
    const auto address=(s.si+0x00000020u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058d825: { // 0x58d825: d84c2414 FMUL float ptr [ESP+0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.multiply32(m.r32(address));
  }
  L0058d829: { // 0x58d829: d9c9 FXCH
    numeric_b88::detail::reg<0xd9c9>(s.fp);
  }
  L0058d82b: { // 0x58d82b: d8ca FMUL st2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L0058d82d: { // 0x58d82d: dee9 FSUBP
    numeric_b88::detail::reg<0xdee9>(s.fp);
  }
  L0058d82f: { // 0x58d82f: d95e24 FSTP float ptr [ESI+0x24]
    const auto address=(s.si+0x00000024u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058d832: { // 0x58d832: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0058d833: { // 0x58d833: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0058d834: { // 0x58d834: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0058d836: { // 0x58d836: 83c408 ADD ESP,8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  L0058d839: { // 0x58d839: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_0018e180(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0058e180: { // 0x58e180: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L0058e183: { // 0x58e183: d94208 FLD float ptr [EDX + 0x8]
    const auto address=(s.dx+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L0058e186: { // 0x58e186: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0058e187: { // 0x58e187: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L0058e18b: { // 0x58e18b: d84e08 FMUL float ptr [ESI + 0x8]
    const auto address=(s.si+0x00000008u);
    s.fp.multiply32(m.r32(address));
  }
  L0058e18e: { // 0x58e18e: d94204 FLD float ptr [EDX + 0x4]
    const auto address=(s.dx+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0058e191: { // 0x58e191: d84e04 FMUL float ptr [ESI + 0x4]
    const auto address=(s.si+0x00000004u);
    s.fp.multiply32(m.r32(address));
  }
  L0058e194: { // 0x58e194: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0058e196: { // 0x58e196: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058e198: { // 0x58e198: d902 FLD float ptr [EDX]
    const auto address=(s.dx);
    s.fp.load32(m.r32(address));
  }
  L0058e19a: { // 0x58e19a: d80e FMUL float ptr [ESI]
    const auto address=(s.si);
    s.fp.multiply32(m.r32(address));
  }
  L0058e19c: { // 0x58e19c: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058e19e: { // 0x58e19e: d8420c FADD float ptr [EDX + 0xc]
    const auto address=(s.dx+0x0000000cu);
    s.fp.add32(m.r32(address));
  }
  L0058e1a1: { // 0x58e1a1: d95c2404 FSTP float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058e1a5: { // 0x58e1a5: d94210 FLD float ptr [EDX + 0x10]
    const auto address=(s.dx+0x00000010u);
    s.fp.load32(m.r32(address));
  }
  L0058e1a8: { // 0x58e1a8: d80e FMUL float ptr [ESI]
    const auto address=(s.si);
    s.fp.multiply32(m.r32(address));
  }
  L0058e1aa: { // 0x58e1aa: d94218 FLD float ptr [EDX + 0x18]
    const auto address=(s.dx+0x00000018u);
    s.fp.load32(m.r32(address));
  }
  L0058e1ad: { // 0x58e1ad: d84e08 FMUL float ptr [ESI + 0x8]
    const auto address=(s.si+0x00000008u);
    s.fp.multiply32(m.r32(address));
  }
  L0058e1b0: { // 0x58e1b0: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058e1b2: { // 0x58e1b2: d94214 FLD float ptr [EDX + 0x14]
    const auto address=(s.dx+0x00000014u);
    s.fp.load32(m.r32(address));
  }
  L0058e1b5: { // 0x58e1b5: d84e04 FMUL float ptr [ESI + 0x4]
    const auto address=(s.si+0x00000004u);
    s.fp.multiply32(m.r32(address));
  }
  L0058e1b8: { // 0x58e1b8: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058e1ba: { // 0x58e1ba: d8421c FADD float ptr [EDX + 0x1c]
    const auto address=(s.dx+0x0000001cu);
    s.fp.add32(m.r32(address));
  }
  L0058e1bd: { // 0x58e1bd: d95c2408 FSTP float ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058e1c1: { // 0x58e1c1: d94220 FLD float ptr [EDX + 0x20]
    const auto address=(s.dx+0x00000020u);
    s.fp.load32(m.r32(address));
  }
  L0058e1c4: { // 0x58e1c4: d80e FMUL float ptr [ESI]
    const auto address=(s.si);
    s.fp.multiply32(m.r32(address));
  }
  L0058e1c6: { // 0x58e1c6: d94228 FLD float ptr [EDX + 0x28]
    const auto address=(s.dx+0x00000028u);
    s.fp.load32(m.r32(address));
  }
  L0058e1c9: { // 0x58e1c9: d84e08 FMUL float ptr [ESI + 0x8]
    const auto address=(s.si+0x00000008u);
    s.fp.multiply32(m.r32(address));
  }
  L0058e1cc: { // 0x58e1cc: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058e1ce: { // 0x58e1ce: d94224 FLD float ptr [EDX + 0x24]
    const auto address=(s.dx+0x00000024u);
    s.fp.load32(m.r32(address));
  }
  L0058e1d1: { // 0x58e1d1: d84e04 FMUL float ptr [ESI + 0x4]
    const auto address=(s.si+0x00000004u);
    s.fp.multiply32(m.r32(address));
  }
  L0058e1d4: { // 0x58e1d4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0058e1d5: { // 0x58e1d5: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058e1d7: { // 0x58e1d7: d8422c FADD float ptr [EDX + 0x2c]
    const auto address=(s.dx+0x0000002cu);
    s.fp.add32(m.r32(address));
  }
  L0058e1da: { // 0x58e1da: 8b542400 MOV EDX,dword ptr [ESP]
    s.dx = m.r32((f.sp));
  }
  L0058e1de: { // 0x58e1de: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  L0058e1e0: { // 0x58e1e0: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L0058e1e4: { // 0x58e1e4: d95c2408 FSTP float ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058e1e8: { // 0x58e1e8: 895104 MOV dword ptr [ECX + 0x4],EDX
    m.w32((s.cx+0x00000004u), s.dx);
  }
  L0058e1eb: { // 0x58e1eb: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L0058e1ef: { // 0x58e1ef: 895108 MOV dword ptr [ECX + 0x8],EDX
    m.w32((s.cx+0x00000008u), s.dx);
  }
  L0058e1f2: { // 0x58e1f2: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0058e1f5: { // 0x58e1f5: c20400 RET 0x4
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
    s.dx = m.r16((f.sp));
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

void f_00298010(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00698010: { // 0x698010: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00698013: { // 0x698013: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00698014: { // 0x698014: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L00698018: { // 0x698018: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00698019: { // 0x698019: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0069801a: { // 0x69801a: 8b33 MOV ESI,dword ptr [EBX]
    s.si = m.r32((s.bx));
  }
  L0069801c: { // 0x69801c: 8b4304 MOV EAX,dword ptr [EBX + 0x4]
    s.ax = m.r32((s.bx+0x00000004u));
  }
  L0069801f: { // 0x69801f: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00698023: { // 0x698023: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L00698025: { // 0x698025: 8d0476 LEA EAX,[ESI + ESI*0x2]
    s.ax = (s.si+(s.si * 0x00000002u));
  }
  L00698028: { // 0x698028: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00698029: { // 0x698029: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L0069802d: { // 0x69802d: 8b5b08 MOV EBX,dword ptr [EBX + 0x8]
    s.bx = m.r32((s.bx+0x00000008u));
  }
  L00698030: { // 0x698030: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L00698033: { // 0x698033: c744241c00000000 MOV dword ptr [ESP + 0x1c],0x0
    m.w32((f.sp+0x0000001cu), 0x00000000u);
  }
  L0069803b: { // 0x69803b: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L0069803e: { // 0x69803e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069803f: { // 0x69803f: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00698041: { // 0x698041: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00698043: { // 0x698043: 8d0476 LEA EAX,[ESI + ESI*0x2]
    s.ax = (s.si+(s.si * 0x00000002u));
  }
  L00698046: { // 0x698046: d1f9 SAR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00698048: { // 0x698048: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0069804b: { // 0x69804b: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
  L0069804d: { // 0x69804d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069804e: { // 0x69804e: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00698050: { // 0x698050: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00698052: { // 0x698052: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L00698054: { // 0x698054: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L00698057: { // 0x698057: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  L00698059: { // 0x698059: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L0069805b: { // 0x69805b: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L0069805e: { // 0x69805e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069805f: { // 0x69805f: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00698061: { // 0x698061: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00698063: { // 0x698063: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00698065: { // 0x698065: 8d047f LEA EAX,[EDI + EDI*0x2]
    s.ax = (s.di+(s.di * 0x00000002u));
  }
  L00698068: { // 0x698068: d1fe SAR ESI,0x1
    s.si = integer::shift(s.si,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069806a: { // 0x69806a: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0069806d: { // 0x69806d: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L00698071: { // 0x698071: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
  L00698073: { // 0x698073: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00698074: { // 0x698074: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00698076: { // 0x698076: 895c2410 MOV dword ptr [ESP + 0x10],EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
  L0069807a: { // 0x69807a: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069807c: { // 0x69807c: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L0069807e: { // 0x69807e: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00698080: { // 0x698080: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00698081: { // 0x698081: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00698087: { // 0x698087: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00698089: { // 0x698089: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0069808b: { // 0x69808b: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0069808d: { // 0x69808d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069808e: { // 0x69808e: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00698094: { // 0x698094: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00698096: { // 0x698096: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00698098: { // 0x698098: c1ff08 SAR EDI,0x8
    s.di = integer::shift(s.di,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069809b: { // 0x69809b: c1fe08 SAR ESI,0x8
    s.si = integer::shift(s.si,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069809e: { // 0x69809e: 81fbd8020000 CMP EBX,0x2d8
    (void)integer::sub(s.bx,0x000002d8u,32,flags);
  }
  L006980a4: { // 0x6980a4: 7c08 JL 0x006980ae
    if(integer::condition("JL",flags)) goto L006980ae;
  }
  L006980a6: { // 0x6980a6: c744241c01000000 MOV dword ptr [ESP + 0x1c],0x1
    m.w32((f.sp+0x0000001cu), 0x00000001u);
  }
  L006980ae: { // 0x6980ae: db442410 FILD dword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load_integer32(m.r32(address));
  }
  L006980b2: { // 0x6980b2: dc0d905faa00 FMUL double ptr [0x00aa5f90]
    const auto address=(0x00aa5f90u);
    s.fp.multiply64(read64(m,address));
  }
  L006980b8: { // 0x6980b8: da44241c FIADD dword ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    floating_b61::fp_extended::add_integer32(s.fp,m.r32(address));
  }
  L006980bc: { // 0x6980bc: dc0528577800 FADD double ptr [0x00785728]
    const auto address=(0x00785728u);
    s.fp.add64(read64(m,address));
  }
  L006980c2: { // 0x6980c2: e889290d00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6914247u,op); flags=s.arithmetic_flags;
  }
  L006980c7: { // 0x6980c7: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  L006980c9: { // 0x6980c9: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L006980cd: { // 0x6980cd: 8938 MOV dword ptr [EAX],EDI
    m.w32((s.ax), s.di);
  }
  L006980cf: { // 0x6980cf: 897004 MOV dword ptr [EAX + 0x4],ESI
    m.w32((s.ax+0x00000004u), s.si);
  }
  L006980d2: { // 0x6980d2: 8b8db0000000 MOV ECX,dword ptr [EBP + 0xb0]
    s.cx = m.r32((s.bp+0x000000b0u));
  }
  L006980d8: { // 0x6980d8: 8badb4000000 MOV EBP,dword ptr [EBP + 0xb4]
    s.bp = m.r32((s.bp+0x000000b4u));
  }
  L006980de: { // 0x6980de: 8b38 MOV EDI,dword ptr [EAX]
    s.di = m.r32((s.ax));
  }
  L006980e0: { // 0x6980e0: 8b7004 MOV ESI,dword ptr [EAX + 0x4]
    s.si = m.r32((s.ax+0x00000004u));
  }
  L006980e3: { // 0x6980e3: 2bf9 SUB EDI,ECX
    s.di = integer::sub(s.di,s.cx,32,flags);
  }
  L006980e5: { // 0x6980e5: 2bf5 SUB ESI,EBP
    s.si = integer::sub(s.si,s.bp,32,flags);
  }
  L006980e7: { // 0x6980e7: 8938 MOV dword ptr [EAX],EDI
    m.w32((s.ax), s.di);
  }
  L006980e9: { // 0x6980e9: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006980eb: { // 0x6980eb: 897004 MOV dword ptr [EAX + 0x4],ESI
    m.w32((s.ax+0x00000004u), s.si);
  }
  L006980ee: { // 0x6980ee: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L006980f0: { // 0x6980f0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006980f1: { // 0x6980f1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006980f2: { // 0x6980f2: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006980f3: { // 0x6980f3: 81f998feffff CMP ECX,0xfffffe98
    (void)integer::sub(s.cx,0xfffffe98u,32,flags);
  }
  L006980f9: { // 0x6980f9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006980fa: { // 0x6980fa: 7d08 JGE 0x00698104
    if(integer::condition("JGE",flags)) goto L00698104;
  }
  L006980fc: { // 0x6980fc: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006980fe: { // 0x6980fe: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00698101: { // 0x698101: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L00698104: { // 0x698104: 8b157060aa00 MOV EDX,dword ptr [0x00aa6070]
    s.dx = m.r32((0x00aa6070u));
  }
  L0069810a: { // 0x69810a: 81c268010000 ADD EDX,0x168
    s.dx = integer::add(s.dx,0x00000168u,32,flags);
  }
  L00698110: { // 0x698110: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L00698112: { // 0x698112: 7e08 JLE 0x0069811c
    if(integer::condition("JLE",flags)) goto L0069811c;
  }
  L00698114: { // 0x698114: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00698116: { // 0x698116: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00698119: { // 0x698119: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0069811c: { // 0x69811c: 3d4cffffff CMP EAX,0xffffff4c
    (void)integer::sub(s.ax,0xffffff4cu,32,flags);
  }
  L00698121: { // 0x698121: 7d08 JGE 0x0069812b
    if(integer::condition("JGE",flags)) goto L0069812b;
  }
  L00698123: { // 0x698123: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00698125: { // 0x698125: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00698128: { // 0x698128: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0069812b: { // 0x69812b: 8b0d7460aa00 MOV ECX,dword ptr [0x00aa6074]
    s.cx = m.r32((0x00aa6074u));
  }
  L00698131: { // 0x698131: 81c1b4000000 ADD ECX,0xb4
    s.cx = integer::add(s.cx,0x000000b4u,32,flags);
  }
  L00698137: { // 0x698137: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00698139: { // 0x698139: 0f9ec0 SETLE AL
    s.ax = with_al(s.ax, (integer::condition("SETLE",flags)?1u:0u));
  }
  L0069813c: { // 0x69813c: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0069813f: { // 0x69813f: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}

void f_000ba0f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004ba0f0: { // 0x4ba0f0: dd442404 FLD double ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load64(read64(m,address));
  }
  L004ba0f4: { // 0x4ba0f4: d80d38317c00 FMUL float ptr [0x007c3138]
    const auto address=(0x007c3138u);
    s.fp.multiply32(m.r32(address));
  }
  L004ba0fa: { // 0x4ba0fa: e851092b00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4956415u,op); flags=s.arithmetic_flags;
  }
  L004ba0ff: { // 0x4ba0ff: 8ac8 MOV CL,AL
    s.cx = with_al(s.cx, (s.ax & 0xffu));
  }
  L004ba101: { // 0x4ba101: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004ba102: { // 0x4ba102: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004ba104: { // 0x4ba104: 80e101 AND CL,0x1
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))&(0x00000001u),8,flags));
  }
  L004ba107: { // 0x4ba107: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L004ba109: { // 0x4ba109: 25ff1f0080 AND EAX,0x80001fff
    s.ax = integer::logical((s.ax)&(0x80001fffu),32,flags);
  }
  L004ba10e: { // 0x4ba10e: 790e JNS 0x004ba11e
    if(integer::condition("JNS",flags)) goto L004ba11e;
  }
  L004ba110: { // 0x4ba110: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L004ba111: { // 0x4ba111: 0d00e0ffff OR EAX,0xffffe000
    s.ax = integer::logical((s.ax)|(0xffffe000u),32,flags);
  }
  L004ba116: { // 0x4ba116: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004ba117: { // 0x4ba117: 7905 JNS 0x004ba11e
    if(integer::condition("JNS",flags)) goto L004ba11e;
  }
  L004ba119: { // 0x4ba119: 0500200000 ADD EAX,0x2000
    s.ax = integer::add(s.ax,0x00002000u,32,flags);
  }
  L004ba11e: { // 0x4ba11e: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004ba120: { // 0x4ba120: 7408 JZ 0x004ba12a
    if(integer::condition("JZ",flags)) goto L004ba12a;
  }
  L004ba122: { // 0x4ba122: 3dff1f0000 CMP EAX,0x1fff
    (void)integer::sub(s.ax,0x00001fffu,32,flags);
  }
  L004ba127: { // 0x4ba127: 7d01 JGE 0x004ba12a
    if(integer::condition("JGE",flags)) goto L004ba12a;
  }
  L004ba129: { // 0x4ba129: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004ba12a: { // 0x4ba12a: d9048504a17e00 FLD float ptr [EAX*0x4 + 0x7ea104]
    const auto address=((s.ax * 0x00000004u)+0x007ea104u);
    s.fp.load32(m.r32(address));
  }
  L004ba131: { // 0x4ba131: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_000ba140(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004ba140: { // 0x4ba140: dd442404 FLD double ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load64(read64(m,address));
  }
  L004ba144: { // 0x4ba144: d80d3c317c00 FMUL float ptr [0x007c313c]
    const auto address=(0x007c313cu);
    s.fp.multiply32(m.r32(address));
  }
  L004ba14a: { // 0x4ba14a: e801092b00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4956495u,op); flags=s.arithmetic_flags;
  }
  L004ba14f: { // 0x4ba14f: 8ac8 MOV CL,AL
    s.cx = with_al(s.cx, (s.ax & 0xffu));
  }
  L004ba151: { // 0x4ba151: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004ba152: { // 0x4ba152: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004ba154: { // 0x4ba154: 80e101 AND CL,0x1
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))&(0x00000001u),8,flags));
  }
  L004ba157: { // 0x4ba157: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L004ba159: { // 0x4ba159: 25ff1f0080 AND EAX,0x80001fff
    s.ax = integer::logical((s.ax)&(0x80001fffu),32,flags);
  }
  L004ba15e: { // 0x4ba15e: 7910 JNS 0x004ba170
    if(integer::condition("JNS",flags)) goto L004ba170;
  }
  L004ba160: { // 0x4ba160: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L004ba161: { // 0x4ba161: 0d00e0ffff OR EAX,0xffffe000
    s.ax = integer::logical((s.ax)|(0xffffe000u),32,flags);
  }
  L004ba166: { // 0x4ba166: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004ba167: { // 0x4ba167: 7907 JNS 0x004ba170
    if(integer::condition("JNS",flags)) goto L004ba170;
  }
  L004ba169: { // 0x4ba169: 0500280000 ADD EAX,0x2800
    s.ax = integer::add(s.ax,0x00002800u,32,flags);
  }
  L004ba16e: { // 0x4ba16e: eb05 JMP 0x004ba175
    goto L004ba175;
  }
  L004ba170: { // 0x4ba170: 0500080000 ADD EAX,0x800
    s.ax = integer::add(s.ax,0x00000800u,32,flags);
  }
  L004ba175: { // 0x4ba175: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004ba177: { // 0x4ba177: 7408 JZ 0x004ba181
    if(integer::condition("JZ",flags)) goto L004ba181;
  }
  L004ba179: { // 0x4ba179: 3dff270000 CMP EAX,0x27ff
    (void)integer::sub(s.ax,0x000027ffu,32,flags);
  }
  L004ba17e: { // 0x4ba17e: 7d01 JGE 0x004ba181
    if(integer::condition("JGE",flags)) goto L004ba181;
  }
  L004ba180: { // 0x4ba180: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004ba181: { // 0x4ba181: d9048504a17e00 FLD float ptr [EAX*0x4 + 0x7ea104]
    const auto address=((s.ax * 0x00000004u)+0x007ea104u);
    s.fp.load32(m.r32(address));
  }
  L004ba188: { // 0x4ba188: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

inline void invoke(Memory&m,State&s,Frame&f,unsigned target,unsigned continuation,const Operations&op){
 f.push(m,continuation); Frame child{f.sp,f.sp,continuation};
 switch(target){
 case 0x718470u:f_00318470(m,s,child,op);break;
 case 0x5cd850u:f_001cd850(m,s,child,op);break;
 case 0x4ba080u:f_000ba080(m,s,child,op);break;
 case 0x4ba1f0u:f_000ba1f0(m,s,child,op);break;
 case 0x58ce60u:f_0018ce60(m,s,child,op);break;
 case 0x58d7a0u:f_0018d7a0(m,s,child,op);break;
 case 0x58e180u:f_0018e180(m,s,child,op);break;
 case 0x76aa50u:f_0036aa50(m,s,child,op);break;
 case 0x698010u:f_00298010(m,s,child,op);break;
 case 0x4ba0f0u:f_000ba0f0(m,s,child,op);break;
 case 0x4ba140u:f_000ba140(m,s,child,op);break;
 default:throw std::domain_error("B1661 unresolved authentic target; fail closed");
 } f.sp=child.sp;
}
struct ExpectedByte { std::uint32_t address; unsigned char value; };
constexpr ExpectedByte ro_bytes[]={
{0x00785708u,0x00u},
{0x00785709u,0x00u},
{0x0078570au,0x00u},
{0x0078570bu,0x00u},
{0x0078570cu,0x00u},
{0x0078570du,0x00u},
{0x0078570eu,0xf0u},
{0x0078570fu,0x3fu},
{0x00785728u,0x00u},
{0x00785729u,0x00u},
{0x0078572au,0x00u},
{0x0078572bu,0x00u},
{0x0078572cu,0x00u},
{0x0078572du,0x00u},
{0x0078572eu,0xe0u},
{0x0078572fu,0x3fu},
{0x00785738u,0x00u},
{0x00785739u,0x00u},
{0x0078573au,0x00u},
{0x0078573bu,0x00u},
{0x00786630u,0x18u},
{0x00786631u,0x2du},
{0x00786632u,0x44u},
{0x00786633u,0x54u},
{0x00786634u,0xfbu},
{0x00786635u,0x21u},
{0x00786636u,0xf9u},
{0x00786637u,0x3fu},
{0x007867f8u,0x00u},
{0x007867f9u,0x00u},
{0x007867fau,0x80u},
{0x007867fbu,0x3fu},
{0x0078bf88u,0x00u},
{0x0078bf89u,0x00u},
{0x0078bf8au,0x00u},
{0x0078bf8bu,0xc5u},
{0x00799b1cu,0x00u},
{0x00799b1du,0x00u},
{0x00799b1eu,0x80u},
{0x00799b1fu,0x3fu},
{0x00799cfcu,0x50u},
{0x00799cfdu,0xd8u},
{0x00799cfeu,0x5cu},
{0x00799cffu,0x00u},
{0x007c3138u,0x83u},
{0x007c3139u,0xf9u},
{0x007c313au,0x22u},
{0x007c313bu,0x45u},
{0x007c313cu,0x83u},
{0x007c313du,0xf9u},
{0x007c313eu,0x22u},
{0x007c313fu,0x45u},
{0x007c3a04u,0x7fu},
{0x007c3a05u,0x0eu},
{0x007c3a06u,0x00u},
{0x007c3a07u,0x00u},
{0x007ea104u,0x00u},
{0x007ea105u,0x00u},
{0x007ea106u,0x00u},
{0x007ea107u,0x00u},
{0x007ec104u,0x00u},
{0x007ec105u,0x00u},
{0x007ec106u,0x80u},
{0x007ec107u,0x3fu},
{0x007f8114u,0xdau},
{0x007f8115u,0x0fu},
{0x007f8116u,0xc9u},
{0x007f8117u,0x3fu},
{0x0080013cu,0x00u},
{0x0080013du,0x00u},
{0x0080013eu,0x00u},
{0x0080013fu,0x00u}
};
constexpr unsigned char warm_table[]={
0x00u,0x00u,0xf0u,0xc1u,0x00u,0x00u,0xc8u,0xc2u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0xf0u,0xc1u,0x00u,0x00u,0xc8u,0x42u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0xf0u,0x41u,0x00u,0x00u,0xc8u,0xc2u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0xf0u,0x41u,0x00u,0x00u,0xc8u,0x42u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x08u,0xc2u,0x00u,0x00u,0x30u,0xc2u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x08u,0xc2u,0x00u,0x00u,0x30u,0x42u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x08u,0x42u,0x00u,0x00u,0x30u,0xc2u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0x08u,0x42u,0x00u,0x00u,0x30u,0x42u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0xd8u,0xc1u,0x00u,0x00u,0x08u,0xc2u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0xd8u,0xc1u,0x00u,0x00u,0x08u,0x42u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0xd8u,0x41u,0x00u,0x00u,0x08u,0xc2u,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u,0xd8u,0x41u,0x00u,0x00u,0x08u,0x42u,0x00u,0x00u,0x00u,0x00u
};
bool disjoint(std::uint64_t a,std::uint64_t an,std::uint64_t b,std::uint64_t bn){return a+an<=b||b+bn<=a;}
bool arena_span(std::uint32_t a,std::uint32_t n){constexpr std::uint32_t bases[]{0x18000000u,0x24000000u,0x31000000u};for(auto b:bases)if(a>=b&&std::uint64_t(a)+n<=std::uint64_t(b)+0x140000u)return true;return false;}
void read_span(Memory&m,std::uint32_t a,std::uint32_t n){if(!a||std::uint64_t(a)+n>0x100000000ull)throw std::domain_error("public span bounds");for(std::uint32_t i=0;i<n;++i)(void)m.r8(a+i);}
} // namespace
Result run(Memory&world,std::uint32_t entry,unsigned char*storage,unsigned size,const NativeState&in,const fp::Image&incoming,const Operations&op){
 (void)op;
 if(!storage||size!=0x8000u+68u||entry<0x8000u||(entry&7u)||std::uint64_t(entry)+68u>0x100000000ull||std::uint64_t(reinterpret_cast<std::uintptr_t>(storage))+0x8000u!=entry)throw std::domain_error("owned 32KB private caller extent/alignment");
 const std::uint64_t lo=std::uint64_t(entry)-0x8000u,hi=std::uint64_t(entry)+68u;
 leaf::Memory local(storage,static_cast<unsigned>(lo),size);Memory m=world;m.add(local);
 std::array<std::uint32_t,16> before{};for(unsigned i=0;i<16;++i)before[i]=m.r32(entry+4u+4u*i);
 const std::uint32_t self=in.cx,P=before[0],Q=before[1],tactical=m.r32(0x821cacu),external=self?m.r32(self+0x19cu):0;
 if(!self||!P||!Q||P==Q||!arena_span(self,0x1d0)||!arena_span(tactical,0xb8)||!arena_span(external,0x310)||!arena_span(P,12)||!arena_span(Q,12))throw std::domain_error("finite owned arena object extents");
 struct Span{std::uint32_t a,n;};const Span spans[]={{self,0x1d0},{tactical,0xb8},{external,0x310},{P,12},{Q,12}};
 for(unsigned i=0;i<5;++i){if(!disjoint(lo,hi-lo,spans[i].a,spans[i].n))throw std::domain_error("public span overlaps private caller");for(unsigned j=0;j<i;++j)if(!disjoint(spans[i].a,spans[i].n,spans[j].a,spans[j].n))throw std::domain_error("public spans overlap");read_span(m,spans[i].a,spans[i].n);}
 if(m.r32(self)!=0x799b60u||m.r32(self+4)!=0x799b44u||m.r32(self+8)!=0x799b3cu||m.r32(self+12)!=0x799b34u||m.r32(self+0x98)!=0||m.r32(self+0x9c)!=0||m.r32(m.r32(self)+0x19c)!=0x5cd850u)throw std::domain_error("normal primary/secondary vptr and zero-index contract");
 if(m.r8(self+0x118)!=1u||m.r8(self+0x119)!=0u||m.r32(self+0x11c)!=100u)throw std::domain_error("normal public constructor scalar fields");
 for(auto off:{0x120u,0x124u,0x128u,0x12cu,0x130u,0x134u,0x168u,0x16cu,0x170u,0x198u})if(m.r32(self+off)!=0)throw std::domain_error("normal public constructor zero fields");
 if(m.r32(P)!=0||m.r32(P+4)!=0||m.r32(P+8)!=0||m.r32(Q)!=256||m.r32(Q+4)!=0||m.r32(Q+8)!=0)throw std::domain_error("finite P/Q endpoint inputs");
 if(m.r32(0x821cac)!=tactical||m.r32(0xaa5f90)!=0||m.r32(0xaa5f94)!=0x3fc00000u||m.r32(0xaa6070)!=16||m.r32(0xaa6074)!=12||m.r8(0xae0c5c)!=1)throw std::domain_error("qualified warm globals");
 for(unsigned i=0;i<144;++i)if(m.r8(0xae0bc0u+i)!=warm_table[i])throw std::domain_error("exact warm 144-byte table required");
 for(const auto&b:ro_bytes)if(m.r8(b.address)!=b.value)throw std::domain_error("exact authenticated Source96 RO input required");
 constexpr unsigned short controls[]{0x037f,0x077f,0x0b7f,0x0f7f,0x027f,0x067f,0x0a7f,0x0e7f,0x007f,0x047f,0x087f,0x0c7f};bool cw_ok=false;for(auto cw:controls)if(incoming.word(0)==cw)cw_ok=true;
 if(!cw_ok||incoming.word(8)!=0xffffu||(incoming.word(4)&~0x3800u)!=0||(in.flags&0x400u))throw std::domain_error("finite x87 CW/TOP/tags/DF precondition");
 State s{};s.ax=in.ax;s.cx=in.cx;s.dx=in.dx;s.bx=in.bx;s.bp=in.bp;s.si=in.si;s.di=in.di;s.arithmetic_flags=in.flags;s.fp.image=incoming;
 Frame f{entry,entry,m.r32(entry)};f_00318470(m,s,f,Operations{});
 if(f.sp!=entry+12u||s.ax!=self+0x138u)throw std::domain_error("Root RET8/full EAX self+138");
 if(s.bx!=in.bx||s.bp!=in.bp||s.si!=in.si||s.di!=in.di||(s.arithmetic_flags&0x400u))throw std::domain_error("preserved nonvolatiles/DF");
 if(s.fp.image.word(0)!=0x0e7fu||(s.fp.image.word(4)&0x3800u)!=(incoming.word(4)&0x3800u)||s.fp.image.word(8)!=0xffffu)throw std::domain_error("qualified post-CW/TOP/empty-tag conditions only");
 for(unsigned i=0;i<24;++i)if(m.r8(self+0x1a0u+i)!=m.r8(external+0x2f8u+i))throw std::domain_error("external 24-byte payload copy");
 Result out{};out.eax=s.ax;out.state=s;for(unsigned i=0;i<16;++i){out.words[i]=m.r32(entry+4u+4u*i);if(out.words[i]!=before[i])throw std::domain_error("all sixteen caller words preserved");}return out;
}
} // namespace ra2::recovered::b1661
