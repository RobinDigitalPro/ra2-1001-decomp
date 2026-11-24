#include "recovered/recovery_b685_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b685 {
namespace {
void f_002b6910(Memory&,State&,Frame&,const Operations&);
void f_000538b0(Memory&,State&,Frame&,const Operations&);
void f_001cdaa0(Memory&,State&,Frame&,const Operations&);
void f_001cd870(Memory&,State&,Frame&,const Operations&);
void f_00053890(Memory&,State&,Frame&,const Operations&);
void f_00079e70(Memory&,State&,Frame&,const Operations&);
void f_00145490(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_002b6910(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006b6910: { // 0x6b6910: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006b6912: {
    if(m.r32(s.ax+0x84)!=0x4538b0)throw std::domain_error("685 unproved tail target");
    s.arithmetic_flags=flags;f_000538b0(m,s,f,op);return;
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
void f_001cdaa0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005cdaa0: { // 0x5cdaa0: 8a4174 MOV AL, byte ptr [ECX + 0x74]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000074u)));
  }
  L005cdaa3: { // 0x5cdaa3: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cdaa5: { // 0x5cdaa5: 7418 JZ 0x5cdabf
    if(integer::condition("JZ",flags)) goto L005cdabf;
  }
  L005cdaa7: { // 0x5cdaa7: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L005cdaa9: { // 0x5cdaa9: ff90b0010000 CALL dword ptr [EAX + 0x1b0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000001b0u)),6085295u); flags=s.arithmetic_flags;
  }
  L005cdaaf: { // 0x5cdaaf: 8b0da8aaa500 MOV ECX, dword ptr [0xa5aaa8]
    s.cx = m.r32((0x00a5aaa8u));
  }
  L005cdab5: { // 0x5cdab5: 8d1409 LEA EDX, [ECX + ECX]
    s.dx = (s.cx+s.cx);
  }
  L005cdab8: { // 0x5cdab8: 3bc2 CMP EAX, EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L005cdaba: { // 0x5cdaba: 7c03 JL 0x5cdabf
    if(integer::condition("JL",flags)) goto L005cdabf;
  }
  L005cdabc: { // 0x5cdabc: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L005cdabe: { // 0x5cdabe: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L005cdabf: { // 0x5cdabf: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L005cdac1: { // 0x5cdac1: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_001cd870(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005cd870: { // 0x5cd870: 83ec0c SUB ESP, 0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L005cd873: { // 0x5cd873: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005cd874: { // 0x5cd874: 8db188000000 LEA ESI, [ECX + 0x88]
    s.si = (s.cx+0x00000088u);
  }
  L005cd87a: { // 0x5cd87a: 8bc6 MOV EAX, ESI
    s.ax = s.si;
  }
  L005cd87c: { // 0x5cd87c: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L005cd87e: { // 0x5cd87e: 894c2404 MOV dword ptr [ESP + 4], ECX
    m.w32((f.sp+4u), s.cx);
  }
  L005cd882: { // 0x5cd882: 8d4c2404 LEA ECX, [ESP + 4]
    s.cx = (f.sp+4u);
  }
  L005cd886: { // 0x5cd886: 8b5004 MOV EDX, dword ptr [EAX + 4]
    s.dx = m.r32((s.ax+4u));
  }
  L005cd889: { // 0x5cd889: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005cd88a: { // 0x5cd88a: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L005cd88f: { // 0x5cd88f: 8954240c MOV dword ptr [ESP + 0xc], EDX
    m.w32((f.sp+0x0000000cu), s.dx);
  }
  L005cd893: { // 0x5cd893: 8b4008 MOV EAX, dword ptr [EAX + 8]
    s.ax = m.r32((s.ax+8u));
  }
  L005cd896: { // 0x5cd896: 89442410 MOV dword ptr [ESP + 0x10], EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L005cd89a: { // 0x5cd89a: e8f17bf7ff CALL 0x545490
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545490u,6084767u); flags=s.arithmetic_flags;
  }
  L005cd89f: { // 0x5cd89f: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005cd8a1: { // 0x5cd8a1: 8b4e08 MOV ECX, dword ptr [ESI + 8]
    s.cx = m.r32((s.si+8u));
  }
  L005cd8a4: { // 0x5cd8a4: 8b4604 MOV EAX, dword ptr [ESI + 4]
    s.ax = m.r32((s.si+4u));
  }
  L005cd8a7: { // 0x5cd8a7: 89542404 MOV dword ptr [ESP + 4], EDX
    m.w32((f.sp+4u), s.dx);
  }
  L005cd8ab: { // 0x5cd8ab: 8d542404 LEA EDX, [ESP + 4]
    s.dx = (f.sp+4u);
  }
  L005cd8af: { // 0x5cd8af: 894c240c MOV dword ptr [ESP + 0xc], ECX
    m.w32((f.sp+0x0000000cu), s.cx);
  }
  L005cd8b3: { // 0x5cd8b3: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005cd8b4: { // 0x5cd8b4: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L005cd8b9: { // 0x5cd8b9: 8944240c MOV dword ptr [ESP + 0xc], EAX
    m.w32((f.sp+0x0000000cu), s.ax);
  }
  L005cd8bd: { // 0x5cd8bd: e8ce7bf7ff CALL 0x545490
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545490u,6084802u); flags=s.arithmetic_flags;
  }
  L005cd8c2: { // 0x5cd8c2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005cd8c3: { // 0x5cd8c3: 83c40c ADD ESP, 0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L005cd8c6: { // 0x5cd8c6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00053890(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00453890: { // 0x453890: b806000000 MOV EAX, 6
    s.ax = 6u;
  }
  L00453895: { // 0x453895: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00079e70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00479e70: { // 0x479e70: 8b4138 MOV EAX, dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  L00479e73: { // 0x479e73: 8b0db8a1a300 MOV ECX, dword ptr [0xa3a1b8]
    s.cx = m.r32((0x00a3a1b8u));
  }
  L00479e79: { // 0x479e79: 3bc1 CMP EAX, ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00479e7b: { // 0x479e7b: 7c0d JL 0x479e8a
    if(integer::condition("JL",flags)) goto L00479e8a;
  }
  L00479e7d: { // 0x479e7d: 83c10e ADD ECX, 0xe
    s.cx = integer::add(s.cx,0x0000000eu,32,flags);
  }
  L00479e80: { // 0x479e80: 3bc1 CMP EAX, ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00479e82: { // 0x479e82: 7d06 JGE 0x479e8a
    if(integer::condition("JGE",flags)) goto L00479e8a;
  }
  L00479e84: { // 0x479e84: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L00479e89: { // 0x479e89: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00479e8a: { // 0x479e8a: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00479e8c: { // 0x479e8c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00145490(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00545490: { // 0x545490: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00545491: { // 0x545491: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00545492: { // 0x545492: 8b7c240c MOV EDI, dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  L00545496: { // 0x545496: 8b07 MOV EAX, dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L00545498: { // 0x545498: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00545499: { // 0x545499: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0054549f: { // 0x54549f: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L005454a1: { // 0x5454a1: 8bf0 MOV ESI, EAX
    s.si = s.ax;
  }
  L005454a3: { // 0x5454a3: 8b4704 MOV EAX, dword ptr [EDI + 4]
    s.ax = m.r32((s.di+4u));
  }
  L005454a6: { // 0x5454a6: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L005454a7: { // 0x5454a7: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L005454ad: { // 0x5454ad: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L005454af: { // 0x5454af: c1f808 SAR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L005454b2: { // 0x5454b2: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L005454b4: { // 0x5454b4: c1fe08 SAR ESI, 8
    s.si = integer::shift(s.si,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L005454b7: { // 0x5454b7: c1e209 SHL EDX, 9
    s.dx = integer::shift(s.dx,9u,32,flags,integer::Shift::left);
  }
  L005454ba: { // 0x5454ba: 03d6 ADD EDX, ESI
    s.dx = integer::add(s.dx,s.si,32,flags);
  }
  L005454bc: { // 0x5454bc: 781c JS 0x5454da
    if(integer::condition("JS",flags)) goto L005454da;
  }
  L005454be: { // 0x5454be: 3b913c010000 CMP EDX, dword ptr [ECX + 0x13c]
    (void)integer::sub(s.dx,m.r32((s.cx+0x0000013cu)),32,flags);
  }
  L005454c4: { // 0x5454c4: 7d14 JGE 0x5454da
    if(integer::condition("JGE",flags)) goto L005454da;
  }
  L005454c6: { // 0x5454c6: 8b8938010000 MOV ECX, dword ptr [ECX + 0x138]
    s.cx = m.r32((s.cx+0x00000138u));
  }
  L005454cc: { // 0x5454cc: 8b1491 MOV EDX, dword ptr [ECX + EDX*4]
    s.dx = m.r32((s.cx+(s.dx * 4u)));
  }
  L005454cf: { // 0x5454cf: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L005454d1: { // 0x5454d1: 7407 JZ 0x5454da
    if(integer::condition("JZ",flags)) goto L005454da;
  }
  L005454d3: { // 0x5454d3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005454d4: { // 0x5454d4: 8bc2 MOV EAX, EDX
    s.ax = s.dx;
  }
  L005454d6: { // 0x5454d6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005454d7: { // 0x5454d7: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L005454da: { // 0x5454da: 668974240c MOV word ptr [ESP + 0xc], SI
    m.w16((f.sp+0x0000000cu), (s.si & 0xffffu));
  }
  L005454df: { // 0x5454df: 668944240e MOV word ptr [ESP + 0xe], AX
    m.w16((f.sp+0x0000000eu), (s.ax & 0xffffu));
  }
  L005454e4: { // 0x5454e4: 8b54240c MOV EDX, dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  L005454e8: { // 0x5454e8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005454e9: { // 0x5454e9: 89153476a500 MOV dword ptr [0xa57634], EDX
    m.w32((0x00a57634u), s.dx);
  }
  L005454ef: { // 0x5454ef: b81076a500 MOV EAX, 0xa57610
    s.ax = 0x00a57610u;
  }
  L005454f4: { // 0x5454f4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005454f5: { // 0x5454f5: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 7039248u:f_002b6910(m,s,child,{});break;
case 4536496u:f_000538b0(m,s,child,{});break;
case 6085280u:f_001cdaa0(m,s,child,{});break;
case 6084720u:f_001cd870(m,s,child,{});break;
case 4536464u:f_00053890(m,s,child,{});break;
case 4693616u:f_00079e70(m,s,child,{});break;
case 5526672u:f_00145490(m,s,child,{});break;
default:throw std::domain_error("recovery685 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_005ff4d0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005ff4d0: { // 0x5ff4d0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005ff4d1: { // 0x5ff4d1: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  L005ff4d5: { // 0x5ff4d5: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005ff4d6: { // 0x5ff4d6: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L005ff4d8: { // 0x5ff4d8: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L005ff4da: { // 0x5ff4da: 7476 JZ 0x005ff552
    if(integer::condition("JZ",flags)) goto L005ff552;
  }
  L005ff4dc: { // 0x5ff4dc: 8a4676 MOV AL,byte ptr [ESI + 0x76]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000076u)));
  }
  L005ff4df: { // 0x5ff4df: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005ff4e1: { // 0x5ff4e1: 756f JNZ 0x005ff552
    if(integer::condition("JNZ",flags)) goto L005ff552;
  }
  L005ff4e3: { // 0x5ff4e3: 8a467d MOV AL,byte ptr [ESI + 0x7d]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000007du)));
  }
  L005ff4e6: { // 0x5ff4e6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005ff4e8: { // 0x5ff4e8: 7468 JZ 0x005ff552
    if(integer::condition("JZ",flags)) goto L005ff552;
  }
  L005ff4ea: { // 0x5ff4ea: 8b466c MOV EAX,dword ptr [ESI + 0x6c]
    s.ax = m.r32((s.si+0x0000006cu));
  }
  L005ff4ed: { // 0x5ff4ed: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005ff4ef: { // 0x5ff4ef: 7461 JZ 0x005ff552
    if(integer::condition("JZ",flags)) goto L005ff552;
  }
  L005ff4f1: { // 0x5ff4f1: 8b8680050000 MOV EAX,dword ptr [ESI + 0x580]
    s.ax = m.r32((s.si+0x00000580u));
  }
  L005ff4f7: { // 0x5ff4f7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005ff4f9: { // 0x5ff4f9: 7557 JNZ 0x005ff552
    if(integer::condition("JNZ",flags)) goto L005ff552;
  }
  L005ff4fb: { // 0x5ff4fb: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005ff4fd: { // 0x5ff4fd: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005ff4ff: { // 0x5ff4ff: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),6288645u); flags=s.arithmetic_flags;
  }
  L005ff505: { // 0x5ff505: 8a88ff0a0000 MOV CL,byte ptr [EAX + 0xaff]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000affu)));
  }
  L005ff50b: { // 0x5ff50b: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L005ff50d: { // 0x5ff50d: 7443 JZ 0x005ff552
    if(integer::condition("JZ",flags)) goto L005ff552;
  }
  L005ff50f: { // 0x5ff50f: 8b4f24 MOV ECX,dword ptr [EDI + 0x24]
    s.cx = m.r32((s.di+0x00000024u));
  }
  L005ff512: { // 0x5ff512: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005ff514: { // 0x5ff514: 7435 JZ 0x005ff54b
    if(integer::condition("JZ",flags)) goto L005ff54b;
  }
  L005ff516: { // 0x5ff516: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L005ff518: { // 0x5ff518: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),6288670u); flags=s.arithmetic_flags;
  }
  L005ff51e: { // 0x5ff51e: 8a88da0a0000 MOV CL,byte ptr [EAX + 0xada]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000adau)));
  }
  L005ff524: { // 0x5ff524: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L005ff526: { // 0x5ff526: 7423 JZ 0x005ff54b
    if(integer::condition("JZ",flags)) goto L005ff54b;
  }
  L005ff528: { // 0x5ff528: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005ff52a: { // 0x5ff52a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005ff52c: { // 0x5ff52c: ff90a4010000 CALL dword ptr [EAX + 0x1a4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000001a4u)),6288690u); flags=s.arithmetic_flags;
  }
  L005ff532: { // 0x5ff532: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005ff534: { // 0x5ff534: 7415 JZ 0x005ff54b
    if(integer::condition("JZ",flags)) goto L005ff54b;
  }
  L005ff536: { // 0x5ff536: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005ff538: { // 0x5ff538: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005ff53a: { // 0x5ff53a: ff92a4010000 CALL dword ptr [EDX + 0x1a4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001a4u)),6288704u); flags=s.arithmetic_flags;
  }
  L005ff540: { // 0x5ff540: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L005ff542: { // 0x5ff542: e829a9e7ff CALL 0x00479e70
    s.arithmetic_flags=flags; invoke(m,s,f,0x00479e70u,6288711u); flags=s.arithmetic_flags;
  }
  L005ff547: { // 0x5ff547: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005ff549: { // 0x5ff549: 7407 JZ 0x005ff552
    if(integer::condition("JZ",flags)) goto L005ff552;
  }
  L005ff54b: { // 0x5ff54b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005ff54c: { // 0x5ff54c: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L005ff54e: { // 0x5ff54e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005ff54f: { // 0x5ff54f: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005ff552: { // 0x5ff552: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005ff553: { // 0x5ff553: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L005ff555: { // 0x5ff555: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005ff556: { // 0x5ff556: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_005ff780(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005ff780: { // 0x5ff780: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005ff781: { // 0x5ff781: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L005ff783: { // 0x5ff783: 8b4e28 MOV ECX,dword ptr [ESI + 0x28]
    s.cx = m.r32((s.si+0x00000028u));
  }
  L005ff786: { // 0x5ff786: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005ff788: { // 0x5ff788: 7504 JNZ 0x005ff78e
    if(integer::condition("JNZ",flags)) goto L005ff78e;
  }
  L005ff78a: { // 0x5ff78a: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L005ff78c: { // 0x5ff78c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005ff78d: { // 0x5ff78d: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005ff78e: { // 0x5ff78e: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L005ff790: { // 0x5ff790: ff5054 CALL dword ptr [EAX + 0x54]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000054u)),6289299u); flags=s.arithmetic_flags;
  }
  L005ff793: { // 0x5ff793: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005ff795: { // 0x5ff795: 7404 JZ 0x005ff79b
    if(integer::condition("JZ",flags)) goto L005ff79b;
  }
  L005ff797: { // 0x5ff797: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L005ff799: { // 0x5ff799: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005ff79a: { // 0x5ff79a: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005ff79b: { // 0x5ff79b: 8b4e24 MOV ECX,dword ptr [ESI + 0x24]
    s.cx = m.r32((s.si+0x00000024u));
  }
  L005ff79e: { // 0x5ff79e: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L005ff7a0: { // 0x5ff7a0: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),6289318u); flags=s.arithmetic_flags;
  }
  L005ff7a6: { // 0x5ff7a6: 8a88da0a0000 MOV CL,byte ptr [EAX + 0xada]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000adau)));
  }
  L005ff7ac: { // 0x5ff7ac: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L005ff7ae: { // 0x5ff7ae: 7551 JNZ 0x005ff801
    if(integer::condition("JNZ",flags)) goto L005ff801;
  }
  L005ff7b0: { // 0x5ff7b0: 8b4e24 MOV ECX,dword ptr [ESI + 0x24]
    s.cx = m.r32((s.si+0x00000024u));
  }
  L005ff7b3: { // 0x5ff7b3: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005ff7b5: { // 0x5ff7b5: 7426 JZ 0x005ff7dd
    if(integer::condition("JZ",flags)) goto L005ff7dd;
  }
  L005ff7b7: { // 0x5ff7b7: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L005ff7b9: { // 0x5ff7b9: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),6289340u); flags=s.arithmetic_flags;
  }
  L005ff7bc: { // 0x5ff7bc: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L005ff7bf: { // 0x5ff7bf: 751c JNZ 0x005ff7dd
    if(integer::condition("JNZ",flags)) goto L005ff7dd;
  }
  L005ff7c1: { // 0x5ff7c1: 8b4e28 MOV ECX,dword ptr [ESI + 0x28]
    s.cx = m.r32((s.si+0x00000028u));
  }
  L005ff7c4: { // 0x5ff7c4: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L005ff7c6: { // 0x5ff7c6: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L005ff7c8: { // 0x5ff7c8: ff92a4010000 CALL dword ptr [EDX + 0x1a4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001a4u)),6289358u); flags=s.arithmetic_flags;
  }
  L005ff7ce: { // 0x5ff7ce: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L005ff7d0: { // 0x5ff7d0: e80b1ce7ff CALL 0x004713e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004713e0u,6289365u); flags=s.arithmetic_flags;
  }
  L005ff7d5: { // 0x5ff7d5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005ff7d7: { // 0x5ff7d7: 7404 JZ 0x005ff7dd
    if(integer::condition("JZ",flags)) goto L005ff7dd;
  }
  L005ff7d9: { // 0x5ff7d9: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L005ff7db: { // 0x5ff7db: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005ff7dc: { // 0x5ff7dc: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005ff7dd: { // 0x5ff7dd: 8b4e28 MOV ECX,dword ptr [ESI + 0x28]
    s.cx = m.r32((s.si+0x00000028u));
  }
  L005ff7e0: { // 0x5ff7e0: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L005ff7e2: { // 0x5ff7e2: ff90a4010000 CALL dword ptr [EAX + 0x1a4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000001a4u)),6289384u); flags=s.arithmetic_flags;
  }
  L005ff7e8: { // 0x5ff7e8: 8b80ec000000 MOV EAX,dword ptr [EAX + 0xec]
    s.ax = m.r32((s.ax+0x000000ecu));
  }
  L005ff7ee: { // 0x5ff7ee: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  L005ff7f1: { // 0x5ff7f1: 740a JZ 0x005ff7fd
    if(integer::condition("JZ",flags)) goto L005ff7fd;
  }
  L005ff7f3: { // 0x5ff7f3: 83f806 CMP EAX,0x6
    (void)integer::sub(s.ax,0x00000006u,32,flags);
  }
  L005ff7f6: { // 0x5ff7f6: 7405 JZ 0x005ff7fd
    if(integer::condition("JZ",flags)) goto L005ff7fd;
  }
  L005ff7f8: { // 0x5ff7f8: 83f803 CMP EAX,0x3
    (void)integer::sub(s.ax,0x00000003u,32,flags);
  }
  L005ff7fb: { // 0x5ff7fb: 7504 JNZ 0x005ff801
    if(integer::condition("JNZ",flags)) goto L005ff801;
  }
  L005ff7fd: { // 0x5ff7fd: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L005ff7ff: { // 0x5ff7ff: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005ff800: { // 0x5ff800: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005ff801: { // 0x5ff801: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L005ff803: { // 0x5ff803: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005ff804: { // 0x5ff804: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
