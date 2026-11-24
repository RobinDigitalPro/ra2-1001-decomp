#include "recovered/recovery_b233_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b233 {
namespace {
void f_001a4890(Memory&,State&,Frame&,const Operations&);
void f_0036ebd0(Memory&,State&,Frame&,const Operations&);
void f_001a6450(Memory&,State&,Frame&,const Operations&);
void f_001a5e10(Memory&,State&,Frame&,const Operations&);
void f_001a5ff0(Memory&,State&,Frame&,const Operations&);
void f_001a5d00(Memory&,State&,Frame&,const Operations&);
void f_001a45b0(Memory&,State&,Frame&,const Operations&);
void f_001a58e0(Memory&,State&,Frame&,const Operations&);
void f_001a46f0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_001a4890(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005a4890: { // 0x5a4890: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005a4891: { // 0x5a4891: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L005a4893: { // 0x5a4893: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  L005a4897: { // 0x5a4897: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005a4898: { // 0x5a4898: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005a489a: { // 0x5a489a: 8bfe MOV EDI,ESI
    s.di = s.si;
  }
  L005a489c: { // 0x5a489c: f3ab STOSD.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::count);
  }
  L005a489e: { // 0x5a489e: 8916 MOV dword ptr [ESI],EDX
    m.w32((s.si), s.dx);
  }
  L005a48a0: { // 0x5a48a0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005a48a1: { // 0x5a48a1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005a48a2: { // 0x5a48a2: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0036ebd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0076ebd0: { // 0x76ebd0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0076ebd1: { // 0x76ebd1: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L0076ebd3: { // 0x76ebd3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0076ebd4: { // 0x76ebd4: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0076ebd5: { // 0x76ebd5: 8b750c MOV ESI,dword ptr [EBP + 0xc]
    s.si = m.r32((s.bp+0x0000000cu));
  }
  L0076ebd8: { // 0x76ebd8: 8b4d10 MOV ECX,dword ptr [EBP + 0x10]
    s.cx = m.r32((s.bp+0x00000010u));
  }
  L0076ebdb: { // 0x76ebdb: 8b7d08 MOV EDI,dword ptr [EBP + 0x8]
    s.di = m.r32((s.bp+0x00000008u));
  }
  L0076ebde: { // 0x76ebde: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0076ebe0: { // 0x76ebe0: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L0076ebe2: { // 0x76ebe2: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L0076ebe4: { // 0x76ebe4: 3bfe CMP EDI,ESI
    (void)integer::sub(s.di,s.si,32,flags);
  }
  L0076ebe6: { // 0x76ebe6: 7608 JBE 0x0076ebf0
    if(integer::condition("JBE",flags)) goto L0076ebf0;
  }
  L0076ebe8: { // 0x76ebe8: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L0076ebea: { // 0x76ebea: 0f8278010000 JC 0x0076ed68
    if(integer::condition("JC",flags)) goto L0076ed68;
  }
  L0076ebf0: { // 0x76ebf0: f7c703000000 TEST EDI,0x3
    (void)integer::logical((s.di)&(0x00000003u),32,flags);
  }
  L0076ebf6: { // 0x76ebf6: 7514 JNZ 0x0076ec0c
    if(integer::condition("JNZ",flags)) goto L0076ec0c;
  }
  L0076ebf8: { // 0x76ebf8: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L0076ebfb: { // 0x76ebfb: 83e203 AND EDX,0x3
    s.dx = integer::logical((s.dx)&(0x00000003u),32,flags);
  }
  L0076ebfe: { // 0x76ebfe: 83f908 CMP ECX,0x8
    (void)integer::sub(s.cx,0x00000008u,32,flags);
  }
  L0076ec01: { // 0x76ec01: 7229 JC 0x0076ec2c
    if(integer::condition("JC",flags)) goto L0076ec2c;
  }
  L0076ec03: { // 0x76ec03: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L0076ec05: { // 0x76ec05: ff249518ed7600 JMP dword ptr [EDX*0x4 + 0x76ed18]
    switch(m.r32(((s.dx * 0x00000004u)+0x0076ed18u))){
    case 0x0076ebd0u: goto L0076ebd0;
    case 0x0076ebd1u: goto L0076ebd1;
    case 0x0076ebd3u: goto L0076ebd3;
    case 0x0076ebd4u: goto L0076ebd4;
    case 0x0076ebd5u: goto L0076ebd5;
    case 0x0076ebd8u: goto L0076ebd8;
    case 0x0076ebdbu: goto L0076ebdb;
    case 0x0076ebdeu: goto L0076ebde;
    case 0x0076ebe0u: goto L0076ebe0;
    case 0x0076ebe2u: goto L0076ebe2;
    case 0x0076ebe4u: goto L0076ebe4;
    case 0x0076ebe6u: goto L0076ebe6;
    case 0x0076ebe8u: goto L0076ebe8;
    case 0x0076ebeau: goto L0076ebea;
    case 0x0076ebf0u: goto L0076ebf0;
    case 0x0076ebf6u: goto L0076ebf6;
    case 0x0076ebf8u: goto L0076ebf8;
    case 0x0076ebfbu: goto L0076ebfb;
    case 0x0076ebfeu: goto L0076ebfe;
    case 0x0076ec01u: goto L0076ec01;
    case 0x0076ec03u: goto L0076ec03;
    case 0x0076ec05u: goto L0076ec05;
    case 0x0076ec0cu: goto L0076ec0c;
    case 0x0076ec0eu: goto L0076ec0e;
    case 0x0076ec13u: goto L0076ec13;
    case 0x0076ec16u: goto L0076ec16;
    case 0x0076ec18u: goto L0076ec18;
    case 0x0076ec1bu: goto L0076ec1b;
    case 0x0076ec1du: goto L0076ec1d;
    case 0x0076ec24u: goto L0076ec24;
    case 0x0076ec2cu: goto L0076ec2c;
    case 0x0076ec40u: goto L0076ec40;
    case 0x0076ec42u: goto L0076ec42;
    case 0x0076ec44u: goto L0076ec44;
    case 0x0076ec46u: goto L0076ec46;
    case 0x0076ec49u: goto L0076ec49;
    case 0x0076ec4cu: goto L0076ec4c;
    case 0x0076ec4fu: goto L0076ec4f;
    case 0x0076ec52u: goto L0076ec52;
    case 0x0076ec55u: goto L0076ec55;
    case 0x0076ec58u: goto L0076ec58;
    case 0x0076ec5bu: goto L0076ec5b;
    case 0x0076ec5eu: goto L0076ec5e;
    case 0x0076ec60u: goto L0076ec60;
    case 0x0076ec62u: goto L0076ec62;
    case 0x0076ec6cu: goto L0076ec6c;
    case 0x0076ec6eu: goto L0076ec6e;
    case 0x0076ec70u: goto L0076ec70;
    case 0x0076ec72u: goto L0076ec72;
    case 0x0076ec75u: goto L0076ec75;
    case 0x0076ec78u: goto L0076ec78;
    case 0x0076ec7bu: goto L0076ec7b;
    case 0x0076ec7eu: goto L0076ec7e;
    case 0x0076ec81u: goto L0076ec81;
    case 0x0076ec84u: goto L0076ec84;
    case 0x0076ec86u: goto L0076ec86;
    case 0x0076ec88u: goto L0076ec88;
    case 0x0076ec90u: goto L0076ec90;
    case 0x0076ec92u: goto L0076ec92;
    case 0x0076ec94u: goto L0076ec94;
    case 0x0076ec96u: goto L0076ec96;
    case 0x0076ec97u: goto L0076ec97;
    case 0x0076ec9au: goto L0076ec9a;
    case 0x0076ec9bu: goto L0076ec9b;
    case 0x0076ec9eu: goto L0076ec9e;
    case 0x0076eca0u: goto L0076eca0;
    case 0x0076eca2u: goto L0076eca2;
    case 0x0076ecccu: goto L0076eccc;
    case 0x0076ecd0u: goto L0076ecd0;
    case 0x0076ecd4u: goto L0076ecd4;
    case 0x0076ecd8u: goto L0076ecd8;
    case 0x0076ecdcu: goto L0076ecdc;
    case 0x0076ece0u: goto L0076ece0;
    case 0x0076ece4u: goto L0076ece4;
    case 0x0076ece8u: goto L0076ece8;
    case 0x0076ececu: goto L0076ecec;
    case 0x0076ecf0u: goto L0076ecf0;
    case 0x0076ecf4u: goto L0076ecf4;
    case 0x0076ecf8u: goto L0076ecf8;
    case 0x0076ecfcu: goto L0076ecfc;
    case 0x0076ed00u: goto L0076ed00;
    case 0x0076ed04u: goto L0076ed04;
    case 0x0076ed0bu: goto L0076ed0b;
    case 0x0076ed0du: goto L0076ed0d;
    case 0x0076ed0fu: goto L0076ed0f;
    case 0x0076ed28u: goto L0076ed28;
    case 0x0076ed2bu: goto L0076ed2b;
    case 0x0076ed2cu: goto L0076ed2c;
    case 0x0076ed2du: goto L0076ed2d;
    case 0x0076ed2eu: goto L0076ed2e;
    case 0x0076ed30u: goto L0076ed30;
    case 0x0076ed32u: goto L0076ed32;
    case 0x0076ed34u: goto L0076ed34;
    case 0x0076ed37u: goto L0076ed37;
    case 0x0076ed38u: goto L0076ed38;
    case 0x0076ed39u: goto L0076ed39;
    case 0x0076ed3au: goto L0076ed3a;
    case 0x0076ed3cu: goto L0076ed3c;
    case 0x0076ed3eu: goto L0076ed3e;
    case 0x0076ed40u: goto L0076ed40;
    case 0x0076ed43u: goto L0076ed43;
    case 0x0076ed46u: goto L0076ed46;
    case 0x0076ed49u: goto L0076ed49;
    case 0x0076ed4au: goto L0076ed4a;
    case 0x0076ed4bu: goto L0076ed4b;
    case 0x0076ed4cu: goto L0076ed4c;
    case 0x0076ed50u: goto L0076ed50;
    case 0x0076ed52u: goto L0076ed52;
    case 0x0076ed54u: goto L0076ed54;
    case 0x0076ed57u: goto L0076ed57;
    case 0x0076ed5au: goto L0076ed5a;
    case 0x0076ed5du: goto L0076ed5d;
    case 0x0076ed60u: goto L0076ed60;
    case 0x0076ed63u: goto L0076ed63;
    case 0x0076ed64u: goto L0076ed64;
    case 0x0076ed65u: goto L0076ed65;
    case 0x0076ed66u: goto L0076ed66;
    case 0x0076ed68u: goto L0076ed68;
    case 0x0076ed6cu: goto L0076ed6c;
    case 0x0076ed70u: goto L0076ed70;
    case 0x0076ed76u: goto L0076ed76;
    case 0x0076ed78u: goto L0076ed78;
    case 0x0076ed7bu: goto L0076ed7b;
    case 0x0076ed7eu: goto L0076ed7e;
    case 0x0076ed81u: goto L0076ed81;
    case 0x0076ed83u: goto L0076ed83;
    case 0x0076ed84u: goto L0076ed84;
    case 0x0076ed86u: goto L0076ed86;
    case 0x0076ed87u: goto L0076ed87;
    case 0x0076ed90u: goto L0076ed90;
    case 0x0076ed92u: goto L0076ed92;
    case 0x0076ed9cu: goto L0076ed9c;
    case 0x0076ed9eu: goto L0076ed9e;
    case 0x0076eda3u: goto L0076eda3;
    case 0x0076eda6u: goto L0076eda6;
    case 0x0076eda8u: goto L0076eda8;
    case 0x0076edabu: goto L0076edab;
    case 0x0076edadu: goto L0076edad;
    case 0x0076edb4u: goto L0076edb4;
    case 0x0076edc8u: goto L0076edc8;
    case 0x0076edcbu: goto L0076edcb;
    case 0x0076edcdu: goto L0076edcd;
    case 0x0076edd0u: goto L0076edd0;
    case 0x0076edd1u: goto L0076edd1;
    case 0x0076edd4u: goto L0076edd4;
    case 0x0076edd5u: goto L0076edd5;
    case 0x0076edd8u: goto L0076edd8;
    case 0x0076eddau: goto L0076edda;
    case 0x0076eddbu: goto L0076eddb;
    case 0x0076edddu: goto L0076eddd;
    case 0x0076eddeu: goto L0076edde;
    case 0x0076ede8u: goto L0076ede8;
    case 0x0076edebu: goto L0076edeb;
    case 0x0076ededu: goto L0076eded;
    case 0x0076edf0u: goto L0076edf0;
    case 0x0076edf3u: goto L0076edf3;
    case 0x0076edf6u: goto L0076edf6;
    case 0x0076edf9u: goto L0076edf9;
    case 0x0076edfcu: goto L0076edfc;
    case 0x0076edffu: goto L0076edff;
    case 0x0076ee02u: goto L0076ee02;
    case 0x0076ee04u: goto L0076ee04;
    case 0x0076ee05u: goto L0076ee05;
    case 0x0076ee07u: goto L0076ee07;
    case 0x0076ee08u: goto L0076ee08;
    case 0x0076ee10u: goto L0076ee10;
    case 0x0076ee13u: goto L0076ee13;
    case 0x0076ee15u: goto L0076ee15;
    case 0x0076ee18u: goto L0076ee18;
    case 0x0076ee1bu: goto L0076ee1b;
    case 0x0076ee1eu: goto L0076ee1e;
    case 0x0076ee21u: goto L0076ee21;
    case 0x0076ee24u: goto L0076ee24;
    case 0x0076ee27u: goto L0076ee27;
    case 0x0076ee2au: goto L0076ee2a;
    case 0x0076ee2du: goto L0076ee2d;
    case 0x0076ee30u: goto L0076ee30;
    case 0x0076ee36u: goto L0076ee36;
    case 0x0076ee37u: goto L0076ee37;
    case 0x0076ee39u: goto L0076ee39;
    case 0x0076ee3au: goto L0076ee3a;
    case 0x0076ee64u: goto L0076ee64;
    case 0x0076ee68u: goto L0076ee68;
    case 0x0076ee6cu: goto L0076ee6c;
    case 0x0076ee70u: goto L0076ee70;
    case 0x0076ee74u: goto L0076ee74;
    case 0x0076ee78u: goto L0076ee78;
    case 0x0076ee7cu: goto L0076ee7c;
    case 0x0076ee80u: goto L0076ee80;
    case 0x0076ee84u: goto L0076ee84;
    case 0x0076ee88u: goto L0076ee88;
    case 0x0076ee8cu: goto L0076ee8c;
    case 0x0076ee90u: goto L0076ee90;
    case 0x0076ee94u: goto L0076ee94;
    case 0x0076ee98u: goto L0076ee98;
    case 0x0076ee9cu: goto L0076ee9c;
    case 0x0076eea3u: goto L0076eea3;
    case 0x0076eea5u: goto L0076eea5;
    case 0x0076eea7u: goto L0076eea7;
    case 0x0076eec0u: goto L0076eec0;
    case 0x0076eec3u: goto L0076eec3;
    case 0x0076eec4u: goto L0076eec4;
    case 0x0076eec5u: goto L0076eec5;
    case 0x0076eec6u: goto L0076eec6;
    case 0x0076eec8u: goto L0076eec8;
    case 0x0076eecbu: goto L0076eecb;
    case 0x0076eeceu: goto L0076eece;
    case 0x0076eed1u: goto L0076eed1;
    case 0x0076eed2u: goto L0076eed2;
    case 0x0076eed3u: goto L0076eed3;
    case 0x0076eed4u: goto L0076eed4;
    case 0x0076eed8u: goto L0076eed8;
    case 0x0076eedbu: goto L0076eedb;
    case 0x0076eedeu: goto L0076eede;
    case 0x0076eee1u: goto L0076eee1;
    case 0x0076eee4u: goto L0076eee4;
    case 0x0076eee7u: goto L0076eee7;
    case 0x0076eee8u: goto L0076eee8;
    case 0x0076eee9u: goto L0076eee9;
    case 0x0076eeeau: goto L0076eeea;
    case 0x0076eeecu: goto L0076eeec;
    case 0x0076eeefu: goto L0076eeef;
    case 0x0076eef2u: goto L0076eef2;
    case 0x0076eef5u: goto L0076eef5;
    case 0x0076eef8u: goto L0076eef8;
    case 0x0076eefbu: goto L0076eefb;
    case 0x0076eefeu: goto L0076eefe;
    case 0x0076ef01u: goto L0076ef01;
    case 0x0076ef02u: goto L0076ef02;
    case 0x0076ef03u: goto L0076ef03;
    case 0x0076ef04u: goto L0076ef04;
    default:throw std::domain_error("recovery233 unsupported switch destination");}
  }
  L0076ec0c: { // 0x76ec0c: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0076ec0e: { // 0x76ec0e: ba03000000 MOV EDX,0x3
    s.dx = 0x00000003u;
  }
  L0076ec13: { // 0x76ec13: 83e904 SUB ECX,0x4
    s.cx = integer::sub(s.cx,0x00000004u,32,flags);
  }
  L0076ec16: { // 0x76ec16: 720c JC 0x0076ec24
    if(integer::condition("JC",flags)) goto L0076ec24;
  }
  L0076ec18: { // 0x76ec18: 83e003 AND EAX,0x3
    s.ax = integer::logical((s.ax)&(0x00000003u),32,flags);
  }
  L0076ec1b: { // 0x76ec1b: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0076ec1d: { // 0x76ec1d: ff248530ec7600 JMP dword ptr [EAX*0x4 + 0x76ec30]
    switch(m.r32(((s.ax * 0x00000004u)+0x0076ec30u))){
    case 0x0076ebd0u: goto L0076ebd0;
    case 0x0076ebd1u: goto L0076ebd1;
    case 0x0076ebd3u: goto L0076ebd3;
    case 0x0076ebd4u: goto L0076ebd4;
    case 0x0076ebd5u: goto L0076ebd5;
    case 0x0076ebd8u: goto L0076ebd8;
    case 0x0076ebdbu: goto L0076ebdb;
    case 0x0076ebdeu: goto L0076ebde;
    case 0x0076ebe0u: goto L0076ebe0;
    case 0x0076ebe2u: goto L0076ebe2;
    case 0x0076ebe4u: goto L0076ebe4;
    case 0x0076ebe6u: goto L0076ebe6;
    case 0x0076ebe8u: goto L0076ebe8;
    case 0x0076ebeau: goto L0076ebea;
    case 0x0076ebf0u: goto L0076ebf0;
    case 0x0076ebf6u: goto L0076ebf6;
    case 0x0076ebf8u: goto L0076ebf8;
    case 0x0076ebfbu: goto L0076ebfb;
    case 0x0076ebfeu: goto L0076ebfe;
    case 0x0076ec01u: goto L0076ec01;
    case 0x0076ec03u: goto L0076ec03;
    case 0x0076ec05u: goto L0076ec05;
    case 0x0076ec0cu: goto L0076ec0c;
    case 0x0076ec0eu: goto L0076ec0e;
    case 0x0076ec13u: goto L0076ec13;
    case 0x0076ec16u: goto L0076ec16;
    case 0x0076ec18u: goto L0076ec18;
    case 0x0076ec1bu: goto L0076ec1b;
    case 0x0076ec1du: goto L0076ec1d;
    case 0x0076ec24u: goto L0076ec24;
    case 0x0076ec2cu: goto L0076ec2c;
    case 0x0076ec40u: goto L0076ec40;
    case 0x0076ec42u: goto L0076ec42;
    case 0x0076ec44u: goto L0076ec44;
    case 0x0076ec46u: goto L0076ec46;
    case 0x0076ec49u: goto L0076ec49;
    case 0x0076ec4cu: goto L0076ec4c;
    case 0x0076ec4fu: goto L0076ec4f;
    case 0x0076ec52u: goto L0076ec52;
    case 0x0076ec55u: goto L0076ec55;
    case 0x0076ec58u: goto L0076ec58;
    case 0x0076ec5bu: goto L0076ec5b;
    case 0x0076ec5eu: goto L0076ec5e;
    case 0x0076ec60u: goto L0076ec60;
    case 0x0076ec62u: goto L0076ec62;
    case 0x0076ec6cu: goto L0076ec6c;
    case 0x0076ec6eu: goto L0076ec6e;
    case 0x0076ec70u: goto L0076ec70;
    case 0x0076ec72u: goto L0076ec72;
    case 0x0076ec75u: goto L0076ec75;
    case 0x0076ec78u: goto L0076ec78;
    case 0x0076ec7bu: goto L0076ec7b;
    case 0x0076ec7eu: goto L0076ec7e;
    case 0x0076ec81u: goto L0076ec81;
    case 0x0076ec84u: goto L0076ec84;
    case 0x0076ec86u: goto L0076ec86;
    case 0x0076ec88u: goto L0076ec88;
    case 0x0076ec90u: goto L0076ec90;
    case 0x0076ec92u: goto L0076ec92;
    case 0x0076ec94u: goto L0076ec94;
    case 0x0076ec96u: goto L0076ec96;
    case 0x0076ec97u: goto L0076ec97;
    case 0x0076ec9au: goto L0076ec9a;
    case 0x0076ec9bu: goto L0076ec9b;
    case 0x0076ec9eu: goto L0076ec9e;
    case 0x0076eca0u: goto L0076eca0;
    case 0x0076eca2u: goto L0076eca2;
    case 0x0076ecccu: goto L0076eccc;
    case 0x0076ecd0u: goto L0076ecd0;
    case 0x0076ecd4u: goto L0076ecd4;
    case 0x0076ecd8u: goto L0076ecd8;
    case 0x0076ecdcu: goto L0076ecdc;
    case 0x0076ece0u: goto L0076ece0;
    case 0x0076ece4u: goto L0076ece4;
    case 0x0076ece8u: goto L0076ece8;
    case 0x0076ececu: goto L0076ecec;
    case 0x0076ecf0u: goto L0076ecf0;
    case 0x0076ecf4u: goto L0076ecf4;
    case 0x0076ecf8u: goto L0076ecf8;
    case 0x0076ecfcu: goto L0076ecfc;
    case 0x0076ed00u: goto L0076ed00;
    case 0x0076ed04u: goto L0076ed04;
    case 0x0076ed0bu: goto L0076ed0b;
    case 0x0076ed0du: goto L0076ed0d;
    case 0x0076ed0fu: goto L0076ed0f;
    case 0x0076ed28u: goto L0076ed28;
    case 0x0076ed2bu: goto L0076ed2b;
    case 0x0076ed2cu: goto L0076ed2c;
    case 0x0076ed2du: goto L0076ed2d;
    case 0x0076ed2eu: goto L0076ed2e;
    case 0x0076ed30u: goto L0076ed30;
    case 0x0076ed32u: goto L0076ed32;
    case 0x0076ed34u: goto L0076ed34;
    case 0x0076ed37u: goto L0076ed37;
    case 0x0076ed38u: goto L0076ed38;
    case 0x0076ed39u: goto L0076ed39;
    case 0x0076ed3au: goto L0076ed3a;
    case 0x0076ed3cu: goto L0076ed3c;
    case 0x0076ed3eu: goto L0076ed3e;
    case 0x0076ed40u: goto L0076ed40;
    case 0x0076ed43u: goto L0076ed43;
    case 0x0076ed46u: goto L0076ed46;
    case 0x0076ed49u: goto L0076ed49;
    case 0x0076ed4au: goto L0076ed4a;
    case 0x0076ed4bu: goto L0076ed4b;
    case 0x0076ed4cu: goto L0076ed4c;
    case 0x0076ed50u: goto L0076ed50;
    case 0x0076ed52u: goto L0076ed52;
    case 0x0076ed54u: goto L0076ed54;
    case 0x0076ed57u: goto L0076ed57;
    case 0x0076ed5au: goto L0076ed5a;
    case 0x0076ed5du: goto L0076ed5d;
    case 0x0076ed60u: goto L0076ed60;
    case 0x0076ed63u: goto L0076ed63;
    case 0x0076ed64u: goto L0076ed64;
    case 0x0076ed65u: goto L0076ed65;
    case 0x0076ed66u: goto L0076ed66;
    case 0x0076ed68u: goto L0076ed68;
    case 0x0076ed6cu: goto L0076ed6c;
    case 0x0076ed70u: goto L0076ed70;
    case 0x0076ed76u: goto L0076ed76;
    case 0x0076ed78u: goto L0076ed78;
    case 0x0076ed7bu: goto L0076ed7b;
    case 0x0076ed7eu: goto L0076ed7e;
    case 0x0076ed81u: goto L0076ed81;
    case 0x0076ed83u: goto L0076ed83;
    case 0x0076ed84u: goto L0076ed84;
    case 0x0076ed86u: goto L0076ed86;
    case 0x0076ed87u: goto L0076ed87;
    case 0x0076ed90u: goto L0076ed90;
    case 0x0076ed92u: goto L0076ed92;
    case 0x0076ed9cu: goto L0076ed9c;
    case 0x0076ed9eu: goto L0076ed9e;
    case 0x0076eda3u: goto L0076eda3;
    case 0x0076eda6u: goto L0076eda6;
    case 0x0076eda8u: goto L0076eda8;
    case 0x0076edabu: goto L0076edab;
    case 0x0076edadu: goto L0076edad;
    case 0x0076edb4u: goto L0076edb4;
    case 0x0076edc8u: goto L0076edc8;
    case 0x0076edcbu: goto L0076edcb;
    case 0x0076edcdu: goto L0076edcd;
    case 0x0076edd0u: goto L0076edd0;
    case 0x0076edd1u: goto L0076edd1;
    case 0x0076edd4u: goto L0076edd4;
    case 0x0076edd5u: goto L0076edd5;
    case 0x0076edd8u: goto L0076edd8;
    case 0x0076eddau: goto L0076edda;
    case 0x0076eddbu: goto L0076eddb;
    case 0x0076edddu: goto L0076eddd;
    case 0x0076eddeu: goto L0076edde;
    case 0x0076ede8u: goto L0076ede8;
    case 0x0076edebu: goto L0076edeb;
    case 0x0076ededu: goto L0076eded;
    case 0x0076edf0u: goto L0076edf0;
    case 0x0076edf3u: goto L0076edf3;
    case 0x0076edf6u: goto L0076edf6;
    case 0x0076edf9u: goto L0076edf9;
    case 0x0076edfcu: goto L0076edfc;
    case 0x0076edffu: goto L0076edff;
    case 0x0076ee02u: goto L0076ee02;
    case 0x0076ee04u: goto L0076ee04;
    case 0x0076ee05u: goto L0076ee05;
    case 0x0076ee07u: goto L0076ee07;
    case 0x0076ee08u: goto L0076ee08;
    case 0x0076ee10u: goto L0076ee10;
    case 0x0076ee13u: goto L0076ee13;
    case 0x0076ee15u: goto L0076ee15;
    case 0x0076ee18u: goto L0076ee18;
    case 0x0076ee1bu: goto L0076ee1b;
    case 0x0076ee1eu: goto L0076ee1e;
    case 0x0076ee21u: goto L0076ee21;
    case 0x0076ee24u: goto L0076ee24;
    case 0x0076ee27u: goto L0076ee27;
    case 0x0076ee2au: goto L0076ee2a;
    case 0x0076ee2du: goto L0076ee2d;
    case 0x0076ee30u: goto L0076ee30;
    case 0x0076ee36u: goto L0076ee36;
    case 0x0076ee37u: goto L0076ee37;
    case 0x0076ee39u: goto L0076ee39;
    case 0x0076ee3au: goto L0076ee3a;
    case 0x0076ee64u: goto L0076ee64;
    case 0x0076ee68u: goto L0076ee68;
    case 0x0076ee6cu: goto L0076ee6c;
    case 0x0076ee70u: goto L0076ee70;
    case 0x0076ee74u: goto L0076ee74;
    case 0x0076ee78u: goto L0076ee78;
    case 0x0076ee7cu: goto L0076ee7c;
    case 0x0076ee80u: goto L0076ee80;
    case 0x0076ee84u: goto L0076ee84;
    case 0x0076ee88u: goto L0076ee88;
    case 0x0076ee8cu: goto L0076ee8c;
    case 0x0076ee90u: goto L0076ee90;
    case 0x0076ee94u: goto L0076ee94;
    case 0x0076ee98u: goto L0076ee98;
    case 0x0076ee9cu: goto L0076ee9c;
    case 0x0076eea3u: goto L0076eea3;
    case 0x0076eea5u: goto L0076eea5;
    case 0x0076eea7u: goto L0076eea7;
    case 0x0076eec0u: goto L0076eec0;
    case 0x0076eec3u: goto L0076eec3;
    case 0x0076eec4u: goto L0076eec4;
    case 0x0076eec5u: goto L0076eec5;
    case 0x0076eec6u: goto L0076eec6;
    case 0x0076eec8u: goto L0076eec8;
    case 0x0076eecbu: goto L0076eecb;
    case 0x0076eeceu: goto L0076eece;
    case 0x0076eed1u: goto L0076eed1;
    case 0x0076eed2u: goto L0076eed2;
    case 0x0076eed3u: goto L0076eed3;
    case 0x0076eed4u: goto L0076eed4;
    case 0x0076eed8u: goto L0076eed8;
    case 0x0076eedbu: goto L0076eedb;
    case 0x0076eedeu: goto L0076eede;
    case 0x0076eee1u: goto L0076eee1;
    case 0x0076eee4u: goto L0076eee4;
    case 0x0076eee7u: goto L0076eee7;
    case 0x0076eee8u: goto L0076eee8;
    case 0x0076eee9u: goto L0076eee9;
    case 0x0076eeeau: goto L0076eeea;
    case 0x0076eeecu: goto L0076eeec;
    case 0x0076eeefu: goto L0076eeef;
    case 0x0076eef2u: goto L0076eef2;
    case 0x0076eef5u: goto L0076eef5;
    case 0x0076eef8u: goto L0076eef8;
    case 0x0076eefbu: goto L0076eefb;
    case 0x0076eefeu: goto L0076eefe;
    case 0x0076ef01u: goto L0076ef01;
    case 0x0076ef02u: goto L0076ef02;
    case 0x0076ef03u: goto L0076ef03;
    case 0x0076ef04u: goto L0076ef04;
    default:throw std::domain_error("recovery233 unsupported switch destination");}
  }
  L0076ec24: { // 0x76ec24: ff248d28ed7600 JMP dword ptr [ECX*0x4 + 0x76ed28]
    switch(m.r32(((s.cx * 0x00000004u)+0x0076ed28u))){
    case 0x0076ebd0u: goto L0076ebd0;
    case 0x0076ebd1u: goto L0076ebd1;
    case 0x0076ebd3u: goto L0076ebd3;
    case 0x0076ebd4u: goto L0076ebd4;
    case 0x0076ebd5u: goto L0076ebd5;
    case 0x0076ebd8u: goto L0076ebd8;
    case 0x0076ebdbu: goto L0076ebdb;
    case 0x0076ebdeu: goto L0076ebde;
    case 0x0076ebe0u: goto L0076ebe0;
    case 0x0076ebe2u: goto L0076ebe2;
    case 0x0076ebe4u: goto L0076ebe4;
    case 0x0076ebe6u: goto L0076ebe6;
    case 0x0076ebe8u: goto L0076ebe8;
    case 0x0076ebeau: goto L0076ebea;
    case 0x0076ebf0u: goto L0076ebf0;
    case 0x0076ebf6u: goto L0076ebf6;
    case 0x0076ebf8u: goto L0076ebf8;
    case 0x0076ebfbu: goto L0076ebfb;
    case 0x0076ebfeu: goto L0076ebfe;
    case 0x0076ec01u: goto L0076ec01;
    case 0x0076ec03u: goto L0076ec03;
    case 0x0076ec05u: goto L0076ec05;
    case 0x0076ec0cu: goto L0076ec0c;
    case 0x0076ec0eu: goto L0076ec0e;
    case 0x0076ec13u: goto L0076ec13;
    case 0x0076ec16u: goto L0076ec16;
    case 0x0076ec18u: goto L0076ec18;
    case 0x0076ec1bu: goto L0076ec1b;
    case 0x0076ec1du: goto L0076ec1d;
    case 0x0076ec24u: goto L0076ec24;
    case 0x0076ec2cu: goto L0076ec2c;
    case 0x0076ec40u: goto L0076ec40;
    case 0x0076ec42u: goto L0076ec42;
    case 0x0076ec44u: goto L0076ec44;
    case 0x0076ec46u: goto L0076ec46;
    case 0x0076ec49u: goto L0076ec49;
    case 0x0076ec4cu: goto L0076ec4c;
    case 0x0076ec4fu: goto L0076ec4f;
    case 0x0076ec52u: goto L0076ec52;
    case 0x0076ec55u: goto L0076ec55;
    case 0x0076ec58u: goto L0076ec58;
    case 0x0076ec5bu: goto L0076ec5b;
    case 0x0076ec5eu: goto L0076ec5e;
    case 0x0076ec60u: goto L0076ec60;
    case 0x0076ec62u: goto L0076ec62;
    case 0x0076ec6cu: goto L0076ec6c;
    case 0x0076ec6eu: goto L0076ec6e;
    case 0x0076ec70u: goto L0076ec70;
    case 0x0076ec72u: goto L0076ec72;
    case 0x0076ec75u: goto L0076ec75;
    case 0x0076ec78u: goto L0076ec78;
    case 0x0076ec7bu: goto L0076ec7b;
    case 0x0076ec7eu: goto L0076ec7e;
    case 0x0076ec81u: goto L0076ec81;
    case 0x0076ec84u: goto L0076ec84;
    case 0x0076ec86u: goto L0076ec86;
    case 0x0076ec88u: goto L0076ec88;
    case 0x0076ec90u: goto L0076ec90;
    case 0x0076ec92u: goto L0076ec92;
    case 0x0076ec94u: goto L0076ec94;
    case 0x0076ec96u: goto L0076ec96;
    case 0x0076ec97u: goto L0076ec97;
    case 0x0076ec9au: goto L0076ec9a;
    case 0x0076ec9bu: goto L0076ec9b;
    case 0x0076ec9eu: goto L0076ec9e;
    case 0x0076eca0u: goto L0076eca0;
    case 0x0076eca2u: goto L0076eca2;
    case 0x0076ecccu: goto L0076eccc;
    case 0x0076ecd0u: goto L0076ecd0;
    case 0x0076ecd4u: goto L0076ecd4;
    case 0x0076ecd8u: goto L0076ecd8;
    case 0x0076ecdcu: goto L0076ecdc;
    case 0x0076ece0u: goto L0076ece0;
    case 0x0076ece4u: goto L0076ece4;
    case 0x0076ece8u: goto L0076ece8;
    case 0x0076ececu: goto L0076ecec;
    case 0x0076ecf0u: goto L0076ecf0;
    case 0x0076ecf4u: goto L0076ecf4;
    case 0x0076ecf8u: goto L0076ecf8;
    case 0x0076ecfcu: goto L0076ecfc;
    case 0x0076ed00u: goto L0076ed00;
    case 0x0076ed04u: goto L0076ed04;
    case 0x0076ed0bu: goto L0076ed0b;
    case 0x0076ed0du: goto L0076ed0d;
    case 0x0076ed0fu: goto L0076ed0f;
    case 0x0076ed28u: goto L0076ed28;
    case 0x0076ed2bu: goto L0076ed2b;
    case 0x0076ed2cu: goto L0076ed2c;
    case 0x0076ed2du: goto L0076ed2d;
    case 0x0076ed2eu: goto L0076ed2e;
    case 0x0076ed30u: goto L0076ed30;
    case 0x0076ed32u: goto L0076ed32;
    case 0x0076ed34u: goto L0076ed34;
    case 0x0076ed37u: goto L0076ed37;
    case 0x0076ed38u: goto L0076ed38;
    case 0x0076ed39u: goto L0076ed39;
    case 0x0076ed3au: goto L0076ed3a;
    case 0x0076ed3cu: goto L0076ed3c;
    case 0x0076ed3eu: goto L0076ed3e;
    case 0x0076ed40u: goto L0076ed40;
    case 0x0076ed43u: goto L0076ed43;
    case 0x0076ed46u: goto L0076ed46;
    case 0x0076ed49u: goto L0076ed49;
    case 0x0076ed4au: goto L0076ed4a;
    case 0x0076ed4bu: goto L0076ed4b;
    case 0x0076ed4cu: goto L0076ed4c;
    case 0x0076ed50u: goto L0076ed50;
    case 0x0076ed52u: goto L0076ed52;
    case 0x0076ed54u: goto L0076ed54;
    case 0x0076ed57u: goto L0076ed57;
    case 0x0076ed5au: goto L0076ed5a;
    case 0x0076ed5du: goto L0076ed5d;
    case 0x0076ed60u: goto L0076ed60;
    case 0x0076ed63u: goto L0076ed63;
    case 0x0076ed64u: goto L0076ed64;
    case 0x0076ed65u: goto L0076ed65;
    case 0x0076ed66u: goto L0076ed66;
    case 0x0076ed68u: goto L0076ed68;
    case 0x0076ed6cu: goto L0076ed6c;
    case 0x0076ed70u: goto L0076ed70;
    case 0x0076ed76u: goto L0076ed76;
    case 0x0076ed78u: goto L0076ed78;
    case 0x0076ed7bu: goto L0076ed7b;
    case 0x0076ed7eu: goto L0076ed7e;
    case 0x0076ed81u: goto L0076ed81;
    case 0x0076ed83u: goto L0076ed83;
    case 0x0076ed84u: goto L0076ed84;
    case 0x0076ed86u: goto L0076ed86;
    case 0x0076ed87u: goto L0076ed87;
    case 0x0076ed90u: goto L0076ed90;
    case 0x0076ed92u: goto L0076ed92;
    case 0x0076ed9cu: goto L0076ed9c;
    case 0x0076ed9eu: goto L0076ed9e;
    case 0x0076eda3u: goto L0076eda3;
    case 0x0076eda6u: goto L0076eda6;
    case 0x0076eda8u: goto L0076eda8;
    case 0x0076edabu: goto L0076edab;
    case 0x0076edadu: goto L0076edad;
    case 0x0076edb4u: goto L0076edb4;
    case 0x0076edc8u: goto L0076edc8;
    case 0x0076edcbu: goto L0076edcb;
    case 0x0076edcdu: goto L0076edcd;
    case 0x0076edd0u: goto L0076edd0;
    case 0x0076edd1u: goto L0076edd1;
    case 0x0076edd4u: goto L0076edd4;
    case 0x0076edd5u: goto L0076edd5;
    case 0x0076edd8u: goto L0076edd8;
    case 0x0076eddau: goto L0076edda;
    case 0x0076eddbu: goto L0076eddb;
    case 0x0076edddu: goto L0076eddd;
    case 0x0076eddeu: goto L0076edde;
    case 0x0076ede8u: goto L0076ede8;
    case 0x0076edebu: goto L0076edeb;
    case 0x0076ededu: goto L0076eded;
    case 0x0076edf0u: goto L0076edf0;
    case 0x0076edf3u: goto L0076edf3;
    case 0x0076edf6u: goto L0076edf6;
    case 0x0076edf9u: goto L0076edf9;
    case 0x0076edfcu: goto L0076edfc;
    case 0x0076edffu: goto L0076edff;
    case 0x0076ee02u: goto L0076ee02;
    case 0x0076ee04u: goto L0076ee04;
    case 0x0076ee05u: goto L0076ee05;
    case 0x0076ee07u: goto L0076ee07;
    case 0x0076ee08u: goto L0076ee08;
    case 0x0076ee10u: goto L0076ee10;
    case 0x0076ee13u: goto L0076ee13;
    case 0x0076ee15u: goto L0076ee15;
    case 0x0076ee18u: goto L0076ee18;
    case 0x0076ee1bu: goto L0076ee1b;
    case 0x0076ee1eu: goto L0076ee1e;
    case 0x0076ee21u: goto L0076ee21;
    case 0x0076ee24u: goto L0076ee24;
    case 0x0076ee27u: goto L0076ee27;
    case 0x0076ee2au: goto L0076ee2a;
    case 0x0076ee2du: goto L0076ee2d;
    case 0x0076ee30u: goto L0076ee30;
    case 0x0076ee36u: goto L0076ee36;
    case 0x0076ee37u: goto L0076ee37;
    case 0x0076ee39u: goto L0076ee39;
    case 0x0076ee3au: goto L0076ee3a;
    case 0x0076ee64u: goto L0076ee64;
    case 0x0076ee68u: goto L0076ee68;
    case 0x0076ee6cu: goto L0076ee6c;
    case 0x0076ee70u: goto L0076ee70;
    case 0x0076ee74u: goto L0076ee74;
    case 0x0076ee78u: goto L0076ee78;
    case 0x0076ee7cu: goto L0076ee7c;
    case 0x0076ee80u: goto L0076ee80;
    case 0x0076ee84u: goto L0076ee84;
    case 0x0076ee88u: goto L0076ee88;
    case 0x0076ee8cu: goto L0076ee8c;
    case 0x0076ee90u: goto L0076ee90;
    case 0x0076ee94u: goto L0076ee94;
    case 0x0076ee98u: goto L0076ee98;
    case 0x0076ee9cu: goto L0076ee9c;
    case 0x0076eea3u: goto L0076eea3;
    case 0x0076eea5u: goto L0076eea5;
    case 0x0076eea7u: goto L0076eea7;
    case 0x0076eec0u: goto L0076eec0;
    case 0x0076eec3u: goto L0076eec3;
    case 0x0076eec4u: goto L0076eec4;
    case 0x0076eec5u: goto L0076eec5;
    case 0x0076eec6u: goto L0076eec6;
    case 0x0076eec8u: goto L0076eec8;
    case 0x0076eecbu: goto L0076eecb;
    case 0x0076eeceu: goto L0076eece;
    case 0x0076eed1u: goto L0076eed1;
    case 0x0076eed2u: goto L0076eed2;
    case 0x0076eed3u: goto L0076eed3;
    case 0x0076eed4u: goto L0076eed4;
    case 0x0076eed8u: goto L0076eed8;
    case 0x0076eedbu: goto L0076eedb;
    case 0x0076eedeu: goto L0076eede;
    case 0x0076eee1u: goto L0076eee1;
    case 0x0076eee4u: goto L0076eee4;
    case 0x0076eee7u: goto L0076eee7;
    case 0x0076eee8u: goto L0076eee8;
    case 0x0076eee9u: goto L0076eee9;
    case 0x0076eeeau: goto L0076eeea;
    case 0x0076eeecu: goto L0076eeec;
    case 0x0076eeefu: goto L0076eeef;
    case 0x0076eef2u: goto L0076eef2;
    case 0x0076eef5u: goto L0076eef5;
    case 0x0076eef8u: goto L0076eef8;
    case 0x0076eefbu: goto L0076eefb;
    case 0x0076eefeu: goto L0076eefe;
    case 0x0076ef01u: goto L0076ef01;
    case 0x0076ef02u: goto L0076ef02;
    case 0x0076ef03u: goto L0076ef03;
    case 0x0076ef04u: goto L0076ef04;
    default:throw std::domain_error("recovery233 unsupported switch destination");}
  }
  L0076ec2c: { // 0x76ec2c: ff248dacec7600 JMP dword ptr [ECX*0x4 + 0x76ecac]
    switch(m.r32(((s.cx * 0x00000004u)+0x0076ecacu))){
    case 0x0076ebd0u: goto L0076ebd0;
    case 0x0076ebd1u: goto L0076ebd1;
    case 0x0076ebd3u: goto L0076ebd3;
    case 0x0076ebd4u: goto L0076ebd4;
    case 0x0076ebd5u: goto L0076ebd5;
    case 0x0076ebd8u: goto L0076ebd8;
    case 0x0076ebdbu: goto L0076ebdb;
    case 0x0076ebdeu: goto L0076ebde;
    case 0x0076ebe0u: goto L0076ebe0;
    case 0x0076ebe2u: goto L0076ebe2;
    case 0x0076ebe4u: goto L0076ebe4;
    case 0x0076ebe6u: goto L0076ebe6;
    case 0x0076ebe8u: goto L0076ebe8;
    case 0x0076ebeau: goto L0076ebea;
    case 0x0076ebf0u: goto L0076ebf0;
    case 0x0076ebf6u: goto L0076ebf6;
    case 0x0076ebf8u: goto L0076ebf8;
    case 0x0076ebfbu: goto L0076ebfb;
    case 0x0076ebfeu: goto L0076ebfe;
    case 0x0076ec01u: goto L0076ec01;
    case 0x0076ec03u: goto L0076ec03;
    case 0x0076ec05u: goto L0076ec05;
    case 0x0076ec0cu: goto L0076ec0c;
    case 0x0076ec0eu: goto L0076ec0e;
    case 0x0076ec13u: goto L0076ec13;
    case 0x0076ec16u: goto L0076ec16;
    case 0x0076ec18u: goto L0076ec18;
    case 0x0076ec1bu: goto L0076ec1b;
    case 0x0076ec1du: goto L0076ec1d;
    case 0x0076ec24u: goto L0076ec24;
    case 0x0076ec2cu: goto L0076ec2c;
    case 0x0076ec40u: goto L0076ec40;
    case 0x0076ec42u: goto L0076ec42;
    case 0x0076ec44u: goto L0076ec44;
    case 0x0076ec46u: goto L0076ec46;
    case 0x0076ec49u: goto L0076ec49;
    case 0x0076ec4cu: goto L0076ec4c;
    case 0x0076ec4fu: goto L0076ec4f;
    case 0x0076ec52u: goto L0076ec52;
    case 0x0076ec55u: goto L0076ec55;
    case 0x0076ec58u: goto L0076ec58;
    case 0x0076ec5bu: goto L0076ec5b;
    case 0x0076ec5eu: goto L0076ec5e;
    case 0x0076ec60u: goto L0076ec60;
    case 0x0076ec62u: goto L0076ec62;
    case 0x0076ec6cu: goto L0076ec6c;
    case 0x0076ec6eu: goto L0076ec6e;
    case 0x0076ec70u: goto L0076ec70;
    case 0x0076ec72u: goto L0076ec72;
    case 0x0076ec75u: goto L0076ec75;
    case 0x0076ec78u: goto L0076ec78;
    case 0x0076ec7bu: goto L0076ec7b;
    case 0x0076ec7eu: goto L0076ec7e;
    case 0x0076ec81u: goto L0076ec81;
    case 0x0076ec84u: goto L0076ec84;
    case 0x0076ec86u: goto L0076ec86;
    case 0x0076ec88u: goto L0076ec88;
    case 0x0076ec90u: goto L0076ec90;
    case 0x0076ec92u: goto L0076ec92;
    case 0x0076ec94u: goto L0076ec94;
    case 0x0076ec96u: goto L0076ec96;
    case 0x0076ec97u: goto L0076ec97;
    case 0x0076ec9au: goto L0076ec9a;
    case 0x0076ec9bu: goto L0076ec9b;
    case 0x0076ec9eu: goto L0076ec9e;
    case 0x0076eca0u: goto L0076eca0;
    case 0x0076eca2u: goto L0076eca2;
    case 0x0076ecccu: goto L0076eccc;
    case 0x0076ecd0u: goto L0076ecd0;
    case 0x0076ecd4u: goto L0076ecd4;
    case 0x0076ecd8u: goto L0076ecd8;
    case 0x0076ecdcu: goto L0076ecdc;
    case 0x0076ece0u: goto L0076ece0;
    case 0x0076ece4u: goto L0076ece4;
    case 0x0076ece8u: goto L0076ece8;
    case 0x0076ececu: goto L0076ecec;
    case 0x0076ecf0u: goto L0076ecf0;
    case 0x0076ecf4u: goto L0076ecf4;
    case 0x0076ecf8u: goto L0076ecf8;
    case 0x0076ecfcu: goto L0076ecfc;
    case 0x0076ed00u: goto L0076ed00;
    case 0x0076ed04u: goto L0076ed04;
    case 0x0076ed0bu: goto L0076ed0b;
    case 0x0076ed0du: goto L0076ed0d;
    case 0x0076ed0fu: goto L0076ed0f;
    case 0x0076ed28u: goto L0076ed28;
    case 0x0076ed2bu: goto L0076ed2b;
    case 0x0076ed2cu: goto L0076ed2c;
    case 0x0076ed2du: goto L0076ed2d;
    case 0x0076ed2eu: goto L0076ed2e;
    case 0x0076ed30u: goto L0076ed30;
    case 0x0076ed32u: goto L0076ed32;
    case 0x0076ed34u: goto L0076ed34;
    case 0x0076ed37u: goto L0076ed37;
    case 0x0076ed38u: goto L0076ed38;
    case 0x0076ed39u: goto L0076ed39;
    case 0x0076ed3au: goto L0076ed3a;
    case 0x0076ed3cu: goto L0076ed3c;
    case 0x0076ed3eu: goto L0076ed3e;
    case 0x0076ed40u: goto L0076ed40;
    case 0x0076ed43u: goto L0076ed43;
    case 0x0076ed46u: goto L0076ed46;
    case 0x0076ed49u: goto L0076ed49;
    case 0x0076ed4au: goto L0076ed4a;
    case 0x0076ed4bu: goto L0076ed4b;
    case 0x0076ed4cu: goto L0076ed4c;
    case 0x0076ed50u: goto L0076ed50;
    case 0x0076ed52u: goto L0076ed52;
    case 0x0076ed54u: goto L0076ed54;
    case 0x0076ed57u: goto L0076ed57;
    case 0x0076ed5au: goto L0076ed5a;
    case 0x0076ed5du: goto L0076ed5d;
    case 0x0076ed60u: goto L0076ed60;
    case 0x0076ed63u: goto L0076ed63;
    case 0x0076ed64u: goto L0076ed64;
    case 0x0076ed65u: goto L0076ed65;
    case 0x0076ed66u: goto L0076ed66;
    case 0x0076ed68u: goto L0076ed68;
    case 0x0076ed6cu: goto L0076ed6c;
    case 0x0076ed70u: goto L0076ed70;
    case 0x0076ed76u: goto L0076ed76;
    case 0x0076ed78u: goto L0076ed78;
    case 0x0076ed7bu: goto L0076ed7b;
    case 0x0076ed7eu: goto L0076ed7e;
    case 0x0076ed81u: goto L0076ed81;
    case 0x0076ed83u: goto L0076ed83;
    case 0x0076ed84u: goto L0076ed84;
    case 0x0076ed86u: goto L0076ed86;
    case 0x0076ed87u: goto L0076ed87;
    case 0x0076ed90u: goto L0076ed90;
    case 0x0076ed92u: goto L0076ed92;
    case 0x0076ed9cu: goto L0076ed9c;
    case 0x0076ed9eu: goto L0076ed9e;
    case 0x0076eda3u: goto L0076eda3;
    case 0x0076eda6u: goto L0076eda6;
    case 0x0076eda8u: goto L0076eda8;
    case 0x0076edabu: goto L0076edab;
    case 0x0076edadu: goto L0076edad;
    case 0x0076edb4u: goto L0076edb4;
    case 0x0076edc8u: goto L0076edc8;
    case 0x0076edcbu: goto L0076edcb;
    case 0x0076edcdu: goto L0076edcd;
    case 0x0076edd0u: goto L0076edd0;
    case 0x0076edd1u: goto L0076edd1;
    case 0x0076edd4u: goto L0076edd4;
    case 0x0076edd5u: goto L0076edd5;
    case 0x0076edd8u: goto L0076edd8;
    case 0x0076eddau: goto L0076edda;
    case 0x0076eddbu: goto L0076eddb;
    case 0x0076edddu: goto L0076eddd;
    case 0x0076eddeu: goto L0076edde;
    case 0x0076ede8u: goto L0076ede8;
    case 0x0076edebu: goto L0076edeb;
    case 0x0076ededu: goto L0076eded;
    case 0x0076edf0u: goto L0076edf0;
    case 0x0076edf3u: goto L0076edf3;
    case 0x0076edf6u: goto L0076edf6;
    case 0x0076edf9u: goto L0076edf9;
    case 0x0076edfcu: goto L0076edfc;
    case 0x0076edffu: goto L0076edff;
    case 0x0076ee02u: goto L0076ee02;
    case 0x0076ee04u: goto L0076ee04;
    case 0x0076ee05u: goto L0076ee05;
    case 0x0076ee07u: goto L0076ee07;
    case 0x0076ee08u: goto L0076ee08;
    case 0x0076ee10u: goto L0076ee10;
    case 0x0076ee13u: goto L0076ee13;
    case 0x0076ee15u: goto L0076ee15;
    case 0x0076ee18u: goto L0076ee18;
    case 0x0076ee1bu: goto L0076ee1b;
    case 0x0076ee1eu: goto L0076ee1e;
    case 0x0076ee21u: goto L0076ee21;
    case 0x0076ee24u: goto L0076ee24;
    case 0x0076ee27u: goto L0076ee27;
    case 0x0076ee2au: goto L0076ee2a;
    case 0x0076ee2du: goto L0076ee2d;
    case 0x0076ee30u: goto L0076ee30;
    case 0x0076ee36u: goto L0076ee36;
    case 0x0076ee37u: goto L0076ee37;
    case 0x0076ee39u: goto L0076ee39;
    case 0x0076ee3au: goto L0076ee3a;
    case 0x0076ee64u: goto L0076ee64;
    case 0x0076ee68u: goto L0076ee68;
    case 0x0076ee6cu: goto L0076ee6c;
    case 0x0076ee70u: goto L0076ee70;
    case 0x0076ee74u: goto L0076ee74;
    case 0x0076ee78u: goto L0076ee78;
    case 0x0076ee7cu: goto L0076ee7c;
    case 0x0076ee80u: goto L0076ee80;
    case 0x0076ee84u: goto L0076ee84;
    case 0x0076ee88u: goto L0076ee88;
    case 0x0076ee8cu: goto L0076ee8c;
    case 0x0076ee90u: goto L0076ee90;
    case 0x0076ee94u: goto L0076ee94;
    case 0x0076ee98u: goto L0076ee98;
    case 0x0076ee9cu: goto L0076ee9c;
    case 0x0076eea3u: goto L0076eea3;
    case 0x0076eea5u: goto L0076eea5;
    case 0x0076eea7u: goto L0076eea7;
    case 0x0076eec0u: goto L0076eec0;
    case 0x0076eec3u: goto L0076eec3;
    case 0x0076eec4u: goto L0076eec4;
    case 0x0076eec5u: goto L0076eec5;
    case 0x0076eec6u: goto L0076eec6;
    case 0x0076eec8u: goto L0076eec8;
    case 0x0076eecbu: goto L0076eecb;
    case 0x0076eeceu: goto L0076eece;
    case 0x0076eed1u: goto L0076eed1;
    case 0x0076eed2u: goto L0076eed2;
    case 0x0076eed3u: goto L0076eed3;
    case 0x0076eed4u: goto L0076eed4;
    case 0x0076eed8u: goto L0076eed8;
    case 0x0076eedbu: goto L0076eedb;
    case 0x0076eedeu: goto L0076eede;
    case 0x0076eee1u: goto L0076eee1;
    case 0x0076eee4u: goto L0076eee4;
    case 0x0076eee7u: goto L0076eee7;
    case 0x0076eee8u: goto L0076eee8;
    case 0x0076eee9u: goto L0076eee9;
    case 0x0076eeeau: goto L0076eeea;
    case 0x0076eeecu: goto L0076eeec;
    case 0x0076eeefu: goto L0076eeef;
    case 0x0076eef2u: goto L0076eef2;
    case 0x0076eef5u: goto L0076eef5;
    case 0x0076eef8u: goto L0076eef8;
    case 0x0076eefbu: goto L0076eefb;
    case 0x0076eefeu: goto L0076eefe;
    case 0x0076ef01u: goto L0076ef01;
    case 0x0076ef02u: goto L0076ef02;
    case 0x0076ef03u: goto L0076ef03;
    case 0x0076ef04u: goto L0076ef04;
    default:throw std::domain_error("recovery233 unsupported switch destination");}
  }
  L0076ec40: { // 0x76ec40: 23d1 AND EDX,ECX
    s.dx = integer::logical((s.dx)&(s.cx),32,flags);
  }
  L0076ec42: { // 0x76ec42: 8a06 MOV AL,byte ptr [ESI]
    s.ax = with_al(s.ax, m.r8((s.si)));
  }
  L0076ec44: { // 0x76ec44: 8807 MOV byte ptr [EDI],AL
    m.w8((s.di), (s.ax & 0xffu));
  }
  L0076ec46: { // 0x76ec46: 8a4601 MOV AL,byte ptr [ESI + 0x1]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000001u)));
  }
  L0076ec49: { // 0x76ec49: 884701 MOV byte ptr [EDI + 0x1],AL
    m.w8((s.di+0x00000001u), (s.ax & 0xffu));
  }
  L0076ec4c: { // 0x76ec4c: 8a4602 MOV AL,byte ptr [ESI + 0x2]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000002u)));
  }
  L0076ec4f: { // 0x76ec4f: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L0076ec52: { // 0x76ec52: 884702 MOV byte ptr [EDI + 0x2],AL
    m.w8((s.di+0x00000002u), (s.ax & 0xffu));
  }
  L0076ec55: { // 0x76ec55: 83c603 ADD ESI,0x3
    s.si = integer::add(s.si,0x00000003u,32,flags);
  }
  L0076ec58: { // 0x76ec58: 83c703 ADD EDI,0x3
    s.di = integer::add(s.di,0x00000003u,32,flags);
  }
  L0076ec5b: { // 0x76ec5b: 83f908 CMP ECX,0x8
    (void)integer::sub(s.cx,0x00000008u,32,flags);
  }
  L0076ec5e: { // 0x76ec5e: 72cc JC 0x0076ec2c
    if(integer::condition("JC",flags)) goto L0076ec2c;
  }
  L0076ec60: { // 0x76ec60: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L0076ec62: { // 0x76ec62: ff249518ed7600 JMP dword ptr [EDX*0x4 + 0x76ed18]
    switch(m.r32(((s.dx * 0x00000004u)+0x0076ed18u))){
    case 0x0076ebd0u: goto L0076ebd0;
    case 0x0076ebd1u: goto L0076ebd1;
    case 0x0076ebd3u: goto L0076ebd3;
    case 0x0076ebd4u: goto L0076ebd4;
    case 0x0076ebd5u: goto L0076ebd5;
    case 0x0076ebd8u: goto L0076ebd8;
    case 0x0076ebdbu: goto L0076ebdb;
    case 0x0076ebdeu: goto L0076ebde;
    case 0x0076ebe0u: goto L0076ebe0;
    case 0x0076ebe2u: goto L0076ebe2;
    case 0x0076ebe4u: goto L0076ebe4;
    case 0x0076ebe6u: goto L0076ebe6;
    case 0x0076ebe8u: goto L0076ebe8;
    case 0x0076ebeau: goto L0076ebea;
    case 0x0076ebf0u: goto L0076ebf0;
    case 0x0076ebf6u: goto L0076ebf6;
    case 0x0076ebf8u: goto L0076ebf8;
    case 0x0076ebfbu: goto L0076ebfb;
    case 0x0076ebfeu: goto L0076ebfe;
    case 0x0076ec01u: goto L0076ec01;
    case 0x0076ec03u: goto L0076ec03;
    case 0x0076ec05u: goto L0076ec05;
    case 0x0076ec0cu: goto L0076ec0c;
    case 0x0076ec0eu: goto L0076ec0e;
    case 0x0076ec13u: goto L0076ec13;
    case 0x0076ec16u: goto L0076ec16;
    case 0x0076ec18u: goto L0076ec18;
    case 0x0076ec1bu: goto L0076ec1b;
    case 0x0076ec1du: goto L0076ec1d;
    case 0x0076ec24u: goto L0076ec24;
    case 0x0076ec2cu: goto L0076ec2c;
    case 0x0076ec40u: goto L0076ec40;
    case 0x0076ec42u: goto L0076ec42;
    case 0x0076ec44u: goto L0076ec44;
    case 0x0076ec46u: goto L0076ec46;
    case 0x0076ec49u: goto L0076ec49;
    case 0x0076ec4cu: goto L0076ec4c;
    case 0x0076ec4fu: goto L0076ec4f;
    case 0x0076ec52u: goto L0076ec52;
    case 0x0076ec55u: goto L0076ec55;
    case 0x0076ec58u: goto L0076ec58;
    case 0x0076ec5bu: goto L0076ec5b;
    case 0x0076ec5eu: goto L0076ec5e;
    case 0x0076ec60u: goto L0076ec60;
    case 0x0076ec62u: goto L0076ec62;
    case 0x0076ec6cu: goto L0076ec6c;
    case 0x0076ec6eu: goto L0076ec6e;
    case 0x0076ec70u: goto L0076ec70;
    case 0x0076ec72u: goto L0076ec72;
    case 0x0076ec75u: goto L0076ec75;
    case 0x0076ec78u: goto L0076ec78;
    case 0x0076ec7bu: goto L0076ec7b;
    case 0x0076ec7eu: goto L0076ec7e;
    case 0x0076ec81u: goto L0076ec81;
    case 0x0076ec84u: goto L0076ec84;
    case 0x0076ec86u: goto L0076ec86;
    case 0x0076ec88u: goto L0076ec88;
    case 0x0076ec90u: goto L0076ec90;
    case 0x0076ec92u: goto L0076ec92;
    case 0x0076ec94u: goto L0076ec94;
    case 0x0076ec96u: goto L0076ec96;
    case 0x0076ec97u: goto L0076ec97;
    case 0x0076ec9au: goto L0076ec9a;
    case 0x0076ec9bu: goto L0076ec9b;
    case 0x0076ec9eu: goto L0076ec9e;
    case 0x0076eca0u: goto L0076eca0;
    case 0x0076eca2u: goto L0076eca2;
    case 0x0076ecccu: goto L0076eccc;
    case 0x0076ecd0u: goto L0076ecd0;
    case 0x0076ecd4u: goto L0076ecd4;
    case 0x0076ecd8u: goto L0076ecd8;
    case 0x0076ecdcu: goto L0076ecdc;
    case 0x0076ece0u: goto L0076ece0;
    case 0x0076ece4u: goto L0076ece4;
    case 0x0076ece8u: goto L0076ece8;
    case 0x0076ececu: goto L0076ecec;
    case 0x0076ecf0u: goto L0076ecf0;
    case 0x0076ecf4u: goto L0076ecf4;
    case 0x0076ecf8u: goto L0076ecf8;
    case 0x0076ecfcu: goto L0076ecfc;
    case 0x0076ed00u: goto L0076ed00;
    case 0x0076ed04u: goto L0076ed04;
    case 0x0076ed0bu: goto L0076ed0b;
    case 0x0076ed0du: goto L0076ed0d;
    case 0x0076ed0fu: goto L0076ed0f;
    case 0x0076ed28u: goto L0076ed28;
    case 0x0076ed2bu: goto L0076ed2b;
    case 0x0076ed2cu: goto L0076ed2c;
    case 0x0076ed2du: goto L0076ed2d;
    case 0x0076ed2eu: goto L0076ed2e;
    case 0x0076ed30u: goto L0076ed30;
    case 0x0076ed32u: goto L0076ed32;
    case 0x0076ed34u: goto L0076ed34;
    case 0x0076ed37u: goto L0076ed37;
    case 0x0076ed38u: goto L0076ed38;
    case 0x0076ed39u: goto L0076ed39;
    case 0x0076ed3au: goto L0076ed3a;
    case 0x0076ed3cu: goto L0076ed3c;
    case 0x0076ed3eu: goto L0076ed3e;
    case 0x0076ed40u: goto L0076ed40;
    case 0x0076ed43u: goto L0076ed43;
    case 0x0076ed46u: goto L0076ed46;
    case 0x0076ed49u: goto L0076ed49;
    case 0x0076ed4au: goto L0076ed4a;
    case 0x0076ed4bu: goto L0076ed4b;
    case 0x0076ed4cu: goto L0076ed4c;
    case 0x0076ed50u: goto L0076ed50;
    case 0x0076ed52u: goto L0076ed52;
    case 0x0076ed54u: goto L0076ed54;
    case 0x0076ed57u: goto L0076ed57;
    case 0x0076ed5au: goto L0076ed5a;
    case 0x0076ed5du: goto L0076ed5d;
    case 0x0076ed60u: goto L0076ed60;
    case 0x0076ed63u: goto L0076ed63;
    case 0x0076ed64u: goto L0076ed64;
    case 0x0076ed65u: goto L0076ed65;
    case 0x0076ed66u: goto L0076ed66;
    case 0x0076ed68u: goto L0076ed68;
    case 0x0076ed6cu: goto L0076ed6c;
    case 0x0076ed70u: goto L0076ed70;
    case 0x0076ed76u: goto L0076ed76;
    case 0x0076ed78u: goto L0076ed78;
    case 0x0076ed7bu: goto L0076ed7b;
    case 0x0076ed7eu: goto L0076ed7e;
    case 0x0076ed81u: goto L0076ed81;
    case 0x0076ed83u: goto L0076ed83;
    case 0x0076ed84u: goto L0076ed84;
    case 0x0076ed86u: goto L0076ed86;
    case 0x0076ed87u: goto L0076ed87;
    case 0x0076ed90u: goto L0076ed90;
    case 0x0076ed92u: goto L0076ed92;
    case 0x0076ed9cu: goto L0076ed9c;
    case 0x0076ed9eu: goto L0076ed9e;
    case 0x0076eda3u: goto L0076eda3;
    case 0x0076eda6u: goto L0076eda6;
    case 0x0076eda8u: goto L0076eda8;
    case 0x0076edabu: goto L0076edab;
    case 0x0076edadu: goto L0076edad;
    case 0x0076edb4u: goto L0076edb4;
    case 0x0076edc8u: goto L0076edc8;
    case 0x0076edcbu: goto L0076edcb;
    case 0x0076edcdu: goto L0076edcd;
    case 0x0076edd0u: goto L0076edd0;
    case 0x0076edd1u: goto L0076edd1;
    case 0x0076edd4u: goto L0076edd4;
    case 0x0076edd5u: goto L0076edd5;
    case 0x0076edd8u: goto L0076edd8;
    case 0x0076eddau: goto L0076edda;
    case 0x0076eddbu: goto L0076eddb;
    case 0x0076edddu: goto L0076eddd;
    case 0x0076eddeu: goto L0076edde;
    case 0x0076ede8u: goto L0076ede8;
    case 0x0076edebu: goto L0076edeb;
    case 0x0076ededu: goto L0076eded;
    case 0x0076edf0u: goto L0076edf0;
    case 0x0076edf3u: goto L0076edf3;
    case 0x0076edf6u: goto L0076edf6;
    case 0x0076edf9u: goto L0076edf9;
    case 0x0076edfcu: goto L0076edfc;
    case 0x0076edffu: goto L0076edff;
    case 0x0076ee02u: goto L0076ee02;
    case 0x0076ee04u: goto L0076ee04;
    case 0x0076ee05u: goto L0076ee05;
    case 0x0076ee07u: goto L0076ee07;
    case 0x0076ee08u: goto L0076ee08;
    case 0x0076ee10u: goto L0076ee10;
    case 0x0076ee13u: goto L0076ee13;
    case 0x0076ee15u: goto L0076ee15;
    case 0x0076ee18u: goto L0076ee18;
    case 0x0076ee1bu: goto L0076ee1b;
    case 0x0076ee1eu: goto L0076ee1e;
    case 0x0076ee21u: goto L0076ee21;
    case 0x0076ee24u: goto L0076ee24;
    case 0x0076ee27u: goto L0076ee27;
    case 0x0076ee2au: goto L0076ee2a;
    case 0x0076ee2du: goto L0076ee2d;
    case 0x0076ee30u: goto L0076ee30;
    case 0x0076ee36u: goto L0076ee36;
    case 0x0076ee37u: goto L0076ee37;
    case 0x0076ee39u: goto L0076ee39;
    case 0x0076ee3au: goto L0076ee3a;
    case 0x0076ee64u: goto L0076ee64;
    case 0x0076ee68u: goto L0076ee68;
    case 0x0076ee6cu: goto L0076ee6c;
    case 0x0076ee70u: goto L0076ee70;
    case 0x0076ee74u: goto L0076ee74;
    case 0x0076ee78u: goto L0076ee78;
    case 0x0076ee7cu: goto L0076ee7c;
    case 0x0076ee80u: goto L0076ee80;
    case 0x0076ee84u: goto L0076ee84;
    case 0x0076ee88u: goto L0076ee88;
    case 0x0076ee8cu: goto L0076ee8c;
    case 0x0076ee90u: goto L0076ee90;
    case 0x0076ee94u: goto L0076ee94;
    case 0x0076ee98u: goto L0076ee98;
    case 0x0076ee9cu: goto L0076ee9c;
    case 0x0076eea3u: goto L0076eea3;
    case 0x0076eea5u: goto L0076eea5;
    case 0x0076eea7u: goto L0076eea7;
    case 0x0076eec0u: goto L0076eec0;
    case 0x0076eec3u: goto L0076eec3;
    case 0x0076eec4u: goto L0076eec4;
    case 0x0076eec5u: goto L0076eec5;
    case 0x0076eec6u: goto L0076eec6;
    case 0x0076eec8u: goto L0076eec8;
    case 0x0076eecbu: goto L0076eecb;
    case 0x0076eeceu: goto L0076eece;
    case 0x0076eed1u: goto L0076eed1;
    case 0x0076eed2u: goto L0076eed2;
    case 0x0076eed3u: goto L0076eed3;
    case 0x0076eed4u: goto L0076eed4;
    case 0x0076eed8u: goto L0076eed8;
    case 0x0076eedbu: goto L0076eedb;
    case 0x0076eedeu: goto L0076eede;
    case 0x0076eee1u: goto L0076eee1;
    case 0x0076eee4u: goto L0076eee4;
    case 0x0076eee7u: goto L0076eee7;
    case 0x0076eee8u: goto L0076eee8;
    case 0x0076eee9u: goto L0076eee9;
    case 0x0076eeeau: goto L0076eeea;
    case 0x0076eeecu: goto L0076eeec;
    case 0x0076eeefu: goto L0076eeef;
    case 0x0076eef2u: goto L0076eef2;
    case 0x0076eef5u: goto L0076eef5;
    case 0x0076eef8u: goto L0076eef8;
    case 0x0076eefbu: goto L0076eefb;
    case 0x0076eefeu: goto L0076eefe;
    case 0x0076ef01u: goto L0076ef01;
    case 0x0076ef02u: goto L0076ef02;
    case 0x0076ef03u: goto L0076ef03;
    case 0x0076ef04u: goto L0076ef04;
    default:throw std::domain_error("recovery233 unsupported switch destination");}
  }
  L0076ec6c: { // 0x76ec6c: 23d1 AND EDX,ECX
    s.dx = integer::logical((s.dx)&(s.cx),32,flags);
  }
  L0076ec6e: { // 0x76ec6e: 8a06 MOV AL,byte ptr [ESI]
    s.ax = with_al(s.ax, m.r8((s.si)));
  }
  L0076ec70: { // 0x76ec70: 8807 MOV byte ptr [EDI],AL
    m.w8((s.di), (s.ax & 0xffu));
  }
  L0076ec72: { // 0x76ec72: 8a4601 MOV AL,byte ptr [ESI + 0x1]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000001u)));
  }
  L0076ec75: { // 0x76ec75: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L0076ec78: { // 0x76ec78: 884701 MOV byte ptr [EDI + 0x1],AL
    m.w8((s.di+0x00000001u), (s.ax & 0xffu));
  }
  L0076ec7b: { // 0x76ec7b: 83c602 ADD ESI,0x2
    s.si = integer::add(s.si,0x00000002u,32,flags);
  }
  L0076ec7e: { // 0x76ec7e: 83c702 ADD EDI,0x2
    s.di = integer::add(s.di,0x00000002u,32,flags);
  }
  L0076ec81: { // 0x76ec81: 83f908 CMP ECX,0x8
    (void)integer::sub(s.cx,0x00000008u,32,flags);
  }
  L0076ec84: { // 0x76ec84: 72a6 JC 0x0076ec2c
    if(integer::condition("JC",flags)) goto L0076ec2c;
  }
  L0076ec86: { // 0x76ec86: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L0076ec88: { // 0x76ec88: ff249518ed7600 JMP dword ptr [EDX*0x4 + 0x76ed18]
    switch(m.r32(((s.dx * 0x00000004u)+0x0076ed18u))){
    case 0x0076ebd0u: goto L0076ebd0;
    case 0x0076ebd1u: goto L0076ebd1;
    case 0x0076ebd3u: goto L0076ebd3;
    case 0x0076ebd4u: goto L0076ebd4;
    case 0x0076ebd5u: goto L0076ebd5;
    case 0x0076ebd8u: goto L0076ebd8;
    case 0x0076ebdbu: goto L0076ebdb;
    case 0x0076ebdeu: goto L0076ebde;
    case 0x0076ebe0u: goto L0076ebe0;
    case 0x0076ebe2u: goto L0076ebe2;
    case 0x0076ebe4u: goto L0076ebe4;
    case 0x0076ebe6u: goto L0076ebe6;
    case 0x0076ebe8u: goto L0076ebe8;
    case 0x0076ebeau: goto L0076ebea;
    case 0x0076ebf0u: goto L0076ebf0;
    case 0x0076ebf6u: goto L0076ebf6;
    case 0x0076ebf8u: goto L0076ebf8;
    case 0x0076ebfbu: goto L0076ebfb;
    case 0x0076ebfeu: goto L0076ebfe;
    case 0x0076ec01u: goto L0076ec01;
    case 0x0076ec03u: goto L0076ec03;
    case 0x0076ec05u: goto L0076ec05;
    case 0x0076ec0cu: goto L0076ec0c;
    case 0x0076ec0eu: goto L0076ec0e;
    case 0x0076ec13u: goto L0076ec13;
    case 0x0076ec16u: goto L0076ec16;
    case 0x0076ec18u: goto L0076ec18;
    case 0x0076ec1bu: goto L0076ec1b;
    case 0x0076ec1du: goto L0076ec1d;
    case 0x0076ec24u: goto L0076ec24;
    case 0x0076ec2cu: goto L0076ec2c;
    case 0x0076ec40u: goto L0076ec40;
    case 0x0076ec42u: goto L0076ec42;
    case 0x0076ec44u: goto L0076ec44;
    case 0x0076ec46u: goto L0076ec46;
    case 0x0076ec49u: goto L0076ec49;
    case 0x0076ec4cu: goto L0076ec4c;
    case 0x0076ec4fu: goto L0076ec4f;
    case 0x0076ec52u: goto L0076ec52;
    case 0x0076ec55u: goto L0076ec55;
    case 0x0076ec58u: goto L0076ec58;
    case 0x0076ec5bu: goto L0076ec5b;
    case 0x0076ec5eu: goto L0076ec5e;
    case 0x0076ec60u: goto L0076ec60;
    case 0x0076ec62u: goto L0076ec62;
    case 0x0076ec6cu: goto L0076ec6c;
    case 0x0076ec6eu: goto L0076ec6e;
    case 0x0076ec70u: goto L0076ec70;
    case 0x0076ec72u: goto L0076ec72;
    case 0x0076ec75u: goto L0076ec75;
    case 0x0076ec78u: goto L0076ec78;
    case 0x0076ec7bu: goto L0076ec7b;
    case 0x0076ec7eu: goto L0076ec7e;
    case 0x0076ec81u: goto L0076ec81;
    case 0x0076ec84u: goto L0076ec84;
    case 0x0076ec86u: goto L0076ec86;
    case 0x0076ec88u: goto L0076ec88;
    case 0x0076ec90u: goto L0076ec90;
    case 0x0076ec92u: goto L0076ec92;
    case 0x0076ec94u: goto L0076ec94;
    case 0x0076ec96u: goto L0076ec96;
    case 0x0076ec97u: goto L0076ec97;
    case 0x0076ec9au: goto L0076ec9a;
    case 0x0076ec9bu: goto L0076ec9b;
    case 0x0076ec9eu: goto L0076ec9e;
    case 0x0076eca0u: goto L0076eca0;
    case 0x0076eca2u: goto L0076eca2;
    case 0x0076ecccu: goto L0076eccc;
    case 0x0076ecd0u: goto L0076ecd0;
    case 0x0076ecd4u: goto L0076ecd4;
    case 0x0076ecd8u: goto L0076ecd8;
    case 0x0076ecdcu: goto L0076ecdc;
    case 0x0076ece0u: goto L0076ece0;
    case 0x0076ece4u: goto L0076ece4;
    case 0x0076ece8u: goto L0076ece8;
    case 0x0076ececu: goto L0076ecec;
    case 0x0076ecf0u: goto L0076ecf0;
    case 0x0076ecf4u: goto L0076ecf4;
    case 0x0076ecf8u: goto L0076ecf8;
    case 0x0076ecfcu: goto L0076ecfc;
    case 0x0076ed00u: goto L0076ed00;
    case 0x0076ed04u: goto L0076ed04;
    case 0x0076ed0bu: goto L0076ed0b;
    case 0x0076ed0du: goto L0076ed0d;
    case 0x0076ed0fu: goto L0076ed0f;
    case 0x0076ed28u: goto L0076ed28;
    case 0x0076ed2bu: goto L0076ed2b;
    case 0x0076ed2cu: goto L0076ed2c;
    case 0x0076ed2du: goto L0076ed2d;
    case 0x0076ed2eu: goto L0076ed2e;
    case 0x0076ed30u: goto L0076ed30;
    case 0x0076ed32u: goto L0076ed32;
    case 0x0076ed34u: goto L0076ed34;
    case 0x0076ed37u: goto L0076ed37;
    case 0x0076ed38u: goto L0076ed38;
    case 0x0076ed39u: goto L0076ed39;
    case 0x0076ed3au: goto L0076ed3a;
    case 0x0076ed3cu: goto L0076ed3c;
    case 0x0076ed3eu: goto L0076ed3e;
    case 0x0076ed40u: goto L0076ed40;
    case 0x0076ed43u: goto L0076ed43;
    case 0x0076ed46u: goto L0076ed46;
    case 0x0076ed49u: goto L0076ed49;
    case 0x0076ed4au: goto L0076ed4a;
    case 0x0076ed4bu: goto L0076ed4b;
    case 0x0076ed4cu: goto L0076ed4c;
    case 0x0076ed50u: goto L0076ed50;
    case 0x0076ed52u: goto L0076ed52;
    case 0x0076ed54u: goto L0076ed54;
    case 0x0076ed57u: goto L0076ed57;
    case 0x0076ed5au: goto L0076ed5a;
    case 0x0076ed5du: goto L0076ed5d;
    case 0x0076ed60u: goto L0076ed60;
    case 0x0076ed63u: goto L0076ed63;
    case 0x0076ed64u: goto L0076ed64;
    case 0x0076ed65u: goto L0076ed65;
    case 0x0076ed66u: goto L0076ed66;
    case 0x0076ed68u: goto L0076ed68;
    case 0x0076ed6cu: goto L0076ed6c;
    case 0x0076ed70u: goto L0076ed70;
    case 0x0076ed76u: goto L0076ed76;
    case 0x0076ed78u: goto L0076ed78;
    case 0x0076ed7bu: goto L0076ed7b;
    case 0x0076ed7eu: goto L0076ed7e;
    case 0x0076ed81u: goto L0076ed81;
    case 0x0076ed83u: goto L0076ed83;
    case 0x0076ed84u: goto L0076ed84;
    case 0x0076ed86u: goto L0076ed86;
    case 0x0076ed87u: goto L0076ed87;
    case 0x0076ed90u: goto L0076ed90;
    case 0x0076ed92u: goto L0076ed92;
    case 0x0076ed9cu: goto L0076ed9c;
    case 0x0076ed9eu: goto L0076ed9e;
    case 0x0076eda3u: goto L0076eda3;
    case 0x0076eda6u: goto L0076eda6;
    case 0x0076eda8u: goto L0076eda8;
    case 0x0076edabu: goto L0076edab;
    case 0x0076edadu: goto L0076edad;
    case 0x0076edb4u: goto L0076edb4;
    case 0x0076edc8u: goto L0076edc8;
    case 0x0076edcbu: goto L0076edcb;
    case 0x0076edcdu: goto L0076edcd;
    case 0x0076edd0u: goto L0076edd0;
    case 0x0076edd1u: goto L0076edd1;
    case 0x0076edd4u: goto L0076edd4;
    case 0x0076edd5u: goto L0076edd5;
    case 0x0076edd8u: goto L0076edd8;
    case 0x0076eddau: goto L0076edda;
    case 0x0076eddbu: goto L0076eddb;
    case 0x0076edddu: goto L0076eddd;
    case 0x0076eddeu: goto L0076edde;
    case 0x0076ede8u: goto L0076ede8;
    case 0x0076edebu: goto L0076edeb;
    case 0x0076ededu: goto L0076eded;
    case 0x0076edf0u: goto L0076edf0;
    case 0x0076edf3u: goto L0076edf3;
    case 0x0076edf6u: goto L0076edf6;
    case 0x0076edf9u: goto L0076edf9;
    case 0x0076edfcu: goto L0076edfc;
    case 0x0076edffu: goto L0076edff;
    case 0x0076ee02u: goto L0076ee02;
    case 0x0076ee04u: goto L0076ee04;
    case 0x0076ee05u: goto L0076ee05;
    case 0x0076ee07u: goto L0076ee07;
    case 0x0076ee08u: goto L0076ee08;
    case 0x0076ee10u: goto L0076ee10;
    case 0x0076ee13u: goto L0076ee13;
    case 0x0076ee15u: goto L0076ee15;
    case 0x0076ee18u: goto L0076ee18;
    case 0x0076ee1bu: goto L0076ee1b;
    case 0x0076ee1eu: goto L0076ee1e;
    case 0x0076ee21u: goto L0076ee21;
    case 0x0076ee24u: goto L0076ee24;
    case 0x0076ee27u: goto L0076ee27;
    case 0x0076ee2au: goto L0076ee2a;
    case 0x0076ee2du: goto L0076ee2d;
    case 0x0076ee30u: goto L0076ee30;
    case 0x0076ee36u: goto L0076ee36;
    case 0x0076ee37u: goto L0076ee37;
    case 0x0076ee39u: goto L0076ee39;
    case 0x0076ee3au: goto L0076ee3a;
    case 0x0076ee64u: goto L0076ee64;
    case 0x0076ee68u: goto L0076ee68;
    case 0x0076ee6cu: goto L0076ee6c;
    case 0x0076ee70u: goto L0076ee70;
    case 0x0076ee74u: goto L0076ee74;
    case 0x0076ee78u: goto L0076ee78;
    case 0x0076ee7cu: goto L0076ee7c;
    case 0x0076ee80u: goto L0076ee80;
    case 0x0076ee84u: goto L0076ee84;
    case 0x0076ee88u: goto L0076ee88;
    case 0x0076ee8cu: goto L0076ee8c;
    case 0x0076ee90u: goto L0076ee90;
    case 0x0076ee94u: goto L0076ee94;
    case 0x0076ee98u: goto L0076ee98;
    case 0x0076ee9cu: goto L0076ee9c;
    case 0x0076eea3u: goto L0076eea3;
    case 0x0076eea5u: goto L0076eea5;
    case 0x0076eea7u: goto L0076eea7;
    case 0x0076eec0u: goto L0076eec0;
    case 0x0076eec3u: goto L0076eec3;
    case 0x0076eec4u: goto L0076eec4;
    case 0x0076eec5u: goto L0076eec5;
    case 0x0076eec6u: goto L0076eec6;
    case 0x0076eec8u: goto L0076eec8;
    case 0x0076eecbu: goto L0076eecb;
    case 0x0076eeceu: goto L0076eece;
    case 0x0076eed1u: goto L0076eed1;
    case 0x0076eed2u: goto L0076eed2;
    case 0x0076eed3u: goto L0076eed3;
    case 0x0076eed4u: goto L0076eed4;
    case 0x0076eed8u: goto L0076eed8;
    case 0x0076eedbu: goto L0076eedb;
    case 0x0076eedeu: goto L0076eede;
    case 0x0076eee1u: goto L0076eee1;
    case 0x0076eee4u: goto L0076eee4;
    case 0x0076eee7u: goto L0076eee7;
    case 0x0076eee8u: goto L0076eee8;
    case 0x0076eee9u: goto L0076eee9;
    case 0x0076eeeau: goto L0076eeea;
    case 0x0076eeecu: goto L0076eeec;
    case 0x0076eeefu: goto L0076eeef;
    case 0x0076eef2u: goto L0076eef2;
    case 0x0076eef5u: goto L0076eef5;
    case 0x0076eef8u: goto L0076eef8;
    case 0x0076eefbu: goto L0076eefb;
    case 0x0076eefeu: goto L0076eefe;
    case 0x0076ef01u: goto L0076ef01;
    case 0x0076ef02u: goto L0076ef02;
    case 0x0076ef03u: goto L0076ef03;
    case 0x0076ef04u: goto L0076ef04;
    default:throw std::domain_error("recovery233 unsupported switch destination");}
  }
  L0076ec90: { // 0x76ec90: 23d1 AND EDX,ECX
    s.dx = integer::logical((s.dx)&(s.cx),32,flags);
  }
  L0076ec92: { // 0x76ec92: 8a06 MOV AL,byte ptr [ESI]
    s.ax = with_al(s.ax, m.r8((s.si)));
  }
  L0076ec94: { // 0x76ec94: 8807 MOV byte ptr [EDI],AL
    m.w8((s.di), (s.ax & 0xffu));
  }
  L0076ec96: { // 0x76ec96: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0076ec97: { // 0x76ec97: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L0076ec9a: { // 0x76ec9a: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0076ec9b: { // 0x76ec9b: 83f908 CMP ECX,0x8
    (void)integer::sub(s.cx,0x00000008u,32,flags);
  }
  L0076ec9e: { // 0x76ec9e: 728c JC 0x0076ec2c
    if(integer::condition("JC",flags)) goto L0076ec2c;
  }
  L0076eca0: { // 0x76eca0: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L0076eca2: { // 0x76eca2: ff249518ed7600 JMP dword ptr [EDX*0x4 + 0x76ed18]
    switch(m.r32(((s.dx * 0x00000004u)+0x0076ed18u))){
    case 0x0076ebd0u: goto L0076ebd0;
    case 0x0076ebd1u: goto L0076ebd1;
    case 0x0076ebd3u: goto L0076ebd3;
    case 0x0076ebd4u: goto L0076ebd4;
    case 0x0076ebd5u: goto L0076ebd5;
    case 0x0076ebd8u: goto L0076ebd8;
    case 0x0076ebdbu: goto L0076ebdb;
    case 0x0076ebdeu: goto L0076ebde;
    case 0x0076ebe0u: goto L0076ebe0;
    case 0x0076ebe2u: goto L0076ebe2;
    case 0x0076ebe4u: goto L0076ebe4;
    case 0x0076ebe6u: goto L0076ebe6;
    case 0x0076ebe8u: goto L0076ebe8;
    case 0x0076ebeau: goto L0076ebea;
    case 0x0076ebf0u: goto L0076ebf0;
    case 0x0076ebf6u: goto L0076ebf6;
    case 0x0076ebf8u: goto L0076ebf8;
    case 0x0076ebfbu: goto L0076ebfb;
    case 0x0076ebfeu: goto L0076ebfe;
    case 0x0076ec01u: goto L0076ec01;
    case 0x0076ec03u: goto L0076ec03;
    case 0x0076ec05u: goto L0076ec05;
    case 0x0076ec0cu: goto L0076ec0c;
    case 0x0076ec0eu: goto L0076ec0e;
    case 0x0076ec13u: goto L0076ec13;
    case 0x0076ec16u: goto L0076ec16;
    case 0x0076ec18u: goto L0076ec18;
    case 0x0076ec1bu: goto L0076ec1b;
    case 0x0076ec1du: goto L0076ec1d;
    case 0x0076ec24u: goto L0076ec24;
    case 0x0076ec2cu: goto L0076ec2c;
    case 0x0076ec40u: goto L0076ec40;
    case 0x0076ec42u: goto L0076ec42;
    case 0x0076ec44u: goto L0076ec44;
    case 0x0076ec46u: goto L0076ec46;
    case 0x0076ec49u: goto L0076ec49;
    case 0x0076ec4cu: goto L0076ec4c;
    case 0x0076ec4fu: goto L0076ec4f;
    case 0x0076ec52u: goto L0076ec52;
    case 0x0076ec55u: goto L0076ec55;
    case 0x0076ec58u: goto L0076ec58;
    case 0x0076ec5bu: goto L0076ec5b;
    case 0x0076ec5eu: goto L0076ec5e;
    case 0x0076ec60u: goto L0076ec60;
    case 0x0076ec62u: goto L0076ec62;
    case 0x0076ec6cu: goto L0076ec6c;
    case 0x0076ec6eu: goto L0076ec6e;
    case 0x0076ec70u: goto L0076ec70;
    case 0x0076ec72u: goto L0076ec72;
    case 0x0076ec75u: goto L0076ec75;
    case 0x0076ec78u: goto L0076ec78;
    case 0x0076ec7bu: goto L0076ec7b;
    case 0x0076ec7eu: goto L0076ec7e;
    case 0x0076ec81u: goto L0076ec81;
    case 0x0076ec84u: goto L0076ec84;
    case 0x0076ec86u: goto L0076ec86;
    case 0x0076ec88u: goto L0076ec88;
    case 0x0076ec90u: goto L0076ec90;
    case 0x0076ec92u: goto L0076ec92;
    case 0x0076ec94u: goto L0076ec94;
    case 0x0076ec96u: goto L0076ec96;
    case 0x0076ec97u: goto L0076ec97;
    case 0x0076ec9au: goto L0076ec9a;
    case 0x0076ec9bu: goto L0076ec9b;
    case 0x0076ec9eu: goto L0076ec9e;
    case 0x0076eca0u: goto L0076eca0;
    case 0x0076eca2u: goto L0076eca2;
    case 0x0076ecccu: goto L0076eccc;
    case 0x0076ecd0u: goto L0076ecd0;
    case 0x0076ecd4u: goto L0076ecd4;
    case 0x0076ecd8u: goto L0076ecd8;
    case 0x0076ecdcu: goto L0076ecdc;
    case 0x0076ece0u: goto L0076ece0;
    case 0x0076ece4u: goto L0076ece4;
    case 0x0076ece8u: goto L0076ece8;
    case 0x0076ececu: goto L0076ecec;
    case 0x0076ecf0u: goto L0076ecf0;
    case 0x0076ecf4u: goto L0076ecf4;
    case 0x0076ecf8u: goto L0076ecf8;
    case 0x0076ecfcu: goto L0076ecfc;
    case 0x0076ed00u: goto L0076ed00;
    case 0x0076ed04u: goto L0076ed04;
    case 0x0076ed0bu: goto L0076ed0b;
    case 0x0076ed0du: goto L0076ed0d;
    case 0x0076ed0fu: goto L0076ed0f;
    case 0x0076ed28u: goto L0076ed28;
    case 0x0076ed2bu: goto L0076ed2b;
    case 0x0076ed2cu: goto L0076ed2c;
    case 0x0076ed2du: goto L0076ed2d;
    case 0x0076ed2eu: goto L0076ed2e;
    case 0x0076ed30u: goto L0076ed30;
    case 0x0076ed32u: goto L0076ed32;
    case 0x0076ed34u: goto L0076ed34;
    case 0x0076ed37u: goto L0076ed37;
    case 0x0076ed38u: goto L0076ed38;
    case 0x0076ed39u: goto L0076ed39;
    case 0x0076ed3au: goto L0076ed3a;
    case 0x0076ed3cu: goto L0076ed3c;
    case 0x0076ed3eu: goto L0076ed3e;
    case 0x0076ed40u: goto L0076ed40;
    case 0x0076ed43u: goto L0076ed43;
    case 0x0076ed46u: goto L0076ed46;
    case 0x0076ed49u: goto L0076ed49;
    case 0x0076ed4au: goto L0076ed4a;
    case 0x0076ed4bu: goto L0076ed4b;
    case 0x0076ed4cu: goto L0076ed4c;
    case 0x0076ed50u: goto L0076ed50;
    case 0x0076ed52u: goto L0076ed52;
    case 0x0076ed54u: goto L0076ed54;
    case 0x0076ed57u: goto L0076ed57;
    case 0x0076ed5au: goto L0076ed5a;
    case 0x0076ed5du: goto L0076ed5d;
    case 0x0076ed60u: goto L0076ed60;
    case 0x0076ed63u: goto L0076ed63;
    case 0x0076ed64u: goto L0076ed64;
    case 0x0076ed65u: goto L0076ed65;
    case 0x0076ed66u: goto L0076ed66;
    case 0x0076ed68u: goto L0076ed68;
    case 0x0076ed6cu: goto L0076ed6c;
    case 0x0076ed70u: goto L0076ed70;
    case 0x0076ed76u: goto L0076ed76;
    case 0x0076ed78u: goto L0076ed78;
    case 0x0076ed7bu: goto L0076ed7b;
    case 0x0076ed7eu: goto L0076ed7e;
    case 0x0076ed81u: goto L0076ed81;
    case 0x0076ed83u: goto L0076ed83;
    case 0x0076ed84u: goto L0076ed84;
    case 0x0076ed86u: goto L0076ed86;
    case 0x0076ed87u: goto L0076ed87;
    case 0x0076ed90u: goto L0076ed90;
    case 0x0076ed92u: goto L0076ed92;
    case 0x0076ed9cu: goto L0076ed9c;
    case 0x0076ed9eu: goto L0076ed9e;
    case 0x0076eda3u: goto L0076eda3;
    case 0x0076eda6u: goto L0076eda6;
    case 0x0076eda8u: goto L0076eda8;
    case 0x0076edabu: goto L0076edab;
    case 0x0076edadu: goto L0076edad;
    case 0x0076edb4u: goto L0076edb4;
    case 0x0076edc8u: goto L0076edc8;
    case 0x0076edcbu: goto L0076edcb;
    case 0x0076edcdu: goto L0076edcd;
    case 0x0076edd0u: goto L0076edd0;
    case 0x0076edd1u: goto L0076edd1;
    case 0x0076edd4u: goto L0076edd4;
    case 0x0076edd5u: goto L0076edd5;
    case 0x0076edd8u: goto L0076edd8;
    case 0x0076eddau: goto L0076edda;
    case 0x0076eddbu: goto L0076eddb;
    case 0x0076edddu: goto L0076eddd;
    case 0x0076eddeu: goto L0076edde;
    case 0x0076ede8u: goto L0076ede8;
    case 0x0076edebu: goto L0076edeb;
    case 0x0076ededu: goto L0076eded;
    case 0x0076edf0u: goto L0076edf0;
    case 0x0076edf3u: goto L0076edf3;
    case 0x0076edf6u: goto L0076edf6;
    case 0x0076edf9u: goto L0076edf9;
    case 0x0076edfcu: goto L0076edfc;
    case 0x0076edffu: goto L0076edff;
    case 0x0076ee02u: goto L0076ee02;
    case 0x0076ee04u: goto L0076ee04;
    case 0x0076ee05u: goto L0076ee05;
    case 0x0076ee07u: goto L0076ee07;
    case 0x0076ee08u: goto L0076ee08;
    case 0x0076ee10u: goto L0076ee10;
    case 0x0076ee13u: goto L0076ee13;
    case 0x0076ee15u: goto L0076ee15;
    case 0x0076ee18u: goto L0076ee18;
    case 0x0076ee1bu: goto L0076ee1b;
    case 0x0076ee1eu: goto L0076ee1e;
    case 0x0076ee21u: goto L0076ee21;
    case 0x0076ee24u: goto L0076ee24;
    case 0x0076ee27u: goto L0076ee27;
    case 0x0076ee2au: goto L0076ee2a;
    case 0x0076ee2du: goto L0076ee2d;
    case 0x0076ee30u: goto L0076ee30;
    case 0x0076ee36u: goto L0076ee36;
    case 0x0076ee37u: goto L0076ee37;
    case 0x0076ee39u: goto L0076ee39;
    case 0x0076ee3au: goto L0076ee3a;
    case 0x0076ee64u: goto L0076ee64;
    case 0x0076ee68u: goto L0076ee68;
    case 0x0076ee6cu: goto L0076ee6c;
    case 0x0076ee70u: goto L0076ee70;
    case 0x0076ee74u: goto L0076ee74;
    case 0x0076ee78u: goto L0076ee78;
    case 0x0076ee7cu: goto L0076ee7c;
    case 0x0076ee80u: goto L0076ee80;
    case 0x0076ee84u: goto L0076ee84;
    case 0x0076ee88u: goto L0076ee88;
    case 0x0076ee8cu: goto L0076ee8c;
    case 0x0076ee90u: goto L0076ee90;
    case 0x0076ee94u: goto L0076ee94;
    case 0x0076ee98u: goto L0076ee98;
    case 0x0076ee9cu: goto L0076ee9c;
    case 0x0076eea3u: goto L0076eea3;
    case 0x0076eea5u: goto L0076eea5;
    case 0x0076eea7u: goto L0076eea7;
    case 0x0076eec0u: goto L0076eec0;
    case 0x0076eec3u: goto L0076eec3;
    case 0x0076eec4u: goto L0076eec4;
    case 0x0076eec5u: goto L0076eec5;
    case 0x0076eec6u: goto L0076eec6;
    case 0x0076eec8u: goto L0076eec8;
    case 0x0076eecbu: goto L0076eecb;
    case 0x0076eeceu: goto L0076eece;
    case 0x0076eed1u: goto L0076eed1;
    case 0x0076eed2u: goto L0076eed2;
    case 0x0076eed3u: goto L0076eed3;
    case 0x0076eed4u: goto L0076eed4;
    case 0x0076eed8u: goto L0076eed8;
    case 0x0076eedbu: goto L0076eedb;
    case 0x0076eedeu: goto L0076eede;
    case 0x0076eee1u: goto L0076eee1;
    case 0x0076eee4u: goto L0076eee4;
    case 0x0076eee7u: goto L0076eee7;
    case 0x0076eee8u: goto L0076eee8;
    case 0x0076eee9u: goto L0076eee9;
    case 0x0076eeeau: goto L0076eeea;
    case 0x0076eeecu: goto L0076eeec;
    case 0x0076eeefu: goto L0076eeef;
    case 0x0076eef2u: goto L0076eef2;
    case 0x0076eef5u: goto L0076eef5;
    case 0x0076eef8u: goto L0076eef8;
    case 0x0076eefbu: goto L0076eefb;
    case 0x0076eefeu: goto L0076eefe;
    case 0x0076ef01u: goto L0076ef01;
    case 0x0076ef02u: goto L0076ef02;
    case 0x0076ef03u: goto L0076ef03;
    case 0x0076ef04u: goto L0076ef04;
    default:throw std::domain_error("recovery233 unsupported switch destination");}
  }
  L0076eccc: { // 0x76eccc: 8b448ee4 MOV EAX,dword ptr [ESI + ECX*0x4 + -0x1c]
    s.ax = m.r32((s.si+(s.cx * 0x00000004u)-0x0000001cu));
  }
  L0076ecd0: { // 0x76ecd0: 89448fe4 MOV dword ptr [EDI + ECX*0x4 + -0x1c],EAX
    m.w32((s.di+(s.cx * 0x00000004u)-0x0000001cu), s.ax);
  }
  L0076ecd4: { // 0x76ecd4: 8b448ee8 MOV EAX,dword ptr [ESI + ECX*0x4 + -0x18]
    s.ax = m.r32((s.si+(s.cx * 0x00000004u)-0x00000018u));
  }
  L0076ecd8: { // 0x76ecd8: 89448fe8 MOV dword ptr [EDI + ECX*0x4 + -0x18],EAX
    m.w32((s.di+(s.cx * 0x00000004u)-0x00000018u), s.ax);
  }
  L0076ecdc: { // 0x76ecdc: 8b448eec MOV EAX,dword ptr [ESI + ECX*0x4 + -0x14]
    s.ax = m.r32((s.si+(s.cx * 0x00000004u)-0x00000014u));
  }
  L0076ece0: { // 0x76ece0: 89448fec MOV dword ptr [EDI + ECX*0x4 + -0x14],EAX
    m.w32((s.di+(s.cx * 0x00000004u)-0x00000014u), s.ax);
  }
  L0076ece4: { // 0x76ece4: 8b448ef0 MOV EAX,dword ptr [ESI + ECX*0x4 + -0x10]
    s.ax = m.r32((s.si+(s.cx * 0x00000004u)-0x00000010u));
  }
  L0076ece8: { // 0x76ece8: 89448ff0 MOV dword ptr [EDI + ECX*0x4 + -0x10],EAX
    m.w32((s.di+(s.cx * 0x00000004u)-0x00000010u), s.ax);
  }
  L0076ecec: { // 0x76ecec: 8b448ef4 MOV EAX,dword ptr [ESI + ECX*0x4 + -0xc]
    s.ax = m.r32((s.si+(s.cx * 0x00000004u)-0x0000000cu));
  }
  L0076ecf0: { // 0x76ecf0: 89448ff4 MOV dword ptr [EDI + ECX*0x4 + -0xc],EAX
    m.w32((s.di+(s.cx * 0x00000004u)-0x0000000cu), s.ax);
  }
  L0076ecf4: { // 0x76ecf4: 8b448ef8 MOV EAX,dword ptr [ESI + ECX*0x4 + -0x8]
    s.ax = m.r32((s.si+(s.cx * 0x00000004u)-0x00000008u));
  }
  L0076ecf8: { // 0x76ecf8: 89448ff8 MOV dword ptr [EDI + ECX*0x4 + -0x8],EAX
    m.w32((s.di+(s.cx * 0x00000004u)-0x00000008u), s.ax);
  }
  L0076ecfc: { // 0x76ecfc: 8b448efc MOV EAX,dword ptr [ESI + ECX*0x4 + -0x4]
    s.ax = m.r32((s.si+(s.cx * 0x00000004u)-0x00000004u));
  }
  L0076ed00: { // 0x76ed00: 89448ffc MOV dword ptr [EDI + ECX*0x4 + -0x4],EAX
    m.w32((s.di+(s.cx * 0x00000004u)-0x00000004u), s.ax);
  }
  L0076ed04: { // 0x76ed04: 8d048d00000000 LEA EAX,[ECX*0x4 + 0x0]
    s.ax = ((s.cx * 0x00000004u)+0x00000000u);
  }
  L0076ed0b: { // 0x76ed0b: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L0076ed0d: { // 0x76ed0d: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L0076ed0f: { // 0x76ed0f: ff249518ed7600 JMP dword ptr [EDX*0x4 + 0x76ed18]
    switch(m.r32(((s.dx * 0x00000004u)+0x0076ed18u))){
    case 0x0076ebd0u: goto L0076ebd0;
    case 0x0076ebd1u: goto L0076ebd1;
    case 0x0076ebd3u: goto L0076ebd3;
    case 0x0076ebd4u: goto L0076ebd4;
    case 0x0076ebd5u: goto L0076ebd5;
    case 0x0076ebd8u: goto L0076ebd8;
    case 0x0076ebdbu: goto L0076ebdb;
    case 0x0076ebdeu: goto L0076ebde;
    case 0x0076ebe0u: goto L0076ebe0;
    case 0x0076ebe2u: goto L0076ebe2;
    case 0x0076ebe4u: goto L0076ebe4;
    case 0x0076ebe6u: goto L0076ebe6;
    case 0x0076ebe8u: goto L0076ebe8;
    case 0x0076ebeau: goto L0076ebea;
    case 0x0076ebf0u: goto L0076ebf0;
    case 0x0076ebf6u: goto L0076ebf6;
    case 0x0076ebf8u: goto L0076ebf8;
    case 0x0076ebfbu: goto L0076ebfb;
    case 0x0076ebfeu: goto L0076ebfe;
    case 0x0076ec01u: goto L0076ec01;
    case 0x0076ec03u: goto L0076ec03;
    case 0x0076ec05u: goto L0076ec05;
    case 0x0076ec0cu: goto L0076ec0c;
    case 0x0076ec0eu: goto L0076ec0e;
    case 0x0076ec13u: goto L0076ec13;
    case 0x0076ec16u: goto L0076ec16;
    case 0x0076ec18u: goto L0076ec18;
    case 0x0076ec1bu: goto L0076ec1b;
    case 0x0076ec1du: goto L0076ec1d;
    case 0x0076ec24u: goto L0076ec24;
    case 0x0076ec2cu: goto L0076ec2c;
    case 0x0076ec40u: goto L0076ec40;
    case 0x0076ec42u: goto L0076ec42;
    case 0x0076ec44u: goto L0076ec44;
    case 0x0076ec46u: goto L0076ec46;
    case 0x0076ec49u: goto L0076ec49;
    case 0x0076ec4cu: goto L0076ec4c;
    case 0x0076ec4fu: goto L0076ec4f;
    case 0x0076ec52u: goto L0076ec52;
    case 0x0076ec55u: goto L0076ec55;
    case 0x0076ec58u: goto L0076ec58;
    case 0x0076ec5bu: goto L0076ec5b;
    case 0x0076ec5eu: goto L0076ec5e;
    case 0x0076ec60u: goto L0076ec60;
    case 0x0076ec62u: goto L0076ec62;
    case 0x0076ec6cu: goto L0076ec6c;
    case 0x0076ec6eu: goto L0076ec6e;
    case 0x0076ec70u: goto L0076ec70;
    case 0x0076ec72u: goto L0076ec72;
    case 0x0076ec75u: goto L0076ec75;
    case 0x0076ec78u: goto L0076ec78;
    case 0x0076ec7bu: goto L0076ec7b;
    case 0x0076ec7eu: goto L0076ec7e;
    case 0x0076ec81u: goto L0076ec81;
    case 0x0076ec84u: goto L0076ec84;
    case 0x0076ec86u: goto L0076ec86;
    case 0x0076ec88u: goto L0076ec88;
    case 0x0076ec90u: goto L0076ec90;
    case 0x0076ec92u: goto L0076ec92;
    case 0x0076ec94u: goto L0076ec94;
    case 0x0076ec96u: goto L0076ec96;
    case 0x0076ec97u: goto L0076ec97;
    case 0x0076ec9au: goto L0076ec9a;
    case 0x0076ec9bu: goto L0076ec9b;
    case 0x0076ec9eu: goto L0076ec9e;
    case 0x0076eca0u: goto L0076eca0;
    case 0x0076eca2u: goto L0076eca2;
    case 0x0076ecccu: goto L0076eccc;
    case 0x0076ecd0u: goto L0076ecd0;
    case 0x0076ecd4u: goto L0076ecd4;
    case 0x0076ecd8u: goto L0076ecd8;
    case 0x0076ecdcu: goto L0076ecdc;
    case 0x0076ece0u: goto L0076ece0;
    case 0x0076ece4u: goto L0076ece4;
    case 0x0076ece8u: goto L0076ece8;
    case 0x0076ececu: goto L0076ecec;
    case 0x0076ecf0u: goto L0076ecf0;
    case 0x0076ecf4u: goto L0076ecf4;
    case 0x0076ecf8u: goto L0076ecf8;
    case 0x0076ecfcu: goto L0076ecfc;
    case 0x0076ed00u: goto L0076ed00;
    case 0x0076ed04u: goto L0076ed04;
    case 0x0076ed0bu: goto L0076ed0b;
    case 0x0076ed0du: goto L0076ed0d;
    case 0x0076ed0fu: goto L0076ed0f;
    case 0x0076ed28u: goto L0076ed28;
    case 0x0076ed2bu: goto L0076ed2b;
    case 0x0076ed2cu: goto L0076ed2c;
    case 0x0076ed2du: goto L0076ed2d;
    case 0x0076ed2eu: goto L0076ed2e;
    case 0x0076ed30u: goto L0076ed30;
    case 0x0076ed32u: goto L0076ed32;
    case 0x0076ed34u: goto L0076ed34;
    case 0x0076ed37u: goto L0076ed37;
    case 0x0076ed38u: goto L0076ed38;
    case 0x0076ed39u: goto L0076ed39;
    case 0x0076ed3au: goto L0076ed3a;
    case 0x0076ed3cu: goto L0076ed3c;
    case 0x0076ed3eu: goto L0076ed3e;
    case 0x0076ed40u: goto L0076ed40;
    case 0x0076ed43u: goto L0076ed43;
    case 0x0076ed46u: goto L0076ed46;
    case 0x0076ed49u: goto L0076ed49;
    case 0x0076ed4au: goto L0076ed4a;
    case 0x0076ed4bu: goto L0076ed4b;
    case 0x0076ed4cu: goto L0076ed4c;
    case 0x0076ed50u: goto L0076ed50;
    case 0x0076ed52u: goto L0076ed52;
    case 0x0076ed54u: goto L0076ed54;
    case 0x0076ed57u: goto L0076ed57;
    case 0x0076ed5au: goto L0076ed5a;
    case 0x0076ed5du: goto L0076ed5d;
    case 0x0076ed60u: goto L0076ed60;
    case 0x0076ed63u: goto L0076ed63;
    case 0x0076ed64u: goto L0076ed64;
    case 0x0076ed65u: goto L0076ed65;
    case 0x0076ed66u: goto L0076ed66;
    case 0x0076ed68u: goto L0076ed68;
    case 0x0076ed6cu: goto L0076ed6c;
    case 0x0076ed70u: goto L0076ed70;
    case 0x0076ed76u: goto L0076ed76;
    case 0x0076ed78u: goto L0076ed78;
    case 0x0076ed7bu: goto L0076ed7b;
    case 0x0076ed7eu: goto L0076ed7e;
    case 0x0076ed81u: goto L0076ed81;
    case 0x0076ed83u: goto L0076ed83;
    case 0x0076ed84u: goto L0076ed84;
    case 0x0076ed86u: goto L0076ed86;
    case 0x0076ed87u: goto L0076ed87;
    case 0x0076ed90u: goto L0076ed90;
    case 0x0076ed92u: goto L0076ed92;
    case 0x0076ed9cu: goto L0076ed9c;
    case 0x0076ed9eu: goto L0076ed9e;
    case 0x0076eda3u: goto L0076eda3;
    case 0x0076eda6u: goto L0076eda6;
    case 0x0076eda8u: goto L0076eda8;
    case 0x0076edabu: goto L0076edab;
    case 0x0076edadu: goto L0076edad;
    case 0x0076edb4u: goto L0076edb4;
    case 0x0076edc8u: goto L0076edc8;
    case 0x0076edcbu: goto L0076edcb;
    case 0x0076edcdu: goto L0076edcd;
    case 0x0076edd0u: goto L0076edd0;
    case 0x0076edd1u: goto L0076edd1;
    case 0x0076edd4u: goto L0076edd4;
    case 0x0076edd5u: goto L0076edd5;
    case 0x0076edd8u: goto L0076edd8;
    case 0x0076eddau: goto L0076edda;
    case 0x0076eddbu: goto L0076eddb;
    case 0x0076edddu: goto L0076eddd;
    case 0x0076eddeu: goto L0076edde;
    case 0x0076ede8u: goto L0076ede8;
    case 0x0076edebu: goto L0076edeb;
    case 0x0076ededu: goto L0076eded;
    case 0x0076edf0u: goto L0076edf0;
    case 0x0076edf3u: goto L0076edf3;
    case 0x0076edf6u: goto L0076edf6;
    case 0x0076edf9u: goto L0076edf9;
    case 0x0076edfcu: goto L0076edfc;
    case 0x0076edffu: goto L0076edff;
    case 0x0076ee02u: goto L0076ee02;
    case 0x0076ee04u: goto L0076ee04;
    case 0x0076ee05u: goto L0076ee05;
    case 0x0076ee07u: goto L0076ee07;
    case 0x0076ee08u: goto L0076ee08;
    case 0x0076ee10u: goto L0076ee10;
    case 0x0076ee13u: goto L0076ee13;
    case 0x0076ee15u: goto L0076ee15;
    case 0x0076ee18u: goto L0076ee18;
    case 0x0076ee1bu: goto L0076ee1b;
    case 0x0076ee1eu: goto L0076ee1e;
    case 0x0076ee21u: goto L0076ee21;
    case 0x0076ee24u: goto L0076ee24;
    case 0x0076ee27u: goto L0076ee27;
    case 0x0076ee2au: goto L0076ee2a;
    case 0x0076ee2du: goto L0076ee2d;
    case 0x0076ee30u: goto L0076ee30;
    case 0x0076ee36u: goto L0076ee36;
    case 0x0076ee37u: goto L0076ee37;
    case 0x0076ee39u: goto L0076ee39;
    case 0x0076ee3au: goto L0076ee3a;
    case 0x0076ee64u: goto L0076ee64;
    case 0x0076ee68u: goto L0076ee68;
    case 0x0076ee6cu: goto L0076ee6c;
    case 0x0076ee70u: goto L0076ee70;
    case 0x0076ee74u: goto L0076ee74;
    case 0x0076ee78u: goto L0076ee78;
    case 0x0076ee7cu: goto L0076ee7c;
    case 0x0076ee80u: goto L0076ee80;
    case 0x0076ee84u: goto L0076ee84;
    case 0x0076ee88u: goto L0076ee88;
    case 0x0076ee8cu: goto L0076ee8c;
    case 0x0076ee90u: goto L0076ee90;
    case 0x0076ee94u: goto L0076ee94;
    case 0x0076ee98u: goto L0076ee98;
    case 0x0076ee9cu: goto L0076ee9c;
    case 0x0076eea3u: goto L0076eea3;
    case 0x0076eea5u: goto L0076eea5;
    case 0x0076eea7u: goto L0076eea7;
    case 0x0076eec0u: goto L0076eec0;
    case 0x0076eec3u: goto L0076eec3;
    case 0x0076eec4u: goto L0076eec4;
    case 0x0076eec5u: goto L0076eec5;
    case 0x0076eec6u: goto L0076eec6;
    case 0x0076eec8u: goto L0076eec8;
    case 0x0076eecbu: goto L0076eecb;
    case 0x0076eeceu: goto L0076eece;
    case 0x0076eed1u: goto L0076eed1;
    case 0x0076eed2u: goto L0076eed2;
    case 0x0076eed3u: goto L0076eed3;
    case 0x0076eed4u: goto L0076eed4;
    case 0x0076eed8u: goto L0076eed8;
    case 0x0076eedbu: goto L0076eedb;
    case 0x0076eedeu: goto L0076eede;
    case 0x0076eee1u: goto L0076eee1;
    case 0x0076eee4u: goto L0076eee4;
    case 0x0076eee7u: goto L0076eee7;
    case 0x0076eee8u: goto L0076eee8;
    case 0x0076eee9u: goto L0076eee9;
    case 0x0076eeeau: goto L0076eeea;
    case 0x0076eeecu: goto L0076eeec;
    case 0x0076eeefu: goto L0076eeef;
    case 0x0076eef2u: goto L0076eef2;
    case 0x0076eef5u: goto L0076eef5;
    case 0x0076eef8u: goto L0076eef8;
    case 0x0076eefbu: goto L0076eefb;
    case 0x0076eefeu: goto L0076eefe;
    case 0x0076ef01u: goto L0076ef01;
    case 0x0076ef02u: goto L0076ef02;
    case 0x0076ef03u: goto L0076ef03;
    case 0x0076ef04u: goto L0076ef04;
    default:throw std::domain_error("recovery233 unsupported switch destination");}
  }
  L0076ed28: { // 0x76ed28: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L0076ed2b: { // 0x76ed2b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076ed2c: { // 0x76ed2c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076ed2d: { // 0x76ed2d: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L0076ed2e: { // 0x76ed2e: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076ed30: { // 0x76ed30: 8a06 MOV AL,byte ptr [ESI]
    s.ax = with_al(s.ax, m.r8((s.si)));
  }
  L0076ed32: { // 0x76ed32: 8807 MOV byte ptr [EDI],AL
    m.w8((s.di), (s.ax & 0xffu));
  }
  L0076ed34: { // 0x76ed34: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L0076ed37: { // 0x76ed37: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076ed38: { // 0x76ed38: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076ed39: { // 0x76ed39: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L0076ed3a: { // 0x76ed3a: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076ed3c: { // 0x76ed3c: 8a06 MOV AL,byte ptr [ESI]
    s.ax = with_al(s.ax, m.r8((s.si)));
  }
  L0076ed3e: { // 0x76ed3e: 8807 MOV byte ptr [EDI],AL
    m.w8((s.di), (s.ax & 0xffu));
  }
  L0076ed40: { // 0x76ed40: 8a4601 MOV AL,byte ptr [ESI + 0x1]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000001u)));
  }
  L0076ed43: { // 0x76ed43: 884701 MOV byte ptr [EDI + 0x1],AL
    m.w8((s.di+0x00000001u), (s.ax & 0xffu));
  }
  L0076ed46: { // 0x76ed46: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L0076ed49: { // 0x76ed49: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076ed4a: { // 0x76ed4a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076ed4b: { // 0x76ed4b: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L0076ed4c: { // 0x76ed4c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076ed50: { // 0x76ed50: 8a06 MOV AL,byte ptr [ESI]
    s.ax = with_al(s.ax, m.r8((s.si)));
  }
  L0076ed52: { // 0x76ed52: 8807 MOV byte ptr [EDI],AL
    m.w8((s.di), (s.ax & 0xffu));
  }
  L0076ed54: { // 0x76ed54: 8a4601 MOV AL,byte ptr [ESI + 0x1]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000001u)));
  }
  L0076ed57: { // 0x76ed57: 884701 MOV byte ptr [EDI + 0x1],AL
    m.w8((s.di+0x00000001u), (s.ax & 0xffu));
  }
  L0076ed5a: { // 0x76ed5a: 8a4602 MOV AL,byte ptr [ESI + 0x2]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000002u)));
  }
  L0076ed5d: { // 0x76ed5d: 884702 MOV byte ptr [EDI + 0x2],AL
    m.w8((s.di+0x00000002u), (s.ax & 0xffu));
  }
  L0076ed60: { // 0x76ed60: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L0076ed63: { // 0x76ed63: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076ed64: { // 0x76ed64: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076ed65: { // 0x76ed65: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L0076ed66: { // 0x76ed66: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076ed68: { // 0x76ed68: 8d7431fc LEA ESI,[ECX + ESI*0x1 + -0x4]
    s.si = (s.cx+(s.si * 0x00000001u)-0x00000004u);
  }
  L0076ed6c: { // 0x76ed6c: 8d7c39fc LEA EDI,[ECX + EDI*0x1 + -0x4]
    s.di = (s.cx+(s.di * 0x00000001u)-0x00000004u);
  }
  L0076ed70: { // 0x76ed70: f7c703000000 TEST EDI,0x3
    (void)integer::logical((s.di)&(0x00000003u),32,flags);
  }
  L0076ed76: { // 0x76ed76: 7524 JNZ 0x0076ed9c
    if(integer::condition("JNZ",flags)) goto L0076ed9c;
  }
  L0076ed78: { // 0x76ed78: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L0076ed7b: { // 0x76ed7b: 83e203 AND EDX,0x3
    s.dx = integer::logical((s.dx)&(0x00000003u),32,flags);
  }
  L0076ed7e: { // 0x76ed7e: 83f908 CMP ECX,0x8
    (void)integer::sub(s.cx,0x00000008u,32,flags);
  }
  L0076ed81: { // 0x76ed81: 720d JC 0x0076ed90
    if(integer::condition("JC",flags)) goto L0076ed90;
  }
  L0076ed83: { // 0x76ed83: fd STD
    flags |= 0x400u;
  }
  L0076ed84: { // 0x76ed84: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L0076ed86: { // 0x76ed86: fc CLD
    flags &= ~0x400u;
  }
  L0076ed87: { // 0x76ed87: ff2495b0ee7600 JMP dword ptr [EDX*0x4 + 0x76eeb0]
    switch(m.r32(((s.dx * 0x00000004u)+0x0076eeb0u))){
    case 0x0076ebd0u: goto L0076ebd0;
    case 0x0076ebd1u: goto L0076ebd1;
    case 0x0076ebd3u: goto L0076ebd3;
    case 0x0076ebd4u: goto L0076ebd4;
    case 0x0076ebd5u: goto L0076ebd5;
    case 0x0076ebd8u: goto L0076ebd8;
    case 0x0076ebdbu: goto L0076ebdb;
    case 0x0076ebdeu: goto L0076ebde;
    case 0x0076ebe0u: goto L0076ebe0;
    case 0x0076ebe2u: goto L0076ebe2;
    case 0x0076ebe4u: goto L0076ebe4;
    case 0x0076ebe6u: goto L0076ebe6;
    case 0x0076ebe8u: goto L0076ebe8;
    case 0x0076ebeau: goto L0076ebea;
    case 0x0076ebf0u: goto L0076ebf0;
    case 0x0076ebf6u: goto L0076ebf6;
    case 0x0076ebf8u: goto L0076ebf8;
    case 0x0076ebfbu: goto L0076ebfb;
    case 0x0076ebfeu: goto L0076ebfe;
    case 0x0076ec01u: goto L0076ec01;
    case 0x0076ec03u: goto L0076ec03;
    case 0x0076ec05u: goto L0076ec05;
    case 0x0076ec0cu: goto L0076ec0c;
    case 0x0076ec0eu: goto L0076ec0e;
    case 0x0076ec13u: goto L0076ec13;
    case 0x0076ec16u: goto L0076ec16;
    case 0x0076ec18u: goto L0076ec18;
    case 0x0076ec1bu: goto L0076ec1b;
    case 0x0076ec1du: goto L0076ec1d;
    case 0x0076ec24u: goto L0076ec24;
    case 0x0076ec2cu: goto L0076ec2c;
    case 0x0076ec40u: goto L0076ec40;
    case 0x0076ec42u: goto L0076ec42;
    case 0x0076ec44u: goto L0076ec44;
    case 0x0076ec46u: goto L0076ec46;
    case 0x0076ec49u: goto L0076ec49;
    case 0x0076ec4cu: goto L0076ec4c;
    case 0x0076ec4fu: goto L0076ec4f;
    case 0x0076ec52u: goto L0076ec52;
    case 0x0076ec55u: goto L0076ec55;
    case 0x0076ec58u: goto L0076ec58;
    case 0x0076ec5bu: goto L0076ec5b;
    case 0x0076ec5eu: goto L0076ec5e;
    case 0x0076ec60u: goto L0076ec60;
    case 0x0076ec62u: goto L0076ec62;
    case 0x0076ec6cu: goto L0076ec6c;
    case 0x0076ec6eu: goto L0076ec6e;
    case 0x0076ec70u: goto L0076ec70;
    case 0x0076ec72u: goto L0076ec72;
    case 0x0076ec75u: goto L0076ec75;
    case 0x0076ec78u: goto L0076ec78;
    case 0x0076ec7bu: goto L0076ec7b;
    case 0x0076ec7eu: goto L0076ec7e;
    case 0x0076ec81u: goto L0076ec81;
    case 0x0076ec84u: goto L0076ec84;
    case 0x0076ec86u: goto L0076ec86;
    case 0x0076ec88u: goto L0076ec88;
    case 0x0076ec90u: goto L0076ec90;
    case 0x0076ec92u: goto L0076ec92;
    case 0x0076ec94u: goto L0076ec94;
    case 0x0076ec96u: goto L0076ec96;
    case 0x0076ec97u: goto L0076ec97;
    case 0x0076ec9au: goto L0076ec9a;
    case 0x0076ec9bu: goto L0076ec9b;
    case 0x0076ec9eu: goto L0076ec9e;
    case 0x0076eca0u: goto L0076eca0;
    case 0x0076eca2u: goto L0076eca2;
    case 0x0076ecccu: goto L0076eccc;
    case 0x0076ecd0u: goto L0076ecd0;
    case 0x0076ecd4u: goto L0076ecd4;
    case 0x0076ecd8u: goto L0076ecd8;
    case 0x0076ecdcu: goto L0076ecdc;
    case 0x0076ece0u: goto L0076ece0;
    case 0x0076ece4u: goto L0076ece4;
    case 0x0076ece8u: goto L0076ece8;
    case 0x0076ececu: goto L0076ecec;
    case 0x0076ecf0u: goto L0076ecf0;
    case 0x0076ecf4u: goto L0076ecf4;
    case 0x0076ecf8u: goto L0076ecf8;
    case 0x0076ecfcu: goto L0076ecfc;
    case 0x0076ed00u: goto L0076ed00;
    case 0x0076ed04u: goto L0076ed04;
    case 0x0076ed0bu: goto L0076ed0b;
    case 0x0076ed0du: goto L0076ed0d;
    case 0x0076ed0fu: goto L0076ed0f;
    case 0x0076ed28u: goto L0076ed28;
    case 0x0076ed2bu: goto L0076ed2b;
    case 0x0076ed2cu: goto L0076ed2c;
    case 0x0076ed2du: goto L0076ed2d;
    case 0x0076ed2eu: goto L0076ed2e;
    case 0x0076ed30u: goto L0076ed30;
    case 0x0076ed32u: goto L0076ed32;
    case 0x0076ed34u: goto L0076ed34;
    case 0x0076ed37u: goto L0076ed37;
    case 0x0076ed38u: goto L0076ed38;
    case 0x0076ed39u: goto L0076ed39;
    case 0x0076ed3au: goto L0076ed3a;
    case 0x0076ed3cu: goto L0076ed3c;
    case 0x0076ed3eu: goto L0076ed3e;
    case 0x0076ed40u: goto L0076ed40;
    case 0x0076ed43u: goto L0076ed43;
    case 0x0076ed46u: goto L0076ed46;
    case 0x0076ed49u: goto L0076ed49;
    case 0x0076ed4au: goto L0076ed4a;
    case 0x0076ed4bu: goto L0076ed4b;
    case 0x0076ed4cu: goto L0076ed4c;
    case 0x0076ed50u: goto L0076ed50;
    case 0x0076ed52u: goto L0076ed52;
    case 0x0076ed54u: goto L0076ed54;
    case 0x0076ed57u: goto L0076ed57;
    case 0x0076ed5au: goto L0076ed5a;
    case 0x0076ed5du: goto L0076ed5d;
    case 0x0076ed60u: goto L0076ed60;
    case 0x0076ed63u: goto L0076ed63;
    case 0x0076ed64u: goto L0076ed64;
    case 0x0076ed65u: goto L0076ed65;
    case 0x0076ed66u: goto L0076ed66;
    case 0x0076ed68u: goto L0076ed68;
    case 0x0076ed6cu: goto L0076ed6c;
    case 0x0076ed70u: goto L0076ed70;
    case 0x0076ed76u: goto L0076ed76;
    case 0x0076ed78u: goto L0076ed78;
    case 0x0076ed7bu: goto L0076ed7b;
    case 0x0076ed7eu: goto L0076ed7e;
    case 0x0076ed81u: goto L0076ed81;
    case 0x0076ed83u: goto L0076ed83;
    case 0x0076ed84u: goto L0076ed84;
    case 0x0076ed86u: goto L0076ed86;
    case 0x0076ed87u: goto L0076ed87;
    case 0x0076ed90u: goto L0076ed90;
    case 0x0076ed92u: goto L0076ed92;
    case 0x0076ed9cu: goto L0076ed9c;
    case 0x0076ed9eu: goto L0076ed9e;
    case 0x0076eda3u: goto L0076eda3;
    case 0x0076eda6u: goto L0076eda6;
    case 0x0076eda8u: goto L0076eda8;
    case 0x0076edabu: goto L0076edab;
    case 0x0076edadu: goto L0076edad;
    case 0x0076edb4u: goto L0076edb4;
    case 0x0076edc8u: goto L0076edc8;
    case 0x0076edcbu: goto L0076edcb;
    case 0x0076edcdu: goto L0076edcd;
    case 0x0076edd0u: goto L0076edd0;
    case 0x0076edd1u: goto L0076edd1;
    case 0x0076edd4u: goto L0076edd4;
    case 0x0076edd5u: goto L0076edd5;
    case 0x0076edd8u: goto L0076edd8;
    case 0x0076eddau: goto L0076edda;
    case 0x0076eddbu: goto L0076eddb;
    case 0x0076edddu: goto L0076eddd;
    case 0x0076eddeu: goto L0076edde;
    case 0x0076ede8u: goto L0076ede8;
    case 0x0076edebu: goto L0076edeb;
    case 0x0076ededu: goto L0076eded;
    case 0x0076edf0u: goto L0076edf0;
    case 0x0076edf3u: goto L0076edf3;
    case 0x0076edf6u: goto L0076edf6;
    case 0x0076edf9u: goto L0076edf9;
    case 0x0076edfcu: goto L0076edfc;
    case 0x0076edffu: goto L0076edff;
    case 0x0076ee02u: goto L0076ee02;
    case 0x0076ee04u: goto L0076ee04;
    case 0x0076ee05u: goto L0076ee05;
    case 0x0076ee07u: goto L0076ee07;
    case 0x0076ee08u: goto L0076ee08;
    case 0x0076ee10u: goto L0076ee10;
    case 0x0076ee13u: goto L0076ee13;
    case 0x0076ee15u: goto L0076ee15;
    case 0x0076ee18u: goto L0076ee18;
    case 0x0076ee1bu: goto L0076ee1b;
    case 0x0076ee1eu: goto L0076ee1e;
    case 0x0076ee21u: goto L0076ee21;
    case 0x0076ee24u: goto L0076ee24;
    case 0x0076ee27u: goto L0076ee27;
    case 0x0076ee2au: goto L0076ee2a;
    case 0x0076ee2du: goto L0076ee2d;
    case 0x0076ee30u: goto L0076ee30;
    case 0x0076ee36u: goto L0076ee36;
    case 0x0076ee37u: goto L0076ee37;
    case 0x0076ee39u: goto L0076ee39;
    case 0x0076ee3au: goto L0076ee3a;
    case 0x0076ee64u: goto L0076ee64;
    case 0x0076ee68u: goto L0076ee68;
    case 0x0076ee6cu: goto L0076ee6c;
    case 0x0076ee70u: goto L0076ee70;
    case 0x0076ee74u: goto L0076ee74;
    case 0x0076ee78u: goto L0076ee78;
    case 0x0076ee7cu: goto L0076ee7c;
    case 0x0076ee80u: goto L0076ee80;
    case 0x0076ee84u: goto L0076ee84;
    case 0x0076ee88u: goto L0076ee88;
    case 0x0076ee8cu: goto L0076ee8c;
    case 0x0076ee90u: goto L0076ee90;
    case 0x0076ee94u: goto L0076ee94;
    case 0x0076ee98u: goto L0076ee98;
    case 0x0076ee9cu: goto L0076ee9c;
    case 0x0076eea3u: goto L0076eea3;
    case 0x0076eea5u: goto L0076eea5;
    case 0x0076eea7u: goto L0076eea7;
    case 0x0076eec0u: goto L0076eec0;
    case 0x0076eec3u: goto L0076eec3;
    case 0x0076eec4u: goto L0076eec4;
    case 0x0076eec5u: goto L0076eec5;
    case 0x0076eec6u: goto L0076eec6;
    case 0x0076eec8u: goto L0076eec8;
    case 0x0076eecbu: goto L0076eecb;
    case 0x0076eeceu: goto L0076eece;
    case 0x0076eed1u: goto L0076eed1;
    case 0x0076eed2u: goto L0076eed2;
    case 0x0076eed3u: goto L0076eed3;
    case 0x0076eed4u: goto L0076eed4;
    case 0x0076eed8u: goto L0076eed8;
    case 0x0076eedbu: goto L0076eedb;
    case 0x0076eedeu: goto L0076eede;
    case 0x0076eee1u: goto L0076eee1;
    case 0x0076eee4u: goto L0076eee4;
    case 0x0076eee7u: goto L0076eee7;
    case 0x0076eee8u: goto L0076eee8;
    case 0x0076eee9u: goto L0076eee9;
    case 0x0076eeeau: goto L0076eeea;
    case 0x0076eeecu: goto L0076eeec;
    case 0x0076eeefu: goto L0076eeef;
    case 0x0076eef2u: goto L0076eef2;
    case 0x0076eef5u: goto L0076eef5;
    case 0x0076eef8u: goto L0076eef8;
    case 0x0076eefbu: goto L0076eefb;
    case 0x0076eefeu: goto L0076eefe;
    case 0x0076ef01u: goto L0076ef01;
    case 0x0076ef02u: goto L0076ef02;
    case 0x0076ef03u: goto L0076ef03;
    case 0x0076ef04u: goto L0076ef04;
    default:throw std::domain_error("recovery233 unsupported switch destination");}
  }
  L0076ed90: { // 0x76ed90: f7d9 NEG ECX
    s.cx = integer::sub(0u,s.cx,32,flags);
  }
  L0076ed92: { // 0x76ed92: ff248d60ee7600 JMP dword ptr [ECX*0x4 + 0x76ee60]
    switch(m.r32(((s.cx * 0x00000004u)+0x0076ee60u))){
    case 0x0076ebd0u: goto L0076ebd0;
    case 0x0076ebd1u: goto L0076ebd1;
    case 0x0076ebd3u: goto L0076ebd3;
    case 0x0076ebd4u: goto L0076ebd4;
    case 0x0076ebd5u: goto L0076ebd5;
    case 0x0076ebd8u: goto L0076ebd8;
    case 0x0076ebdbu: goto L0076ebdb;
    case 0x0076ebdeu: goto L0076ebde;
    case 0x0076ebe0u: goto L0076ebe0;
    case 0x0076ebe2u: goto L0076ebe2;
    case 0x0076ebe4u: goto L0076ebe4;
    case 0x0076ebe6u: goto L0076ebe6;
    case 0x0076ebe8u: goto L0076ebe8;
    case 0x0076ebeau: goto L0076ebea;
    case 0x0076ebf0u: goto L0076ebf0;
    case 0x0076ebf6u: goto L0076ebf6;
    case 0x0076ebf8u: goto L0076ebf8;
    case 0x0076ebfbu: goto L0076ebfb;
    case 0x0076ebfeu: goto L0076ebfe;
    case 0x0076ec01u: goto L0076ec01;
    case 0x0076ec03u: goto L0076ec03;
    case 0x0076ec05u: goto L0076ec05;
    case 0x0076ec0cu: goto L0076ec0c;
    case 0x0076ec0eu: goto L0076ec0e;
    case 0x0076ec13u: goto L0076ec13;
    case 0x0076ec16u: goto L0076ec16;
    case 0x0076ec18u: goto L0076ec18;
    case 0x0076ec1bu: goto L0076ec1b;
    case 0x0076ec1du: goto L0076ec1d;
    case 0x0076ec24u: goto L0076ec24;
    case 0x0076ec2cu: goto L0076ec2c;
    case 0x0076ec40u: goto L0076ec40;
    case 0x0076ec42u: goto L0076ec42;
    case 0x0076ec44u: goto L0076ec44;
    case 0x0076ec46u: goto L0076ec46;
    case 0x0076ec49u: goto L0076ec49;
    case 0x0076ec4cu: goto L0076ec4c;
    case 0x0076ec4fu: goto L0076ec4f;
    case 0x0076ec52u: goto L0076ec52;
    case 0x0076ec55u: goto L0076ec55;
    case 0x0076ec58u: goto L0076ec58;
    case 0x0076ec5bu: goto L0076ec5b;
    case 0x0076ec5eu: goto L0076ec5e;
    case 0x0076ec60u: goto L0076ec60;
    case 0x0076ec62u: goto L0076ec62;
    case 0x0076ec6cu: goto L0076ec6c;
    case 0x0076ec6eu: goto L0076ec6e;
    case 0x0076ec70u: goto L0076ec70;
    case 0x0076ec72u: goto L0076ec72;
    case 0x0076ec75u: goto L0076ec75;
    case 0x0076ec78u: goto L0076ec78;
    case 0x0076ec7bu: goto L0076ec7b;
    case 0x0076ec7eu: goto L0076ec7e;
    case 0x0076ec81u: goto L0076ec81;
    case 0x0076ec84u: goto L0076ec84;
    case 0x0076ec86u: goto L0076ec86;
    case 0x0076ec88u: goto L0076ec88;
    case 0x0076ec90u: goto L0076ec90;
    case 0x0076ec92u: goto L0076ec92;
    case 0x0076ec94u: goto L0076ec94;
    case 0x0076ec96u: goto L0076ec96;
    case 0x0076ec97u: goto L0076ec97;
    case 0x0076ec9au: goto L0076ec9a;
    case 0x0076ec9bu: goto L0076ec9b;
    case 0x0076ec9eu: goto L0076ec9e;
    case 0x0076eca0u: goto L0076eca0;
    case 0x0076eca2u: goto L0076eca2;
    case 0x0076ecccu: goto L0076eccc;
    case 0x0076ecd0u: goto L0076ecd0;
    case 0x0076ecd4u: goto L0076ecd4;
    case 0x0076ecd8u: goto L0076ecd8;
    case 0x0076ecdcu: goto L0076ecdc;
    case 0x0076ece0u: goto L0076ece0;
    case 0x0076ece4u: goto L0076ece4;
    case 0x0076ece8u: goto L0076ece8;
    case 0x0076ececu: goto L0076ecec;
    case 0x0076ecf0u: goto L0076ecf0;
    case 0x0076ecf4u: goto L0076ecf4;
    case 0x0076ecf8u: goto L0076ecf8;
    case 0x0076ecfcu: goto L0076ecfc;
    case 0x0076ed00u: goto L0076ed00;
    case 0x0076ed04u: goto L0076ed04;
    case 0x0076ed0bu: goto L0076ed0b;
    case 0x0076ed0du: goto L0076ed0d;
    case 0x0076ed0fu: goto L0076ed0f;
    case 0x0076ed28u: goto L0076ed28;
    case 0x0076ed2bu: goto L0076ed2b;
    case 0x0076ed2cu: goto L0076ed2c;
    case 0x0076ed2du: goto L0076ed2d;
    case 0x0076ed2eu: goto L0076ed2e;
    case 0x0076ed30u: goto L0076ed30;
    case 0x0076ed32u: goto L0076ed32;
    case 0x0076ed34u: goto L0076ed34;
    case 0x0076ed37u: goto L0076ed37;
    case 0x0076ed38u: goto L0076ed38;
    case 0x0076ed39u: goto L0076ed39;
    case 0x0076ed3au: goto L0076ed3a;
    case 0x0076ed3cu: goto L0076ed3c;
    case 0x0076ed3eu: goto L0076ed3e;
    case 0x0076ed40u: goto L0076ed40;
    case 0x0076ed43u: goto L0076ed43;
    case 0x0076ed46u: goto L0076ed46;
    case 0x0076ed49u: goto L0076ed49;
    case 0x0076ed4au: goto L0076ed4a;
    case 0x0076ed4bu: goto L0076ed4b;
    case 0x0076ed4cu: goto L0076ed4c;
    case 0x0076ed50u: goto L0076ed50;
    case 0x0076ed52u: goto L0076ed52;
    case 0x0076ed54u: goto L0076ed54;
    case 0x0076ed57u: goto L0076ed57;
    case 0x0076ed5au: goto L0076ed5a;
    case 0x0076ed5du: goto L0076ed5d;
    case 0x0076ed60u: goto L0076ed60;
    case 0x0076ed63u: goto L0076ed63;
    case 0x0076ed64u: goto L0076ed64;
    case 0x0076ed65u: goto L0076ed65;
    case 0x0076ed66u: goto L0076ed66;
    case 0x0076ed68u: goto L0076ed68;
    case 0x0076ed6cu: goto L0076ed6c;
    case 0x0076ed70u: goto L0076ed70;
    case 0x0076ed76u: goto L0076ed76;
    case 0x0076ed78u: goto L0076ed78;
    case 0x0076ed7bu: goto L0076ed7b;
    case 0x0076ed7eu: goto L0076ed7e;
    case 0x0076ed81u: goto L0076ed81;
    case 0x0076ed83u: goto L0076ed83;
    case 0x0076ed84u: goto L0076ed84;
    case 0x0076ed86u: goto L0076ed86;
    case 0x0076ed87u: goto L0076ed87;
    case 0x0076ed90u: goto L0076ed90;
    case 0x0076ed92u: goto L0076ed92;
    case 0x0076ed9cu: goto L0076ed9c;
    case 0x0076ed9eu: goto L0076ed9e;
    case 0x0076eda3u: goto L0076eda3;
    case 0x0076eda6u: goto L0076eda6;
    case 0x0076eda8u: goto L0076eda8;
    case 0x0076edabu: goto L0076edab;
    case 0x0076edadu: goto L0076edad;
    case 0x0076edb4u: goto L0076edb4;
    case 0x0076edc8u: goto L0076edc8;
    case 0x0076edcbu: goto L0076edcb;
    case 0x0076edcdu: goto L0076edcd;
    case 0x0076edd0u: goto L0076edd0;
    case 0x0076edd1u: goto L0076edd1;
    case 0x0076edd4u: goto L0076edd4;
    case 0x0076edd5u: goto L0076edd5;
    case 0x0076edd8u: goto L0076edd8;
    case 0x0076eddau: goto L0076edda;
    case 0x0076eddbu: goto L0076eddb;
    case 0x0076edddu: goto L0076eddd;
    case 0x0076eddeu: goto L0076edde;
    case 0x0076ede8u: goto L0076ede8;
    case 0x0076edebu: goto L0076edeb;
    case 0x0076ededu: goto L0076eded;
    case 0x0076edf0u: goto L0076edf0;
    case 0x0076edf3u: goto L0076edf3;
    case 0x0076edf6u: goto L0076edf6;
    case 0x0076edf9u: goto L0076edf9;
    case 0x0076edfcu: goto L0076edfc;
    case 0x0076edffu: goto L0076edff;
    case 0x0076ee02u: goto L0076ee02;
    case 0x0076ee04u: goto L0076ee04;
    case 0x0076ee05u: goto L0076ee05;
    case 0x0076ee07u: goto L0076ee07;
    case 0x0076ee08u: goto L0076ee08;
    case 0x0076ee10u: goto L0076ee10;
    case 0x0076ee13u: goto L0076ee13;
    case 0x0076ee15u: goto L0076ee15;
    case 0x0076ee18u: goto L0076ee18;
    case 0x0076ee1bu: goto L0076ee1b;
    case 0x0076ee1eu: goto L0076ee1e;
    case 0x0076ee21u: goto L0076ee21;
    case 0x0076ee24u: goto L0076ee24;
    case 0x0076ee27u: goto L0076ee27;
    case 0x0076ee2au: goto L0076ee2a;
    case 0x0076ee2du: goto L0076ee2d;
    case 0x0076ee30u: goto L0076ee30;
    case 0x0076ee36u: goto L0076ee36;
    case 0x0076ee37u: goto L0076ee37;
    case 0x0076ee39u: goto L0076ee39;
    case 0x0076ee3au: goto L0076ee3a;
    case 0x0076ee64u: goto L0076ee64;
    case 0x0076ee68u: goto L0076ee68;
    case 0x0076ee6cu: goto L0076ee6c;
    case 0x0076ee70u: goto L0076ee70;
    case 0x0076ee74u: goto L0076ee74;
    case 0x0076ee78u: goto L0076ee78;
    case 0x0076ee7cu: goto L0076ee7c;
    case 0x0076ee80u: goto L0076ee80;
    case 0x0076ee84u: goto L0076ee84;
    case 0x0076ee88u: goto L0076ee88;
    case 0x0076ee8cu: goto L0076ee8c;
    case 0x0076ee90u: goto L0076ee90;
    case 0x0076ee94u: goto L0076ee94;
    case 0x0076ee98u: goto L0076ee98;
    case 0x0076ee9cu: goto L0076ee9c;
    case 0x0076eea3u: goto L0076eea3;
    case 0x0076eea5u: goto L0076eea5;
    case 0x0076eea7u: goto L0076eea7;
    case 0x0076eec0u: goto L0076eec0;
    case 0x0076eec3u: goto L0076eec3;
    case 0x0076eec4u: goto L0076eec4;
    case 0x0076eec5u: goto L0076eec5;
    case 0x0076eec6u: goto L0076eec6;
    case 0x0076eec8u: goto L0076eec8;
    case 0x0076eecbu: goto L0076eecb;
    case 0x0076eeceu: goto L0076eece;
    case 0x0076eed1u: goto L0076eed1;
    case 0x0076eed2u: goto L0076eed2;
    case 0x0076eed3u: goto L0076eed3;
    case 0x0076eed4u: goto L0076eed4;
    case 0x0076eed8u: goto L0076eed8;
    case 0x0076eedbu: goto L0076eedb;
    case 0x0076eedeu: goto L0076eede;
    case 0x0076eee1u: goto L0076eee1;
    case 0x0076eee4u: goto L0076eee4;
    case 0x0076eee7u: goto L0076eee7;
    case 0x0076eee8u: goto L0076eee8;
    case 0x0076eee9u: goto L0076eee9;
    case 0x0076eeeau: goto L0076eeea;
    case 0x0076eeecu: goto L0076eeec;
    case 0x0076eeefu: goto L0076eeef;
    case 0x0076eef2u: goto L0076eef2;
    case 0x0076eef5u: goto L0076eef5;
    case 0x0076eef8u: goto L0076eef8;
    case 0x0076eefbu: goto L0076eefb;
    case 0x0076eefeu: goto L0076eefe;
    case 0x0076ef01u: goto L0076ef01;
    case 0x0076ef02u: goto L0076ef02;
    case 0x0076ef03u: goto L0076ef03;
    case 0x0076ef04u: goto L0076ef04;
    default:throw std::domain_error("recovery233 unsupported switch destination");}
  }
  L0076ed9c: { // 0x76ed9c: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0076ed9e: { // 0x76ed9e: ba03000000 MOV EDX,0x3
    s.dx = 0x00000003u;
  }
  L0076eda3: { // 0x76eda3: 83f904 CMP ECX,0x4
    (void)integer::sub(s.cx,0x00000004u,32,flags);
  }
  L0076eda6: { // 0x76eda6: 720c JC 0x0076edb4
    if(integer::condition("JC",flags)) goto L0076edb4;
  }
  L0076eda8: { // 0x76eda8: 83e003 AND EAX,0x3
    s.ax = integer::logical((s.ax)&(0x00000003u),32,flags);
  }
  L0076edab: { // 0x76edab: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L0076edad: { // 0x76edad: ff2485b8ed7600 JMP dword ptr [EAX*0x4 + 0x76edb8]
    switch(m.r32(((s.ax * 0x00000004u)+0x0076edb8u))){
    case 0x0076ebd0u: goto L0076ebd0;
    case 0x0076ebd1u: goto L0076ebd1;
    case 0x0076ebd3u: goto L0076ebd3;
    case 0x0076ebd4u: goto L0076ebd4;
    case 0x0076ebd5u: goto L0076ebd5;
    case 0x0076ebd8u: goto L0076ebd8;
    case 0x0076ebdbu: goto L0076ebdb;
    case 0x0076ebdeu: goto L0076ebde;
    case 0x0076ebe0u: goto L0076ebe0;
    case 0x0076ebe2u: goto L0076ebe2;
    case 0x0076ebe4u: goto L0076ebe4;
    case 0x0076ebe6u: goto L0076ebe6;
    case 0x0076ebe8u: goto L0076ebe8;
    case 0x0076ebeau: goto L0076ebea;
    case 0x0076ebf0u: goto L0076ebf0;
    case 0x0076ebf6u: goto L0076ebf6;
    case 0x0076ebf8u: goto L0076ebf8;
    case 0x0076ebfbu: goto L0076ebfb;
    case 0x0076ebfeu: goto L0076ebfe;
    case 0x0076ec01u: goto L0076ec01;
    case 0x0076ec03u: goto L0076ec03;
    case 0x0076ec05u: goto L0076ec05;
    case 0x0076ec0cu: goto L0076ec0c;
    case 0x0076ec0eu: goto L0076ec0e;
    case 0x0076ec13u: goto L0076ec13;
    case 0x0076ec16u: goto L0076ec16;
    case 0x0076ec18u: goto L0076ec18;
    case 0x0076ec1bu: goto L0076ec1b;
    case 0x0076ec1du: goto L0076ec1d;
    case 0x0076ec24u: goto L0076ec24;
    case 0x0076ec2cu: goto L0076ec2c;
    case 0x0076ec40u: goto L0076ec40;
    case 0x0076ec42u: goto L0076ec42;
    case 0x0076ec44u: goto L0076ec44;
    case 0x0076ec46u: goto L0076ec46;
    case 0x0076ec49u: goto L0076ec49;
    case 0x0076ec4cu: goto L0076ec4c;
    case 0x0076ec4fu: goto L0076ec4f;
    case 0x0076ec52u: goto L0076ec52;
    case 0x0076ec55u: goto L0076ec55;
    case 0x0076ec58u: goto L0076ec58;
    case 0x0076ec5bu: goto L0076ec5b;
    case 0x0076ec5eu: goto L0076ec5e;
    case 0x0076ec60u: goto L0076ec60;
    case 0x0076ec62u: goto L0076ec62;
    case 0x0076ec6cu: goto L0076ec6c;
    case 0x0076ec6eu: goto L0076ec6e;
    case 0x0076ec70u: goto L0076ec70;
    case 0x0076ec72u: goto L0076ec72;
    case 0x0076ec75u: goto L0076ec75;
    case 0x0076ec78u: goto L0076ec78;
    case 0x0076ec7bu: goto L0076ec7b;
    case 0x0076ec7eu: goto L0076ec7e;
    case 0x0076ec81u: goto L0076ec81;
    case 0x0076ec84u: goto L0076ec84;
    case 0x0076ec86u: goto L0076ec86;
    case 0x0076ec88u: goto L0076ec88;
    case 0x0076ec90u: goto L0076ec90;
    case 0x0076ec92u: goto L0076ec92;
    case 0x0076ec94u: goto L0076ec94;
    case 0x0076ec96u: goto L0076ec96;
    case 0x0076ec97u: goto L0076ec97;
    case 0x0076ec9au: goto L0076ec9a;
    case 0x0076ec9bu: goto L0076ec9b;
    case 0x0076ec9eu: goto L0076ec9e;
    case 0x0076eca0u: goto L0076eca0;
    case 0x0076eca2u: goto L0076eca2;
    case 0x0076ecccu: goto L0076eccc;
    case 0x0076ecd0u: goto L0076ecd0;
    case 0x0076ecd4u: goto L0076ecd4;
    case 0x0076ecd8u: goto L0076ecd8;
    case 0x0076ecdcu: goto L0076ecdc;
    case 0x0076ece0u: goto L0076ece0;
    case 0x0076ece4u: goto L0076ece4;
    case 0x0076ece8u: goto L0076ece8;
    case 0x0076ececu: goto L0076ecec;
    case 0x0076ecf0u: goto L0076ecf0;
    case 0x0076ecf4u: goto L0076ecf4;
    case 0x0076ecf8u: goto L0076ecf8;
    case 0x0076ecfcu: goto L0076ecfc;
    case 0x0076ed00u: goto L0076ed00;
    case 0x0076ed04u: goto L0076ed04;
    case 0x0076ed0bu: goto L0076ed0b;
    case 0x0076ed0du: goto L0076ed0d;
    case 0x0076ed0fu: goto L0076ed0f;
    case 0x0076ed28u: goto L0076ed28;
    case 0x0076ed2bu: goto L0076ed2b;
    case 0x0076ed2cu: goto L0076ed2c;
    case 0x0076ed2du: goto L0076ed2d;
    case 0x0076ed2eu: goto L0076ed2e;
    case 0x0076ed30u: goto L0076ed30;
    case 0x0076ed32u: goto L0076ed32;
    case 0x0076ed34u: goto L0076ed34;
    case 0x0076ed37u: goto L0076ed37;
    case 0x0076ed38u: goto L0076ed38;
    case 0x0076ed39u: goto L0076ed39;
    case 0x0076ed3au: goto L0076ed3a;
    case 0x0076ed3cu: goto L0076ed3c;
    case 0x0076ed3eu: goto L0076ed3e;
    case 0x0076ed40u: goto L0076ed40;
    case 0x0076ed43u: goto L0076ed43;
    case 0x0076ed46u: goto L0076ed46;
    case 0x0076ed49u: goto L0076ed49;
    case 0x0076ed4au: goto L0076ed4a;
    case 0x0076ed4bu: goto L0076ed4b;
    case 0x0076ed4cu: goto L0076ed4c;
    case 0x0076ed50u: goto L0076ed50;
    case 0x0076ed52u: goto L0076ed52;
    case 0x0076ed54u: goto L0076ed54;
    case 0x0076ed57u: goto L0076ed57;
    case 0x0076ed5au: goto L0076ed5a;
    case 0x0076ed5du: goto L0076ed5d;
    case 0x0076ed60u: goto L0076ed60;
    case 0x0076ed63u: goto L0076ed63;
    case 0x0076ed64u: goto L0076ed64;
    case 0x0076ed65u: goto L0076ed65;
    case 0x0076ed66u: goto L0076ed66;
    case 0x0076ed68u: goto L0076ed68;
    case 0x0076ed6cu: goto L0076ed6c;
    case 0x0076ed70u: goto L0076ed70;
    case 0x0076ed76u: goto L0076ed76;
    case 0x0076ed78u: goto L0076ed78;
    case 0x0076ed7bu: goto L0076ed7b;
    case 0x0076ed7eu: goto L0076ed7e;
    case 0x0076ed81u: goto L0076ed81;
    case 0x0076ed83u: goto L0076ed83;
    case 0x0076ed84u: goto L0076ed84;
    case 0x0076ed86u: goto L0076ed86;
    case 0x0076ed87u: goto L0076ed87;
    case 0x0076ed90u: goto L0076ed90;
    case 0x0076ed92u: goto L0076ed92;
    case 0x0076ed9cu: goto L0076ed9c;
    case 0x0076ed9eu: goto L0076ed9e;
    case 0x0076eda3u: goto L0076eda3;
    case 0x0076eda6u: goto L0076eda6;
    case 0x0076eda8u: goto L0076eda8;
    case 0x0076edabu: goto L0076edab;
    case 0x0076edadu: goto L0076edad;
    case 0x0076edb4u: goto L0076edb4;
    case 0x0076edc8u: goto L0076edc8;
    case 0x0076edcbu: goto L0076edcb;
    case 0x0076edcdu: goto L0076edcd;
    case 0x0076edd0u: goto L0076edd0;
    case 0x0076edd1u: goto L0076edd1;
    case 0x0076edd4u: goto L0076edd4;
    case 0x0076edd5u: goto L0076edd5;
    case 0x0076edd8u: goto L0076edd8;
    case 0x0076eddau: goto L0076edda;
    case 0x0076eddbu: goto L0076eddb;
    case 0x0076edddu: goto L0076eddd;
    case 0x0076eddeu: goto L0076edde;
    case 0x0076ede8u: goto L0076ede8;
    case 0x0076edebu: goto L0076edeb;
    case 0x0076ededu: goto L0076eded;
    case 0x0076edf0u: goto L0076edf0;
    case 0x0076edf3u: goto L0076edf3;
    case 0x0076edf6u: goto L0076edf6;
    case 0x0076edf9u: goto L0076edf9;
    case 0x0076edfcu: goto L0076edfc;
    case 0x0076edffu: goto L0076edff;
    case 0x0076ee02u: goto L0076ee02;
    case 0x0076ee04u: goto L0076ee04;
    case 0x0076ee05u: goto L0076ee05;
    case 0x0076ee07u: goto L0076ee07;
    case 0x0076ee08u: goto L0076ee08;
    case 0x0076ee10u: goto L0076ee10;
    case 0x0076ee13u: goto L0076ee13;
    case 0x0076ee15u: goto L0076ee15;
    case 0x0076ee18u: goto L0076ee18;
    case 0x0076ee1bu: goto L0076ee1b;
    case 0x0076ee1eu: goto L0076ee1e;
    case 0x0076ee21u: goto L0076ee21;
    case 0x0076ee24u: goto L0076ee24;
    case 0x0076ee27u: goto L0076ee27;
    case 0x0076ee2au: goto L0076ee2a;
    case 0x0076ee2du: goto L0076ee2d;
    case 0x0076ee30u: goto L0076ee30;
    case 0x0076ee36u: goto L0076ee36;
    case 0x0076ee37u: goto L0076ee37;
    case 0x0076ee39u: goto L0076ee39;
    case 0x0076ee3au: goto L0076ee3a;
    case 0x0076ee64u: goto L0076ee64;
    case 0x0076ee68u: goto L0076ee68;
    case 0x0076ee6cu: goto L0076ee6c;
    case 0x0076ee70u: goto L0076ee70;
    case 0x0076ee74u: goto L0076ee74;
    case 0x0076ee78u: goto L0076ee78;
    case 0x0076ee7cu: goto L0076ee7c;
    case 0x0076ee80u: goto L0076ee80;
    case 0x0076ee84u: goto L0076ee84;
    case 0x0076ee88u: goto L0076ee88;
    case 0x0076ee8cu: goto L0076ee8c;
    case 0x0076ee90u: goto L0076ee90;
    case 0x0076ee94u: goto L0076ee94;
    case 0x0076ee98u: goto L0076ee98;
    case 0x0076ee9cu: goto L0076ee9c;
    case 0x0076eea3u: goto L0076eea3;
    case 0x0076eea5u: goto L0076eea5;
    case 0x0076eea7u: goto L0076eea7;
    case 0x0076eec0u: goto L0076eec0;
    case 0x0076eec3u: goto L0076eec3;
    case 0x0076eec4u: goto L0076eec4;
    case 0x0076eec5u: goto L0076eec5;
    case 0x0076eec6u: goto L0076eec6;
    case 0x0076eec8u: goto L0076eec8;
    case 0x0076eecbu: goto L0076eecb;
    case 0x0076eeceu: goto L0076eece;
    case 0x0076eed1u: goto L0076eed1;
    case 0x0076eed2u: goto L0076eed2;
    case 0x0076eed3u: goto L0076eed3;
    case 0x0076eed4u: goto L0076eed4;
    case 0x0076eed8u: goto L0076eed8;
    case 0x0076eedbu: goto L0076eedb;
    case 0x0076eedeu: goto L0076eede;
    case 0x0076eee1u: goto L0076eee1;
    case 0x0076eee4u: goto L0076eee4;
    case 0x0076eee7u: goto L0076eee7;
    case 0x0076eee8u: goto L0076eee8;
    case 0x0076eee9u: goto L0076eee9;
    case 0x0076eeeau: goto L0076eeea;
    case 0x0076eeecu: goto L0076eeec;
    case 0x0076eeefu: goto L0076eeef;
    case 0x0076eef2u: goto L0076eef2;
    case 0x0076eef5u: goto L0076eef5;
    case 0x0076eef8u: goto L0076eef8;
    case 0x0076eefbu: goto L0076eefb;
    case 0x0076eefeu: goto L0076eefe;
    case 0x0076ef01u: goto L0076ef01;
    case 0x0076ef02u: goto L0076ef02;
    case 0x0076ef03u: goto L0076ef03;
    case 0x0076ef04u: goto L0076ef04;
    default:throw std::domain_error("recovery233 unsupported switch destination");}
  }
  L0076edb4: { // 0x76edb4: ff248db0ee7600 JMP dword ptr [ECX*0x4 + 0x76eeb0]
    switch(m.r32(((s.cx * 0x00000004u)+0x0076eeb0u))){
    case 0x0076ebd0u: goto L0076ebd0;
    case 0x0076ebd1u: goto L0076ebd1;
    case 0x0076ebd3u: goto L0076ebd3;
    case 0x0076ebd4u: goto L0076ebd4;
    case 0x0076ebd5u: goto L0076ebd5;
    case 0x0076ebd8u: goto L0076ebd8;
    case 0x0076ebdbu: goto L0076ebdb;
    case 0x0076ebdeu: goto L0076ebde;
    case 0x0076ebe0u: goto L0076ebe0;
    case 0x0076ebe2u: goto L0076ebe2;
    case 0x0076ebe4u: goto L0076ebe4;
    case 0x0076ebe6u: goto L0076ebe6;
    case 0x0076ebe8u: goto L0076ebe8;
    case 0x0076ebeau: goto L0076ebea;
    case 0x0076ebf0u: goto L0076ebf0;
    case 0x0076ebf6u: goto L0076ebf6;
    case 0x0076ebf8u: goto L0076ebf8;
    case 0x0076ebfbu: goto L0076ebfb;
    case 0x0076ebfeu: goto L0076ebfe;
    case 0x0076ec01u: goto L0076ec01;
    case 0x0076ec03u: goto L0076ec03;
    case 0x0076ec05u: goto L0076ec05;
    case 0x0076ec0cu: goto L0076ec0c;
    case 0x0076ec0eu: goto L0076ec0e;
    case 0x0076ec13u: goto L0076ec13;
    case 0x0076ec16u: goto L0076ec16;
    case 0x0076ec18u: goto L0076ec18;
    case 0x0076ec1bu: goto L0076ec1b;
    case 0x0076ec1du: goto L0076ec1d;
    case 0x0076ec24u: goto L0076ec24;
    case 0x0076ec2cu: goto L0076ec2c;
    case 0x0076ec40u: goto L0076ec40;
    case 0x0076ec42u: goto L0076ec42;
    case 0x0076ec44u: goto L0076ec44;
    case 0x0076ec46u: goto L0076ec46;
    case 0x0076ec49u: goto L0076ec49;
    case 0x0076ec4cu: goto L0076ec4c;
    case 0x0076ec4fu: goto L0076ec4f;
    case 0x0076ec52u: goto L0076ec52;
    case 0x0076ec55u: goto L0076ec55;
    case 0x0076ec58u: goto L0076ec58;
    case 0x0076ec5bu: goto L0076ec5b;
    case 0x0076ec5eu: goto L0076ec5e;
    case 0x0076ec60u: goto L0076ec60;
    case 0x0076ec62u: goto L0076ec62;
    case 0x0076ec6cu: goto L0076ec6c;
    case 0x0076ec6eu: goto L0076ec6e;
    case 0x0076ec70u: goto L0076ec70;
    case 0x0076ec72u: goto L0076ec72;
    case 0x0076ec75u: goto L0076ec75;
    case 0x0076ec78u: goto L0076ec78;
    case 0x0076ec7bu: goto L0076ec7b;
    case 0x0076ec7eu: goto L0076ec7e;
    case 0x0076ec81u: goto L0076ec81;
    case 0x0076ec84u: goto L0076ec84;
    case 0x0076ec86u: goto L0076ec86;
    case 0x0076ec88u: goto L0076ec88;
    case 0x0076ec90u: goto L0076ec90;
    case 0x0076ec92u: goto L0076ec92;
    case 0x0076ec94u: goto L0076ec94;
    case 0x0076ec96u: goto L0076ec96;
    case 0x0076ec97u: goto L0076ec97;
    case 0x0076ec9au: goto L0076ec9a;
    case 0x0076ec9bu: goto L0076ec9b;
    case 0x0076ec9eu: goto L0076ec9e;
    case 0x0076eca0u: goto L0076eca0;
    case 0x0076eca2u: goto L0076eca2;
    case 0x0076ecccu: goto L0076eccc;
    case 0x0076ecd0u: goto L0076ecd0;
    case 0x0076ecd4u: goto L0076ecd4;
    case 0x0076ecd8u: goto L0076ecd8;
    case 0x0076ecdcu: goto L0076ecdc;
    case 0x0076ece0u: goto L0076ece0;
    case 0x0076ece4u: goto L0076ece4;
    case 0x0076ece8u: goto L0076ece8;
    case 0x0076ececu: goto L0076ecec;
    case 0x0076ecf0u: goto L0076ecf0;
    case 0x0076ecf4u: goto L0076ecf4;
    case 0x0076ecf8u: goto L0076ecf8;
    case 0x0076ecfcu: goto L0076ecfc;
    case 0x0076ed00u: goto L0076ed00;
    case 0x0076ed04u: goto L0076ed04;
    case 0x0076ed0bu: goto L0076ed0b;
    case 0x0076ed0du: goto L0076ed0d;
    case 0x0076ed0fu: goto L0076ed0f;
    case 0x0076ed28u: goto L0076ed28;
    case 0x0076ed2bu: goto L0076ed2b;
    case 0x0076ed2cu: goto L0076ed2c;
    case 0x0076ed2du: goto L0076ed2d;
    case 0x0076ed2eu: goto L0076ed2e;
    case 0x0076ed30u: goto L0076ed30;
    case 0x0076ed32u: goto L0076ed32;
    case 0x0076ed34u: goto L0076ed34;
    case 0x0076ed37u: goto L0076ed37;
    case 0x0076ed38u: goto L0076ed38;
    case 0x0076ed39u: goto L0076ed39;
    case 0x0076ed3au: goto L0076ed3a;
    case 0x0076ed3cu: goto L0076ed3c;
    case 0x0076ed3eu: goto L0076ed3e;
    case 0x0076ed40u: goto L0076ed40;
    case 0x0076ed43u: goto L0076ed43;
    case 0x0076ed46u: goto L0076ed46;
    case 0x0076ed49u: goto L0076ed49;
    case 0x0076ed4au: goto L0076ed4a;
    case 0x0076ed4bu: goto L0076ed4b;
    case 0x0076ed4cu: goto L0076ed4c;
    case 0x0076ed50u: goto L0076ed50;
    case 0x0076ed52u: goto L0076ed52;
    case 0x0076ed54u: goto L0076ed54;
    case 0x0076ed57u: goto L0076ed57;
    case 0x0076ed5au: goto L0076ed5a;
    case 0x0076ed5du: goto L0076ed5d;
    case 0x0076ed60u: goto L0076ed60;
    case 0x0076ed63u: goto L0076ed63;
    case 0x0076ed64u: goto L0076ed64;
    case 0x0076ed65u: goto L0076ed65;
    case 0x0076ed66u: goto L0076ed66;
    case 0x0076ed68u: goto L0076ed68;
    case 0x0076ed6cu: goto L0076ed6c;
    case 0x0076ed70u: goto L0076ed70;
    case 0x0076ed76u: goto L0076ed76;
    case 0x0076ed78u: goto L0076ed78;
    case 0x0076ed7bu: goto L0076ed7b;
    case 0x0076ed7eu: goto L0076ed7e;
    case 0x0076ed81u: goto L0076ed81;
    case 0x0076ed83u: goto L0076ed83;
    case 0x0076ed84u: goto L0076ed84;
    case 0x0076ed86u: goto L0076ed86;
    case 0x0076ed87u: goto L0076ed87;
    case 0x0076ed90u: goto L0076ed90;
    case 0x0076ed92u: goto L0076ed92;
    case 0x0076ed9cu: goto L0076ed9c;
    case 0x0076ed9eu: goto L0076ed9e;
    case 0x0076eda3u: goto L0076eda3;
    case 0x0076eda6u: goto L0076eda6;
    case 0x0076eda8u: goto L0076eda8;
    case 0x0076edabu: goto L0076edab;
    case 0x0076edadu: goto L0076edad;
    case 0x0076edb4u: goto L0076edb4;
    case 0x0076edc8u: goto L0076edc8;
    case 0x0076edcbu: goto L0076edcb;
    case 0x0076edcdu: goto L0076edcd;
    case 0x0076edd0u: goto L0076edd0;
    case 0x0076edd1u: goto L0076edd1;
    case 0x0076edd4u: goto L0076edd4;
    case 0x0076edd5u: goto L0076edd5;
    case 0x0076edd8u: goto L0076edd8;
    case 0x0076eddau: goto L0076edda;
    case 0x0076eddbu: goto L0076eddb;
    case 0x0076edddu: goto L0076eddd;
    case 0x0076eddeu: goto L0076edde;
    case 0x0076ede8u: goto L0076ede8;
    case 0x0076edebu: goto L0076edeb;
    case 0x0076ededu: goto L0076eded;
    case 0x0076edf0u: goto L0076edf0;
    case 0x0076edf3u: goto L0076edf3;
    case 0x0076edf6u: goto L0076edf6;
    case 0x0076edf9u: goto L0076edf9;
    case 0x0076edfcu: goto L0076edfc;
    case 0x0076edffu: goto L0076edff;
    case 0x0076ee02u: goto L0076ee02;
    case 0x0076ee04u: goto L0076ee04;
    case 0x0076ee05u: goto L0076ee05;
    case 0x0076ee07u: goto L0076ee07;
    case 0x0076ee08u: goto L0076ee08;
    case 0x0076ee10u: goto L0076ee10;
    case 0x0076ee13u: goto L0076ee13;
    case 0x0076ee15u: goto L0076ee15;
    case 0x0076ee18u: goto L0076ee18;
    case 0x0076ee1bu: goto L0076ee1b;
    case 0x0076ee1eu: goto L0076ee1e;
    case 0x0076ee21u: goto L0076ee21;
    case 0x0076ee24u: goto L0076ee24;
    case 0x0076ee27u: goto L0076ee27;
    case 0x0076ee2au: goto L0076ee2a;
    case 0x0076ee2du: goto L0076ee2d;
    case 0x0076ee30u: goto L0076ee30;
    case 0x0076ee36u: goto L0076ee36;
    case 0x0076ee37u: goto L0076ee37;
    case 0x0076ee39u: goto L0076ee39;
    case 0x0076ee3au: goto L0076ee3a;
    case 0x0076ee64u: goto L0076ee64;
    case 0x0076ee68u: goto L0076ee68;
    case 0x0076ee6cu: goto L0076ee6c;
    case 0x0076ee70u: goto L0076ee70;
    case 0x0076ee74u: goto L0076ee74;
    case 0x0076ee78u: goto L0076ee78;
    case 0x0076ee7cu: goto L0076ee7c;
    case 0x0076ee80u: goto L0076ee80;
    case 0x0076ee84u: goto L0076ee84;
    case 0x0076ee88u: goto L0076ee88;
    case 0x0076ee8cu: goto L0076ee8c;
    case 0x0076ee90u: goto L0076ee90;
    case 0x0076ee94u: goto L0076ee94;
    case 0x0076ee98u: goto L0076ee98;
    case 0x0076ee9cu: goto L0076ee9c;
    case 0x0076eea3u: goto L0076eea3;
    case 0x0076eea5u: goto L0076eea5;
    case 0x0076eea7u: goto L0076eea7;
    case 0x0076eec0u: goto L0076eec0;
    case 0x0076eec3u: goto L0076eec3;
    case 0x0076eec4u: goto L0076eec4;
    case 0x0076eec5u: goto L0076eec5;
    case 0x0076eec6u: goto L0076eec6;
    case 0x0076eec8u: goto L0076eec8;
    case 0x0076eecbu: goto L0076eecb;
    case 0x0076eeceu: goto L0076eece;
    case 0x0076eed1u: goto L0076eed1;
    case 0x0076eed2u: goto L0076eed2;
    case 0x0076eed3u: goto L0076eed3;
    case 0x0076eed4u: goto L0076eed4;
    case 0x0076eed8u: goto L0076eed8;
    case 0x0076eedbu: goto L0076eedb;
    case 0x0076eedeu: goto L0076eede;
    case 0x0076eee1u: goto L0076eee1;
    case 0x0076eee4u: goto L0076eee4;
    case 0x0076eee7u: goto L0076eee7;
    case 0x0076eee8u: goto L0076eee8;
    case 0x0076eee9u: goto L0076eee9;
    case 0x0076eeeau: goto L0076eeea;
    case 0x0076eeecu: goto L0076eeec;
    case 0x0076eeefu: goto L0076eeef;
    case 0x0076eef2u: goto L0076eef2;
    case 0x0076eef5u: goto L0076eef5;
    case 0x0076eef8u: goto L0076eef8;
    case 0x0076eefbu: goto L0076eefb;
    case 0x0076eefeu: goto L0076eefe;
    case 0x0076ef01u: goto L0076ef01;
    case 0x0076ef02u: goto L0076ef02;
    case 0x0076ef03u: goto L0076ef03;
    case 0x0076ef04u: goto L0076ef04;
    default:throw std::domain_error("recovery233 unsupported switch destination");}
  }
  L0076edc8: { // 0x76edc8: 8a4603 MOV AL,byte ptr [ESI + 0x3]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000003u)));
  }
  L0076edcb: { // 0x76edcb: 23d1 AND EDX,ECX
    s.dx = integer::logical((s.dx)&(s.cx),32,flags);
  }
  L0076edcd: { // 0x76edcd: 884703 MOV byte ptr [EDI + 0x3],AL
    m.w8((s.di+0x00000003u), (s.ax & 0xffu));
  }
  L0076edd0: { // 0x76edd0: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L0076edd1: { // 0x76edd1: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L0076edd4: { // 0x76edd4: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L0076edd5: { // 0x76edd5: 83f908 CMP ECX,0x8
    (void)integer::sub(s.cx,0x00000008u,32,flags);
  }
  L0076edd8: { // 0x76edd8: 72b6 JC 0x0076ed90
    if(integer::condition("JC",flags)) goto L0076ed90;
  }
  L0076edda: { // 0x76edda: fd STD
    flags |= 0x400u;
  }
  L0076eddb: { // 0x76eddb: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L0076eddd: { // 0x76eddd: fc CLD
    flags &= ~0x400u;
  }
  L0076edde: { // 0x76edde: ff2495b0ee7600 JMP dword ptr [EDX*0x4 + 0x76eeb0]
    switch(m.r32(((s.dx * 0x00000004u)+0x0076eeb0u))){
    case 0x0076ebd0u: goto L0076ebd0;
    case 0x0076ebd1u: goto L0076ebd1;
    case 0x0076ebd3u: goto L0076ebd3;
    case 0x0076ebd4u: goto L0076ebd4;
    case 0x0076ebd5u: goto L0076ebd5;
    case 0x0076ebd8u: goto L0076ebd8;
    case 0x0076ebdbu: goto L0076ebdb;
    case 0x0076ebdeu: goto L0076ebde;
    case 0x0076ebe0u: goto L0076ebe0;
    case 0x0076ebe2u: goto L0076ebe2;
    case 0x0076ebe4u: goto L0076ebe4;
    case 0x0076ebe6u: goto L0076ebe6;
    case 0x0076ebe8u: goto L0076ebe8;
    case 0x0076ebeau: goto L0076ebea;
    case 0x0076ebf0u: goto L0076ebf0;
    case 0x0076ebf6u: goto L0076ebf6;
    case 0x0076ebf8u: goto L0076ebf8;
    case 0x0076ebfbu: goto L0076ebfb;
    case 0x0076ebfeu: goto L0076ebfe;
    case 0x0076ec01u: goto L0076ec01;
    case 0x0076ec03u: goto L0076ec03;
    case 0x0076ec05u: goto L0076ec05;
    case 0x0076ec0cu: goto L0076ec0c;
    case 0x0076ec0eu: goto L0076ec0e;
    case 0x0076ec13u: goto L0076ec13;
    case 0x0076ec16u: goto L0076ec16;
    case 0x0076ec18u: goto L0076ec18;
    case 0x0076ec1bu: goto L0076ec1b;
    case 0x0076ec1du: goto L0076ec1d;
    case 0x0076ec24u: goto L0076ec24;
    case 0x0076ec2cu: goto L0076ec2c;
    case 0x0076ec40u: goto L0076ec40;
    case 0x0076ec42u: goto L0076ec42;
    case 0x0076ec44u: goto L0076ec44;
    case 0x0076ec46u: goto L0076ec46;
    case 0x0076ec49u: goto L0076ec49;
    case 0x0076ec4cu: goto L0076ec4c;
    case 0x0076ec4fu: goto L0076ec4f;
    case 0x0076ec52u: goto L0076ec52;
    case 0x0076ec55u: goto L0076ec55;
    case 0x0076ec58u: goto L0076ec58;
    case 0x0076ec5bu: goto L0076ec5b;
    case 0x0076ec5eu: goto L0076ec5e;
    case 0x0076ec60u: goto L0076ec60;
    case 0x0076ec62u: goto L0076ec62;
    case 0x0076ec6cu: goto L0076ec6c;
    case 0x0076ec6eu: goto L0076ec6e;
    case 0x0076ec70u: goto L0076ec70;
    case 0x0076ec72u: goto L0076ec72;
    case 0x0076ec75u: goto L0076ec75;
    case 0x0076ec78u: goto L0076ec78;
    case 0x0076ec7bu: goto L0076ec7b;
    case 0x0076ec7eu: goto L0076ec7e;
    case 0x0076ec81u: goto L0076ec81;
    case 0x0076ec84u: goto L0076ec84;
    case 0x0076ec86u: goto L0076ec86;
    case 0x0076ec88u: goto L0076ec88;
    case 0x0076ec90u: goto L0076ec90;
    case 0x0076ec92u: goto L0076ec92;
    case 0x0076ec94u: goto L0076ec94;
    case 0x0076ec96u: goto L0076ec96;
    case 0x0076ec97u: goto L0076ec97;
    case 0x0076ec9au: goto L0076ec9a;
    case 0x0076ec9bu: goto L0076ec9b;
    case 0x0076ec9eu: goto L0076ec9e;
    case 0x0076eca0u: goto L0076eca0;
    case 0x0076eca2u: goto L0076eca2;
    case 0x0076ecccu: goto L0076eccc;
    case 0x0076ecd0u: goto L0076ecd0;
    case 0x0076ecd4u: goto L0076ecd4;
    case 0x0076ecd8u: goto L0076ecd8;
    case 0x0076ecdcu: goto L0076ecdc;
    case 0x0076ece0u: goto L0076ece0;
    case 0x0076ece4u: goto L0076ece4;
    case 0x0076ece8u: goto L0076ece8;
    case 0x0076ececu: goto L0076ecec;
    case 0x0076ecf0u: goto L0076ecf0;
    case 0x0076ecf4u: goto L0076ecf4;
    case 0x0076ecf8u: goto L0076ecf8;
    case 0x0076ecfcu: goto L0076ecfc;
    case 0x0076ed00u: goto L0076ed00;
    case 0x0076ed04u: goto L0076ed04;
    case 0x0076ed0bu: goto L0076ed0b;
    case 0x0076ed0du: goto L0076ed0d;
    case 0x0076ed0fu: goto L0076ed0f;
    case 0x0076ed28u: goto L0076ed28;
    case 0x0076ed2bu: goto L0076ed2b;
    case 0x0076ed2cu: goto L0076ed2c;
    case 0x0076ed2du: goto L0076ed2d;
    case 0x0076ed2eu: goto L0076ed2e;
    case 0x0076ed30u: goto L0076ed30;
    case 0x0076ed32u: goto L0076ed32;
    case 0x0076ed34u: goto L0076ed34;
    case 0x0076ed37u: goto L0076ed37;
    case 0x0076ed38u: goto L0076ed38;
    case 0x0076ed39u: goto L0076ed39;
    case 0x0076ed3au: goto L0076ed3a;
    case 0x0076ed3cu: goto L0076ed3c;
    case 0x0076ed3eu: goto L0076ed3e;
    case 0x0076ed40u: goto L0076ed40;
    case 0x0076ed43u: goto L0076ed43;
    case 0x0076ed46u: goto L0076ed46;
    case 0x0076ed49u: goto L0076ed49;
    case 0x0076ed4au: goto L0076ed4a;
    case 0x0076ed4bu: goto L0076ed4b;
    case 0x0076ed4cu: goto L0076ed4c;
    case 0x0076ed50u: goto L0076ed50;
    case 0x0076ed52u: goto L0076ed52;
    case 0x0076ed54u: goto L0076ed54;
    case 0x0076ed57u: goto L0076ed57;
    case 0x0076ed5au: goto L0076ed5a;
    case 0x0076ed5du: goto L0076ed5d;
    case 0x0076ed60u: goto L0076ed60;
    case 0x0076ed63u: goto L0076ed63;
    case 0x0076ed64u: goto L0076ed64;
    case 0x0076ed65u: goto L0076ed65;
    case 0x0076ed66u: goto L0076ed66;
    case 0x0076ed68u: goto L0076ed68;
    case 0x0076ed6cu: goto L0076ed6c;
    case 0x0076ed70u: goto L0076ed70;
    case 0x0076ed76u: goto L0076ed76;
    case 0x0076ed78u: goto L0076ed78;
    case 0x0076ed7bu: goto L0076ed7b;
    case 0x0076ed7eu: goto L0076ed7e;
    case 0x0076ed81u: goto L0076ed81;
    case 0x0076ed83u: goto L0076ed83;
    case 0x0076ed84u: goto L0076ed84;
    case 0x0076ed86u: goto L0076ed86;
    case 0x0076ed87u: goto L0076ed87;
    case 0x0076ed90u: goto L0076ed90;
    case 0x0076ed92u: goto L0076ed92;
    case 0x0076ed9cu: goto L0076ed9c;
    case 0x0076ed9eu: goto L0076ed9e;
    case 0x0076eda3u: goto L0076eda3;
    case 0x0076eda6u: goto L0076eda6;
    case 0x0076eda8u: goto L0076eda8;
    case 0x0076edabu: goto L0076edab;
    case 0x0076edadu: goto L0076edad;
    case 0x0076edb4u: goto L0076edb4;
    case 0x0076edc8u: goto L0076edc8;
    case 0x0076edcbu: goto L0076edcb;
    case 0x0076edcdu: goto L0076edcd;
    case 0x0076edd0u: goto L0076edd0;
    case 0x0076edd1u: goto L0076edd1;
    case 0x0076edd4u: goto L0076edd4;
    case 0x0076edd5u: goto L0076edd5;
    case 0x0076edd8u: goto L0076edd8;
    case 0x0076eddau: goto L0076edda;
    case 0x0076eddbu: goto L0076eddb;
    case 0x0076edddu: goto L0076eddd;
    case 0x0076eddeu: goto L0076edde;
    case 0x0076ede8u: goto L0076ede8;
    case 0x0076edebu: goto L0076edeb;
    case 0x0076ededu: goto L0076eded;
    case 0x0076edf0u: goto L0076edf0;
    case 0x0076edf3u: goto L0076edf3;
    case 0x0076edf6u: goto L0076edf6;
    case 0x0076edf9u: goto L0076edf9;
    case 0x0076edfcu: goto L0076edfc;
    case 0x0076edffu: goto L0076edff;
    case 0x0076ee02u: goto L0076ee02;
    case 0x0076ee04u: goto L0076ee04;
    case 0x0076ee05u: goto L0076ee05;
    case 0x0076ee07u: goto L0076ee07;
    case 0x0076ee08u: goto L0076ee08;
    case 0x0076ee10u: goto L0076ee10;
    case 0x0076ee13u: goto L0076ee13;
    case 0x0076ee15u: goto L0076ee15;
    case 0x0076ee18u: goto L0076ee18;
    case 0x0076ee1bu: goto L0076ee1b;
    case 0x0076ee1eu: goto L0076ee1e;
    case 0x0076ee21u: goto L0076ee21;
    case 0x0076ee24u: goto L0076ee24;
    case 0x0076ee27u: goto L0076ee27;
    case 0x0076ee2au: goto L0076ee2a;
    case 0x0076ee2du: goto L0076ee2d;
    case 0x0076ee30u: goto L0076ee30;
    case 0x0076ee36u: goto L0076ee36;
    case 0x0076ee37u: goto L0076ee37;
    case 0x0076ee39u: goto L0076ee39;
    case 0x0076ee3au: goto L0076ee3a;
    case 0x0076ee64u: goto L0076ee64;
    case 0x0076ee68u: goto L0076ee68;
    case 0x0076ee6cu: goto L0076ee6c;
    case 0x0076ee70u: goto L0076ee70;
    case 0x0076ee74u: goto L0076ee74;
    case 0x0076ee78u: goto L0076ee78;
    case 0x0076ee7cu: goto L0076ee7c;
    case 0x0076ee80u: goto L0076ee80;
    case 0x0076ee84u: goto L0076ee84;
    case 0x0076ee88u: goto L0076ee88;
    case 0x0076ee8cu: goto L0076ee8c;
    case 0x0076ee90u: goto L0076ee90;
    case 0x0076ee94u: goto L0076ee94;
    case 0x0076ee98u: goto L0076ee98;
    case 0x0076ee9cu: goto L0076ee9c;
    case 0x0076eea3u: goto L0076eea3;
    case 0x0076eea5u: goto L0076eea5;
    case 0x0076eea7u: goto L0076eea7;
    case 0x0076eec0u: goto L0076eec0;
    case 0x0076eec3u: goto L0076eec3;
    case 0x0076eec4u: goto L0076eec4;
    case 0x0076eec5u: goto L0076eec5;
    case 0x0076eec6u: goto L0076eec6;
    case 0x0076eec8u: goto L0076eec8;
    case 0x0076eecbu: goto L0076eecb;
    case 0x0076eeceu: goto L0076eece;
    case 0x0076eed1u: goto L0076eed1;
    case 0x0076eed2u: goto L0076eed2;
    case 0x0076eed3u: goto L0076eed3;
    case 0x0076eed4u: goto L0076eed4;
    case 0x0076eed8u: goto L0076eed8;
    case 0x0076eedbu: goto L0076eedb;
    case 0x0076eedeu: goto L0076eede;
    case 0x0076eee1u: goto L0076eee1;
    case 0x0076eee4u: goto L0076eee4;
    case 0x0076eee7u: goto L0076eee7;
    case 0x0076eee8u: goto L0076eee8;
    case 0x0076eee9u: goto L0076eee9;
    case 0x0076eeeau: goto L0076eeea;
    case 0x0076eeecu: goto L0076eeec;
    case 0x0076eeefu: goto L0076eeef;
    case 0x0076eef2u: goto L0076eef2;
    case 0x0076eef5u: goto L0076eef5;
    case 0x0076eef8u: goto L0076eef8;
    case 0x0076eefbu: goto L0076eefb;
    case 0x0076eefeu: goto L0076eefe;
    case 0x0076ef01u: goto L0076ef01;
    case 0x0076ef02u: goto L0076ef02;
    case 0x0076ef03u: goto L0076ef03;
    case 0x0076ef04u: goto L0076ef04;
    default:throw std::domain_error("recovery233 unsupported switch destination");}
  }
  L0076ede8: { // 0x76ede8: 8a4603 MOV AL,byte ptr [ESI + 0x3]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000003u)));
  }
  L0076edeb: { // 0x76edeb: 23d1 AND EDX,ECX
    s.dx = integer::logical((s.dx)&(s.cx),32,flags);
  }
  L0076eded: { // 0x76eded: 884703 MOV byte ptr [EDI + 0x3],AL
    m.w8((s.di+0x00000003u), (s.ax & 0xffu));
  }
  L0076edf0: { // 0x76edf0: 8a4602 MOV AL,byte ptr [ESI + 0x2]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000002u)));
  }
  L0076edf3: { // 0x76edf3: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L0076edf6: { // 0x76edf6: 884702 MOV byte ptr [EDI + 0x2],AL
    m.w8((s.di+0x00000002u), (s.ax & 0xffu));
  }
  L0076edf9: { // 0x76edf9: 83ee02 SUB ESI,0x2
    s.si = integer::sub(s.si,0x00000002u,32,flags);
  }
  L0076edfc: { // 0x76edfc: 83ef02 SUB EDI,0x2
    s.di = integer::sub(s.di,0x00000002u,32,flags);
  }
  L0076edff: { // 0x76edff: 83f908 CMP ECX,0x8
    (void)integer::sub(s.cx,0x00000008u,32,flags);
  }
  L0076ee02: { // 0x76ee02: 728c JC 0x0076ed90
    if(integer::condition("JC",flags)) goto L0076ed90;
  }
  L0076ee04: { // 0x76ee04: fd STD
    flags |= 0x400u;
  }
  L0076ee05: { // 0x76ee05: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L0076ee07: { // 0x76ee07: fc CLD
    flags &= ~0x400u;
  }
  L0076ee08: { // 0x76ee08: ff2495b0ee7600 JMP dword ptr [EDX*0x4 + 0x76eeb0]
    switch(m.r32(((s.dx * 0x00000004u)+0x0076eeb0u))){
    case 0x0076ebd0u: goto L0076ebd0;
    case 0x0076ebd1u: goto L0076ebd1;
    case 0x0076ebd3u: goto L0076ebd3;
    case 0x0076ebd4u: goto L0076ebd4;
    case 0x0076ebd5u: goto L0076ebd5;
    case 0x0076ebd8u: goto L0076ebd8;
    case 0x0076ebdbu: goto L0076ebdb;
    case 0x0076ebdeu: goto L0076ebde;
    case 0x0076ebe0u: goto L0076ebe0;
    case 0x0076ebe2u: goto L0076ebe2;
    case 0x0076ebe4u: goto L0076ebe4;
    case 0x0076ebe6u: goto L0076ebe6;
    case 0x0076ebe8u: goto L0076ebe8;
    case 0x0076ebeau: goto L0076ebea;
    case 0x0076ebf0u: goto L0076ebf0;
    case 0x0076ebf6u: goto L0076ebf6;
    case 0x0076ebf8u: goto L0076ebf8;
    case 0x0076ebfbu: goto L0076ebfb;
    case 0x0076ebfeu: goto L0076ebfe;
    case 0x0076ec01u: goto L0076ec01;
    case 0x0076ec03u: goto L0076ec03;
    case 0x0076ec05u: goto L0076ec05;
    case 0x0076ec0cu: goto L0076ec0c;
    case 0x0076ec0eu: goto L0076ec0e;
    case 0x0076ec13u: goto L0076ec13;
    case 0x0076ec16u: goto L0076ec16;
    case 0x0076ec18u: goto L0076ec18;
    case 0x0076ec1bu: goto L0076ec1b;
    case 0x0076ec1du: goto L0076ec1d;
    case 0x0076ec24u: goto L0076ec24;
    case 0x0076ec2cu: goto L0076ec2c;
    case 0x0076ec40u: goto L0076ec40;
    case 0x0076ec42u: goto L0076ec42;
    case 0x0076ec44u: goto L0076ec44;
    case 0x0076ec46u: goto L0076ec46;
    case 0x0076ec49u: goto L0076ec49;
    case 0x0076ec4cu: goto L0076ec4c;
    case 0x0076ec4fu: goto L0076ec4f;
    case 0x0076ec52u: goto L0076ec52;
    case 0x0076ec55u: goto L0076ec55;
    case 0x0076ec58u: goto L0076ec58;
    case 0x0076ec5bu: goto L0076ec5b;
    case 0x0076ec5eu: goto L0076ec5e;
    case 0x0076ec60u: goto L0076ec60;
    case 0x0076ec62u: goto L0076ec62;
    case 0x0076ec6cu: goto L0076ec6c;
    case 0x0076ec6eu: goto L0076ec6e;
    case 0x0076ec70u: goto L0076ec70;
    case 0x0076ec72u: goto L0076ec72;
    case 0x0076ec75u: goto L0076ec75;
    case 0x0076ec78u: goto L0076ec78;
    case 0x0076ec7bu: goto L0076ec7b;
    case 0x0076ec7eu: goto L0076ec7e;
    case 0x0076ec81u: goto L0076ec81;
    case 0x0076ec84u: goto L0076ec84;
    case 0x0076ec86u: goto L0076ec86;
    case 0x0076ec88u: goto L0076ec88;
    case 0x0076ec90u: goto L0076ec90;
    case 0x0076ec92u: goto L0076ec92;
    case 0x0076ec94u: goto L0076ec94;
    case 0x0076ec96u: goto L0076ec96;
    case 0x0076ec97u: goto L0076ec97;
    case 0x0076ec9au: goto L0076ec9a;
    case 0x0076ec9bu: goto L0076ec9b;
    case 0x0076ec9eu: goto L0076ec9e;
    case 0x0076eca0u: goto L0076eca0;
    case 0x0076eca2u: goto L0076eca2;
    case 0x0076ecccu: goto L0076eccc;
    case 0x0076ecd0u: goto L0076ecd0;
    case 0x0076ecd4u: goto L0076ecd4;
    case 0x0076ecd8u: goto L0076ecd8;
    case 0x0076ecdcu: goto L0076ecdc;
    case 0x0076ece0u: goto L0076ece0;
    case 0x0076ece4u: goto L0076ece4;
    case 0x0076ece8u: goto L0076ece8;
    case 0x0076ececu: goto L0076ecec;
    case 0x0076ecf0u: goto L0076ecf0;
    case 0x0076ecf4u: goto L0076ecf4;
    case 0x0076ecf8u: goto L0076ecf8;
    case 0x0076ecfcu: goto L0076ecfc;
    case 0x0076ed00u: goto L0076ed00;
    case 0x0076ed04u: goto L0076ed04;
    case 0x0076ed0bu: goto L0076ed0b;
    case 0x0076ed0du: goto L0076ed0d;
    case 0x0076ed0fu: goto L0076ed0f;
    case 0x0076ed28u: goto L0076ed28;
    case 0x0076ed2bu: goto L0076ed2b;
    case 0x0076ed2cu: goto L0076ed2c;
    case 0x0076ed2du: goto L0076ed2d;
    case 0x0076ed2eu: goto L0076ed2e;
    case 0x0076ed30u: goto L0076ed30;
    case 0x0076ed32u: goto L0076ed32;
    case 0x0076ed34u: goto L0076ed34;
    case 0x0076ed37u: goto L0076ed37;
    case 0x0076ed38u: goto L0076ed38;
    case 0x0076ed39u: goto L0076ed39;
    case 0x0076ed3au: goto L0076ed3a;
    case 0x0076ed3cu: goto L0076ed3c;
    case 0x0076ed3eu: goto L0076ed3e;
    case 0x0076ed40u: goto L0076ed40;
    case 0x0076ed43u: goto L0076ed43;
    case 0x0076ed46u: goto L0076ed46;
    case 0x0076ed49u: goto L0076ed49;
    case 0x0076ed4au: goto L0076ed4a;
    case 0x0076ed4bu: goto L0076ed4b;
    case 0x0076ed4cu: goto L0076ed4c;
    case 0x0076ed50u: goto L0076ed50;
    case 0x0076ed52u: goto L0076ed52;
    case 0x0076ed54u: goto L0076ed54;
    case 0x0076ed57u: goto L0076ed57;
    case 0x0076ed5au: goto L0076ed5a;
    case 0x0076ed5du: goto L0076ed5d;
    case 0x0076ed60u: goto L0076ed60;
    case 0x0076ed63u: goto L0076ed63;
    case 0x0076ed64u: goto L0076ed64;
    case 0x0076ed65u: goto L0076ed65;
    case 0x0076ed66u: goto L0076ed66;
    case 0x0076ed68u: goto L0076ed68;
    case 0x0076ed6cu: goto L0076ed6c;
    case 0x0076ed70u: goto L0076ed70;
    case 0x0076ed76u: goto L0076ed76;
    case 0x0076ed78u: goto L0076ed78;
    case 0x0076ed7bu: goto L0076ed7b;
    case 0x0076ed7eu: goto L0076ed7e;
    case 0x0076ed81u: goto L0076ed81;
    case 0x0076ed83u: goto L0076ed83;
    case 0x0076ed84u: goto L0076ed84;
    case 0x0076ed86u: goto L0076ed86;
    case 0x0076ed87u: goto L0076ed87;
    case 0x0076ed90u: goto L0076ed90;
    case 0x0076ed92u: goto L0076ed92;
    case 0x0076ed9cu: goto L0076ed9c;
    case 0x0076ed9eu: goto L0076ed9e;
    case 0x0076eda3u: goto L0076eda3;
    case 0x0076eda6u: goto L0076eda6;
    case 0x0076eda8u: goto L0076eda8;
    case 0x0076edabu: goto L0076edab;
    case 0x0076edadu: goto L0076edad;
    case 0x0076edb4u: goto L0076edb4;
    case 0x0076edc8u: goto L0076edc8;
    case 0x0076edcbu: goto L0076edcb;
    case 0x0076edcdu: goto L0076edcd;
    case 0x0076edd0u: goto L0076edd0;
    case 0x0076edd1u: goto L0076edd1;
    case 0x0076edd4u: goto L0076edd4;
    case 0x0076edd5u: goto L0076edd5;
    case 0x0076edd8u: goto L0076edd8;
    case 0x0076eddau: goto L0076edda;
    case 0x0076eddbu: goto L0076eddb;
    case 0x0076edddu: goto L0076eddd;
    case 0x0076eddeu: goto L0076edde;
    case 0x0076ede8u: goto L0076ede8;
    case 0x0076edebu: goto L0076edeb;
    case 0x0076ededu: goto L0076eded;
    case 0x0076edf0u: goto L0076edf0;
    case 0x0076edf3u: goto L0076edf3;
    case 0x0076edf6u: goto L0076edf6;
    case 0x0076edf9u: goto L0076edf9;
    case 0x0076edfcu: goto L0076edfc;
    case 0x0076edffu: goto L0076edff;
    case 0x0076ee02u: goto L0076ee02;
    case 0x0076ee04u: goto L0076ee04;
    case 0x0076ee05u: goto L0076ee05;
    case 0x0076ee07u: goto L0076ee07;
    case 0x0076ee08u: goto L0076ee08;
    case 0x0076ee10u: goto L0076ee10;
    case 0x0076ee13u: goto L0076ee13;
    case 0x0076ee15u: goto L0076ee15;
    case 0x0076ee18u: goto L0076ee18;
    case 0x0076ee1bu: goto L0076ee1b;
    case 0x0076ee1eu: goto L0076ee1e;
    case 0x0076ee21u: goto L0076ee21;
    case 0x0076ee24u: goto L0076ee24;
    case 0x0076ee27u: goto L0076ee27;
    case 0x0076ee2au: goto L0076ee2a;
    case 0x0076ee2du: goto L0076ee2d;
    case 0x0076ee30u: goto L0076ee30;
    case 0x0076ee36u: goto L0076ee36;
    case 0x0076ee37u: goto L0076ee37;
    case 0x0076ee39u: goto L0076ee39;
    case 0x0076ee3au: goto L0076ee3a;
    case 0x0076ee64u: goto L0076ee64;
    case 0x0076ee68u: goto L0076ee68;
    case 0x0076ee6cu: goto L0076ee6c;
    case 0x0076ee70u: goto L0076ee70;
    case 0x0076ee74u: goto L0076ee74;
    case 0x0076ee78u: goto L0076ee78;
    case 0x0076ee7cu: goto L0076ee7c;
    case 0x0076ee80u: goto L0076ee80;
    case 0x0076ee84u: goto L0076ee84;
    case 0x0076ee88u: goto L0076ee88;
    case 0x0076ee8cu: goto L0076ee8c;
    case 0x0076ee90u: goto L0076ee90;
    case 0x0076ee94u: goto L0076ee94;
    case 0x0076ee98u: goto L0076ee98;
    case 0x0076ee9cu: goto L0076ee9c;
    case 0x0076eea3u: goto L0076eea3;
    case 0x0076eea5u: goto L0076eea5;
    case 0x0076eea7u: goto L0076eea7;
    case 0x0076eec0u: goto L0076eec0;
    case 0x0076eec3u: goto L0076eec3;
    case 0x0076eec4u: goto L0076eec4;
    case 0x0076eec5u: goto L0076eec5;
    case 0x0076eec6u: goto L0076eec6;
    case 0x0076eec8u: goto L0076eec8;
    case 0x0076eecbu: goto L0076eecb;
    case 0x0076eeceu: goto L0076eece;
    case 0x0076eed1u: goto L0076eed1;
    case 0x0076eed2u: goto L0076eed2;
    case 0x0076eed3u: goto L0076eed3;
    case 0x0076eed4u: goto L0076eed4;
    case 0x0076eed8u: goto L0076eed8;
    case 0x0076eedbu: goto L0076eedb;
    case 0x0076eedeu: goto L0076eede;
    case 0x0076eee1u: goto L0076eee1;
    case 0x0076eee4u: goto L0076eee4;
    case 0x0076eee7u: goto L0076eee7;
    case 0x0076eee8u: goto L0076eee8;
    case 0x0076eee9u: goto L0076eee9;
    case 0x0076eeeau: goto L0076eeea;
    case 0x0076eeecu: goto L0076eeec;
    case 0x0076eeefu: goto L0076eeef;
    case 0x0076eef2u: goto L0076eef2;
    case 0x0076eef5u: goto L0076eef5;
    case 0x0076eef8u: goto L0076eef8;
    case 0x0076eefbu: goto L0076eefb;
    case 0x0076eefeu: goto L0076eefe;
    case 0x0076ef01u: goto L0076ef01;
    case 0x0076ef02u: goto L0076ef02;
    case 0x0076ef03u: goto L0076ef03;
    case 0x0076ef04u: goto L0076ef04;
    default:throw std::domain_error("recovery233 unsupported switch destination");}
  }
  L0076ee10: { // 0x76ee10: 8a4603 MOV AL,byte ptr [ESI + 0x3]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000003u)));
  }
  L0076ee13: { // 0x76ee13: 23d1 AND EDX,ECX
    s.dx = integer::logical((s.dx)&(s.cx),32,flags);
  }
  L0076ee15: { // 0x76ee15: 884703 MOV byte ptr [EDI + 0x3],AL
    m.w8((s.di+0x00000003u), (s.ax & 0xffu));
  }
  L0076ee18: { // 0x76ee18: 8a4602 MOV AL,byte ptr [ESI + 0x2]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000002u)));
  }
  L0076ee1b: { // 0x76ee1b: 884702 MOV byte ptr [EDI + 0x2],AL
    m.w8((s.di+0x00000002u), (s.ax & 0xffu));
  }
  L0076ee1e: { // 0x76ee1e: 8a4601 MOV AL,byte ptr [ESI + 0x1]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000001u)));
  }
  L0076ee21: { // 0x76ee21: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L0076ee24: { // 0x76ee24: 884701 MOV byte ptr [EDI + 0x1],AL
    m.w8((s.di+0x00000001u), (s.ax & 0xffu));
  }
  L0076ee27: { // 0x76ee27: 83ee03 SUB ESI,0x3
    s.si = integer::sub(s.si,0x00000003u,32,flags);
  }
  L0076ee2a: { // 0x76ee2a: 83ef03 SUB EDI,0x3
    s.di = integer::sub(s.di,0x00000003u,32,flags);
  }
  L0076ee2d: { // 0x76ee2d: 83f908 CMP ECX,0x8
    (void)integer::sub(s.cx,0x00000008u,32,flags);
  }
  L0076ee30: { // 0x76ee30: 0f825affffff JC 0x0076ed90
    if(integer::condition("JC",flags)) goto L0076ed90;
  }
  L0076ee36: { // 0x76ee36: fd STD
    flags |= 0x400u;
  }
  L0076ee37: { // 0x76ee37: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L0076ee39: { // 0x76ee39: fc CLD
    flags &= ~0x400u;
  }
  L0076ee3a: { // 0x76ee3a: ff2495b0ee7600 JMP dword ptr [EDX*0x4 + 0x76eeb0]
    switch(m.r32(((s.dx * 0x00000004u)+0x0076eeb0u))){
    case 0x0076ebd0u: goto L0076ebd0;
    case 0x0076ebd1u: goto L0076ebd1;
    case 0x0076ebd3u: goto L0076ebd3;
    case 0x0076ebd4u: goto L0076ebd4;
    case 0x0076ebd5u: goto L0076ebd5;
    case 0x0076ebd8u: goto L0076ebd8;
    case 0x0076ebdbu: goto L0076ebdb;
    case 0x0076ebdeu: goto L0076ebde;
    case 0x0076ebe0u: goto L0076ebe0;
    case 0x0076ebe2u: goto L0076ebe2;
    case 0x0076ebe4u: goto L0076ebe4;
    case 0x0076ebe6u: goto L0076ebe6;
    case 0x0076ebe8u: goto L0076ebe8;
    case 0x0076ebeau: goto L0076ebea;
    case 0x0076ebf0u: goto L0076ebf0;
    case 0x0076ebf6u: goto L0076ebf6;
    case 0x0076ebf8u: goto L0076ebf8;
    case 0x0076ebfbu: goto L0076ebfb;
    case 0x0076ebfeu: goto L0076ebfe;
    case 0x0076ec01u: goto L0076ec01;
    case 0x0076ec03u: goto L0076ec03;
    case 0x0076ec05u: goto L0076ec05;
    case 0x0076ec0cu: goto L0076ec0c;
    case 0x0076ec0eu: goto L0076ec0e;
    case 0x0076ec13u: goto L0076ec13;
    case 0x0076ec16u: goto L0076ec16;
    case 0x0076ec18u: goto L0076ec18;
    case 0x0076ec1bu: goto L0076ec1b;
    case 0x0076ec1du: goto L0076ec1d;
    case 0x0076ec24u: goto L0076ec24;
    case 0x0076ec2cu: goto L0076ec2c;
    case 0x0076ec40u: goto L0076ec40;
    case 0x0076ec42u: goto L0076ec42;
    case 0x0076ec44u: goto L0076ec44;
    case 0x0076ec46u: goto L0076ec46;
    case 0x0076ec49u: goto L0076ec49;
    case 0x0076ec4cu: goto L0076ec4c;
    case 0x0076ec4fu: goto L0076ec4f;
    case 0x0076ec52u: goto L0076ec52;
    case 0x0076ec55u: goto L0076ec55;
    case 0x0076ec58u: goto L0076ec58;
    case 0x0076ec5bu: goto L0076ec5b;
    case 0x0076ec5eu: goto L0076ec5e;
    case 0x0076ec60u: goto L0076ec60;
    case 0x0076ec62u: goto L0076ec62;
    case 0x0076ec6cu: goto L0076ec6c;
    case 0x0076ec6eu: goto L0076ec6e;
    case 0x0076ec70u: goto L0076ec70;
    case 0x0076ec72u: goto L0076ec72;
    case 0x0076ec75u: goto L0076ec75;
    case 0x0076ec78u: goto L0076ec78;
    case 0x0076ec7bu: goto L0076ec7b;
    case 0x0076ec7eu: goto L0076ec7e;
    case 0x0076ec81u: goto L0076ec81;
    case 0x0076ec84u: goto L0076ec84;
    case 0x0076ec86u: goto L0076ec86;
    case 0x0076ec88u: goto L0076ec88;
    case 0x0076ec90u: goto L0076ec90;
    case 0x0076ec92u: goto L0076ec92;
    case 0x0076ec94u: goto L0076ec94;
    case 0x0076ec96u: goto L0076ec96;
    case 0x0076ec97u: goto L0076ec97;
    case 0x0076ec9au: goto L0076ec9a;
    case 0x0076ec9bu: goto L0076ec9b;
    case 0x0076ec9eu: goto L0076ec9e;
    case 0x0076eca0u: goto L0076eca0;
    case 0x0076eca2u: goto L0076eca2;
    case 0x0076ecccu: goto L0076eccc;
    case 0x0076ecd0u: goto L0076ecd0;
    case 0x0076ecd4u: goto L0076ecd4;
    case 0x0076ecd8u: goto L0076ecd8;
    case 0x0076ecdcu: goto L0076ecdc;
    case 0x0076ece0u: goto L0076ece0;
    case 0x0076ece4u: goto L0076ece4;
    case 0x0076ece8u: goto L0076ece8;
    case 0x0076ececu: goto L0076ecec;
    case 0x0076ecf0u: goto L0076ecf0;
    case 0x0076ecf4u: goto L0076ecf4;
    case 0x0076ecf8u: goto L0076ecf8;
    case 0x0076ecfcu: goto L0076ecfc;
    case 0x0076ed00u: goto L0076ed00;
    case 0x0076ed04u: goto L0076ed04;
    case 0x0076ed0bu: goto L0076ed0b;
    case 0x0076ed0du: goto L0076ed0d;
    case 0x0076ed0fu: goto L0076ed0f;
    case 0x0076ed28u: goto L0076ed28;
    case 0x0076ed2bu: goto L0076ed2b;
    case 0x0076ed2cu: goto L0076ed2c;
    case 0x0076ed2du: goto L0076ed2d;
    case 0x0076ed2eu: goto L0076ed2e;
    case 0x0076ed30u: goto L0076ed30;
    case 0x0076ed32u: goto L0076ed32;
    case 0x0076ed34u: goto L0076ed34;
    case 0x0076ed37u: goto L0076ed37;
    case 0x0076ed38u: goto L0076ed38;
    case 0x0076ed39u: goto L0076ed39;
    case 0x0076ed3au: goto L0076ed3a;
    case 0x0076ed3cu: goto L0076ed3c;
    case 0x0076ed3eu: goto L0076ed3e;
    case 0x0076ed40u: goto L0076ed40;
    case 0x0076ed43u: goto L0076ed43;
    case 0x0076ed46u: goto L0076ed46;
    case 0x0076ed49u: goto L0076ed49;
    case 0x0076ed4au: goto L0076ed4a;
    case 0x0076ed4bu: goto L0076ed4b;
    case 0x0076ed4cu: goto L0076ed4c;
    case 0x0076ed50u: goto L0076ed50;
    case 0x0076ed52u: goto L0076ed52;
    case 0x0076ed54u: goto L0076ed54;
    case 0x0076ed57u: goto L0076ed57;
    case 0x0076ed5au: goto L0076ed5a;
    case 0x0076ed5du: goto L0076ed5d;
    case 0x0076ed60u: goto L0076ed60;
    case 0x0076ed63u: goto L0076ed63;
    case 0x0076ed64u: goto L0076ed64;
    case 0x0076ed65u: goto L0076ed65;
    case 0x0076ed66u: goto L0076ed66;
    case 0x0076ed68u: goto L0076ed68;
    case 0x0076ed6cu: goto L0076ed6c;
    case 0x0076ed70u: goto L0076ed70;
    case 0x0076ed76u: goto L0076ed76;
    case 0x0076ed78u: goto L0076ed78;
    case 0x0076ed7bu: goto L0076ed7b;
    case 0x0076ed7eu: goto L0076ed7e;
    case 0x0076ed81u: goto L0076ed81;
    case 0x0076ed83u: goto L0076ed83;
    case 0x0076ed84u: goto L0076ed84;
    case 0x0076ed86u: goto L0076ed86;
    case 0x0076ed87u: goto L0076ed87;
    case 0x0076ed90u: goto L0076ed90;
    case 0x0076ed92u: goto L0076ed92;
    case 0x0076ed9cu: goto L0076ed9c;
    case 0x0076ed9eu: goto L0076ed9e;
    case 0x0076eda3u: goto L0076eda3;
    case 0x0076eda6u: goto L0076eda6;
    case 0x0076eda8u: goto L0076eda8;
    case 0x0076edabu: goto L0076edab;
    case 0x0076edadu: goto L0076edad;
    case 0x0076edb4u: goto L0076edb4;
    case 0x0076edc8u: goto L0076edc8;
    case 0x0076edcbu: goto L0076edcb;
    case 0x0076edcdu: goto L0076edcd;
    case 0x0076edd0u: goto L0076edd0;
    case 0x0076edd1u: goto L0076edd1;
    case 0x0076edd4u: goto L0076edd4;
    case 0x0076edd5u: goto L0076edd5;
    case 0x0076edd8u: goto L0076edd8;
    case 0x0076eddau: goto L0076edda;
    case 0x0076eddbu: goto L0076eddb;
    case 0x0076edddu: goto L0076eddd;
    case 0x0076eddeu: goto L0076edde;
    case 0x0076ede8u: goto L0076ede8;
    case 0x0076edebu: goto L0076edeb;
    case 0x0076ededu: goto L0076eded;
    case 0x0076edf0u: goto L0076edf0;
    case 0x0076edf3u: goto L0076edf3;
    case 0x0076edf6u: goto L0076edf6;
    case 0x0076edf9u: goto L0076edf9;
    case 0x0076edfcu: goto L0076edfc;
    case 0x0076edffu: goto L0076edff;
    case 0x0076ee02u: goto L0076ee02;
    case 0x0076ee04u: goto L0076ee04;
    case 0x0076ee05u: goto L0076ee05;
    case 0x0076ee07u: goto L0076ee07;
    case 0x0076ee08u: goto L0076ee08;
    case 0x0076ee10u: goto L0076ee10;
    case 0x0076ee13u: goto L0076ee13;
    case 0x0076ee15u: goto L0076ee15;
    case 0x0076ee18u: goto L0076ee18;
    case 0x0076ee1bu: goto L0076ee1b;
    case 0x0076ee1eu: goto L0076ee1e;
    case 0x0076ee21u: goto L0076ee21;
    case 0x0076ee24u: goto L0076ee24;
    case 0x0076ee27u: goto L0076ee27;
    case 0x0076ee2au: goto L0076ee2a;
    case 0x0076ee2du: goto L0076ee2d;
    case 0x0076ee30u: goto L0076ee30;
    case 0x0076ee36u: goto L0076ee36;
    case 0x0076ee37u: goto L0076ee37;
    case 0x0076ee39u: goto L0076ee39;
    case 0x0076ee3au: goto L0076ee3a;
    case 0x0076ee64u: goto L0076ee64;
    case 0x0076ee68u: goto L0076ee68;
    case 0x0076ee6cu: goto L0076ee6c;
    case 0x0076ee70u: goto L0076ee70;
    case 0x0076ee74u: goto L0076ee74;
    case 0x0076ee78u: goto L0076ee78;
    case 0x0076ee7cu: goto L0076ee7c;
    case 0x0076ee80u: goto L0076ee80;
    case 0x0076ee84u: goto L0076ee84;
    case 0x0076ee88u: goto L0076ee88;
    case 0x0076ee8cu: goto L0076ee8c;
    case 0x0076ee90u: goto L0076ee90;
    case 0x0076ee94u: goto L0076ee94;
    case 0x0076ee98u: goto L0076ee98;
    case 0x0076ee9cu: goto L0076ee9c;
    case 0x0076eea3u: goto L0076eea3;
    case 0x0076eea5u: goto L0076eea5;
    case 0x0076eea7u: goto L0076eea7;
    case 0x0076eec0u: goto L0076eec0;
    case 0x0076eec3u: goto L0076eec3;
    case 0x0076eec4u: goto L0076eec4;
    case 0x0076eec5u: goto L0076eec5;
    case 0x0076eec6u: goto L0076eec6;
    case 0x0076eec8u: goto L0076eec8;
    case 0x0076eecbu: goto L0076eecb;
    case 0x0076eeceu: goto L0076eece;
    case 0x0076eed1u: goto L0076eed1;
    case 0x0076eed2u: goto L0076eed2;
    case 0x0076eed3u: goto L0076eed3;
    case 0x0076eed4u: goto L0076eed4;
    case 0x0076eed8u: goto L0076eed8;
    case 0x0076eedbu: goto L0076eedb;
    case 0x0076eedeu: goto L0076eede;
    case 0x0076eee1u: goto L0076eee1;
    case 0x0076eee4u: goto L0076eee4;
    case 0x0076eee7u: goto L0076eee7;
    case 0x0076eee8u: goto L0076eee8;
    case 0x0076eee9u: goto L0076eee9;
    case 0x0076eeeau: goto L0076eeea;
    case 0x0076eeecu: goto L0076eeec;
    case 0x0076eeefu: goto L0076eeef;
    case 0x0076eef2u: goto L0076eef2;
    case 0x0076eef5u: goto L0076eef5;
    case 0x0076eef8u: goto L0076eef8;
    case 0x0076eefbu: goto L0076eefb;
    case 0x0076eefeu: goto L0076eefe;
    case 0x0076ef01u: goto L0076ef01;
    case 0x0076ef02u: goto L0076ef02;
    case 0x0076ef03u: goto L0076ef03;
    case 0x0076ef04u: goto L0076ef04;
    default:throw std::domain_error("recovery233 unsupported switch destination");}
  }
  L0076ee64: { // 0x76ee64: 8b448e1c MOV EAX,dword ptr [ESI + ECX*0x4 + 0x1c]
    s.ax = m.r32((s.si+(s.cx * 0x00000004u)+0x0000001cu));
  }
  L0076ee68: { // 0x76ee68: 89448f1c MOV dword ptr [EDI + ECX*0x4 + 0x1c],EAX
    m.w32((s.di+(s.cx * 0x00000004u)+0x0000001cu), s.ax);
  }
  L0076ee6c: { // 0x76ee6c: 8b448e18 MOV EAX,dword ptr [ESI + ECX*0x4 + 0x18]
    s.ax = m.r32((s.si+(s.cx * 0x00000004u)+0x00000018u));
  }
  L0076ee70: { // 0x76ee70: 89448f18 MOV dword ptr [EDI + ECX*0x4 + 0x18],EAX
    m.w32((s.di+(s.cx * 0x00000004u)+0x00000018u), s.ax);
  }
  L0076ee74: { // 0x76ee74: 8b448e14 MOV EAX,dword ptr [ESI + ECX*0x4 + 0x14]
    s.ax = m.r32((s.si+(s.cx * 0x00000004u)+0x00000014u));
  }
  L0076ee78: { // 0x76ee78: 89448f14 MOV dword ptr [EDI + ECX*0x4 + 0x14],EAX
    m.w32((s.di+(s.cx * 0x00000004u)+0x00000014u), s.ax);
  }
  L0076ee7c: { // 0x76ee7c: 8b448e10 MOV EAX,dword ptr [ESI + ECX*0x4 + 0x10]
    s.ax = m.r32((s.si+(s.cx * 0x00000004u)+0x00000010u));
  }
  L0076ee80: { // 0x76ee80: 89448f10 MOV dword ptr [EDI + ECX*0x4 + 0x10],EAX
    m.w32((s.di+(s.cx * 0x00000004u)+0x00000010u), s.ax);
  }
  L0076ee84: { // 0x76ee84: 8b448e0c MOV EAX,dword ptr [ESI + ECX*0x4 + 0xc]
    s.ax = m.r32((s.si+(s.cx * 0x00000004u)+0x0000000cu));
  }
  L0076ee88: { // 0x76ee88: 89448f0c MOV dword ptr [EDI + ECX*0x4 + 0xc],EAX
    m.w32((s.di+(s.cx * 0x00000004u)+0x0000000cu), s.ax);
  }
  L0076ee8c: { // 0x76ee8c: 8b448e08 MOV EAX,dword ptr [ESI + ECX*0x4 + 0x8]
    s.ax = m.r32((s.si+(s.cx * 0x00000004u)+0x00000008u));
  }
  L0076ee90: { // 0x76ee90: 89448f08 MOV dword ptr [EDI + ECX*0x4 + 0x8],EAX
    m.w32((s.di+(s.cx * 0x00000004u)+0x00000008u), s.ax);
  }
  L0076ee94: { // 0x76ee94: 8b448e04 MOV EAX,dword ptr [ESI + ECX*0x4 + 0x4]
    s.ax = m.r32((s.si+(s.cx * 0x00000004u)+0x00000004u));
  }
  L0076ee98: { // 0x76ee98: 89448f04 MOV dword ptr [EDI + ECX*0x4 + 0x4],EAX
    m.w32((s.di+(s.cx * 0x00000004u)+0x00000004u), s.ax);
  }
  L0076ee9c: { // 0x76ee9c: 8d048d00000000 LEA EAX,[ECX*0x4 + 0x0]
    s.ax = ((s.cx * 0x00000004u)+0x00000000u);
  }
  L0076eea3: { // 0x76eea3: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L0076eea5: { // 0x76eea5: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L0076eea7: { // 0x76eea7: ff2495b0ee7600 JMP dword ptr [EDX*0x4 + 0x76eeb0]
    switch(m.r32(((s.dx * 0x00000004u)+0x0076eeb0u))){
    case 0x0076ebd0u: goto L0076ebd0;
    case 0x0076ebd1u: goto L0076ebd1;
    case 0x0076ebd3u: goto L0076ebd3;
    case 0x0076ebd4u: goto L0076ebd4;
    case 0x0076ebd5u: goto L0076ebd5;
    case 0x0076ebd8u: goto L0076ebd8;
    case 0x0076ebdbu: goto L0076ebdb;
    case 0x0076ebdeu: goto L0076ebde;
    case 0x0076ebe0u: goto L0076ebe0;
    case 0x0076ebe2u: goto L0076ebe2;
    case 0x0076ebe4u: goto L0076ebe4;
    case 0x0076ebe6u: goto L0076ebe6;
    case 0x0076ebe8u: goto L0076ebe8;
    case 0x0076ebeau: goto L0076ebea;
    case 0x0076ebf0u: goto L0076ebf0;
    case 0x0076ebf6u: goto L0076ebf6;
    case 0x0076ebf8u: goto L0076ebf8;
    case 0x0076ebfbu: goto L0076ebfb;
    case 0x0076ebfeu: goto L0076ebfe;
    case 0x0076ec01u: goto L0076ec01;
    case 0x0076ec03u: goto L0076ec03;
    case 0x0076ec05u: goto L0076ec05;
    case 0x0076ec0cu: goto L0076ec0c;
    case 0x0076ec0eu: goto L0076ec0e;
    case 0x0076ec13u: goto L0076ec13;
    case 0x0076ec16u: goto L0076ec16;
    case 0x0076ec18u: goto L0076ec18;
    case 0x0076ec1bu: goto L0076ec1b;
    case 0x0076ec1du: goto L0076ec1d;
    case 0x0076ec24u: goto L0076ec24;
    case 0x0076ec2cu: goto L0076ec2c;
    case 0x0076ec40u: goto L0076ec40;
    case 0x0076ec42u: goto L0076ec42;
    case 0x0076ec44u: goto L0076ec44;
    case 0x0076ec46u: goto L0076ec46;
    case 0x0076ec49u: goto L0076ec49;
    case 0x0076ec4cu: goto L0076ec4c;
    case 0x0076ec4fu: goto L0076ec4f;
    case 0x0076ec52u: goto L0076ec52;
    case 0x0076ec55u: goto L0076ec55;
    case 0x0076ec58u: goto L0076ec58;
    case 0x0076ec5bu: goto L0076ec5b;
    case 0x0076ec5eu: goto L0076ec5e;
    case 0x0076ec60u: goto L0076ec60;
    case 0x0076ec62u: goto L0076ec62;
    case 0x0076ec6cu: goto L0076ec6c;
    case 0x0076ec6eu: goto L0076ec6e;
    case 0x0076ec70u: goto L0076ec70;
    case 0x0076ec72u: goto L0076ec72;
    case 0x0076ec75u: goto L0076ec75;
    case 0x0076ec78u: goto L0076ec78;
    case 0x0076ec7bu: goto L0076ec7b;
    case 0x0076ec7eu: goto L0076ec7e;
    case 0x0076ec81u: goto L0076ec81;
    case 0x0076ec84u: goto L0076ec84;
    case 0x0076ec86u: goto L0076ec86;
    case 0x0076ec88u: goto L0076ec88;
    case 0x0076ec90u: goto L0076ec90;
    case 0x0076ec92u: goto L0076ec92;
    case 0x0076ec94u: goto L0076ec94;
    case 0x0076ec96u: goto L0076ec96;
    case 0x0076ec97u: goto L0076ec97;
    case 0x0076ec9au: goto L0076ec9a;
    case 0x0076ec9bu: goto L0076ec9b;
    case 0x0076ec9eu: goto L0076ec9e;
    case 0x0076eca0u: goto L0076eca0;
    case 0x0076eca2u: goto L0076eca2;
    case 0x0076ecccu: goto L0076eccc;
    case 0x0076ecd0u: goto L0076ecd0;
    case 0x0076ecd4u: goto L0076ecd4;
    case 0x0076ecd8u: goto L0076ecd8;
    case 0x0076ecdcu: goto L0076ecdc;
    case 0x0076ece0u: goto L0076ece0;
    case 0x0076ece4u: goto L0076ece4;
    case 0x0076ece8u: goto L0076ece8;
    case 0x0076ececu: goto L0076ecec;
    case 0x0076ecf0u: goto L0076ecf0;
    case 0x0076ecf4u: goto L0076ecf4;
    case 0x0076ecf8u: goto L0076ecf8;
    case 0x0076ecfcu: goto L0076ecfc;
    case 0x0076ed00u: goto L0076ed00;
    case 0x0076ed04u: goto L0076ed04;
    case 0x0076ed0bu: goto L0076ed0b;
    case 0x0076ed0du: goto L0076ed0d;
    case 0x0076ed0fu: goto L0076ed0f;
    case 0x0076ed28u: goto L0076ed28;
    case 0x0076ed2bu: goto L0076ed2b;
    case 0x0076ed2cu: goto L0076ed2c;
    case 0x0076ed2du: goto L0076ed2d;
    case 0x0076ed2eu: goto L0076ed2e;
    case 0x0076ed30u: goto L0076ed30;
    case 0x0076ed32u: goto L0076ed32;
    case 0x0076ed34u: goto L0076ed34;
    case 0x0076ed37u: goto L0076ed37;
    case 0x0076ed38u: goto L0076ed38;
    case 0x0076ed39u: goto L0076ed39;
    case 0x0076ed3au: goto L0076ed3a;
    case 0x0076ed3cu: goto L0076ed3c;
    case 0x0076ed3eu: goto L0076ed3e;
    case 0x0076ed40u: goto L0076ed40;
    case 0x0076ed43u: goto L0076ed43;
    case 0x0076ed46u: goto L0076ed46;
    case 0x0076ed49u: goto L0076ed49;
    case 0x0076ed4au: goto L0076ed4a;
    case 0x0076ed4bu: goto L0076ed4b;
    case 0x0076ed4cu: goto L0076ed4c;
    case 0x0076ed50u: goto L0076ed50;
    case 0x0076ed52u: goto L0076ed52;
    case 0x0076ed54u: goto L0076ed54;
    case 0x0076ed57u: goto L0076ed57;
    case 0x0076ed5au: goto L0076ed5a;
    case 0x0076ed5du: goto L0076ed5d;
    case 0x0076ed60u: goto L0076ed60;
    case 0x0076ed63u: goto L0076ed63;
    case 0x0076ed64u: goto L0076ed64;
    case 0x0076ed65u: goto L0076ed65;
    case 0x0076ed66u: goto L0076ed66;
    case 0x0076ed68u: goto L0076ed68;
    case 0x0076ed6cu: goto L0076ed6c;
    case 0x0076ed70u: goto L0076ed70;
    case 0x0076ed76u: goto L0076ed76;
    case 0x0076ed78u: goto L0076ed78;
    case 0x0076ed7bu: goto L0076ed7b;
    case 0x0076ed7eu: goto L0076ed7e;
    case 0x0076ed81u: goto L0076ed81;
    case 0x0076ed83u: goto L0076ed83;
    case 0x0076ed84u: goto L0076ed84;
    case 0x0076ed86u: goto L0076ed86;
    case 0x0076ed87u: goto L0076ed87;
    case 0x0076ed90u: goto L0076ed90;
    case 0x0076ed92u: goto L0076ed92;
    case 0x0076ed9cu: goto L0076ed9c;
    case 0x0076ed9eu: goto L0076ed9e;
    case 0x0076eda3u: goto L0076eda3;
    case 0x0076eda6u: goto L0076eda6;
    case 0x0076eda8u: goto L0076eda8;
    case 0x0076edabu: goto L0076edab;
    case 0x0076edadu: goto L0076edad;
    case 0x0076edb4u: goto L0076edb4;
    case 0x0076edc8u: goto L0076edc8;
    case 0x0076edcbu: goto L0076edcb;
    case 0x0076edcdu: goto L0076edcd;
    case 0x0076edd0u: goto L0076edd0;
    case 0x0076edd1u: goto L0076edd1;
    case 0x0076edd4u: goto L0076edd4;
    case 0x0076edd5u: goto L0076edd5;
    case 0x0076edd8u: goto L0076edd8;
    case 0x0076eddau: goto L0076edda;
    case 0x0076eddbu: goto L0076eddb;
    case 0x0076edddu: goto L0076eddd;
    case 0x0076eddeu: goto L0076edde;
    case 0x0076ede8u: goto L0076ede8;
    case 0x0076edebu: goto L0076edeb;
    case 0x0076ededu: goto L0076eded;
    case 0x0076edf0u: goto L0076edf0;
    case 0x0076edf3u: goto L0076edf3;
    case 0x0076edf6u: goto L0076edf6;
    case 0x0076edf9u: goto L0076edf9;
    case 0x0076edfcu: goto L0076edfc;
    case 0x0076edffu: goto L0076edff;
    case 0x0076ee02u: goto L0076ee02;
    case 0x0076ee04u: goto L0076ee04;
    case 0x0076ee05u: goto L0076ee05;
    case 0x0076ee07u: goto L0076ee07;
    case 0x0076ee08u: goto L0076ee08;
    case 0x0076ee10u: goto L0076ee10;
    case 0x0076ee13u: goto L0076ee13;
    case 0x0076ee15u: goto L0076ee15;
    case 0x0076ee18u: goto L0076ee18;
    case 0x0076ee1bu: goto L0076ee1b;
    case 0x0076ee1eu: goto L0076ee1e;
    case 0x0076ee21u: goto L0076ee21;
    case 0x0076ee24u: goto L0076ee24;
    case 0x0076ee27u: goto L0076ee27;
    case 0x0076ee2au: goto L0076ee2a;
    case 0x0076ee2du: goto L0076ee2d;
    case 0x0076ee30u: goto L0076ee30;
    case 0x0076ee36u: goto L0076ee36;
    case 0x0076ee37u: goto L0076ee37;
    case 0x0076ee39u: goto L0076ee39;
    case 0x0076ee3au: goto L0076ee3a;
    case 0x0076ee64u: goto L0076ee64;
    case 0x0076ee68u: goto L0076ee68;
    case 0x0076ee6cu: goto L0076ee6c;
    case 0x0076ee70u: goto L0076ee70;
    case 0x0076ee74u: goto L0076ee74;
    case 0x0076ee78u: goto L0076ee78;
    case 0x0076ee7cu: goto L0076ee7c;
    case 0x0076ee80u: goto L0076ee80;
    case 0x0076ee84u: goto L0076ee84;
    case 0x0076ee88u: goto L0076ee88;
    case 0x0076ee8cu: goto L0076ee8c;
    case 0x0076ee90u: goto L0076ee90;
    case 0x0076ee94u: goto L0076ee94;
    case 0x0076ee98u: goto L0076ee98;
    case 0x0076ee9cu: goto L0076ee9c;
    case 0x0076eea3u: goto L0076eea3;
    case 0x0076eea5u: goto L0076eea5;
    case 0x0076eea7u: goto L0076eea7;
    case 0x0076eec0u: goto L0076eec0;
    case 0x0076eec3u: goto L0076eec3;
    case 0x0076eec4u: goto L0076eec4;
    case 0x0076eec5u: goto L0076eec5;
    case 0x0076eec6u: goto L0076eec6;
    case 0x0076eec8u: goto L0076eec8;
    case 0x0076eecbu: goto L0076eecb;
    case 0x0076eeceu: goto L0076eece;
    case 0x0076eed1u: goto L0076eed1;
    case 0x0076eed2u: goto L0076eed2;
    case 0x0076eed3u: goto L0076eed3;
    case 0x0076eed4u: goto L0076eed4;
    case 0x0076eed8u: goto L0076eed8;
    case 0x0076eedbu: goto L0076eedb;
    case 0x0076eedeu: goto L0076eede;
    case 0x0076eee1u: goto L0076eee1;
    case 0x0076eee4u: goto L0076eee4;
    case 0x0076eee7u: goto L0076eee7;
    case 0x0076eee8u: goto L0076eee8;
    case 0x0076eee9u: goto L0076eee9;
    case 0x0076eeeau: goto L0076eeea;
    case 0x0076eeecu: goto L0076eeec;
    case 0x0076eeefu: goto L0076eeef;
    case 0x0076eef2u: goto L0076eef2;
    case 0x0076eef5u: goto L0076eef5;
    case 0x0076eef8u: goto L0076eef8;
    case 0x0076eefbu: goto L0076eefb;
    case 0x0076eefeu: goto L0076eefe;
    case 0x0076ef01u: goto L0076ef01;
    case 0x0076ef02u: goto L0076ef02;
    case 0x0076ef03u: goto L0076ef03;
    case 0x0076ef04u: goto L0076ef04;
    default:throw std::domain_error("recovery233 unsupported switch destination");}
  }
  L0076eec0: { // 0x76eec0: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L0076eec3: { // 0x76eec3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076eec4: { // 0x76eec4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076eec5: { // 0x76eec5: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L0076eec6: { // 0x76eec6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076eec8: { // 0x76eec8: 8a4603 MOV AL,byte ptr [ESI + 0x3]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000003u)));
  }
  L0076eecb: { // 0x76eecb: 884703 MOV byte ptr [EDI + 0x3],AL
    m.w8((s.di+0x00000003u), (s.ax & 0xffu));
  }
  L0076eece: { // 0x76eece: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L0076eed1: { // 0x76eed1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076eed2: { // 0x76eed2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076eed3: { // 0x76eed3: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L0076eed4: { // 0x76eed4: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076eed8: { // 0x76eed8: 8a4603 MOV AL,byte ptr [ESI + 0x3]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000003u)));
  }
  L0076eedb: { // 0x76eedb: 884703 MOV byte ptr [EDI + 0x3],AL
    m.w8((s.di+0x00000003u), (s.ax & 0xffu));
  }
  L0076eede: { // 0x76eede: 8a4602 MOV AL,byte ptr [ESI + 0x2]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000002u)));
  }
  L0076eee1: { // 0x76eee1: 884702 MOV byte ptr [EDI + 0x2],AL
    m.w8((s.di+0x00000002u), (s.ax & 0xffu));
  }
  L0076eee4: { // 0x76eee4: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L0076eee7: { // 0x76eee7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076eee8: { // 0x76eee8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076eee9: { // 0x76eee9: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L0076eeea: { // 0x76eeea: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076eeec: { // 0x76eeec: 8a4603 MOV AL,byte ptr [ESI + 0x3]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000003u)));
  }
  L0076eeef: { // 0x76eeef: 884703 MOV byte ptr [EDI + 0x3],AL
    m.w8((s.di+0x00000003u), (s.ax & 0xffu));
  }
  L0076eef2: { // 0x76eef2: 8a4602 MOV AL,byte ptr [ESI + 0x2]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000002u)));
  }
  L0076eef5: { // 0x76eef5: 884702 MOV byte ptr [EDI + 0x2],AL
    m.w8((s.di+0x00000002u), (s.ax & 0xffu));
  }
  L0076eef8: { // 0x76eef8: 8a4601 MOV AL,byte ptr [ESI + 0x1]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000001u)));
  }
  L0076eefb: { // 0x76eefb: 884701 MOV byte ptr [EDI + 0x1],AL
    m.w8((s.di+0x00000001u), (s.ax & 0xffu));
  }
  L0076eefe: { // 0x76eefe: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L0076ef01: { // 0x76ef01: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076ef02: { // 0x76ef02: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076ef03: { // 0x76ef03: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L0076ef04: { // 0x76ef04: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_001a6450(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005a6450: { // 0x5a6450: 81ec14010000 SUB ESP,0x114
    f.sp = integer::sub(f.sp,0x00000114u,32,flags);
  }
  L005a6456: { // 0x5a6456: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005a6457: { // 0x5a6457: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005a6458: { // 0x5a6458: 8bac2428010000 MOV EBP,dword ptr [ESP + 0x128]
    s.bp = m.r32((f.sp+0x00000128u));
  }
  L005a645f: { // 0x5a645f: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L005a6463: { // 0x5a6463: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005a6464: { // 0x5a6464: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L005a6466: { // 0x5a6466: 8d14ad00000000 LEA EDX,[EBP*0x4 + 0x0]
    s.dx = ((s.bp * 0x00000004u)+0x00000000u);
  }
  L005a646d: { // 0x5a646d: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005a646e: { // 0x5a646e: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L005a6470: { // 0x5a6470: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005a6472: { // 0x5a6472: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L005a6474: { // 0x5a6474: 8bfe MOV EDI,ESI
    s.di = s.si;
  }
  L005a6476: { // 0x5a6476: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L005a6479: { // 0x5a6479: f3ab STOSD.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::count);
  }
  L005a647b: { // 0x5a647b: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L005a647d: { // 0x5a647d: 89742410 MOV dword ptr [ESP + 0x10],ESI
    m.w32((f.sp+0x00000010u), s.si);
  }
  L005a6481: { // 0x5a6481: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  L005a6484: { // 0x5a6484: f3aa STOSB.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,8u,Repeat::count);
  }
  L005a6486: { // 0x5a6486: 8b842428010000 MOV EAX,dword ptr [ESP + 0x128]
    s.ax = m.r32((f.sp+0x00000128u));
  }
  L005a648d: { // 0x5a648d: c70601000000 MOV dword ptr [ESI],0x1
    m.w32((s.si), 0x00000001u);
  }
  L005a6493: { // 0x5a6493: 833800 CMP dword ptr [EAX],0x0
    (void)integer::sub(m.r32((s.ax)),0x00000000u,32,flags);
  }
  L005a6496: { // 0x5a6496: 755f JNZ 0x005a64f7
    if(integer::condition("JNZ",flags)) goto L005a64f7;
  }
  L005a6498: { // 0x5a6498: 8b7402fc MOV ESI,dword ptr [EDX + EAX*0x1 + -0x4]
    s.si = m.r32((s.dx+(s.ax * 0x00000001u)-0x00000004u));
  }
  L005a649c: { // 0x5a649c: 8d4402fc LEA EAX,[EDX + EAX*0x1 + -0x4]
    s.ax = (s.dx+(s.ax * 0x00000001u)-0x00000004u);
  }
  L005a64a0: { // 0x5a64a0: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L005a64a2: { // 0x5a64a2: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L005a64a4: { // 0x5a64a4: 750d JNZ 0x005a64b3
    if(integer::condition("JNZ",flags)) goto L005a64b3;
  }
  L005a64a6: { // 0x5a64a6: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L005a64a7: { // 0x5a64a7: 740a JZ 0x005a64b3
    if(integer::condition("JZ",flags)) goto L005a64b3;
  }
  L005a64a9: { // 0x5a64a9: 8b70fc MOV ESI,dword ptr [EAX + -0x4]
    s.si = m.r32((s.ax-0x00000004u));
  }
  L005a64ac: { // 0x5a64ac: 83e804 SUB EAX,0x4
    s.ax = integer::sub(s.ax,0x00000004u,32,flags);
  }
  L005a64af: { // 0x5a64af: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L005a64b1: { // 0x5a64b1: 74f3 JZ 0x005a64a6
    if(integer::condition("JZ",flags)) goto L005a64a6;
  }
  L005a64b3: { // 0x5a64b3: 83f901 CMP ECX,0x1
    (void)integer::sub(s.cx,0x00000001u,32,flags);
  }
  L005a64b6: { // 0x5a64b6: 7f3f JG 0x005a64f7
    if(integer::condition("JG",flags)) goto L005a64f7;
  }
  L005a64b8: { // 0x5a64b8: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L005a64bc: { // 0x5a64bc: 833800 CMP dword ptr [EAX],0x0
    (void)integer::sub(m.r32((s.ax)),0x00000000u,32,flags);
  }
  L005a64bf: { // 0x5a64bf: 0f85eb020000 JNZ 0x005a67b0
    if(integer::condition("JNZ",flags)) goto L005a67b0;
  }
  L005a64c5: { // 0x5a64c5: 8b4c02fc MOV ECX,dword ptr [EDX + EAX*0x1 + -0x4]
    s.cx = m.r32((s.dx+(s.ax * 0x00000001u)-0x00000004u));
  }
  L005a64c9: { // 0x5a64c9: 8d4402fc LEA EAX,[EDX + EAX*0x1 + -0x4]
    s.ax = (s.dx+(s.ax * 0x00000001u)-0x00000004u);
  }
  L005a64cd: { // 0x5a64cd: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005a64cf: { // 0x5a64cf: 750d JNZ 0x005a64de
    if(integer::condition("JNZ",flags)) goto L005a64de;
  }
  L005a64d1: { // 0x5a64d1: 4d DEC EBP
    s.bp = integer::decrement(s.bp,32,flags);
  }
  L005a64d2: { // 0x5a64d2: 740a JZ 0x005a64de
    if(integer::condition("JZ",flags)) goto L005a64de;
  }
  L005a64d4: { // 0x5a64d4: 8b48fc MOV ECX,dword ptr [EAX + -0x4]
    s.cx = m.r32((s.ax-0x00000004u));
  }
  L005a64d7: { // 0x5a64d7: 83e804 SUB EAX,0x4
    s.ax = integer::sub(s.ax,0x00000004u,32,flags);
  }
  L005a64da: { // 0x5a64da: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005a64dc: { // 0x5a64dc: 74f3 JZ 0x005a64d1
    if(integer::condition("JZ",flags)) goto L005a64d1;
  }
  L005a64de: { // 0x5a64de: 83fd01 CMP EBP,0x1
    (void)integer::sub(s.bp,0x00000001u,32,flags);
  }
  L005a64e1: { // 0x5a64e1: 0f8fc9020000 JG 0x005a67b0
    if(integer::condition("JG",flags)) goto L005a67b0;
  }
  L005a64e7: { // 0x5a64e7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005a64e8: { // 0x5a64e8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005a64e9: { // 0x5a64e9: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005a64ea: { // 0x5a64ea: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L005a64ed: { // 0x5a64ed: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005a64ee: { // 0x5a64ee: 81c414010000 ADD ESP,0x114
    f.sp = integer::add(f.sp,0x00000114u,32,flags);
  }
  L005a64f4: { // 0x5a64f4: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L005a64f7: { // 0x5a64f7: 8bb4242c010000 MOV ESI,dword ptr [ESP + 0x12c]
    s.si = m.r32((f.sp+0x0000012cu));
  }
  L005a64fe: { // 0x5a64fe: 833e00 CMP dword ptr [ESI],0x0
    (void)integer::sub(m.r32((s.si)),0x00000000u,32,flags);
  }
  L005a6501: { // 0x5a6501: 7532 JNZ 0x005a6535
    if(integer::condition("JNZ",flags)) goto L005a6535;
  }
  L005a6503: { // 0x5a6503: 8b7c32fc MOV EDI,dword ptr [EDX + ESI*0x1 + -0x4]
    s.di = m.r32((s.dx+(s.si * 0x00000001u)-0x00000004u));
  }
  L005a6507: { // 0x5a6507: 8d4432fc LEA EAX,[EDX + ESI*0x1 + -0x4]
    s.ax = (s.dx+(s.si * 0x00000001u)-0x00000004u);
  }
  L005a650b: { // 0x5a650b: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L005a650d: { // 0x5a650d: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L005a650f: { // 0x5a650f: 750d JNZ 0x005a651e
    if(integer::condition("JNZ",flags)) goto L005a651e;
  }
  L005a6511: { // 0x5a6511: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L005a6512: { // 0x5a6512: 740a JZ 0x005a651e
    if(integer::condition("JZ",flags)) goto L005a651e;
  }
  L005a6514: { // 0x5a6514: 8b78fc MOV EDI,dword ptr [EAX + -0x4]
    s.di = m.r32((s.ax-0x00000004u));
  }
  L005a6517: { // 0x5a6517: 83e804 SUB EAX,0x4
    s.ax = integer::sub(s.ax,0x00000004u,32,flags);
  }
  L005a651a: { // 0x5a651a: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L005a651c: { // 0x5a651c: 74f3 JZ 0x005a6511
    if(integer::condition("JZ",flags)) goto L005a6511;
  }
  L005a651e: { // 0x5a651e: 83f901 CMP ECX,0x1
    (void)integer::sub(s.cx,0x00000001u,32,flags);
  }
  L005a6521: { // 0x5a6521: 7f12 JG 0x005a6535
    if(integer::condition("JG",flags)) goto L005a6535;
  }
  L005a6523: { // 0x5a6523: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005a6524: { // 0x5a6524: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005a6525: { // 0x5a6525: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005a6526: { // 0x5a6526: b8feffffff MOV EAX,0xfffffffe
    s.ax = 0xfffffffeu;
  }
  L005a652b: { // 0x5a652b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005a652c: { // 0x5a652c: 81c414010000 ADD ESP,0x114
    f.sp = integer::add(f.sp,0x00000114u,32,flags);
  }
  L005a6532: { // 0x5a6532: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L005a6535: { // 0x5a6535: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L005a6539: { // 0x5a6539: 8d5c32fc LEA EBX,[EDX + ESI*0x1 + -0x4]
    s.bx = (s.dx+(s.si * 0x00000001u)-0x00000004u);
  }
  L005a653d: { // 0x5a653d: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L005a653f: { // 0x5a653f: 8d7c02fc LEA EDI,[EDX + EAX*0x1 + -0x4]
    s.di = (s.dx+(s.ax * 0x00000001u)-0x00000004u);
  }
  L005a6543: { // 0x5a6543: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L005a6545: { // 0x5a6545: 8b30 MOV ESI,dword ptr [EAX]
    s.si = m.r32((s.ax));
  }
  L005a6547: { // 0x5a6547: 3937 CMP dword ptr [EDI],ESI
    (void)integer::sub(m.r32((s.di)),s.si,32,flags);
  }
  L005a6549: { // 0x5a6549: 7214 JC 0x005a655f
    if(integer::condition("JC",flags)) goto L005a655f;
  }
  L005a654b: { // 0x5a654b: 2bfb SUB EDI,EBX
    s.di = integer::sub(s.di,s.bx,32,flags);
  }
  L005a654d: { // 0x5a654d: 393407 CMP dword ptr [EDI + EAX*0x1],ESI
    (void)integer::sub(m.r32((s.di+(s.ax * 0x00000001u))),s.si,32,flags);
  }
  L005a6550: { // 0x5a6550: 773e JA 0x005a6590
    if(integer::condition("JA",flags)) goto L005a6590;
  }
  L005a6552: { // 0x5a6552: 83e804 SUB EAX,0x4
    s.ax = integer::sub(s.ax,0x00000004u,32,flags);
  }
  L005a6555: { // 0x5a6555: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L005a6556: { // 0x5a6556: 7438 JZ 0x005a6590
    if(integer::condition("JZ",flags)) goto L005a6590;
  }
  L005a6558: { // 0x5a6558: 8b30 MOV ESI,dword ptr [EAX]
    s.si = m.r32((s.ax));
  }
  L005a655a: { // 0x5a655a: 393407 CMP dword ptr [EDI + EAX*0x1],ESI
    (void)integer::sub(m.r32((s.di+(s.ax * 0x00000001u))),s.si,32,flags);
  }
  L005a655d: { // 0x5a655d: 73f1 JNC 0x005a6550
    if(integer::condition("JNC",flags)) goto L005a6550;
  }
  L005a655f: { // 0x5a655f: 8b842428010000 MOV EAX,dword ptr [ESP + 0x128]
    s.ax = m.r32((f.sp+0x00000128u));
  }
  L005a6566: { // 0x5a6566: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L005a6568: { // 0x5a6568: 8b7c02fc MOV EDI,dword ptr [EDX + EAX*0x1 + -0x4]
    s.di = m.r32((s.dx+(s.ax * 0x00000001u)-0x00000004u));
  }
  L005a656c: { // 0x5a656c: 8d7402fc LEA ESI,[EDX + EAX*0x1 + -0x4]
    s.si = (s.dx+(s.ax * 0x00000001u)-0x00000004u);
  }
  L005a6570: { // 0x5a6570: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L005a6572: { // 0x5a6572: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L005a6574: { // 0x5a6574: 3bfa CMP EDI,EDX
    (void)integer::sub(s.di,s.dx,32,flags);
  }
  L005a6576: { // 0x5a6576: 723c JC 0x005a65b4
    if(integer::condition("JC",flags)) goto L005a65b4;
  }
  L005a6578: { // 0x5a6578: 2bf3 SUB ESI,EBX
    s.si = integer::sub(s.si,s.bx,32,flags);
  }
  L005a657a: { // 0x5a657a: 391406 CMP dword ptr [ESI + EAX*0x1],EDX
    (void)integer::sub(m.r32((s.si+(s.ax * 0x00000001u))),s.dx,32,flags);
  }
  L005a657d: { // 0x5a657d: 7723 JA 0x005a65a2
    if(integer::condition("JA",flags)) goto L005a65a2;
  }
  L005a657f: { // 0x5a657f: 83e804 SUB EAX,0x4
    s.ax = integer::sub(s.ax,0x00000004u,32,flags);
  }
  L005a6582: { // 0x5a6582: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L005a6583: { // 0x5a6583: 741d JZ 0x005a65a2
    if(integer::condition("JZ",flags)) goto L005a65a2;
  }
  L005a6585: { // 0x5a6585: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L005a6587: { // 0x5a6587: 8b3c06 MOV EDI,dword ptr [ESI + EAX*0x1]
    s.di = m.r32((s.si+(s.ax * 0x00000001u)));
  }
  L005a658a: { // 0x5a658a: 3bfa CMP EDI,EDX
    (void)integer::sub(s.di,s.dx,32,flags);
  }
  L005a658c: { // 0x5a658c: 73ef JNC 0x005a657d
    if(integer::condition("JNC",flags)) goto L005a657d;
  }
  L005a658e: { // 0x5a658e: eb24 JMP 0x005a65b4
    goto L005a65b4;
  }
  L005a6590: { // 0x5a6590: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005a6591: { // 0x5a6591: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005a6592: { // 0x5a6592: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005a6593: { // 0x5a6593: b8fdffffff MOV EAX,0xfffffffd
    s.ax = 0xfffffffdu;
  }
  L005a6598: { // 0x5a6598: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005a6599: { // 0x5a6599: 81c414010000 ADD ESP,0x114
    f.sp = integer::add(f.sp,0x00000114u,32,flags);
  }
  L005a659f: { // 0x5a659f: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L005a65a2: { // 0x5a65a2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005a65a3: { // 0x5a65a3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005a65a4: { // 0x5a65a4: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005a65a5: { // 0x5a65a5: b8fcffffff MOV EAX,0xfffffffc
    s.ax = 0xfffffffcu;
  }
  L005a65aa: { // 0x5a65aa: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005a65ab: { // 0x5a65ab: 81c414010000 ADD ESP,0x114
    f.sp = integer::add(f.sp,0x00000114u,32,flags);
  }
  L005a65b1: { // 0x5a65b1: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L005a65b4: { // 0x5a65b4: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L005a65b6: { // 0x5a65b6: 8bf5 MOV ESI,EBP
    s.si = s.bp;
  }
  L005a65b8: { // 0x5a65b8: 8974241c MOV dword ptr [ESP + 0x1c],ESI
    m.w32((f.sp+0x0000001cu), s.si);
  }
  L005a65bc: { // 0x5a65bc: 833800 CMP dword ptr [EAX],0x0
    (void)integer::sub(m.r32((s.ax)),0x00000000u,32,flags);
  }
  L005a65bf: { // 0x5a65bf: 7511 JNZ 0x005a65d2
    if(integer::condition("JNZ",flags)) goto L005a65d2;
  }
  L005a65c1: { // 0x5a65c1: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L005a65c2: { // 0x5a65c2: 740a JZ 0x005a65ce
    if(integer::condition("JZ",flags)) goto L005a65ce;
  }
  L005a65c4: { // 0x5a65c4: 8b48fc MOV ECX,dword ptr [EAX + -0x4]
    s.cx = m.r32((s.ax-0x00000004u));
  }
  L005a65c7: { // 0x5a65c7: 83e804 SUB EAX,0x4
    s.ax = integer::sub(s.ax,0x00000004u,32,flags);
  }
  L005a65ca: { // 0x5a65ca: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005a65cc: { // 0x5a65cc: 74f3 JZ 0x005a65c1
    if(integer::condition("JZ",flags)) goto L005a65c1;
  }
  L005a65ce: { // 0x5a65ce: 8974241c MOV dword ptr [ESP + 0x1c],ESI
    m.w32((f.sp+0x0000001cu), s.si);
  }
  L005a65d2: { // 0x5a65d2: 8b8c242c010000 MOV ECX,dword ptr [ESP + 0x12c]
    s.cx = m.r32((f.sp+0x0000012cu));
  }
  L005a65d9: { // 0x5a65d9: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L005a65db: { // 0x5a65db: e830f8ffff CALL 0x005a5e10
    s.arithmetic_flags=flags; invoke(m,s,f,0x005a5e10u,5924320u); flags=s.arithmetic_flags;
  }
  L005a65e0: { // 0x5a65e0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005a65e2: { // 0x5a65e2: 7412 JZ 0x005a65f6
    if(integer::condition("JZ",flags)) goto L005a65f6;
  }
  L005a65e4: { // 0x5a65e4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005a65e5: { // 0x5a65e5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005a65e6: { // 0x5a65e6: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005a65e7: { // 0x5a65e7: b8fbffffff MOV EAX,0xfffffffb
    s.ax = 0xfffffffbu;
  }
  L005a65ec: { // 0x5a65ec: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005a65ed: { // 0x5a65ed: 81c414010000 ADD ESP,0x114
    f.sp = integer::add(f.sp,0x00000114u,32,flags);
  }
  L005a65f3: { // 0x5a65f3: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L005a65f6: { // 0x5a65f6: 8bac2428010000 MOV EBP,dword ptr [ESP + 0x128]
    s.bp = m.r32((f.sp+0x00000128u));
  }
  L005a65fd: { // 0x5a65fd: 8d3cb500000000 LEA EDI,[ESI*0x4 + 0x0]
    s.di = ((s.si * 0x00000004u)+0x00000000u);
  }
  L005a6604: { // 0x5a6604: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005a6606: { // 0x5a6606: 897c2420 MOV dword ptr [ESP + 0x20],EDI
    m.w32((f.sp+0x00000020u), s.di);
  }
  L005a660a: { // 0x5a660a: 8b542ffc MOV EDX,dword ptr [EDI + EBP*0x1 + -0x4]
    s.dx = m.r32((s.di+(s.bp * 0x00000001u)-0x00000004u));
  }
  L005a660e: { // 0x5a660e: 8d442ffc LEA EAX,[EDI + EBP*0x1 + -0x4]
    s.ax = (s.di+(s.bp * 0x00000001u)-0x00000004u);
  }
  L005a6612: { // 0x5a6612: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L005a6614: { // 0x5a6614: 750d JNZ 0x005a6623
    if(integer::condition("JNZ",flags)) goto L005a6623;
  }
  L005a6616: { // 0x5a6616: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L005a6617: { // 0x5a6617: 740e JZ 0x005a6627
    if(integer::condition("JZ",flags)) goto L005a6627;
  }
  L005a6619: { // 0x5a6619: 8b50fc MOV EDX,dword ptr [EAX + -0x4]
    s.dx = m.r32((s.ax-0x00000004u));
  }
  L005a661c: { // 0x5a661c: 83e804 SUB EAX,0x4
    s.ax = integer::sub(s.ax,0x00000004u,32,flags);
  }
  L005a661f: { // 0x5a661f: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L005a6621: { // 0x5a6621: 74f3 JZ 0x005a6616
    if(integer::condition("JZ",flags)) goto L005a6616;
  }
  L005a6623: { // 0x5a6623: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005a6625: { // 0x5a6625: 7504 JNZ 0x005a662b
    if(integer::condition("JNZ",flags)) goto L005a662b;
  }
  L005a6627: { // 0x5a6627: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L005a6629: { // 0x5a6629: eb1b JMP 0x005a6646
    goto L005a6646;
  }
  L005a662b: { // 0x5a662b: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L005a662d: { // 0x5a662d: 8b4c8dfc MOV ECX,dword ptr [EBP + ECX*0x4 + -0x4]
    s.cx = m.r32((s.bp+(s.cx * 0x00000004u)-0x00000004u));
  }
  L005a6631: { // 0x5a6631: ba00000080 MOV EDX,0x80000000
    s.dx = 0x80000000u;
  }
  L005a6636: { // 0x5a6636: c1e005 SHL EAX,0x5
    s.ax = integer::shift(s.ax,0x00000005u,32,flags,integer::Shift::left);
  }
  L005a6639: { // 0x5a6639: 85ca TEST EDX,ECX
    (void)integer::logical((s.dx)&(s.cx),32,flags);
  }
  L005a663b: { // 0x5a663b: 7507 JNZ 0x005a6644
    if(integer::condition("JNZ",flags)) goto L005a6644;
  }
  L005a663d: { // 0x5a663d: d1ea SHR EDX,0x1
    s.dx = integer::shift(s.dx,0x00000001u,32,flags,integer::Shift::right);
  }
  L005a663f: { // 0x5a663f: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L005a6640: { // 0x5a6640: 85ca TEST EDX,ECX
    (void)integer::logical((s.dx)&(s.cx),32,flags);
  }
  L005a6642: { // 0x5a6642: 74f9 JZ 0x005a663d
    if(integer::condition("JZ",flags)) goto L005a663d;
  }
  L005a6644: { // 0x5a6644: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L005a6646: { // 0x5a6646: 8d461f LEA EAX,[ESI + 0x1f]
    s.ax = (s.si+0x0000001fu);
  }
  L005a6649: { // 0x5a6649: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L005a664a: { // 0x5a664a: 83e21f AND EDX,0x1f
    s.dx = integer::logical((s.dx)&(0x0000001fu),32,flags);
  }
  L005a664d: { // 0x5a664d: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L005a664f: { // 0x5a664f: c1f805 SAR EAX,0x5
    s.ax = integer::shift(s.ax,0x00000005u,32,flags,integer::Shift::arithmetic_right);
  }
  L005a6652: { // 0x5a6652: 0f8458010000 JZ 0x005a67b0
    if(integer::condition("JZ",flags)) goto L005a67b0;
  }
  L005a6658: { // 0x5a6658: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L005a665a: { // 0x5a665a: 7504 JNZ 0x005a6660
    if(integer::condition("JNZ",flags)) goto L005a6660;
  }
  L005a665c: { // 0x5a665c: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L005a665e: { // 0x5a665e: eb17 JMP 0x005a6677
    goto L005a6677;
  }
  L005a6660: { // 0x5a6660: 8d4eff LEA ECX,[ESI + -0x1]
    s.cx = (s.si-0x00000001u);
  }
  L005a6663: { // 0x5a6663: 81e11f000080 AND ECX,0x8000001f
    s.cx = integer::logical((s.cx)&(0x8000001fu),32,flags);
  }
  L005a6669: { // 0x5a6669: 7905 JNS 0x005a6670
    if(integer::condition("JNS",flags)) goto L005a6670;
  }
  L005a666b: { // 0x5a666b: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L005a666c: { // 0x5a666c: 83c9e0 OR ECX,0xffffffe0
    s.cx = integer::logical((s.cx)|(0xffffffe0u),32,flags);
  }
  L005a666f: { // 0x5a666f: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L005a6670: { // 0x5a6670: bb01000000 MOV EBX,0x1
    s.bx = 0x00000001u;
  }
  L005a6675: { // 0x5a6675: d3e3 SHL EBX,CL
    s.bx = integer::shift(s.bx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L005a6677: { // 0x5a6677: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L005a667b: { // 0x5a667b: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005a667d: { // 0x5a667d: 8d6c85fc LEA EBP,[EBP + EAX*0x4 + -0x4]
    s.bp = (s.bp+(s.ax * 0x00000004u)-0x00000004u);
  }
  L005a6681: { // 0x5a6681: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L005a6682: { // 0x5a6682: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L005a6684: { // 0x5a6684: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L005a6688: { // 0x5a6688: 8b742418 MOV ESI,dword ptr [ESP + 0x18]
    s.si = m.r32((f.sp+0x00000018u));
  }
  L005a668c: { // 0x5a668c: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L005a668e: { // 0x5a668e: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L005a6691: { // 0x5a6691: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L005a6693: { // 0x5a6693: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L005a6695: { // 0x5a6695: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  L005a6698: { // 0x5a6698: d1eb SHR EBX,0x1
    s.bx = integer::shift(s.bx,0x00000001u,32,flags,integer::Shift::right);
  }
  L005a669a: { // 0x5a669a: f3a4 MOVSB.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::count);
  }
  L005a669c: { // 0x5a669c: 7508 JNZ 0x005a66a6
    if(integer::condition("JNZ",flags)) goto L005a66a6;
  }
  L005a669e: { // 0x5a669e: bb00000080 MOV EBX,0x80000000
    s.bx = 0x80000000u;
  }
  L005a66a3: { // 0x5a66a3: 83ed04 SUB EBP,0x4
    s.bp = integer::sub(s.bp,0x00000004u,32,flags);
  }
  L005a66a6: { // 0x5a66a6: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L005a66aa: { // 0x5a66aa: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L005a66ac: { // 0x5a66ac: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L005a66ad: { // 0x5a66ad: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005a66af: { // 0x5a66af: 7465 JZ 0x005a6716
    if(integer::condition("JZ",flags)) goto L005a6716;
  }
  L005a66b1: { // 0x5a66b1: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L005a66b2: { // 0x5a66b2: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L005a66b6: { // 0x5a66b6: eb04 JMP 0x005a66bc
    goto L005a66bc;
  }
  L005a66b8: { // 0x5a66b8: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L005a66bc: { // 0x5a66bc: 8b74241c MOV ESI,dword ptr [ESP + 0x1c]
    s.si = m.r32((f.sp+0x0000001cu));
  }
  L005a66c0: { // 0x5a66c0: 8d4c2424 LEA ECX,[ESP + 0x24]
    s.cx = (f.sp+0x00000024u);
  }
  L005a66c4: { // 0x5a66c4: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005a66c5: { // 0x5a66c5: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005a66c6: { // 0x5a66c6: e825f9ffff CALL 0x005a5ff0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005a5ff0u,5924555u); flags=s.arithmetic_flags;
  }
  L005a66cb: { // 0x5a66cb: 855d00 TEST dword ptr [EBP],EBX
    (void)integer::logical((m.r32((s.bp)))&(s.bx),32,flags);
  }
  L005a66ce: { // 0x5a66ce: 7415 JZ 0x005a66e5
    if(integer::condition("JZ",flags)) goto L005a66e5;
  }
  L005a66d0: { // 0x5a66d0: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L005a66d4: { // 0x5a66d4: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L005a66d8: { // 0x5a66d8: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005a66d9: { // 0x5a66d9: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005a66da: { // 0x5a66da: 8d54242c LEA EDX,[ESP + 0x2c]
    s.dx = (f.sp+0x0000002cu);
  }
  L005a66de: { // 0x5a66de: e80df9ffff CALL 0x005a5ff0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005a5ff0u,5924579u); flags=s.arithmetic_flags;
  }
  L005a66e3: { // 0x5a66e3: eb1a JMP 0x005a66ff
    goto L005a66ff;
  }
  L005a66e5: { // 0x5a66e5: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L005a66e9: { // 0x5a66e9: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L005a66ed: { // 0x5a66ed: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L005a66ef: { // 0x5a66ef: 8d742424 LEA ESI,[ESP + 0x24]
    s.si = (f.sp+0x00000024u);
  }
  L005a66f3: { // 0x5a66f3: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L005a66f6: { // 0x5a66f6: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L005a66f8: { // 0x5a66f8: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L005a66fa: { // 0x5a66fa: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  L005a66fd: { // 0x5a66fd: f3a4 MOVSB.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::count);
  }
  L005a66ff: { // 0x5a66ff: d1eb SHR EBX,0x1
    s.bx = integer::shift(s.bx,0x00000001u,32,flags,integer::Shift::right);
  }
  L005a6701: { // 0x5a6701: 7508 JNZ 0x005a670b
    if(integer::condition("JNZ",flags)) goto L005a670b;
  }
  L005a6703: { // 0x5a6703: bb00000080 MOV EBX,0x80000000
    s.bx = 0x80000000u;
  }
  L005a6708: { // 0x5a6708: 83ed04 SUB EBP,0x4
    s.bp = integer::sub(s.bp,0x00000004u,32,flags);
  }
  L005a670b: { // 0x5a670b: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L005a670f: { // 0x5a670f: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L005a6710: { // 0x5a6710: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L005a6714: { // 0x5a6714: 75a2 JNZ 0x005a66b8
    if(integer::condition("JNZ",flags)) goto L005a66b8;
  }
  L005a6716: { // 0x5a6716: 8b742420 MOV ESI,dword ptr [ESP + 0x20]
    s.si = m.r32((f.sp+0x00000020u));
  }
  L005a671a: { // 0x5a671a: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005a671c: { // 0x5a671c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005a671e: { // 0x5a671e: bf6c8ea500 MOV EDI,0xa58e6c
    s.di = 0x00a58e6cu;
  }
  L005a6723: { // 0x5a6723: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L005a6725: { // 0x5a6725: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L005a6728: { // 0x5a6728: f3ab STOSD.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::count);
  }
  L005a672a: { // 0x5a672a: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L005a672c: { // 0x5a672c: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L005a672e: { // 0x5a672e: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  L005a6731: { // 0x5a6731: 8915708fa500 MOV dword ptr [0x00a58f70],EDX
    m.w32((0x00a58f70u), s.dx);
  }
  L005a6737: { // 0x5a6737: f3aa STOSB.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,8u,Repeat::count);
  }
  L005a6739: { // 0x5a6739: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005a673b: { // 0x5a673b: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005a673d: { // 0x5a673d: bf748fa500 MOV EDI,0xa58f74
    s.di = 0x00a58f74u;
  }
  L005a6742: { // 0x5a6742: 89156c8ea500 MOV dword ptr [0x00a58e6c],EDX
    m.w32((0x00a58e6cu), s.dx);
  }
  L005a6748: { // 0x5a6748: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L005a674b: { // 0x5a674b: f3ab STOSD.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::count);
  }
  L005a674d: { // 0x5a674d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005a674f: { // 0x5a674f: 89157c91a500 MOV dword ptr [0x00a5917c],EDX
    m.w32((0x00a5917cu), s.dx);
  }
  L005a6755: { // 0x5a6755: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  L005a6758: { // 0x5a6758: 668915588ea500 MOV word ptr [0x00a58e58],DX
    m.w16((0x00a58e58u), (s.dx & 0xffffu));
  }
  L005a675f: { // 0x5a675f: f3aa STOSB.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,8u,Repeat::count);
  }
  L005a6761: { // 0x5a6761: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005a6763: { // 0x5a6763: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L005a6765: { // 0x5a6765: a35c8ea500 MOV [0x00a58e5c],EAX
    m.w32((0x00a58e5cu), s.ax);
  }
  L005a676a: { // 0x5a676a: 890d8091a500 MOV dword ptr [0x00a59180],ECX
    m.w32((0x00a59180u), s.cx);
  }
  L005a6770: { // 0x5a6770: a3608ea500 MOV [0x00a58e60],EAX
    m.w32((0x00a58e60u), s.ax);
  }
  L005a6775: { // 0x5a6775: 890d8491a500 MOV dword ptr [0x00a59184],ECX
    m.w32((0x00a59184u), s.cx);
  }
  L005a677b: { // 0x5a677b: a3648ea500 MOV [0x00a58e64],EAX
    m.w32((0x00a58e64u), s.ax);
  }
  L005a6780: { // 0x5a6780: 890d8891a500 MOV dword ptr [0x00a59188],ECX
    m.w32((0x00a59188u), s.cx);
  }
  L005a6786: { // 0x5a6786: 8915748fa500 MOV dword ptr [0x00a58f74],EDX
    m.w32((0x00a58f74u), s.dx);
  }
  L005a678c: { // 0x5a678c: a3688ea500 MOV [0x00a58e68],EAX
    m.w32((0x00a58e68u), s.ax);
  }
  L005a6791: { // 0x5a6791: 89155c8ea500 MOV dword ptr [0x00a58e5c],EDX
    m.w32((0x00a58e5cu), s.dx);
  }
  L005a6797: { // 0x5a6797: 890d8c91a500 MOV dword ptr [0x00a5918c],ECX
    m.w32((0x00a5918cu), s.cx);
  }
  L005a679d: { // 0x5a679d: 89158091a500 MOV dword ptr [0x00a59180],EDX
    m.w32((0x00a59180u), s.dx);
  }
  L005a67a3: { // 0x5a67a3: 6689156c8fa500 MOV word ptr [0x00a58f6c],DX
    m.w16((0x00a58f6cu), (s.dx & 0xffffu));
  }
  L005a67aa: { // 0x5a67aa: 8915548ea500 MOV dword ptr [0x00a58e54],EDX
    m.w32((0x00a58e54u), s.dx);
  }
  L005a67b0: { // 0x5a67b0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005a67b1: { // 0x5a67b1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005a67b2: { // 0x5a67b2: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005a67b3: { // 0x5a67b3: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005a67b5: { // 0x5a67b5: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005a67b6: { // 0x5a67b6: 81c414010000 ADD ESP,0x114
    f.sp = integer::add(f.sp,0x00000114u,32,flags);
  }
  L005a67bc: { // 0x5a67bc: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
void f_001a5e10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005a5e10: { // 0x5a5e10: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005a5e11: { // 0x5a5e11: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  L005a5e13: { // 0x5a5e13: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005a5e14: { // 0x5a5e14: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L005a5e16: { // 0x5a5e16: 8d049d00000000 LEA EAX,[EBX*0x4 + 0x0]
    s.ax = ((s.bx * 0x00000004u)+0x00000000u);
  }
  L005a5e1d: { // 0x5a5e1d: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005a5e1e: { // 0x5a5e1e: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L005a5e20: { // 0x5a5e20: bf6c8ea500 MOV EDI,0xa58e6c
    s.di = 0x00a58e6cu;
  }
  L005a5e25: { // 0x5a5e25: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L005a5e27: { // 0x5a5e27: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L005a5e2a: { // 0x5a5e2a: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L005a5e2c: { // 0x5a5e2c: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L005a5e2e: { // 0x5a5e2e: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  L005a5e31: { // 0x5a5e31: f3a4 MOVSB.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::count);
  }
  L005a5e33: { // 0x5a5e33: 8db0688ea500 LEA ESI,[EAX + 0xa58e68]
    s.si = (s.ax+0x00a58e68u);
  }
  L005a5e39: { // 0x5a5e39: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L005a5e3b: { // 0x5a5e3b: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L005a5e3d: { // 0x5a5e3d: 833800 CMP dword ptr [EAX],0x0
    (void)integer::sub(m.r32((s.ax)),0x00000000u,32,flags);
  }
  L005a5e40: { // 0x5a5e40: 750d JNZ 0x005a5e4f
    if(integer::condition("JNZ",flags)) goto L005a5e4f;
  }
  L005a5e42: { // 0x5a5e42: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L005a5e43: { // 0x5a5e43: 740e JZ 0x005a5e53
    if(integer::condition("JZ",flags)) goto L005a5e53;
  }
  L005a5e45: { // 0x5a5e45: 8b50fc MOV EDX,dword ptr [EAX + -0x4]
    s.dx = m.r32((s.ax-0x00000004u));
  }
  L005a5e48: { // 0x5a5e48: 83e804 SUB EAX,0x4
    s.ax = integer::sub(s.ax,0x00000004u,32,flags);
  }
  L005a5e4b: { // 0x5a5e4b: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L005a5e4d: { // 0x5a5e4d: 74f3 JZ 0x005a5e42
    if(integer::condition("JZ",flags)) goto L005a5e42;
  }
  L005a5e4f: { // 0x5a5e4f: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005a5e51: { // 0x5a5e51: 7504 JNZ 0x005a5e57
    if(integer::condition("JNZ",flags)) goto L005a5e57;
  }
  L005a5e53: { // 0x5a5e53: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005a5e55: { // 0x5a5e55: eb1c JMP 0x005a5e73
    goto L005a5e73;
  }
  L005a5e57: { // 0x5a5e57: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L005a5e59: { // 0x5a5e59: 8b0c8d688ea500 MOV ECX,dword ptr [ECX*0x4 + 0xa58e68]
    s.cx = m.r32(((s.cx * 0x00000004u)+0x00a58e68u));
  }
  L005a5e60: { // 0x5a5e60: ba00000080 MOV EDX,0x80000000
    s.dx = 0x80000000u;
  }
  L005a5e65: { // 0x5a5e65: c1e005 SHL EAX,0x5
    s.ax = integer::shift(s.ax,0x00000005u,32,flags,integer::Shift::left);
  }
  L005a5e68: { // 0x5a5e68: 85ca TEST EDX,ECX
    (void)integer::logical((s.dx)&(s.cx),32,flags);
  }
  L005a5e6a: { // 0x5a5e6a: 7507 JNZ 0x005a5e73
    if(integer::condition("JNZ",flags)) goto L005a5e73;
  }
  L005a5e6c: { // 0x5a5e6c: d1ea SHR EDX,0x1
    s.dx = integer::shift(s.dx,0x00000001u,32,flags,integer::Shift::right);
  }
  L005a5e6e: { // 0x5a5e6e: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L005a5e6f: { // 0x5a5e6f: 85ca TEST EDX,ECX
    (void)integer::logical((s.dx)&(s.cx),32,flags);
  }
  L005a5e71: { // 0x5a5e71: 74f9 JZ 0x005a5e6c
    if(integer::condition("JZ",flags)) goto L005a5e6c;
  }
  L005a5e73: { // 0x5a5e73: a3708fa500 MOV [0x00a58f70],EAX
    m.w32((0x00a58f70u), s.ax);
  }
  L005a5e78: { // 0x5a5e78: 83c00f ADD EAX,0xf
    s.ax = integer::add(s.ax,0x0000000fu,32,flags);
  }
  L005a5e7b: { // 0x5a5e7b: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L005a5e7c: { // 0x5a5e7c: 83e20f AND EDX,0xf
    s.dx = integer::logical((s.dx)&(0x0000000fu),32,flags);
  }
  L005a5e7f: { // 0x5a5e7f: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L005a5e81: { // 0x5a5e81: c1f804 SAR EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::arithmetic_right);
  }
  L005a5e84: { // 0x5a5e84: a3548ea500 MOV [0x00a58e54],EAX
    m.w32((0x00a58e54u), s.ax);
  }
  L005a5e89: { // 0x5a5e89: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L005a5e8b: { // 0x5a5e8b: 833800 CMP dword ptr [EAX],0x0
    (void)integer::sub(m.r32((s.ax)),0x00000000u,32,flags);
  }
  L005a5e8e: { // 0x5a5e8e: 750d JNZ 0x005a5e9d
    if(integer::condition("JNZ",flags)) goto L005a5e9d;
  }
  L005a5e90: { // 0x5a5e90: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L005a5e91: { // 0x5a5e91: 740a JZ 0x005a5e9d
    if(integer::condition("JZ",flags)) goto L005a5e9d;
  }
  L005a5e93: { // 0x5a5e93: 8b48fc MOV ECX,dword ptr [EAX + -0x4]
    s.cx = m.r32((s.ax-0x00000004u));
  }
  L005a5e96: { // 0x5a5e96: 83e804 SUB EAX,0x4
    s.ax = integer::sub(s.ax,0x00000004u,32,flags);
  }
  L005a5e99: { // 0x5a5e99: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005a5e9b: { // 0x5a5e9b: 74f3 JZ 0x005a5e90
    if(integer::condition("JZ",flags)) goto L005a5e90;
  }
  L005a5e9d: { // 0x5a5e9d: 8d049d648ea500 LEA EAX,[EBX*0x4 + 0xa58e64]
    s.ax = ((s.bx * 0x00000004u)+0x00a58e64u);
  }
  L005a5ea4: { // 0x5a5ea4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005a5ea5: { // 0x5a5ea5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005a5ea6: { // 0x5a5ea6: ba02000000 MOV EDX,0x2
    s.dx = 0x00000002u;
  }
  L005a5eab: { // 0x5a5eab: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L005a5ead: { // 0x5a5ead: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005a5eae: { // 0x5a5eae: 890d8091a500 MOV dword ptr [0x00a59180],ECX
    m.w32((0x00a59180u), s.cx);
  }
  L005a5eb4: { // 0x5a5eb4: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L005a5eb7: { // 0x5a5eb7: b88491a500 MOV EAX,0xa59184
    s.ax = 0x00a59184u;
  }
  L005a5ebc: { // 0x5a5ebc: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005a5ebe: { // 0x5a5ebe: 890d8491a500 MOV dword ptr [0x00a59184],ECX
    m.w32((0x00a59184u), s.cx);
  }
  L005a5ec4: { // 0x5a5ec4: 7515 JNZ 0x005a5edb
    if(integer::condition("JNZ",flags)) goto L005a5edb;
  }
  L005a5ec6: { // 0x5a5ec6: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L005a5ec7: { // 0x5a5ec7: 740e JZ 0x005a5ed7
    if(integer::condition("JZ",flags)) goto L005a5ed7;
  }
  L005a5ec9: { // 0x5a5ec9: 8b48fc MOV ECX,dword ptr [EAX + -0x4]
    s.cx = m.r32((s.ax-0x00000004u));
  }
  L005a5ecc: { // 0x5a5ecc: 83e804 SUB EAX,0x4
    s.ax = integer::sub(s.ax,0x00000004u,32,flags);
  }
  L005a5ecf: { // 0x5a5ecf: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005a5ed1: { // 0x5a5ed1: 74f3 JZ 0x005a5ec6
    if(integer::condition("JZ",flags)) goto L005a5ec6;
  }
  L005a5ed3: { // 0x5a5ed3: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L005a5ed5: { // 0x5a5ed5: 7504 JNZ 0x005a5edb
    if(integer::condition("JNZ",flags)) goto L005a5edb;
  }
  L005a5ed7: { // 0x5a5ed7: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005a5ed9: { // 0x5a5ed9: eb1c JMP 0x005a5ef7
    goto L005a5ef7;
  }
  L005a5edb: { // 0x5a5edb: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L005a5edd: { // 0x5a5edd: 8b14957c91a500 MOV EDX,dword ptr [EDX*0x4 + 0xa5917c]
    s.dx = m.r32(((s.dx * 0x00000004u)+0x00a5917cu));
  }
  L005a5ee4: { // 0x5a5ee4: b900000080 MOV ECX,0x80000000
    s.cx = 0x80000000u;
  }
  L005a5ee9: { // 0x5a5ee9: c1e005 SHL EAX,0x5
    s.ax = integer::shift(s.ax,0x00000005u,32,flags,integer::Shift::left);
  }
  L005a5eec: { // 0x5a5eec: 85d1 TEST ECX,EDX
    (void)integer::logical((s.cx)&(s.dx),32,flags);
  }
  L005a5eee: { // 0x5a5eee: 7507 JNZ 0x005a5ef7
    if(integer::condition("JNZ",flags)) goto L005a5ef7;
  }
  L005a5ef0: { // 0x5a5ef0: d1e9 SHR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::right);
  }
  L005a5ef2: { // 0x5a5ef2: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L005a5ef3: { // 0x5a5ef3: 85d1 TEST ECX,EDX
    (void)integer::logical((s.cx)&(s.dx),32,flags);
  }
  L005a5ef5: { // 0x5a5ef5: 74f9 JZ 0x005a5ef0
    if(integer::condition("JZ",flags)) goto L005a5ef0;
  }
  L005a5ef7: { // 0x5a5ef7: 8d50e0 LEA EDX,[EAX + -0x20]
    s.dx = (s.ax-0x00000020u);
  }
  L005a5efa: { // 0x5a5efa: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  L005a5efc: { // 0x5a5efc: b98091a500 MOV ECX,0xa59180
    s.cx = 0x00a59180u;
  }
  L005a5f01: { // 0x5a5f01: 89157c91a500 MOV dword ptr [0x00a5917c],EDX
    m.w32((0x00a5917cu), s.dx);
  }
  L005a5f07: { // 0x5a5f07: e8a4e6ffff CALL 0x005a45b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005a45b0u,5922572u); flags=s.arithmetic_flags;
  }
  L005a5f0c: { // 0x5a5f0c: ba8091a500 MOV EDX,0xa59180
    s.dx = 0x00a59180u;
  }
  L005a5f11: { // 0x5a5f11: b95c8ea500 MOV ECX,0xa58e5c
    s.cx = 0x00a58e5cu;
  }
  L005a5f16: { // 0x5a5f16: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  L005a5f18: { // 0x5a5f18: e8c3f9ffff CALL 0x005a58e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005a58e0u,5922589u); flags=s.arithmetic_flags;
  }
  L005a5f1d: { // 0x5a5f1d: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L005a5f22: { // 0x5a5f22: b95c8ea500 MOV ECX,0xa58e5c
    s.cx = 0x00a58e5cu;
  }
  L005a5f27: { // 0x5a5f27: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  L005a5f29: { // 0x5a5f29: e882e6ffff CALL 0x005a45b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005a45b0u,5922606u); flags=s.arithmetic_flags;
  }
  L005a5f2e: { // 0x5a5f2e: 8b157c91a500 MOV EDX,dword ptr [0x00a5917c]
    s.dx = m.r32((0x00a5917cu));
  }
  L005a5f34: { // 0x5a5f34: 83c20f ADD EDX,0xf
    s.dx = integer::add(s.dx,0x0000000fu,32,flags);
  }
  L005a5f37: { // 0x5a5f37: 81e20f000080 AND EDX,0x8000000f
    s.dx = integer::logical((s.dx)&(0x8000000fu),32,flags);
  }
  L005a5f3d: { // 0x5a5f3d: 7905 JNS 0x005a5f44
    if(integer::condition("JNS",flags)) goto L005a5f44;
  }
  L005a5f3f: { // 0x5a5f3f: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L005a5f40: { // 0x5a5f40: 83caf0 OR EDX,0xfffffff0
    s.dx = integer::logical((s.dx)|(0xfffffff0u),32,flags);
  }
  L005a5f43: { // 0x5a5f43: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L005a5f44: { // 0x5a5f44: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L005a5f45: { // 0x5a5f45: b902000000 MOV ECX,0x2
    s.cx = 0x00000002u;
  }
  L005a5f4a: { // 0x5a5f4a: 89157c91a500 MOV dword ptr [0x00a5917c],EDX
    m.w32((0x00a5917cu), s.dx);
  }
  L005a5f50: { // 0x5a5f50: 8b155c8ea500 MOV EDX,dword ptr [0x00a58e5c]
    s.dx = m.r32((0x00a58e5cu));
  }
  L005a5f56: { // 0x5a5f56: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L005a5f57: { // 0x5a5f57: b85c8ea500 MOV EAX,0xa58e5c
    s.ax = 0x00a58e5cu;
  }
  L005a5f5c: { // 0x5a5f5c: 89155c8ea500 MOV dword ptr [0x00a58e5c],EDX
    m.w32((0x00a58e5cu), s.dx);
  }
  L005a5f62: { // 0x5a5f62: 750d JNZ 0x005a5f71
    if(integer::condition("JNZ",flags)) goto L005a5f71;
  }
  L005a5f64: { // 0x5a5f64: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  L005a5f67: { // 0x5a5f67: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L005a5f68: { // 0x5a5f68: 7407 JZ 0x005a5f71
    if(integer::condition("JZ",flags)) goto L005a5f71;
  }
  L005a5f6a: { // 0x5a5f6a: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L005a5f6c: { // 0x5a5f6c: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L005a5f6d: { // 0x5a5f6d: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L005a5f6f: { // 0x5a5f6f: 74f3 JZ 0x005a5f64
    if(integer::condition("JZ",flags)) goto L005a5f64;
  }
  L005a5f71: { // 0x5a5f71: 8b0d608ea500 MOV ECX,dword ptr [0x00a58e60]
    s.cx = m.r32((0x00a58e60u));
  }
  L005a5f77: { // 0x5a5f77: ba02000000 MOV EDX,0x2
    s.dx = 0x00000002u;
  }
  L005a5f7c: { // 0x5a5f7c: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005a5f7e: { // 0x5a5f7e: b8608ea500 MOV EAX,0xa58e60
    s.ax = 0x00a58e60u;
  }
  L005a5f83: { // 0x5a5f83: 7511 JNZ 0x005a5f96
    if(integer::condition("JNZ",flags)) goto L005a5f96;
  }
  L005a5f85: { // 0x5a5f85: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L005a5f86: { // 0x5a5f86: 7446 JZ 0x005a5fce
    if(integer::condition("JZ",flags)) goto L005a5fce;
  }
  L005a5f88: { // 0x5a5f88: 8b48fc MOV ECX,dword ptr [EAX + -0x4]
    s.cx = m.r32((s.ax-0x00000004u));
  }
  L005a5f8b: { // 0x5a5f8b: 83e804 SUB EAX,0x4
    s.ax = integer::sub(s.ax,0x00000004u,32,flags);
  }
  L005a5f8e: { // 0x5a5f8e: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005a5f90: { // 0x5a5f90: 74f3 JZ 0x005a5f85
    if(integer::condition("JZ",flags)) goto L005a5f85;
  }
  L005a5f92: { // 0x5a5f92: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L005a5f94: { // 0x5a5f94: 7438 JZ 0x005a5fce
    if(integer::condition("JZ",flags)) goto L005a5fce;
  }
  L005a5f96: { // 0x5a5f96: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L005a5f98: { // 0x5a5f98: 8b1495588ea500 MOV EDX,dword ptr [EDX*0x4 + 0xa58e58]
    s.dx = m.r32(((s.dx * 0x00000004u)+0x00a58e58u));
  }
  L005a5f9f: { // 0x5a5f9f: b900000080 MOV ECX,0x80000000
    s.cx = 0x80000000u;
  }
  L005a5fa4: { // 0x5a5fa4: c1e005 SHL EAX,0x5
    s.ax = integer::shift(s.ax,0x00000005u,32,flags,integer::Shift::left);
  }
  L005a5fa7: { // 0x5a5fa7: 85d1 TEST ECX,EDX
    (void)integer::logical((s.cx)&(s.dx),32,flags);
  }
  L005a5fa9: { // 0x5a5fa9: 7507 JNZ 0x005a5fb2
    if(integer::condition("JNZ",flags)) goto L005a5fb2;
  }
  L005a5fab: { // 0x5a5fab: d1e9 SHR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::right);
  }
  L005a5fad: { // 0x5a5fad: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L005a5fae: { // 0x5a5fae: 85d1 TEST ECX,EDX
    (void)integer::logical((s.cx)&(s.dx),32,flags);
  }
  L005a5fb0: { // 0x5a5fb0: 74f9 JZ 0x005a5fab
    if(integer::condition("JZ",flags)) goto L005a5fab;
  }
  L005a5fb2: { // 0x5a5fb2: 83f820 CMP EAX,0x20
    (void)integer::sub(s.ax,0x00000020u,32,flags);
  }
  L005a5fb5: { // 0x5a5fb5: 7617 JBE 0x005a5fce
    if(integer::condition("JBE",flags)) goto L005a5fce;
  }
  L005a5fb7: { // 0x5a5fb7: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  L005a5fb9: { // 0x5a5fb9: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L005a5fbe: { // 0x5a5fbe: b95c8ea500 MOV ECX,0xa58e5c
    s.cx = 0x00a58e5cu;
  }
  L005a5fc3: { // 0x5a5fc3: e8e8e5ffff CALL 0x005a45b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005a45b0u,5922760u); flags=s.arithmetic_flags;
  }
  L005a5fc8: { // 0x5a5fc8: ff0d7c91a500 DEC dword ptr [0x00a5917c]
    m.w32((0x00a5917cu), integer::decrement(m.r32((0x00a5917cu)),32,flags));
  }
  L005a5fce: { // 0x5a5fce: 66a15c8ea500 MOV AX,[0x00a58e5c]
    s.ax = with_ax(s.ax, m.r16((0x00a58e5cu)));
  }
  L005a5fd4: { // 0x5a5fd4: 668b0d5e8ea500 MOV CX,word ptr [0x00a58e5e]
    s.cx = with_ax(s.cx, m.r16((0x00a58e5eu)));
  }
  L005a5fdb: { // 0x5a5fdb: 66a3588ea500 MOV [0x00a58e58],AX
    m.w16((0x00a58e58u), (s.ax & 0xffffu));
  }
  L005a5fe1: { // 0x5a5fe1: 66890d6c8fa500 MOV word ptr [0x00a58f6c],CX
    m.w16((0x00a58f6cu), (s.cx & 0xffffu));
  }
  L005a5fe8: { // 0x5a5fe8: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005a5fea: { // 0x5a5fea: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_001a5ff0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005a5ff0: { // 0x5a5ff0: 83ec14 SUB ESP,0x14
    f.sp = integer::sub(f.sp,0x00000014u,32,flags);
  }
  L005a5ff3: { // 0x5a5ff3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005a5ff4: { // 0x5a5ff4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005a5ff5: { // 0x5a5ff5: 8bea MOV EBP,EDX
    s.bp = s.dx;
  }
  L005a5ff7: { // 0x5a5ff7: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L005a5ffb: { // 0x5a5ffb: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L005a5fff: { // 0x5a5fff: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005a6000: { // 0x5a6000: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005a6001: { // 0x5a6001: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005a6003: { // 0x5a6003: 8d0cd500000000 LEA ECX,[EDX*0x8 + 0x0]
    s.cx = ((s.dx * 0x00000008u)+0x00000000u);
  }
  L005a600a: { // 0x5a600a: bf748fa500 MOV EDI,0xa58f74
    s.di = 0x00a58f74u;
  }
  L005a600f: { // 0x5a600f: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L005a6011: { // 0x5a6011: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L005a6014: { // 0x5a6014: f3ab STOSD.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::count);
  }
  L005a6016: { // 0x5a6016: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005a6018: { // 0x5a6018: 8b742428 MOV ESI,dword ptr [ESP + 0x28]
    s.si = m.r32((f.sp+0x00000028u));
  }
  L005a601c: { // 0x5a601c: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  L005a601f: { // 0x5a601f: f3aa STOSB.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,8u,Repeat::count);
  }
  L005a6021: { // 0x5a6021: 8d3c12 LEA EDI,[EDX + EDX*0x1]
    s.di = (s.dx+(s.dx * 0x00000001u));
  }
  L005a6024: { // 0x5a6024: c705748fa50000000000 MOV dword ptr [0x00a58f74],0x0
    m.w32((0x00a58f74u), 0x00000000u);
  }
  L005a602e: { // 0x5a602e: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L005a6030: { // 0x5a6030: 7e28 JLE 0x005a605a
    if(integer::condition("JLE",flags)) goto L005a605a;
  }
  L005a6032: { // 0x5a6032: bb748fa500 MOV EBX,0xa58f74
    s.bx = 0x00a58f74u;
  }
  L005a6037: { // 0x5a6037: 897c2428 MOV dword ptr [ESP + 0x28],EDI
    m.w32((f.sp+0x00000028u), s.di);
  }
  L005a603b: { // 0x5a603b: 2bde SUB EBX,ESI
    s.bx = integer::sub(s.bx,s.si,32,flags);
  }
  L005a603d: { // 0x5a603d: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L005a6040: { // 0x5a6040: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005a6041: { // 0x5a6041: 8d0c33 LEA ECX,[EBX + ESI*0x1]
    s.cx = (s.bx+(s.si * 0x00000001u));
  }
  L005a6044: { // 0x5a6044: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005a6045: { // 0x5a6045: 8bd5 MOV EDX,EBP
    s.dx = s.bp;
  }
  L005a6047: { // 0x5a6047: 83c602 ADD ESI,0x2
    s.si = integer::add(s.si,0x00000002u,32,flags);
  }
  L005a604a: { // 0x5a604a: e8b1fcffff CALL 0x005a5d00
    s.arithmetic_flags=flags; invoke(m,s,f,0x005a5d00u,5922895u); flags=s.arithmetic_flags;
  }
  L005a604f: { // 0x5a604f: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L005a6053: { // 0x5a6053: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L005a6054: { // 0x5a6054: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L005a6058: { // 0x5a6058: 75e3 JNZ 0x005a603d
    if(integer::condition("JNZ",flags)) goto L005a603d;
  }
  L005a605a: { // 0x5a605a: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L005a605b: { // 0x5a605b: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005a605d: { // 0x5a605d: 8d04bd708fa500 LEA EAX,[EDI*0x4 + 0xa58f70]
    s.ax = ((s.di * 0x00000004u)+0x00a58f70u);
  }
  L005a6064: { // 0x5a6064: c70000000000 MOV dword ptr [EAX],0x0
    m.w32((s.ax), 0x00000000u);
  }
  L005a606a: { // 0x5a606a: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L005a606c: { // 0x5a606c: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L005a606e: { // 0x5a606e: 750d JNZ 0x005a607d
    if(integer::condition("JNZ",flags)) goto L005a607d;
  }
  L005a6070: { // 0x5a6070: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L005a6071: { // 0x5a6071: 740a JZ 0x005a607d
    if(integer::condition("JZ",flags)) goto L005a607d;
  }
  L005a6073: { // 0x5a6073: 8b50fc MOV EDX,dword ptr [EAX + -0x4]
    s.dx = m.r32((s.ax-0x00000004u));
  }
  L005a6076: { // 0x5a6076: 83e804 SUB EAX,0x4
    s.ax = integer::sub(s.ax,0x00000004u,32,flags);
  }
  L005a6079: { // 0x5a6079: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L005a607b: { // 0x5a607b: 74f3 JZ 0x005a6070
    if(integer::condition("JZ",flags)) goto L005a6070;
  }
  L005a607d: { // 0x5a607d: 8b35548ea500 MOV ESI,dword ptr [0x00a58e54]
    s.si = m.r32((0x00a58e54u));
  }
  L005a6083: { // 0x5a6083: 8d1409 LEA EDX,[ECX + ECX*0x1]
    s.dx = (s.cx+(s.cx * 0x00000001u));
  }
  L005a6086: { // 0x5a6086: 3bd6 CMP EDX,ESI
    (void)integer::sub(s.dx,s.si,32,flags);
  }
  L005a6088: { // 0x5a6088: 0f8c58020000 JL 0x005a62e6
    if(integer::condition("JL",flags)) goto L005a62e6;
  }
  L005a608e: { // 0x5a608e: 8b1d748fa500 MOV EBX,dword ptr [0x00a58f74]
    s.bx = m.r32((0x00a58f74u));
  }
  L005a6094: { // 0x5a6094: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005a6096: { // 0x5a6096: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L005a6097: { // 0x5a6097: b8748fa500 MOV EAX,0xa58f74
    s.ax = 0x00a58f74u;
  }
  L005a609c: { // 0x5a609c: 891d748fa500 MOV dword ptr [0x00a58f74],EBX
    m.w32((0x00a58f74u), s.bx);
  }
  L005a60a2: { // 0x5a60a2: 750d JNZ 0x005a60b1
    if(integer::condition("JNZ",flags)) goto L005a60b1;
  }
  L005a60a4: { // 0x5a60a4: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  L005a60a7: { // 0x5a60a7: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L005a60a8: { // 0x5a60a8: 7407 JZ 0x005a60b1
    if(integer::condition("JZ",flags)) goto L005a60b1;
  }
  L005a60aa: { // 0x5a60aa: 8b18 MOV EBX,dword ptr [EAX]
    s.bx = m.r32((s.ax));
  }
  L005a60ac: { // 0x5a60ac: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L005a60ad: { // 0x5a60ad: 8918 MOV dword ptr [EAX],EBX
    m.w32((s.ax), s.bx);
  }
  L005a60af: { // 0x5a60af: 74f3 JZ 0x005a60a4
    if(integer::condition("JZ",flags)) goto L005a60a4;
  }
  L005a60b1: { // 0x5a60b1: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L005a60b3: { // 0x5a60b3: b8748fa500 MOV EAX,0xa58f74
    s.ax = 0x00a58f74u;
  }
  L005a60b8: { // 0x5a60b8: 7e0f JLE 0x005a60c9
    if(integer::condition("JLE",flags)) goto L005a60c9;
  }
  L005a60ba: { // 0x5a60ba: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005a60bc: { // 0x5a60bc: 8b18 MOV EBX,dword ptr [EAX]
    s.bx = m.r32((s.ax));
  }
  L005a60be: { // 0x5a60be: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  L005a60c1: { // 0x5a60c1: f7d3 NOT EBX
    s.bx = (~(s.bx)&integer::mask(32));
  }
  L005a60c3: { // 0x5a60c3: 8958fc MOV dword ptr [EAX + -0x4],EBX
    m.w32((s.ax-0x00000004u), s.bx);
  }
  L005a60c6: { // 0x5a60c6: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L005a60c7: { // 0x5a60c7: 75f3 JNZ 0x005a60bc
    if(integer::condition("JNZ",flags)) goto L005a60bc;
  }
  L005a60c9: { // 0x5a60c9: 8b0d748fa500 MOV ECX,dword ptr [0x00a58f74]
    s.cx = m.r32((0x00a58f74u));
  }
  L005a60cf: { // 0x5a60cf: b8748fa500 MOV EAX,0xa58f74
    s.ax = 0x00a58f74u;
  }
  L005a60d4: { // 0x5a60d4: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L005a60d5: { // 0x5a60d5: 890d748fa500 MOV dword ptr [0x00a58f74],ECX
    m.w32((0x00a58f74u), s.cx);
  }
  L005a60db: { // 0x5a60db: 750d JNZ 0x005a60ea
    if(integer::condition("JNZ",flags)) goto L005a60ea;
  }
  L005a60dd: { // 0x5a60dd: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  L005a60e0: { // 0x5a60e0: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L005a60e1: { // 0x5a60e1: 7407 JZ 0x005a60ea
    if(integer::condition("JZ",flags)) goto L005a60ea;
  }
  L005a60e3: { // 0x5a60e3: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L005a60e5: { // 0x5a60e5: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L005a60e6: { // 0x5a60e6: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L005a60e8: { // 0x5a60e8: 74f3 JZ 0x005a60dd
    if(integer::condition("JZ",flags)) goto L005a60dd;
  }
  L005a60ea: { // 0x5a60ea: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L005a60ec: { // 0x5a60ec: 8d3c55768fa500 LEA EDI,[EDX*0x2 + 0xa58f76]
    s.di = ((s.dx * 0x00000002u)+0x00a58f76u);
  }
  L005a60f3: { // 0x5a60f3: 2bc6 SUB EAX,ESI
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L005a60f5: { // 0x5a60f5: 8d0c36 LEA ECX,[ESI + ESI*0x1]
    s.cx = (s.si+(s.si * 0x00000001u));
  }
  L005a60f8: { // 0x5a60f8: 8bef MOV EBP,EDI
    s.bp = s.di;
  }
  L005a60fa: { // 0x5a60fa: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L005a60fb: { // 0x5a60fb: 2be9 SUB EBP,ECX
    s.bp = integer::sub(s.bp,s.cx,32,flags);
  }
  L005a60fd: { // 0x5a60fd: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005a60ff: { // 0x5a60ff: 0f8477010000 JZ 0x005a627c
    if(integer::condition("JZ",flags)) goto L005a627c;
  }
  L005a6105: { // 0x5a6105: be6c8ea500 MOV ESI,0xa58e6c
    s.si = 0x00a58e6cu;
  }
  L005a610a: { // 0x5a610a: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L005a610e: { // 0x5a610e: 2bf5 SUB ESI,EBP
    s.si = integer::sub(s.si,s.bp,32,flags);
  }
  L005a6110: { // 0x5a6110: 668b47fc MOV AX,word ptr [EDI + -0x4]
    s.ax = with_ax(s.ax, m.r16((s.di-0x00000004u)));
  }
  L005a6114: { // 0x5a6114: 668b5ffa MOV BX,word ptr [EDI + -0x6]
    s.bx = with_ax(s.bx, m.r16((s.di-0x00000006u)));
  }
  L005a6118: { // 0x5a6118: 668b4ffe MOV CX,word ptr [EDI + -0x2]
    s.cx = with_ax(s.cx, m.r16((s.di-0x00000002u)));
  }
  L005a611c: { // 0x5a611c: 83ef02 SUB EDI,0x2
    s.di = integer::sub(s.di,0x00000002u,32,flags);
  }
  L005a611f: { // 0x5a611f: 8b156c8fa500 MOV EDX,dword ptr [0x00a58f6c]
    s.dx = m.r32((0x00a58f6cu));
  }
  L005a6125: { // 0x5a6125: 83c602 ADD ESI,0x2
    s.si = integer::add(s.si,0x00000002u,32,flags);
  }
  L005a6128: { // 0x5a6128: 66f7d0 NOT AX
    s.ax = with_ax(s.ax, (~((s.ax & 0xffffu))&integer::mask(16)));
  }
  L005a612b: { // 0x5a612b: 83ed02 SUB EBP,0x2
    s.bp = integer::sub(s.bp,0x00000002u,32,flags);
  }
  L005a612e: { // 0x5a612e: 89742410 MOV dword ptr [ESP + 0x10],ESI
    m.w32((f.sp+0x00000010u), s.si);
  }
  L005a6132: { // 0x5a6132: 8b35588ea500 MOV ESI,dword ptr [0x00a58e58]
    s.si = m.r32((0x00a58e58u));
  }
  L005a6138: { // 0x5a6138: 25ffff0000 AND EAX,0xffff
    s.ax = integer::logical((s.ax)&(0x0000ffffu),32,flags);
  }
  L005a613d: { // 0x5a613d: 66f7d3 NOT BX
    s.bx = with_ax(s.bx, (~((s.bx & 0xffffu))&integer::mask(16)));
  }
  L005a6140: { // 0x5a6140: 896c2428 MOV dword ptr [ESP + 0x28],EBP
    m.w32((f.sp+0x00000028u), s.bp);
  }
  L005a6144: { // 0x5a6144: 81e6ffff0000 AND ESI,0xffff
    s.si = integer::logical((s.si)&(0x0000ffffu),32,flags);
  }
  L005a614a: { // 0x5a614a: 66f7d1 NOT CX
    s.cx = with_ax(s.cx, (~((s.cx & 0xffffu))&integer::mask(16)));
  }
  L005a614d: { // 0x5a614d: 81e3ffff0000 AND EBX,0xffff
    s.bx = integer::logical((s.bx)&(0x0000ffffu),32,flags);
  }
  L005a6153: { // 0x5a6153: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L005a6155: { // 0x5a6155: 81e2ffff0000 AND EDX,0xffff
    s.dx = integer::logical((s.dx)&(0x0000ffffu),32,flags);
  }
  L005a615b: { // 0x5a615b: 81e1ffff0000 AND ECX,0xffff
    s.cx = integer::logical((s.cx)&(0x0000ffffu),32,flags);
  }
  L005a6161: { // 0x5a6161: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L005a6162: { // 0x5a6162: 0fafee IMUL EBP,ESI
    s.bp = integer::imul(s.bp,s.si,32,flags);
  }
  L005a6165: { // 0x5a6165: 0fafda IMUL EBX,EDX
    s.bx = integer::imul(s.bx,s.dx,32,flags);
  }
  L005a6168: { // 0x5a6168: 0fafc2 IMUL EAX,EDX
    s.ax = integer::imul(s.ax,s.dx,32,flags);
  }
  L005a616b: { // 0x5a616b: 81c500000100 ADD EBP,0x10000
    s.bp = integer::add(s.bp,0x00010000u,32,flags);
  }
  L005a6171: { // 0x5a6171: d1eb SHR EBX,0x1
    s.bx = integer::shift(s.bx,0x00000001u,32,flags,integer::Shift::right);
  }
  L005a6173: { // 0x5a6173: d1ed SHR EBP,0x1
    s.bp = integer::shift(s.bp,0x00000001u,32,flags,integer::Shift::right);
  }
  L005a6175: { // 0x5a6175: d1e8 SHR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::right);
  }
  L005a6177: { // 0x5a6177: 8d5c2b01 LEA EBX,[EBX + EBP*0x1 + 0x1]
    s.bx = (s.bx+(s.bp * 0x00000001u)+0x00000001u);
  }
  L005a617b: { // 0x5a617b: c1eb10 SHR EBX,0x10
    s.bx = integer::shift(s.bx,0x00000010u,32,flags,integer::Shift::right);
  }
  L005a617e: { // 0x5a617e: 03d8 ADD EBX,EAX
    s.bx = integer::add(s.bx,s.ax,32,flags);
  }
  L005a6180: { // 0x5a6180: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L005a6182: { // 0x5a6182: 0fafc6 IMUL EAX,ESI
    s.ax = integer::imul(s.ax,s.si,32,flags);
  }
  L005a6185: { // 0x5a6185: 0fafca IMUL ECX,EDX
    s.cx = integer::imul(s.cx,s.dx,32,flags);
  }
  L005a6188: { // 0x5a6188: d1e8 SHR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::right);
  }
  L005a618a: { // 0x5a618a: 8d440301 LEA EAX,[EBX + EAX*0x1 + 0x1]
    s.ax = (s.bx+(s.ax * 0x00000001u)+0x00000001u);
  }
  L005a618e: { // 0x5a618e: c1e80e SHR EAX,0xe
    s.ax = integer::shift(s.ax,0x0000000eu,32,flags,integer::Shift::right);
  }
  L005a6191: { // 0x5a6191: 8d0448 LEA EAX,[EAX + ECX*0x2]
    s.ax = (s.ax+(s.cx * 0x00000002u));
  }
  L005a6194: { // 0x5a6194: 8b0d7c91a500 MOV ECX,dword ptr [0x00a5917c]
    s.cx = m.r32((0x00a5917cu));
  }
  L005a619a: { // 0x5a619a: d3e8 SHR EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  L005a619c: { // 0x5a619c: 3dffff0000 CMP EAX,0xffff
    (void)integer::sub(s.ax,0x0000ffffu,32,flags);
  }
  L005a61a1: { // 0x5a61a1: 7207 JC 0x005a61aa
    if(integer::condition("JC",flags)) goto L005a61aa;
  }
  L005a61a3: { // 0x5a61a3: b8ffff0000 MOV EAX,0xffff
    s.ax = 0x0000ffffu;
  }
  L005a61a8: { // 0x5a61a8: eb09 JMP 0x005a61b3
    goto L005a61b3;
  }
  L005a61aa: { // 0x5a61aa: 6685c0 TEST AX,AX
    (void)integer::logical(((s.ax & 0xffffu))&((s.ax & 0xffffu)),16,flags);
  }
  L005a61ad: { // 0x5a61ad: 0f86b2000000 JBE 0x005a6265
    if(integer::condition("JBE",flags)) goto L005a6265;
  }
  L005a61b3: { // 0x5a61b3: 8b74242c MOV ESI,dword ptr [ESP + 0x2c]
    s.si = m.r32((f.sp+0x0000002cu));
  }
  L005a61b7: { // 0x5a61b7: 8b6c2428 MOV EBP,dword ptr [ESP + 0x28]
    s.bp = m.r32((f.sp+0x00000028u));
  }
  L005a61bb: { // 0x5a61bb: 03f6 ADD ESI,ESI
    s.si = integer::add(s.si,s.si,32,flags);
  }
  L005a61bd: { // 0x5a61bd: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L005a61bf: { // 0x5a61bf: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L005a61c1: { // 0x5a61c1: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L005a61c3: { // 0x5a61c3: 0f8e96000000 JLE 0x005a625f
    if(integer::condition("JLE",flags)) goto L005a625f;
  }
  L005a61c9: { // 0x5a61c9: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L005a61cb: { // 0x5a61cb: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L005a61cf: { // 0x5a61cf: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L005a61d3: { // 0x5a61d3: 81e3ffff0000 AND EBX,0xffff
    s.bx = integer::logical((s.bx)&(0x0000ffffu),32,flags);
  }
  L005a61d9: { // 0x5a61d9: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005a61db: { // 0x5a61db: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L005a61dd: { // 0x5a61dd: 668b040e MOV AX,word ptr [ESI + ECX*0x1]
    s.ax = with_ax(s.ax, m.r16((s.si+(s.cx * 0x00000001u))));
  }
  L005a61e1: { // 0x5a61e1: 668b29 MOV BP,word ptr [ECX]
    s.bp = (s.bp & 0xffff0000u) | ((m.r16((s.cx))) & 0xffffu);
  }
  L005a61e4: { // 0x5a61e4: 0fafc3 IMUL EAX,EBX
    s.ax = integer::imul(s.ax,s.bx,32,flags);
  }
  L005a61e7: { // 0x5a61e7: 03ea ADD EBP,EDX
    s.bp = integer::add(s.bp,s.dx,32,flags);
  }
  L005a61e9: { // 0x5a61e9: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L005a61ec: { // 0x5a61ec: 03c5 ADD EAX,EBP
    s.ax = integer::add(s.ax,s.bp,32,flags);
  }
  L005a61ee: { // 0x5a61ee: 668941fe MOV word ptr [ECX + -0x2],AX
    m.w16((s.cx-0x00000002u), (s.ax & 0xffffu));
  }
  L005a61f2: { // 0x5a61f2: c1e810 SHR EAX,0x10
    s.ax = integer::shift(s.ax,0x00000010u,32,flags,integer::Shift::right);
  }
  L005a61f5: { // 0x5a61f5: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L005a61f7: { // 0x5a61f7: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L005a61fb: { // 0x5a61fb: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L005a61fc: { // 0x5a61fc: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L005a6200: { // 0x5a6200: 75d7 JNZ 0x005a61d9
    if(integer::condition("JNZ",flags)) goto L005a61d9;
  }
  L005a6202: { // 0x5a6202: 8b6c2428 MOV EBP,dword ptr [ESP + 0x28]
    s.bp = m.r32((f.sp+0x00000028u));
  }
  L005a6206: { // 0x5a6206: 660111 ADD word ptr [ECX],DX
    m.w16((s.cx), integer::add(m.r16((s.cx)),(s.dx & 0xffffu),16,flags));
  }
  L005a6209: { // 0x5a6209: f6470180 TEST byte ptr [EDI + 0x1],0x80
    (void)integer::logical((m.r8((s.di+0x00000001u)))&(0x00000080u),8,flags);
  }
  L005a620d: { // 0x5a620d: 755e JNZ 0x005a626d
    if(integer::condition("JNZ",flags)) goto L005a626d;
  }
  L005a620f: { // 0x5a620f: 8b54242c MOV EDX,dword ptr [ESP + 0x2c]
    s.dx = m.r32((f.sp+0x0000002cu));
  }
  L005a6213: { // 0x5a6213: c644241800 MOV byte ptr [ESP + 0x18],0x0
    m.w8((f.sp+0x00000018u), 0x00000000u);
  }
  L005a6218: { // 0x5a6218: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L005a621a: { // 0x5a621a: 8d0412 LEA EAX,[EDX + EDX*0x1]
    s.ax = (s.dx+(s.dx * 0x00000001u));
  }
  L005a621d: { // 0x5a621d: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L005a621f: { // 0x5a621f: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L005a6220: { // 0x5a6220: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L005a6222: { // 0x5a6222: 7449 JZ 0x005a626d
    if(integer::condition("JZ",flags)) goto L005a626d;
  }
  L005a6224: { // 0x5a6224: 8d5001 LEA EDX,[EAX + 0x1]
    s.dx = (s.ax+0x00000001u);
  }
  L005a6227: { // 0x5a6227: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005a6229: { // 0x5a6229: 668b040e MOV AX,word ptr [ESI + ECX*0x1]
    s.ax = with_ax(s.ax, m.r16((s.si+(s.cx * 0x00000001u))));
  }
  L005a622d: { // 0x5a622d: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L005a6230: { // 0x5a6230: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L005a6232: { // 0x5a6232: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005a6234: { // 0x5a6234: 668b41fe MOV AX,word ptr [ECX + -0x2]
    s.ax = with_ax(s.ax, m.r16((s.cx-0x00000002u)));
  }
  L005a6238: { // 0x5a6238: 2bc3 SUB EAX,EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L005a623a: { // 0x5a623a: 8b5c2418 MOV EBX,dword ptr [ESP + 0x18]
    s.bx = m.r32((f.sp+0x00000018u));
  }
  L005a623e: { // 0x5a623e: 81e3ff000000 AND EBX,0xff
    s.bx = integer::logical((s.bx)&(0x000000ffu),32,flags);
  }
  L005a6244: { // 0x5a6244: 2bc3 SUB EAX,EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L005a6246: { // 0x5a6246: 668941fe MOV word ptr [ECX + -0x2],AX
    m.w16((s.cx-0x00000002u), (s.ax & 0xffffu));
  }
  L005a624a: { // 0x5a624a: c1e810 SHR EAX,0x10
    s.ax = integer::shift(s.ax,0x00000010u,32,flags,integer::Shift::right);
  }
  L005a624d: { // 0x5a624d: 2401 AND AL,0x1
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags));
  }
  L005a624f: { // 0x5a624f: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L005a6250: { // 0x5a6250: 88442418 MOV byte ptr [ESP + 0x18],AL
    m.w8((f.sp+0x00000018u), (s.ax & 0xffu));
  }
  L005a6254: { // 0x5a6254: 75d1 JNZ 0x005a6227
    if(integer::condition("JNZ",flags)) goto L005a6227;
  }
  L005a6256: { // 0x5a6256: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005a6258: { // 0x5a6258: 7413 JZ 0x005a626d
    if(integer::condition("JZ",flags)) goto L005a626d;
  }
  L005a625a: { // 0x5a625a: 66ff0f DEC word ptr [EDI]
    m.w16((s.di), integer::decrement(m.r16((s.di)),16,flags));
  }
  L005a625d: { // 0x5a625d: eb0e JMP 0x005a626d
    goto L005a626d;
  }
  L005a625f: { // 0x5a625f: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L005a6263: { // 0x5a6263: eba1 JMP 0x005a6206
    goto L005a6206;
  }
  L005a6265: { // 0x5a6265: 8b6c2428 MOV EBP,dword ptr [ESP + 0x28]
    s.bp = m.r32((f.sp+0x00000028u));
  }
  L005a6269: { // 0x5a6269: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L005a626d: { // 0x5a626d: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L005a6271: { // 0x5a6271: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L005a6272: { // 0x5a6272: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L005a6276: { // 0x5a6276: 0f8594feffff JNZ 0x005a6110
    if(integer::condition("JNZ",flags)) goto L005a6110;
  }
  L005a627c: { // 0x5a627c: 8b54242c MOV EDX,dword ptr [ESP + 0x2c]
    s.dx = m.r32((f.sp+0x0000002cu));
  }
  L005a6280: { // 0x5a6280: b8748fa500 MOV EAX,0xa58f74
    s.ax = 0x00a58f74u;
  }
  L005a6285: { // 0x5a6285: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L005a6287: { // 0x5a6287: 7e0f JLE 0x005a6298
    if(integer::condition("JLE",flags)) goto L005a6298;
  }
  L005a6289: { // 0x5a6289: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L005a628b: { // 0x5a628b: 8b30 MOV ESI,dword ptr [EAX]
    s.si = m.r32((s.ax));
  }
  L005a628d: { // 0x5a628d: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  L005a6290: { // 0x5a6290: f7d6 NOT ESI
    s.si = (~(s.si)&integer::mask(32));
  }
  L005a6292: { // 0x5a6292: 8970fc MOV dword ptr [EAX + -0x4],ESI
    m.w32((s.ax-0x00000004u), s.si);
  }
  L005a6295: { // 0x5a6295: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L005a6296: { // 0x5a6296: 75f3 JNZ 0x005a628b
    if(integer::condition("JNZ",flags)) goto L005a628b;
  }
  L005a6298: { // 0x5a6298: 8b35748fa500 MOV ESI,dword ptr [0x00a58f74]
    s.si = m.r32((0x00a58f74u));
  }
  L005a629e: { // 0x5a629e: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L005a62a0: { // 0x5a62a0: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L005a62a1: { // 0x5a62a1: b8748fa500 MOV EAX,0xa58f74
    s.ax = 0x00a58f74u;
  }
  L005a62a6: { // 0x5a62a6: 8935748fa500 MOV dword ptr [0x00a58f74],ESI
    m.w32((0x00a58f74u), s.si);
  }
  L005a62ac: { // 0x5a62ac: 750d JNZ 0x005a62bb
    if(integer::condition("JNZ",flags)) goto L005a62bb;
  }
  L005a62ae: { // 0x5a62ae: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  L005a62b1: { // 0x5a62b1: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L005a62b2: { // 0x5a62b2: 7407 JZ 0x005a62bb
    if(integer::condition("JZ",flags)) goto L005a62bb;
  }
  L005a62b4: { // 0x5a62b4: 8b30 MOV ESI,dword ptr [EAX]
    s.si = m.r32((s.ax));
  }
  L005a62b6: { // 0x5a62b6: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L005a62b7: { // 0x5a62b7: 8930 MOV dword ptr [EAX],ESI
    m.w32((s.ax), s.si);
  }
  L005a62b9: { // 0x5a62b9: 74f3 JZ 0x005a62ae
    if(integer::condition("JZ",flags)) goto L005a62ae;
  }
  L005a62bb: { // 0x5a62bb: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L005a62bd: { // 0x5a62bd: 8b15748fa500 MOV EDX,dword ptr [0x00a58f74]
    s.dx = m.r32((0x00a58f74u));
  }
  L005a62c3: { // 0x5a62c3: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L005a62c4: { // 0x5a62c4: b8748fa500 MOV EAX,0xa58f74
    s.ax = 0x00a58f74u;
  }
  L005a62c9: { // 0x5a62c9: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  L005a62cc: { // 0x5a62cc: 8915748fa500 MOV dword ptr [0x00a58f74],EDX
    m.w32((0x00a58f74u), s.dx);
  }
  L005a62d2: { // 0x5a62d2: 7512 JNZ 0x005a62e6
    if(integer::condition("JNZ",flags)) goto L005a62e6;
  }
  L005a62d4: { // 0x5a62d4: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  L005a62d7: { // 0x5a62d7: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L005a62d8: { // 0x5a62d8: 740c JZ 0x005a62e6
    if(integer::condition("JZ",flags)) goto L005a62e6;
  }
  L005a62da: { // 0x5a62da: 8b30 MOV ESI,dword ptr [EAX]
    s.si = m.r32((s.ax));
  }
  L005a62dc: { // 0x5a62dc: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L005a62dd: { // 0x5a62dd: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L005a62df: { // 0x5a62df: 8930 MOV dword ptr [EAX],ESI
    m.w32((s.ax), s.si);
  }
  L005a62e1: { // 0x5a62e1: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  L005a62e4: { // 0x5a62e4: 74ee JZ 0x005a62d4
    if(integer::condition("JZ",flags)) goto L005a62d4;
  }
  L005a62e6: { // 0x5a62e6: 8b4c242c MOV ECX,dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L005a62ea: { // 0x5a62ea: 8b7c2420 MOV EDI,dword ptr [ESP + 0x20]
    s.di = m.r32((f.sp+0x00000020u));
  }
  L005a62ee: { // 0x5a62ee: be748fa500 MOV ESI,0xa58f74
    s.si = 0x00a58f74u;
  }
  L005a62f3: { // 0x5a62f3: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005a62f5: { // 0x5a62f5: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L005a62f7: { // 0x5a62f7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005a62f8: { // 0x5a62f8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005a62f9: { // 0x5a62f9: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005a62fa: { // 0x5a62fa: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005a62fb: { // 0x5a62fb: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L005a62fe: { // 0x5a62fe: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_001a5d00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005a5d00: { // 0x5a5d00: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005a5d01: { // 0x5a5d01: 8b5c240c MOV EBX,dword ptr [ESP + 0xc]
    s.bx = m.r32((f.sp+0x0000000cu));
  }
  L005a5d05: { // 0x5a5d05: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005a5d06: { // 0x5a5d06: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L005a5d08: { // 0x5a5d08: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L005a5d0a: { // 0x5a5d0a: 7e38 JLE 0x005a5d44
    if(integer::condition("JLE",flags)) goto L005a5d44;
  }
  L005a5d0c: { // 0x5a5d0c: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005a5d0d: { // 0x5a5d0d: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005a5d0e: { // 0x5a5d0e: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L005a5d12: { // 0x5a5d12: 81e7ffff0000 AND EDI,0xffff
    s.di = integer::logical((s.di)&(0x0000ffffu),32,flags);
  }
  L005a5d18: { // 0x5a5d18: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005a5d1a: { // 0x5a5d1a: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L005a5d1c: { // 0x5a5d1c: 668b02 MOV AX,word ptr [EDX]
    s.ax = with_ax(s.ax, m.r16((s.dx)));
  }
  L005a5d1f: { // 0x5a5d1f: 668b29 MOV BP,word ptr [ECX]
    s.bp = (s.bp & 0xffff0000u) | ((m.r16((s.cx))) & 0xffffu);
  }
  L005a5d22: { // 0x5a5d22: 0fafc7 IMUL EAX,EDI
    s.ax = integer::imul(s.ax,s.di,32,flags);
  }
  L005a5d25: { // 0x5a5d25: 03ee ADD EBP,ESI
    s.bp = integer::add(s.bp,s.si,32,flags);
  }
  L005a5d27: { // 0x5a5d27: 83c202 ADD EDX,0x2
    s.dx = integer::add(s.dx,0x00000002u,32,flags);
  }
  L005a5d2a: { // 0x5a5d2a: 03c5 ADD EAX,EBP
    s.ax = integer::add(s.ax,s.bp,32,flags);
  }
  L005a5d2c: { // 0x5a5d2c: 668901 MOV word ptr [ECX],AX
    m.w16((s.cx), (s.ax & 0xffffu));
  }
  L005a5d2f: { // 0x5a5d2f: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L005a5d32: { // 0x5a5d32: c1e810 SHR EAX,0x10
    s.ax = integer::shift(s.ax,0x00000010u,32,flags,integer::Shift::right);
  }
  L005a5d35: { // 0x5a5d35: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L005a5d36: { // 0x5a5d36: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L005a5d38: { // 0x5a5d38: 75de JNZ 0x005a5d18
    if(integer::condition("JNZ",flags)) goto L005a5d18;
  }
  L005a5d3a: { // 0x5a5d3a: 660131 ADD word ptr [ECX],SI
    m.w16((s.cx), integer::add(m.r16((s.cx)),(s.si & 0xffffu),16,flags));
  }
  L005a5d3d: { // 0x5a5d3d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005a5d3e: { // 0x5a5d3e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005a5d3f: { // 0x5a5d3f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005a5d40: { // 0x5a5d40: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005a5d41: { // 0x5a5d41: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L005a5d44: { // 0x5a5d44: 660131 ADD word ptr [ECX],SI
    m.w16((s.cx), integer::add(m.r16((s.cx)),(s.si & 0xffffu),16,flags));
  }
  L005a5d47: { // 0x5a5d47: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005a5d48: { // 0x5a5d48: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005a5d49: { // 0x5a5d49: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_001a45b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005a45b0: { // 0x5a45b0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L005a45b3: { // 0x5a45b3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005a45b4: { // 0x5a45b4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005a45b5: { // 0x5a45b5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005a45b6: { // 0x5a45b6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L005a45b8: { // 0x5a45b8: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005a45b9: { // 0x5a45b9: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L005a45bb: { // 0x5a45bb: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L005a45bd: { // 0x5a45bd: 3bf9 CMP EDI,ECX
    (void)integer::sub(s.di,s.cx,32,flags);
  }
  L005a45bf: { // 0x5a45bf: 7423 JZ 0x005a45e4
    if(integer::condition("JZ",flags)) goto L005a45e4;
  }
  L005a45c1: { // 0x5a45c1: 83ff20 CMP EDI,0x20
    (void)integer::sub(s.di,0x00000020u,32,flags);
  }
  L005a45c4: { // 0x5a45c4: 7528 JNZ 0x005a45ee
    if(integer::condition("JNZ",flags)) goto L005a45ee;
  }
  L005a45c6: { // 0x5a45c6: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L005a45ca: { // 0x5a45ca: 8d0496 LEA EAX,[ESI + EDX*0x4]
    s.ax = (s.si+(s.dx * 0x00000004u));
  }
  L005a45cd: { // 0x5a45cd: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L005a45cf: { // 0x5a45cf: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L005a45d0: { // 0x5a45d0: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L005a45d2: { // 0x5a45d2: 7410 JZ 0x005a45e4
    if(integer::condition("JZ",flags)) goto L005a45e4;
  }
  L005a45d4: { // 0x5a45d4: 8d7201 LEA ESI,[EDX + 0x1]
    s.si = (s.dx+0x00000001u);
  }
  L005a45d7: { // 0x5a45d7: 8b50fc MOV EDX,dword ptr [EAX + -0x4]
    s.dx = m.r32((s.ax-0x00000004u));
  }
  L005a45da: { // 0x5a45da: 83e804 SUB EAX,0x4
    s.ax = integer::sub(s.ax,0x00000004u,32,flags);
  }
  L005a45dd: { // 0x5a45dd: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L005a45de: { // 0x5a45de: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L005a45e0: { // 0x5a45e0: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L005a45e2: { // 0x5a45e2: 75f3 JNZ 0x005a45d7
    if(integer::condition("JNZ",flags)) goto L005a45d7;
  }
  L005a45e4: { // 0x5a45e4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005a45e5: { // 0x5a45e5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005a45e6: { // 0x5a45e6: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005a45e7: { // 0x5a45e7: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005a45e8: { // 0x5a45e8: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L005a45eb: { // 0x5a45eb: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L005a45ee: { // 0x5a45ee: 7d6d JGE 0x005a465d
    if(integer::condition("JGE",flags)) goto L005a465d;
  }
  L005a45f0: { // 0x5a45f0: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L005a45f4: { // 0x5a45f4: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L005a45f8: { // 0x5a45f8: bb01000000 MOV EBX,0x1
    s.bx = 0x00000001u;
  }
  L005a45fd: { // 0x5a45fd: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005a45ff: { // 0x5a45ff: d3e3 SHL EBX,CL
    s.bx = integer::shift(s.bx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L005a4601: { // 0x5a4601: bd20000000 MOV EBP,0x20
    s.bp = 0x00000020u;
  }
  L005a4606: { // 0x5a4606: 8d3486 LEA ESI,[ESI + EAX*0x4]
    s.si = (s.si+(s.ax * 0x00000004u));
  }
  L005a4609: { // 0x5a4609: 2bef SUB EBP,EDI
    s.bp = integer::sub(s.bp,s.di,32,flags);
  }
  L005a460b: { // 0x5a460b: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L005a460d: { // 0x5a460d: 896c2414 MOV dword ptr [ESP + 0x14],EBP
    m.w32((f.sp+0x00000014u), s.bp);
  }
  L005a4611: { // 0x5a4611: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L005a4612: { // 0x5a4612: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L005a4613: { // 0x5a4613: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005a4615: { // 0x5a4615: 74cd JZ 0x005a45e4
    if(integer::condition("JZ",flags)) goto L005a45e4;
  }
  L005a4617: { // 0x5a4617: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L005a4618: { // 0x5a4618: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L005a461c: { // 0x5a461c: eb04 JMP 0x005a4622
    goto L005a4622;
  }
  L005a461e: { // 0x5a461e: 8b6c2414 MOV EBP,dword ptr [ESP + 0x14]
    s.bp = m.r32((f.sp+0x00000014u));
  }
  L005a4622: { // 0x5a4622: 8b46fc MOV EAX,dword ptr [ESI + -0x4]
    s.ax = m.r32((s.si-0x00000004u));
  }
  L005a4625: { // 0x5a4625: 83ee04 SUB ESI,0x4
    s.si = integer::sub(s.si,0x00000004u,32,flags);
  }
  L005a4628: { // 0x5a4628: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005a462a: { // 0x5a462a: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L005a462c: { // 0x5a462c: d3e8 SHR EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  L005a462e: { // 0x5a462e: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L005a4632: { // 0x5a4632: 23d3 AND EDX,EBX
    s.dx = integer::logical((s.dx)&(s.bx),32,flags);
  }
  L005a4634: { // 0x5a4634: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L005a4638: { // 0x5a4638: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L005a463a: { // 0x5a463a: 8b6c241c MOV EBP,dword ptr [ESP + 0x1c]
    s.bp = m.r32((f.sp+0x0000001cu));
  }
  L005a463e: { // 0x5a463e: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L005a4642: { // 0x5a4642: d3e5 SHL EBP,CL
    s.bp = integer::shift(s.bp,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L005a4644: { // 0x5a4644: 0bc5 OR EAX,EBP
    s.ax = integer::logical((s.ax)|(s.bp),32,flags);
  }
  L005a4646: { // 0x5a4646: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  L005a4648: { // 0x5a4648: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L005a464c: { // 0x5a464c: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L005a464d: { // 0x5a464d: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L005a4651: { // 0x5a4651: 75cb JNZ 0x005a461e
    if(integer::condition("JNZ",flags)) goto L005a461e;
  }
  L005a4653: { // 0x5a4653: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005a4654: { // 0x5a4654: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005a4655: { // 0x5a4655: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005a4656: { // 0x5a4656: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005a4657: { // 0x5a4657: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L005a465a: { // 0x5a465a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L005a465d: { // 0x5a465d: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L005a465f: { // 0x5a465f: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L005a4660: { // 0x5a4660: 83e21f AND EDX,0x1f
    s.dx = integer::logical((s.dx)&(0x0000001fu),32,flags);
  }
  L005a4663: { // 0x5a4663: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L005a4665: { // 0x5a4665: c1f805 SAR EAX,0x5
    s.ax = integer::shift(s.ax,0x00000005u,32,flags,integer::Shift::arithmetic_right);
  }
  L005a4668: { // 0x5a4668: 81e71f000080 AND EDI,0x8000001f
    s.di = integer::logical((s.di)&(0x8000001fu),32,flags);
  }
  L005a466e: { // 0x5a466e: 7905 JNS 0x005a4675
    if(integer::condition("JNS",flags)) goto L005a4675;
  }
  L005a4670: { // 0x5a4670: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L005a4671: { // 0x5a4671: 83cfe0 OR EDI,0xffffffe0
    s.di = integer::logical((s.di)|(0xffffffe0u),32,flags);
  }
  L005a4674: { // 0x5a4674: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L005a4675: { // 0x5a4675: 8b5c241c MOV EBX,dword ptr [ESP + 0x1c]
    s.bx = m.r32((f.sp+0x0000001cu));
  }
  L005a4679: { // 0x5a4679: 8d4bff LEA ECX,[EBX + -0x1]
    s.cx = (s.bx-0x00000001u);
  }
  L005a467c: { // 0x5a467c: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L005a467e: { // 0x5a467e: 7d33 JGE 0x005a46b3
    if(integer::condition("JGE",flags)) goto L005a46b3;
  }
  L005a4680: { // 0x5a4680: ba20000000 MOV EDX,0x20
    s.dx = 0x00000020u;
  }
  L005a4685: { // 0x5a4685: 2bd7 SUB EDX,EDI
    s.dx = integer::sub(s.dx,s.di,32,flags);
  }
  L005a4687: { // 0x5a4687: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L005a4689: { // 0x5a4689: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L005a468d: { // 0x5a468d: 8b5c8604 MOV EBX,dword ptr [ESI + EAX*0x4 + 0x4]
    s.bx = m.r32((s.si+(s.ax * 0x00000004u)+0x00000004u));
  }
  L005a4691: { // 0x5a4691: 8b2c86 MOV EBP,dword ptr [ESI + EAX*0x4]
    s.bp = m.r32((s.si+(s.ax * 0x00000004u)));
  }
  L005a4694: { // 0x5a4694: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L005a4696: { // 0x5a4696: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  L005a4699: { // 0x5a4699: d3e3 SHL EBX,CL
    s.bx = integer::shift(s.bx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L005a469b: { // 0x5a469b: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005a469d: { // 0x5a469d: d3ed SHR EBP,CL
    s.bp = integer::shift(s.bp,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  L005a469f: { // 0x5a469f: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L005a46a3: { // 0x5a46a3: 0bdd OR EBX,EBP
    s.bx = integer::logical((s.bx)|(s.bp),32,flags);
  }
  L005a46a5: { // 0x5a46a5: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L005a46a6: { // 0x5a46a6: 895efc MOV dword ptr [ESI + -0x4],EBX
    m.w32((s.si-0x00000004u), s.bx);
  }
  L005a46a9: { // 0x5a46a9: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L005a46ad: { // 0x5a46ad: 75de JNZ 0x005a468d
    if(integer::condition("JNZ",flags)) goto L005a468d;
  }
  L005a46af: { // 0x5a46af: 8b5c241c MOV EBX,dword ptr [ESP + 0x1c]
    s.bx = m.r32((f.sp+0x0000001cu));
  }
  L005a46b3: { // 0x5a46b3: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L005a46b5: { // 0x5a46b5: 7d0d JGE 0x005a46c4
    if(integer::condition("JGE",flags)) goto L005a46c4;
  }
  L005a46b7: { // 0x5a46b7: 8b1486 MOV EDX,dword ptr [ESI + EAX*0x4]
    s.dx = m.r32((s.si+(s.ax * 0x00000004u)));
  }
  L005a46ba: { // 0x5a46ba: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005a46bc: { // 0x5a46bc: d3ea SHR EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  L005a46be: { // 0x5a46be: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  L005a46c1: { // 0x5a46c1: 8956fc MOV dword ptr [ESI + -0x4],EDX
    m.w32((s.si-0x00000004u), s.dx);
  }
  L005a46c4: { // 0x5a46c4: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L005a46c6: { // 0x5a46c6: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L005a46c8: { // 0x5a46c8: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L005a46ca: { // 0x5a46ca: 7c02 JL 0x005a46ce
    if(integer::condition("JL",flags)) goto L005a46ce;
  }
  L005a46cc: { // 0x5a46cc: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L005a46ce: { // 0x5a46ce: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L005a46d0: { // 0x5a46d0: 0f8d0effffff JGE 0x005a45e4
    if(integer::condition("JGE",flags)) goto L005a45e4;
  }
  L005a46d6: { // 0x5a46d6: c70600000000 MOV dword ptr [ESI],0x0
    m.w32((s.si), 0x00000000u);
  }
  L005a46dc: { // 0x5a46dc: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  L005a46df: { // 0x5a46df: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L005a46e0: { // 0x5a46e0: ebe4 JMP 0x005a46c6
    goto L005a46c6;
  }
}
void f_001a58e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005a58e0: { // 0x5a58e0: 81ec14010000 SUB ESP,0x114
    f.sp = integer::sub(f.sp,0x00000114u,32,flags);
  }
  L005a58e6: { // 0x5a58e6: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005a58e7: { // 0x5a58e7: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L005a58e9: { // 0x5a58e9: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L005a58eb: { // 0x5a58eb: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005a58ec: { // 0x5a58ec: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L005a58ee: { // 0x5a58ee: 8bb42420010000 MOV ESI,dword ptr [ESP + 0x120]
    s.si = m.r32((f.sp+0x00000120u));
  }
  L005a58f5: { // 0x5a58f5: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005a58f7: { // 0x5a58f7: 8944240c MOV dword ptr [ESP + 0xc],EAX
    m.w32((f.sp+0x0000000cu), s.ax);
  }
  L005a58fb: { // 0x5a58fb: 752e JNZ 0x005a592b
    if(integer::condition("JNZ",flags)) goto L005a592b;
  }
  L005a58fd: { // 0x5a58fd: 8b54b0fc MOV EDX,dword ptr [EAX + ESI*0x4 + -0x4]
    s.dx = m.r32((s.ax+(s.si * 0x00000004u)-0x00000004u));
  }
  L005a5901: { // 0x5a5901: 8d44b0fc LEA EAX,[EAX + ESI*0x4 + -0x4]
    s.ax = (s.ax+(s.si * 0x00000004u)-0x00000004u);
  }
  L005a5905: { // 0x5a5905: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L005a5907: { // 0x5a5907: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005a5909: { // 0x5a5909: 750d JNZ 0x005a5918
    if(integer::condition("JNZ",flags)) goto L005a5918;
  }
  L005a590b: { // 0x5a590b: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L005a590c: { // 0x5a590c: 740a JZ 0x005a5918
    if(integer::condition("JZ",flags)) goto L005a5918;
  }
  L005a590e: { // 0x5a590e: 8b50fc MOV EDX,dword ptr [EAX + -0x4]
    s.dx = m.r32((s.ax-0x00000004u));
  }
  L005a5911: { // 0x5a5911: 83e804 SUB EAX,0x4
    s.ax = integer::sub(s.ax,0x00000004u,32,flags);
  }
  L005a5914: { // 0x5a5914: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L005a5916: { // 0x5a5916: 74f3 JZ 0x005a590b
    if(integer::condition("JZ",flags)) goto L005a590b;
  }
  L005a5918: { // 0x5a5918: 83f901 CMP ECX,0x1
    (void)integer::sub(s.cx,0x00000001u,32,flags);
  }
  L005a591b: { // 0x5a591b: 7f0e JG 0x005a592b
    if(integer::condition("JG",flags)) goto L005a592b;
  }
  L005a591d: { // 0x5a591d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005a591e: { // 0x5a591e: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L005a5921: { // 0x5a5921: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005a5922: { // 0x5a5922: 81c414010000 ADD ESP,0x114
    f.sp = integer::add(f.sp,0x00000114u,32,flags);
  }
  L005a5928: { // 0x5a5928: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L005a592b: { // 0x5a592b: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005a592c: { // 0x5a592c: 8d2cb500000000 LEA EBP,[ESI*0x4 + 0x0]
    s.bp = ((s.si * 0x00000004u)+0x00000000u);
  }
  L005a5933: { // 0x5a5933: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L005a5935: { // 0x5a5935: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005a5936: { // 0x5a5936: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L005a5938: { // 0x5a5938: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005a593a: { // 0x5a593a: 8d7c2424 LEA EDI,[ESP + 0x24]
    s.di = (f.sp+0x00000024u);
  }
  L005a593e: { // 0x5a593e: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L005a5941: { // 0x5a5941: f3ab STOSD.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::count);
  }
  L005a5943: { // 0x5a5943: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L005a5945: { // 0x5a5945: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  L005a5948: { // 0x5a5948: f3aa STOSB.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,8u,Repeat::count);
  }
  L005a594a: { // 0x5a594a: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L005a594c: { // 0x5a594c: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005a594e: { // 0x5a594e: 8bfb MOV EDI,EBX
    s.di = s.bx;
  }
  L005a5950: { // 0x5a5950: c744242400000000 MOV dword ptr [ESP + 0x24],0x0
    m.w32((f.sp+0x00000024u), 0x00000000u);
  }
  L005a5958: { // 0x5a5958: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L005a595b: { // 0x5a595b: f3ab STOSD.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::count);
  }
  L005a595d: { // 0x5a595d: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L005a595f: { // 0x5a595f: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  L005a5962: { // 0x5a5962: f3aa STOSB.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,8u,Repeat::count);
  }
  L005a5964: { // 0x5a5964: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L005a5968: { // 0x5a5968: c70300000000 MOV dword ptr [EBX],0x0
    m.w32((s.bx), 0x00000000u);
  }
  L005a596e: { // 0x5a596e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005a5970: { // 0x5a5970: 8b5428fc MOV EDX,dword ptr [EAX + EBP*0x1 + -0x4]
    s.dx = m.r32((s.ax+(s.bp * 0x00000001u)-0x00000004u));
  }
  L005a5974: { // 0x5a5974: 8d4428fc LEA EAX,[EAX + EBP*0x1 + -0x4]
    s.ax = (s.ax+(s.bp * 0x00000001u)-0x00000004u);
  }
  L005a5978: { // 0x5a5978: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L005a597a: { // 0x5a597a: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L005a597e: { // 0x5a597e: 750d JNZ 0x005a598d
    if(integer::condition("JNZ",flags)) goto L005a598d;
  }
  L005a5980: { // 0x5a5980: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L005a5981: { // 0x5a5981: 740e JZ 0x005a5991
    if(integer::condition("JZ",flags)) goto L005a5991;
  }
  L005a5983: { // 0x5a5983: 8b50fc MOV EDX,dword ptr [EAX + -0x4]
    s.dx = m.r32((s.ax-0x00000004u));
  }
  L005a5986: { // 0x5a5986: 83e804 SUB EAX,0x4
    s.ax = integer::sub(s.ax,0x00000004u,32,flags);
  }
  L005a5989: { // 0x5a5989: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L005a598b: { // 0x5a598b: 74f3 JZ 0x005a5980
    if(integer::condition("JZ",flags)) goto L005a5980;
  }
  L005a598d: { // 0x5a598d: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005a598f: { // 0x5a598f: 7504 JNZ 0x005a5995
    if(integer::condition("JNZ",flags)) goto L005a5995;
  }
  L005a5991: { // 0x5a5991: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L005a5993: { // 0x5a5993: eb1f JMP 0x005a59b4
    goto L005a59b4;
  }
  L005a5995: { // 0x5a5995: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L005a5999: { // 0x5a5999: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L005a599b: { // 0x5a599b: ba00000080 MOV EDX,0x80000000
    s.dx = 0x80000000u;
  }
  L005a59a0: { // 0x5a59a0: 8b4c8efc MOV ECX,dword ptr [ESI + ECX*0x4 + -0x4]
    s.cx = m.r32((s.si+(s.cx * 0x00000004u)-0x00000004u));
  }
  L005a59a4: { // 0x5a59a4: c1e005 SHL EAX,0x5
    s.ax = integer::shift(s.ax,0x00000005u,32,flags,integer::Shift::left);
  }
  L005a59a7: { // 0x5a59a7: 85ca TEST EDX,ECX
    (void)integer::logical((s.dx)&(s.cx),32,flags);
  }
  L005a59a9: { // 0x5a59a9: 7507 JNZ 0x005a59b2
    if(integer::condition("JNZ",flags)) goto L005a59b2;
  }
  L005a59ab: { // 0x5a59ab: d1ea SHR EDX,0x1
    s.dx = integer::shift(s.dx,0x00000001u,32,flags,integer::Shift::right);
  }
  L005a59ad: { // 0x5a59ad: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L005a59ae: { // 0x5a59ae: 85ca TEST EDX,ECX
    (void)integer::logical((s.dx)&(s.cx),32,flags);
  }
  L005a59b0: { // 0x5a59b0: 74f9 JZ 0x005a59ab
    if(integer::condition("JZ",flags)) goto L005a59ab;
  }
  L005a59b2: { // 0x5a59b2: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L005a59b4: { // 0x5a59b4: 8d4601 LEA EAX,[ESI + 0x1]
    s.ax = (s.si+0x00000001u);
  }
  L005a59b7: { // 0x5a59b7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005a59b9: { // 0x5a59b9: 7506 JNZ 0x005a59c1
    if(integer::condition("JNZ",flags)) goto L005a59c1;
  }
  L005a59bb: { // 0x5a59bb: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L005a59bf: { // 0x5a59bf: eb1b JMP 0x005a59dc
    goto L005a59dc;
  }
  L005a59c1: { // 0x5a59c1: 8d48ff LEA ECX,[EAX + -0x1]
    s.cx = (s.ax-0x00000001u);
  }
  L005a59c4: { // 0x5a59c4: 81e11f000080 AND ECX,0x8000001f
    s.cx = integer::logical((s.cx)&(0x8000001fu),32,flags);
  }
  L005a59ca: { // 0x5a59ca: 7905 JNS 0x005a59d1
    if(integer::condition("JNS",flags)) goto L005a59d1;
  }
  L005a59cc: { // 0x5a59cc: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L005a59cd: { // 0x5a59cd: 83c9e0 OR ECX,0xffffffe0
    s.cx = integer::logical((s.cx)|(0xffffffe0u),32,flags);
  }
  L005a59d0: { // 0x5a59d0: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L005a59d1: { // 0x5a59d1: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L005a59d6: { // 0x5a59d6: d3e0 SHL EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L005a59d8: { // 0x5a59d8: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L005a59dc: { // 0x5a59dc: 8d7eff LEA EDI,[ESI + -0x1]
    s.di = (s.si-0x00000001u);
  }
  L005a59df: { // 0x5a59df: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L005a59e4: { // 0x5a59e4: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005a59e6: { // 0x5a59e6: c1e905 SHR ECX,0x5
    s.cx = integer::shift(s.cx,0x00000005u,32,flags,integer::Shift::right);
  }
  L005a59e9: { // 0x5a59e9: 8d448c24 LEA EAX,[ESP + ECX*0x4 + 0x24]
    s.ax = (f.sp+(s.cx * 0x00000004u)+0x00000024u);
  }
  L005a59ed: { // 0x5a59ed: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005a59ef: { // 0x5a59ef: 83e11f AND ECX,0x1f
    s.cx = integer::logical((s.cx)&(0x0000001fu),32,flags);
  }
  L005a59f2: { // 0x5a59f2: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L005a59f4: { // 0x5a59f4: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L005a59f6: { // 0x5a59f6: 0bca OR ECX,EDX
    s.cx = integer::logical((s.cx)|(s.dx),32,flags);
  }
  L005a59f8: { // 0x5a59f8: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L005a59fa: { // 0x5a59fa: 8d4620 LEA EAX,[ESI + 0x20]
    s.ax = (s.si+0x00000020u);
  }
  L005a59fd: { // 0x5a59fd: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L005a59fe: { // 0x5a59fe: 83e21f AND EDX,0x1f
    s.dx = integer::logical((s.dx)&(0x0000001fu),32,flags);
  }
  L005a5a01: { // 0x5a5a01: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L005a5a03: { // 0x5a5a03: c1f805 SAR EAX,0x5
    s.ax = integer::shift(s.ax,0x00000005u,32,flags,integer::Shift::arithmetic_right);
  }
  L005a5a06: { // 0x5a5a06: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L005a5a08: { // 0x5a5a08: 8d5c83fc LEA EBX,[EBX + EAX*0x4 + -0x4]
    s.bx = (s.bx+(s.ax * 0x00000004u)-0x00000004u);
  }
  L005a5a0c: { // 0x5a5a0c: 0f84c5000000 JZ 0x005a5ad7
    if(integer::condition("JZ",flags)) goto L005a5ad7;
  }
  L005a5a12: { // 0x5a5a12: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L005a5a13: { // 0x5a5a13: 8d6c2c20 LEA EBP,[ESP + EBP*0x1 + 0x20]
    s.bp = (f.sp+(s.bp * 0x00000001u)+0x00000020u);
  }
  L005a5a17: { // 0x5a5a17: 897c241c MOV dword ptr [ESP + 0x1c],EDI
    m.w32((f.sp+0x0000001cu), s.di);
  }
  L005a5a1b: { // 0x5a5a1b: 8bbc2428010000 MOV EDI,dword ptr [ESP + 0x128]
    s.di = m.r32((f.sp+0x00000128u));
  }
  L005a5a22: { // 0x5a5a22: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L005a5a27: { // 0x5a5a27: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005a5a28: { // 0x5a5a28: 8d4c2428 LEA ECX,[ESP + 0x28]
    s.cx = (f.sp+0x00000028u);
  }
  L005a5a2c: { // 0x5a5a2c: e8bfecffff CALL 0x005a46f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005a46f0u,5921329u); flags=s.arithmetic_flags;
  }
  L005a5a31: { // 0x5a5a31: 8b5500 MOV EDX,dword ptr [EBP]
    s.dx = m.r32((s.bp));
  }
  L005a5a34: { // 0x5a5a34: 8bf7 MOV ESI,EDI
    s.si = s.di;
  }
  L005a5a36: { // 0x5a5a36: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L005a5a3a: { // 0x5a5a3a: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L005a5a3c: { // 0x5a5a3c: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L005a5a3e: { // 0x5a5a3e: 7271 JC 0x005a5ab1
    if(integer::condition("JC",flags)) goto L005a5ab1;
  }
  L005a5a40: { // 0x5a5a40: 8bd5 MOV EDX,EBP
    s.dx = s.bp;
  }
  L005a5a42: { // 0x5a5a42: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L005a5a44: { // 0x5a5a44: 390c02 CMP dword ptr [EDX + EAX*0x1],ECX
    (void)integer::sub(m.r32((s.dx+(s.ax * 0x00000001u))),s.cx,32,flags);
  }
  L005a5a47: { // 0x5a5a47: 770f JA 0x005a5a58
    if(integer::condition("JA",flags)) goto L005a5a58;
  }
  L005a5a49: { // 0x5a5a49: 83e804 SUB EAX,0x4
    s.ax = integer::sub(s.ax,0x00000004u,32,flags);
  }
  L005a5a4c: { // 0x5a5a4c: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L005a5a4d: { // 0x5a5a4d: 7409 JZ 0x005a5a58
    if(integer::condition("JZ",flags)) goto L005a5a58;
  }
  L005a5a4f: { // 0x5a5a4f: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L005a5a51: { // 0x5a5a51: 390c02 CMP dword ptr [EDX + EAX*0x1],ECX
    (void)integer::sub(m.r32((s.dx+(s.ax * 0x00000001u))),s.cx,32,flags);
  }
  L005a5a54: { // 0x5a5a54: 73f1 JNC 0x005a5a47
    if(integer::condition("JNC",flags)) goto L005a5a47;
  }
  L005a5a56: { // 0x5a5a56: eb59 JMP 0x005a5ab1
    goto L005a5ab1;
  }
  L005a5a58: { // 0x5a5a58: 8d043f LEA EAX,[EDI + EDI*0x1]
    s.ax = (s.di+(s.di * 0x00000001u));
  }
  L005a5a5b: { // 0x5a5a5b: c644241800 MOV byte ptr [ESP + 0x18],0x0
    m.w8((f.sp+0x00000018u), 0x00000000u);
  }
  L005a5a60: { // 0x5a5a60: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L005a5a62: { // 0x5a5a62: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L005a5a63: { // 0x5a5a63: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L005a5a65: { // 0x5a5a65: 8d4c2424 LEA ECX,[ESP + 0x24]
    s.cx = (f.sp+0x00000024u);
  }
  L005a5a69: { // 0x5a5a69: 743c JZ 0x005a5aa7
    if(integer::condition("JZ",flags)) goto L005a5aa7;
  }
  L005a5a6b: { // 0x5a5a6b: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L005a5a6f: { // 0x5a5a6f: 8d742424 LEA ESI,[ESP + 0x24]
    s.si = (f.sp+0x00000024u);
  }
  L005a5a73: { // 0x5a5a73: 2bd6 SUB EDX,ESI
    s.dx = integer::sub(s.dx,s.si,32,flags);
  }
  L005a5a75: { // 0x5a5a75: 8d7001 LEA ESI,[EAX + 0x1]
    s.si = (s.ax+0x00000001u);
  }
  L005a5a78: { // 0x5a5a78: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005a5a7a: { // 0x5a5a7a: 668b040a MOV AX,word ptr [EDX + ECX*0x1]
    s.ax = with_ax(s.ax, m.r16((s.dx+(s.cx * 0x00000001u))));
  }
  L005a5a7e: { // 0x5a5a7e: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L005a5a81: { // 0x5a5a81: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L005a5a83: { // 0x5a5a83: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005a5a85: { // 0x5a5a85: 668b41fe MOV AX,word ptr [ECX + -0x2]
    s.ax = with_ax(s.ax, m.r16((s.cx-0x00000002u)));
  }
  L005a5a89: { // 0x5a5a89: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  L005a5a8b: { // 0x5a5a8b: 8b7c2418 MOV EDI,dword ptr [ESP + 0x18]
    s.di = m.r32((f.sp+0x00000018u));
  }
  L005a5a8f: { // 0x5a5a8f: 81e7ff000000 AND EDI,0xff
    s.di = integer::logical((s.di)&(0x000000ffu),32,flags);
  }
  L005a5a95: { // 0x5a5a95: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  L005a5a97: { // 0x5a5a97: 668941fe MOV word ptr [ECX + -0x2],AX
    m.w16((s.cx-0x00000002u), (s.ax & 0xffffu));
  }
  L005a5a9b: { // 0x5a5a9b: c1e810 SHR EAX,0x10
    s.ax = integer::shift(s.ax,0x00000010u,32,flags,integer::Shift::right);
  }
  L005a5a9e: { // 0x5a5a9e: 2401 AND AL,0x1
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags));
  }
  L005a5aa0: { // 0x5a5aa0: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L005a5aa1: { // 0x5a5aa1: 88442418 MOV byte ptr [ESP + 0x18],AL
    m.w8((f.sp+0x00000018u), (s.ax & 0xffu));
  }
  L005a5aa5: { // 0x5a5aa5: 75d1 JNZ 0x005a5a78
    if(integer::condition("JNZ",flags)) goto L005a5a78;
  }
  L005a5aa7: { // 0x5a5aa7: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L005a5aab: { // 0x5a5aab: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L005a5aad: { // 0x5a5aad: 0bc1 OR EAX,ECX
    s.ax = integer::logical((s.ax)|(s.cx),32,flags);
  }
  L005a5aaf: { // 0x5a5aaf: 8903 MOV dword ptr [EBX],EAX
    m.w32((s.bx), s.ax);
  }
  L005a5ab1: { // 0x5a5ab1: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L005a5ab5: { // 0x5a5ab5: d1e8 SHR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::right);
  }
  L005a5ab7: { // 0x5a5ab7: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L005a5abb: { // 0x5a5abb: 750b JNZ 0x005a5ac8
    if(integer::condition("JNZ",flags)) goto L005a5ac8;
  }
  L005a5abd: { // 0x5a5abd: c744241000000080 MOV dword ptr [ESP + 0x10],0x80000000
    m.w32((f.sp+0x00000010u), 0x80000000u);
  }
  L005a5ac5: { // 0x5a5ac5: 83eb04 SUB EBX,0x4
    s.bx = integer::sub(s.bx,0x00000004u,32,flags);
  }
  L005a5ac8: { // 0x5a5ac8: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L005a5acc: { // 0x5a5acc: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L005a5acd: { // 0x5a5acd: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L005a5ad1: { // 0x5a5ad1: 0f8544ffffff JNZ 0x005a5a1b
    if(integer::condition("JNZ",flags)) goto L005a5a1b;
  }
  L005a5ad7: { // 0x5a5ad7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005a5ad8: { // 0x5a5ad8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005a5ad9: { // 0x5a5ad9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005a5ada: { // 0x5a5ada: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005a5adc: { // 0x5a5adc: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005a5add: { // 0x5a5add: 81c414010000 ADD ESP,0x114
    f.sp = integer::add(f.sp,0x00000114u,32,flags);
  }
  L005a5ae3: { // 0x5a5ae3: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_001a46f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005a46f0: { // 0x5a46f0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005a46f1: { // 0x5a46f1: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005a46f2: { // 0x5a46f2: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005a46f3: { // 0x5a46f3: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005a46f4: { // 0x5a46f4: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005a46f5: { // 0x5a46f5: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L005a46f7: { // 0x5a46f7: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L005a46f9: { // 0x5a46f9: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L005a46fb: { // 0x5a46fb: 7421 JZ 0x005a471e
    if(integer::condition("JZ",flags)) goto L005a471e;
  }
  L005a46fd: { // 0x5a46fd: 83ff20 CMP EDI,0x20
    (void)integer::sub(s.di,0x00000020u,32,flags);
  }
  L005a4700: { // 0x5a4700: 7524 JNZ 0x005a4726
    if(integer::condition("JNZ",flags)) goto L005a4726;
  }
  L005a4702: { // 0x5a4702: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L005a4706: { // 0x5a4706: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005a4708: { // 0x5a4708: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L005a470a: { // 0x5a470a: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L005a470b: { // 0x5a470b: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L005a470d: { // 0x5a470d: 740f JZ 0x005a471e
    if(integer::condition("JZ",flags)) goto L005a471e;
  }
  L005a470f: { // 0x5a470f: 8d5101 LEA EDX,[ECX + 0x1]
    s.dx = (s.cx+0x00000001u);
  }
  L005a4712: { // 0x5a4712: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L005a4714: { // 0x5a4714: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  L005a4716: { // 0x5a4716: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  L005a4719: { // 0x5a4719: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L005a471a: { // 0x5a471a: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L005a471c: { // 0x5a471c: 75f4 JNZ 0x005a4712
    if(integer::condition("JNZ",flags)) goto L005a4712;
  }
  L005a471e: { // 0x5a471e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005a471f: { // 0x5a471f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005a4720: { // 0x5a4720: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005a4721: { // 0x5a4721: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005a4722: { // 0x5a4722: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005a4723: { // 0x5a4723: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L005a4726: { // 0x5a4726: 7d53 JGE 0x005a477b
    if(integer::condition("JGE",flags)) goto L005a477b;
  }
  L005a4728: { // 0x5a4728: b820000000 MOV EAX,0x20
    s.ax = 0x00000020u;
  }
  L005a472d: { // 0x5a472d: 83cbff OR EBX,0xffffffff
    s.bx = integer::logical((s.bx)|(0xffffffffu),32,flags);
  }
  L005a4730: { // 0x5a4730: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  L005a4732: { // 0x5a4732: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005a4734: { // 0x5a4734: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L005a4738: { // 0x5a4738: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L005a473c: { // 0x5a473c: d3eb SHR EBX,CL
    s.bx = integer::shift(s.bx,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  L005a473e: { // 0x5a473e: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L005a4740: { // 0x5a4740: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L005a4742: { // 0x5a4742: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L005a4743: { // 0x5a4743: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005a4745: { // 0x5a4745: f7d3 NOT EBX
    s.bx = (~(s.bx)&integer::mask(32));
  }
  L005a4747: { // 0x5a4747: 74d5 JZ 0x005a471e
    if(integer::condition("JZ",flags)) goto L005a471e;
  }
  L005a4749: { // 0x5a4749: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L005a474a: { // 0x5a474a: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L005a474e: { // 0x5a474e: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005a4750: { // 0x5a4750: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005a4752: { // 0x5a4752: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L005a4754: { // 0x5a4754: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  L005a4757: { // 0x5a4757: d3e0 SHL EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L005a4759: { // 0x5a4759: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L005a475d: { // 0x5a475d: 23d3 AND EDX,EBX
    s.dx = integer::logical((s.dx)&(s.bx),32,flags);
  }
  L005a475f: { // 0x5a475f: d3ed SHR EBP,CL
    s.bp = integer::shift(s.bp,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  L005a4761: { // 0x5a4761: 0bc5 OR EAX,EBP
    s.ax = integer::logical((s.ax)|(s.bp),32,flags);
  }
  L005a4763: { // 0x5a4763: 8bea MOV EBP,EDX
    s.bp = s.dx;
  }
  L005a4765: { // 0x5a4765: 8946fc MOV dword ptr [ESI + -0x4],EAX
    m.w32((s.si-0x00000004u), s.ax);
  }
  L005a4768: { // 0x5a4768: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L005a476c: { // 0x5a476c: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L005a476d: { // 0x5a476d: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L005a4771: { // 0x5a4771: 75db JNZ 0x005a474e
    if(integer::condition("JNZ",flags)) goto L005a474e;
  }
  L005a4773: { // 0x5a4773: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005a4774: { // 0x5a4774: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005a4775: { // 0x5a4775: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005a4776: { // 0x5a4776: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005a4777: { // 0x5a4777: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005a4778: { // 0x5a4778: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L005a477b: { // 0x5a477b: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L005a477d: { // 0x5a477d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L005a477e: { // 0x5a477e: 83e21f AND EDX,0x1f
    s.dx = integer::logical((s.dx)&(0x0000001fu),32,flags);
  }
  L005a4781: { // 0x5a4781: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L005a4783: { // 0x5a4783: c1f805 SAR EAX,0x5
    s.ax = integer::shift(s.ax,0x00000005u,32,flags,integer::Shift::arithmetic_right);
  }
  L005a4786: { // 0x5a4786: 81e71f000080 AND EDI,0x8000001f
    s.di = integer::logical((s.di)&(0x8000001fu),32,flags);
  }
  L005a478c: { // 0x5a478c: 7905 JNS 0x005a4793
    if(integer::condition("JNS",flags)) goto L005a4793;
  }
  L005a478e: { // 0x5a478e: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L005a478f: { // 0x5a478f: 83cfe0 OR EDI,0xffffffe0
    s.di = integer::logical((s.di)|(0xffffffe0u),32,flags);
  }
  L005a4792: { // 0x5a4792: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L005a4793: { // 0x5a4793: 8b5c2418 MOV EBX,dword ptr [ESP + 0x18]
    s.bx = m.r32((f.sp+0x00000018u));
  }
  L005a4797: { // 0x5a4797: 8d4bff LEA ECX,[EBX + -0x1]
    s.cx = (s.bx-0x00000001u);
  }
  L005a479a: { // 0x5a479a: 8d549efc LEA EDX,[ESI + EBX*0x4 + -0x4]
    s.dx = (s.si+(s.bx * 0x00000004u)-0x00000004u);
  }
  L005a479e: { // 0x5a479e: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L005a47a0: { // 0x5a47a0: 7d47 JGE 0x005a47e9
    if(integer::condition("JGE",flags)) goto L005a47e9;
  }
  L005a47a2: { // 0x5a47a2: be20000000 MOV ESI,0x20
    s.si = 0x00000020u;
  }
  L005a47a7: { // 0x5a47a7: 2bf7 SUB ESI,EDI
    s.si = integer::sub(s.si,s.di,32,flags);
  }
  L005a47a9: { // 0x5a47a9: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L005a47ab: { // 0x5a47ab: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L005a47af: { // 0x5a47af: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  L005a47b1: { // 0x5a47b1: 8d0c8504000000 LEA ECX,[EAX*0x4 + 0x4]
    s.cx = ((s.ax * 0x00000004u)+0x00000004u);
  }
  L005a47b8: { // 0x5a47b8: 2bd9 SUB EBX,ECX
    s.bx = integer::sub(s.bx,s.cx,32,flags);
  }
  L005a47ba: { // 0x5a47ba: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005a47bc: { // 0x5a47bc: 8bea MOV EBP,EDX
    s.bp = s.dx;
  }
  L005a47be: { // 0x5a47be: 83ea04 SUB EDX,0x4
    s.dx = integer::sub(s.dx,0x00000004u,32,flags);
  }
  L005a47c1: { // 0x5a47c1: 8b1b MOV EBX,dword ptr [EBX]
    s.bx = m.r32((s.bx));
  }
  L005a47c3: { // 0x5a47c3: d3eb SHR EBX,CL
    s.bx = integer::shift(s.bx,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  L005a47c5: { // 0x5a47c5: 8d0c8500000000 LEA ECX,[EAX*0x4 + 0x0]
    s.cx = ((s.ax * 0x00000004u)+0x00000000u);
  }
  L005a47cc: { // 0x5a47cc: 2be9 SUB EBP,ECX
    s.bp = integer::sub(s.bp,s.cx,32,flags);
  }
  L005a47ce: { // 0x5a47ce: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005a47d0: { // 0x5a47d0: 8b6d00 MOV EBP,dword ptr [EBP]
    s.bp = m.r32((s.bp));
  }
  L005a47d3: { // 0x5a47d3: d3e5 SHL EBP,CL
    s.bp = integer::shift(s.bp,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L005a47d5: { // 0x5a47d5: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L005a47d9: { // 0x5a47d9: 0bdd OR EBX,EBP
    s.bx = integer::logical((s.bx)|(s.bp),32,flags);
  }
  L005a47db: { // 0x5a47db: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L005a47dc: { // 0x5a47dc: 895a04 MOV dword ptr [EDX + 0x4],EBX
    m.w32((s.dx+0x00000004u), s.bx);
  }
  L005a47df: { // 0x5a47df: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L005a47e3: { // 0x5a47e3: 75ca JNZ 0x005a47af
    if(integer::condition("JNZ",flags)) goto L005a47af;
  }
  L005a47e5: { // 0x5a47e5: 8b5c2418 MOV EBX,dword ptr [ESP + 0x18]
    s.bx = m.r32((f.sp+0x00000018u));
  }
  L005a47e9: { // 0x5a47e9: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L005a47eb: { // 0x5a47eb: 7d17 JGE 0x005a4804
    if(integer::condition("JGE",flags)) goto L005a4804;
  }
  L005a47ed: { // 0x5a47ed: 8d0c8500000000 LEA ECX,[EAX*0x4 + 0x0]
    s.cx = ((s.ax * 0x00000004u)+0x00000000u);
  }
  L005a47f4: { // 0x5a47f4: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L005a47f6: { // 0x5a47f6: 2bf1 SUB ESI,ECX
    s.si = integer::sub(s.si,s.cx,32,flags);
  }
  L005a47f8: { // 0x5a47f8: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005a47fa: { // 0x5a47fa: 8b36 MOV ESI,dword ptr [ESI]
    s.si = m.r32((s.si));
  }
  L005a47fc: { // 0x5a47fc: d3e6 SHL ESI,CL
    s.si = integer::shift(s.si,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L005a47fe: { // 0x5a47fe: 83ea04 SUB EDX,0x4
    s.dx = integer::sub(s.dx,0x00000004u,32,flags);
  }
  L005a4801: { // 0x5a4801: 897204 MOV dword ptr [EDX + 0x4],ESI
    m.w32((s.dx+0x00000004u), s.si);
  }
  L005a4804: { // 0x5a4804: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L005a4806: { // 0x5a4806: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L005a4808: { // 0x5a4808: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L005a480a: { // 0x5a480a: 7c02 JL 0x005a480e
    if(integer::condition("JL",flags)) goto L005a480e;
  }
  L005a480c: { // 0x5a480c: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L005a480e: { // 0x5a480e: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L005a4810: { // 0x5a4810: 0f8d08ffffff JGE 0x005a471e
    if(integer::condition("JGE",flags)) goto L005a471e;
  }
  L005a4816: { // 0x5a4816: c70200000000 MOV dword ptr [EDX],0x0
    m.w32((s.dx), 0x00000000u);
  }
  L005a481c: { // 0x5a481c: 83ea04 SUB EDX,0x4
    s.dx = integer::sub(s.dx,0x00000004u,32,flags);
  }
  L005a481f: { // 0x5a481f: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L005a4820: { // 0x5a4820: ebe4 JMP 0x005a4806
    goto L005a4806;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 5916816u:f_001a4890(m,s,child,{});break;
case 7793616u:f_0036ebd0(m,s,child,{});break;
case 5923920u:f_001a6450(m,s,child,{});break;
case 5922320u:f_001a5e10(m,s,child,{});break;
case 5922800u:f_001a5ff0(m,s,child,{});break;
case 5922048u:f_001a5d00(m,s,child,{});break;
case 5916080u:f_001a45b0(m,s,child,{});break;
case 5920992u:f_001a58e0(m,s,child,{});break;
case 5916400u:f_001a46f0(m,s,child,{});break;
default:throw std::domain_error("recovery233 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00607100(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);
 std::array<std::uint8_t,16> table0{{236,118,0,144,64,236,118,0,108,236,118,0,144,236,118,0}};leaf::Memory tablemem0(table0.data(),7793712u,16u);m.add(tablemem0);
 std::array<std::uint8_t,32> table1{{15,237,118,0,252,236,118,0,244,236,118,0,236,236,118,0,228,236,118,0,220,236,118,0,212,236,118,0,204,236,118,0}};leaf::Memory tablemem1(table1.data(),7793836u,32u);m.add(tablemem1);
 std::array<std::uint8_t,16> table2{{40,237,118,0,48,237,118,0,60,237,118,0,80,237,118,0}};leaf::Memory tablemem2(table2.data(),7793944u,16u);m.add(tablemem2);
 std::array<std::uint8_t,16> table3{{238,118,0,144,200,237,118,0,232,237,118,0,16,238,118,0}};leaf::Memory tablemem3(table3.data(),7794104u,16u);m.add(tablemem3);
 std::array<std::uint8_t,32> table4{{100,238,118,0,108,238,118,0,116,238,118,0,124,238,118,0,132,238,118,0,140,238,118,0,148,238,118,0,167,238,118,0}};leaf::Memory tablemem4(table4.data(),7794244u,32u);m.add(tablemem4);
 std::array<std::uint8_t,16> table5{{192,238,118,0,200,238,118,0,216,238,118,0,236,238,118,0}};leaf::Memory tablemem5(table5.data(),7794352u,16u);m.add(tablemem5);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00607100: { // 0x607100: 81ec04020000 SUB ESP,0x204
    f.sp = integer::sub(f.sp,0x00000204u,32,flags);
  }
  L00607106: { // 0x607106: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00607107: { // 0x607107: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L00607109: { // 0x607109: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0060710b: { // 0x60710b: 8b8300020000 MOV EAX,dword ptr [EBX + 0x200]
    s.ax = m.r32((s.bx+0x00000200u));
  }
  L00607111: { // 0x607111: 894c2404 MOV dword ptr [ESP + 0x4],ECX
    m.w32((f.sp+0x00000004u), s.cx);
  }
  L00607115: { // 0x607115: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00607116: { // 0x607116: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00607117: { // 0x607117: 83e207 AND EDX,0x7
    s.dx = integer::logical((s.dx)&(0x00000007u),32,flags);
  }
  L0060711a: { // 0x60711a: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0060711c: { // 0x60711c: 8b942410020000 MOV EDX,dword ptr [ESP + 0x210]
    s.dx = m.r32((f.sp+0x00000210u));
  }
  L00607123: { // 0x607123: c1f803 SAR EAX,0x3
    s.ax = integer::shift(s.ax,0x00000003u,32,flags,integer::Shift::arithmetic_right);
  }
  L00607126: { // 0x607126: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L00607128: { // 0x607128: 0f8cf5000000 JL 0x00607223
    if(integer::condition("JL",flags)) goto L00607223;
  }
  L0060712e: { // 0x60712e: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0060712f: { // 0x60712f: 8bac2418020000 MOV EBP,dword ptr [ESP + 0x218]
    s.bp = m.r32((f.sp+0x00000218u));
  }
  L00607136: { // 0x607136: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00607137: { // 0x607137: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00607138: { // 0x607138: 6a40 PUSH 0x40
    f.push(m,0x00000040u);
  }
  L0060713a: { // 0x60713a: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0060713c: { // 0x60713c: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L00607140: { // 0x607140: e84bd7f9ff CALL 0x005a4890
    s.arithmetic_flags=flags; invoke(m,s,f,0x005a4890u,6320453u); flags=s.arithmetic_flags;
  }
  L00607145: { // 0x607145: 8b8300020000 MOV EAX,dword ptr [EBX + 0x200]
    s.ax = m.r32((s.bx+0x00000200u));
  }
  L0060714b: { // 0x60714b: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L0060714f: { // 0x60714f: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00607150: { // 0x607150: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00607151: { // 0x607151: 83e207 AND EDX,0x7
    s.dx = integer::logical((s.dx)&(0x00000007u),32,flags);
  }
  L00607154: { // 0x607154: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00607156: { // 0x607156: c1f803 SAR EAX,0x3
    s.ax = integer::shift(s.ax,0x00000003u,32,flags,integer::Shift::arithmetic_right);
  }
  L00607159: { // 0x607159: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0060715a: { // 0x60715a: 8b84241c020000 MOV EAX,dword ptr [ESP + 0x21c]
    s.ax = m.r32((f.sp+0x0000021cu));
  }
  L00607161: { // 0x607161: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00607162: { // 0x607162: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00607163: { // 0x607163: e8687a1600 CALL 0x0076ebd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076ebd0u,6320488u); flags=s.arithmetic_flags;
  }
  L00607168: { // 0x607168: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0060716b: { // 0x60716b: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0060716d: { // 0x60716d: 8d8c2414010000 LEA ECX,[ESP + 0x114]
    s.cx = (f.sp+0x00000114u);
  }
  L00607174: { // 0x607174: 6a40 PUSH 0x40
    f.push(m,0x00000040u);
  }
  L00607176: { // 0x607176: e815d7f9ff CALL 0x005a4890
    s.arithmetic_flags=flags; invoke(m,s,f,0x005a4890u,6320507u); flags=s.arithmetic_flags;
  }
  L0060717b: { // 0x60717b: 6a40 PUSH 0x40
    f.push(m,0x00000040u);
  }
  L0060717d: { // 0x60717d: 8d8300010000 LEA EAX,[EBX + 0x100]
    s.ax = (s.bx+0x00000100u);
  }
  L00607183: { // 0x607183: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00607184: { // 0x607184: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00607185: { // 0x607185: 8d542420 LEA EDX,[ESP + 0x20]
    s.dx = (f.sp+0x00000020u);
  }
  L00607189: { // 0x607189: 8d8c2420010000 LEA ECX,[ESP + 0x120]
    s.cx = (f.sp+0x00000120u);
  }
  L00607190: { // 0x607190: e8bbf2f9ff CALL 0x005a6450
    s.arithmetic_flags=flags; invoke(m,s,f,0x005a6450u,6320533u); flags=s.arithmetic_flags;
  }
  L00607195: { // 0x607195: a30094a200 MOV [0x00a29400],EAX
    m.w32((0x00a29400u), s.ax);
  }
  L0060719a: { // 0x60719a: 8b8300020000 MOV EAX,dword ptr [EBX + 0x200]
    s.ax = m.r32((s.bx+0x00000200u));
  }
  L006071a0: { // 0x6071a0: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L006071a1: { // 0x6071a1: b940000000 MOV ECX,0x40
    s.cx = 0x00000040u;
  }
  L006071a6: { // 0x6071a6: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006071a7: { // 0x6071a7: 83e207 AND EDX,0x7
    s.dx = integer::logical((s.dx)&(0x00000007u),32,flags);
  }
  L006071aa: { // 0x6071aa: 8db42414010000 LEA ESI,[ESP + 0x114]
    s.si = (f.sp+0x00000114u);
  }
  L006071b1: { // 0x6071b1: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L006071b3: { // 0x6071b3: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  L006071b7: { // 0x6071b7: c1f803 SAR EAX,0x3
    s.ax = integer::shift(s.ax,0x00000003u,32,flags,integer::Shift::arithmetic_right);
  }
  L006071ba: { // 0x6071ba: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L006071bb: { // 0x6071bb: 8d7c2414 LEA EDI,[ESP + 0x14]
    s.di = (f.sp+0x00000014u);
  }
  L006071bf: { // 0x6071bf: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006071c0: { // 0x6071c0: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006071c1: { // 0x6071c1: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L006071c3: { // 0x6071c3: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006071c4: { // 0x6071c4: e8077a1600 CALL 0x0076ebd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076ebd0u,6320585u); flags=s.arithmetic_flags;
  }
  L006071c9: { // 0x6071c9: 8b8300020000 MOV EAX,dword ptr [EBX + 0x200]
    s.ax = m.r32((s.bx+0x00000200u));
  }
  L006071cf: { // 0x6071cf: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L006071d2: { // 0x6071d2: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L006071d3: { // 0x6071d3: 8b8c241c020000 MOV ECX,dword ptr [ESP + 0x21c]
    s.cx = m.r32((f.sp+0x0000021cu));
  }
  L006071da: { // 0x6071da: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006071db: { // 0x6071db: 8bb42418020000 MOV ESI,dword ptr [ESP + 0x218]
    s.si = m.r32((f.sp+0x00000218u));
  }
  L006071e2: { // 0x6071e2: 83e207 AND EDX,0x7
    s.dx = integer::logical((s.dx)&(0x00000007u),32,flags);
  }
  L006071e5: { // 0x6071e5: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L006071e7: { // 0x6071e7: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L006071eb: { // 0x6071eb: c1f803 SAR EAX,0x3
    s.ax = integer::shift(s.ax,0x00000003u,32,flags,integer::Shift::arithmetic_right);
  }
  L006071ee: { // 0x6071ee: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L006071f0: { // 0x6071f0: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L006071f2: { // 0x6071f2: 8d540201 LEA EDX,[EDX + EAX*0x1 + 0x1]
    s.dx = (s.dx+(s.ax * 0x00000001u)+0x00000001u);
  }
  L006071f6: { // 0x6071f6: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L006071f8: { // 0x6071f8: 898c241c020000 MOV dword ptr [ESP + 0x21c],ECX
    m.w32((f.sp+0x0000021cu), s.cx);
  }
  L006071ff: { // 0x6071ff: 89b42418020000 MOV dword ptr [ESP + 0x218],ESI
    m.w32((f.sp+0x00000218u), s.si);
  }
  L00607206: { // 0x607206: 8d6c2801 LEA EBP,[EAX + EBP*0x1 + 0x1]
    s.bp = (s.ax+(s.bp * 0x00000001u)+0x00000001u);
  }
  L0060720a: { // 0x60720a: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L0060720e: { // 0x60720e: 0f8d24ffffff JGE 0x00607138
    if(integer::condition("JGE",flags)) goto L00607138;
  }
  L00607214: { // 0x607214: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00607215: { // 0x607215: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00607216: { // 0x607216: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00607217: { // 0x607217: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L00607219: { // 0x607219: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0060721a: { // 0x60721a: 81c404020000 ADD ESP,0x204
    f.sp = integer::add(f.sp,0x00000204u,32,flags);
  }
  L00607220: { // 0x607220: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00607223: { // 0x607223: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00607225: { // 0x607225: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00607226: { // 0x607226: 81c404020000 ADD ESP,0x204
    f.sp = integer::add(f.sp,0x00000204u,32,flags);
  }
  L0060722c: { // 0x60722c: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
