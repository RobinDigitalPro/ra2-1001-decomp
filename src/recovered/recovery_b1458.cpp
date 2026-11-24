#include "recovered/recovery_b1458.hpp"
#include "recovered/recovery_b1023.hpp"
#include "platform/dialog1023.hpp"
#include "platform/x87_state.hpp"
namespace ra2::recovered::b1458 {
unsigned fun_00743390(Memory&m,const Inputs&i){
    b1023::ui::need(i.arg[1]==0x138u,"1458 finite genuine Static color query");
    global_b26::Inputs child{};
    child.cx=i.arg[0];child.dx=i.arg[1];child.arg[0]=i.arg[2];child.arg[1]=i.arg[3];
    const auto host=platform::x87::capture_host();
    i.fp.require_masked();platform::x87::restore_host(i.fp.image);
    try {
        const unsigned brush=b1023::fun_005f77c0(m,child);
        // Capture at target exit, before object verification or restoring host FP.
        i.fp.image=platform::x87::capture_host();platform::x87::restore_host(host);
        b1023::ui::need(brush!=0,"1458 actual nonnull GetStockObject result");
        return brush;
    }catch(...){platform::x87::restore_host(host);throw;}
}
}
