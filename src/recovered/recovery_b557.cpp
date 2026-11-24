#include "recovered/recovery_b557_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b557 {
namespace {
void f_0029ffd0(Memory&,State&,Frame&,const Operations&);
void f_0029c210(Memory&,State&,Frame&,const Operations&);
void f_0018e180(Memory&,State&,Frame&,const Operations&);
void f_00297de0(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_000766c0(Memory&,State&,Frame&,const Operations&);
void f_0007b560(Memory&,State&,Frame&,const Operations&);
void f_0007b580(Memory&,State&,Frame&,const Operations&);
void f_00298150(Memory&,State&,Frame&,const Operations&);
void f_00147f90(Memory&,State&,Frame&,const Operations&);
void f_00157070(Memory&,State&,Frame&,const Operations&);
void f_000702c0(Memory&,State&,Frame&,const Operations&);
void f_00164f30(Memory&,State&,Frame&,const Operations&);
void f_0000dc20(Memory&,State&,Frame&,const Operations&);
void f_002b6910(Memory&,State&,Frame&,const Operations&);
void f_000538b0(Memory&,State&,Frame&,const Operations&);
void f_00053890(Memory&,State&,Frame&,const Operations&);
void tail(Memory&,State&,Frame&,std::uint32_t);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_0029ffd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0069ffd0: { // 0x69ffd0: 83ec28 SUB ESP,0x28
    f.sp = integer::sub(f.sp,0x00000028u,32,flags);
  }
  L0069ffd3: { // 0x69ffd3: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0069ffd4: { // 0x69ffd4: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0069ffd5: { // 0x69ffd5: 8b742434 MOV ESI,dword ptr [ESP + 0x34]
    s.si = m.r32((f.sp+0x00000034u));
  }
  L0069ffd9: { // 0x69ffd9: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L0069ffdb: { // 0x69ffdb: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0069ffdc: { // 0x69ffdc: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0069ffde: { // 0x69ffde: 8b85b0000000 MOV EAX,dword ptr [EBP + 0xb0]
    s.ax = m.r32((s.bp+0x000000b0u));
  }
  L0069ffe4: { // 0x69ffe4: 8b3e MOV EDI,dword ptr [ESI]
    s.di = m.r32((s.si));
  }
  L0069ffe6: { // 0x69ffe6: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  L0069ffe9: { // 0x69ffe9: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L0069ffeb: { // 0x69ffeb: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0069ffef: { // 0x69ffef: 8b85b4000000 MOV EAX,dword ptr [EBP + 0xb4]
    s.ax = m.r32((s.bp+0x000000b4u));
  }
  L0069fff5: { // 0x69fff5: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0069fff7: { // 0x69fff7: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L0069fffb: { // 0x69fffb: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0069ffff: { // 0x69ffff: 8b85b00d0000 MOV EAX,dword ptr [EBP + 0xdb0]
    s.ax = m.r32((s.bp+0x00000db0u));
  }
  L006a0005: { // 0x6a0005: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L006a0007: { // 0x6a0007: c744240cffffffff MOV dword ptr [ESP + 0xc],0xffffffff
    m.w32((f.sp+0x0000000cu), 0xffffffffu);
  }
  L006a000f: { // 0x6a000f: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L006a0013: { // 0x6a0013: 0f8ee9000000 JLE 0x006a0102
    if(integer::condition("JLE",flags)) goto L006a0102;
  }
  L006a0019: { // 0x6a0019: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006a001a: { // 0x6a001a: bf0461aa00 MOV EDI,0xaa6104
    s.di = 0x00aa6104u;
  }
  L006a001f: { // 0x6a001f: 8b77fc MOV ESI,dword ptr [EDI + -0x4]
    s.si = m.r32((s.di-0x00000004u));
  }
  L006a0022: { // 0x6a0022: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L006a0024: { // 0x6a0024: 0f84b1000000 JZ 0x006a00db
    if(integer::condition("JZ",flags)) goto L006a00db;
  }
  L006a002a: { // 0x6a002a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006a002c: { // 0x6a002c: e89fdbd6ff CALL 0x0040dbd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0040dbd0u,6946865u); flags=s.arithmetic_flags;
  }
  L006a0031: { // 0x6a0031: 32db XOR BL,BL
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))^((s.bx & 0xffu)),8,flags));
  }
  L006a0033: { // 0x6a0033: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006a0035: { // 0x6a0035: 0f8419010000 JZ 0x006a0154
    if(integer::condition("JZ",flags)) goto L006a0154;
  }
  L006a003b: { // 0x6a003b: 8a4e7d MOV CL,byte ptr [ESI + 0x7d]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000007du)));
  }
  L006a003e: { // 0x6a003e: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006a0040: { // 0x6a0040: 7448 JZ 0x006a008a
    if(integer::condition("JZ",flags)) goto L006a008a;
  }
  L006a0042: { // 0x6a0042: 8a4876 MOV CL,byte ptr [EAX + 0x76]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000076u)));
  }
  L006a0045: { // 0x6a0045: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006a0047: { // 0x6a0047: 7541 JNZ 0x006a008a
    if(integer::condition("JNZ",flags)) goto L006a008a;
  }
  L006a0049: { // 0x6a0049: 8a8872030000 MOV CL,byte ptr [EAX + 0x372]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000372u)));
  }
  L006a004f: { // 0x6a004f: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006a0051: { // 0x6a0051: 7535 JNZ 0x006a0088
    if(integer::condition("JNZ",flags)) goto L006a0088;
  }
  L006a0053: { // 0x6a0053: 83b8b801000002 CMP dword ptr [EAX + 0x1b8],0x2
    (void)integer::sub(m.r32((s.ax+0x000001b8u)),0x00000002u,32,flags);
  }
  L006a005a: { // 0x6a005a: 752c JNZ 0x006a0088
    if(integer::condition("JNZ",flags)) goto L006a0088;
  }
  L006a005c: { // 0x6a005c: 8b0de4e0a100 MOV ECX,dword ptr [0x00a1e0e4]
    s.cx = m.r32((0x00a1e0e4u));
  }
  L006a0062: { // 0x6a0062: 8b5130 MOV EDX,dword ptr [ECX + 0x30]
    s.dx = m.r32((s.cx+0x00000030u));
  }
  L006a0065: { // 0x6a0065: 8d4c242c LEA ECX,[ESP + 0x2c]
    s.cx = (f.sp+0x0000002cu);
  }
  L006a0069: { // 0x6a0069: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006a006a: { // 0x6a006a: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L006a006c: { // 0x6a006c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006a006d: { // 0x6a006d: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006a006f: { // 0x6a006f: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),6946930u); flags=s.arithmetic_flags;
  }
  L006a0072: { // 0x6a0072: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006a0073: { // 0x6a0073: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006a0078: { // 0x6a0078: e81354eaff CALL 0x00545490
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545490u,6946941u); flags=s.arithmetic_flags;
  }
  L006a007d: { // 0x6a007d: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006a007f: { // 0x6a007f: e85cbeddff CALL 0x0047bee0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047bee0u,6946948u); flags=s.arithmetic_flags;
  }
  L006a0084: { // 0x6a0084: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006a0086: { // 0x6a0086: 7402 JZ 0x006a008a
    if(integer::condition("JZ",flags)) goto L006a008a;
  }
  L006a0088: { // 0x6a0088: b301 MOV BL,0x1
    s.bx = with_al(s.bx, 0x00000001u);
  }
  L006a008a: { // 0x6a008a: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L006a008c: { // 0x6a008c: 744d JZ 0x006a00db
    if(integer::condition("JZ",flags)) goto L006a00db;
  }
  L006a008e: { // 0x6a008e: 8b4f04 MOV ECX,dword ptr [EDI + 0x4]
    s.cx = m.r32((s.di+0x00000004u));
  }
  L006a0091: { // 0x6a0091: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L006a0095: { // 0x6a0095: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L006a0097: { // 0x6a0097: 8b5c241c MOV EBX,dword ptr [ESP + 0x1c]
    s.bx = m.r32((f.sp+0x0000001cu));
  }
  L006a009b: { // 0x6a009b: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L006a009d: { // 0x6a009d: 2bc3 SUB EAX,EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L006a009f: { // 0x6a009f: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L006a00a1: { // 0x6a00a1: 0fafd1 IMUL EDX,ECX
    s.dx = integer::imul(s.dx,s.cx,32,flags);
  }
  L006a00a4: { // 0x6a00a4: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006a00a6: { // 0x6a00a6: 89542428 MOV dword ptr [ESP + 0x28],EDX
    m.w32((f.sp+0x00000028u), s.dx);
  }
  L006a00aa: { // 0x6a00aa: db442428 FILD dword ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.load_integer32(m.r32(address));
  }
  L006a00ae: { // 0x6a00ae: 0fafc8 IMUL ECX,EAX
    s.cx = integer::imul(s.cx,s.ax,32,flags);
  }
  L006a00b1: { // 0x6a00b1: dc0d28577800 FMUL double ptr [0x00785728]
    const auto address=(0x00785728u);
    s.fp.multiply64(read64(m,address));
  }
  L006a00b7: { // 0x6a00b7: 894c2428 MOV dword ptr [ESP + 0x28],ECX
    m.w32((f.sp+0x00000028u), s.cx);
  }
  L006a00bb: { // 0x6a00bb: db442428 FILD dword ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.load_integer32(m.r32(address));
  }
  L006a00bf: { // 0x6a00bf: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L006a00c1: { // 0x6a00c1: e88aa90c00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6947014u); flags=s.arithmetic_flags;
  }
  L006a00c6: { // 0x6a00c6: 3b442410 CMP EAX,dword ptr [ESP + 0x10]
    (void)integer::sub(s.ax,m.r32((f.sp+0x00000010u)),32,flags);
  }
  L006a00ca: { // 0x6a00ca: 730f JNC 0x006a00db
    if(integer::condition("JNC",flags)) goto L006a00db;
  }
  L006a00cc: { // 0x6a00cc: 3dc8000000 CMP EAX,0xc8
    (void)integer::sub(s.ax,0x000000c8u,32,flags);
  }
  L006a00d1: { // 0x6a00d1: 7308 JNC 0x006a00db
    if(integer::condition("JNC",flags)) goto L006a00db;
  }
  L006a00d3: { // 0x6a00d3: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L006a00d7: { // 0x6a00d7: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L006a00db: { // 0x6a00db: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L006a00df: { // 0x6a00df: 8b8db00d0000 MOV ECX,dword ptr [EBP + 0xdb0]
    s.cx = m.r32((s.bp+0x00000db0u));
  }
  L006a00e5: { // 0x6a00e5: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L006a00e6: { // 0x6a00e6: 83c70c ADD EDI,0xc
    s.di = integer::add(s.di,0x0000000cu,32,flags);
  }
  L006a00e9: { // 0x6a00e9: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L006a00eb: { // 0x6a00eb: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L006a00ef: { // 0x6a00ef: 0f8c2affffff JL 0x006a001f
    if(integer::condition("JL",flags)) goto L006a001f;
  }
  L006a00f5: { // 0x6a00f5: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L006a00f9: { // 0x6a00f9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006a00fa: { // 0x6a00fa: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006a00fc: { // 0x6a00fc: 754d JNZ 0x006a014b
    if(integer::condition("JNZ",flags)) goto L006a014b;
  }
  L006a00fe: { // 0x6a00fe: 8b742438 MOV ESI,dword ptr [ESP + 0x38]
    s.si = m.r32((f.sp+0x00000038u));
  }
  L006a0102: { // 0x6a0102: 8b0d70198200 MOV ECX,dword ptr [0x00821970]
    s.cx = m.r32((0x00821970u));
  }
  L006a0108: { // 0x6a0108: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006a010a: { // 0x6a010a: 8b1574198200 MOV EDX,dword ptr [0x00821974]
    s.dx = m.r32((0x00821974u));
  }
  L006a0110: { // 0x6a0110: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L006a0112: { // 0x6a0112: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  L006a0115: { // 0x6a0115: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L006a0119: { // 0x6a0119: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L006a011b: { // 0x6a011b: 8d54241c LEA EDX,[ESP + 0x1c]
    s.dx = (f.sp+0x0000001cu);
  }
  L006a011f: { // 0x6a011f: 8d442424 LEA EAX,[ESP + 0x24]
    s.ax = (f.sp+0x00000024u);
  }
  L006a0123: { // 0x6a0123: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L006a0127: { // 0x6a0127: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006a0128: { // 0x6a0128: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006a0129: { // 0x6a0129: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L006a012b: { // 0x6a012b: e8e0c0ffff CALL 0x0069c210
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069c210u,6947120u); flags=s.arithmetic_flags;
  }
  L006a0130: { // 0x6a0130: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L006a0132: { // 0x6a0132: 8d542438 LEA EDX,[ESP + 0x38]
    s.dx = (f.sp+0x00000038u);
  }
  L006a0136: { // 0x6a0136: 894c2438 MOV dword ptr [ESP + 0x38],ECX
    m.w32((f.sp+0x00000038u), s.cx);
  }
  L006a013a: { // 0x6a013a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006a013b: { // 0x6a013b: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006a0140: { // 0x6a0140: e8bb53eaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6947141u); flags=s.arithmetic_flags;
  }
  L006a0145: { // 0x6a0145: 8b80e4000000 MOV EAX,dword ptr [EAX + 0xe4]
    s.ax = m.r32((s.ax+0x000000e4u));
  }
  L006a014b: { // 0x6a014b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006a014c: { // 0x6a014c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006a014d: { // 0x6a014d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006a014e: { // 0x6a014e: 83c428 ADD ESP,0x28
    f.sp = integer::add(f.sp,0x00000028u,32,flags);
  }
  L006a0151: { // 0x6a0151: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L006a0154: { // 0x6a0154: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006a0156: { // 0x6a0156: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006a0158: { // 0x6a0158: ff9284000000 CALL dword ptr [EDX + 0x84]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000084u)),6947166u); flags=s.arithmetic_flags;
  }
  L006a015e: { // 0x6a015e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006a0160: { // 0x6a0160: 0f8475ffffff JZ 0x006a00db
    if(integer::condition("JZ",flags)) goto L006a00db;
  }
  L006a0166: { // 0x6a0166: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006a0168: { // 0x6a0168: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006a016a: { // 0x6a016a: ff9084000000 CALL dword ptr [EAX + 0x84]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000084u)),6947184u); flags=s.arithmetic_flags;
  }
  L006a0170: { // 0x6a0170: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L006a0172: { // 0x6a0172: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006a0174: { // 0x6a0174: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),6947191u); flags=s.arithmetic_flags;
  }
  L006a0177: { // 0x6a0177: 83f825 CMP EAX,0x25
    (void)integer::sub(s.ax,0x00000025u,32,flags);
  }
  L006a017a: { // 0x6a017a: 0f855bffffff JNZ 0x006a00db
    if(integer::condition("JNZ",flags)) goto L006a00db;
  }
  L006a0180: { // 0x6a0180: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006a0182: { // 0x6a0182: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006a0184: { // 0x6a0184: ff9084000000 CALL dword ptr [EAX + 0x84]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000084u)),6947210u); flags=s.arithmetic_flags;
  }
  L006a018a: { // 0x6a018a: 8a8884020000 MOV CL,byte ptr [EAX + 0x284]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000284u)));
  }
  L006a0190: { // 0x6a0190: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006a0192: { // 0x6a0192: 0f8443ffffff JZ 0x006a00db
    if(integer::condition("JZ",flags)) goto L006a00db;
  }
  L006a0198: { // 0x6a0198: e9f1feffff JMP 0x006a008e
    goto L006a008e;
  }
}
void f_0029c210(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0069c210: { // 0x69c210: 83ec6c SUB ESP,0x6c
    f.sp = integer::sub(f.sp,0x0000006cu,32,flags);
  }
  L0069c213: { // 0x69c213: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0069c214: { // 0x69c214: 8b5c2478 MOV EBX,dword ptr [ESP + 0x78]
    s.bx = m.r32((f.sp+0x00000078u));
  }
  L0069c218: { // 0x69c218: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0069c219: { // 0x69c219: 8b1570198200 MOV EDX,dword ptr [0x00821970]
    s.dx = m.r32((0x00821970u));
  }
  L0069c21f: { // 0x69c21f: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L0069c221: { // 0x69c221: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0069c222: { // 0x69c222: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0069c223: { // 0x69c223: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0069c225: { // 0x69c225: 8b3574198200 MOV ESI,dword ptr [0x00821974]
    s.si = m.r32((0x00821974u));
  }
  L0069c22b: { // 0x69c22b: c744245400000000 MOV dword ptr [ESP + 0x54],0x0
    m.w32((f.sp+0x00000054u), 0x00000000u);
  }
  L0069c233: { // 0x69c233: 8bafb0000000 MOV EBP,dword ptr [EDI + 0xb0]
    s.bp = m.r32((s.di+0x000000b0u));
  }
  L0069c239: { // 0x69c239: 8b8fb4000000 MOV ECX,dword ptr [EDI + 0xb4]
    s.cx = m.r32((s.di+0x000000b4u));
  }
  L0069c23f: { // 0x69c23f: 03c5 ADD EAX,EBP
    s.ax = integer::add(s.ax,s.bp,32,flags);
  }
  L0069c241: { // 0x69c241: 8b6b04 MOV EBP,dword ptr [EBX + 0x4]
    s.bp = m.r32((s.bx+0x00000004u));
  }
  L0069c244: { // 0x69c244: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0069c246: { // 0x69c246: 03cd ADD ECX,EBP
    s.cx = integer::add(s.cx,s.bp,32,flags);
  }
  L0069c248: { // 0x69c248: 8944243c MOV dword ptr [ESP + 0x3c],EAX
    m.w32((f.sp+0x0000003cu), s.ax);
  }
  L0069c24c: { // 0x69c24c: 2bce SUB ECX,ESI
    s.cx = integer::sub(s.cx,s.si,32,flags);
  }
  L0069c24e: { // 0x69c24e: db44243c FILD dword ptr [ESP + 0x3c]
    const auto address=(f.sp+0x0000003cu);
    s.fp.load_integer32(m.r32(address));
  }
  L0069c252: { // 0x69c252: 894c2440 MOV dword ptr [ESP + 0x40],ECX
    m.w32((f.sp+0x00000040u), s.cx);
  }
  L0069c256: { // 0x69c256: 8d44244c LEA EAX,[ESP + 0x4c]
    s.ax = (f.sp+0x0000004cu);
  }
  L0069c25a: { // 0x69c25a: 8d97e40d0000 LEA EDX,[EDI + 0xde4]
    s.dx = (s.di+0x00000de4u);
  }
  L0069c260: { // 0x69c260: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0069c261: { // 0x69c261: d95c2450 FSTP float ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0069c265: { // 0x69c265: db442444 FILD dword ptr [ESP + 0x44]
    const auto address=(f.sp+0x00000044u);
    s.fp.load_integer32(m.r32(address));
  }
  L0069c269: { // 0x69c269: 8d4c2468 LEA ECX,[ESP + 0x68]
    s.cx = (f.sp+0x00000068u);
  }
  L0069c26d: { // 0x69c26d: d95c2454 FSTP float ptr [ESP + 0x54]
    const auto address=(f.sp+0x00000054u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0069c271: { // 0x69c271: e80a1fefff CALL 0x0058e180
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058e180u,6931062u); flags=s.arithmetic_flags;
  }
  L0069c276: { // 0x69c276: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0069c278: { // 0x69c278: 894c244c MOV dword ptr [ESP + 0x4c],ECX
    m.w32((f.sp+0x0000004cu), s.cx);
  }
  L0069c27c: { // 0x69c27c: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0069c27f: { // 0x69c27f: d944244c FLD float ptr [ESP + 0x4c]
    const auto address=(f.sp+0x0000004cu);
    s.fp.load32(m.r32(address));
  }
  L0069c283: { // 0x69c283: 89542450 MOV dword ptr [ESP + 0x50],EDX
    m.w32((f.sp+0x00000050u), s.dx);
  }
  L0069c287: { // 0x69c287: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L0069c28a: { // 0x69c28a: 89442454 MOV dword ptr [ESP + 0x54],EAX
    m.w32((f.sp+0x00000054u), s.ax);
  }
  L0069c28e: { // 0x69c28e: e8bde70c00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6931091u); flags=s.arithmetic_flags;
  }
  L0069c293: { // 0x69c293: d9442450 FLD float ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    s.fp.load32(m.r32(address));
  }
  L0069c297: { // 0x69c297: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0069c299: { // 0x69c299: e8b2e70c00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6931102u); flags=s.arithmetic_flags;
  }
  L0069c29e: { // 0x69c29e: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0069c2a0: { // 0x69c2a0: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0069c2a2: { // 0x69c2a2: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069c2a3: { // 0x69c2a3: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0069c2a9: { // 0x69c2a9: 81e6ff000000 AND ESI,0xff
    s.si = integer::logical((s.si)&(0x000000ffu),32,flags);
  }
  L0069c2af: { // 0x69c2af: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0069c2b1: { // 0x69c2b1: 89742458 MOV dword ptr [ESP + 0x58],ESI
    m.w32((f.sp+0x00000058u), s.si);
  }
  L0069c2b5: { // 0x69c2b5: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069c2b8: { // 0x69c2b8: 6689442428 MOV word ptr [ESP + 0x28],AX
    m.w16((f.sp+0x00000028u), (s.ax & 0xffffu));
  }
  L0069c2bd: { // 0x69c2bd: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0069c2bf: { // 0x69c2bf: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069c2c0: { // 0x69c2c0: 81e1ff000000 AND ECX,0xff
    s.cx = integer::logical((s.cx)&(0x000000ffu),32,flags);
  }
  L0069c2c6: { // 0x69c2c6: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0069c2cc: { // 0x69c2cc: 894c245c MOV dword ptr [ESP + 0x5c],ECX
    m.w32((f.sp+0x0000005cu), s.cx);
  }
  L0069c2d0: { // 0x69c2d0: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0069c2d2: { // 0x69c2d2: 8d4c2458 LEA ECX,[ESP + 0x58]
    s.cx = (f.sp+0x00000058u);
  }
  L0069c2d6: { // 0x69c2d6: 8d542444 LEA EDX,[ESP + 0x44]
    s.dx = (f.sp+0x00000044u);
  }
  L0069c2da: { // 0x69c2da: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069c2dd: { // 0x69c2dd: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0069c2df: { // 0x69c2df: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0069c2e0: { // 0x69c2e0: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0069c2e1: { // 0x69c2e1: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0069c2e3: { // 0x69c2e3: 6689442432 MOV word ptr [ESP + 0x32],AX
    m.w16((f.sp+0x00000032u), (s.ax & 0xffffu));
  }
  L0069c2e8: { // 0x69c2e8: 89742468 MOV dword ptr [ESP + 0x68],ESI
    m.w32((f.sp+0x00000068u), s.si);
  }
  L0069c2ec: { // 0x69c2ec: e8efbaffff CALL 0x00697de0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00697de0u,6931185u); flags=s.arithmetic_flags;
  }
  L0069c2f1: { // 0x69c2f1: 8b0d70198200 MOV ECX,dword ptr [0x00821970]
    s.cx = m.r32((0x00821970u));
  }
  L0069c2f7: { // 0x69c2f7: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L0069c2f9: { // 0x69c2f9: 8b1574198200 MOV EDX,dword ptr [0x00821974]
    s.dx = m.r32((0x00821974u));
  }
  L0069c2ff: { // 0x69c2ff: 8b5b04 MOV EBX,dword ptr [EBX + 0x4]
    s.bx = m.r32((s.bx+0x00000004u));
  }
  L0069c302: { // 0x69c302: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L0069c304: { // 0x69c304: 2bda SUB EBX,EDX
    s.bx = integer::sub(s.bx,s.dx,32,flags);
  }
  L0069c306: { // 0x69c306: 895c2438 MOV dword ptr [ESP + 0x38],EBX
    m.w32((f.sp+0x00000038u), s.bx);
  }
  L0069c30a: { // 0x69c30a: 8944243c MOV dword ptr [ESP + 0x3c],EAX
    m.w32((f.sp+0x0000003cu), s.ax);
  }
  L0069c30e: { // 0x69c30e: 8dabb4000000 LEA EBP,[EBX + 0xb4]
    s.bp = (s.bx+0x000000b4u);
  }
  L0069c314: { // 0x69c314: 895c2440 MOV dword ptr [ESP + 0x40],EBX
    m.w32((f.sp+0x00000040u), s.bx);
  }
  L0069c318: { // 0x69c318: 89442434 MOV dword ptr [ESP + 0x34],EAX
    m.w32((f.sp+0x00000034u), s.ax);
  }
  L0069c31c: { // 0x69c31c: 896c2438 MOV dword ptr [ESP + 0x38],EBP
    m.w32((f.sp+0x00000038u), s.bp);
  }
  L0069c320: { // 0x69c320: 89742424 MOV dword ptr [ESP + 0x24],ESI
    m.w32((f.sp+0x00000024u), s.si);
  }
  L0069c324: { // 0x69c324: eb04 JMP 0x0069c32a
    goto L0069c32a;
  }
  L0069c326: { // 0x69c326: 8b6c2438 MOV EBP,dword ptr [ESP + 0x38]
    s.bp = m.r32((f.sp+0x00000038u));
  }
  L0069c32a: { // 0x69c32a: 8b87b0000000 MOV EAX,dword ptr [EDI + 0xb0]
    s.ax = m.r32((s.di+0x000000b0u));
  }
  L0069c330: { // 0x69c330: 8b542434 MOV EDX,dword ptr [ESP + 0x34]
    s.dx = m.r32((f.sp+0x00000034u));
  }
  L0069c334: { // 0x69c334: 8b8fb4000000 MOV ECX,dword ptr [EDI + 0xb4]
    s.cx = m.r32((s.di+0x000000b4u));
  }
  L0069c33a: { // 0x69c33a: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0069c33c: { // 0x69c33c: 89442444 MOV dword ptr [ESP + 0x44],EAX
    m.w32((f.sp+0x00000044u), s.ax);
  }
  L0069c340: { // 0x69c340: 03cd ADD ECX,EBP
    s.cx = integer::add(s.cx,s.bp,32,flags);
  }
  L0069c342: { // 0x69c342: db442444 FILD dword ptr [ESP + 0x44]
    const auto address=(f.sp+0x00000044u);
    s.fp.load_integer32(m.r32(address));
  }
  L0069c346: { // 0x69c346: 894c2448 MOV dword ptr [ESP + 0x48],ECX
    m.w32((f.sp+0x00000048u), s.cx);
  }
  L0069c34a: { // 0x69c34a: 8d442458 LEA EAX,[ESP + 0x58]
    s.ax = (f.sp+0x00000058u);
  }
  L0069c34e: { // 0x69c34e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0069c34f: { // 0x69c34f: 8d97e40d0000 LEA EDX,[EDI + 0xde4]
    s.dx = (s.di+0x00000de4u);
  }
  L0069c355: { // 0x69c355: d95c245c FSTP float ptr [ESP + 0x5c]
    const auto address=(f.sp+0x0000005cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0069c359: { // 0x69c359: db44244c FILD dword ptr [ESP + 0x4c]
    const auto address=(f.sp+0x0000004cu);
    s.fp.load_integer32(m.r32(address));
  }
  L0069c35d: { // 0x69c35d: 8d4c2474 LEA ECX,[ESP + 0x74]
    s.cx = (f.sp+0x00000074u);
  }
  L0069c361: { // 0x69c361: c744246400000000 MOV dword ptr [ESP + 0x64],0x0
    m.w32((f.sp+0x00000064u), 0x00000000u);
  }
  L0069c369: { // 0x69c369: d95c2460 FSTP float ptr [ESP + 0x60]
    const auto address=(f.sp+0x00000060u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0069c36d: { // 0x69c36d: e80e1eefff CALL 0x0058e180
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058e180u,6931314u); flags=s.arithmetic_flags;
  }
  L0069c372: { // 0x69c372: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0069c374: { // 0x69c374: 894c2458 MOV dword ptr [ESP + 0x58],ECX
    m.w32((f.sp+0x00000058u), s.cx);
  }
  L0069c378: { // 0x69c378: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0069c37b: { // 0x69c37b: d9442458 FLD float ptr [ESP + 0x58]
    const auto address=(f.sp+0x00000058u);
    s.fp.load32(m.r32(address));
  }
  L0069c37f: { // 0x69c37f: 8954245c MOV dword ptr [ESP + 0x5c],EDX
    m.w32((f.sp+0x0000005cu), s.dx);
  }
  L0069c383: { // 0x69c383: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L0069c386: { // 0x69c386: 89442460 MOV dword ptr [ESP + 0x60],EAX
    m.w32((f.sp+0x00000060u), s.ax);
  }
  L0069c38a: { // 0x69c38a: e8c1e60c00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6931343u); flags=s.arithmetic_flags;
  }
  L0069c38f: { // 0x69c38f: d944245c FLD float ptr [ESP + 0x5c]
    const auto address=(f.sp+0x0000005cu);
    s.fp.load32(m.r32(address));
  }
  L0069c393: { // 0x69c393: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0069c395: { // 0x69c395: e8b6e60c00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6931354u); flags=s.arithmetic_flags;
  }
  L0069c39a: { // 0x69c39a: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0069c39c: { // 0x69c39c: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0069c39e: { // 0x69c39e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069c39f: { // 0x69c39f: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0069c3a5: { // 0x69c3a5: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0069c3a7: { // 0x69c3a7: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069c3aa: { // 0x69c3aa: 668944242c MOV word ptr [ESP + 0x2c],AX
    m.w16((f.sp+0x0000002cu), (s.ax & 0xffffu));
  }
  L0069c3af: { // 0x69c3af: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0069c3b1: { // 0x69c3b1: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069c3b2: { // 0x69c3b2: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0069c3b8: { // 0x69c3b8: 8d4c242c LEA ECX,[ESP + 0x2c]
    s.cx = (f.sp+0x0000002cu);
  }
  L0069c3bc: { // 0x69c3bc: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0069c3be: { // 0x69c3be: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0069c3bf: { // 0x69c3bf: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069c3c2: { // 0x69c3c2: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069c3c7: { // 0x69c3c7: 6689442432 MOV word ptr [ESP + 0x32],AX
    m.w16((f.sp+0x00000032u), (s.ax & 0xffffu));
  }
  L0069c3cc: { // 0x69c3cc: e82f91eaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6931409u); flags=s.arithmetic_flags;
  }
  L0069c3d1: { // 0x69c3d1: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0069c3d3: { // 0x69c3d3: 0fbe861b010000 MOVSX EAX,byte ptr [ESI + 0x11b]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.si+0x0000011bu)),8));
  }
  L0069c3da: { // 0x69c3da: 8d0440 LEA EAX,[EAX + EAX*0x2]
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  L0069c3dd: { // 0x69c3dd: 8d1480 LEA EDX,[EAX + EAX*0x4]
    s.dx = (s.ax+(s.ax * 0x00000004u));
  }
  L0069c3e0: { // 0x69c3e0: 8b8640010000 MOV EAX,dword ptr [ESI + 0x140]
    s.ax = m.r32((s.si+0x00000140u));
  }
  L0069c3e6: { // 0x69c3e6: 2bea SUB EBP,EDX
    s.bp = integer::sub(s.bp,s.dx,32,flags);
  }
  L0069c3e8: { // 0x69c3e8: 896c2418 MOV dword ptr [ESP + 0x18],EBP
    m.w32((f.sp+0x00000018u), s.bp);
  }
  L0069c3ec: { // 0x69c3ec: bd00010000 MOV EBP,0x100
    s.bp = 0x00000100u;
  }
  L0069c3f1: { // 0x69c3f1: 85c5 TEST EBP,EAX
    (void)integer::logical((s.bp)&(s.ax),32,flags);
  }
  L0069c3f3: { // 0x69c3f3: 0f844b020000 JZ 0x0069c644
    if(integer::condition("JZ",flags)) goto L0069c644;
  }
  L0069c3f9: { // 0x69c3f9: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  L0069c3fb: { // 0x69c3fb: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0069c3fd: { // 0x69c3fd: e8bea2ddff CALL 0x004766c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004766c0u,6931458u); flags=s.arithmetic_flags;
  }
  L0069c402: { // 0x69c402: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  L0069c404: { // 0x69c404: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0069c406: { // 0x69c406: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L0069c40a: { // 0x69c40a: e8b1a2ddff CALL 0x004766c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004766c0u,6931471u); flags=s.arithmetic_flags;
  }
  L0069c40f: { // 0x69c40f: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L0069c413: { // 0x69c413: 8b8640010000 MOV EAX,dword ptr [ESI + 0x140]
    s.ax = m.r32((s.si+0x00000140u));
  }
  L0069c419: { // 0x69c419: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L0069c41c: { // 0x69c41c: 741b JZ 0x0069c439
    if(integer::condition("JZ",flags)) goto L0069c439;
  }
  L0069c41e: { // 0x69c41e: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0069c420: { // 0x69c420: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0069c422: { // 0x69c422: e899a2ddff CALL 0x004766c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004766c0u,6931495u); flags=s.arithmetic_flags;
  }
  L0069c427: { // 0x69c427: 8b8840010000 MOV ECX,dword ptr [EAX + 0x140]
    s.cx = m.r32((s.ax+0x00000140u));
  }
  L0069c42d: { // 0x69c42d: c684248400000001 MOV byte ptr [ESP + 0x84],0x1
    m.w8((f.sp+0x00000084u), 0x00000001u);
  }
  L0069c435: { // 0x69c435: 85cd TEST EBP,ECX
    (void)integer::logical((s.bp)&(s.cx),32,flags);
  }
  L0069c437: { // 0x69c437: 7408 JZ 0x0069c441
    if(integer::condition("JZ",flags)) goto L0069c441;
  }
  L0069c439: { // 0x69c439: c684248400000000 MOV byte ptr [ESP + 0x84],0x0
    m.w8((f.sp+0x00000084u), 0x00000000u);
  }
  L0069c441: { // 0x69c441: 8b8640010000 MOV EAX,dword ptr [ESI + 0x140]
    s.ax = m.r32((s.si+0x00000140u));
  }
  L0069c447: { // 0x69c447: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L0069c44a: { // 0x69c44a: 7518 JNZ 0x0069c464
    if(integer::condition("JNZ",flags)) goto L0069c464;
  }
  L0069c44c: { // 0x69c44c: 6a06 PUSH 0x6
    f.push(m,0x00000006u);
  }
  L0069c44e: { // 0x69c44e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0069c450: { // 0x69c450: e86ba2ddff CALL 0x004766c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004766c0u,6931541u); flags=s.arithmetic_flags;
  }
  L0069c455: { // 0x69c455: 8b8840010000 MOV ECX,dword ptr [EAX + 0x140]
    s.cx = m.r32((s.ax+0x00000140u));
  }
  L0069c45b: { // 0x69c45b: c644241301 MOV byte ptr [ESP + 0x13],0x1
    m.w8((f.sp+0x00000013u), 0x00000001u);
  }
  L0069c460: { // 0x69c460: 85cd TEST EBP,ECX
    (void)integer::logical((s.bp)&(s.cx),32,flags);
  }
  L0069c462: { // 0x69c462: 7405 JZ 0x0069c469
    if(integer::condition("JZ",flags)) goto L0069c469;
  }
  L0069c464: { // 0x69c464: c644241300 MOV byte ptr [ESP + 0x13],0x0
    m.w8((f.sp+0x00000013u), 0x00000000u);
  }
  L0069c469: { // 0x69c469: 8b8e40010000 MOV ECX,dword ptr [ESI + 0x140]
    s.cx = m.r32((s.si+0x00000140u));
  }
  L0069c46f: { // 0x69c46f: 81e100080000 AND ECX,0x800
    s.cx = integer::logical((s.cx)&(0x00000800u),32,flags);
  }
  L0069c475: { // 0x69c475: 7411 JZ 0x0069c488
    if(integer::condition("JZ",flags)) goto L0069c488;
  }
  L0069c477: { // 0x69c477: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L0069c47b: { // 0x69c47b: c644241401 MOV byte ptr [ESP + 0x14],0x1
    m.w8((f.sp+0x00000014u), 0x00000001u);
  }
  L0069c480: { // 0x69c480: 85a840010000 TEST dword ptr [EAX + 0x140],EBP
    (void)integer::logical((m.r32((s.ax+0x00000140u)))&(s.bp),32,flags);
  }
  L0069c486: { // 0x69c486: 7405 JZ 0x0069c48d
    if(integer::condition("JZ",flags)) goto L0069c48d;
  }
  L0069c488: { // 0x69c488: c644241400 MOV byte ptr [ESP + 0x14],0x0
    m.w8((f.sp+0x00000014u), 0x00000000u);
  }
  L0069c48d: { // 0x69c48d: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0069c48f: { // 0x69c48f: 7511 JNZ 0x0069c4a2
    if(integer::condition("JNZ",flags)) goto L0069c4a2;
  }
  L0069c491: { // 0x69c491: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L0069c495: { // 0x69c495: c644241601 MOV byte ptr [ESP + 0x16],0x1
    m.w8((f.sp+0x00000016u), 0x00000001u);
  }
  L0069c49a: { // 0x69c49a: 85aa40010000 TEST dword ptr [EDX + 0x140],EBP
    (void)integer::logical((m.r32((s.dx+0x00000140u)))&(s.bp),32,flags);
  }
  L0069c4a0: { // 0x69c4a0: 7405 JZ 0x0069c4a7
    if(integer::condition("JZ",flags)) goto L0069c4a7;
  }
  L0069c4a2: { // 0x69c4a2: c644241600 MOV byte ptr [ESP + 0x16],0x0
    m.w8((f.sp+0x00000016u), 0x00000000u);
  }
  L0069c4a7: { // 0x69c4a7: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0069c4a9: { // 0x69c4a9: 742f JZ 0x0069c4da
    if(integer::condition("JZ",flags)) goto L0069c4da;
  }
  L0069c4ab: { // 0x69c4ab: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L0069c4af: { // 0x69c4af: 0fbe901b010000 MOVSX EDX,byte ptr [EAX + 0x11b]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.ax+0x0000011bu)),8));
  }
  L0069c4b6: { // 0x69c4b6: 0fbe861b010000 MOVSX EAX,byte ptr [ESI + 0x11b]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.si+0x0000011bu)),8));
  }
  L0069c4bd: { // 0x69c4bd: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0069c4bf: { // 0x69c4bf: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069c4c0: { // 0x69c4c0: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L0069c4c2: { // 0x69c4c2: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0069c4c4: { // 0x69c4c4: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0069c4c7: { // 0x69c4c7: 7f11 JG 0x0069c4da
    if(integer::condition("JG",flags)) goto L0069c4da;
  }
  L0069c4c9: { // 0x69c4c9: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L0069c4cd: { // 0x69c4cd: c644241701 MOV byte ptr [ESP + 0x17],0x1
    m.w8((f.sp+0x00000017u), 0x00000001u);
  }
  L0069c4d2: { // 0x69c4d2: 85a840010000 TEST dword ptr [EAX + 0x140],EBP
    (void)integer::logical((m.r32((s.ax+0x00000140u)))&(s.bp),32,flags);
  }
  L0069c4d8: { // 0x69c4d8: 7405 JZ 0x0069c4df
    if(integer::condition("JZ",flags)) goto L0069c4df;
  }
  L0069c4da: { // 0x69c4da: c644241700 MOV byte ptr [ESP + 0x17],0x0
    m.w8((f.sp+0x00000017u), 0x00000000u);
  }
  L0069c4df: { // 0x69c4df: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0069c4e1: { // 0x69c4e1: 752d JNZ 0x0069c510
    if(integer::condition("JNZ",flags)) goto L0069c510;
  }
  L0069c4e3: { // 0x69c4e3: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L0069c4e7: { // 0x69c4e7: 0fbe861b010000 MOVSX EAX,byte ptr [ESI + 0x11b]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.si+0x0000011bu)),8));
  }
  L0069c4ee: { // 0x69c4ee: 0fbe911b010000 MOVSX EDX,byte ptr [ECX + 0x11b]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.cx+0x0000011bu)),8));
  }
  L0069c4f5: { // 0x69c4f5: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0069c4f7: { // 0x69c4f7: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069c4f8: { // 0x69c4f8: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L0069c4fa: { // 0x69c4fa: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0069c4fc: { // 0x69c4fc: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0069c4ff: { // 0x69c4ff: 7f0f JG 0x0069c510
    if(integer::condition("JG",flags)) goto L0069c510;
  }
  L0069c501: { // 0x69c501: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0069c503: { // 0x69c503: c644241501 MOV byte ptr [ESP + 0x15],0x1
    m.w8((f.sp+0x00000015u), 0x00000001u);
  }
  L0069c508: { // 0x69c508: 85a840010000 TEST dword ptr [EAX + 0x140],EBP
    (void)integer::logical((m.r32((s.ax+0x00000140u)))&(s.bp),32,flags);
  }
  L0069c50e: { // 0x69c50e: 7405 JZ 0x0069c515
    if(integer::condition("JZ",flags)) goto L0069c515;
  }
  L0069c510: { // 0x69c510: c644241500 MOV byte ptr [ESP + 0x15],0x0
    m.w8((f.sp+0x00000015u), 0x00000000u);
  }
  L0069c515: { // 0x69c515: 0fbf4e26 MOVSX ECX,word ptr [ESI + 0x26]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000026u)),16));
  }
  L0069c519: { // 0x69c519: 0fbf4624 MOVSX EAX,word ptr [ESI + 0x24]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000024u)),16));
  }
  L0069c51d: { // 0x69c51d: c1e108 SHL ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::left);
  }
  L0069c520: { // 0x69c520: 81c180000000 ADD ECX,0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L0069c526: { // 0x69c526: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0069c528: { // 0x69c528: 83c180 ADD ECX,-0x80
    s.cx = integer::add(s.cx,0xffffff80u,32,flags);
  }
  L0069c52b: { // 0x69c52b: 8954246c MOV dword ptr [ESP + 0x6c],EDX
    m.w32((f.sp+0x0000006cu), s.dx);
  }
  L0069c52f: { // 0x69c52f: c1e008 SHL EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::left);
  }
  L0069c532: { // 0x69c532: 894c2468 MOV dword ptr [ESP + 0x68],ECX
    m.w32((f.sp+0x00000068u), s.cx);
  }
  L0069c536: { // 0x69c536: 0580000000 ADD EAX,0x80
    s.ax = integer::add(s.ax,0x00000080u,32,flags);
  }
  L0069c53b: { // 0x69c53b: 8d4c2464 LEA ECX,[ESP + 0x64]
    s.cx = (f.sp+0x00000064u);
  }
  L0069c53f: { // 0x69c53f: 8d54244c LEA EDX,[ESP + 0x4c]
    s.dx = (f.sp+0x0000004cu);
  }
  L0069c543: { // 0x69c543: 83c080 ADD EAX,-0x80
    s.ax = integer::add(s.ax,0xffffff80u,32,flags);
  }
  L0069c546: { // 0x69c546: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0069c547: { // 0x69c547: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0069c548: { // 0x69c548: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0069c54a: { // 0x69c54a: 8944246c MOV dword ptr [ESP + 0x6c],EAX
    m.w32((f.sp+0x0000006cu), s.ax);
  }
  L0069c54e: { // 0x69c54e: e88db8ffff CALL 0x00697de0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00697de0u,6931795u); flags=s.arithmetic_flags;
  }
  L0069c553: { // 0x69c553: 8b28 MOV EBP,dword ptr [EAX]
    s.bp = m.r32((s.ax));
  }
  L0069c555: { // 0x69c555: 8b97b4000000 MOV EDX,dword ptr [EDI + 0xb4]
    s.dx = m.r32((s.di+0x000000b4u));
  }
  L0069c55b: { // 0x69c55b: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L0069c55e: { // 0x69c55e: 8b87b0000000 MOV EAX,dword ptr [EDI + 0xb0]
    s.ax = m.r32((s.di+0x000000b0u));
  }
  L0069c564: { // 0x69c564: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L0069c566: { // 0x69c566: 2be8 SUB EBP,EAX
    s.bp = integer::sub(s.bp,s.ax,32,flags);
  }
  L0069c568: { // 0x69c568: 0fbe961b010000 MOVSX EDX,byte ptr [ESI + 0x11b]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.si+0x0000011bu)),8));
  }
  L0069c56f: { // 0x69c56f: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L0069c571: { // 0x69c571: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L0069c574: { // 0x69c574: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0069c576: { // 0x69c576: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L0069c578: { // 0x69c578: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
  L0069c57a: { // 0x69c57a: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069c57b: { // 0x69c57b: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0069c57d: { // 0x69c57d: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069c57f: { // 0x69c57f: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0069c581: { // 0x69c581: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L0069c583: { // 0x69c583: 7f30 JG 0x0069c5b5
    if(integer::condition("JG",flags)) goto L0069c5b5;
  }
  L0069c585: { // 0x69c585: 8a442414 MOV AL,byte ptr [ESP + 0x14]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000014u)));
  }
  L0069c589: { // 0x69c589: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0069c58b: { // 0x69c58b: 0f8525010000 JNZ 0x0069c6b6
    if(integer::condition("JNZ",flags)) goto L0069c6b6;
  }
  L0069c591: { // 0x69c591: 8a442415 MOV AL,byte ptr [ESP + 0x15]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000015u)));
  }
  L0069c595: { // 0x69c595: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0069c597: { // 0x69c597: 0f8519010000 JNZ 0x0069c6b6
    if(integer::condition("JNZ",flags)) goto L0069c6b6;
  }
  L0069c59d: { // 0x69c59d: 8a442416 MOV AL,byte ptr [ESP + 0x16]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000016u)));
  }
  L0069c5a1: { // 0x69c5a1: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0069c5a3: { // 0x69c5a3: 0f85d9000000 JNZ 0x0069c682
    if(integer::condition("JNZ",flags)) goto L0069c682;
  }
  L0069c5a9: { // 0x69c5a9: 8a442417 MOV AL,byte ptr [ESP + 0x17]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000017u)));
  }
  L0069c5ad: { // 0x69c5ad: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0069c5af: { // 0x69c5af: 0f85cd000000 JNZ 0x0069c682
    if(integer::condition("JNZ",flags)) goto L0069c682;
  }
  L0069c5b5: { // 0x69c5b5: 8a842484000000 MOV AL,byte ptr [ESP + 0x84]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000084u)));
  }
  L0069c5bc: { // 0x69c5bc: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0069c5be: { // 0x69c5be: 7526 JNZ 0x0069c5e6
    if(integer::condition("JNZ",flags)) goto L0069c5e6;
  }
  L0069c5c0: { // 0x69c5c0: 8a442413 MOV AL,byte ptr [ESP + 0x13]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000013u)));
  }
  L0069c5c4: { // 0x69c5c4: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0069c5c6: { // 0x69c5c6: 751e JNZ 0x0069c5e6
    if(integer::condition("JNZ",flags)) goto L0069c5e6;
  }
  L0069c5c8: { // 0x69c5c8: 8b8640010000 MOV EAX,dword ptr [ESI + 0x140]
    s.ax = m.r32((s.si+0x00000140u));
  }
  L0069c5ce: { // 0x69c5ce: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0069c5d2: { // 0x69c5d2: 2500010000 AND EAX,0x100
    s.ax = integer::logical((s.ax)&(0x00000100u),32,flags);
  }
  L0069c5d7: { // 0x69c5d7: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L0069c5d9: { // 0x69c5d9: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  L0069c5db: { // 0x69c5db: 83e03c AND EAX,0x3c
    s.ax = integer::logical((s.ax)&(0x0000003cu),32,flags);
  }
  L0069c5de: { // 0x69c5de: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L0069c5e0: { // 0x69c5e0: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0069c5e4: { // 0x69c5e4: eb5e JMP 0x0069c644
    goto L0069c644;
  }
  L0069c5e6: { // 0x69c5e6: 8b5c243c MOV EBX,dword ptr [ESP + 0x3c]
    s.bx = m.r32((f.sp+0x0000003cu));
  }
  L0069c5ea: { // 0x69c5ea: 8a842484000000 MOV AL,byte ptr [ESP + 0x84]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000084u)));
  }
  L0069c5f1: { // 0x69c5f1: 2bdd SUB EBX,EBP
    s.bx = integer::sub(s.bx,s.bp,32,flags);
  }
  L0069c5f3: { // 0x69c5f3: 8b6c2440 MOV EBP,dword ptr [ESP + 0x40]
    s.bp = m.r32((f.sp+0x00000040u));
  }
  L0069c5f7: { // 0x69c5f7: 2be9 SUB EBP,ECX
    s.bp = integer::sub(s.bp,s.cx,32,flags);
  }
  L0069c5f9: { // 0x69c5f9: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0069c5fb: { // 0x69c5fb: 7410 JZ 0x0069c60d
    if(integer::condition("JZ",flags)) goto L0069c60d;
  }
  L0069c5fd: { // 0x69c5fd: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L0069c5ff: { // 0x69c5ff: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0069c601: { // 0x69c601: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069c602: { // 0x69c602: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0069c604: { // 0x69c604: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069c606: { // 0x69c606: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L0069c608: { // 0x69c608: 83f90f CMP ECX,0xf
    (void)integer::sub(s.cx,0x0000000fu,32,flags);
  }
  L0069c60b: { // 0x69c60b: 7f16 JG 0x0069c623
    if(integer::condition("JG",flags)) goto L0069c623;
  }
  L0069c60d: { // 0x69c60d: 8a442413 MOV AL,byte ptr [ESP + 0x13]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000013u)));
  }
  L0069c611: { // 0x69c611: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0069c613: { // 0x69c613: 742b JZ 0x0069c640
    if(integer::condition("JZ",flags)) goto L0069c640;
  }
  L0069c615: { // 0x69c615: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L0069c617: { // 0x69c617: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069c618: { // 0x69c618: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0069c61a: { // 0x69c61a: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069c61c: { // 0x69c61c: 03c5 ADD EAX,EBP
    s.ax = integer::add(s.ax,s.bp,32,flags);
  }
  L0069c61e: { // 0x69c61e: 83f80f CMP EAX,0xf
    (void)integer::sub(s.ax,0x0000000fu,32,flags);
  }
  L0069c621: { // 0x69c621: 7e1d JLE 0x0069c640
    if(integer::condition("JLE",flags)) goto L0069c640;
  }
  L0069c623: { // 0x69c623: 8b9640010000 MOV EDX,dword ptr [ESI + 0x140]
    s.dx = m.r32((s.si+0x00000140u));
  }
  L0069c629: { // 0x69c629: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0069c62d: { // 0x69c62d: 81e200010000 AND EDX,0x100
    s.dx = integer::logical((s.dx)&(0x00000100u),32,flags);
  }
  L0069c633: { // 0x69c633: f7da NEG EDX
    s.dx = integer::sub(0u,s.dx,32,flags);
  }
  L0069c635: { // 0x69c635: 1bd2 SBB EDX,EDX
    s.dx = integer::sub(s.dx,s.dx,32,flags,flags&integer::CF);
  }
  L0069c637: { // 0x69c637: 83e23c AND EDX,0x3c
    s.dx = integer::logical((s.dx)&(0x0000003cu),32,flags);
  }
  L0069c63a: { // 0x69c63a: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0069c63c: { // 0x69c63c: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0069c640: { // 0x69c640: 8b5c2440 MOV EBX,dword ptr [ESP + 0x40]
    s.bx = m.r32((f.sp+0x00000040u));
  }
  L0069c644: { // 0x69c644: 395c2418 CMP dword ptr [ESP + 0x18],EBX
    (void)integer::sub(m.r32((f.sp+0x00000018u)),s.bx,32,flags);
  }
  L0069c648: { // 0x69c648: 0f8e9c000000 JLE 0x0069c6ea
    if(integer::condition("JLE",flags)) goto L0069c6ea;
  }
  L0069c64e: { // 0x69c64e: 8b742438 MOV ESI,dword ptr [ESP + 0x38]
    s.si = m.r32((f.sp+0x00000038u));
  }
  L0069c652: { // 0x69c652: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L0069c656: { // 0x69c656: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L0069c657: { // 0x69c657: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0069c658: { // 0x69c658: 3db4000000 CMP EAX,0xb4
    (void)integer::sub(s.ax,0x000000b4u,32,flags);
  }
  L0069c65d: { // 0x69c65d: 89742438 MOV dword ptr [ESP + 0x38],ESI
    m.w32((f.sp+0x00000038u), s.si);
  }
  L0069c661: { // 0x69c661: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L0069c665: { // 0x69c665: 0f8cbbfcffff JL 0x0069c326
    if(integer::condition("JL",flags)) goto L0069c326;
  }
  L0069c66b: { // 0x69c66b: 8b842480000000 MOV EAX,dword ptr [ESP + 0x80]
    s.ax = m.r32((f.sp+0x00000080u));
  }
  L0069c672: { // 0x69c672: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L0069c676: { // 0x69c676: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0069c677: { // 0x69c677: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0069c678: { // 0x69c678: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0069c679: { // 0x69c679: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L0069c67b: { // 0x69c67b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0069c67c: { // 0x69c67c: 83c46c ADD ESP,0x6c
    f.sp = integer::add(f.sp,0x0000006cu,32,flags);
  }
  L0069c67f: { // 0x69c67f: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0069c682: { // 0x69c682: 8b54242c MOV EDX,dword ptr [ESP + 0x2c]
    s.dx = m.r32((f.sp+0x0000002cu));
  }
  L0069c686: { // 0x69c686: 668b44242e MOV AX,word ptr [ESP + 0x2e]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x0000002eu)));
  }
  L0069c68b: { // 0x69c68b: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L0069c68c: { // 0x69c68c: 6689842486000000 MOV word ptr [ESP + 0x86],AX
    m.w16((f.sp+0x00000086u), (s.ax & 0xffffu));
  }
  L0069c694: { // 0x69c694: 8b842480000000 MOV EAX,dword ptr [ESP + 0x80]
    s.ax = m.r32((f.sp+0x00000080u));
  }
  L0069c69b: { // 0x69c69b: 6689942484000000 MOV word ptr [ESP + 0x84],DX
    m.w16((f.sp+0x00000084u), (s.dx & 0xffffu));
  }
  L0069c6a3: { // 0x69c6a3: 8b8c2484000000 MOV ECX,dword ptr [ESP + 0x84]
    s.cx = m.r32((f.sp+0x00000084u));
  }
  L0069c6aa: { // 0x69c6aa: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0069c6ab: { // 0x69c6ab: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0069c6ac: { // 0x69c6ac: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0069c6ad: { // 0x69c6ad: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L0069c6af: { // 0x69c6af: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0069c6b0: { // 0x69c6b0: 83c46c ADD ESP,0x6c
    f.sp = integer::add(f.sp,0x0000006cu,32,flags);
  }
  L0069c6b3: { // 0x69c6b3: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0069c6b6: { // 0x69c6b6: 8b54242e MOV EDX,dword ptr [ESP + 0x2e]
    s.dx = m.r32((f.sp+0x0000002eu));
  }
  L0069c6ba: { // 0x69c6ba: 668b4c242c MOV CX,word ptr [ESP + 0x2c]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x0000002cu)));
  }
  L0069c6bf: { // 0x69c6bf: 8b842480000000 MOV EAX,dword ptr [ESP + 0x80]
    s.ax = m.r32((f.sp+0x00000080u));
  }
  L0069c6c6: { // 0x69c6c6: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L0069c6c7: { // 0x69c6c7: 66898c2484000000 MOV word ptr [ESP + 0x84],CX
    m.w16((f.sp+0x00000084u), (s.cx & 0xffffu));
  }
  L0069c6cf: { // 0x69c6cf: 6689942486000000 MOV word ptr [ESP + 0x86],DX
    m.w16((f.sp+0x00000086u), (s.dx & 0xffffu));
  }
  L0069c6d7: { // 0x69c6d7: 8b8c2484000000 MOV ECX,dword ptr [ESP + 0x84]
    s.cx = m.r32((f.sp+0x00000084u));
  }
  L0069c6de: { // 0x69c6de: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0069c6df: { // 0x69c6df: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0069c6e0: { // 0x69c6e0: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0069c6e1: { // 0x69c6e1: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L0069c6e3: { // 0x69c6e3: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0069c6e4: { // 0x69c6e4: 83c46c ADD ESP,0x6c
    f.sp = integer::add(f.sp,0x0000006cu,32,flags);
  }
  L0069c6e7: { // 0x69c6e7: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0069c6ea: { // 0x69c6ea: 8b842480000000 MOV EAX,dword ptr [ESP + 0x80]
    s.ax = m.r32((f.sp+0x00000080u));
  }
  L0069c6f1: { // 0x69c6f1: 8b4c242c MOV ECX,dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L0069c6f5: { // 0x69c6f5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0069c6f6: { // 0x69c6f6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0069c6f7: { // 0x69c6f7: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0069c6f8: { // 0x69c6f8: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L0069c6fa: { // 0x69c6fa: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0069c6fb: { // 0x69c6fb: 83c46c ADD ESP,0x6c
    f.sp = integer::add(f.sp,0x0000006cu,32,flags);
  }
  L0069c6fe: { // 0x69c6fe: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
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
void f_00297de0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00697de0: { // 0x697de0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00697de3: { // 0x697de3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00697de4: { // 0x697de4: 8b5c2414 MOV EBX,dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  L00697de8: { // 0x697de8: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00697de9: { // 0x697de9: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00697dea: { // 0x697dea: 8b33 MOV ESI,dword ptr [EBX]
    s.si = m.r32((s.bx));
  }
  L00697dec: { // 0x697dec: 8b4304 MOV EAX,dword ptr [EBX + 0x4]
    s.ax = m.r32((s.bx+0x00000004u));
  }
  L00697def: { // 0x697def: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00697df3: { // 0x697df3: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L00697df7: { // 0x697df7: 8d0476 LEA EAX,[ESI + ESI*0x2]
    s.ax = (s.si+(s.si * 0x00000002u));
  }
  L00697dfa: { // 0x697dfa: 8b5b08 MOV EBX,dword ptr [EBX + 0x8]
    s.bx = m.r32((s.bx+0x00000008u));
  }
  L00697dfd: { // 0x697dfd: c744241c00000000 MOV dword ptr [ESP + 0x1c],0x0
    m.w32((f.sp+0x0000001cu), 0x00000000u);
  }
  L00697e05: { // 0x697e05: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L00697e08: { // 0x697e08: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L00697e0b: { // 0x697e0b: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00697e0c: { // 0x697e0c: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00697e0e: { // 0x697e0e: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00697e10: { // 0x697e10: 8d0476 LEA EAX,[ESI + ESI*0x2]
    s.ax = (s.si+(s.si * 0x00000002u));
  }
  L00697e13: { // 0x697e13: d1f9 SAR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00697e15: { // 0x697e15: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L00697e18: { // 0x697e18: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
  L00697e1a: { // 0x697e1a: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00697e1b: { // 0x697e1b: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00697e1d: { // 0x697e1d: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00697e1f: { // 0x697e1f: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L00697e21: { // 0x697e21: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L00697e24: { // 0x697e24: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  L00697e26: { // 0x697e26: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L00697e28: { // 0x697e28: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L00697e2b: { // 0x697e2b: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00697e2c: { // 0x697e2c: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00697e2e: { // 0x697e2e: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00697e30: { // 0x697e30: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00697e32: { // 0x697e32: 8d047f LEA EAX,[EDI + EDI*0x2]
    s.ax = (s.di+(s.di * 0x00000002u));
  }
  L00697e35: { // 0x697e35: d1fe SAR ESI,0x1
    s.si = integer::shift(s.si,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00697e37: { // 0x697e37: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L00697e3a: { // 0x697e3a: 894c240c MOV dword ptr [ESP + 0xc],ECX
    m.w32((f.sp+0x0000000cu), s.cx);
  }
  L00697e3e: { // 0x697e3e: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
  L00697e40: { // 0x697e40: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00697e41: { // 0x697e41: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00697e43: { // 0x697e43: 895c240c MOV dword ptr [ESP + 0xc],EBX
    m.w32((f.sp+0x0000000cu), s.bx);
  }
  L00697e47: { // 0x697e47: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00697e49: { // 0x697e49: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L00697e4b: { // 0x697e4b: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00697e4d: { // 0x697e4d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00697e4e: { // 0x697e4e: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00697e54: { // 0x697e54: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00697e56: { // 0x697e56: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00697e58: { // 0x697e58: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00697e5a: { // 0x697e5a: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00697e5b: { // 0x697e5b: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00697e61: { // 0x697e61: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00697e63: { // 0x697e63: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00697e65: { // 0x697e65: c1ff08 SAR EDI,0x8
    s.di = integer::shift(s.di,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00697e68: { // 0x697e68: c1fe08 SAR ESI,0x8
    s.si = integer::shift(s.si,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00697e6b: { // 0x697e6b: 81fbd8020000 CMP EBX,0x2d8
    (void)integer::sub(s.bx,0x000002d8u,32,flags);
  }
  L00697e71: { // 0x697e71: 7c08 JL 0x00697e7b
    if(integer::condition("JL",flags)) goto L00697e7b;
  }
  L00697e73: { // 0x697e73: c744241c01000000 MOV dword ptr [ESP + 0x1c],0x1
    m.w32((f.sp+0x0000001cu), 0x00000001u);
  }
  L00697e7b: { // 0x697e7b: db44240c FILD dword ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    s.fp.load_integer32(m.r32(address));
  }
  L00697e7f: { // 0x697e7f: dc0d905faa00 FMUL double ptr [0x00aa5f90]
    const auto address=(0x00aa5f90u);
    s.fp.multiply64(read64(m,address));
  }
  L00697e85: { // 0x697e85: da44241c FIADD dword ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    floating_b61::fp_extended::add_integer32(s.fp,m.r32(address));
  }
  L00697e89: { // 0x697e89: dc0528577800 FADD double ptr [0x00785728]
    const auto address=(0x00785728u);
    s.fp.add64(read64(m,address));
  }
  L00697e8f: { // 0x697e8f: e8bc2b0d00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6913684u); flags=s.arithmetic_flags;
  }
  L00697e94: { // 0x697e94: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  L00697e96: { // 0x697e96: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00697e9a: { // 0x697e9a: 8938 MOV dword ptr [EAX],EDI
    m.w32((s.ax), s.di);
  }
  L00697e9c: { // 0x697e9c: 897004 MOV dword ptr [EAX + 0x4],ESI
    m.w32((s.ax+0x00000004u), s.si);
  }
  L00697e9f: { // 0x697e9f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00697ea0: { // 0x697ea0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00697ea1: { // 0x697ea1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00697ea2: { // 0x697ea2: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00697ea5: { // 0x697ea5: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
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
void f_00145500(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00545500: { // 0x545500: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L00545504: { // 0x545504: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00545505: { // 0x545505: 0fbf4202 MOVSX EAX,word ptr [EDX + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.dx+0x00000002u)),16));
  }
  L00545509: { // 0x545509: 0fbf32 MOVSX ESI,word ptr [EDX]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.dx)),16));
  }
  L0054550c: { // 0x54550c: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L0054550f: { // 0x54550f: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L00545511: { // 0x545511: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00545512: { // 0x545512: 7814 JS 0x00545528
    if(integer::condition("JS",flags)) goto L00545528;
  }
  L00545514: { // 0x545514: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00545519: { // 0x545519: 7d0d JGE 0x00545528
    if(integer::condition("JGE",flags)) goto L00545528;
  }
  L0054551b: { // 0x54551b: 8b8938010000 MOV ECX,dword ptr [ECX + 0x138]
    s.cx = m.r32((s.cx+0x00000138u));
  }
  L00545521: { // 0x545521: 8b0481 MOV EAX,dword ptr [ECX + EAX*0x4]
    s.ax = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L00545524: { // 0x545524: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00545526: { // 0x545526: 750d JNZ 0x00545535
    if(integer::condition("JNZ",flags)) goto L00545535;
  }
  L00545528: { // 0x545528: 8b12 MOV EDX,dword ptr [EDX]
    s.dx = m.r32((s.dx));
  }
  L0054552a: { // 0x54552a: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L0054552f: { // 0x54552f: 89153476a500 MOV dword ptr [0x00a57634],EDX
    m.w32((0x00a57634u), s.dx);
  }
  L00545535: { // 0x545535: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000766c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004766c0: { // 0x004766c0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004766c1: { // 0x004766c1: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L004766c5: { // 0x004766c5: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004766c7: { // 0x004766c7: 83fa08 CMP EDX,0x8
    (void)integer::sub(s.dx,0x00000008u,32,flags);
  }
  L004766ca: { // 0x004766ca: 7346 JNC 0x00476712
    if(integer::condition("JNC",flags)) goto L00476712;
  }
  L004766cc: { // 0x004766cc: 8b4824 MOV ECX,dword ptr [EAX + 0x24]
    s.cx = m.r32((s.ax+0x00000024u));
  }
  L004766cf: { // 0x004766cf: 83e207 AND EDX,0x7
    s.dx = integer::logical((s.dx)&(0x00000007u),32,flags);
  }
  L004766d2: { // 0x004766d2: 894c2400 MOV dword ptr [ESP],ECX
    m.w32((f.sp), s.cx);
  }
  L004766d6: { // 0x004766d6: 8d0495a09d8300 LEA EAX,[EDX*0x4 + 0x839da0]
    s.ax = ((s.dx * 0x00000004u)+0x00839da0u);
  }
  L004766dd: { // 0x004766dd: 668b1495a09d8300 MOV DX,word ptr [EDX*0x4 + 0x839da0]
    s.dx = with_ax(s.dx, m.r16(((s.dx * 0x00000004u)+0x00839da0u)));
  }
  L004766e5: { // 0x004766e5: 668b4002 MOV AX,word ptr [EAX + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.ax+0x00000002u)));
  }
  L004766e9: { // 0x004766e9: 6603442402 ADD AX,word ptr [ESP + 0x2]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((f.sp+0x00000002u)),16,flags));
  }
  L004766ee: { // 0x004766ee: 6603d1 ADD DX,CX
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),(s.cx & 0xffffu),16,flags));
  }
  L004766f1: { // 0x004766f1: 6689542408 MOV word ptr [ESP + 0x8],DX
    m.w16((f.sp+0x00000008u), (s.dx & 0xffffu));
  }
  L004766f6: { // 0x004766f6: 8d542408 LEA EDX,[ESP + 0x8]
    s.dx = (f.sp+0x00000008u);
  }
  L004766fa: { // 0x004766fa: 668944240a MOV word ptr [ESP + 0xa],AX
    m.w16((f.sp+0x0000000au), (s.ax & 0xffffu));
  }
  L004766ff: { // 0x004766ff: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  L00476703: { // 0x00476703: 894c2408 MOV dword ptr [ESP + 0x8],ECX
    m.w32((f.sp+0x00000008u), s.cx);
  }
  L00476707: { // 0x00476707: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00476708: { // 0x00476708: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0047670d: { // 0x0047670d: e8eeed0c00 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4679442u); flags=s.arithmetic_flags;
  }
  L00476712: { // 0x00476712: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00476713: { // 0x00476713: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0007b560(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0047b560: { // 0x47b560: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  L0047b563: { // 0x47b563: 8b0db0a8a300 MOV ECX,dword ptr [0x00a3a8b0]
    s.cx = m.r32((0x00a3a8b0u));
  }
  L0047b569: { // 0x47b569: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0047b56b: { // 0x47b56b: 7c0a JL 0x0047b577
    if(integer::condition("JL",flags)) goto L0047b577;
  }
  L0047b56d: { // 0x47b56d: 83c110 ADD ECX,0x10
    s.cx = integer::add(s.cx,0x00000010u,32,flags);
  }
  L0047b570: { // 0x47b570: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0047b572: { // 0x47b572: 7d03 JGE 0x0047b577
    if(integer::condition("JGE",flags)) goto L0047b577;
  }
  L0047b574: { // 0x47b574: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047b576: { // 0x47b576: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b577: { // 0x47b577: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0047b579: { // 0x47b579: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0007b580(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0047b580: { // 0x47b580: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  L0047b583: { // 0x47b583: 8b0da047a500 MOV ECX,dword ptr [0x00a547a0]
    s.cx = m.r32((0x00a547a0u));
  }
  L0047b589: { // 0x47b589: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0047b58b: { // 0x47b58b: 7c0a JL 0x0047b597
    if(integer::condition("JL",flags)) goto L0047b597;
  }
  L0047b58d: { // 0x47b58d: 83c110 ADD ECX,0x10
    s.cx = integer::add(s.cx,0x00000010u,32,flags);
  }
  L0047b590: { // 0x47b590: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0047b592: { // 0x47b592: 7d03 JGE 0x0047b597
    if(integer::condition("JGE",flags)) goto L0047b597;
  }
  L0047b594: { // 0x47b594: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047b596: { // 0x47b596: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b597: { // 0x47b597: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0047b599: { // 0x47b599: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00298150(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00698150: { // 0x698150: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L00698154: { // 0x698154: 8b157060aa00 MOV EDX,dword ptr [0x00aa6070]
    s.dx = m.r32((0x00aa6070u));
  }
  L0069815a: { // 0x69815a: 83ec18 SUB ESP,0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
  L0069815d: { // 0x69815d: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0069815e: { // 0x69815e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0069815f: { // 0x69815f: 8b38 MOV EDI,dword ptr [EAX]
    s.di = m.r32((s.ax));
  }
  L00698161: { // 0x698161: 3bfa CMP EDI,EDX
    (void)integer::sub(s.di,s.dx,32,flags);
  }
  L00698163: { // 0x698163: 0f8d9e000000 JGE 0x00698207
    if(integer::condition("JGE",flags)) goto L00698207;
  }
  L00698169: { // 0x698169: 8b7004 MOV ESI,dword ptr [EAX + 0x4]
    s.si = m.r32((s.ax+0x00000004u));
  }
  L0069816c: { // 0x69816c: a17460aa00 MOV EAX,[0x00aa6074]
    s.ax = m.r32((0x00aa6074u));
  }
  L00698171: { // 0x698171: 8b156c60aa00 MOV EDX,dword ptr [0x00aa606c]
    s.dx = m.r32((0x00aa606cu));
  }
  L00698177: { // 0x698177: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00698179: { // 0x698179: 3bf2 CMP ESI,EDX
    (void)integer::sub(s.si,s.dx,32,flags);
  }
  L0069817b: { // 0x69817b: 0f8d86000000 JGE 0x00698207
    if(integer::condition("JGE",flags)) goto L00698207;
  }
  L00698181: { // 0x698181: 8b81b0000000 MOV EAX,dword ptr [ECX + 0xb0]
    s.ax = m.r32((s.cx+0x000000b0u));
  }
  L00698187: { // 0x698187: 8b91b4000000 MOV EDX,dword ptr [ECX + 0xb4]
    s.dx = m.r32((s.cx+0x000000b4u));
  }
  L0069818d: { // 0x69818d: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L0069818f: { // 0x69818f: 03f2 ADD ESI,EDX
    s.si = integer::add(s.si,s.dx,32,flags);
  }
  L00698191: { // 0x698191: 897c2408 MOV dword ptr [ESP + 0x8],EDI
    m.w32((f.sp+0x00000008u), s.di);
  }
  L00698195: { // 0x698195: 8974240c MOV dword ptr [ESP + 0xc],ESI
    m.w32((f.sp+0x0000000cu), s.si);
  }
  L00698199: { // 0x698199: db442408 FILD dword ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.load_integer32(m.r32(address));
  }
  L0069819d: { // 0x69819d: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L006981a1: { // 0x6981a1: 8d91e40d0000 LEA EDX,[ECX + 0xde4]
    s.dx = (s.cx+0x00000de4u);
  }
  L006981a7: { // 0x6981a7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006981a8: { // 0x6981a8: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  L006981ac: { // 0x6981ac: d95c2418 FSTP float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L006981b0: { // 0x6981b0: db442410 FILD dword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load_integer32(m.r32(address));
  }
  L006981b4: { // 0x6981b4: c744242000000000 MOV dword ptr [ESP + 0x20],0x0
    m.w32((f.sp+0x00000020u), 0x00000000u);
  }
  L006981bc: { // 0x6981bc: d95c241c FSTP float ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L006981c0: { // 0x6981c0: e8bb5fefff CALL 0x0058e180
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058e180u,6914501u); flags=s.arithmetic_flags;
  }
  L006981c5: { // 0x6981c5: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L006981c7: { // 0x6981c7: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L006981cb: { // 0x6981cb: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L006981ce: { // 0x6981ce: d9442414 FLD float ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load32(m.r32(address));
  }
  L006981d2: { // 0x6981d2: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L006981d6: { // 0x6981d6: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L006981d9: { // 0x6981d9: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L006981dd: { // 0x6981dd: e86e280d00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6914530u); flags=s.arithmetic_flags;
  }
  L006981e2: { // 0x6981e2: d9442418 FLD float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load32(m.r32(address));
  }
  L006981e6: { // 0x6981e6: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L006981e8: { // 0x6981e8: e863280d00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6914541u); flags=s.arithmetic_flags;
  }
  L006981ed: { // 0x6981ed: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L006981f1: { // 0x6981f1: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L006981f3: { // 0x6981f3: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L006981f5: { // 0x6981f5: 8937 MOV dword ptr [EDI],ESI
    m.w32((s.di), s.si);
  }
  L006981f7: { // 0x6981f7: 894704 MOV dword ptr [EDI + 0x4],EAX
    m.w32((s.di+0x00000004u), s.ax);
  }
  L006981fa: { // 0x6981fa: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L006981fc: { // 0x6981fc: 894f08 MOV dword ptr [EDI + 0x8],ECX
    m.w32((s.di+0x00000008u), s.cx);
  }
  L006981ff: { // 0x6981ff: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00698200: { // 0x698200: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00698201: { // 0x698201: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L00698204: { // 0x698204: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L00698207: { // 0x698207: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L0069820b: { // 0x69820b: 8b154860aa00 MOV EDX,dword ptr [0x00aa6048]
    s.dx = m.r32((0x00aa6048u));
  }
  L00698211: { // 0x698211: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00698213: { // 0x698213: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00698214: { // 0x698214: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00698215: { // 0x698215: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  L00698217: { // 0x698217: 8b154c60aa00 MOV EDX,dword ptr [0x00aa604c]
    s.dx = m.r32((0x00aa604cu));
  }
  L0069821d: { // 0x69821d: 895104 MOV dword ptr [ECX + 0x4],EDX
    m.w32((s.cx+0x00000004u), s.dx);
  }
  L00698220: { // 0x698220: 8b155060aa00 MOV EDX,dword ptr [0x00aa6050]
    s.dx = m.r32((0x00aa6050u));
  }
  L00698226: { // 0x698226: 895108 MOV dword ptr [ECX + 0x8],EDX
    m.w32((s.cx+0x00000008u), s.dx);
  }
  L00698229: { // 0x698229: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L0069822c: { // 0x69822c: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00147f90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00547f90: { // 0x547f90: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00547f91: { // 0x547f91: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00547f92: { // 0x547f92: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  L00547f96: { // 0x547f96: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L00547f98: { // 0x547f98: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00547f99: { // 0x547f99: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00547f9f: { // 0x547f9f: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00547fa1: { // 0x547fa1: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00547fa3: { // 0x547fa3: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  L00547fa6: { // 0x547fa6: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00547fa7: { // 0x547fa7: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00547fad: { // 0x547fad: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00547faf: { // 0x547faf: 8b91f0000000 MOV EDX,dword ptr [ECX + 0xf0]
    s.dx = m.r32((s.cx+0x000000f0u));
  }
  L00547fb5: { // 0x547fb5: c1fe08 SAR ESI,0x8
    s.si = integer::shift(s.si,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00547fb8: { // 0x547fb8: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00547fbb: { // 0x547fbb: 0fbff6 MOVSX ESI,SI
    s.si = std::uint32_t(integer::sign_extend((s.si & 0xffffu),16));
  }
  L00547fbe: { // 0x547fbe: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00547fc1: { // 0x547fc1: 8d3c30 LEA EDI,[EAX + ESI*0x1]
    s.di = (s.ax+(s.si * 0x00000001u));
  }
  L00547fc4: { // 0x547fc4: 3bfa CMP EDI,EDX
    (void)integer::sub(s.di,s.dx,32,flags);
  }
  L00547fc6: { // 0x547fc6: 7e24 JLE 0x00547fec
    if(integer::condition("JLE",flags)) goto L00547fec;
  }
  L00547fc8: { // 0x547fc8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00547fc9: { // 0x547fc9: 8bde MOV EBX,ESI
    s.bx = s.si;
  }
  L00547fcb: { // 0x547fcb: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00547fcd: { // 0x547fcd: 3bda CMP EBX,EDX
    (void)integer::sub(s.bx,s.dx,32,flags);
  }
  L00547fcf: { // 0x547fcf: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00547fd0: { // 0x547fd0: 7d1a JGE 0x00547fec
    if(integer::condition("JGE",flags)) goto L00547fec;
  }
  L00547fd2: { // 0x547fd2: 2bc6 SUB EAX,ESI
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L00547fd4: { // 0x547fd4: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00547fd6: { // 0x547fd6: 7d14 JGE 0x00547fec
    if(integer::condition("JGE",flags)) goto L00547fec;
  }
  L00547fd8: { // 0x547fd8: 8b81f4000000 MOV EAX,dword ptr [ECX + 0xf4]
    s.ax = m.r32((s.cx+0x000000f4u));
  }
  L00547fde: { // 0x547fde: 8d0c42 LEA ECX,[EDX + EAX*0x2]
    s.cx = (s.dx+(s.ax * 0x00000002u));
  }
  L00547fe1: { // 0x547fe1: 3bf9 CMP EDI,ECX
    (void)integer::sub(s.di,s.cx,32,flags);
  }
  L00547fe3: { // 0x547fe3: 7f07 JG 0x00547fec
    if(integer::condition("JG",flags)) goto L00547fec;
  }
  L00547fe5: { // 0x547fe5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00547fe6: { // 0x547fe6: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00547fe8: { // 0x547fe8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00547fe9: { // 0x547fe9: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00547fec: { // 0x547fec: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00547fed: { // 0x547fed: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00547fef: { // 0x547fef: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00547ff0: { // 0x547ff0: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00157070(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00557070: { // 0x00557070: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00557073: { // 0x00557073: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L00557077: { // 0x00557077: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00557078: { // 0x00557078: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0055707a: { // 0x0055707a: 8b5104 MOV EDX,dword ptr [ECX + 0x4]
    s.dx = m.r32((s.cx+0x00000004u));
  }
  L0055707d: { // 0x0055707d: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  L00557081: { // 0x00557081: 89542408 MOV dword ptr [ESP + 0x8],EDX
    m.w32((f.sp+0x00000008u), s.dx);
  }
  L00557085: { // 0x00557085: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00557086: { // 0x00557086: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0055708c: { // 0x0055708c: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0055708e: { // 0x0055708e: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00557090: { // 0x00557090: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L00557093: { // 0x00557093: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00557094: { // 0x00557094: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0055709a: { // 0x0055709a: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0055709c: { // 0x0055709c: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0055709f: { // 0x0055709f: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L005570a1: { // 0x005570a1: c1fe08 SAR ESI,0x8
    s.si = integer::shift(s.si,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L005570a4: { // 0x005570a4: c1e109 SHL ECX,0x9
    s.cx = integer::shift(s.cx,0x00000009u,32,flags,integer::Shift::left);
  }
  L005570a7: { // 0x005570a7: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L005570a9: { // 0x005570a9: 7815 JS 0x005570c0
    if(integer::condition("JS",flags)) goto L005570c0;
  }
  L005570ab: { // 0x005570ab: 3b0d5ca98100 CMP ECX,dword ptr [0x0081a95c]
    (void)integer::sub(s.cx,m.r32((0x0081a95cu)),32,flags);
  }
  L005570b1: { // 0x005570b1: 7d0d JGE 0x005570c0
    if(integer::condition("JGE",flags)) goto L005570c0;
  }
  L005570b3: { // 0x005570b3: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L005570b9: { // 0x005570b9: 8b0c8a MOV ECX,dword ptr [EDX + ECX*0x4]
    s.cx = m.r32((s.dx+(s.cx * 0x00000004u)));
  }
  L005570bc: { // 0x005570bc: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005570be: { // 0x005570be: 7518 JNZ 0x005570d8
    if(integer::condition("JNZ",flags)) goto L005570d8;
  }
  L005570c0: { // 0x005570c0: 6689742410 MOV word ptr [ESP + 0x10],SI
    m.w16((f.sp+0x00000010u), (s.si & 0xffffu));
  }
  L005570c5: { // 0x005570c5: 6689442412 MOV word ptr [ESP + 0x12],AX
    m.w16((f.sp+0x00000012u), (s.ax & 0xffffu));
  }
  L005570ca: { // 0x005570ca: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L005570ce: { // 0x005570ce: b91076a500 MOV ECX,0xa57610
    s.cx = 0x00a57610u;
  }
  L005570d3: { // 0x005570d3: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L005570d8: { // 0x005570d8: 8d542404 LEA EDX,[ESP + 0x4]
    s.dx = (f.sp+0x00000004u);
  }
  L005570dc: { // 0x005570dc: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005570dd: { // 0x005570dd: e8de91f1ff CALL 0x004702c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004702c0u,5599458u); flags=s.arithmetic_flags;
  }
  L005570e2: { // 0x005570e2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005570e3: { // 0x005570e3: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L005570e6: { // 0x005570e6: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000702c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004702c0: { // 0x4702c0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004702c1: { // 0x4702c1: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L004702c3: { // 0x4702c3: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L004702c6: { // 0x4702c6: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L004702c9: { // 0x4702c9: a0708f8300 MOV AL,[0x00838f70]
    s.ax = with_al(s.ax, m.r8((0x00838f70u)));
  }
  L004702ce: { // 0x4702ce: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004702cf: { // 0x4702cf: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L004702d1: { // 0x4702d1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004702d3: { // 0x4702d3: 7513 JNZ 0x004702e8
    if(integer::condition("JNZ",flags)) goto L004702e8;
  }
  L004702d5: { // 0x4702d5: db05808f8300 FILD dword ptr [0x00838f80]
    const auto address=(0x00838f80u);
    s.fp.load_integer32(m.r32(address));
  }
  L004702db: { // 0x4702db: 0c01 OR AL,0x1
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000001u),8,flags));
  }
  L004702dd: { // 0x4702dd: a2708f8300 MOV [0x00838f70],AL
    m.w8((0x00838f70u), (s.ax & 0xffu));
  }
  L004702e2: { // 0x4702e2: dd1df08e8300 FSTP double ptr [0x00838ef0]
    const auto address=(0x00838ef0u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L004702e8: { // 0x4702e8: a802 TEST AL,0x2
    (void)integer::logical(((s.ax & 0xffu))&(0x00000002u),8,flags);
  }
  L004702ea: { // 0x4702ea: 7519 JNZ 0x00470305
    if(integer::condition("JNZ",flags)) goto L00470305;
  }
  L004702ec: { // 0x4702ec: dd05f08e8300 FLD double ptr [0x00838ef0]
    const auto address=(0x00838ef0u);
    s.fp.load64(read64(m,address));
  }
  L004702f2: { // 0x4702f2: dc0d30577800 FMUL double ptr [0x00785730]
    const auto address=(0x00785730u);
    s.fp.multiply64(read64(m,address));
  }
  L004702f8: { // 0x4702f8: 0c02 OR AL,0x2
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000002u),8,flags));
  }
  L004702fa: { // 0x4702fa: a2708f8300 MOV [0x00838f70],AL
    m.w8((0x00838f70u), (s.ax & 0xffu));
  }
  L004702ff: { // 0x4702ff: dd1d108f8300 FSTP double ptr [0x00838f10]
    const auto address=(0x00838f10u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00470305: { // 0x470305: a804 TEST AL,0x4
    (void)integer::logical(((s.ax & 0xffu))&(0x00000004u),8,flags);
  }
  L00470307: { // 0x470307: 0f85a7060000 JNZ 0x004709b4
    if(integer::condition("JNZ",flags)) goto L004709b4;
  }
  L0047030d: { // 0x47030d: 8b0df48e8300 MOV ECX,dword ptr [0x00838ef4]
    s.cx = m.r32((0x00838ef4u));
  }
  L00470313: { // 0x470313: 0c04 OR AL,0x4
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000004u),8,flags));
  }
  L00470315: { // 0x470315: a2708f8300 MOV [0x00838f70],AL
    m.w8((0x00838f70u), (s.ax & 0xffu));
  }
  L0047031a: { // 0x47031a: a1f08e8300 MOV EAX,[0x00838ef0]
    s.ax = m.r32((0x00838ef0u));
  }
  L0047031f: { // 0x47031f: a398d77b00 MOV [0x007bd798],EAX
    m.w32((0x007bd798u), s.ax);
  }
  L00470324: { // 0x470324: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00470326: { // 0x470326: 890d9cd77b00 MOV dword ptr [0x007bd79c],ECX
    m.w32((0x007bd79cu), s.cx);
  }
  L0047032c: { // 0x47032c: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0047032e: { // 0x47032e: 8915c0d77b00 MOV dword ptr [0x007bd7c0],EDX
    m.w32((0x007bd7c0u), s.dx);
  }
  L00470334: { // 0x470334: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L00470336: { // 0x470336: a3c4d77b00 MOV [0x007bd7c4],EAX
    m.w32((0x007bd7c4u), s.ax);
  }
  L0047033b: { // 0x47033b: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0047033d: { // 0x47033d: 890de0d77b00 MOV dword ptr [0x007bd7e0],ECX
    m.w32((0x007bd7e0u), s.cx);
  }
  L00470343: { // 0x470343: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00470345: { // 0x470345: 8915e4d77b00 MOV dword ptr [0x007bd7e4],EDX
    m.w32((0x007bd7e4u), s.dx);
  }
  L0047034b: { // 0x47034b: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L0047034d: { // 0x47034d: dd05f08e8300 FLD double ptr [0x00838ef0]
    const auto address=(0x00838ef0u);
    s.fp.load64(read64(m,address));
  }
  L00470353: { // 0x470353: a3e8d77b00 MOV [0x007bd7e8],EAX
    m.w32((0x007bd7e8u), s.ax);
  }
  L00470358: { // 0x470358: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0047035a: { // 0x47035a: 890decd77b00 MOV dword ptr [0x007bd7ec],ECX
    m.w32((0x007bd7ecu), s.cx);
  }
  L00470360: { // 0x470360: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00470362: { // 0x470362: 891508d87b00 MOV dword ptr [0x007bd808],EDX
    m.w32((0x007bd808u), s.dx);
  }
  L00470368: { // 0x470368: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L0047036a: { // 0x47036a: a30cd87b00 MOV [0x007bd80c],EAX
    m.w32((0x007bd80cu), s.ax);
  }
  L0047036f: { // 0x47036f: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00470371: { // 0x470371: 890d10d87b00 MOV dword ptr [0x007bd810],ECX
    m.w32((0x007bd810u), s.cx);
  }
  L00470377: { // 0x470377: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00470379: { // 0x470379: 891514d87b00 MOV dword ptr [0x007bd814],EDX
    m.w32((0x007bd814u), s.dx);
  }
  L0047037f: { // 0x47037f: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L00470381: { // 0x470381: a338d87b00 MOV [0x007bd838],EAX
    m.w32((0x007bd838u), s.ax);
  }
  L00470386: { // 0x470386: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00470388: { // 0x470388: 890d3cd87b00 MOV dword ptr [0x007bd83c],ECX
    m.w32((0x007bd83cu), s.cx);
  }
  L0047038e: { // 0x47038e: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00470390: { // 0x470390: 891560d87b00 MOV dword ptr [0x007bd860],EDX
    m.w32((0x007bd860u), s.dx);
  }
  L00470396: { // 0x470396: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L00470398: { // 0x470398: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L0047039a: { // 0x47039a: dd1d30d87b00 FSTP double ptr [0x007bd830]
    const auto address=(0x007bd830u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L004703a0: { // 0x4703a0: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L004703a2: { // 0x4703a2: c705a0d77b0000000000 MOV dword ptr [0x007bd7a0],0x0
    m.w32((0x007bd7a0u), 0x00000000u);
  }
  L004703ac: { // 0x4703ac: c705a4d77b0000000000 MOV dword ptr [0x007bd7a4],0x0
    m.w32((0x007bd7a4u), 0x00000000u);
  }
  L004703b6: { // 0x4703b6: c705a8d77b0000000000 MOV dword ptr [0x007bd7a8],0x0
    m.w32((0x007bd7a8u), 0x00000000u);
  }
  L004703c0: { // 0x4703c0: c705acd77b0000000000 MOV dword ptr [0x007bd7ac],0x0
    m.w32((0x007bd7acu), 0x00000000u);
  }
  L004703ca: { // 0x4703ca: c705b0d77b0000000000 MOV dword ptr [0x007bd7b0],0x0
    m.w32((0x007bd7b0u), 0x00000000u);
  }
  L004703d4: { // 0x4703d4: c705b4d77b000000f03f MOV dword ptr [0x007bd7b4],0x3ff00000
    m.w32((0x007bd7b4u), 0x3ff00000u);
  }
  L004703de: { // 0x4703de: c705b8d77b0000000000 MOV dword ptr [0x007bd7b8],0x0
    m.w32((0x007bd7b8u), 0x00000000u);
  }
  L004703e8: { // 0x4703e8: c705bcd77b0000000000 MOV dword ptr [0x007bd7bc],0x0
    m.w32((0x007bd7bcu), 0x00000000u);
  }
  L004703f2: { // 0x4703f2: c705c8d77b0000000000 MOV dword ptr [0x007bd7c8],0x0
    m.w32((0x007bd7c8u), 0x00000000u);
  }
  L004703fc: { // 0x4703fc: c705ccd77b0000000000 MOV dword ptr [0x007bd7cc],0x0
    m.w32((0x007bd7ccu), 0x00000000u);
  }
  L00470406: { // 0x470406: c705d0d77b0000000000 MOV dword ptr [0x007bd7d0],0x0
    m.w32((0x007bd7d0u), 0x00000000u);
  }
  L00470410: { // 0x470410: c705d4d77b000000f0bf MOV dword ptr [0x007bd7d4],0xbff00000
    m.w32((0x007bd7d4u), 0xbff00000u);
  }
  L0047041a: { // 0x47041a: c705d8d77b0000000000 MOV dword ptr [0x007bd7d8],0x0
    m.w32((0x007bd7d8u), 0x00000000u);
  }
  L00470424: { // 0x470424: c705dcd77b0000000000 MOV dword ptr [0x007bd7dc],0x0
    m.w32((0x007bd7dcu), 0x00000000u);
  }
  L0047042e: { // 0x47042e: c705f0d77b0000000000 MOV dword ptr [0x007bd7f0],0x0
    m.w32((0x007bd7f0u), 0x00000000u);
  }
  L00470438: { // 0x470438: c705f4d77b0000000000 MOV dword ptr [0x007bd7f4],0x0
    m.w32((0x007bd7f4u), 0x00000000u);
  }
  L00470442: { // 0x470442: c705f8d77b0000000000 MOV dword ptr [0x007bd7f8],0x0
    m.w32((0x007bd7f8u), 0x00000000u);
  }
  L0047044c: { // 0x47044c: c705fcd77b0000000000 MOV dword ptr [0x007bd7fc],0x0
    m.w32((0x007bd7fcu), 0x00000000u);
  }
  L00470456: { // 0x470456: c70500d87b0000000000 MOV dword ptr [0x007bd800],0x0
    m.w32((0x007bd800u), 0x00000000u);
  }
  L00470460: { // 0x470460: c70504d87b000000f0bf MOV dword ptr [0x007bd804],0xbff00000
    m.w32((0x007bd804u), 0xbff00000u);
  }
  L0047046a: { // 0x47046a: c70518d87b0000000000 MOV dword ptr [0x007bd818],0x0
    m.w32((0x007bd818u), 0x00000000u);
  }
  L00470474: { // 0x470474: c7051cd87b0000000000 MOV dword ptr [0x007bd81c],0x0
    m.w32((0x007bd81cu), 0x00000000u);
  }
  L0047047e: { // 0x47047e: c70520d87b0000000000 MOV dword ptr [0x007bd820],0x0
    m.w32((0x007bd820u), 0x00000000u);
  }
  L00470488: { // 0x470488: c70524d87b000000f03f MOV dword ptr [0x007bd824],0x3ff00000
    m.w32((0x007bd824u), 0x3ff00000u);
  }
  L00470492: { // 0x470492: c70528d87b0000000000 MOV dword ptr [0x007bd828],0x0
    m.w32((0x007bd828u), 0x00000000u);
  }
  L0047049c: { // 0x47049c: c7052cd87b000000f03f MOV dword ptr [0x007bd82c],0x3ff00000
    m.w32((0x007bd82cu), 0x3ff00000u);
  }
  L004704a6: { // 0x4704a6: c70540d87b0000000000 MOV dword ptr [0x007bd840],0x0
    m.w32((0x007bd840u), 0x00000000u);
  }
  L004704b0: { // 0x4704b0: c70544d87b0000000000 MOV dword ptr [0x007bd844],0x0
    m.w32((0x007bd844u), 0x00000000u);
  }
  L004704ba: { // 0x4704ba: c70548d87b0000000000 MOV dword ptr [0x007bd848],0x0
    m.w32((0x007bd848u), 0x00000000u);
  }
  L004704c4: { // 0x4704c4: c7054cd87b000000f0bf MOV dword ptr [0x007bd84c],0xbff00000
    m.w32((0x007bd84cu), 0xbff00000u);
  }
  L004704ce: { // 0x4704ce: c70550d87b0000000000 MOV dword ptr [0x007bd850],0x0
    m.w32((0x007bd850u), 0x00000000u);
  }
  L004704d8: { // 0x4704d8: c70554d87b000000f03f MOV dword ptr [0x007bd854],0x3ff00000
    m.w32((0x007bd854u), 0x3ff00000u);
  }
  L004704e2: { // 0x4704e2: c70558d87b0000000000 MOV dword ptr [0x007bd858],0x0
    m.w32((0x007bd858u), 0x00000000u);
  }
  L004704ec: { // 0x4704ec: c7055cd87b0000000000 MOV dword ptr [0x007bd85c],0x0
    m.w32((0x007bd85cu), 0x00000000u);
  }
  L004704f6: { // 0x4704f6: a364d87b00 MOV [0x007bd864],EAX
    m.w32((0x007bd864u), s.ax);
  }
  L004704fb: { // 0x4704fb: c70568d87b0000000000 MOV dword ptr [0x007bd868],0x0
    m.w32((0x007bd868u), 0x00000000u);
  }
  L00470505: { // 0x470505: c7056cd87b0000000000 MOV dword ptr [0x007bd86c],0x0
    m.w32((0x007bd86cu), 0x00000000u);
  }
  L0047050f: { // 0x47050f: c70570d87b0000000000 MOV dword ptr [0x007bd870],0x0
    m.w32((0x007bd870u), 0x00000000u);
  }
  L00470519: { // 0x470519: c70574d87b000000f0bf MOV dword ptr [0x007bd874],0xbff00000
    m.w32((0x007bd874u), 0xbff00000u);
  }
  L00470523: { // 0x470523: c70578d87b0000000000 MOV dword ptr [0x007bd878],0x0
    m.w32((0x007bd878u), 0x00000000u);
  }
  L0047052d: { // 0x47052d: c7057cd87b000000f0bf MOV dword ptr [0x007bd87c],0xbff00000
    m.w32((0x007bd87cu), 0xbff00000u);
  }
  L00470537: { // 0x470537: 890d80d87b00 MOV dword ptr [0x007bd880],ECX
    m.w32((0x007bd880u), s.cx);
  }
  L0047053d: { // 0x47053d: 891584d87b00 MOV dword ptr [0x007bd884],EDX
    m.w32((0x007bd884u), s.dx);
  }
  L00470543: { // 0x470543: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00470545: { // 0x470545: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L00470547: { // 0x470547: a388d87b00 MOV [0x007bd888],EAX
    m.w32((0x007bd888u), s.ax);
  }
  L0047054c: { // 0x47054c: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0047054e: { // 0x47054e: dd05f08e8300 FLD double ptr [0x00838ef0]
    const auto address=(0x00838ef0u);
    s.fp.load64(read64(m,address));
  }
  L00470554: { // 0x470554: 890d8cd87b00 MOV dword ptr [0x007bd88c],ECX
    m.w32((0x007bd88cu), s.cx);
  }
  L0047055a: { // 0x47055a: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0047055c: { // 0x47055c: 8915b0d87b00 MOV dword ptr [0x007bd8b0],EDX
    m.w32((0x007bd8b0u), s.dx);
  }
  L00470562: { // 0x470562: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L00470564: { // 0x470564: a3b4d87b00 MOV [0x007bd8b4],EAX
    m.w32((0x007bd8b4u), s.ax);
  }
  L00470569: { // 0x470569: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0047056b: { // 0x47056b: 890dd8d87b00 MOV dword ptr [0x007bd8d8],ECX
    m.w32((0x007bd8d8u), s.cx);
  }
  L00470571: { // 0x470571: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00470573: { // 0x470573: 8915dcd87b00 MOV dword ptr [0x007bd8dc],EDX
    m.w32((0x007bd8dcu), s.dx);
  }
  L00470579: { // 0x470579: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L0047057b: { // 0x47057b: a3f8d87b00 MOV [0x007bd8f8],EAX
    m.w32((0x007bd8f8u), s.ax);
  }
  L00470580: { // 0x470580: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00470582: { // 0x470582: 890dfcd87b00 MOV dword ptr [0x007bd8fc],ECX
    m.w32((0x007bd8fcu), s.cx);
  }
  L00470588: { // 0x470588: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0047058a: { // 0x47058a: 891500d97b00 MOV dword ptr [0x007bd900],EDX
    m.w32((0x007bd900u), s.dx);
  }
  L00470590: { // 0x470590: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L00470592: { // 0x470592: a304d97b00 MOV [0x007bd904],EAX
    m.w32((0x007bd904u), s.ax);
  }
  L00470597: { // 0x470597: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00470599: { // 0x470599: dcc0 FADD ST0,ST0
    numeric_b88::detail::reg<0xdcc0>(s.fp);
  }
  L0047059b: { // 0x47059b: 890d28d97b00 MOV dword ptr [0x007bd928],ECX
    m.w32((0x007bd928u), s.cx);
  }
  L004705a1: { // 0x4705a1: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004705a3: { // 0x4705a3: 89152cd97b00 MOV dword ptr [0x007bd92c],EDX
    m.w32((0x007bd92cu), s.dx);
  }
  L004705a9: { // 0x4705a9: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L004705ab: { // 0x4705ab: a348d97b00 MOV [0x007bd948],EAX
    m.w32((0x007bd948u), s.ax);
  }
  L004705b0: { // 0x4705b0: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L004705b2: { // 0x4705b2: dd1520d97b00 FST double ptr [0x007bd920]
    const auto address=(0x007bd920u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L004705b8: { // 0x4705b8: dd1578d97b00 FST double ptr [0x007bd978]
    const auto address=(0x007bd978u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L004705be: { // 0x4705be: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004705c0: { // 0x4705c0: c70590d87b0000000000 MOV dword ptr [0x007bd890],0x0
    m.w32((0x007bd890u), 0x00000000u);
  }
  L004705ca: { // 0x4705ca: c70594d87b0000000000 MOV dword ptr [0x007bd894],0x0
    m.w32((0x007bd894u), 0x00000000u);
  }
  L004705d4: { // 0x4705d4: c70598d87b0000000000 MOV dword ptr [0x007bd898],0x0
    m.w32((0x007bd898u), 0x00000000u);
  }
  L004705de: { // 0x4705de: c7059cd87b000000f03f MOV dword ptr [0x007bd89c],0x3ff00000
    m.w32((0x007bd89cu), 0x3ff00000u);
  }
  L004705e8: { // 0x4705e8: c705a0d87b0000000000 MOV dword ptr [0x007bd8a0],0x0
    m.w32((0x007bd8a0u), 0x00000000u);
  }
  L004705f2: { // 0x4705f2: c705a4d87b000000f0bf MOV dword ptr [0x007bd8a4],0xbff00000
    m.w32((0x007bd8a4u), 0xbff00000u);
  }
  L004705fc: { // 0x4705fc: c705a8d87b0000000000 MOV dword ptr [0x007bd8a8],0x0
    m.w32((0x007bd8a8u), 0x00000000u);
  }
  L00470606: { // 0x470606: c705acd87b0000000000 MOV dword ptr [0x007bd8ac],0x0
    m.w32((0x007bd8acu), 0x00000000u);
  }
  L00470610: { // 0x470610: c705b8d87b0000000000 MOV dword ptr [0x007bd8b8],0x0
    m.w32((0x007bd8b8u), 0x00000000u);
  }
  L0047061a: { // 0x47061a: c705bcd87b0000000000 MOV dword ptr [0x007bd8bc],0x0
    m.w32((0x007bd8bcu), 0x00000000u);
  }
  L00470624: { // 0x470624: c705c0d87b0000000000 MOV dword ptr [0x007bd8c0],0x0
    m.w32((0x007bd8c0u), 0x00000000u);
  }
  L0047062e: { // 0x47062e: c705c4d87b000000f03f MOV dword ptr [0x007bd8c4],0x3ff00000
    m.w32((0x007bd8c4u), 0x3ff00000u);
  }
  L00470638: { // 0x470638: c705c8d87b0000000000 MOV dword ptr [0x007bd8c8],0x0
    m.w32((0x007bd8c8u), 0x00000000u);
  }
  L00470642: { // 0x470642: c705ccd87b000000f03f MOV dword ptr [0x007bd8cc],0x3ff00000
    m.w32((0x007bd8ccu), 0x3ff00000u);
  }
  L0047064c: { // 0x47064c: c705d0d87b0000000000 MOV dword ptr [0x007bd8d0],0x0
    m.w32((0x007bd8d0u), 0x00000000u);
  }
  L00470656: { // 0x470656: c705d4d87b0000000000 MOV dword ptr [0x007bd8d4],0x0
    m.w32((0x007bd8d4u), 0x00000000u);
  }
  L00470660: { // 0x470660: c705e0d87b0000000000 MOV dword ptr [0x007bd8e0],0x0
    m.w32((0x007bd8e0u), 0x00000000u);
  }
  L0047066a: { // 0x47066a: c705e4d87b0000000000 MOV dword ptr [0x007bd8e4],0x0
    m.w32((0x007bd8e4u), 0x00000000u);
  }
  L00470674: { // 0x470674: c705e8d87b0000000000 MOV dword ptr [0x007bd8e8],0x0
    m.w32((0x007bd8e8u), 0x00000000u);
  }
  L0047067e: { // 0x47067e: c705ecd87b000000f0bf MOV dword ptr [0x007bd8ec],0xbff00000
    m.w32((0x007bd8ecu), 0xbff00000u);
  }
  L00470688: { // 0x470688: c705f0d87b0000000000 MOV dword ptr [0x007bd8f0],0x0
    m.w32((0x007bd8f0u), 0x00000000u);
  }
  L00470692: { // 0x470692: c705f4d87b000000f03f MOV dword ptr [0x007bd8f4],0x3ff00000
    m.w32((0x007bd8f4u), 0x3ff00000u);
  }
  L0047069c: { // 0x47069c: c70508d97b0000000000 MOV dword ptr [0x007bd908],0x0
    m.w32((0x007bd908u), 0x00000000u);
  }
  L004706a6: { // 0x4706a6: c7050cd97b0000000000 MOV dword ptr [0x007bd90c],0x0
    m.w32((0x007bd90cu), 0x00000000u);
  }
  L004706b0: { // 0x4706b0: c70510d97b0000000000 MOV dword ptr [0x007bd910],0x0
    m.w32((0x007bd910u), 0x00000000u);
  }
  L004706ba: { // 0x4706ba: c70514d97b000000f0bf MOV dword ptr [0x007bd914],0xbff00000
    m.w32((0x007bd914u), 0xbff00000u);
  }
  L004706c4: { // 0x4706c4: c70518d97b0000000000 MOV dword ptr [0x007bd918],0x0
    m.w32((0x007bd918u), 0x00000000u);
  }
  L004706ce: { // 0x4706ce: c7051cd97b000000f0bf MOV dword ptr [0x007bd91c],0xbff00000
    m.w32((0x007bd91cu), 0xbff00000u);
  }
  L004706d8: { // 0x4706d8: c70530d97b0000000000 MOV dword ptr [0x007bd930],0x0
    m.w32((0x007bd930u), 0x00000000u);
  }
  L004706e2: { // 0x4706e2: c70534d97b0000000000 MOV dword ptr [0x007bd934],0x0
    m.w32((0x007bd934u), 0x00000000u);
  }
  L004706ec: { // 0x4706ec: c70538d97b0000000000 MOV dword ptr [0x007bd938],0x0
    m.w32((0x007bd938u), 0x00000000u);
  }
  L004706f6: { // 0x4706f6: c7053cd97b000000f03f MOV dword ptr [0x007bd93c],0x3ff00000
    m.w32((0x007bd93cu), 0x3ff00000u);
  }
  L00470700: { // 0x470700: c70540d97b0000000000 MOV dword ptr [0x007bd940],0x0
    m.w32((0x007bd940u), 0x00000000u);
  }
  L0047070a: { // 0x47070a: c70544d97b000000f0bf MOV dword ptr [0x007bd944],0xbff00000
    m.w32((0x007bd944u), 0xbff00000u);
  }
  L00470714: { // 0x470714: 890d4cd97b00 MOV dword ptr [0x007bd94c],ECX
    m.w32((0x007bd94cu), s.cx);
  }
  L0047071a: { // 0x47071a: 891550d97b00 MOV dword ptr [0x007bd950],EDX
    m.w32((0x007bd950u), s.dx);
  }
  L00470720: { // 0x470720: a354d97b00 MOV [0x007bd954],EAX
    m.w32((0x007bd954u), s.ax);
  }
  L00470725: { // 0x470725: c70558d97b0000000000 MOV dword ptr [0x007bd958],0x0
    m.w32((0x007bd958u), 0x00000000u);
  }
  L0047072f: { // 0x47072f: c7055cd97b0000000000 MOV dword ptr [0x007bd95c],0x0
    m.w32((0x007bd95cu), 0x00000000u);
  }
  L00470739: { // 0x470739: c70560d97b0000000000 MOV dword ptr [0x007bd960],0x0
    m.w32((0x007bd960u), 0x00000000u);
  }
  L00470743: { // 0x470743: c70564d97b000000f03f MOV dword ptr [0x007bd964],0x3ff00000
    m.w32((0x007bd964u), 0x3ff00000u);
  }
  L0047074d: { // 0x47074d: c70568d97b0000000000 MOV dword ptr [0x007bd968],0x0
    m.w32((0x007bd968u), 0x00000000u);
  }
  L00470757: { // 0x470757: c7056cd97b000000f03f MOV dword ptr [0x007bd96c],0x3ff00000
    m.w32((0x007bd96cu), 0x3ff00000u);
  }
  L00470761: { // 0x470761: c70570d97b0000000000 MOV dword ptr [0x007bd970],0x0
    m.w32((0x007bd970u), 0x00000000u);
  }
  L0047076b: { // 0x47076b: c70574d97b0000000000 MOV dword ptr [0x007bd974],0x0
    m.w32((0x007bd974u), 0x00000000u);
  }
  L00470775: { // 0x470775: c70580d97b0000000000 MOV dword ptr [0x007bd980],0x0
    m.w32((0x007bd980u), 0x00000000u);
  }
  L0047077f: { // 0x47077f: c70584d97b0000000000 MOV dword ptr [0x007bd984],0x0
    m.w32((0x007bd984u), 0x00000000u);
  }
  L00470789: { // 0x470789: c70588d97b0000000000 MOV dword ptr [0x007bd988],0x0
    m.w32((0x007bd988u), 0x00000000u);
  }
  L00470793: { // 0x470793: dd15a0d97b00 FST double ptr [0x007bd9a0]
    const auto address=(0x007bd9a0u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L00470799: { // 0x470799: dd15c0d97b00 FST double ptr [0x007bd9c0]
    const auto address=(0x007bd9c0u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L0047079f: { // 0x47079f: dd15c8d97b00 FST double ptr [0x007bd9c8]
    const auto address=(0x007bd9c8u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L004707a5: { // 0x4707a5: dd1df0d97b00 FSTP double ptr [0x007bd9f0]
    const auto address=(0x007bd9f0u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L004707ab: { // 0x4707ab: dd05f08e8300 FLD double ptr [0x00838ef0]
    const auto address=(0x00838ef0u);
    s.fp.load64(read64(m,address));
  }
  L004707b1: { // 0x4707b1: dc0d28577800 FMUL double ptr [0x00785728]
    const auto address=(0x00785728u);
    s.fp.multiply64(read64(m,address));
  }
  L004707b7: { // 0x4707b7: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L004707b9: { // 0x4707b9: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L004707bb: { // 0x4707bb: 890d98d97b00 MOV dword ptr [0x007bd998],ECX
    m.w32((0x007bd998u), s.cx);
  }
  L004707c1: { // 0x4707c1: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004707c3: { // 0x4707c3: 89159cd97b00 MOV dword ptr [0x007bd99c],EDX
    m.w32((0x007bd99cu), s.dx);
  }
  L004707c9: { // 0x4707c9: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L004707cb: { // 0x4707cb: dd1518da7b00 FST double ptr [0x007bda18]
    const auto address=(0x007bda18u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L004707d1: { // 0x4707d1: dd1520da7b00 FST double ptr [0x007bda20]
    const auto address=(0x007bda20u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L004707d7: { // 0x4707d7: dd1540da7b00 FST double ptr [0x007bda40]
    const auto address=(0x007bda40u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L004707dd: { // 0x4707dd: dd05f08e8300 FLD double ptr [0x00838ef0]
    const auto address=(0x00838ef0u);
    s.fp.load64(read64(m,address));
  }
  L004707e3: { // 0x4707e3: dc0db0797800 FMUL double ptr [0x007879b0]
    const auto address=(0x007879b0u);
    s.fp.multiply64(read64(m,address));
  }
  L004707e9: { // 0x4707e9: a3e8d97b00 MOV [0x007bd9e8],EAX
    m.w32((0x007bd9e8u), s.ax);
  }
  L004707ee: { // 0x4707ee: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L004707f0: { // 0x4707f0: 890decd97b00 MOV dword ptr [0x007bd9ec],ECX
    m.w32((0x007bd9ecu), s.cx);
  }
  L004707f6: { // 0x4707f6: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004707f8: { // 0x4707f8: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L004707fa: { // 0x4707fa: 891538da7b00 MOV dword ptr [0x007bda38],EDX
    m.w32((0x007bda38u), s.dx);
  }
  L00470800: { // 0x470800: dd542408 FST double ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L00470804: { // 0x470804: dd1d48da7b00 FSTP double ptr [0x007bda48]
    const auto address=(0x007bda48u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0047080a: { // 0x47080a: a33cda7b00 MOV [0x007bda3c],EAX
    m.w32((0x007bda3cu), s.ax);
  }
  L0047080f: { // 0x47080f: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00470811: { // 0x470811: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L00470815: { // 0x470815: 890d88da7b00 MOV dword ptr [0x007bda88],ECX
    m.w32((0x007bda88u), s.cx);
  }
  L0047081b: { // 0x47081b: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L0047081f: { // 0x47081f: c7058cd97b000000f0bf MOV dword ptr [0x007bd98c],0xbff00000
    m.w32((0x007bd98cu), 0xbff00000u);
  }
  L00470829: { // 0x470829: dd1568da7b00 FST double ptr [0x007bda68]
    const auto address=(0x007bda68u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L0047082f: { // 0x47082f: dd1570da7b00 FST double ptr [0x007bda70]
    const auto address=(0x007bda70u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L00470835: { // 0x470835: dd1d90da7b00 FSTP double ptr [0x007bda90]
    const auto address=(0x007bda90u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0047083b: { // 0x47083b: c70590d97b0000000000 MOV dword ptr [0x007bd990],0x0
    m.w32((0x007bd990u), 0x00000000u);
  }
  L00470845: { // 0x470845: c70594d97b000000f03f MOV dword ptr [0x007bd994],0x3ff00000
    m.w32((0x007bd994u), 0x3ff00000u);
  }
  L0047084f: { // 0x47084f: c705a8d97b0000000000 MOV dword ptr [0x007bd9a8],0x0
    m.w32((0x007bd9a8u), 0x00000000u);
  }
  L00470859: { // 0x470859: c705acd97b0000000000 MOV dword ptr [0x007bd9ac],0x0
    m.w32((0x007bd9acu), 0x00000000u);
  }
  L00470863: { // 0x470863: c705b0d97b0000000000 MOV dword ptr [0x007bd9b0],0x0
    m.w32((0x007bd9b0u), 0x00000000u);
  }
  L0047086d: { // 0x47086d: c705b4d97b000000f0bf MOV dword ptr [0x007bd9b4],0xbff00000
    m.w32((0x007bd9b4u), 0xbff00000u);
  }
  L00470877: { // 0x470877: c705b8d97b0000000000 MOV dword ptr [0x007bd9b8],0x0
    m.w32((0x007bd9b8u), 0x00000000u);
  }
  L00470881: { // 0x470881: c705bcd97b000000f0bf MOV dword ptr [0x007bd9bc],0xbff00000
    m.w32((0x007bd9bcu), 0xbff00000u);
  }
  L0047088b: { // 0x47088b: c705d0d97b0000000000 MOV dword ptr [0x007bd9d0],0x0
    m.w32((0x007bd9d0u), 0x00000000u);
  }
  L00470895: { // 0x470895: c705d4d97b0000000000 MOV dword ptr [0x007bd9d4],0x0
    m.w32((0x007bd9d4u), 0x00000000u);
  }
  L0047089f: { // 0x47089f: c705d8d97b0000000000 MOV dword ptr [0x007bd9d8],0x0
    m.w32((0x007bd9d8u), 0x00000000u);
  }
  L004708a9: { // 0x4708a9: c705dcd97b000000f03f MOV dword ptr [0x007bd9dc],0x3ff00000
    m.w32((0x007bd9dcu), 0x3ff00000u);
  }
  L004708b3: { // 0x4708b3: c705e0d97b0000000000 MOV dword ptr [0x007bd9e0],0x0
    m.w32((0x007bd9e0u), 0x00000000u);
  }
  L004708bd: { // 0x4708bd: c705e4d97b000000f0bf MOV dword ptr [0x007bd9e4],0xbff00000
    m.w32((0x007bd9e4u), 0xbff00000u);
  }
  L004708c7: { // 0x4708c7: c705f8d97b0000000000 MOV dword ptr [0x007bd9f8],0x0
    m.w32((0x007bd9f8u), 0x00000000u);
  }
  L004708d1: { // 0x4708d1: c705fcd97b0000000000 MOV dword ptr [0x007bd9fc],0x0
    m.w32((0x007bd9fcu), 0x00000000u);
  }
  L004708db: { // 0x4708db: c70500da7b0000000000 MOV dword ptr [0x007bda00],0x0
    m.w32((0x007bda00u), 0x00000000u);
  }
  L004708e5: { // 0x4708e5: c70504da7b0000000000 MOV dword ptr [0x007bda04],0x0
    m.w32((0x007bda04u), 0x00000000u);
  }
  L004708ef: { // 0x4708ef: c70508da7b0000000000 MOV dword ptr [0x007bda08],0x0
    m.w32((0x007bda08u), 0x00000000u);
  }
  L004708f9: { // 0x4708f9: c7050cda7b0000000000 MOV dword ptr [0x007bda0c],0x0
    m.w32((0x007bda0cu), 0x00000000u);
  }
  L00470903: { // 0x470903: c70510da7b0000000000 MOV dword ptr [0x007bda10],0x0
    m.w32((0x007bda10u), 0x00000000u);
  }
  L0047090d: { // 0x47090d: c70514da7b0000000000 MOV dword ptr [0x007bda14],0x0
    m.w32((0x007bda14u), 0x00000000u);
  }
  L00470917: { // 0x470917: c70528da7b0000000000 MOV dword ptr [0x007bda28],0x0
    m.w32((0x007bda28u), 0x00000000u);
  }
  L00470921: { // 0x470921: c7052cda7b0000000000 MOV dword ptr [0x007bda2c],0x0
    m.w32((0x007bda2cu), 0x00000000u);
  }
  L0047092b: { // 0x47092b: c70530da7b0000000000 MOV dword ptr [0x007bda30],0x0
    m.w32((0x007bda30u), 0x00000000u);
  }
  L00470935: { // 0x470935: c70534da7b0000000000 MOV dword ptr [0x007bda34],0x0
    m.w32((0x007bda34u), 0x00000000u);
  }
  L0047093f: { // 0x47093f: c70550da7b0000000000 MOV dword ptr [0x007bda50],0x0
    m.w32((0x007bda50u), 0x00000000u);
  }
  L00470949: { // 0x470949: c70554da7b0000000000 MOV dword ptr [0x007bda54],0x0
    m.w32((0x007bda54u), 0x00000000u);
  }
  L00470953: { // 0x470953: c70558da7b0000000000 MOV dword ptr [0x007bda58],0x0
    m.w32((0x007bda58u), 0x00000000u);
  }
  L0047095d: { // 0x47095d: c7055cda7b0000000000 MOV dword ptr [0x007bda5c],0x0
    m.w32((0x007bda5cu), 0x00000000u);
  }
  L00470967: { // 0x470967: c70560da7b0000000000 MOV dword ptr [0x007bda60],0x0
    m.w32((0x007bda60u), 0x00000000u);
  }
  L00470971: { // 0x470971: c70564da7b0000000000 MOV dword ptr [0x007bda64],0x0
    m.w32((0x007bda64u), 0x00000000u);
  }
  L0047097b: { // 0x47097b: c70578da7b0000000000 MOV dword ptr [0x007bda78],0x0
    m.w32((0x007bda78u), 0x00000000u);
  }
  L00470985: { // 0x470985: c7057cda7b0000000000 MOV dword ptr [0x007bda7c],0x0
    m.w32((0x007bda7cu), 0x00000000u);
  }
  L0047098f: { // 0x47098f: c70580da7b0000000000 MOV dword ptr [0x007bda80],0x0
    m.w32((0x007bda80u), 0x00000000u);
  }
  L00470999: { // 0x470999: c70584da7b0000000000 MOV dword ptr [0x007bda84],0x0
    m.w32((0x007bda84u), 0x00000000u);
  }
  L004709a3: { // 0x4709a3: 89158cda7b00 MOV dword ptr [0x007bda8c],EDX
    m.w32((0x007bda8cu), s.dx);
  }
  L004709a9: { // 0x4709a9: a398da7b00 MOV [0x007bda98],EAX
    m.w32((0x007bda98u), s.ax);
  }
  L004709ae: { // 0x4709ae: 890d9cda7b00 MOV dword ptr [0x007bda9c],ECX
    m.w32((0x007bda9cu), s.cx);
  }
  L004709b4: { // 0x4709b4: 0fbe961b010000 MOVSX EDX,byte ptr [ESI + 0x11b]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.si+0x0000011bu)),8));
  }
  L004709bb: { // 0x4709bb: 0faf15808f8300 IMUL EDX,dword ptr [0x00838f80]
    s.dx = integer::imul(s.dx,m.r32((0x00838f80u)),32,flags);
  }
  L004709c2: { // 0x4709c2: 89542404 MOV dword ptr [ESP + 0x4],EDX
    m.w32((f.sp+0x00000004u), s.dx);
  }
  L004709c6: { // 0x4709c6: db442404 FILD dword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load_integer32(m.r32(address));
  }
  L004709ca: { // 0x4709ca: dc0528577800 FADD double ptr [0x00785728]
    const auto address=(0x00785728u);
    s.fp.add64(read64(m,address));
  }
  L004709d0: { // 0x4709d0: e87ba02f00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4655573u); flags=s.arithmetic_flags;
  }
  L004709d5: { // 0x4709d5: 8a8e1c010000 MOV CL,byte ptr [ESI + 0x11c]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000011cu)));
  }
  L004709db: { // 0x4709db: 89442408 MOV dword ptr [ESP + 0x8],EAX
    m.w32((f.sp+0x00000008u), s.ax);
  }
  L004709df: { // 0x4709df: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004709e1: { // 0x4709e1: 0f868d000000 JBE 0x00470a74
    if(integer::condition("JBE",flags)) goto L00470a74;
  }
  L004709e7: { // 0x4709e7: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L004709ea: { // 0x4709ea: 81e1ff000000 AND ECX,0xff
    s.cx = integer::logical((s.cx)&(0x000000ffu),32,flags);
  }
  L004709f0: { // 0x4709f0: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L004709f1: { // 0x4709f1: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L004709f4: { // 0x4709f4: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L004709f6: { // 0x4709f6: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L004709fc: { // 0x4709fc: 8d0c89 LEA ECX,[ECX + ECX*0x4]
    s.cx = (s.cx+(s.cx * 0x00000004u));
  }
  L004709ff: { // 0x4709ff: 89542404 MOV dword ptr [ESP + 0x4],EDX
    m.w32((f.sp+0x00000004u), s.dx);
  }
  L00470a03: { // 0x470a03: 25ff000000 AND EAX,0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  L00470a08: { // 0x470a08: db442404 FILD dword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load_integer32(m.r32(address));
  }
  L00470a0c: { // 0x470a0c: c1e103 SHL ECX,0x3
    s.cx = integer::shift(s.cx,0x00000003u,32,flags,integer::Shift::left);
  }
  L00470a0f: { // 0x470a0f: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  L00470a13: { // 0x470a13: dc8988d77b00 FMUL double ptr [ECX + 0x7bd788]
    const auto address=(s.cx+0x007bd788u);
    s.fp.multiply64(read64(m,address));
  }
  L00470a19: { // 0x470a19: dc0d108f8300 FMUL double ptr [0x00838f10]
    const auto address=(0x00838f10u);
    s.fp.multiply64(read64(m,address));
  }
  L00470a1f: { // 0x470a1f: db442404 FILD dword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load_integer32(m.r32(address));
  }
  L00470a23: { // 0x470a23: dc8980d77b00 FMUL double ptr [ECX + 0x7bd780]
    const auto address=(s.cx+0x007bd780u);
    s.fp.multiply64(read64(m,address));
  }
  L00470a29: { // 0x470a29: dc0d108f8300 FMUL double ptr [0x00838f10]
    const auto address=(0x00838f10u);
    s.fp.multiply64(read64(m,address));
  }
  L00470a2f: { // 0x470a2f: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L00470a31: { // 0x470a31: dc8190d77b00 FADD double ptr [ECX + 0x7bd790]
    const auto address=(s.cx+0x007bd790u);
    s.fp.add64(read64(m,address));
  }
  L00470a37: { // 0x470a37: dc81a0d77b00 FADD double ptr [ECX + 0x7bd7a0]
    const auto address=(s.cx+0x007bd7a0u);
    s.fp.add64(read64(m,address));
  }
  L00470a3d: { // 0x470a3d: dc1510667800 FCOM double ptr [0x00786610]
    const auto address=(0x00786610u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L00470a43: { // 0x470a43: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00470a45: { // 0x470a45: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00470a48: { // 0x470a48: 7408 JZ 0x00470a52
    if(integer::condition("JZ",flags)) goto L00470a52;
  }
  L00470a4a: { // 0x470a4a: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00470a4c: { // 0x470a4c: dd0510667800 FLD double ptr [0x00786610]
    const auto address=(0x00786610u);
    s.fp.load64(read64(m,address));
  }
  L00470a52: { // 0x470a52: dc9198d77b00 FCOM double ptr [ECX + 0x7bd798]
    const auto address=(s.cx+0x007bd798u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L00470a58: { // 0x470a58: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00470a5a: { // 0x470a5a: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L00470a5d: { // 0x470a5d: 7508 JNZ 0x00470a67
    if(integer::condition("JNZ",flags)) goto L00470a67;
  }
  L00470a5f: { // 0x470a5f: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00470a61: { // 0x470a61: dd8198d77b00 FLD double ptr [ECX + 0x7bd798]
    const auto address=(s.cx+0x007bd798u);
    s.fp.load64(read64(m,address));
  }
  L00470a67: { // 0x470a67: db442408 FILD dword ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.load_integer32(m.r32(address));
  }
  L00470a6b: { // 0x470a6b: d8c1 FADD ST0,ST1
    numeric_b88::detail::reg<0xd8c1>(s.fp);
  }
  L00470a6d: { // 0x470a6d: e8de9f2f00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4655730u); flags=s.arithmetic_flags;
  }
  L00470a72: { // 0x470a72: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00470a74: { // 0x470a74: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00470a75: { // 0x470a75: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L00470a77: { // 0x470a77: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00470a78: { // 0x470a78: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00164f30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00564f30: { // 0x564f30: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00564f33: { // 0x564f33: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00564f34: { // 0x564f34: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L00564f38: { // 0x564f38: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L00564f3b: { // 0x564f3b: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00564f3c: { // 0x564f3c: f73d4878a500 IDIV dword ptr [0x00a57848]
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(m.r32((0x00a57848u)),32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00564f42: { // 0x564f42: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L00564f44: { // 0x564f44: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00564f45: { // 0x564f45: 0f848d000000 JZ 0x00564fd8
    if(integer::condition("JZ",flags)) goto L00564fd8;
  }
  L00564f4b: { // 0x564f4b: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00564f4d: { // 0x564f4d: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00564f4f: { // 0x564f4f: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00564f51: { // 0x564f51: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00564f52: { // 0x564f52: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00564f58: { // 0x564f58: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00564f5a: { // 0x564f5a: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00564f5d: { // 0x564f5d: 6689442404 MOV word ptr [ESP + 0x4],AX
    m.w16((f.sp+0x00000004u), (s.ax & 0xffffu));
  }
  L00564f62: { // 0x564f62: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L00564f65: { // 0x564f65: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00564f66: { // 0x564f66: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00564f6c: { // 0x564f6c: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00564f6e: { // 0x564f6e: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00564f71: { // 0x564f71: d1f9 SAR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00564f73: { // 0x564f73: 6689442406 MOV word ptr [ESP + 0x6],AX
    m.w16((f.sp+0x00000006u), (s.ax & 0xffffu));
  }
  L00564f78: { // 0x564f78: 8b442406 MOV EAX,dword ptr [ESP + 0x6]
    s.ax = m.r32((f.sp+0x00000006u));
  }
  L00564f7c: { // 0x564f7c: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L00564f80: { // 0x564f80: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00564f81: { // 0x564f81: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00564f83: { // 0x564f83: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L00564f85: { // 0x564f85: 6689442412 MOV word ptr [ESP + 0x12],AX
    m.w16((f.sp+0x00000012u), (s.ax & 0xffffu));
  }
  L00564f8a: { // 0x564f8a: 6689542410 MOV word ptr [ESP + 0x10],DX
    m.w16((f.sp+0x00000010u), (s.dx & 0xffffu));
  }
  L00564f8f: { // 0x564f8f: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00564f92: { // 0x564f92: 0fbfca MOVSX ECX,DX
    s.cx = std::uint32_t(integer::sign_extend((s.dx & 0xffffu),16));
  }
  L00564f95: { // 0x564f95: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L00564f98: { // 0x564f98: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00564f9a: { // 0x564f9a: 7818 JS 0x00564fb4
    if(integer::condition("JS",flags)) goto L00564fb4;
  }
  L00564f9c: { // 0x564f9c: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00564fa1: { // 0x564fa1: 7d11 JGE 0x00564fb4
    if(integer::condition("JGE",flags)) goto L00564fb4;
  }
  L00564fa3: { // 0x564fa3: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L00564fa9: { // 0x564fa9: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L00564fac: { // 0x564fac: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00564fae: { // 0x564fae: 7404 JZ 0x00564fb4
    if(integer::condition("JZ",flags)) goto L00564fb4;
  }
  L00564fb0: { // 0x564fb0: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00564fb2: { // 0x564fb2: eb0e JMP 0x00564fc2
    goto L00564fc2;
  }
  L00564fb4: { // 0x564fb4: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00564fb8: { // 0x564fb8: b91076a500 MOV ECX,0xa57610
    s.cx = 0x00a57610u;
  }
  L00564fbd: { // 0x564fbd: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L00564fc2: { // 0x564fc2: f6812c01000008 TEST byte ptr [ECX + 0x12c],0x8
    (void)integer::logical((m.r8((s.cx+0x0000012cu)))&(0x00000008u),8,flags);
  }
  L00564fc9: { // 0x564fc9: 0f858d000000 JNZ 0x0056505c
    if(integer::condition("JNZ",flags)) goto L0056505c;
  }
  L00564fcf: { // 0x564fcf: 6a03 PUSH 0x3
    f.push(m,0x00000003u);
  }
  L00564fd1: { // 0x564fd1: e8ea16f1ff CALL 0x004766c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004766c0u,5656534u); flags=s.arithmetic_flags;
  }
  L00564fd6: { // 0x564fd6: eb72 JMP 0x0056504a
    goto L0056504a;
  }
  L00564fd8: { // 0x564fd8: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00564fda: { // 0x564fda: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00564fdc: { // 0x564fdc: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00564fde: { // 0x564fde: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00564fdf: { // 0x564fdf: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00564fe5: { // 0x564fe5: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00564fe7: { // 0x564fe7: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00564fea: { // 0x564fea: 6689442404 MOV word ptr [ESP + 0x4],AX
    m.w16((f.sp+0x00000004u), (s.ax & 0xffffu));
  }
  L00564fef: { // 0x564fef: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L00564ff2: { // 0x564ff2: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00564ff3: { // 0x564ff3: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00564ff9: { // 0x564ff9: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00564ffb: { // 0x564ffb: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00564ffe: { // 0x564ffe: 6689442406 MOV word ptr [ESP + 0x6],AX
    m.w16((f.sp+0x00000006u), (s.ax & 0xffffu));
  }
  L00565003: { // 0x565003: 8b442406 MOV EAX,dword ptr [ESP + 0x6]
    s.ax = m.r32((f.sp+0x00000006u));
  }
  L00565007: { // 0x565007: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L0056500b: { // 0x56500b: d1f9 SAR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0056500d: { // 0x56500d: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L0056500f: { // 0x56500f: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L00565011: { // 0x565011: 6689442412 MOV word ptr [ESP + 0x12],AX
    m.w16((f.sp+0x00000012u), (s.ax & 0xffffu));
  }
  L00565016: { // 0x565016: 6689542410 MOV word ptr [ESP + 0x10],DX
    m.w16((f.sp+0x00000010u), (s.dx & 0xffffu));
  }
  L0056501b: { // 0x56501b: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0056501e: { // 0x56501e: 0fbfca MOVSX ECX,DX
    s.cx = std::uint32_t(integer::sign_extend((s.dx & 0xffffu),16));
  }
  L00565021: { // 0x565021: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L00565024: { // 0x565024: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00565026: { // 0x565026: 7814 JS 0x0056503c
    if(integer::condition("JS",flags)) goto L0056503c;
  }
  L00565028: { // 0x565028: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L0056502d: { // 0x56502d: 7d0d JGE 0x0056503c
    if(integer::condition("JGE",flags)) goto L0056503c;
  }
  L0056502f: { // 0x56502f: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L00565035: { // 0x565035: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L00565038: { // 0x565038: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0056503a: { // 0x56503a: 750e JNZ 0x0056504a
    if(integer::condition("JNZ",flags)) goto L0056504a;
  }
  L0056503c: { // 0x56503c: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00565040: { // 0x565040: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L00565045: { // 0x565045: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L0056504a: { // 0x56504a: f6802c01000008 TEST byte ptr [EAX + 0x12c],0x8
    (void)integer::logical((m.r8((s.ax+0x0000012cu)))&(0x00000008u),8,flags);
  }
  L00565051: { // 0x565051: 7509 JNZ 0x0056505c
    if(integer::condition("JNZ",flags)) goto L0056505c;
  }
  L00565053: { // 0x565053: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00565055: { // 0x565055: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00565056: { // 0x565056: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00565059: { // 0x565059: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0056505c: { // 0x56505c: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0056505e: { // 0x56505e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0056505f: { // 0x56505f: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00565062: { // 0x565062: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0000dc20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0040dc20: { // 0x40dc20: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0040dc21: { // 0x40dc21: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0040dc23: { // 0x40dc23: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0040dc25: { // 0x40dc25: 741e JZ 0x0040dc45
    if(integer::condition("JZ",flags)) goto L0040dc45;
  }
  L0040dc27: { // 0x40dc27: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0040dc29: { // 0x40dc29: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),4250668u); flags=s.arithmetic_flags;
  }
  L0040dc2c: { // 0x40dc2c: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0040dc2d: { // 0x40dc2d: 83f80e CMP EAX,0xe
    (void)integer::sub(s.ax,0x0000000eu,32,flags);
  }
  L0040dc30: { // 0x40dc30: 7713 JA 0x0040dc45
    if(integer::condition("JA",flags)) goto L0040dc45;
  }
  L0040dc32: { // 0x40dc32: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0040dc34: { // 0x40dc34: 8a8854dc4000 MOV CL,byte ptr [EAX + 0x40dc54]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0040dc54u)));
  }
  L0040dc3a: { // 0x40dc3a: ff248d4cdc4000 JMP dword ptr [ECX*0x4 + 0x40dc4c]
    switch(m.r32(((s.cx * 0x00000004u)+0x0040dc4cu))){
    case 0x0040dc20u: goto L0040dc20;
    case 0x0040dc21u: goto L0040dc21;
    case 0x0040dc23u: goto L0040dc23;
    case 0x0040dc25u: goto L0040dc25;
    case 0x0040dc27u: goto L0040dc27;
    case 0x0040dc29u: goto L0040dc29;
    case 0x0040dc2cu: goto L0040dc2c;
    case 0x0040dc2du: goto L0040dc2d;
    case 0x0040dc30u: goto L0040dc30;
    case 0x0040dc32u: goto L0040dc32;
    case 0x0040dc34u: goto L0040dc34;
    case 0x0040dc3au: goto L0040dc3a;
    case 0x0040dc41u: goto L0040dc41;
    case 0x0040dc43u: goto L0040dc43;
    case 0x0040dc44u: goto L0040dc44;
    case 0x0040dc45u: goto L0040dc45;
    case 0x0040dc47u: goto L0040dc47;
    case 0x0040dc48u: goto L0040dc48;
    default:throw std::domain_error("557 unexpected switch");}
  }
  L0040dc41: { // 0x40dc41: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0040dc43: { // 0x40dc43: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0040dc44: { // 0x40dc44: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0040dc45: { // 0x40dc45: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0040dc47: { // 0x40dc47: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0040dc48: { // 0x40dc48: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002b6910(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006b6910: { // 0x6b6910: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006b6912: { // 0x6b6912: ffa084000000 JMP dword ptr [EAX + 0x84]
    s.arithmetic_flags=flags; tail(m,s,f,m.r32((s.ax+0x00000084u))); return;
  }
}
void f_000538b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004538b0: { // 0x4538b0: 8b8118040000 MOV EAX,dword ptr [ECX + 0x418]
    s.ax = m.r32((s.cx+0x00000418u));
  }
  L004538b6: { // 0x4538b6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00053890(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00453890: { // 0x453890: b806000000 MOV EAX,0x6
    s.ax = 0x00000006u;
  }
  L00453895: { // 0x453895: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 6946768u:f_0029ffd0(m,s,child,{});break;
case 6930960u:f_0029c210(m,s,child,{});break;
case 5824896u:f_0018e180(m,s,child,{});break;
case 6913504u:f_00297de0(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
case 5526784u:f_00145500(m,s,child,{});break;
case 4679360u:f_000766c0(m,s,child,{});break;
case 4699488u:f_0007b560(m,s,child,{});break;
case 4699520u:f_0007b580(m,s,child,{});break;
case 6914384u:f_00298150(m,s,child,{});break;
case 5537680u:f_00147f90(m,s,child,{});break;
case 5599344u:f_00157070(m,s,child,{});break;
case 4653760u:f_000702c0(m,s,child,{});break;
case 5656368u:f_00164f30(m,s,child,{});break;
case 4250656u:f_0000dc20(m,s,child,{});break;
case 7039248u:f_002b6910(m,s,child,{});break;
case 4536496u:f_000538b0(m,s,child,{});break;
case 4536464u:f_00053890(m,s,child,{});break;
default:throw std::domain_error("recovery557 unreviewed original call");}
f.sp=child.sp;
}
}
namespace { void tail(Memory&m,State&s,Frame&f,std::uint32_t target){switch(target){case 6946768u:f_0029ffd0(m,s,f,{});return;case 6930960u:f_0029c210(m,s,f,{});return;case 5824896u:f_0018e180(m,s,f,{});return;case 6913504u:f_00297de0(m,s,f,{});return;case 7776848u:f_0036aa50(m,s,f,{});return;case 5526784u:f_00145500(m,s,f,{});return;case 4679360u:f_000766c0(m,s,f,{});return;case 4699488u:f_0007b560(m,s,f,{});return;case 4699520u:f_0007b580(m,s,f,{});return;case 6914384u:f_00298150(m,s,f,{});return;case 5537680u:f_00147f90(m,s,f,{});return;case 5599344u:f_00157070(m,s,f,{});return;case 4653760u:f_000702c0(m,s,f,{});return;case 5656368u:f_00164f30(m,s,f,{});return;case 4250656u:f_0000dc20(m,s,f,{});return;case 7039248u:f_002b6910(m,s,f,{});return;case 4536496u:f_000538b0(m,s,f,{});return;case 4536464u:f_00053890(m,s,f,{});return;default:throw std::domain_error("557 unexpected tail");}}}

std::uint32_t fun_00660600(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 std::array<std::uint8_t,23> table{0x41,0xdc,0x40,0x0,0x45,0xdc,0x40,0x0,0x0,0x0,0x1,0x1,0x1,0x0,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x0};leaf::Memory ro(table.data(),0x40dc4c,23);m.add(ro);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00660600: { // 0x660600: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00660604: { // 0x660604: 83ec18 SUB ESP,0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
  L00660607: { // 0x660607: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L0066060b: { // 0x66060b: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0066060c: { // 0x66060c: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0066060d: { // 0x66060d: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0066060e: { // 0x66060e: 8b74242c MOV ESI,dword ptr [ESP + 0x2c]
    s.si = m.r32((f.sp+0x0000002cu));
  }
  L00660612: { // 0x660612: c70000000000 MOV dword ptr [EAX],0x0
    m.w32((s.ax), 0x00000000u);
  }
  L00660618: { // 0x660618: 8b0d70eba900 MOV ECX,dword ptr [0x00a9eb70]
    s.cx = m.r32((0x00a9eb70u));
  }
  L0066061e: { // 0x66061e: 890e MOV dword ptr [ESI],ECX
    m.w32((s.si), s.cx);
  }
  L00660620: { // 0x660620: a190eba900 MOV EAX,[0x00a9eb90]
    s.ax = m.r32((0x00a9eb90u));
  }
  L00660625: { // 0x660625: 8b6c2428 MOV EBP,dword ptr [ESP + 0x28]
    s.bp = m.r32((f.sp+0x00000028u));
  }
  L00660629: { // 0x660629: 8902 MOV dword ptr [EDX],EAX
    m.w32((s.dx), s.ax);
  }
  L0066062b: { // 0x66062b: 8b0d94eba900 MOV ECX,dword ptr [0x00a9eb94]
    s.cx = m.r32((0x00a9eb94u));
  }
  L00660631: { // 0x660631: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00660632: { // 0x660632: 8b7c243c MOV EDI,dword ptr [ESP + 0x3c]
    s.di = m.r32((f.sp+0x0000003cu));
  }
  L00660636: { // 0x660636: 894a04 MOV dword ptr [EDX + 0x4],ECX
    m.w32((s.dx+0x00000004u), s.cx);
  }
  L00660639: { // 0x660639: a198eba900 MOV EAX,[0x00a9eb98]
    s.ax = m.r32((0x00a9eb98u));
  }
  L0066063e: { // 0x66063e: 8b4c2440 MOV ECX,dword ptr [ESP + 0x40]
    s.cx = m.r32((f.sp+0x00000040u));
  }
  L00660642: { // 0x660642: 894208 MOV dword ptr [EDX + 0x8],EAX
    m.w32((s.dx+0x00000008u), s.ax);
  }
  L00660645: { // 0x660645: c60700 MOV byte ptr [EDI],0x0
    m.w8((s.di), 0x00000000u);
  }
  L00660648: { // 0x660648: c60100 MOV byte ptr [ECX],0x0
    m.w8((s.cx), 0x00000000u);
  }
  L0066064b: { // 0x66064b: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L0066064e: { // 0x66064e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00660650: { // 0x660650: 0f8ca6020000 JL 0x006608fc
    if(integer::condition("JL",flags)) goto L006608fc;
  }
  L00660656: { // 0x660656: 8b5d04 MOV EBX,dword ptr [EBP + 0x4]
    s.bx = m.r32((s.bp+0x00000004u));
  }
  L00660659: { // 0x660659: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L0066065b: { // 0x66065b: 0f8c9b020000 JL 0x006608fc
    if(integer::condition("JL",flags)) goto L006608fc;
  }
  L00660661: { // 0x660661: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L00660667: { // 0x660667: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00660669: { // 0x660669: 742e JZ 0x00660699
    if(integer::condition("JZ",flags)) goto L00660699;
  }
  L0066066b: { // 0x66066b: 8b1570198200 MOV EDX,dword ptr [0x00821970]
    s.dx = m.r32((0x00821970u));
  }
  L00660671: { // 0x660671: 8b3d74198200 MOV EDI,dword ptr [0x00821974]
    s.di = m.r32((0x00821974u));
  }
  L00660677: { // 0x660677: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00660679: { // 0x660679: 8d143b LEA EDX,[EBX + EDI*0x1]
    s.dx = (s.bx+(s.di * 0x00000001u));
  }
  L0066067c: { // 0x66067c: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00660680: { // 0x660680: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L00660684: { // 0x660684: 8d542410 LEA EDX,[ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  L00660688: { // 0x660688: 8d442430 LEA EAX,[ESP + 0x30]
    s.ax = (f.sp+0x00000030u);
  }
  L0066068c: { // 0x66068c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0066068d: { // 0x66068d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0066068e: { // 0x66068e: e87dbb0300 CALL 0x0069c210
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069c210u,6686355u); flags=s.arithmetic_flags;
  }
  L00660693: { // 0x660693: 8b7c243c MOV EDI,dword ptr [ESP + 0x3c]
    s.di = m.r32((f.sp+0x0000003cu));
  }
  L00660697: { // 0x660697: eb05 JMP 0x0066069e
    goto L0066069e;
  }
  L00660699: { // 0x660699: b870eba900 MOV EAX,0xa9eb70
    s.ax = 0x00a9eb70u;
  }
  L0066069e: { // 0x66069e: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L006606a0: { // 0x6606a0: 890e MOV dword ptr [ESI],ECX
    m.w32((s.si), s.cx);
  }
  L006606a2: { // 0x6606a2: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L006606a8: { // 0x6606a8: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006606aa: { // 0x6606aa: 7432 JZ 0x006606de
    if(integer::condition("JZ",flags)) goto L006606de;
  }
  L006606ac: { // 0x6606ac: 8b3d70198200 MOV EDI,dword ptr [0x00821970]
    s.di = m.r32((0x00821970u));
  }
  L006606b2: { // 0x6606b2: 8b5500 MOV EDX,dword ptr [EBP]
    s.dx = m.r32((s.bp));
  }
  L006606b5: { // 0x6606b5: a174198200 MOV EAX,[0x00821974]
    s.ax = m.r32((0x00821974u));
  }
  L006606ba: { // 0x6606ba: 8b5d04 MOV EBX,dword ptr [EBP + 0x4]
    s.bx = m.r32((s.bp+0x00000004u));
  }
  L006606bd: { // 0x6606bd: 03d7 ADD EDX,EDI
    s.dx = integer::add(s.dx,s.di,32,flags);
  }
  L006606bf: { // 0x6606bf: 03c3 ADD EAX,EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L006606c1: { // 0x6606c1: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L006606c5: { // 0x6606c5: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L006606c9: { // 0x6606c9: 8d542410 LEA EDX,[ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  L006606cd: { // 0x6606cd: 8d44241c LEA EAX,[ESP + 0x1c]
    s.ax = (f.sp+0x0000001cu);
  }
  L006606d1: { // 0x6606d1: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006606d2: { // 0x6606d2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006606d3: { // 0x6606d3: e8787a0300 CALL 0x00698150
    s.arithmetic_flags=flags; invoke(m,s,f,0x00698150u,6686424u); flags=s.arithmetic_flags;
  }
  L006606d8: { // 0x6606d8: 8b7c243c MOV EDI,dword ptr [ESP + 0x3c]
    s.di = m.r32((f.sp+0x0000003cu));
  }
  L006606dc: { // 0x6606dc: eb05 JMP 0x006606e3
    goto L006606e3;
  }
  L006606de: { // 0x6606de: b890eba900 MOV EAX,0xa9eb90
    s.ax = 0x00a9eb90u;
  }
  L006606e3: { // 0x6606e3: 8b4c2434 MOV ECX,dword ptr [ESP + 0x34]
    s.cx = m.r32((f.sp+0x00000034u));
  }
  L006606e7: { // 0x6606e7: 8b18 MOV EBX,dword ptr [EAX]
    s.bx = m.r32((s.ax));
  }
  L006606e9: { // 0x6606e9: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L006606eb: { // 0x6606eb: 891a MOV dword ptr [EDX],EBX
    m.w32((s.dx), s.bx);
  }
  L006606ed: { // 0x6606ed: 8b5804 MOV EBX,dword ptr [EAX + 0x4]
    s.bx = m.r32((s.ax+0x00000004u));
  }
  L006606f0: { // 0x6606f0: 895a04 MOV dword ptr [EDX + 0x4],EBX
    m.w32((s.dx+0x00000004u), s.bx);
  }
  L006606f3: { // 0x6606f3: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L006606f6: { // 0x6606f6: 894208 MOV dword ptr [EDX + 0x8],EAX
    m.w32((s.dx+0x00000008u), s.ax);
  }
  L006606f9: { // 0x6606f9: a1ac1c8200 MOV EAX,[0x00821cac]
    s.ax = m.r32((0x00821cacu));
  }
  L006606fe: { // 0x6606fe: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00660700: { // 0x660700: 0f84f6010000 JZ 0x006608fc
    if(integer::condition("JZ",flags)) goto L006608fc;
  }
  L00660706: { // 0x660706: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00660707: { // 0x660707: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0066070c: { // 0x66070c: e87f78eeff CALL 0x00547f90
    s.arithmetic_flags=flags; invoke(m,s,f,0x00547f90u,6686481u); flags=s.arithmetic_flags;
  }
  L00660711: { // 0x660711: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00660713: { // 0x660713: 0f84e3010000 JZ 0x006608fc
    if(integer::condition("JZ",flags)) goto L006608fc;
  }
  L00660719: { // 0x660719: 0fbf0e MOVSX ECX,word ptr [ESI]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.si)),16));
  }
  L0066071c: { // 0x66071c: 0fbf5602 MOVSX EDX,word ptr [ESI + 0x2]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000002u)),16));
  }
  L00660720: { // 0x660720: c1e108 SHL ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::left);
  }
  L00660723: { // 0x660723: 81c180000000 ADD ECX,0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L00660729: { // 0x660729: 8d44241c LEA EAX,[ESP + 0x1c]
    s.ax = (f.sp+0x0000001cu);
  }
  L0066072d: { // 0x66072d: c1e208 SHL EDX,0x8
    s.dx = integer::shift(s.dx,0x00000008u,32,flags,integer::Shift::left);
  }
  L00660730: { // 0x660730: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L00660734: { // 0x660734: 81c280000000 ADD EDX,0x80
    s.dx = integer::add(s.dx,0x00000080u,32,flags);
  }
  L0066073a: { // 0x66073a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0066073b: { // 0x66073b: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00660740: { // 0x660740: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L00660744: { // 0x660744: c744242800000000 MOV dword ptr [ESP + 0x28],0x0
    m.w32((f.sp+0x00000028u), 0x00000000u);
  }
  L0066074c: { // 0x66074c: e81f69efff CALL 0x00557070
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557070u,6686545u); flags=s.arithmetic_flags;
  }
  L00660751: { // 0x660751: 0fbf0e MOVSX ECX,word ptr [ESI]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.si)),16));
  }
  L00660754: { // 0x660754: 0fbf5602 MOVSX EDX,word ptr [ESI + 0x2]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000002u)),16));
  }
  L00660758: { // 0x660758: c1e108 SHL ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::left);
  }
  L0066075b: { // 0x66075b: 81c180000000 ADD ECX,0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L00660761: { // 0x660761: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00660765: { // 0x660765: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L00660769: { // 0x660769: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L0066076d: { // 0x66076d: c1e208 SHL EDX,0x8
    s.dx = integer::shift(s.dx,0x00000008u,32,flags,integer::Shift::left);
  }
  L00660770: { // 0x660770: 81c280000000 ADD EDX,0x80
    s.dx = integer::add(s.dx,0x00000080u,32,flags);
  }
  L00660776: { // 0x660776: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00660777: { // 0x660777: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0066077c: { // 0x66077c: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L00660780: { // 0x660780: e8ab47f0ff CALL 0x00564f30
    s.arithmetic_flags=flags; invoke(m,s,f,0x00564f30u,6686597u); flags=s.arithmetic_flags;
  }
  L00660785: { // 0x660785: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00660787: { // 0x660787: 7410 JZ 0x00660799
    if(integer::condition("JZ",flags)) goto L00660799;
  }
  L00660789: { // 0x660789: a150deb000 MOV EAX,[0x00b0de50]
    s.ax = m.r32((0x00b0de50u));
  }
  L0066078e: { // 0x66078e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00660790: { // 0x660790: 7407 JZ 0x00660799
    if(integer::condition("JZ",flags)) goto L00660799;
  }
  L00660792: { // 0x660792: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L00660797: { // 0x660797: eb02 JMP 0x0066079b
    goto L0066079b;
  }
  L00660799: { // 0x660799: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0066079b: { // 0x66079b: 8b742440 MOV ESI,dword ptr [ESP + 0x40]
    s.si = m.r32((f.sp+0x00000040u));
  }
  L0066079f: { // 0x66079f: 8806 MOV byte ptr [ESI],AL
    m.w8((s.si), (s.ax & 0xffu));
  }
  L006607a1: { // 0x6607a1: c60700 MOV byte ptr [EDI],0x0
    m.w8((s.di), 0x00000000u);
  }
  L006607a4: { // 0x6607a4: 8b15c055a200 MOV EDX,dword ptr [0x00a255c0]
    s.dx = m.r32((0x00a255c0u));
  }
  L006607aa: { // 0x6607aa: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L006607ac: { // 0x6607ac: f6c410 TEST AH,0x10
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000010u),8,flags);
  }
  L006607af: { // 0x6607af: 744b JZ 0x006607fc
    if(integer::condition("JZ",flags)) goto L006607fc;
  }
  L006607b1: { // 0x6607b1: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L006607b5: { // 0x6607b5: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006607ba: { // 0x6607ba: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006607bb: { // 0x6607bb: e8d04ceeff CALL 0x00545490
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545490u,6686656u); flags=s.arithmetic_flags;
  }
  L006607c0: { // 0x6607c0: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006607c2: { // 0x6607c2: e8e90be1ff CALL 0x004713b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004713b0u,6686663u); flags=s.arithmetic_flags;
  }
  L006607c7: { // 0x6607c7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006607c9: { // 0x6607c9: 740a JZ 0x006607d5
    if(integer::condition("JZ",flags)) goto L006607d5;
  }
  L006607cb: { // 0x6607cb: 8a88b7050000 MOV CL,byte ptr [EAX + 0x5b7]
    s.cx = with_al(s.cx, m.r8((s.ax+0x000005b7u)));
  }
  L006607d1: { // 0x6607d1: 880f MOV byte ptr [EDI],CL
    m.w8((s.di), (s.cx & 0xffu));
  }
  L006607d3: { // 0x6607d3: eb27 JMP 0x006607fc
    goto L006607fc;
  }
  L006607d5: { // 0x6607d5: 8d542410 LEA EDX,[ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  L006607d9: { // 0x6607d9: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006607de: { // 0x6607de: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006607df: { // 0x6607df: e8cc49f0ff CALL 0x005651b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005651b0u,6686692u); flags=s.arithmetic_flags;
  }
  L006607e4: { // 0x6607e4: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006607e6: { // 0x6607e6: 7410 JZ 0x006607f8
    if(integer::condition("JZ",flags)) goto L006607f8;
  }
  L006607e8: { // 0x6607e8: a150deb000 MOV EAX,[0x00b0de50]
    s.ax = m.r32((0x00b0de50u));
  }
  L006607ed: { // 0x6607ed: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006607ef: { // 0x6607ef: 7407 JZ 0x006607f8
    if(integer::condition("JZ",flags)) goto L006607f8;
  }
  L006607f1: { // 0x6607f1: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L006607f6: { // 0x6607f6: eb02 JMP 0x006607fa
    goto L006607fa;
  }
  L006607f8: { // 0x6607f8: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006607fa: { // 0x6607fa: 8807 MOV byte ptr [EDI],AL
    m.w8((s.di), (s.ax & 0xffu));
  }
  L006607fc: { // 0x6607fc: 803e00 CMP byte ptr [ESI],0x0
    (void)integer::sub(m.r8((s.si)),0x00000000u,8,flags);
  }
  L006607ff: { // 0x6607ff: 0f85eb000000 JNZ 0x006608f0
    if(integer::condition("JNZ",flags)) goto L006608f0;
  }
  L00660805: { // 0x660805: 803f00 CMP byte ptr [EDI],0x0
    (void)integer::sub(m.r8((s.di)),0x00000000u,8,flags);
  }
  L00660808: { // 0x660808: 0f85e2000000 JNZ 0x006608f0
    if(integer::condition("JNZ",flags)) goto L006608f0;
  }
  L0066080e: { // 0x66080e: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L00660814: { // 0x660814: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00660815: { // 0x660815: e8b6f70300 CALL 0x0069ffd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069ffd0u,6686746u); flags=s.arithmetic_flags;
  }
  L0066081a: { // 0x66081a: 8b7c2438 MOV EDI,dword ptr [ESP + 0x38]
    s.di = m.r32((f.sp+0x00000038u));
  }
  L0066081e: { // 0x66081e: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00660820: { // 0x660820: 8907 MOV dword ptr [EDI],EAX
    m.w32((s.di), s.ax);
  }
  L00660822: { // 0x660822: e8f9d3daff CALL 0x0040dc20
    s.arithmetic_flags=flags; invoke(m,s,f,0x0040dc20u,6686759u); flags=s.arithmetic_flags;
  }
  L00660827: { // 0x660827: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00660829: { // 0x660829: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0066082b: { // 0x66082b: 7458 JZ 0x00660885
    if(integer::condition("JZ",flags)) goto L00660885;
  }
  L0066082d: { // 0x66082d: 8a8672030000 MOV AL,byte ptr [ESI + 0x372]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000372u)));
  }
  L00660833: { // 0x660833: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00660835: { // 0x660835: 754e JNZ 0x00660885
    if(integer::condition("JNZ",flags)) goto L00660885;
  }
  L00660837: { // 0x660837: 83beb801000002 CMP dword ptr [ESI + 0x1b8],0x2
    (void)integer::sub(m.r32((s.si+0x000001b8u)),0x00000002u,32,flags);
  }
  L0066083e: { // 0x66083e: 752b JNZ 0x0066086b
    if(integer::condition("JNZ",flags)) goto L0066086b;
  }
  L00660840: { // 0x660840: a1e4e0a100 MOV EAX,[0x00a1e0e4]
    s.ax = m.r32((0x00a1e0e4u));
  }
  L00660845: { // 0x660845: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00660847: { // 0x660847: 8b4830 MOV ECX,dword ptr [EAX + 0x30]
    s.cx = m.r32((s.ax+0x00000030u));
  }
  L0066084a: { // 0x66084a: 8d44241c LEA EAX,[ESP + 0x1c]
    s.ax = (f.sp+0x0000001cu);
  }
  L0066084e: { // 0x66084e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0066084f: { // 0x66084f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00660850: { // 0x660850: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00660852: { // 0x660852: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),6686805u); flags=s.arithmetic_flags;
  }
  L00660855: { // 0x660855: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00660856: { // 0x660856: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0066085b: { // 0x66085b: e8304ceeff CALL 0x00545490
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545490u,6686816u); flags=s.arithmetic_flags;
  }
  L00660860: { // 0x660860: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00660862: { // 0x660862: e879b6e1ff CALL 0x0047bee0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047bee0u,6686823u); flags=s.arithmetic_flags;
  }
  L00660867: { // 0x660867: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00660869: { // 0x660869: 7414 JZ 0x0066087f
    if(integer::condition("JZ",flags)) goto L0066087f;
  }
  L0066086b: { // 0x66086b: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0066086d: { // 0x66086d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0066086f: { // 0x66086f: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),6686837u); flags=s.arithmetic_flags;
  }
  L00660875: { // 0x660875: 8a88a60a0000 MOV CL,byte ptr [EAX + 0xaa6]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000aa6u)));
  }
  L0066087b: { // 0x66087b: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0066087d: { // 0x66087d: 7406 JZ 0x00660885
    if(integer::condition("JZ",flags)) goto L00660885;
  }
  L0066087f: { // 0x66087f: c70700000000 MOV dword ptr [EDI],0x0
    m.w32((s.di), 0x00000000u);
  }
  L00660885: { // 0x660885: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  L00660887: { // 0x660887: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00660889: { // 0x660889: 7465 JZ 0x006608f0
    if(integer::condition("JZ",flags)) goto L006608f0;
  }
  L0066088b: { // 0x66088b: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0066088d: { // 0x66088d: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),6686864u); flags=s.arithmetic_flags;
  }
  L00660890: { // 0x660890: 83f806 CMP EAX,0x6
    (void)integer::sub(s.ax,0x00000006u,32,flags);
  }
  L00660893: { // 0x660893: 755b JNZ 0x006608f0
    if(integer::condition("JNZ",flags)) goto L006608f0;
  }
  L00660895: { // 0x660895: 8b3f MOV EDI,dword ptr [EDI]
    s.di = m.r32((s.di));
  }
  L00660897: { // 0x660897: 8a8772030000 MOV AL,byte ptr [EDI + 0x372]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000372u)));
  }
  L0066089d: { // 0x66089d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0066089f: { // 0x66089f: 754f JNZ 0x006608f0
    if(integer::condition("JNZ",flags)) goto L006608f0;
  }
  L006608a1: { // 0x6608a1: 80bfbd0500000f CMP byte ptr [EDI + 0x5bd],0xf
    (void)integer::sub(m.r8((s.di+0x000005bdu)),0x0000000fu,8,flags);
  }
  L006608a8: { // 0x6608a8: 752c JNZ 0x006608d6
    if(integer::condition("JNZ",flags)) goto L006608d6;
  }
  L006608aa: { // 0x6608aa: 8b0de4e0a100 MOV ECX,dword ptr [0x00a1e0e4]
    s.cx = m.r32((0x00a1e0e4u));
  }
  L006608b0: { // 0x6608b0: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006608b2: { // 0x6608b2: 8b5130 MOV EDX,dword ptr [ECX + 0x30]
    s.dx = m.r32((s.cx+0x00000030u));
  }
  L006608b5: { // 0x6608b5: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L006608b9: { // 0x6608b9: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006608ba: { // 0x6608ba: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006608bb: { // 0x6608bb: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006608bd: { // 0x6608bd: ff5048 CALL dword ptr [EAX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000048u)),6686912u); flags=s.arithmetic_flags;
  }
  L006608c0: { // 0x6608c0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006608c1: { // 0x6608c1: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006608c6: { // 0x6608c6: e8c54beeff CALL 0x00545490
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545490u,6686923u); flags=s.arithmetic_flags;
  }
  L006608cb: { // 0x6608cb: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006608cd: { // 0x6608cd: e80eb6e1ff CALL 0x0047bee0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047bee0u,6686930u); flags=s.arithmetic_flags;
  }
  L006608d2: { // 0x6608d2: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006608d4: { // 0x6608d4: 7410 JZ 0x006608e6
    if(integer::condition("JZ",flags)) goto L006608e6;
  }
  L006608d6: { // 0x6608d6: 8b9718040000 MOV EDX,dword ptr [EDI + 0x418]
    s.dx = m.r32((s.di+0x00000418u));
  }
  L006608dc: { // 0x6608dc: 8a8285130000 MOV AL,byte ptr [EDX + 0x1385]
    s.ax = with_al(s.ax, m.r8((s.dx+0x00001385u)));
  }
  L006608e2: { // 0x6608e2: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006608e4: { // 0x6608e4: 740a JZ 0x006608f0
    if(integer::condition("JZ",flags)) goto L006608f0;
  }
  L006608e6: { // 0x6608e6: 8b442438 MOV EAX,dword ptr [ESP + 0x38]
    s.ax = m.r32((f.sp+0x00000038u));
  }
  L006608ea: { // 0x6608ea: c70000000000 MOV dword ptr [EAX],0x0
    m.w32((s.ax), 0x00000000u);
  }
  L006608f0: { // 0x6608f0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006608f1: { // 0x6608f1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006608f2: { // 0x6608f2: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006608f3: { // 0x6608f3: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006608f5: { // 0x6608f5: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006608f6: { // 0x6608f6: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L006608f9: { // 0x6608f9: c21800 RET 0x18
    s.arithmetic_flags=flags; finish(m,s,f,24u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006608fc: { // 0x6608fc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006608fd: { // 0x6608fd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006608fe: { // 0x6608fe: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006608ff: { // 0x6608ff: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00660901: { // 0x660901: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00660902: { // 0x660902: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L00660905: { // 0x660905: c21800 RET 0x18
    s.arithmetic_flags=flags; finish(m,s,f,24u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
