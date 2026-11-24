#include "recovered/recovery_b689_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b689 {
namespace {
void f_002b6910(Memory&,State&,Frame&,const Operations&);
void f_000538b0(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void f_0005e970(Memory&,State&,Frame&,const Operations&);
void f_00053890(Memory&,State&,Frame&,const Operations&);
void f_000f4f20(Memory&,State&,Frame&,const Operations&);
void f_002ce400(Memory&,State&,Frame&,const Operations&);
void f_002cce80(Memory&,State&,Frame&,const Operations&);
void f_00307f60(Memory&,State&,Frame&,const Operations&);
void f_00307fe0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_002b6910(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006b6910: { // 0x6b6910: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006b6912: {if(m.r32(s.ax+0x84)!=0x4538b0)throw std::domain_error("689 unprovedtail");s.arithmetic_flags=flags;f_000538b0(m,s,f,op);return;
  }
}
void f_000538b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004538b0: { // 0x4538b0: 8b8118040000 MOV EAX, dword ptr [ECX + 0x418]
    s.ax = m.r32((s.cx+0x00000418u));
  }
  L004538b6: { // 0x4538b6: c3 RET
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
void f_0005e970(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0045e970: { // 0x45e970: b807000000 MOV EAX, 7
    s.ax = 7u;
  }
  L0045e975: { // 0x45e975: c3 RET
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
void f_000f4f20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004f4f20: { // 0x4f4f20: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004f4f21: { // 0x4f4f21: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L004f4f23: { // 0x4f4f23: 8b4c2408 MOV ECX, dword ptr [ESP + 8]
    s.cx = m.r32((f.sp+8u));
  }
  L004f4f27: { // 0x4f4f27: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L004f4f29: { // 0x4f4f29: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),5197612u); flags=s.arithmetic_flags;
  }
  L004f4f2c: { // 0x4f4f2c: 83f803 CMP EAX, 3
    (void)integer::sub(s.ax,3u,32,flags);
  }
  L004f4f2f: { // 0x4f4f2f: 742e JZ 0x4f4f5f
    if(integer::condition("JZ",flags)) goto L004f4f5f;
  }
  L004f4f31: { // 0x4f4f31: 83f810 CMP EAX, 0x10
    (void)integer::sub(s.ax,0x00000010u,32,flags);
  }
  L004f4f34: { // 0x4f4f34: 741c JZ 0x4f4f52
    if(integer::condition("JZ",flags)) goto L004f4f52;
  }
  L004f4f36: { // 0x4f4f36: 83f828 CMP EAX, 0x28
    (void)integer::sub(s.ax,0x00000028u,32,flags);
  }
  L004f4f39: { // 0x4f4f39: 740a JZ 0x4f4f45
    if(integer::condition("JZ",flags)) goto L004f4f45;
  }
  L004f4f3b: { // 0x4f4f3b: d905f8677800 FLD dword ptr [0x7867f8]
    const auto address=(0x007867f8u);
    s.fp.load32(m.r32(address));
  }
  L004f4f41: { // 0x4f4f41: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004f4f42: { // 0x4f4f42: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004f4f45: { // 0x4f4f45: 8b4e34 MOV ECX, dword ptr [ESI + 0x34]
    s.cx = m.r32((s.si+0x00000034u));
  }
  L004f4f48: { // 0x4f4f48: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004f4f49: { // 0x4f4f49: d9812c010000 FLD dword ptr [ECX + 0x12c]
    const auto address=(s.cx+0x0000012cu);
    s.fp.load32(m.r32(address));
  }
  L004f4f4f: { // 0x4f4f4f: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004f4f52: { // 0x4f4f52: 8b5634 MOV EDX, dword ptr [ESI + 0x34]
    s.dx = m.r32((s.si+0x00000034u));
  }
  L004f4f55: { // 0x4f4f55: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004f4f56: { // 0x4f4f56: d98228010000 FLD dword ptr [EDX + 0x128]
    const auto address=(s.dx+0x00000128u);
    s.fp.load32(m.r32(address));
  }
  L004f4f5c: { // 0x4f4f5c: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004f4f5f: { // 0x4f4f5f: 8b4634 MOV EAX, dword ptr [ESI + 0x34]
    s.ax = m.r32((s.si+0x00000034u));
  }
  L004f4f62: { // 0x4f4f62: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004f4f63: { // 0x4f4f63: d98030010000 FLD dword ptr [EAX + 0x130]
    const auto address=(s.ax+0x00000130u);
    s.fp.load32(m.r32(address));
  }
  L004f4f69: { // 0x4f4f69: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_002ce400(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006ce400: { // 0x6ce400: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006ce402: { // 0x6ce402: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7136264u); flags=s.arithmetic_flags;
  }
  L006ce408: { // 0x6ce408: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006ce40a: { // 0x6ce40a: 7407 JZ 0x6ce413
    if(integer::condition("JZ",flags)) goto L006ce413;
  }
  L006ce40c: { // 0x6ce40c: 8b80a0050000 MOV EAX, dword ptr [EAX + 0x5a0]
    s.ax = m.r32((s.ax+0x000005a0u));
  }
  L006ce412: { // 0x6ce412: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L006ce413: { // 0x6ce413: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006ce415: { // 0x6ce415: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002cce80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006cce80: { // 0x6cce80: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cce81: { // 0x6cce81: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006cce82: { // 0x6cce82: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L006cce84: { // 0x6cce84: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cce85: { // 0x6cce85: 8dbe18010000 LEA EDI, [ESI + 0x118]
    s.di = (s.si+0x00000118u);
  }
  L006cce8b: { // 0x6cce8b: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L006cce8d: { // 0x6cce8d: e8ceb00300 CALL 0x707f60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00707f60u,7130770u); flags=s.arithmetic_flags;
  }
  L006cce92: { // 0x6cce92: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006cce94: { // 0x6cce94: 750b JNZ 0x6ccea1
    if(integer::condition("JNZ",flags)) goto L006ccea1;
  }
  L006cce96: { // 0x6cce96: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L006cce98: { // 0x6cce98: e843b10300 CALL 0x707fe0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00707fe0u,7130781u); flags=s.arithmetic_flags;
  }
  L006cce9d: { // 0x6cce9d: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006cce9f: { // 0x6cce9f: 7457 JZ 0x6ccef8
    if(integer::condition("JZ",flags)) goto L006ccef8;
  }
  L006ccea1: { // 0x6ccea1: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006ccea3: { // 0x6ccea3: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006ccea5: { // 0x6ccea5: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7130795u); flags=s.arithmetic_flags;
  }
  L006cceab: { // 0x6cceab: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L006ccead: { // 0x6ccead: 8bf0 MOV ESI, EAX
    s.si = s.ax;
  }
  L006cceaf: { // 0x6cceaf: e8acb00300 CALL 0x707f60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00707f60u,7130804u); flags=s.arithmetic_flags;
  }
  L006cceb4: { // 0x6cceb4: 8b5c2410 MOV EBX, dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L006cceb8: { // 0x6cceb8: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006cceba: { // 0x6cceba: 7413 JZ 0x6ccecf
    if(integer::condition("JZ",flags)) goto L006ccecf;
  }
  L006ccebc: { // 0x6ccebc: 8a841e6c020000 MOV AL, byte ptr [ESI + EBX + 0x26c]
    s.ax = with_al(s.ax, m.r8((s.si+s.bx+0x0000026cu)));
  }
  L006ccec3: { // 0x6ccec3: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006ccec5: { // 0x6ccec5: 7408 JZ 0x6ccecf
    if(integer::condition("JZ",flags)) goto L006ccecf;
  }
  L006ccec7: { // 0x6ccec7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006ccec8: { // 0x6ccec8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006ccec9: { // 0x6ccec9: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L006ccecb: { // 0x6ccecb: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006ccecc: { // 0x6ccecc: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L006ccecf: { // 0x6ccecf: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L006cced1: { // 0x6cced1: e80ab10300 CALL 0x707fe0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00707fe0u,7130838u); flags=s.arithmetic_flags;
  }
  L006cced6: { // 0x6cced6: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006cced8: { // 0x6cced8: 741e JZ 0x6ccef8
    if(integer::condition("JZ",flags)) goto L006ccef8;
  }
  L006cceda: { // 0x6cceda: 8a841e6c020000 MOV AL, byte ptr [ESI + EBX + 0x26c]
    s.ax = with_al(s.ax, m.r8((s.si+s.bx+0x0000026cu)));
  }
  L006ccee1: { // 0x6ccee1: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006ccee3: { // 0x6ccee3: 750b JNZ 0x6ccef0
    if(integer::condition("JNZ",flags)) goto L006ccef0;
  }
  L006ccee5: { // 0x6ccee5: 8a841e7e020000 MOV AL, byte ptr [ESI + EBX + 0x27e]
    s.ax = with_al(s.ax, m.r8((s.si+s.bx+0x0000027eu)));
  }
  L006cceec: { // 0x6cceec: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006cceee: { // 0x6cceee: 7408 JZ 0x6ccef8
    if(integer::condition("JZ",flags)) goto L006ccef8;
  }
  L006ccef0: { // 0x6ccef0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006ccef1: { // 0x6ccef1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006ccef2: { // 0x6ccef2: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L006ccef4: { // 0x6ccef4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006ccef5: { // 0x6ccef5: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L006ccef8: { // 0x6ccef8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006ccef9: { // 0x6ccef9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006ccefa: { // 0x6ccefa: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006ccefc: { // 0x6ccefc: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006ccefd: { // 0x6ccefd: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00307f60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00707f60: { // 0x707f60: dd01 FLD qword ptr [ECX]
    const auto address=(s.cx);
    s.fp.load64(read64(m,address));
  }
  L00707f62: { // 0x707f62: dc1d08577800 FCOMP qword ptr [0x785708]
    const auto address=(0x00785708u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00707f68: { // 0x707f68: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00707f6a: { // 0x707f6a: f6c401 TEST AH, 1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(1u),8,flags);
  }
  L00707f6d: { // 0x707f6d: 7515 JNZ 0x707f84
    if(integer::condition("JNZ",flags)) goto L00707f84;
  }
  L00707f6f: { // 0x707f6f: dd01 FLD qword ptr [ECX]
    const auto address=(s.cx);
    s.fp.load64(read64(m,address));
  }
  L00707f71: { // 0x707f71: dc1df8567800 FCOMP qword ptr [0x7856f8]
    const auto address=(0x007856f8u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00707f77: { // 0x707f77: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00707f79: { // 0x707f79: f6c401 TEST AH, 1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(1u),8,flags);
  }
  L00707f7c: { // 0x707f7c: 7406 JZ 0x707f84
    if(integer::condition("JZ",flags)) goto L00707f84;
  }
  L00707f7e: { // 0x707f7e: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L00707f83: { // 0x707f83: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00707f84: { // 0x707f84: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00707f86: { // 0x707f86: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00307fe0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00707fe0: { // 0x707fe0: dd01 FLD qword ptr [ECX]
    const auto address=(s.cx);
    s.fp.load64(read64(m,address));
  }
  L00707fe2: { // 0x707fe2: dc1df8567800 FCOMP qword ptr [0x7856f8]
    const auto address=(0x007856f8u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00707fe8: { // 0x707fe8: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00707fea: { // 0x707fea: f6c401 TEST AH, 1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(1u),8,flags);
  }
  L00707fed: { // 0x707fed: 7506 JNZ 0x707ff5
    if(integer::condition("JNZ",flags)) goto L00707ff5;
  }
  L00707fef: { // 0x707fef: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L00707ff4: { // 0x707ff4: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00707ff5: { // 0x707ff5: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00707ff7: { // 0x707ff7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 7039248u:f_002b6910(m,s,child,{});break;
case 4536496u:f_000538b0(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
case 4581744u:f_0005e970(m,s,child,{});break;
case 4536464u:f_00053890(m,s,child,{});break;
case 5197600u:f_000f4f20(m,s,child,{});break;
case 7136256u:f_002ce400(m,s,child,{});break;
case 7130752u:f_002cce80(m,s,child,{});break;
case 7372640u:f_00307f60(m,s,child,{});break;
case 7372768u:f_00307fe0(m,s,child,{});break;
default:throw std::domain_error("recovery689 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_004c9710(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004c9710: { // 0x4c9710: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L004c9713: { // 0x4c9713: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004c9714: { // 0x4c9714: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004c9716: { // 0x4c9716: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004c9717: { // 0x4c9717: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004c9719: { // 0x4c9719: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),5019423u); flags=s.arithmetic_flags;
  }
  L004c971f: { // 0x4c971f: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L004c9725: { // 0x4c9725: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004c9726: { // 0x4c9726: e8f5b70200 CALL 0x004f4f20
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f4f20u,5019435u); flags=s.arithmetic_flags;
  }
  L004c972b: { // 0x4c972b: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004c972d: { // 0x4c972d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004c972f: { // 0x4c972f: dd5c240c FSTP double ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L004c9733: { // 0x4c9733: ff9238030000 CALL dword ptr [EDX + 0x338]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000338u)),5019449u); flags=s.arithmetic_flags;
  }
  L004c9739: { // 0x4c9739: 89442408 MOV dword ptr [ESP + 0x8],EAX
    m.w32((f.sp+0x00000008u), s.ax);
  }
  L004c973d: { // 0x4c973d: db442408 FILD dword ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.load_integer32(m.r32(address));
  }
  L004c9741: { // 0x4c9741: dc4c240c FMUL double ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    s.fp.multiply64(read64(m,address));
  }
  L004c9745: { // 0x4c9745: dc8e70040000 FMUL double ptr [ESI + 0x470]
    const auto address=(s.si+0x00000470u);
    s.fp.multiply64(read64(m,address));
  }
  L004c974b: { // 0x4c974b: e800132a00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5019472u); flags=s.arithmetic_flags;
  }
  L004c9750: { // 0x4c9750: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L004c9752: { // 0x4c9752: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004c9754: { // 0x4c9754: 8944240c MOV dword ptr [ESP + 0xc],EAX
    m.w32((f.sp+0x0000000cu), s.ax);
  }
  L004c9758: { // 0x4c9758: e823372000 CALL 0x006cce80
    s.arithmetic_flags=flags; invoke(m,s,f,0x006cce80u,5019485u); flags=s.arithmetic_flags;
  }
  L004c975d: { // 0x4c975d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004c975f: { // 0x4c975f: 7418 JZ 0x004c9779
    if(integer::condition("JZ",flags)) goto L004c9779;
  }
  L004c9761: { // 0x4c9761: db442408 FILD dword ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.load_integer32(m.r32(address));
  }
  L004c9765: { // 0x4c9765: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L004c976a: { // 0x4c976a: dc8898050000 FMUL double ptr [EAX + 0x598]
    const auto address=(s.ax+0x00000598u);
    s.fp.multiply64(read64(m,address));
  }
  L004c9770: { // 0x4c9770: e8db122a00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5019509u); flags=s.arithmetic_flags;
  }
  L004c9775: { // 0x4c9775: 89442408 MOV dword ptr [ESP + 0x8],EAX
    m.w32((f.sp+0x00000008u), s.ax);
  }
  L004c9779: { // 0x4c9779: db442408 FILD dword ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.load_integer32(m.r32(address));
  }
  L004c977d: { // 0x4c977d: dc8e68040000 FMUL double ptr [ESI + 0x468]
    const auto address=(s.si+0x00000468u);
    s.fp.multiply64(read64(m,address));
  }
  L004c9783: { // 0x4c9783: e8c8122a00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5019528u); flags=s.arithmetic_flags;
  }
  L004c9788: { // 0x4c9788: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004c978a: { // 0x4c978a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004c978c: { // 0x4c978c: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L004c978e: { // 0x4c978e: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),5019537u); flags=s.arithmetic_flags;
  }
  L004c9791: { // 0x4c9791: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L004c9794: { // 0x4c9794: 7518 JNZ 0x004c97ae
    if(integer::condition("JNZ",flags)) goto L004c97ae;
  }
  L004c9796: { // 0x4c9796: 8b86b4050000 MOV EAX,dword ptr [ESI + 0x5b4]
    s.ax = m.r32((s.si+0x000005b4u));
  }
  L004c979c: { // 0x4c979c: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L004c979f: { // 0x4c979f: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L004c97a1: { // 0x4c97a1: 740d JZ 0x004c97b0
    if(integer::condition("JZ",flags)) goto L004c97b0;
  }
  L004c97a3: { // 0x4c97a3: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004c97a4: { // 0x4c97a4: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004c97a6: { // 0x4c97a6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004c97a7: { // 0x4c97a7: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L004c97a9: { // 0x4c97a9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004c97aa: { // 0x4c97aa: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L004c97ad: { // 0x4c97ad: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004c97ae: { // 0x4c97ae: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L004c97b0: { // 0x4c97b0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004c97b1: { // 0x4c97b1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004c97b2: { // 0x4c97b2: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L004c97b5: { // 0x4c97b5: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
