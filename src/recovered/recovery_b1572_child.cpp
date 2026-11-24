#include "recovery_b1572_child.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::global_b26 {
std::uint32_t fun_00545500(Memory&,const Inputs&);
}
namespace ra2::recovered::b1572_child {
namespace {
using U=std::uint32_t;
void need(bool b,const char* s){if(!b)throw std::domain_error(s);}
void descriptor(Memory& m,U t){
    need(t&&m.r32(t)==0x7881f8&&m.r32(t+0x5a4)==0&&m.r32(t+0xbf0)==0&&
         m.r8(t+0x1351)==0&&m.r8(t+0x1358)==0&&m.r8(t+0x1359)==0&&m.r8(t+0xada)==0,
         "B1389 genuine fresh descriptor used-field contract");
}
void common(Memory& m,const Inputs& i){
    need(m.r32(0xa283c4)==0&&m.r8(0xa28953)==0&&m.r8(0xa285a8)==1,
         "B1389 normal active query, no global always-true override");
    need(m.r32(0x81a910)==20&&m.r32(0x81a918)==0&&m.r32(0x81a91c)==0&&
         m.r32(0x81a920)==20&&m.r32(0x81a924)==20&&m.r32(0x8391d0)==0x3f800000&&m.r32(0x785738)==0,
         "B1389 actual bounded map rectangle and B179-produced coefficient1");
    const auto cw=i.fp.image.word(0);
    need((i.fp.image.word(4)&0x3800)==0&&i.fp.image.word(8)==0xffff&&cw==0x0e7f,
         "B1572 caller-produced numeric state; TOP0/empty/CW0E7F, preserve produced status");
}
void cell(Memory& m,U c){
    const U x=m.r16(c+0x24),y=m.r16(c+0x26);
    need(m.r32(c)==0x788b04&&x==y&&x>=10&&x<=20&&m.r32(c+0x44)==0xffffffff&&m.r32(c+0xec)==0&&
         m.r32(c+0xe4)==0&&m.r32(c+0xe8)==0&&m.r8(c+0x124)==0&&m.r8(c+0x11b)==0&&m.r8(c+0x11c)==0,
         "B1389 real flat unoccupied Clear cell on interior/boundary");
}
U original_471260_empty(Memory& m,U c,const std::array<U,2>& point){
    // Actual root produces both private words zero before passing their address.
    // The aligned helper reads them and selects E4, then returns ESI=0.
    const U x=point[0]*7,y=point[1]*7;(void)x;(void)y;
    need(m.r32(c+0xe4)==0,"B1389 original471260 empty live list");return 0;
}
U original_471360_empty(Memory& m,U c){
    need(m.r8(0xa285a8)==1&&m.r32(c+0xe4)==0,"B1389 original471360 active empty list");
    return 0; // Real XOR EAX,EAX / RET8; no original kind callback reached.
}
U original_557530(Memory& m,U c){
    // Integer-only real geometry route with arg1byte1 and flat11B/11C.
    const U x=global_b26::sx16(m.r16(c+0x24)),y=global_b26::sx16(m.r16(c+0x26));
    const U offset=global_b26::sx8(m.r8(c+0x11b));
    U ax=m.r32(0x81a910),limit=ax+2*m.r32(0x81a91c)+offset;
    if(global_b26::s32(x+y)<=global_b26::s32(limit))return ax&0xffffff00u;
    limit=ax+2*(m.r32(0x81a924)+m.r32(0x81a91c))+2+offset;
    if(global_b26::s32(x+y)>global_b26::s32(limit))return ax&0xffffff00u;
    const U f8=m.r32(0x81a918);limit=2*(m.r32(0x81a920)+f8)-ax;
    if(global_b26::s32(x-y)>=global_b26::s32(limit))return ax&0xffffff00u;
    ax-=2*f8;
    return (ax&0xffffff00u)|(global_b26::s32(y-x)<global_b26::s32(ax)?1u:0u);
}
U original_458540_warm(Memory& m,U type){
    need(m.r32(0x788288)==0x458540&&(m.r8(0x8370f0)&1)&&m.r32(type+0xb94)==0x837130&&m.r32(0x837118)==0x7fff7fff,
         "B1389 genuine +90 target and earlier original getter poststate");
    return m.r32(type+0xb94); // Actual full EAX, RET4; no atexit registration.
}
U original_45e970(Memory& m){
    need(m.r32(0x788224)==0x45e970,"B1389 genuine +2C kind7 body");return 7;
}
U lookup_produced_coordinate(Memory& original,U packed){
    // A four-byte adapter-owned span holds the fully produced root-local pair.
    // Its model address is never observed by original game state or returned.
    std::array<std::uint8_t,4> bytes{};leaf::Memory local(bytes.data(),0x10000,4);
    local.w32(0x10000,packed);Memory m=original;m.add(local);
    global_b26::Inputs nested{};nested.cx=0x81a820;nested.arg[0]=0x10000;
    return global_b26::fun_00545500(m,nested);
}
}
std::uint32_t fun_004714b0(Memory& m,const Inputs& i){
    common(m,i);cell(m,i.cx);descriptor(m,i.arg[1]);
    need(i.arg[0]==0,"B1389 actual fresh descriptor coefficient selector0");
    // A283C4=0, descriptor1359/1358/1351/BF0=0, active empty E4.
    const std::array<U,2> private_point{{0,0}};
    need(original_471260_empty(m,i.cx,private_point)==0,"B1389 no occupant");
    need(original_471360_empty(m,i.cx)==0,"B1389 no kind36 occupant");
    const U geometry=original_557530(m,i.cx);
    if((geometry&255)==0)return geometry&0xffffff00u;
    // Overlay44=-1 selects the real coefficient tail. No rules callbacks.
    U ax=9*m.r32(i.cx+0xec)+i.arg[0];
    i.fp.load32(m.r32(0x8391d0+4*ax));i.fp.compare_pop32(m.r32(0x785738));
    ax=(ax&0xffff0000u)|i.fp.status();
    return (ax&0xffffff00u)|((ax&0x4000)?0u:1u);
}
std::uint32_t fun_006d3650(Memory& m,const Inputs& i){
    common(m,i);descriptor(m,i.cx);
    const U input_point=i.arg[0],packed=m.r32(input_point);
    need(packed!=m.r32(0xaa7cf0)&&m.r32(i.cx+0xc78)==0&&m.r8(i.cx+0x1387)==0,
         "B1389 noncached coordinate and authentic default foundation/delegation");
    U list=original_458540_warm(m,i.cx);
    const U kind=original_45e970(m);need(kind==7,"B1389 actual descriptor kind7");
    need(m.r32(list)==0&&m.r32(list+4)==0x7fff7fff,"B1389 genuine nonempty first foundation row");
    bool failed=false;
    // T=entryESP-1C: T+20 is outerarg0, not private scratch.
    i.arg[0]&=0xffffff00u;
    while(m.r32(list)!=0x7fff7fff){
        const U offset=m.r32(list);list+=4;
        const U x=(packed+offset)&0xffffu;
        const U y=((packed>>16)+(offset>>16))&0xffffu;
        const U coordinate=x|(y<<16),receiver=lookup_produced_coordinate(m,coordinate);
        need(receiver!=0xa57610,"B1389 real mapped cell, no fallback object");
        Inputs child=i;child.cx=receiver;child.arg[0]=m.r32(i.cx+0x5a4);child.arg[1]=i.cx;child.arg[2]=i.arg[1];
        const U result=fun_004714b0(m,child);i.fp=child.fp;
        if(result&255)i.arg[0]=(i.arg[0]&0xffffff00u)|1u;else failed=true;
    }
    // Genuine descriptorBF0=0 uses XOR EAX,EAX then SETZ AL of failed flag.
    return failed?0u:1u;
}
}
