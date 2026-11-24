#include "recovered/recovery_b788_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b788 {
namespace {
void f_0002ad30(Memory&,State&,Frame&,const Operations&);
void f_0002add0(Memory&,State&,Frame&,const Operations&);
void f_0007b1e0(Memory&,State&,Frame&,const Operations&);
void f_00147f40(Memory&,State&,Frame&,const Operations&);
void f_0016a990(Memory&,State&,Frame&,const Operations&);
void f_00158b60(Memory&,State&,Frame&,const Operations&);
void f_00157340(Memory&,State&,Frame&,const Operations&);
void f_00157280(Memory&,State&,Frame&,const Operations&);
void f_000766c0(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_0007b190(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_0002ad30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0042ad30: { // 0x42ad30: 668b542408 MOV DX,word ptr [ESP + 0x8]
    s.dx = with_ax(s.dx, m.r16((f.sp+0x00000008u)));
  }
  L0042ad35: { // 0x42ad35: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0042ad37: { // 0x42ad37: 668b4c2404 MOV CX,word ptr [ESP + 0x4]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000004u)));
  }
  L0042ad3c: { // 0x42ad3c: 668908 MOV word ptr [EAX],CX
    m.w16((s.ax), (s.cx & 0xffffu));
  }
  L0042ad3f: { // 0x42ad3f: 66895002 MOV word ptr [EAX + 0x2],DX
    m.w16((s.ax+0x00000002u), (s.dx & 0xffffu));
  }
  L0042ad43: { // 0x42ad43: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_0002add0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0042add0: { // 0x42add0: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L0042add4: { // 0x42add4: 668b10 MOV DX,word ptr [EAX]
    s.dx = with_ax(s.dx, m.r16((s.ax)));
  }
  L0042add7: { // 0x42add7: 668b4002 MOV AX,word ptr [EAX + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.ax+0x00000002u)));
  }
  L0042addb: { // 0x42addb: 66034102 ADD AX,word ptr [ECX + 0x2]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((s.cx+0x00000002u)),16,flags));
  }
  L0042addf: { // 0x42addf: 660311 ADD DX,word ptr [ECX]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((s.cx)),16,flags));
  }
  L0042ade2: { // 0x42ade2: 668944240a MOV word ptr [ESP + 0xa],AX
    m.w16((f.sp+0x0000000au), (s.ax & 0xffffu));
  }
  L0042ade7: { // 0x42ade7: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L0042adeb: { // 0x42adeb: 6689542408 MOV word ptr [ESP + 0x8],DX
    m.w16((f.sp+0x00000008u), (s.dx & 0xffffu));
  }
  L0042adf0: { // 0x42adf0: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  L0042adf4: { // 0x42adf4: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L0042adf6: { // 0x42adf6: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_0007b1e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0047b1e0: { // 0x47b1e0: 8b15a8aaa300 MOV EDX,dword ptr [0x00a3aaa8]
    s.dx = m.r32((0x00a3aaa8u));
  }
  L0047b1e6: { // 0x47b1e6: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0047b1e7: { // 0x47b1e7: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  L0047b1ea: { // 0x47b1ea: 7412 JZ 0x0047b1fe
    if(integer::condition("JZ",flags)) goto L0047b1fe;
  }
  L0047b1ec: { // 0x47b1ec: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  L0047b1ef: { // 0x47b1ef: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047b1f1: { // 0x47b1f1: 7c0b JL 0x0047b1fe
    if(integer::condition("JL",flags)) goto L0047b1fe;
  }
  L0047b1f3: { // 0x47b1f3: 83c228 ADD EDX,0x28
    s.dx = integer::add(s.dx,0x00000028u,32,flags);
  }
  L0047b1f6: { // 0x47b1f6: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047b1f8: { // 0x47b1f8: 7d04 JGE 0x0047b1fe
    if(integer::condition("JGE",flags)) goto L0047b1fe;
  }
  L0047b1fa: { // 0x47b1fa: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047b1fc: { // 0x47b1fc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047b1fd: { // 0x47b1fd: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b1fe: { // 0x47b1fe: 8b15bca1a300 MOV EDX,dword ptr [0x00a3a1bc]
    s.dx = m.r32((0x00a3a1bcu));
  }
  L0047b204: { // 0x47b204: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  L0047b207: { // 0x47b207: 7438 JZ 0x0047b241
    if(integer::condition("JZ",flags)) goto L0047b241;
  }
  L0047b209: { // 0x47b209: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  L0047b20c: { // 0x47b20c: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047b20e: { // 0x47b20e: 7c31 JL 0x0047b241
    if(integer::condition("JL",flags)) goto L0047b241;
  }
  L0047b210: { // 0x47b210: 8d7204 LEA ESI,[EDX + 0x4]
    s.si = (s.dx+0x00000004u);
  }
  L0047b213: { // 0x47b213: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L0047b215: { // 0x47b215: 7d2a JGE 0x0047b241
    if(integer::condition("JGE",flags)) goto L0047b241;
  }
  L0047b217: { // 0x47b217: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047b219: { // 0x47b219: 740b JZ 0x0047b226
    if(integer::condition("JZ",flags)) goto L0047b226;
  }
  L0047b21b: { // 0x47b21b: 83c203 ADD EDX,0x3
    s.dx = integer::add(s.dx,0x00000003u,32,flags);
  }
  L0047b21e: { // 0x47b21e: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047b220: { // 0x47b220: 0f858f010000 JNZ 0x0047b3b5
    if(integer::condition("JNZ",flags)) goto L0047b3b5;
  }
  L0047b226: { // 0x47b226: 8a891a010000 MOV CL,byte ptr [ECX + 0x11a]
    s.cx = with_al(s.cx, m.r8((s.cx+0x0000011au)));
  }
  L0047b22c: { // 0x47b22c: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0047b22e: { // 0x47b22e: 0f8485010000 JZ 0x0047b3b9
    if(integer::condition("JZ",flags)) goto L0047b3b9;
  }
  L0047b234: { // 0x47b234: 80f904 CMP CL,0x4
    (void)integer::sub((s.cx & 0xffu),0x00000004u,8,flags);
  }
  L0047b237: { // 0x47b237: 0f847c010000 JZ 0x0047b3b9
    if(integer::condition("JZ",flags)) goto L0047b3b9;
  }
  L0047b23d: { // 0x47b23d: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047b23f: { // 0x47b23f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047b240: { // 0x47b240: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b241: { // 0x47b241: 8b15904ba500 MOV EDX,dword ptr [0x00a54b90]
    s.dx = m.r32((0x00a54b90u));
  }
  L0047b247: { // 0x47b247: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  L0047b24a: { // 0x47b24a: 7439 JZ 0x0047b285
    if(integer::condition("JZ",flags)) goto L0047b285;
  }
  L0047b24c: { // 0x47b24c: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  L0047b24f: { // 0x47b24f: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047b251: { // 0x47b251: 7c32 JL 0x0047b285
    if(integer::condition("JL",flags)) goto L0047b285;
  }
  L0047b253: { // 0x47b253: 8d7204 LEA ESI,[EDX + 0x4]
    s.si = (s.dx+0x00000004u);
  }
  L0047b256: { // 0x47b256: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L0047b258: { // 0x47b258: 7d2b JGE 0x0047b285
    if(integer::condition("JGE",flags)) goto L0047b285;
  }
  L0047b25a: { // 0x47b25a: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047b25c: { // 0x47b25c: 740b JZ 0x0047b269
    if(integer::condition("JZ",flags)) goto L0047b269;
  }
  L0047b25e: { // 0x47b25e: 83c203 ADD EDX,0x3
    s.dx = integer::add(s.dx,0x00000003u,32,flags);
  }
  L0047b261: { // 0x47b261: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047b263: { // 0x47b263: 0f854c010000 JNZ 0x0047b3b5
    if(integer::condition("JNZ",flags)) goto L0047b3b5;
  }
  L0047b269: { // 0x47b269: 8a891a010000 MOV CL,byte ptr [ECX + 0x11a]
    s.cx = with_al(s.cx, m.r8((s.cx+0x0000011au)));
  }
  L0047b26f: { // 0x47b26f: 80f901 CMP CL,0x1
    (void)integer::sub((s.cx & 0xffu),0x00000001u,8,flags);
  }
  L0047b272: { // 0x47b272: 0f8441010000 JZ 0x0047b3b9
    if(integer::condition("JZ",flags)) goto L0047b3b9;
  }
  L0047b278: { // 0x47b278: 80f903 CMP CL,0x3
    (void)integer::sub((s.cx & 0xffu),0x00000003u,8,flags);
  }
  L0047b27b: { // 0x47b27b: 0f8438010000 JZ 0x0047b3b9
    if(integer::condition("JZ",flags)) goto L0047b3b9;
  }
  L0047b281: { // 0x47b281: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047b283: { // 0x47b283: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047b284: { // 0x47b284: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b285: { // 0x47b285: 8b15d8aaa300 MOV EDX,dword ptr [0x00a3aad8]
    s.dx = m.r32((0x00a3aad8u));
  }
  L0047b28b: { // 0x47b28b: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  L0047b28e: { // 0x47b28e: 7438 JZ 0x0047b2c8
    if(integer::condition("JZ",flags)) goto L0047b2c8;
  }
  L0047b290: { // 0x47b290: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  L0047b293: { // 0x47b293: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047b295: { // 0x47b295: 7c31 JL 0x0047b2c8
    if(integer::condition("JL",flags)) goto L0047b2c8;
  }
  L0047b297: { // 0x47b297: 8d7204 LEA ESI,[EDX + 0x4]
    s.si = (s.dx+0x00000004u);
  }
  L0047b29a: { // 0x47b29a: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L0047b29c: { // 0x47b29c: 7d2a JGE 0x0047b2c8
    if(integer::condition("JGE",flags)) goto L0047b2c8;
  }
  L0047b29e: { // 0x47b29e: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047b2a0: { // 0x47b2a0: 740b JZ 0x0047b2ad
    if(integer::condition("JZ",flags)) goto L0047b2ad;
  }
  L0047b2a2: { // 0x47b2a2: 83c203 ADD EDX,0x3
    s.dx = integer::add(s.dx,0x00000003u,32,flags);
  }
  L0047b2a5: { // 0x47b2a5: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047b2a7: { // 0x47b2a7: 0f8508010000 JNZ 0x0047b3b5
    if(integer::condition("JNZ",flags)) goto L0047b3b5;
  }
  L0047b2ad: { // 0x47b2ad: 8a891a010000 MOV CL,byte ptr [ECX + 0x11a]
    s.cx = with_al(s.cx, m.r8((s.cx+0x0000011au)));
  }
  L0047b2b3: { // 0x47b2b3: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0047b2b5: { // 0x47b2b5: 0f84fe000000 JZ 0x0047b3b9
    if(integer::condition("JZ",flags)) goto L0047b3b9;
  }
  L0047b2bb: { // 0x47b2bb: 80f901 CMP CL,0x1
    (void)integer::sub((s.cx & 0xffu),0x00000001u,8,flags);
  }
  L0047b2be: { // 0x47b2be: 0f84f5000000 JZ 0x0047b3b9
    if(integer::condition("JZ",flags)) goto L0047b3b9;
  }
  L0047b2c4: { // 0x47b2c4: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047b2c6: { // 0x47b2c6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047b2c7: { // 0x47b2c7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b2c8: { // 0x47b2c8: 8b1528aba300 MOV EDX,dword ptr [0x00a3ab28]
    s.dx = m.r32((0x00a3ab28u));
  }
  L0047b2ce: { // 0x47b2ce: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  L0047b2d1: { // 0x47b2d1: 7439 JZ 0x0047b30c
    if(integer::condition("JZ",flags)) goto L0047b30c;
  }
  L0047b2d3: { // 0x47b2d3: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  L0047b2d6: { // 0x47b2d6: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047b2d8: { // 0x47b2d8: 7c32 JL 0x0047b30c
    if(integer::condition("JL",flags)) goto L0047b30c;
  }
  L0047b2da: { // 0x47b2da: 8d7204 LEA ESI,[EDX + 0x4]
    s.si = (s.dx+0x00000004u);
  }
  L0047b2dd: { // 0x47b2dd: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L0047b2df: { // 0x47b2df: 7d2b JGE 0x0047b30c
    if(integer::condition("JGE",flags)) goto L0047b30c;
  }
  L0047b2e1: { // 0x47b2e1: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047b2e3: { // 0x47b2e3: 740b JZ 0x0047b2f0
    if(integer::condition("JZ",flags)) goto L0047b2f0;
  }
  L0047b2e5: { // 0x47b2e5: 83c203 ADD EDX,0x3
    s.dx = integer::add(s.dx,0x00000003u,32,flags);
  }
  L0047b2e8: { // 0x47b2e8: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047b2ea: { // 0x47b2ea: 0f85c5000000 JNZ 0x0047b3b5
    if(integer::condition("JNZ",flags)) goto L0047b3b5;
  }
  L0047b2f0: { // 0x47b2f0: 8a891a010000 MOV CL,byte ptr [ECX + 0x11a]
    s.cx = with_al(s.cx, m.r8((s.cx+0x0000011au)));
  }
  L0047b2f6: { // 0x47b2f6: 80f902 CMP CL,0x2
    (void)integer::sub((s.cx & 0xffu),0x00000002u,8,flags);
  }
  L0047b2f9: { // 0x47b2f9: 0f84ba000000 JZ 0x0047b3b9
    if(integer::condition("JZ",flags)) goto L0047b3b9;
  }
  L0047b2ff: { // 0x47b2ff: 80f903 CMP CL,0x3
    (void)integer::sub((s.cx & 0xffu),0x00000003u,8,flags);
  }
  L0047b302: { // 0x47b302: 0f84b1000000 JZ 0x0047b3b9
    if(integer::condition("JZ",flags)) goto L0047b3b9;
  }
  L0047b308: { // 0x47b308: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047b30a: { // 0x47b30a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047b30b: { // 0x47b30b: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b30c: { // 0x47b30c: 8b153859a500 MOV EDX,dword ptr [0x00a55938]
    s.dx = m.r32((0x00a55938u));
  }
  L0047b312: { // 0x47b312: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  L0047b315: { // 0x47b315: 7412 JZ 0x0047b329
    if(integer::condition("JZ",flags)) goto L0047b329;
  }
  L0047b317: { // 0x47b317: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  L0047b31a: { // 0x47b31a: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047b31c: { // 0x47b31c: 7c0b JL 0x0047b329
    if(integer::condition("JL",flags)) goto L0047b329;
  }
  L0047b31e: { // 0x47b31e: 83c214 ADD EDX,0x14
    s.dx = integer::add(s.dx,0x00000014u,32,flags);
  }
  L0047b321: { // 0x47b321: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047b323: { // 0x47b323: 7d04 JGE 0x0047b329
    if(integer::condition("JGE",flags)) goto L0047b329;
  }
  L0047b325: { // 0x47b325: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047b327: { // 0x47b327: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047b328: { // 0x47b328: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b329: { // 0x47b329: 8b15a847a500 MOV EDX,dword ptr [0x00a547a8]
    s.dx = m.r32((0x00a547a8u));
  }
  L0047b32f: { // 0x47b32f: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  L0047b332: { // 0x47b332: 7412 JZ 0x0047b346
    if(integer::condition("JZ",flags)) goto L0047b346;
  }
  L0047b334: { // 0x47b334: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  L0047b337: { // 0x47b337: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047b339: { // 0x47b339: 7c0b JL 0x0047b346
    if(integer::condition("JL",flags)) goto L0047b346;
  }
  L0047b33b: { // 0x47b33b: 83c204 ADD EDX,0x4
    s.dx = integer::add(s.dx,0x00000004u,32,flags);
  }
  L0047b33e: { // 0x47b33e: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047b340: { // 0x47b340: 7d04 JGE 0x0047b346
    if(integer::condition("JGE",flags)) goto L0047b346;
  }
  L0047b342: { // 0x47b342: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047b344: { // 0x47b344: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047b345: { // 0x47b345: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b346: { // 0x47b346: 8b15b0a8a300 MOV EDX,dword ptr [0x00a3a8b0]
    s.dx = m.r32((0x00a3a8b0u));
  }
  L0047b34c: { // 0x47b34c: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  L0047b34f: { // 0x47b34f: 7412 JZ 0x0047b363
    if(integer::condition("JZ",flags)) goto L0047b363;
  }
  L0047b351: { // 0x47b351: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  L0047b354: { // 0x47b354: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047b356: { // 0x47b356: 7c0b JL 0x0047b363
    if(integer::condition("JL",flags)) goto L0047b363;
  }
  L0047b358: { // 0x47b358: 83c210 ADD EDX,0x10
    s.dx = integer::add(s.dx,0x00000010u,32,flags);
  }
  L0047b35b: { // 0x47b35b: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047b35d: { // 0x47b35d: 7d04 JGE 0x0047b363
    if(integer::condition("JGE",flags)) goto L0047b363;
  }
  L0047b35f: { // 0x47b35f: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047b361: { // 0x47b361: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047b362: { // 0x47b362: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b363: { // 0x47b363: 8b15a047a500 MOV EDX,dword ptr [0x00a547a0]
    s.dx = m.r32((0x00a547a0u));
  }
  L0047b369: { // 0x47b369: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  L0047b36c: { // 0x47b36c: 7412 JZ 0x0047b380
    if(integer::condition("JZ",flags)) goto L0047b380;
  }
  L0047b36e: { // 0x47b36e: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  L0047b371: { // 0x47b371: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047b373: { // 0x47b373: 7c0b JL 0x0047b380
    if(integer::condition("JL",flags)) goto L0047b380;
  }
  L0047b375: { // 0x47b375: 83c210 ADD EDX,0x10
    s.dx = integer::add(s.dx,0x00000010u,32,flags);
  }
  L0047b378: { // 0x47b378: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047b37a: { // 0x47b37a: 7d04 JGE 0x0047b380
    if(integer::condition("JGE",flags)) goto L0047b380;
  }
  L0047b37c: { // 0x47b37c: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047b37e: { // 0x47b37e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047b37f: { // 0x47b37f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b380: { // 0x47b380: 8b15305da500 MOV EDX,dword ptr [0x00a55d30]
    s.dx = m.r32((0x00a55d30u));
  }
  L0047b386: { // 0x47b386: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  L0047b389: { // 0x47b389: 7412 JZ 0x0047b39d
    if(integer::condition("JZ",flags)) goto L0047b39d;
  }
  L0047b38b: { // 0x47b38b: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  L0047b38e: { // 0x47b38e: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047b390: { // 0x47b390: 7c0b JL 0x0047b39d
    if(integer::condition("JL",flags)) goto L0047b39d;
  }
  L0047b392: { // 0x47b392: 83c202 ADD EDX,0x2
    s.dx = integer::add(s.dx,0x00000002u,32,flags);
  }
  L0047b395: { // 0x47b395: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047b397: { // 0x47b397: 7d04 JGE 0x0047b39d
    if(integer::condition("JGE",flags)) goto L0047b39d;
  }
  L0047b399: { // 0x47b399: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047b39b: { // 0x47b39b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047b39c: { // 0x47b39c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b39d: { // 0x47b39d: a1a4aaa300 MOV EAX,[0x00a3aaa4]
    s.ax = m.r32((0x00a3aaa4u));
  }
  L0047b3a2: { // 0x47b3a2: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L0047b3a5: { // 0x47b3a5: 7412 JZ 0x0047b3b9
    if(integer::condition("JZ",flags)) goto L0047b3b9;
  }
  L0047b3a7: { // 0x47b3a7: 8b4938 MOV ECX,dword ptr [ECX + 0x38]
    s.cx = m.r32((s.cx+0x00000038u));
  }
  L0047b3aa: { // 0x47b3aa: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L0047b3ac: { // 0x47b3ac: 7c0b JL 0x0047b3b9
    if(integer::condition("JL",flags)) goto L0047b3b9;
  }
  L0047b3ae: { // 0x47b3ae: 83c01c ADD EAX,0x1c
    s.ax = integer::add(s.ax,0x0000001cu,32,flags);
  }
  L0047b3b1: { // 0x47b3b1: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L0047b3b3: { // 0x47b3b3: 7d04 JGE 0x0047b3b9
    if(integer::condition("JGE",flags)) goto L0047b3b9;
  }
  L0047b3b5: { // 0x47b3b5: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047b3b7: { // 0x47b3b7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047b3b8: { // 0x47b3b8: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b3b9: { // 0x47b3b9: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0047b3bb: { // 0x47b3bb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047b3bc: { // 0x47b3bc: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00147f40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00547f40: { // 0x547f40: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L00547f44: { // 0x547f44: 8b91f0000000 MOV EDX,dword ptr [ECX + 0xf0]
    s.dx = m.r32((s.cx+0x000000f0u));
  }
  L00547f4a: { // 0x547f4a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00547f4b: { // 0x547f4b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00547f4c: { // 0x547f4c: 0fbf30 MOVSX ESI,word ptr [EAX]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.ax)),16));
  }
  L00547f4f: { // 0x547f4f: 0fbf4002 MOVSX EAX,word ptr [EAX + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000002u)),16));
  }
  L00547f53: { // 0x547f53: 8d3c30 LEA EDI,[EAX + ESI*0x1]
    s.di = (s.ax+(s.si * 0x00000001u));
  }
  L00547f56: { // 0x547f56: 3bfa CMP EDI,EDX
    (void)integer::sub(s.di,s.dx,32,flags);
  }
  L00547f58: { // 0x547f58: 7e24 JLE 0x00547f7e
    if(integer::condition("JLE",flags)) goto L00547f7e;
  }
  L00547f5a: { // 0x547f5a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00547f5b: { // 0x547f5b: 8bde MOV EBX,ESI
    s.bx = s.si;
  }
  L00547f5d: { // 0x547f5d: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00547f5f: { // 0x547f5f: 3bda CMP EBX,EDX
    (void)integer::sub(s.bx,s.dx,32,flags);
  }
  L00547f61: { // 0x547f61: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00547f62: { // 0x547f62: 7d1a JGE 0x00547f7e
    if(integer::condition("JGE",flags)) goto L00547f7e;
  }
  L00547f64: { // 0x547f64: 2bc6 SUB EAX,ESI
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L00547f66: { // 0x547f66: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00547f68: { // 0x547f68: 7d14 JGE 0x00547f7e
    if(integer::condition("JGE",flags)) goto L00547f7e;
  }
  L00547f6a: { // 0x547f6a: 8b81f4000000 MOV EAX,dword ptr [ECX + 0xf4]
    s.ax = m.r32((s.cx+0x000000f4u));
  }
  L00547f70: { // 0x547f70: 8d0c42 LEA ECX,[EDX + EAX*0x2]
    s.cx = (s.dx+(s.ax * 0x00000002u));
  }
  L00547f73: { // 0x547f73: 3bf9 CMP EDI,ECX
    (void)integer::sub(s.di,s.cx,32,flags);
  }
  L00547f75: { // 0x547f75: 7f07 JG 0x00547f7e
    if(integer::condition("JG",flags)) goto L00547f7e;
  }
  L00547f77: { // 0x547f77: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00547f78: { // 0x547f78: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00547f7a: { // 0x547f7a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00547f7b: { // 0x547f7b: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00547f7e: { // 0x547f7e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00547f7f: { // 0x547f7f: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00547f81: { // 0x547f81: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00547f82: { // 0x547f82: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0016a990(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0056a990: { // 0x56a990: 0fbf4102 MOVSX EAX,word ptr [ECX + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000002u)),16));
  }
  L0056a994: { // 0x56a994: 0faf054c6b8300 IMUL EAX,dword ptr [0x00836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  L0056a99b: { // 0x56a99b: 0fbf09 MOVSX ECX,word ptr [ECX]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.cx)),16));
  }
  L0056a99e: { // 0x56a99e: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0056a9a0: { // 0x56a9a0: 8b0d3c86a500 MOV ECX,dword ptr [0x00a5863c]
    s.cx = m.r32((0x00a5863cu));
  }
  L0056a9a6: { // 0x56a9a6: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0056a9a9: { // 0x56a9a9: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L0056a9ac: { // 0x56a9ac: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0056a9ae: { // 0x56a9ae: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00158b60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00558b60: { // 0x558b60: 83ec30 SUB ESP,0x30
    f.sp = integer::sub(f.sp,0x00000030u,32,flags);
  }
  L00558b63: { // 0x558b63: 8b442434 MOV EAX,dword ptr [ESP + 0x34]
    s.ax = m.r32((f.sp+0x00000034u));
  }
  L00558b67: { // 0x558b67: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00558b68: { // 0x558b68: 8b3510a98100 MOV ESI,dword ptr [0x0081a910]
    s.si = m.r32((0x0081a910u));
  }
  L00558b6e: { // 0x558b6e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00558b6f: { // 0x558b6f: 0fbe881b010000 MOVSX ECX,byte ptr [EAX + 0x11b]
    s.cx = std::uint32_t(integer::sign_extend(m.r8((s.ax+0x0000011bu)),8));
  }
  L00558b76: { // 0x558b76: 8b4024 MOV EAX,dword ptr [EAX + 0x24]
    s.ax = m.r32((s.ax+0x00000024u));
  }
  L00558b79: { // 0x558b79: 894c240c MOV dword ptr [ESP + 0xc],ECX
    m.w32((f.sp+0x0000000cu), s.cx);
  }
  L00558b7d: { // 0x558b7d: 8944243c MOV dword ptr [ESP + 0x3c],EAX
    m.w32((f.sp+0x0000003cu), s.ax);
  }
  L00558b81: { // 0x558b81: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L00558b85: { // 0x558b85: 0fbfc8 MOVSX ECX,AX
    s.cx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00558b88: { // 0x558b88: 0fbf44243e MOVSX EAX,word ptr [ESP + 0x3e]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x0000003eu)),16));
  }
  L00558b8d: { // 0x558b8d: c744240800000000 MOV dword ptr [ESP + 0x8],0x0
    m.w32((f.sp+0x00000008u), 0x00000000u);
  }
  L00558b95: { // 0x558b95: 8d1408 LEA EDX,[EAX + ECX*0x1]
    s.dx = (s.ax+(s.cx * 0x00000001u));
  }
  L00558b98: { // 0x558b98: 3bd6 CMP EDX,ESI
    (void)integer::sub(s.dx,s.si,32,flags);
  }
  L00558b9a: { // 0x558b9a: 0f8eff040000 JLE 0x0055909f
    if(integer::condition("JLE",flags)) goto L0055909f;
  }
  L00558ba0: { // 0x558ba0: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L00558ba2: { // 0x558ba2: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L00558ba4: { // 0x558ba4: 3bfe CMP EDI,ESI
    (void)integer::sub(s.di,s.si,32,flags);
  }
  L00558ba6: { // 0x558ba6: 0f8df3040000 JGE 0x0055909f
    if(integer::condition("JGE",flags)) goto L0055909f;
  }
  L00558bac: { // 0x558bac: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00558bae: { // 0x558bae: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L00558bb0: { // 0x558bb0: 0f8de9040000 JGE 0x0055909f
    if(integer::condition("JGE",flags)) goto L0055909f;
  }
  L00558bb6: { // 0x558bb6: a114a98100 MOV EAX,[0x0081a914]
    s.ax = m.r32((0x0081a914u));
  }
  L00558bbb: { // 0x558bbb: 8d0c46 LEA ECX,[ESI + EAX*0x2]
    s.cx = (s.si+(s.ax * 0x00000002u));
  }
  L00558bbe: { // 0x558bbe: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L00558bc0: { // 0x558bc0: 0f8fd9040000 JG 0x0055909f
    if(integer::condition("JG",flags)) goto L0055909f;
  }
  L00558bc6: { // 0x558bc6: 8d4c2430 LEA ECX,[ESP + 0x30]
    s.cx = (f.sp+0x00000030u);
  }
  L00558bca: { // 0x558bca: e8c11d0100 CALL 0x0056a990
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056a990u,5606351u); flags=s.arithmetic_flags;
  }
  L00558bcf: { // 0x558bcf: 8a484a MOV CL,byte ptr [EAX + 0x4a]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0000004au)));
  }
  L00558bd2: { // 0x558bd2: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00558bd4: { // 0x558bd4: 0f84c5040000 JZ 0x0055909f
    if(integer::condition("JZ",flags)) goto L0055909f;
  }
  L00558bda: { // 0x558bda: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00558bdb: { // 0x558bdb: 8b5c2434 MOV EBX,dword ptr [ESP + 0x34]
    s.bx = m.r32((f.sp+0x00000034u));
  }
  L00558bdf: { // 0x558bdf: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00558be0: { // 0x558be0: 8b6c243a MOV EBP,dword ptr [ESP + 0x3a]
    s.bp = m.r32((f.sp+0x0000003au));
  }
  L00558be4: { // 0x558be4: 8b3d58a98100 MOV EDI,dword ptr [0x0081a958]
    s.di = m.r32((0x0081a958u));
  }
  L00558bea: { // 0x558bea: 8d4b01 LEA ECX,[EBX + 0x1]
    s.cx = (s.bx+0x00000001u);
  }
  L00558bed: { // 0x558bed: 8d45ff LEA EAX,[EBP + -0x1]
    s.ax = (s.bp-0x00000001u);
  }
  L00558bf0: { // 0x558bf0: 66894c2444 MOV word ptr [ESP + 0x44],CX
    m.w16((f.sp+0x00000044u), (s.cx & 0xffffu));
  }
  L00558bf5: { // 0x558bf5: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L00558bf9: { // 0x558bf9: 6689442446 MOV word ptr [ESP + 0x46],AX
    m.w16((f.sp+0x00000046u), (s.ax & 0xffffu));
  }
  L00558bfe: { // 0x558bfe: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00558c01: { // 0x558c01: 0fbfd1 MOVSX EDX,CX
    s.dx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L00558c04: { // 0x558c04: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L00558c07: { // 0x558c07: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00558c09: { // 0x558c09: 7814 JS 0x00558c1f
    if(integer::condition("JS",flags)) goto L00558c1f;
  }
  L00558c0b: { // 0x558c0b: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00558c10: { // 0x558c10: 7d0d JGE 0x00558c1f
    if(integer::condition("JGE",flags)) goto L00558c1f;
  }
  L00558c12: { // 0x558c12: 8b0487 MOV EAX,dword ptr [EDI + EAX*0x4]
    s.ax = m.r32((s.di+(s.ax * 0x00000004u)));
  }
  L00558c15: { // 0x558c15: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00558c17: { // 0x558c17: 7406 JZ 0x00558c1f
    if(integer::condition("JZ",flags)) goto L00558c1f;
  }
  L00558c19: { // 0x558c19: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00558c1d: { // 0x558c1d: eb11 JMP 0x00558c30
    goto L00558c30;
  }
  L00558c1f: { // 0x558c1f: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    s.ax = m.r32((f.sp+0x00000044u));
  }
  L00558c23: { // 0x558c23: c74424181076a500 MOV dword ptr [ESP + 0x18],0xa57610
    m.w32((f.sp+0x00000018u), 0x00a57610u);
  }
  L00558c2b: { // 0x558c2b: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L00558c30: { // 0x558c30: 0fbff5 MOVSX ESI,BP
    s.si = std::uint32_t(integer::sign_extend((s.bp & 0xffffu),16));
  }
  L00558c33: { // 0x558c33: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00558c35: { // 0x558c35: 66894c2444 MOV word ptr [ESP + 0x44],CX
    m.w16((f.sp+0x00000044u), (s.cx & 0xffffu));
  }
  L00558c3a: { // 0x558c3a: 0fbfd1 MOVSX EDX,CX
    s.dx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L00558c3d: { // 0x558c3d: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L00558c40: { // 0x558c40: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00558c42: { // 0x558c42: 66896c2446 MOV word ptr [ESP + 0x46],BP
    m.w16((f.sp+0x00000046u), (s.bp & 0xffffu));
  }
  L00558c47: { // 0x558c47: 7814 JS 0x00558c5d
    if(integer::condition("JS",flags)) goto L00558c5d;
  }
  L00558c49: { // 0x558c49: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00558c4e: { // 0x558c4e: 7d0d JGE 0x00558c5d
    if(integer::condition("JGE",flags)) goto L00558c5d;
  }
  L00558c50: { // 0x558c50: 8b0487 MOV EAX,dword ptr [EDI + EAX*0x4]
    s.ax = m.r32((s.di+(s.ax * 0x00000004u)));
  }
  L00558c53: { // 0x558c53: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00558c55: { // 0x558c55: 7406 JZ 0x00558c5d
    if(integer::condition("JZ",flags)) goto L00558c5d;
  }
  L00558c57: { // 0x558c57: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L00558c5b: { // 0x558c5b: eb11 JMP 0x00558c6e
    goto L00558c6e;
  }
  L00558c5d: { // 0x558c5d: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    s.ax = m.r32((f.sp+0x00000044u));
  }
  L00558c61: { // 0x558c61: c74424201076a500 MOV dword ptr [ESP + 0x20],0xa57610
    m.w32((f.sp+0x00000020u), 0x00a57610u);
  }
  L00558c69: { // 0x558c69: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L00558c6e: { // 0x558c6e: 8d5501 LEA EDX,[EBP + 0x1]
    s.dx = (s.bp+0x00000001u);
  }
  L00558c71: { // 0x558c71: 66894c2444 MOV word ptr [ESP + 0x44],CX
    m.w16((f.sp+0x00000044u), (s.cx & 0xffffu));
  }
  L00558c76: { // 0x558c76: 668bc2 MOV AX,DX
    s.ax = with_ax(s.ax, (s.dx & 0xffffu));
  }
  L00558c79: { // 0x558c79: 6689442446 MOV word ptr [ESP + 0x46],AX
    m.w16((f.sp+0x00000046u), (s.ax & 0xffffu));
  }
  L00558c7e: { // 0x558c7e: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00558c81: { // 0x558c81: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L00558c84: { // 0x558c84: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L00558c87: { // 0x558c87: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00558c89: { // 0x558c89: 7814 JS 0x00558c9f
    if(integer::condition("JS",flags)) goto L00558c9f;
  }
  L00558c8b: { // 0x558c8b: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00558c90: { // 0x558c90: 7d0d JGE 0x00558c9f
    if(integer::condition("JGE",flags)) goto L00558c9f;
  }
  L00558c92: { // 0x558c92: 8b0487 MOV EAX,dword ptr [EDI + EAX*0x4]
    s.ax = m.r32((s.di+(s.ax * 0x00000004u)));
  }
  L00558c95: { // 0x558c95: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00558c97: { // 0x558c97: 7406 JZ 0x00558c9f
    if(integer::condition("JZ",flags)) goto L00558c9f;
  }
  L00558c99: { // 0x558c99: 8944242c MOV dword ptr [ESP + 0x2c],EAX
    m.w32((f.sp+0x0000002cu), s.ax);
  }
  L00558c9d: { // 0x558c9d: eb11 JMP 0x00558cb0
    goto L00558cb0;
  }
  L00558c9f: { // 0x558c9f: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    s.ax = m.r32((f.sp+0x00000044u));
  }
  L00558ca3: { // 0x558ca3: c744242c1076a500 MOV dword ptr [ESP + 0x2c],0xa57610
    m.w32((f.sp+0x0000002cu), 0x00a57610u);
  }
  L00558cab: { // 0x558cab: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L00558cb0: { // 0x558cb0: 668bc2 MOV AX,DX
    s.ax = with_ax(s.ax, (s.dx & 0xffffu));
  }
  L00558cb3: { // 0x558cb3: 66895c2444 MOV word ptr [ESP + 0x44],BX
    m.w16((f.sp+0x00000044u), (s.bx & 0xffffu));
  }
  L00558cb8: { // 0x558cb8: 6689442446 MOV word ptr [ESP + 0x46],AX
    m.w16((f.sp+0x00000046u), (s.ax & 0xffffu));
  }
  L00558cbd: { // 0x558cbd: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00558cc0: { // 0x558cc0: 0fbfcb MOVSX ECX,BX
    s.cx = std::uint32_t(integer::sign_extend((s.bx & 0xffffu),16));
  }
  L00558cc3: { // 0x558cc3: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L00558cc6: { // 0x558cc6: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00558cc8: { // 0x558cc8: 894c2434 MOV dword ptr [ESP + 0x34],ECX
    m.w32((f.sp+0x00000034u), s.cx);
  }
  L00558ccc: { // 0x558ccc: 7814 JS 0x00558ce2
    if(integer::condition("JS",flags)) goto L00558ce2;
  }
  L00558cce: { // 0x558cce: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00558cd3: { // 0x558cd3: 7d0d JGE 0x00558ce2
    if(integer::condition("JGE",flags)) goto L00558ce2;
  }
  L00558cd5: { // 0x558cd5: 8b0487 MOV EAX,dword ptr [EDI + EAX*0x4]
    s.ax = m.r32((s.di+(s.ax * 0x00000004u)));
  }
  L00558cd8: { // 0x558cd8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00558cda: { // 0x558cda: 7406 JZ 0x00558ce2
    if(integer::condition("JZ",flags)) goto L00558ce2;
  }
  L00558cdc: { // 0x558cdc: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L00558ce0: { // 0x558ce0: eb12 JMP 0x00558cf4
    goto L00558cf4;
  }
  L00558ce2: { // 0x558ce2: 8b4c2444 MOV ECX,dword ptr [ESP + 0x44]
    s.cx = m.r32((f.sp+0x00000044u));
  }
  L00558ce6: { // 0x558ce6: c74424281076a500 MOV dword ptr [ESP + 0x28],0xa57610
    m.w32((f.sp+0x00000028u), 0x00a57610u);
  }
  L00558cee: { // 0x558cee: 890d3476a500 MOV dword ptr [0x00a57634],ECX
    m.w32((0x00a57634u), s.cx);
  }
  L00558cf4: { // 0x558cf4: 8d4bff LEA ECX,[EBX + -0x1]
    s.cx = (s.bx-0x00000001u);
  }
  L00558cf7: { // 0x558cf7: 6689542446 MOV word ptr [ESP + 0x46],DX
    m.w16((f.sp+0x00000046u), (s.dx & 0xffffu));
  }
  L00558cfc: { // 0x558cfc: 0fbfc2 MOVSX EAX,DX
    s.ax = std::uint32_t(integer::sign_extend((s.dx & 0xffffu),16));
  }
  L00558cff: { // 0x558cff: 0fbfd1 MOVSX EDX,CX
    s.dx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L00558d02: { // 0x558d02: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L00558d05: { // 0x558d05: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00558d07: { // 0x558d07: 66894c2444 MOV word ptr [ESP + 0x44],CX
    m.w16((f.sp+0x00000044u), (s.cx & 0xffffu));
  }
  L00558d0c: { // 0x558d0c: 7814 JS 0x00558d22
    if(integer::condition("JS",flags)) goto L00558d22;
  }
  L00558d0e: { // 0x558d0e: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00558d13: { // 0x558d13: 7d0d JGE 0x00558d22
    if(integer::condition("JGE",flags)) goto L00558d22;
  }
  L00558d15: { // 0x558d15: 8b0487 MOV EAX,dword ptr [EDI + EAX*0x4]
    s.ax = m.r32((s.di+(s.ax * 0x00000004u)));
  }
  L00558d18: { // 0x558d18: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00558d1a: { // 0x558d1a: 7406 JZ 0x00558d22
    if(integer::condition("JZ",flags)) goto L00558d22;
  }
  L00558d1c: { // 0x558d1c: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L00558d20: { // 0x558d20: eb11 JMP 0x00558d33
    goto L00558d33;
  }
  L00558d22: { // 0x558d22: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    s.ax = m.r32((f.sp+0x00000044u));
  }
  L00558d26: { // 0x558d26: c74424241076a500 MOV dword ptr [ESP + 0x24],0xa57610
    m.w32((f.sp+0x00000024u), 0x00a57610u);
  }
  L00558d2e: { // 0x558d2e: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L00558d33: { // 0x558d33: 668bc1 MOV AX,CX
    s.ax = with_ax(s.ax, (s.cx & 0xffffu));
  }
  L00558d36: { // 0x558d36: 66896c2446 MOV word ptr [ESP + 0x46],BP
    m.w16((f.sp+0x00000046u), (s.bp & 0xffffu));
  }
  L00558d3b: { // 0x558d3b: 0fbfd0 MOVSX EDX,AX
    s.dx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00558d3e: { // 0x558d3e: c1e609 SHL ESI,0x9
    s.si = integer::shift(s.si,0x00000009u,32,flags,integer::Shift::left);
  }
  L00558d41: { // 0x558d41: 03f2 ADD ESI,EDX
    s.si = integer::add(s.si,s.dx,32,flags);
  }
  L00558d43: { // 0x558d43: 6689442444 MOV word ptr [ESP + 0x44],AX
    m.w16((f.sp+0x00000044u), (s.ax & 0xffffu));
  }
  L00558d48: { // 0x558d48: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00558d4a: { // 0x558d4a: 7814 JS 0x00558d60
    if(integer::condition("JS",flags)) goto L00558d60;
  }
  L00558d4c: { // 0x558d4c: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00558d51: { // 0x558d51: 7d0d JGE 0x00558d60
    if(integer::condition("JGE",flags)) goto L00558d60;
  }
  L00558d53: { // 0x558d53: 8b0487 MOV EAX,dword ptr [EDI + EAX*0x4]
    s.ax = m.r32((s.di+(s.ax * 0x00000004u)));
  }
  L00558d56: { // 0x558d56: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00558d58: { // 0x558d58: 7406 JZ 0x00558d60
    if(integer::condition("JZ",flags)) goto L00558d60;
  }
  L00558d5a: { // 0x558d5a: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L00558d5e: { // 0x558d5e: eb11 JMP 0x00558d71
    goto L00558d71;
  }
  L00558d60: { // 0x558d60: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    s.ax = m.r32((f.sp+0x00000044u));
  }
  L00558d64: { // 0x558d64: c744241c1076a500 MOV dword ptr [ESP + 0x1c],0xa57610
    m.w32((f.sp+0x0000001cu), 0x00a57610u);
  }
  L00558d6c: { // 0x558d6c: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L00558d71: { // 0x558d71: 8b742430 MOV ESI,dword ptr [ESP + 0x30]
    s.si = m.r32((f.sp+0x00000030u));
  }
  L00558d75: { // 0x558d75: 66894c2444 MOV word ptr [ESP + 0x44],CX
    m.w16((f.sp+0x00000044u), (s.cx & 0xffffu));
  }
  L00558d7a: { // 0x558d7a: 668bc6 MOV AX,SI
    s.ax = with_ax(s.ax, (s.si & 0xffffu));
  }
  L00558d7d: { // 0x558d7d: 6689442446 MOV word ptr [ESP + 0x46],AX
    m.w16((f.sp+0x00000046u), (s.ax & 0xffffu));
  }
  L00558d82: { // 0x558d82: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00558d85: { // 0x558d85: 0fbfd1 MOVSX EDX,CX
    s.dx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L00558d88: { // 0x558d88: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L00558d8b: { // 0x558d8b: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00558d8d: { // 0x558d8d: 7812 JS 0x00558da1
    if(integer::condition("JS",flags)) goto L00558da1;
  }
  L00558d8f: { // 0x558d8f: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00558d94: { // 0x558d94: 7d0b JGE 0x00558da1
    if(integer::condition("JGE",flags)) goto L00558da1;
  }
  L00558d96: { // 0x558d96: 8b0487 MOV EAX,dword ptr [EDI + EAX*0x4]
    s.ax = m.r32((s.di+(s.ax * 0x00000004u)));
  }
  L00558d99: { // 0x558d99: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00558d9b: { // 0x558d9b: 7404 JZ 0x00558da1
    if(integer::condition("JZ",flags)) goto L00558da1;
  }
  L00558d9d: { // 0x558d9d: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L00558d9f: { // 0x558d9f: eb0e JMP 0x00558daf
    goto L00558daf;
  }
  L00558da1: { // 0x558da1: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    s.ax = m.r32((f.sp+0x00000044u));
  }
  L00558da5: { // 0x558da5: bd1076a500 MOV EBP,0xa57610
    s.bp = 0x00a57610u;
  }
  L00558daa: { // 0x558daa: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L00558daf: { // 0x558daf: 8b542434 MOV EDX,dword ptr [ESP + 0x34]
    s.dx = m.r32((f.sp+0x00000034u));
  }
  L00558db3: { // 0x558db3: 668bc6 MOV AX,SI
    s.ax = with_ax(s.ax, (s.si & 0xffffu));
  }
  L00558db6: { // 0x558db6: 6689442446 MOV word ptr [ESP + 0x46],AX
    m.w16((f.sp+0x00000046u), (s.ax & 0xffffu));
  }
  L00558dbb: { // 0x558dbb: 66895c2444 MOV word ptr [ESP + 0x44],BX
    m.w16((f.sp+0x00000044u), (s.bx & 0xffffu));
  }
  L00558dc0: { // 0x558dc0: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00558dc3: { // 0x558dc3: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L00558dc6: { // 0x558dc6: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00558dc8: { // 0x558dc8: 7812 JS 0x00558ddc
    if(integer::condition("JS",flags)) goto L00558ddc;
  }
  L00558dca: { // 0x558dca: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00558dcf: { // 0x558dcf: 7d0b JGE 0x00558ddc
    if(integer::condition("JGE",flags)) goto L00558ddc;
  }
  L00558dd1: { // 0x558dd1: 8b0487 MOV EAX,dword ptr [EDI + EAX*0x4]
    s.ax = m.r32((s.di+(s.ax * 0x00000004u)));
  }
  L00558dd4: { // 0x558dd4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00558dd6: { // 0x558dd6: 7404 JZ 0x00558ddc
    if(integer::condition("JZ",flags)) goto L00558ddc;
  }
  L00558dd8: { // 0x558dd8: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00558dda: { // 0x558dda: eb0f JMP 0x00558deb
    goto L00558deb;
  }
  L00558ddc: { // 0x558ddc: 8b542444 MOV EDX,dword ptr [ESP + 0x44]
    s.dx = m.r32((f.sp+0x00000044u));
  }
  L00558de0: { // 0x558de0: bb1076a500 MOV EBX,0xa57610
    s.bx = 0x00a57610u;
  }
  L00558de5: { // 0x558de5: 89153476a500 MOV dword ptr [0x00a57634],EDX
    m.w32((0x00a57634u), s.dx);
  }
  L00558deb: { // 0x558deb: 0fbfd1 MOVSX EDX,CX
    s.dx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L00558dee: { // 0x558dee: 0fbfc6 MOVSX EAX,SI
    s.ax = std::uint32_t(integer::sign_extend((s.si & 0xffffu),16));
  }
  L00558df1: { // 0x558df1: 8b3510a98100 MOV ESI,dword ptr [0x0081a910]
    s.si = m.r32((0x0081a910u));
  }
  L00558df7: { // 0x558df7: 8d3c02 LEA EDI,[EDX + EAX*0x1]
    s.di = (s.dx+(s.ax * 0x00000001u));
  }
  L00558dfa: { // 0x558dfa: 3bfe CMP EDI,ESI
    (void)integer::sub(s.di,s.si,32,flags);
  }
  L00558dfc: { // 0x558dfc: 7e45 JLE 0x00558e43
    if(integer::condition("JLE",flags)) goto L00558e43;
  }
  L00558dfe: { // 0x558dfe: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L00558e00: { // 0x558e00: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00558e02: { // 0x558e02: 3bce CMP ECX,ESI
    (void)integer::sub(s.cx,s.si,32,flags);
  }
  L00558e04: { // 0x558e04: 7d3d JGE 0x00558e43
    if(integer::condition("JGE",flags)) goto L00558e43;
  }
  L00558e06: { // 0x558e06: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00558e08: { // 0x558e08: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L00558e0a: { // 0x558e0a: 7d37 JGE 0x00558e43
    if(integer::condition("JGE",flags)) goto L00558e43;
  }
  L00558e0c: { // 0x558e0c: 8b1514a98100 MOV EDX,dword ptr [0x0081a914]
    s.dx = m.r32((0x0081a914u));
  }
  L00558e12: { // 0x558e12: 8d0456 LEA EAX,[ESI + EDX*0x2]
    s.ax = (s.si+(s.dx * 0x00000002u));
  }
  L00558e15: { // 0x558e15: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L00558e17: { // 0x558e17: 7f2a JG 0x00558e43
    if(integer::condition("JG",flags)) goto L00558e43;
  }
  L00558e19: { // 0x558e19: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L00558e1d: { // 0x558e1d: 0fbe8d1b010000 MOVSX ECX,byte ptr [EBP + 0x11b]
    s.cx = std::uint32_t(integer::sign_extend(m.r8((s.bp+0x0000011bu)),8));
  }
  L00558e24: { // 0x558e24: 8d5704 LEA EDX,[EDI + 0x4]
    s.dx = (s.di+0x00000004u);
  }
  L00558e27: { // 0x558e27: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L00558e29: { // 0x558e29: 7512 JNZ 0x00558e3d
    if(integer::condition("JNZ",flags)) goto L00558e3d;
  }
  L00558e2b: { // 0x558e2b: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00558e2d: { // 0x558e2d: e8ae23f2ff CALL 0x0047b1e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b1e0u,5606962u); flags=s.arithmetic_flags;
  }
  L00558e32: { // 0x558e32: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00558e34: { // 0x558e34: 7507 JNZ 0x00558e3d
    if(integer::condition("JNZ",flags)) goto L00558e3d;
  }
  L00558e36: { // 0x558e36: bd40000000 MOV EBP,0x40
    s.bp = 0x00000040u;
  }
  L00558e3b: { // 0x558e3b: eb0e JMP 0x00558e4b
    goto L00558e4b;
  }
  L00558e3d: { // 0x558e3d: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L00558e41: { // 0x558e41: eb08 JMP 0x00558e4b
    goto L00558e4b;
  }
  L00558e43: { // 0x558e43: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L00558e47: { // 0x558e47: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L00558e4b: { // 0x558e4b: 8b4c243a MOV ECX,dword ptr [ESP + 0x3a]
    s.cx = m.r32((f.sp+0x0000003au));
  }
  L00558e4f: { // 0x558e4f: 668b442438 MOV AX,word ptr [ESP + 0x38]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x00000038u)));
  }
  L00558e54: { // 0x558e54: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00558e55: { // 0x558e55: 6689442444 MOV word ptr [ESP + 0x44],AX
    m.w16((f.sp+0x00000044u), (s.ax & 0xffffu));
  }
  L00558e5a: { // 0x558e5a: 66894c2446 MOV word ptr [ESP + 0x46],CX
    m.w16((f.sp+0x00000046u), (s.cx & 0xffffu));
  }
  L00558e5f: { // 0x558e5f: 8b542444 MOV EDX,dword ptr [ESP + 0x44]
    s.dx = m.r32((f.sp+0x00000044u));
  }
  L00558e63: { // 0x558e63: 8d442444 LEA EAX,[ESP + 0x44]
    s.ax = (f.sp+0x00000044u);
  }
  L00558e67: { // 0x558e67: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00558e6c: { // 0x558e6c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00558e6d: { // 0x558e6d: 89542448 MOV dword ptr [ESP + 0x48],EDX
    m.w32((f.sp+0x00000048u), s.dx);
  }
  L00558e71: { // 0x558e71: e8caf0feff CALL 0x00547f40
    s.arithmetic_flags=flags; invoke(m,s,f,0x00547f40u,5607030u); flags=s.arithmetic_flags;
  }
  L00558e76: { // 0x558e76: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00558e78: { // 0x558e78: 741f JZ 0x00558e99
    if(integer::condition("JZ",flags)) goto L00558e99;
  }
  L00558e7a: { // 0x558e7a: 0fbe8b1b010000 MOVSX ECX,byte ptr [EBX + 0x11b]
    s.cx = std::uint32_t(integer::sign_extend(m.r8((s.bx+0x0000011bu)),8));
  }
  L00558e81: { // 0x558e81: 8d5704 LEA EDX,[EDI + 0x4]
    s.dx = (s.di+0x00000004u);
  }
  L00558e84: { // 0x558e84: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L00558e86: { // 0x558e86: 7511 JNZ 0x00558e99
    if(integer::condition("JNZ",flags)) goto L00558e99;
  }
  L00558e88: { // 0x558e88: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00558e8a: { // 0x558e8a: e85123f2ff CALL 0x0047b1e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b1e0u,5607055u); flags=s.arithmetic_flags;
  }
  L00558e8f: { // 0x558e8f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00558e91: { // 0x558e91: 7506 JNZ 0x00558e99
    if(integer::condition("JNZ",flags)) goto L00558e99;
  }
  L00558e93: { // 0x558e93: 81cd80000000 OR EBP,0x80
    s.bp = integer::logical((s.bp)|(0x00000080u),32,flags);
  }
  L00558e99: { // 0x558e99: 8d442444 LEA EAX,[ESP + 0x44]
    s.ax = (f.sp+0x00000044u);
  }
  L00558e9d: { // 0x558e9d: 8d4c2430 LEA ECX,[ESP + 0x30]
    s.cx = (f.sp+0x00000030u);
  }
  L00558ea1: { // 0x558ea1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00558ea2: { // 0x558ea2: 83ceff OR ESI,0xffffffff
    s.si = integer::logical((s.si)|(0xffffffffu),32,flags);
  }
  L00558ea5: { // 0x558ea5: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00558ea6: { // 0x558ea6: 8d4c2440 LEA ECX,[ESP + 0x40]
    s.cx = (f.sp+0x00000040u);
  }
  L00558eaa: { // 0x558eaa: 66c744244c0100 MOV word ptr [ESP + 0x4c],0x1
    m.w16((f.sp+0x0000004cu), 0x00000001u);
  }
  L00558eb1: { // 0x558eb1: 668974244e MOV word ptr [ESP + 0x4e],SI
    m.w16((f.sp+0x0000004eu), (s.si & 0xffffu));
  }
  L00558eb6: { // 0x558eb6: e8151fedff CALL 0x0042add0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042add0u,5607099u); flags=s.arithmetic_flags;
  }
  L00558ebb: { // 0x558ebb: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00558ebd: { // 0x558ebd: 8d442434 LEA EAX,[ESP + 0x34]
    s.ax = (f.sp+0x00000034u);
  }
  L00558ec1: { // 0x558ec1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00558ec2: { // 0x558ec2: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00558ec7: { // 0x558ec7: 89542438 MOV dword ptr [ESP + 0x38],EDX
    m.w32((f.sp+0x00000038u), s.dx);
  }
  L00558ecb: { // 0x558ecb: e870f0feff CALL 0x00547f40
    s.arithmetic_flags=flags; invoke(m,s,f,0x00547f40u,5607120u); flags=s.arithmetic_flags;
  }
  L00558ed0: { // 0x558ed0: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00558ed2: { // 0x558ed2: 741e JZ 0x00558ef2
    if(integer::condition("JZ",flags)) goto L00558ef2;
  }
  L00558ed4: { // 0x558ed4: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L00558ed8: { // 0x558ed8: 8d4704 LEA EAX,[EDI + 0x4]
    s.ax = (s.di+0x00000004u);
  }
  L00558edb: { // 0x558edb: 0fbe911b010000 MOVSX EDX,byte ptr [ECX + 0x11b]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.cx+0x0000011bu)),8));
  }
  L00558ee2: { // 0x558ee2: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L00558ee4: { // 0x558ee4: 750c JNZ 0x00558ef2
    if(integer::condition("JNZ",flags)) goto L00558ef2;
  }
  L00558ee6: { // 0x558ee6: e8f522f2ff CALL 0x0047b1e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b1e0u,5607147u); flags=s.arithmetic_flags;
  }
  L00558eeb: { // 0x558eeb: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00558eed: { // 0x558eed: 7503 JNZ 0x00558ef2
    if(integer::condition("JNZ",flags)) goto L00558ef2;
  }
  L00558eef: { // 0x558eef: 83cd01 OR EBP,0x1
    s.bp = integer::logical((s.bp)|(0x00000001u),32,flags);
  }
  L00558ef2: { // 0x558ef2: 8d4c2444 LEA ECX,[ESP + 0x44]
    s.cx = (f.sp+0x00000044u);
  }
  L00558ef6: { // 0x558ef6: 8d542430 LEA EDX,[ESP + 0x30]
    s.dx = (f.sp+0x00000030u);
  }
  L00558efa: { // 0x558efa: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00558efb: { // 0x558efb: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00558efc: { // 0x558efc: 8d4c2440 LEA ECX,[ESP + 0x40]
    s.cx = (f.sp+0x00000040u);
  }
  L00558f00: { // 0x558f00: 668974244c MOV word ptr [ESP + 0x4c],SI
    m.w16((f.sp+0x0000004cu), (s.si & 0xffffu));
  }
  L00558f05: { // 0x558f05: 66c744244e0000 MOV word ptr [ESP + 0x4e],0x0
    m.w16((f.sp+0x0000004eu), 0x00000000u);
  }
  L00558f0c: { // 0x558f0c: e8bf1eedff CALL 0x0042add0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042add0u,5607185u); flags=s.arithmetic_flags;
  }
  L00558f11: { // 0x558f11: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L00558f13: { // 0x558f13: 8d4c2434 LEA ECX,[ESP + 0x34]
    s.cx = (f.sp+0x00000034u);
  }
  L00558f17: { // 0x558f17: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00558f18: { // 0x558f18: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00558f1d: { // 0x558f1d: 89442438 MOV dword ptr [ESP + 0x38],EAX
    m.w32((f.sp+0x00000038u), s.ax);
  }
  L00558f21: { // 0x558f21: e81af0feff CALL 0x00547f40
    s.arithmetic_flags=flags; invoke(m,s,f,0x00547f40u,5607206u); flags=s.arithmetic_flags;
  }
  L00558f26: { // 0x558f26: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00558f28: { // 0x558f28: 741e JZ 0x00558f48
    if(integer::condition("JZ",flags)) goto L00558f48;
  }
  L00558f2a: { // 0x558f2a: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L00558f2e: { // 0x558f2e: 8d4704 LEA EAX,[EDI + 0x4]
    s.ax = (s.di+0x00000004u);
  }
  L00558f31: { // 0x558f31: 0fbe911b010000 MOVSX EDX,byte ptr [ECX + 0x11b]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.cx+0x0000011bu)),8));
  }
  L00558f38: { // 0x558f38: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L00558f3a: { // 0x558f3a: 750c JNZ 0x00558f48
    if(integer::condition("JNZ",flags)) goto L00558f48;
  }
  L00558f3c: { // 0x558f3c: e89f22f2ff CALL 0x0047b1e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b1e0u,5607233u); flags=s.arithmetic_flags;
  }
  L00558f41: { // 0x558f41: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00558f43: { // 0x558f43: 7503 JNZ 0x00558f48
    if(integer::condition("JNZ",flags)) goto L00558f48;
  }
  L00558f45: { // 0x558f45: 83cd20 OR EBP,0x20
    s.bp = integer::logical((s.bp)|(0x00000020u),32,flags);
  }
  L00558f48: { // 0x558f48: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00558f4a: { // 0x558f4a: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00558f4c: { // 0x558f4c: 8d4c243c LEA ECX,[ESP + 0x3c]
    s.cx = (f.sp+0x0000003cu);
  }
  L00558f50: { // 0x558f50: e8db1dedff CALL 0x0042ad30
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042ad30u,5607253u); flags=s.arithmetic_flags;
  }
  L00558f55: { // 0x558f55: 8d4c2430 LEA ECX,[ESP + 0x30]
    s.cx = (f.sp+0x00000030u);
  }
  L00558f59: { // 0x558f59: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00558f5a: { // 0x558f5a: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00558f5b: { // 0x558f5b: 8d4c2440 LEA ECX,[ESP + 0x40]
    s.cx = (f.sp+0x00000040u);
  }
  L00558f5f: { // 0x558f5f: e86c1eedff CALL 0x0042add0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042add0u,5607268u); flags=s.arithmetic_flags;
  }
  L00558f64: { // 0x558f64: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00558f66: { // 0x558f66: 8d442444 LEA EAX,[ESP + 0x44]
    s.ax = (f.sp+0x00000044u);
  }
  L00558f6a: { // 0x558f6a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00558f6b: { // 0x558f6b: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00558f70: { // 0x558f70: 89542448 MOV dword ptr [ESP + 0x48],EDX
    m.w32((f.sp+0x00000048u), s.dx);
  }
  L00558f74: { // 0x558f74: e8c7effeff CALL 0x00547f40
    s.arithmetic_flags=flags; invoke(m,s,f,0x00547f40u,5607289u); flags=s.arithmetic_flags;
  }
  L00558f79: { // 0x558f79: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00558f7b: { // 0x558f7b: 741e JZ 0x00558f9b
    if(integer::condition("JZ",flags)) goto L00558f9b;
  }
  L00558f7d: { // 0x558f7d: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L00558f81: { // 0x558f81: 8d4704 LEA EAX,[EDI + 0x4]
    s.ax = (s.di+0x00000004u);
  }
  L00558f84: { // 0x558f84: 0fbe911b010000 MOVSX EDX,byte ptr [ECX + 0x11b]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.cx+0x0000011bu)),8));
  }
  L00558f8b: { // 0x558f8b: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L00558f8d: { // 0x558f8d: 750c JNZ 0x00558f9b
    if(integer::condition("JNZ",flags)) goto L00558f9b;
  }
  L00558f8f: { // 0x558f8f: e84c22f2ff CALL 0x0047b1e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b1e0u,5607316u); flags=s.arithmetic_flags;
  }
  L00558f94: { // 0x558f94: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00558f96: { // 0x558f96: 7503 JNZ 0x00558f9b
    if(integer::condition("JNZ",flags)) goto L00558f9b;
  }
  L00558f98: { // 0x558f98: 83cd02 OR EBP,0x2
    s.bp = integer::logical((s.bp)|(0x00000002u),32,flags);
  }
  L00558f9b: { // 0x558f9b: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00558f9d: { // 0x558f9d: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00558f9e: { // 0x558f9e: 8d4c243c LEA ECX,[ESP + 0x3c]
    s.cx = (f.sp+0x0000003cu);
  }
  L00558fa2: { // 0x558fa2: e8891dedff CALL 0x0042ad30
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042ad30u,5607335u); flags=s.arithmetic_flags;
  }
  L00558fa7: { // 0x558fa7: 8d4c2430 LEA ECX,[ESP + 0x30]
    s.cx = (f.sp+0x00000030u);
  }
  L00558fab: { // 0x558fab: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00558fac: { // 0x558fac: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00558fad: { // 0x558fad: 8d4c2440 LEA ECX,[ESP + 0x40]
    s.cx = (f.sp+0x00000040u);
  }
  L00558fb1: { // 0x558fb1: e81a1eedff CALL 0x0042add0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042add0u,5607350u); flags=s.arithmetic_flags;
  }
  L00558fb6: { // 0x558fb6: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00558fb8: { // 0x558fb8: 8d442444 LEA EAX,[ESP + 0x44]
    s.ax = (f.sp+0x00000044u);
  }
  L00558fbc: { // 0x558fbc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00558fbd: { // 0x558fbd: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00558fc2: { // 0x558fc2: 89542448 MOV dword ptr [ESP + 0x48],EDX
    m.w32((f.sp+0x00000048u), s.dx);
  }
  L00558fc6: { // 0x558fc6: e875effeff CALL 0x00547f40
    s.arithmetic_flags=flags; invoke(m,s,f,0x00547f40u,5607371u); flags=s.arithmetic_flags;
  }
  L00558fcb: { // 0x558fcb: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00558fcd: { // 0x558fcd: 741e JZ 0x00558fed
    if(integer::condition("JZ",flags)) goto L00558fed;
  }
  L00558fcf: { // 0x558fcf: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L00558fd3: { // 0x558fd3: 8d4704 LEA EAX,[EDI + 0x4]
    s.ax = (s.di+0x00000004u);
  }
  L00558fd6: { // 0x558fd6: 0fbe911b010000 MOVSX EDX,byte ptr [ECX + 0x11b]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.cx+0x0000011bu)),8));
  }
  L00558fdd: { // 0x558fdd: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L00558fdf: { // 0x558fdf: 750c JNZ 0x00558fed
    if(integer::condition("JNZ",flags)) goto L00558fed;
  }
  L00558fe1: { // 0x558fe1: e8fa21f2ff CALL 0x0047b1e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b1e0u,5607398u); flags=s.arithmetic_flags;
  }
  L00558fe6: { // 0x558fe6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00558fe8: { // 0x558fe8: 7503 JNZ 0x00558fed
    if(integer::condition("JNZ",flags)) goto L00558fed;
  }
  L00558fea: { // 0x558fea: 83cd10 OR EBP,0x10
    s.bp = integer::logical((s.bp)|(0x00000010u),32,flags);
  }
  L00558fed: { // 0x558fed: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00558fef: { // 0x558fef: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00558ff1: { // 0x558ff1: 8d4c243c LEA ECX,[ESP + 0x3c]
    s.cx = (f.sp+0x0000003cu);
  }
  L00558ff5: { // 0x558ff5: e8361dedff CALL 0x0042ad30
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042ad30u,5607418u); flags=s.arithmetic_flags;
  }
  L00558ffa: { // 0x558ffa: 8d4c2430 LEA ECX,[ESP + 0x30]
    s.cx = (f.sp+0x00000030u);
  }
  L00558ffe: { // 0x558ffe: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00558fff: { // 0x558fff: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00559000: { // 0x559000: 8d4c2440 LEA ECX,[ESP + 0x40]
    s.cx = (f.sp+0x00000040u);
  }
  L00559004: { // 0x559004: e8c71dedff CALL 0x0042add0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042add0u,5607433u); flags=s.arithmetic_flags;
  }
  L00559009: { // 0x559009: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0055900b: { // 0x55900b: 8d442444 LEA EAX,[ESP + 0x44]
    s.ax = (f.sp+0x00000044u);
  }
  L0055900f: { // 0x55900f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00559010: { // 0x559010: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00559015: { // 0x559015: 89542448 MOV dword ptr [ESP + 0x48],EDX
    m.w32((f.sp+0x00000048u), s.dx);
  }
  L00559019: { // 0x559019: e822effeff CALL 0x00547f40
    s.arithmetic_flags=flags; invoke(m,s,f,0x00547f40u,5607454u); flags=s.arithmetic_flags;
  }
  L0055901e: { // 0x55901e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00559020: { // 0x559020: 741e JZ 0x00559040
    if(integer::condition("JZ",flags)) goto L00559040;
  }
  L00559022: { // 0x559022: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L00559026: { // 0x559026: 8d4704 LEA EAX,[EDI + 0x4]
    s.ax = (s.di+0x00000004u);
  }
  L00559029: { // 0x559029: 0fbe911b010000 MOVSX EDX,byte ptr [ECX + 0x11b]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.cx+0x0000011bu)),8));
  }
  L00559030: { // 0x559030: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L00559032: { // 0x559032: 750c JNZ 0x00559040
    if(integer::condition("JNZ",flags)) goto L00559040;
  }
  L00559034: { // 0x559034: e8a721f2ff CALL 0x0047b1e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b1e0u,5607481u); flags=s.arithmetic_flags;
  }
  L00559039: { // 0x559039: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0055903b: { // 0x55903b: 7503 JNZ 0x00559040
    if(integer::condition("JNZ",flags)) goto L00559040;
  }
  L0055903d: { // 0x55903d: 83cd08 OR EBP,0x8
    s.bp = integer::logical((s.bp)|(0x00000008u),32,flags);
  }
  L00559040: { // 0x559040: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00559042: { // 0x559042: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00559044: { // 0x559044: 8d4c243c LEA ECX,[ESP + 0x3c]
    s.cx = (f.sp+0x0000003cu);
  }
  L00559048: { // 0x559048: e8e31cedff CALL 0x0042ad30
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042ad30u,5607501u); flags=s.arithmetic_flags;
  }
  L0055904d: { // 0x55904d: 8d4c2430 LEA ECX,[ESP + 0x30]
    s.cx = (f.sp+0x00000030u);
  }
  L00559051: { // 0x559051: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00559052: { // 0x559052: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00559053: { // 0x559053: 8d4c2440 LEA ECX,[ESP + 0x40]
    s.cx = (f.sp+0x00000040u);
  }
  L00559057: { // 0x559057: e8741dedff CALL 0x0042add0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042add0u,5607516u); flags=s.arithmetic_flags;
  }
  L0055905c: { // 0x55905c: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0055905e: { // 0x55905e: 8d442444 LEA EAX,[ESP + 0x44]
    s.ax = (f.sp+0x00000044u);
  }
  L00559062: { // 0x559062: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00559063: { // 0x559063: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00559068: { // 0x559068: 89542448 MOV dword ptr [ESP + 0x48],EDX
    m.w32((f.sp+0x00000048u), s.dx);
  }
  L0055906c: { // 0x55906c: e8cfeefeff CALL 0x00547f40
    s.arithmetic_flags=flags; invoke(m,s,f,0x00547f40u,5607537u); flags=s.arithmetic_flags;
  }
  L00559071: { // 0x559071: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00559073: { // 0x559073: 741e JZ 0x00559093
    if(integer::condition("JZ",flags)) goto L00559093;
  }
  L00559075: { // 0x559075: 8b4c242c MOV ECX,dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L00559079: { // 0x559079: 83c704 ADD EDI,0x4
    s.di = integer::add(s.di,0x00000004u,32,flags);
  }
  L0055907c: { // 0x55907c: 0fbe911b010000 MOVSX EDX,byte ptr [ECX + 0x11b]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.cx+0x0000011bu)),8));
  }
  L00559083: { // 0x559083: 3bd7 CMP EDX,EDI
    (void)integer::sub(s.dx,s.di,32,flags);
  }
  L00559085: { // 0x559085: 750c JNZ 0x00559093
    if(integer::condition("JNZ",flags)) goto L00559093;
  }
  L00559087: { // 0x559087: e85421f2ff CALL 0x0047b1e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b1e0u,5607564u); flags=s.arithmetic_flags;
  }
  L0055908c: { // 0x55908c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0055908e: { // 0x55908e: 7503 JNZ 0x00559093
    if(integer::condition("JNZ",flags)) goto L00559093;
  }
  L00559090: { // 0x559090: 83cd04 OR EBP,0x4
    s.bp = integer::logical((s.bp)|(0x00000004u),32,flags);
  }
  L00559093: { // 0x559093: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L00559095: { // 0x559095: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00559096: { // 0x559096: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00559097: { // 0x559097: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00559098: { // 0x559098: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00559099: { // 0x559099: 83c430 ADD ESP,0x30
    f.sp = integer::add(f.sp,0x00000030u,32,flags);
  }
  L0055909c: { // 0x55909c: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0055909f: { // 0x55909f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005590a0: { // 0x5590a0: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005590a2: { // 0x5590a2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005590a3: { // 0x5590a3: 83c430 ADD ESP,0x30
    f.sp = integer::add(f.sp,0x00000030u,32,flags);
  }
  L005590a6: { // 0x5590a6: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00157340(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00557340: { // 0x557340: 8b81f0000000 MOV EAX,dword ptr [ECX + 0xf0]
    s.ax = m.r32((s.cx+0x000000f0u));
  }
  L00557346: { // 0x557346: c7810801000001000000 MOV dword ptr [ECX + 0x108],0x1
    m.w32((s.cx+0x00000108u), 0x00000001u);
  }
  L00557350: { // 0x557350: 89810c010000 MOV dword ptr [ECX + 0x10c],EAX
    m.w32((s.cx+0x0000010cu), s.ax);
  }
  L00557356: { // 0x557356: 8d50ff LEA EDX,[EAX + -0x1]
    s.dx = (s.ax-0x00000001u);
  }
  L00557359: { // 0x557359: 899110010000 MOV dword ptr [ECX + 0x110],EDX
    m.w32((s.cx+0x00000110u), s.dx);
  }
  L0055735f: { // 0x55735f: 8b9138010000 MOV EDX,dword ptr [ECX + 0x138]
    s.dx = m.r32((s.cx+0x00000138u));
  }
  L00557365: { // 0x557365: c1e00b SHL EAX,0xb
    s.ax = integer::shift(s.ax,0x0000000bu,32,flags,integer::Shift::left);
  }
  L00557368: { // 0x557368: 8d441004 LEA EAX,[EAX + EDX*0x1 + 0x4]
    s.ax = (s.ax+(s.dx * 0x00000001u)+0x00000004u);
  }
  L0055736c: { // 0x55736c: 898114010000 MOV dword ptr [ECX + 0x114],EAX
    m.w32((s.cx+0x00000114u), s.ax);
  }
  L00557372: { // 0x557372: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00157280(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00557280: { // 0x557280: 8b8110010000 MOV EAX,dword ptr [ECX + 0x110]
    s.ax = m.r32((s.cx+0x00000110u));
  }
  L00557286: { // 0x557286: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00557287: { // 0x557287: 8ba914010000 MOV EBP,dword ptr [ECX + 0x114]
    s.bp = m.r32((s.cx+0x00000114u));
  }
  L0055728d: { // 0x55728d: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0055728e: { // 0x55728e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00557290: { // 0x557290: 7433 JZ 0x005572c5
    if(integer::condition("JZ",flags)) goto L005572c5;
  }
  L00557292: { // 0x557292: 8bb108010000 MOV ESI,dword ptr [ECX + 0x108]
    s.si = m.r32((s.cx+0x00000108u));
  }
  L00557298: { // 0x557298: 8b910c010000 MOV EDX,dword ptr [ECX + 0x10c]
    s.dx = m.r32((s.cx+0x0000010cu));
  }
  L0055729e: { // 0x55729e: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0055729f: { // 0x55729f: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L005572a0: { // 0x5572a0: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L005572a1: { // 0x5572a1: 89b108010000 MOV dword ptr [ECX + 0x108],ESI
    m.w32((s.cx+0x00000108u), s.si);
  }
  L005572a7: { // 0x5572a7: 898110010000 MOV dword ptr [ECX + 0x110],EAX
    m.w32((s.cx+0x00000110u), s.ax);
  }
  L005572ad: { // 0x5572ad: 8d8504f8ffff LEA EAX,[EBP + 0xfffff804]
    s.ax = (s.bp+0xfffff804u);
  }
  L005572b3: { // 0x5572b3: 89910c010000 MOV dword ptr [ECX + 0x10c],EDX
    m.w32((s.cx+0x0000010cu), s.dx);
  }
  L005572b9: { // 0x5572b9: 898114010000 MOV dword ptr [ECX + 0x114],EAX
    m.w32((s.cx+0x00000114u), s.ax);
  }
  L005572bf: { // 0x5572bf: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L005572c2: { // 0x5572c2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005572c3: { // 0x5572c3: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005572c4: { // 0x5572c4: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L005572c5: { // 0x5572c5: 8b910c010000 MOV EDX,dword ptr [ECX + 0x10c]
    s.dx = m.r32((s.cx+0x0000010cu));
  }
  L005572cb: { // 0x5572cb: 8b8108010000 MOV EAX,dword ptr [ECX + 0x108]
    s.ax = m.r32((s.cx+0x00000108u));
  }
  L005572d1: { // 0x5572d1: 8bb1f0000000 MOV ESI,dword ptr [ECX + 0xf0]
    s.si = m.r32((s.cx+0x000000f0u));
  }
  L005572d7: { // 0x5572d7: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005572d8: { // 0x5572d8: 899108010000 MOV dword ptr [ECX + 0x108],EDX
    m.w32((s.cx+0x00000108u), s.dx);
  }
  L005572de: { // 0x5572de: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L005572e0: { // 0x5572e0: 2bd6 SUB EDX,ESI
    s.dx = integer::sub(s.dx,s.si,32,flags);
  }
  L005572e2: { // 0x5572e2: 89810c010000 MOV dword ptr [ECX + 0x10c],EAX
    m.w32((s.cx+0x0000010cu), s.ax);
  }
  L005572e8: { // 0x5572e8: 8d5402ff LEA EDX,[EDX + EAX*0x1 + -0x1]
    s.dx = (s.dx+(s.ax * 0x00000001u)-0x00000001u);
  }
  L005572ec: { // 0x5572ec: f6c201 TEST DL,0x1
    (void)integer::logical(((s.dx & 0xffu))&(0x00000001u),8,flags);
  }
  L005572ef: { // 0x5572ef: 740a JZ 0x005572fb
    if(integer::condition("JZ",flags)) goto L005572fb;
  }
  L005572f1: { // 0x5572f1: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L005572f2: { // 0x5572f2: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L005572f3: { // 0x5572f3: 89810c010000 MOV dword ptr [ECX + 0x10c],EAX
    m.w32((s.cx+0x0000010cu), s.ax);
  }
  L005572f9: { // 0x5572f9: eb0a JMP 0x00557305
    goto L00557305;
  }
  L005572fb: { // 0x5572fb: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L005572fc: { // 0x5572fc: 83c6fe ADD ESI,-0x2
    s.si = integer::add(s.si,0xfffffffeu,32,flags);
  }
  L005572ff: { // 0x5572ff: 89b908010000 MOV dword ptr [ECX + 0x108],EDI
    m.w32((s.cx+0x00000108u), s.di);
  }
  L00557305: { // 0x557305: 8b810c010000 MOV EAX,dword ptr [ECX + 0x10c]
    s.ax = m.r32((s.cx+0x0000010cu));
  }
  L0055730b: { // 0x55730b: 8b9108010000 MOV EDX,dword ptr [ECX + 0x108]
    s.dx = m.r32((s.cx+0x00000108u));
  }
  L00557311: { // 0x557311: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L00557314: { // 0x557314: 89b110010000 MOV dword ptr [ECX + 0x110],ESI
    m.w32((s.cx+0x00000110u), s.si);
  }
  L0055731a: { // 0x55731a: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0055731c: { // 0x55731c: 8b9138010000 MOV EDX,dword ptr [ECX + 0x138]
    s.dx = m.r32((s.cx+0x00000138u));
  }
  L00557322: { // 0x557322: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00557323: { // 0x557323: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00557324: { // 0x557324: 8d0482 LEA EAX,[EDX + EAX*0x4]
    s.ax = (s.dx+(s.ax * 0x00000004u));
  }
  L00557327: { // 0x557327: 898114010000 MOV dword ptr [ECX + 0x114],EAX
    m.w32((s.cx+0x00000114u), s.ax);
  }
  L0055732d: { // 0x55732d: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L00557330: { // 0x557330: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00557331: { // 0x557331: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000766c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004766c0: { // 0x004766c0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004766c1: { // 0x004766c1: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L004766c5: { // 0x004766c5: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004766c7: { // 0x004766c7: 83fa08 CMP EDX,0x8
    (void)integer::sub(s.dx,0x00000008u,32,flags);
  }
  L004766ca: { // 0x004766ca: 7346 JNC 0x00476712
    if(integer::condition("JNC",flags)) goto L00476712;
  }
  L004766cc: { // 0x004766cc: 8b4824 MOV ECX,dword ptr [EAX + 0x24]
    s.cx = m.r32((s.ax+0x00000024u));
  }
  L004766cf: { // 0x004766cf: 83e207 AND EDX,0x7
    s.dx = integer::logical((s.dx)&(0x00000007u),32,flags);
  }
  L004766d2: { // 0x004766d2: 894c2400 MOV dword ptr [ESP],ECX
    m.w32((f.sp), s.cx);
  }
  L004766d6: { // 0x004766d6: 8d0495a09d8300 LEA EAX,[EDX*0x4 + 0x839da0]
    s.ax = ((s.dx * 0x00000004u)+0x00839da0u);
  }
  L004766dd: { // 0x004766dd: 668b1495a09d8300 MOV DX,word ptr [EDX*0x4 + 0x839da0]
    s.dx = with_ax(s.dx, m.r16(((s.dx * 0x00000004u)+0x00839da0u)));
  }
  L004766e5: { // 0x004766e5: 668b4002 MOV AX,word ptr [EAX + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.ax+0x00000002u)));
  }
  L004766e9: { // 0x004766e9: 6603442402 ADD AX,word ptr [ESP + 0x2]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((f.sp+0x00000002u)),16,flags));
  }
  L004766ee: { // 0x004766ee: 6603d1 ADD DX,CX
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),(s.cx & 0xffffu),16,flags));
  }
  L004766f1: { // 0x004766f1: 6689542408 MOV word ptr [ESP + 0x8],DX
    m.w16((f.sp+0x00000008u), (s.dx & 0xffffu));
  }
  L004766f6: { // 0x004766f6: 8d542408 LEA EDX,[ESP + 0x8]
    s.dx = (f.sp+0x00000008u);
  }
  L004766fa: { // 0x004766fa: 668944240a MOV word ptr [ESP + 0xa],AX
    m.w16((f.sp+0x0000000au), (s.ax & 0xffffu));
  }
  L004766ff: { // 0x004766ff: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  L00476703: { // 0x00476703: 894c2408 MOV dword ptr [ESP + 0x8],ECX
    m.w32((f.sp+0x00000008u), s.cx);
  }
  L00476707: { // 0x00476707: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00476708: { // 0x00476708: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0047670d: { // 0x0047670d: e8eeed0c00 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4679442u); flags=s.arithmetic_flags;
  }
  L00476712: { // 0x00476712: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00476713: { // 0x00476713: c20400 RET 0x4
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
void f_0007b190(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0047b190: { // 0x47b190: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  L0047b193: { // 0x47b193: 3dffff0000 CMP EAX,0xffff
    (void)integer::sub(s.ax,0x0000ffffu,32,flags);
  }
  L0047b198: { // 0x47b198: 7407 JZ 0x0047b1a1
    if(integer::condition("JZ",flags)) goto L0047b1a1;
  }
  L0047b19a: { // 0x47b19a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0047b19c: { // 0x47b19c: 7403 JZ 0x0047b1a1
    if(integer::condition("JZ",flags)) goto L0047b1a1;
  }
  L0047b19e: { // 0x47b19e: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0047b1a0: { // 0x47b1a0: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b1a1: { // 0x47b1a1: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047b1a3: { // 0x47b1a3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4369712u:f_0002ad30(m,s,child,{});break;
case 4369872u:f_0002add0(m,s,child,{});break;
case 4698592u:f_0007b1e0(m,s,child,{});break;
case 5537600u:f_00147f40(m,s,child,{});break;
case 5679504u:f_0016a990(m,s,child,{});break;
case 5606240u:f_00158b60(m,s,child,{});break;
case 5600064u:f_00157340(m,s,child,{});break;
case 5599872u:f_00157280(m,s,child,{});break;
case 4679360u:f_000766c0(m,s,child,{});break;
case 5526784u:f_00145500(m,s,child,{});break;
case 4698512u:f_0007b190(m,s,child,{});break;
default:throw std::domain_error("recovery788 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0057ffc0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0057ffc0: { // 0x57ffc0: 83ec18 SUB ESP,0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
  L0057ffc3: { // 0x57ffc3: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0057ffc8: { // 0x57ffc8: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0057ffc9: { // 0x57ffc9: e87273fdff CALL 0x00557340
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557340u,5767118u); flags=s.arithmetic_flags;
  }
  L0057ffce: { // 0x57ffce: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0057ffd3: { // 0x57ffd3: e8a872fdff CALL 0x00557280
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557280u,5767128u); flags=s.arithmetic_flags;
  }
  L0057ffd8: { // 0x57ffd8: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0057ffda: { // 0x57ffda: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0057ffdc: { // 0x57ffdc: 0f845e020000 JZ 0x00580240
    if(integer::condition("JZ",flags)) goto L00580240;
  }
  L0057ffe2: { // 0x57ffe2: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0057ffe3: { // 0x57ffe3: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0057ffe4: { // 0x57ffe4: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0057ffe5: { // 0x57ffe5: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L0057ffe7: { // 0x57ffe7: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0057ffe9: { // 0x57ffe9: e8d266efff CALL 0x004766c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004766c0u,5767150u); flags=s.arithmetic_flags;
  }
  L0057ffee: { // 0x57ffee: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0057fff0: { // 0x57fff0: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0057fff2: { // 0x57fff2: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L0057fff6: { // 0x57fff6: e8c566efff CALL 0x004766c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004766c0u,5767163u); flags=s.arithmetic_flags;
  }
  L0057fffb: { // 0x57fffb: 6a03 PUSH 0x3
    f.push(m,0x00000003u);
  }
  L0057fffd: { // 0x57fffd: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0057ffff: { // 0x57ffff: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00580003: { // 0x580003: e8b866efff CALL 0x004766c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004766c0u,5767176u); flags=s.arithmetic_flags;
  }
  L00580008: { // 0x580008: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  L0058000a: { // 0x58000a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0058000c: { // 0x58000c: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0058000e: { // 0x58000e: e8ad66efff CALL 0x004766c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004766c0u,5767187u); flags=s.arithmetic_flags;
  }
  L00580013: { // 0x580013: 6a06 PUSH 0x6
    f.push(m,0x00000006u);
  }
  L00580015: { // 0x580015: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00580017: { // 0x580017: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L00580019: { // 0x580019: e8a266efff CALL 0x004766c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004766c0u,5767198u); flags=s.arithmetic_flags;
  }
  L0058001e: { // 0x58001e: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0058001f: { // 0x58001f: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00580024: { // 0x580024: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00580026: { // 0x580026: e8358bfdff CALL 0x00558b60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00558b60u,5767211u); flags=s.arithmetic_flags;
  }
  L0058002b: { // 0x58002b: 3d83000000 CMP EAX,0x83
    (void)integer::sub(s.ax,0x00000083u,32,flags);
  }
  L00580030: { // 0x580030: 0f85aa000000 JNZ 0x005800e0
    if(integer::condition("JNZ",flags)) goto L005800e0;
  }
  L00580036: { // 0x580036: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00580037: { // 0x580037: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0058003c: { // 0x58003c: e81f8bfdff CALL 0x00558b60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00558b60u,5767233u); flags=s.arithmetic_flags;
  }
  L00580041: { // 0x580041: 3d83000000 CMP EAX,0x83
    (void)integer::sub(s.ax,0x00000083u,32,flags);
  }
  L00580046: { // 0x580046: 0f85dd010000 JNZ 0x00580229
    if(integer::condition("JNZ",flags)) goto L00580229;
  }
  L0058004c: { // 0x58004c: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0058004e: { // 0x58004e: e83db1efff CALL 0x0047b190
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b190u,5767251u); flags=s.arithmetic_flags;
  }
  L00580053: { // 0x580053: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00580055: { // 0x580055: 0f84ce010000 JZ 0x00580229
    if(integer::condition("JZ",flags)) goto L00580229;
  }
  L0058005b: { // 0x58005b: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L00580060: { // 0x580060: e87bfd0a00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5767269u); flags=s.arithmetic_flags;
  }
  L00580065: { // 0x580065: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00580069: { // 0x580069: c744241c00000000 MOV dword ptr [ESP + 0x1c],0x0
    m.w32((f.sp+0x0000001cu), 0x00000000u);
  }
  L00580071: { // 0x580071: df6c2418 FILD qword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L00580075: { // 0x580075: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0058007b: { // 0x58007b: e8d0a91e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5767296u); flags=s.arithmetic_flags;
  }
  L00580080: { // 0x580080: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L00580083: { // 0x580083: 77d6 JA 0x0058005b
    if(integer::condition("JA",flags)) goto L0058005b;
  }
  L00580085: { // 0x580085: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00580087: { // 0x580087: 0f859c010000 JNZ 0x00580229
    if(integer::condition("JNZ",flags)) goto L00580229;
  }
  L0058008d: { // 0x58008d: 8a8d1b010000 MOV CL,byte ptr [EBP + 0x11b]
    s.cx = with_al(s.cx, m.r8((s.bp+0x0000011bu)));
  }
  L00580093: { // 0x580093: 80c1fc ADD CL,0xfc
    s.cx = with_al(s.cx, integer::add((s.cx & 0xffu),0x000000fcu,8,flags));
  }
  L00580096: { // 0x580096: 888d1b010000 MOV byte ptr [EBP + 0x11b],CL
    m.w8((s.bp+0x0000011bu), (s.cx & 0xffu));
  }
  L0058009c: { // 0x58009c: 8b0d3c86a500 MOV ECX,dword ptr [0x00a5863c]
    s.cx = m.r32((0x00a5863cu));
  }
  L005800a2: { // 0x5800a2: 8b3d4c6b8300 MOV EDI,dword ptr [0x00836b4c]
    s.di = m.r32((0x00836b4cu));
  }
  L005800a8: { // 0x5800a8: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005800aa: { // 0x5800aa: 7505 JNZ 0x005800b1
    if(integer::condition("JNZ",flags)) goto L005800b1;
  }
  L005800ac: { // 0x5800ac: 83caff OR EDX,0xffffffff
    s.dx = integer::logical((s.dx)|(0xffffffffu),32,flags);
  }
  L005800af: { // 0x5800af: eb17 JMP 0x005800c8
    goto L005800c8;
  }
  L005800b1: { // 0x5800b1: 0fbf4626 MOVSX EAX,word ptr [ESI + 0x26]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000026u)),16));
  }
  L005800b5: { // 0x5800b5: 0fbf5624 MOVSX EDX,word ptr [ESI + 0x24]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000024u)),16));
  }
  L005800b9: { // 0x5800b9: 0fafc7 IMUL EAX,EDI
    s.ax = integer::imul(s.ax,s.di,32,flags);
  }
  L005800bc: { // 0x5800bc: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L005800be: { // 0x5800be: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L005800c1: { // 0x5800c1: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L005800c4: { // 0x5800c4: 8b540838 MOV EDX,dword ptr [EAX + ECX*0x1 + 0x38]
    s.dx = m.r32((s.ax+(s.cx * 0x00000001u)+0x00000038u));
  }
  L005800c8: { // 0x5800c8: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005800ca: { // 0x5800ca: 0f8459010000 JZ 0x00580229
    if(integer::condition("JZ",flags)) goto L00580229;
  }
  L005800d0: { // 0x5800d0: 0fbf4526 MOVSX EAX,word ptr [EBP + 0x26]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.bp+0x00000026u)),16));
  }
  L005800d4: { // 0x5800d4: 0fbf7524 MOVSX ESI,word ptr [EBP + 0x24]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.bp+0x00000024u)),16));
  }
  L005800d8: { // 0x5800d8: 0fafc7 IMUL EAX,EDI
    s.ax = integer::imul(s.ax,s.di,32,flags);
  }
  L005800db: { // 0x5800db: e93d010000 JMP 0x0058021d
    goto L0058021d;
  }
  L005800e0: { // 0x5800e0: 83f838 CMP EAX,0x38
    (void)integer::sub(s.ax,0x00000038u,32,flags);
  }
  L005800e3: { // 0x5800e3: 0f85a8000000 JNZ 0x00580191
    if(integer::condition("JNZ",flags)) goto L00580191;
  }
  L005800e9: { // 0x5800e9: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005800ea: { // 0x5800ea: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L005800ef: { // 0x5800ef: e86c8afdff CALL 0x00558b60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00558b60u,5767412u); flags=s.arithmetic_flags;
  }
  L005800f4: { // 0x5800f4: 83f838 CMP EAX,0x38
    (void)integer::sub(s.ax,0x00000038u,32,flags);
  }
  L005800f7: { // 0x5800f7: 0f852c010000 JNZ 0x00580229
    if(integer::condition("JNZ",flags)) goto L00580229;
  }
  L005800fd: { // 0x5800fd: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005800ff: { // 0x5800ff: e88cb0efff CALL 0x0047b190
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b190u,5767428u); flags=s.arithmetic_flags;
  }
  L00580104: { // 0x580104: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00580106: { // 0x580106: 0f841d010000 JZ 0x00580229
    if(integer::condition("JZ",flags)) goto L00580229;
  }
  L0058010c: { // 0x58010c: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L00580111: { // 0x580111: e8cafc0a00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5767446u); flags=s.arithmetic_flags;
  }
  L00580116: { // 0x580116: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L0058011a: { // 0x58011a: c744242400000000 MOV dword ptr [ESP + 0x24],0x0
    m.w32((f.sp+0x00000024u), 0x00000000u);
  }
  L00580122: { // 0x580122: df6c2420 FILD qword ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L00580126: { // 0x580126: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0058012c: { // 0x58012c: e81fa91e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5767473u); flags=s.arithmetic_flags;
  }
  L00580131: { // 0x580131: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L00580134: { // 0x580134: 77d6 JA 0x0058010c
    if(integer::condition("JA",flags)) goto L0058010c;
  }
  L00580136: { // 0x580136: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00580138: { // 0x580138: 0f85eb000000 JNZ 0x00580229
    if(integer::condition("JNZ",flags)) goto L00580229;
  }
  L0058013e: { // 0x58013e: 8a8f1b010000 MOV CL,byte ptr [EDI + 0x11b]
    s.cx = with_al(s.cx, m.r8((s.di+0x0000011bu)));
  }
  L00580144: { // 0x580144: 80c1fc ADD CL,0xfc
    s.cx = with_al(s.cx, integer::add((s.cx & 0xffu),0x000000fcu,8,flags));
  }
  L00580147: { // 0x580147: 888f1b010000 MOV byte ptr [EDI + 0x11b],CL
    m.w8((s.di+0x0000011bu), (s.cx & 0xffu));
  }
  L0058014d: { // 0x58014d: 8b0d3c86a500 MOV ECX,dword ptr [0x00a5863c]
    s.cx = m.r32((0x00a5863cu));
  }
  L00580153: { // 0x580153: 8b1d4c6b8300 MOV EBX,dword ptr [0x00836b4c]
    s.bx = m.r32((0x00836b4cu));
  }
  L00580159: { // 0x580159: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0058015b: { // 0x58015b: 7505 JNZ 0x00580162
    if(integer::condition("JNZ",flags)) goto L00580162;
  }
  L0058015d: { // 0x58015d: 83caff OR EDX,0xffffffff
    s.dx = integer::logical((s.dx)|(0xffffffffu),32,flags);
  }
  L00580160: { // 0x580160: eb17 JMP 0x00580179
    goto L00580179;
  }
  L00580162: { // 0x580162: 0fbf4626 MOVSX EAX,word ptr [ESI + 0x26]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000026u)),16));
  }
  L00580166: { // 0x580166: 0fbf5624 MOVSX EDX,word ptr [ESI + 0x24]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000024u)),16));
  }
  L0058016a: { // 0x58016a: 0fafc3 IMUL EAX,EBX
    s.ax = integer::imul(s.ax,s.bx,32,flags);
  }
  L0058016d: { // 0x58016d: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0058016f: { // 0x58016f: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L00580172: { // 0x580172: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L00580175: { // 0x580175: 8b540838 MOV EDX,dword ptr [EAX + ECX*0x1 + 0x38]
    s.dx = m.r32((s.ax+(s.cx * 0x00000001u)+0x00000038u));
  }
  L00580179: { // 0x580179: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0058017b: { // 0x58017b: 0f84a8000000 JZ 0x00580229
    if(integer::condition("JZ",flags)) goto L00580229;
  }
  L00580181: { // 0x580181: 0fbf4726 MOVSX EAX,word ptr [EDI + 0x26]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000026u)),16));
  }
  L00580185: { // 0x580185: 0fbf7724 MOVSX ESI,word ptr [EDI + 0x24]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000024u)),16));
  }
  L00580189: { // 0x580189: 0fafc3 IMUL EAX,EBX
    s.ax = integer::imul(s.ax,s.bx,32,flags);
  }
  L0058018c: { // 0x58018c: e98c000000 JMP 0x0058021d
    goto L0058021d;
  }
  L00580191: { // 0x580191: 3de0000000 CMP EAX,0xe0
    (void)integer::sub(s.ax,0x000000e0u,32,flags);
  }
  L00580196: { // 0x580196: 0f858d000000 JNZ 0x00580229
    if(integer::condition("JNZ",flags)) goto L00580229;
  }
  L0058019c: { // 0x58019c: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L005801a0: { // 0x5801a0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005801a1: { // 0x5801a1: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L005801a6: { // 0x5801a6: e8b589fdff CALL 0x00558b60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00558b60u,5767595u); flags=s.arithmetic_flags;
  }
  L005801ab: { // 0x5801ab: 3de0000000 CMP EAX,0xe0
    (void)integer::sub(s.ax,0x000000e0u,32,flags);
  }
  L005801b0: { // 0x5801b0: 7577 JNZ 0x00580229
    if(integer::condition("JNZ",flags)) goto L00580229;
  }
  L005801b2: { // 0x5801b2: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L005801b6: { // 0x5801b6: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L005801bb: { // 0x5801bb: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005801bc: { // 0x5801bc: e89f89fdff CALL 0x00558b60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00558b60u,5767617u); flags=s.arithmetic_flags;
  }
  L005801c1: { // 0x5801c1: 3de0000000 CMP EAX,0xe0
    (void)integer::sub(s.ax,0x000000e0u,32,flags);
  }
  L005801c6: { // 0x5801c6: 7561 JNZ 0x00580229
    if(integer::condition("JNZ",flags)) goto L00580229;
  }
  L005801c8: { // 0x5801c8: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005801ca: { // 0x5801ca: e8c1afefff CALL 0x0047b190
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b190u,5767631u); flags=s.arithmetic_flags;
  }
  L005801cf: { // 0x5801cf: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005801d1: { // 0x5801d1: 7456 JZ 0x00580229
    if(integer::condition("JZ",flags)) goto L00580229;
  }
  L005801d3: { // 0x5801d3: 8a8e1b010000 MOV CL,byte ptr [ESI + 0x11b]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000011bu)));
  }
  L005801d9: { // 0x5801d9: 80c104 ADD CL,0x4
    s.cx = with_al(s.cx, integer::add((s.cx & 0xffu),0x00000004u,8,flags));
  }
  L005801dc: { // 0x5801dc: 888e1b010000 MOV byte ptr [ESI + 0x11b],CL
    m.w8((s.si+0x0000011bu), (s.cx & 0xffu));
  }
  L005801e2: { // 0x5801e2: 8b0d3c86a500 MOV ECX,dword ptr [0x00a5863c]
    s.cx = m.r32((0x00a5863cu));
  }
  L005801e8: { // 0x5801e8: 8b1d4c6b8300 MOV EBX,dword ptr [0x00836b4c]
    s.bx = m.r32((0x00836b4cu));
  }
  L005801ee: { // 0x5801ee: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005801f0: { // 0x5801f0: 7505 JNZ 0x005801f7
    if(integer::condition("JNZ",flags)) goto L005801f7;
  }
  L005801f2: { // 0x5801f2: 83caff OR EDX,0xffffffff
    s.dx = integer::logical((s.dx)|(0xffffffffu),32,flags);
  }
  L005801f5: { // 0x5801f5: eb17 JMP 0x0058020e
    goto L0058020e;
  }
  L005801f7: { // 0x5801f7: 0fbf4726 MOVSX EAX,word ptr [EDI + 0x26]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000026u)),16));
  }
  L005801fb: { // 0x5801fb: 0fbf5724 MOVSX EDX,word ptr [EDI + 0x24]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000024u)),16));
  }
  L005801ff: { // 0x5801ff: 0fafc3 IMUL EAX,EBX
    s.ax = integer::imul(s.ax,s.bx,32,flags);
  }
  L00580202: { // 0x580202: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00580204: { // 0x580204: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L00580207: { // 0x580207: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L0058020a: { // 0x58020a: 8b540838 MOV EDX,dword ptr [EAX + ECX*0x1 + 0x38]
    s.dx = m.r32((s.ax+(s.cx * 0x00000001u)+0x00000038u));
  }
  L0058020e: { // 0x58020e: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00580210: { // 0x580210: 7417 JZ 0x00580229
    if(integer::condition("JZ",flags)) goto L00580229;
  }
  L00580212: { // 0x580212: 0fbf4626 MOVSX EAX,word ptr [ESI + 0x26]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000026u)),16));
  }
  L00580216: { // 0x580216: 0fbf7624 MOVSX ESI,word ptr [ESI + 0x24]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000024u)),16));
  }
  L0058021a: { // 0x58021a: 0fafc3 IMUL EAX,EBX
    s.ax = integer::imul(s.ax,s.bx,32,flags);
  }
  L0058021d: { // 0x58021d: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L0058021f: { // 0x58021f: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L00580222: { // 0x580222: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L00580225: { // 0x580225: 89540838 MOV dword ptr [EAX + ECX*0x1 + 0x38],EDX
    m.w32((s.ax+(s.cx * 0x00000001u)+0x00000038u), s.dx);
  }
  L00580229: { // 0x580229: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0058022e: { // 0x58022e: e84d70fdff CALL 0x00557280
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557280u,5767731u); flags=s.arithmetic_flags;
  }
  L00580233: { // 0x580233: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00580235: { // 0x580235: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00580237: { // 0x580237: 0f85a8fdffff JNZ 0x0057ffe5
    if(integer::condition("JNZ",flags)) goto L0057ffe5;
  }
  L0058023d: { // 0x58023d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0058023e: { // 0x58023e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0058023f: { // 0x58023f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00580240: { // 0x580240: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00580241: { // 0x580241: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L00580244: { // 0x580244: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
