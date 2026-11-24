#include "recovered/recovery_b1650.hpp"
#include <array>
#include <cstdint>
#include <stdexcept>
#include "recovered/recovery_b566_machine.hpp"

namespace ra2::recovered::b1650 {
using namespace ra2::recovered::floating_b61;
namespace floating_b61=ra2::recovered::floating_b61;
using State=ra2::recovered::recovery_b566::State;
using Frame=ra2::recovered::recovery_b566::Frame;
using ra2::recovered::recovery_b566::finish;
using ra2::recovered::recovery_b566::string_instruction;
using ra2::recovered::recovery_b566::Kind;
using ra2::recovered::recovery_b566::Repeat;
using ra2::recovered::recovery_b566::reverse_divide32;
using ra2::recovered::recovery_b566::reverse_divide64;
namespace integer=ra2::recovered::direct_b33::integer;
namespace numeric_b88=ra2::recovered::numeric_b88;
namespace fp=ra2::platform::x87;
inline void need(bool ok,const char*why){if(!ok)throw std::domain_error(why);}
struct Operations{};
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t,const Operations&);
void f_000a94c0(Memory&,State&,Frame&,const Operations&);
void f_00085880(Memory&,State&,Frame&,const Operations&);
void f_00085fa0(Memory&,State&,Frame&,const Operations&);
void f_00032350(Memory&,State&,Frame&,const Operations&);
void f_00031d40(Memory&,State&,Frame&,const Operations&);
void f_000b11f0(Memory&,State&,Frame&,const Operations&);
void f_0036ef45(Memory&,State&,Frame&,const Operations&);
void f_000ab200(Memory&,State&,Frame&,const Operations&);
void f_00097920(Memory&,State&,Frame&,const Operations&);
void f_00097610(Memory&,State&,Frame&,const Operations&);
void f_000112c0(Memory&,State&,Frame&,const Operations&);
void f_000112d0(Memory&,State&,Frame&,const Operations&);
void f_000112f0(Memory&,State&,Frame&,const Operations&);
void f_00011370(Memory&,State&,Frame&,const Operations&);
void f_000113b0(Memory&,State&,Frame&,const Operations&);
void f_000113c0(Memory&,State&,Frame&,const Operations&);
void f_000312f0(Memory&,State&,Frame&,const Operations&);
void f_00031310(Memory&,State&,Frame&,const Operations&);
void f_00031320(Memory&,State&,Frame&,const Operations&);
void f_00031370(Memory&,State&,Frame&,const Operations&);
void f_00031790(Memory&,State&,Frame&,const Operations&);
void f_000317a0(Memory&,State&,Frame&,const Operations&);
void f_00031b80(Memory&,State&,Frame&,const Operations&);
void f_00031ec0(Memory&,State&,Frame&,const Operations&);
void f_00031f70(Memory&,State&,Frame&,const Operations&);
void f_00032010(Memory&,State&,Frame&,const Operations&);
void f_00032210(Memory&,State&,Frame&,const Operations&);
void f_00097830(Memory&,State&,Frame&,const Operations&);
void f_0025ace0(Memory&,State&,Frame&,const Operations&);
void f_0009f0c0(Memory&,State&,Frame&,const Operations&);
void f_000fe550(Memory&,State&,Frame&,const Operations&);
void f_00034a00(Memory&,State&,Frame&,const Operations&);
void f_00360cf0(Memory&,State&,Frame&,const Operations&);
void f_00360ad0(Memory&,State&,Frame&,const Operations&);
void f_00035420(Memory&,State&,Frame&,const Operations&);
void f_00035400(Memory&,State&,Frame&,const Operations&);
void f_00361440(Memory&,State&,Frame&,const Operations&);
void f_00011290(Memory&,State&,Frame&,const Operations&);
void f_0001fdf0(Memory&,State&,Frame&,const Operations&);
void f_000ab230(Memory&,State&,Frame&,const Operations&);
void f_0035fa70(Memory&,State&,Frame&,const Operations&);
void f_0035fd00(Memory&,State&,Frame&,const Operations&);
void f_00053ab0(Memory&,State&,Frame&,const Operations&);

void f_000a94c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004a94c0: { // 0x4a94c0: 81ec54010000 SUB ESP,0x154
    f.sp = integer::sub(f.sp,0x00000154u,32,flags);
  }
  L004a94c6: { // 0x4a94c6: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004a94c7: { // 0x4a94c7: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004a94c8: { // 0x4a94c8: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004a94c9: { // 0x4a94c9: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004a94cb: { // 0x4a94cb: b8c2010000 MOV EAX,0x1c2
    s.ax = 0x000001c2u;
  }
  L004a94d0: { // 0x4a94d0: 8bea MOV EBP,EDX
    s.bp = s.dx;
  }
  L004a94d2: { // 0x4a94d2: b92c010000 MOV ECX,0x12c
    s.cx = 0x0000012cu;
  }
  L004a94d7: { // 0x4a94d7: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004a94d8: { // 0x4a94d8: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L004a94dc: { // 0x4a94dc: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004a94de: { // 0x4a94de: babe000000 MOV EDX,0xbe
    s.dx = 0x000000beu;
  }
  L004a94e3: { // 0x4a94e3: bf50000000 MOV EDI,0x50
    s.di = 0x00000050u;
  }
  L004a94e8: { // 0x4a94e8: 894c2434 MOV dword ptr [ESP + 0x34],ECX
    m.w32((f.sp+0x00000034u), s.cx);
  }
  L004a94ec: { // 0x4a94ec: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004a94ee: { // 0x4a94ee: 89542438 MOV dword ptr [ESP + 0x38],EDX
    m.w32((f.sp+0x00000038u), s.dx);
  }
  L004a94f2: { // 0x4a94f2: 897c243c MOV dword ptr [ESP + 0x3c],EDI
    m.w32((f.sp+0x0000003cu), s.di);
  }
  L004a94f6: { // 0x4a94f6: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),4887804u,op); flags=s.arithmetic_flags;
  }
  L004a94fc: { // 0x4a94fc: 8b0d941c8200 MOV ECX,dword ptr [0x00821c94]
    s.cx = m.r32((0x00821c94u));
  }
  L004a9502: { // 0x4a9502: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L004a9504: { // 0x4a9504: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L004a9506: { // 0x4a9506: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),4887820u,op); flags=s.arithmetic_flags;
  }
  L004a950c: { // 0x4a950c: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  L004a950e: { // 0x4a950e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004a9510: { // 0x4a9510: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004a9511: { // 0x4a9511: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004a9513: { // 0x4a9513: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L004a9515: { // 0x4a9515: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004a9517: { // 0x4a9517: d1ff SAR EDI,0x1
    s.di = integer::shift(s.di,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L004a9519: { // 0x4a9519: ff507c CALL dword ptr [EAX + 0x7c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000007cu)),4887836u,op); flags=s.arithmetic_flags;
  }
  L004a951c: { // 0x4a951c: 8b0d941c8200 MOV ECX,dword ptr [0x00821c94]
    s.cx = m.r32((0x00821c94u));
  }
  L004a9522: { // 0x4a9522: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L004a9524: { // 0x4a9524: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L004a9526: { // 0x4a9526: ff527c CALL dword ptr [EDX + 0x7c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000007cu)),4887849u,op); flags=s.arithmetic_flags;
  }
  L004a9529: { // 0x4a9529: 2bc3 SUB EAX,EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L004a952b: { // 0x4a952b: b92c010000 MOV ECX,0x12c
    s.cx = 0x0000012cu;
  }
  L004a9530: { // 0x4a9530: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004a9531: { // 0x4a9531: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004a9533: { // 0x4a9533: 894c242c MOV dword ptr [ESP + 0x2c],ECX
    m.w32((f.sp+0x0000002cu), s.cx);
  }
  L004a9537: { // 0x4a9537: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L004a9539: { // 0x4a9539: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L004a953d: { // 0x4a953d: b8c2010000 MOV EAX,0x1c2
    s.ax = 0x000001c2u;
  }
  L004a9542: { // 0x4a9542: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L004a9546: { // 0x4a9546: 6a50 PUSH 0x50
    f.push(m,0x00000050u);
  }
  L004a9548: { // 0x4a9548: 8d44241c LEA EAX,[ESP + 0x1c]
    s.ax = (f.sp+0x0000001cu);
  }
  L004a954c: { // 0x4a954c: 68be000000 PUSH 0xbe
    f.push(m,0x000000beu);
  }
  L004a9551: { // 0x4a9551: 8d4c2428 LEA ECX,[ESP + 0x28]
    s.cx = (f.sp+0x00000028u);
  }
  L004a9555: { // 0x4a9555: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004a9556: { // 0x4a9556: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004a9557: { // 0x4a9557: 8d4c2438 LEA ECX,[ESP + 0x38]
    s.cx = (f.sp+0x00000038u);
  }
  L004a955b: { // 0x4a955b: 897c242c MOV dword ptr [ESP + 0x2c],EDI
    m.w32((f.sp+0x0000002cu), s.di);
  }
  L004a955f: { // 0x4a955f: e89cbef8ff CALL 0x00435400
    s.arithmetic_flags=flags; invoke(m,s,f,0x00435400u,4887908u,op); flags=s.arithmetic_flags;
  }
  L004a9564: { // 0x4a9564: 8d4c2458 LEA ECX,[ESP + 0x58]
    s.cx = (f.sp+0x00000058u);
  }
  L004a9568: { // 0x4a9568: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004a9569: { // 0x4a9569: e842a5faff CALL 0x00453ab0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00453ab0u,4887918u,op); flags=s.arithmetic_flags;
  }
  L004a956e: { // 0x4a956e: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L004a9570: { // 0x4a9570: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L004a9572: { // 0x4a9572: 89542440 MOV dword ptr [ESP + 0x40],EDX
    m.w32((f.sp+0x00000040u), s.dx);
  }
  L004a9576: { // 0x4a9576: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004a9577: { // 0x4a9577: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L004a957a: { // 0x4a957a: 68e8030000 PUSH 0x3e8
    f.push(m,0x000003e8u);
  }
  L004a957f: { // 0x4a957f: 894c244c MOV dword ptr [ESP + 0x4c],ECX
    m.w32((f.sp+0x0000004cu), s.cx);
  }
  L004a9583: { // 0x4a9583: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004a9584: { // 0x4a9584: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L004a9587: { // 0x4a9587: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004a9588: { // 0x4a9588: 89542458 MOV dword ptr [ESP + 0x58],EDX
    m.w32((f.sp+0x00000058u), s.dx);
  }
  L004a958c: { // 0x4a958c: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004a958d: { // 0x4a958d: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L004a9590: { // 0x4a9590: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L004a9592: { // 0x4a9592: 89442460 MOV dword ptr [ESP + 0x60],EAX
    m.w32((f.sp+0x00000060u), s.ax);
  }
  L004a9596: { // 0x4a9596: 895c2424 MOV dword ptr [ESP + 0x24],EBX
    m.w32((f.sp+0x00000024u), s.bx);
  }
  L004a959a: { // 0x4a959a: 895c2428 MOV dword ptr [ESP + 0x28],EBX
    m.w32((f.sp+0x00000028u), s.bx);
  }
  L004a959e: { // 0x4a959e: e8ddc2fdff CALL 0x00485880
    s.arithmetic_flags=flags; invoke(m,s,f,0x00485880u,4887971u,op); flags=s.arithmetic_flags;
  }
  L004a95a3: { // 0x4a95a3: 8d4c2450 LEA ECX,[ESP + 0x50]
    s.cx = (f.sp+0x00000050u);
  }
  L004a95a7: { // 0x4a95a7: 8d542420 LEA EDX,[ESP + 0x20]
    s.dx = (f.sp+0x00000020u);
  }
  L004a95ab: { // 0x4a95ab: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004a95ac: { // 0x4a95ac: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004a95ad: { // 0x4a95ad: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004a95ae: { // 0x4a95ae: 8d44244c LEA EAX,[ESP + 0x4c]
    s.ax = (f.sp+0x0000004cu);
  }
  L004a95b2: { // 0x4a95b2: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004a95b3: { // 0x4a95b3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004a95b4: { // 0x4a95b4: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004a95b5: { // 0x4a95b5: 8b0d941c8200 MOV ECX,dword ptr [0x00821c94]
    s.cx = m.r32((0x00821c94u));
  }
  L004a95bb: { // 0x4a95bb: 8bd5 MOV EDX,EBP
    s.dx = s.bp;
  }
  L004a95bd: { // 0x4a95bd: e8fe5affff CALL 0x0049f0c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0049f0c0u,4888002u,op); flags=s.arithmetic_flags;
  }
  L004a95c2: { // 0x4a95c2: 8bb42468010000 MOV ESI,dword ptr [ESP + 0x168]
    s.si = m.r32((f.sp+0x00000168u));
  }
  L004a95c9: { // 0x4a95c9: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L004a95cb: { // 0x4a95cb: 0f841d020000 JZ 0x004a97ee
    if(integer::condition("JZ",flags)) goto L004a97ee;
  }
  L004a95d1: { // 0x4a95d1: 8d4e64 LEA ECX,[ESI + 0x64]
    s.cx = (s.si+0x00000064u);
  }
  L004a95d4: { // 0x4a95d4: 8d942414010000 LEA EDX,[ESP + 0x114]
    s.dx = (f.sp+0x00000114u);
  }
  L004a95db: { // 0x4a95db: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004a95dc: { // 0x4a95dc: 68ac137c00 PUSH 0x7c13ac
    f.push(m,0x007c13acu);
  }
  L004a95e1: { // 0x4a95e1: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004a95e2: { // 0x4a95e2: e8bd5a2c00 CALL 0x0076f0a4
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076f0a4u,4888039u,op); flags=s.arithmetic_flags;
  }
  L004a95e7: { // 0x4a95e7: 8a842478010000 MOV AL,byte ptr [ESP + 0x178]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000178u)));
  }
  L004a95ee: { // 0x4a95ee: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L004a95f1: { // 0x4a95f1: 3ac3 CMP AL,BL
    (void)integer::sub((s.ax & 0xffu),(s.bx & 0xffu),8,flags);
  }
  L004a95f3: { // 0x4a95f3: 741f JZ 0x004a9614
    if(integer::condition("JZ",flags)) goto L004a9614;
  }
  L004a95f5: { // 0x4a95f5: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004a95f7: { // 0x4a95f7: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004a95f9: { // 0x4a95f9: ff90ac000000 CALL dword ptr [EAX + 0xac]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000000acu)),4888063u,op); flags=s.arithmetic_flags;
  }
  L004a95ff: { // 0x4a95ff: 8d4c2460 LEA ECX,[ESP + 0x60]
    s.cx = (f.sp+0x00000060u);
  }
  L004a9603: { // 0x4a9603: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004a9604: { // 0x4a9604: 6898137c00 PUSH 0x7c1398
    f.push(m,0x007c1398u);
  }
  L004a9609: { // 0x4a9609: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004a960a: { // 0x4a960a: e8955a2c00 CALL 0x0076f0a4
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076f0a4u,4888079u,op); flags=s.arithmetic_flags;
  }
  L004a960f: { // 0x4a960f: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L004a9612: { // 0x4a9612: eb12 JMP 0x004a9626
    goto L004a9626;
  }
  L004a9614: { // 0x4a9614: 8d542460 LEA EDX,[ESP + 0x60]
    s.dx = (f.sp+0x00000060u);
  }
  L004a9618: { // 0x4a9618: 6884137c00 PUSH 0x7c1384
    f.push(m,0x007c1384u);
  }
  L004a961d: { // 0x4a961d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004a961e: { // 0x4a961e: e8815a2c00 CALL 0x0076f0a4
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076f0a4u,4888099u,op); flags=s.arithmetic_flags;
  }
  L004a9623: { // 0x4a9623: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L004a9626: { // 0x4a9626: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004a9627: { // 0x4a9627: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004a9629: { // 0x4a9629: e802b52200 CALL 0x006d4b30
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d4b30u,4888110u,op); flags=s.arithmetic_flags;
  }
  L004a962e: { // 0x4a962e: 3918 CMP dword ptr [EAX],EBX
    (void)integer::sub(m.r32((s.ax)),s.bx,32,flags);
  }
  L004a9630: { // 0x4a9630: 7425 JZ 0x004a9657
    if(integer::condition("JZ",flags)) goto L004a9657;
  }
  L004a9632: { // 0x4a9632: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004a9633: { // 0x4a9633: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004a9635: { // 0x4a9635: e8f6b42200 CALL 0x006d4b30
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d4b30u,4888122u,op); flags=s.arithmetic_flags;
  }
  L004a963a: { // 0x4a963a: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L004a963c: { // 0x4a963c: 83c064 ADD EAX,0x64
    s.ax = integer::add(s.ax,0x00000064u,32,flags);
  }
  L004a963f: { // 0x4a963f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004a9640: { // 0x4a9640: 8d84248c000000 LEA EAX,[ESP + 0x8c]
    s.ax = (f.sp+0x0000008cu);
  }
  L004a9647: { // 0x4a9647: 6868137c00 PUSH 0x7c1368
    f.push(m,0x007c1368u);
  }
  L004a964c: { // 0x4a964c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004a964d: { // 0x4a964d: e8525a2c00 CALL 0x0076f0a4
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076f0a4u,4888146u,op); flags=s.arithmetic_flags;
  }
  L004a9652: { // 0x4a9652: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L004a9655: { // 0x4a9655: eb15 JMP 0x004a966c
    goto L004a966c;
  }
  L004a9657: { // 0x4a9657: 8d8c2488000000 LEA ECX,[ESP + 0x88]
    s.cx = (f.sp+0x00000088u);
  }
  L004a965e: { // 0x4a965e: 6848137c00 PUSH 0x7c1348
    f.push(m,0x007c1348u);
  }
  L004a9663: { // 0x4a9663: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004a9664: { // 0x4a9664: e83b5a2c00 CALL 0x0076f0a4
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076f0a4u,4888169u,op); flags=s.arithmetic_flags;
  }
  L004a9669: { // 0x4a9669: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L004a966c: { // 0x4a966c: 8b969c000000 MOV EDX,dword ptr [ESI + 0x9c]
    s.dx = m.r32((s.si+0x0000009cu));
  }
  L004a9672: { // 0x4a9672: 8d8c24d8000000 LEA ECX,[ESP + 0xd8]
    s.cx = (f.sp+0x000000d8u);
  }
  L004a9679: { // 0x4a9679: 8b0495288e7800 MOV EAX,dword ptr [EDX*0x4 + 0x788e28]
    s.ax = m.r32(((s.dx * 0x00000004u)+0x00788e28u));
  }
  L004a9680: { // 0x4a9680: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004a9681: { // 0x4a9681: 6834137c00 PUSH 0x7c1334
    f.push(m,0x007c1334u);
  }
  L004a9686: { // 0x4a9686: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004a9687: { // 0x4a9687: e8185a2c00 CALL 0x0076f0a4
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076f0a4u,4888204u,op); flags=s.arithmetic_flags;
  }
  L004a968c: { // 0x4a968c: 8a842478010000 MOV AL,byte ptr [ESP + 0x178]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000178u)));
  }
  L004a9693: { // 0x4a9693: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L004a9696: { // 0x4a9696: 3ac3 CMP AL,BL
    (void)integer::sub((s.ax & 0xffu),(s.bx & 0xffu),8,flags);
  }
  L004a9698: { // 0x4a9698: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L004a969d: { // 0x4a969d: b92c137c00 MOV ECX,0x7c132c
    s.cx = 0x007c132cu;
  }
  L004a96a2: { // 0x4a96a2: 7505 JNZ 0x004a96a9
    if(integer::condition("JNZ",flags)) goto L004a96a9;
  }
  L004a96a4: { // 0x4a96a4: b928137c00 MOV ECX,0x7c1328
    s.cx = 0x007c1328u;
  }
  L004a96a9: { // 0x4a96a9: e832161b00 CALL 0x0065ace0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0065ace0u,4888238u,op); flags=s.arithmetic_flags;
  }
  L004a96ae: { // 0x4a96ae: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L004a96b2: { // 0x4a96b2: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L004a96b6: { // 0x4a96b6: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L004a96b8: { // 0x4a96b8: 81c12c010000 ADD ECX,0x12c
    s.cx = integer::add(s.cx,0x0000012cu,32,flags);
  }
  L004a96be: { // 0x4a96be: 8d82c2010000 LEA EAX,[EDX + 0x1c2]
    s.ax = (s.dx+0x000001c2u);
  }
  L004a96c4: { // 0x4a96c4: 6a46 PUSH 0x46
    f.push(m,0x00000046u);
  }
  L004a96c6: { // 0x4a96c6: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L004a96ca: { // 0x4a96ca: 8b0d941c8200 MOV ECX,dword ptr [0x00821c94]
    s.cx = m.r32((0x00821c94u));
  }
  L004a96d0: { // 0x4a96d0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004a96d1: { // 0x4a96d1: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L004a96d5: { // 0x4a96d5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004a96d6: { // 0x4a96d6: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004a96d7: { // 0x4a96d7: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L004a96db: { // 0x4a96db: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L004a96dd: { // 0x4a96dd: 8d542460 LEA EDX,[ESP + 0x60]
    s.dx = (f.sp+0x00000060u);
  }
  L004a96e1: { // 0x4a96e1: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004a96e2: { // 0x4a96e2: ff5078 CALL dword ptr [EAX + 0x78]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000078u)),4888293u,op); flags=s.arithmetic_flags;
  }
  L004a96e5: { // 0x4a96e5: 8d8c2424010000 LEA ECX,[ESP + 0x124]
    s.cx = (f.sp+0x00000124u);
  }
  L004a96ec: { // 0x4a96ec: 8d542430 LEA EDX,[ESP + 0x30]
    s.dx = (f.sp+0x00000030u);
  }
  L004a96f0: { // 0x4a96f0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004a96f1: { // 0x4a96f1: a1941c8200 MOV EAX,[0x00821c94]
    s.ax = m.r32((0x00821c94u));
  }
  L004a96f6: { // 0x4a96f6: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004a96f7: { // 0x4a96f7: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004a96f8: { // 0x4a96f8: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004a96f9: { // 0x4a96f9: e822e2feff CALL 0x00497920
    s.arithmetic_flags=flags; invoke(m,s,f,0x00497920u,4888318u,op); flags=s.arithmetic_flags;
  }
  L004a96fe: { // 0x4a96fe: 8b4c243c MOV ECX,dword ptr [ESP + 0x3c]
    s.cx = m.r32((f.sp+0x0000003cu));
  }
  L004a9702: { // 0x4a9702: 8b442438 MOV EAX,dword ptr [ESP + 0x38]
    s.ax = m.r32((f.sp+0x00000038u));
  }
  L004a9706: { // 0x4a9706: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L004a9709: { // 0x4a9709: 81c13b010000 ADD ECX,0x13b
    s.cx = integer::add(s.cx,0x0000013bu,32,flags);
  }
  L004a970f: { // 0x4a970f: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L004a9713: { // 0x4a9713: 8b0d941c8200 MOV ECX,dword ptr [0x00821c94]
    s.cx = m.r32((0x00821c94u));
  }
  L004a9719: { // 0x4a9719: 6a46 PUSH 0x46
    f.push(m,0x00000046u);
  }
  L004a971b: { // 0x4a971b: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004a971c: { // 0x4a971c: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L004a9720: { // 0x4a9720: 05c2010000 ADD EAX,0x1c2
    s.ax = integer::add(s.ax,0x000001c2u,32,flags);
  }
  L004a9725: { // 0x4a9725: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004a9726: { // 0x4a9726: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004a9727: { // 0x4a9727: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L004a972b: { // 0x4a972b: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L004a972d: { // 0x4a972d: 8d542460 LEA EDX,[ESP + 0x60]
    s.dx = (f.sp+0x00000060u);
  }
  L004a9731: { // 0x4a9731: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004a9732: { // 0x4a9732: ff5078 CALL dword ptr [EAX + 0x78]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000078u)),4888373u,op); flags=s.arithmetic_flags;
  }
  L004a9735: { // 0x4a9735: 8d8c2498000000 LEA ECX,[ESP + 0x98]
    s.cx = (f.sp+0x00000098u);
  }
  L004a973c: { // 0x4a973c: 8d542430 LEA EDX,[ESP + 0x30]
    s.dx = (f.sp+0x00000030u);
  }
  L004a9740: { // 0x4a9740: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004a9741: { // 0x4a9741: a1941c8200 MOV EAX,[0x00821c94]
    s.ax = m.r32((0x00821c94u));
  }
  L004a9746: { // 0x4a9746: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004a9747: { // 0x4a9747: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004a9748: { // 0x4a9748: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004a9749: { // 0x4a9749: e8d2e1feff CALL 0x00497920
    s.arithmetic_flags=flags; invoke(m,s,f,0x00497920u,4888398u,op); flags=s.arithmetic_flags;
  }
  L004a974e: { // 0x4a974e: 8b4c243c MOV ECX,dword ptr [ESP + 0x3c]
    s.cx = m.r32((f.sp+0x0000003cu));
  }
  L004a9752: { // 0x4a9752: 8b442438 MOV EAX,dword ptr [ESP + 0x38]
    s.ax = m.r32((f.sp+0x00000038u));
  }
  L004a9756: { // 0x4a9756: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L004a9759: { // 0x4a9759: 81c14a010000 ADD ECX,0x14a
    s.cx = integer::add(s.cx,0x0000014au,32,flags);
  }
  L004a975f: { // 0x4a975f: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L004a9763: { // 0x4a9763: 8b0d941c8200 MOV ECX,dword ptr [0x00821c94]
    s.cx = m.r32((0x00821c94u));
  }
  L004a9769: { // 0x4a9769: 6a46 PUSH 0x46
    f.push(m,0x00000046u);
  }
  L004a976b: { // 0x4a976b: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004a976c: { // 0x4a976c: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L004a9770: { // 0x4a9770: 05c2010000 ADD EAX,0x1c2
    s.ax = integer::add(s.ax,0x000001c2u,32,flags);
  }
  L004a9775: { // 0x4a9775: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004a9776: { // 0x4a9776: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004a9777: { // 0x4a9777: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L004a977b: { // 0x4a977b: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L004a977d: { // 0x4a977d: 8d542460 LEA EDX,[ESP + 0x60]
    s.dx = (f.sp+0x00000060u);
  }
  L004a9781: { // 0x4a9781: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004a9782: { // 0x4a9782: ff5078 CALL dword ptr [EAX + 0x78]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000078u)),4888453u,op); flags=s.arithmetic_flags;
  }
  L004a9785: { // 0x4a9785: 8d8c24e8000000 LEA ECX,[ESP + 0xe8]
    s.cx = (f.sp+0x000000e8u);
  }
  L004a978c: { // 0x4a978c: 8d542430 LEA EDX,[ESP + 0x30]
    s.dx = (f.sp+0x00000030u);
  }
  L004a9790: { // 0x4a9790: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004a9791: { // 0x4a9791: a1941c8200 MOV EAX,[0x00821c94]
    s.ax = m.r32((0x00821c94u));
  }
  L004a9796: { // 0x4a9796: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004a9797: { // 0x4a9797: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004a9798: { // 0x4a9798: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004a9799: { // 0x4a9799: e882e1feff CALL 0x00497920
    s.arithmetic_flags=flags; invoke(m,s,f,0x00497920u,4888478u,op); flags=s.arithmetic_flags;
  }
  L004a979e: { // 0x4a979e: 8b442438 MOV EAX,dword ptr [ESP + 0x38]
    s.ax = m.r32((f.sp+0x00000038u));
  }
  L004a97a2: { // 0x4a97a2: 8b4c243c MOV ECX,dword ptr [ESP + 0x3c]
    s.cx = m.r32((f.sp+0x0000003cu));
  }
  L004a97a6: { // 0x4a97a6: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L004a97a9: { // 0x4a97a9: 05c2010000 ADD EAX,0x1c2
    s.ax = integer::add(s.ax,0x000001c2u,32,flags);
  }
  L004a97ae: { // 0x4a97ae: 81c159010000 ADD ECX,0x159
    s.cx = integer::add(s.cx,0x00000159u,32,flags);
  }
  L004a97b4: { // 0x4a97b4: 6a46 PUSH 0x46
    f.push(m,0x00000046u);
  }
  L004a97b6: { // 0x4a97b6: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L004a97ba: { // 0x4a97ba: 8b0d941c8200 MOV ECX,dword ptr [0x00821c94]
    s.cx = m.r32((0x00821c94u));
  }
  L004a97c0: { // 0x4a97c0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004a97c1: { // 0x4a97c1: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L004a97c5: { // 0x4a97c5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004a97c6: { // 0x4a97c6: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004a97c7: { // 0x4a97c7: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L004a97cb: { // 0x4a97cb: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L004a97cd: { // 0x4a97cd: 8d542460 LEA EDX,[ESP + 0x60]
    s.dx = (f.sp+0x00000060u);
  }
  L004a97d1: { // 0x4a97d1: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004a97d2: { // 0x4a97d2: ff5078 CALL dword ptr [EAX + 0x78]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000078u)),4888533u,op); flags=s.arithmetic_flags;
  }
  L004a97d5: { // 0x4a97d5: 8d4c2470 LEA ECX,[ESP + 0x70]
    s.cx = (f.sp+0x00000070u);
  }
  L004a97d9: { // 0x4a97d9: 8d542430 LEA EDX,[ESP + 0x30]
    s.dx = (f.sp+0x00000030u);
  }
  L004a97dd: { // 0x4a97dd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004a97de: { // 0x4a97de: a1941c8200 MOV EAX,[0x00821c94]
    s.ax = m.r32((0x00821c94u));
  }
  L004a97e3: { // 0x4a97e3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004a97e4: { // 0x4a97e4: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004a97e5: { // 0x4a97e5: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004a97e6: { // 0x4a97e6: e835e1feff CALL 0x00497920
    s.arithmetic_flags=flags; invoke(m,s,f,0x00497920u,4888555u,op); flags=s.arithmetic_flags;
  }
  L004a97eb: { // 0x4a97eb: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L004a97ee: { // 0x4a97ee: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004a97ef: { // 0x4a97ef: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004a97f0: { // 0x4a97f0: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004a97f1: { // 0x4a97f1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004a97f2: { // 0x4a97f2: 81c454010000 ADD ESP,0x154
    f.sp = integer::add(f.sp,0x00000154u,32,flags);
  }
  L004a97f8: { // 0x4a97f8: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}

void f_00085880(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00485880: { // 0x485880: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00485881: { // 0x485881: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00485883: { // 0x485883: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L00485886: { // 0x485886: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00485888: { // 0x485888: 7505 JNZ 0x0048588f
    if(integer::condition("JNZ",flags)) goto L0048588f;
  }
  L0048588a: { // 0x48588a: e851e0ffff CALL 0x004838e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004838e0u,4741263u,op); flags=s.arithmetic_flags;
  }
  L0048588f: { // 0x48588f: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L00485893: { // 0x485893: a810 TEST AL,0x10
    (void)integer::logical(((s.ax & 0xffu))&(0x00000010u),8,flags);
  }
  L00485895: { // 0x485895: 744c JZ 0x004858e3
    if(integer::condition("JZ",flags)) goto L004858e3;
  }
  L00485897: { // 0x485897: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L0048589a: { // 0x48589a: 7416 JZ 0x004858b2
    if(integer::condition("JZ",flags)) goto L004858b2;
  }
  L0048589c: { // 0x48589c: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L0048589f: { // 0x48589f: 740a JZ 0x004858ab
    if(integer::condition("JZ",flags)) goto L004858ab;
  }
  L004858a1: { // 0x4858a1: 8b86c0000000 MOV EAX,dword ptr [ESI + 0xc0]
    s.ax = m.r32((s.si+0x000000c0u));
  }
  L004858a7: { // 0x4858a7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004858a8: { // 0x4858a8: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004858ab: { // 0x4858ab: 8b4658 MOV EAX,dword ptr [ESI + 0x58]
    s.ax = m.r32((s.si+0x00000058u));
  }
  L004858ae: { // 0x4858ae: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004858af: { // 0x4858af: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004858b2: { // 0x4858b2: 8505a8eb7b00 TEST dword ptr [0x007beba8],EAX
    (void)integer::logical((m.r32((0x007beba8u)))&(s.ax),32,flags);
  }
  L004858b8: { // 0x4858b8: 7416 JZ 0x004858d0
    if(integer::condition("JZ",flags)) goto L004858d0;
  }
  L004858ba: { // 0x4858ba: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L004858bd: { // 0x4858bd: 740a JZ 0x004858c9
    if(integer::condition("JZ",flags)) goto L004858c9;
  }
  L004858bf: { // 0x4858bf: 8b869c000000 MOV EAX,dword ptr [ESI + 0x9c]
    s.ax = m.r32((s.si+0x0000009cu));
  }
  L004858c5: { // 0x4858c5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004858c6: { // 0x4858c6: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004858c9: { // 0x4858c9: 8b4630 MOV EAX,dword ptr [ESI + 0x30]
    s.ax = m.r32((s.si+0x00000030u));
  }
  L004858cc: { // 0x4858cc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004858cd: { // 0x4858cd: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004858d0: { // 0x4858d0: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L004858d3: { // 0x4858d3: 7407 JZ 0x004858dc
    if(integer::condition("JZ",flags)) goto L004858dc;
  }
  L004858d5: { // 0x4858d5: 8b4670 MOV EAX,dword ptr [ESI + 0x70]
    s.ax = m.r32((s.si+0x00000070u));
  }
  L004858d8: { // 0x4858d8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004858d9: { // 0x4858d9: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004858dc: { // 0x4858dc: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  L004858df: { // 0x4858df: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004858e0: { // 0x4858e0: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004858e3: { // 0x4858e3: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L004858e5: { // 0x4858e5: 83e106 AND ECX,0x6
    s.cx = integer::logical((s.cx)&(0x00000006u),32,flags);
  }
  L004858e8: { // 0x4858e8: 83e902 SUB ECX,0x2
    s.cx = integer::sub(s.cx,0x00000002u,32,flags);
  }
  L004858eb: { // 0x4858eb: 0f84e0010000 JZ 0x00485ad1
    if(integer::condition("JZ",flags)) goto L00485ad1;
  }
  L004858f1: { // 0x4858f1: 83e902 SUB ECX,0x2
    s.cx = integer::sub(s.cx,0x00000002u,32,flags);
  }
  L004858f4: { // 0x4858f4: 0f844f010000 JZ 0x00485a49
    if(integer::condition("JZ",flags)) goto L00485a49;
  }
  L004858fa: { // 0x4858fa: 83e902 SUB ECX,0x2
    s.cx = integer::sub(s.cx,0x00000002u,32,flags);
  }
  L004858fd: { // 0x4858fd: 0f84e0000000 JZ 0x004859e3
    if(integer::condition("JZ",flags)) goto L004859e3;
  }
  L00485903: { // 0x485903: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L00485905: { // 0x485905: 7422 JZ 0x00485929
    if(integer::condition("JZ",flags)) goto L00485929;
  }
  L00485907: { // 0x485907: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L0048590a: { // 0x48590a: 7407 JZ 0x00485913
    if(integer::condition("JZ",flags)) goto L00485913;
  }
  L0048590c: { // 0x48590c: 8b4654 MOV EAX,dword ptr [ESI + 0x54]
    s.ax = m.r32((s.si+0x00000054u));
  }
  L0048590f: { // 0x48590f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485910: { // 0x485910: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485913: { // 0x485913: 8505a8eb7b00 TEST dword ptr [0x007beba8],EAX
    (void)integer::logical((m.r32((0x007beba8u)))&(s.ax),32,flags);
  }
  L00485919: { // 0x485919: 7407 JZ 0x00485922
    if(integer::condition("JZ",flags)) goto L00485922;
  }
  L0048591b: { // 0x48591b: 8b462c MOV EAX,dword ptr [ESI + 0x2c]
    s.ax = m.r32((s.si+0x0000002cu));
  }
  L0048591e: { // 0x48591e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0048591f: { // 0x48591f: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485922: { // 0x485922: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L00485925: { // 0x485925: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485926: { // 0x485926: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485929: { // 0x485929: a820 TEST AL,0x20
    (void)integer::logical(((s.ax & 0xffu))&(0x00000020u),8,flags);
  }
  L0048592b: { // 0x48592b: 743e JZ 0x0048596b
    if(integer::condition("JZ",flags)) goto L0048596b;
  }
  L0048592d: { // 0x48592d: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L00485930: { // 0x485930: 740f JZ 0x00485941
    if(integer::condition("JZ",flags)) goto L00485941;
  }
  L00485932: { // 0x485932: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485935: { // 0x485935: 7448 JZ 0x0048597f
    if(integer::condition("JZ",flags)) goto L0048597f;
  }
  L00485937: { // 0x485937: 8b86bc000000 MOV EAX,dword ptr [ESI + 0xbc]
    s.ax = m.r32((s.si+0x000000bcu));
  }
  L0048593d: { // 0x48593d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0048593e: { // 0x48593e: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485941: { // 0x485941: 8505a8eb7b00 TEST dword ptr [0x007beba8],EAX
    (void)integer::logical((m.r32((0x007beba8u)))&(s.ax),32,flags);
  }
  L00485947: { // 0x485947: 740f JZ 0x00485958
    if(integer::condition("JZ",flags)) goto L00485958;
  }
  L00485949: { // 0x485949: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L0048594c: { // 0x48594c: 744f JZ 0x0048599d
    if(integer::condition("JZ",flags)) goto L0048599d;
  }
  L0048594e: { // 0x48594e: 8b8698000000 MOV EAX,dword ptr [ESI + 0x98]
    s.ax = m.r32((s.si+0x00000098u));
  }
  L00485954: { // 0x485954: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485955: { // 0x485955: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485958: { // 0x485958: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L0048595b: { // 0x48595b: 7407 JZ 0x00485964
    if(integer::condition("JZ",flags)) goto L00485964;
  }
  L0048595d: { // 0x48595d: 8b4668 MOV EAX,dword ptr [ESI + 0x68]
    s.ax = m.r32((s.si+0x00000068u));
  }
  L00485960: { // 0x485960: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485961: { // 0x485961: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485964: { // 0x485964: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L00485967: { // 0x485967: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485968: { // 0x485968: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0048596b: { // 0x48596b: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L0048596e: { // 0x48596e: 7416 JZ 0x00485986
    if(integer::condition("JZ",flags)) goto L00485986;
  }
  L00485970: { // 0x485970: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485973: { // 0x485973: 740a JZ 0x0048597f
    if(integer::condition("JZ",flags)) goto L0048597f;
  }
  L00485975: { // 0x485975: 8b86bc000000 MOV EAX,dword ptr [ESI + 0xbc]
    s.ax = m.r32((s.si+0x000000bcu));
  }
  L0048597b: { // 0x48597b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0048597c: { // 0x48597c: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0048597f: { // 0x48597f: 8b4650 MOV EAX,dword ptr [ESI + 0x50]
    s.ax = m.r32((s.si+0x00000050u));
  }
  L00485982: { // 0x485982: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485983: { // 0x485983: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485986: { // 0x485986: 8505a8eb7b00 TEST dword ptr [0x007beba8],EAX
    (void)integer::logical((m.r32((0x007beba8u)))&(s.ax),32,flags);
  }
  L0048598c: { // 0x48598c: 7416 JZ 0x004859a4
    if(integer::condition("JZ",flags)) goto L004859a4;
  }
  L0048598e: { // 0x48598e: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485991: { // 0x485991: 740a JZ 0x0048599d
    if(integer::condition("JZ",flags)) goto L0048599d;
  }
  L00485993: { // 0x485993: 8b8698000000 MOV EAX,dword ptr [ESI + 0x98]
    s.ax = m.r32((s.si+0x00000098u));
  }
  L00485999: { // 0x485999: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0048599a: { // 0x48599a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0048599d: { // 0x48599d: 8b4628 MOV EAX,dword ptr [ESI + 0x28]
    s.ax = m.r32((s.si+0x00000028u));
  }
  L004859a0: { // 0x4859a0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004859a1: { // 0x4859a1: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004859a4: { // 0x4859a4: f6c480 TEST AH,0x80
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000080u),8,flags);
  }
  L004859a7: { // 0x4859a7: 740a JZ 0x004859b3
    if(integer::condition("JZ",flags)) goto L004859b3;
  }
  L004859a9: { // 0x4859a9: 8b8680000000 MOV EAX,dword ptr [ESI + 0x80]
    s.ax = m.r32((s.si+0x00000080u));
  }
  L004859af: { // 0x4859af: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004859b0: { // 0x4859b0: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004859b3: { // 0x4859b3: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L004859b6: { // 0x4859b6: 740a JZ 0x004859c2
    if(integer::condition("JZ",flags)) goto L004859c2;
  }
  L004859b8: { // 0x4859b8: 8b8684000000 MOV EAX,dword ptr [ESI + 0x84]
    s.ax = m.r32((s.si+0x00000084u));
  }
  L004859be: { // 0x4859be: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004859bf: { // 0x4859bf: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004859c2: { // 0x4859c2: a840 TEST AL,0x40
    (void)integer::logical(((s.ax & 0xffu))&(0x00000040u),8,flags);
  }
  L004859c4: { // 0x4859c4: 740a JZ 0x004859d0
    if(integer::condition("JZ",flags)) goto L004859d0;
  }
  L004859c6: { // 0x4859c6: 8b8688000000 MOV EAX,dword ptr [ESI + 0x88]
    s.ax = m.r32((s.si+0x00000088u));
  }
  L004859cc: { // 0x4859cc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004859cd: { // 0x4859cd: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004859d0: { // 0x4859d0: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L004859d3: { // 0x4859d3: 7407 JZ 0x004859dc
    if(integer::condition("JZ",flags)) goto L004859dc;
  }
  L004859d5: { // 0x4859d5: 8b466c MOV EAX,dword ptr [ESI + 0x6c]
    s.ax = m.r32((s.si+0x0000006cu));
  }
  L004859d8: { // 0x4859d8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004859d9: { // 0x4859d9: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004859dc: { // 0x4859dc: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  L004859df: { // 0x4859df: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004859e0: { // 0x4859e0: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004859e3: { // 0x4859e3: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L004859e6: { // 0x4859e6: 7416 JZ 0x004859fe
    if(integer::condition("JZ",flags)) goto L004859fe;
  }
  L004859e8: { // 0x4859e8: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L004859eb: { // 0x4859eb: 740a JZ 0x004859f7
    if(integer::condition("JZ",flags)) goto L004859f7;
  }
  L004859ed: { // 0x4859ed: 8b86c4000000 MOV EAX,dword ptr [ESI + 0xc4]
    s.ax = m.r32((s.si+0x000000c4u));
  }
  L004859f3: { // 0x4859f3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004859f4: { // 0x4859f4: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004859f7: { // 0x4859f7: 8b465c MOV EAX,dword ptr [ESI + 0x5c]
    s.ax = m.r32((s.si+0x0000005cu));
  }
  L004859fa: { // 0x4859fa: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004859fb: { // 0x4859fb: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004859fe: { // 0x4859fe: 8505a8eb7b00 TEST dword ptr [0x007beba8],EAX
    (void)integer::logical((m.r32((0x007beba8u)))&(s.ax),32,flags);
  }
  L00485a04: { // 0x485a04: 7430 JZ 0x00485a36
    if(integer::condition("JZ",flags)) goto L00485a36;
  }
  L00485a06: { // 0x485a06: a808 TEST AL,0x8
    (void)integer::logical(((s.ax & 0xffu))&(0x00000008u),8,flags);
  }
  L00485a08: { // 0x485a08: 7416 JZ 0x00485a20
    if(integer::condition("JZ",flags)) goto L00485a20;
  }
  L00485a0a: { // 0x485a0a: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485a0d: { // 0x485a0d: 740a JZ 0x00485a19
    if(integer::condition("JZ",flags)) goto L00485a19;
  }
  L00485a0f: { // 0x485a0f: 8b86ac000000 MOV EAX,dword ptr [ESI + 0xac]
    s.ax = m.r32((s.si+0x000000acu));
  }
  L00485a15: { // 0x485a15: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485a16: { // 0x485a16: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485a19: { // 0x485a19: 8b4640 MOV EAX,dword ptr [ESI + 0x40]
    s.ax = m.r32((s.si+0x00000040u));
  }
  L00485a1c: { // 0x485a1c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485a1d: { // 0x485a1d: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485a20: { // 0x485a20: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485a23: { // 0x485a23: 740a JZ 0x00485a2f
    if(integer::condition("JZ",flags)) goto L00485a2f;
  }
  L00485a25: { // 0x485a25: 8b86a0000000 MOV EAX,dword ptr [ESI + 0xa0]
    s.ax = m.r32((s.si+0x000000a0u));
  }
  L00485a2b: { // 0x485a2b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485a2c: { // 0x485a2c: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485a2f: { // 0x485a2f: 8b4634 MOV EAX,dword ptr [ESI + 0x34]
    s.ax = m.r32((s.si+0x00000034u));
  }
  L00485a32: { // 0x485a32: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485a33: { // 0x485a33: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485a36: { // 0x485a36: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485a39: { // 0x485a39: 7407 JZ 0x00485a42
    if(integer::condition("JZ",flags)) goto L00485a42;
  }
  L00485a3b: { // 0x485a3b: 8b4674 MOV EAX,dword ptr [ESI + 0x74]
    s.ax = m.r32((s.si+0x00000074u));
  }
  L00485a3e: { // 0x485a3e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485a3f: { // 0x485a3f: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485a42: { // 0x485a42: 8b4618 MOV EAX,dword ptr [ESI + 0x18]
    s.ax = m.r32((s.si+0x00000018u));
  }
  L00485a45: { // 0x485a45: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485a46: { // 0x485a46: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485a49: { // 0x485a49: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L00485a4c: { // 0x485a4c: 7416 JZ 0x00485a64
    if(integer::condition("JZ",flags)) goto L00485a64;
  }
  L00485a4e: { // 0x485a4e: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485a51: { // 0x485a51: 740a JZ 0x00485a5d
    if(integer::condition("JZ",flags)) goto L00485a5d;
  }
  L00485a53: { // 0x485a53: 8b86c8000000 MOV EAX,dword ptr [ESI + 0xc8]
    s.ax = m.r32((s.si+0x000000c8u));
  }
  L00485a59: { // 0x485a59: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485a5a: { // 0x485a5a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485a5d: { // 0x485a5d: 8b4660 MOV EAX,dword ptr [ESI + 0x60]
    s.ax = m.r32((s.si+0x00000060u));
  }
  L00485a60: { // 0x485a60: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485a61: { // 0x485a61: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485a64: { // 0x485a64: 8505a8eb7b00 TEST dword ptr [0x007beba8],EAX
    (void)integer::logical((m.r32((0x007beba8u)))&(s.ax),32,flags);
  }
  L00485a6a: { // 0x485a6a: 7430 JZ 0x00485a9c
    if(integer::condition("JZ",flags)) goto L00485a9c;
  }
  L00485a6c: { // 0x485a6c: a808 TEST AL,0x8
    (void)integer::logical(((s.ax & 0xffu))&(0x00000008u),8,flags);
  }
  L00485a6e: { // 0x485a6e: 7416 JZ 0x00485a86
    if(integer::condition("JZ",flags)) goto L00485a86;
  }
  L00485a70: { // 0x485a70: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485a73: { // 0x485a73: 740a JZ 0x00485a7f
    if(integer::condition("JZ",flags)) goto L00485a7f;
  }
  L00485a75: { // 0x485a75: 8b86b0000000 MOV EAX,dword ptr [ESI + 0xb0]
    s.ax = m.r32((s.si+0x000000b0u));
  }
  L00485a7b: { // 0x485a7b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485a7c: { // 0x485a7c: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485a7f: { // 0x485a7f: 8b4644 MOV EAX,dword ptr [ESI + 0x44]
    s.ax = m.r32((s.si+0x00000044u));
  }
  L00485a82: { // 0x485a82: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485a83: { // 0x485a83: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485a86: { // 0x485a86: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485a89: { // 0x485a89: 740a JZ 0x00485a95
    if(integer::condition("JZ",flags)) goto L00485a95;
  }
  L00485a8b: { // 0x485a8b: 8b86a4000000 MOV EAX,dword ptr [ESI + 0xa4]
    s.ax = m.r32((s.si+0x000000a4u));
  }
  L00485a91: { // 0x485a91: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485a92: { // 0x485a92: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485a95: { // 0x485a95: 8b4638 MOV EAX,dword ptr [ESI + 0x38]
    s.ax = m.r32((s.si+0x00000038u));
  }
  L00485a98: { // 0x485a98: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485a99: { // 0x485a99: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485a9c: { // 0x485a9c: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485a9f: { // 0x485a9f: 7407 JZ 0x00485aa8
    if(integer::condition("JZ",flags)) goto L00485aa8;
  }
  L00485aa1: { // 0x485aa1: 8b4678 MOV EAX,dword ptr [ESI + 0x78]
    s.ax = m.r32((s.si+0x00000078u));
  }
  L00485aa4: { // 0x485aa4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485aa5: { // 0x485aa5: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485aa8: { // 0x485aa8: a900000100 TEST EAX,0x10000
    (void)integer::logical((s.ax)&(0x00010000u),32,flags);
  }
  L00485aad: { // 0x485aad: 740a JZ 0x00485ab9
    if(integer::condition("JZ",flags)) goto L00485ab9;
  }
  L00485aaf: { // 0x485aaf: 8b8690000000 MOV EAX,dword ptr [ESI + 0x90]
    s.ax = m.r32((s.si+0x00000090u));
  }
  L00485ab5: { // 0x485ab5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485ab6: { // 0x485ab6: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485ab9: { // 0x485ab9: a900000200 TEST EAX,0x20000
    (void)integer::logical((s.ax)&(0x00020000u),32,flags);
  }
  L00485abe: { // 0x485abe: 740a JZ 0x00485aca
    if(integer::condition("JZ",flags)) goto L00485aca;
  }
  L00485ac0: { // 0x485ac0: 8b868c000000 MOV EAX,dword ptr [ESI + 0x8c]
    s.ax = m.r32((s.si+0x0000008cu));
  }
  L00485ac6: { // 0x485ac6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485ac7: { // 0x485ac7: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485aca: { // 0x485aca: 8b461c MOV EAX,dword ptr [ESI + 0x1c]
    s.ax = m.r32((s.si+0x0000001cu));
  }
  L00485acd: { // 0x485acd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485ace: { // 0x485ace: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485ad1: { // 0x485ad1: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L00485ad4: { // 0x485ad4: 7416 JZ 0x00485aec
    if(integer::condition("JZ",flags)) goto L00485aec;
  }
  L00485ad6: { // 0x485ad6: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485ad9: { // 0x485ad9: 740a JZ 0x00485ae5
    if(integer::condition("JZ",flags)) goto L00485ae5;
  }
  L00485adb: { // 0x485adb: 8b86cc000000 MOV EAX,dword ptr [ESI + 0xcc]
    s.ax = m.r32((s.si+0x000000ccu));
  }
  L00485ae1: { // 0x485ae1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485ae2: { // 0x485ae2: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485ae5: { // 0x485ae5: 8b4664 MOV EAX,dword ptr [ESI + 0x64]
    s.ax = m.r32((s.si+0x00000064u));
  }
  L00485ae8: { // 0x485ae8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485ae9: { // 0x485ae9: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485aec: { // 0x485aec: 8505a8eb7b00 TEST dword ptr [0x007beba8],EAX
    (void)integer::logical((m.r32((0x007beba8u)))&(s.ax),32,flags);
  }
  L00485af2: { // 0x485af2: 7430 JZ 0x00485b24
    if(integer::condition("JZ",flags)) goto L00485b24;
  }
  L00485af4: { // 0x485af4: a808 TEST AL,0x8
    (void)integer::logical(((s.ax & 0xffu))&(0x00000008u),8,flags);
  }
  L00485af6: { // 0x485af6: 7416 JZ 0x00485b0e
    if(integer::condition("JZ",flags)) goto L00485b0e;
  }
  L00485af8: { // 0x485af8: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485afb: { // 0x485afb: 740a JZ 0x00485b07
    if(integer::condition("JZ",flags)) goto L00485b07;
  }
  L00485afd: { // 0x485afd: 8b86b4000000 MOV EAX,dword ptr [ESI + 0xb4]
    s.ax = m.r32((s.si+0x000000b4u));
  }
  L00485b03: { // 0x485b03: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485b04: { // 0x485b04: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485b07: { // 0x485b07: 8b4648 MOV EAX,dword ptr [ESI + 0x48]
    s.ax = m.r32((s.si+0x00000048u));
  }
  L00485b0a: { // 0x485b0a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485b0b: { // 0x485b0b: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485b0e: { // 0x485b0e: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485b11: { // 0x485b11: 740a JZ 0x00485b1d
    if(integer::condition("JZ",flags)) goto L00485b1d;
  }
  L00485b13: { // 0x485b13: 8b86a8000000 MOV EAX,dword ptr [ESI + 0xa8]
    s.ax = m.r32((s.si+0x000000a8u));
  }
  L00485b19: { // 0x485b19: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485b1a: { // 0x485b1a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485b1d: { // 0x485b1d: 8b463c MOV EAX,dword ptr [ESI + 0x3c]
    s.ax = m.r32((s.si+0x0000003cu));
  }
  L00485b20: { // 0x485b20: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485b21: { // 0x485b21: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485b24: { // 0x485b24: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485b27: { // 0x485b27: 7407 JZ 0x00485b30
    if(integer::condition("JZ",flags)) goto L00485b30;
  }
  L00485b29: { // 0x485b29: 8b467c MOV EAX,dword ptr [ESI + 0x7c]
    s.ax = m.r32((s.si+0x0000007cu));
  }
  L00485b2c: { // 0x485b2c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485b2d: { // 0x485b2d: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485b30: { // 0x485b30: 8b4620 MOV EAX,dword ptr [ESI + 0x20]
    s.ax = m.r32((s.si+0x00000020u));
  }
  L00485b33: { // 0x485b33: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485b34: { // 0x485b34: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_00085fa0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00485fa0: { // 0x485fa0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00485fa1: { // 0x485fa1: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L00485fa3: { // 0x485fa3: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00485fa6: { // 0x485fa6: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00485fa7: { // 0x485fa7: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00485fa8: { // 0x485fa8: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00485fa9: { // 0x485fa9: 894df8 MOV dword ptr [EBP + -0x8],ECX
    m.w32((s.bp-0x00000008u), s.cx);
  }
  L00485fac: { // 0x485fac: 8b45f8 MOV EAX,dword ptr [EBP + -0x8]
    s.ax = m.r32((s.bp-0x00000008u));
  }
  L00485faf: { // 0x485faf: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L00485fb2: { // 0x485fb2: 894dfc MOV dword ptr [EBP + -0x4],ECX
    m.w32((s.bp-0x00000004u), s.cx);
  }
  L00485fb5: { // 0x485fb5: 8b5dfc MOV EBX,dword ptr [EBP + -0x4]
    s.bx = m.r32((s.bp-0x00000004u));
  }
  L00485fb8: { // 0x485fb8: 8b4d10 MOV ECX,dword ptr [EBP + 0x10]
    s.cx = m.r32((s.bp+0x00000010u));
  }
  L00485fbb: { // 0x485fbb: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00485fbc: { // 0x485fbc: 8b7d08 MOV EDI,dword ptr [EBP + 0x8]
    s.di = m.r32((s.bp+0x00000008u));
  }
  L00485fbf: { // 0x485fbf: 83ef02 SUB EDI,0x2
    s.di = integer::sub(s.di,0x00000002u,32,flags);
  }
  L00485fc2: { // 0x485fc2: 8b750c MOV ESI,dword ptr [EBP + 0xc]
    s.si = m.r32((s.bp+0x0000000cu));
  }
  L00485fc5: { // 0x485fc5: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00485fc7: { // 0x485fc7: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00485fc8: { // 0x485fc8: 7413 JZ 0x00485fdd
    if(integer::condition("JZ",flags)) goto L00485fdd;
  }
  L00485fca: { // 0x485fca: 83c702 ADD EDI,0x2
    s.di = integer::add(s.di,0x00000002u,32,flags);
  }
  L00485fcd: { // 0x485fcd: 8a06 MOV AL,byte ptr [ESI]
    s.ax = with_al(s.ax, m.r8((s.si)));
  }
  L00485fcf: { // 0x485fcf: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L00485fd0: { // 0x485fd0: 0ac0 OR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|((s.ax & 0xffu)),8,flags));
  }
  L00485fd2: { // 0x485fd2: 74f3 JZ 0x00485fc7
    if(integer::condition("JZ",flags)) goto L00485fc7;
  }
  L00485fd4: { // 0x485fd4: 668b1443 MOV DX,word ptr [EBX + EAX*0x2]
    s.dx = with_ax(s.dx, m.r16((s.bx+(s.ax * 0x00000002u))));
  }
  L00485fd8: { // 0x485fd8: 668917 MOV word ptr [EDI],DX
    m.w16((s.di), (s.dx & 0xffffu));
  }
  L00485fdb: { // 0x485fdb: ebea JMP 0x00485fc7
    goto L00485fc7;
  }
  L00485fdd: { // 0x485fdd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00485fde: { // 0x485fde: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485fdf: { // 0x485fdf: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00485fe0: { // 0x485fe0: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L00485fe2: { // 0x485fe2: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00485fe3: { // 0x485fe3: c22000 RET 0x20
    s.arithmetic_flags=flags; finish(m,s,f,32u); return;
  }
}

void f_00032350(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00432350: { // 0x432350: 83ec30 SUB ESP,0x30
    f.sp = integer::sub(f.sp,0x00000030u,32,flags);
  }
  L00432353: { // 0x432353: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00432354: { // 0x432354: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00432355: { // 0x432355: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00432356: { // 0x432356: 8b742440 MOV ESI,dword ptr [ESP + 0x40]
    s.si = m.r32((f.sp+0x00000040u));
  }
  L0043235a: { // 0x43235a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0043235b: { // 0x43235b: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0043235d: { // 0x43235d: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  L0043235f: { // 0x43235f: 0f8422060000 JZ 0x00432987
    if(integer::condition("JZ",flags)) goto L00432987;
  }
  L00432365: { // 0x432365: 8b6c244c MOV EBP,dword ptr [ESP + 0x4c]
    s.bp = m.r32((f.sp+0x0000004cu));
  }
  L00432369: { // 0x432369: 3bef CMP EBP,EDI
    (void)integer::sub(s.bp,s.di,32,flags);
  }
  L0043236b: { // 0x43236b: 0f8416060000 JZ 0x00432987
    if(integer::condition("JZ",flags)) goto L00432987;
  }
  L00432371: { // 0x432371: 8b442448 MOV EAX,dword ptr [ESP + 0x48]
    s.ax = m.r32((f.sp+0x00000048u));
  }
  L00432375: { // 0x432375: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00432377: { // 0x432377: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00432378: { // 0x432378: e8f3fbffff CALL 0x00431f70
    s.arithmetic_flags=flags; invoke(m,s,f,0x00431f70u,4399997u,op); flags=s.arithmetic_flags;
  }
  L0043237d: { // 0x43237d: 8b4c2450 MOV ECX,dword ptr [ESP + 0x50]
    s.cx = m.r32((f.sp+0x00000050u));
  }
  L00432381: { // 0x432381: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00432382: { // 0x432382: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00432384: { // 0x432384: e807f4ffff CALL 0x00431790
    s.arithmetic_flags=flags; invoke(m,s,f,0x00431790u,4400009u,op); flags=s.arithmetic_flags;
  }
  L00432389: { // 0x432389: 8b542444 MOV EDX,dword ptr [ESP + 0x44]
    s.dx = m.r32((f.sp+0x00000044u));
  }
  L0043238d: { // 0x43238d: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0043238f: { // 0x43238f: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00432391: { // 0x432391: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00432393: { // 0x432393: 668b7224 MOV SI,word ptr [EDX + 0x24]
    s.si = (s.si & 0xffff0000u) | ((m.r16((s.dx+0x00000024u))) & 0xffffu);
  }
  L00432397: { // 0x432397: 8bd5 MOV EDX,EBP
    s.dx = s.bp;
  }
  L00432399: { // 0x432399: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0043239b: { // 0x43239b: 897c2420 MOV dword ptr [ESP + 0x20],EDI
    m.w32((f.sp+0x00000020u), s.di);
  }
  L0043239f: { // 0x43239f: 668b12 MOV DX,word ptr [EDX]
    s.dx = with_ax(s.dx, m.r16((s.dx)));
  }
  L004323a2: { // 0x4323a2: 897c242c MOV dword ptr [ESP + 0x2c],EDI
    m.w32((f.sp+0x0000002cu), s.di);
  }
  L004323a6: { // 0x4323a6: 6685d2 TEST DX,DX
    (void)integer::logical(((s.dx & 0xffffu))&((s.dx & 0xffffu)),16,flags);
  }
  L004323a9: { // 0x4323a9: 897c2424 MOV dword ptr [ESP + 0x24],EDI
    m.w32((f.sp+0x00000024u), s.di);
  }
  L004323ad: { // 0x4323ad: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L004323b1: { // 0x4323b1: 89542428 MOV dword ptr [ESP + 0x28],EDX
    m.w32((f.sp+0x00000028u), s.dx);
  }
  L004323b5: { // 0x4323b5: 0f842c040000 JZ 0x004327e7
    if(integer::condition("JZ",flags)) goto L004327e7;
  }
  L004323bb: { // 0x4323bb: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L004323bf: { // 0x4323bf: 81e1ffff0000 AND ECX,0xffff
    s.cx = integer::logical((s.cx)&(0x0000ffffu),32,flags);
  }
  L004323c5: { // 0x4323c5: 83c1f7 ADD ECX,-0x9
    s.cx = integer::add(s.cx,0xfffffff7u,32,flags);
  }
  L004323c8: { // 0x4323c8: 83f917 CMP ECX,0x17
    (void)integer::sub(s.cx,0x00000017u,32,flags);
  }
  L004323cb: { // 0x4323cb: 0f87b9010000 JA 0x0043258a
    if(integer::condition("JA",flags)) goto L0043258a;
  }
  L004323d1: { // 0x4323d1: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L004323d3: { // 0x4323d3: 8a91a4294300 MOV DL,byte ptr [ECX + 0x4329a4]
    s.dx = with_al(s.dx, m.r8((s.cx+0x004329a4u)));
  }
  L004323d9: { // 0x4323d9: ff249594294300 JMP dword ptr [EDX*0x4 + 0x432994]
    switch(m.r32(((s.dx * 0x00000004u)+0x00432994u))){
    case 0x00432350u: goto L00432350;
    case 0x00432353u: goto L00432353;
    case 0x00432354u: goto L00432354;
    case 0x00432355u: goto L00432355;
    case 0x00432356u: goto L00432356;
    case 0x0043235au: goto L0043235a;
    case 0x0043235bu: goto L0043235b;
    case 0x0043235du: goto L0043235d;
    case 0x0043235fu: goto L0043235f;
    case 0x00432365u: goto L00432365;
    case 0x00432369u: goto L00432369;
    case 0x0043236bu: goto L0043236b;
    case 0x00432371u: goto L00432371;
    case 0x00432375u: goto L00432375;
    case 0x00432377u: goto L00432377;
    case 0x00432378u: goto L00432378;
    case 0x0043237du: goto L0043237d;
    case 0x00432381u: goto L00432381;
    case 0x00432382u: goto L00432382;
    case 0x00432384u: goto L00432384;
    case 0x00432389u: goto L00432389;
    case 0x0043238du: goto L0043238d;
    case 0x0043238fu: goto L0043238f;
    case 0x00432391u: goto L00432391;
    case 0x00432393u: goto L00432393;
    case 0x00432397u: goto L00432397;
    case 0x00432399u: goto L00432399;
    case 0x0043239bu: goto L0043239b;
    case 0x0043239fu: goto L0043239f;
    case 0x004323a2u: goto L004323a2;
    case 0x004323a6u: goto L004323a6;
    case 0x004323a9u: goto L004323a9;
    case 0x004323adu: goto L004323ad;
    case 0x004323b1u: goto L004323b1;
    case 0x004323b5u: goto L004323b5;
    case 0x004323bbu: goto L004323bb;
    case 0x004323bfu: goto L004323bf;
    case 0x004323c5u: goto L004323c5;
    case 0x004323c8u: goto L004323c8;
    case 0x004323cbu: goto L004323cb;
    case 0x004323d1u: goto L004323d1;
    case 0x004323d3u: goto L004323d3;
    case 0x004323d9u: goto L004323d9;
    case 0x004323e0u: goto L004323e0;
    case 0x004323e4u: goto L004323e4;
    case 0x004323eau: goto L004323ea;
    case 0x004323eeu: goto L004323ee;
    case 0x004323f0u: goto L004323f0;
    case 0x004323f2u: goto L004323f2;
    case 0x004323f4u: goto L004323f4;
    case 0x004323f8u: goto L004323f8;
    case 0x004323fbu: goto L004323fb;
    case 0x004323fdu: goto L004323fd;
    case 0x004323ffu: goto L004323ff;
    case 0x00432401u: goto L00432401;
    case 0x00432402u: goto L00432402;
    case 0x00432404u: goto L00432404;
    case 0x00432406u: goto L00432406;
    case 0x00432408u: goto L00432408;
    case 0x0043240bu: goto L0043240b;
    case 0x0043240du: goto L0043240d;
    case 0x0043240fu: goto L0043240f;
    case 0x00432411u: goto L00432411;
    case 0x00432415u: goto L00432415;
    case 0x00432417u: goto L00432417;
    case 0x0043241bu: goto L0043241b;
    case 0x0043241fu: goto L0043241f;
    case 0x00432421u: goto L00432421;
    case 0x00432427u: goto L00432427;
    case 0x0043242bu: goto L0043242b;
    case 0x0043242fu: goto L0043242f;
    case 0x00432433u: goto L00432433;
    case 0x00432435u: goto L00432435;
    case 0x00432437u: goto L00432437;
    case 0x00432438u: goto L00432438;
    case 0x0043243au: goto L0043243a;
    case 0x0043243eu: goto L0043243e;
    case 0x00432440u: goto L00432440;
    case 0x00432444u: goto L00432444;
    case 0x00432448u: goto L00432448;
    case 0x00432449u: goto L00432449;
    case 0x0043244au: goto L0043244a;
    case 0x0043244bu: goto L0043244b;
    case 0x0043244fu: goto L0043244f;
    case 0x00432451u: goto L00432451;
    case 0x00432453u: goto L00432453;
    case 0x00432459u: goto L00432459;
    case 0x0043245du: goto L0043245d;
    case 0x00432463u: goto L00432463;
    case 0x00432467u: goto L00432467;
    case 0x0043246du: goto L0043246d;
    case 0x00432474u: goto L00432474;
    case 0x00432476u: goto L00432476;
    case 0x00432479u: goto L00432479;
    case 0x0043247fu: goto L0043247f;
    case 0x00432481u: goto L00432481;
    case 0x00432488u: goto L00432488;
    case 0x0043248bu: goto L0043248b;
    case 0x00432491u: goto L00432491;
    case 0x00432492u: goto L00432492;
    case 0x00432494u: goto L00432494;
    case 0x00432496u: goto L00432496;
    case 0x0043249du: goto L0043249d;
    case 0x004324a0u: goto L004324a0;
    case 0x004324a6u: goto L004324a6;
    case 0x004324a7u: goto L004324a7;
    case 0x004324a9u: goto L004324a9;
    case 0x004324adu: goto L004324ad;
    case 0x004324aeu: goto L004324ae;
    case 0x004324b3u: goto L004324b3;
    case 0x004324b6u: goto L004324b6;
    case 0x004324bbu: goto L004324bb;
    case 0x004324c0u: goto L004324c0;
    case 0x004324c4u: goto L004324c4;
    case 0x004324c7u: goto L004324c7;
    case 0x004324ccu: goto L004324cc;
    case 0x004324d0u: goto L004324d0;
    case 0x004324d1u: goto L004324d1;
    case 0x004324d5u: goto L004324d5;
    case 0x004324d8u: goto L004324d8;
    case 0x004324d9u: goto L004324d9;
    case 0x004324deu: goto L004324de;
    case 0x004324e2u: goto L004324e2;
    case 0x004324e6u: goto L004324e6;
    case 0x004324eau: goto L004324ea;
    case 0x004324efu: goto L004324ef;
    case 0x004324f0u: goto L004324f0;
    case 0x004324f6u: goto L004324f6;
    case 0x004324fcu: goto L004324fc;
    case 0x00432501u: goto L00432501;
    case 0x00432504u: goto L00432504;
    case 0x0043250au: goto L0043250a;
    case 0x0043250eu: goto L0043250e;
    case 0x00432512u: goto L00432512;
    case 0x00432513u: goto L00432513;
    case 0x00432517u: goto L00432517;
    case 0x00432518u: goto L00432518;
    case 0x00432519u: goto L00432519;
    case 0x0043251au: goto L0043251a;
    case 0x0043251eu: goto L0043251e;
    case 0x00432521u: goto L00432521;
    case 0x00432526u: goto L00432526;
    case 0x0043252au: goto L0043252a;
    case 0x0043252eu: goto L0043252e;
    case 0x00432530u: goto L00432530;
    case 0x00432536u: goto L00432536;
    case 0x0043253au: goto L0043253a;
    case 0x0043253eu: goto L0043253e;
    case 0x00432540u: goto L00432540;
    case 0x00432542u: goto L00432542;
    case 0x00432545u: goto L00432545;
    case 0x00432547u: goto L00432547;
    case 0x0043254bu: goto L0043254b;
    case 0x0043254fu: goto L0043254f;
    case 0x00432551u: goto L00432551;
    case 0x00432553u: goto L00432553;
    case 0x00432557u: goto L00432557;
    case 0x0043255du: goto L0043255d;
    case 0x00432561u: goto L00432561;
    case 0x00432564u: goto L00432564;
    case 0x00432569u: goto L00432569;
    case 0x0043256du: goto L0043256d;
    case 0x00432570u: goto L00432570;
    case 0x00432572u: goto L00432572;
    case 0x00432574u: goto L00432574;
    case 0x00432575u: goto L00432575;
    case 0x00432577u: goto L00432577;
    case 0x00432579u: goto L00432579;
    case 0x0043257eu: goto L0043257e;
    case 0x00432582u: goto L00432582;
    case 0x00432586u: goto L00432586;
    case 0x0043258au: goto L0043258a;
    case 0x0043258eu: goto L0043258e;
    case 0x00432592u: goto L00432592;
    case 0x00432593u: goto L00432593;
    case 0x00432598u: goto L00432598;
    case 0x0043259au: goto L0043259a;
    case 0x0043259cu: goto L0043259c;
    case 0x004325a0u: goto L004325a0;
    case 0x004325a2u: goto L004325a2;
    case 0x004325a7u: goto L004325a7;
    case 0x004325a9u: goto L004325a9;
    case 0x004325afu: goto L004325af;
    case 0x004325b3u: goto L004325b3;
    case 0x004325b5u: goto L004325b5;
    case 0x004325b7u: goto L004325b7;
    case 0x004325b8u: goto L004325b8;
    case 0x004325bbu: goto L004325bb;
    case 0x004325bdu: goto L004325bd;
    case 0x004325c1u: goto L004325c1;
    case 0x004325c3u: goto L004325c3;
    case 0x004325c5u: goto L004325c5;
    case 0x004325cbu: goto L004325cb;
    case 0x004325cdu: goto L004325cd;
    case 0x004325d3u: goto L004325d3;
    case 0x004325d7u: goto L004325d7;
    case 0x004325d9u: goto L004325d9;
    case 0x004325dbu: goto L004325db;
    case 0x004325deu: goto L004325de;
    case 0x004325e0u: goto L004325e0;
    case 0x004325e4u: goto L004325e4;
    case 0x004325e8u: goto L004325e8;
    case 0x004325eau: goto L004325ea;
    case 0x004325edu: goto L004325ed;
    case 0x004325efu: goto L004325ef;
    case 0x004325f1u: goto L004325f1;
    case 0x004325f5u: goto L004325f5;
    case 0x004325f8u: goto L004325f8;
    case 0x004325fcu: goto L004325fc;
    case 0x00432600u: goto L00432600;
    case 0x00432602u: goto L00432602;
    case 0x00432604u: goto L00432604;
    case 0x00432606u: goto L00432606;
    case 0x0043260au: goto L0043260a;
    case 0x0043260du: goto L0043260d;
    case 0x0043260fu: goto L0043260f;
    case 0x00432611u: goto L00432611;
    case 0x00432613u: goto L00432613;
    case 0x00432614u: goto L00432614;
    case 0x00432616u: goto L00432616;
    case 0x00432618u: goto L00432618;
    case 0x0043261au: goto L0043261a;
    case 0x0043261du: goto L0043261d;
    case 0x0043261fu: goto L0043261f;
    case 0x00432621u: goto L00432621;
    case 0x00432623u: goto L00432623;
    case 0x00432627u: goto L00432627;
    case 0x00432629u: goto L00432629;
    case 0x0043262du: goto L0043262d;
    case 0x00432631u: goto L00432631;
    case 0x00432633u: goto L00432633;
    case 0x00432639u: goto L00432639;
    case 0x0043263du: goto L0043263d;
    case 0x00432641u: goto L00432641;
    case 0x00432645u: goto L00432645;
    case 0x00432647u: goto L00432647;
    case 0x00432649u: goto L00432649;
    case 0x0043264bu: goto L0043264b;
    case 0x0043264cu: goto L0043264c;
    case 0x0043264eu: goto L0043264e;
    case 0x00432652u: goto L00432652;
    case 0x00432654u: goto L00432654;
    case 0x00432658u: goto L00432658;
    case 0x0043265cu: goto L0043265c;
    case 0x0043265du: goto L0043265d;
    case 0x0043265eu: goto L0043265e;
    case 0x0043265fu: goto L0043265f;
    case 0x00432663u: goto L00432663;
    case 0x00432665u: goto L00432665;
    case 0x00432667u: goto L00432667;
    case 0x0043266du: goto L0043266d;
    case 0x0043266fu: goto L0043266f;
    case 0x00432675u: goto L00432675;
    case 0x00432679u: goto L00432679;
    case 0x0043267fu: goto L0043267f;
    case 0x00432686u: goto L00432686;
    case 0x00432688u: goto L00432688;
    case 0x0043268bu: goto L0043268b;
    case 0x00432691u: goto L00432691;
    case 0x00432696u: goto L00432696;
    case 0x00432698u: goto L00432698;
    case 0x0043269fu: goto L0043269f;
    case 0x004326a2u: goto L004326a2;
    case 0x004326a8u: goto L004326a8;
    case 0x004326acu: goto L004326ac;
    case 0x004326aeu: goto L004326ae;
    case 0x004326b5u: goto L004326b5;
    case 0x004326b9u: goto L004326b9;
    case 0x004326bbu: goto L004326bb;
    case 0x004326beu: goto L004326be;
    case 0x004326c4u: goto L004326c4;
    case 0x004326c6u: goto L004326c6;
    case 0x004326cbu: goto L004326cb;
    case 0x004326d0u: goto L004326d0;
    case 0x004326d4u: goto L004326d4;
    case 0x004326d8u: goto L004326d8;
    case 0x004326ddu: goto L004326dd;
    case 0x004326deu: goto L004326de;
    case 0x004326e2u: goto L004326e2;
    case 0x004326e5u: goto L004326e5;
    case 0x004326e6u: goto L004326e6;
    case 0x004326ebu: goto L004326eb;
    case 0x004326efu: goto L004326ef;
    case 0x004326f5u: goto L004326f5;
    case 0x004326f9u: goto L004326f9;
    case 0x004326feu: goto L004326fe;
    case 0x00432700u: goto L00432700;
    case 0x00432706u: goto L00432706;
    case 0x0043270cu: goto L0043270c;
    case 0x0043270eu: goto L0043270e;
    case 0x00432714u: goto L00432714;
    case 0x00432716u: goto L00432716;
    case 0x0043271cu: goto L0043271c;
    case 0x0043271eu: goto L0043271e;
    case 0x00432724u: goto L00432724;
    case 0x00432726u: goto L00432726;
    case 0x0043272au: goto L0043272a;
    case 0x00432730u: goto L00432730;
    case 0x00432732u: goto L00432732;
    case 0x00432738u: goto L00432738;
    case 0x0043273au: goto L0043273a;
    case 0x0043273cu: goto L0043273c;
    case 0x0043273fu: goto L0043273f;
    case 0x00432745u: goto L00432745;
    case 0x00432749u: goto L00432749;
    case 0x0043274du: goto L0043274d;
    case 0x0043274eu: goto L0043274e;
    case 0x00432752u: goto L00432752;
    case 0x00432753u: goto L00432753;
    case 0x00432754u: goto L00432754;
    case 0x00432755u: goto L00432755;
    case 0x00432759u: goto L00432759;
    case 0x0043275cu: goto L0043275c;
    case 0x00432761u: goto L00432761;
    case 0x00432765u: goto L00432765;
    case 0x00432769u: goto L00432769;
    case 0x0043276bu: goto L0043276b;
    case 0x00432771u: goto L00432771;
    case 0x00432775u: goto L00432775;
    case 0x00432779u: goto L00432779;
    case 0x0043277bu: goto L0043277b;
    case 0x00432783u: goto L00432783;
    case 0x00432786u: goto L00432786;
    case 0x0043278au: goto L0043278a;
    case 0x0043278eu: goto L0043278e;
    case 0x00432790u: goto L00432790;
    case 0x00432792u: goto L00432792;
    case 0x00432795u: goto L00432795;
    case 0x00432797u: goto L00432797;
    case 0x0043279bu: goto L0043279b;
    case 0x0043279fu: goto L0043279f;
    case 0x004327a1u: goto L004327a1;
    case 0x004327a3u: goto L004327a3;
    case 0x004327a7u: goto L004327a7;
    case 0x004327a9u: goto L004327a9;
    case 0x004327adu: goto L004327ad;
    case 0x004327b1u: goto L004327b1;
    case 0x004327b5u: goto L004327b5;
    case 0x004327b8u: goto L004327b8;
    case 0x004327bcu: goto L004327bc;
    case 0x004327bfu: goto L004327bf;
    case 0x004327c2u: goto L004327c2;
    case 0x004327c6u: goto L004327c6;
    case 0x004327c8u: goto L004327c8;
    case 0x004327cdu: goto L004327cd;
    case 0x004327d1u: goto L004327d1;
    case 0x004327d2u: goto L004327d2;
    case 0x004327d7u: goto L004327d7;
    case 0x004327d8u: goto L004327d8;
    case 0x004327d9u: goto L004327d9;
    case 0x004327dau: goto L004327da;
    case 0x004327dcu: goto L004327dc;
    case 0x004327ddu: goto L004327dd;
    case 0x004327e0u: goto L004327e0;
    case 0x004327e3u: goto L004327e3;
    case 0x004327e7u: goto L004327e7;
    case 0x004327ebu: goto L004327eb;
    case 0x004327edu: goto L004327ed;
    case 0x004327efu: goto L004327ef;
    case 0x004327f1u: goto L004327f1;
    case 0x004327f5u: goto L004327f5;
    case 0x004327f8u: goto L004327f8;
    case 0x004327fau: goto L004327fa;
    case 0x004327fcu: goto L004327fc;
    case 0x004327feu: goto L004327fe;
    case 0x004327ffu: goto L004327ff;
    case 0x00432801u: goto L00432801;
    case 0x00432803u: goto L00432803;
    case 0x00432805u: goto L00432805;
    case 0x00432808u: goto L00432808;
    case 0x0043280au: goto L0043280a;
    case 0x0043280cu: goto L0043280c;
    case 0x0043280eu: goto L0043280e;
    case 0x00432812u: goto L00432812;
    case 0x00432814u: goto L00432814;
    case 0x00432818u: goto L00432818;
    case 0x0043281cu: goto L0043281c;
    case 0x0043281eu: goto L0043281e;
    case 0x00432824u: goto L00432824;
    case 0x00432828u: goto L00432828;
    case 0x0043282cu: goto L0043282c;
    case 0x0043282eu: goto L0043282e;
    case 0x00432830u: goto L00432830;
    case 0x00432832u: goto L00432832;
    case 0x00432833u: goto L00432833;
    case 0x00432835u: goto L00432835;
    case 0x00432839u: goto L00432839;
    case 0x0043283au: goto L0043283a;
    case 0x0043283bu: goto L0043283b;
    case 0x0043283cu: goto L0043283c;
    case 0x00432840u: goto L00432840;
    case 0x00432842u: goto L00432842;
    case 0x00432844u: goto L00432844;
    case 0x0043284au: goto L0043284a;
    case 0x0043284cu: goto L0043284c;
    case 0x00432852u: goto L00432852;
    case 0x00432856u: goto L00432856;
    case 0x0043285cu: goto L0043285c;
    case 0x00432863u: goto L00432863;
    case 0x00432865u: goto L00432865;
    case 0x00432868u: goto L00432868;
    case 0x0043286eu: goto L0043286e;
    case 0x00432873u: goto L00432873;
    case 0x00432875u: goto L00432875;
    case 0x0043287cu: goto L0043287c;
    case 0x0043287fu: goto L0043287f;
    case 0x00432885u: goto L00432885;
    case 0x00432889u: goto L00432889;
    case 0x0043288bu: goto L0043288b;
    case 0x00432892u: goto L00432892;
    case 0x00432896u: goto L00432896;
    case 0x00432898u: goto L00432898;
    case 0x0043289bu: goto L0043289b;
    case 0x004328a1u: goto L004328a1;
    case 0x004328a3u: goto L004328a3;
    case 0x004328a8u: goto L004328a8;
    case 0x004328adu: goto L004328ad;
    case 0x004328b1u: goto L004328b1;
    case 0x004328b5u: goto L004328b5;
    case 0x004328bau: goto L004328ba;
    case 0x004328bbu: goto L004328bb;
    case 0x004328bfu: goto L004328bf;
    case 0x004328c2u: goto L004328c2;
    case 0x004328c3u: goto L004328c3;
    case 0x004328c8u: goto L004328c8;
    case 0x004328ccu: goto L004328cc;
    case 0x004328d2u: goto L004328d2;
    case 0x004328d6u: goto L004328d6;
    case 0x004328dbu: goto L004328db;
    case 0x004328ddu: goto L004328dd;
    case 0x004328e3u: goto L004328e3;
    case 0x004328e9u: goto L004328e9;
    case 0x004328ebu: goto L004328eb;
    case 0x004328f1u: goto L004328f1;
    case 0x004328f3u: goto L004328f3;
    case 0x004328f9u: goto L004328f9;
    case 0x004328fbu: goto L004328fb;
    case 0x00432901u: goto L00432901;
    case 0x00432903u: goto L00432903;
    case 0x00432907u: goto L00432907;
    case 0x0043290du: goto L0043290d;
    case 0x0043290fu: goto L0043290f;
    case 0x00432915u: goto L00432915;
    case 0x00432917u: goto L00432917;
    case 0x00432919u: goto L00432919;
    case 0x0043291cu: goto L0043291c;
    case 0x0043291eu: goto L0043291e;
    case 0x00432922u: goto L00432922;
    case 0x00432926u: goto L00432926;
    case 0x00432927u: goto L00432927;
    case 0x0043292bu: goto L0043292b;
    case 0x0043292cu: goto L0043292c;
    case 0x0043292du: goto L0043292d;
    case 0x0043292eu: goto L0043292e;
    case 0x00432932u: goto L00432932;
    case 0x00432935u: goto L00432935;
    case 0x0043293au: goto L0043293a;
    case 0x0043293eu: goto L0043293e;
    case 0x00432942u: goto L00432942;
    case 0x00432944u: goto L00432944;
    case 0x00432946u: goto L00432946;
    case 0x0043294au: goto L0043294a;
    case 0x0043294eu: goto L0043294e;
    case 0x00432953u: goto L00432953;
    case 0x00432957u: goto L00432957;
    case 0x0043295bu: goto L0043295b;
    case 0x0043295cu: goto L0043295c;
    case 0x00432961u: goto L00432961;
    case 0x00432962u: goto L00432962;
    case 0x00432963u: goto L00432963;
    case 0x00432964u: goto L00432964;
    case 0x00432966u: goto L00432966;
    case 0x00432967u: goto L00432967;
    case 0x0043296au: goto L0043296a;
    case 0x0043296du: goto L0043296d;
    case 0x00432971u: goto L00432971;
    case 0x00432972u: goto L00432972;
    case 0x00432976u: goto L00432976;
    case 0x0043297bu: goto L0043297b;
    case 0x0043297cu: goto L0043297c;
    case 0x0043297du: goto L0043297d;
    case 0x0043297eu: goto L0043297e;
    case 0x00432980u: goto L00432980;
    case 0x00432981u: goto L00432981;
    case 0x00432984u: goto L00432984;
    case 0x00432987u: goto L00432987;
    case 0x00432988u: goto L00432988;
    case 0x00432989u: goto L00432989;
    case 0x0043298au: goto L0043298a;
    case 0x0043298cu: goto L0043298c;
    case 0x0043298du: goto L0043298d;
    case 0x00432990u: goto L00432990;
    default:throw std::domain_error("recovery107 unsupported switch destination");}
  }
  L004323e0: { // 0x4323e0: 663d0d00 CMP AX,0xd
    (void)integer::sub((s.ax & 0xffffu),0x0000000du,16,flags);
  }
  L004323e4: { // 0x4323e4: 0f8477010000 JZ 0x00432561
    if(integer::condition("JZ",flags)) goto L00432561;
  }
  L004323ea: { // 0x4323ea: 8b4c2458 MOV ECX,dword ptr [ESP + 0x58]
    s.cx = m.r32((f.sp+0x00000058u));
  }
  L004323ee: { // 0x4323ee: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004323f0: { // 0x4323f0: 3bcf CMP ECX,EDI
    (void)integer::sub(s.cx,s.di,32,flags);
  }
  L004323f2: { // 0x4323f2: 7e1d JLE 0x00432411
    if(integer::condition("JLE",flags)) goto L00432411;
  }
  L004323f4: { // 0x4323f4: 8a542460 MOV DL,byte ptr [ESP + 0x60]
    s.dx = with_al(s.dx, m.r8((f.sp+0x00000060u)));
  }
  L004323f8: { // 0x4323f8: f6c201 TEST DL,0x1
    (void)integer::logical(((s.dx & 0xffu))&(0x00000001u),8,flags);
  }
  L004323fb: { // 0x4323fb: 740b JZ 0x00432408
    if(integer::condition("JZ",flags)) goto L00432408;
  }
  L004323fd: { // 0x4323fd: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004323ff: { // 0x4323ff: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  L00432401: { // 0x432401: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00432402: { // 0x432402: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00432404: { // 0x432404: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00432406: { // 0x432406: eb09 JMP 0x00432411
    goto L00432411;
  }
  L00432408: { // 0x432408: f6c202 TEST DL,0x2
    (void)integer::logical(((s.dx & 0xffu))&(0x00000002u),8,flags);
  }
  L0043240b: { // 0x43240b: 7404 JZ 0x00432411
    if(integer::condition("JZ",flags)) goto L00432411;
  }
  L0043240d: { // 0x43240d: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0043240f: { // 0x43240f: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  L00432411: { // 0x432411: 8b4c2450 MOV ECX,dword ptr [ESP + 0x50]
    s.cx = m.r32((f.sp+0x00000050u));
  }
  L00432415: { // 0x432415: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00432417: { // 0x432417: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0043241b: { // 0x43241b: 8b44244c MOV EAX,dword ptr [ESP + 0x4c]
    s.ax = m.r32((f.sp+0x0000004cu));
  }
  L0043241f: { // 0x43241f: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L00432421: { // 0x432421: 0f830f010000 JNC 0x00432536
    if(integer::condition("JNC",flags)) goto L00432536;
  }
  L00432427: { // 0x432427: 8b4c2464 MOV ECX,dword ptr [ESP + 0x64]
    s.cx = m.r32((f.sp+0x00000064u));
  }
  L0043242b: { // 0x43242b: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0043242f: { // 0x43242f: 8b542468 MOV EDX,dword ptr [ESP + 0x68]
    s.dx = m.r32((f.sp+0x00000068u));
  }
  L00432433: { // 0x432433: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L00432435: { // 0x432435: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L00432437: { // 0x432437: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L00432438: { // 0x432438: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L0043243a: { // 0x43243a: 8d5c1001 LEA EBX,[EAX + EDX*0x1 + 0x1]
    s.bx = (s.ax+(s.dx * 0x00000001u)+0x00000001u);
  }
  L0043243e: { // 0x43243e: eb04 JMP 0x00432444
    goto L00432444;
  }
  L00432440: { // 0x432440: 8b4c2464 MOV ECX,dword ptr [ESP + 0x64]
    s.cx = m.r32((f.sp+0x00000064u));
  }
  L00432444: { // 0x432444: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00432448: { // 0x432448: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00432449: { // 0x432449: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L0043244a: { // 0x43244a: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L0043244b: { // 0x43244b: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0043244f: { // 0x43244f: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00432451: { // 0x432451: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00432453: { // 0x432453: 0f84a8000000 JZ 0x00432501
    if(integer::condition("JZ",flags)) goto L00432501;
  }
  L00432459: { // 0x432459: 394c2418 CMP dword ptr [ESP + 0x18],ECX
    (void)integer::sub(m.r32((f.sp+0x00000018u)),s.cx,32,flags);
  }
  L0043245d: { // 0x43245d: 0f8df0040000 JGE 0x00432953
    if(integer::condition("JGE",flags)) goto L00432953;
  }
  L00432463: { // 0x432463: 3b7c2468 CMP EDI,dword ptr [ESP + 0x68]
    (void)integer::sub(s.di,m.r32((f.sp+0x00000068u)),32,flags);
  }
  L00432467: { // 0x432467: 0f8d94000000 JGE 0x00432501
    if(integer::condition("JGE",flags)) goto L00432501;
  }
  L0043246d: { // 0x43246d: 668b0df0b28300 MOV CX,word ptr [0x0083b2f0]
    s.cx = with_ax(s.cx, m.r16((0x0083b2f0u)));
  }
  L00432474: { // 0x432474: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L00432476: { // 0x432476: 66d3e8 SHR AX,CL
    s.ax = with_ax(s.ax, integer::shift((s.ax & 0xffffu),(s.cx & 0xffu),16,flags,integer::Shift::right));
  }
  L00432479: { // 0x432479: 8b0df4b28300 MOV ECX,dword ptr [0x0083b2f4]
    s.cx = m.r32((0x0083b2f4u));
  }
  L0043247f: { // 0x43247f: d2e0 SHL AL,CL
    s.ax = with_al(s.ax, integer::shift((s.ax & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::left));
  }
  L00432481: { // 0x432481: 668b0df8b28300 MOV CX,word ptr [0x0083b2f8]
    s.cx = with_ax(s.cx, m.r16((0x0083b2f8u)));
  }
  L00432488: { // 0x432488: 66d3ea SHR DX,CL
    s.dx = with_ax(s.dx, integer::shift((s.dx & 0xffffu),(s.cx & 0xffu),16,flags,integer::Shift::right));
  }
  L0043248b: { // 0x43248b: 8b0dfcb28300 MOV ECX,dword ptr [0x0083b2fc]
    s.cx = m.r32((0x0083b2fcu));
  }
  L00432491: { // 0x432491: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00432492: { // 0x432492: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00432494: { // 0x432494: d2e2 SHL DL,CL
    s.dx = with_al(s.dx, integer::shift((s.dx & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::left));
  }
  L00432496: { // 0x432496: 668b0de8b28300 MOV CX,word ptr [0x0083b2e8]
    s.cx = with_ax(s.cx, m.r16((0x0083b2e8u)));
  }
  L0043249d: { // 0x43249d: 66d3e8 SHR AX,CL
    s.ax = with_ax(s.ax, integer::shift((s.ax & 0xffffu),(s.cx & 0xffu),16,flags,integer::Shift::right));
  }
  L004324a0: { // 0x4324a0: 8b0decb28300 MOV ECX,dword ptr [0x0083b2ec]
    s.cx = m.r32((0x0083b2ecu));
  }
  L004324a6: { // 0x4324a6: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004324a7: { // 0x4324a7: d2e0 SHL AL,CL
    s.ax = with_al(s.ax, integer::shift((s.ax & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::left));
  }
  L004324a9: { // 0x4324a9: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L004324ad: { // 0x4324ad: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004324ae: { // 0x4324ae: e87d070000 CALL 0x00432c30
    s.arithmetic_flags=flags; invoke(m,s,f,0x00432c30u,4400307u,op); flags=s.arithmetic_flags;
  }
  L004324b3: { // 0x4324b3: 668b08 MOV CX,word ptr [EAX]
    s.cx = with_ax(s.cx, m.r16((s.ax)));
  }
  L004324b6: { // 0x4324b6: 6869e3a900 PUSH 0xa9e369
    f.push(m,0x00a9e369u);
  }
  L004324bb: { // 0x4324bb: 66894c2434 MOV word ptr [ESP + 0x34],CX
    m.w16((f.sp+0x00000034u), (s.cx & 0xffffu));
  }
  L004324c0: { // 0x4324c0: 8d4c2434 LEA ECX,[ESP + 0x34]
    s.cx = (f.sp+0x00000034u);
  }
  L004324c4: { // 0x4324c4: 8a5002 MOV DL,byte ptr [EAX + 0x2]
    s.dx = with_al(s.dx, m.r8((s.ax+0x00000002u)));
  }
  L004324c7: { // 0x4324c7: b8ff000000 MOV EAX,0xff
    s.ax = 0x000000ffu;
  }
  L004324cc: { // 0x4324cc: 88542436 MOV byte ptr [ESP + 0x36],DL
    m.w8((f.sp+0x00000036u), (s.dx & 0xffu));
  }
  L004324d0: { // 0x4324d0: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004324d1: { // 0x4324d1: f77c246c IDIV dword ptr [ESP + 0x6c]
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(m.r32((f.sp+0x0000006cu)),32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L004324d5: { // 0x4324d5: 0fafc3 IMUL EAX,EBX
    s.ax = integer::imul(s.ax,s.bx,32,flags);
  }
  L004324d8: { // 0x4324d8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004324d9: { // 0x4324d9: e8321e2000 CALL 0x00634310
    s.arithmetic_flags=flags; invoke(m,s,f,0x00634310u,4400350u,op); flags=s.arithmetic_flags;
  }
  L004324de: { // 0x4324de: 8b442432 MOV EAX,dword ptr [ESP + 0x32]
    s.ax = m.r32((f.sp+0x00000032u));
  }
  L004324e2: { // 0x4324e2: 8b542431 MOV EDX,dword ptr [ESP + 0x31]
    s.dx = m.r32((f.sp+0x00000031u));
  }
  L004324e6: { // 0x4324e6: 8b4c2430 MOV ECX,dword ptr [ESP + 0x30]
    s.cx = m.r32((f.sp+0x00000030u));
  }
  L004324ea: { // 0x4324ea: 25ff000000 AND EAX,0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  L004324ef: { // 0x4324ef: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004324f0: { // 0x4324f0: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L004324f6: { // 0x4324f6: 81e1ff000000 AND ECX,0xff
    s.cx = integer::logical((s.cx)&(0x000000ffu),32,flags);
  }
  L004324fc: { // 0x4324fc: e84f070000 CALL 0x00432c50
    s.arithmetic_flags=flags; invoke(m,s,f,0x00432c50u,4400385u,op); flags=s.arithmetic_flags;
  }
  L00432501: { // 0x432501: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00432504: { // 0x432504: 0f8449040000 JZ 0x00432953
    if(integer::condition("JZ",flags)) goto L00432953;
  }
  L0043250a: { // 0x43250a: 8b542454 MOV EDX,dword ptr [ESP + 0x54]
    s.dx = m.r32((f.sp+0x00000054u));
  }
  L0043250e: { // 0x43250e: 668b4d00 MOV CX,word ptr [EBP]
    s.cx = with_ax(s.cx, m.r16((s.bp)));
  }
  L00432512: { // 0x432512: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00432513: { // 0x432513: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L00432517: { // 0x432517: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00432518: { // 0x432518: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00432519: { // 0x432519: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0043251a: { // 0x43251a: 8b4c2454 MOV ECX,dword ptr [ESP + 0x54]
    s.cx = m.r32((f.sp+0x00000054u));
  }
  L0043251e: { // 0x43251e: 83c502 ADD EBP,0x2
    s.bp = integer::add(s.bp,0x00000002u,32,flags);
  }
  L00432521: { // 0x432521: e87af2ffff CALL 0x004317a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004317a0u,4400422u,op); flags=s.arithmetic_flags;
  }
  L00432526: { // 0x432526: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0043252a: { // 0x43252a: 8b44244c MOV EAX,dword ptr [ESP + 0x4c]
    s.ax = m.r32((f.sp+0x0000004cu));
  }
  L0043252e: { // 0x43252e: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L00432530: { // 0x432530: 0f820affffff JC 0x00432440
    if(integer::condition("JC",flags)) goto L00432440;
  }
  L00432536: { // 0x432536: 8b4c2444 MOV ECX,dword ptr [ESP + 0x44]
    s.cx = m.r32((f.sp+0x00000044u));
  }
  L0043253a: { // 0x43253a: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L0043253e: { // 0x43253e: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00432540: { // 0x432540: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00432542: { // 0x432542: 8b411c MOV EAX,dword ptr [ECX + 0x1c]
    s.ax = m.r32((s.cx+0x0000001cu));
  }
  L00432545: { // 0x432545: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00432547: { // 0x432547: 89542420 MOV dword ptr [ESP + 0x20],EDX
    m.w32((f.sp+0x00000020u), s.dx);
  }
  L0043254b: { // 0x43254b: 8b54245c MOV EDX,dword ptr [ESP + 0x5c]
    s.dx = m.r32((f.sp+0x0000005cu));
  }
  L0043254f: { // 0x43254f: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00432551: { // 0x432551: 740a JZ 0x0043255d
    if(integer::condition("JZ",flags)) goto L0043255d;
  }
  L00432553: { // 0x432553: 39542420 CMP dword ptr [ESP + 0x20],EDX
    (void)integer::sub(m.r32((f.sp+0x00000020u)),s.dx,32,flags);
  }
  L00432557: { // 0x432557: 0f8d70020000 JGE 0x004327cd
    if(integer::condition("JGE",flags)) goto L004327cd;
  }
  L0043255d: { // 0x43255d: 01442454 ADD dword ptr [ESP + 0x54],EAX
    m.w32((f.sp+0x00000054u), integer::add(m.r32((f.sp+0x00000054u)),s.ax,32,flags));
  }
  L00432561: { // 0x432561: 83c502 ADD EBP,0x2
    s.bp = integer::add(s.bp,0x00000002u,32,flags);
  }
  L00432564: { // 0x432564: e944020000 JMP 0x004327ad
    goto L004327ad;
  }
  L00432569: { // 0x432569: 8b4c2444 MOV ECX,dword ptr [ESP + 0x44]
    s.cx = m.r32((f.sp+0x00000044u));
  }
  L0043256d: { // 0x43256d: 8b4928 MOV ECX,dword ptr [ECX + 0x28]
    s.cx = m.r32((s.cx+0x00000028u));
  }
  L00432570: { // 0x432570: 03f9 ADD EDI,ECX
    s.di = integer::add(s.di,s.cx,32,flags);
  }
  L00432572: { // 0x432572: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L00432574: { // 0x432574: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00432575: { // 0x432575: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00432577: { // 0x432577: 2bfa SUB EDI,EDX
    s.di = integer::sub(s.di,s.dx,32,flags);
  }
  L00432579: { // 0x432579: e92f020000 JMP 0x004327ad
    goto L004327ad;
  }
  L0043257e: { // 0x43257e: 8b54244c MOV EDX,dword ptr [ESP + 0x4c]
    s.dx = m.r32((f.sp+0x0000004cu));
  }
  L00432582: { // 0x432582: 897c242c MOV dword ptr [ESP + 0x2c],EDI
    m.w32((f.sp+0x0000002cu), s.di);
  }
  L00432586: { // 0x432586: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L0043258a: { // 0x43258a: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L0043258e: { // 0x43258e: 8b4c2444 MOV ECX,dword ptr [ESP + 0x44]
    s.cx = m.r32((f.sp+0x00000044u));
  }
  L00432592: { // 0x432592: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00432593: { // 0x432593: e8a8f7ffff CALL 0x00431d40
    s.arithmetic_flags=flags; invoke(m,s,f,0x00431d40u,4400536u,op); flags=s.arithmetic_flags;
  }
  L00432598: { // 0x432598: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0043259a: { // 0x43259a: 7513 JNZ 0x004325af
    if(integer::condition("JNZ",flags)) goto L004325af;
  }
  L0043259c: { // 0x43259c: 8b4c2444 MOV ECX,dword ptr [ESP + 0x44]
    s.cx = m.r32((f.sp+0x00000044u));
  }
  L004325a0: { // 0x4325a0: 6a3f PUSH 0x3f
    f.push(m,0x0000003fu);
  }
  L004325a2: { // 0x4325a2: e899f7ffff CALL 0x00431d40
    s.arithmetic_flags=flags; invoke(m,s,f,0x00431d40u,4400551u,op); flags=s.arithmetic_flags;
  }
  L004325a7: { // 0x4325a7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004325a9: { // 0x4325a9: 0f84fe010000 JZ 0x004327ad
    if(integer::condition("JZ",flags)) goto L004327ad;
  }
  L004325af: { // 0x4325af: 8b542444 MOV EDX,dword ptr [ESP + 0x44]
    s.dx = m.r32((f.sp+0x00000044u));
  }
  L004325b3: { // 0x4325b3: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L004325b5: { // 0x4325b5: 8a08 MOV CL,byte ptr [EAX]
    s.cx = with_al(s.cx, m.r8((s.ax)));
  }
  L004325b7: { // 0x4325b7: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L004325b8: { // 0x4325b8: 8b422c MOV EAX,dword ptr [EDX + 0x2c]
    s.ax = m.r32((s.dx+0x0000002cu));
  }
  L004325bb: { // 0x4325bb: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L004325bd: { // 0x4325bd: 8b4c2458 MOV ECX,dword ptr [ESP + 0x58]
    s.cx = m.r32((f.sp+0x00000058u));
  }
  L004325c1: { // 0x4325c1: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L004325c3: { // 0x4325c3: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004325c5: { // 0x4325c5: 0f84e2010000 JZ 0x004327ad
    if(integer::condition("JZ",flags)) goto L004327ad;
  }
  L004325cb: { // 0x4325cb: 3bf9 CMP EDI,ECX
    (void)integer::sub(s.di,s.cx,32,flags);
  }
  L004325cd: { // 0x4325cd: 0f8eda010000 JLE 0x004327ad
    if(integer::condition("JLE",flags)) goto L004327ad;
  }
  L004325d3: { // 0x4325d3: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L004325d7: { // 0x4325d7: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004325d9: { // 0x4325d9: 740f JZ 0x004325ea
    if(integer::condition("JZ",flags)) goto L004325ea;
  }
  L004325db: { // 0x4325db: 83fb01 CMP EBX,0x1
    (void)integer::sub(s.bx,0x00000001u,32,flags);
  }
  L004325de: { // 0x4325de: 7e1c JLE 0x004325fc
    if(integer::condition("JLE",flags)) goto L004325fc;
  }
  L004325e0: { // 0x4325e0: 8b7c242c MOV EDI,dword ptr [ESP + 0x2c]
    s.di = m.r32((f.sp+0x0000002cu));
  }
  L004325e4: { // 0x4325e4: 894c244c MOV dword ptr [ESP + 0x4c],ECX
    m.w32((f.sp+0x0000004cu), s.cx);
  }
  L004325e8: { // 0x4325e8: eb12 JMP 0x004325fc
    goto L004325fc;
  }
  L004325ea: { // 0x4325ea: 83fb01 CMP EBX,0x1
    (void)integer::sub(s.bx,0x00000001u,32,flags);
  }
  L004325ed: { // 0x4325ed: 7e0d JLE 0x004325fc
    if(integer::condition("JLE",flags)) goto L004325fc;
  }
  L004325ef: { // 0x4325ef: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L004325f1: { // 0x4325f1: 8b44244c MOV EAX,dword ptr [ESP + 0x4c]
    s.ax = m.r32((f.sp+0x0000004cu));
  }
  L004325f5: { // 0x4325f5: 83e802 SUB EAX,0x2
    s.ax = integer::sub(s.ax,0x00000002u,32,flags);
  }
  L004325f8: { // 0x4325f8: 8944244c MOV dword ptr [ESP + 0x4c],EAX
    m.w32((f.sp+0x0000004cu), s.ax);
  }
  L004325fc: { // 0x4325fc: 8b542458 MOV EDX,dword ptr [ESP + 0x58]
    s.dx = m.r32((f.sp+0x00000058u));
  }
  L00432600: { // 0x432600: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00432602: { // 0x432602: 3bd7 CMP EDX,EDI
    (void)integer::sub(s.dx,s.di,32,flags);
  }
  L00432604: { // 0x432604: 7e1d JLE 0x00432623
    if(integer::condition("JLE",flags)) goto L00432623;
  }
  L00432606: { // 0x432606: 8a5c2460 MOV BL,byte ptr [ESP + 0x60]
    s.bx = with_al(s.bx, m.r8((f.sp+0x00000060u)));
  }
  L0043260a: { // 0x43260a: f6c301 TEST BL,0x1
    (void)integer::logical(((s.bx & 0xffu))&(0x00000001u),8,flags);
  }
  L0043260d: { // 0x43260d: 740b JZ 0x0043261a
    if(integer::condition("JZ",flags)) goto L0043261a;
  }
  L0043260f: { // 0x43260f: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L00432611: { // 0x432611: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  L00432613: { // 0x432613: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00432614: { // 0x432614: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00432616: { // 0x432616: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00432618: { // 0x432618: eb09 JMP 0x00432623
    goto L00432623;
  }
  L0043261a: { // 0x43261a: f6c302 TEST BL,0x2
    (void)integer::logical(((s.bx & 0xffu))&(0x00000002u),8,flags);
  }
  L0043261d: { // 0x43261d: 7404 JZ 0x00432623
    if(integer::condition("JZ",flags)) goto L00432623;
  }
  L0043261f: { // 0x43261f: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L00432621: { // 0x432621: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  L00432623: { // 0x432623: 8b542450 MOV EDX,dword ptr [ESP + 0x50]
    s.dx = m.r32((f.sp+0x00000050u));
  }
  L00432627: { // 0x432627: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00432629: { // 0x432629: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0043262d: { // 0x43262d: 8b44244c MOV EAX,dword ptr [ESP + 0x4c]
    s.ax = m.r32((f.sp+0x0000004cu));
  }
  L00432631: { // 0x432631: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L00432633: { // 0x432633: 0f833c010000 JNC 0x00432775
    if(integer::condition("JNC",flags)) goto L00432775;
  }
  L00432639: { // 0x432639: 8b542464 MOV EDX,dword ptr [ESP + 0x64]
    s.dx = m.r32((f.sp+0x00000064u));
  }
  L0043263d: { // 0x43263d: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L00432641: { // 0x432641: 8b7c2468 MOV EDI,dword ptr [ESP + 0x68]
    s.di = m.r32((f.sp+0x00000068u));
  }
  L00432645: { // 0x432645: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  L00432647: { // 0x432647: 2bd9 SUB EBX,ECX
    s.bx = integer::sub(s.bx,s.cx,32,flags);
  }
  L00432649: { // 0x432649: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0043264b: { // 0x43264b: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L0043264c: { // 0x43264c: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0043264e: { // 0x43264e: 8d7c3801 LEA EDI,[EAX + EDI*0x1 + 0x1]
    s.di = (s.ax+(s.di * 0x00000001u)+0x00000001u);
  }
  L00432652: { // 0x432652: eb08 JMP 0x0043265c
    goto L0043265c;
  }
  L00432654: { // 0x432654: 8b542464 MOV EDX,dword ptr [ESP + 0x64]
    s.dx = m.r32((f.sp+0x00000064u));
  }
  L00432658: { // 0x432658: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0043265c: { // 0x43265c: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0043265d: { // 0x43265d: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0043265e: { // 0x43265e: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L0043265f: { // 0x43265f: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L00432663: { // 0x432663: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00432665: { // 0x432665: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00432667: { // 0x432667: 0f84cf000000 JZ 0x0043273c
    if(integer::condition("JZ",flags)) goto L0043273c;
  }
  L0043266d: { // 0x43266d: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L0043266f: { // 0x43266f: 0f8dde020000 JGE 0x00432953
    if(integer::condition("JGE",flags)) goto L00432953;
  }
  L00432675: { // 0x432675: 3b5c2468 CMP EBX,dword ptr [ESP + 0x68]
    (void)integer::sub(s.bx,m.r32((f.sp+0x00000068u)),32,flags);
  }
  L00432679: { // 0x432679: 0f8dbd000000 JGE 0x0043273c
    if(integer::condition("JGE",flags)) goto L0043273c;
  }
  L0043267f: { // 0x43267f: 668b0de8b28300 MOV CX,word ptr [0x0083b2e8]
    s.cx = with_ax(s.cx, m.r16((0x0083b2e8u)));
  }
  L00432686: { // 0x432686: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L00432688: { // 0x432688: 66d3ea SHR DX,CL
    s.dx = with_ax(s.dx, integer::shift((s.dx & 0xffffu),(s.cx & 0xffu),16,flags,integer::Shift::right));
  }
  L0043268b: { // 0x43268b: 8b0decb28300 MOV ECX,dword ptr [0x0083b2ec]
    s.cx = m.r32((0x0083b2ecu));
  }
  L00432691: { // 0x432691: 6869e3a900 PUSH 0xa9e369
    f.push(m,0x00a9e369u);
  }
  L00432696: { // 0x432696: d2e2 SHL DL,CL
    s.dx = with_al(s.dx, integer::shift((s.dx & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::left));
  }
  L00432698: { // 0x432698: 668b0df8b28300 MOV CX,word ptr [0x0083b2f8]
    s.cx = with_ax(s.cx, m.r16((0x0083b2f8u)));
  }
  L0043269f: { // 0x43269f: 66d3e8 SHR AX,CL
    s.ax = with_ax(s.ax, integer::shift((s.ax & 0xffffu),(s.cx & 0xffu),16,flags,integer::Shift::right));
  }
  L004326a2: { // 0x4326a2: 8b0dfcb28300 MOV ECX,dword ptr [0x0083b2fc]
    s.cx = m.r32((0x0083b2fcu));
  }
  L004326a8: { // 0x4326a8: 88542414 MOV byte ptr [ESP + 0x14],DL
    m.w8((f.sp+0x00000014u), (s.dx & 0xffu));
  }
  L004326ac: { // 0x4326ac: d2e0 SHL AL,CL
    s.ax = with_al(s.ax, integer::shift((s.ax & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::left));
  }
  L004326ae: { // 0x4326ae: 668b0df0b28300 MOV CX,word ptr [0x0083b2f0]
    s.cx = with_ax(s.cx, m.r16((0x0083b2f0u)));
  }
  L004326b5: { // 0x4326b5: 88442415 MOV byte ptr [ESP + 0x15],AL
    m.w8((f.sp+0x00000015u), (s.ax & 0xffu));
  }
  L004326b9: { // 0x4326b9: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004326bb: { // 0x4326bb: 66d3e8 SHR AX,CL
    s.ax = with_ax(s.ax, integer::shift((s.ax & 0xffffu),(s.cx & 0xffu),16,flags,integer::Shift::right));
  }
  L004326be: { // 0x4326be: 8b0df4b28300 MOV ECX,dword ptr [0x0083b2f4]
    s.cx = m.r32((0x0083b2f4u));
  }
  L004326c4: { // 0x4326c4: d2e0 SHL AL,CL
    s.ax = with_al(s.ax, integer::shift((s.ax & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::left));
  }
  L004326c6: { // 0x4326c6: 668b4c2414 MOV CX,word ptr [ESP + 0x14]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000014u)));
  }
  L004326cb: { // 0x4326cb: 66894c243c MOV word ptr [ESP + 0x3c],CX
    m.w16((f.sp+0x0000003cu), (s.cx & 0xffffu));
  }
  L004326d0: { // 0x4326d0: 8d4c243c LEA ECX,[ESP + 0x3c]
    s.cx = (f.sp+0x0000003cu);
  }
  L004326d4: { // 0x4326d4: 8844243e MOV byte ptr [ESP + 0x3e],AL
    m.w8((f.sp+0x0000003eu), (s.ax & 0xffu));
  }
  L004326d8: { // 0x4326d8: b8ff000000 MOV EAX,0xff
    s.ax = 0x000000ffu;
  }
  L004326dd: { // 0x4326dd: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004326de: { // 0x4326de: f77c246c IDIV dword ptr [ESP + 0x6c]
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(m.r32((f.sp+0x0000006cu)),32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L004326e2: { // 0x4326e2: 0fafc7 IMUL EAX,EDI
    s.ax = integer::imul(s.ax,s.di,32,flags);
  }
  L004326e5: { // 0x4326e5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004326e6: { // 0x4326e6: e8251c2000 CALL 0x00634310
    s.arithmetic_flags=flags; invoke(m,s,f,0x00634310u,4400875u,op); flags=s.arithmetic_flags;
  }
  L004326eb: { // 0x4326eb: 8b442439 MOV EAX,dword ptr [ESP + 0x39]
    s.ax = m.r32((f.sp+0x00000039u));
  }
  L004326ef: { // 0x4326ef: 8a0dfcb28300 MOV CL,byte ptr [0x0083b2fc]
    s.cx = with_al(s.cx, m.r8((0x0083b2fcu)));
  }
  L004326f5: { // 0x4326f5: 8b54243a MOV EDX,dword ptr [ESP + 0x3a]
    s.dx = m.r32((f.sp+0x0000003au));
  }
  L004326f9: { // 0x4326f9: 25ff000000 AND EAX,0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  L004326fe: { // 0x4326fe: d3e8 SHR EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  L00432700: { // 0x432700: 8b0df8b28300 MOV ECX,dword ptr [0x0083b2f8]
    s.cx = m.r32((0x0083b2f8u));
  }
  L00432706: { // 0x432706: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0043270c: { // 0x43270c: d3e0 SHL EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L0043270e: { // 0x43270e: 8a0df4b28300 MOV CL,byte ptr [0x0083b2f4]
    s.cx = with_al(s.cx, m.r8((0x0083b2f4u)));
  }
  L00432714: { // 0x432714: d3ea SHR EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  L00432716: { // 0x432716: 8b0df0b28300 MOV ECX,dword ptr [0x0083b2f0]
    s.cx = m.r32((0x0083b2f0u));
  }
  L0043271c: { // 0x43271c: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L0043271e: { // 0x43271e: 8a0decb28300 MOV CL,byte ptr [0x0083b2ec]
    s.cx = with_al(s.cx, m.r8((0x0083b2ecu)));
  }
  L00432724: { // 0x432724: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  L00432726: { // 0x432726: 8b542438 MOV EDX,dword ptr [ESP + 0x38]
    s.dx = m.r32((f.sp+0x00000038u));
  }
  L0043272a: { // 0x43272a: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00432730: { // 0x432730: d3ea SHR EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  L00432732: { // 0x432732: 8b0de8b28300 MOV ECX,dword ptr [0x0083b2e8]
    s.cx = m.r32((0x0083b2e8u));
  }
  L00432738: { // 0x432738: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L0043273a: { // 0x43273a: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  L0043273c: { // 0x43273c: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L0043273f: { // 0x43273f: 0f840e020000 JZ 0x00432953
    if(integer::condition("JZ",flags)) goto L00432953;
  }
  L00432745: { // 0x432745: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L00432749: { // 0x432749: 668b4d00 MOV CX,word ptr [EBP]
    s.cx = with_ax(s.cx, m.r16((s.bp)));
  }
  L0043274d: { // 0x43274d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0043274e: { // 0x43274e: 8b442458 MOV EAX,dword ptr [ESP + 0x58]
    s.ax = m.r32((f.sp+0x00000058u));
  }
  L00432752: { // 0x432752: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00432753: { // 0x432753: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00432754: { // 0x432754: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00432755: { // 0x432755: 8b4c2454 MOV ECX,dword ptr [ESP + 0x54]
    s.cx = m.r32((f.sp+0x00000054u));
  }
  L00432759: { // 0x432759: 83c502 ADD EBP,0x2
    s.bp = integer::add(s.bp,0x00000002u,32,flags);
  }
  L0043275c: { // 0x43275c: e83ff0ffff CALL 0x004317a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004317a0u,4400993u,op); flags=s.arithmetic_flags;
  }
  L00432761: { // 0x432761: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L00432765: { // 0x432765: 8b44244c MOV EAX,dword ptr [ESP + 0x4c]
    s.ax = m.r32((f.sp+0x0000004cu));
  }
  L00432769: { // 0x432769: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L0043276b: { // 0x43276b: 0f82e3feffff JC 0x00432654
    if(integer::condition("JC",flags)) goto L00432654;
  }
  L00432771: { // 0x432771: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L00432775: { // 0x432775: 394c244c CMP dword ptr [ESP + 0x4c],ECX
    (void)integer::sub(m.r32((f.sp+0x0000004cu)),s.cx,32,flags);
  }
  L00432779: { // 0x432779: 750b JNZ 0x00432786
    if(integer::condition("JNZ",flags)) goto L00432786;
  }
  L0043277b: { // 0x43277b: c744242400000000 MOV dword ptr [ESP + 0x24],0x0
    m.w32((f.sp+0x00000024u), 0x00000000u);
  }
  L00432783: { // 0x432783: 83c502 ADD EBP,0x2
    s.bp = integer::add(s.bp,0x00000002u,32,flags);
  }
  L00432786: { // 0x432786: 8b4c2444 MOV ECX,dword ptr [ESP + 0x44]
    s.cx = m.r32((f.sp+0x00000044u));
  }
  L0043278a: { // 0x43278a: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L0043278e: { // 0x43278e: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00432790: { // 0x432790: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00432792: { // 0x432792: 8b411c MOV EAX,dword ptr [ECX + 0x1c]
    s.ax = m.r32((s.cx+0x0000001cu));
  }
  L00432795: { // 0x432795: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00432797: { // 0x432797: 89542420 MOV dword ptr [ESP + 0x20],EDX
    m.w32((f.sp+0x00000020u), s.dx);
  }
  L0043279b: { // 0x43279b: 8b54245c MOV EDX,dword ptr [ESP + 0x5c]
    s.dx = m.r32((f.sp+0x0000005cu));
  }
  L0043279f: { // 0x43279f: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L004327a1: { // 0x4327a1: 7406 JZ 0x004327a9
    if(integer::condition("JZ",flags)) goto L004327a9;
  }
  L004327a3: { // 0x4327a3: 39542420 CMP dword ptr [ESP + 0x20],EDX
    (void)integer::sub(m.r32((f.sp+0x00000020u)),s.dx,32,flags);
  }
  L004327a7: { // 0x4327a7: 7d24 JGE 0x004327cd
    if(integer::condition("JGE",flags)) goto L004327cd;
  }
  L004327a9: { // 0x4327a9: 01442454 ADD dword ptr [ESP + 0x54],EAX
    m.w32((f.sp+0x00000054u), integer::add(m.r32((f.sp+0x00000054u)),s.ax,32,flags));
  }
  L004327ad: { // 0x4327ad: 8b4c244c MOV ECX,dword ptr [ESP + 0x4c]
    s.cx = m.r32((f.sp+0x0000004cu));
  }
  L004327b1: { // 0x4327b1: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L004327b5: { // 0x4327b5: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L004327b8: { // 0x4327b8: 894c244c MOV dword ptr [ESP + 0x4c],ECX
    m.w32((f.sp+0x0000004cu), s.cx);
  }
  L004327bc: { // 0x4327bc: 668b09 MOV CX,word ptr [ECX]
    s.cx = with_ax(s.cx, m.r16((s.cx)));
  }
  L004327bf: { // 0x4327bf: 6685c9 TEST CX,CX
    (void)integer::logical(((s.cx & 0xffffu))&((s.cx & 0xffffu)),16,flags);
  }
  L004327c2: { // 0x4327c2: 894c2428 MOV dword ptr [ESP + 0x28],ECX
    m.w32((f.sp+0x00000028u), s.cx);
  }
  L004327c6: { // 0x4327c6: 741b JZ 0x004327e3
    if(integer::condition("JZ",flags)) goto L004327e3;
  }
  L004327c8: { // 0x4327c8: e9eefbffff JMP 0x004323bb
    goto L004323bb;
  }
  L004327cd: { // 0x4327cd: 8b542448 MOV EDX,dword ptr [ESP + 0x48]
    s.dx = m.r32((f.sp+0x00000048u));
  }
  L004327d1: { // 0x4327d1: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004327d2: { // 0x4327d2: e839f8ffff CALL 0x00432010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00432010u,4401111u,op); flags=s.arithmetic_flags;
  }
  L004327d7: { // 0x4327d7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004327d8: { // 0x4327d8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004327d9: { // 0x4327d9: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004327da: { // 0x4327da: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L004327dc: { // 0x4327dc: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004327dd: { // 0x4327dd: 83c430 ADD ESP,0x30
    f.sp = integer::add(f.sp,0x00000030u,32,flags);
  }
  L004327e0: { // 0x4327e0: c22800 RET 0x28
    s.arithmetic_flags=flags; finish(m,s,f,40u); return;
  }
  L004327e3: { // 0x4327e3: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L004327e7: { // 0x4327e7: 8b542458 MOV EDX,dword ptr [ESP + 0x58]
    s.dx = m.r32((f.sp+0x00000058u));
  }
  L004327eb: { // 0x4327eb: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004327ed: { // 0x4327ed: 3bd7 CMP EDX,EDI
    (void)integer::sub(s.dx,s.di,32,flags);
  }
  L004327ef: { // 0x4327ef: 7e1d JLE 0x0043280e
    if(integer::condition("JLE",flags)) goto L0043280e;
  }
  L004327f1: { // 0x4327f1: 8a5c2460 MOV BL,byte ptr [ESP + 0x60]
    s.bx = with_al(s.bx, m.r8((f.sp+0x00000060u)));
  }
  L004327f5: { // 0x4327f5: f6c301 TEST BL,0x1
    (void)integer::logical(((s.bx & 0xffu))&(0x00000001u),8,flags);
  }
  L004327f8: { // 0x4327f8: 740b JZ 0x00432805
    if(integer::condition("JZ",flags)) goto L00432805;
  }
  L004327fa: { // 0x4327fa: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L004327fc: { // 0x4327fc: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  L004327fe: { // 0x4327fe: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004327ff: { // 0x4327ff: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00432801: { // 0x432801: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00432803: { // 0x432803: eb09 JMP 0x0043280e
    goto L0043280e;
  }
  L00432805: { // 0x432805: f6c302 TEST BL,0x2
    (void)integer::logical(((s.bx & 0xffu))&(0x00000002u),8,flags);
  }
  L00432808: { // 0x432808: 7404 JZ 0x0043280e
    if(integer::condition("JZ",flags)) goto L0043280e;
  }
  L0043280a: { // 0x43280a: 2bd7 SUB EDX,EDI
    s.dx = integer::sub(s.dx,s.di,32,flags);
  }
  L0043280c: { // 0x43280c: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L0043280e: { // 0x43280e: 8b542450 MOV EDX,dword ptr [ESP + 0x50]
    s.dx = m.r32((f.sp+0x00000050u));
  }
  L00432812: { // 0x432812: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00432814: { // 0x432814: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L00432818: { // 0x432818: 8b44244c MOV EAX,dword ptr [ESP + 0x4c]
    s.ax = m.r32((f.sp+0x0000004cu));
  }
  L0043281c: { // 0x43281c: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L0043281e: { // 0x43281e: 0f8349010000 JNC 0x0043296d
    if(integer::condition("JNC",flags)) goto L0043296d;
  }
  L00432824: { // 0x432824: 8b542464 MOV EDX,dword ptr [ESP + 0x64]
    s.dx = m.r32((f.sp+0x00000064u));
  }
  L00432828: { // 0x432828: 8b7c2468 MOV EDI,dword ptr [ESP + 0x68]
    s.di = m.r32((f.sp+0x00000068u));
  }
  L0043282c: { // 0x43282c: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  L0043282e: { // 0x43282e: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00432830: { // 0x432830: 2bd9 SUB EBX,ECX
    s.bx = integer::sub(s.bx,s.cx,32,flags);
  }
  L00432832: { // 0x432832: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L00432833: { // 0x432833: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00432835: { // 0x432835: 8d7c3801 LEA EDI,[EAX + EDI*0x1 + 0x1]
    s.di = (s.ax+(s.di * 0x00000001u)+0x00000001u);
  }
  L00432839: { // 0x432839: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0043283a: { // 0x43283a: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0043283b: { // 0x43283b: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L0043283c: { // 0x43283c: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L00432840: { // 0x432840: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00432842: { // 0x432842: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00432844: { // 0x432844: 0f84cf000000 JZ 0x00432919
    if(integer::condition("JZ",flags)) goto L00432919;
  }
  L0043284a: { // 0x43284a: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L0043284c: { // 0x43284c: 0f8d01010000 JGE 0x00432953
    if(integer::condition("JGE",flags)) goto L00432953;
  }
  L00432852: { // 0x432852: 3b5c2468 CMP EBX,dword ptr [ESP + 0x68]
    (void)integer::sub(s.bx,m.r32((f.sp+0x00000068u)),32,flags);
  }
  L00432856: { // 0x432856: 0f8dbd000000 JGE 0x00432919
    if(integer::condition("JGE",flags)) goto L00432919;
  }
  L0043285c: { // 0x43285c: 668b0de8b28300 MOV CX,word ptr [0x0083b2e8]
    s.cx = with_ax(s.cx, m.r16((0x0083b2e8u)));
  }
  L00432863: { // 0x432863: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L00432865: { // 0x432865: 66d3ea SHR DX,CL
    s.dx = with_ax(s.dx, integer::shift((s.dx & 0xffffu),(s.cx & 0xffu),16,flags,integer::Shift::right));
  }
  L00432868: { // 0x432868: 8b0decb28300 MOV ECX,dword ptr [0x0083b2ec]
    s.cx = m.r32((0x0083b2ecu));
  }
  L0043286e: { // 0x43286e: 6869e3a900 PUSH 0xa9e369
    f.push(m,0x00a9e369u);
  }
  L00432873: { // 0x432873: d2e2 SHL DL,CL
    s.dx = with_al(s.dx, integer::shift((s.dx & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::left));
  }
  L00432875: { // 0x432875: 668b0df8b28300 MOV CX,word ptr [0x0083b2f8]
    s.cx = with_ax(s.cx, m.r16((0x0083b2f8u)));
  }
  L0043287c: { // 0x43287c: 66d3e8 SHR AX,CL
    s.ax = with_ax(s.ax, integer::shift((s.ax & 0xffffu),(s.cx & 0xffu),16,flags,integer::Shift::right));
  }
  L0043287f: { // 0x43287f: 8b0dfcb28300 MOV ECX,dword ptr [0x0083b2fc]
    s.cx = m.r32((0x0083b2fcu));
  }
  L00432885: { // 0x432885: 8854245c MOV byte ptr [ESP + 0x5c],DL
    m.w8((f.sp+0x0000005cu), (s.dx & 0xffu));
  }
  L00432889: { // 0x432889: d2e0 SHL AL,CL
    s.ax = with_al(s.ax, integer::shift((s.ax & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::left));
  }
  L0043288b: { // 0x43288b: 668b0df0b28300 MOV CX,word ptr [0x0083b2f0]
    s.cx = with_ax(s.cx, m.r16((0x0083b2f0u)));
  }
  L00432892: { // 0x432892: 8844245d MOV byte ptr [ESP + 0x5d],AL
    m.w8((f.sp+0x0000005du), (s.ax & 0xffu));
  }
  L00432896: { // 0x432896: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00432898: { // 0x432898: 66d3e8 SHR AX,CL
    s.ax = with_ax(s.ax, integer::shift((s.ax & 0xffffu),(s.cx & 0xffu),16,flags,integer::Shift::right));
  }
  L0043289b: { // 0x43289b: 8b0df4b28300 MOV ECX,dword ptr [0x0083b2f4]
    s.cx = m.r32((0x0083b2f4u));
  }
  L004328a1: { // 0x4328a1: d2e0 SHL AL,CL
    s.ax = with_al(s.ax, integer::shift((s.ax & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::left));
  }
  L004328a3: { // 0x4328a3: 668b4c245c MOV CX,word ptr [ESP + 0x5c]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x0000005cu)));
  }
  L004328a8: { // 0x4328a8: 66894c243c MOV word ptr [ESP + 0x3c],CX
    m.w16((f.sp+0x0000003cu), (s.cx & 0xffffu));
  }
  L004328ad: { // 0x4328ad: 8d4c243c LEA ECX,[ESP + 0x3c]
    s.cx = (f.sp+0x0000003cu);
  }
  L004328b1: { // 0x4328b1: 8844243e MOV byte ptr [ESP + 0x3e],AL
    m.w8((f.sp+0x0000003eu), (s.ax & 0xffu));
  }
  L004328b5: { // 0x4328b5: b8ff000000 MOV EAX,0xff
    s.ax = 0x000000ffu;
  }
  L004328ba: { // 0x4328ba: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004328bb: { // 0x4328bb: f77c246c IDIV dword ptr [ESP + 0x6c]
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(m.r32((f.sp+0x0000006cu)),32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L004328bf: { // 0x4328bf: 0fafc7 IMUL EAX,EDI
    s.ax = integer::imul(s.ax,s.di,32,flags);
  }
  L004328c2: { // 0x4328c2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004328c3: { // 0x4328c3: e8481a2000 CALL 0x00634310
    s.arithmetic_flags=flags; invoke(m,s,f,0x00634310u,4401352u,op); flags=s.arithmetic_flags;
  }
  L004328c8: { // 0x4328c8: 8b442439 MOV EAX,dword ptr [ESP + 0x39]
    s.ax = m.r32((f.sp+0x00000039u));
  }
  L004328cc: { // 0x4328cc: 8a0dfcb28300 MOV CL,byte ptr [0x0083b2fc]
    s.cx = with_al(s.cx, m.r8((0x0083b2fcu)));
  }
  L004328d2: { // 0x4328d2: 8b54243a MOV EDX,dword ptr [ESP + 0x3a]
    s.dx = m.r32((f.sp+0x0000003au));
  }
  L004328d6: { // 0x4328d6: 25ff000000 AND EAX,0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  L004328db: { // 0x4328db: d3e8 SHR EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  L004328dd: { // 0x4328dd: 8b0df8b28300 MOV ECX,dword ptr [0x0083b2f8]
    s.cx = m.r32((0x0083b2f8u));
  }
  L004328e3: { // 0x4328e3: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L004328e9: { // 0x4328e9: d3e0 SHL EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L004328eb: { // 0x4328eb: 8a0df4b28300 MOV CL,byte ptr [0x0083b2f4]
    s.cx = with_al(s.cx, m.r8((0x0083b2f4u)));
  }
  L004328f1: { // 0x4328f1: d3ea SHR EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  L004328f3: { // 0x4328f3: 8b0df0b28300 MOV ECX,dword ptr [0x0083b2f0]
    s.cx = m.r32((0x0083b2f0u));
  }
  L004328f9: { // 0x4328f9: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L004328fb: { // 0x4328fb: 8a0decb28300 MOV CL,byte ptr [0x0083b2ec]
    s.cx = with_al(s.cx, m.r8((0x0083b2ecu)));
  }
  L00432901: { // 0x432901: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  L00432903: { // 0x432903: 8b542438 MOV EDX,dword ptr [ESP + 0x38]
    s.dx = m.r32((f.sp+0x00000038u));
  }
  L00432907: { // 0x432907: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0043290d: { // 0x43290d: d3ea SHR EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  L0043290f: { // 0x43290f: 8b0de8b28300 MOV ECX,dword ptr [0x0083b2e8]
    s.cx = m.r32((0x0083b2e8u));
  }
  L00432915: { // 0x432915: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L00432917: { // 0x432917: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  L00432919: { // 0x432919: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L0043291c: { // 0x43291c: 7435 JZ 0x00432953
    if(integer::condition("JZ",flags)) goto L00432953;
  }
  L0043291e: { // 0x43291e: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L00432922: { // 0x432922: 668b4d00 MOV CX,word ptr [EBP]
    s.cx = with_ax(s.cx, m.r16((s.bp)));
  }
  L00432926: { // 0x432926: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00432927: { // 0x432927: 8b442458 MOV EAX,dword ptr [ESP + 0x58]
    s.ax = m.r32((f.sp+0x00000058u));
  }
  L0043292b: { // 0x43292b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0043292c: { // 0x43292c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0043292d: { // 0x43292d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0043292e: { // 0x43292e: 8b4c2454 MOV ECX,dword ptr [ESP + 0x54]
    s.cx = m.r32((f.sp+0x00000054u));
  }
  L00432932: { // 0x432932: 83c502 ADD EBP,0x2
    s.bp = integer::add(s.bp,0x00000002u,32,flags);
  }
  L00432935: { // 0x432935: e866eeffff CALL 0x004317a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004317a0u,4401466u,op); flags=s.arithmetic_flags;
  }
  L0043293a: { // 0x43293a: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0043293e: { // 0x43293e: 8b44244c MOV EAX,dword ptr [ESP + 0x4c]
    s.ax = m.r32((f.sp+0x0000004cu));
  }
  L00432942: { // 0x432942: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L00432944: { // 0x432944: 7327 JNC 0x0043296d
    if(integer::condition("JNC",flags)) goto L0043296d;
  }
  L00432946: { // 0x432946: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0043294a: { // 0x43294a: 8b542464 MOV EDX,dword ptr [ESP + 0x64]
    s.dx = m.r32((f.sp+0x00000064u));
  }
  L0043294e: { // 0x43294e: e9e6feffff JMP 0x00432839
    goto L00432839;
  }
  L00432953: { // 0x432953: 8b442448 MOV EAX,dword ptr [ESP + 0x48]
    s.ax = m.r32((f.sp+0x00000048u));
  }
  L00432957: { // 0x432957: 8b4c2444 MOV ECX,dword ptr [ESP + 0x44]
    s.cx = m.r32((f.sp+0x00000044u));
  }
  L0043295b: { // 0x43295b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0043295c: { // 0x43295c: e8aff6ffff CALL 0x00432010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00432010u,4401505u,op); flags=s.arithmetic_flags;
  }
  L00432961: { // 0x432961: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00432962: { // 0x432962: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00432963: { // 0x432963: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00432964: { // 0x432964: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00432966: { // 0x432966: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00432967: { // 0x432967: 83c430 ADD ESP,0x30
    f.sp = integer::add(f.sp,0x00000030u,32,flags);
  }
  L0043296a: { // 0x43296a: c22800 RET 0x28
    s.arithmetic_flags=flags; finish(m,s,f,40u); return;
  }
  L0043296d: { // 0x43296d: 8b4c2448 MOV ECX,dword ptr [ESP + 0x48]
    s.cx = m.r32((f.sp+0x00000048u));
  }
  L00432971: { // 0x432971: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00432972: { // 0x432972: 8b4c2448 MOV ECX,dword ptr [ESP + 0x48]
    s.cx = m.r32((f.sp+0x00000048u));
  }
  L00432976: { // 0x432976: e895f6ffff CALL 0x00432010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00432010u,4401531u,op); flags=s.arithmetic_flags;
  }
  L0043297b: { // 0x43297b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0043297c: { // 0x43297c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0043297d: { // 0x43297d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0043297e: { // 0x43297e: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00432980: { // 0x432980: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00432981: { // 0x432981: 83c430 ADD ESP,0x30
    f.sp = integer::add(f.sp,0x00000030u,32,flags);
  }
  L00432984: { // 0x432984: c22800 RET 0x28
    s.arithmetic_flags=flags; finish(m,s,f,40u); return;
  }
  L00432987: { // 0x432987: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00432988: { // 0x432988: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00432989: { // 0x432989: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0043298a: { // 0x43298a: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0043298c: { // 0x43298c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0043298d: { // 0x43298d: 83c430 ADD ESP,0x30
    f.sp = integer::add(f.sp,0x00000030u,32,flags);
  }
  L00432990: { // 0x432990: c22800 RET 0x28
    s.arithmetic_flags=flags; finish(m,s,f,40u); return;
  }
}

void f_00031d40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00431d40: { // 0x431d40: 8b4904 MOV ECX,dword ptr [ECX + 0x4]
    s.cx = m.r32((s.cx+0x00000004u));
  }
  L00431d43: { // 0x431d43: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00431d45: { // 0x431d45: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00431d47: { // 0x431d47: 7425 JZ 0x00431d6e
    if(integer::condition("JZ",flags)) goto L00431d6e;
  }
  L00431d49: { // 0x431d49: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00431d4a: { // 0x431d4a: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  L00431d4e: { // 0x431d4e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00431d4f: { // 0x431d4f: 8b7918 MOV EDI,dword ptr [ECX + 0x18]
    s.di = m.r32((s.cx+0x00000018u));
  }
  L00431d52: { // 0x431d52: 81e6ffff0000 AND ESI,0xffff
    s.si = integer::logical((s.si)&(0x0000ffffu),32,flags);
  }
  L00431d58: { // 0x431d58: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00431d5a: { // 0x431d5a: 668b1477 MOV DX,word ptr [EDI + ESI*0x2]
    s.dx = with_ax(s.dx, m.r16((s.di+(s.si * 0x00000002u))));
  }
  L00431d5e: { // 0x431d5e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00431d5f: { // 0x431d5f: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00431d61: { // 0x431d61: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00431d62: { // 0x431d62: 740a JZ 0x00431d6e
    if(integer::condition("JZ",flags)) goto L00431d6e;
  }
  L00431d64: { // 0x431d64: 8b4114 MOV EAX,dword ptr [ECX + 0x14]
    s.ax = m.r32((s.cx+0x00000014u));
  }
  L00431d67: { // 0x431d67: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L00431d68: { // 0x431d68: 0fafc2 IMUL EAX,EDX
    s.ax = integer::imul(s.ax,s.dx,32,flags);
  }
  L00431d6b: { // 0x431d6b: 03411c ADD EAX,dword ptr [ECX + 0x1c]
    s.ax = integer::add(s.ax,m.r32((s.cx+0x0000001cu)),32,flags);
  }
  L00431d6e: { // 0x431d6e: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_000b11f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004b11f0: { // 0x4b11f0: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L004b11f2: { // 0x4b11f2: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_0036ef45(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0076ef45: { // 0x76ef45: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L0076ef49: { // 0x76ef49: 66833900 CMP word ptr [ECX],0x0
    (void)integer::sub(m.r16((s.cx)),0x00000000u,16,flags);
  }
  L0076ef4d: { // 0x76ef4d: 8d4102 LEA EAX,[ECX + 0x2]
    s.ax = (s.cx+0x00000002u);
  }
  L0076ef50: { // 0x76ef50: 740a JZ 0x0076ef5c
    if(integer::condition("JZ",flags)) goto L0076ef5c;
  }
  L0076ef52: { // 0x76ef52: 668b10 MOV DX,word ptr [EAX]
    s.dx = with_ax(s.dx, m.r16((s.ax)));
  }
  L0076ef55: { // 0x76ef55: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0076ef56: { // 0x76ef56: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0076ef57: { // 0x76ef57: 6685d2 TEST DX,DX
    (void)integer::logical(((s.dx & 0xffffu))&((s.dx & 0xffffu)),16,flags);
  }
  L0076ef5a: { // 0x76ef5a: 75f6 JNZ 0x0076ef52
    if(integer::condition("JNZ",flags)) goto L0076ef52;
  }
  L0076ef5c: { // 0x76ef5c: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L0076ef5e: { // 0x76ef5e: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0076ef60: { // 0x76ef60: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0076ef61: { // 0x76ef61: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_000ab200(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004ab200: { // 0x4ab200: 8b442408 MOV EAX,dword ptr [ESP+8]
    s.ax = m.r32((f.sp+8u));
  }
  L004ab204: { // 0x4ab204: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L004ab207: { // 0x4ab207: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004ab208: { // 0x4ab208: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004ab20a: { // 0x4ab20a: 8b4c2418 MOV ECX,dword ptr [ESP+0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L004ab20e: { // 0x4ab20e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004ab20f: { // 0x4ab20f: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004ab211: { // 0x4ab211: 8d442408 LEA EAX,[ESP+8]
    s.ax = (f.sp+8u);
  }
  L004ab215: { // 0x4ab215: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004ab216: { // 0x4ab216: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004ab217: { // 0x4ab217: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004ab219: { // 0x4ab219: ff5278 CALL dword ptr [EDX+0x78]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000078u)),4895260u,op); flags=s.arithmetic_flags;
  }
  L004ab21c: { // 0x4ab21c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004ab21d: { // 0x4ab21d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004ab21f: { // 0x4ab21f: e80c000000 CALL 0x4ab230
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ab230u,4895268u,op); flags=s.arithmetic_flags;
  }
  L004ab224: { // 0x4ab224: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004ab225: { // 0x4ab225: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L004ab228: { // 0x4ab228: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}

void f_00097920(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00497920: { // 0x497920: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L00497924: { // 0x497924: 81ec0c040000 SUB ESP,0x40c
    f.sp = integer::sub(f.sp,0x0000040cu,32,flags);
  }
  L0049792a: { // 0x49792a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049792c: { // 0x49792c: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0049792d: { // 0x49792d: 0f84c5000000 JZ 0x004979f8
    if(integer::condition("JZ",flags)) goto L004979f8;
  }
  L00497933: { // 0x497933: 8d8c2434040000 LEA ECX,[ESP + 0x434]
    s.cx = (f.sp+0x00000434u);
  }
  L0049793a: { // 0x49793a: 8d542410 LEA EDX,[ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  L0049793e: { // 0x49793e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049793f: { // 0x49793f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00497940: { // 0x497940: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00497941: { // 0x497941: e8527a2d00 CALL 0x0076f398
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076f398u,4815174u,op); flags=s.arithmetic_flags;
  }
  L00497946: { // 0x497946: 8b8c2434040000 MOV ECX,dword ptr [ESP + 0x434]
    s.cx = m.r32((f.sp+0x00000434u));
  }
  L0049794d: { // 0x49794d: 8bb4243c040000 MOV ESI,dword ptr [ESP + 0x43c]
    s.si = m.r32((f.sp+0x0000043cu));
  }
  L00497954: { // 0x497954: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00497957: { // 0x497957: 8d44240c LEA EAX,[ESP + 0xc]
    s.ax = (f.sp+0x0000000cu);
  }
  L0049795b: { // 0x49795b: 81c108030000 ADD ECX,0x308
    s.cx = integer::add(s.cx,0x00000308u,32,flags);
  }
  L00497961: { // 0x497961: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00497962: { // 0x497962: e8e96b0600 CALL 0x004fe550
    s.arithmetic_flags=flags; invoke(m,s,f,0x004fe550u,4815207u,op); flags=s.arithmetic_flags;
  }
  L00497967: { // 0x497967: 668b10 MOV DX,word ptr [EAX]
    s.dx = with_ax(s.dx, m.r16((s.ax)));
  }
  L0049796a: { // 0x49796a: 8a0decb28300 MOV CL,byte ptr [0x0083b2ec]
    s.cx = with_al(s.cx, m.r8((0x0083b2ecu)));
  }
  L00497970: { // 0x497970: 6689542404 MOV word ptr [ESP + 0x4],DX
    m.w16((f.sp+0x00000004u), (s.dx & 0xffffu));
  }
  L00497975: { // 0x497975: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00497977: { // 0x497977: 8a4002 MOV AL,byte ptr [EAX + 0x2]
    s.ax = with_al(s.ax, m.r8((s.ax+0x00000002u)));
  }
  L0049797a: { // 0x49797a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0049797b: { // 0x49797b: 8844240e MOV byte ptr [ESP + 0xe],AL
    m.w8((f.sp+0x0000000eu), (s.ax & 0xffu));
  }
  L0049797f: { // 0x49797f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L00497983: { // 0x497983: 8b54240e MOV EDX,dword ptr [ESP + 0xe]
    s.dx = m.r32((f.sp+0x0000000eu));
  }
  L00497987: { // 0x497987: 25ff000000 AND EAX,0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  L0049798c: { // 0x49798c: d3e8 SHR EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  L0049798e: { // 0x49798e: 8b0de8b28300 MOV ECX,dword ptr [0x0083b2e8]
    s.cx = m.r32((0x0083b2e8u));
  }
  L00497994: { // 0x497994: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0049799a: { // 0x49799a: d3e0 SHL EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L0049799c: { // 0x49799c: 8a0df4b28300 MOV CL,byte ptr [0x0083b2f4]
    s.cx = with_al(s.cx, m.r8((0x0083b2f4u)));
  }
  L004979a2: { // 0x4979a2: d3ea SHR EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  L004979a4: { // 0x4979a4: 8b0df0b28300 MOV ECX,dword ptr [0x0083b2f0]
    s.cx = m.r32((0x0083b2f0u));
  }
  L004979aa: { // 0x4979aa: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L004979ac: { // 0x4979ac: 8a0dfcb28300 MOV CL,byte ptr [0x0083b2fc]
    s.cx = with_al(s.cx, m.r8((0x0083b2fcu)));
  }
  L004979b2: { // 0x4979b2: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  L004979b4: { // 0x4979b4: 8b54240d MOV EDX,dword ptr [ESP + 0xd]
    s.dx = m.r32((f.sp+0x0000000du));
  }
  L004979b8: { // 0x4979b8: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L004979be: { // 0x4979be: d3ea SHR EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  L004979c0: { // 0x4979c0: 8b0df8b28300 MOV ECX,dword ptr [0x0083b2f8]
    s.cx = m.r32((0x0083b2f8u));
  }
  L004979c6: { // 0x4979c6: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L004979c8: { // 0x4979c8: 8b8c2434040000 MOV ECX,dword ptr [ESP + 0x434]
    s.cx = m.r32((f.sp+0x00000434u));
  }
  L004979cf: { // 0x4979cf: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004979d0: { // 0x4979d0: 8b8c2428040000 MOV ECX,dword ptr [ESP + 0x428]
    s.cx = m.r32((f.sp+0x00000428u));
  }
  L004979d7: { // 0x4979d7: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  L004979d9: { // 0x4979d9: 8b942430040000 MOV EDX,dword ptr [ESP + 0x430]
    s.dx = m.r32((f.sp+0x00000430u));
  }
  L004979e0: { // 0x4979e0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004979e1: { // 0x4979e1: 8b842430040000 MOV EAX,dword ptr [ESP + 0x430]
    s.ax = m.r32((f.sp+0x00000430u));
  }
  L004979e8: { // 0x4979e8: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004979e9: { // 0x4979e9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004979ea: { // 0x4979ea: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004979eb: { // 0x4979eb: 8d54242c LEA EDX,[ESP + 0x2c]
    s.dx = (f.sp+0x0000002cu);
  }
  L004979ef: { // 0x4979ef: 8d4c2420 LEA ECX,[ESP + 0x20]
    s.cx = (f.sp+0x00000020u);
  }
  L004979f3: { // 0x4979f3: e9a8000000 JMP 0x00497aa0
    goto L00497aa0;
  }
  L004979f8: { // 0x4979f8: 8b8c2428040000 MOV ECX,dword ptr [ESP + 0x428]
    s.cx = m.r32((f.sp+0x00000428u));
  }
  L004979ff: { // 0x4979ff: 8bb42430040000 MOV ESI,dword ptr [ESP + 0x430]
    s.si = m.r32((f.sp+0x00000430u));
  }
  L00497a06: { // 0x497a06: 8d44240c LEA EAX,[ESP + 0xc]
    s.ax = (f.sp+0x0000000cu);
  }
  L00497a0a: { // 0x497a0a: 81c108030000 ADD ECX,0x308
    s.cx = integer::add(s.cx,0x00000308u,32,flags);
  }
  L00497a10: { // 0x497a10: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00497a11: { // 0x497a11: e83a6b0600 CALL 0x004fe550
    s.arithmetic_flags=flags; invoke(m,s,f,0x004fe550u,4815382u,op); flags=s.arithmetic_flags;
  }
  L00497a16: { // 0x497a16: 668b10 MOV DX,word ptr [EAX]
    s.dx = with_ax(s.dx, m.r16((s.ax)));
  }
  L00497a19: { // 0x497a19: 8a0decb28300 MOV CL,byte ptr [0x0083b2ec]
    s.cx = with_al(s.cx, m.r8((0x0083b2ecu)));
  }
  L00497a1f: { // 0x497a1f: 6689542404 MOV word ptr [ESP + 0x4],DX
    m.w16((f.sp+0x00000004u), (s.dx & 0xffffu));
  }
  L00497a24: { // 0x497a24: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00497a26: { // 0x497a26: 8a4002 MOV AL,byte ptr [EAX + 0x2]
    s.ax = with_al(s.ax, m.r8((s.ax+0x00000002u)));
  }
  L00497a29: { // 0x497a29: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00497a2a: { // 0x497a2a: 8844240e MOV byte ptr [ESP + 0xe],AL
    m.w8((f.sp+0x0000000eu), (s.ax & 0xffu));
  }
  L00497a2e: { // 0x497a2e: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L00497a32: { // 0x497a32: 8b54240e MOV EDX,dword ptr [ESP + 0xe]
    s.dx = m.r32((f.sp+0x0000000eu));
  }
  L00497a36: { // 0x497a36: 25ff000000 AND EAX,0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  L00497a3b: { // 0x497a3b: d3e8 SHR EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  L00497a3d: { // 0x497a3d: 8b0de8b28300 MOV ECX,dword ptr [0x0083b2e8]
    s.cx = m.r32((0x0083b2e8u));
  }
  L00497a43: { // 0x497a43: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00497a49: { // 0x497a49: d3e0 SHL EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L00497a4b: { // 0x497a4b: 8a0df4b28300 MOV CL,byte ptr [0x0083b2f4]
    s.cx = with_al(s.cx, m.r8((0x0083b2f4u)));
  }
  L00497a51: { // 0x497a51: d3ea SHR EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  L00497a53: { // 0x497a53: 8b0df0b28300 MOV ECX,dword ptr [0x0083b2f0]
    s.cx = m.r32((0x0083b2f0u));
  }
  L00497a59: { // 0x497a59: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L00497a5b: { // 0x497a5b: 8a0dfcb28300 MOV CL,byte ptr [0x0083b2fc]
    s.cx = with_al(s.cx, m.r8((0x0083b2fcu)));
  }
  L00497a61: { // 0x497a61: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  L00497a63: { // 0x497a63: 8b54240d MOV EDX,dword ptr [ESP + 0xd]
    s.dx = m.r32((f.sp+0x0000000du));
  }
  L00497a67: { // 0x497a67: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00497a6d: { // 0x497a6d: d3ea SHR EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  L00497a6f: { // 0x497a6f: 8b0df8b28300 MOV ECX,dword ptr [0x0083b2f8]
    s.cx = m.r32((0x0083b2f8u));
  }
  L00497a75: { // 0x497a75: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L00497a77: { // 0x497a77: 8b8c2434040000 MOV ECX,dword ptr [ESP + 0x434]
    s.cx = m.r32((f.sp+0x00000434u));
  }
  L00497a7e: { // 0x497a7e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00497a7f: { // 0x497a7f: 8b8c2428040000 MOV ECX,dword ptr [ESP + 0x428]
    s.cx = m.r32((f.sp+0x00000428u));
  }
  L00497a86: { // 0x497a86: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  L00497a88: { // 0x497a88: 8b942430040000 MOV EDX,dword ptr [ESP + 0x430]
    s.dx = m.r32((f.sp+0x00000430u));
  }
  L00497a8f: { // 0x497a8f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00497a90: { // 0x497a90: 8b842430040000 MOV EAX,dword ptr [ESP + 0x430]
    s.ax = m.r32((f.sp+0x00000430u));
  }
  L00497a97: { // 0x497a97: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00497a98: { // 0x497a98: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00497a99: { // 0x497a99: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00497a9a: { // 0x497a9a: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00497a9c: { // 0x497a9c: 8d4c2420 LEA ECX,[ESP + 0x20]
    s.cx = (f.sp+0x00000020u);
  }
  L00497aa0: { // 0x497aa0: e86bfbffff CALL 0x00497610
    s.arithmetic_flags=flags; invoke(m,s,f,0x00497610u,4815525u,op); flags=s.arithmetic_flags;
  }
  L00497aa5: { // 0x497aa5: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00497aa7: { // 0x497aa7: 8b842414040000 MOV EAX,dword ptr [ESP + 0x414]
    s.ax = m.r32((f.sp+0x00000414u));
  }
  L00497aae: { // 0x497aae: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00497aaf: { // 0x497aaf: 8b0a MOV ECX,dword ptr [EDX]
    s.cx = m.r32((s.dx));
  }
  L00497ab1: { // 0x497ab1: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L00497ab3: { // 0x497ab3: 8b5204 MOV EDX,dword ptr [EDX + 0x4]
    s.dx = m.r32((s.dx+0x00000004u));
  }
  L00497ab6: { // 0x497ab6: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
  L00497ab9: { // 0x497ab9: 81c40c040000 ADD ESP,0x40c
    f.sp = integer::add(f.sp,0x0000040cu,32,flags);
  }
  L00497abf: { // 0x497abf: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_00097610(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00497610: { // 0x497610: 83ec28 SUB ESP,0x28
    f.sp = integer::sub(f.sp,0x00000028u,32,flags);
  }
  L00497613: { // 0x497613: 8b442434 MOV EAX,dword ptr [ESP + 0x34]
    s.ax = m.r32((f.sp+0x00000034u));
  }
  L00497617: { // 0x497617: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00497618: { // 0x497618: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00497619: { // 0x497619: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0049761a: { // 0x49761a: 8b6804 MOV EBP,dword ptr [EAX + 0x4]
    s.bp = m.r32((s.ax+0x00000004u));
  }
  L0049761d: { // 0x49761d: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0049761e: { // 0x49761e: 8b7c2440 MOV EDI,dword ptr [ESP + 0x40]
    s.di = m.r32((f.sp+0x00000040u));
  }
  L00497622: { // 0x497622: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L00497626: { // 0x497626: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00497628: { // 0x497628: 8b1d306d8300 MOV EBX,dword ptr [0x00836d30]
    s.bx = m.r32((0x00836d30u));
  }
  L0049762e: { // 0x49762e: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  L00497631: { // 0x497631: 8b37 MOV ESI,dword ptr [EDI]
    s.si = m.r32((s.di));
  }
  L00497633: { // 0x497633: 03e8 ADD EBP,EAX
    s.bp = integer::add(s.bp,s.ax,32,flags);
  }
  L00497635: { // 0x497635: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  L00497638: { // 0x497638: 03f1 ADD ESI,ECX
    s.si = integer::add(s.si,s.cx,32,flags);
  }
  L0049763a: { // 0x49763a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049763b: { // 0x49763b: 8d4c2444 LEA ECX,[ESP + 0x44]
    s.cx = (f.sp+0x00000044u);
  }
  L0049763f: { // 0x49763f: 8d442448 LEA EAX,[ESP + 0x48]
    s.ax = (f.sp+0x00000048u);
  }
  L00497643: { // 0x497643: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00497644: { // 0x497644: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00497645: { // 0x497645: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00497646: { // 0x497646: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00497648: { // 0x497648: 89542420 MOV dword ptr [ESP + 0x20],EDX
    m.w32((f.sp+0x00000020u), s.dx);
  }
  L0049764c: { // 0x49764c: e81f9df9ff CALL 0x00431370
    s.arithmetic_flags=flags; invoke(m,s,f,0x00431370u,4814417u,op); flags=s.arithmetic_flags;
  }
  L00497651: { // 0x497651: 8b442450 MOV EAX,dword ptr [ESP + 0x50]
    s.ax = m.r32((f.sp+0x00000050u));
  }
  L00497655: { // 0x497655: 8b4c2444 MOV ECX,dword ptr [ESP + 0x44]
    s.cx = m.r32((f.sp+0x00000044u));
  }
  L00497659: { // 0x497659: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0049765c: { // 0x49765c: 7411 JZ 0x0049766f
    if(integer::condition("JZ",flags)) goto L0049766f;
  }
  L0049765e: { // 0x49765e: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00497660: { // 0x497660: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00497661: { // 0x497661: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00497663: { // 0x497663: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00497665: { // 0x497665: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L00497667: { // 0x497667: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L00497669: { // 0x497669: 8b442450 MOV EAX,dword ptr [ESP + 0x50]
    s.ax = m.r32((f.sp+0x00000050u));
  }
  L0049766d: { // 0x49766d: eb07 JMP 0x00497676
    goto L00497676;
  }
  L0049766f: { // 0x49766f: f6c402 TEST AH,0x2
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000002u),8,flags);
  }
  L00497672: { // 0x497672: 7402 JZ 0x00497676
    if(integer::condition("JZ",flags)) goto L00497676;
  }
  L00497674: { // 0x497674: 2bf1 SUB ESI,ECX
    s.si = integer::sub(s.si,s.cx,32,flags);
  }
  L00497676: { // 0x497676: f6c480 TEST AH,0x80
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000080u),8,flags);
  }
  L00497679: { // 0x497679: 7446 JZ 0x004976c1
    if(integer::condition("JZ",flags)) goto L004976c1;
  }
  L0049767b: { // 0x49767b: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L0049767e: { // 0x49767e: 8d45ff LEA EAX,[EBP + -0x1]
    s.ax = (s.bp-0x00000001u);
  }
  L00497681: { // 0x497681: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L00497685: { // 0x497685: 8b4c2440 MOV ECX,dword ptr [ESP + 0x40]
    s.cx = m.r32((f.sp+0x00000040u));
  }
  L00497689: { // 0x497689: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L0049768c: { // 0x49768c: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L00497690: { // 0x497690: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L00497694: { // 0x497694: 8b4c243c MOV ECX,dword ptr [ESP + 0x3c]
    s.cx = m.r32((f.sp+0x0000003cu));
  }
  L00497698: { // 0x497698: 8d442450 LEA EAX,[ESP + 0x50]
    s.ax = (f.sp+0x00000050u);
  }
  L0049769c: { // 0x49769c: 8d56ff LEA EDX,[ESI + -0x1]
    s.dx = (s.si-0x00000001u);
  }
  L0049769f: { // 0x49769f: 6a3c PUSH 0x3c
    f.push(m,0x0000003cu);
  }
  L004976a1: { // 0x4976a1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004976a2: { // 0x4976a2: 89542420 MOV dword ptr [ESP + 0x20],EDX
    m.w32((f.sp+0x00000020u), s.dx);
  }
  L004976a6: { // 0x4976a6: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L004976a8: { // 0x4976a8: 8d442420 LEA EAX,[ESP + 0x20]
    s.ax = (f.sp+0x00000020u);
  }
  L004976ac: { // 0x4976ac: c644245800 MOV byte ptr [ESP + 0x58],0x0
    m.w8((f.sp+0x00000058u), 0x00000000u);
  }
  L004976b1: { // 0x4976b1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004976b2: { // 0x4976b2: c644245d00 MOV byte ptr [ESP + 0x5d],0x0
    m.w8((f.sp+0x0000005du), 0x00000000u);
  }
  L004976b7: { // 0x4976b7: c644245e00 MOV byte ptr [ESP + 0x5e],0x0
    m.w8((f.sp+0x0000005eu), 0x00000000u);
  }
  L004976bc: { // 0x4976bc: ff521c CALL dword ptr [EDX + 0x1c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000001cu)),4814527u,op); flags=s.arithmetic_flags;
  }
  L004976bf: { // 0x4976bf: eb35 JMP 0x004976f6
    goto L004976f6;
  }
  L004976c1: { // 0x4976c1: f6c404 TEST AH,0x4
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000004u),8,flags);
  }
  L004976c4: { // 0x4976c4: 7430 JZ 0x004976f6
    if(integer::condition("JZ",flags)) goto L004976f6;
  }
  L004976c6: { // 0x4976c6: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L004976c9: { // 0x4976c9: 8d45ff LEA EAX,[EBP + -0x1]
    s.ax = (s.bp-0x00000001u);
  }
  L004976cc: { // 0x4976cc: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L004976d0: { // 0x4976d0: 8b4c2440 MOV ECX,dword ptr [ESP + 0x40]
    s.cx = m.r32((f.sp+0x00000040u));
  }
  L004976d4: { // 0x4976d4: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L004976d7: { // 0x4976d7: 8d56ff LEA EDX,[ESI + -0x1]
    s.dx = (s.si-0x00000001u);
  }
  L004976da: { // 0x4976da: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L004976de: { // 0x4976de: 8b4c243c MOV ECX,dword ptr [ESP + 0x3c]
    s.cx = m.r32((f.sp+0x0000003cu));
  }
  L004976e2: { // 0x4976e2: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L004976e6: { // 0x4976e6: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L004976ea: { // 0x4976ea: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L004976ec: { // 0x4976ec: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L004976f0: { // 0x4976f0: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L004976f2: { // 0x4976f2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004976f3: { // 0x4976f3: ff5214 CALL dword ptr [EDX + 0x14]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000014u)),4814582u,op); flags=s.arithmetic_flags;
  }
  L004976f6: { // 0x4976f6: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L004976f8: { // 0x4976f8: 8b5708 MOV EDX,dword ptr [EDI + 0x8]
    s.dx = m.r32((s.di+0x00000008u));
  }
  L004976fb: { // 0x4976fb: 8b4f04 MOV ECX,dword ptr [EDI + 0x4]
    s.cx = m.r32((s.di+0x00000004u));
  }
  L004976fe: { // 0x4976fe: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L00497702: { // 0x497702: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00497704: { // 0x497704: 8b570c MOV EDX,dword ptr [EDI + 0xc]
    s.dx = m.r32((s.di+0x0000000cu));
  }
  L00497707: { // 0x497707: 894c242c MOV dword ptr [ESP + 0x2c],ECX
    m.w32((f.sp+0x0000002cu), s.cx);
  }
  L0049770b: { // 0x49770b: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L0049770d: { // 0x49770d: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0049770f: { // 0x49770f: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00497711: { // 0x497711: 89442434 MOV dword ptr [ESP + 0x34],EAX
    m.w32((f.sp+0x00000034u), s.ax);
  }
  L00497715: { // 0x497715: 89542438 MOV dword ptr [ESP + 0x38],EDX
    m.w32((f.sp+0x00000038u), s.dx);
  }
  L00497719: { // 0x497719: e8f29bf9ff CALL 0x00431310
    s.arithmetic_flags=flags; invoke(m,s,f,0x00431310u,4814622u,op); flags=s.arithmetic_flags;
  }
  L0049771e: { // 0x49771e: 8d442428 LEA EAX,[ESP + 0x28]
    s.ax = (f.sp+0x00000028u);
  }
  L00497722: { // 0x497722: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00497724: { // 0x497724: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00497725: { // 0x497725: e8f69bf9ff CALL 0x00431320
    s.arithmetic_flags=flags; invoke(m,s,f,0x00431320u,4814634u,op); flags=s.arithmetic_flags;
  }
  L0049772a: { // 0x49772a: 8b4c2448 MOV ECX,dword ptr [ESP + 0x48]
    s.cx = m.r32((f.sp+0x00000048u));
  }
  L0049772e: { // 0x49772e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049772f: { // 0x49772f: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00497731: { // 0x497731: e8ba9bf9ff CALL 0x004312f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004312f0u,4814646u,op); flags=s.arithmetic_flags;
  }
  L00497736: { // 0x497736: 8b0d186d8300 MOV ECX,dword ptr [0x00836d18]
    s.cx = m.r32((0x00836d18u));
  }
  L0049773c: { // 0x49773c: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00497740: { // 0x497740: 8b44243c MOV EAX,dword ptr [ESP + 0x3c]
    s.ax = m.r32((f.sp+0x0000003cu));
  }
  L00497744: { // 0x497744: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00497746: { // 0x497746: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00497748: { // 0x497748: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00497749: { // 0x497749: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0049774a: { // 0x49774a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049774b: { // 0x49774b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049774c: { // 0x49774c: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0049774d: { // 0x49774d: e8beaaf9ff CALL 0x00432210
    s.arithmetic_flags=flags; invoke(m,s,f,0x00432210u,4814674u,op); flags=s.arithmetic_flags;
  }
  L00497752: { // 0x497752: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00497756: { // 0x497756: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00497757: { // 0x497757: 8930 MOV dword ptr [EAX],ESI
    m.w32((s.ax), s.si);
  }
  L00497759: { // 0x497759: 896804 MOV dword ptr [EAX + 0x4],EBP
    m.w32((s.ax+0x00000004u), s.bp);
  }
  L0049775c: { // 0x49775c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049775d: { // 0x49775d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0049775e: { // 0x49775e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0049775f: { // 0x49775f: 83c428 ADD ESP,0x28
    f.sp = integer::add(f.sp,0x00000028u,32,flags);
  }
  L00497762: { // 0x497762: c21c00 RET 0x1c
    s.arithmetic_flags=flags; finish(m,s,f,28u); return;
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

void f_000312f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004312f0: { // 0x4312f0: 668b542404 MOV DX,word ptr [ESP + 0x4]
    s.dx = with_ax(s.dx, m.r16((f.sp+0x00000004u)));
  }
  L004312f5: { // 0x4312f5: 668b4124 MOV AX,word ptr [ECX + 0x24]
    s.ax = with_ax(s.ax, m.r16((s.cx+0x00000024u)));
  }
  L004312f9: { // 0x4312f9: 66895124 MOV word ptr [ECX + 0x24],DX
    m.w16((s.cx+0x00000024u), (s.dx & 0xffffu));
  }
  L004312fd: { // 0x4312fd: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_00031310(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00431310: { // 0x431310: 8a542404 MOV DL,byte ptr [ESP + 0x4]
    s.dx = with_al(s.dx, m.r8((f.sp+0x00000004u)));
  }
  L00431314: { // 0x431314: 8a4141 MOV AL,byte ptr [ECX + 0x41]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000041u)));
  }
  L00431317: { // 0x431317: 885141 MOV byte ptr [ECX + 0x41],DL
    m.w8((s.cx+0x00000041u), (s.dx & 0xffu));
  }
  L0043131a: { // 0x43131a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_00031320(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00431320: { // 0x431320: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L00431324: { // 0x431324: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00431326: { // 0x431326: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00431328: { // 0x431328: 741a JZ 0x00431344
    if(integer::condition("JZ",flags)) goto L00431344;
  }
  L0043132a: { // 0x43132a: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0043132c: { // 0x43132c: 895130 MOV dword ptr [ECX + 0x30],EDX
    m.w32((s.cx+0x00000030u), s.dx);
  }
  L0043132f: { // 0x43132f: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L00431332: { // 0x431332: 895134 MOV dword ptr [ECX + 0x34],EDX
    m.w32((s.cx+0x00000034u), s.dx);
  }
  L00431335: { // 0x431335: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L00431338: { // 0x431338: 895138 MOV dword ptr [ECX + 0x38],EDX
    m.w32((s.cx+0x00000038u), s.dx);
  }
  L0043133b: { // 0x43133b: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L0043133e: { // 0x43133e: 89413c MOV dword ptr [ECX + 0x3c],EAX
    m.w32((s.cx+0x0000003cu), s.ax);
  }
  L00431341: { // 0x431341: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00431344: { // 0x431344: 89513c MOV dword ptr [ECX + 0x3c],EDX
    m.w32((s.cx+0x0000003cu), s.dx);
  }
  L00431347: { // 0x431347: 895138 MOV dword ptr [ECX + 0x38],EDX
    m.w32((s.cx+0x00000038u), s.dx);
  }
  L0043134a: { // 0x43134a: 895134 MOV dword ptr [ECX + 0x34],EDX
    m.w32((s.cx+0x00000034u), s.dx);
  }
  L0043134d: { // 0x43134d: 895130 MOV dword ptr [ECX + 0x30],EDX
    m.w32((s.cx+0x00000030u), s.dx);
  }
  L00431350: { // 0x431350: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_00031370(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00431370: { // 0x431370: 83ec1c SUB ESP,0x1c
    f.sp = integer::sub(f.sp,0x0000001cu,32,flags);
  }
  L00431373: { // 0x431373: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L00431376: { // 0x431376: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00431378: { // 0x431378: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0043137a: { // 0x43137a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0043137b: { // 0x43137b: 894c2408 MOV dword ptr [ESP + 0x8],ECX
    m.w32((f.sp+0x00000008u), s.cx);
  }
  L0043137f: { // 0x43137f: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L00431383: { // 0x431383: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00431387: { // 0x431387: 0f847b010000 JZ 0x00431508
    if(integer::condition("JZ",flags)) goto L00431508;
  }
  L0043138d: { // 0x43138d: 8b5c2424 MOV EBX,dword ptr [ESP + 0x24]
    s.bx = m.r32((f.sp+0x00000024u));
  }
  L00431391: { // 0x431391: 3bda CMP EBX,EDX
    (void)integer::sub(s.bx,s.dx,32,flags);
  }
  L00431393: { // 0x431393: 0f846f010000 JZ 0x00431508
    if(integer::condition("JZ",flags)) goto L00431508;
  }
  L00431399: { // 0x431399: 8b411c MOV EAX,dword ptr [ECX + 0x1c]
    s.ax = m.r32((s.cx+0x0000001cu));
  }
  L0043139c: { // 0x43139c: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0043139d: { // 0x43139d: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0043139e: { // 0x43139e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0043139f: { // 0x43139f: 668b3b MOV DI,word ptr [EBX]
    s.di = (s.di & 0xffff0000u) | ((m.r16((s.bx))) & 0xffffu);
  }
  L004313a2: { // 0x4313a2: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L004313a4: { // 0x4313a4: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L004313a6: { // 0x4313a6: 83c302 ADD EBX,0x2
    s.bx = integer::add(s.bx,0x00000002u,32,flags);
  }
  L004313a9: { // 0x4313a9: 6685ff TEST DI,DI
    (void)integer::logical(((s.di & 0xffffu))&((s.di & 0xffffu)),16,flags);
  }
  L004313ac: { // 0x4313ac: 89542430 MOV dword ptr [ESP + 0x30],EDX
    m.w32((f.sp+0x00000030u), s.dx);
  }
  L004313b0: { // 0x4313b0: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L004313b4: { // 0x4313b4: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L004313b8: { // 0x4313b8: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L004313bc: { // 0x4313bc: 897c2428 MOV dword ptr [ESP + 0x28],EDI
    m.w32((f.sp+0x00000028u), s.di);
  }
  L004313c0: { // 0x4313c0: 0f841a010000 JZ 0x004314e0
    if(integer::condition("JZ",flags)) goto L004314e0;
  }
  L004313c6: { // 0x4313c6: 81e7ffff0000 AND EDI,0xffff
    s.di = integer::logical((s.di)&(0x0000ffffu),32,flags);
  }
  L004313cc: { // 0x4313cc: 8d47f7 LEA EAX,[EDI + -0x9]
    s.ax = (s.di-0x00000009u);
  }
  L004313cf: { // 0x4313cf: 83f817 CMP EAX,0x17
    (void)integer::sub(s.ax,0x00000017u,32,flags);
  }
  L004313d2: { // 0x4313d2: 7751 JA 0x00431425
    if(integer::condition("JA",flags)) goto L00431425;
  }
  L004313d4: { // 0x4313d4: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L004313d6: { // 0x4313d6: 8a8838154300 MOV CL,byte ptr [EAX + 0x431538]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00431538u)));
  }
  L004313dc: { // 0x4313dc: ff248d28154300 JMP dword ptr [ECX*0x4 + 0x431528]
    switch(m.r32(((s.cx * 0x00000004u)+0x00431528u))){
    case 0x00431370u: goto L00431370;
    case 0x00431373u: goto L00431373;
    case 0x00431376u: goto L00431376;
    case 0x00431378u: goto L00431378;
    case 0x0043137au: goto L0043137a;
    case 0x0043137bu: goto L0043137b;
    case 0x0043137fu: goto L0043137f;
    case 0x00431383u: goto L00431383;
    case 0x00431387u: goto L00431387;
    case 0x0043138du: goto L0043138d;
    case 0x00431391u: goto L00431391;
    case 0x00431393u: goto L00431393;
    case 0x00431399u: goto L00431399;
    case 0x0043139cu: goto L0043139c;
    case 0x0043139du: goto L0043139d;
    case 0x0043139eu: goto L0043139e;
    case 0x0043139fu: goto L0043139f;
    case 0x004313a2u: goto L004313a2;
    case 0x004313a4u: goto L004313a4;
    case 0x004313a6u: goto L004313a6;
    case 0x004313a9u: goto L004313a9;
    case 0x004313acu: goto L004313ac;
    case 0x004313b0u: goto L004313b0;
    case 0x004313b4u: goto L004313b4;
    case 0x004313b8u: goto L004313b8;
    case 0x004313bcu: goto L004313bc;
    case 0x004313c0u: goto L004313c0;
    case 0x004313c6u: goto L004313c6;
    case 0x004313ccu: goto L004313cc;
    case 0x004313cfu: goto L004313cf;
    case 0x004313d2u: goto L004313d2;
    case 0x004313d4u: goto L004313d4;
    case 0x004313d6u: goto L004313d6;
    case 0x004313dcu: goto L004313dc;
    case 0x004313e3u: goto L004313e3;
    case 0x004313e7u: goto L004313e7;
    case 0x004313edu: goto L004313ed;
    case 0x004313f1u: goto L004313f1;
    case 0x004313f5u: goto L004313f5;
    case 0x004313f7u: goto L004313f7;
    case 0x004313f9u: goto L004313f9;
    case 0x004313fbu: goto L004313fb;
    case 0x004313ffu: goto L004313ff;
    case 0x00431404u: goto L00431404;
    case 0x00431408u: goto L00431408;
    case 0x0043140bu: goto L0043140b;
    case 0x0043140du: goto L0043140d;
    case 0x0043140fu: goto L0043140f;
    case 0x00431410u: goto L00431410;
    case 0x00431412u: goto L00431412;
    case 0x00431414u: goto L00431414;
    case 0x00431419u: goto L00431419;
    case 0x0043141du: goto L0043141d;
    case 0x00431421u: goto L00431421;
    case 0x00431425u: goto L00431425;
    case 0x00431429u: goto L00431429;
    case 0x0043142bu: goto L0043142b;
    case 0x0043142du: goto L0043142d;
    case 0x0043142fu: goto L0043142f;
    case 0x00431432u: goto L00431432;
    case 0x00431434u: goto L00431434;
    case 0x00431438u: goto L00431438;
    case 0x0043143au: goto L0043143a;
    case 0x0043143cu: goto L0043143c;
    case 0x00431440u: goto L00431440;
    case 0x00431441u: goto L00431441;
    case 0x00431444u: goto L00431444;
    case 0x00431447u: goto L00431447;
    case 0x0043144au: goto L0043144a;
    case 0x0043144cu: goto L0043144c;
    case 0x0043144eu: goto L0043144e;
    case 0x00431452u: goto L00431452;
    case 0x00431455u: goto L00431455;
    case 0x00431457u: goto L00431457;
    case 0x00431459u: goto L00431459;
    case 0x0043145du: goto L0043145d;
    case 0x0043145fu: goto L0043145f;
    case 0x00431461u: goto L00431461;
    case 0x00431462u: goto L00431462;
    case 0x00431465u: goto L00431465;
    case 0x00431467u: goto L00431467;
    case 0x0043146au: goto L0043146a;
    case 0x0043146cu: goto L0043146c;
    case 0x00431470u: goto L00431470;
    case 0x00431472u: goto L00431472;
    case 0x00431474u: goto L00431474;
    case 0x00431476u: goto L00431476;
    case 0x00431478u: goto L00431478;
    case 0x0043147cu: goto L0043147c;
    case 0x0043147eu: goto L0043147e;
    case 0x00431480u: goto L00431480;
    case 0x00431483u: goto L00431483;
    case 0x00431485u: goto L00431485;
    case 0x00431489u: goto L00431489;
    case 0x0043148bu: goto L0043148b;
    case 0x0043148fu: goto L0043148f;
    case 0x00431491u: goto L00431491;
    case 0x00431494u: goto L00431494;
    case 0x00431496u: goto L00431496;
    case 0x00431498u: goto L00431498;
    case 0x0043149au: goto L0043149a;
    case 0x0043149du: goto L0043149d;
    case 0x004314a1u: goto L004314a1;
    case 0x004314a3u: goto L004314a3;
    case 0x004314a7u: goto L004314a7;
    case 0x004314abu: goto L004314ab;
    case 0x004314afu: goto L004314af;
    case 0x004314b1u: goto L004314b1;
    case 0x004314b3u: goto L004314b3;
    case 0x004314b5u: goto L004314b5;
    case 0x004314b9u: goto L004314b9;
    case 0x004314bdu: goto L004314bd;
    case 0x004314bfu: goto L004314bf;
    case 0x004314c3u: goto L004314c3;
    case 0x004314c5u: goto L004314c5;
    case 0x004314c9u: goto L004314c9;
    case 0x004314ccu: goto L004314cc;
    case 0x004314d0u: goto L004314d0;
    case 0x004314d3u: goto L004314d3;
    case 0x004314d7u: goto L004314d7;
    case 0x004314dau: goto L004314da;
    case 0x004314e0u: goto L004314e0;
    case 0x004314e4u: goto L004314e4;
    case 0x004314e5u: goto L004314e5;
    case 0x004314e6u: goto L004314e6;
    case 0x004314e7u: goto L004314e7;
    case 0x004314e9u: goto L004314e9;
    case 0x004314ebu: goto L004314eb;
    case 0x004314efu: goto L004314ef;
    case 0x004314f1u: goto L004314f1;
    case 0x004314f5u: goto L004314f5;
    case 0x004314f7u: goto L004314f7;
    case 0x004314f9u: goto L004314f9;
    case 0x004314fdu: goto L004314fd;
    case 0x004314ffu: goto L004314ff;
    case 0x00431501u: goto L00431501;
    case 0x00431502u: goto L00431502;
    case 0x00431505u: goto L00431505;
    case 0x00431508u: goto L00431508;
    case 0x0043150cu: goto L0043150c;
    case 0x0043150eu: goto L0043150e;
    case 0x00431510u: goto L00431510;
    case 0x00431512u: goto L00431512;
    case 0x00431516u: goto L00431516;
    case 0x00431518u: goto L00431518;
    case 0x0043151au: goto L0043151a;
    case 0x0043151cu: goto L0043151c;
    case 0x0043151eu: goto L0043151e;
    case 0x0043151fu: goto L0043151f;
    case 0x00431522u: goto L00431522;
    default:throw std::domain_error("recovery107 unsupported switch destination");}
  }
  L004313e3: { // 0x4313e3: 6683fa0d CMP DX,0xd
    (void)integer::sub((s.dx & 0xffffu),0x0000000du,16,flags);
  }
  L004313e7: { // 0x4313e7: 0f84dc000000 JZ 0x004314c9
    if(integer::condition("JZ",flags)) goto L004314c9;
  }
  L004313ed: { // 0x4313ed: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L004313f1: { // 0x4313f1: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L004313f5: { // 0x4313f5: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L004313f7: { // 0x4313f7: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L004313f9: { // 0x4313f9: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004313fb: { // 0x4313fb: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L004313ff: { // 0x4313ff: e9c5000000 JMP 0x004314c9
    goto L004314c9;
  }
  L00431404: { // 0x431404: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00431408: { // 0x431408: 8b7828 MOV EDI,dword ptr [EAX + 0x28]
    s.di = m.r32((s.ax+0x00000028u));
  }
  L0043140b: { // 0x43140b: 03f7 ADD ESI,EDI
    s.si = integer::add(s.si,s.di,32,flags);
  }
  L0043140d: { // 0x43140d: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0043140f: { // 0x43140f: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00431410: { // 0x431410: f7ff IDIV EDI
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.di,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00431412: { // 0x431412: 2bf2 SUB ESI,EDX
    s.si = integer::sub(s.si,s.dx,32,flags);
  }
  L00431414: { // 0x431414: e9b0000000 JMP 0x004314c9
    goto L004314c9;
  }
  L00431419: { // 0x431419: 8b4c2430 MOV ECX,dword ptr [ESP + 0x30]
    s.cx = m.r32((f.sp+0x00000030u));
  }
  L0043141d: { // 0x43141d: 895c2418 MOV dword ptr [ESP + 0x18],EBX
    m.w32((f.sp+0x00000018u), s.bx);
  }
  L00431421: { // 0x431421: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L00431425: { // 0x431425: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L00431429: { // 0x431429: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0043142b: { // 0x43142b: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0043142d: { // 0x43142d: 741b JZ 0x0043144a
    if(integer::condition("JZ",flags)) goto L0043144a;
  }
  L0043142f: { // 0x43142f: 8b4918 MOV ECX,dword ptr [ECX + 0x18]
    s.cx = m.r32((s.cx+0x00000018u));
  }
  L00431432: { // 0x431432: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00431434: { // 0x431434: 668b1479 MOV DX,word ptr [ECX + EDI*0x2]
    s.dx = with_ax(s.dx, m.r16((s.cx+(s.di * 0x00000002u))));
  }
  L00431438: { // 0x431438: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0043143a: { // 0x43143a: 740e JZ 0x0043144a
    if(integer::condition("JZ",flags)) goto L0043144a;
  }
  L0043143c: { // 0x43143c: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L00431440: { // 0x431440: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L00431441: { // 0x431441: 8b4114 MOV EAX,dword ptr [ECX + 0x14]
    s.ax = m.r32((s.cx+0x00000014u));
  }
  L00431444: { // 0x431444: 0fafc2 IMUL EAX,EDX
    s.ax = integer::imul(s.ax,s.dx,32,flags);
  }
  L00431447: { // 0x431447: 03411c ADD EAX,dword ptr [ECX + 0x1c]
    s.ax = integer::add(s.ax,m.r32((s.cx+0x0000001cu)),32,flags);
  }
  L0043144a: { // 0x43144a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0043144c: { // 0x43144c: 750b JNZ 0x00431459
    if(integer::condition("JNZ",flags)) goto L00431459;
  }
  L0043144e: { // 0x43144e: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L00431452: { // 0x431452: 8b4208 MOV EAX,dword ptr [EDX + 0x8]
    s.ax = m.r32((s.dx+0x00000008u));
  }
  L00431455: { // 0x431455: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00431457: { // 0x431457: 7470 JZ 0x004314c9
    if(integer::condition("JZ",flags)) goto L004314c9;
  }
  L00431459: { // 0x431459: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L0043145d: { // 0x43145d: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0043145f: { // 0x43145f: 8a08 MOV CL,byte ptr [EAX]
    s.cx = with_al(s.cx, m.r8((s.ax)));
  }
  L00431461: { // 0x431461: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L00431462: { // 0x431462: 8b522c MOV EDX,dword ptr [EDX + 0x2c]
    s.dx = m.r32((s.dx+0x0000002cu));
  }
  L00431465: { // 0x431465: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00431467: { // 0x431467: 8d0c02 LEA ECX,[EDX + EAX*0x1]
    s.cx = (s.dx+(s.ax * 0x00000001u));
  }
  L0043146a: { // 0x43146a: 03f1 ADD ESI,ECX
    s.si = integer::add(s.si,s.cx,32,flags);
  }
  L0043146c: { // 0x43146c: 8b4c243c MOV ECX,dword ptr [ESP + 0x3c]
    s.cx = m.r32((f.sp+0x0000003cu));
  }
  L00431470: { // 0x431470: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00431472: { // 0x431472: 744b JZ 0x004314bf
    if(integer::condition("JZ",flags)) goto L004314bf;
  }
  L00431474: { // 0x431474: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L00431476: { // 0x431476: 7e47 JLE 0x004314bf
    if(integer::condition("JLE",flags)) goto L004314bf;
  }
  L00431478: { // 0x431478: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0043147c: { // 0x43147c: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0043147e: { // 0x43147e: 7411 JZ 0x00431491
    if(integer::condition("JZ",flags)) goto L00431491;
  }
  L00431480: { // 0x431480: 83fd01 CMP EBP,0x1
    (void)integer::sub(s.bp,0x00000001u,32,flags);
  }
  L00431483: { // 0x431483: 7e22 JLE 0x004314a7
    if(integer::condition("JLE",flags)) goto L004314a7;
  }
  L00431485: { // 0x431485: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L00431489: { // 0x431489: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0043148b: { // 0x43148b: 89542430 MOV dword ptr [ESP + 0x30],EDX
    m.w32((f.sp+0x00000030u), s.dx);
  }
  L0043148f: { // 0x43148f: eb16 JMP 0x004314a7
    goto L004314a7;
  }
  L00431491: { // 0x431491: 83fd01 CMP EBP,0x1
    (void)integer::sub(s.bp,0x00000001u,32,flags);
  }
  L00431494: { // 0x431494: 7e07 JLE 0x0043149d
    if(integer::condition("JLE",flags)) goto L0043149d;
  }
  L00431496: { // 0x431496: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00431498: { // 0x431498: 2bf2 SUB ESI,EDX
    s.si = integer::sub(s.si,s.dx,32,flags);
  }
  L0043149a: { // 0x43149a: 83eb02 SUB EBX,0x2
    s.bx = integer::sub(s.bx,0x00000002u,32,flags);
  }
  L0043149d: { // 0x43149d: 3b742430 CMP ESI,dword ptr [ESP + 0x30]
    (void)integer::sub(s.si,m.r32((f.sp+0x00000030u)),32,flags);
  }
  L004314a1: { // 0x4314a1: 7e04 JLE 0x004314a7
    if(integer::condition("JLE",flags)) goto L004314a7;
  }
  L004314a3: { // 0x4314a3: 89742430 MOV dword ptr [ESP + 0x30],ESI
    m.w32((f.sp+0x00000030u), s.si);
  }
  L004314a7: { // 0x4314a7: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L004314ab: { // 0x4314ab: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L004314af: { // 0x4314af: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L004314b1: { // 0x4314b1: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L004314b3: { // 0x4314b3: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L004314b5: { // 0x4314b5: 896c2418 MOV dword ptr [ESP + 0x18],EBP
    m.w32((f.sp+0x00000018u), s.bp);
  }
  L004314b9: { // 0x4314b9: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L004314bd: { // 0x4314bd: eb0a JMP 0x004314c9
    goto L004314c9;
  }
  L004314bf: { // 0x4314bf: 3b742430 CMP ESI,dword ptr [ESP + 0x30]
    (void)integer::sub(s.si,m.r32((f.sp+0x00000030u)),32,flags);
  }
  L004314c3: { // 0x4314c3: 7e04 JLE 0x004314c9
    if(integer::condition("JLE",flags)) goto L004314c9;
  }
  L004314c5: { // 0x4314c5: 89742430 MOV dword ptr [ESP + 0x30],ESI
    m.w32((f.sp+0x00000030u), s.si);
  }
  L004314c9: { // 0x4314c9: 668b3b MOV DI,word ptr [EBX]
    s.di = (s.di & 0xffff0000u) | ((m.r16((s.bx))) & 0xffffu);
  }
  L004314cc: { // 0x4314cc: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L004314d0: { // 0x4314d0: 83c302 ADD EBX,0x2
    s.bx = integer::add(s.bx,0x00000002u,32,flags);
  }
  L004314d3: { // 0x4314d3: 897c2428 MOV dword ptr [ESP + 0x28],EDI
    m.w32((f.sp+0x00000028u), s.di);
  }
  L004314d7: { // 0x4314d7: 6685ff TEST DI,DI
    (void)integer::logical(((s.di & 0xffffu))&((s.di & 0xffffu)),16,flags);
  }
  L004314da: { // 0x4314da: 0f85e6feffff JNZ 0x004313c6
    if(integer::condition("JNZ",flags)) goto L004313c6;
  }
  L004314e0: { // 0x4314e0: 8b442434 MOV EAX,dword ptr [ESP + 0x34]
    s.ax = m.r32((f.sp+0x00000034u));
  }
  L004314e4: { // 0x4314e4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004314e5: { // 0x4314e5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004314e6: { // 0x4314e6: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004314e7: { // 0x4314e7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004314e9: { // 0x4314e9: 7406 JZ 0x004314f1
    if(integer::condition("JZ",flags)) goto L004314f1;
  }
  L004314eb: { // 0x4314eb: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L004314ef: { // 0x4314ef: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L004314f1: { // 0x4314f1: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L004314f5: { // 0x4314f5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004314f7: { // 0x4314f7: 7406 JZ 0x004314ff
    if(integer::condition("JZ",flags)) goto L004314ff;
  }
  L004314f9: { // 0x4314f9: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L004314fd: { // 0x4314fd: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L004314ff: { // 0x4314ff: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00431501: { // 0x431501: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00431502: { // 0x431502: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L00431505: { // 0x431505: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L00431508: { // 0x431508: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L0043150c: { // 0x43150c: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0043150e: { // 0x43150e: 7402 JZ 0x00431512
    if(integer::condition("JZ",flags)) goto L00431512;
  }
  L00431510: { // 0x431510: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L00431512: { // 0x431512: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L00431516: { // 0x431516: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00431518: { // 0x431518: 7402 JZ 0x0043151c
    if(integer::condition("JZ",flags)) goto L0043151c;
  }
  L0043151a: { // 0x43151a: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L0043151c: { // 0x43151c: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0043151e: { // 0x43151e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0043151f: { // 0x43151f: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L00431522: { // 0x431522: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
}

void f_00031790(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00431790: { // 0x431790: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L00431794: { // 0x431794: 894120 MOV dword ptr [ECX + 0x20],EAX
    m.w32((s.cx+0x00000020u), s.ax);
  }
  L00431797: { // 0x431797: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_000317a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004317a0: { // 0x4317a0: 83ec30 SUB ESP,0x30
    f.sp = integer::sub(f.sp,0x00000030u,32,flags);
  }
  L004317a3: { // 0x4317a3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004317a4: { // 0x4317a4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004317a5: { // 0x4317a5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004317a6: { // 0x4317a6: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004317a7: { // 0x4317a7: 8b7c2444 MOV EDI,dword ptr [ESP + 0x44]
    s.di = m.r32((f.sp+0x00000044u));
  }
  L004317ab: { // 0x4317ab: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004317ad: { // 0x4317ad: 6683ff09 CMP DI,0x9
    (void)integer::sub((s.di & 0xffffu),0x00000009u,16,flags);
  }
  L004317b1: { // 0x4317b1: 89742410 MOV dword ptr [ESP + 0x10],ESI
    m.w32((f.sp+0x00000010u), s.si);
  }
  L004317b5: { // 0x4317b5: 7521 JNZ 0x004317d8
    if(integer::condition("JNZ",flags)) goto L004317d8;
  }
  L004317b7: { // 0x4317b7: 8b4e28 MOV ECX,dword ptr [ESI + 0x28]
    s.cx = m.r32((s.si+0x00000028u));
  }
  L004317ba: { // 0x4317ba: 8b7c2448 MOV EDI,dword ptr [ESP + 0x48]
    s.di = m.r32((f.sp+0x00000048u));
  }
  L004317be: { // 0x4317be: 8b5620 MOV EDX,dword ptr [ESI + 0x20]
    s.dx = m.r32((s.si+0x00000020u));
  }
  L004317c1: { // 0x4317c1: 03f9 ADD EDI,ECX
    s.di = integer::add(s.di,s.cx,32,flags);
  }
  L004317c3: { // 0x4317c3: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L004317c5: { // 0x4317c5: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004317c7: { // 0x4317c7: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004317c8: { // 0x4317c8: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L004317ca: { // 0x4317ca: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L004317cc: { // 0x4317cc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004317cd: { // 0x4317cd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004317ce: { // 0x4317ce: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004317cf: { // 0x4317cf: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004317d0: { // 0x4317d0: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004317d2: { // 0x4317d2: 83c430 ADD ESP,0x30
    f.sp = integer::add(f.sp,0x00000030u,32,flags);
  }
  L004317d5: { // 0x4317d5: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L004317d8: { // 0x4317d8: 668b4624 MOV AX,word ptr [ESI + 0x24]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000024u)));
  }
  L004317dc: { // 0x4317dc: 6689442444 MOV word ptr [ESP + 0x44],AX
    m.w16((f.sp+0x00000044u), (s.ax & 0xffffu));
  }
  L004317e1: { // 0x4317e1: 8b442450 MOV EAX,dword ptr [ESP + 0x50]
    s.ax = m.r32((f.sp+0x00000050u));
  }
  L004317e5: { // 0x4317e5: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L004317e8: { // 0x4317e8: 7404 JZ 0x004317ee
    if(integer::condition("JZ",flags)) goto L004317ee;
  }
  L004317ea: { // 0x4317ea: 89442444 MOV dword ptr [ESP + 0x44],EAX
    m.w32((f.sp+0x00000044u), s.ax);
  }
  L004317ee: { // 0x4317ee: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  L004317f1: { // 0x4317f1: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004317f3: { // 0x4317f3: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004317f5: { // 0x4317f5: 741d JZ 0x00431814
    if(integer::condition("JZ",flags)) goto L00431814;
  }
  L004317f7: { // 0x4317f7: 8b5918 MOV EBX,dword ptr [ECX + 0x18]
    s.bx = m.r32((s.cx+0x00000018u));
  }
  L004317fa: { // 0x4317fa: 81e7ffff0000 AND EDI,0xffff
    s.di = integer::logical((s.di)&(0x0000ffffu),32,flags);
  }
  L00431800: { // 0x431800: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00431802: { // 0x431802: 668b147b MOV DX,word ptr [EBX + EDI*0x2]
    s.dx = with_ax(s.dx, m.r16((s.bx+(s.di * 0x00000002u))));
  }
  L00431806: { // 0x431806: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00431808: { // 0x431808: 740a JZ 0x00431814
    if(integer::condition("JZ",flags)) goto L00431814;
  }
  L0043180a: { // 0x43180a: 8b4114 MOV EAX,dword ptr [ECX + 0x14]
    s.ax = m.r32((s.cx+0x00000014u));
  }
  L0043180d: { // 0x43180d: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L0043180e: { // 0x43180e: 0fafc2 IMUL EAX,EDX
    s.ax = integer::imul(s.ax,s.dx,32,flags);
  }
  L00431811: { // 0x431811: 03411c ADD EAX,dword ptr [ECX + 0x1c]
    s.ax = integer::add(s.ax,m.r32((s.cx+0x0000001cu)),32,flags);
  }
  L00431814: { // 0x431814: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00431816: { // 0x431816: 7525 JNZ 0x0043183d
    if(integer::condition("JNZ",flags)) goto L0043183d;
  }
  L00431818: { // 0x431818: 8d542444 LEA EDX,[ESP + 0x44]
    s.dx = (f.sp+0x00000044u);
  }
  L0043181c: { // 0x43181c: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0043181e: { // 0x43181e: 7408 JZ 0x00431828
    if(integer::condition("JZ",flags)) goto L00431828;
  }
  L00431820: { // 0x431820: 8174244455550000 XOR dword ptr [ESP + 0x44],0x5555
    m.w32((f.sp+0x00000044u), integer::logical((m.r32((f.sp+0x00000044u)))^(0x00005555u),32,flags));
  }
  L00431828: { // 0x431828: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L0043182b: { // 0x43182b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0043182d: { // 0x43182d: 750e JNZ 0x0043183d
    if(integer::condition("JNZ",flags)) goto L0043183d;
  }
  L0043182f: { // 0x43182f: 8b442448 MOV EAX,dword ptr [ESP + 0x48]
    s.ax = m.r32((f.sp+0x00000048u));
  }
  L00431833: { // 0x431833: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00431834: { // 0x431834: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00431835: { // 0x431835: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00431836: { // 0x431836: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00431837: { // 0x431837: 83c430 ADD ESP,0x30
    f.sp = integer::add(f.sp,0x00000030u,32,flags);
  }
  L0043183a: { // 0x43183a: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L0043183d: { // 0x43183d: 8b560c MOV EDX,dword ptr [ESI + 0xc]
    s.dx = m.r32((s.si+0x0000000cu));
  }
  L00431840: { // 0x431840: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00431842: { // 0x431842: 750e JNZ 0x00431852
    if(integer::condition("JNZ",flags)) goto L00431852;
  }
  L00431844: { // 0x431844: 8b442448 MOV EAX,dword ptr [ESP + 0x48]
    s.ax = m.r32((f.sp+0x00000048u));
  }
  L00431848: { // 0x431848: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00431849: { // 0x431849: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0043184a: { // 0x43184a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0043184b: { // 0x43184b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0043184c: { // 0x43184c: 83c430 ADD ESP,0x30
    f.sp = integer::add(f.sp,0x00000030u,32,flags);
  }
  L0043184f: { // 0x43184f: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L00431852: { // 0x431852: 8d5001 LEA EDX,[EAX + 0x1]
    s.dx = (s.ax+0x00000001u);
  }
  L00431855: { // 0x431855: 8b7908 MOV EDI,dword ptr [ECX + 0x8]
    s.di = m.r32((s.cx+0x00000008u));
  }
  L00431858: { // 0x431858: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L0043185c: { // 0x43185c: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0043185e: { // 0x43185e: 8a10 MOV DL,byte ptr [EAX]
    s.dx = with_al(s.dx, m.r8((s.ax)));
  }
  L00431860: { // 0x431860: 8a4641 MOV AL,byte ptr [ESI + 0x41]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000041u)));
  }
  L00431863: { // 0x431863: 8b74244c MOV ESI,dword ptr [ESP + 0x4c]
    s.si = m.r32((f.sp+0x0000004cu));
  }
  L00431867: { // 0x431867: 89542450 MOV dword ptr [ESP + 0x50],EDX
    m.w32((f.sp+0x00000050u), s.dx);
  }
  L0043186b: { // 0x43186b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0043186d: { // 0x43186d: 0f8405020000 JZ 0x00431a78
    if(integer::condition("JZ",flags)) goto L00431a78;
  }
  L00431873: { // 0x431873: 8b5c2448 MOV EBX,dword ptr [ESP + 0x48]
    s.bx = m.r32((f.sp+0x00000048u));
  }
  L00431877: { // 0x431877: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L00431879: { // 0x431879: 8d4437ff LEA EAX,[EDI + ESI*0x1 + -0x1]
    s.ax = (s.di+(s.si * 0x00000001u)-0x00000001u);
  }
  L0043187d: { // 0x43187d: 8d5419ff LEA EDX,[ECX + EBX*0x1 + -0x1]
    s.dx = (s.cx+(s.bx * 0x00000001u)-0x00000001u);
  }
  L00431881: { // 0x431881: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00431882: { // 0x431882: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00431883: { // 0x431883: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00431884: { // 0x431884: 8d44242c LEA EAX,[ESP + 0x2c]
    s.ax = (f.sp+0x0000002cu);
  }
  L00431888: { // 0x431888: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00431889: { // 0x431889: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0043188a: { // 0x43188a: ff15a8547800 CALL dword ptr [0x007854a8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((0x007854a8u)),4397200u,op); flags=s.arithmetic_flags;
  }
  L00431890: { // 0x431890: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L00431894: { // 0x431894: 8d542420 LEA EDX,[ESP + 0x20]
    s.dx = (f.sp+0x00000020u);
  }
  L00431898: { // 0x431898: 8d442430 LEA EAX,[ESP + 0x30]
    s.ax = (f.sp+0x00000030u);
  }
  L0043189c: { // 0x43189c: 8d4d30 LEA ECX,[EBP + 0x30]
    s.cx = (s.bp+0x00000030u);
  }
  L0043189f: { // 0x43189f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004318a0: { // 0x4318a0: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004318a1: { // 0x4318a1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004318a2: { // 0x4318a2: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L004318a4: { // 0x4318a4: e817060000 CALL 0x00431ec0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00431ec0u,4397225u,op); flags=s.arithmetic_flags;
  }
  L004318a9: { // 0x4318a9: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004318ab: { // 0x4318ab: 7515 JNZ 0x004318c2
    if(integer::condition("JNZ",flags)) goto L004318c2;
  }
  L004318ad: { // 0x4318ad: 8b452c MOV EAX,dword ptr [EBP + 0x2c]
    s.ax = m.r32((s.bp+0x0000002cu));
  }
  L004318b0: { // 0x4318b0: 8b542450 MOV EDX,dword ptr [ESP + 0x50]
    s.dx = m.r32((f.sp+0x00000050u));
  }
  L004318b4: { // 0x4318b4: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004318b6: { // 0x4318b6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004318b7: { // 0x4318b7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004318b8: { // 0x4318b8: 03c3 ADD EAX,EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L004318ba: { // 0x4318ba: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004318bb: { // 0x4318bb: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004318bc: { // 0x4318bc: 83c430 ADD ESP,0x30
    f.sp = integer::add(f.sp,0x00000030u,32,flags);
  }
  L004318bf: { // 0x4318bf: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L004318c2: { // 0x4318c2: 8b5c2430 MOV EBX,dword ptr [ESP + 0x30]
    s.bx = m.r32((f.sp+0x00000030u));
  }
  L004318c6: { // 0x4318c6: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L004318ca: { // 0x4318ca: 8b6c2424 MOV EBP,dword ptr [ESP + 0x24]
    s.bp = m.r32((f.sp+0x00000024u));
  }
  L004318ce: { // 0x4318ce: 8b4c243c MOV ECX,dword ptr [ESP + 0x3c]
    s.cx = m.r32((f.sp+0x0000003cu));
  }
  L004318d2: { // 0x4318d2: 8b542434 MOV EDX,dword ptr [ESP + 0x34]
    s.dx = m.r32((f.sp+0x00000034u));
  }
  L004318d6: { // 0x4318d6: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L004318d8: { // 0x4318d8: 7c18 JL 0x004318f2
    if(integer::condition("JL",flags)) goto L004318f2;
  }
  L004318da: { // 0x4318da: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L004318de: { // 0x4318de: 3b442438 CMP EAX,dword ptr [ESP + 0x38]
    (void)integer::sub(s.ax,m.r32((f.sp+0x00000038u)),32,flags);
  }
  L004318e2: { // 0x4318e2: 7f0e JG 0x004318f2
    if(integer::condition("JG",flags)) goto L004318f2;
  }
  L004318e4: { // 0x4318e4: 3bea CMP EBP,EDX
    (void)integer::sub(s.bp,s.dx,32,flags);
  }
  L004318e6: { // 0x4318e6: 7c0a JL 0x004318f2
    if(integer::condition("JL",flags)) goto L004318f2;
  }
  L004318e8: { // 0x4318e8: 394c242c CMP dword ptr [ESP + 0x2c],ECX
    (void)integer::sub(m.r32((f.sp+0x0000002cu)),s.cx,32,flags);
  }
  L004318ec: { // 0x4318ec: 0f8e86010000 JLE 0x00431a78
    if(integer::condition("JLE",flags)) goto L00431a78;
  }
  L004318f2: { // 0x4318f2: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L004318f4: { // 0x4318f4: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L004318f6: { // 0x4318f6: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L004318fa: { // 0x4318fa: 2bc5 SUB EAX,EBP
    s.ax = integer::sub(s.ax,s.bp,32,flags);
  }
  L004318fc: { // 0x4318fc: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L004318fe: { // 0x4318fe: 8b6c2414 MOV EBP,dword ptr [ESP + 0x14]
    s.bp = m.r32((f.sp+0x00000014u));
  }
  L00431902: { // 0x431902: 8b7a18 MOV EDI,dword ptr [EDX + 0x18]
    s.di = m.r32((s.dx+0x00000018u));
  }
  L00431905: { // 0x431905: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00431906: { // 0x431906: 0faff8 IMUL EDI,EAX
    s.di = integer::imul(s.di,s.ax,32,flags);
  }
  L00431909: { // 0x431909: 8b4210 MOV EAX,dword ptr [EDX + 0x10]
    s.ax = m.r32((s.dx+0x00000010u));
  }
  L0043190c: { // 0x43190c: 03ef ADD EBP,EDI
    s.bp = integer::add(s.bp,s.di,32,flags);
  }
  L0043190e: { // 0x43190e: 0fafc6 IMUL EAX,ESI
    s.ax = integer::imul(s.ax,s.si,32,flags);
  }
  L00431911: { // 0x431911: 8b742448 MOV ESI,dword ptr [ESP + 0x48]
    s.si = m.r32((f.sp+0x00000048u));
  }
  L00431915: { // 0x431915: 8b7c2438 MOV EDI,dword ptr [ESP + 0x38]
    s.di = m.r32((f.sp+0x00000038u));
  }
  L00431919: { // 0x431919: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L0043191b: { // 0x43191b: 8b720c MOV ESI,dword ptr [EDX + 0xc]
    s.si = m.r32((s.dx+0x0000000cu));
  }
  L0043191e: { // 0x43191e: 896c2414 MOV dword ptr [ESP + 0x14],EBP
    m.w32((f.sp+0x00000014u), s.bp);
  }
  L00431922: { // 0x431922: 8d3446 LEA ESI,[ESI + EAX*0x2]
    s.si = (s.si+(s.ax * 0x00000002u));
  }
  L00431925: { // 0x431925: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00431927: { // 0x431927: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00431928: { // 0x431928: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L0043192c: { // 0x43192c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0043192e: { // 0x43192e: 0f8430020000 JZ 0x00431b64
    if(integer::condition("JZ",flags)) goto L00431b64;
  }
  L00431934: { // 0x431934: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00431935: { // 0x431935: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L00431939: { // 0x431939: 8b4c2450 MOV ECX,dword ptr [ESP + 0x50]
    s.cx = m.r32((f.sp+0x00000050u));
  }
  L0043193d: { // 0x43193d: 8b442448 MOV EAX,dword ptr [ESP + 0x48]
    s.ax = m.r32((f.sp+0x00000048u));
  }
  L00431941: { // 0x431941: 896c244c MOV dword ptr [ESP + 0x4c],EBP
    m.w32((f.sp+0x0000004cu), s.bp);
  }
  L00431945: { // 0x431945: 8b6c244c MOV EBP,dword ptr [ESP + 0x4c]
    s.bp = m.r32((f.sp+0x0000004cu));
  }
  L00431949: { // 0x431949: 8a5500 MOV DL,byte ptr [EBP]
    s.dx = with_al(s.dx, m.r8((s.bp)));
  }
  L0043194c: { // 0x43194c: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L0043194d: { // 0x43194d: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L0043194f: { // 0x43194f: 896c244c MOV dword ptr [ESP + 0x4c],EBP
    m.w32((f.sp+0x0000004cu), s.bp);
  }
  L00431953: { // 0x431953: 750e JNZ 0x00431963
    if(integer::condition("JNZ",flags)) goto L00431963;
  }
  L00431955: { // 0x431955: 83c610 ADD ESI,0x10
    s.si = integer::add(s.si,0x00000010u,32,flags);
  }
  L00431958: { // 0x431958: 83e908 SUB ECX,0x8
    s.cx = integer::sub(s.cx,0x00000008u,32,flags);
  }
  L0043195b: { // 0x43195b: 83c008 ADD EAX,0x8
    s.ax = integer::add(s.ax,0x00000008u,32,flags);
  }
  L0043195e: { // 0x43195e: e9da000000 JMP 0x00431a3d
    goto L00431a3d;
  }
  L00431963: { // 0x431963: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00431965: { // 0x431965: 7c12 JL 0x00431979
    if(integer::condition("JL",flags)) goto L00431979;
  }
  L00431967: { // 0x431967: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L00431969: { // 0x431969: 7f0e JG 0x00431979
    if(integer::condition("JG",flags)) goto L00431979;
  }
  L0043196b: { // 0x43196b: f6c280 TEST DL,0x80
    (void)integer::logical(((s.dx & 0xffu))&(0x00000080u),8,flags);
  }
  L0043196e: { // 0x43196e: 7409 JZ 0x00431979
    if(integer::condition("JZ",flags)) goto L00431979;
  }
  L00431970: { // 0x431970: 8b6c2444 MOV EBP,dword ptr [ESP + 0x44]
    s.bp = m.r32((f.sp+0x00000044u));
  }
  L00431974: { // 0x431974: 66892e MOV word ptr [ESI],BP
    m.w16((s.si), (s.bp & 0xffffu));
  }
  L00431977: { // 0x431977: eb04 JMP 0x0043197d
    goto L0043197d;
  }
  L00431979: { // 0x431979: 8b6c2444 MOV EBP,dword ptr [ESP + 0x44]
    s.bp = m.r32((f.sp+0x00000044u));
  }
  L0043197d: { // 0x43197d: 83c602 ADD ESI,0x2
    s.si = integer::add(s.si,0x00000002u,32,flags);
  }
  L00431980: { // 0x431980: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00431981: { // 0x431981: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00431982: { // 0x431982: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00431984: { // 0x431984: 0f8ebb000000 JLE 0x00431a45
    if(integer::condition("JLE",flags)) goto L00431a45;
  }
  L0043198a: { // 0x43198a: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0043198c: { // 0x43198c: 7c0c JL 0x0043199a
    if(integer::condition("JL",flags)) goto L0043199a;
  }
  L0043198e: { // 0x43198e: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L00431990: { // 0x431990: 7f08 JG 0x0043199a
    if(integer::condition("JG",flags)) goto L0043199a;
  }
  L00431992: { // 0x431992: f6c240 TEST DL,0x40
    (void)integer::logical(((s.dx & 0xffu))&(0x00000040u),8,flags);
  }
  L00431995: { // 0x431995: 7403 JZ 0x0043199a
    if(integer::condition("JZ",flags)) goto L0043199a;
  }
  L00431997: { // 0x431997: 66892e MOV word ptr [ESI],BP
    m.w16((s.si), (s.bp & 0xffffu));
  }
  L0043199a: { // 0x43199a: 83c602 ADD ESI,0x2
    s.si = integer::add(s.si,0x00000002u,32,flags);
  }
  L0043199d: { // 0x43199d: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0043199e: { // 0x43199e: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0043199f: { // 0x43199f: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004319a1: { // 0x4319a1: 0f8e9e000000 JLE 0x00431a45
    if(integer::condition("JLE",flags)) goto L00431a45;
  }
  L004319a7: { // 0x4319a7: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L004319a9: { // 0x4319a9: 7c0c JL 0x004319b7
    if(integer::condition("JL",flags)) goto L004319b7;
  }
  L004319ab: { // 0x4319ab: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L004319ad: { // 0x4319ad: 7f08 JG 0x004319b7
    if(integer::condition("JG",flags)) goto L004319b7;
  }
  L004319af: { // 0x4319af: f6c220 TEST DL,0x20
    (void)integer::logical(((s.dx & 0xffu))&(0x00000020u),8,flags);
  }
  L004319b2: { // 0x4319b2: 7403 JZ 0x004319b7
    if(integer::condition("JZ",flags)) goto L004319b7;
  }
  L004319b4: { // 0x4319b4: 66892e MOV word ptr [ESI],BP
    m.w16((s.si), (s.bp & 0xffffu));
  }
  L004319b7: { // 0x4319b7: 83c602 ADD ESI,0x2
    s.si = integer::add(s.si,0x00000002u,32,flags);
  }
  L004319ba: { // 0x4319ba: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004319bb: { // 0x4319bb: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L004319bc: { // 0x4319bc: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004319be: { // 0x4319be: 0f8e81000000 JLE 0x00431a45
    if(integer::condition("JLE",flags)) goto L00431a45;
  }
  L004319c4: { // 0x4319c4: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L004319c6: { // 0x4319c6: 7c0c JL 0x004319d4
    if(integer::condition("JL",flags)) goto L004319d4;
  }
  L004319c8: { // 0x4319c8: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L004319ca: { // 0x4319ca: 7f08 JG 0x004319d4
    if(integer::condition("JG",flags)) goto L004319d4;
  }
  L004319cc: { // 0x4319cc: f6c210 TEST DL,0x10
    (void)integer::logical(((s.dx & 0xffu))&(0x00000010u),8,flags);
  }
  L004319cf: { // 0x4319cf: 7403 JZ 0x004319d4
    if(integer::condition("JZ",flags)) goto L004319d4;
  }
  L004319d1: { // 0x4319d1: 66892e MOV word ptr [ESI],BP
    m.w16((s.si), (s.bp & 0xffffu));
  }
  L004319d4: { // 0x4319d4: 83c602 ADD ESI,0x2
    s.si = integer::add(s.si,0x00000002u,32,flags);
  }
  L004319d7: { // 0x4319d7: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004319d8: { // 0x4319d8: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L004319d9: { // 0x4319d9: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004319db: { // 0x4319db: 7e68 JLE 0x00431a45
    if(integer::condition("JLE",flags)) goto L00431a45;
  }
  L004319dd: { // 0x4319dd: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L004319df: { // 0x4319df: 7c0c JL 0x004319ed
    if(integer::condition("JL",flags)) goto L004319ed;
  }
  L004319e1: { // 0x4319e1: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L004319e3: { // 0x4319e3: 7f08 JG 0x004319ed
    if(integer::condition("JG",flags)) goto L004319ed;
  }
  L004319e5: { // 0x4319e5: f6c208 TEST DL,0x8
    (void)integer::logical(((s.dx & 0xffu))&(0x00000008u),8,flags);
  }
  L004319e8: { // 0x4319e8: 7403 JZ 0x004319ed
    if(integer::condition("JZ",flags)) goto L004319ed;
  }
  L004319ea: { // 0x4319ea: 66892e MOV word ptr [ESI],BP
    m.w16((s.si), (s.bp & 0xffffu));
  }
  L004319ed: { // 0x4319ed: 83c602 ADD ESI,0x2
    s.si = integer::add(s.si,0x00000002u,32,flags);
  }
  L004319f0: { // 0x4319f0: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004319f1: { // 0x4319f1: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L004319f2: { // 0x4319f2: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004319f4: { // 0x4319f4: 7e4f JLE 0x00431a45
    if(integer::condition("JLE",flags)) goto L00431a45;
  }
  L004319f6: { // 0x4319f6: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L004319f8: { // 0x4319f8: 7c0c JL 0x00431a06
    if(integer::condition("JL",flags)) goto L00431a06;
  }
  L004319fa: { // 0x4319fa: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L004319fc: { // 0x4319fc: 7f08 JG 0x00431a06
    if(integer::condition("JG",flags)) goto L00431a06;
  }
  L004319fe: { // 0x4319fe: f6c204 TEST DL,0x4
    (void)integer::logical(((s.dx & 0xffu))&(0x00000004u),8,flags);
  }
  L00431a01: { // 0x431a01: 7403 JZ 0x00431a06
    if(integer::condition("JZ",flags)) goto L00431a06;
  }
  L00431a03: { // 0x431a03: 66892e MOV word ptr [ESI],BP
    m.w16((s.si), (s.bp & 0xffffu));
  }
  L00431a06: { // 0x431a06: 83c602 ADD ESI,0x2
    s.si = integer::add(s.si,0x00000002u,32,flags);
  }
  L00431a09: { // 0x431a09: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00431a0a: { // 0x431a0a: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00431a0b: { // 0x431a0b: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00431a0d: { // 0x431a0d: 7e36 JLE 0x00431a45
    if(integer::condition("JLE",flags)) goto L00431a45;
  }
  L00431a0f: { // 0x431a0f: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00431a11: { // 0x431a11: 7c0c JL 0x00431a1f
    if(integer::condition("JL",flags)) goto L00431a1f;
  }
  L00431a13: { // 0x431a13: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L00431a15: { // 0x431a15: 7f08 JG 0x00431a1f
    if(integer::condition("JG",flags)) goto L00431a1f;
  }
  L00431a17: { // 0x431a17: f6c202 TEST DL,0x2
    (void)integer::logical(((s.dx & 0xffu))&(0x00000002u),8,flags);
  }
  L00431a1a: { // 0x431a1a: 7403 JZ 0x00431a1f
    if(integer::condition("JZ",flags)) goto L00431a1f;
  }
  L00431a1c: { // 0x431a1c: 66892e MOV word ptr [ESI],BP
    m.w16((s.si), (s.bp & 0xffffu));
  }
  L00431a1f: { // 0x431a1f: 83c602 ADD ESI,0x2
    s.si = integer::add(s.si,0x00000002u,32,flags);
  }
  L00431a22: { // 0x431a22: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00431a23: { // 0x431a23: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00431a24: { // 0x431a24: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00431a26: { // 0x431a26: 7e1d JLE 0x00431a45
    if(integer::condition("JLE",flags)) goto L00431a45;
  }
  L00431a28: { // 0x431a28: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00431a2a: { // 0x431a2a: 7c0c JL 0x00431a38
    if(integer::condition("JL",flags)) goto L00431a38;
  }
  L00431a2c: { // 0x431a2c: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L00431a2e: { // 0x431a2e: 7f08 JG 0x00431a38
    if(integer::condition("JG",flags)) goto L00431a38;
  }
  L00431a30: { // 0x431a30: f6c201 TEST DL,0x1
    (void)integer::logical(((s.dx & 0xffu))&(0x00000001u),8,flags);
  }
  L00431a33: { // 0x431a33: 7403 JZ 0x00431a38
    if(integer::condition("JZ",flags)) goto L00431a38;
  }
  L00431a35: { // 0x431a35: 66892e MOV word ptr [ESI],BP
    m.w16((s.si), (s.bp & 0xffffu));
  }
  L00431a38: { // 0x431a38: 83c602 ADD ESI,0x2
    s.si = integer::add(s.si,0x00000002u,32,flags);
  }
  L00431a3b: { // 0x431a3b: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00431a3c: { // 0x431a3c: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00431a3d: { // 0x431a3d: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00431a3f: { // 0x431a3f: 0f8f00ffffff JG 0x00431945
    if(integer::condition("JG",flags)) goto L00431945;
  }
  L00431a45: { // 0x431a45: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00431a49: { // 0x431a49: 8b6c2414 MOV EBP,dword ptr [ESP + 0x14]
    s.bp = m.r32((f.sp+0x00000014u));
  }
  L00431a4d: { // 0x431a4d: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00431a51: { // 0x431a51: 8b4a18 MOV ECX,dword ptr [EDX + 0x18]
    s.cx = m.r32((s.dx+0x00000018u));
  }
  L00431a54: { // 0x431a54: 03e9 ADD EBP,ECX
    s.bp = integer::add(s.bp,s.cx,32,flags);
  }
  L00431a56: { // 0x431a56: 8b4a10 MOV ECX,dword ptr [EDX + 0x10]
    s.cx = m.r32((s.dx+0x00000010u));
  }
  L00431a59: { // 0x431a59: 896c2414 MOV dword ptr [ESP + 0x14],EBP
    m.w32((f.sp+0x00000014u), s.bp);
  }
  L00431a5d: { // 0x431a5d: 8d3448 LEA ESI,[EAX + ECX*0x2]
    s.si = (s.ax+(s.cx * 0x00000002u));
  }
  L00431a60: { // 0x431a60: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L00431a64: { // 0x431a64: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00431a65: { // 0x431a65: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L00431a69: { // 0x431a69: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L00431a6d: { // 0x431a6d: 0f85c6feffff JNZ 0x00431939
    if(integer::condition("JNZ",flags)) goto L00431939;
  }
  L00431a73: { // 0x431a73: e9ec000000 JMP 0x00431b64
    goto L00431b64;
  }
  L00431a78: { // 0x431a78: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00431a7c: { // 0x431a7c: 8b4810 MOV ECX,dword ptr [EAX + 0x10]
    s.cx = m.r32((s.ax+0x00000010u));
  }
  L00431a7f: { // 0x431a7f: 8b500c MOV EDX,dword ptr [EAX + 0xc]
    s.dx = m.r32((s.ax+0x0000000cu));
  }
  L00431a82: { // 0x431a82: 0fafce IMUL ECX,ESI
    s.cx = integer::imul(s.cx,s.si,32,flags);
  }
  L00431a85: { // 0x431a85: 8b742448 MOV ESI,dword ptr [ESP + 0x48]
    s.si = m.r32((f.sp+0x00000048u));
  }
  L00431a89: { // 0x431a89: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L00431a8b: { // 0x431a8b: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L00431a8d: { // 0x431a8d: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L00431a8e: { // 0x431a8e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00431a90: { // 0x431a90: 8d2c4a LEA EBP,[EDX + ECX*0x2]
    s.bp = (s.dx+(s.cx * 0x00000002u));
  }
  L00431a93: { // 0x431a93: 0f84c7000000 JZ 0x00431b60
    if(integer::condition("JZ",flags)) goto L00431b60;
  }
  L00431a99: { // 0x431a99: 8b742444 MOV ESI,dword ptr [ESP + 0x44]
    s.si = m.r32((f.sp+0x00000044u));
  }
  L00431a9d: { // 0x431a9d: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L00431a9e: { // 0x431a9e: 897c244c MOV dword ptr [ESP + 0x4c],EDI
    m.w32((f.sp+0x0000004cu), s.di);
  }
  L00431aa2: { // 0x431aa2: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L00431aa6: { // 0x431aa6: 8b442450 MOV EAX,dword ptr [ESP + 0x50]
    s.ax = m.r32((f.sp+0x00000050u));
  }
  L00431aaa: { // 0x431aaa: 8bdf MOV EBX,EDI
    s.bx = s.di;
  }
  L00431aac: { // 0x431aac: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00431aae: { // 0x431aae: 8a13 MOV DL,byte ptr [EBX]
    s.dx = with_al(s.dx, m.r8((s.bx)));
  }
  L00431ab0: { // 0x431ab0: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L00431ab1: { // 0x431ab1: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L00431ab3: { // 0x431ab3: 7508 JNZ 0x00431abd
    if(integer::condition("JNZ",flags)) goto L00431abd;
  }
  L00431ab5: { // 0x431ab5: 83c110 ADD ECX,0x10
    s.cx = integer::add(s.cx,0x00000010u,32,flags);
  }
  L00431ab8: { // 0x431ab8: 83e808 SUB EAX,0x8
    s.ax = integer::sub(s.ax,0x00000008u,32,flags);
  }
  L00431abb: { // 0x431abb: eb7c JMP 0x00431b39
    goto L00431b39;
  }
  L00431abd: { // 0x431abd: f6c280 TEST DL,0x80
    (void)integer::logical(((s.dx & 0xffu))&(0x00000080u),8,flags);
  }
  L00431ac0: { // 0x431ac0: 7403 JZ 0x00431ac5
    if(integer::condition("JZ",flags)) goto L00431ac5;
  }
  L00431ac2: { // 0x431ac2: 668931 MOV word ptr [ECX],SI
    m.w16((s.cx), (s.si & 0xffffu));
  }
  L00431ac5: { // 0x431ac5: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L00431ac8: { // 0x431ac8: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00431ac9: { // 0x431ac9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00431acb: { // 0x431acb: 7e74 JLE 0x00431b41
    if(integer::condition("JLE",flags)) goto L00431b41;
  }
  L00431acd: { // 0x431acd: f6c240 TEST DL,0x40
    (void)integer::logical(((s.dx & 0xffu))&(0x00000040u),8,flags);
  }
  L00431ad0: { // 0x431ad0: 7403 JZ 0x00431ad5
    if(integer::condition("JZ",flags)) goto L00431ad5;
  }
  L00431ad2: { // 0x431ad2: 668931 MOV word ptr [ECX],SI
    m.w16((s.cx), (s.si & 0xffffu));
  }
  L00431ad5: { // 0x431ad5: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L00431ad8: { // 0x431ad8: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00431ad9: { // 0x431ad9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00431adb: { // 0x431adb: 7e64 JLE 0x00431b41
    if(integer::condition("JLE",flags)) goto L00431b41;
  }
  L00431add: { // 0x431add: f6c220 TEST DL,0x20
    (void)integer::logical(((s.dx & 0xffu))&(0x00000020u),8,flags);
  }
  L00431ae0: { // 0x431ae0: 7403 JZ 0x00431ae5
    if(integer::condition("JZ",flags)) goto L00431ae5;
  }
  L00431ae2: { // 0x431ae2: 668931 MOV word ptr [ECX],SI
    m.w16((s.cx), (s.si & 0xffffu));
  }
  L00431ae5: { // 0x431ae5: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L00431ae8: { // 0x431ae8: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00431ae9: { // 0x431ae9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00431aeb: { // 0x431aeb: 7e54 JLE 0x00431b41
    if(integer::condition("JLE",flags)) goto L00431b41;
  }
  L00431aed: { // 0x431aed: f6c210 TEST DL,0x10
    (void)integer::logical(((s.dx & 0xffu))&(0x00000010u),8,flags);
  }
  L00431af0: { // 0x431af0: 7403 JZ 0x00431af5
    if(integer::condition("JZ",flags)) goto L00431af5;
  }
  L00431af2: { // 0x431af2: 668931 MOV word ptr [ECX],SI
    m.w16((s.cx), (s.si & 0xffffu));
  }
  L00431af5: { // 0x431af5: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L00431af8: { // 0x431af8: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00431af9: { // 0x431af9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00431afb: { // 0x431afb: 7e44 JLE 0x00431b41
    if(integer::condition("JLE",flags)) goto L00431b41;
  }
  L00431afd: { // 0x431afd: f6c208 TEST DL,0x8
    (void)integer::logical(((s.dx & 0xffu))&(0x00000008u),8,flags);
  }
  L00431b00: { // 0x431b00: 7403 JZ 0x00431b05
    if(integer::condition("JZ",flags)) goto L00431b05;
  }
  L00431b02: { // 0x431b02: 668931 MOV word ptr [ECX],SI
    m.w16((s.cx), (s.si & 0xffffu));
  }
  L00431b05: { // 0x431b05: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L00431b08: { // 0x431b08: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00431b09: { // 0x431b09: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00431b0b: { // 0x431b0b: 7e34 JLE 0x00431b41
    if(integer::condition("JLE",flags)) goto L00431b41;
  }
  L00431b0d: { // 0x431b0d: f6c204 TEST DL,0x4
    (void)integer::logical(((s.dx & 0xffu))&(0x00000004u),8,flags);
  }
  L00431b10: { // 0x431b10: 7403 JZ 0x00431b15
    if(integer::condition("JZ",flags)) goto L00431b15;
  }
  L00431b12: { // 0x431b12: 668931 MOV word ptr [ECX],SI
    m.w16((s.cx), (s.si & 0xffffu));
  }
  L00431b15: { // 0x431b15: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L00431b18: { // 0x431b18: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00431b19: { // 0x431b19: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00431b1b: { // 0x431b1b: 7e24 JLE 0x00431b41
    if(integer::condition("JLE",flags)) goto L00431b41;
  }
  L00431b1d: { // 0x431b1d: f6c202 TEST DL,0x2
    (void)integer::logical(((s.dx & 0xffu))&(0x00000002u),8,flags);
  }
  L00431b20: { // 0x431b20: 7403 JZ 0x00431b25
    if(integer::condition("JZ",flags)) goto L00431b25;
  }
  L00431b22: { // 0x431b22: 668931 MOV word ptr [ECX],SI
    m.w16((s.cx), (s.si & 0xffffu));
  }
  L00431b25: { // 0x431b25: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L00431b28: { // 0x431b28: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00431b29: { // 0x431b29: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00431b2b: { // 0x431b2b: 7e14 JLE 0x00431b41
    if(integer::condition("JLE",flags)) goto L00431b41;
  }
  L00431b2d: { // 0x431b2d: f6c201 TEST DL,0x1
    (void)integer::logical(((s.dx & 0xffu))&(0x00000001u),8,flags);
  }
  L00431b30: { // 0x431b30: 7403 JZ 0x00431b35
    if(integer::condition("JZ",flags)) goto L00431b35;
  }
  L00431b32: { // 0x431b32: 668931 MOV word ptr [ECX],SI
    m.w16((s.cx), (s.si & 0xffffu));
  }
  L00431b35: { // 0x431b35: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L00431b38: { // 0x431b38: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00431b39: { // 0x431b39: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00431b3b: { // 0x431b3b: 0f8f6dffffff JG 0x00431aae
    if(integer::condition("JG",flags)) goto L00431aae;
  }
  L00431b41: { // 0x431b41: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00431b45: { // 0x431b45: 8b4818 MOV ECX,dword ptr [EAX + 0x18]
    s.cx = m.r32((s.ax+0x00000018u));
  }
  L00431b48: { // 0x431b48: 03f9 ADD EDI,ECX
    s.di = integer::add(s.di,s.cx,32,flags);
  }
  L00431b4a: { // 0x431b4a: 8b4810 MOV ECX,dword ptr [EAX + 0x10]
    s.cx = m.r32((s.ax+0x00000010u));
  }
  L00431b4d: { // 0x431b4d: 8b44244c MOV EAX,dword ptr [ESP + 0x4c]
    s.ax = m.r32((f.sp+0x0000004cu));
  }
  L00431b51: { // 0x431b51: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00431b52: { // 0x431b52: 8d6c4d00 LEA EBP,[EBP + ECX*0x2]
    s.bp = (s.bp+(s.cx * 0x00000002u));
  }
  L00431b56: { // 0x431b56: 8944244c MOV dword ptr [ESP + 0x4c],EAX
    m.w32((f.sp+0x0000004cu), s.ax);
  }
  L00431b5a: { // 0x431b5a: 0f8546ffffff JNZ 0x00431aa6
    if(integer::condition("JNZ",flags)) goto L00431aa6;
  }
  L00431b60: { // 0x431b60: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00431b64: { // 0x431b64: 8b422c MOV EAX,dword ptr [EDX + 0x2c]
    s.ax = m.r32((s.dx+0x0000002cu));
  }
  L00431b67: { // 0x431b67: 8b542450 MOV EDX,dword ptr [ESP + 0x50]
    s.dx = m.r32((f.sp+0x00000050u));
  }
  L00431b6b: { // 0x431b6b: 8b4c2448 MOV ECX,dword ptr [ESP + 0x48]
    s.cx = m.r32((f.sp+0x00000048u));
  }
  L00431b6f: { // 0x431b6f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00431b70: { // 0x431b70: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00431b72: { // 0x431b72: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00431b73: { // 0x431b73: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00431b74: { // 0x431b74: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00431b76: { // 0x431b76: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00431b77: { // 0x431b77: 83c430 ADD ESP,0x30
    f.sp = integer::add(f.sp,0x00000030u,32,flags);
  }
  L00431b7a: { // 0x431b7a: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
}

void f_00031b80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00431b80: { // 0x431b80: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L00431b83: { // 0x431b83: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L00431b87: { // 0x431b87: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00431b88: { // 0x431b88: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00431b89: { // 0x431b89: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00431b8a: { // 0x431b8a: 668b32 MOV SI,word ptr [EDX]
    s.si = (s.si & 0xffff0000u) | ((m.r16((s.dx))) & 0xffffu);
  }
  L00431b8d: { // 0x431b8d: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00431b8e: { // 0x431b8e: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L00431b90: { // 0x431b90: 83c202 ADD EDX,0x2
    s.dx = integer::add(s.dx,0x00000002u,32,flags);
  }
  L00431b93: { // 0x431b93: 6685f6 TEST SI,SI
    (void)integer::logical(((s.si & 0xffffu))&((s.si & 0xffffu)),16,flags);
  }
  L00431b96: { // 0x431b96: 668b5f24 MOV BX,word ptr [EDI + 0x24]
    s.bx = with_ax(s.bx, m.r16((s.di+0x00000024u)));
  }
  L00431b9a: { // 0x431b9a: c744241800000000 MOV dword ptr [ESP + 0x18],0x0
    m.w32((f.sp+0x00000018u), 0x00000000u);
  }
  L00431ba2: { // 0x431ba2: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L00431ba6: { // 0x431ba6: 0f844f010000 JZ 0x00431cfb
    if(integer::condition("JZ",flags)) goto L00431cfb;
  }
  L00431bac: { // 0x431bac: 8b4c2434 MOV ECX,dword ptr [ESP + 0x34]
    s.cx = m.r32((f.sp+0x00000034u));
  }
  L00431bb0: { // 0x431bb0: 8d41ff LEA EAX,[ECX + -0x1]
    s.ax = (s.cx-0x00000001u);
  }
  L00431bb3: { // 0x431bb3: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L00431bb7: { // 0x431bb7: b809000000 MOV EAX,0x9
    s.ax = 0x00000009u;
  }
  L00431bbc: { // 0x431bbc: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00431bbe: { // 0x431bbe: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L00431bc0: { // 0x431bc0: c1e505 SHL EBP,0x5
    s.bp = integer::shift(s.bp,0x00000005u,32,flags,integer::Shift::left);
  }
  L00431bc3: { // 0x431bc3: 2be8 SUB EBP,EAX
    s.bp = integer::sub(s.bp,s.ax,32,flags);
  }
  L00431bc5: { // 0x431bc5: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00431bc7: { // 0x431bc7: 0f84e0000000 JZ 0x00431cad
    if(integer::condition("JZ",flags)) goto L00431cad;
  }
  L00431bcd: { // 0x431bcd: 394c2418 CMP dword ptr [ESP + 0x18],ECX
    (void)integer::sub(m.r32((f.sp+0x00000018u)),s.cx,32,flags);
  }
  L00431bd1: { // 0x431bd1: 0f8d36010000 JGE 0x00431d0d
    if(integer::condition("JGE",flags)) goto L00431d0d;
  }
  L00431bd7: { // 0x431bd7: 837c241c08 CMP dword ptr [ESP + 0x1c],0x8
    (void)integer::sub(m.r32((f.sp+0x0000001cu)),0x00000008u,32,flags);
  }
  L00431bdc: { // 0x431bdc: 0f8db6000000 JGE 0x00431c98
    if(integer::condition("JGE",flags)) goto L00431c98;
  }
  L00431be2: { // 0x431be2: 668b0de8b28300 MOV CX,word ptr [0x0083b2e8]
    s.cx = with_ax(s.cx, m.r16((0x0083b2e8u)));
  }
  L00431be9: { // 0x431be9: 8bd3 MOV EDX,EBX
    s.dx = s.bx;
  }
  L00431beb: { // 0x431beb: 66d3ea SHR DX,CL
    s.dx = with_ax(s.dx, integer::shift((s.dx & 0xffffu),(s.cx & 0xffu),16,flags,integer::Shift::right));
  }
  L00431bee: { // 0x431bee: 8b0decb28300 MOV ECX,dword ptr [0x0083b2ec]
    s.cx = m.r32((0x0083b2ecu));
  }
  L00431bf4: { // 0x431bf4: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L00431bf6: { // 0x431bf6: 6869e3a900 PUSH 0xa9e369
    f.push(m,0x00a9e369u);
  }
  L00431bfb: { // 0x431bfb: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00431bfc: { // 0x431bfc: d2e2 SHL DL,CL
    s.dx = with_al(s.dx, integer::shift((s.dx & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::left));
  }
  L00431bfe: { // 0x431bfe: 668b0df8b28300 MOV CX,word ptr [0x0083b2f8]
    s.cx = with_ax(s.cx, m.r16((0x0083b2f8u)));
  }
  L00431c05: { // 0x431c05: 66d3e8 SHR AX,CL
    s.ax = with_ax(s.ax, integer::shift((s.ax & 0xffffu),(s.cx & 0xffu),16,flags,integer::Shift::right));
  }
  L00431c08: { // 0x431c08: 8b0dfcb28300 MOV ECX,dword ptr [0x0083b2fc]
    s.cx = m.r32((0x0083b2fcu));
  }
  L00431c0e: { // 0x431c0e: 88542418 MOV byte ptr [ESP + 0x18],DL
    m.w8((f.sp+0x00000018u), (s.dx & 0xffu));
  }
  L00431c12: { // 0x431c12: d2e0 SHL AL,CL
    s.ax = with_al(s.ax, integer::shift((s.ax & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::left));
  }
  L00431c14: { // 0x431c14: 668b0df0b28300 MOV CX,word ptr [0x0083b2f0]
    s.cx = with_ax(s.cx, m.r16((0x0083b2f0u)));
  }
  L00431c1b: { // 0x431c1b: 88442419 MOV byte ptr [ESP + 0x19],AL
    m.w8((f.sp+0x00000019u), (s.ax & 0xffu));
  }
  L00431c1f: { // 0x431c1f: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L00431c21: { // 0x431c21: 66d3e8 SHR AX,CL
    s.ax = with_ax(s.ax, integer::shift((s.ax & 0xffffu),(s.cx & 0xffu),16,flags,integer::Shift::right));
  }
  L00431c24: { // 0x431c24: 8b0df4b28300 MOV ECX,dword ptr [0x0083b2f4]
    s.cx = m.r32((0x0083b2f4u));
  }
  L00431c2a: { // 0x431c2a: d2e0 SHL AL,CL
    s.ax = with_al(s.ax, integer::shift((s.ax & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::left));
  }
  L00431c2c: { // 0x431c2c: 668b4c2418 MOV CX,word ptr [ESP + 0x18]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000018u)));
  }
  L00431c31: { // 0x431c31: 66894c241c MOV word ptr [ESP + 0x1c],CX
    m.w16((f.sp+0x0000001cu), (s.cx & 0xffffu));
  }
  L00431c36: { // 0x431c36: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L00431c3a: { // 0x431c3a: 8844241e MOV byte ptr [ESP + 0x1e],AL
    m.w8((f.sp+0x0000001eu), (s.ax & 0xffu));
  }
  L00431c3e: { // 0x431c3e: e8cd262000 CALL 0x00634310
    s.arithmetic_flags=flags; invoke(m,s,f,0x00634310u,4398147u,op); flags=s.arithmetic_flags;
  }
  L00431c43: { // 0x431c43: 8a542415 MOV DL,byte ptr [ESP + 0x15]
    s.dx = with_al(s.dx, m.r8((f.sp+0x00000015u)));
  }
  L00431c47: { // 0x431c47: 8a0dfcb28300 MOV CL,byte ptr [0x0083b2fc]
    s.cx = with_al(s.cx, m.r8((0x0083b2fcu)));
  }
  L00431c4d: { // 0x431c4d: d2ea SHR DL,CL
    s.dx = with_al(s.dx, integer::shift((s.dx & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::right));
  }
  L00431c4f: { // 0x431c4f: 8b0df8b28300 MOV ECX,dword ptr [0x0083b2f8]
    s.cx = m.r32((0x0083b2f8u));
  }
  L00431c55: { // 0x431c55: 6633c0 XOR AX,AX
    s.ax = with_ax(s.ax, integer::logical(((s.ax & 0xffffu))^((s.ax & 0xffffu)),16,flags));
  }
  L00431c58: { // 0x431c58: 8ac2 MOV AL,DL
    s.ax = with_al(s.ax, (s.dx & 0xffu));
  }
  L00431c5a: { // 0x431c5a: 8a542416 MOV DL,byte ptr [ESP + 0x16]
    s.dx = with_al(s.dx, m.r8((f.sp+0x00000016u)));
  }
  L00431c5e: { // 0x431c5e: d3e0 SHL EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L00431c60: { // 0x431c60: 8a0df4b28300 MOV CL,byte ptr [0x0083b2f4]
    s.cx = with_al(s.cx, m.r8((0x0083b2f4u)));
  }
  L00431c66: { // 0x431c66: d2ea SHR DL,CL
    s.dx = with_al(s.dx, integer::shift((s.dx & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::right));
  }
  L00431c68: { // 0x431c68: 8b0df0b28300 MOV ECX,dword ptr [0x0083b2f0]
    s.cx = m.r32((0x0083b2f0u));
  }
  L00431c6e: { // 0x431c6e: 660fb6d2 MOVZX DX,DL
    s.dx = with_ax(s.dx, ((s.dx & 0xffu)&integer::mask(8)));
  }
  L00431c72: { // 0x431c72: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L00431c74: { // 0x431c74: 8a0decb28300 MOV CL,byte ptr [0x0083b2ec]
    s.cx = with_al(s.cx, m.r8((0x0083b2ecu)));
  }
  L00431c7a: { // 0x431c7a: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  L00431c7c: { // 0x431c7c: 8a542414 MOV DL,byte ptr [ESP + 0x14]
    s.dx = with_al(s.dx, m.r8((f.sp+0x00000014u)));
  }
  L00431c80: { // 0x431c80: d2ea SHR DL,CL
    s.dx = with_al(s.dx, integer::shift((s.dx & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::right));
  }
  L00431c82: { // 0x431c82: 8b0de8b28300 MOV ECX,dword ptr [0x0083b2e8]
    s.cx = m.r32((0x0083b2e8u));
  }
  L00431c88: { // 0x431c88: 660fb6d2 MOVZX DX,DL
    s.dx = with_ax(s.dx, ((s.dx & 0xffu)&integer::mask(8)));
  }
  L00431c8c: { // 0x431c8c: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L00431c8e: { // 0x431c8e: 8b4c2434 MOV ECX,dword ptr [ESP + 0x34]
    s.cx = m.r32((f.sp+0x00000034u));
  }
  L00431c92: { // 0x431c92: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  L00431c94: { // 0x431c94: 66894724 MOV word ptr [EDI + 0x24],AX
    m.w16((s.di+0x00000024u), (s.ax & 0xffffu));
  }
  L00431c98: { // 0x431c98: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00431c9c: { // 0x431c9c: 83c51f ADD EBP,0x1f
    s.bp = integer::add(s.bp,0x0000001fu,32,flags);
  }
  L00431c9f: { // 0x431c9f: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00431ca0: { // 0x431ca0: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00431ca4: { // 0x431ca4: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L00431ca8: { // 0x431ca8: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00431ca9: { // 0x431ca9: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L00431cad: { // 0x431cad: 6683fe0d CMP SI,0xd
    (void)integer::sub((s.si & 0xffffu),0x0000000du,16,flags);
  }
  L00431cb1: { // 0x431cb1: 7422 JZ 0x00431cd5
    if(integer::condition("JZ",flags)) goto L00431cd5;
  }
  L00431cb3: { // 0x431cb3: 6683fe0a CMP SI,0xa
    (void)integer::sub((s.si & 0xffffu),0x0000000au,16,flags);
  }
  L00431cb7: { // 0x431cb7: 741c JZ 0x00431cd5
    if(integer::condition("JZ",flags)) goto L00431cd5;
  }
  L00431cb9: { // 0x431cb9: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L00431cbd: { // 0x431cbd: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L00431cc1: { // 0x431cc1: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L00431cc3: { // 0x431cc3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00431cc4: { // 0x431cc4: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00431cc5: { // 0x431cc5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00431cc6: { // 0x431cc6: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00431cc8: { // 0x431cc8: e8d3faffff CALL 0x004317a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004317a0u,4398285u,op); flags=s.arithmetic_flags;
  }
  L00431ccd: { // 0x431ccd: 8b4c2434 MOV ECX,dword ptr [ESP + 0x34]
    s.cx = m.r32((f.sp+0x00000034u));
  }
  L00431cd1: { // 0x431cd1: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L00431cd5: { // 0x431cd5: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L00431cd9: { // 0x431cd9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00431cdb: { // 0x431cdb: 7407 JZ 0x00431ce4
    if(integer::condition("JZ",flags)) goto L00431ce4;
  }
  L00431cdd: { // 0x431cdd: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00431cde: { // 0x431cde: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L00431ce2: { // 0x431ce2: 7417 JZ 0x00431cfb
    if(integer::condition("JZ",flags)) goto L00431cfb;
  }
  L00431ce4: { // 0x431ce4: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L00431ce8: { // 0x431ce8: 668b32 MOV SI,word ptr [EDX]
    s.si = (s.si & 0xffff0000u) | ((m.r16((s.dx))) & 0xffffu);
  }
  L00431ceb: { // 0x431ceb: 83c202 ADD EDX,0x2
    s.dx = integer::add(s.dx,0x00000002u,32,flags);
  }
  L00431cee: { // 0x431cee: 6685f6 TEST SI,SI
    (void)integer::logical(((s.si & 0xffffu))&((s.si & 0xffffu)),16,flags);
  }
  L00431cf1: { // 0x431cf1: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L00431cf5: { // 0x431cf5: 0f85cafeffff JNZ 0x00431bc5
    if(integer::condition("JNZ",flags)) goto L00431bc5;
  }
  L00431cfb: { // 0x431cfb: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L00431cff: { // 0x431cff: 66895f24 MOV word ptr [EDI + 0x24],BX
    m.w16((s.di+0x00000024u), (s.bx & 0xffffu));
  }
  L00431d03: { // 0x431d03: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00431d04: { // 0x431d04: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00431d05: { // 0x431d05: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00431d06: { // 0x431d06: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00431d07: { // 0x431d07: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00431d0a: { // 0x431d0a: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
  L00431d0d: { // 0x431d0d: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00431d0f: { // 0x431d0f: 8d442428 LEA EAX,[ESP + 0x28]
    s.ax = (f.sp+0x00000028u);
  }
  L00431d13: { // 0x431d13: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00431d15: { // 0x431d15: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00431d16: { // 0x431d16: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00431d17: { // 0x431d17: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00431d19: { // 0x431d19: 66895f24 MOV word ptr [EDI + 0x24],BX
    m.w16((s.di+0x00000024u), (s.bx & 0xffffu));
  }
  L00431d1d: { // 0x431d1d: e84ef6ffff CALL 0x00431370
    s.arithmetic_flags=flags; invoke(m,s,f,0x00431370u,4398370u,op); flags=s.arithmetic_flags;
  }
  L00431d22: { // 0x431d22: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L00431d26: { // 0x431d26: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L00431d2a: { // 0x431d2a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00431d2b: { // 0x431d2b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00431d2c: { // 0x431d2c: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00431d2d: { // 0x431d2d: 8d0411 LEA EAX,[ECX + EDX*0x1]
    s.ax = (s.cx+(s.dx * 0x00000001u));
  }
  L00431d30: { // 0x431d30: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00431d31: { // 0x431d31: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00431d34: { // 0x431d34: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
}

void f_00031ec0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00431ec0: { // 0x431ec0: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  L00431ec4: { // 0x431ec4: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  L00431ec8: { // 0x431ec8: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00431ec9: { // 0x431ec9: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L00431ecc: { // 0x431ecc: 8b720c MOV ESI,dword ptr [EDX + 0xc]
    s.si = m.r32((s.dx+0x0000000cu));
  }
  L00431ecf: { // 0x431ecf: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L00431ed1: { // 0x431ed1: 7f6f JG 0x00431f42
    if(integer::condition("JG",flags)) goto L00431f42;
  }
  L00431ed3: { // 0x431ed3: 8b4204 MOV EAX,dword ptr [EDX + 0x4]
    s.ax = m.r32((s.dx+0x00000004u));
  }
  L00431ed6: { // 0x431ed6: 8b710c MOV ESI,dword ptr [ECX + 0xc]
    s.si = m.r32((s.cx+0x0000000cu));
  }
  L00431ed9: { // 0x431ed9: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L00431edb: { // 0x431edb: 7f65 JG 0x00431f42
    if(integer::condition("JG",flags)) goto L00431f42;
  }
  L00431edd: { // 0x431edd: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00431edf: { // 0x431edf: 8b7208 MOV ESI,dword ptr [EDX + 0x8]
    s.si = m.r32((s.dx+0x00000008u));
  }
  L00431ee2: { // 0x431ee2: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L00431ee4: { // 0x431ee4: 7f5c JG 0x00431f42
    if(integer::condition("JG",flags)) goto L00431f42;
  }
  L00431ee6: { // 0x431ee6: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L00431ee8: { // 0x431ee8: 8b7108 MOV ESI,dword ptr [ECX + 0x8]
    s.si = m.r32((s.cx+0x00000008u));
  }
  L00431eeb: { // 0x431eeb: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L00431eed: { // 0x431eed: 7f53 JG 0x00431f42
    if(integer::condition("JG",flags)) goto L00431f42;
  }
  L00431eef: { // 0x431eef: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L00431ef3: { // 0x431ef3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00431ef4: { // 0x431ef4: 8b39 MOV EDI,dword ptr [ECX]
    s.di = m.r32((s.cx));
  }
  L00431ef6: { // 0x431ef6: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00431ef8: { // 0x431ef8: 893e MOV dword ptr [ESI],EDI
    m.w32((s.si), s.di);
  }
  L00431efa: { // 0x431efa: 8b7904 MOV EDI,dword ptr [ECX + 0x4]
    s.di = m.r32((s.cx+0x00000004u));
  }
  L00431efd: { // 0x431efd: 897e04 MOV dword ptr [ESI + 0x4],EDI
    m.w32((s.si+0x00000004u), s.di);
  }
  L00431f00: { // 0x431f00: 8b7908 MOV EDI,dword ptr [ECX + 0x8]
    s.di = m.r32((s.cx+0x00000008u));
  }
  L00431f03: { // 0x431f03: 897e08 MOV dword ptr [ESI + 0x8],EDI
    m.w32((s.si+0x00000008u), s.di);
  }
  L00431f06: { // 0x431f06: 8b490c MOV ECX,dword ptr [ECX + 0xc]
    s.cx = m.r32((s.cx+0x0000000cu));
  }
  L00431f09: { // 0x431f09: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00431f0a: { // 0x431f0a: 894e0c MOV dword ptr [ESI + 0xc],ECX
    m.w32((s.si+0x0000000cu), s.cx);
  }
  L00431f0d: { // 0x431f0d: 8b4a04 MOV ECX,dword ptr [EDX + 0x4]
    s.cx = m.r32((s.dx+0x00000004u));
  }
  L00431f10: { // 0x431f10: 394804 CMP dword ptr [EAX + 0x4],ECX
    (void)integer::sub(m.r32((s.ax+0x00000004u)),s.cx,32,flags);
  }
  L00431f13: { // 0x431f13: 7d03 JGE 0x00431f18
    if(integer::condition("JGE",flags)) goto L00431f18;
  }
  L00431f15: { // 0x431f15: 894804 MOV dword ptr [EAX + 0x4],ECX
    m.w32((s.ax+0x00000004u), s.cx);
  }
  L00431f18: { // 0x431f18: 8b0a MOV ECX,dword ptr [EDX]
    s.cx = m.r32((s.dx));
  }
  L00431f1a: { // 0x431f1a: 8b30 MOV ESI,dword ptr [EAX]
    s.si = m.r32((s.ax));
  }
  L00431f1c: { // 0x431f1c: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L00431f1e: { // 0x431f1e: 7d02 JGE 0x00431f22
    if(integer::condition("JGE",flags)) goto L00431f22;
  }
  L00431f20: { // 0x431f20: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L00431f22: { // 0x431f22: 8b4a0c MOV ECX,dword ptr [EDX + 0xc]
    s.cx = m.r32((s.dx+0x0000000cu));
  }
  L00431f25: { // 0x431f25: 8b700c MOV ESI,dword ptr [EAX + 0xc]
    s.si = m.r32((s.ax+0x0000000cu));
  }
  L00431f28: { // 0x431f28: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L00431f2a: { // 0x431f2a: 7e03 JLE 0x00431f2f
    if(integer::condition("JLE",flags)) goto L00431f2f;
  }
  L00431f2c: { // 0x431f2c: 89480c MOV dword ptr [EAX + 0xc],ECX
    m.w32((s.ax+0x0000000cu), s.cx);
  }
  L00431f2f: { // 0x431f2f: 8b5208 MOV EDX,dword ptr [EDX + 0x8]
    s.dx = m.r32((s.dx+0x00000008u));
  }
  L00431f32: { // 0x431f32: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L00431f35: { // 0x431f35: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L00431f37: { // 0x431f37: 7e03 JLE 0x00431f3c
    if(integer::condition("JLE",flags)) goto L00431f3c;
  }
  L00431f39: { // 0x431f39: 895008 MOV dword ptr [EAX + 0x8],EDX
    m.w32((s.ax+0x00000008u), s.dx);
  }
  L00431f3c: { // 0x431f3c: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00431f3e: { // 0x431f3e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00431f3f: { // 0x431f3f: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L00431f42: { // 0x431f42: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L00431f46: { // 0x431f46: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  L00431f49: { // 0x431f49: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00431f4a: { // 0x431f4a: c70000000000 MOV dword ptr [EAX],0x0
    m.w32((s.ax), 0x00000000u);
  }
  L00431f50: { // 0x431f50: c7400400000000 MOV dword ptr [EAX + 0x4],0x0
    m.w32((s.ax+0x00000004u), 0x00000000u);
  }
  L00431f57: { // 0x431f57: 894808 MOV dword ptr [EAX + 0x8],ECX
    m.w32((s.ax+0x00000008u), s.cx);
  }
  L00431f5a: { // 0x431f5a: 89480c MOV dword ptr [EAX + 0xc],ECX
    m.w32((s.ax+0x0000000cu), s.cx);
  }
  L00431f5d: { // 0x431f5d: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00431f5f: { // 0x431f5f: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}

void f_00031f70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00431f70: { // 0x431f70: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L00431f73: { // 0x431f73: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00431f74: { // 0x431f74: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00431f75: { // 0x431f75: 8b7c241c MOV EDI,dword ptr [ESP + 0x1c]
    s.di = m.r32((f.sp+0x0000001cu));
  }
  L00431f79: { // 0x431f79: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00431f7b: { // 0x431f7b: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00431f7d: { // 0x431f7d: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00431f7f: { // 0x431f7f: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L00431f81: { // 0x431f81: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00431f82: { // 0x431f82: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00431f83: { // 0x431f83: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00431f85: { // 0x431f85: ff525c CALL dword ptr [EDX + 0x5c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000005cu)),4398984u,op); flags=s.arithmetic_flags;
  }
  L00431f88: { // 0x431f88: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  L00431f8b: { // 0x431f8b: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L00431f8d: { // 0x431f8d: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00431f8f: { // 0x431f8f: ff5074 CALL dword ptr [EAX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000074u)),4398994u,op); flags=s.arithmetic_flags;
  }
  L00431f92: { // 0x431f92: d1e8 SHR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::right);
  }
  L00431f94: { // 0x431f94: 894610 MOV dword ptr [ESI + 0x10],EAX
    m.w32((s.si+0x00000010u), s.ax);
  }
  L00431f97: { // 0x431f97: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L00431f99: { // 0x431f99: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00431f9b: { // 0x431f9b: c744240800000000 MOV dword ptr [ESP + 0x8],0x0
    m.w32((f.sp+0x00000008u), 0x00000000u);
  }
  L00431fa3: { // 0x431fa3: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  L00431fab: { // 0x431fab: ff527c CALL dword ptr [EDX + 0x7c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000007cu)),4399022u,op); flags=s.arithmetic_flags;
  }
  L00431fae: { // 0x431fae: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00431faf: { // 0x431faf: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00431fb1: { // 0x431fb1: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00431fb5: { // 0x431fb5: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L00431fb7: { // 0x431fb7: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),4399037u,op); flags=s.arithmetic_flags;
  }
  L00431fbd: { // 0x431fbd: 8b5638 MOV EDX,dword ptr [ESI + 0x38]
    s.dx = m.r32((s.si+0x00000038u));
  }
  L00431fc0: { // 0x431fc0: 8b7e3c MOV EDI,dword ptr [ESI + 0x3c]
    s.di = m.r32((s.si+0x0000003cu));
  }
  L00431fc3: { // 0x431fc3: 0bd7 OR EDX,EDI
    s.dx = integer::logical((s.dx)|(s.di),32,flags);
  }
  L00431fc5: { // 0x431fc5: 8b7e34 MOV EDI,dword ptr [ESI + 0x34]
    s.di = m.r32((s.si+0x00000034u));
  }
  L00431fc8: { // 0x431fc8: 8d4e30 LEA ECX,[ESI + 0x30]
    s.cx = (s.si+0x00000030u);
  }
  L00431fcb: { // 0x431fcb: 0bd7 OR EDX,EDI
    s.dx = integer::logical((s.dx)|(s.di),32,flags);
  }
  L00431fcd: { // 0x431fcd: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00431fce: { // 0x431fce: 8b39 MOV EDI,dword ptr [ECX]
    s.di = m.r32((s.cx));
  }
  L00431fd0: { // 0x431fd0: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00431fd4: { // 0x431fd4: 0bd7 OR EDX,EDI
    s.dx = integer::logical((s.dx)|(s.di),32,flags);
  }
  L00431fd6: { // 0x431fd6: 751f JNZ 0x00431ff7
    if(integer::condition("JNZ",flags)) goto L00431ff7;
  }
  L00431fd8: { // 0x431fd8: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L00431fdc: { // 0x431fdc: 89463c MOV dword ptr [ESI + 0x3c],EAX
    m.w32((s.si+0x0000003cu), s.ax);
  }
  L00431fdf: { // 0x431fdf: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  L00431fe1: { // 0x431fe1: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L00431fe5: { // 0x431fe5: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00431fe9: { // 0x431fe9: 894e34 MOV dword ptr [ESI + 0x34],ECX
    m.w32((s.si+0x00000034u), s.cx);
  }
  L00431fec: { // 0x431fec: 895638 MOV dword ptr [ESI + 0x38],EDX
    m.w32((s.si+0x00000038u), s.dx);
  }
  L00431fef: { // 0x431fef: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00431ff0: { // 0x431ff0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00431ff1: { // 0x431ff1: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00431ff4: { // 0x431ff4: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00431ff7: { // 0x431ff7: 8d442408 LEA EAX,[ESP + 0x8]
    s.ax = (f.sp+0x00000008u);
  }
  L00431ffb: { // 0x431ffb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00431ffc: { // 0x431ffc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00431ffd: { // 0x431ffd: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00431ffe: { // 0x431ffe: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00432000: { // 0x432000: e8bbfeffff CALL 0x00431ec0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00431ec0u,4399109u,op); flags=s.arithmetic_flags;
  }
  L00432005: { // 0x432005: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00432006: { // 0x432006: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00432007: { // 0x432007: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0043200a: { // 0x43200a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_00032010(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00432010: { // 0x00432010: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00432011: { // 0x00432011: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00432013: { // 0x00432013: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  L00432017: { // 0x00432017: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00432019: { // 0x00432019: ff5060 CALL dword ptr [EAX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000060u)),4399132u,op); flags=s.arithmetic_flags;
  }
  L0043201c: { // 0x0043201c: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0043201e: { // 0x0043201e: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  L00432021: { // 0x00432021: 894610 MOV dword ptr [ESI + 0x10],EAX
    m.w32((s.si+0x00000010u), s.ax);
  }
  L00432024: { // 0x00432024: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00432025: { // 0x00432025: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_00032210(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00432210: { // 0x432210: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00432211: { // 0x432211: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  L00432215: { // 0x432215: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00432216: { // 0x432216: 8b7c2418 MOV EDI,dword ptr [ESP + 0x18]
    s.di = m.r32((f.sp+0x00000018u));
  }
  L0043221a: { // 0x43221a: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0043221c: { // 0x43221c: 7443 JZ 0x00432261
    if(integer::condition("JZ",flags)) goto L00432261;
  }
  L0043221e: { // 0x43221e: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0043221f: { // 0x43221f: 8b5c2414 MOV EBX,dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  L00432223: { // 0x432223: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00432224: { // 0x432224: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00432226: { // 0x432226: e845fdffff CALL 0x00431f70
    s.arithmetic_flags=flags; invoke(m,s,f,0x00431f70u,4399659u,op); flags=s.arithmetic_flags;
  }
  L0043222b: { // 0x43222b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0043222c: { // 0x43222c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0043222e: { // 0x43222e: e85df5ffff CALL 0x00431790
    s.arithmetic_flags=flags; invoke(m,s,f,0x00431790u,4399667u,op); flags=s.arithmetic_flags;
  }
  L00432233: { // 0x432233: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L00432237: { // 0x432237: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L0043223b: { // 0x43223b: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L0043223f: { // 0x43223f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00432240: { // 0x432240: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L00432244: { // 0x432244: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00432245: { // 0x432245: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00432246: { // 0x432246: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00432247: { // 0x432247: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00432248: { // 0x432248: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0043224a: { // 0x43224a: e831f9ffff CALL 0x00431b80
    s.arithmetic_flags=flags; invoke(m,s,f,0x00431b80u,4399695u,op); flags=s.arithmetic_flags;
  }
  L0043224f: { // 0x43224f: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00432250: { // 0x432250: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00432252: { // 0x432252: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00432254: { // 0x432254: e8b7fdffff CALL 0x00432010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00432010u,4399705u,op); flags=s.arithmetic_flags;
  }
  L00432259: { // 0x432259: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0043225b: { // 0x43225b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0043225c: { // 0x43225c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0043225d: { // 0x43225d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0043225e: { // 0x43225e: c21c00 RET 0x1c
    s.arithmetic_flags=flags; finish(m,s,f,28u); return;
  }
  L00432261: { // 0x432261: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L00432263: { // 0x432263: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00432264: { // 0x432264: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00432265: { // 0x432265: c21c00 RET 0x1c
    s.arithmetic_flags=flags; finish(m,s,f,28u); return;
  }
}

void f_00097830(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00497830: { // 0x497830: a1306d8300 MOV EAX,[0x00836d30]
    s.ax = m.r32((0x00836d30u));
  }
  L00497835: { // 0x497835: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_0025ace0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0065ace0: { // 0x65ace0: a110eaa900 MOV EAX,[0x00a9ea10]
    s.ax = m.r32((0x00a9ea10u));
  }
  L0065ace5: { // 0x65ace5: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0065ace6: { // 0x65ace6: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0065ace7: { // 0x65ace7: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0065ace9: { // 0x65ace9: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0065acea: { // 0x65acea: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L0065acec: { // 0x65acec: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0065acee: { // 0x65acee: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0065acf0: { // 0x65acf0: 7e37 JLE 0x0065ad29
    if(integer::condition("JLE",flags)) goto L0065ad29;
  }
  L0065acf2: { // 0x65acf2: a104eaa900 MOV EAX,[0x00a9ea04]
    s.ax = m.r32((0x00a9ea04u));
  }
  L0065acf7: { // 0x65acf7: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  L0065acfa: { // 0x65acfa: 8b8804030000 MOV ECX,dword ptr [EAX + 0x304]
    s.cx = m.r32((s.ax+0x00000304u));
  }
  L0065ad00: { // 0x65ad00: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0065ad01: { // 0x65ad01: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0065ad02: { // 0x65ad02: e8592b1100 CALL 0x0076d860
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d860u,6663431u,op); flags=s.arithmetic_flags;
  }
  L0065ad07: { // 0x65ad07: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0065ad0a: { // 0x65ad0a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0065ad0c: { // 0x65ad0c: a104eaa900 MOV EAX,[0x00a9ea04]
    s.ax = m.r32((0x00a9ea04u));
  }
  L0065ad11: { // 0x65ad11: 750b JNZ 0x0065ad1e
    if(integer::condition("JNZ",flags)) goto L0065ad1e;
  }
  L0065ad13: { // 0x65ad13: 8b14b0 MOV EDX,dword ptr [EAX + ESI*0x4]
    s.dx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  L0065ad16: { // 0x65ad16: 39ba10030000 CMP dword ptr [EDX + 0x310],EDI
    (void)integer::sub(m.r32((s.dx+0x00000310u)),s.di,32,flags);
  }
  L0065ad1c: { // 0x65ad1c: 7411 JZ 0x0065ad2f
    if(integer::condition("JZ",flags)) goto L0065ad2f;
  }
  L0065ad1e: { // 0x65ad1e: 8b0d10eaa900 MOV ECX,dword ptr [0x00a9ea10]
    s.cx = m.r32((0x00a9ea10u));
  }
  L0065ad24: { // 0x65ad24: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0065ad25: { // 0x65ad25: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L0065ad27: { // 0x65ad27: 7cce JL 0x0065acf7
    if(integer::condition("JL",flags)) goto L0065acf7;
  }
  L0065ad29: { // 0x65ad29: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0065ad2a: { // 0x65ad2a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0065ad2b: { // 0x65ad2b: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0065ad2d: { // 0x65ad2d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0065ad2e: { // 0x65ad2e: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0065ad2f: { // 0x65ad2f: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0065ad31: { // 0x65ad31: 7cf6 JL 0x0065ad29
    if(integer::condition("JL",flags)) goto L0065ad29;
  }
  L0065ad33: { // 0x65ad33: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  L0065ad36: { // 0x65ad36: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0065ad37: { // 0x65ad37: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0065ad38: { // 0x65ad38: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0065ad39: { // 0x65ad39: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_0009f0c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0049f0c0: { // 0x49f0c0: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0049f0c4: { // 0x49f0c4: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  L0049f0c7: { // 0x49f0c7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049f0c9: { // 0x49f0c9: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0049f0ca: { // 0x49f0ca: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0049f0cb: { // 0x49f0cb: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0049f0cd: { // 0x49f0cd: 8b4c243c MOV ECX,dword ptr [ESP + 0x3c]
    s.cx = m.r32((f.sp+0x0000003cu));
  }
  L0049f0d1: { // 0x49f0d1: 898a7c010000 MOV dword ptr [EDX + 0x17c],ECX
    m.w32((s.dx+0x0000017cu), s.cx);
  }
  L0049f0d7: { // 0x49f0d7: 750f JNZ 0x0049f0e8
    if(integer::condition("JNZ",flags)) goto L0049f0e8;
  }
  L0049f0d9: { // 0x49f0d9: f7d9 NEG ECX
    s.cx = integer::sub(0u,s.cx,32,flags);
  }
  L0049f0db: { // 0x49f0db: 1bc9 SBB ECX,ECX
    s.cx = integer::sub(s.cx,s.cx,32,flags,flags&integer::CF);
  }
  L0049f0dd: { // 0x49f0dd: 83e110 AND ECX,0x10
    s.cx = integer::logical((s.cx)&(0x00000010u),32,flags);
  }
  L0049f0e0: { // 0x49f0e0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049f0e1: { // 0x49f0e1: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L0049f0e3: { // 0x49f0e3: e89867feff CALL 0x00485880
    s.arithmetic_flags=flags; invoke(m,s,f,0x00485880u,4845800u,op); flags=s.arithmetic_flags;
  }
  L0049f0e8: { // 0x49f0e8: 8b4c2434 MOV ECX,dword ptr [ESP + 0x34]
    s.cx = m.r32((f.sp+0x00000034u));
  }
  L0049f0ec: { // 0x49f0ec: 8b74242c MOV ESI,dword ptr [ESP + 0x2c]
    s.si = m.r32((f.sp+0x0000002cu));
  }
  L0049f0f0: { // 0x49f0f0: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L0049f0f2: { // 0x49f0f2: 8b4904 MOV ECX,dword ptr [ECX + 0x4]
    s.cx = m.r32((s.cx+0x00000004u));
  }
  L0049f0f5: { // 0x49f0f5: 894c240c MOV dword ptr [ESP + 0xc],ECX
    m.w32((f.sp+0x0000000cu), s.cx);
  }
  L0049f0f9: { // 0x49f0f9: 8b4c2430 MOV ECX,dword ptr [ESP + 0x30]
    s.cx = m.r32((f.sp+0x00000030u));
  }
  L0049f0fd: { // 0x49f0fd: 89542408 MOV dword ptr [ESP + 0x8],EDX
    m.w32((f.sp+0x00000008u), s.dx);
  }
  L0049f101: { // 0x49f101: 8b5108 MOV EDX,dword ptr [ECX + 0x8]
    s.dx = m.r32((s.cx+0x00000008u));
  }
  L0049f104: { // 0x49f104: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L0049f108: { // 0x49f108: 8b510c MOV EDX,dword ptr [ECX + 0xc]
    s.dx = m.r32((s.cx+0x0000000cu));
  }
  L0049f10b: { // 0x49f10b: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L0049f10f: { // 0x49f10f: 8b542450 MOV EDX,dword ptr [ESP + 0x50]
    s.dx = m.r32((f.sp+0x00000050u));
  }
  L0049f113: { // 0x49f113: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049f114: { // 0x49f114: 8b542450 MOV EDX,dword ptr [ESP + 0x50]
    s.dx = m.r32((f.sp+0x00000050u));
  }
  L0049f118: { // 0x49f118: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049f119: { // 0x49f119: 8b542450 MOV EDX,dword ptr [ESP + 0x50]
    s.dx = m.r32((f.sp+0x00000050u));
  }
  L0049f11d: { // 0x49f11d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049f11e: { // 0x49f11e: 8b542450 MOV EDX,dword ptr [ESP + 0x50]
    s.dx = m.r32((f.sp+0x00000050u));
  }
  L0049f122: { // 0x49f122: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049f123: { // 0x49f123: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049f124: { // 0x49f124: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0049f126: { // 0x49f126: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049f127: { // 0x49f127: 8d4c2430 LEA ECX,[ESP + 0x30]
    s.cx = (f.sp+0x00000030u);
  }
  L0049f12b: { // 0x49f12b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049f12c: { // 0x49f12c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0049f12e: { // 0x49f12e: ff5078 CALL dword ptr [EAX + 0x78]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000078u)),4845873u,op); flags=s.arithmetic_flags;
  }
  L0049f131: { // 0x49f131: 8d542420 LEA EDX,[ESP + 0x20]
    s.dx = (f.sp+0x00000020u);
  }
  L0049f135: { // 0x49f135: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0049f137: { // 0x49f137: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049f138: { // 0x49f138: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0049f139: { // 0x49f139: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049f13a: { // 0x49f13a: 8b54245c MOV EDX,dword ptr [ESP + 0x5c]
    s.dx = m.r32((f.sp+0x0000005cu));
  }
  L0049f13e: { // 0x49f13e: e8bd58f9ff CALL 0x00434a00
    s.arithmetic_flags=flags; invoke(m,s,f,0x00434a00u,4845891u,op); flags=s.arithmetic_flags;
  }
  L0049f143: { // 0x49f143: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0049f144: { // 0x49f144: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049f145: { // 0x49f145: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L0049f148: { // 0x49f148: c22800 RET 0x28
    s.arithmetic_flags=flags; finish(m,s,f,40u); return;
  }
}

void f_000fe550(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004fe550: { // 0x4fe550: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  L004fe553: { // 0x4fe553: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004fe555: { // 0x4fe555: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004fe556: { // 0x4fe556: 8a4102 MOV AL,byte ptr [ECX + 0x2]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000002u)));
  }
  L004fe559: { // 0x4fe559: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004fe55a: { // 0x4fe55a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004fe55b: { // 0x4fe55b: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L004fe55d: { // 0x4fe55d: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004fe55f: { // 0x4fe55f: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L004fe561: { // 0x4fe561: 8a01 MOV AL,byte ptr [ECX]
    s.ax = with_al(s.ax, m.r8((s.cx)));
  }
  L004fe563: { // 0x4fe563: 8a5901 MOV BL,byte ptr [ECX + 0x1]
    s.bx = with_al(s.bx, m.r8((s.cx+0x00000001u)));
  }
  L004fe566: { // 0x4fe566: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004fe567: { // 0x4fe567: bfff000000 MOV EDI,0xff
    s.di = 0x000000ffu;
  }
  L004fe56c: { // 0x4fe56c: 8d0c40 LEA ECX,[EAX + EAX*0x2]
    s.cx = (s.ax+(s.ax * 0x00000002u));
  }
  L004fe56f: { // 0x4fe56f: 8974241c MOV dword ptr [ESP + 0x1c],ESI
    m.w32((f.sp+0x0000001cu), s.si);
  }
  L004fe573: { // 0x4fe573: d1e1 SHL ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::left);
  }
  L004fe575: { // 0x4fe575: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004fe577: { // 0x4fe577: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L004fe57b: { // 0x4fe57b: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004fe57c: { // 0x4fe57c: f7ff IDIV EDI
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.di,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L004fe57e: { // 0x4fe57e: b881808080 MOV EAX,0x80808081
    s.ax = 0x80808081u;
  }
  L004fe583: { // 0x4fe583: 8bea MOV EBP,EDX
    s.bp = s.dx;
  }
  L004fe585: { // 0x4fe585: 0fafd3 IMUL EDX,EBX
    s.dx = integer::imul(s.dx,s.bx,32,flags);
  }
  L004fe588: { // 0x4fe588: f7e2 MUL EDX
    const auto product=std::uint64_t(s.ax)*std::uint64_t(s.dx);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(product>>32);
    flags=(flags&~(integer::CF|integer::OF))|(s.dx?integer::CF|integer::OF:0);
  }
  L004fe58a: { // 0x4fe58a: c1ea07 SHR EDX,0x7
    s.dx = integer::shift(s.dx,0x00000007u,32,flags,integer::Shift::right);
  }
  L004fe58d: { // 0x4fe58d: 2bfa SUB EDI,EDX
    s.di = integer::sub(s.di,s.dx,32,flags);
  }
  L004fe58f: { // 0x4fe58f: b881808080 MOV EAX,0x80808081
    s.ax = 0x80808081u;
  }
  L004fe594: { // 0x4fe594: 0faffe IMUL EDI,ESI
    s.di = integer::imul(s.di,s.si,32,flags);
  }
  L004fe597: { // 0x4fe597: f7e7 MUL EDI
    const auto product=std::uint64_t(s.ax)*std::uint64_t(s.di);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(product>>32);
    flags=(flags&~(integer::CF|integer::OF))|(s.dx?integer::CF|integer::OF:0);
  }
  L004fe599: { // 0x4fe599: bfff000000 MOV EDI,0xff
    s.di = 0x000000ffu;
  }
  L004fe59e: { // 0x4fe59e: b881808080 MOV EAX,0x80808081
    s.ax = 0x80808081u;
  }
  L004fe5a3: { // 0x4fe5a3: 2bfb SUB EDI,EBX
    s.di = integer::sub(s.di,s.bx,32,flags);
  }
  L004fe5a5: { // 0x4fe5a5: 0faffe IMUL EDI,ESI
    s.di = integer::imul(s.di,s.si,32,flags);
  }
  L004fe5a8: { // 0x4fe5a8: c1ea07 SHR EDX,0x7
    s.dx = integer::shift(s.dx,0x00000007u,32,flags,integer::Shift::right);
  }
  L004fe5ab: { // 0x4fe5ab: 89542420 MOV dword ptr [ESP + 0x20],EDX
    m.w32((f.sp+0x00000020u), s.dx);
  }
  L004fe5af: { // 0x4fe5af: f7ef IMUL EDI
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.di,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  L004fe5b1: { // 0x4fe5b1: 03d7 ADD EDX,EDI
    s.dx = integer::add(s.dx,s.di,32,flags);
  }
  L004fe5b3: { // 0x4fe5b3: bfff000000 MOV EDI,0xff
    s.di = 0x000000ffu;
  }
  L004fe5b8: { // 0x4fe5b8: c1fa07 SAR EDX,0x7
    s.dx = integer::shift(s.dx,0x00000007u,32,flags,integer::Shift::arithmetic_right);
  }
  L004fe5bb: { // 0x4fe5bb: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L004fe5bd: { // 0x4fe5bd: c1e81f SHR EAX,0x1f
    s.ax = integer::shift(s.ax,0x0000001fu,32,flags,integer::Shift::right);
  }
  L004fe5c0: { // 0x4fe5c0: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L004fe5c2: { // 0x4fe5c2: b881808080 MOV EAX,0x80808081
    s.ax = 0x80808081u;
  }
  L004fe5c7: { // 0x4fe5c7: 89542428 MOV dword ptr [ESP + 0x28],EDX
    m.w32((f.sp+0x00000028u), s.dx);
  }
  L004fe5cb: { // 0x4fe5cb: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L004fe5cf: { // 0x4fe5cf: baff000000 MOV EDX,0xff
    s.dx = 0x000000ffu;
  }
  L004fe5d4: { // 0x4fe5d4: 2bd5 SUB EDX,EBP
    s.dx = integer::sub(s.dx,s.bp,32,flags);
  }
  L004fe5d6: { // 0x4fe5d6: 0fafd3 IMUL EDX,EBX
    s.dx = integer::imul(s.dx,s.bx,32,flags);
  }
  L004fe5d9: { // 0x4fe5d9: f7e2 MUL EDX
    const auto product=std::uint64_t(s.ax)*std::uint64_t(s.dx);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(product>>32);
    flags=(flags&~(integer::CF|integer::OF))|(s.dx?integer::CF|integer::OF:0);
  }
  L004fe5db: { // 0x4fe5db: c1ea07 SHR EDX,0x7
    s.dx = integer::shift(s.dx,0x00000007u,32,flags,integer::Shift::right);
  }
  L004fe5de: { // 0x4fe5de: 2bfa SUB EDI,EDX
    s.di = integer::sub(s.di,s.dx,32,flags);
  }
  L004fe5e0: { // 0x4fe5e0: b881808080 MOV EAX,0x80808081
    s.ax = 0x80808081u;
  }
  L004fe5e5: { // 0x4fe5e5: 0faffe IMUL EDI,ESI
    s.di = integer::imul(s.di,s.si,32,flags);
  }
  L004fe5e8: { // 0x4fe5e8: f7e7 MUL EDI
    const auto product=std::uint64_t(s.ax)*std::uint64_t(s.di);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(product>>32);
    flags=(flags&~(integer::CF|integer::OF))|(s.dx?integer::CF|integer::OF:0);
  }
  L004fe5ea: { // 0x4fe5ea: c1ea07 SHR EDX,0x7
    s.dx = integer::shift(s.dx,0x00000007u,32,flags,integer::Shift::right);
  }
  L004fe5ed: { // 0x4fe5ed: b881808080 MOV EAX,0x80808081
    s.ax = 0x80808081u;
  }
  L004fe5f2: { // 0x4fe5f2: 8954242c MOV dword ptr [ESP + 0x2c],EDX
    m.w32((f.sp+0x0000002cu), s.dx);
  }
  L004fe5f6: { // 0x4fe5f6: f7e9 IMUL ECX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.cx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  L004fe5f8: { // 0x4fe5f8: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L004fe5fa: { // 0x4fe5fa: ba04000000 MOV EDX,0x4
    s.dx = 0x00000004u;
  }
  L004fe5ff: { // 0x4fe5ff: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L004fe601: { // 0x4fe601: c1f807 SAR EAX,0x7
    s.ax = integer::shift(s.ax,0x00000007u,32,flags,integer::Shift::arithmetic_right);
  }
  L004fe604: { // 0x4fe604: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L004fe606: { // 0x4fe606: c1e91f SHR ECX,0x1f
    s.cx = integer::shift(s.cx,0x0000001fu,32,flags,integer::Shift::right);
  }
  L004fe609: { // 0x4fe609: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L004fe60b: { // 0x4fe60b: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L004fe60d: { // 0x4fe60d: 1bc9 SBB ECX,ECX
    s.cx = integer::sub(s.cx,s.cx,32,flags,flags&integer::CF);
  }
  L004fe60f: { // 0x4fe60f: 83e1fa AND ECX,0xfffffffa
    s.cx = integer::logical((s.cx)&(0xfffffffau),32,flags);
  }
  L004fe612: { // 0x4fe612: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L004fe615: { // 0x4fe615: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L004fe617: { // 0x4fe617: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L004fe619: { // 0x4fe619: 8b4c8414 MOV ECX,dword ptr [ESP + EAX*0x4 + 0x14]
    s.cx = m.r32((f.sp+(s.ax * 0x00000004u)+0x00000014u));
  }
  L004fe61d: { // 0x4fe61d: 1bd2 SBB EDX,EDX
    s.dx = integer::sub(s.dx,s.dx,32,flags,flags&integer::CF);
  }
  L004fe61f: { // 0x4fe61f: 884c2410 MOV byte ptr [ESP + 0x10],CL
    m.w8((f.sp+0x00000010u), (s.cx & 0xffu));
  }
  L004fe623: { // 0x4fe623: 83e2fa AND EDX,0xfffffffa
    s.dx = integer::logical((s.dx)&(0xfffffffau),32,flags);
  }
  L004fe626: { // 0x4fe626: b904000000 MOV ECX,0x4
    s.cx = 0x00000004u;
  }
  L004fe62b: { // 0x4fe62b: 83c202 ADD EDX,0x2
    s.dx = integer::add(s.dx,0x00000002u,32,flags);
  }
  L004fe62e: { // 0x4fe62e: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004fe630: { // 0x4fe630: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L004fe632: { // 0x4fe632: 1bd2 SBB EDX,EDX
    s.dx = integer::sub(s.dx,s.dx,32,flags,flags&integer::CF);
  }
  L004fe634: { // 0x4fe634: 83e2fa AND EDX,0xfffffffa
    s.dx = integer::logical((s.dx)&(0xfffffffau),32,flags);
  }
  L004fe637: { // 0x4fe637: 83c202 ADD EDX,0x2
    s.dx = integer::add(s.dx,0x00000002u,32,flags);
  }
  L004fe63a: { // 0x4fe63a: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L004fe63c: { // 0x4fe63c: 8a448414 MOV AL,byte ptr [ESP + EAX*0x4 + 0x14]
    s.ax = with_al(s.ax, m.r8((f.sp+(s.ax * 0x00000004u)+0x00000014u)));
  }
  L004fe640: { // 0x4fe640: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004fe641: { // 0x4fe641: 8a4c9410 MOV CL,byte ptr [ESP + EDX*0x4 + 0x10]
    s.cx = with_al(s.cx, m.r8((f.sp+(s.dx * 0x00000004u)+0x00000010u)));
  }
  L004fe645: { // 0x4fe645: 884c240d MOV byte ptr [ESP + 0xd],CL
    m.w8((f.sp+0x0000000du), (s.cx & 0xffu));
  }
  L004fe649: { // 0x4fe649: 8b4c2430 MOV ECX,dword ptr [ESP + 0x30]
    s.cx = m.r32((f.sp+0x00000030u));
  }
  L004fe64d: { // 0x4fe64d: 668b74240c MOV SI,word ptr [ESP + 0xc]
    s.si = (s.si & 0xffff0000u) | ((m.r16((f.sp+0x0000000cu))) & 0xffffu);
  }
  L004fe652: { // 0x4fe652: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L004fe654: { // 0x4fe654: 668932 MOV word ptr [EDX],SI
    m.w16((s.dx), (s.si & 0xffffu));
  }
  L004fe657: { // 0x4fe657: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004fe658: { // 0x4fe658: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004fe659: { // 0x4fe659: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004fe65a: { // 0x4fe65a: 884202 MOV byte ptr [EDX + 0x2],AL
    m.w8((s.dx+0x00000002u), (s.ax & 0xffu));
  }
  L004fe65d: { // 0x4fe65d: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004fe65f: { // 0x4fe65f: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L004fe662: { // 0x4fe662: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_00034a00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00434a00: { // 0x434a00: 83ec48 SUB ESP,0x48
    f.sp = integer::sub(f.sp,0x00000048u,32,flags);
  }
  L00434a03: { // 0x434a03: 8b442458 MOV EAX,dword ptr [ESP + 0x58]
    s.ax = m.r32((f.sp+0x00000058u));
  }
  L00434a07: { // 0x434a07: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00434a08: { // 0x434a08: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00434a09: { // 0x434a09: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00434a0a: { // 0x434a0a: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L00434a0c: { // 0x434a0c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00434a0d: { // 0x434a0d: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00434a0f: { // 0x434a0f: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00434a11: { // 0x434a11: 89542448 MOV dword ptr [ESP + 0x48],EDX
    m.w32((f.sp+0x00000048u), s.dx);
  }
  L00434a15: { // 0x434a15: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00434a17: { // 0x434a17: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L00434a1a: { // 0x434a1a: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L00434a1e: { // 0x434a1e: 8954244c MOV dword ptr [ESP + 0x4c],EDX
    m.w32((f.sp+0x0000004cu), s.dx);
  }
  L00434a22: { // 0x434a22: c644246800 MOV byte ptr [ESP + 0x68],0x0
    m.w8((f.sp+0x00000068u), 0x00000000u);
  }
  L00434a27: { // 0x434a27: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L00434a2a: { // 0x434a2a: 897c2410 MOV dword ptr [ESP + 0x10],EDI
    m.w32((f.sp+0x00000010u), s.di);
  }
  L00434a2e: { // 0x434a2e: 89542450 MOV dword ptr [ESP + 0x50],EDX
    m.w32((f.sp+0x00000050u), s.dx);
  }
  L00434a32: { // 0x434a32: 8b54245c MOV EDX,dword ptr [ESP + 0x5c]
    s.dx = m.r32((f.sp+0x0000005cu));
  }
  L00434a36: { // 0x434a36: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L00434a39: { // 0x434a39: 897c245c MOV dword ptr [ESP + 0x5c],EDI
    m.w32((f.sp+0x0000005cu), s.di);
  }
  L00434a3d: { // 0x434a3d: 89442454 MOV dword ptr [ESP + 0x54],EAX
    m.w32((f.sp+0x00000054u), s.ax);
  }
  L00434a41: { // 0x434a41: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L00434a43: { // 0x434a43: 89442438 MOV dword ptr [ESP + 0x38],EAX
    m.w32((f.sp+0x00000038u), s.ax);
  }
  L00434a47: { // 0x434a47: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L00434a49: { // 0x434a49: 8b4204 MOV EAX,dword ptr [EDX + 0x4]
    s.ax = m.r32((s.dx+0x00000004u));
  }
  L00434a4c: { // 0x434a4c: 897c2414 MOV dword ptr [ESP + 0x14],EDI
    m.w32((f.sp+0x00000014u), s.di);
  }
  L00434a50: { // 0x434a50: 8944243c MOV dword ptr [ESP + 0x3c],EAX
    m.w32((f.sp+0x0000003cu), s.ax);
  }
  L00434a54: { // 0x434a54: 897c2420 MOV dword ptr [ESP + 0x20],EDI
    m.w32((f.sp+0x00000020u), s.di);
  }
  L00434a58: { // 0x434a58: 8b4208 MOV EAX,dword ptr [EDX + 0x8]
    s.ax = m.r32((s.dx+0x00000008u));
  }
  L00434a5b: { // 0x434a5b: 897c2424 MOV dword ptr [ESP + 0x24],EDI
    m.w32((f.sp+0x00000024u), s.di);
  }
  L00434a5f: { // 0x434a5f: 89442440 MOV dword ptr [ESP + 0x40],EAX
    m.w32((f.sp+0x00000040u), s.ax);
  }
  L00434a63: { // 0x434a63: 8b442474 MOV EAX,dword ptr [ESP + 0x74]
    s.ax = m.r32((f.sp+0x00000074u));
  }
  L00434a67: { // 0x434a67: 8b520c MOV EDX,dword ptr [EDX + 0xc]
    s.dx = m.r32((s.dx+0x0000000cu));
  }
  L00434a6a: { // 0x434a6a: 895c2430 MOV dword ptr [ESP + 0x30],EBX
    m.w32((f.sp+0x00000030u), s.bx);
  }
  L00434a6e: { // 0x434a6e: 8d0440 LEA EAX,[EAX + EAX*0x2]
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  L00434a71: { // 0x434a71: 89542444 MOV dword ptr [ESP + 0x44],EDX
    m.w32((f.sp+0x00000044u), s.dx);
  }
  L00434a75: { // 0x434a75: 897c242c MOV dword ptr [ESP + 0x2c],EDI
    m.w32((f.sp+0x0000002cu), s.di);
  }
  L00434a79: { // 0x434a79: 897c2428 MOV dword ptr [ESP + 0x28],EDI
    m.w32((f.sp+0x00000028u), s.di);
  }
  L00434a7d: { // 0x434a7d: 8d14c5f8907b00 LEA EDX,[EAX*0x8 + 0x7b90f8]
    s.dx = ((s.ax * 0x00000008u)+0x007b90f8u);
  }
  L00434a84: { // 0x434a84: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L00434a88: { // 0x434a88: 89542474 MOV dword ptr [ESP + 0x74],EDX
    m.w32((f.sp+0x00000074u), s.dx);
  }
  L00434a8c: { // 0x434a8c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00434a8d: { // 0x434a8d: 8d542460 LEA EDX,[ESP + 0x60]
    s.dx = (f.sp+0x00000060u);
  }
  L00434a91: { // 0x434a91: 8d44246c LEA EAX,[ESP + 0x6c]
    s.ax = (f.sp+0x0000006cu);
  }
  L00434a95: { // 0x434a95: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00434a96: { // 0x434a96: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00434a97: { // 0x434a97: 8b442470 MOV EAX,dword ptr [ESP + 0x70]
    s.ax = m.r32((f.sp+0x00000070u));
  }
  L00434a9b: { // 0x434a9b: 8d542454 LEA EDX,[ESP + 0x54]
    s.dx = (f.sp+0x00000054u);
  }
  L00434a9f: { // 0x434a9f: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00434aa0: { // 0x434aa0: 8b542470 MOV EDX,dword ptr [ESP + 0x70]
    s.dx = m.r32((f.sp+0x00000070u));
  }
  L00434aa4: { // 0x434aa4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00434aa5: { // 0x434aa5: 8d44244c LEA EAX,[ESP + 0x4c]
    s.ax = (f.sp+0x0000004cu);
  }
  L00434aa9: { // 0x434aa9: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00434aaa: { // 0x434aaa: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00434aab: { // 0x434aab: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L00434aad: { // 0x434aad: e83ec23200 CALL 0x00760cf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00760cf0u,4410034u,op); flags=s.arithmetic_flags;
  }
  L00434ab2: { // 0x434ab2: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00434ab4: { // 0x434ab4: 750a JNZ 0x00434ac0
    if(integer::condition("JNZ",flags)) goto L00434ac0;
  }
  L00434ab6: { // 0x434ab6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00434ab7: { // 0x434ab7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00434ab8: { // 0x434ab8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00434ab9: { // 0x434ab9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00434aba: { // 0x434aba: 83c448 ADD ESP,0x48
    f.sp = integer::add(f.sp,0x00000048u,32,flags);
  }
  L00434abd: { // 0x434abd: c22400 RET 0x24
    s.arithmetic_flags=flags; finish(m,s,f,36u); return;
  }
  L00434ac0: { // 0x434ac0: 8b0df4988100 MOV ECX,dword ptr [0x008198f4]
    s.cx = m.r32((0x008198f4u));
  }
  L00434ac6: { // 0x434ac6: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00434ac8: { // 0x434ac8: 7429 JZ 0x00434af3
    if(integer::condition("JZ",flags)) goto L00434af3;
  }
  L00434aca: { // 0x434aca: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00434acc: { // 0x434acc: 8b5c2438 MOV EBX,dword ptr [ESP + 0x38]
    s.bx = m.r32((f.sp+0x00000038u));
  }
  L00434ad0: { // 0x434ad0: 8b44243c MOV EAX,dword ptr [ESP + 0x3c]
    s.ax = m.r32((f.sp+0x0000003cu));
  }
  L00434ad4: { // 0x434ad4: 03da ADD EBX,EDX
    s.bx = integer::add(s.bx,s.dx,32,flags);
  }
  L00434ad6: { // 0x434ad6: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  L00434ad9: { // 0x434ad9: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00434adb: { // 0x434adb: 8b5104 MOV EDX,dword ptr [ECX + 0x4]
    s.dx = m.r32((s.cx+0x00000004u));
  }
  L00434ade: { // 0x434ade: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00434ae2: { // 0x434ae2: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00434ae4: { // 0x434ae4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00434ae5: { // 0x434ae5: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00434ae6: { // 0x434ae6: e845c7fdff CALL 0x00411230
    s.arithmetic_flags=flags; invoke(m,s,f,0x00411230u,4410091u,op); flags=s.arithmetic_flags;
  }
  L00434aeb: { // 0x434aeb: 8b5c2430 MOV EBX,dword ptr [ESP + 0x30]
    s.bx = m.r32((f.sp+0x00000030u));
  }
  L00434aef: { // 0x434aef: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00434af3: { // 0x434af3: 8b0dac1f8200 MOV ECX,dword ptr [0x00821fac]
    s.cx = m.r32((0x00821facu));
  }
  L00434af9: { // 0x434af9: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00434afb: { // 0x434afb: 0f84c6000000 JZ 0x00434bc7
    if(integer::condition("JZ",flags)) goto L00434bc7;
  }
  L00434b01: { // 0x434b01: 8b44243c MOV EAX,dword ptr [ESP + 0x3c]
    s.ax = m.r32((f.sp+0x0000003cu));
  }
  L00434b05: { // 0x434b05: 8b7e04 MOV EDI,dword ptr [ESI + 0x4]
    s.di = m.r32((s.si+0x00000004u));
  }
  L00434b08: { // 0x434b08: 8b6904 MOV EBP,dword ptr [ECX + 0x4]
    s.bp = m.r32((s.cx+0x00000004u));
  }
  L00434b0b: { // 0x434b0b: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00434b0d: { // 0x434b0d: 8b5c2438 MOV EBX,dword ptr [ESP + 0x38]
    s.bx = m.r32((f.sp+0x00000038u));
  }
  L00434b11: { // 0x434b11: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L00434b13: { // 0x434b13: 89442434 MOV dword ptr [ESP + 0x34],EAX
    m.w32((f.sp+0x00000034u), s.ax);
  }
  L00434b17: { // 0x434b17: 2bc5 SUB EAX,EBP
    s.ax = integer::sub(s.ax,s.bp,32,flags);
  }
  L00434b19: { // 0x434b19: 03d3 ADD EDX,EBX
    s.dx = integer::add(s.dx,s.bx,32,flags);
  }
  L00434b1b: { // 0x434b1b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00434b1c: { // 0x434b1c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00434b1d: { // 0x434b1d: e85ed13200 CALL 0x00761c80
    s.arithmetic_flags=flags; invoke(m,s,f,0x00761c80u,4410146u,op); flags=s.arithmetic_flags;
  }
  L00434b22: { // 0x434b22: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L00434b24: { // 0x434b24: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00434b26: { // 0x434b26: 8b7c2474 MOV EDI,dword ptr [ESP + 0x74]
    s.di = m.r32((f.sp+0x00000074u));
  }
  L00434b2a: { // 0x434b2a: 8b470c MOV EAX,dword ptr [EDI + 0xc]
    s.ax = m.r32((s.di+0x0000000cu));
  }
  L00434b2d: { // 0x434b2d: 8b4f08 MOV ECX,dword ptr [EDI + 0x8]
    s.cx = m.r32((s.di+0x00000008u));
  }
  L00434b30: { // 0x434b30: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L00434b34: { // 0x434b34: 894c242c MOV dword ptr [ESP + 0x2c],ECX
    m.w32((f.sp+0x0000002cu), s.cx);
  }
  L00434b38: { // 0x434b38: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00434b39: { // 0x434b39: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00434b3b: { // 0x434b3b: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00434b3d: { // 0x434b3d: 8a4714 MOV AL,byte ptr [EDI + 0x14]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000014u)));
  }
  L00434b40: { // 0x434b40: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00434b42: { // 0x434b42: 7430 JZ 0x00434b74
    if(integer::condition("JZ",flags)) goto L00434b74;
  }
  L00434b44: { // 0x434b44: 8b15ac1f8200 MOV EDX,dword ptr [0x00821fac]
    s.dx = m.r32((0x00821facu));
  }
  L00434b4a: { // 0x434b4a: 8b4f04 MOV ECX,dword ptr [EDI + 0x4]
    s.cx = m.r32((s.di+0x00000004u));
  }
  L00434b4d: { // 0x434b4d: 668b4224 MOV AX,word ptr [EDX + 0x24]
    s.ax = with_ax(s.ax, m.r16((s.dx+0x00000024u)));
  }
  L00434b51: { // 0x434b51: 66034204 ADD AX,word ptr [EDX + 0x4]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((s.dx+0x00000004u)),16,flags));
  }
  L00434b55: { // 0x434b55: 8b54243c MOV EDX,dword ptr [ESP + 0x3c]
    s.dx = m.r32((f.sp+0x0000003cu));
  }
  L00434b59: { // 0x434b59: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00434b5b: { // 0x434b5b: 8b542470 MOV EDX,dword ptr [ESP + 0x70]
    s.dx = m.r32((f.sp+0x00000070u));
  }
  L00434b5f: { // 0x434b5f: 662b4604 SUB AX,word ptr [ESI + 0x4]
    s.ax = with_ax(s.ax, integer::sub((s.ax & 0xffffu),m.r16((s.si+0x00000004u)),16,flags));
  }
  L00434b63: { // 0x434b63: 25ffff0000 AND EAX,0xffff
    s.ax = integer::logical((s.ax)&(0x0000ffffu),32,flags);
  }
  L00434b68: { // 0x434b68: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00434b6a: { // 0x434b6a: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00434b6b: { // 0x434b6b: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00434b6d: { // 0x434b6d: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00434b6f: { // 0x434b6f: 0faff9 IMUL EDI,ECX
    s.di = integer::imul(s.di,s.cx,32,flags);
  }
  L00434b72: { // 0x434b72: eb53 JMP 0x00434bc7
    goto L00434bc7;
  }
  L00434b74: { // 0x434b74: 8b15ac1f8200 MOV EDX,dword ptr [0x00821fac]
    s.dx = m.r32((0x00821facu));
  }
  L00434b7a: { // 0x434b7a: 8b5c2444 MOV EBX,dword ptr [ESP + 0x44]
    s.bx = m.r32((f.sp+0x00000044u));
  }
  L00434b7e: { // 0x434b7e: 668b4224 MOV AX,word ptr [EDX + 0x24]
    s.ax = with_ax(s.ax, m.r16((s.dx+0x00000024u)));
  }
  L00434b82: { // 0x434b82: 66034204 ADD AX,word ptr [EDX + 0x4]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((s.dx+0x00000004u)),16,flags));
  }
  L00434b86: { // 0x434b86: 8b54243c MOV EDX,dword ptr [ESP + 0x3c]
    s.dx = m.r32((f.sp+0x0000003cu));
  }
  L00434b8a: { // 0x434b8a: 2bc3 SUB EAX,EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L00434b8c: { // 0x434b8c: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00434b8e: { // 0x434b8e: 662b4604 SUB AX,word ptr [ESI + 0x4]
    s.ax = with_ax(s.ax, integer::sub((s.ax & 0xffffu),m.r16((s.si+0x00000004u)),16,flags));
  }
  L00434b92: { // 0x434b92: 8b742470 MOV ESI,dword ptr [ESP + 0x70]
    s.si = m.r32((f.sp+0x00000070u));
  }
  L00434b96: { // 0x434b96: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00434b97: { // 0x434b97: 25ffff0000 AND EAX,0xffff
    s.ax = integer::logical((s.ax)&(0x0000ffffu),32,flags);
  }
  L00434b9c: { // 0x434b9c: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L00434b9e: { // 0x434b9e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00434b9f: { // 0x434b9f: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00434ba1: { // 0x434ba1: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00434ba3: { // 0x434ba3: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L00434ba5: { // 0x434ba5: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00434ba6: { // 0x434ba6: 0faff9 IMUL EDI,ECX
    s.di = integer::imul(s.di,s.cx,32,flags);
  }
  L00434ba9: { // 0x434ba9: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00434bab: { // 0x434bab: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L00434bad: { // 0x434bad: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L00434baf: { // 0x434baf: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00434bb0: { // 0x434bb0: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00434bb2: { // 0x434bb2: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L00434bb6: { // 0x434bb6: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00434bb8: { // 0x434bb8: 2bda SUB EBX,EDX
    s.bx = integer::sub(s.bx,s.dx,32,flags);
  }
  L00434bba: { // 0x434bba: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L00434bbc: { // 0x434bbc: 7509 JNZ 0x00434bc7
    if(integer::condition("JNZ",flags)) goto L00434bc7;
  }
  L00434bbe: { // 0x434bbe: 8b4c2474 MOV ECX,dword ptr [ESP + 0x74]
    s.cx = m.r32((f.sp+0x00000074u));
  }
  L00434bc2: { // 0x434bc2: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00434bc4: { // 0x434bc4: 037910 ADD EDI,dword ptr [ECX + 0x10]
    s.di = integer::add(s.di,m.r32((s.cx+0x00000010u)),32,flags);
  }
  L00434bc7: { // 0x434bc7: 8b74241c MOV ESI,dword ptr [ESP + 0x1c]
    s.si = m.r32((f.sp+0x0000001cu));
  }
  L00434bcb: { // 0x434bcb: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00434bcd: { // 0x434bcd: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00434bcf: { // 0x434bcf: ff5270 CALL dword ptr [EDX + 0x70]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000070u)),4410322u,op); flags=s.arithmetic_flags;
  }
  L00434bd2: { // 0x434bd2: 0faf442440 IMUL EAX,dword ptr [ESP + 0x40]
    s.ax = integer::imul(s.ax,m.r32((f.sp+0x00000040u)),32,flags);
  }
  L00434bd7: { // 0x434bd7: 89442470 MOV dword ptr [ESP + 0x70],EAX
    m.w32((f.sp+0x00000070u), s.ax);
  }
  L00434bdb: { // 0x434bdb: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00434bdd: { // 0x434bdd: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00434bdf: { // 0x434bdf: ff5074 CALL dword ptr [EAX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000074u)),4410338u,op); flags=s.arithmetic_flags;
  }
  L00434be2: { // 0x434be2: 39442470 CMP dword ptr [ESP + 0x70],EAX
    (void)integer::sub(m.r32((f.sp+0x00000070u)),s.ax,32,flags);
  }
  L00434be6: { // 0x434be6: 757e JNZ 0x00434c66
    if(integer::condition("JNZ",flags)) goto L00434c66;
  }
  L00434be8: { // 0x434be8: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00434bea: { // 0x434bea: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00434bec: { // 0x434bec: ff5274 CALL dword ptr [EDX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000074u)),4410351u,op); flags=s.arithmetic_flags;
  }
  L00434bef: { // 0x434bef: 8b4c2460 MOV ECX,dword ptr [ESP + 0x60]
    s.cx = m.r32((f.sp+0x00000060u));
  }
  L00434bf3: { // 0x434bf3: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00434bf5: { // 0x434bf5: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00434bf7: { // 0x434bf7: ff5074 CALL dword ptr [EAX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000074u)),4410362u,op); flags=s.arithmetic_flags;
  }
  L00434bfa: { // 0x434bfa: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L00434bfc: { // 0x434bfc: 7564 JNZ 0x00434c62
    if(integer::condition("JNZ",flags)) goto L00434c62;
  }
  L00434bfe: { // 0x434bfe: 8b442450 MOV EAX,dword ptr [ESP + 0x50]
    s.ax = m.r32((f.sp+0x00000050u));
  }
  L00434c02: { // 0x434c02: 8b4c2440 MOV ECX,dword ptr [ESP + 0x40]
    s.cx = m.r32((f.sp+0x00000040u));
  }
  L00434c06: { // 0x434c06: 0faf442454 IMUL EAX,dword ptr [ESP + 0x54]
    s.ax = integer::imul(s.ax,m.r32((f.sp+0x00000054u)),32,flags);
  }
  L00434c0b: { // 0x434c0b: 0faf4c2444 IMUL ECX,dword ptr [ESP + 0x44]
    s.cx = integer::imul(s.cx,m.r32((f.sp+0x00000044u)),32,flags);
  }
  L00434c10: { // 0x434c10: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00434c12: { // 0x434c12: 7c02 JL 0x00434c16
    if(integer::condition("JL",flags)) goto L00434c16;
  }
  L00434c14: { // 0x434c14: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00434c16: { // 0x434c16: 8a4c2468 MOV CL,byte ptr [ESP + 0x68]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000068u)));
  }
  L00434c1a: { // 0x434c1a: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00434c1c: { // 0x434c1c: 8b4c246c MOV ECX,dword ptr [ESP + 0x6c]
    s.cx = m.r32((f.sp+0x0000006cu));
  }
  L00434c20: { // 0x434c20: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00434c22: { // 0x434c22: 741e JZ 0x00434c42
    if(integer::condition("JZ",flags)) goto L00434c42;
  }
  L00434c24: { // 0x434c24: 68e8030000 PUSH 0x3e8
    f.push(m,0x000003e8u);
  }
  L00434c29: { // 0x434c29: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00434c2b: { // 0x434c2b: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00434c2d: { // 0x434c2d: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00434c2f: { // 0x434c2f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00434c30: { // 0x434c30: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L00434c34: { // 0x434c34: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00434c35: { // 0x434c35: 8b442474 MOV EAX,dword ptr [ESP + 0x74]
    s.ax = m.r32((f.sp+0x00000074u));
  }
  L00434c39: { // 0x434c39: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00434c3a: { // 0x434c3a: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),4410429u,op); flags=s.arithmetic_flags;
  }
  L00434c3d: { // 0x434c3d: e9b5020000 JMP 0x00434ef7
    goto L00434ef7;
  }
  L00434c42: { // 0x434c42: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00434c44: { // 0x434c44: 68e8030000 PUSH 0x3e8
    f.push(m,0x000003e8u);
  }
  L00434c49: { // 0x434c49: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00434c4b: { // 0x434c4b: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00434c4d: { // 0x434c4d: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00434c4f: { // 0x434c4f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00434c50: { // 0x434c50: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L00434c54: { // 0x434c54: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00434c55: { // 0x434c55: 8b442478 MOV EAX,dword ptr [ESP + 0x78]
    s.ax = m.r32((f.sp+0x00000078u));
  }
  L00434c59: { // 0x434c59: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00434c5a: { // 0x434c5a: ff5204 CALL dword ptr [EDX + 0x4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000004u)),4410461u,op); flags=s.arithmetic_flags;
  }
  L00434c5d: { // 0x434c5d: e995020000 JMP 0x00434ef7
    goto L00434ef7;
  }
  L00434c62: { // 0x434c62: 8b74241c MOV ESI,dword ptr [ESP + 0x1c]
    s.si = m.r32((f.sp+0x0000001cu));
  }
  L00434c66: { // 0x434c66: 8b4c2460 MOV ECX,dword ptr [ESP + 0x60]
    s.cx = m.r32((f.sp+0x00000060u));
  }
  L00434c6a: { // 0x434c6a: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00434c6c: { // 0x434c6c: ff5274 CALL dword ptr [EDX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000074u)),4410479u,op); flags=s.arithmetic_flags;
  }
  L00434c6f: { // 0x434c6f: 89442470 MOV dword ptr [ESP + 0x70],EAX
    m.w32((f.sp+0x00000070u), s.ax);
  }
  L00434c73: { // 0x434c73: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00434c75: { // 0x434c75: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00434c77: { // 0x434c77: ff5074 CALL dword ptr [EAX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000074u)),4410490u,op); flags=s.arithmetic_flags;
  }
  L00434c7a: { // 0x434c7a: 8b0dac1f8200 MOV ECX,dword ptr [0x00821fac]
    s.cx = m.r32((0x00821facu));
  }
  L00434c80: { // 0x434c80: 89442464 MOV dword ptr [ESP + 0x64],EAX
    m.w32((f.sp+0x00000064u), s.ax);
  }
  L00434c84: { // 0x434c84: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00434c86: { // 0x434c86: 7407 JZ 0x00434c8f
    if(integer::condition("JZ",flags)) goto L00434c8f;
  }
  L00434c88: { // 0x434c88: 8b4928 MOV ECX,dword ptr [ECX + 0x28]
    s.cx = m.r32((s.cx+0x00000028u));
  }
  L00434c8b: { // 0x434c8b: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L00434c8f: { // 0x434c8f: 8b0df4988100 MOV ECX,dword ptr [0x008198f4]
    s.cx = m.r32((0x008198f4u));
  }
  L00434c95: { // 0x434c95: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00434c97: { // 0x434c97: 7407 JZ 0x00434ca0
    if(integer::condition("JZ",flags)) goto L00434ca0;
  }
  L00434c99: { // 0x434c99: 8b5128 MOV EDX,dword ptr [ECX + 0x28]
    s.dx = m.r32((s.cx+0x00000028u));
  }
  L00434c9c: { // 0x434c9c: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L00434ca0: { // 0x434ca0: 8a4c2468 MOV CL,byte ptr [ESP + 0x68]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000068u)));
  }
  L00434ca4: { // 0x434ca4: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00434ca6: { // 0x434ca6: 0f84c4000000 JZ 0x00434d70
    if(integer::condition("JZ",flags)) goto L00434d70;
  }
  L00434cac: { // 0x434cac: 8b4c2470 MOV ECX,dword ptr [ESP + 0x70]
    s.cx = m.r32((f.sp+0x00000070u));
  }
  L00434cb0: { // 0x434cb0: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L00434cb4: { // 0x434cb4: f7d9 NEG ECX
    s.cx = integer::sub(0u,s.cx,32,flags);
  }
  L00434cb6: { // 0x434cb6: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L00434cb8: { // 0x434cb8: 894c2470 MOV dword ptr [ESP + 0x70],ECX
    m.w32((f.sp+0x00000070u), s.cx);
  }
  L00434cbc: { // 0x434cbc: 8b4c2460 MOV ECX,dword ptr [ESP + 0x60]
    s.cx = m.r32((f.sp+0x00000060u));
  }
  L00434cc0: { // 0x434cc0: 89442464 MOV dword ptr [ESP + 0x64],EAX
    m.w32((f.sp+0x00000064u), s.ax);
  }
  L00434cc4: { // 0x434cc4: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L00434cc8: { // 0x434cc8: f7da NEG EDX
    s.dx = integer::sub(0u,s.dx,32,flags);
  }
  L00434cca: { // 0x434cca: 89542420 MOV dword ptr [ESP + 0x20],EDX
    m.w32((f.sp+0x00000020u), s.dx);
  }
  L00434cce: { // 0x434cce: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00434cd0: { // 0x434cd0: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L00434cd2: { // 0x434cd2: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L00434cd6: { // 0x434cd6: ff5274 CALL dword ptr [EDX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000074u)),4410585u,op); flags=s.arithmetic_flags;
  }
  L00434cd9: { // 0x434cd9: 8b4c2454 MOV ECX,dword ptr [ESP + 0x54]
    s.cx = m.r32((f.sp+0x00000054u));
  }
  L00434cdd: { // 0x434cdd: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00434cdf: { // 0x434cdf: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00434ce0: { // 0x434ce0: 0fafc1 IMUL EAX,ECX
    s.ax = integer::imul(s.ax,s.cx,32,flags);
  }
  L00434ce3: { // 0x434ce3: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00434ce7: { // 0x434ce7: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00434ce9: { // 0x434ce9: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L00434ced: { // 0x434ced: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00434cef: { // 0x434cef: ff5274 CALL dword ptr [EDX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000074u)),4410610u,op); flags=s.arithmetic_flags;
  }
  L00434cf2: { // 0x434cf2: 8b4c2444 MOV ECX,dword ptr [ESP + 0x44]
    s.cx = m.r32((f.sp+0x00000044u));
  }
  L00434cf6: { // 0x434cf6: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00434cf7: { // 0x434cf7: 0fafc1 IMUL EAX,ECX
    s.ax = integer::imul(s.ax,s.cx,32,flags);
  }
  L00434cfa: { // 0x434cfa: 8b4c245c MOV ECX,dword ptr [ESP + 0x5c]
    s.cx = m.r32((f.sp+0x0000005cu));
  }
  L00434cfe: { // 0x434cfe: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00434d00: { // 0x434d00: a1ac1f8200 MOV EAX,[0x00821fac]
    s.ax = m.r32((0x00821facu));
  }
  L00434d05: { // 0x434d05: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00434d07: { // 0x434d07: 894c245c MOV dword ptr [ESP + 0x5c],ECX
    m.w32((f.sp+0x0000005cu), s.cx);
  }
  L00434d0b: { // 0x434d0b: 742d JZ 0x00434d3a
    if(integer::condition("JZ",flags)) goto L00434d3a;
  }
  L00434d0d: { // 0x434d0d: 8b4828 MOV ECX,dword ptr [EAX + 0x28]
    s.cx = m.r32((s.ax+0x00000028u));
  }
  L00434d10: { // 0x434d10: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L00434d12: { // 0x434d12: f7da NEG EDX
    s.dx = integer::sub(0u,s.dx,32,flags);
  }
  L00434d14: { // 0x434d14: c1e21f SHL EDX,0x1f
    s.dx = integer::shift(s.dx,0x0000001fu,32,flags,integer::Shift::left);
  }
  L00434d17: { // 0x434d17: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L00434d19: { // 0x434d19: 8b4c2454 MOV ECX,dword ptr [ESP + 0x54]
    s.cx = m.r32((f.sp+0x00000054u));
  }
  L00434d1d: { // 0x434d1d: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L00434d1f: { // 0x434d1f: 8d6c5500 LEA EBP,[EBP + EDX*0x2]
    s.bp = (s.bp+(s.dx * 0x00000002u));
  }
  L00434d23: { // 0x434d23: 8b501c MOV EDX,dword ptr [EAX + 0x1c]
    s.dx = m.r32((s.ax+0x0000001cu));
  }
  L00434d26: { // 0x434d26: 3bea CMP EBP,EDX
    (void)integer::sub(s.bp,s.dx,32,flags);
  }
  L00434d28: { // 0x434d28: 7203 JC 0x00434d2d
    if(integer::condition("JC",flags)) goto L00434d2d;
  }
  L00434d2a: { // 0x434d2a: 2b6820 SUB EBP,dword ptr [EAX + 0x20]
    s.bp = integer::sub(s.bp,m.r32((s.ax+0x00000020u)),32,flags);
  }
  L00434d2d: { // 0x434d2d: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L00434d32: { // 0x434d32: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00434d34: { // 0x434d34: 8b4c245c MOV ECX,dword ptr [ESP + 0x5c]
    s.cx = m.r32((f.sp+0x0000005cu));
  }
  L00434d38: { // 0x434d38: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L00434d3a: { // 0x434d3a: a1f4988100 MOV EAX,[0x008198f4]
    s.ax = m.r32((0x008198f4u));
  }
  L00434d3f: { // 0x434d3f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00434d41: { // 0x434d41: 7431 JZ 0x00434d74
    if(integer::condition("JZ",flags)) goto L00434d74;
  }
  L00434d43: { // 0x434d43: 8b4028 MOV EAX,dword ptr [EAX + 0x28]
    s.ax = m.r32((s.ax+0x00000028u));
  }
  L00434d46: { // 0x434d46: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00434d48: { // 0x434d48: f7da NEG EDX
    s.dx = integer::sub(0u,s.dx,32,flags);
  }
  L00434d4a: { // 0x434d4a: c1e21f SHL EDX,0x1f
    s.dx = integer::shift(s.dx,0x0000001fu,32,flags,integer::Shift::left);
  }
  L00434d4d: { // 0x434d4d: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L00434d4f: { // 0x434d4f: 8b442454 MOV EAX,dword ptr [ESP + 0x54]
    s.ax = m.r32((f.sp+0x00000054u));
  }
  L00434d53: { // 0x434d53: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00434d55: { // 0x434d55: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00434d59: { // 0x434d59: 8d0450 LEA EAX,[EAX + EDX*0x2]
    s.ax = (s.ax+(s.dx * 0x00000002u));
  }
  L00434d5c: { // 0x434d5c: 8b15f4988100 MOV EDX,dword ptr [0x008198f4]
    s.dx = m.r32((0x008198f4u));
  }
  L00434d62: { // 0x434d62: 3b421c CMP EAX,dword ptr [EDX + 0x1c]
    (void)integer::sub(s.ax,m.r32((s.dx+0x0000001cu)),32,flags);
  }
  L00434d65: { // 0x434d65: 7203 JC 0x00434d6a
    if(integer::condition("JC",flags)) goto L00434d6a;
  }
  L00434d67: { // 0x434d67: 2b4220 SUB EAX,dword ptr [EDX + 0x20]
    s.ax = integer::sub(s.ax,m.r32((s.dx+0x00000020u)),32,flags);
  }
  L00434d6a: { // 0x434d6a: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00434d6e: { // 0x434d6e: eb04 JMP 0x00434d74
    goto L00434d74;
  }
  L00434d70: { // 0x434d70: 8b4c245c MOV ECX,dword ptr [ESP + 0x5c]
    s.cx = m.r32((f.sp+0x0000005cu));
  }
  L00434d74: { // 0x434d74: 8b442454 MOV EAX,dword ptr [ESP + 0x54]
    s.ax = m.r32((f.sp+0x00000054u));
  }
  L00434d78: { // 0x434d78: 8b542444 MOV EDX,dword ptr [ESP + 0x44]
    s.dx = m.r32((f.sp+0x00000044u));
  }
  L00434d7c: { // 0x434d7c: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00434d7e: { // 0x434d7e: 7c02 JL 0x00434d82
    if(integer::condition("JL",flags)) goto L00434d82;
  }
  L00434d80: { // 0x434d80: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L00434d82: { // 0x434d82: 8a542468 MOV DL,byte ptr [ESP + 0x68]
    s.dx = with_al(s.dx, m.r8((f.sp+0x00000068u)));
  }
  L00434d86: { // 0x434d86: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L00434d88: { // 0x434d88: 0f84b6000000 JZ 0x00434e44
    if(integer::condition("JZ",flags)) goto L00434e44;
  }
  L00434d8e: { // 0x434d8e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00434d90: { // 0x434d90: 0f8e65010000 JLE 0x00434efb
    if(integer::condition("JLE",flags)) goto L00434efb;
  }
  L00434d96: { // 0x434d96: 8b74246c MOV ESI,dword ptr [ESP + 0x6c]
    s.si = m.r32((f.sp+0x0000006cu));
  }
  L00434d9a: { // 0x434d9a: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L00434d9e: { // 0x434d9e: 8b442478 MOV EAX,dword ptr [ESP + 0x78]
    s.ax = m.r32((f.sp+0x00000078u));
  }
  L00434da2: { // 0x434da2: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00434da4: { // 0x434da4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00434da5: { // 0x434da5: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00434da9: { // 0x434da9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00434daa: { // 0x434daa: 8b442458 MOV EAX,dword ptr [ESP + 0x58]
    s.ax = m.r32((f.sp+0x00000058u));
  }
  L00434dae: { // 0x434dae: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00434daf: { // 0x434daf: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00434db0: { // 0x434db0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00434db1: { // 0x434db1: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L00434db5: { // 0x434db5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00434db6: { // 0x434db6: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00434db7: { // 0x434db7: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00434db9: { // 0x434db9: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),4410812u,op); flags=s.arithmetic_flags;
  }
  L00434dbc: { // 0x434dbc: 8b4c245c MOV ECX,dword ptr [ESP + 0x5c]
    s.cx = m.r32((f.sp+0x0000005cu));
  }
  L00434dc0: { // 0x434dc0: 8b542464 MOV EDX,dword ptr [ESP + 0x64]
    s.dx = m.r32((f.sp+0x00000064u));
  }
  L00434dc4: { // 0x434dc4: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00434dc8: { // 0x434dc8: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L00434dca: { // 0x434dca: 8b542470 MOV EDX,dword ptr [ESP + 0x70]
    s.dx = m.r32((f.sp+0x00000070u));
  }
  L00434dce: { // 0x434dce: 894c245c MOV dword ptr [ESP + 0x5c],ECX
    m.w32((f.sp+0x0000005cu), s.cx);
  }
  L00434dd2: { // 0x434dd2: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00434dd4: { // 0x434dd4: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00434dd8: { // 0x434dd8: a1ac1f8200 MOV EAX,[0x00821fac]
    s.ax = m.r32((0x00821facu));
  }
  L00434ddd: { // 0x434ddd: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00434ddf: { // 0x434ddf: 7429 JZ 0x00434e0a
    if(integer::condition("JZ",flags)) goto L00434e0a;
  }
  L00434de1: { // 0x434de1: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L00434de5: { // 0x434de5: 8d6c5500 LEA EBP,[EBP + EDX*0x2]
    s.bp = (s.bp+(s.dx * 0x00000002u));
  }
  L00434de9: { // 0x434de9: 8b5018 MOV EDX,dword ptr [EAX + 0x18]
    s.dx = m.r32((s.ax+0x00000018u));
  }
  L00434dec: { // 0x434dec: 3bea CMP EBP,EDX
    (void)integer::sub(s.bp,s.dx,32,flags);
  }
  L00434dee: { // 0x434dee: 7303 JNC 0x00434df3
    if(integer::condition("JNC",flags)) goto L00434df3;
  }
  L00434df0: { // 0x434df0: 036820 ADD EBP,dword ptr [EAX + 0x20]
    s.bp = integer::add(s.bp,m.r32((s.ax+0x00000020u)),32,flags);
  }
  L00434df3: { // 0x434df3: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L00434df7: { // 0x434df7: 03d8 ADD EBX,EAX
    s.bx = integer::add(s.bx,s.ax,32,flags);
  }
  L00434df9: { // 0x434df9: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L00434dfd: { // 0x434dfd: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L00434dff: { // 0x434dff: 7c09 JL 0x00434e0a
    if(integer::condition("JL",flags)) goto L00434e0a;
  }
  L00434e01: { // 0x434e01: 8b542474 MOV EDX,dword ptr [ESP + 0x74]
    s.dx = m.r32((f.sp+0x00000074u));
  }
  L00434e05: { // 0x434e05: 037a10 ADD EDI,dword ptr [EDX + 0x10]
    s.di = integer::add(s.di,m.r32((s.dx+0x00000010u)),32,flags);
  }
  L00434e08: { // 0x434e08: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00434e0a: { // 0x434e0a: a1f4988100 MOV EAX,[0x008198f4]
    s.ax = m.r32((0x008198f4u));
  }
  L00434e0f: { // 0x434e0f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00434e11: { // 0x434e11: 741d JZ 0x00434e30
    if(integer::condition("JZ",flags)) goto L00434e30;
  }
  L00434e13: { // 0x434e13: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00434e17: { // 0x434e17: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L00434e1b: { // 0x434e1b: 8d0450 LEA EAX,[EAX + EDX*0x2]
    s.ax = (s.ax+(s.dx * 0x00000002u));
  }
  L00434e1e: { // 0x434e1e: 8b15f4988100 MOV EDX,dword ptr [0x008198f4]
    s.dx = m.r32((0x008198f4u));
  }
  L00434e24: { // 0x434e24: 3b4218 CMP EAX,dword ptr [EDX + 0x18]
    (void)integer::sub(s.ax,m.r32((s.dx+0x00000018u)),32,flags);
  }
  L00434e27: { // 0x434e27: 7303 JNC 0x00434e2c
    if(integer::condition("JNC",flags)) goto L00434e2c;
  }
  L00434e29: { // 0x434e29: 034220 ADD EAX,dword ptr [EDX + 0x20]
    s.ax = integer::add(s.ax,m.r32((s.dx+0x00000020u)),32,flags);
  }
  L00434e2c: { // 0x434e2c: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00434e30: { // 0x434e30: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L00434e34: { // 0x434e34: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00434e35: { // 0x434e35: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L00434e39: { // 0x434e39: 0f855fffffff JNZ 0x00434d9e
    if(integer::condition("JNZ",flags)) goto L00434d9e;
  }
  L00434e3f: { // 0x434e3f: e9b3000000 JMP 0x00434ef7
    goto L00434ef7;
  }
  L00434e44: { // 0x434e44: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00434e46: { // 0x434e46: 0f8eaf000000 JLE 0x00434efb
    if(integer::condition("JLE",flags)) goto L00434efb;
  }
  L00434e4c: { // 0x434e4c: 8b74246c MOV ESI,dword ptr [ESP + 0x6c]
    s.si = m.r32((f.sp+0x0000006cu));
  }
  L00434e50: { // 0x434e50: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L00434e54: { // 0x434e54: 8b542478 MOV EDX,dword ptr [ESP + 0x78]
    s.dx = m.r32((f.sp+0x00000078u));
  }
  L00434e58: { // 0x434e58: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00434e5a: { // 0x434e5a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00434e5b: { // 0x434e5b: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L00434e5f: { // 0x434e5f: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00434e61: { // 0x434e61: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00434e62: { // 0x434e62: 8b54245c MOV EDX,dword ptr [ESP + 0x5c]
    s.dx = m.r32((f.sp+0x0000005cu));
  }
  L00434e66: { // 0x434e66: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00434e67: { // 0x434e67: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00434e68: { // 0x434e68: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00434e69: { // 0x434e69: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L00434e6d: { // 0x434e6d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00434e6e: { // 0x434e6e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00434e6f: { // 0x434e6f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00434e71: { // 0x434e71: ff5004 CALL dword ptr [EAX + 0x4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000004u)),4410996u,op); flags=s.arithmetic_flags;
  }
  L00434e74: { // 0x434e74: 8b4c245c MOV ECX,dword ptr [ESP + 0x5c]
    s.cx = m.r32((f.sp+0x0000005cu));
  }
  L00434e78: { // 0x434e78: 8b442464 MOV EAX,dword ptr [ESP + 0x64]
    s.ax = m.r32((f.sp+0x00000064u));
  }
  L00434e7c: { // 0x434e7c: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00434e80: { // 0x434e80: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00434e82: { // 0x434e82: 8b442470 MOV EAX,dword ptr [ESP + 0x70]
    s.ax = m.r32((f.sp+0x00000070u));
  }
  L00434e86: { // 0x434e86: 894c245c MOV dword ptr [ESP + 0x5c],ECX
    m.w32((f.sp+0x0000005cu), s.cx);
  }
  L00434e8a: { // 0x434e8a: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00434e8c: { // 0x434e8c: a1ac1f8200 MOV EAX,[0x00821fac]
    s.ax = m.r32((0x00821facu));
  }
  L00434e91: { // 0x434e91: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00434e93: { // 0x434e93: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L00434e97: { // 0x434e97: 7429 JZ 0x00434ec2
    if(integer::condition("JZ",flags)) goto L00434ec2;
  }
  L00434e99: { // 0x434e99: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L00434e9d: { // 0x434e9d: 8d6c5500 LEA EBP,[EBP + EDX*0x2]
    s.bp = (s.bp+(s.dx * 0x00000002u));
  }
  L00434ea1: { // 0x434ea1: 8b501c MOV EDX,dword ptr [EAX + 0x1c]
    s.dx = m.r32((s.ax+0x0000001cu));
  }
  L00434ea4: { // 0x434ea4: 3bea CMP EBP,EDX
    (void)integer::sub(s.bp,s.dx,32,flags);
  }
  L00434ea6: { // 0x434ea6: 7203 JC 0x00434eab
    if(integer::condition("JC",flags)) goto L00434eab;
  }
  L00434ea8: { // 0x434ea8: 2b6820 SUB EBP,dword ptr [EAX + 0x20]
    s.bp = integer::sub(s.bp,m.r32((s.ax+0x00000020u)),32,flags);
  }
  L00434eab: { // 0x434eab: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L00434eaf: { // 0x434eaf: 03d8 ADD EBX,EAX
    s.bx = integer::add(s.bx,s.ax,32,flags);
  }
  L00434eb1: { // 0x434eb1: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L00434eb5: { // 0x434eb5: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L00434eb7: { // 0x434eb7: 7c09 JL 0x00434ec2
    if(integer::condition("JL",flags)) goto L00434ec2;
  }
  L00434eb9: { // 0x434eb9: 8b542474 MOV EDX,dword ptr [ESP + 0x74]
    s.dx = m.r32((f.sp+0x00000074u));
  }
  L00434ebd: { // 0x434ebd: 037a10 ADD EDI,dword ptr [EDX + 0x10]
    s.di = integer::add(s.di,m.r32((s.dx+0x00000010u)),32,flags);
  }
  L00434ec0: { // 0x434ec0: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00434ec2: { // 0x434ec2: a1f4988100 MOV EAX,[0x008198f4]
    s.ax = m.r32((0x008198f4u));
  }
  L00434ec7: { // 0x434ec7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00434ec9: { // 0x434ec9: 741d JZ 0x00434ee8
    if(integer::condition("JZ",flags)) goto L00434ee8;
  }
  L00434ecb: { // 0x434ecb: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00434ecf: { // 0x434ecf: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L00434ed3: { // 0x434ed3: 8d0450 LEA EAX,[EAX + EDX*0x2]
    s.ax = (s.ax+(s.dx * 0x00000002u));
  }
  L00434ed6: { // 0x434ed6: 8b15f4988100 MOV EDX,dword ptr [0x008198f4]
    s.dx = m.r32((0x008198f4u));
  }
  L00434edc: { // 0x434edc: 3b421c CMP EAX,dword ptr [EDX + 0x1c]
    (void)integer::sub(s.ax,m.r32((s.dx+0x0000001cu)),32,flags);
  }
  L00434edf: { // 0x434edf: 7203 JC 0x00434ee4
    if(integer::condition("JC",flags)) goto L00434ee4;
  }
  L00434ee1: { // 0x434ee1: 2b4220 SUB EAX,dword ptr [EDX + 0x20]
    s.ax = integer::sub(s.ax,m.r32((s.dx+0x00000020u)),32,flags);
  }
  L00434ee4: { // 0x434ee4: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00434ee8: { // 0x434ee8: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L00434eec: { // 0x434eec: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00434eed: { // 0x434eed: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L00434ef1: { // 0x434ef1: 0f855dffffff JNZ 0x00434e54
    if(integer::condition("JNZ",flags)) goto L00434e54;
  }
  L00434ef7: { // 0x434ef7: 8b74241c MOV ESI,dword ptr [ESP + 0x1c]
    s.si = m.r32((f.sp+0x0000001cu));
  }
  L00434efb: { // 0x434efb: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00434efd: { // 0x434efd: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00434eff: { // 0x434eff: ff5060 CALL dword ptr [EAX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000060u)),4411138u,op); flags=s.arithmetic_flags;
  }
  L00434f02: { // 0x434f02: 8b4c2460 MOV ECX,dword ptr [ESP + 0x60]
    s.cx = m.r32((f.sp+0x00000060u));
  }
  L00434f06: { // 0x434f06: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00434f08: { // 0x434f08: ff5260 CALL dword ptr [EDX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),4411147u,op); flags=s.arithmetic_flags;
  }
  L00434f0b: { // 0x434f0b: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00434f0d: { // 0x434f0d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00434f0e: { // 0x434f0e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00434f0f: { // 0x434f0f: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00434f10: { // 0x434f10: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00434f11: { // 0x434f11: 83c448 ADD ESP,0x48
    f.sp = integer::add(f.sp,0x00000048u,32,flags);
  }
  L00434f14: { // 0x434f14: c22400 RET 0x24
    s.arithmetic_flags=flags; finish(m,s,f,36u); return;
  }
}

void f_00360cf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00760cf0: { // 0x760cf0: 83ec18 SUB ESP,0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
  L00760cf3: { // 0x760cf3: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L00760cf7: { // 0x760cf7: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00760cf8: { // 0x760cf8: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00760cf9: { // 0x760cf9: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L00760cfb: { // 0x760cfb: 8b4c2438 MOV ECX,dword ptr [ESP + 0x38]
    s.cx = m.r32((f.sp+0x00000038u));
  }
  L00760cff: { // 0x760cff: 8bea MOV EBP,EDX
    s.bp = s.dx;
  }
  L00760d01: { // 0x760d01: 8b54243c MOV EDX,dword ptr [ESP + 0x3c]
    s.dx = m.r32((f.sp+0x0000003cu));
  }
  L00760d05: { // 0x760d05: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00760d06: { // 0x760d06: 8b742428 MOV ESI,dword ptr [ESP + 0x28]
    s.si = m.r32((f.sp+0x00000028u));
  }
  L00760d0a: { // 0x760d0a: c60000 MOV byte ptr [EAX],0x0
    m.w8((s.ax), 0x00000000u);
  }
  L00760d0d: { // 0x760d0d: c70100000000 MOV dword ptr [ECX],0x0
    m.w32((s.cx), 0x00000000u);
  }
  L00760d13: { // 0x760d13: c70200000000 MOV dword ptr [EDX],0x0
    m.w32((s.dx), 0x00000000u);
  }
  L00760d19: { // 0x760d19: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L00760d1c: { // 0x760d1c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00760d1d: { // 0x760d1d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760d1f: { // 0x760d1f: 896c2418 MOV dword ptr [ESP + 0x18],EBP
    m.w32((f.sp+0x00000018u), s.bp);
  }
  L00760d23: { // 0x760d23: 895c2410 MOV dword ptr [ESP + 0x10],EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
  L00760d27: { // 0x760d27: 0f8e53010000 JLE 0x00760e80
    if(integer::condition("JLE",flags)) goto L00760e80;
  }
  L00760d2d: { // 0x760d2d: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  L00760d30: { // 0x760d30: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760d32: { // 0x760d32: 0f8e48010000 JLE 0x00760e80
    if(integer::condition("JLE",flags)) goto L00760e80;
  }
  L00760d38: { // 0x760d38: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L00760d3b: { // 0x760d3b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760d3d: { // 0x760d3d: 0f8e3d010000 JLE 0x00760e80
    if(integer::condition("JLE",flags)) goto L00760e80;
  }
  L00760d43: { // 0x760d43: 8b450c MOV EAX,dword ptr [EBP + 0xc]
    s.ax = m.r32((s.bp+0x0000000cu));
  }
  L00760d46: { // 0x760d46: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760d48: { // 0x760d48: 0f8e32010000 JLE 0x00760e80
    if(integer::condition("JLE",flags)) goto L00760e80;
  }
  L00760d4e: { // 0x760d4e: 8b7c2438 MOV EDI,dword ptr [ESP + 0x38]
    s.di = m.r32((f.sp+0x00000038u));
  }
  L00760d52: { // 0x760d52: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  L00760d55: { // 0x760d55: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760d57: { // 0x760d57: 0f8e23010000 JLE 0x00760e80
    if(integer::condition("JLE",flags)) goto L00760e80;
  }
  L00760d5d: { // 0x760d5d: 8b470c MOV EAX,dword ptr [EDI + 0xc]
    s.ax = m.r32((s.di+0x0000000cu));
  }
  L00760d60: { // 0x760d60: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760d62: { // 0x760d62: 0f8e18010000 JLE 0x00760e80
    if(integer::condition("JLE",flags)) goto L00760e80;
  }
  L00760d68: { // 0x760d68: 8b442434 MOV EAX,dword ptr [ESP + 0x34]
    s.ax = m.r32((f.sp+0x00000034u));
  }
  L00760d6c: { // 0x760d6c: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L00760d6f: { // 0x760d6f: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00760d71: { // 0x760d71: 0f8e09010000 JLE 0x00760e80
    if(integer::condition("JLE",flags)) goto L00760e80;
  }
  L00760d77: { // 0x760d77: 8b480c MOV ECX,dword ptr [EAX + 0xc]
    s.cx = m.r32((s.ax+0x0000000cu));
  }
  L00760d7a: { // 0x760d7a: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00760d7c: { // 0x760d7c: 0f8efe000000 JLE 0x00760e80
    if(integer::condition("JLE",flags)) goto L00760e80;
  }
  L00760d82: { // 0x760d82: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00760d83: { // 0x760d83: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00760d84: { // 0x760d84: 8bd5 MOV EDX,EBP
    s.dx = s.bp;
  }
  L00760d86: { // 0x760d86: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00760d88: { // 0x760d88: e843fdffff CALL 0x00760ad0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00760ad0u,7736717u,op); flags=s.arithmetic_flags;
  }
  L00760d8d: { // 0x760d8d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00760d8f: { // 0x760d8f: 0f84eb000000 JZ 0x00760e80
    if(integer::condition("JZ",flags)) goto L00760e80;
  }
  L00760d95: { // 0x760d95: 8b44243c MOV EAX,dword ptr [ESP + 0x3c]
    s.ax = m.r32((f.sp+0x0000003cu));
  }
  L00760d99: { // 0x760d99: c60000 MOV byte ptr [EAX],0x0
    m.w8((s.ax), 0x00000000u);
  }
  L00760d9c: { // 0x760d9c: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L00760da0: { // 0x760da0: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00760da2: { // 0x760da2: 7547 JNZ 0x00760deb
    if(integer::condition("JNZ",flags)) goto L00760deb;
  }
  L00760da4: { // 0x760da4: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00760da6: { // 0x760da6: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L00760da9: { // 0x760da9: 8b1f MOV EBX,dword ptr [EDI]
    s.bx = m.r32((s.di));
  }
  L00760dab: { // 0x760dab: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L00760dad: { // 0x760dad: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L00760daf: { // 0x760daf: 7d36 JGE 0x00760de7
    if(integer::condition("JGE",flags)) goto L00760de7;
  }
  L00760db1: { // 0x760db1: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L00760db4: { // 0x760db4: 8b6e0c MOV EBP,dword ptr [ESI + 0xc]
    s.bp = m.r32((s.si+0x0000000cu));
  }
  L00760db7: { // 0x760db7: 8b4f04 MOV ECX,dword ptr [EDI + 0x4]
    s.cx = m.r32((s.di+0x00000004u));
  }
  L00760dba: { // 0x760dba: 03e8 ADD EBP,EAX
    s.bp = integer::add(s.bp,s.ax,32,flags);
  }
  L00760dbc: { // 0x760dbc: 3bcd CMP ECX,EBP
    (void)integer::sub(s.cx,s.bp,32,flags);
  }
  L00760dbe: { // 0x760dbe: 7d23 JGE 0x00760de3
    if(integer::condition("JGE",flags)) goto L00760de3;
  }
  L00760dc0: { // 0x760dc0: 8beb MOV EBP,EBX
    s.bp = s.bx;
  }
  L00760dc2: { // 0x760dc2: 036f08 ADD EBP,dword ptr [EDI + 0x8]
    s.bp = integer::add(s.bp,m.r32((s.di+0x00000008u)),32,flags);
  }
  L00760dc5: { // 0x760dc5: 3bea CMP EBP,EDX
    (void)integer::sub(s.bp,s.dx,32,flags);
  }
  L00760dc7: { // 0x760dc7: 7e1a JLE 0x00760de3
    if(integer::condition("JLE",flags)) goto L00760de3;
  }
  L00760dc9: { // 0x760dc9: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L00760dcb: { // 0x760dcb: 036f0c ADD EBP,dword ptr [EDI + 0xc]
    s.bp = integer::add(s.bp,m.r32((s.di+0x0000000cu)),32,flags);
  }
  L00760dce: { // 0x760dce: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L00760dd0: { // 0x760dd0: 7e11 JLE 0x00760de3
    if(integer::condition("JLE",flags)) goto L00760de3;
  }
  L00760dd2: { // 0x760dd2: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00760dd4: { // 0x760dd4: 7c06 JL 0x00760ddc
    if(integer::condition("JL",flags)) goto L00760ddc;
  }
  L00760dd6: { // 0x760dd6: 750b JNZ 0x00760de3
    if(integer::condition("JNZ",flags)) goto L00760de3;
  }
  L00760dd8: { // 0x760dd8: 3bda CMP EBX,EDX
    (void)integer::sub(s.bx,s.dx,32,flags);
  }
  L00760dda: { // 0x760dda: 7d07 JGE 0x00760de3
    if(integer::condition("JGE",flags)) goto L00760de3;
  }
  L00760ddc: { // 0x760ddc: 8b54243c MOV EDX,dword ptr [ESP + 0x3c]
    s.dx = m.r32((f.sp+0x0000003cu));
  }
  L00760de0: { // 0x760de0: c60201 MOV byte ptr [EDX],0x1
    m.w8((s.dx), 0x00000001u);
  }
  L00760de3: { // 0x760de3: 8b6c2418 MOV EBP,dword ptr [ESP + 0x18]
    s.bp = m.r32((f.sp+0x00000018u));
  }
  L00760de7: { // 0x760de7: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L00760deb: { // 0x760deb: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L00760def: { // 0x760def: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00760df1: { // 0x760df1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00760df2: { // 0x760df2: e82946cdff CALL 0x00435420
    s.arithmetic_flags=flags; invoke(m,s,f,0x00435420u,7736823u,op); flags=s.arithmetic_flags;
  }
  L00760df7: { // 0x760df7: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L00760dfb: { // 0x760dfb: 8d542420 LEA EDX,[ESP + 0x20]
    s.dx = (f.sp+0x00000020u);
  }
  L00760dff: { // 0x760dff: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00760e00: { // 0x760e00: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00760e01: { // 0x760e01: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00760e02: { // 0x760e02: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00760e04: { // 0x760e04: e81746cdff CALL 0x00435420
    s.arithmetic_flags=flags; invoke(m,s,f,0x00435420u,7736841u,op); flags=s.arithmetic_flags;
  }
  L00760e09: { // 0x760e09: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00760e0b: { // 0x760e0b: e8f045cdff CALL 0x00435400
    s.arithmetic_flags=flags; invoke(m,s,f,0x00435400u,7736848u,op); flags=s.arithmetic_flags;
  }
  L00760e10: { // 0x760e10: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00760e12: { // 0x760e12: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00760e15: { // 0x760e15: 8bcc MOV ECX,ESP
    s.cx = f.sp;
  }
  L00760e17: { // 0x760e17: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  L00760e19: { // 0x760e19: 8b4004 MOV EAX,dword ptr [EAX + 0x4]
    s.ax = m.r32((s.ax+0x00000004u));
  }
  L00760e1c: { // 0x760e1c: 894104 MOV dword ptr [ECX + 0x4],EAX
    m.w32((s.cx+0x00000004u), s.ax);
  }
  L00760e1f: { // 0x760e1f: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L00760e21: { // 0x760e21: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00760e23: { // 0x760e23: ff525c CALL dword ptr [EDX + 0x5c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000005cu)),7736870u,op); flags=s.arithmetic_flags;
  }
  L00760e26: { // 0x760e26: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760e28: { // 0x760e28: 8b4c2440 MOV ECX,dword ptr [ESP + 0x40]
    s.cx = m.r32((f.sp+0x00000040u));
  }
  L00760e2c: { // 0x760e2c: 8901 MOV dword ptr [ECX],EAX
    m.w32((s.cx), s.ax);
  }
  L00760e2e: { // 0x760e2e: 7450 JZ 0x00760e80
    if(integer::condition("JZ",flags)) goto L00760e80;
  }
  L00760e30: { // 0x760e30: 8d542420 LEA EDX,[ESP + 0x20]
    s.dx = (f.sp+0x00000020u);
  }
  L00760e34: { // 0x760e34: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00760e36: { // 0x760e36: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00760e37: { // 0x760e37: e8e445cdff CALL 0x00435420
    s.arithmetic_flags=flags; invoke(m,s,f,0x00435420u,7736892u,op); flags=s.arithmetic_flags;
  }
  L00760e3c: { // 0x760e3c: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L00760e40: { // 0x760e40: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00760e41: { // 0x760e41: 8d44241c LEA EAX,[ESP + 0x1c]
    s.ax = (f.sp+0x0000001cu);
  }
  L00760e45: { // 0x760e45: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00760e46: { // 0x760e46: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00760e47: { // 0x760e47: 8b4c2440 MOV ECX,dword ptr [ESP + 0x40]
    s.cx = m.r32((f.sp+0x00000040u));
  }
  L00760e4b: { // 0x760e4b: e8d045cdff CALL 0x00435420
    s.arithmetic_flags=flags; invoke(m,s,f,0x00435420u,7736912u,op); flags=s.arithmetic_flags;
  }
  L00760e50: { // 0x760e50: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00760e52: { // 0x760e52: e8a945cdff CALL 0x00435400
    s.arithmetic_flags=flags; invoke(m,s,f,0x00435400u,7736919u,op); flags=s.arithmetic_flags;
  }
  L00760e57: { // 0x760e57: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00760e59: { // 0x760e59: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00760e5c: { // 0x760e5c: 8bcc MOV ECX,ESP
    s.cx = f.sp;
  }
  L00760e5e: { // 0x760e5e: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  L00760e60: { // 0x760e60: 8b4004 MOV EAX,dword ptr [EAX + 0x4]
    s.ax = m.r32((s.ax+0x00000004u));
  }
  L00760e63: { // 0x760e63: 894104 MOV dword ptr [ECX + 0x4],EAX
    m.w32((s.cx+0x00000004u), s.ax);
  }
  L00760e66: { // 0x760e66: 8b4c2438 MOV ECX,dword ptr [ESP + 0x38]
    s.cx = m.r32((f.sp+0x00000038u));
  }
  L00760e6a: { // 0x760e6a: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00760e6c: { // 0x760e6c: ff525c CALL dword ptr [EDX + 0x5c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000005cu)),7736943u,op); flags=s.arithmetic_flags;
  }
  L00760e6f: { // 0x760e6f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760e71: { // 0x760e71: 8b4c2444 MOV ECX,dword ptr [ESP + 0x44]
    s.cx = m.r32((f.sp+0x00000044u));
  }
  L00760e75: { // 0x760e75: 8901 MOV dword ptr [ECX],EAX
    m.w32((s.cx), s.ax);
  }
  L00760e77: { // 0x760e77: 7513 JNZ 0x00760e8c
    if(integer::condition("JNZ",flags)) goto L00760e8c;
  }
  L00760e79: { // 0x760e79: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L00760e7b: { // 0x760e7b: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00760e7d: { // 0x760e7d: ff5260 CALL dword ptr [EDX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),7736960u,op); flags=s.arithmetic_flags;
  }
  L00760e80: { // 0x760e80: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00760e82: { // 0x760e82: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00760e83: { // 0x760e83: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00760e84: { // 0x760e84: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00760e85: { // 0x760e85: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00760e86: { // 0x760e86: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L00760e89: { // 0x760e89: c21c00 RET 0x1c
    s.arithmetic_flags=flags; finish(m,s,f,28u); return;
  }
  L00760e8c: { // 0x760e8c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00760e8d: { // 0x760e8d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00760e8e: { // 0x760e8e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00760e8f: { // 0x760e8f: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00760e91: { // 0x760e91: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00760e92: { // 0x760e92: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L00760e95: { // 0x760e95: c21c00 RET 0x1c
    s.arithmetic_flags=flags; finish(m,s,f,28u); return;
  }
}

void f_00360ad0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00760ad0: { // 0x760ad0: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L00760ad3: { // 0x760ad3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00760ad4: { // 0x760ad4: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00760ad5: { // 0x760ad5: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00760ad6: { // 0x760ad6: 8b7c2420 MOV EDI,dword ptr [ESP + 0x20]
    s.di = m.r32((f.sp+0x00000020u));
  }
  L00760ada: { // 0x760ada: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00760adc: { // 0x760adc: 8b4f08 MOV ECX,dword ptr [EDI + 0x8]
    s.cx = m.r32((s.di+0x00000008u));
  }
  L00760adf: { // 0x760adf: 394e08 CMP dword ptr [ESI + 0x8],ECX
    (void)integer::sub(m.r32((s.si+0x00000008u)),s.cx,32,flags);
  }
  L00760ae2: { // 0x760ae2: 0f852e010000 JNZ 0x00760c16
    if(integer::condition("JNZ",flags)) goto L00760c16;
  }
  L00760ae8: { // 0x760ae8: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  L00760aeb: { // 0x760aeb: 8b5f0c MOV EBX,dword ptr [EDI + 0xc]
    s.bx = m.r32((s.di+0x0000000cu));
  }
  L00760aee: { // 0x760aee: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00760af0: { // 0x760af0: 0f8520010000 JNZ 0x00760c16
    if(integer::condition("JNZ",flags)) goto L00760c16;
  }
  L00760af6: { // 0x760af6: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00760af8: { // 0x760af8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760afa: { // 0x760afa: 7d1d JGE 0x00760b19
    if(integer::condition("JGE",flags)) goto L00760b19;
  }
  L00760afc: { // 0x760afc: 8b1f MOV EBX,dword ptr [EDI]
    s.bx = m.r32((s.di));
  }
  L00760afe: { // 0x760afe: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00760b00: { // 0x760b00: 891f MOV dword ptr [EDI],EBX
    m.w32((s.di), s.bx);
  }
  L00760b02: { // 0x760b02: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00760b04: { // 0x760b04: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00760b06: { // 0x760b06: 894708 MOV dword ptr [EDI + 0x8],EAX
    m.w32((s.di+0x00000008u), s.ax);
  }
  L00760b09: { // 0x760b09: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L00760b0b: { // 0x760b0b: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L00760b0e: { // 0x760b0e: c70600000000 MOV dword ptr [ESI],0x0
    m.w32((s.si), 0x00000000u);
  }
  L00760b14: { // 0x760b14: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00760b16: { // 0x760b16: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  L00760b19: { // 0x760b19: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L00760b1c: { // 0x760b1c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760b1e: { // 0x760b1e: 7d25 JGE 0x00760b45
    if(integer::condition("JGE",flags)) goto L00760b45;
  }
  L00760b20: { // 0x760b20: 8b5f04 MOV EBX,dword ptr [EDI + 0x4]
    s.bx = m.r32((s.di+0x00000004u));
  }
  L00760b23: { // 0x760b23: 8b4f0c MOV ECX,dword ptr [EDI + 0xc]
    s.cx = m.r32((s.di+0x0000000cu));
  }
  L00760b26: { // 0x760b26: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00760b28: { // 0x760b28: 895f04 MOV dword ptr [EDI + 0x4],EBX
    m.w32((s.di+0x00000004u), s.bx);
  }
  L00760b2b: { // 0x760b2b: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L00760b2e: { // 0x760b2e: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00760b30: { // 0x760b30: 894f0c MOV dword ptr [EDI + 0xc],ECX
    m.w32((s.di+0x0000000cu), s.cx);
  }
  L00760b33: { // 0x760b33: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  L00760b36: { // 0x760b36: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  L00760b39: { // 0x760b39: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  L00760b40: { // 0x760b40: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00760b42: { // 0x760b42: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  L00760b45: { // 0x760b45: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00760b47: { // 0x760b47: 8b4a08 MOV ECX,dword ptr [EDX + 0x8]
    s.cx = m.r32((s.dx+0x00000008u));
  }
  L00760b4a: { // 0x760b4a: 8b5e08 MOV EBX,dword ptr [ESI + 0x8]
    s.bx = m.r32((s.si+0x00000008u));
  }
  L00760b4d: { // 0x760b4d: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00760b4f: { // 0x760b4f: 03c3 ADD EAX,EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L00760b51: { // 0x760b51: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760b53: { // 0x760b53: 7e10 JLE 0x00760b65
    if(integer::condition("JLE",flags)) goto L00760b65;
  }
  L00760b55: { // 0x760b55: 8b5f08 MOV EBX,dword ptr [EDI + 0x8]
    s.bx = m.r32((s.di+0x00000008u));
  }
  L00760b58: { // 0x760b58: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00760b5a: { // 0x760b5a: 895f08 MOV dword ptr [EDI + 0x8],EBX
    m.w32((s.di+0x00000008u), s.bx);
  }
  L00760b5d: { // 0x760b5d: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L00760b60: { // 0x760b60: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00760b62: { // 0x760b62: 894e08 MOV dword ptr [ESI + 0x8],ECX
    m.w32((s.si+0x00000008u), s.cx);
  }
  L00760b65: { // 0x760b65: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  L00760b68: { // 0x760b68: 8b5a0c MOV EBX,dword ptr [EDX + 0xc]
    s.bx = m.r32((s.dx+0x0000000cu));
  }
  L00760b6b: { // 0x760b6b: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  L00760b6e: { // 0x760b6e: 2bc3 SUB EAX,EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L00760b70: { // 0x760b70: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00760b72: { // 0x760b72: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760b74: { // 0x760b74: 7e10 JLE 0x00760b86
    if(integer::condition("JLE",flags)) goto L00760b86;
  }
  L00760b76: { // 0x760b76: 8b570c MOV EDX,dword ptr [EDI + 0xc]
    s.dx = m.r32((s.di+0x0000000cu));
  }
  L00760b79: { // 0x760b79: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L00760b7b: { // 0x760b7b: 89570c MOV dword ptr [EDI + 0xc],EDX
    m.w32((s.di+0x0000000cu), s.dx);
  }
  L00760b7e: { // 0x760b7e: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  L00760b81: { // 0x760b81: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00760b83: { // 0x760b83: 894e0c MOV dword ptr [ESI + 0xc],ECX
    m.w32((s.si+0x0000000cu), s.cx);
  }
  L00760b86: { // 0x760b86: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L00760b88: { // 0x760b88: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760b8a: { // 0x760b8a: 7d1e JGE 0x00760baa
    if(integer::condition("JGE",flags)) goto L00760baa;
  }
  L00760b8c: { // 0x760b8c: 8b1e MOV EBX,dword ptr [ESI]
    s.bx = m.r32((s.si));
  }
  L00760b8e: { // 0x760b8e: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00760b90: { // 0x760b90: 891e MOV dword ptr [ESI],EBX
    m.w32((s.si), s.bx);
  }
  L00760b92: { // 0x760b92: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L00760b94: { // 0x760b94: 8b5708 MOV EDX,dword ptr [EDI + 0x8]
    s.dx = m.r32((s.di+0x00000008u));
  }
  L00760b97: { // 0x760b97: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00760b99: { // 0x760b99: 895708 MOV dword ptr [EDI + 0x8],EDX
    m.w32((s.di+0x00000008u), s.dx);
  }
  L00760b9c: { // 0x760b9c: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L00760b9f: { // 0x760b9f: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00760ba1: { // 0x760ba1: 894e08 MOV dword ptr [ESI + 0x8],ECX
    m.w32((s.si+0x00000008u), s.cx);
  }
  L00760ba4: { // 0x760ba4: c70700000000 MOV dword ptr [EDI],0x0
    m.w32((s.di), 0x00000000u);
  }
  L00760baa: { // 0x760baa: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  L00760bad: { // 0x760bad: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760baf: { // 0x760baf: 7d22 JGE 0x00760bd3
    if(integer::condition("JGE",flags)) goto L00760bd3;
  }
  L00760bb1: { // 0x760bb1: 8b5e04 MOV EBX,dword ptr [ESI + 0x4]
    s.bx = m.r32((s.si+0x00000004u));
  }
  L00760bb4: { // 0x760bb4: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00760bb6: { // 0x760bb6: 895e04 MOV dword ptr [ESI + 0x4],EBX
    m.w32((s.si+0x00000004u), s.bx);
  }
  L00760bb9: { // 0x760bb9: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  L00760bbc: { // 0x760bbc: 8b570c MOV EDX,dword ptr [EDI + 0xc]
    s.dx = m.r32((s.di+0x0000000cu));
  }
  L00760bbf: { // 0x760bbf: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00760bc1: { // 0x760bc1: 89570c MOV dword ptr [EDI + 0xc],EDX
    m.w32((s.di+0x0000000cu), s.dx);
  }
  L00760bc4: { // 0x760bc4: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  L00760bc7: { // 0x760bc7: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00760bc9: { // 0x760bc9: 894e0c MOV dword ptr [ESI + 0xc],ECX
    m.w32((s.si+0x0000000cu), s.cx);
  }
  L00760bcc: { // 0x760bcc: c7470400000000 MOV dword ptr [EDI + 0x4],0x0
    m.w32((s.di+0x00000004u), 0x00000000u);
  }
  L00760bd3: { // 0x760bd3: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L00760bd7: { // 0x760bd7: 8b4f08 MOV ECX,dword ptr [EDI + 0x8]
    s.cx = m.r32((s.di+0x00000008u));
  }
  L00760bda: { // 0x760bda: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00760bdc: { // 0x760bdc: 8b5a08 MOV EBX,dword ptr [EDX + 0x8]
    s.bx = m.r32((s.dx+0x00000008u));
  }
  L00760bdf: { // 0x760bdf: 2bc3 SUB EAX,EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L00760be1: { // 0x760be1: 8b1f MOV EBX,dword ptr [EDI]
    s.bx = m.r32((s.di));
  }
  L00760be3: { // 0x760be3: 03c3 ADD EAX,EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L00760be5: { // 0x760be5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760be7: { // 0x760be7: 7e0d JLE 0x00760bf6
    if(integer::condition("JLE",flags)) goto L00760bf6;
  }
  L00760be9: { // 0x760be9: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00760beb: { // 0x760beb: 894f08 MOV dword ptr [EDI + 0x8],ECX
    m.w32((s.di+0x00000008u), s.cx);
  }
  L00760bee: { // 0x760bee: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L00760bf1: { // 0x760bf1: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00760bf3: { // 0x760bf3: 894e08 MOV dword ptr [ESI + 0x8],ECX
    m.w32((s.si+0x00000008u), s.cx);
  }
  L00760bf6: { // 0x760bf6: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  L00760bf9: { // 0x760bf9: 8b5a0c MOV EBX,dword ptr [EDX + 0xc]
    s.bx = m.r32((s.dx+0x0000000cu));
  }
  L00760bfc: { // 0x760bfc: 8b4f0c MOV ECX,dword ptr [EDI + 0xc]
    s.cx = m.r32((s.di+0x0000000cu));
  }
  L00760bff: { // 0x760bff: 2bc3 SUB EAX,EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L00760c01: { // 0x760c01: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00760c03: { // 0x760c03: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760c05: { // 0x760c05: 7e63 JLE 0x00760c6a
    if(integer::condition("JLE",flags)) goto L00760c6a;
  }
  L00760c07: { // 0x760c07: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00760c09: { // 0x760c09: 894f0c MOV dword ptr [EDI + 0xc],ECX
    m.w32((s.di+0x0000000cu), s.cx);
  }
  L00760c0c: { // 0x760c0c: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  L00760c0f: { // 0x760c0f: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00760c11: { // 0x760c11: 894e0c MOV dword ptr [ESI + 0xc],ECX
    m.w32((s.si+0x0000000cu), s.cx);
  }
  L00760c14: { // 0x760c14: eb54 JMP 0x00760c6a
    goto L00760c6a;
  }
  L00760c16: { // 0x760c16: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00760c18: { // 0x760c18: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00760c1a: { // 0x760c1a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00760c1b: { // 0x760c1b: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L00760c1d: { // 0x760c1d: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L00760c21: { // 0x760c21: e8caf1cbff CALL 0x0041fdf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041fdf0u,7736358u,op); flags=s.arithmetic_flags;
  }
  L00760c26: { // 0x760c26: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00760c28: { // 0x760c28: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L00760c2a: { // 0x760c2a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00760c2c: { // 0x760c2c: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00760c2e: { // 0x760c2e: 890a MOV dword ptr [EDX],ECX
    m.w32((s.dx), s.cx);
  }
  L00760c30: { // 0x760c30: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L00760c33: { // 0x760c33: 894a04 MOV dword ptr [EDX + 0x4],ECX
    m.w32((s.dx+0x00000004u), s.cx);
  }
  L00760c36: { // 0x760c36: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L00760c39: { // 0x760c39: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  L00760c3c: { // 0x760c3c: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L00760c3f: { // 0x760c3f: 8b4c242c MOV ECX,dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L00760c43: { // 0x760c43: 89420c MOV dword ptr [EDX + 0xc],EAX
    m.w32((s.dx+0x0000000cu), s.ax);
  }
  L00760c46: { // 0x760c46: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00760c47: { // 0x760c47: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  L00760c49: { // 0x760c49: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L00760c4d: { // 0x760c4d: e89ef1cbff CALL 0x0041fdf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041fdf0u,7736402u,op); flags=s.arithmetic_flags;
  }
  L00760c52: { // 0x760c52: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00760c54: { // 0x760c54: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  L00760c56: { // 0x760c56: 890a MOV dword ptr [EDX],ECX
    m.w32((s.dx), s.cx);
  }
  L00760c58: { // 0x760c58: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L00760c5b: { // 0x760c5b: 894a04 MOV dword ptr [EDX + 0x4],ECX
    m.w32((s.dx+0x00000004u), s.cx);
  }
  L00760c5e: { // 0x760c5e: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L00760c61: { // 0x760c61: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  L00760c64: { // 0x760c64: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L00760c67: { // 0x760c67: 89420c MOV dword ptr [EDX + 0xc],EAX
    m.w32((s.dx+0x0000000cu), s.ax);
  }
  L00760c6a: { // 0x760c6a: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L00760c6d: { // 0x760c6d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760c6f: { // 0x760c6f: 7e23 JLE 0x00760c94
    if(integer::condition("JLE",flags)) goto L00760c94;
  }
  L00760c71: { // 0x760c71: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  L00760c74: { // 0x760c74: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760c76: { // 0x760c76: 7e1c JLE 0x00760c94
    if(integer::condition("JLE",flags)) goto L00760c94;
  }
  L00760c78: { // 0x760c78: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  L00760c7b: { // 0x760c7b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760c7d: { // 0x760c7d: 7e15 JLE 0x00760c94
    if(integer::condition("JLE",flags)) goto L00760c94;
  }
  L00760c7f: { // 0x760c7f: 8b470c MOV EAX,dword ptr [EDI + 0xc]
    s.ax = m.r32((s.di+0x0000000cu));
  }
  L00760c82: { // 0x760c82: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760c84: { // 0x760c84: 7e0e JLE 0x00760c94
    if(integer::condition("JLE",flags)) goto L00760c94;
  }
  L00760c86: { // 0x760c86: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00760c87: { // 0x760c87: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00760c88: { // 0x760c88: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L00760c8d: { // 0x760c8d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00760c8e: { // 0x760c8e: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00760c91: { // 0x760c91: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L00760c94: { // 0x760c94: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00760c95: { // 0x760c95: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00760c96: { // 0x760c96: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00760c98: { // 0x760c98: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00760c99: { // 0x760c99: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00760c9c: { // 0x760c9c: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}

void f_00035420(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00435420: { // 0x435420: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L00435424: { // 0x435424: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00435426: { // 0x435426: 8b4904 MOV ECX,dword ptr [ECX + 0x4]
    s.cx = m.r32((s.cx+0x00000004u));
  }
  L00435429: { // 0x435429: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L0043542b: { // 0x43542b: 894804 MOV dword ptr [EAX + 0x4],ECX
    m.w32((s.ax+0x00000004u), s.cx);
  }
  L0043542e: { // 0x43542e: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_00035400(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00435400: { // 0x435400: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L00435404: { // 0x435404: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00435405: { // 0x435405: 8b31 MOV ESI,dword ptr [ECX]
    s.si = m.r32((s.cx));
  }
  L00435407: { // 0x435407: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00435409: { // 0x435409: 03d6 ADD EDX,ESI
    s.dx = integer::add(s.dx,s.si,32,flags);
  }
  L0043540b: { // 0x43540b: 8b7004 MOV ESI,dword ptr [EAX + 0x4]
    s.si = m.r32((s.ax+0x00000004u));
  }
  L0043540e: { // 0x43540e: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L00435411: { // 0x435411: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L00435413: { // 0x435413: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L00435417: { // 0x435417: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L00435419: { // 0x435419: 897004 MOV dword ptr [EAX + 0x4],ESI
    m.w32((s.ax+0x00000004u), s.si);
  }
  L0043541c: { // 0x43541c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0043541d: { // 0x43541d: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}

void f_00361440(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00761440: { // 0x761440: 8b44240c MOV EAX, dword ptr [ESP + 0xC]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L00761444: { // 0x761444: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00761446: { // 0x761446: 7e20 JLE 0x761468
    if(integer::condition("JLE",flags)) goto L00761468;
  }
  L00761448: { // 0x761448: 8b4c2408 MOV ECX, dword ptr [ESP + 8]
    s.cx = m.r32((f.sp+8u));
  }
  L0076144c: { // 0x76144c: 8b542404 MOV EDX, dword ptr [ESP + 4]
    s.dx = m.r32((f.sp+4u));
  }
  L00761450: { // 0x761450: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00761451: { // 0x761451: 8bf0 MOV ESI, EAX
    s.si = s.ax;
  }
  L00761453: { // 0x761453: 668b01 MOV AX, word ptr [ECX]
    s.ax = with_ax(s.ax, m.r16((s.cx)));
  }
  L00761456: { // 0x761456: 83c102 ADD ECX, 2
    s.cx = integer::add(s.cx,2u,32,flags);
  }
  L00761459: { // 0x761459: 6685c0 TEST AX, AX
    (void)integer::logical(((s.ax & 0xffffu))&((s.ax & 0xffffu)),16,flags);
  }
  L0076145c: { // 0x76145c: 7403 JZ 0x761461
    if(integer::condition("JZ",flags)) goto L00761461;
  }
  L0076145e: { // 0x76145e: 668902 MOV word ptr [EDX], AX
    m.w16((s.dx), (s.ax & 0xffffu));
  }
  L00761461: { // 0x761461: 83c202 ADD EDX, 2
    s.dx = integer::add(s.dx,2u,32,flags);
  }
  L00761464: { // 0x761464: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L00761465: { // 0x761465: 75ec JNZ 0x761453
    if(integer::condition("JNZ",flags)) goto L00761453;
  }
  L00761467: { // 0x761467: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00761468: { // 0x761468: c22000 RET 0x20
    s.arithmetic_flags=flags; finish(m,s,f,32u); return;
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

void f_000ab230(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004ab230: { // 0x4ab230: 81ecb4000000 SUB ESP,0xb4
    f.sp = integer::sub(f.sp,0x000000b4u,32,flags);
  }
  L004ab236: { // 0x4ab236: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004ab237: { // 0x4ab237: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004ab238: { // 0x4ab238: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004ab23a: { // 0x4ab23a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004ab23b: { // 0x4ab23b: 8b461c MOV EAX,dword ptr [ESI + 0x1c]
    s.ax = m.r32((s.si+0x0000001cu));
  }
  L004ab23e: { // 0x4ab23e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004ab240: { // 0x4ab240: 0f84ea010000 JZ 0x004ab430
    if(integer::condition("JZ",flags)) goto L004ab430;
  }
  L004ab246: { // 0x4ab246: 8bbc24c8000000 MOV EDI,dword ptr [ESP + 0xc8]
    s.di = m.r32((f.sp+0x000000c8u));
  }
  L004ab24d: { // 0x4ab24d: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  L004ab250: { // 0x4ab250: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004ab252: { // 0x4ab252: 0f8ed8010000 JLE 0x004ab430
    if(integer::condition("JLE",flags)) goto L004ab430;
  }
  L004ab258: { // 0x4ab258: 8b470c MOV EAX,dword ptr [EDI + 0xc]
    s.ax = m.r32((s.di+0x0000000cu));
  }
  L004ab25b: { // 0x4ab25b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004ab25d: { // 0x4ab25d: 0f8ecd010000 JLE 0x004ab430
    if(integer::condition("JLE",flags)) goto L004ab430;
  }
  L004ab263: { // 0x4ab263: a0c4137c00 MOV AL,[0x007c13c4]
    s.ax = with_al(s.ax, m.r8((0x007c13c4u)));
  }
  L004ab268: { // 0x4ab268: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004ab26a: { // 0x4ab26a: 0f849c010000 JZ 0x004ab40c
    if(integer::condition("JZ",flags)) goto L004ab40c;
  }
  L004ab270: { // 0x4ab270: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004ab272: { // 0x4ab272: ff506c CALL dword ptr [EAX + 0x6c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000006cu)),4895349u,op); flags=s.arithmetic_flags;
  }
  L004ab275: { // 0x4ab275: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004ab277: { // 0x4ab277: 0f858f010000 JNZ 0x004ab40c
    if(integer::condition("JNZ",flags)) goto L004ab40c;
  }
  L004ab27d: { // 0x4ab27d: 8b461c MOV EAX,dword ptr [ESI + 0x1c]
    s.ax = m.r32((s.si+0x0000001cu));
  }
  L004ab280: { // 0x4ab280: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L004ab282: { // 0x4ab282: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004ab283: { // 0x4ab283: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L004ab285: { // 0x4ab285: ff5134 CALL dword ptr [ECX + 0x34]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+0x00000034u)),4895368u,op); flags=s.arithmetic_flags;
  }
  L004ab288: { // 0x4ab288: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004ab28a: { // 0x4ab28a: 0f857c010000 JNZ 0x004ab40c
    if(integer::condition("JNZ",flags)) goto L004ab40c;
  }
  L004ab290: { // 0x4ab290: a0e09f8300 MOV AL,[0x00839fe0]
    s.ax = with_al(s.ax, m.r8((0x00839fe0u)));
  }
  L004ab295: { // 0x4ab295: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004ab297: { // 0x4ab297: 750d JNZ 0x004ab2a6
    if(integer::condition("JNZ",flags)) goto L004ab2a6;
  }
  L004ab299: { // 0x4ab299: a06889a200 MOV AL,[0x00a28968]
    s.ax = with_al(s.ax, m.r8((0x00a28968u)));
  }
  L004ab29e: { // 0x4ab29e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004ab2a0: { // 0x4ab2a0: 0f848a010000 JZ 0x004ab430
    if(integer::condition("JZ",flags)) goto L004ab430;
  }
  L004ab2a6: { // 0x4ab2a6: 8b461c MOV EAX,dword ptr [ESI + 0x1c]
    s.ax = m.r32((s.si+0x0000001cu));
  }
  L004ab2a9: { // 0x4ab2a9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004ab2ab: { // 0x4ab2ab: 7455 JZ 0x004ab302
    if(integer::condition("JZ",flags)) goto L004ab302;
  }
  L004ab2ad: { // 0x4ab2ad: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L004ab2af: { // 0x4ab2af: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004ab2b0: { // 0x4ab2b0: ff5260 CALL dword ptr [EDX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),4895411u,op); flags=s.arithmetic_flags;
  }
  L004ab2b3: { // 0x4ab2b3: 3dc2017688 CMP EAX,0x887601c2
    (void)integer::sub(s.ax,0x887601c2u,32,flags);
  }
  L004ab2b8: { // 0x4ab2b8: 7548 JNZ 0x004ab302
    if(integer::condition("JNZ",flags)) goto L004ab302;
  }
  L004ab2ba: { // 0x4ab2ba: 8b461c MOV EAX,dword ptr [ESI + 0x1c]
    s.ax = m.r32((s.si+0x0000001cu));
  }
  L004ab2bd: { // 0x4ab2bd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004ab2be: { // 0x4ab2be: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L004ab2c0: { // 0x4ab2c0: ff516c CALL dword ptr [ECX + 0x6c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+0x0000006cu)),4895427u,op); flags=s.arithmetic_flags;
  }
  L004ab2c3: { // 0x4ab2c3: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004ab2c5: { // 0x4ab2c5: 0f8565010000 JNZ 0x004ab430
    if(integer::condition("JNZ",flags)) goto L004ab430;
  }
  L004ab2cb: { // 0x4ab2cb: 8b461c MOV EAX,dword ptr [ESI + 0x1c]
    s.ax = m.r32((s.si+0x0000001cu));
  }
  L004ab2ce: { // 0x4ab2ce: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004ab2cf: { // 0x4ab2cf: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L004ab2d1: { // 0x4ab2d1: ff5260 CALL dword ptr [EDX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),4895444u,op); flags=s.arithmetic_flags;
  }
  L004ab2d4: { // 0x4ab2d4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004ab2d6: { // 0x4ab2d6: 0f8554010000 JNZ 0x004ab430
    if(integer::condition("JNZ",flags)) goto L004ab430;
  }
  L004ab2dc: { // 0x4ab2dc: 8b5e0c MOV EBX,dword ptr [ESI + 0xc]
    s.bx = m.r32((s.si+0x0000000cu));
  }
  L004ab2df: { // 0x4ab2df: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L004ab2e1: { // 0x4ab2e1: 7e1f JLE 0x004ab302
    if(integer::condition("JLE",flags)) goto L004ab302;
  }
  L004ab2e3: { // 0x4ab2e3: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004ab2e5: { // 0x4ab2e5: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L004ab2e7: { // 0x4ab2e7: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004ab2e8: { // 0x4ab2e8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004ab2e9: { // 0x4ab2e9: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004ab2eb: { // 0x4ab2eb: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  L004ab2ee: { // 0x4ab2ee: ff525c CALL dword ptr [EDX + 0x5c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000005cu)),4895473u,op); flags=s.arithmetic_flags;
  }
  L004ab2f1: { // 0x4ab2f1: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  L004ab2f4: { // 0x4ab2f4: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004ab2f6: { // 0x4ab2f6: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004ab2f7: { // 0x4ab2f7: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  L004ab2fa: { // 0x4ab2fa: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004ab2fc: { // 0x4ab2fc: ff5060 CALL dword ptr [EAX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000060u)),4895487u,op); flags=s.arithmetic_flags;
  }
  L004ab2ff: { // 0x4ab2ff: 895e0c MOV dword ptr [ESI + 0xc],EBX
    m.w32((s.si+0x0000000cu), s.bx);
  }
  L004ab302: { // 0x4ab302: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004ab304: { // 0x4ab304: 8d44244c LEA EAX,[ESP + 0x4c]
    s.ax = (f.sp+0x0000004cu);
  }
  L004ab308: { // 0x4ab308: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004ab309: { // 0x4ab309: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004ab30b: { // 0x4ab30b: ff5278 CALL dword ptr [EDX + 0x78]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000078u)),4895502u,op); flags=s.arithmetic_flags;
  }
  L004ab30e: { // 0x4ab30e: 8b9c24c4000000 MOV EBX,dword ptr [ESP + 0xc4]
    s.bx = m.r32((f.sp+0x000000c4u));
  }
  L004ab315: { // 0x4ab315: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L004ab317: { // 0x4ab317: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L004ab319: { // 0x4ab319: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004ab31a: { // 0x4ab31a: 8bd3 MOV EDX,EBX
    s.dx = s.bx;
  }
  L004ab31c: { // 0x4ab31c: 8d4c2448 LEA ECX,[ESP + 0x48]
    s.cx = (f.sp+0x00000048u);
  }
  L004ab320: { // 0x4ab320: e8cb4af7ff CALL 0x0041fdf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041fdf0u,4895525u,op); flags=s.arithmetic_flags;
  }
  L004ab325: { // 0x4ab325: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L004ab327: { // 0x4ab327: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L004ab329: { // 0x4ab329: 894c2430 MOV dword ptr [ESP + 0x30],ECX
    m.w32((f.sp+0x00000030u), s.cx);
  }
  L004ab32d: { // 0x4ab32d: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L004ab32f: { // 0x4ab32f: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L004ab332: { // 0x4ab332: 89542438 MOV dword ptr [ESP + 0x38],EDX
    m.w32((f.sp+0x00000038u), s.dx);
  }
  L004ab336: { // 0x4ab336: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L004ab339: { // 0x4ab339: 894c243c MOV dword ptr [ESP + 0x3c],ECX
    m.w32((f.sp+0x0000003cu), s.cx);
  }
  L004ab33d: { // 0x4ab33d: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  L004ab33f: { // 0x4ab33f: 8b500c MOV EDX,dword ptr [EAX + 0xc]
    s.dx = m.r32((s.ax+0x0000000cu));
  }
  L004ab342: { // 0x4ab342: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L004ab344: { // 0x4ab344: 8b5b04 MOV EBX,dword ptr [EBX + 0x4]
    s.bx = m.r32((s.bx+0x00000004u));
  }
  L004ab347: { // 0x4ab347: 89542440 MOV dword ptr [ESP + 0x40],EDX
    m.w32((f.sp+0x00000040u), s.dx);
  }
  L004ab34b: { // 0x4ab34b: 8b5704 MOV EDX,dword ptr [EDI + 0x4]
    s.dx = m.r32((s.di+0x00000004u));
  }
  L004ab34e: { // 0x4ab34e: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L004ab350: { // 0x4ab350: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L004ab354: { // 0x4ab354: 8d442434 LEA EAX,[ESP + 0x34]
    s.ax = (f.sp+0x00000034u);
  }
  L004ab358: { // 0x4ab358: 8d0c13 LEA ECX,[EBX + EDX*0x1]
    s.cx = (s.bx+(s.dx * 0x00000001u));
  }
  L004ab35b: { // 0x4ab35b: 8b5708 MOV EDX,dword ptr [EDI + 0x8]
    s.dx = m.r32((s.di+0x00000008u));
  }
  L004ab35e: { // 0x4ab35e: 8b7f0c MOV EDI,dword ptr [EDI + 0xc]
    s.di = m.r32((s.di+0x0000000cu));
  }
  L004ab361: { // 0x4ab361: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L004ab365: { // 0x4ab365: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L004ab369: { // 0x4ab369: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004ab36a: { // 0x4ab36a: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L004ab36e: { // 0x4ab36e: 8d4c2448 LEA ECX,[ESP + 0x48]
    s.cx = (f.sp+0x00000048u);
  }
  L004ab372: { // 0x4ab372: 897c2424 MOV dword ptr [ESP + 0x24],EDI
    m.w32((f.sp+0x00000024u), s.di);
  }
  L004ab376: { // 0x4ab376: e8754af7ff CALL 0x0041fdf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041fdf0u,4895611u,op); flags=s.arithmetic_flags;
  }
  L004ab37b: { // 0x4ab37b: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L004ab37d: { // 0x4ab37d: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  L004ab37f: { // 0x4ab37f: 894c240c MOV dword ptr [ESP + 0xc],ECX
    m.w32((f.sp+0x0000000cu), s.cx);
  }
  L004ab383: { // 0x4ab383: 8b5704 MOV EDX,dword ptr [EDI + 0x4]
    s.dx = m.r32((s.di+0x00000004u));
  }
  L004ab386: { // 0x4ab386: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L004ab38a: { // 0x4ab38a: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  L004ab38d: { // 0x4ab38d: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L004ab391: { // 0x4ab391: 8b7f0c MOV EDI,dword ptr [EDI + 0xc]
    s.di = m.r32((s.di+0x0000000cu));
  }
  L004ab394: { // 0x4ab394: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004ab396: { // 0x4ab396: 897c2418 MOV dword ptr [ESP + 0x18],EDI
    m.w32((f.sp+0x00000018u), s.di);
  }
  L004ab39a: { // 0x4ab39a: 0f8e90000000 JLE 0x004ab430
    if(integer::condition("JLE",flags)) goto L004ab430;
  }
  L004ab3a0: { // 0x4ab3a0: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L004ab3a2: { // 0x4ab3a2: 0f8e88000000 JLE 0x004ab430
    if(integer::condition("JLE",flags)) goto L004ab430;
  }
  L004ab3a8: { // 0x4ab3a8: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L004ab3aa: { // 0x4ab3aa: 03fa ADD EDI,EDX
    s.di = integer::add(s.di,s.dx,32,flags);
  }
  L004ab3ac: { // 0x4ab3ac: 8b761c MOV ESI,dword ptr [ESI + 0x1c]
    s.si = m.r32((s.si+0x0000001cu));
  }
  L004ab3af: { // 0x4ab3af: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L004ab3b3: { // 0x4ab3b3: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L004ab3b7: { // 0x4ab3b7: 897c2428 MOV dword ptr [ESP + 0x28],EDI
    m.w32((f.sp+0x00000028u), s.di);
  }
  L004ab3bb: { // 0x4ab3bb: b919000000 MOV ECX,0x19
    s.cx = 0x00000019u;
  }
  L004ab3c0: { // 0x4ab3c0: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004ab3c2: { // 0x4ab3c2: 8d7c245c LEA EDI,[ESP + 0x5c]
    s.di = (f.sp+0x0000005cu);
  }
  L004ab3c6: { // 0x4ab3c6: 89542420 MOV dword ptr [ESP + 0x20],EDX
    m.w32((f.sp+0x00000020u), s.dx);
  }
  L004ab3ca: { // 0x4ab3ca: f3ab STOSD.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::count);
  }
  L004ab3cc: { // 0x4ab3cc: 8b8c24cc000000 MOV ECX,dword ptr [ESP + 0xcc]
    s.cx = m.r32((f.sp+0x000000ccu));
  }
  L004ab3d3: { // 0x4ab3d3: 8d44245c LEA EAX,[ESP + 0x5c]
    s.ax = (f.sp+0x0000005cu);
  }
  L004ab3d7: { // 0x4ab3d7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004ab3d8: { // 0x4ab3d8: 898c24b0000000 MOV dword ptr [ESP + 0xb0],ECX
    m.w32((f.sp+0x000000b0u), s.cx);
  }
  L004ab3df: { // 0x4ab3df: 6800040001 PUSH 0x1000400
    f.push(m,0x01000400u);
  }
  L004ab3e4: { // 0x4ab3e4: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L004ab3e6: { // 0x4ab3e6: 8d4c2428 LEA ECX,[ESP + 0x28]
    s.cx = (f.sp+0x00000028u);
  }
  L004ab3ea: { // 0x4ab3ea: c744246864000000 MOV dword ptr [ESP + 0x68],0x64
    m.w32((f.sp+0x00000068u), 0x00000064u);
  }
  L004ab3f2: { // 0x4ab3f2: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004ab3f4: { // 0x4ab3f4: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L004ab3f6: { // 0x4ab3f6: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004ab3f7: { // 0x4ab3f7: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004ab3f8: { // 0x4ab3f8: ff5214 CALL dword ptr [EDX + 0x14]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000014u)),4895739u,op); flags=s.arithmetic_flags;
  }
  L004ab3fb: { // 0x4ab3fb: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L004ab3fd: { // 0x4ab3fd: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  L004ab3ff: { // 0x4ab3ff: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004ab400: { // 0x4ab400: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004ab401: { // 0x4ab401: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004ab402: { // 0x4ab402: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004ab403: { // 0x4ab403: 81c4b4000000 ADD ESP,0xb4
    f.sp = integer::add(f.sp,0x000000b4u,32,flags);
  }
  L004ab409: { // 0x4ab409: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L004ab40c: { // 0x4ab40c: 8b9424cc000000 MOV EDX,dword ptr [ESP + 0xcc]
    s.dx = m.r32((f.sp+0x000000ccu));
  }
  L004ab413: { // 0x4ab413: 8b8424c4000000 MOV EAX,dword ptr [ESP + 0xc4]
    s.ax = m.r32((f.sp+0x000000c4u));
  }
  L004ab41a: { // 0x4ab41a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004ab41b: { // 0x4ab41b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004ab41c: { // 0x4ab41c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004ab41d: { // 0x4ab41d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004ab41f: { // 0x4ab41f: e8dc482b00 CALL 0x0075fd00
    s.arithmetic_flags=flags; invoke(m,s,f,0x0075fd00u,4895780u,op); flags=s.arithmetic_flags;
  }
  L004ab424: { // 0x4ab424: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004ab425: { // 0x4ab425: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004ab426: { // 0x4ab426: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004ab427: { // 0x4ab427: 81c4b4000000 ADD ESP,0xb4
    f.sp = integer::add(f.sp,0x000000b4u,32,flags);
  }
  L004ab42d: { // 0x4ab42d: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L004ab430: { // 0x4ab430: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004ab431: { // 0x4ab431: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004ab432: { // 0x4ab432: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004ab434: { // 0x4ab434: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004ab435: { // 0x4ab435: 81c4b4000000 ADD ESP,0xb4
    f.sp = integer::add(f.sp,0x000000b4u,32,flags);
  }
  L004ab43b: { // 0x4ab43b: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }


}

void f_0035fa70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0075fa70: { // 0x75fa70: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  L0075fa73: { // 0x75fa73: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L0075fa77: { // 0x75fa77: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0075fa78: { // 0x75fa78: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0075fa79: { // 0x75fa79: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0075fa7b: { // 0x75fa7b: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0075fa7d: { // 0x75fa7d: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0075fa80: { // 0x75fa80: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0075fa81: { // 0x75fa81: 8b7808 MOV EDI,dword ptr [EAX + 0x8]
    s.di = m.r32((s.ax+0x00000008u));
  }
  L0075fa84: { // 0x75fa84: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L0075fa87: { // 0x75fa87: 8b5c2430 MOV EBX,dword ptr [ESP + 0x30]
    s.bx = m.r32((f.sp+0x00000030u));
  }
  L0075fa8b: { // 0x75fa8b: 8d7c0fff LEA EDI,[EDI + ECX*0x1 + -0x1]
    s.di = (s.di+(s.cx * 0x00000001u)-0x00000001u);
  }
  L0075fa8f: { // 0x75fa8f: 894c240c MOV dword ptr [ESP + 0xc],ECX
    m.w32((f.sp+0x0000000cu), s.cx);
  }
  L0075fa93: { // 0x75fa93: 8d4410ff LEA EAX,[EAX + EDX*0x1 + -0x1]
    s.ax = (s.ax+(s.dx * 0x00000001u)-0x00000001u);
  }
  L0075fa97: { // 0x75fa97: 897c2414 MOV dword ptr [ESP + 0x14],EDI
    m.w32((f.sp+0x00000014u), s.di);
  }
  L0075fa9b: { // 0x75fa9b: 897c241c MOV dword ptr [ESP + 0x1c],EDI
    m.w32((f.sp+0x0000001cu), s.di);
  }
  L0075fa9f: { // 0x75fa9f: 8b7c2438 MOV EDI,dword ptr [ESP + 0x38]
    s.di = m.r32((f.sp+0x00000038u));
  }
  L0075faa3: { // 0x75faa3: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L0075faa7: { // 0x75faa7: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L0075faab: { // 0x75faab: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L0075faaf: { // 0x75faaf: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L0075fab3: { // 0x75fab3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0075fab4: { // 0x75fab4: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L0075fab8: { // 0x75fab8: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L0075fabc: { // 0x75fabc: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L0075fac0: { // 0x75fac0: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0075fac2: { // 0x75fac2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0075fac3: { // 0x75fac3: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0075fac4: { // 0x75fac4: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0075fac5: { // 0x75fac5: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0075fac7: { // 0x75fac7: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),7731914u,op); flags=s.arithmetic_flags;
  }
  L0075faca: { // 0x75faca: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0075facc: { // 0x75facc: 8d442424 LEA EAX,[ESP + 0x24]
    s.ax = (f.sp+0x00000024u);
  }
  L0075fad0: { // 0x75fad0: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0075fad1: { // 0x75fad1: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L0075fad5: { // 0x75fad5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0075fad6: { // 0x75fad6: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0075fad7: { // 0x75fad7: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0075fad8: { // 0x75fad8: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0075fada: { // 0x75fada: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),7731933u,op); flags=s.arithmetic_flags;
  }
  L0075fadd: { // 0x75fadd: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0075fadf: { // 0x75fadf: 8d44241c LEA EAX,[ESP + 0x1c]
    s.ax = (f.sp+0x0000001cu);
  }
  L0075fae3: { // 0x75fae3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0075fae4: { // 0x75fae4: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0075fae8: { // 0x75fae8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0075fae9: { // 0x75fae9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0075faea: { // 0x75faea: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0075faeb: { // 0x75faeb: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0075faed: { // 0x75faed: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),7731952u,op); flags=s.arithmetic_flags;
  }
  L0075faf0: { // 0x75faf0: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0075faf2: { // 0x75faf2: 8d44241c LEA EAX,[ESP + 0x1c]
    s.ax = (f.sp+0x0000001cu);
  }
  L0075faf6: { // 0x75faf6: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0075faf7: { // 0x75faf7: 8d4c2428 LEA ECX,[ESP + 0x28]
    s.cx = (f.sp+0x00000028u);
  }
  L0075fafb: { // 0x75fafb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0075fafc: { // 0x75fafc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0075fafd: { // 0x75fafd: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0075fafe: { // 0x75fafe: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0075fb00: { // 0x75fb00: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),7731971u,op); flags=s.arithmetic_flags;
  }
  L0075fb03: { // 0x75fb03: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0075fb04: { // 0x75fb04: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0075fb05: { // 0x75fb05: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0075fb07: { // 0x75fb07: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0075fb08: { // 0x75fb08: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L0075fb0b: { // 0x75fb0b: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}

void f_0035fd00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0075fd00: { // 0x75fd00: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0075fd01: { // 0x75fd01: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L0075fd03: { // 0x75fd03: 83ec6c SUB ESP,0x6c
    f.sp = integer::sub(f.sp,0x0000006cu,32,flags);
  }
  L0075fd06: { // 0x75fd06: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0075fd07: { // 0x75fd07: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0075fd08: { // 0x75fd08: 8b750c MOV ESI,dword ptr [EBP + 0xc]
    s.si = m.r32((s.bp+0x0000000cu));
  }
  L0075fd0b: { // 0x75fd0b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0075fd0c: { // 0x75fd0c: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0075fd0e: { // 0x75fd0e: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L0075fd11: { // 0x75fd11: 897dfc MOV dword ptr [EBP + -0x4],EDI
    m.w32((s.bp-0x00000004u), s.di);
  }
  L0075fd14: { // 0x75fd14: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0075fd16: { // 0x75fd16: 0f8ec5020000 JLE 0x0075ffe1
    if(integer::condition("JLE",flags)) goto L0075ffe1;
  }
  L0075fd1c: { // 0x75fd1c: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  L0075fd1f: { // 0x75fd1f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0075fd21: { // 0x75fd21: 0f8eba020000 JLE 0x0075ffe1
    if(integer::condition("JLE",flags)) goto L0075ffe1;
  }
  L0075fd27: { // 0x75fd27: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L0075fd29: { // 0x75fd29: 8d4db4 LEA ECX,[EBP + -0x4c]
    s.cx = (s.bp-0x0000004cu);
  }
  L0075fd2c: { // 0x75fd2c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0075fd2d: { // 0x75fd2d: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0075fd2f: { // 0x75fd2f: ff5078 CALL dword ptr [EAX + 0x78]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000078u)),7732530u,op); flags=s.arithmetic_flags;
  }
  L0075fd32: { // 0x75fd32: 8b5d08 MOV EBX,dword ptr [EBP + 0x8]
    s.bx = m.r32((s.bp+0x00000008u));
  }
  L0075fd35: { // 0x75fd35: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0075fd37: { // 0x75fd37: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0075fd39: { // 0x75fd39: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0075fd3a: { // 0x75fd3a: 8bd3 MOV EDX,EBX
    s.dx = s.bx;
  }
  L0075fd3c: { // 0x75fd3c: 8d4de4 LEA ECX,[EBP + -0x1c]
    s.cx = (s.bp-0x0000001cu);
  }
  L0075fd3f: { // 0x75fd3f: e8ac00ccff CALL 0x0041fdf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041fdf0u,7732548u,op); flags=s.arithmetic_flags;
  }
  L0075fd44: { // 0x75fd44: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0075fd46: { // 0x75fd46: 8955c4 MOV dword ptr [EBP + -0x3c],EDX
    m.w32((s.bp-0x0000003cu), s.dx);
  }
  L0075fd49: { // 0x75fd49: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L0075fd4c: { // 0x75fd4c: 894dc8 MOV dword ptr [EBP + -0x38],ECX
    m.w32((s.bp-0x00000038u), s.cx);
  }
  L0075fd4f: { // 0x75fd4f: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0075fd51: { // 0x75fd51: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L0075fd54: { // 0x75fd54: 8955cc MOV dword ptr [EBP + -0x34],EDX
    m.w32((s.bp-0x00000034u), s.dx);
  }
  L0075fd57: { // 0x75fd57: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  L0075fd5a: { // 0x75fd5a: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L0075fd5d: { // 0x75fd5d: 8945d0 MOV dword ptr [EBP + -0x30],EAX
    m.w32((s.bp-0x00000030u), s.ax);
  }
  L0075fd60: { // 0x75fd60: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L0075fd62: { // 0x75fd62: 8b5b04 MOV EBX,dword ptr [EBX + 0x4]
    s.bx = m.r32((s.bx+0x00000004u));
  }
  L0075fd65: { // 0x75fd65: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0075fd67: { // 0x75fd67: 8945ec MOV dword ptr [EBP + -0x14],EAX
    m.w32((s.bp-0x00000014u), s.ax);
  }
  L0075fd6a: { // 0x75fd6a: 8d45ec LEA EAX,[EBP + -0x14]
    s.ax = (s.bp-0x00000014u);
  }
  L0075fd6d: { // 0x75fd6d: 8d0c1a LEA ECX,[EDX + EBX*0x1]
    s.cx = (s.dx+(s.bx * 0x00000001u));
  }
  L0075fd70: { // 0x75fd70: 8b5608 MOV EDX,dword ptr [ESI + 0x8]
    s.dx = m.r32((s.si+0x00000008u));
  }
  L0075fd73: { // 0x75fd73: 894df0 MOV dword ptr [EBP + -0x10],ECX
    m.w32((s.bp-0x00000010u), s.cx);
  }
  L0075fd76: { // 0x75fd76: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  L0075fd79: { // 0x75fd79: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0075fd7a: { // 0x75fd7a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0075fd7b: { // 0x75fd7b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0075fd7c: { // 0x75fd7c: 8d4da4 LEA ECX,[EBP + -0x5c]
    s.cx = (s.bp-0x0000005cu);
  }
  L0075fd7f: { // 0x75fd7f: e82c3dcfff CALL 0x00453ab0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00453ab0u,7732612u,op); flags=s.arithmetic_flags;
  }
  L0075fd84: { // 0x75fd84: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0075fd86: { // 0x75fd86: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0075fd88: { // 0x75fd88: 894db4 MOV dword ptr [EBP + -0x4c],ECX
    m.w32((s.bp-0x0000004cu), s.cx);
  }
  L0075fd8b: { // 0x75fd8b: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0075fd8d: { // 0x75fd8d: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0075fd90: { // 0x75fd90: 8955b8 MOV dword ptr [EBP + -0x48],EDX
    m.w32((s.bp-0x00000048u), s.dx);
  }
  L0075fd93: { // 0x75fd93: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L0075fd96: { // 0x75fd96: 894dbc MOV dword ptr [EBP + -0x44],ECX
    m.w32((s.bp-0x00000044u), s.cx);
  }
  L0075fd99: { // 0x75fd99: 8d4d94 LEA ECX,[EBP + -0x6c]
    s.cx = (s.bp-0x0000006cu);
  }
  L0075fd9c: { // 0x75fd9c: 8b500c MOV EDX,dword ptr [EAX + 0xc]
    s.dx = m.r32((s.ax+0x0000000cu));
  }
  L0075fd9f: { // 0x75fd9f: 8d45b4 LEA EAX,[EBP + -0x4c]
    s.ax = (s.bp-0x0000004cu);
  }
  L0075fda2: { // 0x75fda2: 8955c0 MOV dword ptr [EBP + -0x40],EDX
    m.w32((s.bp-0x00000040u), s.dx);
  }
  L0075fda5: { // 0x75fda5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0075fda6: { // 0x75fda6: 8d55c4 LEA EDX,[EBP + -0x3c]
    s.dx = (s.bp-0x0000003cu);
  }
  L0075fda9: { // 0x75fda9: e84200ccff CALL 0x0041fdf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041fdf0u,7732654u,op); flags=s.arithmetic_flags;
  }
  L0075fdae: { // 0x75fdae: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0075fdb0: { // 0x75fdb0: 894dd4 MOV dword ptr [EBP + -0x2c],ECX
    m.w32((s.bp-0x0000002cu), s.cx);
  }
  L0075fdb3: { // 0x75fdb3: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0075fdb6: { // 0x75fdb6: 8955d8 MOV dword ptr [EBP + -0x28],EDX
    m.w32((s.bp-0x00000028u), s.dx);
  }
  L0075fdb9: { // 0x75fdb9: 8b5808 MOV EBX,dword ptr [EAX + 0x8]
    s.bx = m.r32((s.ax+0x00000008u));
  }
  L0075fdbc: { // 0x75fdbc: 895ddc MOV dword ptr [EBP + -0x24],EBX
    m.w32((s.bp-0x00000024u), s.bx);
  }
  L0075fdbf: { // 0x75fdbf: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L0075fdc2: { // 0x75fdc2: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L0075fdc4: { // 0x75fdc4: 8945e0 MOV dword ptr [EBP + -0x20],EAX
    m.w32((s.bp-0x00000020u), s.ax);
  }
  L0075fdc7: { // 0x75fdc7: 0f8e14020000 JLE 0x0075ffe1
    if(integer::condition("JLE",flags)) goto L0075ffe1;
  }
  L0075fdcd: { // 0x75fdcd: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0075fdcf: { // 0x75fdcf: 0f8e0c020000 JLE 0x0075ffe1
    if(integer::condition("JLE",flags)) goto L0075ffe1;
  }
  L0075fdd5: { // 0x75fdd5: 894508 MOV dword ptr [EBP + 0x8],EAX
    m.w32((s.bp+0x00000008u), s.ax);
  }
  L0075fdd8: { // 0x75fdd8: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L0075fdda: { // 0x75fdda: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0075fddc: { // 0x75fddc: ff5074 CALL dword ptr [EAX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000074u)),7732703u,op); flags=s.arithmetic_flags;
  }
  L0075fddf: { // 0x75fddf: 8d4dec LEA ECX,[EBP + -0x14]
    s.cx = (s.bp-0x00000014u);
  }
  L0075fde2: { // 0x75fde2: 89450c MOV dword ptr [EBP + 0xc],EAX
    m.w32((s.bp+0x0000000cu), s.ax);
  }
  L0075fde5: { // 0x75fde5: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0075fde6: { // 0x75fde6: 8d4dd4 LEA ECX,[EBP + -0x2c]
    s.cx = (s.bp-0x0000002cu);
  }
  L0075fde9: { // 0x75fde9: e83256cdff CALL 0x00435420
    s.arithmetic_flags=flags; invoke(m,s,f,0x00435420u,7732718u,op); flags=s.arithmetic_flags;
  }
  L0075fdee: { // 0x75fdee: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0075fdf0: { // 0x75fdf0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0075fdf3: { // 0x75fdf3: 8bcc MOV ECX,ESP
    s.cx = f.sp;
  }
  L0075fdf5: { // 0x75fdf5: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  L0075fdf7: { // 0x75fdf7: 8b4004 MOV EAX,dword ptr [EAX + 0x4]
    s.ax = m.r32((s.ax+0x00000004u));
  }
  L0075fdfa: { // 0x75fdfa: 894104 MOV dword ptr [ECX + 0x4],EAX
    m.w32((s.cx+0x00000004u), s.ax);
  }
  L0075fdfd: { // 0x75fdfd: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L0075fdff: { // 0x75fdff: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0075fe01: { // 0x75fe01: ff525c CALL dword ptr [EDX + 0x5c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000005cu)),7732740u,op); flags=s.arithmetic_flags;
  }
  L0075fe04: { // 0x75fe04: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0075fe06: { // 0x75fe06: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0075fe08: { // 0x75fe08: 8975f4 MOV dword ptr [EBP + -0xc],ESI
    m.w32((s.bp-0x0000000cu), s.si);
  }
  L0075fe0b: { // 0x75fe0b: 0f84d0010000 JZ 0x0075ffe1
    if(integer::condition("JZ",flags)) goto L0075ffe1;
  }
  L0075fe11: { // 0x75fe11: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L0075fe13: { // 0x75fe13: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0075fe15: { // 0x75fe15: ff5070 CALL dword ptr [EAX + 0x70]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000070u)),7732760u,op); flags=s.arithmetic_flags;
  }
  L0075fe18: { // 0x75fe18: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0075fe1b: { // 0x75fe1b: 755c JNZ 0x0075fe79
    if(integer::condition("JNZ",flags)) goto L0075fe79;
  }
  L0075fe1d: { // 0x75fe1d: 8b45e0 MOV EAX,dword ptr [EBP + -0x20]
    s.ax = m.r32((s.bp-0x00000020u));
  }
  L0075fe20: { // 0x75fe20: c7450800000000 MOV dword ptr [EBP + 0x8],0x0
    m.w32((s.bp+0x00000008u), 0x00000000u);
  }
  L0075fe27: { // 0x75fe27: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0075fe29: { // 0x75fe29: 0f8ea0010000 JLE 0x0075ffcf
    if(integer::condition("JLE",flags)) goto L0075ffcf;
  }
  L0075fe2f: { // 0x75fe2f: 8a4510 MOV AL,byte ptr [EBP + 0x10]
    s.ax = with_al(s.ax, m.r8((s.bp+0x00000010u)));
  }
  L0075fe32: { // 0x75fe32: 8b4ddc MOV ECX,dword ptr [EBP + -0x24]
    s.cx = m.r32((s.bp-0x00000024u));
  }
  L0075fe35: { // 0x75fe35: 8ad8 MOV BL,AL
    s.bx = with_al(s.bx, (s.ax & 0xffu));
  }
  L0075fe37: { // 0x75fe37: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L0075fe39: { // 0x75fe39: 8afb MOV BH,BL
    s.bx = (s.bx & 0xffff00ffu) | ((((s.bx & 0xffu)) & 0xffu) << 8);
  }
  L0075fe3b: { // 0x75fe3b: 8bfe MOV EDI,ESI
    s.di = s.si;
  }
  L0075fe3d: { // 0x75fe3d: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L0075fe3f: { // 0x75fe3f: c1e010 SHL EAX,0x10
    s.ax = integer::shift(s.ax,0x00000010u,32,flags,integer::Shift::left);
  }
  L0075fe42: { // 0x75fe42: 668bc3 MOV AX,BX
    s.ax = with_ax(s.ax, (s.bx & 0xffffu));
  }
  L0075fe45: { // 0x75fe45: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L0075fe48: { // 0x75fe48: f3ab STOSD.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::count);
  }
  L0075fe4a: { // 0x75fe4a: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L0075fe4c: { // 0x75fe4c: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  L0075fe4f: { // 0x75fe4f: f3aa STOSB.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,8u,Repeat::count);
  }
  L0075fe51: { // 0x75fe51: 8b7d0c MOV EDI,dword ptr [EBP + 0xc]
    s.di = m.r32((s.bp+0x0000000cu));
  }
  L0075fe54: { // 0x75fe54: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L0075fe57: { // 0x75fe57: 8b4de0 MOV ECX,dword ptr [EBP + -0x20]
    s.cx = m.r32((s.bp-0x00000020u));
  }
  L0075fe5a: { // 0x75fe5a: 03f7 ADD ESI,EDI
    s.si = integer::add(s.si,s.di,32,flags);
  }
  L0075fe5c: { // 0x75fe5c: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0075fe5d: { // 0x75fe5d: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0075fe5f: { // 0x75fe5f: 894508 MOV dword ptr [EBP + 0x8],EAX
    m.w32((s.bp+0x00000008u), s.ax);
  }
  L0075fe62: { // 0x75fe62: 7ccb JL 0x0075fe2f
    if(integer::condition("JL",flags)) goto L0075fe2f;
  }
  L0075fe64: { // 0x75fe64: 8b7dfc MOV EDI,dword ptr [EBP + -0x4]
    s.di = m.r32((s.bp-0x00000004u));
  }
  L0075fe67: { // 0x75fe67: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0075fe69: { // 0x75fe69: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L0075fe6b: { // 0x75fe6b: ff5260 CALL dword ptr [EDX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),7732846u,op); flags=s.arithmetic_flags;
  }
  L0075fe6e: { // 0x75fe6e: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0075fe70: { // 0x75fe70: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0075fe71: { // 0x75fe71: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0075fe72: { // 0x75fe72: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0075fe73: { // 0x75fe73: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L0075fe75: { // 0x75fe75: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0075fe76: { // 0x75fe76: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L0075fe79: { // 0x75fe79: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0075fe7b: { // 0x75fe7b: 83e003 AND EAX,0x3
    s.ax = integer::logical((s.ax)&(0x00000003u),32,flags);
  }
  L0075fe7e: { // 0x75fe7e: 83e800 SUB EAX,0x0
    s.ax = integer::sub(s.ax,0x00000000u,32,flags);
  }
  L0075fe81: { // 0x75fe81: 0f84f8000000 JZ 0x0075ff7f
    if(integer::condition("JZ",flags)) goto L0075ff7f;
  }
  L0075fe87: { // 0x75fe87: 83e802 SUB EAX,0x2
    s.ax = integer::sub(s.ax,0x00000002u,32,flags);
  }
  L0075fe8a: { // 0x75fe8a: 7450 JZ 0x0075fedc
    if(integer::condition("JZ",flags)) goto L0075fedc;
  }
  L0075fe8c: { // 0x75fe8c: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L0075fe8f: { // 0x75fe8f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0075fe91: { // 0x75fe91: 0f8e38010000 JLE 0x0075ffcf
    if(integer::condition("JLE",flags)) goto L0075ffcf;
  }
  L0075fe97: { // 0x75fe97: 894508 MOV dword ptr [EBP + 0x8],EAX
    m.w32((s.bp+0x00000008u), s.ax);
  }
  L0075fe9a: { // 0x75fe9a: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L0075fe9c: { // 0x75fe9c: 7e1e JLE 0x0075febc
    if(integer::condition("JLE",flags)) goto L0075febc;
  }
  L0075fe9e: { // 0x75fe9e: 8b4510 MOV EAX,dword ptr [EBP + 0x10]
    s.ax = m.r32((s.bp+0x00000010u));
  }
  L0075fea1: { // 0x75fea1: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0075fea3: { // 0x75fea3: 668bd0 MOV DX,AX
    s.dx = with_ax(s.dx, (s.ax & 0xffffu));
  }
  L0075fea6: { // 0x75fea6: 8bfe MOV EDI,ESI
    s.di = s.si;
  }
  L0075fea8: { // 0x75fea8: c1e210 SHL EDX,0x10
    s.dx = integer::shift(s.dx,0x00000010u,32,flags,integer::Shift::left);
  }
  L0075feab: { // 0x75feab: 668bd0 MOV DX,AX
    s.dx = with_ax(s.dx, (s.ax & 0xffffu));
  }
  L0075feae: { // 0x75feae: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L0075feb0: { // 0x75feb0: d1e9 SHR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::right);
  }
  L0075feb2: { // 0x75feb2: f3ab STOSD.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::count);
  }
  L0075feb4: { // 0x75feb4: 13c9 ADC ECX,ECX
    s.cx = integer::add(s.cx,s.cx,32,flags,flags&integer::CF);
  }
  L0075feb6: { // 0x75feb6: 66f3ab STOSW.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,16u,Repeat::count);
  }
  L0075feb9: { // 0x75feb9: 8b7dfc MOV EDI,dword ptr [EBP + -0x4]
    s.di = m.r32((s.bp-0x00000004u));
  }
  L0075febc: { // 0x75febc: 8b4d0c MOV ECX,dword ptr [EBP + 0xc]
    s.cx = m.r32((s.bp+0x0000000cu));
  }
  L0075febf: { // 0x75febf: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L0075fec2: { // 0x75fec2: 03f1 ADD ESI,ECX
    s.si = integer::add(s.si,s.cx,32,flags);
  }
  L0075fec4: { // 0x75fec4: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0075fec5: { // 0x75fec5: 894508 MOV dword ptr [EBP + 0x8],EAX
    m.w32((s.bp+0x00000008u), s.ax);
  }
  L0075fec8: { // 0x75fec8: 75d0 JNZ 0x0075fe9a
    if(integer::condition("JNZ",flags)) goto L0075fe9a;
  }
  L0075feca: { // 0x75feca: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L0075fecc: { // 0x75fecc: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0075fece: { // 0x75fece: ff5260 CALL dword ptr [EDX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),7732945u,op); flags=s.arithmetic_flags;
  }
  L0075fed1: { // 0x75fed1: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0075fed3: { // 0x75fed3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0075fed4: { // 0x75fed4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0075fed5: { // 0x75fed5: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0075fed6: { // 0x75fed6: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L0075fed8: { // 0x75fed8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0075fed9: { // 0x75fed9: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L0075fedc: { // 0x75fedc: 83fb01 CMP EBX,0x1
    (void)integer::sub(s.bx,0x00000001u,32,flags);
  }
  L0075fedf: { // 0x75fedf: 7f31 JG 0x0075ff12
    if(integer::condition("JG",flags)) goto L0075ff12;
  }
  L0075fee1: { // 0x75fee1: 0f85e8000000 JNZ 0x0075ffcf
    if(integer::condition("JNZ",flags)) goto L0075ffcf;
  }
  L0075fee7: { // 0x75fee7: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L0075feea: { // 0x75feea: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0075feec: { // 0x75feec: 0f8edd000000 JLE 0x0075ffcf
    if(integer::condition("JLE",flags)) goto L0075ffcf;
  }
  L0075fef2: { // 0x75fef2: 8b4d10 MOV ECX,dword ptr [EBP + 0x10]
    s.cx = m.r32((s.bp+0x00000010u));
  }
  L0075fef5: { // 0x75fef5: 8b5d0c MOV EBX,dword ptr [EBP + 0xc]
    s.bx = m.r32((s.bp+0x0000000cu));
  }
  L0075fef8: { // 0x75fef8: 66890e MOV word ptr [ESI],CX
    m.w16((s.si), (s.cx & 0xffffu));
  }
  L0075fefb: { // 0x75fefb: 03f3 ADD ESI,EBX
    s.si = integer::add(s.si,s.bx,32,flags);
  }
  L0075fefd: { // 0x75fefd: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0075fefe: { // 0x75fefe: 75f5 JNZ 0x0075fef5
    if(integer::condition("JNZ",flags)) goto L0075fef5;
  }
  L0075ff00: { // 0x75ff00: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L0075ff02: { // 0x75ff02: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0075ff04: { // 0x75ff04: ff5260 CALL dword ptr [EDX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),7732999u,op); flags=s.arithmetic_flags;
  }
  L0075ff07: { // 0x75ff07: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0075ff09: { // 0x75ff09: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0075ff0a: { // 0x75ff0a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0075ff0b: { // 0x75ff0b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0075ff0c: { // 0x75ff0c: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L0075ff0e: { // 0x75ff0e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0075ff0f: { // 0x75ff0f: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L0075ff12: { // 0x75ff12: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L0075ff13: { // 0x75ff13: 8bd3 MOV EDX,EBX
    s.dx = s.bx;
  }
  L0075ff15: { // 0x75ff15: d1fb SAR EBX,0x1
    s.bx = integer::shift(s.bx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0075ff17: { // 0x75ff17: 895df8 MOV dword ptr [EBP + -0x8],EBX
    m.w32((s.bp-0x00000008u), s.bx);
  }
  L0075ff1a: { // 0x75ff1a: 8b5d10 MOV EBX,dword ptr [EBP + 0x10]
    s.bx = m.r32((s.bp+0x00000010u));
  }
  L0075ff1d: { // 0x75ff1d: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L0075ff1f: { // 0x75ff1f: 83e201 AND EDX,0x1
    s.dx = integer::logical((s.dx)&(0x00000001u),32,flags);
  }
  L0075ff22: { // 0x75ff22: c1e010 SHL EAX,0x10
    s.ax = integer::shift(s.ax,0x00000010u,32,flags,integer::Shift::left);
  }
  L0075ff25: { // 0x75ff25: 0bc3 OR EAX,EBX
    s.ax = integer::logical((s.ax)|(s.bx),32,flags);
  }
  L0075ff27: { // 0x75ff27: 8945f4 MOV dword ptr [EBP + -0xc],EAX
    m.w32((s.bp-0x0000000cu), s.ax);
  }
  L0075ff2a: { // 0x75ff2a: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L0075ff2d: { // 0x75ff2d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0075ff2f: { // 0x75ff2f: 0f8e9a000000 JLE 0x0075ffcf
    if(integer::condition("JLE",flags)) goto L0075ffcf;
  }
  L0075ff35: { // 0x75ff35: 894510 MOV dword ptr [EBP + 0x10],EAX
    m.w32((s.bp+0x00000010u), s.ax);
  }
  L0075ff38: { // 0x75ff38: 8d4e02 LEA ECX,[ESI + 0x2]
    s.cx = (s.si+0x00000002u);
  }
  L0075ff3b: { // 0x75ff3b: 66891e MOV word ptr [ESI],BX
    m.w16((s.si), (s.bx & 0xffffu));
  }
  L0075ff3e: { // 0x75ff3e: 894d08 MOV dword ptr [EBP + 0x8],ECX
    m.w32((s.bp+0x00000008u), s.cx);
  }
  L0075ff41: { // 0x75ff41: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0075ff42: { // 0x75ff42: 8b4df8 MOV ECX,dword ptr [EBP + -0x8]
    s.cx = m.r32((s.bp-0x00000008u));
  }
  L0075ff45: { // 0x75ff45: 8b7d08 MOV EDI,dword ptr [EBP + 0x8]
    s.di = m.r32((s.bp+0x00000008u));
  }
  L0075ff48: { // 0x75ff48: 83f900 CMP ECX,0x0
    (void)integer::sub(s.cx,0x00000000u,32,flags);
  }
  L0075ff4b: { // 0x75ff4b: 7e05 JLE 0x0075ff52
    if(integer::condition("JLE",flags)) goto L0075ff52;
  }
  L0075ff4d: { // 0x75ff4d: 8b45f4 MOV EAX,dword ptr [EBP + -0xc]
    s.ax = m.r32((s.bp-0x0000000cu));
  }
  L0075ff50: { // 0x75ff50: f3ab STOSD.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::count);
  }
  L0075ff52: { // 0x75ff52: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0075ff54: { // 0x75ff54: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0075ff55: { // 0x75ff55: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0075ff57: { // 0x75ff57: 7403 JZ 0x0075ff5c
    if(integer::condition("JZ",flags)) goto L0075ff5c;
  }
  L0075ff59: { // 0x75ff59: 668918 MOV word ptr [EAX],BX
    m.w16((s.ax), (s.bx & 0xffffu));
  }
  L0075ff5c: { // 0x75ff5c: 8b4d0c MOV ECX,dword ptr [EBP + 0xc]
    s.cx = m.r32((s.bp+0x0000000cu));
  }
  L0075ff5f: { // 0x75ff5f: 8b4510 MOV EAX,dword ptr [EBP + 0x10]
    s.ax = m.r32((s.bp+0x00000010u));
  }
  L0075ff62: { // 0x75ff62: 03f1 ADD ESI,ECX
    s.si = integer::add(s.si,s.cx,32,flags);
  }
  L0075ff64: { // 0x75ff64: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0075ff65: { // 0x75ff65: 894510 MOV dword ptr [EBP + 0x10],EAX
    m.w32((s.bp+0x00000010u), s.ax);
  }
  L0075ff68: { // 0x75ff68: 75ce JNZ 0x0075ff38
    if(integer::condition("JNZ",flags)) goto L0075ff38;
  }
  L0075ff6a: { // 0x75ff6a: 8b7dfc MOV EDI,dword ptr [EBP + -0x4]
    s.di = m.r32((s.bp-0x00000004u));
  }
  L0075ff6d: { // 0x75ff6d: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0075ff6f: { // 0x75ff6f: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L0075ff71: { // 0x75ff71: ff5260 CALL dword ptr [EDX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),7733108u,op); flags=s.arithmetic_flags;
  }
  L0075ff74: { // 0x75ff74: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0075ff76: { // 0x75ff76: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0075ff77: { // 0x75ff77: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0075ff78: { // 0x75ff78: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0075ff79: { // 0x75ff79: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L0075ff7b: { // 0x75ff7b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0075ff7c: { // 0x75ff7c: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L0075ff7f: { // 0x75ff7f: 8bd3 MOV EDX,EBX
    s.dx = s.bx;
  }
  L0075ff81: { // 0x75ff81: d1fb SAR EBX,0x1
    s.bx = integer::shift(s.bx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0075ff83: { // 0x75ff83: 895df8 MOV dword ptr [EBP + -0x8],EBX
    m.w32((s.bp-0x00000008u), s.bx);
  }
  L0075ff86: { // 0x75ff86: 8b5d10 MOV EBX,dword ptr [EBP + 0x10]
    s.bx = m.r32((s.bp+0x00000010u));
  }
  L0075ff89: { // 0x75ff89: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L0075ff8b: { // 0x75ff8b: 83e201 AND EDX,0x1
    s.dx = integer::logical((s.dx)&(0x00000001u),32,flags);
  }
  L0075ff8e: { // 0x75ff8e: c1e010 SHL EAX,0x10
    s.ax = integer::shift(s.ax,0x00000010u,32,flags,integer::Shift::left);
  }
  L0075ff91: { // 0x75ff91: 0bc3 OR EAX,EBX
    s.ax = integer::logical((s.ax)|(s.bx),32,flags);
  }
  L0075ff93: { // 0x75ff93: 8945f0 MOV dword ptr [EBP + -0x10],EAX
    m.w32((s.bp-0x00000010u), s.ax);
  }
  L0075ff96: { // 0x75ff96: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L0075ff99: { // 0x75ff99: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0075ff9b: { // 0x75ff9b: 7e32 JLE 0x0075ffcf
    if(integer::condition("JLE",flags)) goto L0075ffcf;
  }
  L0075ff9d: { // 0x75ff9d: 894510 MOV dword ptr [EBP + 0x10],EAX
    m.w32((s.bp+0x00000010u), s.ax);
  }
  L0075ffa0: { // 0x75ffa0: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0075ffa1: { // 0x75ffa1: 8b4df8 MOV ECX,dword ptr [EBP + -0x8]
    s.cx = m.r32((s.bp-0x00000008u));
  }
  L0075ffa4: { // 0x75ffa4: 8b7df4 MOV EDI,dword ptr [EBP + -0xc]
    s.di = m.r32((s.bp-0x0000000cu));
  }
  L0075ffa7: { // 0x75ffa7: 83f900 CMP ECX,0x0
    (void)integer::sub(s.cx,0x00000000u,32,flags);
  }
  L0075ffaa: { // 0x75ffaa: 7e05 JLE 0x0075ffb1
    if(integer::condition("JLE",flags)) goto L0075ffb1;
  }
  L0075ffac: { // 0x75ffac: 8b45f0 MOV EAX,dword ptr [EBP + -0x10]
    s.ax = m.r32((s.bp-0x00000010u));
  }
  L0075ffaf: { // 0x75ffaf: f3ab STOSD.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::count);
  }
  L0075ffb1: { // 0x75ffb1: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0075ffb3: { // 0x75ffb3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0075ffb4: { // 0x75ffb4: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0075ffb6: { // 0x75ffb6: 7403 JZ 0x0075ffbb
    if(integer::condition("JZ",flags)) goto L0075ffbb;
  }
  L0075ffb8: { // 0x75ffb8: 668918 MOV word ptr [EAX],BX
    m.w16((s.ax), (s.bx & 0xffffu));
  }
  L0075ffbb: { // 0x75ffbb: 8b4d0c MOV ECX,dword ptr [EBP + 0xc]
    s.cx = m.r32((s.bp+0x0000000cu));
  }
  L0075ffbe: { // 0x75ffbe: 8b4510 MOV EAX,dword ptr [EBP + 0x10]
    s.ax = m.r32((s.bp+0x00000010u));
  }
  L0075ffc1: { // 0x75ffc1: 03f1 ADD ESI,ECX
    s.si = integer::add(s.si,s.cx,32,flags);
  }
  L0075ffc3: { // 0x75ffc3: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0075ffc4: { // 0x75ffc4: 8975f4 MOV dword ptr [EBP + -0xc],ESI
    m.w32((s.bp-0x0000000cu), s.si);
  }
  L0075ffc7: { // 0x75ffc7: 894510 MOV dword ptr [EBP + 0x10],EAX
    m.w32((s.bp+0x00000010u), s.ax);
  }
  L0075ffca: { // 0x75ffca: 75d4 JNZ 0x0075ffa0
    if(integer::condition("JNZ",flags)) goto L0075ffa0;
  }
  L0075ffcc: { // 0x75ffcc: 8b7dfc MOV EDI,dword ptr [EBP + -0x4]
    s.di = m.r32((s.bp-0x00000004u));
  }
  L0075ffcf: { // 0x75ffcf: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L0075ffd1: { // 0x75ffd1: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0075ffd3: { // 0x75ffd3: ff5260 CALL dword ptr [EDX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),7733206u,op); flags=s.arithmetic_flags;
  }
  L0075ffd6: { // 0x75ffd6: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0075ffd8: { // 0x75ffd8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0075ffd9: { // 0x75ffd9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0075ffda: { // 0x75ffda: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0075ffdb: { // 0x75ffdb: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L0075ffdd: { // 0x75ffdd: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0075ffde: { // 0x75ffde: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L0075ffe1: { // 0x75ffe1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0075ffe2: { // 0x75ffe2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0075ffe3: { // 0x75ffe3: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0075ffe5: { // 0x75ffe5: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0075ffe6: { // 0x75ffe6: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L0075ffe8: { // 0x75ffe8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0075ffe9: { // 0x75ffe9: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}

void f_00053ab0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00453ab0: { // 0x453ab0: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00453ab2: { // 0x453ab2: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L00453ab6: { // 0x453ab6: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00453ab8: { // 0x453ab8: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L00453aba: { // 0x453aba: 8b4904 MOV ECX,dword ptr [ECX + 0x4]
    s.cx = m.r32((s.cx+0x00000004u));
  }
  L00453abd: { // 0x453abd: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L00453ac1: { // 0x453ac1: 894804 MOV dword ptr [EAX + 0x4],ECX
    m.w32((s.ax+0x00000004u), s.cx);
  }
  L00453ac4: { // 0x453ac4: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L00453ac8: { // 0x453ac8: 895008 MOV dword ptr [EAX + 0x8],EDX
    m.w32((s.ax+0x00000008u), s.dx);
  }
  L00453acb: { // 0x453acb: 89480c MOV dword ptr [EAX + 0xc],ECX
    m.w32((s.ax+0x0000000cu), s.cx);
  }
  L00453ace: { // 0x453ace: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}


inline void invoke(Memory&m,State&s,Frame&f,unsigned target,unsigned continuation,const Operations&op){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};switch(target){
case 0x4a94c0:f_000a94c0(m,s,child,op);break;
case 0x485880:f_00085880(m,s,child,op);break;
case 0x485fa0:f_00085fa0(m,s,child,op);break;
case 0x432350:f_00032350(m,s,child,op);break;
case 0x431d40:f_00031d40(m,s,child,op);break;
case 0x4b11f0:f_000b11f0(m,s,child,op);break;
case 0x76ef45:f_0036ef45(m,s,child,op);break;
case 0x4ab200:f_000ab200(m,s,child,op);break;
case 0x497920:f_00097920(m,s,child,op);break;
case 0x497610:f_00097610(m,s,child,op);break;
case 0x4112c0:f_000112c0(m,s,child,op);break;
case 0x4112d0:f_000112d0(m,s,child,op);break;
case 0x4112f0:f_000112f0(m,s,child,op);break;
case 0x411370:f_00011370(m,s,child,op);break;
case 0x4113b0:f_000113b0(m,s,child,op);break;
case 0x4113c0:f_000113c0(m,s,child,op);break;
case 0x4312f0:f_000312f0(m,s,child,op);break;
case 0x431310:f_00031310(m,s,child,op);break;
case 0x431320:f_00031320(m,s,child,op);break;
case 0x431370:f_00031370(m,s,child,op);break;
case 0x431790:f_00031790(m,s,child,op);break;
case 0x4317a0:f_000317a0(m,s,child,op);break;
case 0x431b80:f_00031b80(m,s,child,op);break;
case 0x431ec0:f_00031ec0(m,s,child,op);break;
case 0x431f70:f_00031f70(m,s,child,op);break;
case 0x432010:f_00032010(m,s,child,op);break;
case 0x432210:f_00032210(m,s,child,op);break;
case 0x497830:f_00097830(m,s,child,op);break;
case 0x65ace0:f_0025ace0(m,s,child,op);break;
case 0x49f0c0:f_0009f0c0(m,s,child,op);break;
case 0x4fe550:f_000fe550(m,s,child,op);break;
case 0x434a00:f_00034a00(m,s,child,op);break;
case 0x760cf0:f_00360cf0(m,s,child,op);break;
case 0x760ad0:f_00360ad0(m,s,child,op);break;
case 0x435420:f_00035420(m,s,child,op);break;
case 0x435400:f_00035400(m,s,child,op);break;
case 0x761440:f_00361440(m,s,child,op);break;
case 0x411290:f_00011290(m,s,child,op);break;
case 0x41fdf0:f_0001fdf0(m,s,child,op);break;
case 0x4ab230:f_000ab230(m,s,child,op);break;
case 0x75fa70:f_0035fa70(m,s,child,op);break;
case 0x75fd00:f_0035fd00(m,s,child,op);break;
case 0x453ab0:f_00053ab0(m,s,child,op);break;

 case 0x411300:s.dx=m.r32(s.cx+12);s.ax=0;s.arithmetic_flags=integer::logical(s.dx,32,s.arithmetic_flags);s.ax=s.dx!=0;finish(m,s,child,0);break;
 default:throw std::domain_error("unselected palette composition call; no provider/callback fallback");
 }f.sp=child.sp;
}


Result run(Memory&world,unsigned entry,unsigned char*storage,unsigned size,const NativeState&in,const fp::Image&incoming){
 need(size>=0x4000+68&&unsigned(reinterpret_cast<std::uintptr_t>(storage))+0x4000==entry,"genuinely owned current Source frame");
 ra2::recovered::leaf::Memory local(storage,entry-0x4000,size);Memory m=world;m.add(local);
 const unsigned source=in.cx,dest=m.r32(0x821c94),context=in.dx,lut=m.r32(context+0x174),mode=m.r32(context+12),guard=m.r32(context+8);
 for(unsigned self:{source,dest})need(m.r32(self)==0x785ef8&&m.r32(self+4)==640&&m.r32(self+8)==480&&m.r32(self+12)==0&&m.r8(self+28)==0,"authentic borrowed BSurface640x480/initialdepth0");
 need(source!=dest&&m.r32(source+16)==1&&m.r32(dest+16)==2&&m.r32(source+24)==307200&&m.r32(dest+24)==614400,"disjoint1byte source/2byte destination extents");
 need(m.r32(context)==0x788f70&&m.r32(context+4)==2&&m.r32(context+0x16c)==1&&m.r32(context+0x170)==lut&&m.r32(context+0x178)==0&&m.r32(context+0x17c)==0,"normal B1063 bpp2/N1 borrowed postproducer context");
 need(m.r32(mode)==0x78942c&&m.r32(mode+4)==lut&&m.r32(guard)==0x78943c&&m.r32(guard+4)==lut,"actual flags0 descriptor publication and lookup backing");
 need(m.r32(entry+4)==0&&m.r32(0x8198f4)==0&&m.r32(0x821fac)==0,"optional labels absent; authentic absent auxiliary planes");
 State s{};s.ax=in.ax;s.cx=in.cx;s.dx=in.dx;s.bx=in.bx;s.bp=in.bp;s.si=in.si;s.di=in.di;s.fp.image=incoming;s.arithmetic_flags=in.flags;const auto initial=s;Frame frame{entry,entry,m.r32(entry)};Operations op{};f_000a94c0(m,s,frame,op);
 need(frame.sp==entry+12&&s.bx==initial.bx&&s.bp==initial.bp&&s.si==initial.si&&s.di==initial.di,"Root RET8 and modeled preserved registers");
 Result out{s.ax,s,{}};for(unsigned k=0;k<16;++k)out.words[k]=m.r32(entry+4+4*k);return out;
}
}
