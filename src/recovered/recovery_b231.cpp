#include "recovered/recovery_b231_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b231 {
namespace {
void f_00020110(Memory&,State&,Frame&,const Operations&);
void f_001ca970(Memory&,State&,Frame&,const Operations&);
void f_0000ff10(Memory&,State&,Frame&,const Operations&);
void f_00005bf0(Memory&,State&,Frame&,const Operations&);
void f_0000ffd0(Memory&,State&,Frame&,const Operations&);
void f_0025a120(Memory&,State&,Frame&,const Operations&);
void f_0025a130(Memory&,State&,Frame&,const Operations&);
void f_00157070(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_000702c0(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void f_00219cf0(Memory&,State&,Frame&,const Operations&);
void f_001ccfb0(Memory&,State&,Frame&,const Operations&);
void f_001cbf20(Memory&,State&,Frame&,const Operations&);
void f_000226d0(Memory&,State&,Frame&,const Operations&);
void f_00021500(Memory&,State&,Frame&,const Operations&);
void f_001cc7f0(Memory&,State&,Frame&,const Operations&);
void f_00005d50(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);
void f_00020110(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00420110: { // 0x420110: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00420111: { // 0x420111: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L00420113: { // 0x420113: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L00420116: { // 0x420116: 83ec54 SUB ESP,0x54
    f.sp = integer::sub(f.sp,0x00000054u,32,flags);
  }
  L00420119: { // 0x420119: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0042011a: { // 0x42011a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0042011b: { // 0x42011b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0042011c: { // 0x42011c: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0042011e: { // 0x42011e: e84da81a00 CALL 0x005ca970
    s.arithmetic_flags=flags; invoke(m,s,f,0x005ca970u,4325667u); flags=s.arithmetic_flags;
  }
  L00420123: { // 0x420123: 8b4d08 MOV ECX,dword ptr [EBP + 0x8]
    s.cx = m.r32((s.bp+0x00000008u));
  }
  L00420126: { // 0x420126: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00420128: { // 0x420128: 899e98000000 MOV dword ptr [ESI + 0x98],EBX
    m.w32((s.si+0x00000098u), s.bx);
  }
  L0042012e: { // 0x42012e: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  L00420133: { // 0x420133: 89869c000000 MOV dword ptr [ESI + 0x9c],EAX
    m.w32((s.si+0x0000009cu), s.ax);
  }
  L00420139: { // 0x420139: 899ea4000000 MOV dword ptr [ESI + 0xa4],EBX
    m.w32((s.si+0x000000a4u), s.bx);
  }
  L0042013f: { // 0x42013f: 899ea8000000 MOV dword ptr [ESI + 0xa8],EBX
    m.w32((s.si+0x000000a8u), s.bx);
  }
  L00420145: { // 0x420145: c786ac00000001000000 MOV dword ptr [ESI + 0xac],0x1
    m.w32((s.si+0x000000acu), 0x00000001u);
  }
  L0042014f: { // 0x42014f: 898eb0000000 MOV dword ptr [ESI + 0xb0],ECX
    m.w32((s.si+0x000000b0u), s.cx);
  }
  L00420155: { // 0x420155: 83cfff OR EDI,0xffffffff
    s.di = integer::logical((s.di)|(0xffffffffu),32,flags);
  }
  L00420158: { // 0x420158: 899eb4000000 MOV dword ptr [ESI + 0xb4],EBX
    m.w32((s.si+0x000000b4u), s.bx);
  }
  L0042015e: { // 0x42015e: 89beb8000000 MOV dword ptr [ESI + 0xb8],EDI
    m.w32((s.si+0x000000b8u), s.di);
  }
  L00420164: { // 0x420164: 899ebc000000 MOV dword ptr [ESI + 0xbc],EBX
    m.w32((s.si+0x000000bcu), s.bx);
  }
  L0042016a: { // 0x42016a: 89bec0000000 MOV dword ptr [ESI + 0xc0],EDI
    m.w32((s.si+0x000000c0u), s.di);
  }
  L00420170: { // 0x420170: c786e4000000e8030000 MOV dword ptr [ESI + 0xe4],0x3e8
    m.w32((s.si+0x000000e4u), 0x000003e8u);
  }
  L0042017a: { // 0x42017a: 899ee8000000 MOV dword ptr [ESI + 0xe8],EBX
    m.w32((s.si+0x000000e8u), s.bx);
  }
  L00420180: { // 0x420180: 899eec000000 MOV dword ptr [ESI + 0xec],EBX
    m.w32((s.si+0x000000ecu), s.bx);
  }
  L00420186: { // 0x420186: a1104a8300 MOV EAX,[0x00834a10]
    s.ax = m.r32((0x00834a10u));
  }
  L0042018b: { // 0x42018b: 8d96f0000000 LEA EDX,[ESI + 0xf0]
    s.dx = (s.si+0x000000f0u);
  }
  L00420191: { // 0x420191: 680000803f PUSH 0x3f800000
    f.push(m,0x3f800000u);
  }
  L00420196: { // 0x420196: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00420197: { // 0x420197: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00420198: { // 0x420198: 8902 MOV dword ptr [EDX],EAX
    m.w32((s.dx), s.ax);
  }
  L0042019a: { // 0x42019a: 8b0d144a8300 MOV ECX,dword ptr [0x00834a14]
    s.cx = m.r32((0x00834a14u));
  }
  L004201a0: { // 0x4201a0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004201a1: { // 0x4201a1: 894a04 MOV dword ptr [EDX + 0x4],ECX
    m.w32((s.dx+0x00000004u), s.cx);
  }
  L004201a4: { // 0x4201a4: a1184a8300 MOV EAX,[0x00834a18]
    s.ax = m.r32((0x00834a18u));
  }
  L004201a9: { // 0x4201a9: 899efc000000 MOV dword ptr [ESI + 0xfc],EBX
    m.w32((s.si+0x000000fcu), s.bx);
  }
  L004201af: { // 0x4201af: 889e00010000 MOV byte ptr [ESI + 0x100],BL
    m.w8((s.si+0x00000100u), (s.bx & 0xffu));
  }
  L004201b5: { // 0x4201b5: 894208 MOV dword ptr [EDX + 0x8],EAX
    m.w32((s.dx+0x00000008u), s.ax);
  }
  L004201b8: { // 0x4201b8: 889e01010000 MOV byte ptr [ESI + 0x101],BL
    m.w8((s.si+0x00000101u), (s.bx & 0xffu));
  }
  L004201be: { // 0x4201be: 889e02010000 MOV byte ptr [ESI + 0x102],BL
    m.w8((s.si+0x00000102u), (s.bx & 0xffu));
  }
  L004201c4: { // 0x4201c4: 889e03010000 MOV byte ptr [ESI + 0x103],BL
    m.w8((s.si+0x00000103u), (s.bx & 0xffu));
  }
  L004201ca: { // 0x4201ca: 899e04010000 MOV dword ptr [ESI + 0x104],EBX
    m.w32((s.si+0x00000104u), s.bx);
  }
  L004201d0: { // 0x4201d0: 899e08010000 MOV dword ptr [ESI + 0x108],EBX
    m.w32((s.si+0x00000108u), s.bx);
  }
  L004201d6: { // 0x4201d6: 899e10010000 MOV dword ptr [ESI + 0x110],EBX
    m.w32((s.si+0x00000110u), s.bx);
  }
  L004201dc: { // 0x4201dc: 899e18010000 MOV dword ptr [ESI + 0x118],EBX
    m.w32((s.si+0x00000118u), s.bx);
  }
  L004201e2: { // 0x4201e2: 8d8e38010000 LEA ECX,[ESI + 0x138]
    s.cx = (s.si+0x00000138u);
  }
  L004201e8: { // 0x4201e8: 899e0c010000 MOV dword ptr [ESI + 0x10c],EBX
    m.w32((s.si+0x0000010cu), s.bx);
  }
  L004201ee: { // 0x4201ee: 899e14010000 MOV dword ptr [ESI + 0x114],EBX
    m.w32((s.si+0x00000114u), s.bx);
  }
  L004201f4: { // 0x4201f4: 899e1c010000 MOV dword ptr [ESI + 0x11c],EBX
    m.w32((s.si+0x0000011cu), s.bx);
  }
  L004201fa: { // 0x4201fa: e8f19a1f00 CALL 0x00619cf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00619cf0u,4325887u); flags=s.arithmetic_flags;
  }
  L004201ff: { // 0x4201ff: 680000803f PUSH 0x3f800000
    f.push(m,0x3f800000u);
  }
  L00420204: { // 0x420204: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00420205: { // 0x420205: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00420206: { // 0x420206: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00420207: { // 0x420207: 8d8e48010000 LEA ECX,[ESI + 0x148]
    s.cx = (s.si+0x00000148u);
  }
  L0042020d: { // 0x42020d: e8de9a1f00 CALL 0x00619cf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00619cf0u,4325906u); flags=s.arithmetic_flags;
  }
  L00420212: { // 0x420212: 8b4d10 MOV ECX,dword ptr [EBP + 0x10]
    s.cx = m.r32((s.bp+0x00000010u));
  }
  L00420215: { // 0x420215: 8b5518 MOV EDX,dword ptr [EBP + 0x18]
    s.dx = m.r32((s.bp+0x00000018u));
  }
  L00420218: { // 0x420218: 8d4604 LEA EAX,[ESI + 0x4]
    s.ax = (s.si+0x00000004u);
  }
  L0042021b: { // 0x42021b: 899e68010000 MOV dword ptr [ESI + 0x168],EBX
    m.w32((s.si+0x00000168u), s.bx);
  }
  L00420221: { // 0x420221: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00420222: { // 0x420222: 889e58010000 MOV byte ptr [ESI + 0x158],BL
    m.w8((s.si+0x00000158u), (s.bx & 0xffu));
  }
  L00420228: { // 0x420228: 889e59010000 MOV byte ptr [ESI + 0x159],BL
    m.w8((s.si+0x00000159u), (s.bx & 0xffu));
  }
  L0042022e: { // 0x42022e: 899e5c010000 MOV dword ptr [ESI + 0x15c],EBX
    m.w32((s.si+0x0000015cu), s.bx);
  }
  L00420234: { // 0x420234: 898e64010000 MOV dword ptr [ESI + 0x164],ECX
    m.w32((s.si+0x00000164u), s.cx);
  }
  L0042023a: { // 0x42023a: c7866c0100000000f03f MOV dword ptr [ESI + 0x16c],0x3ff00000
    m.w32((s.si+0x0000016cu), 0x3ff00000u);
  }
  L00420244: { // 0x420244: 899670010000 MOV dword ptr [ESI + 0x170],EDX
    m.w32((s.si+0x00000170u), s.dx);
  }
  L0042024a: { // 0x42024a: 889e74010000 MOV byte ptr [ESI + 0x174],BL
    m.w8((s.si+0x00000174u), (s.bx & 0xffu));
  }
  L00420250: { // 0x420250: c6867501000001 MOV byte ptr [ESI + 0x175],0x1
    m.w8((s.si+0x00000175u), 0x00000001u);
  }
  L00420257: { // 0x420257: 889e76010000 MOV byte ptr [ESI + 0x176],BL
    m.w8((s.si+0x00000176u), (s.bx & 0xffu));
  }
  L0042025d: { // 0x42025d: 889e77010000 MOV byte ptr [ESI + 0x177],BL
    m.w8((s.si+0x00000177u), (s.bx & 0xffu));
  }
  L00420263: { // 0x420263: 889e78010000 MOV byte ptr [ESI + 0x178],BL
    m.w8((s.si+0x00000178u), (s.bx & 0xffu));
  }
  L00420269: { // 0x420269: 889e79010000 MOV byte ptr [ESI + 0x179],BL
    m.w8((s.si+0x00000179u), (s.bx & 0xffu));
  }
  L0042026f: { // 0x42026f: 889e7a010000 MOV byte ptr [ESI + 0x17a],BL
    m.w8((s.si+0x0000017au), (s.bx & 0xffu));
  }
  L00420275: { // 0x420275: 889e7b010000 MOV byte ptr [ESI + 0x17b],BL
    m.w8((s.si+0x0000017bu), (s.bx & 0xffu));
  }
  L0042027b: { // 0x42027b: c6867c01000001 MOV byte ptr [ESI + 0x17c],0x1
    m.w8((s.si+0x0000017cu), 0x00000001u);
  }
  L00420282: { // 0x420282: 889e7d010000 MOV byte ptr [ESI + 0x17d],BL
    m.w8((s.si+0x0000017du), (s.bx & 0xffu));
  }
  L00420288: { // 0x420288: 889e7e010000 MOV byte ptr [ESI + 0x17e],BL
    m.w8((s.si+0x0000017eu), (s.bx & 0xffu));
  }
  L0042028e: { // 0x42028e: c70684707800 MOV dword ptr [ESI],0x787084
    m.w32((s.si), 0x00787084u);
  }
  L00420294: { // 0x420294: c70068707800 MOV dword ptr [EAX],0x787068
    m.w32((s.ax), 0x00787068u);
  }
  L0042029a: { // 0x42029a: c7460860707800 MOV dword ptr [ESI + 0x8],0x787060
    m.w32((s.si+0x00000008u), 0x00787060u);
  }
  L004202a1: { // 0x4202a1: c7460c58707800 MOV dword ptr [ESI + 0xc],0x787058
    m.w32((s.si+0x0000000cu), 0x00787058u);
  }
  L004202a8: { // 0x4202a8: 889ec4000000 MOV byte ptr [ESI + 0xc4],BL
    m.w8((s.si+0x000000c4u), (s.bx & 0xffu));
  }
  L004202ae: { // 0x4202ae: e81dfdfeff CALL 0x0040ffd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0040ffd0u,4326067u); flags=s.arithmetic_flags;
  }
  L004202b3: { // 0x4202b3: 8d8e80010000 LEA ECX,[ESI + 0x180]
    s.cx = (s.si+0x00000180u);
  }
  L004202b9: { // 0x4202b9: e83259feff CALL 0x00405bf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00405bf0u,4326078u); flags=s.arithmetic_flags;
  }
  L004202be: { // 0x4202be: 8d8e94010000 LEA ECX,[ESI + 0x194]
    s.cx = (s.si+0x00000194u);
  }
  L004202c4: { // 0x4202c4: e82759feff CALL 0x00405bf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00405bf0u,4326089u); flags=s.arithmetic_flags;
  }
  L004202c9: { // 0x4202c9: a1b885a200 MOV EAX,[0x00a285b8]
    s.ax = m.r32((0x00a285b8u));
  }
  L004202ce: { // 0x4202ce: 8b0dc085a200 MOV ECX,dword ptr [0x00a285c0]
    s.cx = m.r32((0x00a285c0u));
  }
  L004202d4: { // 0x4202d4: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L004202d6: { // 0x4202d6: 7c2b JL 0x00420303
    if(integer::condition("JL",flags)) goto L00420303;
  }
  L004202d8: { // 0x4202d8: 381dbd85a200 CMP byte ptr [0x00a285bd],BL
    (void)integer::sub(m.r8((0x00a285bdu)),(s.bx & 0xffu),8,flags);
  }
  L004202de: { // 0x4202de: 7504 JNZ 0x004202e4
    if(integer::condition("JNZ",flags)) goto L004202e4;
  }
  L004202e0: { // 0x4202e0: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L004202e2: { // 0x4202e2: 7537 JNZ 0x0042031b
    if(integer::condition("JNZ",flags)) goto L0042031b;
  }
  L004202e4: { // 0x4202e4: 8b0dc485a200 MOV ECX,dword ptr [0x00a285c4]
    s.cx = m.r32((0x00a285c4u));
  }
  L004202ea: { // 0x4202ea: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L004202ec: { // 0x4202ec: 7e2d JLE 0x0042031b
    if(integer::condition("JLE",flags)) goto L0042031b;
  }
  L004202ee: { // 0x4202ee: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L004202f0: { // 0x4202f0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004202f1: { // 0x4202f1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004202f2: { // 0x4202f2: a1b085a200 MOV EAX,[0x00a285b0]
    s.ax = m.r32((0x00a285b0u));
  }
  L004202f7: { // 0x4202f7: b9b085a200 MOV ECX,0xa285b0
    s.cx = 0x00a285b0u;
  }
  L004202fc: { // 0x4202fc: ff5008 CALL dword ptr [EAX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000008u)),4326143u); flags=s.arithmetic_flags;
  }
  L004202ff: { // 0x4202ff: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00420301: { // 0x420301: 7418 JZ 0x0042031b
    if(integer::condition("JZ",flags)) goto L0042031b;
  }
  L00420303: { // 0x420303: 8b0dc085a200 MOV ECX,dword ptr [0x00a285c0]
    s.cx = m.r32((0x00a285c0u));
  }
  L00420309: { // 0x420309: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0042030b: { // 0x42030b: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0042030c: { // 0x42030c: 890dc085a200 MOV dword ptr [0x00a285c0],ECX
    m.w32((0x00a285c0u), s.cx);
  }
  L00420312: { // 0x420312: 8b0db485a200 MOV ECX,dword ptr [0x00a285b4]
    s.cx = m.r32((0x00a285b4u));
  }
  L00420318: { // 0x420318: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L0042031b: { // 0x42031b: 8b96b0000000 MOV EDX,dword ptr [ESI + 0xb0]
    s.dx = m.r32((s.si+0x000000b0u));
  }
  L00420321: { // 0x420321: c6467d01 MOV byte ptr [ESI + 0x7d],0x1
    m.w8((s.si+0x0000007du), 0x00000001u);
  }
  L00420325: { // 0x420325: 8b8200030000 MOV EAX,dword ptr [EDX + 0x300]
    s.ax = m.r32((s.dx+0x00000300u));
  }
  L0042032b: { // 0x42032b: 8986ec000000 MOV dword ptr [ESI + 0xec],EAX
    m.w32((s.si+0x000000ecu), s.ax);
  }
  L00420331: { // 0x420331: 8b8eb0000000 MOV ECX,dword ptr [ESI + 0xb0]
    s.cx = m.r32((s.si+0x000000b0u));
  }
  L00420337: { // 0x420337: 39b988020000 CMP dword ptr [ECX + 0x288],EDI
    (void)integer::sub(m.r32((s.cx+0x00000288u)),s.di,32,flags);
  }
  L0042033d: { // 0x42033d: 7537 JNZ 0x00420376
    if(integer::condition("JNZ",flags)) goto L00420376;
  }
  L0042033f: { // 0x42033f: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00420341: { // 0x420341: ff929c000000 CALL dword ptr [EDX + 0x9c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000009cu)),4326215u); flags=s.arithmetic_flags;
  }
  L00420347: { // 0x420347: 0fbf4006 MOVSX EAX,word ptr [EAX + 0x6]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000006u)),16));
  }
  L0042034b: { // 0x42034b: 8b8eb0000000 MOV ECX,dword ptr [ESI + 0xb0]
    s.cx = m.r32((s.si+0x000000b0u));
  }
  L00420351: { // 0x420351: 898188020000 MOV dword ptr [ECX + 0x288],EAX
    m.w32((s.cx+0x00000288u), s.ax);
  }
  L00420357: { // 0x420357: 8b8eb0000000 MOV ECX,dword ptr [ESI + 0xb0]
    s.cx = m.r32((s.si+0x000000b0u));
  }
  L0042035d: { // 0x42035d: 38992d030000 CMP byte ptr [ECX + 0x32d],BL
    (void)integer::sub(m.r8((s.cx+0x0000032du)),(s.bx & 0xffu),8,flags);
  }
  L00420363: { // 0x420363: 7411 JZ 0x00420376
    if(integer::condition("JZ",flags)) goto L00420376;
  }
  L00420365: { // 0x420365: 8b8188020000 MOV EAX,dword ptr [ECX + 0x288]
    s.ax = m.r32((s.cx+0x00000288u));
  }
  L0042036b: { // 0x42036b: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0042036c: { // 0x42036c: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0042036e: { // 0x42036e: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00420370: { // 0x420370: 898188020000 MOV dword ptr [ECX + 0x288],EAX
    m.w32((s.cx+0x00000288u), s.ax);
  }
  L00420376: { // 0x420376: 8b86b0000000 MOV EAX,dword ptr [ESI + 0xb0]
    s.ax = m.r32((s.si+0x000000b0u));
  }
  L0042037c: { // 0x42037c: 39b884020000 CMP dword ptr [EAX + 0x284],EDI
    (void)integer::sub(m.r32((s.ax+0x00000284u)),s.di,32,flags);
  }
  L00420382: { // 0x420382: 750c JNZ 0x00420390
    if(integer::condition("JNZ",flags)) goto L00420390;
  }
  L00420384: { // 0x420384: 8b9088020000 MOV EDX,dword ptr [EAX + 0x288]
    s.dx = m.r32((s.ax+0x00000288u));
  }
  L0042038a: { // 0x42038a: 899084020000 MOV dword ptr [EAX + 0x284],EDX
    m.w32((s.ax+0x00000284u), s.dx);
  }
  L00420390: { // 0x420390: 8b451c MOV EAX,dword ptr [EBP + 0x1c]
    s.ax = m.r32((s.bp+0x0000001cu));
  }
  L00420393: { // 0x420393: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00420395: { // 0x420395: 7408 JZ 0x0042039f
    if(integer::condition("JZ",flags)) goto L0042039f;
  }
  L00420397: { // 0x420397: 8986e8000000 MOV dword ptr [ESI + 0xe8],EAX
    m.w32((s.si+0x000000e8u), s.ax);
  }
  L0042039d: { // 0x42039d: eb12 JMP 0x004203b1
    goto L004203b1;
  }
  L0042039f: { // 0x42039f: 8b86b0000000 MOV EAX,dword ptr [ESI + 0xb0]
    s.ax = m.r32((s.si+0x000000b0u));
  }
  L004203a5: { // 0x4203a5: 8b8808030000 MOV ECX,dword ptr [EAX + 0x308]
    s.cx = m.r32((s.ax+0x00000308u));
  }
  L004203ab: { // 0x4203ab: 898ee8000000 MOV dword ptr [ESI + 0xe8],ECX
    m.w32((s.si+0x000000e8u), s.cx);
  }
  L004203b1: { // 0x4203b1: 8b8eb0000000 MOV ECX,dword ptr [ESI + 0xb0]
    s.cx = m.r32((s.si+0x000000b0u));
  }
  L004203b7: { // 0x4203b7: 8b91a4020000 MOV EDX,dword ptr [ECX + 0x2a4]
    s.dx = m.r32((s.cx+0x000002a4u));
  }
  L004203bd: { // 0x4203bd: 8b8178020000 MOV EAX,dword ptr [ECX + 0x278]
    s.ax = m.r32((s.cx+0x00000278u));
  }
  L004203c3: { // 0x4203c3: 3bd3 CMP EDX,EBX
    (void)integer::sub(s.dx,s.bx,32,flags);
  }
  L004203c5: { // 0x4203c5: 7508 JNZ 0x004203cf
    if(integer::condition("JNZ",flags)) goto L004203cf;
  }
  L004203c7: { // 0x4203c7: 3999a8020000 CMP dword ptr [ECX + 0x2a8],EBX
    (void)integer::sub(m.r32((s.cx+0x000002a8u)),s.bx,32,flags);
  }
  L004203cd: { // 0x4203cd: 741d JZ 0x004203ec
    if(integer::condition("JZ",flags)) goto L004203ec;
  }
  L004203cf: { // 0x4203cf: 8b89a8020000 MOV ECX,dword ptr [ECX + 0x2a8]
    s.cx = m.r32((s.cx+0x000002a8u));
  }
  L004203d5: { // 0x4203d5: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L004203d7: { // 0x4203d7: 7f13 JG 0x004203ec
    if(integer::condition("JG",flags)) goto L004203ec;
  }
  L004203d9: { // 0x4203d9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004203da: { // 0x4203da: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004203db: { // 0x4203db: 8b15c055a200 MOV EDX,dword ptr [0x00a255c0]
    s.dx = m.r32((0x00a255c0u));
  }
  L004203e1: { // 0x4203e1: 8d8a18020000 LEA ECX,[EDX + 0x218]
    s.cx = (s.dx+0x00000218u);
  }
  L004203e7: { // 0x4203e7: e854fa2000 CALL 0x0062fe40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fe40u,4326380u); flags=s.arithmetic_flags;
  }
  L004203ec: { // 0x4203ec: 8b8eb0000000 MOV ECX,dword ptr [ESI + 0xb0]
    s.cx = m.r32((s.si+0x000000b0u));
  }
  L004203f2: { // 0x4203f2: 38991e030000 CMP byte ptr [ECX + 0x31e],BL
    (void)integer::sub(m.r8((s.cx+0x0000031eu)),(s.bx & 0xffu),8,flags);
  }
  L004203f8: { // 0x4203f8: 7423 JZ 0x0042041d
    if(integer::condition("JZ",flags)) goto L0042041d;
  }
  L004203fa: { // 0x4203fa: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004203fb: { // 0x4203fb: b95887a200 MOV ECX,0xa28758
    s.cx = 0x00a28758u;
  }
  L00420400: { // 0x420400: e8db191b00 CALL 0x005d1de0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005d1de0u,4326405u); flags=s.arithmetic_flags;
  }
  L00420405: { // 0x420405: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  L0042040b: { // 0x42040b: 8d969c000000 LEA EDX,[ESI + 0x9c]
    s.dx = (s.si+0x0000009cu);
  }
  L00420411: { // 0x420411: 898e9c000000 MOV dword ptr [ESI + 0x9c],ECX
    m.w32((s.si+0x0000009cu), s.cx);
  }
  L00420417: { // 0x420417: 8b4c2434 MOV ECX,dword ptr [ESP + 0x34]
    s.cx = m.r32((f.sp+0x00000034u));
  }
  L0042041b: { // 0x42041b: eb16 JMP 0x00420433
    goto L00420433;
  }
  L0042041d: { // 0x42041d: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  L00420423: { // 0x420423: 8d969c000000 LEA EDX,[ESI + 0x9c]
    s.dx = (s.si+0x0000009cu);
  }
  L00420429: { // 0x420429: 898e9c000000 MOV dword ptr [ESI + 0x9c],ECX
    m.w32((s.si+0x0000009cu), s.cx);
  }
  L0042042f: { // 0x42042f: 8b4c2434 MOV ECX,dword ptr [ESP + 0x34]
    s.cx = m.r32((f.sp+0x00000034u));
  }
  L00420433: { // 0x420433: 894a04 MOV dword ptr [EDX + 0x4],ECX
    m.w32((s.dx+0x00000004u), s.cx);
  }
  L00420436: { // 0x420436: 894208 MOV dword ptr [EDX + 0x8],EAX
    m.w32((s.dx+0x00000008u), s.ax);
  }
  L00420439: { // 0x420439: 8986a8000000 MOV dword ptr [ESI + 0xa8],EAX
    m.w32((s.si+0x000000a8u), s.ax);
  }
  L0042043f: { // 0x42043f: 8b96b0000000 MOV EDX,dword ptr [ESI + 0xb0]
    s.dx = m.r32((s.si+0x000000b0u));
  }
  L00420445: { // 0x420445: 899e98000000 MOV dword ptr [ESI + 0x98],EBX
    m.w32((s.si+0x00000098u), s.bx);
  }
  L0042044b: { // 0x42044b: 8b8220030000 MOV EAX,dword ptr [EDX + 0x320]
    s.ax = m.r32((s.dx+0x00000320u));
  }
  L00420451: { // 0x420451: 83f803 CMP EAX,0x3
    (void)integer::sub(s.ax,0x00000003u,32,flags);
  }
  L00420454: { // 0x420454: 740f JZ 0x00420465
    if(integer::condition("JZ",flags)) goto L00420465;
  }
  L00420456: { // 0x420456: 83f804 CMP EAX,0x4
    (void)integer::sub(s.ax,0x00000004u,32,flags);
  }
  L00420459: { // 0x420459: 740a JZ 0x00420465
    if(integer::condition("JZ",flags)) goto L00420465;
  }
  L0042045b: { // 0x42045b: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0042045c: { // 0x42045c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0042045e: { // 0x42045e: e88dca1a00 CALL 0x005ccef0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005ccef0u,4326499u); flags=s.arithmetic_flags;
  }
  L00420463: { // 0x420463: eb13 JMP 0x00420478
    goto L00420478;
  }
  L00420465: { // 0x420465: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L0042046a: { // 0x42046a: 8b88dc060000 MOV ECX,dword ptr [EAX + 0x6dc]
    s.cx = m.r32((s.ax+0x000006dcu));
  }
  L00420470: { // 0x420470: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00420471: { // 0x420471: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00420473: { // 0x420473: e838cb1a00 CALL 0x005ccfb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005ccfb0u,4326520u); flags=s.arithmetic_flags;
  }
  L00420478: { // 0x420478: 8b86b0000000 MOV EAX,dword ptr [ESI + 0xb0]
    s.ax = m.r32((s.si+0x000000b0u));
  }
  L0042047e: { // 0x42047e: 38982c030000 CMP byte ptr [EAX + 0x32c],BL
    (void)integer::sub(m.r8((s.ax+0x0000032cu)),(s.bx & 0xffu),8,flags);
  }
  L00420484: { // 0x420484: 741a JZ 0x004204a0
    if(integer::condition("JZ",flags)) goto L004204a0;
  }
  L00420486: { // 0x420486: 8b9084020000 MOV EDX,dword ptr [EAX + 0x284]
    s.dx = m.r32((s.ax+0x00000284u));
  }
  L0042048c: { // 0x42048c: 899698000000 MOV dword ptr [ESI + 0x98],EDX
    m.w32((s.si+0x00000098u), s.dx);
  }
  L00420492: { // 0x420492: 8b86ac000000 MOV EAX,dword ptr [ESI + 0xac]
    s.ax = m.r32((s.si+0x000000acu));
  }
  L00420498: { // 0x420498: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L0042049a: { // 0x42049a: 8986ac000000 MOV dword ptr [ESI + 0xac],EAX
    m.w32((s.si+0x000000acu), s.ax);
  }
  L004204a0: { // 0x4204a0: 8b86b0000000 MOV EAX,dword ptr [ESI + 0xb0]
    s.ax = m.r32((s.si+0x000000b0u));
  }
  L004204a6: { // 0x4204a6: 389816030000 CMP byte ptr [EAX + 0x316],BL
    (void)integer::sub(m.r8((s.ax+0x00000316u)),(s.bx & 0xffu),8,flags);
  }
  L004204ac: { // 0x4204ac: 7519 JNZ 0x004204c7
    if(integer::condition("JNZ",flags)) goto L004204c7;
  }
  L004204ae: { // 0x4204ae: 389812030000 CMP byte ptr [EAX + 0x312],BL
    (void)integer::sub(m.r8((s.ax+0x00000312u)),(s.bx & 0xffu),8,flags);
  }
  L004204b4: { // 0x4204b4: 7511 JNZ 0x004204c7
    if(integer::condition("JNZ",flags)) goto L004204c7;
  }
  L004204b6: { // 0x4204b6: 8b4d0c MOV ECX,dword ptr [EBP + 0xc]
    s.cx = m.r32((s.bp+0x0000000cu));
  }
  L004204b9: { // 0x4204b9: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004204ba: { // 0x4204ba: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004204bb: { // 0x4204bb: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004204bd: { // 0x4204bd: e85eba1a00 CALL 0x005cbf20
    s.arithmetic_flags=flags; invoke(m,s,f,0x005cbf20u,4326594u); flags=s.arithmetic_flags;
  }
  L004204c2: { // 0x4204c2: e947030000 JMP 0x0042080e
    goto L0042080e;
  }
  L004204c7: { // 0x4204c7: c6867401000001 MOV byte ptr [ESI + 0x174],0x1
    m.w8((s.si+0x00000174u), 0x00000001u);
  }
  L004204ce: { // 0x4204ce: 8a8812030000 MOV CL,byte ptr [EAX + 0x312]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000312u)));
  }
  L004204d4: { // 0x4204d4: 3acb CMP CL,BL
    (void)integer::sub((s.cx & 0xffu),(s.bx & 0xffu),8,flags);
  }
  L004204d6: { // 0x4204d6: 0f84be010000 JZ 0x0042069a
    if(integer::condition("JZ",flags)) goto L0042069a;
  }
  L004204dc: { // 0x4204dc: 8b15c055a200 MOV EDX,dword ptr [0x00a255c0]
    s.dx = m.r32((0x00a255c0u));
  }
  L004204e2: { // 0x4204e2: 8d8a18020000 LEA ECX,[EDX + 0x218]
    s.cx = (s.dx+0x00000218u);
  }
  L004204e8: { // 0x4204e8: e8f3f82000 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,4326637u); flags=s.arithmetic_flags;
  }
  L004204ed: { // 0x4204ed: 8944240c MOV dword ptr [ESP + 0xc],EAX
    m.w32((f.sp+0x0000000cu), s.ax);
  }
  L004204f1: { // 0x4204f1: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  L004204f6: { // 0x4204f6: 8d8818020000 LEA ECX,[EAX + 0x218]
    s.cx = (s.ax+0x00000218u);
  }
  L004204fc: { // 0x4204fc: e8dff82000 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,4326657u); flags=s.arithmetic_flags;
  }
  L00420501: { // 0x420501: 8bbeb0000000 MOV EDI,dword ptr [ESI + 0xb0]
    s.di = m.r32((s.si+0x000000b0u));
  }
  L00420507: { // 0x420507: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0042050b: { // 0x42050b: dd87d8020000 FLD double ptr [EDI + 0x2d8]
    const auto address=(s.di+0x000002d8u);
    s.fp.load64(read64(m,address));
  }
  L00420511: { // 0x420511: dd87e8020000 FLD double ptr [EDI + 0x2e8]
    const auto address=(s.di+0x000002e8u);
    s.fp.load64(read64(m,address));
  }
  L00420517: { // 0x420517: dcc0 FADD ST0,ST0
    numeric_b88::detail::reg<0xdcc0>(s.fp);
  }
  L00420519: { // 0x420519: e832a53400 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4326686u); flags=s.arithmetic_flags;
  }
  L0042051e: { // 0x42051e: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00420520: { // 0x420520: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L00420524: { // 0x420524: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00420525: { // 0x420525: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L00420527: { // 0x420527: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00420529: { // 0x420529: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0042052a: { // 0x42052a: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L0042052c: { // 0x42052c: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00420530: { // 0x420530: 8954240c MOV dword ptr [ESP + 0xc],EDX
    m.w32((f.sp+0x0000000cu), s.dx);
  }
  L00420534: { // 0x420534: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00420535: { // 0x420535: db44240c FILD dword ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    s.fp.load_integer32(m.r32(address));
  }
  L00420539: { // 0x420539: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L0042053b: { // 0x42053b: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0042053d: { // 0x42053d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0042053e: { // 0x42053e: dca7e8020000 FSUB double ptr [EDI + 0x2e8]
    const auto address=(s.di+0x000002e8u);
    s.fp.subtract64(read64(m,address));
  }
  L00420544: { // 0x420544: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00420546: { // 0x420546: d954240c FST float ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    const auto value=s.fp.store32();
    m.w32(address,value);
  }
  L0042054a: { // 0x42054a: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L0042054e: { // 0x42054e: db442410 FILD dword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load_integer32(m.r32(address));
  }
  L00420552: { // 0x420552: dca7e8020000 FSUB double ptr [EDI + 0x2e8]
    const auto address=(s.di+0x000002e8u);
    s.fp.subtract64(read64(m,address));
  }
  L00420558: { // 0x420558: d95c2418 FSTP float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0042055c: { // 0x42055c: d95c241c FSTP float ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00420560: { // 0x420560: d95c2420 FSTP float ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00420564: { // 0x420564: d944240c FLD float ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    s.fp.load32(m.r32(address));
  }
  L00420568: { // 0x420568: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L0042056a: { // 0x42056a: d9442418 FLD float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load32(m.r32(address));
  }
  L0042056e: { // 0x42056e: d8d9 FCOMP
    numeric_b88::detail::reg<0xd8d9>(s.fp);
  }
  L00420570: { // 0x420570: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00420572: { // 0x420572: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00420575: { // 0x420575: 7410 JZ 0x00420587
    if(integer::condition("JZ",flags)) goto L00420587;
  }
  L00420577: { // 0x420577: d9442418 FLD float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load32(m.r32(address));
  }
  L0042057b: { // 0x42057b: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L0042057d: { // 0x42057d: d95c2418 FSTP float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00420581: { // 0x420581: d95c241c FSTP float ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00420585: { // 0x420585: eb02 JMP 0x00420589
    goto L00420589;
  }
  L00420587: { // 0x420587: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00420589: { // 0x420589: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L0042058f: { // 0x42058f: 81c118020000 ADD ECX,0x218
    s.cx = integer::add(s.cx,0x00000218u,32,flags);
  }
  L00420595: { // 0x420595: e846f82000 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,4326810u); flags=s.arithmetic_flags;
  }
  L0042059a: { // 0x42059a: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0042059b: { // 0x42059b: b914000000 MOV ECX,0x14
    s.cx = 0x00000014u;
  }
  L004205a0: { // 0x4205a0: 8b7d0c MOV EDI,dword ptr [EBP + 0xc]
    s.di = m.r32((s.bp+0x0000000cu));
  }
  L004205a3: { // 0x4205a3: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L004205a5: { // 0x4205a5: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L004205a7: { // 0x4205a7: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004205a8: { // 0x4205a8: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L004205aa: { // 0x4205aa: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004205ac: { // 0x4205ac: ba46000000 MOV EDX,0x46
    s.dx = 0x00000046u;
  }
  L004205b1: { // 0x4205b1: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L004205b3: { // 0x4205b3: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L004205b7: { // 0x4205b7: db442410 FILD dword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load_integer32(m.r32(address));
  }
  L004205bb: { // 0x4205bb: db07 FILD dword ptr [EDI]
    const auto address=(s.di);
    s.fp.load_integer32(m.r32(address));
  }
  L004205bd: { // 0x4205bd: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L004205bf: { // 0x4205bf: d84c2418 FMUL float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.multiply32(m.r32(address));
  }
  L004205c3: { // 0x4205c3: dee9 FSUBP
    numeric_b88::detail::reg<0xdee9>(s.fp);
  }
  L004205c5: { // 0x4205c5: e886a43400 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4326858u); flags=s.arithmetic_flags;
  }
  L004205ca: { // 0x4205ca: db4704 FILD dword ptr [EDI + 0x4]
    const auto address=(s.di+0x00000004u);
    s.fp.load_integer32(m.r32(address));
  }
  L004205cd: { // 0x4205cd: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L004205cf: { // 0x4205cf: d84c241c FMUL float ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    s.fp.multiply32(m.r32(address));
  }
  L004205d3: { // 0x4205d3: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L004205d7: { // 0x4205d7: dee9 FSUBP
    numeric_b88::detail::reg<0xdee9>(s.fp);
  }
  L004205d9: { // 0x4205d9: e872a43400 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4326878u); flags=s.arithmetic_flags;
  }
  L004205de: { // 0x4205de: db4708 FILD dword ptr [EDI + 0x8]
    const auto address=(s.di+0x00000008u);
    s.fp.load_integer32(m.r32(address));
  }
  L004205e1: { // 0x4205e1: d9c9 FXCH
    numeric_b88::detail::reg<0xd9c9>(s.fp);
  }
  L004205e3: { // 0x4205e3: d84c2420 FMUL float ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.multiply32(m.r32(address));
  }
  L004205e7: { // 0x4205e7: 89442434 MOV dword ptr [ESP + 0x34],EAX
    m.w32((f.sp+0x00000034u), s.ax);
  }
  L004205eb: { // 0x4205eb: dee9 FSUBP
    numeric_b88::detail::reg<0xdee9>(s.fp);
  }
  L004205ed: { // 0x4205ed: e85ea43400 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4326898u); flags=s.arithmetic_flags;
  }
  L004205f2: { // 0x4205f2: 89442438 MOV dword ptr [ESP + 0x38],EAX
    m.w32((f.sp+0x00000038u), s.ax);
  }
  L004205f6: { // 0x4205f6: 8d442430 LEA EAX,[ESP + 0x30]
    s.ax = (f.sp+0x00000030u);
  }
  L004205fa: { // 0x4205fa: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004205fb: { // 0x4205fb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004205fc: { // 0x4205fc: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004205fe: { // 0x4205fe: e81db91a00 CALL 0x005cbf20
    s.arithmetic_flags=flags; invoke(m,s,f,0x005cbf20u,4326915u); flags=s.arithmetic_flags;
  }
  L00420603: { // 0x420603: 399eb4000000 CMP dword ptr [ESI + 0xb4],EBX
    (void)integer::sub(m.r32((s.si+0x000000b4u)),s.bx,32,flags);
  }
  L00420609: { // 0x420609: 743e JZ 0x00420649
    if(integer::condition("JZ",flags)) goto L00420649;
  }
  L0042060b: { // 0x42060b: 8d4c243c LEA ECX,[ESP + 0x3c]
    s.cx = (f.sp+0x0000003cu);
  }
  L0042060f: { // 0x42060f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00420610: { // 0x420610: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00420612: { // 0x420612: e8b9ce1a00 CALL 0x005cd4d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005cd4d0u,4326935u); flags=s.arithmetic_flags;
  }
  L00420617: { // 0x420617: 8b8eb4000000 MOV ECX,dword ptr [ESI + 0xb4]
    s.cx = m.r32((s.si+0x000000b4u));
  }
  L0042061d: { // 0x42061d: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0042061f: { // 0x42061f: 8d442448 LEA EAX,[ESP + 0x48]
    s.ax = (f.sp+0x00000048u);
  }
  L00420623: { // 0x420623: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00420625: { // 0x420625: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00420626: { // 0x420626: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),4326953u); flags=s.arithmetic_flags;
  }
  L00420629: { // 0x420629: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0042062b: { // 0x42062b: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L0042062d: { // 0x42062d: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L0042062f: { // 0x42062f: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L00420632: { // 0x420632: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L00420635: { // 0x420635: 035704 ADD EDX,dword ptr [EDI + 0x4]
    s.dx = integer::add(s.dx,m.r32((s.di+0x00000004u)),32,flags);
  }
  L00420638: { // 0x420638: 034708 ADD EAX,dword ptr [EDI + 0x8]
    s.ax = integer::add(s.ax,m.r32((s.di+0x00000008u)),32,flags);
  }
  L0042063b: { // 0x42063b: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L0042063f: { // 0x42063f: 89542428 MOV dword ptr [ESP + 0x28],EDX
    m.w32((f.sp+0x00000028u), s.dx);
  }
  L00420643: { // 0x420643: 8944242c MOV dword ptr [ESP + 0x2c],EAX
    m.w32((f.sp+0x0000002cu), s.ax);
  }
  L00420647: { // 0x420647: eb20 JMP 0x00420669
    goto L00420669;
  }
  L00420649: { // 0x420649: 8d4c2454 LEA ECX,[ESP + 0x54]
    s.cx = (f.sp+0x00000054u);
  }
  L0042064d: { // 0x42064d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0042064e: { // 0x42064e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00420650: { // 0x420650: e87bce1a00 CALL 0x005cd4d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005cd4d0u,4326997u); flags=s.arithmetic_flags;
  }
  L00420655: { // 0x420655: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00420657: { // 0x420657: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L0042065b: { // 0x42065b: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L0042065e: { // 0x42065e: 894c2428 MOV dword ptr [ESP + 0x28],ECX
    m.w32((f.sp+0x00000028u), s.cx);
  }
  L00420662: { // 0x420662: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L00420665: { // 0x420665: 8954242c MOV dword ptr [ESP + 0x2c],EDX
    m.w32((f.sp+0x0000002cu), s.dx);
  }
  L00420669: { // 0x420669: 8b8eb0000000 MOV ECX,dword ptr [ESI + 0xb0]
    s.cx = m.r32((s.si+0x000000b0u));
  }
  L0042066f: { // 0x42066f: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00420670: { // 0x420670: 8d44241c LEA EAX,[ESP + 0x1c]
    s.ax = (f.sp+0x0000001cu);
  }
  L00420674: { // 0x420674: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00420675: { // 0x420675: 8b91d4020000 MOV EDX,dword ptr [ECX + 0x2d4]
    s.dx = m.r32((s.cx+0x000002d4u));
  }
  L0042067b: { // 0x42067b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0042067c: { // 0x42067c: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0042067d: { // 0x42067d: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0042067e: { // 0x42067e: 8b81d0020000 MOV EAX,dword ptr [ECX + 0x2d0]
    s.ax = m.r32((s.cx+0x000002d0u));
  }
  L00420684: { // 0x420684: 686666f63f PUSH 0x3ff66666
    f.push(m,0x3ff66666u);
  }
  L00420689: { // 0x420689: 6800000060 PUSH 0x60000000
    f.push(m,0x60000000u);
  }
  L0042068e: { // 0x42068e: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0042068f: { // 0x42068f: 8d4c2444 LEA ECX,[ESP + 0x44]
    s.cx = (f.sp+0x00000044u);
  }
  L00420693: { // 0x420693: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00420694: { // 0x420694: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00420695: { // 0x420695: e969010000 JMP 0x00420803
    goto L00420803;
  }
  L0042069a: { // 0x42069a: 8b550c MOV EDX,dword ptr [EBP + 0xc]
    s.dx = m.r32((s.bp+0x0000000cu));
  }
  L0042069d: { // 0x42069d: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0042069e: { // 0x42069e: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0042069f: { // 0x42069f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004206a1: { // 0x4206a1: e87ab81a00 CALL 0x005cbf20
    s.arithmetic_flags=flags; invoke(m,s,f,0x005cbf20u,4327078u); flags=s.arithmetic_flags;
  }
  L004206a6: { // 0x4206a6: 399eb4000000 CMP dword ptr [ESI + 0xb4],EBX
    (void)integer::sub(m.r32((s.si+0x000000b4u)),s.bx,32,flags);
  }
  L004206ac: { // 0x4206ac: 7436 JZ 0x004206e4
    if(integer::condition("JZ",flags)) goto L004206e4;
  }
  L004206ae: { // 0x4206ae: 8d442454 LEA EAX,[ESP + 0x54]
    s.ax = (f.sp+0x00000054u);
  }
  L004206b2: { // 0x4206b2: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004206b4: { // 0x4206b4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004206b5: { // 0x4206b5: e816ce1a00 CALL 0x005cd4d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005cd4d0u,4327098u); flags=s.arithmetic_flags;
  }
  L004206ba: { // 0x4206ba: 8b8eb4000000 MOV ECX,dword ptr [ESI + 0xb4]
    s.cx = m.r32((s.si+0x000000b4u));
  }
  L004206c0: { // 0x4206c0: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L004206c2: { // 0x4206c2: 8d442448 LEA EAX,[ESP + 0x48]
    s.ax = (f.sp+0x00000048u);
  }
  L004206c6: { // 0x4206c6: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L004206c8: { // 0x4206c8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004206c9: { // 0x4206c9: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),4327116u); flags=s.arithmetic_flags;
  }
  L004206cc: { // 0x4206cc: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  L004206ce: { // 0x4206ce: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L004206d0: { // 0x4206d0: 8b5f04 MOV EBX,dword ptr [EDI + 0x4]
    s.bx = m.r32((s.di+0x00000004u));
  }
  L004206d3: { // 0x4206d3: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L004206d5: { // 0x4206d5: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L004206d8: { // 0x4206d8: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L004206db: { // 0x4206db: 03d3 ADD EDX,EBX
    s.dx = integer::add(s.dx,s.bx,32,flags);
  }
  L004206dd: { // 0x4206dd: 8b5f08 MOV EBX,dword ptr [EDI + 0x8]
    s.bx = m.r32((s.di+0x00000008u));
  }
  L004206e0: { // 0x4206e0: 03c3 ADD EAX,EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L004206e2: { // 0x4206e2: eb14 JMP 0x004206f8
    goto L004206f8;
  }
  L004206e4: { // 0x4206e4: 8d4c243c LEA ECX,[ESP + 0x3c]
    s.cx = (f.sp+0x0000003cu);
  }
  L004206e8: { // 0x4206e8: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004206e9: { // 0x4206e9: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004206eb: { // 0x4206eb: e8e0cd1a00 CALL 0x005cd4d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005cd4d0u,4327152u); flags=s.arithmetic_flags;
  }
  L004206f0: { // 0x4206f0: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L004206f2: { // 0x4206f2: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L004206f5: { // 0x4206f5: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L004206f8: { // 0x4206f8: 89542428 MOV dword ptr [ESP + 0x28],EDX
    m.w32((f.sp+0x00000028u), s.dx);
  }
  L004206fc: { // 0x4206fc: 8b15c055a200 MOV EDX,dword ptr [0x00a255c0]
    s.dx = m.r32((0x00a255c0u));
  }
  L00420702: { // 0x420702: 83c00a ADD EAX,0xa
    s.ax = integer::add(s.ax,0x0000000au,32,flags);
  }
  L00420705: { // 0x420705: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L00420709: { // 0x420709: 8d8a18020000 LEA ECX,[EDX + 0x218]
    s.cx = (s.dx+0x00000218u);
  }
  L0042070f: { // 0x42070f: 8944242c MOV dword ptr [ESP + 0x2c],EAX
    m.w32((f.sp+0x0000002cu), s.ax);
  }
  L00420713: { // 0x420713: e8c8f62000 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,4327192u); flags=s.arithmetic_flags;
  }
  L00420718: { // 0x420718: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0042071a: { // 0x42071a: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  L0042071f: { // 0x42071f: 8d8818020000 LEA ECX,[EAX + 0x218]
    s.cx = (s.ax+0x00000218u);
  }
  L00420725: { // 0x420725: e8b6f62000 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,4327210u); flags=s.arithmetic_flags;
  }
  L0042072a: { // 0x42072a: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L00420730: { // 0x420730: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00420734: { // 0x420734: 81c118020000 ADD ECX,0x218
    s.cx = integer::add(s.cx,0x00000218u,32,flags);
  }
  L0042073a: { // 0x42073a: e8a1f62000 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,4327231u); flags=s.arithmetic_flags;
  }
  L0042073f: { // 0x42073f: 8bbeb0000000 MOV EDI,dword ptr [ESI + 0xb0]
    s.di = m.r32((s.si+0x000000b0u));
  }
  L00420745: { // 0x420745: 8944240c MOV dword ptr [ESP + 0xc],EAX
    m.w32((f.sp+0x0000000cu), s.ax);
  }
  L00420749: { // 0x420749: dd87e8020000 FLD double ptr [EDI + 0x2e8]
    const auto address=(s.di+0x000002e8u);
    s.fp.load64(read64(m,address));
  }
  L0042074f: { // 0x42074f: dcc0 FADD ST0,ST0
    numeric_b88::detail::reg<0xdcc0>(s.fp);
  }
  L00420751: { // 0x420751: e8faa23400 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4327254u); flags=s.arithmetic_flags;
  }
  L00420756: { // 0x420756: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00420758: { // 0x420758: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0042075c: { // 0x42075c: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0042075d: { // 0x42075d: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L0042075f: { // 0x42075f: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L00420763: { // 0x420763: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00420765: { // 0x420765: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00420766: { // 0x420766: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00420768: { // 0x420768: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L0042076a: { // 0x42076a: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L0042076e: { // 0x42076e: db442410 FILD dword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load_integer32(m.r32(address));
  }
  L00420772: { // 0x420772: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00420773: { // 0x420773: dca7e8020000 FSUB double ptr [EDI + 0x2e8]
    const auto address=(s.di+0x000002e8u);
    s.fp.subtract64(read64(m,address));
  }
  L00420779: { // 0x420779: dd87e0020000 FLD double ptr [EDI + 0x2e0]
    const auto address=(s.di+0x000002e0u);
    s.fp.load64(read64(m,address));
  }
  L0042077f: { // 0x42077f: dca7d8020000 FSUB double ptr [EDI + 0x2d8]
    const auto address=(s.di+0x000002d8u);
    s.fp.subtract64(read64(m,address));
  }
  L00420785: { // 0x420785: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00420787: { // 0x420787: 33da XOR EBX,EDX
    s.bx = integer::logical((s.bx)^(s.dx),32,flags);
  }
  L00420789: { // 0x420789: dc0508577800 FADD double ptr [0x00785708]
    const auto address=(0x00785708u);
    s.fp.add64(read64(m,address));
  }
  L0042078f: { // 0x42078f: 2bda SUB EBX,EDX
    s.bx = integer::sub(s.bx,s.dx,32,flags);
  }
  L00420791: { // 0x420791: e8baa23400 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4327318u); flags=s.arithmetic_flags;
  }
  L00420796: { // 0x420796: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00420798: { // 0x420798: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L0042079a: { // 0x42079a: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0042079b: { // 0x42079b: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L0042079d: { // 0x42079d: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L004207a1: { // 0x4207a1: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L004207a5: { // 0x4207a5: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004207a6: { // 0x4207a6: db442410 FILD dword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load_integer32(m.r32(address));
  }
  L004207aa: { // 0x4207aa: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L004207ac: { // 0x4207ac: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004207ae: { // 0x4207ae: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004207af: { // 0x4207af: dc87d8020000 FADD double ptr [EDI + 0x2d8]
    const auto address=(s.di+0x000002d8u);
    s.fp.add64(read64(m,address));
  }
  L004207b5: { // 0x4207b5: f77c2414 IDIV dword ptr [ESP + 0x14]
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(m.r32((f.sp+0x00000014u)),32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L004207b9: { // 0x4207b9: d95c2410 FSTP float ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L004207bd: { // 0x4207bd: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L004207bf: { // 0x4207bf: 8d442430 LEA EAX,[ESP + 0x30]
    s.ax = (f.sp+0x00000030u);
  }
  L004207c3: { // 0x4207c3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004207c4: { // 0x4207c4: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004207c5: { // 0x4207c5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004207c6: { // 0x4207c6: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004207c7: { // 0x4207c7: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004207c8: { // 0x4207c8: 686666f63f PUSH 0x3ff66666
    f.push(m,0x3ff66666u);
  }
  L004207cd: { // 0x4207cd: 6800000060 PUSH 0x60000000
    f.push(m,0x60000000u);
  }
  L004207d2: { // 0x4207d2: 8d442440 LEA EAX,[ESP + 0x40]
    s.ax = (f.sp+0x00000040u);
  }
  L004207d6: { // 0x4207d6: 89542430 MOV dword ptr [ESP + 0x30],EDX
    m.w32((f.sp+0x00000030u), s.dx);
  }
  L004207da: { // 0x4207da: 8b54242c MOV EDX,dword ptr [ESP + 0x2c]
    s.dx = m.r32((f.sp+0x0000002cu));
  }
  L004207de: { // 0x4207de: db442430 FILD dword ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.load_integer32(m.r32(address));
  }
  L004207e2: { // 0x4207e2: dca7e8020000 FSUB double ptr [EDI + 0x2e8]
    const auto address=(s.di+0x000002e8u);
    s.fp.subtract64(read64(m,address));
  }
  L004207e8: { // 0x4207e8: 89542454 MOV dword ptr [ESP + 0x54],EDX
    m.w32((f.sp+0x00000054u), s.dx);
  }
  L004207ec: { // 0x4207ec: d95c244c FSTP float ptr [ESP + 0x4c]
    const auto address=(f.sp+0x0000004cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L004207f0: { // 0x4207f0: d95c2450 FSTP float ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L004207f4: { // 0x4207f4: 8b8fd4020000 MOV ECX,dword ptr [EDI + 0x2d4]
    s.cx = m.r32((s.di+0x000002d4u));
  }
  L004207fa: { // 0x4207fa: 8b97d0020000 MOV EDX,dword ptr [EDI + 0x2d0]
    s.dx = m.r32((s.di+0x000002d0u));
  }
  L00420800: { // 0x420800: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00420801: { // 0x420801: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00420802: { // 0x420802: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00420803: { // 0x420803: 8d8e08010000 LEA ECX,[ESI + 0x108]
    s.cx = (s.si+0x00000108u);
  }
  L00420809: { // 0x420809: e832640100 CALL 0x00436c40
    s.arithmetic_flags=flags; invoke(m,s,f,0x00436c40u,4327438u); flags=s.arithmetic_flags;
  }
  L0042080e: { // 0x42080e: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L00420813: { // 0x420813: 8b8eb0000000 MOV ECX,dword ptr [ESI + 0xb0]
    s.cx = m.r32((s.si+0x000000b0u));
  }
  L00420819: { // 0x420819: 3b88e4100000 CMP ECX,dword ptr [EAX + 0x10e4]
    (void)integer::sub(s.cx,m.r32((s.ax+0x000010e4u)),32,flags);
  }
  L0042081f: { // 0x42081f: 755f JNZ 0x00420880
    if(integer::condition("JNZ",flags)) goto L00420880;
  }
  L00420821: { // 0x420821: 8b15e4e0a100 MOV EDX,dword ptr [0x00a1e0e4]
    s.dx = m.r32((0x00a1e0e4u));
  }
  L00420827: { // 0x420827: 8b8024110000 MOV EAX,dword ptr [EAX + 0x1124]
    s.ax = m.r32((s.ax+0x00001124u));
  }
  L0042082d: { // 0x42082d: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0042082e: { // 0x42082e: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00420830: { // 0x420830: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00420831: { // 0x420831: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00420832: { // 0x420832: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00420833: { // 0x420833: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00420834: { // 0x420834: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00420835: { // 0x420835: 8b7d0c MOV EDI,dword ptr [EBP + 0xc]
    s.di = m.r32((s.bp+0x0000000cu));
  }
  L00420838: { // 0x420838: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0042083e: { // 0x42083e: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00420840: { // 0x420840: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00420845: { // 0x420845: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00420848: { // 0x420848: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00420849: { // 0x420849: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0042084a: { // 0x42084a: e8516d1200 CALL 0x005475a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005475a0u,4327503u); flags=s.arithmetic_flags;
  }
  L0042084f: { // 0x42084f: a1e4e0a100 MOV EAX,[0x00a1e0e4]
    s.ax = m.r32((0x00a1e0e4u));
  }
  L00420854: { // 0x420854: 8b0d881b8200 MOV ECX,dword ptr [0x00821b88]
    s.cx = m.r32((0x00821b88u));
  }
  L0042085a: { // 0x42085a: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0042085c: { // 0x42085c: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0042085e: { // 0x42085e: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0042085f: { // 0x42085f: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00420860: { // 0x420860: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00420861: { // 0x420861: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00420862: { // 0x420862: 8b8124110000 MOV EAX,dword ptr [ECX + 0x1124]
    s.ax = m.r32((s.cx+0x00001124u));
  }
  L00420868: { // 0x420868: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0042086d: { // 0x42086d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0042086e: { // 0x42086e: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00420874: { // 0x420874: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00420876: { // 0x420876: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00420879: { // 0x420879: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0042087a: { // 0x42087a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0042087b: { // 0x42087b: e8206d1200 CALL 0x005475a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005475a0u,4327552u); flags=s.arithmetic_flags;
  }
  L00420880: { // 0x420880: 8b4d14 MOV ECX,dword ptr [EBP + 0x14]
    s.cx = m.r32((s.bp+0x00000014u));
  }
  L00420883: { // 0x420883: 83f901 CMP ECX,0x1
    (void)integer::sub(s.cx,0x00000001u,32,flags);
  }
  L00420886: { // 0x420886: 7f05 JG 0x0042088d
    if(integer::condition("JG",flags)) goto L0042088d;
  }
  L00420888: { // 0x420888: b901000000 MOV ECX,0x1
    s.cx = 0x00000001u;
  }
  L0042088d: { // 0x42088d: 8b96b0000000 MOV EDX,dword ptr [ESI + 0xb0]
    s.dx = m.r32((s.si+0x000000b0u));
  }
  L00420893: { // 0x420893: 8a828c020000 MOV AL,byte ptr [EDX + 0x28c]
    s.ax = with_al(s.ax, m.r8((s.dx+0x0000028cu)));
  }
  L00420899: { // 0x420899: f6e9 IMUL CL
    const auto product=integer::sign_extend(s.ax,8)*integer::sign_extend((s.cx & 0xffu),8);
    s.ax=with_ax(s.ax,std::uint32_t(product));
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,8)?integer::CF|integer::OF:0);
  }
  L0042089b: { // 0x42089b: 3c01 CMP AL,0x1
    (void)integer::sub((s.ax & 0xffu),0x00000001u,8,flags);
  }
  L0042089d: { // 0x42089d: 888675010000 MOV byte ptr [ESI + 0x175],AL
    m.w8((s.si+0x00000175u), (s.ax & 0xffu));
  }
  L004208a3: { // 0x4208a3: 7607 JBE 0x004208ac
    if(integer::condition("JBE",flags)) goto L004208ac;
  }
  L004208a5: { // 0x4208a5: 25ff000000 AND EAX,0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  L004208aa: { // 0x4208aa: eb05 JMP 0x004208b1
    goto L004208b1;
  }
  L004208ac: { // 0x4208ac: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L004208b1: { // 0x4208b1: 888675010000 MOV byte ptr [ESI + 0x175],AL
    m.w8((s.si+0x00000175u), (s.ax & 0xffu));
  }
  L004208b7: { // 0x4208b7: 8b8664010000 MOV EAX,dword ptr [ESI + 0x164]
    s.ax = m.r32((s.si+0x00000164u));
  }
  L004208bd: { // 0x4208bd: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L004208bf: { // 0x4208bf: 7507 JNZ 0x004208c8
    if(integer::condition("JNZ",flags)) goto L004208c8;
  }
  L004208c1: { // 0x4208c1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004208c3: { // 0x4208c3: e8081e0000 CALL 0x004226d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004226d0u,4327624u); flags=s.arithmetic_flags;
  }
  L004208c8: { // 0x4208c8: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004208ca: { // 0x4208ca: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004208cb: { // 0x4208cb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004208cc: { // 0x4208cc: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004208cd: { // 0x4208cd: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L004208cf: { // 0x4208cf: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004208d0: { // 0x4208d0: c21800 RET 0x18
    s.arithmetic_flags=flags; finish(m,s,f,24u); return;
  }
}
void f_001ca970(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005ca970: { // 0x5ca970: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005ca971: { // 0x5ca971: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005ca972: { // 0x5ca972: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L005ca974: { // 0x5ca974: e89755e4ff CALL 0x0040ff10
    s.arithmetic_flags=flags; invoke(m,s,f,0x0040ff10u,6072697u); flags=s.arithmetic_flags;
  }
  L005ca979: { // 0x5ca979: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L005ca97b: { // 0x5ca97b: b8ff000000 MOV EAX,0xff
    s.ax = 0x000000ffu;
  }
  L005ca980: { // 0x5ca980: 895e24 MOV dword ptr [ESI + 0x24],EBX
    m.w32((s.si+0x00000024u), s.bx);
  }
  L005ca983: { // 0x5ca983: 895e28 MOV dword ptr [ESI + 0x28],EBX
    m.w32((s.si+0x00000028u), s.bx);
  }
  L005ca986: { // 0x5ca986: 895e2c MOV dword ptr [ESI + 0x2c],EBX
    m.w32((s.si+0x0000002cu), s.bx);
  }
  L005ca989: { // 0x5ca989: 89466c MOV dword ptr [ESI + 0x6c],EAX
    m.w32((s.si+0x0000006cu), s.ax);
  }
  L005ca98c: { // 0x5ca98c: 894670 MOV dword ptr [ESI + 0x70],EAX
    m.w32((s.si+0x00000070u), s.ax);
  }
  L005ca98f: { // 0x5ca98f: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L005ca991: { // 0x5ca991: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  L005ca994: { // 0x5ca994: 884676 MOV byte ptr [ESI + 0x76],AL
    m.w8((s.si+0x00000076u), (s.ax & 0xffu));
  }
  L005ca997: { // 0x5ca997: 88467d MOV byte ptr [ESI + 0x7d],AL
    m.w8((s.si+0x0000007du), (s.ax & 0xffu));
  }
  L005ca99a: { // 0x5ca99a: 888685000000 MOV byte ptr [ESI + 0x85],AL
    m.w8((s.si+0x00000085u), (s.ax & 0xffu));
  }
  L005ca9a0: { // 0x5ca9a0: 895e30 MOV dword ptr [ESI + 0x30],EBX
    m.w32((s.si+0x00000030u), s.bx);
  }
  L005ca9a3: { // 0x5ca9a3: 895e34 MOV dword ptr [ESI + 0x34],EBX
    m.w32((s.si+0x00000034u), s.bx);
  }
  L005ca9a6: { // 0x5ca9a6: 895e38 MOV dword ptr [ESI + 0x38],EBX
    m.w32((s.si+0x00000038u), s.bx);
  }
  L005ca9a9: { // 0x5ca9a9: 894e64 MOV dword ptr [ESI + 0x64],ECX
    m.w32((s.si+0x00000064u), s.cx);
  }
  L005ca9ac: { // 0x5ca9ac: 885e68 MOV byte ptr [ESI + 0x68],BL
    m.w8((s.si+0x00000068u), (s.bx & 0xffu));
  }
  L005ca9af: { // 0x5ca9af: 885e74 MOV byte ptr [ESI + 0x74],BL
    m.w8((s.si+0x00000074u), (s.bx & 0xffu));
  }
  L005ca9b2: { // 0x5ca9b2: 885e75 MOV byte ptr [ESI + 0x75],BL
    m.w8((s.si+0x00000075u), (s.bx & 0xffu));
  }
  L005ca9b5: { // 0x5ca9b5: 885e77 MOV byte ptr [ESI + 0x77],BL
    m.w8((s.si+0x00000077u), (s.bx & 0xffu));
  }
  L005ca9b8: { // 0x5ca9b8: 885e78 MOV byte ptr [ESI + 0x78],BL
    m.w8((s.si+0x00000078u), (s.bx & 0xffu));
  }
  L005ca9bb: { // 0x5ca9bb: 885e79 MOV byte ptr [ESI + 0x79],BL
    m.w8((s.si+0x00000079u), (s.bx & 0xffu));
  }
  L005ca9be: { // 0x5ca9be: 885e7a MOV byte ptr [ESI + 0x7a],BL
    m.w8((s.si+0x0000007au), (s.bx & 0xffu));
  }
  L005ca9c1: { // 0x5ca9c1: 885e7b MOV byte ptr [ESI + 0x7b],BL
    m.w8((s.si+0x0000007bu), (s.bx & 0xffu));
  }
  L005ca9c4: { // 0x5ca9c4: 885e7c MOV byte ptr [ESI + 0x7c],BL
    m.w8((s.si+0x0000007cu), (s.bx & 0xffu));
  }
  L005ca9c7: { // 0x5ca9c7: 898e80000000 MOV dword ptr [ESI + 0x80],ECX
    m.w32((s.si+0x00000080u), s.cx);
  }
  L005ca9cd: { // 0x5ca9cd: 889e84000000 MOV byte ptr [ESI + 0x84],BL
    m.w8((s.si+0x00000084u), (s.bx & 0xffu));
  }
  L005ca9d3: { // 0x5ca9d3: 8b0d68aaa500 MOV ECX,dword ptr [0x00a5aa68]
    s.cx = m.r32((0x00a5aa68u));
  }
  L005ca9d9: { // 0x5ca9d9: 8d8688000000 LEA EAX,[ESI + 0x88]
    s.ax = (s.si+0x00000088u);
  }
  L005ca9df: { // 0x5ca9df: 898e88000000 MOV dword ptr [ESI + 0x88],ECX
    m.w32((s.si+0x00000088u), s.cx);
  }
  L005ca9e5: { // 0x5ca9e5: 8b156caaa500 MOV EDX,dword ptr [0x00a5aa6c]
    s.dx = m.r32((0x00a5aa6cu));
  }
  L005ca9eb: { // 0x5ca9eb: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
  L005ca9ee: { // 0x5ca9ee: 8b0d70aaa500 MOV ECX,dword ptr [0x00a5aa70]
    s.cx = m.r32((0x00a5aa70u));
  }
  L005ca9f4: { // 0x5ca9f4: 899e94000000 MOV dword ptr [ESI + 0x94],EBX
    m.w32((s.si+0x00000094u), s.bx);
  }
  L005ca9fa: { // 0x5ca9fa: c70658247900 MOV dword ptr [ESI],0x792458
    m.w32((s.si), 0x00792458u);
  }
  L005caa00: { // 0x5caa00: 894808 MOV dword ptr [EAX + 0x8],ECX
    m.w32((s.ax+0x00000008u), s.cx);
  }
  L005caa03: { // 0x5caa03: 8d4e3c LEA ECX,[ESI + 0x3c]
    s.cx = (s.si+0x0000003cu);
  }
  L005caa06: { // 0x5caa06: c746043c247900 MOV dword ptr [ESI + 0x4],0x79243c
    m.w32((s.si+0x00000004u), 0x0079243cu);
  }
  L005caa0d: { // 0x5caa0d: c7460834247900 MOV dword ptr [ESI + 0x8],0x792434
    m.w32((s.si+0x00000008u), 0x00792434u);
  }
  L005caa14: { // 0x5caa14: c7460c2c247900 MOV dword ptr [ESI + 0xc],0x79242c
    m.w32((s.si+0x0000000cu), 0x0079242cu);
  }
  L005caa1b: { // 0x5caa1b: e8d0b1e3ff CALL 0x00405bf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00405bf0u,6072864u); flags=s.arithmetic_flags;
  }
  L005caa20: { // 0x5caa20: 8d4e50 LEA ECX,[ESI + 0x50]
    s.cx = (s.si+0x00000050u);
  }
  L005caa23: { // 0x5caa23: e8c8b1e3ff CALL 0x00405bf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00405bf0u,6072872u); flags=s.arithmetic_flags;
  }
  L005caa28: { // 0x5caa28: a1c07fa200 MOV EAX,[0x00a27fc0]
    s.ax = m.r32((0x00a27fc0u));
  }
  L005caa2d: { // 0x5caa2d: 8b0dc87fa200 MOV ECX,dword ptr [0x00a27fc8]
    s.cx = m.r32((0x00a27fc8u));
  }
  L005caa33: { // 0x5caa33: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L005caa35: { // 0x5caa35: 7c2c JL 0x005caa63
    if(integer::condition("JL",flags)) goto L005caa63;
  }
  L005caa37: { // 0x5caa37: 381dc57fa200 CMP byte ptr [0x00a27fc5],BL
    (void)integer::sub(m.r8((0x00a27fc5u)),(s.bx & 0xffu),8,flags);
  }
  L005caa3d: { // 0x5caa3d: 7504 JNZ 0x005caa43
    if(integer::condition("JNZ",flags)) goto L005caa43;
  }
  L005caa3f: { // 0x5caa3f: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L005caa41: { // 0x5caa41: 7538 JNZ 0x005caa7b
    if(integer::condition("JNZ",flags)) goto L005caa7b;
  }
  L005caa43: { // 0x5caa43: 8b0dcc7fa200 MOV ECX,dword ptr [0x00a27fcc]
    s.cx = m.r32((0x00a27fccu));
  }
  L005caa49: { // 0x5caa49: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L005caa4b: { // 0x5caa4b: 7e2e JLE 0x005caa7b
    if(integer::condition("JLE",flags)) goto L005caa7b;
  }
  L005caa4d: { // 0x5caa4d: 8b15b87fa200 MOV EDX,dword ptr [0x00a27fb8]
    s.dx = m.r32((0x00a27fb8u));
  }
  L005caa53: { // 0x5caa53: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L005caa55: { // 0x5caa55: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005caa56: { // 0x5caa56: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005caa57: { // 0x5caa57: b9b87fa200 MOV ECX,0xa27fb8
    s.cx = 0x00a27fb8u;
  }
  L005caa5c: { // 0x5caa5c: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),6072927u); flags=s.arithmetic_flags;
  }
  L005caa5f: { // 0x5caa5f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005caa61: { // 0x5caa61: 7418 JZ 0x005caa7b
    if(integer::condition("JZ",flags)) goto L005caa7b;
  }
  L005caa63: { // 0x5caa63: 8b0dc87fa200 MOV ECX,dword ptr [0x00a27fc8]
    s.cx = m.r32((0x00a27fc8u));
  }
  L005caa69: { // 0x5caa69: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L005caa6b: { // 0x5caa6b: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L005caa6c: { // 0x5caa6c: 890dc87fa200 MOV dword ptr [0x00a27fc8],ECX
    m.w32((0x00a27fc8u), s.cx);
  }
  L005caa72: { // 0x5caa72: 8b0dbc7fa200 MOV ECX,dword ptr [0x00a27fbc]
    s.cx = m.r32((0x00a27fbcu));
  }
  L005caa78: { // 0x5caa78: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L005caa7b: { // 0x5caa7b: a17088aa00 MOV EAX,[0x00aa8870]
    s.ax = m.r32((0x00aa8870u));
  }
  L005caa80: { // 0x5caa80: 8b0d7888aa00 MOV ECX,dword ptr [0x00aa8878]
    s.cx = m.r32((0x00aa8878u));
  }
  L005caa86: { // 0x5caa86: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L005caa88: { // 0x5caa88: 7c2c JL 0x005caab6
    if(integer::condition("JL",flags)) goto L005caab6;
  }
  L005caa8a: { // 0x5caa8a: 381d7588aa00 CMP byte ptr [0x00aa8875],BL
    (void)integer::sub(m.r8((0x00aa8875u)),(s.bx & 0xffu),8,flags);
  }
  L005caa90: { // 0x5caa90: 7504 JNZ 0x005caa96
    if(integer::condition("JNZ",flags)) goto L005caa96;
  }
  L005caa92: { // 0x5caa92: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L005caa94: { // 0x5caa94: 7538 JNZ 0x005caace
    if(integer::condition("JNZ",flags)) goto L005caace;
  }
  L005caa96: { // 0x5caa96: 8b0d7c88aa00 MOV ECX,dword ptr [0x00aa887c]
    s.cx = m.r32((0x00aa887cu));
  }
  L005caa9c: { // 0x5caa9c: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L005caa9e: { // 0x5caa9e: 7e2e JLE 0x005caace
    if(integer::condition("JLE",flags)) goto L005caace;
  }
  L005caaa0: { // 0x5caaa0: 8b156888aa00 MOV EDX,dword ptr [0x00aa8868]
    s.dx = m.r32((0x00aa8868u));
  }
  L005caaa6: { // 0x5caaa6: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L005caaa8: { // 0x5caaa8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005caaa9: { // 0x5caaa9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005caaaa: { // 0x5caaaa: b96888aa00 MOV ECX,0xaa8868
    s.cx = 0x00aa8868u;
  }
  L005caaaf: { // 0x5caaaf: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),6073010u); flags=s.arithmetic_flags;
  }
  L005caab2: { // 0x5caab2: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005caab4: { // 0x5caab4: 7418 JZ 0x005caace
    if(integer::condition("JZ",flags)) goto L005caace;
  }
  L005caab6: { // 0x5caab6: 8b0d7888aa00 MOV ECX,dword ptr [0x00aa8878]
    s.cx = m.r32((0x00aa8878u));
  }
  L005caabc: { // 0x5caabc: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L005caabe: { // 0x5caabe: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L005caabf: { // 0x5caabf: 890d7888aa00 MOV dword ptr [0x00aa8878],ECX
    m.w32((0x00aa8878u), s.cx);
  }
  L005caac5: { // 0x5caac5: 8b0d6c88aa00 MOV ECX,dword ptr [0x00aa886c]
    s.cx = m.r32((0x00aa886cu));
  }
  L005caacb: { // 0x5caacb: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L005caace: { // 0x5caace: a1c087aa00 MOV EAX,[0x00aa87c0]
    s.ax = m.r32((0x00aa87c0u));
  }
  L005caad3: { // 0x5caad3: 8b0dc887aa00 MOV ECX,dword ptr [0x00aa87c8]
    s.cx = m.r32((0x00aa87c8u));
  }
  L005caad9: { // 0x5caad9: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L005caadb: { // 0x5caadb: 7c2c JL 0x005cab09
    if(integer::condition("JL",flags)) goto L005cab09;
  }
  L005caadd: { // 0x5caadd: 381dc587aa00 CMP byte ptr [0x00aa87c5],BL
    (void)integer::sub(m.r8((0x00aa87c5u)),(s.bx & 0xffu),8,flags);
  }
  L005caae3: { // 0x5caae3: 7504 JNZ 0x005caae9
    if(integer::condition("JNZ",flags)) goto L005caae9;
  }
  L005caae5: { // 0x5caae5: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L005caae7: { // 0x5caae7: 7538 JNZ 0x005cab21
    if(integer::condition("JNZ",flags)) goto L005cab21;
  }
  L005caae9: { // 0x5caae9: 8b0dcc87aa00 MOV ECX,dword ptr [0x00aa87cc]
    s.cx = m.r32((0x00aa87ccu));
  }
  L005caaef: { // 0x5caaef: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L005caaf1: { // 0x5caaf1: 7e2e JLE 0x005cab21
    if(integer::condition("JLE",flags)) goto L005cab21;
  }
  L005caaf3: { // 0x5caaf3: 8b15b887aa00 MOV EDX,dword ptr [0x00aa87b8]
    s.dx = m.r32((0x00aa87b8u));
  }
  L005caaf9: { // 0x5caaf9: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L005caafb: { // 0x5caafb: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005caafc: { // 0x5caafc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005caafd: { // 0x5caafd: b9b887aa00 MOV ECX,0xaa87b8
    s.cx = 0x00aa87b8u;
  }
  L005cab02: { // 0x5cab02: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),6073093u); flags=s.arithmetic_flags;
  }
  L005cab05: { // 0x5cab05: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cab07: { // 0x5cab07: 7418 JZ 0x005cab21
    if(integer::condition("JZ",flags)) goto L005cab21;
  }
  L005cab09: { // 0x5cab09: 8b0dc887aa00 MOV ECX,dword ptr [0x00aa87c8]
    s.cx = m.r32((0x00aa87c8u));
  }
  L005cab0f: { // 0x5cab0f: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L005cab11: { // 0x5cab11: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L005cab12: { // 0x5cab12: 890dc887aa00 MOV dword ptr [0x00aa87c8],ECX
    m.w32((0x00aa87c8u), s.cx);
  }
  L005cab18: { // 0x5cab18: 8b0dbc87aa00 MOV ECX,dword ptr [0x00aa87bc]
    s.cx = m.r32((0x00aa87bcu));
  }
  L005cab1e: { // 0x5cab1e: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L005cab21: { // 0x5cab21: a16887aa00 MOV EAX,[0x00aa8768]
    s.ax = m.r32((0x00aa8768u));
  }
  L005cab26: { // 0x5cab26: 8b0d7087aa00 MOV ECX,dword ptr [0x00aa8770]
    s.cx = m.r32((0x00aa8770u));
  }
  L005cab2c: { // 0x5cab2c: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L005cab2e: { // 0x5cab2e: 7c2c JL 0x005cab5c
    if(integer::condition("JL",flags)) goto L005cab5c;
  }
  L005cab30: { // 0x5cab30: 381d6d87aa00 CMP byte ptr [0x00aa876d],BL
    (void)integer::sub(m.r8((0x00aa876du)),(s.bx & 0xffu),8,flags);
  }
  L005cab36: { // 0x5cab36: 7504 JNZ 0x005cab3c
    if(integer::condition("JNZ",flags)) goto L005cab3c;
  }
  L005cab38: { // 0x5cab38: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L005cab3a: { // 0x5cab3a: 7538 JNZ 0x005cab74
    if(integer::condition("JNZ",flags)) goto L005cab74;
  }
  L005cab3c: { // 0x5cab3c: 8b0d7487aa00 MOV ECX,dword ptr [0x00aa8774]
    s.cx = m.r32((0x00aa8774u));
  }
  L005cab42: { // 0x5cab42: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L005cab44: { // 0x5cab44: 7e2e JLE 0x005cab74
    if(integer::condition("JLE",flags)) goto L005cab74;
  }
  L005cab46: { // 0x5cab46: 8b156087aa00 MOV EDX,dword ptr [0x00aa8760]
    s.dx = m.r32((0x00aa8760u));
  }
  L005cab4c: { // 0x5cab4c: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L005cab4e: { // 0x5cab4e: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005cab4f: { // 0x5cab4f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005cab50: { // 0x5cab50: b96087aa00 MOV ECX,0xaa8760
    s.cx = 0x00aa8760u;
  }
  L005cab55: { // 0x5cab55: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),6073176u); flags=s.arithmetic_flags;
  }
  L005cab58: { // 0x5cab58: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cab5a: { // 0x5cab5a: 7418 JZ 0x005cab74
    if(integer::condition("JZ",flags)) goto L005cab74;
  }
  L005cab5c: { // 0x5cab5c: 8b0d7087aa00 MOV ECX,dword ptr [0x00aa8770]
    s.cx = m.r32((0x00aa8770u));
  }
  L005cab62: { // 0x5cab62: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L005cab64: { // 0x5cab64: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L005cab65: { // 0x5cab65: 890d7087aa00 MOV dword ptr [0x00aa8770],ECX
    m.w32((0x00aa8770u), s.cx);
  }
  L005cab6b: { // 0x5cab6b: 8b0d6487aa00 MOV ECX,dword ptr [0x00aa8764]
    s.cx = m.r32((0x00aa8764u));
  }
  L005cab71: { // 0x5cab71: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L005cab74: { // 0x5cab74: 8a4614 MOV AL,byte ptr [ESI + 0x14]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000014u)));
  }
  L005cab77: { // 0x5cab77: 0c02 OR AL,0x2
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000002u),8,flags));
  }
  L005cab79: { // 0x5cab79: 884614 MOV byte ptr [ESI + 0x14],AL
    m.w8((s.si+0x00000014u), (s.ax & 0xffu));
  }
  L005cab7c: { // 0x5cab7c: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L005cab7e: { // 0x5cab7e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005cab7f: { // 0x5cab7f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005cab80: { // 0x5cab80: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
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
void f_00005bf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00405bf0: { // 0x405bf0: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00405bf2: { // 0x405bf2: c7410cec928100 MOV dword ptr [ECX + 0xc],0x8192ec
    m.w32((s.cx+0x0000000cu), 0x008192ecu);
  }
  L00405bf9: { // 0x405bf9: 8901 MOV dword ptr [ECX],EAX
    m.w32((s.cx), s.ax);
  }
  L00405bfb: { // 0x405bfb: 894104 MOV dword ptr [ECX + 0x4],EAX
    m.w32((s.cx+0x00000004u), s.ax);
  }
  L00405bfe: { // 0x405bfe: 894108 MOV dword ptr [ECX + 0x8],EAX
    m.w32((s.cx+0x00000008u), s.ax);
  }
  L00405c01: { // 0x405c01: c3 RET
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
void f_0025a120(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0065a120: { // 0x65a120: 8b8114020000 MOV EAX,dword ptr [ECX + 0x214]
    s.ax = m.r32((s.cx+0x00000214u));
  }
  L0065a126: { // 0x65a126: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0065a127: { // 0x65a127: 898114020000 MOV dword ptr [ECX + 0x214],EAX
    m.w32((s.cx+0x00000214u), s.ax);
  }
  L0065a12d: { // 0x65a12d: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0025a130(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0065a130: { // 0x65a130: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L0065a134: { // 0x65a134: 8b8c8132060000 MOV ECX,dword ptr [ECX + EAX*0x4 + 0x632]
    s.cx = m.r32((s.cx+(s.ax * 0x00000004u)+0x00000632u));
  }
  L0065a13b: { // 0x65a13b: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L0065a13f: { // 0x65a13f: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L0065a141: { // 0x65a141: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
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
void f_00219cf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00619cf0: { // 0x619cf0: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L00619cf4: { // 0x619cf4: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00619cf6: { // 0x619cf6: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L00619cfa: { // 0x619cfa: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L00619cfc: { // 0x619cfc: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L00619d00: { // 0x619d00: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
  L00619d03: { // 0x619d03: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00619d07: { // 0x619d07: 894808 MOV dword ptr [EAX + 0x8],ECX
    m.w32((s.ax+0x00000008u), s.cx);
  }
  L00619d0a: { // 0x619d0a: 89500c MOV dword ptr [EAX + 0xc],EDX
    m.w32((s.ax+0x0000000cu), s.dx);
  }
  L00619d0d: { // 0x619d0d: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
}
void f_001ccfb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005ccfb0: { // 0x5ccfb0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005ccfb1: { // 0x5ccfb1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L005ccfb3: { // 0x5ccfb3: 8a4674 MOV AL,byte ptr [ESI + 0x74]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000074u)));
  }
  L005ccfb6: { // 0x5ccfb6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005ccfb8: { // 0x5ccfb8: 7424 JZ 0x005ccfde
    if(integer::condition("JZ",flags)) goto L005ccfde;
  }
  L005ccfba: { // 0x5ccfba: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005ccfbc: { // 0x5ccfbc: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L005ccfbe: { // 0x5ccfbe: ff901c010000 CALL dword ptr [EAX + 0x11c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000011cu)),6082500u); flags=s.arithmetic_flags;
  }
  L005ccfc4: { // 0x5ccfc4: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  L005ccfc8: { // 0x5ccfc8: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005ccfca: { // 0x5ccfca: 898e90000000 MOV dword ptr [ESI + 0x90],ECX
    m.w32((s.si+0x00000090u), s.cx);
  }
  L005ccfd0: { // 0x5ccfd0: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L005ccfd2: { // 0x5ccfd2: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005ccfd4: { // 0x5ccfd4: ff921c010000 CALL dword ptr [EDX + 0x11c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000011cu)),6082522u); flags=s.arithmetic_flags;
  }
  L005ccfda: { // 0x5ccfda: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005ccfdb: { // 0x5ccfdb: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L005ccfde: { // 0x5ccfde: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L005ccfe2: { // 0x5ccfe2: 898690000000 MOV dword ptr [ESI + 0x90],EAX
    m.w32((s.si+0x00000090u), s.ax);
  }
  L005ccfe8: { // 0x5ccfe8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005ccfe9: { // 0x5ccfe9: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_001cbf20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005cbf20: { // 0x5cbf20: a0a885a200 MOV AL,[0x00a285a8]
    s.ax = with_al(s.ax, m.r8((0x00a285a8u)));
  }
  L005cbf25: { // 0x5cbf25: 83ec2c SUB ESP,0x2c
    f.sp = integer::sub(f.sp,0x0000002cu,32,flags);
  }
  L005cbf28: { // 0x5cbf28: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cbf2a: { // 0x5cbf2a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005cbf2b: { // 0x5cbf2b: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005cbf2c: { // 0x5cbf2c: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005cbf2d: { // 0x5cbf2d: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005cbf2e: { // 0x5cbf2e: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L005cbf30: { // 0x5cbf30: 0f8416030000 JZ 0x005cc24c
    if(integer::condition("JZ",flags)) goto L005cc24c;
  }
  L005cbf36: { // 0x5cbf36: 8a4676 MOV AL,byte ptr [ESI + 0x76]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000076u)));
  }
  L005cbf39: { // 0x5cbf39: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cbf3b: { // 0x5cbf3b: 0f840b030000 JZ 0x005cc24c
    if(integer::condition("JZ",flags)) goto L005cc24c;
  }
  L005cbf41: { // 0x5cbf41: 8a4674 MOV AL,byte ptr [ESI + 0x74]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000074u)));
  }
  L005cbf44: { // 0x5cbf44: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cbf46: { // 0x5cbf46: 0f8500030000 JNZ 0x005cc24c
    if(integer::condition("JNZ",flags)) goto L005cc24c;
  }
  L005cbf4c: { // 0x5cbf4c: a1c483a200 MOV EAX,[0x00a283c4]
    s.ax = m.r32((0x00a283c4u));
  }
  L005cbf51: { // 0x5cbf51: 8b7c2440 MOV EDI,dword ptr [ESP + 0x40]
    s.di = m.r32((f.sp+0x00000040u));
  }
  L005cbf55: { // 0x5cbf55: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005cbf57: { // 0x5cbf57: 7526 JNZ 0x005cbf7f
    if(integer::condition("JNZ",flags)) goto L005cbf7f;
  }
  L005cbf59: { // 0x5cbf59: 8b1e MOV EBX,dword ptr [ESI]
    s.bx = m.r32((s.si));
  }
  L005cbf5b: { // 0x5cbf5b: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L005cbf5d: { // 0x5cbf5d: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L005cbf5f: { // 0x5cbf5f: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L005cbf61: { // 0x5cbf61: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L005cbf63: { // 0x5cbf63: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005cbf64: { // 0x5cbf64: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L005cbf69: { // 0x5cbf69: e82295f7ff CALL 0x00545490
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545490u,6078318u); flags=s.arithmetic_flags;
  }
  L005cbf6e: { // 0x5cbf6e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005cbf6f: { // 0x5cbf6f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cbf71: { // 0x5cbf71: ff9394010000 CALL dword ptr [EBX + 0x194]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bx+0x00000194u)),6078327u); flags=s.arithmetic_flags;
  }
  L005cbf77: { // 0x5cbf77: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005cbf79: { // 0x5cbf79: 0f85cd020000 JNZ 0x005cc24c
    if(integer::condition("JNZ",flags)) goto L005cc24c;
  }
  L005cbf7f: { // 0x5cbf7f: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005cbf81: { // 0x5cbf81: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cbf83: { // 0x5cbf83: c6467600 MOV byte ptr [ESI + 0x76],0x0
    m.w8((s.si+0x00000076u), 0x00000000u);
  }
  L005cbf87: { // 0x5cbf87: c6467500 MOV byte ptr [ESI + 0x75],0x0
    m.w8((s.si+0x00000075u), 0x00000000u);
  }
  L005cbf8b: { // 0x5cbf8b: ff9084000000 CALL dword ptr [EAX + 0x84]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000084u)),6078353u); flags=s.arithmetic_flags;
  }
  L005cbf91: { // 0x5cbf91: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005cbf93: { // 0x5cbf93: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L005cbf95: { // 0x5cbf95: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L005cbf97: { // 0x5cbf97: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L005cbf99: { // 0x5cbf99: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L005cbf9d: { // 0x5cbf9d: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L005cbfa0: { // 0x5cbfa0: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L005cbfa4: { // 0x5cbfa4: 8b4908 MOV ECX,dword ptr [ECX + 0x8]
    s.cx = m.r32((s.cx+0x00000008u));
  }
  L005cbfa7: { // 0x5cbfa7: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L005cbfab: { // 0x5cbfab: 7421 JZ 0x005cbfce
    if(integer::condition("JZ",flags)) goto L005cbfce;
  }
  L005cbfad: { // 0x5cbfad: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L005cbfaf: { // 0x5cbfaf: 8d442424 LEA EAX,[ESP + 0x24]
    s.ax = (f.sp+0x00000024u);
  }
  L005cbfb3: { // 0x5cbfb3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005cbfb4: { // 0x5cbfb4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005cbfb5: { // 0x5cbfb5: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L005cbfb7: { // 0x5cbfb7: ff526c CALL dword ptr [EDX + 0x6c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000006cu)),6078394u); flags=s.arithmetic_flags;
  }
  L005cbfba: { // 0x5cbfba: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L005cbfbc: { // 0x5cbfbc: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L005cbfc0: { // 0x5cbfc0: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L005cbfc3: { // 0x5cbfc3: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L005cbfc7: { // 0x5cbfc7: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L005cbfca: { // 0x5cbfca: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L005cbfce: { // 0x5cbfce: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005cbfd0: { // 0x5cbfd0: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L005cbfd4: { // 0x5cbfd4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005cbfd5: { // 0x5cbfd5: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cbfd7: { // 0x5cbfd7: ff929c010000 CALL dword ptr [EDX + 0x19c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000019cu)),6078429u); flags=s.arithmetic_flags;
  }
  L005cbfdd: { // 0x5cbfdd: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005cbfdf: { // 0x5cbfdf: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L005cbfe1: { // 0x5cbfe1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cbfe3: { // 0x5cbfe3: ff921c010000 CALL dword ptr [EDX + 0x11c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000011cu)),6078441u); flags=s.arithmetic_flags;
  }
  L005cbfe9: { // 0x5cbfe9: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cbfeb: { // 0x5cbfeb: 0f8457020000 JZ 0x005cc248
    if(integer::condition("JZ",flags)) goto L005cc248;
  }
  L005cbff1: { // 0x5cbff1: 8a467d MOV AL,byte ptr [ESI + 0x7d]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000007du)));
  }
  L005cbff4: { // 0x5cbff4: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cbff6: { // 0x5cbff6: 0f8440020000 JZ 0x005cc23c
    if(integer::condition("JZ",flags)) goto L005cc23c;
  }
  L005cbffc: { // 0x5cbffc: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005cbffe: { // 0x5cbffe: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cc000: { // 0x5cc000: ff5074 CALL dword ptr [EAX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000074u)),6078467u); flags=s.arithmetic_flags;
  }
  L005cc003: { // 0x5cc003: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L005cc006: { // 0x5cc006: 740b JZ 0x005cc013
    if(integer::condition("JZ",flags)) goto L005cc013;
  }
  L005cc008: { // 0x5cc008: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005cc009: { // 0x5cc009: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L005cc00e: { // 0x5cc00e: e80dd8ecff CALL 0x00499820
    s.arithmetic_flags=flags; invoke(m,s,f,0x00499820u,6078483u); flags=s.arithmetic_flags;
  }
  L005cc013: { // 0x5cc013: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L005cc015: { // 0x5cc015: 0f845c010000 JZ 0x005cc177
    if(integer::condition("JZ",flags)) goto L005cc177;
  }
  L005cc01b: { // 0x5cc01b: 8a8304020000 MOV AL,byte ptr [EBX + 0x204]
    s.ax = with_al(s.ax, m.r8((s.bx+0x00000204u)));
  }
  L005cc021: { // 0x5cc021: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cc023: { // 0x5cc023: 744c JZ 0x005cc071
    if(integer::condition("JZ",flags)) goto L005cc071;
  }
  L005cc025: { // 0x5cc025: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005cc027: { // 0x5cc027: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cc029: { // 0x5cc029: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),6078508u); flags=s.arithmetic_flags;
  }
  L005cc02c: { // 0x5cc02c: 83f824 CMP EAX,0x24
    (void)integer::sub(s.ax,0x00000024u,32,flags);
  }
  L005cc02f: { // 0x5cc02f: 7516 JNZ 0x005cc047
    if(integer::condition("JNZ",flags)) goto L005cc047;
  }
  L005cc031: { // 0x5cc031: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005cc033: { // 0x5cc033: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cc035: { // 0x5cc035: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),6078520u); flags=s.arithmetic_flags;
  }
  L005cc038: { // 0x5cc038: 83f824 CMP EAX,0x24
    (void)integer::sub(s.ax,0x00000024u,32,flags);
  }
  L005cc03b: { // 0x5cc03b: 7534 JNZ 0x005cc071
    if(integer::condition("JNZ",flags)) goto L005cc071;
  }
  L005cc03d: { // 0x5cc03d: 8a8381020000 MOV AL,byte ptr [EBX + 0x281]
    s.ax = with_al(s.ax, m.r8((s.bx+0x00000281u)));
  }
  L005cc043: { // 0x5cc043: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cc045: { // 0x5cc045: 742a JZ 0x005cc071
    if(integer::condition("JZ",flags)) goto L005cc071;
  }
  L005cc047: { // 0x5cc047: a1c855a200 MOV EAX,[0x00a255c8]
    s.ax = m.r32((0x00a255c8u));
  }
  L005cc04c: { // 0x5cc04c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005cc04e: { // 0x5cc04e: 7414 JZ 0x005cc064
    if(integer::condition("JZ",flags)) goto L005cc064;
  }
  L005cc050: { // 0x5cc050: 83f805 CMP EAX,0x5
    (void)integer::sub(s.ax,0x00000005u,32,flags);
  }
  L005cc053: { // 0x5cc053: 740f JZ 0x005cc064
    if(integer::condition("JZ",flags)) goto L005cc064;
  }
  L005cc055: { // 0x5cc055: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  L005cc058: { // 0x5cc058: 8d4604 LEA EAX,[ESI + 0x4]
    s.ax = (s.si+0x00000004u);
  }
  L005cc05b: { // 0x5cc05b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005cc05c: { // 0x5cc05c: ff5110 CALL dword ptr [ECX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+0x00000010u)),6078559u); flags=s.arithmetic_flags;
  }
  L005cc05f: { // 0x5cc05f: 83f8fe CMP EAX,-0x2
    (void)integer::sub(s.ax,0xfffffffeu,32,flags);
  }
  L005cc062: { // 0x5cc062: 740d JZ 0x005cc071
    if(integer::condition("JZ",flags)) goto L005cc071;
  }
  L005cc064: { // 0x5cc064: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L005cc066: { // 0x5cc066: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005cc067: { // 0x5cc067: b9b0a78100 MOV ECX,0x81a7b0
    s.cx = 0x0081a7b0u;
  }
  L005cc06c: { // 0x5cc06c: e89f04f7ff CALL 0x0053c510
    s.arithmetic_flags=flags; invoke(m,s,f,0x0053c510u,6078577u); flags=s.arithmetic_flags;
  }
  L005cc071: { // 0x5cc071: 8b83ac000000 MOV EAX,dword ptr [EBX + 0xac]
    s.ax = m.r32((s.bx+0x000000acu));
  }
  L005cc077: { // 0x5cc077: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005cc079: { // 0x5cc079: 0f84f8000000 JZ 0x005cc177
    if(integer::condition("JZ",flags)) goto L005cc177;
  }
  L005cc07f: { // 0x5cc07f: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005cc081: { // 0x5cc081: 8d442430 LEA EAX,[ESP + 0x30]
    s.ax = (f.sp+0x00000030u);
  }
  L005cc085: { // 0x5cc085: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005cc086: { // 0x5cc086: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cc088: { // 0x5cc088: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),6078603u); flags=s.arithmetic_flags;
  }
  L005cc08b: { // 0x5cc08b: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L005cc08d: { // 0x5cc08d: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L005cc091: { // 0x5cc091: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L005cc095: { // 0x5cc095: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L005cc098: { // 0x5cc098: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005cc099: { // 0x5cc099: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L005cc09f: { // 0x5cc09f: 8954242c MOV dword ptr [ESP + 0x2c],EDX
    m.w32((f.sp+0x0000002cu), s.dx);
  }
  L005cc0a3: { // 0x5cc0a3: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L005cc0a6: { // 0x5cc0a6: 8d542428 LEA EDX,[ESP + 0x28]
    s.dx = (f.sp+0x00000028u);
  }
  L005cc0aa: { // 0x5cc0aa: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005cc0ab: { // 0x5cc0ab: 89442434 MOV dword ptr [ESP + 0x34],EAX
    m.w32((f.sp+0x00000034u), s.ax);
  }
  L005cc0af: { // 0x5cc0af: e85cbf0c00 CALL 0x00698010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00698010u,6078644u); flags=s.arithmetic_flags;
  }
  L005cc0b4: { // 0x5cc0b4: a1ac1c8200 MOV EAX,[0x00821cac]
    s.ax = m.r32((0x00821cacu));
  }
  L005cc0b9: { // 0x5cc0b9: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L005cc0bd: { // 0x5cc0bd: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L005cc0c1: { // 0x5cc0c1: 8b88b0000000 MOV ECX,dword ptr [EAX + 0xb0]
    s.cx = m.r32((s.ax+0x000000b0u));
  }
  L005cc0c7: { // 0x5cc0c7: 8b80b4000000 MOV EAX,dword ptr [EAX + 0xb4]
    s.ax = m.r32((s.ax+0x000000b4u));
  }
  L005cc0cd: { // 0x5cc0cd: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L005cc0cf: { // 0x5cc0cf: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005cc0d1: { // 0x5cc0d1: 03f9 ADD EDI,ECX
    s.di = integer::add(s.di,s.cx,32,flags);
  }
  L005cc0d3: { // 0x5cc0d3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cc0d5: { // 0x5cc0d5: 897c2410 MOV dword ptr [ESP + 0x10],EDI
    m.w32((f.sp+0x00000010u), s.di);
  }
  L005cc0d9: { // 0x5cc0d9: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L005cc0dd: { // 0x5cc0dd: ff9084000000 CALL dword ptr [EAX + 0x84]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000084u)),6078691u); flags=s.arithmetic_flags;
  }
  L005cc0e3: { // 0x5cc0e3: 8bb8ac000000 MOV EDI,dword ptr [EAX + 0xac]
    s.di = m.r32((s.ax+0x000000acu));
  }
  L005cc0e9: { // 0x5cc0e9: 8b6c2414 MOV EBP,dword ptr [ESP + 0x14]
    s.bp = m.r32((f.sp+0x00000014u));
  }
  L005cc0ed: { // 0x5cc0ed: 6a40 PUSH 0x40
    f.push(m,0x00000040u);
  }
  L005cc0ef: { // 0x5cc0ef: 0fbf4702 MOVSX EAX,word ptr [EDI + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L005cc0f3: { // 0x5cc0f3: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L005cc0f4: { // 0x5cc0f4: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L005cc0f6: { // 0x5cc0f6: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L005cc0f8: { // 0x5cc0f8: 0fbf4704 MOVSX EAX,word ptr [EDI + 0x4]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000004u)),16));
  }
  L005cc0fc: { // 0x5cc0fc: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L005cc0fd: { // 0x5cc0fd: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L005cc0ff: { // 0x5cc0ff: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L005cc103: { // 0x5cc103: d1f9 SAR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L005cc105: { // 0x5cc105: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L005cc107: { // 0x5cc107: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L005cc109: { // 0x5cc109: 2be8 SUB EBP,EAX
    s.bp = integer::sub(s.bp,s.ax,32,flags);
  }
  L005cc10b: { // 0x5cc10b: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L005cc10f: { // 0x5cc10f: 896c2418 MOV dword ptr [ESP + 0x18],EBP
    m.w32((f.sp+0x00000018u), s.bp);
  }
  L005cc113: { // 0x5cc113: e83f181a00 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,6078744u); flags=s.arithmetic_flags;
  }
  L005cc118: { // 0x5cc118: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L005cc11b: { // 0x5cc11b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005cc11d: { // 0x5cc11d: 7412 JZ 0x005cc131
    if(integer::condition("JZ",flags)) goto L005cc131;
  }
  L005cc11f: { // 0x5cc11f: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L005cc123: { // 0x5cc123: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L005cc127: { // 0x5cc127: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005cc128: { // 0x5cc128: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005cc129: { // 0x5cc129: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005cc12a: { // 0x5cc12a: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L005cc12c: { // 0x5cc12c: e8af2ae5ff CALL 0x0041ebe0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041ebe0u,6078769u); flags=s.arithmetic_flags;
  }
  L005cc131: { // 0x5cc131: a1c483a200 MOV EAX,[0x00a283c4]
    s.ax = m.r32((0x00a283c4u));
  }
  L005cc136: { // 0x5cc136: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005cc138: { // 0x5cc138: 753d JNZ 0x005cc177
    if(integer::condition("JNZ",flags)) goto L005cc177;
  }
  L005cc13a: { // 0x5cc13a: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L005cc140: { // 0x5cc140: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L005cc144: { // 0x5cc144: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L005cc146: { // 0x5cc146: 8b91b0000000 MOV EDX,dword ptr [ECX + 0xb0]
    s.dx = m.r32((s.cx+0x000000b0u));
  }
  L005cc14c: { // 0x5cc14c: 8ba9b4000000 MOV EBP,dword ptr [ECX + 0xb4]
    s.bp = m.r32((s.cx+0x000000b4u));
  }
  L005cc152: { // 0x5cc152: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L005cc155: { // 0x5cc155: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L005cc157: { // 0x5cc157: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L005cc15b: { // 0x5cc15b: 8bdc MOV EBX,ESP
    s.bx = f.sp;
  }
  L005cc15d: { // 0x5cc15d: 2bd5 SUB EDX,EBP
    s.dx = integer::sub(s.dx,s.bp,32,flags);
  }
  L005cc15f: { // 0x5cc15f: 0fbf6f02 MOVSX EBP,word ptr [EDI + 0x2]
    s.bp = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L005cc163: { // 0x5cc163: 0fbf7f04 MOVSX EDI,word ptr [EDI + 0x4]
    s.di = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000004u)),16));
  }
  L005cc167: { // 0x5cc167: 8903 MOV dword ptr [EBX],EAX
    m.w32((s.bx), s.ax);
  }
  L005cc169: { // 0x5cc169: 895304 MOV dword ptr [EBX + 0x4],EDX
    m.w32((s.bx+0x00000004u), s.dx);
  }
  L005cc16c: { // 0x5cc16c: 896b08 MOV dword ptr [EBX + 0x8],EBP
    m.w32((s.bx+0x00000008u), s.bp);
  }
  L005cc16f: { // 0x5cc16f: 897b0c MOV dword ptr [EBX + 0xc],EDI
    m.w32((s.bx+0x0000000cu), s.di);
  }
  L005cc172: { // 0x5cc172: e8e9c40c00 CALL 0x00698660
    s.arithmetic_flags=flags; invoke(m,s,f,0x00698660u,6078839u); flags=s.arithmetic_flags;
  }
  L005cc177: { // 0x5cc177: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005cc179: { // 0x5cc179: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cc17b: { // 0x5cc17b: ff9084000000 CALL dword ptr [EAX + 0x84]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000084u)),6078849u); flags=s.arithmetic_flags;
  }
  L005cc181: { // 0x5cc181: 8a880a020000 MOV CL,byte ptr [EAX + 0x20a]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0000020au)));
  }
  L005cc187: { // 0x5cc187: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L005cc189: { // 0x5cc189: 0f84ad000000 JZ 0x005cc23c
    if(integer::condition("JZ",flags)) goto L005cc23c;
  }
  L005cc18f: { // 0x5cc18f: 6810020000 PUSH 0x210
    f.push(m,0x00000210u);
  }
  L005cc194: { // 0x5cc194: e8be171a00 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,6078873u); flags=s.arithmetic_flags;
  }
  L005cc199: { // 0x5cc199: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L005cc19c: { // 0x5cc19c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005cc19e: { // 0x5cc19e: 7409 JZ 0x005cc1a9
    if(integer::condition("JZ",flags)) goto L005cc1a9;
  }
  L005cc1a0: { // 0x5cc1a0: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L005cc1a2: { // 0x5cc1a2: e819b4f6ff CALL 0x005375c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005375c0u,6078887u); flags=s.arithmetic_flags;
  }
  L005cc1a7: { // 0x5cc1a7: eb02 JMP 0x005cc1ab
    goto L005cc1ab;
  }
  L005cc1a9: { // 0x5cc1a9: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005cc1ab: { // 0x5cc1ab: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005cc1ad: { // 0x5cc1ad: 898694000000 MOV dword ptr [ESI + 0x94],EAX
    m.w32((s.si+0x00000094u), s.ax);
  }
  L005cc1b3: { // 0x5cc1b3: 0f8483000000 JZ 0x005cc23c
    if(integer::condition("JZ",flags)) goto L005cc23c;
  }
  L005cc1b9: { // 0x5cc1b9: 8b0d881b8200 MOV ECX,dword ptr [0x00821b88]
    s.cx = m.r32((0x00821b88u));
  }
  L005cc1bf: { // 0x5cc1bf: 81c1ab140000 ADD ECX,0x14ab
    s.cx = integer::add(s.cx,0x000014abu,32,flags);
  }
  L005cc1c5: { // 0x5cc1c5: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L005cc1c7: { // 0x5cc1c7: 668b3a MOV DI,word ptr [EDX]
    s.di = (s.di & 0xffff0000u) | ((m.r16((s.dx))) & 0xffffu);
  }
  L005cc1ca: { // 0x5cc1ca: 66897c2440 MOV word ptr [ESP + 0x40],DI
    m.w16((f.sp+0x00000040u), (s.di & 0xffffu));
  }
  L005cc1cf: { // 0x5cc1cf: 8a5c2440 MOV BL,byte ptr [ESP + 0x40]
    s.bx = with_al(s.bx, m.r8((f.sp+0x00000040u)));
  }
  L005cc1d3: { // 0x5cc1d3: 8a5202 MOV DL,byte ptr [EDX + 0x2]
    s.dx = with_al(s.dx, m.r8((s.dx+0x00000002u)));
  }
  L005cc1d6: { // 0x5cc1d6: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L005cc1d8: { // 0x5cc1d8: 7531 JNZ 0x005cc20b
    if(integer::condition("JNZ",flags)) goto L005cc20b;
  }
  L005cc1da: { // 0x5cc1da: 8a5c2441 MOV BL,byte ptr [ESP + 0x41]
    s.bx = with_al(s.bx, m.r8((f.sp+0x00000041u)));
  }
  L005cc1de: { // 0x5cc1de: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L005cc1e0: { // 0x5cc1e0: 7529 JNZ 0x005cc20b
    if(integer::condition("JNZ",flags)) goto L005cc20b;
  }
  L005cc1e2: { // 0x5cc1e2: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L005cc1e4: { // 0x5cc1e4: 7525 JNZ 0x005cc20b
    if(integer::condition("JNZ",flags)) goto L005cc20b;
  }
  L005cc1e6: { // 0x5cc1e6: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005cc1e8: { // 0x5cc1e8: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cc1ea: { // 0x5cc1ea: ff9084000000 CALL dword ptr [EAX + 0x84]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000084u)),6078960u); flags=s.arithmetic_flags;
  }
  L005cc1f0: { // 0x5cc1f0: 8b9694000000 MOV EDX,dword ptr [ESI + 0x94]
    s.dx = m.r32((s.si+0x00000094u));
  }
  L005cc1f6: { // 0x5cc1f6: 050b020000 ADD EAX,0x20b
    s.ax = integer::add(s.ax,0x0000020bu,32,flags);
  }
  L005cc1fb: { // 0x5cc1fb: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L005cc1fd: { // 0x5cc1fd: 668b01 MOV AX,word ptr [ECX]
    s.ax = with_ax(s.ax, m.r16((s.cx)));
  }
  L005cc200: { // 0x5cc200: 8a4902 MOV CL,byte ptr [ECX + 0x2]
    s.cx = with_al(s.cx, m.r8((s.cx+0x00000002u)));
  }
  L005cc203: { // 0x5cc203: 668902 MOV word ptr [EDX],AX
    m.w16((s.dx), (s.ax & 0xffffu));
  }
  L005cc206: { // 0x5cc206: 884a02 MOV byte ptr [EDX + 0x2],CL
    m.w8((s.dx+0x00000002u), (s.cx & 0xffu));
  }
  L005cc209: { // 0x5cc209: eb0c JMP 0x005cc217
    goto L005cc217;
  }
  L005cc20b: { // 0x5cc20b: 668b11 MOV DX,word ptr [ECX]
    s.dx = with_ax(s.dx, m.r16((s.cx)));
  }
  L005cc20e: { // 0x5cc20e: 8a4902 MOV CL,byte ptr [ECX + 0x2]
    s.cx = with_al(s.cx, m.r8((s.cx+0x00000002u)));
  }
  L005cc211: { // 0x5cc211: 668910 MOV word ptr [EAX],DX
    m.w16((s.ax), (s.dx & 0xffffu));
  }
  L005cc214: { // 0x5cc214: 884802 MOV byte ptr [EAX + 0x2],CL
    m.w8((s.ax+0x00000002u), (s.cx & 0xffu));
  }
  L005cc217: { // 0x5cc217: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005cc219: { // 0x5cc219: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cc21b: { // 0x5cc21b: ff9084000000 CALL dword ptr [EAX + 0x84]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000084u)),6079009u); flags=s.arithmetic_flags;
  }
  L005cc221: { // 0x5cc221: 8b8810020000 MOV ECX,dword ptr [EAX + 0x210]
    s.cx = m.r32((s.ax+0x00000210u));
  }
  L005cc227: { // 0x5cc227: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005cc228: { // 0x5cc228: 8b8e94000000 MOV ECX,dword ptr [ESI + 0x94]
    s.cx = m.r32((s.si+0x00000094u));
  }
  L005cc22e: { // 0x5cc22e: e8bdb4f6ff CALL 0x005376f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005376f0u,6079027u); flags=s.arithmetic_flags;
  }
  L005cc233: { // 0x5cc233: 8b9694000000 MOV EDX,dword ptr [ESI + 0x94]
    s.dx = m.r32((s.si+0x00000094u));
  }
  L005cc239: { // 0x5cc239: 897204 MOV dword ptr [EDX + 0x4],ESI
    m.w32((s.dx+0x00000004u), s.si);
  }
  L005cc23c: { // 0x5cc23c: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L005cc23e: { // 0x5cc23e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005cc23f: { // 0x5cc23f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005cc240: { // 0x5cc240: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005cc241: { // 0x5cc241: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005cc242: { // 0x5cc242: 83c42c ADD ESP,0x2c
    f.sp = integer::add(f.sp,0x0000002cu,32,flags);
  }
  L005cc245: { // 0x5cc245: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L005cc248: { // 0x5cc248: c6467601 MOV byte ptr [ESI + 0x76],0x1
    m.w8((s.si+0x00000076u), 0x00000001u);
  }
  L005cc24c: { // 0x5cc24c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005cc24d: { // 0x5cc24d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005cc24e: { // 0x5cc24e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005cc24f: { // 0x5cc24f: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L005cc251: { // 0x5cc251: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005cc252: { // 0x5cc252: 83c42c ADD ESP,0x2c
    f.sp = integer::add(f.sp,0x0000002cu,32,flags);
  }
  L005cc255: { // 0x5cc255: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_000226d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004226d0: { // 0x4226d0: 83ec24 SUB ESP,0x24
    f.sp = integer::sub(f.sp,0x00000024u,32,flags);
  }
  L004226d3: { // 0x4226d3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004226d4: { // 0x4226d4: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004226d5: { // 0x4226d5: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004226d7: { // 0x4226d7: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  L004226d9: { // 0x4226d9: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004226db: { // 0x4226db: ff901c010000 CALL dword ptr [EAX + 0x11c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000011cu)),4335329u); flags=s.arithmetic_flags;
  }
  L004226e1: { // 0x4226e1: 8a8678010000 MOV AL,byte ptr [ESI + 0x178]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000178u)));
  }
  L004226e7: { // 0x4226e7: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004226e9: { // 0x4226e9: 7537 JNZ 0x00422722
    if(integer::condition("JNZ",flags)) goto L00422722;
  }
  L004226eb: { // 0x4226eb: 8b8eb0000000 MOV ECX,dword ptr [ESI + 0xb0]
    s.cx = m.r32((s.si+0x000000b0u));
  }
  L004226f1: { // 0x4226f1: 83b9b8020000ff CMP dword ptr [ECX + 0x2b8],-0x1
    (void)integer::sub(m.r32((s.cx+0x000002b8u)),0xffffffffu,32,flags);
  }
  L004226f8: { // 0x4226f8: 7428 JZ 0x00422722
    if(integer::condition("JZ",flags)) goto L00422722;
  }
  L004226fa: { // 0x4226fa: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004226fc: { // 0x4226fc: 8d9680010000 LEA EDX,[ESI + 0x180]
    s.dx = (s.si+0x00000180u);
  }
  L00422702: { // 0x422702: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  L00422706: { // 0x422706: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00422707: { // 0x422707: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00422708: { // 0x422708: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0042270a: { // 0x42270a: ff5048 CALL dword ptr [EAX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000048u)),4335373u); flags=s.arithmetic_flags;
  }
  L0042270d: { // 0x42270d: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0042270f: { // 0x42270f: 8b86b0000000 MOV EAX,dword ptr [ESI + 0xb0]
    s.ax = m.r32((s.si+0x000000b0u));
  }
  L00422715: { // 0x422715: 8b88b8020000 MOV ECX,dword ptr [EAX + 0x2b8]
    s.cx = m.r32((s.ax+0x000002b8u));
  }
  L0042271b: { // 0x42271b: e800632e00 CALL 0x00708a20
    s.arithmetic_flags=flags; invoke(m,s,f,0x00708a20u,4335392u); flags=s.arithmetic_flags;
  }
  L00422720: { // 0x422720: eb0b JMP 0x0042272d
    goto L0042272d;
  }
  L00422722: { // 0x422722: 8d8e80010000 LEA ECX,[ESI + 0x180]
    s.cx = (s.si+0x00000180u);
  }
  L00422728: { // 0x422728: e82336feff CALL 0x00405d50
    s.arithmetic_flags=flags; invoke(m,s,f,0x00405d50u,4335405u); flags=s.arithmetic_flags;
  }
  L0042272d: { // 0x42272d: 8d8e94010000 LEA ECX,[ESI + 0x194]
    s.cx = (s.si+0x00000194u);
  }
  L00422733: { // 0x422733: e81836feff CALL 0x00405d50
    s.arithmetic_flags=flags; invoke(m,s,f,0x00405d50u,4335416u); flags=s.arithmetic_flags;
  }
  L00422738: { // 0x422738: 8b8eb0000000 MOV ECX,dword ptr [ESI + 0xb0]
    s.cx = m.r32((s.si+0x000000b0u));
  }
  L0042273e: { // 0x42273e: 8b8168020000 MOV EAX,dword ptr [ECX + 0x268]
    s.ax = m.r32((s.cx+0x00000268u));
  }
  L00422744: { // 0x422744: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00422746: { // 0x422746: 7507 JNZ 0x0042274f
    if(integer::condition("JNZ",flags)) goto L0042274f;
  }
  L00422748: { // 0x422748: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0042274a: { // 0x42274a: e8a1010000 CALL 0x004228f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004228f0u,4335439u); flags=s.arithmetic_flags;
  }
  L0042274f: { // 0x42274f: 8a8678010000 MOV AL,byte ptr [ESI + 0x178]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000178u)));
  }
  L00422755: { // 0x422755: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00422757: { // 0x422757: 0f8588010000 JNZ 0x004228e5
    if(integer::condition("JNZ",flags)) goto L004228e5;
  }
  L0042275d: { // 0x42275d: 8b96b0000000 MOV EDX,dword ptr [ESI + 0xb0]
    s.dx = m.r32((s.si+0x000000b0u));
  }
  L00422763: { // 0x422763: 8a8213030000 MOV AL,byte ptr [EDX + 0x313]
    s.ax = with_al(s.ax, m.r8((s.dx+0x00000313u)));
  }
  L00422769: { // 0x422769: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0042276b: { // 0x42276b: 0f8474010000 JZ 0x004228e5
    if(integer::condition("JZ",flags)) goto L004228e5;
  }
  L00422771: { // 0x422771: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00422773: { // 0x422773: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L00422777: { // 0x422777: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00422778: { // 0x422778: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0042277a: { // 0x42277a: ff5048 CALL dword ptr [EAX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000048u)),4335485u); flags=s.arithmetic_flags;
  }
  L0042277d: { // 0x42277d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0042277e: { // 0x42277e: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00422783: { // 0x422783: e8082d1200 CALL 0x00545490
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545490u,4335496u); flags=s.arithmetic_flags;
  }
  L00422788: { // 0x422788: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0042278a: { // 0x42278a: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0042278c: { // 0x42278c: e88f760500 CALL 0x00479e20
    s.arithmetic_flags=flags; invoke(m,s,f,0x00479e20u,4335505u); flags=s.arithmetic_flags;
  }
  L00422791: { // 0x422791: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00422794: { // 0x422794: 0f844b010000 JZ 0x004228e5
    if(integer::condition("JZ",flags)) goto L004228e5;
  }
  L0042279a: { // 0x42279a: 8b153c86aa00 MOV EDX,dword ptr [0x00aa863c]
    s.dx = m.r32((0x00aa863cu));
  }
  L004227a0: { // 0x4227a0: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004227a1: { // 0x4227a1: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L004227a3: { // 0x4227a3: 8b3c82 MOV EDI,dword ptr [EDX + EAX*0x4]
    s.di = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L004227a6: { // 0x4227a6: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004227a8: { // 0x4227a8: 8a831e010000 MOV AL,byte ptr [EBX + 0x11e]
    s.ax = with_al(s.ax, m.r8((s.bx+0x0000011eu)));
  }
  L004227ae: { // 0x4227ae: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004227af: { // 0x4227af: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004227b0: { // 0x4227b0: e8fb310500 CALL 0x004759b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004759b0u,4335541u); flags=s.arithmetic_flags;
  }
  L004227b5: { // 0x4227b5: 8b87d4000000 MOV EAX,dword ptr [EDI + 0xd4]
    s.ax = m.r32((s.di+0x000000d4u));
  }
  L004227bb: { // 0x4227bb: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004227bd: { // 0x4227bd: 0f8ec6000000 JLE 0x00422889
    if(integer::condition("JLE",flags)) goto L00422889;
  }
  L004227c3: { // 0x4227c3: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L004227c9: { // 0x4227c9: 81c118020000 ADD ECX,0x218
    s.cx = integer::add(s.cx,0x00000218u,32,flags);
  }
  L004227cf: { // 0x4227cf: e80cd62000 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,4335572u); flags=s.arithmetic_flags;
  }
  L004227d4: { // 0x4227d4: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004227d5: { // 0x4227d5: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L004227d7: { // 0x4227d7: b903000000 MOV ECX,0x3
    s.cx = 0x00000003u;
  }
  L004227dc: { // 0x4227dc: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004227de: { // 0x4227de: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004227df: { // 0x4227df: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L004227e1: { // 0x4227e1: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L004227e3: { // 0x4227e3: 0f85a0000000 JNZ 0x00422889
    if(integer::condition("JNZ",flags)) goto L00422889;
  }
  L004227e9: { // 0x4227e9: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004227ea: { // 0x4227ea: 68a8010000 PUSH 0x1a8
    f.push(m,0x000001a8u);
  }
  L004227ef: { // 0x4227ef: e863b13400 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,4335604u); flags=s.arithmetic_flags;
  }
  L004227f4: { // 0x4227f4: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L004227f6: { // 0x4227f6: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L004227f9: { // 0x4227f9: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L004227fb: { // 0x4227fb: 7461 JZ 0x0042285e
    if(integer::condition("JZ",flags)) goto L0042285e;
  }
  L004227fd: { // 0x4227fd: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004227ff: { // 0x4227ff: 8d442428 LEA EAX,[ESP + 0x28]
    s.ax = (f.sp+0x00000028u);
  }
  L00422803: { // 0x422803: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00422804: { // 0x422804: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00422806: { // 0x422806: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),4335625u); flags=s.arithmetic_flags;
  }
  L00422809: { // 0x422809: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0042280b: { // 0x42280b: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0042280e: { // 0x42280e: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L00422811: { // 0x422811: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L00422815: { // 0x422815: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L0042281b: { // 0x42281b: 83c00a ADD EAX,0xa
    s.ax = integer::add(s.ax,0x0000000au,32,flags);
  }
  L0042281e: { // 0x42281e: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00422822: { // 0x422822: 8b87d4000000 MOV EAX,dword ptr [EDI + 0xd4]
    s.ax = m.r32((s.di+0x000000d4u));
  }
  L00422828: { // 0x422828: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00422829: { // 0x422829: 81c118020000 ADD ECX,0x218
    s.cx = integer::add(s.cx,0x00000218u,32,flags);
  }
  L0042282f: { // 0x42282f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00422830: { // 0x422830: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00422832: { // 0x422832: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L00422836: { // 0x422836: e805d62000 CALL 0x0062fe40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fe40u,4335675u); flags=s.arithmetic_flags;
  }
  L0042283b: { // 0x42283b: 8b8fc8000000 MOV ECX,dword ptr [EDI + 0xc8]
    s.cx = m.r32((s.di+0x000000c8u));
  }
  L00422841: { // 0x422841: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00422843: { // 0x422843: 6800060000 PUSH 0x600
    f.push(m,0x00000600u);
  }
  L00422848: { // 0x422848: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0042284a: { // 0x42284a: 8d54241c LEA EDX,[ESP + 0x1c]
    s.dx = (f.sp+0x0000001cu);
  }
  L0042284e: { // 0x42284e: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00422850: { // 0x422850: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00422851: { // 0x422851: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L00422854: { // 0x422854: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00422855: { // 0x422855: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00422857: { // 0x422857: e8b4d8ffff CALL 0x00420110
    s.arithmetic_flags=flags; invoke(m,s,f,0x00420110u,4335708u); flags=s.arithmetic_flags;
  }
  L0042285c: { // 0x42285c: eb02 JMP 0x00422860
    goto L00422860;
  }
  L0042285e: { // 0x42285e: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00422860: { // 0x422860: 8b8fc0000000 MOV ECX,dword ptr [EDI + 0xc0]
    s.cx = m.r32((s.di+0x000000c0u));
  }
  L00422866: { // 0x422866: 8b1504eaa900 MOV EDX,dword ptr [0x00a9ea04]
    s.dx = m.r32((0x00a9ea04u));
  }
  L0042286c: { // 0x42286c: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0042286d: { // 0x42286d: 8b0c8a MOV ECX,dword ptr [EDX + ECX*0x4]
    s.cx = m.r32((s.dx+(s.cx * 0x00000004u)));
  }
  L00422870: { // 0x422870: 8b910c030000 MOV EDX,dword ptr [ECX + 0x30c]
    s.dx = m.r32((s.cx+0x0000030cu));
  }
  L00422876: { // 0x422876: 8990bc000000 MOV dword ptr [EAX + 0xbc],EDX
    m.w32((s.ax+0x000000bcu), s.dx);
  }
  L0042287c: { // 0x42287c: 0fbf8b0a010000 MOVSX ECX,word ptr [EBX + 0x10a]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.bx+0x0000010au)),16));
  }
  L00422883: { // 0x422883: 8988e4000000 MOV dword ptr [EAX + 0xe4],ECX
    m.w32((s.ax+0x000000e4u), s.cx);
  }
  L00422889: { // 0x422889: 81c688000000 ADD ESI,0x88
    s.si = integer::add(s.si,0x00000088u,32,flags);
  }
  L0042288f: { // 0x42288f: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00422891: { // 0x422891: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00422893: { // 0x422893: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L00422897: { // 0x422897: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L0042289a: { // 0x42289a: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L0042289e: { // 0x42289e: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L004228a3: { // 0x4228a3: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L004228a6: { // 0x4228a6: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L004228aa: { // 0x4228aa: 8b90740c0000 MOV EDX,dword ptr [EAX + 0xc74]
    s.dx = m.r32((s.ax+0x00000c74u));
  }
  L004228b0: { // 0x4228b0: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004228b1: { // 0x4228b1: 8b9088040000 MOV EDX,dword ptr [EAX + 0x488]
    s.dx = m.r32((s.ax+0x00000488u));
  }
  L004228b7: { // 0x4228b7: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L004228b9: { // 0x4228b9: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L004228bd: { // 0x4228bd: e8feb50500 CALL 0x0047dec0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047dec0u,4335810u); flags=s.arithmetic_flags;
  }
  L004228c2: { // 0x4228c2: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L004228c4: { // 0x4228c4: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L004228c6: { // 0x4228c6: e875f80400 CALL 0x00472140
    s.arithmetic_flags=flags; invoke(m,s,f,0x00472140u,4335819u); flags=s.arithmetic_flags;
  }
  L004228cb: { // 0x4228cb: 83c324 ADD EBX,0x24
    s.bx = integer::add(s.bx,0x00000024u,32,flags);
  }
  L004228ce: { // 0x4228ce: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L004228d3: { // 0x4228d3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004228d4: { // 0x4228d4: e8d7a61200 CALL 0x0054cfb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054cfb0u,4335833u); flags=s.arithmetic_flags;
  }
  L004228d9: { // 0x4228d9: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004228da: { // 0x4228da: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L004228df: { // 0x4228df: e84c081400 CALL 0x00563130
    s.arithmetic_flags=flags; invoke(m,s,f,0x00563130u,4335844u); flags=s.arithmetic_flags;
  }
  L004228e4: { // 0x4228e4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004228e5: { // 0x4228e5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004228e6: { // 0x4228e6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004228e7: { // 0x4228e7: 83c424 ADD ESP,0x24
    f.sp = integer::add(f.sp,0x00000024u,32,flags);
  }
  L004228ea: { // 0x4228ea: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00021500(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00421500: { // 0x421500: 8b442404 MOV EAX, dword ptr [ESP + 4]
    s.ax = m.r32((f.sp+4u));
  }
  L00421504: { // 0x421504: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00421505: { // 0x421505: e8e6b21a00 CALL 0x5CC7F0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005cc7f0u,4330762u); flags=s.arithmetic_flags;
  }
  L0042150a: { // 0x42150a: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0042150c: { // 0x42150c: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  L0042150f: { // 0x42150f: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_001cc7f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005cc7f0: { // 0x5cc7f0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005cc7f1: { // 0x5cc7f1: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005cc7f2: { // 0x5cc7f2: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L005cc7f4: { // 0x5cc7f4: 8a4676 MOV AL,byte ptr [ESI + 0x76]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000076u)));
  }
  L005cc7f7: { // 0x5cc7f7: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cc7f9: { // 0x5cc7f9: 0f85b8000000 JNZ 0x005cc8b7
    if(integer::condition("JNZ",flags)) goto L005cc8b7;
  }
  L005cc7ff: { // 0x5cc7ff: 8b5c240c MOV EBX,dword ptr [ESP + 0xc]
    s.bx = m.r32((f.sp+0x0000000cu));
  }
  L005cc803: { // 0x5cc803: 83fb02 CMP EBX,0x2
    (void)integer::sub(s.bx,0x00000002u,32,flags);
  }
  L005cc806: { // 0x5cc806: 7525 JNZ 0x005cc82d
    if(integer::condition("JNZ",flags)) goto L005cc82d;
  }
  L005cc808: { // 0x5cc808: 8a4675 MOV AL,byte ptr [ESI + 0x75]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000075u)));
  }
  L005cc80b: { // 0x5cc80b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cc80d: { // 0x5cc80d: 0f85a4000000 JNZ 0x005cc8b7
    if(integer::condition("JNZ",flags)) goto L005cc8b7;
  }
  L005cc813: { // 0x5cc813: 8a4674 MOV AL,byte ptr [ESI + 0x74]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000074u)));
  }
  L005cc816: { // 0x5cc816: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cc818: { // 0x5cc818: 0f8499000000 JZ 0x005cc8b7
    if(integer::condition("JZ",flags)) goto L005cc8b7;
  }
  L005cc81e: { // 0x5cc81e: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005cc820: { // 0x5cc820: ff902c010000 CALL dword ptr [EAX + 0x12c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000012cu)),6080550u); flags=s.arithmetic_flags;
  }
  L005cc826: { // 0x5cc826: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005cc827: { // 0x5cc827: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L005cc829: { // 0x5cc829: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005cc82a: { // 0x5cc82a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L005cc82d: { // 0x5cc82d: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005cc82f: { // 0x5cc82f: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005cc830: { // 0x5cc830: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cc832: { // 0x5cc832: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),6080565u); flags=s.arithmetic_flags;
  }
  L005cc835: { // 0x5cc835: 83f806 CMP EAX,0x6
    (void)integer::sub(s.ax,0x00000006u,32,flags);
  }
  L005cc838: { // 0x5cc838: 7514 JNZ 0x005cc84e
    if(integer::condition("JNZ",flags)) goto L005cc84e;
  }
  L005cc83a: { // 0x5cc83a: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L005cc840: { // 0x5cc840: 8b88f00b0000 MOV ECX,dword ptr [EAX + 0xbf0]
    s.cx = m.r32((s.ax+0x00000bf0u));
  }
  L005cc846: { // 0x5cc846: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005cc848: { // 0x5cc848: 7404 JZ 0x005cc84e
    if(integer::condition("JZ",flags)) goto L005cc84e;
  }
  L005cc84a: { // 0x5cc84a: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L005cc84c: { // 0x5cc84c: 742d JZ 0x005cc87b
    if(integer::condition("JZ",flags)) goto L005cc87b;
  }
  L005cc84e: { // 0x5cc84e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cc850: { // 0x5cc850: e8cb13e4ff CALL 0x0040dc20
    s.arithmetic_flags=flags; invoke(m,s,f,0x0040dc20u,6080597u); flags=s.arithmetic_flags;
  }
  L005cc855: { // 0x5cc855: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L005cc857: { // 0x5cc857: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L005cc859: { // 0x5cc859: 7420 JZ 0x005cc87b
    if(integer::condition("JZ",flags)) goto L005cc87b;
  }
  L005cc85b: { // 0x5cc85b: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L005cc85d: { // 0x5cc85d: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005cc85f: { // 0x5cc85f: ff92a0020000 CALL dword ptr [EDX + 0x2a0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000002a0u)),6080613u); flags=s.arithmetic_flags;
  }
  L005cc865: { // 0x5cc865: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L005cc867: { // 0x5cc867: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005cc869: { // 0x5cc869: ff5038 CALL dword ptr [EAX + 0x38]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000038u)),6080620u); flags=s.arithmetic_flags;
  }
  L005cc86c: { // 0x5cc86c: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005cc86e: { // 0x5cc86e: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L005cc872: { // 0x5cc872: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005cc873: { // 0x5cc873: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cc875: { // 0x5cc875: ff92a0010000 CALL dword ptr [EDX + 0x1a0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001a0u)),6080635u); flags=s.arithmetic_flags;
  }
  L005cc87b: { // 0x5cc87b: 83fb01 CMP EBX,0x1
    (void)integer::sub(s.bx,0x00000001u,32,flags);
  }
  L005cc87e: { // 0x5cc87e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005cc87f: { // 0x5cc87f: 7405 JZ 0x005cc886
    if(integer::condition("JZ",flags)) goto L005cc886;
  }
  L005cc881: { // 0x5cc881: 83fb03 CMP EBX,0x3
    (void)integer::sub(s.bx,0x00000003u,32,flags);
  }
  L005cc884: { // 0x5cc884: 751c JNZ 0x005cc8a2
    if(integer::condition("JNZ",flags)) goto L005cc8a2;
  }
  L005cc886: { // 0x5cc886: 8a4674 MOV AL,byte ptr [ESI + 0x74]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000074u)));
  }
  L005cc889: { // 0x5cc889: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cc88b: { // 0x5cc88b: 7515 JNZ 0x005cc8a2
    if(integer::condition("JNZ",flags)) goto L005cc8a2;
  }
  L005cc88d: { // 0x5cc88d: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005cc88f: { // 0x5cc88f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cc891: { // 0x5cc891: c6467401 MOV byte ptr [ESI + 0x74],0x1
    m.w8((s.si+0x00000074u), 0x00000001u);
  }
  L005cc895: { // 0x5cc895: ff922c010000 CALL dword ptr [EDX + 0x12c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000012cu)),6080667u); flags=s.arithmetic_flags;
  }
  L005cc89b: { // 0x5cc89b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005cc89c: { // 0x5cc89c: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L005cc89e: { // 0x5cc89e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005cc89f: { // 0x5cc89f: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L005cc8a2: { // 0x5cc8a2: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L005cc8a4: { // 0x5cc8a4: 7511 JNZ 0x005cc8b7
    if(integer::condition("JNZ",flags)) goto L005cc8b7;
  }
  L005cc8a6: { // 0x5cc8a6: 8a4674 MOV AL,byte ptr [ESI + 0x74]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000074u)));
  }
  L005cc8a9: { // 0x5cc8a9: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cc8ab: { // 0x5cc8ab: 740a JZ 0x005cc8b7
    if(integer::condition("JZ",flags)) goto L005cc8b7;
  }
  L005cc8ad: { // 0x5cc8ad: 885e74 MOV byte ptr [ESI + 0x74],BL
    m.w8((s.si+0x00000074u), (s.bx & 0xffu));
  }
  L005cc8b0: { // 0x5cc8b0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005cc8b1: { // 0x5cc8b1: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L005cc8b3: { // 0x5cc8b3: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005cc8b4: { // 0x5cc8b4: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L005cc8b7: { // 0x5cc8b7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005cc8b8: { // 0x5cc8b8: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L005cc8ba: { // 0x5cc8ba: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005cc8bb: { // 0x5cc8bb: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00005d50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00405d50: { // 0x405d50: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00405d51: { // 0x405d51: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00405d53: { // 0x405d53: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00405d54: { // 0x405d54: 8b0df8928100 MOV ECX,dword ptr [0x008192f8]
    s.cx = m.r32((0x008192f8u));
  }
  L00405d5a: { // 0x405d5a: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L00405d5c: { // 0x405d5c: 3bcd CMP ECX,EBP
    (void)integer::sub(s.cx,s.bp,32,flags);
  }
  L00405d5e: { // 0x405d5e: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00405d5f: { // 0x405d5f: 89442408 MOV dword ptr [ESP + 0x8],EAX
    m.w32((f.sp+0x00000008u), s.ax);
  }
  L00405d63: { // 0x405d63: 0f8418010000 JZ 0x00405e81
    if(integer::condition("JZ",flags)) goto L00405e81;
  }
  L00405d69: { // 0x405d69: 81780cec928100 CMP dword ptr [EAX + 0xc],0x8192ec
    (void)integer::sub(m.r32((s.ax+0x0000000cu)),0x008192ecu,32,flags);
  }
  L00405d70: { // 0x405d70: 0f850b010000 JNZ 0x00405e81
    if(integer::condition("JNZ",flags)) goto L00405e81;
  }
  L00405d76: { // 0x405d76: 8b30 MOV ESI,dword ptr [EAX]
    s.si = m.r32((s.ax));
  }
  L00405d78: { // 0x405d78: 3bf5 CMP ESI,EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  L00405d7a: { // 0x405d7a: 0f8401010000 JZ 0x00405e81
    if(integer::condition("JZ",flags)) goto L00405e81;
  }
  L00405d80: { // 0x405d80: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L00405d83: { // 0x405d83: 8b5624 MOV EDX,dword ptr [ESI + 0x24]
    s.dx = m.r32((s.si+0x00000024u));
  }
  L00405d86: { // 0x405d86: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L00405d88: { // 0x405d88: 0f85f1000000 JNZ 0x00405e7f
    if(integer::condition("JNZ",flags)) goto L00405e7f;
  }
  L00405d8e: { // 0x405d8e: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L00405d91: { // 0x405d91: 8b8e38010000 MOV ECX,dword ptr [ESI + 0x138]
    s.cx = m.r32((s.si+0x00000138u));
  }
  L00405d97: { // 0x405d97: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L00405d99: { // 0x405d99: 0f85e0000000 JNZ 0x00405e7f
    if(integer::condition("JNZ",flags)) goto L00405e7f;
  }
  L00405d9f: { // 0x405d9f: f6461801 TEST byte ptr [ESI + 0x18],0x1
    (void)integer::logical((m.r8((s.si+0x00000018u)))&(0x00000001u),8,flags);
  }
  L00405da3: { // 0x405da3: 0f85d6000000 JNZ 0x00405e7f
    if(integer::condition("JNZ",flags)) goto L00405e7f;
  }
  L00405da9: { // 0x405da9: 8b8eb0000000 MOV ECX,dword ptr [ESI + 0xb0]
    s.cx = m.r32((s.si+0x000000b0u));
  }
  L00405daf: { // 0x405daf: 3bcd CMP ECX,EBP
    (void)integer::sub(s.cx,s.bp,32,flags);
  }
  L00405db1: { // 0x405db1: 747c JZ 0x00405e2f
    if(integer::condition("JZ",flags)) goto L00405e2f;
  }
  L00405db3: { // 0x405db3: 3bb1c0000000 CMP ESI,dword ptr [ECX + 0xc0]
    (void)integer::sub(s.si,m.r32((s.cx+0x000000c0u)),32,flags);
  }
  L00405db9: { // 0x405db9: 7574 JNZ 0x00405e2f
    if(integer::condition("JNZ",flags)) goto L00405e2f;
  }
  L00405dbb: { // 0x405dbb: f6461802 TEST byte ptr [ESI + 0x18],0x2
    (void)integer::logical((m.r8((s.si+0x00000018u)))&(0x00000002u),8,flags);
  }
  L00405dbf: { // 0x405dbf: 7405 JZ 0x00405dc6
    if(integer::condition("JZ",flags)) goto L00405dc6;
  }
  L00405dc1: { // 0x405dc1: e8eac7ffff CALL 0x004025b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004025b0u,4218310u); flags=s.arithmetic_flags;
  }
  L00405dc6: { // 0x405dc6: 8b8eb0000000 MOV ECX,dword ptr [ESI + 0xb0]
    s.cx = m.r32((s.si+0x000000b0u));
  }
  L00405dcc: { // 0x405dcc: e81fc9ffff CALL 0x004026f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004026f0u,4218321u); flags=s.arithmetic_flags;
  }
  L00405dd1: { // 0x405dd1: 8b86b0000000 MOV EAX,dword ptr [ESI + 0xb0]
    s.ax = m.r32((s.si+0x000000b0u));
  }
  L00405dd7: { // 0x405dd7: 89a8c0000000 MOV dword ptr [EAX + 0xc0],EBP
    m.w32((s.ax+0x000000c0u), s.bp);
  }
  L00405ddd: { // 0x405ddd: 8b8eb0000000 MOV ECX,dword ptr [ESI + 0xb0]
    s.cx = m.r32((s.si+0x000000b0u));
  }
  L00405de3: { // 0x405de3: 89a9bc000000 MOV dword ptr [ECX + 0xbc],EBP
    m.w32((s.cx+0x000000bcu), s.bp);
  }
  L00405de9: { // 0x405de9: 8b96b0000000 MOV EDX,dword ptr [ESI + 0xb0]
    s.dx = m.r32((s.si+0x000000b0u));
  }
  L00405def: { // 0x405def: 89aab4000000 MOV dword ptr [EDX + 0xb4],EBP
    m.w32((s.dx+0x000000b4u), s.bp);
  }
  L00405df5: { // 0x405df5: 8b86b0000000 MOV EAX,dword ptr [ESI + 0xb0]
    s.ax = m.r32((s.si+0x000000b0u));
  }
  L00405dfb: { // 0x405dfb: 89a8b8000000 MOV dword ptr [EAX + 0xb8],EBP
    m.w32((s.ax+0x000000b8u), s.bp);
  }
  L00405e01: { // 0x405e01: 8b8eb0000000 MOV ECX,dword ptr [ESI + 0xb0]
    s.cx = m.r32((s.si+0x000000b0u));
  }
  L00405e07: { // 0x405e07: 89a990000000 MOV dword ptr [ECX + 0x90],EBP
    m.w32((s.cx+0x00000090u), s.bp);
  }
  L00405e0d: { // 0x405e0d: 8b96b0000000 MOV EDX,dword ptr [ESI + 0xb0]
    s.dx = m.r32((s.si+0x000000b0u));
  }
  L00405e13: { // 0x405e13: 89aa98000000 MOV dword ptr [EDX + 0x98],EBP
    m.w32((s.dx+0x00000098u), s.bp);
  }
  L00405e19: { // 0x405e19: 8b86b0000000 MOV EAX,dword ptr [ESI + 0xb0]
    s.ax = m.r32((s.si+0x000000b0u));
  }
  L00405e1f: { // 0x405e1f: 89a89c000000 MOV dword ptr [EAX + 0x9c],EBP
    m.w32((s.ax+0x0000009cu), s.bp);
  }
  L00405e25: { // 0x405e25: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L00405e29: { // 0x405e29: 89aeb0000000 MOV dword ptr [ESI + 0xb0],EBP
    m.w32((s.si+0x000000b0u), s.bp);
  }
  L00405e2f: { // 0x405e2f: 8b8ea8000000 MOV ECX,dword ptr [ESI + 0xa8]
    s.cx = m.r32((s.si+0x000000a8u));
  }
  L00405e35: { // 0x405e35: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00405e36: { // 0x405e36: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00405e38: { // 0x405e38: 3bcd CMP ECX,EBP
    (void)integer::sub(s.cx,s.bp,32,flags);
  }
  L00405e3a: { // 0x405e3a: 7e20 JLE 0x00405e5c
    if(integer::condition("JLE",flags)) goto L00405e5c;
  }
  L00405e3c: { // 0x405e3c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00405e3d: { // 0x405e3d: 8d7e28 LEA EDI,[ESI + 0x28]
    s.di = (s.si+0x00000028u);
  }
  L00405e40: { // 0x405e40: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  L00405e42: { // 0x405e42: e849c1ffff CALL 0x00401f90
    s.arithmetic_flags=flags; invoke(m,s,f,0x00401f90u,4218439u); flags=s.arithmetic_flags;
  }
  L00405e47: { // 0x405e47: 892f MOV dword ptr [EDI],EBP
    m.w32((s.di), s.bp);
  }
  L00405e49: { // 0x405e49: 8b86a8000000 MOV EAX,dword ptr [ESI + 0xa8]
    s.ax = m.r32((s.si+0x000000a8u));
  }
  L00405e4f: { // 0x405e4f: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L00405e50: { // 0x405e50: 83c704 ADD EDI,0x4
    s.di = integer::add(s.di,0x00000004u,32,flags);
  }
  L00405e53: { // 0x405e53: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L00405e55: { // 0x405e55: 7ce9 JL 0x00405e40
    if(integer::condition("JL",flags)) goto L00405e40;
  }
  L00405e57: { // 0x405e57: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00405e5b: { // 0x405e5b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00405e5c: { // 0x405e5c: 89aea8000000 MOV dword ptr [ESI + 0xa8],EBP
    m.w32((s.si+0x000000a8u), s.bp);
  }
  L00405e62: { // 0x405e62: c7461c04000000 MOV dword ptr [ESI + 0x1c],0x4
    m.w32((s.si+0x0000001cu), 0x00000004u);
  }
  L00405e69: { // 0x405e69: 89ae38010000 MOV dword ptr [ESI + 0x138],EBP
    m.w32((s.si+0x00000138u), s.bp);
  }
  L00405e6f: { // 0x405e6f: 89ae78020000 MOV dword ptr [ESI + 0x278],EBP
    m.w32((s.si+0x00000278u), s.bp);
  }
  L00405e75: { // 0x405e75: 8b4e18 MOV ECX,dword ptr [ESI + 0x18]
    s.cx = m.r32((s.si+0x00000018u));
  }
  L00405e78: { // 0x405e78: 83c901 OR ECX,0x1
    s.cx = integer::logical((s.cx)|(0x00000001u),32,flags);
  }
  L00405e7b: { // 0x405e7b: 894e18 MOV dword ptr [ESI + 0x18],ECX
    m.w32((s.si+0x00000018u), s.cx);
  }
  L00405e7e: { // 0x405e7e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00405e7f: { // 0x405e7f: 8928 MOV dword ptr [EAX],EBP
    m.w32((s.ax), s.bp);
  }
  L00405e81: { // 0x405e81: 896808 MOV dword ptr [EAX + 0x8],EBP
    m.w32((s.ax+0x00000008u), s.bp);
  }
  L00405e84: { // 0x405e84: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00405e85: { // 0x405e85: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00405e86: { // 0x405e86: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00405e87: { // 0x405e87: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4325648u:f_00020110(m,s,child,{});break;
case 6072688u:f_001ca970(m,s,child,{});break;
case 4259600u:f_0000ff10(m,s,child,{});break;
case 4217840u:f_00005bf0(m,s,child,{});break;
case 4259792u:f_0000ffd0(m,s,child,{});break;
case 6660384u:f_0025a120(m,s,child,{});break;
case 6660400u:f_0025a130(m,s,child,{});break;
case 5599344u:f_00157070(m,s,child,{});break;
case 5526784u:f_00145500(m,s,child,{});break;
case 4653760u:f_000702c0(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
case 6397168u:f_00219cf0(m,s,child,{});break;
case 6082480u:f_001ccfb0(m,s,child,{});break;
case 6078240u:f_001cbf20(m,s,child,{});break;
case 4335312u:f_000226d0(m,s,child,{});break;
case 4330752u:f_00021500(m,s,child,{});break;
case 6080496u:f_001cc7f0(m,s,child,{});break;
case 4218192u:f_00005d50(m,s,child,{});break;
case 0x76d957u:{const auto request=m.r32(child.entry_sp+4);if(request!=424)throw std::domain_error("231 exact allocation");s.ax=s.heap->allocate(request);m.w32(child.entry_sp-0x44,s.bx);m.w32(child.entry_sp-0x48,request);m.w32(child.entry_sp-0x4c,s.di);s.allocation.reset(new leaf::Memory(reinterpret_cast<unsigned char*>(std::uintptr_t(s.ax)),s.ax,424));m.add(*s.allocation);finish(m,s,child,0);break;}
default:throw std::domain_error("recovery231 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_006a6d60(Memory& original,const Inputs& i,Heap& heap){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6000u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.heap=&heap;s.bx=0x13579bdf;s.si=0x2468ace0;s.di=0x789abcde;s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006a6d60: { // 0x6a6d60: 83ec14 SUB ESP,0x14
    f.sp = integer::sub(f.sp,0x00000014u,32,flags);
  }
  L006a6d63: { // 0x6a6d63: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006a6d64: { // 0x6a6d64: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006a6d66: { // 0x6a6d66: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  L006a6d6a: { // 0x6a6d6a: 8b4644 MOV EAX,dword ptr [ESI + 0x44]
    s.ax = m.r32((s.si+0x00000044u));
  }
  L006a6d6d: { // 0x6a6d6d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006a6d6e: { // 0x6a6d6e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006a6d6f: { // 0x6a6d6f: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L006a6d75: { // 0x6a6d75: e8b633fbff CALL 0x0065a130
    s.arithmetic_flags=flags; invoke(m,s,f,0x0065a130u,6974842u); flags=s.arithmetic_flags;
  }
  L006a6d7a: { // 0x6a6d7a: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L006a6d7c: { // 0x6a6d7c: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L006a6d7e: { // 0x6a6d7e: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  L006a6d82: { // 0x6a6d82: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L006a6d86: { // 0x6a6d86: 0fbf4c2406 MOVSX ECX,word ptr [ESP + 0x6]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000006u)),16));
  }
  L006a6d8b: { // 0x6a6d8b: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L006a6d8e: { // 0x6a6d8e: c1e108 SHL ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::left);
  }
  L006a6d91: { // 0x6a6d91: c1e008 SHL EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::left);
  }
  L006a6d94: { // 0x6a6d94: 81c180000000 ADD ECX,0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L006a6d9a: { // 0x6a6d9a: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  L006a6d9e: { // 0x6a6d9e: 0580000000 ADD EAX,0x80
    s.ax = integer::add(s.ax,0x00000080u,32,flags);
  }
  L006a6da3: { // 0x6a6da3: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L006a6da7: { // 0x6a6da7: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006a6da8: { // 0x6a6da8: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006a6dad: { // 0x6a6dad: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L006a6db1: { // 0x6a6db1: e8ba02ebff CALL 0x00557070
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557070u,6974902u); flags=s.arithmetic_flags;
  }
  L006a6db6: { // 0x6a6db6: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L006a6dba: { // 0x6a6dba: 8d442404 LEA EAX,[ESP + 0x4]
    s.ax = (f.sp+0x00000004u);
  }
  L006a6dbe: { // 0x6a6dbe: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006a6dbf: { // 0x6a6dbf: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006a6dc4: { // 0x6a6dc4: e837e7e9ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6974921u); flags=s.arithmetic_flags;
  }
  L006a6dc9: { // 0x6a6dc9: 8b8840010000 MOV ECX,dword ptr [EAX + 0x140]
    s.cx = m.r32((s.ax+0x00000140u));
  }
  L006a6dcf: { // 0x6a6dcf: f6c501 TEST CH,0x1
    (void)integer::logical((((s.cx >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L006a6dd2: { // 0x6a6dd2: 751a JNZ 0x006a6dee
    if(integer::condition("JNZ",flags)) goto L006a6dee;
  }
  L006a6dd4: { // 0x6a6dd4: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  L006a6dd8: { // 0x6a6dd8: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006a6dd9: { // 0x6a6dd9: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006a6dde: { // 0x6a6dde: e81de7e9ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6974947u); flags=s.arithmetic_flags;
  }
  L006a6de3: { // 0x6a6de3: 8b8840010000 MOV ECX,dword ptr [EAX + 0x140]
    s.cx = m.r32((s.ax+0x00000140u));
  }
  L006a6de9: { // 0x6a6de9: f6c504 TEST CH,0x4
    (void)integer::logical((((s.cx >> 8) & 0xffu))&(0x00000004u),8,flags);
  }
  L006a6dec: { // 0x6a6dec: 7410 JZ 0x006a6dfe
    if(integer::condition("JZ",flags)) goto L006a6dfe;
  }
  L006a6dee: { // 0x6a6dee: 8b150079aa00 MOV EDX,dword ptr [0x00aa7900]
    s.dx = m.r32((0x00aa7900u));
  }
  L006a6df4: { // 0x6a6df4: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L006a6df8: { // 0x6a6df8: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L006a6dfa: { // 0x6a6dfa: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L006a6dfe: { // 0x6a6dfe: 68a8010000 PUSH 0x1a8
    f.push(m,0x000001a8u);
  }
  L006a6e03: { // 0x6a6e03: e84f6b0c00 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,6974984u); flags=s.arithmetic_flags;
  }
  L006a6e08: { // 0x6a6e08: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L006a6e0b: { // 0x6a6e0b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006a6e0d: { // 0x6a6e0d: 7434 JZ 0x006a6e43
    if(integer::condition("JZ",flags)) goto L006a6e43;
  }
  L006a6e0f: { // 0x6a6e0f: 8b5674 MOV EDX,dword ptr [ESI + 0x74]
    s.dx = m.r32((s.si+0x00000074u));
  }
  L006a6e12: { // 0x6a6e12: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006a6e14: { // 0x6a6e14: 6800060000 PUSH 0x600
    f.push(m,0x00000600u);
  }
  L006a6e19: { // 0x6a6e19: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L006a6e1b: { // 0x6a6e1b: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L006a6e1f: { // 0x6a6e1f: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006a6e21: { // 0x6a6e21: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006a6e22: { // 0x6a6e22: 8b0d14e58400 MOV ECX,dword ptr [0x0084e514]
    s.cx = m.r32((0x0084e514u));
  }
  L006a6e28: { // 0x6a6e28: 8b1491 MOV EDX,dword ptr [ECX + EDX*0x4]
    s.dx = m.r32((s.cx+(s.dx * 0x00000004u)));
  }
  L006a6e2b: { // 0x6a6e2b: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006a6e2d: { // 0x6a6e2d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006a6e2e: { // 0x6a6e2e: e8dd92d7ff CALL 0x00420110
    s.arithmetic_flags=flags; invoke(m,s,f,0x00420110u,6975027u); flags=s.arithmetic_flags;
  }
  L006a6e33: { // 0x6a6e33: c6807801000001 MOV byte ptr [EAX + 0x178],0x1
    m.w8((s.ax+0x00000178u), 0x00000001u);
  }
  L006a6e3a: { // 0x6a6e3a: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006a6e3c: { // 0x6a6e3c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006a6e3d: { // 0x6a6e3d: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L006a6e40: { // 0x6a6e40: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006a6e43: { // 0x6a6e43: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006a6e45: { // 0x6a6e45: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006a6e46: { // 0x6a6e46: c6807801000001 MOV byte ptr [EAX + 0x178],0x1
    m.w8((s.ax+0x00000178u), 0x00000001u);
  }
  L006a6e4d: { // 0x6a6e4d: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006a6e4f: { // 0x6a6e4f: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L006a6e52: { // 0x6a6e52: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
