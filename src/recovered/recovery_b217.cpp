#include "recovered/recovery_b217_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b217 {
namespace {
void f_00031370(Memory&,State&,Frame&,const Operations&);
void f_002e6be0(Memory&,State&,Frame&,const Operations&);
void f_001f6840(Memory&,State&,Frame&,const Operations&);
void f_00011370(Memory&,State&,Frame&,const Operations&);
void f_000113b0(Memory&,State&,Frame&,const Operations&);
void f_000113c0(Memory&,State&,Frame&,const Operations&);
void f_000112c0(Memory&,State&,Frame&,const Operations&);
void f_000112f0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

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
    default:throw std::domain_error("recovery217 unsupported switch destination");}
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
void f_002e6be0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006e6be0: { // 0x6e6be0: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006e6be2: { // 0x6e6be2: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L006e6be4: { // 0x6e6be4: 8901 MOV dword ptr [ECX],EAX
    m.w32((s.cx), s.ax);
  }
  L006e6be6: { // 0x6e6be6: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L006e6be9: { // 0x6e6be9: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L006e6beb: { // 0x6e6beb: 894104 MOV dword ptr [ECX + 0x4],EAX
    m.w32((s.cx+0x00000004u), s.ax);
  }
  L006e6bee: { // 0x6e6bee: 8d0412 LEA EAX,[EDX + EDX*0x1]
    s.ax = (s.dx+(s.dx * 0x00000001u));
  }
  L006e6bf1: { // 0x6e6bf1: 8b5108 MOV EDX,dword ptr [ECX + 0x8]
    s.dx = m.r32((s.cx+0x00000008u));
  }
  L006e6bf4: { // 0x6e6bf4: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L006e6bf6: { // 0x6e6bf6: 895108 MOV dword ptr [ECX + 0x8],EDX
    m.w32((s.cx+0x00000008u), s.dx);
  }
  L006e6bf9: { // 0x6e6bf9: 8b510c MOV EDX,dword ptr [ECX + 0xc]
    s.dx = m.r32((s.cx+0x0000000cu));
  }
  L006e6bfc: { // 0x6e6bfc: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L006e6bfe: { // 0x6e6bfe: 89510c MOV dword ptr [ECX + 0xc],EDX
    m.w32((s.cx+0x0000000cu), s.dx);
  }
  L006e6c01: { // 0x6e6c01: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_001f6840(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005f6840: { // 0x5f6840: 83ec2c SUB ESP,0x2c
    f.sp = integer::sub(f.sp,0x0000002cu,32,flags);
  }
  L005f6843: { // 0x5f6843: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005f6844: { // 0x5f6844: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005f6845: { // 0x5f6845: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L005f6847: { // 0x5f6847: 8bea MOV EBP,EDX
    s.bp = s.dx;
  }
  L005f6849: { // 0x5f6849: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L005f684b: { // 0x5f684b: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005f684d: { // 0x5f684d: 8b5500 MOV EDX,dword ptr [EBP]
    s.dx = m.r32((s.bp));
  }
  L005f6850: { // 0x5f6850: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005f6851: { // 0x5f6851: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005f6852: { // 0x5f6852: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L005f6854: { // 0x5f6854: 896c241c MOV dword ptr [ESP + 0x1c],EBP
    m.w32((f.sp+0x0000001cu), s.bp);
  }
  L005f6858: { // 0x5f6858: 89742434 MOV dword ptr [ESP + 0x34],ESI
    m.w32((f.sp+0x00000034u), s.si);
  }
  L005f685c: { // 0x5f685c: ff525c CALL dword ptr [EDX + 0x5c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000005cu)),6252639u); flags=s.arithmetic_flags;
  }
  L005f685f: { // 0x5f685f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005f6861: { // 0x5f6861: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L005f6865: { // 0x5f6865: 0f8476010000 JZ 0x005f69e1
    if(integer::condition("JZ",flags)) goto L005f69e1;
  }
  L005f686b: { // 0x5f686b: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L005f686e: { // 0x5f686e: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005f686f: { // 0x5f686f: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005f6870: { // 0x5f6870: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L005f6872: { // 0x5f6872: ff5074 CALL dword ptr [EAX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000074u)),6252661u); flags=s.arithmetic_flags;
  }
  L005f6875: { // 0x5f6875: 8b5e04 MOV EBX,dword ptr [ESI + 0x4]
    s.bx = m.r32((s.si+0x00000004u));
  }
  L005f6878: { // 0x5f6878: 8b7e0c MOV EDI,dword ptr [ESI + 0xc]
    s.di = m.r32((s.si+0x0000000cu));
  }
  L005f687b: { // 0x5f687b: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L005f687c: { // 0x5f687c: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L005f687e: { // 0x5f687e: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L005f6880: { // 0x5f6880: 03cf ADD ECX,EDI
    s.cx = integer::add(s.cx,s.di,32,flags);
  }
  L005f6882: { // 0x5f6882: 895c2420 MOV dword ptr [ESP + 0x20],EBX
    m.w32((f.sp+0x00000020u), s.bx);
  }
  L005f6886: { // 0x5f6886: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L005f6888: { // 0x5f6888: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L005f688a: { // 0x5f688a: 89442438 MOV dword ptr [ESP + 0x38],EAX
    m.w32((f.sp+0x00000038u), s.ax);
  }
  L005f688e: { // 0x5f688e: 0f8d43010000 JGE 0x005f69d7
    if(integer::condition("JGE",flags)) goto L005f69d7;
  }
  L005f6894: { // 0x5f6894: 8bfb MOV EDI,EBX
    s.di = s.bx;
  }
  L005f6896: { // 0x5f6896: 0faff8 IMUL EDI,EAX
    s.di = integer::imul(s.di,s.ax,32,flags);
  }
  L005f6899: { // 0x5f6899: 897c2424 MOV dword ptr [ESP + 0x24],EDI
    m.w32((f.sp+0x00000024u), s.di);
  }
  L005f689d: { // 0x5f689d: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L005f689f: { // 0x5f689f: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L005f68a2: { // 0x5f68a2: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L005f68a4: { // 0x5f68a4: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L005f68a8: { // 0x5f68a8: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L005f68aa: { // 0x5f68aa: 8d140f LEA EDX,[EDI + ECX*0x1]
    s.dx = (s.di+(s.cx * 0x00000001u));
  }
  L005f68ad: { // 0x5f68ad: 0f8d01010000 JGE 0x005f69b4
    if(integer::condition("JGE",flags)) goto L005f69b4;
  }
  L005f68b3: { // 0x5f68b3: 8b7c2444 MOV EDI,dword ptr [ESP + 0x44]
    s.di = m.r32((f.sp+0x00000044u));
  }
  L005f68b7: { // 0x5f68b7: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L005f68bb: { // 0x5f68bb: 8b5c2440 MOV EBX,dword ptr [ESP + 0x40]
    s.bx = m.r32((f.sp+0x00000040u));
  }
  L005f68bf: { // 0x5f68bf: 81e7ff000000 AND EDI,0xff
    s.di = integer::logical((s.di)&(0x000000ffu),32,flags);
  }
  L005f68c5: { // 0x5f68c5: b9ff000000 MOV ECX,0xff
    s.cx = 0x000000ffu;
  }
  L005f68ca: { // 0x5f68ca: 8d0450 LEA EAX,[EAX + EDX*0x2]
    s.ax = (s.ax+(s.dx * 0x00000002u));
  }
  L005f68cd: { // 0x5f68cd: 2bcf SUB ECX,EDI
    s.cx = integer::sub(s.cx,s.di,32,flags);
  }
  L005f68cf: { // 0x5f68cf: 81e3ffff0000 AND EBX,0xffff
    s.bx = integer::logical((s.bx)&(0x0000ffffu),32,flags);
  }
  L005f68d5: { // 0x5f68d5: 897c242c MOV dword ptr [ESP + 0x2c],EDI
    m.w32((f.sp+0x0000002cu), s.di);
  }
  L005f68d9: { // 0x5f68d9: 894c2430 MOV dword ptr [ESP + 0x30],ECX
    m.w32((f.sp+0x00000030u), s.cx);
  }
  L005f68dd: { // 0x5f68dd: 895c2410 MOV dword ptr [ESP + 0x10],EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
  L005f68e1: { // 0x5f68e1: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L005f68e5: { // 0x5f68e5: eb08 JMP 0x005f68ef
    goto L005f68ef;
  }
  L005f68e7: { // 0x5f68e7: 8b7c242c MOV EDI,dword ptr [ESP + 0x2c]
    s.di = m.r32((f.sp+0x0000002cu));
  }
  L005f68eb: { // 0x5f68eb: 8b4c2430 MOV ECX,dword ptr [ESP + 0x30]
    s.cx = m.r32((f.sp+0x00000030u));
  }
  L005f68ef: { // 0x5f68ef: 668b30 MOV SI,word ptr [EAX]
    s.si = (s.si & 0xffff0000u) | ((m.r16((s.ax))) & 0xffffu);
  }
  L005f68f2: { // 0x5f68f2: 890db80ab100 MOV dword ptr [0x00b10ab8],ECX
    m.w32((0x00b10ab8u), s.cx);
  }
  L005f68f8: { // 0x5f68f8: 8b0d30dfa500 MOV ECX,dword ptr [0x00a5df30]
    s.cx = m.r32((0x00a5df30u));
  }
  L005f68fe: { // 0x5f68fe: 81e6ffff0000 AND ESI,0xffff
    s.si = integer::logical((s.si)&(0x0000ffffu),32,flags);
  }
  L005f6904: { // 0x5f6904: 81e1ffff0000 AND ECX,0xffff
    s.cx = integer::logical((s.cx)&(0x0000ffffu),32,flags);
  }
  L005f690a: { // 0x5f690a: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005f690c: { // 0x5f690c: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L005f690e: { // 0x5f690e: 23ce AND ECX,ESI
    s.cx = integer::logical((s.cx)&(s.si),32,flags);
  }
  L005f6910: { // 0x5f6910: 0faf0db80ab100 IMUL ECX,dword ptr [0x00b10ab8]
    s.cx = integer::imul(s.cx,m.r32((0x00b10ab8u)),32,flags);
  }
  L005f6917: { // 0x5f6917: 23eb AND EBP,EBX
    s.bp = integer::logical((s.bp)&(s.bx),32,flags);
  }
  L005f6919: { // 0x5f6919: 66a132dfa500 MOV AX,[0x00a5df32]
    s.ax = with_ax(s.ax, m.r16((0x00a5df32u)));
  }
  L005f691f: { // 0x5f691f: 0fafef IMUL EBP,EDI
    s.bp = integer::imul(s.bp,s.di,32,flags);
  }
  L005f6922: { // 0x5f6922: 03e9 ADD EBP,ECX
    s.bp = integer::add(s.bp,s.cx,32,flags);
  }
  L005f6924: { // 0x5f6924: 8b0d30dfa500 MOV ECX,dword ptr [0x00a5df30]
    s.cx = m.r32((0x00a5df30u));
  }
  L005f692a: { // 0x5f692a: c1ed08 SHR EBP,0x8
    s.bp = integer::shift(s.bp,0x00000008u,32,flags,integer::Shift::right);
  }
  L005f692d: { // 0x5f692d: 23e9 AND EBP,ECX
    s.bp = integer::logical((s.bp)&(s.cx),32,flags);
  }
  L005f692f: { // 0x5f692f: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L005f6933: { // 0x5f6933: 8bde MOV EBX,ESI
    s.bx = s.si;
  }
  L005f6935: { // 0x5f6935: 23c8 AND ECX,EAX
    s.cx = integer::logical((s.cx)&(s.ax),32,flags);
  }
  L005f6937: { // 0x5f6937: 23d8 AND EBX,EAX
    s.bx = integer::logical((s.bx)&(s.ax),32,flags);
  }
  L005f6939: { // 0x5f6939: a1b80ab100 MOV EAX,[0x00b10ab8]
    s.ax = m.r32((0x00b10ab8u));
  }
  L005f693e: { // 0x5f693e: 0fafcf IMUL ECX,EDI
    s.cx = integer::imul(s.cx,s.di,32,flags);
  }
  L005f6941: { // 0x5f6941: 0fafd8 IMUL EBX,EAX
    s.bx = integer::imul(s.bx,s.ax,32,flags);
  }
  L005f6944: { // 0x5f6944: 8b1534dfa500 MOV EDX,dword ptr [0x00a5df34]
    s.dx = m.r32((0x00a5df34u));
  }
  L005f694a: { // 0x5f694a: 03cb ADD ECX,EBX
    s.cx = integer::add(s.cx,s.bx,32,flags);
  }
  L005f694c: { // 0x5f694c: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L005f6950: { // 0x5f6950: 81e2ffff0000 AND EDX,0xffff
    s.dx = integer::logical((s.dx)&(0x0000ffffu),32,flags);
  }
  L005f6956: { // 0x5f6956: c1e908 SHR ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::right);
  }
  L005f6959: { // 0x5f6959: 66230d32dfa500 AND CX,word ptr [0x00a5df32]
    s.cx = with_ax(s.cx, integer::logical(((s.cx & 0xffffu))&(m.r16((0x00a5df32u))),16,flags));
  }
  L005f6960: { // 0x5f6960: 893db40ab100 MOV dword ptr [0x00b10ab4],EDI
    m.w32((0x00b10ab4u), s.di);
  }
  L005f6966: { // 0x5f6966: 0be9 OR EBP,ECX
    s.bp = integer::logical((s.bp)|(s.cx),32,flags);
  }
  L005f6968: { // 0x5f6968: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L005f696a: { // 0x5f696a: 23cb AND ECX,EBX
    s.cx = integer::logical((s.cx)&(s.bx),32,flags);
  }
  L005f696c: { // 0x5f696c: 23d6 AND EDX,ESI
    s.dx = integer::logical((s.dx)&(s.si),32,flags);
  }
  L005f696e: { // 0x5f696e: 0fafcf IMUL ECX,EDI
    s.cx = integer::imul(s.cx,s.di,32,flags);
  }
  L005f6971: { // 0x5f6971: 0fafd0 IMUL EDX,EAX
    s.dx = integer::imul(s.dx,s.ax,32,flags);
  }
  L005f6974: { // 0x5f6974: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L005f6978: { // 0x5f6978: 8b742434 MOV ESI,dword ptr [ESP + 0x34]
    s.si = m.r32((f.sp+0x00000034u));
  }
  L005f697c: { // 0x5f697c: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L005f697e: { // 0x5f697e: 83c002 ADD EAX,0x2
    s.ax = integer::add(s.ax,0x00000002u,32,flags);
  }
  L005f6981: { // 0x5f6981: c1e908 SHR ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::right);
  }
  L005f6984: { // 0x5f6984: 0be9 OR EBP,ECX
    s.bp = integer::logical((s.bp)|(s.cx),32,flags);
  }
  L005f6986: { // 0x5f6986: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L005f698a: { // 0x5f698a: 668968fe MOV word ptr [EAX + -0x2],BP
    m.w16((s.ax-0x00000002u), (s.bp & 0xffffu));
  }
  L005f698e: { // 0x5f698e: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005f6990: { // 0x5f6990: 8b6e08 MOV EBP,dword ptr [ESI + 0x8]
    s.bp = m.r32((s.si+0x00000008u));
  }
  L005f6993: { // 0x5f6993: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L005f6994: { // 0x5f6994: 03d5 ADD EDX,EBP
    s.dx = integer::add(s.dx,s.bp,32,flags);
  }
  L005f6996: { // 0x5f6996: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L005f699a: { // 0x5f699a: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L005f699c: { // 0x5f699c: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L005f69a0: { // 0x5f69a0: 0f8c41ffffff JL 0x005f68e7
    if(integer::condition("JL",flags)) goto L005f68e7;
  }
  L005f69a6: { // 0x5f69a6: 8b6c241c MOV EBP,dword ptr [ESP + 0x1c]
    s.bp = m.r32((f.sp+0x0000001cu));
  }
  L005f69aa: { // 0x5f69aa: 8b5c2420 MOV EBX,dword ptr [ESP + 0x20]
    s.bx = m.r32((f.sp+0x00000020u));
  }
  L005f69ae: { // 0x5f69ae: 8b7c2424 MOV EDI,dword ptr [ESP + 0x24]
    s.di = m.r32((f.sp+0x00000024u));
  }
  L005f69b2: { // 0x5f69b2: eb04 JMP 0x005f69b8
    goto L005f69b8;
  }
  L005f69b4: { // 0x5f69b4: 8b6c241c MOV EBP,dword ptr [ESP + 0x1c]
    s.bp = m.r32((f.sp+0x0000001cu));
  }
  L005f69b8: { // 0x5f69b8: 8b442438 MOV EAX,dword ptr [ESP + 0x38]
    s.ax = m.r32((f.sp+0x00000038u));
  }
  L005f69bc: { // 0x5f69bc: 8b560c MOV EDX,dword ptr [ESI + 0xc]
    s.dx = m.r32((s.si+0x0000000cu));
  }
  L005f69bf: { // 0x5f69bf: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L005f69c1: { // 0x5f69c1: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L005f69c4: { // 0x5f69c4: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L005f69c5: { // 0x5f69c5: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L005f69c7: { // 0x5f69c7: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L005f69c9: { // 0x5f69c9: 895c2420 MOV dword ptr [ESP + 0x20],EBX
    m.w32((f.sp+0x00000020u), s.bx);
  }
  L005f69cd: { // 0x5f69cd: 897c2424 MOV dword ptr [ESP + 0x24],EDI
    m.w32((f.sp+0x00000024u), s.di);
  }
  L005f69d1: { // 0x5f69d1: 0f8cc6feffff JL 0x005f689d
    if(integer::condition("JL",flags)) goto L005f689d;
  }
  L005f69d7: { // 0x5f69d7: 8b5500 MOV EDX,dword ptr [EBP]
    s.dx = m.r32((s.bp));
  }
  L005f69da: { // 0x5f69da: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L005f69dc: { // 0x5f69dc: ff5260 CALL dword ptr [EDX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),6253023u); flags=s.arithmetic_flags;
  }
  L005f69df: { // 0x5f69df: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005f69e0: { // 0x5f69e0: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005f69e1: { // 0x5f69e1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005f69e2: { // 0x5f69e2: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005f69e3: { // 0x5f69e3: 83c42c ADD ESP,0x2c
    f.sp = integer::add(f.sp,0x0000002cu,32,flags);
  }
  L005f69e6: { // 0x5f69e6: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
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
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000070u)),4264836u); flags=s.arithmetic_flags;
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
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000074u)),4264850u); flags=s.arithmetic_flags;
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
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000007cu)),4264904u); flags=s.arithmetic_flags;
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
void f_000112c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004112c0: { // 0x4112c0: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L004112c3: { // 0x4112c3: c3 RET
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
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4395888u:f_00031370(m,s,child,{});break;
case 7236576u:f_002e6be0(m,s,child,{});break;
case 6252608u:f_001f6840(m,s,child,{});break;
case 4264816u:f_00011370(m,s,child,{});break;
case 4264880u:f_000113b0(m,s,child,{});break;
case 4264896u:f_000113c0(m,s,child,{});break;
case 4264640u:f_000112c0(m,s,child,{});break;
case 4264688u:f_000112f0(m,s,child,{});break;
default:throw std::domain_error("recovery217 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00534e50(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00534e50: { // 0x534e50: 83ec18 SUB ESP,0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
  L00534e53: { // 0x534e53: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00534e54: { // 0x534e54: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00534e55: { // 0x534e55: 8b7c242c MOV EDI,dword ptr [ESP + 0x2c]
    s.di = m.r32((f.sp+0x0000002cu));
  }
  L00534e59: { // 0x534e59: 8bea MOV EBP,EDX
    s.bp = s.dx;
  }
  L00534e5b: { // 0x534e5b: 8d44240c LEA EAX,[ESP + 0xc]
    s.ax = (f.sp+0x0000000cu);
  }
  L00534e5f: { // 0x534e5f: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00534e60: { // 0x534e60: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  L00534e64: { // 0x534e64: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00534e65: { // 0x534e65: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00534e66: { // 0x534e66: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00534e67: { // 0x534e67: 8b0d306d8300 MOV ECX,dword ptr [0x00836d30]
    s.cx = m.r32((0x00836d30u));
  }
  L00534e6d: { // 0x534e6d: c744241800000000 MOV dword ptr [ESP + 0x18],0x0
    m.w32((f.sp+0x00000018u), 0x00000000u);
  }
  L00534e75: { // 0x534e75: c744241c00000000 MOV dword ptr [ESP + 0x1c],0x0
    m.w32((f.sp+0x0000001cu), 0x00000000u);
  }
  L00534e7d: { // 0x534e7d: e8eec4efff CALL 0x00431370
    s.arithmetic_flags=flags; invoke(m,s,f,0x00431370u,5459586u); flags=s.arithmetic_flags;
  }
  L00534e82: { // 0x534e82: 8a442434 MOV AL,byte ptr [ESP + 0x34]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000034u)));
  }
  L00534e86: { // 0x534e86: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00534e88: { // 0x534e88: 7408 JZ 0x00534e92
    if(integer::condition("JZ",flags)) goto L00534e92;
  }
  L00534e8a: { // 0x534e8a: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  L00534e8c: { // 0x534e8c: 89542408 MOV dword ptr [ESP + 0x8],EDX
    m.w32((f.sp+0x00000008u), s.dx);
  }
  L00534e90: { // 0x534e90: eb04 JMP 0x00534e96
    goto L00534e96;
  }
  L00534e92: { // 0x534e92: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L00534e96: { // 0x534e96: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L00534e9a: { // 0x534e9a: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L00534e9e: { // 0x534e9e: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00534e9f: { // 0x534e9f: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L00534ea3: { // 0x534ea3: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00534ea7: { // 0x534ea7: 8a442434 MOV AL,byte ptr [ESP + 0x34]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000034u)));
  }
  L00534eab: { // 0x534eab: 89742420 MOV dword ptr [ESP + 0x20],ESI
    m.w32((f.sp+0x00000020u), s.si);
  }
  L00534eaf: { // 0x534eaf: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L00534eb3: { // 0x534eb3: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L00534eb5: { // 0x534eb5: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L00534eb9: { // 0x534eb9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00534eba: { // 0x534eba: 7411 JZ 0x00534ecd
    if(integer::condition("JZ",flags)) goto L00534ecd;
  }
  L00534ebc: { // 0x534ebc: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L00534ebe: { // 0x534ebe: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00534ec0: { // 0x534ec0: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00534ec1: { // 0x534ec1: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00534ec3: { // 0x534ec3: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00534ec5: { // 0x534ec5: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00534ec7: { // 0x534ec7: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00534ecb: { // 0x534ecb: eb0c JMP 0x00534ed9
    goto L00534ed9;
  }
  L00534ecd: { // 0x534ecd: a802 TEST AL,0x2
    (void)integer::logical(((s.ax & 0xffu))&(0x00000002u),8,flags);
  }
  L00534ecf: { // 0x534ecf: 7408 JZ 0x00534ed9
    if(integer::condition("JZ",flags)) goto L00534ed9;
  }
  L00534ed1: { // 0x534ed1: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L00534ed3: { // 0x534ed3: 03cf ADD ECX,EDI
    s.cx = integer::add(s.cx,s.di,32,flags);
  }
  L00534ed5: { // 0x534ed5: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L00534ed9: { // 0x534ed9: bafcffffff MOV EDX,0xfffffffc
    s.dx = 0xfffffffcu;
  }
  L00534ede: { // 0x534ede: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L00534ee2: { // 0x534ee2: e8f91c1b00 CALL 0x006e6be0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006e6be0u,5459687u); flags=s.arithmetic_flags;
  }
  L00534ee7: { // 0x534ee7: 8bd5 MOV EDX,EBP
    s.dx = s.bp;
  }
  L00534ee9: { // 0x534ee9: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L00534eed: { // 0x534eed: 689f000000 PUSH 0x9f
    f.push(m,0x0000009fu);
  }
  L00534ef2: { // 0x534ef2: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00534ef4: { // 0x534ef4: e847190c00 CALL 0x005f6840
    s.arithmetic_flags=flags; invoke(m,s,f,0x005f6840u,5459705u); flags=s.arithmetic_flags;
  }
  L00534ef9: { // 0x534ef9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00534efa: { // 0x534efa: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00534efb: { // 0x534efb: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L00534efe: { // 0x534efe: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
