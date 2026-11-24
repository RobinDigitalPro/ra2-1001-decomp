#include "recovery_b1368.hpp"
#include <stdexcept>
namespace ra2::recovered::b1368 {
namespace {
using U=std::uint32_t;
void need(bool valid,const char* reason){if(!valid)throw std::domain_error(reason);}
U al(U eax,U byte){return (eax&0xffffff00u)|(byte&255u);}
U ax(U eax,U word){return (eax&0xffff0000u)|(word&65535u);}
// All ring adapters below follow the real pinned original bodies. Indices are
// bounded0..255. In this domain AND800000FF/JNS implements modulo256 exactly.
// The unimplemented5B29F0 poll/refill call is excluded by a genuine full ring.
U peek_00530530(Memory& m,U r){
    const U tail=m.r32(r+0x318),head=m.r32(r+0x314);
    need(tail<256 && head<256 && ((tail+1)&255)==head,"B1368 530530 full ring excludes poll");
    need(head!=tail,"B1368 530530 nonempty ring");
    return ax(head,m.r16(r+0x114+2*head));
}
U full_00530be0(Memory& m,U r){
    const U next=(m.r32(r+0x318)+1)&255;
    return al(next,next==m.r32(r+0x314)?1u:0u); // SETZ AL preserves high24.
}
U peek_00530b80(Memory& m,U r){
    const U head=m.r32(r+0x314),tail=m.r32(r+0x318);
    return ax(head,head==tail?0u:m.r16(r+0x114+2*head));
}
U consume_00530580(Memory& m,U r){
    const U tail=m.r32(r+0x318),head=m.r32(r+0x314);
    need(tail<256 && head<256 && ((tail+1)&255)==head,"B1368 530580 initial full-ring poll exclusion");
    need(head!=tail && m.r16(r+0x114+2*head)!=0,"B1368 530580 first nonempty word");
    need((full_00530be0(m,r)&255)!=0,"B1368 530BE0 excludes second poll");
    need(m.r32(r+0x314)!=m.r32(r+0x318),"B1368 530580 still nonempty before peek");
    const U peek=peek_00530b80(m,r);
    need((peek&65535)==0x1b,"B1368 actual single-word Escape event");
    // Original5305F9 XOR EAX,EAX, then MOV AX from the head word.
    U eax=0;const U current=m.r32(r+0x314);
    if(current!=m.r32(r+0x318)){
        eax=m.r16(r+0x114+2*current);
        m.w32(r+0x314,(current+1)&255);
    }
    need((eax&255)==0x1b,"B1368 excludes compound event payload consumption");
    return eax;
}
}
U fun_0061e390(Memory& m,const Inputs& i){
    const U kind=m.r32(i.cx),owner=m.r32(0xa1e0e4),owner_index=m.r32(owner+0x30);
    need(kind>=1 && kind<=45 && m.r32(0xa2588c)!=1 && owner_index<8,
         "B1368 ordinary record classification with a bounded owner index");
    const U byte=m.r8(i.cx+2);
    U eax=(byte&0x80)?(byte|0xffffff00u):byte; // Original MOVSX EAX,byte2.
    eax-=owner_index;
    const bool carry=eax!=0;eax=0-eax;       // NEG sets CF iff operand nonzero.
    eax=carry?0xffffffffu:0;                // SBB EAX,EAX.
    eax=al(eax,eax&0xfau);                  // Original AND AL,FA, not AND EAX.
    return eax+6;
}
U fun_004c7710(Memory& m,const Inputs& i){
    need(i.arg[1]==28 && m.r32(i.cx+0x494)!=0,"B1368 real selector28 and present linked object");
    // (28-17)=11; original byte table[11]=4; original DWORD table[4]=4C776E.
    return 10;
}
U fun_00502f10(Memory& m,const Inputs& i){
    const U mode=m.r32(i.cx+0x5ac);
    need(mode==0x0b || mode==0x0c || mode==0x0d || mode==0x0e || mode==0x0f ||
         mode==0x22 || mode==0x23 || mode==0x24 || mode==0x14 || mode==0x15,
         "B1368 one of ten explicitly classified modes");
    return 6; // Every listed comparison reaches original502F51 MOV EAX,6.
}
U fun_0061b300(Memory& m,const Inputs&){
    need((m.r8(0xa27928)&2)!=0 && m.r8(0xa285a8)==1,"B1368 active buffered-input flag");
    U r=m.r32(0x81a7a8);
    const U preview=peek_00530530(m,r);
    need((preview&65535)==0x1b,"B1368 nonempty Escape preview");
    r=m.r32(0x81a7a8); // Original root reloads the same global after preview.
    const U eax=consume_00530580(m,r);
    need((eax&65535)==0x1b,"B1368 original CMP AX,1B branch");
    m.w8(0xa285a8,0);
    return eax;
}
}
