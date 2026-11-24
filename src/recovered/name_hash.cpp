#include "recovered/name_hash.hpp"

#include <limits>
#include <stdexcept>

namespace ra2::recovered {
namespace {
constexpr std::array<std::uint32_t, 256> make_table() {
    std::array<std::uint32_t, 256> table{};
    for (std::uint32_t i = 0; i < table.size(); ++i) {
        auto crc = i;
        for (int bit = 0; bit < 8; ++bit)
            crc = (crc >> 1) ^ ((crc & 1u) ? 0xedb88320u : 0u);
        table[i] = crc;
    }
    return table;
}
// All 256 generated words are checked against original VA 0x7c0634 by the gate.
constexpr auto table = make_table();
}

std::uint32_t fun_00493f70(const std::uint8_t* bytes, std::uint32_t length,
                         std::uint32_t seed) {
    auto crc = ~seed;                              // 0x493f70..0x493f7c
    for (std::uint32_t i = 0; i < length; ++i)
        crc = (crc >> 8) ^ table[(crc & 0xffu) ^ bytes[i]];
    return ~crc;                                  // 0x493fa1
}

std::uint32_t fun_00493da0(NameHashState& state, const std::uint8_t* bytes,
                         std::int32_t length) {
    if (bytes != nullptr && length > 0) {          // 0x493dae / 0x493dba
        while (state.pending != 0 && length > 0) { // 0x493dc0..0x493e19
            state.scratch[state.pending++] = *bytes++;
            --length;
            if (state.pending == 4) {
                state.completion_byte = 4;        // 0x493de6: observed write +12
                state.accumulator = fun_00493f70(state.scratch.data(), 4, state.accumulator);
                state.pending = 0;
            }
        }
        while (length >= 4) {                     // 0x493e1b..0x493e74
            state.accumulator = fun_00493f70(bytes, 4, state.accumulator);
            bytes += 4;
            length -= 4;
        }
        while (length > 0) {                      // 0x493e76..0x493efe
            if (state.pending == 0) state.scratch.fill(0);
            state.scratch[state.pending++] = *bytes++;
            --length;
        }
    }
    if (state.pending == 0) return state.accumulator;
    state.scratch[state.pending] = static_cast<std::uint8_t>(state.pending);
    for (auto i = state.pending + 1; i < 4; ++i)
        state.scratch[i] = state.scratch[0];       // 0x493f07..0x493f21
    return fun_00493f70(state.scratch.data(), 4, state.accumulator); // no commit
}

std::uint32_t ini_name_hash(const std::uint8_t* bytes, std::size_t length, void*) {
    if (length > static_cast<std::size_t>(std::numeric_limits<std::int32_t>::max()))
        throw std::length_error("INI name exceeds the signed original hash length");
    NameHashState state{};
    return fun_00493da0(state, bytes, static_cast<std::int32_t>(length));
}

} // namespace ra2::recovered
