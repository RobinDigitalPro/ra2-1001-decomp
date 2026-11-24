#include "recovered/recovery_b1544_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b1544 {
namespace {
void f_000290c0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);
void tail(Memory&,State&,Frame&,std::uint32_t);
void f_000290c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004290c0: { // 0x4290c0: 81ec80000000 SUB ESP,0x80
    f.sp = integer::sub(f.sp,0x00000080u,32,flags);
  }
  L004290c6: { // 0x4290c6: 894c2450 MOV dword ptr [ESP + 0x50],ECX
    m.w32((f.sp+0x00000050u), s.cx);
  }
  L004290ca: { // 0x4290ca: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004290cb: { // 0x4290cb: 8b8c2488000000 MOV ECX,dword ptr [ESP + 0x88]
    s.cx = m.r32((f.sp+0x00000088u));
  }
  L004290d2: { // 0x4290d2: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004290d3: { // 0x4290d3: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004290d4: { // 0x4290d4: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004290d5: { // 0x4290d5: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L004290d8: { // 0x4290d8: 8b510c MOV EDX,dword ptr [ECX + 0xc]
    s.dx = m.r32((s.cx+0x0000000cu));
  }
  L004290db: { // 0x4290db: 8b39 MOV EDI,dword ptr [ECX]
    s.di = m.r32((s.cx));
  }
  L004290dd: { // 0x4290dd: 8b6914 MOV EBP,dword ptr [ECX + 0x14]
    s.bp = m.r32((s.cx+0x00000014u));
  }
  L004290e0: { // 0x4290e0: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L004290e1: { // 0x4290e1: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L004290e3: { // 0x4290e3: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L004290e5: { // 0x4290e5: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L004290e7: { // 0x4290e7: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L004290eb: { // 0x4290eb: 89442468 MOV dword ptr [ESP + 0x68],EAX
    m.w32((f.sp+0x00000068u), s.ax);
  }
  L004290ef: { // 0x4290ef: 895c2434 MOV dword ptr [ESP + 0x34],EBX
    m.w32((f.sp+0x00000034u), s.bx);
  }
  L004290f3: { // 0x4290f3: 89bc2480000000 MOV dword ptr [ESP + 0x80],EDI
    m.w32((f.sp+0x00000080u), s.di);
  }
  L004290fa: { // 0x4290fa: 896c2464 MOV dword ptr [ESP + 0x64],EBP
    m.w32((f.sp+0x00000064u), s.bp);
  }
  L004290fe: { // 0x4290fe: 895c242c MOV dword ptr [ESP + 0x2c],EBX
    m.w32((f.sp+0x0000002cu), s.bx);
  }
  L00429102: { // 0x429102: 895c2428 MOV dword ptr [ESP + 0x28],EBX
    m.w32((f.sp+0x00000028u), s.bx);
  }
  L00429106: { // 0x429106: 66895c2418 MOV word ptr [ESP + 0x18],BX
    m.w16((f.sp+0x00000018u), (s.bx & 0xffffu));
  }
  L0042910b: { // 0x42910b: 66895c241a MOV word ptr [ESP + 0x1a],BX
    m.w16((f.sp+0x0000001au), (s.bx & 0xffffu));
  }
  L00429110: { // 0x429110: 66895c2470 MOV word ptr [ESP + 0x70],BX
    m.w16((f.sp+0x00000070u), (s.bx & 0xffffu));
  }
  L00429115: { // 0x429115: 66895c2472 MOV word ptr [ESP + 0x72],BX
    m.w16((f.sp+0x00000072u), (s.bx & 0xffffu));
  }
  L0042911a: { // 0x42911a: 895c2420 MOV dword ptr [ESP + 0x20],EBX
    m.w32((f.sp+0x00000020u), s.bx);
  }
  L0042911e: { // 0x42911e: 895c2424 MOV dword ptr [ESP + 0x24],EBX
    m.w32((f.sp+0x00000024u), s.bx);
  }
  L00429122: { // 0x429122: 66895c2414 MOV word ptr [ESP + 0x14],BX
    m.w16((f.sp+0x00000014u), (s.bx & 0xffffu));
  }
  L00429127: { // 0x429127: 66895c2416 MOV word ptr [ESP + 0x16],BX
    m.w16((f.sp+0x00000016u), (s.bx & 0xffffu));
  }
  L0042912c: { // 0x42912c: 0f8ed8030000 JLE 0x0042950a
    if(integer::condition("JLE",flags)) goto L0042950a;
  }
  L00429132: { // 0x429132: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L00429136: { // 0x429136: 83fe14 CMP ESI,0x14
    (void)integer::sub(s.si,0x00000014u,32,flags);
  }
  L00429139: { // 0x429139: 0f8df9020000 JGE 0x00429438
    if(integer::condition("JGE",flags)) goto L00429438;
  }
  L0042913f: { // 0x42913f: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00429143: { // 0x429143: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L00429145: { // 0x429145: 83f808 CMP EAX,0x8
    (void)integer::sub(s.ax,0x00000008u,32,flags);
  }
  L00429148: { // 0x429148: 8944246c MOV dword ptr [ESP + 0x6c],EAX
    m.w32((f.sp+0x0000006cu), s.ax);
  }
  L0042914c: { // 0x42914c: 0f8587000000 JNZ 0x004291d9
    if(integer::condition("JNZ",flags)) goto L004291d9;
  }
  L00429152: { // 0x429152: 668b842482000000 MOV AX,word ptr [ESP + 0x82]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x00000082u)));
  }
  L0042915a: { // 0x42915a: 8b15a09d8300 MOV EDX,dword ptr [0x00839da0]
    s.dx = m.r32((0x00839da0u));
  }
  L00429160: { // 0x429160: 660305a29d8300 ADD AX,word ptr [0x00839da2]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((0x00839da2u)),16,flags));
  }
  L00429167: { // 0x429167: 03fa ADD EDI,EDX
    s.di = integer::add(s.di,s.dx,32,flags);
  }
  L00429169: { // 0x429169: 66895c2440 MOV word ptr [ESP + 0x40],BX
    m.w16((f.sp+0x00000040u), (s.bx & 0xffffu));
  }
  L0042916e: { // 0x42916e: 66895c2442 MOV word ptr [ESP + 0x42],BX
    m.w16((f.sp+0x00000042u), (s.bx & 0xffffu));
  }
  L00429173: { // 0x429173: 8b542440 MOV EDX,dword ptr [ESP + 0x40]
    s.dx = m.r32((f.sp+0x00000040u));
  }
  L00429177: { // 0x429177: 668944243e MOV word ptr [ESP + 0x3e],AX
    m.w16((f.sp+0x0000003eu), (s.ax & 0xffffu));
  }
  L0042917c: { // 0x42917c: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00429180: { // 0x429180: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L00429181: { // 0x429181: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  L00429184: { // 0x429184: 66897c243c MOV word ptr [ESP + 0x3c],DI
    m.w16((f.sp+0x0000003cu), (s.di & 0xffffu));
  }
  L00429189: { // 0x429189: 8b7c243c MOV EDI,dword ptr [ESP + 0x3c]
    s.di = m.r32((f.sp+0x0000003cu));
  }
  L0042918d: { // 0x42918d: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L00429191: { // 0x429191: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00429195: { // 0x429195: 66895c2444 MOV word ptr [ESP + 0x44],BX
    m.w16((f.sp+0x00000044u), (s.bx & 0xffffu));
  }
  L0042919a: { // 0x42919a: 66895c2446 MOV word ptr [ESP + 0x46],BX
    m.w16((f.sp+0x00000046u), (s.bx & 0xffffu));
  }
  L0042919f: { // 0x42919f: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    s.ax = m.r32((f.sp+0x00000044u));
  }
  L004291a3: { // 0x4291a3: 66895c2448 MOV word ptr [ESP + 0x48],BX
    m.w16((f.sp+0x00000048u), (s.bx & 0xffffu));
  }
  L004291a8: { // 0x4291a8: 66895c244a MOV word ptr [ESP + 0x4a],BX
    m.w16((f.sp+0x0000004au), (s.bx & 0xffffu));
  }
  L004291ad: { // 0x4291ad: 8b542448 MOV EDX,dword ptr [ESP + 0x48]
    s.dx = m.r32((f.sp+0x00000048u));
  }
  L004291b1: { // 0x4291b1: 89bc2480000000 MOV dword ptr [ESP + 0x80],EDI
    m.w32((f.sp+0x00000080u), s.di);
  }
  L004291b8: { // 0x4291b8: 89742434 MOV dword ptr [ESP + 0x34],ESI
    m.w32((f.sp+0x00000034u), s.si);
  }
  L004291bc: { // 0x4291bc: 895c2428 MOV dword ptr [ESP + 0x28],EBX
    m.w32((f.sp+0x00000028u), s.bx);
  }
  L004291c0: { // 0x4291c0: 895c2420 MOV dword ptr [ESP + 0x20],EBX
    m.w32((f.sp+0x00000020u), s.bx);
  }
  L004291c4: { // 0x4291c4: 895c2424 MOV dword ptr [ESP + 0x24],EBX
    m.w32((f.sp+0x00000024u), s.bx);
  }
  L004291c8: { // 0x4291c8: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L004291cc: { // 0x4291cc: 8974242c MOV dword ptr [ESP + 0x2c],ESI
    m.w32((f.sp+0x0000002cu), s.si);
  }
  L004291d0: { // 0x4291d0: 89542470 MOV dword ptr [ESP + 0x70],EDX
    m.w32((f.sp+0x00000070u), s.dx);
  }
  L004291d4: { // 0x4291d4: e955020000 JMP 0x0042942e
    goto L0042942e;
  }
  L004291d9: { // 0x4291d9: 83f8fe CMP EAX,-0x2
    (void)integer::sub(s.ax,0xfffffffeu,32,flags);
  }
  L004291dc: { // 0x4291dc: 7511 JNZ 0x004291ef
    if(integer::condition("JNZ",flags)) goto L004291ef;
  }
  L004291de: { // 0x4291de: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L004291e2: { // 0x4291e2: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L004291e3: { // 0x4291e3: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  L004291e6: { // 0x4291e6: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L004291ea: { // 0x4291ea: e93f020000 JMP 0x0042942e
    goto L0042942e;
  }
  L004291ef: { // 0x4291ef: 83e007 AND EAX,0x7
    s.ax = integer::logical((s.ax)&(0x00000007u),32,flags);
  }
  L004291f2: { // 0x4291f2: 668b1c85a09d8300 MOV BX,word ptr [EAX*0x4 + 0x839da0]
    s.bx = with_ax(s.bx, m.r16(((s.ax * 0x00000004u)+0x00839da0u)));
  }
  L004291fa: { // 0x4291fa: 668b2c85a29d8300 MOV BP,word ptr [EAX*0x4 + 0x839da2]
    s.bp = (s.bp & 0xffff0000u) | ((m.r16(((s.ax * 0x00000004u)+0x00839da2u))) & 0xffffu);
  }
  L00429202: { // 0x429202: 668b0c85a09d8300 MOV CX,word ptr [EAX*0x4 + 0x839da0]
    s.cx = with_ax(s.cx, m.r16(((s.ax * 0x00000004u)+0x00839da0u)));
  }
  L0042920a: { // 0x42920a: 8d0485a09d8300 LEA EAX,[EAX*0x4 + 0x839da0]
    s.ax = ((s.ax * 0x00000004u)+0x00839da0u);
  }
  L00429211: { // 0x429211: 66034c2414 ADD CX,word ptr [ESP + 0x14]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((f.sp+0x00000014u)),16,flags));
  }
  L00429216: { // 0x429216: 66035c2418 ADD BX,word ptr [ESP + 0x18]
    s.bx = with_ax(s.bx, integer::add((s.bx & 0xffffu),m.r16((f.sp+0x00000018u)),16,flags));
  }
  L0042921b: { // 0x42921b: 668b4002 MOV AX,word ptr [EAX + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.ax+0x00000002u)));
  }
  L0042921f: { // 0x42921f: 66036c241a ADD BP,word ptr [ESP + 0x1a]
    s.bp = (s.bp & 0xffff0000u) | ((integer::add((s.bp & 0xffffu),m.r16((f.sp+0x0000001au)),16,flags)) & 0xffffu);
  }
  L00429224: { // 0x429224: 6603442416 ADD AX,word ptr [ESP + 0x16]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((f.sp+0x00000016u)),16,flags));
  }
  L00429229: { // 0x429229: 66894c2430 MOV word ptr [ESP + 0x30],CX
    m.w16((f.sp+0x00000030u), (s.cx & 0xffffu));
  }
  L0042922e: { // 0x42922e: 66895c2450 MOV word ptr [ESP + 0x50],BX
    m.w16((f.sp+0x00000050u), (s.bx & 0xffffu));
  }
  L00429233: { // 0x429233: 66896c2452 MOV word ptr [ESP + 0x52],BP
    m.w16((f.sp+0x00000052u), (s.bp & 0xffffu));
  }
  L00429238: { // 0x429238: 6689442432 MOV word ptr [ESP + 0x32],AX
    m.w16((f.sp+0x00000032u), (s.ax & 0xffffu));
  }
  L0042923d: { // 0x42923d: 0fbfc1 MOVSX EAX,CX
    s.ax = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L00429240: { // 0x429240: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00429241: { // 0x429241: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00429243: { // 0x429243: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L00429247: { // 0x429247: 33ca XOR ECX,EDX
    s.cx = integer::logical((s.cx)^(s.dx),32,flags);
  }
  L00429249: { // 0x429249: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L0042924b: { // 0x42924b: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L0042924d: { // 0x42924d: 0f8c31010000 JL 0x00429384
    if(integer::condition("JL",flags)) goto L00429384;
  }
  L00429253: { // 0x429253: 0fbf442432 MOVSX EAX,word ptr [ESP + 0x32]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000032u)),16));
  }
  L00429258: { // 0x429258: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00429259: { // 0x429259: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L0042925b: { // 0x42925b: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0042925d: { // 0x42925d: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L00429261: { // 0x429261: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00429263: { // 0x429263: 0f8c1b010000 JL 0x00429384
    if(integer::condition("JL",flags)) goto L00429384;
  }
  L00429269: { // 0x429269: 8b542430 MOV EDX,dword ptr [ESP + 0x30]
    s.dx = m.r32((f.sp+0x00000030u));
  }
  L0042926d: { // 0x42926d: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L00429271: { // 0x429271: 0fbfc5 MOVSX EAX,BP
    s.ax = std::uint32_t(integer::sign_extend((s.bp & 0xffffu),16));
  }
  L00429274: { // 0x429274: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L00429278: { // 0x429278: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L0042927c: { // 0x42927c: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0042927d: { // 0x42927d: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0042927f: { // 0x42927f: 0fbfc3 MOVSX EAX,BX
    s.ax = std::uint32_t(integer::sign_extend((s.bx & 0xffffu),16));
  }
  L00429282: { // 0x429282: 33ca XOR ECX,EDX
    s.cx = integer::logical((s.cx)^(s.dx),32,flags);
  }
  L00429284: { // 0x429284: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L00429286: { // 0x429286: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00429287: { // 0x429287: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L00429289: { // 0x429289: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0042928b: { // 0x42928b: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0042928d: { // 0x42928d: 7f02 JG 0x00429291
    if(integer::condition("JG",flags)) goto L00429291;
  }
  L0042928f: { // 0x42928f: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00429291: { // 0x429291: 8b54246c MOV EDX,dword ptr [ESP + 0x6c]
    s.dx = m.r32((f.sp+0x0000006cu));
  }
  L00429295: { // 0x429295: 83e207 AND EDX,0x7
    s.dx = integer::logical((s.dx)&(0x00000007u),32,flags);
  }
  L00429298: { // 0x429298: 668b0c95a09d8300 MOV CX,word ptr [EDX*0x4 + 0x839da0]
    s.cx = with_ax(s.cx, m.r16(((s.dx * 0x00000004u)+0x00839da0u)));
  }
  L004292a0: { // 0x4292a0: 8d1495a09d8300 LEA EDX,[EDX*0x4 + 0x839da0]
    s.dx = ((s.dx * 0x00000004u)+0x00839da0u);
  }
  L004292a7: { // 0x4292a7: 6603cf ADD CX,DI
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),(s.di & 0xffffu),16,flags));
  }
  L004292aa: { // 0x4292aa: 668b5202 MOV DX,word ptr [EDX + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.dx+0x00000002u)));
  }
  L004292ae: { // 0x4292ae: 66898c2488000000 MOV word ptr [ESP + 0x88],CX
    m.w16((f.sp+0x00000088u), (s.cx & 0xffffu));
  }
  L004292b6: { // 0x4292b6: 6603942482000000 ADD DX,word ptr [ESP + 0x82]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((f.sp+0x00000082u)),16,flags));
  }
  L004292be: { // 0x4292be: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L004292c2: { // 0x4292c2: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L004292c4: { // 0x4292c4: 668994248a000000 MOV word ptr [ESP + 0x8a],DX
    m.w16((f.sp+0x0000008au), (s.dx & 0xffffu));
  }
  L004292cc: { // 0x4292cc: 8b9c2488000000 MOV EBX,dword ptr [ESP + 0x88]
    s.bx = m.r32((f.sp+0x00000088u));
  }
  L004292d3: { // 0x4292d3: 8bfb MOV EDI,EBX
    s.di = s.bx;
  }
  L004292d5: { // 0x4292d5: 89bc2480000000 MOV dword ptr [ESP + 0x80],EDI
    m.w32((f.sp+0x00000080u), s.di);
  }
  L004292dc: { // 0x4292dc: 7d09 JGE 0x004292e7
    if(integer::condition("JGE",flags)) goto L004292e7;
  }
  L004292de: { // 0x4292de: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L004292e2: { // 0x4292e2: e984000000 JMP 0x0042936b
    goto L0042936b;
  }
  L004292e7: { // 0x4292e7: 8b542434 MOV EDX,dword ptr [ESP + 0x34]
    s.dx = m.r32((f.sp+0x00000034u));
  }
  L004292eb: { // 0x4292eb: 8b6c2460 MOV EBP,dword ptr [ESP + 0x60]
    s.bp = m.r32((f.sp+0x00000060u));
  }
  L004292ef: { // 0x4292ef: 8d442478 LEA EAX,[ESP + 0x78]
    s.ax = (f.sp+0x00000078u);
  }
  L004292f3: { // 0x4292f3: 8d4c2438 LEA ECX,[ESP + 0x38]
    s.cx = (f.sp+0x00000038u);
  }
  L004292f7: { // 0x4292f7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004292f8: { // 0x4292f8: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L004292fc: { // 0x4292fc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004292fd: { // 0x4292fd: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004292fe: { // 0x4292fe: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004292ff: { // 0x4292ff: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00429300: { // 0x429300: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00429302: { // 0x429302: 899c248c000000 MOV dword ptr [ESP + 0x8c],EBX
    m.w32((f.sp+0x0000008cu), s.bx);
  }
  L00429309: { // 0x429309: e862020000 CALL 0x00429570
    s.arithmetic_flags=flags; invoke(m,s,f,0x00429570u,4363022u); flags=s.arithmetic_flags;
  }
  L0042930e: { // 0x42930e: 8b442478 MOV EAX,dword ptr [ESP + 0x78]
    s.ax = m.r32((f.sp+0x00000078u));
  }
  L00429312: { // 0x429312: 8b8c248a000000 MOV ECX,dword ptr [ESP + 0x8a]
    s.cx = m.r32((f.sp+0x0000008au));
  }
  L00429319: { // 0x429319: 8b54247a MOV EDX,dword ptr [ESP + 0x7a]
    s.dx = m.r32((f.sp+0x0000007au));
  }
  L0042931d: { // 0x42931d: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L0042931f: { // 0x42931f: 8b442438 MOV EAX,dword ptr [ESP + 0x38]
    s.ax = m.r32((f.sp+0x00000038u));
  }
  L00429323: { // 0x429323: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L00429325: { // 0x429325: 66895c244c MOV word ptr [ESP + 0x4c],BX
    m.w16((f.sp+0x0000004cu), (s.bx & 0xffffu));
  }
  L0042932a: { // 0x42932a: 66894c244e MOV word ptr [ESP + 0x4e],CX
    m.w16((f.sp+0x0000004eu), (s.cx & 0xffffu));
  }
  L0042932f: { // 0x42932f: 8b54244c MOV EDX,dword ptr [ESP + 0x4c]
    s.dx = m.r32((f.sp+0x0000004cu));
  }
  L00429333: { // 0x429333: 8b4c2464 MOV ECX,dword ptr [ESP + 0x64]
    s.cx = m.r32((f.sp+0x00000064u));
  }
  L00429337: { // 0x429337: 8954246c MOV dword ptr [ESP + 0x6c],EDX
    m.w32((f.sp+0x0000006cu), s.dx);
  }
  L0042933b: { // 0x42933b: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0042933d: { // 0x42933d: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L00429340: { // 0x429340: 8b8c249c000000 MOV ECX,dword ptr [ESP + 0x9c]
    s.cx = m.r32((f.sp+0x0000009cu));
  }
  L00429347: { // 0x429347: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00429348: { // 0x429348: 8d542474 LEA EDX,[ESP + 0x74]
    s.dx = (f.sp+0x00000074u);
  }
  L0042934c: { // 0x42934c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0042934d: { // 0x42934d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0042934e: { // 0x42934e: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L00429350: { // 0x429350: 8d8c2488000000 LEA ECX,[ESP + 0x88]
    s.cx = (f.sp+0x00000088u);
  }
  L00429357: { // 0x429357: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L00429359: { // 0x429359: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0042935a: { // 0x42935a: 8b4c2430 MOV ECX,dword ptr [ESP + 0x30]
    s.cx = m.r32((f.sp+0x00000030u));
  }
  L0042935e: { // 0x42935e: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L0042935f: { // 0x42935f: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00429360: { // 0x429360: 8d1481 LEA EDX,[ECX + EAX*0x4]
    s.dx = (s.cx+(s.ax * 0x00000004u));
  }
  L00429363: { // 0x429363: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00429365: { // 0x429365: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00429366: { // 0x429366: e885030000 CALL 0x004296f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004296f0u,4363115u); flags=s.arithmetic_flags;
  }
  L0042936b: { // 0x42936b: 8b442450 MOV EAX,dword ptr [ESP + 0x50]
    s.ax = m.r32((f.sp+0x00000050u));
  }
  L0042936f: { // 0x42936f: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L00429370: { // 0x429370: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00429374: { // 0x429374: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00429378: { // 0x429378: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  L0042937b: { // 0x42937b: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0042937f: { // 0x42937f: e9a1000000 JMP 0x00429425
    goto L00429425;
  }
  L00429384: { // 0x429384: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00429386: { // 0x429386: 66394c2470 CMP word ptr [ESP + 0x70],CX
    (void)integer::sub(m.r16((f.sp+0x00000070u)),(s.cx & 0xffffu),16,flags);
  }
  L0042938b: { // 0x42938b: 752b JNZ 0x004293b8
    if(integer::condition("JNZ",flags)) goto L004293b8;
  }
  L0042938d: { // 0x42938d: 66394c2472 CMP word ptr [ESP + 0x72],CX
    (void)integer::sub(m.r16((f.sp+0x00000072u)),(s.cx & 0xffffu),16,flags);
  }
  L00429392: { // 0x429392: 7524 JNZ 0x004293b8
    if(integer::condition("JNZ",flags)) goto L004293b8;
  }
  L00429394: { // 0x429394: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L00429398: { // 0x429398: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L0042939c: { // 0x42939c: 66894c2454 MOV word ptr [ESP + 0x54],CX
    m.w16((f.sp+0x00000054u), (s.cx & 0xffffu));
  }
  L004293a1: { // 0x4293a1: 66894c2456 MOV word ptr [ESP + 0x56],CX
    m.w16((f.sp+0x00000056u), (s.cx & 0xffffu));
  }
  L004293a6: { // 0x4293a6: 8b4c2454 MOV ECX,dword ptr [ESP + 0x54]
    s.cx = m.r32((f.sp+0x00000054u));
  }
  L004293aa: { // 0x4293aa: 897c2470 MOV dword ptr [ESP + 0x70],EDI
    m.w32((f.sp+0x00000070u), s.di);
  }
  L004293ae: { // 0x4293ae: 8974242c MOV dword ptr [ESP + 0x2c],ESI
    m.w32((f.sp+0x0000002cu), s.si);
  }
  L004293b2: { // 0x4293b2: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L004293b6: { // 0x4293b6: eb6d JMP 0x00429425
    goto L00429425;
  }
  L004293b8: { // 0x4293b8: 8b54242c MOV EDX,dword ptr [ESP + 0x2c]
    s.dx = m.r32((f.sp+0x0000002cu));
  }
  L004293bc: { // 0x4293bc: 8b442472 MOV EAX,dword ptr [ESP + 0x72]
    s.ax = m.r32((f.sp+0x00000072u));
  }
  L004293c0: { // 0x4293c0: 8b5c2470 MOV EBX,dword ptr [ESP + 0x70]
    s.bx = m.r32((f.sp+0x00000070u));
  }
  L004293c4: { // 0x4293c4: 89542434 MOV dword ptr [ESP + 0x34],EDX
    m.w32((f.sp+0x00000034u), s.dx);
  }
  L004293c8: { // 0x4293c8: 8b942482000000 MOV EDX,dword ptr [ESP + 0x82]
    s.dx = m.r32((f.sp+0x00000082u));
  }
  L004293cf: { // 0x4293cf: 2bdf SUB EBX,EDI
    s.bx = integer::sub(s.bx,s.di,32,flags);
  }
  L004293d1: { // 0x4293d1: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004293d3: { // 0x4293d3: 66895c2458 MOV word ptr [ESP + 0x58],BX
    m.w16((f.sp+0x00000058u), (s.bx & 0xffffu));
  }
  L004293d8: { // 0x4293d8: 668944245a MOV word ptr [ESP + 0x5a],AX
    m.w16((f.sp+0x0000005au), (s.ax & 0xffffu));
  }
  L004293dd: { // 0x4293dd: 8b542458 MOV EDX,dword ptr [ESP + 0x58]
    s.dx = m.r32((f.sp+0x00000058u));
  }
  L004293e1: { // 0x4293e1: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L004293e4: { // 0x4293e4: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L004293e8: { // 0x4293e8: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L004293ec: { // 0x4293ec: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L004293f0: { // 0x4293f0: 66894c245c MOV word ptr [ESP + 0x5c],CX
    m.w16((f.sp+0x0000005cu), (s.cx & 0xffffu));
  }
  L004293f5: { // 0x4293f5: 66894c245e MOV word ptr [ESP + 0x5e],CX
    m.w16((f.sp+0x0000005eu), (s.cx & 0xffffu));
  }
  L004293fa: { // 0x4293fa: 8b4c245c MOV ECX,dword ptr [ESP + 0x5c]
    s.cx = m.r32((f.sp+0x0000005cu));
  }
  L004293fe: { // 0x4293fe: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004293ff: { // 0x4293ff: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L00429403: { // 0x429403: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00429405: { // 0x429405: 0fbfc3 MOVSX EAX,BX
    s.ax = std::uint32_t(integer::sign_extend((s.bx & 0xffffu),16));
  }
  L00429408: { // 0x429408: 33ca XOR ECX,EDX
    s.cx = integer::logical((s.cx)^(s.dx),32,flags);
  }
  L0042940a: { // 0x42940a: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L0042940c: { // 0x42940c: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0042940d: { // 0x42940d: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L0042940f: { // 0x42940f: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00429411: { // 0x429411: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00429413: { // 0x429413: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L00429417: { // 0x429417: 7f04 JG 0x0042941d
    if(integer::condition("JG",flags)) goto L0042941d;
  }
  L00429419: { // 0x429419: 894c2428 MOV dword ptr [ESP + 0x28],ECX
    m.w32((f.sp+0x00000028u), s.cx);
  }
  L0042941d: { // 0x42941d: 897c2470 MOV dword ptr [ESP + 0x70],EDI
    m.w32((f.sp+0x00000070u), s.di);
  }
  L00429421: { // 0x429421: 8974242c MOV dword ptr [ESP + 0x2c],ESI
    m.w32((f.sp+0x0000002cu), s.si);
  }
  L00429425: { // 0x429425: 8b8c2494000000 MOV ECX,dword ptr [ESP + 0x94]
    s.cx = m.r32((f.sp+0x00000094u));
  }
  L0042942c: { // 0x42942c: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0042942e: { // 0x42942e: 3b742468 CMP ESI,dword ptr [ESP + 0x68]
    (void)integer::sub(s.si,m.r32((f.sp+0x00000068u)),32,flags);
  }
  L00429432: { // 0x429432: 0f8cfefcffff JL 0x00429136
    if(integer::condition("JL",flags)) goto L00429136;
  }
  L00429438: { // 0x429438: 66395c2470 CMP word ptr [ESP + 0x70],BX
    (void)integer::sub(m.r16((f.sp+0x00000070u)),(s.bx & 0xffffu),16,flags);
  }
  L0042943d: { // 0x42943d: 750b JNZ 0x0042944a
    if(integer::condition("JNZ",flags)) goto L0042944a;
  }
  L0042943f: { // 0x42943f: 66395c2472 CMP word ptr [ESP + 0x72],BX
    (void)integer::sub(m.r16((f.sp+0x00000072u)),(s.bx & 0xffffu),16,flags);
  }
  L00429444: { // 0x429444: 0f84c0000000 JZ 0x0042950a
    if(integer::condition("JZ",flags)) goto L0042950a;
  }
  L0042944a: { // 0x42944a: 8b842482000000 MOV EAX,dword ptr [ESP + 0x82]
    s.ax = m.r32((f.sp+0x00000082u));
  }
  L00429451: { // 0x429451: 8b4c2472 MOV ECX,dword ptr [ESP + 0x72]
    s.cx = m.r32((f.sp+0x00000072u));
  }
  L00429455: { // 0x429455: 8b542470 MOV EDX,dword ptr [ESP + 0x70]
    s.dx = m.r32((f.sp+0x00000070u));
  }
  L00429459: { // 0x429459: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L0042945b: { // 0x42945b: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0042945e: { // 0x42945e: 8bef MOV EBP,EDI
    s.bp = s.di;
  }
  L00429460: { // 0x429460: 2bea SUB EBP,EDX
    s.bp = integer::sub(s.bp,s.dx,32,flags);
  }
  L00429462: { // 0x429462: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00429463: { // 0x429463: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00429465: { // 0x429465: 0fbfc5 MOVSX EAX,BP
    s.ax = std::uint32_t(integer::sign_extend((s.bp & 0xffffu),16));
  }
  L00429468: { // 0x429468: 33ca XOR ECX,EDX
    s.cx = integer::logical((s.cx)^(s.dx),32,flags);
  }
  L0042946a: { // 0x42946a: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L0042946c: { // 0x42946c: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0042946d: { // 0x42946d: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L0042946f: { // 0x42946f: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00429471: { // 0x429471: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00429473: { // 0x429473: 7f02 JG 0x00429477
    if(integer::condition("JG",flags)) goto L00429477;
  }
  L00429475: { // 0x429475: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00429477: { // 0x429477: 8b54242c MOV EDX,dword ptr [ESP + 0x2c]
    s.dx = m.r32((f.sp+0x0000002cu));
  }
  L0042947b: { // 0x42947b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0042947d: { // 0x42947d: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L0042947f: { // 0x42947f: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00429480: { // 0x429480: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00429482: { // 0x429482: 7e7f JLE 0x00429503
    if(integer::condition("JLE",flags)) goto L00429503;
  }
  L00429484: { // 0x429484: 8b6c2460 MOV EBP,dword ptr [ESP + 0x60]
    s.bp = m.r32((f.sp+0x00000060u));
  }
  L00429488: { // 0x429488: 8d442478 LEA EAX,[ESP + 0x78]
    s.ax = (f.sp+0x00000078u);
  }
  L0042948c: { // 0x42948c: 8d4c2438 LEA ECX,[ESP + 0x38]
    s.cx = (f.sp+0x00000038u);
  }
  L00429490: { // 0x429490: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00429491: { // 0x429491: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00429492: { // 0x429492: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L00429493: { // 0x429493: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00429494: { // 0x429494: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L00429498: { // 0x429498: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00429499: { // 0x429499: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0042949a: { // 0x42949a: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0042949c: { // 0x42949c: 89bc248c000000 MOV dword ptr [ESP + 0x8c],EDI
    m.w32((f.sp+0x0000008cu), s.di);
  }
  L004294a3: { // 0x4294a3: e8c8000000 CALL 0x00429570
    s.arithmetic_flags=flags; invoke(m,s,f,0x00429570u,4363432u); flags=s.arithmetic_flags;
  }
  L004294a8: { // 0x4294a8: 8b442478 MOV EAX,dword ptr [ESP + 0x78]
    s.ax = m.r32((f.sp+0x00000078u));
  }
  L004294ac: { // 0x4294ac: 8b54247a MOV EDX,dword ptr [ESP + 0x7a]
    s.dx = m.r32((f.sp+0x0000007au));
  }
  L004294b0: { // 0x4294b0: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L004294b2: { // 0x4294b2: 8b842482000000 MOV EAX,dword ptr [ESP + 0x82]
    s.ax = m.r32((f.sp+0x00000082u));
  }
  L004294b9: { // 0x4294b9: 8b4c2464 MOV ECX,dword ptr [ESP + 0x64]
    s.cx = m.r32((f.sp+0x00000064u));
  }
  L004294bd: { // 0x4294bd: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004294bf: { // 0x4294bf: 66897c2460 MOV word ptr [ESP + 0x60],DI
    m.w16((f.sp+0x00000060u), (s.di & 0xffffu));
  }
  L004294c4: { // 0x4294c4: 6689442462 MOV word ptr [ESP + 0x62],AX
    m.w16((f.sp+0x00000062u), (s.ax & 0xffffu));
  }
  L004294c9: { // 0x4294c9: 8b442460 MOV EAX,dword ptr [ESP + 0x60]
    s.ax = m.r32((f.sp+0x00000060u));
  }
  L004294cd: { // 0x4294cd: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L004294cf: { // 0x4294cf: 89442470 MOV dword ptr [ESP + 0x70],EAX
    m.w32((f.sp+0x00000070u), s.ax);
  }
  L004294d3: { // 0x4294d3: 8b44243c MOV EAX,dword ptr [ESP + 0x3c]
    s.ax = m.r32((f.sp+0x0000003cu));
  }
  L004294d7: { // 0x4294d7: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  L004294d9: { // 0x4294d9: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L004294dc: { // 0x4294dc: 8b8c249c000000 MOV ECX,dword ptr [ESP + 0x9c]
    s.cx = m.r32((f.sp+0x0000009cu));
  }
  L004294e3: { // 0x4294e3: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004294e4: { // 0x4294e4: 8d542474 LEA EDX,[ESP + 0x74]
    s.dx = (f.sp+0x00000074u);
  }
  L004294e8: { // 0x4294e8: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004294e9: { // 0x4294e9: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004294ea: { // 0x4294ea: 8b54242c MOV EDX,dword ptr [ESP + 0x2c]
    s.dx = m.r32((f.sp+0x0000002cu));
  }
  L004294ee: { // 0x4294ee: 8d8c2488000000 LEA ECX,[ESP + 0x88]
    s.cx = (f.sp+0x00000088u);
  }
  L004294f5: { // 0x4294f5: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L004294f6: { // 0x4294f6: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004294f7: { // 0x4294f7: 8d0482 LEA EAX,[EDX + EAX*0x4]
    s.ax = (s.dx+(s.ax * 0x00000004u));
  }
  L004294fa: { // 0x4294fa: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004294fb: { // 0x4294fb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004294fc: { // 0x4294fc: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L004294fe: { // 0x4294fe: e8ed010000 CALL 0x004296f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004296f0u,4363523u); flags=s.arithmetic_flags;
  }
  L00429503: { // 0x429503: 8b8c2494000000 MOV ECX,dword ptr [ESP + 0x94]
    s.cx = m.r32((f.sp+0x00000094u));
  }
  L0042950a: { // 0x42950a: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L0042950e: { // 0x42950e: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L00429510: { // 0x429510: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L00429512: { // 0x429512: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00429515: { // 0x429515: 7423 JZ 0x0042953a
    if(integer::condition("JZ",flags)) goto L0042953a;
  }
  L00429517: { // 0x429517: 8b6c2468 MOV EBP,dword ptr [ESP + 0x68]
    s.bp = m.r32((f.sp+0x00000068u));
  }
  L0042951b: { // 0x42951b: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L0042951d: { // 0x42951d: 3bf5 CMP ESI,EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  L0042951f: { // 0x42951f: 7d19 JGE 0x0042953a
    if(integer::condition("JGE",flags)) goto L0042953a;
  }
  L00429521: { // 0x429521: 83f8fe CMP EAX,-0x2
    (void)integer::sub(s.ax,0xfffffffeu,32,flags);
  }
  L00429524: { // 0x429524: 7408 JZ 0x0042952e
    if(integer::condition("JZ",flags)) goto L0042952e;
  }
  L00429526: { // 0x429526: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L00429528: { // 0x429528: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L00429529: { // 0x429529: 8907 MOV dword ptr [EDI],EAX
    m.w32((s.di), s.ax);
  }
  L0042952b: { // 0x42952b: 83c704 ADD EDI,0x4
    s.di = integer::add(s.di,0x00000004u,32,flags);
  }
  L0042952e: { // 0x42952e: 8b4204 MOV EAX,dword ptr [EDX + 0x4]
    s.ax = m.r32((s.dx+0x00000004u));
  }
  L00429531: { // 0x429531: 83c204 ADD EDX,0x4
    s.dx = integer::add(s.dx,0x00000004u,32,flags);
  }
  L00429534: { // 0x429534: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L00429535: { // 0x429535: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00429538: { // 0x429538: 75e3 JNZ 0x0042951d
    if(integer::condition("JNZ",flags)) goto L0042951d;
  }
  L0042953a: { // 0x42953a: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L0042953d: { // 0x42953d: 8bd3 MOV EDX,EBX
    s.dx = s.bx;
  }
  L0042953f: { // 0x42953f: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00429540: { // 0x429540: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L00429542: { // 0x429542: 7d19 JGE 0x0042955d
    if(integer::condition("JGE",flags)) goto L0042955d;
  }
  L00429544: { // 0x429544: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L00429548: { // 0x429548: 8d0498 LEA EAX,[EAX + EBX*0x4]
    s.ax = (s.ax+(s.bx * 0x00000004u));
  }
  L0042954b: { // 0x42954b: c700ffffffff MOV dword ptr [EAX],0xffffffff
    m.w32((s.ax), 0xffffffffu);
  }
  L00429551: { // 0x429551: 8b7108 MOV ESI,dword ptr [ECX + 0x8]
    s.si = m.r32((s.cx+0x00000008u));
  }
  L00429554: { // 0x429554: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L00429555: { // 0x429555: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  L00429558: { // 0x429558: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L00429559: { // 0x429559: 3bd6 CMP EDX,ESI
    (void)integer::sub(s.dx,s.si,32,flags);
  }
  L0042955b: { // 0x42955b: 7cee JL 0x0042954b
    if(integer::condition("JL",flags)) goto L0042954b;
  }
  L0042955d: { // 0x42955d: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L0042955e: { // 0x42955e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0042955f: { // 0x42955f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00429560: { // 0x429560: 895908 MOV dword ptr [ECX + 0x8],EBX
    m.w32((s.cx+0x00000008u), s.bx);
  }
  L00429563: { // 0x429563: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00429564: { // 0x429564: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00429565: { // 0x429565: 81c480000000 ADD ESP,0x80
    f.sp = integer::add(f.sp,0x00000080u,32,flags);
  }
  L0042956b: { // 0x42956b: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4362432u:f_000290c0(m,s,child,{});break;
default:throw std::domain_error("recovery1544 unreviewed original call");}
f.sp=child.sp;
}
}
namespace { void tail(Memory&m,State&s,Frame&f,std::uint32_t target){ throw std::domain_error("B1544 no reviewed tail"); } }

std::uint32_t fun_004290c0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004290c0: { // 0x4290c0: 81ec80000000 SUB ESP,0x80
    f.sp = integer::sub(f.sp,0x00000080u,32,flags);
  }
  L004290c6: { // 0x4290c6: 894c2450 MOV dword ptr [ESP + 0x50],ECX
    m.w32((f.sp+0x00000050u), s.cx);
  }
  L004290ca: { // 0x4290ca: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004290cb: { // 0x4290cb: 8b8c2488000000 MOV ECX,dword ptr [ESP + 0x88]
    s.cx = m.r32((f.sp+0x00000088u));
  }
  L004290d2: { // 0x4290d2: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004290d3: { // 0x4290d3: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004290d4: { // 0x4290d4: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004290d5: { // 0x4290d5: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L004290d8: { // 0x4290d8: 8b510c MOV EDX,dword ptr [ECX + 0xc]
    s.dx = m.r32((s.cx+0x0000000cu));
  }
  L004290db: { // 0x4290db: 8b39 MOV EDI,dword ptr [ECX]
    s.di = m.r32((s.cx));
  }
  L004290dd: { // 0x4290dd: 8b6914 MOV EBP,dword ptr [ECX + 0x14]
    s.bp = m.r32((s.cx+0x00000014u));
  }
  L004290e0: { // 0x4290e0: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L004290e1: { // 0x4290e1: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L004290e3: { // 0x4290e3: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L004290e5: { // 0x4290e5: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L004290e7: { // 0x4290e7: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L004290eb: { // 0x4290eb: 89442468 MOV dword ptr [ESP + 0x68],EAX
    m.w32((f.sp+0x00000068u), s.ax);
  }
  L004290ef: { // 0x4290ef: 895c2434 MOV dword ptr [ESP + 0x34],EBX
    m.w32((f.sp+0x00000034u), s.bx);
  }
  L004290f3: { // 0x4290f3: 89bc2480000000 MOV dword ptr [ESP + 0x80],EDI
    m.w32((f.sp+0x00000080u), s.di);
  }
  L004290fa: { // 0x4290fa: 896c2464 MOV dword ptr [ESP + 0x64],EBP
    m.w32((f.sp+0x00000064u), s.bp);
  }
  L004290fe: { // 0x4290fe: 895c242c MOV dword ptr [ESP + 0x2c],EBX
    m.w32((f.sp+0x0000002cu), s.bx);
  }
  L00429102: { // 0x429102: 895c2428 MOV dword ptr [ESP + 0x28],EBX
    m.w32((f.sp+0x00000028u), s.bx);
  }
  L00429106: { // 0x429106: 66895c2418 MOV word ptr [ESP + 0x18],BX
    m.w16((f.sp+0x00000018u), (s.bx & 0xffffu));
  }
  L0042910b: { // 0x42910b: 66895c241a MOV word ptr [ESP + 0x1a],BX
    m.w16((f.sp+0x0000001au), (s.bx & 0xffffu));
  }
  L00429110: { // 0x429110: 66895c2470 MOV word ptr [ESP + 0x70],BX
    m.w16((f.sp+0x00000070u), (s.bx & 0xffffu));
  }
  L00429115: { // 0x429115: 66895c2472 MOV word ptr [ESP + 0x72],BX
    m.w16((f.sp+0x00000072u), (s.bx & 0xffffu));
  }
  L0042911a: { // 0x42911a: 895c2420 MOV dword ptr [ESP + 0x20],EBX
    m.w32((f.sp+0x00000020u), s.bx);
  }
  L0042911e: { // 0x42911e: 895c2424 MOV dword ptr [ESP + 0x24],EBX
    m.w32((f.sp+0x00000024u), s.bx);
  }
  L00429122: { // 0x429122: 66895c2414 MOV word ptr [ESP + 0x14],BX
    m.w16((f.sp+0x00000014u), (s.bx & 0xffffu));
  }
  L00429127: { // 0x429127: 66895c2416 MOV word ptr [ESP + 0x16],BX
    m.w16((f.sp+0x00000016u), (s.bx & 0xffffu));
  }
  L0042912c: { // 0x42912c: 0f8ed8030000 JLE 0x0042950a
    if(integer::condition("JLE",flags)) goto L0042950a;
  }
  L00429132: { // 0x429132: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L00429136: { // 0x429136: 83fe14 CMP ESI,0x14
    (void)integer::sub(s.si,0x00000014u,32,flags);
  }
  L00429139: { // 0x429139: 0f8df9020000 JGE 0x00429438
    if(integer::condition("JGE",flags)) goto L00429438;
  }
  L0042913f: { // 0x42913f: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00429143: { // 0x429143: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L00429145: { // 0x429145: 83f808 CMP EAX,0x8
    (void)integer::sub(s.ax,0x00000008u,32,flags);
  }
  L00429148: { // 0x429148: 8944246c MOV dword ptr [ESP + 0x6c],EAX
    m.w32((f.sp+0x0000006cu), s.ax);
  }
  L0042914c: { // 0x42914c: 0f8587000000 JNZ 0x004291d9
    if(integer::condition("JNZ",flags)) goto L004291d9;
  }
  L00429152: { // 0x429152: 668b842482000000 MOV AX,word ptr [ESP + 0x82]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x00000082u)));
  }
  L0042915a: { // 0x42915a: 8b15a09d8300 MOV EDX,dword ptr [0x00839da0]
    s.dx = m.r32((0x00839da0u));
  }
  L00429160: { // 0x429160: 660305a29d8300 ADD AX,word ptr [0x00839da2]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((0x00839da2u)),16,flags));
  }
  L00429167: { // 0x429167: 03fa ADD EDI,EDX
    s.di = integer::add(s.di,s.dx,32,flags);
  }
  L00429169: { // 0x429169: 66895c2440 MOV word ptr [ESP + 0x40],BX
    m.w16((f.sp+0x00000040u), (s.bx & 0xffffu));
  }
  L0042916e: { // 0x42916e: 66895c2442 MOV word ptr [ESP + 0x42],BX
    m.w16((f.sp+0x00000042u), (s.bx & 0xffffu));
  }
  L00429173: { // 0x429173: 8b542440 MOV EDX,dword ptr [ESP + 0x40]
    s.dx = m.r32((f.sp+0x00000040u));
  }
  L00429177: { // 0x429177: 668944243e MOV word ptr [ESP + 0x3e],AX
    m.w16((f.sp+0x0000003eu), (s.ax & 0xffffu));
  }
  L0042917c: { // 0x42917c: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00429180: { // 0x429180: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L00429181: { // 0x429181: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  L00429184: { // 0x429184: 66897c243c MOV word ptr [ESP + 0x3c],DI
    m.w16((f.sp+0x0000003cu), (s.di & 0xffffu));
  }
  L00429189: { // 0x429189: 8b7c243c MOV EDI,dword ptr [ESP + 0x3c]
    s.di = m.r32((f.sp+0x0000003cu));
  }
  L0042918d: { // 0x42918d: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L00429191: { // 0x429191: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00429195: { // 0x429195: 66895c2444 MOV word ptr [ESP + 0x44],BX
    m.w16((f.sp+0x00000044u), (s.bx & 0xffffu));
  }
  L0042919a: { // 0x42919a: 66895c2446 MOV word ptr [ESP + 0x46],BX
    m.w16((f.sp+0x00000046u), (s.bx & 0xffffu));
  }
  L0042919f: { // 0x42919f: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    s.ax = m.r32((f.sp+0x00000044u));
  }
  L004291a3: { // 0x4291a3: 66895c2448 MOV word ptr [ESP + 0x48],BX
    m.w16((f.sp+0x00000048u), (s.bx & 0xffffu));
  }
  L004291a8: { // 0x4291a8: 66895c244a MOV word ptr [ESP + 0x4a],BX
    m.w16((f.sp+0x0000004au), (s.bx & 0xffffu));
  }
  L004291ad: { // 0x4291ad: 8b542448 MOV EDX,dword ptr [ESP + 0x48]
    s.dx = m.r32((f.sp+0x00000048u));
  }
  L004291b1: { // 0x4291b1: 89bc2480000000 MOV dword ptr [ESP + 0x80],EDI
    m.w32((f.sp+0x00000080u), s.di);
  }
  L004291b8: { // 0x4291b8: 89742434 MOV dword ptr [ESP + 0x34],ESI
    m.w32((f.sp+0x00000034u), s.si);
  }
  L004291bc: { // 0x4291bc: 895c2428 MOV dword ptr [ESP + 0x28],EBX
    m.w32((f.sp+0x00000028u), s.bx);
  }
  L004291c0: { // 0x4291c0: 895c2420 MOV dword ptr [ESP + 0x20],EBX
    m.w32((f.sp+0x00000020u), s.bx);
  }
  L004291c4: { // 0x4291c4: 895c2424 MOV dword ptr [ESP + 0x24],EBX
    m.w32((f.sp+0x00000024u), s.bx);
  }
  L004291c8: { // 0x4291c8: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L004291cc: { // 0x4291cc: 8974242c MOV dword ptr [ESP + 0x2c],ESI
    m.w32((f.sp+0x0000002cu), s.si);
  }
  L004291d0: { // 0x4291d0: 89542470 MOV dword ptr [ESP + 0x70],EDX
    m.w32((f.sp+0x00000070u), s.dx);
  }
  L004291d4: { // 0x4291d4: e955020000 JMP 0x0042942e
    goto L0042942e;
  }
  L004291d9: { // 0x4291d9: 83f8fe CMP EAX,-0x2
    (void)integer::sub(s.ax,0xfffffffeu,32,flags);
  }
  L004291dc: { // 0x4291dc: 7511 JNZ 0x004291ef
    if(integer::condition("JNZ",flags)) goto L004291ef;
  }
  L004291de: { // 0x4291de: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L004291e2: { // 0x4291e2: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L004291e3: { // 0x4291e3: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  L004291e6: { // 0x4291e6: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L004291ea: { // 0x4291ea: e93f020000 JMP 0x0042942e
    goto L0042942e;
  }
  L004291ef: { // 0x4291ef: 83e007 AND EAX,0x7
    s.ax = integer::logical((s.ax)&(0x00000007u),32,flags);
  }
  L004291f2: { // 0x4291f2: 668b1c85a09d8300 MOV BX,word ptr [EAX*0x4 + 0x839da0]
    s.bx = with_ax(s.bx, m.r16(((s.ax * 0x00000004u)+0x00839da0u)));
  }
  L004291fa: { // 0x4291fa: 668b2c85a29d8300 MOV BP,word ptr [EAX*0x4 + 0x839da2]
    s.bp = (s.bp & 0xffff0000u) | ((m.r16(((s.ax * 0x00000004u)+0x00839da2u))) & 0xffffu);
  }
  L00429202: { // 0x429202: 668b0c85a09d8300 MOV CX,word ptr [EAX*0x4 + 0x839da0]
    s.cx = with_ax(s.cx, m.r16(((s.ax * 0x00000004u)+0x00839da0u)));
  }
  L0042920a: { // 0x42920a: 8d0485a09d8300 LEA EAX,[EAX*0x4 + 0x839da0]
    s.ax = ((s.ax * 0x00000004u)+0x00839da0u);
  }
  L00429211: { // 0x429211: 66034c2414 ADD CX,word ptr [ESP + 0x14]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((f.sp+0x00000014u)),16,flags));
  }
  L00429216: { // 0x429216: 66035c2418 ADD BX,word ptr [ESP + 0x18]
    s.bx = with_ax(s.bx, integer::add((s.bx & 0xffffu),m.r16((f.sp+0x00000018u)),16,flags));
  }
  L0042921b: { // 0x42921b: 668b4002 MOV AX,word ptr [EAX + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.ax+0x00000002u)));
  }
  L0042921f: { // 0x42921f: 66036c241a ADD BP,word ptr [ESP + 0x1a]
    s.bp = (s.bp & 0xffff0000u) | ((integer::add((s.bp & 0xffffu),m.r16((f.sp+0x0000001au)),16,flags)) & 0xffffu);
  }
  L00429224: { // 0x429224: 6603442416 ADD AX,word ptr [ESP + 0x16]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((f.sp+0x00000016u)),16,flags));
  }
  L00429229: { // 0x429229: 66894c2430 MOV word ptr [ESP + 0x30],CX
    m.w16((f.sp+0x00000030u), (s.cx & 0xffffu));
  }
  L0042922e: { // 0x42922e: 66895c2450 MOV word ptr [ESP + 0x50],BX
    m.w16((f.sp+0x00000050u), (s.bx & 0xffffu));
  }
  L00429233: { // 0x429233: 66896c2452 MOV word ptr [ESP + 0x52],BP
    m.w16((f.sp+0x00000052u), (s.bp & 0xffffu));
  }
  L00429238: { // 0x429238: 6689442432 MOV word ptr [ESP + 0x32],AX
    m.w16((f.sp+0x00000032u), (s.ax & 0xffffu));
  }
  L0042923d: { // 0x42923d: 0fbfc1 MOVSX EAX,CX
    s.ax = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L00429240: { // 0x429240: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00429241: { // 0x429241: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00429243: { // 0x429243: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L00429247: { // 0x429247: 33ca XOR ECX,EDX
    s.cx = integer::logical((s.cx)^(s.dx),32,flags);
  }
  L00429249: { // 0x429249: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L0042924b: { // 0x42924b: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L0042924d: { // 0x42924d: 0f8c31010000 JL 0x00429384
    if(integer::condition("JL",flags)) goto L00429384;
  }
  L00429253: { // 0x429253: 0fbf442432 MOVSX EAX,word ptr [ESP + 0x32]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000032u)),16));
  }
  L00429258: { // 0x429258: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00429259: { // 0x429259: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L0042925b: { // 0x42925b: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0042925d: { // 0x42925d: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L00429261: { // 0x429261: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00429263: { // 0x429263: 0f8c1b010000 JL 0x00429384
    if(integer::condition("JL",flags)) goto L00429384;
  }
  L00429269: { // 0x429269: 8b542430 MOV EDX,dword ptr [ESP + 0x30]
    s.dx = m.r32((f.sp+0x00000030u));
  }
  L0042926d: { // 0x42926d: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L00429271: { // 0x429271: 0fbfc5 MOVSX EAX,BP
    s.ax = std::uint32_t(integer::sign_extend((s.bp & 0xffffu),16));
  }
  L00429274: { // 0x429274: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L00429278: { // 0x429278: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L0042927c: { // 0x42927c: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0042927d: { // 0x42927d: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0042927f: { // 0x42927f: 0fbfc3 MOVSX EAX,BX
    s.ax = std::uint32_t(integer::sign_extend((s.bx & 0xffffu),16));
  }
  L00429282: { // 0x429282: 33ca XOR ECX,EDX
    s.cx = integer::logical((s.cx)^(s.dx),32,flags);
  }
  L00429284: { // 0x429284: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L00429286: { // 0x429286: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00429287: { // 0x429287: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L00429289: { // 0x429289: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0042928b: { // 0x42928b: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0042928d: { // 0x42928d: 7f02 JG 0x00429291
    if(integer::condition("JG",flags)) goto L00429291;
  }
  L0042928f: { // 0x42928f: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00429291: { // 0x429291: 8b54246c MOV EDX,dword ptr [ESP + 0x6c]
    s.dx = m.r32((f.sp+0x0000006cu));
  }
  L00429295: { // 0x429295: 83e207 AND EDX,0x7
    s.dx = integer::logical((s.dx)&(0x00000007u),32,flags);
  }
  L00429298: { // 0x429298: 668b0c95a09d8300 MOV CX,word ptr [EDX*0x4 + 0x839da0]
    s.cx = with_ax(s.cx, m.r16(((s.dx * 0x00000004u)+0x00839da0u)));
  }
  L004292a0: { // 0x4292a0: 8d1495a09d8300 LEA EDX,[EDX*0x4 + 0x839da0]
    s.dx = ((s.dx * 0x00000004u)+0x00839da0u);
  }
  L004292a7: { // 0x4292a7: 6603cf ADD CX,DI
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),(s.di & 0xffffu),16,flags));
  }
  L004292aa: { // 0x4292aa: 668b5202 MOV DX,word ptr [EDX + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.dx+0x00000002u)));
  }
  L004292ae: { // 0x4292ae: 66898c2488000000 MOV word ptr [ESP + 0x88],CX
    m.w16((f.sp+0x00000088u), (s.cx & 0xffffu));
  }
  L004292b6: { // 0x4292b6: 6603942482000000 ADD DX,word ptr [ESP + 0x82]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((f.sp+0x00000082u)),16,flags));
  }
  L004292be: { // 0x4292be: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L004292c2: { // 0x4292c2: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L004292c4: { // 0x4292c4: 668994248a000000 MOV word ptr [ESP + 0x8a],DX
    m.w16((f.sp+0x0000008au), (s.dx & 0xffffu));
  }
  L004292cc: { // 0x4292cc: 8b9c2488000000 MOV EBX,dword ptr [ESP + 0x88]
    s.bx = m.r32((f.sp+0x00000088u));
  }
  L004292d3: { // 0x4292d3: 8bfb MOV EDI,EBX
    s.di = s.bx;
  }
  L004292d5: { // 0x4292d5: 89bc2480000000 MOV dword ptr [ESP + 0x80],EDI
    m.w32((f.sp+0x00000080u), s.di);
  }
  L004292dc: { // 0x4292dc: 7d09 JGE 0x004292e7
    if(integer::condition("JGE",flags)) goto L004292e7;
  }
  L004292de: { // 0x4292de: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L004292e2: { // 0x4292e2: e984000000 JMP 0x0042936b
    goto L0042936b;
  }
  L004292e7: { // 0x4292e7: 8b542434 MOV EDX,dword ptr [ESP + 0x34]
    s.dx = m.r32((f.sp+0x00000034u));
  }
  L004292eb: { // 0x4292eb: 8b6c2460 MOV EBP,dword ptr [ESP + 0x60]
    s.bp = m.r32((f.sp+0x00000060u));
  }
  L004292ef: { // 0x4292ef: 8d442478 LEA EAX,[ESP + 0x78]
    s.ax = (f.sp+0x00000078u);
  }
  L004292f3: { // 0x4292f3: 8d4c2438 LEA ECX,[ESP + 0x38]
    s.cx = (f.sp+0x00000038u);
  }
  L004292f7: { // 0x4292f7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004292f8: { // 0x4292f8: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L004292fc: { // 0x4292fc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004292fd: { // 0x4292fd: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004292fe: { // 0x4292fe: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004292ff: { // 0x4292ff: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00429300: { // 0x429300: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00429302: { // 0x429302: 899c248c000000 MOV dword ptr [ESP + 0x8c],EBX
    m.w32((f.sp+0x0000008cu), s.bx);
  }
  L00429309: { // 0x429309: e862020000 CALL 0x00429570
    s.arithmetic_flags=flags; invoke(m,s,f,0x00429570u,4363022u); flags=s.arithmetic_flags;
  }
  L0042930e: { // 0x42930e: 8b442478 MOV EAX,dword ptr [ESP + 0x78]
    s.ax = m.r32((f.sp+0x00000078u));
  }
  L00429312: { // 0x429312: 8b8c248a000000 MOV ECX,dword ptr [ESP + 0x8a]
    s.cx = m.r32((f.sp+0x0000008au));
  }
  L00429319: { // 0x429319: 8b54247a MOV EDX,dword ptr [ESP + 0x7a]
    s.dx = m.r32((f.sp+0x0000007au));
  }
  L0042931d: { // 0x42931d: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L0042931f: { // 0x42931f: 8b442438 MOV EAX,dword ptr [ESP + 0x38]
    s.ax = m.r32((f.sp+0x00000038u));
  }
  L00429323: { // 0x429323: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L00429325: { // 0x429325: 66895c244c MOV word ptr [ESP + 0x4c],BX
    m.w16((f.sp+0x0000004cu), (s.bx & 0xffffu));
  }
  L0042932a: { // 0x42932a: 66894c244e MOV word ptr [ESP + 0x4e],CX
    m.w16((f.sp+0x0000004eu), (s.cx & 0xffffu));
  }
  L0042932f: { // 0x42932f: 8b54244c MOV EDX,dword ptr [ESP + 0x4c]
    s.dx = m.r32((f.sp+0x0000004cu));
  }
  L00429333: { // 0x429333: 8b4c2464 MOV ECX,dword ptr [ESP + 0x64]
    s.cx = m.r32((f.sp+0x00000064u));
  }
  L00429337: { // 0x429337: 8954246c MOV dword ptr [ESP + 0x6c],EDX
    m.w32((f.sp+0x0000006cu), s.dx);
  }
  L0042933b: { // 0x42933b: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0042933d: { // 0x42933d: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L00429340: { // 0x429340: 8b8c249c000000 MOV ECX,dword ptr [ESP + 0x9c]
    s.cx = m.r32((f.sp+0x0000009cu));
  }
  L00429347: { // 0x429347: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00429348: { // 0x429348: 8d542474 LEA EDX,[ESP + 0x74]
    s.dx = (f.sp+0x00000074u);
  }
  L0042934c: { // 0x42934c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0042934d: { // 0x42934d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0042934e: { // 0x42934e: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L00429350: { // 0x429350: 8d8c2488000000 LEA ECX,[ESP + 0x88]
    s.cx = (f.sp+0x00000088u);
  }
  L00429357: { // 0x429357: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L00429359: { // 0x429359: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0042935a: { // 0x42935a: 8b4c2430 MOV ECX,dword ptr [ESP + 0x30]
    s.cx = m.r32((f.sp+0x00000030u));
  }
  L0042935e: { // 0x42935e: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L0042935f: { // 0x42935f: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00429360: { // 0x429360: 8d1481 LEA EDX,[ECX + EAX*0x4]
    s.dx = (s.cx+(s.ax * 0x00000004u));
  }
  L00429363: { // 0x429363: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00429365: { // 0x429365: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00429366: { // 0x429366: e885030000 CALL 0x004296f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004296f0u,4363115u); flags=s.arithmetic_flags;
  }
  L0042936b: { // 0x42936b: 8b442450 MOV EAX,dword ptr [ESP + 0x50]
    s.ax = m.r32((f.sp+0x00000050u));
  }
  L0042936f: { // 0x42936f: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L00429370: { // 0x429370: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00429374: { // 0x429374: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00429378: { // 0x429378: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  L0042937b: { // 0x42937b: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0042937f: { // 0x42937f: e9a1000000 JMP 0x00429425
    goto L00429425;
  }
  L00429384: { // 0x429384: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00429386: { // 0x429386: 66394c2470 CMP word ptr [ESP + 0x70],CX
    (void)integer::sub(m.r16((f.sp+0x00000070u)),(s.cx & 0xffffu),16,flags);
  }
  L0042938b: { // 0x42938b: 752b JNZ 0x004293b8
    if(integer::condition("JNZ",flags)) goto L004293b8;
  }
  L0042938d: { // 0x42938d: 66394c2472 CMP word ptr [ESP + 0x72],CX
    (void)integer::sub(m.r16((f.sp+0x00000072u)),(s.cx & 0xffffu),16,flags);
  }
  L00429392: { // 0x429392: 7524 JNZ 0x004293b8
    if(integer::condition("JNZ",flags)) goto L004293b8;
  }
  L00429394: { // 0x429394: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L00429398: { // 0x429398: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L0042939c: { // 0x42939c: 66894c2454 MOV word ptr [ESP + 0x54],CX
    m.w16((f.sp+0x00000054u), (s.cx & 0xffffu));
  }
  L004293a1: { // 0x4293a1: 66894c2456 MOV word ptr [ESP + 0x56],CX
    m.w16((f.sp+0x00000056u), (s.cx & 0xffffu));
  }
  L004293a6: { // 0x4293a6: 8b4c2454 MOV ECX,dword ptr [ESP + 0x54]
    s.cx = m.r32((f.sp+0x00000054u));
  }
  L004293aa: { // 0x4293aa: 897c2470 MOV dword ptr [ESP + 0x70],EDI
    m.w32((f.sp+0x00000070u), s.di);
  }
  L004293ae: { // 0x4293ae: 8974242c MOV dword ptr [ESP + 0x2c],ESI
    m.w32((f.sp+0x0000002cu), s.si);
  }
  L004293b2: { // 0x4293b2: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L004293b6: { // 0x4293b6: eb6d JMP 0x00429425
    goto L00429425;
  }
  L004293b8: { // 0x4293b8: 8b54242c MOV EDX,dword ptr [ESP + 0x2c]
    s.dx = m.r32((f.sp+0x0000002cu));
  }
  L004293bc: { // 0x4293bc: 8b442472 MOV EAX,dword ptr [ESP + 0x72]
    s.ax = m.r32((f.sp+0x00000072u));
  }
  L004293c0: { // 0x4293c0: 8b5c2470 MOV EBX,dword ptr [ESP + 0x70]
    s.bx = m.r32((f.sp+0x00000070u));
  }
  L004293c4: { // 0x4293c4: 89542434 MOV dword ptr [ESP + 0x34],EDX
    m.w32((f.sp+0x00000034u), s.dx);
  }
  L004293c8: { // 0x4293c8: 8b942482000000 MOV EDX,dword ptr [ESP + 0x82]
    s.dx = m.r32((f.sp+0x00000082u));
  }
  L004293cf: { // 0x4293cf: 2bdf SUB EBX,EDI
    s.bx = integer::sub(s.bx,s.di,32,flags);
  }
  L004293d1: { // 0x4293d1: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004293d3: { // 0x4293d3: 66895c2458 MOV word ptr [ESP + 0x58],BX
    m.w16((f.sp+0x00000058u), (s.bx & 0xffffu));
  }
  L004293d8: { // 0x4293d8: 668944245a MOV word ptr [ESP + 0x5a],AX
    m.w16((f.sp+0x0000005au), (s.ax & 0xffffu));
  }
  L004293dd: { // 0x4293dd: 8b542458 MOV EDX,dword ptr [ESP + 0x58]
    s.dx = m.r32((f.sp+0x00000058u));
  }
  L004293e1: { // 0x4293e1: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L004293e4: { // 0x4293e4: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L004293e8: { // 0x4293e8: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L004293ec: { // 0x4293ec: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L004293f0: { // 0x4293f0: 66894c245c MOV word ptr [ESP + 0x5c],CX
    m.w16((f.sp+0x0000005cu), (s.cx & 0xffffu));
  }
  L004293f5: { // 0x4293f5: 66894c245e MOV word ptr [ESP + 0x5e],CX
    m.w16((f.sp+0x0000005eu), (s.cx & 0xffffu));
  }
  L004293fa: { // 0x4293fa: 8b4c245c MOV ECX,dword ptr [ESP + 0x5c]
    s.cx = m.r32((f.sp+0x0000005cu));
  }
  L004293fe: { // 0x4293fe: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004293ff: { // 0x4293ff: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L00429403: { // 0x429403: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00429405: { // 0x429405: 0fbfc3 MOVSX EAX,BX
    s.ax = std::uint32_t(integer::sign_extend((s.bx & 0xffffu),16));
  }
  L00429408: { // 0x429408: 33ca XOR ECX,EDX
    s.cx = integer::logical((s.cx)^(s.dx),32,flags);
  }
  L0042940a: { // 0x42940a: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L0042940c: { // 0x42940c: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0042940d: { // 0x42940d: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L0042940f: { // 0x42940f: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00429411: { // 0x429411: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00429413: { // 0x429413: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L00429417: { // 0x429417: 7f04 JG 0x0042941d
    if(integer::condition("JG",flags)) goto L0042941d;
  }
  L00429419: { // 0x429419: 894c2428 MOV dword ptr [ESP + 0x28],ECX
    m.w32((f.sp+0x00000028u), s.cx);
  }
  L0042941d: { // 0x42941d: 897c2470 MOV dword ptr [ESP + 0x70],EDI
    m.w32((f.sp+0x00000070u), s.di);
  }
  L00429421: { // 0x429421: 8974242c MOV dword ptr [ESP + 0x2c],ESI
    m.w32((f.sp+0x0000002cu), s.si);
  }
  L00429425: { // 0x429425: 8b8c2494000000 MOV ECX,dword ptr [ESP + 0x94]
    s.cx = m.r32((f.sp+0x00000094u));
  }
  L0042942c: { // 0x42942c: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0042942e: { // 0x42942e: 3b742468 CMP ESI,dword ptr [ESP + 0x68]
    (void)integer::sub(s.si,m.r32((f.sp+0x00000068u)),32,flags);
  }
  L00429432: { // 0x429432: 0f8cfefcffff JL 0x00429136
    if(integer::condition("JL",flags)) goto L00429136;
  }
  L00429438: { // 0x429438: 66395c2470 CMP word ptr [ESP + 0x70],BX
    (void)integer::sub(m.r16((f.sp+0x00000070u)),(s.bx & 0xffffu),16,flags);
  }
  L0042943d: { // 0x42943d: 750b JNZ 0x0042944a
    if(integer::condition("JNZ",flags)) goto L0042944a;
  }
  L0042943f: { // 0x42943f: 66395c2472 CMP word ptr [ESP + 0x72],BX
    (void)integer::sub(m.r16((f.sp+0x00000072u)),(s.bx & 0xffffu),16,flags);
  }
  L00429444: { // 0x429444: 0f84c0000000 JZ 0x0042950a
    if(integer::condition("JZ",flags)) goto L0042950a;
  }
  L0042944a: { // 0x42944a: 8b842482000000 MOV EAX,dword ptr [ESP + 0x82]
    s.ax = m.r32((f.sp+0x00000082u));
  }
  L00429451: { // 0x429451: 8b4c2472 MOV ECX,dword ptr [ESP + 0x72]
    s.cx = m.r32((f.sp+0x00000072u));
  }
  L00429455: { // 0x429455: 8b542470 MOV EDX,dword ptr [ESP + 0x70]
    s.dx = m.r32((f.sp+0x00000070u));
  }
  L00429459: { // 0x429459: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L0042945b: { // 0x42945b: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0042945e: { // 0x42945e: 8bef MOV EBP,EDI
    s.bp = s.di;
  }
  L00429460: { // 0x429460: 2bea SUB EBP,EDX
    s.bp = integer::sub(s.bp,s.dx,32,flags);
  }
  L00429462: { // 0x429462: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00429463: { // 0x429463: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00429465: { // 0x429465: 0fbfc5 MOVSX EAX,BP
    s.ax = std::uint32_t(integer::sign_extend((s.bp & 0xffffu),16));
  }
  L00429468: { // 0x429468: 33ca XOR ECX,EDX
    s.cx = integer::logical((s.cx)^(s.dx),32,flags);
  }
  L0042946a: { // 0x42946a: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L0042946c: { // 0x42946c: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0042946d: { // 0x42946d: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L0042946f: { // 0x42946f: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00429471: { // 0x429471: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00429473: { // 0x429473: 7f02 JG 0x00429477
    if(integer::condition("JG",flags)) goto L00429477;
  }
  L00429475: { // 0x429475: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00429477: { // 0x429477: 8b54242c MOV EDX,dword ptr [ESP + 0x2c]
    s.dx = m.r32((f.sp+0x0000002cu));
  }
  L0042947b: { // 0x42947b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0042947d: { // 0x42947d: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L0042947f: { // 0x42947f: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00429480: { // 0x429480: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00429482: { // 0x429482: 7e7f JLE 0x00429503
    if(integer::condition("JLE",flags)) goto L00429503;
  }
  L00429484: { // 0x429484: 8b6c2460 MOV EBP,dword ptr [ESP + 0x60]
    s.bp = m.r32((f.sp+0x00000060u));
  }
  L00429488: { // 0x429488: 8d442478 LEA EAX,[ESP + 0x78]
    s.ax = (f.sp+0x00000078u);
  }
  L0042948c: { // 0x42948c: 8d4c2438 LEA ECX,[ESP + 0x38]
    s.cx = (f.sp+0x00000038u);
  }
  L00429490: { // 0x429490: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00429491: { // 0x429491: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00429492: { // 0x429492: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L00429493: { // 0x429493: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00429494: { // 0x429494: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L00429498: { // 0x429498: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00429499: { // 0x429499: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0042949a: { // 0x42949a: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0042949c: { // 0x42949c: 89bc248c000000 MOV dword ptr [ESP + 0x8c],EDI
    m.w32((f.sp+0x0000008cu), s.di);
  }
  L004294a3: { // 0x4294a3: e8c8000000 CALL 0x00429570
    s.arithmetic_flags=flags; invoke(m,s,f,0x00429570u,4363432u); flags=s.arithmetic_flags;
  }
  L004294a8: { // 0x4294a8: 8b442478 MOV EAX,dword ptr [ESP + 0x78]
    s.ax = m.r32((f.sp+0x00000078u));
  }
  L004294ac: { // 0x4294ac: 8b54247a MOV EDX,dword ptr [ESP + 0x7a]
    s.dx = m.r32((f.sp+0x0000007au));
  }
  L004294b0: { // 0x4294b0: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L004294b2: { // 0x4294b2: 8b842482000000 MOV EAX,dword ptr [ESP + 0x82]
    s.ax = m.r32((f.sp+0x00000082u));
  }
  L004294b9: { // 0x4294b9: 8b4c2464 MOV ECX,dword ptr [ESP + 0x64]
    s.cx = m.r32((f.sp+0x00000064u));
  }
  L004294bd: { // 0x4294bd: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004294bf: { // 0x4294bf: 66897c2460 MOV word ptr [ESP + 0x60],DI
    m.w16((f.sp+0x00000060u), (s.di & 0xffffu));
  }
  L004294c4: { // 0x4294c4: 6689442462 MOV word ptr [ESP + 0x62],AX
    m.w16((f.sp+0x00000062u), (s.ax & 0xffffu));
  }
  L004294c9: { // 0x4294c9: 8b442460 MOV EAX,dword ptr [ESP + 0x60]
    s.ax = m.r32((f.sp+0x00000060u));
  }
  L004294cd: { // 0x4294cd: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L004294cf: { // 0x4294cf: 89442470 MOV dword ptr [ESP + 0x70],EAX
    m.w32((f.sp+0x00000070u), s.ax);
  }
  L004294d3: { // 0x4294d3: 8b44243c MOV EAX,dword ptr [ESP + 0x3c]
    s.ax = m.r32((f.sp+0x0000003cu));
  }
  L004294d7: { // 0x4294d7: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  L004294d9: { // 0x4294d9: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L004294dc: { // 0x4294dc: 8b8c249c000000 MOV ECX,dword ptr [ESP + 0x9c]
    s.cx = m.r32((f.sp+0x0000009cu));
  }
  L004294e3: { // 0x4294e3: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004294e4: { // 0x4294e4: 8d542474 LEA EDX,[ESP + 0x74]
    s.dx = (f.sp+0x00000074u);
  }
  L004294e8: { // 0x4294e8: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004294e9: { // 0x4294e9: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004294ea: { // 0x4294ea: 8b54242c MOV EDX,dword ptr [ESP + 0x2c]
    s.dx = m.r32((f.sp+0x0000002cu));
  }
  L004294ee: { // 0x4294ee: 8d8c2488000000 LEA ECX,[ESP + 0x88]
    s.cx = (f.sp+0x00000088u);
  }
  L004294f5: { // 0x4294f5: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L004294f6: { // 0x4294f6: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004294f7: { // 0x4294f7: 8d0482 LEA EAX,[EDX + EAX*0x4]
    s.ax = (s.dx+(s.ax * 0x00000004u));
  }
  L004294fa: { // 0x4294fa: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004294fb: { // 0x4294fb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004294fc: { // 0x4294fc: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L004294fe: { // 0x4294fe: e8ed010000 CALL 0x004296f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004296f0u,4363523u); flags=s.arithmetic_flags;
  }
  L00429503: { // 0x429503: 8b8c2494000000 MOV ECX,dword ptr [ESP + 0x94]
    s.cx = m.r32((f.sp+0x00000094u));
  }
  L0042950a: { // 0x42950a: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L0042950e: { // 0x42950e: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L00429510: { // 0x429510: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L00429512: { // 0x429512: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00429515: { // 0x429515: 7423 JZ 0x0042953a
    if(integer::condition("JZ",flags)) goto L0042953a;
  }
  L00429517: { // 0x429517: 8b6c2468 MOV EBP,dword ptr [ESP + 0x68]
    s.bp = m.r32((f.sp+0x00000068u));
  }
  L0042951b: { // 0x42951b: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L0042951d: { // 0x42951d: 3bf5 CMP ESI,EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  L0042951f: { // 0x42951f: 7d19 JGE 0x0042953a
    if(integer::condition("JGE",flags)) goto L0042953a;
  }
  L00429521: { // 0x429521: 83f8fe CMP EAX,-0x2
    (void)integer::sub(s.ax,0xfffffffeu,32,flags);
  }
  L00429524: { // 0x429524: 7408 JZ 0x0042952e
    if(integer::condition("JZ",flags)) goto L0042952e;
  }
  L00429526: { // 0x429526: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L00429528: { // 0x429528: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L00429529: { // 0x429529: 8907 MOV dword ptr [EDI],EAX
    m.w32((s.di), s.ax);
  }
  L0042952b: { // 0x42952b: 83c704 ADD EDI,0x4
    s.di = integer::add(s.di,0x00000004u,32,flags);
  }
  L0042952e: { // 0x42952e: 8b4204 MOV EAX,dword ptr [EDX + 0x4]
    s.ax = m.r32((s.dx+0x00000004u));
  }
  L00429531: { // 0x429531: 83c204 ADD EDX,0x4
    s.dx = integer::add(s.dx,0x00000004u,32,flags);
  }
  L00429534: { // 0x429534: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L00429535: { // 0x429535: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00429538: { // 0x429538: 75e3 JNZ 0x0042951d
    if(integer::condition("JNZ",flags)) goto L0042951d;
  }
  L0042953a: { // 0x42953a: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L0042953d: { // 0x42953d: 8bd3 MOV EDX,EBX
    s.dx = s.bx;
  }
  L0042953f: { // 0x42953f: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00429540: { // 0x429540: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L00429542: { // 0x429542: 7d19 JGE 0x0042955d
    if(integer::condition("JGE",flags)) goto L0042955d;
  }
  L00429544: { // 0x429544: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L00429548: { // 0x429548: 8d0498 LEA EAX,[EAX + EBX*0x4]
    s.ax = (s.ax+(s.bx * 0x00000004u));
  }
  L0042954b: { // 0x42954b: c700ffffffff MOV dword ptr [EAX],0xffffffff
    m.w32((s.ax), 0xffffffffu);
  }
  L00429551: { // 0x429551: 8b7108 MOV ESI,dword ptr [ECX + 0x8]
    s.si = m.r32((s.cx+0x00000008u));
  }
  L00429554: { // 0x429554: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L00429555: { // 0x429555: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  L00429558: { // 0x429558: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L00429559: { // 0x429559: 3bd6 CMP EDX,ESI
    (void)integer::sub(s.dx,s.si,32,flags);
  }
  L0042955b: { // 0x42955b: 7cee JL 0x0042954b
    if(integer::condition("JL",flags)) goto L0042954b;
  }
  L0042955d: { // 0x42955d: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L0042955e: { // 0x42955e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0042955f: { // 0x42955f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00429560: { // 0x429560: 895908 MOV dword ptr [ECX + 0x8],EBX
    m.w32((s.cx+0x00000008u), s.bx);
  }
  L00429563: { // 0x429563: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00429564: { // 0x429564: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00429565: { // 0x429565: 81c480000000 ADD ESP,0x80
    f.sp = integer::add(f.sp,0x00000080u,32,flags);
  }
  L0042956b: { // 0x42956b: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
