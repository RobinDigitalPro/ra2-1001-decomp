#include "recovered/recovery_b202_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b202 {
namespace {
void f_0025a130(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_001475a0(Memory&,State&,Frame&,const Operations&);
void f_00297fb0(Memory&,State&,Frame&,const Operations&);
void f_000ba080(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void f_00227330(Memory&,State&,Frame&,const Operations&);
void f_00099da0(Memory&,State&,Frame&,const Operations&);
void f_0007c440(Memory&,State&,Frame&,const Operations&);
void f_0007c4a0(Memory&,State&,Frame&,const Operations&);
void f_0029e380(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

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
void f_001475a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005475a0: { // 0x5475a0: 83ec38 SUB ESP,0x38
    f.sp = integer::sub(f.sp,0x00000038u,32,flags);
  }
  L005475a3: { // 0x5475a3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005475a4: { // 0x5475a4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005475a5: { // 0x5475a5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005475a6: { // 0x5475a6: 8b742448 MOV ESI,dword ptr [ESP + 0x48]
    s.si = m.r32((f.sp+0x00000048u));
  }
  L005475aa: { // 0x5475aa: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005475ab: { // 0x5475ab: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L005475af: { // 0x5475af: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L005475b2: { // 0x5475b2: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L005475b3: { // 0x5475b3: f73d4878a500 IDIV dword ptr [0x00a57848]
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(m.r32((0x00a57848u)),32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L005475b9: { // 0x5475b9: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L005475bd: { // 0x5475bd: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L005475bf: { // 0x5475bf: 8b38 MOV EDI,dword ptr [EAX]
    s.di = m.r32((s.ax));
  }
  L005475c1: { // 0x5475c1: 8b5804 MOV EBX,dword ptr [EAX + 0x4]
    s.bx = m.r32((s.ax+0x00000004u));
  }
  L005475c4: { // 0x5475c4: 8b6808 MOV EBP,dword ptr [EAX + 0x8]
    s.bp = m.r32((s.ax+0x00000008u));
  }
  L005475c7: { // 0x5475c7: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L005475c9: { // 0x5475c9: e8e2091500 CALL 0x00697fb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00697fb0u,5535182u); flags=s.arithmetic_flags;
  }
  L005475ce: { // 0x5475ce: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L005475d0: { // 0x5475d0: b877777777 MOV EAX,0x77777777
    s.ax = 0x77777777u;
  }
  L005475d5: { // 0x5475d5: f7e9 IMUL ECX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.cx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  L005475d7: { // 0x5475d7: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L005475d9: { // 0x5475d9: c1fa04 SAR EDX,0x4
    s.dx = integer::shift(s.dx,0x00000004u,32,flags,integer::Shift::arithmetic_right);
  }
  L005475dc: { // 0x5475dc: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L005475de: { // 0x5475de: c1e91f SHR ECX,0x1f
    s.cx = integer::shift(s.cx,0x0000001fu,32,flags,integer::Shift::right);
  }
  L005475e1: { // 0x5475e1: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L005475e3: { // 0x5475e3: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L005475e5: { // 0x5475e5: c1e208 SHL EDX,0x8
    s.dx = integer::shift(s.dx,0x00000008u,32,flags,integer::Shift::left);
  }
  L005475e8: { // 0x5475e8: 03fa ADD EDI,EDX
    s.di = integer::add(s.di,s.dx,32,flags);
  }
  L005475ea: { // 0x5475ea: e8c1091500 CALL 0x00697fb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00697fb0u,5535215u); flags=s.arithmetic_flags;
  }
  L005475ef: { // 0x5475ef: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L005475f1: { // 0x5475f1: b877777777 MOV EAX,0x77777777
    s.ax = 0x77777777u;
  }
  L005475f6: { // 0x5475f6: f7e9 IMUL ECX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.cx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  L005475f8: { // 0x5475f8: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L005475fa: { // 0x5475fa: c1fa04 SAR EDX,0x4
    s.dx = integer::shift(s.dx,0x00000004u,32,flags,integer::Shift::arithmetic_right);
  }
  L005475fd: { // 0x5475fd: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L005475ff: { // 0x5475ff: c1e81f SHR EAX,0x1f
    s.ax = integer::shift(s.ax,0x0000001fu,32,flags,integer::Shift::right);
  }
  L00547602: { // 0x547602: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00547604: { // 0x547604: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L00547606: { // 0x547606: c1e208 SHL EDX,0x8
    s.dx = integer::shift(s.dx,0x00000008u,32,flags,integer::Shift::left);
  }
  L00547609: { // 0x547609: 03da ADD EBX,EDX
    s.bx = integer::add(s.bx,s.dx,32,flags);
  }
  L0054760b: { // 0x54760b: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0054760c: { // 0x54760c: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00547612: { // 0x547612: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00547614: { // 0x547614: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L00547616: { // 0x547616: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L00547618: { // 0x547618: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00547619: { // 0x547619: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0054761f: { // 0x54761f: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00547621: { // 0x547621: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00547623: { // 0x547623: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00547625: { // 0x547625: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00547626: { // 0x547626: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0054762c: { // 0x54762c: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0054762e: { // 0x54762e: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00547631: { // 0x547631: 6689442430 MOV word ptr [ESP + 0x30],AX
    m.w16((f.sp+0x00000030u), (s.ax & 0xffffu));
  }
  L00547636: { // 0x547636: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L00547639: { // 0x547639: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0054763a: { // 0x54763a: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00547640: { // 0x547640: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00547642: { // 0x547642: c1fd08 SAR EBP,0x8
    s.bp = integer::shift(s.bp,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00547645: { // 0x547645: c1f908 SAR ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00547648: { // 0x547648: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0054764b: { // 0x54764b: 66896c2428 MOV word ptr [ESP + 0x28],BP
    m.w16((f.sp+0x00000028u), (s.bp & 0xffffu));
  }
  L00547650: { // 0x547650: 66894c242a MOV word ptr [ESP + 0x2a],CX
    m.w16((f.sp+0x0000002au), (s.cx & 0xffffu));
  }
  L00547655: { // 0x547655: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L00547659: { // 0x547659: 6689442432 MOV word ptr [ESP + 0x32],AX
    m.w16((f.sp+0x00000032u), (s.ax & 0xffffu));
  }
  L0054765e: { // 0x54765e: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L00547662: { // 0x547662: 8b5c2432 MOV EBX,dword ptr [ESP + 0x32]
    s.bx = m.r32((f.sp+0x00000032u));
  }
  L00547666: { // 0x547666: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L00547668: { // 0x547668: 8b44242a MOV EAX,dword ptr [ESP + 0x2a]
    s.ax = m.r32((f.sp+0x0000002au));
  }
  L0054766c: { // 0x54766c: 2bc3 SUB EAX,EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L0054766e: { // 0x54766e: 668954241c MOV word ptr [ESP + 0x1c],DX
    m.w16((f.sp+0x0000001cu), (s.dx & 0xffffu));
  }
  L00547673: { // 0x547673: 668944241e MOV word ptr [ESP + 0x1e],AX
    m.w16((f.sp+0x0000001eu), (s.ax & 0xffffu));
  }
  L00547678: { // 0x547678: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L0054767c: { // 0x54767c: 8b44241e MOV EAX,dword ptr [ESP + 0x1e]
    s.ax = m.r32((f.sp+0x0000001eu));
  }
  L00547680: { // 0x547680: 83c2fe ADD EDX,-0x2
    s.dx = integer::add(s.dx,0xfffffffeu,32,flags);
  }
  L00547683: { // 0x547683: 83c0fe ADD EAX,-0x2
    s.ax = integer::add(s.ax,0xfffffffeu,32,flags);
  }
  L00547686: { // 0x547686: 6689542440 MOV word ptr [ESP + 0x40],DX
    m.w16((f.sp+0x00000040u), (s.dx & 0xffffu));
  }
  L0054768b: { // 0x54768b: 6689442442 MOV word ptr [ESP + 0x42],AX
    m.w16((f.sp+0x00000042u), (s.ax & 0xffffu));
  }
  L00547690: { // 0x547690: 0fbff5 MOVSX ESI,BP
    s.si = std::uint32_t(integer::sign_extend((s.bp & 0xffffu),16));
  }
  L00547693: { // 0x547693: 0fbfc1 MOVSX EAX,CX
    s.ax = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L00547696: { // 0x547696: 8d1430 LEA EDX,[EAX + ESI*0x1]
    s.dx = (s.ax+(s.si * 0x00000001u));
  }
  L00547699: { // 0x547699: 8b5c2414 MOV EBX,dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  L0054769d: { // 0x54769d: 8b8bf0000000 MOV ECX,dword ptr [EBX + 0xf0]
    s.cx = m.r32((s.bx+0x000000f0u));
  }
  L005476a3: { // 0x5476a3: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L005476a5: { // 0x5476a5: 0f8e2b030000 JLE 0x005479d6
    if(integer::condition("JLE",flags)) goto L005479d6;
  }
  L005476ab: { // 0x5476ab: 8bfe MOV EDI,ESI
    s.di = s.si;
  }
  L005476ad: { // 0x5476ad: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L005476af: { // 0x5476af: 3bf9 CMP EDI,ECX
    (void)integer::sub(s.di,s.cx,32,flags);
  }
  L005476b1: { // 0x5476b1: 0f8d1f030000 JGE 0x005479d6
    if(integer::condition("JGE",flags)) goto L005479d6;
  }
  L005476b7: { // 0x5476b7: 2bc6 SUB EAX,ESI
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L005476b9: { // 0x5476b9: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L005476bb: { // 0x5476bb: 0f8d15030000 JGE 0x005479d6
    if(integer::condition("JGE",flags)) goto L005479d6;
  }
  L005476c1: { // 0x5476c1: 8b83f4000000 MOV EAX,dword ptr [EBX + 0xf4]
    s.ax = m.r32((s.bx+0x000000f4u));
  }
  L005476c7: { // 0x5476c7: 8d0c41 LEA ECX,[ECX + EAX*0x2]
    s.cx = (s.cx+(s.ax * 0x00000002u));
  }
  L005476ca: { // 0x5476ca: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L005476cc: { // 0x5476cc: 0f8f04030000 JG 0x005479d6
    if(integer::condition("JG",flags)) goto L005479d6;
  }
  L005476d2: { // 0x5476d2: 8b442450 MOV EAX,dword ptr [ESP + 0x50]
    s.ax = m.r32((f.sp+0x00000050u));
  }
  L005476d6: { // 0x5476d6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005476d8: { // 0x5476d8: 0f84f8020000 JZ 0x005479d6
    if(integer::condition("JZ",flags)) goto L005479d6;
  }
  L005476de: { // 0x5476de: 83f80b CMP EAX,0xb
    (void)integer::sub(s.ax,0x0000000bu,32,flags);
  }
  L005476e1: { // 0x5476e1: 7d05 JGE 0x005476e8
    if(integer::condition("JGE",flags)) goto L005476e8;
  }
  L005476e3: { // 0x5476e3: 83f80a CMP EAX,0xa
    (void)integer::sub(s.ax,0x0000000au,32,flags);
  }
  L005476e6: { // 0x5476e6: 7e09 JLE 0x005476f1
    if(integer::condition("JLE",flags)) goto L005476f1;
  }
  L005476e8: { // 0x5476e8: b80a000000 MOV EAX,0xa
    s.ax = 0x0000000au;
  }
  L005476ed: { // 0x5476ed: 89442450 MOV dword ptr [ESP + 0x50],EAX
    m.w32((f.sp+0x00000050u), s.ax);
  }
  L005476f1: { // 0x5476f1: 8b15881b8200 MOV EDX,dword ptr [0x00821b88]
    s.dx = m.r32((0x00821b88u));
  }
  L005476f7: { // 0x5476f7: 8b3c85e8087900 MOV EDI,dword ptr [EAX*0x4 + 0x7908e8]
    s.di = m.r32(((s.ax * 0x00000004u)+0x007908e8u));
  }
  L005476fe: { // 0x5476fe: c7442410686ea500 MOV dword ptr [ESP + 0x10],0xa56e68
    m.w32((f.sp+0x00000010u), 0x00a56e68u);
  }
  L00547706: { // 0x547706: c744244c3869a500 MOV dword ptr [ESP + 0x4c],0xa56938
    m.w32((f.sp+0x0000004cu), 0x00a56938u);
  }
  L0054770e: { // 0x54770e: 8a8a32140000 MOV CL,byte ptr [EDX + 0x1432]
    s.cx = with_al(s.cx, m.r8((s.dx+0x00001432u)));
  }
  L00547714: { // 0x547714: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00547716: { // 0x547716: 752c JNZ 0x00547744
    if(integer::condition("JNZ",flags)) goto L00547744;
  }
  L00547718: { // 0x547718: 8a4c2458 MOV CL,byte ptr [ESP + 0x58]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000058u)));
  }
  L0054771c: { // 0x54771c: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0054771e: { // 0x54771e: 7424 JZ 0x00547744
    if(integer::condition("JZ",flags)) goto L00547744;
  }
  L00547720: { // 0x547720: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  L00547723: { // 0x547723: 7e1f JLE 0x00547744
    if(integer::condition("JLE",flags)) goto L00547744;
  }
  L00547725: { // 0x547725: 8b0485dc087900 MOV EAX,dword ptr [EAX*0x4 + 0x7908dc]
    s.ax = m.r32(((s.ax * 0x00000004u)+0x007908dcu));
  }
  L0054772c: { // 0x54772c: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L0054772e: { // 0x54772e: 8d0c85686ea500 LEA ECX,[EAX*0x4 + 0xa56e68]
    s.cx = ((s.ax * 0x00000004u)+0x00a56e68u);
  }
  L00547735: { // 0x547735: 8d14853869a500 LEA EDX,[EAX*0x4 + 0xa56938]
    s.dx = ((s.ax * 0x00000004u)+0x00a56938u);
  }
  L0054773c: { // 0x54773c: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L00547740: { // 0x547740: 8954244c MOV dword ptr [ESP + 0x4c],EDX
    m.w32((f.sp+0x0000004cu), s.dx);
  }
  L00547744: { // 0x547744: 8b4c244c MOV ECX,dword ptr [ESP + 0x4c]
    s.cx = m.r32((f.sp+0x0000004cu));
  }
  L00547748: { // 0x547748: 8b742454 MOV ESI,dword ptr [ESP + 0x54]
    s.si = m.r32((f.sp+0x00000054u));
  }
  L0054774c: { // 0x54774c: 83e904 SUB ECX,0x4
    s.cx = integer::sub(s.cx,0x00000004u,32,flags);
  }
  L0054774f: { // 0x54774f: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00547751: { // 0x547751: 894c244c MOV dword ptr [ESP + 0x4c],ECX
    m.w32((f.sp+0x0000004cu), s.cx);
  }
  L00547755: { // 0x547755: 7457 JZ 0x005477ae
    if(integer::condition("JZ",flags)) goto L005477ae;
  }
  L00547757: { // 0x547757: a1e4e0a100 MOV EAX,[0x00a1e0e4]
    s.ax = m.r32((0x00a1e0e4u));
  }
  L0054775c: { // 0x54775c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0054775e: { // 0x54775e: 7453 JZ 0x005477b3
    if(integer::condition("JZ",flags)) goto L005477b3;
  }
  L00547760: { // 0x547760: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L00547762: { // 0x547762: 7457 JZ 0x005477bb
    if(integer::condition("JZ",flags)) goto L005477bb;
  }
  L00547764: { // 0x547764: 8b4834 MOV ECX,dword ptr [EAX + 0x34]
    s.cx = m.r32((s.ax+0x00000034u));
  }
  L00547767: { // 0x547767: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L0054776c: { // 0x54776c: 8b89b8000000 MOV ECX,dword ptr [ECX + 0xb8]
    s.cx = m.r32((s.cx+0x000000b8u));
  }
  L00547772: { // 0x547772: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L00547774: { // 0x547774: 859614540000 TEST dword ptr [ESI + 0x5414],EDX
    (void)integer::logical((m.r32((s.si+0x00005414u)))&(s.dx),32,flags);
  }
  L0054777a: { // 0x54777a: 7406 JZ 0x00547782
    if(integer::condition("JZ",flags)) goto L00547782;
  }
  L0054777c: { // 0x54777c: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0054777e: { // 0x54777e: 89742454 MOV dword ptr [ESP + 0x54],ESI
    m.w32((f.sp+0x00000054u), s.si);
  }
  L00547782: { // 0x547782: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L00547784: { // 0x547784: 7435 JZ 0x005477bb
    if(integer::condition("JZ",flags)) goto L005477bb;
  }
  L00547786: { // 0x547786: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00547787: { // 0x547787: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00547789: { // 0x547789: e852d4f9ff CALL 0x004e4be0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e4be0u,5535630u); flags=s.arithmetic_flags;
  }
  L0054778e: { // 0x54778e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00547790: { // 0x547790: 741c JZ 0x005477ae
    if(integer::condition("JZ",flags)) goto L005477ae;
  }
  L00547792: { // 0x547792: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L00547797: { // 0x547797: 8a882b140000 MOV CL,byte ptr [EAX + 0x142b]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0000142bu)));
  }
  L0054779d: { // 0x54779d: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0054779f: { // 0x54779f: 740d JZ 0x005477ae
    if(integer::condition("JZ",flags)) goto L005477ae;
  }
  L005477a1: { // 0x5477a1: a1e4e0a100 MOV EAX,[0x00a1e0e4]
    s.ax = m.r32((0x00a1e0e4u));
  }
  L005477a6: { // 0x5477a6: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L005477a8: { // 0x5477a8: 89742454 MOV dword ptr [ESP + 0x54],ESI
    m.w32((f.sp+0x00000054u), s.si);
  }
  L005477ac: { // 0x5477ac: eb05 JMP 0x005477b3
    goto L005477b3;
  }
  L005477ae: { // 0x5477ae: a1e4e0a100 MOV EAX,[0x00a1e0e4]
    s.ax = m.r32((0x00a1e0e4u));
  }
  L005477b3: { // 0x5477b3: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L005477b5: { // 0x5477b5: 0f851b020000 JNZ 0x005479d6
    if(integer::condition("JNZ",flags)) goto L005479d6;
  }
  L005477bb: { // 0x5477bb: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005477bd: { // 0x5477bd: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L005477be: { // 0x5477be: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005477c0: { // 0x5477c0: 0f8410020000 JZ 0x005479d6
    if(integer::condition("JZ",flags)) goto L005479d6;
  }
  L005477c6: { // 0x5477c6: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L005477c7: { // 0x5477c7: 897c2418 MOV dword ptr [ESP + 0x18],EDI
    m.w32((f.sp+0x00000018u), s.di);
  }
  L005477cb: { // 0x5477cb: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L005477cf: { // 0x5477cf: 8b54244c MOV EDX,dword ptr [ESP + 0x4c]
    s.dx = m.r32((f.sp+0x0000004cu));
  }
  L005477d3: { // 0x5477d3: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L005477d5: { // 0x5477d5: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  L005477d8: { // 0x5477d8: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L005477dc: { // 0x5477dc: 83c204 ADD EDX,0x4
    s.dx = integer::add(s.dx,0x00000004u,32,flags);
  }
  L005477df: { // 0x5477df: 668b01 MOV AX,word ptr [ECX]
    s.ax = with_ax(s.ax, m.r16((s.cx)));
  }
  L005477e2: { // 0x5477e2: 668b4902 MOV CX,word ptr [ECX + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.cx+0x00000002u)));
  }
  L005477e6: { // 0x5477e6: 66034c242a ADD CX,word ptr [ESP + 0x2a]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((f.sp+0x0000002au)),16,flags));
  }
  L005477eb: { // 0x5477eb: 6603c5 ADD AX,BP
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),(s.bp & 0xffffu),16,flags));
  }
  L005477ee: { // 0x5477ee: 6689442438 MOV word ptr [ESP + 0x38],AX
    m.w16((f.sp+0x00000038u), (s.ax & 0xffffu));
  }
  L005477f3: { // 0x5477f3: 8954244c MOV dword ptr [ESP + 0x4c],EDX
    m.w32((f.sp+0x0000004cu), s.dx);
  }
  L005477f7: { // 0x5477f7: 8b93f0000000 MOV EDX,dword ptr [EBX + 0xf0]
    s.dx = m.r32((s.bx+0x000000f0u));
  }
  L005477fd: { // 0x5477fd: 66894c243a MOV word ptr [ESP + 0x3a],CX
    m.w16((f.sp+0x0000003au), (s.cx & 0xffffu));
  }
  L00547802: { // 0x547802: 8b7c2438 MOV EDI,dword ptr [ESP + 0x38]
    s.di = m.r32((f.sp+0x00000038u));
  }
  L00547806: { // 0x547806: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00547809: { // 0x547809: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L0054780c: { // 0x54780c: 897c2430 MOV dword ptr [ESP + 0x30],EDI
    m.w32((f.sp+0x00000030u), s.di);
  }
  L00547810: { // 0x547810: 8d3401 LEA ESI,[ECX + EAX*0x1]
    s.si = (s.cx+(s.ax * 0x00000001u));
  }
  L00547813: { // 0x547813: 3bf2 CMP ESI,EDX
    (void)integer::sub(s.si,s.dx,32,flags);
  }
  L00547815: { // 0x547815: 0f8eac010000 JLE 0x005479c7
    if(integer::condition("JLE",flags)) goto L005479c7;
  }
  L0054781b: { // 0x54781b: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0054781d: { // 0x54781d: 2bd9 SUB EBX,ECX
    s.bx = integer::sub(s.bx,s.cx,32,flags);
  }
  L0054781f: { // 0x54781f: 3bda CMP EBX,EDX
    (void)integer::sub(s.bx,s.dx,32,flags);
  }
  L00547821: { // 0x547821: 0f8d9c010000 JGE 0x005479c3
    if(integer::condition("JGE",flags)) goto L005479c3;
  }
  L00547827: { // 0x547827: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00547829: { // 0x547829: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L0054782b: { // 0x54782b: 0f8d92010000 JGE 0x005479c3
    if(integer::condition("JGE",flags)) goto L005479c3;
  }
  L00547831: { // 0x547831: 8b5c2414 MOV EBX,dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  L00547835: { // 0x547835: 8b8bf4000000 MOV ECX,dword ptr [EBX + 0xf4]
    s.cx = m.r32((s.bx+0x000000f4u));
  }
  L0054783b: { // 0x54783b: 8d144a LEA EDX,[EDX + ECX*0x2]
    s.dx = (s.dx+(s.cx * 0x00000002u));
  }
  L0054783e: { // 0x54783e: 3bf2 CMP ESI,EDX
    (void)integer::sub(s.si,s.dx,32,flags);
  }
  L00547840: { // 0x547840: 0f8f81010000 JG 0x005479c7
    if(integer::condition("JG",flags)) goto L005479c7;
  }
  L00547846: { // 0x547846: 0fbfcd MOVSX ECX,BP
    s.cx = std::uint32_t(integer::sign_extend((s.bp & 0xffffu),16));
  }
  L00547849: { // 0x547849: 8b742450 MOV ESI,dword ptr [ESP + 0x50]
    s.si = m.r32((f.sp+0x00000050u));
  }
  L0054784d: { // 0x54784d: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L0054784f: { // 0x54784f: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00547850: { // 0x547850: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L00547852: { // 0x547852: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00547854: { // 0x547854: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L00547856: { // 0x547856: 0f8f6b010000 JG 0x005479c7
    if(integer::condition("JG",flags)) goto L005479c7;
  }
  L0054785c: { // 0x54785c: 8b44243a MOV EAX,dword ptr [ESP + 0x3a]
    s.ax = m.r32((f.sp+0x0000003au));
  }
  L00547860: { // 0x547860: 8b4c242a MOV ECX,dword ptr [ESP + 0x2a]
    s.cx = m.r32((f.sp+0x0000002au));
  }
  L00547864: { // 0x547864: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L00547868: { // 0x547868: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L0054786a: { // 0x54786a: 2bfa SUB EDI,EDX
    s.di = integer::sub(s.di,s.dx,32,flags);
  }
  L0054786c: { // 0x54786c: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0054786f: { // 0x54786f: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00547872: { // 0x547872: 0fbfcf MOVSX ECX,DI
    s.cx = std::uint32_t(integer::sign_extend((s.di & 0xffffu),16));
  }
  L00547875: { // 0x547875: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L00547879: { // 0x547879: db442424 FILD dword ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.load_integer32(m.r32(address));
  }
  L0054787d: { // 0x54787d: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L00547881: { // 0x547881: db442424 FILD dword ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.load_integer32(m.r32(address));
  }
  L00547885: { // 0x547885: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L00547887: { // 0x547887: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L00547889: { // 0x547889: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L0054788b: { // 0x54788b: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L0054788d: { // 0x54788d: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0054788f: { // 0x54788f: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00547892: { // 0x547892: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00547894: { // 0x547894: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00547896: { // 0x547896: e8e527f7ff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,5535899u); flags=s.arithmetic_flags;
  }
  L0054789b: { // 0x54789b: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0054789e: { // 0x54789e: e8ad312200 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5535907u); flags=s.arithmetic_flags;
  }
  L005478a3: { // 0x5478a3: 0fbfd0 MOVSX EDX,AX
    s.dx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L005478a6: { // 0x5478a6: 3bd6 CMP EDX,ESI
    (void)integer::sub(s.dx,s.si,32,flags);
  }
  L005478a8: { // 0x5478a8: 0f8f19010000 JG 0x005479c7
    if(integer::condition("JG",flags)) goto L005479c7;
  }
  L005478ae: { // 0x5478ae: 8b4c2432 MOV ECX,dword ptr [ESP + 0x32]
    s.cx = m.r32((f.sp+0x00000032u));
  }
  L005478b2: { // 0x5478b2: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L005478b6: { // 0x5478b6: 0fbfd1 MOVSX EDX,CX
    s.dx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L005478b9: { // 0x5478b9: 0fbff0 MOVSX ESI,AX
    s.si = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L005478bc: { // 0x5478bc: c1e209 SHL EDX,0x9
    s.dx = integer::shift(s.dx,0x00000009u,32,flags,integer::Shift::left);
  }
  L005478bf: { // 0x5478bf: 03d6 ADD EDX,ESI
    s.dx = integer::add(s.dx,s.si,32,flags);
  }
  L005478c1: { // 0x5478c1: 7819 JS 0x005478dc
    if(integer::condition("JS",flags)) goto L005478dc;
  }
  L005478c3: { // 0x5478c3: 81fa00000400 CMP EDX,0x40000
    (void)integer::sub(s.dx,0x00040000u,32,flags);
  }
  L005478c9: { // 0x5478c9: 7d11 JGE 0x005478dc
    if(integer::condition("JGE",flags)) goto L005478dc;
  }
  L005478cb: { // 0x5478cb: 8bb338010000 MOV ESI,dword ptr [EBX + 0x138]
    s.si = m.r32((s.bx+0x00000138u));
  }
  L005478d1: { // 0x5478d1: 8b1496 MOV EDX,dword ptr [ESI + EDX*0x4]
    s.dx = m.r32((s.si+(s.dx * 0x00000004u)));
  }
  L005478d4: { // 0x5478d4: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L005478d6: { // 0x5478d6: 7404 JZ 0x005478dc
    if(integer::condition("JZ",flags)) goto L005478dc;
  }
  L005478d8: { // 0x5478d8: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L005478da: { // 0x5478da: eb0a JMP 0x005478e6
    goto L005478e6;
  }
  L005478dc: { // 0x5478dc: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L005478e1: { // 0x5478e1: be1076a500 MOV ESI,0xa57610
    s.si = 0x00a57610u;
  }
  L005478e6: { // 0x5478e6: 8a542464 MOV DL,byte ptr [ESP + 0x64]
    s.dx = with_al(s.dx, m.r8((f.sp+0x00000064u)));
  }
  L005478ea: { // 0x5478ea: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L005478ec: { // 0x5478ec: 747a JZ 0x00547968
    if(integer::condition("JZ",flags)) goto L00547968;
  }
  L005478ee: { // 0x5478ee: 8b15881b8200 MOV EDX,dword ptr [0x00821b88]
    s.dx = m.r32((0x00821b88u));
  }
  L005478f4: { // 0x5478f4: 80ba3214000000 CMP byte ptr [EDX + 0x1432],0x0
    (void)integer::sub(m.r8((s.dx+0x00001432u)),0x00000000u,8,flags);
  }
  L005478fb: { // 0x5478fb: 746b JZ 0x00547968
    if(integer::condition("JZ",flags)) goto L00547968;
  }
  L005478fd: { // 0x5478fd: 8b7c2440 MOV EDI,dword ptr [ESP + 0x40]
    s.di = m.r32((f.sp+0x00000040u));
  }
  L00547901: { // 0x547901: 8b542442 MOV EDX,dword ptr [ESP + 0x42]
    s.dx = m.r32((f.sp+0x00000042u));
  }
  L00547905: { // 0x547905: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  L00547907: { // 0x547907: 8b7c244c MOV EDI,dword ptr [ESP + 0x4c]
    s.di = m.r32((f.sp+0x0000004cu));
  }
  L0054790b: { // 0x54790b: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L0054790d: { // 0x54790d: 668bd1 MOV DX,CX
    s.dx = with_ax(s.dx, (s.cx & 0xffffu));
  }
  L00547910: { // 0x547910: 668b0f MOV CX,word ptr [EDI]
    s.cx = with_ax(s.cx, m.r16((s.di)));
  }
  L00547913: { // 0x547913: 6603c8 ADD CX,AX
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),(s.ax & 0xffffu),16,flags));
  }
  L00547916: { // 0x547916: 668b4702 MOV AX,word ptr [EDI + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.di+0x00000002u)));
  }
  L0054791a: { // 0x54791a: 6603c2 ADD AX,DX
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),(s.dx & 0xffffu),16,flags));
  }
  L0054791d: { // 0x54791d: 66894c2458 MOV word ptr [ESP + 0x58],CX
    m.w16((f.sp+0x00000058u), (s.cx & 0xffffu));
  }
  L00547922: { // 0x547922: 668944245a MOV word ptr [ESP + 0x5a],AX
    m.w16((f.sp+0x0000005au), (s.ax & 0xffffu));
  }
  L00547927: { // 0x547927: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0054792a: { // 0x54792a: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L0054792d: { // 0x54792d: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L00547930: { // 0x547930: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00547932: { // 0x547932: 7814 JS 0x00547948
    if(integer::condition("JS",flags)) goto L00547948;
  }
  L00547934: { // 0x547934: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00547939: { // 0x547939: 7d0d JGE 0x00547948
    if(integer::condition("JGE",flags)) goto L00547948;
  }
  L0054793b: { // 0x54793b: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L00547941: { // 0x547941: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L00547944: { // 0x547944: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00547946: { // 0x547946: 750e JNZ 0x00547956
    if(integer::condition("JNZ",flags)) goto L00547956;
  }
  L00547948: { // 0x547948: 8b442458 MOV EAX,dword ptr [ESP + 0x58]
    s.ax = m.r32((f.sp+0x00000058u));
  }
  L0054794c: { // 0x54794c: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L00547951: { // 0x547951: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L00547956: { // 0x547956: 0fbe881b010000 MOVSX ECX,byte ptr [EAX + 0x11b]
    s.cx = std::uint32_t(integer::sign_extend(m.r8((s.ax+0x0000011bu)),8));
  }
  L0054795d: { // 0x54795d: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L00547961: { // 0x547961: 83c203 ADD EDX,0x3
    s.dx = integer::add(s.dx,0x00000003u,32,flags);
  }
  L00547964: { // 0x547964: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L00547966: { // 0x547966: 7f5f JG 0x005479c7
    if(integer::condition("JG",flags)) goto L005479c7;
  }
  L00547968: { // 0x547968: 8b9640010000 MOV EDX,dword ptr [ESI + 0x140]
    s.dx = m.r32((s.si+0x00000140u));
  }
  L0054796e: { // 0x54796e: 8a4c2460 MOV CL,byte ptr [ESP + 0x60]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000060u)));
  }
  L00547972: { // 0x547972: 83e2bf AND EDX,0xffffffbf
    s.dx = integer::logical((s.dx)&(0xffffffbfu),32,flags);
  }
  L00547975: { // 0x547975: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00547977: { // 0x547977: 899640010000 MOV dword ptr [ESI + 0x140],EDX
    m.w32((s.si+0x00000140u), s.dx);
  }
  L0054797d: { // 0x54797d: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L0054797f: { // 0x54797f: 7427 JZ 0x005479a8
    if(integer::condition("JZ",flags)) goto L005479a8;
  }
  L00547981: { // 0x547981: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L00547983: { // 0x547983: 7404 JZ 0x00547989
    if(integer::condition("JZ",flags)) goto L00547989;
  }
  L00547985: { // 0x547985: a802 TEST AL,0x2
    (void)integer::logical(((s.ax & 0xffu))&(0x00000002u),8,flags);
  }
  L00547987: { // 0x547987: 753e JNZ 0x005479c7
    if(integer::condition("JNZ",flags)) goto L005479c7;
  }
  L00547989: { // 0x547989: f6862c01000008 TEST byte ptr [ESI + 0x12c],0x8
    (void)integer::logical((m.r8((s.si+0x0000012cu)))&(0x00000008u),8,flags);
  }
  L00547990: { // 0x547990: 7435 JZ 0x005479c7
    if(integer::condition("JZ",flags)) goto L005479c7;
  }
  L00547992: { // 0x547992: 8b442454 MOV EAX,dword ptr [ESP + 0x54]
    s.ax = m.r32((f.sp+0x00000054u));
  }
  L00547996: { // 0x547996: 8d4c2430 LEA ECX,[ESP + 0x30]
    s.cx = (f.sp+0x00000030u);
  }
  L0054799a: { // 0x54799a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0054799b: { // 0x54799b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0054799c: { // 0x54799c: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L005479a1: { // 0x5479a1: e82a25f5ff CALL 0x00499ed0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00499ed0u,5536166u); flags=s.arithmetic_flags;
  }
  L005479a6: { // 0x5479a6: eb1f JMP 0x005479c7
    goto L005479c7;
  }
  L005479a8: { // 0x5479a8: 8b542468 MOV EDX,dword ptr [ESP + 0x68]
    s.dx = m.r32((f.sp+0x00000068u));
  }
  L005479ac: { // 0x5479ac: 8b442454 MOV EAX,dword ptr [ESP + 0x54]
    s.ax = m.r32((f.sp+0x00000054u));
  }
  L005479b0: { // 0x5479b0: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005479b1: { // 0x5479b1: 8d4c2434 LEA ECX,[ESP + 0x34]
    s.cx = (f.sp+0x00000034u);
  }
  L005479b5: { // 0x5479b5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005479b6: { // 0x5479b6: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005479b7: { // 0x5479b7: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L005479bc: { // 0x5479bc: e86ff90d00 CALL 0x00627330
    s.arithmetic_flags=flags; invoke(m,s,f,0x00627330u,5536193u); flags=s.arithmetic_flags;
  }
  L005479c1: { // 0x5479c1: eb04 JMP 0x005479c7
    goto L005479c7;
  }
  L005479c3: { // 0x5479c3: 8b5c2414 MOV EBX,dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  L005479c7: { // 0x5479c7: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L005479cb: { // 0x5479cb: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L005479cc: { // 0x5479cc: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L005479d0: { // 0x5479d0: 0f85f5fdffff JNZ 0x005477cb
    if(integer::condition("JNZ",flags)) goto L005477cb;
  }
  L005479d6: { // 0x5479d6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005479d7: { // 0x5479d7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005479d8: { // 0x5479d8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005479d9: { // 0x5479d9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005479da: { // 0x5479da: 83c438 ADD ESP,0x38
    f.sp = integer::add(f.sp,0x00000038u,32,flags);
  }
  L005479dd: { // 0x5479dd: c22000 RET 0x20
    s.arithmetic_flags=flags; finish(m,s,f,32u); return;
  }
}
void f_00297fb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00697fb0: { // 0x697fb0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00697fb3: { // 0x697fb3: 81f9d8020000 CMP ECX,0x2d8
    (void)integer::sub(s.cx,0x000002d8u,32,flags);
  }
  L00697fb9: { // 0x697fb9: 894c2404 MOV dword ptr [ESP + 0x4],ECX
    m.w32((f.sp+0x00000004u), s.cx);
  }
  L00697fbd: { // 0x697fbd: c744240000000000 MOV dword ptr [ESP],0x0
    m.w32((f.sp), 0x00000000u);
  }
  L00697fc5: { // 0x697fc5: 7c08 JL 0x00697fcf
    if(integer::condition("JL",flags)) goto L00697fcf;
  }
  L00697fc7: { // 0x697fc7: c744240001000000 MOV dword ptr [ESP],0x1
    m.w32((f.sp), 0x00000001u);
  }
  L00697fcf: { // 0x697fcf: db442404 FILD dword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load_integer32(m.r32(address));
  }
  L00697fd3: { // 0x697fd3: dc0d905faa00 FMUL double ptr [0x00aa5f90]
    const auto address=(0x00aa5f90u);
    s.fp.multiply64(read64(m,address));
  }
  L00697fd9: { // 0x697fd9: da442400 FIADD dword ptr [ESP]
    const auto address=(f.sp);
    floating_b61::fp_extended::add_integer32(s.fp,m.r32(address));
  }
  L00697fdd: { // 0x697fdd: dc0528577800 FADD double ptr [0x00785728]
    const auto address=(0x00785728u);
    s.fp.add64(read64(m,address));
  }
  L00697fe3: { // 0x697fe3: e8682a0d00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6914024u); flags=s.arithmetic_flags;
  }
  L00697fe8: { // 0x697fe8: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00697feb: { // 0x697feb: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000ba080(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004ba080: { // 0x4ba080: dd442404 FLD double ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load64(read64(m,address));
  }
  L004ba084: { // 0x4ba084: d81538577800 FCOM float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.compare32(m.r32(address));
  }
  L004ba08a: { // 0x4ba08a: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004ba08c: { // 0x4ba08c: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L004ba08f: { // 0x4ba08f: 7409 JZ 0x004ba09a
    if(integer::condition("JZ",flags)) goto L004ba09a;
  }
  L004ba091: { // 0x4ba091: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L004ba093: { // 0x4ba093: d90538577800 FLD float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.load32(m.r32(address));
  }
  L004ba099: { // 0x4ba099: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004ba09a: { // 0x4ba09a: d81538577800 FCOM float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.compare32(m.r32(address));
  }
  L004ba0a0: { // 0x4ba0a0: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004ba0a2: { // 0x4ba0a2: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L004ba0a5: { // 0x4ba0a5: 7406 JZ 0x004ba0ad
    if(integer::condition("JZ",flags)) goto L004ba0ad;
  }
  L004ba0a7: { // 0x4ba0a7: dc0d78857800 FMUL double ptr [0x00788578]
    const auto address=(0x00788578u);
    s.fp.multiply64(read64(m,address));
  }
  L004ba0ad: { // 0x4ba0ad: d95c2404 FSTP float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L004ba0b1: { // 0x4ba0b1: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L004ba0b5: { // 0x4ba0b5: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004ba0b7: { // 0x4ba0b7: 81e1ffff7f00 AND ECX,0x7fffff
    s.cx = integer::logical((s.cx)&(0x007fffffu),32,flags);
  }
  L004ba0bd: { // 0x4ba0bd: c1e817 SHR EAX,0x17
    s.ax = integer::shift(s.ax,0x00000017u,32,flags,integer::Shift::right);
  }
  L004ba0c0: { // 0x4ba0c0: 83e87f SUB EAX,0x7f
    s.ax = integer::sub(s.ax,0x0000007fu,32,flags);
  }
  L004ba0c3: { // 0x4ba0c3: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L004ba0c5: { // 0x4ba0c5: 7406 JZ 0x004ba0cd
    if(integer::condition("JZ",flags)) goto L004ba0cd;
  }
  L004ba0c7: { // 0x4ba0c7: 81c900008000 OR ECX,0x800000
    s.cx = integer::logical((s.cx)|(0x00800000u),32,flags);
  }
  L004ba0cd: { // 0x4ba0cd: 66d1f8 SAR AX,0x1
    s.ax = with_ax(s.ax, integer::shift((s.ax & 0xffffu),0x00000001u,16,flags,integer::Shift::arithmetic_right));
  }
  L004ba0d0: { // 0x4ba0d0: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L004ba0d3: { // 0x4ba0d3: c1e90a SHR ECX,0xa
    s.cx = integer::shift(s.cx,0x0000000au,32,flags,integer::Shift::right);
  }
  L004ba0d6: { // 0x4ba0d6: 83c07f ADD EAX,0x7f
    s.ax = integer::add(s.ax,0x0000007fu,32,flags);
  }
  L004ba0d9: { // 0x4ba0d9: 8b0c8d3c018000 MOV ECX,dword ptr [ECX*0x4 + 0x80013c]
    s.cx = m.r32(((s.cx * 0x00000004u)+0x0080013cu));
  }
  L004ba0e0: { // 0x4ba0e0: c1e017 SHL EAX,0x17
    s.ax = integer::shift(s.ax,0x00000017u,32,flags,integer::Shift::left);
  }
  L004ba0e3: { // 0x4ba0e3: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L004ba0e5: { // 0x4ba0e5: 894c2404 MOV dword ptr [ESP + 0x4],ECX
    m.w32((f.sp+0x00000004u), s.cx);
  }
  L004ba0e9: { // 0x4ba0e9: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L004ba0ed: { // 0x4ba0ed: c3 RET
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
void f_00227330(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00627330: { // 0x00627330: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L00627334: { // 0x00627334: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L00627338: { // 0x00627338: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00627339: { // 0x00627339: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L0062733d: { // 0x0062733d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0062733e: { // 0x0062733e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0062733f: { // 0x0062733f: e85c2ae7ff CALL 0x00499da0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00499da0u,6452036u); flags=s.arithmetic_flags;
  }
  L00627344: { // 0x00627344: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00627346: { // 0x00627346: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  L00627349: { // 0x00627349: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
void f_00099da0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00499da0: { // 0x499da0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00499da1: { // 0x499da1: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00499da2: { // 0x499da2: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00499da3: { // 0x499da3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00499da4: { // 0x499da4: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L00499da8: { // 0x499da8: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00499da9: { // 0x499da9: e852b70a00 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4824494u); flags=s.arithmetic_flags;
  }
  L00499dae: { // 0x499dae: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00499db0: { // 0x499db0: 8b8640010000 MOV EAX,dword ptr [ESI + 0x140]
    s.ax = m.r32((s.si+0x00000140u));
  }
  L00499db6: { // 0x499db6: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00499db8: { // 0x499db8: d1eb SHR EBX,0x1
    s.bx = integer::shift(s.bx,0x00000001u,32,flags,integer::Shift::right);
  }
  L00499dba: { // 0x499dba: f6d3 NOT BL
    s.bx = with_al(s.bx, (~((s.bx & 0xffu))&integer::mask(8)));
  }
  L00499dbc: { // 0x499dbc: 80e301 AND BL,0x1
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))&(0x00000001u),8,flags));
  }
  L00499dbf: { // 0x499dbf: a802 TEST AL,0x2
    (void)integer::logical(((s.ax & 0xffu))&(0x00000002u),8,flags);
  }
  L00499dc1: { // 0x499dc1: 7410 JZ 0x00499dd3
    if(integer::condition("JZ",flags)) goto L00499dd3;
  }
  L00499dc3: { // 0x499dc3: 8a8e2c010000 MOV CL,byte ptr [ESI + 0x12c]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000012cu)));
  }
  L00499dc9: { // 0x499dc9: c644241400 MOV byte ptr [ESP + 0x14],0x0
    m.w8((f.sp+0x00000014u), 0x00000000u);
  }
  L00499dce: { // 0x499dce: f6c108 TEST CL,0x8
    (void)integer::logical(((s.cx & 0xffu))&(0x00000008u),8,flags);
  }
  L00499dd1: { // 0x499dd1: 7505 JNZ 0x00499dd8
    if(integer::condition("JNZ",flags)) goto L00499dd8;
  }
  L00499dd3: { // 0x499dd3: c644241401 MOV byte ptr [ESP + 0x14],0x1
    m.w8((f.sp+0x00000014u), 0x00000001u);
  }
  L00499dd8: { // 0x499dd8: 8a4c2414 MOV CL,byte ptr [ESP + 0x14]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000014u)));
  }
  L00499ddc: { // 0x499ddc: 24bf AND AL,0xbf
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000bfu),8,flags));
  }
  L00499dde: { // 0x499dde: 0c02 OR AL,0x2
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000002u),8,flags));
  }
  L00499de0: { // 0x499de0: 884c240c MOV byte ptr [ESP + 0xc],CL
    m.w8((f.sp+0x0000000cu), (s.cx & 0xffu));
  }
  L00499de4: { // 0x499de4: 898640010000 MOV dword ptr [ESI + 0x140],EAX
    m.w32((s.si+0x00000140u), s.ax);
  }
  L00499dea: { // 0x499dea: 8a44241c MOV AL,byte ptr [ESP + 0x1c]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000001cu)));
  }
  L00499dee: { // 0x499dee: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00499df0: { // 0x499df0: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00499df2: { // 0x499df2: 7407 JZ 0x00499dfb
    if(integer::condition("JZ",flags)) goto L00499dfb;
  }
  L00499df4: { // 0x499df4: e8a726feff CALL 0x0047c4a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047c4a0u,4824569u); flags=s.arithmetic_flags;
  }
  L00499df9: { // 0x499df9: eb05 JMP 0x00499e00
    goto L00499e00;
  }
  L00499dfb: { // 0x499dfb: e84026feff CALL 0x0047c440
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047c440u,4824576u); flags=s.arithmetic_flags;
  }
  L00499e00: { // 0x499e00: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L00499e06: { // 0x499e06: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00499e08: { // 0x499e08: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00499e09: { // 0x499e09: e872452000 CALL 0x0069e380
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069e380u,4824590u); flags=s.arithmetic_flags;
  }
  L00499e0e: { // 0x499e0e: 3a8620010000 CMP AL,byte ptr [ESI + 0x120]
    (void)integer::sub((s.ax & 0xffu),m.r8((s.si+0x00000120u)),8,flags);
  }
  L00499e14: { // 0x499e14: 740b JZ 0x00499e21
    if(integer::condition("JZ",flags)) goto L00499e21;
  }
  L00499e16: { // 0x499e16: c644241401 MOV byte ptr [ESP + 0x14],0x1
    m.w8((f.sp+0x00000014u), 0x00000001u);
  }
  L00499e1b: { // 0x499e1b: 888620010000 MOV byte ptr [ESI + 0x120],AL
    m.w8((s.si+0x00000120u), (s.ax & 0xffu));
  }
  L00499e21: { // 0x499e21: 80be20010000ff CMP byte ptr [ESI + 0x120],0xff
    (void)integer::sub(m.r8((s.si+0x00000120u)),0x000000ffu,8,flags);
  }
  L00499e28: { // 0x499e28: 750e JNZ 0x00499e38
    if(integer::condition("JNZ",flags)) goto L00499e38;
  }
  L00499e2a: { // 0x499e2a: 8b862c010000 MOV EAX,dword ptr [ESI + 0x12c]
    s.ax = m.r32((s.si+0x0000012cu));
  }
  L00499e30: { // 0x499e30: 0c10 OR AL,0x10
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000010u),8,flags));
  }
  L00499e32: { // 0x499e32: 89862c010000 MOV dword ptr [ESI + 0x12c],EAX
    m.w32((s.si+0x0000012cu), s.ax);
  }
  L00499e38: { // 0x499e38: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L00499e3e: { // 0x499e3e: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00499e40: { // 0x499e40: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00499e41: { // 0x499e41: e83a452000 CALL 0x0069e380
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069e380u,4824646u); flags=s.arithmetic_flags;
  }
  L00499e46: { // 0x499e46: 8ac8 MOV CL,AL
    s.cx = with_al(s.cx, (s.ax & 0xffu));
  }
  L00499e48: { // 0x499e48: 8a8621010000 MOV AL,byte ptr [ESI + 0x121]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000121u)));
  }
  L00499e4e: { // 0x499e4e: 3ac8 CMP CL,AL
    (void)integer::sub((s.cx & 0xffu),(s.ax & 0xffu),8,flags);
  }
  L00499e50: { // 0x499e50: 740e JZ 0x00499e60
    if(integer::condition("JZ",flags)) goto L00499e60;
  }
  L00499e52: { // 0x499e52: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00499e54: { // 0x499e54: 888e21010000 MOV byte ptr [ESI + 0x121],CL
    m.w8((s.si+0x00000121u), (s.cx & 0xffu));
  }
  L00499e5a: { // 0x499e5a: 88442414 MOV byte ptr [ESP + 0x14],AL
    m.w8((f.sp+0x00000014u), (s.ax & 0xffu));
  }
  L00499e5e: { // 0x499e5e: eb04 JMP 0x00499e64
    goto L00499e64;
  }
  L00499e60: { // 0x499e60: 8a442414 MOV AL,byte ptr [ESP + 0x14]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000014u)));
  }
  L00499e64: { // 0x499e64: 80be21010000ff CMP byte ptr [ESI + 0x121],0xff
    (void)integer::sub(m.r8((s.si+0x00000121u)),0x000000ffu,8,flags);
  }
  L00499e6b: { // 0x499e6b: 7507 JNZ 0x00499e74
    if(integer::condition("JNZ",flags)) goto L00499e74;
  }
  L00499e6d: { // 0x499e6d: 838e4001000001 OR dword ptr [ESI + 0x140],0x1
    m.w32((s.si+0x00000140u), integer::logical((m.r32((s.si+0x00000140u)))|(0x00000001u),32,flags));
  }
  L00499e74: { // 0x499e74: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00499e76: { // 0x499e76: 7425 JZ 0x00499e9d
    if(integer::condition("JZ",flags)) goto L00499e9d;
  }
  L00499e78: { // 0x499e78: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L00499e7e: { // 0x499e7e: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00499e7f: { // 0x499e7f: e88c652000 CALL 0x006a0410
    s.arithmetic_flags=flags; invoke(m,s,f,0x006a0410u,4824708u); flags=s.arithmetic_flags;
  }
  L00499e84: { // 0x499e84: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  L00499e88: { // 0x499e88: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00499e8c: { // 0x499e8c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00499e8d: { // 0x499e8d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00499e8e: { // 0x499e8e: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00499e8f: { // 0x499e8f: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00499e94: { // 0x499e94: e877b40c00 CALL 0x00565310
    s.arithmetic_flags=flags; invoke(m,s,f,0x00565310u,4824729u); flags=s.arithmetic_flags;
  }
  L00499e99: { // 0x499e99: 8a442414 MOV AL,byte ptr [ESP + 0x14]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000014u)));
  }
  L00499e9d: { // 0x499e9d: f6864001000002 TEST byte ptr [ESI + 0x140],0x2
    (void)integer::logical((m.r8((s.si+0x00000140u)))&(0x00000002u),8,flags);
  }
  L00499ea4: { // 0x499ea4: 741c JZ 0x00499ec2
    if(integer::condition("JZ",flags)) goto L00499ec2;
  }
  L00499ea6: { // 0x499ea6: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L00499ea8: { // 0x499ea8: 7418 JZ 0x00499ec2
    if(integer::condition("JZ",flags)) goto L00499ec2;
  }
  L00499eaa: { // 0x499eaa: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L00499eb0: { // 0x499eb0: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00499eb2: { // 0x499eb2: f6c610 TEST DH,0x10
    (void)integer::logical((((s.dx >> 8) & 0xffu))&(0x00000010u),8,flags);
  }
  L00499eb5: { // 0x499eb5: 740b JZ 0x00499ec2
    if(integer::condition("JZ",flags)) goto L00499ec2;
  }
  L00499eb7: { // 0x499eb7: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00499eb9: { // 0x499eb9: e8421bfeff CALL 0x0047ba00
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047ba00u,4824766u); flags=s.arithmetic_flags;
  }
  L00499ebe: { // 0x499ebe: 8a442414 MOV AL,byte ptr [ESP + 0x14]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000014u)));
  }
  L00499ec2: { // 0x499ec2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00499ec3: { // 0x499ec3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00499ec4: { // 0x499ec4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00499ec5: { // 0x499ec5: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00499ec6: { // 0x499ec6: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
void f_0007c440(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0047c440: { // 0x47c440: 83b93001000001 CMP dword ptr [ECX + 0x130],0x1
    (void)integer::sub(m.r32((s.cx+0x00000130u)),0x00000001u,32,flags);
  }
  L0047c447: { // 0x47c447: 750a JNZ 0x0047c453
    if(integer::condition("JNZ",flags)) goto L0047c453;
  }
  L0047c449: { // 0x47c449: c7813001000000000000 MOV dword ptr [ECX + 0x130],0x0
    m.w32((s.cx+0x00000130u), 0x00000000u);
  }
  L0047c453: { // 0x47c453: 8b8130010000 MOV EAX,dword ptr [ECX + 0x130]
    s.ax = m.r32((s.cx+0x00000130u));
  }
  L0047c459: { // 0x47c459: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0047c45a: { // 0x47c45a: 898130010000 MOV dword ptr [ECX + 0x130],EAX
    m.w32((s.cx+0x00000130u), s.ax);
  }
  L0047c460: { // 0x47c460: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0047c462: { // 0x47c462: 8b812c010000 MOV EAX,dword ptr [ECX + 0x12c]
    s.ax = m.r32((s.cx+0x0000012cu));
  }
  L0047c468: { // 0x47c468: a808 TEST AL,0x8
    (void)integer::logical(((s.ax & 0xffu))&(0x00000008u),8,flags);
  }
  L0047c46a: { // 0x47c46a: 7404 JZ 0x0047c470
    if(integer::condition("JZ",flags)) goto L0047c470;
  }
  L0047c46c: { // 0x47c46c: a810 TEST AL,0x10
    (void)integer::logical(((s.ax & 0xffu))&(0x00000010u),8,flags);
  }
  L0047c46e: { // 0x47c46e: 750d JNZ 0x0047c47d
    if(integer::condition("JNZ",flags)) goto L0047c47d;
  }
  L0047c470: { // 0x47c470: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0047c472: { // 0x47c472: 7f25 JG 0x0047c499
    if(integer::condition("JG",flags)) goto L0047c499;
  }
  L0047c474: { // 0x47c474: 0c18 OR AL,0x18
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000018u),8,flags));
  }
  L0047c476: { // 0x47c476: 89812c010000 MOV dword ptr [ECX + 0x12c],EAX
    m.w32((s.cx+0x0000012cu), s.ax);
  }
  L0047c47c: { // 0x47c47c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047c47d: { // 0x47c47d: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0047c47f: { // 0x47c47f: 7f18 JG 0x0047c499
    if(integer::condition("JG",flags)) goto L0047c499;
  }
  L0047c481: { // 0x47c481: 8b8140010000 MOV EAX,dword ptr [ECX + 0x140]
    s.ax = m.r32((s.cx+0x00000140u));
  }
  L0047c487: { // 0x47c487: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0047c489: { // 0x47c489: 83e220 AND EDX,0x20
    s.dx = integer::logical((s.dx)&(0x00000020u),32,flags);
  }
  L0047c48c: { // 0x47c48c: 80fa20 CMP DL,0x20
    (void)integer::sub((s.dx & 0xffu),0x00000020u,8,flags);
  }
  L0047c48f: { // 0x47c48f: 7508 JNZ 0x0047c499
    if(integer::condition("JNZ",flags)) goto L0047c499;
  }
  L0047c491: { // 0x47c491: 24df AND AL,0xdf
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000dfu),8,flags));
  }
  L0047c493: { // 0x47c493: 898140010000 MOV dword ptr [ECX + 0x140],EAX
    m.w32((s.cx+0x00000140u), s.ax);
  }
  L0047c499: { // 0x47c499: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0007c4a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0047c4a0: { // 0x47c4a0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0047c4a1: { // 0x47c4a1: 8bb130010000 MOV ESI,dword ptr [ECX + 0x130]
    s.si = m.r32((s.cx+0x00000130u));
  }
  L0047c4a7: { // 0x47c4a7: 83feff CMP ESI,-0x1
    (void)integer::sub(s.si,0xffffffffu,32,flags);
  }
  L0047c4aa: { // 0x47c4aa: 750a JNZ 0x0047c4b6
    if(integer::condition("JNZ",flags)) goto L0047c4b6;
  }
  L0047c4ac: { // 0x47c4ac: c7813001000000000000 MOV dword ptr [ECX + 0x130],0x0
    m.w32((s.cx+0x00000130u), 0x00000000u);
  }
  L0047c4b6: { // 0x47c4b6: 8b8130010000 MOV EAX,dword ptr [ECX + 0x130]
    s.ax = m.r32((s.cx+0x00000130u));
  }
  L0047c4bc: { // 0x47c4bc: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0047c4bd: { // 0x47c4bd: 898130010000 MOV dword ptr [ECX + 0x130],EAX
    m.w32((s.cx+0x00000130u), s.ax);
  }
  L0047c4c3: { // 0x47c4c3: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0047c4c5: { // 0x47c4c5: 8b8134010000 MOV EAX,dword ptr [ECX + 0x134]
    s.ax = m.r32((s.cx+0x00000134u));
  }
  L0047c4cb: { // 0x47c4cb: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L0047c4cd: { // 0x47c4cd: 7e06 JLE 0x0047c4d5
    if(integer::condition("JLE",flags)) goto L0047c4d5;
  }
  L0047c4cf: { // 0x47c4cf: 898130010000 MOV dword ptr [ECX + 0x130],EAX
    m.w32((s.cx+0x00000130u), s.ax);
  }
  L0047c4d5: { // 0x47c4d5: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0047c4d7: { // 0x47c4d7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047c4d8: { // 0x47c4d8: 7f18 JG 0x0047c4f2
    if(integer::condition("JG",flags)) goto L0047c4f2;
  }
  L0047c4da: { // 0x47c4da: 8b8130010000 MOV EAX,dword ptr [ECX + 0x130]
    s.ax = m.r32((s.cx+0x00000130u));
  }
  L0047c4e0: { // 0x47c4e0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0047c4e2: { // 0x47c4e2: 7e0e JLE 0x0047c4f2
    if(integer::condition("JLE",flags)) goto L0047c4f2;
  }
  L0047c4e4: { // 0x47c4e4: 8b8140010000 MOV EAX,dword ptr [ECX + 0x140]
    s.ax = m.r32((s.cx+0x00000140u));
  }
  L0047c4ea: { // 0x47c4ea: 0c20 OR AL,0x20
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000020u),8,flags));
  }
  L0047c4ec: { // 0x47c4ec: 898140010000 MOV dword ptr [ECX + 0x140],EAX
    m.w32((s.cx+0x00000140u), s.ax);
  }
  L0047c4f2: { // 0x47c4f2: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0029e380(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0069e380: { // 0x69e380: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0069e381: { // 0x69e381: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0069e382: { // 0x69e382: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0069e383: { // 0x69e383: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L0069e387: { // 0x69e387: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0069e388: { // 0x69e388: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0069e389: { // 0x69e389: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e38e: { // 0x69e38e: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L0069e390: { // 0x69e390: 83cfff OR EDI,0xffffffff
    s.di = integer::logical((s.di)|(0xffffffffu),32,flags);
  }
  L0069e393: { // 0x69e393: e86871eaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6939544u); flags=s.arithmetic_flags;
  }
  L0069e398: { // 0x69e398: 8a4c2418 MOV CL,byte ptr [ESP + 0x18]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000018u)));
  }
  L0069e39c: { // 0x69e39c: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0069e39e: { // 0x69e39e: 0f84d0010000 JZ 0x0069e574
    if(integer::condition("JZ",flags)) goto L0069e574;
  }
  L0069e3a4: { // 0x69e3a4: 8b8040010000 MOV EAX,dword ptr [EAX + 0x140]
    s.ax = m.r32((s.ax+0x00000140u));
  }
  L0069e3aa: { // 0x69e3aa: a803 TEST AL,0x3
    (void)integer::logical(((s.ax & 0xffu))&(0x00000003u),8,flags);
  }
  L0069e3ac: { // 0x69e3ac: 7505 JNZ 0x0069e3b3
    if(integer::condition("JNZ",flags)) goto L0069e3b3;
  }
  L0069e3ae: { // 0x69e3ae: bffeffffff MOV EDI,0xfffffffe
    s.di = 0xfffffffeu;
  }
  L0069e3b3: { // 0x69e3b3: bb02000000 MOV EBX,0x2
    s.bx = 0x00000002u;
  }
  L0069e3b8: { // 0x69e3b8: 84c3 TEST BL,AL
    (void)integer::logical(((s.bx & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0069e3ba: { // 0x69e3ba: 0f8494030000 JZ 0x0069e754
    if(integer::condition("JZ",flags)) goto L0069e754;
  }
  L0069e3c0: { // 0x69e3c0: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0069e3c3: { // 0x69e3c3: 668b4e02 MOV CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000002u)));
  }
  L0069e3c7: { // 0x69e3c7: 6648 DEC AX
    s.ax = with_ax(s.ax, integer::decrement((s.ax & 0xffffu),16,flags));
  }
  L0069e3c9: { // 0x69e3c9: 6649 DEC CX
    s.cx = with_ax(s.cx, integer::decrement((s.cx & 0xffffu),16,flags));
  }
  L0069e3cb: { // 0x69e3cb: 6689442418 MOV word ptr [ESP + 0x18],AX
    m.w16((f.sp+0x00000018u), (s.ax & 0xffffu));
  }
  L0069e3d0: { // 0x69e3d0: 66894c241a MOV word ptr [ESP + 0x1a],CX
    m.w16((f.sp+0x0000001au), (s.cx & 0xffffu));
  }
  L0069e3d5: { // 0x69e3d5: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0069e3d9: { // 0x69e3d9: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L0069e3dd: { // 0x69e3dd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0069e3de: { // 0x69e3de: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e3e3: { // 0x69e3e3: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L0069e3e7: { // 0x69e3e7: e81471eaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6939628u); flags=s.arithmetic_flags;
  }
  L0069e3ec: { // 0x69e3ec: 849840010000 TEST byte ptr [EAX + 0x140],BL
    (void)integer::logical((m.r8((s.ax+0x00000140u)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e3f2: { // 0x69e3f2: 7505 JNZ 0x0069e3f9
    if(integer::condition("JNZ",flags)) goto L0069e3f9;
  }
  L0069e3f4: { // 0x69e3f4: bd40000000 MOV EBP,0x40
    s.bp = 0x00000040u;
  }
  L0069e3f9: { // 0x69e3f9: 668b0e MOV CX,word ptr [ESI]
    s.cx = with_ax(s.cx, m.r16((s.si)));
  }
  L0069e3fc: { // 0x69e3fc: 668b5602 MOV DX,word ptr [ESI + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.si+0x00000002u)));
  }
  L0069e400: { // 0x69e400: 66894c2418 MOV word ptr [ESP + 0x18],CX
    m.w16((f.sp+0x00000018u), (s.cx & 0xffffu));
  }
  L0069e405: { // 0x69e405: 664a DEC DX
    s.dx = with_ax(s.dx, integer::decrement((s.dx & 0xffffu),16,flags));
  }
  L0069e407: { // 0x69e407: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0069e40b: { // 0x69e40b: 668954241a MOV word ptr [ESP + 0x1a],DX
    m.w16((f.sp+0x0000001au), (s.dx & 0xffffu));
  }
  L0069e410: { // 0x69e410: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0069e414: { // 0x69e414: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0069e415: { // 0x69e415: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e41a: { // 0x69e41a: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0069e41e: { // 0x69e41e: e8dd70eaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6939683u); flags=s.arithmetic_flags;
  }
  L0069e423: { // 0x69e423: 849840010000 TEST byte ptr [EAX + 0x140],BL
    (void)integer::logical((m.r8((s.ax+0x00000140u)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e429: { // 0x69e429: 7506 JNZ 0x0069e431
    if(integer::condition("JNZ",flags)) goto L0069e431;
  }
  L0069e42b: { // 0x69e42b: 81cd80000000 OR EBP,0x80
    s.bp = integer::logical((s.bp)|(0x00000080u),32,flags);
  }
  L0069e431: { // 0x69e431: 668b16 MOV DX,word ptr [ESI]
    s.dx = with_ax(s.dx, m.r16((s.si)));
  }
  L0069e434: { // 0x69e434: 668b4602 MOV AX,word ptr [ESI + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000002u)));
  }
  L0069e438: { // 0x69e438: 6642 INC DX
    s.dx = with_ax(s.dx, integer::increment((s.dx & 0xffffu),16,flags));
  }
  L0069e43a: { // 0x69e43a: 6648 DEC AX
    s.ax = with_ax(s.ax, integer::decrement((s.ax & 0xffffu),16,flags));
  }
  L0069e43c: { // 0x69e43c: 6689542418 MOV word ptr [ESP + 0x18],DX
    m.w16((f.sp+0x00000018u), (s.dx & 0xffffu));
  }
  L0069e441: { // 0x69e441: 668944241a MOV word ptr [ESP + 0x1a],AX
    m.w16((f.sp+0x0000001au), (s.ax & 0xffffu));
  }
  L0069e446: { // 0x69e446: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0069e44a: { // 0x69e44a: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L0069e44e: { // 0x69e44e: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0069e452: { // 0x69e452: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0069e453: { // 0x69e453: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e458: { // 0x69e458: e8a370eaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6939741u); flags=s.arithmetic_flags;
  }
  L0069e45d: { // 0x69e45d: 849840010000 TEST byte ptr [EAX + 0x140],BL
    (void)integer::logical((m.r8((s.ax+0x00000140u)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e463: { // 0x69e463: 7503 JNZ 0x0069e468
    if(integer::condition("JNZ",flags)) goto L0069e468;
  }
  L0069e465: { // 0x69e465: 83cd01 OR EBP,0x1
    s.bp = integer::logical((s.bp)|(0x00000001u),32,flags);
  }
  L0069e468: { // 0x69e468: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0069e46b: { // 0x69e46b: 668b4e02 MOV CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000002u)));
  }
  L0069e46f: { // 0x69e46f: 6648 DEC AX
    s.ax = with_ax(s.ax, integer::decrement((s.ax & 0xffffu),16,flags));
  }
  L0069e471: { // 0x69e471: 66894c241a MOV word ptr [ESP + 0x1a],CX
    m.w16((f.sp+0x0000001au), (s.cx & 0xffffu));
  }
  L0069e476: { // 0x69e476: 6689442418 MOV word ptr [ESP + 0x18],AX
    m.w16((f.sp+0x00000018u), (s.ax & 0xffffu));
  }
  L0069e47b: { // 0x69e47b: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0069e47f: { // 0x69e47f: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L0069e483: { // 0x69e483: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e488: { // 0x69e488: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0069e489: { // 0x69e489: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L0069e48d: { // 0x69e48d: e86e70eaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6939794u); flags=s.arithmetic_flags;
  }
  L0069e492: { // 0x69e492: 849840010000 TEST byte ptr [EAX + 0x140],BL
    (void)integer::logical((m.r8((s.ax+0x00000140u)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e498: { // 0x69e498: 7503 JNZ 0x0069e49d
    if(integer::condition("JNZ",flags)) goto L0069e49d;
  }
  L0069e49a: { // 0x69e49a: 83cd20 OR EBP,0x20
    s.bp = integer::logical((s.bp)|(0x00000020u),32,flags);
  }
  L0069e49d: { // 0x69e49d: 668b0e MOV CX,word ptr [ESI]
    s.cx = with_ax(s.cx, m.r16((s.si)));
  }
  L0069e4a0: { // 0x69e4a0: 668b5602 MOV DX,word ptr [ESI + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.si+0x00000002u)));
  }
  L0069e4a4: { // 0x69e4a4: 6641 INC CX
    s.cx = with_ax(s.cx, integer::increment((s.cx & 0xffffu),16,flags));
  }
  L0069e4a6: { // 0x69e4a6: 668954241a MOV word ptr [ESP + 0x1a],DX
    m.w16((f.sp+0x0000001au), (s.dx & 0xffffu));
  }
  L0069e4ab: { // 0x69e4ab: 66894c2418 MOV word ptr [ESP + 0x18],CX
    m.w16((f.sp+0x00000018u), (s.cx & 0xffffu));
  }
  L0069e4b0: { // 0x69e4b0: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0069e4b4: { // 0x69e4b4: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0069e4b8: { // 0x69e4b8: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0069e4bc: { // 0x69e4bc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0069e4bd: { // 0x69e4bd: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e4c2: { // 0x69e4c2: e83970eaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6939847u); flags=s.arithmetic_flags;
  }
  L0069e4c7: { // 0x69e4c7: 849840010000 TEST byte ptr [EAX + 0x140],BL
    (void)integer::logical((m.r8((s.ax+0x00000140u)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e4cd: { // 0x69e4cd: 7502 JNZ 0x0069e4d1
    if(integer::condition("JNZ",flags)) goto L0069e4d1;
  }
  L0069e4cf: { // 0x69e4cf: 0beb OR EBP,EBX
    s.bp = integer::logical((s.bp)|(s.bx),32,flags);
  }
  L0069e4d1: { // 0x69e4d1: 668b16 MOV DX,word ptr [ESI]
    s.dx = with_ax(s.dx, m.r16((s.si)));
  }
  L0069e4d4: { // 0x69e4d4: 668b4602 MOV AX,word ptr [ESI + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000002u)));
  }
  L0069e4d8: { // 0x69e4d8: 664a DEC DX
    s.dx = with_ax(s.dx, integer::decrement((s.dx & 0xffffu),16,flags));
  }
  L0069e4da: { // 0x69e4da: 6640 INC AX
    s.ax = with_ax(s.ax, integer::increment((s.ax & 0xffffu),16,flags));
  }
  L0069e4dc: { // 0x69e4dc: 6689542418 MOV word ptr [ESP + 0x18],DX
    m.w16((f.sp+0x00000018u), (s.dx & 0xffffu));
  }
  L0069e4e1: { // 0x69e4e1: 668944241a MOV word ptr [ESP + 0x1a],AX
    m.w16((f.sp+0x0000001au), (s.ax & 0xffffu));
  }
  L0069e4e6: { // 0x69e4e6: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0069e4ea: { // 0x69e4ea: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L0069e4ee: { // 0x69e4ee: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0069e4f2: { // 0x69e4f2: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0069e4f3: { // 0x69e4f3: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e4f8: { // 0x69e4f8: e80370eaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6939901u); flags=s.arithmetic_flags;
  }
  L0069e4fd: { // 0x69e4fd: 849840010000 TEST byte ptr [EAX + 0x140],BL
    (void)integer::logical((m.r8((s.ax+0x00000140u)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e503: { // 0x69e503: 7503 JNZ 0x0069e508
    if(integer::condition("JNZ",flags)) goto L0069e508;
  }
  L0069e505: { // 0x69e505: 83cd10 OR EBP,0x10
    s.bp = integer::logical((s.bp)|(0x00000010u),32,flags);
  }
  L0069e508: { // 0x69e508: 668b4e02 MOV CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000002u)));
  }
  L0069e50c: { // 0x69e50c: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0069e50f: { // 0x69e50f: 6641 INC CX
    s.cx = with_ax(s.cx, integer::increment((s.cx & 0xffffu),16,flags));
  }
  L0069e511: { // 0x69e511: 6689442418 MOV word ptr [ESP + 0x18],AX
    m.w16((f.sp+0x00000018u), (s.ax & 0xffffu));
  }
  L0069e516: { // 0x69e516: 66894c241a MOV word ptr [ESP + 0x1a],CX
    m.w16((f.sp+0x0000001au), (s.cx & 0xffffu));
  }
  L0069e51b: { // 0x69e51b: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0069e51f: { // 0x69e51f: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L0069e523: { // 0x69e523: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e528: { // 0x69e528: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0069e529: { // 0x69e529: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L0069e52d: { // 0x69e52d: e8ce6feaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6939954u); flags=s.arithmetic_flags;
  }
  L0069e532: { // 0x69e532: 849840010000 TEST byte ptr [EAX + 0x140],BL
    (void)integer::logical((m.r8((s.ax+0x00000140u)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e538: { // 0x69e538: 7503 JNZ 0x0069e53d
    if(integer::condition("JNZ",flags)) goto L0069e53d;
  }
  L0069e53a: { // 0x69e53a: 83cd08 OR EBP,0x8
    s.bp = integer::logical((s.bp)|(0x00000008u),32,flags);
  }
  L0069e53d: { // 0x69e53d: 668b0e MOV CX,word ptr [ESI]
    s.cx = with_ax(s.cx, m.r16((s.si)));
  }
  L0069e540: { // 0x69e540: 668b5602 MOV DX,word ptr [ESI + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.si+0x00000002u)));
  }
  L0069e544: { // 0x69e544: 6641 INC CX
    s.cx = with_ax(s.cx, integer::increment((s.cx & 0xffffu),16,flags));
  }
  L0069e546: { // 0x69e546: 6642 INC DX
    s.dx = with_ax(s.dx, integer::increment((s.dx & 0xffffu),16,flags));
  }
  L0069e548: { // 0x69e548: 66894c2418 MOV word ptr [ESP + 0x18],CX
    m.w16((f.sp+0x00000018u), (s.cx & 0xffffu));
  }
  L0069e54d: { // 0x69e54d: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0069e551: { // 0x69e551: 668954241a MOV word ptr [ESP + 0x1a],DX
    m.w16((f.sp+0x0000001au), (s.dx & 0xffffu));
  }
  L0069e556: { // 0x69e556: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0069e55a: { // 0x69e55a: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0069e55b: { // 0x69e55b: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e560: { // 0x69e560: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0069e564: { // 0x69e564: e8976feaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6940009u); flags=s.arithmetic_flags;
  }
  L0069e569: { // 0x69e569: 8a8840010000 MOV CL,byte ptr [EAX + 0x140]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000140u)));
  }
  L0069e56f: { // 0x69e56f: e9cb010000 JMP 0x0069e73f
    goto L0069e73f;
  }
  L0069e574: { // 0x69e574: 8b802c010000 MOV EAX,dword ptr [EAX + 0x12c]
    s.ax = m.r32((s.ax+0x0000012cu));
  }
  L0069e57a: { // 0x69e57a: a818 TEST AL,0x18
    (void)integer::logical(((s.ax & 0xffu))&(0x00000018u),8,flags);
  }
  L0069e57c: { // 0x69e57c: 7505 JNZ 0x0069e583
    if(integer::condition("JNZ",flags)) goto L0069e583;
  }
  L0069e57e: { // 0x69e57e: bffeffffff MOV EDI,0xfffffffe
    s.di = 0xfffffffeu;
  }
  L0069e583: { // 0x69e583: bb08000000 MOV EBX,0x8
    s.bx = 0x00000008u;
  }
  L0069e588: { // 0x69e588: 84c3 TEST BL,AL
    (void)integer::logical(((s.bx & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0069e58a: { // 0x69e58a: 0f84c4010000 JZ 0x0069e754
    if(integer::condition("JZ",flags)) goto L0069e754;
  }
  L0069e590: { // 0x69e590: 668b16 MOV DX,word ptr [ESI]
    s.dx = with_ax(s.dx, m.r16((s.si)));
  }
  L0069e593: { // 0x69e593: 668b4602 MOV AX,word ptr [ESI + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000002u)));
  }
  L0069e597: { // 0x69e597: 664a DEC DX
    s.dx = with_ax(s.dx, integer::decrement((s.dx & 0xffffu),16,flags));
  }
  L0069e599: { // 0x69e599: 6648 DEC AX
    s.ax = with_ax(s.ax, integer::decrement((s.ax & 0xffffu),16,flags));
  }
  L0069e59b: { // 0x69e59b: 6689542418 MOV word ptr [ESP + 0x18],DX
    m.w16((f.sp+0x00000018u), (s.dx & 0xffffu));
  }
  L0069e5a0: { // 0x69e5a0: 668944241a MOV word ptr [ESP + 0x1a],AX
    m.w16((f.sp+0x0000001au), (s.ax & 0xffffu));
  }
  L0069e5a5: { // 0x69e5a5: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0069e5a9: { // 0x69e5a9: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L0069e5ad: { // 0x69e5ad: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0069e5b1: { // 0x69e5b1: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0069e5b2: { // 0x69e5b2: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e5b7: { // 0x69e5b7: e8446feaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6940092u); flags=s.arithmetic_flags;
  }
  L0069e5bc: { // 0x69e5bc: 84982c010000 TEST byte ptr [EAX + 0x12c],BL
    (void)integer::logical((m.r8((s.ax+0x0000012cu)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e5c2: { // 0x69e5c2: 7505 JNZ 0x0069e5c9
    if(integer::condition("JNZ",flags)) goto L0069e5c9;
  }
  L0069e5c4: { // 0x69e5c4: bd40000000 MOV EBP,0x40
    s.bp = 0x00000040u;
  }
  L0069e5c9: { // 0x69e5c9: 668b4e02 MOV CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000002u)));
  }
  L0069e5cd: { // 0x69e5cd: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0069e5d0: { // 0x69e5d0: 6649 DEC CX
    s.cx = with_ax(s.cx, integer::decrement((s.cx & 0xffffu),16,flags));
  }
  L0069e5d2: { // 0x69e5d2: 6689442418 MOV word ptr [ESP + 0x18],AX
    m.w16((f.sp+0x00000018u), (s.ax & 0xffffu));
  }
  L0069e5d7: { // 0x69e5d7: 66894c241a MOV word ptr [ESP + 0x1a],CX
    m.w16((f.sp+0x0000001au), (s.cx & 0xffffu));
  }
  L0069e5dc: { // 0x69e5dc: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0069e5e0: { // 0x69e5e0: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L0069e5e4: { // 0x69e5e4: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e5e9: { // 0x69e5e9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0069e5ea: { // 0x69e5ea: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L0069e5ee: { // 0x69e5ee: e80d6feaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6940147u); flags=s.arithmetic_flags;
  }
  L0069e5f3: { // 0x69e5f3: 84982c010000 TEST byte ptr [EAX + 0x12c],BL
    (void)integer::logical((m.r8((s.ax+0x0000012cu)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e5f9: { // 0x69e5f9: 7506 JNZ 0x0069e601
    if(integer::condition("JNZ",flags)) goto L0069e601;
  }
  L0069e5fb: { // 0x69e5fb: 81cd80000000 OR EBP,0x80
    s.bp = integer::logical((s.bp)|(0x00000080u),32,flags);
  }
  L0069e601: { // 0x69e601: 668b0e MOV CX,word ptr [ESI]
    s.cx = with_ax(s.cx, m.r16((s.si)));
  }
  L0069e604: { // 0x69e604: 668b5602 MOV DX,word ptr [ESI + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.si+0x00000002u)));
  }
  L0069e608: { // 0x69e608: 6641 INC CX
    s.cx = with_ax(s.cx, integer::increment((s.cx & 0xffffu),16,flags));
  }
  L0069e60a: { // 0x69e60a: 664a DEC DX
    s.dx = with_ax(s.dx, integer::decrement((s.dx & 0xffffu),16,flags));
  }
  L0069e60c: { // 0x69e60c: 66894c2418 MOV word ptr [ESP + 0x18],CX
    m.w16((f.sp+0x00000018u), (s.cx & 0xffffu));
  }
  L0069e611: { // 0x69e611: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0069e615: { // 0x69e615: 668954241a MOV word ptr [ESP + 0x1a],DX
    m.w16((f.sp+0x0000001au), (s.dx & 0xffffu));
  }
  L0069e61a: { // 0x69e61a: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0069e61e: { // 0x69e61e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0069e61f: { // 0x69e61f: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e624: { // 0x69e624: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0069e628: { // 0x69e628: e8d36eeaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6940205u); flags=s.arithmetic_flags;
  }
  L0069e62d: { // 0x69e62d: 84982c010000 TEST byte ptr [EAX + 0x12c],BL
    (void)integer::logical((m.r8((s.ax+0x0000012cu)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e633: { // 0x69e633: 7503 JNZ 0x0069e638
    if(integer::condition("JNZ",flags)) goto L0069e638;
  }
  L0069e635: { // 0x69e635: 83cd01 OR EBP,0x1
    s.bp = integer::logical((s.bp)|(0x00000001u),32,flags);
  }
  L0069e638: { // 0x69e638: 668b16 MOV DX,word ptr [ESI]
    s.dx = with_ax(s.dx, m.r16((s.si)));
  }
  L0069e63b: { // 0x69e63b: 668b4602 MOV AX,word ptr [ESI + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000002u)));
  }
  L0069e63f: { // 0x69e63f: 664a DEC DX
    s.dx = with_ax(s.dx, integer::decrement((s.dx & 0xffffu),16,flags));
  }
  L0069e641: { // 0x69e641: 668944241a MOV word ptr [ESP + 0x1a],AX
    m.w16((f.sp+0x0000001au), (s.ax & 0xffffu));
  }
  L0069e646: { // 0x69e646: 6689542418 MOV word ptr [ESP + 0x18],DX
    m.w16((f.sp+0x00000018u), (s.dx & 0xffffu));
  }
  L0069e64b: { // 0x69e64b: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0069e64f: { // 0x69e64f: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L0069e653: { // 0x69e653: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0069e657: { // 0x69e657: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0069e658: { // 0x69e658: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e65d: { // 0x69e65d: e89e6eeaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6940258u); flags=s.arithmetic_flags;
  }
  L0069e662: { // 0x69e662: 84982c010000 TEST byte ptr [EAX + 0x12c],BL
    (void)integer::logical((m.r8((s.ax+0x0000012cu)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e668: { // 0x69e668: 7503 JNZ 0x0069e66d
    if(integer::condition("JNZ",flags)) goto L0069e66d;
  }
  L0069e66a: { // 0x69e66a: 83cd20 OR EBP,0x20
    s.bp = integer::logical((s.bp)|(0x00000020u),32,flags);
  }
  L0069e66d: { // 0x69e66d: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0069e670: { // 0x69e670: 668b4e02 MOV CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000002u)));
  }
  L0069e674: { // 0x69e674: 6640 INC AX
    s.ax = with_ax(s.ax, integer::increment((s.ax & 0xffffu),16,flags));
  }
  L0069e676: { // 0x69e676: 66894c241a MOV word ptr [ESP + 0x1a],CX
    m.w16((f.sp+0x0000001au), (s.cx & 0xffffu));
  }
  L0069e67b: { // 0x69e67b: 6689442418 MOV word ptr [ESP + 0x18],AX
    m.w16((f.sp+0x00000018u), (s.ax & 0xffffu));
  }
  L0069e680: { // 0x69e680: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0069e684: { // 0x69e684: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L0069e688: { // 0x69e688: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e68d: { // 0x69e68d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0069e68e: { // 0x69e68e: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L0069e692: { // 0x69e692: e8696eeaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6940311u); flags=s.arithmetic_flags;
  }
  L0069e697: { // 0x69e697: 84982c010000 TEST byte ptr [EAX + 0x12c],BL
    (void)integer::logical((m.r8((s.ax+0x0000012cu)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e69d: { // 0x69e69d: 7503 JNZ 0x0069e6a2
    if(integer::condition("JNZ",flags)) goto L0069e6a2;
  }
  L0069e69f: { // 0x69e69f: 83cd02 OR EBP,0x2
    s.bp = integer::logical((s.bp)|(0x00000002u),32,flags);
  }
  L0069e6a2: { // 0x69e6a2: 668b0e MOV CX,word ptr [ESI]
    s.cx = with_ax(s.cx, m.r16((s.si)));
  }
  L0069e6a5: { // 0x69e6a5: 668b5602 MOV DX,word ptr [ESI + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.si+0x00000002u)));
  }
  L0069e6a9: { // 0x69e6a9: 6649 DEC CX
    s.cx = with_ax(s.cx, integer::decrement((s.cx & 0xffffu),16,flags));
  }
  L0069e6ab: { // 0x69e6ab: 6642 INC DX
    s.dx = with_ax(s.dx, integer::increment((s.dx & 0xffffu),16,flags));
  }
  L0069e6ad: { // 0x69e6ad: 66894c2418 MOV word ptr [ESP + 0x18],CX
    m.w16((f.sp+0x00000018u), (s.cx & 0xffffu));
  }
  L0069e6b2: { // 0x69e6b2: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0069e6b6: { // 0x69e6b6: 668954241a MOV word ptr [ESP + 0x1a],DX
    m.w16((f.sp+0x0000001au), (s.dx & 0xffffu));
  }
  L0069e6bb: { // 0x69e6bb: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0069e6bf: { // 0x69e6bf: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0069e6c0: { // 0x69e6c0: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e6c5: { // 0x69e6c5: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0069e6c9: { // 0x69e6c9: e8326eeaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6940366u); flags=s.arithmetic_flags;
  }
  L0069e6ce: { // 0x69e6ce: 84982c010000 TEST byte ptr [EAX + 0x12c],BL
    (void)integer::logical((m.r8((s.ax+0x0000012cu)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e6d4: { // 0x69e6d4: 7503 JNZ 0x0069e6d9
    if(integer::condition("JNZ",flags)) goto L0069e6d9;
  }
  L0069e6d6: { // 0x69e6d6: 83cd10 OR EBP,0x10
    s.bp = integer::logical((s.bp)|(0x00000010u),32,flags);
  }
  L0069e6d9: { // 0x69e6d9: 668b4602 MOV AX,word ptr [ESI + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000002u)));
  }
  L0069e6dd: { // 0x69e6dd: 668b16 MOV DX,word ptr [ESI]
    s.dx = with_ax(s.dx, m.r16((s.si)));
  }
  L0069e6e0: { // 0x69e6e0: 6640 INC AX
    s.ax = with_ax(s.ax, integer::increment((s.ax & 0xffffu),16,flags));
  }
  L0069e6e2: { // 0x69e6e2: 6689542418 MOV word ptr [ESP + 0x18],DX
    m.w16((f.sp+0x00000018u), (s.dx & 0xffffu));
  }
  L0069e6e7: { // 0x69e6e7: 668944241a MOV word ptr [ESP + 0x1a],AX
    m.w16((f.sp+0x0000001au), (s.ax & 0xffffu));
  }
  L0069e6ec: { // 0x69e6ec: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0069e6f0: { // 0x69e6f0: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L0069e6f4: { // 0x69e6f4: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0069e6f8: { // 0x69e6f8: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0069e6f9: { // 0x69e6f9: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e6fe: { // 0x69e6fe: e8fd6deaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6940419u); flags=s.arithmetic_flags;
  }
  L0069e703: { // 0x69e703: 84982c010000 TEST byte ptr [EAX + 0x12c],BL
    (void)integer::logical((m.r8((s.ax+0x0000012cu)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e709: { // 0x69e709: 7502 JNZ 0x0069e70d
    if(integer::condition("JNZ",flags)) goto L0069e70d;
  }
  L0069e70b: { // 0x69e70b: 0beb OR EBP,EBX
    s.bp = integer::logical((s.bp)|(s.bx),32,flags);
  }
  L0069e70d: { // 0x69e70d: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0069e710: { // 0x69e710: 668b4e02 MOV CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000002u)));
  }
  L0069e714: { // 0x69e714: 6640 INC AX
    s.ax = with_ax(s.ax, integer::increment((s.ax & 0xffffu),16,flags));
  }
  L0069e716: { // 0x69e716: 6641 INC CX
    s.cx = with_ax(s.cx, integer::increment((s.cx & 0xffffu),16,flags));
  }
  L0069e718: { // 0x69e718: 6689442418 MOV word ptr [ESP + 0x18],AX
    m.w16((f.sp+0x00000018u), (s.ax & 0xffffu));
  }
  L0069e71d: { // 0x69e71d: 66894c241a MOV word ptr [ESP + 0x1a],CX
    m.w16((f.sp+0x0000001au), (s.cx & 0xffffu));
  }
  L0069e722: { // 0x69e722: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0069e726: { // 0x69e726: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L0069e72a: { // 0x69e72a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0069e72b: { // 0x69e72b: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e730: { // 0x69e730: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L0069e734: { // 0x69e734: e8c76deaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6940473u); flags=s.arithmetic_flags;
  }
  L0069e739: { // 0x69e739: 8a882c010000 MOV CL,byte ptr [EAX + 0x12c]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0000012cu)));
  }
  L0069e73f: { // 0x69e73f: 84cb TEST BL,CL
    (void)integer::logical(((s.bx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0069e741: { // 0x69e741: 7503 JNZ 0x0069e746
    if(integer::condition("JNZ",flags)) goto L0069e746;
  }
  L0069e743: { // 0x69e743: 83cd04 OR EBP,0x4
    s.bp = integer::logical((s.bp)|(0x00000004u),32,flags);
  }
  L0069e746: { // 0x69e746: 0fbe8564727900 MOVSX EAX,byte ptr [EBP + 0x797264]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.bp+0x00797264u)),8));
  }
  L0069e74d: { // 0x69e74d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0069e74e: { // 0x69e74e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0069e74f: { // 0x69e74f: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0069e750: { // 0x69e750: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0069e751: { // 0x69e751: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0069e754: { // 0x69e754: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0069e756: { // 0x69e756: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0069e757: { // 0x69e757: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0069e758: { // 0x69e758: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0069e759: { // 0x69e759: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0069e75a: { // 0x69e75a: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 6660400u:f_0025a130(m,s,child,{});break;
case 5526784u:f_00145500(m,s,child,{});break;
case 5535136u:f_001475a0(m,s,child,{});break;
case 6913968u:f_00297fb0(m,s,child,{});break;
case 4956288u:f_000ba080(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
case 6452016u:f_00227330(m,s,child,{});break;
case 4824480u:f_00099da0(m,s,child,{});break;
case 4703296u:f_0007c440(m,s,child,{});break;
case 4703392u:f_0007c4a0(m,s,child,{});break;
case 6939520u:f_0029e380(m,s,child,{});break;
default:throw std::domain_error("recovery202 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_006a5cc0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006a5cc0: { // 0x6a5cc0: a1e4e0a100 MOV EAX,[0x00a1e0e4]
    s.ax = m.r32((0x00a1e0e4u));
  }
  L006a5cc5: { // 0x6a5cc5: 83ec14 SUB ESP,0x14
    f.sp = integer::sub(f.sp,0x00000014u,32,flags);
  }
  L006a5cc8: { // 0x6a5cc8: 8a9088010000 MOV DL,byte ptr [EAX + 0x188]
    s.dx = with_al(s.dx, m.r8((s.ax+0x00000188u)));
  }
  L006a5cce: { // 0x6a5cce: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L006a5cd0: { // 0x6a5cd0: 0f8571010000 JNZ 0x006a5e47
    if(integer::condition("JNZ",flags)) goto L006a5e47;
  }
  L006a5cd6: { // 0x6a5cd6: 8b4974 MOV ECX,dword ptr [ECX + 0x74]
    s.cx = m.r32((s.cx+0x00000074u));
  }
  L006a5cd9: { // 0x6a5cd9: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006a5cda: { // 0x6a5cda: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006a5cdb: { // 0x6a5cdb: 8d542408 LEA EDX,[ESP + 0x8]
    s.dx = (f.sp+0x00000008u);
  }
  L006a5cdf: { // 0x6a5cdf: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006a5ce0: { // 0x6a5ce0: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L006a5ce6: { // 0x6a5ce6: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006a5ce7: { // 0x6a5ce7: e84444fbff CALL 0x0065a130
    s.arithmetic_flags=flags; invoke(m,s,f,0x0065a130u,6970604u); flags=s.arithmetic_flags;
  }
  L006a5cec: { // 0x6a5cec: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L006a5cee: { // 0x6a5cee: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L006a5cf2: { // 0x6a5cf2: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006a5cf3: { // 0x6a5cf3: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006a5cf8: { // 0x6a5cf8: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L006a5cfc: { // 0x6a5cfc: e8fff7e9ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6970625u); flags=s.arithmetic_flags;
  }
  L006a5d01: { // 0x6a5d01: 8b8840010000 MOV ECX,dword ptr [EAX + 0x140]
    s.cx = m.r32((s.ax+0x00000140u));
  }
  L006a5d07: { // 0x6a5d07: f6c501 TEST CH,0x1
    (void)integer::logical((((s.cx >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L006a5d0a: { // 0x6a5d0a: 751e JNZ 0x006a5d2a
    if(integer::condition("JNZ",flags)) goto L006a5d2a;
  }
  L006a5d0c: { // 0x6a5d0c: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  L006a5d10: { // 0x6a5d10: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006a5d15: { // 0x6a5d15: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006a5d16: { // 0x6a5d16: e8e5f7e9ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6970651u); flags=s.arithmetic_flags;
  }
  L006a5d1b: { // 0x6a5d1b: 8b8840010000 MOV ECX,dword ptr [EAX + 0x140]
    s.cx = m.r32((s.ax+0x00000140u));
  }
  L006a5d21: { // 0x6a5d21: f6c504 TEST CH,0x4
    (void)integer::logical((((s.cx >> 8) & 0xffu))&(0x00000004u),8,flags);
  }
  L006a5d24: { // 0x6a5d24: 7504 JNZ 0x006a5d2a
    if(integer::condition("JNZ",flags)) goto L006a5d2a;
  }
  L006a5d26: { // 0x6a5d26: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L006a5d28: { // 0x6a5d28: eb05 JMP 0x006a5d2f
    goto L006a5d2f;
  }
  L006a5d2a: { // 0x6a5d2a: bf04000000 MOV EDI,0x4
    s.di = 0x00000004u;
  }
  L006a5d2f: { // 0x6a5d2f: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L006a5d33: { // 0x6a5d33: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006a5d38: { // 0x6a5d38: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006a5d39: { // 0x6a5d39: e8c2f7e9ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6970686u); flags=s.arithmetic_flags;
  }
  L006a5d3e: { // 0x6a5d3e: 0fbeb01b010000 MOVSX ESI,byte ptr [EAX + 0x11b]
    s.si = std::uint32_t(integer::sign_extend(m.r8((s.ax+0x0000011bu)),8));
  }
  L006a5d45: { // 0x6a5d45: 03f7 ADD ESI,EDI
    s.si = integer::add(s.si,s.di,32,flags);
  }
  L006a5d47: { // 0x6a5d47: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006a5d49: { // 0x6a5d49: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L006a5d4b: { // 0x6a5d4b: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L006a5d4d: { // 0x6a5d4d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006a5d4e: { // 0x6a5d4e: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006a5d50: { // 0x6a5d50: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006a5d52: { // 0x6a5d52: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L006a5d54: { // 0x6a5d54: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L006a5d58: { // 0x6a5d58: d1ff SAR EDI,0x1
    s.di = integer::shift(s.di,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L006a5d5a: { // 0x6a5d5a: 66897c2414 MOV word ptr [ESP + 0x14],DI
    m.w16((f.sp+0x00000014u), (s.di & 0xffffu));
  }
  L006a5d5f: { // 0x6a5d5f: 66897c2416 MOV word ptr [ESP + 0x16],DI
    m.w16((f.sp+0x00000016u), (s.di & 0xffffu));
  }
  L006a5d64: { // 0x6a5d64: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L006a5d68: { // 0x6a5d68: 8b542416 MOV EDX,dword ptr [ESP + 0x16]
    s.dx = m.r32((f.sp+0x00000016u));
  }
  L006a5d6c: { // 0x6a5d6c: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L006a5d6e: { // 0x6a5d6e: 8b4c2422 MOV ECX,dword ptr [ESP + 0x22]
    s.cx = m.r32((f.sp+0x00000022u));
  }
  L006a5d72: { // 0x6a5d72: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L006a5d74: { // 0x6a5d74: 8b151079aa00 MOV EDX,dword ptr [0x00aa7910]
    s.dx = m.r32((0x00aa7910u));
  }
  L006a5d7a: { // 0x6a5d7a: 0fafd6 IMUL EDX,ESI
    s.dx = integer::imul(s.dx,s.si,32,flags);
  }
  L006a5d7d: { // 0x6a5d7d: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L006a5d80: { // 0x6a5d80: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L006a5d83: { // 0x6a5d83: c1e108 SHL ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::left);
  }
  L006a5d86: { // 0x6a5d86: c1e008 SHL EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::left);
  }
  L006a5d89: { // 0x6a5d89: 81c180000000 ADD ECX,0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L006a5d8f: { // 0x6a5d8f: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L006a5d93: { // 0x6a5d93: 8b15881b8200 MOV EDX,dword ptr [0x00821b88]
    s.dx = m.r32((0x00821b88u));
  }
  L006a5d99: { // 0x6a5d99: 0580000000 ADD EAX,0x80
    s.ax = integer::add(s.ax,0x00000080u,32,flags);
  }
  L006a5d9e: { // 0x6a5d9e: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L006a5da2: { // 0x6a5da2: 8b0de4e0a100 MOV ECX,dword ptr [0x00a1e0e4]
    s.cx = m.r32((0x00a1e0e4u));
  }
  L006a5da8: { // 0x6a5da8: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006a5daa: { // 0x6a5daa: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L006a5dae: { // 0x6a5dae: 8b824c050000 MOV EAX,dword ptr [EDX + 0x54c]
    s.ax = m.r32((s.dx+0x0000054cu));
  }
  L006a5db4: { // 0x6a5db4: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006a5db6: { // 0x6a5db6: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006a5db7: { // 0x6a5db7: 8d4c2420 LEA ECX,[ESP + 0x20]
    s.cx = (f.sp+0x00000020u);
  }
  L006a5dbb: { // 0x6a5dbb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006a5dbc: { // 0x6a5dbc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006a5dbd: { // 0x6a5dbd: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006a5dc2: { // 0x6a5dc2: e8d917eaff CALL 0x005475a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005475a0u,6970823u); flags=s.arithmetic_flags;
  }
  L006a5dc7: { // 0x6a5dc7: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L006a5dcb: { // 0x6a5dcb: 8b151079aa00 MOV EDX,dword ptr [0x00aa7910]
    s.dx = m.r32((0x00aa7910u));
  }
  L006a5dd1: { // 0x6a5dd1: 66897c2408 MOV word ptr [ESP + 0x8],DI
    m.w16((f.sp+0x00000008u), (s.di & 0xffffu));
  }
  L006a5dd6: { // 0x6a5dd6: 66897c240a MOV word ptr [ESP + 0xa],DI
    m.w16((f.sp+0x0000000au), (s.di & 0xffffu));
  }
  L006a5ddb: { // 0x6a5ddb: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  L006a5ddf: { // 0x6a5ddf: 8b7c240a MOV EDI,dword ptr [ESP + 0xa]
    s.di = m.r32((f.sp+0x0000000au));
  }
  L006a5de3: { // 0x6a5de3: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L006a5de5: { // 0x6a5de5: 8b4c2416 MOV ECX,dword ptr [ESP + 0x16]
    s.cx = m.r32((f.sp+0x00000016u));
  }
  L006a5de9: { // 0x6a5de9: 0fafd6 IMUL EDX,ESI
    s.dx = integer::imul(s.dx,s.si,32,flags);
  }
  L006a5dec: { // 0x6a5dec: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L006a5def: { // 0x6a5def: 2bcf SUB ECX,EDI
    s.cx = integer::sub(s.cx,s.di,32,flags);
  }
  L006a5df1: { // 0x6a5df1: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L006a5df3: { // 0x6a5df3: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L006a5df6: { // 0x6a5df6: c1e008 SHL EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::left);
  }
  L006a5df9: { // 0x6a5df9: 0580000000 ADD EAX,0x80
    s.ax = integer::add(s.ax,0x00000080u,32,flags);
  }
  L006a5dfe: { // 0x6a5dfe: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L006a5e00: { // 0x6a5e00: c1e108 SHL ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::left);
  }
  L006a5e03: { // 0x6a5e03: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L006a5e07: { // 0x6a5e07: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L006a5e0c: { // 0x6a5e0c: 81c180000000 ADD ECX,0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L006a5e12: { // 0x6a5e12: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L006a5e16: { // 0x6a5e16: 8b15e4e0a100 MOV EDX,dword ptr [0x00a1e0e4]
    s.dx = m.r32((0x00a1e0e4u));
  }
  L006a5e1c: { // 0x6a5e1c: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006a5e1e: { // 0x6a5e1e: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006a5e20: { // 0x6a5e20: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L006a5e24: { // 0x6a5e24: 8b884c050000 MOV ECX,dword ptr [EAX + 0x54c]
    s.cx = m.r32((s.ax+0x0000054cu));
  }
  L006a5e2a: { // 0x6a5e2a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006a5e2c: { // 0x6a5e2c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006a5e2d: { // 0x6a5e2d: 8d542420 LEA EDX,[ESP + 0x20]
    s.dx = (f.sp+0x00000020u);
  }
  L006a5e31: { // 0x6a5e31: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006a5e32: { // 0x6a5e32: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006a5e33: { // 0x6a5e33: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006a5e38: { // 0x6a5e38: e86317eaff CALL 0x005475a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005475a0u,6970941u); flags=s.arithmetic_flags;
  }
  L006a5e3d: { // 0x6a5e3d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006a5e3e: { // 0x6a5e3e: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006a5e40: { // 0x6a5e40: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006a5e41: { // 0x6a5e41: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L006a5e44: { // 0x6a5e44: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006a5e47: { // 0x6a5e47: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006a5e49: { // 0x6a5e49: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L006a5e4c: { // 0x6a5e4c: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
