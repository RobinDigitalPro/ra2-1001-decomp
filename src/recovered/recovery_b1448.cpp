#include "recovered/recovery_b1448.hpp"
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::b1448 {
namespace {
struct PrivateVectorScratch {
    std::uint32_t vptr;
    std::uint32_t word_04;
    std::uint32_t word_08;
    std::uint8_t byte_0c;
    std::uint8_t byte_0d;
};

bool overlaps(std::uint32_t a, std::uint32_t a_size,
              std::uint32_t b, std::uint32_t b_size) {
    const auto ae = std::uint64_t(a) + a_size;
    const auto be = std::uint64_t(b) + b_size;
    return std::uint64_t(a) < be && std::uint64_t(b) < ae;
}
}

std::uint32_t fun_004ef8c0(Memory& m, const Inputs& i) {
    const std::uint32_t owner = i.cx;
    const std::uint32_t out = i.arg[0];
    const std::uint32_t type = i.arg[1];
    if (owner == 0u || type == 0u || out == 0u)
        throw std::domain_error("1448 requires the selected nonnull owner, type, and output pointers");
    if (overlaps(out, 4u, owner, 0x5644u) ||
        overlaps(out, 4u, type, 0x0adbu) ||
        overlaps(owner, 0x5644u, type, 0x0adbu))
        throw std::domain_error("1448 finite fixture requires disjoint owner/type/output spans");

    // The original reads type+0xADA as arg1's route selector.
    if (m.r8(type + 0x0adau) != 0u)
        throw std::domain_error("1448 supports the original type byte ADA == 0 route only");

    // Original 0x42D4A0(0,0) initializes this private stack vector. The two
    // selected helper bodies write only this local shape; with word_04 == 0,
    // 0x42CFB0 takes its no-release path and clears word_08/byte_0d. No part
    // of this temporary escapes into observable Memory.
    PrivateVectorScratch vector{0x007875e0u, 0u, 0u, 1u, 0u};

    if (m.r16(owner + 0x5640u) != 0u || m.r16(owner + 0x5642u) != 0u)
        throw std::domain_error("1448 supports the original packed owner words 5640/5642 == 0 route only");

    // The selected original route uses signed coordinates, but its finite
    // domain is positive: raw centers are (cell * 256) + 128 for cells 5..36
    // and 7..38. Division by 256 therefore matches the original truncating
    // conversion exactly on this reviewed domain.
    const std::uint32_t raw_x = m.r32(owner + 0x53bcu);
    const std::uint32_t raw_y = m.r32(owner + 0x53c0u);
    if (m.r32(owner + 0x53c4u) != 0u ||
        raw_x < (5u * 256u + 128u) || raw_x > (36u * 256u + 128u) ||
        raw_y < (7u * 256u + 128u) || raw_y > (38u * 256u + 128u) ||
        ((raw_x - 128u) & 0xffu) != 0u || ((raw_y - 128u) & 0xffu) != 0u)
        throw std::domain_error("1448 supports only the reviewed positive center projection");

    const std::uint32_t cell_x = raw_x / 256u;
    const std::uint32_t cell_y = raw_y / 256u;
    const std::uint32_t packed = (cell_x & 0xffffu) | ((cell_y & 0xffffu) << 16u);
    m.w32(out, packed);

    // The actual 0x42CFB0 call is represented by its proved selected local
    // effect. Its owned pointer is zero, so no release or persistent write is
    // reached; the remaining field resets are private stack state only.
    vector.byte_0d = 0u;
    vector.word_08 = 0u;
    (void)vector;
    return out;
}
}
