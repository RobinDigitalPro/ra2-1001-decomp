#include "recovered/recovery_b485.hpp"
#include "recovered/name_hash.hpp"

#include <stdexcept>

namespace ra2::recovered::recovery_b485 {
namespace {
void need(bool ok, const char* why) {
    if (!ok) throw std::domain_error(why);
}

std::uint32_t duplicate_filename(Memory& m, std::uint32_t source, Heap& heap) {
    need(source != 0, "B485 positive filename route requires a nonnull source");
    std::uint32_t length = 0;
    for (; length < 0x10000u; ++length) {
        if (m.r8(source + length) == 0) break;
    }
    need(length < 0x10000u, "B485 filename is not terminated within the bounded span");
    need(length >= 1020u, "B485 ordinary-heap route requires a long filename");
    const auto bytes = length + 1u;
    const auto copy = heap.allocate(bytes);
    need(copy != 0, "B485 excludes ordinary-heap allocation failure");
    for (std::uint32_t j = 0; j < bytes; ++j) heap.w8(copy + j, m.r8(source + j));
    return copy;
}

// Exact successful path of accepted 0x230110 with an ordinary-sized
// nonempty filename: 0x36df28 releases the prior owned pointer when the
// ownership flag is set; 0x779146 duplicates the input and stores it at +14.
std::uint32_t assign_filename(Memory& m, std::uint32_t self,
                              std::uint32_t source, Heap& heap) {
    const auto prior = m.r32(self + 0x14u);
    if (prior != 0u && m.r8(self + 0x1cu) != 0u) {
        (void)heap.release(prior);
        m.w32(self + 0x14u, 0u);
        m.w8(self + 0x1cu, 0u);
    }
    if (source == 0u) return 0u;
    // The pinned 0x230110 body initializes these fields immediately before
    // its nonnull 0x779146 duplicate call.
    m.w32(self + 0x08u, 0u);
    m.w32(self + 0x0cu, 0xffffffffu);
    const auto copy = duplicate_filename(m, source, heap);
    m.w32(self + 0x14u, copy);
    m.w8(self + 0x1cu, 1u);
    return copy;
}

std::uint32_t getter(Memory& m, std::uint32_t self) {
    need(m.r32(self) == 0x78773cu, "B485 authentic object vptr required");
    need(m.r32(0x787740u) == 0x401940u, "B485 pinned getter slot target required");
    return m.r32(self + 0x14u);
}

bool same_filename(Memory& m, Heap& heap, std::uint32_t source,
                   std::uint32_t old_name) {
    for (std::uint32_t j = 0; j < 0x10000u; ++j) {
        const auto a = m.r8(source + j);
        const auto b = heap.r8(old_name + j);
        if (a != b) return false;
        if (a == 0u) return true;
    }
    throw std::domain_error("B485 bounded filename comparison lacks a terminator");
}
}

std::uint32_t fun_0042f100(Memory& m, const Inputs& in, Heap& heap) {
    const auto self = in.cx;
    const auto zero = 0u;
    const auto minus_one = 0xffffffffu;
    m.w32(self + 0x04u, 1u);
    m.w32(self + 0x08u, zero);
    m.w32(self + 0x0cu, minus_one);
    m.w32(self + 0x10u, minus_one);
    m.w32(self + 0x14u, zero);
    m.w16(self + 0x18u, 0u);
    m.w16(self + 0x1au, 0u);
    m.w8(self + 0x1cu, 0u);
    m.w8(self + 0x20u, 0u);
    m.w8(self + 0x21u, 0u);
    m.w8(self + 0x22u, 0u);
    m.w8(self + 0x23u, 0u);
    m.w8(self + 0x24u, 0u);
    m.w8(self + 0x25u, 0u);
    for (const auto off : {0x28u, 0x2cu, 0x30u, 0x34u, 0x38u, 0x44u, 0x48u, 0x4cu})
        m.w32(self + off, 0u);
    m.w32(self + 0x3cu, minus_one);
    m.w32(self + 0x40u, minus_one);
    m.w32(self, 0x78773cu);

    // Original constructor's getter returns the newly initialized null +14.
    (void)getter(m, self);
    (void)assign_filename(m, self, in.arg[0], heap);
    (void)getter(m, self);
    return self;
}

std::uint32_t fun_0042f550(Memory& m, const Inputs& in, Heap& heap) {
    const auto self = in.cx;
    need(m.r32(self) == 0x78773cu, "B485 authentic object vptr required");
    const auto old_name = getter(m, self);
    if (old_name != 0u && m.r8(self + 0x25u) != 0u &&
        same_filename(m, heap, in.arg[0], old_name)) {
        return getter(m, self);
    }

    // 0x2f4a0 returns at its exact clean-buffer guard when +24 is zero.
    if (old_name != 0u && m.r8(self + 0x25u) != 0u) {
        need(m.r8(self + 0x24u) == 0u,
             "B485 only composes the original clean-buffer guard route");
        m.w8(self + 0x23u, 0u);
    }
    (void)assign_filename(m, self, in.arg[0], heap);
    return getter(m, self);
}
}
