#include "recovered/recovery_b165.hpp"
#include "platform/observed_ticks152.hpp"
#include <algorithm>
#include <stdexcept>

namespace ra2::recovered::recovery_b165 {
namespace {
constexpr std::uint32_t kScratchBase = 0x7d005f90u; // fixed virtual S-0x70; S=0x7d006000
constexpr std::uint32_t kQueue = 0x00a1a674u;
constexpr std::uint32_t kCount = 0x00a1a668u;
constexpr std::uint32_t kCursor = 0x00a1a670u;
constexpr std::uint32_t kTicks = 0x00a1ddf4u;

ra2::recovered::global_b26::Function helper_b5e80() {
    const auto& entries = ra2::recovered::global_b26::entries_a();
    const auto found = std::find_if(entries.begin(), entries.end(), [](const auto& e) {
        return e.rva == 0x000b5e80u;
    });
    if (found == entries.end()) throw std::logic_error("accepted 0xb5e80 helper missing");
    return found->function;
}
}

std::uint32_t fun_0061af30(Memory& m, const Inputs& i, const Scratch& scratch) {
    // Local helper memory aliases the real global spans and adds only the
    // explicitly supplied 112-byte entry-stack prestate. The authentic helper
    // writes the same partial record as original 0x4b5e80.
    auto local_memory = m;
    auto local_bytes = scratch;
    ra2::recovered::leaf::Memory local_span(local_bytes.data(), kScratchBase,
                                             static_cast<std::uint32_t>(local_bytes.size()));
    local_memory.add(local_span);

    const auto context = m.r32(0x00a1e0e4u);
    if (!context || context > 0xffffffccu) throw std::domain_error("Block165 requires readable 0xa1e0e4 context +0x30 DWORD");
    if (i.dx > 0xfffffffau) throw std::domain_error("Block165 EDX input must cover five readable bytes");
    if (!i.arg[2] || i.arg[2] > 0xfffffffau) throw std::domain_error("Block165 arg2 input must cover five readable bytes");

    ra2::recovered::global_b26::Inputs h{};
    h.cx = kScratchBase;
    h.arg[0] = m.r32(context + 0x30u); // nonnegative route selected in fixtures
    if (ra2::recovered::global_b26::s32(h.arg[0]) < 0)
        throw std::domain_error("Block165 fixtures use the helper's nonnegative record branch");
    h.arg[1] = i.arg[0];
    h.arg[2] = i.arg[1] & 0xffu;
    h.arg[3] = i.cx;
    h.arg[4] = m.r32(i.dx);
    h.arg[5] = m.r8(i.dx + 4u);
    h.arg[6] = m.r32(i.arg[2]);
    h.arg[7] = m.r8(i.arg[2] + 4u);
    h.arg[8] = i.arg[0];
    h.arg[9] = 0;
    (void)helper_b5e80()(local_memory, h);

    const auto count = m.r32(kCount);
    if (ra2::recovered::global_b26::s32(count) < 0 || count >= 128u)
        throw std::domain_error("Block165 positive-route fixtures require signed count in [0,127]");
    const auto cursor = m.r32(kCursor);
    if (cursor >= 128u) throw std::domain_error("Block165 fixtures require cursor < 128");

    const auto destination = kQueue + cursor * 111u;
    for (std::uint32_t n = 0; n < 111u; ++n)
        m.w8(destination + n, local_memory.r8(kScratchBase + n));

    const auto tick = ra2::platform::ticks152::Tick::get();
    m.w32(kTicks + cursor * 4u, tick);
    m.w32(kCount, count + 1u);
    m.w32(kCursor, (cursor + 1u) & 0x7fu);

    // Original MOV EAX,[count]; INC EAX; MOV AL,1. Since count<128,
    // the resulting full EAX is exactly 1, not the clock sample.
    return 1u;
}
}
