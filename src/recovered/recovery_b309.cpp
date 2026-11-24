#include "recovery_b309.hpp"

#include <stdexcept>

namespace ra2::recovered::recovery_b309 {
namespace {
void need(bool ok, const char* why) {
    if (!ok) throw std::domain_error(why);
}
}

std::uint32_t fun_0050fa60(Memory& memory, Inputs& in, GuestHeap& heap,
                           std::uint32_t scratch_base) {
    // The pinned format at 0x7c002c is "%02d:%02d:%02d". The original
    // reciprocal-multiply sequence divides the signed input by 60 three
    // times, then emits q3, q2 mod 60, q1 mod 60. Bound the positive input
    // below 60^4 so each formatted field is exactly two digits and the value
    // clone is exactly 9 bytes including NUL.
    const auto units = in.arg[2];
    need(units <= 12959999u, "0x10fa60 draft route requires signed nonnegative input <= 60^4-1");
    need(in.cx != 0 && in.arg[0] != 0 && in.arg[1] != 0,
         "0x10fa60 route requires root, section, and key addresses");
    need(scratch_base != 0 && std::uint64_t(scratch_base) + 0x20u <= 0x100000000ull,
         "0x10fa60 local formatting buffer must be mapped and nonwrapping");

    const auto q1 = units / 60u;
    const auto q2 = q1 / 60u;
    const auto q3 = q2 / 60u;
    const auto first = q3;
    const auto second = q2 - q3 * 60u;
    const auto third = q1 - q2 * 60u;
    const std::uint8_t text[9] = {
        static_cast<std::uint8_t>('0' + (first / 10u)),
        static_cast<std::uint8_t>('0' + (first % 10u)), ':',
        static_cast<std::uint8_t>('0' + (second / 10u)),
        static_cast<std::uint8_t>('0' + (second % 10u)), ':',
        static_cast<std::uint8_t>('0' + (third / 10u)),
        static_cast<std::uint8_t>('0' + (third % 10u)), 0};
    for (unsigned i = 0; i != sizeof(text); ++i)
        memory.w8(scratch_base + i, text[i]);

    // Original 0x50fae4 passes outer arg0 as section, arg1 as key, and the
    // formatted local buffer as value. The helper's two caller-word stores
    // affect only this temporary 3-argument call frame, not outer inputs.
    Inputs child{};
    child.ax = in.ax;
    child.cx = in.cx;
    child.dx = in.dx;
    child.arg[0] = in.arg[0];
    child.arg[1] = in.arg[1];
    child.arg[2] = scratch_base;
    child.stack_minus8 = in.stack_minus8;
    child.arithmetic_flags = in.arithmetic_flags;
    const auto result = ra2::recovered::recovery_b305::fun_0010da40(memory, child, heap);
    in.ax = result;
    return result;
}
} // namespace ra2::recovered::recovery_b309
