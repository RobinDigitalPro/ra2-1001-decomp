#include "recovered/recovery_b737_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b737 {
namespace {
void f_002e0430(Memory&,State&,Frame&,const Operations&);
void f_002e0420(Memory&,State&,Frame&,const Operations&);
void f_000cf180(Memory&,State&,Frame&,const Operations&);
void f_000ced20(Memory&,State&,Frame&,const Operations&);
void f_000ced30(Memory&,State&,Frame&,const Operations&);
void f_000ced40(Memory&,State&,Frame&,const Operations&);
void f_000cf1f0(Memory&,State&,Frame&,const Operations&);
void f_000e0130(Memory&,State&,Frame&,const Operations&);
void f_000e0150(Memory&,State&,Frame&,const Operations&);
void f_000e0190(Memory&,State&,Frame&,const Operations&);
void f_001371d0(Memory&,State&,Frame&,const Operations&);
void f_00137220(Memory&,State&,Frame&,const Operations&);
void f_00137250(Memory&,State&,Frame&,const Operations&);
void f_001372c0(Memory&,State&,Frame&,const Operations&);
void f_001372f0(Memory&,State&,Frame&,const Operations&);
void f_000ced50(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_002e0430(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006e0430: { // 0x6e0430: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006e0432: { // 0x6e0432: c6412d00 MOV byte ptr [ECX + 0x2d], 0
    m.w8((s.cx+0x0000002du), 0u);
  }
  L006e0436: {if(m.r32(s.ax+72)!=0x4cf180)throw std::domain_error("737 unprovedtail");s.arithmetic_flags=flags;f_000cf180(m,s,f,op);return;
  }
}
void f_002e0420(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006e0420: { // 0x6e0420: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006e0422: { // 0x6e0422: c6412d01 MOV byte ptr [ECX + 0x2d], 1
    m.w8((s.cx+0x0000002du), 1u);
  }
  L006e0426: {if(m.r32(s.ax+72)!=0x4cf180)throw std::domain_error("737 unprovedtail");s.arithmetic_flags=flags;f_000cf180(m,s,f,op);return;
  }
}
void f_000cf180(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004cf180: { // 0x4cf180: c6411c01 MOV byte ptr [ECX + 0x1c], 1
    m.w8((s.cx+0x0000001cu), 1u);
  }
  L004cf184: { // 0x4cf184: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000ced20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004ced20: { // 0x4ced20: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L004ced22: { // 0x4ced22: c6411e00 MOV byte ptr [ECX + 0x1e], 0
    m.w8((s.cx+0x0000001eu), 0u);
  }
  L004ced26: { // 0x4ced26: c6411c01 MOV byte ptr [ECX + 0x1c], 1
    m.w8((s.cx+0x0000001cu), 1u);
  }
  L004ced2a: {if(m.r32(s.ax+84)!=0x4cf1f0)throw std::domain_error("737 unprovedtail");s.arithmetic_flags=flags;f_000cf1f0(m,s,f,op);return;
  }
}
void f_000ced30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004ced30: { // 0x4ced30: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L004ced32: { // 0x4ced32: 88411e MOV byte ptr [ECX + 0x1e], AL
    m.w8((s.cx+0x0000001eu), (s.ax & 0xffu));
  }
  L004ced35: { // 0x4ced35: 88411c MOV byte ptr [ECX + 0x1c], AL
    m.w8((s.cx+0x0000001cu), (s.ax & 0xffu));
  }
  L004ced38: { // 0x4ced38: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L004ced3a: {if(m.r32(s.ax+84)!=0x4cf1f0)throw std::domain_error("737 unprovedtail");s.arithmetic_flags=flags;f_000cf1f0(m,s,f,op);return;
  }
}
void f_000ced40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004ced40: { // 0x4ced40: 8a511e MOV DL, byte ptr [ECX + 0x1e]
    s.dx = with_al(s.dx, m.r8((s.cx+0x0000001eu)));
  }
  L004ced43: { // 0x4ced43: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004ced45: { // 0x4ced45: 84d2 TEST DL, DL
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
  L004cf1f0: { // 0x4cf1f0: 390d28e38400 CMP dword ptr [0x84e328], ECX
    (void)integer::sub(m.r32((0x0084e328u)),s.cx,32,flags);
  }
  L004cf1f6: { // 0x4cf1f6: 7513 JNZ 0x4cf20b
    if(integer::condition("JNZ",flags)) goto L004cf20b;
  }
  L004cf1f8: { // 0x4cf1f8: 8b4120 MOV EAX, dword ptr [ECX + 0x20]
    s.ax = m.r32((s.cx+0x00000020u));
  }
  L004cf1fb: { // 0x4cf1fb: 80e4fe AND AH, 0xfe
    s.ax = (s.ax & 0xffff00ffu) | (((integer::logical((((s.ax >> 8) & 0xffu))&(0x000000feu),8,flags)) & 0xffu) << 8);
  }
  L004cf1fe: { // 0x4cf1fe: 894120 MOV dword ptr [ECX + 0x20], EAX
    m.w32((s.cx+0x00000020u), s.ax);
  }
  L004cf201: { // 0x4cf201: c70528e3840000000000 MOV dword ptr [0x84e328], 0
    m.w32((0x0084e328u), 0u);
  }
  L004cf20b: { // 0x4cf20b: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000e0130(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004e0130: { // 0x4e0130: 8b4c2404 MOV ECX, dword ptr [ESP + 4]
    s.cx = m.r32((f.sp+4u));
  }
  L004e0134: { // 0x4e0134: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L004e0136: { // 0x4e0136: ff5018 CALL dword ptr [EAX + 0x18]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000018u)),5112121u); flags=s.arithmetic_flags;
  }
  L004e0139: { // 0x4e0139: 8b15348ba200 MOV EDX, dword ptr [0xa28b34]
    s.dx = m.r32((0x00a28b34u));
  }
  L004e013f: { // 0x4e013f: 33c9 XOR ECX, ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L004e0141: { // 0x4e0141: 3bd0 CMP EDX, EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L004e0143: { // 0x4e0143: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L004e0146: { // 0x4e0146: 8ac1 MOV AL, CL
    s.ax = with_al(s.ax, (s.cx & 0xffu));
  }
  L004e0148: { // 0x4e0148: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000e0150(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004e0150: { // 0x4e0150: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L004e0152: { // 0x4e0152: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004e0153: { // 0x4e0153: 8b742408 MOV ESI, dword ptr [ESP + 8]
    s.si = m.r32((f.sp+8u));
  }
  L004e0157: { // 0x4e0157: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004e0158: { // 0x4e0158: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),5112155u); flags=s.arithmetic_flags;
  }
  L004e015b: { // 0x4e015b: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e015d: { // 0x4e015d: 7406 JZ 0x4e0165
    if(integer::condition("JZ",flags)) goto L004e0165;
  }
  L004e015f: { // 0x4e015f: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004e0161: { // 0x4e0161: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004e0162: { // 0x4e0162: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004e0165: { // 0x4e0165: a1348ba200 MOV EAX, dword ptr [0xa28b34]
    s.ax = m.r32((0x00a28b34u));
  }
  L004e016a: { // 0x4e016a: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e016c: { // 0x4e016c: 740e JZ 0x4e017c
    if(integer::condition("JZ",flags)) goto L004e017c;
  }
  L004e016e: { // 0x4e016e: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004e0170: { // 0x4e0170: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004e0171: { // 0x4e0171: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004e0173: { // 0x4e0173: ff5210 CALL dword ptr [EDX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000010u)),5112182u); flags=s.arithmetic_flags;
  }
  L004e0176: { // 0x4e0176: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L004e0178: { // 0x4e0178: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004e0179: { // 0x4e0179: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004e017c: { // 0x4e017c: 8935348ba200 MOV dword ptr [0xa28b34], ESI
    m.w32((0x00a28b34u), s.si);
  }
  L004e0182: { // 0x4e0182: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L004e0184: { // 0x4e0184: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004e0185: { // 0x4e0185: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000e0190(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004e0190: { // 0x4e0190: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L004e0192: { // 0x4e0192: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004e0193: { // 0x4e0193: 8b742408 MOV ESI, dword ptr [ESP + 8]
    s.si = m.r32((f.sp+8u));
  }
  L004e0197: { // 0x4e0197: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004e0198: { // 0x4e0198: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),5112219u); flags=s.arithmetic_flags;
  }
  L004e019b: { // 0x4e019b: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e019d: { // 0x4e019d: 7504 JNZ 0x4e01a3
    if(integer::condition("JNZ",flags)) goto L004e01a3;
  }
  L004e019f: { // 0x4e019f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004e01a0: { // 0x4e01a0: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004e01a3: { // 0x4e01a3: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004e01a5: { // 0x4e01a5: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004e01a7: { // 0x4e01a7: ff5224 CALL dword ptr [EDX + 0x24]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000024u)),5112234u); flags=s.arithmetic_flags;
  }
  L004e01aa: { // 0x4e01aa: a3348ba200 MOV dword ptr [0xa28b34], EAX
    m.w32((0x00a28b34u), s.ax);
  }
  L004e01af: { // 0x4e01af: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L004e01b1: { // 0x4e01b1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004e01b2: { // 0x4e01b2: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_001371d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005371d0: { // 0x5371d0: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005371d2: { // 0x5371d2: 894104 MOV dword ptr [ECX + 4], EAX
    m.w32((s.cx+4u), s.ax);
  }
  L005371d5: { // 0x5371d5: 894108 MOV dword ptr [ECX + 8], EAX
    m.w32((s.cx+8u), s.ax);
  }
  L005371d8: { // 0x5371d8: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00137220(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00537220: { // 0x537220: 8b4108 MOV EAX, dword ptr [ECX + 8]
    s.ax = m.r32((s.cx+8u));
  }
  L00537223: { // 0x537223: 8d5108 LEA EDX, [ECX + 8]
    s.dx = (s.cx+8u);
  }
  L00537226: { // 0x537226: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00537228: { // 0x537228: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00537229: { // 0x537229: 7412 JZ 0x53723d
    if(integer::condition("JZ",flags)) goto L0053723d;
  }
  L0053722b: { // 0x53722b: 8b02 MOV EAX, dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L0053722d: { // 0x53722d: 3bc1 CMP EAX, ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0053722f: { // 0x53722f: 740e JZ 0x53723f
    if(integer::condition("JZ",flags)) goto L0053723f;
  }
  L00537231: { // 0x537231: 8b7008 MOV ESI, dword ptr [EAX + 8]
    s.si = m.r32((s.ax+8u));
  }
  L00537234: { // 0x537234: 8d5008 LEA EDX, [EAX + 8]
    s.dx = (s.ax+8u);
  }
  L00537237: { // 0x537237: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00537239: { // 0x537239: 75f0 JNZ 0x53722b
    if(integer::condition("JNZ",flags)) goto L0053722b;
  }
  L0053723b: { // 0x53723b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0053723c: { // 0x53723c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0053723d: { // 0x53723d: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L0053723f: { // 0x53723f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00537240: { // 0x537240: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00137250(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00537250: { // 0x537250: 8b4104 MOV EAX, dword ptr [ECX + 4]
    s.ax = m.r32((s.cx+4u));
  }
  L00537253: { // 0x537253: 8d5104 LEA EDX, [ECX + 4]
    s.dx = (s.cx+4u);
  }
  L00537256: { // 0x537256: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00537258: { // 0x537258: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00537259: { // 0x537259: 7412 JZ 0x53726d
    if(integer::condition("JZ",flags)) goto L0053726d;
  }
  L0053725b: { // 0x53725b: 8b02 MOV EAX, dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L0053725d: { // 0x53725d: 3bc1 CMP EAX, ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0053725f: { // 0x53725f: 740e JZ 0x53726f
    if(integer::condition("JZ",flags)) goto L0053726f;
  }
  L00537261: { // 0x537261: 8b7004 MOV ESI, dword ptr [EAX + 4]
    s.si = m.r32((s.ax+4u));
  }
  L00537264: { // 0x537264: 8d5004 LEA EDX, [EAX + 4]
    s.dx = (s.ax+4u);
  }
  L00537267: { // 0x537267: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00537269: { // 0x537269: 75f0 JNZ 0x53725b
    if(integer::condition("JNZ",flags)) goto L0053725b;
  }
  L0053726b: { // 0x53726b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0053726c: { // 0x53726c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0053726d: { // 0x53726d: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L0053726f: { // 0x53726f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00537270: { // 0x537270: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_001372c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005372c0: { // 0x5372c0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005372c1: { // 0x5372c1: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L005372c3: { // 0x5372c3: 8b4c2408 MOV ECX, dword ptr [ESP + 8]
    s.cx = m.r32((f.sp+8u));
  }
  L005372c7: { // 0x5372c7: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L005372c9: { // 0x5372c9: ff501c CALL dword ptr [EAX + 0x1c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000001cu)),5468876u); flags=s.arithmetic_flags;
  }
  L005372cc: { // 0x5372cc: 897004 MOV dword ptr [EAX + 4], ESI
    m.w32((s.ax+4u), s.si);
  }
  L005372cf: { // 0x5372cf: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005372d1: { // 0x5372d1: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L005372d3: { // 0x5372d3: 894608 MOV dword ptr [ESI + 8], EAX
    m.w32((s.si+8u), s.ax);
  }
  L005372d6: { // 0x5372d6: c7460400000000 MOV dword ptr [ESI + 4], 0
    m.w32((s.si+4u), 0u);
  }
  L005372dd: { // 0x5372dd: ff5218 CALL dword ptr [EDX + 0x18]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000018u)),5468896u); flags=s.arithmetic_flags;
  }
  L005372e0: { // 0x5372e0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005372e1: { // 0x5372e1: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_001372f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005372f0: { // 0x5372f0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005372f1: { // 0x5372f1: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005372f2: { // 0x5372f2: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L005372f4: { // 0x5372f4: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005372f5: { // 0x5372f5: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005372f7: { // 0x5372f7: ff5018 CALL dword ptr [EAX + 0x18]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000018u)),5468922u); flags=s.arithmetic_flags;
  }
  L005372fa: { // 0x5372fa: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005372fc: { // 0x5372fc: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L005372fe: { // 0x5372fe: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L00537300: { // 0x537300: ff521c CALL dword ptr [EDX + 0x1c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000001cu)),5468931u); flags=s.arithmetic_flags;
  }
  L00537303: { // 0x537303: 8b5608 MOV EDX, dword ptr [ESI + 8]
    s.dx = m.r32((s.si+8u));
  }
  L00537306: { // 0x537306: 33c9 XOR ECX, ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00537308: { // 0x537308: 3bd1 CMP EDX, ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L0053730a: { // 0x53730a: 7406 JZ 0x537312
    if(integer::condition("JZ",flags)) goto L00537312;
  }
  L0053730c: { // 0x53730c: 8b5e04 MOV EBX, dword ptr [ESI + 4]
    s.bx = m.r32((s.si+4u));
  }
  L0053730f: { // 0x53730f: 895a04 MOV dword ptr [EDX + 4], EBX
    m.w32((s.dx+4u), s.bx);
  }
  L00537312: { // 0x537312: 8b5604 MOV EDX, dword ptr [ESI + 4]
    s.dx = m.r32((s.si+4u));
  }
  L00537315: { // 0x537315: 3bd1 CMP EDX, ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L00537317: { // 0x537317: 7406 JZ 0x53731f
    if(integer::condition("JZ",flags)) goto L0053731f;
  }
  L00537319: { // 0x537319: 8b5e08 MOV EBX, dword ptr [ESI + 8]
    s.bx = m.r32((s.si+8u));
  }
  L0053731c: { // 0x53731c: 895a08 MOV dword ptr [EDX + 8], EBX
    m.w32((s.dx+8u), s.bx);
  }
  L0053731f: { // 0x53731f: 3bfe CMP EDI, ESI
    (void)integer::sub(s.di,s.si,32,flags);
  }
  L00537321: { // 0x537321: 894e08 MOV dword ptr [ESI + 8], ECX
    m.w32((s.si+8u), s.cx);
  }
  L00537324: { // 0x537324: 894e04 MOV dword ptr [ESI + 4], ECX
    m.w32((s.si+4u), s.cx);
  }
  L00537327: { // 0x537327: 7515 JNZ 0x53733e
    if(integer::condition("JNZ",flags)) goto L0053733e;
  }
  L00537329: { // 0x537329: 3bc6 CMP EAX, ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L0053732b: { // 0x53732b: 7506 JNZ 0x537333
    if(integer::condition("JNZ",flags)) goto L00537333;
  }
  L0053732d: { // 0x53732d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0053732e: { // 0x53732e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0053732f: { // 0x53732f: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00537331: { // 0x537331: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00537332: { // 0x537332: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00537333: { // 0x537333: 8b10 MOV EDX, dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00537335: { // 0x537335: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L00537337: { // 0x537337: ff5218 CALL dword ptr [EDX + 0x18]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000018u)),5468986u); flags=s.arithmetic_flags;
  }
  L0053733a: { // 0x53733a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0053733b: { // 0x53733b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0053733c: { // 0x53733c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0053733d: { // 0x53733d: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0053733e: { // 0x53733e: 8bc7 MOV EAX, EDI
    s.ax = s.di;
  }
  L00537340: { // 0x537340: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00537341: { // 0x537341: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00537342: { // 0x537342: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00537343: { // 0x537343: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000ced50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004ced50: { // 0x4ced50: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004ced51: { // 0x4ced51: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L004ced53: { // 0x4ced53: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004ced55: { // 0x4ced55: ff5054 CALL dword ptr [EAX + 0x54]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000054u)),5041496u); flags=s.arithmetic_flags;
  }
  L004ced58: { // 0x4ced58: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004ced5a: { // 0x4ced5a: e891850600 CALL 0x5372f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005372f0u,5041503u); flags=s.arithmetic_flags;
  }
  L004ced5f: { // 0x4ced5f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004ced60: { // 0x4ced60: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 7210032u:f_002e0430(m,s,child,{});break;
case 7210016u:f_002e0420(m,s,child,{});break;
case 5042560u:f_000cf180(m,s,child,{});break;
case 5041440u:f_000ced20(m,s,child,{});break;
case 5041456u:f_000ced30(m,s,child,{});break;
case 5041472u:f_000ced40(m,s,child,{});break;
case 5042672u:f_000cf1f0(m,s,child,{});break;
case 5112112u:f_000e0130(m,s,child,{});break;
case 5112144u:f_000e0150(m,s,child,{});break;
case 5112208u:f_000e0190(m,s,child,{});break;
case 5468624u:f_001371d0(m,s,child,{});break;
case 5468704u:f_00137220(m,s,child,{});break;
case 5468752u:f_00137250(m,s,child,{});break;
case 5468864u:f_001372c0(m,s,child,{});break;
case 5468912u:f_001372f0(m,s,child,{});break;
case 5041488u:f_000ced50(m,s,child,{});break;
default:throw std::domain_error("recovery737 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00673150(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00673150: { // 0x673150: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00673151: { // 0x673151: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00673153: { // 0x673153: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00673154: { // 0x673154: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  L00673158: { // 0x673158: 8b86d84e0000 MOV EAX,dword ptr [ESI + 0x4ed8]
    s.ax = m.r32((s.si+0x00004ed8u));
  }
  L0067315e: { // 0x67315e: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L00673160: { // 0x673160: 0f8450020000 JZ 0x006733b6
    if(integer::condition("JZ",flags)) goto L006733b6;
  }
  L00673166: { // 0x673166: 8d0c40 LEA ECX,[EAX + EAX*0x2]
    s.cx = (s.ax+(s.ax * 0x00000002u));
  }
  L00673169: { // 0x673169: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0067316a: { // 0x67316a: c1e105 SHL ECX,0x5
    s.cx = integer::shift(s.cx,0x00000005u,32,flags,integer::Shift::left);
  }
  L0067316d: { // 0x67316d: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0067316e: { // 0x67316e: 81c10810aa00 ADD ECX,0xaa1008
    s.cx = integer::add(s.cx,0x00aa1008u,32,flags);
  }
  L00673174: { // 0x673174: e8b7d20600 CALL 0x006e0430
    s.arithmetic_flags=flags; invoke(m,s,f,0x006e0430u,6762873u); flags=s.arithmetic_flags;
  }
  L00673179: { // 0x673179: 8b8ed84e0000 MOV ECX,dword ptr [ESI + 0x4ed8]
    s.cx = m.r32((s.si+0x00004ed8u));
  }
  L0067317f: { // 0x67317f: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00673181: { // 0x673181: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L00673184: { // 0x673184: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00673186: { // 0x673186: 8d04c0 LEA EAX,[EAX + EAX*0x8]
    s.ax = (s.ax+(s.ax * 0x00000008u));
  }
  L00673189: { // 0x673189: 8d0c41 LEA ECX,[ECX + EAX*0x2]
    s.cx = (s.cx+(s.ax * 0x00000002u));
  }
  L0067318c: { // 0x67318c: 8d0c49 LEA ECX,[ECX + ECX*0x2]
    s.cx = (s.cx+(s.cx * 0x00000002u));
  }
  L0067318f: { // 0x67318f: 8dac8e40150000 LEA EBP,[ESI + ECX*0x4 + 0x1540]
    s.bp = (s.si+(s.cx * 0x00000004u)+0x00001540u);
  }
  L00673196: { // 0x673196: c6451800 MOV byte ptr [EBP + 0x18],0x0
    m.w8((s.bp+0x00000018u), 0x00000000u);
  }
  L0067319a: { // 0x67319a: 8b15c055a200 MOV EDX,dword ptr [0x00a255c0]
    s.dx = m.r32((0x00a255c0u));
  }
  L006731a0: { // 0x6731a0: 8b0d6c198200 MOV ECX,dword ptr [0x0082196c]
    s.cx = m.r32((0x0082196cu));
  }
  L006731a6: { // 0x6731a6: 8b1d6c48aa00 MOV EBX,dword ptr [0x00aa486c]
    s.bx = m.r32((0x00aa486cu));
  }
  L006731ac: { // 0x6731ac: 8a8239220000 MOV AL,byte ptr [EDX + 0x2239]
    s.ax = with_al(s.ax, m.r8((s.dx+0x00002239u)));
  }
  L006731b2: { // 0x6731b2: 8b1564198200 MOV EDX,dword ptr [0x00821964]
    s.dx = m.r32((0x00821964u));
  }
  L006731b8: { // 0x6731b8: f6d8 NEG AL
    s.ax = with_al(s.ax, integer::sub(0u,(s.ax & 0xffu),8,flags));
  }
  L006731ba: { // 0x6731ba: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  L006731bc: { // 0x6731bc: 2bcb SUB ECX,EBX
    s.cx = integer::sub(s.cx,s.bx,32,flags);
  }
  L006731be: { // 0x6731be: 83e008 AND EAX,0x8
    s.ax = integer::logical((s.ax)&(0x00000008u),32,flags);
  }
  L006731c1: { // 0x6731c1: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L006731c3: { // 0x6731c3: 83c012 ADD EAX,0x12
    s.ax = integer::add(s.ax,0x00000012u,32,flags);
  }
  L006731c6: { // 0x6731c6: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L006731c8: { // 0x6731c8: b81f85eb51 MOV EAX,0x51eb851f
    s.ax = 0x51eb851fu;
  }
  L006731cd: { // 0x6731cd: 8d4c11f9 LEA ECX,[ECX + EDX*0x1 + -0x7]
    s.cx = (s.cx+(s.dx * 0x00000001u)-0x00000007u);
  }
  L006731d1: { // 0x6731d1: f7e9 IMUL ECX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.cx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  L006731d3: { // 0x6731d3: c1fa04 SAR EDX,0x4
    s.dx = integer::shift(s.dx,0x00000004u,32,flags,integer::Shift::arithmetic_right);
  }
  L006731d6: { // 0x6731d6: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L006731d8: { // 0x6731d8: c1e81f SHR EAX,0x1f
    s.ax = integer::shift(s.ax,0x0000001fu,32,flags,integer::Shift::right);
  }
  L006731db: { // 0x6731db: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L006731dd: { // 0x6731dd: d1e2 SHL EDX,0x1
    s.dx = integer::shift(s.dx,0x00000001u,32,flags,integer::Shift::left);
  }
  L006731df: { // 0x6731df: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L006731e1: { // 0x6731e1: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L006731e5: { // 0x6731e5: 7e2c JLE 0x00673213
    if(integer::condition("JLE",flags)) goto L00673213;
  }
  L006731e7: { // 0x6731e7: 8b4534 MOV EAX,dword ptr [EBP + 0x34]
    s.ax = m.r32((s.bp+0x00000034u));
  }
  L006731ea: { // 0x6731ea: 6bc03c IMUL EAX,EAX,0x3c
    s.ax = integer::imul(s.ax,0x0000003cu,32,flags);
  }
  L006731ed: { // 0x6731ed: 03c3 ADD EAX,EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L006731ef: { // 0x6731ef: 8d0cc500000000 LEA ECX,[EAX*0x8 + 0x0]
    s.cx = ((s.ax * 0x00000008u)+0x00000000u);
  }
  L006731f6: { // 0x6731f6: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L006731f8: { // 0x6731f8: 8d14cd4012aa00 LEA EDX,[ECX*0x8 + 0xaa1240]
    s.dx = ((s.cx * 0x00000008u)+0x00aa1240u);
  }
  L006731ff: { // 0x6731ff: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00673204: { // 0x673204: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00673205: { // 0x673205: e886cfe6ff CALL 0x004e0190
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e0190u,6763018u); flags=s.arithmetic_flags;
  }
  L0067320a: { // 0x67320a: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0067320e: { // 0x67320e: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L0067320f: { // 0x67320f: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L00673211: { // 0x673211: 7cd4 JL 0x006731e7
    if(integer::condition("JL",flags)) goto L006731e7;
  }
  L00673213: { // 0x673213: 8d0c7f LEA ECX,[EDI + EDI*0x2]
    s.cx = (s.di+(s.di * 0x00000002u));
  }
  L00673216: { // 0x673216: 89bed84e0000 MOV dword ptr [ESI + 0x4ed8],EDI
    m.w32((s.si+0x00004ed8u), s.di);
  }
  L0067321c: { // 0x67321c: c1e105 SHL ECX,0x5
    s.cx = integer::shift(s.cx,0x00000005u,32,flags,integer::Shift::left);
  }
  L0067321f: { // 0x67321f: 81c10810aa00 ADD ECX,0xaa1008
    s.cx = integer::add(s.cx,0x00aa1008u,32,flags);
  }
  L00673225: { // 0x673225: e8f6d10600 CALL 0x006e0420
    s.arithmetic_flags=flags; invoke(m,s,f,0x006e0420u,6763050u); flags=s.arithmetic_flags;
  }
  L0067322a: { // 0x67322a: 8b8ed84e0000 MOV ECX,dword ptr [ESI + 0x4ed8]
    s.cx = m.r32((s.si+0x00004ed8u));
  }
  L00673230: { // 0x673230: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00673232: { // 0x673232: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L00673235: { // 0x673235: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00673237: { // 0x673237: 8d04c0 LEA EAX,[EAX + EAX*0x8]
    s.ax = (s.ax+(s.ax * 0x00000008u));
  }
  L0067323a: { // 0x67323a: 8d0441 LEA EAX,[ECX + EAX*0x2]
    s.ax = (s.cx+(s.ax * 0x00000002u));
  }
  L0067323d: { // 0x67323d: 8d0c40 LEA ECX,[EAX + EAX*0x2]
    s.cx = (s.ax+(s.ax * 0x00000002u));
  }
  L00673240: { // 0x673240: 8dac8e40150000 LEA EBP,[ESI + ECX*0x4 + 0x1540]
    s.bp = (s.si+(s.cx * 0x00000004u)+0x00001540u);
  }
  L00673247: { // 0x673247: c6451801 MOV byte ptr [EBP + 0x18],0x1
    m.w8((s.bp+0x00000018u), 0x00000001u);
  }
  L0067324b: { // 0x67324b: 8b15c055a200 MOV EDX,dword ptr [0x00a255c0]
    s.dx = m.r32((0x00a255c0u));
  }
  L00673251: { // 0x673251: 8b0d6c198200 MOV ECX,dword ptr [0x0082196c]
    s.cx = m.r32((0x0082196cu));
  }
  L00673257: { // 0x673257: 8b1d6c48aa00 MOV EBX,dword ptr [0x00aa486c]
    s.bx = m.r32((0x00aa486cu));
  }
  L0067325d: { // 0x67325d: 8a8239220000 MOV AL,byte ptr [EDX + 0x2239]
    s.ax = with_al(s.ax, m.r8((s.dx+0x00002239u)));
  }
  L00673263: { // 0x673263: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L00673265: { // 0x673265: f6d8 NEG AL
    s.ax = with_al(s.ax, integer::sub(0u,(s.ax & 0xffu),8,flags));
  }
  L00673267: { // 0x673267: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  L00673269: { // 0x673269: 2bd3 SUB EDX,EBX
    s.dx = integer::sub(s.dx,s.bx,32,flags);
  }
  L0067326b: { // 0x67326b: 83e008 AND EAX,0x8
    s.ax = integer::logical((s.ax)&(0x00000008u),32,flags);
  }
  L0067326e: { // 0x67326e: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00673270: { // 0x673270: 83c012 ADD EAX,0x12
    s.ax = integer::add(s.ax,0x00000012u,32,flags);
  }
  L00673273: { // 0x673273: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L00673275: { // 0x673275: a164198200 MOV EAX,[0x00821964]
    s.ax = m.r32((0x00821964u));
  }
  L0067327a: { // 0x67327a: 8d5402f9 LEA EDX,[EDX + EAX*0x1 + -0x7]
    s.dx = (s.dx+(s.ax * 0x00000001u)-0x00000007u);
  }
  L0067327e: { // 0x67327e: b81f85eb51 MOV EAX,0x51eb851f
    s.ax = 0x51eb851fu;
  }
  L00673283: { // 0x673283: f7ea IMUL EDX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.dx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  L00673285: { // 0x673285: c1fa04 SAR EDX,0x4
    s.dx = integer::shift(s.dx,0x00000004u,32,flags,integer::Shift::arithmetic_right);
  }
  L00673288: { // 0x673288: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L0067328a: { // 0x67328a: c1e81f SHR EAX,0x1f
    s.ax = integer::shift(s.ax,0x0000001fu,32,flags,integer::Shift::right);
  }
  L0067328d: { // 0x67328d: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L0067328f: { // 0x67328f: d1e2 SHL EDX,0x1
    s.dx = integer::shift(s.dx,0x00000001u,32,flags,integer::Shift::left);
  }
  L00673291: { // 0x673291: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  L00673293: { // 0x673293: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L00673295: { // 0x673295: 7e4b JLE 0x006732e2
    if(integer::condition("JLE",flags)) goto L006732e2;
  }
  L00673297: { // 0x673297: 8b4534 MOV EAX,dword ptr [EBP + 0x34]
    s.ax = m.r32((s.bp+0x00000034u));
  }
  L0067329a: { // 0x67329a: 6bc03c IMUL EAX,EAX,0x3c
    s.ax = integer::imul(s.ax,0x0000003cu,32,flags);
  }
  L0067329d: { // 0x67329d: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L0067329f: { // 0x67329f: 8d0cc500000000 LEA ECX,[EAX*0x8 + 0x0]
    s.cx = ((s.ax * 0x00000008u)+0x00000000u);
  }
  L006732a6: { // 0x6732a6: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L006732a8: { // 0x6732a8: 8d0ccd4012aa00 LEA ECX,[ECX*0x8 + 0xaa1240]
    s.cx = ((s.cx * 0x00000008u)+0x00aa1240u);
  }
  L006732af: { // 0x6732af: e81c3fecff CALL 0x005371d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005371d0u,6763188u); flags=s.arithmetic_flags;
  }
  L006732b4: { // 0x6732b4: 8b4534 MOV EAX,dword ptr [EBP + 0x34]
    s.ax = m.r32((s.bp+0x00000034u));
  }
  L006732b7: { // 0x6732b7: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006732bc: { // 0x6732bc: 6bc03c IMUL EAX,EAX,0x3c
    s.ax = integer::imul(s.ax,0x0000003cu,32,flags);
  }
  L006732bf: { // 0x6732bf: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L006732c1: { // 0x6732c1: 8d14c500000000 LEA EDX,[EAX*0x8 + 0x0]
    s.dx = ((s.ax * 0x00000008u)+0x00000000u);
  }
  L006732c8: { // 0x6732c8: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L006732ca: { // 0x6732ca: 8d04d54012aa00 LEA EAX,[EDX*0x8 + 0xaa1240]
    s.ax = ((s.dx * 0x00000008u)+0x00aa1240u);
  }
  L006732d1: { // 0x6732d1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006732d2: { // 0x6732d2: e879cee6ff CALL 0x004e0150
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e0150u,6763223u); flags=s.arithmetic_flags;
  }
  L006732d7: { // 0x6732d7: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L006732d8: { // 0x6732d8: 3bfb CMP EDI,EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  L006732da: { // 0x6732da: 7cbb JL 0x00673297
    if(integer::condition("JL",flags)) goto L00673297;
  }
  L006732dc: { // 0x6732dc: 8b0d6c198200 MOV ECX,dword ptr [0x0082196c]
    s.cx = m.r32((0x0082196cu));
  }
  L006732e2: { // 0x6732e2: 8b15c055a200 MOV EDX,dword ptr [0x00a255c0]
    s.dx = m.r32((0x00a255c0u));
  }
  L006732e8: { // 0x6732e8: c60503f7810001 MOV byte ptr [0x0081f703],0x1
    m.w8((0x0081f703u), 0x00000001u);
  }
  L006732ef: { // 0x6732ef: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006732f0: { // 0x6732f0: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006732f1: { // 0x6732f1: 8a8239220000 MOV AL,byte ptr [EDX + 0x2239]
    s.ax = with_al(s.ax, m.r8((s.dx+0x00002239u)));
  }
  L006732f7: { // 0x6732f7: 8b156c48aa00 MOV EDX,dword ptr [0x00aa486c]
    s.dx = m.r32((0x00aa486cu));
  }
  L006732fd: { // 0x6732fd: f6d8 NEG AL
    s.ax = with_al(s.ax, integer::sub(0u,(s.ax & 0xffu),8,flags));
  }
  L006732ff: { // 0x6732ff: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  L00673301: { // 0x673301: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L00673303: { // 0x673303: 83e008 AND EAX,0x8
    s.ax = integer::logical((s.ax)&(0x00000008u),32,flags);
  }
  L00673306: { // 0x673306: 83c012 ADD EAX,0x12
    s.ax = integer::add(s.ax,0x00000012u,32,flags);
  }
  L00673309: { // 0x673309: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L0067330b: { // 0x67330b: a164198200 MOV EAX,[0x00821964]
    s.ax = m.r32((0x00821964u));
  }
  L00673310: { // 0x673310: 8d4c01f9 LEA ECX,[ECX + EAX*0x1 + -0x7]
    s.cx = (s.cx+(s.ax * 0x00000001u)-0x00000007u);
  }
  L00673314: { // 0x673314: b81f85eb51 MOV EAX,0x51eb851f
    s.ax = 0x51eb851fu;
  }
  L00673319: { // 0x673319: f7e9 IMUL ECX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.cx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  L0067331b: { // 0x67331b: c1fa04 SAR EDX,0x4
    s.dx = integer::shift(s.dx,0x00000004u,32,flags,integer::Shift::arithmetic_right);
  }
  L0067331e: { // 0x67331e: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L00673320: { // 0x673320: c1e91f SHR ECX,0x1f
    s.cx = integer::shift(s.cx,0x0000001fu,32,flags,integer::Shift::right);
  }
  L00673323: { // 0x673323: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L00673325: { // 0x673325: 8b8ed84e0000 MOV ECX,dword ptr [ESI + 0x4ed8]
    s.cx = m.r32((s.si+0x00004ed8u));
  }
  L0067332b: { // 0x67332b: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0067332d: { // 0x67332d: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L00673330: { // 0x673330: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00673332: { // 0x673332: d1e2 SHL EDX,0x1
    s.dx = integer::shift(s.dx,0x00000001u,32,flags,integer::Shift::left);
  }
  L00673334: { // 0x673334: 8d04c0 LEA EAX,[EAX + EAX*0x8]
    s.ax = (s.ax+(s.ax * 0x00000008u));
  }
  L00673337: { // 0x673337: 8d0441 LEA EAX,[ECX + EAX*0x2]
    s.ax = (s.cx+(s.ax * 0x00000002u));
  }
  L0067333a: { // 0x67333a: 8d0c40 LEA ECX,[EAX + EAX*0x2]
    s.cx = (s.ax+(s.ax * 0x00000002u));
  }
  L0067333d: { // 0x67333d: 8b848e90150000 MOV EAX,dword ptr [ESI + ECX*0x4 + 0x1590]
    s.ax = m.r32((s.si+(s.cx * 0x00000004u)+0x00001590u));
  }
  L00673344: { // 0x673344: b9f046aa00 MOV ECX,0xaa46f0
    s.cx = 0x00aa46f0u;
  }
  L00673349: { // 0x673349: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0067334b: { // 0x67334b: 7e37 JLE 0x00673384
    if(integer::condition("JLE",flags)) goto L00673384;
  }
  L0067334d: { // 0x67334d: e8eeb9e5ff CALL 0x004ced40
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced40u,6763346u); flags=s.arithmetic_flags;
  }
  L00673352: { // 0x673352: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00673354: { // 0x673354: 750a JNZ 0x00673360
    if(integer::condition("JNZ",flags)) goto L00673360;
  }
  L00673356: { // 0x673356: b9f046aa00 MOV ECX,0xaa46f0
    s.cx = 0x00aa46f0u;
  }
  L0067335b: { // 0x67335b: e8c0b9e5ff CALL 0x004ced20
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced20u,6763360u); flags=s.arithmetic_flags;
  }
  L00673360: { // 0x673360: b9c847aa00 MOV ECX,0xaa47c8
    s.cx = 0x00aa47c8u;
  }
  L00673365: { // 0x673365: e8d6b9e5ff CALL 0x004ced40
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced40u,6763370u); flags=s.arithmetic_flags;
  }
  L0067336a: { // 0x67336a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0067336c: { // 0x67336c: 7541 JNZ 0x006733af
    if(integer::condition("JNZ",flags)) goto L006733af;
  }
  L0067336e: { // 0x67336e: b9c847aa00 MOV ECX,0xaa47c8
    s.cx = 0x00aa47c8u;
  }
  L00673373: { // 0x673373: e8a8b9e5ff CALL 0x004ced20
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced20u,6763384u); flags=s.arithmetic_flags;
  }
  L00673378: { // 0x673378: c686e34e000001 MOV byte ptr [ESI + 0x4ee3],0x1
    m.w8((s.si+0x00004ee3u), 0x00000001u);
  }
  L0067337f: { // 0x67337f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00673380: { // 0x673380: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00673381: { // 0x673381: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00673384: { // 0x673384: e8b7b9e5ff CALL 0x004ced40
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced40u,6763401u); flags=s.arithmetic_flags;
  }
  L00673389: { // 0x673389: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0067338b: { // 0x67338b: 740a JZ 0x00673397
    if(integer::condition("JZ",flags)) goto L00673397;
  }
  L0067338d: { // 0x67338d: b9f046aa00 MOV ECX,0xaa46f0
    s.cx = 0x00aa46f0u;
  }
  L00673392: { // 0x673392: e899b9e5ff CALL 0x004ced30
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced30u,6763415u); flags=s.arithmetic_flags;
  }
  L00673397: { // 0x673397: b9c847aa00 MOV ECX,0xaa47c8
    s.cx = 0x00aa47c8u;
  }
  L0067339c: { // 0x67339c: e89fb9e5ff CALL 0x004ced40
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced40u,6763425u); flags=s.arithmetic_flags;
  }
  L006733a1: { // 0x6733a1: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006733a3: { // 0x6733a3: 740a JZ 0x006733af
    if(integer::condition("JZ",flags)) goto L006733af;
  }
  L006733a5: { // 0x6733a5: b9c847aa00 MOV ECX,0xaa47c8
    s.cx = 0x00aa47c8u;
  }
  L006733aa: { // 0x6733aa: e881b9e5ff CALL 0x004ced30
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ced30u,6763439u); flags=s.arithmetic_flags;
  }
  L006733af: { // 0x6733af: c686e34e000001 MOV byte ptr [ESI + 0x4ee3],0x1
    m.w8((s.si+0x00004ee3u), 0x00000001u);
  }
  L006733b6: { // 0x6733b6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006733b7: { // 0x6733b7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006733b8: { // 0x6733b8: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
