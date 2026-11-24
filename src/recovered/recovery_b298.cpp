#include "recovery_b298.hpp"

#include <stdexcept>

namespace ra2::recovered::recovery_b298 {
namespace {
std::uint32_t release_if_owned(OrdinaryHeap& heap, std::uint32_t p,
                               std::uint32_t eax) {
    return p ? heap.release(p) : eax;
}

// The selected inputs have no virtual-call list at +0x0c. The traversal
// below is the real +0x34 payload/node cleanup, with each pointer required
// to be an exact live allocation base by OrdinaryHeap::release.
std::uint32_t release_payload_nodes(Memory& m, std::uint32_t receiver,
                                    std::uint32_t head_offset,
                                    OrdinaryHeap& heap, std::uint32_t eax) {
    auto node = m.r32(receiver + head_offset);
    while (node != 0) {
        const auto payload = heap.r32(node);
        eax = release_if_owned(heap, payload, eax);
        const auto next = heap.r32(node + 4);
        eax = release_if_owned(heap, node, eax);
        m.w32(receiver + head_offset, next);
        node = next;
    }
    return eax;
}
}

std::uint32_t fun_0010fc10(Memory& m, const Inputs& in, OrdinaryHeap& heap) {
    const auto receiver = in.cx;
    if (!receiver) throw std::domain_error("0x10fc10 null receiver excluded");
    m.w32(receiver, 0x78eb9c); // Original initial node-vtable/tag write at VA 0x50fc17.
    auto eax = in.ax;
    eax = release_if_owned(heap, m.r32(receiver + 0x0c), eax);
    eax = release_if_owned(heap, m.r32(receiver + 0x10), eax);
    m.w32(receiver + 0x0c, 0);
    m.w32(receiver + 0x10, 0);
    eax = release_payload_nodes(m, receiver, 0x14, heap, eax);
    eax = release_if_owned(heap, m.r32(receiver + 0x18), eax);
    m.w32(receiver + 0x18, 0);
    m.w32(receiver, 0x785afc);
    const auto previous = m.r32(receiver + 4);
    const auto next = m.r32(receiver + 8);
    if (receiver != 0 && previous != 0 && next != 0) {
        m.w32(next + 4, previous);
        m.w32(previous + 8, next);
        m.w32(receiver + 8, 0);
        m.w32(receiver + 4, 0);
    }
    return eax;
}

std::uint32_t fun_0010adf0(Memory& m, const Inputs& in, OrdinaryHeap& heap) {
    const auto receiver = in.cx;
    // This supported positive route supplies a null first stack argument.
    // A nonnull name enters parsing, string conversion and callbacks outside
    // this contract.
    if (in.arg[0] != 0) throw std::domain_error("0x10adf0 nonnull-name route excluded");
    if (m.r32(receiver + 0x0c) != 0)
        throw std::domain_error("0x10adf0 virtual-call list must be empty");
    auto eax = release_if_owned(heap, m.r32(receiver + 0x20), in.ax);
    m.w32(receiver + 0x20, 0);
    m.w32(receiver + 0x24, 0);
    m.w32(receiver + 0x28, 0);
    m.w8(receiver + 0x2c, 0);
    m.w32(receiver + 0x30, 0);
    eax = release_payload_nodes(m, receiver, 0x34, heap, eax);
    // MOV AL,1 overwrites only the low byte. On this positive route EAX above
    // is the exact BOOL from the final node release through 36d67b/36df28.
    return (eax & 0xffffff00u) | 1u;
}

std::uint32_t fun_0010ad20(Memory& m, const Inputs& in, OrdinaryHeap& heap) {
    const auto receiver = in.cx;
    if (!receiver) throw std::domain_error("0x10ad20 null receiver excluded");
    m.w32(receiver, 0x78db34); // Original first receiver write at VA 0x50ad28.
    // Original pushes two null arguments and calls 0x10adf0 (RET 8).
    Inputs child = in;
    child.cx = receiver;
    child.ax = 0;
    child.arg[0] = 0;
    (void)fun_0010adf0(m, child, heap);
    // 0x10adf0 clears +0x20, so the composed outer wrapper's second release
    // is the exact accepted null-release early path and has no heap event.
    (void)release_if_owned(heap, m.r32(receiver + 0x20), 0);
    m.w32(receiver + 0x20, 0);
    m.w32(receiver + 0x24, 0);
    m.w32(receiver + 0x28, 0);
    m.w8(receiver + 0x2c, 0);
    m.w32(receiver + 0x30, 0);
    m.w32(receiver + 4, 0x785af4);
    // The empty +0x14 node is tested through its next/previous fields at
    // receiver+0x18/+0x1c. The second head at +0x08 has its own dispatch gate
    // at +0x0c. Do not treat the head tag at +0x14 as a pointer.
    if (m.r32(receiver + 0x18) || m.r32(receiver + 0x1c) || m.r32(receiver + 0x0c))
        throw std::domain_error("0x10ad20 detach lists must be empty");
    m.w32(receiver + 0x14, 0x785afc);
    m.w32(receiver + 8, 0x785afc);
    return receiver + 8; // exact final LEA EAX,[ESI+8]
}
} // namespace ra2::recovered::recovery_b298
