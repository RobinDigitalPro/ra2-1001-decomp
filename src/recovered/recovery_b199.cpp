// Bounded Block 199 translation: original D0B50 positive lookup through the actual
// 282140 -> 359260 / 2814E0 / 3593B0 / 359320 closure. Bounded raw table
// state and the one request-9 temporary are supplied by the fixture/Heap.
#include "recovered/recovery_b199.hpp"

#include <array>
#include <stdexcept>

namespace ra2::recovered::recovery_b199 {
namespace {
constexpr std::uint32_t kTable = 0x00a5ded0u;
constexpr std::uint32_t kCacheReady = 0x00aa4be8u;
constexpr std::uint32_t kResult = 0x00aa4bf0u;
constexpr std::uint32_t kHash = 0x006814e0u;
constexpr std::uint32_t kNodeNext = 0x308u;

std::uint32_t bounded_length(const Memory& memory, std::uint32_t text) {
    for (std::uint32_t n = 0; n < 9u; ++n)
        if (memory.r8(text + n) == 0) return n;
    throw std::domain_error("B199 original query must terminate in its nine-byte bound");
}

std::uint32_t bounded_length(const Heap& heap, std::uint32_t text) {
    for (std::uint32_t n = 0; n < 9u; ++n)
        if (heap.r8(text + n) == 0) return n;
    throw std::domain_error("B199 temporary string must terminate in its nine-byte bound");
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
            throw std::domain_error("B199 comparator input exceeded nine-byte bound");
        const auto a1 = memory.r8(original + n + 1u);
        const auto b1 = heap.r8(temporary + n + 1u);
        if (a1 != b1) return false;
        if (a1 == 0) return true;
    }
    throw std::domain_error("B199 comparator input exceeded nine-byte bound");
}

std::uint32_t lookup_282140(Memory& memory, Heap& heap,
                            std::uint32_t key_pointer) {
    // 359260's bounded C-string constructor: request strlen+1, then copy the
    // bytes including NUL into the actual CRT allocation.
    const auto length = bounded_length(memory, key_pointer);
    if (length != 8u) throw std::domain_error("B199 requires an original eight-byte key");
    const auto temporary = heap.allocate(length + 1u);
    heap.w8(temporary, 0);
    for (std::uint32_t n = 0; n <= length; ++n)
        heap.w8(temporary + n, memory.r8(key_pointer + n));

    // The campaign fixture supplies the authentic initialized hash object,
    // including the constructor-proven callback target and a positive chain.
    if ((memory.r8(kCacheReady) & 1u) == 0)
        throw std::domain_error("B199 excludes the unrelated one-time registration path");
    if (memory.r32(kTable + 0x18u) != kHash)
        throw std::domain_error("B199 requires the constructor-proven hash callback");
    memory.w32(kResult, 0);

    const auto bucket_array = memory.r32(kTable);
    const auto bucket_count = memory.r32(kTable + 4u);
    const auto shift = memory.r32(kTable + 0x0cu);
    if (!bucket_array || !bucket_count || shift != 7u)
        throw std::domain_error("B199 raw 128-bucket table prestate differs");
    const auto hash_value = hash_2814e0(heap, temporary);
    auto node = memory.r32(bucket_array + ((hash_value & 127u) * 4u));
    std::uint32_t examined = 0;
    while (node) {
        if (++examined > 10u)
            throw std::domain_error("B199 bucket chain exceeded the supplied node count");
        if (equal_3593b0(memory, heap, node, temporary)) {
            // REP MOVSD, 0xC1 DWORDs from node+4 to the global result record.
            for (std::uint32_t n = 0; n < 0xc1u; ++n)
                memory.w32(kResult + n * 4u, memory.r32(node + 4u + n * 4u));
            break;
        }
        node = memory.r32(node + kNodeNext);
    }
    const auto result = memory.r32(kResult);
    // 359320 destroys the temporary; request 9 rounds to the same class-1
    // span handled by the parent's narrow Block 173 terminal-release arm.
    heap.release(temporary);
    return result;
}
} // namespace

std::uint32_t fun_004d0b50(Memory& memory, const Inputs& input, Heap& heap) {
    std::uint32_t index;
    if (input.cx == 0xfffffffeu) index = 0;
    else if (input.cx <= 8u) index = input.cx + 1u;
    else throw std::domain_error("B199 fixture selector is outside the ten original switch leaves");
    // Preserve D0B50's absolute DWORD reads from the original pointer table.
    const auto key_pointer = memory.r32(0x007e1f28u + index * 4u);
    return lookup_282140(memory, heap, key_pointer);
}
} // namespace ra2::recovered::recovery_b199
