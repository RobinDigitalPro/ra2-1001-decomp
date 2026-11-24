#include "recovered/recovery_b827.hpp"
#include "recovered/recovery_b394.hpp"
#include <stdexcept>

namespace ra2::recovered::recovery_b827 {
namespace {
std::uint32_t original_op5_copy(Memory& m, std::uint32_t self,
                                std::uint32_t destination,
                                std::uint32_t bytes) {
    // Bounded portable semantics of the pinned original callback's op-5 arm.
    // This is deliberately not a generic or substitute callback dispatcher.
    if (m.r32(self + 0x40) != 0x00763ef0u)
        throw std::domain_error("B827 requires original callback 0x763EF0");
    const auto cache = m.r32(self + 0x6f4);
    const auto bound = m.r32(self + 0x700);
    const auto cursor = m.r32(self + 0x704);
    if (cursor > bound || bytes > bound - cursor)
        throw std::domain_error("B827 op-5 cache bound");
    for (std::uint32_t k = 0; k < bytes; ++k)
        m.w8(destination + k, m.r8(cache + cursor + k));
    m.w32(self + 0x704, cursor + bytes);
    return 0;
}
}

std::uint32_t fun_00766f60(Memory& m, const Inputs& i) {
    const auto self = i.cx;
    const auto input_bytes = i.dx;
    const auto format = m.r8(self + 0x3f);
    const auto channels = m.r8(self + 0x3e);
    if (!(m.r8(self + 0x84) & 1u) || format != 16u || channels != 1u ||
        !input_bytes || (input_bytes & 3u))
        throw std::domain_error("B827 bounded mono16 contract only");

    const auto output_bytes = (format >> 2) * input_bytes;
    const auto small_output = m.r32(self + 0x7a8);
    const auto large_output = m.r32(self + 0x78c);
    if (!small_output || !large_output)
        throw std::domain_error("B827 requires both initialized output buffers");

    const bool small = output_bytes <= m.r32(self + 0x7b4);
    std::uint32_t packed = 0;
    std::uint32_t decoded = 0;
    if (small) {
        const auto threshold = m.r32(self + 0x7b4);
        if (threshold < input_bytes)
            throw std::domain_error("B827 small-buffer range");
        packed = small_output + threshold - input_bytes;
        decoded = small_output;
    } else {
        if (m.r32(self + 0x790) != 0 || m.r32(self + 0x7ac) != 0)
            throw std::domain_error("B827 only the initial large-buffer block is covered");
        const auto tail = m.r32(self + 0x98);
        if (tail < input_bytes || !m.r32(self + 0x794) ||
            m.r32(self + 0x9c) != 16u)
            throw std::domain_error("B827 large-buffer initialized fields");
        packed = large_output + tail - input_bytes;
        decoded = large_output;
    }

    if (original_op5_copy(m, self, packed, input_bytes) != 0)
        throw std::domain_error("B827 original op-5 copy failed");

    Inputs child{};
    child.fp = i.fp;
    child.arg[0] = packed;
    child.arg[1] = decoded;
    child.arg[2] = format;
    child.arg[3] = channels;
    child.arg[4] = output_bytes;
    child.arg[5] = self + 0x7d0;
    const auto decoded_bytes = recovery_b394::fun_0076bec1(m, child);
    i.fp = child.fp;
    if (decoded_bytes != output_bytes)
        throw std::domain_error("B827 B394 output count mismatch");

    if (small) {
        m.w32(self + 0x7b0, output_bytes);
    } else {
        m.w32(self + 0x790, m.r32(self + 0x790) + output_bytes);
        const auto blocks = output_bytes / m.r32(self + 0x9c);
        const auto ready = m.r32(self + 0x794);
        for (std::uint32_t k = 0; k < blocks; ++k)
            m.w8(ready + k, 1);
    }
    return 0xffffffffu;
}
}
