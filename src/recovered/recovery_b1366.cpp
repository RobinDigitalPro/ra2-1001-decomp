#include "recovery_b1366.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1366 {
namespace {
using U=std::uint32_t;
void need(bool x,const char* message){if(!x)throw std::domain_error(message);}
U original_443af0_pending(Memory& m,U self,U requested){
    const U current=m.r32(self+0x42cu);
    m.w32(self+0x430u,requested);
    need(current!=0xffffffffu&&requested!=0u&&m.r32(0xa283c4u)==0u,"B1366 real pending-request early branch");
    // Actual443B1A ->443E03, before the later443DF0 unproduced S-8 read.
    return 0xffffffffu;
}
U original_7827fb(Memory& m,const Inputs& i){
    i.arg[1]+=4u;return m.r32(i.arg[1]-4u);
}
constexpr std::array<std::uint8_t,89> parser_bytes{{0x06u,0x00u,0x00u,0x06u,0x00u,0x01u,0x00u,0x00u,0x10u,0x00u,0x03u,0x06u,0x00u,0x06u,0x02u,0x10u,0x04u,0x45u,0x45u,0x45u,0x05u,0x05u,0x05u,0x05u,0x05u,0x35u,0x30u,0x00u,0x50u,0x00u,0x00u,0x00u,0x00u,0x20u,0x28u,0x38u,0x50u,0x58u,0x07u,0x08u,0x00u,0x37u,0x30u,0x30u,0x57u,0x50u,0x07u,0x00u,0x00u,0x20u,0x20u,0x08u,0x00u,0x00u,0x00u,0x00u,0x08u,0x60u,0x68u,0x60u,0x60u,0x60u,0x60u,0x00u,0x00u,0x70u,0x70u,0x78u,0x78u,0x78u,0x78u,0x08u,0x07u,0x08u,0x00u,0x00u,0x07u,0x00u,0x08u,0x08u,0x08u,0x00u,0x00u,0x08u,0x00u,0x08u,0x00u,0x07u,0x08u}};
U original_719920(Memory& m,U container,U index){
    if(floating_b61::s32(index)<0||floating_b61::s32(index)>=floating_b61::s32(m.r32(container+0x38u)))return 0u;
    return m.r32(container+0x2cu)+12u*index;
}
U original_4ec700_positive(Memory& m,U holder,U xy){
    const U first=m.r32(holder+0x158u),second=m.r32(holder+0x15cu);
    need(first!=0u&&second!=0u&&m.r32(first+0x38u)==0u&&m.r32(second+0x38u)==1u,"B1366 actual preinitialized empty first and single-record second container");
    const U record=original_719920(m,second,0u);
    const U x=m.r32(record),y=m.r32(record+4u);
    const U qx=floating_b61::sar(x+((x>>31u)?255u:0u),8u),qy=floating_b61::sar(y+((y>>31u)?255u:0u),8u);
    need((qx&65535u)==m.r16(xy)&&(qy&65535u)==m.r16(xy+2u),"B1366 real positive coordinate record lookup");
    return record;
}
U original_522930_cached(Memory& m,U key){
    const U cached=m.r32(0xa39eecu);need(cached==1u,"B1366 genuine cached keyboard provider");
    return (cached&0xffff0000u)|m.r16(0xa39c10u+2u*(key&255u));
}
U original_530af0_nonmouse(Memory& m,U key){
    key&=255u;need(key>=3u&&key<=6u,"B1366 accepted nonmouse keys");
    // Actual NEG AX / SBB EAX,EAX / NEG EAX: any nonzero lowWORD is true.
    return (original_522930_cached(m,key)&65535u)!=0u?1u:0u;
}
U original_6eb4d0_inactive(Memory& m){
    need(m.r8(0xaa8db8u)==0u&&m.r32(0x81a7a8u)!=0u,"B1366 real cached-key branch, no global shortcut");
    const U first=original_530af0_nonmouse(m,m.r32(0xa287ecu));
    const U pair1=first!=0u?1u:original_530af0_nonmouse(m,m.r32(0xa287f0u));
    const U third=original_530af0_nonmouse(m,m.r32(0xa287f4u));
    const U pair2=third!=0u?1u:original_530af0_nonmouse(m,m.r32(0xa287f8u));
    need(pair1==1u&&pair2==1u,"B1366 two genuine positive cached key pairs");
    const U count=m.r32(0xa288b0u),table=m.r32(0xa288a4u);
    need(count==3u&&table!=0u,"B1366 populated actual selected-record registry");
    for(U k=0;k<count;++k){const U object=m.r32(table+4u*k);
        need(object!=0u&&(m.r8(object+0x14u)&1u)==0u,"B1366 inactive real records avoid eligibility virtual call");
    }
    // Actual final loop MOV EAX,[A288A4], followed by final MOV AL,1.
    return (table&0xffffff00u)|1u;
}
U original_6ce4d0(Memory& m,U action){
    const U eligible=original_6eb4d0_inactive(m);
    if(action==1u&&(eligible&255u)!=0u)return 0x3eu;
    if(action==5u&&(eligible&255u)!=0u)return 0x3fu;
    return action;
}
U packed_rgb(Memory& m,U r,U g,U b){
    return ((r>>(m.r8(0x83b2ecu)&31u))<<(m.r32(0x83b2e8u)&31u))|
           ((g>>(m.r8(0x83b2fcu)&31u))<<(m.r32(0x83b2f8u)&31u))|
           ((b>>(m.r8(0x83b2f4u)&31u))<<(m.r32(0x83b2f0u)&31u));
}
}
U fun_004480f0(Memory& m,const Inputs& i){
    const U type=m.r32(i.cx+0x418u);
    need(type!=0u&&m.r8(type+0x1354u)==1u&&m.r32(i.cx+0xa8u)==3u,"B1366 actual selector3 and enabled type branch");
    need(m.r32(i.cx+0x42cu)==2u||m.r32(i.cx+0x42cu)==3u,"B1366 existing current state");
    (void)original_443af0_pending(m,i.cx,5u);m.w32(i.cx+0xa8u,4u);return 6u;
}
U fun_00782055(Memory& m,const Inputs& i){
    U state=0u,flags=0u,directives=0u;const U count=0u;
    // The first% overwrites every relevant private parser field. The original's
    // earlier unproduced precision load is dead on this explicit domain.
    U ch=m.r8(i.arg[0]);++i.arg[0];
    need(ch=='%',"B1366 nonempty genuine count directive format");
    while(ch!=0u){
        need(ch=='%'||ch=='h'||ch=='n',"B1366 bounded count directives only");
        const U cls=parser_bytes[ch-0x20u]&15u;
        const U next=parser_bytes[cls*8u+state]>>4u;
        if(next==1u){need(ch=='%',"B1366 actual percent initialization");flags=0u;}
        else if(next==6u){need(ch=='h'&&state==1u,"B1366 actual short count qualifier");flags|=0x20u;}
        else if(next==7u){
            need(ch=='n'&&(state==1u||state==6u)&&directives<2u,"B1366 actual count conversion");
            const U destination=original_7827fb(m,i);
            if(flags&0x20u)m.w16(destination,count);else m.w32(destination,count);
            ++directives;
        }else throw std::domain_error("B1366 unsupported parser transition");
        state=next;ch=m.r8(i.arg[0]);++i.arg[0];
    }
    need(state==7u&&directives>=1u,"B1366 complete one or two count directives");return count;
}
U fun_0049aed0(Memory& m,const Inputs& i){
    const U self=i.cx,xy=i.arg[0],holder=m.r32(0xa1e0e4u),action=i.arg[3];
    need(i.arg[2]==0u&&(i.arg[1]&255u)==0u&&action==28u,"B1366 direct-return palette action28");
    need(m.r16(xy)==m.r16(0x83a940u)&&m.r16(xy+2u)==m.r16(0x83a942u),"B1366 selected coordinate matches actual cached coordinate");
    need(m.r8(self+0x11afu)==0u&&m.r8(self+0x11c8u)!=0u,"B1366 existing nonzero cached RGB and no position-update branch");
    need(m.r32(0x83b2e8u)==11u&&m.r32(0x83b2ecu)==3u&&m.r32(0x83b2f0u)==0u&&m.r32(0x83b2f4u)==3u&&m.r32(0x83b2f8u)==5u&&m.r32(0x83b2fcu)==2u,"B1366 accepted RGB565 layout");
    for(U k=0;k<24u;++k)need(m.r8(0x81fb50u+k)==0u,"B1366 exact original zero palette triplets");
    m.w8(self+0x11ccu,0u);
    const U record=original_4ec700_positive(m,holder,xy);need(record!=0u,"B1366 nonempty original lookup result");
    const U output=m.r32(m.r32(0x81a708u)+0x174u);
    m.w16(output+2u,packed_rgb(m,m.r8(self+0x11c8u),m.r8(self+0x11c9u),m.r8(self+0x11cau)));
    for(U k=0;k<8u;++k){const U p=0x81fb50u+3u*k;
        // Actual WORD[ESP24] is OUTERarg0 low16; EBX retains originalxy.
        i.arg[0]=(i.arg[0]&0xffff0000u)|m.r16(p);
        // EBP startsoutput+2, thenADD2/store[EBP-2]: firstloop storeoverwritescachedcolor.
        m.w16(output+2u+2u*k,packed_rgb(m,m.r8(p),m.r8(p+1u),m.r8(p+2u)));
    }
    m.w32(holder+0x154u,0xffffffffu);
    const U normalized=original_6ce4d0(m,action);
    need(normalized==28u,"B1366 exact terminal table entry49B868->49B727");return normalized-1u;
}
}
