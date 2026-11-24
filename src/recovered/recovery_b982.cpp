#include "recovered/recovery_b982.hpp"
#include "platform/observed_window_b982.hpp"
#include <stdexcept>
namespace ra2::recovered::b982 {
namespace api=ra2::platform::window_api_b982;
std::uint32_t fun_005f6060(Memory&m,const Inputs&i){
 const auto p=i.cx;auto h=reinterpret_cast<HWND>(std::uintptr_t(m.r32(p+0x14u)));
 if(!m.r32(0x821c90u)||!m.r32(0x821c98u)||m.r32(p)!=4u||m.r32(0xa5b1b8u)!=0x5d6fc0u||m.r32(0xa5b1acu)!=7u||!m.r32(0xa5b1a4u))throw std::domain_error("982 finitepositivecontract");
 RECT relative{};if(!api::get_window_rect(h,&relative))throw std::domain_error("982 helperwindowrect");
 auto anchor=reinterpret_cast<HWND>(std::uintptr_t(m.r32(0xb0de50u)));RECT client{};
 if(!api::get_client_rect(anchor,&client))throw std::domain_error("982 anchorclient");
 POINT origin{client.left,client.top};if(!api::client_to_screen(anchor,&origin))throw std::domain_error("982 helperorigin");
 relative.left-=origin.x;relative.right-=origin.x;relative.top-=origin.y;relative.bottom-=origin.y;
 RECT target{};if(!api::get_client_rect(h,&target))throw std::domain_error("982 targetclient");
 const LONG style=api::get_window_long_a(h,-16);
 if(style&WS_BORDER){const int bx=api::get_system_metrics(5),by=api::get_system_metrics(6);relative.left+=bx;relative.right-=bx;relative.top+=by;relative.bottom-=by;}
 const auto key=m.r32(p+0x14u),buckets=m.r32(0xa5b1a0u);auto node=m.r32(buckets+4u*(key&127u));
 while(node&&m.r32(node)!=key)node=m.r32(node+0x204u);if(!node)throw std::domain_error("982 positivehashrecord");
 m.w32(node+0xecu,m.r32(p+0x10u));RECT dirty{LONG(m.r32(p+0x1cu)),LONG(m.r32(p+0x20u)),LONG(m.r32(p+0x24u)),LONG(m.r32(p+0x28u))};
 if(!api::invalidate_rect(h,&dirty,FALSE))throw std::domain_error("982 actualinvalidate");return std::uint32_t(api::update_window(h));
}}
