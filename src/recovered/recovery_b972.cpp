#include "recovery_b972.hpp"
#include "platform/observed_window972.hpp"
namespace ra2::recovered::b972 {
std::uint32_t fun_0072b050(Memory&m,const Inputs&i){
 const std::uint32_t x=i.cx&0xffffu,y=(i.cx>>16)&0xffffu;
 const HWND global_parent=reinterpret_cast<HWND>(std::uintptr_t(m.r32(0x00b0d9a8u)));
 const HWND search_parent=reinterpret_cast<HWND>(std::uintptr_t(ra2::platform::window_api_b972::get_window_long(global_parent,-8)));
 POINT point{static_cast<LONG>(x),static_cast<LONG>(y)};
 const HWND hit=ra2::platform::window_api_b972::child_window_from_point(search_parent,point);
 const HWND hit_parent=reinterpret_cast<HWND>(std::uintptr_t(ra2::platform::window_api_b972::get_window_long(hit,-8)));
 const HWND global_parent_parent=reinterpret_cast<HWND>(std::uintptr_t(ra2::platform::window_api_b972::get_window_long(global_parent,-8)));
 const HWND convert_window=(hit==global_parent_parent)?hit:hit_parent;
 POINT screen=point;ra2::platform::window_api_b972::client_to_screen(convert_window,&screen);
 RECT rect{};ra2::platform::window_api_b972::get_window_rect(hit,&rect);
 const std::uint32_t out=i.arg[0];
 const std::uint32_t values[10]={ra2::platform::window_api_b972::narrow(hit),ra2::platform::window_api_b972::narrow(convert_window),m.r32(0x00b0d9a8u),m.r32(0x00b0d9acu),static_cast<std::uint32_t>(screen.x),static_cast<std::uint32_t>(screen.y),x,y,static_cast<std::uint32_t>(screen.x-rect.left),static_cast<std::uint32_t>(screen.y-rect.top)};
 for(unsigned k=0;k<10;++k)m.w32(out+k*4u,values[k]);
 return out;
}
}
