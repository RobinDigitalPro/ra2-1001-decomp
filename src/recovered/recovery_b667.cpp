#include "recovered/recovery_b667_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b667 {
namespace {
void f_0022e4b0(Memory&,State&,Frame&,const Operations&);
void f_0022e3c0(Memory&,State&,Frame&,const Operations&);
void f_00191570(Memory&,State&,Frame&,const Operations&);
void f_00053890(Memory&,State&,Frame&,const Operations&);
void f_00157450(Memory&,State&,Frame&,const Operations&);
void f_00023ec0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_0022e4b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0062e4b0: { // 0x62e4b0: 8b91d0000000 MOV EDX,dword ptr [ECX + 0xd0]
    s.dx = m.r32((s.cx+0x000000d0u));
  }
  L0062e4b6: { // 0x62e4b6: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0062e4b8: { // 0x62e4b8: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0062e4ba: { // 0x62e4ba: 7e13 JLE 0x0062e4cf
    if(integer::condition("JLE",flags)) goto L0062e4cf;
  }
  L0062e4bc: { // 0x62e4bc: 8b89cc000000 MOV ECX,dword ptr [ECX + 0xcc]
    s.cx = m.r32((s.cx+0x000000ccu));
  }
  L0062e4c2: { // 0x62e4c2: 833900 CMP dword ptr [ECX],0x0
    (void)integer::sub(m.r32((s.cx)),0x00000000u,32,flags);
  }
  L0062e4c5: { // 0x62e4c5: 750b JNZ 0x0062e4d2
    if(integer::condition("JNZ",flags)) goto L0062e4d2;
  }
  L0062e4c7: { // 0x62e4c7: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0062e4c8: { // 0x62e4c8: 83c104 ADD ECX,0x4
    s.cx = integer::add(s.cx,0x00000004u,32,flags);
  }
  L0062e4cb: { // 0x62e4cb: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0062e4cd: { // 0x62e4cd: 7cf3 JL 0x0062e4c2
    if(integer::condition("JL",flags)) goto L0062e4c2;
  }
  L0062e4cf: { // 0x62e4cf: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0062e4d1: { // 0x62e4d1: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0062e4d2: { // 0x62e4d2: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0062e4d4: { // 0x62e4d4: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0022e3c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0062e3c0: { // 0x62e3c0: 8b81cc000000 MOV EAX,dword ptr [ECX + 0xcc]
    s.ax = m.r32((s.cx+0x000000ccu));
  }
  L0062e3c6: { // 0x62e3c6: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L0062e3ca: { // 0x62e3ca: 8b0488 MOV EAX,dword ptr [EAX + ECX*0x4]
    s.ax = m.r32((s.ax+(s.cx * 0x00000004u)));
  }
  L0062e3cd: { // 0x62e3cd: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00191570(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00591570: { // 0x591570: 8b8198000000 MOV EAX, dword ptr [ECX + 0x98]
    s.ax = m.r32((s.cx+0x00000098u));
  }
  L00591576: { // 0x591576: 83f8ff CMP EAX, -1
    (void)integer::sub(s.ax,4294967295u,32,flags);
  }
  L00591579: { // 0x591579: 7506 JNZ 0x591581
    if(integer::condition("JNZ",flags)) goto L00591581;
  }
  L0059157b: { // 0x59157b: 8b81a0000000 MOV EAX, dword ptr [ECX + 0xa0]
    s.ax = m.r32((s.cx+0x000000a0u));
  }
  L00591581: { // 0x591581: c3 RET
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

void f_00157450(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00557450: { // 0x557450: 8a442408 MOV AL,byte ptr [ESP + 0x8]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000008u)));
  }
  L00557454: { // 0x557454: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00557455: { // 0x557455: 8b5c2408 MOV EBX,dword ptr [ESP + 0x8]
    s.bx = m.r32((f.sp+0x00000008u));
  }
  L00557459: { // 0x557459: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0055745a: { // 0x55745a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0055745b: { // 0x55745b: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0055745d: { // 0x55745d: 0fbf5302 MOVSX EDX,word ptr [EBX + 0x2]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.bx+0x00000002u)),16));
  }
  L00557461: { // 0x557461: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00557462: { // 0x557462: 0fbf3b MOVSX EDI,word ptr [EBX]
    s.di = std::uint32_t(integer::sign_extend(m.r16((s.bx)),16));
  }
  L00557465: { // 0x557465: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00557467: { // 0x557467: 7454 JZ 0x005574bd
    if(integer::condition("JZ",flags)) goto L005574bd;
  }
  L00557469: { // 0x557469: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L0055746b: { // 0x55746b: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L0055746e: { // 0x55746e: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L00557470: { // 0x557470: 7814 JS 0x00557486
    if(integer::condition("JS",flags)) goto L00557486;
  }
  L00557472: { // 0x557472: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00557477: { // 0x557477: 7d0d JGE 0x00557486
    if(integer::condition("JGE",flags)) goto L00557486;
  }
  L00557479: { // 0x557479: 8b3558a98100 MOV ESI,dword ptr [0x0081a958]
    s.si = m.r32((0x0081a958u));
  }
  L0055747f: { // 0x55747f: 8b0486 MOV EAX,dword ptr [ESI + EAX*0x4]
    s.ax = m.r32((s.si+(s.ax * 0x00000004u)));
  }
  L00557482: { // 0x557482: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00557484: { // 0x557484: 750c JNZ 0x00557492
    if(integer::condition("JNZ",flags)) goto L00557492;
  }
  L00557486: { // 0x557486: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L00557488: { // 0x557488: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L0055748d: { // 0x55748d: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L00557492: { // 0x557492: 8a981c010000 MOV BL,byte ptr [EAX + 0x11c]
    s.bx = with_al(s.bx, m.r8((s.ax+0x0000011cu)));
  }
  L00557498: { // 0x557498: 0fbeb01b010000 MOVSX ESI,byte ptr [EAX + 0x11b]
    s.si = std::uint32_t(integer::sign_extend(m.r8((s.ax+0x0000011bu)),8));
  }
  L0055749f: { // 0x55749f: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L005574a1: { // 0x5574a1: 741a JZ 0x005574bd
    if(integer::condition("JZ",flags)) goto L005574bd;
  }
  L005574a3: { // 0x5574a3: 8b81fc000000 MOV EAX,dword ptr [ECX + 0xfc]
    s.ax = m.r32((s.cx+0x000000fcu));
  }
  L005574a9: { // 0x5574a9: 8b99f0000000 MOV EBX,dword ptr [ECX + 0xf0]
    s.bx = m.r32((s.cx+0x000000f0u));
  }
  L005574af: { // 0x5574af: 8d444304 LEA EAX,[EBX + EAX*0x2 + 0x4]
    s.ax = (s.bx+(s.ax * 0x00000002u)+0x00000004u);
  }
  L005574b3: { // 0x5574b3: 8d1c3a LEA EBX,[EDX + EDI*0x1]
    s.bx = (s.dx+(s.di * 0x00000001u));
  }
  L005574b6: { // 0x5574b6: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L005574b8: { // 0x5574b8: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L005574ba: { // 0x5574ba: 7d01 JGE 0x005574bd
    if(integer::condition("JGE",flags)) goto L005574bd;
  }
  L005574bc: { // 0x5574bc: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L005574bd: { // 0x5574bd: 8b99fc000000 MOV EBX,dword ptr [ECX + 0xfc]
    s.bx = m.r32((s.cx+0x000000fcu));
  }
  L005574c3: { // 0x5574c3: 8b81f0000000 MOV EAX,dword ptr [ECX + 0xf0]
    s.ax = m.r32((s.cx+0x000000f0u));
  }
  L005574c9: { // 0x5574c9: 8d2c3a LEA EBP,[EDX + EDI*0x1]
    s.bp = (s.dx+(s.di * 0x00000001u));
  }
  L005574cc: { // 0x5574cc: 8d1c58 LEA EBX,[EAX + EBX*0x2]
    s.bx = (s.ax+(s.bx * 0x00000002u));
  }
  L005574cf: { // 0x5574cf: 03de ADD EBX,ESI
    s.bx = integer::add(s.bx,s.si,32,flags);
  }
  L005574d1: { // 0x5574d1: 3beb CMP EBP,EBX
    (void)integer::sub(s.bp,s.bx,32,flags);
  }
  L005574d3: { // 0x5574d3: 7e49 JLE 0x0055751e
    if(integer::condition("JLE",flags)) goto L0055751e;
  }
  L005574d5: { // 0x5574d5: 8b9904010000 MOV EBX,dword ptr [ECX + 0x104]
    s.bx = m.r32((s.cx+0x00000104u));
  }
  L005574db: { // 0x5574db: 8ba9fc000000 MOV EBP,dword ptr [ECX + 0xfc]
    s.bp = m.r32((s.cx+0x000000fcu));
  }
  L005574e1: { // 0x5574e1: 03dd ADD EBX,EBP
    s.bx = integer::add(s.bx,s.bp,32,flags);
  }
  L005574e3: { // 0x5574e3: 8d5c5802 LEA EBX,[EAX + EBX*0x2 + 0x2]
    s.bx = (s.ax+(s.bx * 0x00000002u)+0x00000002u);
  }
  L005574e7: { // 0x5574e7: 03de ADD EBX,ESI
    s.bx = integer::add(s.bx,s.si,32,flags);
  }
  L005574e9: { // 0x5574e9: 8d343a LEA ESI,[EDX + EDI*0x1]
    s.si = (s.dx+(s.di * 0x00000001u));
  }
  L005574ec: { // 0x5574ec: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L005574ee: { // 0x5574ee: 7f2e JG 0x0055751e
    if(integer::condition("JG",flags)) goto L0055751e;
  }
  L005574f0: { // 0x5574f0: 8bb1f8000000 MOV ESI,dword ptr [ECX + 0xf8]
    s.si = m.r32((s.cx+0x000000f8u));
  }
  L005574f6: { // 0x5574f6: 8b8900010000 MOV ECX,dword ptr [ECX + 0x100]
    s.cx = m.r32((s.cx+0x00000100u));
  }
  L005574fc: { // 0x5574fc: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L005574fe: { // 0x5574fe: 8bdf MOV EBX,EDI
    s.bx = s.di;
  }
  L00557500: { // 0x557500: d1e1 SHL ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::left);
  }
  L00557502: { // 0x557502: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00557504: { // 0x557504: 2bda SUB EBX,EDX
    s.bx = integer::sub(s.bx,s.dx,32,flags);
  }
  L00557506: { // 0x557506: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L00557508: { // 0x557508: 7d14 JGE 0x0055751e
    if(integer::condition("JGE",flags)) goto L0055751e;
  }
  L0055750a: { // 0x55750a: 8d0c36 LEA ECX,[ESI + ESI*0x1]
    s.cx = (s.si+(s.si * 0x00000001u));
  }
  L0055750d: { // 0x55750d: 2bd7 SUB EDX,EDI
    s.dx = integer::sub(s.dx,s.di,32,flags);
  }
  L0055750f: { // 0x55750f: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00557511: { // 0x557511: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L00557513: { // 0x557513: 7d09 JGE 0x0055751e
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
  L00557518: { // 0x557518: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0055751a: { // 0x55751a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0055751b: { // 0x55751b: c20800 RET 0x8
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
  L00557521: { // 0x557521: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00557523: { // 0x557523: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00557524: { // 0x557524: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00023ec0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00423ec0: { // 0x423ec0: b804000000 MOV EAX, 4
    s.ax = 4u;
  }
  L00423ec5: { // 0x423ec5: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 6481072u:f_0022e4b0(m,s,child,{});break;
case 6480832u:f_0022e3c0(m,s,child,{});break;
case 5838192u:f_00191570(m,s,child,{});break;
case 4536464u:f_00053890(m,s,child,{});break;
case 5600336u:f_00157450(m,s,child,{});break;
case 4341440u:f_00023ec0(m,s,child,{});break;
default:throw std::domain_error("recovery667 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0041adf0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0041adf0: { // 0x41adf0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0041adf1: { // 0x41adf1: 8b5c2408 MOV EBX,dword ptr [ESP + 0x8]
    s.bx = m.r32((f.sp+0x00000008u));
  }
  L0041adf5: { // 0x41adf5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0041adf6: { // 0x41adf6: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0041adf7: { // 0x41adf7: 8b4304 MOV EAX,dword ptr [EBX + 0x4]
    s.ax = m.r32((s.bx+0x00000004u));
  }
  L0041adfa: { // 0x41adfa: 8a88940b0000 MOV CL,byte ptr [EAX + 0xb94]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000b94u)));
  }
  L0041ae00: { // 0x41ae00: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0041ae02: { // 0x41ae02: 745f JZ 0x0041ae63
    if(integer::condition("JZ",flags)) goto L0041ae63;
  }
  L0041ae04: { // 0x41ae04: 8b8354fbffff MOV EAX,dword ptr [EBX + 0xfffffb54]
    s.ax = m.r32((s.bx+0xfffffb54u));
  }
  L0041ae0a: { // 0x41ae0a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0041ae0c: { // 0x41ae0c: 7555 JNZ 0x0041ae63
    if(integer::condition("JNZ",flags)) goto L0041ae63;
  }
  L0041ae0e: { // 0x41ae0e: 8db358faffff LEA ESI,[EBX + 0xfffffa58]
    s.si = (s.bx+0xfffffa58u);
  }
  L0041ae14: { // 0x41ae14: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0041ae16: { // 0x41ae16: e895362100 CALL 0x0062e4b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062e4b0u,4304411u); flags=s.arithmetic_flags;
  }
  L0041ae1b: { // 0x41ae1b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0041ae1d: { // 0x41ae1d: 7444 JZ 0x0041ae63
    if(integer::condition("JZ",flags)) goto L0041ae63;
  }
  L0041ae1f: { // 0x41ae1f: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0041ae21: { // 0x41ae21: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0041ae23: { // 0x41ae23: e898352100 CALL 0x0062e3c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062e3c0u,4304424u); flags=s.arithmetic_flags;
  }
  L0041ae28: { // 0x41ae28: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0041ae2a: { // 0x41ae2a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0041ae2c: { // 0x41ae2c: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0041ae2e: { // 0x41ae2e: ff926c010000 CALL dword ptr [EDX + 0x16c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000016cu)),4304436u); flags=s.arithmetic_flags;
  }
  L0041ae34: { // 0x41ae34: 83f807 CMP EAX,0x7
    (void)integer::sub(s.ax,0x00000007u,32,flags);
  }
  L0041ae37: { // 0x41ae37: 752a JNZ 0x0041ae63
    if(integer::condition("JNZ",flags)) goto L0041ae63;
  }
  L0041ae39: { // 0x41ae39: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0041ae3b: { // 0x41ae3b: 7426 JZ 0x0041ae63
    if(integer::condition("JZ",flags)) goto L0041ae63;
  }
  L0041ae3d: { // 0x41ae3d: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L0041ae3f: { // 0x41ae3f: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0041ae41: { // 0x41ae41: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),4304452u); flags=s.arithmetic_flags;
  }
  L0041ae44: { // 0x41ae44: 83f806 CMP EAX,0x6
    (void)integer::sub(s.ax,0x00000006u,32,flags);
  }
  L0041ae47: { // 0x41ae47: 751a JNZ 0x0041ae63
    if(integer::condition("JNZ",flags)) goto L0041ae63;
  }
  L0041ae49: { // 0x41ae49: 8bbf18040000 MOV EDI,dword ptr [EDI + 0x418]
    s.di = m.r32((s.di+0x00000418u));
  }
  L0041ae4f: { // 0x41ae4f: 8a8749130000 MOV AL,byte ptr [EDI + 0x1349]
    s.ax = with_al(s.ax, m.r8((s.di+0x00001349u)));
  }
  L0041ae55: { // 0x41ae55: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0041ae57: { // 0x41ae57: 7548 JNZ 0x0041aea1
    if(integer::condition("JNZ",flags)) goto L0041aea1;
  }
  L0041ae59: { // 0x41ae59: 8a8765130000 MOV AL,byte ptr [EDI + 0x1365]
    s.ax = with_al(s.ax, m.r8((s.di+0x00001365u)));
  }
  L0041ae5f: { // 0x41ae5f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0041ae61: { // 0x41ae61: 753e JNZ 0x0041aea1
    if(integer::condition("JNZ",flags)) goto L0041aea1;
  }
  L0041ae63: { // 0x41ae63: 8d8b58faffff LEA ECX,[EBX + 0xfffffa58]
    s.cx = (s.bx+0xfffffa58u);
  }
  L0041ae69: { // 0x41ae69: e842362100 CALL 0x0062e4b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062e4b0u,4304494u); flags=s.arithmetic_flags;
  }
  L0041ae6e: { // 0x41ae6e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0041ae70: { // 0x41ae70: 740d JZ 0x0041ae7f
    if(integer::condition("JZ",flags)) goto L0041ae7f;
  }
  L0041ae72: { // 0x41ae72: 8b4b04 MOV ECX,dword ptr [EBX + 0x4]
    s.cx = m.r32((s.bx+0x00000004u));
  }
  L0041ae75: { // 0x41ae75: 8a81940b0000 MOV AL,byte ptr [ECX + 0xb94]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000b94u)));
  }
  L0041ae7b: { // 0x41ae7b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0041ae7d: { // 0x41ae7d: 7517 JNZ 0x0041ae96
    if(integer::condition("JNZ",flags)) goto L0041ae96;
  }
  L0041ae7f: { // 0x41ae7f: 8b8354fbffff MOV EAX,dword ptr [EBX + 0xfffffb54]
    s.ax = m.r32((s.bx+0xfffffb54u));
  }
  L0041ae85: { // 0x41ae85: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0041ae87: { // 0x41ae87: 7418 JZ 0x0041aea1
    if(integer::condition("JZ",flags)) goto L0041aea1;
  }
  L0041ae89: { // 0x41ae89: 8b5304 MOV EDX,dword ptr [EBX + 0x4]
    s.dx = m.r32((s.bx+0x00000004u));
  }
  L0041ae8c: { // 0x41ae8c: 8a82940b0000 MOV AL,byte ptr [EDX + 0xb94]
    s.ax = with_al(s.ax, m.r8((s.dx+0x00000b94u)));
  }
  L0041ae92: { // 0x41ae92: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0041ae94: { // 0x41ae94: 740b JZ 0x0041aea1
    if(integer::condition("JZ",flags)) goto L0041aea1;
  }
  L0041ae96: { // 0x41ae96: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0041ae97: { // 0x41ae97: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0041ae98: { // 0x41ae98: b864000000 MOV EAX,0x64
    s.ax = 0x00000064u;
  }
  L0041ae9d: { // 0x41ae9d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0041ae9e: { // 0x41ae9e: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0041aea1: { // 0x41aea1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0041aea2: { // 0x41aea2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0041aea3: { // 0x41aea3: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0041aea5: { // 0x41aea5: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0041aea6: { // 0x41aea6: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_004787a0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004787a0: { // 0x4787a0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004787a1: { // 0x4787a1: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004787a2: { // 0x4787a2: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L004787a4: { // 0x4787a4: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L004787a6: { // 0x4787a6: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L004787ab: { // 0x4787ab: 8d4724 LEA EAX,[EDI + 0x24]
    s.ax = (s.di+0x00000024u);
  }
  L004787ae: { // 0x4787ae: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004787af: { // 0x4787af: e89cec0d00 CALL 0x00557450
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557450u,4687796u); flags=s.arithmetic_flags;
  }
  L004787b4: { // 0x4787b4: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004787b6: { // 0x4787b6: 0f84ed000000 JZ 0x004788a9
    if(integer::condition("JZ",flags)) goto L004788a9;
  }
  L004787bc: { // 0x4787bc: 8b8740010000 MOV EAX,dword ptr [EDI + 0x140]
    s.ax = m.r32((s.di+0x00000140u));
  }
  L004787c2: { // 0x4787c2: f6c405 TEST AH,0x5
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000005u),8,flags);
  }
  L004787c5: { // 0x4787c5: 0f85de000000 JNZ 0x004788a9
    if(integer::condition("JNZ",flags)) goto L004788a9;
  }
  L004787cb: { // 0x4787cb: a0a885a200 MOV AL,[0x00a285a8]
    s.ax = with_al(s.ax, m.r8((0x00a285a8u)));
  }
  L004787d0: { // 0x4787d0: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004787d2: { // 0x4787d2: 0f8484000000 JZ 0x0047885c
    if(integer::condition("JZ",flags)) goto L0047885c;
  }
  L004787d8: { // 0x4787d8: 8bb7e4000000 MOV ESI,dword ptr [EDI + 0xe4]
    s.si = m.r32((s.di+0x000000e4u));
  }
  L004787de: { // 0x4787de: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L004787e0: { // 0x4787e0: 743e JZ 0x00478820
    if(integer::condition("JZ",flags)) goto L00478820;
  }
  L004787e2: { // 0x4787e2: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004787e4: { // 0x4787e4: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004787e6: { // 0x4787e6: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),4687849u); flags=s.arithmetic_flags;
  }
  L004787e9: { // 0x4787e9: 83f806 CMP EAX,0x6
    (void)integer::sub(s.ax,0x00000006u,32,flags);
  }
  L004787ec: { // 0x4787ec: 7409 JZ 0x004787f7
    if(integer::condition("JZ",flags)) goto L004787f7;
  }
  L004787ee: { // 0x4787ee: 8b7630 MOV ESI,dword ptr [ESI + 0x30]
    s.si = m.r32((s.si+0x00000030u));
  }
  L004787f1: { // 0x4787f1: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L004787f3: { // 0x4787f3: 75ed JNZ 0x004787e2
    if(integer::condition("JNZ",flags)) goto L004787e2;
  }
  L004787f5: { // 0x4787f5: eb29 JMP 0x00478820
    goto L00478820;
  }
  L004787f7: { // 0x4787f7: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L004787f9: { // 0x4787f9: 7425 JZ 0x00478820
    if(integer::condition("JZ",flags)) goto L00478820;
  }
  L004787fb: { // 0x4787fb: 8b466c MOV EAX,dword ptr [ESI + 0x6c]
    s.ax = m.r32((s.si+0x0000006cu));
  }
  L004787fe: { // 0x4787fe: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00478800: { // 0x478800: 7e1e JLE 0x00478820
    if(integer::condition("JLE",flags)) goto L00478820;
  }
  L00478802: { // 0x478802: 8bb618040000 MOV ESI,dword ptr [ESI + 0x418]
    s.si = m.r32((s.si+0x00000418u));
  }
  L00478808: { // 0x478808: 8a86a60a0000 MOV AL,byte ptr [ESI + 0xaa6]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000aa6u)));
  }
  L0047880e: { // 0x47880e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00478810: { // 0x478810: 750e JNZ 0x00478820
    if(integer::condition("JNZ",flags)) goto L00478820;
  }
  L00478812: { // 0x478812: 8a8685130000 MOV AL,byte ptr [ESI + 0x1385]
    s.ax = with_al(s.ax, m.r8((s.si+0x00001385u)));
  }
  L00478818: { // 0x478818: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0047881a: { // 0x47881a: 0f8489000000 JZ 0x004788a9
    if(integer::condition("JZ",flags)) goto L004788a9;
  }
  L00478820: { // 0x478820: a0a885a200 MOV AL,[0x00a285a8]
    s.ax = with_al(s.ax, m.r8((0x00a285a8u)));
  }
  L00478825: { // 0x478825: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00478827: { // 0x478827: 7433 JZ 0x0047885c
    if(integer::condition("JZ",flags)) goto L0047885c;
  }
  L00478829: { // 0x478829: 8bb7e4000000 MOV ESI,dword ptr [EDI + 0xe4]
    s.si = m.r32((s.di+0x000000e4u));
  }
  L0047882f: { // 0x47882f: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00478831: { // 0x478831: 7429 JZ 0x0047885c
    if(integer::condition("JZ",flags)) goto L0047885c;
  }
  L00478833: { // 0x478833: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00478835: { // 0x478835: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00478837: { // 0x478837: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),4687930u); flags=s.arithmetic_flags;
  }
  L0047883a: { // 0x47883a: 83f824 CMP EAX,0x24
    (void)integer::sub(s.ax,0x00000024u,32,flags);
  }
  L0047883d: { // 0x47883d: 7409 JZ 0x00478848
    if(integer::condition("JZ",flags)) goto L00478848;
  }
  L0047883f: { // 0x47883f: 8b7630 MOV ESI,dword ptr [ESI + 0x30]
    s.si = m.r32((s.si+0x00000030u));
  }
  L00478842: { // 0x478842: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00478844: { // 0x478844: 75ed JNZ 0x00478833
    if(integer::condition("JNZ",flags)) goto L00478833;
  }
  L00478846: { // 0x478846: eb14 JMP 0x0047885c
    goto L0047885c;
  }
  L00478848: { // 0x478848: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0047884a: { // 0x47884a: 7410 JZ 0x0047885c
    if(integer::condition("JZ",flags)) goto L0047885c;
  }
  L0047884c: { // 0x47884c: 8b8eb0000000 MOV ECX,dword ptr [ESI + 0xb0]
    s.cx = m.r32((s.si+0x000000b0u));
  }
  L00478852: { // 0x478852: 8a8181020000 MOV AL,byte ptr [ECX + 0x281]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000281u)));
  }
  L00478858: { // 0x478858: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0047885a: { // 0x47885a: 754d JNZ 0x004788a9
    if(integer::condition("JNZ",flags)) goto L004788a9;
  }
  L0047885c: { // 0x47885c: 8b87ec000000 MOV EAX,dword ptr [EDI + 0xec]
    s.ax = m.r32((s.di+0x000000ecu));
  }
  L00478862: { // 0x478862: 8d14c0 LEA EDX,[EAX + EAX*0x8]
    s.dx = (s.ax+(s.ax * 0x00000008u));
  }
  L00478865: { // 0x478865: 8a0495f0918300 MOV AL,byte ptr [EDX*0x4 + 0x8391f0]
    s.ax = with_al(s.ax, m.r8(((s.dx * 0x00000004u)+0x008391f0u)));
  }
  L0047886c: { // 0x47886c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0047886e: { // 0x47886e: 7439 JZ 0x004788a9
    if(integer::condition("JZ",flags)) goto L004788a9;
  }
  L00478870: { // 0x478870: 837f44ff CMP dword ptr [EDI + 0x44],-0x1
    (void)integer::sub(m.r32((s.di+0x00000044u)),0xffffffffu,32,flags);
  }
  L00478874: { // 0x478874: 7533 JNZ 0x004788a9
    if(integer::condition("JNZ",flags)) goto L004788a9;
  }
  L00478876: { // 0x478876: 8a871c010000 MOV AL,byte ptr [EDI + 0x11c]
    s.ax = with_al(s.ax, m.r8((s.di+0x0000011cu)));
  }
  L0047887c: { // 0x47887c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0047887e: { // 0x47887e: 7529 JNZ 0x004788a9
    if(integer::condition("JNZ",flags)) goto L004788a9;
  }
  L00478880: { // 0x478880: 8b4738 MOV EAX,dword ptr [EDI + 0x38]
    s.ax = m.r32((s.di+0x00000038u));
  }
  L00478883: { // 0x478883: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00478885: { // 0x478885: 7c1b JL 0x004788a2
    if(integer::condition("JL",flags)) goto L004788a2;
  }
  L00478887: { // 0x478887: 3b052089a200 CMP EAX,dword ptr [0x00a28920]
    (void)integer::sub(s.ax,m.r32((0x00a28920u)),32,flags);
  }
  L0047888d: { // 0x47888d: 7d13 JGE 0x004788a2
    if(integer::condition("JGE",flags)) goto L004788a2;
  }
  L0047888f: { // 0x47888f: 8b0d1489a200 MOV ECX,dword ptr [0x00a28914]
    s.cx = m.r32((0x00a28914u));
  }
  L00478895: { // 0x478895: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L00478898: { // 0x478898: 8a82d6020000 MOV AL,byte ptr [EDX + 0x2d6]
    s.ax = with_al(s.ax, m.r8((s.dx+0x000002d6u)));
  }
  L0047889e: { // 0x47889e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004788a0: { // 0x4788a0: 7407 JZ 0x004788a9
    if(integer::condition("JZ",flags)) goto L004788a9;
  }
  L004788a2: { // 0x4788a2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004788a3: { // 0x4788a3: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L004788a5: { // 0x4788a5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004788a6: { // 0x4788a6: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004788a9: { // 0x4788a9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004788aa: { // 0x4788aa: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004788ac: { // 0x4788ac: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004788ad: { // 0x4788ad: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
