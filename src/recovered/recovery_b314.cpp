#include "recovery_b314.hpp"

#include <stdexcept>

namespace ra2::recovered::recovery_b314 {
namespace {
void need(bool ok, const char* why) { if (!ok) throw std::domain_error(why); }
}

std::uint32_t fun_0046b730(Memory& memory, Inputs& in, GuestHeap& heap,
                           std::uint32_t scratch_base) {
    constexpr std::uint32_t zero_fill_flag = 0x008248a4u;
    need(in.cx && in.arg[0] && in.arg[1] && in.arg[2],
         "0x6b730 route requires root, section, key and collection pointers");
    need(scratch_base && std::uint64_t(scratch_base) + 0x200u <= 0x100000000ull,
         "0x6b730 local buffer must be a mapped nonwrapping 512-byte span");
    need(memory.r8(zero_fill_flag) == 0,
         "0x6b730 route requires the original zero-filled optional-prefix byte");

    const auto collection = in.arg[2];
    need(memory.r32(collection + 0x10u) == 1,
         "0x6b730 draft covers exactly one collection row");
    const auto array = memory.r32(collection + 4u);
    need(array != 0, "0x6b730 one-row collection requires its item array");
    const auto row = memory.r32(array);
    need(row != 0, "0x6b730 one-row collection requires a nonnull row");
    const auto text = row + 0x24u;
    need(memory.r8(text) != 0 && memory.r8(text + 1u) != 0 &&
         memory.r8(text + 2u) == 0,
         "0x6b730 finite route requires exactly two row bytes and a terminator");

    // Original prologue clears bytes 1..511 after copying the zero-fill flag
    // into byte 0. The single SCASB/REP MOVS row pass replaces bytes 0..2.
    memory.w8(scratch_base, 0);
    for (std::uint32_t i = 1; i != 0x200u; ++i) memory.w8(scratch_base + i, 0);
    for (std::uint32_t i = 0; i != 3; ++i)
        memory.w8(scratch_base + i, memory.r8(text + i));

    // Original 0x46b7ef / 0x46b7f0 passes outer arg0/arg1 and the private
    // buffer as value. Child A1/A2 mutations remain in this temporary frame.
    Inputs child{};
    child.ax = in.ax; child.cx = in.cx; child.dx = in.dx;
    child.arg[0] = in.arg[0]; child.arg[1] = in.arg[1]; child.arg[2] = scratch_base;
    child.stack_minus8 = in.stack_minus8;
    child.arithmetic_flags = in.arithmetic_flags;
    const auto eax = ra2::recovered::recovery_b305::fun_0010da40(memory, child, heap);
    in.ax = eax;
    return eax;
}
}
