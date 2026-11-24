#include "recovery_b283.hpp"

#include "recovered/text_b68.hpp"

#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b283 {

std::uint32_t fun_0042b850(Memory& memory, const Inputs& inputs) {
    // Closed positive route: inline mode, entire available byte count consumed.
    const auto receiver = inputs.cx;
    const auto destination = inputs.arg[0];
    const auto requested = inputs.arg[1];
    if (!receiver || !destination || receiver > 0xffffffe7u)
        throw std::domain_error("Block283 route requires nonnull receiver and destination");
    if (memory.r32(receiver + 0x0cu) != 0u)
        throw std::domain_error("Block283 route is limited to inline mode 0");

    const auto available = memory.r32(receiver + 0x10u);
    if (available == 0u || available > 4u || requested != available)
        throw std::domain_error("Block283 route requires 1 <= requested == available <= 4");

    // Mode 0 chooses EBX = receiver+0x14 and EBP = 4, then computes
    // source = EBP - available + EBX = receiver+0x18-available.
    // This is the trailing requested span of the receiver's inline 4-byte area.
    const auto source = receiver + 0x18u - available;
    const auto source_end = std::uint64_t(source) + available;
    const auto destination_end = std::uint64_t(destination) + available;
    if (source_end > 0x100000000ull || destination_end > 0x100000000ull ||
        (std::uint64_t(destination) < source_end && std::uint64_t(source) < destination_end))
        throw std::domain_error("Block283 route requires nonwrapping distinct inline and destination spans");

    // Original call at VA 0x42b8c6 -> accepted RVA 0x36ebd0. The helper
    // receives destination, source, count and has plain RET (caller cleans 12).
    Inputs copy{};
    copy.arg[0] = destination;
    copy.arg[1] = source;
    copy.arg[2] = available;
    (void)ra2::recovered::global_b26::fun_0076ebd0(memory, copy);

    // With requested == available, EBX becomes zero and the original takes
    // the epilogue before calls at 0x42b903, 0x42b918, and 0x42b91f.
    memory.w32(receiver + 0x10u, 0u);
    inputs.arg[0] = destination + available;
    inputs.arg[1] = 0u;
    return available;
}

} // namespace ra2::recovered::recovery_b283
