#include "recovery_b253.hpp"
#include "platform/current_crt_thread.hpp"
#include <array>
#include <stdexcept>

namespace ra2::recovered::recovery_b253 {
std::uint32_t fun_0076e802(Memory& memory, const Inputs& input) {
    // ESI retains the delimiter argument before the original overwrites arg1.
    const auto delimiters = input.arg[1];
    const auto thread = ra2::platform::current_crt_thread(memory.r32(0x817778));
    input.arg[1] = thread; // Original VA 76e815, observable caller storage.
    std::array<std::uint8_t, 32> bitmap{};
    bool terminated = false;
    for (unsigned k = 0; k < 256; ++k) {
        const auto byte = memory.r8(delimiters + k);
        bitmap[byte >> 3] |= static_cast<std::uint8_t>(1u << (byte & 7));
        if (!byte) { terminated = true; break; }
    }
    if (!terminated) throw std::domain_error("253 delimiter bound exceeded");
    const auto is_delimiter = [&](std::uint32_t byte) {
        return (bitmap[byte >> 3] & (1u << (byte & 7))) != 0;
    };
    auto cursor = input.arg[0] ? input.arg[0] : memory.r32(thread + 0x18);
    if (!cursor) throw std::domain_error("253 requires readable continuation");
    unsigned consumed = 0;
    while (consumed < 512) {
        const auto byte = memory.r8(cursor);
        if (!byte || !is_delimiter(byte)) break;
        ++cursor; ++consumed;
    }
    if (consumed == 512) throw std::domain_error("253 input bound exceeded");
    const auto start = cursor;
    while (consumed < 512) {
        const auto byte = memory.r8(cursor);
        if (!byte) break;
        if (is_delimiter(byte)) { memory.w8(cursor, 0); ++cursor; break; }
        ++cursor; ++consumed;
    }
    if (consumed == 512) throw std::domain_error("253 input bound exceeded");
    memory.w32(thread + 0x18, cursor);
    return start == cursor ? 0u : start;
}
}
