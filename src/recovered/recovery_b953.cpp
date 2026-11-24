#include "recovered/recovery_b953.hpp"
#include "platform/observed_window953.hpp"
#include <algorithm>
namespace ra2::recovered::b953 {
std::uint32_t fun_0072bc40(Memory&m,const Inputs&i){namespace api=ra2::platform::window_api_b953;auto target=reinterpret_cast<HWND>(std::uintptr_t(i.cx)),reference=reinterpret_cast<HWND>(std::uintptr_t(i.dx));RECT rr{},tr{};api::get_client_rect(reference,&rr);if(m.r32(0xb0de50)==i.dx){rr.right=LONG(m.r32(0x83a710));rr.bottom=LONG(m.r32(0x83a714));}POINT rl{rr.left,rr.top},rb{rr.right,rr.bottom};api::client_to_screen(reference,&rl);api::client_to_screen(reference,&rb);api::get_client_rect(target,&tr);POINT tl{tr.left,tr.top},tb{tr.right,tr.bottom};api::client_to_screen(target,&tl);api::client_to_screen(target,&tb);auto x=std::max<LONG>(0,((rb.x-rl.x)-(tb.x-tl.x)+1)/2),y=std::max<LONG>(0,((rb.y-rl.y)-(tb.y-tl.y)+1)/2);return std::uint32_t(api::set_window_pos(target,nullptr,x,y,-1,-1,5));}
}
