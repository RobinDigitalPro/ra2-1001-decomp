#include "recovered/recovery_b193.hpp"

#include "recovered/recovery_b193.hpp"
#include "recovered/global_b26_memory.hpp"

#include <array>
#include <stdexcept>

namespace ra2::recovered::recovery_b193 {
using floating_b61::Inputs;
using floating_b61::Memory;

namespace {
enum class Root { r14e6f0, r151ce0, r152640 };

void require(bool condition, const char* message) {
    if (!condition) throw std::domain_error(message);
}

std::uint32_t run_outer(Memory& m, const Inputs& i, Root root) {
    // At entry [ESP+8] is arg1 (offset index). After PUSH ESI,
    // [ESP+8] is arg0 (the input coordinate pair).
    const auto index = i.arg[1] & 7u;
    const auto coordinate = i.arg[0];
    const auto dx = m.r16(0x00839da0u + index * 4u);
    const auto dy = m.r16(0x00839da2u + index * 4u);
    const auto x = (m.r16(coordinate) + dx) & 0xffffu;
    const auto y = (m.r16(coordinate + 2u) + dy) & 0xffffu;

    // The original writes DX/AX to [ESP+0xc]/[ESP+0xe], which is the
    // caller's arg1 slot after PUSH ESI. Preserve the full resulting DWORD.
    i.arg[1] = x | (y << 16u);

    const auto sx = global_b26::s32(global_b26::sx16(x));
    const auto sy = global_b26::s32(global_b26::sx16(y));
    const auto signed_index = sy * 0x200 + sx;
    require(signed_index >= 0 && signed_index < 0x40000,
            "Block193 outer route requires an in-range nonfallback cell");
    const auto tile_table = m.r32(0x0081a958u);
    const auto cell = m.r32(tile_table + std::uint32_t(signed_index) * 4u);
    require(cell != 0,
            "Block193 outer route excludes the null-cell fallback branch");

    // Preserve each wrapper's distinct pre-dispatch type-byte update.
    if ((m.r8(cell + 0x140u) & 0x80u) != 0u) {
        const auto kind = m.r8(cell + 0x11eu);
        switch (root) {
        case Root::r14e6f0:
            if (kind <= 3u) m.w8(cell + 0x11eu, 4u);
            else if (kind == 5u) m.w8(cell + 0x11eu, 6u);
            break;
        case Root::r151ce0:
            if (kind <= 3u) m.w8(cell + 0x11eu, 5u);
            else if (kind == 4u) m.w8(cell + 0x11eu, 6u);
            break;
        case Root::r152640:
            if (kind >= 9u && kind <= 12u) m.w8(cell + 0x11eu, 13u);
            else if (kind == 14u) m.w8(cell + 0x11eu, 15u);
            break;
        }
    }

    std::uint32_t base_address = 0;
    std::uint32_t first_threshold = 0;
    std::uint32_t alternate_threshold = 0;
    std::uint32_t unsupported_threshold = 0;
    std::uint32_t unsupported_delta = 0;
    switch (root) {
    case Root::r14e6f0:
        base_address = 0x00a547a0u;
        first_threshold = 0x00a55c60u;
        alternate_threshold = 0x00a3a8c0u;
        unsupported_threshold = 0x00a547b4u;
        unsupported_delta = 2u;
        break;
    case Root::r151ce0:
        base_address = 0x00a3a8b0u;
        first_threshold = 0x00a55d1cu;
        alternate_threshold = 0x00a3abb8u;
        unsupported_threshold = 0x00a547b4u;
        unsupported_delta = 1u;
        break;
    case Root::r152640:
        base_address = 0x00a3a8b0u;
        first_threshold = 0x00a3afccu;
        alternate_threshold = 0x00a3a1c0u;
        unsupported_threshold = 0x00a3aab0u;
        unsupported_delta = 1u;
        break;
    }
    const auto dispatch = m.r32(cell + 0x38u) - m.r32(base_address) + 1u;
    require(dispatch == m.r32(first_threshold),
            "Block193 outer route requires its original first 0x14e340 threshold");
    require(dispatch != m.r32(alternate_threshold),
            "Block193 outer route excludes the alternate threshold branch");
    const auto unsupported = m.r32(unsupported_threshold);
    require(dispatch != unsupported && dispatch != unsupported + unsupported_delta,
            "Block193 outer route excludes both 0x14e530 branches");

    // Root locals are transient: only the packed caller arg1 above remains
    // observable. The callee receives the local pair and original call args
    // (coordinate pointer, 1, 0) in that order.
    constexpr std::uint32_t local_pair = 0x7e210000u;
    std::array<std::uint8_t, 4> pair_bytes{};
    leaf::Memory pair_span(pair_bytes.data(), local_pair,
                           static_cast<std::uint32_t>(pair_bytes.size()));
    Memory local = m;
    local.add(pair_span);
    local.w16(local_pair, x);
    local.w16(local_pair + 2u, y);
    Inputs inner = i;
    inner.arg[0] = local_pair;
    inner.arg[1] = 1u;
    inner.arg[2] = 0u;
    const auto result = fun_0054e340(local, inner);
    i.fp = inner.fp;
    return result;
}
} // namespace

std::uint32_t fun_0054e6f0(Memory& m, const Inputs& i) {
    return run_outer(m, i, Root::r14e6f0);
}

std::uint32_t fun_00551ce0(Memory& m, const Inputs& i) {
    return run_outer(m, i, Root::r151ce0);
}

std::uint32_t fun_00552640(Memory& m, const Inputs& i) {
    return run_outer(m, i, Root::r152640);
}
} // namespace ra2::recovered::recovery_b193
