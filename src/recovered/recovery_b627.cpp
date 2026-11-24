#include "recovered/recovery_b627_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b627 {
namespace {
void f_001cde80(Memory&,State&,Frame&,const Operations&);
void f_00010580(Memory&,State&,Frame&,const Operations&);
void f_0000ff10(Memory&,State&,Frame&,const Operations&);
void f_0036dd10(Memory&,State&,Frame&,const Operations&);
void f_0000ffd0(Memory&,State&,Frame&,const Operations&);
void f_0006d890(Memory&,State&,Frame&,const Operations&);
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
void f_0036dd10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0076dd10: { // 0x76dd10: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L0076dd14: { // 0x76dd14: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0076dd15: { // 0x76dd15: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0076dd17: { // 0x76dd17: 747a JZ 0x0076dd93
    if(integer::condition("JZ",flags)) goto L0076dd93;
  }
  L0076dd19: { // 0x76dd19: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0076dd1a: { // 0x76dd1a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0076dd1b: { // 0x76dd1b: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0076dd1d: { // 0x76dd1d: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L0076dd21: { // 0x76dd21: f7c603000000 TEST ESI,0x3
    (void)integer::logical((s.si)&(0x00000003u),32,flags);
  }
  L0076dd27: { // 0x76dd27: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L0076dd2b: { // 0x76dd2b: 7507 JNZ 0x0076dd34
    if(integer::condition("JNZ",flags)) goto L0076dd34;
  }
  L0076dd2d: { // 0x76dd2d: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L0076dd30: { // 0x76dd30: 756f JNZ 0x0076dda1
    if(integer::condition("JNZ",flags)) goto L0076dda1;
  }
  L0076dd32: { // 0x76dd32: eb21 JMP 0x0076dd55
    goto L0076dd55;
  }
  L0076dd34: { // 0x76dd34: 8a06 MOV AL,byte ptr [ESI]
    s.ax = with_al(s.ax, m.r8((s.si)));
  }
  L0076dd36: { // 0x76dd36: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0076dd37: { // 0x76dd37: 8807 MOV byte ptr [EDI],AL
    m.w8((s.di), (s.ax & 0xffu));
  }
  L0076dd39: { // 0x76dd39: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0076dd3a: { // 0x76dd3a: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0076dd3b: { // 0x76dd3b: 7425 JZ 0x0076dd62
    if(integer::condition("JZ",flags)) goto L0076dd62;
  }
  L0076dd3d: { // 0x76dd3d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0076dd3f: { // 0x76dd3f: 7429 JZ 0x0076dd6a
    if(integer::condition("JZ",flags)) goto L0076dd6a;
  }
  L0076dd41: { // 0x76dd41: f7c603000000 TEST ESI,0x3
    (void)integer::logical((s.si)&(0x00000003u),32,flags);
  }
  L0076dd47: { // 0x76dd47: 75eb JNZ 0x0076dd34
    if(integer::condition("JNZ",flags)) goto L0076dd34;
  }
  L0076dd49: { // 0x76dd49: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0076dd4b: { // 0x76dd4b: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L0076dd4e: { // 0x76dd4e: 7551 JNZ 0x0076dda1
    if(integer::condition("JNZ",flags)) goto L0076dda1;
  }
  L0076dd50: { // 0x76dd50: 83e303 AND EBX,0x3
    s.bx = integer::logical((s.bx)&(0x00000003u),32,flags);
  }
  L0076dd53: { // 0x76dd53: 740d JZ 0x0076dd62
    if(integer::condition("JZ",flags)) goto L0076dd62;
  }
  L0076dd55: { // 0x76dd55: 8a06 MOV AL,byte ptr [ESI]
    s.ax = with_al(s.ax, m.r8((s.si)));
  }
  L0076dd57: { // 0x76dd57: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0076dd58: { // 0x76dd58: 8807 MOV byte ptr [EDI],AL
    m.w8((s.di), (s.ax & 0xffu));
  }
  L0076dd5a: { // 0x76dd5a: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0076dd5b: { // 0x76dd5b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0076dd5d: { // 0x76dd5d: 742f JZ 0x0076dd8e
    if(integer::condition("JZ",flags)) goto L0076dd8e;
  }
  L0076dd5f: { // 0x76dd5f: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L0076dd60: { // 0x76dd60: 75f3 JNZ 0x0076dd55
    if(integer::condition("JNZ",flags)) goto L0076dd55;
  }
  L0076dd62: { // 0x76dd62: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
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
  L0076dd6a: { // 0x76dd6a: f7c703000000 TEST EDI,0x3
    (void)integer::logical((s.di)&(0x00000003u),32,flags);
  }
  L0076dd70: { // 0x76dd70: 7412 JZ 0x0076dd84
    if(integer::condition("JZ",flags)) goto L0076dd84;
  }
  L0076dd72: { // 0x76dd72: 8807 MOV byte ptr [EDI],AL
    m.w8((s.di), (s.ax & 0xffu));
  }
  L0076dd74: { // 0x76dd74: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0076dd75: { // 0x76dd75: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0076dd76: { // 0x76dd76: 0f848a000000 JZ 0x0076de06
    if(integer::condition("JZ",flags)) goto L0076de06;
  }
  L0076dd7c: { // 0x76dd7c: f7c703000000 TEST EDI,0x3
    (void)integer::logical((s.di)&(0x00000003u),32,flags);
  }
  L0076dd82: { // 0x76dd82: 75ee JNZ 0x0076dd72
    if(integer::condition("JNZ",flags)) goto L0076dd72;
  }
  L0076dd84: { // 0x76dd84: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0076dd86: { // 0x76dd86: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L0076dd89: { // 0x76dd89: 756c JNZ 0x0076ddf7
    if(integer::condition("JNZ",flags)) goto L0076ddf7;
  }
  L0076dd8b: { // 0x76dd8b: 8807 MOV byte ptr [EDI],AL
    m.w8((s.di), (s.ax & 0xffu));
  }
  L0076dd8d: { // 0x76dd8d: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0076dd8e: { // 0x76dd8e: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L0076dd8f: { // 0x76dd8f: 75fa JNZ 0x0076dd8b
    if(integer::condition("JNZ",flags)) goto L0076dd8b;
  }
  L0076dd91: { // 0x76dd91: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0076dd92: { // 0x76dd92: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076dd93: { // 0x76dd93: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L0076dd97: { // 0x76dd97: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076dd98: { // 0x76dd98: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076dd99: { // 0x76dd99: 8917 MOV dword ptr [EDI],EDX
    m.w32((s.di), s.dx);
  }
  L0076dd9b: { // 0x76dd9b: 83c704 ADD EDI,0x4
    s.di = integer::add(s.di,0x00000004u,32,flags);
  }
  L0076dd9e: { // 0x76dd9e: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0076dd9f: { // 0x76dd9f: 74af JZ 0x0076dd50
    if(integer::condition("JZ",flags)) goto L0076dd50;
  }
  L0076dda1: { // 0x76dda1: bafffefe7e MOV EDX,0x7efefeff
    s.dx = 0x7efefeffu;
  }
  L0076dda6: { // 0x76dda6: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0076dda8: { // 0x76dda8: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L0076ddaa: { // 0x76ddaa: 83f0ff XOR EAX,0xffffffff
    s.ax = integer::logical((s.ax)^(0xffffffffu),32,flags);
  }
  L0076ddad: { // 0x76ddad: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L0076ddaf: { // 0x76ddaf: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0076ddb1: { // 0x76ddb1: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  L0076ddb4: { // 0x76ddb4: a900010181 TEST EAX,0x81010100
    (void)integer::logical((s.ax)&(0x81010100u),32,flags);
  }
  L0076ddb9: { // 0x76ddb9: 74de JZ 0x0076dd99
    if(integer::condition("JZ",flags)) goto L0076dd99;
  }
  L0076ddbb: { // 0x76ddbb: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L0076ddbd: { // 0x76ddbd: 742c JZ 0x0076ddeb
    if(integer::condition("JZ",flags)) goto L0076ddeb;
  }
  L0076ddbf: { // 0x76ddbf: 84f6 TEST DH,DH
    (void)integer::logical((((s.dx >> 8) & 0xffu))&(((s.dx >> 8) & 0xffu)),8,flags);
  }
  L0076ddc1: { // 0x76ddc1: 741e JZ 0x0076dde1
    if(integer::condition("JZ",flags)) goto L0076dde1;
  }
  L0076ddc3: { // 0x76ddc3: f7c20000ff00 TEST EDX,0xff0000
    (void)integer::logical((s.dx)&(0x00ff0000u),32,flags);
  }
  L0076ddc9: { // 0x76ddc9: 740c JZ 0x0076ddd7
    if(integer::condition("JZ",flags)) goto L0076ddd7;
  }
  L0076ddcb: { // 0x76ddcb: f7c2000000ff TEST EDX,0xff000000
    (void)integer::logical((s.dx)&(0xff000000u),32,flags);
  }
  L0076ddd1: { // 0x76ddd1: 75c6 JNZ 0x0076dd99
    if(integer::condition("JNZ",flags)) goto L0076dd99;
  }
  L0076ddd3: { // 0x76ddd3: 8917 MOV dword ptr [EDI],EDX
    m.w32((s.di), s.dx);
  }
  L0076ddd5: { // 0x76ddd5: eb18 JMP 0x0076ddef
    goto L0076ddef;
  }
  L0076ddd7: { // 0x76ddd7: 81e2ffff0000 AND EDX,0xffff
    s.dx = integer::logical((s.dx)&(0x0000ffffu),32,flags);
  }
  L0076dddd: { // 0x76dddd: 8917 MOV dword ptr [EDI],EDX
    m.w32((s.di), s.dx);
  }
  L0076dddf: { // 0x76dddf: eb0e JMP 0x0076ddef
    goto L0076ddef;
  }
  L0076dde1: { // 0x76dde1: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0076dde7: { // 0x76dde7: 8917 MOV dword ptr [EDI],EDX
    m.w32((s.di), s.dx);
  }
  L0076dde9: { // 0x76dde9: eb04 JMP 0x0076ddef
    goto L0076ddef;
  }
  L0076ddeb: { // 0x76ddeb: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0076dded: { // 0x76dded: 8917 MOV dword ptr [EDI],EDX
    m.w32((s.di), s.dx);
  }
  L0076ddef: { // 0x76ddef: 83c704 ADD EDI,0x4
    s.di = integer::add(s.di,0x00000004u,32,flags);
  }
  L0076ddf2: { // 0x76ddf2: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0076ddf4: { // 0x76ddf4: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0076ddf5: { // 0x76ddf5: 740a JZ 0x0076de01
    if(integer::condition("JZ",flags)) goto L0076de01;
  }
  L0076ddf7: { // 0x76ddf7: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0076ddf9: { // 0x76ddf9: 8907 MOV dword ptr [EDI],EAX
    m.w32((s.di), s.ax);
  }
  L0076ddfb: { // 0x76ddfb: 83c704 ADD EDI,0x4
    s.di = integer::add(s.di,0x00000004u,32,flags);
  }
  L0076ddfe: { // 0x76ddfe: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0076ddff: { // 0x76ddff: 75f8 JNZ 0x0076ddf9
    if(integer::condition("JNZ",flags)) goto L0076ddf9;
  }
  L0076de01: { // 0x76de01: 83e303 AND EBX,0x3
    s.bx = integer::logical((s.bx)&(0x00000003u),32,flags);
  }
  L0076de04: { // 0x76de04: 7585 JNZ 0x0076dd8b
    if(integer::condition("JNZ",flags)) goto L0076dd8b;
  }
  L0076de06: { // 0x76de06: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
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

void f_0006d890(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0046d890: { // 0x46d890: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0046d891: { // 0x46d891: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0046d892: { // 0x46d892: 8b74240c MOV ESI,dword ptr [ESP + 0xc]
    s.si = m.r32((f.sp+0x0000000cu));
  }
  L0046d896: { // 0x46d896: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0046d897: { // 0x46d897: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0046d899: { // 0x46d899: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0046d89b: { // 0x46d89b: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L0046d89d: { // 0x46d89d: 895f04 MOV dword ptr [EDI + 0x4],EBX
    m.w32((s.di+0x00000004u), s.bx);
  }
  L0046d8a0: { // 0x46d8a0: 897708 MOV dword ptr [EDI + 0x8],ESI
    m.w32((s.di+0x00000008u), s.si);
  }
  L0046d8a3: { // 0x46d8a3: c6470c01 MOV byte ptr [EDI + 0xc],0x1
    m.w8((s.di+0x0000000cu), 0x00000001u);
  }
  L0046d8a7: { // 0x46d8a7: 885f0d MOV byte ptr [EDI + 0xd],BL
    m.w8((s.di+0x0000000du), (s.bx & 0xffu));
  }
  L0046d8aa: { // 0x46d8aa: c707548a7800 MOV dword ptr [EDI],0x788a54
    m.w32((s.di), 0x00788a54u);
  }
  L0046d8b0: { // 0x46d8b0: 745e JZ 0x0046d910
    if(integer::condition("JZ",flags)) goto L0046d910;
  }
  L0046d8b2: { // 0x46d8b2: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L0046d8b6: { // 0x46d8b6: 3bd3 CMP EDX,EBX
    (void)integer::sub(s.dx,s.bx,32,flags);
  }
  L0046d8b8: { // 0x46d8b8: 7424 JZ 0x0046d8de
    if(integer::condition("JZ",flags)) goto L0046d8de;
  }
  L0046d8ba: { // 0x46d8ba: 8d4eff LEA ECX,[ESI + -0x1]
    s.cx = (s.si-0x00000001u);
  }
  L0046d8bd: { // 0x46d8bd: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L0046d8bf: { // 0x46d8bf: 7c12 JL 0x0046d8d3
    if(integer::condition("JL",flags)) goto L0046d8d3;
  }
  L0046d8c1: { // 0x46d8c1: 8d4202 LEA EAX,[EDX + 0x2]
    s.ax = (s.dx+0x00000002u);
  }
  L0046d8c4: { // 0x46d8c4: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0046d8c5: { // 0x46d8c5: 8858fe MOV byte ptr [EAX + -0x2],BL
    m.w8((s.ax-0x00000002u), (s.bx & 0xffu));
  }
  L0046d8c8: { // 0x46d8c8: 8858ff MOV byte ptr [EAX + -0x1],BL
    m.w8((s.ax-0x00000001u), (s.bx & 0xffu));
  }
  L0046d8cb: { // 0x46d8cb: 8818 MOV byte ptr [EAX],BL
    m.w8((s.ax), (s.bx & 0xffu));
  }
  L0046d8cd: { // 0x46d8cd: 83c003 ADD EAX,0x3
    s.ax = integer::add(s.ax,0x00000003u,32,flags);
  }
  L0046d8d0: { // 0x46d8d0: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0046d8d1: { // 0x46d8d1: 75f2 JNZ 0x0046d8c5
    if(integer::condition("JNZ",flags)) goto L0046d8c5;
  }
  L0046d8d3: { // 0x46d8d3: 895704 MOV dword ptr [EDI + 0x4],EDX
    m.w32((s.di+0x00000004u), s.dx);
  }
  L0046d8d6: { // 0x46d8d6: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0046d8d8: { // 0x46d8d8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0046d8d9: { // 0x46d8d9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0046d8da: { // 0x46d8da: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0046d8db: { // 0x46d8db: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0046d8de: { // 0x46d8de: 8d0476 LEA EAX,[ESI + ESI*0x2]
    s.ax = (s.si+(s.si * 0x00000002u));
  }
  L0046d8e1: { // 0x46d8e1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0046d8e2: { // 0x46d8e2: e870003000 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,4643047u); flags=s.arithmetic_flags;
  }
  L0046d8e7: { // 0x46d8e7: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0046d8ea: { // 0x46d8ea: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0046d8ec: { // 0x46d8ec: 741b JZ 0x0046d909
    if(integer::condition("JZ",flags)) goto L0046d909;
  }
  L0046d8ee: { // 0x46d8ee: 8d56ff LEA EDX,[ESI + -0x1]
    s.dx = (s.si-0x00000001u);
  }
  L0046d8f1: { // 0x46d8f1: 3bd3 CMP EDX,EBX
    (void)integer::sub(s.dx,s.bx,32,flags);
  }
  L0046d8f3: { // 0x46d8f3: 7c12 JL 0x0046d907
    if(integer::condition("JL",flags)) goto L0046d907;
  }
  L0046d8f5: { // 0x46d8f5: 8d4802 LEA ECX,[EAX + 0x2]
    s.cx = (s.ax+0x00000002u);
  }
  L0046d8f8: { // 0x46d8f8: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L0046d8f9: { // 0x46d8f9: 8859fe MOV byte ptr [ECX + -0x2],BL
    m.w8((s.cx-0x00000002u), (s.bx & 0xffu));
  }
  L0046d8fc: { // 0x46d8fc: 8859ff MOV byte ptr [ECX + -0x1],BL
    m.w8((s.cx-0x00000001u), (s.bx & 0xffu));
  }
  L0046d8ff: { // 0x46d8ff: 8819 MOV byte ptr [ECX],BL
    m.w8((s.cx), (s.bx & 0xffu));
  }
  L0046d901: { // 0x46d901: 83c103 ADD ECX,0x3
    s.cx = integer::add(s.cx,0x00000003u,32,flags);
  }
  L0046d904: { // 0x46d904: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L0046d905: { // 0x46d905: 75f2 JNZ 0x0046d8f9
    if(integer::condition("JNZ",flags)) goto L0046d8f9;
  }
  L0046d907: { // 0x46d907: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0046d909: { // 0x46d909: 895f04 MOV dword ptr [EDI + 0x4],EBX
    m.w32((s.di+0x00000004u), s.bx);
  }
  L0046d90c: { // 0x46d90c: c6470d01 MOV byte ptr [EDI + 0xd],0x1
    m.w8((s.di+0x0000000du), 0x00000001u);
  }
  L0046d910: { // 0x46d910: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0046d912: { // 0x46d912: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0046d913: { // 0x46d913: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0046d914: { // 0x46d914: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0046d915: { // 0x46d915: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}

} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 6086272u:f_001cde80(m,s,child,{});break;
case 4261248u:f_00010580(m,s,child,{});break;
case 4259600u:f_0000ff10(m,s,child,{});break;
case 7789840u:f_0036dd10(m,s,child,{});break;
case 4259792u:f_0000ffd0(m,s,child,{});break;
case 4642960u:f_0006d890(m,s,child,{});break;
default:throw std::domain_error("recovery627 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00464110(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00464110: { // 0x464110: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L00464114: { // 0x464114: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00464115: { // 0x464115: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00464116: { // 0x464116: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00464118: { // 0x464118: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00464119: { // 0x464119: e8629d1600 CALL 0x005cde80
    s.arithmetic_flags=flags; invoke(m,s,f,0x005cde80u,4604190u); flags=s.arithmetic_flags;
  }
  L0046411e: { // 0x46411e: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00464120: { // 0x464120: b803000000 MOV EAX,0x3
    s.ax = 0x00000003u;
  }
  L00464125: { // 0x464125: 889e64020000 MOV byte ptr [ESI + 0x264],BL
    m.w8((s.si+0x00000264u), (s.bx & 0xffu));
  }
  L0046412b: { // 0x46412b: 889e65020000 MOV byte ptr [ESI + 0x265],BL
    m.w8((s.si+0x00000265u), (s.bx & 0xffu));
  }
  L00464131: { // 0x464131: 889e66020000 MOV byte ptr [ESI + 0x266],BL
    m.w8((s.si+0x00000266u), (s.bx & 0xffu));
  }
  L00464137: { // 0x464137: 889e67020000 MOV byte ptr [ESI + 0x267],BL
    m.w8((s.si+0x00000267u), (s.bx & 0xffu));
  }
  L0046413d: { // 0x46413d: 889e68020000 MOV byte ptr [ESI + 0x268],BL
    m.w8((s.si+0x00000268u), (s.bx & 0xffu));
  }
  L00464143: { // 0x464143: 889e69020000 MOV byte ptr [ESI + 0x269],BL
    m.w8((s.si+0x00000269u), (s.bx & 0xffu));
  }
  L00464149: { // 0x464149: c6866a02000001 MOV byte ptr [ESI + 0x26a],0x1
    m.w8((s.si+0x0000026au), 0x00000001u);
  }
  L00464150: { // 0x464150: 889e6b020000 MOV byte ptr [ESI + 0x26b],BL
    m.w8((s.si+0x0000026bu), (s.bx & 0xffu));
  }
  L00464156: { // 0x464156: 889e6c020000 MOV byte ptr [ESI + 0x26c],BL
    m.w8((s.si+0x0000026cu), (s.bx & 0xffu));
  }
  L0046415c: { // 0x46415c: 889e6d020000 MOV byte ptr [ESI + 0x26d],BL
    m.w8((s.si+0x0000026du), (s.bx & 0xffu));
  }
  L00464162: { // 0x464162: 889e6e020000 MOV byte ptr [ESI + 0x26e],BL
    m.w8((s.si+0x0000026eu), (s.bx & 0xffu));
  }
  L00464168: { // 0x464168: 889e6f020000 MOV byte ptr [ESI + 0x26f],BL
    m.w8((s.si+0x0000026fu), (s.bx & 0xffu));
  }
  L0046416e: { // 0x46416e: 889e70020000 MOV byte ptr [ESI + 0x270],BL
    m.w8((s.si+0x00000270u), (s.bx & 0xffu));
  }
  L00464174: { // 0x464174: c6867102000001 MOV byte ptr [ESI + 0x271],0x1
    m.w8((s.si+0x00000271u), 0x00000001u);
  }
  L0046417b: { // 0x46417b: 889e72020000 MOV byte ptr [ESI + 0x272],BL
    m.w8((s.si+0x00000272u), (s.bx & 0xffu));
  }
  L00464181: { // 0x464181: 889e73020000 MOV byte ptr [ESI + 0x273],BL
    m.w8((s.si+0x00000273u), (s.bx & 0xffu));
  }
  L00464187: { // 0x464187: 889e74020000 MOV byte ptr [ESI + 0x274],BL
    m.w8((s.si+0x00000274u), (s.bx & 0xffu));
  }
  L0046418d: { // 0x46418d: c6867502000001 MOV byte ptr [ESI + 0x275],0x1
    m.w8((s.si+0x00000275u), 0x00000001u);
  }
  L00464194: { // 0x464194: 8986a0020000 MOV dword ptr [ESI + 0x2a0],EAX
    m.w32((s.si+0x000002a0u), s.ax);
  }
  L0046419a: { // 0x46419a: 8986b4020000 MOV dword ptr [ESI + 0x2b4],EAX
    m.w32((s.si+0x000002b4u), s.ax);
  }
  L004641a0: { // 0x4641a0: 889e76020000 MOV byte ptr [ESI + 0x276],BL
    m.w8((s.si+0x00000276u), (s.bx & 0xffu));
  }
  L004641a6: { // 0x4641a6: 8d4604 LEA EAX,[ESI + 0x4]
    s.ax = (s.si+0x00000004u);
  }
  L004641a9: { // 0x4641a9: 889e77020000 MOV byte ptr [ESI + 0x277],BL
    m.w8((s.si+0x00000277u), (s.bx & 0xffu));
  }
  L004641af: { // 0x4641af: 889e78020000 MOV byte ptr [ESI + 0x278],BL
    m.w8((s.si+0x00000278u), (s.bx & 0xffu));
  }
  L004641b5: { // 0x4641b5: 899e98020000 MOV dword ptr [ESI + 0x298],EBX
    m.w32((s.si+0x00000298u), s.bx);
  }
  L004641bb: { // 0x4641bb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004641bc: { // 0x4641bc: 889e79020000 MOV byte ptr [ESI + 0x279],BL
    m.w8((s.si+0x00000279u), (s.bx & 0xffu));
  }
  L004641c2: { // 0x4641c2: c7867c02000001000000 MOV dword ptr [ESI + 0x27c],0x1
    m.w32((s.si+0x0000027cu), 0x00000001u);
  }
  L004641cc: { // 0x4641cc: 899e80020000 MOV dword ptr [ESI + 0x280],EBX
    m.w32((s.si+0x00000280u), s.bx);
  }
  L004641d2: { // 0x4641d2: 899e84020000 MOV dword ptr [ESI + 0x284],EBX
    m.w32((s.si+0x00000284u), s.bx);
  }
  L004641d8: { // 0x4641d8: 899e88020000 MOV dword ptr [ESI + 0x288],EBX
    m.w32((s.si+0x00000288u), s.bx);
  }
  L004641de: { // 0x4641de: 899e8c020000 MOV dword ptr [ESI + 0x28c],EBX
    m.w32((s.si+0x0000028cu), s.bx);
  }
  L004641e4: { // 0x4641e4: 889e90020000 MOV byte ptr [ESI + 0x290],BL
    m.w8((s.si+0x00000290u), (s.bx & 0xffu));
  }
  L004641ea: { // 0x4641ea: c7869c0200000000e83f MOV dword ptr [ESI + 0x29c],0x3fe80000
    m.w32((s.si+0x0000029cu), 0x3fe80000u);
  }
  L004641f4: { // 0x4641f4: 899ea4020000 MOV dword ptr [ESI + 0x2a4],EBX
    m.w32((s.si+0x000002a4u), s.bx);
  }
  L004641fa: { // 0x4641fa: 899ea8020000 MOV dword ptr [ESI + 0x2a8],EBX
    m.w32((s.si+0x000002a8u), s.bx);
  }
  L00464200: { // 0x464200: 899eac020000 MOV dword ptr [ESI + 0x2ac],EBX
    m.w32((s.si+0x000002acu), s.bx);
  }
  L00464206: { // 0x464206: 899eb0020000 MOV dword ptr [ESI + 0x2b0],EBX
    m.w32((s.si+0x000002b0u), s.bx);
  }
  L0046420c: { // 0x46420c: 899eb8020000 MOV dword ptr [ESI + 0x2b8],EBX
    m.w32((s.si+0x000002b8u), s.bx);
  }
  L00464212: { // 0x464212: 889ebc020000 MOV byte ptr [ESI + 0x2bc],BL
    m.w8((s.si+0x000002bcu), (s.bx & 0xffu));
  }
  L00464218: { // 0x464218: 899ec0020000 MOV dword ptr [ESI + 0x2c0],EBX
    m.w32((s.si+0x000002c0u), s.bx);
  }
  L0046421e: { // 0x46421e: 889ec4020000 MOV byte ptr [ESI + 0x2c4],BL
    m.w8((s.si+0x000002c4u), (s.bx & 0xffu));
  }
  L00464224: { // 0x464224: 889ec5020000 MOV byte ptr [ESI + 0x2c5],BL
    m.w8((s.si+0x000002c5u), (s.bx & 0xffu));
  }
  L0046422a: { // 0x46422a: 889ec6020000 MOV byte ptr [ESI + 0x2c6],BL
    m.w8((s.si+0x000002c6u), (s.bx & 0xffu));
  }
  L00464230: { // 0x464230: 889ec7020000 MOV byte ptr [ESI + 0x2c7],BL
    m.w8((s.si+0x000002c7u), (s.bx & 0xffu));
  }
  L00464236: { // 0x464236: c706c0857800 MOV dword ptr [ESI],0x7885c0
    m.w32((s.si), 0x007885c0u);
  }
  L0046423c: { // 0x46423c: c700a4857800 MOV dword ptr [EAX],0x7885a4
    m.w32((s.ax), 0x007885a4u);
  }
  L00464242: { // 0x464242: c746089c857800 MOV dword ptr [ESI + 0x8],0x78859c
    m.w32((s.si+0x00000008u), 0x0078859cu);
  }
  L00464249: { // 0x464249: c7460c94857800 MOV dword ptr [ESI + 0xc],0x788594
    m.w32((s.si+0x0000000cu), 0x00788594u);
  }
  L00464250: { // 0x464250: e87bbdfaff CALL 0x0040ffd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0040ffd0u,4604501u); flags=s.arithmetic_flags;
  }
  L00464255: { // 0x464255: c6860402000001 MOV byte ptr [ESI + 0x204],0x1
    m.w8((s.si+0x00000204u), 0x00000001u);
  }
  L0046425c: { // 0x46425c: c686ff01000001 MOV byte ptr [ESI + 0x1ff],0x1
    m.w8((s.si+0x000001ffu), 0x00000001u);
  }
  L00464263: { // 0x464263: 889e00020000 MOV byte ptr [ESI + 0x200],BL
    m.w8((s.si+0x00000200u), (s.bx & 0xffu));
  }
  L00464269: { // 0x464269: 889e01020000 MOV byte ptr [ESI + 0x201],BL
    m.w8((s.si+0x00000201u), (s.bx & 0xffu));
  }
  L0046426f: { // 0x46426f: c6860202000001 MOV byte ptr [ESI + 0x202],0x1
    m.w8((s.si+0x00000202u), 0x00000001u);
  }
  L00464276: { // 0x464276: c6860302000001 MOV byte ptr [ESI + 0x203],0x1
    m.w8((s.si+0x00000203u), 0x00000001u);
  }
  L0046427d: { // 0x46427d: 889e05020000 MOV byte ptr [ESI + 0x205],BL
    m.w8((s.si+0x00000205u), (s.bx & 0xffu));
  }
  L00464283: { // 0x464283: a128e0a100 MOV EAX,[0x00a1e028]
    s.ax = m.r32((0x00a1e028u));
  }
  L00464288: { // 0x464288: 390530e0a100 CMP dword ptr [0x00a1e030],EAX
    (void)integer::sub(m.r32((0x00a1e030u)),s.ax,32,flags);
  }
  L0046428e: { // 0x46428e: 7c2c JL 0x004642bc
    if(integer::condition("JL",flags)) goto L004642bc;
  }
  L00464290: { // 0x464290: 381d2de0a100 CMP byte ptr [0x00a1e02d],BL
    (void)integer::sub(m.r8((0x00a1e02du)),(s.bx & 0xffu),8,flags);
  }
  L00464296: { // 0x464296: 7504 JNZ 0x0046429c
    if(integer::condition("JNZ",flags)) goto L0046429c;
  }
  L00464298: { // 0x464298: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0046429a: { // 0x46429a: 7538 JNZ 0x004642d4
    if(integer::condition("JNZ",flags)) goto L004642d4;
  }
  L0046429c: { // 0x46429c: 8b0d34e0a100 MOV ECX,dword ptr [0x00a1e034]
    s.cx = m.r32((0x00a1e034u));
  }
  L004642a2: { // 0x4642a2: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L004642a4: { // 0x4642a4: 7e2e JLE 0x004642d4
    if(integer::condition("JLE",flags)) goto L004642d4;
  }
  L004642a6: { // 0x4642a6: 8b1520e0a100 MOV EDX,dword ptr [0x00a1e020]
    s.dx = m.r32((0x00a1e020u));
  }
  L004642ac: { // 0x4642ac: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L004642ae: { // 0x4642ae: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004642af: { // 0x4642af: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004642b0: { // 0x4642b0: b920e0a100 MOV ECX,0xa1e020
    s.cx = 0x00a1e020u;
  }
  L004642b5: { // 0x4642b5: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),4604600u); flags=s.arithmetic_flags;
  }
  L004642b8: { // 0x4642b8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004642ba: { // 0x4642ba: 7418 JZ 0x004642d4
    if(integer::condition("JZ",flags)) goto L004642d4;
  }
  L004642bc: { // 0x4642bc: 8b0d30e0a100 MOV ECX,dword ptr [0x00a1e030]
    s.cx = m.r32((0x00a1e030u));
  }
  L004642c2: { // 0x4642c2: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004642c4: { // 0x4642c4: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L004642c5: { // 0x4642c5: 890d30e0a100 MOV dword ptr [0x00a1e030],ECX
    m.w32((0x00a1e030u), s.cx);
  }
  L004642cb: { // 0x4642cb: 8b0d24e0a100 MOV ECX,dword ptr [0x00a1e024]
    s.cx = m.r32((0x00a1e024u));
  }
  L004642d1: { // 0x4642d1: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L004642d4: { // 0x4642d4: a1c087aa00 MOV EAX,[0x00aa87c0]
    s.ax = m.r32((0x00aa87c0u));
  }
  L004642d9: { // 0x4642d9: 8b0dc887aa00 MOV ECX,dword ptr [0x00aa87c8]
    s.cx = m.r32((0x00aa87c8u));
  }
  L004642df: { // 0x4642df: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L004642e1: { // 0x4642e1: 7c2c JL 0x0046430f
    if(integer::condition("JL",flags)) goto L0046430f;
  }
  L004642e3: { // 0x4642e3: 381dc587aa00 CMP byte ptr [0x00aa87c5],BL
    (void)integer::sub(m.r8((0x00aa87c5u)),(s.bx & 0xffu),8,flags);
  }
  L004642e9: { // 0x4642e9: 7504 JNZ 0x004642ef
    if(integer::condition("JNZ",flags)) goto L004642ef;
  }
  L004642eb: { // 0x4642eb: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L004642ed: { // 0x4642ed: 7538 JNZ 0x00464327
    if(integer::condition("JNZ",flags)) goto L00464327;
  }
  L004642ef: { // 0x4642ef: 8b0dcc87aa00 MOV ECX,dword ptr [0x00aa87cc]
    s.cx = m.r32((0x00aa87ccu));
  }
  L004642f5: { // 0x4642f5: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L004642f7: { // 0x4642f7: 7e2e JLE 0x00464327
    if(integer::condition("JLE",flags)) goto L00464327;
  }
  L004642f9: { // 0x4642f9: 8b15b887aa00 MOV EDX,dword ptr [0x00aa87b8]
    s.dx = m.r32((0x00aa87b8u));
  }
  L004642ff: { // 0x4642ff: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00464301: { // 0x464301: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00464302: { // 0x464302: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00464303: { // 0x464303: b9b887aa00 MOV ECX,0xaa87b8
    s.cx = 0x00aa87b8u;
  }
  L00464308: { // 0x464308: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),4604683u); flags=s.arithmetic_flags;
  }
  L0046430b: { // 0x46430b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0046430d: { // 0x46430d: 7418 JZ 0x00464327
    if(integer::condition("JZ",flags)) goto L00464327;
  }
  L0046430f: { // 0x46430f: 8b0dc887aa00 MOV ECX,dword ptr [0x00aa87c8]
    s.cx = m.r32((0x00aa87c8u));
  }
  L00464315: { // 0x464315: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00464317: { // 0x464317: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00464318: { // 0x464318: 890dc887aa00 MOV dword ptr [0x00aa87c8],ECX
    m.w32((0x00aa87c8u), s.cx);
  }
  L0046431e: { // 0x46431e: 8b0dbc87aa00 MOV ECX,dword ptr [0x00aa87bc]
    s.cx = m.r32((0x00aa87bcu));
  }
  L00464324: { // 0x464324: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L00464327: { // 0x464327: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00464329: { // 0x464329: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0046432a: { // 0x46432a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0046432b: { // 0x46432b: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00618cb0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00618cb0: { // 0x618cb0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L00618cb4: { // 0x618cb4: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00618cb5: { // 0x618cb5: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00618cb6: { // 0x618cb6: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00618cb7: { // 0x618cb7: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00618cb8: { // 0x618cb8: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00618cba: { // 0x618cba: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00618cbb: { // 0x618cbb: e8c051fbff CALL 0x005cde80
    s.arithmetic_flags=flags; invoke(m,s,f,0x005cde80u,6393024u); flags=s.arithmetic_flags;
  }
  L00618cc0: { // 0x618cc0: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00618cc2: { // 0x618cc2: 8dbe88020000 LEA EDI,[ESI + 0x288]
    s.di = (s.si+0x00000288u);
  }
  L00618cc8: { // 0x618cc8: 899e64020000 MOV dword ptr [ESI + 0x264],EBX
    m.w32((s.si+0x00000264u), s.bx);
  }
  L00618cce: { // 0x618cce: 899e68020000 MOV dword ptr [ESI + 0x268],EBX
    m.w32((s.si+0x00000268u), s.bx);
  }
  L00618cd4: { // 0x618cd4: 899e6c020000 MOV dword ptr [ESI + 0x26c],EBX
    m.w32((s.si+0x0000026cu), s.bx);
  }
  L00618cda: { // 0x618cda: bd01000000 MOV EBP,0x1
    s.bp = 0x00000001u;
  }
  L00618cdf: { // 0x618cdf: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00618ce0: { // 0x618ce0: 899e80020000 MOV dword ptr [ESI + 0x280],EBX
    m.w32((s.si+0x00000280u), s.bx);
  }
  L00618ce6: { // 0x618ce6: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00618ce7: { // 0x618ce7: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00618ce9: { // 0x618ce9: 89ae70020000 MOV dword ptr [ESI + 0x270],EBP
    m.w32((s.si+0x00000270u), s.bp);
  }
  L00618cef: { // 0x618cef: 89ae74020000 MOV dword ptr [ESI + 0x274],EBP
    m.w32((s.si+0x00000274u), s.bp);
  }
  L00618cf5: { // 0x618cf5: 899e78020000 MOV dword ptr [ESI + 0x278],EBX
    m.w32((s.si+0x00000278u), s.bx);
  }
  L00618cfb: { // 0x618cfb: 89ae7c020000 MOV dword ptr [ESI + 0x27c],EBP
    m.w32((s.si+0x0000027cu), s.bp);
  }
  L00618d01: { // 0x618d01: 899e84020000 MOV dword ptr [ESI + 0x284],EBX
    m.w32((s.si+0x00000284u), s.bx);
  }
  L00618d07: { // 0x618d07: e8844be5ff CALL 0x0046d890
    s.arithmetic_flags=flags; invoke(m,s,f,0x0046d890u,6393100u); flags=s.arithmetic_flags;
  }
  L00618d0c: { // 0x618d0c: c747140a000000 MOV dword ptr [EDI + 0x14],0xa
    m.w32((s.di+0x00000014u), 0x0000000au);
  }
  L00618d13: { // 0x618d13: 895f10 MOV dword ptr [EDI + 0x10],EBX
    m.w32((s.di+0x00000010u), s.bx);
  }
  L00618d16: { // 0x618d16: c707748a7800 MOV dword ptr [EDI],0x788a74
    m.w32((s.di), 0x00788a74u);
  }
  L00618d1c: { // 0x618d1c: 889ea4020000 MOV byte ptr [ESI + 0x2a4],BL
    m.w8((s.si+0x000002a4u), (s.bx & 0xffu));
  }
  L00618d22: { // 0x618d22: 889ea5020000 MOV byte ptr [ESI + 0x2a5],BL
    m.w8((s.si+0x000002a5u), (s.bx & 0xffu));
  }
  L00618d28: { // 0x618d28: 889ea6020000 MOV byte ptr [ESI + 0x2a6],BL
    m.w8((s.si+0x000002a6u), (s.bx & 0xffu));
  }
  L00618d2e: { // 0x618d2e: b0ff MOV AL,0xff
    s.ax = with_al(s.ax, 0x000000ffu);
  }
  L00618d30: { // 0x618d30: 889ea7020000 MOV byte ptr [ESI + 0x2a7],BL
    m.w8((s.si+0x000002a7u), (s.bx & 0xffu));
  }
  L00618d36: { // 0x618d36: 889ea8020000 MOV byte ptr [ESI + 0x2a8],BL
    m.w8((s.si+0x000002a8u), (s.bx & 0xffu));
  }
  L00618d3c: { // 0x618d3c: 889ea9020000 MOV byte ptr [ESI + 0x2a9],BL
    m.w8((s.si+0x000002a9u), (s.bx & 0xffu));
  }
  L00618d42: { // 0x618d42: 8886dd020000 MOV byte ptr [ESI + 0x2dd],AL
    m.w8((s.si+0x000002ddu), (s.ax & 0xffu));
  }
  L00618d48: { // 0x618d48: 8886de020000 MOV byte ptr [ESI + 0x2de],AL
    m.w8((s.si+0x000002deu), (s.ax & 0xffu));
  }
  L00618d4e: { // 0x618d4e: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L00618d51: { // 0x618d51: 899eac020000 MOV dword ptr [ESI + 0x2ac],EBX
    m.w32((s.si+0x000002acu), s.bx);
  }
  L00618d57: { // 0x618d57: 89aeb0020000 MOV dword ptr [ESI + 0x2b0],EBP
    m.w32((s.si+0x000002b0u), s.bp);
  }
  L00618d5d: { // 0x618d5d: 899eb4020000 MOV dword ptr [ESI + 0x2b4],EBX
    m.w32((s.si+0x000002b4u), s.bx);
  }
  L00618d63: { // 0x618d63: 899eb8020000 MOV dword ptr [ESI + 0x2b8],EBX
    m.w32((s.si+0x000002b8u), s.bx);
  }
  L00618d69: { // 0x618d69: 899ebc020000 MOV dword ptr [ESI + 0x2bc],EBX
    m.w32((s.si+0x000002bcu), s.bx);
  }
  L00618d6f: { // 0x618d6f: 89aec0020000 MOV dword ptr [ESI + 0x2c0],EBP
    m.w32((s.si+0x000002c0u), s.bp);
  }
  L00618d75: { // 0x618d75: 899ec4020000 MOV dword ptr [ESI + 0x2c4],EBX
    m.w32((s.si+0x000002c4u), s.bx);
  }
  L00618d7b: { // 0x618d7b: 899ec8020000 MOV dword ptr [ESI + 0x2c8],EBX
    m.w32((s.si+0x000002c8u), s.bx);
  }
  L00618d81: { // 0x618d81: 899ecc020000 MOV dword ptr [ESI + 0x2cc],EBX
    m.w32((s.si+0x000002ccu), s.bx);
  }
  L00618d87: { // 0x618d87: 899ed0020000 MOV dword ptr [ESI + 0x2d0],EBX
    m.w32((s.si+0x000002d0u), s.bx);
  }
  L00618d8d: { // 0x618d8d: 899ed4020000 MOV dword ptr [ESI + 0x2d4],EBX
    m.w32((s.si+0x000002d4u), s.bx);
  }
  L00618d93: { // 0x618d93: 889ed8020000 MOV byte ptr [ESI + 0x2d8],BL
    m.w8((s.si+0x000002d8u), (s.bx & 0xffu));
  }
  L00618d99: { // 0x618d99: 889ed9020000 MOV byte ptr [ESI + 0x2d9],BL
    m.w8((s.si+0x000002d9u), (s.bx & 0xffu));
  }
  L00618d9f: { // 0x618d9f: 889eda020000 MOV byte ptr [ESI + 0x2da],BL
    m.w8((s.si+0x000002dau), (s.bx & 0xffu));
  }
  L00618da5: { // 0x618da5: c686db02000004 MOV byte ptr [ESI + 0x2db],0x4
    m.w8((s.si+0x000002dbu), 0x00000004u);
  }
  L00618dac: { // 0x618dac: 889edc020000 MOV byte ptr [ESI + 0x2dc],BL
    m.w8((s.si+0x000002dcu), (s.bx & 0xffu));
  }
  L00618db2: { // 0x618db2: 889edf020000 MOV byte ptr [ESI + 0x2df],BL
    m.w8((s.si+0x000002dfu), (s.bx & 0xffu));
  }
  L00618db8: { // 0x618db8: 8986e0020000 MOV dword ptr [ESI + 0x2e0],EAX
    m.w32((s.si+0x000002e0u), s.ax);
  }
  L00618dbe: { // 0x618dbe: 8986e4020000 MOV dword ptr [ESI + 0x2e4],EAX
    m.w32((s.si+0x000002e4u), s.ax);
  }
  L00618dc4: { // 0x618dc4: c70620357900 MOV dword ptr [ESI],0x793520
    m.w32((s.si), 0x00793520u);
  }
  L00618dca: { // 0x618dca: c7460404357900 MOV dword ptr [ESI + 0x4],0x793504
    m.w32((s.si+0x00000004u), 0x00793504u);
  }
  L00618dd1: { // 0x618dd1: c74608fc347900 MOV dword ptr [ESI + 0x8],0x7934fc
    m.w32((s.si+0x00000008u), 0x007934fcu);
  }
  L00618dd8: { // 0x618dd8: c7460cf4347900 MOV dword ptr [ESI + 0xc],0x7934f4
    m.w32((s.si+0x0000000cu), 0x007934f4u);
  }
  L00618ddf: { // 0x618ddf: a138e1a100 MOV EAX,[0x00a1e138]
    s.ax = m.r32((0x00a1e138u));
  }
  L00618de4: { // 0x618de4: 8b0d40e1a100 MOV ECX,dword ptr [0x00a1e140]
    s.cx = m.r32((0x00a1e140u));
  }
  L00618dea: { // 0x618dea: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00618dec: { // 0x618dec: 7c2c JL 0x00618e1a
    if(integer::condition("JL",flags)) goto L00618e1a;
  }
  L00618dee: { // 0x618dee: 381d3de1a100 CMP byte ptr [0x00a1e13d],BL
    (void)integer::sub(m.r8((0x00a1e13du)),(s.bx & 0xffu),8,flags);
  }
  L00618df4: { // 0x618df4: 7504 JNZ 0x00618dfa
    if(integer::condition("JNZ",flags)) goto L00618dfa;
  }
  L00618df6: { // 0x618df6: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00618df8: { // 0x618df8: 7538 JNZ 0x00618e32
    if(integer::condition("JNZ",flags)) goto L00618e32;
  }
  L00618dfa: { // 0x618dfa: 8b0d44e1a100 MOV ECX,dword ptr [0x00a1e144]
    s.cx = m.r32((0x00a1e144u));
  }
  L00618e00: { // 0x618e00: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L00618e02: { // 0x618e02: 7e2e JLE 0x00618e32
    if(integer::condition("JLE",flags)) goto L00618e32;
  }
  L00618e04: { // 0x618e04: 8b1530e1a100 MOV EDX,dword ptr [0x00a1e130]
    s.dx = m.r32((0x00a1e130u));
  }
  L00618e0a: { // 0x618e0a: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00618e0c: { // 0x618e0c: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00618e0d: { // 0x618e0d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00618e0e: { // 0x618e0e: b930e1a100 MOV ECX,0xa1e130
    s.cx = 0x00a1e130u;
  }
  L00618e13: { // 0x618e13: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),6393366u); flags=s.arithmetic_flags;
  }
  L00618e16: { // 0x618e16: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00618e18: { // 0x618e18: 7418 JZ 0x00618e32
    if(integer::condition("JZ",flags)) goto L00618e32;
  }
  L00618e1a: { // 0x618e1a: 8b0d40e1a100 MOV ECX,dword ptr [0x00a1e140]
    s.cx = m.r32((0x00a1e140u));
  }
  L00618e20: { // 0x618e20: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00618e22: { // 0x618e22: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00618e23: { // 0x618e23: 890d40e1a100 MOV dword ptr [0x00a1e140],ECX
    m.w32((0x00a1e140u), s.cx);
  }
  L00618e29: { // 0x618e29: 8b0d34e1a100 MOV ECX,dword ptr [0x00a1e134]
    s.cx = m.r32((0x00a1e134u));
  }
  L00618e2f: { // 0x618e2f: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L00618e32: { // 0x618e32: a1c087aa00 MOV EAX,[0x00aa87c0]
    s.ax = m.r32((0x00aa87c0u));
  }
  L00618e37: { // 0x618e37: 8b0dc887aa00 MOV ECX,dword ptr [0x00aa87c8]
    s.cx = m.r32((0x00aa87c8u));
  }
  L00618e3d: { // 0x618e3d: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00618e3f: { // 0x618e3f: 7c2c JL 0x00618e6d
    if(integer::condition("JL",flags)) goto L00618e6d;
  }
  L00618e41: { // 0x618e41: 381dc587aa00 CMP byte ptr [0x00aa87c5],BL
    (void)integer::sub(m.r8((0x00aa87c5u)),(s.bx & 0xffu),8,flags);
  }
  L00618e47: { // 0x618e47: 7504 JNZ 0x00618e4d
    if(integer::condition("JNZ",flags)) goto L00618e4d;
  }
  L00618e49: { // 0x618e49: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00618e4b: { // 0x618e4b: 7538 JNZ 0x00618e85
    if(integer::condition("JNZ",flags)) goto L00618e85;
  }
  L00618e4d: { // 0x618e4d: 8b0dcc87aa00 MOV ECX,dword ptr [0x00aa87cc]
    s.cx = m.r32((0x00aa87ccu));
  }
  L00618e53: { // 0x618e53: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L00618e55: { // 0x618e55: 7e2e JLE 0x00618e85
    if(integer::condition("JLE",flags)) goto L00618e85;
  }
  L00618e57: { // 0x618e57: 8b15b887aa00 MOV EDX,dword ptr [0x00aa87b8]
    s.dx = m.r32((0x00aa87b8u));
  }
  L00618e5d: { // 0x618e5d: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00618e5f: { // 0x618e5f: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00618e60: { // 0x618e60: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00618e61: { // 0x618e61: b9b887aa00 MOV ECX,0xaa87b8
    s.cx = 0x00aa87b8u;
  }
  L00618e66: { // 0x618e66: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),6393449u); flags=s.arithmetic_flags;
  }
  L00618e69: { // 0x618e69: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00618e6b: { // 0x618e6b: 7418 JZ 0x00618e85
    if(integer::condition("JZ",flags)) goto L00618e85;
  }
  L00618e6d: { // 0x618e6d: 8b0dc887aa00 MOV ECX,dword ptr [0x00aa87c8]
    s.cx = m.r32((0x00aa87c8u));
  }
  L00618e73: { // 0x618e73: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00618e75: { // 0x618e75: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00618e76: { // 0x618e76: 890dc887aa00 MOV dword ptr [0x00aa87c8],ECX
    m.w32((0x00aa87c8u), s.cx);
  }
  L00618e7c: { // 0x618e7c: 8b0dbc87aa00 MOV ECX,dword ptr [0x00aa87bc]
    s.cx = m.r32((0x00aa87bcu));
  }
  L00618e82: { // 0x618e82: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L00618e85: { // 0x618e85: 889e04020000 MOV byte ptr [ESI + 0x204],BL
    m.w8((s.si+0x00000204u), (s.bx & 0xffu));
  }
  L00618e8b: { // 0x618e8b: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00618e8d: { // 0x618e8d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00618e8e: { // 0x618e8e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00618e8f: { // 0x618e8f: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00618e90: { // 0x618e90: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00618e91: { // 0x618e91: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00702d60(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00702d60: { // 0x702d60: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L00702d64: { // 0x702d64: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00702d65: { // 0x702d65: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00702d66: { // 0x702d66: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00702d68: { // 0x702d68: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00702d69: { // 0x702d69: e812b1ecff CALL 0x005cde80
    s.arithmetic_flags=flags; invoke(m,s,f,0x005cde80u,7351662u); flags=s.arithmetic_flags;
  }
  L00702d6e: { // 0x702d6e: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L00702d71: { // 0x702d71: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00702d73: { // 0x702d73: 8986ac020000 MOV dword ptr [ESI + 0x2ac],EAX
    m.w32((s.si+0x000002acu), s.ax);
  }
  L00702d79: { // 0x702d79: 8986b0020000 MOV dword ptr [ESI + 0x2b0],EAX
    m.w32((s.si+0x000002b0u), s.ax);
  }
  L00702d7f: { // 0x702d7f: 889e64020000 MOV byte ptr [ESI + 0x264],BL
    m.w8((s.si+0x00000264u), (s.bx & 0xffu));
  }
  L00702d85: { // 0x702d85: 8d4604 LEA EAX,[ESI + 0x4]
    s.ax = (s.si+0x00000004u);
  }
  L00702d88: { // 0x702d88: 889e65020000 MOV byte ptr [ESI + 0x265],BL
    m.w8((s.si+0x00000265u), (s.bx & 0xffu));
  }
  L00702d8e: { // 0x702d8e: 889e66020000 MOV byte ptr [ESI + 0x266],BL
    m.w8((s.si+0x00000266u), (s.bx & 0xffu));
  }
  L00702d94: { // 0x702d94: c78670020000000000a0 MOV dword ptr [ESI + 0x270],0xa0000000
    m.w32((s.si+0x00000270u), 0xa0000000u);
  }
  L00702d9e: { // 0x702d9e: 899e78020000 MOV dword ptr [ESI + 0x278],EBX
    m.w32((s.si+0x00000278u), s.bx);
  }
  L00702da4: { // 0x702da4: c786800200004649e61c MOV dword ptr [ESI + 0x280],0x1ce64946
    m.w32((s.si+0x00000280u), 0x1ce64946u);
  }
  L00702dae: { // 0x702dae: 899e88020000 MOV dword ptr [ESI + 0x288],EBX
    m.w32((s.si+0x00000288u), s.bx);
  }
  L00702db4: { // 0x702db4: 899e90020000 MOV dword ptr [ESI + 0x290],EBX
    m.w32((s.si+0x00000290u), s.bx);
  }
  L00702dba: { // 0x702dba: 899e98020000 MOV dword ptr [ESI + 0x298],EBX
    m.w32((s.si+0x00000298u), s.bx);
  }
  L00702dc0: { // 0x702dc0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00702dc1: { // 0x702dc1: 899e68020000 MOV dword ptr [ESI + 0x268],EBX
    m.w32((s.si+0x00000268u), s.bx);
  }
  L00702dc7: { // 0x702dc7: c7866c0200001e000000 MOV dword ptr [ESI + 0x26c],0x1e
    m.w32((s.si+0x0000026cu), 0x0000001eu);
  }
  L00702dd1: { // 0x702dd1: c786740200009999e93f MOV dword ptr [ESI + 0x274],0x3fe99999
    m.w32((s.si+0x00000274u), 0x3fe99999u);
  }
  L00702ddb: { // 0x702ddb: 899e7c020000 MOV dword ptr [ESI + 0x27c],EBX
    m.w32((s.si+0x0000027cu), s.bx);
  }
  L00702de1: { // 0x702de1: c78684020000ed56c63f MOV dword ptr [ESI + 0x284],0x3fc656ed
    m.w32((s.si+0x00000284u), 0x3fc656edu);
  }
  L00702deb: { // 0x702deb: c7868c02000000000c40 MOV dword ptr [ESI + 0x28c],0x400c0000
    m.w32((s.si+0x0000028cu), 0x400c0000u);
  }
  L00702df5: { // 0x702df5: c7869402000000001440 MOV dword ptr [ESI + 0x294],0x40140000
    m.w32((s.si+0x00000294u), 0x40140000u);
  }
  L00702dff: { // 0x702dff: c7869c02000000002e40 MOV dword ptr [ESI + 0x29c],0x402e0000
    m.w32((s.si+0x0000029cu), 0x402e0000u);
  }
  L00702e09: { // 0x702e09: 889ea0020000 MOV byte ptr [ESI + 0x2a0],BL
    m.w8((s.si+0x000002a0u), (s.bx & 0xffu));
  }
  L00702e0f: { // 0x702e0f: 899ea4020000 MOV dword ptr [ESI + 0x2a4],EBX
    m.w32((s.si+0x000002a4u), s.bx);
  }
  L00702e15: { // 0x702e15: 899ea8020000 MOV dword ptr [ESI + 0x2a8],EBX
    m.w32((s.si+0x000002a8u), s.bx);
  }
  L00702e1b: { // 0x702e1b: 899eb4020000 MOV dword ptr [ESI + 0x2b4],EBX
    m.w32((s.si+0x000002b4u), s.bx);
  }
  L00702e21: { // 0x702e21: 899eb8020000 MOV dword ptr [ESI + 0x2b8],EBX
    m.w32((s.si+0x000002b8u), s.bx);
  }
  L00702e27: { // 0x702e27: 899ebc020000 MOV dword ptr [ESI + 0x2bc],EBX
    m.w32((s.si+0x000002bcu), s.bx);
  }
  L00702e2d: { // 0x702e2d: 899ec0020000 MOV dword ptr [ESI + 0x2c0],EBX
    m.w32((s.si+0x000002c0u), s.bx);
  }
  L00702e33: { // 0x702e33: 899ec4020000 MOV dword ptr [ESI + 0x2c4],EBX
    m.w32((s.si+0x000002c4u), s.bx);
  }
  L00702e39: { // 0x702e39: 899ec8020000 MOV dword ptr [ESI + 0x2c8],EBX
    m.w32((s.si+0x000002c8u), s.bx);
  }
  L00702e3f: { // 0x702e3f: 899ecc020000 MOV dword ptr [ESI + 0x2cc],EBX
    m.w32((s.si+0x000002ccu), s.bx);
  }
  L00702e45: { // 0x702e45: 889ed0020000 MOV byte ptr [ESI + 0x2d0],BL
    m.w8((s.si+0x000002d0u), (s.bx & 0xffu));
  }
  L00702e4b: { // 0x702e4b: c706d0947900 MOV dword ptr [ESI],0x7994d0
    m.w32((s.si), 0x007994d0u);
  }
  L00702e51: { // 0x702e51: c700b4947900 MOV dword ptr [EAX],0x7994b4
    m.w32((s.ax), 0x007994b4u);
  }
  L00702e57: { // 0x702e57: c74608ac947900 MOV dword ptr [ESI + 0x8],0x7994ac
    m.w32((s.si+0x00000008u), 0x007994acu);
  }
  L00702e5e: { // 0x702e5e: c7460ca4947900 MOV dword ptr [ESI + 0xc],0x7994a4
    m.w32((s.si+0x0000000cu), 0x007994a4u);
  }
  L00702e65: { // 0x702e65: e866d1d0ff CALL 0x0040ffd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0040ffd0u,7351914u); flags=s.arithmetic_flags;
  }
  L00702e6a: { // 0x702e6a: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00702e6c: { // 0x702e6c: 889e01020000 MOV byte ptr [ESI + 0x201],BL
    m.w8((s.si+0x00000201u), (s.bx & 0xffu));
  }
  L00702e72: { // 0x702e72: 888604020000 MOV byte ptr [ESI + 0x204],AL
    m.w8((s.si+0x00000204u), (s.ax & 0xffu));
  }
  L00702e78: { // 0x702e78: 8886ff010000 MOV byte ptr [ESI + 0x1ff],AL
    m.w8((s.si+0x000001ffu), (s.ax & 0xffu));
  }
  L00702e7e: { // 0x702e7e: 888600020000 MOV byte ptr [ESI + 0x200],AL
    m.w8((s.si+0x00000200u), (s.ax & 0xffu));
  }
  L00702e84: { // 0x702e84: 888602020000 MOV byte ptr [ESI + 0x202],AL
    m.w8((s.si+0x00000202u), (s.ax & 0xffu));
  }
  L00702e8a: { // 0x702e8a: 888603020000 MOV byte ptr [ESI + 0x203],AL
    m.w8((s.si+0x00000203u), (s.ax & 0xffu));
  }
  L00702e90: { // 0x702e90: 889e05020000 MOV byte ptr [ESI + 0x205],BL
    m.w8((s.si+0x00000205u), (s.bx & 0xffu));
  }
  L00702e96: { // 0x702e96: a1c087aa00 MOV EAX,[0x00aa87c0]
    s.ax = m.r32((0x00aa87c0u));
  }
  L00702e9b: { // 0x702e9b: 8b0dc887aa00 MOV ECX,dword ptr [0x00aa87c8]
    s.cx = m.r32((0x00aa87c8u));
  }
  L00702ea1: { // 0x702ea1: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00702ea3: { // 0x702ea3: 7c2c JL 0x00702ed1
    if(integer::condition("JL",flags)) goto L00702ed1;
  }
  L00702ea5: { // 0x702ea5: 381dc587aa00 CMP byte ptr [0x00aa87c5],BL
    (void)integer::sub(m.r8((0x00aa87c5u)),(s.bx & 0xffu),8,flags);
  }
  L00702eab: { // 0x702eab: 7504 JNZ 0x00702eb1
    if(integer::condition("JNZ",flags)) goto L00702eb1;
  }
  L00702ead: { // 0x702ead: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00702eaf: { // 0x702eaf: 7538 JNZ 0x00702ee9
    if(integer::condition("JNZ",flags)) goto L00702ee9;
  }
  L00702eb1: { // 0x702eb1: 8b0dcc87aa00 MOV ECX,dword ptr [0x00aa87cc]
    s.cx = m.r32((0x00aa87ccu));
  }
  L00702eb7: { // 0x702eb7: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L00702eb9: { // 0x702eb9: 7e2e JLE 0x00702ee9
    if(integer::condition("JLE",flags)) goto L00702ee9;
  }
  L00702ebb: { // 0x702ebb: 8b15b887aa00 MOV EDX,dword ptr [0x00aa87b8]
    s.dx = m.r32((0x00aa87b8u));
  }
  L00702ec1: { // 0x702ec1: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00702ec3: { // 0x702ec3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00702ec4: { // 0x702ec4: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00702ec5: { // 0x702ec5: b9b887aa00 MOV ECX,0xaa87b8
    s.cx = 0x00aa87b8u;
  }
  L00702eca: { // 0x702eca: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),7352013u); flags=s.arithmetic_flags;
  }
  L00702ecd: { // 0x702ecd: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00702ecf: { // 0x702ecf: 7418 JZ 0x00702ee9
    if(integer::condition("JZ",flags)) goto L00702ee9;
  }
  L00702ed1: { // 0x702ed1: 8b0dc887aa00 MOV ECX,dword ptr [0x00aa87c8]
    s.cx = m.r32((0x00aa87c8u));
  }
  L00702ed7: { // 0x702ed7: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00702ed9: { // 0x702ed9: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00702eda: { // 0x702eda: 890dc887aa00 MOV dword ptr [0x00aa87c8],ECX
    m.w32((0x00aa87c8u), s.cx);
  }
  L00702ee0: { // 0x702ee0: 8b0dbc87aa00 MOV ECX,dword ptr [0x00aa87bc]
    s.cx = m.r32((0x00aa87bcu));
  }
  L00702ee6: { // 0x702ee6: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L00702ee9: { // 0x702ee9: a12887a200 MOV EAX,[0x00a28728]
    s.ax = m.r32((0x00a28728u));
  }
  L00702eee: { // 0x702eee: 8b0d3087a200 MOV ECX,dword ptr [0x00a28730]
    s.cx = m.r32((0x00a28730u));
  }
  L00702ef4: { // 0x702ef4: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00702ef6: { // 0x702ef6: 7c2c JL 0x00702f24
    if(integer::condition("JL",flags)) goto L00702f24;
  }
  L00702ef8: { // 0x702ef8: 381d2d87a200 CMP byte ptr [0x00a2872d],BL
    (void)integer::sub(m.r8((0x00a2872du)),(s.bx & 0xffu),8,flags);
  }
  L00702efe: { // 0x702efe: 7504 JNZ 0x00702f04
    if(integer::condition("JNZ",flags)) goto L00702f04;
  }
  L00702f00: { // 0x702f00: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00702f02: { // 0x702f02: 7538 JNZ 0x00702f3c
    if(integer::condition("JNZ",flags)) goto L00702f3c;
  }
  L00702f04: { // 0x702f04: 8b0d3487a200 MOV ECX,dword ptr [0x00a28734]
    s.cx = m.r32((0x00a28734u));
  }
  L00702f0a: { // 0x702f0a: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L00702f0c: { // 0x702f0c: 7e2e JLE 0x00702f3c
    if(integer::condition("JLE",flags)) goto L00702f3c;
  }
  L00702f0e: { // 0x702f0e: 8b152087a200 MOV EDX,dword ptr [0x00a28720]
    s.dx = m.r32((0x00a28720u));
  }
  L00702f14: { // 0x702f14: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00702f16: { // 0x702f16: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00702f17: { // 0x702f17: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00702f18: { // 0x702f18: b92087a200 MOV ECX,0xa28720
    s.cx = 0x00a28720u;
  }
  L00702f1d: { // 0x702f1d: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),7352096u); flags=s.arithmetic_flags;
  }
  L00702f20: { // 0x702f20: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00702f22: { // 0x702f22: 7418 JZ 0x00702f3c
    if(integer::condition("JZ",flags)) goto L00702f3c;
  }
  L00702f24: { // 0x702f24: 8b0d3087a200 MOV ECX,dword ptr [0x00a28730]
    s.cx = m.r32((0x00a28730u));
  }
  L00702f2a: { // 0x702f2a: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00702f2c: { // 0x702f2c: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00702f2d: { // 0x702f2d: 890d3087a200 MOV dword ptr [0x00a28730],ECX
    m.w32((0x00a28730u), s.cx);
  }
  L00702f33: { // 0x702f33: 8b0d2487a200 MOV ECX,dword ptr [0x00a28724]
    s.cx = m.r32((0x00a28724u));
  }
  L00702f39: { // 0x702f39: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L00702f3c: { // 0x702f3c: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00702f3e: { // 0x702f3e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00702f3f: { // 0x702f3f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00702f40: { // 0x702f40: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
