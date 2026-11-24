#include "recovered/recovery_b201.hpp"

#include <stdexcept>

namespace ra2::recovered::recovery_b201 {
using floating_b61::Inputs;
using floating_b61::Memory;

namespace {
void require(bool okay, const char* message) {
    if (!okay) throw std::domain_error(message);
}

std::uint32_t execute_000e0030_zero_argument(Memory& m, std::uint32_t object,
                                             std::uint32_t argument) {
    // The receiver's original +0x38 slot must point to the pinned target.
    const auto vtable = m.r32(object);
    require(vtable == 0x00785954u && m.r32(vtable + 0x38u) == 0x004e0030u,
            "Block201 requires the constructor-proven 0x785954 +0x38 -> 0x4e0030 slot");

    // Exact reached instructions of RVA 0x0e0030. Its caller staged argument
    // is zero, so the branch to RET 4 is taken after the optional global byte
    // write. No callback return value is supplied by the fixture.
    const auto manager = m.r32(0x00821cacu);
    if (manager != 0u) m.w8(manager + 0xd7du, 1u);
    require(argument == 0u,
            "Block201 only models original 0x0e0030 pushed-zero argument branch");
    return 0u;
}

std::uint32_t signed_magic_divide_50(std::uint32_t value) {
    // Original: IMUL EDX by 51eb851f; SAR high half by four; add the sign
    // correction from SHR EAX,31. This equals signed truncation by 50.
    const auto product = std::int64_t(floating_b61::s32(value)) * 0x51eb851fll;
    const auto high = static_cast<std::uint32_t>(static_cast<std::uint64_t>(product) >> 32u);
    const auto shifted = floating_b61::sar(high, 4u);
    return shifted + (shifted >> 31u);
}

std::uint32_t small_counter(Memory& m, std::uint32_t row) {
    // Exact original global/player expression, with every operation wrapping
    // as a 32-bit instruction before signed IMUL/divide interpretation.
    const auto player = m.r32(0x00a255c0u);
    const auto player_nonzero = m.r8(player + 0x2239u) != 0u;
    const auto penalty = player_nonzero ? 26u : 18u;
    auto difference = m.r32(0x0082196cu) - m.r32(0x00aa486cu);
    difference -= penalty;
    difference += m.r32(0x00821964u);
    difference -= 7u;
    const auto quotient = signed_magic_divide_50(difference);
    const auto adjusted = quotient + m.r32(row + 0x40u);
    const auto doubled = adjusted << 1u;
    return floating_b61::s32(doubled) >= floating_b61::s32(m.r32(row + 0x50u))
        ? 1u : 0u;
}
} // namespace

std::uint32_t fun_00672590(Memory& m, const Inputs& i) {
    const auto early_value = m.r32(0x00a28974u);
    if (early_value != 0u)
        return early_value & 0xffffff00u; // original XOR AL,AL epilogue

    // Original EDX is arg1. -1 selects the receiver's +0x4ed8 fallback.
    const auto input_index = i.arg[1];
    const auto index = input_index == 0xffffffffu
        ? m.r32(i.cx + 0x4ed8u)
        : input_index;
    require(index <= 3u,
            "Block201 bounded route selects row index 0..3 only");

    // Preserve the original multiply sequence:
    // 16n+n=17n; LEA *9=153n; 2*153n+n=307n; final LEA *3=921n;
    // ESI adds EDX*4, so each row starts 0xe64 bytes after its predecessor.
    const auto row = i.cx + 0x1540u + index * 0xe64u;
    if ((i.arg[0] & 0xffu) != 0u) {
        const auto guard = m.r32(row + 0x40u);
        if (guard == 0u) return 0u;

        // Original order is counter read, PUSH 0, DEC, store, then dispatch.
        m.w32(row + 0x44u, m.r32(row + 0x44u) - 1u);
    } else {
        if (small_counter(m, row) != 0u)
            return m.r32(row + 0x50u) & 0xffffff00u;
        m.w32(row + 0x44u, m.r32(row + 0x44u) + 1u);
    }

    // Both productive counter branches call the same authentic +0x38 target
    // with PUSH 0. Its RET 4 returns EAX=0; MOV AL,1 yields full EAX=1.
    const auto target_result = execute_000e0030_zero_argument(m, i.cx, 0u);
    (void)target_result;
    return 1u;
}
} // namespace ra2::recovered::recovery_b201
