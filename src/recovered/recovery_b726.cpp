#include "recovered/recovery_b726_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b726 {
namespace {
void f_000538c0(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_000538c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004538c0: { // 0x4538c0: 81c188000000 ADD ECX, 0x88
    s.cx = integer::add(s.cx,0x00000088u,32,flags);
  }
  L004538c6: { // 0x4538c6: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004538c7: { // 0x4538c7: 8bd1 MOV EDX, ECX
    s.dx = s.cx;
  }
  L004538c9: { // 0x4538c9: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004538ca: { // 0x4538ca: 8b02 MOV EAX, dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L004538cc: { // 0x4538cc: 8b4a04 MOV ECX, dword ptr [EDX + 4]
    s.cx = m.r32((s.dx+4u));
  }
  L004538cf: { // 0x4538cf: 8d7080 LEA ESI, [EAX - 0x80]
    s.si = (s.ax-0x00000080u);
  }
  L004538d2: { // 0x4538d2: 8b44240c MOV EAX, dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L004538d6: { // 0x4538d6: 83c180 ADD ECX, -0x80
    s.cx = integer::add(s.cx,0xffffff80u,32,flags);
  }
  L004538d9: { // 0x4538d9: 8b5208 MOV EDX, dword ptr [EDX + 8]
    s.dx = m.r32((s.dx+8u));
  }
  L004538dc: { // 0x4538dc: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L004538de: { // 0x4538de: 8937 MOV dword ptr [EDI], ESI
    m.w32((s.di), s.si);
  }
  L004538e0: { // 0x4538e0: 894f04 MOV dword ptr [EDI + 4], ECX
    m.w32((s.di+4u), s.cx);
  }
  L004538e3: { // 0x4538e3: 895708 MOV dword ptr [EDI + 8], EDX
    m.w32((s.di+8u), s.dx);
  }
  L004538e6: { // 0x4538e6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004538e7: { // 0x4538e7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004538e8: { // 0x4538e8: c20400 RET 4
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
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4536512u:f_000538c0(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
default:throw std::domain_error("recovery726 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0069f7c0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0069f7c0: { // 0x69f7c0: 83ec2c SUB ESP,0x2c
    f.sp = integer::sub(f.sp,0x0000002cu,32,flags);
  }
  L0069f7c3: { // 0x69f7c3: 8b81b0000000 MOV EAX,dword ptr [ECX + 0xb0]
    s.ax = m.r32((s.cx+0x000000b0u));
  }
  L0069f7c9: { // 0x69f7c9: 8b542430 MOV EDX,dword ptr [ESP + 0x30]
    s.dx = m.r32((f.sp+0x00000030u));
  }
  L0069f7cd: { // 0x69f7cd: 8b89b4000000 MOV ECX,dword ptr [ECX + 0xb4]
    s.cx = m.r32((s.cx+0x000000b4u));
  }
  L0069f7d3: { // 0x69f7d3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0069f7d4: { // 0x69f7d4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0069f7d5: { // 0x69f7d5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0069f7d6: { // 0x69f7d6: 8d3410 LEA ESI,[EAX + EDX*0x1]
    s.si = (s.ax+(s.dx * 0x00000001u));
  }
  L0069f7d9: { // 0x69f7d9: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0069f7da: { // 0x69f7da: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L0069f7de: { // 0x69f7de: 8b742444 MOV ESI,dword ptr [ESP + 0x44]
    s.si = m.r32((f.sp+0x00000044u));
  }
  L0069f7e2: { // 0x69f7e2: 8d3c31 LEA EDI,[ECX + ESI*0x1]
    s.di = (s.cx+(s.si * 0x00000001u));
  }
  L0069f7e5: { // 0x69f7e5: 897c241c MOV dword ptr [ESP + 0x1c],EDI
    m.w32((f.sp+0x0000001cu), s.di);
  }
  L0069f7e9: { // 0x69f7e9: 8b7c2448 MOV EDI,dword ptr [ESP + 0x48]
    s.di = m.r32((f.sp+0x00000048u));
  }
  L0069f7ed: { // 0x69f7ed: 8d1c38 LEA EBX,[EAX + EDI*0x1]
    s.bx = (s.ax+(s.di * 0x00000001u));
  }
  L0069f7f0: { // 0x69f7f0: 8b44244c MOV EAX,dword ptr [ESP + 0x4c]
    s.ax = m.r32((f.sp+0x0000004cu));
  }
  L0069f7f4: { // 0x69f7f4: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0069f7f6: { // 0x69f7f6: 03da ADD EBX,EDX
    s.bx = integer::add(s.bx,s.dx,32,flags);
  }
  L0069f7f8: { // 0x69f7f8: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L0069f7fa: { // 0x69f7fa: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0069f7fc: { // 0x69f7fc: 894c242c MOV dword ptr [ESP + 0x2c],ECX
    m.w32((f.sp+0x0000002cu), s.cx);
  }
  L0069f800: { // 0x69f800: 8b0d4887a200 MOV ECX,dword ptr [0x00a28748]
    s.cx = m.r32((0x00a28748u));
  }
  L0069f806: { // 0x69f806: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0069f808: { // 0x69f808: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0069f80c: { // 0x69f80c: 0f8e15010000 JLE 0x0069f927
    if(integer::condition("JLE",flags)) goto L0069f927;
  }
  L0069f812: { // 0x69f812: 8b0d3c87a200 MOV ECX,dword ptr [0x00a2873c]
    s.cx = m.r32((0x00a2873cu));
  }
  L0069f818: { // 0x69f818: 8b0c81 MOV ECX,dword ptr [ECX + EAX*0x4]
    s.cx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L0069f81b: { // 0x69f81b: 8a517d MOV DL,byte ptr [ECX + 0x7d]
    s.dx = with_al(s.dx, m.r8((s.cx+0x0000007du)));
  }
  L0069f81e: { // 0x69f81e: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L0069f820: { // 0x69f820: 0f84ee000000 JZ 0x0069f914
    if(integer::condition("JZ",flags)) goto L0069f914;
  }
  L0069f826: { // 0x69f826: 8a5175 MOV DL,byte ptr [ECX + 0x75]
    s.dx = with_al(s.dx, m.r8((s.cx+0x00000075u)));
  }
  L0069f829: { // 0x69f829: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L0069f82b: { // 0x69f82b: 0f84e3000000 JZ 0x0069f914
    if(integer::condition("JZ",flags)) goto L0069f914;
  }
  L0069f831: { // 0x69f831: 8a5174 MOV DL,byte ptr [ECX + 0x74]
    s.dx = with_al(s.dx, m.r8((s.cx+0x00000074u)));
  }
  L0069f834: { // 0x69f834: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L0069f836: { // 0x69f836: 0f84d8000000 JZ 0x0069f914
    if(integer::condition("JZ",flags)) goto L0069f914;
  }
  L0069f83c: { // 0x69f83c: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L0069f83e: { // 0x69f83e: 8d442430 LEA EAX,[ESP + 0x30]
    s.ax = (f.sp+0x00000030u);
  }
  L0069f842: { // 0x69f842: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0069f843: { // 0x69f843: ff92a8000000 CALL dword ptr [EDX + 0xa8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000000a8u)),6944841u); flags=s.arithmetic_flags;
  }
  L0069f849: { // 0x69f849: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0069f84b: { // 0x69f84b: 8b37 MOV ESI,dword ptr [EDI]
    s.si = m.r32((s.di));
  }
  L0069f84d: { // 0x69f84d: 8b4f04 MOV ECX,dword ptr [EDI + 0x4]
    s.cx = m.r32((s.di+0x00000004u));
  }
  L0069f850: { // 0x69f850: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L0069f854: { // 0x69f854: 8b6c2424 MOV EBP,dword ptr [ESP + 0x24]
    s.bp = m.r32((f.sp+0x00000024u));
  }
  L0069f858: { // 0x69f858: 8d0476 LEA EAX,[ESI + ESI*0x2]
    s.ax = (s.si+(s.si * 0x00000002u));
  }
  L0069f85b: { // 0x69f85b: 8b7f08 MOV EDI,dword ptr [EDI + 0x8]
    s.di = m.r32((s.di+0x00000008u));
  }
  L0069f85e: { // 0x69f85e: 897c2414 MOV dword ptr [ESP + 0x14],EDI
    m.w32((f.sp+0x00000014u), s.di);
  }
  L0069f862: { // 0x69f862: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0069f865: { // 0x69f865: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L0069f868: { // 0x69f868: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069f869: { // 0x69f869: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0069f86b: { // 0x69f86b: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0069f86d: { // 0x69f86d: 8d0476 LEA EAX,[ESI + ESI*0x2]
    s.ax = (s.si+(s.si * 0x00000002u));
  }
  L0069f870: { // 0x69f870: d1f9 SAR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069f872: { // 0x69f872: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0069f875: { // 0x69f875: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
  L0069f877: { // 0x69f877: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069f878: { // 0x69f878: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0069f87a: { // 0x69f87a: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0069f87c: { // 0x69f87c: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L0069f87e: { // 0x69f87e: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L0069f881: { // 0x69f881: 2bc5 SUB EAX,EBP
    s.ax = integer::sub(s.ax,s.bp,32,flags);
  }
  L0069f883: { // 0x69f883: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L0069f885: { // 0x69f885: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L0069f888: { // 0x69f888: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069f889: { // 0x69f889: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0069f88b: { // 0x69f88b: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069f88d: { // 0x69f88d: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0069f88f: { // 0x69f88f: 8d446d00 LEA EAX,[EBP + EBP*0x2]
    s.ax = (s.bp+(s.bp * 0x00000002u));
  }
  L0069f893: { // 0x69f893: d1fe SAR ESI,0x1
    s.si = integer::shift(s.si,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069f895: { // 0x69f895: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0069f898: { // 0x69f898: 894c2440 MOV dword ptr [ESP + 0x40],ECX
    m.w32((f.sp+0x00000040u), s.cx);
  }
  L0069f89c: { // 0x69f89c: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
  L0069f89e: { // 0x69f89e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069f89f: { // 0x69f89f: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0069f8a1: { // 0x69f8a1: c744244000000000 MOV dword ptr [ESP + 0x40],0x0
    m.w32((f.sp+0x00000040u), 0x00000000u);
  }
  L0069f8a9: { // 0x69f8a9: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069f8ab: { // 0x69f8ab: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L0069f8ad: { // 0x69f8ad: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0069f8af: { // 0x69f8af: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069f8b0: { // 0x69f8b0: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0069f8b6: { // 0x69f8b6: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0069f8b8: { // 0x69f8b8: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L0069f8ba: { // 0x69f8ba: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0069f8bc: { // 0x69f8bc: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069f8bd: { // 0x69f8bd: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0069f8c3: { // 0x69f8c3: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0069f8c5: { // 0x69f8c5: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0069f8c7: { // 0x69f8c7: c1fd08 SAR EBP,0x8
    s.bp = integer::shift(s.bp,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069f8ca: { // 0x69f8ca: c1fe08 SAR ESI,0x8
    s.si = integer::shift(s.si,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069f8cd: { // 0x69f8cd: 81ffd8020000 CMP EDI,0x2d8
    (void)integer::sub(s.di,0x000002d8u,32,flags);
  }
  L0069f8d3: { // 0x69f8d3: 7c08 JL 0x0069f8dd
    if(integer::condition("JL",flags)) goto L0069f8dd;
  }
  L0069f8d5: { // 0x69f8d5: c744244001000000 MOV dword ptr [ESP + 0x40],0x1
    m.w32((f.sp+0x00000040u), 0x00000001u);
  }
  L0069f8dd: { // 0x69f8dd: db442414 FILD dword ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load_integer32(m.r32(address));
  }
  L0069f8e1: { // 0x69f8e1: dc0d905faa00 FMUL double ptr [0x00aa5f90]
    const auto address=(0x00aa5f90u);
    s.fp.multiply64(read64(m,address));
  }
  L0069f8e7: { // 0x69f8e7: da442440 FIADD dword ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    floating_b61::fp_extended::add_integer32(s.fp,m.r32(address));
  }
  L0069f8eb: { // 0x69f8eb: dc0528577800 FADD double ptr [0x00785728]
    const auto address=(0x00785728u);
    s.fp.add64(read64(m,address));
  }
  L0069f8f1: { // 0x69f8f1: e85ab10c00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6945014u); flags=s.arithmetic_flags;
  }
  L0069f8f6: { // 0x69f8f6: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  L0069f8f8: { // 0x69f8f8: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0069f8fc: { // 0x69f8fc: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L0069f8fe: { // 0x69f8fe: 7c10 JL 0x0069f910
    if(integer::condition("JL",flags)) goto L0069f910;
  }
  L0069f900: { // 0x69f900: 3beb CMP EBP,EBX
    (void)integer::sub(s.bp,s.bx,32,flags);
  }
  L0069f902: { // 0x69f902: 7f0c JG 0x0069f910
    if(integer::condition("JG",flags)) goto L0069f910;
  }
  L0069f904: { // 0x69f904: 3b74241c CMP ESI,dword ptr [ESP + 0x1c]
    (void)integer::sub(s.si,m.r32((f.sp+0x0000001cu)),32,flags);
  }
  L0069f908: { // 0x69f908: 7c06 JL 0x0069f910
    if(integer::condition("JL",flags)) goto L0069f910;
  }
  L0069f90a: { // 0x69f90a: 3b74242c CMP ESI,dword ptr [ESP + 0x2c]
    (void)integer::sub(s.si,m.r32((f.sp+0x0000002cu)),32,flags);
  }
  L0069f90e: { // 0x69f90e: 7e23 JLE 0x0069f933
    if(integer::condition("JLE",flags)) goto L0069f933;
  }
  L0069f910: { // 0x69f910: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0069f914: { // 0x69f914: 8b0d4887a200 MOV ECX,dword ptr [0x00a28748]
    s.cx = m.r32((0x00a28748u));
  }
  L0069f91a: { // 0x69f91a: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0069f91b: { // 0x69f91b: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0069f91d: { // 0x69f91d: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0069f921: { // 0x69f921: 0f8cebfeffff JL 0x0069f812
    if(integer::condition("JL",flags)) goto L0069f812;
  }
  L0069f927: { // 0x69f927: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0069f928: { // 0x69f928: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0069f929: { // 0x69f929: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0069f92a: { // 0x69f92a: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0069f92c: { // 0x69f92c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0069f92d: { // 0x69f92d: 83c42c ADD ESP,0x2c
    f.sp = integer::add(f.sp,0x0000002cu,32,flags);
  }
  L0069f930: { // 0x69f930: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0069f933: { // 0x69f933: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0069f934: { // 0x69f934: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0069f935: { // 0x69f935: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0069f936: { // 0x69f936: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0069f938: { // 0x69f938: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0069f939: { // 0x69f939: 83c42c ADD ESP,0x2c
    f.sp = integer::add(f.sp,0x0000002cu,32,flags);
  }
  L0069f93c: { // 0x69f93c: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
