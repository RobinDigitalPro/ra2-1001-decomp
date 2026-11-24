#include "recovered/recovery_b717_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b717 {
namespace {
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_0001b320(Memory&,State&,Frame&,const Operations&);
void f_002abc60(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

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
void f_0001b320(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0041b320: { // 0x41b320: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0041b321: { // 0x41b321: 8b8188000000 MOV EAX, dword ptr [ECX + 0x88]
    s.ax = m.r32((s.cx+0x00000088u));
  }
  L0041b327: { // 0x41b327: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0041b328: { // 0x41b328: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0041b32e: { // 0x41b32e: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0041b330: { // 0x41b330: c1f808 SAR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L0041b333: { // 0x41b333: 6689442400 MOV word ptr [ESP], AX
    m.w16((f.sp), (s.ax & 0xffffu));
  }
  L0041b338: { // 0x41b338: 8b818c000000 MOV EAX, dword ptr [ECX + 0x8c]
    s.ax = m.r32((s.cx+0x0000008cu));
  }
  L0041b33e: { // 0x41b33e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0041b33f: { // 0x41b33f: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0041b345: { // 0x41b345: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0041b347: { // 0x41b347: c1f808 SAR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L0041b34a: { // 0x41b34a: 6689442402 MOV word ptr [ESP + 2], AX
    m.w16((f.sp+2u), (s.ax & 0xffffu));
  }
  L0041b34f: { // 0x41b34f: 8b442408 MOV EAX, dword ptr [ESP + 8]
    s.ax = m.r32((f.sp+8u));
  }
  L0041b353: { // 0x41b353: 8b4c2400 MOV ECX, dword ptr [ESP]
    s.cx = m.r32((f.sp));
  }
  L0041b357: { // 0x41b357: 8908 MOV dword ptr [EAX], ECX
    m.w32((s.ax), s.cx);
  }
  L0041b359: { // 0x41b359: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0041b35a: { // 0x41b35a: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_002abc60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006abc60: { // 0x6abc60: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006abc61: { // 0x6abc61: 8079040b CMP byte ptr [ECX + 4], 0xb
    (void)integer::sub(m.r8((s.cx+4u)),0x0000000bu,8,flags);
  }
  L006abc65: { // 0x6abc65: 753a JNZ 0x6abca1
    if(integer::condition("JNZ",flags)) goto L006abca1;
  }
  L006abc67: { // 0x6abc67: 8b09 MOV ECX, dword ptr [ECX]
    s.cx = m.r32((s.cx));
  }
  L006abc69: { // 0x6abc69: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006abc6a: { // 0x6abc6a: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L006abc6c: { // 0x6abc6c: bee8030000 MOV ESI, 0x3e8
    s.si = 0x000003e8u;
  }
  L006abc71: { // 0x6abc71: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006abc72: { // 0x6abc72: f7fe IDIV ESI
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.si,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L006abc74: { // 0x6abc74: b8d34d6210 MOV EAX, 0x10624dd3
    s.ax = 0x10624dd3u;
  }
  L006abc79: { // 0x6abc79: 6689542404 MOV word ptr [ESP + 4], DX
    m.w16((f.sp+4u), (s.dx & 0xffffu));
  }
  L006abc7e: { // 0x6abc7e: f7e9 IMUL ECX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.cx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  L006abc80: { // 0x6abc80: c1fa06 SAR EDX, 6
    s.dx = integer::shift(s.dx,6u,32,flags,integer::Shift::arithmetic_right);
  }
  L006abc83: { // 0x6abc83: 8bc2 MOV EAX, EDX
    s.ax = s.dx;
  }
  L006abc85: { // 0x6abc85: 8d4c2404 LEA ECX, [ESP + 4]
    s.cx = (f.sp+4u);
  }
  L006abc89: { // 0x6abc89: c1e81f SHR EAX, 0x1f
    s.ax = integer::shift(s.ax,0x0000001fu,32,flags,integer::Shift::right);
  }
  L006abc8c: { // 0x6abc8c: 03d0 ADD EDX, EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L006abc8e: { // 0x6abc8e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006abc8f: { // 0x6abc8f: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L006abc94: { // 0x6abc94: 668954240a MOV word ptr [ESP + 0xa], DX
    m.w16((f.sp+0x0000000au), (s.dx & 0xffffu));
  }
  L006abc99: { // 0x6abc99: e86298e9ff CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6995102u); flags=s.arithmetic_flags;
  }
  L006abc9e: { // 0x6abc9e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006abc9f: { // 0x6abc9f: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L006abca0: { // 0x6abca0: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L006abca1: { // 0x6abca1: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006abca3: { // 0x6abca3: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L006abca4: { // 0x6abca4: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 5526784u:f_00145500(m,s,child,{});break;
case 4305696u:f_0001b320(m,s,child,{});break;
case 6995040u:f_002abc60(m,s,child,{});break;
default:throw std::domain_error("recovery717 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0060d4f0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0060d4f0: { // 0x60d4f0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0060d4f3: { // 0x60d4f3: 83fa0b CMP EDX,0xb
    (void)integer::sub(s.dx,0x0000000bu,32,flags);
  }
  L0060d4f6: { // 0x60d4f6: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0060d4f7: { // 0x60d4f7: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0060d4f9: { // 0x60d4f9: 0f858f000000 JNZ 0x0060d58e
    if(integer::condition("JNZ",flags)) goto L0060d58e;
  }
  L0060d4ff: { // 0x60d4ff: 8a442414 MOV AL,byte ptr [ESP + 0x14]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000014u)));
  }
  L0060d503: { // 0x60d503: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0060d505: { // 0x60d505: 7509 JNZ 0x0060d510
    if(integer::condition("JNZ",flags)) goto L0060d510;
  }
  L0060d507: { // 0x60d507: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0060d509: { // 0x60d509: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0060d50a: { // 0x60d50a: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0060d50d: { // 0x60d50d: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0060d510: { // 0x60d510: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0060d512: { // 0x60d512: 747a JZ 0x0060d58e
    if(integer::condition("JZ",flags)) goto L0060d58e;
  }
  L0060d514: { // 0x60d514: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0060d516: { // 0x60d516: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  L0060d51a: { // 0x60d51a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0060d51b: { // 0x60d51b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0060d51c: { // 0x60d51c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0060d51e: { // 0x60d51e: ff90a0010000 CALL dword ptr [EAX + 0x1a0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000001a0u)),6346020u); flags=s.arithmetic_flags;
  }
  L0060d524: { // 0x60d524: 8b38 MOV EDI,dword ptr [EAX]
    s.di = m.r32((s.ax));
  }
  L0060d526: { // 0x60d526: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0060d528: { // 0x60d528: 8d442408 LEA EAX,[ESP + 0x8]
    s.ax = (f.sp+0x00000008u);
  }
  L0060d52c: { // 0x60d52c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0060d52e: { // 0x60d52e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0060d52f: { // 0x60d52f: 897c2410 MOV dword ptr [ESP + 0x10],EDI
    m.w32((f.sp+0x00000010u), s.di);
  }
  L0060d533: { // 0x60d533: ff92a0010000 CALL dword ptr [EDX + 0x1a0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001a0u)),6346041u); flags=s.arithmetic_flags;
  }
  L0060d539: { // 0x60d539: 8b30 MOV ESI,dword ptr [EAX]
    s.si = m.r32((s.ax));
  }
  L0060d53b: { // 0x60d53b: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L0060d53f: { // 0x60d53f: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  L0060d543: { // 0x60d543: e818e70900 CALL 0x006abc60
    s.arithmetic_flags=flags; invoke(m,s,f,0x006abc60u,6346056u); flags=s.arithmetic_flags;
  }
  L0060d548: { // 0x60d548: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0060d54a: { // 0x60d54a: 7405 JZ 0x0060d551
    if(integer::condition("JZ",flags)) goto L0060d551;
  }
  L0060d54c: { // 0x60d54c: 8b7024 MOV ESI,dword ptr [EAX + 0x24]
    s.si = m.r32((s.ax+0x00000024u));
  }
  L0060d54f: { // 0x60d54f: eb1e JMP 0x0060d56f
    goto L0060d56f;
  }
  L0060d551: { // 0x60d551: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L0060d555: { // 0x60d555: e806da0900 CALL 0x006aaf60
    s.arithmetic_flags=flags; invoke(m,s,f,0x006aaf60u,6346074u); flags=s.arithmetic_flags;
  }
  L0060d55a: { // 0x60d55a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0060d55c: { // 0x60d55c: 7415 JZ 0x0060d573
    if(integer::condition("JZ",flags)) goto L0060d573;
  }
  L0060d55e: { // 0x60d55e: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0060d560: { // 0x60d560: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  L0060d564: { // 0x60d564: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0060d565: { // 0x60d565: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0060d567: { // 0x60d567: ff92a0010000 CALL dword ptr [EDX + 0x1a0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001a0u)),6346093u); flags=s.arithmetic_flags;
  }
  L0060d56d: { // 0x60d56d: 8b30 MOV ESI,dword ptr [EAX]
    s.si = m.r32((s.ax));
  }
  L0060d56f: { // 0x60d56f: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  L0060d573: { // 0x60d573: 663bfe CMP DI,SI
    (void)integer::sub((s.di & 0xffffu),(s.si & 0xffffu),16,flags);
  }
  L0060d576: { // 0x60d576: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0060d577: { // 0x60d577: 7515 JNZ 0x0060d58e
    if(integer::condition("JNZ",flags)) goto L0060d58e;
  }
  L0060d579: { // 0x60d579: 668b54240a MOV DX,word ptr [ESP + 0xa]
    s.dx = with_ax(s.dx, m.r16((f.sp+0x0000000au)));
  }
  L0060d57e: { // 0x60d57e: 663b542406 CMP DX,word ptr [ESP + 0x6]
    (void)integer::sub((s.dx & 0xffffu),m.r16((f.sp+0x00000006u)),16,flags);
  }
  L0060d583: { // 0x60d583: 7509 JNZ 0x0060d58e
    if(integer::condition("JNZ",flags)) goto L0060d58e;
  }
  L0060d585: { // 0x60d585: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0060d587: { // 0x60d587: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0060d588: { // 0x60d588: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0060d58b: { // 0x60d58b: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0060d58e: { // 0x60d58e: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0060d590: { // 0x60d590: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0060d591: { // 0x60d591: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0060d594: { // 0x60d594: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
