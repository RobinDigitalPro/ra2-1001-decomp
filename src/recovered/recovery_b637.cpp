#include "recovered/recovery_b637_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b637 {
namespace {
void f_000ced20(Memory&,State&,Frame&,const Operations&);
void f_000ced30(Memory&,State&,Frame&,const Operations&);
void f_000ced40(Memory&,State&,Frame&,const Operations&);
void f_000cf1f0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_000ced20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004ced20: { // 0x4ced20: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L004ced22: { // 0x4ced22: c6411e00 MOV byte ptr [ECX + 0x1e],0x0
    m.w8((s.cx+0x0000001eu), 0x00000000u);
  }
  L004ced26: { // 0x4ced26: c6411c01 MOV byte ptr [ECX + 0x1c],0x1
    m.w8((s.cx+0x0000001cu), 0x00000001u);
  }
  L004ced2a: { // 0x4ced2a: ff6054 JMP dword ptr [EAX + 0x54]
    switch(m.r32((s.ax+0x00000054u))){
    case 0x004ced20u: goto L004ced20;
    case 0x004ced22u: goto L004ced22;
    case 0x004ced26u: goto L004ced26;
    case 0x004ced2au: goto L004ced2a;
    case 0x004cf1f0u:s.arithmetic_flags=flags;f_000cf1f0(m,s,f,op);return;default:throw std::domain_error("recovery637 unsupported switch destination");}
  }
}
void f_000ced30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004ced30: { // 0x4ced30: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L004ced32: { // 0x4ced32: 88411e MOV byte ptr [ECX + 0x1e],AL
    m.w8((s.cx+0x0000001eu), (s.ax & 0xffu));
  }
  L004ced35: { // 0x4ced35: 88411c MOV byte ptr [ECX + 0x1c],AL
    m.w8((s.cx+0x0000001cu), (s.ax & 0xffu));
  }
  L004ced38: { // 0x4ced38: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L004ced3a: { // 0x4ced3a: ff6054 JMP dword ptr [EAX + 0x54]
    switch(m.r32((s.ax+0x00000054u))){
    case 0x004ced30u: goto L004ced30;
    case 0x004ced32u: goto L004ced32;
    case 0x004ced35u: goto L004ced35;
    case 0x004ced38u: goto L004ced38;
    case 0x004ced3au: goto L004ced3a;
    case 0x004cf1f0u:s.arithmetic_flags=flags;f_000cf1f0(m,s,f,op);return;default:throw std::domain_error("recovery637 unsupported switch destination");}
  }
}
void f_000ced40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004ced40: { // 0x4ced40: 8a511e MOV DL,byte ptr [ECX + 0x1e]
    s.dx = with_al(s.dx, m.r8((s.cx+0x0000001eu)));
  }
  L004ced43: { // 0x4ced43: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004ced45: { // 0x4ced45: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L004ced47: { // 0x4ced47: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  L004ced4a: { // 0x4ced4a: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000cf1f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004cf1f0: { // 0x4cf1f0: 390d28e38400 CMP dword ptr [0x0084e328],ECX
    (void)integer::sub(m.r32((0x0084e328u)),s.cx,32,flags);
  }
  L004cf1f6: { // 0x4cf1f6: 7513 JNZ 0x004cf20b
    if(integer::condition("JNZ",flags)) goto L004cf20b;
  }
  L004cf1f8: { // 0x4cf1f8: 8b4120 MOV EAX,dword ptr [ECX + 0x20]
    s.ax = m.r32((s.cx+0x00000020u));
  }
  L004cf1fb: { // 0x4cf1fb: 80e4fe AND AH,0xfe
    s.ax = (s.ax & 0xffff00ffu) | (((integer::logical((((s.ax >> 8) & 0xffu))&(0x000000feu),8,flags)) & 0xffu) << 8);
  }
  L004cf1fe: { // 0x4cf1fe: 894120 MOV dword ptr [ECX + 0x20],EAX
    m.w32((s.cx+0x00000020u), s.ax);
  }
  L004cf201: { // 0x4cf201: c70528e3840000000000 MOV dword ptr [0x0084e328],0x0
    m.w32((0x0084e328u), 0x00000000u);
  }
  L004cf20b: { // 0x4cf20b: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 5041440u:f_000ced20(m,s,child,{});break;
case 5041456u:f_000ced30(m,s,child,{});break;
case 5041472u:f_000ced40(m,s,child,{});break;
case 5042672u:f_000cf1f0(m,s,child,{});break;
default:throw std::domain_error("recovery637 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00672210(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00672210: { // 0x672210: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00672211: { // 0x672211: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00672212: { // 0x672212: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00672214: { // 0x672214: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00672216: { // 0x672216: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L0067221a: { // 0x67221a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0067221b: { // 0x67221b: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0067221d: { // 0x67221d: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L00672220: { // 0x672220: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00672222: { // 0x672222: 8d04c0 LEA EAX,[EAX + EAX*0x8]
    s.ax = (s.ax+(s.ax * 0x00000008u));
  }
  L00672225: { // 0x672225: 8d0441 LEA EAX,[ECX + EAX*0x2]
    s.ax = (s.cx+(s.ax * 0x00000002u));
  }
  L00672228: { // 0x672228: 8d1440 LEA EDX,[EAX + EAX*0x2]
    s.dx = (s.ax+(s.ax * 0x00000002u));
  }
  L0067222b: { // 0x67222b: 399c9690150000 CMP dword ptr [ESI + EDX*0x4 + 0x1590],EBX
    (void)integer::sub(m.r32((s.si+(s.dx * 0x00000004u)+0x00001590u)),s.bx,32,flags);
  }
  L00672232: { // 0x672232: 0f8ed2000000 JLE 0x0067230a
    if(integer::condition("JLE",flags)) goto L0067230a;
  }
  L00672238: { // 0x672238: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  L0067223d: { // 0x67223d: 8b0d6c198200 MOV ECX,dword ptr [0x0082196c]
    s.cx = m.r32((0x0082196cu));
  }
  L00672243: { // 0x672243: 8b156c48aa00 MOV EDX,dword ptr [0x00aa486c]
    s.dx = m.r32((0x00aa486cu));
  }
  L00672249: { // 0x672249: 8a8039220000 MOV AL,byte ptr [EAX + 0x2239]
    s.ax = with_al(s.ax, m.r8((s.ax+0x00002239u)));
  }
  L0067224f: { // 0x67224f: f6d8 NEG AL
    s.ax = with_al(s.ax, integer::sub(0u,(s.ax & 0xffu),8,flags));
  }
  L00672251: { // 0x672251: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  L00672253: { // 0x672253: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L00672255: { // 0x672255: 8b1564198200 MOV EDX,dword ptr [0x00821964]
    s.dx = m.r32((0x00821964u));
  }
  L0067225b: { // 0x67225b: 83e008 AND EAX,0x8
    s.ax = integer::logical((s.ax)&(0x00000008u),32,flags);
  }
  L0067225e: { // 0x67225e: 83c012 ADD EAX,0x12
    s.ax = integer::add(s.ax,0x00000012u,32,flags);
  }
  L00672261: { // 0x672261: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00672263: { // 0x672263: b81f85eb51 MOV EAX,0x51eb851f
    s.ax = 0x51eb851fu;
  }
  L00672268: { // 0x672268: 8d4c11f9 LEA ECX,[ECX + EDX*0x1 + -0x7]
    s.cx = (s.cx+(s.dx * 0x00000001u)-0x00000007u);
  }
  L0067226c: { // 0x67226c: f7e9 IMUL ECX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.cx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  L0067226e: { // 0x67226e: 8b8ed84e0000 MOV ECX,dword ptr [ESI + 0x4ed8]
    s.cx = m.r32((s.si+0x00004ed8u));
  }
  L00672274: { // 0x672274: c1fa04 SAR EDX,0x4
    s.dx = integer::shift(s.dx,0x00000004u,32,flags,integer::Shift::arithmetic_right);
  }
  L00672277: { // 0x672277: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L00672279: { // 0x672279: c1e81f SHR EAX,0x1f
    s.ax = integer::shift(s.ax,0x0000001fu,32,flags,integer::Shift::right);
  }
  L0067227c: { // 0x67227c: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L0067227e: { // 0x67227e: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00672280: { // 0x672280: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L00672283: { // 0x672283: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00672285: { // 0x672285: d1e2 SHL EDX,0x1
    s.dx = integer::shift(s.dx,0x00000001u,32,flags,integer::Shift::left);
  }
  L00672287: { // 0x672287: 8d04c0 LEA EAX,[EAX + EAX*0x8]
    s.ax = (s.ax+(s.ax * 0x00000008u));
  }
  L0067228a: { // 0x67228a: 8d0441 LEA EAX,[ECX + EAX*0x2]
    s.ax = (s.cx+(s.ax * 0x00000002u));
  }
  L0067228d: { // 0x67228d: 8d0c40 LEA ECX,[EAX + EAX*0x2]
    s.cx = (s.ax+(s.ax * 0x00000002u));
  }
  L00672290: { // 0x672290: 8b848e90150000 MOV EAX,dword ptr [ESI + ECX*0x4 + 0x1590]
    s.ax = m.r32((s.si+(s.cx * 0x00000004u)+0x00001590u));
  }
  L00672297: { // 0x672297: b9f046aa00 MOV ECX,0xaa46f0
    s.cx = 0x00aa46f0u;
  }
  L0067229c: { // 0x67229c: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0067229e: { // 0x67229e: 7e35 JLE 0x006722d5
    if(integer::condition("JLE",flags)) goto L006722d5;
  }
  L006722a0: { // 0x6722a0: e89bcae5ff CALL 0x004ced40
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced40u,6759077u); flags=s.arithmetic_flags;
  }
  L006722a5: { // 0x6722a5: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006722a7: { // 0x6722a7: 750a JNZ 0x006722b3
    if(integer::condition("JNZ",flags)) goto L006722b3;
  }
  L006722a9: { // 0x6722a9: b9f046aa00 MOV ECX,0xaa46f0
    s.cx = 0x00aa46f0u;
  }
  L006722ae: { // 0x6722ae: e86dcae5ff CALL 0x004ced20
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced20u,6759091u); flags=s.arithmetic_flags;
  }
  L006722b3: { // 0x6722b3: b9c847aa00 MOV ECX,0xaa47c8
    s.cx = 0x00aa47c8u;
  }
  L006722b8: { // 0x6722b8: e883cae5ff CALL 0x004ced40
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced40u,6759101u); flags=s.arithmetic_flags;
  }
  L006722bd: { // 0x6722bd: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006722bf: { // 0x6722bf: 0f85b9020000 JNZ 0x0067257e
    if(integer::condition("JNZ",flags)) goto L0067257e;
  }
  L006722c5: { // 0x6722c5: b9c847aa00 MOV ECX,0xaa47c8
    s.cx = 0x00aa47c8u;
  }
  L006722ca: { // 0x6722ca: e851cae5ff CALL 0x004ced20
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced20u,6759119u); flags=s.arithmetic_flags;
  }
  L006722cf: { // 0x6722cf: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006722d0: { // 0x6722d0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006722d1: { // 0x6722d1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006722d2: { // 0x6722d2: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006722d5: { // 0x6722d5: e866cae5ff CALL 0x004ced40
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced40u,6759130u); flags=s.arithmetic_flags;
  }
  L006722da: { // 0x6722da: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006722dc: { // 0x6722dc: 740a JZ 0x006722e8
    if(integer::condition("JZ",flags)) goto L006722e8;
  }
  L006722de: { // 0x6722de: b9f046aa00 MOV ECX,0xaa46f0
    s.cx = 0x00aa46f0u;
  }
  L006722e3: { // 0x6722e3: e848cae5ff CALL 0x004ced30
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced30u,6759144u); flags=s.arithmetic_flags;
  }
  L006722e8: { // 0x6722e8: b9c847aa00 MOV ECX,0xaa47c8
    s.cx = 0x00aa47c8u;
  }
  L006722ed: { // 0x6722ed: e84ecae5ff CALL 0x004ced40
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced40u,6759154u); flags=s.arithmetic_flags;
  }
  L006722f2: { // 0x6722f2: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006722f4: { // 0x6722f4: 0f8484020000 JZ 0x0067257e
    if(integer::condition("JZ",flags)) goto L0067257e;
  }
  L006722fa: { // 0x6722fa: b9c847aa00 MOV ECX,0xaa47c8
    s.cx = 0x00aa47c8u;
  }
  L006722ff: { // 0x6722ff: e82ccae5ff CALL 0x004ced30
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced30u,6759172u); flags=s.arithmetic_flags;
  }
  L00672304: { // 0x672304: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00672305: { // 0x672305: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00672306: { // 0x672306: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00672307: { // 0x672307: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0067230a: { // 0x67230a: 8d0c49 LEA ECX,[ECX + ECX*0x2]
    s.cx = (s.cx+(s.cx * 0x00000002u));
  }
  L0067230d: { // 0x67230d: c1e105 SHL ECX,0x5
    s.cx = integer::shift(s.cx,0x00000005u,32,flags,integer::Shift::left);
  }
  L00672310: { // 0x672310: 81c10810aa00 ADD ECX,0xaa1008
    s.cx = integer::add(s.cx,0x00aa1008u,32,flags);
  }
  L00672316: { // 0x672316: e815cae5ff CALL 0x004ced30
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced30u,6759195u); flags=s.arithmetic_flags;
  }
  L0067231b: { // 0x67231b: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0067231d: { // 0x67231d: 8d8690150000 LEA EAX,[ESI + 0x1590]
    s.ax = (s.si+0x00001590u);
  }
  L00672323: { // 0x672323: 3918 CMP dword ptr [EAX],EBX
    (void)integer::sub(m.r32((s.ax)),s.bx,32,flags);
  }
  L00672325: { // 0x672325: 7f0d JG 0x00672334
    if(integer::condition("JG",flags)) goto L00672334;
  }
  L00672327: { // 0x672327: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L00672328: { // 0x672328: 05640e0000 ADD EAX,0xe64
    s.ax = integer::add(s.ax,0x00000e64u,32,flags);
  }
  L0067232d: { // 0x67232d: 83ff04 CMP EDI,0x4
    (void)integer::sub(s.di,0x00000004u,32,flags);
  }
  L00672330: { // 0x672330: 7cf1 JL 0x00672323
    if(integer::condition("JL",flags)) goto L00672323;
  }
  L00672332: { // 0x672332: eb09 JMP 0x0067233d
    goto L0067233d;
  }
  L00672334: { // 0x672334: 83ffff CMP EDI,-0x1
    (void)integer::sub(s.di,0xffffffffu,32,flags);
  }
  L00672337: { // 0x672337: 0f85ed000000 JNZ 0x0067242a
    if(integer::condition("JNZ",flags)) goto L0067242a;
  }
  L0067233d: { // 0x67233d: 8b15c055a200 MOV EDX,dword ptr [0x00a255c0]
    s.dx = m.r32((0x00a255c0u));
  }
  L00672343: { // 0x672343: 8b0d6c198200 MOV ECX,dword ptr [0x0082196c]
    s.cx = m.r32((0x0082196cu));
  }
  L00672349: { // 0x672349: 8b3d6c48aa00 MOV EDI,dword ptr [0x00aa486c]
    s.di = m.r32((0x00aa486cu));
  }
  L0067234f: { // 0x67234f: 8a8239220000 MOV AL,byte ptr [EDX + 0x2239]
    s.ax = with_al(s.ax, m.r8((s.dx+0x00002239u)));
  }
  L00672355: { // 0x672355: 8b1564198200 MOV EDX,dword ptr [0x00821964]
    s.dx = m.r32((0x00821964u));
  }
  L0067235b: { // 0x67235b: f6d8 NEG AL
    s.ax = with_al(s.ax, integer::sub(0u,(s.ax & 0xffu),8,flags));
  }
  L0067235d: { // 0x67235d: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  L0067235f: { // 0x67235f: 2bcf SUB ECX,EDI
    s.cx = integer::sub(s.cx,s.di,32,flags);
  }
  L00672361: { // 0x672361: 83e008 AND EAX,0x8
    s.ax = integer::logical((s.ax)&(0x00000008u),32,flags);
  }
  L00672364: { // 0x672364: 83c012 ADD EAX,0x12
    s.ax = integer::add(s.ax,0x00000012u,32,flags);
  }
  L00672367: { // 0x672367: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00672369: { // 0x672369: b81f85eb51 MOV EAX,0x51eb851f
    s.ax = 0x51eb851fu;
  }
  L0067236e: { // 0x67236e: 8d4c11f9 LEA ECX,[ECX + EDX*0x1 + -0x7]
    s.cx = (s.cx+(s.dx * 0x00000001u)-0x00000007u);
  }
  L00672372: { // 0x672372: f7e9 IMUL ECX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.cx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  L00672374: { // 0x672374: 8b8ed84e0000 MOV ECX,dword ptr [ESI + 0x4ed8]
    s.cx = m.r32((s.si+0x00004ed8u));
  }
  L0067237a: { // 0x67237a: c1fa04 SAR EDX,0x4
    s.dx = integer::shift(s.dx,0x00000004u,32,flags,integer::Shift::arithmetic_right);
  }
  L0067237d: { // 0x67237d: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L0067237f: { // 0x67237f: c1e81f SHR EAX,0x1f
    s.ax = integer::shift(s.ax,0x0000001fu,32,flags,integer::Shift::right);
  }
  L00672382: { // 0x672382: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00672384: { // 0x672384: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00672386: { // 0x672386: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L00672389: { // 0x672389: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0067238b: { // 0x67238b: d1e2 SHL EDX,0x1
    s.dx = integer::shift(s.dx,0x00000001u,32,flags,integer::Shift::left);
  }
  L0067238d: { // 0x67238d: 8d04c0 LEA EAX,[EAX + EAX*0x8]
    s.ax = (s.ax+(s.ax * 0x00000008u));
  }
  L00672390: { // 0x672390: 8d0441 LEA EAX,[ECX + EAX*0x2]
    s.ax = (s.cx+(s.ax * 0x00000002u));
  }
  L00672393: { // 0x672393: 8d0c40 LEA ECX,[EAX + EAX*0x2]
    s.cx = (s.ax+(s.ax * 0x00000002u));
  }
  L00672396: { // 0x672396: 8b848e90150000 MOV EAX,dword ptr [ESI + ECX*0x4 + 0x1590]
    s.ax = m.r32((s.si+(s.cx * 0x00000004u)+0x00001590u));
  }
  L0067239d: { // 0x67239d: b9f046aa00 MOV ECX,0xaa46f0
    s.cx = 0x00aa46f0u;
  }
  L006723a2: { // 0x6723a2: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L006723a4: { // 0x6723a4: 7e2d JLE 0x006723d3
    if(integer::condition("JLE",flags)) goto L006723d3;
  }
  L006723a6: { // 0x6723a6: e895c9e5ff CALL 0x004ced40
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced40u,6759339u); flags=s.arithmetic_flags;
  }
  L006723ab: { // 0x6723ab: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006723ad: { // 0x6723ad: 750a JNZ 0x006723b9
    if(integer::condition("JNZ",flags)) goto L006723b9;
  }
  L006723af: { // 0x6723af: b9f046aa00 MOV ECX,0xaa46f0
    s.cx = 0x00aa46f0u;
  }
  L006723b4: { // 0x6723b4: e867c9e5ff CALL 0x004ced20
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced20u,6759353u); flags=s.arithmetic_flags;
  }
  L006723b9: { // 0x6723b9: b9c847aa00 MOV ECX,0xaa47c8
    s.cx = 0x00aa47c8u;
  }
  L006723be: { // 0x6723be: e87dc9e5ff CALL 0x004ced40
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced40u,6759363u); flags=s.arithmetic_flags;
  }
  L006723c3: { // 0x6723c3: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006723c5: { // 0x6723c5: 7537 JNZ 0x006723fe
    if(integer::condition("JNZ",flags)) goto L006723fe;
  }
  L006723c7: { // 0x6723c7: b9c847aa00 MOV ECX,0xaa47c8
    s.cx = 0x00aa47c8u;
  }
  L006723cc: { // 0x6723cc: e84fc9e5ff CALL 0x004ced20
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced20u,6759377u); flags=s.arithmetic_flags;
  }
  L006723d1: { // 0x6723d1: eb2b JMP 0x006723fe
    goto L006723fe;
  }
  L006723d3: { // 0x6723d3: e868c9e5ff CALL 0x004ced40
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced40u,6759384u); flags=s.arithmetic_flags;
  }
  L006723d8: { // 0x6723d8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006723da: { // 0x6723da: 740a JZ 0x006723e6
    if(integer::condition("JZ",flags)) goto L006723e6;
  }
  L006723dc: { // 0x6723dc: b9f046aa00 MOV ECX,0xaa46f0
    s.cx = 0x00aa46f0u;
  }
  L006723e1: { // 0x6723e1: e84ac9e5ff CALL 0x004ced30
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced30u,6759398u); flags=s.arithmetic_flags;
  }
  L006723e6: { // 0x6723e6: b9c847aa00 MOV ECX,0xaa47c8
    s.cx = 0x00aa47c8u;
  }
  L006723eb: { // 0x6723eb: e850c9e5ff CALL 0x004ced40
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced40u,6759408u); flags=s.arithmetic_flags;
  }
  L006723f0: { // 0x6723f0: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006723f2: { // 0x6723f2: 740a JZ 0x006723fe
    if(integer::condition("JZ",flags)) goto L006723fe;
  }
  L006723f4: { // 0x6723f4: b9c847aa00 MOV ECX,0xaa47c8
    s.cx = 0x00aa47c8u;
  }
  L006723f9: { // 0x6723f9: e832c9e5ff CALL 0x004ced30
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced30u,6759422u); flags=s.arithmetic_flags;
  }
  L006723fe: { // 0x6723fe: 391d3848aa00 CMP dword ptr [0x00aa4838],EBX
    (void)integer::sub(m.r32((0x00aa4838u)),s.bx,32,flags);
  }
  L00672404: { // 0x672404: 0f8474010000 JZ 0x0067257e
    if(integer::condition("JZ",flags)) goto L0067257e;
  }
  L0067240a: { // 0x67240a: c786d44e0000ffffffff MOV dword ptr [ESI + 0x4ed4],0xffffffff
    m.w32((s.si+0x00004ed4u), 0xffffffffu);
  }
  L00672414: { // 0x672414: 8b153848aa00 MOV EDX,dword ptr [0x00aa4838]
    s.dx = m.r32((0x00aa4838u));
  }
  L0067241a: { // 0x67241a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0067241b: { // 0x67241b: 0fbf4206 MOVSX EAX,word ptr [EDX + 0x6]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.dx+0x00000006u)),16));
  }
  L0067241f: { // 0x67241f: 8986d04e0000 MOV dword ptr [ESI + 0x4ed0],EAX
    m.w32((s.si+0x00004ed0u), s.ax);
  }
  L00672425: { // 0x672425: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00672426: { // 0x672426: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00672427: { // 0x672427: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0067242a: { // 0x67242a: 8b86d84e0000 MOV EAX,dword ptr [ESI + 0x4ed8]
    s.ax = m.r32((s.si+0x00004ed8u));
  }
  L00672430: { // 0x672430: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L00672432: { // 0x672432: 0f8446010000 JZ 0x0067257e
    if(integer::condition("JZ",flags)) goto L0067257e;
  }
  L00672438: { // 0x672438: 8d0c40 LEA ECX,[EAX + EAX*0x2]
    s.cx = (s.ax+(s.ax * 0x00000002u));
  }
  L0067243b: { // 0x67243b: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0067243c: { // 0x67243c: c1e105 SHL ECX,0x5
    s.cx = integer::shift(s.cx,0x00000005u,32,flags,integer::Shift::left);
  }
  L0067243f: { // 0x67243f: 81c10810aa00 ADD ECX,0xaa1008
    s.cx = integer::add(s.cx,0x00aa1008u,32,flags);
  }
  L00672445: { // 0x672445: e8e6df0600 CALL 0x006e0430
    s.arithmetic_flags=flags; invoke(m,s,f,0x006e0430u,6759498u); flags=s.arithmetic_flags;
  }
  L0067244a: { // 0x67244a: 8b8ed84e0000 MOV ECX,dword ptr [ESI + 0x4ed8]
    s.cx = m.r32((s.si+0x00004ed8u));
  }
  L00672450: { // 0x672450: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00672452: { // 0x672452: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L00672455: { // 0x672455: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00672457: { // 0x672457: 8d14c0 LEA EDX,[EAX + EAX*0x8]
    s.dx = (s.ax+(s.ax * 0x00000008u));
  }
  L0067245a: { // 0x67245a: 8d0451 LEA EAX,[ECX + EDX*0x2]
    s.ax = (s.cx+(s.dx * 0x00000002u));
  }
  L0067245d: { // 0x67245d: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00672462: { // 0x672462: 8d0440 LEA EAX,[EAX + EAX*0x2]
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  L00672465: { // 0x672465: 8dac8640150000 LEA EBP,[ESI + EAX*0x4 + 0x1540]
    s.bp = (s.si+(s.ax * 0x00000004u)+0x00001540u);
  }
  L0067246c: { // 0x67246c: 885d18 MOV byte ptr [EBP + 0x18],BL
    m.w8((s.bp+0x00000018u), (s.bx & 0xffu));
  }
  L0067246f: { // 0x67246f: e8ac530000 CALL 0x00677820
    s.arithmetic_flags=flags; invoke(m,s,f,0x00677820u,6759540u); flags=s.arithmetic_flags;
  }
  L00672474: { // 0x672474: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00672476: { // 0x672476: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L0067247a: { // 0x67247a: 7e2c JLE 0x006724a8
    if(integer::condition("JLE",flags)) goto L006724a8;
  }
  L0067247c: { // 0x67247c: 8b4534 MOV EAX,dword ptr [EBP + 0x34]
    s.ax = m.r32((s.bp+0x00000034u));
  }
  L0067247f: { // 0x67247f: 6bc03c IMUL EAX,EAX,0x3c
    s.ax = integer::imul(s.ax,0x0000003cu,32,flags);
  }
  L00672482: { // 0x672482: 03c3 ADD EAX,EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L00672484: { // 0x672484: 8d0cc500000000 LEA ECX,[EAX*0x8 + 0x0]
    s.cx = ((s.ax * 0x00000008u)+0x00000000u);
  }
  L0067248b: { // 0x67248b: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L0067248d: { // 0x67248d: 8d14cd4012aa00 LEA EDX,[ECX*0x8 + 0xaa1240]
    s.dx = ((s.cx * 0x00000008u)+0x00aa1240u);
  }
  L00672494: { // 0x672494: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00672499: { // 0x672499: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0067249a: { // 0x67249a: e8f1dce6ff CALL 0x004e0190
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e0190u,6759583u); flags=s.arithmetic_flags;
  }
  L0067249f: { // 0x67249f: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L006724a3: { // 0x6724a3: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L006724a4: { // 0x6724a4: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L006724a6: { // 0x6724a6: 7cd4 JL 0x0067247c
    if(integer::condition("JL",flags)) goto L0067247c;
  }
  L006724a8: { // 0x6724a8: 8d0c7f LEA ECX,[EDI + EDI*0x2]
    s.cx = (s.di+(s.di * 0x00000002u));
  }
  L006724ab: { // 0x6724ab: 89bed84e0000 MOV dword ptr [ESI + 0x4ed8],EDI
    m.w32((s.si+0x00004ed8u), s.di);
  }
  L006724b1: { // 0x6724b1: c1e105 SHL ECX,0x5
    s.cx = integer::shift(s.cx,0x00000005u,32,flags,integer::Shift::left);
  }
  L006724b4: { // 0x6724b4: 81c10810aa00 ADD ECX,0xaa1008
    s.cx = integer::add(s.cx,0x00aa1008u,32,flags);
  }
  L006724ba: { // 0x6724ba: e861df0600 CALL 0x006e0420
    s.arithmetic_flags=flags; invoke(m,s,f,0x006e0420u,6759615u); flags=s.arithmetic_flags;
  }
  L006724bf: { // 0x6724bf: 8b8ed84e0000 MOV ECX,dword ptr [ESI + 0x4ed8]
    s.cx = m.r32((s.si+0x00004ed8u));
  }
  L006724c5: { // 0x6724c5: b301 MOV BL,0x1
    s.bx = with_al(s.bx, 0x00000001u);
  }
  L006724c7: { // 0x6724c7: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L006724c9: { // 0x6724c9: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L006724cc: { // 0x6724cc: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L006724ce: { // 0x6724ce: 8d04c0 LEA EAX,[EAX + EAX*0x8]
    s.ax = (s.ax+(s.ax * 0x00000008u));
  }
  L006724d1: { // 0x6724d1: 8d0441 LEA EAX,[ECX + EAX*0x2]
    s.ax = (s.cx+(s.ax * 0x00000002u));
  }
  L006724d4: { // 0x6724d4: 8d0c40 LEA ECX,[EAX + EAX*0x2]
    s.cx = (s.ax+(s.ax * 0x00000002u));
  }
  L006724d7: { // 0x6724d7: 8d8c8e40150000 LEA ECX,[ESI + ECX*0x4 + 0x1540]
    s.cx = (s.si+(s.cx * 0x00000004u)+0x00001540u);
  }
  L006724de: { // 0x6724de: 885918 MOV byte ptr [ECX + 0x18],BL
    m.w8((s.cx+0x00000018u), (s.bx & 0xffu));
  }
  L006724e1: { // 0x6724e1: e8aa1b0000 CALL 0x00674090
    s.arithmetic_flags=flags; invoke(m,s,f,0x00674090u,6759654u); flags=s.arithmetic_flags;
  }
  L006724e6: { // 0x6724e6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006724e8: { // 0x6724e8: e8e3520000 CALL 0x006777d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006777d0u,6759661u); flags=s.arithmetic_flags;
  }
  L006724ed: { // 0x6724ed: 8b96d84e0000 MOV EDX,dword ptr [ESI + 0x4ed8]
    s.dx = m.r32((s.si+0x00004ed8u));
  }
  L006724f3: { // 0x6724f3: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006724f4: { // 0x6724f4: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L006724f6: { // 0x6724f6: c1e104 SHL ECX,0x4
    s.cx = integer::shift(s.cx,0x00000004u,32,flags,integer::Shift::left);
  }
  L006724f9: { // 0x6724f9: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L006724fb: { // 0x6724fb: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
  L006724fd: { // 0x6724fd: 8d0cc9 LEA ECX,[ECX + ECX*0x8]
    s.cx = (s.cx+(s.cx * 0x00000008u));
  }
  L00672500: { // 0x672500: 8d0c4a LEA ECX,[EDX + ECX*0x2]
    s.cx = (s.dx+(s.cx * 0x00000002u));
  }
  L00672503: { // 0x672503: 8d1449 LEA EDX,[ECX + ECX*0x2]
    s.dx = (s.cx+(s.cx * 0x00000002u));
  }
  L00672506: { // 0x672506: 8b8c9690150000 MOV ECX,dword ptr [ESI + EDX*0x4 + 0x1590]
    s.cx = m.r32((s.si+(s.dx * 0x00000004u)+0x00001590u));
  }
  L0067250d: { // 0x67250d: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L0067250f: { // 0x67250f: b9f046aa00 MOV ECX,0xaa46f0
    s.cx = 0x00aa46f0u;
  }
  L00672514: { // 0x672514: 7e37 JLE 0x0067254d
    if(integer::condition("JLE",flags)) goto L0067254d;
  }
  L00672516: { // 0x672516: e825c8e5ff CALL 0x004ced40
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced40u,6759707u); flags=s.arithmetic_flags;
  }
  L0067251b: { // 0x67251b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0067251d: { // 0x67251d: 750a JNZ 0x00672529
    if(integer::condition("JNZ",flags)) goto L00672529;
  }
  L0067251f: { // 0x67251f: b9f046aa00 MOV ECX,0xaa46f0
    s.cx = 0x00aa46f0u;
  }
  L00672524: { // 0x672524: e8f7c7e5ff CALL 0x004ced20
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced20u,6759721u); flags=s.arithmetic_flags;
  }
  L00672529: { // 0x672529: b9c847aa00 MOV ECX,0xaa47c8
    s.cx = 0x00aa47c8u;
  }
  L0067252e: { // 0x67252e: e80dc8e5ff CALL 0x004ced40
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced40u,6759731u); flags=s.arithmetic_flags;
  }
  L00672533: { // 0x672533: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00672535: { // 0x672535: 7541 JNZ 0x00672578
    if(integer::condition("JNZ",flags)) goto L00672578;
  }
  L00672537: { // 0x672537: b9c847aa00 MOV ECX,0xaa47c8
    s.cx = 0x00aa47c8u;
  }
  L0067253c: { // 0x67253c: e8dfc7e5ff CALL 0x004ced20
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced20u,6759745u); flags=s.arithmetic_flags;
  }
  L00672541: { // 0x672541: 889ee34e0000 MOV byte ptr [ESI + 0x4ee3],BL
    m.w8((s.si+0x00004ee3u), (s.bx & 0xffu));
  }
  L00672547: { // 0x672547: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00672548: { // 0x672548: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00672549: { // 0x672549: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0067254a: { // 0x67254a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0067254d: { // 0x67254d: e8eec7e5ff CALL 0x004ced40
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced40u,6759762u); flags=s.arithmetic_flags;
  }
  L00672552: { // 0x672552: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00672554: { // 0x672554: 740a JZ 0x00672560
    if(integer::condition("JZ",flags)) goto L00672560;
  }
  L00672556: { // 0x672556: b9f046aa00 MOV ECX,0xaa46f0
    s.cx = 0x00aa46f0u;
  }
  L0067255b: { // 0x67255b: e8d0c7e5ff CALL 0x004ced30
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced30u,6759776u); flags=s.arithmetic_flags;
  }
  L00672560: { // 0x672560: b9c847aa00 MOV ECX,0xaa47c8
    s.cx = 0x00aa47c8u;
  }
  L00672565: { // 0x672565: e8d6c7e5ff CALL 0x004ced40
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced40u,6759786u); flags=s.arithmetic_flags;
  }
  L0067256a: { // 0x67256a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0067256c: { // 0x67256c: 740a JZ 0x00672578
    if(integer::condition("JZ",flags)) goto L00672578;
  }
  L0067256e: { // 0x67256e: b9c847aa00 MOV ECX,0xaa47c8
    s.cx = 0x00aa47c8u;
  }
  L00672573: { // 0x672573: e8b8c7e5ff CALL 0x004ced30
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced30u,6759800u); flags=s.arithmetic_flags;
  }
  L00672578: { // 0x672578: 889ee34e0000 MOV byte ptr [ESI + 0x4ee3],BL
    m.w8((s.si+0x00004ee3u), (s.bx & 0xffu));
  }
  L0067257e: { // 0x67257e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0067257f: { // 0x67257f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00672580: { // 0x672580: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00672581: { // 0x672581: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
