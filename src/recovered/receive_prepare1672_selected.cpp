#include "recovered/global_b26_memory.hpp"
#include <stdexcept>
namespace preparation1672 {
using Memory=ra2::recovered::global_b26::Memory;using U=unsigned;
void require(bool b){if(!b)throw std::domain_error("B1672 receive preparation outside qualified71B domain");}
void copy(Memory&m,U dst,U src,U n){for(U k=0;k<n;++k)m.w8(dst+k,m.r8(src+k));}
U select_480530(Memory&m,U table,U index){
    const U slot=m.r32(m.r32(table+0x40)+4*index);
    const U record=m.r32(table+0x34)+20*slot;
    return (m.r32(record)&1)?record:0;
}
U normal_table(Memory&m,U provider){
    require(provider&&m.r32(provider)==0x78f684);
    const U t=m.r32(provider+4);require(m.r32(t)==0x788db4);return t;
}
U receive_523870(Memory&m,U provider,U payload,U length,U descriptor,U word){
    const U table=normal_table(m,provider);
    if(!m.r32(table+0x38))return 0;
    const U record=select_480530(m,table,0);
    if(!record||(m.r8(record)&2))return 0;
    m.w32(record,m.r32(record)|2);
    const U total=m.r32(record+4),buffer=m.r32(record+8);
    require(total==71); // Selected positive61-byte payload, no capacity guess.
    copy(m,payload,buffer+10,total-10);
    m.w32(length,total-10);m.w16(word,m.r16(buffer+8));
    copy(m,descriptor,m.r32(record+16),10);return 1;
}
}
