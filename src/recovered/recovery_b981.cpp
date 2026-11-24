#include "recovery_b981.hpp"
#include "platform/observed_window_b981.hpp"

#include <cstdint>
#include <stdexcept>
namespace ra2::recovered::b981 {
static std::int32_t s32(std::uint32_t v){return static_cast<std::int32_t>(v);}static std::int32_t half0(std::int32_t v){return v/2;}static std::int32_t positive_half(std::int32_t v){auto q=half0(v);return q>0?q:0;}
std::uint32_t fun_005e1150(Memory&m,const Inputs&i){HWND target=reinterpret_cast<HWND>(std::uintptr_t(i.cx));HWND parent=ra2::platform::window_api_b981::get_parent(target);const bool flag=m.r8(0xa27f64u)!=0;if(m.r32(0xa5b1b8u)!=0x5d6fc0u||m.r32(0xa5b1acu)!=7u||!m.r32(0xa5b1a4u))throw std::domain_error("981 originalpositivehashcontract");RECT pr{},tr{};ra2::platform::window_api_b981::get_window_rect(parent,&pr);ra2::platform::window_api_b981::get_window_rect(target,&tr);
 const std::int32_t pw=pr.right-pr.left,ph=pr.bottom-pr.top,tw=tr.right-tr.left,th=tr.bottom-tr.top;
 const std::int32_t xpad=flag?0:positive_half(pw-s32(m.r32(0x00798c00u)));
 std::int32_t yadj=0;if(!flag){const std::int32_t step=s32(m.r32(0x00798c0cu));const std::int32_t requested=s32(m.r32(i.dx+4u));yadj=positive_half(ph-step)-positive_half(requested-step);}
 const std::uint32_t buckets=m.r32(0x00a5b1a0u);const std::uint32_t idx=i.cx&((1u<<m.r32(0x00a5b1acu))-1u);std::uint32_t node=m.r32(buckets+idx*4u);while(node&&m.r32(node)!=i.cx)node=m.r32(node+0x204u);if(!node)throw std::runtime_error("B981 fixture must provide authentic positive HWND record");
 std::int32_t off=s32(m.r32(node+0xe0u));if(!off)off=(s32(m.r32(0x00798c14u))-tw)/2;
 const std::int32_t x=pw-off-tw-xpad;const std::int32_t y=(tr.top-pr.top)+yadj;
 return std::uint32_t(ra2::platform::window_api_b981::move_window(target,x,y,tw,th,FALSE));}
}
