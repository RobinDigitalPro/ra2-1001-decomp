#include "recovery_b1390.hpp"
#include "recovered/recovery_b1370.hpp"
#include <stdexcept>
namespace ra2::recovered::b1390 {
namespace {
using U = std::uint32_t;
void need(bool ok, const char* message) {
    if (!ok) throw std::domain_error(message);
}
}
U fun_002962a0(Memory& m, const Inputs& i) {
    // The selected original branch requires the initialized static-layout flag.
    // Reuse the unchanged accepted implementation and its exact helper closure.
    const U helper_eax = ra2::recovered::b1370::fun_00671450(m, i);
    const U al = m.r8(0xa28953u);
    need(al == 1u && (helper_eax & 0xffu) == 1u,
         "B1390 selected nonzero AL branch after accepted 0x271450 layout helper");
    // Original 0x6962AC reloads AL from A28953; high EAX is preserved.
    return (helper_eax & 0xffffff00u) | al;
}
}
