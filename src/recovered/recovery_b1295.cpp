#include "recovery_b1295.hpp"
#include "recovered/map_b98.hpp"
#include "recovered/recovery_b108.hpp"
#include "recovered/recovery_b522.hpp"
#include "recovered/numeric_b88_detail.hpp"
#include <array>
#include <cmath>
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::b1295 {
using namespace floating_b61;
namespace {
constexpr std::uint32_t map=0x81a820u, table=0x81a958u;
constexpr std::uint32_t scratch=0x7d200000u, root_scratch=0x7d300000u;
void need(bool b,const char* why){if(!b)throw std::domain_error(why);}
// 25A130 is a leaf-ABI helper. Its 20 original bytes are translated directly:
// output receives [scenario + index*4 + 0x632].
std::uint32_t scenario_coord(Memory&m,std::uint32_t out,std::uint32_t scenario,std::uint32_t index){
    const auto p=m.r32(scenario+0x632u+index*4u);m.w32(out,p);return out;
}
void cursor_init(Memory&m,std::uint32_t x,std::uint32_t y){
    // Exact 157840 assignments, four original loads and two stores.
    const auto x0=m.r32(map+0xf8u), x1=m.r32(map+0xfcu);
    const auto y0=m.r32(map+0xf0u), y1=m.r32(map+0xf8u);
    m.w32(map+0x118u,x0+x1+1u);m.w32(map+0x11cu,y0-y1+x1);
    (void)x;(void)y;
}
std::uint32_t zone(Memory&m,std::uint32_t coord){
    Inputs z{};z.cx=map;z.arg[0]=coord;z.arg[1]=1u;z.arg[2]=0u;
    return recovery_b108::fun_0054cd80(m,z);
}
void update_99da0(Memory& original,std::int32_t x,std::int32_t y,std::uint32_t house,std::uint32_t mode,Inputs& parent){
    // 227330's reached route forwards these three values to accepted 499DA0.
    // Its local point and the helper frame occupy distinct emulated stack ranges.
    std::array<std::uint8_t,0x4000> bytes{};
    leaf::Memory local(bytes.data(),scratch,static_cast<std::uint32_t>(bytes.size()));
    Memory m=original;m.add(local);
    const auto point=scratch+0x1000u;
    m.w16(point,std::uint32_t(x));m.w16(point+2u,std::uint32_t(y));m.w32(point+4u,0u);
    Inputs u{};u.cx=map;u.arg[0]=point;u.arg[1]=house;u.arg[2]=mode;
    u.fp=parent.fp;
    recovery_b522::fun_00499da0(m,u);parent.fp=u.fp;
    // Copy back writes on original declared spans; local stack is intentionally ephemeral.
    // Accepted Memory forwarding means mutations to shared spans are already visible.
}
std::uint32_t reveal_route(Memory&m,Inputs&root,std::uint32_t point,std::uint32_t radius,std::uint32_t house,std::uint32_t mode){
    need(radius==2u&&house!=0u&&house==m.r32(0xa1e0e4u),"1295 selected bounded radius/house route");
    const auto x=std::int32_t(numeric_b88::detail::div256(m.r32(point)));
    const auto y=std::int32_t(numeric_b88::detail::div256(m.r32(point+4u)));
    const auto width=std::int32_t(m.r32(map+0xf0u)),height=std::int32_t(m.r32(map+0xf4u));
    const auto count=m.r32(0x7908e8u+radius*4u);need(count==21u,"1295 radius-2 offset cardinality");
    const auto renderer=m.r32(0x821b88u);need(renderer&&m.r8(renderer+0x1432u)==0u,"1295 optional nested route skipped by original renderer byte");
    const auto z=m.r32(point+8u);
    root.fp.load_integer32(z);root.fp.multiply64(read64(m,0xaa5f90u));ra2::platform::x87_extended::add_integer32(root.fp,s32(z)>=728?1u:0u);root.fp.add64(read64(m,0x785728u));need(numeric_b88::detail::integer(m,root.fp)==0u,"1295 zero projected height");
    root.fp.load_integer32(z);root.fp.multiply64(read64(m,0xaa5f90u));ra2::platform::x87_extended::add_integer32(root.fp,s32(z)>=728?1u:0u);root.fp.add64(read64(m,0x785728u));need(numeric_b88::detail::integer(m,root.fp)==0u,"1295 second zero projected height");
    for(std::uint32_t k=0;k<count;++k){
        const auto packed=m.r32(0xa56e68u+4u*k);
        const auto dx=std::int32_t(std::int16_t(packed)),dy=std::int32_t(std::int16_t(packed>>16u));
        const auto xx=x+dx,yy=y+dy;
        need(xx+yy>width&&xx-yy<width&&yy-xx<width&&xx+yy<=width+2*height,"1295 original diagonal map bounds");
        root.fp.load_integer32(std::uint32_t(dy));root.fp.load_integer32(std::uint32_t(dx));root.fp.load_st0();numeric_b88::detail::reg<0xd8c9>(root.fp);root.fp.load_st2();numeric_b88::detail::reg<0xd8cb>(root.fp);root.fp.add_pop();const auto square=root.fp.pop64();root.fp.pop_st0();root.fp.pop_st0();numeric_b88::detail::root(m,root.fp,square);const auto distance=std::int32_t(std::int16_t(numeric_b88::detail::integer(m,root.fp)));need(distance<=int(radius),"1295 original radius distance");
        const auto index=std::uint32_t(512*yy+xx);need(index<0x40000u,"1295 map cell index");
        const auto cell=m.r32(m.r32(map+0x138u)+index*4u);need(cell,"1295 populated radius cell");
        const auto flags=m.r32(cell+0x140u);
        m.w32(cell+0x140u,flags&~0x40u);
        // Root's arg5=0 path calls 227330 -> 499DA0. Use the real accepted
        // implementation on this actual coordinate; no callback is substituted.
        update_99da0(m,xx,yy,house,mode,root);
    }
    return 0u;
}
}
std::uint32_t fun_002a5e90(Memory&m,const Inputs&i){
    std::array<std::uint8_t,0x4000> root_bytes{};
    leaf::Memory root_local(root_bytes.data(),root_scratch,std::uint32_t(root_bytes.size()));
    Memory work=m;work.add(root_local);Inputs state=i;
    need(work.r32(0xa1e0e4u)!=0u&&work.r32(work.r32(0xa1e0e4u)+0x188u)==0u,"1295 current-house gate");
    need(work.r32(i.cx+0x74u)==0u,"1295 root index is zero");
    const auto out=root_scratch+0x2000u;
    const auto scenario=work.r32(0xa255c0u);need(scenario,"1295 scenario table");
    const auto coord=scenario_coord(work,out,scenario,work.r32(i.cx+0x74u));
    need(coord,"1295 nonnull scenario coordinate");
    const auto scenario_zone=zone(work,coord);
    cursor_init(work,0,0);
    Inputs it{};it.cx=map;it.fp=state.fp;
    auto cell=map_b98::fun_00557700(work,it);state.fp=it.fp;
    while(cell){
        const auto cell_coord=cell+0x24u;
        if(zone(work,cell_coord)==scenario_zone){
            const auto level=std::int32_t(std::int8_t(work.r8(cell+0x11bu)));
            need(level==0,"1295 original level-zero projection");
            const auto subtract=0;
            const auto center=root_scratch+0x2100u;
            const auto cx=std::int32_t(work.r16(cell_coord))-subtract;
            const auto cy=std::int32_t(work.r16(cell_coord+2u))-subtract;
            work.w32(center,std::uint32_t(cx*256+128));work.w32(center+4u,std::uint32_t(cy*256+128));work.w32(center+8u,0u);
            const auto house=work.r32(0xa1e0e4u);
            reveal_route(work,state,center,2u,house,0u);
            reveal_route(work,state,center,2u,house,1u);
        }
        it.fp=state.fp;
        cell=map_b98::fun_00557700(work,it);state.fp=it.fp;
    }
    i.fp=state.fp;
    return 1u;
}
}



