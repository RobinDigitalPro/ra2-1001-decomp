#include "recovered/recovery_b633_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b633 {
namespace {
void f_002cf0b0(Memory&,State&,Frame&,const Operations&);
void f_0000ff10(Memory&,State&,Frame&,const Operations&);
void f_0000ffd0(Memory&,State&,Frame&,const Operations&);
void f_00010580(Memory&,State&,Frame&,const Operations&);
void f_00054750(Memory&,State&,Frame&,const Operations&);
void f_0006c880(Memory&,State&,Frame&,const Operations&);
void f_0006cc20(Memory&,State&,Frame&,const Operations&);
void f_000f6100(Memory&,State&,Frame&,const Operations&);
void f_000f7ea0(Memory&,State&,Frame&,const Operations&);
void f_0010a560(Memory&,State&,Frame&,const Operations&);
void f_0010acb0(Memory&,State&,Frame&,const Operations&);
void f_001cde80(Memory&,State&,Frame&,const Operations&);
void f_00249b90(Memory&,State&,Frame&,const Operations&);
void f_0024ba00(Memory&,State&,Frame&,const Operations&);
void f_0036dd10(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_002cf0b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006cf0b0: { // 0x6cf0b0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006cf0b1: { // 0x6cf0b1: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L006cf0b3: { // 0x6cf0b3: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L006cf0b6: { // 0x6cf0b6: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006cf0b7: { // 0x6cf0b7: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L006cf0ba: { // 0x6cf0ba: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cf0bb: { // 0x6cf0bb: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006cf0bc: { // 0x6cf0bc: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cf0bd: { // 0x6cf0bd: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006cf0bf: { // 0x6cf0bf: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006cf0c0: { // 0x6cf0c0: e8bbedefff CALL 0x005cde80
    s.arithmetic_flags=flags; invoke(m,s,f,0x005cde80u,7139525u); flags=s.arithmetic_flags;
  }
  L006cf0c5: { // 0x6cf0c5: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L006cf0c7: { // 0x6cf0c7: c7866402000001000000 MOV dword ptr [ESI + 0x264],0x1
    m.w32((s.si+0x00000264u), 0x00000001u);
  }
  L006cf0d1: { // 0x6cf0d1: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L006cf0d3: { // 0x6cf0d3: 899e68020000 MOV dword ptr [ESI + 0x268],EBX
    m.w32((s.si+0x00000268u), s.bx);
  }
  L006cf0d9: { // 0x6cf0d9: 898e6c020000 MOV dword ptr [ESI + 0x26c],ECX
    m.w32((s.si+0x0000026cu), s.cx);
  }
  L006cf0df: { // 0x6cf0df: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L006cf0e1: { // 0x6cf0e1: 898e70020000 MOV dword ptr [ESI + 0x270],ECX
    m.w32((s.si+0x00000270u), s.cx);
  }
  L006cf0e7: { // 0x6cf0e7: 8dbee4020000 LEA EDI,[ESI + 0x2e4]
    s.di = (s.si+0x000002e4u);
  }
  L006cf0ed: { // 0x6cf0ed: 898e74020000 MOV dword ptr [ESI + 0x274],ECX
    m.w32((s.si+0x00000274u), s.cx);
  }
  L006cf0f3: { // 0x6cf0f3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cf0f4: { // 0x6cf0f4: 898e78020000 MOV dword ptr [ESI + 0x278],ECX
    m.w32((s.si+0x00000278u), s.cx);
  }
  L006cf0fa: { // 0x6cf0fa: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cf0fb: { // 0x6cf0fb: 66898e7c020000 MOV word ptr [ESI + 0x27c],CX
    m.w16((s.si+0x0000027cu), (s.cx & 0xffffu));
  }
  L006cf102: { // 0x6cf102: 89967e020000 MOV dword ptr [ESI + 0x27e],EDX
    m.w32((s.si+0x0000027eu), s.dx);
  }
  L006cf108: { // 0x6cf108: 899682020000 MOV dword ptr [ESI + 0x282],EDX
    m.w32((s.si+0x00000282u), s.dx);
  }
  L006cf10e: { // 0x6cf10e: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006cf110: { // 0x6cf110: 899686020000 MOV dword ptr [ESI + 0x286],EDX
    m.w32((s.si+0x00000286u), s.dx);
  }
  L006cf116: { // 0x6cf116: 89968a020000 MOV dword ptr [ESI + 0x28a],EDX
    m.w32((s.si+0x0000028au), s.dx);
  }
  L006cf11c: { // 0x6cf11c: 6689968e020000 MOV word ptr [ESI + 0x28e],DX
    m.w16((s.si+0x0000028eu), (s.dx & 0xffffu));
  }
  L006cf123: { // 0x6cf123: 899e90020000 MOV dword ptr [ESI + 0x290],EBX
    m.w32((s.si+0x00000290u), s.bx);
  }
  L006cf129: { // 0x6cf129: 899e94020000 MOV dword ptr [ESI + 0x294],EBX
    m.w32((s.si+0x00000294u), s.bx);
  }
  L006cf12f: { // 0x6cf12f: 899e98020000 MOV dword ptr [ESI + 0x298],EBX
    m.w32((s.si+0x00000298u), s.bx);
  }
  L006cf135: { // 0x6cf135: 899e9c020000 MOV dword ptr [ESI + 0x29c],EBX
    m.w32((s.si+0x0000029cu), s.bx);
  }
  L006cf13b: { // 0x6cf13b: 899ea0020000 MOV dword ptr [ESI + 0x2a0],EBX
    m.w32((s.si+0x000002a0u), s.bx);
  }
  L006cf141: { // 0x6cf141: 899ea4020000 MOV dword ptr [ESI + 0x2a4],EBX
    m.w32((s.si+0x000002a4u), s.bx);
  }
  L006cf147: { // 0x6cf147: 899ea8020000 MOV dword ptr [ESI + 0x2a8],EBX
    m.w32((s.si+0x000002a8u), s.bx);
  }
  L006cf14d: { // 0x6cf14d: 899eac020000 MOV dword ptr [ESI + 0x2ac],EBX
    m.w32((s.si+0x000002acu), s.bx);
  }
  L006cf153: { // 0x6cf153: 899eb0020000 MOV dword ptr [ESI + 0x2b0],EBX
    m.w32((s.si+0x000002b0u), s.bx);
  }
  L006cf159: { // 0x6cf159: 899eb4020000 MOV dword ptr [ESI + 0x2b4],EBX
    m.w32((s.si+0x000002b4u), s.bx);
  }
  L006cf15f: { // 0x6cf15f: 899eb8020000 MOV dword ptr [ESI + 0x2b8],EBX
    m.w32((s.si+0x000002b8u), s.bx);
  }
  L006cf165: { // 0x6cf165: 899ebc020000 MOV dword ptr [ESI + 0x2bc],EBX
    m.w32((s.si+0x000002bcu), s.bx);
  }
  L006cf16b: { // 0x6cf16b: 899ec0020000 MOV dword ptr [ESI + 0x2c0],EBX
    m.w32((s.si+0x000002c0u), s.bx);
  }
  L006cf171: { // 0x6cf171: 899ec4020000 MOV dword ptr [ESI + 0x2c4],EBX
    m.w32((s.si+0x000002c4u), s.bx);
  }
  L006cf177: { // 0x6cf177: c786c8020000f4010000 MOV dword ptr [ESI + 0x2c8],0x1f4
    m.w32((s.si+0x000002c8u), 0x000001f4u);
  }
  L006cf181: { // 0x6cf181: c786d0020000fca9f1d2 MOV dword ptr [ESI + 0x2d0],0xd2f1a9fc
    m.w32((s.si+0x000002d0u), 0xd2f1a9fcu);
  }
  L006cf18b: { // 0x6cf18b: c786d40200004d62603f MOV dword ptr [ESI + 0x2d4],0x3f60624d
    m.w32((s.si+0x000002d4u), 0x3f60624du);
  }
  L006cf195: { // 0x6cf195: c786d8020000b81e85eb MOV dword ptr [ESI + 0x2d8],0xeb851eb8
    m.w32((s.si+0x000002d8u), 0xeb851eb8u);
  }
  L006cf19f: { // 0x6cf19f: c786dc02000051b89e3f MOV dword ptr [ESI + 0x2dc],0x3f9eb851
    m.w32((s.si+0x000002dcu), 0x3f9eb851u);
  }
  L006cf1a9: { // 0x6cf1a9: c786e002000007000000 MOV dword ptr [ESI + 0x2e0],0x7
    m.w32((s.si+0x000002e0u), 0x00000007u);
  }
  L006cf1b3: { // 0x6cf1b3: e848c8f7ff CALL 0x0064ba00
    s.arithmetic_flags=flags; invoke(m,s,f,0x0064ba00u,7139768u); flags=s.arithmetic_flags;
  }
  L006cf1b8: { // 0x6cf1b8: c747140a000000 MOV dword ptr [EDI + 0x14],0xa
    m.w32((s.di+0x00000014u), 0x0000000au);
  }
  L006cf1bf: { // 0x6cf1bf: 895f10 MOV dword ptr [EDI + 0x10],EBX
    m.w32((s.di+0x00000010u), s.bx);
  }
  L006cf1c2: { // 0x6cf1c2: c707a03f7900 MOV dword ptr [EDI],0x793fa0
    m.w32((s.di), 0x00793fa0u);
  }
  L006cf1c8: { // 0x6cf1c8: 8dbe00030000 LEA EDI,[ESI + 0x300]
    s.di = (s.si+0x00000300u);
  }
  L006cf1ce: { // 0x6cf1ce: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cf1cf: { // 0x6cf1cf: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cf1d0: { // 0x6cf1d0: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006cf1d2: { // 0x6cf1d2: e849dad9ff CALL 0x0046cc20
    s.arithmetic_flags=flags; invoke(m,s,f,0x0046cc20u,7139799u); flags=s.arithmetic_flags;
  }
  L006cf1d7: { // 0x6cf1d7: c747140a000000 MOV dword ptr [EDI + 0x14],0xa
    m.w32((s.di+0x00000014u), 0x0000000au);
  }
  L006cf1de: { // 0x6cf1de: 895f10 MOV dword ptr [EDI + 0x10],EBX
    m.w32((s.di+0x00000010u), s.bx);
  }
  L006cf1e1: { // 0x6cf1e1: c707f4897800 MOV dword ptr [EDI],0x7889f4
    m.w32((s.di), 0x007889f4u);
  }
  L006cf1e7: { // 0x6cf1e7: 8b0dd0cf7800 MOV ECX,dword ptr [0x0078cfd0]
    s.cx = m.r32((0x0078cfd0u));
  }
  L006cf1ed: { // 0x6cf1ed: 8d861c030000 LEA EAX,[ESI + 0x31c]
    s.ax = (s.si+0x0000031cu);
  }
  L006cf1f3: { // 0x6cf1f3: 898e1c030000 MOV dword ptr [ESI + 0x31c],ECX
    m.w32((s.si+0x0000031cu), s.cx);
  }
  L006cf1f9: { // 0x6cf1f9: 8b15d4cf7800 MOV EDX,dword ptr [0x0078cfd4]
    s.dx = m.r32((0x0078cfd4u));
  }
  L006cf1ff: { // 0x6cf1ff: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
  L006cf202: { // 0x6cf202: 8b0dd8cf7800 MOV ECX,dword ptr [0x0078cfd8]
    s.cx = m.r32((0x0078cfd8u));
  }
  L006cf208: { // 0x6cf208: 894808 MOV dword ptr [EAX + 0x8],ECX
    m.w32((s.ax+0x00000008u), s.cx);
  }
  L006cf20b: { // 0x6cf20b: 8b15dccf7800 MOV EDX,dword ptr [0x0078cfdc]
    s.dx = m.r32((0x0078cfdcu));
  }
  L006cf211: { // 0x6cf211: 89500c MOV dword ptr [EAX + 0xc],EDX
    m.w32((s.ax+0x0000000cu), s.dx);
  }
  L006cf214: { // 0x6cf214: 899e30030000 MOV dword ptr [ESI + 0x330],EBX
    m.w32((s.si+0x00000330u), s.bx);
  }
  L006cf21a: { // 0x6cf21a: 899e34030000 MOV dword ptr [ESI + 0x334],EBX
    m.w32((s.si+0x00000334u), s.bx);
  }
  L006cf220: { // 0x6cf220: 899e38030000 MOV dword ptr [ESI + 0x338],EBX
    m.w32((s.si+0x00000338u), s.bx);
  }
  L006cf226: { // 0x6cf226: 899e3c030000 MOV dword ptr [ESI + 0x33c],EBX
    m.w32((s.si+0x0000033cu), s.bx);
  }
  L006cf22c: { // 0x6cf22c: b80000f03f MOV EAX,0x3ff00000
    s.ax = 0x3ff00000u;
  }
  L006cf231: { // 0x6cf231: 899e40030000 MOV dword ptr [ESI + 0x340],EBX
    m.w32((s.si+0x00000340u), s.bx);
  }
  L006cf237: { // 0x6cf237: 898644030000 MOV dword ptr [ESI + 0x344],EAX
    m.w32((s.si+0x00000344u), s.ax);
  }
  L006cf23d: { // 0x6cf23d: 899e48030000 MOV dword ptr [ESI + 0x348],EBX
    m.w32((s.si+0x00000348u), s.bx);
  }
  L006cf243: { // 0x6cf243: c7864c03000000000040 MOV dword ptr [ESI + 0x34c],0x40000000
    m.w32((s.si+0x0000034cu), 0x40000000u);
  }
  L006cf24d: { // 0x6cf24d: 899e50030000 MOV dword ptr [ESI + 0x350],EBX
    m.w32((s.si+0x00000350u), s.bx);
  }
  L006cf253: { // 0x6cf253: 898654030000 MOV dword ptr [ESI + 0x354],EAX
    m.w32((s.si+0x00000354u), s.ax);
  }
  L006cf259: { // 0x6cf259: 899e58030000 MOV dword ptr [ESI + 0x358],EBX
    m.w32((s.si+0x00000358u), s.bx);
  }
  L006cf25f: { // 0x6cf25f: 899e5c030000 MOV dword ptr [ESI + 0x35c],EBX
    m.w32((s.si+0x0000035cu), s.bx);
  }
  L006cf265: { // 0x6cf265: 889e60030000 MOV byte ptr [ESI + 0x360],BL
    m.w8((s.si+0x00000360u), (s.bx & 0xffu));
  }
  L006cf26b: { // 0x6cf26b: 899e64030000 MOV dword ptr [ESI + 0x364],EBX
    m.w32((s.si+0x00000364u), s.bx);
  }
  L006cf271: { // 0x6cf271: c786680300000f000000 MOV dword ptr [ESI + 0x368],0xf
    m.w32((s.si+0x00000368u), 0x0000000fu);
  }
  L006cf27b: { // 0x6cf27b: c7867003000065732d38 MOV dword ptr [ESI + 0x370],0x382d7365
    m.w32((s.si+0x00000370u), 0x382d7365u);
  }
  L006cf285: { // 0x6cf285: c7867403000052c1e03f MOV dword ptr [ESI + 0x374],0x3fe0c152
    m.w32((s.si+0x00000374u), 0x3fe0c152u);
  }
  L006cf28f: { // 0x6cf28f: 899e78030000 MOV dword ptr [ESI + 0x378],EBX
    m.w32((s.si+0x00000378u), s.bx);
  }
  L006cf295: { // 0x6cf295: c7867c0300000000d03f MOV dword ptr [ESI + 0x37c],0x3fd00000
    m.w32((s.si+0x0000037cu), 0x3fd00000u);
  }
  L006cf29f: { // 0x6cf29f: c786800300008744e74a MOV dword ptr [ESI + 0x380],0x4ae74487
    m.w32((s.si+0x00000380u), 0x4ae74487u);
  }
  L006cf2a9: { // 0x6cf2a9: c786840300001857d63f MOV dword ptr [ESI + 0x384],0x3fd65718
    m.w32((s.si+0x00000384u), 0x3fd65718u);
  }
  L006cf2b3: { // 0x6cf2b3: 83cfff OR EDI,0xffffffff
    s.di = integer::logical((s.di)|(0xffffffffu),32,flags);
  }
  L006cf2b6: { // 0x6cf2b6: c78688030000ffffff7f MOV dword ptr [ESI + 0x388],0x7fffffff
    m.w32((s.si+0x00000388u), 0x7fffffffu);
  }
  L006cf2c0: { // 0x6cf2c0: 89be8c030000 MOV dword ptr [ESI + 0x38c],EDI
    m.w32((s.si+0x0000038cu), s.di);
  }
  L006cf2c6: { // 0x6cf2c6: 899e90030000 MOV dword ptr [ESI + 0x390],EBX
    m.w32((s.si+0x00000390u), s.bx);
  }
  L006cf2cc: { // 0x6cf2cc: 899e98030000 MOV dword ptr [ESI + 0x398],EBX
    m.w32((s.si+0x00000398u), s.bx);
  }
  L006cf2d2: { // 0x6cf2d2: 899e9c030000 MOV dword ptr [ESI + 0x39c],EBX
    m.w32((s.si+0x0000039cu), s.bx);
  }
  L006cf2d8: { // 0x6cf2d8: c786a003000008000000 MOV dword ptr [ESI + 0x3a0],0x8
    m.w32((s.si+0x000003a0u), 0x00000008u);
  }
  L006cf2e2: { // 0x6cf2e2: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cf2e3: { // 0x6cf2e3: 899ea4030000 MOV dword ptr [ESI + 0x3a4],EBX
    m.w32((s.si+0x000003a4u), s.bx);
  }
  L006cf2e9: { // 0x6cf2e9: 8d8eac030000 LEA ECX,[ESI + 0x3ac]
    s.cx = (s.si+0x000003acu);
  }
  L006cf2ef: { // 0x6cf2ef: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cf2f0: { // 0x6cf2f0: 899ea8030000 MOV dword ptr [ESI + 0x3a8],EBX
    m.w32((s.si+0x000003a8u), s.bx);
  }
  L006cf2f6: { // 0x6cf2f6: e8a58be2ff CALL 0x004f7ea0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f7ea0u,7140091u); flags=s.arithmetic_flags;
  }
  L006cf2fb: { // 0x6cf2fb: c786c00300000a000000 MOV dword ptr [ESI + 0x3c0],0xa
    m.w32((s.si+0x000003c0u), 0x0000000au);
  }
  L006cf305: { // 0x6cf305: 899ebc030000 MOV dword ptr [ESI + 0x3bc],EBX
    m.w32((s.si+0x000003bcu), s.bx);
  }
  L006cf30b: { // 0x6cf30b: c786ac0300002c0e7900 MOV dword ptr [ESI + 0x3ac],0x790e2c
    m.w32((s.si+0x000003acu), 0x00790e2cu);
  }
  L006cf315: { // 0x6cf315: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cf316: { // 0x6cf316: 899ec8030000 MOV dword ptr [ESI + 0x3c8],EBX
    m.w32((s.si+0x000003c8u), s.bx);
  }
  L006cf31c: { // 0x6cf31c: 8d8ed0030000 LEA ECX,[ESI + 0x3d0]
    s.cx = (s.si+0x000003d0u);
  }
  L006cf322: { // 0x6cf322: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cf323: { // 0x6cf323: 899ecc030000 MOV dword ptr [ESI + 0x3cc],EBX
    m.w32((s.si+0x000003ccu), s.bx);
  }
  L006cf329: { // 0x6cf329: e8f2d8d9ff CALL 0x0046cc20
    s.arithmetic_flags=flags; invoke(m,s,f,0x0046cc20u,7140142u); flags=s.arithmetic_flags;
  }
  L006cf32e: { // 0x6cf32e: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cf32f: { // 0x6cf32f: 8d8eec030000 LEA ECX,[ESI + 0x3ec]
    s.cx = (s.si+0x000003ecu);
  }
  L006cf335: { // 0x6cf335: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cf336: { // 0x6cf336: c786e40300000a000000 MOV dword ptr [ESI + 0x3e4],0xa
    m.w32((s.si+0x000003e4u), 0x0000000au);
  }
  L006cf340: { // 0x6cf340: 899ee0030000 MOV dword ptr [ESI + 0x3e0],EBX
    m.w32((s.si+0x000003e0u), s.bx);
  }
  L006cf346: { // 0x6cf346: c786d0030000f4897800 MOV dword ptr [ESI + 0x3d0],0x7889f4
    m.w32((s.si+0x000003d0u), 0x007889f4u);
  }
  L006cf350: { // 0x6cf350: e8cbd8d9ff CALL 0x0046cc20
    s.arithmetic_flags=flags; invoke(m,s,f,0x0046cc20u,7140181u); flags=s.arithmetic_flags;
  }
  L006cf355: { // 0x6cf355: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cf356: { // 0x6cf356: 8d8e08040000 LEA ECX,[ESI + 0x408]
    s.cx = (s.si+0x00000408u);
  }
  L006cf35c: { // 0x6cf35c: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cf35d: { // 0x6cf35d: c786000400000a000000 MOV dword ptr [ESI + 0x400],0xa
    m.w32((s.si+0x00000400u), 0x0000000au);
  }
  L006cf367: { // 0x6cf367: 899efc030000 MOV dword ptr [ESI + 0x3fc],EBX
    m.w32((s.si+0x000003fcu), s.bx);
  }
  L006cf36d: { // 0x6cf36d: c786ec030000f4897800 MOV dword ptr [ESI + 0x3ec],0x7889f4
    m.w32((s.si+0x000003ecu), 0x007889f4u);
  }
  L006cf377: { // 0x6cf377: e8a4d8d9ff CALL 0x0046cc20
    s.arithmetic_flags=flags; invoke(m,s,f,0x0046cc20u,7140220u); flags=s.arithmetic_flags;
  }
  L006cf37c: { // 0x6cf37c: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cf37d: { // 0x6cf37d: 8d8e24040000 LEA ECX,[ESI + 0x424]
    s.cx = (s.si+0x00000424u);
  }
  L006cf383: { // 0x6cf383: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cf384: { // 0x6cf384: c7861c0400000a000000 MOV dword ptr [ESI + 0x41c],0xa
    m.w32((s.si+0x0000041cu), 0x0000000au);
  }
  L006cf38e: { // 0x6cf38e: 899e18040000 MOV dword ptr [ESI + 0x418],EBX
    m.w32((s.si+0x00000418u), s.bx);
  }
  L006cf394: { // 0x6cf394: c78608040000f4897800 MOV dword ptr [ESI + 0x408],0x7889f4
    m.w32((s.si+0x00000408u), 0x007889f4u);
  }
  L006cf39e: { // 0x6cf39e: e87dd8d9ff CALL 0x0046cc20
    s.arithmetic_flags=flags; invoke(m,s,f,0x0046cc20u,7140259u); flags=s.arithmetic_flags;
  }
  L006cf3a3: { // 0x6cf3a3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cf3a4: { // 0x6cf3a4: 8d8e40040000 LEA ECX,[ESI + 0x440]
    s.cx = (s.si+0x00000440u);
  }
  L006cf3aa: { // 0x6cf3aa: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cf3ab: { // 0x6cf3ab: c786380400000a000000 MOV dword ptr [ESI + 0x438],0xa
    m.w32((s.si+0x00000438u), 0x0000000au);
  }
  L006cf3b5: { // 0x6cf3b5: 899e34040000 MOV dword ptr [ESI + 0x434],EBX
    m.w32((s.si+0x00000434u), s.bx);
  }
  L006cf3bb: { // 0x6cf3bb: c78624040000f4897800 MOV dword ptr [ESI + 0x424],0x7889f4
    m.w32((s.si+0x00000424u), 0x007889f4u);
  }
  L006cf3c5: { // 0x6cf3c5: e856d8d9ff CALL 0x0046cc20
    s.arithmetic_flags=flags; invoke(m,s,f,0x0046cc20u,7140298u); flags=s.arithmetic_flags;
  }
  L006cf3ca: { // 0x6cf3ca: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cf3cb: { // 0x6cf3cb: 8d8e5c040000 LEA ECX,[ESI + 0x45c]
    s.cx = (s.si+0x0000045cu);
  }
  L006cf3d1: { // 0x6cf3d1: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cf3d2: { // 0x6cf3d2: c786540400000a000000 MOV dword ptr [ESI + 0x454],0xa
    m.w32((s.si+0x00000454u), 0x0000000au);
  }
  L006cf3dc: { // 0x6cf3dc: 899e50040000 MOV dword ptr [ESI + 0x450],EBX
    m.w32((s.si+0x00000450u), s.bx);
  }
  L006cf3e2: { // 0x6cf3e2: c78640040000f4897800 MOV dword ptr [ESI + 0x440],0x7889f4
    m.w32((s.si+0x00000440u), 0x007889f4u);
  }
  L006cf3ec: { // 0x6cf3ec: e82fd8d9ff CALL 0x0046cc20
    s.arithmetic_flags=flags; invoke(m,s,f,0x0046cc20u,7140337u); flags=s.arithmetic_flags;
  }
  L006cf3f1: { // 0x6cf3f1: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cf3f2: { // 0x6cf3f2: 8d8e78040000 LEA ECX,[ESI + 0x478]
    s.cx = (s.si+0x00000478u);
  }
  L006cf3f8: { // 0x6cf3f8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cf3f9: { // 0x6cf3f9: c786700400000a000000 MOV dword ptr [ESI + 0x470],0xa
    m.w32((s.si+0x00000470u), 0x0000000au);
  }
  L006cf403: { // 0x6cf403: 899e6c040000 MOV dword ptr [ESI + 0x46c],EBX
    m.w32((s.si+0x0000046cu), s.bx);
  }
  L006cf409: { // 0x6cf409: c7865c040000f4897800 MOV dword ptr [ESI + 0x45c],0x7889f4
    m.w32((s.si+0x0000045cu), 0x007889f4u);
  }
  L006cf413: { // 0x6cf413: e808d8d9ff CALL 0x0046cc20
    s.arithmetic_flags=flags; invoke(m,s,f,0x0046cc20u,7140376u); flags=s.arithmetic_flags;
  }
  L006cf418: { // 0x6cf418: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cf419: { // 0x6cf419: 8d8e94040000 LEA ECX,[ESI + 0x494]
    s.cx = (s.si+0x00000494u);
  }
  L006cf41f: { // 0x6cf41f: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cf420: { // 0x6cf420: c7868c0400000a000000 MOV dword ptr [ESI + 0x48c],0xa
    m.w32((s.si+0x0000048cu), 0x0000000au);
  }
  L006cf42a: { // 0x6cf42a: 899e88040000 MOV dword ptr [ESI + 0x488],EBX
    m.w32((s.si+0x00000488u), s.bx);
  }
  L006cf430: { // 0x6cf430: c78678040000f4897800 MOV dword ptr [ESI + 0x478],0x7889f4
    m.w32((s.si+0x00000478u), 0x007889f4u);
  }
  L006cf43a: { // 0x6cf43a: e8e1d7d9ff CALL 0x0046cc20
    s.arithmetic_flags=flags; invoke(m,s,f,0x0046cc20u,7140415u); flags=s.arithmetic_flags;
  }
  L006cf43f: { // 0x6cf43f: c786a80400000a000000 MOV dword ptr [ESI + 0x4a8],0xa
    m.w32((s.si+0x000004a8u), 0x0000000au);
  }
  L006cf449: { // 0x6cf449: 899ea4040000 MOV dword ptr [ESI + 0x4a4],EBX
    m.w32((s.si+0x000004a4u), s.bx);
  }
  L006cf44f: { // 0x6cf44f: c78694040000f4897800 MOV dword ptr [ESI + 0x494],0x7889f4
    m.w32((s.si+0x00000494u), 0x007889f4u);
  }
  L006cf459: { // 0x6cf459: 89beb0040000 MOV dword ptr [ESI + 0x4b0],EDI
    m.w32((s.si+0x000004b0u), s.di);
  }
  L006cf45f: { // 0x6cf45f: 89beb4040000 MOV dword ptr [ESI + 0x4b4],EDI
    m.w32((s.si+0x000004b4u), s.di);
  }
  L006cf465: { // 0x6cf465: 89beb8040000 MOV dword ptr [ESI + 0x4b8],EDI
    m.w32((s.si+0x000004b8u), s.di);
  }
  L006cf46b: { // 0x6cf46b: 89bebc040000 MOV dword ptr [ESI + 0x4bc],EDI
    m.w32((s.si+0x000004bcu), s.di);
  }
  L006cf471: { // 0x6cf471: 89bec0040000 MOV dword ptr [ESI + 0x4c0],EDI
    m.w32((s.si+0x000004c0u), s.di);
  }
  L006cf477: { // 0x6cf477: 89bec4040000 MOV dword ptr [ESI + 0x4c4],EDI
    m.w32((s.si+0x000004c4u), s.di);
  }
  L006cf47d: { // 0x6cf47d: 89bec8040000 MOV dword ptr [ESI + 0x4c8],EDI
    m.w32((s.si+0x000004c8u), s.di);
  }
  L006cf483: { // 0x6cf483: 89becc040000 MOV dword ptr [ESI + 0x4cc],EDI
    m.w32((s.si+0x000004ccu), s.di);
  }
  L006cf489: { // 0x6cf489: 89bed0040000 MOV dword ptr [ESI + 0x4d0],EDI
    m.w32((s.si+0x000004d0u), s.di);
  }
  L006cf48f: { // 0x6cf48f: 89bed4040000 MOV dword ptr [ESI + 0x4d4],EDI
    m.w32((s.si+0x000004d4u), s.di);
  }
  L006cf495: { // 0x6cf495: 89bed8040000 MOV dword ptr [ESI + 0x4d8],EDI
    m.w32((s.si+0x000004d8u), s.di);
  }
  L006cf49b: { // 0x6cf49b: 89bedc040000 MOV dword ptr [ESI + 0x4dc],EDI
    m.w32((s.si+0x000004dcu), s.di);
  }
  L006cf4a1: { // 0x6cf4a1: 89bee0040000 MOV dword ptr [ESI + 0x4e0],EDI
    m.w32((s.si+0x000004e0u), s.di);
  }
  L006cf4a7: { // 0x6cf4a7: 89bee4040000 MOV dword ptr [ESI + 0x4e4],EDI
    m.w32((s.si+0x000004e4u), s.di);
  }
  L006cf4ad: { // 0x6cf4ad: 89bee8040000 MOV dword ptr [ESI + 0x4e8],EDI
    m.w32((s.si+0x000004e8u), s.di);
  }
  L006cf4b3: { // 0x6cf4b3: 89beec040000 MOV dword ptr [ESI + 0x4ec],EDI
    m.w32((s.si+0x000004ecu), s.di);
  }
  L006cf4b9: { // 0x6cf4b9: 89bef0040000 MOV dword ptr [ESI + 0x4f0],EDI
    m.w32((s.si+0x000004f0u), s.di);
  }
  L006cf4bf: { // 0x6cf4bf: 89bef4040000 MOV dword ptr [ESI + 0x4f4],EDI
    m.w32((s.si+0x000004f4u), s.di);
  }
  L006cf4c5: { // 0x6cf4c5: 89bef8040000 MOV dword ptr [ESI + 0x4f8],EDI
    m.w32((s.si+0x000004f8u), s.di);
  }
  L006cf4cb: { // 0x6cf4cb: 89befc040000 MOV dword ptr [ESI + 0x4fc],EDI
    m.w32((s.si+0x000004fcu), s.di);
  }
  L006cf4d1: { // 0x6cf4d1: 899e00050000 MOV dword ptr [ESI + 0x500],EBX
    m.w32((s.si+0x00000500u), s.bx);
  }
  L006cf4d7: { // 0x6cf4d7: 899e04050000 MOV dword ptr [ESI + 0x504],EBX
    m.w32((s.si+0x00000504u), s.bx);
  }
  L006cf4dd: { // 0x6cf4dd: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cf4de: { // 0x6cf4de: 899e08050000 MOV dword ptr [ESI + 0x508],EBX
    m.w32((s.si+0x00000508u), s.bx);
  }
  L006cf4e4: { // 0x6cf4e4: 8d8e10050000 LEA ECX,[ESI + 0x510]
    s.cx = (s.si+0x00000510u);
  }
  L006cf4ea: { // 0x6cf4ea: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cf4eb: { // 0x6cf4eb: 899e0c050000 MOV dword ptr [ESI + 0x50c],EBX
    m.w32((s.si+0x0000050cu), s.bx);
  }
  L006cf4f1: { // 0x6cf4f1: e8bab7e3ff CALL 0x0050acb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0050acb0u,7140598u); flags=s.arithmetic_flags;
  }
  L006cf4f6: { // 0x6cf4f6: c786240500000a000000 MOV dword ptr [ESI + 0x524],0xa
    m.w32((s.si+0x00000524u), 0x0000000au);
  }
  L006cf500: { // 0x6cf500: 899e20050000 MOV dword ptr [ESI + 0x520],EBX
    m.w32((s.si+0x00000520u), s.bx);
  }
  L006cf506: { // 0x6cf506: c786100500003ceb7800 MOV dword ptr [ESI + 0x510],0x78eb3c
    m.w32((s.si+0x00000510u), 0x0078eb3cu);
  }
  L006cf510: { // 0x6cf510: 899e2c050000 MOV dword ptr [ESI + 0x52c],EBX
    m.w32((s.si+0x0000052cu), s.bx);
  }
  L006cf516: { // 0x6cf516: 899e30050000 MOV dword ptr [ESI + 0x530],EBX
    m.w32((s.si+0x00000530u), s.bx);
  }
  L006cf51c: { // 0x6cf51c: 889e34050000 MOV byte ptr [ESI + 0x534],BL
    m.w8((s.si+0x00000534u), (s.bx & 0xffu));
  }
  L006cf522: { // 0x6cf522: 899e38050000 MOV dword ptr [ESI + 0x538],EBX
    m.w32((s.si+0x00000538u), s.bx);
  }
  L006cf528: { // 0x6cf528: 899e3c050000 MOV dword ptr [ESI + 0x53c],EBX
    m.w32((s.si+0x0000053cu), s.bx);
  }
  L006cf52e: { // 0x6cf52e: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cf52f: { // 0x6cf52f: 899e40050000 MOV dword ptr [ESI + 0x540],EBX
    m.w32((s.si+0x00000540u), s.bx);
  }
  L006cf535: { // 0x6cf535: 8d8e60050000 LEA ECX,[ESI + 0x560]
    s.cx = (s.si+0x00000560u);
  }
  L006cf53b: { // 0x6cf53b: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cf53c: { // 0x6cf53c: c7864405000005000000 MOV dword ptr [ESI + 0x544],0x5
    m.w32((s.si+0x00000544u), 0x00000005u);
  }
  L006cf546: { // 0x6cf546: 899e48050000 MOV dword ptr [ESI + 0x548],EBX
    m.w32((s.si+0x00000548u), s.bx);
  }
  L006cf54c: { // 0x6cf54c: 899e4c050000 MOV dword ptr [ESI + 0x54c],EBX
    m.w32((s.si+0x0000054cu), s.bx);
  }
  L006cf552: { // 0x6cf552: 899e50050000 MOV dword ptr [ESI + 0x550],EBX
    m.w32((s.si+0x00000550u), s.bx);
  }
  L006cf558: { // 0x6cf558: 899e54050000 MOV dword ptr [ESI + 0x554],EBX
    m.w32((s.si+0x00000554u), s.bx);
  }
  L006cf55e: { // 0x6cf55e: 89be58050000 MOV dword ptr [ESI + 0x558],EDI
    m.w32((s.si+0x00000558u), s.di);
  }
  L006cf564: { // 0x6cf564: c7865c050000ff000000 MOV dword ptr [ESI + 0x55c],0xff
    m.w32((s.si+0x0000055cu), 0x000000ffu);
  }
  L006cf56e: { // 0x6cf56e: e8add6d9ff CALL 0x0046cc20
    s.arithmetic_flags=flags; invoke(m,s,f,0x0046cc20u,7140723u); flags=s.arithmetic_flags;
  }
  L006cf573: { // 0x6cf573: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cf574: { // 0x6cf574: 8d8e7c050000 LEA ECX,[ESI + 0x57c]
    s.cx = (s.si+0x0000057cu);
  }
  L006cf57a: { // 0x6cf57a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cf57b: { // 0x6cf57b: c786740500000a000000 MOV dword ptr [ESI + 0x574],0xa
    m.w32((s.si+0x00000574u), 0x0000000au);
  }
  L006cf585: { // 0x6cf585: 899e70050000 MOV dword ptr [ESI + 0x570],EBX
    m.w32((s.si+0x00000570u), s.bx);
  }
  L006cf58b: { // 0x6cf58b: c78660050000f4897800 MOV dword ptr [ESI + 0x560],0x7889f4
    m.w32((s.si+0x00000560u), 0x007889f4u);
  }
  L006cf595: { // 0x6cf595: e886d6d9ff CALL 0x0046cc20
    s.arithmetic_flags=flags; invoke(m,s,f,0x0046cc20u,7140762u); flags=s.arithmetic_flags;
  }
  L006cf59a: { // 0x6cf59a: 8b450c MOV EAX,dword ptr [EBP + 0xc]
    s.ax = m.r32((s.bp+0x0000000cu));
  }
  L006cf59d: { // 0x6cf59d: c786900500000a000000 MOV dword ptr [ESI + 0x590],0xa
    m.w32((s.si+0x00000590u), 0x0000000au);
  }
  L006cf5a7: { // 0x6cf5a7: 899e8c050000 MOV dword ptr [ESI + 0x58c],EBX
    m.w32((s.si+0x0000058cu), s.bx);
  }
  L006cf5ad: { // 0x6cf5ad: c7867c050000f4897800 MOV dword ptr [ESI + 0x57c],0x7889f4
    m.w32((s.si+0x0000057cu), 0x007889f4u);
  }
  L006cf5b7: { // 0x6cf5b7: 899e98050000 MOV dword ptr [ESI + 0x598],EBX
    m.w32((s.si+0x00000598u), s.bx);
  }
  L006cf5bd: { // 0x6cf5bd: 899e9c050000 MOV dword ptr [ESI + 0x59c],EBX
    m.w32((s.si+0x0000059cu), s.bx);
  }
  L006cf5c3: { // 0x6cf5c3: 899ea0050000 MOV dword ptr [ESI + 0x5a0],EBX
    m.w32((s.si+0x000005a0u), s.bx);
  }
  L006cf5c9: { // 0x6cf5c9: 8986a4050000 MOV dword ptr [ESI + 0x5a4],EAX
    m.w32((s.si+0x000005a4u), s.ax);
  }
  L006cf5cf: { // 0x6cf5cf: 89bea8050000 MOV dword ptr [ESI + 0x5a8],EDI
    m.w32((s.si+0x000005a8u), s.di);
  }
  L006cf5d5: { // 0x6cf5d5: 89beac050000 MOV dword ptr [ESI + 0x5ac],EDI
    m.w32((s.si+0x000005acu), s.di);
  }
  L006cf5db: { // 0x6cf5db: 899eb0050000 MOV dword ptr [ESI + 0x5b0],EBX
    m.w32((s.si+0x000005b0u), s.bx);
  }
  L006cf5e1: { // 0x6cf5e1: 899eb4050000 MOV dword ptr [ESI + 0x5b4],EBX
    m.w32((s.si+0x000005b4u), s.bx);
  }
  L006cf5e7: { // 0x6cf5e7: 899eb8050000 MOV dword ptr [ESI + 0x5b8],EBX
    m.w32((s.si+0x000005b8u), s.bx);
  }
  L006cf5ed: { // 0x6cf5ed: 89bebc050000 MOV dword ptr [ESI + 0x5bc],EDI
    m.w32((s.si+0x000005bcu), s.di);
  }
  L006cf5f3: { // 0x6cf5f3: 899ec0050000 MOV dword ptr [ESI + 0x5c0],EBX
    m.w32((s.si+0x000005c0u), s.bx);
  }
  L006cf5f9: { // 0x6cf5f9: 899ec4050000 MOV dword ptr [ESI + 0x5c4],EBX
    m.w32((s.si+0x000005c4u), s.bx);
  }
  L006cf5ff: { // 0x6cf5ff: c786c805000001000000 MOV dword ptr [ESI + 0x5c8],0x1
    m.w32((s.si+0x000005c8u), 0x00000001u);
  }
  L006cf609: { // 0x6cf609: 889ecc050000 MOV byte ptr [ESI + 0x5cc],BL
    m.w8((s.si+0x000005ccu), (s.bx & 0xffu));
  }
  L006cf60f: { // 0x6cf60f: c686cd05000001 MOV byte ptr [ESI + 0x5cd],0x1
    m.w8((s.si+0x000005cdu), 0x00000001u);
  }
  L006cf616: { // 0x6cf616: 889ece050000 MOV byte ptr [ESI + 0x5ce],BL
    m.w8((s.si+0x000005ceu), (s.bx & 0xffu));
  }
  L006cf61c: { // 0x6cf61c: 889ecf050000 MOV byte ptr [ESI + 0x5cf],BL
    m.w8((s.si+0x000005cfu), (s.bx & 0xffu));
  }
  L006cf622: { // 0x6cf622: 889ed0050000 MOV byte ptr [ESI + 0x5d0],BL
    m.w8((s.si+0x000005d0u), (s.bx & 0xffu));
  }
  L006cf628: { // 0x6cf628: 899ed4050000 MOV dword ptr [ESI + 0x5d4],EBX
    m.w32((s.si+0x000005d4u), s.bx);
  }
  L006cf62e: { // 0x6cf62e: 899ed8050000 MOV dword ptr [ESI + 0x5d8],EBX
    m.w32((s.si+0x000005d8u), s.bx);
  }
  L006cf634: { // 0x6cf634: 889edc050000 MOV byte ptr [ESI + 0x5dc],BL
    m.w8((s.si+0x000005dcu), (s.bx & 0xffu));
  }
  L006cf63a: { // 0x6cf63a: 889edd050000 MOV byte ptr [ESI + 0x5dd],BL
    m.w8((s.si+0x000005ddu), (s.bx & 0xffu));
  }
  L006cf640: { // 0x6cf640: 89bee0050000 MOV dword ptr [ESI + 0x5e0],EDI
    m.w32((s.si+0x000005e0u), s.di);
  }
  L006cf646: { // 0x6cf646: 889ee4050000 MOV byte ptr [ESI + 0x5e4],BL
    m.w8((s.si+0x000005e4u), (s.bx & 0xffu));
  }
  L006cf64c: { // 0x6cf64c: 899ee8050000 MOV dword ptr [ESI + 0x5e8],EBX
    m.w32((s.si+0x000005e8u), s.bx);
  }
  L006cf652: { // 0x6cf652: b9a4488200 MOV ECX,0x8248a4
    s.cx = 0x008248a4u;
  }
  L006cf657: { // 0x6cf657: 89beec050000 MOV dword ptr [ESI + 0x5ec],EDI
    m.w32((s.si+0x000005ecu), s.di);
  }
  L006cf65d: { // 0x6cf65d: 889ef0050000 MOV byte ptr [ESI + 0x5f0],BL
    m.w8((s.si+0x000005f0u), (s.bx & 0xffu));
  }
  L006cf663: { // 0x6cf663: c686f105000001 MOV byte ptr [ESI + 0x5f1],0x1
    m.w8((s.si+0x000005f1u), 0x00000001u);
  }
  L006cf66a: { // 0x6cf66a: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006cf66c: { // 0x6cf66c: 8d86f2050000 LEA EAX,[ESI + 0x5f2]
    s.ax = (s.si+0x000005f2u);
  }
  L006cf672: { // 0x6cf672: 7504 JNZ 0x006cf678
    if(integer::condition("JNZ",flags)) goto L006cf678;
  }
  L006cf674: { // 0x6cf674: 8818 MOV byte ptr [EAX],BL
    m.w8((s.ax), (s.bx & 0xffu));
  }
  L006cf676: { // 0x6cf676: eb16 JMP 0x006cf68e
    goto L006cf68e;
  }
  L006cf678: { // 0x6cf678: 6a18 PUSH 0x18
    f.push(m,0x00000018u);
  }
  L006cf67a: { // 0x6cf67a: 68a4488200 PUSH 0x8248a4
    f.push(m,0x008248a4u);
  }
  L006cf67f: { // 0x6cf67f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006cf680: { // 0x6cf680: e88be60900 CALL 0x0076dd10
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076dd10u,7140997u); flags=s.arithmetic_flags;
  }
  L006cf685: { // 0x6cf685: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L006cf688: { // 0x6cf688: 889e0a060000 MOV byte ptr [ESI + 0x60a],BL
    m.w8((s.si+0x0000060au), (s.bx & 0xffu));
  }
  L006cf68e: { // 0x6cf68e: baa4488200 MOV EDX,0x8248a4
    s.dx = 0x008248a4u;
  }
  L006cf693: { // 0x6cf693: 899e0c060000 MOV dword ptr [ESI + 0x60c],EBX
    m.w32((s.si+0x0000060cu), s.bx);
  }
  L006cf699: { // 0x6cf699: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L006cf69b: { // 0x6cf69b: 889e10060000 MOV byte ptr [ESI + 0x610],BL
    m.w8((s.si+0x00000610u), (s.bx & 0xffu));
  }
  L006cf6a1: { // 0x6cf6a1: 8d8611060000 LEA EAX,[ESI + 0x611]
    s.ax = (s.si+0x00000611u);
  }
  L006cf6a7: { // 0x6cf6a7: 7504 JNZ 0x006cf6ad
    if(integer::condition("JNZ",flags)) goto L006cf6ad;
  }
  L006cf6a9: { // 0x6cf6a9: 8818 MOV byte ptr [EAX],BL
    m.w8((s.ax), (s.bx & 0xffu));
  }
  L006cf6ab: { // 0x6cf6ab: eb16 JMP 0x006cf6c3
    goto L006cf6c3;
  }
  L006cf6ad: { // 0x6cf6ad: 6a18 PUSH 0x18
    f.push(m,0x00000018u);
  }
  L006cf6af: { // 0x6cf6af: 68a4488200 PUSH 0x8248a4
    f.push(m,0x008248a4u);
  }
  L006cf6b4: { // 0x6cf6b4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006cf6b5: { // 0x6cf6b5: e856e60900 CALL 0x0076dd10
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076dd10u,7141050u); flags=s.arithmetic_flags;
  }
  L006cf6ba: { // 0x6cf6ba: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L006cf6bd: { // 0x6cf6bd: 889e29060000 MOV byte ptr [ESI + 0x629],BL
    m.w8((s.si+0x00000629u), (s.bx & 0xffu));
  }
  L006cf6c3: { // 0x6cf6c3: 899e2c060000 MOV dword ptr [ESI + 0x62c],EBX
    m.w32((s.si+0x0000062cu), s.bx);
  }
  L006cf6c9: { // 0x6cf6c9: 889e30060000 MOV byte ptr [ESI + 0x630],BL
    m.w8((s.si+0x00000630u), (s.bx & 0xffu));
  }
  L006cf6cf: { // 0x6cf6cf: 899e34060000 MOV dword ptr [ESI + 0x634],EBX
    m.w32((s.si+0x00000634u), s.bx);
  }
  L006cf6d5: { // 0x6cf6d5: 899e38060000 MOV dword ptr [ESI + 0x638],EBX
    m.w32((s.si+0x00000638u), s.bx);
  }
  L006cf6db: { // 0x6cf6db: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cf6dc: { // 0x6cf6dc: 899e3c060000 MOV dword ptr [ESI + 0x63c],EBX
    m.w32((s.si+0x0000063cu), s.bx);
  }
  L006cf6e2: { // 0x6cf6e2: 8d8e44060000 LEA ECX,[ESI + 0x644]
    s.cx = (s.si+0x00000644u);
  }
  L006cf6e8: { // 0x6cf6e8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cf6e9: { // 0x6cf6e9: 899e40060000 MOV dword ptr [ESI + 0x640],EBX
    m.w32((s.si+0x00000640u), s.bx);
  }
  L006cf6ef: { // 0x6cf6ef: e8bcb5e3ff CALL 0x0050acb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0050acb0u,7141108u); flags=s.arithmetic_flags;
  }
  L006cf6f4: { // 0x6cf6f4: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cf6f5: { // 0x6cf6f5: 8d8e60060000 LEA ECX,[ESI + 0x660]
    s.cx = (s.si+0x00000660u);
  }
  L006cf6fb: { // 0x6cf6fb: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cf6fc: { // 0x6cf6fc: c786580600000a000000 MOV dword ptr [ESI + 0x658],0xa
    m.w32((s.si+0x00000658u), 0x0000000au);
  }
  L006cf706: { // 0x6cf706: 899e54060000 MOV dword ptr [ESI + 0x654],EBX
    m.w32((s.si+0x00000654u), s.bx);
  }
  L006cf70c: { // 0x6cf70c: c786440600003ceb7800 MOV dword ptr [ESI + 0x644],0x78eb3c
    m.w32((s.si+0x00000644u), 0x0078eb3cu);
  }
  L006cf716: { // 0x6cf716: e895b5e3ff CALL 0x0050acb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0050acb0u,7141147u); flags=s.arithmetic_flags;
  }
  L006cf71b: { // 0x6cf71b: c786740600000a000000 MOV dword ptr [ESI + 0x674],0xa
    m.w32((s.si+0x00000674u), 0x0000000au);
  }
  L006cf725: { // 0x6cf725: 899e70060000 MOV dword ptr [ESI + 0x670],EBX
    m.w32((s.si+0x00000670u), s.bx);
  }
  L006cf72b: { // 0x6cf72b: c786600600003ceb7800 MOV dword ptr [ESI + 0x660],0x78eb3c
    m.w32((s.si+0x00000660u), 0x0078eb3cu);
  }
  L006cf735: { // 0x6cf735: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cf736: { // 0x6cf736: 899e7c060000 MOV dword ptr [ESI + 0x67c],EBX
    m.w32((s.si+0x0000067cu), s.bx);
  }
  L006cf73c: { // 0x6cf73c: 8d8e8c060000 LEA ECX,[ESI + 0x68c]
    s.cx = (s.si+0x0000068cu);
  }
  L006cf742: { // 0x6cf742: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cf743: { // 0x6cf743: 899e80060000 MOV dword ptr [ESI + 0x680],EBX
    m.w32((s.si+0x00000680u), s.bx);
  }
  L006cf749: { // 0x6cf749: 899e84060000 MOV dword ptr [ESI + 0x684],EBX
    m.w32((s.si+0x00000684u), s.bx);
  }
  L006cf74f: { // 0x6cf74f: 899e88060000 MOV dword ptr [ESI + 0x688],EBX
    m.w32((s.si+0x00000688u), s.bx);
  }
  L006cf755: { // 0x6cf755: e8f64fd8ff CALL 0x00454750
    s.arithmetic_flags=flags; invoke(m,s,f,0x00454750u,7141210u); flags=s.arithmetic_flags;
  }
  L006cf75a: { // 0x6cf75a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cf75b: { // 0x6cf75b: 8d8ea8060000 LEA ECX,[ESI + 0x6a8]
    s.cx = (s.si+0x000006a8u);
  }
  L006cf761: { // 0x6cf761: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cf762: { // 0x6cf762: c786a00600000a000000 MOV dword ptr [ESI + 0x6a0],0xa
    m.w32((s.si+0x000006a0u), 0x0000000au);
  }
  L006cf76c: { // 0x6cf76c: 899e9c060000 MOV dword ptr [ESI + 0x69c],EBX
    m.w32((s.si+0x0000069cu), s.bx);
  }
  L006cf772: { // 0x6cf772: c7868c060000ec7f7900 MOV dword ptr [ESI + 0x68c],0x797fec
    m.w32((s.si+0x0000068cu), 0x00797fecu);
  }
  L006cf77c: { // 0x6cf77c: e8cf4fd8ff CALL 0x00454750
    s.arithmetic_flags=flags; invoke(m,s,f,0x00454750u,7141249u); flags=s.arithmetic_flags;
  }
  L006cf781: { // 0x6cf781: b90a000000 MOV ECX,0xa
    s.cx = 0x0000000au;
  }
  L006cf786: { // 0x6cf786: 899eb8060000 MOV dword ptr [ESI + 0x6b8],EBX
    m.w32((s.si+0x000006b8u), s.bx);
  }
  L006cf78c: { // 0x6cf78c: 898ebc060000 MOV dword ptr [ESI + 0x6bc],ECX
    m.w32((s.si+0x000006bcu), s.cx);
  }
  L006cf792: { // 0x6cf792: c786a8060000ec7f7900 MOV dword ptr [ESI + 0x6a8],0x797fec
    m.w32((s.si+0x000006a8u), 0x00797fecu);
  }
  L006cf79c: { // 0x6cf79c: 899ec4060000 MOV dword ptr [ESI + 0x6c4],EBX
    m.w32((s.si+0x000006c4u), s.bx);
  }
  L006cf7a2: { // 0x6cf7a2: 899ec8060000 MOV dword ptr [ESI + 0x6c8],EBX
    m.w32((s.si+0x000006c8u), s.bx);
  }
  L006cf7a8: { // 0x6cf7a8: 899ecc060000 MOV dword ptr [ESI + 0x6cc],EBX
    m.w32((s.si+0x000006ccu), s.bx);
  }
  L006cf7ae: { // 0x6cf7ae: 889ed0060000 MOV byte ptr [ESI + 0x6d0],BL
    m.w8((s.si+0x000006d0u), (s.bx & 0xffu));
  }
  L006cf7b4: { // 0x6cf7b4: 899ed4060000 MOV dword ptr [ESI + 0x6d4],EBX
    m.w32((s.si+0x000006d4u), s.bx);
  }
  L006cf7ba: { // 0x6cf7ba: 899ed8060000 MOV dword ptr [ESI + 0x6d8],EBX
    m.w32((s.si+0x000006d8u), s.bx);
  }
  L006cf7c0: { // 0x6cf7c0: 899edc060000 MOV dword ptr [ESI + 0x6dc],EBX
    m.w32((s.si+0x000006dcu), s.bx);
  }
  L006cf7c6: { // 0x6cf7c6: 899ee0060000 MOV dword ptr [ESI + 0x6e0],EBX
    m.w32((s.si+0x000006e0u), s.bx);
  }
  L006cf7cc: { // 0x6cf7cc: 899ee4060000 MOV dword ptr [ESI + 0x6e4],EBX
    m.w32((s.si+0x000006e4u), s.bx);
  }
  L006cf7d2: { // 0x6cf7d2: 899ee8060000 MOV dword ptr [ESI + 0x6e8],EBX
    m.w32((s.si+0x000006e8u), s.bx);
  }
  L006cf7d8: { // 0x6cf7d8: 899eec060000 MOV dword ptr [ESI + 0x6ec],EBX
    m.w32((s.si+0x000006ecu), s.bx);
  }
  L006cf7de: { // 0x6cf7de: 899ef0060000 MOV dword ptr [ESI + 0x6f0],EBX
    m.w32((s.si+0x000006f0u), s.bx);
  }
  L006cf7e4: { // 0x6cf7e4: 899ef4060000 MOV dword ptr [ESI + 0x6f4],EBX
    m.w32((s.si+0x000006f4u), s.bx);
  }
  L006cf7ea: { // 0x6cf7ea: 899ef8060000 MOV dword ptr [ESI + 0x6f8],EBX
    m.w32((s.si+0x000006f8u), s.bx);
  }
  L006cf7f0: { // 0x6cf7f0: 899efc060000 MOV dword ptr [ESI + 0x6fc],EBX
    m.w32((s.si+0x000006fcu), s.bx);
  }
  L006cf7f6: { // 0x6cf7f6: 889e00070000 MOV byte ptr [ESI + 0x700],BL
    m.w8((s.si+0x00000700u), (s.bx & 0xffu));
  }
  L006cf7fc: { // 0x6cf7fc: 889e01070000 MOV byte ptr [ESI + 0x701],BL
    m.w8((s.si+0x00000701u), (s.bx & 0xffu));
  }
  L006cf802: { // 0x6cf802: 889e02070000 MOV byte ptr [ESI + 0x702],BL
    m.w8((s.si+0x00000702u), (s.bx & 0xffu));
  }
  L006cf808: { // 0x6cf808: 899e04070000 MOV dword ptr [ESI + 0x704],EBX
    m.w32((s.si+0x00000704u), s.bx);
  }
  L006cf80e: { // 0x6cf80e: 889e0c070000 MOV byte ptr [ESI + 0x70c],BL
    m.w8((s.si+0x0000070cu), (s.bx & 0xffu));
  }
  L006cf814: { // 0x6cf814: 889ef0080000 MOV byte ptr [ESI + 0x8f0],BL
    m.w8((s.si+0x000008f0u), (s.bx & 0xffu));
  }
  L006cf81a: { // 0x6cf81a: 889e980a0000 MOV byte ptr [ESI + 0xa98],BL
    m.w8((s.si+0x00000a98u), (s.bx & 0xffu));
  }
  L006cf820: { // 0x6cf820: c686990a000001 MOV byte ptr [ESI + 0xa99],0x1
    m.w8((s.si+0x00000a99u), 0x00000001u);
  }
  L006cf827: { // 0x6cf827: c6869a0a000001 MOV byte ptr [ESI + 0xa9a],0x1
    m.w8((s.si+0x00000a9au), 0x00000001u);
  }
  L006cf82e: { // 0x6cf82e: 889e9b0a0000 MOV byte ptr [ESI + 0xa9b],BL
    m.w8((s.si+0x00000a9bu), (s.bx & 0xffu));
  }
  L006cf834: { // 0x6cf834: 889e9c0a0000 MOV byte ptr [ESI + 0xa9c],BL
    m.w8((s.si+0x00000a9cu), (s.bx & 0xffu));
  }
  L006cf83a: { // 0x6cf83a: 889e9d0a0000 MOV byte ptr [ESI + 0xa9d],BL
    m.w8((s.si+0x00000a9du), (s.bx & 0xffu));
  }
  L006cf840: { // 0x6cf840: 889e9e0a0000 MOV byte ptr [ESI + 0xa9e],BL
    m.w8((s.si+0x00000a9eu), (s.bx & 0xffu));
  }
  L006cf846: { // 0x6cf846: 889e9f0a0000 MOV byte ptr [ESI + 0xa9f],BL
    m.w8((s.si+0x00000a9fu), (s.bx & 0xffu));
  }
  L006cf84c: { // 0x6cf84c: 889ea00a0000 MOV byte ptr [ESI + 0xaa0],BL
    m.w8((s.si+0x00000aa0u), (s.bx & 0xffu));
  }
  L006cf852: { // 0x6cf852: 889ea10a0000 MOV byte ptr [ESI + 0xaa1],BL
    m.w8((s.si+0x00000aa1u), (s.bx & 0xffu));
  }
  L006cf858: { // 0x6cf858: 889ea20a0000 MOV byte ptr [ESI + 0xaa2],BL
    m.w8((s.si+0x00000aa2u), (s.bx & 0xffu));
  }
  L006cf85e: { // 0x6cf85e: c686a30a000001 MOV byte ptr [ESI + 0xaa3],0x1
    m.w8((s.si+0x00000aa3u), 0x00000001u);
  }
  L006cf865: { // 0x6cf865: 889ea40a0000 MOV byte ptr [ESI + 0xaa4],BL
    m.w8((s.si+0x00000aa4u), (s.bx & 0xffu));
  }
  L006cf86b: { // 0x6cf86b: 889ea50a0000 MOV byte ptr [ESI + 0xaa5],BL
    m.w8((s.si+0x00000aa5u), (s.bx & 0xffu));
  }
  L006cf871: { // 0x6cf871: 889ea60a0000 MOV byte ptr [ESI + 0xaa6],BL
    m.w8((s.si+0x00000aa6u), (s.bx & 0xffu));
  }
  L006cf877: { // 0x6cf877: 889ea70a0000 MOV byte ptr [ESI + 0xaa7],BL
    m.w8((s.si+0x00000aa7u), (s.bx & 0xffu));
  }
  L006cf87d: { // 0x6cf87d: 889ea80a0000 MOV byte ptr [ESI + 0xaa8],BL
    m.w8((s.si+0x00000aa8u), (s.bx & 0xffu));
  }
  L006cf883: { // 0x6cf883: 889ea90a0000 MOV byte ptr [ESI + 0xaa9],BL
    m.w8((s.si+0x00000aa9u), (s.bx & 0xffu));
  }
  L006cf889: { // 0x6cf889: 889eaa0a0000 MOV byte ptr [ESI + 0xaaa],BL
    m.w8((s.si+0x00000aaau), (s.bx & 0xffu));
  }
  L006cf88f: { // 0x6cf88f: 889eab0a0000 MOV byte ptr [ESI + 0xaab],BL
    m.w8((s.si+0x00000aabu), (s.bx & 0xffu));
  }
  L006cf895: { // 0x6cf895: c686ac0a000001 MOV byte ptr [ESI + 0xaac],0x1
    m.w8((s.si+0x00000aacu), 0x00000001u);
  }
  L006cf89c: { // 0x6cf89c: ba02000000 MOV EDX,0x2
    s.dx = 0x00000002u;
  }
  L006cf8a1: { // 0x6cf8a1: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L006cf8a6: { // 0x6cf8a6: 8996b00a0000 MOV dword ptr [ESI + 0xab0],EDX
    m.w32((s.si+0x00000ab0u), s.dx);
  }
  L006cf8ac: { // 0x6cf8ac: 8986b40a0000 MOV dword ptr [ESI + 0xab4],EAX
    m.w32((s.si+0x00000ab4u), s.ax);
  }
  L006cf8b2: { // 0x6cf8b2: 8986b80a0000 MOV dword ptr [ESI + 0xab8],EAX
    m.w32((s.si+0x00000ab8u), s.ax);
  }
  L006cf8b8: { // 0x6cf8b8: 8986bc0a0000 MOV dword ptr [ESI + 0xabc],EAX
    m.w32((s.si+0x00000abcu), s.ax);
  }
  L006cf8be: { // 0x6cf8be: 889ec00a0000 MOV byte ptr [ESI + 0xac0],BL
    m.w8((s.si+0x00000ac0u), (s.bx & 0xffu));
  }
  L006cf8c4: { // 0x6cf8c4: 8996c40a0000 MOV dword ptr [ESI + 0xac4],EDX
    m.w32((s.si+0x00000ac4u), s.dx);
  }
  L006cf8ca: { // 0x6cf8ca: 8986c80a0000 MOV dword ptr [ESI + 0xac8],EAX
    m.w32((s.si+0x00000ac8u), s.ax);
  }
  L006cf8d0: { // 0x6cf8d0: 8986cc0a0000 MOV dword ptr [ESI + 0xacc],EAX
    m.w32((s.si+0x00000accu), s.ax);
  }
  L006cf8d6: { // 0x6cf8d6: 8986d00a0000 MOV dword ptr [ESI + 0xad0],EAX
    m.w32((s.si+0x00000ad0u), s.ax);
  }
  L006cf8dc: { // 0x6cf8dc: 889ed40a0000 MOV byte ptr [ESI + 0xad4],BL
    m.w8((s.si+0x00000ad4u), (s.bx & 0xffu));
  }
  L006cf8e2: { // 0x6cf8e2: 8886d80a0000 MOV byte ptr [ESI + 0xad8],AL
    m.w8((s.si+0x00000ad8u), (s.ax & 0xffu));
  }
  L006cf8e8: { // 0x6cf8e8: 889ed90a0000 MOV byte ptr [ESI + 0xad9],BL
    m.w8((s.si+0x00000ad9u), (s.bx & 0xffu));
  }
  L006cf8ee: { // 0x6cf8ee: 889eda0a0000 MOV byte ptr [ESI + 0xada],BL
    m.w8((s.si+0x00000adau), (s.bx & 0xffu));
  }
  L006cf8f4: { // 0x6cf8f4: 889edb0a0000 MOV byte ptr [ESI + 0xadb],BL
    m.w8((s.si+0x00000adbu), (s.bx & 0xffu));
  }
  L006cf8fa: { // 0x6cf8fa: 889edc0a0000 MOV byte ptr [ESI + 0xadc],BL
    m.w8((s.si+0x00000adcu), (s.bx & 0xffu));
  }
  L006cf900: { // 0x6cf900: 889edd0a0000 MOV byte ptr [ESI + 0xadd],BL
    m.w8((s.si+0x00000addu), (s.bx & 0xffu));
  }
  L006cf906: { // 0x6cf906: 889ede0a0000 MOV byte ptr [ESI + 0xade],BL
    m.w8((s.si+0x00000adeu), (s.bx & 0xffu));
  }
  L006cf90c: { // 0x6cf90c: 889edf0a0000 MOV byte ptr [ESI + 0xadf],BL
    m.w8((s.si+0x00000adfu), (s.bx & 0xffu));
  }
  L006cf912: { // 0x6cf912: 889ee00a0000 MOV byte ptr [ESI + 0xae0],BL
    m.w8((s.si+0x00000ae0u), (s.bx & 0xffu));
  }
  L006cf918: { // 0x6cf918: 889ee10a0000 MOV byte ptr [ESI + 0xae1],BL
    m.w8((s.si+0x00000ae1u), (s.bx & 0xffu));
  }
  L006cf91e: { // 0x6cf91e: 889ee20a0000 MOV byte ptr [ESI + 0xae2],BL
    m.w8((s.si+0x00000ae2u), (s.bx & 0xffu));
  }
  L006cf924: { // 0x6cf924: 899ee40a0000 MOV dword ptr [ESI + 0xae4],EBX
    m.w32((s.si+0x00000ae4u), s.bx);
  }
  L006cf92a: { // 0x6cf92a: c786e80a00000000803f MOV dword ptr [ESI + 0xae8],0x3f800000
    m.w32((s.si+0x00000ae8u), 0x3f800000u);
  }
  L006cf934: { // 0x6cf934: 889eec0a0000 MOV byte ptr [ESI + 0xaec],BL
    m.w8((s.si+0x00000aecu), (s.bx & 0xffu));
  }
  L006cf93a: { // 0x6cf93a: 889eed0a0000 MOV byte ptr [ESI + 0xaed],BL
    m.w8((s.si+0x00000aedu), (s.bx & 0xffu));
  }
  L006cf940: { // 0x6cf940: 889eee0a0000 MOV byte ptr [ESI + 0xaee],BL
    m.w8((s.si+0x00000aeeu), (s.bx & 0xffu));
  }
  L006cf946: { // 0x6cf946: 889eef0a0000 MOV byte ptr [ESI + 0xaef],BL
    m.w8((s.si+0x00000aefu), (s.bx & 0xffu));
  }
  L006cf94c: { // 0x6cf94c: 889ef00a0000 MOV byte ptr [ESI + 0xaf0],BL
    m.w8((s.si+0x00000af0u), (s.bx & 0xffu));
  }
  L006cf952: { // 0x6cf952: 889ef10a0000 MOV byte ptr [ESI + 0xaf1],BL
    m.w8((s.si+0x00000af1u), (s.bx & 0xffu));
  }
  L006cf958: { // 0x6cf958: 889ef20a0000 MOV byte ptr [ESI + 0xaf2],BL
    m.w8((s.si+0x00000af2u), (s.bx & 0xffu));
  }
  L006cf95e: { // 0x6cf95e: 889ef30a0000 MOV byte ptr [ESI + 0xaf3],BL
    m.w8((s.si+0x00000af3u), (s.bx & 0xffu));
  }
  L006cf964: { // 0x6cf964: 8886f40a0000 MOV byte ptr [ESI + 0xaf4],AL
    m.w8((s.si+0x00000af4u), (s.ax & 0xffu));
  }
  L006cf96a: { // 0x6cf96a: 889ef50a0000 MOV byte ptr [ESI + 0xaf5],BL
    m.w8((s.si+0x00000af5u), (s.bx & 0xffu));
  }
  L006cf970: { // 0x6cf970: 889ef60a0000 MOV byte ptr [ESI + 0xaf6],BL
    m.w8((s.si+0x00000af6u), (s.bx & 0xffu));
  }
  L006cf976: { // 0x6cf976: 889ef70a0000 MOV byte ptr [ESI + 0xaf7],BL
    m.w8((s.si+0x00000af7u), (s.bx & 0xffu));
  }
  L006cf97c: { // 0x6cf97c: 889ef80a0000 MOV byte ptr [ESI + 0xaf8],BL
    m.w8((s.si+0x00000af8u), (s.bx & 0xffu));
  }
  L006cf982: { // 0x6cf982: 889ef90a0000 MOV byte ptr [ESI + 0xaf9],BL
    m.w8((s.si+0x00000af9u), (s.bx & 0xffu));
  }
  L006cf988: { // 0x6cf988: 889efa0a0000 MOV byte ptr [ESI + 0xafa],BL
    m.w8((s.si+0x00000afau), (s.bx & 0xffu));
  }
  L006cf98e: { // 0x6cf98e: 8886fb0a0000 MOV byte ptr [ESI + 0xafb],AL
    m.w8((s.si+0x00000afbu), (s.ax & 0xffu));
  }
  L006cf994: { // 0x6cf994: 8886fc0a0000 MOV byte ptr [ESI + 0xafc],AL
    m.w8((s.si+0x00000afcu), (s.ax & 0xffu));
  }
  L006cf99a: { // 0x6cf99a: 889efe0a0000 MOV byte ptr [ESI + 0xafe],BL
    m.w8((s.si+0x00000afeu), (s.bx & 0xffu));
  }
  L006cf9a0: { // 0x6cf9a0: 889e000b0000 MOV byte ptr [ESI + 0xb00],BL
    m.w8((s.si+0x00000b00u), (s.bx & 0xffu));
  }
  L006cf9a6: { // 0x6cf9a6: 8886010b0000 MOV byte ptr [ESI + 0xb01],AL
    m.w8((s.si+0x00000b01u), (s.ax & 0xffu));
  }
  L006cf9ac: { // 0x6cf9ac: 889e020b0000 MOV byte ptr [ESI + 0xb02],BL
    m.w8((s.si+0x00000b02u), (s.bx & 0xffu));
  }
  L006cf9b2: { // 0x6cf9b2: 889e030b0000 MOV byte ptr [ESI + 0xb03],BL
    m.w8((s.si+0x00000b03u), (s.bx & 0xffu));
  }
  L006cf9b8: { // 0x6cf9b8: 889e040b0000 MOV byte ptr [ESI + 0xb04],BL
    m.w8((s.si+0x00000b04u), (s.bx & 0xffu));
  }
  L006cf9be: { // 0x6cf9be: 899e080b0000 MOV dword ptr [ESI + 0xb08],EBX
    m.w32((s.si+0x00000b08u), s.bx);
  }
  L006cf9c4: { // 0x6cf9c4: 899e0c0b0000 MOV dword ptr [ESI + 0xb0c],EBX
    m.w32((s.si+0x00000b0cu), s.bx);
  }
  L006cf9ca: { // 0x6cf9ca: 899e100b0000 MOV dword ptr [ESI + 0xb10],EBX
    m.w32((s.si+0x00000b10u), s.bx);
  }
  L006cf9d0: { // 0x6cf9d0: 899e140b0000 MOV dword ptr [ESI + 0xb14],EBX
    m.w32((s.si+0x00000b14u), s.bx);
  }
  L006cf9d6: { // 0x6cf9d6: 889e180b0000 MOV byte ptr [ESI + 0xb18],BL
    m.w8((s.si+0x00000b18u), (s.bx & 0xffu));
  }
  L006cf9dc: { // 0x6cf9dc: 889e190b0000 MOV byte ptr [ESI + 0xb19],BL
    m.w8((s.si+0x00000b19u), (s.bx & 0xffu));
  }
  L006cf9e2: { // 0x6cf9e2: 889e1a0b0000 MOV byte ptr [ESI + 0xb1a],BL
    m.w8((s.si+0x00000b1au), (s.bx & 0xffu));
  }
  L006cf9e8: { // 0x6cf9e8: 899e1c0b0000 MOV dword ptr [ESI + 0xb1c],EBX
    m.w32((s.si+0x00000b1cu), s.bx);
  }
  L006cf9ee: { // 0x6cf9ee: c786200b000004000000 MOV dword ptr [ESI + 0xb20],0x4
    m.w32((s.si+0x00000b20u), 0x00000004u);
  }
  L006cf9f8: { // 0x6cf9f8: b80000a040 MOV EAX,0x40a00000
    s.ax = 0x40a00000u;
  }
  L006cf9fd: { // 0x6cf9fd: c786240b00000e000000 MOV dword ptr [ESI + 0xb24],0xe
    m.w32((s.si+0x00000b24u), 0x0000000eu);
  }
  L006cfa07: { // 0x6cfa07: 8986280b0000 MOV dword ptr [ESI + 0xb28],EAX
    m.w32((s.si+0x00000b28u), s.ax);
  }
  L006cfa0d: { // 0x6cfa0d: 89862c0b0000 MOV dword ptr [ESI + 0xb2c],EAX
    m.w32((s.si+0x00000b2cu), s.ax);
  }
  L006cfa13: { // 0x6cfa13: c786300b0000f4010000 MOV dword ptr [ESI + 0xb30],0x1f4
    m.w32((s.si+0x00000b30u), 0x000001f4u);
  }
  L006cfa1d: { // 0x6cfa1d: c786340b000000000040 MOV dword ptr [ESI + 0xb34],0x40000000
    m.w32((s.si+0x00000b34u), 0x40000000u);
  }
  L006cfa27: { // 0x6cfa27: c786380b00009a99193e MOV dword ptr [ESI + 0xb38],0x3e19999a
    m.w32((s.si+0x00000b38u), 0x3e19999au);
  }
  L006cfa31: { // 0x6cfa31: 889e3c0b0000 MOV byte ptr [ESI + 0xb3c],BL
    m.w8((s.si+0x00000b3cu), (s.bx & 0xffu));
  }
  L006cfa37: { // 0x6cfa37: c786400b000028000000 MOV dword ptr [ESI + 0xb40],0x28
    m.w32((s.si+0x00000b40u), 0x00000028u);
  }
  L006cfa41: { // 0x6cfa41: 889e440b0000 MOV byte ptr [ESI + 0xb44],BL
    m.w8((s.si+0x00000b44u), (s.bx & 0xffu));
  }
  L006cfa47: { // 0x6cfa47: 889e450b0000 MOV byte ptr [ESI + 0xb45],BL
    m.w8((s.si+0x00000b45u), (s.bx & 0xffu));
  }
  L006cfa4d: { // 0x6cfa4d: 889e480b0000 MOV byte ptr [ESI + 0xb48],BL
    m.w8((s.si+0x00000b48u), (s.bx & 0xffu));
  }
  L006cfa53: { // 0x6cfa53: c686490b000001 MOV byte ptr [ESI + 0xb49],0x1
    m.w8((s.si+0x00000b49u), 0x00000001u);
  }
  L006cfa5a: { // 0x6cfa5a: c6864a0b000001 MOV byte ptr [ESI + 0xb4a],0x1
    m.w8((s.si+0x00000b4au), 0x00000001u);
  }
  L006cfa61: { // 0x6cfa61: 889e4b0b0000 MOV byte ptr [ESI + 0xb4b],BL
    m.w8((s.si+0x00000b4bu), (s.bx & 0xffu));
  }
  L006cfa67: { // 0x6cfa67: 889e4c0b0000 MOV byte ptr [ESI + 0xb4c],BL
    m.w8((s.si+0x00000b4cu), (s.bx & 0xffu));
  }
  L006cfa6d: { // 0x6cfa6d: 89be500b0000 MOV dword ptr [ESI + 0xb50],EDI
    m.w32((s.si+0x00000b50u), s.di);
  }
  L006cfa73: { // 0x6cfa73: 89be540b0000 MOV dword ptr [ESI + 0xb54],EDI
    m.w32((s.si+0x00000b54u), s.di);
  }
  L006cfa79: { // 0x6cfa79: 889e580b0000 MOV byte ptr [ESI + 0xb58],BL
    m.w8((s.si+0x00000b58u), (s.bx & 0xffu));
  }
  L006cfa7f: { // 0x6cfa7f: c686590b000001 MOV byte ptr [ESI + 0xb59],0x1
    m.w8((s.si+0x00000b59u), 0x00000001u);
  }
  L006cfa86: { // 0x6cfa86: 889e5a0b0000 MOV byte ptr [ESI + 0xb5a],BL
    m.w8((s.si+0x00000b5au), (s.bx & 0xffu));
  }
  L006cfa8c: { // 0x6cfa8c: 889e5b0b0000 MOV byte ptr [ESI + 0xb5b],BL
    m.w8((s.si+0x00000b5bu), (s.bx & 0xffu));
  }
  L006cfa92: { // 0x6cfa92: 898e5c0b0000 MOV dword ptr [ESI + 0xb5c],ECX
    m.w32((s.si+0x00000b5cu), s.cx);
  }
  L006cfa98: { // 0x6cfa98: c786600b000005000000 MOV dword ptr [ESI + 0xb60],0x5
    m.w32((s.si+0x00000b60u), 0x00000005u);
  }
  L006cfaa2: { // 0x6cfaa2: 898e640b0000 MOV dword ptr [ESI + 0xb64],ECX
    m.w32((s.si+0x00000b64u), s.cx);
  }
  L006cfaa8: { // 0x6cfaa8: 899e680b0000 MOV dword ptr [ESI + 0xb68],EBX
    m.w32((s.si+0x00000b68u), s.bx);
  }
  L006cfaae: { // 0x6cfaae: 899e8c0b0000 MOV dword ptr [ESI + 0xb8c],EBX
    m.w32((s.si+0x00000b8cu), s.bx);
  }
  L006cfab4: { // 0x6cfab4: c706287f7900 MOV dword ptr [ESI],0x797f28
    m.w32((s.si), 0x00797f28u);
  }
  L006cfaba: { // 0x6cfaba: c746040c7f7900 MOV dword ptr [ESI + 0x4],0x797f0c
    m.w32((s.si+0x00000004u), 0x00797f0cu);
  }
  L006cfac1: { // 0x6cfac1: c74608047f7900 MOV dword ptr [ESI + 0x8],0x797f04
    m.w32((s.si+0x00000008u), 0x00797f04u);
  }
  L006cfac8: { // 0x6cfac8: c7460cfc7e7900 MOV dword ptr [ESI + 0xc],0x797efc
    m.w32((s.si+0x0000000cu), 0x00797efcu);
  }
  L006cfacf: { // 0x6cfacf: 8d8ee4020000 LEA ECX,[ESI + 0x2e4]
    s.cx = (s.si+0x000002e4u);
  }
  L006cfad5: { // 0x6cfad5: 889e6c0b0000 MOV byte ptr [ESI + 0xb6c],BL
    m.w8((s.si+0x00000b6cu), (s.bx & 0xffu));
  }
  L006cfadb: { // 0x6cfadb: c6860402000001 MOV byte ptr [ESI + 0x204],0x1
    m.w8((s.si+0x00000204u), 0x00000001u);
  }
  L006cfae2: { // 0x6cfae2: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006cfae4: { // 0x6cfae4: ff500c CALL dword ptr [EAX + 0xc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000000cu)),7142119u); flags=s.arithmetic_flags;
  }
  L006cfae7: { // 0x6cfae7: 8b9610050000 MOV EDX,dword ptr [ESI + 0x510]
    s.dx = m.r32((s.si+0x00000510u));
  }
  L006cfaed: { // 0x6cfaed: 8d8e10050000 LEA ECX,[ESI + 0x510]
    s.cx = (s.si+0x00000510u);
  }
  L006cfaf3: { // 0x6cfaf3: ff520c CALL dword ptr [EDX + 0xc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000000cu)),7142134u); flags=s.arithmetic_flags;
  }
  L006cfaf6: { // 0x6cfaf6: 8b8600030000 MOV EAX,dword ptr [ESI + 0x300]
    s.ax = m.r32((s.si+0x00000300u));
  }
  L006cfafc: { // 0x6cfafc: 8d8e00030000 LEA ECX,[ESI + 0x300]
    s.cx = (s.si+0x00000300u);
  }
  L006cfb02: { // 0x6cfb02: ff500c CALL dword ptr [EAX + 0xc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000000cu)),7142149u); flags=s.arithmetic_flags;
  }
  L006cfb05: { // 0x6cfb05: 8b96ac030000 MOV EDX,dword ptr [ESI + 0x3ac]
    s.dx = m.r32((s.si+0x000003acu));
  }
  L006cfb0b: { // 0x6cfb0b: 8d8eac030000 LEA ECX,[ESI + 0x3ac]
    s.cx = (s.si+0x000003acu);
  }
  L006cfb11: { // 0x6cfb11: ff520c CALL dword ptr [EDX + 0xc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000000cu)),7142164u); flags=s.arithmetic_flags;
  }
  L006cfb14: { // 0x6cfb14: 8d865c070000 LEA EAX,[ESI + 0x75c]
    s.ax = (s.si+0x0000075cu);
  }
  L006cfb1a: { // 0x6cfb1a: c744240c0f000000 MOV dword ptr [ESP + 0xc],0xf
    m.w32((f.sp+0x0000000cu), 0x0000000fu);
  }
  L006cfb22: { // 0x6cfb22: 8d48f4 LEA ECX,[EAX + -0xc]
    s.cx = (s.ax-0x0000000cu);
  }
  L006cfb25: { // 0x6cfb25: 8958f0 MOV dword ptr [EAX + -0x10],EBX
    m.w32((s.ax-0x00000010u), s.bx);
  }
  L006cfb28: { // 0x6cfb28: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L006cfb2a: { // 0x6cfb2a: 8918 MOV dword ptr [EAX],EBX
    m.w32((s.ax), s.bx);
  }
  L006cfb2c: { // 0x6cfb2c: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L006cfb2e: { // 0x6cfb2e: 895804 MOV dword ptr [EAX + 0x4],EBX
    m.w32((s.ax+0x00000004u), s.bx);
  }
  L006cfb31: { // 0x6cfb31: 890a MOV dword ptr [EDX],ECX
    m.w32((s.dx), s.cx);
  }
  L006cfb33: { // 0x6cfb33: 83c01c ADD EAX,0x1c
    s.ax = integer::add(s.ax,0x0000001cu,32,flags);
  }
  L006cfb36: { // 0x6cfb36: 894a04 MOV dword ptr [EDX + 0x4],ECX
    m.w32((s.dx+0x00000004u), s.cx);
  }
  L006cfb39: { // 0x6cfb39: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  L006cfb3c: { // 0x6cfb3c: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L006cfb40: { // 0x6cfb40: 8858ec MOV byte ptr [EAX + -0x14],BL
    m.w8((s.ax-0x00000014u), (s.bx & 0xffu));
  }
  L006cfb43: { // 0x6cfb43: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L006cfb44: { // 0x6cfb44: 894c240c MOV dword ptr [ESP + 0xc],ECX
    m.w32((f.sp+0x0000000cu), s.cx);
  }
  L006cfb48: { // 0x6cfb48: 75d8 JNZ 0x006cfb22
    if(integer::condition("JNZ",flags)) goto L006cfb22;
  }
  L006cfb4a: { // 0x6cfb4a: 8d8604090000 LEA EAX,[ESI + 0x904]
    s.ax = (s.si+0x00000904u);
  }
  L006cfb50: { // 0x6cfb50: c744240c0f000000 MOV dword ptr [ESP + 0xc],0xf
    m.w32((f.sp+0x0000000cu), 0x0000000fu);
  }
  L006cfb58: { // 0x6cfb58: 8d48f4 LEA ECX,[EAX + -0xc]
    s.cx = (s.ax-0x0000000cu);
  }
  L006cfb5b: { // 0x6cfb5b: 8958f0 MOV dword ptr [EAX + -0x10],EBX
    m.w32((s.ax-0x00000010u), s.bx);
  }
  L006cfb5e: { // 0x6cfb5e: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L006cfb60: { // 0x6cfb60: 8918 MOV dword ptr [EAX],EBX
    m.w32((s.ax), s.bx);
  }
  L006cfb62: { // 0x6cfb62: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L006cfb64: { // 0x6cfb64: 895804 MOV dword ptr [EAX + 0x4],EBX
    m.w32((s.ax+0x00000004u), s.bx);
  }
  L006cfb67: { // 0x6cfb67: 890a MOV dword ptr [EDX],ECX
    m.w32((s.dx), s.cx);
  }
  L006cfb69: { // 0x6cfb69: 83c01c ADD EAX,0x1c
    s.ax = integer::add(s.ax,0x0000001cu,32,flags);
  }
  L006cfb6c: { // 0x6cfb6c: 894a04 MOV dword ptr [EDX + 0x4],ECX
    m.w32((s.dx+0x00000004u), s.cx);
  }
  L006cfb6f: { // 0x6cfb6f: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  L006cfb72: { // 0x6cfb72: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L006cfb76: { // 0x6cfb76: 8858ec MOV byte ptr [EAX + -0x14],BL
    m.w8((s.ax-0x00000014u), (s.bx & 0xffu));
  }
  L006cfb79: { // 0x6cfb79: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L006cfb7a: { // 0x6cfb7a: 894c240c MOV dword ptr [ESP + 0xc],ECX
    m.w32((f.sp+0x0000000cu), s.cx);
  }
  L006cfb7e: { // 0x6cfb7e: 75d8 JNZ 0x006cfb58
    if(integer::condition("JNZ",flags)) goto L006cfb58;
  }
  L006cfb80: { // 0x6cfb80: 8d9610070000 LEA EDX,[ESI + 0x710]
    s.dx = (s.si+0x00000710u);
  }
  L006cfb86: { // 0x6cfb86: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L006cfb88: { // 0x6cfb88: b90f000000 MOV ECX,0xf
    s.cx = 0x0000000fu;
  }
  L006cfb8d: { // 0x6cfb8d: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L006cfb8f: { // 0x6cfb8f: f3ab STOSD.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::count);
  }
  L006cfb91: { // 0x6cfb91: a1c087aa00 MOV EAX,[0x00aa87c0]
    s.ax = m.r32((0x00aa87c0u));
  }
  L006cfb96: { // 0x6cfb96: 8b0dc887aa00 MOV ECX,dword ptr [0x00aa87c8]
    s.cx = m.r32((0x00aa87c8u));
  }
  L006cfb9c: { // 0x6cfb9c: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L006cfb9e: { // 0x6cfb9e: 7c2b JL 0x006cfbcb
    if(integer::condition("JL",flags)) goto L006cfbcb;
  }
  L006cfba0: { // 0x6cfba0: 381dc587aa00 CMP byte ptr [0x00aa87c5],BL
    (void)integer::sub(m.r8((0x00aa87c5u)),(s.bx & 0xffu),8,flags);
  }
  L006cfba6: { // 0x6cfba6: 7504 JNZ 0x006cfbac
    if(integer::condition("JNZ",flags)) goto L006cfbac;
  }
  L006cfba8: { // 0x6cfba8: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L006cfbaa: { // 0x6cfbaa: 7537 JNZ 0x006cfbe3
    if(integer::condition("JNZ",flags)) goto L006cfbe3;
  }
  L006cfbac: { // 0x6cfbac: 8b0dcc87aa00 MOV ECX,dword ptr [0x00aa87cc]
    s.cx = m.r32((0x00aa87ccu));
  }
  L006cfbb2: { // 0x6cfbb2: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L006cfbb4: { // 0x6cfbb4: 7e2d JLE 0x006cfbe3
    if(integer::condition("JLE",flags)) goto L006cfbe3;
  }
  L006cfbb6: { // 0x6cfbb6: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L006cfbb8: { // 0x6cfbb8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cfbb9: { // 0x6cfbb9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006cfbba: { // 0x6cfbba: a1b887aa00 MOV EAX,[0x00aa87b8]
    s.ax = m.r32((0x00aa87b8u));
  }
  L006cfbbf: { // 0x6cfbbf: b9b887aa00 MOV ECX,0xaa87b8
    s.cx = 0x00aa87b8u;
  }
  L006cfbc4: { // 0x6cfbc4: ff5008 CALL dword ptr [EAX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000008u)),7142343u); flags=s.arithmetic_flags;
  }
  L006cfbc7: { // 0x6cfbc7: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006cfbc9: { // 0x6cfbc9: 7418 JZ 0x006cfbe3
    if(integer::condition("JZ",flags)) goto L006cfbe3;
  }
  L006cfbcb: { // 0x6cfbcb: 8b0dc887aa00 MOV ECX,dword ptr [0x00aa87c8]
    s.cx = m.r32((0x00aa87c8u));
  }
  L006cfbd1: { // 0x6cfbd1: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L006cfbd3: { // 0x6cfbd3: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L006cfbd4: { // 0x6cfbd4: 890dc887aa00 MOV dword ptr [0x00aa87c8],ECX
    m.w32((0x00aa87c8u), s.cx);
  }
  L006cfbda: { // 0x6cfbda: 8b0dbc87aa00 MOV ECX,dword ptr [0x00aa87bc]
    s.cx = m.r32((0x00aa87bcu));
  }
  L006cfbe0: { // 0x6cfbe0: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L006cfbe3: { // 0x6cfbe3: a10087a200 MOV EAX,[0x00a28700]
    s.ax = m.r32((0x00a28700u));
  }
  L006cfbe8: { // 0x6cfbe8: 8b0d0887a200 MOV ECX,dword ptr [0x00a28708]
    s.cx = m.r32((0x00a28708u));
  }
  L006cfbee: { // 0x6cfbee: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L006cfbf0: { // 0x6cfbf0: 7c2c JL 0x006cfc1e
    if(integer::condition("JL",flags)) goto L006cfc1e;
  }
  L006cfbf2: { // 0x6cfbf2: 381d0587a200 CMP byte ptr [0x00a28705],BL
    (void)integer::sub(m.r8((0x00a28705u)),(s.bx & 0xffu),8,flags);
  }
  L006cfbf8: { // 0x6cfbf8: 7504 JNZ 0x006cfbfe
    if(integer::condition("JNZ",flags)) goto L006cfbfe;
  }
  L006cfbfa: { // 0x6cfbfa: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L006cfbfc: { // 0x6cfbfc: 7538 JNZ 0x006cfc36
    if(integer::condition("JNZ",flags)) goto L006cfc36;
  }
  L006cfbfe: { // 0x6cfbfe: 8b0d0c87a200 MOV ECX,dword ptr [0x00a2870c]
    s.cx = m.r32((0x00a2870cu));
  }
  L006cfc04: { // 0x6cfc04: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L006cfc06: { // 0x6cfc06: 7e2e JLE 0x006cfc36
    if(integer::condition("JLE",flags)) goto L006cfc36;
  }
  L006cfc08: { // 0x6cfc08: 8b15f886a200 MOV EDX,dword ptr [0x00a286f8]
    s.dx = m.r32((0x00a286f8u));
  }
  L006cfc0e: { // 0x6cfc0e: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L006cfc10: { // 0x6cfc10: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cfc11: { // 0x6cfc11: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006cfc12: { // 0x6cfc12: b9f886a200 MOV ECX,0xa286f8
    s.cx = 0x00a286f8u;
  }
  L006cfc17: { // 0x6cfc17: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),7142426u); flags=s.arithmetic_flags;
  }
  L006cfc1a: { // 0x6cfc1a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006cfc1c: { // 0x6cfc1c: 7418 JZ 0x006cfc36
    if(integer::condition("JZ",flags)) goto L006cfc36;
  }
  L006cfc1e: { // 0x6cfc1e: 8b0d0887a200 MOV ECX,dword ptr [0x00a28708]
    s.cx = m.r32((0x00a28708u));
  }
  L006cfc24: { // 0x6cfc24: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L006cfc26: { // 0x6cfc26: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L006cfc27: { // 0x6cfc27: 890d0887a200 MOV dword ptr [0x00a28708],ECX
    m.w32((0x00a28708u), s.cx);
  }
  L006cfc2d: { // 0x6cfc2d: 8b0dfc86a200 MOV ECX,dword ptr [0x00a286fc]
    s.cx = m.r32((0x00a286fcu));
  }
  L006cfc33: { // 0x6cfc33: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L006cfc36: { // 0x6cfc36: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L006cfc38: { // 0x6cfc38: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006cfc39: { // 0x6cfc39: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006cfc3a: { // 0x6cfc3a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006cfc3b: { // 0x6cfc3b: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L006cfc3d: { // 0x6cfc3d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006cfc3e: { // 0x6cfc3e: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_0000ff10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0040ff10: { // 0x40ff10: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0040ff12: { // 0x40ff12: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0040ff14: { // 0x40ff14: c74008445e7800 MOV dword ptr [EAX + 0x8],0x785e44
    m.w32((s.ax+0x00000008u), 0x00785e44u);
  }
  L0040ff1b: { // 0x40ff1b: c7400c3c5e7800 MOV dword ptr [EAX + 0xc],0x785e3c
    m.w32((s.ax+0x0000000cu), 0x00785e3cu);
  }
  L0040ff22: { // 0x40ff22: 894818 MOV dword ptr [EAX + 0x18],ECX
    m.w32((s.ax+0x00000018u), s.cx);
  }
  L0040ff25: { // 0x40ff25: 89481c MOV dword ptr [EAX + 0x1c],ECX
    m.w32((s.ax+0x0000001cu), s.cx);
  }
  L0040ff28: { // 0x40ff28: 884820 MOV byte ptr [EAX + 0x20],CL
    m.w8((s.ax+0x00000020u), (s.cx & 0xffu));
  }
  L0040ff2b: { // 0x40ff2b: 8a4814 MOV CL,byte ptr [EAX + 0x14]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000014u)));
  }
  L0040ff2e: { // 0x40ff2e: 80e1f8 AND CL,0xf8
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))&(0x000000f8u),8,flags));
  }
  L0040ff31: { // 0x40ff31: c74010ffffffff MOV dword ptr [EAX + 0x10],0xffffffff
    m.w32((s.ax+0x00000010u), 0xffffffffu);
  }
  L0040ff38: { // 0x40ff38: c700d85d7800 MOV dword ptr [EAX],0x785dd8
    m.w32((s.ax), 0x00785dd8u);
  }
  L0040ff3e: { // 0x40ff3e: c74004bc5d7800 MOV dword ptr [EAX + 0x4],0x785dbc
    m.w32((s.ax+0x00000004u), 0x00785dbcu);
  }
  L0040ff45: { // 0x40ff45: c74008b45d7800 MOV dword ptr [EAX + 0x8],0x785db4
    m.w32((s.ax+0x00000008u), 0x00785db4u);
  }
  L0040ff4c: { // 0x40ff4c: c7400cac5d7800 MOV dword ptr [EAX + 0xc],0x785dac
    m.w32((s.ax+0x0000000cu), 0x00785dacu);
  }
  L0040ff53: { // 0x40ff53: 884814 MOV byte ptr [EAX + 0x14],CL
    m.w8((s.ax+0x00000014u), (s.cx & 0xffu));
  }
  L0040ff56: { // 0x40ff56: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0000ffd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0040ffd0: { // 0x0040ffd0: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L0040ffd6: { // 0x0040ffd6: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0040ffd8: { // 0x0040ffd8: 750c JNZ 0x0040ffe6
    if(integer::condition("JNZ",flags)) goto L0040ffe6;
  }
  L0040ffda: { // 0x0040ffda: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L0040ffde: { // 0x0040ffde: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0040ffe0: { // 0x0040ffe0: 89410c MOV dword ptr [ECX + 0xc],EAX
    m.w32((s.cx+0x0000000cu), s.ax);
  }
  L0040ffe3: { // 0x0040ffe3: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0040ffe6: { // 0x0040ffe6: e835a12400 CALL 0x0065a120
    s.arithmetic_flags=flags; invoke(m,s,f,0x0065a120u,4259819u); flags=s.arithmetic_flags;
  }
  L0040ffeb: { // 0x0040ffeb: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L0040ffef: { // 0x0040ffef: 89420c MOV dword ptr [EDX + 0xc],EAX
    m.w32((s.dx+0x0000000cu), s.ax);
  }
  L0040fff2: { // 0x0040fff2: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00010580(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00410580: { // 0x410580: 83ec44 SUB ESP,0x44
    f.sp = integer::sub(f.sp,0x00000044u,32,flags);
  }
  L00410583: { // 0x410583: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00410584: { // 0x410584: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00410585: { // 0x410585: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00410586: { // 0x410586: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00410587: { // 0x410587: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L00410589: { // 0x410589: e882f9ffff CALL 0x0040ff10
    s.arithmetic_flags=flags; invoke(m,s,f,0x0040ff10u,4261262u); flags=s.arithmetic_flags;
  }
  L0041058e: { // 0x41058e: 8b442458 MOV EAX,dword ptr [ESP + 0x58]
    s.ax = m.r32((f.sp+0x00000058u));
  }
  L00410592: { // 0x410592: 8d5d24 LEA EBX,[EBP + 0x24]
    s.bx = (s.bp+0x00000024u);
  }
  L00410595: { // 0x410595: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00410597: { // 0x410597: c60300 MOV byte ptr [EBX],0x0
    m.w8((s.bx), 0x00000000u);
  }
  L0041059a: { // 0x41059a: c6453d00 MOV byte ptr [EBP + 0x3d],0x0
    m.w8((s.bp+0x0000003du), 0x00000000u);
  }
  L0041059e: { // 0x41059e: c6456400 MOV byte ptr [EBP + 0x64],0x0
    m.w8((s.bp+0x00000064u), 0x00000000u);
  }
  L004105a2: { // 0x4105a2: c74500885e7800 MOV dword ptr [EBP],0x785e88
    m.w32((s.bp), 0x00785e88u);
  }
  L004105a9: { // 0x4105a9: c745046c5e7800 MOV dword ptr [EBP + 0x4],0x785e6c
    m.w32((s.bp+0x00000004u), 0x00785e6cu);
  }
  L004105b0: { // 0x4105b0: c74508645e7800 MOV dword ptr [EBP + 0x8],0x785e64
    m.w32((s.bp+0x00000008u), 0x00785e64u);
  }
  L004105b7: { // 0x4105b7: c7450c5c5e7800 MOV dword ptr [EBP + 0xc],0x785e5c
    m.w32((s.bp+0x0000000cu), 0x00785e5cu);
  }
  L004105be: { // 0x4105be: 754d JNZ 0x0041060d
    if(integer::condition("JNZ",flags)) goto L0041060d;
  }
  L004105c0: { // 0x4105c0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004105c1: { // 0x4105c1: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L004105c5: { // 0x4105c5: 6810927b00 PUSH 0x7b9210
    f.push(m,0x007b9210u);
  }
  L004105ca: { // 0x4105ca: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004105cb: { // 0x4105cb: e864d43500 CALL 0x0076da34
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076da34u,4261328u); flags=s.arithmetic_flags;
  }
  L004105d0: { // 0x4105d0: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L004105d4: { // 0x4105d4: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L004105d7: { // 0x4105d7: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004105d9: { // 0x4105d9: 7506 JNZ 0x004105e1
    if(integer::condition("JNZ",flags)) goto L004105e1;
  }
  L004105db: { // 0x4105db: 884c2420 MOV byte ptr [ESP + 0x20],CL
    m.w8((f.sp+0x00000020u), (s.cx & 0xffu));
  }
  L004105df: { // 0x4105df: eb19 JMP 0x004105fa
    goto L004105fa;
  }
  L004105e1: { // 0x4105e1: 8d542410 LEA EDX,[ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  L004105e5: { // 0x4105e5: 6a18 PUSH 0x18
    f.push(m,0x00000018u);
  }
  L004105e7: { // 0x4105e7: 8d442424 LEA EAX,[ESP + 0x24]
    s.ax = (f.sp+0x00000024u);
  }
  L004105eb: { // 0x4105eb: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004105ec: { // 0x4105ec: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004105ed: { // 0x4105ed: e81ed73500 CALL 0x0076dd10
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076dd10u,4261362u); flags=s.arithmetic_flags;
  }
  L004105f2: { // 0x4105f2: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L004105f5: { // 0x4105f5: c644243800 MOV byte ptr [ESP + 0x38],0x0
    m.w8((f.sp+0x00000038u), 0x00000000u);
  }
  L004105fa: { // 0x4105fa: 8d4c2420 LEA ECX,[ESP + 0x20]
    s.cx = (f.sp+0x00000020u);
  }
  L004105fe: { // 0x4105fe: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L00410600: { // 0x410600: 7436 JZ 0x00410638
    if(integer::condition("JZ",flags)) goto L00410638;
  }
  L00410602: { // 0x410602: b906000000 MOV ECX,0x6
    s.cx = 0x00000006u;
  }
  L00410607: { // 0x410607: 8d742420 LEA ESI,[ESP + 0x20]
    s.si = (f.sp+0x00000020u);
  }
  L0041060b: { // 0x41060b: eb26 JMP 0x00410633
    goto L00410633;
  }
  L0041060d: { // 0x41060d: 6a18 PUSH 0x18
    f.push(m,0x00000018u);
  }
  L0041060f: { // 0x41060f: 8d542424 LEA EDX,[ESP + 0x24]
    s.dx = (f.sp+0x00000024u);
  }
  L00410613: { // 0x410613: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00410614: { // 0x410614: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00410615: { // 0x410615: e8f6d63500 CALL 0x0076dd10
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076dd10u,4261402u); flags=s.arithmetic_flags;
  }
  L0041061a: { // 0x41061a: 8d44242c LEA EAX,[ESP + 0x2c]
    s.ax = (f.sp+0x0000002cu);
  }
  L0041061e: { // 0x41061e: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00410621: { // 0x410621: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00410623: { // 0x410623: c644243800 MOV byte ptr [ESP + 0x38],0x0
    m.w8((f.sp+0x00000038u), 0x00000000u);
  }
  L00410628: { // 0x410628: 740e JZ 0x00410638
    if(integer::condition("JZ",flags)) goto L00410638;
  }
  L0041062a: { // 0x41062a: b906000000 MOV ECX,0x6
    s.cx = 0x00000006u;
  }
  L0041062f: { // 0x41062f: 8d742420 LEA ESI,[ESP + 0x20]
    s.si = (f.sp+0x00000020u);
  }
  L00410633: { // 0x410633: 8bfb MOV EDI,EBX
    s.di = s.bx;
  }
  L00410635: { // 0x410635: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L00410637: { // 0x410637: a4 MOVSB ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::single);
  }
  L00410638: { // 0x410638: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L0041063a: { // 0x41063a: 7506 JNZ 0x00410642
    if(integer::condition("JNZ",flags)) goto L00410642;
  }
  L0041063c: { // 0x41063c: 885c2420 MOV byte ptr [ESP + 0x20],BL
    m.w8((f.sp+0x00000020u), (s.bx & 0xffu));
  }
  L00410640: { // 0x410640: eb15 JMP 0x00410657
    goto L00410657;
  }
  L00410642: { // 0x410642: 6a30 PUSH 0x30
    f.push(m,0x00000030u);
  }
  L00410644: { // 0x410644: 8d4c2424 LEA ECX,[ESP + 0x24]
    s.cx = (f.sp+0x00000024u);
  }
  L00410648: { // 0x410648: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00410649: { // 0x410649: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0041064a: { // 0x41064a: e8c1d63500 CALL 0x0076dd10
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076dd10u,4261455u); flags=s.arithmetic_flags;
  }
  L0041064f: { // 0x41064f: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00410652: { // 0x410652: c644245000 MOV byte ptr [ESP + 0x50],0x0
    m.w8((f.sp+0x00000050u), 0x00000000u);
  }
  L00410657: { // 0x410657: 8d542420 LEA EDX,[ESP + 0x20]
    s.dx = (f.sp+0x00000020u);
  }
  L0041065b: { // 0x41065b: 8d7d64 LEA EDI,[EBP + 0x64]
    s.di = (s.bp+0x00000064u);
  }
  L0041065e: { // 0x41065e: 3bd7 CMP EDX,EDI
    (void)integer::sub(s.dx,s.di,32,flags);
  }
  L00410660: { // 0x410660: 740c JZ 0x0041066e
    if(integer::condition("JZ",flags)) goto L0041066e;
  }
  L00410662: { // 0x410662: b90c000000 MOV ECX,0xc
    s.cx = 0x0000000cu;
  }
  L00410667: { // 0x410667: 8d742420 LEA ESI,[ESP + 0x20]
    s.si = (f.sp+0x00000020u);
  }
  L0041066b: { // 0x41066b: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L0041066d: { // 0x41066d: a4 MOVSB ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::single);
  }
  L0041066e: { // 0x41066e: c745608c208200 MOV dword ptr [EBP + 0x60],0x82208c
    m.w32((s.bp+0x00000060u), 0x0082208cu);
  }
  L00410675: { // 0x410675: a18085a200 MOV EAX,[0x00a28580]
    s.ax = m.r32((0x00a28580u));
  }
  L0041067a: { // 0x41067a: 39058885a200 CMP dword ptr [0x00a28588],EAX
    (void)integer::sub(m.r32((0x00a28588u)),s.ax,32,flags);
  }
  L00410680: { // 0x410680: 7c2e JL 0x004106b0
    if(integer::condition("JL",flags)) goto L004106b0;
  }
  L00410682: { // 0x410682: 8a0d8585a200 MOV CL,byte ptr [0x00a28585]
    s.cx = with_al(s.cx, m.r8((0x00a28585u)));
  }
  L00410688: { // 0x410688: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0041068a: { // 0x41068a: 7504 JNZ 0x00410690
    if(integer::condition("JNZ",flags)) goto L00410690;
  }
  L0041068c: { // 0x41068c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0041068e: { // 0x41068e: 7538 JNZ 0x004106c8
    if(integer::condition("JNZ",flags)) goto L004106c8;
  }
  L00410690: { // 0x410690: 8b0d8c85a200 MOV ECX,dword ptr [0x00a2858c]
    s.cx = m.r32((0x00a2858cu));
  }
  L00410696: { // 0x410696: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00410698: { // 0x410698: 7e2e JLE 0x004106c8
    if(integer::condition("JLE",flags)) goto L004106c8;
  }
  L0041069a: { // 0x41069a: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0041069c: { // 0x41069c: a17885a200 MOV EAX,[0x00a28578]
    s.ax = m.r32((0x00a28578u));
  }
  L004106a1: { // 0x4106a1: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L004106a3: { // 0x4106a3: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004106a4: { // 0x4106a4: b97885a200 MOV ECX,0xa28578
    s.cx = 0x00a28578u;
  }
  L004106a9: { // 0x4106a9: ff5008 CALL dword ptr [EAX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000008u)),4261548u); flags=s.arithmetic_flags;
  }
  L004106ac: { // 0x4106ac: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004106ae: { // 0x4106ae: 7418 JZ 0x004106c8
    if(integer::condition("JZ",flags)) goto L004106c8;
  }
  L004106b0: { // 0x4106b0: 8b0d8885a200 MOV ECX,dword ptr [0x00a28588]
    s.cx = m.r32((0x00a28588u));
  }
  L004106b6: { // 0x4106b6: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004106b8: { // 0x4106b8: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L004106b9: { // 0x4106b9: 890d8885a200 MOV dword ptr [0x00a28588],ECX
    m.w32((0x00a28588u), s.cx);
  }
  L004106bf: { // 0x4106bf: 8b0d7c85a200 MOV ECX,dword ptr [0x00a2857c]
    s.cx = m.r32((0x00a2857cu));
  }
  L004106c5: { // 0x4106c5: 892c81 MOV dword ptr [ECX + EAX*0x4],EBP
    m.w32((s.cx+(s.ax * 0x00000004u)), s.bp);
  }
  L004106c8: { // 0x4106c8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004106c9: { // 0x4106c9: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L004106cb: { // 0x4106cb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004106cc: { // 0x4106cc: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004106cd: { // 0x4106cd: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004106ce: { // 0x4106ce: 83c444 ADD ESP,0x44
    f.sp = integer::add(f.sp,0x00000044u,32,flags);
  }
  L004106d1: { // 0x4106d1: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00054750(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00454750: { // 0x454750: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L00454754: { // 0x454754: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00454755: { // 0x454755: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00454757: { // 0x454757: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00454759: { // 0x454759: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0045475b: { // 0x45475b: 895604 MOV dword ptr [ESI + 0x4],EDX
    m.w32((s.si+0x00000004u), s.dx);
  }
  L0045475e: { // 0x45475e: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  L00454761: { // 0x454761: c6460c01 MOV byte ptr [ESI + 0xc],0x1
    m.w8((s.si+0x0000000cu), 0x00000001u);
  }
  L00454765: { // 0x454765: 88560d MOV byte ptr [ESI + 0xd],DL
    m.w8((s.si+0x0000000du), (s.dx & 0xffu));
  }
  L00454768: { // 0x454768: c706ac807800 MOV dword ptr [ESI],0x7880ac
    m.w32((s.si), 0x007880acu);
  }
  L0045476e: { // 0x45476e: 7424 JZ 0x00454794
    if(integer::condition("JZ",flags)) goto L00454794;
  }
  L00454770: { // 0x454770: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L00454774: { // 0x454774: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L00454776: { // 0x454776: 7409 JZ 0x00454781
    if(integer::condition("JZ",flags)) goto L00454781;
  }
  L00454778: { // 0x454778: 894e04 MOV dword ptr [ESI + 0x4],ECX
    m.w32((s.si+0x00000004u), s.cx);
  }
  L0045477b: { // 0x45477b: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0045477d: { // 0x45477d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0045477e: { // 0x45477e: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L00454781: { // 0x454781: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L00454784: { // 0x454784: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00454785: { // 0x454785: e8cd913100 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,4540298u); flags=s.arithmetic_flags;
  }
  L0045478a: { // 0x45478a: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0045478d: { // 0x45478d: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  L00454790: { // 0x454790: c6460d01 MOV byte ptr [ESI + 0xd],0x1
    m.w8((s.si+0x0000000du), 0x00000001u);
  }
  L00454794: { // 0x454794: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00454796: { // 0x454796: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00454797: { // 0x454797: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_0006c880(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0046c880: { // 0x46c880: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0046c881: { // 0x46c881: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0046c882: { // 0x46c882: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0046c884: { // 0x46c884: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0046c886: { // 0x46c886: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L0046c889: { // 0x46c889: 895e10 MOV dword ptr [ESI + 0x10],EBX
    m.w32((s.si+0x00000010u), s.bx);
  }
  L0046c88c: { // 0x46c88c: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0046c88e: { // 0x46c88e: 7411 JZ 0x0046c8a1
    if(integer::condition("JZ",flags)) goto L0046c8a1;
  }
  L0046c890: { // 0x46c890: 385e0d CMP byte ptr [ESI + 0xd],BL
    (void)integer::sub(m.r8((s.si+0x0000000du)),(s.bx & 0xffu),8,flags);
  }
  L0046c893: { // 0x46c893: 740c JZ 0x0046c8a1
    if(integer::condition("JZ",flags)) goto L0046c8a1;
  }
  L0046c895: { // 0x46c895: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0046c896: { // 0x46c896: e8e00d3000 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,4638875u); flags=s.arithmetic_flags;
  }
  L0046c89b: { // 0x46c89b: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0046c89e: { // 0x46c89e: 895e04 MOV dword ptr [ESI + 0x4],EBX
    m.w32((s.si+0x00000004u), s.bx);
  }
  L0046c8a1: { // 0x46c8a1: 885e0d MOV byte ptr [ESI + 0xd],BL
    m.w8((s.si+0x0000000du), (s.bx & 0xffu));
  }
  L0046c8a4: { // 0x46c8a4: 895e08 MOV dword ptr [ESI + 0x8],EBX
    m.w32((s.si+0x00000008u), s.bx);
  }
  L0046c8a7: { // 0x46c8a7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0046c8a8: { // 0x46c8a8: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0046c8a9: { // 0x46c8a9: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
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
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,4639834u); flags=s.arithmetic_flags;
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
void f_000f6100(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004f6100: { // 0x4f6100: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004f6101: { // 0x4f6101: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004f6102: { // 0x4f6102: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004f6104: { // 0x4f6104: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L004f6106: { // 0x4f6106: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L004f6109: { // 0x4f6109: 895e10 MOV dword ptr [ESI + 0x10],EBX
    m.w32((s.si+0x00000010u), s.bx);
  }
  L004f610c: { // 0x4f610c: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L004f610e: { // 0x4f610e: 7411 JZ 0x004f6121
    if(integer::condition("JZ",flags)) goto L004f6121;
  }
  L004f6110: { // 0x4f6110: 385e0d CMP byte ptr [ESI + 0xd],BL
    (void)integer::sub(m.r8((s.si+0x0000000du)),(s.bx & 0xffu),8,flags);
  }
  L004f6113: { // 0x4f6113: 740c JZ 0x004f6121
    if(integer::condition("JZ",flags)) goto L004f6121;
  }
  L004f6115: { // 0x4f6115: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004f6116: { // 0x4f6116: e860752700 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,5202203u); flags=s.arithmetic_flags;
  }
  L004f611b: { // 0x4f611b: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L004f611e: { // 0x4f611e: 895e04 MOV dword ptr [ESI + 0x4],EBX
    m.w32((s.si+0x00000004u), s.bx);
  }
  L004f6121: { // 0x4f6121: 885e0d MOV byte ptr [ESI + 0xd],BL
    m.w8((s.si+0x0000000du), (s.bx & 0xffu));
  }
  L004f6124: { // 0x4f6124: 895e08 MOV dword ptr [ESI + 0x8],EBX
    m.w32((s.si+0x00000008u), s.bx);
  }
  L004f6127: { // 0x4f6127: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004f6128: { // 0x4f6128: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004f6129: { // 0x4f6129: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000f7ea0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004f7ea0: { // 0x4f7ea0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L004f7ea4: { // 0x4f7ea4: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004f7ea5: { // 0x4f7ea5: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004f7ea7: { // 0x4f7ea7: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L004f7ea9: { // 0x4f7ea9: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L004f7eab: { // 0x4f7eab: 895604 MOV dword ptr [ESI + 0x4],EDX
    m.w32((s.si+0x00000004u), s.dx);
  }
  L004f7eae: { // 0x4f7eae: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  L004f7eb1: { // 0x4f7eb1: c6460c01 MOV byte ptr [ESI + 0xc],0x1
    m.w8((s.si+0x0000000cu), 0x00000001u);
  }
  L004f7eb5: { // 0x4f7eb5: 88560d MOV byte ptr [ESI + 0xd],DL
    m.w8((s.si+0x0000000du), (s.dx & 0xffu));
  }
  L004f7eb8: { // 0x4f7eb8: c70608df7800 MOV dword ptr [ESI],0x78df08
    m.w32((s.si), 0x0078df08u);
  }
  L004f7ebe: { // 0x4f7ebe: 7424 JZ 0x004f7ee4
    if(integer::condition("JZ",flags)) goto L004f7ee4;
  }
  L004f7ec0: { // 0x4f7ec0: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L004f7ec4: { // 0x4f7ec4: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L004f7ec6: { // 0x4f7ec6: 7409 JZ 0x004f7ed1
    if(integer::condition("JZ",flags)) goto L004f7ed1;
  }
  L004f7ec8: { // 0x4f7ec8: 894e04 MOV dword ptr [ESI + 0x4],ECX
    m.w32((s.si+0x00000004u), s.cx);
  }
  L004f7ecb: { // 0x4f7ecb: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004f7ecd: { // 0x4f7ecd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004f7ece: { // 0x4f7ece: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L004f7ed1: { // 0x4f7ed1: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L004f7ed4: { // 0x4f7ed4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004f7ed5: { // 0x4f7ed5: e87d5a2700 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,5209818u); flags=s.arithmetic_flags;
  }
  L004f7eda: { // 0x4f7eda: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L004f7edd: { // 0x4f7edd: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  L004f7ee0: { // 0x4f7ee0: c6460d01 MOV byte ptr [ESI + 0xd],0x1
    m.w8((s.si+0x0000000du), 0x00000001u);
  }
  L004f7ee4: { // 0x4f7ee4: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004f7ee6: { // 0x4f7ee6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004f7ee7: { // 0x4f7ee7: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_0010a560(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0050a560: { // 0x50a560: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0050a561: { // 0x50a561: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0050a562: { // 0x50a562: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0050a564: { // 0x50a564: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0050a566: { // 0x50a566: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L0050a569: { // 0x50a569: 895e10 MOV dword ptr [ESI + 0x10],EBX
    m.w32((s.si+0x00000010u), s.bx);
  }
  L0050a56c: { // 0x50a56c: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0050a56e: { // 0x50a56e: 7411 JZ 0x0050a581
    if(integer::condition("JZ",flags)) goto L0050a581;
  }
  L0050a570: { // 0x50a570: 385e0d CMP byte ptr [ESI + 0xd],BL
    (void)integer::sub(m.r8((s.si+0x0000000du)),(s.bx & 0xffu),8,flags);
  }
  L0050a573: { // 0x50a573: 740c JZ 0x0050a581
    if(integer::condition("JZ",flags)) goto L0050a581;
  }
  L0050a575: { // 0x50a575: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0050a576: { // 0x50a576: e800312600 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,5285243u); flags=s.arithmetic_flags;
  }
  L0050a57b: { // 0x50a57b: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0050a57e: { // 0x50a57e: 895e04 MOV dword ptr [ESI + 0x4],EBX
    m.w32((s.si+0x00000004u), s.bx);
  }
  L0050a581: { // 0x50a581: 885e0d MOV byte ptr [ESI + 0xd],BL
    m.w8((s.si+0x0000000du), (s.bx & 0xffu));
  }
  L0050a584: { // 0x50a584: 895e08 MOV dword ptr [ESI + 0x8],EBX
    m.w32((s.si+0x00000008u), s.bx);
  }
  L0050a587: { // 0x50a587: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0050a588: { // 0x50a588: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0050a589: { // 0x50a589: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0010acb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0050acb0: { // 0x50acb0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L0050acb4: { // 0x50acb4: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0050acb5: { // 0x50acb5: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0050acb7: { // 0x50acb7: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0050acb9: { // 0x50acb9: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0050acbb: { // 0x50acbb: 895604 MOV dword ptr [ESI + 0x4],EDX
    m.w32((s.si+0x00000004u), s.dx);
  }
  L0050acbe: { // 0x50acbe: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  L0050acc1: { // 0x50acc1: c6460c01 MOV byte ptr [ESI + 0xc],0x1
    m.w8((s.si+0x0000000cu), 0x00000001u);
  }
  L0050acc5: { // 0x50acc5: 88560d MOV byte ptr [ESI + 0xd],DL
    m.w8((s.si+0x0000000du), (s.dx & 0xffu));
  }
  L0050acc8: { // 0x50acc8: c7065ceb7800 MOV dword ptr [ESI],0x78eb5c
    m.w32((s.si), 0x0078eb5cu);
  }
  L0050acce: { // 0x50acce: 7424 JZ 0x0050acf4
    if(integer::condition("JZ",flags)) goto L0050acf4;
  }
  L0050acd0: { // 0x50acd0: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L0050acd4: { // 0x50acd4: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L0050acd6: { // 0x50acd6: 7409 JZ 0x0050ace1
    if(integer::condition("JZ",flags)) goto L0050ace1;
  }
  L0050acd8: { // 0x50acd8: 894e04 MOV dword ptr [ESI + 0x4],ECX
    m.w32((s.si+0x00000004u), s.cx);
  }
  L0050acdb: { // 0x50acdb: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0050acdd: { // 0x50acdd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0050acde: { // 0x50acde: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0050ace1: { // 0x50ace1: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L0050ace4: { // 0x50ace4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0050ace5: { // 0x50ace5: e86d2c2600 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,5287146u); flags=s.arithmetic_flags;
  }
  L0050acea: { // 0x50acea: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0050aced: { // 0x50aced: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  L0050acf0: { // 0x50acf0: c6460d01 MOV byte ptr [ESI + 0xd],0x1
    m.w8((s.si+0x0000000du), 0x00000001u);
  }
  L0050acf4: { // 0x50acf4: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0050acf6: { // 0x50acf6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0050acf7: { // 0x50acf7: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_001cde80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005cde80: { // 0x5cde80: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L005cde84: { // 0x5cde84: 83ec1c SUB ESP,0x1c
    f.sp = integer::sub(f.sp,0x0000001cu,32,flags);
  }
  L005cde87: { // 0x5cde87: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005cde88: { // 0x5cde88: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005cde89: { // 0x5cde89: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L005cde8b: { // 0x5cde8b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005cde8c: { // 0x5cde8c: e8ef26e4ff CALL 0x00410580
    s.arithmetic_flags=flags; invoke(m,s,f,0x00410580u,6086289u); flags=s.arithmetic_flags;
  }
  L005cde91: { // 0x5cde91: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L005cde93: { // 0x5cde93: 8d85c8000000 LEA EAX,[EBP + 0xc8]
    s.ax = (s.bp+0x000000c8u);
  }
  L005cde99: { // 0x5cde99: 889d98000000 MOV byte ptr [EBP + 0x98],BL
    m.w8((s.bp+0x00000098u), (s.bx & 0xffu));
  }
  L005cde9f: { // 0x5cde9f: 889d99000000 MOV byte ptr [EBP + 0x99],BL
    m.w8((s.bp+0x00000099u), (s.bx & 0xffu));
  }
  L005cdea5: { // 0x5cdea5: 889d9a000000 MOV byte ptr [EBP + 0x9a],BL
    m.w8((s.bp+0x0000009au), (s.bx & 0xffu));
  }
  L005cdeab: { // 0x5cdeab: 899d9c000000 MOV dword ptr [EBP + 0x9c],EBX
    m.w32((s.bp+0x0000009cu), s.bx);
  }
  L005cdeb1: { // 0x5cdeb1: 899da0000000 MOV dword ptr [EBP + 0xa0],EBX
    m.w32((s.bp+0x000000a0u), s.bx);
  }
  L005cdeb7: { // 0x5cdeb7: 899da4000000 MOV dword ptr [EBP + 0xa4],EBX
    m.w32((s.bp+0x000000a4u), s.bx);
  }
  L005cdebd: { // 0x5cdebd: 889da8000000 MOV byte ptr [EBP + 0xa8],BL
    m.w8((s.bp+0x000000a8u), (s.bx & 0xffu));
  }
  L005cdec3: { // 0x5cdec3: 899dac000000 MOV dword ptr [EBP + 0xac],EBX
    m.w32((s.bp+0x000000acu), s.bx);
  }
  L005cdec9: { // 0x5cdec9: 899db0000000 MOV dword ptr [EBP + 0xb0],EBX
    m.w32((s.bp+0x000000b0u), s.bx);
  }
  L005cdecf: { // 0x5cdecf: 899db4000000 MOV dword ptr [EBP + 0xb4],EBX
    m.w32((s.bp+0x000000b4u), s.bx);
  }
  L005cded5: { // 0x5cded5: 899db8000000 MOV dword ptr [EBP + 0xb8],EBX
    m.w32((s.bp+0x000000b8u), s.bx);
  }
  L005cdedb: { // 0x5cdedb: 899dbc000000 MOV dword ptr [EBP + 0xbc],EBX
    m.w32((s.bp+0x000000bcu), s.bx);
  }
  L005cdee1: { // 0x5cdee1: 899dc0000000 MOV dword ptr [EBP + 0xc0],EBX
    m.w32((s.bp+0x000000c0u), s.bx);
  }
  L005cdee7: { // 0x5cdee7: 899dc4000000 MOV dword ptr [EBP + 0xc4],EBX
    m.w32((s.bp+0x000000c4u), s.bx);
  }
  L005cdeed: { // 0x5cdeed: b90f000000 MOV ECX,0xf
    s.cx = 0x0000000fu;
  }
  L005cdef2: { // 0x5cdef2: 8918 MOV dword ptr [EAX],EBX
    m.w32((s.ax), s.bx);
  }
  L005cdef4: { // 0x5cdef4: 895804 MOV dword ptr [EAX + 0x4],EBX
    m.w32((s.ax+0x00000004u), s.bx);
  }
  L005cdef7: { // 0x5cdef7: 83c008 ADD EAX,0x8
    s.ax = integer::add(s.ax,0x00000008u,32,flags);
  }
  L005cdefa: { // 0x5cdefa: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L005cdefb: { // 0x5cdefb: 75f5 JNZ 0x005cdef2
    if(integer::condition("JNZ",flags)) goto L005cdef2;
  }
  L005cdefd: { // 0x5cdefd: 8d8540010000 LEA EAX,[EBP + 0x140]
    s.ax = (s.bp+0x00000140u);
  }
  L005cdf03: { // 0x5cdf03: b90f000000 MOV ECX,0xf
    s.cx = 0x0000000fu;
  }
  L005cdf08: { // 0x5cdf08: 8918 MOV dword ptr [EAX],EBX
    m.w32((s.ax), s.bx);
  }
  L005cdf0a: { // 0x5cdf0a: 895804 MOV dword ptr [EAX + 0x4],EBX
    m.w32((s.ax+0x00000004u), s.bx);
  }
  L005cdf0d: { // 0x5cdf0d: 83c008 ADD EAX,0x8
    s.ax = integer::add(s.ax,0x00000008u,32,flags);
  }
  L005cdf10: { // 0x5cdf10: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L005cdf11: { // 0x5cdf11: 75f5 JNZ 0x005cdf08
    if(integer::condition("JNZ",flags)) goto L005cdf08;
  }
  L005cdf13: { // 0x5cdf13: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005cdf14: { // 0x5cdf14: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005cdf15: { // 0x5cdf15: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L005cdf18: { // 0x5cdf18: 8dbdc8010000 LEA EDI,[EBP + 0x1c8]
    s.di = (s.bp+0x000001c8u);
  }
  L005cdf1e: { // 0x5cdf1e: 889db8010000 MOV byte ptr [EBP + 0x1b8],BL
    m.w8((s.bp+0x000001b8u), (s.bx & 0xffu));
  }
  L005cdf24: { // 0x5cdf24: 899dbc010000 MOV dword ptr [EBP + 0x1bc],EBX
    m.w32((s.bp+0x000001bcu), s.bx);
  }
  L005cdf2a: { // 0x5cdf2a: 8985c0010000 MOV dword ptr [EBP + 0x1c0],EAX
    m.w32((s.bp+0x000001c0u), s.ax);
  }
  L005cdf30: { // 0x5cdf30: 8985c4010000 MOV dword ptr [EBP + 0x1c4],EAX
    m.w32((s.bp+0x000001c4u), s.ax);
  }
  L005cdf36: { // 0x5cdf36: 881f MOV byte ptr [EDI],BL
    m.w8((s.di), (s.bx & 0xffu));
  }
  L005cdf38: { // 0x5cdf38: 889de1010000 MOV byte ptr [EBP + 0x1e1],BL
    m.w8((s.bp+0x000001e1u), (s.bx & 0xffu));
  }
  L005cdf3e: { // 0x5cdf3e: 889de2010000 MOV byte ptr [EBP + 0x1e2],BL
    m.w8((s.bp+0x000001e2u), (s.bx & 0xffu));
  }
  L005cdf44: { // 0x5cdf44: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L005cdf46: { // 0x5cdf46: 889de3010000 MOV byte ptr [EBP + 0x1e3],BL
    m.w8((s.bp+0x000001e3u), (s.bx & 0xffu));
  }
  L005cdf4c: { // 0x5cdf4c: 8885fe010000 MOV byte ptr [EBP + 0x1fe],AL
    m.w8((s.bp+0x000001feu), (s.ax & 0xffu));
  }
  L005cdf52: { // 0x5cdf52: 888500020000 MOV byte ptr [EBP + 0x200],AL
    m.w8((s.bp+0x00000200u), (s.ax & 0xffu));
  }
  L005cdf58: { // 0x5cdf58: 888501020000 MOV byte ptr [EBP + 0x201],AL
    m.w8((s.bp+0x00000201u), (s.ax & 0xffu));
  }
  L005cdf5e: { // 0x5cdf5e: 888505020000 MOV byte ptr [EBP + 0x205],AL
    m.w8((s.bp+0x00000205u), (s.ax & 0xffu));
  }
  L005cdf64: { // 0x5cdf64: b080 MOV AL,0x80
    s.ax = with_al(s.ax, 0x00000080u);
  }
  L005cdf66: { // 0x5cdf66: 889dfc010000 MOV byte ptr [EBP + 0x1fc],BL
    m.w8((s.bp+0x000001fcu), (s.bx & 0xffu));
  }
  L005cdf6c: { // 0x5cdf6c: 889dfd010000 MOV byte ptr [EBP + 0x1fd],BL
    m.w8((s.bp+0x000001fdu), (s.bx & 0xffu));
  }
  L005cdf72: { // 0x5cdf72: 889dff010000 MOV byte ptr [EBP + 0x1ff],BL
    m.w8((s.bp+0x000001ffu), (s.bx & 0xffu));
  }
  L005cdf78: { // 0x5cdf78: 889d02020000 MOV byte ptr [EBP + 0x202],BL
    m.w8((s.bp+0x00000202u), (s.bx & 0xffu));
  }
  L005cdf7e: { // 0x5cdf7e: 889d03020000 MOV byte ptr [EBP + 0x203],BL
    m.w8((s.bp+0x00000203u), (s.bx & 0xffu));
  }
  L005cdf84: { // 0x5cdf84: 889d04020000 MOV byte ptr [EBP + 0x204],BL
    m.w8((s.bp+0x00000204u), (s.bx & 0xffu));
  }
  L005cdf8a: { // 0x5cdf8a: 889d06020000 MOV byte ptr [EBP + 0x206],BL
    m.w8((s.bp+0x00000206u), (s.bx & 0xffu));
  }
  L005cdf90: { // 0x5cdf90: 889d07020000 MOV byte ptr [EBP + 0x207],BL
    m.w8((s.bp+0x00000207u), (s.bx & 0xffu));
  }
  L005cdf96: { // 0x5cdf96: 889d08020000 MOV byte ptr [EBP + 0x208],BL
    m.w8((s.bp+0x00000208u), (s.bx & 0xffu));
  }
  L005cdf9c: { // 0x5cdf9c: 889d09020000 MOV byte ptr [EBP + 0x209],BL
    m.w8((s.bp+0x00000209u), (s.bx & 0xffu));
  }
  L005cdfa2: { // 0x5cdfa2: 889d0a020000 MOV byte ptr [EBP + 0x20a],BL
    m.w8((s.bp+0x0000020au), (s.bx & 0xffu));
  }
  L005cdfa8: { // 0x5cdfa8: 88850b020000 MOV byte ptr [EBP + 0x20b],AL
    m.w8((s.bp+0x0000020bu), (s.ax & 0xffu));
  }
  L005cdfae: { // 0x5cdfae: 88850c020000 MOV byte ptr [EBP + 0x20c],AL
    m.w8((s.bp+0x0000020cu), (s.ax & 0xffu));
  }
  L005cdfb4: { // 0x5cdfb4: 88850d020000 MOV byte ptr [EBP + 0x20d],AL
    m.w8((s.bp+0x0000020du), (s.ax & 0xffu));
  }
  L005cdfba: { // 0x5cdfba: c7851002000010000000 MOV dword ptr [EBP + 0x210],0x10
    m.w32((s.bp+0x00000210u), 0x00000010u);
  }
  L005cdfc4: { // 0x5cdfc4: 899d14020000 MOV dword ptr [EBP + 0x214],EBX
    m.w32((s.bp+0x00000214u), s.bx);
  }
  L005cdfca: { // 0x5cdfca: 899d18020000 MOV dword ptr [EBP + 0x218],EBX
    m.w32((s.bp+0x00000218u), s.bx);
  }
  L005cdfd0: { // 0x5cdfd0: 899d1c020000 MOV dword ptr [EBP + 0x21c],EBX
    m.w32((s.bp+0x0000021cu), s.bx);
  }
  L005cdfd6: { // 0x5cdfd6: 889d20020000 MOV byte ptr [EBP + 0x220],BL
    m.w8((s.bp+0x00000220u), (s.bx & 0xffu));
  }
  L005cdfdc: { // 0x5cdfdc: 899d24020000 MOV dword ptr [EBP + 0x224],EBX
    m.w32((s.bp+0x00000224u), s.bx);
  }
  L005cdfe2: { // 0x5cdfe2: 899d28020000 MOV dword ptr [EBP + 0x228],EBX
    m.w32((s.bp+0x00000228u), s.bx);
  }
  L005cdfe8: { // 0x5cdfe8: 899d2c020000 MOV dword ptr [EBP + 0x22c],EBX
    m.w32((s.bp+0x0000022cu), s.bx);
  }
  L005cdfee: { // 0x5cdfee: 899d30020000 MOV dword ptr [EBP + 0x230],EBX
    m.w32((s.bp+0x00000230u), s.bx);
  }
  L005cdff4: { // 0x5cdff4: 889d34020000 MOV byte ptr [EBP + 0x234],BL
    m.w8((s.bp+0x00000234u), (s.bx & 0xffu));
  }
  L005cdffa: { // 0x5cdffa: 899d38020000 MOV dword ptr [EBP + 0x238],EBX
    m.w32((s.bp+0x00000238u), s.bx);
  }
  L005ce000: { // 0x5ce000: 8d7524 LEA ESI,[EBP + 0x24]
    s.si = (s.bp+0x00000024u);
  }
  L005ce003: { // 0x5ce003: 899d3c020000 MOV dword ptr [EBP + 0x23c],EBX
    m.w32((s.bp+0x0000023cu), s.bx);
  }
  L005ce009: { // 0x5ce009: 899d40020000 MOV dword ptr [EBP + 0x240],EBX
    m.w32((s.bp+0x00000240u), s.bx);
  }
  L005ce00f: { // 0x5ce00f: 899d44020000 MOV dword ptr [EBP + 0x244],EBX
    m.w32((s.bp+0x00000244u), s.bx);
  }
  L005ce015: { // 0x5ce015: 889d48020000 MOV byte ptr [EBP + 0x248],BL
    m.w8((s.bp+0x00000248u), (s.bx & 0xffu));
  }
  L005ce01b: { // 0x5ce01b: 899d4c020000 MOV dword ptr [EBP + 0x24c],EBX
    m.w32((s.bp+0x0000024cu), s.bx);
  }
  L005ce021: { // 0x5ce021: 899d50020000 MOV dword ptr [EBP + 0x250],EBX
    m.w32((s.bp+0x00000250u), s.bx);
  }
  L005ce027: { // 0x5ce027: 899d54020000 MOV dword ptr [EBP + 0x254],EBX
    m.w32((s.bp+0x00000254u), s.bx);
  }
  L005ce02d: { // 0x5ce02d: 899d58020000 MOV dword ptr [EBP + 0x258],EBX
    m.w32((s.bp+0x00000258u), s.bx);
  }
  L005ce033: { // 0x5ce033: 889d5c020000 MOV byte ptr [EBP + 0x25c],BL
    m.w8((s.bp+0x0000025cu), (s.bx & 0xffu));
  }
  L005ce039: { // 0x5ce039: 899d60020000 MOV dword ptr [EBP + 0x260],EBX
    m.w32((s.bp+0x00000260u), s.bx);
  }
  L005ce03f: { // 0x5ce03f: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  L005ce041: { // 0x5ce041: c74500b8267900 MOV dword ptr [EBP],0x7926b8
    m.w32((s.bp), 0x007926b8u);
  }
  L005ce048: { // 0x5ce048: c745049c267900 MOV dword ptr [EBP + 0x4],0x79269c
    m.w32((s.bp+0x00000004u), 0x0079269cu);
  }
  L005ce04f: { // 0x5ce04f: c7450894267900 MOV dword ptr [EBP + 0x8],0x792694
    m.w32((s.bp+0x00000008u), 0x00792694u);
  }
  L005ce056: { // 0x5ce056: c7450c8c267900 MOV dword ptr [EBP + 0xc],0x79268c
    m.w32((s.bp+0x0000000cu), 0x0079268cu);
  }
  L005ce05d: { // 0x5ce05d: 7408 JZ 0x005ce067
    if(integer::condition("JZ",flags)) goto L005ce067;
  }
  L005ce05f: { // 0x5ce05f: b906000000 MOV ECX,0x6
    s.cx = 0x00000006u;
  }
  L005ce064: { // 0x5ce064: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L005ce066: { // 0x5ce066: a4 MOVSB ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::single);
  }
  L005ce067: { // 0x5ce067: b9a4488200 MOV ECX,0x8248a4
    s.cx = 0x008248a4u;
  }
  L005ce06c: { // 0x5ce06c: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005ce06e: { // 0x5ce06e: 7506 JNZ 0x005ce076
    if(integer::condition("JNZ",flags)) goto L005ce076;
  }
  L005ce070: { // 0x5ce070: 885c2410 MOV byte ptr [ESP + 0x10],BL
    m.w8((f.sp+0x00000010u), (s.bx & 0xffu));
  }
  L005ce074: { // 0x5ce074: eb18 JMP 0x005ce08e
    goto L005ce08e;
  }
  L005ce076: { // 0x5ce076: 6a18 PUSH 0x18
    f.push(m,0x00000018u);
  }
  L005ce078: { // 0x5ce078: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  L005ce07c: { // 0x5ce07c: 68a4488200 PUSH 0x8248a4
    f.push(m,0x008248a4u);
  }
  L005ce081: { // 0x5ce081: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005ce082: { // 0x5ce082: e889fc1900 CALL 0x0076dd10
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076dd10u,6086791u); flags=s.arithmetic_flags;
  }
  L005ce087: { // 0x5ce087: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L005ce08a: { // 0x5ce08a: 885c2428 MOV byte ptr [ESP + 0x28],BL
    m.w8((f.sp+0x00000028u), (s.bx & 0xffu));
  }
  L005ce08e: { // 0x5ce08e: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L005ce092: { // 0x5ce092: 8dbde3010000 LEA EDI,[EBP + 0x1e3]
    s.di = (s.bp+0x000001e3u);
  }
  L005ce098: { // 0x5ce098: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L005ce09a: { // 0x5ce09a: 740c JZ 0x005ce0a8
    if(integer::condition("JZ",flags)) goto L005ce0a8;
  }
  L005ce09c: { // 0x5ce09c: b906000000 MOV ECX,0x6
    s.cx = 0x00000006u;
  }
  L005ce0a1: { // 0x5ce0a1: 8d742410 LEA ESI,[ESP + 0x10]
    s.si = (f.sp+0x00000010u);
  }
  L005ce0a5: { // 0x5ce0a5: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L005ce0a7: { // 0x5ce0a7: a4 MOVSB ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::single);
  }
  L005ce0a8: { // 0x5ce0a8: a100aba500 MOV EAX,[0x00a5ab00]
    s.ax = m.r32((0x00a5ab00u));
  }
  L005ce0ad: { // 0x5ce0ad: 8b0d08aba500 MOV ECX,dword ptr [0x00a5ab08]
    s.cx = m.r32((0x00a5ab08u));
  }
  L005ce0b3: { // 0x5ce0b3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005ce0b4: { // 0x5ce0b4: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L005ce0b6: { // 0x5ce0b6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005ce0b7: { // 0x5ce0b7: 7c2c JL 0x005ce0e5
    if(integer::condition("JL",flags)) goto L005ce0e5;
  }
  L005ce0b9: { // 0x5ce0b9: 381d05aba500 CMP byte ptr [0x00a5ab05],BL
    (void)integer::sub(m.r8((0x00a5ab05u)),(s.bx & 0xffu),8,flags);
  }
  L005ce0bf: { // 0x5ce0bf: 7504 JNZ 0x005ce0c5
    if(integer::condition("JNZ",flags)) goto L005ce0c5;
  }
  L005ce0c1: { // 0x5ce0c1: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L005ce0c3: { // 0x5ce0c3: 7538 JNZ 0x005ce0fd
    if(integer::condition("JNZ",flags)) goto L005ce0fd;
  }
  L005ce0c5: { // 0x5ce0c5: 8b0d0caba500 MOV ECX,dword ptr [0x00a5ab0c]
    s.cx = m.r32((0x00a5ab0cu));
  }
  L005ce0cb: { // 0x5ce0cb: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L005ce0cd: { // 0x5ce0cd: 7e2e JLE 0x005ce0fd
    if(integer::condition("JLE",flags)) goto L005ce0fd;
  }
  L005ce0cf: { // 0x5ce0cf: 8b15f8aaa500 MOV EDX,dword ptr [0x00a5aaf8]
    s.dx = m.r32((0x00a5aaf8u));
  }
  L005ce0d5: { // 0x5ce0d5: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L005ce0d7: { // 0x5ce0d7: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005ce0d8: { // 0x5ce0d8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005ce0d9: { // 0x5ce0d9: b9f8aaa500 MOV ECX,0xa5aaf8
    s.cx = 0x00a5aaf8u;
  }
  L005ce0de: { // 0x5ce0de: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),6086881u); flags=s.arithmetic_flags;
  }
  L005ce0e1: { // 0x5ce0e1: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005ce0e3: { // 0x5ce0e3: 7418 JZ 0x005ce0fd
    if(integer::condition("JZ",flags)) goto L005ce0fd;
  }
  L005ce0e5: { // 0x5ce0e5: 8b0d08aba500 MOV ECX,dword ptr [0x00a5ab08]
    s.cx = m.r32((0x00a5ab08u));
  }
  L005ce0eb: { // 0x5ce0eb: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L005ce0ed: { // 0x5ce0ed: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L005ce0ee: { // 0x5ce0ee: 890d08aba500 MOV dword ptr [0x00a5ab08],ECX
    m.w32((0x00a5ab08u), s.cx);
  }
  L005ce0f4: { // 0x5ce0f4: 8b0dfcaaa500 MOV ECX,dword ptr [0x00a5aafc]
    s.cx = m.r32((0x00a5aafcu));
  }
  L005ce0fa: { // 0x5ce0fa: 892c81 MOV dword ptr [ECX + EAX*0x4],EBP
    m.w32((s.cx+(s.ax * 0x00000004u)), s.bp);
  }
  L005ce0fd: { // 0x5ce0fd: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L005ce0ff: { // 0x5ce0ff: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005ce100: { // 0x5ce100: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005ce101: { // 0x5ce101: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L005ce104: { // 0x5ce104: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00249b90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00649b90: { // 0x649b90: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00649b91: { // 0x649b91: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00649b92: { // 0x649b92: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00649b94: { // 0x649b94: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00649b96: { // 0x649b96: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L00649b99: { // 0x649b99: 895e10 MOV dword ptr [ESI + 0x10],EBX
    m.w32((s.si+0x00000010u), s.bx);
  }
  L00649b9c: { // 0x649b9c: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00649b9e: { // 0x649b9e: 7411 JZ 0x00649bb1
    if(integer::condition("JZ",flags)) goto L00649bb1;
  }
  L00649ba0: { // 0x649ba0: 385e0d CMP byte ptr [ESI + 0xd],BL
    (void)integer::sub(m.r8((s.si+0x0000000du)),(s.bx & 0xffu),8,flags);
  }
  L00649ba3: { // 0x649ba3: 740c JZ 0x00649bb1
    if(integer::condition("JZ",flags)) goto L00649bb1;
  }
  L00649ba5: { // 0x649ba5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00649ba6: { // 0x649ba6: e8d03a1200 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,6593451u); flags=s.arithmetic_flags;
  }
  L00649bab: { // 0x649bab: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00649bae: { // 0x649bae: 895e04 MOV dword ptr [ESI + 0x4],EBX
    m.w32((s.si+0x00000004u), s.bx);
  }
  L00649bb1: { // 0x649bb1: 885e0d MOV byte ptr [ESI + 0xd],BL
    m.w8((s.si+0x0000000du), (s.bx & 0xffu));
  }
  L00649bb4: { // 0x649bb4: 895e08 MOV dword ptr [ESI + 0x8],EBX
    m.w32((s.si+0x00000008u), s.bx);
  }
  L00649bb7: { // 0x649bb7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00649bb8: { // 0x649bb8: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00649bb9: { // 0x649bb9: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0024ba00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0064ba00: { // 0x64ba00: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L0064ba04: { // 0x64ba04: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0064ba05: { // 0x64ba05: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0064ba07: { // 0x64ba07: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0064ba09: { // 0x64ba09: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0064ba0b: { // 0x64ba0b: 895604 MOV dword ptr [ESI + 0x4],EDX
    m.w32((s.si+0x00000004u), s.dx);
  }
  L0064ba0e: { // 0x64ba0e: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  L0064ba11: { // 0x64ba11: c6460c01 MOV byte ptr [ESI + 0xc],0x1
    m.w8((s.si+0x0000000cu), 0x00000001u);
  }
  L0064ba15: { // 0x64ba15: 88560d MOV byte ptr [ESI + 0xd],DL
    m.w8((s.si+0x0000000du), (s.dx & 0xffu));
  }
  L0064ba18: { // 0x64ba18: c706c03f7900 MOV dword ptr [ESI],0x793fc0
    m.w32((s.si), 0x00793fc0u);
  }
  L0064ba1e: { // 0x64ba1e: 7424 JZ 0x0064ba44
    if(integer::condition("JZ",flags)) goto L0064ba44;
  }
  L0064ba20: { // 0x64ba20: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L0064ba24: { // 0x64ba24: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L0064ba26: { // 0x64ba26: 7409 JZ 0x0064ba31
    if(integer::condition("JZ",flags)) goto L0064ba31;
  }
  L0064ba28: { // 0x64ba28: 894e04 MOV dword ptr [ESI + 0x4],ECX
    m.w32((s.si+0x00000004u), s.cx);
  }
  L0064ba2b: { // 0x64ba2b: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0064ba2d: { // 0x64ba2d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0064ba2e: { // 0x64ba2e: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0064ba31: { // 0x64ba31: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L0064ba34: { // 0x64ba34: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0064ba35: { // 0x64ba35: e81d1f1200 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,6601274u); flags=s.arithmetic_flags;
  }
  L0064ba3a: { // 0x64ba3a: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0064ba3d: { // 0x64ba3d: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  L0064ba40: { // 0x64ba40: c6460d01 MOV byte ptr [ESI + 0xd],0x1
    m.w8((s.si+0x0000000du), 0x00000001u);
  }
  L0064ba44: { // 0x64ba44: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0064ba46: { // 0x64ba46: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0064ba47: { // 0x64ba47: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_0036dd10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0076dd10: { // 0x76dd10: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L0076dd14: { // 0x76dd14: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0076dd15: { // 0x76dd15: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0076dd17: { // 0x76dd17: 747a JZ 0x0076dd93
    if(integer::condition("JZ",flags)) goto L0076dd93;
  }
  L0076dd19: { // 0x76dd19: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0076dd1a: { // 0x76dd1a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0076dd1b: { // 0x76dd1b: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0076dd1d: { // 0x76dd1d: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L0076dd21: { // 0x76dd21: f7c603000000 TEST ESI,0x3
    (void)integer::logical((s.si)&(0x00000003u),32,flags);
  }
  L0076dd27: { // 0x76dd27: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L0076dd2b: { // 0x76dd2b: 7507 JNZ 0x0076dd34
    if(integer::condition("JNZ",flags)) goto L0076dd34;
  }
  L0076dd2d: { // 0x76dd2d: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L0076dd30: { // 0x76dd30: 756f JNZ 0x0076dda1
    if(integer::condition("JNZ",flags)) goto L0076dda1;
  }
  L0076dd32: { // 0x76dd32: eb21 JMP 0x0076dd55
    goto L0076dd55;
  }
  L0076dd34: { // 0x76dd34: 8a06 MOV AL,byte ptr [ESI]
    s.ax = with_al(s.ax, m.r8((s.si)));
  }
  L0076dd36: { // 0x76dd36: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0076dd37: { // 0x76dd37: 8807 MOV byte ptr [EDI],AL
    m.w8((s.di), (s.ax & 0xffu));
  }
  L0076dd39: { // 0x76dd39: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0076dd3a: { // 0x76dd3a: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0076dd3b: { // 0x76dd3b: 7425 JZ 0x0076dd62
    if(integer::condition("JZ",flags)) goto L0076dd62;
  }
  L0076dd3d: { // 0x76dd3d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0076dd3f: { // 0x76dd3f: 7429 JZ 0x0076dd6a
    if(integer::condition("JZ",flags)) goto L0076dd6a;
  }
  L0076dd41: { // 0x76dd41: f7c603000000 TEST ESI,0x3
    (void)integer::logical((s.si)&(0x00000003u),32,flags);
  }
  L0076dd47: { // 0x76dd47: 75eb JNZ 0x0076dd34
    if(integer::condition("JNZ",flags)) goto L0076dd34;
  }
  L0076dd49: { // 0x76dd49: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0076dd4b: { // 0x76dd4b: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L0076dd4e: { // 0x76dd4e: 7551 JNZ 0x0076dda1
    if(integer::condition("JNZ",flags)) goto L0076dda1;
  }
  L0076dd50: { // 0x76dd50: 83e303 AND EBX,0x3
    s.bx = integer::logical((s.bx)&(0x00000003u),32,flags);
  }
  L0076dd53: { // 0x76dd53: 740d JZ 0x0076dd62
    if(integer::condition("JZ",flags)) goto L0076dd62;
  }
  L0076dd55: { // 0x76dd55: 8a06 MOV AL,byte ptr [ESI]
    s.ax = with_al(s.ax, m.r8((s.si)));
  }
  L0076dd57: { // 0x76dd57: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0076dd58: { // 0x76dd58: 8807 MOV byte ptr [EDI],AL
    m.w8((s.di), (s.ax & 0xffu));
  }
  L0076dd5a: { // 0x76dd5a: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0076dd5b: { // 0x76dd5b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0076dd5d: { // 0x76dd5d: 742f JZ 0x0076dd8e
    if(integer::condition("JZ",flags)) goto L0076dd8e;
  }
  L0076dd5f: { // 0x76dd5f: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L0076dd60: { // 0x76dd60: 75f3 JNZ 0x0076dd55
    if(integer::condition("JNZ",flags)) goto L0076dd55;
  }
  L0076dd62: { // 0x76dd62: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0076dd66: { // 0x76dd66: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0076dd67: { // 0x76dd67: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076dd68: { // 0x76dd68: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076dd69: { // 0x76dd69: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076dd6a: { // 0x76dd6a: f7c703000000 TEST EDI,0x3
    (void)integer::logical((s.di)&(0x00000003u),32,flags);
  }
  L0076dd70: { // 0x76dd70: 7412 JZ 0x0076dd84
    if(integer::condition("JZ",flags)) goto L0076dd84;
  }
  L0076dd72: { // 0x76dd72: 8807 MOV byte ptr [EDI],AL
    m.w8((s.di), (s.ax & 0xffu));
  }
  L0076dd74: { // 0x76dd74: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0076dd75: { // 0x76dd75: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0076dd76: { // 0x76dd76: 0f848a000000 JZ 0x0076de06
    if(integer::condition("JZ",flags)) goto L0076de06;
  }
  L0076dd7c: { // 0x76dd7c: f7c703000000 TEST EDI,0x3
    (void)integer::logical((s.di)&(0x00000003u),32,flags);
  }
  L0076dd82: { // 0x76dd82: 75ee JNZ 0x0076dd72
    if(integer::condition("JNZ",flags)) goto L0076dd72;
  }
  L0076dd84: { // 0x76dd84: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0076dd86: { // 0x76dd86: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L0076dd89: { // 0x76dd89: 756c JNZ 0x0076ddf7
    if(integer::condition("JNZ",flags)) goto L0076ddf7;
  }
  L0076dd8b: { // 0x76dd8b: 8807 MOV byte ptr [EDI],AL
    m.w8((s.di), (s.ax & 0xffu));
  }
  L0076dd8d: { // 0x76dd8d: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0076dd8e: { // 0x76dd8e: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L0076dd8f: { // 0x76dd8f: 75fa JNZ 0x0076dd8b
    if(integer::condition("JNZ",flags)) goto L0076dd8b;
  }
  L0076dd91: { // 0x76dd91: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0076dd92: { // 0x76dd92: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076dd93: { // 0x76dd93: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L0076dd97: { // 0x76dd97: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076dd98: { // 0x76dd98: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076dd99: { // 0x76dd99: 8917 MOV dword ptr [EDI],EDX
    m.w32((s.di), s.dx);
  }
  L0076dd9b: { // 0x76dd9b: 83c704 ADD EDI,0x4
    s.di = integer::add(s.di,0x00000004u,32,flags);
  }
  L0076dd9e: { // 0x76dd9e: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0076dd9f: { // 0x76dd9f: 74af JZ 0x0076dd50
    if(integer::condition("JZ",flags)) goto L0076dd50;
  }
  L0076dda1: { // 0x76dda1: bafffefe7e MOV EDX,0x7efefeff
    s.dx = 0x7efefeffu;
  }
  L0076dda6: { // 0x76dda6: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0076dda8: { // 0x76dda8: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L0076ddaa: { // 0x76ddaa: 83f0ff XOR EAX,0xffffffff
    s.ax = integer::logical((s.ax)^(0xffffffffu),32,flags);
  }
  L0076ddad: { // 0x76ddad: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L0076ddaf: { // 0x76ddaf: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0076ddb1: { // 0x76ddb1: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  L0076ddb4: { // 0x76ddb4: a900010181 TEST EAX,0x81010100
    (void)integer::logical((s.ax)&(0x81010100u),32,flags);
  }
  L0076ddb9: { // 0x76ddb9: 74de JZ 0x0076dd99
    if(integer::condition("JZ",flags)) goto L0076dd99;
  }
  L0076ddbb: { // 0x76ddbb: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L0076ddbd: { // 0x76ddbd: 742c JZ 0x0076ddeb
    if(integer::condition("JZ",flags)) goto L0076ddeb;
  }
  L0076ddbf: { // 0x76ddbf: 84f6 TEST DH,DH
    (void)integer::logical((((s.dx >> 8) & 0xffu))&(((s.dx >> 8) & 0xffu)),8,flags);
  }
  L0076ddc1: { // 0x76ddc1: 741e JZ 0x0076dde1
    if(integer::condition("JZ",flags)) goto L0076dde1;
  }
  L0076ddc3: { // 0x76ddc3: f7c20000ff00 TEST EDX,0xff0000
    (void)integer::logical((s.dx)&(0x00ff0000u),32,flags);
  }
  L0076ddc9: { // 0x76ddc9: 740c JZ 0x0076ddd7
    if(integer::condition("JZ",flags)) goto L0076ddd7;
  }
  L0076ddcb: { // 0x76ddcb: f7c2000000ff TEST EDX,0xff000000
    (void)integer::logical((s.dx)&(0xff000000u),32,flags);
  }
  L0076ddd1: { // 0x76ddd1: 75c6 JNZ 0x0076dd99
    if(integer::condition("JNZ",flags)) goto L0076dd99;
  }
  L0076ddd3: { // 0x76ddd3: 8917 MOV dword ptr [EDI],EDX
    m.w32((s.di), s.dx);
  }
  L0076ddd5: { // 0x76ddd5: eb18 JMP 0x0076ddef
    goto L0076ddef;
  }
  L0076ddd7: { // 0x76ddd7: 81e2ffff0000 AND EDX,0xffff
    s.dx = integer::logical((s.dx)&(0x0000ffffu),32,flags);
  }
  L0076dddd: { // 0x76dddd: 8917 MOV dword ptr [EDI],EDX
    m.w32((s.di), s.dx);
  }
  L0076dddf: { // 0x76dddf: eb0e JMP 0x0076ddef
    goto L0076ddef;
  }
  L0076dde1: { // 0x76dde1: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0076dde7: { // 0x76dde7: 8917 MOV dword ptr [EDI],EDX
    m.w32((s.di), s.dx);
  }
  L0076dde9: { // 0x76dde9: eb04 JMP 0x0076ddef
    goto L0076ddef;
  }
  L0076ddeb: { // 0x76ddeb: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0076dded: { // 0x76dded: 8917 MOV dword ptr [EDI],EDX
    m.w32((s.di), s.dx);
  }
  L0076ddef: { // 0x76ddef: 83c704 ADD EDI,0x4
    s.di = integer::add(s.di,0x00000004u,32,flags);
  }
  L0076ddf2: { // 0x76ddf2: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0076ddf4: { // 0x76ddf4: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0076ddf5: { // 0x76ddf5: 740a JZ 0x0076de01
    if(integer::condition("JZ",flags)) goto L0076de01;
  }
  L0076ddf7: { // 0x76ddf7: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0076ddf9: { // 0x76ddf9: 8907 MOV dword ptr [EDI],EAX
    m.w32((s.di), s.ax);
  }
  L0076ddfb: { // 0x76ddfb: 83c704 ADD EDI,0x4
    s.di = integer::add(s.di,0x00000004u,32,flags);
  }
  L0076ddfe: { // 0x76ddfe: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0076ddff: { // 0x76ddff: 75f8 JNZ 0x0076ddf9
    if(integer::condition("JNZ",flags)) goto L0076ddf9;
  }
  L0076de01: { // 0x76de01: 83e303 AND EBX,0x3
    s.bx = integer::logical((s.bx)&(0x00000003u),32,flags);
  }
  L0076de04: { // 0x76de04: 7585 JNZ 0x0076dd8b
    if(integer::condition("JNZ",flags)) goto L0076dd8b;
  }
  L0076de06: { // 0x76de06: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0076de0a: { // 0x76de0a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0076de0b: { // 0x76de0b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076de0c: { // 0x76de0c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076de0d: { // 0x76de0d: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 7139504u:f_002cf0b0(m,s,child,{});break;
case 4259600u:f_0000ff10(m,s,child,{});break;
case 4259792u:f_0000ffd0(m,s,child,{});break;
case 4261248u:f_00010580(m,s,child,{});break;
case 4540240u:f_00054750(m,s,child,{});break;
case 4638848u:f_0006c880(m,s,child,{});break;
case 4639776u:f_0006cc20(m,s,child,{});break;
case 5202176u:f_000f6100(m,s,child,{});break;
case 5209760u:f_000f7ea0(m,s,child,{});break;
case 5285216u:f_0010a560(m,s,child,{});break;
case 5287088u:f_0010acb0(m,s,child,{});break;
case 6086272u:f_001cde80(m,s,child,{});break;
case 6593424u:f_00249b90(m,s,child,{});break;
case 6601216u:f_0024ba00(m,s,child,{});break;
case 7789840u:f_0036dd10(m,s,child,{});break;
default:throw std::domain_error("recovery633 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0041bc90(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0041bc90: { // 0x41bc90: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L0041bc94: { // 0x41bc94: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0041bc95: { // 0x41bc95: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0041bc96: { // 0x41bc96: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  L0041bc98: { // 0x41bc98: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0041bc9a: { // 0x41bc9a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0041bc9b: { // 0x41bc9b: e810342b00 CALL 0x006cf0b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006cf0b0u,4308128u); flags=s.arithmetic_flags;
  }
  L0041bca0: { // 0x41bca0: 8d4604 LEA EAX,[ESI + 0x4]
    s.ax = (s.si+0x00000004u);
  }
  L0041bca3: { // 0x41bca3: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0041bca5: { // 0x41bca5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0041bca6: { // 0x41bca6: c786900b0000ffffffff MOV dword ptr [ESI + 0xb90],0xffffffff
    m.w32((s.si+0x00000b90u), 0xffffffffu);
  }
  L0041bcb0: { // 0x41bcb0: 889e940b0000 MOV byte ptr [ESI + 0xb94],BL
    m.w8((s.si+0x00000b94u), (s.bx & 0xffu));
  }
  L0041bcb6: { // 0x41bcb6: 889ea00b0000 MOV byte ptr [ESI + 0xba0],BL
    m.w8((s.si+0x00000ba0u), (s.bx & 0xffu));
  }
  L0041bcbc: { // 0x41bcbc: 889ea10b0000 MOV byte ptr [ESI + 0xba1],BL
    m.w8((s.si+0x00000ba1u), (s.bx & 0xffu));
  }
  L0041bcc2: { // 0x41bcc2: 889ea20b0000 MOV byte ptr [ESI + 0xba2],BL
    m.w8((s.si+0x00000ba2u), (s.bx & 0xffu));
  }
  L0041bcc8: { // 0x41bcc8: 889ea30b0000 MOV byte ptr [ESI + 0xba3],BL
    m.w8((s.si+0x00000ba3u), (s.bx & 0xffu));
  }
  L0041bcce: { // 0x41bcce: 889ea40b0000 MOV byte ptr [ESI + 0xba4],BL
    m.w8((s.si+0x00000ba4u), (s.bx & 0xffu));
  }
  L0041bcd4: { // 0x41bcd4: c70678667800 MOV dword ptr [ESI],0x786678
    m.w32((s.si), 0x00786678u);
  }
  L0041bcda: { // 0x41bcda: c7005c667800 MOV dword ptr [EAX],0x78665c
    m.w32((s.ax), 0x0078665cu);
  }
  L0041bce0: { // 0x41bce0: c7460854667800 MOV dword ptr [ESI + 0x8],0x786654
    m.w32((s.si+0x00000008u), 0x00786654u);
  }
  L0041bce7: { // 0x41bce7: c7460c4c667800 MOV dword ptr [ESI + 0xc],0x78664c
    m.w32((s.si+0x0000000cu), 0x0078664cu);
  }
  L0041bcee: { // 0x41bcee: e8dd42ffff CALL 0x0040ffd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0040ffd0u,4308211u); flags=s.arithmetic_flags;
  }
  L0041bcf3: { // 0x41bcf3: a1b855a200 MOV EAX,[0x00a255b8]
    s.ax = m.r32((0x00a255b8u));
  }
  L0041bcf8: { // 0x41bcf8: 8b0db055a200 MOV ECX,dword ptr [0x00a255b0]
    s.cx = m.r32((0x00a255b0u));
  }
  L0041bcfe: { // 0x41bcfe: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0041bd00: { // 0x41bd00: 7c31 JL 0x0041bd33
    if(integer::condition("JL",flags)) goto L0041bd33;
  }
  L0041bd02: { // 0x41bd02: 381db555a200 CMP byte ptr [0x00a255b5],BL
    (void)integer::sub(m.r8((0x00a255b5u)),(s.bx & 0xffu),8,flags);
  }
  L0041bd08: { // 0x41bd08: 7504 JNZ 0x0041bd0e
    if(integer::condition("JNZ",flags)) goto L0041bd0e;
  }
  L0041bd0a: { // 0x41bd0a: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L0041bd0c: { // 0x41bd0c: 753a JNZ 0x0041bd48
    if(integer::condition("JNZ",flags)) goto L0041bd48;
  }
  L0041bd0e: { // 0x41bd0e: 8b15bc55a200 MOV EDX,dword ptr [0x00a255bc]
    s.dx = m.r32((0x00a255bcu));
  }
  L0041bd14: { // 0x41bd14: 3bd3 CMP EDX,EBX
    (void)integer::sub(s.dx,s.bx,32,flags);
  }
  L0041bd16: { // 0x41bd16: 7e30 JLE 0x0041bd48
    if(integer::condition("JLE",flags)) goto L0041bd48;
  }
  L0041bd18: { // 0x41bd18: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L0041bd1a: { // 0x41bd1a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0041bd1b: { // 0x41bd1b: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0041bd1c: { // 0x41bd1c: 8b15a855a200 MOV EDX,dword ptr [0x00a255a8]
    s.dx = m.r32((0x00a255a8u));
  }
  L0041bd22: { // 0x41bd22: b9a855a200 MOV ECX,0xa255a8
    s.cx = 0x00a255a8u;
  }
  L0041bd27: { // 0x41bd27: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),4308266u); flags=s.arithmetic_flags;
  }
  L0041bd2a: { // 0x41bd2a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0041bd2c: { // 0x41bd2c: a1b855a200 MOV EAX,[0x00a255b8]
    s.ax = m.r32((0x00a255b8u));
  }
  L0041bd31: { // 0x41bd31: 7415 JZ 0x0041bd48
    if(integer::condition("JZ",flags)) goto L0041bd48;
  }
  L0041bd33: { // 0x41bd33: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0041bd35: { // 0x41bd35: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0041bd36: { // 0x41bd36: a3b855a200 MOV [0x00a255b8],EAX
    m.w32((0x00a255b8u), s.ax);
  }
  L0041bd3b: { // 0x41bd3b: a1ac55a200 MOV EAX,[0x00a255ac]
    s.ax = m.r32((0x00a255acu));
  }
  L0041bd40: { // 0x41bd40: 893488 MOV dword ptr [EAX + ECX*0x4],ESI
    m.w32((s.ax+(s.cx * 0x00000004u)), s.si);
  }
  L0041bd43: { // 0x41bd43: a1b855a200 MOV EAX,[0x00a255b8]
    s.ax = m.r32((0x00a255b8u));
  }
  L0041bd48: { // 0x41bd48: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0041bd4a: { // 0x41bd4a: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0041bd4c: { // 0x41bd4c: 7e12 JLE 0x0041bd60
    if(integer::condition("JLE",flags)) goto L0041bd60;
  }
  L0041bd4e: { // 0x41bd4e: 8b15ac55a200 MOV EDX,dword ptr [0x00a255ac]
    s.dx = m.r32((0x00a255acu));
  }
  L0041bd54: { // 0x41bd54: 3932 CMP dword ptr [EDX],ESI
    (void)integer::sub(m.r32((s.dx)),s.si,32,flags);
  }
  L0041bd56: { // 0x41bd56: 740b JZ 0x0041bd63
    if(integer::condition("JZ",flags)) goto L0041bd63;
  }
  L0041bd58: { // 0x41bd58: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0041bd59: { // 0x41bd59: 83c204 ADD EDX,0x4
    s.dx = integer::add(s.dx,0x00000004u,32,flags);
  }
  L0041bd5c: { // 0x41bd5c: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L0041bd5e: { // 0x41bd5e: 7cf4 JL 0x0041bd54
    if(integer::condition("JL",flags)) goto L0041bd54;
  }
  L0041bd60: { // 0x41bd60: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  L0041bd63: { // 0x41bd63: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0041bd65: { // 0x41bd65: 898e900b0000 MOV dword ptr [ESI + 0xb90],ECX
    m.w32((s.si+0x00000b90u), s.cx);
  }
  L0041bd6b: { // 0x41bd6b: 8886ff0a0000 MOV byte ptr [ESI + 0xaff],AL
    m.w8((s.si+0x00000affu), (s.ax & 0xffu));
  }
  L0041bd71: { // 0x41bd71: 8886460b0000 MOV byte ptr [ESI + 0xb46],AL
    m.w8((s.si+0x00000b46u), (s.ax & 0xffu));
  }
  L0041bd77: { // 0x41bd77: 889e990a0000 MOV byte ptr [ESI + 0xa99],BL
    m.w8((s.si+0x00000a99u), (s.bx & 0xffu));
  }
  L0041bd7d: { // 0x41bd7d: c7863406000020000000 MOV dword ptr [ESI + 0x634],0x20
    m.w32((s.si+0x00000634u), 0x00000020u);
  }
  L0041bd87: { // 0x41bd87: 899e980b0000 MOV dword ptr [ESI + 0xb98],EBX
    m.w32((s.si+0x00000b98u), s.bx);
  }
  L0041bd8d: { // 0x41bd8d: c7869c0b000003000000 MOV dword ptr [ESI + 0xb9c],0x3
    m.w32((s.si+0x00000b9cu), 0x00000003u);
  }
  L0041bd97: { // 0x41bd97: 889efd0a0000 MOV byte ptr [ESI + 0xafd],BL
    m.w8((s.si+0x00000afdu), (s.bx & 0xffu));
  }
  L0041bd9d: { // 0x41bd9d: 889e470b0000 MOV byte ptr [ESI + 0xb47],BL
    m.w8((s.si+0x00000b47u), (s.bx & 0xffu));
  }
  L0041bda3: { // 0x41bda3: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0041bda5: { // 0x41bda5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0041bda6: { // 0x41bda6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0041bda7: { // 0x41bda7: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_006ff1c0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006ff1c0: { // 0x6ff1c0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L006ff1c4: { // 0x6ff1c4: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006ff1c5: { // 0x6ff1c5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006ff1c6: { // 0x6ff1c6: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006ff1c7: { // 0x6ff1c7: 83cfff OR EDI,0xffffffff
    s.di = integer::logical((s.di)|(0xffffffffu),32,flags);
  }
  L006ff1ca: { // 0x6ff1ca: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006ff1cb: { // 0x6ff1cb: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006ff1cd: { // 0x6ff1cd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006ff1ce: { // 0x6ff1ce: e8ddfefcff CALL 0x006cf0b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006cf0b0u,7336403u); flags=s.arithmetic_flags;
  }
  L006ff1d3: { // 0x6ff1d3: 89be900b0000 MOV dword ptr [ESI + 0xb90],EDI
    m.w32((s.si+0x00000b90u), s.di);
  }
  L006ff1d9: { // 0x6ff1d9: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L006ff1db: { // 0x6ff1db: 89be940b0000 MOV dword ptr [ESI + 0xb94],EDI
    m.w32((s.si+0x00000b94u), s.di);
  }
  L006ff1e1: { // 0x6ff1e1: 899e980b0000 MOV dword ptr [ESI + 0xb98],EBX
    m.w32((s.si+0x00000b98u), s.bx);
  }
  L006ff1e7: { // 0x6ff1e7: 899e9c0b0000 MOV dword ptr [ESI + 0xb9c],EBX
    m.w32((s.si+0x00000b9cu), s.bx);
  }
  L006ff1ed: { // 0x6ff1ed: 899ea00b0000 MOV dword ptr [ESI + 0xba0],EBX
    m.w32((s.si+0x00000ba0u), s.bx);
  }
  L006ff1f3: { // 0x6ff1f3: 889ea40b0000 MOV byte ptr [ESI + 0xba4],BL
    m.w8((s.si+0x00000ba4u), (s.bx & 0xffu));
  }
  L006ff1f9: { // 0x6ff1f9: 889ea50b0000 MOV byte ptr [ESI + 0xba5],BL
    m.w8((s.si+0x00000ba5u), (s.bx & 0xffu));
  }
  L006ff1ff: { // 0x6ff1ff: 889ea60b0000 MOV byte ptr [ESI + 0xba6],BL
    m.w8((s.si+0x00000ba6u), (s.bx & 0xffu));
  }
  L006ff205: { // 0x6ff205: 889ea70b0000 MOV byte ptr [ESI + 0xba7],BL
    m.w8((s.si+0x00000ba7u), (s.bx & 0xffu));
  }
  L006ff20b: { // 0x6ff20b: 889ea80b0000 MOV byte ptr [ESI + 0xba8],BL
    m.w8((s.si+0x00000ba8u), (s.bx & 0xffu));
  }
  L006ff211: { // 0x6ff211: 8d4604 LEA EAX,[ESI + 0x4]
    s.ax = (s.si+0x00000004u);
  }
  L006ff214: { // 0x6ff214: 889ea90b0000 MOV byte ptr [ESI + 0xba9],BL
    m.w8((s.si+0x00000ba9u), (s.bx & 0xffu));
  }
  L006ff21a: { // 0x6ff21a: 889eaa0b0000 MOV byte ptr [ESI + 0xbaa],BL
    m.w8((s.si+0x00000baau), (s.bx & 0xffu));
  }
  L006ff220: { // 0x6ff220: 889eab0b0000 MOV byte ptr [ESI + 0xbab],BL
    m.w8((s.si+0x00000babu), (s.bx & 0xffu));
  }
  L006ff226: { // 0x6ff226: c686ac0b000001 MOV byte ptr [ESI + 0xbac],0x1
    m.w8((s.si+0x00000bacu), 0x00000001u);
  }
  L006ff22d: { // 0x6ff22d: 889ead0b0000 MOV byte ptr [ESI + 0xbad],BL
    m.w8((s.si+0x00000badu), (s.bx & 0xffu));
  }
  L006ff233: { // 0x6ff233: 889eae0b0000 MOV byte ptr [ESI + 0xbae],BL
    m.w8((s.si+0x00000baeu), (s.bx & 0xffu));
  }
  L006ff239: { // 0x6ff239: 889eaf0b0000 MOV byte ptr [ESI + 0xbaf],BL
    m.w8((s.si+0x00000bafu), (s.bx & 0xffu));
  }
  L006ff23f: { // 0x6ff23f: 889eb00b0000 MOV byte ptr [ESI + 0xbb0],BL
    m.w8((s.si+0x00000bb0u), (s.bx & 0xffu));
  }
  L006ff245: { // 0x6ff245: 889eb10b0000 MOV byte ptr [ESI + 0xbb1],BL
    m.w8((s.si+0x00000bb1u), (s.bx & 0xffu));
  }
  L006ff24b: { // 0x6ff24b: 889eb20b0000 MOV byte ptr [ESI + 0xbb2],BL
    m.w8((s.si+0x00000bb2u), (s.bx & 0xffu));
  }
  L006ff251: { // 0x6ff251: 889eb30b0000 MOV byte ptr [ESI + 0xbb3],BL
    m.w8((s.si+0x00000bb3u), (s.bx & 0xffu));
  }
  L006ff257: { // 0x6ff257: 899eb40b0000 MOV dword ptr [ESI + 0xbb4],EBX
    m.w32((s.si+0x00000bb4u), s.bx);
  }
  L006ff25d: { // 0x6ff25d: 899eb80b0000 MOV dword ptr [ESI + 0xbb8],EBX
    m.w32((s.si+0x00000bb8u), s.bx);
  }
  L006ff263: { // 0x6ff263: c786bc0b000001000000 MOV dword ptr [ESI + 0xbbc],0x1
    m.w32((s.si+0x00000bbcu), 0x00000001u);
  }
  L006ff26d: { // 0x6ff26d: 89bec00b0000 MOV dword ptr [ESI + 0xbc0],EDI
    m.w32((s.si+0x00000bc0u), s.di);
  }
  L006ff273: { // 0x6ff273: 89bec40b0000 MOV dword ptr [ESI + 0xbc4],EDI
    m.w32((s.si+0x00000bc4u), s.di);
  }
  L006ff279: { // 0x6ff279: 89bec80b0000 MOV dword ptr [ESI + 0xbc8],EDI
    m.w32((s.si+0x00000bc8u), s.di);
  }
  L006ff27f: { // 0x6ff27f: 89becc0b0000 MOV dword ptr [ESI + 0xbcc],EDI
    m.w32((s.si+0x00000bccu), s.di);
  }
  L006ff285: { // 0x6ff285: 89bed00b0000 MOV dword ptr [ESI + 0xbd0],EDI
    m.w32((s.si+0x00000bd0u), s.di);
  }
  L006ff28b: { // 0x6ff28b: c786d40b000008000000 MOV dword ptr [ESI + 0xbd4],0x8
    m.w32((s.si+0x00000bd4u), 0x00000008u);
  }
  L006ff295: { // 0x6ff295: 899ef00b0000 MOV dword ptr [ESI + 0xbf0],EBX
    m.w32((s.si+0x00000bf0u), s.bx);
  }
  L006ff29b: { // 0x6ff29b: c686f40b00000c MOV byte ptr [ESI + 0xbf4],0xc
    m.w8((s.si+0x00000bf4u), 0x0000000cu);
  }
  L006ff2a2: { // 0x6ff2a2: 889ef50b0000 MOV byte ptr [ESI + 0xbf5],BL
    m.w8((s.si+0x00000bf5u), (s.bx & 0xffu));
  }
  L006ff2a8: { // 0x6ff2a8: 889ef60b0000 MOV byte ptr [ESI + 0xbf6],BL
    m.w8((s.si+0x00000bf6u), (s.bx & 0xffu));
  }
  L006ff2ae: { // 0x6ff2ae: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006ff2af: { // 0x6ff2af: c706b8917900 MOV dword ptr [ESI],0x7991b8
    m.w32((s.si), 0x007991b8u);
  }
  L006ff2b5: { // 0x6ff2b5: c7009c917900 MOV dword ptr [EAX],0x79919c
    m.w32((s.ax), 0x0079919cu);
  }
  L006ff2bb: { // 0x6ff2bb: c7460894917900 MOV dword ptr [ESI + 0x8],0x799194
    m.w32((s.si+0x00000008u), 0x00799194u);
  }
  L006ff2c2: { // 0x6ff2c2: c7460c8c917900 MOV dword ptr [ESI + 0xc],0x79918c
    m.w32((s.si+0x0000000cu), 0x0079918cu);
  }
  L006ff2c9: { // 0x6ff2c9: e8020dd1ff CALL 0x0040ffd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0040ffd0u,7336654u); flags=s.arithmetic_flags;
  }
  L006ff2ce: { // 0x6ff2ce: c7863406000020000000 MOV dword ptr [ESI + 0x634],0x20
    m.w32((s.si+0x00000634u), 0x00000020u);
  }
  L006ff2d8: { // 0x6ff2d8: a188e0a100 MOV EAX,[0x00a1e088]
    s.ax = m.r32((0x00a1e088u));
  }
  L006ff2dd: { // 0x6ff2dd: 8b0d80e0a100 MOV ECX,dword ptr [0x00a1e080]
    s.cx = m.r32((0x00a1e080u));
  }
  L006ff2e3: { // 0x6ff2e3: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L006ff2e5: { // 0x6ff2e5: 7c31 JL 0x006ff318
    if(integer::condition("JL",flags)) goto L006ff318;
  }
  L006ff2e7: { // 0x6ff2e7: 381d85e0a100 CMP byte ptr [0x00a1e085],BL
    (void)integer::sub(m.r8((0x00a1e085u)),(s.bx & 0xffu),8,flags);
  }
  L006ff2ed: { // 0x6ff2ed: 7504 JNZ 0x006ff2f3
    if(integer::condition("JNZ",flags)) goto L006ff2f3;
  }
  L006ff2ef: { // 0x6ff2ef: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L006ff2f1: { // 0x6ff2f1: 753a JNZ 0x006ff32d
    if(integer::condition("JNZ",flags)) goto L006ff32d;
  }
  L006ff2f3: { // 0x6ff2f3: 8b158ce0a100 MOV EDX,dword ptr [0x00a1e08c]
    s.dx = m.r32((0x00a1e08cu));
  }
  L006ff2f9: { // 0x6ff2f9: 3bd3 CMP EDX,EBX
    (void)integer::sub(s.dx,s.bx,32,flags);
  }
  L006ff2fb: { // 0x6ff2fb: 7e30 JLE 0x006ff32d
    if(integer::condition("JLE",flags)) goto L006ff32d;
  }
  L006ff2fd: { // 0x6ff2fd: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L006ff2ff: { // 0x6ff2ff: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006ff300: { // 0x6ff300: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006ff301: { // 0x6ff301: 8b1578e0a100 MOV EDX,dword ptr [0x00a1e078]
    s.dx = m.r32((0x00a1e078u));
  }
  L006ff307: { // 0x6ff307: b978e0a100 MOV ECX,0xa1e078
    s.cx = 0x00a1e078u;
  }
  L006ff30c: { // 0x6ff30c: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),7336719u); flags=s.arithmetic_flags;
  }
  L006ff30f: { // 0x6ff30f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006ff311: { // 0x6ff311: a188e0a100 MOV EAX,[0x00a1e088]
    s.ax = m.r32((0x00a1e088u));
  }
  L006ff316: { // 0x6ff316: 7415 JZ 0x006ff32d
    if(integer::condition("JZ",flags)) goto L006ff32d;
  }
  L006ff318: { // 0x6ff318: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006ff31a: { // 0x6ff31a: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L006ff31b: { // 0x6ff31b: a388e0a100 MOV [0x00a1e088],EAX
    m.w32((0x00a1e088u), s.ax);
  }
  L006ff320: { // 0x6ff320: a17ce0a100 MOV EAX,[0x00a1e07c]
    s.ax = m.r32((0x00a1e07cu));
  }
  L006ff325: { // 0x6ff325: 893488 MOV dword ptr [EAX + ECX*0x4],ESI
    m.w32((s.ax+(s.cx * 0x00000004u)), s.si);
  }
  L006ff328: { // 0x6ff328: a188e0a100 MOV EAX,[0x00a1e088]
    s.ax = m.r32((0x00a1e088u));
  }
  L006ff32d: { // 0x6ff32d: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L006ff32f: { // 0x6ff32f: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L006ff331: { // 0x6ff331: 7e12 JLE 0x006ff345
    if(integer::condition("JLE",flags)) goto L006ff345;
  }
  L006ff333: { // 0x6ff333: 8b157ce0a100 MOV EDX,dword ptr [0x00a1e07c]
    s.dx = m.r32((0x00a1e07cu));
  }
  L006ff339: { // 0x6ff339: 3932 CMP dword ptr [EDX],ESI
    (void)integer::sub(m.r32((s.dx)),s.si,32,flags);
  }
  L006ff33b: { // 0x6ff33b: 740a JZ 0x006ff347
    if(integer::condition("JZ",flags)) goto L006ff347;
  }
  L006ff33d: { // 0x6ff33d: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L006ff33e: { // 0x6ff33e: 83c204 ADD EDX,0x4
    s.dx = integer::add(s.dx,0x00000004u,32,flags);
  }
  L006ff341: { // 0x6ff341: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L006ff343: { // 0x6ff343: 7cf4 JL 0x006ff339
    if(integer::condition("JL",flags)) goto L006ff339;
  }
  L006ff345: { // 0x6ff345: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006ff347: { // 0x6ff347: 898e900b0000 MOV dword ptr [ESI + 0xb90],ECX
    m.w32((s.si+0x00000b90u), s.cx);
  }
  L006ff34d: { // 0x6ff34d: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006ff34f: { // 0x6ff34f: 898ed80b0000 MOV dword ptr [ESI + 0xbd8],ECX
    m.w32((s.si+0x00000bd8u), s.cx);
  }
  L006ff355: { // 0x6ff355: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L006ff357: { // 0x6ff357: 898edc0b0000 MOV dword ptr [ESI + 0xbdc],ECX
    m.w32((s.si+0x00000bdcu), s.cx);
  }
  L006ff35d: { // 0x6ff35d: 89bee00b0000 MOV dword ptr [ESI + 0xbe0],EDI
    m.w32((s.si+0x00000be0u), s.di);
  }
  L006ff363: { // 0x6ff363: 89bee40b0000 MOV dword ptr [ESI + 0xbe4],EDI
    m.w32((s.si+0x00000be4u), s.di);
  }
  L006ff369: { // 0x6ff369: 89bee80b0000 MOV dword ptr [ESI + 0xbe8],EDI
    m.w32((s.si+0x00000be8u), s.di);
  }
  L006ff36f: { // 0x6ff36f: 89beec0b0000 MOV dword ptr [ESI + 0xbec],EDI
    m.w32((s.si+0x00000becu), s.di);
  }
  L006ff375: { // 0x6ff375: 889efd0a0000 MOV byte ptr [ESI + 0xafd],BL
    m.w8((s.si+0x00000afdu), (s.bx & 0xffu));
  }
  L006ff37b: { // 0x6ff37b: c686ff0a000001 MOV byte ptr [ESI + 0xaff],0x1
    m.w8((s.si+0x00000affu), 0x00000001u);
  }
  L006ff382: { // 0x6ff382: 889e470b0000 MOV byte ptr [ESI + 0xb47],BL
    m.w8((s.si+0x00000b47u), (s.bx & 0xffu));
  }
  L006ff388: { // 0x6ff388: 889e460b0000 MOV byte ptr [ESI + 0xb46],BL
    m.w8((s.si+0x00000b46u), (s.bx & 0xffu));
  }
  L006ff38e: { // 0x6ff38e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006ff38f: { // 0x6ff38f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006ff390: { // 0x6ff390: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006ff391: { // 0x6ff391: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}

namespace ra2::recovered::recovery_b633 {
std::uint32_t fun_006cf0b0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t sb=0x7d000000u,entry=sb+0x6004u;
 leaf::Memory local(stack.data(),sb,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame fr{entry,entry,0x76543210u};const Operations op{};m.w32(entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(entry+4u+4u*k,i.arg[k]);
 m.w32(entry-8u,i.stack_minus8);m.w32(((entry-4u)&~7u)-8u,i.stack_minus8);
 f_002cf0b0(m,s,fr,op);i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(entry+4u+4u*k);return s.ax;
}
}
