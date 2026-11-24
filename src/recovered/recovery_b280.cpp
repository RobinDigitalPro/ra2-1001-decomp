#include "recovery_b280.hpp"

#include "recovered/text_b68.hpp"

#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b280 {

std::uint32_t fun_0053d230(Memory& memory, const Inputs& inputs) {
    // Frozen positive route: mode 1, a positive byte count equal to the
    // receiver's available count, and separate readable source/writable
    // destination spans. Equality makes the original post-copy EBX zero, so
    // execution exits before its resize/allocation/codec alternatives.
    const auto receiver = inputs.cx;
    const auto destination = inputs.arg[0]; // first stack argument
    const auto count = inputs.arg[1];       // second stack argument
    if (!receiver || !destination)
        throw std::domain_error("numeric280 route requires nonnull receiver and destination");
    if (memory.r32(receiver + 0x0cu) != 1u)
        throw std::domain_error("numeric280 route is limited to mode 1");

    const auto available = memory.r32(receiver + 0x10u);
    if (!available || available > 512u || count != available)
        throw std::domain_error("numeric280 route requires count==positive fixture-bounded available length");

    const auto source_base = memory.r32(receiver + 0x14u);
    const auto source_offset = memory.r16(receiver + 0x26u);
    if (!source_base || source_offset != available)
        throw std::domain_error("numeric280 fixture must resolve the mode-1 source to source_base");
    const auto source = source_base + std::uint32_t(source_offset) - available;
    const auto source_end = std::uint64_t(source) + count;
    const auto destination_end = std::uint64_t(destination) + count;
    if (source_end > 0x100000000ull || destination_end > 0x100000000ull ||
        (std::uint64_t(destination) < source_end && std::uint64_t(source) < destination_end))
        throw std::domain_error("numeric280 fixture requires nonwrapping nonoverlapping spans");

    // Accepted original helper 0x36ebd0 has the same destination, source,
    // count stack order and RET 0 contract. The route exits immediately after
    // this call, stores zero in receiver+0x10 and in the caller's second
    // stack word, then returns count in EAX.
    Inputs copy{};
    copy.arg[0] = destination;
    copy.arg[1] = source;
    copy.arg[2] = count;
    (void)ra2::recovered::global_b26::fun_0076ebd0(memory, copy);
    memory.w32(receiver + 0x10u, available - count);
    inputs.arg[1] = 0u;
    return count;
}

} // namespace ra2::recovered::recovery_b280
