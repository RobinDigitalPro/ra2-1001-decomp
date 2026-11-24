#include "recovery_b127.hpp"

#include <stdexcept>

namespace ra2::recovered::recovery_b127 {
namespace {
void require(bool condition, const char* message) {
    if (!condition) throw std::domain_error(message);
}

// Reached helper RVA 0x7380: the circular-list unlink, including its final
// self-links. This accesses tracked heap objects, not the caller's arena.
std::uint32_t list_unlink(Heap& h, std::uint32_t node) {
    const auto next = h.r32(node);
    const auto previous = h.r32(node + 4u);
    h.w32(previous, next);
    const auto next_again = h.r32(node);
    const auto previous_again = h.r32(node + 4u);
    h.w32(next_again + 4u, previous_again);
    h.w32(node, node);
    h.w32(node + 4u, node);
    return next_again;
}

// Reached helper RVA 0x8850, with [descriptor+0x28] == 0. The non-null table
// path is outside this entry contract; this is the helper's complete null path.
void reset_empty_descriptor(Heap& h, std::uint32_t descriptor) {
    const auto buffer = h.r32(descriptor + 0x28u);
    h.w32(descriptor + 0x2cu, 0u);
    h.w32(descriptor + 0x0cu, buffer);
    require(buffer == 0u, "0x8760 draft is contracted to null cursor buffers");
    h.w32(descriptor + 4u, 0u);
    h.w32(descriptor + 8u, 0u);
    h.w32(descriptor + 0x10u, h.r32(descriptor + 0x10u) & 0xfffffffeu);
}

// Original wrapper RVA 0x36d67b reaches the accepted CRT/OS HeapFree closure.
// Preserve the actual Win32 BOOL in EAX instead of substituting success.
std::uint32_t original_free(Heap& h, std::uint32_t pointer) {
    return h.release(pointer);
}
} // namespace

std::uint32_t fun_00408760(Memory& m, const Inputs& i, Heap& h) {
    const auto root = i.cx;
    require(root != 0u, "0x8760 requires the caller-owned tracked root");
    const auto sentinel = root + 4u;
    auto node = h.r32(sentinel);

    // Original loop: unlink each node; apply its shared-header mutations; free
    // any optional payload, then the node. The concrete fixture has one node
    // and a null optional payload.
    while (node != sentinel) {
        (void)list_unlink(h, node);
        const auto header = h.r32(node + 0x30u);
        h.w32(node + 0x30u, 0u);
        const auto references = m.r32(header);
        const auto amount = m.r32(header + 0x14u);
        m.w32(header, references - 1u);
        const auto decrement = h.r32(node + 0x1cu);
        m.w32(header + 0x14u, amount - decrement);
        const auto flags = m.r32(header + 0x10u);
        m.w32(header + 0x10u, flags & 0xfffffffdu);

        const auto payload = h.r32(node + 0x10u);
        if (payload) (void)original_free(h, payload);
        (void)original_free(h, node);
        node = h.r32(sentinel);
    }

    // Empty list makes EBP=0. The original initializes each embedded
    // descriptor's table buffer to null before entering helper 0x8850.
    h.w32(root + 0x40u, 0u);
    h.w32(root + 0x4cu, 0xfffffc17u);
    h.w32(root + 0x50u, 0xfffffc17u);
    h.w32(root + 0x48u, 0u);
    reset_empty_descriptor(h, root + 0x18u);

    h.w32(root + 0x80u, 0u);
    h.w32(root + 0x8cu, 0xfffffc17u);
    h.w32(root + 0x90u, 0xfffffc17u);
    h.w32(root + 0x88u, 0u);
    reset_empty_descriptor(h, root + 0x58u);

    // The final ADD uses the original root+0x14 value. Root is then freed;
    // these root-local writes are intentionally not retained by the fixture.
    h.w32(root + 0x4cu, h.r32(root + 0x4cu) + h.r32(root + 0x14u));
    return original_free(h, root);
}
} // namespace ra2::recovered::recovery_b127
