#include "recovered/recovery_b1379.hpp"
#include "recovered/floating_b61_b.hpp"
#include "recovered/global_b58_c.hpp"
#include <stdexcept>

namespace ra2::recovered::b1379 {
namespace {
using U=std::uint32_t;
using global_b26::s32;
using global_b26::sx16;
constexpr U directions[]{0xffff0000,0xffff0001,1,0x10001,0x10000,0x1ffff,0xffff,0xffffffff};
constexpr U absent[]{0xa3ab18,0xa547ac,0xa3a8ac,0xa3a1c8,0xa3ab30,0xa3ab2c,0xa55944,0xa3a8a4,0xa3aae0,0xa55c50};
void require(bool b,const char* why){if(!b)throw std::domain_error(why);}
void compass(Memory& m){for(U k=0;k<8;++k)require(m.r32(0x839da0+4*k)==directions[k],"B1379 requires original491400 compass prestate");}
// Original42ADD0 and4766C0 add each WORD independently. Their scratch output
// and overwritten nested arguments are private; neither writes root arg[].
U add_point(U point,U delta){return U(std::uint16_t(point+delta))|(U(std::uint16_t((point>>16)+(delta>>16)))<<16);}
// Actual545500 indexed nonnull branch. Packed argument is passed by value here
// only because the caller's produced local address is private and not escaped.
U lookup(Memory& m,U point){
    const U index=(sx16(point>>16)<<9)+sx16(point&0xffff);
    require(s32(index)>=0&&index<0x40000,"B1379 nonfallback map index");
    const U cell=m.r32(m.r32(0x81a958)+4*index);
    require(cell&&m.r32(cell)==0x788b04&&m.r32(cell+0x24)==point,"B1379 populated authentic cell");
    return cell;
}
U neighbor(Memory& m,U cell,U direction){
    if(direction>=8)return cell; //4766C0 original unsigned dispatch.
    return lookup(m,add_point(m.r32(cell+0x24),m.r32(0x839da0+4*(direction&7))));
}
// Actual527630 warm cache branch, called only through pinned790188+9C.
U warm_tile(Memory& m,U type){
    require(m.r32(type)==0x790188&&m.r32(0x790224)==0x527630,"B1379 authentic tile virtual provider");
    const U value=m.r32(type+0xa4);require(value!=0,"B1379 borrowed warmed cache required");return value;
}
// Exact62FDE0 enabled-state adaptation from leaf_text_rng to multi-span Memory.
// Real two-table-word XOR, write and both cursor increments; no fixed draw.
U random_word(Memory& m,U state){
    require(m.r8(state)==0,"B1379 enabled RNG required");
    U p=m.r32(state+4),q=m.r32(state+8);
    require(p<250&&q<250&&p!=q,"B1379 distinct bounded RNG cursors");
    m.w32(state+12+4*p,m.r32(state+12+4*p)^m.r32(state+12+4*q));
    p=m.r32(state+4);q=m.r32(state+8);const U value=m.r32(state+12+4*p);
    ++p;++q;m.w32(state+4,p);m.w32(state+8,q);
    if(s32(p)>=250)m.w32(state+4,0);
    if(s32(q)>=250)m.w32(state+8,0);
    return value;
}
// Actual76AA50: FNSTCW's unproduced adjacent high WORD is masked by AND FFFF
// before use. Only the produced control value can escape; no invented padding.
U truncate(Memory& m,const Inputs& i){
    const U wanted=m.r32(0x7c3a04),old=i.fp.control();
    if(old!=wanted)i.fp.load_control(std::uint16_t(wanted));
    return U(i.fp.pop_integer64());
}
U blocked_neighbor(Memory& m,U cell){
    require(m.r8(cell+0x11b)==0&&m.r8(cell+0x11c)==0&&(m.r32(cell+0x140)&0x100)!=0,"B1379 blocked ordinary neighbor");
    global_b26::Inputs nested{};nested.cx=0x81a820;nested.arg[0]=cell+0x24;nested.arg[1]=1;
    U eax=global_b26::fun_00557450(m,nested); //Actual geometry and populated grid.
    if((eax&255)==0)return eax&0xffffff00; //4788A9 preserves high24.
    eax=m.r32(cell+0x140);
    require((eax&0x500)!=0,"B1379 original4787C5 flag exit");
    return eax&0xffffff00;
}
void queue_contract(Memory& m,const Inputs& i){
    compass(m);const U self=i.cx,heap=m.r32(self+0xf4),record=m.r32(m.r32(heap+8)+4);
    const auto scale=floating_b61::read64(m,self+0xa0);
    require(m.r32(heap)==1&&m.r32(heap+4)==8&&record!=0&&m.r32(record)==0x30003&&m.r32(record+4)==0&&
        m.r32(heap+12)==record&&m.r32(heap+16)==record&&m.r32(self+0xfc)==record&&m.r32(self+0xf0)==1&&m.r8(m.r32(self+0xf8)+5)!=0,
        "B1379 coherent borrowed one-record heap and pending marker");
    require(scale==0x3ff0000000000000ull||scale==0x4000000000000000ull||scale==0x4008000000000000ull,"B1379 exact scale1/2/3");
    require(floating_b61::read64(m,0x787520)==0x3ee4f8b588e368f1ull&&m.r32(0x7c3a04)==0xe7f,"B1379 authentic numeric literals");
    require(i.fp.image.word(8)==0xffff&&i.fp.image.word(4)==0,"B1379 empty TOP0 clear-status entry");
    const U cw=i.fp.image.word(0);require((cw&0xf0ff)==0x7f&&(cw&0x300)!=0x100,"B1379 twelve valid masked controls");
    require(m.r32(0x81a910)==4&&m.r32(0x81a914)==4&&m.r32(0x81a918)==0&&m.r32(0x81a91c)==0&&m.r32(0x81a920)==4&&m.r32(0x81a924)==4,"B1379 actual4x4 map bounds");
    const U state=m.r32(0xa255c0)+0x218,p=m.r32(state+4),q=m.r32(state+8);
    require(m.r8(state)==0&&p<250&&q<250&&p!=q,"B1379 enabled bounded RNG");
    const U draw=m.r32(state+12+4*p)^m.r32(state+12+4*q);
    require(draw>=1&&draw<=0x7ffffffe,"B1379 bounded positive random draw");
    const U center=lookup(m,m.r32(record));
    for(U k=0;k<8;++k){const U cell=neighbor(m,center,k);require(m.r8(cell+0x11b)==0&&m.r8(cell+0x11c)==0&&m.r32(cell+0x140)==0x100,"B1379 eight blocked nonactor cells");}
}
}

// RVA71910: first tile family, positive four-cardinal variant, authentic warm
// type cache. Remaining families use the original explicit -1 absence guards.
U fun_00471910(Memory& m,const Inputs& i){
    compass(m);for(U a:absent)require(m.r32(a)==0xffffffff,"B1379 original absent-family sentinel");
    const U self=i.cx,old=m.r32(self+0x38),base=m.r32(0xa3abbc),fallback=m.r32(0xa55d20);
    require(old==0&&fallback==0&&base==16&&m.r32(self)==0x788b04,"B1379 first-family initial cell");
    U mask=0;
    for(U bit=0,direction=0;bit<4;++bit,direction=(direction+2)&7){
        const U cell=neighbor(m,self,direction),tile=m.r32(cell+0x38);
        require(tile<=1,"B1379 cardinal neighbor tile0/1");
        if(tile!=fallback&&(s32(tile)<s32(base)||s32(tile)>s32(base+15)))mask|=1u<<bit;
    }
    require(mask!=0,"B1379 positive variant change");
    m.w32(self+0x38,mask?base+mask:fallback);
    // Three subsequent absent families and both absent final ranges bypass all
    // advanced terrain branches. Original oldtile local survives untouched.
    const U now=m.r32(self+0x38);
    if(old!=now){const U type=m.r32(m.r32(0xa28914)+4*now);require(m.r32(type+0x264)==now,"B1379 coherent type catalog index");(void)warm_tile(m,type);}
    return old!=m.r32(self+0x38)?1u:0u;
}

// RVA2DE9E0: consume an actual pending record; all eight ordinary neighbors
// are rejected by original geometry/flags, so the persistent pending bit clears.
U fun_006de9e0(Memory& m,const Inputs& i){
    queue_contract(m,i);const U self=i.cx,heap=m.r32(self+0xf4),count=m.r32(heap);
    i.fp.load64(floating_b61::read64(m,self+0xa0));
    i.fp.compare_pop64(floating_b61::read64(m,0x787520));
    require((i.fp.status()&0x4100)==0,"B1379 scale passes actual threshold");
    i.fp.load_integer32(count);i.fp.multiply64(floating_b61::read64(m,self+0xa0));
    U limit=truncate(m,i);if(s32(limit)<5)limit=5;else if(s32(limit)>25)limit=25;
    const U draw=random_word(m,m.r32(0xa255c0)+0x218),sign=global_b26::sar(draw,31),absolute=(draw^sign)-sign;
    const U request=global_b26::idiv_remainder(absolute,limit)+1;
    const U map_count=(m.r32(0x81a914)+4)*m.r32(0x81a910)*2; //428AC0 exact formula.
    require(s32(count)<=s32(map_count-20),"B1379 no queue expansion");
    const U slots=m.r32(heap+8),record=m.r32(slots+4);
    m.w32(slots+4,m.r32(slots+count*4));m.w32(m.r32(heap+8)+count*4,0);m.w32(heap,m.r32(heap)-1);
    Inputs sift{};sift.cx=heap;sift.ax=count;sift.arg[0]=1;sift.fp=i.fp;
    (void)floating_b61::fun_0058be90(m,sift);i.fp=sift.fp;
    const U center=lookup(m,m.r32(record));U eligible=0;
    for(U direction=0;direction<8;++direction)if(blocked_neighbor(m,neighbor(m,center,direction))&255)++eligible;
    require(eligible==0,"B1379 actual blocked-neighbor route");
    const U packed=m.r32(center+0x24),x=sx16(packed&0xffff),y=sx16(packed>>16),width=m.r32(0x81a910);
    const U index=(x-width+y-1)*width+global_b26::sar(x-y+width-1,1); //428A90.
    m.w8(m.r32(self+0xf8)+index,0);
    require(eligible<request&&m.r32(heap)==0,"B1379 exhausted queue next iteration");
    return 0; //Actual6DEC13 XOR EAX, subsequent null-record exit; RET0.
}
}
