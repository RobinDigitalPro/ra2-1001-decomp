#include "recovery_b1381.hpp"
#include <stdexcept>
namespace ra2::recovered::b1381 {
namespace {
using U = std::uint32_t;
void need(bool ok, const char* message) {
    if (!ok) throw std::domain_error(message);
}
// Exact finite translation of the already accepted 0x430320 helper body:
// MOV EAX,[ECX+4]; MOV ECX,[EAX+0C]; MOV EDX,[EAX+8]; CMP ECX,EDX;
// SBB EAX,EAX; INC EAX; RET. It is called twice on the selected true route.
U original_430320(Memory& m, U resource) {
    const U record = m.r32(resource + 4u);
    return m.r32(record + 8u) <= m.r32(record + 0xcu) ? 1u : 0u;
}
}
U fun_005aa600(Memory& m, const Inputs& i) {
    need(i.arg[0] != 0, "B1381 selected nonnull first stack argument");
    const U resource = m.r32(i.cx + 0x1cu);
    need(resource != 0, "B1381 selected nonnull resource pointer");
    need(original_430320(m, resource) == 1u,
         "B1381 first accepted 0x430320 result takes completed-resource route");
    // A true first result skips the 0x4306C0 route and the virtual/drawing body.
    need(original_430320(m, resource) == 1u,
         "B1381 second accepted 0x430320 result keeps completed-resource route");
    // The original loads the byte at self+38; zero returns full EAX=1, nonzero
    // returns full EAX=0. Neither selected exit changes memory, stack words or FP.
    return m.r8(i.cx + 0x38u) == 0 ? 1u : 0u;
}
}
