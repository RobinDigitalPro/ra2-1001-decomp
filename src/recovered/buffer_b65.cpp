#include "buffer_b65.hpp"

#include <algorithm>
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::global_b26 {
namespace {

// These wrappers cover the original direct-buffer route only.  The original
// allocator, owned-buffer release, and zero-count virtual-call routes remain
// outside this finite contract.
std::uint32_t resize_supplied(Memory& m, const Inputs& i,
                              unsigned stride, bool clamp_high_water,
                              bool count_residue) {
    const std::uint32_t object = i.cx;
    const std::uint32_t count = i.arg[0];
    const std::uint32_t destination = i.arg[1];
    if (!destination || s32(count) <= 0 || count > 512u)
        throw std::domain_error("Block65 requires a positive bounded count and supplied destination");
    if (std::uint64_t(object) + 0x14u > 0x100000000ull)
        throw std::domain_error("Block65 object span wraps guest address space");

    const auto old_pointer = m.r32(object + 4u);
    const auto old_count = m.r32(object + 8u);
    const auto owner = m.r8(object + 0x0du);
    if (old_pointer && owner != 0u)
        throw std::domain_error("Block65 owned-buffer release route is outside the supplied-buffer contract");
    if (old_pointer && (s32(old_count) < 0 || old_count > 512u))
        throw std::domain_error("Block65 old element count is outside the bounded contract");

    const std::uint32_t copied = old_pointer
        ? std::min(count, old_count)
        : 0u;
    const std::uint64_t object_begin = object;
    const std::uint64_t object_end = object_begin + 0x14u;
    const std::uint64_t dst_begin = destination;
    const std::uint64_t dst_end = dst_begin + std::uint64_t(count) * stride;
    const std::uint64_t src_begin = old_pointer;
    const std::uint64_t src_end = src_begin + std::uint64_t(copied) * stride;
    if (dst_end > 0x100000000ull ||
        (dst_begin < object_end && object_begin < dst_end) ||
        (old_pointer && copied && src_end > 0x100000000ull) ||
        (old_pointer && copied && src_begin < object_end && object_begin < src_end))
        throw std::domain_error("Block65 requires mapped, non-object-overlapping element spans");
    if (old_pointer && copied && old_pointer != destination &&
        dst_begin < src_end && src_begin < dst_end)
        throw std::domain_error("Block65 excludes partial source/destination overlap");

    // MOV byte [this+0xc],0 followed by the direct-buffer success flag.
    m.w8(object + 0x0cu, 0u);
    m.w8(object + 0x0cu, 1u);

    // Original loops copy forward. Exact alias is valid and preserves the
    // same per-element read/write order; partial overlap is excluded above.
    for (std::uint32_t n = 0; n < copied; ++n) {
        const auto src = old_pointer + n * stride;
        const auto dst = destination + n * stride;
        for (unsigned word = 0; word < stride; word += 4u)
            m.w32(dst + word, m.r32(src + word));
    }

    m.w32(object + 4u, destination);
    m.w32(object + 8u, count);
    m.w8(object + 0x0du, 0u);

    if (clamp_high_water) {
        const auto high_water = m.r32(object + 0x10u);
        if (s32(count) < s32(high_water)) m.w32(object + 0x10u, count);
    }

    // Most bodies reload count into EAX before MOV AL,1. Three 4-byte
    // unclamped clones and the 8-byte clone zero EAX before setting AL.
    return count_residue ? ((count & 0xffffff00u) | 1u) : 1u;
}

} // namespace

#define B65_FN(name, stride, clamp, residue) \
    std::uint32_t name(Memory& m, const Inputs& i) { \
        return resize_supplied(m, i, stride, clamp, residue); \
    }

B65_FN(fun_0046ce50, 4u, true, true)
B65_FN(fun_0040cd40, 4u, true, true)
B65_FN(fun_004f6690, 4u, true, true)
B65_FN(fun_00491040, 4u, true, true)
B65_FN(fun_004d97c0, 4u, true, true)
B65_FN(fun_00454050, 4u, true, true)
B65_FN(fun_0046d180, 4u, true, true)
B65_FN(fun_004cdd40, 4u, true, true)
B65_FN(fun_0058b680, 4u, true, true)
B65_FN(fun_0064a830, 4u, true, true)
B65_FN(fun_00669540, 4u, true, true)
B65_FN(fun_0042b040, 4u, true, true)
B65_FN(fun_00453cd0, 4u, true, true)
B65_FN(fun_004933a0, 4u, true, true)
B65_FN(fun_004d53c0, 4u, true, true)
B65_FN(fun_004d5620, 4u, true, true)
B65_FN(fun_004d5fa0, 4u, true, true)
B65_FN(fun_004d7b40, 4u, true, true)
B65_FN(fun_004d9c80, 4u, true, true)
B65_FN(fun_004de7d0, 4u, true, true)
B65_FN(fun_004fa040, 4u, true, true)
B65_FN(fun_004fa7e0, 4u, true, true)
B65_FN(fun_0058ae90, 4u, true, true)
B65_FN(fun_0058b250, 4u, true, true)
B65_FN(fun_005ae980, 4u, true, true)
B65_FN(fun_005aebe0, 4u, true, true)
B65_FN(fun_005b5eb0, 4u, true, true)
B65_FN(fun_005fcb20, 4u, true, true)
B65_FN(fun_0064ab40, 4u, true, true)
B65_FN(fun_00680360, 4u, true, true)
B65_FN(fun_004b9eb0, 4u, true, true)
B65_FN(fun_004d5d40, 4u, true, true)
B65_FN(fun_004da140, 4u, true, true)

B65_FN(fun_0040b8b0, 4u, false, false)
B65_FN(fun_0046ccb0, 4u, false, false)
B65_FN(fun_005688b0, 4u, false, false)
B65_FN(fun_0058b7a0, 8u, false, false)
B65_FN(fun_0042cce0, 16u, true, true)

#undef B65_FN
} // namespace ra2::recovered::global_b26
