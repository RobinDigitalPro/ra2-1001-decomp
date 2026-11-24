#include "recovery_b333.hpp"

#include <stdexcept>

namespace ra2::recovered::recovery_b333 {
namespace {
constexpr std::uint32_t kDescriptorTable = 0x00b10d00u;
constexpr std::uint32_t kDescriptorCount = 0x00b10e00u;
constexpr std::uint32_t kReadCount = 0x00b10450u;
constexpr std::uint32_t kDescriptorStride = 0x24u;
constexpr std::uint32_t kBufferBytes = 0x1000u;

std::uint32_t descriptor_record(Memory& memory, std::uint32_t fd) {
    if (fd >= memory.r32(kDescriptorCount))
        throw std::domain_error("0x380de3 draft requires an initialized in-range CRT descriptor");
    const auto chunk = memory.r32(kDescriptorTable + 4u * (fd >> 5));
    if (!chunk)
        throw std::domain_error("0x380de3 draft requires an initialized descriptor chunk");
    return chunk + (fd & 31u) * kDescriptorStride;
}
} // namespace

std::uint32_t fun_00780de3(Memory& memory, const Inputs& inputs, Heap& heap,
                           FileOps& file_ops) {
    const auto stream = inputs.arg[0];
    if (!stream)
        throw std::domain_error("0x380de3 draft requires a nonnull stream state");

    // 0x780de8..0x780e12: this narrow route starts at flags==1, takes the
    // allocation branch, and leaves the stream flags at 1 until 0x77b750.
    if (memory.r32(stream + 0x00u) != 0u ||
        memory.r32(stream + 0x04u) != 0u ||
        memory.r32(stream + 0x08u) != 0u ||
        memory.r32(stream + 0x0cu) != 1u ||
        memory.r32(stream + 0x18u) != 0u)
        throw std::domain_error("0x380de3 draft requires the observed empty flags-1 stream preimage");

    // Inline the exact successful branch of 0x77b750: INC [0xb10450],
    // HeapAlloc(0x1000), then publish the buffer and refill state. The
    // ordinary-heap adapter provides the actual OS heap allocation and bytes.
    memory.w32(kReadCount, memory.r32(kReadCount) + 1u);
    const auto buffer = heap.allocate(kBufferBytes);
    if (!buffer)
        throw std::runtime_error("0x380de3 draft is success-only; 4096-byte allocation failed");
    memory.w32(stream + 0x08u, buffer);
    memory.w32(stream + 0x0cu, memory.r32(stream + 0x0cu) | 0x08u);
    memory.w32(stream + 0x18u, kBufferBytes);
    memory.w32(stream + 0x04u, 0u);
    memory.w32(stream + 0x00u, buffer);

    const auto fd = memory.r32(stream + 0x10u);
    const auto record = descriptor_record(memory, fd);
    if (memory.r8(record + 4u) != 0x11u || memory.r32(record) == 0u ||
        memory.r32(record) == 0xffffffffu || memory.r32(record + 8u) == 0u)
        throw std::domain_error("0x380de3 draft requires a live binary disk descriptor with flags 0x11 and initialized-count nonzero");

    // 0x77439f validates the descriptor, locks record+0xc, calls 0x774404,
    // then unlocks. For exact flags 0x11, the accepted branch of 0x774404
    // forwards one real binary ReadFile request and returns its byte count.
    const auto lock = record + 0x0cu;
    file_ops.enter(lock);
    std::uint32_t bytes_read = 0;
    bool ok = false;
    try {
        ok = file_ops.read_file(memory.r32(record), buffer, kBufferBytes, bytes_read);
    } catch (...) {
        file_ops.leave(lock);
        throw;
    }
    file_ops.leave(lock);
    if (!ok || bytes_read <= 1u)
        throw std::domain_error("0x380de3 draft covers only successful binary reads returning more than one byte");

    // 0x780e33..0x780eb0: publish fetched count, return the first UTF-16LE
    // word, and leave the cursor at buffer+2 with count-2 still available.
    memory.w32(stream + 0x04u, bytes_read);
    const auto stream_flags = memory.r32(stream + 0x0cu);
    if ((stream_flags & 0x82u) != 0u)
        throw std::domain_error("0x380de3 draft excludes translation and device stream flags");
    if (bytes_read == 0u || bytes_read == 1u || bytes_read == 0xffffffffu)
        throw std::domain_error("0x380de3 draft requires the observed successful count branch");

    const auto value = heap.r8(buffer) | (heap.r8(buffer + 1u) << 8);
    memory.w32(stream + 0x04u, bytes_read - 2u);
    memory.w32(stream + 0x00u, buffer + 2u);
    return value;
}

} // namespace ra2::recovered::recovery_b333
