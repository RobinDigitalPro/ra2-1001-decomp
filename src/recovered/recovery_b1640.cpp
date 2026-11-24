#include "recovered/recovery_b1640.hpp"
#include "platform/x87_state.hpp"
#include <stdexcept>

namespace ra2::recovered::b1640 {
namespace {
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
U ptr(HWND h){return U(reinterpret_cast<std::uintptr_t>(h));}
}

U fun_004cf5e0(Memory&m,const Inputs&i,Api&a){
    namespace fp=ra2::platform::x87;
    const auto host=fp::capture_host();
    try{
        need(a.parent&&a.get_dlg_item&&a.send_message_a,
             "B1640 requires actual owned parent/GetDlgItem/SendMessageA bindings");
        need(i.cx&&m.r32(i.cx)==ptr(a.parent),
             "B1640 ECX must point to the readable actual parent-HWND holder");
        need(m.r8(0x00a285a8u)==1&&m.r32(0x00a255c8u)==0,
             "B1640 selected material route requires flag 1 and mode 0");

        fp::restore_host(i.fp.image);

        HWND track=a.get_dlg_item(a.parent,0x529);
        need(track!=nullptr,"B1640 resource-255 trackbar 0x529 must exist");
        const auto position=a.send_message_a(track,0x400u,0,0);
        need(position>=0&&position<=6,
             "B1640 actual TBM_GETPOS result must be in [0,6]");
        const U value=6u-U(position);
        need(m.r32(0x00a28758u)!=value,
             "B1640 material route requires A28758 to differ from 6-TBM_GETPOS");

        m.w32(0x00a28758u,value);

        for(const int id:std::array<int,5>{0x52a,0x52b,0x601,0x604,0x602}){
            need(a.get_dlg_item(a.parent,id)==nullptr,
                 "B1640 selected resource-255 route requires the remaining queried controls to be absent");
        }
        i.fp.image=fp::capture_host();
        fp::restore_host(host);
        return 1u;
    }catch(...){
        fp::restore_host(host);
        throw;
    }
}
}


