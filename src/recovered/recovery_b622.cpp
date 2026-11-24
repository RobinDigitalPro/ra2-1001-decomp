#include "recovered/recovery_b622_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b622 {
namespace {
void f_001cde80(Memory&,State&,Frame&,const Operations&);
void f_00010580(Memory&,State&,Frame&,const Operations&);
void f_0000ffd0(Memory&,State&,Frame&,const Operations&);
void f_0000ff10(Memory&,State&,Frame&,const Operations&);
void f_0036dd10(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_001cde80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005cde80: { // 0x5cde80: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L005cde84: { // 0x5cde84: 83ec1c SUB ESP,0x1c
    f.sp = integer::sub(f.sp,0x0000001cu,32,flags);
  }
  L005cde87: { // 0x5cde87: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005cde88: { // 0x5cde88: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005cde89: { // 0x5cde89: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L005cde8b: { // 0x5cde8b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005cde8c: { // 0x5cde8c: e8ef26e4ff CALL 0x00410580
    s.arithmetic_flags=flags; invoke(m,s,f,0x00410580u,6086289u); flags=s.arithmetic_flags;
  }
  L005cde91: { // 0x5cde91: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L005cde93: { // 0x5cde93: 8d85c8000000 LEA EAX,[EBP + 0xc8]
    s.ax = (s.bp+0x000000c8u);
  }
  L005cde99: { // 0x5cde99: 889d98000000 MOV byte ptr [EBP + 0x98],BL
    m.w8((s.bp+0x00000098u), (s.bx & 0xffu));
  }
  L005cde9f: { // 0x5cde9f: 889d99000000 MOV byte ptr [EBP + 0x99],BL
    m.w8((s.bp+0x00000099u), (s.bx & 0xffu));
  }
  L005cdea5: { // 0x5cdea5: 889d9a000000 MOV byte ptr [EBP + 0x9a],BL
    m.w8((s.bp+0x0000009au), (s.bx & 0xffu));
  }
  L005cdeab: { // 0x5cdeab: 899d9c000000 MOV dword ptr [EBP + 0x9c],EBX
    m.w32((s.bp+0x0000009cu), s.bx);
  }
  L005cdeb1: { // 0x5cdeb1: 899da0000000 MOV dword ptr [EBP + 0xa0],EBX
    m.w32((s.bp+0x000000a0u), s.bx);
  }
  L005cdeb7: { // 0x5cdeb7: 899da4000000 MOV dword ptr [EBP + 0xa4],EBX
    m.w32((s.bp+0x000000a4u), s.bx);
  }
  L005cdebd: { // 0x5cdebd: 889da8000000 MOV byte ptr [EBP + 0xa8],BL
    m.w8((s.bp+0x000000a8u), (s.bx & 0xffu));
  }
  L005cdec3: { // 0x5cdec3: 899dac000000 MOV dword ptr [EBP + 0xac],EBX
    m.w32((s.bp+0x000000acu), s.bx);
  }
  L005cdec9: { // 0x5cdec9: 899db0000000 MOV dword ptr [EBP + 0xb0],EBX
    m.w32((s.bp+0x000000b0u), s.bx);
  }
  L005cdecf: { // 0x5cdecf: 899db4000000 MOV dword ptr [EBP + 0xb4],EBX
    m.w32((s.bp+0x000000b4u), s.bx);
  }
  L005cded5: { // 0x5cded5: 899db8000000 MOV dword ptr [EBP + 0xb8],EBX
    m.w32((s.bp+0x000000b8u), s.bx);
  }
  L005cdedb: { // 0x5cdedb: 899dbc000000 MOV dword ptr [EBP + 0xbc],EBX
    m.w32((s.bp+0x000000bcu), s.bx);
  }
  L005cdee1: { // 0x5cdee1: 899dc0000000 MOV dword ptr [EBP + 0xc0],EBX
    m.w32((s.bp+0x000000c0u), s.bx);
  }
  L005cdee7: { // 0x5cdee7: 899dc4000000 MOV dword ptr [EBP + 0xc4],EBX
    m.w32((s.bp+0x000000c4u), s.bx);
  }
  L005cdeed: { // 0x5cdeed: b90f000000 MOV ECX,0xf
    s.cx = 0x0000000fu;
  }
  L005cdef2: { // 0x5cdef2: 8918 MOV dword ptr [EAX],EBX
    m.w32((s.ax), s.bx);
  }
  L005cdef4: { // 0x5cdef4: 895804 MOV dword ptr [EAX + 0x4],EBX
    m.w32((s.ax+0x00000004u), s.bx);
  }
  L005cdef7: { // 0x5cdef7: 83c008 ADD EAX,0x8
    s.ax = integer::add(s.ax,0x00000008u,32,flags);
  }
  L005cdefa: { // 0x5cdefa: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L005cdefb: { // 0x5cdefb: 75f5 JNZ 0x005cdef2
    if(integer::condition("JNZ",flags)) goto L005cdef2;
  }
  L005cdefd: { // 0x5cdefd: 8d8540010000 LEA EAX,[EBP + 0x140]
    s.ax = (s.bp+0x00000140u);
  }
  L005cdf03: { // 0x5cdf03: b90f000000 MOV ECX,0xf
    s.cx = 0x0000000fu;
  }
  L005cdf08: { // 0x5cdf08: 8918 MOV dword ptr [EAX],EBX
    m.w32((s.ax), s.bx);
  }
  L005cdf0a: { // 0x5cdf0a: 895804 MOV dword ptr [EAX + 0x4],EBX
    m.w32((s.ax+0x00000004u), s.bx);
  }
  L005cdf0d: { // 0x5cdf0d: 83c008 ADD EAX,0x8
    s.ax = integer::add(s.ax,0x00000008u,32,flags);
  }
  L005cdf10: { // 0x5cdf10: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L005cdf11: { // 0x5cdf11: 75f5 JNZ 0x005cdf08
    if(integer::condition("JNZ",flags)) goto L005cdf08;
  }
  L005cdf13: { // 0x5cdf13: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005cdf14: { // 0x5cdf14: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005cdf15: { // 0x5cdf15: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L005cdf18: { // 0x5cdf18: 8dbdc8010000 LEA EDI,[EBP + 0x1c8]
    s.di = (s.bp+0x000001c8u);
  }
  L005cdf1e: { // 0x5cdf1e: 889db8010000 MOV byte ptr [EBP + 0x1b8],BL
    m.w8((s.bp+0x000001b8u), (s.bx & 0xffu));
  }
  L005cdf24: { // 0x5cdf24: 899dbc010000 MOV dword ptr [EBP + 0x1bc],EBX
    m.w32((s.bp+0x000001bcu), s.bx);
  }
  L005cdf2a: { // 0x5cdf2a: 8985c0010000 MOV dword ptr [EBP + 0x1c0],EAX
    m.w32((s.bp+0x000001c0u), s.ax);
  }
  L005cdf30: { // 0x5cdf30: 8985c4010000 MOV dword ptr [EBP + 0x1c4],EAX
    m.w32((s.bp+0x000001c4u), s.ax);
  }
  L005cdf36: { // 0x5cdf36: 881f MOV byte ptr [EDI],BL
    m.w8((s.di), (s.bx & 0xffu));
  }
  L005cdf38: { // 0x5cdf38: 889de1010000 MOV byte ptr [EBP + 0x1e1],BL
    m.w8((s.bp+0x000001e1u), (s.bx & 0xffu));
  }
  L005cdf3e: { // 0x5cdf3e: 889de2010000 MOV byte ptr [EBP + 0x1e2],BL
    m.w8((s.bp+0x000001e2u), (s.bx & 0xffu));
  }
  L005cdf44: { // 0x5cdf44: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L005cdf46: { // 0x5cdf46: 889de3010000 MOV byte ptr [EBP + 0x1e3],BL
    m.w8((s.bp+0x000001e3u), (s.bx & 0xffu));
  }
  L005cdf4c: { // 0x5cdf4c: 8885fe010000 MOV byte ptr [EBP + 0x1fe],AL
    m.w8((s.bp+0x000001feu), (s.ax & 0xffu));
  }
  L005cdf52: { // 0x5cdf52: 888500020000 MOV byte ptr [EBP + 0x200],AL
    m.w8((s.bp+0x00000200u), (s.ax & 0xffu));
  }
  L005cdf58: { // 0x5cdf58: 888501020000 MOV byte ptr [EBP + 0x201],AL
    m.w8((s.bp+0x00000201u), (s.ax & 0xffu));
  }
  L005cdf5e: { // 0x5cdf5e: 888505020000 MOV byte ptr [EBP + 0x205],AL
    m.w8((s.bp+0x00000205u), (s.ax & 0xffu));
  }
  L005cdf64: { // 0x5cdf64: b080 MOV AL,0x80
    s.ax = with_al(s.ax, 0x00000080u);
  }
  L005cdf66: { // 0x5cdf66: 889dfc010000 MOV byte ptr [EBP + 0x1fc],BL
    m.w8((s.bp+0x000001fcu), (s.bx & 0xffu));
  }
  L005cdf6c: { // 0x5cdf6c: 889dfd010000 MOV byte ptr [EBP + 0x1fd],BL
    m.w8((s.bp+0x000001fdu), (s.bx & 0xffu));
  }
  L005cdf72: { // 0x5cdf72: 889dff010000 MOV byte ptr [EBP + 0x1ff],BL
    m.w8((s.bp+0x000001ffu), (s.bx & 0xffu));
  }
  L005cdf78: { // 0x5cdf78: 889d02020000 MOV byte ptr [EBP + 0x202],BL
    m.w8((s.bp+0x00000202u), (s.bx & 0xffu));
  }
  L005cdf7e: { // 0x5cdf7e: 889d03020000 MOV byte ptr [EBP + 0x203],BL
    m.w8((s.bp+0x00000203u), (s.bx & 0xffu));
  }
  L005cdf84: { // 0x5cdf84: 889d04020000 MOV byte ptr [EBP + 0x204],BL
    m.w8((s.bp+0x00000204u), (s.bx & 0xffu));
  }
  L005cdf8a: { // 0x5cdf8a: 889d06020000 MOV byte ptr [EBP + 0x206],BL
    m.w8((s.bp+0x00000206u), (s.bx & 0xffu));
  }
  L005cdf90: { // 0x5cdf90: 889d07020000 MOV byte ptr [EBP + 0x207],BL
    m.w8((s.bp+0x00000207u), (s.bx & 0xffu));
  }
  L005cdf96: { // 0x5cdf96: 889d08020000 MOV byte ptr [EBP + 0x208],BL
    m.w8((s.bp+0x00000208u), (s.bx & 0xffu));
  }
  L005cdf9c: { // 0x5cdf9c: 889d09020000 MOV byte ptr [EBP + 0x209],BL
    m.w8((s.bp+0x00000209u), (s.bx & 0xffu));
  }
  L005cdfa2: { // 0x5cdfa2: 889d0a020000 MOV byte ptr [EBP + 0x20a],BL
    m.w8((s.bp+0x0000020au), (s.bx & 0xffu));
  }
  L005cdfa8: { // 0x5cdfa8: 88850b020000 MOV byte ptr [EBP + 0x20b],AL
    m.w8((s.bp+0x0000020bu), (s.ax & 0xffu));
  }
  L005cdfae: { // 0x5cdfae: 88850c020000 MOV byte ptr [EBP + 0x20c],AL
    m.w8((s.bp+0x0000020cu), (s.ax & 0xffu));
  }
  L005cdfb4: { // 0x5cdfb4: 88850d020000 MOV byte ptr [EBP + 0x20d],AL
    m.w8((s.bp+0x0000020du), (s.ax & 0xffu));
  }
  L005cdfba: { // 0x5cdfba: c7851002000010000000 MOV dword ptr [EBP + 0x210],0x10
    m.w32((s.bp+0x00000210u), 0x00000010u);
  }
  L005cdfc4: { // 0x5cdfc4: 899d14020000 MOV dword ptr [EBP + 0x214],EBX
    m.w32((s.bp+0x00000214u), s.bx);
  }
  L005cdfca: { // 0x5cdfca: 899d18020000 MOV dword ptr [EBP + 0x218],EBX
    m.w32((s.bp+0x00000218u), s.bx);
  }
  L005cdfd0: { // 0x5cdfd0: 899d1c020000 MOV dword ptr [EBP + 0x21c],EBX
    m.w32((s.bp+0x0000021cu), s.bx);
  }
  L005cdfd6: { // 0x5cdfd6: 889d20020000 MOV byte ptr [EBP + 0x220],BL
    m.w8((s.bp+0x00000220u), (s.bx & 0xffu));
  }
  L005cdfdc: { // 0x5cdfdc: 899d24020000 MOV dword ptr [EBP + 0x224],EBX
    m.w32((s.bp+0x00000224u), s.bx);
  }
  L005cdfe2: { // 0x5cdfe2: 899d28020000 MOV dword ptr [EBP + 0x228],EBX
    m.w32((s.bp+0x00000228u), s.bx);
  }
  L005cdfe8: { // 0x5cdfe8: 899d2c020000 MOV dword ptr [EBP + 0x22c],EBX
    m.w32((s.bp+0x0000022cu), s.bx);
  }
  L005cdfee: { // 0x5cdfee: 899d30020000 MOV dword ptr [EBP + 0x230],EBX
    m.w32((s.bp+0x00000230u), s.bx);
  }
  L005cdff4: { // 0x5cdff4: 889d34020000 MOV byte ptr [EBP + 0x234],BL
    m.w8((s.bp+0x00000234u), (s.bx & 0xffu));
  }
  L005cdffa: { // 0x5cdffa: 899d38020000 MOV dword ptr [EBP + 0x238],EBX
    m.w32((s.bp+0x00000238u), s.bx);
  }
  L005ce000: { // 0x5ce000: 8d7524 LEA ESI,[EBP + 0x24]
    s.si = (s.bp+0x00000024u);
  }
  L005ce003: { // 0x5ce003: 899d3c020000 MOV dword ptr [EBP + 0x23c],EBX
    m.w32((s.bp+0x0000023cu), s.bx);
  }
  L005ce009: { // 0x5ce009: 899d40020000 MOV dword ptr [EBP + 0x240],EBX
    m.w32((s.bp+0x00000240u), s.bx);
  }
  L005ce00f: { // 0x5ce00f: 899d44020000 MOV dword ptr [EBP + 0x244],EBX
    m.w32((s.bp+0x00000244u), s.bx);
  }
  L005ce015: { // 0x5ce015: 889d48020000 MOV byte ptr [EBP + 0x248],BL
    m.w8((s.bp+0x00000248u), (s.bx & 0xffu));
  }
  L005ce01b: { // 0x5ce01b: 899d4c020000 MOV dword ptr [EBP + 0x24c],EBX
    m.w32((s.bp+0x0000024cu), s.bx);
  }
  L005ce021: { // 0x5ce021: 899d50020000 MOV dword ptr [EBP + 0x250],EBX
    m.w32((s.bp+0x00000250u), s.bx);
  }
  L005ce027: { // 0x5ce027: 899d54020000 MOV dword ptr [EBP + 0x254],EBX
    m.w32((s.bp+0x00000254u), s.bx);
  }
  L005ce02d: { // 0x5ce02d: 899d58020000 MOV dword ptr [EBP + 0x258],EBX
    m.w32((s.bp+0x00000258u), s.bx);
  }
  L005ce033: { // 0x5ce033: 889d5c020000 MOV byte ptr [EBP + 0x25c],BL
    m.w8((s.bp+0x0000025cu), (s.bx & 0xffu));
  }
  L005ce039: { // 0x5ce039: 899d60020000 MOV dword ptr [EBP + 0x260],EBX
    m.w32((s.bp+0x00000260u), s.bx);
  }
  L005ce03f: { // 0x5ce03f: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  L005ce041: { // 0x5ce041: c74500b8267900 MOV dword ptr [EBP],0x7926b8
    m.w32((s.bp), 0x007926b8u);
  }
  L005ce048: { // 0x5ce048: c745049c267900 MOV dword ptr [EBP + 0x4],0x79269c
    m.w32((s.bp+0x00000004u), 0x0079269cu);
  }
  L005ce04f: { // 0x5ce04f: c7450894267900 MOV dword ptr [EBP + 0x8],0x792694
    m.w32((s.bp+0x00000008u), 0x00792694u);
  }
  L005ce056: { // 0x5ce056: c7450c8c267900 MOV dword ptr [EBP + 0xc],0x79268c
    m.w32((s.bp+0x0000000cu), 0x0079268cu);
  }
  L005ce05d: { // 0x5ce05d: 7408 JZ 0x005ce067
    if(integer::condition("JZ",flags)) goto L005ce067;
  }
  L005ce05f: { // 0x5ce05f: b906000000 MOV ECX,0x6
    s.cx = 0x00000006u;
  }
  L005ce064: { // 0x5ce064: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L005ce066: { // 0x5ce066: a4 MOVSB ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::single);
  }
  L005ce067: { // 0x5ce067: b9a4488200 MOV ECX,0x8248a4
    s.cx = 0x008248a4u;
  }
  L005ce06c: { // 0x5ce06c: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005ce06e: { // 0x5ce06e: 7506 JNZ 0x005ce076
    if(integer::condition("JNZ",flags)) goto L005ce076;
  }
  L005ce070: { // 0x5ce070: 885c2410 MOV byte ptr [ESP + 0x10],BL
    m.w8((f.sp+0x00000010u), (s.bx & 0xffu));
  }
  L005ce074: { // 0x5ce074: eb18 JMP 0x005ce08e
    goto L005ce08e;
  }
  L005ce076: { // 0x5ce076: 6a18 PUSH 0x18
    f.push(m,0x00000018u);
  }
  L005ce078: { // 0x5ce078: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  L005ce07c: { // 0x5ce07c: 68a4488200 PUSH 0x8248a4
    f.push(m,0x008248a4u);
  }
  L005ce081: { // 0x5ce081: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005ce082: { // 0x5ce082: e889fc1900 CALL 0x0076dd10
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076dd10u,6086791u); flags=s.arithmetic_flags;
  }
  L005ce087: { // 0x5ce087: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L005ce08a: { // 0x5ce08a: 885c2428 MOV byte ptr [ESP + 0x28],BL
    m.w8((f.sp+0x00000028u), (s.bx & 0xffu));
  }
  L005ce08e: { // 0x5ce08e: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L005ce092: { // 0x5ce092: 8dbde3010000 LEA EDI,[EBP + 0x1e3]
    s.di = (s.bp+0x000001e3u);
  }
  L005ce098: { // 0x5ce098: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L005ce09a: { // 0x5ce09a: 740c JZ 0x005ce0a8
    if(integer::condition("JZ",flags)) goto L005ce0a8;
  }
  L005ce09c: { // 0x5ce09c: b906000000 MOV ECX,0x6
    s.cx = 0x00000006u;
  }
  L005ce0a1: { // 0x5ce0a1: 8d742410 LEA ESI,[ESP + 0x10]
    s.si = (f.sp+0x00000010u);
  }
  L005ce0a5: { // 0x5ce0a5: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L005ce0a7: { // 0x5ce0a7: a4 MOVSB ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::single);
  }
  L005ce0a8: { // 0x5ce0a8: a100aba500 MOV EAX,[0x00a5ab00]
    s.ax = m.r32((0x00a5ab00u));
  }
  L005ce0ad: { // 0x5ce0ad: 8b0d08aba500 MOV ECX,dword ptr [0x00a5ab08]
    s.cx = m.r32((0x00a5ab08u));
  }
  L005ce0b3: { // 0x5ce0b3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005ce0b4: { // 0x5ce0b4: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L005ce0b6: { // 0x5ce0b6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005ce0b7: { // 0x5ce0b7: 7c2c JL 0x005ce0e5
    if(integer::condition("JL",flags)) goto L005ce0e5;
  }
  L005ce0b9: { // 0x5ce0b9: 381d05aba500 CMP byte ptr [0x00a5ab05],BL
    (void)integer::sub(m.r8((0x00a5ab05u)),(s.bx & 0xffu),8,flags);
  }
  L005ce0bf: { // 0x5ce0bf: 7504 JNZ 0x005ce0c5
    if(integer::condition("JNZ",flags)) goto L005ce0c5;
  }
  L005ce0c1: { // 0x5ce0c1: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L005ce0c3: { // 0x5ce0c3: 7538 JNZ 0x005ce0fd
    if(integer::condition("JNZ",flags)) goto L005ce0fd;
  }
  L005ce0c5: { // 0x5ce0c5: 8b0d0caba500 MOV ECX,dword ptr [0x00a5ab0c]
    s.cx = m.r32((0x00a5ab0cu));
  }
  L005ce0cb: { // 0x5ce0cb: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L005ce0cd: { // 0x5ce0cd: 7e2e JLE 0x005ce0fd
    if(integer::condition("JLE",flags)) goto L005ce0fd;
  }
  L005ce0cf: { // 0x5ce0cf: 8b15f8aaa500 MOV EDX,dword ptr [0x00a5aaf8]
    s.dx = m.r32((0x00a5aaf8u));
  }
  L005ce0d5: { // 0x5ce0d5: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L005ce0d7: { // 0x5ce0d7: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005ce0d8: { // 0x5ce0d8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005ce0d9: { // 0x5ce0d9: b9f8aaa500 MOV ECX,0xa5aaf8
    s.cx = 0x00a5aaf8u;
  }
  L005ce0de: { // 0x5ce0de: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),6086881u); flags=s.arithmetic_flags;
  }
  L005ce0e1: { // 0x5ce0e1: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005ce0e3: { // 0x5ce0e3: 7418 JZ 0x005ce0fd
    if(integer::condition("JZ",flags)) goto L005ce0fd;
  }
  L005ce0e5: { // 0x5ce0e5: 8b0d08aba500 MOV ECX,dword ptr [0x00a5ab08]
    s.cx = m.r32((0x00a5ab08u));
  }
  L005ce0eb: { // 0x5ce0eb: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L005ce0ed: { // 0x5ce0ed: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L005ce0ee: { // 0x5ce0ee: 890d08aba500 MOV dword ptr [0x00a5ab08],ECX
    m.w32((0x00a5ab08u), s.cx);
  }
  L005ce0f4: { // 0x5ce0f4: 8b0dfcaaa500 MOV ECX,dword ptr [0x00a5aafc]
    s.cx = m.r32((0x00a5aafcu));
  }
  L005ce0fa: { // 0x5ce0fa: 892c81 MOV dword ptr [ECX + EAX*0x4],EBP
    m.w32((s.cx+(s.ax * 0x00000004u)), s.bp);
  }
  L005ce0fd: { // 0x5ce0fd: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L005ce0ff: { // 0x5ce0ff: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005ce100: { // 0x5ce100: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005ce101: { // 0x5ce101: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L005ce104: { // 0x5ce104: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00010580(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00410580: { // 0x410580: 83ec44 SUB ESP,0x44
    f.sp = integer::sub(f.sp,0x00000044u,32,flags);
  }
  L00410583: { // 0x410583: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00410584: { // 0x410584: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00410585: { // 0x410585: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00410586: { // 0x410586: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00410587: { // 0x410587: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L00410589: { // 0x410589: e882f9ffff CALL 0x0040ff10
    s.arithmetic_flags=flags; invoke(m,s,f,0x0040ff10u,4261262u); flags=s.arithmetic_flags;
  }
  L0041058e: { // 0x41058e: 8b442458 MOV EAX,dword ptr [ESP + 0x58]
    s.ax = m.r32((f.sp+0x00000058u));
  }
  L00410592: { // 0x410592: 8d5d24 LEA EBX,[EBP + 0x24]
    s.bx = (s.bp+0x00000024u);
  }
  L00410595: { // 0x410595: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00410597: { // 0x410597: c60300 MOV byte ptr [EBX],0x0
    m.w8((s.bx), 0x00000000u);
  }
  L0041059a: { // 0x41059a: c6453d00 MOV byte ptr [EBP + 0x3d],0x0
    m.w8((s.bp+0x0000003du), 0x00000000u);
  }
  L0041059e: { // 0x41059e: c6456400 MOV byte ptr [EBP + 0x64],0x0
    m.w8((s.bp+0x00000064u), 0x00000000u);
  }
  L004105a2: { // 0x4105a2: c74500885e7800 MOV dword ptr [EBP],0x785e88
    m.w32((s.bp), 0x00785e88u);
  }
  L004105a9: { // 0x4105a9: c745046c5e7800 MOV dword ptr [EBP + 0x4],0x785e6c
    m.w32((s.bp+0x00000004u), 0x00785e6cu);
  }
  L004105b0: { // 0x4105b0: c74508645e7800 MOV dword ptr [EBP + 0x8],0x785e64
    m.w32((s.bp+0x00000008u), 0x00785e64u);
  }
  L004105b7: { // 0x4105b7: c7450c5c5e7800 MOV dword ptr [EBP + 0xc],0x785e5c
    m.w32((s.bp+0x0000000cu), 0x00785e5cu);
  }
  L004105be: { // 0x4105be: 754d JNZ 0x0041060d
    if(integer::condition("JNZ",flags)) goto L0041060d;
  }
  L004105c0: { // 0x4105c0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004105c1: { // 0x4105c1: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L004105c5: { // 0x4105c5: 6810927b00 PUSH 0x7b9210
    f.push(m,0x007b9210u);
  }
  L004105ca: { // 0x4105ca: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004105cb: { // 0x4105cb: e864d43500 CALL 0x0076da34
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076da34u,4261328u); flags=s.arithmetic_flags;
  }
  L004105d0: { // 0x4105d0: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L004105d4: { // 0x4105d4: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L004105d7: { // 0x4105d7: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004105d9: { // 0x4105d9: 7506 JNZ 0x004105e1
    if(integer::condition("JNZ",flags)) goto L004105e1;
  }
  L004105db: { // 0x4105db: 884c2420 MOV byte ptr [ESP + 0x20],CL
    m.w8((f.sp+0x00000020u), (s.cx & 0xffu));
  }
  L004105df: { // 0x4105df: eb19 JMP 0x004105fa
    goto L004105fa;
  }
  L004105e1: { // 0x4105e1: 8d542410 LEA EDX,[ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  L004105e5: { // 0x4105e5: 6a18 PUSH 0x18
    f.push(m,0x00000018u);
  }
  L004105e7: { // 0x4105e7: 8d442424 LEA EAX,[ESP + 0x24]
    s.ax = (f.sp+0x00000024u);
  }
  L004105eb: { // 0x4105eb: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004105ec: { // 0x4105ec: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004105ed: { // 0x4105ed: e81ed73500 CALL 0x0076dd10
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076dd10u,4261362u); flags=s.arithmetic_flags;
  }
  L004105f2: { // 0x4105f2: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L004105f5: { // 0x4105f5: c644243800 MOV byte ptr [ESP + 0x38],0x0
    m.w8((f.sp+0x00000038u), 0x00000000u);
  }
  L004105fa: { // 0x4105fa: 8d4c2420 LEA ECX,[ESP + 0x20]
    s.cx = (f.sp+0x00000020u);
  }
  L004105fe: { // 0x4105fe: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L00410600: { // 0x410600: 7436 JZ 0x00410638
    if(integer::condition("JZ",flags)) goto L00410638;
  }
  L00410602: { // 0x410602: b906000000 MOV ECX,0x6
    s.cx = 0x00000006u;
  }
  L00410607: { // 0x410607: 8d742420 LEA ESI,[ESP + 0x20]
    s.si = (f.sp+0x00000020u);
  }
  L0041060b: { // 0x41060b: eb26 JMP 0x00410633
    goto L00410633;
  }
  L0041060d: { // 0x41060d: 6a18 PUSH 0x18
    f.push(m,0x00000018u);
  }
  L0041060f: { // 0x41060f: 8d542424 LEA EDX,[ESP + 0x24]
    s.dx = (f.sp+0x00000024u);
  }
  L00410613: { // 0x410613: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00410614: { // 0x410614: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00410615: { // 0x410615: e8f6d63500 CALL 0x0076dd10
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076dd10u,4261402u); flags=s.arithmetic_flags;
  }
  L0041061a: { // 0x41061a: 8d44242c LEA EAX,[ESP + 0x2c]
    s.ax = (f.sp+0x0000002cu);
  }
  L0041061e: { // 0x41061e: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00410621: { // 0x410621: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00410623: { // 0x410623: c644243800 MOV byte ptr [ESP + 0x38],0x0
    m.w8((f.sp+0x00000038u), 0x00000000u);
  }
  L00410628: { // 0x410628: 740e JZ 0x00410638
    if(integer::condition("JZ",flags)) goto L00410638;
  }
  L0041062a: { // 0x41062a: b906000000 MOV ECX,0x6
    s.cx = 0x00000006u;
  }
  L0041062f: { // 0x41062f: 8d742420 LEA ESI,[ESP + 0x20]
    s.si = (f.sp+0x00000020u);
  }
  L00410633: { // 0x410633: 8bfb MOV EDI,EBX
    s.di = s.bx;
  }
  L00410635: { // 0x410635: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L00410637: { // 0x410637: a4 MOVSB ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::single);
  }
  L00410638: { // 0x410638: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L0041063a: { // 0x41063a: 7506 JNZ 0x00410642
    if(integer::condition("JNZ",flags)) goto L00410642;
  }
  L0041063c: { // 0x41063c: 885c2420 MOV byte ptr [ESP + 0x20],BL
    m.w8((f.sp+0x00000020u), (s.bx & 0xffu));
  }
  L00410640: { // 0x410640: eb15 JMP 0x00410657
    goto L00410657;
  }
  L00410642: { // 0x410642: 6a30 PUSH 0x30
    f.push(m,0x00000030u);
  }
  L00410644: { // 0x410644: 8d4c2424 LEA ECX,[ESP + 0x24]
    s.cx = (f.sp+0x00000024u);
  }
  L00410648: { // 0x410648: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00410649: { // 0x410649: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0041064a: { // 0x41064a: e8c1d63500 CALL 0x0076dd10
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076dd10u,4261455u); flags=s.arithmetic_flags;
  }
  L0041064f: { // 0x41064f: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00410652: { // 0x410652: c644245000 MOV byte ptr [ESP + 0x50],0x0
    m.w8((f.sp+0x00000050u), 0x00000000u);
  }
  L00410657: { // 0x410657: 8d542420 LEA EDX,[ESP + 0x20]
    s.dx = (f.sp+0x00000020u);
  }
  L0041065b: { // 0x41065b: 8d7d64 LEA EDI,[EBP + 0x64]
    s.di = (s.bp+0x00000064u);
  }
  L0041065e: { // 0x41065e: 3bd7 CMP EDX,EDI
    (void)integer::sub(s.dx,s.di,32,flags);
  }
  L00410660: { // 0x410660: 740c JZ 0x0041066e
    if(integer::condition("JZ",flags)) goto L0041066e;
  }
  L00410662: { // 0x410662: b90c000000 MOV ECX,0xc
    s.cx = 0x0000000cu;
  }
  L00410667: { // 0x410667: 8d742420 LEA ESI,[ESP + 0x20]
    s.si = (f.sp+0x00000020u);
  }
  L0041066b: { // 0x41066b: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L0041066d: { // 0x41066d: a4 MOVSB ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::single);
  }
  L0041066e: { // 0x41066e: c745608c208200 MOV dword ptr [EBP + 0x60],0x82208c
    m.w32((s.bp+0x00000060u), 0x0082208cu);
  }
  L00410675: { // 0x410675: a18085a200 MOV EAX,[0x00a28580]
    s.ax = m.r32((0x00a28580u));
  }
  L0041067a: { // 0x41067a: 39058885a200 CMP dword ptr [0x00a28588],EAX
    (void)integer::sub(m.r32((0x00a28588u)),s.ax,32,flags);
  }
  L00410680: { // 0x410680: 7c2e JL 0x004106b0
    if(integer::condition("JL",flags)) goto L004106b0;
  }
  L00410682: { // 0x410682: 8a0d8585a200 MOV CL,byte ptr [0x00a28585]
    s.cx = with_al(s.cx, m.r8((0x00a28585u)));
  }
  L00410688: { // 0x410688: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0041068a: { // 0x41068a: 7504 JNZ 0x00410690
    if(integer::condition("JNZ",flags)) goto L00410690;
  }
  L0041068c: { // 0x41068c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0041068e: { // 0x41068e: 7538 JNZ 0x004106c8
    if(integer::condition("JNZ",flags)) goto L004106c8;
  }
  L00410690: { // 0x410690: 8b0d8c85a200 MOV ECX,dword ptr [0x00a2858c]
    s.cx = m.r32((0x00a2858cu));
  }
  L00410696: { // 0x410696: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00410698: { // 0x410698: 7e2e JLE 0x004106c8
    if(integer::condition("JLE",flags)) goto L004106c8;
  }
  L0041069a: { // 0x41069a: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0041069c: { // 0x41069c: a17885a200 MOV EAX,[0x00a28578]
    s.ax = m.r32((0x00a28578u));
  }
  L004106a1: { // 0x4106a1: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L004106a3: { // 0x4106a3: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004106a4: { // 0x4106a4: b97885a200 MOV ECX,0xa28578
    s.cx = 0x00a28578u;
  }
  L004106a9: { // 0x4106a9: ff5008 CALL dword ptr [EAX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000008u)),4261548u); flags=s.arithmetic_flags;
  }
  L004106ac: { // 0x4106ac: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004106ae: { // 0x4106ae: 7418 JZ 0x004106c8
    if(integer::condition("JZ",flags)) goto L004106c8;
  }
  L004106b0: { // 0x4106b0: 8b0d8885a200 MOV ECX,dword ptr [0x00a28588]
    s.cx = m.r32((0x00a28588u));
  }
  L004106b6: { // 0x4106b6: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004106b8: { // 0x4106b8: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L004106b9: { // 0x4106b9: 890d8885a200 MOV dword ptr [0x00a28588],ECX
    m.w32((0x00a28588u), s.cx);
  }
  L004106bf: { // 0x4106bf: 8b0d7c85a200 MOV ECX,dword ptr [0x00a2857c]
    s.cx = m.r32((0x00a2857cu));
  }
  L004106c5: { // 0x4106c5: 892c81 MOV dword ptr [ECX + EAX*0x4],EBP
    m.w32((s.cx+(s.ax * 0x00000004u)), s.bp);
  }
  L004106c8: { // 0x4106c8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004106c9: { // 0x4106c9: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L004106cb: { // 0x4106cb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004106cc: { // 0x4106cc: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004106cd: { // 0x4106cd: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004106ce: { // 0x4106ce: 83c444 ADD ESP,0x44
    f.sp = integer::add(f.sp,0x00000044u,32,flags);
  }
  L004106d1: { // 0x4106d1: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0000ffd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0040ffd0: { // 0x40ffd0: 8b0dc055a200 MOV ECX, dword ptr [0xa255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L0040ffd6: { // 0x40ffd6: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0040ffd8: { // 0x40ffd8: 750c JNZ 0x40ffe6
    if(integer::condition("JNZ",flags)) goto L0040ffe6;
  }
  L0040ffda: { // 0x40ffda: 8b4c2404 MOV ECX, dword ptr [ESP + 4]
    s.cx = m.r32((f.sp+4u));
  }
  L0040ffde: { // 0x40ffde: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0040ffe0: { // 0x40ffe0: 89410c MOV dword ptr [ECX + 0xc], EAX
    m.w32((s.cx+0x0000000cu), s.ax);
  }
  L0040ffe3: { // 0x40ffe3: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0040ffe6: { // 0x40ffe6: e835a12400 CALL 0x65a120
    s.arithmetic_flags=flags; invoke(m,s,f,0x0065a120u,4259819u); flags=s.arithmetic_flags;
  }
  L0040ffeb: { // 0x40ffeb: 8b542404 MOV EDX, dword ptr [ESP + 4]
    s.dx = m.r32((f.sp+4u));
  }
  L0040ffef: { // 0x40ffef: 89420c MOV dword ptr [EDX + 0xc], EAX
    m.w32((s.dx+0x0000000cu), s.ax);
  }
  L0040fff2: { // 0x40fff2: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0000ff10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0040ff10: { // 0x40ff10: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L0040ff12: { // 0x40ff12: 33c9 XOR ECX, ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0040ff14: { // 0x40ff14: c74008445e7800 MOV dword ptr [EAX + 8], 0x785e44
    m.w32((s.ax+8u), 0x00785e44u);
  }
  L0040ff1b: { // 0x40ff1b: c7400c3c5e7800 MOV dword ptr [EAX + 0xc], 0x785e3c
    m.w32((s.ax+0x0000000cu), 0x00785e3cu);
  }
  L0040ff22: { // 0x40ff22: 894818 MOV dword ptr [EAX + 0x18], ECX
    m.w32((s.ax+0x00000018u), s.cx);
  }
  L0040ff25: { // 0x40ff25: 89481c MOV dword ptr [EAX + 0x1c], ECX
    m.w32((s.ax+0x0000001cu), s.cx);
  }
  L0040ff28: { // 0x40ff28: 884820 MOV byte ptr [EAX + 0x20], CL
    m.w8((s.ax+0x00000020u), (s.cx & 0xffu));
  }
  L0040ff2b: { // 0x40ff2b: 8a4814 MOV CL, byte ptr [EAX + 0x14]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000014u)));
  }
  L0040ff2e: { // 0x40ff2e: 80e1f8 AND CL, 0xf8
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))&(0x000000f8u),8,flags));
  }
  L0040ff31: { // 0x40ff31: c74010ffffffff MOV dword ptr [EAX + 0x10], 0xffffffff
    m.w32((s.ax+0x00000010u), 0xffffffffu);
  }
  L0040ff38: { // 0x40ff38: c700d85d7800 MOV dword ptr [EAX], 0x785dd8
    m.w32((s.ax), 0x00785dd8u);
  }
  L0040ff3e: { // 0x40ff3e: c74004bc5d7800 MOV dword ptr [EAX + 4], 0x785dbc
    m.w32((s.ax+4u), 0x00785dbcu);
  }
  L0040ff45: { // 0x40ff45: c74008b45d7800 MOV dword ptr [EAX + 8], 0x785db4
    m.w32((s.ax+8u), 0x00785db4u);
  }
  L0040ff4c: { // 0x40ff4c: c7400cac5d7800 MOV dword ptr [EAX + 0xc], 0x785dac
    m.w32((s.ax+0x0000000cu), 0x00785dacu);
  }
  L0040ff53: { // 0x40ff53: 884814 MOV byte ptr [EAX + 0x14], CL
    m.w8((s.ax+0x00000014u), (s.cx & 0xffu));
  }
  L0040ff56: { // 0x40ff56: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0036dd10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0076dd10: { // 0x76dd10: 8b4c240c MOV ECX, dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L0076dd14: { // 0x76dd14: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0076dd15: { // 0x76dd15: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0076dd17: { // 0x76dd17: 747a JZ 0x76dd93
    if(integer::condition("JZ",flags)) goto L0076dd93;
  }
  L0076dd19: { // 0x76dd19: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0076dd1a: { // 0x76dd1a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0076dd1b: { // 0x76dd1b: 8bd9 MOV EBX, ECX
    s.bx = s.cx;
  }
  L0076dd1d: { // 0x76dd1d: 8b742414 MOV ESI, dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L0076dd21: { // 0x76dd21: f7c603000000 TEST ESI, 3
    (void)integer::logical((s.si)&(3u),32,flags);
  }
  L0076dd27: { // 0x76dd27: 8b7c2410 MOV EDI, dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L0076dd2b: { // 0x76dd2b: 7507 JNZ 0x76dd34
    if(integer::condition("JNZ",flags)) goto L0076dd34;
  }
  L0076dd2d: { // 0x76dd2d: c1e902 SHR ECX, 2
    s.cx = integer::shift(s.cx,2u,32,flags,integer::Shift::right);
  }
  L0076dd30: { // 0x76dd30: 756f JNZ 0x76dda1
    if(integer::condition("JNZ",flags)) goto L0076dda1;
  }
  L0076dd32: { // 0x76dd32: eb21 JMP 0x76dd55
    goto L0076dd55;
  }
  L0076dd34: { // 0x76dd34: 8a06 MOV AL, byte ptr [ESI]
    s.ax = with_al(s.ax, m.r8((s.si)));
  }
  L0076dd36: { // 0x76dd36: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0076dd37: { // 0x76dd37: 8807 MOV byte ptr [EDI], AL
    m.w8((s.di), (s.ax & 0xffu));
  }
  L0076dd39: { // 0x76dd39: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0076dd3a: { // 0x76dd3a: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0076dd3b: { // 0x76dd3b: 7425 JZ 0x76dd62
    if(integer::condition("JZ",flags)) goto L0076dd62;
  }
  L0076dd3d: { // 0x76dd3d: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0076dd3f: { // 0x76dd3f: 7429 JZ 0x76dd6a
    if(integer::condition("JZ",flags)) goto L0076dd6a;
  }
  L0076dd41: { // 0x76dd41: f7c603000000 TEST ESI, 3
    (void)integer::logical((s.si)&(3u),32,flags);
  }
  L0076dd47: { // 0x76dd47: 75eb JNZ 0x76dd34
    if(integer::condition("JNZ",flags)) goto L0076dd34;
  }
  L0076dd49: { // 0x76dd49: 8bd9 MOV EBX, ECX
    s.bx = s.cx;
  }
  L0076dd4b: { // 0x76dd4b: c1e902 SHR ECX, 2
    s.cx = integer::shift(s.cx,2u,32,flags,integer::Shift::right);
  }
  L0076dd4e: { // 0x76dd4e: 7551 JNZ 0x76dda1
    if(integer::condition("JNZ",flags)) goto L0076dda1;
  }
  L0076dd50: { // 0x76dd50: 83e303 AND EBX, 3
    s.bx = integer::logical((s.bx)&(3u),32,flags);
  }
  L0076dd53: { // 0x76dd53: 740d JZ 0x76dd62
    if(integer::condition("JZ",flags)) goto L0076dd62;
  }
  L0076dd55: { // 0x76dd55: 8a06 MOV AL, byte ptr [ESI]
    s.ax = with_al(s.ax, m.r8((s.si)));
  }
  L0076dd57: { // 0x76dd57: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0076dd58: { // 0x76dd58: 8807 MOV byte ptr [EDI], AL
    m.w8((s.di), (s.ax & 0xffu));
  }
  L0076dd5a: { // 0x76dd5a: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0076dd5b: { // 0x76dd5b: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0076dd5d: { // 0x76dd5d: 742f JZ 0x76dd8e
    if(integer::condition("JZ",flags)) goto L0076dd8e;
  }
  L0076dd5f: { // 0x76dd5f: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L0076dd60: { // 0x76dd60: 75f3 JNZ 0x76dd55
    if(integer::condition("JNZ",flags)) goto L0076dd55;
  }
  L0076dd62: { // 0x76dd62: 8b442410 MOV EAX, dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0076dd66: { // 0x76dd66: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0076dd67: { // 0x76dd67: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076dd68: { // 0x76dd68: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076dd69: { // 0x76dd69: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076dd6a: { // 0x76dd6a: f7c703000000 TEST EDI, 3
    (void)integer::logical((s.di)&(3u),32,flags);
  }
  L0076dd70: { // 0x76dd70: 7412 JZ 0x76dd84
    if(integer::condition("JZ",flags)) goto L0076dd84;
  }
  L0076dd72: { // 0x76dd72: 8807 MOV byte ptr [EDI], AL
    m.w8((s.di), (s.ax & 0xffu));
  }
  L0076dd74: { // 0x76dd74: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0076dd75: { // 0x76dd75: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0076dd76: { // 0x76dd76: 0f848a000000 JZ 0x76de06
    if(integer::condition("JZ",flags)) goto L0076de06;
  }
  L0076dd7c: { // 0x76dd7c: f7c703000000 TEST EDI, 3
    (void)integer::logical((s.di)&(3u),32,flags);
  }
  L0076dd82: { // 0x76dd82: 75ee JNZ 0x76dd72
    if(integer::condition("JNZ",flags)) goto L0076dd72;
  }
  L0076dd84: { // 0x76dd84: 8bd9 MOV EBX, ECX
    s.bx = s.cx;
  }
  L0076dd86: { // 0x76dd86: c1e902 SHR ECX, 2
    s.cx = integer::shift(s.cx,2u,32,flags,integer::Shift::right);
  }
  L0076dd89: { // 0x76dd89: 756c JNZ 0x76ddf7
    if(integer::condition("JNZ",flags)) goto L0076ddf7;
  }
  L0076dd8b: { // 0x76dd8b: 8807 MOV byte ptr [EDI], AL
    m.w8((s.di), (s.ax & 0xffu));
  }
  L0076dd8d: { // 0x76dd8d: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0076dd8e: { // 0x76dd8e: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L0076dd8f: { // 0x76dd8f: 75fa JNZ 0x76dd8b
    if(integer::condition("JNZ",flags)) goto L0076dd8b;
  }
  L0076dd91: { // 0x76dd91: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0076dd92: { // 0x76dd92: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076dd93: { // 0x76dd93: 8b442408 MOV EAX, dword ptr [ESP + 8]
    s.ax = m.r32((f.sp+8u));
  }
  L0076dd97: { // 0x76dd97: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076dd98: { // 0x76dd98: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076dd99: { // 0x76dd99: 8917 MOV dword ptr [EDI], EDX
    m.w32((s.di), s.dx);
  }
  L0076dd9b: { // 0x76dd9b: 83c704 ADD EDI, 4
    s.di = integer::add(s.di,4u,32,flags);
  }
  L0076dd9e: { // 0x76dd9e: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0076dd9f: { // 0x76dd9f: 74af JZ 0x76dd50
    if(integer::condition("JZ",flags)) goto L0076dd50;
  }
  L0076dda1: { // 0x76dda1: bafffefe7e MOV EDX, 0x7efefeff
    s.dx = 0x7efefeffu;
  }
  L0076dda6: { // 0x76dda6: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0076dda8: { // 0x76dda8: 03d0 ADD EDX, EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L0076ddaa: { // 0x76ddaa: 83f0ff XOR EAX, 0xffffffff
    s.ax = integer::logical((s.ax)^(0xffffffffu),32,flags);
  }
  L0076ddad: { // 0x76ddad: 33c2 XOR EAX, EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L0076ddaf: { // 0x76ddaf: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0076ddb1: { // 0x76ddb1: 83c604 ADD ESI, 4
    s.si = integer::add(s.si,4u,32,flags);
  }
  L0076ddb4: { // 0x76ddb4: a900010181 TEST EAX, 0x81010100
    (void)integer::logical((s.ax)&(0x81010100u),32,flags);
  }
  L0076ddb9: { // 0x76ddb9: 74de JZ 0x76dd99
    if(integer::condition("JZ",flags)) goto L0076dd99;
  }
  L0076ddbb: { // 0x76ddbb: 84d2 TEST DL, DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L0076ddbd: { // 0x76ddbd: 742c JZ 0x76ddeb
    if(integer::condition("JZ",flags)) goto L0076ddeb;
  }
  L0076ddbf: { // 0x76ddbf: 84f6 TEST DH, DH
    (void)integer::logical((((s.dx >> 8) & 0xffu))&(((s.dx >> 8) & 0xffu)),8,flags);
  }
  L0076ddc1: { // 0x76ddc1: 741e JZ 0x76dde1
    if(integer::condition("JZ",flags)) goto L0076dde1;
  }
  L0076ddc3: { // 0x76ddc3: f7c20000ff00 TEST EDX, 0xff0000
    (void)integer::logical((s.dx)&(0x00ff0000u),32,flags);
  }
  L0076ddc9: { // 0x76ddc9: 740c JZ 0x76ddd7
    if(integer::condition("JZ",flags)) goto L0076ddd7;
  }
  L0076ddcb: { // 0x76ddcb: f7c2000000ff TEST EDX, 0xff000000
    (void)integer::logical((s.dx)&(0xff000000u),32,flags);
  }
  L0076ddd1: { // 0x76ddd1: 75c6 JNZ 0x76dd99
    if(integer::condition("JNZ",flags)) goto L0076dd99;
  }
  L0076ddd3: { // 0x76ddd3: 8917 MOV dword ptr [EDI], EDX
    m.w32((s.di), s.dx);
  }
  L0076ddd5: { // 0x76ddd5: eb18 JMP 0x76ddef
    goto L0076ddef;
  }
  L0076ddd7: { // 0x76ddd7: 81e2ffff0000 AND EDX, 0xffff
    s.dx = integer::logical((s.dx)&(0x0000ffffu),32,flags);
  }
  L0076dddd: { // 0x76dddd: 8917 MOV dword ptr [EDI], EDX
    m.w32((s.di), s.dx);
  }
  L0076dddf: { // 0x76dddf: eb0e JMP 0x76ddef
    goto L0076ddef;
  }
  L0076dde1: { // 0x76dde1: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0076dde7: { // 0x76dde7: 8917 MOV dword ptr [EDI], EDX
    m.w32((s.di), s.dx);
  }
  L0076dde9: { // 0x76dde9: eb04 JMP 0x76ddef
    goto L0076ddef;
  }
  L0076ddeb: { // 0x76ddeb: 33d2 XOR EDX, EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0076dded: { // 0x76dded: 8917 MOV dword ptr [EDI], EDX
    m.w32((s.di), s.dx);
  }
  L0076ddef: { // 0x76ddef: 83c704 ADD EDI, 4
    s.di = integer::add(s.di,4u,32,flags);
  }
  L0076ddf2: { // 0x76ddf2: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0076ddf4: { // 0x76ddf4: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0076ddf5: { // 0x76ddf5: 740a JZ 0x76de01
    if(integer::condition("JZ",flags)) goto L0076de01;
  }
  L0076ddf7: { // 0x76ddf7: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0076ddf9: { // 0x76ddf9: 8907 MOV dword ptr [EDI], EAX
    m.w32((s.di), s.ax);
  }
  L0076ddfb: { // 0x76ddfb: 83c704 ADD EDI, 4
    s.di = integer::add(s.di,4u,32,flags);
  }
  L0076ddfe: { // 0x76ddfe: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0076ddff: { // 0x76ddff: 75f8 JNZ 0x76ddf9
    if(integer::condition("JNZ",flags)) goto L0076ddf9;
  }
  L0076de01: { // 0x76de01: 83e303 AND EBX, 3
    s.bx = integer::logical((s.bx)&(3u),32,flags);
  }
  L0076de04: { // 0x76de04: 7585 JNZ 0x76dd8b
    if(integer::condition("JNZ",flags)) goto L0076dd8b;
  }
  L0076de06: { // 0x76de06: 8b442410 MOV EAX, dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0076de0a: { // 0x76de0a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0076de0b: { // 0x76de0b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076de0c: { // 0x76de0c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076de0d: { // 0x76de0d: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}


} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 6086272u:f_001cde80(m,s,child,{});break;
case 4261248u:f_00010580(m,s,child,{});break;
case 4259792u:f_0000ffd0(m,s,child,{});break;
case 4259600u:f_0000ff10(m,s,child,{});break;
case 7789840u:f_0036dd10(m,s,child,{});break;
default:throw std::domain_error("recovery622 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00618190(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00618190: { // 0x618190: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L00618194: { // 0x618194: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00618195: { // 0x618195: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00618196: { // 0x618196: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00618198: { // 0x618198: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00618199: { // 0x618199: e8e25cfbff CALL 0x005cde80
    s.arithmetic_flags=flags; invoke(m,s,f,0x005cde80u,6390174u); flags=s.arithmetic_flags;
  }
  L0061819e: { // 0x61819e: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L006181a1: { // 0x6181a1: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L006181a3: { // 0x6181a3: 898664020000 MOV dword ptr [ESI + 0x264],EAX
    m.w32((s.si+0x00000264u), s.ax);
  }
  L006181a9: { // 0x6181a9: 898684020000 MOV dword ptr [ESI + 0x284],EAX
    m.w32((s.si+0x00000284u), s.ax);
  }
  L006181af: { // 0x6181af: 898688020000 MOV dword ptr [ESI + 0x288],EAX
    m.w32((s.si+0x00000288u), s.ax);
  }
  L006181b5: { // 0x6181b5: 889e68020000 MOV byte ptr [ESI + 0x268],BL
    m.w8((s.si+0x00000268u), (s.bx & 0xffu));
  }
  L006181bb: { // 0x6181bb: c7866c02000001000000 MOV dword ptr [ESI + 0x26c],0x1
    m.w32((s.si+0x0000026cu), 0x00000001u);
  }
  L006181c5: { // 0x6181c5: 899e70020000 MOV dword ptr [ESI + 0x270],EBX
    m.w32((s.si+0x00000270u), s.bx);
  }
  L006181cb: { // 0x6181cb: c7867402000032000000 MOV dword ptr [ESI + 0x274],0x32
    m.w32((s.si+0x00000274u), 0x00000032u);
  }
  L006181d5: { // 0x6181d5: 899e78020000 MOV dword ptr [ESI + 0x278],EBX
    m.w32((s.si+0x00000278u), s.bx);
  }
  L006181db: { // 0x6181db: 899e7c020000 MOV dword ptr [ESI + 0x27c],EBX
    m.w32((s.si+0x0000027cu), s.bx);
  }
  L006181e1: { // 0x6181e1: 899e80020000 MOV dword ptr [ESI + 0x280],EBX
    m.w32((s.si+0x00000280u), s.bx);
  }
  L006181e7: { // 0x6181e7: b89a999999 MOV EAX,0x9999999a
    s.ax = 0x9999999au;
  }
  L006181ec: { // 0x6181ec: 899e8c020000 MOV dword ptr [ESI + 0x28c],EBX
    m.w32((s.si+0x0000028cu), s.bx);
  }
  L006181f2: { // 0x6181f2: 899e90020000 MOV dword ptr [ESI + 0x290],EBX
    m.w32((s.si+0x00000290u), s.bx);
  }
  L006181f8: { // 0x6181f8: 899e94020000 MOV dword ptr [ESI + 0x294],EBX
    m.w32((s.si+0x00000294u), s.bx);
  }
  L006181fe: { // 0x6181fe: 898698020000 MOV dword ptr [ESI + 0x298],EAX
    m.w32((s.si+0x00000298u), s.ax);
  }
  L00618204: { // 0x618204: 8986a0020000 MOV dword ptr [ESI + 0x2a0],EAX
    m.w32((s.si+0x000002a0u), s.ax);
  }
  L0061820a: { // 0x61820a: 899ea8020000 MOV dword ptr [ESI + 0x2a8],EBX
    m.w32((s.si+0x000002a8u), s.bx);
  }
  L00618210: { // 0x618210: 899eb0020000 MOV dword ptr [ESI + 0x2b0],EBX
    m.w32((s.si+0x000002b0u), s.bx);
  }
  L00618216: { // 0x618216: 899eb8020000 MOV dword ptr [ESI + 0x2b8],EBX
    m.w32((s.si+0x000002b8u), s.bx);
  }
  L0061821c: { // 0x61821c: 899ec0020000 MOV dword ptr [ESI + 0x2c0],EBX
    m.w32((s.si+0x000002c0u), s.bx);
  }
  L00618222: { // 0x618222: 899ec8020000 MOV dword ptr [ESI + 0x2c8],EBX
    m.w32((s.si+0x000002c8u), s.bx);
  }
  L00618228: { // 0x618228: 8d4604 LEA EAX,[ESI + 0x4]
    s.ax = (s.si+0x00000004u);
  }
  L0061822b: { // 0x61822b: c7869c0200009999b93f MOV dword ptr [ESI + 0x29c],0x3fb99999
    m.w32((s.si+0x0000029cu), 0x3fb99999u);
  }
  L00618235: { // 0x618235: c786a40200009999993f MOV dword ptr [ESI + 0x2a4],0x3f999999
    m.w32((s.si+0x000002a4u), 0x3f999999u);
  }
  L0061823f: { // 0x61823f: c786ac02000000003940 MOV dword ptr [ESI + 0x2ac],0x40390000
    m.w32((s.si+0x000002acu), 0x40390000u);
  }
  L00618249: { // 0x618249: 899eb4020000 MOV dword ptr [ESI + 0x2b4],EBX
    m.w32((s.si+0x000002b4u), s.bx);
  }
  L0061824f: { // 0x61824f: 899ebc020000 MOV dword ptr [ESI + 0x2bc],EBX
    m.w32((s.si+0x000002bcu), s.bx);
  }
  L00618255: { // 0x618255: 899ec4020000 MOV dword ptr [ESI + 0x2c4],EBX
    m.w32((s.si+0x000002c4u), s.bx);
  }
  L0061825b: { // 0x61825b: 899ecc020000 MOV dword ptr [ESI + 0x2cc],EBX
    m.w32((s.si+0x000002ccu), s.bx);
  }
  L00618261: { // 0x618261: 899ed0020000 MOV dword ptr [ESI + 0x2d0],EBX
    m.w32((s.si+0x000002d0u), s.bx);
  }
  L00618267: { // 0x618267: 899ed4020000 MOV dword ptr [ESI + 0x2d4],EBX
    m.w32((s.si+0x000002d4u), s.bx);
  }
  L0061826d: { // 0x61826d: 889ed8020000 MOV byte ptr [ESI + 0x2d8],BL
    m.w8((s.si+0x000002d8u), (s.bx & 0xffu));
  }
  L00618273: { // 0x618273: 889ed9020000 MOV byte ptr [ESI + 0x2d9],BL
    m.w8((s.si+0x000002d9u), (s.bx & 0xffu));
  }
  L00618279: { // 0x618279: 889eda020000 MOV byte ptr [ESI + 0x2da],BL
    m.w8((s.si+0x000002dau), (s.bx & 0xffu));
  }
  L0061827f: { // 0x61827f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00618280: { // 0x618280: 889edb020000 MOV byte ptr [ESI + 0x2db],BL
    m.w8((s.si+0x000002dbu), (s.bx & 0xffu));
  }
  L00618286: { // 0x618286: 889edc020000 MOV byte ptr [ESI + 0x2dc],BL
    m.w8((s.si+0x000002dcu), (s.bx & 0xffu));
  }
  L0061828c: { // 0x61828c: c70640347900 MOV dword ptr [ESI],0x793440
    m.w32((s.si), 0x00793440u);
  }
  L00618292: { // 0x618292: c70024347900 MOV dword ptr [EAX],0x793424
    m.w32((s.ax), 0x00793424u);
  }
  L00618298: { // 0x618298: c746081c347900 MOV dword ptr [ESI + 0x8],0x79341c
    m.w32((s.si+0x00000008u), 0x0079341cu);
  }
  L0061829f: { // 0x61829f: c7460c14347900 MOV dword ptr [ESI + 0xc],0x793414
    m.w32((s.si+0x0000000cu), 0x00793414u);
  }
  L006182a6: { // 0x6182a6: e8257ddfff CALL 0x0040ffd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0040ffd0u,6390443u); flags=s.arithmetic_flags;
  }
  L006182ab: { // 0x6182ab: a108e1a100 MOV EAX,[0x00a1e108]
    s.ax = m.r32((0x00a1e108u));
  }
  L006182b0: { // 0x6182b0: 8b0d10e1a100 MOV ECX,dword ptr [0x00a1e110]
    s.cx = m.r32((0x00a1e110u));
  }
  L006182b6: { // 0x6182b6: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L006182b8: { // 0x6182b8: 7c2c JL 0x006182e6
    if(integer::condition("JL",flags)) goto L006182e6;
  }
  L006182ba: { // 0x6182ba: 381d0de1a100 CMP byte ptr [0x00a1e10d],BL
    (void)integer::sub(m.r8((0x00a1e10du)),(s.bx & 0xffu),8,flags);
  }
  L006182c0: { // 0x6182c0: 7504 JNZ 0x006182c6
    if(integer::condition("JNZ",flags)) goto L006182c6;
  }
  L006182c2: { // 0x6182c2: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L006182c4: { // 0x6182c4: 7538 JNZ 0x006182fe
    if(integer::condition("JNZ",flags)) goto L006182fe;
  }
  L006182c6: { // 0x6182c6: 8b0d14e1a100 MOV ECX,dword ptr [0x00a1e114]
    s.cx = m.r32((0x00a1e114u));
  }
  L006182cc: { // 0x6182cc: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L006182ce: { // 0x6182ce: 7e2e JLE 0x006182fe
    if(integer::condition("JLE",flags)) goto L006182fe;
  }
  L006182d0: { // 0x6182d0: 8b1500e1a100 MOV EDX,dword ptr [0x00a1e100]
    s.dx = m.r32((0x00a1e100u));
  }
  L006182d6: { // 0x6182d6: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L006182d8: { // 0x6182d8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006182d9: { // 0x6182d9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006182da: { // 0x6182da: b900e1a100 MOV ECX,0xa1e100
    s.cx = 0x00a1e100u;
  }
  L006182df: { // 0x6182df: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),6390498u); flags=s.arithmetic_flags;
  }
  L006182e2: { // 0x6182e2: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006182e4: { // 0x6182e4: 7418 JZ 0x006182fe
    if(integer::condition("JZ",flags)) goto L006182fe;
  }
  L006182e6: { // 0x6182e6: 8b0d10e1a100 MOV ECX,dword ptr [0x00a1e110]
    s.cx = m.r32((0x00a1e110u));
  }
  L006182ec: { // 0x6182ec: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L006182ee: { // 0x6182ee: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L006182ef: { // 0x6182ef: 890d10e1a100 MOV dword ptr [0x00a1e110],ECX
    m.w32((0x00a1e110u), s.cx);
  }
  L006182f5: { // 0x6182f5: 8b0d04e1a100 MOV ECX,dword ptr [0x00a1e104]
    s.cx = m.r32((0x00a1e104u));
  }
  L006182fb: { // 0x6182fb: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L006182fe: { // 0x6182fe: c6860402000001 MOV byte ptr [ESI + 0x204],0x1
    m.w8((s.si+0x00000204u), 0x00000001u);
  }
  L00618305: { // 0x618305: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00618307: { // 0x618307: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00618308: { // 0x618308: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00618309: { // 0x618309: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_0067d4d0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0067d4d0: { // 0x67d4d0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L0067d4d4: { // 0x67d4d4: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0067d4d5: { // 0x67d4d5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0067d4d6: { // 0x67d4d6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0067d4d8: { // 0x67d4d8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0067d4d9: { // 0x67d4d9: e8a209f5ff CALL 0x005cde80
    s.arithmetic_flags=flags; invoke(m,s,f,0x005cde80u,6804702u); flags=s.arithmetic_flags;
  }
  L0067d4de: { // 0x67d4de: 8d4604 LEA EAX,[ESI + 0x4]
    s.ax = (s.si+0x00000004u);
  }
  L0067d4e1: { // 0x67d4e1: bb01000000 MOV EBX,0x1
    s.bx = 0x00000001u;
  }
  L0067d4e6: { // 0x67d4e6: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0067d4e7: { // 0x67d4e7: c78664020000ffffffff MOV dword ptr [ESI + 0x264],0xffffffff
    m.w32((s.si+0x00000264u), 0xffffffffu);
  }
  L0067d4f1: { // 0x67d4f1: 899e68020000 MOV dword ptr [ESI + 0x268],EBX
    m.w32((s.si+0x00000268u), s.bx);
  }
  L0067d4f7: { // 0x67d4f7: 899e6c020000 MOV dword ptr [ESI + 0x26c],EBX
    m.w32((s.si+0x0000026cu), s.bx);
  }
  L0067d4fd: { // 0x67d4fd: c6867002000000 MOV byte ptr [ESI + 0x270],0x0
    m.w8((s.si+0x00000270u), 0x00000000u);
  }
  L0067d504: { // 0x67d504: c6867102000000 MOV byte ptr [ESI + 0x271],0x0
    m.w8((s.si+0x00000271u), 0x00000000u);
  }
  L0067d50b: { // 0x67d50b: c70648667900 MOV dword ptr [ESI],0x796648
    m.w32((s.si), 0x00796648u);
  }
  L0067d511: { // 0x67d511: c7002c667900 MOV dword ptr [EAX],0x79662c
    m.w32((s.ax), 0x0079662cu);
  }
  L0067d517: { // 0x67d517: c7460824667900 MOV dword ptr [ESI + 0x8],0x796624
    m.w32((s.si+0x00000008u), 0x00796624u);
  }
  L0067d51e: { // 0x67d51e: c7460c1c667900 MOV dword ptr [ESI + 0xc],0x79661c
    m.w32((s.si+0x0000000cu), 0x0079661cu);
  }
  L0067d525: { // 0x67d525: e8a62ad9ff CALL 0x0040ffd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0040ffd0u,6804778u); flags=s.arithmetic_flags;
  }
  L0067d52a: { // 0x67d52a: 889eff010000 MOV byte ptr [ESI + 0x1ff],BL
    m.w8((s.si+0x000001ffu), (s.bx & 0xffu));
  }
  L0067d530: { // 0x67d530: c6860002000000 MOV byte ptr [ESI + 0x200],0x0
    m.w8((s.si+0x00000200u), 0x00000000u);
  }
  L0067d537: { // 0x67d537: c6860102000000 MOV byte ptr [ESI + 0x201],0x0
    m.w8((s.si+0x00000201u), 0x00000000u);
  }
  L0067d53e: { // 0x67d53e: 889e02020000 MOV byte ptr [ESI + 0x202],BL
    m.w8((s.si+0x00000202u), (s.bx & 0xffu));
  }
  L0067d544: { // 0x67d544: 889e03020000 MOV byte ptr [ESI + 0x203],BL
    m.w8((s.si+0x00000203u), (s.bx & 0xffu));
  }
  L0067d54a: { // 0x67d54a: c6860502000000 MOV byte ptr [ESI + 0x205],0x0
    m.w8((s.si+0x00000205u), 0x00000000u);
  }
  L0067d551: { // 0x67d551: a11888a200 MOV EAX,[0x00a28818]
    s.ax = m.r32((0x00a28818u));
  }
  L0067d556: { // 0x67d556: 8b0d1088a200 MOV ECX,dword ptr [0x00a28810]
    s.cx = m.r32((0x00a28810u));
  }
  L0067d55c: { // 0x67d55c: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0067d55e: { // 0x67d55e: 7c34 JL 0x0067d594
    if(integer::condition("JL",flags)) goto L0067d594;
  }
  L0067d560: { // 0x67d560: 8a151588a200 MOV DL,byte ptr [0x00a28815]
    s.dx = with_al(s.dx, m.r8((0x00a28815u)));
  }
  L0067d566: { // 0x67d566: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L0067d568: { // 0x67d568: 7504 JNZ 0x0067d56e
    if(integer::condition("JNZ",flags)) goto L0067d56e;
  }
  L0067d56a: { // 0x67d56a: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0067d56c: { // 0x67d56c: 753b JNZ 0x0067d5a9
    if(integer::condition("JNZ",flags)) goto L0067d5a9;
  }
  L0067d56e: { // 0x67d56e: 8b151c88a200 MOV EDX,dword ptr [0x00a2881c]
    s.dx = m.r32((0x00a2881cu));
  }
  L0067d574: { // 0x67d574: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0067d576: { // 0x67d576: 7e31 JLE 0x0067d5a9
    if(integer::condition("JLE",flags)) goto L0067d5a9;
  }
  L0067d578: { // 0x67d578: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L0067d57a: { // 0x67d57a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0067d57c: { // 0x67d57c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0067d57d: { // 0x67d57d: 8b150888a200 MOV EDX,dword ptr [0x00a28808]
    s.dx = m.r32((0x00a28808u));
  }
  L0067d583: { // 0x67d583: b90888a200 MOV ECX,0xa28808
    s.cx = 0x00a28808u;
  }
  L0067d588: { // 0x67d588: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),6804875u); flags=s.arithmetic_flags;
  }
  L0067d58b: { // 0x67d58b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0067d58d: { // 0x67d58d: a11888a200 MOV EAX,[0x00a28818]
    s.ax = m.r32((0x00a28818u));
  }
  L0067d592: { // 0x67d592: 7415 JZ 0x0067d5a9
    if(integer::condition("JZ",flags)) goto L0067d5a9;
  }
  L0067d594: { // 0x67d594: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0067d596: { // 0x67d596: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0067d597: { // 0x67d597: a31888a200 MOV [0x00a28818],EAX
    m.w32((0x00a28818u), s.ax);
  }
  L0067d59c: { // 0x67d59c: a10c88a200 MOV EAX,[0x00a2880c]
    s.ax = m.r32((0x00a2880cu));
  }
  L0067d5a1: { // 0x67d5a1: 893488 MOV dword ptr [EAX + ECX*0x4],ESI
    m.w32((s.ax+(s.cx * 0x00000004u)), s.si);
  }
  L0067d5a4: { // 0x67d5a4: a11888a200 MOV EAX,[0x00a28818]
    s.ax = m.r32((0x00a28818u));
  }
  L0067d5a9: { // 0x67d5a9: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0067d5ab: { // 0x67d5ab: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0067d5ad: { // 0x67d5ad: 7e12 JLE 0x0067d5c1
    if(integer::condition("JLE",flags)) goto L0067d5c1;
  }
  L0067d5af: { // 0x67d5af: 8b150c88a200 MOV EDX,dword ptr [0x00a2880c]
    s.dx = m.r32((0x00a2880cu));
  }
  L0067d5b5: { // 0x67d5b5: 3932 CMP dword ptr [EDX],ESI
    (void)integer::sub(m.r32((s.dx)),s.si,32,flags);
  }
  L0067d5b7: { // 0x67d5b7: 7418 JZ 0x0067d5d1
    if(integer::condition("JZ",flags)) goto L0067d5d1;
  }
  L0067d5b9: { // 0x67d5b9: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0067d5ba: { // 0x67d5ba: 83c204 ADD EDX,0x4
    s.dx = integer::add(s.dx,0x00000004u,32,flags);
  }
  L0067d5bd: { // 0x67d5bd: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L0067d5bf: { // 0x67d5bf: 7cf4 JL 0x0067d5b5
    if(integer::condition("JL",flags)) goto L0067d5b5;
  }
  L0067d5c1: { // 0x67d5c1: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L0067d5c4: { // 0x67d5c4: 898664020000 MOV dword ptr [ESI + 0x264],EAX
    m.w32((s.si+0x00000264u), s.ax);
  }
  L0067d5ca: { // 0x67d5ca: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0067d5cc: { // 0x67d5cc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0067d5cd: { // 0x67d5cd: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0067d5ce: { // 0x67d5ce: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0067d5d1: { // 0x67d5d1: 898e64020000 MOV dword ptr [ESI + 0x264],ECX
    m.w32((s.si+0x00000264u), s.cx);
  }
  L0067d5d7: { // 0x67d5d7: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0067d5d9: { // 0x67d5d9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0067d5da: { // 0x67d5da: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0067d5db: { // 0x67d5db: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_006da520(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006da520: { // 0x6da520: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L006da524: { // 0x6da524: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006da525: { // 0x6da525: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006da526: { // 0x6da526: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006da528: { // 0x6da528: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006da529: { // 0x6da529: e85239efff CALL 0x005cde80
    s.arithmetic_flags=flags; invoke(m,s,f,0x005cde80u,7185710u); flags=s.arithmetic_flags;
  }
  L006da52e: { // 0x6da52e: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L006da530: { // 0x6da530: c78664020000ffffffff MOV dword ptr [ESI + 0x264],0xffffffff
    m.w32((s.si+0x00000264u), 0xffffffffu);
  }
  L006da53a: { // 0x6da53a: 899e68020000 MOV dword ptr [ESI + 0x268],EBX
    m.w32((s.si+0x00000268u), s.bx);
  }
  L006da540: { // 0x6da540: b807000000 MOV EAX,0x7
    s.ax = 0x00000007u;
  }
  L006da545: { // 0x6da545: 889e6c020000 MOV byte ptr [ESI + 0x26c],BL
    m.w8((s.si+0x0000026cu), (s.bx & 0xffu));
  }
  L006da54b: { // 0x6da54b: 889e6d020000 MOV byte ptr [ESI + 0x26d],BL
    m.w8((s.si+0x0000026du), (s.bx & 0xffu));
  }
  L006da551: { // 0x6da551: 889e6e020000 MOV byte ptr [ESI + 0x26e],BL
    m.w8((s.si+0x0000026eu), (s.bx & 0xffu));
  }
  L006da557: { // 0x6da557: 898678020000 MOV dword ptr [ESI + 0x278],EAX
    m.w32((s.si+0x00000278u), s.ax);
  }
  L006da55d: { // 0x6da55d: 89867c020000 MOV dword ptr [ESI + 0x27c],EAX
    m.w32((s.si+0x0000027cu), s.ax);
  }
  L006da563: { // 0x6da563: 8d4604 LEA EAX,[ESI + 0x4]
    s.ax = (s.si+0x00000004u);
  }
  L006da566: { // 0x6da566: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006da567: { // 0x6da567: 899e70020000 MOV dword ptr [ESI + 0x270],EBX
    m.w32((s.si+0x00000270u), s.bx);
  }
  L006da56d: { // 0x6da56d: 899e74020000 MOV dword ptr [ESI + 0x274],EBX
    m.w32((s.si+0x00000274u), s.bx);
  }
  L006da573: { // 0x6da573: 889e80020000 MOV byte ptr [ESI + 0x280],BL
    m.w8((s.si+0x00000280u), (s.bx & 0xffu));
  }
  L006da579: { // 0x6da579: 889e81020000 MOV byte ptr [ESI + 0x281],BL
    m.w8((s.si+0x00000281u), (s.bx & 0xffu));
  }
  L006da57f: { // 0x6da57f: 889e82020000 MOV byte ptr [ESI + 0x282],BL
    m.w8((s.si+0x00000282u), (s.bx & 0xffu));
  }
  L006da585: { // 0x6da585: 889e83020000 MOV byte ptr [ESI + 0x283],BL
    m.w8((s.si+0x00000283u), (s.bx & 0xffu));
  }
  L006da58b: { // 0x6da58b: 889e84020000 MOV byte ptr [ESI + 0x284],BL
    m.w8((s.si+0x00000284u), (s.bx & 0xffu));
  }
  L006da591: { // 0x6da591: 899e88020000 MOV dword ptr [ESI + 0x288],EBX
    m.w32((s.si+0x00000288u), s.bx);
  }
  L006da597: { // 0x6da597: c70688847900 MOV dword ptr [ESI],0x798488
    m.w32((s.si), 0x00798488u);
  }
  L006da59d: { // 0x6da59d: c7006c847900 MOV dword ptr [EAX],0x79846c
    m.w32((s.ax), 0x0079846cu);
  }
  L006da5a3: { // 0x6da5a3: c7460864847900 MOV dword ptr [ESI + 0x8],0x798464
    m.w32((s.si+0x00000008u), 0x00798464u);
  }
  L006da5aa: { // 0x6da5aa: c7460c5c847900 MOV dword ptr [ESI + 0xc],0x79845c
    m.w32((s.si+0x0000000cu), 0x0079845cu);
  }
  L006da5b1: { // 0x6da5b1: e81a5ad3ff CALL 0x0040ffd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0040ffd0u,7185846u); flags=s.arithmetic_flags;
  }
  L006da5b6: { // 0x6da5b6: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006da5b8: { // 0x6da5b8: 889e00020000 MOV byte ptr [ESI + 0x200],BL
    m.w8((s.si+0x00000200u), (s.bx & 0xffu));
  }
  L006da5be: { // 0x6da5be: 888604020000 MOV byte ptr [ESI + 0x204],AL
    m.w8((s.si+0x00000204u), (s.ax & 0xffu));
  }
  L006da5c4: { // 0x6da5c4: 8886ff010000 MOV byte ptr [ESI + 0x1ff],AL
    m.w8((s.si+0x000001ffu), (s.ax & 0xffu));
  }
  L006da5ca: { // 0x6da5ca: 889e01020000 MOV byte ptr [ESI + 0x201],BL
    m.w8((s.si+0x00000201u), (s.bx & 0xffu));
  }
  L006da5d0: { // 0x6da5d0: 888602020000 MOV byte ptr [ESI + 0x202],AL
    m.w8((s.si+0x00000202u), (s.ax & 0xffu));
  }
  L006da5d6: { // 0x6da5d6: a1807fa200 MOV EAX,[0x00a27f80]
    s.ax = m.r32((0x00a27f80u));
  }
  L006da5db: { // 0x6da5db: 8b0d787fa200 MOV ECX,dword ptr [0x00a27f78]
    s.cx = m.r32((0x00a27f78u));
  }
  L006da5e1: { // 0x6da5e1: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L006da5e3: { // 0x6da5e3: 7c31 JL 0x006da616
    if(integer::condition("JL",flags)) goto L006da616;
  }
  L006da5e5: { // 0x6da5e5: 381d7d7fa200 CMP byte ptr [0x00a27f7d],BL
    (void)integer::sub(m.r8((0x00a27f7du)),(s.bx & 0xffu),8,flags);
  }
  L006da5eb: { // 0x6da5eb: 7504 JNZ 0x006da5f1
    if(integer::condition("JNZ",flags)) goto L006da5f1;
  }
  L006da5ed: { // 0x6da5ed: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L006da5ef: { // 0x6da5ef: 753a JNZ 0x006da62b
    if(integer::condition("JNZ",flags)) goto L006da62b;
  }
  L006da5f1: { // 0x6da5f1: 8b15847fa200 MOV EDX,dword ptr [0x00a27f84]
    s.dx = m.r32((0x00a27f84u));
  }
  L006da5f7: { // 0x6da5f7: 3bd3 CMP EDX,EBX
    (void)integer::sub(s.dx,s.bx,32,flags);
  }
  L006da5f9: { // 0x6da5f9: 7e30 JLE 0x006da62b
    if(integer::condition("JLE",flags)) goto L006da62b;
  }
  L006da5fb: { // 0x6da5fb: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L006da5fd: { // 0x6da5fd: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006da5fe: { // 0x6da5fe: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006da5ff: { // 0x6da5ff: 8b15707fa200 MOV EDX,dword ptr [0x00a27f70]
    s.dx = m.r32((0x00a27f70u));
  }
  L006da605: { // 0x6da605: b9707fa200 MOV ECX,0xa27f70
    s.cx = 0x00a27f70u;
  }
  L006da60a: { // 0x6da60a: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),7185933u); flags=s.arithmetic_flags;
  }
  L006da60d: { // 0x6da60d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006da60f: { // 0x6da60f: a1807fa200 MOV EAX,[0x00a27f80]
    s.ax = m.r32((0x00a27f80u));
  }
  L006da614: { // 0x6da614: 7415 JZ 0x006da62b
    if(integer::condition("JZ",flags)) goto L006da62b;
  }
  L006da616: { // 0x6da616: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006da618: { // 0x6da618: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L006da619: { // 0x6da619: a3807fa200 MOV [0x00a27f80],EAX
    m.w32((0x00a27f80u), s.ax);
  }
  L006da61e: { // 0x6da61e: a1747fa200 MOV EAX,[0x00a27f74]
    s.ax = m.r32((0x00a27f74u));
  }
  L006da623: { // 0x6da623: 893488 MOV dword ptr [EAX + ECX*0x4],ESI
    m.w32((s.ax+(s.cx * 0x00000004u)), s.si);
  }
  L006da626: { // 0x6da626: a1807fa200 MOV EAX,[0x00a27f80]
    s.ax = m.r32((0x00a27f80u));
  }
  L006da62b: { // 0x6da62b: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L006da62d: { // 0x6da62d: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L006da62f: { // 0x6da62f: 7e12 JLE 0x006da643
    if(integer::condition("JLE",flags)) goto L006da643;
  }
  L006da631: { // 0x6da631: 8b15747fa200 MOV EDX,dword ptr [0x00a27f74]
    s.dx = m.r32((0x00a27f74u));
  }
  L006da637: { // 0x6da637: 3932 CMP dword ptr [EDX],ESI
    (void)integer::sub(m.r32((s.dx)),s.si,32,flags);
  }
  L006da639: { // 0x6da639: 740b JZ 0x006da646
    if(integer::condition("JZ",flags)) goto L006da646;
  }
  L006da63b: { // 0x6da63b: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L006da63c: { // 0x6da63c: 83c204 ADD EDX,0x4
    s.dx = integer::add(s.dx,0x00000004u,32,flags);
  }
  L006da63f: { // 0x6da63f: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L006da641: { // 0x6da641: 7cf4 JL 0x006da637
    if(integer::condition("JL",flags)) goto L006da637;
  }
  L006da643: { // 0x6da643: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  L006da646: { // 0x6da646: 898e64020000 MOV dword ptr [ESI + 0x264],ECX
    m.w32((s.si+0x00000264u), s.cx);
  }
  L006da64c: { // 0x6da64c: c786a0000000ffffffff MOV dword ptr [ESI + 0xa0],0xffffffff
    m.w32((s.si+0x000000a0u), 0xffffffffu);
  }
  L006da656: { // 0x6da656: c7869c00000006000000 MOV dword ptr [ESI + 0x9c],0x6
    m.w32((s.si+0x0000009cu), 0x00000006u);
  }
  L006da660: { // 0x6da660: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L006da662: { // 0x6da662: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006da663: { // 0x6da663: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006da664: { // 0x6da664: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
