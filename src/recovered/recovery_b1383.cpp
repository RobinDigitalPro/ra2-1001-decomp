#include "recovered/recovery_b1383.hpp"
#include "recovered/recovery_b1067.hpp"
#include "recovered/recovery_b1065.hpp"
#include "recovered/global_b58_c.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1383 {
namespace {
using U=std::uint32_t;
void need(bool b,const char* why){if(!b)throw std::domain_error(why);}
void reset_iterator(Memory& m,U map){
    const U width=m.r32(map+0xf0);
    m.w32(map+0x108,1);m.w32(map+0x10c,width);m.w32(map+0x110,width-1);m.w32(map+0x114,m.r32(map+0x138)+(width<<11)+4);
}
// Actual557280 nonzero110 branch. Both calls in each selected pass take this
// branch; the old slot is returned after the iterator fields are advanced.
U next(Memory& m,U map){
    const U count=m.r32(map+0x110),slot=m.r32(map+0x114);
    need(count!=0,"B1383 original first diagonal iterator scope");
    m.w32(map+0x108,m.r32(map+0x108)+1);m.w32(map+0x110,count-1);m.w32(map+0x10c,m.r32(map+0x10c)-1);m.w32(map+0x114,slot-0x7fc);
    return m.r32(slot);
}
void ambient_null(Memory& m,const Inputs& i,U cell){
    // Original478CF0's eight output addresses are fully produced private
    // arguments/locals. These model-local cells never alias root arg[].
    std::array<std::uint8_t,32> bytes{};
    leaf::Memory local(bytes.data(),0x20000,U(bytes.size()));auto memory=m;memory.add(local);
    Inputs call{};call.cx=cell;call.fp=i.fp;for(U k=0;k<8;++k)call.arg[k]=0x20000+4*k;
    (void)b1067::fun_00479040(memory,call);i.fp=call.fp;
    std::array<U,8> a{};for(U k=0;k<8;++k)a[k]=memory.r32(0x20000+4*k);
    b1065::Inputs lookup{};lookup.cx=a[5];lookup.dx=a[6];lookup.arg[0]=a[7];
    const U record=b1065::fun_005277f0(m,lookup); //Authentic white registry hit.
    m.w32(cell+0x34,record);if(record)m.w32(record+0x194,m.r32(record+0x194)+1);
    m.w32(cell+0x104,a[0]);for(U k=1;k<8;++k)m.w16(cell+0x106+2*k,a[k]);
}
U cache_index(Memory& m,U point){ //Actual54CF40 signed/clamped index.
    U value=(m.r32(0x81a914)+m.r32(0x81a910)+1)*global_b26::sx16(m.r16(point+2))+global_b26::sx16(m.r16(point));
    if(global_b26::s32(value)<0)return 0;
    if(global_b26::s32(value)>=global_b26::s32(m.r32(0x81a888)))return m.r32(0x81a888)-1;
    return value;
}
// Exact reached472140/478B40 semantics, adapting B1211's real cache rows to
// borrowed Memory and explicit guest FP. No Heap object or allocator is faked.
U publish_cache(Memory& m,const Inputs& i,U cell){
    const U a=m.r32(0x81a884)+4*cache_index(m,cell+0x24);
    const U z=m.r32(0x81a88c)+10*cache_index(m,cell+0x24);
    m.w32(cell+0xec,0);m.w8(cell+0x11c,0);
    global_b26::Inputs check{};check.cx=0x81a820;check.arg[0]=cell+0x24;check.arg[1]=1;
    need((global_b26::fun_00557450(m,check)&255)!=0,"B1383 real positive Map membership");
    i.fp.load32(m.r32(0x8391d8));i.fp.compare_pop64(floating_b61::read64(m,0x787518));
    need((i.fp.status()&0x4100)==0,"B1383 actual Clear Wheel comparison");
    m.w32(cell+0x4c,0);
    m.w8(a+1,m.r8(cell+0x11b));m.w8(a,m.r8(cell+0x4c));m.w8(z+8,m.r8(cell+0x11b));return z;
}
void contract(Memory& m,const Inputs& i){
    need(i.cx==0x81a820&&m.r32(0xa285c0)==0,"B1383 Map receiver and ordinary empty actor registry");
    need(m.r32(0x81a910)==20&&m.r32(0x81a914)==20&&m.r32(0x81a918)==0&&m.r32(0x81a91c)==0&&m.r32(0x81a920)==20&&m.r32(0x81a924)==20&&m.r32(0x81a888)==1681,"B1383 20x20 dimensions and full cache extents");
    const U table=m.r32(0x81a958),cell=m.r32(table+4*10241),config=m.r32(0xa255c0);
    need(cell&&m.r32(table+4*9730)==0&&m.r32(cell)==0x788b04&&m.r32(cell+0x24)==0x140001,"B1383 one real first cell then null iterator slot");
    need(m.r32(cell+0x34)==0&&m.r32(cell+0x38)==0xffff&&m.r32(cell+0x3c)==0&&m.r32(cell+0x44)==0xffffffff&&m.r32(cell+0xe4)==0&&m.r8(cell+0x11b)==0&&m.r8(cell+0x11c)==0,"B1383 null-current flat Clear cell, no overlay/actors");
    const U ambient=m.r32(config+0x22ac);
    need(ambient>=100&&ambient<=200&&m.r32(config+0x22b4)==100&&m.r32(config+0x22b8)==100&&m.r32(config+0x22bc)==100&&m.r32(config+0x22c0)==100&&m.r32(config+0x22c4)==16,"B1383 white positive normal ambient");
    need(m.r8(0xa39574)==0&&m.r32(0xa3957c)==0&&m.r32(0xa56458)==0&&m.r8(m.r32(0x821b88)+0x584)==0,"B1383 actual normal weather and empty local lights");
    const U count=m.r32(0x81a6e8),record=m.r32(m.r32(0x81a6dc));
    need(m.r32(0x821c90)!=0&&count>=2&&count<=8&&m.r32(record)==0x7905bc&&m.r32(record+0x198)==1000&&m.r32(record+0x19c)==1000&&m.r32(record+0x1a0)==1000&&m.r32(record+0x194)<128,"B1383 existing white record with bounded refcount");
    need(m.r8(m.r32(0x81a884)+4*821)==7&&m.r32(0x8391d8)==0x3f800000&&floating_b61::read64(m,0x787518)==0x3f847ae147ae147bull,"B1383 real cache initial class and warm Clear/literal");
    const U cw=i.fp.image.word(0);need(i.fp.image.word(8)==0xffff&&i.fp.image.word(4)==0&&(cw&0xf0ff)==0x7f&&(cw&0x300)!=0x100,"B1383 empty TOP0 and masked valid controls");
}
}
U fun_00548770(Memory& m,const Inputs& i){
    contract(m,i);const U map=i.cx;
    reset_iterator(m,map);
    for(U cell=next(m,map);cell;cell=next(m,map))m.w32(cell+0x140,m.r32(cell+0x140)&0xffcfffff);
    reset_iterator(m,map);U total=0;
    for(U cell=next(m,map);cell;cell=next(m,map)){
        m.w32(cell+0x30,0);ambient_null(m,i,cell);m.w32(cell+0x140,m.r32(cell+0x140)&0xfffdffff);
        // Actual4767A0 overlay=-1 branch returns full0; private aggregate
        // is produced at rootT+C. Positive work is the cell/cache publication.
        need(m.r32(cell+0x44)==0xffffffff,"B1383 actual no-overlay sum branch");total+=0;
        (void)publish_cache(m,i,cell);
    }
    return total;
}
}
