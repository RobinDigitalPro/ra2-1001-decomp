#include "recovered/recovery_b784_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b784 {
namespace {
void f_0022fde0(Memory&,State&,Frame&,const Operations&);
void f_00176590(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_0022fde0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0062fde0: { // 0x62fde0: 803900 CMP byte ptr [ECX], 0
    (void)integer::sub(m.r8((s.cx)),0u,8,flags);
  }
  L0062fde3: { // 0x62fde3: 7403 JZ 0x62fde8
    if(integer::condition("JZ",flags)) goto L0062fde8;
  }
  L0062fde5: { // 0x62fde5: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0062fde7: { // 0x62fde7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0062fde8: { // 0x62fde8: 8b4104 MOV EAX, dword ptr [ECX + 4]
    s.ax = m.r32((s.cx+4u));
  }
  L0062fdeb: { // 0x62fdeb: 8b5108 MOV EDX, dword ptr [ECX + 8]
    s.dx = m.r32((s.cx+8u));
  }
  L0062fdee: { // 0x62fdee: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0062fdef: { // 0x62fdef: 8b54910c MOV EDX, dword ptr [ECX + EDX*4 + 0xc]
    s.dx = m.r32((s.cx+(s.dx * 4u)+0x0000000cu));
  }
  L0062fdf3: { // 0x62fdf3: 8b74810c MOV ESI, dword ptr [ECX + EAX*4 + 0xc]
    s.si = m.r32((s.cx+(s.ax * 4u)+0x0000000cu));
  }
  L0062fdf7: { // 0x62fdf7: 8d44810c LEA EAX, [ECX + EAX*4 + 0xc]
    s.ax = (s.cx+(s.ax * 4u)+0x0000000cu);
  }
  L0062fdfb: { // 0x62fdfb: 33f2 XOR ESI, EDX
    s.si = integer::logical((s.si)^(s.dx),32,flags);
  }
  L0062fdfd: { // 0x62fdfd: 8930 MOV dword ptr [EAX], ESI
    m.w32((s.ax), s.si);
  }
  L0062fdff: { // 0x62fdff: 8b5104 MOV EDX, dword ptr [ECX + 4]
    s.dx = m.r32((s.cx+4u));
  }
  L0062fe02: { // 0x62fe02: 8b7108 MOV ESI, dword ptr [ECX + 8]
    s.si = m.r32((s.cx+8u));
  }
  L0062fe05: { // 0x62fe05: 8b44910c MOV EAX, dword ptr [ECX + EDX*4 + 0xc]
    s.ax = m.r32((s.cx+(s.dx * 4u)+0x0000000cu));
  }
  L0062fe09: { // 0x62fe09: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L0062fe0a: { // 0x62fe0a: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0062fe0b: { // 0x62fe0b: 81fafa000000 CMP EDX, 0xfa
    (void)integer::sub(s.dx,0x000000fau,32,flags);
  }
  L0062fe11: { // 0x62fe11: 895104 MOV dword ptr [ECX + 4], EDX
    m.w32((s.cx+4u), s.dx);
  }
  L0062fe14: { // 0x62fe14: 897108 MOV dword ptr [ECX + 8], ESI
    m.w32((s.cx+8u), s.si);
  }
  L0062fe17: { // 0x62fe17: 7c07 JL 0x62fe20
    if(integer::condition("JL",flags)) goto L0062fe20;
  }
  L0062fe19: { // 0x62fe19: c7410400000000 MOV dword ptr [ECX + 4], 0
    m.w32((s.cx+4u), 0u);
  }
  L0062fe20: { // 0x62fe20: 81fefa000000 CMP ESI, 0xfa
    (void)integer::sub(s.si,0x000000fau,32,flags);
  }
  L0062fe26: { // 0x62fe26: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0062fe27: { // 0x62fe27: 7c07 JL 0x62fe30
    if(integer::condition("JL",flags)) goto L0062fe30;
  }
  L0062fe29: { // 0x62fe29: c7410800000000 MOV dword ptr [ECX + 8], 0
    m.w32((s.cx+8u), 0u);
  }
  L0062fe30: { // 0x62fe30: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00176590(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00576590: { // 0x576590: 83ec18 SUB ESP, 0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
  L00576593: { // 0x576593: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00576594: { // 0x576594: 8bf2 MOV ESI, EDX
    s.si = s.dx;
  }
  L00576596: { // 0x576596: 8bc6 MOV EAX, ESI
    s.ax = s.si;
  }
  L00576598: { // 0x576598: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00576599: { // 0x576599: 2bc1 SUB EAX, ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L0057659b: { // 0x57659b: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0057659c: { // 0x57659c: 33ff XOR EDI, EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0057659e: { // 0x57659e: 89442408 MOV dword ptr [ESP + 8], EAX
    m.w32((f.sp+8u), s.ax);
  }
  L005765a2: { // 0x5765a2: 897c240c MOV dword ptr [ESP + 0xc], EDI
    m.w32((f.sp+0x0000000cu), s.di);
  }
  L005765a6: { // 0x5765a6: df6c2408 FILD qword ptr [ESP + 8]
    const auto address=(f.sp+8u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L005765aa: { // 0x5765aa: 894c2408 MOV dword ptr [ESP + 8], ECX
    m.w32((f.sp+8u), s.cx);
  }
  L005765ae: { // 0x5765ae: 897c240c MOV dword ptr [ESP + 0xc], EDI
    m.w32((f.sp+0x0000000cu), s.di);
  }
  L005765b2: { // 0x5765b2: dd5c2410 FSTP qword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L005765b6: { // 0x5765b6: df6c2408 FILD qword ptr [ESP + 8]
    const auto address=(f.sp+8u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L005765ba: { // 0x5765ba: dd5c2418 FSTP qword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L005765be: { // 0x5765be: b9d881a500 MOV ECX, 0xa581d8
    s.cx = 0x00a581d8u;
  }
  L005765c3: { // 0x5765c3: e818980b00 CALL 0x62fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5727688u); flags=s.arithmetic_flags;
  }
  L005765c8: { // 0x5765c8: 89442408 MOV dword ptr [ESP + 8], EAX
    m.w32((f.sp+8u), s.ax);
  }
  L005765cc: { // 0x5765cc: 897c240c MOV dword ptr [ESP + 0xc], EDI
    m.w32((f.sp+0x0000000cu), s.di);
  }
  L005765d0: { // 0x5765d0: df6c2408 FILD qword ptr [ESP + 8]
    const auto address=(f.sp+8u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L005765d4: { // 0x5765d4: dc4c2410 FMUL qword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.multiply64(read64(m,address));
  }
  L005765d8: { // 0x5765d8: dc0db00d7900 FMUL qword ptr [0x790db0]
    const auto address=(0x00790db0u);
    s.fp.multiply64(read64(m,address));
  }
  L005765de: { // 0x5765de: dc442418 FADD qword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.add64(read64(m,address));
  }
  L005765e2: { // 0x5765e2: e869441f00 CALL 0x76aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5727719u); flags=s.arithmetic_flags;
  }
  L005765e7: { // 0x5765e7: 3bc6 CMP EAX, ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L005765e9: { // 0x5765e9: 77d3 JA 0x5765be
    if(integer::condition("JA",flags)) goto L005765be;
  }
  L005765eb: { // 0x5765eb: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005765ec: { // 0x5765ec: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005765ed: { // 0x5765ed: 83c418 ADD ESP, 0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L005765f0: { // 0x5765f0: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0036aa50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0076aa50: { // 0x76aa50: 83ec0c SUB ESP, 0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L0076aa53: { // 0x76aa53: d93c24 FNSTCW word ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.control();
    m.w16(address,value);
  }
  L0076aa56: { // 0x76aa56: 8d442404 LEA EAX, [ESP + 4]
    s.ax = (f.sp+4u);
  }
  L0076aa5a: { // 0x76aa5a: 8b1424 MOV EDX, dword ptr [ESP]
    s.dx = m.r32((f.sp));
  }
  L0076aa5d: { // 0x76aa5d: 81e2ffff0000 AND EDX, 0xffff
    s.dx = integer::logical((s.dx)&(0x0000ffffu),32,flags);
  }
  L0076aa63: { // 0x76aa63: 3b15043a7c00 CMP EDX, dword ptr [0x7c3a04]
    (void)integer::sub(s.dx,m.r32((0x007c3a04u)),32,flags);
  }
  L0076aa69: { // 0x76aa69: 750b JNZ 0x76aa76
    if(integer::condition("JNZ",flags)) goto L0076aa76;
  }
  L0076aa6b: { // 0x76aa6b: df38 FISTP qword ptr [EAX]
    const auto address=(s.ax);
    const auto value=s.fp.pop_integer64();
    write64(m,address,value);
  }
  L0076aa6d: { // 0x76aa6d: 8b5004 MOV EDX, dword ptr [EAX + 4]
    s.dx = m.r32((s.ax+4u));
  }
  L0076aa70: { // 0x76aa70: 8b00 MOV EAX, dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0076aa72: { // 0x76aa72: 83c40c ADD ESP, 0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0076aa75: { // 0x76aa75: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076aa76: { // 0x76aa76: 8b15043a7c00 MOV EDX, dword ptr [0x7c3a04]
    s.dx = m.r32((0x007c3a04u));
  }
  L0076aa7c: { // 0x76aa7c: 891424 MOV dword ptr [ESP], EDX
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
  L0076aa84: { // 0x76aa84: 8b5004 MOV EDX, dword ptr [EAX + 4]
    s.dx = m.r32((s.ax+4u));
  }
  L0076aa87: { // 0x76aa87: 8b00 MOV EAX, dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0076aa89: { // 0x76aa89: 83c40c ADD ESP, 0xc
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
case 6487520u:f_0022fde0(m,s,child,{});break;
case 5727632u:f_00176590(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
default:throw std::domain_error("recovery784 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0057f930(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 std::array<std::uint8_t,117> table{91,249,87,0,155,249,87,0,214,249,87,0,16,250,87,0,80,250,87,0,139,250,87,0,197,250,87,0,5,251,87,0,64,251,87,0,122,251,87,0,186,251,87,0,245,251,87,0,47,252,87,0,111,252,87,0,170,252,87,0,228,252,87,0,248,252,87,0,12,253,87,0,24,253,87,0,55,253,87,0,70,253,87,0,0,1,2,20,3,4,5,6,7,8,9,10,11,20,20,20,20,20,12,13,14,20,20,20,15,16,20,20,20,20,17,18,19};leaf::Memory readonly_table(table.data(),0x57fd58u,117);m.add(readonly_table);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0057f930: { // 0x57f930: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L0057f934: { // 0x57f934: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0057f937: { // 0x57f937: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0057f938: { // 0x57f938: 8b35a8aaa300 MOV ESI,dword ptr [0x00a3aaa8]
    s.si = m.r32((0x00a3aaa8u));
  }
  L0057f93e: { // 0x57f93e: 2bc6 SUB EAX,ESI
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L0057f940: { // 0x57f940: 8d48fc LEA ECX,[EAX + -0x4]
    s.cx = (s.ax-0x00000004u);
  }
  L0057f943: { // 0x57f943: 83f920 CMP ECX,0x20
    (void)integer::sub(s.cx,0x00000020u,32,flags);
  }
  L0057f946: { // 0x57f946: 0f87fa030000 JA 0x0057fd46
    if(integer::condition("JA",flags)) goto L0057fd46;
  }
  L0057f94c: { // 0x57f94c: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0057f94e: { // 0x57f94e: 8a91acfd5700 MOV DL,byte ptr [ECX + 0x57fdac]
    s.dx = with_al(s.dx, m.r8((s.cx+0x0057fdacu)));
  }
  L0057f954: { // 0x57f954: ff249558fd5700 JMP dword ptr [EDX*0x4 + 0x57fd58]
    switch(m.r32(((s.dx * 0x00000004u)+0x0057fd58u))){
    case 0x0057f930u: goto L0057f930;
    case 0x0057f934u: goto L0057f934;
    case 0x0057f937u: goto L0057f937;
    case 0x0057f938u: goto L0057f938;
    case 0x0057f93eu: goto L0057f93e;
    case 0x0057f940u: goto L0057f940;
    case 0x0057f943u: goto L0057f943;
    case 0x0057f946u: goto L0057f946;
    case 0x0057f94cu: goto L0057f94c;
    case 0x0057f94eu: goto L0057f94e;
    case 0x0057f954u: goto L0057f954;
    case 0x0057f95bu: goto L0057f95b;
    case 0x0057f95du: goto L0057f95d;
    case 0x0057f962u: goto L0057f962;
    case 0x0057f967u: goto L0057f967;
    case 0x0057f96bu: goto L0057f96b;
    case 0x0057f96fu: goto L0057f96f;
    case 0x0057f973u: goto L0057f973;
    case 0x0057f979u: goto L0057f979;
    case 0x0057f97fu: goto L0057f97f;
    case 0x0057f984u: goto L0057f984;
    case 0x0057f987u: goto L0057f987;
    case 0x0057f989u: goto L0057f989;
    case 0x0057f98fu: goto L0057f98f;
    case 0x0057f992u: goto L0057f992;
    case 0x0057f994u: goto L0057f994;
    case 0x0057f995u: goto L0057f995;
    case 0x0057f998u: goto L0057f998;
    case 0x0057f99bu: goto L0057f99b;
    case 0x0057f99du: goto L0057f99d;
    case 0x0057f9a2u: goto L0057f9a2;
    case 0x0057f9a7u: goto L0057f9a7;
    case 0x0057f9abu: goto L0057f9ab;
    case 0x0057f9afu: goto L0057f9af;
    case 0x0057f9b3u: goto L0057f9b3;
    case 0x0057f9b9u: goto L0057f9b9;
    case 0x0057f9beu: goto L0057f9be;
    case 0x0057f9c1u: goto L0057f9c1;
    case 0x0057f9c3u: goto L0057f9c3;
    case 0x0057f9c9u: goto L0057f9c9;
    case 0x0057f9cdu: goto L0057f9cd;
    case 0x0057f9cfu: goto L0057f9cf;
    case 0x0057f9d0u: goto L0057f9d0;
    case 0x0057f9d3u: goto L0057f9d3;
    case 0x0057f9d6u: goto L0057f9d6;
    case 0x0057f9d8u: goto L0057f9d8;
    case 0x0057f9ddu: goto L0057f9dd;
    case 0x0057f9e2u: goto L0057f9e2;
    case 0x0057f9e6u: goto L0057f9e6;
    case 0x0057f9eau: goto L0057f9ea;
    case 0x0057f9eeu: goto L0057f9ee;
    case 0x0057f9f4u: goto L0057f9f4;
    case 0x0057f9f9u: goto L0057f9f9;
    case 0x0057f9fcu: goto L0057f9fc;
    case 0x0057f9feu: goto L0057f9fe;
    case 0x0057fa04u: goto L0057fa04;
    case 0x0057fa07u: goto L0057fa07;
    case 0x0057fa09u: goto L0057fa09;
    case 0x0057fa0au: goto L0057fa0a;
    case 0x0057fa0du: goto L0057fa0d;
    case 0x0057fa10u: goto L0057fa10;
    case 0x0057fa12u: goto L0057fa12;
    case 0x0057fa17u: goto L0057fa17;
    case 0x0057fa1cu: goto L0057fa1c;
    case 0x0057fa20u: goto L0057fa20;
    case 0x0057fa24u: goto L0057fa24;
    case 0x0057fa28u: goto L0057fa28;
    case 0x0057fa2eu: goto L0057fa2e;
    case 0x0057fa34u: goto L0057fa34;
    case 0x0057fa39u: goto L0057fa39;
    case 0x0057fa3cu: goto L0057fa3c;
    case 0x0057fa3eu: goto L0057fa3e;
    case 0x0057fa44u: goto L0057fa44;
    case 0x0057fa47u: goto L0057fa47;
    case 0x0057fa49u: goto L0057fa49;
    case 0x0057fa4au: goto L0057fa4a;
    case 0x0057fa4du: goto L0057fa4d;
    case 0x0057fa50u: goto L0057fa50;
    case 0x0057fa52u: goto L0057fa52;
    case 0x0057fa57u: goto L0057fa57;
    case 0x0057fa5cu: goto L0057fa5c;
    case 0x0057fa60u: goto L0057fa60;
    case 0x0057fa64u: goto L0057fa64;
    case 0x0057fa68u: goto L0057fa68;
    case 0x0057fa6eu: goto L0057fa6e;
    case 0x0057fa73u: goto L0057fa73;
    case 0x0057fa76u: goto L0057fa76;
    case 0x0057fa78u: goto L0057fa78;
    case 0x0057fa7eu: goto L0057fa7e;
    case 0x0057fa82u: goto L0057fa82;
    case 0x0057fa84u: goto L0057fa84;
    case 0x0057fa85u: goto L0057fa85;
    case 0x0057fa88u: goto L0057fa88;
    case 0x0057fa8bu: goto L0057fa8b;
    case 0x0057fa8du: goto L0057fa8d;
    case 0x0057fa92u: goto L0057fa92;
    case 0x0057fa97u: goto L0057fa97;
    case 0x0057fa9bu: goto L0057fa9b;
    case 0x0057fa9fu: goto L0057fa9f;
    case 0x0057faa3u: goto L0057faa3;
    case 0x0057faa9u: goto L0057faa9;
    case 0x0057faaeu: goto L0057faae;
    case 0x0057fab1u: goto L0057fab1;
    case 0x0057fab3u: goto L0057fab3;
    case 0x0057fab9u: goto L0057fab9;
    case 0x0057fabcu: goto L0057fabc;
    case 0x0057fabeu: goto L0057fabe;
    case 0x0057fabfu: goto L0057fabf;
    case 0x0057fac2u: goto L0057fac2;
    case 0x0057fac5u: goto L0057fac5;
    case 0x0057fac7u: goto L0057fac7;
    case 0x0057faccu: goto L0057facc;
    case 0x0057fad1u: goto L0057fad1;
    case 0x0057fad5u: goto L0057fad5;
    case 0x0057fad9u: goto L0057fad9;
    case 0x0057faddu: goto L0057fadd;
    case 0x0057fae3u: goto L0057fae3;
    case 0x0057fae9u: goto L0057fae9;
    case 0x0057faeeu: goto L0057faee;
    case 0x0057faf1u: goto L0057faf1;
    case 0x0057faf3u: goto L0057faf3;
    case 0x0057faf9u: goto L0057faf9;
    case 0x0057fafcu: goto L0057fafc;
    case 0x0057fafeu: goto L0057fafe;
    case 0x0057faffu: goto L0057faff;
    case 0x0057fb02u: goto L0057fb02;
    case 0x0057fb05u: goto L0057fb05;
    case 0x0057fb07u: goto L0057fb07;
    case 0x0057fb0cu: goto L0057fb0c;
    case 0x0057fb11u: goto L0057fb11;
    case 0x0057fb15u: goto L0057fb15;
    case 0x0057fb19u: goto L0057fb19;
    case 0x0057fb1du: goto L0057fb1d;
    case 0x0057fb23u: goto L0057fb23;
    case 0x0057fb28u: goto L0057fb28;
    case 0x0057fb2bu: goto L0057fb2b;
    case 0x0057fb2du: goto L0057fb2d;
    case 0x0057fb33u: goto L0057fb33;
    case 0x0057fb37u: goto L0057fb37;
    case 0x0057fb39u: goto L0057fb39;
    case 0x0057fb3au: goto L0057fb3a;
    case 0x0057fb3du: goto L0057fb3d;
    case 0x0057fb40u: goto L0057fb40;
    case 0x0057fb42u: goto L0057fb42;
    case 0x0057fb47u: goto L0057fb47;
    case 0x0057fb4cu: goto L0057fb4c;
    case 0x0057fb50u: goto L0057fb50;
    case 0x0057fb54u: goto L0057fb54;
    case 0x0057fb58u: goto L0057fb58;
    case 0x0057fb5eu: goto L0057fb5e;
    case 0x0057fb63u: goto L0057fb63;
    case 0x0057fb66u: goto L0057fb66;
    case 0x0057fb68u: goto L0057fb68;
    case 0x0057fb6eu: goto L0057fb6e;
    case 0x0057fb71u: goto L0057fb71;
    case 0x0057fb73u: goto L0057fb73;
    case 0x0057fb74u: goto L0057fb74;
    case 0x0057fb77u: goto L0057fb77;
    case 0x0057fb7au: goto L0057fb7a;
    case 0x0057fb7cu: goto L0057fb7c;
    case 0x0057fb81u: goto L0057fb81;
    case 0x0057fb86u: goto L0057fb86;
    case 0x0057fb8au: goto L0057fb8a;
    case 0x0057fb8eu: goto L0057fb8e;
    case 0x0057fb92u: goto L0057fb92;
    case 0x0057fb98u: goto L0057fb98;
    case 0x0057fb9eu: goto L0057fb9e;
    case 0x0057fba3u: goto L0057fba3;
    case 0x0057fba6u: goto L0057fba6;
    case 0x0057fba8u: goto L0057fba8;
    case 0x0057fbaeu: goto L0057fbae;
    case 0x0057fbb1u: goto L0057fbb1;
    case 0x0057fbb3u: goto L0057fbb3;
    case 0x0057fbb4u: goto L0057fbb4;
    case 0x0057fbb7u: goto L0057fbb7;
    case 0x0057fbbau: goto L0057fbba;
    case 0x0057fbbcu: goto L0057fbbc;
    case 0x0057fbc1u: goto L0057fbc1;
    case 0x0057fbc6u: goto L0057fbc6;
    case 0x0057fbcau: goto L0057fbca;
    case 0x0057fbceu: goto L0057fbce;
    case 0x0057fbd2u: goto L0057fbd2;
    case 0x0057fbd8u: goto L0057fbd8;
    case 0x0057fbddu: goto L0057fbdd;
    case 0x0057fbe0u: goto L0057fbe0;
    case 0x0057fbe2u: goto L0057fbe2;
    case 0x0057fbe8u: goto L0057fbe8;
    case 0x0057fbecu: goto L0057fbec;
    case 0x0057fbeeu: goto L0057fbee;
    case 0x0057fbefu: goto L0057fbef;
    case 0x0057fbf2u: goto L0057fbf2;
    case 0x0057fbf5u: goto L0057fbf5;
    case 0x0057fbf7u: goto L0057fbf7;
    case 0x0057fbfcu: goto L0057fbfc;
    case 0x0057fc01u: goto L0057fc01;
    case 0x0057fc05u: goto L0057fc05;
    case 0x0057fc09u: goto L0057fc09;
    case 0x0057fc0du: goto L0057fc0d;
    case 0x0057fc13u: goto L0057fc13;
    case 0x0057fc18u: goto L0057fc18;
    case 0x0057fc1bu: goto L0057fc1b;
    case 0x0057fc1du: goto L0057fc1d;
    case 0x0057fc23u: goto L0057fc23;
    case 0x0057fc26u: goto L0057fc26;
    case 0x0057fc28u: goto L0057fc28;
    case 0x0057fc29u: goto L0057fc29;
    case 0x0057fc2cu: goto L0057fc2c;
    case 0x0057fc2fu: goto L0057fc2f;
    case 0x0057fc31u: goto L0057fc31;
    case 0x0057fc36u: goto L0057fc36;
    case 0x0057fc3bu: goto L0057fc3b;
    case 0x0057fc3fu: goto L0057fc3f;
    case 0x0057fc43u: goto L0057fc43;
    case 0x0057fc47u: goto L0057fc47;
    case 0x0057fc4du: goto L0057fc4d;
    case 0x0057fc53u: goto L0057fc53;
    case 0x0057fc58u: goto L0057fc58;
    case 0x0057fc5bu: goto L0057fc5b;
    case 0x0057fc5du: goto L0057fc5d;
    case 0x0057fc63u: goto L0057fc63;
    case 0x0057fc66u: goto L0057fc66;
    case 0x0057fc68u: goto L0057fc68;
    case 0x0057fc69u: goto L0057fc69;
    case 0x0057fc6cu: goto L0057fc6c;
    case 0x0057fc6fu: goto L0057fc6f;
    case 0x0057fc71u: goto L0057fc71;
    case 0x0057fc76u: goto L0057fc76;
    case 0x0057fc7bu: goto L0057fc7b;
    case 0x0057fc7fu: goto L0057fc7f;
    case 0x0057fc83u: goto L0057fc83;
    case 0x0057fc87u: goto L0057fc87;
    case 0x0057fc8du: goto L0057fc8d;
    case 0x0057fc92u: goto L0057fc92;
    case 0x0057fc95u: goto L0057fc95;
    case 0x0057fc97u: goto L0057fc97;
    case 0x0057fc9du: goto L0057fc9d;
    case 0x0057fca1u: goto L0057fca1;
    case 0x0057fca3u: goto L0057fca3;
    case 0x0057fca4u: goto L0057fca4;
    case 0x0057fca7u: goto L0057fca7;
    case 0x0057fcaau: goto L0057fcaa;
    case 0x0057fcacu: goto L0057fcac;
    case 0x0057fcb1u: goto L0057fcb1;
    case 0x0057fcb6u: goto L0057fcb6;
    case 0x0057fcbau: goto L0057fcba;
    case 0x0057fcbeu: goto L0057fcbe;
    case 0x0057fcc2u: goto L0057fcc2;
    case 0x0057fcc8u: goto L0057fcc8;
    case 0x0057fccdu: goto L0057fccd;
    case 0x0057fcd0u: goto L0057fcd0;
    case 0x0057fcd2u: goto L0057fcd2;
    case 0x0057fcd8u: goto L0057fcd8;
    case 0x0057fcdbu: goto L0057fcdb;
    case 0x0057fcddu: goto L0057fcdd;
    case 0x0057fcdeu: goto L0057fcde;
    case 0x0057fce1u: goto L0057fce1;
    case 0x0057fce4u: goto L0057fce4;
    case 0x0057fceau: goto L0057fcea;
    case 0x0057fcefu: goto L0057fcef;
    case 0x0057fcf1u: goto L0057fcf1;
    case 0x0057fcf2u: goto L0057fcf2;
    case 0x0057fcf5u: goto L0057fcf5;
    case 0x0057fcf8u: goto L0057fcf8;
    case 0x0057fcfeu: goto L0057fcfe;
    case 0x0057fd03u: goto L0057fd03;
    case 0x0057fd05u: goto L0057fd05;
    case 0x0057fd06u: goto L0057fd06;
    case 0x0057fd09u: goto L0057fd09;
    case 0x0057fd0cu: goto L0057fd0c;
    case 0x0057fd11u: goto L0057fd11;
    case 0x0057fd16u: goto L0057fd16;
    case 0x0057fd18u: goto L0057fd18;
    case 0x0057fd1du: goto L0057fd1d;
    case 0x0057fd1fu: goto L0057fd1f;
    case 0x0057fd24u: goto L0057fd24;
    case 0x0057fd2au: goto L0057fd2a;
    case 0x0057fd2eu: goto L0057fd2e;
    case 0x0057fd30u: goto L0057fd30;
    case 0x0057fd31u: goto L0057fd31;
    case 0x0057fd34u: goto L0057fd34;
    case 0x0057fd37u: goto L0057fd37;
    case 0x0057fd3cu: goto L0057fd3c;
    case 0x0057fd3eu: goto L0057fd3e;
    case 0x0057fd43u: goto L0057fd43;
    case 0x0057fd46u: goto L0057fd46;
    case 0x0057fd4cu: goto L0057fd4c;
    case 0x0057fd4du: goto L0057fd4d;
    case 0x0057fd4fu: goto L0057fd4f;
    case 0x0057fd52u: goto L0057fd52;
    default:throw std::domain_error("recovery784 unsupported switch destination");}
  }
  L0057f95b: { // 0x57f95b: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0057f95d: { // 0x57f95d: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0057f962: { // 0x57f962: e879040b00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5765479u); flags=s.arithmetic_flags;
  }
  L0057f967: { // 0x57f967: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  L0057f96b: { // 0x57f96b: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  L0057f96f: { // 0x57f96f: df6c2404 FILD qword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0057f973: { // 0x57f973: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0057f979: { // 0x57f979: dc0508577800 FADD double ptr [0x00785708]
    const auto address=(0x00785708u);
    s.fp.add64(read64(m,address));
  }
  L0057f97f: { // 0x57f97f: e8ccb01e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5765508u); flags=s.arithmetic_flags;
  }
  L0057f984: { // 0x57f984: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  L0057f987: { // 0x57f987: 77d4 JA 0x0057f95d
    if(integer::condition("JA",flags)) goto L0057f95d;
  }
  L0057f989: { // 0x57f989: 8b0da8aaa300 MOV ECX,dword ptr [0x00a3aaa8]
    s.cx = m.r32((0x00a3aaa8u));
  }
  L0057f98f: { // 0x57f98f: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  L0057f992: { // 0x57f992: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057f994: { // 0x57f994: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057f995: { // 0x57f995: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0057f998: { // 0x57f998: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0057f99b: { // 0x57f99b: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0057f99d: { // 0x57f99d: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0057f9a2: { // 0x57f9a2: e839040b00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5765543u); flags=s.arithmetic_flags;
  }
  L0057f9a7: { // 0x57f9a7: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  L0057f9ab: { // 0x57f9ab: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  L0057f9af: { // 0x57f9af: df6c2404 FILD qword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0057f9b3: { // 0x57f9b3: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0057f9b9: { // 0x57f9b9: e892b01e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5765566u); flags=s.arithmetic_flags;
  }
  L0057f9be: { // 0x57f9be: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0057f9c1: { // 0x57f9c1: 77da JA 0x0057f99d
    if(integer::condition("JA",flags)) goto L0057f99d;
  }
  L0057f9c3: { // 0x57f9c3: 8b0da8aaa300 MOV ECX,dword ptr [0x00a3aaa8]
    s.cx = m.r32((0x00a3aaa8u));
  }
  L0057f9c9: { // 0x57f9c9: 8d440004 LEA EAX,[EAX + EAX*0x1 + 0x4]
    s.ax = (s.ax+(s.ax * 0x00000001u)+0x00000004u);
  }
  L0057f9cd: { // 0x57f9cd: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057f9cf: { // 0x57f9cf: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057f9d0: { // 0x57f9d0: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0057f9d3: { // 0x57f9d3: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0057f9d6: { // 0x57f9d6: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0057f9d8: { // 0x57f9d8: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0057f9dd: { // 0x57f9dd: e8fe030b00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5765602u); flags=s.arithmetic_flags;
  }
  L0057f9e2: { // 0x57f9e2: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  L0057f9e6: { // 0x57f9e6: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  L0057f9ea: { // 0x57f9ea: df6c2404 FILD qword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0057f9ee: { // 0x57f9ee: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0057f9f4: { // 0x57f9f4: e857b01e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5765625u); flags=s.arithmetic_flags;
  }
  L0057f9f9: { // 0x57f9f9: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0057f9fc: { // 0x57f9fc: 77da JA 0x0057f9d8
    if(integer::condition("JA",flags)) goto L0057f9d8;
  }
  L0057f9fe: { // 0x57f9fe: 8b0da8aaa300 MOV ECX,dword ptr [0x00a3aaa8]
    s.cx = m.r32((0x00a3aaa8u));
  }
  L0057fa04: { // 0x57fa04: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  L0057fa07: { // 0x57fa07: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057fa09: { // 0x57fa09: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057fa0a: { // 0x57fa0a: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0057fa0d: { // 0x57fa0d: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0057fa10: { // 0x57fa10: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0057fa12: { // 0x57fa12: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0057fa17: { // 0x57fa17: e8c4030b00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5765660u); flags=s.arithmetic_flags;
  }
  L0057fa1c: { // 0x57fa1c: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  L0057fa20: { // 0x57fa20: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  L0057fa24: { // 0x57fa24: df6c2404 FILD qword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0057fa28: { // 0x57fa28: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0057fa2e: { // 0x57fa2e: dc0508577800 FADD double ptr [0x00785708]
    const auto address=(0x00785708u);
    s.fp.add64(read64(m,address));
  }
  L0057fa34: { // 0x57fa34: e817b01e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5765689u); flags=s.arithmetic_flags;
  }
  L0057fa39: { // 0x57fa39: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  L0057fa3c: { // 0x57fa3c: 77d4 JA 0x0057fa12
    if(integer::condition("JA",flags)) goto L0057fa12;
  }
  L0057fa3e: { // 0x57fa3e: 8b0da8aaa300 MOV ECX,dword ptr [0x00a3aaa8]
    s.cx = m.r32((0x00a3aaa8u));
  }
  L0057fa44: { // 0x57fa44: 83c008 ADD EAX,0x8
    s.ax = integer::add(s.ax,0x00000008u,32,flags);
  }
  L0057fa47: { // 0x57fa47: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057fa49: { // 0x57fa49: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057fa4a: { // 0x57fa4a: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0057fa4d: { // 0x57fa4d: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0057fa50: { // 0x57fa50: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0057fa52: { // 0x57fa52: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0057fa57: { // 0x57fa57: e884030b00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5765724u); flags=s.arithmetic_flags;
  }
  L0057fa5c: { // 0x57fa5c: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  L0057fa60: { // 0x57fa60: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  L0057fa64: { // 0x57fa64: df6c2404 FILD qword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0057fa68: { // 0x57fa68: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0057fa6e: { // 0x57fa6e: e8ddaf1e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5765747u); flags=s.arithmetic_flags;
  }
  L0057fa73: { // 0x57fa73: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0057fa76: { // 0x57fa76: 77da JA 0x0057fa52
    if(integer::condition("JA",flags)) goto L0057fa52;
  }
  L0057fa78: { // 0x57fa78: 8b0da8aaa300 MOV ECX,dword ptr [0x00a3aaa8]
    s.cx = m.r32((0x00a3aaa8u));
  }
  L0057fa7e: { // 0x57fa7e: 8d440008 LEA EAX,[EAX + EAX*0x1 + 0x8]
    s.ax = (s.ax+(s.ax * 0x00000001u)+0x00000008u);
  }
  L0057fa82: { // 0x57fa82: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057fa84: { // 0x57fa84: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057fa85: { // 0x57fa85: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0057fa88: { // 0x57fa88: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0057fa8b: { // 0x57fa8b: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0057fa8d: { // 0x57fa8d: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0057fa92: { // 0x57fa92: e849030b00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5765783u); flags=s.arithmetic_flags;
  }
  L0057fa97: { // 0x57fa97: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  L0057fa9b: { // 0x57fa9b: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  L0057fa9f: { // 0x57fa9f: df6c2404 FILD qword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0057faa3: { // 0x57faa3: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0057faa9: { // 0x57faa9: e8a2af1e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5765806u); flags=s.arithmetic_flags;
  }
  L0057faae: { // 0x57faae: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0057fab1: { // 0x57fab1: 77da JA 0x0057fa8d
    if(integer::condition("JA",flags)) goto L0057fa8d;
  }
  L0057fab3: { // 0x57fab3: 8b0da8aaa300 MOV ECX,dword ptr [0x00a3aaa8]
    s.cx = m.r32((0x00a3aaa8u));
  }
  L0057fab9: { // 0x57fab9: 83c008 ADD EAX,0x8
    s.ax = integer::add(s.ax,0x00000008u,32,flags);
  }
  L0057fabc: { // 0x57fabc: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057fabe: { // 0x57fabe: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057fabf: { // 0x57fabf: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0057fac2: { // 0x57fac2: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0057fac5: { // 0x57fac5: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0057fac7: { // 0x57fac7: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0057facc: { // 0x57facc: e80f030b00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5765841u); flags=s.arithmetic_flags;
  }
  L0057fad1: { // 0x57fad1: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  L0057fad5: { // 0x57fad5: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  L0057fad9: { // 0x57fad9: df6c2404 FILD qword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0057fadd: { // 0x57fadd: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0057fae3: { // 0x57fae3: dc0508577800 FADD double ptr [0x00785708]
    const auto address=(0x00785708u);
    s.fp.add64(read64(m,address));
  }
  L0057fae9: { // 0x57fae9: e862af1e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5765870u); flags=s.arithmetic_flags;
  }
  L0057faee: { // 0x57faee: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  L0057faf1: { // 0x57faf1: 77d4 JA 0x0057fac7
    if(integer::condition("JA",flags)) goto L0057fac7;
  }
  L0057faf3: { // 0x57faf3: 8b0da8aaa300 MOV ECX,dword ptr [0x00a3aaa8]
    s.cx = m.r32((0x00a3aaa8u));
  }
  L0057faf9: { // 0x57faf9: 83c00b ADD EAX,0xb
    s.ax = integer::add(s.ax,0x0000000bu,32,flags);
  }
  L0057fafc: { // 0x57fafc: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057fafe: { // 0x57fafe: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057faff: { // 0x57faff: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0057fb02: { // 0x57fb02: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0057fb05: { // 0x57fb05: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0057fb07: { // 0x57fb07: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0057fb0c: { // 0x57fb0c: e8cf020b00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5765905u); flags=s.arithmetic_flags;
  }
  L0057fb11: { // 0x57fb11: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  L0057fb15: { // 0x57fb15: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  L0057fb19: { // 0x57fb19: df6c2404 FILD qword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0057fb1d: { // 0x57fb1d: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0057fb23: { // 0x57fb23: e828af1e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5765928u); flags=s.arithmetic_flags;
  }
  L0057fb28: { // 0x57fb28: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0057fb2b: { // 0x57fb2b: 77da JA 0x0057fb07
    if(integer::condition("JA",flags)) goto L0057fb07;
  }
  L0057fb2d: { // 0x57fb2d: 8b0da8aaa300 MOV ECX,dword ptr [0x00a3aaa8]
    s.cx = m.r32((0x00a3aaa8u));
  }
  L0057fb33: { // 0x57fb33: 8d44000b LEA EAX,[EAX + EAX*0x1 + 0xb]
    s.ax = (s.ax+(s.ax * 0x00000001u)+0x0000000bu);
  }
  L0057fb37: { // 0x57fb37: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057fb39: { // 0x57fb39: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057fb3a: { // 0x57fb3a: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0057fb3d: { // 0x57fb3d: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0057fb40: { // 0x57fb40: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0057fb42: { // 0x57fb42: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0057fb47: { // 0x57fb47: e894020b00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5765964u); flags=s.arithmetic_flags;
  }
  L0057fb4c: { // 0x57fb4c: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  L0057fb50: { // 0x57fb50: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  L0057fb54: { // 0x57fb54: df6c2404 FILD qword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0057fb58: { // 0x57fb58: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0057fb5e: { // 0x57fb5e: e8edae1e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5765987u); flags=s.arithmetic_flags;
  }
  L0057fb63: { // 0x57fb63: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0057fb66: { // 0x57fb66: 77da JA 0x0057fb42
    if(integer::condition("JA",flags)) goto L0057fb42;
  }
  L0057fb68: { // 0x57fb68: 8b0da8aaa300 MOV ECX,dword ptr [0x00a3aaa8]
    s.cx = m.r32((0x00a3aaa8u));
  }
  L0057fb6e: { // 0x57fb6e: 83c00b ADD EAX,0xb
    s.ax = integer::add(s.ax,0x0000000bu,32,flags);
  }
  L0057fb71: { // 0x57fb71: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057fb73: { // 0x57fb73: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057fb74: { // 0x57fb74: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0057fb77: { // 0x57fb77: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0057fb7a: { // 0x57fb7a: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0057fb7c: { // 0x57fb7c: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0057fb81: { // 0x57fb81: e85a020b00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5766022u); flags=s.arithmetic_flags;
  }
  L0057fb86: { // 0x57fb86: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  L0057fb8a: { // 0x57fb8a: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  L0057fb8e: { // 0x57fb8e: df6c2404 FILD qword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0057fb92: { // 0x57fb92: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0057fb98: { // 0x57fb98: dc0508577800 FADD double ptr [0x00785708]
    const auto address=(0x00785708u);
    s.fp.add64(read64(m,address));
  }
  L0057fb9e: { // 0x57fb9e: e8adae1e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5766051u); flags=s.arithmetic_flags;
  }
  L0057fba3: { // 0x57fba3: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  L0057fba6: { // 0x57fba6: 77d4 JA 0x0057fb7c
    if(integer::condition("JA",flags)) goto L0057fb7c;
  }
  L0057fba8: { // 0x57fba8: 8b0da8aaa300 MOV ECX,dword ptr [0x00a3aaa8]
    s.cx = m.r32((0x00a3aaa8u));
  }
  L0057fbae: { // 0x57fbae: 83c00e ADD EAX,0xe
    s.ax = integer::add(s.ax,0x0000000eu,32,flags);
  }
  L0057fbb1: { // 0x57fbb1: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057fbb3: { // 0x57fbb3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057fbb4: { // 0x57fbb4: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0057fbb7: { // 0x57fbb7: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0057fbba: { // 0x57fbba: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0057fbbc: { // 0x57fbbc: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0057fbc1: { // 0x57fbc1: e81a020b00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5766086u); flags=s.arithmetic_flags;
  }
  L0057fbc6: { // 0x57fbc6: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  L0057fbca: { // 0x57fbca: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  L0057fbce: { // 0x57fbce: df6c2404 FILD qword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0057fbd2: { // 0x57fbd2: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0057fbd8: { // 0x57fbd8: e873ae1e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5766109u); flags=s.arithmetic_flags;
  }
  L0057fbdd: { // 0x57fbdd: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0057fbe0: { // 0x57fbe0: 77da JA 0x0057fbbc
    if(integer::condition("JA",flags)) goto L0057fbbc;
  }
  L0057fbe2: { // 0x57fbe2: 8b0da8aaa300 MOV ECX,dword ptr [0x00a3aaa8]
    s.cx = m.r32((0x00a3aaa8u));
  }
  L0057fbe8: { // 0x57fbe8: 8d44000e LEA EAX,[EAX + EAX*0x1 + 0xe]
    s.ax = (s.ax+(s.ax * 0x00000001u)+0x0000000eu);
  }
  L0057fbec: { // 0x57fbec: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057fbee: { // 0x57fbee: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057fbef: { // 0x57fbef: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0057fbf2: { // 0x57fbf2: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0057fbf5: { // 0x57fbf5: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0057fbf7: { // 0x57fbf7: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0057fbfc: { // 0x57fbfc: e8df010b00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5766145u); flags=s.arithmetic_flags;
  }
  L0057fc01: { // 0x57fc01: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  L0057fc05: { // 0x57fc05: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  L0057fc09: { // 0x57fc09: df6c2404 FILD qword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0057fc0d: { // 0x57fc0d: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0057fc13: { // 0x57fc13: e838ae1e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5766168u); flags=s.arithmetic_flags;
  }
  L0057fc18: { // 0x57fc18: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0057fc1b: { // 0x57fc1b: 77da JA 0x0057fbf7
    if(integer::condition("JA",flags)) goto L0057fbf7;
  }
  L0057fc1d: { // 0x57fc1d: 8b0da8aaa300 MOV ECX,dword ptr [0x00a3aaa8]
    s.cx = m.r32((0x00a3aaa8u));
  }
  L0057fc23: { // 0x57fc23: 83c00e ADD EAX,0xe
    s.ax = integer::add(s.ax,0x0000000eu,32,flags);
  }
  L0057fc26: { // 0x57fc26: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057fc28: { // 0x57fc28: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057fc29: { // 0x57fc29: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0057fc2c: { // 0x57fc2c: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0057fc2f: { // 0x57fc2f: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0057fc31: { // 0x57fc31: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0057fc36: { // 0x57fc36: e8a5010b00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5766203u); flags=s.arithmetic_flags;
  }
  L0057fc3b: { // 0x57fc3b: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  L0057fc3f: { // 0x57fc3f: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  L0057fc43: { // 0x57fc43: df6c2404 FILD qword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0057fc47: { // 0x57fc47: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0057fc4d: { // 0x57fc4d: dc0508577800 FADD double ptr [0x00785708]
    const auto address=(0x00785708u);
    s.fp.add64(read64(m,address));
  }
  L0057fc53: { // 0x57fc53: e8f8ad1e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5766232u); flags=s.arithmetic_flags;
  }
  L0057fc58: { // 0x57fc58: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  L0057fc5b: { // 0x57fc5b: 77d4 JA 0x0057fc31
    if(integer::condition("JA",flags)) goto L0057fc31;
  }
  L0057fc5d: { // 0x57fc5d: 8b0da8aaa300 MOV ECX,dword ptr [0x00a3aaa8]
    s.cx = m.r32((0x00a3aaa8u));
  }
  L0057fc63: { // 0x57fc63: 83c016 ADD EAX,0x16
    s.ax = integer::add(s.ax,0x00000016u,32,flags);
  }
  L0057fc66: { // 0x57fc66: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057fc68: { // 0x57fc68: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057fc69: { // 0x57fc69: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0057fc6c: { // 0x57fc6c: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0057fc6f: { // 0x57fc6f: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0057fc71: { // 0x57fc71: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0057fc76: { // 0x57fc76: e865010b00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5766267u); flags=s.arithmetic_flags;
  }
  L0057fc7b: { // 0x57fc7b: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  L0057fc7f: { // 0x57fc7f: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  L0057fc83: { // 0x57fc83: df6c2404 FILD qword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0057fc87: { // 0x57fc87: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0057fc8d: { // 0x57fc8d: e8bead1e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5766290u); flags=s.arithmetic_flags;
  }
  L0057fc92: { // 0x57fc92: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0057fc95: { // 0x57fc95: 77da JA 0x0057fc71
    if(integer::condition("JA",flags)) goto L0057fc71;
  }
  L0057fc97: { // 0x57fc97: 8b0da8aaa300 MOV ECX,dword ptr [0x00a3aaa8]
    s.cx = m.r32((0x00a3aaa8u));
  }
  L0057fc9d: { // 0x57fc9d: 8d440016 LEA EAX,[EAX + EAX*0x1 + 0x16]
    s.ax = (s.ax+(s.ax * 0x00000001u)+0x00000016u);
  }
  L0057fca1: { // 0x57fca1: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057fca3: { // 0x57fca3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057fca4: { // 0x57fca4: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0057fca7: { // 0x57fca7: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0057fcaa: { // 0x57fcaa: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0057fcac: { // 0x57fcac: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0057fcb1: { // 0x57fcb1: e82a010b00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5766326u); flags=s.arithmetic_flags;
  }
  L0057fcb6: { // 0x57fcb6: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  L0057fcba: { // 0x57fcba: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  L0057fcbe: { // 0x57fcbe: df6c2404 FILD qword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0057fcc2: { // 0x57fcc2: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0057fcc8: { // 0x57fcc8: e883ad1e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5766349u); flags=s.arithmetic_flags;
  }
  L0057fccd: { // 0x57fccd: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0057fcd0: { // 0x57fcd0: 77da JA 0x0057fcac
    if(integer::condition("JA",flags)) goto L0057fcac;
  }
  L0057fcd2: { // 0x57fcd2: 8b0da8aaa300 MOV ECX,dword ptr [0x00a3aaa8]
    s.cx = m.r32((0x00a3aaa8u));
  }
  L0057fcd8: { // 0x57fcd8: 83c016 ADD EAX,0x16
    s.ax = integer::add(s.ax,0x00000016u,32,flags);
  }
  L0057fcdb: { // 0x57fcdb: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057fcdd: { // 0x57fcdd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057fcde: { // 0x57fcde: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0057fce1: { // 0x57fce1: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0057fce4: { // 0x57fce4: 8b0da8aaa300 MOV ECX,dword ptr [0x00a3aaa8]
    s.cx = m.r32((0x00a3aaa8u));
  }
  L0057fcea: { // 0x57fcea: b81d000000 MOV EAX,0x1d
    s.ax = 0x0000001du;
  }
  L0057fcef: { // 0x57fcef: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057fcf1: { // 0x57fcf1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057fcf2: { // 0x57fcf2: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0057fcf5: { // 0x57fcf5: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0057fcf8: { // 0x57fcf8: 8b0da8aaa300 MOV ECX,dword ptr [0x00a3aaa8]
    s.cx = m.r32((0x00a3aaa8u));
  }
  L0057fcfe: { // 0x57fcfe: b81c000000 MOV EAX,0x1c
    s.ax = 0x0000001cu;
  }
  L0057fd03: { // 0x57fd03: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057fd05: { // 0x57fd05: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057fd06: { // 0x57fd06: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0057fd09: { // 0x57fd09: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0057fd0c: { // 0x57fd0c: ba02000000 MOV EDX,0x2
    s.dx = 0x00000002u;
  }
  L0057fd11: { // 0x57fd11: b901000000 MOV ECX,0x1
    s.cx = 0x00000001u;
  }
  L0057fd16: { // 0x57fd16: eb26 JMP 0x0057fd3e
    goto L0057fd3e;
  }
  L0057fd18: { // 0x57fd18: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L0057fd1d: { // 0x57fd1d: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0057fd1f: { // 0x57fd1f: e86c68ffff CALL 0x00576590
    s.arithmetic_flags=flags; invoke(m,s,f,0x00576590u,5766436u); flags=s.arithmetic_flags;
  }
  L0057fd24: { // 0x57fd24: 8b0da8aaa300 MOV ECX,dword ptr [0x00a3aaa8]
    s.cx = m.r32((0x00a3aaa8u));
  }
  L0057fd2a: { // 0x57fd2a: 8d440022 LEA EAX,[EAX + EAX*0x1 + 0x22]
    s.ax = (s.ax+(s.ax * 0x00000001u)+0x00000022u);
  }
  L0057fd2e: { // 0x57fd2e: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057fd30: { // 0x57fd30: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057fd31: { // 0x57fd31: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0057fd34: { // 0x57fd34: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0057fd37: { // 0x57fd37: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L0057fd3c: { // 0x57fd3c: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0057fd3e: { // 0x57fd3e: e84d68ffff CALL 0x00576590
    s.arithmetic_flags=flags; invoke(m,s,f,0x00576590u,5766467u); flags=s.arithmetic_flags;
  }
  L0057fd43: { // 0x57fd43: 83c022 ADD EAX,0x22
    s.ax = integer::add(s.ax,0x00000022u,32,flags);
  }
  L0057fd46: { // 0x57fd46: 8b0da8aaa300 MOV ECX,dword ptr [0x00a3aaa8]
    s.cx = m.r32((0x00a3aaa8u));
  }
  L0057fd4c: { // 0x57fd4c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057fd4d: { // 0x57fd4d: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057fd4f: { // 0x57fd4f: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0057fd52: { // 0x57fd52: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
