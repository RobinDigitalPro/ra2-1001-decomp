#include "recovered/recovery_b131.hpp"

#include <stdexcept>

namespace ra2::recovered::recovery_b131 {
namespace {
void require(bool condition, const char* message) {
    if (!condition) throw std::domain_error(message);
}

// Exact reached effects of helper RVA 0x7380 for the mixed storage route:
// list links live in Memory (the root is arena-backed); node links/self-links
// live in this per-side Heap.
std::uint32_t unlink_one(Memory& m, Heap& h, std::uint32_t node) {
    const auto next = h.r32(node);
    const auto previous = h.r32(node + 4u);
    m.w32(previous, next);
    const auto next_again = h.r32(node);
    const auto previous_again = h.r32(node + 4u);
    m.w32(next_again + 4u, previous_again);
    h.w32(node, node);
    h.w32(node + 4u, node);
    return next_again;
}

std::uint32_t release_via_original_crt(Heap& h, std::uint32_t pointer) {
    // Original call target 0x36d67b -> 0x36df28 -> ordinary HeapFree path.
    return h.release(pointer);
}
} // namespace

std::uint32_t fun_00408890(Memory& m, const Inputs& i, Heap& h) {
    const auto root = i.cx;
    require(root != 0u, "0x8890 requires caller-owned arena root");
    const auto sentinel = root + 4u;
    auto node = m.r32(sentinel);

    while (node != sentinel) {
        (void)unlink_one(m, h, node);

        const auto header = h.r32(node + 0x30u);
        h.w32(node + 0x30u, 0u);
        const auto references = m.r32(header);
        const auto amount = m.r32(header + 0x14u);
        m.w32(header, references - 1u);
        const auto decrement = h.r32(node + 0x1cu);
        m.w32(header + 0x14u, amount - decrement);
        const auto flags = m.r32(header + 0x10u);
        m.w32(header + 0x10u, flags & 0xfffffffdu);

        const auto optional_payload = h.r32(node + 0x10u);
        if (optional_payload) (void)release_via_original_crt(h, optional_payload);
        (void)release_via_original_crt(h, node);
        node = m.r32(sentinel);
    }

    // The route has emptied the sole list, so the original ESI/EBX values are
    // both zero. Apply the two inline 0x40-byte descriptor reset sequences.
    for (std::uint32_t n = 0; n != 2u; ++n) {
        const auto eax = root + 0x4cu + n * 0x40u;
        m.w32(eax - 0x0cu, 0u);
        m.w32(eax, 0xfffffc17u);
        m.w32(eax + 4u, 0xfffffc17u);
        m.w32(eax - 4u, 0u);
        m.w32(eax - 8u, 0u);
        m.w32(eax - 0x28u, 0u);
        m.w32(eax - 0x30u, 0u);
        m.w32(eax - 0x2cu, 0u);
        m.w32(eax - 0x24u, m.r32(eax - 0x24u) & 0xfffffffeu);
    }

    // Original VA 0x408973 loads EAX=[EDI], i.e. -1001. The following ADD
    // changes ECX and stores the result but does not change EAX; pops preserve
    // it through RET, so the observable full return is 0xfffffc17.
    const auto root_total = m.r32(root + 0x14u);
    const auto return_value = m.r32(root + 0x4cu);
    m.w32(root + 0x4cu, root_total + return_value);
    return return_value;
}
} // namespace ra2::recovered::recovery_b131
