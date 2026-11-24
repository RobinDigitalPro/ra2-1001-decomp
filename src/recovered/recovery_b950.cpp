#include "recovered/recovery_b950.hpp"
#include "platform/listbox950.hpp"
using namespace ra2::platform::b950;
#include <cstdint>
namespace ra2::recovered::b950 {
std::uint32_t fun_00664bd0(Memory& m,const Inputs& i) {
    const std::uint32_t self=i.cx;
    const auto list=get_dlg_item(reinterpret_cast<HWND>(std::uintptr_t(m.r32(self))),0x65e);
    if(!list) return 0;
    const auto count=send_message(list,LB_GETCOUNT,0,0);
    if(static_cast<std::int32_t>(count)<=0) return count;
    std::uint32_t selected=send_message(list,LB_GETCURSEL,0,0);
    if(selected==0xffffffffu) return selected;
    send_message(list,LB_DELETESTRING,selected,0);
    auto global_count=m.r32(0x00a27e90);
    if(selected<global_count) {
        --global_count; m.w32(0x00a27e90,global_count);
        const auto array=m.r32(0x00a27e84);
        for(auto at=selected+1;at<=global_count;++at) m.w32(array+4u*(at-1),m.r32(array+4u*at));
    }
    const auto after_count=send_message(list,LB_GETCOUNT,0,0);
    if(selected>=after_count) --selected;
    send_message(list,LB_SETCURSEL,selected,0);
    const auto eax=send_message(list,LB_SETTOPINDEX,selected,0);
    m.w32(self+0x98,selected);
    return eax;
}
}
