#include "recovered/recovery_b207_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b207 {
namespace {
void f_002c69a0(Memory&,State&,Frame&,const Operations&);
void f_00191430(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_002c69a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006c69a0: { // 0x6c69a0: 8b8108040000 MOV EAX,dword ptr [ECX + 0x408]
    s.ax = m.r32((s.cx+0x00000408u));
  }
  L006c69a6: { // 0x6c69a6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00191430(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00591430: { // 0x591430: b8c2010000 MOV EAX,0x1c2
    s.ax = 0x000001c2u;
  }
  L00591435: { // 0x591435: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 7104928u:f_002c69a0(m,s,child,{});break;
case 5837872u:f_00191430(m,s,child,{});break;
default:throw std::domain_error("recovery207 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0060e630(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0060e630: { // 0x60e630: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0060e633: { // 0x60e633: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0060e634: { // 0x60e634: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0060e635: { // 0x60e635: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0060e636: { // 0x60e636: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0060e637: { // 0x60e637: e864830b00 CALL 0x006c69a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006c69a0u,6350396u); flags=s.arithmetic_flags;
  }
  L0060e63c: { // 0x60e63c: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0060e63e: { // 0x60e63e: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0060e640: { // 0x60e640: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L0060e644: { // 0x60e644: 8b7114 MOV ESI,dword ptr [ECX + 0x14]
    s.si = m.r32((s.cx+0x00000014u));
  }
  L0060e647: { // 0x60e647: 8ba994000000 MOV EBP,dword ptr [ECX + 0x94]
    s.bp = m.r32((s.cx+0x00000094u));
  }
  L0060e64d: { // 0x60e64d: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0060e64f: { // 0x60e64f: 89742410 MOV dword ptr [ESP + 0x10],ESI
    m.w32((f.sp+0x00000010u), s.si);
  }
  L0060e653: { // 0x60e653: 7425 JZ 0x0060e67a
    if(integer::condition("JZ",flags)) goto L0060e67a;
  }
  L0060e655: { // 0x60e655: 7f1b JG 0x0060e672
    if(integer::condition("JG",flags)) goto L0060e672;
  }
  L0060e657: { // 0x60e657: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0060e659: { // 0x60e659: 7f02 JG 0x0060e65d
    if(integer::condition("JG",flags)) goto L0060e65d;
  }
  L0060e65b: { // 0x60e65b: 751d JNZ 0x0060e67a
    if(integer::condition("JNZ",flags)) goto L0060e67a;
  }
  L0060e65d: { // 0x60e65d: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L0060e65f: { // 0x60e65f: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L0060e661: { // 0x60e661: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0060e662: { // 0x60e662: f7b990000000 IDIV dword ptr [ECX + 0x90]
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(m.r32((s.cx+0x00000090u)),32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L0060e668: { // 0x60e668: 03d5 ADD EDX,EBP
    s.dx = integer::add(s.dx,s.bp,32,flags);
  }
  L0060e66a: { // 0x60e66a: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0060e66c: { // 0x60e66c: 7c0c JL 0x0060e67a
    if(integer::condition("JL",flags)) goto L0060e67a;
  }
  L0060e66e: { // 0x60e66e: 3bd6 CMP EDX,ESI
    (void)integer::sub(s.dx,s.si,32,flags);
  }
  L0060e670: { // 0x60e670: 7d08 JGE 0x0060e67a
    if(integer::condition("JGE",flags)) goto L0060e67a;
  }
  L0060e672: { // 0x60e672: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L0060e675: { // 0x60e675: 8b3c90 MOV EDI,dword ptr [EAX + EDX*0x4]
    s.di = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L0060e678: { // 0x60e678: eb02 JMP 0x0060e67c
    goto L0060e67c;
  }
  L0060e67a: { // 0x60e67a: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0060e67c: { // 0x60e67c: 8b5f10 MOV EBX,dword ptr [EDI + 0x10]
    s.bx = m.r32((s.di+0x00000010u));
  }
  L0060e67f: { // 0x60e67f: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0060e681: { // 0x60e681: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L0060e683: { // 0x60e683: 0f8e8e000000 JLE 0x0060e717
    if(integer::condition("JLE",flags)) goto L0060e717;
  }
  L0060e689: { // 0x60e689: 8b4f04 MOV ECX,dword ptr [EDI + 0x4]
    s.cx = m.r32((s.di+0x00000004u));
  }
  L0060e68c: { // 0x60e68c: 8b14b1 MOV EDX,dword ptr [ECX + ESI*0x4]
    s.dx = m.r32((s.cx+(s.si * 0x00000004u)));
  }
  L0060e68f: { // 0x60e68f: 8b0a MOV ECX,dword ptr [EDX]
    s.cx = m.r32((s.dx));
  }
  L0060e691: { // 0x60e691: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0060e693: { // 0x60e693: ff904c040000 CALL dword ptr [EAX + 0x44c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000044cu)),6350489u); flags=s.arithmetic_flags;
  }
  L0060e699: { // 0x60e699: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0060e69b: { // 0x60e69b: 750d JNZ 0x0060e6aa
    if(integer::condition("JNZ",flags)) goto L0060e6aa;
  }
  L0060e69d: { // 0x60e69d: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0060e69e: { // 0x60e69e: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L0060e6a0: { // 0x60e6a0: 7ce7 JL 0x0060e689
    if(integer::condition("JL",flags)) goto L0060e689;
  }
  L0060e6a2: { // 0x60e6a2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0060e6a3: { // 0x60e6a3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0060e6a4: { // 0x60e6a4: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0060e6a5: { // 0x60e6a5: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0060e6a6: { // 0x60e6a6: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0060e6a9: { // 0x60e6a9: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0060e6aa: { // 0x60e6aa: 3b6c2410 CMP EBP,dword ptr [ESP + 0x10]
    (void)integer::sub(s.bp,m.r32((f.sp+0x00000010u)),32,flags);
  }
  L0060e6ae: { // 0x60e6ae: 7d67 JGE 0x0060e717
    if(integer::condition("JGE",flags)) goto L0060e717;
  }
  L0060e6b0: { // 0x60e6b0: b302 MOV BL,0x2
    s.bx = with_al(s.bx, 0x00000002u);
  }
  L0060e6b2: { // 0x60e6b2: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L0060e6b6: { // 0x60e6b6: 8bd5 MOV EDX,EBP
    s.dx = s.bp;
  }
  L0060e6b8: { // 0x60e6b8: 8b7714 MOV ESI,dword ptr [EDI + 0x14]
    s.si = m.r32((s.di+0x00000014u));
  }
  L0060e6bb: { // 0x60e6bb: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0060e6bd: { // 0x60e6bd: 742d JZ 0x0060e6ec
    if(integer::condition("JZ",flags)) goto L0060e6ec;
  }
  L0060e6bf: { // 0x60e6bf: 3bee CMP EBP,ESI
    (void)integer::sub(s.bp,s.si,32,flags);
  }
  L0060e6c1: { // 0x60e6c1: 7c19 JL 0x0060e6dc
    if(integer::condition("JL",flags)) goto L0060e6dc;
  }
  L0060e6c3: { // 0x60e6c3: 8b8f94000000 MOV ECX,dword ptr [EDI + 0x94]
    s.cx = m.r32((s.di+0x00000094u));
  }
  L0060e6c9: { // 0x60e6c9: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0060e6cb: { // 0x60e6cb: 7f02 JG 0x0060e6cf
    if(integer::condition("JG",flags)) goto L0060e6cf;
  }
  L0060e6cd: { // 0x60e6cd: 751d JNZ 0x0060e6ec
    if(integer::condition("JNZ",flags)) goto L0060e6ec;
  }
  L0060e6cf: { // 0x60e6cf: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L0060e6d1: { // 0x60e6d1: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L0060e6d3: { // 0x60e6d3: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0060e6d4: { // 0x60e6d4: f7bf90000000 IDIV dword ptr [EDI + 0x90]
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(m.r32((s.di+0x00000090u)),32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L0060e6da: { // 0x60e6da: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L0060e6dc: { // 0x60e6dc: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0060e6de: { // 0x60e6de: 7c0c JL 0x0060e6ec
    if(integer::condition("JL",flags)) goto L0060e6ec;
  }
  L0060e6e0: { // 0x60e6e0: 3bd6 CMP EDX,ESI
    (void)integer::sub(s.dx,s.si,32,flags);
  }
  L0060e6e2: { // 0x60e6e2: 7d08 JGE 0x0060e6ec
    if(integer::condition("JGE",flags)) goto L0060e6ec;
  }
  L0060e6e4: { // 0x60e6e4: 8b4f08 MOV ECX,dword ptr [EDI + 0x8]
    s.cx = m.r32((s.di+0x00000008u));
  }
  L0060e6e7: { // 0x60e6e7: 8b1491 MOV EDX,dword ptr [ECX + EDX*0x4]
    s.dx = m.r32((s.cx+(s.dx * 0x00000004u)));
  }
  L0060e6ea: { // 0x60e6ea: eb02 JMP 0x0060e6ee
    goto L0060e6ee;
  }
  L0060e6ec: { // 0x60e6ec: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0060e6ee: { // 0x60e6ee: 8b7210 MOV ESI,dword ptr [EDX + 0x10]
    s.si = m.r32((s.dx+0x00000010u));
  }
  L0060e6f1: { // 0x60e6f1: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0060e6f3: { // 0x60e6f3: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0060e6f5: { // 0x60e6f5: 7e17 JLE 0x0060e70e
    if(integer::condition("JLE",flags)) goto L0060e70e;
  }
  L0060e6f7: { // 0x60e6f7: 8b4204 MOV EAX,dword ptr [EDX + 0x4]
    s.ax = m.r32((s.dx+0x00000004u));
  }
  L0060e6fa: { // 0x60e6fa: 8b0488 MOV EAX,dword ptr [EAX + ECX*0x4]
    s.ax = m.r32((s.ax+(s.cx * 0x00000004u)));
  }
  L0060e6fd: { // 0x60e6fd: 8b4004 MOV EAX,dword ptr [EAX + 0x4]
    s.ax = m.r32((s.ax+0x00000004u));
  }
  L0060e700: { // 0x60e700: 38580c CMP byte ptr [EAX + 0xc],BL
    (void)integer::sub(m.r8((s.ax+0x0000000cu)),(s.bx & 0xffu),8,flags);
  }
  L0060e703: { // 0x60e703: 7504 JNZ 0x0060e709
    if(integer::condition("JNZ",flags)) goto L0060e709;
  }
  L0060e705: { // 0x60e705: c6400c1d MOV byte ptr [EAX + 0xc],0x1d
    m.w8((s.ax+0x0000000cu), 0x0000001du);
  }
  L0060e709: { // 0x60e709: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0060e70a: { // 0x60e70a: 3bce CMP ECX,ESI
    (void)integer::sub(s.cx,s.si,32,flags);
  }
  L0060e70c: { // 0x60e70c: 7ce9 JL 0x0060e6f7
    if(integer::condition("JL",flags)) goto L0060e6f7;
  }
  L0060e70e: { // 0x60e70e: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0060e712: { // 0x60e712: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L0060e713: { // 0x60e713: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L0060e715: { // 0x60e715: 7c9b JL 0x0060e6b2
    if(integer::condition("JL",flags)) goto L0060e6b2;
  }
  L0060e717: { // 0x60e717: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0060e718: { // 0x60e718: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0060e719: { // 0x60e719: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0060e71a: { // 0x60e71a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0060e71b: { // 0x60e71b: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0060e71e: { // 0x60e71e: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
