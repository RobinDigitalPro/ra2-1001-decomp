#include "recovered/recovery_b265.hpp"
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

void fun_004284e0(Memory& m, State& s, OrdinaryHeap& heap) {
    const auto self=s.cx;
    for(const auto off:std::array<std::uint32_t,4>{{0x18u,0x1cu,0x24u,0x20u}})
        free_nonnull_field(m,s,heap,self,off);
    const auto descriptor=s.arg[0];
    const auto side=m.r32(descriptor+0xcu)+m.r32(descriptor+8u)+1u;
    s.ax=side;
    m.w32(0x00836b4cu,side);
    const auto bytes=side*side*4u;
    const auto p1=heap.allocate(bytes); m.w32(self+0x1cu,p1);
    const auto p2=heap.allocate(bytes); m.w32(self+0x18u,p2);
    const auto p3=heap.allocate(bytes); m.w32(self+0x24u,p3);
    const auto p4=heap.allocate(bytes); m.w32(self+0x20u,p4);
    m.w32(0x00834b78u,0u-side);
    m.w32(0x00834b84u,side+1u);
    m.w32(0x00834b7cu,1u-side);
    m.w32(0x00834b80u,1u);
    m.w32(0x00834b88u,side);
    m.w32(0x00834b8cu,side-1u);
    m.w32(0x00834b90u,0xffffffffu);
    m.w32(0x00834b94u,0xffffffffu-side);
    s.ax=side;
}
}
