#include "recovery42_cleanup.hpp"

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

void fun_006de930(Memory& m, State& s, OrdinaryHeap& heap) {
    global_vector_family(m,s,heap,0xf4u,0xfcu,0xf8u,0xf0u);
}
void fun_006defc0(Memory& m, State& s, OrdinaryHeap& heap) {
    const auto self=s.cx;
    clear_vector_and_release(m,s,heap,self,0xf4u);
    free_nonnull_field(m,s,heap,self,0xfcu);
    free_nonnull_field(m,s,heap,self,0xf8u);
    m.w32(self+0xf0u,0);
}
void fun_006df3f0(Memory& m, State& s, OrdinaryHeap& heap) {
    global_vector_family(m,s,heap,0x110u,0x118u,0x114u,0x10cu);
}
void fun_00706850(Memory& m, State& s, OrdinaryHeap& heap) {
    const auto self=s.cx;
    clear_vector_and_release(m,s,heap,self,0x9cu);
    free_nonnull_field(m,s,heap,self,0xa0u);
    free_nonnull_field(m,s,heap,self,0xb0u);
    m.w32(self+0x98u,0);
}
}
