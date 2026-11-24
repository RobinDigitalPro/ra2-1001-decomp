#include "recovered/recovery_b1659.hpp"
namespace ra2::recovered::b1659 {
using namespace floating_b61;using Frame=recovery_b566::Frame;
using recovery_b566::finish;using recovery_b566::string_instruction;using recovery_b566::Kind;using recovery_b566::Repeat;using recovery_b566::reverse_divide32;using recovery_b566::reverse_divide64;
namespace integer=direct_b33::integer;namespace floating_b61=ra2::recovered::floating_b61;namespace numeric_b88=ra2::recovered::numeric_b88;
namespace {inline void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
void invoke(Memory&,State&,Frame&,unsigned,unsigned,const Operations&);
void f_00130cc0(Memory&,State&,Frame&,const Operations&);
void f_00130730(Memory&,State&,Frame&,const Operations&);
void f_001228e0(Memory&,State&,Frame&,const Operations&);

void f_00130cc0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00530cc0: { // 0x530cc0: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L00530cc3: { // 0x530cc3: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L00530cc7: { // 0x530cc7: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00530cc8: { // 0x530cc8: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00530cc9: { // 0x530cc9: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00530cca: { // 0x530cca: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00530ccc: { // 0x530ccc: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  L00530cd0: { // 0x530cd0: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00530cd2: { // 0x530cd2: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00530cd3: { // 0x530cd3: c1e810 SHR EAX,0x10
    s.ax = integer::shift(s.ax,0x00000010u,32,flags,integer::Shift::right);
  }
  L00530cd6: { // 0x530cd6: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L00530cda: { // 0x530cda: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L00530cde: { // 0x530cde: 81e1ffff0000 AND ECX,0xffff
    s.cx = integer::logical((s.cx)&(0x0000ffffu),32,flags);
  }
  L00530ce4: { // 0x530ce4: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00530ce5: { // 0x530ce5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00530ce6: { // 0x530ce6: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L00530cea: { // 0x530cea: ff15ac547800 CALL dword ptr [0x007854ac]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((0x007854acu)),5442800u,op); flags=s.arithmetic_flags;
  }
  L00530cf0: { // 0x530cf0: 8b0da81f8200 MOV ECX,dword ptr [0x00821fa8]
    s.cx = m.r32((0x00821fa8u));
  }
  L00530cf6: { // 0x530cf6: 8b7c2418 MOV EDI,dword ptr [ESP + 0x18]
    s.di = m.r32((f.sp+0x00000018u));
  }
  L00530cfa: { // 0x530cfa: 8b6c241c MOV EBP,dword ptr [ESP + 0x1c]
    s.bp = m.r32((f.sp+0x0000001cu));
  }
  L00530cfe: { // 0x530cfe: 897c2414 MOV dword ptr [ESP + 0x14],EDI
    m.w32((f.sp+0x00000014u), s.di);
  }
  L00530d02: { // 0x530d02: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00530d04: { // 0x530d04: 896c2410 MOV dword ptr [ESP + 0x10],EBP
    m.w32((f.sp+0x00000010u), s.bp);
  }
  L00530d08: { // 0x530d08: 7417 JZ 0x00530d21
    if(integer::condition("JZ",flags)) goto L00530d21;
  }
  L00530d0a: { // 0x530d0a: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00530d0c: { // 0x530d0c: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L00530d10: { // 0x530d10: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00530d11: { // 0x530d11: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L00530d15: { // 0x530d15: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00530d16: { // 0x530d16: ff5244 CALL dword ptr [EDX + 0x44]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000044u)),5442841u,op); flags=s.arithmetic_flags;
  }
  L00530d19: { // 0x530d19: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L00530d1d: { // 0x530d1d: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L00530d21: { // 0x530d21: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L00530d25: { // 0x530d25: 8b5c242c MOV EBX,dword ptr [ESP + 0x2c]
    s.bx = m.r32((f.sp+0x0000002cu));
  }
  L00530d29: { // 0x530d29: 3d01020000 CMP EAX,0x201
    (void)integer::sub(s.ax,0x00000201u,32,flags);
  }
  L00530d2e: { // 0x530d2e: 0f8704010000 JA 0x00530e38
    if(integer::condition("JA",flags)) goto L00530e38;
  }
  L00530d34: { // 0x530d34: 3d01020000 CMP EAX,0x201
    (void)integer::sub(s.ax,0x00000201u,32,flags);
  }
  L00530d39: { // 0x530d39: 0f84aa000000 JZ 0x00530de9
    if(integer::condition("JZ",flags)) goto L00530de9;
  }
  L00530d3f: { // 0x530d3f: 0500ffffff ADD EAX,0xffffff00
    s.ax = integer::add(s.ax,0xffffff00u,32,flags);
  }
  L00530d44: { // 0x530d44: 83f805 CMP EAX,0x5
    (void)integer::sub(s.ax,0x00000005u,32,flags);
  }
  L00530d47: { // 0x530d47: 0f8720030000 JA 0x0053106d
    if(integer::condition("JA",flags)) goto L0053106d;
  }
  L00530d4d: { // 0x530d4d: ff24857c105300 JMP dword ptr [EAX*0x4 + 0x53107c]
    switch(m.r32(((s.ax * 0x00000004u)+0x0053107cu))){
    case 0x00530cc0u: goto L00530cc0;
    case 0x00530cc3u: goto L00530cc3;
    case 0x00530cc7u: goto L00530cc7;
    case 0x00530cc8u: goto L00530cc8;
    case 0x00530cc9u: goto L00530cc9;
    case 0x00530ccau: goto L00530cca;
    case 0x00530cccu: goto L00530ccc;
    case 0x00530cd0u: goto L00530cd0;
    case 0x00530cd2u: goto L00530cd2;
    case 0x00530cd3u: goto L00530cd3;
    case 0x00530cd6u: goto L00530cd6;
    case 0x00530cdau: goto L00530cda;
    case 0x00530cdeu: goto L00530cde;
    case 0x00530ce4u: goto L00530ce4;
    case 0x00530ce5u: goto L00530ce5;
    case 0x00530ce6u: goto L00530ce6;
    case 0x00530ceau: goto L00530cea;
    case 0x00530cf0u: goto L00530cf0;
    case 0x00530cf6u: goto L00530cf6;
    case 0x00530cfau: goto L00530cfa;
    case 0x00530cfeu: goto L00530cfe;
    case 0x00530d02u: goto L00530d02;
    case 0x00530d04u: goto L00530d04;
    case 0x00530d08u: goto L00530d08;
    case 0x00530d0au: goto L00530d0a;
    case 0x00530d0cu: goto L00530d0c;
    case 0x00530d10u: goto L00530d10;
    case 0x00530d11u: goto L00530d11;
    case 0x00530d15u: goto L00530d15;
    case 0x00530d16u: goto L00530d16;
    case 0x00530d19u: goto L00530d19;
    case 0x00530d1du: goto L00530d1d;
    case 0x00530d21u: goto L00530d21;
    case 0x00530d25u: goto L00530d25;
    case 0x00530d29u: goto L00530d29;
    case 0x00530d2eu: goto L00530d2e;
    case 0x00530d34u: goto L00530d34;
    case 0x00530d39u: goto L00530d39;
    case 0x00530d3fu: goto L00530d3f;
    case 0x00530d44u: goto L00530d44;
    case 0x00530d47u: goto L00530d47;
    case 0x00530d4du: goto L00530d4d;
    case 0x00530d54u: goto L00530d54;
    case 0x00530d5au: goto L00530d5a;
    case 0x00530d60u: goto L00530d60;
    case 0x00530d68u: goto L00530d68;
    case 0x00530d6eu: goto L00530d6e;
    case 0x00530d70u: goto L00530d70;
    case 0x00530d71u: goto L00530d71;
    case 0x00530d73u: goto L00530d73;
    case 0x00530d78u: goto L00530d78;
    case 0x00530d7du: goto L00530d7d;
    case 0x00530d7fu: goto L00530d7f;
    case 0x00530d80u: goto L00530d80;
    case 0x00530d82u: goto L00530d82;
    case 0x00530d87u: goto L00530d87;
    case 0x00530d8cu: goto L00530d8c;
    case 0x00530d91u: goto L00530d91;
    case 0x00530d93u: goto L00530d93;
    case 0x00530d99u: goto L00530d99;
    case 0x00530d9eu: goto L00530d9e;
    case 0x00530da0u: goto L00530da0;
    case 0x00530da6u: goto L00530da6;
    case 0x00530dacu: goto L00530dac;
    case 0x00530db2u: goto L00530db2;
    case 0x00530db4u: goto L00530db4;
    case 0x00530db9u: goto L00530db9;
    case 0x00530dbau: goto L00530dba;
    case 0x00530dbcu: goto L00530dbc;
    case 0x00530dbeu: goto L00530dbe;
    case 0x00530dc0u: goto L00530dc0;
    case 0x00530dc3u: goto L00530dc3;
    case 0x00530dc9u: goto L00530dc9;
    case 0x00530dcbu: goto L00530dcb;
    case 0x00530dcdu: goto L00530dcd;
    case 0x00530dcfu: goto L00530dcf;
    case 0x00530dd4u: goto L00530dd4;
    case 0x00530dd6u: goto L00530dd6;
    case 0x00530dd8u: goto L00530dd8;
    case 0x00530ddeu: goto L00530dde;
    case 0x00530ddfu: goto L00530ddf;
    case 0x00530de4u: goto L00530de4;
    case 0x00530de9u: goto L00530de9;
    case 0x00530deeu: goto L00530dee;
    case 0x00530df0u: goto L00530df0;
    case 0x00530df6u: goto L00530df6;
    case 0x00530dfcu: goto L00530dfc;
    case 0x00530e02u: goto L00530e02;
    case 0x00530e04u: goto L00530e04;
    case 0x00530e09u: goto L00530e09;
    case 0x00530e0au: goto L00530e0a;
    case 0x00530e0cu: goto L00530e0c;
    case 0x00530e0eu: goto L00530e0e;
    case 0x00530e10u: goto L00530e10;
    case 0x00530e13u: goto L00530e13;
    case 0x00530e19u: goto L00530e19;
    case 0x00530e1bu: goto L00530e1b;
    case 0x00530e1du: goto L00530e1d;
    case 0x00530e1fu: goto L00530e1f;
    case 0x00530e24u: goto L00530e24;
    case 0x00530e26u: goto L00530e26;
    case 0x00530e2bu: goto L00530e2b;
    case 0x00530e2du: goto L00530e2d;
    case 0x00530e33u: goto L00530e33;
    case 0x00530e38u: goto L00530e38;
    case 0x00530e3du: goto L00530e3d;
    case 0x00530e40u: goto L00530e40;
    case 0x00530e46u: goto L00530e46;
    case 0x00530e4du: goto L00530e4d;
    case 0x00530e52u: goto L00530e52;
    case 0x00530e54u: goto L00530e54;
    case 0x00530e5au: goto L00530e5a;
    case 0x00530e60u: goto L00530e60;
    case 0x00530e66u: goto L00530e66;
    case 0x00530e68u: goto L00530e68;
    case 0x00530e69u: goto L00530e69;
    case 0x00530e6bu: goto L00530e6b;
    case 0x00530e6du: goto L00530e6d;
    case 0x00530e72u: goto L00530e72;
    case 0x00530e74u: goto L00530e74;
    case 0x00530e77u: goto L00530e77;
    case 0x00530e7du: goto L00530e7d;
    case 0x00530e7fu: goto L00530e7f;
    case 0x00530e81u: goto L00530e81;
    case 0x00530e86u: goto L00530e86;
    case 0x00530e88u: goto L00530e88;
    case 0x00530e8eu: goto L00530e8e;
    case 0x00530e94u: goto L00530e94;
    case 0x00530e9au: goto L00530e9a;
    case 0x00530e9cu: goto L00530e9c;
    case 0x00530ea1u: goto L00530ea1;
    case 0x00530ea2u: goto L00530ea2;
    case 0x00530ea4u: goto L00530ea4;
    case 0x00530ea6u: goto L00530ea6;
    case 0x00530ea8u: goto L00530ea8;
    case 0x00530eabu: goto L00530eab;
    case 0x00530eadu: goto L00530ead;
    case 0x00530eafu: goto L00530eaf;
    case 0x00530eb1u: goto L00530eb1;
    case 0x00530eb3u: goto L00530eb3;
    case 0x00530eb8u: goto L00530eb8;
    case 0x00530ebau: goto L00530eba;
    case 0x00530ebfu: goto L00530ebf;
    case 0x00530ec1u: goto L00530ec1;
    case 0x00530ec3u: goto L00530ec3;
    case 0x00530ec4u: goto L00530ec4;
    case 0x00530ec6u: goto L00530ec6;
    case 0x00530ecbu: goto L00530ecb;
    case 0x00530eccu: goto L00530ecc;
    case 0x00530eceu: goto L00530ece;
    case 0x00530ed3u: goto L00530ed3;
    case 0x00530ed7u: goto L00530ed7;
    case 0x00530edbu: goto L00530edb;
    case 0x00530ee0u: goto L00530ee0;
    case 0x00530ee2u: goto L00530ee2;
    case 0x00530ee8u: goto L00530ee8;
    case 0x00530eeeu: goto L00530eee;
    case 0x00530ef4u: goto L00530ef4;
    case 0x00530ef6u: goto L00530ef6;
    case 0x00530ef7u: goto L00530ef7;
    case 0x00530ef9u: goto L00530ef9;
    case 0x00530efbu: goto L00530efb;
    case 0x00530f00u: goto L00530f00;
    case 0x00530f02u: goto L00530f02;
    case 0x00530f05u: goto L00530f05;
    case 0x00530f0bu: goto L00530f0b;
    case 0x00530f0du: goto L00530f0d;
    case 0x00530f0fu: goto L00530f0f;
    case 0x00530f11u: goto L00530f11;
    case 0x00530f16u: goto L00530f16;
    case 0x00530f18u: goto L00530f18;
    case 0x00530f1du: goto L00530f1d;
    case 0x00530f1fu: goto L00530f1f;
    case 0x00530f21u: goto L00530f21;
    case 0x00530f22u: goto L00530f22;
    case 0x00530f24u: goto L00530f24;
    case 0x00530f29u: goto L00530f29;
    case 0x00530f2au: goto L00530f2a;
    case 0x00530f2cu: goto L00530f2c;
    case 0x00530f31u: goto L00530f31;
    case 0x00530f36u: goto L00530f36;
    case 0x00530f3bu: goto L00530f3b;
    case 0x00530f3du: goto L00530f3d;
    case 0x00530f43u: goto L00530f43;
    case 0x00530f49u: goto L00530f49;
    case 0x00530f4fu: goto L00530f4f;
    case 0x00530f51u: goto L00530f51;
    case 0x00530f56u: goto L00530f56;
    case 0x00530f57u: goto L00530f57;
    case 0x00530f59u: goto L00530f59;
    case 0x00530f5bu: goto L00530f5b;
    case 0x00530f5du: goto L00530f5d;
    case 0x00530f60u: goto L00530f60;
    case 0x00530f66u: goto L00530f66;
    case 0x00530f68u: goto L00530f68;
    case 0x00530f6au: goto L00530f6a;
    case 0x00530f6cu: goto L00530f6c;
    case 0x00530f71u: goto L00530f71;
    case 0x00530f72u: goto L00530f72;
    case 0x00530f74u: goto L00530f74;
    case 0x00530f79u: goto L00530f79;
    case 0x00530f7au: goto L00530f7a;
    case 0x00530f7cu: goto L00530f7c;
    case 0x00530f81u: goto L00530f81;
    case 0x00530f86u: goto L00530f86;
    case 0x00530f8bu: goto L00530f8b;
    case 0x00530f8du: goto L00530f8d;
    case 0x00530f93u: goto L00530f93;
    case 0x00530f99u: goto L00530f99;
    case 0x00530f9fu: goto L00530f9f;
    case 0x00530fa1u: goto L00530fa1;
    case 0x00530fa6u: goto L00530fa6;
    case 0x00530fa7u: goto L00530fa7;
    case 0x00530fa9u: goto L00530fa9;
    case 0x00530fabu: goto L00530fab;
    case 0x00530fadu: goto L00530fad;
    case 0x00530fb0u: goto L00530fb0;
    case 0x00530fb2u: goto L00530fb2;
    case 0x00530fb4u: goto L00530fb4;
    case 0x00530fb6u: goto L00530fb6;
    case 0x00530fb8u: goto L00530fb8;
    case 0x00530fbdu: goto L00530fbd;
    case 0x00530fbeu: goto L00530fbe;
    case 0x00530fc0u: goto L00530fc0;
    case 0x00530fc5u: goto L00530fc5;
    case 0x00530fc6u: goto L00530fc6;
    case 0x00530fc8u: goto L00530fc8;
    case 0x00530fcdu: goto L00530fcd;
    case 0x00530fd1u: goto L00530fd1;
    case 0x00530fd5u: goto L00530fd5;
    case 0x00530fdau: goto L00530fda;
    case 0x00530fdcu: goto L00530fdc;
    case 0x00530fdeu: goto L00530fde;
    case 0x00530fe4u: goto L00530fe4;
    case 0x00530feau: goto L00530fea;
    case 0x00530fecu: goto L00530fec;
    case 0x00530fedu: goto L00530fed;
    case 0x00530fefu: goto L00530fef;
    case 0x00530ff1u: goto L00530ff1;
    case 0x00530ff6u: goto L00530ff6;
    case 0x00530ff8u: goto L00530ff8;
    case 0x00530ffbu: goto L00530ffb;
    case 0x00530ffdu: goto L00530ffd;
    case 0x00530fffu: goto L00530fff;
    case 0x00531001u: goto L00531001;
    case 0x00531003u: goto L00531003;
    case 0x00531008u: goto L00531008;
    case 0x00531009u: goto L00531009;
    case 0x0053100bu: goto L0053100b;
    case 0x00531010u: goto L00531010;
    case 0x00531011u: goto L00531011;
    case 0x00531013u: goto L00531013;
    case 0x00531018u: goto L00531018;
    case 0x0053101au: goto L0053101a;
    case 0x0053101cu: goto L0053101c;
    case 0x0053101du: goto L0053101d;
    case 0x0053101eu: goto L0053101e;
    case 0x00531020u: goto L00531020;
    case 0x00531022u: goto L00531022;
    case 0x00531023u: goto L00531023;
    case 0x00531024u: goto L00531024;
    case 0x00531026u: goto L00531026;
    case 0x00531028u: goto L00531028;
    case 0x00531029u: goto L00531029;
    case 0x0053102au: goto L0053102a;
    case 0x0053102cu: goto L0053102c;
    case 0x0053102eu: goto L0053102e;
    case 0x00531033u: goto L00531033;
    case 0x00531037u: goto L00531037;
    case 0x0053103bu: goto L0053103b;
    case 0x0053103du: goto L0053103d;
    case 0x0053103eu: goto L0053103e;
    case 0x0053103fu: goto L0053103f;
    case 0x00531041u: goto L00531041;
    case 0x00531043u: goto L00531043;
    case 0x00531048u: goto L00531048;
    case 0x0053104cu: goto L0053104c;
    case 0x00531050u: goto L00531050;
    case 0x00531054u: goto L00531054;
    case 0x00531055u: goto L00531055;
    case 0x00531056u: goto L00531056;
    case 0x00531057u: goto L00531057;
    case 0x00531058u: goto L00531058;
    case 0x0053105eu: goto L0053105e;
    case 0x0053105fu: goto L0053105f;
    case 0x00531060u: goto L00531060;
    case 0x00531061u: goto L00531061;
    case 0x00531066u: goto L00531066;
    case 0x00531067u: goto L00531067;
    case 0x0053106au: goto L0053106a;
    case 0x0053106du: goto L0053106d;
    case 0x0053106eu: goto L0053106e;
    case 0x0053106fu: goto L0053106f;
    case 0x00531070u: goto L00531070;
    case 0x00531072u: goto L00531072;
    case 0x00531073u: goto L00531073;
    case 0x00531076u: goto L00531076;
    default:throw std::domain_error("recovery107 unsupported switch destination");}
  }
  L00530d54: { // 0x530d54: 81fb91000000 CMP EBX,0x91
    (void)integer::sub(s.bx,0x00000091u,32,flags);
  }
  L00530d5a: { // 0x530d5a: 0f84e8020000 JZ 0x00531048
    if(integer::condition("JZ",flags)) goto L00531048;
  }
  L00530d60: { // 0x530d60: f744243000000040 TEST dword ptr [ESP + 0x30],0x40000000
    (void)integer::logical((m.r32((f.sp+0x00000030u)))&(0x40000000u),32,flags);
  }
  L00530d68: { // 0x530d68: 0f85da020000 JNZ 0x00531048
    if(integer::condition("JNZ",flags)) goto L00531048;
  }
  L00530d6e: { // 0x530d6e: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00530d70: { // 0x530d70: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00530d71: { // 0x530d71: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00530d73: { // 0x530d73: e8b8f9ffff CALL 0x00530730
    s.arithmetic_flags=flags; invoke(m,s,f,0x00530730u,5442936u,op); flags=s.arithmetic_flags;
  }
  L00530d78: { // 0x530d78: e9cb020000 JMP 0x00531048
    goto L00531048;
  }
  L00530d7d: { // 0x530d7d: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00530d7f: { // 0x530d7f: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00530d80: { // 0x530d80: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00530d82: { // 0x530d82: e8a9f9ffff CALL 0x00530730
    s.arithmetic_flags=flags; invoke(m,s,f,0x00530730u,5442951u,op); flags=s.arithmetic_flags;
  }
  L00530d87: { // 0x530d87: e9bc020000 JMP 0x00531048
    goto L00531048;
  }
  L00530d8c: { // 0x530d8c: a0b95fa200 MOV AL,[0x00a25fb9]
    s.ax = with_al(s.ax, m.r8((0x00a25fb9u)));
  }
  L00530d91: { // 0x530d91: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00530d93: { // 0x530d93: 0f84af020000 JZ 0x00531048
    if(integer::condition("JZ",flags)) goto L00531048;
  }
  L00530d99: { // 0x530d99: a08489a200 MOV AL,[0x00a28984]
    s.ax = with_al(s.ax, m.r8((0x00a28984u)));
  }
  L00530d9e: { // 0x530d9e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00530da0: { // 0x530da0: 0f85a2020000 JNZ 0x00531048
    if(integer::condition("JNZ",flags)) goto L00531048;
  }
  L00530da6: { // 0x530da6: 8b8618030000 MOV EAX,dword ptr [ESI + 0x318]
    s.ax = m.r32((s.si+0x00000318u));
  }
  L00530dac: { // 0x530dac: 8b8e14030000 MOV ECX,dword ptr [ESI + 0x314]
    s.cx = m.r32((s.si+0x00000314u));
  }
  L00530db2: { // 0x530db2: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00530db4: { // 0x530db4: b900010000 MOV ECX,0x100
    s.cx = 0x00000100u;
  }
  L00530db9: { // 0x530db9: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00530dba: { // 0x530dba: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L00530dbc: { // 0x530dbc: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00530dbe: { // 0x530dbe: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00530dc0: { // 0x530dc0: 83f902 CMP ECX,0x2
    (void)integer::sub(s.cx,0x00000002u,32,flags);
  }
  L00530dc3: { // 0x530dc3: 0f8c7f020000 JL 0x00531048
    if(integer::condition("JL",flags)) goto L00531048;
  }
  L00530dc9: { // 0x530dc9: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00530dcb: { // 0x530dcb: 6a0a PUSH 0xa
    f.push(m,0x0000000au);
  }
  L00530dcd: { // 0x530dcd: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00530dcf: { // 0x530dcf: e85cf9ffff CALL 0x00530730
    s.arithmetic_flags=flags; invoke(m,s,f,0x00530730u,5443028u,op); flags=s.arithmetic_flags;
  }
  L00530dd4: { // 0x530dd4: 8ad3 MOV DL,BL
    s.dx = with_al(s.dx, (s.bx & 0xffu));
  }
  L00530dd6: { // 0x530dd6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00530dd8: { // 0x530dd8: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00530dde: { // 0x530dde: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00530ddf: { // 0x530ddf: e80cf9ffff CALL 0x005306f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005306f0u,5443044u,op); flags=s.arithmetic_flags;
  }
  L00530de4: { // 0x530de4: e95f020000 JMP 0x00531048
    goto L00531048;
  }
  L00530de9: { // 0x530de9: a08489a200 MOV AL,[0x00a28984]
    s.ax = with_al(s.ax, m.r8((0x00a28984u)));
  }
  L00530dee: { // 0x530dee: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00530df0: { // 0x530df0: 0f8552020000 JNZ 0x00531048
    if(integer::condition("JNZ",flags)) goto L00531048;
  }
  L00530df6: { // 0x530df6: 8b8618030000 MOV EAX,dword ptr [ESI + 0x318]
    s.ax = m.r32((s.si+0x00000318u));
  }
  L00530dfc: { // 0x530dfc: 8b9614030000 MOV EDX,dword ptr [ESI + 0x314]
    s.dx = m.r32((s.si+0x00000314u));
  }
  L00530e02: { // 0x530e02: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00530e04: { // 0x530e04: b900010000 MOV ECX,0x100
    s.cx = 0x00000100u;
  }
  L00530e09: { // 0x530e09: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00530e0a: { // 0x530e0a: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L00530e0c: { // 0x530e0c: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00530e0e: { // 0x530e0e: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00530e10: { // 0x530e10: 83f903 CMP ECX,0x3
    (void)integer::sub(s.cx,0x00000003u,32,flags);
  }
  L00530e13: { // 0x530e13: 0f8c2f020000 JL 0x00531048
    if(integer::condition("JL",flags)) goto L00531048;
  }
  L00530e19: { // 0x530e19: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00530e1b: { // 0x530e1b: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00530e1d: { // 0x530e1d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00530e1f: { // 0x530e1f: e80cf9ffff CALL 0x00530730
    s.arithmetic_flags=flags; invoke(m,s,f,0x00530730u,5443108u,op); flags=s.arithmetic_flags;
  }
  L00530e24: { // 0x530e24: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00530e26: { // 0x530e26: e8b5fdffff CALL 0x00530be0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00530be0u,5443115u,op); flags=s.arithmetic_flags;
  }
  L00530e2b: { // 0x530e2b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00530e2d: { // 0x530e2d: 0f85f6000000 JNZ 0x00530f29
    if(integer::condition("JNZ",flags)) goto L00530f29;
  }
  L00530e33: { // 0x530e33: e9e9000000 JMP 0x00530f21
    goto L00530f21;
  }
  L00530e38: { // 0x530e38: 05fefdffff ADD EAX,0xfffffdfe
    s.ax = integer::add(s.ax,0xfffffdfeu,32,flags);
  }
  L00530e3d: { // 0x530e3d: 83f807 CMP EAX,0x7
    (void)integer::sub(s.ax,0x00000007u,32,flags);
  }
  L00530e40: { // 0x530e40: 0f8727020000 JA 0x0053106d
    if(integer::condition("JA",flags)) goto L0053106d;
  }
  L00530e46: { // 0x530e46: ff248594105300 JMP dword ptr [EAX*0x4 + 0x531094]
    switch(m.r32(((s.ax * 0x00000004u)+0x00531094u))){
    case 0x00530cc0u: goto L00530cc0;
    case 0x00530cc3u: goto L00530cc3;
    case 0x00530cc7u: goto L00530cc7;
    case 0x00530cc8u: goto L00530cc8;
    case 0x00530cc9u: goto L00530cc9;
    case 0x00530ccau: goto L00530cca;
    case 0x00530cccu: goto L00530ccc;
    case 0x00530cd0u: goto L00530cd0;
    case 0x00530cd2u: goto L00530cd2;
    case 0x00530cd3u: goto L00530cd3;
    case 0x00530cd6u: goto L00530cd6;
    case 0x00530cdau: goto L00530cda;
    case 0x00530cdeu: goto L00530cde;
    case 0x00530ce4u: goto L00530ce4;
    case 0x00530ce5u: goto L00530ce5;
    case 0x00530ce6u: goto L00530ce6;
    case 0x00530ceau: goto L00530cea;
    case 0x00530cf0u: goto L00530cf0;
    case 0x00530cf6u: goto L00530cf6;
    case 0x00530cfau: goto L00530cfa;
    case 0x00530cfeu: goto L00530cfe;
    case 0x00530d02u: goto L00530d02;
    case 0x00530d04u: goto L00530d04;
    case 0x00530d08u: goto L00530d08;
    case 0x00530d0au: goto L00530d0a;
    case 0x00530d0cu: goto L00530d0c;
    case 0x00530d10u: goto L00530d10;
    case 0x00530d11u: goto L00530d11;
    case 0x00530d15u: goto L00530d15;
    case 0x00530d16u: goto L00530d16;
    case 0x00530d19u: goto L00530d19;
    case 0x00530d1du: goto L00530d1d;
    case 0x00530d21u: goto L00530d21;
    case 0x00530d25u: goto L00530d25;
    case 0x00530d29u: goto L00530d29;
    case 0x00530d2eu: goto L00530d2e;
    case 0x00530d34u: goto L00530d34;
    case 0x00530d39u: goto L00530d39;
    case 0x00530d3fu: goto L00530d3f;
    case 0x00530d44u: goto L00530d44;
    case 0x00530d47u: goto L00530d47;
    case 0x00530d4du: goto L00530d4d;
    case 0x00530d54u: goto L00530d54;
    case 0x00530d5au: goto L00530d5a;
    case 0x00530d60u: goto L00530d60;
    case 0x00530d68u: goto L00530d68;
    case 0x00530d6eu: goto L00530d6e;
    case 0x00530d70u: goto L00530d70;
    case 0x00530d71u: goto L00530d71;
    case 0x00530d73u: goto L00530d73;
    case 0x00530d78u: goto L00530d78;
    case 0x00530d7du: goto L00530d7d;
    case 0x00530d7fu: goto L00530d7f;
    case 0x00530d80u: goto L00530d80;
    case 0x00530d82u: goto L00530d82;
    case 0x00530d87u: goto L00530d87;
    case 0x00530d8cu: goto L00530d8c;
    case 0x00530d91u: goto L00530d91;
    case 0x00530d93u: goto L00530d93;
    case 0x00530d99u: goto L00530d99;
    case 0x00530d9eu: goto L00530d9e;
    case 0x00530da0u: goto L00530da0;
    case 0x00530da6u: goto L00530da6;
    case 0x00530dacu: goto L00530dac;
    case 0x00530db2u: goto L00530db2;
    case 0x00530db4u: goto L00530db4;
    case 0x00530db9u: goto L00530db9;
    case 0x00530dbau: goto L00530dba;
    case 0x00530dbcu: goto L00530dbc;
    case 0x00530dbeu: goto L00530dbe;
    case 0x00530dc0u: goto L00530dc0;
    case 0x00530dc3u: goto L00530dc3;
    case 0x00530dc9u: goto L00530dc9;
    case 0x00530dcbu: goto L00530dcb;
    case 0x00530dcdu: goto L00530dcd;
    case 0x00530dcfu: goto L00530dcf;
    case 0x00530dd4u: goto L00530dd4;
    case 0x00530dd6u: goto L00530dd6;
    case 0x00530dd8u: goto L00530dd8;
    case 0x00530ddeu: goto L00530dde;
    case 0x00530ddfu: goto L00530ddf;
    case 0x00530de4u: goto L00530de4;
    case 0x00530de9u: goto L00530de9;
    case 0x00530deeu: goto L00530dee;
    case 0x00530df0u: goto L00530df0;
    case 0x00530df6u: goto L00530df6;
    case 0x00530dfcu: goto L00530dfc;
    case 0x00530e02u: goto L00530e02;
    case 0x00530e04u: goto L00530e04;
    case 0x00530e09u: goto L00530e09;
    case 0x00530e0au: goto L00530e0a;
    case 0x00530e0cu: goto L00530e0c;
    case 0x00530e0eu: goto L00530e0e;
    case 0x00530e10u: goto L00530e10;
    case 0x00530e13u: goto L00530e13;
    case 0x00530e19u: goto L00530e19;
    case 0x00530e1bu: goto L00530e1b;
    case 0x00530e1du: goto L00530e1d;
    case 0x00530e1fu: goto L00530e1f;
    case 0x00530e24u: goto L00530e24;
    case 0x00530e26u: goto L00530e26;
    case 0x00530e2bu: goto L00530e2b;
    case 0x00530e2du: goto L00530e2d;
    case 0x00530e33u: goto L00530e33;
    case 0x00530e38u: goto L00530e38;
    case 0x00530e3du: goto L00530e3d;
    case 0x00530e40u: goto L00530e40;
    case 0x00530e46u: goto L00530e46;
    case 0x00530e4du: goto L00530e4d;
    case 0x00530e52u: goto L00530e52;
    case 0x00530e54u: goto L00530e54;
    case 0x00530e5au: goto L00530e5a;
    case 0x00530e60u: goto L00530e60;
    case 0x00530e66u: goto L00530e66;
    case 0x00530e68u: goto L00530e68;
    case 0x00530e69u: goto L00530e69;
    case 0x00530e6bu: goto L00530e6b;
    case 0x00530e6du: goto L00530e6d;
    case 0x00530e72u: goto L00530e72;
    case 0x00530e74u: goto L00530e74;
    case 0x00530e77u: goto L00530e77;
    case 0x00530e7du: goto L00530e7d;
    case 0x00530e7fu: goto L00530e7f;
    case 0x00530e81u: goto L00530e81;
    case 0x00530e86u: goto L00530e86;
    case 0x00530e88u: goto L00530e88;
    case 0x00530e8eu: goto L00530e8e;
    case 0x00530e94u: goto L00530e94;
    case 0x00530e9au: goto L00530e9a;
    case 0x00530e9cu: goto L00530e9c;
    case 0x00530ea1u: goto L00530ea1;
    case 0x00530ea2u: goto L00530ea2;
    case 0x00530ea4u: goto L00530ea4;
    case 0x00530ea6u: goto L00530ea6;
    case 0x00530ea8u: goto L00530ea8;
    case 0x00530eabu: goto L00530eab;
    case 0x00530eadu: goto L00530ead;
    case 0x00530eafu: goto L00530eaf;
    case 0x00530eb1u: goto L00530eb1;
    case 0x00530eb3u: goto L00530eb3;
    case 0x00530eb8u: goto L00530eb8;
    case 0x00530ebau: goto L00530eba;
    case 0x00530ebfu: goto L00530ebf;
    case 0x00530ec1u: goto L00530ec1;
    case 0x00530ec3u: goto L00530ec3;
    case 0x00530ec4u: goto L00530ec4;
    case 0x00530ec6u: goto L00530ec6;
    case 0x00530ecbu: goto L00530ecb;
    case 0x00530eccu: goto L00530ecc;
    case 0x00530eceu: goto L00530ece;
    case 0x00530ed3u: goto L00530ed3;
    case 0x00530ed7u: goto L00530ed7;
    case 0x00530edbu: goto L00530edb;
    case 0x00530ee0u: goto L00530ee0;
    case 0x00530ee2u: goto L00530ee2;
    case 0x00530ee8u: goto L00530ee8;
    case 0x00530eeeu: goto L00530eee;
    case 0x00530ef4u: goto L00530ef4;
    case 0x00530ef6u: goto L00530ef6;
    case 0x00530ef7u: goto L00530ef7;
    case 0x00530ef9u: goto L00530ef9;
    case 0x00530efbu: goto L00530efb;
    case 0x00530f00u: goto L00530f00;
    case 0x00530f02u: goto L00530f02;
    case 0x00530f05u: goto L00530f05;
    case 0x00530f0bu: goto L00530f0b;
    case 0x00530f0du: goto L00530f0d;
    case 0x00530f0fu: goto L00530f0f;
    case 0x00530f11u: goto L00530f11;
    case 0x00530f16u: goto L00530f16;
    case 0x00530f18u: goto L00530f18;
    case 0x00530f1du: goto L00530f1d;
    case 0x00530f1fu: goto L00530f1f;
    case 0x00530f21u: goto L00530f21;
    case 0x00530f22u: goto L00530f22;
    case 0x00530f24u: goto L00530f24;
    case 0x00530f29u: goto L00530f29;
    case 0x00530f2au: goto L00530f2a;
    case 0x00530f2cu: goto L00530f2c;
    case 0x00530f31u: goto L00530f31;
    case 0x00530f36u: goto L00530f36;
    case 0x00530f3bu: goto L00530f3b;
    case 0x00530f3du: goto L00530f3d;
    case 0x00530f43u: goto L00530f43;
    case 0x00530f49u: goto L00530f49;
    case 0x00530f4fu: goto L00530f4f;
    case 0x00530f51u: goto L00530f51;
    case 0x00530f56u: goto L00530f56;
    case 0x00530f57u: goto L00530f57;
    case 0x00530f59u: goto L00530f59;
    case 0x00530f5bu: goto L00530f5b;
    case 0x00530f5du: goto L00530f5d;
    case 0x00530f60u: goto L00530f60;
    case 0x00530f66u: goto L00530f66;
    case 0x00530f68u: goto L00530f68;
    case 0x00530f6au: goto L00530f6a;
    case 0x00530f6cu: goto L00530f6c;
    case 0x00530f71u: goto L00530f71;
    case 0x00530f72u: goto L00530f72;
    case 0x00530f74u: goto L00530f74;
    case 0x00530f79u: goto L00530f79;
    case 0x00530f7au: goto L00530f7a;
    case 0x00530f7cu: goto L00530f7c;
    case 0x00530f81u: goto L00530f81;
    case 0x00530f86u: goto L00530f86;
    case 0x00530f8bu: goto L00530f8b;
    case 0x00530f8du: goto L00530f8d;
    case 0x00530f93u: goto L00530f93;
    case 0x00530f99u: goto L00530f99;
    case 0x00530f9fu: goto L00530f9f;
    case 0x00530fa1u: goto L00530fa1;
    case 0x00530fa6u: goto L00530fa6;
    case 0x00530fa7u: goto L00530fa7;
    case 0x00530fa9u: goto L00530fa9;
    case 0x00530fabu: goto L00530fab;
    case 0x00530fadu: goto L00530fad;
    case 0x00530fb0u: goto L00530fb0;
    case 0x00530fb2u: goto L00530fb2;
    case 0x00530fb4u: goto L00530fb4;
    case 0x00530fb6u: goto L00530fb6;
    case 0x00530fb8u: goto L00530fb8;
    case 0x00530fbdu: goto L00530fbd;
    case 0x00530fbeu: goto L00530fbe;
    case 0x00530fc0u: goto L00530fc0;
    case 0x00530fc5u: goto L00530fc5;
    case 0x00530fc6u: goto L00530fc6;
    case 0x00530fc8u: goto L00530fc8;
    case 0x00530fcdu: goto L00530fcd;
    case 0x00530fd1u: goto L00530fd1;
    case 0x00530fd5u: goto L00530fd5;
    case 0x00530fdau: goto L00530fda;
    case 0x00530fdcu: goto L00530fdc;
    case 0x00530fdeu: goto L00530fde;
    case 0x00530fe4u: goto L00530fe4;
    case 0x00530feau: goto L00530fea;
    case 0x00530fecu: goto L00530fec;
    case 0x00530fedu: goto L00530fed;
    case 0x00530fefu: goto L00530fef;
    case 0x00530ff1u: goto L00530ff1;
    case 0x00530ff6u: goto L00530ff6;
    case 0x00530ff8u: goto L00530ff8;
    case 0x00530ffbu: goto L00530ffb;
    case 0x00530ffdu: goto L00530ffd;
    case 0x00530fffu: goto L00530fff;
    case 0x00531001u: goto L00531001;
    case 0x00531003u: goto L00531003;
    case 0x00531008u: goto L00531008;
    case 0x00531009u: goto L00531009;
    case 0x0053100bu: goto L0053100b;
    case 0x00531010u: goto L00531010;
    case 0x00531011u: goto L00531011;
    case 0x00531013u: goto L00531013;
    case 0x00531018u: goto L00531018;
    case 0x0053101au: goto L0053101a;
    case 0x0053101cu: goto L0053101c;
    case 0x0053101du: goto L0053101d;
    case 0x0053101eu: goto L0053101e;
    case 0x00531020u: goto L00531020;
    case 0x00531022u: goto L00531022;
    case 0x00531023u: goto L00531023;
    case 0x00531024u: goto L00531024;
    case 0x00531026u: goto L00531026;
    case 0x00531028u: goto L00531028;
    case 0x00531029u: goto L00531029;
    case 0x0053102au: goto L0053102a;
    case 0x0053102cu: goto L0053102c;
    case 0x0053102eu: goto L0053102e;
    case 0x00531033u: goto L00531033;
    case 0x00531037u: goto L00531037;
    case 0x0053103bu: goto L0053103b;
    case 0x0053103du: goto L0053103d;
    case 0x0053103eu: goto L0053103e;
    case 0x0053103fu: goto L0053103f;
    case 0x00531041u: goto L00531041;
    case 0x00531043u: goto L00531043;
    case 0x00531048u: goto L00531048;
    case 0x0053104cu: goto L0053104c;
    case 0x00531050u: goto L00531050;
    case 0x00531054u: goto L00531054;
    case 0x00531055u: goto L00531055;
    case 0x00531056u: goto L00531056;
    case 0x00531057u: goto L00531057;
    case 0x00531058u: goto L00531058;
    case 0x0053105eu: goto L0053105e;
    case 0x0053105fu: goto L0053105f;
    case 0x00531060u: goto L00531060;
    case 0x00531061u: goto L00531061;
    case 0x00531066u: goto L00531066;
    case 0x00531067u: goto L00531067;
    case 0x0053106au: goto L0053106a;
    case 0x0053106du: goto L0053106d;
    case 0x0053106eu: goto L0053106e;
    case 0x0053106fu: goto L0053106f;
    case 0x00531070u: goto L00531070;
    case 0x00531072u: goto L00531072;
    case 0x00531073u: goto L00531073;
    case 0x00531076u: goto L00531076;
    default:throw std::domain_error("recovery107 unsupported switch destination");}
  }
  L00530e4d: { // 0x530e4d: a08489a200 MOV AL,[0x00a28984]
    s.ax = with_al(s.ax, m.r8((0x00a28984u)));
  }
  L00530e52: { // 0x530e52: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00530e54: { // 0x530e54: 0f85ee010000 JNZ 0x00531048
    if(integer::condition("JNZ",flags)) goto L00531048;
  }
  L00530e5a: { // 0x530e5a: 8b8618030000 MOV EAX,dword ptr [ESI + 0x318]
    s.ax = m.r32((s.si+0x00000318u));
  }
  L00530e60: { // 0x530e60: 8b9614030000 MOV EDX,dword ptr [ESI + 0x314]
    s.dx = m.r32((s.si+0x00000314u));
  }
  L00530e66: { // 0x530e66: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00530e68: { // 0x530e68: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00530e69: { // 0x530e69: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L00530e6b: { // 0x530e6b: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00530e6d: { // 0x530e6d: ba00010000 MOV EDX,0x100
    s.dx = 0x00000100u;
  }
  L00530e72: { // 0x530e72: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L00530e74: { // 0x530e74: 83fa03 CMP EDX,0x3
    (void)integer::sub(s.dx,0x00000003u,32,flags);
  }
  L00530e77: { // 0x530e77: 0f8ccb010000 JL 0x00531048
    if(integer::condition("JL",flags)) goto L00531048;
  }
  L00530e7d: { // 0x530e7d: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00530e7f: { // 0x530e7f: eb9a JMP 0x00530e1b
    goto L00530e1b;
  }
  L00530e81: { // 0x530e81: a08489a200 MOV AL,[0x00a28984]
    s.ax = with_al(s.ax, m.r8((0x00a28984u)));
  }
  L00530e86: { // 0x530e86: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00530e88: { // 0x530e88: 0f85ba010000 JNZ 0x00531048
    if(integer::condition("JNZ",flags)) goto L00531048;
  }
  L00530e8e: { // 0x530e8e: 8b8618030000 MOV EAX,dword ptr [ESI + 0x318]
    s.ax = m.r32((s.si+0x00000318u));
  }
  L00530e94: { // 0x530e94: 8b9614030000 MOV EDX,dword ptr [ESI + 0x314]
    s.dx = m.r32((s.si+0x00000314u));
  }
  L00530e9a: { // 0x530e9a: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00530e9c: { // 0x530e9c: b900010000 MOV ECX,0x100
    s.cx = 0x00000100u;
  }
  L00530ea1: { // 0x530ea1: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00530ea2: { // 0x530ea2: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L00530ea4: { // 0x530ea4: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00530ea6: { // 0x530ea6: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00530ea8: { // 0x530ea8: 83f903 CMP ECX,0x3
    (void)integer::sub(s.cx,0x00000003u,32,flags);
  }
  L00530eab: { // 0x530eab: 7c2e JL 0x00530edb
    if(integer::condition("JL",flags)) goto L00530edb;
  }
  L00530ead: { // 0x530ead: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00530eaf: { // 0x530eaf: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00530eb1: { // 0x530eb1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00530eb3: { // 0x530eb3: e878f8ffff CALL 0x00530730
    s.arithmetic_flags=flags; invoke(m,s,f,0x00530730u,5443256u,op); flags=s.arithmetic_flags;
  }
  L00530eb8: { // 0x530eb8: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00530eba: { // 0x530eba: e821fdffff CALL 0x00530be0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00530be0u,5443263u,op); flags=s.arithmetic_flags;
  }
  L00530ebf: { // 0x530ebf: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00530ec1: { // 0x530ec1: 7508 JNZ 0x00530ecb
    if(integer::condition("JNZ",flags)) goto L00530ecb;
  }
  L00530ec3: { // 0x530ec3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00530ec4: { // 0x530ec4: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00530ec6: { // 0x530ec6: e8d5fcffff CALL 0x00530ba0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00530ba0u,5443275u,op); flags=s.arithmetic_flags;
  }
  L00530ecb: { // 0x530ecb: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00530ecc: { // 0x530ecc: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00530ece: { // 0x530ece: e81df8ffff CALL 0x005306f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005306f0u,5443283u,op); flags=s.arithmetic_flags;
  }
  L00530ed3: { // 0x530ed3: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L00530ed7: { // 0x530ed7: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L00530edb: { // 0x530edb: a08489a200 MOV AL,[0x00a28984]
    s.ax = with_al(s.ax, m.r8((0x00a28984u)));
  }
  L00530ee0: { // 0x530ee0: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00530ee2: { // 0x530ee2: 0f8560010000 JNZ 0x00531048
    if(integer::condition("JNZ",flags)) goto L00531048;
  }
  L00530ee8: { // 0x530ee8: 8b8618030000 MOV EAX,dword ptr [ESI + 0x318]
    s.ax = m.r32((s.si+0x00000318u));
  }
  L00530eee: { // 0x530eee: 8b9614030000 MOV EDX,dword ptr [ESI + 0x314]
    s.dx = m.r32((s.si+0x00000314u));
  }
  L00530ef4: { // 0x530ef4: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00530ef6: { // 0x530ef6: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00530ef7: { // 0x530ef7: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L00530ef9: { // 0x530ef9: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00530efb: { // 0x530efb: ba00010000 MOV EDX,0x100
    s.dx = 0x00000100u;
  }
  L00530f00: { // 0x530f00: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L00530f02: { // 0x530f02: 83fa03 CMP EDX,0x3
    (void)integer::sub(s.dx,0x00000003u,32,flags);
  }
  L00530f05: { // 0x530f05: 0f8c3d010000 JL 0x00531048
    if(integer::condition("JL",flags)) goto L00531048;
  }
  L00530f0b: { // 0x530f0b: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00530f0d: { // 0x530f0d: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00530f0f: { // 0x530f0f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00530f11: { // 0x530f11: e81af8ffff CALL 0x00530730
    s.arithmetic_flags=flags; invoke(m,s,f,0x00530730u,5443350u,op); flags=s.arithmetic_flags;
  }
  L00530f16: { // 0x530f16: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00530f18: { // 0x530f18: e8c3fcffff CALL 0x00530be0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00530be0u,5443357u,op); flags=s.arithmetic_flags;
  }
  L00530f1d: { // 0x530f1d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00530f1f: { // 0x530f1f: 7508 JNZ 0x00530f29
    if(integer::condition("JNZ",flags)) goto L00530f29;
  }
  L00530f21: { // 0x530f21: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00530f22: { // 0x530f22: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00530f24: { // 0x530f24: e877fcffff CALL 0x00530ba0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00530ba0u,5443369u,op); flags=s.arithmetic_flags;
  }
  L00530f29: { // 0x530f29: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00530f2a: { // 0x530f2a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00530f2c: { // 0x530f2c: e8bff7ffff CALL 0x005306f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005306f0u,5443377u,op); flags=s.arithmetic_flags;
  }
  L00530f31: { // 0x530f31: e912010000 JMP 0x00531048
    goto L00531048;
  }
  L00530f36: { // 0x530f36: a08489a200 MOV AL,[0x00a28984]
    s.ax = with_al(s.ax, m.r8((0x00a28984u)));
  }
  L00530f3b: { // 0x530f3b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00530f3d: { // 0x530f3d: 0f8505010000 JNZ 0x00531048
    if(integer::condition("JNZ",flags)) goto L00531048;
  }
  L00530f43: { // 0x530f43: 8b8618030000 MOV EAX,dword ptr [ESI + 0x318]
    s.ax = m.r32((s.si+0x00000318u));
  }
  L00530f49: { // 0x530f49: 8b9614030000 MOV EDX,dword ptr [ESI + 0x314]
    s.dx = m.r32((s.si+0x00000314u));
  }
  L00530f4f: { // 0x530f4f: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00530f51: { // 0x530f51: b900010000 MOV ECX,0x100
    s.cx = 0x00000100u;
  }
  L00530f56: { // 0x530f56: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00530f57: { // 0x530f57: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L00530f59: { // 0x530f59: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00530f5b: { // 0x530f5b: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00530f5d: { // 0x530f5d: 83f903 CMP ECX,0x3
    (void)integer::sub(s.cx,0x00000003u,32,flags);
  }
  L00530f60: { // 0x530f60: 0f8ce2000000 JL 0x00531048
    if(integer::condition("JL",flags)) goto L00531048;
  }
  L00530f66: { // 0x530f66: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00530f68: { // 0x530f68: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  L00530f6a: { // 0x530f6a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00530f6c: { // 0x530f6c: e8bff7ffff CALL 0x00530730
    s.arithmetic_flags=flags; invoke(m,s,f,0x00530730u,5443441u,op); flags=s.arithmetic_flags;
  }
  L00530f71: { // 0x530f71: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00530f72: { // 0x530f72: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00530f74: { // 0x530f74: e877f7ffff CALL 0x005306f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005306f0u,5443449u,op); flags=s.arithmetic_flags;
  }
  L00530f79: { // 0x530f79: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00530f7a: { // 0x530f7a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00530f7c: { // 0x530f7c: e86ff7ffff CALL 0x005306f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005306f0u,5443457u,op); flags=s.arithmetic_flags;
  }
  L00530f81: { // 0x530f81: e9c2000000 JMP 0x00531048
    goto L00531048;
  }
  L00530f86: { // 0x530f86: a08489a200 MOV AL,[0x00a28984]
    s.ax = with_al(s.ax, m.r8((0x00a28984u)));
  }
  L00530f8b: { // 0x530f8b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00530f8d: { // 0x530f8d: 0f85b5000000 JNZ 0x00531048
    if(integer::condition("JNZ",flags)) goto L00531048;
  }
  L00530f93: { // 0x530f93: 8b8618030000 MOV EAX,dword ptr [ESI + 0x318]
    s.ax = m.r32((s.si+0x00000318u));
  }
  L00530f99: { // 0x530f99: 8b9614030000 MOV EDX,dword ptr [ESI + 0x314]
    s.dx = m.r32((s.si+0x00000314u));
  }
  L00530f9f: { // 0x530f9f: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00530fa1: { // 0x530fa1: b900010000 MOV ECX,0x100
    s.cx = 0x00000100u;
  }
  L00530fa6: { // 0x530fa6: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00530fa7: { // 0x530fa7: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L00530fa9: { // 0x530fa9: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00530fab: { // 0x530fab: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00530fad: { // 0x530fad: 83f903 CMP ECX,0x3
    (void)integer::sub(s.cx,0x00000003u,32,flags);
  }
  L00530fb0: { // 0x530fb0: 7c23 JL 0x00530fd5
    if(integer::condition("JL",flags)) goto L00530fd5;
  }
  L00530fb2: { // 0x530fb2: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00530fb4: { // 0x530fb4: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  L00530fb6: { // 0x530fb6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00530fb8: { // 0x530fb8: e873f7ffff CALL 0x00530730
    s.arithmetic_flags=flags; invoke(m,s,f,0x00530730u,5443517u,op); flags=s.arithmetic_flags;
  }
  L00530fbd: { // 0x530fbd: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00530fbe: { // 0x530fbe: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00530fc0: { // 0x530fc0: e82bf7ffff CALL 0x005306f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005306f0u,5443525u,op); flags=s.arithmetic_flags;
  }
  L00530fc5: { // 0x530fc5: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00530fc6: { // 0x530fc6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00530fc8: { // 0x530fc8: e823f7ffff CALL 0x005306f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005306f0u,5443533u,op); flags=s.arithmetic_flags;
  }
  L00530fcd: { // 0x530fcd: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L00530fd1: { // 0x530fd1: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L00530fd5: { // 0x530fd5: a08489a200 MOV AL,[0x00a28984]
    s.ax = with_al(s.ax, m.r8((0x00a28984u)));
  }
  L00530fda: { // 0x530fda: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00530fdc: { // 0x530fdc: 756a JNZ 0x00531048
    if(integer::condition("JNZ",flags)) goto L00531048;
  }
  L00530fde: { // 0x530fde: 8b8618030000 MOV EAX,dword ptr [ESI + 0x318]
    s.ax = m.r32((s.si+0x00000318u));
  }
  L00530fe4: { // 0x530fe4: 8b9614030000 MOV EDX,dword ptr [ESI + 0x314]
    s.dx = m.r32((s.si+0x00000314u));
  }
  L00530fea: { // 0x530fea: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00530fec: { // 0x530fec: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00530fed: { // 0x530fed: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L00530fef: { // 0x530fef: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00530ff1: { // 0x530ff1: ba00010000 MOV EDX,0x100
    s.dx = 0x00000100u;
  }
  L00530ff6: { // 0x530ff6: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L00530ff8: { // 0x530ff8: 83fa03 CMP EDX,0x3
    (void)integer::sub(s.dx,0x00000003u,32,flags);
  }
  L00530ffb: { // 0x530ffb: 7c4b JL 0x00531048
    if(integer::condition("JL",flags)) goto L00531048;
  }
  L00530ffd: { // 0x530ffd: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00530fff: { // 0x530fff: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  L00531001: { // 0x531001: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00531003: { // 0x531003: e828f7ffff CALL 0x00530730
    s.arithmetic_flags=flags; invoke(m,s,f,0x00530730u,5443592u,op); flags=s.arithmetic_flags;
  }
  L00531008: { // 0x531008: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00531009: { // 0x531009: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0053100b: { // 0x53100b: e8e0f6ffff CALL 0x005306f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005306f0u,5443600u,op); flags=s.arithmetic_flags;
  }
  L00531010: { // 0x531010: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00531011: { // 0x531011: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00531013: { // 0x531013: e8d8f6ffff CALL 0x005306f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005306f0u,5443608u,op); flags=s.arithmetic_flags;
  }
  L00531018: { // 0x531018: eb2e JMP 0x00531048
    goto L00531048;
  }
  L0053101a: { // 0x53101a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0053101c: { // 0x53101c: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0053101d: { // 0x53101d: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0053101e: { // 0x53101e: eb1f JMP 0x0053103f
    goto L0053103f;
  }
  L00531020: { // 0x531020: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00531022: { // 0x531022: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00531023: { // 0x531023: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00531024: { // 0x531024: eb19 JMP 0x0053103f
    goto L0053103f;
  }
  L00531026: { // 0x531026: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00531028: { // 0x531028: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00531029: { // 0x531029: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0053102a: { // 0x53102a: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  L0053102c: { // 0x53102c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0053102e: { // 0x53102e: e8edf7ffff CALL 0x00530820
    s.arithmetic_flags=flags; invoke(m,s,f,0x00530820u,5443635u,op); flags=s.arithmetic_flags;
  }
  L00531033: { // 0x531033: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00531037: { // 0x531037: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0053103b: { // 0x53103b: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0053103d: { // 0x53103d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0053103e: { // 0x53103e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0053103f: { // 0x53103f: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  L00531041: { // 0x531041: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00531043: { // 0x531043: e8d8f7ffff CALL 0x00530820
    s.arithmetic_flags=flags; invoke(m,s,f,0x00530820u,5443656u,op); flags=s.arithmetic_flags;
  }
  L00531048: { // 0x531048: 8b542430 MOV EDX,dword ptr [ESP + 0x30]
    s.dx = m.r32((f.sp+0x00000030u));
  }
  L0053104c: { // 0x53104c: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L00531050: { // 0x531050: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L00531054: { // 0x531054: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00531055: { // 0x531055: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00531056: { // 0x531056: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00531057: { // 0x531057: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00531058: { // 0x531058: ff1588537800 CALL dword ptr [0x00785388]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((0x00785388u)),5443678u,op); flags=s.arithmetic_flags;
  }
  L0053105e: { // 0x53105e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0053105f: { // 0x53105f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00531060: { // 0x531060: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00531061: { // 0x531061: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L00531066: { // 0x531066: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00531067: { // 0x531067: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0053106a: { // 0x53106a: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L0053106d: { // 0x53106d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0053106e: { // 0x53106e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0053106f: { // 0x53106f: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00531070: { // 0x531070: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00531072: { // 0x531072: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00531073: { // 0x531073: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00531076: { // 0x531076: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
}

void f_00130730(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00530730: { // 0x530730: a08489a200 MOV AL,[0x00a28984]
    s.ax = with_al(s.ax, m.r8((0x00a28984u)));
  }
  L00530735: { // 0x530735: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00530736: { // 0x530736: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00530737: { // 0x530737: 8b74240c MOV ESI,dword ptr [ESP + 0xc]
    s.si = m.r32((f.sp+0x0000000cu));
  }
  L0053073b: { // 0x53073b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0053073c: { // 0x53073c: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0053073e: { // 0x53073e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00530740: { // 0x530740: 740e JZ 0x00530750
    if(integer::condition("JZ",flags)) goto L00530750;
  }
  L00530742: { // 0x530742: 6683fe1b CMP si,0x1b
    (void)integer::sub((s.si & 0xffffu),0x0000001bu,16,flags);
  }
  L00530746: { // 0x530746: 7408 JZ 0x00530750
    if(integer::condition("JZ",flags)) goto L00530750;
  }
  L00530748: { // 0x530748: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00530749: { // 0x530749: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0053074a: { // 0x53074a: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0053074c: { // 0x53074c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0053074d: { // 0x53074d: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L00530750: { // 0x530750: 8a5c2414 MOV BL,byte ptr [ESP + 0x14]
    s.bx = with_al(s.bx, m.r8((f.sp+0x00000014u)));
  }
  L00530754: { // 0x530754: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00530756: { // 0x530756: 8ad3 MOV DL,BL
    s.dx = with_al(s.dx, (s.bx & 0xffu));
  }
  L00530758: { // 0x530758: 81e1ffff0000 AND ECX,0xffff
    s.cx = integer::logical((s.cx)&(0x0000ffffu),32,flags);
  }
  L0053075e: { // 0x53075e: e87d21ffff CALL 0x005228e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005228e0u,5441379u,op); flags=s.arithmetic_flags;
  }
  L00530763: { // 0x530763: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00530765: { // 0x530765: 25ff000000 AND EAX,0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  L0053076a: { // 0x53076a: 663d0100 CMP AX,0x1
    (void)integer::sub((s.ax & 0xffffu),0x00000001u,16,flags);
  }
  L0053076e: { // 0x53076e: 745f JZ 0x005307cf
    if(integer::condition("JZ",flags)) goto L005307cf;
  }
  L00530770: { // 0x530770: 663d0400 CMP AX,0x4
    (void)integer::sub((s.ax & 0xffffu),0x00000004u,16,flags);
  }
  L00530774: { // 0x530774: 7459 JZ 0x005307cf
    if(integer::condition("JZ",flags)) goto L005307cf;
  }
  L00530776: { // 0x530776: 663d0200 CMP AX,0x2
    (void)integer::sub((s.ax & 0xffffu),0x00000002u,16,flags);
  }
  L0053077a: { // 0x53077a: 7453 JZ 0x005307cf
    if(integer::condition("JZ",flags)) goto L005307cf;
  }
  L0053077c: { // 0x53077c: 663d0a00 CMP AX,0xa
    (void)integer::sub((s.ax & 0xffffu),0x0000000au,16,flags);
  }
  L00530780: { // 0x530780: 744d JZ 0x005307cf
    if(integer::condition("JZ",flags)) goto L005307cf;
  }
  L00530782: { // 0x530782: b910000000 MOV ECX,0x10
    s.cx = 0x00000010u;
  }
  L00530787: { // 0x530787: e88421ffff CALL 0x00522910
    s.arithmetic_flags=flags; invoke(m,s,f,0x00522910u,5441420u,op); flags=s.arithmetic_flags;
  }
  L0053078c: { // 0x53078c: f6c480 TEST AH,0x80
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000080u),8,flags);
  }
  L0053078f: { // 0x53078f: 7406 JZ 0x00530797
    if(integer::condition("JZ",flags)) goto L00530797;
  }
  L00530791: { // 0x530791: 81ce00010000 OR ESI,0x100
    s.si = integer::logical((s.si)|(0x00000100u),32,flags);
  }
  L00530797: { // 0x530797: b911000000 MOV ECX,0x11
    s.cx = 0x00000011u;
  }
  L0053079c: { // 0x53079c: e86f21ffff CALL 0x00522910
    s.arithmetic_flags=flags; invoke(m,s,f,0x00522910u,5441441u,op); flags=s.arithmetic_flags;
  }
  L005307a1: { // 0x5307a1: f6c480 TEST AH,0x80
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000080u),8,flags);
  }
  L005307a4: { // 0x5307a4: 7406 JZ 0x005307ac
    if(integer::condition("JZ",flags)) goto L005307ac;
  }
  L005307a6: { // 0x5307a6: 81ce00020000 OR ESI,0x200
    s.si = integer::logical((s.si)|(0x00000200u),32,flags);
  }
  L005307ac: { // 0x5307ac: b912000000 MOV ECX,0x12
    s.cx = 0x00000012u;
  }
  L005307b1: { // 0x5307b1: e85a21ffff CALL 0x00522910
    s.arithmetic_flags=flags; invoke(m,s,f,0x00522910u,5441462u,op); flags=s.arithmetic_flags;
  }
  L005307b6: { // 0x5307b6: f6c480 TEST AH,0x80
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000080u),8,flags);
  }
  L005307b9: { // 0x5307b9: 7414 JZ 0x005307cf
    if(integer::condition("JZ",flags)) goto L005307cf;
  }
  L005307bb: { // 0x5307bb: 6683fe09 CMP si,0x9
    (void)integer::sub((s.si & 0xffffu),0x00000009u,16,flags);
  }
  L005307bf: { // 0x5307bf: 7508 JNZ 0x005307c9
    if(integer::condition("JNZ",flags)) goto L005307c9;
  }
  L005307c1: { // 0x5307c1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005307c2: { // 0x5307c2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005307c3: { // 0x5307c3: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L005307c5: { // 0x5307c5: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005307c6: { // 0x5307c6: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L005307c9: { // 0x5307c9: 81ce00040000 OR ESI,0x400
    s.si = integer::logical((s.si)|(0x00000400u),32,flags);
  }
  L005307cf: { // 0x5307cf: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L005307d1: { // 0x5307d1: 7406 JZ 0x005307d9
    if(integer::condition("JZ",flags)) goto L005307d9;
  }
  L005307d3: { // 0x5307d3: 81ce00080000 OR ESI,0x800
    s.si = integer::logical((s.si)|(0x00000800u),32,flags);
  }
  L005307d9: { // 0x5307d9: 8b8f18030000 MOV ECX,dword ptr [EDI + 0x318]
    s.cx = m.r32((s.di+0x00000318u));
  }
  L005307df: { // 0x5307df: 8d4101 LEA EAX,[ECX + 0x1]
    s.ax = (s.cx+0x00000001u);
  }
  L005307e2: { // 0x5307e2: 25ff000080 AND EAX,0x800000ff
    s.ax = integer::logical((s.ax)&(0x800000ffu),32,flags);
  }
  L005307e7: { // 0x5307e7: 7907 JNS 0x005307f0
    if(integer::condition("JNS",flags)) goto L005307f0;
  }
  L005307e9: { // 0x5307e9: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L005307ea: { // 0x5307ea: 0d00ffffff OR EAX,0xffffff00
    s.ax = integer::logical((s.ax)|(0xffffff00u),32,flags);
  }
  L005307ef: { // 0x5307ef: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L005307f0: { // 0x5307f0: 3b8714030000 CMP EAX,dword ptr [EDI + 0x314]
    (void)integer::sub(s.ax,m.r32((s.di+0x00000314u)),32,flags);
  }
  L005307f6: { // 0x5307f6: 7416 JZ 0x0053080e
    if(integer::condition("JZ",flags)) goto L0053080e;
  }
  L005307f8: { // 0x5307f8: 6689b44f14010000 MOV word ptr [EDI + ECX*0x2 + 0x114],si
    m.w16((s.di+(s.cx * 0x00000002u)+0x00000114u), (s.si & 0xffffu));
  }
  L00530800: { // 0x530800: 898718030000 MOV dword ptr [EDI + 0x318],EAX
    m.w32((s.di+0x00000318u), s.ax);
  }
  L00530806: { // 0x530806: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00530807: { // 0x530807: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00530808: { // 0x530808: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0053080a: { // 0x53080a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0053080b: { // 0x53080b: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0053080e: { // 0x53080e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0053080f: { // 0x53080f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00530810: { // 0x530810: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00530812: { // 0x530812: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00530813: { // 0x530813: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}

void f_001228e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005228e0: { // 0x5228e0: a1ec9ea300 MOV EAX,[0x00a39eec]
    s.ax = m.r32((0x00a39eecu));
  }
  L005228e5: { // 0x5228e5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005228e7: { // 0x5228e7: 741e JZ 0x00522907
    if(integer::condition("JZ",flags)) goto L00522907;
  }
  L005228e9: { // 0x5228e9: f6da NEG DL
    s.dx = with_al(s.dx, integer::sub(0u,(s.dx & 0xffu),8,flags));
  }
  L005228eb: { // 0x5228eb: 1bd2 SBB EDX,EDX
    s.dx = integer::sub(s.dx,s.dx,32,flags,flags&integer::CF);
  }
  L005228ed: { // 0x5228ed: 81e200800000 AND EDX,0x8000
    s.dx = integer::logical((s.dx)&(0x00008000u),32,flags);
  }
  L005228f3: { // 0x5228f3: 81c20080ffff ADD EDX,0xffff8000
    s.dx = integer::add(s.dx,0xffff8000u,32,flags);
  }
  L005228f9: { // 0x5228f9: 81e1ff000000 AND ECX,0xff
    s.cx = integer::logical((s.cx)&(0x000000ffu),32,flags);
  }
  L005228ff: { // 0x5228ff: 6689144d109ca300 MOV word ptr [ECX*0x2 + 0xa39c10],DX
    m.w16(((s.cx * 0x00000002u)+0x00a39c10u), (s.dx & 0xffffu));
  }
  L00522907: { // 0x522907: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

inline void invoke(Memory&m,State&s,Frame&f,unsigned target,unsigned continuation,const Operations&op){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 if(op.client_to_screen_target&&target==op.client_to_screen_target){
  if(!op.window_context||!op.client_to_screen||target!=m.r32(0x7854ac))throw std::domain_error("actual ownedClientToScreen target/provider/IAT binding required");
  s.ax=op.client_to_screen(op.window_context,m,target,child.entry_sp,s.fp);finish(m,s,child,8);f.sp=child.sp;return;
 }
 if(op.def_window_proc_target&&target==op.def_window_proc_target){
  if(!op.window_context||!op.def_window_proc||target!=m.r32(0x785388))throw std::domain_error("actual ownedDefWindowProcA target/provider/IAT binding required");
  s.ax=op.def_window_proc(op.window_context,m,target,child.entry_sp,s.fp);finish(m,s,child,16);f.sp=child.sp;return;
 }
 switch(target){
case 0x530cc0u:f_00130cc0(m,s,child,op);break;
case 0x530730u:f_00130730(m,s,child,op);break;
case 0x5228e0u:f_001228e0(m,s,child,op);break;
default:throw std::domain_error("private_window unresolved authentic target");}f.sp=child.sp;
}

} // anonymous namespace
Result run(Memory&world,unsigned entry,unsigned char*storage,unsigned size,const NativeState&in,const fp::Image&incoming,const Operations&op){
 need(entry>=0x8000&&size>=0x8000+68&&std::uint64_t(entry)+68<=0x100000000ull&&std::uint64_t(reinterpret_cast<std::uintptr_t>(storage))+0x8000==entry,"actual owned32KB Source frame/caller extent");
 need(op.window_context&&op.client_to_screen&&op.def_window_proc&&op.client_to_screen_target&&op.def_window_proc_target&&op.client_to_screen_target!=op.def_window_proc_target,"boundactual ownedwindow provider and distinct frozen User32 identities");
 leaf::Memory local(storage,entry-0x8000,size);Memory m=world;m.add(local);std::array<unsigned,16>before{};for(unsigned k=0;k<16;++k)before[k]=m.r32(entry+4+4*k);
 // HWND ownership/class/procedure/lifecycle is a genuine provider precondition;
 // portable Source never invents a vptr or queries unrelated OS windows.
 need(before[0]!=0&&before[1]==0x100&&before[2]==1&&before[3]==0,"ownedHWND WM_KEYDOWN1/lParam0 finiteargs");
 const unsigned self=in.cx;need(self&&std::uint64_t(self)+0x31c<=0x100000000ull&&(std::uint64_t(self)+0x31c<=entry-0x8000||std::uint64_t(self)>=std::uint64_t(entry)+68),"public borrowednumeric ring extent/private disjoint");for(unsigned k=0;k<0x31c;++k)(void)m.r8(self+k);
 need(m.r32(self+0x314)==2&&m.r32(self+0x318)==0,"appendable ringhead2/tail0");need(m.r8(0xa28984)==0&&m.r32(0xa39eec)==1&&m.r32(0x821fa8)==0,"finite B95gates/authenticcoldoptionalnull");
 need(m.r32(0x7854ac)==op.client_to_screen_target&&m.r32(0x785388)==op.def_window_proc_target,"actual frozen User32 IAT identities");
 constexpr unsigned targets[]{0x530d54,0x530d7d,0x530d8c,0x53106d,0x530d54,0x530d7d};for(unsigned k=0;k<6;++k)need(m.r32(0x53107c+4*k)==targets[k],"authentic6cell computedjump table");
 constexpr unsigned short controls[]{0x037f,0x077f,0x0b7f,0x0f7f,0x027f,0x067f,0x0a7f,0x0e7f,0x007f,0x047f,0x087f,0x0c7f};bool cw=false;for(auto v:controls)if(incoming.word(0)==v)cw=true;need(cw&&incoming.word(8)==0xffff&&(incoming.word(4)&~0x3800u)==0&&!(in.flags&0x400),"finite12CW/all8TOP emptytags/DFclear");
 State state{};state.ax=in.ax;state.cx=in.cx;state.dx=in.dx;state.bx=in.bx;state.bp=in.bp;state.si=in.si;state.di=in.di;state.arithmetic_flags=in.flags;state.fp.image=incoming;Frame frame{entry,entry,m.r32(entry)};
 f_00130cc0(m,state,frame,op);
 need(frame.sp==entry+20&&state.ax==1&&state.bx==in.bx&&state.bp==in.bp&&state.si==in.si&&state.di==in.di&&!(state.arithmetic_flags&0x400),"actualRootRET16/fullMOV1/nonvolDF");need(fp::same_numeric(state.fp.image,incoming),"actual API transportednumeric86/all80 identity");
 Result result{state.ax,state,{}};for(unsigned k=0;k<16;++k){result.words[k]=m.r32(entry+4+4*k);need(result.words[k]==before[k],"all16actualcallerwords unchanged");}return result;
}
}
