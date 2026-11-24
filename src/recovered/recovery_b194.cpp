#include "recovery_b194.hpp"
#include "recovered/global_b26_memory.hpp"
#include "recovered/records_b85.hpp"
#include <array>
#include <cstdint>
#include <algorithm>
#include <stdexcept>

namespace ra2::recovered::recovery_b194 {
using global_b26::Inputs;
using global_b26::Memory;
using global_b26::s32;

namespace {
struct Rect { std::uint32_t x,y,w,h; };

// Exact 0x1fdf0 operation order for the positive intersection domain below;
// the two optional accumulator arguments in the caller are zero.
Rect clip_1fdf0(Rect r1, Rect r2) {
    auto left=r2.x,top=r2.y,w=r2.w,h=r2.h;
    if(s32(r1.w)<=0 || s32(r1.h)<=0 || s32(w)<=0 || s32(h)<=0)
        return {0,0,0,0};
    if(s32(left)<s32(r1.x)){ w += left-r1.x; left=r1.x; }
    if(s32(w)<1)return {0,0,0,0};
    if(s32(top)<s32(r1.y)){ h += top-r1.y; top=r1.y; }
    if(s32(h)<1)return {0,0,0,0};
    if(s32(r1.x+r1.w)<s32(left+w))w=r1.x-left+r1.w;
    if(s32(w)<1)return {0,0,0,0};
    if(s32(r1.y+r1.h)<s32(top+h))h=r1.y-top+r1.h;
    if(s32(h)<1)return {0,0,0,0};
    return {left,top,w,h};
}

// Original 0x157340 (VA 0x557340) setup and 0x157280 (VA 0x557280)
// next-item operation, limited to the reviewed one-item queue plus terminator.
void cursor_setup(Memory& m,std::uint32_t p) {
    const auto row=m.r32(p+0xf0u);
    m.w32(p+0x108u,1u); m.w32(p+0x10cu,row);
    m.w32(p+0x110u,row-1u);
    const auto base=m.r32(p+0x138u);
    m.w32(p+0x114u,(row<<11)+base+4u);
}
std::uint32_t cursor_next(Memory& m) {
    constexpr std::uint32_t p=0x0081a820u;
    const auto count=m.r32(p+0x110u), old=m.r32(p+0x114u);
    if(count!=0u){
        const auto begin=m.r32(p+0x108u)+1u;
        const auto end=m.r32(p+0x10cu)-1u;
        m.w32(p+0x108u,begin); m.w32(p+0x110u,count-1u);
        m.w32(p+0x10cu,end); m.w32(p+0x114u,old-0x7fcu);
        return m.r32(old);
    }
    auto end=m.r32(p+0x10cu), begin=m.r32(p+0x108u), row=m.r32(p+0xf0u);
    m.w32(p+0x108u,end); m.w32(p+0x10cu,begin);
    const auto span=end-row, parity=span+begin-1u;
    if(parity&1u){++begin;--row;m.w32(p+0x10cu,begin);}
    else{++end;row-=2u;m.w32(p+0x108u,end);}
    m.w32(p+0x110u,row);
    const auto cell=(m.r32(p+0x10cu)<<9)+m.r32(p+0x108u);
    const auto next=m.r32(p+0x138u)+(cell<<2);
    m.w32(p+0x114u,next);
    return m.r32(old);
}

// 0x70ec0 route-specific composition. Its first call to 0x71360 is the
// original accepted gate-false path: global byte A285A8 is zero, so the
// linked-list virtual call at slot +0x2c is not reached. The remaining path
// reaches accepted original 0x1d4730, not an injected return value.
void call_71360_gatefalse(Memory& m,std::uint32_t object) {
    (void)object;
    // Actual MOV AL,[A285A8]; TEST AL,AL; JZ 47139B; XOR EAX,EAX;
    // POP EDI; POP ESI; RET8. The reached prefix has no persistent writes.
    if(m.r8(0xa285a8u))throw std::domain_error("194 active linked-list route excluded");
}
void color_pair_70ec0(Memory& m, std::uint32_t object,
                      std::array<std::uint8_t,3>& out0, std::array<std::uint8_t,3>& out1) {
    if(m.r8(0x00a285a8u)!=0u)throw std::domain_error("B194 requires actual 0x71360 gate-false branch");
    call_71360_gatefalse(m,object);
    if((m.r32(object+0x140u)&0x100u)!=0u || m.r32(object+0x38u)!=0xffffu ||
       m.r32(0x00a3ab38u)!=0u || m.r32(object+0x44u)!=0u)
        throw std::domain_error("B194 0x70ec0 selector outside bounded route");
    const auto table=m.r32(0x00a28914u);
    (void)m.r32(table+4u*m.r32(0x00a3ab38u)); // original selected EDI is not dereferenced on this branch
    const auto type_table=m.r32(0x00a1e11cu);
    const auto type_object=m.r32(type_table); // receiver+44 is zero
    if(m.r8(type_object+0x279u)==0u || m.r32(type_object+0x26cu)!=0u)
        throw std::domain_error("B194 0x70ec0 requires nonvirtual fallback to 0x1d4730");
    records_b85::Inputs interval{}; interval.cx=0;
    const auto color=records_b85::fun_005d4730(m,interval);
    if(color==0xffffffffu)throw std::domain_error("B194 excludes 0x763a0 continuation");
    out0={0xaau,0xaau,0x82u}; out1={0xaau,0xaau,0x82u};
}
}

// RVA 0x2288d0 finite positive contract. The root's local stack records are
// represented as C++ temporaries; persistent writes and helper order match the
// original. Entry args: arg0 points to a positive row stride at +8; arg1 points
// to the caller's signed x/y/width/height rectangle. RET 8; full EAX is zero
// after the final accepted cursor read returns null.
std::uint32_t fun_006288d0(Memory& m,const Inputs& in) {
    const auto receiver=in.cx, stride_record=in.arg[0], clip_record=in.arg[1];
    if(receiver!=0x0081a820u)throw std::domain_error("B194 fixture pins first-call receiver to original manager");
    cursor_setup(m,receiver);
    auto item=cursor_next(m);
    while(item!=0u){
        const auto x=s32(ra2::recovered::global_b26::sx16(m.r16(item+0x24u)));
        const auto y=s32(ra2::recovered::global_b26::sx16(m.r16(item+0x26u)));
        const auto bound=m.r32(receiver+0x1494u);
        const auto sum=std::uint32_t(x)+std::uint32_t(y);
        if(s32(sum)>=s32(bound)){
            const auto map_width=(m.r32(0x0081a918u)*2u)-m.r32(0x0081a910u)+1u;
            Rect first{std::uint32_t(x)-std::uint32_t(y)-map_width,
                       sum-bound,2u,1u};
            Rect second{m.r32(clip_record),m.r32(clip_record+4u),
                        m.r32(clip_record+8u),m.r32(clip_record+12u)};
            const auto clipped=clip_1fdf0(first,second);
            if(s32(clipped.w)>0 && s32(clipped.h)>0){
                const auto index=m.r32(stride_record+8u)*clipped.y+clipped.x;
                std::array<std::uint8_t,3> local0{},local1{};
                color_pair_70ec0(m,item,local0,local1);
                const auto edge_key=std::uint32_t(x)-std::uint32_t(y)-map_width;
                if(edge_key==m.r32(clip_record)-1u){
                    const auto dst=m.r32(receiver+0x1238u)+index*3u;
                    for(unsigned k=0;k<3;++k)m.w8(dst+k,local1[k]);
                }else if(edge_key==m.r32(clip_record+8u)+m.r32(clip_record)-1u){
                    const auto dst=m.r32(receiver+0x1238u)+index*3u;
                    for(unsigned k=0;k<3;++k)m.w8(dst+k,local0[k]);
                }else{
                    const auto dst=m.r32(receiver+0x1238u)+index*3u;
                    for(unsigned k=0;k<3;++k){m.w8(dst+k,local0[k]);m.w8(dst+3u+k,local1[k]);}
                }
            }
        }
        item=cursor_next(m);
    }
    return 0u;
}
}
