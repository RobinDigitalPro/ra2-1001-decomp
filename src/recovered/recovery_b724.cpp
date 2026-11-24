#include "recovery_b724.hpp"
#include "platform/small_crt_heap_empty173.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b724 {
namespace { void need(bool x,const char* s){if(!x)throw std::domain_error(s);} }
std::uint32_t fun_007733a8(Memory& m,Inputs& i,Heap& h){
    // Finite direct-entry contract: the actual first region record and its
    // first class-1 allocation are supplied by the declared fixture.
    const auto record=i.arg[0],user=i.arg[1];
    need(record!=0&&record==m.r32(0xb10e0cu),"3733A8 requires the selected current region record");
    need(user!=0&&user==h.first_user_pointer(),"3733A8 requires the live first request-20 allocation");
    // The wrapper 36DF28 owns lock entry/leave; the standalone helper body
    // 3733A8 does not enter that wrapper or call a host free API on this path.
    ra2::platform::small_crt_heap::empty173::release_last_class1(h,user);
    // EBP+0x0C is the mutable second caller word. The final merged class is
    // clamped to 0x3f by 77349A..7734A5 and survives through RET at 7736D2.
    i.arg[1]=0x3fu;
    // The supported nonempty-region branch loads the supplied record at
    // 7736C0 and returns it in full EAX.
    return record;
}
}
