#include "recovery_b406.hpp"
#include "recovered/allocation_wrappers.hpp"
#include <array>
#include <cstdint>
#include <stdexcept>

namespace ra2::recovery_b406 {
namespace {
void need(bool ok,const char* why){if(!ok)throw std::domain_error(why);}
std::int32_t s16(const Memory&m,std::uint32_t p){return static_cast<std::int16_t>(m.r16(p));}
std::uint32_t allocate16(std::uint32_t n,std::uint32_t flag,void* context){
    if(n!=16u||flag!=1u)throw std::domain_error("B406 original wrapper call contract is request16/flag1");
    return static_cast<Heap*>(context)->allocate(n);
}
struct Rect {std::uint32_t x,y,w,h;};
Rect make_rect(Memory&m,const ra2::recovered::AllocationWrapperOperations&ops,Heap&heap,
               std::uint32_t slot,std::uint32_t x,std::uint32_t y,
               std::int32_t w,std::int32_t h){
    if(w<=0||h<=0){throw std::domain_error("B406 nonpositive rectangle at slot "+std::to_string(slot)+" w="+std::to_string(w)+" h="+std::to_string(h));}
    const auto p=ra2::recovered::fun_0076d957(16u,ops);
    need(p!=0u,"B406 selected route excludes any operator-new failure");
    Rect r{x,y,static_cast<std::uint32_t>(w),static_cast<std::uint32_t>(h)};
    heap.w32(p,r.x);heap.w32(p+4u,r.y);heap.w32(p+8u,r.w);heap.w32(p+12u,r.h);
    m.w32(slot,p);
    return r;
}
}

std::uint32_t fun_006e8e60(Memory&m,const ra2::recovered::global_b26::Inputs&i,Heap&heap){
    const auto W=static_cast<std::int32_t>(i.cx),H=static_cast<std::int32_t>(i.dx);
    need(W>=0x280&&H>=0x1e0,"B406 bounded route requires the selected positive source dimensions");
    const auto left=W>=0x400?(W-0x320)/2:0;
    const auto center_x=W-left;
    const auto top=H>=0x300?(H-0x258)/2:0;
    const auto center_y=H-top;
    const auto inner_h=H-2*top;
    const ra2::recovered::AllocationWrapperOperations ops{allocate16,nullptr,&heap};

    const bool special_w=W==0x280;
    const bool special_h=H==0x1e0;
    const auto width_source=special_w?0x00aa8bbcu:0x00aa8b0cu;
    const auto height_source=special_h?0x00aa8bbcu:0x00aa8b0cu;
    make_rect(m,ops,heap,0x00aa8c50u,static_cast<std::uint32_t>(left),
              static_cast<std::uint32_t>(top),s16(m,m.r32(width_source)+2u),s16(m,m.r32(height_source)+4u));

    const auto p2=m.r32(0x00aa8b8cu);
    const auto w2=s16(m,p2+2u),h2=s16(m,p2+4u);
    const auto r2=make_rect(m,ops,heap,0x00aa8c54u,static_cast<std::uint32_t>(center_x-w2),static_cast<std::uint32_t>(top),w2,h2);

    const auto p3=m.r32(0x00aa8b6cu);const auto h3=s16(m,p3+4u);
    make_rect(m,ops,heap,0x00aa8c4cu,static_cast<std::uint32_t>(center_x-w2),static_cast<std::uint32_t>(top),w2,h3);

    const auto p4=m.r32(0x00aa8b4cu);const auto h4=s16(m,p4+4u);
    const auto r4=make_rect(m,ops,heap,0x00aa8c58u,static_cast<std::uint32_t>(center_x-w2),
                            static_cast<std::uint32_t>(h2+top),w2,h4);

    const auto p5=m.r32(0x00aa8b70u);const auto w5=s16(m,p5+2u),h5=s16(m,p5+4u);
    make_rect(m,ops,heap,0x00aa8c44u,static_cast<std::uint32_t>(std::int32_t(r4.x)+std::int32_t(r4.w)-w5),
              r4.y,w5,h5);

    const auto p6=m.r32(0x00aa8af4u);const auto w6=s16(m,p6+2u),h6=s16(m,p6+4u);
    make_rect(m,ops,heap,0x00aa8c48u,static_cast<std::uint32_t>(center_x-w6),
              static_cast<std::uint32_t>(std::int32_t(r4.y)+std::int32_t(r4.h)-h6),w6,h6);

    const auto numerator=inner_h-static_cast<std::int32_t>(r2.h);
    need(r4.h!=0u,"B406 excludes original IDIV by zero");
    const auto quotient=numerator/static_cast<std::int32_t>(r4.h);
    m.w32(0x00aa8b24u,static_cast<std::uint32_t>(quotient));
    const auto y7=static_cast<std::int32_t>(r4.y)+quotient*static_cast<std::int32_t>(r4.h);
    const auto w7=s16(m,m.r32(0x00aa8b2cu)+2u);
    const auto h7=inner_h-(static_cast<std::int32_t>(r2.h)+quotient*static_cast<std::int32_t>(r4.h));
    make_rect(m,ops,heap,0x00aa8c5cu,static_cast<std::uint32_t>(center_x-w7),
              static_cast<std::uint32_t>(y7),w7,h7);

    const auto last_w_source=special_w?0x00aa8b88u:0x00aa8b3cu;
    const auto last_h_source=special_h?0x00aa8b88u:0x00aa8b3cu;
    const auto w8=s16(m,m.r32(last_w_source)+2u),h8=s16(m,m.r32(last_h_source)+4u);
    const auto last=make_rect(m,ops,heap,0x00aa8c60u,static_cast<std::uint32_t>(left),
                              static_cast<std::uint32_t>(center_y-h8),w8,h8);
    return m.r32(0x00aa8c60u);
}
} // namespace ra2::recovery_b406

