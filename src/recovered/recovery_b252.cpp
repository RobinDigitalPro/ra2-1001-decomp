#include "recovered/recovery_b252_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b252 {
namespace {
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_0007b190(Memory&,State&,Frame&,const Operations&);
void f_000f89d0(Memory&,State&,Frame&,const Operations&);
void f_000ecc60(Memory&,State&,Frame&,const Operations&);
void f_00058050(Memory&,State&,Frame&,const Operations&);
void f_0036d860(Memory&,State&,Frame&,const Operations&);
void f_00038b60(Memory&,State&,Frame&,const Operations&);
void f_002b6320(Memory&,State&,Frame&,const Operations&);
void f_0022ddd0(Memory&,State&,Frame&,const Operations&);
void f_00191300(Memory&,State&,Frame&,const Operations&);
void f_001ca970(Memory&,State&,Frame&,const Operations&);
void f_0003f5d0(Memory&,State&,Frame&,const Operations&);
void f_002b72a0(Memory&,State&,Frame&,const Operations&);
void f_0003d130(Memory&,State&,Frame&,const Operations&);
void f_002b9c70(Memory&,State&,Frame&,const Operations&);
void f_001cbf20(Memory&,State&,Frame&,const Operations&);
void f_00045110(Memory&,State&,Frame&,const Operations&);
void f_0005d4f0(Memory&,State&,Frame&,const Operations&);
void f_0005e400(Memory&,State&,Frame&,const Operations&);
void f_0022fde0(Memory&,State&,Frame&,const Operations&);
void f_0022e4e0(Memory&,State&,Frame&,const Operations&);
void f_00307f00(Memory&,State&,Frame&,const Operations&);
void f_00290440(Memory&,State&,Frame&,const Operations&);
void f_00096850(Memory&,State&,Frame&,const Operations&);
void f_000b8660(Memory&,State&,Frame&,const Operations&);
void f_000b8640(Memory&,State&,Frame&,const Operations&);
void f_000b86a0(Memory&,State&,Frame&,const Operations&);
void f_0000ffc0(Memory&,State&,Frame&,const Operations&);
void f_000b8b00(Memory&,State&,Frame&,const Operations&);
void f_0004d670(Memory&,State&,Frame&,const Operations&);
void f_002cdab0(Memory&,State&,Frame&,const Operations&);
void f_00307fe0(Memory&,State&,Frame&,const Operations&);
void f_002d4b50(Memory&,State&,Frame&,const Operations&);
void f_002d4b30(Memory&,State&,Frame&,const Operations&);
void f_002b6910(Memory&,State&,Frame&,const Operations&);
void f_000538b0(Memory&,State&,Frame&,const Operations&);
void f_00053890(Memory&,State&,Frame&,const Operations&);
void f_0000ff10(Memory&,State&,Frame&,const Operations&);
void f_00005bf0(Memory&,State&,Frame&,const Operations&);
void f_0000ffd0(Memory&,State&,Frame&,const Operations&);
void f_00157450(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void f_0025a120(Memory&,State&,Frame&,const Operations&);
void f_00145490(Memory&,State&,Frame&,const Operations&);
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
void f_000f89d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004f89d0: { // 0x4f89d0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004f89d1: { // 0x4f89d1: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004f89d2: { // 0x4f89d2: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004f89d3: { // 0x4f89d3: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L004f89d5: { // 0x4f89d5: 68b0ce7b00 PUSH 0x7bceb0
    f.push(m,0x007bceb0u);
  }
  L004f89da: { // 0x4f89da: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004f89db: { // 0x4f89db: e8804e2700 CALL 0x0076d860
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d860u,5212640u); flags=s.arithmetic_flags;
  }
  L004f89e0: { // 0x4f89e0: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L004f89e3: { // 0x4f89e3: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004f89e5: { // 0x4f89e5: 7509 JNZ 0x004f89f0
    if(integer::condition("JNZ",flags)) goto L004f89f0;
  }
  L004f89e7: { // 0x4f89e7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004f89e8: { // 0x4f89e8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004f89e9: { // 0x4f89e9: b8feffffff MOV EAX,0xfffffffe
    s.ax = 0xfffffffeu;
  }
  L004f89ee: { // 0x4f89ee: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004f89ef: { // 0x4f89ef: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004f89f0: { // 0x4f89f0: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L004f89f2: { // 0x4f89f2: 743f JZ 0x004f8a33
    if(integer::condition("JZ",flags)) goto L004f8a33;
  }
  L004f89f4: { // 0x4f89f4: a148e0a100 MOV EAX,[0x00a1e048]
    s.ax = m.r32((0x00a1e048u));
  }
  L004f89f9: { // 0x4f89f9: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L004f89fb: { // 0x4f89fb: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004f89fd: { // 0x4f89fd: 7e34 JLE 0x004f8a33
    if(integer::condition("JLE",flags)) goto L004f8a33;
  }
  L004f89ff: { // 0x4f89ff: a13ce0a100 MOV EAX,[0x00a1e03c]
    s.ax = m.r32((0x00a1e03cu));
  }
  L004f8a04: { // 0x4f8a04: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004f8a05: { // 0x4f8a05: 8b3498 MOV ESI,dword ptr [EAX + EBX*0x4]
    s.si = m.r32((s.ax+(s.bx * 0x00000004u)));
  }
  L004f8a08: { // 0x4f8a08: 8d4e64 LEA ECX,[ESI + 0x64]
    s.cx = (s.si+0x00000064u);
  }
  L004f8a0b: { // 0x4f8a0b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004f8a0c: { // 0x4f8a0c: e84f4e2700 CALL 0x0076d860
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d860u,5212689u); flags=s.arithmetic_flags;
  }
  L004f8a11: { // 0x4f8a11: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L004f8a14: { // 0x4f8a14: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004f8a16: { // 0x4f8a16: 7422 JZ 0x004f8a3a
    if(integer::condition("JZ",flags)) goto L004f8a3a;
  }
  L004f8a18: { // 0x4f8a18: 8d5624 LEA EDX,[ESI + 0x24]
    s.dx = (s.si+0x00000024u);
  }
  L004f8a1b: { // 0x4f8a1b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004f8a1c: { // 0x4f8a1c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004f8a1d: { // 0x4f8a1d: e83e4e2700 CALL 0x0076d860
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d860u,5212706u); flags=s.arithmetic_flags;
  }
  L004f8a22: { // 0x4f8a22: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L004f8a25: { // 0x4f8a25: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004f8a27: { // 0x4f8a27: 7411 JZ 0x004f8a3a
    if(integer::condition("JZ",flags)) goto L004f8a3a;
  }
  L004f8a29: { // 0x4f8a29: a148e0a100 MOV EAX,[0x00a1e048]
    s.ax = m.r32((0x00a1e048u));
  }
  L004f8a2e: { // 0x4f8a2e: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L004f8a2f: { // 0x4f8a2f: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L004f8a31: { // 0x4f8a31: 7ccc JL 0x004f89ff
    if(integer::condition("JL",flags)) goto L004f89ff;
  }
  L004f8a33: { // 0x4f8a33: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004f8a34: { // 0x4f8a34: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004f8a35: { // 0x4f8a35: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L004f8a38: { // 0x4f8a38: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004f8a39: { // 0x4f8a39: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004f8a3a: { // 0x4f8a3a: 8b86b8000000 MOV EAX,dword ptr [ESI + 0xb8]
    s.ax = m.r32((s.si+0x000000b8u));
  }
  L004f8a40: { // 0x4f8a40: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004f8a41: { // 0x4f8a41: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004f8a42: { // 0x4f8a42: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004f8a43: { // 0x4f8a43: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000ecc60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004ecc60: { // 0x4ecc60: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004ecc61: { // 0x4ecc61: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004ecc62: { // 0x4ecc62: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004ecc63: { // 0x4ecc63: 8b3dd8a5a100 MOV EDI,dword ptr [0x00a1a5d8]
    s.di = m.r32((0x00a1a5d8u));
  }
  L004ecc69: { // 0x4ecc69: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L004ecc6b: { // 0x4ecc6b: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L004ecc6d: { // 0x4ecc6d: 7e1b JLE 0x004ecc8a
    if(integer::condition("JLE",flags)) goto L004ecc8a;
  }
  L004ecc6f: { // 0x4ecc6f: 8b35cca5a100 MOV ESI,dword ptr [0x00a1a5cc]
    s.si = m.r32((0x00a1a5ccu));
  }
  L004ecc75: { // 0x4ecc75: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004ecc77: { // 0x4ecc77: 8b5834 MOV EBX,dword ptr [EAX + 0x34]
    s.bx = m.r32((s.ax+0x00000034u));
  }
  L004ecc7a: { // 0x4ecc7a: 398bb8000000 CMP dword ptr [EBX + 0xb8],ECX
    (void)integer::sub(m.r32((s.bx+0x000000b8u)),s.cx,32,flags);
  }
  L004ecc80: { // 0x4ecc80: 740a JZ 0x004ecc8c
    if(integer::condition("JZ",flags)) goto L004ecc8c;
  }
  L004ecc82: { // 0x4ecc82: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L004ecc83: { // 0x4ecc83: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  L004ecc86: { // 0x4ecc86: 3bd7 CMP EDX,EDI
    (void)integer::sub(s.dx,s.di,32,flags);
  }
  L004ecc88: { // 0x4ecc88: 7ceb JL 0x004ecc75
    if(integer::condition("JL",flags)) goto L004ecc75;
  }
  L004ecc8a: { // 0x4ecc8a: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004ecc8c: { // 0x4ecc8c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004ecc8d: { // 0x4ecc8d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004ecc8e: { // 0x4ecc8e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004ecc8f: { // 0x4ecc8f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00058050(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00458050: { // 0x458050: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00458051: { // 0x458051: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00458052: { // 0x458052: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L00458054: { // 0x458054: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L00458056: { // 0x458056: 742e JZ 0x00458086
    if(integer::condition("JZ",flags)) goto L00458086;
  }
  L00458058: { // 0x458058: a118e0a100 MOV EAX,[0x00a1e018]
    s.ax = m.r32((0x00a1e018u));
  }
  L0045805d: { // 0x45805d: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0045805f: { // 0x45805f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00458061: { // 0x458061: 7e23 JLE 0x00458086
    if(integer::condition("JLE",flags)) goto L00458086;
  }
  L00458063: { // 0x458063: a10ce0a100 MOV EAX,[0x00a1e00c]
    s.ax = m.r32((0x00a1e00cu));
  }
  L00458068: { // 0x458068: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00458069: { // 0x458069: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  L0045806c: { // 0x45806c: 83c124 ADD ECX,0x24
    s.cx = integer::add(s.cx,0x00000024u,32,flags);
  }
  L0045806f: { // 0x45806f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00458070: { // 0x458070: e8eb573100 CALL 0x0076d860
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d860u,4554869u); flags=s.arithmetic_flags;
  }
  L00458075: { // 0x458075: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00458078: { // 0x458078: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0045807a: { // 0x45807a: 7410 JZ 0x0045808c
    if(integer::condition("JZ",flags)) goto L0045808c;
  }
  L0045807c: { // 0x45807c: a118e0a100 MOV EAX,[0x00a1e018]
    s.ax = m.r32((0x00a1e018u));
  }
  L00458081: { // 0x458081: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L00458082: { // 0x458082: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L00458084: { // 0x458084: 7cdd JL 0x00458063
    if(integer::condition("JL",flags)) goto L00458063;
  }
  L00458086: { // 0x458086: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00458087: { // 0x458087: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L0045808a: { // 0x45808a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0045808b: { // 0x45808b: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0045808c: { // 0x45808c: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0045808e: { // 0x45808e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0045808f: { // 0x45808f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00458090: { // 0x458090: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0036d860(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0076d860: { // 0x76d860: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0076d861: { // 0x76d861: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L0076d863: { // 0x76d863: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0076d864: { // 0x76d864: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0076d865: { // 0x76d865: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0076d866: { // 0x76d866: 8b750c MOV ESI,dword ptr [EBP + 0xc]
    s.si = m.r32((s.bp+0x0000000cu));
  }
  L0076d869: { // 0x76d869: 8b7d08 MOV EDI,dword ptr [EBP + 0x8]
    s.di = m.r32((s.bp+0x00000008u));
  }
  L0076d86c: { // 0x76d86c: 8d052805b100 LEA EAX,[0xb10528]
    s.ax = (0x00b10528u);
  }
  L0076d872: { // 0x76d872: 83780800 CMP dword ptr [EAX + 0x8],0x0
    (void)integer::sub(m.r32((s.ax+0x00000008u)),0x00000000u,32,flags);
  }
  L0076d876: { // 0x76d876: 753b JNZ 0x0076d8b3
    if(integer::condition("JNZ",flags)) goto L0076d8b3;
  }
  L0076d878: { // 0x76d878: b0ff MOV AL,0xff
    s.ax = with_al(s.ax, 0x000000ffu);
  }
  L0076d87a: { // 0x76d87a: 8bff MOV EDI,EDI
    s.di = s.di;
  }
  L0076d87c: { // 0x76d87c: 0ac0 OR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|((s.ax & 0xffu)),8,flags));
  }
  L0076d87e: { // 0x76d87e: 742e JZ 0x0076d8ae
    if(integer::condition("JZ",flags)) goto L0076d8ae;
  }
  L0076d880: { // 0x76d880: 8a06 MOV AL,byte ptr [ESI]
    s.ax = with_al(s.ax, m.r8((s.si)));
  }
  L0076d882: { // 0x76d882: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0076d883: { // 0x76d883: 8a27 MOV AH,byte ptr [EDI]
    s.ax = (s.ax & 0xffff00ffu) | (((m.r8((s.di))) & 0xffu) << 8);
  }
  L0076d885: { // 0x76d885: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0076d886: { // 0x76d886: 38c4 CMP AH,AL
    (void)integer::sub(((s.ax >> 8) & 0xffu),(s.ax & 0xffu),8,flags);
  }
  L0076d888: { // 0x76d888: 74f2 JZ 0x0076d87c
    if(integer::condition("JZ",flags)) goto L0076d87c;
  }
  L0076d88a: { // 0x76d88a: 2c41 SUB AL,0x41
    s.ax = with_al(s.ax, integer::sub((s.ax & 0xffu),0x00000041u,8,flags));
  }
  L0076d88c: { // 0x76d88c: 3c1a CMP AL,0x1a
    (void)integer::sub((s.ax & 0xffu),0x0000001au,8,flags);
  }
  L0076d88e: { // 0x76d88e: 1ac9 SBB CL,CL
    s.cx = with_al(s.cx, integer::sub((s.cx & 0xffu),(s.cx & 0xffu),8,flags,flags&integer::CF));
  }
  L0076d890: { // 0x76d890: 80e120 AND CL,0x20
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))&(0x00000020u),8,flags));
  }
  L0076d893: { // 0x76d893: 02c1 ADD AL,CL
    s.ax = with_al(s.ax, integer::add((s.ax & 0xffu),(s.cx & 0xffu),8,flags));
  }
  L0076d895: { // 0x76d895: 0441 ADD AL,0x41
    s.ax = with_al(s.ax, integer::add((s.ax & 0xffu),0x00000041u,8,flags));
  }
  L0076d897: { // 0x76d897: 86e0 XCHG AL,AH
    const auto left=(s.ax & 0xffu);const auto right=((s.ax >> 8) & 0xffu);s.ax = with_al(s.ax, right);s.ax = (s.ax & 0xffff00ffu) | (((left) & 0xffu) << 8);
  }
  L0076d899: { // 0x76d899: 2c41 SUB AL,0x41
    s.ax = with_al(s.ax, integer::sub((s.ax & 0xffu),0x00000041u,8,flags));
  }
  L0076d89b: { // 0x76d89b: 3c1a CMP AL,0x1a
    (void)integer::sub((s.ax & 0xffu),0x0000001au,8,flags);
  }
  L0076d89d: { // 0x76d89d: 1ac9 SBB CL,CL
    s.cx = with_al(s.cx, integer::sub((s.cx & 0xffu),(s.cx & 0xffu),8,flags,flags&integer::CF));
  }
  L0076d89f: { // 0x76d89f: 80e120 AND CL,0x20
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))&(0x00000020u),8,flags));
  }
  L0076d8a2: { // 0x76d8a2: 02c1 ADD AL,CL
    s.ax = with_al(s.ax, integer::add((s.ax & 0xffu),(s.cx & 0xffu),8,flags));
  }
  L0076d8a4: { // 0x76d8a4: 0441 ADD AL,0x41
    s.ax = with_al(s.ax, integer::add((s.ax & 0xffu),0x00000041u,8,flags));
  }
  L0076d8a6: { // 0x76d8a6: 38e0 CMP AL,AH
    (void)integer::sub((s.ax & 0xffu),((s.ax >> 8) & 0xffu),8,flags);
  }
  L0076d8a8: { // 0x76d8a8: 74d2 JZ 0x0076d87c
    if(integer::condition("JZ",flags)) goto L0076d87c;
  }
  L0076d8aa: { // 0x76d8aa: 1ac0 SBB AL,AL
    s.ax = with_al(s.ax, integer::sub((s.ax & 0xffu),(s.ax & 0xffu),8,flags,flags&integer::CF));
  }
  L0076d8ac: { // 0x76d8ac: 1cff SBB AL,0xff
    s.ax = with_al(s.ax, integer::sub((s.ax & 0xffu),0x000000ffu,8,flags,flags&integer::CF));
  }
  L0076d8ae: { // 0x76d8ae: 0fbec0 MOVSX EAX,AL
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffu),8));
  }
  L0076d8b1: { // 0x76d8b1: eb78 JMP 0x0076d92b
    goto L0076d92b;
  }
  L0076d8b3: { // 0x76d8b3: f0ff05240eb100 INC.LOCK dword ptr [0x00b10e24]
    throw std::domain_error("252 locale branch excluded");
  }
  L0076d8ba: { // 0x76d8ba: 833d200eb10000 CMP dword ptr [0x00b10e20],0x0
    (void)integer::sub(m.r32((0x00b10e20u)),0x00000000u,32,flags);
  }
  L0076d8c1: { // 0x76d8c1: 7f04 JG 0x0076d8c7
    if(integer::condition("JG",flags)) goto L0076d8c7;
  }
  L0076d8c3: { // 0x76d8c3: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0076d8c5: { // 0x76d8c5: eb15 JMP 0x0076d8dc
    goto L0076d8dc;
  }
  L0076d8c7: { // 0x76d8c7: f0ff0d240eb100 DEC.LOCK dword ptr [0x00b10e24]
    throw std::domain_error("252 locale branch excluded");
  }
  L0076d8ce: { // 0x76d8ce: 6a13 PUSH 0x13
    f.push(m,0x00000013u);
  }
  L0076d8d0: { // 0x76d8d0: e8e13c0000 CALL 0x007715b6
    s.arithmetic_flags=flags; invoke(m,s,f,0x007715b6u,7788757u); flags=s.arithmetic_flags;
  }
  L0076d8d5: { // 0x76d8d5: c7042401000000 MOV dword ptr [ESP],0x1
    m.w32((f.sp), 0x00000001u);
  }
  L0076d8dc: { // 0x76d8dc: b8ff000000 MOV EAX,0xff
    s.ax = 0x000000ffu;
  }
  L0076d8e1: { // 0x76d8e1: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0076d8e3: { // 0x76d8e3: 90 NOP
    (void)0;
  }
  L0076d8e4: { // 0x76d8e4: 0ac0 OR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|((s.ax & 0xffu)),8,flags));
  }
  L0076d8e6: { // 0x76d8e6: 7427 JZ 0x0076d90f
    if(integer::condition("JZ",flags)) goto L0076d90f;
  }
  L0076d8e8: { // 0x76d8e8: 8a06 MOV AL,byte ptr [ESI]
    s.ax = with_al(s.ax, m.r8((s.si)));
  }
  L0076d8ea: { // 0x76d8ea: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0076d8eb: { // 0x76d8eb: 8a1f MOV BL,byte ptr [EDI]
    s.bx = with_al(s.bx, m.r8((s.di)));
  }
  L0076d8ed: { // 0x76d8ed: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0076d8ee: { // 0x76d8ee: 38d8 CMP AL,BL
    (void)integer::sub((s.ax & 0xffu),(s.bx & 0xffu),8,flags);
  }
  L0076d8f0: { // 0x76d8f0: 74f2 JZ 0x0076d8e4
    if(integer::condition("JZ",flags)) goto L0076d8e4;
  }
  L0076d8f2: { // 0x76d8f2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0076d8f3: { // 0x76d8f3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0076d8f4: { // 0x76d8f4: e8aa220000 CALL 0x0076fba3
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076fba3u,7788793u); flags=s.arithmetic_flags;
  }
  L0076d8f9: { // 0x76d8f9: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0076d8fb: { // 0x76d8fb: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0076d8fe: { // 0x76d8fe: e8a0220000 CALL 0x0076fba3
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076fba3u,7788803u); flags=s.arithmetic_flags;
  }
  L0076d903: { // 0x76d903: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0076d906: { // 0x76d906: 38c3 CMP BL,AL
    (void)integer::sub((s.bx & 0xffu),(s.ax & 0xffu),8,flags);
  }
  L0076d908: { // 0x76d908: 74da JZ 0x0076d8e4
    if(integer::condition("JZ",flags)) goto L0076d8e4;
  }
  L0076d90a: { // 0x76d90a: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  L0076d90c: { // 0x76d90c: 83d8ff SBB EAX,-0x1
    s.ax = integer::sub(s.ax,0xffffffffu,32,flags,flags&integer::CF);
  }
  L0076d90f: { // 0x76d90f: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0076d911: { // 0x76d911: 58 POP EAX
    const auto value=f.pop(m); s.ax = value;
  }
  L0076d912: { // 0x76d912: 0bc0 OR EAX,EAX
    s.ax = integer::logical((s.ax)|(s.ax),32,flags);
  }
  L0076d914: { // 0x76d914: 7509 JNZ 0x0076d91f
    if(integer::condition("JNZ",flags)) goto L0076d91f;
  }
  L0076d916: { // 0x76d916: f0ff0d240eb100 DEC.LOCK dword ptr [0x00b10e24]
    throw std::domain_error("252 locale branch excluded");
  }
  L0076d91d: { // 0x76d91d: eb0a JMP 0x0076d929
    goto L0076d929;
  }
  L0076d91f: { // 0x76d91f: 6a13 PUSH 0x13
    f.push(m,0x00000013u);
  }
  L0076d921: { // 0x76d921: e8f13c0000 CALL 0x00771617
    s.arithmetic_flags=flags; invoke(m,s,f,0x00771617u,7788838u); flags=s.arithmetic_flags;
  }
  L0076d926: { // 0x76d926: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0076d929: { // 0x76d929: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L0076d92b: { // 0x76d92b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0076d92c: { // 0x76d92c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076d92d: { // 0x76d92d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076d92e: { // 0x76d92e: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L0076d92f: { // 0x76d92f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00038b60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00438b60: { // 0x438b60: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L00438b64: { // 0x438b64: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00438b65: { // 0x438b65: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00438b66: { // 0x438b66: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00438b67: { // 0x438b67: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00438b68: { // 0x438b68: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00438b6a: { // 0x438b6a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00438b6b: { // 0x438b6b: e8b0d72700 CALL 0x006b6320
    s.arithmetic_flags=flags; invoke(m,s,f,0x006b6320u,4426608u); flags=s.arithmetic_flags;
  }
  L00438b70: { // 0x438b70: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L00438b74: { // 0x438b74: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00438b76: { // 0x438b76: 898e18040000 MOV dword ptr [ESI + 0x418],ECX
    m.w32((s.si+0x00000418u), s.cx);
  }
  L00438b7c: { // 0x438b7c: 899e1c040000 MOV dword ptr [ESI + 0x41c],EBX
    m.w32((s.si+0x0000041cu), s.bx);
  }
  L00438b82: { // 0x438b82: 8b156c89a200 MOV EDX,dword ptr [0x00a2896c]
    s.dx = m.r32((0x00a2896cu));
  }
  L00438b88: { // 0x438b88: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L00438b8b: { // 0x438b8b: 899620040000 MOV dword ptr [ESI + 0x420],EDX
    m.w32((s.si+0x00000420u), s.dx);
  }
  L00438b91: { // 0x438b91: 899e28040000 MOV dword ptr [ESI + 0x428],EBX
    m.w32((s.si+0x00000428u), s.bx);
  }
  L00438b97: { // 0x438b97: 89862c040000 MOV dword ptr [ESI + 0x42c],EAX
    m.w32((s.si+0x0000042cu), s.ax);
  }
  L00438b9d: { // 0x438b9d: 898630040000 MOV dword ptr [ESI + 0x430],EAX
    m.w32((s.si+0x00000430u), s.ax);
  }
  L00438ba3: { // 0x438ba3: 899e34040000 MOV dword ptr [ESI + 0x434],EBX
    m.w32((s.si+0x00000434u), s.bx);
  }
  L00438ba9: { // 0x438ba9: 899e38040000 MOV dword ptr [ESI + 0x438],EBX
    m.w32((s.si+0x00000438u), s.bx);
  }
  L00438baf: { // 0x438baf: 899e3c040000 MOV dword ptr [ESI + 0x43c],EBX
    m.w32((s.si+0x0000043cu), s.bx);
  }
  L00438bb5: { // 0x438bb5: 899e40040000 MOV dword ptr [ESI + 0x440],EBX
    m.w32((s.si+0x00000440u), s.bx);
  }
  L00438bbb: { // 0x438bbb: 899e44040000 MOV dword ptr [ESI + 0x444],EBX
    m.w32((s.si+0x00000444u), s.bx);
  }
  L00438bc1: { // 0x438bc1: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  L00438bc7: { // 0x438bc7: 898e48040000 MOV dword ptr [ESI + 0x448],ECX
    m.w32((s.si+0x00000448u), s.cx);
  }
  L00438bcd: { // 0x438bcd: 899e50040000 MOV dword ptr [ESI + 0x450],EBX
    m.w32((s.si+0x00000450u), s.bx);
  }
  L00438bd3: { // 0x438bd3: 889ebc040000 MOV byte ptr [ESI + 0x4bc],BL
    m.w8((s.si+0x000004bcu), (s.bx & 0xffu));
  }
  L00438bd9: { // 0x438bd9: 8986cc040000 MOV dword ptr [ESI + 0x4cc],EAX
    m.w32((s.si+0x000004ccu), s.ax);
  }
  L00438bdf: { // 0x438bdf: 8986d0040000 MOV dword ptr [ESI + 0x4d0],EAX
    m.w32((s.si+0x000004d0u), s.ax);
  }
  L00438be5: { // 0x438be5: 899ed4040000 MOV dword ptr [ESI + 0x4d4],EBX
    m.w32((s.si+0x000004d4u), s.bx);
  }
  L00438beb: { // 0x438beb: 8b156c89a200 MOV EDX,dword ptr [0x00a2896c]
    s.dx = m.r32((0x00a2896cu));
  }
  L00438bf1: { // 0x438bf1: 899ee0040000 MOV dword ptr [ESI + 0x4e0],EBX
    m.w32((s.si+0x000004e0u), s.bx);
  }
  L00438bf7: { // 0x438bf7: 8996d8040000 MOV dword ptr [ESI + 0x4d8],EDX
    m.w32((s.si+0x000004d8u), s.dx);
  }
  L00438bfd: { // 0x438bfd: 899ee4040000 MOV dword ptr [ESI + 0x4e4],EBX
    m.w32((s.si+0x000004e4u), s.bx);
  }
  L00438c03: { // 0x438c03: 899ee8040000 MOV dword ptr [ESI + 0x4e8],EBX
    m.w32((s.si+0x000004e8u), s.bx);
  }
  L00438c09: { // 0x438c09: 899eec040000 MOV dword ptr [ESI + 0x4ec],EBX
    m.w32((s.si+0x000004ecu), s.bx);
  }
  L00438c0f: { // 0x438c0f: 899ef0040000 MOV dword ptr [ESI + 0x4f0],EBX
    m.w32((s.si+0x000004f0u), s.bx);
  }
  L00438c15: { // 0x438c15: 899ef4040000 MOV dword ptr [ESI + 0x4f4],EBX
    m.w32((s.si+0x000004f4u), s.bx);
  }
  L00438c1b: { // 0x438c1b: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  L00438c21: { // 0x438c21: 899e00050000 MOV dword ptr [ESI + 0x500],EBX
    m.w32((s.si+0x00000500u), s.bx);
  }
  L00438c27: { // 0x438c27: 898ef8040000 MOV dword ptr [ESI + 0x4f8],ECX
    m.w32((s.si+0x000004f8u), s.cx);
  }
  L00438c2d: { // 0x438c2d: 899e04050000 MOV dword ptr [ESI + 0x504],EBX
    m.w32((s.si+0x00000504u), s.bx);
  }
  L00438c33: { // 0x438c33: c7860805000001000000 MOV dword ptr [ESI + 0x508],0x1
    m.w32((s.si+0x00000508u), 0x00000001u);
  }
  L00438c3d: { // 0x438c3d: 8b0d48708300 MOV ECX,dword ptr [0x00837048]
    s.cx = m.r32((0x00837048u));
  }
  L00438c43: { // 0x438c43: 8d960c050000 LEA EDX,[ESI + 0x50c]
    s.dx = (s.si+0x0000050cu);
  }
  L00438c49: { // 0x438c49: 898e0c050000 MOV dword ptr [ESI + 0x50c],ECX
    m.w32((s.si+0x0000050cu), s.cx);
  }
  L00438c4f: { // 0x438c4f: 8b0d4c708300 MOV ECX,dword ptr [0x0083704c]
    s.cx = m.r32((0x0083704cu));
  }
  L00438c55: { // 0x438c55: 894a04 MOV dword ptr [EDX + 0x4],ECX
    m.w32((s.dx+0x00000004u), s.cx);
  }
  L00438c58: { // 0x438c58: 8b0d50708300 MOV ECX,dword ptr [0x00837050]
    s.cx = m.r32((0x00837050u));
  }
  L00438c5e: { // 0x438c5e: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  L00438c61: { // 0x438c61: 8b0d54708300 MOV ECX,dword ptr [0x00837054]
    s.cx = m.r32((0x00837054u));
  }
  L00438c67: { // 0x438c67: 894a0c MOV dword ptr [EDX + 0xc],ECX
    m.w32((s.dx+0x0000000cu), s.cx);
  }
  L00438c6a: { // 0x438c6a: 8b0d78708300 MOV ECX,dword ptr [0x00837078]
    s.cx = m.r32((0x00837078u));
  }
  L00438c70: { // 0x438c70: 8d961c050000 LEA EDX,[ESI + 0x51c]
    s.dx = (s.si+0x0000051cu);
  }
  L00438c76: { // 0x438c76: 898e1c050000 MOV dword ptr [ESI + 0x51c],ECX
    m.w32((s.si+0x0000051cu), s.cx);
  }
  L00438c7c: { // 0x438c7c: 8b0d7c708300 MOV ECX,dword ptr [0x0083707c]
    s.cx = m.r32((0x0083707cu));
  }
  L00438c82: { // 0x438c82: 894a04 MOV dword ptr [EDX + 0x4],ECX
    m.w32((s.dx+0x00000004u), s.cx);
  }
  L00438c85: { // 0x438c85: 8b0d80708300 MOV ECX,dword ptr [0x00837080]
    s.cx = m.r32((0x00837080u));
  }
  L00438c8b: { // 0x438c8b: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  L00438c8e: { // 0x438c8e: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00438c90: { // 0x438c90: 898e28050000 MOV dword ptr [ESI + 0x528],ECX
    m.w32((s.si+0x00000528u), s.cx);
  }
  L00438c96: { // 0x438c96: 899e2c050000 MOV dword ptr [ESI + 0x52c],EBX
    m.w32((s.si+0x0000052cu), s.bx);
  }
  L00438c9c: { // 0x438c9c: c6863005000001 MOV byte ptr [ESI + 0x530],0x1
    m.w8((s.si+0x00000530u), 0x00000001u);
  }
  L00438ca3: { // 0x438ca3: 889e31050000 MOV byte ptr [ESI + 0x531],BL
    m.w8((s.si+0x00000531u), (s.bx & 0xffu));
  }
  L00438ca9: { // 0x438ca9: 899e34050000 MOV dword ptr [ESI + 0x534],EBX
    m.w32((s.si+0x00000534u), s.bx);
  }
  L00438caf: { // 0x438caf: 889e38050000 MOV byte ptr [ESI + 0x538],BL
    m.w8((s.si+0x00000538u), (s.bx & 0xffu));
  }
  L00438cb5: { // 0x438cb5: b954807800 MOV ECX,0x788054
    s.cx = 0x00788054u;
  }
  L00438cba: { // 0x438cba: ba0a000000 MOV EDX,0xa
    s.dx = 0x0000000au;
  }
  L00438cbf: { // 0x438cbf: 889e39050000 MOV byte ptr [ESI + 0x539],BL
    m.w8((s.si+0x00000539u), (s.bx & 0xffu));
  }
  L00438cc5: { // 0x438cc5: 899e40050000 MOV dword ptr [ESI + 0x540],EBX
    m.w32((s.si+0x00000540u), s.bx);
  }
  L00438ccb: { // 0x438ccb: 899e44050000 MOV dword ptr [ESI + 0x544],EBX
    m.w32((s.si+0x00000544u), s.bx);
  }
  L00438cd1: { // 0x438cd1: c6864805000001 MOV byte ptr [ESI + 0x548],0x1
    m.w8((s.si+0x00000548u), 0x00000001u);
  }
  L00438cd8: { // 0x438cd8: 889e49050000 MOV byte ptr [ESI + 0x549],BL
    m.w8((s.si+0x00000549u), (s.bx & 0xffu));
  }
  L00438cde: { // 0x438cde: 898e3c050000 MOV dword ptr [ESI + 0x53c],ECX
    m.w32((s.si+0x0000053cu), s.cx);
  }
  L00438ce4: { // 0x438ce4: 899650050000 MOV dword ptr [ESI + 0x550],EDX
    m.w32((s.si+0x00000550u), s.dx);
  }
  L00438cea: { // 0x438cea: 899e4c050000 MOV dword ptr [ESI + 0x54c],EBX
    m.w32((s.si+0x0000054cu), s.bx);
  }
  L00438cf0: { // 0x438cf0: 899e58050000 MOV dword ptr [ESI + 0x558],EBX
    m.w32((s.si+0x00000558u), s.bx);
  }
  L00438cf6: { // 0x438cf6: 899e5c050000 MOV dword ptr [ESI + 0x55c],EBX
    m.w32((s.si+0x0000055cu), s.bx);
  }
  L00438cfc: { // 0x438cfc: c6866005000001 MOV byte ptr [ESI + 0x560],0x1
    m.w8((s.si+0x00000560u), 0x00000001u);
  }
  L00438d03: { // 0x438d03: 889e61050000 MOV byte ptr [ESI + 0x561],BL
    m.w8((s.si+0x00000561u), (s.bx & 0xffu));
  }
  L00438d09: { // 0x438d09: 898e54050000 MOV dword ptr [ESI + 0x554],ECX
    m.w32((s.si+0x00000554u), s.cx);
  }
  L00438d0f: { // 0x438d0f: 899668050000 MOV dword ptr [ESI + 0x568],EDX
    m.w32((s.si+0x00000568u), s.dx);
  }
  L00438d15: { // 0x438d15: 899e64050000 MOV dword ptr [ESI + 0x564],EBX
    m.w32((s.si+0x00000564u), s.bx);
  }
  L00438d1b: { // 0x438d1b: 899e6c050000 MOV dword ptr [ESI + 0x56c],EBX
    m.w32((s.si+0x0000056cu), s.bx);
  }
  L00438d21: { // 0x438d21: 889e98050000 MOV byte ptr [ESI + 0x598],BL
    m.w8((s.si+0x00000598u), (s.bx & 0xffu));
  }
  L00438d27: { // 0x438d27: 889e99050000 MOV byte ptr [ESI + 0x599],BL
    m.w8((s.si+0x00000599u), (s.bx & 0xffu));
  }
  L00438d2d: { // 0x438d2d: 889e9a050000 MOV byte ptr [ESI + 0x59a],BL
    m.w8((s.si+0x0000059au), (s.bx & 0xffu));
  }
  L00438d33: { // 0x438d33: 889e9b050000 MOV byte ptr [ESI + 0x59b],BL
    m.w8((s.si+0x0000059bu), (s.bx & 0xffu));
  }
  L00438d39: { // 0x438d39: 889e9c050000 MOV byte ptr [ESI + 0x59c],BL
    m.w8((s.si+0x0000059cu), (s.bx & 0xffu));
  }
  L00438d3f: { // 0x438d3f: 8b156c89a200 MOV EDX,dword ptr [0x00a2896c]
    s.dx = m.r32((0x00a2896cu));
  }
  L00438d45: { // 0x438d45: 8d6e04 LEA EBP,[ESI + 0x4]
    s.bp = (s.si+0x00000004u);
  }
  L00438d48: { // 0x438d48: 8996a0050000 MOV dword ptr [ESI + 0x5a0],EDX
    m.w32((s.si+0x000005a0u), s.dx);
  }
  L00438d4e: { // 0x438d4e: 899ea8050000 MOV dword ptr [ESI + 0x5a8],EBX
    m.w32((s.si+0x000005a8u), s.bx);
  }
  L00438d54: { // 0x438d54: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00438d55: { // 0x438d55: c686ac05000001 MOV byte ptr [ESI + 0x5ac],0x1
    m.w8((s.si+0x000005acu), 0x00000001u);
  }
  L00438d5c: { // 0x438d5c: 889ead050000 MOV byte ptr [ESI + 0x5ad],BL
    m.w8((s.si+0x000005adu), (s.bx & 0xffu));
  }
  L00438d62: { // 0x438d62: 889eae050000 MOV byte ptr [ESI + 0x5ae],BL
    m.w8((s.si+0x000005aeu), (s.bx & 0xffu));
  }
  L00438d68: { // 0x438d68: 889eaf050000 MOV byte ptr [ESI + 0x5af],BL
    m.w8((s.si+0x000005afu), (s.bx & 0xffu));
  }
  L00438d6e: { // 0x438d6e: 889eb0050000 MOV byte ptr [ESI + 0x5b0],BL
    m.w8((s.si+0x000005b0u), (s.bx & 0xffu));
  }
  L00438d74: { // 0x438d74: 889eb1050000 MOV byte ptr [ESI + 0x5b1],BL
    m.w8((s.si+0x000005b1u), (s.bx & 0xffu));
  }
  L00438d7a: { // 0x438d7a: 889eb2050000 MOV byte ptr [ESI + 0x5b2],BL
    m.w8((s.si+0x000005b2u), (s.bx & 0xffu));
  }
  L00438d80: { // 0x438d80: 889eb3050000 MOV byte ptr [ESI + 0x5b3],BL
    m.w8((s.si+0x000005b3u), (s.bx & 0xffu));
  }
  L00438d86: { // 0x438d86: 889eb4050000 MOV byte ptr [ESI + 0x5b4],BL
    m.w8((s.si+0x000005b4u), (s.bx & 0xffu));
  }
  L00438d8c: { // 0x438d8c: 889eb5050000 MOV byte ptr [ESI + 0x5b5],BL
    m.w8((s.si+0x000005b5u), (s.bx & 0xffu));
  }
  L00438d92: { // 0x438d92: 889eb6050000 MOV byte ptr [ESI + 0x5b6],BL
    m.w8((s.si+0x000005b6u), (s.bx & 0xffu));
  }
  L00438d98: { // 0x438d98: 889eb7050000 MOV byte ptr [ESI + 0x5b7],BL
    m.w8((s.si+0x000005b7u), (s.bx & 0xffu));
  }
  L00438d9e: { // 0x438d9e: 889eb8050000 MOV byte ptr [ESI + 0x5b8],BL
    m.w8((s.si+0x000005b8u), (s.bx & 0xffu));
  }
  L00438da4: { // 0x438da4: 889eb9050000 MOV byte ptr [ESI + 0x5b9],BL
    m.w8((s.si+0x000005b9u), (s.bx & 0xffu));
  }
  L00438daa: { // 0x438daa: c686ba05000001 MOV byte ptr [ESI + 0x5ba],0x1
    m.w8((s.si+0x000005bau), 0x00000001u);
  }
  L00438db1: { // 0x438db1: 889ebb050000 MOV byte ptr [ESI + 0x5bb],BL
    m.w8((s.si+0x000005bbu), (s.bx & 0xffu));
  }
  L00438db7: { // 0x438db7: 889ebc050000 MOV byte ptr [ESI + 0x5bc],BL
    m.w8((s.si+0x000005bcu), (s.bx & 0xffu));
  }
  L00438dbd: { // 0x438dbd: 889ebd050000 MOV byte ptr [ESI + 0x5bd],BL
    m.w8((s.si+0x000005bdu), (s.bx & 0xffu));
  }
  L00438dc3: { // 0x438dc3: 899ec0050000 MOV dword ptr [ESI + 0x5c0],EBX
    m.w32((s.si+0x000005c0u), s.bx);
  }
  L00438dc9: { // 0x438dc9: 66c786c4050000e803 MOV word ptr [ESI + 0x5c4],0x3e8
    m.w16((s.si+0x000005c4u), 0x000003e8u);
  }
  L00438dd2: { // 0x438dd2: 889ec6050000 MOV byte ptr [ESI + 0x5c6],BL
    m.w8((s.si+0x000005c6u), (s.bx & 0xffu));
  }
  L00438dd8: { // 0x438dd8: 8886c7050000 MOV byte ptr [ESI + 0x5c7],AL
    m.w8((s.si+0x000005c7u), (s.ax & 0xffu));
  }
  L00438dde: { // 0x438dde: 899ec8050000 MOV dword ptr [ESI + 0x5c8],EBX
    m.w32((s.si+0x000005c8u), s.bx);
  }
  L00438de4: { // 0x438de4: 899ed8050000 MOV dword ptr [ESI + 0x5d8],EBX
    m.w32((s.si+0x000005d8u), s.bx);
  }
  L00438dea: { // 0x438dea: c706bc7b7800 MOV dword ptr [ESI],0x787bbc
    m.w32((s.si), 0x00787bbcu);
  }
  L00438df0: { // 0x438df0: c74500a07b7800 MOV dword ptr [EBP],0x787ba0
    m.w32((s.bp), 0x00787ba0u);
  }
  L00438df7: { // 0x438df7: c74608987b7800 MOV dword ptr [ESI + 0x8],0x787b98
    m.w32((s.si+0x00000008u), 0x00787b98u);
  }
  L00438dfe: { // 0x438dfe: c7460c907b7800 MOV dword ptr [ESI + 0xc],0x787b90
    m.w32((s.si+0x0000000cu), 0x00787b90u);
  }
  L00438e05: { // 0x438e05: e8c671fdff CALL 0x0040ffd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0040ffd0u,4427274u); flags=s.arithmetic_flags;
  }
  L00438e0a: { // 0x438e0a: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00438e0c: { // 0x438e0c: 8d96cc050000 LEA EDX,[ESI + 0x5cc]
    s.dx = (s.si+0x000005ccu);
  }
  L00438e12: { // 0x438e12: 8986c0040000 MOV dword ptr [ESI + 0x4c0],EAX
    m.w32((s.si+0x000004c0u), s.ax);
  }
  L00438e18: { // 0x438e18: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00438e1a: { // 0x438e1a: 8986c4040000 MOV dword ptr [ESI + 0x4c4],EAX
    m.w32((s.si+0x000004c4u), s.ax);
  }
  L00438e20: { // 0x438e20: 8986c8040000 MOV dword ptr [ESI + 0x4c8],EAX
    m.w32((s.si+0x000004c8u), s.ax);
  }
  L00438e26: { // 0x438e26: 8902 MOV dword ptr [EDX],EAX
    m.w32((s.dx), s.ax);
  }
  L00438e28: { // 0x438e28: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L00438e2e: { // 0x438e2e: 894a04 MOV dword ptr [EDX + 0x4],ECX
    m.w32((s.dx+0x00000004u), s.cx);
  }
  L00438e31: { // 0x438e31: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00438e33: { // 0x438e33: 895a08 MOV dword ptr [EDX + 0x8],EBX
    m.w32((s.dx+0x00000008u), s.bx);
  }
  L00438e36: { // 0x438e36: 741b JZ 0x00438e53
    if(integer::condition("JZ",flags)) goto L00438e53;
  }
  L00438e38: { // 0x438e38: 8aa894130000 MOV CH,byte ptr [EAX + 0x1394]
    s.cx = (s.cx & 0xffff00ffu) | (((m.r8((s.ax+0x00001394u))) & 0xffu) << 8);
  }
  L00438e3e: { // 0x438e3e: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L00438e42: { // 0x438e42: 66894c2418 MOV word ptr [ESP + 0x18],CX
    m.w16((f.sp+0x00000018u), (s.cx & 0xffffu));
  }
  L00438e47: { // 0x438e47: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00438e48: { // 0x438e48: 8d8ec8020000 LEA ECX,[ESI + 0x2c8]
    s.cx = (s.si+0x000002c8u);
  }
  L00438e4e: { // 0x438e4e: e84df80700 CALL 0x004b86a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004b86a0u,4427347u); flags=s.arithmetic_flags;
  }
  L00438e53: { // 0x438e53: b912000000 MOV ECX,0x12
    s.cx = 0x00000012u;
  }
  L00438e58: { // 0x438e58: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00438e5a: { // 0x438e5a: 8dbe54040000 LEA EDI,[ESI + 0x454]
    s.di = (s.si+0x00000454u);
  }
  L00438e60: { // 0x438e60: f3ab STOSD.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::count);
  }
  L00438e62: { // 0x438e62: 8dbe9c040000 LEA EDI,[ESI + 0x49c]
    s.di = (s.si+0x0000049cu);
  }
  L00438e68: { // 0x438e68: b908000000 MOV ECX,0x8
    s.cx = 0x00000008u;
  }
  L00438e6d: { // 0x438e6d: f3ab STOSD.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::count);
  }
  L00438e6f: { // 0x438e6f: 8d8e70050000 LEA ECX,[ESI + 0x570]
    s.cx = (s.si+0x00000570u);
  }
  L00438e75: { // 0x438e75: e876cdfcff CALL 0x00405bf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00405bf0u,4427386u); flags=s.arithmetic_flags;
  }
  L00438e7a: { // 0x438e7a: 8d8e84050000 LEA ECX,[ESI + 0x584]
    s.cx = (s.si+0x00000584u);
  }
  L00438e80: { // 0x438e80: e86bcdfcff CALL 0x00405bf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00405bf0u,4427397u); flags=s.arithmetic_flags;
  }
  L00438e85: { // 0x438e85: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L00438e89: { // 0x438e89: 8d8ec8020000 LEA ECX,[ESI + 0x2c8]
    s.cx = (s.si+0x000002c8u);
  }
  L00438e8f: { // 0x438e8f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00438e90: { // 0x438e90: 66c744241c0040 MOV word ptr [ESP + 0x1c],0x4000
    m.w16((f.sp+0x0000001cu), 0x00004000u);
  }
  L00438e97: { // 0x438e97: e804f80700 CALL 0x004b86a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004b86a0u,4427420u); flags=s.arithmetic_flags;
  }
  L00438e9c: { // 0x438e9c: 899ef4040000 MOV dword ptr [ESI + 0x4f4],EBX
    m.w32((s.si+0x000004f4u), s.bx);
  }
  L00438ea2: { // 0x438ea2: a14087a200 MOV EAX,[0x00a28740]
    s.ax = m.r32((0x00a28740u));
  }
  L00438ea7: { // 0x438ea7: 39054887a200 CMP dword ptr [0x00a28748],EAX
    (void)integer::sub(m.r32((0x00a28748u)),s.ax,32,flags);
  }
  L00438ead: { // 0x438ead: 7c2c JL 0x00438edb
    if(integer::condition("JL",flags)) goto L00438edb;
  }
  L00438eaf: { // 0x438eaf: 381d4587a200 CMP byte ptr [0x00a28745],BL
    (void)integer::sub(m.r8((0x00a28745u)),(s.bx & 0xffu),8,flags);
  }
  L00438eb5: { // 0x438eb5: 7504 JNZ 0x00438ebb
    if(integer::condition("JNZ",flags)) goto L00438ebb;
  }
  L00438eb7: { // 0x438eb7: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00438eb9: { // 0x438eb9: 7538 JNZ 0x00438ef3
    if(integer::condition("JNZ",flags)) goto L00438ef3;
  }
  L00438ebb: { // 0x438ebb: 8b0d4c87a200 MOV ECX,dword ptr [0x00a2874c]
    s.cx = m.r32((0x00a2874cu));
  }
  L00438ec1: { // 0x438ec1: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L00438ec3: { // 0x438ec3: 7e2e JLE 0x00438ef3
    if(integer::condition("JLE",flags)) goto L00438ef3;
  }
  L00438ec5: { // 0x438ec5: 8b153887a200 MOV EDX,dword ptr [0x00a28738]
    s.dx = m.r32((0x00a28738u));
  }
  L00438ecb: { // 0x438ecb: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00438ecd: { // 0x438ecd: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00438ece: { // 0x438ece: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00438ecf: { // 0x438ecf: b93887a200 MOV ECX,0xa28738
    s.cx = 0x00a28738u;
  }
  L00438ed4: { // 0x438ed4: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),4427479u); flags=s.arithmetic_flags;
  }
  L00438ed7: { // 0x438ed7: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00438ed9: { // 0x438ed9: 7418 JZ 0x00438ef3
    if(integer::condition("JZ",flags)) goto L00438ef3;
  }
  L00438edb: { // 0x438edb: 8b0d4887a200 MOV ECX,dword ptr [0x00a28748]
    s.cx = m.r32((0x00a28748u));
  }
  L00438ee1: { // 0x438ee1: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00438ee3: { // 0x438ee3: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00438ee4: { // 0x438ee4: 890d4887a200 MOV dword ptr [0x00a28748],ECX
    m.w32((0x00a28748u), s.cx);
  }
  L00438eea: { // 0x438eea: 8b0d3c87a200 MOV ECX,dword ptr [0x00a2873c]
    s.cx = m.r32((0x00a2873cu));
  }
  L00438ef0: { // 0x438ef0: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L00438ef3: { // 0x438ef3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00438ef5: { // 0x438ef5: e8d6660000 CALL 0x0043f5d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0043f5d0u,4427514u); flags=s.arithmetic_flags;
  }
  L00438efa: { // 0x438efa: a19087aa00 MOV EAX,[0x00aa8790]
    s.ax = m.r32((0x00aa8790u));
  }
  L00438eff: { // 0x438eff: 8b0d9887aa00 MOV ECX,dword ptr [0x00aa8798]
    s.cx = m.r32((0x00aa8798u));
  }
  L00438f05: { // 0x438f05: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00438f07: { // 0x438f07: 7c2c JL 0x00438f35
    if(integer::condition("JL",flags)) goto L00438f35;
  }
  L00438f09: { // 0x438f09: 381d9587aa00 CMP byte ptr [0x00aa8795],BL
    (void)integer::sub(m.r8((0x00aa8795u)),(s.bx & 0xffu),8,flags);
  }
  L00438f0f: { // 0x438f0f: 7504 JNZ 0x00438f15
    if(integer::condition("JNZ",flags)) goto L00438f15;
  }
  L00438f11: { // 0x438f11: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00438f13: { // 0x438f13: 7538 JNZ 0x00438f4d
    if(integer::condition("JNZ",flags)) goto L00438f4d;
  }
  L00438f15: { // 0x438f15: 8b0d9c87aa00 MOV ECX,dword ptr [0x00aa879c]
    s.cx = m.r32((0x00aa879cu));
  }
  L00438f1b: { // 0x438f1b: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L00438f1d: { // 0x438f1d: 7e2e JLE 0x00438f4d
    if(integer::condition("JLE",flags)) goto L00438f4d;
  }
  L00438f1f: { // 0x438f1f: 8b158887aa00 MOV EDX,dword ptr [0x00aa8788]
    s.dx = m.r32((0x00aa8788u));
  }
  L00438f25: { // 0x438f25: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00438f27: { // 0x438f27: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00438f28: { // 0x438f28: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00438f29: { // 0x438f29: b98887aa00 MOV ECX,0xaa8788
    s.cx = 0x00aa8788u;
  }
  L00438f2e: { // 0x438f2e: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),4427569u); flags=s.arithmetic_flags;
  }
  L00438f31: { // 0x438f31: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00438f33: { // 0x438f33: 7418 JZ 0x00438f4d
    if(integer::condition("JZ",flags)) goto L00438f4d;
  }
  L00438f35: { // 0x438f35: 8b0d9887aa00 MOV ECX,dword ptr [0x00aa8798]
    s.cx = m.r32((0x00aa8798u));
  }
  L00438f3b: { // 0x438f3b: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00438f3d: { // 0x438f3d: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00438f3e: { // 0x438f3e: 890d9887aa00 MOV dword ptr [0x00aa8798],ECX
    m.w32((0x00aa8798u), s.cx);
  }
  L00438f44: { // 0x438f44: 8b0d8c87aa00 MOV ECX,dword ptr [0x00aa878c]
    s.cx = m.r32((0x00aa878cu));
  }
  L00438f4a: { // 0x438f4a: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L00438f4d: { // 0x438f4d: a10887aa00 MOV EAX,[0x00aa8708]
    s.ax = m.r32((0x00aa8708u));
  }
  L00438f52: { // 0x438f52: 8b0d1087aa00 MOV ECX,dword ptr [0x00aa8710]
    s.cx = m.r32((0x00aa8710u));
  }
  L00438f58: { // 0x438f58: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00438f5a: { // 0x438f5a: 7c2c JL 0x00438f88
    if(integer::condition("JL",flags)) goto L00438f88;
  }
  L00438f5c: { // 0x438f5c: 381d0d87aa00 CMP byte ptr [0x00aa870d],BL
    (void)integer::sub(m.r8((0x00aa870du)),(s.bx & 0xffu),8,flags);
  }
  L00438f62: { // 0x438f62: 7504 JNZ 0x00438f68
    if(integer::condition("JNZ",flags)) goto L00438f68;
  }
  L00438f64: { // 0x438f64: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00438f66: { // 0x438f66: 7538 JNZ 0x00438fa0
    if(integer::condition("JNZ",flags)) goto L00438fa0;
  }
  L00438f68: { // 0x438f68: 8b0d1487aa00 MOV ECX,dword ptr [0x00aa8714]
    s.cx = m.r32((0x00aa8714u));
  }
  L00438f6e: { // 0x438f6e: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L00438f70: { // 0x438f70: 7e2e JLE 0x00438fa0
    if(integer::condition("JLE",flags)) goto L00438fa0;
  }
  L00438f72: { // 0x438f72: 8b150087aa00 MOV EDX,dword ptr [0x00aa8700]
    s.dx = m.r32((0x00aa8700u));
  }
  L00438f78: { // 0x438f78: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00438f7a: { // 0x438f7a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00438f7b: { // 0x438f7b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00438f7c: { // 0x438f7c: b90087aa00 MOV ECX,0xaa8700
    s.cx = 0x00aa8700u;
  }
  L00438f81: { // 0x438f81: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),4427652u); flags=s.arithmetic_flags;
  }
  L00438f84: { // 0x438f84: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00438f86: { // 0x438f86: 7418 JZ 0x00438fa0
    if(integer::condition("JZ",flags)) goto L00438fa0;
  }
  L00438f88: { // 0x438f88: 8b0d1087aa00 MOV ECX,dword ptr [0x00aa8710]
    s.cx = m.r32((0x00aa8710u));
  }
  L00438f8e: { // 0x438f8e: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00438f90: { // 0x438f90: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00438f91: { // 0x438f91: 890d1087aa00 MOV dword ptr [0x00aa8710],ECX
    m.w32((0x00aa8710u), s.cx);
  }
  L00438f97: { // 0x438f97: 8b0d0487aa00 MOV ECX,dword ptr [0x00aa8704]
    s.cx = m.r32((0x00aa8704u));
  }
  L00438f9d: { // 0x438f9d: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L00438fa0: { // 0x438fa0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00438fa1: { // 0x438fa1: e81a70fdff CALL 0x0040ffc0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0040ffc0u,4427686u); flags=s.arithmetic_flags;
  }
  L00438fa6: { // 0x438fa6: 8b15647aaa00 MOV EDX,dword ptr [0x00aa7a64]
    s.dx = m.r32((0x00aa7a64u));
  }
  L00438fac: { // 0x438fac: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00438fb0: { // 0x438fb0: a1687aaa00 MOV EAX,[0x00aa7a68]
    s.ax = m.r32((0x00aa7a68u));
  }
  L00438fb5: { // 0x438fb5: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L00438fb6: { // 0x438fb6: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L00438fb8: { // 0x438fb8: 0f8e8e000000 JLE 0x0043904c
    if(integer::condition("JLE",flags)) goto L0043904c;
  }
  L00438fbe: { // 0x438fbe: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00438fc0: { // 0x438fc0: 7507 JNZ 0x00438fc9
    if(integer::condition("JNZ",flags)) goto L00438fc9;
  }
  L00438fc2: { // 0x438fc2: bd0a000000 MOV EBP,0xa
    s.bp = 0x0000000au;
  }
  L00438fc7: { // 0x438fc7: eb0a JMP 0x00438fd3
    goto L00438fd3;
  }
  L00438fc9: { // 0x438fc9: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L00438fcb: { // 0x438fcb: 3beb CMP EBP,EBX
    (void)integer::sub(s.bp,s.bx,32,flags);
  }
  L00438fcd: { // 0x438fcd: 0f8cac000000 JL 0x0043907f
    if(integer::condition("JL",flags)) goto L0043907f;
  }
  L00438fd3: { // 0x438fd3: 03c5 ADD EAX,EBP
    s.ax = integer::add(s.ax,s.bp,32,flags);
  }
  L00438fd5: { // 0x438fd5: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00438fd9: { // 0x438fd9: c1e003 SHL EAX,0x3
    s.ax = integer::shift(s.ax,0x00000003u,32,flags,integer::Shift::left);
  }
  L00438fdc: { // 0x438fdc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00438fdd: { // 0x438fdd: e875493300 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,4427746u); flags=s.arithmetic_flags;
  }
  L00438fe2: { // 0x438fe2: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00438fe4: { // 0x438fe4: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00438fe7: { // 0x438fe7: 3bfb CMP EDI,EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  L00438fe9: { // 0x438fe9: 0f8490000000 JZ 0x0043907f
    if(integer::condition("JZ",flags)) goto L0043907f;
  }
  L00438fef: { // 0x438fef: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L00438ff3: { // 0x438ff3: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00438ff5: { // 0x438ff5: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00438ff6: { // 0x438ff6: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L00438ffa: { // 0x438ffa: 8b0d647aaa00 MOV ECX,dword ptr [0x00aa7a64]
    s.cx = m.r32((0x00aa7a64u));
  }
  L00439000: { // 0x439000: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L00439002: { // 0x439002: 7e21 JLE 0x00439025
    if(integer::condition("JLE",flags)) goto L00439025;
  }
  L00439004: { // 0x439004: 8b15607aaa00 MOV EDX,dword ptr [0x00aa7a60]
    s.dx = m.r32((0x00aa7a60u));
  }
  L0043900a: { // 0x43900a: 8d0cc2 LEA ECX,[EDX + EAX*0x8]
    s.cx = (s.dx+(s.ax * 0x00000008u));
  }
  L0043900d: { // 0x43900d: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0043900e: { // 0x43900e: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00439010: { // 0x439010: 8954c7f8 MOV dword ptr [EDI + EAX*0x8 + -0x8],EDX
    m.w32((s.di+(s.ax * 0x00000008u)-0x00000008u), s.dx);
  }
  L00439014: { // 0x439014: 8b4904 MOV ECX,dword ptr [ECX + 0x4]
    s.cx = m.r32((s.cx+0x00000004u));
  }
  L00439017: { // 0x439017: 894cc7fc MOV dword ptr [EDI + EAX*0x8 + -0x4],ECX
    m.w32((s.di+(s.ax * 0x00000008u)-0x00000004u), s.cx);
  }
  L0043901b: { // 0x43901b: 8b0d647aaa00 MOV ECX,dword ptr [0x00aa7a64]
    s.cx = m.r32((0x00aa7a64u));
  }
  L00439021: { // 0x439021: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00439023: { // 0x439023: 7cdf JL 0x00439004
    if(integer::condition("JL",flags)) goto L00439004;
  }
  L00439025: { // 0x439025: 8b15607aaa00 MOV EDX,dword ptr [0x00aa7a60]
    s.dx = m.r32((0x00aa7a60u));
  }
  L0043902b: { // 0x43902b: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0043902c: { // 0x43902c: e84a463300 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,4427825u); flags=s.arithmetic_flags;
  }
  L00439031: { // 0x439031: a1687aaa00 MOV EAX,[0x00aa7a68]
    s.ax = m.r32((0x00aa7a68u));
  }
  L00439036: { // 0x439036: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00439039: { // 0x439039: 03c5 ADD EAX,EBP
    s.ax = integer::add(s.ax,s.bp,32,flags);
  }
  L0043903b: { // 0x43903b: 893d607aaa00 MOV dword ptr [0x00aa7a60],EDI
    m.w32((0x00aa7a60u), s.di);
  }
  L00439041: { // 0x439041: a3687aaa00 MOV [0x00aa7a68],EAX
    m.w32((0x00aa7a68u), s.ax);
  }
  L00439046: { // 0x439046: 891d707aaa00 MOV dword ptr [0x00aa7a70],EBX
    m.w32((0x00aa7a70u), s.bx);
  }
  L0043904c: { // 0x43904c: 8b0d607aaa00 MOV ECX,dword ptr [0x00aa7a60]
    s.cx = m.r32((0x00aa7a60u));
  }
  L00439052: { // 0x439052: 8b15647aaa00 MOV EDX,dword ptr [0x00aa7a64]
    s.dx = m.r32((0x00aa7a64u));
  }
  L00439058: { // 0x439058: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0043905c: { // 0x43905c: 8904d1 MOV dword ptr [ECX + EDX*0x8],EAX
    m.w32((s.cx+(s.dx * 0x00000008u)), s.ax);
  }
  L0043905f: { // 0x43905f: a1647aaa00 MOV EAX,[0x00aa7a64]
    s.ax = m.r32((0x00aa7a64u));
  }
  L00439064: { // 0x439064: 8b0d607aaa00 MOV ECX,dword ptr [0x00aa7a60]
    s.cx = m.r32((0x00aa7a60u));
  }
  L0043906a: { // 0x43906a: 8974c104 MOV dword ptr [ECX + EAX*0x8 + 0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000008u)+0x00000004u), s.si);
  }
  L0043906e: { // 0x43906e: a1647aaa00 MOV EAX,[0x00aa7a64]
    s.ax = m.r32((0x00aa7a64u));
  }
  L00439073: { // 0x439073: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00439074: { // 0x439074: 881d6c7aaa00 MOV byte ptr [0x00aa7a6c],BL
    m.w8((0x00aa7a6cu), (s.bx & 0xffu));
  }
  L0043907a: { // 0x43907a: a3647aaa00 MOV [0x00aa7a64],EAX
    m.w32((0x00aa7a64u), s.ax);
  }
  L0043907f: { // 0x43907f: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L00439085: { // 0x439085: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00439087: { // 0x439087: 7421 JZ 0x004390aa
    if(integer::condition("JZ",flags)) goto L004390aa;
  }
  L00439089: { // 0x439089: 8b8000140000 MOV EAX,dword ptr [EAX + 0x1400]
    s.ax = m.r32((s.ax+0x00001400u));
  }
  L0043908f: { // 0x43908f: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L00439092: { // 0x439092: 7d05 JGE 0x00439099
    if(integer::condition("JGE",flags)) goto L00439099;
  }
  L00439094: { // 0x439094: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L00439099: { // 0x439099: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0043909a: { // 0x43909a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0043909c: { // 0x43909c: e83f541f00 CALL 0x0062e4e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062e4e0u,4427937u); flags=s.arithmetic_flags;
  }
  L004390a1: { // 0x4390a1: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004390a3: { // 0x4390a3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004390a4: { // 0x4390a4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004390a5: { // 0x4390a5: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004390a6: { // 0x4390a6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004390a7: { // 0x4390a7: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L004390aa: { // 0x4390aa: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L004390ac: { // 0x4390ac: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004390ae: { // 0x4390ae: e82d541f00 CALL 0x0062e4e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062e4e0u,4427955u); flags=s.arithmetic_flags;
  }
  L004390b3: { // 0x4390b3: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004390b5: { // 0x4390b5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004390b6: { // 0x4390b6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004390b7: { // 0x4390b7: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004390b8: { // 0x4390b8: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004390b9: { // 0x4390b9: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_002b6320(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006b6320: { // 0x6b6320: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006b6321: { // 0x6b6321: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006b6322: { // 0x6b6322: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006b6323: { // 0x6b6323: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006b6324: { // 0x6b6324: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006b6326: { // 0x6b6326: e8a57af7ff CALL 0x0062ddd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062ddd0u,7037739u); flags=s.arithmetic_flags;
  }
  L006b632b: { // 0x6b632b: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L006b632d: { // 0x6b632d: bf01000000 MOV EDI,0x1
    s.di = 0x00000001u;
  }
  L006b6332: { // 0x6b6332: 899ed8000000 MOV dword ptr [ESI + 0xd8],EBX
    m.w32((s.si+0x000000d8u), s.bx);
  }
  L006b6338: { // 0x6b6338: 889edc000000 MOV byte ptr [ESI + 0xdc],BL
    m.w8((s.si+0x000000dcu), (s.bx & 0xffu));
  }
  L006b633e: { // 0x6b633e: 899ee0000000 MOV dword ptr [ESI + 0xe0],EBX
    m.w32((s.si+0x000000e0u), s.bx);
  }
  L006b6344: { // 0x6b6344: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  L006b6349: { // 0x6b6349: 8986e4000000 MOV dword ptr [ESI + 0xe4],EAX
    m.w32((s.si+0x000000e4u), s.ax);
  }
  L006b634f: { // 0x6b634f: 899eec000000 MOV dword ptr [ESI + 0xec],EBX
    m.w32((s.si+0x000000ecu), s.bx);
  }
  L006b6355: { // 0x6b6355: 899ef0000000 MOV dword ptr [ESI + 0xf0],EBX
    m.w32((s.si+0x000000f0u), s.bx);
  }
  L006b635b: { // 0x6b635b: 89bef4000000 MOV dword ptr [ESI + 0xf4],EDI
    m.w32((s.si+0x000000f4u), s.di);
  }
  L006b6361: { // 0x6b6361: 83cdff OR EBP,0xffffffff
    s.bp = integer::logical((s.bp)|(0xffffffffu),32,flags);
  }
  L006b6364: { // 0x6b6364: 899ef8000000 MOV dword ptr [ESI + 0xf8],EBX
    m.w32((s.si+0x000000f8u), s.bx);
  }
  L006b636a: { // 0x6b636a: 899efc000000 MOV dword ptr [ESI + 0xfc],EBX
    m.w32((s.si+0x000000fcu), s.bx);
  }
  L006b6370: { // 0x6b6370: 89ae00010000 MOV dword ptr [ESI + 0x100],EBP
    m.w32((s.si+0x00000100u), s.bp);
  }
  L006b6376: { // 0x6b6376: 89ae04010000 MOV dword ptr [ESI + 0x104],EBP
    m.w32((s.si+0x00000104u), s.bp);
  }
  L006b637c: { // 0x6b637c: 899e08010000 MOV dword ptr [ESI + 0x108],EBX
    m.w32((s.si+0x00000108u), s.bx);
  }
  L006b6382: { // 0x6b6382: 899e0c010000 MOV dword ptr [ESI + 0x10c],EBX
    m.w32((s.si+0x0000010cu), s.bx);
  }
  L006b6388: { // 0x6b6388: 89ae10010000 MOV dword ptr [ESI + 0x110],EBP
    m.w32((s.si+0x00000110u), s.bp);
  }
  L006b638e: { // 0x6b638e: 8d8e18010000 LEA ECX,[ESI + 0x118]
    s.cx = (s.si+0x00000118u);
  }
  L006b6394: { // 0x6b6394: 89ae14010000 MOV dword ptr [ESI + 0x114],EBP
    m.w32((s.si+0x00000114u), s.bp);
  }
  L006b639a: { // 0x6b639a: e8611b0500 CALL 0x00707f00
    s.arithmetic_flags=flags; invoke(m,s,f,0x00707f00u,7037855u); flags=s.arithmetic_flags;
  }
  L006b639f: { // 0x6b639f: b80000f03f MOV EAX,0x3ff00000
    s.ax = 0x3ff00000u;
  }
  L006b63a4: { // 0x6b63a4: 899e20010000 MOV dword ptr [ESI + 0x120],EBX
    m.w32((s.si+0x00000120u), s.bx);
  }
  L006b63aa: { // 0x6b63aa: 898624010000 MOV dword ptr [ESI + 0x124],EAX
    m.w32((s.si+0x00000124u), s.ax);
  }
  L006b63b0: { // 0x6b63b0: 899e28010000 MOV dword ptr [ESI + 0x128],EBX
    m.w32((s.si+0x00000128u), s.bx);
  }
  L006b63b6: { // 0x6b63b6: 89862c010000 MOV dword ptr [ESI + 0x12c],EAX
    m.w32((s.si+0x0000012cu), s.ax);
  }
  L006b63bc: { // 0x6b63bc: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  L006b63c2: { // 0x6b63c2: 898e30010000 MOV dword ptr [ESI + 0x130],ECX
    m.w32((s.si+0x00000130u), s.cx);
  }
  L006b63c8: { // 0x6b63c8: 899e38010000 MOV dword ptr [ESI + 0x138],EBX
    m.w32((s.si+0x00000138u), s.bx);
  }
  L006b63ce: { // 0x6b63ce: 8b156c89a200 MOV EDX,dword ptr [0x00a2896c]
    s.dx = m.r32((0x00a2896cu));
  }
  L006b63d4: { // 0x6b63d4: 899e44010000 MOV dword ptr [ESI + 0x144],EBX
    m.w32((s.si+0x00000144u), s.bx);
  }
  L006b63da: { // 0x6b63da: 89963c010000 MOV dword ptr [ESI + 0x13c],EDX
    m.w32((s.si+0x0000013cu), s.dx);
  }
  L006b63e0: { // 0x6b63e0: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  L006b63e5: { // 0x6b63e5: 898648010000 MOV dword ptr [ESI + 0x148],EAX
    m.w32((s.si+0x00000148u), s.ax);
  }
  L006b63eb: { // 0x6b63eb: c786500100002d000000 MOV dword ptr [ESI + 0x150],0x2d
    m.w32((s.si+0x00000150u), 0x0000002du);
  }
  L006b63f5: { // 0x6b63f5: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  L006b63fb: { // 0x6b63fb: 899e5c010000 MOV dword ptr [ESI + 0x15c],EBX
    m.w32((s.si+0x0000015cu), s.bx);
  }
  L006b6401: { // 0x6b6401: 898e54010000 MOV dword ptr [ESI + 0x154],ECX
    m.w32((s.si+0x00000154u), s.cx);
  }
  L006b6407: { // 0x6b6407: 8b156c89a200 MOV EDX,dword ptr [0x00a2896c]
    s.dx = m.r32((0x00a2896cu));
  }
  L006b640d: { // 0x6b640d: 899660010000 MOV dword ptr [ESI + 0x160],EDX
    m.w32((s.si+0x00000160u), s.dx);
  }
  L006b6413: { // 0x6b6413: 899e68010000 MOV dword ptr [ESI + 0x168],EBX
    m.w32((s.si+0x00000168u), s.bx);
  }
  L006b6419: { // 0x6b6419: 889e70010000 MOV byte ptr [ESI + 0x170],BL
    m.w8((s.si+0x00000170u), (s.bx & 0xffu));
  }
  L006b641f: { // 0x6b641f: 899e74010000 MOV dword ptr [ESI + 0x174],EBX
    m.w32((s.si+0x00000174u), s.bx);
  }
  L006b6425: { // 0x6b6425: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  L006b642a: { // 0x6b642a: 899e80010000 MOV dword ptr [ESI + 0x180],EBX
    m.w32((s.si+0x00000180u), s.bx);
  }
  L006b6430: { // 0x6b6430: 898678010000 MOV dword ptr [ESI + 0x178],EAX
    m.w32((s.si+0x00000178u), s.ax);
  }
  L006b6436: { // 0x6b6436: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  L006b643c: { // 0x6b643c: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L006b6440: { // 0x6b6440: 898e84010000 MOV dword ptr [ESI + 0x184],ECX
    m.w32((s.si+0x00000184u), s.cx);
  }
  L006b6446: { // 0x6b6446: 899e8c010000 MOV dword ptr [ESI + 0x18c],EBX
    m.w32((s.si+0x0000018cu), s.bx);
  }
  L006b644c: { // 0x6b644c: 889e90010000 MOV byte ptr [ESI + 0x190],BL
    m.w8((s.si+0x00000190u), (s.bx & 0xffu));
  }
  L006b6452: { // 0x6b6452: 8b156c89a200 MOV EDX,dword ptr [0x00a2896c]
    s.dx = m.r32((0x00a2896cu));
  }
  L006b6458: { // 0x6b6458: 899e9c010000 MOV dword ptr [ESI + 0x19c],EBX
    m.w32((s.si+0x0000019cu), s.bx);
  }
  L006b645e: { // 0x6b645e: 899694010000 MOV dword ptr [ESI + 0x194],EDX
    m.w32((s.si+0x00000194u), s.dx);
  }
  L006b6464: { // 0x6b6464: 899ea0010000 MOV dword ptr [ESI + 0x1a0],EBX
    m.w32((s.si+0x000001a0u), s.bx);
  }
  L006b646a: { // 0x6b646a: 899ea4010000 MOV dword ptr [ESI + 0x1a4],EBX
    m.w32((s.si+0x000001a4u), s.bx);
  }
  L006b6470: { // 0x6b6470: 899ea8010000 MOV dword ptr [ESI + 0x1a8],EBX
    m.w32((s.si+0x000001a8u), s.bx);
  }
  L006b6476: { // 0x6b6476: 89aeac010000 MOV dword ptr [ESI + 0x1ac],EBP
    m.w32((s.si+0x000001acu), s.bp);
  }
  L006b647c: { // 0x6b647c: 899eb0010000 MOV dword ptr [ESI + 0x1b0],EBX
    m.w32((s.si+0x000001b0u), s.bx);
  }
  L006b6482: { // 0x6b6482: 8986b4010000 MOV dword ptr [ESI + 0x1b4],EAX
    m.w32((s.si+0x000001b4u), s.ax);
  }
  L006b6488: { // 0x6b6488: 899eb8010000 MOV dword ptr [ESI + 0x1b8],EBX
    m.w32((s.si+0x000001b8u), s.bx);
  }
  L006b648e: { // 0x6b648e: 899ebc010000 MOV dword ptr [ESI + 0x1bc],EBX
    m.w32((s.si+0x000001bcu), s.bx);
  }
  L006b6494: { // 0x6b6494: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  L006b649a: { // 0x6b649a: 898ec0010000 MOV dword ptr [ESI + 0x1c0],ECX
    m.w32((s.si+0x000001c0u), s.cx);
  }
  L006b64a0: { // 0x6b64a0: 899ec8010000 MOV dword ptr [ESI + 0x1c8],EBX
    m.w32((s.si+0x000001c8u), s.bx);
  }
  L006b64a6: { // 0x6b64a6: 899ecc010000 MOV dword ptr [ESI + 0x1cc],EBX
    m.w32((s.si+0x000001ccu), s.bx);
  }
  L006b64ac: { // 0x6b64ac: 89bed0010000 MOV dword ptr [ESI + 0x1d0],EDI
    m.w32((s.si+0x000001d0u), s.di);
  }
  L006b64b2: { // 0x6b64b2: 8b156c89a200 MOV EDX,dword ptr [0x00a2896c]
    s.dx = m.r32((0x00a2896cu));
  }
  L006b64b8: { // 0x6b64b8: 899edc010000 MOV dword ptr [ESI + 0x1dc],EBX
    m.w32((s.si+0x000001dcu), s.bx);
  }
  L006b64be: { // 0x6b64be: 8996d4010000 MOV dword ptr [ESI + 0x1d4],EDX
    m.w32((s.si+0x000001d4u), s.dx);
  }
  L006b64c4: { // 0x6b64c4: 899ee0010000 MOV dword ptr [ESI + 0x1e0],EBX
    m.w32((s.si+0x000001e0u), s.bx);
  }
  L006b64ca: { // 0x6b64ca: 889ee4010000 MOV byte ptr [ESI + 0x1e4],BL
    m.w8((s.si+0x000001e4u), (s.bx & 0xffu));
  }
  L006b64d0: { // 0x6b64d0: 8b0d907caa00 MOV ECX,dword ptr [0x00aa7c90]
    s.cx = m.r32((0x00aa7c90u));
  }
  L006b64d6: { // 0x6b64d6: 8d86e8010000 LEA EAX,[ESI + 0x1e8]
    s.ax = (s.si+0x000001e8u);
  }
  L006b64dc: { // 0x6b64dc: 898ee8010000 MOV dword ptr [ESI + 0x1e8],ECX
    m.w32((s.si+0x000001e8u), s.cx);
  }
  L006b64e2: { // 0x6b64e2: 8b15947caa00 MOV EDX,dword ptr [0x00aa7c94]
    s.dx = m.r32((0x00aa7c94u));
  }
  L006b64e8: { // 0x6b64e8: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
  L006b64eb: { // 0x6b64eb: 8b0d987caa00 MOV ECX,dword ptr [0x00aa7c98]
    s.cx = m.r32((0x00aa7c98u));
  }
  L006b64f1: { // 0x6b64f1: 8d961c020000 LEA EDX,[ESI + 0x21c]
    s.dx = (s.si+0x0000021cu);
  }
  L006b64f7: { // 0x6b64f7: 894808 MOV dword ptr [EAX + 0x8],ECX
    m.w32((s.ax+0x00000008u), s.cx);
  }
  L006b64fa: { // 0x6b64fa: 899ef4010000 MOV dword ptr [ESI + 0x1f4],EBX
    m.w32((s.si+0x000001f4u), s.bx);
  }
  L006b6500: { // 0x6b6500: 899ef8010000 MOV dword ptr [ESI + 0x1f8],EBX
    m.w32((s.si+0x000001f8u), s.bx);
  }
  L006b6506: { // 0x6b6506: 889efc010000 MOV byte ptr [ESI + 0x1fc],BL
    m.w8((s.si+0x000001fcu), (s.bx & 0xffu));
  }
  L006b650c: { // 0x6b650c: 889efd010000 MOV byte ptr [ESI + 0x1fd],BL
    m.w8((s.si+0x000001fdu), (s.bx & 0xffu));
  }
  L006b6512: { // 0x6b6512: 899e00020000 MOV dword ptr [ESI + 0x200],EBX
    m.w32((s.si+0x00000200u), s.bx);
  }
  L006b6518: { // 0x6b6518: 889e04020000 MOV byte ptr [ESI + 0x204],BL
    m.w8((s.si+0x00000204u), (s.bx & 0xffu));
  }
  L006b651e: { // 0x6b651e: 889e05020000 MOV byte ptr [ESI + 0x205],BL
    m.w8((s.si+0x00000205u), (s.bx & 0xffu));
  }
  L006b6524: { // 0x6b6524: 889e06020000 MOV byte ptr [ESI + 0x206],BL
    m.w8((s.si+0x00000206u), (s.bx & 0xffu));
  }
  L006b652a: { // 0x6b652a: 899e08020000 MOV dword ptr [ESI + 0x208],EBX
    m.w32((s.si+0x00000208u), s.bx);
  }
  L006b6530: { // 0x6b6530: 899e0c020000 MOV dword ptr [ESI + 0x20c],EBX
    m.w32((s.si+0x0000020cu), s.bx);
  }
  L006b6536: { // 0x6b6536: 889e10020000 MOV byte ptr [ESI + 0x210],BL
    m.w8((s.si+0x00000210u), (s.bx & 0xffu));
  }
  L006b653c: { // 0x6b653c: 899e14020000 MOV dword ptr [ESI + 0x214],EBX
    m.w32((s.si+0x00000214u), s.bx);
  }
  L006b6542: { // 0x6b6542: 899e18020000 MOV dword ptr [ESI + 0x218],EBX
    m.w32((s.si+0x00000218u), s.bx);
  }
  L006b6548: { // 0x6b6548: a1907caa00 MOV EAX,[0x00aa7c90]
    s.ax = m.r32((0x00aa7c90u));
  }
  L006b654d: { // 0x6b654d: 8902 MOV dword ptr [EDX],EAX
    m.w32((s.dx), s.ax);
  }
  L006b654f: { // 0x6b654f: 8b0d947caa00 MOV ECX,dword ptr [0x00aa7c94]
    s.cx = m.r32((0x00aa7c94u));
  }
  L006b6555: { // 0x6b6555: 894a04 MOV dword ptr [EDX + 0x4],ECX
    m.w32((s.dx+0x00000004u), s.cx);
  }
  L006b6558: { // 0x6b6558: a1987caa00 MOV EAX,[0x00aa7c98]
    s.ax = m.r32((0x00aa7c98u));
  }
  L006b655d: { // 0x6b655d: 894208 MOV dword ptr [EDX + 0x8],EAX
    m.w32((s.dx+0x00000008u), s.ax);
  }
  L006b6560: { // 0x6b6560: 899e28020000 MOV dword ptr [ESI + 0x228],EBX
    m.w32((s.si+0x00000228u), s.bx);
  }
  L006b6566: { // 0x6b6566: 899e2c020000 MOV dword ptr [ESI + 0x22c],EBX
    m.w32((s.si+0x0000022cu), s.bx);
  }
  L006b656c: { // 0x6b656c: 899e30020000 MOV dword ptr [ESI + 0x230],EBX
    m.w32((s.si+0x00000230u), s.bx);
  }
  L006b6572: { // 0x6b6572: 899e34020000 MOV dword ptr [ESI + 0x234],EBX
    m.w32((s.si+0x00000234u), s.bx);
  }
  L006b6578: { // 0x6b6578: 899e38020000 MOV dword ptr [ESI + 0x238],EBX
    m.w32((s.si+0x00000238u), s.bx);
  }
  L006b657e: { // 0x6b657e: 899e3c020000 MOV dword ptr [ESI + 0x23c],EBX
    m.w32((s.si+0x0000023cu), s.bx);
  }
  L006b6584: { // 0x6b6584: 899e40020000 MOV dword ptr [ESI + 0x240],EBX
    m.w32((s.si+0x00000240u), s.bx);
  }
  L006b658a: { // 0x6b658a: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  L006b6590: { // 0x6b6590: 899e4c020000 MOV dword ptr [ESI + 0x24c],EBX
    m.w32((s.si+0x0000024cu), s.bx);
  }
  L006b6596: { // 0x6b6596: 898e44020000 MOV dword ptr [ESI + 0x244],ECX
    m.w32((s.si+0x00000244u), s.cx);
  }
  L006b659c: { // 0x6b659c: 899e50020000 MOV dword ptr [ESI + 0x250],EBX
    m.w32((s.si+0x00000250u), s.bx);
  }
  L006b65a2: { // 0x6b65a2: 89ae54020000 MOV dword ptr [ESI + 0x254],EBP
    m.w32((s.si+0x00000254u), s.bp);
  }
  L006b65a8: { // 0x6b65a8: 899e58020000 MOV dword ptr [ESI + 0x258],EBX
    m.w32((s.si+0x00000258u), s.bx);
  }
  L006b65ae: { // 0x6b65ae: 899e7c020000 MOV dword ptr [ESI + 0x27c],EBX
    m.w32((s.si+0x0000027cu), s.bx);
  }
  L006b65b4: { // 0x6b65b4: 899e80020000 MOV dword ptr [ESI + 0x280],EBX
    m.w32((s.si+0x00000280u), s.bx);
  }
  L006b65ba: { // 0x6b65ba: 899e84020000 MOV dword ptr [ESI + 0x284],EBX
    m.w32((s.si+0x00000284u), s.bx);
  }
  L006b65c0: { // 0x6b65c0: 899e88020000 MOV dword ptr [ESI + 0x288],EBX
    m.w32((s.si+0x00000288u), s.bx);
  }
  L006b65c6: { // 0x6b65c6: 899e8c020000 MOV dword ptr [ESI + 0x28c],EBX
    m.w32((s.si+0x0000028cu), s.bx);
  }
  L006b65cc: { // 0x6b65cc: 8d8e94020000 LEA ECX,[ESI + 0x294]
    s.cx = (s.si+0x00000294u);
  }
  L006b65d2: { // 0x6b65d2: 89ae90020000 MOV dword ptr [ESI + 0x290],EBP
    m.w32((s.si+0x00000290u), s.bp);
  }
  L006b65d8: { // 0x6b65d8: e8639efdff CALL 0x00690440
    s.arithmetic_flags=flags; invoke(m,s,f,0x00690440u,7038429u); flags=s.arithmetic_flags;
  }
  L006b65dd: { // 0x6b65dd: 8d8ea8020000 LEA ECX,[ESI + 0x2a8]
    s.cx = (s.si+0x000002a8u);
  }
  L006b65e3: { // 0x6b65e3: e86802deff CALL 0x00496850
    s.arithmetic_flags=flags; invoke(m,s,f,0x00496850u,7038440u); flags=s.arithmetic_flags;
  }
  L006b65e8: { // 0x6b65e8: 6a03 PUSH 0x3
    f.push(m,0x00000003u);
  }
  L006b65ea: { // 0x6b65ea: 8d8ec8020000 LEA ECX,[ESI + 0x2c8]
    s.cx = (s.si+0x000002c8u);
  }
  L006b65f0: { // 0x6b65f0: e86b20e0ff CALL 0x004b8660
    s.arithmetic_flags=flags; invoke(m,s,f,0x004b8660u,7038453u); flags=s.arithmetic_flags;
  }
  L006b65f5: { // 0x6b65f5: 8d8ee0020000 LEA ECX,[ESI + 0x2e0]
    s.cx = (s.si+0x000002e0u);
  }
  L006b65fb: { // 0x6b65fb: e84020e0ff CALL 0x004b8640
    s.arithmetic_flags=flags; invoke(m,s,f,0x004b8640u,7038464u); flags=s.arithmetic_flags;
  }
  L006b6600: { // 0x6b6600: 8d8ef8020000 LEA ECX,[ESI + 0x2f8]
    s.cx = (s.si+0x000002f8u);
  }
  L006b6606: { // 0x6b6606: e83520e0ff CALL 0x004b8640
    s.arithmetic_flags=flags; invoke(m,s,f,0x004b8640u,7038475u); flags=s.arithmetic_flags;
  }
  L006b660b: { // 0x6b660b: 899e10030000 MOV dword ptr [ESI + 0x310],EBX
    m.w32((s.si+0x00000310u), s.bx);
  }
  L006b6611: { // 0x6b6611: 8b156c89a200 MOV EDX,dword ptr [0x00a2896c]
    s.dx = m.r32((0x00a2896cu));
  }
  L006b6617: { // 0x6b6617: 899614030000 MOV dword ptr [ESI + 0x314],EDX
    m.w32((s.si+0x00000314u), s.dx);
  }
  L006b661d: { // 0x6b661d: 899e1c030000 MOV dword ptr [ESI + 0x31c],EBX
    m.w32((s.si+0x0000031cu), s.bx);
  }
  L006b6623: { // 0x6b6623: 66899e22030000 MOV word ptr [ESI + 0x322],BX
    m.w16((s.si+0x00000322u), (s.bx & 0xffffu));
  }
  L006b662a: { // 0x6b662a: 889e24030000 MOV byte ptr [ESI + 0x324],BL
    m.w8((s.si+0x00000324u), (s.bx & 0xffu));
  }
  L006b6630: { // 0x6b6630: 889e25030000 MOV byte ptr [ESI + 0x325],BL
    m.w8((s.si+0x00000325u), (s.bx & 0xffu));
  }
  L006b6636: { // 0x6b6636: 889e26030000 MOV byte ptr [ESI + 0x326],BL
    m.w8((s.si+0x00000326u), (s.bx & 0xffu));
  }
  L006b663c: { // 0x6b663c: 889e27030000 MOV byte ptr [ESI + 0x327],BL
    m.w8((s.si+0x00000327u), (s.bx & 0xffu));
  }
  L006b6642: { // 0x6b6642: 889e28030000 MOV byte ptr [ESI + 0x328],BL
    m.w8((s.si+0x00000328u), (s.bx & 0xffu));
  }
  L006b6648: { // 0x6b6648: 889e29030000 MOV byte ptr [ESI + 0x329],BL
    m.w8((s.si+0x00000329u), (s.bx & 0xffu));
  }
  L006b664e: { // 0x6b664e: 889e2a030000 MOV byte ptr [ESI + 0x32a],BL
    m.w8((s.si+0x0000032au), (s.bx & 0xffu));
  }
  L006b6654: { // 0x6b6654: 889e2b030000 MOV byte ptr [ESI + 0x32b],BL
    m.w8((s.si+0x0000032bu), (s.bx & 0xffu));
  }
  L006b665a: { // 0x6b665a: 889e2c030000 MOV byte ptr [ESI + 0x32c],BL
    m.w8((s.si+0x0000032cu), (s.bx & 0xffu));
  }
  L006b6660: { // 0x6b6660: b802000000 MOV EAX,0x2
    s.ax = 0x00000002u;
  }
  L006b6665: { // 0x6b6665: 889e2d030000 MOV byte ptr [ESI + 0x32d],BL
    m.w8((s.si+0x0000032du), (s.bx & 0xffu));
  }
  L006b666b: { // 0x6b666b: 898630030000 MOV dword ptr [ESI + 0x330],EAX
    m.w32((s.si+0x00000330u), s.ax);
  }
  L006b6671: { // 0x6b6671: 89be34030000 MOV dword ptr [ESI + 0x334],EDI
    m.w32((s.si+0x00000334u), s.di);
  }
  L006b6677: { // 0x6b6677: 89be38030000 MOV dword ptr [ESI + 0x338],EDI
    m.w32((s.si+0x00000338u), s.di);
  }
  L006b667d: { // 0x6b667d: 89be3c030000 MOV dword ptr [ESI + 0x33c],EDI
    m.w32((s.si+0x0000033cu), s.di);
  }
  L006b6683: { // 0x6b6683: 899e44030000 MOV dword ptr [ESI + 0x344],EBX
    m.w32((s.si+0x00000344u), s.bx);
  }
  L006b6689: { // 0x6b6689: 899e48030000 MOV dword ptr [ESI + 0x348],EBX
    m.w32((s.si+0x00000348u), s.bx);
  }
  L006b668f: { // 0x6b668f: 898650030000 MOV dword ptr [ESI + 0x350],EAX
    m.w32((s.si+0x00000350u), s.ax);
  }
  L006b6695: { // 0x6b6695: 89be54030000 MOV dword ptr [ESI + 0x354],EDI
    m.w32((s.si+0x00000354u), s.di);
  }
  L006b669b: { // 0x6b669b: 89be58030000 MOV dword ptr [ESI + 0x358],EDI
    m.w32((s.si+0x00000358u), s.di);
  }
  L006b66a1: { // 0x6b66a1: 89be5c030000 MOV dword ptr [ESI + 0x35c],EDI
    m.w32((s.si+0x0000035cu), s.di);
  }
  L006b66a7: { // 0x6b66a7: 899e64030000 MOV dword ptr [ESI + 0x364],EBX
    m.w32((s.si+0x00000364u), s.bx);
  }
  L006b66ad: { // 0x6b66ad: 899e68030000 MOV dword ptr [ESI + 0x368],EBX
    m.w32((s.si+0x00000368u), s.bx);
  }
  L006b66b3: { // 0x6b66b3: 889e70030000 MOV byte ptr [ESI + 0x370],BL
    m.w8((s.si+0x00000370u), (s.bx & 0xffu));
  }
  L006b66b9: { // 0x6b66b9: 889e71030000 MOV byte ptr [ESI + 0x371],BL
    m.w8((s.si+0x00000371u), (s.bx & 0xffu));
  }
  L006b66bf: { // 0x6b66bf: 889e72030000 MOV byte ptr [ESI + 0x372],BL
    m.w8((s.si+0x00000372u), (s.bx & 0xffu));
  }
  L006b66c5: { // 0x6b66c5: b80a000000 MOV EAX,0xa
    s.ax = 0x0000000au;
  }
  L006b66ca: { // 0x6b66ca: 889e73030000 MOV byte ptr [ESI + 0x373],BL
    m.w8((s.si+0x00000373u), (s.bx & 0xffu));
  }
  L006b66d0: { // 0x6b66d0: 889e74030000 MOV byte ptr [ESI + 0x374],BL
    m.w8((s.si+0x00000374u), (s.bx & 0xffu));
  }
  L006b66d6: { // 0x6b66d6: 889e75030000 MOV byte ptr [ESI + 0x375],BL
    m.w8((s.si+0x00000375u), (s.bx & 0xffu));
  }
  L006b66dc: { // 0x6b66dc: 889e76030000 MOV byte ptr [ESI + 0x376],BL
    m.w8((s.si+0x00000376u), (s.bx & 0xffu));
  }
  L006b66e2: { // 0x6b66e2: 889e77030000 MOV byte ptr [ESI + 0x377],BL
    m.w8((s.si+0x00000377u), (s.bx & 0xffu));
  }
  L006b66e8: { // 0x6b66e8: 889e78030000 MOV byte ptr [ESI + 0x378],BL
    m.w8((s.si+0x00000378u), (s.bx & 0xffu));
  }
  L006b66ee: { // 0x6b66ee: c6867903000001 MOV byte ptr [ESI + 0x379],0x1
    m.w8((s.si+0x00000379u), 0x00000001u);
  }
  L006b66f5: { // 0x6b66f5: c6867a03000001 MOV byte ptr [ESI + 0x37a],0x1
    m.w8((s.si+0x0000037au), 0x00000001u);
  }
  L006b66fc: { // 0x6b66fc: 889e7b030000 MOV byte ptr [ESI + 0x37b],BL
    m.w8((s.si+0x0000037bu), (s.bx & 0xffu));
  }
  L006b6702: { // 0x6b6702: 889e7c030000 MOV byte ptr [ESI + 0x37c],BL
    m.w8((s.si+0x0000037cu), (s.bx & 0xffu));
  }
  L006b6708: { // 0x6b6708: 889e7d030000 MOV byte ptr [ESI + 0x37d],BL
    m.w8((s.si+0x0000037du), (s.bx & 0xffu));
  }
  L006b670e: { // 0x6b670e: 889e7e030000 MOV byte ptr [ESI + 0x37e],BL
    m.w8((s.si+0x0000037eu), (s.bx & 0xffu));
  }
  L006b6714: { // 0x6b6714: 889e7f030000 MOV byte ptr [ESI + 0x37f],BL
    m.w8((s.si+0x0000037fu), (s.bx & 0xffu));
  }
  L006b671a: { // 0x6b671a: 889e80030000 MOV byte ptr [ESI + 0x380],BL
    m.w8((s.si+0x00000380u), (s.bx & 0xffu));
  }
  L006b6720: { // 0x6b6720: 889e81030000 MOV byte ptr [ESI + 0x381],BL
    m.w8((s.si+0x00000381u), (s.bx & 0xffu));
  }
  L006b6726: { // 0x6b6726: 899e84030000 MOV dword ptr [ESI + 0x384],EBX
    m.w32((s.si+0x00000384u), s.bx);
  }
  L006b672c: { // 0x6b672c: 889e88030000 MOV byte ptr [ESI + 0x388],BL
    m.w8((s.si+0x00000388u), (s.bx & 0xffu));
  }
  L006b6732: { // 0x6b6732: 899e8c030000 MOV dword ptr [ESI + 0x38c],EBX
    m.w32((s.si+0x0000038cu), s.bx);
  }
  L006b6738: { // 0x6b6738: b97cc77800 MOV ECX,0x78c77c
    s.cx = 0x0078c77cu;
  }
  L006b673d: { // 0x6b673d: 899e94030000 MOV dword ptr [ESI + 0x394],EBX
    m.w32((s.si+0x00000394u), s.bx);
  }
  L006b6743: { // 0x6b6743: 899e98030000 MOV dword ptr [ESI + 0x398],EBX
    m.w32((s.si+0x00000398u), s.bx);
  }
  L006b6749: { // 0x6b6749: c6869c03000001 MOV byte ptr [ESI + 0x39c],0x1
    m.w8((s.si+0x0000039cu), 0x00000001u);
  }
  L006b6750: { // 0x6b6750: 889e9d030000 MOV byte ptr [ESI + 0x39d],BL
    m.w8((s.si+0x0000039du), (s.bx & 0xffu));
  }
  L006b6756: { // 0x6b6756: c78690030000948a7800 MOV dword ptr [ESI + 0x390],0x788a94
    m.w32((s.si+0x00000390u), 0x00788a94u);
  }
  L006b6760: { // 0x6b6760: 8986a4030000 MOV dword ptr [ESI + 0x3a4],EAX
    m.w32((s.si+0x000003a4u), s.ax);
  }
  L006b6766: { // 0x6b6766: 899ea0030000 MOV dword ptr [ESI + 0x3a0],EBX
    m.w32((s.si+0x000003a0u), s.bx);
  }
  L006b676c: { // 0x6b676c: 899eac030000 MOV dword ptr [ESI + 0x3ac],EBX
    m.w32((s.si+0x000003acu), s.bx);
  }
  L006b6772: { // 0x6b6772: 899eb0030000 MOV dword ptr [ESI + 0x3b0],EBX
    m.w32((s.si+0x000003b0u), s.bx);
  }
  L006b6778: { // 0x6b6778: c686b403000001 MOV byte ptr [ESI + 0x3b4],0x1
    m.w8((s.si+0x000003b4u), 0x00000001u);
  }
  L006b677f: { // 0x6b677f: 889eb5030000 MOV byte ptr [ESI + 0x3b5],BL
    m.w8((s.si+0x000003b5u), (s.bx & 0xffu));
  }
  L006b6785: { // 0x6b6785: 898ea8030000 MOV dword ptr [ESI + 0x3a8],ECX
    m.w32((s.si+0x000003a8u), s.cx);
  }
  L006b678b: { // 0x6b678b: 8986bc030000 MOV dword ptr [ESI + 0x3bc],EAX
    m.w32((s.si+0x000003bcu), s.ax);
  }
  L006b6791: { // 0x6b6791: 899eb8030000 MOV dword ptr [ESI + 0x3b8],EBX
    m.w32((s.si+0x000003b8u), s.bx);
  }
  L006b6797: { // 0x6b6797: 899ec4030000 MOV dword ptr [ESI + 0x3c4],EBX
    m.w32((s.si+0x000003c4u), s.bx);
  }
  L006b679d: { // 0x6b679d: 899ec8030000 MOV dword ptr [ESI + 0x3c8],EBX
    m.w32((s.si+0x000003c8u), s.bx);
  }
  L006b67a3: { // 0x6b67a3: c686cc03000001 MOV byte ptr [ESI + 0x3cc],0x1
    m.w8((s.si+0x000003ccu), 0x00000001u);
  }
  L006b67aa: { // 0x6b67aa: 889ecd030000 MOV byte ptr [ESI + 0x3cd],BL
    m.w8((s.si+0x000003cdu), (s.bx & 0xffu));
  }
  L006b67b0: { // 0x6b67b0: 898ec0030000 MOV dword ptr [ESI + 0x3c0],ECX
    m.w32((s.si+0x000003c0u), s.cx);
  }
  L006b67b6: { // 0x6b67b6: 8986d4030000 MOV dword ptr [ESI + 0x3d4],EAX
    m.w32((s.si+0x000003d4u), s.ax);
  }
  L006b67bc: { // 0x6b67bc: 899ed0030000 MOV dword ptr [ESI + 0x3d0],EBX
    m.w32((s.si+0x000003d0u), s.bx);
  }
  L006b67c2: { // 0x6b67c2: 89beec030000 MOV dword ptr [ESI + 0x3ec],EDI
    m.w32((s.si+0x000003ecu), s.di);
  }
  L006b67c8: { // 0x6b67c8: 899ef0030000 MOV dword ptr [ESI + 0x3f0],EBX
    m.w32((s.si+0x000003f0u), s.bx);
  }
  L006b67ce: { // 0x6b67ce: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  L006b67d3: { // 0x6b67d3: 8986f4030000 MOV dword ptr [ESI + 0x3f4],EAX
    m.w32((s.si+0x000003f4u), s.ax);
  }
  L006b67d9: { // 0x6b67d9: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L006b67dd: { // 0x6b67dd: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L006b67df: { // 0x6b67df: 899ef8030000 MOV dword ptr [ESI + 0x3f8],EBX
    m.w32((s.si+0x000003f8u), s.bx);
  }
  L006b67e5: { // 0x6b67e5: 899efc030000 MOV dword ptr [ESI + 0x3fc],EBX
    m.w32((s.si+0x000003fcu), s.bx);
  }
  L006b67eb: { // 0x6b67eb: 899e08040000 MOV dword ptr [ESI + 0x408],EBX
    m.w32((s.si+0x00000408u), s.bx);
  }
  L006b67f1: { // 0x6b67f1: 899e0c040000 MOV dword ptr [ESI + 0x40c],EBX
    m.w32((s.si+0x0000040cu), s.bx);
  }
  L006b67f7: { // 0x6b67f7: 899e10040000 MOV dword ptr [ESI + 0x410],EBX
    m.w32((s.si+0x00000410u), s.bx);
  }
  L006b67fd: { // 0x6b67fd: c706287a7900 MOV dword ptr [ESI],0x797a28
    m.w32((s.si), 0x00797a28u);
  }
  L006b6803: { // 0x6b6803: c746040c7a7900 MOV dword ptr [ESI + 0x4],0x797a0c
    m.w32((s.si+0x00000004u), 0x00797a0cu);
  }
  L006b680a: { // 0x6b680a: c74608047a7900 MOV dword ptr [ESI + 0x8],0x797a04
    m.w32((s.si+0x00000008u), 0x00797a04u);
  }
  L006b6811: { // 0x6b6811: c7460cfc797900 MOV dword ptr [ESI + 0xc],0x7979fc
    m.w32((s.si+0x0000000cu), 0x007979fcu);
  }
  L006b6818: { // 0x6b6818: 740c JZ 0x006b6826
    if(integer::condition("JZ",flags)) goto L006b6826;
  }
  L006b681a: { // 0x6b681a: 8b8830010000 MOV ECX,dword ptr [EAX + 0x130]
    s.cx = m.r32((s.ax+0x00000130u));
  }
  L006b6820: { // 0x6b6820: 898e14010000 MOV dword ptr [ESI + 0x114],ECX
    m.w32((s.si+0x00000114u), s.cx);
  }
  L006b6826: { // 0x6b6826: 8d8ed8030000 LEA ECX,[ESI + 0x3d8]
    s.cx = (s.si+0x000003d8u);
  }
  L006b682c: { // 0x6b682c: e8bff3d4ff CALL 0x00405bf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00405bf0u,7039025u); flags=s.arithmetic_flags;
  }
  L006b6831: { // 0x6b6831: a16888a200 MOV EAX,[0x00a28868]
    s.ax = m.r32((0x00a28868u));
  }
  L006b6836: { // 0x6b6836: 8b0d7088a200 MOV ECX,dword ptr [0x00a28870]
    s.cx = m.r32((0x00a28870u));
  }
  L006b683c: { // 0x6b683c: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L006b683e: { // 0x6b683e: 7c2c JL 0x006b686c
    if(integer::condition("JL",flags)) goto L006b686c;
  }
  L006b6840: { // 0x6b6840: 381d6d88a200 CMP byte ptr [0x00a2886d],BL
    (void)integer::sub(m.r8((0x00a2886du)),(s.bx & 0xffu),8,flags);
  }
  L006b6846: { // 0x6b6846: 7504 JNZ 0x006b684c
    if(integer::condition("JNZ",flags)) goto L006b684c;
  }
  L006b6848: { // 0x6b6848: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L006b684a: { // 0x6b684a: 7538 JNZ 0x006b6884
    if(integer::condition("JNZ",flags)) goto L006b6884;
  }
  L006b684c: { // 0x6b684c: 8b0d7488a200 MOV ECX,dword ptr [0x00a28874]
    s.cx = m.r32((0x00a28874u));
  }
  L006b6852: { // 0x6b6852: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L006b6854: { // 0x6b6854: 7e2e JLE 0x006b6884
    if(integer::condition("JLE",flags)) goto L006b6884;
  }
  L006b6856: { // 0x6b6856: 8b156088a200 MOV EDX,dword ptr [0x00a28860]
    s.dx = m.r32((0x00a28860u));
  }
  L006b685c: { // 0x6b685c: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L006b685e: { // 0x6b685e: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006b685f: { // 0x6b685f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006b6860: { // 0x6b6860: b96088a200 MOV ECX,0xa28860
    s.cx = 0x00a28860u;
  }
  L006b6865: { // 0x6b6865: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),7039080u); flags=s.arithmetic_flags;
  }
  L006b6868: { // 0x6b6868: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b686a: { // 0x6b686a: 7418 JZ 0x006b6884
    if(integer::condition("JZ",flags)) goto L006b6884;
  }
  L006b686c: { // 0x6b686c: 8b0d7088a200 MOV ECX,dword ptr [0x00a28870]
    s.cx = m.r32((0x00a28870u));
  }
  L006b6872: { // 0x6b6872: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L006b6874: { // 0x6b6874: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L006b6875: { // 0x6b6875: 890d7088a200 MOV dword ptr [0x00a28870],ECX
    m.w32((0x00a28870u), s.cx);
  }
  L006b687b: { // 0x6b687b: 8b0d6488a200 MOV ECX,dword ptr [0x00a28864]
    s.cx = m.r32((0x00a28864u));
  }
  L006b6881: { // 0x6b6881: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L006b6884: { // 0x6b6884: a11888aa00 MOV EAX,[0x00aa8818]
    s.ax = m.r32((0x00aa8818u));
  }
  L006b6889: { // 0x6b6889: 8b0d2088aa00 MOV ECX,dword ptr [0x00aa8820]
    s.cx = m.r32((0x00aa8820u));
  }
  L006b688f: { // 0x6b688f: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L006b6891: { // 0x6b6891: 7c2c JL 0x006b68bf
    if(integer::condition("JL",flags)) goto L006b68bf;
  }
  L006b6893: { // 0x6b6893: 381d1d88aa00 CMP byte ptr [0x00aa881d],BL
    (void)integer::sub(m.r8((0x00aa881du)),(s.bx & 0xffu),8,flags);
  }
  L006b6899: { // 0x6b6899: 7504 JNZ 0x006b689f
    if(integer::condition("JNZ",flags)) goto L006b689f;
  }
  L006b689b: { // 0x6b689b: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L006b689d: { // 0x6b689d: 7538 JNZ 0x006b68d7
    if(integer::condition("JNZ",flags)) goto L006b68d7;
  }
  L006b689f: { // 0x6b689f: 8b0d2488aa00 MOV ECX,dword ptr [0x00aa8824]
    s.cx = m.r32((0x00aa8824u));
  }
  L006b68a5: { // 0x6b68a5: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L006b68a7: { // 0x6b68a7: 7e2e JLE 0x006b68d7
    if(integer::condition("JLE",flags)) goto L006b68d7;
  }
  L006b68a9: { // 0x6b68a9: 8b151088aa00 MOV EDX,dword ptr [0x00aa8810]
    s.dx = m.r32((0x00aa8810u));
  }
  L006b68af: { // 0x6b68af: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L006b68b1: { // 0x6b68b1: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006b68b2: { // 0x6b68b2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006b68b3: { // 0x6b68b3: b91088aa00 MOV ECX,0xaa8810
    s.cx = 0x00aa8810u;
  }
  L006b68b8: { // 0x6b68b8: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),7039163u); flags=s.arithmetic_flags;
  }
  L006b68bb: { // 0x6b68bb: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b68bd: { // 0x6b68bd: 7418 JZ 0x006b68d7
    if(integer::condition("JZ",flags)) goto L006b68d7;
  }
  L006b68bf: { // 0x6b68bf: 8b0d2088aa00 MOV ECX,dword ptr [0x00aa8820]
    s.cx = m.r32((0x00aa8820u));
  }
  L006b68c5: { // 0x6b68c5: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L006b68c7: { // 0x6b68c7: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L006b68c8: { // 0x6b68c8: 890d2088aa00 MOV dword ptr [0x00aa8820],ECX
    m.w32((0x00aa8820u), s.cx);
  }
  L006b68ce: { // 0x6b68ce: 8b0d1488aa00 MOV ECX,dword ptr [0x00aa8814]
    s.cx = m.r32((0x00aa8814u));
  }
  L006b68d4: { // 0x6b68d4: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L006b68d7: { // 0x6b68d7: 8a4614 MOV AL,byte ptr [ESI + 0x14]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000014u)));
  }
  L006b68da: { // 0x6b68da: 8dbe5c020000 LEA EDI,[ESI + 0x25c]
    s.di = (s.si+0x0000025cu);
  }
  L006b68e0: { // 0x6b68e0: 0c01 OR AL,0x1
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000001u),8,flags));
  }
  L006b68e2: { // 0x6b68e2: b908000000 MOV ECX,0x8
    s.cx = 0x00000008u;
  }
  L006b68e7: { // 0x6b68e7: 884614 MOV byte ptr [ESI + 0x14],AL
    m.w8((s.si+0x00000014u), (s.ax & 0xffu));
  }
  L006b68ea: { // 0x6b68ea: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006b68ec: { // 0x6b68ec: f3ab STOSD.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::count);
  }
  L006b68ee: { // 0x6b68ee: 8b15c055a200 MOV EDX,dword ptr [0x00a255c0]
    s.dx = m.r32((0x00a255c0u));
  }
  L006b68f4: { // 0x6b68f4: 8d8a18020000 LEA ECX,[EDX + 0x218]
    s.cx = (s.dx+0x00000218u);
  }
  L006b68fa: { // 0x6b68fa: e8e194f7ff CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,7039231u); flags=s.arithmetic_flags;
  }
  L006b68ff: { // 0x6b68ff: 66898620030000 MOV word ptr [ESI + 0x320],AX
    m.w16((s.si+0x00000320u), (s.ax & 0xffffu));
  }
  L006b6906: { // 0x6b6906: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L006b6908: { // 0x6b6908: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b6909: { // 0x6b6909: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b690a: { // 0x6b690a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006b690b: { // 0x6b690b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006b690c: { // 0x6b690c: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0022ddd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0062ddd0: { // 0x62ddd0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0062ddd1: { // 0x62ddd1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0062ddd3: { // 0x62ddd3: e82835f6ff CALL 0x00591300
    s.arithmetic_flags=flags; invoke(m,s,f,0x00591300u,6479320u); flags=s.arithmetic_flags;
  }
  L0062ddd8: { // 0x62ddd8: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  L0062ddda: { // 0x62ddda: c786cc00000000000000 MOV dword ptr [ESI + 0xcc],0x0
    m.w32((s.si+0x000000ccu), 0x00000000u);
  }
  L0062dde4: { // 0x62dde4: c786d000000001000000 MOV dword ptr [ESI + 0xd0],0x1
    m.w32((s.si+0x000000d0u), 0x00000001u);
  }
  L0062ddee: { // 0x62ddee: c686d400000001 MOV byte ptr [ESI + 0xd4],0x1
    m.w8((s.si+0x000000d4u), 0x00000001u);
  }
  L0062ddf5: { // 0x62ddf5: c686d500000000 MOV byte ptr [ESI + 0xd5],0x0
    m.w8((s.si+0x000000d5u), 0x00000000u);
  }
  L0062ddfc: { // 0x62ddfc: c786c8000000fc577800 MOV dword ptr [ESI + 0xc8],0x7857fc
    m.w32((s.si+0x000000c8u), 0x007857fcu);
  }
  L0062de06: { // 0x62de06: e84cfb1300 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,6479371u); flags=s.arithmetic_flags;
  }
  L0062de0b: { // 0x62de0b: 8986cc000000 MOV dword ptr [ESI + 0xcc],EAX
    m.w32((s.si+0x000000ccu), s.ax);
  }
  L0062de11: { // 0x62de11: c686d500000001 MOV byte ptr [ESI + 0xd5],0x1
    m.w8((s.si+0x000000d5u), 0x00000001u);
  }
  L0062de18: { // 0x62de18: c706a8387900 MOV dword ptr [ESI],0x7938a8
    m.w32((s.si), 0x007938a8u);
  }
  L0062de1e: { // 0x62de1e: c746048c387900 MOV dword ptr [ESI + 0x4],0x79388c
    m.w32((s.si+0x00000004u), 0x0079388cu);
  }
  L0062de25: { // 0x62de25: c7460884387900 MOV dword ptr [ESI + 0x8],0x793884
    m.w32((s.si+0x00000008u), 0x00793884u);
  }
  L0062de2c: { // 0x62de2c: c7460c7c387900 MOV dword ptr [ESI + 0xc],0x79387c
    m.w32((s.si+0x0000000cu), 0x0079387cu);
  }
  L0062de33: { // 0x62de33: 8b86cc000000 MOV EAX,dword ptr [ESI + 0xcc]
    s.ax = m.r32((s.si+0x000000ccu));
  }
  L0062de39: { // 0x62de39: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0062de3b: { // 0x62de3b: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0062de3e: { // 0x62de3e: c70000000000 MOV dword ptr [EAX],0x0
    m.w32((s.ax), 0x00000000u);
  }
  L0062de44: { // 0x62de44: 898ebc000000 MOV dword ptr [ESI + 0xbc],ECX
    m.w32((s.si+0x000000bcu), s.cx);
  }
  L0062de4a: { // 0x62de4a: 898ec0000000 MOV dword ptr [ESI + 0xc0],ECX
    m.w32((s.si+0x000000c0u), s.cx);
  }
  L0062de50: { // 0x62de50: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0062de52: { // 0x62de52: 898ec4000000 MOV dword ptr [ESI + 0xc4],ECX
    m.w32((s.si+0x000000c4u), s.cx);
  }
  L0062de58: { // 0x62de58: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0062de59: { // 0x62de59: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00191300(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00591300: { // 0x00591300: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00591301: { // 0x00591301: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00591303: { // 0x00591303: e868960300 CALL 0x005ca970
    s.arithmetic_flags=flags; invoke(m,s,f,0x005ca970u,5837576u); flags=s.arithmetic_flags;
  }
  L00591308: { // 0x00591308: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L0059130b: { // 0x0059130b: 898698000000 MOV dword ptr [ESI + 0x98],EAX
    m.w32((s.si+0x00000098u), s.ax);
  }
  L00591311: { // 0x00591311: 89869c000000 MOV dword ptr [ESI + 0x9c],EAX
    m.w32((s.si+0x0000009cu), s.ax);
  }
  L00591317: { // 0x00591317: 8986a0000000 MOV dword ptr [ESI + 0xa0],EAX
    m.w32((s.si+0x000000a0u), s.ax);
  }
  L0059131d: { // 0x0059131d: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0059131f: { // 0x0059131f: 8886a4000000 MOV byte ptr [ESI + 0xa4],AL
    m.w8((s.si+0x000000a4u), (s.ax & 0xffu));
  }
  L00591325: { // 0x00591325: 8986a8000000 MOV dword ptr [ESI + 0xa8],EAX
    m.w32((s.si+0x000000a8u), s.ax);
  }
  L0059132b: { // 0x0059132b: 8986ac000000 MOV dword ptr [ESI + 0xac],EAX
    m.w32((s.si+0x000000acu), s.ax);
  }
  L00591331: { // 0x00591331: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  L00591337: { // 0x00591337: 898eb0000000 MOV dword ptr [ESI + 0xb0],ECX
    m.w32((s.si+0x000000b0u), s.cx);
  }
  L0059133d: { // 0x0059133d: 8986b8000000 MOV dword ptr [ESI + 0xb8],EAX
    m.w32((s.si+0x000000b8u), s.ax);
  }
  L00591343: { // 0x00591343: c706e8117900 MOV dword ptr [ESI],0x7911e8
    m.w32((s.si), 0x007911e8u);
  }
  L00591349: { // 0x00591349: c74604cc117900 MOV dword ptr [ESI + 0x4],0x7911cc
    m.w32((s.si+0x00000004u), 0x007911ccu);
  }
  L00591350: { // 0x00591350: c74608c4117900 MOV dword ptr [ESI + 0x8],0x7911c4
    m.w32((s.si+0x00000008u), 0x007911c4u);
  }
  L00591357: { // 0x00591357: c7460cbc117900 MOV dword ptr [ESI + 0xc],0x7911bc
    m.w32((s.si+0x0000000cu), 0x007911bcu);
  }
  L0059135e: { // 0x0059135e: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00591360: { // 0x00591360: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00591361: { // 0x00591361: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_001ca970(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005ca970: { // 0x5ca970: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005ca971: { // 0x5ca971: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005ca972: { // 0x5ca972: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L005ca974: { // 0x5ca974: e89755e4ff CALL 0x0040ff10
    s.arithmetic_flags=flags; invoke(m,s,f,0x0040ff10u,6072697u); flags=s.arithmetic_flags;
  }
  L005ca979: { // 0x5ca979: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L005ca97b: { // 0x5ca97b: b8ff000000 MOV EAX,0xff
    s.ax = 0x000000ffu;
  }
  L005ca980: { // 0x5ca980: 895e24 MOV dword ptr [ESI + 0x24],EBX
    m.w32((s.si+0x00000024u), s.bx);
  }
  L005ca983: { // 0x5ca983: 895e28 MOV dword ptr [ESI + 0x28],EBX
    m.w32((s.si+0x00000028u), s.bx);
  }
  L005ca986: { // 0x5ca986: 895e2c MOV dword ptr [ESI + 0x2c],EBX
    m.w32((s.si+0x0000002cu), s.bx);
  }
  L005ca989: { // 0x5ca989: 89466c MOV dword ptr [ESI + 0x6c],EAX
    m.w32((s.si+0x0000006cu), s.ax);
  }
  L005ca98c: { // 0x5ca98c: 894670 MOV dword ptr [ESI + 0x70],EAX
    m.w32((s.si+0x00000070u), s.ax);
  }
  L005ca98f: { // 0x5ca98f: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L005ca991: { // 0x5ca991: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  L005ca994: { // 0x5ca994: 884676 MOV byte ptr [ESI + 0x76],AL
    m.w8((s.si+0x00000076u), (s.ax & 0xffu));
  }
  L005ca997: { // 0x5ca997: 88467d MOV byte ptr [ESI + 0x7d],AL
    m.w8((s.si+0x0000007du), (s.ax & 0xffu));
  }
  L005ca99a: { // 0x5ca99a: 888685000000 MOV byte ptr [ESI + 0x85],AL
    m.w8((s.si+0x00000085u), (s.ax & 0xffu));
  }
  L005ca9a0: { // 0x5ca9a0: 895e30 MOV dword ptr [ESI + 0x30],EBX
    m.w32((s.si+0x00000030u), s.bx);
  }
  L005ca9a3: { // 0x5ca9a3: 895e34 MOV dword ptr [ESI + 0x34],EBX
    m.w32((s.si+0x00000034u), s.bx);
  }
  L005ca9a6: { // 0x5ca9a6: 895e38 MOV dword ptr [ESI + 0x38],EBX
    m.w32((s.si+0x00000038u), s.bx);
  }
  L005ca9a9: { // 0x5ca9a9: 894e64 MOV dword ptr [ESI + 0x64],ECX
    m.w32((s.si+0x00000064u), s.cx);
  }
  L005ca9ac: { // 0x5ca9ac: 885e68 MOV byte ptr [ESI + 0x68],BL
    m.w8((s.si+0x00000068u), (s.bx & 0xffu));
  }
  L005ca9af: { // 0x5ca9af: 885e74 MOV byte ptr [ESI + 0x74],BL
    m.w8((s.si+0x00000074u), (s.bx & 0xffu));
  }
  L005ca9b2: { // 0x5ca9b2: 885e75 MOV byte ptr [ESI + 0x75],BL
    m.w8((s.si+0x00000075u), (s.bx & 0xffu));
  }
  L005ca9b5: { // 0x5ca9b5: 885e77 MOV byte ptr [ESI + 0x77],BL
    m.w8((s.si+0x00000077u), (s.bx & 0xffu));
  }
  L005ca9b8: { // 0x5ca9b8: 885e78 MOV byte ptr [ESI + 0x78],BL
    m.w8((s.si+0x00000078u), (s.bx & 0xffu));
  }
  L005ca9bb: { // 0x5ca9bb: 885e79 MOV byte ptr [ESI + 0x79],BL
    m.w8((s.si+0x00000079u), (s.bx & 0xffu));
  }
  L005ca9be: { // 0x5ca9be: 885e7a MOV byte ptr [ESI + 0x7a],BL
    m.w8((s.si+0x0000007au), (s.bx & 0xffu));
  }
  L005ca9c1: { // 0x5ca9c1: 885e7b MOV byte ptr [ESI + 0x7b],BL
    m.w8((s.si+0x0000007bu), (s.bx & 0xffu));
  }
  L005ca9c4: { // 0x5ca9c4: 885e7c MOV byte ptr [ESI + 0x7c],BL
    m.w8((s.si+0x0000007cu), (s.bx & 0xffu));
  }
  L005ca9c7: { // 0x5ca9c7: 898e80000000 MOV dword ptr [ESI + 0x80],ECX
    m.w32((s.si+0x00000080u), s.cx);
  }
  L005ca9cd: { // 0x5ca9cd: 889e84000000 MOV byte ptr [ESI + 0x84],BL
    m.w8((s.si+0x00000084u), (s.bx & 0xffu));
  }
  L005ca9d3: { // 0x5ca9d3: 8b0d68aaa500 MOV ECX,dword ptr [0x00a5aa68]
    s.cx = m.r32((0x00a5aa68u));
  }
  L005ca9d9: { // 0x5ca9d9: 8d8688000000 LEA EAX,[ESI + 0x88]
    s.ax = (s.si+0x00000088u);
  }
  L005ca9df: { // 0x5ca9df: 898e88000000 MOV dword ptr [ESI + 0x88],ECX
    m.w32((s.si+0x00000088u), s.cx);
  }
  L005ca9e5: { // 0x5ca9e5: 8b156caaa500 MOV EDX,dword ptr [0x00a5aa6c]
    s.dx = m.r32((0x00a5aa6cu));
  }
  L005ca9eb: { // 0x5ca9eb: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
  L005ca9ee: { // 0x5ca9ee: 8b0d70aaa500 MOV ECX,dword ptr [0x00a5aa70]
    s.cx = m.r32((0x00a5aa70u));
  }
  L005ca9f4: { // 0x5ca9f4: 899e94000000 MOV dword ptr [ESI + 0x94],EBX
    m.w32((s.si+0x00000094u), s.bx);
  }
  L005ca9fa: { // 0x5ca9fa: c70658247900 MOV dword ptr [ESI],0x792458
    m.w32((s.si), 0x00792458u);
  }
  L005caa00: { // 0x5caa00: 894808 MOV dword ptr [EAX + 0x8],ECX
    m.w32((s.ax+0x00000008u), s.cx);
  }
  L005caa03: { // 0x5caa03: 8d4e3c LEA ECX,[ESI + 0x3c]
    s.cx = (s.si+0x0000003cu);
  }
  L005caa06: { // 0x5caa06: c746043c247900 MOV dword ptr [ESI + 0x4],0x79243c
    m.w32((s.si+0x00000004u), 0x0079243cu);
  }
  L005caa0d: { // 0x5caa0d: c7460834247900 MOV dword ptr [ESI + 0x8],0x792434
    m.w32((s.si+0x00000008u), 0x00792434u);
  }
  L005caa14: { // 0x5caa14: c7460c2c247900 MOV dword ptr [ESI + 0xc],0x79242c
    m.w32((s.si+0x0000000cu), 0x0079242cu);
  }
  L005caa1b: { // 0x5caa1b: e8d0b1e3ff CALL 0x00405bf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00405bf0u,6072864u); flags=s.arithmetic_flags;
  }
  L005caa20: { // 0x5caa20: 8d4e50 LEA ECX,[ESI + 0x50]
    s.cx = (s.si+0x00000050u);
  }
  L005caa23: { // 0x5caa23: e8c8b1e3ff CALL 0x00405bf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00405bf0u,6072872u); flags=s.arithmetic_flags;
  }
  L005caa28: { // 0x5caa28: a1c07fa200 MOV EAX,[0x00a27fc0]
    s.ax = m.r32((0x00a27fc0u));
  }
  L005caa2d: { // 0x5caa2d: 8b0dc87fa200 MOV ECX,dword ptr [0x00a27fc8]
    s.cx = m.r32((0x00a27fc8u));
  }
  L005caa33: { // 0x5caa33: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L005caa35: { // 0x5caa35: 7c2c JL 0x005caa63
    if(integer::condition("JL",flags)) goto L005caa63;
  }
  L005caa37: { // 0x5caa37: 381dc57fa200 CMP byte ptr [0x00a27fc5],BL
    (void)integer::sub(m.r8((0x00a27fc5u)),(s.bx & 0xffu),8,flags);
  }
  L005caa3d: { // 0x5caa3d: 7504 JNZ 0x005caa43
    if(integer::condition("JNZ",flags)) goto L005caa43;
  }
  L005caa3f: { // 0x5caa3f: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L005caa41: { // 0x5caa41: 7538 JNZ 0x005caa7b
    if(integer::condition("JNZ",flags)) goto L005caa7b;
  }
  L005caa43: { // 0x5caa43: 8b0dcc7fa200 MOV ECX,dword ptr [0x00a27fcc]
    s.cx = m.r32((0x00a27fccu));
  }
  L005caa49: { // 0x5caa49: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L005caa4b: { // 0x5caa4b: 7e2e JLE 0x005caa7b
    if(integer::condition("JLE",flags)) goto L005caa7b;
  }
  L005caa4d: { // 0x5caa4d: 8b15b87fa200 MOV EDX,dword ptr [0x00a27fb8]
    s.dx = m.r32((0x00a27fb8u));
  }
  L005caa53: { // 0x5caa53: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L005caa55: { // 0x5caa55: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005caa56: { // 0x5caa56: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005caa57: { // 0x5caa57: b9b87fa200 MOV ECX,0xa27fb8
    s.cx = 0x00a27fb8u;
  }
  L005caa5c: { // 0x5caa5c: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),6072927u); flags=s.arithmetic_flags;
  }
  L005caa5f: { // 0x5caa5f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005caa61: { // 0x5caa61: 7418 JZ 0x005caa7b
    if(integer::condition("JZ",flags)) goto L005caa7b;
  }
  L005caa63: { // 0x5caa63: 8b0dc87fa200 MOV ECX,dword ptr [0x00a27fc8]
    s.cx = m.r32((0x00a27fc8u));
  }
  L005caa69: { // 0x5caa69: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L005caa6b: { // 0x5caa6b: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L005caa6c: { // 0x5caa6c: 890dc87fa200 MOV dword ptr [0x00a27fc8],ECX
    m.w32((0x00a27fc8u), s.cx);
  }
  L005caa72: { // 0x5caa72: 8b0dbc7fa200 MOV ECX,dword ptr [0x00a27fbc]
    s.cx = m.r32((0x00a27fbcu));
  }
  L005caa78: { // 0x5caa78: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L005caa7b: { // 0x5caa7b: a17088aa00 MOV EAX,[0x00aa8870]
    s.ax = m.r32((0x00aa8870u));
  }
  L005caa80: { // 0x5caa80: 8b0d7888aa00 MOV ECX,dword ptr [0x00aa8878]
    s.cx = m.r32((0x00aa8878u));
  }
  L005caa86: { // 0x5caa86: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L005caa88: { // 0x5caa88: 7c2c JL 0x005caab6
    if(integer::condition("JL",flags)) goto L005caab6;
  }
  L005caa8a: { // 0x5caa8a: 381d7588aa00 CMP byte ptr [0x00aa8875],BL
    (void)integer::sub(m.r8((0x00aa8875u)),(s.bx & 0xffu),8,flags);
  }
  L005caa90: { // 0x5caa90: 7504 JNZ 0x005caa96
    if(integer::condition("JNZ",flags)) goto L005caa96;
  }
  L005caa92: { // 0x5caa92: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L005caa94: { // 0x5caa94: 7538 JNZ 0x005caace
    if(integer::condition("JNZ",flags)) goto L005caace;
  }
  L005caa96: { // 0x5caa96: 8b0d7c88aa00 MOV ECX,dword ptr [0x00aa887c]
    s.cx = m.r32((0x00aa887cu));
  }
  L005caa9c: { // 0x5caa9c: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L005caa9e: { // 0x5caa9e: 7e2e JLE 0x005caace
    if(integer::condition("JLE",flags)) goto L005caace;
  }
  L005caaa0: { // 0x5caaa0: 8b156888aa00 MOV EDX,dword ptr [0x00aa8868]
    s.dx = m.r32((0x00aa8868u));
  }
  L005caaa6: { // 0x5caaa6: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L005caaa8: { // 0x5caaa8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005caaa9: { // 0x5caaa9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005caaaa: { // 0x5caaaa: b96888aa00 MOV ECX,0xaa8868
    s.cx = 0x00aa8868u;
  }
  L005caaaf: { // 0x5caaaf: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),6073010u); flags=s.arithmetic_flags;
  }
  L005caab2: { // 0x5caab2: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005caab4: { // 0x5caab4: 7418 JZ 0x005caace
    if(integer::condition("JZ",flags)) goto L005caace;
  }
  L005caab6: { // 0x5caab6: 8b0d7888aa00 MOV ECX,dword ptr [0x00aa8878]
    s.cx = m.r32((0x00aa8878u));
  }
  L005caabc: { // 0x5caabc: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L005caabe: { // 0x5caabe: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L005caabf: { // 0x5caabf: 890d7888aa00 MOV dword ptr [0x00aa8878],ECX
    m.w32((0x00aa8878u), s.cx);
  }
  L005caac5: { // 0x5caac5: 8b0d6c88aa00 MOV ECX,dword ptr [0x00aa886c]
    s.cx = m.r32((0x00aa886cu));
  }
  L005caacb: { // 0x5caacb: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L005caace: { // 0x5caace: a1c087aa00 MOV EAX,[0x00aa87c0]
    s.ax = m.r32((0x00aa87c0u));
  }
  L005caad3: { // 0x5caad3: 8b0dc887aa00 MOV ECX,dword ptr [0x00aa87c8]
    s.cx = m.r32((0x00aa87c8u));
  }
  L005caad9: { // 0x5caad9: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L005caadb: { // 0x5caadb: 7c2c JL 0x005cab09
    if(integer::condition("JL",flags)) goto L005cab09;
  }
  L005caadd: { // 0x5caadd: 381dc587aa00 CMP byte ptr [0x00aa87c5],BL
    (void)integer::sub(m.r8((0x00aa87c5u)),(s.bx & 0xffu),8,flags);
  }
  L005caae3: { // 0x5caae3: 7504 JNZ 0x005caae9
    if(integer::condition("JNZ",flags)) goto L005caae9;
  }
  L005caae5: { // 0x5caae5: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L005caae7: { // 0x5caae7: 7538 JNZ 0x005cab21
    if(integer::condition("JNZ",flags)) goto L005cab21;
  }
  L005caae9: { // 0x5caae9: 8b0dcc87aa00 MOV ECX,dword ptr [0x00aa87cc]
    s.cx = m.r32((0x00aa87ccu));
  }
  L005caaef: { // 0x5caaef: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L005caaf1: { // 0x5caaf1: 7e2e JLE 0x005cab21
    if(integer::condition("JLE",flags)) goto L005cab21;
  }
  L005caaf3: { // 0x5caaf3: 8b15b887aa00 MOV EDX,dword ptr [0x00aa87b8]
    s.dx = m.r32((0x00aa87b8u));
  }
  L005caaf9: { // 0x5caaf9: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L005caafb: { // 0x5caafb: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005caafc: { // 0x5caafc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005caafd: { // 0x5caafd: b9b887aa00 MOV ECX,0xaa87b8
    s.cx = 0x00aa87b8u;
  }
  L005cab02: { // 0x5cab02: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),6073093u); flags=s.arithmetic_flags;
  }
  L005cab05: { // 0x5cab05: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cab07: { // 0x5cab07: 7418 JZ 0x005cab21
    if(integer::condition("JZ",flags)) goto L005cab21;
  }
  L005cab09: { // 0x5cab09: 8b0dc887aa00 MOV ECX,dword ptr [0x00aa87c8]
    s.cx = m.r32((0x00aa87c8u));
  }
  L005cab0f: { // 0x5cab0f: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L005cab11: { // 0x5cab11: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L005cab12: { // 0x5cab12: 890dc887aa00 MOV dword ptr [0x00aa87c8],ECX
    m.w32((0x00aa87c8u), s.cx);
  }
  L005cab18: { // 0x5cab18: 8b0dbc87aa00 MOV ECX,dword ptr [0x00aa87bc]
    s.cx = m.r32((0x00aa87bcu));
  }
  L005cab1e: { // 0x5cab1e: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L005cab21: { // 0x5cab21: a16887aa00 MOV EAX,[0x00aa8768]
    s.ax = m.r32((0x00aa8768u));
  }
  L005cab26: { // 0x5cab26: 8b0d7087aa00 MOV ECX,dword ptr [0x00aa8770]
    s.cx = m.r32((0x00aa8770u));
  }
  L005cab2c: { // 0x5cab2c: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L005cab2e: { // 0x5cab2e: 7c2c JL 0x005cab5c
    if(integer::condition("JL",flags)) goto L005cab5c;
  }
  L005cab30: { // 0x5cab30: 381d6d87aa00 CMP byte ptr [0x00aa876d],BL
    (void)integer::sub(m.r8((0x00aa876du)),(s.bx & 0xffu),8,flags);
  }
  L005cab36: { // 0x5cab36: 7504 JNZ 0x005cab3c
    if(integer::condition("JNZ",flags)) goto L005cab3c;
  }
  L005cab38: { // 0x5cab38: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L005cab3a: { // 0x5cab3a: 7538 JNZ 0x005cab74
    if(integer::condition("JNZ",flags)) goto L005cab74;
  }
  L005cab3c: { // 0x5cab3c: 8b0d7487aa00 MOV ECX,dword ptr [0x00aa8774]
    s.cx = m.r32((0x00aa8774u));
  }
  L005cab42: { // 0x5cab42: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L005cab44: { // 0x5cab44: 7e2e JLE 0x005cab74
    if(integer::condition("JLE",flags)) goto L005cab74;
  }
  L005cab46: { // 0x5cab46: 8b156087aa00 MOV EDX,dword ptr [0x00aa8760]
    s.dx = m.r32((0x00aa8760u));
  }
  L005cab4c: { // 0x5cab4c: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L005cab4e: { // 0x5cab4e: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005cab4f: { // 0x5cab4f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005cab50: { // 0x5cab50: b96087aa00 MOV ECX,0xaa8760
    s.cx = 0x00aa8760u;
  }
  L005cab55: { // 0x5cab55: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),6073176u); flags=s.arithmetic_flags;
  }
  L005cab58: { // 0x5cab58: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cab5a: { // 0x5cab5a: 7418 JZ 0x005cab74
    if(integer::condition("JZ",flags)) goto L005cab74;
  }
  L005cab5c: { // 0x5cab5c: 8b0d7087aa00 MOV ECX,dword ptr [0x00aa8770]
    s.cx = m.r32((0x00aa8770u));
  }
  L005cab62: { // 0x5cab62: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L005cab64: { // 0x5cab64: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L005cab65: { // 0x5cab65: 890d7087aa00 MOV dword ptr [0x00aa8770],ECX
    m.w32((0x00aa8770u), s.cx);
  }
  L005cab6b: { // 0x5cab6b: 8b0d6487aa00 MOV ECX,dword ptr [0x00aa8764]
    s.cx = m.r32((0x00aa8764u));
  }
  L005cab71: { // 0x5cab71: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L005cab74: { // 0x5cab74: 8a4614 MOV AL,byte ptr [ESI + 0x14]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000014u)));
  }
  L005cab77: { // 0x5cab77: 0c02 OR AL,0x2
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000002u),8,flags));
  }
  L005cab79: { // 0x5cab79: 884614 MOV byte ptr [ESI + 0x14],AL
    m.w8((s.si+0x00000014u), (s.ax & 0xffu));
  }
  L005cab7c: { // 0x5cab7c: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L005cab7e: { // 0x5cab7e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005cab7f: { // 0x5cab7f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005cab80: { // 0x5cab80: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0003f5d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0043f5d0: { // 0x43f5d0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0043f5d1: { // 0x43f5d1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0043f5d3: { // 0x43f5d3: e8c87c2700 CALL 0x006b72a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006b72a0u,4453848u); flags=s.arithmetic_flags;
  }
  L0043f5d8: { // 0x43f5d8: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L0043f5de: { // 0x43f5de: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0043f5e0: { // 0x43f5e0: 7415 JZ 0x0043f5f7
    if(integer::condition("JZ",flags)) goto L0043f5f7;
  }
  L0043f5e2: { // 0x43f5e2: 8b4134 MOV EAX,dword ptr [ECX + 0x34]
    s.ax = m.r32((s.cx+0x00000034u));
  }
  L0043f5e5: { // 0x43f5e5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0043f5e6: { // 0x43f5e6: 8b90b8000000 MOV EDX,dword ptr [EAX + 0xb8]
    s.dx = m.r32((s.ax+0x000000b8u));
  }
  L0043f5ec: { // 0x43f5ec: 899634040000 MOV dword ptr [ESI + 0x434],EDX
    m.w32((s.si+0x00000434u), s.dx);
  }
  L0043f5f2: { // 0x43f5f2: e899a80a00 CALL 0x004e9e90
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e9e90u,4453879u); flags=s.arithmetic_flags;
  }
  L0043f5f7: { // 0x43f5f7: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L0043f5fd: { // 0x43f5fd: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0043f5ff: { // 0x43f5ff: 7461 JZ 0x0043f662
    if(integer::condition("JZ",flags)) goto L0043f662;
  }
  L0043f601: { // 0x43f601: 8b88a0000000 MOV ECX,dword ptr [EAX + 0xa0]
    s.cx = m.r32((s.ax+0x000000a0u));
  }
  L0043f607: { // 0x43f607: 894e6c MOV dword ptr [ESI + 0x6c],ECX
    m.w32((s.si+0x0000006cu), s.cx);
  }
  L0043f60a: { // 0x43f60a: 894e70 MOV dword ptr [ESI + 0x70],ECX
    m.w32((s.si+0x00000070u), s.cx);
  }
  L0043f60d: { // 0x43f60d: 8b88a8050000 MOV ECX,dword ptr [EAX + 0x5a8]
    s.cx = m.r32((s.ax+0x000005a8u));
  }
  L0043f613: { // 0x43f613: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  L0043f616: { // 0x43f616: 7506 JNZ 0x0043f61e
    if(integer::condition("JNZ",flags)) goto L0043f61e;
  }
  L0043f618: { // 0x43f618: 8b88ac050000 MOV ECX,dword ptr [EAX + 0x5ac]
    s.cx = m.r32((s.ax+0x000005acu));
  }
  L0043f61e: { // 0x43f61e: 898e54020000 MOV dword ptr [ESI + 0x254],ECX
    m.w32((s.si+0x00000254u), s.cx);
  }
  L0043f624: { // 0x43f624: 8b9038060000 MOV EDX,dword ptr [EAX + 0x638]
    s.dx = m.r32((s.ax+0x00000638u));
  }
  L0043f62a: { // 0x43f62a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0043f62b: { // 0x43f62b: 8d8ee0020000 LEA ECX,[ESI + 0x2e0]
    s.cx = (s.si+0x000002e0u);
  }
  L0043f631: { // 0x43f631: e8ca940700 CALL 0x004b8b00
    s.arithmetic_flags=flags; invoke(m,s,f,0x004b8b00u,4453942u); flags=s.arithmetic_flags;
  }
  L0043f636: { // 0x43f636: 8b8e18040000 MOV ECX,dword ptr [ESI + 0x418]
    s.cx = m.r32((s.si+0x00000418u));
  }
  L0043f63c: { // 0x43f63c: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0043f63e: { // 0x43f63e: ff90c0000000 CALL dword ptr [EAX + 0xc0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000000c0u)),4453956u); flags=s.arithmetic_flags;
  }
  L0043f644: { // 0x43f644: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0043f646: { // 0x43f646: 7508 JNZ 0x0043f650
    if(integer::condition("JNZ",flags)) goto L0043f650;
  }
  L0043f648: { // 0x43f648: 8886ac050000 MOV byte ptr [ESI + 0x5ac],AL
    m.w8((s.si+0x000005acu), (s.ax & 0xffu));
  }
  L0043f64e: { // 0x43f64e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0043f64f: { // 0x43f64f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0043f650: { // 0x43f650: 8b8e18040000 MOV ECX,dword ptr [ESI + 0x418]
    s.cx = m.r32((s.si+0x00000418u));
  }
  L0043f656: { // 0x43f656: e835ef0100 CALL 0x0045e590
    s.arithmetic_flags=flags; invoke(m,s,f,0x0045e590u,4453979u); flags=s.arithmetic_flags;
  }
  L0043f65b: { // 0x43f65b: c686b905000001 MOV byte ptr [ESI + 0x5b9],0x1
    m.w8((s.si+0x000005b9u), 0x00000001u);
  }
  L0043f662: { // 0x43f662: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0043f663: { // 0x43f663: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002b72a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006b72a0: { // 0x6b72a0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006b72a1: { // 0x6b72a1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006b72a3: { // 0x6b72a3: 8b86b4010000 MOV EAX,dword ptr [ESI + 0x1b4]
    s.ax = m.r32((s.si+0x000001b4u));
  }
  L006b72a9: { // 0x6b72a9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006b72ab: { // 0x6b72ab: 7418 JZ 0x006b72c5
    if(integer::condition("JZ",flags)) goto L006b72c5;
  }
  L006b72ad: { // 0x6b72ad: 3905e4e0a100 CMP dword ptr [0x00a1e0e4],EAX
    (void)integer::sub(m.r32((0x00a1e0e4u)),s.ax,32,flags);
  }
  L006b72b3: { // 0x6b72b3: 7509 JNZ 0x006b72be
    if(integer::condition("JNZ",flags)) goto L006b72be;
  }
  L006b72b5: { // 0x6b72b5: c6867203000001 MOV byte ptr [ESI + 0x372],0x1
    m.w8((s.si+0x00000372u), 0x00000001u);
  }
  L006b72bc: { // 0x6b72bc: eb07 JMP 0x006b72c5
    goto L006b72c5;
  }
  L006b72be: { // 0x6b72be: c6867203000000 MOV byte ptr [ESI + 0x372],0x0
    m.w8((s.si+0x00000372u), 0x00000000u);
  }
  L006b72c5: { // 0x6b72c5: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006b72c7: { // 0x6b72c7: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b72c9: { // 0x6b72c9: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7041743u); flags=s.arithmetic_flags;
  }
  L006b72cf: { // 0x6b72cf: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006b72d1: { // 0x6b72d1: 0f849b020000 JZ 0x006b7572
    if(integer::condition("JZ",flags)) goto L006b7572;
  }
  L006b72d7: { // 0x6b72d7: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b72d9: { // 0x6b72d9: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b72db: { // 0x6b72db: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7041761u); flags=s.arithmetic_flags;
  }
  L006b72e1: { // 0x6b72e1: 8b8840050000 MOV ECX,dword ptr [EAX + 0x540]
    s.cx = m.r32((s.ax+0x00000540u));
  }
  L006b72e7: { // 0x6b72e7: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006b72e9: { // 0x6b72e9: 740b JZ 0x006b72f6
    if(integer::condition("JZ",flags)) goto L006b72f6;
  }
  L006b72eb: { // 0x6b72eb: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006b72ec: { // 0x6b72ec: b920a68100 MOV ECX,0x81a620
    s.cx = 0x0081a620u;
  }
  L006b72f1: { // 0x6b72f1: e80af2d7ff CALL 0x00436500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00436500u,7041782u); flags=s.arithmetic_flags;
  }
  L006b72f6: { // 0x6b72f6: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006b72f8: { // 0x6b72f8: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b72fa: { // 0x6b72fa: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7041792u); flags=s.arithmetic_flags;
  }
  L006b7300: { // 0x6b7300: 8b88080b0000 MOV ECX,dword ptr [EAX + 0xb08]
    s.cx = m.r32((s.ax+0x00000b08u));
  }
  L006b7306: { // 0x6b7306: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006b7308: { // 0x6b7308: 7468 JZ 0x006b7372
    if(integer::condition("JZ",flags)) goto L006b7372;
  }
  L006b730a: { // 0x6b730a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006b730b: { // 0x6b730b: 6a74 PUSH 0x74
    f.push(m,0x00000074u);
  }
  L006b730d: { // 0x6b730d: e845660b00 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,7041810u); flags=s.arithmetic_flags;
  }
  L006b7312: { // 0x6b7312: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L006b7314: { // 0x6b7314: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L006b7317: { // 0x6b7317: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L006b7319: { // 0x6b7319: 744e JZ 0x006b7369
    if(integer::condition("JZ",flags)) goto L006b7369;
  }
  L006b731b: { // 0x6b731b: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b731d: { // 0x6b731d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b731f: { // 0x6b731f: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7041829u); flags=s.arithmetic_flags;
  }
  L006b7325: { // 0x6b7325: 8b80140b0000 MOV EAX,dword ptr [EAX + 0xb14]
    s.ax = m.r32((s.ax+0x00000b14u));
  }
  L006b732b: { // 0x6b732b: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b732d: { // 0x6b732d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006b732e: { // 0x6b732e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b7330: { // 0x6b7330: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7041846u); flags=s.arithmetic_flags;
  }
  L006b7336: { // 0x6b7336: 8b80100b0000 MOV EAX,dword ptr [EAX + 0xb10]
    s.ax = m.r32((s.ax+0x00000b10u));
  }
  L006b733c: { // 0x6b733c: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b733e: { // 0x6b733e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006b733f: { // 0x6b733f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b7341: { // 0x6b7341: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7041863u); flags=s.arithmetic_flags;
  }
  L006b7347: { // 0x6b7347: 8b800c0b0000 MOV EAX,dword ptr [EAX + 0xb0c]
    s.ax = m.r32((s.ax+0x00000b0cu));
  }
  L006b734d: { // 0x6b734d: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b734f: { // 0x6b734f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006b7350: { // 0x6b7350: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b7352: { // 0x6b7352: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7041880u); flags=s.arithmetic_flags;
  }
  L006b7358: { // 0x6b7358: 8b80080b0000 MOV EAX,dword ptr [EAX + 0xb08]
    s.ax = m.r32((s.ax+0x00000b08u));
  }
  L006b735e: { // 0x6b735e: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006b7360: { // 0x6b7360: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006b7361: { // 0x6b7361: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006b7362: { // 0x6b7362: e8a97afcff CALL 0x0067ee10
    s.arithmetic_flags=flags; invoke(m,s,f,0x0067ee10u,7041895u); flags=s.arithmetic_flags;
  }
  L006b7367: { // 0x6b7367: eb02 JMP 0x006b736b
    goto L006b736b;
  }
  L006b7369: { // 0x6b7369: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006b736b: { // 0x6b736b: 898638020000 MOV dword ptr [ESI + 0x238],EAX
    m.w32((s.si+0x00000238u), s.ax);
  }
  L006b7371: { // 0x6b7371: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b7372: { // 0x6b7372: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b7374: { // 0x6b7374: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006b7376: { // 0x6b7376: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b7378: { // 0x6b7378: ff929c030000 CALL dword ptr [EDX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000039cu)),7041918u); flags=s.arithmetic_flags;
  }
  L006b737e: { // 0x6b737e: 833800 CMP dword ptr [EAX],0x0
    (void)integer::sub(m.r32((s.ax)),0x00000000u,32,flags);
  }
  L006b7381: { // 0x6b7381: 743e JZ 0x006b73c1
    if(integer::condition("JZ",flags)) goto L006b73c1;
  }
  L006b7383: { // 0x6b7383: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006b7385: { // 0x6b7385: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006b7387: { // 0x6b7387: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b7389: { // 0x6b7389: ff909c030000 CALL dword ptr [EAX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000039cu)),7041935u); flags=s.arithmetic_flags;
  }
  L006b738f: { // 0x6b738f: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L006b7391: { // 0x6b7391: 8b91ac000000 MOV EDX,dword ptr [ECX + 0xac]
    s.dx = m.r32((s.cx+0x000000acu));
  }
  L006b7397: { // 0x6b7397: 8a8253010000 MOV AL,byte ptr [EDX + 0x153]
    s.ax = with_al(s.ax, m.r8((s.dx+0x00000153u)));
  }
  L006b739d: { // 0x6b739d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b739f: { // 0x6b739f: 7420 JZ 0x006b73c1
    if(integer::condition("JZ",flags)) goto L006b73c1;
  }
  L006b73a1: { // 0x6b73a1: 6a30 PUSH 0x30
    f.push(m,0x00000030u);
  }
  L006b73a3: { // 0x6b73a3: e8af650b00 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,7041960u); flags=s.arithmetic_flags;
  }
  L006b73a8: { // 0x6b73a8: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L006b73ab: { // 0x6b73ab: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006b73ad: { // 0x6b73ad: 740a JZ 0x006b73b9
    if(integer::condition("JZ",flags)) goto L006b73b9;
  }
  L006b73af: { // 0x6b73af: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006b73b0: { // 0x6b73b0: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006b73b2: { // 0x6b73b2: e82906dbff CALL 0x004679e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004679e0u,7041975u); flags=s.arithmetic_flags;
  }
  L006b73b7: { // 0x6b73b7: eb02 JMP 0x006b73bb
    goto L006b73bb;
  }
  L006b73b9: { // 0x6b73b9: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006b73bb: { // 0x6b73bb: 898630020000 MOV dword ptr [ESI + 0x230],EAX
    m.w32((s.si+0x00000230u), s.ax);
  }
  L006b73c1: { // 0x6b73c1: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006b73c3: { // 0x6b73c3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b73c5: { // 0x6b73c5: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),7041992u); flags=s.arithmetic_flags;
  }
  L006b73c8: { // 0x6b73c8: 83f806 CMP EAX,0x6
    (void)integer::sub(s.ax,0x00000006u,32,flags);
  }
  L006b73cb: { // 0x6b73cb: 744f JZ 0x006b741c
    if(integer::condition("JZ",flags)) goto L006b741c;
  }
  L006b73cd: { // 0x6b73cd: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b73cf: { // 0x6b73cf: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006b73d1: { // 0x6b73d1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b73d3: { // 0x6b73d3: ff929c030000 CALL dword ptr [EDX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000039cu)),7042009u); flags=s.arithmetic_flags;
  }
  L006b73d9: { // 0x6b73d9: 833800 CMP dword ptr [EAX],0x0
    (void)integer::sub(m.r32((s.ax)),0x00000000u,32,flags);
  }
  L006b73dc: { // 0x6b73dc: 743e JZ 0x006b741c
    if(integer::condition("JZ",flags)) goto L006b741c;
  }
  L006b73de: { // 0x6b73de: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006b73e0: { // 0x6b73e0: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006b73e2: { // 0x6b73e2: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b73e4: { // 0x6b73e4: ff909c030000 CALL dword ptr [EAX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000039cu)),7042026u); flags=s.arithmetic_flags;
  }
  L006b73ea: { // 0x6b73ea: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L006b73ec: { // 0x6b73ec: 8b91ac000000 MOV EDX,dword ptr [ECX + 0xac]
    s.dx = m.r32((s.cx+0x000000acu));
  }
  L006b73f2: { // 0x6b73f2: 8a8256010000 MOV AL,byte ptr [EDX + 0x156]
    s.ax = with_al(s.ax, m.r8((s.dx+0x00000156u)));
  }
  L006b73f8: { // 0x6b73f8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b73fa: { // 0x6b73fa: 7420 JZ 0x006b741c
    if(integer::condition("JZ",flags)) goto L006b741c;
  }
  L006b73fc: { // 0x6b73fc: 6a58 PUSH 0x58
    f.push(m,0x00000058u);
  }
  L006b73fe: { // 0x6b73fe: e854650b00 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,7042051u); flags=s.arithmetic_flags;
  }
  L006b7403: { // 0x6b7403: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L006b7406: { // 0x6b7406: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006b7408: { // 0x6b7408: 740a JZ 0x006b7414
    if(integer::condition("JZ",flags)) goto L006b7414;
  }
  L006b740a: { // 0x6b740a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006b740b: { // 0x6b740b: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006b740d: { // 0x6b740d: e80e6af4ff CALL 0x005fde20
    s.arithmetic_flags=flags; invoke(m,s,f,0x005fde20u,7042066u); flags=s.arithmetic_flags;
  }
  L006b7412: { // 0x6b7412: eb02 JMP 0x006b7416
    goto L006b7416;
  }
  L006b7414: { // 0x6b7414: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006b7416: { // 0x6b7416: 898688050000 MOV dword ptr [ESI + 0x588],EAX
    m.w32((s.si+0x00000588u), s.ax);
  }
  L006b741c: { // 0x6b741c: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006b741e: { // 0x6b741e: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006b7420: { // 0x6b7420: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b7422: { // 0x6b7422: ff909c030000 CALL dword ptr [EAX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000039cu)),7042088u); flags=s.arithmetic_flags;
  }
  L006b7428: { // 0x6b7428: 833800 CMP dword ptr [EAX],0x0
    (void)integer::sub(m.r32((s.ax)),0x00000000u,32,flags);
  }
  L006b742b: { // 0x6b742b: 745b JZ 0x006b7488
    if(integer::condition("JZ",flags)) goto L006b7488;
  }
  L006b742d: { // 0x6b742d: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b742f: { // 0x6b742f: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006b7431: { // 0x6b7431: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b7433: { // 0x6b7433: ff929c030000 CALL dword ptr [EDX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000039cu)),7042105u); flags=s.arithmetic_flags;
  }
  L006b7439: { // 0x6b7439: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L006b743b: { // 0x6b743b: 8b88ac000000 MOV ECX,dword ptr [EAX + 0xac]
    s.cx = m.r32((s.ax+0x000000acu));
  }
  L006b7441: { // 0x6b7441: 8a8157010000 MOV AL,byte ptr [ECX + 0x157]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000157u)));
  }
  L006b7447: { // 0x6b7447: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b7449: { // 0x6b7449: 743d JZ 0x006b7488
    if(integer::condition("JZ",flags)) goto L006b7488;
  }
  L006b744b: { // 0x6b744b: 6a50 PUSH 0x50
    f.push(m,0x00000050u);
  }
  L006b744d: { // 0x6b744d: e805650b00 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,7042130u); flags=s.arithmetic_flags;
  }
  L006b7452: { // 0x6b7452: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L006b7455: { // 0x6b7455: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006b7457: { // 0x6b7457: 740a JZ 0x006b7463
    if(integer::condition("JZ",flags)) goto L006b7463;
  }
  L006b7459: { // 0x6b7459: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006b745a: { // 0x6b745a: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006b745c: { // 0x6b745c: e86fff0100 CALL 0x006d73d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d73d0u,7042145u); flags=s.arithmetic_flags;
  }
  L006b7461: { // 0x6b7461: eb02 JMP 0x006b7465
    goto L006b7465;
  }
  L006b7463: { // 0x6b7463: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006b7465: { // 0x6b7465: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b7467: { // 0x6b7467: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006b7469: { // 0x6b7469: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b746b: { // 0x6b746b: 898608020000 MOV dword ptr [ESI + 0x208],EAX
    m.w32((s.si+0x00000208u), s.ax);
  }
  L006b7471: { // 0x6b7471: ff929c030000 CALL dword ptr [EDX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000039cu)),7042167u); flags=s.arithmetic_flags;
  }
  L006b7477: { // 0x6b7477: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L006b7479: { // 0x6b7479: 8b8e08020000 MOV ECX,dword ptr [ESI + 0x208]
    s.cx = m.r32((s.si+0x00000208u));
  }
  L006b747f: { // 0x6b747f: 8b90a4000000 MOV EDX,dword ptr [EAX + 0xa4]
    s.dx = m.r32((s.ax+0x000000a4u));
  }
  L006b7485: { // 0x6b7485: 89514c MOV dword ptr [ECX + 0x4c],EDX
    m.w32((s.cx+0x0000004cu), s.dx);
  }
  L006b7488: { // 0x6b7488: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006b748a: { // 0x6b748a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b748c: { // 0x6b748c: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7042194u); flags=s.arithmetic_flags;
  }
  L006b7492: { // 0x6b7492: 8a88f70a0000 MOV CL,byte ptr [EAX + 0xaf7]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000af7u)));
  }
  L006b7498: { // 0x6b7498: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006b749a: { // 0x6b749a: 7456 JZ 0x006b74f2
    if(integer::condition("JZ",flags)) goto L006b74f2;
  }
  L006b749c: { // 0x6b749c: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b749e: { // 0x6b749e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b74a0: { // 0x6b74a0: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7042214u); flags=s.arithmetic_flags;
  }
  L006b74a6: { // 0x6b74a6: 8a88f80a0000 MOV CL,byte ptr [EAX + 0xaf8]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000af8u)));
  }
  L006b74ac: { // 0x6b74ac: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006b74ae: { // 0x6b74ae: 7442 JZ 0x006b74f2
    if(integer::condition("JZ",flags)) goto L006b74f2;
  }
  L006b74b0: { // 0x6b74b0: 8b86b4010000 MOV EAX,dword ptr [ESI + 0x1b4]
    s.ax = m.r32((s.si+0x000001b4u));
  }
  L006b74b6: { // 0x6b74b6: c6867001000001 MOV byte ptr [ESI + 0x170],0x1
    m.w8((s.si+0x00000170u), 0x00000001u);
  }
  L006b74bd: { // 0x6b74bd: 898610040000 MOV dword ptr [ESI + 0x410],EAX
    m.w32((s.si+0x00000410u), s.ax);
  }
  L006b74c3: { // 0x6b74c3: 8b8830010000 MOV ECX,dword ptr [EAX + 0x130]
    s.cx = m.r32((s.ax+0x00000130u));
  }
  L006b74c9: { // 0x6b74c9: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006b74cb: { // 0x6b74cb: 7513 JNZ 0x006b74e0
    if(integer::condition("JNZ",flags)) goto L006b74e0;
  }
  L006b74cd: { // 0x6b74cd: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L006b74d2: { // 0x6b74d2: 8b886c0b0000 MOV ECX,dword ptr [EAX + 0xb6c]
    s.cx = m.r32((s.ax+0x00000b6cu));
  }
  L006b74d8: { // 0x6b74d8: 898e0c040000 MOV dword ptr [ESI + 0x40c],ECX
    m.w32((s.si+0x0000040cu), s.cx);
  }
  L006b74de: { // 0x6b74de: eb12 JMP 0x006b74f2
    goto L006b74f2;
  }
  L006b74e0: { // 0x6b74e0: 8b15881b8200 MOV EDX,dword ptr [0x00821b88]
    s.dx = m.r32((0x00821b88u));
  }
  L006b74e6: { // 0x6b74e6: 8b82700b0000 MOV EAX,dword ptr [EDX + 0xb70]
    s.ax = m.r32((s.dx+0x00000b70u));
  }
  L006b74ec: { // 0x6b74ec: 89860c040000 MOV dword ptr [ESI + 0x40c],EAX
    m.w32((s.si+0x0000040cu), s.ax);
  }
  L006b74f2: { // 0x6b74f2: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b74f4: { // 0x6b74f4: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b74f6: { // 0x6b74f6: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7042300u); flags=s.arithmetic_flags;
  }
  L006b74fc: { // 0x6b74fc: 8b88b00a0000 MOV ECX,dword ptr [EAX + 0xab0]
    s.cx = m.r32((s.ax+0x00000ab0u));
  }
  L006b7502: { // 0x6b7502: 05b00a0000 ADD EAX,0xab0
    s.ax = integer::add(s.ax,0x00000ab0u,32,flags);
  }
  L006b7507: { // 0x6b7507: 898e30030000 MOV dword ptr [ESI + 0x330],ECX
    m.w32((s.si+0x00000330u), s.cx);
  }
  L006b750d: { // 0x6b750d: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L006b7510: { // 0x6b7510: 899634030000 MOV dword ptr [ESI + 0x334],EDX
    m.w32((s.si+0x00000334u), s.dx);
  }
  L006b7516: { // 0x6b7516: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L006b7519: { // 0x6b7519: 898e38030000 MOV dword ptr [ESI + 0x338],ECX
    m.w32((s.si+0x00000338u), s.cx);
  }
  L006b751f: { // 0x6b751f: 8b500c MOV EDX,dword ptr [EAX + 0xc]
    s.dx = m.r32((s.ax+0x0000000cu));
  }
  L006b7522: { // 0x6b7522: 89963c030000 MOV dword ptr [ESI + 0x33c],EDX
    m.w32((s.si+0x0000033cu), s.dx);
  }
  L006b7528: { // 0x6b7528: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006b752a: { // 0x6b752a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b752c: { // 0x6b752c: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7042354u); flags=s.arithmetic_flags;
  }
  L006b7532: { // 0x6b7532: 8b88c40a0000 MOV ECX,dword ptr [EAX + 0xac4]
    s.cx = m.r32((s.ax+0x00000ac4u));
  }
  L006b7538: { // 0x6b7538: 05c40a0000 ADD EAX,0xac4
    s.ax = integer::add(s.ax,0x00000ac4u,32,flags);
  }
  L006b753d: { // 0x6b753d: 898e50030000 MOV dword ptr [ESI + 0x350],ECX
    m.w32((s.si+0x00000350u), s.cx);
  }
  L006b7543: { // 0x6b7543: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L006b7546: { // 0x6b7546: 899654030000 MOV dword ptr [ESI + 0x354],EDX
    m.w32((s.si+0x00000354u), s.dx);
  }
  L006b754c: { // 0x6b754c: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L006b754f: { // 0x6b754f: 898e58030000 MOV dword ptr [ESI + 0x358],ECX
    m.w32((s.si+0x00000358u), s.cx);
  }
  L006b7555: { // 0x6b7555: 8b500c MOV EDX,dword ptr [EAX + 0xc]
    s.dx = m.r32((s.ax+0x0000000cu));
  }
  L006b7558: { // 0x6b7558: 89965c030000 MOV dword ptr [ESI + 0x35c],EDX
    m.w32((s.si+0x0000035cu), s.dx);
  }
  L006b755e: { // 0x6b755e: c786ec03000001000000 MOV dword ptr [ESI + 0x3ec],0x1
    m.w32((s.si+0x000003ecu), 0x00000001u);
  }
  L006b7568: { // 0x6b7568: c786f003000000000000 MOV dword ptr [ESI + 0x3f0],0x0
    m.w32((s.si+0x000003f0u), 0x00000000u);
  }
  L006b7572: { // 0x6b7572: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b7573: { // 0x6b7573: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0003d130(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0043d130: { // 0x0043d130: 83ec34 SUB ESP, 0x34
    f.sp = integer::sub(f.sp,0x00000034u,32,flags);
  }
  L0043d133: { // 0x0043d133: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0043d134: { // 0x0043d134: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0043d135: { // 0x0043d135: 8b6c2440 MOV EBP, dword ptr [ESP + 0x40]
    s.bp = m.r32((f.sp+0x00000040u));
  }
  L0043d139: { // 0x0043d139: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0043d13a: { // 0x0043d13a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0043d13b: { // 0x0043d13b: 6a01 PUSH 1
    f.push(m,1u);
  }
  L0043d13d: { // 0x0043d13d: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0043d13f: { // 0x0043d13f: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L0043d141: { // 0x0043d141: 6aff PUSH -1
    f.push(m,4294967295u);
  }
  L0043d143: { // 0x0043d143: 6aff PUSH -1
    f.push(m,4294967295u);
  }
  L0043d145: { // 0x0043d145: 8b3e MOV EDI, dword ptr [ESI]
    s.di = m.r32((s.si));
  }
  L0043d147: { // 0x0043d147: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0043d148: { // 0x0043d148: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0043d14d: { // 0x0043d14d: e83e831000 CALL 0x545490
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545490u,4444498u); flags=s.arithmetic_flags;
  }
  L0043d152: { // 0x0043d152: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0043d153: { // 0x0043d153: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0043d155: { // 0x0043d155: ff9794010000 CALL dword ptr [EDI + 0x194]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.di+0x00000194u)),4444507u); flags=s.arithmetic_flags;
  }
  L0043d15b: { // 0x0043d15b: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0043d15d: { // 0x0043d15d: 0f94c3 SETZ BL
    s.bx = with_al(s.bx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L0043d160: { // 0x0043d160: 84db TEST BL, BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L0043d162: { // 0x0043d162: 885c2413 MOV byte ptr [ESP + 0x13], BL
    m.w8((f.sp+0x00000013u), (s.bx & 0xffu));
  }
  L0043d166: { // 0x0043d166: 0f84b8010000 JZ 0x43d324
    if(integer::condition("JZ",flags)) goto L0043d324;
  }
  L0043d16c: { // 0x0043d16c: a1881b8200 MOV EAX, dword ptr [0x821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L0043d171: { // 0x0043d171: 8b8e18040000 MOV ECX, dword ptr [ESI + 0x418]
    s.cx = m.r32((s.si+0x00000418u));
  }
  L0043d177: { // 0x0043d177: 3b888c070000 CMP ECX, dword ptr [EAX + 0x78c]
    (void)integer::sub(s.cx,m.r32((s.ax+0x0000078cu)),32,flags);
  }
  L0043d17d: { // 0x0043d17d: 7537 JNZ 0x43d1b6
    if(integer::condition("JNZ",flags)) goto L0043d1b6;
  }
  L0043d17f: { // 0x0043d17f: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0043d180: { // 0x0043d180: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0043d185: { // 0x0043d185: e806831000 CALL 0x545490
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545490u,4444554u); flags=s.arithmetic_flags;
  }
  L0043d18a: { // 0x0043d18a: 8b4850 MOV ECX, dword ptr [EAX + 0x50]
    s.cx = m.r32((s.ax+0x00000050u));
  }
  L0043d18d: { // 0x0043d18d: 33d2 XOR EDX, EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0043d18f: { // 0x0043d18f: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0043d191: { // 0x0043d191: 7c09 JL 0x43d19c
    if(integer::condition("JL",flags)) goto L0043d19c;
  }
  L0043d193: { // 0x0043d193: 8b15cca5a100 MOV EDX, dword ptr [0xa1a5cc]
    s.dx = m.r32((0x00a1a5ccu));
  }
  L0043d199: { // 0x0043d199: 8b148a MOV EDX, dword ptr [EDX + ECX*4]
    s.dx = m.r32((s.dx+(s.cx * 4u)));
  }
  L0043d19c: { // 0x0043d19c: 8b8eb4010000 MOV ECX, dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L0043d1a2: { // 0x0043d1a2: 3bd1 CMP EDX, ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L0043d1a4: { // 0x0043d1a4: 0f857a010000 JNZ 0x43d324
    if(integer::condition("JNZ",flags)) goto L0043d324;
  }
  L0043d1aa: { // 0x0043d1aa: 8b5044 MOV EDX, dword ptr [EAX + 0x44]
    s.dx = m.r32((s.ax+0x00000044u));
  }
  L0043d1ad: { // 0x0043d1ad: 83fa02 CMP EDX, 2
    (void)integer::sub(s.dx,2u,32,flags);
  }
  L0043d1b0: { // 0x0043d1b0: 7454 JZ 0x43d206
    if(integer::condition("JZ",flags)) goto L0043d206;
  }
  L0043d1b2: { // 0x0043d1b2: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0043d1b4: { // 0x0043d1b4: eb4a JMP 0x43d200
    goto L0043d200;
  }
  L0043d1b6: { // 0x0043d1b6: 8b81ec0b0000 MOV EAX, dword ptr [ECX + 0xbec]
    s.ax = m.r32((s.cx+0x00000becu));
  }
  L0043d1bc: { // 0x0043d1bc: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0043d1be: { // 0x0043d1be: 7456 JZ 0x43d216
    if(integer::condition("JZ",flags)) goto L0043d216;
  }
  L0043d1c0: { // 0x0043d1c0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0043d1c1: { // 0x0043d1c1: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0043d1c6: { // 0x0043d1c6: e8c5821000 CALL 0x545490
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545490u,4444619u); flags=s.arithmetic_flags;
  }
  L0043d1cb: { // 0x0043d1cb: 8b4850 MOV ECX, dword ptr [EAX + 0x50]
    s.cx = m.r32((s.ax+0x00000050u));
  }
  L0043d1ce: { // 0x0043d1ce: 33d2 XOR EDX, EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0043d1d0: { // 0x0043d1d0: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0043d1d2: { // 0x0043d1d2: 7c09 JL 0x43d1dd
    if(integer::condition("JL",flags)) goto L0043d1dd;
  }
  L0043d1d4: { // 0x0043d1d4: 8b15cca5a100 MOV EDX, dword ptr [0xa1a5cc]
    s.dx = m.r32((0x00a1a5ccu));
  }
  L0043d1da: { // 0x0043d1da: 8b148a MOV EDX, dword ptr [EDX + ECX*4]
    s.dx = m.r32((s.dx+(s.cx * 4u)));
  }
  L0043d1dd: { // 0x0043d1dd: 8b8eb4010000 MOV ECX, dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L0043d1e3: { // 0x0043d1e3: 3bd1 CMP EDX, ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L0043d1e5: { // 0x0043d1e5: 0f8539010000 JNZ 0x43d324
    if(integer::condition("JNZ",flags)) goto L0043d324;
  }
  L0043d1eb: { // 0x0043d1eb: 8b9618040000 MOV EDX, dword ptr [ESI + 0x418]
    s.dx = m.r32((s.si+0x00000418u));
  }
  L0043d1f1: { // 0x0043d1f1: 8b7844 MOV EDI, dword ptr [EAX + 0x44]
    s.di = m.r32((s.ax+0x00000044u));
  }
  L0043d1f4: { // 0x0043d1f4: 8b92ec0b0000 MOV EDX, dword ptr [EDX + 0xbec]
    s.dx = m.r32((s.dx+0x00000becu));
  }
  L0043d1fa: { // 0x0043d1fa: 3bba64020000 CMP EDI, dword ptr [EDX + 0x264]
    (void)integer::sub(s.di,m.r32((s.dx+0x00000264u)),32,flags);
  }
  L0043d200: { // 0x0043d200: 0f851e010000 JNZ 0x43d324
    if(integer::condition("JNZ",flags)) goto L0043d324;
  }
  L0043d206: { // 0x0043d206: 83c024 ADD EAX, 0x24
    s.ax = integer::add(s.ax,0x00000024u,32,flags);
  }
  L0043d209: { // 0x0043d209: 6a01 PUSH 1
    f.push(m,1u);
  }
  L0043d20b: { // 0x0043d20b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0043d20c: { // 0x0043d20c: e8afa60a00 CALL 0x4e78c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e78c0u,4444689u); flags=s.arithmetic_flags;
  }
  L0043d211: { // 0x0043d211: e90e010000 JMP 0x43d324
    goto L0043d324;
  }
  L0043d216: { // 0x0043d216: 8a8151130000 MOV AL, byte ptr [ECX + 0x1351]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00001351u)));
  }
  L0043d21c: { // 0x0043d21c: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0043d21e: { // 0x0043d21e: 0f8400010000 JZ 0x43d324
    if(integer::condition("JZ",flags)) goto L0043d324;
  }
  L0043d224: { // 0x0043d224: 8b4500 MOV EAX, dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L0043d227: { // 0x0043d227: 6a01 PUSH 1
    f.push(m,1u);
  }
  L0043d229: { // 0x0043d229: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0043d22a: { // 0x0043d22a: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0043d230: { // 0x0043d230: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0043d232: { // 0x0043d232: c1f808 SAR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L0043d235: { // 0x0043d235: 6689442418 MOV word ptr [ESP + 0x18], AX
    m.w16((f.sp+0x00000018u), (s.ax & 0xffffu));
  }
  L0043d23a: { // 0x0043d23a: 8b4504 MOV EAX, dword ptr [EBP + 4]
    s.ax = m.r32((s.bp+4u));
  }
  L0043d23d: { // 0x0043d23d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0043d23e: { // 0x0043d23e: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0043d244: { // 0x0043d244: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0043d246: { // 0x0043d246: c1f808 SAR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L0043d249: { // 0x0043d249: 668944241a MOV word ptr [ESP + 0x1a], AX
    m.w16((f.sp+0x0000001au), (s.ax & 0xffffu));
  }
  L0043d24e: { // 0x0043d24e: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0043d250: { // 0x0043d250: ff9090000000 CALL dword ptr [EAX + 0x90]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000090u)),4444758u); flags=s.arithmetic_flags;
  }
  L0043d256: { // 0x0043d256: 8bd8 MOV EBX, EAX
    s.bx = s.ax;
  }
  L0043d258: { // 0x0043d258: 668b03 MOV AX, word ptr [EBX]
    s.ax = with_ax(s.ax, m.r16((s.bx)));
  }
  L0043d25b: { // 0x0043d25b: 663dff7f CMP AX, 0x7fff
    (void)integer::sub((s.ax & 0xffffu),0x00007fffu,16,flags);
  }
  L0043d25f: { // 0x0043d25f: 750a JNZ 0x43d26b
    if(integer::condition("JNZ",flags)) goto L0043d26b;
  }
  L0043d261: { // 0x0043d261: 66394302 CMP word ptr [EBX + 2], AX
    (void)integer::sub(m.r16((s.bx+2u)),(s.ax & 0xffffu),16,flags);
  }
  L0043d265: { // 0x0043d265: 0f84b5000000 JZ 0x43d320
    if(integer::condition("JZ",flags)) goto L0043d320;
  }
  L0043d26b: { // 0x0043d26b: 668b5302 MOV DX, word ptr [EBX + 2]
    s.dx = with_ax(s.dx, m.r16((s.bx+2u)));
  }
  L0043d26f: { // 0x0043d26f: 8b4c2414 MOV ECX, dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0043d273: { // 0x0043d273: 6603542416 ADD DX, word ptr [ESP + 0x16]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((f.sp+0x00000016u)),16,flags));
  }
  L0043d278: { // 0x0043d278: 03c1 ADD EAX, ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0043d27a: { // 0x0043d27a: 8d4c241c LEA ECX, [ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L0043d27e: { // 0x0043d27e: 6689442418 MOV word ptr [ESP + 0x18], AX
    m.w16((f.sp+0x00000018u), (s.ax & 0xffffu));
  }
  L0043d283: { // 0x0043d283: 668954241a MOV word ptr [ESP + 0x1a], DX
    m.w16((f.sp+0x0000001au), (s.dx & 0xffffu));
  }
  L0043d288: { // 0x0043d288: 8b442418 MOV EAX, dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0043d28c: { // 0x0043d28c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0043d28d: { // 0x0043d28d: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0043d292: { // 0x0043d292: 89442420 MOV dword ptr [ESP + 0x20], EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L0043d296: { // 0x0043d296: e865821000 CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4444827u); flags=s.arithmetic_flags;
  }
  L0043d29b: { // 0x0043d29b: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L0043d29d: { // 0x0043d29d: 33d2 XOR EDX, EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0043d29f: { // 0x0043d29f: 8b4750 MOV EAX, dword ptr [EDI + 0x50]
    s.ax = m.r32((s.di+0x00000050u));
  }
  L0043d2a2: { // 0x0043d2a2: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0043d2a4: { // 0x0043d2a4: 7c09 JL 0x43d2af
    if(integer::condition("JL",flags)) goto L0043d2af;
  }
  L0043d2a6: { // 0x0043d2a6: 8b15cca5a100 MOV EDX, dword ptr [0xa1a5cc]
    s.dx = m.r32((0x00a1a5ccu));
  }
  L0043d2ac: { // 0x0043d2ac: 8b1482 MOV EDX, dword ptr [EDX + EAX*4]
    s.dx = m.r32((s.dx+(s.ax * 4u)));
  }
  L0043d2af: { // 0x0043d2af: 8b8eb4010000 MOV ECX, dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L0043d2b5: { // 0x0043d2b5: 3bd1 CMP EDX, ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L0043d2b7: { // 0x0043d2b7: 751c JNZ 0x43d2d5
    if(integer::condition("JNZ",flags)) goto L0043d2d5;
  }
  L0043d2b9: { // 0x0043d2b9: 8b4744 MOV EAX, dword ptr [EDI + 0x44]
    s.ax = m.r32((s.di+0x00000044u));
  }
  L0043d2bc: { // 0x0043d2bc: 83f802 CMP EAX, 2
    (void)integer::sub(s.ax,2u,32,flags);
  }
  L0043d2bf: { // 0x0043d2bf: 7409 JZ 0x43d2ca
    if(integer::condition("JZ",flags)) goto L0043d2ca;
  }
  L0043d2c1: { // 0x0043d2c1: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0043d2c3: { // 0x0043d2c3: 7405 JZ 0x43d2ca
    if(integer::condition("JZ",flags)) goto L0043d2ca;
  }
  L0043d2c5: { // 0x0043d2c5: 83f81a CMP EAX, 0x1a
    (void)integer::sub(s.ax,0x0000001au,32,flags);
  }
  L0043d2c8: { // 0x0043d2c8: 750b JNZ 0x43d2d5
    if(integer::condition("JNZ",flags)) goto L0043d2d5;
  }
  L0043d2ca: { // 0x0043d2ca: 8d4724 LEA EAX, [EDI + 0x24]
    s.ax = (s.di+0x00000024u);
  }
  L0043d2cd: { // 0x0043d2cd: 6a01 PUSH 1
    f.push(m,1u);
  }
  L0043d2cf: { // 0x0043d2cf: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0043d2d0: { // 0x0043d2d0: e8eba50a00 CALL 0x4e78c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e78c0u,4444885u); flags=s.arithmetic_flags;
  }
  L0043d2d5: { // 0x0043d2d5: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L0043d2d7: { // 0x0043d2d7: e8d4400300 CALL 0x4713b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004713b0u,4444892u); flags=s.arithmetic_flags;
  }
  L0043d2dc: { // 0x0043d2dc: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0043d2de: { // 0x0043d2de: 7438 JZ 0x43d318
    if(integer::condition("JZ",flags)) goto L0043d318;
  }
  L0043d2e0: { // 0x0043d2e0: 8b8818040000 MOV ECX, dword ptr [EAX + 0x418]
    s.cx = m.r32((s.ax+0x00000418u));
  }
  L0043d2e6: { // 0x0043d2e6: 8a9159130000 MOV DL, byte ptr [ECX + 0x1359]
    s.dx = with_al(s.dx, m.r8((s.cx+0x00001359u)));
  }
  L0043d2ec: { // 0x0043d2ec: 84d2 TEST DL, DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L0043d2ee: { // 0x0043d2ee: 7428 JZ 0x43d318
    if(integer::condition("JZ",flags)) goto L0043d318;
  }
  L0043d2f0: { // 0x0043d2f0: 8b10 MOV EDX, dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0043d2f2: { // 0x0043d2f2: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L0043d2f4: { // 0x0043d2f4: ff5238 CALL dword ptr [EDX + 0x38]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000038u)),4444919u); flags=s.arithmetic_flags;
  }
  L0043d2f7: { // 0x0043d2f7: 8be8 MOV EBP, EAX
    s.bp = s.ax;
  }
  L0043d2f9: { // 0x0043d2f9: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0043d2fb: { // 0x0043d2fb: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0043d2fd: { // 0x0043d2fd: ff5038 CALL dword ptr [EAX + 0x38]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000038u)),4444928u); flags=s.arithmetic_flags;
  }
  L0043d300: { // 0x0043d300: 3be8 CMP EBP, EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L0043d302: { // 0x0043d302: 7510 JNZ 0x43d314
    if(integer::condition("JNZ",flags)) goto L0043d314;
  }
  L0043d304: { // 0x0043d304: 8b4f24 MOV ECX, dword ptr [EDI + 0x24]
    s.cx = m.r32((s.di+0x00000024u));
  }
  L0043d307: { // 0x0043d307: 894c241c MOV dword ptr [ESP + 0x1c], ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L0043d30b: { // 0x0043d30b: 8d4c241c LEA ECX, [ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L0043d30f: { // 0x0043d30f: e81c0e0100 CALL 0x44e130
    s.arithmetic_flags=flags; invoke(m,s,f,0x0044e130u,4444948u); flags=s.arithmetic_flags;
  }
  L0043d314: { // 0x0043d314: 8b6c2448 MOV EBP, dword ptr [ESP + 0x48]
    s.bp = m.r32((f.sp+0x00000048u));
  }
  L0043d318: { // 0x0043d318: 83c304 ADD EBX, 4
    s.bx = integer::add(s.bx,4u,32,flags);
  }
  L0043d31b: { // 0x0043d31b: e938ffffff JMP 0x43d258
    goto L0043d258;
  }
  L0043d320: { // 0x0043d320: 8a5c2413 MOV BL, byte ptr [ESP + 0x13]
    s.bx = with_al(s.bx, m.r8((f.sp+0x00000013u)));
  }
  L0043d324: { // 0x0043d324: 8b8618040000 MOV EAX, dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L0043d32a: { // 0x0043d32a: 8a8815120000 MOV CL, byte ptr [EAX + 0x1215]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001215u)));
  }
  L0043d330: { // 0x0043d330: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0043d332: { // 0x0043d332: 0f84e9000000 JZ 0x43d421
    if(integer::condition("JZ",flags)) goto L0043d421;
  }
  L0043d338: { // 0x0043d338: 8b3e MOV EDI, dword ptr [ESI]
    s.di = m.r32((s.si));
  }
  L0043d33a: { // 0x0043d33a: 6a01 PUSH 1
    f.push(m,1u);
  }
  L0043d33c: { // 0x0043d33c: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0043d33e: { // 0x0043d33e: 6aff PUSH -1
    f.push(m,4294967295u);
  }
  L0043d340: { // 0x0043d340: 6aff PUSH -1
    f.push(m,4294967295u);
  }
  L0043d342: { // 0x0043d342: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0043d343: { // 0x0043d343: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0043d348: { // 0x0043d348: e843811000 CALL 0x545490
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545490u,4445005u); flags=s.arithmetic_flags;
  }
  L0043d34d: { // 0x0043d34d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0043d34e: { // 0x0043d34e: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0043d350: { // 0x0043d350: ff9794010000 CALL dword ptr [EDI + 0x194]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.di+0x00000194u)),4445014u); flags=s.arithmetic_flags;
  }
  L0043d356: { // 0x0043d356: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0043d358: { // 0x0043d358: 0f8578010000 JNZ 0x43d4d6
    if(integer::condition("JNZ",flags)) goto L0043d4d6;
  }
  L0043d35e: { // 0x0043d35e: 8b9618040000 MOV EDX, dword ptr [ESI + 0x418]
    s.dx = m.r32((s.si+0x00000418u));
  }
  L0043d364: { // 0x0043d364: 8b8aec0b0000 MOV ECX, dword ptr [EDX + 0xbec]
    s.cx = m.r32((s.dx+0x00000becu));
  }
  L0043d36a: { // 0x0043d36a: 8b96b4010000 MOV EDX, dword ptr [ESI + 0x1b4]
    s.dx = m.r32((s.si+0x000001b4u));
  }
  L0043d370: { // 0x0043d370: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0043d371: { // 0x0043d371: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0043d373: { // 0x0043d373: ff908c000000 CALL dword ptr [EAX + 0x8c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000008cu)),4445049u); flags=s.arithmetic_flags;
  }
  L0043d379: { // 0x0043d379: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0043d37b: { // 0x0043d37b: 0f8455010000 JZ 0x43d4d6
    if(integer::condition("JZ",flags)) goto L0043d4d6;
  }
  L0043d381: { // 0x0043d381: 8b10 MOV EDX, dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0043d383: { // 0x0043d383: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0043d385: { // 0x0043d385: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0043d386: { // 0x0043d386: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L0043d388: { // 0x0043d388: ff92d4000000 CALL dword ptr [EDX + 0xd4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000000d4u)),4445070u); flags=s.arithmetic_flags;
  }
  L0043d38e: { // 0x0043d38e: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0043d390: { // 0x0043d390: 0f8440010000 JZ 0x43d4d6
    if(integer::condition("JZ",flags)) goto L0043d4d6;
  }
  L0043d396: { // 0x0043d396: 8bbeb4010000 MOV EDI, dword ptr [ESI + 0x1b4]
    s.di = m.r32((s.si+0x000001b4u));
  }
  L0043d39c: { // 0x0043d39c: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0043d39d: { // 0x0043d39d: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0043d3a2: { // 0x0043d3a2: e8e9801000 CALL 0x545490
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545490u,4445095u); flags=s.arithmetic_flags;
  }
  L0043d3a7: { // 0x0043d3a7: 8b4f30 MOV ECX, dword ptr [EDI + 0x30]
    s.cx = m.r32((s.di+0x00000030u));
  }
  L0043d3aa: { // 0x0043d3aa: 6a03 PUSH 3
    f.push(m,3u);
  }
  L0043d3ac: { // 0x0043d3ac: 894850 MOV dword ptr [EAX + 0x50], ECX
    m.w32((s.ax+0x00000050u), s.cx);
  }
  L0043d3af: { // 0x0043d3af: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0043d3b1: { // 0x0043d3b1: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0043d3b3: { // 0x0043d3b3: ff9254020000 CALL dword ptr [EDX + 0x254]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000254u)),4445113u); flags=s.arithmetic_flags;
  }
  L0043d3b9: { // 0x0043d3b9: 8b8e18040000 MOV ECX, dword ptr [ESI + 0x418]
    s.cx = m.r32((s.si+0x00000418u));
  }
  L0043d3bf: { // 0x0043d3bf: 8b86b4010000 MOV EAX, dword ptr [ESI + 0x1b4]
    s.ax = m.r32((s.si+0x000001b4u));
  }
  L0043d3c5: { // 0x0043d3c5: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0043d3c7: { // 0x0043d3c7: 6a01 PUSH 1
    f.push(m,1u);
  }
  L0043d3c9: { // 0x0043d3c9: 8b9130050000 MOV EDX, dword ptr [ECX + 0x530]
    s.dx = m.r32((s.cx+0x00000530u));
  }
  L0043d3cf: { // 0x0043d3cf: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0043d3d1: { // 0x0043d3d1: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0043d3d3: { // 0x0043d3d3: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0043d3d5: { // 0x0043d3d5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0043d3d6: { // 0x0043d3d6: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0043d3d7: { // 0x0043d3d7: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0043d3d8: { // 0x0043d3d8: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0043d3dd: { // 0x0043d3dd: e8bea11000 CALL 0x5475a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005475a0u,4445154u); flags=s.arithmetic_flags;
  }
  L0043d3e2: { // 0x0043d3e2: 8b8e18040000 MOV ECX, dword ptr [ESI + 0x418]
    s.cx = m.r32((s.si+0x00000418u));
  }
  L0043d3e8: { // 0x0043d3e8: 8b86b4010000 MOV EAX, dword ptr [ESI + 0x1b4]
    s.ax = m.r32((s.si+0x000001b4u));
  }
  L0043d3ee: { // 0x0043d3ee: 6a01 PUSH 1
    f.push(m,1u);
  }
  L0043d3f0: { // 0x0043d3f0: 6a01 PUSH 1
    f.push(m,1u);
  }
  L0043d3f2: { // 0x0043d3f2: 8b9130050000 MOV EDX, dword ptr [ECX + 0x530]
    s.dx = m.r32((s.cx+0x00000530u));
  }
  L0043d3f8: { // 0x0043d3f8: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0043d3fa: { // 0x0043d3fa: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0043d3fc: { // 0x0043d3fc: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0043d3fe: { // 0x0043d3fe: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0043d3ff: { // 0x0043d3ff: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0043d400: { // 0x0043d400: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0043d401: { // 0x0043d401: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0043d406: { // 0x0043d406: e895a11000 CALL 0x5475a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005475a0u,4445195u); flags=s.arithmetic_flags;
  }
  L0043d40b: { // 0x0043d40b: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0043d40d: { // 0x0043d40d: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0043d40f: { // 0x0043d40f: ff90f0000000 CALL dword ptr [EAX + 0xf0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000000f0u)),4445205u); flags=s.arithmetic_flags;
  }
  L0043d415: { // 0x0043d415: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L0043d417: { // 0x0043d417: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0043d418: { // 0x0043d418: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0043d419: { // 0x0043d419: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0043d41a: { // 0x0043d41a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0043d41b: { // 0x0043d41b: 83c434 ADD ESP, 0x34
    f.sp = integer::add(f.sp,0x00000034u,32,flags);
  }
  L0043d41e: { // 0x0043d41e: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0043d421: { // 0x0043d421: 8a88200c0000 MOV CL, byte ptr [EAX + 0xc20]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000c20u)));
  }
  L0043d427: { // 0x0043d427: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0043d429: { // 0x0043d429: 0f8403020000 JZ 0x43d632
    if(integer::condition("JZ",flags)) goto L0043d632;
  }
  L0043d42f: { // 0x0043d42f: 8b4500 MOV EAX, dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L0043d432: { // 0x0043d432: 33db XOR EBX, EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0043d434: { // 0x0043d434: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0043d435: { // 0x0043d435: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0043d43b: { // 0x0043d43b: 895c242c MOV dword ptr [ESP + 0x2c], EBX
    m.w32((f.sp+0x0000002cu), s.bx);
  }
  L0043d43f: { // 0x0043d43f: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0043d441: { // 0x0043d441: 895c2430 MOV dword ptr [ESP + 0x30], EBX
    m.w32((f.sp+0x00000030u), s.bx);
  }
  L0043d445: { // 0x0043d445: c1f808 SAR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L0043d448: { // 0x0043d448: 6689442448 MOV word ptr [ESP + 0x48], AX
    m.w16((f.sp+0x00000048u), (s.ax & 0xffffu));
  }
  L0043d44d: { // 0x0043d44d: 8b4504 MOV EAX, dword ptr [EBP + 4]
    s.ax = m.r32((s.bp+4u));
  }
  L0043d450: { // 0x0043d450: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0043d451: { // 0x0043d451: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0043d457: { // 0x0043d457: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0043d459: { // 0x0043d459: 8d54242c LEA EDX, [ESP + 0x2c]
    s.dx = (f.sp+0x0000002cu);
  }
  L0043d45d: { // 0x0043d45d: c1f808 SAR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L0043d460: { // 0x0043d460: 668944244a MOV word ptr [ESP + 0x4a], AX
    m.w16((f.sp+0x0000004au), (s.ax & 0xffffu));
  }
  L0043d465: { // 0x0043d465: 8b4c2448 MOV ECX, dword ptr [ESP + 0x48]
    s.cx = m.r32((f.sp+0x00000048u));
  }
  L0043d469: { // 0x0043d469: 8d442448 LEA EAX, [ESP + 0x48]
    s.ax = (f.sp+0x00000048u);
  }
  L0043d46d: { // 0x0043d46d: 894c2448 MOV dword ptr [ESP + 0x48], ECX
    m.w32((f.sp+0x00000048u), s.cx);
  }
  L0043d471: { // 0x0043d471: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0043d472: { // 0x0043d472: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0043d473: { // 0x0043d473: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0043d478: { // 0x0043d478: e813cf0500 CALL 0x49a390
    s.arithmetic_flags=flags; invoke(m,s,f,0x0049a390u,4445309u); flags=s.arithmetic_flags;
  }
  L0043d47d: { // 0x0043d47d: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L0043d47f: { // 0x0043d47f: 3bfb CMP EDI, EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  L0043d481: { // 0x0043d481: 7453 JZ 0x43d4d6
    if(integer::condition("JZ",flags)) goto L0043d4d6;
  }
  L0043d483: { // 0x0043d483: 8b17 MOV EDX, dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L0043d485: { // 0x0043d485: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L0043d487: { // 0x0043d487: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),4445322u); flags=s.arithmetic_flags;
  }
  L0043d48a: { // 0x0043d48a: 83f806 CMP EAX, 6
    (void)integer::sub(s.ax,6u,32,flags);
  }
  L0043d48d: { // 0x0043d48d: 7547 JNZ 0x43d4d6
    if(integer::condition("JNZ",flags)) goto L0043d4d6;
  }
  L0043d48f: { // 0x0043d48f: 8b86b4010000 MOV EAX, dword ptr [ESI + 0x1b4]
    s.ax = m.r32((s.si+0x000001b4u));
  }
  L0043d495: { // 0x0043d495: 8b8fb4010000 MOV ECX, dword ptr [EDI + 0x1b4]
    s.cx = m.r32((s.di+0x000001b4u));
  }
  L0043d49b: { // 0x0043d49b: 8b9e18040000 MOV EBX, dword ptr [ESI + 0x418]
    s.bx = m.r32((s.si+0x00000418u));
  }
  L0043d4a1: { // 0x0043d4a1: 3bc1 CMP EAX, ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0043d4a3: { // 0x0043d4a3: 7531 JNZ 0x43d4d6
    if(integer::condition("JNZ",flags)) goto L0043d4d6;
  }
  L0043d4a5: { // 0x0043d4a5: 8b8f18040000 MOV ECX, dword ptr [EDI + 0x418]
    s.cx = m.r32((s.di+0x00000418u));
  }
  L0043d4ab: { // 0x0043d4ab: 8d93200c0000 LEA EDX, [EBX + 0xc20]
    s.dx = (s.bx+0x00000c20u);
  }
  L0043d4b1: { // 0x0043d4b1: 83c124 ADD ECX, 0x24
    s.cx = integer::add(s.cx,0x00000024u,32,flags);
  }
  L0043d4b4: { // 0x0043d4b4: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0043d4b5: { // 0x0043d4b5: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0043d4b6: { // 0x0043d4b6: e8a5033300 CALL 0x76d860
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d860u,4445371u); flags=s.arithmetic_flags;
  }
  L0043d4bb: { // 0x0043d4bb: 83c408 ADD ESP, 8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  L0043d4be: { // 0x0043d4be: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0043d4c0: { // 0x0043d4c0: 7514 JNZ 0x43d4d6
    if(integer::condition("JNZ",flags)) goto L0043d4d6;
  }
  L0043d4c2: { // 0x0043d4c2: 8b8380130000 MOV EAX, dword ptr [EBX + 0x1380]
    s.ax = m.r32((s.bx+0x00001380u));
  }
  L0043d4c8: { // 0x0043d4c8: 83f8ff CMP EAX, -1
    (void)integer::sub(s.ax,4294967295u,32,flags);
  }
  L0043d4cb: { // 0x0043d4cb: 7415 JZ 0x43d4e2
    if(integer::condition("JZ",flags)) goto L0043d4e2;
  }
  L0043d4cd: { // 0x0043d4cd: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0043d4cf: { // 0x0043d4cf: 7e05 JLE 0x43d4d6
    if(integer::condition("JLE",flags)) goto L0043d4d6;
  }
  L0043d4d1: { // 0x0043d4d1: 83f803 CMP EAX, 3
    (void)integer::sub(s.ax,3u,32,flags);
  }
  L0043d4d4: { // 0x0043d4d4: 7e21 JLE 0x43d4f7
    if(integer::condition("JLE",flags)) goto L0043d4f7;
  }
  L0043d4d6: { // 0x0043d4d6: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0043d4d8: { // 0x0043d4d8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0043d4d9: { // 0x0043d4d9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0043d4da: { // 0x0043d4da: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0043d4db: { // 0x0043d4db: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0043d4dc: { // 0x0043d4dc: 83c434 ADD ESP, 0x34
    f.sp = integer::add(f.sp,0x00000034u,32,flags);
  }
  L0043d4df: { // 0x0043d4df: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0043d4e2: { // 0x0043d4e2: 8b8718040000 MOV EAX, dword ptr [EDI + 0x418]
    s.ax = m.r32((s.di+0x00000418u));
  }
  L0043d4e8: { // 0x0043d4e8: 0fbe8fc6050000 MOVSX ECX, byte ptr [EDI + 0x5c6]
    s.cx = std::uint32_t(integer::sign_extend(m.r8((s.di+0x000005c6u)),8));
  }
  L0043d4ef: { // 0x0043d4ef: 3b889c110000 CMP ECX, dword ptr [EAX + 0x119c]
    (void)integer::sub(s.cx,m.r32((s.ax+0x0000119cu)),32,flags);
  }
  L0043d4f5: { // 0x0043d4f5: 7c0a JL 0x43d501
    if(integer::condition("JL",flags)) goto L0043d501;
  }
  L0043d4f7: { // 0x0043d4f7: 8a87c6050000 MOV AL, byte ptr [EDI + 0x5c6]
    s.ax = with_al(s.ax, m.r8((s.di+0x000005c6u)));
  }
  L0043d4fd: { // 0x0043d4fd: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0043d4ff: { // 0x0043d4ff: 75d5 JNZ 0x43d4d6
    if(integer::condition("JNZ",flags)) goto L0043d4d6;
  }
  L0043d501: { // 0x0043d501: 8b96b4010000 MOV EDX, dword ptr [ESI + 0x1b4]
    s.dx = m.r32((s.si+0x000001b4u));
  }
  L0043d507: { // 0x0043d507: c6826956000001 MOV byte ptr [EDX + 0x5669], 1
    m.w8((s.dx+0x00005669u), 1u);
  }
  L0043d50e: { // 0x0043d50e: 8b86b4010000 MOV EAX, dword ptr [ESI + 0x1b4]
    s.ax = m.r32((s.si+0x000001b4u));
  }
  L0043d514: { // 0x0043d514: c6806856000001 MOV byte ptr [EAX + 0x5668], 1
    m.w8((s.ax+0x00005668u), 1u);
  }
  L0043d51b: { // 0x0043d51b: 8b8618040000 MOV EAX, dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L0043d521: { // 0x0043d521: 8b9880130000 MOV EBX, dword ptr [EAX + 0x1380]
    s.bx = m.r32((s.ax+0x00001380u));
  }
  L0043d527: { // 0x0043d527: 83fbff CMP EBX, -1
    (void)integer::sub(s.bx,4294967295u,32,flags);
  }
  L0043d52a: { // 0x0043d52a: 7505 JNZ 0x43d531
    if(integer::condition("JNZ",flags)) goto L0043d531;
  }
  L0043d52c: { // 0x0043d52c: bb01000000 MOV EBX, 1
    s.bx = 1u;
  }
  L0043d531: { // 0x0043d531: 0fbe8fc6050000 MOVSX ECX, byte ptr [EDI + 0x5c6]
    s.cx = std::uint32_t(integer::sign_extend(m.r8((s.di+0x000005c6u)),8));
  }
  L0043d538: { // 0x0043d538: 8bd1 MOV EDX, ECX
    s.dx = s.cx;
  }
  L0043d53a: { // 0x0043d53a: 05c8010000 ADD EAX, 0x1c8
    s.ax = integer::add(s.ax,0x000001c8u,32,flags);
  }
  L0043d53f: { // 0x0043d53f: c1e204 SHL EDX, 4
    s.dx = integer::shift(s.dx,4u,32,flags,integer::Shift::left);
  }
  L0043d542: { // 0x0043d542: 03d1 ADD EDX, ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L0043d544: { // 0x0043d544: 8b8f18040000 MOV ECX, dword ptr [EDI + 0x418]
    s.cx = m.r32((s.di+0x00000418u));
  }
  L0043d54a: { // 0x0043d54a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0043d54b: { // 0x0043d54b: 8dac91d40c0000 LEA EBP, [ECX + EDX*4 + 0xcd4]
    s.bp = (s.cx+(s.dx * 4u)+0x00000cd4u);
  }
  L0043d552: { // 0x0043d552: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0043d553: { // 0x0043d553: e808033300 CALL 0x76d860
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d860u,4445528u); flags=s.arithmetic_flags;
  }
  L0043d558: { // 0x0043d558: 83c408 ADD ESP, 8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  L0043d55b: { // 0x0043d55b: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0043d55d: { // 0x0043d55d: 7418 JZ 0x43d577
    if(integer::condition("JZ",flags)) goto L0043d577;
  }
  L0043d55f: { // 0x0043d55f: 8b9618040000 MOV EDX, dword ptr [ESI + 0x418]
    s.dx = m.r32((s.si+0x00000418u));
  }
  L0043d565: { // 0x0043d565: 6a10 PUSH 0x10
    f.push(m,0x00000010u);
  }
  L0043d567: { // 0x0043d567: 81c2c8010000 ADD EDX, 0x1c8
    s.dx = integer::add(s.dx,0x000001c8u,32,flags);
  }
  L0043d56d: { // 0x0043d56d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0043d56e: { // 0x0043d56e: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0043d56f: { // 0x0043d56f: e89c073300 CALL 0x76dd10
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076dd10u,4445556u); flags=s.arithmetic_flags;
  }
  L0043d574: { // 0x0043d574: 83c40c ADD ESP, 0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0043d577: { // 0x0043d577: 85db TEST EBX, EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L0043d579: { // 0x0043d579: 740a JZ 0x43d585
    if(integer::condition("JZ",flags)) goto L0043d585;
  }
  L0043d57b: { // 0x0043d57b: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L0043d57d: { // 0x0043d57d: e83eed0000 CALL 0x44c2c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0044c2c0u,4445570u); flags=s.arithmetic_flags;
  }
  L0043d582: { // 0x0043d582: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L0043d583: { // 0x0043d583: 75f6 JNZ 0x43d57b
    if(integer::condition("JNZ",flags)) goto L0043d57b;
  }
  L0043d585: { // 0x0043d585: 0fbe87c6050000 MOVSX EAX, byte ptr [EDI + 0x5c6]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.di+0x000005c6u)),8));
  }
  L0043d58c: { // 0x0043d58c: 8b8e18040000 MOV ECX, dword ptr [ESI + 0x418]
    s.cx = m.r32((s.si+0x00000418u));
  }
  L0043d592: { // 0x0043d592: 33db XOR EBX, EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0043d594: { // 0x0043d594: 898c87bc040000 MOV dword ptr [EDI + EAX*4 + 0x4bc], ECX
    m.w32((s.di+(s.ax * 4u)+0x000004bcu), s.cx);
  }
  L0043d59b: { // 0x0043d59b: 8baeb4010000 MOV EBP, dword ptr [ESI + 0x1b4]
    s.bp = m.r32((s.si+0x000001b4u));
  }
  L0043d5a1: { // 0x0043d5a1: 8b4578 MOV EAX, dword ptr [EBP + 0x78]
    s.ax = m.r32((s.bp+0x00000078u));
  }
  L0043d5a4: { // 0x0043d5a4: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0043d5a6: { // 0x0043d5a6: 89442448 MOV dword ptr [ESP + 0x48], EAX
    m.w32((f.sp+0x00000048u), s.ax);
  }
  L0043d5aa: { // 0x0043d5aa: 7e3d JLE 0x43d5e9
    if(integer::condition("JLE",flags)) goto L0043d5e9;
  }
  L0043d5ac: { // 0x0043d5ac: 8b556c MOV EDX, dword ptr [EBP + 0x6c]
    s.dx = m.r32((s.bp+0x0000006cu));
  }
  L0043d5af: { // 0x0043d5af: 8b3c9a MOV EDI, dword ptr [EDX + EBX*4]
    s.di = m.r32((s.dx+(s.bx * 4u)));
  }
  L0043d5b2: { // 0x0043d5b2: 8a4f7d MOV CL, byte ptr [EDI + 0x7d]
    s.cx = with_al(s.cx, m.r8((s.di+0x0000007du)));
  }
  L0043d5b5: { // 0x0043d5b5: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0043d5b7: { // 0x0043d5b7: 742b JZ 0x43d5e4
    if(integer::condition("JZ",flags)) goto L0043d5e4;
  }
  L0043d5b9: { // 0x0043d5b9: 8a4f76 MOV CL, byte ptr [EDI + 0x76]
    s.cx = with_al(s.cx, m.r8((s.di+0x00000076u)));
  }
  L0043d5bc: { // 0x0043d5bc: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0043d5be: { // 0x0043d5be: 7524 JNZ 0x43d5e4
    if(integer::condition("JNZ",flags)) goto L0043d5e4;
  }
  L0043d5c0: { // 0x0043d5c0: 8b8718040000 MOV EAX, dword ptr [EDI + 0x418]
    s.ax = m.r32((s.di+0x00000418u));
  }
  L0043d5c6: { // 0x0043d5c6: 8a8858130000 MOV CL, byte ptr [EAX + 0x1358]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001358u)));
  }
  L0043d5cc: { // 0x0043d5cc: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0043d5ce: { // 0x0043d5ce: 7409 JZ 0x43d5d9
    if(integer::condition("JZ",flags)) goto L0043d5d9;
  }
  L0043d5d0: { // 0x0043d5d0: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0043d5d2: { // 0x0043d5d2: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L0043d5d4: { // 0x0043d5d4: e8b70c0100 CALL 0x44e290
    s.arithmetic_flags=flags; invoke(m,s,f,0x0044e290u,4445657u); flags=s.arithmetic_flags;
  }
  L0043d5d9: { // 0x0043d5d9: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L0043d5db: { // 0x0043d5db: e8f01f0100 CALL 0x44f5d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0044f5d0u,4445664u); flags=s.arithmetic_flags;
  }
  L0043d5e0: { // 0x0043d5e0: 8b442448 MOV EAX, dword ptr [ESP + 0x48]
    s.ax = m.r32((f.sp+0x00000048u));
  }
  L0043d5e4: { // 0x0043d5e4: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L0043d5e5: { // 0x0043d5e5: 3bd8 CMP EBX, EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L0043d5e7: { // 0x0043d5e7: 7cc3 JL 0x43d5ac
    if(integer::condition("JL",flags)) goto L0043d5ac;
  }
  L0043d5e9: { // 0x0043d5e9: 8b8eb4010000 MOV ECX, dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L0043d5ef: { // 0x0043d5ef: e8bc6c0b00 CALL 0x4f42b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f42b0u,4445684u); flags=s.arithmetic_flags;
  }
  L0043d5f4: { // 0x0043d5f4: 8b8eb4010000 MOV ECX, dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L0043d5fa: { // 0x0043d5fa: c6814401000001 MOV byte ptr [ECX + 0x144], 1
    m.w8((s.cx+0x00000144u), 1u);
  }
  L0043d601: { // 0x0043d601: 8b9618040000 MOV EDX, dword ptr [ESI + 0x418]
    s.dx = m.r32((s.si+0x00000418u));
  }
  L0043d607: { // 0x0043d607: 8a82e3130000 MOV AL, byte ptr [EDX + 0x13e3]
    s.ax = with_al(s.ax, m.r8((s.dx+0x000013e3u)));
  }
  L0043d60d: { // 0x0043d60d: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0043d60f: { // 0x0043d60f: 740b JZ 0x43d61c
    if(integer::condition("JZ",flags)) goto L0043d61c;
  }
  L0043d611: { // 0x0043d611: 8b8eb4010000 MOV ECX, dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L0043d617: { // 0x0043d617: e844500b00 CALL 0x4f2660
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f2660u,4445724u); flags=s.arithmetic_flags;
  }
  L0043d61c: { // 0x0043d61c: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0043d61e: { // 0x0043d61e: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0043d620: { // 0x0043d620: ff90f0000000 CALL dword ptr [EAX + 0xf0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000000f0u)),4445734u); flags=s.arithmetic_flags;
  }
  L0043d626: { // 0x0043d626: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L0043d628: { // 0x0043d628: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0043d629: { // 0x0043d629: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0043d62a: { // 0x0043d62a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0043d62b: { // 0x0043d62b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0043d62c: { // 0x0043d62c: 83c434 ADD ESP, 0x34
    f.sp = integer::add(f.sp,0x00000034u,32,flags);
  }
  L0043d62f: { // 0x0043d62f: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0043d632: { // 0x0043d632: 8a8859130000 MOV CL, byte ptr [EAX + 0x1359]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001359u)));
  }
  L0043d638: { // 0x0043d638: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0043d63a: { // 0x0043d63a: 7431 JZ 0x43d66d
    if(integer::condition("JZ",flags)) goto L0043d66d;
  }
  L0043d63c: { // 0x0043d63c: 33c9 XOR ECX, ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0043d63e: { // 0x0043d63e: 8a6c244c MOV CH, byte ptr [ESP + 0x4c]
    s.cx = (s.cx & 0xffff00ffu) | (((m.r8((f.sp+0x0000004cu))) & 0xffu) << 8);
  }
  L0043d642: { // 0x0043d642: 66894c241c MOV word ptr [ESP + 0x1c], CX
    m.w16((f.sp+0x0000001cu), (s.cx & 0xffffu));
  }
  L0043d647: { // 0x0043d647: 8b54241c MOV EDX, dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L0043d64b: { // 0x0043d64b: c1ea0c SHR EDX, 0xc
    s.dx = integer::shift(s.dx,0x0000000cu,32,flags,integer::Shift::right);
  }
  L0043d64e: { // 0x0043d64e: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L0043d64f: { // 0x0043d64f: 83e206 AND EDX, 6
    s.dx = integer::logical((s.dx)&(6u),32,flags);
  }
  L0043d652: { // 0x0043d652: 80fa04 CMP DL, 4
    (void)integer::sub((s.dx & 0xffu),4u,8,flags);
  }
  L0043d655: { // 0x0043d655: 750c JNZ 0x43d663
    if(integer::condition("JNZ",flags)) goto L0043d663;
  }
  L0043d657: { // 0x0043d657: c786ec04000008000000 MOV dword ptr [ESI + 0x4ec], 8
    m.w32((s.si+0x000004ecu), 8u);
  }
  L0043d661: { // 0x0043d661: eb0a JMP 0x43d66d
    goto L0043d66d;
  }
  L0043d663: { // 0x0043d663: c786ec0400000c000000 MOV dword ptr [ESI + 0x4ec], 0xc
    m.w32((s.si+0x000004ecu), 0x0000000cu);
  }
  L0043d66d: { // 0x0043d66d: 84db TEST BL, BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L0043d66f: { // 0x0043d66f: 0f8492000000 JZ 0x43d707
    if(integer::condition("JZ",flags)) goto L0043d707;
  }
  L0043d675: { // 0x0043d675: 8a8858130000 MOV CL, byte ptr [EAX + 0x1358]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001358u)));
  }
  L0043d67b: { // 0x0043d67b: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0043d67d: { // 0x0043d67d: 0f8484000000 JZ 0x43d707
    if(integer::condition("JZ",flags)) goto L0043d707;
  }
  L0043d683: { // 0x0043d683: c786ec04000000000000 MOV dword ptr [ESI + 0x4ec], 0
    m.w32((s.si+0x000004ecu), 0u);
  }
  L0043d68d: { // 0x0043d68d: 8b4500 MOV EAX, dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L0043d690: { // 0x0043d690: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0043d691: { // 0x0043d691: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0043d697: { // 0x0043d697: 8d4c241c LEA ECX, [ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L0043d69b: { // 0x0043d69b: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0043d69d: { // 0x0043d69d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0043d69e: { // 0x0043d69e: c1f808 SAR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L0043d6a1: { // 0x0043d6a1: 668944241c MOV word ptr [ESP + 0x1c], AX
    m.w16((f.sp+0x0000001cu), (s.ax & 0xffffu));
  }
  L0043d6a6: { // 0x0043d6a6: 8b4504 MOV EAX, dword ptr [EBP + 4]
    s.ax = m.r32((s.bp+4u));
  }
  L0043d6a9: { // 0x0043d6a9: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0043d6aa: { // 0x0043d6aa: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0043d6b0: { // 0x0043d6b0: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0043d6b5: { // 0x0043d6b5: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0043d6b7: { // 0x0043d6b7: c1f808 SAR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L0043d6ba: { // 0x0043d6ba: 668944241e MOV word ptr [ESP + 0x1e], AX
    m.w16((f.sp+0x0000001eu), (s.ax & 0xffffu));
  }
  L0043d6bf: { // 0x0043d6bf: 8b44241c MOV EAX, dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L0043d6c3: { // 0x0043d6c3: 89442420 MOV dword ptr [ESP + 0x20], EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L0043d6c7: { // 0x0043d6c7: e8347e1000 CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4445900u); flags=s.arithmetic_flags;
  }
  L0043d6cc: { // 0x0043d6cc: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L0043d6ce: { // 0x0043d6ce: e8dd3c0300 CALL 0x4713b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004713b0u,4445907u); flags=s.arithmetic_flags;
  }
  L0043d6d3: { // 0x0043d6d3: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L0043d6d5: { // 0x0043d6d5: 85ff TEST EDI, EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0043d6d7: { // 0x0043d6d7: 742e JZ 0x43d707
    if(integer::condition("JZ",flags)) goto L0043d707;
  }
  L0043d6d9: { // 0x0043d6d9: 8b9718040000 MOV EDX, dword ptr [EDI + 0x418]
    s.dx = m.r32((s.di+0x00000418u));
  }
  L0043d6df: { // 0x0043d6df: 8a8259130000 MOV AL, byte ptr [EDX + 0x1359]
    s.ax = with_al(s.ax, m.r8((s.dx+0x00001359u)));
  }
  L0043d6e5: { // 0x0043d6e5: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0043d6e7: { // 0x0043d6e7: 741e JZ 0x43d707
    if(integer::condition("JZ",flags)) goto L0043d707;
  }
  L0043d6e9: { // 0x0043d6e9: 8b07 MOV EAX, dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L0043d6eb: { // 0x0043d6eb: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L0043d6ed: { // 0x0043d6ed: ff5038 CALL dword ptr [EAX + 0x38]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000038u)),4445936u); flags=s.arithmetic_flags;
  }
  L0043d6f0: { // 0x0043d6f0: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0043d6f2: { // 0x0043d6f2: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0043d6f4: { // 0x0043d6f4: 8bd8 MOV EBX, EAX
    s.bx = s.ax;
  }
  L0043d6f6: { // 0x0043d6f6: ff5238 CALL dword ptr [EDX + 0x38]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000038u)),4445945u); flags=s.arithmetic_flags;
  }
  L0043d6f9: { // 0x0043d6f9: 3bc3 CMP EAX, EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0043d6fb: { // 0x0043d6fb: 750a JNZ 0x43d707
    if(integer::condition("JNZ",flags)) goto L0043d707;
  }
  L0043d6fd: { // 0x0043d6fd: 8b07 MOV EAX, dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L0043d6ff: { // 0x0043d6ff: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L0043d701: { // 0x0043d701: ff90f0000000 CALL dword ptr [EAX + 0xf0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000000f0u)),4445959u); flags=s.arithmetic_flags;
  }
  L0043d707: { // 0x0043d707: 8b4c244c MOV ECX, dword ptr [ESP + 0x4c]
    s.cx = m.r32((f.sp+0x0000004cu));
  }
  L0043d70b: { // 0x0043d70b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0043d70c: { // 0x0043d70c: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0043d70d: { // 0x0043d70d: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0043d70f: { // 0x0043d70f: e85cc52700 CALL 0x6b9c70
    s.arithmetic_flags=flags; invoke(m,s,f,0x006b9c70u,4445972u); flags=s.arithmetic_flags;
  }
  L0043d714: { // 0x0043d714: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0043d716: { // 0x0043d716: 0f84bafdffff JZ 0x43d4d6
    if(integer::condition("JZ",flags)) goto L0043d4d6;
  }
  L0043d71c: { // 0x0043d71c: 8b9618040000 MOV EDX, dword ptr [ESI + 0x418]
    s.dx = m.r32((s.si+0x00000418u));
  }
  L0043d722: { // 0x0043d722: 8a8261130000 MOV AL, byte ptr [EDX + 0x1361]
    s.ax = with_al(s.ax, m.r8((s.dx+0x00001361u)));
  }
  L0043d728: { // 0x0043d728: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0043d72a: { // 0x0043d72a: 740d JZ 0x43d739
    if(integer::condition("JZ",flags)) goto L0043d739;
  }
  L0043d72c: { // 0x0043d72c: 8b86b4010000 MOV EAX, dword ptr [ESI + 0x1b4]
    s.ax = m.r32((s.si+0x000001b4u));
  }
  L0043d732: { // 0x0043d732: c680e855000001 MOV byte ptr [EAX + 0x55e8], 1
    m.w8((s.ax+0x000055e8u), 1u);
  }
  L0043d739: { // 0x0043d739: 8a467d MOV AL, byte ptr [ESI + 0x7d]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000007du)));
  }
  L0043d73c: { // 0x0043d73c: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0043d73e: { // 0x0043d73e: 750c JNZ 0x43d74c
    if(integer::condition("JNZ",flags)) goto L0043d74c;
  }
  L0043d740: { // 0x0043d740: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L0043d742: { // 0x0043d742: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0043d743: { // 0x0043d743: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0043d744: { // 0x0043d744: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0043d745: { // 0x0043d745: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0043d746: { // 0x0043d746: 83c434 ADD ESP, 0x34
    f.sp = integer::add(f.sp,0x00000034u,32,flags);
  }
  L0043d749: { // 0x0043d749: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0043d74c: { // 0x0043d74c: a1c855a200 MOV EAX, dword ptr [0xa255c8]
    s.ax = m.r32((0x00a255c8u));
  }
  L0043d751: { // 0x0043d751: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0043d753: { // 0x0043d753: 7429 JZ 0x43d77e
    if(integer::condition("JZ",flags)) goto L0043d77e;
  }
  L0043d755: { // 0x0043d755: 8b8eb4010000 MOV ECX, dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L0043d75b: { // 0x0043d75b: e890700b00 CALL 0x4f47f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f47f0u,4446048u); flags=s.arithmetic_flags;
  }
  L0043d760: { // 0x0043d760: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0043d762: { // 0x0043d762: 751a JNZ 0x43d77e
    if(integer::condition("JNZ",flags)) goto L0043d77e;
  }
  L0043d764: { // 0x0043d764: 8b8eb4010000 MOV ECX, dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L0043d76a: { // 0x0043d76a: 8b5134 MOV EDX, dword ptr [ECX + 0x34]
    s.dx = m.r32((s.cx+0x00000034u));
  }
  L0043d76d: { // 0x0043d76d: 8a82a6010000 MOV AL, byte ptr [EDX + 0x1a6]
    s.ax = with_al(s.ax, m.r8((s.dx+0x000001a6u)));
  }
  L0043d773: { // 0x0043d773: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0043d775: { // 0x0043d775: 7507 JNZ 0x43d77e
    if(integer::condition("JNZ",flags)) goto L0043d77e;
  }
  L0043d777: { // 0x0043d777: c6869b05000001 MOV byte ptr [ESI + 0x59b], 1
    m.w8((s.si+0x0000059bu), 1u);
  }
  L0043d77e: { // 0x0043d77e: a1c055a200 MOV EAX, dword ptr [0xa255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  L0043d783: { // 0x0043d783: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0043d785: { // 0x0043d785: f6c510 TEST CH, 0x10
    (void)integer::logical((((s.cx >> 8) & 0xffu))&(0x00000010u),8,flags);
  }
  L0043d788: { // 0x0043d788: 747b JZ 0x43d805
    if(integer::condition("JZ",flags)) goto L0043d805;
  }
  L0043d78a: { // 0x0043d78a: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0043d78c: { // 0x0043d78c: 8d442418 LEA EAX, [ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L0043d790: { // 0x0043d790: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0043d791: { // 0x0043d791: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0043d793: { // 0x0043d793: ff92a0010000 CALL dword ptr [EDX + 0x1a0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001a0u)),4446105u); flags=s.arithmetic_flags;
  }
  L0043d799: { // 0x0043d799: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0043d79b: { // 0x0043d79b: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0043d79d: { // 0x0043d79d: 894c2450 MOV dword ptr [ESP + 0x50], ECX
    m.w32((f.sp+0x00000050u), s.cx);
  }
  L0043d7a1: { // 0x0043d7a1: 8b8e18040000 MOV ECX, dword ptr [ESI + 0x418]
    s.cx = m.r32((s.si+0x00000418u));
  }
  L0043d7a7: { // 0x0043d7a7: 8b11 MOV EDX, dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L0043d7a9: { // 0x0043d7a9: ff9290000000 CALL dword ptr [EDX + 0x90]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000090u)),4446127u); flags=s.arithmetic_flags;
  }
  L0043d7af: { // 0x0043d7af: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L0043d7b1: { // 0x0043d7b1: bb00004000 MOV EBX, 0x400000
    s.bx = 0x00400000u;
  }
  L0043d7b6: { // 0x0043d7b6: 66813fff7f CMP word ptr [EDI], 0x7fff
    (void)integer::sub(m.r16((s.di)),0x00007fffu,16,flags);
  }
  L0043d7bb: { // 0x0043d7bb: 7508 JNZ 0x43d7c5
    if(integer::condition("JNZ",flags)) goto L0043d7c5;
  }
  L0043d7bd: { // 0x0043d7bd: 66817f02ff7f CMP word ptr [EDI + 2], 0x7fff
    (void)integer::sub(m.r16((s.di+2u)),0x00007fffu,16,flags);
  }
  L0043d7c3: { // 0x0043d7c3: 7433 JZ 0x43d7f8
    if(integer::condition("JZ",flags)) goto L0043d7f8;
  }
  L0043d7c5: { // 0x0043d7c5: 8d44244c LEA EAX, [ESP + 0x4c]
    s.ax = (f.sp+0x0000004cu);
  }
  L0043d7c9: { // 0x0043d7c9: 8d4c2414 LEA ECX, [ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L0043d7cd: { // 0x0043d7cd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0043d7ce: { // 0x0043d7ce: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0043d7cf: { // 0x0043d7cf: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L0043d7d1: { // 0x0043d7d1: e8fad5feff CALL 0x42add0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042add0u,4446166u); flags=s.arithmetic_flags;
  }
  L0043d7d6: { // 0x0043d7d6: 8b10 MOV EDX, dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0043d7d8: { // 0x0043d7d8: 8d44241c LEA EAX, [ESP + 0x1c]
    s.ax = (f.sp+0x0000001cu);
  }
  L0043d7dc: { // 0x0043d7dc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0043d7dd: { // 0x0043d7dd: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0043d7e2: { // 0x0043d7e2: 89542420 MOV dword ptr [ESP + 0x20], EDX
    m.w32((f.sp+0x00000020u), s.dx);
  }
  L0043d7e6: { // 0x0043d7e6: e8157d1000 CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4446187u); flags=s.arithmetic_flags;
  }
  L0043d7eb: { // 0x0043d7eb: 859840010000 TEST dword ptr [EAX + 0x140], EBX
    (void)integer::logical((m.r32((s.ax+0x00000140u)))&(s.bx),32,flags);
  }
  L0043d7f1: { // 0x0043d7f1: 7412 JZ 0x43d805
    if(integer::condition("JZ",flags)) goto L0043d805;
  }
  L0043d7f3: { // 0x0043d7f3: 83c704 ADD EDI, 4
    s.di = integer::add(s.di,4u,32,flags);
  }
  L0043d7f6: { // 0x0043d7f6: ebbe JMP 0x43d7b6
    goto L0043d7b6;
  }
  L0043d7f8: { // 0x0043d7f8: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0043d7fa: { // 0x0043d7fa: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0043d7fc: { // 0x0043d7fc: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0043d7fe: { // 0x0043d7fe: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0043d800: { // 0x0043d800: e8db500100 CALL 0x4528e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004528e0u,4446213u); flags=s.arithmetic_flags;
  }
  L0043d805: { // 0x0043d805: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0043d807: { // 0x0043d807: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0043d809: { // 0x0043d809: ff527c CALL dword ptr [EDX + 0x7c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000007cu)),4446220u); flags=s.arithmetic_flags;
  }
  L0043d80c: { // 0x0043d80c: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0043d80e: { // 0x0043d80e: 7509 JNZ 0x43d819
    if(integer::condition("JNZ",flags)) goto L0043d819;
  }
  L0043d810: { // 0x0043d810: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0043d812: { // 0x0043d812: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0043d814: { // 0x0043d814: e897350100 CALL 0x450db0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00450db0u,4446233u); flags=s.arithmetic_flags;
  }
  L0043d819: { // 0x0043d819: 8b8e18040000 MOV ECX, dword ptr [ESI + 0x418]
    s.cx = m.r32((s.si+0x00000418u));
  }
  L0043d81f: { // 0x0043d81f: e88cad0100 CALL 0x4585b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004585b0u,4446244u); flags=s.arithmetic_flags;
  }
  L0043d824: { // 0x0043d824: 8b8e18040000 MOV ECX, dword ptr [ESI + 0x418]
    s.cx = m.r32((s.si+0x00000418u));
  }
  L0043d82a: { // 0x0043d82a: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0043d82c: { // 0x0043d82c: 8bd8 MOV EBX, EAX
    s.bx = s.ax;
  }
  L0043d82e: { // 0x0043d82e: e88dad0100 CALL 0x4585c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004585c0u,4446259u); flags=s.arithmetic_flags;
  }
  L0043d833: { // 0x0043d833: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L0043d835: { // 0x0043d835: 8b4500 MOV EAX, dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L0043d838: { // 0x0043d838: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0043d839: { // 0x0043d839: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0043d83f: { // 0x0043d83f: 83c102 ADD ECX, 2
    s.cx = integer::add(s.cx,2u,32,flags);
  }
  L0043d842: { // 0x0043d842: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0043d844: { // 0x0043d844: 894c2414 MOV dword ptr [ESP + 0x14], ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L0043d848: { // 0x0043d848: c1f808 SAR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L0043d84b: { // 0x0043d84b: 6689442420 MOV word ptr [ESP + 0x20], AX
    m.w16((f.sp+0x00000020u), (s.ax & 0xffffu));
  }
  L0043d850: { // 0x0043d850: 8b4504 MOV EAX, dword ptr [EBP + 4]
    s.ax = m.r32((s.bp+4u));
  }
  L0043d853: { // 0x0043d853: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0043d854: { // 0x0043d854: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0043d85a: { // 0x0043d85a: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0043d85c: { // 0x0043d85c: c1f808 SAR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L0043d85f: { // 0x0043d85f: 6689442422 MOV word ptr [ESP + 0x22], AX
    m.w16((f.sp+0x00000022u), (s.ax & 0xffffu));
  }
  L0043d864: { // 0x0043d864: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0043d866: { // 0x0043d866: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0043d868: { // 0x0043d868: 89442418 MOV dword ptr [ESP + 0x18], EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0043d86c: { // 0x0043d86c: 7e73 JLE 0x43d8e1
    if(integer::condition("JLE",flags)) goto L0043d8e1;
  }
  L0043d86e: { // 0x0043d86e: 83c302 ADD EBX, 2
    s.bx = integer::add(s.bx,2u,32,flags);
  }
  L0043d871: { // 0x0043d871: 33ff XOR EDI, EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0043d873: { // 0x0043d873: 85db TEST EBX, EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L0043d875: { // 0x0043d875: 7e61 JLE 0x43d8d8
    if(integer::condition("JLE",flags)) goto L0043d8d8;
  }
  L0043d877: { // 0x0043d877: 8b4c2420 MOV ECX, dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L0043d87b: { // 0x0043d87b: 8b542422 MOV EDX, dword ptr [ESP + 0x22]
    s.dx = m.r32((f.sp+0x00000022u));
  }
  L0043d87f: { // 0x0043d87f: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0043d880: { // 0x0043d880: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L0043d881: { // 0x0043d881: 66894c242c MOV word ptr [ESP + 0x2c], CX
    m.w16((f.sp+0x0000002cu), (s.cx & 0xffffu));
  }
  L0043d886: { // 0x0043d886: 668954242e MOV word ptr [ESP + 0x2e], DX
    m.w16((f.sp+0x0000002eu), (s.dx & 0xffffu));
  }
  L0043d88b: { // 0x0043d88b: 8b4c242e MOV ECX, dword ptr [ESP + 0x2e]
    s.cx = m.r32((f.sp+0x0000002eu));
  }
  L0043d88f: { // 0x0043d88f: 8b6c242c MOV EBP, dword ptr [ESP + 0x2c]
    s.bp = m.r32((f.sp+0x0000002cu));
  }
  L0043d893: { // 0x0043d893: 03c8 ADD ECX, EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0043d895: { // 0x0043d895: 66894c244e MOV word ptr [ESP + 0x4e], CX
    m.w16((f.sp+0x0000004eu), (s.cx & 0xffffu));
  }
  L0043d89a: { // 0x0043d89a: 8d142f LEA EDX, [EDI + EBP]
    s.dx = (s.di+s.bp);
  }
  L0043d89d: { // 0x0043d89d: 8d4c241c LEA ECX, [ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L0043d8a1: { // 0x0043d8a1: 668954244c MOV word ptr [ESP + 0x4c], DX
    m.w16((f.sp+0x0000004cu), (s.dx & 0xffffu));
  }
  L0043d8a6: { // 0x0043d8a6: 8b44244c MOV EAX, dword ptr [ESP + 0x4c]
    s.ax = m.r32((f.sp+0x0000004cu));
  }
  L0043d8aa: { // 0x0043d8aa: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0043d8ab: { // 0x0043d8ab: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0043d8b0: { // 0x0043d8b0: 89442420 MOV dword ptr [ESP + 0x20], EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L0043d8b4: { // 0x0043d8b4: e8477c1000 CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4446393u); flags=s.arithmetic_flags;
  }
  L0043d8b9: { // 0x0043d8b9: 8a9022010000 MOV DL, byte ptr [EAX + 0x122]
    s.dx = with_al(s.dx, m.r8((s.ax+0x00000122u)));
  }
  L0043d8bf: { // 0x0043d8bf: fec2 INC DL
    s.dx = with_al(s.dx, integer::increment((s.dx & 0xffu),8,flags));
  }
  L0043d8c1: { // 0x0043d8c1: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0043d8c2: { // 0x0043d8c2: 3bfb CMP EDI, EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  L0043d8c4: { // 0x0043d8c4: 889022010000 MOV byte ptr [EAX + 0x122], DL
    m.w8((s.ax+0x00000122u), (s.dx & 0xffu));
  }
  L0043d8ca: { // 0x0043d8ca: 7cce JL 0x43d89a
    if(integer::condition("JL",flags)) goto L0043d89a;
  }
  L0043d8cc: { // 0x0043d8cc: 8b6c2448 MOV EBP, dword ptr [ESP + 0x48]
    s.bp = m.r32((f.sp+0x00000048u));
  }
  L0043d8d0: { // 0x0043d8d0: 8b4c2414 MOV ECX, dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0043d8d4: { // 0x0043d8d4: 8b442418 MOV EAX, dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0043d8d8: { // 0x0043d8d8: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0043d8d9: { // 0x0043d8d9: 3bc1 CMP EAX, ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0043d8db: { // 0x0043d8db: 89442418 MOV dword ptr [ESP + 0x18], EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0043d8df: { // 0x0043d8df: 7c90 JL 0x43d871
    if(integer::condition("JL",flags)) goto L0043d871;
  }
  L0043d8e1: { // 0x0043d8e1: 8b9618040000 MOV EDX, dword ptr [ESI + 0x418]
    s.dx = m.r32((s.si+0x00000418u));
  }
  L0043d8e7: { // 0x0043d8e7: 8a825a130000 MOV AL, byte ptr [EDX + 0x135a]
    s.ax = with_al(s.ax, m.r8((s.dx+0x0000135au)));
  }
  L0043d8ed: { // 0x0043d8ed: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0043d8ef: { // 0x0043d8ef: 7448 JZ 0x43d939
    if(integer::condition("JZ",flags)) goto L0043d939;
  }
  L0043d8f1: { // 0x0043d8f1: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0043d8f3: { // 0x0043d8f3: e8482d0100 CALL 0x450640
    s.arithmetic_flags=flags; invoke(m,s,f,0x00450640u,4446456u); flags=s.arithmetic_flags;
  }
  L0043d8f8: { // 0x0043d8f8: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0043d8f9: { // 0x0043d8f9: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0043d8fe: { // 0x0043d8fe: e88d7b1000 CALL 0x545490
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545490u,4446467u); flags=s.arithmetic_flags;
  }
  L0043d903: { // 0x0043d903: 8bd8 MOV EBX, EAX
    s.bx = s.ax;
  }
  L0043d905: { // 0x0043d905: 33ff XOR EDI, EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0043d907: { // 0x0043d907: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0043d908: { // 0x0043d908: 8bcb MOV ECX, EBX
    s.cx = s.bx;
  }
  L0043d90a: { // 0x0043d90a: e8b18d0300 CALL 0x4766c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004766c0u,4446479u); flags=s.arithmetic_flags;
  }
  L0043d90f: { // 0x0043d90f: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L0043d911: { // 0x0043d911: e89a3a0300 CALL 0x4713b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004713b0u,4446486u); flags=s.arithmetic_flags;
  }
  L0043d916: { // 0x0043d916: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0043d918: { // 0x0043d918: 7417 JZ 0x43d931
    if(integer::condition("JZ",flags)) goto L0043d931;
  }
  L0043d91a: { // 0x0043d91a: 8b8818040000 MOV ECX, dword ptr [EAX + 0x418]
    s.cx = m.r32((s.ax+0x00000418u));
  }
  L0043d920: { // 0x0043d920: 8a915a130000 MOV DL, byte ptr [ECX + 0x135a]
    s.dx = with_al(s.dx, m.r8((s.cx+0x0000135au)));
  }
  L0043d926: { // 0x0043d926: 84d2 TEST DL, DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L0043d928: { // 0x0043d928: 7407 JZ 0x43d931
    if(integer::condition("JZ",flags)) goto L0043d931;
  }
  L0043d92a: { // 0x0043d92a: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L0043d92c: { // 0x0043d92c: e80f2d0100 CALL 0x450640
    s.arithmetic_flags=flags; invoke(m,s,f,0x00450640u,4446513u); flags=s.arithmetic_flags;
  }
  L0043d931: { // 0x0043d931: 83c702 ADD EDI, 2
    s.di = integer::add(s.di,2u,32,flags);
  }
  L0043d934: { // 0x0043d934: 83ff08 CMP EDI, 8
    (void)integer::sub(s.di,8u,32,flags);
  }
  L0043d937: { // 0x0043d937: 7cce JL 0x43d907
    if(integer::condition("JL",flags)) goto L0043d907;
  }
  L0043d939: { // 0x0043d939: 8b8eb4010000 MOV ECX, dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L0043d93f: { // 0x0043d93f: e83ca20a00 CALL 0x4e7b80
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e7b80u,4446532u); flags=s.arithmetic_flags;
  }
  L0043d944: { // 0x0043d944: 8b8eb4010000 MOV ECX, dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L0043d94a: { // 0x0043d94a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0043d94b: { // 0x0043d94b: e840c80a00 CALL 0x4ea190
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ea190u,4446544u); flags=s.arithmetic_flags;
  }
  L0043d950: { // 0x0043d950: 8b96b4010000 MOV EDX, dword ptr [ESI + 0x1b4]
    s.dx = m.r32((s.si+0x000001b4u));
  }
  L0043d956: { // 0x0043d956: c6824401000001 MOV byte ptr [EDX + 0x144], 1
    m.w8((s.dx+0x00000144u), 1u);
  }
  L0043d95d: { // 0x0043d95d: 8a8673030000 MOV AL, byte ptr [ESI + 0x373]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000373u)));
  }
  L0043d963: { // 0x0043d963: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0043d965: { // 0x0043d965: c7863c04000000000000 MOV dword ptr [ESI + 0x43c], 0
    m.w32((s.si+0x0000043cu), 0u);
  }
  L0043d96f: { // 0x0043d96f: 7514 JNZ 0x43d985
    if(integer::condition("JNZ",flags)) goto L0043d985;
  }
  L0043d971: { // 0x0043d971: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0043d972: { // 0x0043d972: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0043d977: { // 0x0043d977: e8147b1000 CALL 0x545490
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545490u,4446588u); flags=s.arithmetic_flags;
  }
  L0043d97c: { // 0x0043d97c: f6802c01000010 TEST byte ptr [EAX + 0x12c], 0x10
    (void)integer::logical((m.r8((s.ax+0x0000012cu)))&(0x00000010u),8,flags);
  }
  L0043d983: { // 0x0043d983: 7509 JNZ 0x43d98e
    if(integer::condition("JNZ",flags)) goto L0043d98e;
  }
  L0043d985: { // 0x0043d985: a1c855a200 MOV EAX, dword ptr [0xa255c8]
    s.ax = m.r32((0x00a255c8u));
  }
  L0043d98a: { // 0x0043d98a: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0043d98c: { // 0x0043d98c: 7416 JZ 0x43d9a4
    if(integer::condition("JZ",flags)) goto L0043d9a4;
  }
  L0043d98e: { // 0x0043d98e: 8b0de4e0a100 MOV ECX, dword ptr [0xa1e0e4]
    s.cx = m.r32((0x00a1e0e4u));
  }
  L0043d994: { // 0x0043d994: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0043d996: { // 0x0043d996: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0043d997: { // 0x0043d997: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0043d999: { // 0x0043d999: ff9080010000 CALL dword ptr [EAX + 0x180]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000180u)),4446623u); flags=s.arithmetic_flags;
  }
  L0043d99f: { // 0x0043d99f: e996000000 JMP 0x43da3a
    goto L0043da3a;
  }
  L0043d9a4: { // 0x0043d9a4: 8b9618040000 MOV EDX, dword ptr [ESI + 0x418]
    s.dx = m.r32((s.si+0x00000418u));
  }
  L0043d9aa: { // 0x0043d9aa: 8b82cc0b0000 MOV EAX, dword ptr [EDX + 0xbcc]
    s.ax = m.r32((s.dx+0x00000bccu));
  }
  L0043d9b0: { // 0x0043d9b0: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0043d9b2: { // 0x0043d9b2: 0f8482000000 JZ 0x43da3a
    if(integer::condition("JZ",flags)) goto L0043da3a;
  }
  L0043d9b8: { // 0x0043d9b8: 8b86e8040000 MOV EAX, dword ptr [ESI + 0x4e8]
    s.ax = m.r32((s.si+0x000004e8u));
  }
  L0043d9be: { // 0x0043d9be: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0043d9c0: { // 0x0043d9c0: 756b JNZ 0x43da2d
    if(integer::condition("JNZ",flags)) goto L0043da2d;
  }
  L0043d9c2: { // 0x0043d9c2: 6a4c PUSH 0x4c
    f.push(m,0x0000004cu);
  }
  L0043d9c4: { // 0x0043d9c4: e88eff3200 CALL 0x76d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,4446665u); flags=s.arithmetic_flags;
  }
  L0043d9c9: { // 0x0043d9c9: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L0043d9cb: { // 0x0043d9cb: 83c404 ADD ESP, 4
    f.sp = integer::add(f.sp,4u,32,flags);
  }
  L0043d9ce: { // 0x0043d9ce: 85ff TEST EDI, EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0043d9d0: { // 0x0043d9d0: 7453 JZ 0x43da25
    if(integer::condition("JZ",flags)) goto L0043da25;
  }
  L0043d9d2: { // 0x0043d9d2: 8b8618040000 MOV EAX, dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L0043d9d8: { // 0x0043d9d8: 8b88d80b0000 MOV ECX, dword ptr [EAX + 0xbd8]
    s.cx = m.r32((s.ax+0x00000bd8u));
  }
  L0043d9de: { // 0x0043d9de: 8b90d40b0000 MOV EDX, dword ptr [EAX + 0xbd4]
    s.dx = m.r32((s.ax+0x00000bd4u));
  }
  L0043d9e4: { // 0x0043d9e4: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0043d9e5: { // 0x0043d9e5: 8b88d00b0000 MOV ECX, dword ptr [EAX + 0xbd0]
    s.cx = m.r32((s.ax+0x00000bd0u));
  }
  L0043d9eb: { // 0x0043d9eb: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0043d9ec: { // 0x0043d9ec: 8b90cc0b0000 MOV EDX, dword ptr [EAX + 0xbcc]
    s.dx = m.r32((s.ax+0x00000bccu));
  }
  L0043d9f2: { // 0x0043d9f2: 8b80c80b0000 MOV EAX, dword ptr [EAX + 0xbc8]
    s.ax = m.r32((s.ax+0x00000bc8u));
  }
  L0043d9f8: { // 0x0043d9f8: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0043d9f9: { // 0x0043d9f9: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0043d9fa: { // 0x0043d9fa: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0043d9fc: { // 0x0043d9fc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0043d9fd: { // 0x0043d9fd: 8d44244c LEA EAX, [ESP + 0x4c]
    s.ax = (f.sp+0x0000004cu);
  }
  L0043da01: { // 0x0043da01: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0043da02: { // 0x0043da02: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0043da04: { // 0x0043da04: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),4446727u); flags=s.arithmetic_flags;
  }
  L0043da07: { // 0x0043da07: 8b10 MOV EDX, dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0043da09: { // 0x0043da09: 83ec0c SUB ESP, 0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L0043da0c: { // 0x0043da0c: 8bcc MOV ECX, ESP
    s.cx = f.sp;
  }
  L0043da0e: { // 0x0043da0e: 8911 MOV dword ptr [ECX], EDX
    m.w32((s.cx), s.dx);
  }
  L0043da10: { // 0x0043da10: 8b5004 MOV EDX, dword ptr [EAX + 4]
    s.dx = m.r32((s.ax+4u));
  }
  L0043da13: { // 0x0043da13: 8b4008 MOV EAX, dword ptr [EAX + 8]
    s.ax = m.r32((s.ax+8u));
  }
  L0043da16: { // 0x0043da16: 895104 MOV dword ptr [ECX + 4], EDX
    m.w32((s.cx+4u), s.dx);
  }
  L0043da19: { // 0x0043da19: 894108 MOV dword ptr [ECX + 8], EAX
    m.w32((s.cx+8u), s.ax);
  }
  L0043da1c: { // 0x0043da1c: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L0043da1e: { // 0x0043da1e: e8fd790f00 CALL 0x535420
    s.arithmetic_flags=flags; invoke(m,s,f,0x00535420u,4446755u); flags=s.arithmetic_flags;
  }
  L0043da23: { // 0x0043da23: eb02 JMP 0x43da27
    goto L0043da27;
  }
  L0043da25: { // 0x0043da25: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0043da27: { // 0x0043da27: 8986e8040000 MOV dword ptr [ESI + 0x4e8], EAX
    m.w32((s.si+0x000004e8u), s.ax);
  }
  L0043da2d: { // 0x0043da2d: 8b8ee8040000 MOV ECX, dword ptr [ESI + 0x4e8]
    s.cx = m.r32((s.si+0x000004e8u));
  }
  L0043da33: { // 0x0043da33: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0043da35: { // 0x0043da35: e8e67c0f00 CALL 0x535720
    s.arithmetic_flags=flags; invoke(m,s,f,0x00535720u,4446778u); flags=s.arithmetic_flags;
  }
  L0043da3a: { // 0x0043da3a: 8b8e18040000 MOV ECX, dword ptr [ESI + 0x418]
    s.cx = m.r32((s.si+0x00000418u));
  }
  L0043da40: { // 0x0043da40: 8a8158130000 MOV AL, byte ptr [ECX + 0x1358]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00001358u)));
  }
  L0043da46: { // 0x0043da46: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0043da48: { // 0x0043da48: 7444 JZ 0x43da8e
    if(integer::condition("JZ",flags)) goto L0043da8e;
  }
  L0043da4a: { // 0x0043da4a: a1c483a200 MOV EAX, dword ptr [0xa283c4]
    s.ax = m.r32((0x00a283c4u));
  }
  L0043da4f: { // 0x0043da4f: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0043da51: { // 0x0043da51: 753b JNZ 0x43da8e
    if(integer::condition("JNZ",flags)) goto L0043da8e;
  }
  L0043da53: { // 0x0043da53: 8a467d MOV AL, byte ptr [ESI + 0x7d]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000007du)));
  }
  L0043da56: { // 0x0043da56: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0043da58: { // 0x0043da58: 7434 JZ 0x43da8e
    if(integer::condition("JZ",flags)) goto L0043da8e;
  }
  L0043da5a: { // 0x0043da5a: 8a4676 MOV AL, byte ptr [ESI + 0x76]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000076u)));
  }
  L0043da5d: { // 0x0043da5d: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0043da5f: { // 0x0043da5f: 752d JNZ 0x43da8e
    if(integer::condition("JNZ",flags)) goto L0043da8e;
  }
  L0043da61: { // 0x0043da61: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0043da63: { // 0x0043da63: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0043da65: { // 0x0043da65: e846020100 CALL 0x44dcb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0044dcb0u,4446826u); flags=s.arithmetic_flags;
  }
  L0043da6a: { // 0x0043da6a: 6a02 PUSH 2
    f.push(m,2u);
  }
  L0043da6c: { // 0x0043da6c: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0043da6e: { // 0x0043da6e: e83d020100 CALL 0x44dcb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0044dcb0u,4446835u); flags=s.arithmetic_flags;
  }
  L0043da73: { // 0x0043da73: 6a04 PUSH 4
    f.push(m,4u);
  }
  L0043da75: { // 0x0043da75: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0043da77: { // 0x0043da77: e834020100 CALL 0x44dcb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0044dcb0u,4446844u); flags=s.arithmetic_flags;
  }
  L0043da7c: { // 0x0043da7c: 6a06 PUSH 6
    f.push(m,6u);
  }
  L0043da7e: { // 0x0043da7e: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0043da80: { // 0x0043da80: e82b020100 CALL 0x44dcb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0044dcb0u,4446853u); flags=s.arithmetic_flags;
  }
  L0043da85: { // 0x0043da85: 6a01 PUSH 1
    f.push(m,1u);
  }
  L0043da87: { // 0x0043da87: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0043da89: { // 0x0043da89: e802080100 CALL 0x44e290
    s.arithmetic_flags=flags; invoke(m,s,f,0x0044e290u,4446862u); flags=s.arithmetic_flags;
  }
  L0043da8e: { // 0x0043da8e: 8b8eb4010000 MOV ECX, dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L0043da94: { // 0x0043da94: e8576d0b00 CALL 0x4f47f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f47f0u,4446873u); flags=s.arithmetic_flags;
  }
  L0043da99: { // 0x0043da99: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0043da9b: { // 0x0043da9b: 7511 JNZ 0x43daae
    if(integer::condition("JNZ",flags)) goto L0043daae;
  }
  L0043da9d: { // 0x0043da9d: 8b86b4010000 MOV EAX, dword ptr [ESI + 0x1b4]
    s.ax = m.r32((s.si+0x000001b4u));
  }
  L0043daa3: { // 0x0043daa3: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0043daa5: { // 0x0043daa5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0043daa6: { // 0x0043daa6: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0043daa8: { // 0x0043daa8: ff9280010000 CALL dword ptr [EDX + 0x180]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000180u)),4446894u); flags=s.arithmetic_flags;
  }
  L0043daae: { // 0x0043daae: 8a8672030000 MOV AL, byte ptr [ESI + 0x372]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000372u)));
  }
  L0043dab4: { // 0x0043dab4: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0043dab6: { // 0x0043dab6: 7413 JZ 0x43dacb
    if(integer::condition("JZ",flags)) goto L0043dacb;
  }
  L0043dab8: { // 0x0043dab8: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0043daba: { // 0x0043daba: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0043dabf: { // 0x0043dabf: c60528bd810001 MOV byte ptr [0x81bd28], 1
    m.w8((0x0081bd28u), 1u);
  }
  L0043dac6: { // 0x0043dac6: e865250a00 CALL 0x4e0030
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e0030u,4446923u); flags=s.arithmetic_flags;
  }
  L0043dacb: { // 0x0043dacb: 8b8618040000 MOV EAX, dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L0043dad1: { // 0x0043dad1: 8b887c060000 MOV ECX, dword ptr [EAX + 0x67c]
    s.cx = m.r32((s.ax+0x0000067cu));
  }
  L0043dad7: { // 0x0043dad7: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0043dad9: { // 0x0043dad9: 0f84b2000000 JZ 0x43db91
    if(integer::condition("JZ",flags)) goto L0043db91;
  }
  L0043dadf: { // 0x0043dadf: 8b8e64020000 MOV ECX, dword ptr [ESI + 0x264]
    s.cx = m.r32((s.si+0x00000264u));
  }
  L0043dae5: { // 0x0043dae5: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0043dae7: { // 0x0043dae7: 0f85a4000000 JNZ 0x43db91
    if(integer::condition("JNZ",flags)) goto L0043db91;
  }
  L0043daed: { // 0x0043daed: 0580060000 ADD EAX, 0x680
    s.ax = integer::add(s.ax,0x00000680u,32,flags);
  }
  L0043daf2: { // 0x0043daf2: 68e8000000 PUSH 0xe8
    f.push(m,0x000000e8u);
  }
  L0043daf7: { // 0x0043daf7: 8b18 MOV EBX, dword ptr [EAX]
    s.bx = m.r32((s.ax));
  }
  L0043daf9: { // 0x0043daf9: 8b4804 MOV ECX, dword ptr [EAX + 4]
    s.cx = m.r32((s.ax+4u));
  }
  L0043dafc: { // 0x0043dafc: 894c2434 MOV dword ptr [ESP + 0x34], ECX
    m.w32((f.sp+0x00000034u), s.cx);
  }
  L0043db00: { // 0x0043db00: 8b5008 MOV EDX, dword ptr [EAX + 8]
    s.dx = m.r32((s.ax+8u));
  }
  L0043db03: { // 0x0043db03: 89542438 MOV dword ptr [ESP + 0x38], EDX
    m.w32((f.sp+0x00000038u), s.dx);
  }
  L0043db07: { // 0x0043db07: e84bfe3200 CALL 0x76d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,4446988u); flags=s.arithmetic_flags;
  }
  L0043db0c: { // 0x0043db0c: 8be8 MOV EBP, EAX
    s.bp = s.ax;
  }
  L0043db0e: { // 0x0043db0e: 83c404 ADD ESP, 4
    f.sp = integer::add(f.sp,4u,32,flags);
  }
  L0043db11: { // 0x0043db11: 85ed TEST EBP, EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0043db13: { // 0x0043db13: 7470 JZ 0x43db85
    if(integer::condition("JZ",flags)) goto L0043db85;
  }
  L0043db15: { // 0x0043db15: 8d8688000000 LEA EAX, [ESI + 0x88]
    s.ax = (s.si+0x00000088u);
  }
  L0043db1b: { // 0x0043db1b: 6878708300 PUSH 0x837078
    f.push(m,0x00837078u);
  }
  L0043db20: { // 0x0043db20: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L0043db22: { // 0x0043db22: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0043db24: { // 0x0043db24: 8b0f MOV ECX, dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  L0043db26: { // 0x0043db26: 03cb ADD ECX, EBX
    s.cx = integer::add(s.cx,s.bx,32,flags);
  }
  L0043db28: { // 0x0043db28: 8b5c2438 MOV EBX, dword ptr [ESP + 0x38]
    s.bx = m.r32((f.sp+0x00000038u));
  }
  L0043db2c: { // 0x0043db2c: 8b5704 MOV EDX, dword ptr [EDI + 4]
    s.dx = m.r32((s.di+4u));
  }
  L0043db2f: { // 0x0043db2f: 894c2440 MOV dword ptr [ESP + 0x40], ECX
    m.w32((f.sp+0x00000040u), s.cx);
  }
  L0043db33: { // 0x0043db33: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0043db35: { // 0x0043db35: 03d3 ADD EDX, EBX
    s.dx = integer::add(s.dx,s.bx,32,flags);
  }
  L0043db37: { // 0x0043db37: 8b7f08 MOV EDI, dword ptr [EDI + 8]
    s.di = m.r32((s.di+8u));
  }
  L0043db3a: { // 0x0043db3a: 8b5c243c MOV EBX, dword ptr [ESP + 0x3c]
    s.bx = m.r32((f.sp+0x0000003cu));
  }
  L0043db3e: { // 0x0043db3e: 894c2428 MOV dword ptr [ESP + 0x28], ECX
    m.w32((f.sp+0x00000028u), s.cx);
  }
  L0043db42: { // 0x0043db42: 89542444 MOV dword ptr [ESP + 0x44], EDX
    m.w32((f.sp+0x00000044u), s.dx);
  }
  L0043db46: { // 0x0043db46: 8b5004 MOV EDX, dword ptr [EAX + 4]
    s.dx = m.r32((s.ax+4u));
  }
  L0043db49: { // 0x0043db49: 8b4008 MOV EAX, dword ptr [EAX + 8]
    s.ax = m.r32((s.ax+8u));
  }
  L0043db4c: { // 0x0043db4c: 8d4c2428 LEA ECX, [ESP + 0x28]
    s.cx = (f.sp+0x00000028u);
  }
  L0043db50: { // 0x0043db50: 03fb ADD EDI, EBX
    s.di = integer::add(s.di,s.bx,32,flags);
  }
  L0043db52: { // 0x0043db52: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0043db53: { // 0x0043db53: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0043db58: { // 0x0043db58: 897c244c MOV dword ptr [ESP + 0x4c], EDI
    m.w32((f.sp+0x0000004cu), s.di);
  }
  L0043db5c: { // 0x0043db5c: 89542430 MOV dword ptr [ESP + 0x30], EDX
    m.w32((f.sp+0x00000030u), s.dx);
  }
  L0043db60: { // 0x0043db60: 89442434 MOV dword ptr [ESP + 0x34], EAX
    m.w32((f.sp+0x00000034u), s.ax);
  }
  L0043db64: { // 0x0043db64: e827791000 CALL 0x545490
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545490u,4447081u); flags=s.arithmetic_flags;
  }
  L0043db69: { // 0x0043db69: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0043db6a: { // 0x0043db6a: 8b8618040000 MOV EAX, dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L0043db70: { // 0x0043db70: 8d542444 LEA EDX, [ESP + 0x44]
    s.dx = (f.sp+0x00000044u);
  }
  L0043db74: { // 0x0043db74: 8b887c060000 MOV ECX, dword ptr [EAX + 0x67c]
    s.cx = m.r32((s.ax+0x0000067cu));
  }
  L0043db7a: { // 0x0043db7a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0043db7b: { // 0x0043db7b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0043db7c: { // 0x0043db7c: 8bcd MOV ECX, EBP
    s.cx = s.bp;
  }
  L0043db7e: { // 0x0043db7e: e8cd4a1c00 CALL 0x602650
    s.arithmetic_flags=flags; invoke(m,s,f,0x00602650u,4447107u); flags=s.arithmetic_flags;
  }
  L0043db83: { // 0x0043db83: eb02 JMP 0x43db87
    goto L0043db87;
  }
  L0043db85: { // 0x0043db85: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0043db87: { // 0x0043db87: 8b6c2448 MOV EBP, dword ptr [ESP + 0x48]
    s.bp = m.r32((f.sp+0x00000048u));
  }
  L0043db8b: { // 0x0043db8b: 898664020000 MOV dword ptr [ESI + 0x264], EAX
    m.w32((s.si+0x00000264u), s.ax);
  }
  L0043db91: { // 0x0043db91: a1881b8200 MOV EAX, dword ptr [0x821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L0043db96: { // 0x0043db96: 8b9618040000 MOV EDX, dword ptr [ESI + 0x418]
    s.dx = m.r32((s.si+0x00000418u));
  }
  L0043db9c: { // 0x0043db9c: 3b908c070000 CMP EDX, dword ptr [EAX + 0x78c]
    (void)integer::sub(s.dx,m.r32((s.ax+0x0000078cu)),32,flags);
  }
  L0043dba2: { // 0x0043dba2: 0f85d5000000 JNZ 0x43dc7d
    if(integer::condition("JNZ",flags)) goto L0043dc7d;
  }
  L0043dba8: { // 0x0043dba8: 8b442448 MOV EAX, dword ptr [ESP + 0x48]
    s.ax = m.r32((f.sp+0x00000048u));
  }
  L0043dbac: { // 0x0043dbac: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0043dbb1: { // 0x0043dbb1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0043dbb2: { // 0x0043dbb2: e8d9781000 CALL 0x545490
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545490u,4447159u); flags=s.arithmetic_flags;
  }
  L0043dbb7: { // 0x0043dbb7: 8b7824 MOV EDI, dword ptr [EAX + 0x24]
    s.di = m.r32((s.ax+0x00000024u));
  }
  L0043dbba: { // 0x0043dbba: 8d44244c LEA EAX, [ESP + 0x4c]
    s.ax = (f.sp+0x0000004cu);
  }
  L0043dbbe: { // 0x0043dbbe: 897c242c MOV dword ptr [ESP + 0x2c], EDI
    m.w32((f.sp+0x0000002cu), s.di);
  }
  L0043dbc2: { // 0x0043dbc2: 8b6c242e MOV EBP, dword ptr [ESP + 0x2e]
    s.bp = m.r32((f.sp+0x0000002eu));
  }
  L0043dbc6: { // 0x0043dbc6: 8d4f01 LEA ECX, [EDI + 1]
    s.cx = (s.di+1u);
  }
  L0043dbc9: { // 0x0043dbc9: 66896c244e MOV word ptr [ESP + 0x4e], BP
    m.w16((f.sp+0x0000004eu), (s.bp & 0xffffu));
  }
  L0043dbce: { // 0x0043dbce: 66894c244c MOV word ptr [ESP + 0x4c], CX
    m.w16((f.sp+0x0000004cu), (s.cx & 0xffffu));
  }
  L0043dbd3: { // 0x0043dbd3: 8b54244c MOV EDX, dword ptr [ESP + 0x4c]
    s.dx = m.r32((f.sp+0x0000004cu));
  }
  L0043dbd7: { // 0x0043dbd7: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0043dbd9: { // 0x0043dbd9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0043dbda: { // 0x0043dbda: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0043dbdf: { // 0x0043dbdf: 89542454 MOV dword ptr [ESP + 0x54], EDX
    m.w32((f.sp+0x00000054u), s.dx);
  }
  L0043dbe3: { // 0x0043dbe3: e818791000 CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4447208u); flags=s.arithmetic_flags;
  }
  L0043dbe8: { // 0x0043dbe8: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L0043dbea: { // 0x0043dbea: e871790300 CALL 0x475560
    s.arithmetic_flags=flags; invoke(m,s,f,0x00475560u,4447215u); flags=s.arithmetic_flags;
  }
  L0043dbef: { // 0x0043dbef: 8d4fff LEA ECX, [EDI - 1]
    s.cx = (s.di-1u);
  }
  L0043dbf2: { // 0x0043dbf2: 66896c244e MOV word ptr [ESP + 0x4e], BP
    m.w16((f.sp+0x0000004eu), (s.bp & 0xffffu));
  }
  L0043dbf7: { // 0x0043dbf7: 66894c244c MOV word ptr [ESP + 0x4c], CX
    m.w16((f.sp+0x0000004cu), (s.cx & 0xffffu));
  }
  L0043dbfc: { // 0x0043dbfc: 8b54244c MOV EDX, dword ptr [ESP + 0x4c]
    s.dx = m.r32((f.sp+0x0000004cu));
  }
  L0043dc00: { // 0x0043dc00: 8d44244c LEA EAX, [ESP + 0x4c]
    s.ax = (f.sp+0x0000004cu);
  }
  L0043dc04: { // 0x0043dc04: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0043dc06: { // 0x0043dc06: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0043dc07: { // 0x0043dc07: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0043dc0c: { // 0x0043dc0c: 89542454 MOV dword ptr [ESP + 0x54], EDX
    m.w32((f.sp+0x00000054u), s.dx);
  }
  L0043dc10: { // 0x0043dc10: e8eb781000 CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4447253u); flags=s.arithmetic_flags;
  }
  L0043dc15: { // 0x0043dc15: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L0043dc17: { // 0x0043dc17: e844790300 CALL 0x475560
    s.arithmetic_flags=flags; invoke(m,s,f,0x00475560u,4447260u); flags=s.arithmetic_flags;
  }
  L0043dc1c: { // 0x0043dc1c: 8d4d01 LEA ECX, [EBP + 1]
    s.cx = (s.bp+1u);
  }
  L0043dc1f: { // 0x0043dc1f: 66897c244c MOV word ptr [ESP + 0x4c], DI
    m.w16((f.sp+0x0000004cu), (s.di & 0xffffu));
  }
  L0043dc24: { // 0x0043dc24: 66894c244e MOV word ptr [ESP + 0x4e], CX
    m.w16((f.sp+0x0000004eu), (s.cx & 0xffffu));
  }
  L0043dc29: { // 0x0043dc29: 8b54244c MOV EDX, dword ptr [ESP + 0x4c]
    s.dx = m.r32((f.sp+0x0000004cu));
  }
  L0043dc2d: { // 0x0043dc2d: 8d44244c LEA EAX, [ESP + 0x4c]
    s.ax = (f.sp+0x0000004cu);
  }
  L0043dc31: { // 0x0043dc31: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0043dc33: { // 0x0043dc33: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0043dc34: { // 0x0043dc34: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0043dc39: { // 0x0043dc39: 89542454 MOV dword ptr [ESP + 0x54], EDX
    m.w32((f.sp+0x00000054u), s.dx);
  }
  L0043dc3d: { // 0x0043dc3d: e8be781000 CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4447298u); flags=s.arithmetic_flags;
  }
  L0043dc42: { // 0x0043dc42: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L0043dc44: { // 0x0043dc44: e817790300 CALL 0x475560
    s.arithmetic_flags=flags; invoke(m,s,f,0x00475560u,4447305u); flags=s.arithmetic_flags;
  }
  L0043dc49: { // 0x0043dc49: 4d DEC EBP
    s.bp = integer::decrement(s.bp,32,flags);
  }
  L0043dc4a: { // 0x0043dc4a: 66897c244c MOV word ptr [ESP + 0x4c], DI
    m.w16((f.sp+0x0000004cu), (s.di & 0xffffu));
  }
  L0043dc4f: { // 0x0043dc4f: 66896c244e MOV word ptr [ESP + 0x4e], BP
    m.w16((f.sp+0x0000004eu), (s.bp & 0xffffu));
  }
  L0043dc54: { // 0x0043dc54: 8b4c244c MOV ECX, dword ptr [ESP + 0x4c]
    s.cx = m.r32((f.sp+0x0000004cu));
  }
  L0043dc58: { // 0x0043dc58: 8d54244c LEA EDX, [ESP + 0x4c]
    s.dx = (f.sp+0x0000004cu);
  }
  L0043dc5c: { // 0x0043dc5c: 894c244c MOV dword ptr [ESP + 0x4c], ECX
    m.w32((f.sp+0x0000004cu), s.cx);
  }
  L0043dc60: { // 0x0043dc60: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0043dc62: { // 0x0043dc62: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0043dc63: { // 0x0043dc63: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0043dc68: { // 0x0043dc68: e893781000 CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4447341u); flags=s.arithmetic_flags;
  }
  L0043dc6d: { // 0x0043dc6d: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L0043dc6f: { // 0x0043dc6f: e8ec780300 CALL 0x475560
    s.arithmetic_flags=flags; invoke(m,s,f,0x00475560u,4447348u); flags=s.arithmetic_flags;
  }
  L0043dc74: { // 0x0043dc74: a1881b8200 MOV EAX, dword ptr [0x821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L0043dc79: { // 0x0043dc79: 8b6c2448 MOV EBP, dword ptr [ESP + 0x48]
    s.bp = m.r32((f.sp+0x00000048u));
  }
  L0043dc7d: { // 0x0043dc7d: 8b8e18040000 MOV ECX, dword ptr [ESI + 0x418]
    s.cx = m.r32((s.si+0x00000418u));
  }
  L0043dc83: { // 0x0043dc83: 8b907c070000 MOV EDX, dword ptr [EAX + 0x77c]
    s.dx = m.r32((s.ax+0x0000077cu));
  }
  L0043dc89: { // 0x0043dc89: 3bca CMP ECX, EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L0043dc8b: { // 0x0043dc8b: 7408 JZ 0x43dc95
    if(integer::condition("JZ",flags)) goto L0043dc95;
  }
  L0043dc8d: { // 0x0043dc8d: 3b8884070000 CMP ECX, dword ptr [EAX + 0x784]
    (void)integer::sub(s.cx,m.r32((s.ax+0x00000784u)),32,flags);
  }
  L0043dc93: { // 0x0043dc93: 7576 JNZ 0x43dd0b
    if(integer::condition("JNZ",flags)) goto L0043dd0b;
  }
  L0043dc95: { // 0x0043dc95: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0043dc96: { // 0x0043dc96: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0043dc9b: { // 0x0043dc9b: e8f0771000 CALL 0x545490
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545490u,4447392u); flags=s.arithmetic_flags;
  }
  L0043dca0: { // 0x0043dca0: 8b7824 MOV EDI, dword ptr [EAX + 0x24]
    s.di = m.r32((s.ax+0x00000024u));
  }
  L0043dca3: { // 0x0043dca3: 8d542448 LEA EDX, [ESP + 0x48]
    s.dx = (f.sp+0x00000048u);
  }
  L0043dca7: { // 0x0043dca7: 897c244c MOV dword ptr [ESP + 0x4c], EDI
    m.w32((f.sp+0x0000004cu), s.di);
  }
  L0043dcab: { // 0x0043dcab: 668b5c244e MOV BX, word ptr [ESP + 0x4e]
    s.bx = with_ax(s.bx, m.r16((f.sp+0x0000004eu)));
  }
  L0043dcb0: { // 0x0043dcb0: 8d47ff LEA EAX, [EDI - 1]
    s.ax = (s.di-1u);
  }
  L0043dcb3: { // 0x0043dcb3: 66895c244a MOV word ptr [ESP + 0x4a], BX
    m.w16((f.sp+0x0000004au), (s.bx & 0xffffu));
  }
  L0043dcb8: { // 0x0043dcb8: 6689442448 MOV word ptr [ESP + 0x48], AX
    m.w16((f.sp+0x00000048u), (s.ax & 0xffffu));
  }
  L0043dcbd: { // 0x0043dcbd: 8b4c2448 MOV ECX, dword ptr [ESP + 0x48]
    s.cx = m.r32((f.sp+0x00000048u));
  }
  L0043dcc1: { // 0x0043dcc1: 894c2448 MOV dword ptr [ESP + 0x48], ECX
    m.w32((f.sp+0x00000048u), s.cx);
  }
  L0043dcc5: { // 0x0043dcc5: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0043dcc7: { // 0x0043dcc7: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0043dcc8: { // 0x0043dcc8: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0043dccd: { // 0x0043dccd: e82e781000 CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4447442u); flags=s.arithmetic_flags;
  }
  L0043dcd2: { // 0x0043dcd2: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L0043dcd4: { // 0x0043dcd4: e887780300 CALL 0x475560
    s.arithmetic_flags=flags; invoke(m,s,f,0x00475560u,4447449u); flags=s.arithmetic_flags;
  }
  L0043dcd9: { // 0x0043dcd9: 83c703 ADD EDI, 3
    s.di = integer::add(s.di,3u,32,flags);
  }
  L0043dcdc: { // 0x0043dcdc: 8d4c2448 LEA ECX, [ESP + 0x48]
    s.cx = (f.sp+0x00000048u);
  }
  L0043dce0: { // 0x0043dce0: 66897c2448 MOV word ptr [ESP + 0x48], DI
    m.w16((f.sp+0x00000048u), (s.di & 0xffffu));
  }
  L0043dce5: { // 0x0043dce5: 66895c244a MOV word ptr [ESP + 0x4a], BX
    m.w16((f.sp+0x0000004au), (s.bx & 0xffffu));
  }
  L0043dcea: { // 0x0043dcea: 8b442448 MOV EAX, dword ptr [ESP + 0x48]
    s.ax = m.r32((f.sp+0x00000048u));
  }
  L0043dcee: { // 0x0043dcee: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0043dcf0: { // 0x0043dcf0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0043dcf1: { // 0x0043dcf1: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0043dcf6: { // 0x0043dcf6: 89442450 MOV dword ptr [ESP + 0x50], EAX
    m.w32((f.sp+0x00000050u), s.ax);
  }
  L0043dcfa: { // 0x0043dcfa: e801781000 CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4447487u); flags=s.arithmetic_flags;
  }
  L0043dcff: { // 0x0043dcff: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L0043dd01: { // 0x0043dd01: e85a780300 CALL 0x475560
    s.arithmetic_flags=flags; invoke(m,s,f,0x00475560u,4447494u); flags=s.arithmetic_flags;
  }
  L0043dd06: { // 0x0043dd06: a1881b8200 MOV EAX, dword ptr [0x821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L0043dd0b: { // 0x0043dd0b: 8b8e18040000 MOV ECX, dword ptr [ESI + 0x418]
    s.cx = m.r32((s.si+0x00000418u));
  }
  L0043dd11: { // 0x0043dd11: 8b9080070000 MOV EDX, dword ptr [EAX + 0x780]
    s.dx = m.r32((s.ax+0x00000780u));
  }
  L0043dd17: { // 0x0043dd17: 3bca CMP ECX, EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L0043dd19: { // 0x0043dd19: 7408 JZ 0x43dd23
    if(integer::condition("JZ",flags)) goto L0043dd23;
  }
  L0043dd1b: { // 0x0043dd1b: 3b8888070000 CMP ECX, dword ptr [EAX + 0x788]
    (void)integer::sub(s.cx,m.r32((s.ax+0x00000788u)),32,flags);
  }
  L0043dd21: { // 0x0043dd21: 7570 JNZ 0x43dd93
    if(integer::condition("JNZ",flags)) goto L0043dd93;
  }
  L0043dd23: { // 0x0043dd23: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0043dd24: { // 0x0043dd24: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0043dd29: { // 0x0043dd29: e862771000 CALL 0x545490
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545490u,4447534u); flags=s.arithmetic_flags;
  }
  L0043dd2e: { // 0x0043dd2e: 8b7824 MOV EDI, dword ptr [EAX + 0x24]
    s.di = m.r32((s.ax+0x00000024u));
  }
  L0043dd31: { // 0x0043dd31: 8d4c2448 LEA ECX, [ESP + 0x48]
    s.cx = (f.sp+0x00000048u);
  }
  L0043dd35: { // 0x0043dd35: 897c242c MOV dword ptr [ESP + 0x2c], EDI
    m.w32((f.sp+0x0000002cu), s.di);
  }
  L0043dd39: { // 0x0043dd39: 8b5c242e MOV EBX, dword ptr [ESP + 0x2e]
    s.bx = m.r32((f.sp+0x0000002eu));
  }
  L0043dd3d: { // 0x0043dd3d: 66897c2448 MOV word ptr [ESP + 0x48], DI
    m.w16((f.sp+0x00000048u), (s.di & 0xffffu));
  }
  L0043dd42: { // 0x0043dd42: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0043dd44: { // 0x0043dd44: 8d53ff LEA EDX, [EBX - 1]
    s.dx = (s.bx-1u);
  }
  L0043dd47: { // 0x0043dd47: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0043dd48: { // 0x0043dd48: 6689542452 MOV word ptr [ESP + 0x52], DX
    m.w16((f.sp+0x00000052u), (s.dx & 0xffffu));
  }
  L0043dd4d: { // 0x0043dd4d: 8b442450 MOV EAX, dword ptr [ESP + 0x50]
    s.ax = m.r32((f.sp+0x00000050u));
  }
  L0043dd51: { // 0x0043dd51: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0043dd56: { // 0x0043dd56: 89442450 MOV dword ptr [ESP + 0x50], EAX
    m.w32((f.sp+0x00000050u), s.ax);
  }
  L0043dd5a: { // 0x0043dd5a: e8a1771000 CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4447583u); flags=s.arithmetic_flags;
  }
  L0043dd5f: { // 0x0043dd5f: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L0043dd61: { // 0x0043dd61: e8fa770300 CALL 0x475560
    s.arithmetic_flags=flags; invoke(m,s,f,0x00475560u,4447590u); flags=s.arithmetic_flags;
  }
  L0043dd66: { // 0x0043dd66: 83c303 ADD EBX, 3
    s.bx = integer::add(s.bx,3u,32,flags);
  }
  L0043dd69: { // 0x0043dd69: 66897c2448 MOV word ptr [ESP + 0x48], DI
    m.w16((f.sp+0x00000048u), (s.di & 0xffffu));
  }
  L0043dd6e: { // 0x0043dd6e: 66895c244a MOV word ptr [ESP + 0x4a], BX
    m.w16((f.sp+0x0000004au), (s.bx & 0xffffu));
  }
  L0043dd73: { // 0x0043dd73: 8b542448 MOV EDX, dword ptr [ESP + 0x48]
    s.dx = m.r32((f.sp+0x00000048u));
  }
  L0043dd77: { // 0x0043dd77: 8d442448 LEA EAX, [ESP + 0x48]
    s.ax = (f.sp+0x00000048u);
  }
  L0043dd7b: { // 0x0043dd7b: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0043dd7d: { // 0x0043dd7d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0043dd7e: { // 0x0043dd7e: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0043dd83: { // 0x0043dd83: 89542450 MOV dword ptr [ESP + 0x50], EDX
    m.w32((f.sp+0x00000050u), s.dx);
  }
  L0043dd87: { // 0x0043dd87: e874771000 CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4447628u); flags=s.arithmetic_flags;
  }
  L0043dd8c: { // 0x0043dd8c: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L0043dd8e: { // 0x0043dd8e: e8cd770300 CALL 0x475560
    s.arithmetic_flags=flags; invoke(m,s,f,0x00475560u,4447635u); flags=s.arithmetic_flags;
  }
  L0043dd93: { // 0x0043dd93: 8b8e18040000 MOV ECX, dword ptr [ESI + 0x418]
    s.cx = m.r32((s.si+0x00000418u));
  }
  L0043dd99: { // 0x0043dd99: 8a81ff110000 MOV AL, byte ptr [ECX + 0x11ff]
    s.ax = with_al(s.ax, m.r8((s.cx+0x000011ffu)));
  }
  L0043dd9f: { // 0x0043dd9f: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0043dda1: { // 0x0043dda1: 7423 JZ 0x43ddc6
    if(integer::condition("JZ",flags)) goto L0043ddc6;
  }
  L0043dda3: { // 0x0043dda3: 68d0000000 PUSH 0xd0
    f.push(m,0x000000d0u);
  }
  L0043dda8: { // 0x0043dda8: e8aafb3200 CALL 0x76d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,4447661u); flags=s.arithmetic_flags;
  }
  L0043ddad: { // 0x0043ddad: 83c404 ADD ESP, 4
    f.sp = integer::add(f.sp,4u,32,flags);
  }
  L0043ddb0: { // 0x0043ddb0: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0043ddb2: { // 0x0043ddb2: 740a JZ 0x43ddbe
    if(integer::condition("JZ",flags)) goto L0043ddbe;
  }
  L0043ddb4: { // 0x0043ddb4: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0043ddb5: { // 0x0043ddb5: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L0043ddb7: { // 0x0043ddb7: e8c450ffff CALL 0x432e80
    s.arithmetic_flags=flags; invoke(m,s,f,0x00432e80u,4447676u); flags=s.arithmetic_flags;
  }
  L0043ddbc: { // 0x0043ddbc: eb02 JMP 0x43ddc0
    goto L0043ddc0;
  }
  L0043ddbe: { // 0x0043ddbe: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0043ddc0: { // 0x0043ddc0: 8986d4040000 MOV dword ptr [ESI + 0x4d4], EAX
    m.w32((s.si+0x000004d4u), s.ax);
  }
  L0043ddc6: { // 0x0043ddc6: 8b9618040000 MOV EDX, dword ptr [ESI + 0x418]
    s.dx = m.r32((s.si+0x00000418u));
  }
  L0043ddcc: { // 0x0043ddcc: c6862b03000000 MOV byte ptr [ESI + 0x32b], 0
    m.w8((s.si+0x0000032bu), 0u);
  }
  L0043ddd3: { // 0x0043ddd3: 8b82440c0000 MOV EAX, dword ptr [EDX + 0xc44]
    s.ax = m.r32((s.dx+0x00000c44u));
  }
  L0043ddd9: { // 0x0043ddd9: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0043dddb: { // 0x0043dddb: 7409 JZ 0x43dde6
    if(integer::condition("JZ",flags)) goto L0043dde6;
  }
  L0043dddd: { // 0x0043dddd: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0043dddf: { // 0x0043dddf: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0043dde1: { // 0x0043dde1: e85a640000 CALL 0x444240
    s.arithmetic_flags=flags; invoke(m,s,f,0x00444240u,4447718u); flags=s.arithmetic_flags;
  }
  L0043dde6: { // 0x0043dde6: 8b0d881b8200 MOV ECX, dword ptr [0x821b88]
    s.cx = m.r32((0x00821b88u));
  }
  L0043ddec: { // 0x0043ddec: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0043ddee: { // 0x0043ddee: 8b91d8070000 MOV EDX, dword ptr [ECX + 0x7d8]
    s.dx = m.r32((s.cx+0x000007d8u));
  }
  L0043ddf4: { // 0x0043ddf4: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0043ddf6: { // 0x0043ddf6: 7e5e JLE 0x43de56
    if(integer::condition("JLE",flags)) goto L0043de56;
  }
  L0043ddf8: { // 0x0043ddf8: 8bbe18040000 MOV EDI, dword ptr [ESI + 0x418]
    s.di = m.r32((s.si+0x00000418u));
  }
  L0043ddfe: { // 0x0043ddfe: 8b89cc070000 MOV ECX, dword ptr [ECX + 0x7cc]
    s.cx = m.r32((s.cx+0x000007ccu));
  }
  L0043de04: { // 0x0043de04: 3939 CMP dword ptr [ECX], EDI
    (void)integer::sub(m.r32((s.cx)),s.di,32,flags);
  }
  L0043de06: { // 0x0043de06: 740a JZ 0x43de12
    if(integer::condition("JZ",flags)) goto L0043de12;
  }
  L0043de08: { // 0x0043de08: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0043de09: { // 0x0043de09: 83c104 ADD ECX, 4
    s.cx = integer::add(s.cx,4u,32,flags);
  }
  L0043de0c: { // 0x0043de0c: 3bc2 CMP EAX, EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0043de0e: { // 0x0043de0e: 7cf4 JL 0x43de04
    if(integer::condition("JL",flags)) goto L0043de04;
  }
  L0043de10: { // 0x0043de10: eb44 JMP 0x43de56
    goto L0043de56;
  }
  L0043de12: { // 0x0043de12: 8bbeb4010000 MOV EDI, dword ptr [ESI + 0x1b4]
    s.di = m.r32((s.si+0x000001b4u));
  }
  L0043de18: { // 0x0043de18: 83c750 ADD EDI, 0x50
    s.di = integer::add(s.di,0x00000050u,32,flags);
  }
  L0043de1b: { // 0x0043de1b: 8b4f08 MOV ECX, dword ptr [EDI + 8]
    s.cx = m.r32((s.di+8u));
  }
  L0043de1e: { // 0x0043de1e: 8b4710 MOV EAX, dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  L0043de21: { // 0x0043de21: 3bc1 CMP EAX, ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0043de23: { // 0x0043de23: 7c22 JL 0x43de47
    if(integer::condition("JL",flags)) goto L0043de47;
  }
  L0043de25: { // 0x0043de25: 8a470d MOV AL, byte ptr [EDI + 0xd]
    s.ax = with_al(s.ax, m.r8((s.di+0x0000000du)));
  }
  L0043de28: { // 0x0043de28: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0043de2a: { // 0x0043de2a: 7504 JNZ 0x43de30
    if(integer::condition("JNZ",flags)) goto L0043de30;
  }
  L0043de2c: { // 0x0043de2c: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0043de2e: { // 0x0043de2e: 7526 JNZ 0x43de56
    if(integer::condition("JNZ",flags)) goto L0043de56;
  }
  L0043de30: { // 0x0043de30: 8b4714 MOV EAX, dword ptr [EDI + 0x14]
    s.ax = m.r32((s.di+0x00000014u));
  }
  L0043de33: { // 0x0043de33: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0043de35: { // 0x0043de35: 7e1f JLE 0x43de56
    if(integer::condition("JLE",flags)) goto L0043de56;
  }
  L0043de37: { // 0x0043de37: 8b17 MOV EDX, dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L0043de39: { // 0x0043de39: 03c8 ADD ECX, EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0043de3b: { // 0x0043de3b: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0043de3d: { // 0x0043de3d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0043de3e: { // 0x0043de3e: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L0043de40: { // 0x0043de40: ff5208 CALL dword ptr [EDX + 8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+8u)),4447811u); flags=s.arithmetic_flags;
  }
  L0043de43: { // 0x0043de43: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0043de45: { // 0x0043de45: 740f JZ 0x43de56
    if(integer::condition("JZ",flags)) goto L0043de56;
  }
  L0043de47: { // 0x0043de47: 8b4710 MOV EAX, dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  L0043de4a: { // 0x0043de4a: 8b5704 MOV EDX, dword ptr [EDI + 4]
    s.dx = m.r32((s.di+4u));
  }
  L0043de4d: { // 0x0043de4d: 8d4801 LEA ECX, [EAX + 1]
    s.cx = (s.ax+1u);
  }
  L0043de50: { // 0x0043de50: 894f10 MOV dword ptr [EDI + 0x10], ECX
    m.w32((s.di+0x00000010u), s.cx);
  }
  L0043de53: { // 0x0043de53: 893482 MOV dword ptr [EDX + EAX*4], ESI
    m.w32((s.dx+(s.ax * 4u)), s.si);
  }
  L0043de56: { // 0x0043de56: 8b8618040000 MOV EAX, dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L0043de5c: { // 0x0043de5c: 8a8849130000 MOV CL, byte ptr [EAX + 0x1349]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001349u)));
  }
  L0043de62: { // 0x0043de62: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0043de64: { // 0x0043de64: 7447 JZ 0x43dead
    if(integer::condition("JZ",flags)) goto L0043dead;
  }
  L0043de66: { // 0x0043de66: 8bbeb4010000 MOV EDI, dword ptr [ESI + 0x1b4]
    s.di = m.r32((s.si+0x000001b4u));
  }
  L0043de6c: { // 0x0043de6c: 81c780000000 ADD EDI, 0x80
    s.di = integer::add(s.di,0x00000080u,32,flags);
  }
  L0043de72: { // 0x0043de72: 8b4f08 MOV ECX, dword ptr [EDI + 8]
    s.cx = m.r32((s.di+8u));
  }
  L0043de75: { // 0x0043de75: 8b4710 MOV EAX, dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  L0043de78: { // 0x0043de78: 3bc1 CMP EAX, ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0043de7a: { // 0x0043de7a: 7c22 JL 0x43de9e
    if(integer::condition("JL",flags)) goto L0043de9e;
  }
  L0043de7c: { // 0x0043de7c: 8a470d MOV AL, byte ptr [EDI + 0xd]
    s.ax = with_al(s.ax, m.r8((s.di+0x0000000du)));
  }
  L0043de7f: { // 0x0043de7f: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0043de81: { // 0x0043de81: 7504 JNZ 0x43de87
    if(integer::condition("JNZ",flags)) goto L0043de87;
  }
  L0043de83: { // 0x0043de83: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0043de85: { // 0x0043de85: 7526 JNZ 0x43dead
    if(integer::condition("JNZ",flags)) goto L0043dead;
  }
  L0043de87: { // 0x0043de87: 8b4714 MOV EAX, dword ptr [EDI + 0x14]
    s.ax = m.r32((s.di+0x00000014u));
  }
  L0043de8a: { // 0x0043de8a: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0043de8c: { // 0x0043de8c: 7e1f JLE 0x43dead
    if(integer::condition("JLE",flags)) goto L0043dead;
  }
  L0043de8e: { // 0x0043de8e: 8b17 MOV EDX, dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L0043de90: { // 0x0043de90: 03c8 ADD ECX, EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0043de92: { // 0x0043de92: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0043de94: { // 0x0043de94: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0043de95: { // 0x0043de95: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L0043de97: { // 0x0043de97: ff5208 CALL dword ptr [EDX + 8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+8u)),4447898u); flags=s.arithmetic_flags;
  }
  L0043de9a: { // 0x0043de9a: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0043de9c: { // 0x0043de9c: 740f JZ 0x43dead
    if(integer::condition("JZ",flags)) goto L0043dead;
  }
  L0043de9e: { // 0x0043de9e: 8b4710 MOV EAX, dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  L0043dea1: { // 0x0043dea1: 8b5704 MOV EDX, dword ptr [EDI + 4]
    s.dx = m.r32((s.di+4u));
  }
  L0043dea4: { // 0x0043dea4: 8d4801 LEA ECX, [EAX + 1]
    s.cx = (s.ax+1u);
  }
  L0043dea7: { // 0x0043dea7: 894f10 MOV dword ptr [EDI + 0x10], ECX
    m.w32((s.di+0x00000010u), s.cx);
  }
  L0043deaa: { // 0x0043deaa: 893482 MOV dword ptr [EDX + EAX*4], ESI
    m.w32((s.dx+(s.ax * 4u)), s.si);
  }
  L0043dead: { // 0x0043dead: 8b8618040000 MOV EAX, dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L0043deb3: { // 0x0043deb3: 8a884b130000 MOV CL, byte ptr [EAX + 0x134b]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0000134bu)));
  }
  L0043deb9: { // 0x0043deb9: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0043debb: { // 0x0043debb: 7447 JZ 0x43df04
    if(integer::condition("JZ",flags)) goto L0043df04;
  }
  L0043debd: { // 0x0043debd: 8bbeb4010000 MOV EDI, dword ptr [ESI + 0x1b4]
    s.di = m.r32((s.si+0x000001b4u));
  }
  L0043dec3: { // 0x0043dec3: 81c798000000 ADD EDI, 0x98
    s.di = integer::add(s.di,0x00000098u,32,flags);
  }
  L0043dec9: { // 0x0043dec9: 8b4f08 MOV ECX, dword ptr [EDI + 8]
    s.cx = m.r32((s.di+8u));
  }
  L0043decc: { // 0x0043decc: 8b4710 MOV EAX, dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  L0043decf: { // 0x0043decf: 3bc1 CMP EAX, ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0043ded1: { // 0x0043ded1: 7c22 JL 0x43def5
    if(integer::condition("JL",flags)) goto L0043def5;
  }
  L0043ded3: { // 0x0043ded3: 8a470d MOV AL, byte ptr [EDI + 0xd]
    s.ax = with_al(s.ax, m.r8((s.di+0x0000000du)));
  }
  L0043ded6: { // 0x0043ded6: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0043ded8: { // 0x0043ded8: 7504 JNZ 0x43dede
    if(integer::condition("JNZ",flags)) goto L0043dede;
  }
  L0043deda: { // 0x0043deda: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0043dedc: { // 0x0043dedc: 7526 JNZ 0x43df04
    if(integer::condition("JNZ",flags)) goto L0043df04;
  }
  L0043dede: { // 0x0043dede: 8b4714 MOV EAX, dword ptr [EDI + 0x14]
    s.ax = m.r32((s.di+0x00000014u));
  }
  L0043dee1: { // 0x0043dee1: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0043dee3: { // 0x0043dee3: 7e1f JLE 0x43df04
    if(integer::condition("JLE",flags)) goto L0043df04;
  }
  L0043dee5: { // 0x0043dee5: 8b17 MOV EDX, dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L0043dee7: { // 0x0043dee7: 03c8 ADD ECX, EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0043dee9: { // 0x0043dee9: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0043deeb: { // 0x0043deeb: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0043deec: { // 0x0043deec: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L0043deee: { // 0x0043deee: ff5208 CALL dword ptr [EDX + 8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+8u)),4447985u); flags=s.arithmetic_flags;
  }
  L0043def1: { // 0x0043def1: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0043def3: { // 0x0043def3: 740f JZ 0x43df04
    if(integer::condition("JZ",flags)) goto L0043df04;
  }
  L0043def5: { // 0x0043def5: 8b4710 MOV EAX, dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  L0043def8: { // 0x0043def8: 8b5704 MOV EDX, dword ptr [EDI + 4]
    s.dx = m.r32((s.di+4u));
  }
  L0043defb: { // 0x0043defb: 8d4801 LEA ECX, [EAX + 1]
    s.cx = (s.ax+1u);
  }
  L0043defe: { // 0x0043defe: 894f10 MOV dword ptr [EDI + 0x10], ECX
    m.w32((s.di+0x00000010u), s.cx);
  }
  L0043df01: { // 0x0043df01: 893482 MOV dword ptr [EDX + EAX*4], ESI
    m.w32((s.dx+(s.ax * 4u)), s.si);
  }
  L0043df04: { // 0x0043df04: 8b8618040000 MOV EAX, dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L0043df0a: { // 0x0043df0a: 8b8890130000 MOV ECX, dword ptr [EAX + 0x1390]
    s.cx = m.r32((s.ax+0x00001390u));
  }
  L0043df10: { // 0x0043df10: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0043df12: { // 0x0043df12: 7e47 JLE 0x43df5b
    if(integer::condition("JLE",flags)) goto L0043df5b;
  }
  L0043df14: { // 0x0043df14: 8bbeb4010000 MOV EDI, dword ptr [ESI + 0x1b4]
    s.di = m.r32((s.si+0x000001b4u));
  }
  L0043df1a: { // 0x0043df1a: 81c7b0000000 ADD EDI, 0xb0
    s.di = integer::add(s.di,0x000000b0u,32,flags);
  }
  L0043df20: { // 0x0043df20: 8b4f08 MOV ECX, dword ptr [EDI + 8]
    s.cx = m.r32((s.di+8u));
  }
  L0043df23: { // 0x0043df23: 8b4710 MOV EAX, dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  L0043df26: { // 0x0043df26: 3bc1 CMP EAX, ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0043df28: { // 0x0043df28: 7c22 JL 0x43df4c
    if(integer::condition("JL",flags)) goto L0043df4c;
  }
  L0043df2a: { // 0x0043df2a: 8a470d MOV AL, byte ptr [EDI + 0xd]
    s.ax = with_al(s.ax, m.r8((s.di+0x0000000du)));
  }
  L0043df2d: { // 0x0043df2d: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0043df2f: { // 0x0043df2f: 7504 JNZ 0x43df35
    if(integer::condition("JNZ",flags)) goto L0043df35;
  }
  L0043df31: { // 0x0043df31: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0043df33: { // 0x0043df33: 7526 JNZ 0x43df5b
    if(integer::condition("JNZ",flags)) goto L0043df5b;
  }
  L0043df35: { // 0x0043df35: 8b4714 MOV EAX, dword ptr [EDI + 0x14]
    s.ax = m.r32((s.di+0x00000014u));
  }
  L0043df38: { // 0x0043df38: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0043df3a: { // 0x0043df3a: 7e1f JLE 0x43df5b
    if(integer::condition("JLE",flags)) goto L0043df5b;
  }
  L0043df3c: { // 0x0043df3c: 8b17 MOV EDX, dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L0043df3e: { // 0x0043df3e: 03c8 ADD ECX, EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0043df40: { // 0x0043df40: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0043df42: { // 0x0043df42: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0043df43: { // 0x0043df43: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L0043df45: { // 0x0043df45: ff5208 CALL dword ptr [EDX + 8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+8u)),4448072u); flags=s.arithmetic_flags;
  }
  L0043df48: { // 0x0043df48: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0043df4a: { // 0x0043df4a: 740f JZ 0x43df5b
    if(integer::condition("JZ",flags)) goto L0043df5b;
  }
  L0043df4c: { // 0x0043df4c: 8b4710 MOV EAX, dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  L0043df4f: { // 0x0043df4f: 8b5704 MOV EDX, dword ptr [EDI + 4]
    s.dx = m.r32((s.di+4u));
  }
  L0043df52: { // 0x0043df52: 8d4801 LEA ECX, [EAX + 1]
    s.cx = (s.ax+1u);
  }
  L0043df55: { // 0x0043df55: 894f10 MOV dword ptr [EDI + 0x10], ECX
    m.w32((s.di+0x00000010u), s.cx);
  }
  L0043df58: { // 0x0043df58: 893482 MOV dword ptr [EDX + EAX*4], ESI
    m.w32((s.dx+(s.ax * 4u)), s.si);
  }
  L0043df5b: { // 0x0043df5b: 8bbeb4010000 MOV EDI, dword ptr [ESI + 0x1b4]
    s.di = m.r32((s.si+0x000001b4u));
  }
  L0043df61: { // 0x0043df61: 83c768 ADD EDI, 0x68
    s.di = integer::add(s.di,0x00000068u,32,flags);
  }
  L0043df64: { // 0x0043df64: 8b4f08 MOV ECX, dword ptr [EDI + 8]
    s.cx = m.r32((s.di+8u));
  }
  L0043df67: { // 0x0043df67: 8b4710 MOV EAX, dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  L0043df6a: { // 0x0043df6a: 3bc1 CMP EAX, ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0043df6c: { // 0x0043df6c: 7c22 JL 0x43df90
    if(integer::condition("JL",flags)) goto L0043df90;
  }
  L0043df6e: { // 0x0043df6e: 8a470d MOV AL, byte ptr [EDI + 0xd]
    s.ax = with_al(s.ax, m.r8((s.di+0x0000000du)));
  }
  L0043df71: { // 0x0043df71: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0043df73: { // 0x0043df73: 7504 JNZ 0x43df79
    if(integer::condition("JNZ",flags)) goto L0043df79;
  }
  L0043df75: { // 0x0043df75: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0043df77: { // 0x0043df77: 7526 JNZ 0x43df9f
    if(integer::condition("JNZ",flags)) goto L0043df9f;
  }
  L0043df79: { // 0x0043df79: 8b4714 MOV EAX, dword ptr [EDI + 0x14]
    s.ax = m.r32((s.di+0x00000014u));
  }
  L0043df7c: { // 0x0043df7c: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0043df7e: { // 0x0043df7e: 7e1f JLE 0x43df9f
    if(integer::condition("JLE",flags)) goto L0043df9f;
  }
  L0043df80: { // 0x0043df80: 8b17 MOV EDX, dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L0043df82: { // 0x0043df82: 03c8 ADD ECX, EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0043df84: { // 0x0043df84: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0043df86: { // 0x0043df86: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0043df87: { // 0x0043df87: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L0043df89: { // 0x0043df89: ff5208 CALL dword ptr [EDX + 8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+8u)),4448140u); flags=s.arithmetic_flags;
  }
  L0043df8c: { // 0x0043df8c: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0043df8e: { // 0x0043df8e: 740f JZ 0x43df9f
    if(integer::condition("JZ",flags)) goto L0043df9f;
  }
  L0043df90: { // 0x0043df90: 8b4710 MOV EAX, dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  L0043df93: { // 0x0043df93: 8b5704 MOV EDX, dword ptr [EDI + 4]
    s.dx = m.r32((s.di+4u));
  }
  L0043df96: { // 0x0043df96: 8d4801 LEA ECX, [EAX + 1]
    s.cx = (s.ax+1u);
  }
  L0043df99: { // 0x0043df99: 894f10 MOV dword ptr [EDI + 0x10], ECX
    m.w32((s.di+0x00000010u), s.cx);
  }
  L0043df9c: { // 0x0043df9c: 893482 MOV dword ptr [EDX + EAX*4], ESI
    m.w32((s.dx+(s.ax * 4u)), s.si);
  }
  L0043df9f: { // 0x0043df9f: 8b8eb4010000 MOV ECX, dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L0043dfa5: { // 0x0043dfa5: e846680b00 CALL 0x4f47f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f47f0u,4448170u); flags=s.arithmetic_flags;
  }
  L0043dfaa: { // 0x0043dfaa: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0043dfac: { // 0x0043dfac: 7512 JNZ 0x43dfc0
    if(integer::condition("JNZ",flags)) goto L0043dfc0;
  }
  L0043dfae: { // 0x0043dfae: 8b8eb4010000 MOV ECX, dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L0043dfb4: { // 0x0043dfb4: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0043dfb5: { // 0x0043dfb5: 81c1f0550000 ADD ECX, 0x55f0
    s.cx = integer::add(s.cx,0x000055f0u,32,flags);
  }
  L0043dfbb: { // 0x0043dfbb: e810ebfeff CALL 0x42cad0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042cad0u,4448192u); flags=s.arithmetic_flags;
  }
  L0043dfc0: { // 0x0043dfc0: 8b8618040000 MOV EAX, dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L0043dfc6: { // 0x0043dfc6: 8b88440c0000 MOV ECX, dword ptr [EAX + 0xc44]
    s.cx = m.r32((s.ax+0x00000c44u));
  }
  L0043dfcc: { // 0x0043dfcc: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0043dfce: { // 0x0043dfce: 7415 JZ 0x43dfe5
    if(integer::condition("JZ",flags)) goto L0043dfe5;
  }
  L0043dfd0: { // 0x0043dfd0: 8a80da0a0000 MOV AL, byte ptr [EAX + 0xada]
    s.ax = with_al(s.ax, m.r8((s.ax+0x00000adau)));
  }
  L0043dfd6: { // 0x0043dfd6: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0043dfd8: { // 0x0043dfd8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0043dfd9: { // 0x0043dfd9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0043dfda: { // 0x0043dfda: 8b8eb4010000 MOV ECX, dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L0043dfe0: { // 0x0043dfe0: e88b460b00 CALL 0x4f2670
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f2670u,4448229u); flags=s.arithmetic_flags;
  }
  L0043dfe5: { // 0x0043dfe5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0043dfe6: { // 0x0043dfe6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0043dfe7: { // 0x0043dfe7: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0043dfe8: { // 0x0043dfe8: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L0043dfea: { // 0x0043dfea: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0043dfeb: { // 0x0043dfeb: 83c434 ADD ESP, 0x34
    f.sp = integer::add(f.sp,0x00000034u,32,flags);
  }
  L0043dfee: { // 0x0043dfee: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_002b9c70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006b9c70: { // 0x6b9c70: 83ec18 SUB ESP,0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
  L006b9c73: { // 0x6b9c73: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006b9c74: { // 0x6b9c74: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006b9c75: { // 0x6b9c75: 8b7c2424 MOV EDI,dword ptr [ESP + 0x24]
    s.di = m.r32((f.sp+0x00000024u));
  }
  L006b9c79: { // 0x6b9c79: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006b9c7b: { // 0x6b9c7b: 8d4c2424 LEA ECX,[ESP + 0x24]
    s.cx = (f.sp+0x00000024u);
  }
  L006b9c7f: { // 0x6b9c7f: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L006b9c81: { // 0x6b9c81: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L006b9c83: { // 0x6b9c83: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006b9c84: { // 0x6b9c84: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006b9c85: { // 0x6b9c85: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L006b9c8b: { // 0x6b9c8b: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006b9c90: { // 0x6b9c90: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L006b9c92: { // 0x6b9c92: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L006b9c95: { // 0x6b9c95: 668944242c MOV word ptr [ESP + 0x2c],AX
    m.w16((f.sp+0x0000002cu), (s.ax & 0xffffu));
  }
  L006b9c9a: { // 0x6b9c9a: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  L006b9c9d: { // 0x6b9c9d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006b9c9e: { // 0x6b9c9e: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L006b9ca4: { // 0x6b9ca4: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L006b9ca6: { // 0x6b9ca6: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L006b9ca9: { // 0x6b9ca9: 668944242e MOV word ptr [ESP + 0x2e],AX
    m.w16((f.sp+0x0000002eu), (s.ax & 0xffffu));
  }
  L006b9cae: { // 0x6b9cae: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L006b9cb2: { // 0x6b9cb2: 8944242c MOV dword ptr [ESP + 0x2c],EAX
    m.w32((f.sp+0x0000002cu), s.ax);
  }
  L006b9cb6: { // 0x6b9cb6: e895d7e9ff CALL 0x00557450
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557450u,7052475u); flags=s.arithmetic_flags;
  }
  L006b9cbb: { // 0x6b9cbb: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L006b9cbf: { // 0x6b9cbf: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b9cc1: { // 0x6b9cc1: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006b9cc2: { // 0x6b9cc2: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006b9cc3: { // 0x6b9cc3: 88862d030000 MOV byte ptr [ESI + 0x32d],AL
    m.w8((s.si+0x0000032du), (s.ax & 0xffu));
  }
  L006b9cc9: { // 0x6b9cc9: e85222f1ff CALL 0x005cbf20
    s.arithmetic_flags=flags; invoke(m,s,f,0x005cbf20u,7052494u); flags=s.arithmetic_flags;
  }
  L006b9cce: { // 0x6b9cce: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b9cd0: { // 0x6b9cd0: 0f841e020000 JZ 0x006b9ef4
    if(integer::condition("JZ",flags)) goto L006b9ef4;
  }
  L006b9cd6: { // 0x6b9cd6: 8a467d MOV AL,byte ptr [ESI + 0x7d]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000007du)));
  }
  L006b9cd9: { // 0x6b9cd9: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b9cdb: { // 0x6b9cdb: 750a JNZ 0x006b9ce7
    if(integer::condition("JNZ",flags)) goto L006b9ce7;
  }
  L006b9cdd: { // 0x6b9cdd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b9cde: { // 0x6b9cde: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006b9ce0: { // 0x6b9ce0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b9ce1: { // 0x6b9ce1: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L006b9ce4: { // 0x6b9ce4: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L006b9ce7: { // 0x6b9ce7: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006b9ce9: { // 0x6b9ce9: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006b9cea: { // 0x6b9cea: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006b9ceb: { // 0x6b9ceb: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006b9ced: { // 0x6b9ced: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006b9cef: { // 0x6b9cef: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006b9cf1: { // 0x6b9cf1: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006b9cf3: { // 0x6b9cf3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b9cf5: { // 0x6b9cf5: ff9018040000 CALL dword ptr [EAX + 0x418]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000418u)),7052539u); flags=s.arithmetic_flags;
  }
  L006b9cfb: { // 0x6b9cfb: 8d9e88000000 LEA EBX,[ESI + 0x88]
    s.bx = (s.si+0x00000088u);
  }
  L006b9d01: { // 0x6b9d01: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006b9d03: { // 0x6b9d03: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L006b9d05: { // 0x6b9d05: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L006b9d07: { // 0x6b9d07: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L006b9d0b: { // 0x6b9d0b: 8b96f4010000 MOV EDX,dword ptr [ESI + 0x1f4]
    s.dx = m.r32((s.si+0x000001f4u));
  }
  L006b9d11: { // 0x6b9d11: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L006b9d14: { // 0x6b9d14: 83c203 ADD EDX,0x3
    s.dx = integer::add(s.dx,0x00000003u,32,flags);
  }
  L006b9d17: { // 0x6b9d17: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L006b9d1b: { // 0x6b9d1b: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006b9d1c: { // 0x6b9d1c: 8b4908 MOV ECX,dword ptr [ECX + 0x8]
    s.cx = m.r32((s.cx+0x00000008u));
  }
  L006b9d1f: { // 0x6b9d1f: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L006b9d23: { // 0x6b9d23: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L006b9d27: { // 0x6b9d27: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006b9d29: { // 0x6b9d29: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006b9d2a: { // 0x6b9d2a: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006b9d2f: { // 0x6b9d2f: e8acdce8ff CALL 0x005479e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005479e0u,7052596u); flags=s.arithmetic_flags;
  }
  L006b9d34: { // 0x6b9d34: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L006b9d3a: { // 0x6b9d3a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006b9d3c: { // 0x6b9d3c: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006b9d3d: { // 0x6b9d3d: e8ce2de3ff CALL 0x004ecb10
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ecb10u,7052610u); flags=s.arithmetic_flags;
  }
  L006b9d42: { // 0x6b9d42: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L006b9d44: { // 0x6b9d44: 8d542430 LEA EDX,[ESP + 0x30]
    s.dx = (f.sp+0x00000030u);
  }
  L006b9d48: { // 0x6b9d48: 8a6c2430 MOV CH,byte ptr [ESP + 0x30]
    s.cx = (s.cx & 0xffff00ffu) | (((m.r8((f.sp+0x00000030u))) & 0xffu) << 8);
  }
  L006b9d4c: { // 0x6b9d4c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006b9d4d: { // 0x6b9d4d: 66894c2434 MOV word ptr [ESP + 0x34],CX
    m.w16((f.sp+0x00000034u), (s.cx & 0xffffu));
  }
  L006b9d52: { // 0x6b9d52: 8d8ee0020000 LEA ECX,[ESI + 0x2e0]
    s.cx = (s.si+0x000002e0u);
  }
  L006b9d58: { // 0x6b9d58: e823eadfff CALL 0x004b8780
    s.arithmetic_flags=flags; invoke(m,s,f,0x004b8780u,7052637u); flags=s.arithmetic_flags;
  }
  L006b9d5d: { // 0x6b9d5d: 8daec8020000 LEA EBP,[ESI + 0x2c8]
    s.bp = (s.si+0x000002c8u);
  }
  L006b9d63: { // 0x6b9d63: 8d442430 LEA EAX,[ESP + 0x30]
    s.ax = (f.sp+0x00000030u);
  }
  L006b9d67: { // 0x6b9d67: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006b9d68: { // 0x6b9d68: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L006b9d6a: { // 0x6b9d6a: 66c74424340040 MOV word ptr [ESP + 0x34],0x4000
    m.w16((f.sp+0x00000034u), 0x00004000u);
  }
  L006b9d71: { // 0x6b9d71: e80aeadfff CALL 0x004b8780
    s.arithmetic_flags=flags; invoke(m,s,f,0x004b8780u,7052662u); flags=s.arithmetic_flags;
  }
  L006b9d76: { // 0x6b9d76: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b9d78: { // 0x6b9d78: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b9d7a: { // 0x6b9d7a: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7052672u); flags=s.arithmetic_flags;
  }
  L006b9d80: { // 0x6b9d80: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L006b9d82: { // 0x6b9d82: ba00400000 MOV EDX,0x4000
    s.dx = 0x00004000u;
  }
  L006b9d87: { // 0x6b9d87: 8aa8a0030000 MOV CH,byte ptr [EAX + 0x3a0]
    s.cx = (s.cx & 0xffff00ffu) | (((m.r8((s.ax+0x000003a0u))) & 0xffu) << 8);
  }
  L006b9d8d: { // 0x6b9d8d: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L006b9d8f: { // 0x6b9d8f: 8d4c2430 LEA ECX,[ESP + 0x30]
    s.cx = (f.sp+0x00000030u);
  }
  L006b9d93: { // 0x6b9d93: 6689542430 MOV word ptr [ESP + 0x30],DX
    m.w16((f.sp+0x00000030u), (s.dx & 0xffffu));
  }
  L006b9d98: { // 0x6b9d98: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L006b9d9c: { // 0x6b9d9c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006b9d9d: { // 0x6b9d9d: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L006b9d9f: { // 0x6b9d9f: 89442434 MOV dword ptr [ESP + 0x34],EAX
    m.w32((f.sp+0x00000034u), s.ax);
  }
  L006b9da3: { // 0x6b9da3: e8f8e8dfff CALL 0x004b86a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004b86a0u,7052712u); flags=s.arithmetic_flags;
  }
  L006b9da8: { // 0x6b9da8: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b9daa: { // 0x6b9daa: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b9dac: { // 0x6b9dac: c786ec03000001000000 MOV dword ptr [ESI + 0x3ec],0x1
    m.w32((s.si+0x000003ecu), 0x00000001u);
  }
  L006b9db6: { // 0x6b9db6: c786f003000000000000 MOV dword ptr [ESI + 0x3f0],0x0
    m.w32((s.si+0x000003f0u), 0x00000000u);
  }
  L006b9dc0: { // 0x6b9dc0: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),7052739u); flags=s.arithmetic_flags;
  }
  L006b9dc3: { // 0x6b9dc3: 83f80f CMP EAX,0xf
    (void)integer::sub(s.ax,0x0000000fu,32,flags);
  }
  L006b9dc6: { // 0x6b9dc6: 7507 JNZ 0x006b9dcf
    if(integer::condition("JNZ",flags)) goto L006b9dcf;
  }
  L006b9dc8: { // 0x6b9dc8: c6869001000001 MOV byte ptr [ESI + 0x190],0x1
    m.w8((s.si+0x00000190u), 0x00000001u);
  }
  L006b9dcf: { // 0x6b9dcf: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006b9dd1: { // 0x6b9dd1: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L006b9dd3: { // 0x6b9dd3: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L006b9dd5: { // 0x6b9dd5: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b9dd7: { // 0x6b9dd7: ff9014040000 CALL dword ptr [EAX + 0x414]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000414u)),7052765u); flags=s.arithmetic_flags;
  }
  L006b9ddd: { // 0x6b9ddd: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b9ddf: { // 0x6b9ddf: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b9de1: { // 0x6b9de1: c6869001000000 MOV byte ptr [ESI + 0x190],0x0
    m.w8((s.si+0x00000190u), 0x00000000u);
  }
  L006b9de8: { // 0x6b9de8: ff92e8010000 CALL dword ptr [EDX + 0x1e8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001e8u)),7052782u); flags=s.arithmetic_flags;
  }
  L006b9dee: { // 0x6b9dee: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b9df0: { // 0x6b9df0: 740a JZ 0x006b9dfc
    if(integer::condition("JZ",flags)) goto L006b9dfc;
  }
  L006b9df2: { // 0x6b9df2: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006b9df4: { // 0x6b9df4: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b9df6: { // 0x6b9df6: ff90d4010000 CALL dword ptr [EAX + 0x1d4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000001d4u)),7052796u); flags=s.arithmetic_flags;
  }
  L006b9dfc: { // 0x6b9dfc: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  L006b9dff: { // 0x6b9dff: 8b0d881b8200 MOV ECX,dword ptr [0x00821b88]
    s.cx = m.r32((0x00821b88u));
  }
  L006b9e05: { // 0x6b9e05: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006b9e06: { // 0x6b9e06: f7b924130000 IDIV dword ptr [ECX + 0x1324]
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(m.r32((s.cx+0x00001324u)),32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L006b9e0c: { // 0x6b9e0c: b20a MOV DL,0xa
    s.dx = with_al(s.dx, 0x0000000au);
  }
  L006b9e0e: { // 0x6b9e0e: 8d4c2430 LEA ECX,[ESP + 0x30]
    s.cx = (f.sp+0x00000030u);
  }
  L006b9e12: { // 0x6b9e12: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L006b9e14: { // 0x6b9e14: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006b9e15: { // 0x6b9e15: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006b9e1a: { // 0x6b9e1a: f6ea IMUL DL
    const auto product=integer::sign_extend(s.ax,8)*integer::sign_extend((s.dx & 0xffu),8);
    s.ax=with_ax(s.ax,std::uint32_t(product));
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,8)?integer::CF|integer::OF:0);
  }
  L006b9e1c: { // 0x6b9e1c: 888678030000 MOV byte ptr [ESI + 0x378],AL
    m.w8((s.si+0x00000378u), (s.ax & 0xffu));
  }
  L006b9e22: { // 0x6b9e22: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L006b9e24: { // 0x6b9e24: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006b9e25: { // 0x6b9e25: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L006b9e2b: { // 0x6b9e2b: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L006b9e2d: { // 0x6b9e2d: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L006b9e30: { // 0x6b9e30: 6689442438 MOV word ptr [ESP + 0x38],AX
    m.w16((f.sp+0x00000038u), (s.ax & 0xffffu));
  }
  L006b9e35: { // 0x6b9e35: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  L006b9e38: { // 0x6b9e38: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006b9e39: { // 0x6b9e39: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L006b9e3f: { // 0x6b9e3f: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L006b9e41: { // 0x6b9e41: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L006b9e44: { // 0x6b9e44: 668944243a MOV word ptr [ESP + 0x3a],AX
    m.w16((f.sp+0x0000003au), (s.ax & 0xffffu));
  }
  L006b9e49: { // 0x6b9e49: 8b442438 MOV EAX,dword ptr [ESP + 0x38]
    s.ax = m.r32((f.sp+0x00000038u));
  }
  L006b9e4d: { // 0x6b9e4d: 89442438 MOV dword ptr [ESP + 0x38],EAX
    m.w32((f.sp+0x00000038u), s.ax);
  }
  L006b9e51: { // 0x6b9e51: e8fad5e9ff CALL 0x00557450
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557450u,7052886u); flags=s.arithmetic_flags;
  }
  L006b9e56: { // 0x6b9e56: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b9e58: { // 0x6b9e58: 7506 JNZ 0x006b9e60
    if(integer::condition("JNZ",flags)) goto L006b9e60;
  }
  L006b9e5a: { // 0x6b9e5a: 888673030000 MOV byte ptr [ESI + 0x373],AL
    m.w8((s.si+0x00000373u), (s.ax & 0xffu));
  }
  L006b9e60: { // 0x6b9e60: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b9e62: { // 0x6b9e62: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b9e64: { // 0x6b9e64: ff92a4010000 CALL dword ptr [EDX + 0x1a4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001a4u)),7052906u); flags=s.arithmetic_flags;
  }
  L006b9e6a: { // 0x6b9e6a: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L006b9e6c: { // 0x6b9e6c: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L006b9e6e: { // 0x6b9e6e: 7420 JZ 0x006b9e90
    if(integer::condition("JZ",flags)) goto L006b9e90;
  }
  L006b9e70: { // 0x6b9e70: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006b9e72: { // 0x6b9e72: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b9e74: { // 0x6b9e74: ff90a0020000 CALL dword ptr [EAX + 0x2a0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000002a0u)),7052922u); flags=s.arithmetic_flags;
  }
  L006b9e7a: { // 0x6b9e7a: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b9e7c: { // 0x6b9e7c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006b9e7d: { // 0x6b9e7d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b9e7f: { // 0x6b9e7f: 898600040000 MOV dword ptr [ESI + 0x400],EAX
    m.w32((s.si+0x00000400u), s.ax);
  }
  L006b9e85: { // 0x6b9e85: ff5238 CALL dword ptr [EDX + 0x38]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000038u)),7052936u); flags=s.arithmetic_flags;
  }
  L006b9e88: { // 0x6b9e88: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006b9e89: { // 0x6b9e89: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006b9e8b: { // 0x6b9e8b: e890c8dbff CALL 0x00476720
    s.arithmetic_flags=flags; invoke(m,s,f,0x00476720u,7052944u); flags=s.arithmetic_flags;
  }
  L006b9e90: { // 0x6b9e90: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L006b9e92: { // 0x6b9e92: 8b4b04 MOV ECX,dword ptr [EBX + 0x4]
    s.cx = m.r32((s.bx+0x00000004u));
  }
  L006b9e95: { // 0x6b9e95: 8b5308 MOV EDX,dword ptr [EBX + 0x8]
    s.dx = m.r32((s.bx+0x00000008u));
  }
  L006b9e98: { // 0x6b9e98: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L006b9e9c: { // 0x6b9e9c: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L006b9ea0: { // 0x6b9ea0: 8d44241c LEA EAX,[ESP + 0x1c]
    s.ax = (f.sp+0x0000001cu);
  }
  L006b9ea4: { // 0x6b9ea4: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L006b9ea6: { // 0x6b9ea6: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L006b9eaa: { // 0x6b9eaa: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006b9eab: { // 0x6b9eab: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006b9eac: { // 0x6b9eac: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006b9eb1: { // 0x6b9eb1: 89542430 MOV dword ptr [ESP + 0x30],EDX
    m.w32((f.sp+0x00000030u), s.dx);
  }
  L006b9eb5: { // 0x6b9eb5: e866f3f6ff CALL 0x00629220
    s.arithmetic_flags=flags; invoke(m,s,f,0x00629220u,7052986u); flags=s.arithmetic_flags;
  }
  L006b9eba: { // 0x6b9eba: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L006b9ebc: { // 0x6b9ebc: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006b9ebd: { // 0x6b9ebd: 8996a0010000 MOV dword ptr [ESI + 0x1a0],EDX
    m.w32((s.si+0x000001a0u), s.dx);
  }
  L006b9ec3: { // 0x6b9ec3: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006b9ec4: { // 0x6b9ec4: 8b4004 MOV EAX,dword ptr [EAX + 0x4]
    s.ax = m.r32((s.ax+0x00000004u));
  }
  L006b9ec7: { // 0x6b9ec7: 8986a4010000 MOV dword ptr [ESI + 0x1a4],EAX
    m.w32((s.si+0x000001a4u), s.ax);
  }
  L006b9ecd: { // 0x6b9ecd: 8b8614010000 MOV EAX,dword ptr [ESI + 0x114]
    s.ax = m.r32((s.si+0x00000114u));
  }
  L006b9ed3: { // 0x6b9ed3: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L006b9ed6: { // 0x6b9ed6: 7512 JNZ 0x006b9eea
    if(integer::condition("JNZ",flags)) goto L006b9eea;
  }
  L006b9ed8: { // 0x6b9ed8: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L006b9ede: { // 0x6b9ede: 8b9130010000 MOV EDX,dword ptr [ECX + 0x130]
    s.dx = m.r32((s.cx+0x00000130u));
  }
  L006b9ee4: { // 0x6b9ee4: 899614010000 MOV dword ptr [ESI + 0x114],EDX
    m.w32((s.si+0x00000114u), s.dx);
  }
  L006b9eea: { // 0x6b9eea: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b9eeb: { // 0x6b9eeb: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006b9eed: { // 0x6b9eed: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b9eee: { // 0x6b9eee: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L006b9ef1: { // 0x6b9ef1: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L006b9ef4: { // 0x6b9ef4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b9ef5: { // 0x6b9ef5: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006b9ef7: { // 0x6b9ef7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b9ef8: { // 0x6b9ef8: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L006b9efb: { // 0x6b9efb: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_001cbf20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005cbf20: { // 0x5cbf20: a0a885a200 MOV AL,[0x00a285a8]
    s.ax = with_al(s.ax, m.r8((0x00a285a8u)));
  }
  L005cbf25: { // 0x5cbf25: 83ec2c SUB ESP,0x2c
    f.sp = integer::sub(f.sp,0x0000002cu,32,flags);
  }
  L005cbf28: { // 0x5cbf28: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cbf2a: { // 0x5cbf2a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005cbf2b: { // 0x5cbf2b: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005cbf2c: { // 0x5cbf2c: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005cbf2d: { // 0x5cbf2d: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005cbf2e: { // 0x5cbf2e: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L005cbf30: { // 0x5cbf30: 0f8416030000 JZ 0x005cc24c
    if(integer::condition("JZ",flags)) goto L005cc24c;
  }
  L005cbf36: { // 0x5cbf36: 8a4676 MOV AL,byte ptr [ESI + 0x76]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000076u)));
  }
  L005cbf39: { // 0x5cbf39: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cbf3b: { // 0x5cbf3b: 0f840b030000 JZ 0x005cc24c
    if(integer::condition("JZ",flags)) goto L005cc24c;
  }
  L005cbf41: { // 0x5cbf41: 8a4674 MOV AL,byte ptr [ESI + 0x74]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000074u)));
  }
  L005cbf44: { // 0x5cbf44: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cbf46: { // 0x5cbf46: 0f8500030000 JNZ 0x005cc24c
    if(integer::condition("JNZ",flags)) goto L005cc24c;
  }
  L005cbf4c: { // 0x5cbf4c: a1c483a200 MOV EAX,[0x00a283c4]
    s.ax = m.r32((0x00a283c4u));
  }
  L005cbf51: { // 0x5cbf51: 8b7c2440 MOV EDI,dword ptr [ESP + 0x40]
    s.di = m.r32((f.sp+0x00000040u));
  }
  L005cbf55: { // 0x5cbf55: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005cbf57: { // 0x5cbf57: 7526 JNZ 0x005cbf7f
    if(integer::condition("JNZ",flags)) goto L005cbf7f;
  }
  L005cbf59: { // 0x5cbf59: 8b1e MOV EBX,dword ptr [ESI]
    s.bx = m.r32((s.si));
  }
  L005cbf5b: { // 0x5cbf5b: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L005cbf5d: { // 0x5cbf5d: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L005cbf5f: { // 0x5cbf5f: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L005cbf61: { // 0x5cbf61: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L005cbf63: { // 0x5cbf63: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005cbf64: { // 0x5cbf64: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L005cbf69: { // 0x5cbf69: e82295f7ff CALL 0x00545490
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545490u,6078318u); flags=s.arithmetic_flags;
  }
  L005cbf6e: { // 0x5cbf6e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005cbf6f: { // 0x5cbf6f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cbf71: { // 0x5cbf71: ff9394010000 CALL dword ptr [EBX + 0x194]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bx+0x00000194u)),6078327u); flags=s.arithmetic_flags;
  }
  L005cbf77: { // 0x5cbf77: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005cbf79: { // 0x5cbf79: 0f85cd020000 JNZ 0x005cc24c
    if(integer::condition("JNZ",flags)) goto L005cc24c;
  }
  L005cbf7f: { // 0x5cbf7f: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005cbf81: { // 0x5cbf81: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cbf83: { // 0x5cbf83: c6467600 MOV byte ptr [ESI + 0x76],0x0
    m.w8((s.si+0x00000076u), 0x00000000u);
  }
  L005cbf87: { // 0x5cbf87: c6467500 MOV byte ptr [ESI + 0x75],0x0
    m.w8((s.si+0x00000075u), 0x00000000u);
  }
  L005cbf8b: { // 0x5cbf8b: ff9084000000 CALL dword ptr [EAX + 0x84]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000084u)),6078353u); flags=s.arithmetic_flags;
  }
  L005cbf91: { // 0x5cbf91: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005cbf93: { // 0x5cbf93: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L005cbf95: { // 0x5cbf95: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L005cbf97: { // 0x5cbf97: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L005cbf99: { // 0x5cbf99: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L005cbf9d: { // 0x5cbf9d: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L005cbfa0: { // 0x5cbfa0: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L005cbfa4: { // 0x5cbfa4: 8b4908 MOV ECX,dword ptr [ECX + 0x8]
    s.cx = m.r32((s.cx+0x00000008u));
  }
  L005cbfa7: { // 0x5cbfa7: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L005cbfab: { // 0x5cbfab: 7421 JZ 0x005cbfce
    if(integer::condition("JZ",flags)) goto L005cbfce;
  }
  L005cbfad: { // 0x5cbfad: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L005cbfaf: { // 0x5cbfaf: 8d442424 LEA EAX,[ESP + 0x24]
    s.ax = (f.sp+0x00000024u);
  }
  L005cbfb3: { // 0x5cbfb3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005cbfb4: { // 0x5cbfb4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005cbfb5: { // 0x5cbfb5: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L005cbfb7: { // 0x5cbfb7: ff526c CALL dword ptr [EDX + 0x6c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000006cu)),6078394u); flags=s.arithmetic_flags;
  }
  L005cbfba: { // 0x5cbfba: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L005cbfbc: { // 0x5cbfbc: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L005cbfc0: { // 0x5cbfc0: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L005cbfc3: { // 0x5cbfc3: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L005cbfc7: { // 0x5cbfc7: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L005cbfca: { // 0x5cbfca: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L005cbfce: { // 0x5cbfce: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005cbfd0: { // 0x5cbfd0: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L005cbfd4: { // 0x5cbfd4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005cbfd5: { // 0x5cbfd5: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cbfd7: { // 0x5cbfd7: ff929c010000 CALL dword ptr [EDX + 0x19c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000019cu)),6078429u); flags=s.arithmetic_flags;
  }
  L005cbfdd: { // 0x5cbfdd: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005cbfdf: { // 0x5cbfdf: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L005cbfe1: { // 0x5cbfe1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cbfe3: { // 0x5cbfe3: ff921c010000 CALL dword ptr [EDX + 0x11c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000011cu)),6078441u); flags=s.arithmetic_flags;
  }
  L005cbfe9: { // 0x5cbfe9: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cbfeb: { // 0x5cbfeb: 0f8457020000 JZ 0x005cc248
    if(integer::condition("JZ",flags)) goto L005cc248;
  }
  L005cbff1: { // 0x5cbff1: 8a467d MOV AL,byte ptr [ESI + 0x7d]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000007du)));
  }
  L005cbff4: { // 0x5cbff4: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cbff6: { // 0x5cbff6: 0f8440020000 JZ 0x005cc23c
    if(integer::condition("JZ",flags)) goto L005cc23c;
  }
  L005cbffc: { // 0x5cbffc: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005cbffe: { // 0x5cbffe: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cc000: { // 0x5cc000: ff5074 CALL dword ptr [EAX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000074u)),6078467u); flags=s.arithmetic_flags;
  }
  L005cc003: { // 0x5cc003: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L005cc006: { // 0x5cc006: 740b JZ 0x005cc013
    if(integer::condition("JZ",flags)) goto L005cc013;
  }
  L005cc008: { // 0x5cc008: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005cc009: { // 0x5cc009: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L005cc00e: { // 0x5cc00e: e80dd8ecff CALL 0x00499820
    s.arithmetic_flags=flags; invoke(m,s,f,0x00499820u,6078483u); flags=s.arithmetic_flags;
  }
  L005cc013: { // 0x5cc013: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L005cc015: { // 0x5cc015: 0f845c010000 JZ 0x005cc177
    if(integer::condition("JZ",flags)) goto L005cc177;
  }
  L005cc01b: { // 0x5cc01b: 8a8304020000 MOV AL,byte ptr [EBX + 0x204]
    s.ax = with_al(s.ax, m.r8((s.bx+0x00000204u)));
  }
  L005cc021: { // 0x5cc021: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cc023: { // 0x5cc023: 744c JZ 0x005cc071
    if(integer::condition("JZ",flags)) goto L005cc071;
  }
  L005cc025: { // 0x5cc025: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005cc027: { // 0x5cc027: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cc029: { // 0x5cc029: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),6078508u); flags=s.arithmetic_flags;
  }
  L005cc02c: { // 0x5cc02c: 83f824 CMP EAX,0x24
    (void)integer::sub(s.ax,0x00000024u,32,flags);
  }
  L005cc02f: { // 0x5cc02f: 7516 JNZ 0x005cc047
    if(integer::condition("JNZ",flags)) goto L005cc047;
  }
  L005cc031: { // 0x5cc031: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005cc033: { // 0x5cc033: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cc035: { // 0x5cc035: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),6078520u); flags=s.arithmetic_flags;
  }
  L005cc038: { // 0x5cc038: 83f824 CMP EAX,0x24
    (void)integer::sub(s.ax,0x00000024u,32,flags);
  }
  L005cc03b: { // 0x5cc03b: 7534 JNZ 0x005cc071
    if(integer::condition("JNZ",flags)) goto L005cc071;
  }
  L005cc03d: { // 0x5cc03d: 8a8381020000 MOV AL,byte ptr [EBX + 0x281]
    s.ax = with_al(s.ax, m.r8((s.bx+0x00000281u)));
  }
  L005cc043: { // 0x5cc043: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cc045: { // 0x5cc045: 742a JZ 0x005cc071
    if(integer::condition("JZ",flags)) goto L005cc071;
  }
  L005cc047: { // 0x5cc047: a1c855a200 MOV EAX,[0x00a255c8]
    s.ax = m.r32((0x00a255c8u));
  }
  L005cc04c: { // 0x5cc04c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005cc04e: { // 0x5cc04e: 7414 JZ 0x005cc064
    if(integer::condition("JZ",flags)) goto L005cc064;
  }
  L005cc050: { // 0x5cc050: 83f805 CMP EAX,0x5
    (void)integer::sub(s.ax,0x00000005u,32,flags);
  }
  L005cc053: { // 0x5cc053: 740f JZ 0x005cc064
    if(integer::condition("JZ",flags)) goto L005cc064;
  }
  L005cc055: { // 0x5cc055: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  L005cc058: { // 0x5cc058: 8d4604 LEA EAX,[ESI + 0x4]
    s.ax = (s.si+0x00000004u);
  }
  L005cc05b: { // 0x5cc05b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005cc05c: { // 0x5cc05c: ff5110 CALL dword ptr [ECX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+0x00000010u)),6078559u); flags=s.arithmetic_flags;
  }
  L005cc05f: { // 0x5cc05f: 83f8fe CMP EAX,-0x2
    (void)integer::sub(s.ax,0xfffffffeu,32,flags);
  }
  L005cc062: { // 0x5cc062: 740d JZ 0x005cc071
    if(integer::condition("JZ",flags)) goto L005cc071;
  }
  L005cc064: { // 0x5cc064: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L005cc066: { // 0x5cc066: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005cc067: { // 0x5cc067: b9b0a78100 MOV ECX,0x81a7b0
    s.cx = 0x0081a7b0u;
  }
  L005cc06c: { // 0x5cc06c: e89f04f7ff CALL 0x0053c510
    s.arithmetic_flags=flags; invoke(m,s,f,0x0053c510u,6078577u); flags=s.arithmetic_flags;
  }
  L005cc071: { // 0x5cc071: 8b83ac000000 MOV EAX,dword ptr [EBX + 0xac]
    s.ax = m.r32((s.bx+0x000000acu));
  }
  L005cc077: { // 0x5cc077: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005cc079: { // 0x5cc079: 0f84f8000000 JZ 0x005cc177
    if(integer::condition("JZ",flags)) goto L005cc177;
  }
  L005cc07f: { // 0x5cc07f: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005cc081: { // 0x5cc081: 8d442430 LEA EAX,[ESP + 0x30]
    s.ax = (f.sp+0x00000030u);
  }
  L005cc085: { // 0x5cc085: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005cc086: { // 0x5cc086: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cc088: { // 0x5cc088: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),6078603u); flags=s.arithmetic_flags;
  }
  L005cc08b: { // 0x5cc08b: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L005cc08d: { // 0x5cc08d: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L005cc091: { // 0x5cc091: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L005cc095: { // 0x5cc095: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L005cc098: { // 0x5cc098: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005cc099: { // 0x5cc099: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L005cc09f: { // 0x5cc09f: 8954242c MOV dword ptr [ESP + 0x2c],EDX
    m.w32((f.sp+0x0000002cu), s.dx);
  }
  L005cc0a3: { // 0x5cc0a3: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L005cc0a6: { // 0x5cc0a6: 8d542428 LEA EDX,[ESP + 0x28]
    s.dx = (f.sp+0x00000028u);
  }
  L005cc0aa: { // 0x5cc0aa: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005cc0ab: { // 0x5cc0ab: 89442434 MOV dword ptr [ESP + 0x34],EAX
    m.w32((f.sp+0x00000034u), s.ax);
  }
  L005cc0af: { // 0x5cc0af: e85cbf0c00 CALL 0x00698010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00698010u,6078644u); flags=s.arithmetic_flags;
  }
  L005cc0b4: { // 0x5cc0b4: a1ac1c8200 MOV EAX,[0x00821cac]
    s.ax = m.r32((0x00821cacu));
  }
  L005cc0b9: { // 0x5cc0b9: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L005cc0bd: { // 0x5cc0bd: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L005cc0c1: { // 0x5cc0c1: 8b88b0000000 MOV ECX,dword ptr [EAX + 0xb0]
    s.cx = m.r32((s.ax+0x000000b0u));
  }
  L005cc0c7: { // 0x5cc0c7: 8b80b4000000 MOV EAX,dword ptr [EAX + 0xb4]
    s.ax = m.r32((s.ax+0x000000b4u));
  }
  L005cc0cd: { // 0x5cc0cd: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L005cc0cf: { // 0x5cc0cf: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005cc0d1: { // 0x5cc0d1: 03f9 ADD EDI,ECX
    s.di = integer::add(s.di,s.cx,32,flags);
  }
  L005cc0d3: { // 0x5cc0d3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cc0d5: { // 0x5cc0d5: 897c2410 MOV dword ptr [ESP + 0x10],EDI
    m.w32((f.sp+0x00000010u), s.di);
  }
  L005cc0d9: { // 0x5cc0d9: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L005cc0dd: { // 0x5cc0dd: ff9084000000 CALL dword ptr [EAX + 0x84]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000084u)),6078691u); flags=s.arithmetic_flags;
  }
  L005cc0e3: { // 0x5cc0e3: 8bb8ac000000 MOV EDI,dword ptr [EAX + 0xac]
    s.di = m.r32((s.ax+0x000000acu));
  }
  L005cc0e9: { // 0x5cc0e9: 8b6c2414 MOV EBP,dword ptr [ESP + 0x14]
    s.bp = m.r32((f.sp+0x00000014u));
  }
  L005cc0ed: { // 0x5cc0ed: 6a40 PUSH 0x40
    f.push(m,0x00000040u);
  }
  L005cc0ef: { // 0x5cc0ef: 0fbf4702 MOVSX EAX,word ptr [EDI + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L005cc0f3: { // 0x5cc0f3: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L005cc0f4: { // 0x5cc0f4: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L005cc0f6: { // 0x5cc0f6: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L005cc0f8: { // 0x5cc0f8: 0fbf4704 MOVSX EAX,word ptr [EDI + 0x4]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000004u)),16));
  }
  L005cc0fc: { // 0x5cc0fc: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L005cc0fd: { // 0x5cc0fd: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L005cc0ff: { // 0x5cc0ff: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L005cc103: { // 0x5cc103: d1f9 SAR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L005cc105: { // 0x5cc105: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L005cc107: { // 0x5cc107: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L005cc109: { // 0x5cc109: 2be8 SUB EBP,EAX
    s.bp = integer::sub(s.bp,s.ax,32,flags);
  }
  L005cc10b: { // 0x5cc10b: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L005cc10f: { // 0x5cc10f: 896c2418 MOV dword ptr [ESP + 0x18],EBP
    m.w32((f.sp+0x00000018u), s.bp);
  }
  L005cc113: { // 0x5cc113: e83f181a00 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,6078744u); flags=s.arithmetic_flags;
  }
  L005cc118: { // 0x5cc118: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L005cc11b: { // 0x5cc11b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005cc11d: { // 0x5cc11d: 7412 JZ 0x005cc131
    if(integer::condition("JZ",flags)) goto L005cc131;
  }
  L005cc11f: { // 0x5cc11f: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L005cc123: { // 0x5cc123: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L005cc127: { // 0x5cc127: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005cc128: { // 0x5cc128: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005cc129: { // 0x5cc129: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005cc12a: { // 0x5cc12a: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L005cc12c: { // 0x5cc12c: e8af2ae5ff CALL 0x0041ebe0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041ebe0u,6078769u); flags=s.arithmetic_flags;
  }
  L005cc131: { // 0x5cc131: a1c483a200 MOV EAX,[0x00a283c4]
    s.ax = m.r32((0x00a283c4u));
  }
  L005cc136: { // 0x5cc136: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005cc138: { // 0x5cc138: 753d JNZ 0x005cc177
    if(integer::condition("JNZ",flags)) goto L005cc177;
  }
  L005cc13a: { // 0x5cc13a: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L005cc140: { // 0x5cc140: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L005cc144: { // 0x5cc144: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L005cc146: { // 0x5cc146: 8b91b0000000 MOV EDX,dword ptr [ECX + 0xb0]
    s.dx = m.r32((s.cx+0x000000b0u));
  }
  L005cc14c: { // 0x5cc14c: 8ba9b4000000 MOV EBP,dword ptr [ECX + 0xb4]
    s.bp = m.r32((s.cx+0x000000b4u));
  }
  L005cc152: { // 0x5cc152: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L005cc155: { // 0x5cc155: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L005cc157: { // 0x5cc157: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L005cc15b: { // 0x5cc15b: 8bdc MOV EBX,ESP
    s.bx = f.sp;
  }
  L005cc15d: { // 0x5cc15d: 2bd5 SUB EDX,EBP
    s.dx = integer::sub(s.dx,s.bp,32,flags);
  }
  L005cc15f: { // 0x5cc15f: 0fbf6f02 MOVSX EBP,word ptr [EDI + 0x2]
    s.bp = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L005cc163: { // 0x5cc163: 0fbf7f04 MOVSX EDI,word ptr [EDI + 0x4]
    s.di = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000004u)),16));
  }
  L005cc167: { // 0x5cc167: 8903 MOV dword ptr [EBX],EAX
    m.w32((s.bx), s.ax);
  }
  L005cc169: { // 0x5cc169: 895304 MOV dword ptr [EBX + 0x4],EDX
    m.w32((s.bx+0x00000004u), s.dx);
  }
  L005cc16c: { // 0x5cc16c: 896b08 MOV dword ptr [EBX + 0x8],EBP
    m.w32((s.bx+0x00000008u), s.bp);
  }
  L005cc16f: { // 0x5cc16f: 897b0c MOV dword ptr [EBX + 0xc],EDI
    m.w32((s.bx+0x0000000cu), s.di);
  }
  L005cc172: { // 0x5cc172: e8e9c40c00 CALL 0x00698660
    s.arithmetic_flags=flags; invoke(m,s,f,0x00698660u,6078839u); flags=s.arithmetic_flags;
  }
  L005cc177: { // 0x5cc177: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005cc179: { // 0x5cc179: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cc17b: { // 0x5cc17b: ff9084000000 CALL dword ptr [EAX + 0x84]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000084u)),6078849u); flags=s.arithmetic_flags;
  }
  L005cc181: { // 0x5cc181: 8a880a020000 MOV CL,byte ptr [EAX + 0x20a]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0000020au)));
  }
  L005cc187: { // 0x5cc187: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L005cc189: { // 0x5cc189: 0f84ad000000 JZ 0x005cc23c
    if(integer::condition("JZ",flags)) goto L005cc23c;
  }
  L005cc18f: { // 0x5cc18f: 6810020000 PUSH 0x210
    f.push(m,0x00000210u);
  }
  L005cc194: { // 0x5cc194: e8be171a00 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,6078873u); flags=s.arithmetic_flags;
  }
  L005cc199: { // 0x5cc199: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L005cc19c: { // 0x5cc19c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005cc19e: { // 0x5cc19e: 7409 JZ 0x005cc1a9
    if(integer::condition("JZ",flags)) goto L005cc1a9;
  }
  L005cc1a0: { // 0x5cc1a0: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L005cc1a2: { // 0x5cc1a2: e819b4f6ff CALL 0x005375c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005375c0u,6078887u); flags=s.arithmetic_flags;
  }
  L005cc1a7: { // 0x5cc1a7: eb02 JMP 0x005cc1ab
    goto L005cc1ab;
  }
  L005cc1a9: { // 0x5cc1a9: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005cc1ab: { // 0x5cc1ab: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005cc1ad: { // 0x5cc1ad: 898694000000 MOV dword ptr [ESI + 0x94],EAX
    m.w32((s.si+0x00000094u), s.ax);
  }
  L005cc1b3: { // 0x5cc1b3: 0f8483000000 JZ 0x005cc23c
    if(integer::condition("JZ",flags)) goto L005cc23c;
  }
  L005cc1b9: { // 0x5cc1b9: 8b0d881b8200 MOV ECX,dword ptr [0x00821b88]
    s.cx = m.r32((0x00821b88u));
  }
  L005cc1bf: { // 0x5cc1bf: 81c1ab140000 ADD ECX,0x14ab
    s.cx = integer::add(s.cx,0x000014abu,32,flags);
  }
  L005cc1c5: { // 0x5cc1c5: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L005cc1c7: { // 0x5cc1c7: 668b3a MOV DI,word ptr [EDX]
    s.di = (s.di & 0xffff0000u) | ((m.r16((s.dx))) & 0xffffu);
  }
  L005cc1ca: { // 0x5cc1ca: 66897c2440 MOV word ptr [ESP + 0x40],DI
    m.w16((f.sp+0x00000040u), (s.di & 0xffffu));
  }
  L005cc1cf: { // 0x5cc1cf: 8a5c2440 MOV BL,byte ptr [ESP + 0x40]
    s.bx = with_al(s.bx, m.r8((f.sp+0x00000040u)));
  }
  L005cc1d3: { // 0x5cc1d3: 8a5202 MOV DL,byte ptr [EDX + 0x2]
    s.dx = with_al(s.dx, m.r8((s.dx+0x00000002u)));
  }
  L005cc1d6: { // 0x5cc1d6: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L005cc1d8: { // 0x5cc1d8: 7531 JNZ 0x005cc20b
    if(integer::condition("JNZ",flags)) goto L005cc20b;
  }
  L005cc1da: { // 0x5cc1da: 8a5c2441 MOV BL,byte ptr [ESP + 0x41]
    s.bx = with_al(s.bx, m.r8((f.sp+0x00000041u)));
  }
  L005cc1de: { // 0x5cc1de: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L005cc1e0: { // 0x5cc1e0: 7529 JNZ 0x005cc20b
    if(integer::condition("JNZ",flags)) goto L005cc20b;
  }
  L005cc1e2: { // 0x5cc1e2: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L005cc1e4: { // 0x5cc1e4: 7525 JNZ 0x005cc20b
    if(integer::condition("JNZ",flags)) goto L005cc20b;
  }
  L005cc1e6: { // 0x5cc1e6: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005cc1e8: { // 0x5cc1e8: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cc1ea: { // 0x5cc1ea: ff9084000000 CALL dword ptr [EAX + 0x84]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000084u)),6078960u); flags=s.arithmetic_flags;
  }
  L005cc1f0: { // 0x5cc1f0: 8b9694000000 MOV EDX,dword ptr [ESI + 0x94]
    s.dx = m.r32((s.si+0x00000094u));
  }
  L005cc1f6: { // 0x5cc1f6: 050b020000 ADD EAX,0x20b
    s.ax = integer::add(s.ax,0x0000020bu,32,flags);
  }
  L005cc1fb: { // 0x5cc1fb: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L005cc1fd: { // 0x5cc1fd: 668b01 MOV AX,word ptr [ECX]
    s.ax = with_ax(s.ax, m.r16((s.cx)));
  }
  L005cc200: { // 0x5cc200: 8a4902 MOV CL,byte ptr [ECX + 0x2]
    s.cx = with_al(s.cx, m.r8((s.cx+0x00000002u)));
  }
  L005cc203: { // 0x5cc203: 668902 MOV word ptr [EDX],AX
    m.w16((s.dx), (s.ax & 0xffffu));
  }
  L005cc206: { // 0x5cc206: 884a02 MOV byte ptr [EDX + 0x2],CL
    m.w8((s.dx+0x00000002u), (s.cx & 0xffu));
  }
  L005cc209: { // 0x5cc209: eb0c JMP 0x005cc217
    goto L005cc217;
  }
  L005cc20b: { // 0x5cc20b: 668b11 MOV DX,word ptr [ECX]
    s.dx = with_ax(s.dx, m.r16((s.cx)));
  }
  L005cc20e: { // 0x5cc20e: 8a4902 MOV CL,byte ptr [ECX + 0x2]
    s.cx = with_al(s.cx, m.r8((s.cx+0x00000002u)));
  }
  L005cc211: { // 0x5cc211: 668910 MOV word ptr [EAX],DX
    m.w16((s.ax), (s.dx & 0xffffu));
  }
  L005cc214: { // 0x5cc214: 884802 MOV byte ptr [EAX + 0x2],CL
    m.w8((s.ax+0x00000002u), (s.cx & 0xffu));
  }
  L005cc217: { // 0x5cc217: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005cc219: { // 0x5cc219: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cc21b: { // 0x5cc21b: ff9084000000 CALL dword ptr [EAX + 0x84]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000084u)),6079009u); flags=s.arithmetic_flags;
  }
  L005cc221: { // 0x5cc221: 8b8810020000 MOV ECX,dword ptr [EAX + 0x210]
    s.cx = m.r32((s.ax+0x00000210u));
  }
  L005cc227: { // 0x5cc227: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005cc228: { // 0x5cc228: 8b8e94000000 MOV ECX,dword ptr [ESI + 0x94]
    s.cx = m.r32((s.si+0x00000094u));
  }
  L005cc22e: { // 0x5cc22e: e8bdb4f6ff CALL 0x005376f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005376f0u,6079027u); flags=s.arithmetic_flags;
  }
  L005cc233: { // 0x5cc233: 8b9694000000 MOV EDX,dword ptr [ESI + 0x94]
    s.dx = m.r32((s.si+0x00000094u));
  }
  L005cc239: { // 0x5cc239: 897204 MOV dword ptr [EDX + 0x4],ESI
    m.w32((s.dx+0x00000004u), s.si);
  }
  L005cc23c: { // 0x5cc23c: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L005cc23e: { // 0x5cc23e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005cc23f: { // 0x5cc23f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005cc240: { // 0x5cc240: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005cc241: { // 0x5cc241: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005cc242: { // 0x5cc242: 83c42c ADD ESP,0x2c
    f.sp = integer::add(f.sp,0x0000002cu,32,flags);
  }
  L005cc245: { // 0x5cc245: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L005cc248: { // 0x5cc248: c6467601 MOV byte ptr [ESI + 0x76],0x1
    m.w8((s.si+0x00000076u), 0x00000001u);
  }
  L005cc24c: { // 0x5cc24c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005cc24d: { // 0x5cc24d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005cc24e: { // 0x5cc24e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005cc24f: { // 0x5cc24f: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L005cc251: { // 0x5cc251: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005cc252: { // 0x5cc252: 83c42c ADD ESP,0x2c
    f.sp = integer::add(f.sp,0x0000002cu,32,flags);
  }
  L005cc255: { // 0x5cc255: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00045110(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00445110: { // 0x00445110: 8b442404 MOV EAX, dword ptr [ESP + 4]
    s.ax = m.r32((f.sp+4u));
  }
  L00445114: { // 0x00445114: 8b5024 MOV EDX, dword ptr [EAX + 0x24]
    s.dx = m.r32((s.ax+0x00000024u));
  }
  L00445117: { // 0x00445117: 8b8118040000 MOV EAX, dword ptr [ECX + 0x418]
    s.ax = m.r32((s.cx+0x00000418u));
  }
  L0044511d: { // 0x0044511d: 89542404 MOV dword ptr [ESP + 4], EDX
    m.w32((f.sp+4u), s.dx);
  }
  L00445121: { // 0x00445121: 8b90cc030000 MOV EDX, dword ptr [EAX + 0x3cc]
    s.dx = m.r32((s.ax+0x000003ccu));
  }
  L00445127: { // 0x00445127: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00445129: { // 0x00445129: 7438 JZ 0x445163
    if(integer::condition("JZ",flags)) goto L00445163;
  }
  L0044512b: { // 0x0044512b: 8a5174 MOV DL, byte ptr [ECX + 0x74]
    s.dx = with_al(s.dx, m.r8((s.cx+0x00000074u)));
  }
  L0044512e: { // 0x0044512e: 84d2 TEST DL, DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L00445130: { // 0x00445130: 7431 JZ 0x445163
    if(integer::condition("JZ",flags)) goto L00445163;
  }
  L00445132: { // 0x00445132: 8b89b4010000 MOV ECX, dword ptr [ECX + 0x1b4]
    s.cx = m.r32((s.cx+0x000001b4u));
  }
  L00445138: { // 0x00445138: 8b90a4050000 MOV EDX, dword ptr [EAX + 0x5a4]
    s.dx = m.r32((s.ax+0x000005a4u));
  }
  L0044513e: { // 0x0044513e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0044513f: { // 0x0044513f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00445140: { // 0x00445140: 8d44240c LEA EAX, [ESP + 0xc]
    s.ax = (f.sp+0x0000000cu);
  }
  L00445144: { // 0x00445144: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00445145: { // 0x00445145: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00445146: { // 0x00445146: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0044514b: { // 0x0044514b: e8b0031000 CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4477264u); flags=s.arithmetic_flags;
  }
  L00445150: { // 0x00445150: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L00445152: { // 0x00445152: e859c30200 CALL 0x4714b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004714b0u,4477271u); flags=s.arithmetic_flags;
  }
  L00445157: { // 0x00445157: f6d8 NEG AL
    s.ax = with_al(s.ax, integer::sub(0u,(s.ax & 0xffu),8,flags));
  }
  L00445159: { // 0x00445159: 1bc0 SBB EAX, EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  L0044515b: { // 0x0044515b: 24f9 AND AL, 0xf9
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000f9u),8,flags));
  }
  L0044515d: { // 0x0044515d: 83c007 ADD EAX, 7
    s.ax = integer::add(s.ax,7u,32,flags);
  }
  L00445160: { // 0x00445160: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
  L00445163: { // 0x00445163: 8b89b4010000 MOV ECX, dword ptr [ECX + 0x1b4]
    s.cx = m.r32((s.cx+0x000001b4u));
  }
  L00445169: { // 0x00445169: 8b10 MOV EDX, dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0044516b: { // 0x0044516b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0044516c: { // 0x0044516c: 8d4c2408 LEA ECX, [ESP + 8]
    s.cx = (f.sp+8u);
  }
  L00445170: { // 0x00445170: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00445171: { // 0x00445171: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L00445173: { // 0x00445173: ff92a8000000 CALL dword ptr [EDX + 0xa8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000000a8u)),4477305u); flags=s.arithmetic_flags;
  }
  L00445179: { // 0x00445179: f6d8 NEG AL
    s.ax = with_al(s.ax, integer::sub(0u,(s.ax & 0xffu),8,flags));
  }
  L0044517b: { // 0x0044517b: 1bc0 SBB EAX, EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  L0044517d: { // 0x0044517d: 24f9 AND AL, 0xf9
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000f9u),8,flags));
  }
  L0044517f: { // 0x0044517f: 83c007 ADD EAX, 7
    s.ax = integer::add(s.ax,7u,32,flags);
  }
  L00445182: { // 0x00445182: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
}
void f_0005d4f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0045d4f0: { // 0x0045d4f0: 8a8187130000 MOV AL, byte ptr [ECX + 0x1387]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00001387u)));
  }
  L0045d4f6: { // 0x0045d4f6: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0045d4f8: { // 0x0045d4f8: 7405 JZ 0x45d4ff
    if(integer::condition("JZ",flags)) goto L0045d4ff;
  }
  L0045d4fa: { // 0x0045d4fa: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L0045d4fc: { // 0x0045d4fc: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0045d4ff: { // 0x0045d4ff: 8b442408 MOV EAX, dword ptr [ESP + 8]
    s.ax = m.r32((f.sp+8u));
  }
  L0045d503: { // 0x0045d503: 8b542404 MOV EDX, dword ptr [ESP + 4]
    s.dx = m.r32((f.sp+4u));
  }
  L0045d507: { // 0x0045d507: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0045d508: { // 0x0045d508: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0045d509: { // 0x0045d509: e842612700 CALL 0x6d3650
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d3650u,4576526u); flags=s.arithmetic_flags;
  }
  L0045d50e: { // 0x0045d50e: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_0005e400(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0045e400: { // 0x0045e400: 81ecd0010000 SUB ESP, 0x1d0
    f.sp = integer::sub(f.sp,0x000001d0u,32,flags);
  }
  L0045e406: { // 0x0045e406: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0045e407: { // 0x0045e407: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L0045e409: { // 0x0045e409: 8b86980b0000 MOV EAX, dword ptr [ESI + 0xb98]
    s.ax = m.r32((s.si+0x00000b98u));
  }
  L0045e40f: { // 0x0045e40f: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0045e411: { // 0x0045e411: 0f856e010000 JNZ 0x45e585
    if(integer::condition("JNZ",flags)) goto L0045e585;
  }
  L0045e417: { // 0x0045e417: 8a8ee1130000 MOV CL, byte ptr [ESI + 0x13e1]
    s.cx = with_al(s.cx, m.r8((s.si+0x000013e1u)));
  }
  L0045e41d: { // 0x0045e41d: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0045e41f: { // 0x0045e41f: 0f8460010000 JZ 0x45e585
    if(integer::condition("JZ",flags)) goto L0045e585;
  }
  L0045e425: { // 0x0045e425: 8d96f40b0000 LEA EDX, [ESI + 0xbf4]
    s.dx = (s.si+0x00000bf4u);
  }
  L0045e42b: { // 0x0045e42b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0045e42c: { // 0x0045e42c: 8bfa MOV EDI, EDX
    s.di = s.dx;
  }
  L0045e42e: { // 0x0045e42e: 83c9ff OR ECX, 0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  L0045e431: { // 0x0045e431: f2ae SCASB.REPNE ES:EDI
    string_instruction(m,s,flags,Kind::scan,8u,Repeat::not_equal);
  }
  L0045e433: { // 0x0045e433: f7d1 NOT ECX
    s.cx = (~(s.cx)&integer::mask(32));
  }
  L0045e435: { // 0x0045e435: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0045e436: { // 0x0045e436: 0f8442010000 JZ 0x45e57e
    if(integer::condition("JZ",flags)) goto L0045e57e;
  }
  L0045e43c: { // 0x0045e43c: 68a49c7b00 PUSH 0x7b9ca4
    f.push(m,0x007b9ca4u);
  }
  L0045e441: { // 0x0045e441: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0045e442: { // 0x0045e442: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0045e443: { // 0x0045e443: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0045e444: { // 0x0045e444: 8d8424e4000000 LEA EAX, [ESP + 0xe4]
    s.ax = (f.sp+0x000000e4u);
  }
  L0045e44b: { // 0x0045e44b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0045e44c: { // 0x0045e44c: e8df063100 CALL 0x76eb30
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076eb30u,4580433u); flags=s.arithmetic_flags;
  }
  L0045e451: { // 0x0045e451: 8b0dc055a200 MOV ECX, dword ptr [0xa255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L0045e457: { // 0x0045e457: 83c414 ADD ESP, 0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L0045e45a: { // 0x0045e45a: 8b9138080000 MOV EDX, dword ptr [ECX + 0x838]
    s.dx = m.r32((s.cx+0x00000838u));
  }
  L0045e460: { // 0x0045e460: 8d8c24d4000000 LEA ECX, [ESP + 0xd4]
    s.cx = (f.sp+0x000000d4u);
  }
  L0045e467: { // 0x0045e467: e8f41d1700 CALL 0x5d0260
    s.arithmetic_flags=flags; invoke(m,s,f,0x005d0260u,4580460u); flags=s.arithmetic_flags;
  }
  L0045e46c: { // 0x0045e46c: 8d9424d4000000 LEA EDX, [ESP + 0xd4]
    s.dx = (f.sp+0x000000d4u);
  }
  L0045e473: { // 0x0045e473: 8d4c2470 LEA ECX, [ESP + 0x70]
    s.cx = (f.sp+0x00000070u);
  }
  L0045e477: { // 0x0045e477: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0045e478: { // 0x0045e478: e8f3a60000 CALL 0x468b70
    s.arithmetic_flags=flags; invoke(m,s,f,0x00468b70u,4580477u); flags=s.arithmetic_flags;
  }
  L0045e47d: { // 0x0045e47d: 8d4c2470 LEA ECX, [ESP + 0x70]
    s.cx = (f.sp+0x00000070u);
  }
  L0045e481: { // 0x0045e481: e88a6b0300 CALL 0x495010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00495010u,4580486u); flags=s.arithmetic_flags;
  }
  L0045e486: { // 0x0045e486: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L0045e488: { // 0x0045e488: 85ff TEST EDI, EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0045e48a: { // 0x0045e48a: 7552 JNZ 0x45e4de
    if(integer::condition("JNZ",flags)) goto L0045e4de;
  }
  L0045e48c: { // 0x0045e48c: 8d8c24d4000000 LEA ECX, [ESP + 0xd4]
    s.cx = (f.sp+0x000000d4u);
  }
  L0045e493: { // 0x0045e493: e8181e1700 CALL 0x5d02b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005d02b0u,4580504u); flags=s.arithmetic_flags;
  }
  L0045e498: { // 0x0045e498: 8d8424d4000000 LEA EAX, [ESP + 0xd4]
    s.ax = (f.sp+0x000000d4u);
  }
  L0045e49f: { // 0x0045e49f: 8d4c240c LEA ECX, [ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  L0045e4a3: { // 0x0045e4a3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0045e4a4: { // 0x0045e4a4: e8c7a60000 CALL 0x468b70
    s.arithmetic_flags=flags; invoke(m,s,f,0x00468b70u,4580521u); flags=s.arithmetic_flags;
  }
  L0045e4a9: { // 0x0045e4a9: 8d4c240c LEA ECX, [ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  L0045e4ad: { // 0x0045e4ad: e85e6b0300 CALL 0x495010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00495010u,4580530u); flags=s.arithmetic_flags;
  }
  L0045e4b2: { // 0x0045e4b2: 8d4c2460 LEA ECX, [ESP + 0x60]
    s.cx = (f.sp+0x00000060u);
  }
  L0045e4b6: { // 0x0045e4b6: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L0045e4b8: { // 0x0045e4b8: c744240ca0567800 MOV dword ptr [ESP + 0xc], 0x7856a0
    m.w32((f.sp+0x0000000cu), 0x007856a0u);
  }
  L0045e4c0: { // 0x0045e4c0: c744246c00000000 MOV dword ptr [ESP + 0x6c], 0
    m.w32((f.sp+0x0000006cu), 0u);
  }
  L0045e4c8: { // 0x0045e4c8: e8c39dfdff CALL 0x438290
    s.arithmetic_flags=flags; invoke(m,s,f,0x00438290u,4580557u); flags=s.arithmetic_flags;
  }
  L0045e4cd: { // 0x0045e4cd: 8d4c240c LEA ECX, [ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  L0045e4d1: { // 0x0045e4d1: c744240c58567800 MOV dword ptr [ESP + 0xc], 0x785658
    m.w32((f.sp+0x0000000cu), 0x00785658u);
  }
  L0045e4d9: { // 0x0045e4d9: e8720dfdff CALL 0x42f250
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042f250u,4580574u); flags=s.arithmetic_flags;
  }
  L0045e4de: { // 0x0045e4de: 85ff TEST EDI, EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0045e4e0: { // 0x0045e4e0: 89be980b0000 MOV dword ptr [ESI + 0xb98], EDI
    m.w32((s.si+0x00000b98u), s.di);
  }
  L0045e4e6: { // 0x0045e4e6: 7466 JZ 0x45e54e
    if(integer::condition("JZ",flags)) goto L0045e54e;
  }
  L0045e4e8: { // 0x0045e4e8: b901000000 MOV ECX, 1
    s.cx = 1u;
  }
  L0045e4ed: { // 0x0045e4ed: 888e9c0b0000 MOV byte ptr [ESI + 0xb9c], CL
    m.w8((s.si+0x00000b9cu), (s.cx & 0xffu));
  }
  L0045e4f3: { // 0x0045e4f3: 0fbf4706 MOVSX EAX, word ptr [EDI + 6]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di+6u)),16));
  }
  L0045e4f7: { // 0x0045e4f7: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0045e4f8: { // 0x0045e4f8: 2bc2 SUB EAX, EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0045e4fa: { // 0x0045e4fa: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L0045e4fc: { // 0x0045e4fc: 8a8651130000 MOV AL, byte ptr [ESI + 0x1351]
    s.ax = with_al(s.ax, m.r8((s.si+0x00001351u)));
  }
  L0045e502: { // 0x0045e502: d1ff SAR EDI, 1
    s.di = integer::shift(s.di,1u,32,flags,integer::Shift::arithmetic_right);
  }
  L0045e504: { // 0x0045e504: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0045e506: { // 0x0045e506: 897c2408 MOV dword ptr [ESP + 8], EDI
    m.w32((f.sp+8u), s.di);
  }
  L0045e50a: { // 0x0045e50a: 740b JZ 0x45e517
    if(integer::condition("JZ",flags)) goto L0045e517;
  }
  L0045e50c: { // 0x0045e50c: 8bbe7c130000 MOV EDI, dword ptr [ESI + 0x137c]
    s.di = m.r32((s.si+0x0000137cu));
  }
  L0045e512: { // 0x0045e512: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0045e513: { // 0x0045e513: 897c2408 MOV dword ptr [ESP + 8], EDI
    m.w32((f.sp+8u), s.di);
  }
  L0045e517: { // 0x0045e517: 85ff TEST EDI, EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0045e519: { // 0x0045e519: 7e1d JLE 0x45e538
    if(integer::condition("JLE",flags)) goto L0045e538;
  }
  L0045e51b: { // 0x0045e51b: 8b0d881b8200 MOV ECX, dword ptr [0x821b88]
    s.cx = m.r32((0x00821b88u));
  }
  L0045e521: { // 0x0045e521: dd8178110000 FLD qword ptr [ECX + 0x1178]
    const auto address=(s.cx+0x00001178u);
    s.fp.load64(read64(m,address));
  }
  L0045e527: { // 0x0045e527: dc0d08667800 FMUL qword ptr [0x786608]
    const auto address=(0x00786608u);
    s.fp.multiply64(read64(m,address));
  }
  L0045e52d: { // 0x0045e52d: da742408 FIDIV dword ptr [ESP + 8]
    const auto address=(f.sp+8u);
    s.fp.divide_integer32(m.r32(address));
  }
  L0045e531: { // 0x0045e531: e81ac53000 CALL 0x76aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4580662u); flags=s.arithmetic_flags;
  }
  L0045e536: { // 0x0045e536: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L0045e538: { // 0x0045e538: c7868c0c000000000000 MOV dword ptr [ESI + 0xc8c], 0
    m.w32((s.si+0x00000c8cu), 0u);
  }
  L0045e542: { // 0x0045e542: 89be900c0000 MOV dword ptr [ESI + 0xc90], EDI
    m.w32((s.si+0x00000c90u), s.di);
  }
  L0045e548: { // 0x0045e548: 898e940c0000 MOV dword ptr [ESI + 0xc94], ECX
    m.w32((s.si+0x00000c94u), s.cx);
  }
  L0045e54e: { // 0x0045e54e: 8d8c24c4000000 LEA ECX, [ESP + 0xc4]
    s.cx = (f.sp+0x000000c4u);
  }
  L0045e555: { // 0x0045e555: c7442470a0567800 MOV dword ptr [ESP + 0x70], 0x7856a0
    m.w32((f.sp+0x00000070u), 0x007856a0u);
  }
  L0045e55d: { // 0x0045e55d: c78424d000000000000000 MOV dword ptr [ESP + 0xd0], 0
    m.w32((f.sp+0x000000d0u), 0u);
  }
  L0045e568: { // 0x0045e568: e8239dfdff CALL 0x438290
    s.arithmetic_flags=flags; invoke(m,s,f,0x00438290u,4580717u); flags=s.arithmetic_flags;
  }
  L0045e56d: { // 0x0045e56d: 8d4c2470 LEA ECX, [ESP + 0x70]
    s.cx = (f.sp+0x00000070u);
  }
  L0045e571: { // 0x0045e571: c744247058567800 MOV dword ptr [ESP + 0x70], 0x785658
    m.w32((f.sp+0x00000070u), 0x00785658u);
  }
  L0045e579: { // 0x0045e579: e8d20cfdff CALL 0x42f250
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042f250u,4580734u); flags=s.arithmetic_flags;
  }
  L0045e57e: { // 0x0045e57e: 8b86980b0000 MOV EAX, dword ptr [ESI + 0xb98]
    s.ax = m.r32((s.si+0x00000b98u));
  }
  L0045e584: { // 0x0045e584: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0045e585: { // 0x0045e585: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0045e586: { // 0x0045e586: 81c4d0010000 ADD ESP, 0x1d0
    f.sp = integer::add(f.sp,0x000001d0u,32,flags);
  }
  L0045e58c: { // 0x0045e58c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0022fde0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0062fde0: { // 0x62fde0: 803900 CMP byte ptr [ECX],0x0
    (void)integer::sub(m.r8((s.cx)),0x00000000u,8,flags);
  }
  L0062fde3: { // 0x62fde3: 7403 JZ 0x0062fde8
    if(integer::condition("JZ",flags)) goto L0062fde8;
  }
  L0062fde5: { // 0x62fde5: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0062fde7: { // 0x62fde7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0062fde8: { // 0x62fde8: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L0062fdeb: { // 0x62fdeb: 8b5108 MOV EDX,dword ptr [ECX + 0x8]
    s.dx = m.r32((s.cx+0x00000008u));
  }
  L0062fdee: { // 0x62fdee: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0062fdef: { // 0x62fdef: 8b54910c MOV EDX,dword ptr [ECX + EDX*0x4 + 0xc]
    s.dx = m.r32((s.cx+(s.dx * 0x00000004u)+0x0000000cu));
  }
  L0062fdf3: { // 0x62fdf3: 8b74810c MOV ESI,dword ptr [ECX + EAX*0x4 + 0xc]
    s.si = m.r32((s.cx+(s.ax * 0x00000004u)+0x0000000cu));
  }
  L0062fdf7: { // 0x62fdf7: 8d44810c LEA EAX,[ECX + EAX*0x4 + 0xc]
    s.ax = (s.cx+(s.ax * 0x00000004u)+0x0000000cu);
  }
  L0062fdfb: { // 0x62fdfb: 33f2 XOR ESI,EDX
    s.si = integer::logical((s.si)^(s.dx),32,flags);
  }
  L0062fdfd: { // 0x62fdfd: 8930 MOV dword ptr [EAX],ESI
    m.w32((s.ax), s.si);
  }
  L0062fdff: { // 0x62fdff: 8b5104 MOV EDX,dword ptr [ECX + 0x4]
    s.dx = m.r32((s.cx+0x00000004u));
  }
  L0062fe02: { // 0x62fe02: 8b7108 MOV ESI,dword ptr [ECX + 0x8]
    s.si = m.r32((s.cx+0x00000008u));
  }
  L0062fe05: { // 0x62fe05: 8b44910c MOV EAX,dword ptr [ECX + EDX*0x4 + 0xc]
    s.ax = m.r32((s.cx+(s.dx * 0x00000004u)+0x0000000cu));
  }
  L0062fe09: { // 0x62fe09: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L0062fe0a: { // 0x62fe0a: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0062fe0b: { // 0x62fe0b: 81fafa000000 CMP EDX,0xfa
    (void)integer::sub(s.dx,0x000000fau,32,flags);
  }
  L0062fe11: { // 0x62fe11: 895104 MOV dword ptr [ECX + 0x4],EDX
    m.w32((s.cx+0x00000004u), s.dx);
  }
  L0062fe14: { // 0x62fe14: 897108 MOV dword ptr [ECX + 0x8],ESI
    m.w32((s.cx+0x00000008u), s.si);
  }
  L0062fe17: { // 0x62fe17: 7c07 JL 0x0062fe20
    if(integer::condition("JL",flags)) goto L0062fe20;
  }
  L0062fe19: { // 0x62fe19: c7410400000000 MOV dword ptr [ECX + 0x4],0x0
    m.w32((s.cx+0x00000004u), 0x00000000u);
  }
  L0062fe20: { // 0x62fe20: 81fefa000000 CMP ESI,0xfa
    (void)integer::sub(s.si,0x000000fau,32,flags);
  }
  L0062fe26: { // 0x62fe26: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0062fe27: { // 0x62fe27: 7c07 JL 0x0062fe30
    if(integer::condition("JL",flags)) goto L0062fe30;
  }
  L0062fe29: { // 0x62fe29: c7410800000000 MOV dword ptr [ECX + 0x8],0x0
    m.w32((s.cx+0x00000008u), 0x00000000u);
  }
  L0062fe30: { // 0x62fe30: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0022e4e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0062e4e0: { // 0x0062e4e0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0062e4e1: { // 0x0062e4e1: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0062e4e2: { // 0x0062e4e2: 8b74240c MOV ESI,dword ptr [ESP + 0xc]
    s.si = m.r32((f.sp+0x0000000cu));
  }
  L0062e4e6: { // 0x0062e4e6: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0062e4e7: { // 0x0062e4e7: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0062e4e9: { // 0x0062e4e9: 8b9fd0000000 MOV EBX,dword ptr [EDI + 0xd0]
    s.bx = m.r32((s.di+0x000000d0u));
  }
  L0062e4ef: { // 0x0062e4ef: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L0062e4f1: { // 0x0062e4f1: 7e2b JLE 0x0062e51e
    if(integer::condition("JLE",flags)) goto L0062e51e;
  }
  L0062e4f3: { // 0x0062e4f3: 8b87c8000000 MOV EAX,dword ptr [EDI + 0xc8]
    s.ax = m.r32((s.di+0x000000c8u));
  }
  L0062e4f9: { // 0x0062e4f9: 8d8fc8000000 LEA ECX,[EDI + 0xc8]
    s.cx = (s.di+0x000000c8u);
  }
  L0062e4ff: { // 0x0062e4ff: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0062e501: { // 0x0062e501: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0062e502: { // 0x0062e502: ff5008 CALL dword ptr [EAX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000008u)),6481157u); flags=s.arithmetic_flags;
  }
  L0062e505: { // 0x0062e505: 3bde CMP EBX,ESI
    (void)integer::sub(s.bx,s.si,32,flags);
  }
  L0062e507: { // 0x0062e507: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L0062e509: { // 0x0062e509: 7d13 JGE 0x0062e51e
    if(integer::condition("JGE",flags)) goto L0062e51e;
  }
  L0062e50b: { // 0x0062e50b: 8b8fcc000000 MOV ECX,dword ptr [EDI + 0xcc]
    s.cx = m.r32((s.di+0x000000ccu));
  }
  L0062e511: { // 0x0062e511: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0062e512: { // 0x0062e512: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L0062e514: { // 0x0062e514: c74481fc00000000 MOV dword ptr [ECX + EAX*0x4 + -0x4],0x0
    m.w32((s.cx+(s.ax * 0x00000004u)-0x00000004u), 0x00000000u);
  }
  L0062e51c: { // 0x0062e51c: 7ced JL 0x0062e50b
    if(integer::condition("JL",flags)) goto L0062e50b;
  }
  L0062e51e: { // 0x0062e51e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0062e51f: { // 0x0062e51f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0062e520: { // 0x0062e520: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0062e521: { // 0x0062e521: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00307f00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00707f00: { // 0x707f00: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00707f02: { // 0x707f02: c70000000000 MOV dword ptr [EAX],0x0
    m.w32((s.ax), 0x00000000u);
  }
  L00707f08: { // 0x707f08: c7400400000000 MOV dword ptr [EAX + 0x4],0x0
    m.w32((s.ax+0x00000004u), 0x00000000u);
  }
  L00707f0f: { // 0x707f0f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00290440(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00690440: { // 0x690440: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00690442: { // 0x690442: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00690444: { // 0x690444: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00690446: { // 0x690446: 890a MOV dword ptr [EDX],ECX
    m.w32((s.dx), s.cx);
  }
  L00690448: { // 0x690448: 894a04 MOV dword ptr [EDX + 0x4],ECX
    m.w32((s.dx+0x00000004u), s.cx);
  }
  L0069044b: { // 0x69044b: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  L0069044e: { // 0x69044e: 894a0c MOV dword ptr [EDX + 0xc],ECX
    m.w32((s.dx+0x0000000cu), s.cx);
  }
  L00690451: { // 0x690451: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00096850(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00496850: { // 0x496850: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00496852: { // 0x496852: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  L00496858: { // 0x496858: 894808 MOV dword ptr [EAX + 0x8],ECX
    m.w32((s.ax+0x00000008u), s.cx);
  }
  L0049685b: { // 0x49685b: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0049685d: { // 0x49685d: 894810 MOV dword ptr [EAX + 0x10],ECX
    m.w32((s.ax+0x00000010u), s.cx);
  }
  L00496860: { // 0x496860: 894814 MOV dword ptr [EAX + 0x14],ECX
    m.w32((s.ax+0x00000014u), s.cx);
  }
  L00496863: { // 0x496863: 884818 MOV byte ptr [EAX + 0x18],CL
    m.w8((s.ax+0x00000018u), (s.cx & 0xffu));
  }
  L00496866: { // 0x496866: 884819 MOV byte ptr [EAX + 0x19],CL
    m.w8((s.ax+0x00000019u), (s.cx & 0xffu));
  }
  L00496869: { // 0x496869: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000b8660(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004b8660: { // 0x4b8660: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004b8662: { // 0x4b8662: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L004b8664: { // 0x4b8664: 668908 MOV word ptr [EAX],CX
    m.w16((s.ax), (s.cx & 0xffffu));
  }
  L004b8667: { // 0x4b8667: 66894804 MOV word ptr [EAX + 0x4],CX
    m.w16((s.ax+0x00000004u), (s.cx & 0xffffu));
  }
  L004b866b: { // 0x4b866b: 8b156c89a200 MOV EDX,dword ptr [0x00a2896c]
    s.dx = m.r32((0x00a2896cu));
  }
  L004b8671: { // 0x4b8671: 894810 MOV dword ptr [EAX + 0x10],ECX
    m.w32((s.ax+0x00000010u), s.cx);
  }
  L004b8674: { // 0x4b8674: 895008 MOV dword ptr [EAX + 0x8],EDX
    m.w32((s.ax+0x00000008u), s.dx);
  }
  L004b8677: { // 0x4b8677: 66894814 MOV word ptr [EAX + 0x14],CX
    m.w16((s.ax+0x00000014u), (s.cx & 0xffffu));
  }
  L004b867b: { // 0x4b867b: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L004b867f: { // 0x4b867f: 83f97f CMP ECX,0x7f
    (void)integer::sub(s.cx,0x0000007fu,32,flags);
  }
  L004b8682: { // 0x4b8682: 7c05 JL 0x004b8689
    if(integer::condition("JL",flags)) goto L004b8689;
  }
  L004b8684: { // 0x4b8684: b97f000000 MOV ECX,0x7f
    s.cx = 0x0000007fu;
  }
  L004b8689: { // 0x4b8689: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L004b868b: { // 0x4b868b: 8af1 MOV DH,CL
    s.dx = (s.dx & 0xffff00ffu) | ((((s.cx & 0xffu)) & 0xffu) << 8);
  }
  L004b868d: { // 0x4b868d: 66895014 MOV word ptr [EAX + 0x14],DX
    m.w16((s.ax+0x00000014u), (s.dx & 0xffffu));
  }
  L004b8691: { // 0x4b8691: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000b8640(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004b8640: { // 0x4b8640: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004b8642: { // 0x4b8642: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L004b8644: { // 0x4b8644: 668908 MOV word ptr [EAX],CX
    m.w16((s.ax), (s.cx & 0xffffu));
  }
  L004b8647: { // 0x4b8647: 66894804 MOV word ptr [EAX + 0x4],CX
    m.w16((s.ax+0x00000004u), (s.cx & 0xffffu));
  }
  L004b864b: { // 0x4b864b: 8b156c89a200 MOV EDX,dword ptr [0x00a2896c]
    s.dx = m.r32((0x00a2896cu));
  }
  L004b8651: { // 0x4b8651: 894810 MOV dword ptr [EAX + 0x10],ECX
    m.w32((s.ax+0x00000010u), s.cx);
  }
  L004b8654: { // 0x4b8654: 895008 MOV dword ptr [EAX + 0x8],EDX
    m.w32((s.ax+0x00000008u), s.dx);
  }
  L004b8657: { // 0x4b8657: 66894814 MOV word ptr [EAX + 0x14],CX
    m.w16((s.ax+0x00000014u), (s.cx & 0xffffu));
  }
  L004b865b: { // 0x4b865b: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000b86a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004b86a0: { // 0x4b86a0: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L004b86a4: { // 0x4b86a4: 668b01 MOV AX,word ptr [ECX]
    s.ax = with_ax(s.ax, m.r16((s.cx)));
  }
  L004b86a7: { // 0x4b86a7: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L004b86aa: { // 0x4b86aa: 663b02 CMP AX,word ptr [EDX]
    (void)integer::sub((s.ax & 0xffffu),m.r16((s.dx)),16,flags);
  }
  L004b86ad: { // 0x4b86ad: 0f84c4000000 JZ 0x004b8777
    if(integer::condition("JZ",flags)) goto L004b8777;
  }
  L004b86b3: { // 0x4b86b3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004b86b4: { // 0x4b86b4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004b86b5: { // 0x4b86b5: 668b6914 MOV BP,word ptr [ECX + 0x14]
    s.bp = (s.bp & 0xffff0000u) | ((m.r16((s.cx+0x00000014u))) & 0xffffu);
  }
  L004b86b9: { // 0x4b86b9: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004b86ba: { // 0x4b86ba: 6685ed TEST BP,BP
    (void)integer::logical(((s.bp & 0xffffu))&((s.bp & 0xffffu)),16,flags);
  }
  L004b86bd: { // 0x4b86bd: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004b86be: { // 0x4b86be: 7e6f JLE 0x004b872f
    if(integer::condition("JLE",flags)) goto L004b872f;
  }
  L004b86c0: { // 0x4b86c0: 8b7908 MOV EDI,dword ptr [ECX + 0x8]
    s.di = m.r32((s.cx+0x00000008u));
  }
  L004b86c3: { // 0x4b86c3: 8b5110 MOV EDX,dword ptr [ECX + 0x10]
    s.dx = m.r32((s.cx+0x00000010u));
  }
  L004b86c6: { // 0x4b86c6: 8b1d6c89a200 MOV EBX,dword ptr [0x00a2896c]
    s.bx = m.r32((0x00a2896cu));
  }
  L004b86cc: { // 0x4b86cc: 83ffff CMP EDI,-0x1
    (void)integer::sub(s.di,0xffffffffu,32,flags);
  }
  L004b86cf: { // 0x4b86cf: 740a JZ 0x004b86db
    if(integer::condition("JZ",flags)) goto L004b86db;
  }
  L004b86d1: { // 0x4b86d1: 8bf3 MOV ESI,EBX
    s.si = s.bx;
  }
  L004b86d3: { // 0x4b86d3: 2bf7 SUB ESI,EDI
    s.si = integer::sub(s.si,s.di,32,flags);
  }
  L004b86d5: { // 0x4b86d5: 3bf2 CMP ESI,EDX
    (void)integer::sub(s.si,s.dx,32,flags);
  }
  L004b86d7: { // 0x4b86d7: 7d56 JGE 0x004b872f
    if(integer::condition("JGE",flags)) goto L004b872f;
  }
  L004b86d9: { // 0x4b86d9: 2bd6 SUB EDX,ESI
    s.dx = integer::sub(s.dx,s.si,32,flags);
  }
  L004b86db: { // 0x4b86db: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L004b86dd: { // 0x4b86dd: 7450 JZ 0x004b872f
    if(integer::condition("JZ",flags)) goto L004b872f;
  }
  L004b86df: { // 0x4b86df: 662b4104 SUB AX,word ptr [ECX + 0x4]
    s.ax = with_ax(s.ax, integer::sub((s.ax & 0xffffu),m.r16((s.cx+0x00000004u)),16,flags));
  }
  L004b86e3: { // 0x4b86e3: 0fbffd MOVSX EDI,BP
    s.di = std::uint32_t(integer::sign_extend((s.bp & 0xffffu),16));
  }
  L004b86e6: { // 0x4b86e6: 0fbff0 MOVSX ESI,AX
    s.si = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L004b86e9: { // 0x4b86e9: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004b86eb: { // 0x4b86eb: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004b86ec: { // 0x4b86ec: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L004b86ee: { // 0x4b86ee: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004b86f0: { // 0x4b86f0: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004b86f1: { // 0x4b86f1: f7ff IDIV EDI
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.di,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L004b86f3: { // 0x4b86f3: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L004b86f5: { // 0x4b86f5: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L004b86f9: { // 0x4b86f9: 6685c0 TEST AX,AX
    (void)integer::logical(((s.ax & 0xffffu))&((s.ax & 0xffffu)),16,flags);
  }
  L004b86fc: { // 0x4b86fc: 7e27 JLE 0x004b8725
    if(integer::condition("JLE",flags)) goto L004b8725;
  }
  L004b86fe: { // 0x4b86fe: 8b7908 MOV EDI,dword ptr [ECX + 0x8]
    s.di = m.r32((s.cx+0x00000008u));
  }
  L004b8701: { // 0x4b8701: 8b5110 MOV EDX,dword ptr [ECX + 0x10]
    s.dx = m.r32((s.cx+0x00000010u));
  }
  L004b8704: { // 0x4b8704: 83ffff CMP EDI,-0x1
    (void)integer::sub(s.di,0xffffffffu,32,flags);
  }
  L004b8707: { // 0x4b8707: 740a JZ 0x004b8713
    if(integer::condition("JZ",flags)) goto L004b8713;
  }
  L004b8709: { // 0x4b8709: 2bdf SUB EBX,EDI
    s.bx = integer::sub(s.bx,s.di,32,flags);
  }
  L004b870b: { // 0x4b870b: 8bfb MOV EDI,EBX
    s.di = s.bx;
  }
  L004b870d: { // 0x4b870d: 3bfa CMP EDI,EDX
    (void)integer::sub(s.di,s.dx,32,flags);
  }
  L004b870f: { // 0x4b870f: 7d1a JGE 0x004b872b
    if(integer::condition("JGE",flags)) goto L004b872b;
  }
  L004b8711: { // 0x4b8711: 2bd7 SUB EDX,EDI
    s.dx = integer::sub(s.dx,s.di,32,flags);
  }
  L004b8713: { // 0x4b8713: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L004b8715: { // 0x4b8715: 0fbfd8 MOVSX EBX,AX
    s.bx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L004b8718: { // 0x4b8718: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004b871a: { // 0x4b871a: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004b871b: { // 0x4b871b: f7fb IDIV EBX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.bx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L004b871d: { // 0x4b871d: 0fafc7 IMUL EAX,EDI
    s.ax = integer::imul(s.ax,s.di,32,flags);
  }
  L004b8720: { // 0x4b8720: 6629442410 SUB word ptr [ESP + 0x10],AX
    m.w16((f.sp+0x00000010u), integer::sub(m.r16((f.sp+0x00000010u)),(s.ax & 0xffffu),16,flags));
  }
  L004b8725: { // 0x4b8725: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L004b8729: { // 0x4b8729: eb06 JMP 0x004b8731
    goto L004b8731;
  }
  L004b872b: { // 0x4b872b: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L004b872d: { // 0x4b872d: ebe6 JMP 0x004b8715
    goto L004b8715;
  }
  L004b872f: { // 0x4b872f: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L004b8731: { // 0x4b8731: 894104 MOV dword ptr [ECX + 0x4],EAX
    m.w32((s.cx+0x00000004u), s.ax);
  }
  L004b8734: { // 0x4b8734: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L004b8738: { // 0x4b8738: 6685ed TEST BP,BP
    (void)integer::logical(((s.bp & 0xffffu))&((s.bp & 0xffffu)),16,flags);
  }
  L004b873b: { // 0x4b873b: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L004b873d: { // 0x4b873d: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  L004b873f: { // 0x4b873f: 7e2a JLE 0x004b876b
    if(integer::condition("JLE",flags)) goto L004b876b;
  }
  L004b8741: { // 0x4b8741: 668bc2 MOV AX,DX
    s.ax = with_ax(s.ax, (s.dx & 0xffffu));
  }
  L004b8744: { // 0x4b8744: 8b356c89a200 MOV ESI,dword ptr [0x00a2896c]
    s.si = m.r32((0x00a2896cu));
  }
  L004b874a: { // 0x4b874a: 662b4104 SUB AX,word ptr [ECX + 0x4]
    s.ax = with_ax(s.ax, integer::sub((s.ax & 0xffffu),m.r16((s.cx+0x00000004u)),16,flags));
  }
  L004b874e: { // 0x4b874e: 0fbffd MOVSX EDI,BP
    s.di = std::uint32_t(integer::sign_extend((s.bp & 0xffffu),16));
  }
  L004b8751: { // 0x4b8751: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L004b8754: { // 0x4b8754: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004b8755: { // 0x4b8755: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L004b8757: { // 0x4b8757: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004b8759: { // 0x4b8759: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004b875a: { // 0x4b875a: f7ff IDIV EDI
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.di,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L004b875c: { // 0x4b875c: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L004b8760: { // 0x4b8760: 83c108 ADD ECX,0x8
    s.cx = integer::add(s.cx,0x00000008u,32,flags);
  }
  L004b8763: { // 0x4b8763: 8931 MOV dword ptr [ECX],ESI
    m.w32((s.cx), s.si);
  }
  L004b8765: { // 0x4b8765: 895104 MOV dword ptr [ECX + 0x4],EDX
    m.w32((s.cx+0x00000004u), s.dx);
  }
  L004b8768: { // 0x4b8768: 894108 MOV dword ptr [ECX + 0x8],EAX
    m.w32((s.cx+0x00000008u), s.ax);
  }
  L004b876b: { // 0x4b876b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004b876c: { // 0x4b876c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004b876d: { // 0x4b876d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004b876e: { // 0x4b876e: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L004b8770: { // 0x4b8770: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004b8771: { // 0x4b8771: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L004b8774: { // 0x4b8774: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004b8777: { // 0x4b8777: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004b8779: { // 0x4b8779: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L004b877c: { // 0x4b877c: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0000ffc0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0040ffc0: { // 0x40ffc0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L0040ffc4: { // 0x40ffc4: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L0040ffc7: { // 0x40ffc7: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000b8b00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004b8b00: { // 0x4b8b00: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L004b8b04: { // 0x4b8b04: 83f87f CMP EAX,0x7f
    (void)integer::sub(s.ax,0x0000007fu,32,flags);
  }
  L004b8b07: { // 0x4b8b07: 7c05 JL 0x004b8b0e
    if(integer::condition("JL",flags)) goto L004b8b0e;
  }
  L004b8b09: { // 0x4b8b09: b87f000000 MOV EAX,0x7f
    s.ax = 0x0000007fu;
  }
  L004b8b0e: { // 0x4b8b0e: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L004b8b10: { // 0x4b8b10: 8af0 MOV DH,AL
    s.dx = (s.dx & 0xffff00ffu) | ((((s.ax & 0xffu)) & 0xffu) << 8);
  }
  L004b8b12: { // 0x4b8b12: 66895114 MOV word ptr [ECX + 0x14],DX
    m.w16((s.cx+0x00000014u), (s.dx & 0xffffu));
  }
  L004b8b16: { // 0x4b8b16: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0004d670(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0044d670: { // 0x44d670: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0044d671: { // 0x44d671: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0044d672: { // 0x44d672: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0044d673: { // 0x44d673: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L0044d677: { // 0x44d677: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0044d678: { // 0x44d678: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0044d67a: { // 0x44d67a: 8a87c6050000 MOV AL,byte ptr [EDI + 0x5c6]
    s.ax = with_al(s.ax, m.r8((s.di+0x000005c6u)));
  }
  L0044d680: { // 0x44d680: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044d682: { // 0x44d682: 742c JZ 0x0044d6b0
    if(integer::condition("JZ",flags)) goto L0044d6b0;
  }
  L0044d684: { // 0x44d684: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0044d686: { // 0x44d686: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044d688: { // 0x44d688: 7e26 JLE 0x0044d6b0
    if(integer::condition("JLE",flags)) goto L0044d6b0;
  }
  L0044d68a: { // 0x44d68a: 8db7c0040000 LEA ESI,[EDI + 0x4c0]
    s.si = (s.di+0x000004c0u);
  }
  L0044d690: { // 0x44d690: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0044d692: { // 0x44d692: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0044d694: { // 0x44d694: 740b JZ 0x0044d6a1
    if(integer::condition("JZ",flags)) goto L0044d6a1;
  }
  L0044d696: { // 0x44d696: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0044d697: { // 0x44d697: e894742800 CALL 0x006d4b30
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d4b30u,4511388u); flags=s.arithmetic_flags;
  }
  L0044d69c: { // 0x44d69c: 833800 CMP dword ptr [EAX],0x0
    (void)integer::sub(m.r32((s.ax)),0x00000000u,32,flags);
  }
  L0044d69f: { // 0x44d69f: 7517 JNZ 0x0044d6b8
    if(integer::condition("JNZ",flags)) goto L0044d6b8;
  }
  L0044d6a1: { // 0x44d6a1: 0fbe87c6050000 MOVSX EAX,byte ptr [EDI + 0x5c6]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.di+0x000005c6u)),8));
  }
  L0044d6a8: { // 0x44d6a8: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L0044d6a9: { // 0x44d6a9: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  L0044d6ac: { // 0x44d6ac: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L0044d6ae: { // 0x44d6ae: 7ce0 JL 0x0044d690
    if(integer::condition("JL",flags)) goto L0044d690;
  }
  L0044d6b0: { // 0x44d6b0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0044d6b1: { // 0x44d6b1: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0044d6b3: { // 0x44d6b3: e8f8032800 CALL 0x006cdab0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006cdab0u,4511416u); flags=s.arithmetic_flags;
  }
  L0044d6b8: { // 0x44d6b8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0044d6b9: { // 0x44d6b9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0044d6ba: { // 0x44d6ba: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0044d6bb: { // 0x44d6bb: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0044d6bc: { // 0x44d6bc: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_002cdab0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006cdab0: { // 0x6cdab0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006cdab1: { // 0x6cdab1: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cdab2: { // 0x6cdab2: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  L006cdab6: { // 0x6cdab6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006cdab8: { // 0x6cdab8: 83ffff CMP EDI,-0x1
    (void)integer::sub(s.di,0xffffffffu,32,flags);
  }
  L006cdabb: { // 0x6cdabb: 7507 JNZ 0x006cdac4
    if(integer::condition("JNZ",flags)) goto L006cdac4;
  }
  L006cdabd: { // 0x6cdabd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006cdabe: { // 0x6cdabe: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006cdac0: { // 0x6cdac0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006cdac1: { // 0x6cdac1: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L006cdac4: { // 0x6cdac4: 8d8e18010000 LEA ECX,[ESI + 0x118]
    s.cx = (s.si+0x00000118u);
  }
  L006cdaca: { // 0x6cdaca: e811a50300 CALL 0x00707fe0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00707fe0u,7133903u); flags=s.arithmetic_flags;
  }
  L006cdacf: { // 0x6cdacf: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006cdad1: { // 0x6cdad1: 741b JZ 0x006cdaee
    if(integer::condition("JZ",flags)) goto L006cdaee;
  }
  L006cdad3: { // 0x6cdad3: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006cdad5: { // 0x6cdad5: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cdad6: { // 0x6cdad6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006cdad8: { // 0x6cdad8: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7133918u); flags=s.arithmetic_flags;
  }
  L006cdade: { // 0x6cdade: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006cdae0: { // 0x6cdae0: e86b700000 CALL 0x006d4b50
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d4b50u,7133925u); flags=s.arithmetic_flags;
  }
  L006cdae5: { // 0x6cdae5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006cdae7: { // 0x6cdae7: 7405 JZ 0x006cdaee
    if(integer::condition("JZ",flags)) goto L006cdaee;
  }
  L006cdae9: { // 0x6cdae9: 833800 CMP dword ptr [EAX],0x0
    (void)integer::sub(m.r32((s.ax)),0x00000000u,32,flags);
  }
  L006cdaec: { // 0x6cdaec: 7512 JNZ 0x006cdb00
    if(integer::condition("JNZ",flags)) goto L006cdb00;
  }
  L006cdaee: { // 0x6cdaee: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006cdaf0: { // 0x6cdaf0: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cdaf1: { // 0x6cdaf1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006cdaf3: { // 0x6cdaf3: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7133945u); flags=s.arithmetic_flags;
  }
  L006cdaf9: { // 0x6cdaf9: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006cdafb: { // 0x6cdafb: e830700000 CALL 0x006d4b30
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d4b30u,7133952u); flags=s.arithmetic_flags;
  }
  L006cdb00: { // 0x6cdb00: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006cdb01: { // 0x6cdb01: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006cdb02: { // 0x6cdb02: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00307fe0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00707fe0: { // 0x707fe0: dd01 FLD double ptr [ECX]
    const auto address=(s.cx);
    s.fp.load64(read64(m,address));
  }
  L00707fe2: { // 0x707fe2: dc1df8567800 FCOMP double ptr [0x007856f8]
    const auto address=(0x007856f8u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00707fe8: { // 0x707fe8: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00707fea: { // 0x707fea: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00707fed: { // 0x707fed: 7506 JNZ 0x00707ff5
    if(integer::condition("JNZ",flags)) goto L00707ff5;
  }
  L00707fef: { // 0x707fef: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L00707ff4: { // 0x707ff4: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00707ff5: { // 0x707ff5: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00707ff7: { // 0x707ff7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002d4b50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006d4b50: { // 0x6d4b50: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L006d4b54: { // 0x6d4b54: 8d14c500000000 LEA EDX,[EAX*0x8 + 0x0]
    s.dx = ((s.ax * 0x00000008u)+0x00000000u);
  }
  L006d4b5b: { // 0x6d4b5b: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L006d4b5d: { // 0x6d4b5d: 8d8491f4080000 LEA EAX,[ECX + EDX*0x4 + 0x8f4]
    s.ax = (s.cx+(s.dx * 0x00000004u)+0x000008f4u);
  }
  L006d4b64: { // 0x6d4b64: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_002d4b30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006d4b30: { // 0x6d4b30: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L006d4b34: { // 0x6d4b34: 8d14c500000000 LEA EDX,[EAX*0x8 + 0x0]
    s.dx = ((s.ax * 0x00000008u)+0x00000000u);
  }
  L006d4b3b: { // 0x6d4b3b: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L006d4b3d: { // 0x6d4b3d: 8d84914c070000 LEA EAX,[ECX + EDX*0x4 + 0x74c]
    s.ax = (s.cx+(s.dx * 0x00000004u)+0x0000074cu);
  }
  L006d4b44: { // 0x6d4b44: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_002b6910(Memory& m,State& s,Frame& f,const Operations& op) {s.ax=m.r32(s.cx);const auto target=m.r32(s.ax+0x84);f.sp+=4;invoke(m,s,f,target,f.outer_return);}
void f_000538b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004538b0: { // 0x004538b0: 8b8118040000 MOV EAX, dword ptr [ECX + 0x418]
    s.ax = m.r32((s.cx+0x00000418u));
  }
  L004538b6: { // 0x004538b6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00053890(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00453890: { // 0x00453890: b806000000 MOV EAX, 6
    s.ax = 6u;
  }
  L00453895: { // 0x00453895: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0000ff10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0040ff10: { // 0x40ff10: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0040ff12: { // 0x40ff12: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0040ff14: { // 0x40ff14: c74008445e7800 MOV dword ptr [EAX + 0x8],0x785e44
    m.w32((s.ax+0x00000008u), 0x00785e44u);
  }
  L0040ff1b: { // 0x40ff1b: c7400c3c5e7800 MOV dword ptr [EAX + 0xc],0x785e3c
    m.w32((s.ax+0x0000000cu), 0x00785e3cu);
  }
  L0040ff22: { // 0x40ff22: 894818 MOV dword ptr [EAX + 0x18],ECX
    m.w32((s.ax+0x00000018u), s.cx);
  }
  L0040ff25: { // 0x40ff25: 89481c MOV dword ptr [EAX + 0x1c],ECX
    m.w32((s.ax+0x0000001cu), s.cx);
  }
  L0040ff28: { // 0x40ff28: 884820 MOV byte ptr [EAX + 0x20],CL
    m.w8((s.ax+0x00000020u), (s.cx & 0xffu));
  }
  L0040ff2b: { // 0x40ff2b: 8a4814 MOV CL,byte ptr [EAX + 0x14]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000014u)));
  }
  L0040ff2e: { // 0x40ff2e: 80e1f8 AND CL,0xf8
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))&(0x000000f8u),8,flags));
  }
  L0040ff31: { // 0x40ff31: c74010ffffffff MOV dword ptr [EAX + 0x10],0xffffffff
    m.w32((s.ax+0x00000010u), 0xffffffffu);
  }
  L0040ff38: { // 0x40ff38: c700d85d7800 MOV dword ptr [EAX],0x785dd8
    m.w32((s.ax), 0x00785dd8u);
  }
  L0040ff3e: { // 0x40ff3e: c74004bc5d7800 MOV dword ptr [EAX + 0x4],0x785dbc
    m.w32((s.ax+0x00000004u), 0x00785dbcu);
  }
  L0040ff45: { // 0x40ff45: c74008b45d7800 MOV dword ptr [EAX + 0x8],0x785db4
    m.w32((s.ax+0x00000008u), 0x00785db4u);
  }
  L0040ff4c: { // 0x40ff4c: c7400cac5d7800 MOV dword ptr [EAX + 0xc],0x785dac
    m.w32((s.ax+0x0000000cu), 0x00785dacu);
  }
  L0040ff53: { // 0x40ff53: 884814 MOV byte ptr [EAX + 0x14],CL
    m.w8((s.ax+0x00000014u), (s.cx & 0xffu));
  }
  L0040ff56: { // 0x40ff56: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00005bf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00405bf0: { // 0x405bf0: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00405bf2: { // 0x405bf2: c7410cec928100 MOV dword ptr [ECX + 0xc],0x8192ec
    m.w32((s.cx+0x0000000cu), 0x008192ecu);
  }
  L00405bf9: { // 0x405bf9: 8901 MOV dword ptr [ECX],EAX
    m.w32((s.cx), s.ax);
  }
  L00405bfb: { // 0x405bfb: 894104 MOV dword ptr [ECX + 0x4],EAX
    m.w32((s.cx+0x00000004u), s.ax);
  }
  L00405bfe: { // 0x405bfe: 894108 MOV dword ptr [ECX + 0x8],EAX
    m.w32((s.cx+0x00000008u), s.ax);
  }
  L00405c01: { // 0x405c01: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0000ffd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0040ffd0: { // 0x0040ffd0: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L0040ffd6: { // 0x0040ffd6: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0040ffd8: { // 0x0040ffd8: 750c JNZ 0x0040ffe6
    if(integer::condition("JNZ",flags)) goto L0040ffe6;
  }
  L0040ffda: { // 0x0040ffda: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L0040ffde: { // 0x0040ffde: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0040ffe0: { // 0x0040ffe0: 89410c MOV dword ptr [ECX + 0xc],EAX
    m.w32((s.cx+0x0000000cu), s.ax);
  }
  L0040ffe3: { // 0x0040ffe3: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0040ffe6: { // 0x0040ffe6: e835a12400 CALL 0x0065a120
    s.arithmetic_flags=flags; invoke(m,s,f,0x0065a120u,4259819u); flags=s.arithmetic_flags;
  }
  L0040ffeb: { // 0x0040ffeb: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L0040ffef: { // 0x0040ffef: 89420c MOV dword ptr [EDX + 0xc],EAX
    m.w32((s.dx+0x0000000cu), s.ax);
  }
  L0040fff2: { // 0x0040fff2: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
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

void f_0025a120(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0065a120: { // 0x65a120: 8b8114020000 MOV EAX,dword ptr [ECX + 0x214]
    s.ax = m.r32((s.cx+0x00000214u));
  }
  L0065a126: { // 0x65a126: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0065a127: { // 0x65a127: 898114020000 MOV dword ptr [ECX + 0x214],EAX
    m.w32((s.cx+0x00000214u), s.ax);
  }
  L0065a12d: { // 0x65a12d: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00145490(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00545490: { // 0x545490: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00545491: { // 0x545491: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00545492: { // 0x545492: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  L00545496: { // 0x545496: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L00545498: { // 0x545498: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00545499: { // 0x545499: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0054549f: { // 0x54549f: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L005454a1: { // 0x5454a1: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L005454a3: { // 0x5454a3: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  L005454a6: { // 0x5454a6: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L005454a7: { // 0x5454a7: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L005454ad: { // 0x5454ad: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L005454af: { // 0x5454af: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L005454b2: { // 0x5454b2: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L005454b4: { // 0x5454b4: c1fe08 SAR ESI,0x8
    s.si = integer::shift(s.si,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L005454b7: { // 0x5454b7: c1e209 SHL EDX,0x9
    s.dx = integer::shift(s.dx,0x00000009u,32,flags,integer::Shift::left);
  }
  L005454ba: { // 0x5454ba: 03d6 ADD EDX,ESI
    s.dx = integer::add(s.dx,s.si,32,flags);
  }
  L005454bc: { // 0x5454bc: 781c JS 0x005454da
    if(integer::condition("JS",flags)) goto L005454da;
  }
  L005454be: { // 0x5454be: 3b913c010000 CMP EDX,dword ptr [ECX + 0x13c]
    (void)integer::sub(s.dx,m.r32((s.cx+0x0000013cu)),32,flags);
  }
  L005454c4: { // 0x5454c4: 7d14 JGE 0x005454da
    if(integer::condition("JGE",flags)) goto L005454da;
  }
  L005454c6: { // 0x5454c6: 8b8938010000 MOV ECX,dword ptr [ECX + 0x138]
    s.cx = m.r32((s.cx+0x00000138u));
  }
  L005454cc: { // 0x5454cc: 8b1491 MOV EDX,dword ptr [ECX + EDX*0x4]
    s.dx = m.r32((s.cx+(s.dx * 0x00000004u)));
  }
  L005454cf: { // 0x5454cf: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L005454d1: { // 0x5454d1: 7407 JZ 0x005454da
    if(integer::condition("JZ",flags)) goto L005454da;
  }
  L005454d3: { // 0x5454d3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005454d4: { // 0x5454d4: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L005454d6: { // 0x5454d6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005454d7: { // 0x5454d7: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L005454da: { // 0x5454da: 668974240c MOV word ptr [ESP + 0xc],SI
    m.w16((f.sp+0x0000000cu), (s.si & 0xffffu));
  }
  L005454df: { // 0x5454df: 668944240e MOV word ptr [ESP + 0xe],AX
    m.w16((f.sp+0x0000000eu), (s.ax & 0xffffu));
  }
  L005454e4: { // 0x5454e4: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  L005454e8: { // 0x5454e8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005454e9: { // 0x5454e9: 89153476a500 MOV dword ptr [0x00a57634],EDX
    m.w32((0x00a57634u), s.dx);
  }
  L005454ef: { // 0x5454ef: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L005454f4: { // 0x5454f4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005454f5: { // 0x5454f5: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 5526784u:f_00145500(m,s,child,{});break;
case 4698512u:f_0007b190(m,s,child,{});break;
case 5212624u:f_000f89d0(m,s,child,{});break;
case 5164128u:f_000ecc60(m,s,child,{});break;
case 4554832u:f_00058050(m,s,child,{});break;
case 7788640u:f_0036d860(m,s,child,{});break;
case 4426592u:f_00038b60(m,s,child,{});break;
case 7037728u:f_002b6320(m,s,child,{});break;
case 6479312u:f_0022ddd0(m,s,child,{});break;
case 5837568u:f_00191300(m,s,child,{});break;
case 6072688u:f_001ca970(m,s,child,{});break;
case 4453840u:f_0003f5d0(m,s,child,{});break;
case 7041696u:f_002b72a0(m,s,child,{});break;
case 4444464u:f_0003d130(m,s,child,{});break;
case 7052400u:f_002b9c70(m,s,child,{});break;
case 6078240u:f_001cbf20(m,s,child,{});break;
case 4477200u:f_00045110(m,s,child,{});break;
case 4576496u:f_0005d4f0(m,s,child,{});break;
case 4580352u:f_0005e400(m,s,child,{});break;
case 6487520u:f_0022fde0(m,s,child,{});break;
case 6481120u:f_0022e4e0(m,s,child,{});break;
case 7372544u:f_00307f00(m,s,child,{});break;
case 6882368u:f_00290440(m,s,child,{});break;
case 4810832u:f_00096850(m,s,child,{});break;
case 4949600u:f_000b8660(m,s,child,{});break;
case 4949568u:f_000b8640(m,s,child,{});break;
case 4949664u:f_000b86a0(m,s,child,{});break;
case 4259776u:f_0000ffc0(m,s,child,{});break;
case 4950784u:f_000b8b00(m,s,child,{});break;
case 4511344u:f_0004d670(m,s,child,{});break;
case 7133872u:f_002cdab0(m,s,child,{});break;
case 7372768u:f_00307fe0(m,s,child,{});break;
case 7162704u:f_002d4b50(m,s,child,{});break;
case 7162672u:f_002d4b30(m,s,child,{});break;
case 7039248u:f_002b6910(m,s,child,{});break;
case 4536496u:f_000538b0(m,s,child,{});break;
case 4536464u:f_00053890(m,s,child,{});break;
case 4259600u:f_0000ff10(m,s,child,{});break;
case 4217840u:f_00005bf0(m,s,child,{});break;
case 4259792u:f_0000ffd0(m,s,child,{});break;
case 5600336u:f_00157450(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
case 6660384u:f_0025a120(m,s,child,{});break;
case 5526672u:f_00145490(m,s,child,{});break;
case 0x76d957u:{const auto request=m.r32(child.entry_sp+4);if(request!=4&&request!=0x5e0)throw std::domain_error("252 exact allocation");s.ax=request==4?s.heap->allocate(4):s.heap->allocate_building252();s.allocations.emplace_back(new leaf::Memory(reinterpret_cast<unsigned char*>(std::uintptr_t(s.ax)),s.ax,request));m.add(*s.allocations.back());finish(m,s,child,0);break;}
default:throw std::domain_error("recovery252 unreviewed original call "+std::to_string(target)+" from "+std::to_string(continuation));}
f.sp=child.sp;
}
}

std::uint32_t fun_0056eba0(Memory& original,const Inputs& i,Heap& heap){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.heap=&heap;s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0056eba0: { // 0x56eba0: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L0056eba3: { // 0x56eba3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0056eba4: { // 0x56eba4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0056eba5: { // 0x56eba5: 8b6c2418 MOV EBP,dword ptr [ESP + 0x18]
    s.bp = m.r32((f.sp+0x00000018u));
  }
  L0056eba9: { // 0x56eba9: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0056ebaa: { // 0x56ebaa: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0056ebab: { // 0x56ebab: 8b5d04 MOV EBX,dword ptr [EBP + 0x4]
    s.bx = m.r32((s.bp+0x00000004u));
  }
  L0056ebae: { // 0x56ebae: 8b450c MOV EAX,dword ptr [EBP + 0xc]
    s.ax = m.r32((s.bp+0x0000000cu));
  }
  L0056ebb1: { // 0x56ebb1: 8d4c1801 LEA ECX,[EAX + EBX*0x1 + 0x1]
    s.cx = (s.ax+(s.bx * 0x00000001u)+0x00000001u);
  }
  L0056ebb5: { // 0x56ebb5: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L0056ebb7: { // 0x56ebb7: 7d62 JGE 0x0056ec1b
    if(integer::condition("JGE",flags)) goto L0056ec1b;
  }
  L0056ebb9: { // 0x56ebb9: 8b7d00 MOV EDI,dword ptr [EBP]
    s.di = m.r32((s.bp));
  }
  L0056ebbc: { // 0x56ebbc: 8b5508 MOV EDX,dword ptr [EBP + 0x8]
    s.dx = m.r32((s.bp+0x00000008u));
  }
  L0056ebbf: { // 0x56ebbf: 8d443a01 LEA EAX,[EDX + EDI*0x1 + 0x1]
    s.ax = (s.dx+(s.di * 0x00000001u)+0x00000001u);
  }
  L0056ebc3: { // 0x56ebc3: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L0056ebc5: { // 0x56ebc5: 7d45 JGE 0x0056ec0c
    if(integer::condition("JGE",flags)) goto L0056ec0c;
  }
  L0056ebc7: { // 0x56ebc7: 8d4c2420 LEA ECX,[ESP + 0x20]
    s.cx = (f.sp+0x00000020u);
  }
  L0056ebcb: { // 0x56ebcb: 66897c2420 MOV word ptr [ESP + 0x20],DI
    m.w16((f.sp+0x00000020u), (s.di & 0xffffu));
  }
  L0056ebd0: { // 0x56ebd0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0056ebd1: { // 0x56ebd1: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0056ebd6: { // 0x56ebd6: 66895c2426 MOV word ptr [ESP + 0x26],BX
    m.w16((f.sp+0x00000026u), (s.bx & 0xffffu));
  }
  L0056ebdb: { // 0x56ebdb: e82069fdff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5696480u); flags=s.arithmetic_flags;
  }
  L0056ebe0: { // 0x56ebe0: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0056ebe2: { // 0x56ebe2: 837e44ff CMP dword ptr [ESI + 0x44],-0x1
    (void)integer::sub(m.r32((s.si+0x00000044u)),0xffffffffu,32,flags);
  }
  L0056ebe6: { // 0x56ebe6: 7515 JNZ 0x0056ebfd
    if(integer::condition("JNZ",flags)) goto L0056ebfd;
  }
  L0056ebe8: { // 0x56ebe8: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0056ebea: { // 0x56ebea: e8a1c5f0ff CALL 0x0047b190
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b190u,5696495u); flags=s.arithmetic_flags;
  }
  L0056ebef: { // 0x56ebef: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0056ebf1: { // 0x56ebf1: 740a JZ 0x0056ebfd
    if(integer::condition("JZ",flags)) goto L0056ebfd;
  }
  L0056ebf3: { // 0x56ebf3: 8b86e4000000 MOV EAX,dword ptr [ESI + 0xe4]
    s.ax = m.r32((s.si+0x000000e4u));
  }
  L0056ebf9: { // 0x56ebf9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0056ebfb: { // 0x56ebfb: 742a JZ 0x0056ec27
    if(integer::condition("JZ",flags)) goto L0056ec27;
  }
  L0056ebfd: { // 0x56ebfd: 8b5508 MOV EDX,dword ptr [EBP + 0x8]
    s.dx = m.r32((s.bp+0x00000008u));
  }
  L0056ec00: { // 0x56ec00: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L0056ec03: { // 0x56ec03: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0056ec04: { // 0x56ec04: 8d4c0201 LEA ECX,[EDX + EAX*0x1 + 0x1]
    s.cx = (s.dx+(s.ax * 0x00000001u)+0x00000001u);
  }
  L0056ec08: { // 0x56ec08: 3bf9 CMP EDI,ECX
    (void)integer::sub(s.di,s.cx,32,flags);
  }
  L0056ec0a: { // 0x56ec0a: 7cbb JL 0x0056ebc7
    if(integer::condition("JL",flags)) goto L0056ebc7;
  }
  L0056ec0c: { // 0x56ec0c: 8b550c MOV EDX,dword ptr [EBP + 0xc]
    s.dx = m.r32((s.bp+0x0000000cu));
  }
  L0056ec0f: { // 0x56ec0f: 8b4504 MOV EAX,dword ptr [EBP + 0x4]
    s.ax = m.r32((s.bp+0x00000004u));
  }
  L0056ec12: { // 0x56ec12: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L0056ec13: { // 0x56ec13: 8d4c0201 LEA ECX,[EDX + EAX*0x1 + 0x1]
    s.cx = (s.dx+(s.ax * 0x00000001u)+0x00000001u);
  }
  L0056ec17: { // 0x56ec17: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L0056ec19: { // 0x56ec19: 7c9e JL 0x0056ebb9
    if(integer::condition("JL",flags)) goto L0056ebb9;
  }
  L0056ec1b: { // 0x56ec1b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0056ec1c: { // 0x56ec1c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0056ec1d: { // 0x56ec1d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0056ec1e: { // 0x56ec1e: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0056ec20: { // 0x56ec20: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0056ec21: { // 0x56ec21: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0056ec24: { // 0x56ec24: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0056ec27: { // 0x56ec27: b990bf7c00 MOV ECX,0x7cbf90
    s.cx = 0x007cbf90u;
  }
  L0056ec2c: { // 0x56ec2c: e89f9df8ff CALL 0x004f89d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f89d0u,5696561u); flags=s.arithmetic_flags;
  }
  L0056ec31: { // 0x56ec31: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0056ec33: { // 0x56ec33: e828e0f7ff CALL 0x004ecc60
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ecc60u,5696568u); flags=s.arithmetic_flags;
  }
  L0056ec38: { // 0x56ec38: b988bf7c00 MOV ECX,0x7cbf88
    s.cx = 0x007cbf88u;
  }
  L0056ec3d: { // 0x56ec3d: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0056ec3f: { // 0x56ec3f: e80c94eeff CALL 0x00458050
    s.arithmetic_flags=flags; invoke(m,s,f,0x00458050u,5696580u); flags=s.arithmetic_flags;
  }
  L0056ec44: { // 0x56ec44: 68e0050000 PUSH 0x5e0
    f.push(m,0x000005e0u);
  }
  L0056ec49: { // 0x56ec49: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0056ec4b: { // 0x56ec4b: e807ed1f00 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,5696592u); flags=s.arithmetic_flags;
  }
  L0056ec50: { // 0x56ec50: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0056ec53: { // 0x56ec53: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0056ec55: { // 0x56ec55: 7414 JZ 0x0056ec6b
    if(integer::condition("JZ",flags)) goto L0056ec6b;
  }
  L0056ec57: { // 0x56ec57: 8b150ce0a100 MOV EDX,dword ptr [0x00a1e00c]
    s.dx = m.r32((0x00a1e00cu));
  }
  L0056ec5d: { // 0x56ec5d: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0056ec5e: { // 0x56ec5e: 8b0c9a MOV ECX,dword ptr [EDX + EBX*0x4]
    s.cx = m.r32((s.dx+(s.bx * 0x00000004u)));
  }
  L0056ec61: { // 0x56ec61: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0056ec62: { // 0x56ec62: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0056ec64: { // 0x56ec64: e8f79eecff CALL 0x00438b60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00438b60u,5696617u); flags=s.arithmetic_flags;
  }
  L0056ec69: { // 0x56ec69: eb02 JMP 0x0056ec6d
    goto L0056ec6d;
  }
  L0056ec6b: { // 0x56ec6b: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0056ec6d: { // 0x56ec6d: 0fbf4e26 MOVSX ECX,word ptr [ESI + 0x26]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000026u)),16));
  }
  L0056ec71: { // 0x56ec71: 0fbf5624 MOVSX EDX,word ptr [ESI + 0x24]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000024u)),16));
  }
  L0056ec75: { // 0x56ec75: c1e108 SHL ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::left);
  }
  L0056ec78: { // 0x56ec78: c1e208 SHL EDX,0x8
    s.dx = integer::shift(s.dx,0x00000008u,32,flags,integer::Shift::left);
  }
  L0056ec7b: { // 0x56ec7b: 81c180000000 ADD ECX,0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L0056ec81: { // 0x56ec81: 81c280000000 ADD EDX,0x80
    s.dx = integer::add(s.dx,0x00000080u,32,flags);
  }
  L0056ec87: { // 0x56ec87: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L0056ec8b: { // 0x56ec8b: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L0056ec8f: { // 0x56ec8f: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L0056ec93: { // 0x56ec93: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0056ec95: { // 0x56ec95: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0056ec97: { // 0x56ec97: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0056ec98: { // 0x56ec98: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0056ec9a: { // 0x56ec9a: c744242000000000 MOV dword ptr [ESP + 0x20],0x0
    m.w32((f.sp+0x00000020u), 0x00000000u);
  }
  L0056eca2: { // 0x56eca2: ff92d4000000 CALL dword ptr [EDX + 0xd4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000000d4u)),5696680u); flags=s.arithmetic_flags;
  }
  L0056eca8: { // 0x56eca8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0056eca9: { // 0x56eca9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0056ecaa: { // 0x56ecaa: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0056ecab: { // 0x56ecab: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0056ecad: { // 0x56ecad: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0056ecae: { // 0x56ecae: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0056ecb1: { // 0x56ecb1: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
