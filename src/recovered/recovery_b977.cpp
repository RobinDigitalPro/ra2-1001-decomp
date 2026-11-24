#include "recovery_b977.hpp"
#include "platform/observed_window_b977.hpp"

#include <cstdint>
#include <stdexcept>
namespace ra2::recovered::b977 {
static std::int32_t s32(std::uint32_t v){return static_cast<std::int32_t>(v);}
static std::uint32_t run(Memory&m,const Inputs&i,bool row_y){
 HWND target=reinterpret_cast<HWND>(std::uintptr_t(i.cx)); HWND parent=ra2::platform::window_api_b977::get_parent(target);
 const std::uint8_t flag=std::uint8_t(m.r8(0xa27f64u));if(m.r32(0xa5b1b8u)!=0x5d6fc0u||m.r32(0xa5b1acu)!=7u||!m.r32(0xa5b1a4u))throw std::domain_error("977 exact original positive hash contract");
 RECT cr{},wr{};ra2::platform::window_api_b977::get_client_rect(parent,&cr);ra2::platform::window_api_b977::get_window_rect(target,&wr);
 const std::int32_t clientw=cr.right-cr.left,tw=wr.right-wr.left,th=wr.bottom-wr.top;
 const std::uint32_t hwnd=std::uint32_t(reinterpret_cast<std::uintptr_t>(target));
 const std::uint32_t bucket=hwnd&((1u<<m.r32(0x00a5b1acu))-1u);
 const std::uint32_t bucket_array=m.r32(0x00a5b1a0u);std::uint32_t node=m.r32(bucket_array+bucket*4u);
 while(node&&m.r32(node)!=hwnd)node=m.r32(node+0x204u);
 if(!node)throw std::runtime_error("B977 fixture must contain an original-hash positive HWND record");
 const std::int32_t override_x=s32(m.r32(node+0xe0u));
 std::int32_t pad=0;if(!flag){const std::int32_t d=clientw-s32(m.r32(0x00798c00u));pad=d/2;if(pad<0)pad=0;}
 std::int32_t off=override_x;if(!off){const std::int32_t d=s32(m.r32(0x00798c14u))-tw;off=d/2;}
 const std::int32_t x=clientw-off-tw-pad;
 std::uint32_t p=m.r32(flag?0x00aa8c84u:0x00aa8c5cu);
 std::int32_t y=s32(m.r32(p+4u));if(row_y)y+=s32(m.r32(p+0xcu));y-=th;
 return std::uint32_t(ra2::platform::window_api_b977::move_window(target,x,y,tw,th,FALSE));
}
std::uint32_t fun_005e13a0(Memory&m,const Inputs&i){return run(m,i,false);} std::uint32_t fun_005e15a0(Memory&m,const Inputs&i){return run(m,i,true);}
}
