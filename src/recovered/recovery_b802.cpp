#include "recovered/recovery_b802_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b802 {
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
default:throw std::domain_error("recovery802 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0044e290(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0044e290: { // 0x44e290: 83ec50 SUB ESP,0x50
    f.sp = integer::sub(f.sp,0x00000050u,32,flags);
  }
  L0044e293: { // 0x44e293: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0044e294: { // 0x44e294: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0044e296: { // 0x44e296: 895c2420 MOV dword ptr [ESP + 0x20],EBX
    m.w32((f.sp+0x00000020u), s.bx);
  }
  L0044e29a: { // 0x44e29a: 8b8318040000 MOV EAX,dword ptr [EBX + 0x418]
    s.ax = m.r32((s.bx+0x00000418u));
  }
  L0044e2a0: { // 0x44e2a0: 8a8858130000 MOV CL,byte ptr [EAX + 0x1358]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001358u)));
  }
  L0044e2a6: { // 0x44e2a6: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044e2a8: { // 0x44e2a8: 0f844c040000 JZ 0x0044e6fa
    if(integer::condition("JZ",flags)) goto L0044e6fa;
  }
  L0044e2ae: { // 0x44e2ae: 8a4b7d MOV CL,byte ptr [EBX + 0x7d]
    s.cx = with_al(s.cx, m.r8((s.bx+0x0000007du)));
  }
  L0044e2b1: { // 0x44e2b1: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044e2b3: { // 0x44e2b3: 0f8441040000 JZ 0x0044e6fa
    if(integer::condition("JZ",flags)) goto L0044e6fa;
  }
  L0044e2b9: { // 0x44e2b9: 8a4b76 MOV CL,byte ptr [EBX + 0x76]
    s.cx = with_al(s.cx, m.r8((s.bx+0x00000076u)));
  }
  L0044e2bc: { // 0x44e2bc: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044e2be: { // 0x44e2be: 0f8536040000 JNZ 0x0044e6fa
    if(integer::condition("JNZ",flags)) goto L0044e6fa;
  }
  L0044e2c4: { // 0x44e2c4: 8b8004050000 MOV EAX,dword ptr [EAX + 0x504]
    s.ax = m.r32((s.ax+0x00000504u));
  }
  L0044e2ca: { // 0x44e2ca: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0044e2cd: { // 0x44e2cd: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0044e2d0: { // 0x44e2d0: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L0044e2d4: { // 0x44e2d4: 7f08 JG 0x0044e2de
    if(integer::condition("JG",flags)) goto L0044e2de;
  }
  L0044e2d6: { // 0x44e2d6: c744242801000000 MOV dword ptr [ESP + 0x28],0x1
    m.w32((f.sp+0x00000028u), 0x00000001u);
  }
  L0044e2de: { // 0x44e2de: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L0044e2e0: { // 0x44e2e0: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0044e2e2: { // 0x44e2e2: c644240600 MOV byte ptr [ESP + 0x6],0x0
    m.w8((f.sp+0x00000006u), 0x00000000u);
  }
  L0044e2e7: { // 0x44e2e7: ff900c030000 CALL dword ptr [EAX + 0x30c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000030cu)),4514541u); flags=s.arithmetic_flags;
  }
  L0044e2ed: { // 0x44e2ed: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044e2ef: { // 0x44e2ef: 742d JZ 0x0044e31e
    if(integer::condition("JZ",flags)) goto L0044e31e;
  }
  L0044e2f1: { // 0x44e2f1: 8a83ba050000 MOV AL,byte ptr [EBX + 0x5ba]
    s.ax = with_al(s.ax, m.r8((s.bx+0x000005bau)));
  }
  L0044e2f7: { // 0x44e2f7: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044e2f9: { // 0x44e2f9: 7423 JZ 0x0044e31e
    if(integer::condition("JZ",flags)) goto L0044e31e;
  }
  L0044e2fb: { // 0x44e2fb: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L0044e2fd: { // 0x44e2fd: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0044e2ff: { // 0x44e2ff: ff926c010000 CALL dword ptr [EDX + 0x16c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000016cu)),4514565u); flags=s.arithmetic_flags;
  }
  L0044e305: { // 0x44e305: 83f813 CMP EAX,0x13
    (void)integer::sub(s.ax,0x00000013u,32,flags);
  }
  L0044e308: { // 0x44e308: 7414 JZ 0x0044e31e
    if(integer::condition("JZ",flags)) goto L0044e31e;
  }
  L0044e30a: { // 0x44e30a: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L0044e30c: { // 0x44e30c: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0044e30e: { // 0x44e30e: ff906c010000 CALL dword ptr [EAX + 0x16c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000016cu)),4514580u); flags=s.arithmetic_flags;
  }
  L0044e314: { // 0x44e314: 83f812 CMP EAX,0x12
    (void)integer::sub(s.ax,0x00000012u,32,flags);
  }
  L0044e317: { // 0x44e317: 7405 JZ 0x0044e31e
    if(integer::condition("JZ",flags)) goto L0044e31e;
  }
  L0044e319: { // 0x44e319: c644240601 MOV byte ptr [ESP + 0x6],0x1
    m.w8((f.sp+0x00000006u), 0x00000001u);
  }
  L0044e31e: { // 0x44e31e: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0044e31f: { // 0x44e31f: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0044e320: { // 0x44e320: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0044e321: { // 0x44e321: c744242000000000 MOV dword ptr [ESP + 0x20],0x0
    m.w32((f.sp+0x00000020u), 0x00000000u);
  }
  L0044e329: { // 0x44e329: c744244404000000 MOV dword ptr [ESP + 0x44],0x4
    m.w32((f.sp+0x00000044u), 0x00000004u);
  }
  L0044e331: { // 0x44e331: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L0044e333: { // 0x44e333: 8d442454 LEA EAX,[ESP + 0x54]
    s.ax = (f.sp+0x00000054u);
  }
  L0044e337: { // 0x44e337: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0044e338: { // 0x44e338: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0044e33a: { // 0x44e33a: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),4514621u); flags=s.arithmetic_flags;
  }
  L0044e33d: { // 0x44e33d: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0044e33f: { // 0x44e33f: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0044e341: { // 0x44e341: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0044e342: { // 0x44e342: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0044e348: { // 0x44e348: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0044e34a: { // 0x44e34a: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0044e34c: { // 0x44e34c: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L0044e34f: { // 0x44e34f: 8b742420 MOV ESI,dword ptr [ESP + 0x20]
    s.si = m.r32((f.sp+0x00000020u));
  }
  L0044e353: { // 0x44e353: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0044e354: { // 0x44e354: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0044e35a: { // 0x44e35a: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0044e35c: { // 0x44e35c: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L0044e35e: { // 0x44e35e: 83e207 AND EDX,0x7
    s.dx = integer::logical((s.dx)&(0x00000007u),32,flags);
  }
  L0044e361: { // 0x44e361: c1f908 SAR ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0044e364: { // 0x44e364: 668b3c95a09d8300 MOV DI,word ptr [EDX*0x4 + 0x839da0]
    s.di = (s.di & 0xffff0000u) | ((m.r16(((s.dx * 0x00000004u)+0x00839da0u))) & 0xffffu);
  }
  L0044e36c: { // 0x44e36c: 8d1495a09d8300 LEA EDX,[EDX*0x4 + 0x839da0]
    s.dx = ((s.dx * 0x00000004u)+0x00839da0u);
  }
  L0044e373: { // 0x44e373: 6603f9 ADD DI,CX
    s.di = (s.di & 0xffff0000u) | ((integer::add((s.di & 0xffffu),(s.cx & 0xffffu),16,flags)) & 0xffffu);
  }
  L0044e376: { // 0x44e376: 89542448 MOV dword ptr [ESP + 0x48],EDX
    m.w32((f.sp+0x00000048u), s.dx);
  }
  L0044e37a: { // 0x44e37a: 668b4a02 MOV CX,word ptr [EDX + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.dx+0x00000002u)));
  }
  L0044e37e: { // 0x44e37e: 66897c2430 MOV word ptr [ESP + 0x30],DI
    m.w16((f.sp+0x00000030u), (s.di & 0xffffu));
  }
  L0044e383: { // 0x44e383: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0044e386: { // 0x44e386: 6603c8 ADD CX,AX
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),(s.ax & 0xffffu),16,flags));
  }
  L0044e389: { // 0x44e389: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L0044e38d: { // 0x44e38d: 66894c2432 MOV word ptr [ESP + 0x32],CX
    m.w16((f.sp+0x00000032u), (s.cx & 0xffffu));
  }
  L0044e392: { // 0x44e392: 8b542430 MOV EDX,dword ptr [ESP + 0x30]
    s.dx = m.r32((f.sp+0x00000030u));
  }
  L0044e396: { // 0x44e396: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0044e397: { // 0x44e397: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0044e39c: { // 0x44e39c: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L0044e3a0: { // 0x44e3a0: e85b710f00 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4514725u); flags=s.arithmetic_flags;
  }
  L0044e3a5: { // 0x44e3a5: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0044e3a7: { // 0x44e3a7: e804300200 CALL 0x004713b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004713b0u,4514732u); flags=s.arithmetic_flags;
  }
  L0044e3ac: { // 0x44e3ac: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0044e3ae: { // 0x44e3ae: 83e603 AND ESI,0x3
    s.si = integer::logical((s.si)&(0x00000003u),32,flags);
  }
  L0044e3b1: { // 0x44e3b1: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0044e3b3: { // 0x44e3b3: 89742428 MOV dword ptr [ESP + 0x28],ESI
    m.w32((f.sp+0x00000028u), s.si);
  }
  L0044e3b7: { // 0x44e3b7: 0f841d030000 JZ 0x0044e6da
    if(integer::condition("JZ",flags)) goto L0044e6da;
  }
  L0044e3bd: { // 0x44e3bd: 8b8f18040000 MOV ECX,dword ptr [EDI + 0x418]
    s.cx = m.r32((s.di+0x00000418u));
  }
  L0044e3c3: { // 0x44e3c3: 8a8159130000 MOV AL,byte ptr [ECX + 0x1359]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00001359u)));
  }
  L0044e3c9: { // 0x44e3c9: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044e3cb: { // 0x44e3cb: 0f8409030000 JZ 0x0044e6da
    if(integer::condition("JZ",flags)) goto L0044e6da;
  }
  L0044e3d1: { // 0x44e3d1: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L0044e3d3: { // 0x44e3d3: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0044e3d5: { // 0x44e3d5: ff5238 CALL dword ptr [EDX + 0x38]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000038u)),4514776u); flags=s.arithmetic_flags;
  }
  L0044e3d8: { // 0x44e3d8: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L0044e3da: { // 0x44e3da: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L0044e3dc: { // 0x44e3dc: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0044e3de: { // 0x44e3de: ff5038 CALL dword ptr [EAX + 0x38]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000038u)),4514785u); flags=s.arithmetic_flags;
  }
  L0044e3e1: { // 0x44e3e1: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L0044e3e3: { // 0x44e3e3: 0f85f1020000 JNZ 0x0044e6da
    if(integer::condition("JNZ",flags)) goto L0044e6da;
  }
  L0044e3e9: { // 0x44e3e9: 8d4c244c LEA ECX,[ESP + 0x4c]
    s.cx = (f.sp+0x0000004cu);
  }
  L0044e3ed: { // 0x44e3ed: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0044e3ee: { // 0x44e3ee: 8d8fe0020000 LEA ECX,[EDI + 0x2e0]
    s.cx = (s.di+0x000002e0u);
  }
  L0044e3f4: { // 0x44e3f4: e857a40600 CALL 0x004b8850
    s.arithmetic_flags=flags; invoke(m,s,f,0x004b8850u,4514809u); flags=s.arithmetic_flags;
  }
  L0044e3f9: { // 0x44e3f9: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0044e3fb: { // 0x44e3fb: c1ea0c SHR EDX,0xc
    s.dx = integer::shift(s.dx,0x0000000cu,32,flags,integer::Shift::right);
  }
  L0044e3fe: { // 0x44e3fe: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L0044e3ff: { // 0x44e3ff: d1ea SHR EDX,0x1
    s.dx = integer::shift(s.dx,0x00000001u,32,flags,integer::Shift::right);
  }
  L0044e401: { // 0x44e401: 83e203 AND EDX,0x3
    s.dx = integer::logical((s.dx)&(0x00000003u),32,flags);
  }
  L0044e404: { // 0x44e404: 3bd6 CMP EDX,ESI
    (void)integer::sub(s.dx,s.si,32,flags);
  }
  L0044e406: { // 0x44e406: 0f85ce020000 JNZ 0x0044e6da
    if(integer::condition("JNZ",flags)) goto L0044e6da;
  }
  L0044e40c: { // 0x44e40c: 8a442464 MOV AL,byte ptr [ESP + 0x64]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000064u)));
  }
  L0044e410: { // 0x44e410: 897c2440 MOV dword ptr [ESP + 0x40],EDI
    m.w32((f.sp+0x00000040u), s.di);
  }
  L0044e414: { // 0x44e414: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044e416: { // 0x44e416: 897c243c MOV dword ptr [ESP + 0x3c],EDI
    m.w32((f.sp+0x0000003cu), s.di);
  }
  L0044e41a: { // 0x44e41a: 752a JNZ 0x0044e446
    if(integer::condition("JNZ",flags)) goto L0044e446;
  }
  L0044e41c: { // 0x44e41c: 8a442412 MOV AL,byte ptr [ESP + 0x12]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000012u)));
  }
  L0044e420: { // 0x44e420: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044e422: { // 0x44e422: 7415 JZ 0x0044e439
    if(integer::condition("JZ",flags)) goto L0044e439;
  }
  L0044e424: { // 0x44e424: 8b87ec040000 MOV EAX,dword ptr [EDI + 0x4ec]
    s.ax = m.r32((s.di+0x000004ecu));
  }
  L0044e42a: { // 0x44e42a: bd08000000 MOV EBP,0x8
    s.bp = 0x00000008u;
  }
  L0044e42f: { // 0x44e42f: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L0044e431: { // 0x44e431: 0f8ca3020000 JL 0x0044e6da
    if(integer::condition("JL",flags)) goto L0044e6da;
  }
  L0044e437: { // 0x44e437: eb12 JMP 0x0044e44b
    goto L0044e44b;
  }
  L0044e439: { // 0x44e439: 83bfec04000008 CMP dword ptr [EDI + 0x4ec],0x8
    (void)integer::sub(m.r32((s.di+0x000004ecu)),0x00000008u,32,flags);
  }
  L0044e440: { // 0x44e440: 0f8d94020000 JGE 0x0044e6da
    if(integer::condition("JGE",flags)) goto L0044e6da;
  }
  L0044e446: { // 0x44e446: bd08000000 MOV EBP,0x8
    s.bp = 0x00000008u;
  }
  L0044e44b: { // 0x44e44b: 8a442412 MOV AL,byte ptr [ESP + 0x12]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000012u)));
  }
  L0044e44f: { // 0x44e44f: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0044e451: { // 0x44e451: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044e453: { // 0x44e453: 7412 JZ 0x0044e467
    if(integer::condition("JZ",flags)) goto L0044e467;
  }
  L0044e455: { // 0x44e455: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L0044e459: { // 0x44e459: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L0044e45b: { // 0x44e45b: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0044e45d: { // 0x44e45d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0044e45e: { // 0x44e45e: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0044e460: { // 0x44e460: e83bf6ffff CALL 0x0044daa0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0044daa0u,4514917u); flags=s.arithmetic_flags;
  }
  L0044e465: { // 0x44e465: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0044e467: { // 0x44e467: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L0044e46b: { // 0x44e46b: bb0c000000 MOV EBX,0xc
    s.bx = 0x0000000cu;
  }
  L0044e470: { // 0x44e470: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  L0044e473: { // 0x44e473: 895c2414 MOV dword ptr [ESP + 0x14],EBX
    m.w32((f.sp+0x00000014u), s.bx);
  }
  L0044e477: { // 0x44e477: 895c241c MOV dword ptr [ESP + 0x1c],EBX
    m.w32((f.sp+0x0000001cu), s.bx);
  }
  L0044e47b: { // 0x44e47b: 750a JNZ 0x0044e487
    if(integer::condition("JNZ",flags)) goto L0044e487;
  }
  L0044e47d: { // 0x44e47d: 8bdd MOV EBX,EBP
    s.bx = s.bp;
  }
  L0044e47f: { // 0x44e47f: 896c2414 MOV dword ptr [ESP + 0x14],EBP
    m.w32((f.sp+0x00000014u), s.bp);
  }
  L0044e483: { // 0x44e483: 896c241c MOV dword ptr [ESP + 0x1c],EBP
    m.w32((f.sp+0x0000001cu), s.bp);
  }
  L0044e487: { // 0x44e487: 8a442412 MOV AL,byte ptr [ESP + 0x12]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000012u)));
  }
  L0044e48b: { // 0x44e48b: c644241300 MOV byte ptr [ESP + 0x13],0x0
    m.w8((f.sp+0x00000013u), 0x00000000u);
  }
  L0044e490: { // 0x44e490: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044e492: { // 0x44e492: 0f84af000000 JZ 0x0044e547
    if(integer::condition("JZ",flags)) goto L0044e547;
  }
  L0044e498: { // 0x44e498: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L0044e49a: { // 0x44e49a: 3bf5 CMP ESI,EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  L0044e49c: { // 0x44e49c: 0f84a5000000 JZ 0x0044e547
    if(integer::condition("JZ",flags)) goto L0044e547;
  }
  L0044e4a2: { // 0x44e4a2: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0044e4a4: { // 0x44e4a4: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0044e4a6: { // 0x44e4a6: ff920c030000 CALL dword ptr [EDX + 0x30c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000030cu)),4514988u); flags=s.arithmetic_flags;
  }
  L0044e4ac: { // 0x44e4ac: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044e4ae: { // 0x44e4ae: 0f8493000000 JZ 0x0044e547
    if(integer::condition("JZ",flags)) goto L0044e547;
  }
  L0044e4b4: { // 0x44e4b4: 8a86ba050000 MOV AL,byte ptr [ESI + 0x5ba]
    s.ax = with_al(s.ax, m.r8((s.si+0x000005bau)));
  }
  L0044e4ba: { // 0x44e4ba: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044e4bc: { // 0x44e4bc: 0f8485000000 JZ 0x0044e547
    if(integer::condition("JZ",flags)) goto L0044e547;
  }
  L0044e4c2: { // 0x44e4c2: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0044e4c4: { // 0x44e4c4: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0044e4c6: { // 0x44e4c6: ff906c010000 CALL dword ptr [EAX + 0x16c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000016cu)),4515020u); flags=s.arithmetic_flags;
  }
  L0044e4cc: { // 0x44e4cc: 83f813 CMP EAX,0x13
    (void)integer::sub(s.ax,0x00000013u,32,flags);
  }
  L0044e4cf: { // 0x44e4cf: 7476 JZ 0x0044e547
    if(integer::condition("JZ",flags)) goto L0044e547;
  }
  L0044e4d1: { // 0x44e4d1: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0044e4d3: { // 0x44e4d3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0044e4d5: { // 0x44e4d5: ff926c010000 CALL dword ptr [EDX + 0x16c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000016cu)),4515035u); flags=s.arithmetic_flags;
  }
  L0044e4db: { // 0x44e4db: 83f812 CMP EAX,0x12
    (void)integer::sub(s.ax,0x00000012u,32,flags);
  }
  L0044e4de: { // 0x44e4de: 7467 JZ 0x0044e547
    if(integer::condition("JZ",flags)) goto L0044e547;
  }
  L0044e4e0: { // 0x44e4e0: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L0044e4e4: { // 0x44e4e4: c644241301 MOV byte ptr [ESP + 0x13],0x1
    m.w8((f.sp+0x00000013u), 0x00000001u);
  }
  L0044e4e9: { // 0x44e4e9: 83f806 CMP EAX,0x6
    (void)integer::sub(s.ax,0x00000006u,32,flags);
  }
  L0044e4ec: { // 0x44e4ec: 7759 JA 0x0044e547
    if(integer::condition("JA",flags)) goto L0044e547;
  }
  L0044e4ee: { // 0x44e4ee: ff248504e74400 JMP dword ptr [EAX*0x4 + 0x44e704]
    switch(m.r32(((s.ax * 0x00000004u)+0x0044e704u))){
    case 0x0044e290u: goto L0044e290;
    case 0x0044e293u: goto L0044e293;
    case 0x0044e294u: goto L0044e294;
    case 0x0044e296u: goto L0044e296;
    case 0x0044e29au: goto L0044e29a;
    case 0x0044e2a0u: goto L0044e2a0;
    case 0x0044e2a6u: goto L0044e2a6;
    case 0x0044e2a8u: goto L0044e2a8;
    case 0x0044e2aeu: goto L0044e2ae;
    case 0x0044e2b1u: goto L0044e2b1;
    case 0x0044e2b3u: goto L0044e2b3;
    case 0x0044e2b9u: goto L0044e2b9;
    case 0x0044e2bcu: goto L0044e2bc;
    case 0x0044e2beu: goto L0044e2be;
    case 0x0044e2c4u: goto L0044e2c4;
    case 0x0044e2cau: goto L0044e2ca;
    case 0x0044e2cdu: goto L0044e2cd;
    case 0x0044e2d0u: goto L0044e2d0;
    case 0x0044e2d4u: goto L0044e2d4;
    case 0x0044e2d6u: goto L0044e2d6;
    case 0x0044e2deu: goto L0044e2de;
    case 0x0044e2e0u: goto L0044e2e0;
    case 0x0044e2e2u: goto L0044e2e2;
    case 0x0044e2e7u: goto L0044e2e7;
    case 0x0044e2edu: goto L0044e2ed;
    case 0x0044e2efu: goto L0044e2ef;
    case 0x0044e2f1u: goto L0044e2f1;
    case 0x0044e2f7u: goto L0044e2f7;
    case 0x0044e2f9u: goto L0044e2f9;
    case 0x0044e2fbu: goto L0044e2fb;
    case 0x0044e2fdu: goto L0044e2fd;
    case 0x0044e2ffu: goto L0044e2ff;
    case 0x0044e305u: goto L0044e305;
    case 0x0044e308u: goto L0044e308;
    case 0x0044e30au: goto L0044e30a;
    case 0x0044e30cu: goto L0044e30c;
    case 0x0044e30eu: goto L0044e30e;
    case 0x0044e314u: goto L0044e314;
    case 0x0044e317u: goto L0044e317;
    case 0x0044e319u: goto L0044e319;
    case 0x0044e31eu: goto L0044e31e;
    case 0x0044e31fu: goto L0044e31f;
    case 0x0044e320u: goto L0044e320;
    case 0x0044e321u: goto L0044e321;
    case 0x0044e329u: goto L0044e329;
    case 0x0044e331u: goto L0044e331;
    case 0x0044e333u: goto L0044e333;
    case 0x0044e337u: goto L0044e337;
    case 0x0044e338u: goto L0044e338;
    case 0x0044e33au: goto L0044e33a;
    case 0x0044e33du: goto L0044e33d;
    case 0x0044e33fu: goto L0044e33f;
    case 0x0044e341u: goto L0044e341;
    case 0x0044e342u: goto L0044e342;
    case 0x0044e348u: goto L0044e348;
    case 0x0044e34au: goto L0044e34a;
    case 0x0044e34cu: goto L0044e34c;
    case 0x0044e34fu: goto L0044e34f;
    case 0x0044e353u: goto L0044e353;
    case 0x0044e354u: goto L0044e354;
    case 0x0044e35au: goto L0044e35a;
    case 0x0044e35cu: goto L0044e35c;
    case 0x0044e35eu: goto L0044e35e;
    case 0x0044e361u: goto L0044e361;
    case 0x0044e364u: goto L0044e364;
    case 0x0044e36cu: goto L0044e36c;
    case 0x0044e373u: goto L0044e373;
    case 0x0044e376u: goto L0044e376;
    case 0x0044e37au: goto L0044e37a;
    case 0x0044e37eu: goto L0044e37e;
    case 0x0044e383u: goto L0044e383;
    case 0x0044e386u: goto L0044e386;
    case 0x0044e389u: goto L0044e389;
    case 0x0044e38du: goto L0044e38d;
    case 0x0044e392u: goto L0044e392;
    case 0x0044e396u: goto L0044e396;
    case 0x0044e397u: goto L0044e397;
    case 0x0044e39cu: goto L0044e39c;
    case 0x0044e3a0u: goto L0044e3a0;
    case 0x0044e3a5u: goto L0044e3a5;
    case 0x0044e3a7u: goto L0044e3a7;
    case 0x0044e3acu: goto L0044e3ac;
    case 0x0044e3aeu: goto L0044e3ae;
    case 0x0044e3b1u: goto L0044e3b1;
    case 0x0044e3b3u: goto L0044e3b3;
    case 0x0044e3b7u: goto L0044e3b7;
    case 0x0044e3bdu: goto L0044e3bd;
    case 0x0044e3c3u: goto L0044e3c3;
    case 0x0044e3c9u: goto L0044e3c9;
    case 0x0044e3cbu: goto L0044e3cb;
    case 0x0044e3d1u: goto L0044e3d1;
    case 0x0044e3d3u: goto L0044e3d3;
    case 0x0044e3d5u: goto L0044e3d5;
    case 0x0044e3d8u: goto L0044e3d8;
    case 0x0044e3dau: goto L0044e3da;
    case 0x0044e3dcu: goto L0044e3dc;
    case 0x0044e3deu: goto L0044e3de;
    case 0x0044e3e1u: goto L0044e3e1;
    case 0x0044e3e3u: goto L0044e3e3;
    case 0x0044e3e9u: goto L0044e3e9;
    case 0x0044e3edu: goto L0044e3ed;
    case 0x0044e3eeu: goto L0044e3ee;
    case 0x0044e3f4u: goto L0044e3f4;
    case 0x0044e3f9u: goto L0044e3f9;
    case 0x0044e3fbu: goto L0044e3fb;
    case 0x0044e3feu: goto L0044e3fe;
    case 0x0044e3ffu: goto L0044e3ff;
    case 0x0044e401u: goto L0044e401;
    case 0x0044e404u: goto L0044e404;
    case 0x0044e406u: goto L0044e406;
    case 0x0044e40cu: goto L0044e40c;
    case 0x0044e410u: goto L0044e410;
    case 0x0044e414u: goto L0044e414;
    case 0x0044e416u: goto L0044e416;
    case 0x0044e41au: goto L0044e41a;
    case 0x0044e41cu: goto L0044e41c;
    case 0x0044e420u: goto L0044e420;
    case 0x0044e422u: goto L0044e422;
    case 0x0044e424u: goto L0044e424;
    case 0x0044e42au: goto L0044e42a;
    case 0x0044e42fu: goto L0044e42f;
    case 0x0044e431u: goto L0044e431;
    case 0x0044e437u: goto L0044e437;
    case 0x0044e439u: goto L0044e439;
    case 0x0044e440u: goto L0044e440;
    case 0x0044e446u: goto L0044e446;
    case 0x0044e44bu: goto L0044e44b;
    case 0x0044e44fu: goto L0044e44f;
    case 0x0044e451u: goto L0044e451;
    case 0x0044e453u: goto L0044e453;
    case 0x0044e455u: goto L0044e455;
    case 0x0044e459u: goto L0044e459;
    case 0x0044e45bu: goto L0044e45b;
    case 0x0044e45du: goto L0044e45d;
    case 0x0044e45eu: goto L0044e45e;
    case 0x0044e460u: goto L0044e460;
    case 0x0044e465u: goto L0044e465;
    case 0x0044e467u: goto L0044e467;
    case 0x0044e46bu: goto L0044e46b;
    case 0x0044e470u: goto L0044e470;
    case 0x0044e473u: goto L0044e473;
    case 0x0044e477u: goto L0044e477;
    case 0x0044e47bu: goto L0044e47b;
    case 0x0044e47du: goto L0044e47d;
    case 0x0044e47fu: goto L0044e47f;
    case 0x0044e483u: goto L0044e483;
    case 0x0044e487u: goto L0044e487;
    case 0x0044e48bu: goto L0044e48b;
    case 0x0044e490u: goto L0044e490;
    case 0x0044e492u: goto L0044e492;
    case 0x0044e498u: goto L0044e498;
    case 0x0044e49au: goto L0044e49a;
    case 0x0044e49cu: goto L0044e49c;
    case 0x0044e4a2u: goto L0044e4a2;
    case 0x0044e4a4u: goto L0044e4a4;
    case 0x0044e4a6u: goto L0044e4a6;
    case 0x0044e4acu: goto L0044e4ac;
    case 0x0044e4aeu: goto L0044e4ae;
    case 0x0044e4b4u: goto L0044e4b4;
    case 0x0044e4bau: goto L0044e4ba;
    case 0x0044e4bcu: goto L0044e4bc;
    case 0x0044e4c2u: goto L0044e4c2;
    case 0x0044e4c4u: goto L0044e4c4;
    case 0x0044e4c6u: goto L0044e4c6;
    case 0x0044e4ccu: goto L0044e4cc;
    case 0x0044e4cfu: goto L0044e4cf;
    case 0x0044e4d1u: goto L0044e4d1;
    case 0x0044e4d3u: goto L0044e4d3;
    case 0x0044e4d5u: goto L0044e4d5;
    case 0x0044e4dbu: goto L0044e4db;
    case 0x0044e4deu: goto L0044e4de;
    case 0x0044e4e0u: goto L0044e4e0;
    case 0x0044e4e4u: goto L0044e4e4;
    case 0x0044e4e9u: goto L0044e4e9;
    case 0x0044e4ecu: goto L0044e4ec;
    case 0x0044e4eeu: goto L0044e4ee;
    case 0x0044e4f5u: goto L0044e4f5;
    case 0x0044e4fau: goto L0044e4fa;
    case 0x0044e502u: goto L0044e502;
    case 0x0044e50au: goto L0044e50a;
    case 0x0044e50cu: goto L0044e50c;
    case 0x0044e511u: goto L0044e511;
    case 0x0044e519u: goto L0044e519;
    case 0x0044e521u: goto L0044e521;
    case 0x0044e523u: goto L0044e523;
    case 0x0044e528u: goto L0044e528;
    case 0x0044e52cu: goto L0044e52c;
    case 0x0044e534u: goto L0044e534;
    case 0x0044e536u: goto L0044e536;
    case 0x0044e53bu: goto L0044e53b;
    case 0x0044e53fu: goto L0044e53f;
    case 0x0044e547u: goto L0044e547;
    case 0x0044e54fu: goto L0044e54f;
    case 0x0044e553u: goto L0044e553;
    case 0x0044e557u: goto L0044e557;
    case 0x0044e559u: goto L0044e559;
    case 0x0044e55fu: goto L0044e55f;
    case 0x0044e565u: goto L0044e565;
    case 0x0044e56bu: goto L0044e56b;
    case 0x0044e56du: goto L0044e56d;
    case 0x0044e573u: goto L0044e573;
    case 0x0044e575u: goto L0044e575;
    case 0x0044e577u: goto L0044e577;
    case 0x0044e57au: goto L0044e57a;
    case 0x0044e57eu: goto L0044e57e;
    case 0x0044e580u: goto L0044e580;
    case 0x0044e582u: goto L0044e582;
    case 0x0044e585u: goto L0044e585;
    case 0x0044e587u: goto L0044e587;
    case 0x0044e58du: goto L0044e58d;
    case 0x0044e591u: goto L0044e591;
    case 0x0044e592u: goto L0044e592;
    case 0x0044e598u: goto L0044e598;
    case 0x0044e59du: goto L0044e59d;
    case 0x0044e59fu: goto L0044e59f;
    case 0x0044e5a3u: goto L0044e5a3;
    case 0x0044e5a6u: goto L0044e5a6;
    case 0x0044e5a7u: goto L0044e5a7;
    case 0x0044e5a9u: goto L0044e5a9;
    case 0x0044e5acu: goto L0044e5ac;
    case 0x0044e5aeu: goto L0044e5ae;
    case 0x0044e5b4u: goto L0044e5b4;
    case 0x0044e5b8u: goto L0044e5b8;
    case 0x0044e5bcu: goto L0044e5bc;
    case 0x0044e5beu: goto L0044e5be;
    case 0x0044e5c0u: goto L0044e5c0;
    case 0x0044e5c6u: goto L0044e5c6;
    case 0x0044e5c8u: goto L0044e5c8;
    case 0x0044e5ccu: goto L0044e5cc;
    case 0x0044e5d2u: goto L0044e5d2;
    case 0x0044e5d6u: goto L0044e5d6;
    case 0x0044e5dau: goto L0044e5da;
    case 0x0044e5dcu: goto L0044e5dc;
    case 0x0044e5deu: goto L0044e5de;
    case 0x0044e5e2u: goto L0044e5e2;
    case 0x0044e5e3u: goto L0044e5e3;
    case 0x0044e5e8u: goto L0044e5e8;
    case 0x0044e5edu: goto L0044e5ed;
    case 0x0044e5f3u: goto L0044e5f3;
    case 0x0044e5f5u: goto L0044e5f5;
    case 0x0044e5f7u: goto L0044e5f7;
    case 0x0044e5f9u: goto L0044e5f9;
    case 0x0044e5fbu: goto L0044e5fb;
    case 0x0044e5feu: goto L0044e5fe;
    case 0x0044e600u: goto L0044e600;
    case 0x0044e602u: goto L0044e602;
    case 0x0044e605u: goto L0044e605;
    case 0x0044e607u: goto L0044e607;
    case 0x0044e60au: goto L0044e60a;
    case 0x0044e60cu: goto L0044e60c;
    case 0x0044e60fu: goto L0044e60f;
    case 0x0044e612u: goto L0044e612;
    case 0x0044e615u: goto L0044e615;
    case 0x0044e617u: goto L0044e617;
    case 0x0044e619u: goto L0044e619;
    case 0x0044e61fu: goto L0044e61f;
    case 0x0044e621u: goto L0044e621;
    case 0x0044e623u: goto L0044e623;
    case 0x0044e625u: goto L0044e625;
    case 0x0044e62bu: goto L0044e62b;
    case 0x0044e62cu: goto L0044e62c;
    case 0x0044e62du: goto L0044e62d;
    case 0x0044e62fu: goto L0044e62f;
    case 0x0044e630u: goto L0044e630;
    case 0x0044e632u: goto L0044e632;
    case 0x0044e638u: goto L0044e638;
    case 0x0044e63au: goto L0044e63a;
    case 0x0044e63cu: goto L0044e63c;
    case 0x0044e63fu: goto L0044e63f;
    case 0x0044e641u: goto L0044e641;
    case 0x0044e643u: goto L0044e643;
    case 0x0044e647u: goto L0044e647;
    case 0x0044e64bu: goto L0044e64b;
    case 0x0044e64cu: goto L0044e64c;
    case 0x0044e64fu: goto L0044e64f;
    case 0x0044e653u: goto L0044e653;
    case 0x0044e658u: goto L0044e658;
    case 0x0044e65du: goto L0044e65d;
    case 0x0044e661u: goto L0044e661;
    case 0x0044e666u: goto L0044e666;
    case 0x0044e66bu: goto L0044e66b;
    case 0x0044e66fu: goto L0044e66f;
    case 0x0044e673u: goto L0044e673;
    case 0x0044e677u: goto L0044e677;
    case 0x0044e678u: goto L0044e678;
    case 0x0044e67du: goto L0044e67d;
    case 0x0044e682u: goto L0044e682;
    case 0x0044e684u: goto L0044e684;
    case 0x0044e689u: goto L0044e689;
    case 0x0044e68bu: goto L0044e68b;
    case 0x0044e68du: goto L0044e68d;
    case 0x0044e693u: goto L0044e693;
    case 0x0044e697u: goto L0044e697;
    case 0x0044e699u: goto L0044e699;
    case 0x0044e69bu: goto L0044e69b;
    case 0x0044e69fu: goto L0044e69f;
    case 0x0044e6a1u: goto L0044e6a1;
    case 0x0044e6a3u: goto L0044e6a3;
    case 0x0044e6a7u: goto L0044e6a7;
    case 0x0044e6a9u: goto L0044e6a9;
    case 0x0044e6aeu: goto L0044e6ae;
    case 0x0044e6b0u: goto L0044e6b0;
    case 0x0044e6bau: goto L0044e6ba;
    case 0x0044e6bcu: goto L0044e6bc;
    case 0x0044e6c6u: goto L0044e6c6;
    case 0x0044e6c8u: goto L0044e6c8;
    case 0x0044e6ccu: goto L0044e6cc;
    case 0x0044e6d2u: goto L0044e6d2;
    case 0x0044e6d6u: goto L0044e6d6;
    case 0x0044e6dau: goto L0044e6da;
    case 0x0044e6deu: goto L0044e6de;
    case 0x0044e6e2u: goto L0044e6e2;
    case 0x0044e6e5u: goto L0044e6e5;
    case 0x0044e6e8u: goto L0044e6e8;
    case 0x0044e6e9u: goto L0044e6e9;
    case 0x0044e6edu: goto L0044e6ed;
    case 0x0044e6f1u: goto L0044e6f1;
    case 0x0044e6f7u: goto L0044e6f7;
    case 0x0044e6f8u: goto L0044e6f8;
    case 0x0044e6f9u: goto L0044e6f9;
    case 0x0044e6fau: goto L0044e6fa;
    case 0x0044e6fbu: goto L0044e6fb;
    case 0x0044e6feu: goto L0044e6fe;
    default:throw std::domain_error("recovery802 unsupported switch destination");}
  }
  L0044e4f5: { // 0x44e4f5: bb05000000 MOV EBX,0x5
    s.bx = 0x00000005u;
  }
  L0044e4fa: { // 0x44e4fa: c744241404000000 MOV dword ptr [ESP + 0x14],0x4
    m.w32((f.sp+0x00000014u), 0x00000004u);
  }
  L0044e502: { // 0x44e502: c744241c06000000 MOV dword ptr [ESP + 0x1c],0x6
    m.w32((f.sp+0x0000001cu), 0x00000006u);
  }
  L0044e50a: { // 0x44e50a: eb3b JMP 0x0044e547
    goto L0044e547;
  }
  L0044e50c: { // 0x44e50c: bb06000000 MOV EBX,0x6
    s.bx = 0x00000006u;
  }
  L0044e511: { // 0x44e511: c744241404000000 MOV dword ptr [ESP + 0x14],0x4
    m.w32((f.sp+0x00000014u), 0x00000004u);
  }
  L0044e519: { // 0x44e519: c744241c05000000 MOV dword ptr [ESP + 0x1c],0x5
    m.w32((f.sp+0x0000001cu), 0x00000005u);
  }
  L0044e521: { // 0x44e521: eb24 JMP 0x0044e547
    goto L0044e547;
  }
  L0044e523: { // 0x44e523: bb01000000 MOV EBX,0x1
    s.bx = 0x00000001u;
  }
  L0044e528: { // 0x44e528: 896c2414 MOV dword ptr [ESP + 0x14],EBP
    m.w32((f.sp+0x00000014u), s.bp);
  }
  L0044e52c: { // 0x44e52c: c744241c02000000 MOV dword ptr [ESP + 0x1c],0x2
    m.w32((f.sp+0x0000001cu), 0x00000002u);
  }
  L0044e534: { // 0x44e534: eb11 JMP 0x0044e547
    goto L0044e547;
  }
  L0044e536: { // 0x44e536: bb02000000 MOV EBX,0x2
    s.bx = 0x00000002u;
  }
  L0044e53b: { // 0x44e53b: 896c2414 MOV dword ptr [ESP + 0x14],EBP
    m.w32((f.sp+0x00000014u), s.bp);
  }
  L0044e53f: { // 0x44e53f: c744241c01000000 MOV dword ptr [ESP + 0x1c],0x1
    m.w32((f.sp+0x0000001cu), 0x00000001u);
  }
  L0044e547: { // 0x44e547: c744242400000000 MOV dword ptr [ESP + 0x24],0x0
    m.w32((f.sp+0x00000024u), 0x00000000u);
  }
  L0044e54f: { // 0x44e54f: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L0044e553: { // 0x44e553: 8b4c2434 MOV ECX,dword ptr [ESP + 0x34]
    s.cx = m.r32((f.sp+0x00000034u));
  }
  L0044e557: { // 0x44e557: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0044e559: { // 0x44e559: 0f8d34010000 JGE 0x0044e693
    if(integer::condition("JGE",flags)) goto L0044e693;
  }
  L0044e55f: { // 0x44e55f: 8b8f18040000 MOV ECX,dword ptr [EDI + 0x418]
    s.cx = m.r32((s.di+0x00000418u));
  }
  L0044e565: { // 0x44e565: 8a8159130000 MOV AL,byte ptr [ECX + 0x1359]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00001359u)));
  }
  L0044e56b: { // 0x44e56b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044e56d: { // 0x44e56d: 0f8420010000 JZ 0x0044e693
    if(integer::condition("JZ",flags)) goto L0044e693;
  }
  L0044e573: { // 0x44e573: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L0044e575: { // 0x44e575: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0044e577: { // 0x44e577: ff5238 CALL dword ptr [EDX + 0x38]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000038u)),4515194u); flags=s.arithmetic_flags;
  }
  L0044e57a: { // 0x44e57a: 8b4c242c MOV ECX,dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L0044e57e: { // 0x44e57e: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0044e580: { // 0x44e580: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0044e582: { // 0x44e582: ff5038 CALL dword ptr [EAX + 0x38]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000038u)),4515205u); flags=s.arithmetic_flags;
  }
  L0044e585: { // 0x44e585: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L0044e587: { // 0x44e587: 0f8506010000 JNZ 0x0044e693
    if(integer::condition("JNZ",flags)) goto L0044e693;
  }
  L0044e58d: { // 0x44e58d: 8d4c2450 LEA ECX,[ESP + 0x50]
    s.cx = (f.sp+0x00000050u);
  }
  L0044e591: { // 0x44e591: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0044e592: { // 0x44e592: 8d8fe0020000 LEA ECX,[EDI + 0x2e0]
    s.cx = (s.di+0x000002e0u);
  }
  L0044e598: { // 0x44e598: e8b3a20600 CALL 0x004b8850
    s.arithmetic_flags=flags; invoke(m,s,f,0x004b8850u,4515229u); flags=s.arithmetic_flags;
  }
  L0044e59d: { // 0x44e59d: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0044e59f: { // 0x44e59f: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L0044e5a3: { // 0x44e5a3: c1ea0c SHR EDX,0xc
    s.dx = integer::shift(s.dx,0x0000000cu,32,flags,integer::Shift::right);
  }
  L0044e5a6: { // 0x44e5a6: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L0044e5a7: { // 0x44e5a7: d1ea SHR EDX,0x1
    s.dx = integer::shift(s.dx,0x00000001u,32,flags,integer::Shift::right);
  }
  L0044e5a9: { // 0x44e5a9: 83e203 AND EDX,0x3
    s.dx = integer::logical((s.dx)&(0x00000003u),32,flags);
  }
  L0044e5ac: { // 0x44e5ac: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L0044e5ae: { // 0x44e5ae: 0f85df000000 JNZ 0x0044e693
    if(integer::condition("JNZ",flags)) goto L0044e693;
  }
  L0044e5b4: { // 0x44e5b4: 8b442440 MOV EAX,dword ptr [ESP + 0x40]
    s.ax = m.r32((f.sp+0x00000040u));
  }
  L0044e5b8: { // 0x44e5b8: 897c243c MOV dword ptr [ESP + 0x3c],EDI
    m.w32((f.sp+0x0000003cu), s.di);
  }
  L0044e5bc: { // 0x44e5bc: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L0044e5be: { // 0x44e5be: 7508 JNZ 0x0044e5c8
    if(integer::condition("JNZ",flags)) goto L0044e5c8;
  }
  L0044e5c0: { // 0x44e5c0: 899fec040000 MOV dword ptr [EDI + 0x4ec],EBX
    m.w32((s.di+0x000004ecu), s.bx);
  }
  L0044e5c6: { // 0x44e5c6: eb0a JMP 0x0044e5d2
    goto L0044e5d2;
  }
  L0044e5c8: { // 0x44e5c8: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0044e5cc: { // 0x44e5cc: 8987ec040000 MOV dword ptr [EDI + 0x4ec],EAX
    m.w32((s.di+0x000004ecu), s.ax);
  }
  L0044e5d2: { // 0x44e5d2: 8a442413 MOV AL,byte ptr [ESP + 0x13]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000013u)));
  }
  L0044e5d6: { // 0x44e5d6: c6477501 MOV byte ptr [EDI + 0x75],0x1
    m.w8((s.di+0x00000075u), 0x00000001u);
  }
  L0044e5da: { // 0x44e5da: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044e5dc: { // 0x44e5dc: 7465 JZ 0x0044e643
    if(integer::condition("JZ",flags)) goto L0044e643;
  }
  L0044e5de: { // 0x44e5de: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0044e5e2: { // 0x44e5e2: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0044e5e3: { // 0x44e5e3: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0044e5e8: { // 0x44e5e8: e8136f0f00 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4515309u); flags=s.arithmetic_flags;
  }
  L0044e5ed: { // 0x44e5ed: 8bb0e4000000 MOV ESI,dword ptr [EAX + 0xe4]
    s.si = m.r32((s.ax+0x000000e4u));
  }
  L0044e5f3: { // 0x44e5f3: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0044e5f5: { // 0x44e5f5: 744c JZ 0x0044e643
    if(integer::condition("JZ",flags)) goto L0044e643;
  }
  L0044e5f7: { // 0x44e5f7: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0044e5f9: { // 0x44e5f9: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0044e5fb: { // 0x44e5fb: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),4515326u); flags=s.arithmetic_flags;
  }
  L0044e5fe: { // 0x44e5fe: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0044e600: { // 0x44e600: 7e3a JLE 0x0044e63c
    if(integer::condition("JLE",flags)) goto L0044e63c;
  }
  L0044e602: { // 0x44e602: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  L0044e605: { // 0x44e605: 7e05 JLE 0x0044e60c
    if(integer::condition("JLE",flags)) goto L0044e60c;
  }
  L0044e607: { // 0x44e607: 83f80f CMP EAX,0xf
    (void)integer::sub(s.ax,0x0000000fu,32,flags);
  }
  L0044e60a: { // 0x44e60a: 7530 JNZ 0x0044e63c
    if(integer::condition("JNZ",flags)) goto L0044e63c;
  }
  L0044e60c: { // 0x44e60c: 8b4e6c MOV ECX,dword ptr [ESI + 0x6c]
    s.cx = m.r32((s.si+0x0000006cu));
  }
  L0044e60f: { // 0x44e60f: 8b6e30 MOV EBP,dword ptr [ESI + 0x30]
    s.bp = m.r32((s.si+0x00000030u));
  }
  L0044e612: { // 0x44e612: 8d466c LEA EAX,[ESI + 0x6c]
    s.ax = (s.si+0x0000006cu);
  }
  L0044e615: { // 0x44e615: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0044e617: { // 0x44e617: 7e1f JLE 0x0044e638
    if(integer::condition("JLE",flags)) goto L0044e638;
  }
  L0044e619: { // 0x44e619: 8b0d881b8200 MOV ECX,dword ptr [0x00821b88]
    s.cx = m.r32((0x00821b88u));
  }
  L0044e61f: { // 0x44e61f: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0044e621: { // 0x44e621: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0044e623: { // 0x44e623: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0044e625: { // 0x44e625: 8b89740c0000 MOV ECX,dword ptr [ECX + 0xc74]
    s.cx = m.r32((s.cx+0x00000c74u));
  }
  L0044e62b: { // 0x44e62b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0044e62c: { // 0x44e62c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0044e62d: { // 0x44e62d: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0044e62f: { // 0x44e62f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0044e630: { // 0x44e630: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0044e632: { // 0x44e632: ff9258010000 CALL dword ptr [EDX + 0x158]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000158u)),4515384u); flags=s.arithmetic_flags;
  }
  L0044e638: { // 0x44e638: 8bf5 MOV ESI,EBP
    s.si = s.bp;
  }
  L0044e63a: { // 0x44e63a: eb03 JMP 0x0044e63f
    goto L0044e63f;
  }
  L0044e63c: { // 0x44e63c: 8b7630 MOV ESI,dword ptr [ESI + 0x30]
    s.si = m.r32((s.si+0x00000030u));
  }
  L0044e63f: { // 0x44e63f: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0044e641: { // 0x44e641: 75b4 JNZ 0x0044e5f7
    if(integer::condition("JNZ",flags)) goto L0044e5f7;
  }
  L0044e643: { // 0x44e643: 8b442448 MOV EAX,dword ptr [ESP + 0x48]
    s.ax = m.r32((f.sp+0x00000048u));
  }
  L0044e647: { // 0x44e647: 8b7c2424 MOV EDI,dword ptr [ESP + 0x24]
    s.di = m.r32((f.sp+0x00000024u));
  }
  L0044e64b: { // 0x44e64b: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0044e64c: { // 0x44e64c: 668b10 MOV DX,word ptr [EAX]
    s.dx = with_ax(s.dx, m.r16((s.ax)));
  }
  L0044e64f: { // 0x44e64f: 668b4002 MOV AX,word ptr [EAX + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.ax+0x00000002u)));
  }
  L0044e653: { // 0x44e653: 6603542418 ADD DX,word ptr [ESP + 0x18]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((f.sp+0x00000018u)),16,flags));
  }
  L0044e658: { // 0x44e658: 660344241a ADD AX,word ptr [ESP + 0x1a]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((f.sp+0x0000001au)),16,flags));
  }
  L0044e65d: { // 0x44e65d: 897c2424 MOV dword ptr [ESP + 0x24],EDI
    m.w32((f.sp+0x00000024u), s.di);
  }
  L0044e661: { // 0x44e661: 6689542438 MOV word ptr [ESP + 0x38],DX
    m.w16((f.sp+0x00000038u), (s.dx & 0xffffu));
  }
  L0044e666: { // 0x44e666: 668944243a MOV word ptr [ESP + 0x3a],AX
    m.w16((f.sp+0x0000003au), (s.ax & 0xffffu));
  }
  L0044e66b: { // 0x44e66b: 8b4c2438 MOV ECX,dword ptr [ESP + 0x38]
    s.cx = m.r32((f.sp+0x00000038u));
  }
  L0044e66f: { // 0x44e66f: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L0044e673: { // 0x44e673: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0044e677: { // 0x44e677: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0044e678: { // 0x44e678: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0044e67d: { // 0x44e67d: e87e6e0f00 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4515458u); flags=s.arithmetic_flags;
  }
  L0044e682: { // 0x44e682: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0044e684: { // 0x44e684: e8272d0200 CALL 0x004713b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004713b0u,4515465u); flags=s.arithmetic_flags;
  }
  L0044e689: { // 0x44e689: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0044e68b: { // 0x44e68b: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0044e68d: { // 0x44e68d: 0f85bcfeffff JNZ 0x0044e54f
    if(integer::condition("JNZ",flags)) goto L0044e54f;
  }
  L0044e693: { // 0x44e693: 8a442413 MOV AL,byte ptr [ESP + 0x13]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000013u)));
  }
  L0044e697: { // 0x44e697: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044e699: { // 0x44e699: 743b JZ 0x0044e6d6
    if(integer::condition("JZ",flags)) goto L0044e6d6;
  }
  L0044e69b: { // 0x44e69b: 8b44243c MOV EAX,dword ptr [ESP + 0x3c]
    s.ax = m.r32((f.sp+0x0000003cu));
  }
  L0044e69f: { // 0x44e69f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0044e6a1: { // 0x44e6a1: 7433 JZ 0x0044e6d6
    if(integer::condition("JZ",flags)) goto L0044e6d6;
  }
  L0044e6a3: { // 0x44e6a3: 39442440 CMP dword ptr [ESP + 0x40],EAX
    (void)integer::sub(m.r32((f.sp+0x00000040u)),s.ax,32,flags);
  }
  L0044e6a7: { // 0x44e6a7: 751f JNZ 0x0044e6c8
    if(integer::condition("JNZ",flags)) goto L0044e6c8;
  }
  L0044e6a9: { // 0x44e6a9: 837c242802 CMP dword ptr [ESP + 0x28],0x2
    (void)integer::sub(m.r32((f.sp+0x00000028u)),0x00000002u,32,flags);
  }
  L0044e6ae: { // 0x44e6ae: 750c JNZ 0x0044e6bc
    if(integer::condition("JNZ",flags)) goto L0044e6bc;
  }
  L0044e6b0: { // 0x44e6b0: c780ec04000003000000 MOV dword ptr [EAX + 0x4ec],0x3
    m.w32((s.ax+0x000004ecu), 0x00000003u);
  }
  L0044e6ba: { // 0x44e6ba: eb16 JMP 0x0044e6d2
    goto L0044e6d2;
  }
  L0044e6bc: { // 0x44e6bc: c780ec04000007000000 MOV dword ptr [EAX + 0x4ec],0x7
    m.w32((s.ax+0x000004ecu), 0x00000007u);
  }
  L0044e6c6: { // 0x44e6c6: eb0a JMP 0x0044e6d2
    goto L0044e6d2;
  }
  L0044e6c8: { // 0x44e6c8: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0044e6cc: { // 0x44e6cc: 8988ec040000 MOV dword ptr [EAX + 0x4ec],ECX
    m.w32((s.ax+0x000004ecu), s.cx);
  }
  L0044e6d2: { // 0x44e6d2: c6407501 MOV byte ptr [EAX + 0x75],0x1
    m.w8((s.ax+0x00000075u), 0x00000001u);
  }
  L0044e6d6: { // 0x44e6d6: 8b5c242c MOV EBX,dword ptr [ESP + 0x2c]
    s.bx = m.r32((f.sp+0x0000002cu));
  }
  L0044e6da: { // 0x44e6da: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L0044e6de: { // 0x44e6de: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    s.ax = m.r32((f.sp+0x00000044u));
  }
  L0044e6e2: { // 0x44e6e2: 83c202 ADD EDX,0x2
    s.dx = integer::add(s.dx,0x00000002u,32,flags);
  }
  L0044e6e5: { // 0x44e6e5: 83e207 AND EDX,0x7
    s.dx = integer::logical((s.dx)&(0x00000007u),32,flags);
  }
  L0044e6e8: { // 0x44e6e8: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0044e6e9: { // 0x44e6e9: 89542420 MOV dword ptr [ESP + 0x20],EDX
    m.w32((f.sp+0x00000020u), s.dx);
  }
  L0044e6ed: { // 0x44e6ed: 89442444 MOV dword ptr [ESP + 0x44],EAX
    m.w32((f.sp+0x00000044u), s.ax);
  }
  L0044e6f1: { // 0x44e6f1: 0f853afcffff JNZ 0x0044e331
    if(integer::condition("JNZ",flags)) goto L0044e331;
  }
  L0044e6f7: { // 0x44e6f7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0044e6f8: { // 0x44e6f8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0044e6f9: { // 0x44e6f9: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0044e6fa: { // 0x44e6fa: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0044e6fb: { // 0x44e6fb: 83c450 ADD ESP,0x50
    f.sp = integer::add(f.sp,0x00000050u,32,flags);
  }
  L0044e6fe: { // 0x44e6fe: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
