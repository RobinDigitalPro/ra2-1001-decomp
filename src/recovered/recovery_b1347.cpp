#include "recovery_b1347.hpp"
#include "recovered/numeric_b88_detail.hpp"
#include "recovered/map_b106.hpp"
#include "recovered/recovery_b522.hpp"
#include "recovered/leaf_memory.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1347 {
namespace {
using U=std::uint32_t;
using namespace numeric_b88::detail;
constexpr U map=0x0081a820u,vt=0x0078612cu;
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
U terrain_height(Memory&m,Inputs&state,U actor){
    const U x=m.r32(actor+0x88u),y=m.r32(actor+0x8cu),ix=div256(x),iy=div256(y),index=iy*512u+ix;
    const U table=m.r32(0x81a958u);need(index<m.r32(0x81a95cu)&&table,"1347 actual557070 in-range lookup");
    const U cell=m.r32(table+index*4u);need(cell,"1347 populated terrain cell");
    constexpr U scratch=0x7d100000u;std::array<std::uint8_t,8>bytes{};
    leaf::Memory span(bytes.data(),scratch,8u);Memory view=m;view.add(span);view.w32(scratch,x);view.w32(scratch+4u,y);
    map_b106::Inputs h{};h.ax=iy;h.cx=cell;h.dx=scratch;h.arg[0]=scratch;h.arithmetic_flags=0x202u;h.fp=state.fp;
    const U result=map_b106::fun_004702c0(view,h);state.fp=h.fp;return result;
}
void cell_update(Memory&m,Inputs&state,int x,int y,U house,U mode){
    constexpr U scratch=0x7d200000u,point=scratch+0x1000u;
    std::array<std::uint8_t,0x4000>bytes{};leaf::Memory span(bytes.data(),scratch,U(bytes.size()));Memory view=m;view.add(span);
    view.w16(point,U(x));view.w16(point+2u,U(y));view.w32(point+4u,0u);
    recovery_b522::Inputs u{};u.cx=map;u.arg[0]=point;u.arg[1]=house;u.arg[2]=mode;u.fp=state.fp;
    (void)recovery_b522::fun_00499da0(view,u);state.fp=u.fp;
}
void reveal_pass(Memory&m,Inputs&state,U actor,U house,U mode){
    need(house==m.r32(0xa1e0e4u)&&m.r8(m.r32(0x821b88u)+0x1432u)==0u,"1347 currenthouse/renderer route");
    const U z=m.r32(actor+0x90u);
    for(unsigned q=0;q<2u;++q){state.fp.load_integer32(z);state.fp.multiply64(read64(m,0xaa5f90u));
        fp_extended::add_integer32(state.fp,s32(z)>=728?1u:0u);state.fp.add64(read64(m,0x785728u));
        need(integer(m,state.fp)==0u,"1347 real projected-height predicate");}
    const int center_x=s32(div256(m.r32(actor+0x88u))),center_y=s32(div256(m.r32(actor+0x8cu)));
    const int width=s32(m.r32(map+0xf0u)),height=s32(m.r32(map+0xf4u));
    need(m.r32(0x7908f0u)==21u,"1347 original radius2 offset cardinality");
    for(U k=0;k<21u;++k){
        const U packed=m.r32(0xa56e68u+k*4u);const int dx=std::int16_t(packed),dy=std::int16_t(packed>>16u),x=center_x+dx,y=center_y+dy;
        need(x+y>width&&x-y<width&&y-x<width&&x+y<=width+2*height,"1347 actual diagonal bounds");
        state.fp.load_integer32(U(dy));state.fp.load_integer32(U(dx));reg<0xd9c0>(state.fp);reg<0xd8c9>(state.fp);
        reg<0xd9c2>(state.fp);reg<0xd8cb>(state.fp);state.fp.add_pop();const auto sq=state.fp.pop64();state.fp.pop_st0();state.fp.pop_st0();
        root(m,state.fp,sq);need(std::int16_t(integer(m,state.fp))<=2,"1347 actual LUT radius test");
        const U index=U(512*y+x);need(index<0x40000u,"1347 populated radius index");
        const U cell=m.r32(m.r32(map+0x138u)+4u*index);need(cell,"1347 real cell");
        m.w32(cell+0x140u,m.r32(cell+0x140u)&~0x40u);cell_update(m,state,x,y,house,mode);
    }
}
void actual_41a530(Memory&m,Inputs&state,U actor,U type){
    need(m.r32(vt+0x118u)==0x41a530u&&m.r32(vt+0x1b0u)==0x5ccea0u,"1347 actual visibility/height slots");
    U radius=m.r32(type+0x530u);U height=m.r32(actor+0x90u)-terrain_height(m,state,actor);
    if(m.r8(actor+0x79u))height-=m.r32(0xa5aa98u);
    if(height==0u)radius=1u;need(radius==2u,"1347 corrected nonzero height retains radius2");
    // Original root pushes two zero words. Provider produces XYZ for each
    // pass; helperarg3/4 zero, mode0 then1; no outer callerword forwarding.
    const U house=m.r32(actor+0x1b4u);reveal_pass(m,state,actor,house,0u);reveal_pass(m,state,actor,house,1u);
}
}
U fun_0049df00(Memory&m,const Inputs&i){
    using namespace numeric_b88::detail;Inputs state=i;
    need(m.r32(0x83a8e8u)==1u,"1347 one actual registry entry");
    const U actor=m.r32(m.r32(0x83a8dcu));need(m.r32(actor)==vt,"1347 original actor vptr");
    need(m.r32(vt+0x2cu)==0x41b580u,"1347 actual kind2 provider and40DC20 readonly switch");
    // Actual40DC20 selector[2-1]=0 routes to40DC41 returning actor.
    const U house=m.r32(actor+0x1b4u);
    const bool visible=m.r32(0xa255c8u)?house==m.r32(0xa1e0e4u):(m.r8(house+0x134u)||m.r8(house+0x135u));
    need(visible&&m.r8(actor+0x373u),"1347 actual positive owner/373 gates");
    need(m.r32(vt+0x48u)==0x5cd4d0u&&m.r32(vt+0x80u)==0x6b6910u&&m.r32(vt+0x84u)==0x41b600u,"1347 actual coordinate/type providers");
    const U p=i.arg[0],dx=m.r32(p)-m.r32(actor+0x88u),dy=m.r32(p+4u)-m.r32(actor+0x8cu),dz=m.r32(p+8u)-m.r32(actor+0x90u);
    need(dx==4u&&dy==0u&&dz==0u&&i.arg[1]==0u,"1347 bounded positive distance4 andzero radius expansion");
    need(state.fp.image.word(8)==0xffffu&&((state.fp.image.word(4)>>11)&7u)==0u,"1347 emptyTOP0 entry");
    auto&f=state.fp;f.load_integer32(dz);f.load_integer32(dy);f.load_integer32(dx);
    reg<0xd9c0>(f);reg<0xd8c9>(f);reg<0xd9c2>(f);reg<0xd8cb>(f);f.add_pop();reg<0xd9c3>(f);reg<0xd8cc>(f);f.add_pop();
    const auto square=f.pop64();f.pop_st0();f.pop_st0();f.pop_st0();root(m,f,square);const U distance=integer(m,f);
    const U type=m.r32(actor+0x5acu);need(distance==4u&&s32(distance)<=s32((m.r32(type+0x530u)<<8u)+i.arg[1]),"1347 actual positive distance threshold");
    actual_41a530(m,state,actor,type);i.fp=state.fp;return 1u;
}
}
