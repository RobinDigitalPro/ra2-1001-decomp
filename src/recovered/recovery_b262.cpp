#include "recovered/recovery_b262.hpp"
#include <array>
#include <cstdint>
#include <limits>
#include <stdexcept>

namespace ra2::recovered::recovery42_cleanup {
namespace {
void release(Memory& m, State& s, OrdinaryHeap& heap, std::uint32_t p) {
    s.ax = heap.release(p);
    s.cx = p; // Wrapper 0x36d67b restores the forwarded pointer into ECX.
    (void)m;
}

void free_nonnull_field(Memory& m, State& s, OrdinaryHeap& heap,
                        std::uint32_t object, std::uint32_t field) {
    const auto p = m.r32(object + field);
    s.ax = p;
    if (p != 0) release(m, s, heap, p);
    m.w32(object + field, 0);
}

void clear_vector_and_release(Memory& m, State& s, OrdinaryHeap& heap,
                              std::uint32_t object, std::uint32_t descriptor_offset) {
    auto descriptor = m.r32(object + descriptor_offset);
    s.ax = descriptor;
    if (descriptor == 0) return;
    auto count = heap.r32(descriptor);
    s.ax = count;
    if (static_cast<std::int32_t>(count) >= 0) {
        const auto backing = heap.r32(descriptor + 8u);
        s.ax = backing;
        for (std::uint32_t i = 0; i <= count; ++i) {
            heap.w32(backing + i * 4u, 0);
        }
    }
    heap.w32(descriptor, 0);
    descriptor = m.r32(object + descriptor_offset);
    s.ax = descriptor;
    if (descriptor != 0) {
        const auto backing = heap.r32(descriptor + 8u);
        s.ax = backing;
        release(m, s, heap, backing);
        release(m, s, heap, descriptor);
    }
    m.w32(object + descriptor_offset, 0);
}

void global_vector_family(Memory& m, State& s, OrdinaryHeap& heap,
                          std::uint32_t descriptor_offset,
                          std::uint32_t owner_a, std::uint32_t owner_b,
                          std::uint32_t count_offset) {
    const auto count = m.r32(0x00aa8648u);
    s.ax = count;
    for (std::uint32_t i = 0; static_cast<std::int32_t>(i) <
                             static_cast<std::int32_t>(count); ++i) {
        const auto table = m.r32(0x00aa863cu);
        s.ax = table;
        const auto object = m.r32(table + i * 4u);
        s.ax = object;
        clear_vector_and_release(m, s, heap, object, descriptor_offset);
        free_nonnull_field(m, s, heap, object, owner_a);
        free_nonnull_field(m, s, heap, object, owner_b);
        m.w32(object + count_offset, 0);
        s.ax = m.r32(0x00aa8648u);
    }
}

struct Format { unsigned red, green, blue; };
constexpr std::array<Format, 4> formats{{{10,5,0}, {11,6,1}, {11,6,0}, {11,5,0}}};
}

void fun_00429a90(Memory& m, State& s, OrdinaryHeap& heap) {
    const auto self = s.cx;
    constexpr std::array<std::uint32_t,3> base_fields{{0x40u,0x44u,0x48u}};
    constexpr std::array<std::uint32_t,3> dimensions{{0x81a890u,0x81a894u,0x81a898u}};
    for (unsigned i=0; i<3; ++i) {
        const auto count = m.r32(dimensions[i]);
        s.ax = count;
        if (count > std::numeric_limits<std::uint32_t>::max()/4u)
            throw std::overflow_error("0x29a90 selected count range excludes request overflow");
        const auto bytes = count * 4u;
        for (const auto delta : std::array<std::uint32_t,3>{{0u,0x0cu,0x18u}}) {
            const auto field = base_fields[i] + delta;
            const auto old = m.r32(self + field);
            s.ax = old;
            if (old != 0) release(m, s, heap, old);
            const auto p = heap.allocate(bytes);
            s.ax = p;
            m.w32(self + field, p);
            for (std::uint32_t n=0; n<count; ++n) heap.w32(p + n*4u, 0);
            s.ax = count ? p - 4u : p; // Zero-loop post-decrement leaves EAX at base-4 when count is positive.
        }
    }
}
}
