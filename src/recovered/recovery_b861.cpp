#include "recovered/recovery_b861.hpp"

#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b861 {
namespace {
using Heap = ra2::platform::ordinary_heap::Heap;

void require(bool condition, const char* message) {
    if (!condition) throw std::domain_error(message);
}

bool disjoint(std::uint32_t a, std::uint32_t a_size,
              std::uint32_t b, std::uint32_t b_size) {
    const auto a_end = std::uint64_t(a) + a_size;
    const auto b_end = std::uint64_t(b) + b_size;
    return a_end <= b || b_end <= a;
}

std::uint32_t copy_record(Memory& memory, Heap& heap,
                          std::uint32_t destination, std::uint32_t source) {
    require(destination != 0u && source != 0u && destination != source,
            "B861 record copy requires distinct nonnull record addresses");
    heap.w32(destination, memory.r32(source));
    require(memory.r32(source + 4u) == 0u,
            "B861 finite route requires null first string pointer");
    heap.w32(destination + 4u, 0u);
    require(memory.r32(source + 8u) == 0u,
            "B861 finite route requires null second string pointer");
    heap.w32(destination + 8u, 0u);
    heap.w32(destination + 0x0cu, memory.r32(source + 0x0cu));
    heap.w32(destination + 0x10u, memory.r32(source + 0x10u));
    heap.w32(destination + 0x14u, memory.r32(source + 0x14u));
    return destination;
}

void grow_empty_vector(Memory& memory, std::uint32_t object, Heap& heap) {
    const auto count = memory.r32(object + 8u);
    const auto capacity = memory.r32(object + 0x0cu);
    const auto old_data = memory.r32(object + 0x10u);
    require(count == 0u && capacity == 0u && old_data == 0u,
            "B861 root must reach 0x1f9470 with the cleared empty header");

    // 0x5f9483 doubles count (zero), then clamps to ten; 0x5f9492..99
    // requests new_capacity*24 = 240 bytes through 0x76d957. That helper
    // selects its ordinary heap branch under the explicit zero small-block
    // threshold fixture used by this bounded interface contract.
    const auto fresh = heap.allocate(240u);
    require(fresh != 0u, "B861 success route requires 240-byte allocation");
    require(disjoint(object, 0x14u, fresh, 240u),
            "B861 vector storage must not overlap the receiver header");
    for (std::uint32_t offset = 0; offset < 240u; ++offset)
        heap.w8(fresh + offset, 0u);

    // The original calls 0x76d67b with the old null pointer; that wrapper
    // returns before any allocator API, so the Heap interface sees no release.
    memory.w32(object + 0x0cu, 10u);
    memory.w32(object + 0x10u, fresh);
}
}

std::uint32_t fun_005fa230(Memory& memory, const Inputs& inputs, Heap& heap) {
    const auto object = inputs.cx;
    const auto input = inputs.arg[0];
    require(object != 0u && input != 0u && object != input,
            "B861 append requires distinct nonnull object and input");
    require((inputs.arithmetic_flags & 0x400u) == 0u,
            "B861 finite route requires direction flag clear");

    const auto count = memory.r32(input + 8u);
    const auto source_records = memory.r32(input + 0x10u);
    require(count >= 1u && count <= 4u,
            "B861 finite positive route accepts 1..4 input records");
    require(source_records != 0u,
            "B861 finite route requires input record storage");
    const auto input_bytes = 0x10u + count * 24u;
    const auto source_bytes = count * 24u;
    require(disjoint(object, 0x14u, input, input_bytes) &&
                disjoint(object, 0x14u, source_records, source_bytes) &&
                disjoint(input, input_bytes, source_records, source_bytes),
            "B861 finite contract requires disjoint receiver and input spans");

    memory.w32(object, memory.r32(input));
    memory.w32(object + 4u, memory.r32(input + 4u));
    memory.w32(object + 8u, 0u);
    memory.w32(object + 0x0cu, 0u);
    memory.w32(object + 0x10u, 0u);
    grow_empty_vector(memory, object, heap);

    for (std::uint32_t index = 0; index < count; ++index) {
        const auto source = source_records + index * 24u;
        require(memory.r32(source + 4u) == 0u &&
                    memory.r32(source + 8u) == 0u,
                "B861 finite route excludes nonempty owned string inputs");
        const auto destination = memory.r32(object + 0x10u) + index * 24u;
        (void)copy_record(memory, heap, destination, source);
        memory.w32(object + 8u, index + 1u);
    }
    return object;
}
}
