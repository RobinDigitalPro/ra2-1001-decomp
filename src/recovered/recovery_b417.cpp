#include "recovery_b417.hpp"
#include "recovered/allocation_wrappers.hpp"
#include <cstdint>
#include <stdexcept>

namespace ra2::recovery_b417 {
namespace {
void need(bool ok, const char* why) { if (!ok) throw std::domain_error(why); }
std::int32_t s16(const Memory& m, std::uint32_t p) { return static_cast<std::int16_t>(m.r16(p)); }
struct Rect { std::uint32_t x, y, w, h; };
std::uint32_t allocate16(std::uint32_t n, std::uint32_t flag, void* ctx) {
    if (n != 16u || flag != 1u) throw std::domain_error("B417 requires request-16/flag-1 allocations");
    return static_cast<Heap*>(ctx)->allocate(n);
}
Rect make(Memory& m, Heap& heap, const ra2::recovered::AllocationWrapperOperations& ops,
          std::uint32_t slot, std::uint32_t x, std::uint32_t y, std::int32_t w, std::int32_t h) {
    need(w > 0 && h > 0, "B417 finite route requires positive signed source dimensions");
    const auto p = ra2::recovered::fun_0076d957(16u, ops);
    need(p != 0u, "B417 selected route excludes allocation failure");
    Rect r{x, y, static_cast<std::uint32_t>(w), static_cast<std::uint32_t>(h)};
    heap.w32(p, r.x); heap.w32(p+4u, r.y); heap.w32(p+8u, r.w); heap.w32(p+12u, r.h);
    m.w32(slot, p);
    return r;
}
}

std::uint32_t fun_006e9c80(Memory& m, const ra2::recovered::global_b26::Inputs& in, Heap& heap) {
    const std::int32_t cx = static_cast<std::int32_t>(in.cx), dx = static_cast<std::int32_t>(in.dx);
    const auto mode = m.r32(0x0083a710u);
    const auto first = mode == 0x280u ? m.r32(0x00aa8b7cu) :
                       mode == 0x320u ? m.r32(0x00aa8b74u) : m.r32(0x00aa8b38u);
    const auto fw = s16(m, first+2u), fh = s16(m, first+4u);
    need(fw > 0 && fh > 0, "B417 first selected dimensions must be positive");
    const ra2::recovered::AllocationWrapperOperations ops{allocate16, nullptr, &heap};
    const Rect r1 = make(m,heap,ops,0x00aa8c64u,0u,0u,fw,fh);
    (void)r1;
    const auto p2=m.r32(0x00aa8b9cu); const auto w2=s16(m,p2+2u),h2=s16(m,p2+4u);
    const Rect r2=make(m,heap,ops,0x00aa8c68u,static_cast<std::uint32_t>(cx-w2),0u,w2,h2);
    const auto p3=m.r32(0x00aa8af8u); const auto h3=s16(m,p3+4u);
    const Rect r3=make(m,heap,ops,0x00aa8c6cu,static_cast<std::uint32_t>(cx-w2),static_cast<std::uint32_t>(h2),w2,h3);
    const auto p4=m.r32(0x00aa8b40u); const auto h4=s16(m,p4+4u);
    const Rect r4=make(m,heap,ops,0x00aa8c70u,r3.x,r3.y+r3.h,w2,h4);
    const auto p5=m.r32(0x00aa8b48u); const auto h5=s16(m,p5+4u);
    const Rect r5=make(m,heap,ops,0x00aa8c78u,r4.x,r4.y+r4.h,w2,h5);
    const auto p6=m.r32(0x00aa8b90u); const auto h6=s16(m,p6+4u);
    const Rect r6=make(m,heap,ops,0x00aa8c7cu,r5.x,r5.y+r5.h,w2,h6);
    const auto p7=m.r32(0x00aa8b54u); const auto h7=s16(m,p7+4u);
    const Rect r7=make(m,heap,ops,0x00aa8c80u,r6.x,r6.y+r6.h,w2,h7);
    const auto p8=m.r32(0x00aa8b34u); const auto h8=s16(m,p8+4u);
    const Rect r8=make(m,heap,ops,0x00aa8c84u,r7.x,r7.y+r7.h,w2,h8);

    const std::int64_t qnum=std::int64_t(dx)-r7.h-r5.h-r4.h-r3.h-r2.h;
    need(r6.h>0 && qnum/r6.h>=INT32_MIN && qnum/r6.h<=INT32_MAX,"B417 first geometry IDIV in bounded range");
    const auto q1=static_cast<std::int32_t>(qnum/r6.h); m.w32(0x00aa8b84u,static_cast<std::uint32_t>(q1));
    const auto y7=std::uint32_t(std::int32_t(r6.y)+q1*std::int32_t(r6.h));
    // Original stores the computed y to the seventh publication, then rewrites
    // the eighth y from the seventh y plus the seventh height.
    heap.w32(m.r32(0x00aa8c80u)+4u,y7);
    heap.w32(m.r32(0x00aa8c84u)+4u,static_cast<std::uint32_t>(y7+h7));

    const auto a=m.r32(0x00821980u),b=m.r32(0x00821984u),c=m.r32(0x00821988u),d=m.r32(0x0082198cu);
    (void)a;(void)b;(void)d;
    const auto base_y=static_cast<std::uint32_t>(dx-32);
    const auto r9=make(m,heap,ops,0x00aa8c8cu,0u,base_y,static_cast<std::int32_t>(c)-0xa8,0x20);
    const auto p10=m.r32(0x00aa8b30u); const auto w10=s16(m,p10+2u),h10=s16(m,p10+4u);
    const auto r10=make(m,heap,ops,0x00aa8c90u,0u,base_y,w10,h10);
    const auto p11=m.r32(0x00aa8b58u); const auto w11=s16(m,p11+2u),h11=s16(m,p11+4u);
    auto r11=make(m,heap,ops,0x00aa8c94u,0u,base_y,w11,h11);
    const auto r12=make(m,heap,ops,0x00aa8c98u,0u,base_y,w11,h11);
    const auto p13=m.r32(0x00aa8b64u); const auto w13=s16(m,p13+2u),h13=s16(m,p13+4u);
    auto r13=make(m,heap,ops,0x00aa8c9cu,0u,base_y,w13,h13);
    const auto p14=m.r32(0x00aa8b68u); const auto w14=s16(m,p14+2u),h14=s16(m,p14+4u);
    auto r14=make(m,heap,ops,0x00aa8ca0u,0u,base_y,w14,h14);
    need(w13>0,"B417 second geometry IDIV divisor must be positive");
    const auto q2=static_cast<std::int32_t>((std::int64_t(cx)-r11.w-r2.w-r14.w)/w13);
    m.w32(0x00aa8afcu,static_cast<std::uint32_t>(q2));
    const auto x14=std::uint32_t(std::int32_t(r2.x)-std::int32_t(r14.w));
    const auto x13=std::uint32_t(std::int32_t(x14)-q2*std::int32_t(r13.w));
    const auto x11=std::uint32_t(std::int32_t(x13)-std::int32_t(r11.w));
    r14.x=x14; r13.x=x13; r11.x=x11;
    heap.w32(m.r32(0x00aa8ca0u),x14);
    heap.w32(m.r32(0x00aa8c9cu),x13);
    heap.w32(m.r32(0x00aa8c94u),x11);
    m.w32(0x00aa8b80u,x11);
    const auto x12=std::uint32_t(std::int32_t(x14)-std::int32_t(r12.w));
    heap.w32(m.r32(0x00aa8c98u),x12); m.w32(0x00aa8b60u,x12);
    const auto source=m.r32(0x00aa8c6cu);
    m.w32(0x00aa8b50u,std::uint32_t(std::int32_t(r14.x)-std::int32_t(r11.w)-std::int32_t(r11.x)));
    const auto final=make(m,heap,ops,0x00aa8c74u,
      heap.r32(source), heap.r32(source+4u),
      static_cast<std::int32_t>(heap.r32(source+8u)),
      static_cast<std::int32_t>(heap.r32(m.r32(0x00aa8c70u)+12u)+heap.r32(source+12u)));
    (void)r9;(void)r10;(void)r12;(void)r13;(void)r14;(void)final;

    const auto qheight=static_cast<std::int32_t>(q1*std::int32_t(h6)+std::int32_t(h7)+std::int32_t(h5));
    const auto ret=make(m,heap,ops,0x00aa8c88u,r5.x,r5.y,r5.w,qheight);
    return m.r32(0x00aa8c88u);
}

namespace {
std::uint32_t release_null_cb(std::uint32_t p,void*){if(p)throw std::domain_error("B417 excludes nonnull old slot");return 0;}
}
std::uint32_t fun_006e83a0(Memory&m,const ra2::recovered::global_b26::Inputs&i,Heap&heap){
    constexpr std::uint32_t slots[]{0xaa8c44u,0xaa8c48u,0xaa8c4cu,0xaa8c50u,0xaa8c54u,0xaa8c58u,0xaa8c5cu,0xaa8c60u};
    for(auto p:slots)if(m.r32(p)!=0u)throw std::domain_error("B417 2e83a0 only composes the original null-release route");
    const ra2::recovered::AllocationWrapperOperations ops{nullptr,release_null_cb,nullptr};
    for(auto p:slots){(void)ra2::recovered::fun_0076d67b(m.r32(p),ops);m.w32(p,0u);}
    return ra2::recovery_b406::fun_006e8e60(m,i,heap);
}
} // namespace ra2::recovery_b417
