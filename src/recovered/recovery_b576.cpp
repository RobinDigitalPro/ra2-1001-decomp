// Bounded standalone282140 positive lookup through the actual
// 282140 -> 359260 / 2814E0 / 3593B0 / 359320 closure. Bounded raw table
// state and the one request-9 temporary are supplied by the fixture/Heap.
#include "recovered/recovery_b576.hpp"

#include <array>
#include <stdexcept>

namespace ra2::recovered::recovery_b576 {
namespace {
constexpr std::uint32_t kCacheReady = 0x00aa4be8u;
constexpr std::uint32_t kResult = 0x00aa4bf0u;
constexpr std::uint32_t kHash = 0x006814e0u;
constexpr std::uint32_t kNodeNext = 0x308u;

std::uint32_t bounded_length(const Memory& memory, std::uint32_t text) {
    for (std::uint32_t n = 0; n < 9u; ++n)
        if (memory.r8(text + n) == 0) return n;
    throw std::domain_error("B576 original query must terminate in its nine-byte bound");
}

std::uint32_t bounded_length(const Heap& heap, std::uint32_t text) {
    for (std::uint32_t n = 0; n < 9u; ++n)
        if (heap.r8(text + n) == 0) return n;
    throw std::domain_error("B576 temporary string must terminate in its nine-byte bound");
}

std::uint32_t hash_2814e0(const Heap& heap, std::uint32_t text) {
    // The original callback receives the temporary string object's address.
    // For this route its two reached helpers reduce to reading the object's
    // nonnull data pointer, then strlen/data access; `text` is that data pointer.
    const auto length = bounded_length(heap, text);
    std::uint32_t value = length;
    for (std::uint32_t n = 0; n < length; ++n) {
        const auto byte = heap.r8(text + n);
        const auto signed_byte = (byte & 0x80u) ? (byte | 0xffffff00u) : byte;
        value += signed_byte + n;
        value = (value << 8u) ^ (value >> 24u);
    }
    return value;
}

bool equal_3593b0(const Memory& memory, const Heap& heap,
                  std::uint32_t node, std::uint32_t temporary) {
    auto original = memory.r32(node);
    // Original compares two byte pairs per loop (+2/+2), checking NUL after
    // each equal byte. This is bytewise equality, with a bounded nine-byte key.
    for (std::uint32_t n = 0; n < 9u; n += 2u) {
        const auto a = memory.r8(original + n);
        const auto b = heap.r8(temporary + n);
        if (a != b) return false;
        if (a == 0) return true;
        if (n == 8u)
            throw std::domain_error("B576 comparator input exceeded nine-byte bound");
        const auto a1 = memory.r8(original + n + 1u);
        const auto b1 = heap.r8(temporary + n + 1u);
        if (a1 != b1) return false;
        if (a1 == 0) return true;
    }
    throw std::domain_error("B576 comparator input exceeded nine-byte bound");
}

std::uint32_t lookup_282140(Memory& memory, Heap& heap,
                            std::uint32_t table, std::uint32_t key_pointer,
                            std::uint32_t output_pointer) {
    // 359260's bounded C-string constructor: request strlen+1, then copy the
    // bytes including NUL into the actual CRT allocation.
    const auto length = bounded_length(memory, key_pointer);
    if (length != 8u) throw std::domain_error("B576 requires an original eight-byte key");
    const auto temporary = heap.allocate(length + 1u);
    heap.w8(temporary, 0);
    for (std::uint32_t n = 0; n <= length; ++n)
        heap.w8(temporary + n, memory.r8(key_pointer + n));

    // The campaign fixture supplies the authentic initialized hash object,
    // including the constructor-proven callback target and a positive chain.
    if ((memory.r8(kCacheReady) & 1u) == 0)
        throw std::domain_error("B576 excludes the unrelated one-time registration path");
    if (memory.r32(table + 0x18u) != kHash)
        throw std::domain_error("B576 requires the constructor-proven hash callback");
    memory.w32(kResult, 0);

    const auto bucket_array = memory.r32(table);
    const auto bucket_count = memory.r32(table + 4u);
    const auto shift = memory.r32(table + 0x0cu);
    if (!bucket_array || !bucket_count || shift != 7u)
        throw std::domain_error("B576 raw 128-bucket table prestate differs");
    const auto hash_value = hash_2814e0(heap, temporary);
    auto node = memory.r32(bucket_array + ((hash_value & 127u) * 4u));
    std::uint32_t examined = 0;
    while (node) {
        if (++examined > 10u)
            throw std::domain_error("B576 bucket chain exceeded the supplied node count");
        if (equal_3593b0(memory, heap, node, temporary)) {
            // REP MOVSD, 0xC1 DWORDs from node+4 to the global result record.
            for (std::uint32_t n = 0; n < 0xc1u; ++n)
                memory.w32(kResult + n * 4u, memory.r32(node + 4u + n * 4u));
            break;
        }
        node = memory.r32(node + kNodeNext);
    }
    const auto result = memory.r32(kResult);
    // Root 282140 copies 0xc0 dwords from result+4 when stack arg1 is nonnull.
    if (output_pointer != 0u)
        for (std::uint32_t n = 0; n < 0xc0u; ++n)
            memory.w32(output_pointer + n * 4u, memory.r32(kResult + 4u + n * 4u));
    // 359320 destroys the temporary; request 9 rounds to the same class-1
    // span handled by the parent's narrow Block 173 terminal-release arm.
    heap.release(temporary);
    return result;
}
} // namespace

std::uint32_t fun_00682140(Memory& memory, Inputs& input, Heap& heap) {
    const auto result = lookup_282140(memory, heap, input.cx, input.arg[0], input.arg[1]);
    input.arg[0] = 0u; // Original 359320 clears the root's overwritten stack arg0.
    return result;
}
} // namespace ra2::recovered::recovery_b576
