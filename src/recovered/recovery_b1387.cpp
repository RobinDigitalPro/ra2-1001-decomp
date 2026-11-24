#include "recovery_b1387.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1387 {
namespace {
using U=std::uint32_t;
void need(bool b,const char* s){if(!b)throw std::domain_error(s);}
void append(Memory& m,U header,U self){
    const U n=m.r32(header+0x10),capacity=m.r32(header+8);
    need(global_b26::s32(n)>=0&&global_b26::s32(n)<global_b26::s32(capacity),"B1387 original signed registry room required");
    m.w32(header+0x10,n+1);m.w32(m.r32(header+4)+4*n,self);
}
// Finite instruction-derived adapters for the actual bodies. These do not
// link to the historical B101/B66 implementations or their broader closures.
void original_40ff10(Memory& m,U c){
    m.w32(c+8,0x785e44);m.w32(c+0xc,0x785e3c);
    m.w32(c+0x18,0);m.w32(c+0x1c,0);m.w8(c+0x20,0);
    const U flags=m.r8(c+0x14)&0xf8;
    m.w32(c+0x10,0xffffffff);m.w32(c,0x785dd8);m.w32(c+4,0x785dbc);
    m.w32(c+8,0x785db4);m.w32(c+0xc,0x785dac);m.w8(c+0x14,flags);
}
void original_405bf0(Memory& m,U c){
    m.w32(c+0xc,0x8192ec);m.w32(c,0);m.w32(c+4,0);m.w32(c+8,0);
}
void original_5ca970(Memory& m,U c){
    original_40ff10(m,c);
    m.w32(c+0x24,0);m.w32(c+0x28,0);m.w32(c+0x2c,0);
    // 5CA97B MOV EAX,000000FF, then full DWORD stores (not -1).
    m.w32(c+0x6c,0xff);m.w32(c+0x70,0xff);
    m.w8(c+0x76,1);m.w8(c+0x7d,1);m.w8(c+0x85,1);
    m.w32(c+0x30,0);m.w32(c+0x34,0);m.w32(c+0x38,0);
    m.w32(c+0x64,0xffffffff);m.w8(c+0x68,0);
    for(U o:{0x74u,0x75u,0x77u,0x78u,0x79u,0x7au,0x7bu,0x7cu})m.w8(c+o,0);
    m.w32(c+0x80,0xffffffff);m.w8(c+0x84,0);
    m.w32(c+0x88,m.r32(0xa5aa68));m.w32(c+0x8c,m.r32(0xa5aa6c));m.w32(c+0x90,m.r32(0xa5aa70));
    m.w32(c+0x94,0);m.w32(c,0x792458);m.w32(c+4,0x79243c);
    m.w32(c+8,0x792434);m.w32(c+0xc,0x79242c);
    original_405bf0(m,c+0x3c);original_405bf0(m,c+0x50);
    append(m,0xa27fb8,c);append(m,0xaa8868,c);append(m,0xaa87b8,c);append(m,0xaa8760,c);
    m.w8(c+0x14,m.r8(c+0x14)|2);
}
U original_40ffd0(Memory& m,U subobject){
    need(m.r32(0xa255c0)==0,"B1387 original null-global registration branch");
    m.w32(subobject+0xc,0);return 0;
}
U original_4d4250(Memory& m,U vector){
    const U pointer=m.r32(vector+4);m.w32(vector+0x10,0);
    need(pointer==0,"B1387 vector pointer was initialized null by root");
    m.w8(vector+0xd,0);m.w32(vector+8,0);return pointer;
}
U original_5cbf20_inactive(Memory& m,U incoming_eax,const std::array<U,3>& point){
    (void)point; // Produced root-local XYZ; original inactive arm never reads it.
    need(m.r8(0xa285a8)==0,"B1387 inactive entry to original 5CBF20");
    return incoming_eax&0xffffff00u; // MOV AL,0 / XOR AL,AL; not a full zero return.
}
void contract(Memory& m,const Inputs& i){
    need(i.arg[0]!=0&&i.arg[1]!=0&&i.arg[2]==0&&i.arg[3]==0&&i.arg[4]!=0,
         "B1387 descriptor/two points and absent optional actor/owner");
    const U n=m.r32(i.arg[0]+0x26c);
    const auto cw=i.fp.image.word(0);
    need(n>=1&&n<=5&&m.r32(i.arg[0]+0x288)==0xffffffff&&m.r32(i.arg[0]+0x2d0)==0,
         "B1387 bounded configured integer and descriptor default fields");
    need(m.r32(0xa255c0)==0&&m.r8(0xa285a8)==0&&m.r32(0x78d2b0)==0x4d4250,
         "B1387 actual inactive globals and genuine vector target");
    need(i.fp.image.word(4)==0&&i.fp.image.word(8)==0xffff&&(cw&0xf0ff)==0x007f&&(cw&0x300)!=0x100,
         "B1387 empty TOP0 masked x87 with valid precision");
    for(U h:{0xa27fb8u,0xaa8868u,0xaa87b8u,0xaa8760u,0xa1a5b0u}){
        const U count=m.r32(h+0x10),extra=h==0xaa8868u?2u:1u;
        need(m.r32(h+8)==8&&count<=8-extra,"B1387 six appends require reserved signed capacity");
    }
}
}
std::uint32_t fun_00602650(Memory& m,const Inputs& i){
    contract(m,i);const U c=i.cx,descriptor=i.arg[0];
    original_5ca970(m,c);
    m.w32(c+0x98,descriptor);m.w32(c+0x9c,0);m.w32(c+0xa0,0);m.w32(c+0xa4,0);
    const U vector=c+0xa8;
    m.w32(vector+4,0);m.w32(vector+8,0);m.w8(vector+0xc,1);m.w8(vector+0xd,0);
    m.w32(vector,0x78d2a4);m.w32(vector+0x14,10);m.w32(vector+0x10,0);
    m.w32(c+0xc0,m.r32(0xa5e0c0));m.w32(c+0xc4,m.r32(0xa5e0c4));m.w32(c+0xc8,m.r32(0xa5e0c8));
    m.w32(c+0xcc,0);m.w32(c+0xd0,0);
    i.fp.load_integer32(m.r32(descriptor+0x26c));m.w32(c+0xd4,i.fp.pop32());
    m.w32(c+0xd8,m.r32(descriptor+0x288));m.w32(c+0xdc,m.r32(descriptor+0x2d0));
    m.w32(c+0xe0,29);m.w8(c+0xe4,0);m.w8(c+0xe5,0);
    m.w32(c,0x792f4c);m.w32(c+4,0x792f30);m.w32(c+8,0x792f28);m.w32(c+0xc,0x792f20);
    (void)original_40ffd0(m,c+4);append(m,0xa1a5b0,c);
    need(m.r32(vector)==0x78d2a4,"B1387 root-produced actual vector vptr");
    (void)original_4d4250(m,vector);
    for(U k=0;k<3;++k)m.w32(c+0xc0+4*k,m.r32(i.arg[4]+4*k));
    const std::array<U,3> private_point{{m.r32(i.arg[1]),m.r32(i.arg[1]+4),m.r32(i.arg[1]+8)}};
    m.w32(c+0xcc,0);m.w32(c+0xd0,i.arg[2]);
    (void)original_5cbf20_inactive(m,i.arg[1],private_point);
    append(m,0xaa8868,c);return c;
}
}
