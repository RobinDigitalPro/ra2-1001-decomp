#include "recovered/recovery_b155.hpp"
#include <stdexcept>

namespace ra2::recovered::global_b26 {
std::uint32_t fun_0076ebd0(Memory&, const Inputs&);
}

namespace ra2::recovered::recovery_b155 {
std::uint32_t fun_005335e0(Memory& m, const Inputs& i) {
    const auto receiver = i.cx;
    const auto destination = i.arg[0];
    const auto requested = i.arg[1];
    const auto mode = m.r32(receiver + 0x0cu);
    const auto available = m.r32(receiver + 0x10u);
    const auto source_base = m.r32(receiver + 0x14u);
    const auto source_end = m.r16(receiver + 0x26u);
    if (!destination || requested == 0u || requested > 32u || mode != 1u ||
        available < requested || available > 32u || source_end < available || !source_base)
        throw std::domain_error("Block155 requires mode 1 and one bounded nonempty existing-buffer transfer");

    const auto source = source_base + static_cast<std::uint32_t>(source_end) - available;
    global_b26::Inputs copy{};
    copy.arg[0] = destination;
    copy.arg[1] = source;
    copy.arg[2] = requested;
    global_b26::fun_0076ebd0(m, copy);

    // The original exits immediately once the requested length is consumed;
    // refill/resize branches (including missing 0x290740) stay unreachable.
    m.w32(receiver + 0x10u, available - requested);
    i.arg[1] = 0u; // [ESP+0x1c] aliases the caller's second argument on exit.
    return requested;
}
}
