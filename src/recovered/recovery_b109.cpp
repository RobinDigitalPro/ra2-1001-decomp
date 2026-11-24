#include "recovered/recovery_b109_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b109 {
namespace {
void f_0036ebd0(Memory&,State&,Frame&,const Operations&);
void f_0036df28(Memory&,State&,Frame&,const Operations&);
void f_0036d67b(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);


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
    default:throw std::domain_error("recovery109 unsupported switch destination");}
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
    default:throw std::domain_error("recovery109 unsupported switch destination");}
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
    default:throw std::domain_error("recovery109 unsupported switch destination");}
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
    default:throw std::domain_error("recovery109 unsupported switch destination");}
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
    default:throw std::domain_error("recovery109 unsupported switch destination");}
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
    default:throw std::domain_error("recovery109 unsupported switch destination");}
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
    default:throw std::domain_error("recovery109 unsupported switch destination");}
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
    default:throw std::domain_error("recovery109 unsupported switch destination");}
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
    default:throw std::domain_error("recovery109 unsupported switch destination");}
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
    default:throw std::domain_error("recovery109 unsupported switch destination");}
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
    default:throw std::domain_error("recovery109 unsupported switch destination");}
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
    default:throw std::domain_error("recovery109 unsupported switch destination");}
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
    default:throw std::domain_error("recovery109 unsupported switch destination");}
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
    default:throw std::domain_error("recovery109 unsupported switch destination");}
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
    default:throw std::domain_error("recovery109 unsupported switch destination");}
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
    default:throw std::domain_error("recovery109 unsupported switch destination");}
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

void f_0036df28(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0076df28: { // 0x76df28: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0076df29: { // 0x76df29: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  L0076df2d: { // 0x76df2d: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0076df2f: { // 0x76df2f: 743d JZ 0x0076df6e
    if(integer::condition("JZ",flags)) goto L0076df6e;
  }
  L0076df31: { // 0x76df31: 6a09 PUSH 0x9
    f.push(m,0x00000009u);
  }
  L0076df33: { // 0x76df33: e87e360000 CALL 0x007715b6
    s.arithmetic_flags=flags; invoke(m,s,f,0x007715b6u,7790392u); flags=s.arithmetic_flags;
  }
  L0076df38: { // 0x76df38: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0076df39: { // 0x76df39: e83f540000 CALL 0x0077337d
    s.arithmetic_flags=flags; invoke(m,s,f,0x0077337du,7790398u); flags=s.arithmetic_flags;
  }
  L0076df3e: { // 0x76df3e: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0076df3f: { // 0x76df3f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0076df41: { // 0x76df41: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0076df42: { // 0x76df42: 7413 JZ 0x0076df57
    if(integer::condition("JZ",flags)) goto L0076df57;
  }
  L0076df44: { // 0x76df44: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0076df45: { // 0x76df45: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0076df46: { // 0x76df46: e85d540000 CALL 0x007733a8
    s.arithmetic_flags=flags; invoke(m,s,f,0x007733a8u,7790411u); flags=s.arithmetic_flags;
  }
  L0076df4b: { // 0x76df4b: 6a09 PUSH 0x9
    f.push(m,0x00000009u);
  }
  L0076df4d: { // 0x76df4d: e8c5360000 CALL 0x00771617
    s.arithmetic_flags=flags; invoke(m,s,f,0x00771617u,7790418u); flags=s.arithmetic_flags;
  }
  L0076df52: { // 0x76df52: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0076df55: { // 0x76df55: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076df56: { // 0x76df56: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076df57: { // 0x76df57: 6a09 PUSH 0x9
    f.push(m,0x00000009u);
  }
  L0076df59: { // 0x76df59: e8b9360000 CALL 0x00771617
    s.arithmetic_flags=flags; invoke(m,s,f,0x00771617u,7790430u); flags=s.arithmetic_flags;
  }
  L0076df5e: { // 0x76df5e: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0076df5f: { // 0x76df5f: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0076df60: { // 0x76df60: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0076df62: { // 0x76df62: ff351c0eb100 PUSH dword ptr [0x00b10e1c]
    f.push(m,m.r32((0x00b10e1cu)));
  }
  L0076df68: { // 0x76df68: ff1568527800 CALL dword ptr [0x00785268]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((0x00785268u)),7790446u); flags=s.arithmetic_flags;
  }
  L0076df6e: { // 0x76df6e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076df6f: { // 0x76df6f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}



void f_0036d67b(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0076d67b: { // 0x76d67b: ff742404 PUSH dword ptr [ESP + 0x4]
    f.push(m,m.r32((f.sp+0x00000004u)));
  }
  L0076d67f: { // 0x76d67f: e8a4080000 CALL 0x0076df28
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076df28u,7788164u); flags=s.arithmetic_flags;
  }
  L0076d684: { // 0x76d684: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0076d685: { // 0x76d685: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}



} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 7793616u:f_0036ebd0(m,s,child,{});break;
case 7790376u:f_0036df28(m,s,child,{});break;
case 7788155u:f_0036d67b(m,s,child,{});break;
default:throw std::domain_error("recovery109 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00409b60(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00409b60: { // 0x409b60: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00409b61: { // 0x409b61: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00409b63: { // 0x409b63: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00409b64: { // 0x409b64: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00409b66: { // 0x409b66: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L00409b68: { // 0x409b68: 8b8168010000 MOV EAX,dword ptr [ECX + 0x168]
    s.ax = m.r32((s.cx+0x00000168u));
  }
  L00409b6e: { // 0x409b6e: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L00409b70: { // 0x409b70: 0f8431010000 JZ 0x00409ca7
    if(integer::condition("JZ",flags)) goto L00409ca7;
  }
  L00409b76: { // 0x409b76: 8b4014 MOV EAX,dword ptr [EAX + 0x14]
    s.ax = m.r32((s.ax+0x00000014u));
  }
  L00409b79: { // 0x409b79: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L00409b7b: { // 0x409b7b: 7509 JNZ 0x00409b86
    if(integer::condition("JNZ",flags)) goto L00409b86;
  }
  L00409b7d: { // 0x409b7d: 8b81ac000000 MOV EAX,dword ptr [ECX + 0xac]
    s.ax = m.r32((s.cx+0x000000acu));
  }
  L00409b83: { // 0x409b83: 83c044 ADD EAX,0x44
    s.ax = integer::add(s.ax,0x00000044u,32,flags);
  }
  L00409b86: { // 0x409b86: 89be98000000 MOV dword ptr [ESI + 0x98],EDI
    m.w32((s.si+0x00000098u), s.di);
  }
  L00409b8c: { // 0x409b8c: 89be84000000 MOV dword ptr [ESI + 0x84],EDI
    m.w32((s.si+0x00000084u), s.di);
  }
  L00409b92: { // 0x409b92: 89be80000000 MOV dword ptr [ESI + 0x80],EDI
    m.w32((s.si+0x00000080u), s.di);
  }
  L00409b98: { // 0x409b98: c7467403000000 MOV dword ptr [ESI + 0x74],0x3
    m.w32((s.si+0x00000074u), 0x00000003u);
  }
  L00409b9f: { // 0x409b9f: 89be8c000000 MOV dword ptr [ESI + 0x8c],EDI
    m.w32((s.si+0x0000008cu), s.di);
  }
  L00409ba5: { // 0x409ba5: 89bea0000000 MOV dword ptr [ESI + 0xa0],EDI
    m.w32((s.si+0x000000a0u), s.di);
  }
  L00409bab: { // 0x409bab: 8b480c MOV ECX,dword ptr [EAX + 0xc]
    s.cx = m.r32((s.ax+0x0000000cu));
  }
  L00409bae: { // 0x409bae: 89bea8000000 MOV dword ptr [ESI + 0xa8],EDI
    m.w32((s.si+0x000000a8u), s.di);
  }
  L00409bb4: { // 0x409bb4: 898ea4000000 MOV dword ptr [ESI + 0xa4],ECX
    m.w32((s.si+0x000000a4u), s.cx);
  }
  L00409bba: { // 0x409bba: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L00409bbd: { // 0x409bbd: 2bcf SUB ECX,EDI
    s.cx = integer::sub(s.cx,s.di,32,flags);
  }
  L00409bbf: { // 0x409bbf: 7444 JZ 0x00409c05
    if(integer::condition("JZ",flags)) goto L00409c05;
  }
  L00409bc1: { // 0x409bc1: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00409bc2: { // 0x409bc2: 740c JZ 0x00409bd0
    if(integer::condition("JZ",flags)) goto L00409bd0;
  }
  L00409bc4: { // 0x409bc4: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00409bc5: { // 0x409bc5: 7545 JNZ 0x00409c0c
    if(integer::condition("JNZ",flags)) goto L00409c0c;
  }
  L00409bc7: { // 0x409bc7: c74670009d4000 MOV dword ptr [ESI + 0x70],0x409d00
    m.w32((s.si+0x00000070u), 0x00409d00u);
  }
  L00409bce: { // 0x409bce: eb3c JMP 0x00409c0c
    goto L00409c0c;
  }
  L00409bd0: { // 0x409bd0: c74670009d4000 MOV dword ptr [ESI + 0x70],0x409d00
    m.w32((s.si+0x00000070u), 0x00409d00u);
  }
  L00409bd7: { // 0x409bd7: c786b000000090a94000 MOV dword ptr [ESI + 0xb0],0x40a990
    m.w32((s.si+0x000000b0u), 0x0040a990u);
  }
  L00409be1: { // 0x409be1: 8b5018 MOV EDX,dword ptr [EAX + 0x18]
    s.dx = m.r32((s.ax+0x00000018u));
  }
  L00409be4: { // 0x409be4: 89968c000000 MOV dword ptr [ESI + 0x8c],EDX
    m.w32((s.si+0x0000008cu), s.dx);
  }
  L00409bea: { // 0x409bea: 8b4818 MOV ECX,dword ptr [EAX + 0x18]
    s.cx = m.r32((s.ax+0x00000018u));
  }
  L00409bed: { // 0x409bed: 898eac000000 MOV dword ptr [ESI + 0xac],ECX
    m.w32((s.si+0x000000acu), s.cx);
  }
  L00409bf3: { // 0x409bf3: 8b5018 MOV EDX,dword ptr [EAX + 0x18]
    s.dx = m.r32((s.ax+0x00000018u));
  }
  L00409bf6: { // 0x409bf6: 8d049580000000 LEA EAX,[EDX*0x4 + 0x80]
    s.ax = ((s.dx * 0x00000004u)+0x00000080u);
  }
  L00409bfd: { // 0x409bfd: 8986a0000000 MOV dword ptr [ESI + 0xa0],EAX
    m.w32((s.si+0x000000a0u), s.ax);
  }
  L00409c03: { // 0x409c03: eb07 JMP 0x00409c0c
    goto L00409c0c;
  }
  L00409c05: { // 0x409c05: c74670b09c4000 MOV dword ptr [ESI + 0x70],0x409cb0
    m.w32((s.si+0x00000070u), 0x00409cb0u);
  }
  L00409c0c: { // 0x409c0c: 8b8e88000000 MOV ECX,dword ptr [ESI + 0x88]
    s.cx = m.r32((s.si+0x00000088u));
  }
  L00409c12: { // 0x409c12: 8b868c000000 MOV EAX,dword ptr [ESI + 0x8c]
    s.ax = m.r32((s.si+0x0000008cu));
  }
  L00409c18: { // 0x409c18: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00409c1a: { // 0x409c1a: 7d3a JGE 0x00409c56
    if(integer::condition("JGE",flags)) goto L00409c56;
  }
  L00409c1c: { // 0x409c1c: 8b467c MOV EAX,dword ptr [ESI + 0x7c]
    s.ax = m.r32((s.si+0x0000007cu));
  }
  L00409c1f: { // 0x409c1f: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L00409c21: { // 0x409c21: 7409 JZ 0x00409c2c
    if(integer::condition("JZ",flags)) goto L00409c2c;
  }
  L00409c23: { // 0x409c23: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00409c24: { // 0x409c24: e8ff423600 CALL 0x0076df28
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076df28u,4234281u); flags=s.arithmetic_flags;
  }
  L00409c29: { // 0x409c29: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00409c2c: { // 0x409c2c: 8b968c000000 MOV EDX,dword ptr [ESI + 0x8c]
    s.dx = m.r32((s.si+0x0000008cu));
  }
  L00409c32: { // 0x409c32: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00409c33: { // 0x409c33: e838433600 CALL 0x0076df70
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076df70u,4234296u); flags=s.arithmetic_flags;
  }
  L00409c38: { // 0x409c38: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00409c3b: { // 0x409c3b: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L00409c3d: { // 0x409c3d: 89467c MOV dword ptr [ESI + 0x7c],EAX
    m.w32((s.si+0x0000007cu), s.ax);
  }
  L00409c40: { // 0x409c40: 7508 JNZ 0x00409c4a
    if(integer::condition("JNZ",flags)) goto L00409c4a;
  }
  L00409c42: { // 0x409c42: 89be88000000 MOV dword ptr [ESI + 0x88],EDI
    m.w32((s.si+0x00000088u), s.di);
  }
  L00409c48: { // 0x409c48: eb0c JMP 0x00409c56
    goto L00409c56;
  }
  L00409c4a: { // 0x409c4a: 8b868c000000 MOV EAX,dword ptr [ESI + 0x8c]
    s.ax = m.r32((s.si+0x0000008cu));
  }
  L00409c50: { // 0x409c50: 898688000000 MOV dword ptr [ESI + 0x88],EAX
    m.w32((s.si+0x00000088u), s.ax);
  }
  L00409c56: { // 0x409c56: 8b8e9c000000 MOV ECX,dword ptr [ESI + 0x9c]
    s.cx = m.r32((s.si+0x0000009cu));
  }
  L00409c5c: { // 0x409c5c: 8b86a0000000 MOV EAX,dword ptr [ESI + 0xa0]
    s.ax = m.r32((s.si+0x000000a0u));
  }
  L00409c62: { // 0x409c62: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00409c64: { // 0x409c64: 7d41 JGE 0x00409ca7
    if(integer::condition("JGE",flags)) goto L00409ca7;
  }
  L00409c66: { // 0x409c66: 8b8690000000 MOV EAX,dword ptr [ESI + 0x90]
    s.ax = m.r32((s.si+0x00000090u));
  }
  L00409c6c: { // 0x409c6c: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L00409c6e: { // 0x409c6e: 7409 JZ 0x00409c79
    if(integer::condition("JZ",flags)) goto L00409c79;
  }
  L00409c70: { // 0x409c70: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00409c71: { // 0x409c71: e8b2423600 CALL 0x0076df28
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076df28u,4234358u); flags=s.arithmetic_flags;
  }
  L00409c76: { // 0x409c76: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00409c79: { // 0x409c79: 8b96a0000000 MOV EDX,dword ptr [ESI + 0xa0]
    s.dx = m.r32((s.si+0x000000a0u));
  }
  L00409c7f: { // 0x409c7f: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00409c80: { // 0x409c80: e8eb423600 CALL 0x0076df70
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076df70u,4234373u); flags=s.arithmetic_flags;
  }
  L00409c85: { // 0x409c85: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00409c88: { // 0x409c88: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L00409c8a: { // 0x409c8a: 898690000000 MOV dword ptr [ESI + 0x90],EAX
    m.w32((s.si+0x00000090u), s.ax);
  }
  L00409c90: { // 0x409c90: 7509 JNZ 0x00409c9b
    if(integer::condition("JNZ",flags)) goto L00409c9b;
  }
  L00409c92: { // 0x409c92: 89be9c000000 MOV dword ptr [ESI + 0x9c],EDI
    m.w32((s.si+0x0000009cu), s.di);
  }
  L00409c98: { // 0x409c98: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00409c99: { // 0x409c99: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00409c9a: { // 0x409c9a: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00409c9b: { // 0x409c9b: 8b86a0000000 MOV EAX,dword ptr [ESI + 0xa0]
    s.ax = m.r32((s.si+0x000000a0u));
  }
  L00409ca1: { // 0x409ca1: 89869c000000 MOV dword ptr [ESI + 0x9c],EAX
    m.w32((s.si+0x0000009cu), s.ax);
  }
  L00409ca7: { // 0x409ca7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00409ca8: { // 0x409ca8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00409ca9: { // 0x409ca9: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00435700(Memory& original,const Inputs& i){
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
  L00435700: { // 0x435700: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00435701: { // 0x435701: 8b5c2408 MOV EBX,dword ptr [ESP + 0x8]
    s.bx = m.r32((f.sp+0x00000008u));
  }
  L00435705: { // 0x435705: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00435706: { // 0x435706: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00435707: { // 0x435707: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L00435709: { // 0x435709: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0043570b: { // 0x43570b: 0f84ca000000 JZ 0x004357db
    if(integer::condition("JZ",flags)) goto L004357db;
  }
  L00435711: { // 0x435711: 8b6c2414 MOV EBP,dword ptr [ESP + 0x14]
    s.bp = m.r32((f.sp+0x00000014u));
  }
  L00435715: { // 0x435715: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L00435717: { // 0x435717: 0f8ebe000000 JLE 0x004357db
    if(integer::condition("JLE",flags)) goto L004357db;
  }
  L0043571d: { // 0x43571d: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  L00435720: { // 0x435720: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00435722: { // 0x435722: 750d JNZ 0x00435731
    if(integer::condition("JNZ",flags)) goto L00435731;
  }
  L00435724: { // 0x435724: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00435725: { // 0x435725: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00435726: { // 0x435726: e815b02500 CALL 0x00690740
    s.arithmetic_flags=flags; invoke(m,s,f,0x00690740u,4413227u); flags=s.arithmetic_flags;
  }
  L0043572b: { // 0x43572b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0043572c: { // 0x43572c: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0043572d: { // 0x43572d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0043572e: { // 0x43572e: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00435731: { // 0x435731: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00435732: { // 0x435732: c744241800000000 MOV dword ptr [ESP + 0x18],0x0
    m.w32((f.sp+0x00000018u), 0x00000000u);
  }
  L0043573a: { // 0x43573a: eb04 JMP 0x00435740
    goto L00435740;
  }
  L0043573c: { // 0x43573c: 8b5c2414 MOV EBX,dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  L00435740: { // 0x435740: 8b4618 MOV EAX,dword ptr [ESI + 0x18]
    s.ax = m.r32((s.si+0x00000018u));
  }
  L00435743: { // 0x435743: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00435745: { // 0x435745: 7e34 JLE 0x0043577b
    if(integer::condition("JLE",flags)) goto L0043577b;
  }
  L00435747: { // 0x435747: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L00435749: { // 0x435749: 8bfd MOV EDI,EBP
    s.di = s.bp;
  }
  L0043574b: { // 0x43574b: 7c02 JL 0x0043574f
    if(integer::condition("JL",flags)) goto L0043574f;
  }
  L0043574d: { // 0x43574d: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0043574f: { // 0x43574f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00435751: { // 0x435751: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00435752: { // 0x435752: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00435754: { // 0x435754: 83c118 ADD ECX,0x18
    s.cx = integer::add(s.cx,0x00000018u,32,flags);
  }
  L00435757: { // 0x435757: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00435758: { // 0x435758: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00435759: { // 0x435759: e872943300 CALL 0x0076ebd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076ebd0u,4413278u); flags=s.arithmetic_flags;
  }
  L0043575e: { // 0x43575e: 8b4618 MOV EAX,dword ptr [ESI + 0x18]
    s.ax = m.r32((s.si+0x00000018u));
  }
  L00435761: { // 0x435761: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00435764: { // 0x435764: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  L00435766: { // 0x435766: 03df ADD EBX,EDI
    s.bx = integer::add(s.bx,s.di,32,flags);
  }
  L00435768: { // 0x435768: 894618 MOV dword ptr [ESI + 0x18],EAX
    m.w32((s.si+0x00000018u), s.ax);
  }
  L0043576b: { // 0x43576b: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0043576f: { // 0x43576f: 2bef SUB EBP,EDI
    s.bp = integer::sub(s.bp,s.di,32,flags);
  }
  L00435771: { // 0x435771: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L00435773: { // 0x435773: 895c2414 MOV dword ptr [ESP + 0x14],EBX
    m.w32((f.sp+0x00000014u), s.bx);
  }
  L00435777: { // 0x435777: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0043577b: { // 0x43577b: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0043577d: { // 0x43577d: 7451 JZ 0x004357d0
    if(integer::condition("JZ",flags)) goto L004357d0;
  }
  L0043577f: { // 0x43577f: 8d7e10 LEA EDI,[ESI + 0x10]
    s.di = (s.si+0x00000010u);
  }
  L00435782: { // 0x435782: 6a08 PUSH 0x8
    f.push(m,0x00000008u);
  }
  L00435784: { // 0x435784: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00435785: { // 0x435785: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00435787: { // 0x435787: e8b4af2500 CALL 0x00690740
    s.arithmetic_flags=flags; invoke(m,s,f,0x00690740u,4413324u); flags=s.arithmetic_flags;
  }
  L0043578c: { // 0x43578c: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0043578e: { // 0x43578e: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L00435790: { // 0x435790: 743e JZ 0x004357d0
    if(integer::condition("JZ",flags)) goto L004357d0;
  }
  L00435792: { // 0x435792: 83fb08 CMP EBX,0x8
    (void)integer::sub(s.bx,0x00000008u,32,flags);
  }
  L00435795: { // 0x435795: 751c JNZ 0x004357b3
    if(integer::condition("JNZ",flags)) goto L004357b3;
  }
  L00435797: { // 0x435797: 8b461c MOV EAX,dword ptr [ESI + 0x1c]
    s.ax = m.r32((s.si+0x0000001cu));
  }
  L0043579a: { // 0x43579a: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  L0043579d: { // 0x43579d: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0043579e: { // 0x43579e: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L004357a1: { // 0x4357a1: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004357a2: { // 0x4357a2: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004357a3: { // 0x4357a3: 7507 JNZ 0x004357ac
    if(integer::condition("JNZ",flags)) goto L004357ac;
  }
  L004357a5: { // 0x4357a5: e876fdffff CALL 0x00435520
    s.arithmetic_flags=flags; invoke(m,s,f,0x00435520u,4413354u); flags=s.arithmetic_flags;
  }
  L004357aa: { // 0x4357aa: eb19 JMP 0x004357c5
    goto L004357c5;
  }
  L004357ac: { // 0x4357ac: e83ffdffff CALL 0x004354f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004354f0u,4413361u); flags=s.arithmetic_flags;
  }
  L004357b1: { // 0x4357b1: eb12 JMP 0x004357c5
    goto L004357c5;
  }
  L004357b3: { // 0x4357b3: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L004357b5: { // 0x4357b5: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004357b6: { // 0x4357b6: 2bd3 SUB EDX,EBX
    s.dx = integer::sub(s.dx,s.bx,32,flags);
  }
  L004357b8: { // 0x4357b8: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004357b9: { // 0x4357b9: 83c218 ADD EDX,0x18
    s.dx = integer::add(s.dx,0x00000018u,32,flags);
  }
  L004357bc: { // 0x4357bc: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004357bd: { // 0x4357bd: e80e943300 CALL 0x0076ebd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076ebd0u,4413378u); flags=s.arithmetic_flags;
  }
  L004357c2: { // 0x4357c2: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L004357c5: { // 0x4357c5: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L004357c7: { // 0x4357c7: 895e18 MOV dword ptr [ESI + 0x18],EBX
    m.w32((s.si+0x00000018u), s.bx);
  }
  L004357ca: { // 0x4357ca: 0f8f6cffffff JG 0x0043573c
    if(integer::condition("JG",flags)) goto L0043573c;
  }
  L004357d0: { // 0x4357d0: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L004357d4: { // 0x4357d4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004357d5: { // 0x4357d5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004357d6: { // 0x4357d6: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004357d7: { // 0x4357d7: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004357d8: { // 0x4357d8: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004357db: { // 0x4357db: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004357dc: { // 0x4357dc: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004357dd: { // 0x4357dd: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004357df: { // 0x4357df: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004357e0: { // 0x4357e0: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_0050fe00(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0050fe00: { // 0x50fe00: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0050fe01: { // 0x50fe01: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0050fe02: { // 0x50fe02: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0050fe04: { // 0x50fe04: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  L0050fe07: { // 0x50fe07: c7069ceb7800 MOV dword ptr [ESI],0x78eb9c
    m.w32((s.si), 0x0078eb9cu);
  }
  L0050fe0d: { // 0x50fe0d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0050fe0e: { // 0x50fe0e: e815e12500 CALL 0x0076df28
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076df28u,5307923u); flags=s.arithmetic_flags;
  }
  L0050fe13: { // 0x50fe13: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    s.cx = m.r32((s.si+0x00000010u));
  }
  L0050fe16: { // 0x50fe16: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0050fe18: { // 0x50fe18: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0050fe19: { // 0x50fe19: 895e0c MOV dword ptr [ESI + 0xc],EBX
    m.w32((s.si+0x0000000cu), s.bx);
  }
  L0050fe1c: { // 0x50fe1c: e807e12500 CALL 0x0076df28
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076df28u,5307937u); flags=s.arithmetic_flags;
  }
  L0050fe21: { // 0x50fe21: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  L0050fe24: { // 0x50fe24: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0050fe27: { // 0x50fe27: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0050fe29: { // 0x50fe29: 895e10 MOV dword ptr [ESI + 0x10],EBX
    m.w32((s.si+0x00000010u), s.bx);
  }
  L0050fe2c: { // 0x50fe2c: 7425 JZ 0x0050fe53
    if(integer::condition("JZ",flags)) goto L0050fe53;
  }
  L0050fe2e: { // 0x50fe2e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0050fe2f: { // 0x50fe2f: 8b5614 MOV EDX,dword ptr [ESI + 0x14]
    s.dx = m.r32((s.si+0x00000014u));
  }
  L0050fe32: { // 0x50fe32: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L0050fe34: { // 0x50fe34: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0050fe35: { // 0x50fe35: e8eee02500 CALL 0x0076df28
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076df28u,5307962u); flags=s.arithmetic_flags;
  }
  L0050fe3a: { // 0x50fe3a: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx = m.r32((s.si+0x00000014u));
  }
  L0050fe3d: { // 0x50fe3d: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L0050fe3f: { // 0x50fe3f: 8b7904 MOV EDI,dword ptr [ECX + 0x4]
    s.di = m.r32((s.cx+0x00000004u));
  }
  L0050fe42: { // 0x50fe42: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0050fe43: { // 0x50fe43: e833d82500 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,5307976u); flags=s.arithmetic_flags;
  }
  L0050fe48: { // 0x50fe48: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0050fe4b: { // 0x50fe4b: 3bfb CMP EDI,EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  L0050fe4d: { // 0x50fe4d: 897e14 MOV dword ptr [ESI + 0x14],EDI
    m.w32((s.si+0x00000014u), s.di);
  }
  L0050fe50: { // 0x50fe50: 75dd JNZ 0x0050fe2f
    if(integer::condition("JNZ",flags)) goto L0050fe2f;
  }
  L0050fe52: { // 0x50fe52: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0050fe53: { // 0x50fe53: 8b4618 MOV EAX,dword ptr [ESI + 0x18]
    s.ax = m.r32((s.si+0x00000018u));
  }
  L0050fe56: { // 0x50fe56: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0050fe57: { // 0x50fe57: e8cce02500 CALL 0x0076df28
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076df28u,5307996u); flags=s.arithmetic_flags;
  }
  L0050fe5c: { // 0x50fe5c: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0050fe5f: { // 0x50fe5f: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L0050fe61: { // 0x50fe61: 895e18 MOV dword ptr [ESI + 0x18],EBX
    m.w32((s.si+0x00000018u), s.bx);
  }
  L0050fe64: { // 0x50fe64: c706fc5a7800 MOV dword ptr [ESI],0x785afc
    m.w32((s.si), 0x00785afcu);
  }
  L0050fe6a: { // 0x50fe6a: 7420 JZ 0x0050fe8c
    if(integer::condition("JZ",flags)) goto L0050fe8c;
  }
  L0050fe6c: { // 0x50fe6c: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  L0050fe6f: { // 0x50fe6f: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L0050fe71: { // 0x50fe71: 7419 JZ 0x0050fe8c
    if(integer::condition("JZ",flags)) goto L0050fe8c;
  }
  L0050fe73: { // 0x50fe73: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L0050fe76: { // 0x50fe76: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0050fe78: { // 0x50fe78: 7412 JZ 0x0050fe8c
    if(integer::condition("JZ",flags)) goto L0050fe8c;
  }
  L0050fe7a: { // 0x50fe7a: 894804 MOV dword ptr [EAX + 0x4],ECX
    m.w32((s.ax+0x00000004u), s.cx);
  }
  L0050fe7d: { // 0x50fe7d: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  L0050fe80: { // 0x50fe80: 8b5608 MOV EDX,dword ptr [ESI + 0x8]
    s.dx = m.r32((s.si+0x00000008u));
  }
  L0050fe83: { // 0x50fe83: 895108 MOV dword ptr [ECX + 0x8],EDX
    m.w32((s.cx+0x00000008u), s.dx);
  }
  L0050fe86: { // 0x50fe86: 895e08 MOV dword ptr [ESI + 0x8],EBX
    m.w32((s.si+0x00000008u), s.bx);
  }
  L0050fe89: { // 0x50fe89: 895e04 MOV dword ptr [ESI + 0x4],EBX
    m.w32((s.si+0x00000004u), s.bx);
  }
  L0050fe8c: { // 0x50fe8c: f644240c01 TEST byte ptr [ESP + 0xc],0x1
    (void)integer::logical((m.r8((f.sp+0x0000000cu)))&(0x00000001u),8,flags);
  }
  L0050fe91: { // 0x50fe91: 7409 JZ 0x0050fe9c
    if(integer::condition("JZ",flags)) goto L0050fe9c;
  }
  L0050fe93: { // 0x50fe93: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0050fe94: { // 0x50fe94: e8e2d72500 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,5308057u); flags=s.arithmetic_flags;
  }
  L0050fe99: { // 0x50fe99: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0050fe9c: { // 0x50fe9c: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0050fe9e: { // 0x50fe9e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0050fe9f: { // 0x50fe9f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0050fea0: { // 0x50fea0: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00565070(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00565070: { // 0x565070: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00565073: { // 0x565073: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00565074: { // 0x565074: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L00565078: { // 0x565078: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L0056507b: { // 0x56507b: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0056507c: { // 0x56507c: f73d4878a500 IDIV dword ptr [0x00a57848]
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(m.r32((0x00a57848u)),32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00565082: { // 0x565082: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L00565084: { // 0x565084: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00565085: { // 0x565085: 0f848c000000 JZ 0x00565117
    if(integer::condition("JZ",flags)) goto L00565117;
  }
  L0056508b: { // 0x56508b: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0056508d: { // 0x56508d: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0056508f: { // 0x56508f: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00565091: { // 0x565091: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00565092: { // 0x565092: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00565098: { // 0x565098: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0056509a: { // 0x56509a: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0056509d: { // 0x56509d: 6689442404 MOV word ptr [ESP + 0x4],AX
    m.w16((f.sp+0x00000004u), (s.ax & 0xffffu));
  }
  L005650a2: { // 0x5650a2: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L005650a5: { // 0x5650a5: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L005650a6: { // 0x5650a6: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L005650ac: { // 0x5650ac: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L005650ae: { // 0x5650ae: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L005650b1: { // 0x5650b1: d1f9 SAR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L005650b3: { // 0x5650b3: 6689442406 MOV word ptr [ESP + 0x6],AX
    m.w16((f.sp+0x00000006u), (s.ax & 0xffffu));
  }
  L005650b8: { // 0x5650b8: 8b442406 MOV EAX,dword ptr [ESP + 0x6]
    s.ax = m.r32((f.sp+0x00000006u));
  }
  L005650bc: { // 0x5650bc: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L005650c0: { // 0x5650c0: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L005650c1: { // 0x5650c1: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L005650c3: { // 0x5650c3: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L005650c5: { // 0x5650c5: 6689442412 MOV word ptr [ESP + 0x12],AX
    m.w16((f.sp+0x00000012u), (s.ax & 0xffffu));
  }
  L005650ca: { // 0x5650ca: 6689542410 MOV word ptr [ESP + 0x10],DX
    m.w16((f.sp+0x00000010u), (s.dx & 0xffffu));
  }
  L005650cf: { // 0x5650cf: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L005650d2: { // 0x5650d2: 0fbfca MOVSX ECX,DX
    s.cx = std::uint32_t(integer::sign_extend((s.dx & 0xffffu),16));
  }
  L005650d5: { // 0x5650d5: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L005650d8: { // 0x5650d8: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L005650da: { // 0x5650da: 7814 JS 0x005650f0
    if(integer::condition("JS",flags)) goto L005650f0;
  }
  L005650dc: { // 0x5650dc: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L005650e1: { // 0x5650e1: 7d0d JGE 0x005650f0
    if(integer::condition("JGE",flags)) goto L005650f0;
  }
  L005650e3: { // 0x5650e3: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L005650e9: { // 0x5650e9: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L005650ec: { // 0x5650ec: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005650ee: { // 0x5650ee: 750e JNZ 0x005650fe
    if(integer::condition("JNZ",flags)) goto L005650fe;
  }
  L005650f0: { // 0x5650f0: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L005650f4: { // 0x5650f4: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L005650f9: { // 0x5650f9: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L005650fe: { // 0x5650fe: 8b883c010000 MOV ECX,dword ptr [EAX + 0x13c]
    s.cx = m.r32((s.ax+0x0000013cu));
  }
  L00565104: { // 0x565104: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00565106: { // 0x565106: 0f8e90000000 JLE 0x0056519c
    if(integer::condition("JLE",flags)) goto L0056519c;
  }
  L0056510c: { // 0x56510c: 6a03 PUSH 0x3
    f.push(m,0x00000003u);
  }
  L0056510e: { // 0x56510e: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00565110: { // 0x565110: e8ab15f1ff CALL 0x004766c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004766c0u,5656853u); flags=s.arithmetic_flags;
  }
  L00565115: { // 0x565115: eb72 JMP 0x00565189
    goto L00565189;
  }
  L00565117: { // 0x565117: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00565119: { // 0x565119: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0056511b: { // 0x56511b: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0056511d: { // 0x56511d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0056511e: { // 0x56511e: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00565124: { // 0x565124: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00565126: { // 0x565126: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00565129: { // 0x565129: 6689442404 MOV word ptr [ESP + 0x4],AX
    m.w16((f.sp+0x00000004u), (s.ax & 0xffffu));
  }
  L0056512e: { // 0x56512e: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L00565131: { // 0x565131: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00565132: { // 0x565132: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00565138: { // 0x565138: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0056513a: { // 0x56513a: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0056513d: { // 0x56513d: 6689442406 MOV word ptr [ESP + 0x6],AX
    m.w16((f.sp+0x00000006u), (s.ax & 0xffffu));
  }
  L00565142: { // 0x565142: 8b442406 MOV EAX,dword ptr [ESP + 0x6]
    s.ax = m.r32((f.sp+0x00000006u));
  }
  L00565146: { // 0x565146: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L0056514a: { // 0x56514a: d1f9 SAR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0056514c: { // 0x56514c: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L0056514e: { // 0x56514e: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L00565150: { // 0x565150: 6689442412 MOV word ptr [ESP + 0x12],AX
    m.w16((f.sp+0x00000012u), (s.ax & 0xffffu));
  }
  L00565155: { // 0x565155: 6689542410 MOV word ptr [ESP + 0x10],DX
    m.w16((f.sp+0x00000010u), (s.dx & 0xffffu));
  }
  L0056515a: { // 0x56515a: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0056515d: { // 0x56515d: 0fbfca MOVSX ECX,DX
    s.cx = std::uint32_t(integer::sign_extend((s.dx & 0xffffu),16));
  }
  L00565160: { // 0x565160: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L00565163: { // 0x565163: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00565165: { // 0x565165: 7814 JS 0x0056517b
    if(integer::condition("JS",flags)) goto L0056517b;
  }
  L00565167: { // 0x565167: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L0056516c: { // 0x56516c: 7d0d JGE 0x0056517b
    if(integer::condition("JGE",flags)) goto L0056517b;
  }
  L0056516e: { // 0x56516e: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L00565174: { // 0x565174: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L00565177: { // 0x565177: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00565179: { // 0x565179: 750e JNZ 0x00565189
    if(integer::condition("JNZ",flags)) goto L00565189;
  }
  L0056517b: { // 0x56517b: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0056517f: { // 0x56517f: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L00565184: { // 0x565184: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L00565189: { // 0x565189: 8b883c010000 MOV ECX,dword ptr [EAX + 0x13c]
    s.cx = m.r32((s.ax+0x0000013cu));
  }
  L0056518f: { // 0x56518f: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00565191: { // 0x565191: 7e09 JLE 0x0056519c
    if(integer::condition("JLE",flags)) goto L0056519c;
  }
  L00565193: { // 0x565193: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00565195: { // 0x565195: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00565196: { // 0x565196: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00565199: { // 0x565199: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0056519c: { // 0x56519c: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0056519e: { // 0x56519e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0056519f: { // 0x56519f: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L005651a2: { // 0x5651a2: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_005b39d0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005b39d0: { // 0x5b39d0: a03896a500 MOV AL,[0x00a59638]
    s.ax = with_al(s.ax, m.r8((0x00a59638u)));
  }
  L005b39d5: { // 0x5b39d5: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005b39d6: { // 0x5b39d6: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L005b39d8: { // 0x5b39d8: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L005b39da: { // 0x5b39da: 754b JNZ 0x005b3a27
    if(integer::condition("JNZ",flags)) goto L005b3a27;
  }
  L005b39dc: { // 0x5b39dc: 8ad0 MOV DL,AL
    s.dx = with_al(s.dx, (s.ax & 0xffu));
  }
  L005b39de: { // 0x5b39de: 68a0375b00 PUSH 0x5b37a0
    f.push(m,0x005b37a0u);
  }
  L005b39e3: { // 0x5b39e3: 80ca01 OR DL,0x1
    s.dx = with_al(s.dx, integer::logical(((s.dx & 0xffu))|(0x00000001u),8,flags));
  }
  L005b39e6: { // 0x5b39e6: 891d2496a500 MOV dword ptr [0x00a59624],EBX
    m.w32((0x00a59624u), s.bx);
  }
  L005b39ec: { // 0x5b39ec: 88153896a500 MOV byte ptr [0x00a59638],DL
    m.w8((0x00a59638u), (s.dx & 0xffu));
  }
  L005b39f2: { // 0x5b39f2: 891d2896a500 MOV dword ptr [0x00a59628],EBX
    m.w32((0x00a59628u), s.bx);
  }
  L005b39f8: { // 0x5b39f8: c6052c96a50001 MOV byte ptr [0x00a5962c],0x1
    m.w8((0x00a5962cu), 0x00000001u);
  }
  L005b39ff: { // 0x5b39ff: 881d2d96a500 MOV byte ptr [0x00a5962d],BL
    m.w8((0x00a5962du), (s.bx & 0xffu));
  }
  L005b3a05: { // 0x5b3a05: c7052096a50048217900 MOV dword ptr [0x00a59620],0x792148
    m.w32((0x00a59620u), 0x00792148u);
  }
  L005b3a0f: { // 0x5b3a0f: c7053496a5000a000000 MOV dword ptr [0x00a59634],0xa
    m.w32((0x00a59634u), 0x0000000au);
  }
  L005b3a19: { // 0x5b3a19: 891d3096a500 MOV dword ptr [0x00a59630],EBX
    m.w32((0x00a59630u), s.bx);
  }
  L005b3a1f: { // 0x5b3a1f: e8a6a81b00 CALL 0x0076e2ca
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076e2cau,5978660u); flags=s.arithmetic_flags;
  }
  L005b3a24: { // 0x5b3a24: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L005b3a27: { // 0x5b3a27: 391d3096a500 CMP dword ptr [0x00a59630],EBX
    (void)integer::sub(m.r32((0x00a59630u)),s.bx,32,flags);
  }
  L005b3a2d: { // 0x5b3a2d: 7504 JNZ 0x005b3a33
    if(integer::condition("JNZ",flags)) goto L005b3a33;
  }
  L005b3a2f: { // 0x5b3a2f: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005b3a31: { // 0x5b3a31: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005b3a32: { // 0x5b3a32: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005b3a33: { // 0x5b3a33: a03896a500 MOV AL,[0x00a59638]
    s.ax = with_al(s.ax, m.r8((0x00a59638u)));
  }
  L005b3a38: { // 0x5b3a38: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L005b3a3a: { // 0x5b3a3a: 754b JNZ 0x005b3a87
    if(integer::condition("JNZ",flags)) goto L005b3a87;
  }
  L005b3a3c: { // 0x5b3a3c: 8ad0 MOV DL,AL
    s.dx = with_al(s.dx, (s.ax & 0xffu));
  }
  L005b3a3e: { // 0x5b3a3e: 68a0375b00 PUSH 0x5b37a0
    f.push(m,0x005b37a0u);
  }
  L005b3a43: { // 0x5b3a43: 80ca01 OR DL,0x1
    s.dx = with_al(s.dx, integer::logical(((s.dx & 0xffu))|(0x00000001u),8,flags));
  }
  L005b3a46: { // 0x5b3a46: 891d2496a500 MOV dword ptr [0x00a59624],EBX
    m.w32((0x00a59624u), s.bx);
  }
  L005b3a4c: { // 0x5b3a4c: 88153896a500 MOV byte ptr [0x00a59638],DL
    m.w8((0x00a59638u), (s.dx & 0xffu));
  }
  L005b3a52: { // 0x5b3a52: 891d2896a500 MOV dword ptr [0x00a59628],EBX
    m.w32((0x00a59628u), s.bx);
  }
  L005b3a58: { // 0x5b3a58: c6052c96a50001 MOV byte ptr [0x00a5962c],0x1
    m.w8((0x00a5962cu), 0x00000001u);
  }
  L005b3a5f: { // 0x5b3a5f: 881d2d96a500 MOV byte ptr [0x00a5962d],BL
    m.w8((0x00a5962du), (s.bx & 0xffu));
  }
  L005b3a65: { // 0x5b3a65: c7052096a50048217900 MOV dword ptr [0x00a59620],0x792148
    m.w32((0x00a59620u), 0x00792148u);
  }
  L005b3a6f: { // 0x5b3a6f: c7053496a5000a000000 MOV dword ptr [0x00a59634],0xa
    m.w32((0x00a59634u), 0x0000000au);
  }
  L005b3a79: { // 0x5b3a79: 891d3096a500 MOV dword ptr [0x00a59630],EBX
    m.w32((0x00a59630u), s.bx);
  }
  L005b3a7f: { // 0x5b3a7f: e846a81b00 CALL 0x0076e2ca
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076e2cau,5978756u); flags=s.arithmetic_flags;
  }
  L005b3a84: { // 0x5b3a84: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L005b3a87: { // 0x5b3a87: a12496a500 MOV EAX,[0x00a59624]
    s.ax = m.r32((0x00a59624u));
  }
  L005b3a8c: { // 0x5b3a8c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005b3a8d: { // 0x5b3a8d: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L005b3a8f: { // 0x5b3a8f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_005d0580(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005d0580: { // 0x5d0580: a108aba500 MOV EAX,[0x00a5ab08]
    s.ax = m.r32((0x00a5ab08u));
  }
  L005d0585: { // 0x5d0585: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005d0586: { // 0x5d0586: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005d0587: { // 0x5d0587: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L005d0589: { // 0x5d0589: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L005d058b: { // 0x5d058b: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L005d058d: { // 0x5d058d: 0f8ed2000000 JLE 0x005d0665
    if(integer::condition("JLE",flags)) goto L005d0665;
  }
  L005d0593: { // 0x5d0593: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005d0594: { // 0x5d0594: a1fcaaa500 MOV EAX,[0x00a5aafc]
    s.ax = m.r32((0x00a5aafcu));
  }
  L005d0599: { // 0x5d0599: 8b34b8 MOV ESI,dword ptr [EAX + EDI*0x4]
    s.si = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  L005d059c: { // 0x5d059c: 8b8e14020000 MOV ECX,dword ptr [ESI + 0x214]
    s.cx = m.r32((s.si+0x00000214u));
  }
  L005d05a2: { // 0x5d05a2: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005d05a3: { // 0x5d05a3: e8d3d01900 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,6096296u); flags=s.arithmetic_flags;
  }
  L005d05a8: { // 0x5d05a8: 899e14020000 MOV dword ptr [ESI + 0x214],EBX
    m.w32((s.si+0x00000214u), s.bx);
  }
  L005d05ae: { // 0x5d05ae: 899e18020000 MOV dword ptr [ESI + 0x218],EBX
    m.w32((s.si+0x00000218u), s.bx);
  }
  L005d05b4: { // 0x5d05b4: 899e1c020000 MOV dword ptr [ESI + 0x21c],EBX
    m.w32((s.si+0x0000021cu), s.bx);
  }
  L005d05ba: { // 0x5d05ba: 889e20020000 MOV byte ptr [ESI + 0x220],BL
    m.w8((s.si+0x00000220u), (s.bx & 0xffu));
  }
  L005d05c0: { // 0x5d05c0: 899e24020000 MOV dword ptr [ESI + 0x224],EBX
    m.w32((s.si+0x00000224u), s.bx);
  }
  L005d05c6: { // 0x5d05c6: 8b9628020000 MOV EDX,dword ptr [ESI + 0x228]
    s.dx = m.r32((s.si+0x00000228u));
  }
  L005d05cc: { // 0x5d05cc: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005d05cd: { // 0x5d05cd: e8a9d01900 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,6096338u); flags=s.arithmetic_flags;
  }
  L005d05d2: { // 0x5d05d2: 899e28020000 MOV dword ptr [ESI + 0x228],EBX
    m.w32((s.si+0x00000228u), s.bx);
  }
  L005d05d8: { // 0x5d05d8: 899e2c020000 MOV dword ptr [ESI + 0x22c],EBX
    m.w32((s.si+0x0000022cu), s.bx);
  }
  L005d05de: { // 0x5d05de: 899e30020000 MOV dword ptr [ESI + 0x230],EBX
    m.w32((s.si+0x00000230u), s.bx);
  }
  L005d05e4: { // 0x5d05e4: 889e34020000 MOV byte ptr [ESI + 0x234],BL
    m.w8((s.si+0x00000234u), (s.bx & 0xffu));
  }
  L005d05ea: { // 0x5d05ea: 899e38020000 MOV dword ptr [ESI + 0x238],EBX
    m.w32((s.si+0x00000238u), s.bx);
  }
  L005d05f0: { // 0x5d05f0: 8b863c020000 MOV EAX,dword ptr [ESI + 0x23c]
    s.ax = m.r32((s.si+0x0000023cu));
  }
  L005d05f6: { // 0x5d05f6: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005d05f7: { // 0x5d05f7: e87fd01900 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,6096380u); flags=s.arithmetic_flags;
  }
  L005d05fc: { // 0x5d05fc: 899e3c020000 MOV dword ptr [ESI + 0x23c],EBX
    m.w32((s.si+0x0000023cu), s.bx);
  }
  L005d0602: { // 0x5d0602: 899e40020000 MOV dword ptr [ESI + 0x240],EBX
    m.w32((s.si+0x00000240u), s.bx);
  }
  L005d0608: { // 0x5d0608: 899e44020000 MOV dword ptr [ESI + 0x244],EBX
    m.w32((s.si+0x00000244u), s.bx);
  }
  L005d060e: { // 0x5d060e: 889e48020000 MOV byte ptr [ESI + 0x248],BL
    m.w8((s.si+0x00000248u), (s.bx & 0xffu));
  }
  L005d0614: { // 0x5d0614: 899e4c020000 MOV dword ptr [ESI + 0x24c],EBX
    m.w32((s.si+0x0000024cu), s.bx);
  }
  L005d061a: { // 0x5d061a: 8b8e50020000 MOV ECX,dword ptr [ESI + 0x250]
    s.cx = m.r32((s.si+0x00000250u));
  }
  L005d0620: { // 0x5d0620: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005d0621: { // 0x5d0621: e855d01900 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,6096422u); flags=s.arithmetic_flags;
  }
  L005d0626: { // 0x5d0626: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L005d0629: { // 0x5d0629: 899e50020000 MOV dword ptr [ESI + 0x250],EBX
    m.w32((s.si+0x00000250u), s.bx);
  }
  L005d062f: { // 0x5d062f: 899e54020000 MOV dword ptr [ESI + 0x254],EBX
    m.w32((s.si+0x00000254u), s.bx);
  }
  L005d0635: { // 0x5d0635: 899e58020000 MOV dword ptr [ESI + 0x258],EBX
    m.w32((s.si+0x00000258u), s.bx);
  }
  L005d063b: { // 0x5d063b: 889e5c020000 MOV byte ptr [ESI + 0x25c],BL
    m.w8((s.si+0x0000025cu), (s.bx & 0xffu));
  }
  L005d0641: { // 0x5d0641: 899e60020000 MOV dword ptr [ESI + 0x260],EBX
    m.w32((s.si+0x00000260u), s.bx);
  }
  L005d0647: { // 0x5d0647: a108aba500 MOV EAX,[0x00a5ab08]
    s.ax = m.r32((0x00a5ab08u));
  }
  L005d064c: { // 0x5d064c: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L005d064d: { // 0x5d064d: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L005d064f: { // 0x5d064f: 0f8c3fffffff JL 0x005d0594
    if(integer::condition("JL",flags)) goto L005d0594;
  }
  L005d0655: { // 0x5d0655: 8b15e41d8200 MOV EDX,dword ptr [0x00821de4]
    s.dx = m.r32((0x00821de4u));
  }
  L005d065b: { // 0x5d065b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005d065c: { // 0x5d065c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005d065d: { // 0x5d065d: 8915e81d8200 MOV dword ptr [0x00821de8],EDX
    m.w32((0x00821de8u), s.dx);
  }
  L005d0663: { // 0x5d0663: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005d0664: { // 0x5d0664: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005d0665: { // 0x5d0665: a1e41d8200 MOV EAX,[0x00821de4]
    s.ax = m.r32((0x00821de4u));
  }
  L005d066a: { // 0x5d066a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005d066b: { // 0x5d066b: a3e81d8200 MOV [0x00821de8],EAX
    m.w32((0x00821de8u), s.ax);
  }
  L005d0670: { // 0x5d0670: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005d0671: { // 0x5d0671: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_006dfab0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006dfab0: { // 0x6dfab0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006dfab1: { // 0x6dfab1: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006dfab2: { // 0x6dfab2: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006dfab4: { // 0x6dfab4: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L006dfab6: { // 0x6dfab6: 8b8610010000 MOV EAX,dword ptr [ESI + 0x110]
    s.ax = m.r32((s.si+0x00000110u));
  }
  L006dfabc: { // 0x6dfabc: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L006dfabe: { // 0x6dfabe: 743c JZ 0x006dfafc
    if(integer::condition("JZ",flags)) goto L006dfafc;
  }
  L006dfac0: { // 0x6dfac0: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L006dfac2: { // 0x6dfac2: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L006dfac4: { // 0x6dfac4: 3bd3 CMP EDX,EBX
    (void)integer::sub(s.dx,s.bx,32,flags);
  }
  L006dfac6: { // 0x6dfac6: 7c0e JL 0x006dfad6
    if(integer::condition("JL",flags)) goto L006dfad6;
  }
  L006dfac8: { // 0x6dfac8: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L006dfacb: { // 0x6dfacb: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L006dfacc: { // 0x6dfacc: 895c8afc MOV dword ptr [EDX + ECX*0x4 + -0x4],EBX
    m.w32((s.dx+(s.cx * 0x00000004u)-0x00000004u), s.bx);
  }
  L006dfad0: { // 0x6dfad0: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L006dfad2: { // 0x6dfad2: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L006dfad4: { // 0x6dfad4: 7ef2 JLE 0x006dfac8
    if(integer::condition("JLE",flags)) goto L006dfac8;
  }
  L006dfad6: { // 0x6dfad6: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006dfad7: { // 0x6dfad7: 8918 MOV dword ptr [EAX],EBX
    m.w32((s.ax), s.bx);
  }
  L006dfad9: { // 0x6dfad9: 8bbe10010000 MOV EDI,dword ptr [ESI + 0x110]
    s.di = m.r32((s.si+0x00000110u));
  }
  L006dfadf: { // 0x6dfadf: 3bfb CMP EDI,EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  L006dfae1: { // 0x6dfae1: 7412 JZ 0x006dfaf5
    if(integer::condition("JZ",flags)) goto L006dfaf5;
  }
  L006dfae3: { // 0x6dfae3: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  L006dfae6: { // 0x6dfae6: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006dfae7: { // 0x6dfae7: e88fdb0800 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,7207660u); flags=s.arithmetic_flags;
  }
  L006dfaec: { // 0x6dfaec: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006dfaed: { // 0x6dfaed: e889db0800 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,7207666u); flags=s.arithmetic_flags;
  }
  L006dfaf2: { // 0x6dfaf2: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L006dfaf5: { // 0x6dfaf5: 899e10010000 MOV dword ptr [ESI + 0x110],EBX
    m.w32((s.si+0x00000110u), s.bx);
  }
  L006dfafb: { // 0x6dfafb: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006dfafc: { // 0x6dfafc: 8b8618010000 MOV EAX,dword ptr [ESI + 0x118]
    s.ax = m.r32((s.si+0x00000118u));
  }
  L006dfb02: { // 0x6dfb02: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L006dfb04: { // 0x6dfb04: 740f JZ 0x006dfb15
    if(integer::condition("JZ",flags)) goto L006dfb15;
  }
  L006dfb06: { // 0x6dfb06: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006dfb07: { // 0x6dfb07: e86fdb0800 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,7207692u); flags=s.arithmetic_flags;
  }
  L006dfb0c: { // 0x6dfb0c: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L006dfb0f: { // 0x6dfb0f: 899e18010000 MOV dword ptr [ESI + 0x118],EBX
    m.w32((s.si+0x00000118u), s.bx);
  }
  L006dfb15: { // 0x6dfb15: 8b8614010000 MOV EAX,dword ptr [ESI + 0x114]
    s.ax = m.r32((s.si+0x00000114u));
  }
  L006dfb1b: { // 0x6dfb1b: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L006dfb1d: { // 0x6dfb1d: 740f JZ 0x006dfb2e
    if(integer::condition("JZ",flags)) goto L006dfb2e;
  }
  L006dfb1f: { // 0x6dfb1f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006dfb20: { // 0x6dfb20: e856db0800 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,7207717u); flags=s.arithmetic_flags;
  }
  L006dfb25: { // 0x6dfb25: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L006dfb28: { // 0x6dfb28: 899e14010000 MOV dword ptr [ESI + 0x114],EBX
    m.w32((s.si+0x00000114u), s.bx);
  }
  L006dfb2e: { // 0x6dfb2e: 899e0c010000 MOV dword ptr [ESI + 0x10c],EBX
    m.w32((s.si+0x0000010cu), s.bx);
  }
  L006dfb34: { // 0x6dfb34: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006dfb35: { // 0x6dfb35: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006dfb36: { // 0x6dfb36: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_0077eba5(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0077eba5: { // 0x77eba5: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0077eba6: { // 0x77eba6: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L0077eba8: { // 0x77eba8: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0077eba9: { // 0x77eba9: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0077ebaa: { // 0x77ebaa: 8b7508 MOV ESI,dword ptr [EBP + 0x8]
    s.si = m.r32((s.bp+0x00000008u));
  }
  L0077ebad: { // 0x77ebad: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0077ebae: { // 0x77ebae: f6460c40 TEST byte ptr [ESI + 0xc],0x40
    (void)integer::logical((m.r8((s.si+0x0000000cu)))&(0x00000040u),8,flags);
  }
  L0077ebb2: { // 0x77ebb2: 0f85c1000000 JNZ 0x0077ec79
    if(integer::condition("JNZ",flags)) goto L0077ec79;
  }
  L0077ebb8: { // 0x77ebb8: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L0077ebbb: { // 0x77ebbb: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L0077ebbe: { // 0x77ebbe: 7417 JZ 0x0077ebd7
    if(integer::condition("JZ",flags)) goto L0077ebd7;
  }
  L0077ebc0: { // 0x77ebc0: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0077ebc2: { // 0x77ebc2: c1f905 SAR ECX,0x5
    s.cx = integer::shift(s.cx,0x00000005u,32,flags,integer::Shift::arithmetic_right);
  }
  L0077ebc5: { // 0x77ebc5: 83e01f AND EAX,0x1f
    s.ax = integer::logical((s.ax)&(0x0000001fu),32,flags);
  }
  L0077ebc8: { // 0x77ebc8: 8b0c8d000db100 MOV ECX,dword ptr [ECX*0x4 + 0xb10d00]
    s.cx = m.r32(((s.cx * 0x00000004u)+0x00b10d00u));
  }
  L0077ebcf: { // 0x77ebcf: 8d04c0 LEA EAX,[EAX + EAX*0x8]
    s.ax = (s.ax+(s.ax * 0x00000008u));
  }
  L0077ebd2: { // 0x77ebd2: 8d0481 LEA EAX,[ECX + EAX*0x4]
    s.ax = (s.cx+(s.ax * 0x00000004u));
  }
  L0077ebd5: { // 0x77ebd5: eb05 JMP 0x0077ebdc
    goto L0077ebdc;
  }
  L0077ebd7: { // 0x77ebd7: b8f8788100 MOV EAX,0x8178f8
    s.ax = 0x008178f8u;
  }
  L0077ebdc: { // 0x77ebdc: f6400480 TEST byte ptr [EAX + 0x4],0x80
    (void)integer::logical((m.r8((s.ax+0x00000004u)))&(0x00000080u),8,flags);
  }
  L0077ebe0: { // 0x77ebe0: 0f8493000000 JZ 0x0077ec79
    if(integer::condition("JZ",flags)) goto L0077ec79;
  }
  L0077ebe6: { // 0x77ebe6: ff4e04 DEC dword ptr [ESI + 0x4]
    m.w32((s.si+0x00000004u), integer::decrement(m.r32((s.si+0x00000004u)),32,flags));
  }
  L0077ebe9: { // 0x77ebe9: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0077ebeb: { // 0x77ebeb: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0077ebec: { // 0x77ebec: 780a JS 0x0077ebf8
    if(integer::condition("JS",flags)) goto L0077ebf8;
  }
  L0077ebee: { // 0x77ebee: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0077ebf0: { // 0x77ebf0: 0fb601 MOVZX EAX,byte ptr [ECX]
    s.ax = (m.r8((s.cx))&integer::mask(8));
  }
  L0077ebf3: { // 0x77ebf3: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0077ebf4: { // 0x77ebf4: 890e MOV dword ptr [ESI],ECX
    m.w32((s.si), s.cx);
  }
  L0077ebf6: { // 0x77ebf6: eb07 JMP 0x0077ebff
    goto L0077ebff;
  }
  L0077ebf8: { // 0x77ebf8: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0077ebf9: { // 0x77ebf9: e8c556ffff CALL 0x007742c3
    s.arithmetic_flags=flags; invoke(m,s,f,0x007742c3u,7859198u); flags=s.arithmetic_flags;
  }
  L0077ebfe: { // 0x77ebfe: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0077ebff: { // 0x77ebff: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L0077ec02: { // 0x77ec02: 7509 JNZ 0x0077ec0d
    if(integer::condition("JNZ",flags)) goto L0077ec0d;
  }
  L0077ec04: { // 0x77ec04: 660dffff OR AX,0xffff
    s.ax = with_ax(s.ax, integer::logical(((s.ax & 0xffffu))|(0x0000ffffu),16,flags));
  }
  L0077ec08: { // 0x77ec08: e985000000 JMP 0x0077ec92
    goto L0077ec92;
  }
  L0077ec0d: { // 0x77ec0d: 8b0d60758100 MOV ECX,dword ptr [0x00817560]
    s.cx = m.r32((0x00817560u));
  }
  L0077ec13: { // 0x77ec13: 8845fc MOV byte ptr [EBP + -0x4],AL
    m.w8((s.bp-0x00000004u), (s.ax & 0xffu));
  }
  L0077ec16: { // 0x77ec16: 0fb6c0 MOVZX EAX,AL
    s.ax = ((s.ax & 0xffu)&integer::mask(8));
  }
  L0077ec19: { // 0x77ec19: f644410180 TEST byte ptr [ECX + EAX*0x2 + 0x1],0x80
    (void)integer::logical((m.r8((s.cx+(s.ax * 0x00000002u)+0x00000001u)))&(0x00000080u),8,flags);
  }
  L0077ec1e: { // 0x77ec1e: 7430 JZ 0x0077ec50
    if(integer::condition("JZ",flags)) goto L0077ec50;
  }
  L0077ec20: { // 0x77ec20: ff4e04 DEC dword ptr [ESI + 0x4]
    m.w32((s.si+0x00000004u), integer::decrement(m.r32((s.si+0x00000004u)),32,flags));
  }
  L0077ec23: { // 0x77ec23: 780a JS 0x0077ec2f
    if(integer::condition("JS",flags)) goto L0077ec2f;
  }
  L0077ec25: { // 0x77ec25: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0077ec27: { // 0x77ec27: 0fb601 MOVZX EAX,byte ptr [ECX]
    s.ax = (m.r8((s.cx))&integer::mask(8));
  }
  L0077ec2a: { // 0x77ec2a: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0077ec2b: { // 0x77ec2b: 890e MOV dword ptr [ESI],ECX
    m.w32((s.si), s.cx);
  }
  L0077ec2d: { // 0x77ec2d: eb07 JMP 0x0077ec36
    goto L0077ec36;
  }
  L0077ec2f: { // 0x77ec2f: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0077ec30: { // 0x77ec30: e88e56ffff CALL 0x007742c3
    s.arithmetic_flags=flags; invoke(m,s,f,0x007742c3u,7859253u); flags=s.arithmetic_flags;
  }
  L0077ec35: { // 0x77ec35: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0077ec36: { // 0x77ec36: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L0077ec39: { // 0x77ec39: 750f JNZ 0x0077ec4a
    if(integer::condition("JNZ",flags)) goto L0077ec4a;
  }
  L0077ec3b: { // 0x77ec3b: 0fbe45fc MOVSX EAX,byte ptr [EBP + -0x4]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.bp-0x00000004u)),8));
  }
  L0077ec3f: { // 0x77ec3f: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0077ec40: { // 0x77ec40: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0077ec41: { // 0x77ec41: e809f1ffff CALL 0x0077dd4f
    s.arithmetic_flags=flags; invoke(m,s,f,0x0077dd4fu,7859270u); flags=s.arithmetic_flags;
  }
  L0077ec46: { // 0x77ec46: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0077ec47: { // 0x77ec47: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0077ec48: { // 0x77ec48: ebba JMP 0x0077ec04
    goto L0077ec04;
  }
  L0077ec4a: { // 0x77ec4a: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  L0077ec4c: { // 0x77ec4c: 8845fd MOV byte ptr [EBP + -0x3],AL
    m.w8((s.bp-0x00000003u), (s.ax & 0xffu));
  }
  L0077ec4f: { // 0x77ec4f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0077ec50: { // 0x77ec50: 8d45fc LEA EAX,[EBP + -0x4]
    s.ax = (s.bp-0x00000004u);
  }
  L0077ec53: { // 0x77ec53: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0077ec54: { // 0x77ec54: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0077ec55: { // 0x77ec55: 8d450a LEA EAX,[EBP + 0xa]
    s.ax = (s.bp+0x0000000au);
  }
  L0077ec58: { // 0x77ec58: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0077ec59: { // 0x77ec59: e8a7efffff CALL 0x0077dc05
    s.arithmetic_flags=flags; invoke(m,s,f,0x0077dc05u,7859294u); flags=s.arithmetic_flags;
  }
  L0077ec5e: { // 0x77ec5e: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0077ec61: { // 0x77ec61: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L0077ec64: { // 0x77ec64: 750d JNZ 0x0077ec73
    if(integer::condition("JNZ",flags)) goto L0077ec73;
  }
  L0077ec66: { // 0x77ec66: e8e365ffff CALL 0x0077524e
    s.arithmetic_flags=flags; invoke(m,s,f,0x0077524eu,7859307u); flags=s.arithmetic_flags;
  }
  L0077ec6b: { // 0x77ec6b: c7002a000000 MOV dword ptr [EAX],0x2a
    m.w32((s.ax), 0x0000002au);
  }
  L0077ec71: { // 0x77ec71: eb91 JMP 0x0077ec04
    goto L0077ec04;
  }
  L0077ec73: { // 0x77ec73: 668b450a MOV AX,word ptr [EBP + 0xa]
    s.ax = with_ax(s.ax, m.r16((s.bp+0x0000000au)));
  }
  L0077ec77: { // 0x77ec77: eb19 JMP 0x0077ec92
    goto L0077ec92;
  }
  L0077ec79: { // 0x77ec79: 834604fe ADD dword ptr [ESI + 0x4],-0x2
    m.w32((s.si+0x00000004u), integer::add(m.r32((s.si+0x00000004u)),0xfffffffeu,32,flags));
  }
  L0077ec7d: { // 0x77ec7d: 780c JS 0x0077ec8b
    if(integer::condition("JS",flags)) goto L0077ec8b;
  }
  L0077ec7f: { // 0x77ec7f: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0077ec81: { // 0x77ec81: 668b01 MOV AX,word ptr [ECX]
    s.ax = with_ax(s.ax, m.r16((s.cx)));
  }
  L0077ec84: { // 0x77ec84: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L0077ec87: { // 0x77ec87: 890e MOV dword ptr [ESI],ECX
    m.w32((s.si), s.cx);
  }
  L0077ec89: { // 0x77ec89: eb07 JMP 0x0077ec92
    goto L0077ec92;
  }
  L0077ec8b: { // 0x77ec8b: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0077ec8c: { // 0x77ec8c: e852210000 CALL 0x00780de3
    s.arithmetic_flags=flags; invoke(m,s,f,0x00780de3u,7859345u); flags=s.arithmetic_flags;
  }
  L0077ec91: { // 0x77ec91: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0077ec92: { // 0x77ec92: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0077ec93: { // 0x77ec93: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0077ec94: { // 0x77ec94: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L0077ec95: { // 0x77ec95: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_0077eccb(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0077eccb: { // 0x77eccb: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0077eccc: { // 0x77eccc: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L0077ecce: { // 0x77ecce: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0077eccf: { // 0x77eccf: 8b5d08 MOV EBX,dword ptr [EBP + 0x8]
    s.bx = m.r32((s.bp+0x00000008u));
  }
  L0077ecd2: { // 0x77ecd2: 6681fbffff CMP BX,0xffff
    (void)integer::sub((s.bx & 0xffffu),0x0000ffffu,16,flags);
  }
  L0077ecd7: { // 0x77ecd7: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0077ecd8: { // 0x77ecd8: 7470 JZ 0x0077ed4a
    if(integer::condition("JZ",flags)) goto L0077ed4a;
  }
  L0077ecda: { // 0x77ecda: 8b750c MOV ESI,dword ptr [EBP + 0xc]
    s.si = m.r32((s.bp+0x0000000cu));
  }
  L0077ecdd: { // 0x77ecdd: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  L0077ece0: { // 0x77ece0: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L0077ece2: { // 0x77ece2: 7508 JNZ 0x0077ecec
    if(integer::condition("JNZ",flags)) goto L0077ecec;
  }
  L0077ece4: { // 0x77ece4: a880 TEST AL,0x80
    (void)integer::logical(((s.ax & 0xffu))&(0x00000080u),8,flags);
  }
  L0077ece6: { // 0x77ece6: 7462 JZ 0x0077ed4a
    if(integer::condition("JZ",flags)) goto L0077ed4a;
  }
  L0077ece8: { // 0x77ece8: a802 TEST AL,0x2
    (void)integer::logical(((s.ax & 0xffu))&(0x00000002u),8,flags);
  }
  L0077ecea: { // 0x77ecea: 755e JNZ 0x0077ed4a
    if(integer::condition("JNZ",flags)) goto L0077ed4a;
  }
  L0077ecec: { // 0x77ecec: 837e0800 CMP dword ptr [ESI + 0x8],0x0
    (void)integer::sub(m.r32((s.si+0x00000008u)),0x00000000u,32,flags);
  }
  L0077ecf0: { // 0x77ecf0: 7507 JNZ 0x0077ecf9
    if(integer::condition("JNZ",flags)) goto L0077ecf9;
  }
  L0077ecf2: { // 0x77ecf2: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0077ecf3: { // 0x77ecf3: e858caffff CALL 0x0077b750
    s.arithmetic_flags=flags; invoke(m,s,f,0x0077b750u,7859448u); flags=s.arithmetic_flags;
  }
  L0077ecf8: { // 0x77ecf8: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0077ecf9: { // 0x77ecf9: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  L0077ecfc: { // 0x77ecfc: a840 TEST AL,0x40
    (void)integer::logical(((s.ax & 0xffu))&(0x00000040u),8,flags);
  }
  L0077ecfe: { // 0x77ecfe: 0f8588000000 JNZ 0x0077ed8c
    if(integer::condition("JNZ",flags)) goto L0077ed8c;
  }
  L0077ed04: { // 0x77ed04: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    s.cx = m.r32((s.si+0x00000010u));
  }
  L0077ed07: { // 0x77ed07: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  L0077ed0a: { // 0x77ed0a: 7417 JZ 0x0077ed23
    if(integer::condition("JZ",flags)) goto L0077ed23;
  }
  L0077ed0c: { // 0x77ed0c: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L0077ed0e: { // 0x77ed0e: c1fa05 SAR EDX,0x5
    s.dx = integer::shift(s.dx,0x00000005u,32,flags,integer::Shift::arithmetic_right);
  }
  L0077ed11: { // 0x77ed11: 83e11f AND ECX,0x1f
    s.cx = integer::logical((s.cx)&(0x0000001fu),32,flags);
  }
  L0077ed14: { // 0x77ed14: 8b1495000db100 MOV EDX,dword ptr [EDX*0x4 + 0xb10d00]
    s.dx = m.r32(((s.dx * 0x00000004u)+0x00b10d00u));
  }
  L0077ed1b: { // 0x77ed1b: 8d0cc9 LEA ECX,[ECX + ECX*0x8]
    s.cx = (s.cx+(s.cx * 0x00000008u));
  }
  L0077ed1e: { // 0x77ed1e: 8d0c8a LEA ECX,[EDX + ECX*0x4]
    s.cx = (s.dx+(s.cx * 0x00000004u));
  }
  L0077ed21: { // 0x77ed21: eb05 JMP 0x0077ed28
    goto L0077ed28;
  }
  L0077ed23: { // 0x77ed23: b9f8788100 MOV ECX,0x8178f8
    s.cx = 0x008178f8u;
  }
  L0077ed28: { // 0x77ed28: f6410480 TEST byte ptr [ECX + 0x4],0x80
    (void)integer::logical((m.r8((s.cx+0x00000004u)))&(0x00000080u),8,flags);
  }
  L0077ed2c: { // 0x77ed2c: 745e JZ 0x0077ed8c
    if(integer::condition("JZ",flags)) goto L0077ed8c;
  }
  L0077ed2e: { // 0x77ed2e: 8d4508 LEA EAX,[EBP + 0x8]
    s.ax = (s.bp+0x00000008u);
  }
  L0077ed31: { // 0x77ed31: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0077ed32: { // 0x77ed32: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0077ed33: { // 0x77ed33: e885caffff CALL 0x0077b7bd
    s.arithmetic_flags=flags; invoke(m,s,f,0x0077b7bdu,7859512u); flags=s.arithmetic_flags;
  }
  L0077ed38: { // 0x77ed38: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0077ed39: { // 0x77ed39: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L0077ed3c: { // 0x77ed3c: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0077ed3d: { // 0x77ed3d: 7513 JNZ 0x0077ed52
    if(integer::condition("JNZ",flags)) goto L0077ed52;
  }
  L0077ed3f: { // 0x77ed3f: e80a65ffff CALL 0x0077524e
    s.arithmetic_flags=flags; invoke(m,s,f,0x0077524eu,7859524u); flags=s.arithmetic_flags;
  }
  L0077ed44: { // 0x77ed44: c7002a000000 MOV dword ptr [EAX],0x2a
    m.w32((s.ax), 0x0000002au);
  }
  L0077ed4a: { // 0x77ed4a: 660dffff OR AX,0xffff
    s.ax = with_ax(s.ax, integer::logical(((s.ax & 0xffffu))|(0x0000ffffu),16,flags));
  }
  L0077ed4e: { // 0x77ed4e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0077ed4f: { // 0x77ed4f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0077ed50: { // 0x77ed50: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0077ed51: { // 0x77ed51: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0077ed52: { // 0x77ed52: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0077ed54: { // 0x77ed54: 3b4e08 CMP ECX,dword ptr [ESI + 0x8]
    (void)integer::sub(s.cx,m.r32((s.si+0x00000008u)),32,flags);
  }
  L0077ed57: { // 0x77ed57: 750a JNZ 0x0077ed63
    if(integer::condition("JNZ",flags)) goto L0077ed63;
  }
  L0077ed59: { // 0x77ed59: 837e0400 CMP dword ptr [ESI + 0x4],0x0
    (void)integer::sub(m.r32((s.si+0x00000004u)),0x00000000u,32,flags);
  }
  L0077ed5d: { // 0x77ed5d: 75eb JNZ 0x0077ed4a
    if(integer::condition("JNZ",flags)) goto L0077ed4a;
  }
  L0077ed5f: { // 0x77ed5f: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0077ed61: { // 0x77ed61: 890e MOV dword ptr [ESI],ECX
    m.w32((s.si), s.cx);
  }
  L0077ed63: { // 0x77ed63: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0077ed66: { // 0x77ed66: 7409 JZ 0x0077ed71
    if(integer::condition("JZ",flags)) goto L0077ed71;
  }
  L0077ed68: { // 0x77ed68: ff0e DEC dword ptr [ESI]
    m.w32((s.si), integer::decrement(m.r32((s.si)),32,flags));
  }
  L0077ed6a: { // 0x77ed6a: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0077ed6c: { // 0x77ed6c: 8a5509 MOV DL,byte ptr [EBP + 0x9]
    s.dx = with_al(s.dx, m.r8((s.bp+0x00000009u)));
  }
  L0077ed6f: { // 0x77ed6f: 8811 MOV byte ptr [ECX],DL
    m.w8((s.cx), (s.dx & 0xffu));
  }
  L0077ed71: { // 0x77ed71: ff0e DEC dword ptr [ESI]
    m.w32((s.si), integer::decrement(m.r32((s.si)),32,flags));
  }
  L0077ed73: { // 0x77ed73: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0077ed75: { // 0x77ed75: 8a5508 MOV DL,byte ptr [EBP + 0x8]
    s.dx = with_al(s.dx, m.r8((s.bp+0x00000008u)));
  }
  L0077ed78: { // 0x77ed78: 8811 MOV byte ptr [ECX],DL
    m.w8((s.cx), (s.dx & 0xffu));
  }
  L0077ed7a: { // 0x77ed7a: 014604 ADD dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), integer::add(m.r32((s.si+0x00000004u)),s.ax,32,flags));
  }
  L0077ed7d: { // 0x77ed7d: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  L0077ed80: { // 0x77ed80: 24ef AND AL,0xef
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000efu),8,flags));
  }
  L0077ed82: { // 0x77ed82: 0c01 OR AL,0x1
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000001u),8,flags));
  }
  L0077ed84: { // 0x77ed84: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  L0077ed87: { // 0x77ed87: 668bc3 MOV AX,BX
    s.ax = with_ax(s.ax, (s.bx & 0xffffu));
  }
  L0077ed8a: { // 0x77ed8a: ebc2 JMP 0x0077ed4e
    goto L0077ed4e;
  }
  L0077ed8c: { // 0x77ed8c: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0077ed8e: { // 0x77ed8e: 3b4e08 CMP ECX,dword ptr [ESI + 0x8]
    (void)integer::sub(s.cx,m.r32((s.si+0x00000008u)),32,flags);
  }
  L0077ed91: { // 0x77ed91: 750b JNZ 0x0077ed9e
    if(integer::condition("JNZ",flags)) goto L0077ed9e;
  }
  L0077ed93: { // 0x77ed93: 837e0400 CMP dword ptr [ESI + 0x4],0x0
    (void)integer::sub(m.r32((s.si+0x00000004u)),0x00000000u,32,flags);
  }
  L0077ed97: { // 0x77ed97: 75b1 JNZ 0x0077ed4a
    if(integer::condition("JNZ",flags)) goto L0077ed4a;
  }
  L0077ed99: { // 0x77ed99: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L0077ed9c: { // 0x77ed9c: 890e MOV dword ptr [ESI],ECX
    m.w32((s.si), s.cx);
  }
  L0077ed9e: { // 0x77ed9e: 83460402 ADD dword ptr [ESI + 0x4],0x2
    m.w32((s.si+0x00000004u), integer::add(m.r32((s.si+0x00000004u)),0x00000002u,32,flags));
  }
  L0077eda2: { // 0x77eda2: 24ef AND AL,0xef
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000efu),8,flags));
  }
  L0077eda4: { // 0x77eda4: 0c01 OR AL,0x1
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000001u),8,flags));
  }
  L0077eda6: { // 0x77eda6: 8306fe ADD dword ptr [ESI],-0x2
    m.w32((s.si), integer::add(m.r32((s.si)),0xfffffffeu,32,flags));
  }
  L0077eda9: { // 0x77eda9: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  L0077edac: { // 0x77edac: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0077edae: { // 0x77edae: 668918 MOV word ptr [EAX],BX
    m.w16((s.ax), (s.bx & 0xffffu));
  }
  L0077edb1: { // 0x77edb1: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0077edb3: { // 0x77edb3: 668b00 MOV AX,word ptr [EAX]
    s.ax = with_ax(s.ax, m.r16((s.ax)));
  }
  L0077edb6: { // 0x77edb6: eb96 JMP 0x0077ed4e
    goto L0077ed4e;
  }

}
}
