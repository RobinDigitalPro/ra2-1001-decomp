#include "recovery_b1313.hpp"
#include "recovered/map_b106.hpp"
#include "recovered/recovery_b522.hpp"
#include "recovered/leaf_memory.hpp"
#include "recovered/numeric_b88_detail.hpp"
#include <array>
#include <stdexcept>

namespace ra2::recovered::b1313 {
namespace {
using U=std::uint32_t;
constexpr U map=0x0081a820u, actor_vt=0x0078612cu;
constexpr U height_stack=0x7d100000u, update_stack=0x7d200000u;
constexpr U actor_globals=0x0083a8dcu, actor_count=0x0083a8e8u;
void need(bool v,const char* why){if(!v)throw std::domain_error(why);}

U height_at_actor(Memory& m,const Inputs& state,U actor){
    const U world=actor+0x88u,x=m.r32(world),y=m.r32(world+4u);
    // 557070 truncates signed world coordinates toward zero before the cell lookup.
    const U ix=numeric_b88::detail::div256(x),iy=numeric_b88::detail::div256(y);
    const U index=iy*512u+ix,table=m.r32(0x0081a958u);
    need(index<m.r32(0x0081a95cu)&&table,"B1313 original 557070 in-range cell lookup");
    const U cell=m.r32(table+index*4u);need(cell,"B1313 populated 557070 cell");
    std::array<std::uint8_t,8> bytes{};leaf::Memory local(bytes.data(),height_stack,U(bytes.size()));
    Memory view=m;view.add(local);view.w32(height_stack,x);view.w32(height_stack+4u,y);
    map_b106::Inputs h{};h.ax=iy;h.cx=cell;h.dx=height_stack;h.arg[0]=height_stack;h.arithmetic_flags=0x202u;h.fp=state.fp;
    const U height=map_b106::fun_004702c0(view,h);state.fp=h.fp;
    const U relative=m.r32(world+8u)-height;
    return m.r8(actor+0x79u)?relative-m.r32(0x00a5aa98u):relative;
}

void update_cell(Memory& original,Inputs& state,int x,int y,U house,U mode){
    std::array<std::uint8_t,0x4000> bytes{};leaf::Memory local(bytes.data(),update_stack,U(bytes.size()));
    Memory view=original;view.add(local);const U point=update_stack+0x1000u;
    view.w16(point,U(x));view.w16(point+2u,U(y));view.w32(point+4u,0u);
    recovery_b522::Inputs u{};u.cx=map;u.arg[0]=point;u.arg[1]=house;u.arg[2]=mode;u.fp=state.fp;
    (void)recovery_b522::fun_00499da0(view,u);state.fp=u.fp;
}

void visibility_pass(Memory& m,Inputs& state,U point,U radius,U house,U mode){
    need(radius==2u&&house&&house==m.r32(0x00a1e0e4u),"B1313 5475a0 radius-2/current-house route");
    const U renderer=m.r32(0x821b88u);
    need(renderer&&m.r8(renderer+0x1432u)==0u,"B1313 arg6=1 nested renderer query skipped");
    const U z=m.r32(point+8u);
    for(unsigned q=0;q<2u;++q){
        state.fp.load_integer32(z);state.fp.multiply64(floating_b61::read64(m,0xaa5f90u));
        floating_b61::fp_extended::add_integer32(state.fp,global_b26::s32(z)>=728?1u:0u);
        state.fp.add64(floating_b61::read64(m,0x785728u));
        need(numeric_b88::detail::integer(m,state.fp)==0u,"B1313 projected-height predicate");
    }
    const int cx=global_b26::s32(numeric_b88::detail::div256(m.r32(point)));
    const int cy=global_b26::s32(numeric_b88::detail::div256(m.r32(point+4u)));
    const int width=global_b26::s32(m.r32(map+0xf0u)),height=global_b26::s32(m.r32(map+0xf4u));
    need(m.r32(0x7908e8u+radius*4u)==21u,"B1313 radius-2 offset count");
    U calls=0;
    for(U k=0;k<21u;++k){
        const U packed=m.r32(0xa56e68u+4u*k);
        const int dx=global_b26::sx16(packed),dy=global_b26::sx16(packed>>16u),x=cx+dx,y=cy+dy;
        need(x+y>width&&x-y<width&&y-x<width&&x+y<=width+2*height,"B1313 original diagonal map bounds");
        state.fp.load_integer32(U(dy));state.fp.load_integer32(U(dx));state.fp.load_st0();
        numeric_b88::detail::reg<0xd8c9>(state.fp);state.fp.load_st2();numeric_b88::detail::reg<0xd8cb>(state.fp);
        state.fp.add_pop();const auto square=state.fp.pop64();state.fp.pop_st0();state.fp.pop_st0();
        numeric_b88::detail::root(m,state.fp,square);
        const int distance=std::int16_t(numeric_b88::detail::integer(m,state.fp));need(distance<=2,"B1313 radius-two distance");
        const U index=U(512*y+x),table=m.r32(map+0x138u);need(index<0x40000u&&table,"B1313 radius cell index");
        const U cell=m.r32(table+4u*index);need(cell,"B1313 populated radius cell");
        m.w32(cell+0x140u,m.r32(cell+0x140u)&~0x40u);update_cell(m,state,x,y,house,mode);++calls;
    }
    need(calls==21u,"B1313 5475a0 radius-two call cardinality");
}

void actor_update(Memory& m,Inputs& state,U actor,U arg0,U arg1){
    need(m.r32(actor)==actor_vt&&m.r32(actor_vt+0x118u)==0x0041a530u,"B1313 actor +118 vtable target");
    need(m.r32(actor_vt+0x1b0u)==0x005ccea0u,"B1313 actor height slot target");
    const U type=m.r32(actor+0x5acu);need(type,"B1313 actor type pointer");
    U radius=m.r32(type+0x530u);const U height=height_at_actor(m,state,actor);
    if(height==0u)radius=1u;need(radius==2u,"B1313 nonzero corrected height keeps type radius 2");
    need((arg0&255u)==0u,"B1313 callback arg3 low-byte route");
    const U house=m.r32(actor+0x1b4u),point=actor+0x88u;
    visibility_pass(m,state,point,radius,house,0u);
    visibility_pass(m,state,point,radius,house,1u);
    (void)arg1; // Original 41a530 forwards caller arg1 as helper arg4; this route does not read it.
}
}

std::uint32_t fun_0049de40(Memory& m,const Inputs& input){
    Inputs state=input;const U count=m.r32(actor_count),array=m.r32(actor_globals);
    need(count==1u&&array,"B1313 one-entry original global actor registry");
    const U actor=m.r32(array);need(actor,"B1313 nonnull registry member");
    if((m.r8(actor+0x14u)&1u)!=0u){
        need(m.r32(actor)==actor_vt&&m.r32(actor_vt+0x2cu)==0x0041b580u,"B1313 actor kind vtable slot");
        const U kind=2u; // 0x41b580 is MOV EAX,2; RET.
        if(kind==6u&&(input.arg[0]&255u)!=0u)return count;
        const U owner=m.r32(actor+0x1b4u);
        need(owner,"B1313 real owner pointer");
        const bool owner_visible=m.r32(0x00a255c8u)!=0u ? owner==m.r32(0x00a1e0e4u) : (m.r8(owner+0x134u)!=0u||m.r8(owner+0x135u)!=0u);
        if(owner_visible&&m.r8(actor+0x373u)!=0u)actor_update(m,state,actor,0u,input.arg[1]); // 49DE98 PUSH EDI; 49DE99 PUSH 0.
    }
    input.fp=state.fp;return m.r32(actor_count);
}
}
