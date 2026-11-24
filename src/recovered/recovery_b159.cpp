#include "recovered/recovery_b159.hpp"
#include "platform/observed_ticks152.hpp"
#include "platform/x87_scalar_b46.hpp"
#include <stdexcept>

namespace ra2::recovered::recovery_b159 {
std::uint32_t fun_005903e0(Memory& m, const Inputs& i) {
    if (!i.cx || i.cx > 0xfffffff8u)
        throw std::domain_error("159 requires an eight-byte guest input cell");
    if (m.r32(i.cx) != 0u || m.r32(i.cx + 4u) != 0x3ff00000u)
        throw std::domain_error("159 exact route requires the input binary64 value 1.0");
    if (m.r32(0x007cc7dcu) == 0xffffffffu)
        throw std::domain_error("159 bounded route bypasses first-use timing initialization");

    // The original reaches WINMM timeGetTime through IAT 0x785524 on this
    // branch. Tick::get calls that real OS API and records its actual result.
    const auto tick = ra2::platform::ticks152::Tick::get();
    ra2::platform::x87_scalar_b46::load_integer64(i.fp, std::uint64_t(tick));
    return tick; // Original EAX still contains the imported DWORD after FILD.
}
}
