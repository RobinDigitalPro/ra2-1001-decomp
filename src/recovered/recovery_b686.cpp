#include "recovered/recovery_b686_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b686 {
namespace {
void f_002b6910(Memory&,State&,Frame&,const Operations&);
void f_000538b0(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void f_00058600(Memory&,State&,Frame&,const Operations&);
void f_002d3790(Memory&,State&,Frame&,const Operations&);
void f_002c2be0(Memory&,State&,Frame&,const Operations&);
void f_002cdb10(Memory&,State&,Frame&,const Operations&);
void f_0004d670(Memory&,State&,Frame&,const Operations&);
void f_002d4b30(Memory&,State&,Frame&,const Operations&);
void f_002d4bf0(Memory&,State&,Frame&,const Operations&);
void f_002d0490(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_002b6910(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006b6910: { // 0x6b6910: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006b6912: { if(m.r32(s.ax+0x84)!=0x4538b0)throw std::domain_error("686 unprovedtype tail");s.arithmetic_flags=flags;f_000538b0(m,s,f,op);return;
  }
}
void f_000538b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004538b0: { // 0x4538b0: 8b8118040000 MOV EAX, dword ptr [ECX + 0x418]
    s.ax = m.r32((s.cx+0x00000418u));
  }
  L004538b6: { // 0x4538b6: c3 RET
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
void f_00058600(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00458600: { // 0x458600: 8b81780c0000 MOV EAX, dword ptr [ECX + 0xc78]
    s.ax = m.r32((s.cx+0x00000c78u));
  }
  L00458606: { // 0x458606: 8b048508ac7b00 MOV EAX, dword ptr [EAX*4 + 0x7bac08]
    s.ax = m.r32(((s.ax * 4u)+0x007bac08u));
  }
  L0045860d: { // 0x45860d: 8d0440 LEA EAX, [EAX + EAX*2]
    s.ax = (s.ax+(s.ax * 2u));
  }
  L00458610: { // 0x458610: 8d0480 LEA EAX, [EAX + EAX*4]
    s.ax = (s.ax+(s.ax * 4u));
  }
  L00458613: { // 0x458613: c1e002 SHL EAX, 2
    s.ax = integer::shift(s.ax,2u,32,flags,integer::Shift::left);
  }
  L00458616: { // 0x458616: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00458617: { // 0x458617: 83e207 AND EDX, 7
    s.dx = integer::logical((s.dx)&(7u),32,flags);
  }
  L0045861a: { // 0x45861a: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0045861c: { // 0x45861c: 8b91a4030000 MOV EDX, dword ptr [ECX + 0x3a4]
    s.dx = m.r32((s.cx+0x000003a4u));
  }
  L00458622: { // 0x458622: c1f803 SAR EAX, 3
    s.ax = integer::shift(s.ax,3u,32,flags,integer::Shift::arithmetic_right);
  }
  L00458625: { // 0x458625: 83ea02 SUB EDX, 2
    s.dx = integer::sub(s.dx,2u,32,flags);
  }
  L00458628: { // 0x458628: 740a JZ 0x458634
    if(integer::condition("JZ",flags)) goto L00458634;
  }
  L0045862a: { // 0x45862a: 83ea02 SUB EDX, 2
    s.dx = integer::sub(s.dx,2u,32,flags);
  }
  L0045862d: { // 0x45862d: 743c JZ 0x45866b
    if(integer::condition("JZ",flags)) goto L0045866b;
  }
  L0045862f: { s.arithmetic_flags=flags;f_002d3790(m,s,f,op);return;
  }
  L00458634: { // 0x458634: 8a9156130000 MOV DL, byte ptr [ECX + 0x1356]
    s.dx = with_al(s.dx, m.r8((s.cx+0x00001356u)));
  }
  L0045863a: { // 0x45863a: 84d2 TEST DL, DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L0045863c: { // 0x45863c: 741a JZ 0x458658
    if(integer::condition("JZ",flags)) goto L00458658;
  }
  L0045863e: { // 0x45863e: 8b0d881b8200 MOV ECX, dword ptr [0x821b88]
    s.cx = m.r32((0x00821b88u));
  }
  L00458644: { // 0x458644: 8b8910140000 MOV ECX, dword ptr [ECX + 0x1410]
    s.cx = m.r32((s.cx+0x00001410u));
  }
  L0045864a: { // 0x45864a: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0045864c: { // 0x45864c: 7d03 JGE 0x458651
    if(integer::condition("JGE",flags)) goto L00458651;
  }
  L0045864e: { // 0x45864e: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00458650: { // 0x458650: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00458651: { // 0x458651: 3bc8 CMP ECX, EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00458653: { // 0x458653: 7f16 JG 0x45866b
    if(integer::condition("JG",flags)) goto L0045866b;
  }
  L00458655: { // 0x458655: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L00458657: { // 0x458657: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00458658: { // 0x458658: 8b89fc060000 MOV ECX, dword ptr [ECX + 0x6fc]
    s.cx = m.r32((s.cx+0x000006fcu));
  }
  L0045865e: { // 0x45865e: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00458660: { // 0x458660: 7d03 JGE 0x458665
    if(integer::condition("JGE",flags)) goto L00458665;
  }
  L00458662: { // 0x458662: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00458664: { // 0x458664: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00458665: { // 0x458665: 3bc8 CMP ECX, EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00458667: { // 0x458667: 7f02 JG 0x45866b
    if(integer::condition("JG",flags)) goto L0045866b;
  }
  L00458669: { // 0x458669: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L0045866b: { // 0x45866b: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002d3790(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006d3790: { // 0x6d3790: 8b81a4030000 MOV EAX, dword ptr [ECX + 0x3a4]
    s.ax = m.r32((s.cx+0x000003a4u));
  }
  L006d3796: { // 0x6d3796: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L006d3797: { // 0x6d3797: 83f803 CMP EAX, 3
    (void)integer::sub(s.ax,3u,32,flags);
  }
  L006d379a: { // 0x6d379a: 7721 JA 0x6d37bd
    if(integer::condition("JA",flags)) goto L006d37bd;
  }
  L006d379c: { // Original read-only jump table; same frame
 switch(s.ax){case 0:goto L006d37a9;case 1:goto L006d37b0;case 2:goto L006d37b6;case 3:goto L006d37a3;default:throw std::domain_error("686 capacity jump target");}
  }
  L006d37a3: { // 0x6d37a3: b80a000000 MOV EAX, 0xa
    s.ax = 0x0000000au;
  }
  L006d37a8: { // 0x6d37a8: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L006d37a9: { // 0x6d37a9: 8b81ac050000 MOV EAX, dword ptr [ECX + 0x5ac]
    s.ax = m.r32((s.cx+0x000005acu));
  }
  L006d37af: { // 0x6d37af: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L006d37b0: { // 0x6d37b0: b805000000 MOV EAX, 5
    s.ax = 5u;
  }
  L006d37b5: { // 0x6d37b5: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L006d37b6: { // 0x6d37b6: 8b812c050000 MOV EAX, dword ptr [ECX + 0x52c]
    s.ax = m.r32((s.cx+0x0000052cu));
  }
  L006d37bc: { // 0x6d37bc: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L006d37bd: { // 0x6d37bd: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006d37bf: { // 0x6d37bf: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_002c2be0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006c2be0: { // 0x6c2be0: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006c2be2: { // 0x6c2be2: ff9098030000 CALL dword ptr [EAX + 0x398]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000398u)),7089128u); flags=s.arithmetic_flags;
  }
  L006c2be8: { // 0x6c2be8: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006c2bea: { // 0x6c2bea: 740b JZ 0x6c2bf7
    if(integer::condition("JZ",flags)) goto L006c2bf7;
  }
  L006c2bec: { // 0x6c2bec: 833800 CMP dword ptr [EAX], 0
    (void)integer::sub(m.r32((s.ax)),0u,32,flags);
  }
  L006c2bef: { // 0x6c2bef: 7406 JZ 0x6c2bf7
    if(integer::condition("JZ",flags)) goto L006c2bf7;
  }
  L006c2bf1: { // 0x6c2bf1: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L006c2bf6: { // 0x6c2bf6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L006c2bf7: { // 0x6c2bf7: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006c2bf9: { // 0x6c2bf9: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002cdb10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006cdb10: { // 0x6cdb10: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006cdb11: { // 0x6cdb11: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L006cdb13: { // 0x6cdb13: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006cdb15: { // 0x6cdb15: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7133979u); flags=s.arithmetic_flags;
  }
  L006cdb1b: { // 0x6cdb1b: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L006cdb1d: { // 0x6cdb1d: e8ce700000 CALL 0x6d4bf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d4bf0u,7133986u); flags=s.arithmetic_flags;
  }
  L006cdb22: { // 0x6cdb22: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006cdb24: { // 0x6cdb24: 7413 JZ 0x6cdb39
    if(integer::condition("JZ",flags)) goto L006cdb39;
  }
  L006cdb26: { // 0x6cdb26: 8b860c010000 MOV EAX, dword ptr [ESI + 0x10c]
    s.ax = m.r32((s.si+0x0000010cu));
  }
  L006cdb2c: { // 0x6cdb2c: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006cdb2e: { // 0x6cdb2e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006cdb2f: { // 0x6cdb2f: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006cdb31: { // 0x6cdb31: ff929c030000 CALL dword ptr [EDX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000039cu)),7134007u); flags=s.arithmetic_flags;
  }
  L006cdb37: { // 0x6cdb37: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006cdb38: { // 0x6cdb38: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L006cdb39: { // 0x6cdb39: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006cdb3b: { // 0x6cdb3b: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006cdb3d: { // 0x6cdb3d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006cdb3e: { // 0x6cdb3e: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006cdb40: { // 0x6cdb40: ff929c030000 CALL dword ptr [EDX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000039cu)),7134022u); flags=s.arithmetic_flags;
  }
  L006cdb46: { // 0x6cdb46: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006cdb47: { // 0x6cdb47: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0004d670(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0044d670: { // 0x44d670: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0044d671: { // 0x44d671: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0044d672: { // 0x44d672: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0044d673: { // 0x44d673: 8b6c2410 MOV EBP, dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L0044d677: { // 0x44d677: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0044d678: { // 0x44d678: 8bf9 MOV EDI, ECX
    s.di = s.cx;
  }
  L0044d67a: { // 0x44d67a: 8a87c6050000 MOV AL, byte ptr [EDI + 0x5c6]
    s.ax = with_al(s.ax, m.r8((s.di+0x000005c6u)));
  }
  L0044d680: { // 0x44d680: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044d682: { // 0x44d682: 742c JZ 0x44d6b0
    if(integer::condition("JZ",flags)) goto L0044d6b0;
  }
  L0044d684: { // 0x44d684: 33db XOR EBX, EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0044d686: { // 0x44d686: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044d688: { // 0x44d688: 7e26 JLE 0x44d6b0
    if(integer::condition("JLE",flags)) goto L0044d6b0;
  }
  L0044d68a: { // 0x44d68a: 8db7c0040000 LEA ESI, [EDI + 0x4c0]
    s.si = (s.di+0x000004c0u);
  }
  L0044d690: { // 0x44d690: 8b0e MOV ECX, dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0044d692: { // 0x44d692: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0044d694: { // 0x44d694: 740b JZ 0x44d6a1
    if(integer::condition("JZ",flags)) goto L0044d6a1;
  }
  L0044d696: { // 0x44d696: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0044d697: { // 0x44d697: e894742800 CALL 0x6d4b30
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d4b30u,4511388u); flags=s.arithmetic_flags;
  }
  L0044d69c: { // 0x44d69c: 833800 CMP dword ptr [EAX], 0
    (void)integer::sub(m.r32((s.ax)),0u,32,flags);
  }
  L0044d69f: { // 0x44d69f: 7517 JNZ 0x44d6b8
    if(integer::condition("JNZ",flags)) goto L0044d6b8;
  }
  L0044d6a1: { // 0x44d6a1: 0fbe87c6050000 MOVSX EAX, byte ptr [EDI + 0x5c6]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.di+0x000005c6u)),8));
  }
  L0044d6a8: { // 0x44d6a8: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L0044d6a9: { // 0x44d6a9: 83c604 ADD ESI, 4
    s.si = integer::add(s.si,4u,32,flags);
  }
  L0044d6ac: { // 0x44d6ac: 3bd8 CMP EBX, EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L0044d6ae: { // 0x44d6ae: 7ce0 JL 0x44d690
    if(integer::condition("JL",flags)) goto L0044d690;
  }
  L0044d6b0: { // 0x44d6b0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0044d6b1: { // 0x44d6b1: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L0044d6b3: { // 0x44d6b3: e8f8032800 CALL 0x6cdab0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006cdab0u,4511416u); flags=s.arithmetic_flags;
  }
  L0044d6b8: { // 0x44d6b8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0044d6b9: { // 0x44d6b9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0044d6ba: { // 0x44d6ba: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0044d6bb: { // 0x44d6bb: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0044d6bc: { // 0x44d6bc: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_002d4b30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006d4b30: { // 0x6d4b30: 8b442404 MOV EAX, dword ptr [ESP + 4]
    s.ax = m.r32((f.sp+4u));
  }
  L006d4b34: { // 0x6d4b34: 8d14c500000000 LEA EDX, [EAX*8]
    s.dx = ((s.ax * 8u));
  }
  L006d4b3b: { // 0x6d4b3b: 2bd0 SUB EDX, EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L006d4b3d: { // 0x6d4b3d: 8d84914c070000 LEA EAX, [ECX + EDX*4 + 0x74c]
    s.ax = (s.cx+(s.dx * 4u)+0x0000074cu);
  }
  L006d4b44: { // 0x6d4b44: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_002d4bf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006d4bf0: { // 0x6d4bf0: 8b9104070000 MOV EDX, dword ptr [ECX + 0x704]
    s.dx = m.r32((s.cx+0x00000704u));
  }
  L006d4bf6: { // 0x6d4bf6: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006d4bf8: { // 0x6d4bf8: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L006d4bfa: { // 0x6d4bfa: 0f9fc0 SETG AL
    s.ax = with_al(s.ax, (integer::condition("JG",flags)?1u:0u));
  }
  L006d4bfd: { // 0x6d4bfd: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002d0490(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006d0490: { // 0x6d0490: 8b914c070000 MOV EDX, dword ptr [ECX + 0x74c]
    s.dx = m.r32((s.cx+0x0000074cu));
  }
  L006d0496: { // 0x6d0496: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L006d0498: { // 0x6d0498: 7427 JZ 0x6d04c1
    if(integer::condition("JZ",flags)) goto L006d04c1;
  }
  L006d049a: { // 0x6d049a: 8b8968070000 MOV ECX, dword ptr [ECX + 0x768]
    s.cx = m.r32((s.cx+0x00000768u));
  }
  L006d04a0: { // 0x6d04a0: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L006d04a5: { // 0x6d04a5: 3bd1 CMP EDX, ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L006d04a7: { // 0x6d04a7: 741a JZ 0x6d04c3
    if(integer::condition("JZ",flags)) goto L006d04c3;
  }
  L006d04a9: { // 0x6d04a9: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006d04aa: { // 0x6d04aa: 8bb29c000000 MOV ESI, dword ptr [EDX + 0x9c]
    s.si = m.r32((s.dx+0x0000009cu));
  }
  L006d04b0: { // 0x6d04b0: 3bf0 CMP ESI, EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L006d04b2: { // 0x6d04b2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006d04b3: { // 0x6d04b3: 7f0e JG 0x6d04c3
    if(integer::condition("JG",flags)) goto L006d04c3;
  }
  L006d04b5: { // 0x6d04b5: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006d04b7: { // 0x6d04b7: 7408 JZ 0x6d04c1
    if(integer::condition("JZ",flags)) goto L006d04c1;
  }
  L006d04b9: { // 0x6d04b9: 39819c000000 CMP dword ptr [ECX + 0x9c], EAX
    (void)integer::sub(m.r32((s.cx+0x0000009cu)),s.ax,32,flags);
  }
  L006d04bf: { // 0x6d04bf: 7f02 JG 0x6d04c3
    if(integer::condition("JG",flags)) goto L006d04c3;
  }
  L006d04c1: { // 0x6d04c1: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006d04c3: { // 0x6d04c3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 7039248u:f_002b6910(m,s,child,{});break;
case 4536496u:f_000538b0(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
case 4556288u:f_00058600(m,s,child,{});break;
case 7157648u:f_002d3790(m,s,child,{});break;
case 7089120u:f_002c2be0(m,s,child,{});break;
case 7133968u:f_002cdb10(m,s,child,{});break;
case 4511344u:f_0004d670(m,s,child,{});break;
case 7162672u:f_002d4b30(m,s,child,{});break;
case 7162864u:f_002d4bf0(m,s,child,{});break;
case 7144592u:f_002d0490(m,s,child,{});break;
default:throw std::domain_error("recovery686 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_006c9440(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006c9440: { // 0x6c9440: 83ec14 SUB ESP,0x14
    f.sp = integer::sub(f.sp,0x00000014u,32,flags);
  }
  L006c9443: { // 0x6c9443: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006c9444: { // 0x6c9444: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006c9446: { // 0x6c9446: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006c9448: { // 0x6c9448: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7115854u); flags=s.arithmetic_flags;
  }
  L006c944e: { // 0x6c944e: 8b80a4030000 MOV EAX,dword ptr [EAX + 0x3a4]
    s.ax = m.r32((s.ax+0x000003a4u));
  }
  L006c9454: { // 0x6c9454: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L006c9455: { // 0x6c9455: 7428 JZ 0x006c947f
    if(integer::condition("JZ",flags)) goto L006c947f;
  }
  L006c9457: { // 0x6c9457: 83e802 SUB EAX,0x2
    s.ax = integer::sub(s.ax,0x00000002u,32,flags);
  }
  L006c945a: { // 0x6c945a: 7407 JZ 0x006c9463
    if(integer::condition("JZ",flags)) goto L006c9463;
  }
  L006c945c: { // 0x6c945c: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006c945e: { // 0x6c945e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c945f: { // 0x6c945f: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L006c9462: { // 0x6c9462: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006c9463: { // 0x6c9463: db86f8000000 FILD dword ptr [ESI + 0xf8]
    const auto address=(s.si+0x000000f8u);
    s.fp.load_integer32(m.r32(address));
  }
  L006c9469: { // 0x6c9469: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006c946b: { // 0x6c946b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c946d: { // 0x6c946d: dd5c2408 FSTP double ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L006c9471: { // 0x6c9471: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7115895u); flags=s.arithmetic_flags;
  }
  L006c9477: { // 0x6c9477: db802c050000 FILD dword ptr [EAX + 0x52c]
    const auto address=(s.ax+0x0000052cu);
    s.fp.load_integer32(m.r32(address));
  }
  L006c947d: { // 0x6c947d: eb1a JMP 0x006c9499
    goto L006c9499;
  }
  L006c947f: { // 0x6c947f: db8654020000 FILD dword ptr [ESI + 0x254]
    const auto address=(s.si+0x00000254u);
    s.fp.load_integer32(m.r32(address));
  }
  L006c9485: { // 0x6c9485: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006c9487: { // 0x6c9487: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c9489: { // 0x6c9489: dd5c2408 FSTP double ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L006c948d: { // 0x6c948d: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7115923u); flags=s.arithmetic_flags;
  }
  L006c9493: { // 0x6c9493: db80ac050000 FILD dword ptr [EAX + 0x5ac]
    const auto address=(s.ax+0x000005acu);
    s.fp.load_integer32(m.r32(address));
  }
  L006c9499: { // 0x6c9499: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006c949b: { // 0x6c949b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c949d: { // 0x6c949d: dd5c2410 FSTP double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L006c94a1: { // 0x6c94a1: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7115943u); flags=s.arithmetic_flags;
  }
  L006c94a7: { // 0x6c94a7: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L006c94a9: { // 0x6c94a9: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006c94ab: { // 0x6c94ab: ff5274 CALL dword ptr [EDX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000074u)),7115950u); flags=s.arithmetic_flags;
  }
  L006c94ae: { // 0x6c94ae: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  L006c94b2: { // 0x6c94b2: db442404 FILD dword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load_integer32(m.r32(address));
  }
  L006c94b6: { // 0x6c94b6: dd442408 FLD double ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.load64(read64(m,address));
  }
  L006c94ba: { // 0x6c94ba: dc742410 FDIV double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.divide64(read64(m,address));
  }
  L006c94be: { // 0x6c94be: dec9 FMULP
    numeric_b88::detail::reg<0xdec9>(s.fp);
  }
  L006c94c0: { // 0x6c94c0: dc0528577800 FADD double ptr [0x00785728]
    const auto address=(0x00785728u);
    s.fp.add64(read64(m,address));
  }
  L006c94c6: { // 0x6c94c6: e885150a00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7115979u); flags=s.arithmetic_flags;
  }
  L006c94cb: { // 0x6c94cb: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006c94cd: { // 0x6c94cd: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006c94cf: { // 0x6c94cf: 7516 JNZ 0x006c94e7
    if(integer::condition("JNZ",flags)) goto L006c94e7;
  }
  L006c94d1: { // 0x6c94d1: dd442408 FLD double ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.load64(read64(m,address));
  }
  L006c94d5: { // 0x6c94d5: dc1d10667800 FCOMP double ptr [0x00786610]
    const auto address=(0x00786610u);
    s.fp.compare_pop64(read64(m,address));
  }
  L006c94db: { // 0x6c94db: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L006c94dd: { // 0x6c94dd: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L006c94e0: { // 0x6c94e0: 7505 JNZ 0x006c94e7
    if(integer::condition("JNZ",flags)) goto L006c94e7;
  }
  L006c94e2: { // 0x6c94e2: b901000000 MOV ECX,0x1
    s.cx = 0x00000001u;
  }
  L006c94e7: { // 0x6c94e7: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L006c94e9: { // 0x6c94e9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c94ea: { // 0x6c94ea: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L006c94ed: { // 0x6c94ed: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_006cade0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006cade0: { // 0x6cade0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006cade1: { // 0x6cade1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006cade3: { // 0x6cade3: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006cade5: { // 0x6cade5: ff908c020000 CALL dword ptr [EAX + 0x28c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000028cu)),7122411u); flags=s.arithmetic_flags;
  }
  L006cadeb: { // 0x6cadeb: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006caded: { // 0x6caded: 746f JZ 0x006cae5e
    if(integer::condition("JZ",flags)) goto L006cae5e;
  }
  L006cadef: { // 0x6cadef: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006cadf1: { // 0x6cadf1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006cadf3: { // 0x6cadf3: ff9298030000 CALL dword ptr [EDX + 0x398]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000398u)),7122425u); flags=s.arithmetic_flags;
  }
  L006cadf9: { // 0x6cadf9: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L006cadfb: { // 0x6cadfb: 8b88a0000000 MOV ECX,dword ptr [EAX + 0xa0]
    s.cx = m.r32((s.ax+0x000000a0u));
  }
  L006cae01: { // 0x6cae01: 8a9174020000 MOV DL,byte ptr [ECX + 0x274]
    s.dx = with_al(s.dx, m.r8((s.cx+0x00000274u)));
  }
  L006cae07: { // 0x6cae07: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L006cae09: { // 0x6cae09: 7453 JZ 0x006cae5e
    if(integer::condition("JZ",flags)) goto L006cae5e;
  }
  L006cae0b: { // 0x6cae0b: db80a4000000 FILD dword ptr [EAX + 0xa4]
    const auto address=(s.ax+0x000000a4u);
    s.fp.load_integer32(m.r32(address));
  }
  L006cae11: { // 0x6cae11: 8b90ac000000 MOV EDX,dword ptr [EAX + 0xac]
    s.dx = m.r32((s.ax+0x000000acu));
  }
  L006cae17: { // 0x6cae17: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cae18: { // 0x6cae18: dc8ab8000000 FMUL double ptr [EDX + 0xb8]
    const auto address=(s.dx+0x000000b8u);
    s.fp.multiply64(read64(m,address));
  }
  L006cae1e: { // 0x6cae1e: da88b4000000 FIMUL dword ptr [EAX + 0xb4]
    const auto operand=m.r32((s.ax+0x000000b4u));
    ra2::platform::x87::Image host;
    asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\tfimull %[operand]\n\tfnsave %[guest]\n\tfrstor %[host]" : [host]"=m"(host.bytes),[guest]"+m"(s.fp.image.bytes) : [operand]"m"(operand) : "memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");
  }
  L006cae24: { // 0x6cae24: dab0b0000000 FIDIV dword ptr [EAX + 0xb0]
    const auto address=(s.ax+0x000000b0u);
    s.fp.divide_integer32(m.r32(address));
  }
  L006cae2a: { // 0x6cae2a: e821fc0900 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7122479u); flags=s.arithmetic_flags;
  }
  L006cae2f: { // 0x6cae2f: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L006cae31: { // 0x6cae31: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006cae33: { // 0x6cae33: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006cae35: { // 0x6cae35: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7122491u); flags=s.arithmetic_flags;
  }
  L006cae3b: { // 0x6cae3b: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006cae3d: { // 0x6cae3d: e84e560000 CALL 0x006d0490
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d0490u,7122498u); flags=s.arithmetic_flags;
  }
  L006cae42: { // 0x6cae42: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006cae44: { // 0x6cae44: 7402 JZ 0x006cae48
    if(integer::condition("JZ",flags)) goto L006cae48;
  }
  L006cae46: { // 0x6cae46: 03ff ADD EDI,EDI
    s.di = integer::add(s.di,s.di,32,flags);
  }
  L006cae48: { // 0x6cae48: b81f85eb51 MOV EAX,0x51eb851f
    s.ax = 0x51eb851fu;
  }
  L006cae4d: { // 0x6cae4d: f7ef IMUL EDI
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.di,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  L006cae4f: { // 0x6cae4f: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L006cae51: { // 0x6cae51: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006cae52: { // 0x6cae52: c1f804 SAR EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::arithmetic_right);
  }
  L006cae55: { // 0x6cae55: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006cae57: { // 0x6cae57: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006cae58: { // 0x6cae58: c1e91f SHR ECX,0x1f
    s.cx = integer::shift(s.cx,0x0000001fu,32,flags,integer::Shift::right);
  }
  L006cae5b: { // 0x6cae5b: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L006cae5d: { // 0x6cae5d: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006cae5e: { // 0x6cae5e: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006cae60: { // 0x6cae60: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006cae61: { // 0x6cae61: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
