#include "recovery_b304.hpp"
#include <limits>
#include <stdexcept>
namespace ra2::recovered::recovery_b304 {
namespace {
void require(bool ok, const char* why) {
    if (!ok) throw std::domain_error(why);
}
}

// Exact finite positive route for original RVA 0x000aa870 when its sole
// stack argument is zero. The original initializes the receiver's observed
// 0x24-byte field region, skips allocation and the indirect call, and returns
// the receiver in full EAX with RET 4. Field names and class semantics remain
// unknown; offset writes mirror the original instructions.
std::uint32_t fun_004aa870(Memory& m, const Inputs& i) {
    const auto receiver = i.cx;
    const auto count = i.arg[0];
    require(receiver != 0 && receiver <= std::numeric_limits<std::uint32_t>::max()-0x23u &&
                (i.arithmetic_flags & 0x400u) == 0,
            "B304 requires a nonnull receiver and clear direction flag");
    require(count == 0,
            "B304 closes only the original zero-count branch");

    m.w32(receiver + 0x04u, 0);
    m.w32(receiver + 0x08u, 0);
    m.w32(receiver + 0x0cu, 0);
    m.w32(receiver + 0x10u, 0);
    m.w32(receiver + 0x14u, 0);
    m.w8(receiver + 0x18u, 0);
    m.w8(receiver + 0x19u, 0);
    m.w32(receiver + 0x1cu, count);
    m.w32(receiver + 0x20u, 0);
    m.w32(receiver, 0x0078bbe4u);
    return receiver;
}
}
