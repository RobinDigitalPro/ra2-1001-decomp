#include "recovered/recovery_b806_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b806 {
namespace {
void f_00050050(Memory&,State&,Frame&,const Operations&);
void f_00043e10(Memory&,State&,Frame&,const Operations&);
void f_000585b0(Memory&,State&,Frame&,const Operations&);
void f_000585c0(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_000713b0(Memory&,State&,Frame&,const Operations&);
void f_000b8850(Memory&,State&,Frame&,const Operations&);
void f_00053890(Memory&,State&,Frame&,const Operations&);
void f_002bca00(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_00050050(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00450050: { // 0x450050: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00450051: { // 0x450051: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00450053: { // 0x450053: 8a8630050000 MOV AL,byte ptr [ESI + 0x530]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000530u)));
  }
  L00450059: { // 0x450059: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0045005b: { // 0x45005b: 750d JNZ 0x0045006a
    if(integer::condition("JNZ",flags)) goto L0045006a;
  }
  L0045005d: { // 0x45005d: 83be4c05000002 CMP dword ptr [ESI + 0x54c],0x2
    (void)integer::sub(m.r32((s.si+0x0000054cu)),0x00000002u,32,flags);
  }
  L00450064: { // 0x450064: 7d04 JGE 0x0045006a
    if(integer::condition("JGE",flags)) goto L0045006a;
  }
  L00450066: { // 0x450066: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00450068: { // 0x450068: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00450069: { // 0x450069: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0045006a: { // 0x45006a: 8b86fc030000 MOV EAX,dword ptr [ESI + 0x3fc]
    s.ax = m.r32((s.si+0x000003fcu));
  }
  L00450070: { // 0x450070: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00450072: { // 0x450072: 7e04 JLE 0x00450078
    if(integer::condition("JLE",flags)) goto L00450078;
  }
  L00450074: { // 0x450074: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00450076: { // 0x450076: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00450077: { // 0x450077: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00450078: { // 0x450078: 8b466c MOV EAX,dword ptr [ESI + 0x6c]
    s.ax = m.r32((s.si+0x0000006cu));
  }
  L0045007b: { // 0x45007b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0045007d: { // 0x45007d: 7504 JNZ 0x00450083
    if(integer::condition("JNZ",flags)) goto L00450083;
  }
  L0045007f: { // 0x45007f: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00450081: { // 0x450081: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00450082: { // 0x450082: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00450083: { // 0x450083: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L00450089: { // 0x450089: 8a8817120000 MOV CL,byte ptr [EAX + 0x1217]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001217u)));
  }
  L0045008f: { // 0x45008f: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00450091: { // 0x450091: 7439 JZ 0x004500cc
    if(integer::condition("JZ",flags)) goto L004500cc;
  }
  L00450093: { // 0x450093: 8b886c0c0000 MOV ECX,dword ptr [EAX + 0xc6c]
    s.cx = m.r32((s.ax+0x00000c6cu));
  }
  L00450099: { // 0x450099: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0045009b: { // 0x45009b: 7e2f JLE 0x004500cc
    if(integer::condition("JLE",flags)) goto L004500cc;
  }
  L0045009d: { // 0x45009d: 8a88fe110000 MOV CL,byte ptr [EAX + 0x11fe]
    s.cx = with_al(s.cx, m.r8((s.ax+0x000011feu)));
  }
  L004500a3: { // 0x4500a3: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004500a5: { // 0x4500a5: 7425 JZ 0x004500cc
    if(integer::condition("JZ",flags)) goto L004500cc;
  }
  L004500a7: { // 0x4500a7: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L004500ad: { // 0x4500ad: e8be770900 CALL 0x004e7870
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e7870u,4522162u); flags=s.arithmetic_flags;
  }
  L004500b2: { // 0x4500b2: dc1d08577800 FCOMP double ptr [0x00785708]
    const auto address=(0x00785708u);
    s.fp.compare_pop64(read64(m,address));
  }
  L004500b8: { // 0x4500b8: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004500ba: { // 0x4500ba: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L004500bd: { // 0x4500bd: 740d JZ 0x004500cc
    if(integer::condition("JZ",flags)) goto L004500cc;
  }
  L004500bf: { // 0x4500bf: 83be4c05000002 CMP dword ptr [ESI + 0x54c],0x2
    (void)integer::sub(m.r32((s.si+0x0000054cu)),0x00000002u,32,flags);
  }
  L004500c6: { // 0x4500c6: 7d04 JGE 0x004500cc
    if(integer::condition("JGE",flags)) goto L004500cc;
  }
  L004500c8: { // 0x4500c8: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004500ca: { // 0x4500ca: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004500cb: { // 0x4500cb: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004500cc: { // 0x4500cc: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L004500d2: { // 0x4500d2: 8a8806120000 MOV CL,byte ptr [EAX + 0x1206]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001206u)));
  }
  L004500d8: { // 0x4500d8: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004500da: { // 0x4500da: 740e JZ 0x004500ea
    if(integer::condition("JZ",flags)) goto L004500ea;
  }
  L004500dc: { // 0x4500dc: 8a869c050000 MOV AL,byte ptr [ESI + 0x59c]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000059cu)));
  }
  L004500e2: { // 0x4500e2: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004500e4: { // 0x4500e4: 7504 JNZ 0x004500ea
    if(integer::condition("JNZ",flags)) goto L004500ea;
  }
  L004500e6: { // 0x4500e6: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004500e8: { // 0x4500e8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004500e9: { // 0x4500e9: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004500ea: { // 0x4500ea: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L004500ec: { // 0x4500ec: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004500ed: { // 0x4500ed: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00043e10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00443e10: { // 0x443e10: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00443e11: { // 0x443e11: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00443e12: { // 0x443e12: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L00443e14: { // 0x443e14: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00443e16: { // 0x443e16: 8b8f18040000 MOV ECX,dword ptr [EDI + 0x418]
    s.cx = m.r32((s.di+0x00000418u));
  }
  L00443e1c: { // 0x443e1c: e89f470100 CALL 0x004585c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004585c0u,4472353u); flags=s.arithmetic_flags;
  }
  L00443e21: { // 0x443e21: 8b8f18040000 MOV ECX,dword ptr [EDI + 0x418]
    s.cx = m.r32((s.di+0x00000418u));
  }
  L00443e27: { // 0x443e27: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00443e29: { // 0x443e29: c1e607 SHL ESI,0x7
    s.si = integer::shift(s.si,0x00000007u,32,flags,integer::Shift::left);
  }
  L00443e2c: { // 0x443e2c: 81ee80000000 SUB ESI,0x80
    s.si = integer::sub(s.si,0x00000080u,32,flags);
  }
  L00443e32: { // 0x443e32: e879470100 CALL 0x004585b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004585b0u,4472375u); flags=s.arithmetic_flags;
  }
  L00443e37: { // 0x443e37: 81c788000000 ADD EDI,0x88
    s.di = integer::add(s.di,0x00000088u,32,flags);
  }
  L00443e3d: { // 0x443e3d: c1e007 SHL EAX,0x7
    s.ax = integer::shift(s.ax,0x00000007u,32,flags,integer::Shift::left);
  }
  L00443e40: { // 0x443e40: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  L00443e42: { // 0x443e42: 2d80000000 SUB EAX,0x80
    s.ax = integer::sub(s.ax,0x00000080u,32,flags);
  }
  L00443e47: { // 0x443e47: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00443e49: { // 0x443e49: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L00443e4d: { // 0x443e4d: 8b5704 MOV EDX,dword ptr [EDI + 0x4]
    s.dx = m.r32((s.di+0x00000004u));
  }
  L00443e50: { // 0x443e50: 03d6 ADD EDX,ESI
    s.dx = integer::add(s.dx,s.si,32,flags);
  }
  L00443e52: { // 0x443e52: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00443e54: { // 0x443e54: 8b7f08 MOV EDI,dword ptr [EDI + 0x8]
    s.di = m.r32((s.di+0x00000008u));
  }
  L00443e57: { // 0x443e57: 890e MOV dword ptr [ESI],ECX
    m.w32((s.si), s.cx);
  }
  L00443e59: { // 0x443e59: 895604 MOV dword ptr [ESI + 0x4],EDX
    m.w32((s.si+0x00000004u), s.dx);
  }
  L00443e5c: { // 0x443e5c: 897e08 MOV dword ptr [ESI + 0x8],EDI
    m.w32((s.si+0x00000008u), s.di);
  }
  L00443e5f: { // 0x443e5f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00443e60: { // 0x443e60: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00443e61: { // 0x443e61: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000585b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004585b0: { // 0x4585b0: 8b81780c0000 MOV EAX,dword ptr [ECX + 0xc78]
    s.ax = m.r32((s.cx+0x00000c78u));
  }
  L004585b6: { // 0x4585b6: 8b048508ac7b00 MOV EAX,dword ptr [EAX*0x4 + 0x7bac08]
    s.ax = m.r32(((s.ax * 0x00000004u)+0x007bac08u));
  }
  L004585bd: { // 0x4585bd: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000585c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004585c0: { // 0x4585c0: 8a442404 MOV AL,byte ptr [ESP + 0x4]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000004u)));
  }
  L004585c4: { // 0x4585c4: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004585c6: { // 0x4585c6: 7421 JZ 0x004585e9
    if(integer::condition("JZ",flags)) goto L004585e9;
  }
  L004585c8: { // 0x4585c8: 8a8114120000 MOV AL,byte ptr [ECX + 0x1214]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00001214u)));
  }
  L004585ce: { // 0x4585ce: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004585d0: { // 0x4585d0: 7417 JZ 0x004585e9
    if(integer::condition("JZ",flags)) goto L004585e9;
  }
  L004585d2: { // 0x4585d2: 8b81780c0000 MOV EAX,dword ptr [ECX + 0xc78]
    s.ax = m.r32((s.cx+0x00000c78u));
  }
  L004585d8: { // 0x4585d8: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L004585dd: { // 0x4585dd: 8b048560ac7b00 MOV EAX,dword ptr [EAX*0x4 + 0x7bac60]
    s.ax = m.r32(((s.ax * 0x00000004u)+0x007bac60u));
  }
  L004585e4: { // 0x4585e4: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004585e6: { // 0x4585e6: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004585e9: { // 0x4585e9: 8b81780c0000 MOV EAX,dword ptr [ECX + 0xc78]
    s.ax = m.r32((s.cx+0x00000c78u));
  }
  L004585ef: { // 0x4585ef: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L004585f1: { // 0x4585f1: 8b048560ac7b00 MOV EAX,dword ptr [EAX*0x4 + 0x7bac60]
    s.ax = m.r32(((s.ax * 0x00000004u)+0x007bac60u));
  }
  L004585f8: { // 0x4585f8: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004585fa: { // 0x4585fa: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
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
void f_000b8850(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004b8850: { // 0x4b8850: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004b8851: { // 0x4b8851: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004b8852: { // 0x4b8852: 668b5914 MOV BX,word ptr [ECX + 0x14]
    s.bx = with_ax(s.bx, m.r16((s.cx+0x00000014u)));
  }
  L004b8856: { // 0x4b8856: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004b8857: { // 0x4b8857: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004b8858: { // 0x4b8858: 6685db TEST BX,BX
    (void)integer::logical(((s.bx & 0xffffu))&((s.bx & 0xffffu)),16,flags);
  }
  L004b885b: { // 0x4b885b: 7e7d JLE 0x004b88da
    if(integer::condition("JLE",flags)) goto L004b88da;
  }
  L004b885d: { // 0x4b885d: 8b7108 MOV ESI,dword ptr [ECX + 0x8]
    s.si = m.r32((s.cx+0x00000008u));
  }
  L004b8860: { // 0x4b8860: 8b4110 MOV EAX,dword ptr [ECX + 0x10]
    s.ax = m.r32((s.cx+0x00000010u));
  }
  L004b8863: { // 0x4b8863: 8b3d6c89a200 MOV EDI,dword ptr [0x00a2896c]
    s.di = m.r32((0x00a2896cu));
  }
  L004b8869: { // 0x4b8869: 83feff CMP ESI,-0x1
    (void)integer::sub(s.si,0xffffffffu,32,flags);
  }
  L004b886c: { // 0x4b886c: 740a JZ 0x004b8878
    if(integer::condition("JZ",flags)) goto L004b8878;
  }
  L004b886e: { // 0x4b886e: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  L004b8870: { // 0x4b8870: 2bd6 SUB EDX,ESI
    s.dx = integer::sub(s.dx,s.si,32,flags);
  }
  L004b8872: { // 0x4b8872: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L004b8874: { // 0x4b8874: 7d64 JGE 0x004b88da
    if(integer::condition("JGE",flags)) goto L004b88da;
  }
  L004b8876: { // 0x4b8876: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004b8878: { // 0x4b8878: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004b887a: { // 0x4b887a: 745e JZ 0x004b88da
    if(integer::condition("JZ",flags)) goto L004b88da;
  }
  L004b887c: { // 0x4b887c: 668b01 MOV AX,word ptr [ECX]
    s.ax = with_ax(s.ax, m.r16((s.cx)));
  }
  L004b887f: { // 0x4b887f: 662b4104 SUB AX,word ptr [ECX + 0x4]
    s.ax = with_ax(s.ax, integer::sub((s.ax & 0xffffu),m.r16((s.cx+0x00000004u)),16,flags));
  }
  L004b8883: { // 0x4b8883: 0fbfdb MOVSX EBX,BX
    s.bx = std::uint32_t(integer::sign_extend((s.bx & 0xffffu),16));
  }
  L004b8886: { // 0x4b8886: 0fbff0 MOVSX ESI,AX
    s.si = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L004b8889: { // 0x4b8889: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004b888b: { // 0x4b888b: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004b888c: { // 0x4b888c: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L004b888e: { // 0x4b888e: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004b8890: { // 0x4b8890: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004b8891: { // 0x4b8891: f7fb IDIV EBX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.bx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L004b8893: { // 0x4b8893: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L004b8895: { // 0x4b8895: 8954240c MOV dword ptr [ESP + 0xc],EDX
    m.w32((f.sp+0x0000000cu), s.dx);
  }
  L004b8899: { // 0x4b8899: 6685c0 TEST AX,AX
    (void)integer::logical(((s.ax & 0xffffu))&((s.ax & 0xffffu)),16,flags);
  }
  L004b889c: { // 0x4b889c: 7e27 JLE 0x004b88c5
    if(integer::condition("JLE",flags)) goto L004b88c5;
  }
  L004b889e: { // 0x4b889e: 8b5110 MOV EDX,dword ptr [ECX + 0x10]
    s.dx = m.r32((s.cx+0x00000010u));
  }
  L004b88a1: { // 0x4b88a1: 8b4908 MOV ECX,dword ptr [ECX + 0x8]
    s.cx = m.r32((s.cx+0x00000008u));
  }
  L004b88a4: { // 0x4b88a4: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  L004b88a7: { // 0x4b88a7: 740a JZ 0x004b88b3
    if(integer::condition("JZ",flags)) goto L004b88b3;
  }
  L004b88a9: { // 0x4b88a9: 2bf9 SUB EDI,ECX
    s.di = integer::sub(s.di,s.cx,32,flags);
  }
  L004b88ab: { // 0x4b88ab: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L004b88ad: { // 0x4b88ad: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L004b88af: { // 0x4b88af: 7d25 JGE 0x004b88d6
    if(integer::condition("JGE",flags)) goto L004b88d6;
  }
  L004b88b1: { // 0x4b88b1: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L004b88b3: { // 0x4b88b3: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L004b88b5: { // 0x4b88b5: 0fbff8 MOVSX EDI,AX
    s.di = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L004b88b8: { // 0x4b88b8: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004b88ba: { // 0x4b88ba: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004b88bb: { // 0x4b88bb: f7ff IDIV EDI
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.di,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L004b88bd: { // 0x4b88bd: 0fafc1 IMUL EAX,ECX
    s.ax = integer::imul(s.ax,s.cx,32,flags);
  }
  L004b88c0: { // 0x4b88c0: 662944240c SUB word ptr [ESP + 0xc],AX
    m.w16((f.sp+0x0000000cu), integer::sub(m.r16((f.sp+0x0000000cu)),(s.ax & 0xffffu),16,flags));
  }
  L004b88c5: { // 0x4b88c5: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L004b88c9: { // 0x4b88c9: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L004b88cd: { // 0x4b88cd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004b88ce: { // 0x4b88ce: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004b88cf: { // 0x4b88cf: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L004b88d1: { // 0x4b88d1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004b88d2: { // 0x4b88d2: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L004b88d3: { // 0x4b88d3: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004b88d6: { // 0x4b88d6: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L004b88d8: { // 0x4b88d8: ebdb JMP 0x004b88b5
    goto L004b88b5;
  }
  L004b88da: { // 0x4b88da: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L004b88de: { // 0x4b88de: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L004b88e0: { // 0x4b88e0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004b88e1: { // 0x4b88e1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004b88e2: { // 0x4b88e2: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L004b88e4: { // 0x4b88e4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004b88e5: { // 0x4b88e5: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L004b88e6: { // 0x4b88e6: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
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
void f_002bca00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006bca00: { // 0x6bca00: 8b81b4010000 MOV EAX, dword ptr [ECX + 0x1b4]
    s.ax = m.r32((s.cx+0x000001b4u));
  }
  L006bca06: { // 0x6bca06: 8b4030 MOV EAX, dword ptr [EAX + 0x30]
    s.ax = m.r32((s.ax+0x00000030u));
  }
  L006bca09: { // 0x6bca09: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4522064u:f_00050050(m,s,child,{});break;
case 4472336u:f_00043e10(m,s,child,{});break;
case 4556208u:f_000585b0(m,s,child,{});break;
case 4556224u:f_000585c0(m,s,child,{});break;
case 5526784u:f_00145500(m,s,child,{});break;
case 4658096u:f_000713b0(m,s,child,{});break;
case 4950096u:f_000b8850(m,s,child,{});break;
case 4536464u:f_00053890(m,s,child,{});break;
case 7064064u:f_002bca00(m,s,child,{});break;
default:throw std::domain_error("recovery806 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0044daa0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0044daa0: { // 0x44daa0: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  L0044daa3: { // 0x44daa3: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L0044daa7: { // 0x44daa7: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0044daa8: { // 0x44daa8: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0044daa9: { // 0x44daa9: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0044daaa: { // 0x44daaa: bb01000000 MOV EBX,0x1
    s.bx = 0x00000001u;
  }
  L0044daaf: { // 0x44daaf: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0044dab0: { // 0x44dab0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0044dab2: { // 0x44dab2: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0044dab4: { // 0x44dab4: 895c2410 MOV dword ptr [ESP + 0x10],EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
  L0044dab8: { // 0x44dab8: 7d29 JGE 0x0044dae3
    if(integer::condition("JGE",flags)) goto L0044dae3;
  }
  L0044daba: { // 0x44daba: 8b8718040000 MOV EAX,dword ptr [EDI + 0x418]
    s.ax = m.r32((s.di+0x00000418u));
  }
  L0044dac0: { // 0x44dac0: 8a8858130000 MOV CL,byte ptr [EAX + 0x1358]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001358u)));
  }
  L0044dac6: { // 0x44dac6: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044dac8: { // 0x44dac8: 741f JZ 0x0044dae9
    if(integer::condition("JZ",flags)) goto L0044dae9;
  }
  L0044daca: { // 0x44daca: 8b9804050000 MOV EBX,dword ptr [EAX + 0x504]
    s.bx = m.r32((s.ax+0x00000504u));
  }
  L0044dad0: { // 0x44dad0: c1fb08 SAR EBX,0x8
    s.bx = integer::shift(s.bx,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0044dad3: { // 0x44dad3: 83fb01 CMP EBX,0x1
    (void)integer::sub(s.bx,0x00000001u,32,flags);
  }
  L0044dad6: { // 0x44dad6: 895c2410 MOV dword ptr [ESP + 0x10],EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
  L0044dada: { // 0x44dada: 7f0d JG 0x0044dae9
    if(integer::condition("JG",flags)) goto L0044dae9;
  }
  L0044dadc: { // 0x44dadc: bb01000000 MOV EBX,0x1
    s.bx = 0x00000001u;
  }
  L0044dae1: { // 0x44dae1: eb02 JMP 0x0044dae5
    goto L0044dae5;
  }
  L0044dae3: { // 0x44dae3: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0044dae5: { // 0x44dae5: 895c2410 MOV dword ptr [ESP + 0x10],EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
  L0044dae9: { // 0x44dae9: 8b742434 MOV ESI,dword ptr [ESP + 0x34]
    s.si = m.r32((f.sp+0x00000034u));
  }
  L0044daed: { // 0x44daed: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L0044daef: { // 0x44daef: 8d4c2424 LEA ECX,[ESP + 0x24]
    s.cx = (f.sp+0x00000024u);
  }
  L0044daf3: { // 0x44daf3: 8bee MOV EBP,ESI
    s.bp = s.si;
  }
  L0044daf5: { // 0x44daf5: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0044daf6: { // 0x44daf6: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0044daf8: { // 0x44daf8: 83e503 AND EBP,0x3
    s.bp = integer::logical((s.bp)&(0x00000003u),32,flags);
  }
  L0044dafb: { // 0x44dafb: ff5048 CALL dword ptr [EAX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000048u)),4512510u); flags=s.arithmetic_flags;
  }
  L0044dafe: { // 0x44dafe: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0044db00: { // 0x44db00: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0044db02: { // 0x44db02: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0044db03: { // 0x44db03: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0044db09: { // 0x44db09: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0044db0b: { // 0x44db0b: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0044db0e: { // 0x44db0e: 668944243c MOV word ptr [ESP + 0x3c],AX
    m.w16((f.sp+0x0000003cu), (s.ax & 0xffffu));
  }
  L0044db13: { // 0x44db13: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L0044db16: { // 0x44db16: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0044db17: { // 0x44db17: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0044db1d: { // 0x44db1d: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0044db1f: { // 0x44db1f: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0044db22: { // 0x44db22: 668944243e MOV word ptr [ESP + 0x3e],AX
    m.w16((f.sp+0x0000003eu), (s.ax & 0xffffu));
  }
  L0044db27: { // 0x44db27: 8b54243c MOV EDX,dword ptr [ESP + 0x3c]
    s.dx = m.r32((f.sp+0x0000003cu));
  }
  L0044db2b: { // 0x44db2b: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0044db2d: { // 0x44db2d: 89542434 MOV dword ptr [ESP + 0x34],EDX
    m.w32((f.sp+0x00000034u), s.dx);
  }
  L0044db31: { // 0x44db31: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L0044db33: { // 0x44db33: 8944243c MOV dword ptr [ESP + 0x3c],EAX
    m.w32((f.sp+0x0000003cu), s.ax);
  }
  L0044db37: { // 0x44db37: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0044db3b: { // 0x44db3b: 0f8edf000000 JLE 0x0044dc20
    if(integer::condition("JLE",flags)) goto L0044dc20;
  }
  L0044db41: { // 0x44db41: 83e607 AND ESI,0x7
    s.si = integer::logical((s.si)&(0x00000007u),32,flags);
  }
  L0044db44: { // 0x44db44: 8d34b5a09d8300 LEA ESI,[ESI*0x4 + 0x839da0]
    s.si = ((s.si * 0x00000004u)+0x00839da0u);
  }
  L0044db4b: { // 0x44db4b: 8974241c MOV dword ptr [ESP + 0x1c],ESI
    m.w32((f.sp+0x0000001cu), s.si);
  }
  L0044db4f: { // 0x44db4f: eb04 JMP 0x0044db55
    goto L0044db55;
  }
  L0044db51: { // 0x44db51: 8b74241c MOV ESI,dword ptr [ESP + 0x1c]
    s.si = m.r32((f.sp+0x0000001cu));
  }
  L0044db55: { // 0x44db55: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0044db58: { // 0x44db58: 668b4e02 MOV CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000002u)));
  }
  L0044db5c: { // 0x44db5c: 6603442434 ADD AX,word ptr [ESP + 0x34]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((f.sp+0x00000034u)),16,flags));
  }
  L0044db61: { // 0x44db61: 66034c2436 ADD CX,word ptr [ESP + 0x36]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((f.sp+0x00000036u)),16,flags));
  }
  L0044db66: { // 0x44db66: 6689442414 MOV word ptr [ESP + 0x14],AX
    m.w16((f.sp+0x00000014u), (s.ax & 0xffffu));
  }
  L0044db6b: { // 0x44db6b: 66894c2416 MOV word ptr [ESP + 0x16],CX
    m.w16((f.sp+0x00000016u), (s.cx & 0xffffu));
  }
  L0044db70: { // 0x44db70: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L0044db74: { // 0x44db74: 8d442434 LEA EAX,[ESP + 0x34]
    s.ax = (f.sp+0x00000034u);
  }
  L0044db78: { // 0x44db78: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0044db79: { // 0x44db79: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0044db7e: { // 0x44db7e: 89542438 MOV dword ptr [ESP + 0x38],EDX
    m.w32((f.sp+0x00000038u), s.dx);
  }
  L0044db82: { // 0x44db82: e879790f00 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4512647u); flags=s.arithmetic_flags;
  }
  L0044db87: { // 0x44db87: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0044db89: { // 0x44db89: e822380200 CALL 0x004713b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004713b0u,4512654u); flags=s.arithmetic_flags;
  }
  L0044db8e: { // 0x44db8e: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0044db90: { // 0x44db90: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0044db92: { // 0x44db92: 7477 JZ 0x0044dc0b
    if(integer::condition("JZ",flags)) goto L0044dc0b;
  }
  L0044db94: { // 0x44db94: 8b8e18040000 MOV ECX,dword ptr [ESI + 0x418]
    s.cx = m.r32((s.si+0x00000418u));
  }
  L0044db9a: { // 0x44db9a: 8a8158130000 MOV AL,byte ptr [ECX + 0x1358]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00001358u)));
  }
  L0044dba0: { // 0x44dba0: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044dba2: { // 0x44dba2: 7418 JZ 0x0044dbbc
    if(integer::condition("JZ",flags)) goto L0044dbbc;
  }
  L0044dba4: { // 0x44dba4: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0044dba6: { // 0x44dba6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0044dba8: { // 0x44dba8: ff5238 CALL dword ptr [EDX + 0x38]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000038u)),4512683u); flags=s.arithmetic_flags;
  }
  L0044dbab: { // 0x44dbab: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0044dbad: { // 0x44dbad: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L0044dbaf: { // 0x44dbaf: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0044dbb1: { // 0x44dbb1: ff5038 CALL dword ptr [EAX + 0x38]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000038u)),4512692u); flags=s.arithmetic_flags;
  }
  L0044dbb4: { // 0x44dbb4: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0044dbb6: { // 0x44dbb6: 7504 JNZ 0x0044dbbc
    if(integer::condition("JNZ",flags)) goto L0044dbbc;
  }
  L0044dbb8: { // 0x44dbb8: 8974243c MOV dword ptr [ESP + 0x3c],ESI
    m.w32((f.sp+0x0000003cu), s.si);
  }
  L0044dbbc: { // 0x44dbbc: 8a442438 MOV AL,byte ptr [ESP + 0x38]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000038u)));
  }
  L0044dbc0: { // 0x44dbc0: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044dbc2: { // 0x44dbc2: 7458 JZ 0x0044dc1c
    if(integer::condition("JZ",flags)) goto L0044dc1c;
  }
  L0044dbc4: { // 0x44dbc4: 8b8e18040000 MOV ECX,dword ptr [ESI + 0x418]
    s.cx = m.r32((s.si+0x00000418u));
  }
  L0044dbca: { // 0x44dbca: 8a8159130000 MOV AL,byte ptr [ECX + 0x1359]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00001359u)));
  }
  L0044dbd0: { // 0x44dbd0: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044dbd2: { // 0x44dbd2: 7448 JZ 0x0044dc1c
    if(integer::condition("JZ",flags)) goto L0044dc1c;
  }
  L0044dbd4: { // 0x44dbd4: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0044dbd6: { // 0x44dbd6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0044dbd8: { // 0x44dbd8: ff5238 CALL dword ptr [EDX + 0x38]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000038u)),4512731u); flags=s.arithmetic_flags;
  }
  L0044dbdb: { // 0x44dbdb: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0044dbdd: { // 0x44dbdd: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L0044dbdf: { // 0x44dbdf: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0044dbe1: { // 0x44dbe1: ff5038 CALL dword ptr [EAX + 0x38]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000038u)),4512740u); flags=s.arithmetic_flags;
  }
  L0044dbe4: { // 0x44dbe4: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0044dbe6: { // 0x44dbe6: 7534 JNZ 0x0044dc1c
    if(integer::condition("JNZ",flags)) goto L0044dc1c;
  }
  L0044dbe8: { // 0x44dbe8: 8d4c2420 LEA ECX,[ESP + 0x20]
    s.cx = (f.sp+0x00000020u);
  }
  L0044dbec: { // 0x44dbec: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0044dbed: { // 0x44dbed: 8d8ee0020000 LEA ECX,[ESI + 0x2e0]
    s.cx = (s.si+0x000002e0u);
  }
  L0044dbf3: { // 0x44dbf3: e858ac0600 CALL 0x004b8850
    s.arithmetic_flags=flags; invoke(m,s,f,0x004b8850u,4512760u); flags=s.arithmetic_flags;
  }
  L0044dbf8: { // 0x44dbf8: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0044dbfa: { // 0x44dbfa: c1ea0c SHR EDX,0xc
    s.dx = integer::shift(s.dx,0x0000000cu,32,flags,integer::Shift::right);
  }
  L0044dbfd: { // 0x44dbfd: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L0044dbfe: { // 0x44dbfe: d1ea SHR EDX,0x1
    s.dx = integer::shift(s.dx,0x00000001u,32,flags,integer::Shift::right);
  }
  L0044dc00: { // 0x44dc00: 83e203 AND EDX,0x3
    s.dx = integer::logical((s.dx)&(0x00000003u),32,flags);
  }
  L0044dc03: { // 0x44dc03: 3bd5 CMP EDX,EBP
    (void)integer::sub(s.dx,s.bp,32,flags);
  }
  L0044dc05: { // 0x44dc05: 7515 JNZ 0x0044dc1c
    if(integer::condition("JNZ",flags)) goto L0044dc1c;
  }
  L0044dc07: { // 0x44dc07: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L0044dc0b: { // 0x44dc0b: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0044dc0f: { // 0x44dc0f: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0044dc10: { // 0x44dc10: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0044dc12: { // 0x44dc12: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0044dc16: { // 0x44dc16: 0f8c35ffffff JL 0x0044db51
    if(integer::condition("JL",flags)) goto L0044db51;
  }
  L0044dc1c: { // 0x44dc1c: 8b44243c MOV EAX,dword ptr [ESP + 0x3c]
    s.ax = m.r32((f.sp+0x0000003cu));
  }
  L0044dc20: { // 0x44dc20: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0044dc21: { // 0x44dc21: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0044dc22: { // 0x44dc22: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0044dc23: { // 0x44dc23: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0044dc24: { // 0x44dc24: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L0044dc27: { // 0x44dc27: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
