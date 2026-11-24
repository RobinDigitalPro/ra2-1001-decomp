#include "recovered/recovery_b728_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b728 {
namespace {
void f_00157450(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_00157450(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00557450: { // 0x557450: 8a442408 MOV AL, byte ptr [ESP + 8]
    s.ax = with_al(s.ax, m.r8((f.sp+8u)));
  }
  L00557454: { // 0x557454: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00557455: { // 0x557455: 8b5c2408 MOV EBX, dword ptr [ESP + 8]
    s.bx = m.r32((f.sp+8u));
  }
  L00557459: { // 0x557459: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0055745a: { // 0x55745a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0055745b: { // 0x55745b: 33f6 XOR ESI, ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0055745d: { // 0x55745d: 0fbf5302 MOVSX EDX, word ptr [EBX + 2]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.bx+2u)),16));
  }
  L00557461: { // 0x557461: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00557462: { // 0x557462: 0fbf3b MOVSX EDI, word ptr [EBX]
    s.di = std::uint32_t(integer::sign_extend(m.r16((s.bx)),16));
  }
  L00557465: { // 0x557465: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00557467: { // 0x557467: 7454 JZ 0x5574bd
    if(integer::condition("JZ",flags)) goto L005574bd;
  }
  L00557469: { // 0x557469: 8bc2 MOV EAX, EDX
    s.ax = s.dx;
  }
  L0055746b: { // 0x55746b: c1e009 SHL EAX, 9
    s.ax = integer::shift(s.ax,9u,32,flags,integer::Shift::left);
  }
  L0055746e: { // 0x55746e: 03c7 ADD EAX, EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L00557470: { // 0x557470: 7814 JS 0x557486
    if(integer::condition("JS",flags)) goto L00557486;
  }
  L00557472: { // 0x557472: 3d00000400 CMP EAX, 0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00557477: { // 0x557477: 7d0d JGE 0x557486
    if(integer::condition("JGE",flags)) goto L00557486;
  }
  L00557479: { // 0x557479: 8b3558a98100 MOV ESI, dword ptr [0x81a958]
    s.si = m.r32((0x0081a958u));
  }
  L0055747f: { // 0x55747f: 8b0486 MOV EAX, dword ptr [ESI + EAX*4]
    s.ax = m.r32((s.si+(s.ax * 4u)));
  }
  L00557482: { // 0x557482: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00557484: { // 0x557484: 750c JNZ 0x557492
    if(integer::condition("JNZ",flags)) goto L00557492;
  }
  L00557486: { // 0x557486: 8b03 MOV EAX, dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L00557488: { // 0x557488: a33476a500 MOV dword ptr [0xa57634], EAX
    m.w32((0x00a57634u), s.ax);
  }
  L0055748d: { // 0x55748d: b81076a500 MOV EAX, 0xa57610
    s.ax = 0x00a57610u;
  }
  L00557492: { // 0x557492: 8a981c010000 MOV BL, byte ptr [EAX + 0x11c]
    s.bx = with_al(s.bx, m.r8((s.ax+0x0000011cu)));
  }
  L00557498: { // 0x557498: 0fbeb01b010000 MOVSX ESI, byte ptr [EAX + 0x11b]
    s.si = std::uint32_t(integer::sign_extend(m.r8((s.ax+0x0000011bu)),8));
  }
  L0055749f: { // 0x55749f: 84db TEST BL, BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L005574a1: { // 0x5574a1: 741a JZ 0x5574bd
    if(integer::condition("JZ",flags)) goto L005574bd;
  }
  L005574a3: { // 0x5574a3: 8b81fc000000 MOV EAX, dword ptr [ECX + 0xfc]
    s.ax = m.r32((s.cx+0x000000fcu));
  }
  L005574a9: { // 0x5574a9: 8b99f0000000 MOV EBX, dword ptr [ECX + 0xf0]
    s.bx = m.r32((s.cx+0x000000f0u));
  }
  L005574af: { // 0x5574af: 8d444304 LEA EAX, [EBX + EAX*2 + 4]
    s.ax = (s.bx+(s.ax * 2u)+4u);
  }
  L005574b3: { // 0x5574b3: 8d1c3a LEA EBX, [EDX + EDI]
    s.bx = (s.dx+s.di);
  }
  L005574b6: { // 0x5574b6: 03c6 ADD EAX, ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L005574b8: { // 0x5574b8: 3bd8 CMP EBX, EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L005574ba: { // 0x5574ba: 7d01 JGE 0x5574bd
    if(integer::condition("JGE",flags)) goto L005574bd;
  }
  L005574bc: { // 0x5574bc: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L005574bd: { // 0x5574bd: 8b99fc000000 MOV EBX, dword ptr [ECX + 0xfc]
    s.bx = m.r32((s.cx+0x000000fcu));
  }
  L005574c3: { // 0x5574c3: 8b81f0000000 MOV EAX, dword ptr [ECX + 0xf0]
    s.ax = m.r32((s.cx+0x000000f0u));
  }
  L005574c9: { // 0x5574c9: 8d2c3a LEA EBP, [EDX + EDI]
    s.bp = (s.dx+s.di);
  }
  L005574cc: { // 0x5574cc: 8d1c58 LEA EBX, [EAX + EBX*2]
    s.bx = (s.ax+(s.bx * 2u));
  }
  L005574cf: { // 0x5574cf: 03de ADD EBX, ESI
    s.bx = integer::add(s.bx,s.si,32,flags);
  }
  L005574d1: { // 0x5574d1: 3beb CMP EBP, EBX
    (void)integer::sub(s.bp,s.bx,32,flags);
  }
  L005574d3: { // 0x5574d3: 7e49 JLE 0x55751e
    if(integer::condition("JLE",flags)) goto L0055751e;
  }
  L005574d5: { // 0x5574d5: 8b9904010000 MOV EBX, dword ptr [ECX + 0x104]
    s.bx = m.r32((s.cx+0x00000104u));
  }
  L005574db: { // 0x5574db: 8ba9fc000000 MOV EBP, dword ptr [ECX + 0xfc]
    s.bp = m.r32((s.cx+0x000000fcu));
  }
  L005574e1: { // 0x5574e1: 03dd ADD EBX, EBP
    s.bx = integer::add(s.bx,s.bp,32,flags);
  }
  L005574e3: { // 0x5574e3: 8d5c5802 LEA EBX, [EAX + EBX*2 + 2]
    s.bx = (s.ax+(s.bx * 2u)+2u);
  }
  L005574e7: { // 0x5574e7: 03de ADD EBX, ESI
    s.bx = integer::add(s.bx,s.si,32,flags);
  }
  L005574e9: { // 0x5574e9: 8d343a LEA ESI, [EDX + EDI]
    s.si = (s.dx+s.di);
  }
  L005574ec: { // 0x5574ec: 3bf3 CMP ESI, EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L005574ee: { // 0x5574ee: 7f2e JG 0x55751e
    if(integer::condition("JG",flags)) goto L0055751e;
  }
  L005574f0: { // 0x5574f0: 8bb1f8000000 MOV ESI, dword ptr [ECX + 0xf8]
    s.si = m.r32((s.cx+0x000000f8u));
  }
  L005574f6: { // 0x5574f6: 8b8900010000 MOV ECX, dword ptr [ECX + 0x100]
    s.cx = m.r32((s.cx+0x00000100u));
  }
  L005574fc: { // 0x5574fc: 03ce ADD ECX, ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L005574fe: { // 0x5574fe: 8bdf MOV EBX, EDI
    s.bx = s.di;
  }
  L00557500: { // 0x557500: d1e1 SHL ECX, 1
    s.cx = integer::shift(s.cx,1u,32,flags,integer::Shift::left);
  }
  L00557502: { // 0x557502: 2bc8 SUB ECX, EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00557504: { // 0x557504: 2bda SUB EBX, EDX
    s.bx = integer::sub(s.bx,s.dx,32,flags);
  }
  L00557506: { // 0x557506: 3bd9 CMP EBX, ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L00557508: { // 0x557508: 7d14 JGE 0x55751e
    if(integer::condition("JGE",flags)) goto L0055751e;
  }
  L0055750a: { // 0x55750a: 8d0c36 LEA ECX, [ESI + ESI]
    s.cx = (s.si+s.si);
  }
  L0055750d: { // 0x55750d: 2bd7 SUB EDX, EDI
    s.dx = integer::sub(s.dx,s.di,32,flags);
  }
  L0055750f: { // 0x55750f: 2bc1 SUB EAX, ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00557511: { // 0x557511: 3bd0 CMP EDX, EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L00557513: { // 0x557513: 7d09 JGE 0x55751e
    if(integer::condition("JGE",flags)) goto L0055751e;
  }
  L00557515: { // 0x557515: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00557516: { // 0x557516: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00557517: { // 0x557517: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00557518: { // 0x557518: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L0055751a: { // 0x55751a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0055751b: { // 0x55751b: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0055751e: { // 0x55751e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0055751f: { // 0x55751f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00557520: { // 0x557520: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00557521: { // 0x557521: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00557523: { // 0x557523: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00557524: { // 0x557524: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 5600336u:f_00157450(m,s,child,{});break;
default:throw std::domain_error("recovery728 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00478b40(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00478b40: { // 0x478b40: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00478b41: { // 0x478b41: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00478b42: { // 0x478b42: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00478b43: { // 0x478b43: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L00478b45: { // 0x478b45: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00478b47: { // 0x478b47: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00478b4c: { // 0x478b4c: 8d4724 LEA EAX,[EDI + 0x24]
    s.ax = (s.di+0x00000024u);
  }
  L00478b4f: { // 0x478b4f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00478b50: { // 0x478b50: e8fbe80d00 CALL 0x00557450
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557450u,4688725u); flags=s.arithmetic_flags;
  }
  L00478b55: { // 0x478b55: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00478b57: { // 0x478b57: 750b JNZ 0x00478b64
    if(integer::condition("JNZ",flags)) goto L00478b64;
  }
  L00478b59: { // 0x478b59: c7474c07000000 MOV dword ptr [EDI + 0x4c],0x7
    m.w32((s.di+0x0000004cu), 0x00000007u);
  }
  L00478b60: { // 0x478b60: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00478b61: { // 0x478b61: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00478b62: { // 0x478b62: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00478b63: { // 0x478b63: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00478b64: { // 0x478b64: 8b4744 MOV EAX,dword ptr [EDI + 0x44]
    s.ax = m.r32((s.di+0x00000044u));
  }
  L00478b67: { // 0x478b67: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00478b6a: { // 0x478b6a: 747e JZ 0x00478bea
    if(integer::condition("JZ",flags)) goto L00478bea;
  }
  L00478b6c: { // 0x478b6c: 8b0d1ce1a100 MOV ECX,dword ptr [0x00a1e11c]
    s.cx = m.r32((0x00a1e11cu));
  }
  L00478b72: { // 0x478b72: 8b0c81 MOV ECX,dword ptr [ECX + EAX*0x4]
    s.cx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L00478b75: { // 0x478b75: 8a81fd010000 MOV AL,byte ptr [ECX + 0x1fd]
    s.ax = with_al(s.ax, m.r8((s.cx+0x000001fdu)));
  }
  L00478b7b: { // 0x478b7b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00478b7d: { // 0x478b7d: 740b JZ 0x00478b8a
    if(integer::condition("JZ",flags)) goto L00478b8a;
  }
  L00478b7f: { // 0x478b7f: c7474c01000000 MOV dword ptr [EDI + 0x4c],0x1
    m.w32((s.di+0x0000004cu), 0x00000001u);
  }
  L00478b86: { // 0x478b86: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00478b87: { // 0x478b87: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00478b88: { // 0x478b88: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00478b89: { // 0x478b89: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00478b8a: { // 0x478b8a: 8a8178020000 MOV AL,byte ptr [ECX + 0x278]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000278u)));
  }
  L00478b90: { // 0x478b90: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00478b92: { // 0x478b92: 740b JZ 0x00478b9f
    if(integer::condition("JZ",flags)) goto L00478b9f;
  }
  L00478b94: { // 0x478b94: c7474c02000000 MOV dword ptr [EDI + 0x4c],0x2
    m.w32((s.di+0x0000004cu), 0x00000002u);
  }
  L00478b9b: { // 0x478b9b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00478b9c: { // 0x478b9c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00478b9d: { // 0x478b9d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00478b9e: { // 0x478b9e: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00478b9f: { // 0x478b9f: 8b8168020000 MOV EAX,dword ptr [ECX + 0x268]
    s.ax = m.r32((s.cx+0x00000268u));
  }
  L00478ba5: { // 0x478ba5: 8d14c0 LEA EDX,[EAX + EAX*0x8]
    s.dx = (s.ax+(s.ax * 0x00000008u));
  }
  L00478ba8: { // 0x478ba8: d90495d8918300 FLD float ptr [EDX*0x4 + 0x8391d8]
    const auto address=((s.dx * 0x00000004u)+0x008391d8u);
    s.fp.load32(m.r32(address));
  }
  L00478baf: { // 0x478baf: d81d38577800 FCOMP float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.compare_pop32(m.r32(address));
  }
  L00478bb5: { // 0x478bb5: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00478bb7: { // 0x478bb7: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L00478bba: { // 0x478bba: 740b JZ 0x00478bc7
    if(integer::condition("JZ",flags)) goto L00478bc7;
  }
  L00478bbc: { // 0x478bbc: c7474c06000000 MOV dword ptr [EDI + 0x4c],0x6
    m.w32((s.di+0x0000004cu), 0x00000006u);
  }
  L00478bc3: { // 0x478bc3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00478bc4: { // 0x478bc4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00478bc5: { // 0x478bc5: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00478bc6: { // 0x478bc6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00478bc7: { // 0x478bc7: 8a8185020000 MOV AL,byte ptr [ECX + 0x285]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000285u)));
  }
  L00478bcd: { // 0x478bcd: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00478bcf: { // 0x478bcf: 740b JZ 0x00478bdc
    if(integer::condition("JZ",flags)) goto L00478bdc;
  }
  L00478bd1: { // 0x478bd1: c7474c06000000 MOV dword ptr [EDI + 0x4c],0x6
    m.w32((s.di+0x0000004cu), 0x00000006u);
  }
  L00478bd8: { // 0x478bd8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00478bd9: { // 0x478bd9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00478bda: { // 0x478bda: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00478bdb: { // 0x478bdb: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00478bdc: { // 0x478bdc: 8a8184020000 MOV AL,byte ptr [ECX + 0x284]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000284u)));
  }
  L00478be2: { // 0x478be2: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00478be4: { // 0x478be4: 0f85aa000000 JNZ 0x00478c94
    if(integer::condition("JNZ",flags)) goto L00478c94;
  }
  L00478bea: { // 0x478bea: 8b87ec000000 MOV EAX,dword ptr [EDI + 0xec]
    s.ax = m.r32((s.di+0x000000ecu));
  }
  L00478bf0: { // 0x478bf0: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  L00478bf3: { // 0x478bf3: 750b JNZ 0x00478c00
    if(integer::condition("JNZ",flags)) goto L00478c00;
  }
  L00478bf5: { // 0x478bf5: c7474c04000000 MOV dword ptr [EDI + 0x4c],0x4
    m.w32((s.di+0x0000004cu), 0x00000004u);
  }
  L00478bfc: { // 0x478bfc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00478bfd: { // 0x478bfd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00478bfe: { // 0x478bfe: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00478bff: { // 0x478bff: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00478c00: { // 0x478c00: bd06000000 MOV EBP,0x6
    s.bp = 0x00000006u;
  }
  L00478c05: { // 0x478c05: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L00478c07: { // 0x478c07: 750b JNZ 0x00478c14
    if(integer::condition("JNZ",flags)) goto L00478c14;
  }
  L00478c09: { // 0x478c09: c7474c03000000 MOV dword ptr [EDI + 0x4c],0x3
    m.w32((s.di+0x0000004cu), 0x00000003u);
  }
  L00478c10: { // 0x478c10: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00478c11: { // 0x478c11: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00478c12: { // 0x478c12: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00478c13: { // 0x478c13: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00478c14: { // 0x478c14: 8d04c0 LEA EAX,[EAX + EAX*0x8]
    s.ax = (s.ax+(s.ax * 0x00000008u));
  }
  L00478c17: { // 0x478c17: d90485d8918300 FLD float ptr [EAX*0x4 + 0x8391d8]
    const auto address=((s.ax * 0x00000004u)+0x008391d8u);
    s.fp.load32(m.r32(address));
  }
  L00478c1e: { // 0x478c1e: dc1d18757800 FCOMP double ptr [0x00787518]
    const auto address=(0x00787518u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00478c24: { // 0x478c24: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00478c26: { // 0x478c26: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L00478c29: { // 0x478c29: 7407 JZ 0x00478c32
    if(integer::condition("JZ",flags)) goto L00478c32;
  }
  L00478c2b: { // 0x478c2b: 896f4c MOV dword ptr [EDI + 0x4c],EBP
    m.w32((s.di+0x0000004cu), s.bp);
  }
  L00478c2e: { // 0x478c2e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00478c2f: { // 0x478c2f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00478c30: { // 0x478c30: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00478c31: { // 0x478c31: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00478c32: { // 0x478c32: 8bb7e4000000 MOV ESI,dword ptr [EDI + 0xe4]
    s.si = m.r32((s.di+0x000000e4u));
  }
  L00478c38: { // 0x478c38: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00478c3a: { // 0x478c3a: 7458 JZ 0x00478c94
    if(integer::condition("JZ",flags)) goto L00478c94;
  }
  L00478c3c: { // 0x478c3c: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00478c3e: { // 0x478c3e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00478c40: { // 0x478c40: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),4688963u); flags=s.arithmetic_flags;
  }
  L00478c43: { // 0x478c43: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L00478c45: { // 0x478c45: 7407 JZ 0x00478c4e
    if(integer::condition("JZ",flags)) goto L00478c4e;
  }
  L00478c47: { // 0x478c47: 83f824 CMP EAX,0x24
    (void)integer::sub(s.ax,0x00000024u,32,flags);
  }
  L00478c4a: { // 0x478c4a: 7453 JZ 0x00478c9f
    if(integer::condition("JZ",flags)) goto L00478c9f;
  }
  L00478c4c: { // 0x478c4c: eb3f JMP 0x00478c8d
    goto L00478c8d;
  }
  L00478c4e: { // 0x478c4e: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L00478c54: { // 0x478c54: 8a885a130000 MOV CL,byte ptr [EAX + 0x135a]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0000135au)));
  }
  L00478c5a: { // 0x478c5a: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00478c5c: { // 0x478c5c: 7412 JZ 0x00478c70
    if(integer::condition("JZ",flags)) goto L00478c70;
  }
  L00478c5e: { // 0x478c5e: 8b86b4010000 MOV EAX,dword ptr [ESI + 0x1b4]
    s.ax = m.r32((s.si+0x000001b4u));
  }
  L00478c64: { // 0x478c64: 8a8842010000 MOV CL,byte ptr [EAX + 0x142]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000142u)));
  }
  L00478c6a: { // 0x478c6a: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00478c6c: { // 0x478c6c: 75bd JNZ 0x00478c2b
    if(integer::condition("JNZ",flags)) goto L00478c2b;
  }
  L00478c6e: { // 0x478c6e: eb1d JMP 0x00478c8d
    goto L00478c8d;
  }
  L00478c70: { // 0x478c70: 8a8859130000 MOV CL,byte ptr [EAX + 0x1359]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001359u)));
  }
  L00478c76: { // 0x478c76: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00478c78: { // 0x478c78: 7413 JZ 0x00478c8d
    if(integer::condition("JZ",flags)) goto L00478c8d;
  }
  L00478c7a: { // 0x478c7a: 8b86ec040000 MOV EAX,dword ptr [ESI + 0x4ec]
    s.ax = m.r32((s.si+0x000004ecu));
  }
  L00478c80: { // 0x478c80: 83f80c CMP EAX,0xc
    (void)integer::sub(s.ax,0x0000000cu,32,flags);
  }
  L00478c83: { // 0x478c83: 7408 JZ 0x00478c8d
    if(integer::condition("JZ",flags)) goto L00478c8d;
  }
  L00478c85: { // 0x478c85: 83f808 CMP EAX,0x8
    (void)integer::sub(s.ax,0x00000008u,32,flags);
  }
  L00478c88: { // 0x478c88: 7403 JZ 0x00478c8d
    if(integer::condition("JZ",flags)) goto L00478c8d;
  }
  L00478c8a: { // 0x478c8a: 896f4c MOV dword ptr [EDI + 0x4c],EBP
    m.w32((s.di+0x0000004cu), s.bp);
  }
  L00478c8d: { // 0x478c8d: 8b7630 MOV ESI,dword ptr [ESI + 0x30]
    s.si = m.r32((s.si+0x00000030u));
  }
  L00478c90: { // 0x478c90: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00478c92: { // 0x478c92: 75a8 JNZ 0x00478c3c
    if(integer::condition("JNZ",flags)) goto L00478c3c;
  }
  L00478c94: { // 0x478c94: c7474c00000000 MOV dword ptr [EDI + 0x4c],0x0
    m.w32((s.di+0x0000004cu), 0x00000000u);
  }
  L00478c9b: { // 0x478c9b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00478c9c: { // 0x478c9c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00478c9d: { // 0x478c9d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00478c9e: { // 0x478c9e: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00478c9f: { // 0x478c9f: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L00478ca5: { // 0x478ca5: 8b8138080000 MOV EAX,dword ptr [ECX + 0x838]
    s.ax = m.r32((s.cx+0x00000838u));
  }
  L00478cab: { // 0x478cab: b907000000 MOV ECX,0x7
    s.cx = 0x00000007u;
  }
  L00478cb0: { // 0x478cb0: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L00478cb3: { // 0x478cb3: 7417 JZ 0x00478ccc
    if(integer::condition("JZ",flags)) goto L00478ccc;
  }
  L00478cb5: { // 0x478cb5: 8b96b0000000 MOV EDX,dword ptr [ESI + 0xb0]
    s.dx = m.r32((s.si+0x000000b0u));
  }
  L00478cbb: { // 0x478cbb: 398a78020000 CMP dword ptr [EDX + 0x278],ECX
    (void)integer::sub(m.r32((s.dx+0x00000278u)),s.cx,32,flags);
  }
  L00478cc1: { // 0x478cc1: 751b JNZ 0x00478cde
    if(integer::condition("JNZ",flags)) goto L00478cde;
  }
  L00478cc3: { // 0x478cc3: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L00478cc6: { // 0x478cc6: 0f85c8feffff JNZ 0x00478b94
    if(integer::condition("JNZ",flags)) goto L00478b94;
  }
  L00478ccc: { // 0x478ccc: 8b86b0000000 MOV EAX,dword ptr [ESI + 0xb0]
    s.ax = m.r32((s.si+0x000000b0u));
  }
  L00478cd2: { // 0x478cd2: 39887c020000 CMP dword ptr [EAX + 0x27c],ECX
    (void)integer::sub(m.r32((s.ax+0x0000027cu)),s.cx,32,flags);
  }
  L00478cd8: { // 0x478cd8: 0f84b6feffff JZ 0x00478b94
    if(integer::condition("JZ",flags)) goto L00478b94;
  }
  L00478cde: { // 0x478cde: c7474c05000000 MOV dword ptr [EDI + 0x4c],0x5
    m.w32((s.di+0x0000004cu), 0x00000005u);
  }
  L00478ce5: { // 0x478ce5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00478ce6: { // 0x478ce6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00478ce7: { // 0x478ce7: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00478ce8: { // 0x478ce8: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
