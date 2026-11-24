#include "recovered/recovery_b541_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b541 {
namespace {
void f_0022fde0(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void f_00186120(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_0007b480(Memory&,State&,Frame&,const Operations&);
void f_001851f0(Memory&,State&,Frame&,const Operations&);
void f_0001c300(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_0022fde0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0062fde0: { // 0x62fde0: 803900 CMP byte ptr [ECX],0x0
    (void)integer::sub(m.r8((s.cx)),0x00000000u,8,flags);
  }
  L0062fde3: { // 0x62fde3: 7403 JZ 0x0062fde8
    if(integer::condition("JZ",flags)) goto L0062fde8;
  }
  L0062fde5: { // 0x62fde5: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0062fde7: { // 0x62fde7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0062fde8: { // 0x62fde8: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L0062fdeb: { // 0x62fdeb: 8b5108 MOV EDX,dword ptr [ECX + 0x8]
    s.dx = m.r32((s.cx+0x00000008u));
  }
  L0062fdee: { // 0x62fdee: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0062fdef: { // 0x62fdef: 8b54910c MOV EDX,dword ptr [ECX + EDX*0x4 + 0xc]
    s.dx = m.r32((s.cx+(s.dx * 0x00000004u)+0x0000000cu));
  }
  L0062fdf3: { // 0x62fdf3: 8b74810c MOV ESI,dword ptr [ECX + EAX*0x4 + 0xc]
    s.si = m.r32((s.cx+(s.ax * 0x00000004u)+0x0000000cu));
  }
  L0062fdf7: { // 0x62fdf7: 8d44810c LEA EAX,[ECX + EAX*0x4 + 0xc]
    s.ax = (s.cx+(s.ax * 0x00000004u)+0x0000000cu);
  }
  L0062fdfb: { // 0x62fdfb: 33f2 XOR ESI,EDX
    s.si = integer::logical((s.si)^(s.dx),32,flags);
  }
  L0062fdfd: { // 0x62fdfd: 8930 MOV dword ptr [EAX],ESI
    m.w32((s.ax), s.si);
  }
  L0062fdff: { // 0x62fdff: 8b5104 MOV EDX,dword ptr [ECX + 0x4]
    s.dx = m.r32((s.cx+0x00000004u));
  }
  L0062fe02: { // 0x62fe02: 8b7108 MOV ESI,dword ptr [ECX + 0x8]
    s.si = m.r32((s.cx+0x00000008u));
  }
  L0062fe05: { // 0x62fe05: 8b44910c MOV EAX,dword ptr [ECX + EDX*0x4 + 0xc]
    s.ax = m.r32((s.cx+(s.dx * 0x00000004u)+0x0000000cu));
  }
  L0062fe09: { // 0x62fe09: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L0062fe0a: { // 0x62fe0a: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0062fe0b: { // 0x62fe0b: 81fafa000000 CMP EDX,0xfa
    (void)integer::sub(s.dx,0x000000fau,32,flags);
  }
  L0062fe11: { // 0x62fe11: 895104 MOV dword ptr [ECX + 0x4],EDX
    m.w32((s.cx+0x00000004u), s.dx);
  }
  L0062fe14: { // 0x62fe14: 897108 MOV dword ptr [ECX + 0x8],ESI
    m.w32((s.cx+0x00000008u), s.si);
  }
  L0062fe17: { // 0x62fe17: 7c07 JL 0x0062fe20
    if(integer::condition("JL",flags)) goto L0062fe20;
  }
  L0062fe19: { // 0x62fe19: c7410400000000 MOV dword ptr [ECX + 0x4],0x0
    m.w32((s.cx+0x00000004u), 0x00000000u);
  }
  L0062fe20: { // 0x62fe20: 81fefa000000 CMP ESI,0xfa
    (void)integer::sub(s.si,0x000000fau,32,flags);
  }
  L0062fe26: { // 0x62fe26: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0062fe27: { // 0x62fe27: 7c07 JL 0x0062fe30
    if(integer::condition("JL",flags)) goto L0062fe30;
  }
  L0062fe29: { // 0x62fe29: c7410800000000 MOV dword ptr [ECX + 0x8],0x0
    m.w32((s.cx+0x00000008u), 0x00000000u);
  }
  L0062fe30: { // 0x62fe30: c3 RET
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
void f_00186120(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00586120: { // 0x586120: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L00586123: { // 0x586123: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00586124: { // 0x586124: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00586125: { // 0x586125: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L00586127: { // 0x586127: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00586128: { // 0x586128: 8b0d3486a500 MOV ECX,dword ptr [0x00a58634]
    s.cx = m.r32((0x00a58634u));
  }
  L0058612e: { // 0x58612e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0058612f: { // 0x58612f: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L00586132: { // 0x586132: 8b5d04 MOV EBX,dword ptr [EBP + 0x4]
    s.bx = m.r32((s.bp+0x00000004u));
  }
  L00586135: { // 0x586135: 0fbff0 MOVSX ESI,AX
    s.si = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00586138: { // 0x586138: 0fbfd3 MOVSX EDX,BX
    s.dx = std::uint32_t(integer::sign_extend((s.bx & 0xffffu),16));
  }
  L0058613b: { // 0x58613b: 895c2410 MOV dword ptr [ESP + 0x10],EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
  L0058613f: { // 0x58613f: 8d3c32 LEA EDI,[EDX + ESI*0x1]
    s.di = (s.dx+(s.si * 0x00000001u));
  }
  L00586142: { // 0x586142: 3bf9 CMP EDI,ECX
    (void)integer::sub(s.di,s.cx,32,flags);
  }
  L00586144: { // 0x586144: 897c2414 MOV dword ptr [ESP + 0x14],EDI
    m.w32((f.sp+0x00000014u), s.di);
  }
  L00586148: { // 0x586148: 0f8e85010000 JLE 0x005862d3
    if(integer::condition("JLE",flags)) goto L005862d3;
  }
  L0058614e: { // 0x58614e: 8bfe MOV EDI,ESI
    s.di = s.si;
  }
  L00586150: { // 0x586150: 2bfa SUB EDI,EDX
    s.di = integer::sub(s.di,s.dx,32,flags);
  }
  L00586152: { // 0x586152: 3bf9 CMP EDI,ECX
    (void)integer::sub(s.di,s.cx,32,flags);
  }
  L00586154: { // 0x586154: 0f8d79010000 JGE 0x005862d3
    if(integer::condition("JGE",flags)) goto L005862d3;
  }
  L0058615a: { // 0x58615a: 2bd6 SUB EDX,ESI
    s.dx = integer::sub(s.dx,s.si,32,flags);
  }
  L0058615c: { // 0x58615c: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L0058615e: { // 0x58615e: 0f8d6f010000 JGE 0x005862d3
    if(integer::condition("JGE",flags)) goto L005862d3;
  }
  L00586164: { // 0x586164: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L00586168: { // 0x586168: 8b353886a500 MOV ESI,dword ptr [0x00a58638]
    s.si = m.r32((0x00a58638u));
  }
  L0058616e: { // 0x58616e: 3bd6 CMP EDX,ESI
    (void)integer::sub(s.dx,s.si,32,flags);
  }
  L00586170: { // 0x586170: 0f8f5d010000 JG 0x005862d3
    if(integer::condition("JG",flags)) goto L005862d3;
  }
  L00586176: { // 0x586176: 8b5508 MOV EDX,dword ptr [EBP + 0x8]
    s.dx = m.r32((s.bp+0x00000008u));
  }
  L00586179: { // 0x586179: 8d7402ff LEA ESI,[EDX + EAX*0x1 + -0x1]
    s.si = (s.dx+(s.ax * 0x00000001u)-0x00000001u);
  }
  L0058617d: { // 0x58617d: 0fbffe MOVSX EDI,SI
    s.di = std::uint32_t(integer::sign_extend((s.si & 0xffffu),16));
  }
  L00586180: { // 0x586180: 0fbff3 MOVSX ESI,BX
    s.si = std::uint32_t(integer::sign_extend((s.bx & 0xffffu),16));
  }
  L00586183: { // 0x586183: 8d1c3e LEA EBX,[ESI + EDI*0x1]
    s.bx = (s.si+(s.di * 0x00000001u));
  }
  L00586186: { // 0x586186: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L00586188: { // 0x586188: 895c2414 MOV dword ptr [ESP + 0x14],EBX
    m.w32((f.sp+0x00000014u), s.bx);
  }
  L0058618c: { // 0x58618c: 0f8e41010000 JLE 0x005862d3
    if(integer::condition("JLE",flags)) goto L005862d3;
  }
  L00586192: { // 0x586192: 8bdf MOV EBX,EDI
    s.bx = s.di;
  }
  L00586194: { // 0x586194: 2bde SUB EBX,ESI
    s.bx = integer::sub(s.bx,s.si,32,flags);
  }
  L00586196: { // 0x586196: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L00586198: { // 0x586198: 0f8d35010000 JGE 0x005862d3
    if(integer::condition("JGE",flags)) goto L005862d3;
  }
  L0058619e: { // 0x58619e: 2bf7 SUB ESI,EDI
    s.si = integer::sub(s.si,s.di,32,flags);
  }
  L005861a0: { // 0x5861a0: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L005861a2: { // 0x5861a2: 0f8d2b010000 JGE 0x005862d3
    if(integer::condition("JGE",flags)) goto L005862d3;
  }
  L005861a8: { // 0x5861a8: 8b353886a500 MOV ESI,dword ptr [0x00a58638]
    s.si = m.r32((0x00a58638u));
  }
  L005861ae: { // 0x5861ae: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L005861b2: { // 0x5861b2: 3bfe CMP EDI,ESI
    (void)integer::sub(s.di,s.si,32,flags);
  }
  L005861b4: { // 0x5861b4: 0f8f19010000 JG 0x005862d3
    if(integer::condition("JG",flags)) goto L005862d3;
  }
  L005861ba: { // 0x5861ba: 8b750c MOV ESI,dword ptr [EBP + 0xc]
    s.si = m.r32((s.bp+0x0000000cu));
  }
  L005861bd: { // 0x5861bd: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L005861c1: { // 0x5861c1: 8d743eff LEA ESI,[ESI + EDI*0x1 + -0x1]
    s.si = (s.si+(s.di * 0x00000001u)-0x00000001u);
  }
  L005861c5: { // 0x5861c5: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L005861c9: { // 0x5861c9: 0fbff8 MOVSX EDI,AX
    s.di = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L005861cc: { // 0x5861cc: 0fbff6 MOVSX ESI,SI
    s.si = std::uint32_t(integer::sign_extend((s.si & 0xffffu),16));
  }
  L005861cf: { // 0x5861cf: 8d1c3e LEA EBX,[ESI + EDI*0x1]
    s.bx = (s.si+(s.di * 0x00000001u));
  }
  L005861d2: { // 0x5861d2: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L005861d4: { // 0x5861d4: 895c2414 MOV dword ptr [ESP + 0x14],EBX
    m.w32((f.sp+0x00000014u), s.bx);
  }
  L005861d8: { // 0x5861d8: 0f8ef5000000 JLE 0x005862d3
    if(integer::condition("JLE",flags)) goto L005862d3;
  }
  L005861de: { // 0x5861de: 8bdf MOV EBX,EDI
    s.bx = s.di;
  }
  L005861e0: { // 0x5861e0: 2bde SUB EBX,ESI
    s.bx = integer::sub(s.bx,s.si,32,flags);
  }
  L005861e2: { // 0x5861e2: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L005861e4: { // 0x5861e4: 0f8de9000000 JGE 0x005862d3
    if(integer::condition("JGE",flags)) goto L005862d3;
  }
  L005861ea: { // 0x5861ea: 2bf7 SUB ESI,EDI
    s.si = integer::sub(s.si,s.di,32,flags);
  }
  L005861ec: { // 0x5861ec: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L005861ee: { // 0x5861ee: 0f8ddf000000 JGE 0x005862d3
    if(integer::condition("JGE",flags)) goto L005862d3;
  }
  L005861f4: { // 0x5861f4: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L005861f8: { // 0x5861f8: 8b3d3886a500 MOV EDI,dword ptr [0x00a58638]
    s.di = m.r32((0x00a58638u));
  }
  L005861fe: { // 0x5861fe: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  L00586200: { // 0x586200: 0f8fcd000000 JG 0x005862d3
    if(integer::condition("JG",flags)) goto L005862d3;
  }
  L00586206: { // 0x586206: 8d7402ff LEA ESI,[EDX + EAX*0x1 + -0x1]
    s.si = (s.dx+(s.ax * 0x00000001u)-0x00000001u);
  }
  L0058620a: { // 0x58620a: 0fbffe MOVSX EDI,SI
    s.di = std::uint32_t(integer::sign_extend((s.si & 0xffffu),16));
  }
  L0058620d: { // 0x58620d: 0fbf742418 MOVSX ESI,word ptr [ESP + 0x18]
    s.si = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000018u)),16));
  }
  L00586212: { // 0x586212: 8d1c3e LEA EBX,[ESI + EDI*0x1]
    s.bx = (s.si+(s.di * 0x00000001u));
  }
  L00586215: { // 0x586215: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L00586217: { // 0x586217: 895c2418 MOV dword ptr [ESP + 0x18],EBX
    m.w32((f.sp+0x00000018u), s.bx);
  }
  L0058621b: { // 0x58621b: 0f8eb2000000 JLE 0x005862d3
    if(integer::condition("JLE",flags)) goto L005862d3;
  }
  L00586221: { // 0x586221: 8bdf MOV EBX,EDI
    s.bx = s.di;
  }
  L00586223: { // 0x586223: 2bde SUB EBX,ESI
    s.bx = integer::sub(s.bx,s.si,32,flags);
  }
  L00586225: { // 0x586225: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L00586227: { // 0x586227: 0f8da6000000 JGE 0x005862d3
    if(integer::condition("JGE",flags)) goto L005862d3;
  }
  L0058622d: { // 0x58622d: 2bf7 SUB ESI,EDI
    s.si = integer::sub(s.si,s.di,32,flags);
  }
  L0058622f: { // 0x58622f: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L00586231: { // 0x586231: 0f8d9c000000 JGE 0x005862d3
    if(integer::condition("JGE",flags)) goto L005862d3;
  }
  L00586237: { // 0x586237: 8b0d3886a500 MOV ECX,dword ptr [0x00a58638]
    s.cx = m.r32((0x00a58638u));
  }
  L0058623d: { // 0x58623d: 8b742418 MOV ESI,dword ptr [ESP + 0x18]
    s.si = m.r32((f.sp+0x00000018u));
  }
  L00586241: { // 0x586241: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L00586243: { // 0x586243: 0f8f8a000000 JG 0x005862d3
    if(integer::condition("JG",flags)) goto L005862d3;
  }
  L00586249: { // 0x586249: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L0058624d: { // 0x58624d: 8b750c MOV ESI,dword ptr [EBP + 0xc]
    s.si = m.r32((s.bp+0x0000000cu));
  }
  L00586250: { // 0x586250: 03f1 ADD ESI,ECX
    s.si = integer::add(s.si,s.cx,32,flags);
  }
  L00586252: { // 0x586252: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L00586256: { // 0x586256: 3bce CMP ECX,ESI
    (void)integer::sub(s.cx,s.si,32,flags);
  }
  L00586258: { // 0x586258: 7d6f JGE 0x005862c9
    if(integer::condition("JGE",flags)) goto L005862c9;
  }
  L0058625a: { // 0x58625a: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0058625c: { // 0x58625c: 8d3402 LEA ESI,[EDX + EAX*0x1]
    s.si = (s.dx+(s.ax * 0x00000001u));
  }
  L0058625f: { // 0x58625f: 3bfe CMP EDI,ESI
    (void)integer::sub(s.di,s.si,32,flags);
  }
  L00586261: { // 0x586261: 7d55 JGE 0x005862b8
    if(integer::condition("JGE",flags)) goto L005862b8;
  }
  L00586263: { // 0x586263: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  L00586267: { // 0x586267: 66894c2416 MOV word ptr [ESP + 0x16],CX
    m.w16((f.sp+0x00000016u), (s.cx & 0xffffu));
  }
  L0058626c: { // 0x58626c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0058626d: { // 0x58626d: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00586272: { // 0x586272: 66897c2418 MOV word ptr [ESP + 0x18],DI
    m.w16((f.sp+0x00000018u), (s.di & 0xffffu));
  }
  L00586277: { // 0x586277: e884f2fbff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5792380u); flags=s.arithmetic_flags;
  }
  L0058627c: { // 0x58627c: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0058627e: { // 0x58627e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00586280: { // 0x586280: 8b5e38 MOV EBX,dword ptr [ESI + 0x38]
    s.bx = m.r32((s.si+0x00000038u));
  }
  L00586283: { // 0x586283: e8f851efff CALL 0x0047b480
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b480u,5792392u); flags=s.arithmetic_flags;
  }
  L00586288: { // 0x586288: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0058628a: { // 0x58628a: 7510 JNZ 0x0058629c
    if(integer::condition("JNZ",flags)) goto L0058629c;
  }
  L0058628c: { // 0x58628c: a12caba300 MOV EAX,[0x00a3ab2c]
    s.ax = m.r32((0x00a3ab2cu));
  }
  L00586291: { // 0x586291: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L00586293: { // 0x586293: 7c3e JL 0x005862d3
    if(integer::condition("JL",flags)) goto L005862d3;
  }
  L00586295: { // 0x586295: 83c007 ADD EAX,0x7
    s.ax = integer::add(s.ax,0x00000007u,32,flags);
  }
  L00586298: { // 0x586298: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L0058629a: { // 0x58629a: 7f37 JG 0x005862d3
    if(integer::condition("JG",flags)) goto L005862d3;
  }
  L0058629c: { // 0x58629c: 8b86e4000000 MOV EAX,dword ptr [ESI + 0xe4]
    s.ax = m.r32((s.si+0x000000e4u));
  }
  L005862a2: { // 0x5862a2: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005862a4: { // 0x5862a4: 752d JNZ 0x005862d3
    if(integer::condition("JNZ",flags)) goto L005862d3;
  }
  L005862a6: { // 0x5862a6: 8b5508 MOV EDX,dword ptr [EBP + 0x8]
    s.dx = m.r32((s.bp+0x00000008u));
  }
  L005862a9: { // 0x5862a9: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L005862ac: { // 0x5862ac: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L005862ad: { // 0x5862ad: 8d0c02 LEA ECX,[EDX + EAX*0x1]
    s.cx = (s.dx+(s.ax * 0x00000001u));
  }
  L005862b0: { // 0x5862b0: 3bf9 CMP EDI,ECX
    (void)integer::sub(s.di,s.cx,32,flags);
  }
  L005862b2: { // 0x5862b2: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L005862b6: { // 0x5862b6: 7cab JL 0x00586263
    if(integer::condition("JL",flags)) goto L00586263;
  }
  L005862b8: { // 0x5862b8: 8b7504 MOV ESI,dword ptr [EBP + 0x4]
    s.si = m.r32((s.bp+0x00000004u));
  }
  L005862bb: { // 0x5862bb: 8b5d0c MOV EBX,dword ptr [EBP + 0xc]
    s.bx = m.r32((s.bp+0x0000000cu));
  }
  L005862be: { // 0x5862be: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L005862bf: { // 0x5862bf: 03f3 ADD ESI,EBX
    s.si = integer::add(s.si,s.bx,32,flags);
  }
  L005862c1: { // 0x5862c1: 3bce CMP ECX,ESI
    (void)integer::sub(s.cx,s.si,32,flags);
  }
  L005862c3: { // 0x5862c3: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L005862c7: { // 0x5862c7: 7c91 JL 0x0058625a
    if(integer::condition("JL",flags)) goto L0058625a;
  }
  L005862c9: { // 0x5862c9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005862ca: { // 0x5862ca: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005862cb: { // 0x5862cb: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005862cc: { // 0x5862cc: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L005862ce: { // 0x5862ce: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005862cf: { // 0x5862cf: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L005862d2: { // 0x5862d2: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L005862d3: { // 0x5862d3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005862d4: { // 0x5862d4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005862d5: { // 0x5862d5: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005862d6: { // 0x5862d6: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L005862d8: { // 0x5862d8: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005862d9: { // 0x5862d9: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L005862dc: { // 0x5862dc: c3 RET
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
void f_0007b480(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0047b480: { // 0x47b480: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  L0047b483: { // 0x47b483: 8b0d185da500 MOV ECX,dword ptr [0x00a55d18]
    s.cx = m.r32((0x00a55d18u));
  }
  L0047b489: { // 0x47b489: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0047b48b: { // 0x47b48b: 7c0a JL 0x0047b497
    if(integer::condition("JL",flags)) goto L0047b497;
  }
  L0047b48d: { // 0x47b48d: 83c110 ADD ECX,0x10
    s.cx = integer::add(s.cx,0x00000010u,32,flags);
  }
  L0047b490: { // 0x47b490: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0047b492: { // 0x47b492: 7d03 JGE 0x0047b497
    if(integer::condition("JGE",flags)) goto L0047b497;
  }
  L0047b494: { // 0x47b494: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047b496: { // 0x47b496: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b497: { // 0x47b497: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0047b499: { // 0x47b499: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_001851f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005851f0: { // 0x5851f0: 83ec14 SUB ESP,0x14
    f.sp = integer::sub(f.sp,0x00000014u,32,flags);
  }
  L005851f3: { // 0x5851f3: a11489a200 MOV EAX,[0x00a28914]
    s.ax = m.r32((0x00a28914u));
  }
  L005851f8: { // 0x5851f8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005851f9: { // 0x5851f9: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005851fa: { // 0x5851fa: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L005851fe: { // 0x5851fe: 8b2c88 MOV EBP,dword ptr [EAX + ECX*0x4]
    s.bp = m.r32((s.ax+(s.cx * 0x00000004u)));
  }
  L00585201: { // 0x585201: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00585203: { // 0x585203: 8b5500 MOV EDX,dword ptr [EBP]
    s.dx = m.r32((s.bp));
  }
  L00585206: { // 0x585206: ff929c000000 CALL dword ptr [EDX + 0x9c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000009cu)),5788172u); flags=s.arithmetic_flags;
  }
  L0058520c: { // 0x58520c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0058520e: { // 0x58520e: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00585212: { // 0x585212: 0f8436010000 JZ 0x0058534e
    if(integer::condition("JZ",flags)) goto L0058534e;
  }
  L00585218: { // 0x585218: 8b85b8020000 MOV EAX,dword ptr [EBP + 0x2b8]
    s.ax = m.r32((s.bp+0x000002b8u));
  }
  L0058521e: { // 0x58521e: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00585220: { // 0x585220: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00585222: { // 0x585222: 895c240c MOV dword ptr [ESP + 0xc],EBX
    m.w32((f.sp+0x0000000cu), s.bx);
  }
  L00585226: { // 0x585226: 0f8e22010000 JLE 0x0058534e
    if(integer::condition("JLE",flags)) goto L0058534e;
  }
  L0058522c: { // 0x58522c: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0058522d: { // 0x58522d: 8b353486a500 MOV ESI,dword ptr [0x00a58634]
    s.si = m.r32((0x00a58634u));
  }
  L00585233: { // 0x585233: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00585234: { // 0x585234: 8b85b4020000 MOV EAX,dword ptr [EBP + 0x2b4]
    s.ax = m.r32((s.bp+0x000002b4u));
  }
  L0058523a: { // 0x58523a: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0058523c: { // 0x58523c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0058523e: { // 0x58523e: 0f8ef5000000 JLE 0x00585339
    if(integer::condition("JLE",flags)) goto L00585339;
  }
  L00585244: { // 0x585244: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L00585248: { // 0x585248: 668bcb MOV CX,BX
    s.cx = with_ax(s.cx, (s.bx & 0xffffu));
  }
  L0058524b: { // 0x58524b: 668b02 MOV AX,word ptr [EDX]
    s.ax = with_ax(s.ax, m.r16((s.dx)));
  }
  L0058524e: { // 0x58524e: 66034a02 ADD CX,word ptr [EDX + 0x2]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((s.dx+0x00000002u)),16,flags));
  }
  L00585252: { // 0x585252: 6603c7 ADD AX,DI
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),(s.di & 0xffffu),16,flags));
  }
  L00585255: { // 0x585255: 6689442418 MOV word ptr [ESP + 0x18],AX
    m.w16((f.sp+0x00000018u), (s.ax & 0xffffu));
  }
  L0058525a: { // 0x58525a: 66894c241a MOV word ptr [ESP + 0x1a],CX
    m.w16((f.sp+0x0000001au), (s.cx & 0xffffu));
  }
  L0058525f: { // 0x58525f: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L00585263: { // 0x585263: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L00585267: { // 0x585267: 0fbfd0 MOVSX EDX,AX
    s.dx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0058526a: { // 0x58526a: 0fbfc1 MOVSX EAX,CX
    s.ax = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L0058526d: { // 0x58526d: 8d0c10 LEA ECX,[EAX + EDX*0x1]
    s.cx = (s.ax+(s.dx * 0x00000001u));
  }
  L00585270: { // 0x585270: 3bce CMP ECX,ESI
    (void)integer::sub(s.cx,s.si,32,flags);
  }
  L00585272: { // 0x585272: 0f8eb2000000 JLE 0x0058532a
    if(integer::condition("JLE",flags)) goto L0058532a;
  }
  L00585278: { // 0x585278: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  L0058527a: { // 0x58527a: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L0058527c: { // 0x58527c: 3bde CMP EBX,ESI
    (void)integer::sub(s.bx,s.si,32,flags);
  }
  L0058527e: { // 0x58527e: 0f8da2000000 JGE 0x00585326
    if(integer::condition("JGE",flags)) goto L00585326;
  }
  L00585284: { // 0x585284: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00585286: { // 0x585286: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L00585288: { // 0x585288: 0f8d98000000 JGE 0x00585326
    if(integer::condition("JGE",flags)) goto L00585326;
  }
  L0058528e: { // 0x58528e: 3b0d3886a500 CMP ECX,dword ptr [0x00a58638]
    (void)integer::sub(s.cx,m.r32((0x00a58638u)),32,flags);
  }
  L00585294: { // 0x585294: 0f8f8c000000 JG 0x00585326
    if(integer::condition("JG",flags)) goto L00585326;
  }
  L0058529a: { // 0x58529a: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L0058529e: { // 0x58529e: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L005852a3: { // 0x5852a3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005852a4: { // 0x5852a4: e85702fcff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5788329u); flags=s.arithmetic_flags;
  }
  L005852a9: { // 0x5852a9: 8b8db4020000 MOV ECX,dword ptr [EBP + 0x2b4]
    s.cx = m.r32((s.bp+0x000002b4u));
  }
  L005852af: { // 0x5852af: 8b5c2414 MOV EBX,dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  L005852b3: { // 0x5852b3: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L005852b7: { // 0x5852b7: 0fafcb IMUL ECX,EBX
    s.cx = integer::imul(s.cx,s.bx,32,flags);
  }
  L005852ba: { // 0x5852ba: 03cf ADD ECX,EDI
    s.cx = integer::add(s.cx,s.di,32,flags);
  }
  L005852bc: { // 0x5852bc: 8b748a10 MOV ESI,dword ptr [EDX + ECX*0x4 + 0x10]
    s.si = m.r32((s.dx+(s.cx * 0x00000004u)+0x00000010u));
  }
  L005852c0: { // 0x5852c0: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L005852c2: { // 0x5852c2: 745a JZ 0x0058531e
    if(integer::condition("JZ",flags)) goto L0058531e;
  }
  L005852c4: { // 0x5852c4: 8b9564020000 MOV EDX,dword ptr [EBP + 0x264]
    s.dx = m.r32((s.bp+0x00000264u));
  }
  L005852ca: { // 0x5852ca: 88881a010000 MOV byte ptr [EAX + 0x11a],CL
    m.w8((s.ax+0x0000011au), (s.cx & 0xffu));
  }
  L005852d0: { // 0x5852d0: 8b4c242c MOV ECX,dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L005852d4: { // 0x5852d4: 895038 MOV dword ptr [EAX + 0x38],EDX
    m.w32((s.ax+0x00000038u), s.dx);
  }
  L005852d7: { // 0x5852d7: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  L005852da: { // 0x5852da: 740e JZ 0x005852ea
    if(integer::condition("JZ",flags)) goto L005852ea;
  }
  L005852dc: { // 0x5852dc: 8a5628 MOV DL,byte ptr [ESI + 0x28]
    s.dx = with_al(s.dx, m.r8((s.si+0x00000028u)));
  }
  L005852df: { // 0x5852df: 02d1 ADD DL,CL
    s.dx = with_al(s.dx, integer::add((s.dx & 0xffu),(s.cx & 0xffu),8,flags));
  }
  L005852e1: { // 0x5852e1: 80ea04 SUB DL,0x4
    s.dx = with_al(s.dx, integer::sub((s.dx & 0xffu),0x00000004u,8,flags));
  }
  L005852e4: { // 0x5852e4: 88901b010000 MOV byte ptr [EAX + 0x11b],DL
    m.w8((s.ax+0x0000011bu), (s.dx & 0xffu));
  }
  L005852ea: { // 0x5852ea: 8a4e2a MOV CL,byte ptr [ESI + 0x2a]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000002au)));
  }
  L005852ed: { // 0x5852ed: 88881c010000 MOV byte ptr [EAX + 0x11c],CL
    m.w8((s.ax+0x0000011cu), (s.cx & 0xffu));
  }
  L005852f3: { // 0x5852f3: 8b0d3c86a500 MOV ECX,dword ptr [0x00a5863c]
    s.cx = m.r32((0x00a5863cu));
  }
  L005852f9: { // 0x5852f9: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005852fb: { // 0x5852fb: 7421 JZ 0x0058531e
    if(integer::condition("JZ",flags)) goto L0058531e;
  }
  L005852fd: { // 0x5852fd: 0fbf442412 MOVSX EAX,word ptr [ESP + 0x12]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000012u)),16));
  }
  L00585302: { // 0x585302: 0faf054c6b8300 IMUL EAX,dword ptr [0x00836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  L00585309: { // 0x585309: 0fbf542410 MOVSX EDX,word ptr [ESP + 0x10]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000010u)),16));
  }
  L0058530e: { // 0x58530e: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00585310: { // 0x585310: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L00585314: { // 0x585314: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L00585317: { // 0x585317: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L0058531a: { // 0x58531a: 89540838 MOV dword ptr [EAX + ECX*0x1 + 0x38],EDX
    m.w32((s.ax+(s.cx * 0x00000001u)+0x00000038u), s.dx);
  }
  L0058531e: { // 0x58531e: 8b353486a500 MOV ESI,dword ptr [0x00a58634]
    s.si = m.r32((0x00a58634u));
  }
  L00585324: { // 0x585324: eb04 JMP 0x0058532a
    goto L0058532a;
  }
  L00585326: { // 0x585326: 8b5c2414 MOV EBX,dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  L0058532a: { // 0x58532a: 8b85b4020000 MOV EAX,dword ptr [EBP + 0x2b4]
    s.ax = m.r32((s.bp+0x000002b4u));
  }
  L00585330: { // 0x585330: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L00585331: { // 0x585331: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L00585333: { // 0x585333: 0f8c0bffffff JL 0x00585244
    if(integer::condition("JL",flags)) goto L00585244;
  }
  L00585339: { // 0x585339: 8b85b8020000 MOV EAX,dword ptr [EBP + 0x2b8]
    s.ax = m.r32((s.bp+0x000002b8u));
  }
  L0058533f: { // 0x58533f: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L00585340: { // 0x585340: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L00585342: { // 0x585342: 895c2414 MOV dword ptr [ESP + 0x14],EBX
    m.w32((f.sp+0x00000014u), s.bx);
  }
  L00585346: { // 0x585346: 0f8ce8feffff JL 0x00585234
    if(integer::condition("JL",flags)) goto L00585234;
  }
  L0058534c: { // 0x58534c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0058534d: { // 0x58534d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0058534e: { // 0x58534e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0058534f: { // 0x58534f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00585350: { // 0x585350: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L00585353: { // 0x585353: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_0001c300(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0041c300: { // 0x41c300: 8b81a4000000 MOV EAX,dword ptr [ECX + 0xa4]
    s.ax = m.r32((s.cx+0x000000a4u));
  }
  L0041c306: { // 0x41c306: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 6487520u:f_0022fde0(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
case 5792032u:f_00186120(m,s,child,{});break;
case 5526784u:f_00145500(m,s,child,{});break;
case 4699264u:f_0007b480(m,s,child,{});break;
case 5788144u:f_001851f0(m,s,child,{});break;
case 4309760u:f_0001c300(m,s,child,{});break;
default:throw std::domain_error("recovery541 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00585eb0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00585eb0: { // 0x585eb0: 81ec94000000 SUB ESP,0x94
    f.sp = integer::sub(f.sp,0x00000094u,32,flags);
  }
  L00585eb6: { // 0x585eb6: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00585eb7: { // 0x585eb7: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00585eb8: { // 0x585eb8: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00585eb9: { // 0x585eb9: ba06000000 MOV EDX,0x6
    s.dx = 0x00000006u;
  }
  L00585ebe: { // 0x585ebe: be04000000 MOV ESI,0x4
    s.si = 0x00000004u;
  }
  L00585ec3: { // 0x585ec3: 89542458 MOV dword ptr [ESP + 0x58],EDX
    m.w32((f.sp+0x00000058u), s.dx);
  }
  L00585ec7: { // 0x585ec7: 8974245c MOV dword ptr [ESP + 0x5c],ESI
    m.w32((f.sp+0x0000005cu), s.si);
  }
  L00585ecb: { // 0x585ecb: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L00585ecd: { // 0x585ecd: be06000000 MOV ESI,0x6
    s.si = 0x00000006u;
  }
  L00585ed2: { // 0x585ed2: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00585ed3: { // 0x585ed3: 8bbc24a8000000 MOV EDI,dword ptr [ESP + 0xa8]
    s.di = m.r32((f.sp+0x000000a8u));
  }
  L00585eda: { // 0x585eda: 89742470 MOV dword ptr [ESP + 0x70],ESI
    m.w32((f.sp+0x00000070u), s.si);
  }
  L00585ede: { // 0x585ede: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L00585ee0: { // 0x585ee0: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00585ee2: { // 0x585ee2: 89b42480000000 MOV dword ptr [ESP + 0x80],ESI
    m.w32((f.sp+0x00000080u), s.si);
  }
  L00585ee9: { // 0x585ee9: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00585eeb: { // 0x585eeb: be02000000 MOV ESI,0x2
    s.si = 0x00000002u;
  }
  L00585ef0: { // 0x585ef0: 8954246c MOV dword ptr [ESP + 0x6c],EDX
    m.w32((f.sp+0x0000006cu), s.dx);
  }
  L00585ef4: { // 0x585ef4: 8954247c MOV dword ptr [ESP + 0x7c],EDX
    m.w32((f.sp+0x0000007cu), s.dx);
  }
  L00585ef8: { // 0x585ef8: 8994248c000000 MOV dword ptr [ESP + 0x8c],EDX
    m.w32((f.sp+0x0000008cu), s.dx);
  }
  L00585eff: { // 0x585eff: 89442454 MOV dword ptr [ESP + 0x54],EAX
    m.w32((f.sp+0x00000054u), s.ax);
  }
  L00585f03: { // 0x585f03: 894c2458 MOV dword ptr [ESP + 0x58],ECX
    m.w32((f.sp+0x00000058u), s.cx);
  }
  L00585f07: { // 0x585f07: 89442464 MOV dword ptr [ESP + 0x64],EAX
    m.w32((f.sp+0x00000064u), s.ax);
  }
  L00585f0b: { // 0x585f0b: 894c2468 MOV dword ptr [ESP + 0x68],ECX
    m.w32((f.sp+0x00000068u), s.cx);
  }
  L00585f0f: { // 0x585f0f: 89442474 MOV dword ptr [ESP + 0x74],EAX
    m.w32((f.sp+0x00000074u), s.ax);
  }
  L00585f13: { // 0x585f13: 894c2478 MOV dword ptr [ESP + 0x78],ECX
    m.w32((f.sp+0x00000078u), s.cx);
  }
  L00585f17: { // 0x585f17: 89842484000000 MOV dword ptr [ESP + 0x84],EAX
    m.w32((f.sp+0x00000084u), s.ax);
  }
  L00585f1e: { // 0x585f1e: 898c2488000000 MOV dword ptr [ESP + 0x88],ECX
    m.w32((f.sp+0x00000088u), s.cx);
  }
  L00585f25: { // 0x585f25: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L00585f27: { // 0x585f27: 89842494000000 MOV dword ptr [ESP + 0x94],EAX
    m.w32((f.sp+0x00000094u), s.ax);
  }
  L00585f2e: { // 0x585f2e: 898c2498000000 MOV dword ptr [ESP + 0x98],ECX
    m.w32((f.sp+0x00000098u), s.cx);
  }
  L00585f35: { // 0x585f35: 8b4f10 MOV ECX,dword ptr [EDI + 0x10]
    s.cx = m.r32((s.di+0x00000010u));
  }
  L00585f38: { // 0x585f38: b81f85eb51 MOV EAX,0x51eb851f
    s.ax = 0x51eb851fu;
  }
  L00585f3d: { // 0x585f3d: 8994249c000000 MOV dword ptr [ESP + 0x9c],EDX
    m.w32((f.sp+0x0000009cu), s.dx);
  }
  L00585f44: { // 0x585f44: f7e9 IMUL ECX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.cx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  L00585f46: { // 0x585f46: c1fa04 SAR EDX,0x4
    s.dx = integer::shift(s.dx,0x00000004u,32,flags,integer::Shift::arithmetic_right);
  }
  L00585f49: { // 0x585f49: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L00585f4b: { // 0x585f4b: 89b42490000000 MOV dword ptr [ESP + 0x90],ESI
    m.w32((f.sp+0x00000090u), s.si);
  }
  L00585f52: { // 0x585f52: c1e81f SHR EAX,0x1f
    s.ax = integer::shift(s.ax,0x0000001fu,32,flags,integer::Shift::right);
  }
  L00585f55: { // 0x585f55: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00585f57: { // 0x585f57: be04000000 MOV ESI,0x4
    s.si = 0x00000004u;
  }
  L00585f5c: { // 0x585f5c: 8bea MOV EBP,EDX
    s.bp = s.dx;
  }
  L00585f5e: { // 0x585f5e: 89b424a0000000 MOV dword ptr [ESP + 0xa0],ESI
    m.w32((f.sp+0x000000a0u), s.si);
  }
  L00585f65: { // 0x585f65: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00585f67: { // 0x585f67: 896c2434 MOV dword ptr [ESP + 0x34],EBP
    m.w32((f.sp+0x00000034u), s.bp);
  }
  L00585f6b: { // 0x585f6b: 8d74ad00 LEA ESI,[EBP + EBP*0x4]
    s.si = (s.bp+(s.bp * 0x00000004u));
  }
  L00585f6f: { // 0x585f6f: 895c2410 MOV dword ptr [ESP + 0x10],EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
  L00585f73: { // 0x585f73: d1e6 SHL ESI,0x1
    s.si = integer::shift(s.si,0x00000001u,32,flags,integer::Shift::left);
  }
  L00585f75: { // 0x585f75: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L00585f77: { // 0x585f77: 895c2430 MOV dword ptr [ESP + 0x30],EBX
    m.w32((f.sp+0x00000030u), s.bx);
  }
  L00585f7b: { // 0x585f7b: 89742438 MOV dword ptr [ESP + 0x38],ESI
    m.w32((f.sp+0x00000038u), s.si);
  }
  L00585f7f: { // 0x585f7f: 0f8e87010000 JLE 0x0058610c
    if(integer::condition("JLE",flags)) goto L0058610c;
  }
  L00585f85: { // 0x585f85: eb07 JMP 0x00585f8e
    goto L00585f8e;
  }
  L00585f87: { // 0x585f87: 8bbc24a8000000 MOV EDI,dword ptr [ESP + 0xa8]
    s.di = m.r32((f.sp+0x000000a8u));
  }
  L00585f8e: { // 0x585f8e: 396c2410 CMP dword ptr [ESP + 0x10],EBP
    (void)integer::sub(m.r32((f.sp+0x00000010u)),s.bp,32,flags);
  }
  L00585f92: { // 0x585f92: 0f8d74010000 JGE 0x0058610c
    if(integer::condition("JGE",flags)) goto L0058610c;
  }
  L00585f98: { // 0x585f98: 8b5f10 MOV EBX,dword ptr [EDI + 0x10]
    s.bx = m.r32((s.di+0x00000010u));
  }
  L00585f9b: { // 0x585f9b: c744245000000000 MOV dword ptr [ESP + 0x50],0x0
    m.w32((f.sp+0x00000050u), 0x00000000u);
  }
  L00585fa3: { // 0x585fa3: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L00585fa4: { // 0x585fa4: 8d4b01 LEA ECX,[EBX + 0x1]
    s.cx = (s.bx+0x00000001u);
  }
  L00585fa7: { // 0x585fa7: 894c244c MOV dword ptr [ESP + 0x4c],ECX
    m.w32((f.sp+0x0000004cu), s.cx);
  }
  L00585fab: { // 0x585fab: df6c244c FILD qword ptr [ESP + 0x4c]
    const auto address=(f.sp+0x0000004cu);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L00585faf: { // 0x585faf: dd5c2414 FSTP double ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00585fb3: { // 0x585fb3: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L00585fb8: { // 0x585fb8: e8239e0a00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5791677u); flags=s.arithmetic_flags;
  }
  L00585fbd: { // 0x585fbd: 89442444 MOV dword ptr [ESP + 0x44],EAX
    m.w32((f.sp+0x00000044u), s.ax);
  }
  L00585fc1: { // 0x585fc1: c744244800000000 MOV dword ptr [ESP + 0x48],0x0
    m.w32((f.sp+0x00000048u), 0x00000000u);
  }
  L00585fc9: { // 0x585fc9: df6c2444 FILD qword ptr [ESP + 0x44]
    const auto address=(f.sp+0x00000044u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L00585fcd: { // 0x585fcd: dc4c2414 FMUL double ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.multiply64(read64(m,address));
  }
  L00585fd1: { // 0x585fd1: dc0db00d7900 FMUL double ptr [0x00790db0]
    const auto address=(0x00790db0u);
    s.fp.multiply64(read64(m,address));
  }
  L00585fd7: { // 0x585fd7: e8744a1e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5791708u); flags=s.arithmetic_flags;
  }
  L00585fdc: { // 0x585fdc: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00585fde: { // 0x585fde: 77d3 JA 0x00585fb3
    if(integer::condition("JA",flags)) goto L00585fb3;
  }
  L00585fe0: { // 0x585fe0: 8b5704 MOV EDX,dword ptr [EDI + 0x4]
    s.dx = m.r32((s.di+0x00000004u));
  }
  L00585fe3: { // 0x585fe3: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00585fe5: { // 0x585fe5: 32db XOR BL,BL
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))^((s.bx & 0xffu)),8,flags));
  }
  L00585fe7: { // 0x585fe7: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L00585fea: { // 0x585fea: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00585fee: { // 0x585fee: 0fbf4c2416 MOVSX ECX,word ptr [ESP + 0x16]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000016u)),16));
  }
  L00585ff3: { // 0x585ff3: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00585ff6: { // 0x585ff6: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L00585ffa: { // 0x585ffa: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00585ffc: { // 0x585ffc: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L00586000: { // 0x586000: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L00586004: { // 0x586004: 8d442460 LEA EAX,[ESP + 0x60]
    s.ax = (f.sp+0x00000060u);
  }
  L00586008: { // 0x586008: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L0058600c: { // 0x58600c: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00586010: { // 0x586010: eb04 JMP 0x00586016
    goto L00586016;
  }
  L00586012: { // 0x586012: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00586016: { // 0x586016: 83ff05 CMP EDI,0x5
    (void)integer::sub(s.di,0x00000005u,32,flags);
  }
  L00586019: { // 0x586019: 7d2e JGE 0x00586049
    if(integer::condition("JGE",flags)) goto L00586049;
  }
  L0058601b: { // 0x58601b: 8b50fc MOV EDX,dword ptr [EAX + -0x4]
    s.dx = m.r32((s.ax-0x00000004u));
  }
  L0058601e: { // 0x58601e: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L00586020: { // 0x586020: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L00586024: { // 0x586024: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L00586028: { // 0x586028: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L0058602c: { // 0x58602c: e8ef000000 CALL 0x00586120
    s.arithmetic_flags=flags; invoke(m,s,f,0x00586120u,5791793u); flags=s.arithmetic_flags;
  }
  L00586031: { // 0x586031: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00586033: { // 0x586033: 7402 JZ 0x00586037
    if(integer::condition("JZ",flags)) goto L00586037;
  }
  L00586035: { // 0x586035: b301 MOV BL,0x1
    s.bx = with_al(s.bx, 0x00000001u);
  }
  L00586037: { // 0x586037: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0058603b: { // 0x58603b: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0058603c: { // 0x58603c: 83c110 ADD ECX,0x10
    s.cx = integer::add(s.cx,0x00000010u,32,flags);
  }
  L0058603f: { // 0x58603f: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L00586041: { // 0x586041: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L00586045: { // 0x586045: 74cb JZ 0x00586012
    if(integer::condition("JZ",flags)) goto L00586012;
  }
  L00586047: { // 0x586047: eb08 JMP 0x00586051
    goto L00586051;
  }
  L00586049: { // 0x586049: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L0058604b: { // 0x58604b: 0f84aa000000 JZ 0x005860fb
    if(integer::condition("JZ",flags)) goto L005860fb;
  }
  L00586051: { // 0x586051: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L00586056: { // 0x586056: e8859d0a00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5791835u); flags=s.arithmetic_flags;
  }
  L0058605b: { // 0x58605b: 8944243c MOV dword ptr [ESP + 0x3c],EAX
    m.w32((f.sp+0x0000003cu), s.ax);
  }
  L0058605f: { // 0x58605f: c744244000000000 MOV dword ptr [ESP + 0x40],0x0
    m.w32((f.sp+0x00000040u), 0x00000000u);
  }
  L00586067: { // 0x586067: df6c243c FILD qword ptr [ESP + 0x3c]
    const auto address=(f.sp+0x0000003cu);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0058606b: { // 0x58606b: dc0d680f7900 FMUL double ptr [0x00790f68]
    const auto address=(0x00790f68u);
    s.fp.multiply64(read64(m,address));
  }
  L00586071: { // 0x586071: e8da491e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5791862u); flags=s.arithmetic_flags;
  }
  L00586076: { // 0x586076: 83f805 CMP EAX,0x5
    (void)integer::sub(s.ax,0x00000005u,32,flags);
  }
  L00586079: { // 0x586079: 77d6 JA 0x00586051
    if(integer::condition("JA",flags)) goto L00586051;
  }
  L0058607b: { // 0x58607b: 8b0d2caba300 MOV ECX,dword ptr [0x00a3ab2c]
    s.cx = m.r32((0x00a3ab2cu));
  }
  L00586081: { // 0x586081: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00586083: { // 0x586083: 8d6c0808 LEA EBP,[EAX + ECX*0x1 + 0x8]
    s.bp = (s.ax+(s.cx * 0x00000001u)+0x00000008u);
  }
  L00586087: { // 0x586087: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L0058608b: { // 0x58608b: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0058608c: { // 0x58608c: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0058608e: { // 0x58608e: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00586090: { // 0x586090: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00586092: { // 0x586092: 7e5a JLE 0x005860ee
    if(integer::condition("JLE",flags)) goto L005860ee;
  }
  L00586094: { // 0x586094: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L00586098: { // 0x586098: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0058609a: { // 0x58609a: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0058609c: { // 0x58609c: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0058609d: { // 0x58609d: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0058609f: { // 0x58609f: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L005860a1: { // 0x5860a1: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005860a3: { // 0x5860a3: 7e37 JLE 0x005860dc
    if(integer::condition("JLE",flags)) goto L005860dc;
  }
  L005860a5: { // 0x5860a5: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L005860a9: { // 0x5860a9: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L005860ad: { // 0x5860ad: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L005860af: { // 0x5860af: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L005860b1: { // 0x5860b1: 8d0472 LEA EAX,[EDX + ESI*0x2]
    s.ax = (s.dx+(s.si * 0x00000002u));
  }
  L005860b4: { // 0x5860b4: 8d1479 LEA EDX,[ECX + EDI*0x2]
    s.dx = (s.cx+(s.di * 0x00000002u));
  }
  L005860b7: { // 0x5860b7: 6689542436 MOV word ptr [ESP + 0x36],DX
    m.w16((f.sp+0x00000036u), (s.dx & 0xffffu));
  }
  L005860bc: { // 0x5860bc: 8d542434 LEA EDX,[ESP + 0x34]
    s.dx = (f.sp+0x00000034u);
  }
  L005860c0: { // 0x5860c0: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L005860c2: { // 0x5860c2: 6689442434 MOV word ptr [ESP + 0x34],AX
    m.w16((f.sp+0x00000034u), (s.ax & 0xffffu));
  }
  L005860c7: { // 0x5860c7: e824f1ffff CALL 0x005851f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005851f0u,5791948u); flags=s.arithmetic_flags;
  }
  L005860cc: { // 0x5860cc: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L005860d0: { // 0x5860d0: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L005860d1: { // 0x5860d1: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L005860d3: { // 0x5860d3: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L005860d4: { // 0x5860d4: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L005860d6: { // 0x5860d6: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L005860d8: { // 0x5860d8: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L005860da: { // 0x5860da: 7cc9 JL 0x005860a5
    if(integer::condition("JL",flags)) goto L005860a5;
  }
  L005860dc: { // 0x5860dc: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L005860e0: { // 0x5860e0: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L005860e1: { // 0x5860e1: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L005860e2: { // 0x5860e2: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L005860e4: { // 0x5860e4: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L005860e6: { // 0x5860e6: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L005860e8: { // 0x5860e8: 7cae JL 0x00586098
    if(integer::condition("JL",flags)) goto L00586098;
  }
  L005860ea: { // 0x5860ea: 8b742438 MOV ESI,dword ptr [ESP + 0x38]
    s.si = m.r32((f.sp+0x00000038u));
  }
  L005860ee: { // 0x5860ee: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L005860f2: { // 0x5860f2: 8b6c2434 MOV EBP,dword ptr [ESP + 0x34]
    s.bp = m.r32((f.sp+0x00000034u));
  }
  L005860f6: { // 0x5860f6: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L005860f7: { // 0x5860f7: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L005860fb: { // 0x5860fb: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L005860ff: { // 0x5860ff: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00586100: { // 0x586100: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L00586102: { // 0x586102: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L00586106: { // 0x586106: 0f8c7bfeffff JL 0x00585f87
    if(integer::condition("JL",flags)) goto L00585f87;
  }
  L0058610c: { // 0x58610c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0058610d: { // 0x58610d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0058610e: { // 0x58610e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0058610f: { // 0x58610f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00586110: { // 0x586110: 81c494000000 ADD ESP,0x94
    f.sp = integer::add(f.sp,0x00000094u,32,flags);
  }
  L00586116: { // 0x586116: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
