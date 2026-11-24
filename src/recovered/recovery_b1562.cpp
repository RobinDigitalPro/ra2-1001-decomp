#include "recovered/recovery_b1562.hpp"
#include "recovered/recovery_b439.hpp"
#include <cstdint>
#include <stdexcept>
namespace ra2::recovered::recovery_b1562 {
namespace {
using U=std::uint32_t;
[[noreturn]] void out_of_scope(const char*why){throw std::domain_error(why);}
U map_lookup(Memory&m,U xraw,U yraw){
    // Exact accepted 0x145490 positive path: signed 8.8 coordinates,
    // 512-wide linear table, and the live cell pointer at the computed index.
    const auto x=static_cast<std::int32_t>(xraw)/256;
    const auto y=static_cast<std::int32_t>(yraw)/256;
    if(x<0||y<0)out_of_scope("B1562 finite route requires nonnegative map coordinate");
    const U index=(static_cast<U>(y)<<9u)+static_cast<U>(x);
    const U map=0x81a820u;
    const U count=m.r32(map+0x13cu);
    if(index>=count)out_of_scope("B1562 map index outside accepted 145490 table");
    const U table=m.r32(map+0x138u);
    const U cell=m.r32(table+index*4u);
    if(!cell)out_of_scope("B1562 fixture requires a populated 145490 cell");
    return cell;
}
U owner_position(Memory&m,U owner){
    // 0x1CD870 reads all three owner coordinates for both exact 0x545490
    // calls; the accepted map helper consumes the first two 8.8 DWORDs.
    const U x1=m.r32(owner+0x88u),y1=m.r32(owner+0x8cu);(void)m.r32(owner+0x90u);
    (void)map_lookup(m,x1,y1);
    const U x2=m.r32(owner+0x88u),y2=m.r32(owner+0x8cu);(void)m.r32(owner+0x90u);
    return map_lookup(m,x2,y2);
}
U building_numeric(Memory&m,U owner,U input){
    // Complete 256-byte-window branch graph at original 0x451E90:
    // mode bit 2 clear passes through; set selects +500 or -500.
    if((m.r32(owner+0xd8u)&2u)==0u)return input;
    return static_cast<std::int32_t>(input)<=0x5dc ? input+0x1f4u : input-0x1f4u;
}
bool building_timer(Memory&m,U owner){
    const U start=m.r32(owner+0x154u);const U duration=m.r32(owner+0x15cu);
    if(start!=0xffffffffu)out_of_scope("B1562 finite route requires the exact timer sentinel");
    // Exact 0x41b390 sentinel branch: JZ reaches TEST EAX/SETG; AL is signed-duration>0.
    return static_cast<std::int32_t>(duration)>0;
}
}
U run(Memory&m,const Inputs&i){
    const U owner=i.cx;
    if(m.r32(owner)!=0x00787bbcu)out_of_scope("B1562 public route requires pinned Building vptr 787BBC");
    // Reuse the accepted B439 property-list method: Building+418 getter,
    // owner+1B4 -> owner+15F40 index, property+B8C list+4 -> row+30C.
    const U selected=ra2::recovered::recovery_b439::fun_006c69f0(m,i);
    const U cell=owner_position(m,owner);
    const U sample=static_cast<U>(static_cast<std::int32_t>(static_cast<std::int16_t>(m.r16(cell+0x10au))));
    const U value=building_numeric(m,owner,sample);
    if(building_timer(m,owner))out_of_scope("B1562 selected route must bypass timer-dependent 2CDC60");
    m.w16(owner+0x5c4u,static_cast<std::uint16_t>(value));
    const auto mode=static_cast<std::int8_t>(m.r8(owner+0x5bdu));
    if(mode==15)out_of_scope("B1562 public route chooses mode 3 and bypasses main +64 callback");
    for(U n=0;n<18u;++n){
        const U child=m.r32(owner+0x454u+4u*n);if(!child)continue;
        const U attachment=m.r32(child+0xb0u);if(!attachment)continue;
        if(m.r8(attachment+0x318u)==0u)continue;
        m.w32(child+0xbcu,selected);m.w32(child+0xe4u,value&0xffffu);
    }
    U eax=0u;
    for(U n=0;n<18u;++n){const U child=m.r32(owner+0x454u+4u*n);eax=child;if(child)m.w8(child+0x158u,static_cast<U>(static_cast<std::uint8_t>(mode)));}
    return eax; // root RET 0 leaves final slot-17 pointer in EAX
}
}
