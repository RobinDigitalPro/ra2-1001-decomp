#include "recovered/recovery_b530_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b530 {
namespace {
void f_0025a170(Memory&,State&,Frame&,const Operations&);
void f_000702c0(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_000713b0(Memory&,State&,Frame&,const Operations&);
void f_000713e0(Memory&,State&,Frame&,const Operations&);
void f_001cdbb0(Memory&,State&,Frame&,const Operations&);
void f_00005fe0(Memory&,State&,Frame&,const Operations&);
void f_00308f70(Memory&,State&,Frame&,const Operations&);
void f_000072f0(Memory&,State&,Frame&,const Operations&);
void f_00007310(Memory&,State&,Frame&,const Operations&);
void f_0007b650(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_0025a170(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0065a170: { // 0x65a170: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L0065a174: { // 0x65a174: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L0065a177: { // 0x65a177: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0065a178: { // 0x65a178: 8d8c8132060000 LEA ECX,[ECX + EAX*0x4 + 0x632]
    s.cx = (s.cx+(s.ax * 0x00000004u)+0x00000632u);
  }
  L0065a17f: { // 0x65a17f: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0065a180: { // 0x65a180: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0065a181: { // 0x65a181: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0065a186: { // 0x65a186: e875b3eeff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6660491u); flags=s.arithmetic_flags;
  }
  L0065a18b: { // 0x65a18b: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0065a18d: { // 0x65a18d: 8d442408 LEA EAX,[ESP + 0x8]
    s.ax = (f.sp+0x00000008u);
  }
  L0065a191: { // 0x65a191: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0065a192: { // 0x65a192: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0065a194: { // 0x65a194: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0065a196: { // 0x65a196: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),6660505u); flags=s.arithmetic_flags;
  }
  L0065a199: { // 0x65a199: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0065a19b: { // 0x65a19b: 8b7804 MOV EDI,dword ptr [EAX + 0x4]
    s.di = m.r32((s.ax+0x00000004u));
  }
  L0065a19e: { // 0x65a19e: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L0065a1a1: { // 0x65a1a1: 8b8640010000 MOV EAX,dword ptr [ESI + 0x140]
    s.ax = m.r32((s.si+0x00000140u));
  }
  L0065a1a7: { // 0x65a1a7: f6c405 TEST AH,0x5
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000005u),8,flags);
  }
  L0065a1aa: { // 0x65a1aa: 7406 JZ 0x0065a1b2
    if(integer::condition("JZ",flags)) goto L0065a1b2;
  }
  L0065a1ac: { // 0x65a1ac: 030de8e9a900 ADD ECX,dword ptr [0x00a9e9e8]
    s.cx = integer::add(s.cx,m.r32((0x00a9e9e8u)),32,flags);
  }
  L0065a1b2: { // 0x65a1b2: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0065a1b6: { // 0x65a1b6: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0065a1b8: { // 0x65a1b8: 8916 MOV dword ptr [ESI],EDX
    m.w32((s.si), s.dx);
  }
  L0065a1ba: { // 0x65a1ba: 897e04 MOV dword ptr [ESI + 0x4],EDI
    m.w32((s.si+0x00000004u), s.di);
  }
  L0065a1bd: { // 0x65a1bd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0065a1be: { // 0x65a1be: 894e08 MOV dword ptr [ESI + 0x8],ECX
    m.w32((s.si+0x00000008u), s.cx);
  }
  L0065a1c1: { // 0x65a1c1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0065a1c2: { // 0x65a1c2: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0065a1c5: { // 0x65a1c5: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
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
void f_000713b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004713b0: { // 0x004713b0: a0a885a200 MOV AL,[0x00a285a8]
    s.ax = with_al(s.ax, m.r8((0x00a285a8u)));
  }
  L004713b5: { // 0x004713b5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004713b6: { // 0x004713b6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004713b8: { // 0x004713b8: 741d JZ 0x004713d7
    if(integer::condition("JZ",flags)) goto L004713d7;
  }
  L004713ba: { // 0x004713ba: 8bb1e4000000 MOV ESI,dword ptr [ECX + 0xe4]
    s.si = m.r32((s.cx+0x000000e4u));
  }
  L004713c0: { // 0x004713c0: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L004713c2: { // 0x004713c2: 7413 JZ 0x004713d7
    if(integer::condition("JZ",flags)) goto L004713d7;
  }
  L004713c4: { // 0x004713c4: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004713c6: { // 0x004713c6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004713c8: { // 0x004713c8: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),4658123u); flags=s.arithmetic_flags;
  }
  L004713cb: { // 0x004713cb: 83f806 CMP EAX,0x6
    (void)integer::sub(s.ax,0x00000006u,32,flags);
  }
  L004713ce: { // 0x004713ce: 740b JZ 0x004713db
    if(integer::condition("JZ",flags)) goto L004713db;
  }
  L004713d0: { // 0x004713d0: 8b7630 MOV ESI,dword ptr [ESI + 0x30]
    s.si = m.r32((s.si+0x00000030u));
  }
  L004713d3: { // 0x004713d3: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L004713d5: { // 0x004713d5: 75ed JNZ 0x004713c4
    if(integer::condition("JNZ",flags)) goto L004713c4;
  }
  L004713d7: { // 0x004713d7: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004713d9: { // 0x004713d9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004713da: { // 0x004713da: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004713db: { // 0x004713db: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004713dd: { // 0x004713dd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004713de: { // 0x004713de: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000713e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004713e0: { // 0x004713e0: a0a885a200 MOV AL,[0x00a285a8]
    s.ax = with_al(s.ax, m.r8((0x00a285a8u)));
  }
  L004713e5: { // 0x004713e5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004713e6: { // 0x004713e6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004713e8: { // 0x004713e8: 742d JZ 0x00471417
    if(integer::condition("JZ",flags)) goto L00471417;
  }
  L004713ea: { // 0x004713ea: 8a442408 MOV AL,byte ptr [ESP + 0x8]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000008u)));
  }
  L004713ee: { // 0x004713ee: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004713f0: { // 0x004713f0: 7408 JZ 0x004713fa
    if(integer::condition("JZ",flags)) goto L004713fa;
  }
  L004713f2: { // 0x004713f2: 8bb1e8000000 MOV ESI,dword ptr [ECX + 0xe8]
    s.si = m.r32((s.cx+0x000000e8u));
  }
  L004713f8: { // 0x004713f8: eb06 JMP 0x00471400
    goto L00471400;
  }
  L004713fa: { // 0x004713fa: 8bb1e4000000 MOV ESI,dword ptr [ECX + 0xe4]
    s.si = m.r32((s.cx+0x000000e4u));
  }
  L00471400: { // 0x00471400: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00471402: { // 0x00471402: 7413 JZ 0x00471417
    if(integer::condition("JZ",flags)) goto L00471417;
  }
  L00471404: { // 0x00471404: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00471406: { // 0x00471406: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00471408: { // 0x00471408: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),4658187u); flags=s.arithmetic_flags;
  }
  L0047140b: { // 0x0047140b: 83f824 CMP EAX,0x24
    (void)integer::sub(s.ax,0x00000024u,32,flags);
  }
  L0047140e: { // 0x0047140e: 740d JZ 0x0047141d
    if(integer::condition("JZ",flags)) goto L0047141d;
  }
  L00471410: { // 0x00471410: 8b7630 MOV ESI,dword ptr [ESI + 0x30]
    s.si = m.r32((s.si+0x00000030u));
  }
  L00471413: { // 0x00471413: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00471415: { // 0x00471415: 75ed JNZ 0x00471404
    if(integer::condition("JNZ",flags)) goto L00471404;
  }
  L00471417: { // 0x00471417: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00471419: { // 0x00471419: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047141a: { // 0x0047141a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0047141d: { // 0x0047141d: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0047141f: { // 0x0047141f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00471420: { // 0x00471420: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_001cdbb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005cdbb0: { // 0x005cdbb0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L005cdbb4: { // 0x005cdbb4: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L005cdbb7: { // 0x005cdbb7: 894164 MOV dword ptr [ECX + 0x64],EAX
    m.w32((s.cx+0x00000064u), s.ax);
  }
  L005cdbba: { // 0x005cdbba: 7508 JNZ 0x005cdbc4
    if(integer::condition("JNZ",flags)) goto L005cdbc4;
  }
  L005cdbbc: { // 0x005cdbbc: 83c150 ADD ECX,0x50
    s.cx = integer::add(s.cx,0x00000050u,32,flags);
  }
  L005cdbbf: { // 0x005cdbbf: e81c84e3ff CALL 0x00405fe0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00405fe0u,6085572u); flags=s.arithmetic_flags;
  }
  L005cdbc4: { // 0x005cdbc4: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00005fe0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00405fe0: { // 0x405fe0: a1f8928100 MOV EAX,[0x008192f8]
    s.ax = m.r32((0x008192f8u));
  }
  L00405fe5: { // 0x405fe5: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00405fe6: { // 0x405fe6: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00405fe8: { // 0x405fe8: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00405fe9: { // 0x405fe9: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00405fea: { // 0x405fea: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00405fec: { // 0x405fec: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L00405fee: { // 0x405fee: 746c JZ 0x0040605c
    if(integer::condition("JZ",flags)) goto L0040605c;
  }
  L00405ff0: { // 0x405ff0: 817f0cec928100 CMP dword ptr [EDI + 0xc],0x8192ec
    (void)integer::sub(m.r32((s.di+0x0000000cu)),0x008192ecu,32,flags);
  }
  L00405ff7: { // 0x405ff7: 7563 JNZ 0x0040605c
    if(integer::condition("JNZ",flags)) goto L0040605c;
  }
  L00405ff9: { // 0x405ff9: 8b37 MOV ESI,dword ptr [EDI]
    s.si = m.r32((s.di));
  }
  L00405ffb: { // 0x405ffb: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L00405ffd: { // 0x405ffd: 745d JZ 0x0040605c
    if(integer::condition("JZ",flags)) goto L0040605c;
  }
  L00405fff: { // 0x405fff: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  L00406002: { // 0x406002: 8b4e24 MOV ECX,dword ptr [ESI + 0x24]
    s.cx = m.r32((s.si+0x00000024u));
  }
  L00406005: { // 0x406005: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00406007: { // 0x406007: 7551 JNZ 0x0040605a
    if(integer::condition("JNZ",flags)) goto L0040605a;
  }
  L00406009: { // 0x406009: 8b4f04 MOV ECX,dword ptr [EDI + 0x4]
    s.cx = m.r32((s.di+0x00000004u));
  }
  L0040600c: { // 0x40600c: 8b8638010000 MOV EAX,dword ptr [ESI + 0x138]
    s.ax = m.r32((s.si+0x00000138u));
  }
  L00406012: { // 0x406012: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00406014: { // 0x406014: 7544 JNZ 0x0040605a
    if(integer::condition("JNZ",flags)) goto L0040605a;
  }
  L00406016: { // 0x406016: f6461820 TEST byte ptr [ESI + 0x18],0x20
    (void)integer::logical((m.r8((s.si+0x00000018u)))&(0x00000020u),8,flags);
  }
  L0040601a: { // 0x40601a: 753e JNZ 0x0040605a
    if(integer::condition("JNZ",flags)) goto L0040605a;
  }
  L0040601c: { // 0x40601c: 8b86b0000000 MOV EAX,dword ptr [ESI + 0xb0]
    s.ax = m.r32((s.si+0x000000b0u));
  }
  L00406022: { // 0x406022: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00406024: { // 0x406024: 742c JZ 0x00406052
    if(integer::condition("JZ",flags)) goto L00406052;
  }
  L00406026: { // 0x406026: 3bb0c0000000 CMP ESI,dword ptr [EAX + 0xc0]
    (void)integer::sub(s.si,m.r32((s.ax+0x000000c0u)),32,flags);
  }
  L0040602c: { // 0x40602c: 7524 JNZ 0x00406052
    if(integer::condition("JNZ",flags)) goto L00406052;
  }
  L0040602e: { // 0x40602e: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00406030: { // 0x406030: e86bc6ffff CALL 0x004026a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004026a0u,4218933u); flags=s.arithmetic_flags;
  }
  L00406035: { // 0x406035: 8b5618 MOV EDX,dword ptr [ESI + 0x18]
    s.dx = m.r32((s.si+0x00000018u));
  }
  L00406038: { // 0x406038: 83ca60 OR EDX,0x60
    s.dx = integer::logical((s.dx)|(0x00000060u),32,flags);
  }
  L0040603b: { // 0x40603b: 895618 MOV dword ptr [ESI + 0x18],EDX
    m.w32((s.si+0x00000018u), s.dx);
  }
  L0040603e: { // 0x40603e: 8b8eb0000000 MOV ECX,dword ptr [ESI + 0xb0]
    s.cx = m.r32((s.si+0x000000b0u));
  }
  L00406044: { // 0x406044: e867c6ffff CALL 0x004026b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004026b0u,4218953u); flags=s.arithmetic_flags;
  }
  L00406049: { // 0x406049: 891f MOV dword ptr [EDI],EBX
    m.w32((s.di), s.bx);
  }
  L0040604b: { // 0x40604b: 895f08 MOV dword ptr [EDI + 0x8],EBX
    m.w32((s.di+0x00000008u), s.bx);
  }
  L0040604e: { // 0x40604e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0040604f: { // 0x40604f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00406050: { // 0x406050: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00406051: { // 0x406051: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00406052: { // 0x406052: 8b4618 MOV EAX,dword ptr [ESI + 0x18]
    s.ax = m.r32((s.si+0x00000018u));
  }
  L00406055: { // 0x406055: 0c60 OR AL,0x60
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000060u),8,flags));
  }
  L00406057: { // 0x406057: 894618 MOV dword ptr [ESI + 0x18],EAX
    m.w32((s.si+0x00000018u), s.ax);
  }
  L0040605a: { // 0x40605a: 891f MOV dword ptr [EDI],EBX
    m.w32((s.di), s.bx);
  }
  L0040605c: { // 0x40605c: 895f08 MOV dword ptr [EDI + 0x8],EBX
    m.w32((s.di+0x00000008u), s.bx);
  }
  L0040605f: { // 0x40605f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00406060: { // 0x406060: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00406061: { // 0x406061: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00406062: { // 0x406062: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00308f70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00708f70: { // 0x708f70: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00708f71: { // 0x708f71: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00708f72: { // 0x708f72: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00708f73: { // 0x708f73: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L00708f75: { // 0x708f75: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  L00708f77: { // 0x708f77: b95082ab00 MOV ECX,0xab8250
    s.cx = 0x00ab8250u;
  }
  L00708f7c: { // 0x708f7c: e86fe3cfff CALL 0x004072f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004072f0u,7376769u); flags=s.arithmetic_flags;
  }
  L00708f81: { // 0x708f81: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00708f83: { // 0x708f83: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00708f85: { // 0x708f85: 7437 JZ 0x00708fbe
    if(integer::condition("JZ",flags)) goto L00708fbe;
  }
  L00708f87: { // 0x708f87: 855e2c TEST dword ptr [ESI + 0x2c],EBX
    (void)integer::logical((m.r32((s.si+0x0000002cu)))&(s.bx),32,flags);
  }
  L00708f8a: { // 0x708f8a: 7425 JZ 0x00708fb1
    if(integer::condition("JZ",flags)) goto L00708fb1;
  }
  L00708f8c: { // 0x708f8c: 8b4620 MOV EAX,dword ptr [ESI + 0x20]
    s.ax = m.r32((s.si+0x00000020u));
  }
  L00708f8f: { // 0x708f8f: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  L00708f91: { // 0x708f91: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00708f93: { // 0x708f93: 751c JNZ 0x00708fb1
    if(integer::condition("JNZ",flags)) goto L00708fb1;
  }
  L00708f95: { // 0x708f95: 8b4e24 MOV ECX,dword ptr [ESI + 0x24]
    s.cx = m.r32((s.si+0x00000024u));
  }
  L00708f98: { // 0x708f98: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  L00708f9b: { // 0x708f9b: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00708f9d: { // 0x708f9d: 7512 JNZ 0x00708fb1
    if(integer::condition("JNZ",flags)) goto L00708fb1;
  }
  L00708f9f: { // 0x708f9f: 8b5628 MOV EDX,dword ptr [ESI + 0x28]
    s.dx = m.r32((s.si+0x00000028u));
  }
  L00708fa2: { // 0x708fa2: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  L00708fa5: { // 0x708fa5: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L00708fa7: { // 0x708fa7: 7508 JNZ 0x00708fb1
    if(integer::condition("JNZ",flags)) goto L00708fb1;
  }
  L00708fa9: { // 0x708fa9: 8d4e0c LEA ECX,[ESI + 0xc]
    s.cx = (s.si+0x0000000cu);
  }
  L00708fac: { // 0x708fac: e82fd0cfff CALL 0x00405fe0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00405fe0u,7376817u); flags=s.arithmetic_flags;
  }
  L00708fb1: { // 0x708fb1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00708fb3: { // 0x708fb3: e858e3cfff CALL 0x00407310
    s.arithmetic_flags=flags; invoke(m,s,f,0x00407310u,7376824u); flags=s.arithmetic_flags;
  }
  L00708fb8: { // 0x708fb8: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00708fba: { // 0x708fba: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00708fbc: { // 0x708fbc: 75c9 JNZ 0x00708f87
    if(integer::condition("JNZ",flags)) goto L00708f87;
  }
  L00708fbe: { // 0x708fbe: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00708fbf: { // 0x708fbf: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00708fc0: { // 0x708fc0: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00708fc1: { // 0x708fc1: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000072f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004072f0: { // 0x4072f0: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004072f2: { // 0x4072f2: 740b JZ 0x004072ff
    if(integer::condition("JZ",flags)) goto L004072ff;
  }
  L004072f4: { // 0x4072f4: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L004072f6: { // 0x4072f6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004072f8: { // 0x4072f8: 7407 JZ 0x00407301
    if(integer::condition("JZ",flags)) goto L00407301;
  }
  L004072fa: { // 0x4072fa: 3b4008 CMP EAX,dword ptr [EAX + 0x8]
    (void)integer::sub(s.ax,m.r32((s.ax+0x00000008u)),32,flags);
  }
  L004072fd: { // 0x4072fd: 7502 JNZ 0x00407301
    if(integer::condition("JNZ",flags)) goto L00407301;
  }
  L004072ff: { // 0x4072ff: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00407301: { // 0x407301: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00007310(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00407310: { // 0x407310: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00407312: { // 0x407312: 740b JZ 0x0040731f
    if(integer::condition("JZ",flags)) goto L0040731f;
  }
  L00407314: { // 0x407314: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00407316: { // 0x407316: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00407318: { // 0x407318: 7407 JZ 0x00407321
    if(integer::condition("JZ",flags)) goto L00407321;
  }
  L0040731a: { // 0x40731a: 3b4008 CMP EAX,dword ptr [EAX + 0x8]
    (void)integer::sub(s.ax,m.r32((s.ax+0x00000008u)),32,flags);
  }
  L0040731d: { // 0x40731d: 7502 JNZ 0x00407321
    if(integer::condition("JNZ",flags)) goto L00407321;
  }
  L0040731f: { // 0x40731f: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00407321: { // 0x407321: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0007b650(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0047b650: { // 0x47b650: 83ec08 SUB ESP, 0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0047b653: { // 0x47b653: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0047b654: { // 0x47b654: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0047b655: { // 0x47b655: 0fbf7124 MOVSX ESI, word ptr [ECX + 0x24]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000024u)),16));
  }
  L0047b659: { // 0x47b659: 0fbf7926 MOVSX EDI, word ptr [ECX + 0x26]
    s.di = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000026u)),16));
  }
  L0047b65d: { // 0x47b65d: c1e608 SHL ESI, 0x8
    s.si = integer::shift(s.si,0x00000008u,32,flags,integer::Shift::left);
  }
  L0047b660: { // 0x47b660: c1e708 SHL EDI, 0x8
    s.di = integer::shift(s.di,0x00000008u,32,flags,integer::Shift::left);
  }
  L0047b663: { // 0x47b663: 8d442408 LEA EAX, [ESP + 0x8]
    s.ax = (f.sp+0x00000008u);
  }
  L0047b667: { // 0x47b667: 81c680000000 ADD ESI, 0x80
    s.si = integer::add(s.si,0x00000080u,32,flags);
  }
  L0047b66d: { // 0x47b66d: 81c780000000 ADD EDI, 0x80
    s.di = integer::add(s.di,0x00000080u,32,flags);
  }
  L0047b673: { // 0x47b673: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0047b674: { // 0x47b674: 8974240c MOV dword ptr [ESP + 0xc], ESI
    m.w32((f.sp+0x0000000cu), s.si);
  }
  L0047b678: { // 0x47b678: 897c2410 MOV dword ptr [ESP + 0x10], EDI
    m.w32((f.sp+0x00000010u), s.di);
  }
  L0047b67c: { // 0x47b67c: e83f4cffff CALL 0x4702c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004702c0u,4699777u); flags=s.arithmetic_flags;
  }
  L0047b681: { // 0x47b681: 8b4c2414 MOV ECX, dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0047b685: { // 0x47b685: 8bd1 MOV EDX, ECX
    s.dx = s.cx;
  }
  L0047b687: { // 0x47b687: 8932 MOV dword ptr [EDX], ESI
    m.w32((s.dx), s.si);
  }
  L0047b689: { // 0x47b689: 897a04 MOV dword ptr [EDX + 0x4], EDI
    m.w32((s.dx+0x00000004u), s.di);
  }
  L0047b68c: { // 0x47b68c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0047b68d: { // 0x47b68d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047b68e: { // 0x47b68e: 894208 MOV dword ptr [EDX + 0x8], EAX
    m.w32((s.dx+0x00000008u), s.ax);
  }
  L0047b691: { // 0x47b691: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L0047b693: { // 0x47b693: 83c408 ADD ESP, 0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0047b696: { // 0x47b696: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 6660464u:f_0025a170(m,s,child,{});break;
case 4653760u:f_000702c0(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
case 5526784u:f_00145500(m,s,child,{});break;
case 4658096u:f_000713b0(m,s,child,{});break;
case 4658144u:f_000713e0(m,s,child,{});break;
case 6085552u:f_001cdbb0(m,s,child,{});break;
case 4218848u:f_00005fe0(m,s,child,{});break;
case 7376752u:f_00308f70(m,s,child,{});break;
case 4223728u:f_000072f0(m,s,child,{});break;
case 4223760u:f_00007310(m,s,child,{});break;
case 4699728u:f_0007b650(m,s,child,{});break;
default:throw std::domain_error("recovery530 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_006a65e0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006a65e0: { // 0x6a65e0: 83ec1c SUB ESP,0x1c
    f.sp = integer::sub(f.sp,0x0000001cu,32,flags);
  }
  L006a65e3: { // 0x6a65e3: 8b4144 MOV EAX,dword ptr [ECX + 0x44]
    s.ax = m.r32((s.cx+0x00000044u));
  }
  L006a65e6: { // 0x6a65e6: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006a65e7: { // 0x6a65e7: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L006a65eb: { // 0x6a65eb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006a65ec: { // 0x6a65ec: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006a65ed: { // 0x6a65ed: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L006a65f3: { // 0x6a65f3: e8783bfbff CALL 0x0065a170
    s.arithmetic_flags=flags; invoke(m,s,f,0x0065a170u,6972920u); flags=s.arithmetic_flags;
  }
  L006a65f8: { // 0x6a65f8: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L006a65fa: { // 0x6a65fa: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L006a65fc: { // 0x6a65fc: 89442408 MOV dword ptr [ESP + 0x8],EAX
    m.w32((f.sp+0x00000008u), s.ax);
  }
  L006a6600: { // 0x6a6600: 8b7204 MOV ESI,dword ptr [EDX + 0x4]
    s.si = m.r32((s.dx+0x00000004u));
  }
  L006a6603: { // 0x6a6603: 8974240c MOV dword ptr [ESP + 0xc],ESI
    m.w32((f.sp+0x0000000cu), s.si);
  }
  L006a6607: { // 0x6a6607: 8b4a08 MOV ECX,dword ptr [EDX + 0x8]
    s.cx = m.r32((s.dx+0x00000008u));
  }
  L006a660a: { // 0x6a660a: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006a660b: { // 0x6a660b: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L006a6611: { // 0x6a6611: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L006a6615: { // 0x6a6615: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L006a6617: { // 0x6a6617: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006a6619: { // 0x6a6619: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L006a661b: { // 0x6a661b: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006a661c: { // 0x6a661c: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L006a6622: { // 0x6a6622: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L006a6624: { // 0x6a6624: c1f908 SAR ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L006a6627: { // 0x6a6627: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L006a662a: { // 0x6a662a: 663b0db878aa00 CMP CX,word ptr [0x00aa78b8]
    (void)integer::sub((s.cx & 0xffffu),m.r16((0x00aa78b8u)),16,flags);
  }
  L006a6631: { // 0x6a6631: 66894c2404 MOV word ptr [ESP + 0x4],CX
    m.w16((f.sp+0x00000004u), (s.cx & 0xffffu));
  }
  L006a6636: { // 0x6a6636: 6689442406 MOV word ptr [ESP + 0x6],AX
    m.w16((f.sp+0x00000006u), (s.ax & 0xffffu));
  }
  L006a663b: { // 0x6a663b: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L006a663f: { // 0x6a663f: 89542404 MOV dword ptr [ESP + 0x4],EDX
    m.w32((f.sp+0x00000004u), s.dx);
  }
  L006a6643: { // 0x6a6643: 7509 JNZ 0x006a664e
    if(integer::condition("JNZ",flags)) goto L006a664e;
  }
  L006a6645: { // 0x6a6645: 663b05ba78aa00 CMP AX,word ptr [0x00aa78ba]
    (void)integer::sub((s.ax & 0xffffu),m.r16((0x00aa78bau)),16,flags);
  }
  L006a664c: { // 0x6a664c: 743a JZ 0x006a6688
    if(integer::condition("JZ",flags)) goto L006a6688;
  }
  L006a664e: { // 0x6a664e: 8d442404 LEA EAX,[ESP + 0x4]
    s.ax = (f.sp+0x00000004u);
  }
  L006a6652: { // 0x6a6652: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006a6657: { // 0x6a6657: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006a6658: { // 0x6a6658: e8a3eee9ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6973021u); flags=s.arithmetic_flags;
  }
  L006a665d: { // 0x6a665d: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L006a665f: { // 0x6a665f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006a6661: { // 0x6a6661: e84aaddcff CALL 0x004713b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004713b0u,6973030u); flags=s.arithmetic_flags;
  }
  L006a6666: { // 0x6a6666: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006a6668: { // 0x6a6668: 750c JNZ 0x006a6676
    if(integer::condition("JNZ",flags)) goto L006a6676;
  }
  L006a666a: { // 0x6a666a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006a666b: { // 0x6a666b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006a666d: { // 0x6a666d: e86eaddcff CALL 0x004713e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004713e0u,6973042u); flags=s.arithmetic_flags;
  }
  L006a6672: { // 0x6a6672: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006a6674: { // 0x6a6674: 7412 JZ 0x006a6688
    if(integer::condition("JZ",flags)) goto L006a6688;
  }
  L006a6676: { // 0x6a6676: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L006a6678: { // 0x6a6678: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006a667a: { // 0x6a667a: e83175f2ff CALL 0x005cdbb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005cdbb0u,6973055u); flags=s.arithmetic_flags;
  }
  L006a667f: { // 0x6a667f: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006a6681: { // 0x6a6681: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006a6682: { // 0x6a6682: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L006a6685: { // 0x6a6685: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006a6688: { // 0x6a6688: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L006a668d: { // 0x6a668d: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  L006a6691: { // 0x6a6691: e8da280600 CALL 0x00708f70
    s.arithmetic_flags=flags; invoke(m,s,f,0x00708f70u,6973078u); flags=s.arithmetic_flags;
  }
  L006a6696: { // 0x6a6696: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006a6698: { // 0x6a6698: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006a6699: { // 0x6a6699: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L006a669c: { // 0x6a669c: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
