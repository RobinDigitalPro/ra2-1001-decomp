#include "recovery_b308.hpp"
#include <array>
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b308 {
namespace {
void need(bool ok, const char* why) {
    if (!ok) throw std::domain_error(why);
}
}

// Finite useful 0x62a5b0 mode transition. The second argument is zero, so
// the original conditional 0x708970 call is skipped. The reached 0x6070
// helper is constrained to its accepted no-tail-call path.
std::uint32_t rva_0022a5b0(Memory& m, const Inputs& in) {
    const auto receiver = in.cx;
    need(receiver != 0, "B308 requires a mapped receiver");
    need(in.arg[0] == 0u, "B308 chooses selector mode zero (not mode one)");
    need(in.arg[1] == 0u, "B308 skips missing 0x308970 resource consumer");
    need(m.r32(0x8192f8u) != 0u, "B308 0x6070 manager-active guard");

    global_b26::Inputs helper{};
    helper.cx = receiver + 0x14bcu;
    const auto w=helper.cx,node=m.r32(w),record=m.r32(w+8);
    need(node&&record&&m.r32(w+12)==0x8192ec&&m.r32(node+0x24)==record&&m.r32(node+0x138)==m.r32(w+4),"308 exact accepted child identity");
    need((m.r8(record+0x10)&1)&&m.r32(record+0x4c)==0&&(m.r8(node+0x18)&0x20)==0&&m.r32(node+0xb0)==0,"308 accepted no-tail child branch");
    // Exact accepted objects_b99::mark_child body, isolated from unrelated functions.
    const auto helper_eax=m.r32(node+0x18)|0x60u;m.w32(node+0x18,helper_eax);m.w32(w,0);m.w32(w+8,0);

    // Original stores state 2 after 0x6070 and MOV AL,[entry ESP+8] supplies
    // zero. Its following 0x68f0 body is exactly RET, preserving upper EAX.
    m.w32(receiver + 0x14a8u, 2u);
    const auto eax = helper_eax & 0xffffff00u;

    // Original 0x4068f0 is exactly RET: preserve the incoming EAX.
    return eax;
}
}
